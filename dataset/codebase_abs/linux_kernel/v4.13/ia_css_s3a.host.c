void
F_1 ( unsigned int V_1 )
{
V_2 = V_1 ;
}
static void
F_2 (
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
unsigned V_7 )
{
( void ) V_7 ;
V_4 -> V_8 =
F_3 ( V_6 -> V_9 , 16 , V_10 ) ;
V_4 -> V_11 =
F_3 ( V_6 -> V_12 , 16 , V_10 ) ;
V_4 -> V_13 =
F_3 ( V_6 -> V_14 , 16 , V_10 ) ;
}
static void
F_4 (
struct V_15 * V_4 ,
const struct V_5 * V_6 ,
unsigned V_7 )
{
( void ) V_7 ;
V_4 -> V_16 =
F_3 ( V_6 -> V_17 , 16 , V_2 ) ;
V_4 -> V_18 =
F_3 ( V_6 -> V_19 , 16 , V_20 ) ;
V_4 -> V_21 =
F_3 ( V_6 -> V_22 , 16 , V_20 ) ;
}
static void
F_5 (
struct V_23 * V_4 ,
const struct V_5 * V_6 ,
unsigned V_7 )
{
unsigned int V_24 ;
( void ) V_7 ;
for ( V_24 = 0 ; V_24 < 7 ; ++ V_24 ) {
V_4 -> V_25 [ V_24 ] =
F_6 ( V_6 -> V_26 [ V_24 ] , 15 ,
V_27 ) ;
V_4 -> V_28 [ V_24 ] =
F_6 ( V_6 -> V_29 [ V_24 ] , 15 ,
V_27 ) ;
}
}
void
F_7 (
struct V_30 * V_4 ,
const struct V_5 * V_6 ,
unsigned V_7 )
{
( void ) V_7 ;
F_2 ( & V_4 -> V_31 , V_6 , sizeof( V_4 -> V_31 ) ) ;
F_4 ( & V_4 -> V_32 , V_6 , sizeof( V_4 -> V_32 ) ) ;
F_5 ( & V_4 -> V_33 , V_6 , sizeof( V_4 -> V_33 ) ) ;
}
void
F_8 (
const struct V_3 * V_31 ,
unsigned V_34 )
{
if ( ! V_31 ) return;
F_9 ( V_34 , L_1 ,
L_2 , V_31 -> V_8 ) ;
F_9 ( V_34 , L_1 ,
L_3 , V_31 -> V_11 ) ;
F_9 ( V_34 , L_1 ,
L_4 , V_31 -> V_13 ) ;
}
void
F_10 (
const struct V_15 * V_32 ,
unsigned V_34 )
{
F_9 ( V_34 , L_1 ,
L_5 , V_32 -> V_16 ) ;
F_9 ( V_34 , L_1 ,
L_6 , V_32 -> V_18 ) ;
F_9 ( V_34 , L_1 ,
L_7 , V_32 -> V_21 ) ;
}
void
F_11 (
const struct V_23 * V_33 ,
unsigned V_34 )
{
F_9 ( V_34 , L_1 ,
L_8 , V_33 -> V_25 [ 0 ] ) ;
F_9 ( V_34 , L_1 ,
L_9 , V_33 -> V_25 [ 1 ] ) ;
F_9 ( V_34 , L_1 ,
L_10 , V_33 -> V_25 [ 2 ] ) ;
F_9 ( V_34 , L_1 ,
L_11 , V_33 -> V_25 [ 3 ] ) ;
F_9 ( V_34 , L_1 ,
L_12 , V_33 -> V_25 [ 4 ] ) ;
F_9 ( V_34 , L_1 ,
L_13 , V_33 -> V_25 [ 5 ] ) ;
F_9 ( V_34 , L_1 ,
L_14 , V_33 -> V_25 [ 6 ] ) ;
F_9 ( V_34 , L_1 ,
L_15 , V_33 -> V_28 [ 0 ] ) ;
F_9 ( V_34 , L_1 ,
L_16 , V_33 -> V_28 [ 1 ] ) ;
F_9 ( V_34 , L_1 ,
L_17 , V_33 -> V_28 [ 2 ] ) ;
F_9 ( V_34 , L_1 ,
L_18 , V_33 -> V_28 [ 3 ] ) ;
F_9 ( V_34 , L_1 ,
L_19 , V_33 -> V_28 [ 4 ] ) ;
F_9 ( V_34 , L_1 ,
L_20 , V_33 -> V_28 [ 5 ] ) ;
F_9 ( V_34 , L_1 ,
L_21 , V_33 -> V_28 [ 6 ] ) ;
}
void
F_12 (
const struct V_30 * V_35 ,
unsigned V_34 )
{
F_9 ( V_34 , L_22 ) ;
F_8 ( & V_35 -> V_31 , V_34 ) ;
F_10 ( & V_35 -> V_32 , V_34 ) ;
F_11 ( & V_35 -> V_33 , V_34 ) ;
}
void
F_13 (
const struct V_5 * V_36 ,
unsigned V_34 )
{
F_9 ( V_34 ,
L_23
L_24
L_25 ,
V_36 -> V_9 , V_36 -> V_12 ,
V_36 -> V_14 , V_36 -> V_17 ,
V_36 -> V_19 , V_36 -> V_22 ) ;
}
void
F_14 (
struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
#if F_15 ( V_41 )
( void ) V_38 ;
( void ) V_40 ;
#else
struct V_42 * V_43 ;
int V_24 ;
int V_44 ;
int V_45 , V_46 ;
assert ( V_38 != NULL ) ;
assert ( V_38 -> V_47 != NULL ) ;
assert ( V_40 != NULL ) ;
V_44 = V_38 -> V_48 . V_49 * V_38 -> V_48 . V_50
* V_38 -> V_48 . V_51
* V_38 -> V_48 . V_51 ;
V_43 = V_38 -> V_47 ;
F_16 ( V_43 , V_40 ) ;
V_45 = 0 ;
for ( V_24 = 0 ; V_24 < V_52 ; V_24 ++ ) {
V_45 += V_43 [ V_24 ] . V_53 ;
}
if ( V_45 < V_44 ) {
return;
}
#if 0
{
int sum_g = 0;
int sum_b = 0;
int sum_y = 0;
for (i = 0; i < HMEM_UNIT_SIZE; i++) {
sum_g += out_ptr[i].g;
sum_b += out_ptr[i].b;
sum_y += out_ptr[i].y;
}
if (sum_g != sum_r || sum_b != sum_r || sum_y != sum_r) {
return;
}
}
#endif
V_46 = V_45 - V_44 ;
V_43 [ 0 ] . V_53 -= V_46 ;
V_43 [ 0 ] . V_54 -= V_46 ;
V_43 [ 0 ] . V_55 -= V_46 ;
V_43 [ 0 ] . V_56 -= V_46 ;
#endif
}
void
F_17 (
struct V_37 * V_38 ,
const struct V_57 * V_58 )
{
int V_59 , V_60 , V_50 , V_24 ;
struct V_57 * V_61 ;
assert ( V_38 != NULL ) ;
assert ( V_38 -> V_62 != NULL ) ;
assert ( V_58 != NULL ) ;
V_59 = V_38 -> V_48 . V_63 ;
V_60 = V_38 -> V_48 . V_49 ;
V_50 = V_38 -> V_48 . V_50 ;
V_61 = V_38 -> V_62 ;
for ( V_24 = 0 ; V_24 < V_50 ; V_24 ++ ) {
memcpy ( V_61 , V_58 , V_60 * sizeof( * V_61 ) ) ;
V_58 += V_59 ;
V_61 += V_60 ;
}
}
T_1 int
F_18 ( unsigned short V_64 , unsigned short V_65 )
{
int V_66 = ( int ) ( ( ( ( unsigned int ) V_64 << 14 ) & 0xfffc000 ) |
( ( unsigned int ) V_65 & 0x3fff ) ) ;
return V_66 ;
}
void
F_19 (
struct V_37 * V_38 ,
const T_2 * V_67 ,
const T_2 * V_68 )
{
int V_69 , V_70 , V_71 , V_72 , V_73 , V_56 , V_74 , V_75 , V_76 , V_77 , V_78 ;
const T_2 * V_64 , * V_65 ;
struct V_57 * V_79 ;
assert ( V_38 != NULL ) ;
assert ( V_38 -> V_62 != NULL ) ;
assert ( V_67 != NULL ) ;
assert ( V_68 != NULL ) ;
V_79 = V_38 -> V_62 ;
V_69 = V_38 -> V_48 . V_49 ;
V_70 = V_38 -> V_48 . V_50 ;
V_64 = V_67 ;
V_65 = V_68 ;
V_71 = V_80 >> V_38 -> V_48 . V_81 ;
V_71 = F_20 ( V_71 , 1 ) ;
for ( V_56 = 0 ; V_56 < V_70 ; V_56 ++ ) {
V_76 = V_56 * V_82 ;
V_72 = V_69 ;
V_74 = 0 ;
while ( V_74 < V_69 ) {
V_73 = ( V_72 > V_71 ) ? V_71 : V_72 ;
V_78 = V_56 * V_69 + V_74 ;
V_77 = V_76 + V_74 * sizeof( * V_79 ) / sizeof( V_83 ) ;
for ( V_75 = 0 ; V_75 < V_73 ; V_75 ++ , V_77 ++ ) {
V_79 [ V_78 + V_75 ] . V_84 = F_18 (
V_64 [ V_77 + V_71 * 0 ] , V_65 [ V_77 + V_71 * 0 ] ) ;
V_79 [ V_78 + V_75 ] . V_85 = F_18 (
V_64 [ V_77 + V_71 * 1 ] , V_65 [ V_77 + V_71 * 1 ] ) ;
V_79 [ V_78 + V_75 ] . V_86 = F_18 (
V_64 [ V_77 + V_71 * 2 ] , V_65 [ V_77 + V_71 * 2 ] ) ;
V_79 [ V_78 + V_75 ] . V_87 = F_18 (
V_64 [ V_77 + V_71 * 3 ] , V_65 [ V_77 + V_71 * 3 ] ) ;
V_79 [ V_78 + V_75 ] . V_88 = F_18 (
V_64 [ V_77 + V_71 * 4 ] , V_65 [ V_77 + V_71 * 4 ] ) ;
V_79 [ V_78 + V_75 ] . V_89 = F_18 (
V_64 [ V_77 + V_71 * 5 ] , V_65 [ V_77 + V_71 * 5 ] ) ;
V_79 [ V_78 + V_75 ] . V_90 = F_18 (
V_64 [ V_77 + V_71 * 6 ] , V_65 [ V_77 + V_71 * 6 ] ) ;
V_79 [ V_78 + V_75 ] . V_91 = F_18 (
V_64 [ V_77 + V_71 * 7 ] , V_65 [ V_77 + V_71 * 7 ] ) ;
}
V_74 += V_71 ;
V_72 -= V_71 ;
}
}
}
