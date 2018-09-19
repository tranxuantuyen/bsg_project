#include<stdio.h>
#define NINPUTS  2048
#define SWAP(a, b) tmp=(a); (a)=(b); (b)=tmp

// - Cac du lieu da cung cap
// + wprBase va wpiBase: Cac he so co so dung trong qua trinh bien doi
// + dataR1 va dataI1: Du lieu inputs
// + ref: output de kiem tra ket qua


static int wprBase[] = {
	32768,	32768, 32767, 32767, 32766, 32764, 32762, 32760, 32758, 32756, 32753, 32749, 32746, 32742, 32738, 32733, 32729, 
	32723, 32718, 32712, 32706, 32700, 32693, 32686, 32679, 32672, 32664, 32656, 32647, 32638, 32629, 32620, 32610, 
	32600, 32590, 32579, 32568, 32557, 32546, 32534, 32522, 32509, 32496, 32483, 32470, 32456, 32442, 32428, 32413, 
	32398, 32383, 32368, 32352, 32336, 32319, 32303, 32286, 32268, 32251, 32233, 32214, 32196, 32177, 32158, 32138, 
	32119, 32099, 32078, 32058, 32037, 32015, 31994, 31972, 31950, 31927, 31904, 31881, 31858, 31834, 31810, 31786, 
	31761, 31737, 31711, 31686, 31660, 31634, 31608, 31581, 31554, 31527, 31499, 31471, 31443, 31415, 31386, 31357, 
	31328, 31298, 31268, 31238, 31207, 31177, 31146, 31114, 31082, 31050, 31018, 30986, 30953, 30920, 30886, 30853, 
	30819, 30784, 30750, 30715, 30680, 30644, 30608, 30572, 30536, 30499, 30462, 30425, 30388, 30350, 30312, 30274, 
	30235, 30196, 30157, 30118, 30078, 30038, 29997, 29957, 29916, 29875, 29833, 29792, 29750, 29707, 29665, 29622, 
	29579, 29535, 29492, 29448, 29404, 29359, 29314, 29269, 29224, 29178, 29132, 29086, 29040, 28993, 28946, 28899, 
	28851, 28803, 28755, 28707, 28658, 28610, 28560, 28511, 28461, 28411, 28361, 28311, 28260, 28209, 28158, 28106, 
	28054, 28002, 27950, 27897, 27844, 27791, 27738, 27684, 27630, 27576, 27522, 27467, 27412, 27357, 27301, 27246, 
	27190, 27133, 27077, 27020, 26963, 26906, 26848, 26791, 26733, 26674, 26616, 26557, 26498, 26439, 26379, 26320, 
	26259, 26199, 26139, 26078, 26017, 25956, 25894, 25833, 25771, 25708, 25646, 25583, 25520, 25457, 25394, 25330, 
	25266, 25202, 25138, 25073, 25008, 24943, 24878, 24812, 24746, 24680, 24614, 24548, 24481, 24414, 24347, 24279, 
	24212, 24144, 24076, 24008, 23939, 23870, 23801, 23732, 23663, 23593, 23523, 23453, 23383, 23312, 23241, 23170, 
	23099, 23028, 22956, 22884, 22812, 22740, 22668, 22595, 22522, 22449, 22375, 22302, 22228, 22154, 22080, 22006, 
	21931, 21856, 21781, 21706, 21631, 21555, 21479, 21403, 21327, 21251, 21174, 21097, 21020, 20943, 20865, 20788, 
	20710, 20632, 20554, 20475, 20397, 20318, 20239, 20160, 20081, 20001, 19921, 19841, 19761, 19681, 19601, 19520, 
	19439, 19358, 19277, 19195, 19114, 19032, 18950, 18868, 18786, 18703, 18621, 18538, 18455, 18372, 18288, 18205, 
	18121, 18037, 17953, 17869, 17785, 17700, 17616, 17531, 17446, 17361, 17275, 17190, 17104, 17018, 16932, 16846, 
	16760, 16673, 16587, 16500, 16413, 16326, 16239, 16151, 16064, 15976, 15888, 15800, 15712, 15624, 15535, 15447, 
	15358, 15269, 15180, 15091, 15002, 14912, 14823, 14733, 14643, 14553, 14463, 14373, 14282, 14192, 14101, 14010, 
	13919, 13828, 13737, 13646, 13554, 13463, 13371, 13279, 13187, 13095, 13003, 12910, 12818, 12725, 12633, 12540, 
	12447, 12354, 12261, 12167, 12074, 11980, 11887, 11793, 11699, 11605, 11511, 11417, 11323, 11228, 11134, 11039, 
	10945, 10850, 10755, 10660, 10565, 10469, 10374, 10279, 10183, 10088, 9992, 9896, 9800, 9704, 9608, 9512, 
	9416, 9319, 9223, 9127, 9030, 8933, 8836, 8740, 8643, 8546, 8449, 8351, 8254, 8157, 8059, 7962, 
	7864, 7767, 7669, 7571, 7473, 7376, 7278, 7180, 7081, 6983, 6885, 6787, 6688, 6590, 6491, 6393, 
	6294, 6195, 6097, 5998, 5899, 5800, 5701, 5602, 5503, 5404, 5305, 5205, 5106, 5007, 4907, 4808, 
	4709, 4609, 4510, 4410, 4310, 4211, 4111, 4011, 3911, 3812, 3712, 3612, 3512, 3412, 3312, 3212, 
	3112, 3012, 2912, 2811, 2711, 2611, 2511, 2411, 2310, 2210, 2110, 2009, 1909, 1809, 1708, 1608, 
	1507, 1407, 1307, 1206, 1106, 1005, 905, 804, 704, 603, 503, 402, 302, 201, 101, 0, 
	-101, -201, -302, -402, -503, -603, -704, -804, -905, -1005, -1106, -1206, -1307, -1407, -1507, -1608, 
	-1708, -1809, -1909, -2009, -2110, -2210, -2310, -2411, -2511, -2611, -2711, -2811, -2912, -3012, -3112, -3212, 
	-3312, -3412, -3512, -3612, -3712, -3812, -3911, -4011, -4111, -4211, -4310, -4410, -4510, -4609, -4709, -4808, 
	-4907, -5007, -5106, -5205, -5305, -5404, -5503, -5602, -5701, -5800, -5899, -5998, -6097, -6195, -6294, -6393, 
	-6491, -6590, -6688, -6787, -6885, -6983, -7081, -7180, -7278, -7376, -7473, -7571, -7669, -7767, -7864, -7962, 
	-8059, -8157, -8254, -8351, -8449, -8546, -8643, -8740, -8836, -8933, -9030, -9127, -9223, -9319, -9416, -9512, 
	-9608, -9704, -9800, -9896, -9992, -10088, -10183, -10279, -10374, -10469, -10565, -10660, -10755, -10850, -10945, -11039, 
	-11134, -11228, -11323, -11417, -11511, -11605, -11699, -11793, -11887, -11980, -12074, -12167, -12261, -12354, -12447, -12540, 
	-12633, -12725, -12818, -12910, -13003, -13095, -13187, -13279, -13371, -13463, -13554, -13646, -13737, -13828, -13919, -14010, 
	-14101, -14192, -14282, -14373, -14463, -14553, -14643, -14733, -14823, -14912, -15002, -15091, -15180, -15269, -15358, -15447, 
	-15535, -15624, -15712, -15800, -15888, -15976, -16064, -16151, -16239, -16326, -16413, -16500, -16587, -16673, -16760, -16846, 
	-16932, -17018, -17104, -17190, -17275, -17361, -17446, -17531, -17616, -17700, -17785, -17869, -17953, -18037, -18121, -18205, 
	-18288, -18372, -18455, -18538, -18621, -18703, -18786, -18868, -18950, -19032, -19114, -19195, -19277, -19358, -19439, -19520, 
	-19601, -19681, -19761, -19841, -19921, -20001, -20081, -20160, -20239, -20318, -20397, -20475, -20554, -20632, -20710, -20788, 
	-20865, -20943, -21020, -21097, -21174, -21251, -21327, -21403, -21479, -21555, -21631, -21706, -21781, -21856, -21931, -22006, 
	-22080, -22154, -22228, -22302, -22375, -22449, -22522, -22595, -22668, -22740, -22812, -22884, -22956, -23028, -23099, -23170, 
	-23241, -23312, -23383, -23453, -23523, -23593, -23663, -23732, -23801, -23870, -23939, -24008, -24076, -24144, -24212, -24279, 
	-24347, -24414, -24481, -24548, -24614, -24680, -24746, -24812, -24878, -24943, -25008, -25073, -25138, -25202, -25266, -25330, 
	-25394, -25457, -25520, -25583, -25646, -25708, -25771, -25833, -25894, -25956, -26017, -26078, -26139, -26199, -26259, -26320, 
	-26379, -26439, -26498, -26557, -26616, -26674, -26733, -26791, -26848, -26906, -26963, -27020, -27077, -27133, -27190, -27246, 
	-27301, -27357, -27412, -27467, -27522, -27576, -27630, -27684, -27738, -27791, -27844, -27897, -27950, -28002, -28054, -28106, 
	-28158, -28209, -28260, -28311, -28361, -28411, -28461, -28511, -28560, -28610, -28658, -28707, -28755, -28803, -28851, -28899, 
	-28946, -28993, -29040, -29086, -29132, -29178, -29224, -29269, -29314, -29359, -29404, -29448, -29492, -29535, -29579, -29622, 
	-29665, -29707, -29750, -29792, -29833, -29875, -29916, -29957, -29997, -30038, -30078, -30118, -30157, -30196, -30235, -30274, 
	-30312, -30350, -30388, -30425, -30462, -30499, -30536, -30572, -30608, -30644, -30680, -30715, -30750, -30784, -30819, -30853, 
	-30886, -30920, -30953, -30986, -31018, -31050, -31082, -31114, -31146, -31177, -31207, -31238, -31268, -31298, -31328, -31357, 
	-31386, -31415, -31443, -31471, -31499, -31527, -31554, -31581, -31608, -31634, -31660, -31686, -31711, -31737, -31761, -31786, 
	-31810, -31834, -31858, -31881, -31904, -31927, -31950, -31972, -31994, -32015, -32037, -32058, -32078, -32099, -32119, -32138, 
	-32158, -32177, -32196, -32214, -32233, -32251, -32268, -32286, -32303, -32319, -32336, -32352, -32368, -32383, -32398, -32413, 
	-32428, -32442, -32456, -32470, -32483, -32496, -32509, -32522, -32534, -32546, -32557, -32568, -32579, -32590, -32600, -32610, 
	-32620, -32629, -32638, -32647, -32656, -32664, -32672, -32679, -32686, -32693, -32700, -32706, -32712, -32718, -32723, -32729, 
	-32733, -32738, -32742, -32746, -32749, -32753, -32756, -32758, -32760, -32762, -32764, -32766, -32767, -32767, -32768, 
	};
 static int wpiBase[] = {
		0, 101, 201, 302, 402, 503, 603, 704, 804, 905, 1005, 1106, 1206, 1307, 1407, 1507, 1608, 
	1708, 1809, 1909, 2009, 2110, 2210, 2310, 2411, 2511, 2611, 2711, 2811, 2912, 3012, 3112, 3212, 
	3312, 3412, 3512, 3612, 3712, 3812, 3911, 4011, 4111, 4211, 4310, 4410, 4510, 4609, 4709, 4808, 
	4907, 5007, 5106, 5205, 5305, 5404, 5503, 5602, 5701, 5800, 5899, 5998, 6097, 6195, 6294, 6393, 
	6491, 6590, 6688, 6787, 6885, 6983, 7081, 7180, 7278, 7376, 7473, 7571, 7669, 7767, 7864, 7962, 
	8059, 8157, 8254, 8351, 8449, 8546, 8643, 8740, 8836, 8933, 9030, 9127, 9223, 9319, 9416, 9512, 
	9608, 9704, 9800, 9896, 9992, 10088, 10183, 10279, 10374, 10469, 10565, 10660, 10755, 10850, 10945, 11039, 
	11134, 11228, 11323, 11417, 11511, 11605, 11699, 11793, 11887, 11980, 12074, 12167, 12261, 12354, 12447, 12540, 
	12633, 12725, 12818, 12910, 13003, 13095, 13187, 13279, 13371, 13463, 13554, 13646, 13737, 13828, 13919, 14010, 
	14101, 14192, 14282, 14373, 14463, 14553, 14643, 14733, 14823, 14912, 15002, 15091, 15180, 15269, 15358, 15447, 
	15535, 15624, 15712, 15800, 15888, 15976, 16064, 16151, 16239, 16326, 16413, 16500, 16587, 16673, 16760, 16846, 
	16932, 17018, 17104, 17190, 17275, 17361, 17446, 17531, 17616, 17700, 17785, 17869, 17953, 18037, 18121, 18205, 
	18288, 18372, 18455, 18538, 18621, 18703, 18786, 18868, 18950, 19032, 19114, 19195, 19277, 19358, 19439, 19520, 
	19601, 19681, 19761, 19841, 19921, 20001, 20081, 20160, 20239, 20318, 20397, 20475, 20554, 20632, 20710, 20788, 
	20865, 20943, 21020, 21097, 21174, 21251, 21327, 21403, 21479, 21555, 21631, 21706, 21781, 21856, 21931, 22006, 
	22080, 22154, 22228, 22302, 22375, 22449, 22522, 22595, 22668, 22740, 22812, 22884, 22956, 23028, 23099, 23170, 
	23241, 23312, 23383, 23453, 23523, 23593, 23663, 23732, 23801, 23870, 23939, 24008, 24076, 24144, 24212, 24279, 
	24347, 24414, 24481, 24548, 24614, 24680, 24746, 24812, 24878, 24943, 25008, 25073, 25138, 25202, 25266, 25330, 
	25394, 25457, 25520, 25583, 25646, 25708, 25771, 25833, 25894, 25956, 26017, 26078, 26139, 26199, 26259, 26320, 
	26379, 26439, 26498, 26557, 26616, 26674, 26733, 26791, 26848, 26906, 26963, 27020, 27077, 27133, 27190, 27246, 
	27301, 27357, 27412, 27467, 27522, 27576, 27630, 27684, 27738, 27791, 27844, 27897, 27950, 28002, 28054, 28106, 
	28158, 28209, 28260, 28311, 28361, 28411, 28461, 28511, 28560, 28610, 28658, 28707, 28755, 28803, 28851, 28899, 
	28946, 28993, 29040, 29086, 29132, 29178, 29224, 29269, 29314, 29359, 29404, 29448, 29492, 29535, 29579, 29622, 
	29665, 29707, 29750, 29792, 29833, 29875, 29916, 29957, 29997, 30038, 30078, 30118, 30157, 30196, 30235, 30274, 
	30312, 30350, 30388, 30425, 30462, 30499, 30536, 30572, 30608, 30644, 30680, 30715, 30750, 30784, 30819, 30853, 
	30886, 30920, 30953, 30986, 31018, 31050, 31082, 31114, 31146, 31177, 31207, 31238, 31268, 31298, 31328, 31357, 
	31386, 31415, 31443, 31471, 31499, 31527, 31554, 31581, 31608, 31634, 31660, 31686, 31711, 31737, 31761, 31786, 
	31810, 31834, 31858, 31881, 31904, 31927, 31950, 31972, 31994, 32015, 32037, 32058, 32078, 32099, 32119, 32138, 
	32158, 32177, 32196, 32214, 32233, 32251, 32268, 32286, 32303, 32319, 32336, 32352, 32368, 32383, 32398, 32413, 
	32428, 32442, 32456, 32470, 32483, 32496, 32509, 32522, 32534, 32546, 32557, 32568, 32579, 32590, 32600, 32610, 
	32620, 32629, 32638, 32647, 32656, 32664, 32672, 32679, 32686, 32693, 32700, 32706, 32712, 32718, 32723, 32729, 
	32733, 32738, 32742, 32746, 32749, 32753, 32756, 32758, 32760, 32762, 32764, 32766, 32767, 32767, 32768, 32768, 
	32768, 32767, 32767, 32766, 32764, 32762, 32760, 32758, 32756, 32753, 32749, 32746, 32742, 32738, 32733, 32729, 
	32723, 32718, 32712, 32706, 32700, 32693, 32686, 32679, 32672, 32664, 32656, 32647, 32638, 32629, 32620, 32610, 
	32600, 32590, 32579, 32568, 32557, 32546, 32534, 32522, 32509, 32496, 32483, 32470, 32456, 32442, 32428, 32413, 
	32398, 32383, 32368, 32352, 32336, 32319, 32303, 32286, 32268, 32251, 32233, 32214, 32196, 32177, 32158, 32138, 
	32119, 32099, 32078, 32058, 32037, 32015, 31994, 31972, 31950, 31927, 31904, 31881, 31858, 31834, 31810, 31786, 
	31761, 31737, 31711, 31686, 31660, 31634, 31608, 31581, 31554, 31527, 31499, 31471, 31443, 31415, 31386, 31357, 
	31328, 31298, 31268, 31238, 31207, 31177, 31146, 31114, 31082, 31050, 31018, 30986, 30953, 30920, 30886, 30853, 
	30819, 30784, 30750, 30715, 30680, 30644, 30608, 30572, 30536, 30499, 30462, 30425, 30388, 30350, 30312, 30274, 
	30235, 30196, 30157, 30118, 30078, 30038, 29997, 29957, 29916, 29875, 29833, 29792, 29750, 29707, 29665, 29622, 
	29579, 29535, 29492, 29448, 29404, 29359, 29314, 29269, 29224, 29178, 29132, 29086, 29040, 28993, 28946, 28899, 
	28851, 28803, 28755, 28707, 28658, 28610, 28560, 28511, 28461, 28411, 28361, 28311, 28260, 28209, 28158, 28106, 
	28054, 28002, 27950, 27897, 27844, 27791, 27738, 27684, 27630, 27576, 27522, 27467, 27412, 27357, 27301, 27246, 
	27190, 27133, 27077, 27020, 26963, 26906, 26848, 26791, 26733, 26674, 26616, 26557, 26498, 26439, 26379, 26320, 
	26259, 26199, 26139, 26078, 26017, 25956, 25894, 25833, 25771, 25708, 25646, 25583, 25520, 25457, 25394, 25330, 
	25266, 25202, 25138, 25073, 25008, 24943, 24878, 24812, 24746, 24680, 24614, 24548, 24481, 24414, 24347, 24279, 
	24212, 24144, 24076, 24008, 23939, 23870, 23801, 23732, 23663, 23593, 23523, 23453, 23383, 23312, 23241, 23170, 
	23099, 23028, 22956, 22884, 22812, 22740, 22668, 22595, 22522, 22449, 22375, 22302, 22228, 22154, 22080, 22006, 
	21931, 21856, 21781, 21706, 21631, 21555, 21479, 21403, 21327, 21251, 21174, 21097, 21020, 20943, 20865, 20788, 
	20710, 20632, 20554, 20475, 20397, 20318, 20239, 20160, 20081, 20001, 19921, 19841, 19761, 19681, 19601, 19520, 
	19439, 19358, 19277, 19195, 19114, 19032, 18950, 18868, 18786, 18703, 18621, 18538, 18455, 18372, 18288, 18205, 
	18121, 18037, 17953, 17869, 17785, 17700, 17616, 17531, 17446, 17361, 17275, 17190, 17104, 17018, 16932, 16846, 
	16760, 16673, 16587, 16500, 16413, 16326, 16239, 16151, 16064, 15976, 15888, 15800, 15712, 15624, 15535, 15447, 
	15358, 15269, 15180, 15091, 15002, 14912, 14823, 14733, 14643, 14553, 14463, 14373, 14282, 14192, 14101, 14010, 
	13919, 13828, 13737, 13646, 13554, 13463, 13371, 13279, 13187, 13095, 13003, 12910, 12818, 12725, 12633, 12540, 
	12447, 12354, 12261, 12167, 12074, 11980, 11887, 11793, 11699, 11605, 11511, 11417, 11323, 11228, 11134, 11039, 
	10945, 10850, 10755, 10660, 10565, 10469, 10374, 10279, 10183, 10088, 9992, 9896, 9800, 9704, 9608, 9512, 
	9416, 9319, 9223, 9127, 9030, 8933, 8836, 8740, 8643, 8546, 8449, 8351, 8254, 8157, 8059, 7962, 
	7864, 7767, 7669, 7571, 7473, 7376, 7278, 7180, 7081, 6983, 6885, 6787, 6688, 6590, 6491, 6393, 
	6294, 6195, 6097, 5998, 5899, 5800, 5701, 5602, 5503, 5404, 5305, 5205, 5106, 5007, 4907, 4808, 
	4709, 4609, 4510, 4410, 4310, 4211, 4111, 4011, 3911, 3812, 3712, 3612, 3512, 3412, 3312, 3212, 
	3112, 3012, 2912, 2811, 2711, 2611, 2511, 2411, 2310, 2210, 2110, 2009, 1909, 1809, 1708, 1608, 
	1507, 1407, 1307, 1206, 1106, 1005, 905, 804, 704, 603, 503, 402, 302, 201, 101, 
	};
 
 int buf[2 * NINPUTS] = {0, 0, 2, 0, 0, 0, -1, 0, 2, 0, 3, 0, -0, 0, 1, 0, 1, 0, 1, 0, -0, 0, 1, 0, -1, 0, 0, 0, -0, 0, 0, 0, -3, 0, 1, 0, 0, 0, -0, 0, -2, 0, 3, 0, 1, 0, 1, 0, -0, 0, 4, 0, 1, 0, 1, 0, 1, 0, 3, 0, 0, 0, 2, 0, -0, 0, 0, 0, 0, 0, 1, 0, -2, 0, -0, 0, 2, 0, 1, 0, -2, 0, 1, 0, 3, 0, 1, 0, 0, 0, 3, 0, 3, 0, 1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1, 0, -1, 0, 1, 0, 0, 0, 0, 0, -2, 0, 2, 0, 1, 0, 0, 0, -2, 0, 4, 0, 1, 0, 1, 0, 0, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 0, 0, 2, 0, -1, 0, 0, 0, -0, 0, 1, 0, -2, 0, -0, 0, 1, 0, 1, 0, -2, 0, 1, 0, 3, 0, 1, 0, -0, 0, 2, 0, 3, 0, 0, 0, 1, 0, 1, 0, 1, 0, -0, 0, 1, 0, -1, 0, 0, 0, -0, 0, -0, 0, -3, 0, 1, 0, -0, 0, -1, 0, -2, 0, 3, 0, 0, 0, -0, 0, -1, 0, 3, 0, -0, 0, 1, 0, -0, 0, 2, 0, -1, 0, 1, 0, -2, 0, -1, 0, -1, 0, -0, 0, -3, 0, -1, 0, -0, 0, -1, 0, -3, 0, 0, 0, 1, 0, -1, 0, -2, 0, 1, 0, 1, 0, -1, 0, -0, 0, 0, 0, -0, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -2, 0, -4, 0, 0, 0, -1, 0, -2, 0, -3, 0, 2, 0, -1, 0, -1, 0, -1, 0, 3, 0, -1, 0, -0, 0, -1, 0, 1, 0, -2, 0, -0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -2, 0, -1, 0, -1, 0, -4, 0, 0, 0, 1, 0, -1, 0, -2, 0, 1, 0, 1, 0, -1, 0, -0, 0, 0, 0, -0, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -2, 0, -4, 0, 0, 0, -1, 0, -2, 0, -3, 0, 2, 0, -0, 0, -1, 0, -1, 0, 3, 0, -1, 0, 0, 0, -0, 0, 2, 0, -1, 0, 1, 0, -2, 0, -0, 0, -1, 0, 0, 0, -3, 0, -0, 0, 0, 0, -0, 0, -3, 0, 1, 0, 2, 0, 0, 0, -1, 0, 3, 0, 2, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -2, 0, 1, 0, 0, 0, -1, 0, -1, 0, 3, 0, 1, 0, 0, 0, 1, 0, 4, 0, 0, 0, 2, 0, 1, 0, 3, 0, -0, 0, 2, 0, -1, 0, 1, 0, -0, 0, 1, 0, -2, 0, 1, 0, 1, 0, 1, 0, -2, 0, 2, 0, 2, 0, 1, 0, 0, 0, 4, 0, 2, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, -0, 0, 1, 0, 1, 0, -0, 0, -2, 0, 2, 0, 1, 0, -0, 0, -1, 0, 4, 0, 1, 0, 1, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, -0, 0, 2, 0, -1, 0, 1, 0, -0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 1, 0, -2, 0, 2, 0, 2, 0, 1, 0, -0, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0, -0, 0, -1, 0, -0, 0, 0, 0, -1, 0, -2, 0, 1, 0, 0, 0, -2, 0, -1, 0, 3, 0, -0, 0, -0, 0, 0, 0, 3, 0, -1, 0, 1, 0, -0, 0, 1, 0, -1, 0, 1, 0, -2, 0, -0, 0, -1, 0, -0, 0, -4, 0, -0, 0, -0, 0, -1, 0, -3, 0, 1, 0, 1, 0, -1, 0, -2, 0, 2, 0, 0, 0, -0, 0, -1, 0, 1, 0, -1, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -3, 0, -3, 0, -0, 0, -1, 0, -3, 0, -2, 0, 2, 0, -1, 0, -1, 0, -0, 0, 2, 0, -1, 0, -0, 0, -1, 0, 1, 0, -2, 0, -0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -1, 0, -1, 0, -1, 0, -4, 0, 1, 0, 0, 0, -1, 0, -2, 0, 2, 0, -0, 0, -0, 0, -1, 0, 1, 0, -1, 0, -0, 0, -2, 0, -2, 0, -1, 0, -1, 0, -3, 0, -3, 0, 0, 0, -1, 0, -3, 0, -1, 0, 2, 0, -1, 0, -1, 0, 0, 0, 3, 0, -1, 0, 0, 0, -0, 0, 1, 0, -1, 0, 1, 0, -2, 0, -0, 0, -1, 0, -0, 0, -4, 0, 0, 0, -0, 0, -0, 0, -3, 0, 2, 0, 1, 0, 0, 0, -1, 0, 3, 0, 1, 0, 1, 0, 0, 0, 2, 0, -0, 0, 1, 0, -1, 0, -0, 0, -0, 0, 1, 0, -2, 0, -1, 0, 1, 0, 1, 0, -2, 0, 0, 0, 3, 0, 1, 0, 0, 0, 2, 0, 4, 0, 0, 0, 2, 0, 1, 0, 2, 0, -0, 0, 2, 0, -1, 0, 1, 0, 0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 1, 0, -2, 0, 3, 0, 2, 0, 1, 0, 0, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, -0, 0, 0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 2, 0, 1, 0, -1, 0, 1, 0, 3, 0, 1, 0, 0, 0, 2, 0, 4, 0, 1, 0, 2, 0, 1, 0, 2, 0, 0, 0, 1, 0, -1, 0, 1, 0, -0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 0, 0, -2, 0, 3, 0, 1, 0, 1, 0, -0, 0, 4, 0, 1, 0, 1, 0, 0, 0, 2, 0, -0, 0, 1, 0, -1, 0, -0, 0, -0, 0, 0, 0, -2, 0, -1, 0, 1, 0, 0, 0, -2, 0, -0, 0, 2, 0, -0, 0, -1, 0, 1, 0, 2, 0, -0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, -2, 0, -0, 0, -1, 0, -1, 0, -4, 0, 0, 0, -1, 0, -1, 0, -3, 0, 2, 0, -0, 0, -1, 0, -1, 0, 3, 0, -1, 0, 0, 0, -1, 0, 1, 0, -1, 0, -0, 0, -2, 0, -1, 0, -2, 0, -1, 0, -4, 0, -2, 0, -0, 0, -1, 0, -3, 0, -1, 0, 1, 0, -1, 0, -2, 0, 1, 0, 1, 0, -1, 0, -0, 0, -0, 0, 0, 0, -2, 0, -1, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -0, 0, -1, 0, -2, 0, -3, 0, 2, 0, -1, 0, -1, 0, -1, 0, 3, 0, -1, 0, -0, 0, -1, 0, 1, 0, -2, 0, 0, 0, -2, 0, -1, 0, -2, 0, -0, 0, -4, 0, -2, 0, -0, 0, -1, 0, -3, 0, -0, 0, 2, 0, -1, 0, -1, 0, 1, 0, 2, 0, -1, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, -2, 0, -0, 0, -1, 0, -1, 0, -3, 0, 1, 0, -0, 0, -1, 0, -2, 0, 3, 0, 0, 0, 0, 0, -0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 2, 0, -1, 0, 1, 0, -1, 0, 0, 0, -0, 0, 1, 0, -3, 0, -0, 0, 1, 0, 1, 0, -2, 0, 1, 0, 3, 0, 1, 0, -0, 0, 3, 0, 3, 0, 1, 0, 1, 0, 2, 0, 2, 0, 0, 0, 1, 0, -1, 0, 1, 0, 0, 0, 0, 0, -2, 0, 2, 0, 1, 0, -0, 0, -1, 0, 4, 0, 1, 0, 1, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 0, 0, 2, 0, -1, 0, 1, 0, 0, 0, 1, 0, -2, 0, 0, 0, 1, 0, 1, 0, -2, 0, 2, 0, 3, 0, 1, 0, 0, 0, 3, 0, 3, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 0, 0, -0, 0, -2, 0, 2, 0, 1, 0, -1, 0, -1, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 2, 0, -1, 0, 1, 0, -1, 0, 0, 0, -1, 0, 1, 0, -3, 0, -0, 0, 0, 0, 0, 0, -3, 0, 1, 0, 2, 0, -0, 0, -1, 0, 2, 0, 1, 0, -0, 0, 0, 0, 1, 0, 0, 0, -0, 0, -0, 0, -2, 0, -1, 0, -1, 0, -2, 0, -3, 0, 0, 0, -1, 0, -2, 0, -2, 0, 2, 0, -1, 0, -1, 0, -1, 0, 3, 0, -1, 0, 0, 0, -1, 0, 1, 0, -2, 0, 0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -1, 0, -1, 0, -1, 0, -4, 0, 1, 0, 0, 0, -1, 0, -2, 0, 2, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -2, 0, -4, 0, -0, 0, -1, 0, -2, 0, -2, 0, 2, 0, -1, 0, -1, 0, -1, 0, 2, 0, -1, 0, 0, 0, -1, 0, 1, 0, -2, 0, 0, 0, -3, 0, -1, 0, -2, 0, -0, 0, -4, 0, -1, 0, -0, 0, -1, 0, -3, 0, 1, 0, 1, 0, -0, 0, -1, 0, 2, 0, 1, 0, -0, 0, -0, 0, 1, 0, -0, 0, -0, 0, -1, 0, -1, 0, -1, 0, -0, 0, -2, 0, -3, 0, 1, 0, -0, 0, -2, 0, -1, 0, 3, 0, 0, 0, -0, 0, 0, 0, 3, 0, -0, 0, 1, 0, 0, 0, 2, 0, -1, 0, 1, 0, -2, 0, 0, 0, -0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 0, 0, -2, 0, 3, 0, 2, 0, 1, 0, -0, 0, 4, 0, 2, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 0, 0, -0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 2, 0, 1, 0, -1, 0, -0, 0, 4, 0, 1, 0, 1, 0, 2, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 0, 0, 2, 0, -1, 0, 1, 0, 0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 1, 0, -2, 0, 3, 0, 2, 0, 1, 0, -0, 0, 4, 0, 2, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 0, 0, -0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 2, 0, 1, 0, -1, 0, -0, 0, 3, 0, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 1, 0, 1, 0, 2, 0, -1, 0, 1, 0, -2, 0, 0, 0, -1, 0, 0, 0, -3, 0, 1, 0, 0, 0, -0, 0, -3, 0, 2, 0, 1, 0, 0, 0, -1, 0, 3, 0, 0, 0, 0, 0, -0, 0, 1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, -0, 0, -3, 0, -2, 0, 0, 0, -1, 0, -3, 0, -1, 0, 2, 0, -1, 0, -1, 0, 0, 0, 2, 0, -1, 0, 0, 0, -0, 0, 1, 0, -2, 0, -0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -0, 0, -1, 0, -1, 0, -4, 0, 2, 0, -0, 0, -1, 0, -2, 0, 2, 0, -0, 0, -0, 0, -1, 0, 1, 0, -1, 0, -0, 0, -2, 0, -2, 0, -2, 0, -1, 0, -3, 0, -3, 0, -0, 0, -1, 0, -3, 0, -1, 0, 2, 0, -1, 0, -2, 0, 0, 0, 2, 0, -1, 0, -0, 0, -0, 0, 0, 0, -2, 0, -0, 0, -3, 0, -1, 0, -1, 0, -1, 0, -4, 0, 0, 0, -1, 0, -1, 0, -3, 0, 2, 0, 0, 0, -0, 0, -1, 0, 3, 0, -0, 0, 0, 0, -0, 0, 1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, 0, 0, -3, 0, -2, 0, 1, 0, -0, 0, -2, 0, -0, 0, 2, 0, 0, 0, -1, 0, 2, 0, 3, 0, -0, 0, 1, 0, 1, 0, 1, 0, -0, 0, 1, 0, -1, 0, 0, 0, -0, 0, 0, 0, -3, 0, 1, 0, 0, 0, -0, 0, -2, 0, 3, 0, 1, 0, 1, 0, -0, 0, 4, 0, 1, 0, 1, 0, 1, 0, 3, 0, 0, 0, 2, 0, -0, 0, 0, 0, 0, 0, 1, 0, -2, 0, -0, 0, 2, 0, 1, 0, -2, 0, 1, 0, 3, 0, 1, 0, 0, 0, 3, 0, 3, 0, 1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1, 0, -1, 0, 1, 0, 0, 0, 0, 0, -2, 0, 2, 0, 1, 0, 0, 0, -2, 0, 4, 0, 1, 0, 1, 0, 0, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 0, 0, 2, 0, -1, 0, 0, 0, -0, 0, 1, 0, -2, 0, -0, 0, 1, 0, 1, 0, -2, 0, 1, 0, 3, 0, 1, 0, -0, 0, 2, 0, 3, 0, 0, 0, 1, 0, 1, 0, 1, 0, -0, 0, 1, 0, -1, 0, 0, 0, -0, 0, -0, 0, -3, 0, 1, 0, -0, 0, -1, 0, -2, 0, 3, 0, 0, 0, -0, 0, -1, 0, 3, 0, -0, 0, 1, 0, -0, 0, 2, 0, -1, 0, 1, 0, -2, 0, -1, 0, -1, 0, -0, 0, -3, 0, -1, 0, -0, 0, -1, 0, -3, 0, 0, 0, 1, 0, -1, 0, -2, 0, 1, 0, 1, 0, -1, 0, -0, 0, 0, 0, -0, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -2, 0, -4, 0, 0, 0, -1, 0, -2, 0, -3, 0, 2, 0, -1, 0, -1, 0, -1, 0, 3, 0, -1, 0, -0, 0, -1, 0, 1, 0, -2, 0, -0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -2, 0, -1, 0, -1, 0, -4, 0, 0, 0, 1, 0, -1, 0, -2, 0, 1, 0, 1, 0, -1, 0, -0, 0, 0, 0, -0, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -2, 0, -4, 0, 0, 0, -1, 0, -2, 0, -3, 0, 2, 0, -0, 0, -1, 0, -1, 0, 3, 0, -1, 0, 0, 0, -0, 0, 2, 0, -1, 0, 1, 0, -2, 0, -0, 0, -1, 0, 0, 0, -3, 0, -0, 0, 0, 0, -0, 0, -3, 0, 1, 0, 2, 0, 0, 0, -1, 0, 3, 0, 2, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -2, 0, 1, 0, 0, 0, -1, 0, -1, 0, 3, 0, 1, 0, 0, 0, 1, 0, 4, 0, 0, 0, 2, 0, 1, 0, 3, 0, -0, 0, 2, 0, -1, 0, 1, 0, -0, 0, 1, 0, -2, 0, 1, 0, 1, 0, 1, 0, -2, 0, 2, 0, 2, 0, 1, 0, 0, 0, 4, 0, 2, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, -0, 0, 1, 0, 1, 0, -0, 0, -2, 0, 2, 0, 1, 0, -0, 0, -1, 0, 4, 0, 1, 0, 1, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, -0, 0, 2, 0, -1, 0, 1, 0, -0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 1, 0, -2, 0, 2, 0, 2, 0, 1, 0, -0, 0, 3, 0, 2, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0, -0, 0, -1, 0, -0, 0, 0, 0, -1, 0, -2, 0, 1, 0, 0, 0, -2, 0, -1, 0, 3, 0, -0, 0, -0, 0, 0, 0, 3, 0, -1, 0, 1, 0, -0, 0, 1, 0, -1, 0, 1, 0, -2, 0, -0, 0, -1, 0, -0, 0, -4, 0, -0, 0, -0, 0, -1, 0, -3, 0, 1, 0, 1, 0, -1, 0, -2, 0, 2, 0, 0, 0, -0, 0, -1, 0, 1, 0, -1, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -3, 0, -3, 0, -0, 0, -1, 0, -3, 0, -2, 0, 2, 0, -1, 0, -1, 0, -0, 0, 2, 0, -1, 0, -0, 0, -1, 0, 1, 0, -2, 0, -0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -1, 0, -1, 0, -1, 0, -4, 0, 1, 0, 0, 0, -1, 0, -2, 0, 2, 0, -0, 0, -0, 0, -1, 0, 1, 0, -1, 0, -0, 0, -2, 0, -2, 0, -1, 0, -1, 0, -3, 0, -3, 0, 0, 0, -1, 0, -3, 0, -1, 0, 2, 0, -1, 0, -1, 0, 0, 0, 3, 0, -1, 0, 0, 0, -0, 0, 1, 0, -1, 0, 1, 0, -2, 0, -0, 0, -1, 0, -0, 0, -4, 0, 0, 0, -0, 0, -0, 0, -3, 0, 2, 0, 1, 0, 0, 0, -1, 0, 3, 0, 1, 0, 1, 0, 0, 0, 2, 0, -0, 0, 1, 0, -1, 0, -0, 0, -0, 0, 1, 0, -2, 0, -1, 0, 1, 0, 1, 0, -2, 0, 0, 0, 3, 0, 1, 0, 0, 0, 2, 0, 4, 0, 0, 0, 2, 0, 1, 0, 2, 0, -0, 0, 2, 0, -1, 0, 1, 0, 0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 1, 0, -2, 0, 3, 0, 2, 0, 1, 0, 0, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, -0, 0, 0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 2, 0, 1, 0, -1, 0, 1, 0, 3, 0, 1, 0, 0, 0, 2, 0, 4, 0, 1, 0, 2, 0, 1, 0, 2, 0, 0, 0, 1, 0, -1, 0, 1, 0, -0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 0, 0, -2, 0, 3, 0, 1, 0, 1, 0, -0, 0, 4, 0, 1, 0, 1, 0, 0, 0, 2, 0, -0, 0, 1, 0, -1, 0, -0, 0, -0, 0, 0, 0, -2, 0, -1, 0, 1, 0, 0, 0, -2, 0, -0, 0, 2, 0, -0, 0, -1, 0, 1, 0, 2, 0, -0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, -2, 0, -0, 0, -1, 0, -1, 0, -4, 0, 0, 0, -1, 0, -1, 0, -3, 0, 2, 0, -0, 0, -1, 0, -1, 0, 3, 0, -1, 0, 0, 0, -1, 0, 1, 0, -1, 0, -0, 0, -2, 0, -1, 0, -2, 0, -1, 0, -4, 0, -2, 0, -0, 0, -1, 0, -3, 0, -1, 0, 1, 0, -1, 0, -2, 0, 1, 0, 1, 0, -1, 0, -0, 0, -0, 0, 0, 0, -2, 0, -1, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -0, 0, -1, 0, -2, 0, -3, 0, 2, 0, -1, 0, -1, 0, -1, 0, 3, 0, -1, 0, -0, 0, -1, 0, 1, 0, -2, 0, 0, 0, -2, 0, -1, 0, -2, 0, -0, 0, -4, 0, -2, 0, -0, 0, -1, 0, -3, 0, -0, 0, 2, 0, -1, 0, -1, 0, 1, 0, 2, 0, -1, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 0, -2, 0, -0, 0, -1, 0, -1, 0, -3, 0, 1, 0, -0, 0, -1, 0, -2, 0, 3, 0, 0, 0, 0, 0, -0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 2, 0, -1, 0, 1, 0, -1, 0, 0, 0, -0, 0, 1, 0, -3, 0, -0, 0, 1, 0, 1, 0, -2, 0, 1, 0, 3, 0, 1, 0, -0, 0, 3, 0, 3, 0, 1, 0, 1, 0, 2, 0, 2, 0, 0, 0, 1, 0, -1, 0, 1, 0, 0, 0, 0, 0, -2, 0, 2, 0, 1, 0, -0, 0, -1, 0, 4, 0, 1, 0, 1, 0, 1, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 0, 0, 2, 0, -1, 0, 1, 0, 0, 0, 1, 0, -2, 0, 0, 0, 1, 0, 1, 0, -2, 0, 2, 0, 3, 0, 1, 0, 0, 0, 3, 0, 3, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, -1, 0, 1, 0, 0, 0, -0, 0, -2, 0, 2, 0, 1, 0, -1, 0, -1, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 0, 0, 0, 2, 0, -1, 0, 1, 0, -1, 0, 0, 0, -1, 0, 1, 0, -3, 0, -0, 0, 0, 0, 0, 0, -3, 0, 1, 0, 2, 0, -0, 0, -1, 0, 2, 0, 1, 0, -0, 0, 0, 0, 1, 0, 0, 0, -0, 0, -0, 0, -2, 0, -1, 0, -1, 0, -2, 0, -3, 0, 0, 0, -1, 0, -2, 0, -2, 0, 2, 0, -1, 0, -1, 0, -1, 0, 3, 0, -1, 0, 0, 0, -1, 0, 1, 0, -2, 0, 0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -1, 0, -1, 0, -1, 0, -4, 0, 1, 0, 0, 0, -1, 0, -2, 0, 2, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, -2, 0, -1, 0, -1, 0, -2, 0, -4, 0, -0, 0, -1, 0, -2, 0, -2, 0, 2, 0, -1, 0, -1, 0, -1, 0, 2, 0, -1, 0, 0, 0, -1, 0, 1, 0, -2, 0, 0, 0, -3, 0, -1, 0, -2, 0, -0, 0, -4, 0, -1, 0, -0, 0, -1, 0, -3, 0, 1, 0, 1, 0, -0, 0, -1, 0, 2, 0, 1, 0, -0, 0, -0, 0, 1, 0, -0, 0, -0, 0, -1, 0, -1, 0, -1, 0, -0, 0, -2, 0, -3, 0, 1, 0, -0, 0, -2, 0, -1, 0, 3, 0, 0, 0, -0, 0, 0, 0, 3, 0, -0, 0, 1, 0, 0, 0, 2, 0, -1, 0, 1, 0, -2, 0, 0, 0, -0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 0, 0, -2, 0, 3, 0, 2, 0, 1, 0, -0, 0, 4, 0, 2, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 0, 0, -0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 2, 0, 1, 0, -1, 0, -0, 0, 4, 0, 1, 0, 1, 0, 2, 0, 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 0, 0, 2, 0, -1, 0, 1, 0, 0, 0, 1, 0, -3, 0, 1, 0, 1, 0, 1, 0, -2, 0, 3, 0, 2, 0, 1, 0, -0, 0, 4, 0, 2, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 0, 0, -0, 0, 0, 0, 1, 0, -1, 0, -1, 0, 2, 0, 1, 0, -1, 0, -0, 0, 3, 0, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 1, 0, 1, 0, 2, 0, -1, 0, 1, 0, -2, 0, 0, 0, -1, 0, 0, 0, -3, 0, 1, 0, 0, 0, -0, 0, -3, 0, 2, 0, 1, 0, 0, 0, -1, 0, 3, 0, 0, 0, 0, 0, -0, 0, 1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, -0, 0, -3, 0, -2, 0, 0, 0, -1, 0, -3, 0, -1, 0, 2, 0, -1, 0, -1, 0, 0, 0, 2, 0, -1, 0, 0, 0, -0, 0, 1, 0, -2, 0, -0, 0, -3, 0, -1, 0, -2, 0, -1, 0, -4, 0, -0, 0, -1, 0, -1, 0, -4, 0, 2, 0, -0, 0, -1, 0, -2, 0, 2, 0, -0, 0, -0, 0, -1, 0, 1, 0, -1, 0, -0, 0, -2, 0, -2, 0, -2, 0, -1, 0, -3, 0, -3, 0, -0, 0, -1, 0, -3, 0, -1, 0, 2, 0, -1, 0, -2, 0, 0, 0, 2, 0, -1, 0, -0, 0, -0, 0, 0, 0, -2, 0, -0, 0, -3, 0, -1, 0, -1, 0, -1, 0, -4, 0, 0, 0, -1, 0, -1, 0, -3, 0, 2, 0, 0, 0, -0, 0, -1, 0, 3, 0, -0, 0, 0, 0, -0, 0, 1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, 0, 0, -3, 0, -2, 0, 1, 0, -0, 0, -2, 0, 
  };




void fft_pre(int *data, int len) {

	int max = len;
	len <<= 1;
	int wstep = 1;

	int *wpr = wprBase;
	int *wpi = wpiBase;

	for (int m = 0; m < max; m += 2) {
		int wr = *wpr;
		int wi = *wpi;
		wpr += wstep;
		wpi += wstep;

		int step = max << 1;

		for (int i = m; i < len; i += step) {
			int j = i + max;

			int tr = data[i] - data[j];
			int ti = data[i + 1] - data[j + 1];

			data[i] += data[j];
			data[i + 1] += data[j + 1];

			int xr = ((wr * tr + wi * ti) << 1) + 0x8000;
			int xi = ((wr * ti - wi * tr) << 1) + 0x8000;

			data[j] = xr >> 16;
			data[j + 1] = xi >> 16;
		}
	}
	max >>= 1;
	wstep <<= 1;

}


void fft_firstHalf(int *data, int len)
{
	len <<= 1;
	int max = NINPUTS / 2;
	int wstep = 2;
	while (max > 2) {
		int *wpr = wprBase;
		int *wpi = wpiBase;

		for (int m = 0; m < max; m += 2) {
			int wr = *wpr;
			int wi = *wpi;
			wpr += wstep;
			wpi += wstep;

			int step = max << 1;

			for (int i = m; i < len / 2; i += step) {
				int j = i + max;

				int tr = data[i] - data[j];
				int ti = data[i + 1] - data[j + 1];

				data[i] += data[j];
				data[i + 1] += data[j + 1];

				int xr = ((wr * tr + wi * ti) << 1) + 0x8000;
				int xi = ((wr * ti - wi * tr) << 1) + 0x8000;

				data[j] = xr >> 16;
				data[j + 1] = xi >> 16;
			}


		}
		max >>= 1;
		wstep <<= 1;
	}

	///////////////////////////

}

void fft3_secondHalf(int *data, int len)
{
	len <<= 1;
	int max = NINPUTS / 2;
	int wstep = 2;
	while (max > 2) {
		int *wpr = wprBase;
		int *wpi = wpiBase;

		for (int m = 0; m < max; m += 2) {
			int wr = *wpr;
			int wi = *wpi;
			wpr += wstep;
			wpi += wstep;

			int step = max << 1;

			for (int i = m + len / 2; i < len; i += step) {
				int j = i + max;

				int tr = data[i] - data[j];
				int ti = data[i + 1] - data[j + 1];

				data[i] += data[j];
				data[i + 1] += data[j + 1];

				int xr = ((wr * tr + wi * ti) << 1) + 0x8000;
				int xi = ((wr * ti - wi * tr) << 1) + 0x8000;

				data[j] = xr >> 16;
				data[j + 1] = xi >> 16;
			}


		}
		max >>= 1;
		wstep <<= 1;
	}


}




void merge(int *data, int len)
{
	len <<= 1;
	{
		int max = 2;
		int step = max << 1;

		for (int i = 0; i < len; i += step) {
			int j = i + max;

			int tr = data[i] - data[j];
			int ti = data[i + 1] - data[j + 1];

			data[i] += data[j];
			data[i + 1] += data[j + 1];


			data[j] = tr;
			data[j + 1] = ti;
		}
	}



	data--;
	int j = 1;
	for (int i = 1; i < len; i += 2) {
		if (j > i) {
			int tmp;
			SWAP(data[j], data[i]);
			SWAP(data[j + 1], data[i + 1]);
		}
		int m = len >> 1;
		while (m >= 2 && j >m) {
			j -= m;
			m >>= 1;
		}
		j += m;
	}
}
int main()
{
	FILE *fp;
	fp = fopen("vidu.txt", "w+");
	for(int i = 0; i < 2048*2; i = i + 2)
	{
		
		fprintf(fp, "%d	", buf[i]);
		
	}	
	fprintf(fp, "\n");
	
	/////////////////////////////////////////
	fft_pre(buf, NINPUTS);   // Core 0
	fft_firstHalf(buf, NINPUTS); //core 1
	fft3_secondHalf(buf, NINPUTS); //core 2
	merge(buf, NINPUTS);			// core 3
	//===============================================//
	
	
	
   	fprintf(fp, "Vi du kiem tra ham fprintf ...\n");
   	for(int i = 1; i < 2048*2; i = i +2)
   	{
   		fprintf(fp, "%d	", buf[i]);
   		// fprintf(fp, "0, ");
   	}
	

	return 0;
}
