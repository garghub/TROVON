static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_3 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_3 , 0 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_7 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
return F_7 ( V_9 , F_8 ( V_2 ) / 4 ) ;
}
static void F_9 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_1 V_12 = 0 ;
T_1 V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
T_1 V_16 = V_6 -> V_17 . V_16 [ V_14 ] ;
V_12 |= V_16 << ( 28 - ( V_14 * 4 ) ) ;
if ( ( V_16 > 0x8 ) && ( V_13 < ( V_16 - 0x8 ) ) )
V_13 = V_16 - 0x8 ;
}
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_18 , F_10 ( V_9 ) ) ;
F_2 ( V_2 , V_19 , V_12 ) ;
F_2 ( V_2 , V_20 , V_13 ) ;
if ( V_13 > 0 ) {
F_2 ( V_2 , V_21 , V_6 -> V_22 . V_16 [ 0 ] ) ;
F_2 ( V_2 , V_23 , V_6 -> V_22 . V_16 [ 1 ] ) ;
F_2 ( V_2 , V_24 , V_6 -> V_22 . V_16 [ 2 ] ) ;
F_2 ( V_2 , V_25 , V_6 -> V_22 . V_16 [ 3 ] ) ;
F_2 ( V_2 , V_26 , V_6 -> V_22 . V_16 [ 4 ] ) ;
F_2 ( V_2 , V_27 , V_6 -> V_22 . V_16 [ 5 ] ) ;
F_2 ( V_2 , V_28 , V_6 -> V_22 . V_16 [ 6 ] ) ;
F_2 ( V_2 , V_29 , V_6 -> V_22 . V_16 [ 7 ] ) ;
}
if ( V_13 > 1 ) {
F_2 ( V_2 , V_30 , V_6 -> V_31 . V_16 [ 0 ] ) ;
F_2 ( V_2 , V_32 , V_6 -> V_31 . V_16 [ 1 ] ) ;
F_2 ( V_2 , V_33 , V_6 -> V_31 . V_16 [ 2 ] ) ;
F_2 ( V_2 , V_34 , V_6 -> V_31 . V_16 [ 3 ] ) ;
F_2 ( V_2 , V_35 , V_6 -> V_31 . V_16 [ 4 ] ) ;
F_2 ( V_2 , V_36 , V_6 -> V_31 . V_16 [ 5 ] ) ;
F_2 ( V_2 , V_37 , V_6 -> V_31 . V_16 [ 6 ] ) ;
F_2 ( V_2 , V_38 , V_6 -> V_31 . V_16 [ 7 ] ) ;
}
if ( V_13 > 2 ) {
F_2 ( V_2 , V_39 , V_6 -> V_40 . V_16 [ 0 ] ) ;
F_2 ( V_2 , V_41 , V_6 -> V_40 . V_16 [ 1 ] ) ;
F_2 ( V_2 , V_42 , V_6 -> V_40 . V_16 [ 2 ] ) ;
F_2 ( V_2 , V_43 , V_6 -> V_40 . V_16 [ 3 ] ) ;
F_2 ( V_2 , V_44 , V_6 -> V_40 . V_16 [ 4 ] ) ;
F_2 ( V_2 , V_45 , V_6 -> V_40 . V_16 [ 5 ] ) ;
F_2 ( V_2 , V_46 , V_6 -> V_40 . V_16 [ 6 ] ) ;
F_2 ( V_2 , V_47 , V_6 -> V_40 . V_16 [ 7 ] ) ;
}
if ( V_13 > 3 ) {
F_2 ( V_2 , V_48 , V_6 -> V_49 . V_16 [ 0 ] ) ;
F_2 ( V_2 , V_50 , V_6 -> V_49 . V_16 [ 1 ] ) ;
F_2 ( V_2 , V_51 , V_6 -> V_49 . V_16 [ 2 ] ) ;
F_2 ( V_2 , V_52 , V_6 -> V_49 . V_16 [ 3 ] ) ;
F_2 ( V_2 , V_53 , V_6 -> V_49 . V_16 [ 4 ] ) ;
F_2 ( V_2 , V_54 , V_6 -> V_49 . V_16 [ 5 ] ) ;
F_2 ( V_2 , V_55 , V_6 -> V_49 . V_16 [ 6 ] ) ;
F_2 ( V_2 , V_56 , V_6 -> V_49 . V_16 [ 7 ] ) ;
}
F_2 ( V_2 , V_4 , 0 ) ;
}
static void F_11 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_14 ;
if ( ! V_6 -> V_57 . V_16 )
return;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_6 -> V_17 . V_16 [ V_14 ] = 0 ;
V_6 -> V_22 . V_16 [ V_14 ] = 0 ;
V_6 -> V_31 . V_16 [ V_14 ] = 0 ;
V_6 -> V_40 . V_16 [ V_14 ] = 0 ;
V_6 -> V_49 . V_16 [ V_14 ] = 0 ;
}
V_6 -> V_57 . V_16 = 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
F_13 ( V_2 ) ;
F_1 ( V_2 ) ;
F_9 ( V_9 , V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
F_3 ( V_2 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_62 * V_63 = V_59 -> V_64 ;
V_6 -> V_7 = 0 ;
if ( V_63 -> V_65 -> V_66 ) {
struct V_10 * V_11 = F_17 ( V_2 ) ;
struct V_67 * V_68 = F_18 ( V_11 ) ;
struct V_69 * V_70 ;
struct V_60 * V_71 ;
int V_72 = V_59 -> V_72 ;
F_19 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_71 = & V_70 -> V_73 ;
if ( F_20 ( V_61 ) != F_20 ( V_71 ) )
V_6 -> V_7 = F_20 ( V_71 ) ;
}
F_21 ( V_68 , L_1 , V_6 -> V_7 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_62 * V_74 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_75 ;
V_75 = F_23 ( V_2 , V_9 , V_74 , L_2 ,
V_76 ,
NULL ,
& V_6 -> V_17 , V_15 ,
0xC ) ;
V_75 = F_23 ( V_2 , V_9 , V_74 , L_3 ,
V_76 ,
NULL ,
& V_6 -> V_22 , V_15 ,
0x00FFFFFF ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_23 ( V_2 , V_9 , V_74 , L_4 ,
V_76 ,
NULL ,
& V_6 -> V_31 , V_15 ,
0x00FFFFFF ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_23 ( V_2 , V_9 , V_74 , L_5 ,
V_76 ,
NULL ,
& V_6 -> V_40 , V_15 ,
0x00FFFFFF ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_23 ( V_2 , V_9 , V_74 , L_6 ,
V_76 ,
NULL ,
& V_6 -> V_49 , V_15 ,
0x00FFFFFF ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_24 ( V_2 , V_9 , V_74 , L_7 ,
V_76 ,
F_11 ,
& V_6 -> V_57 , 1 ) ;
return V_75 ;
}
struct V_1 * F_25 ( struct V_10 * V_11 , int V_77 )
{
if ( F_26 ( V_77 < 0 || V_77 >= F_27 ( V_11 ) ) )
V_77 = 0 ;
return F_28 ( F_29 ( V_11 , V_77 ) ) ;
}
int F_30 ( struct V_10 * V_11 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 ;
struct V_67 * V_68 = F_18 ( V_11 ) ;
struct V_5 * V_6 ;
struct V_81 * V_81 ;
char V_82 [ V_83 ] ;
int V_14 , V_84 , V_75 ;
if ( F_31 ( V_11 ) )
return 0 ;
V_79 = F_32 ( V_11 ) ;
if ( ! V_79 )
return 0 ;
V_84 = F_33 ( V_79 ) ;
if ( ! V_84 ) {
V_75 = - V_85 ;
goto V_86;
}
V_6 = F_34 ( V_68 , sizeof( * V_6 ) * V_84 , V_87 ) ;
if ( ! V_6 ) {
V_75 = - V_88 ;
goto V_86;
}
V_11 -> V_89 = V_84 ;
V_11 -> V_6 = V_6 ;
V_14 = 0 ;
V_75 = 0 ;
F_35 (node, np) {
V_6 = F_29 ( V_11 , V_14 ) ;
snprintf ( V_82 , V_83 , L_8 ,
V_90 , V_14 / 4 ) ;
V_81 = F_36 ( V_68 , V_82 ) ;
if ( F_37 ( V_81 ) ) {
V_75 = F_38 ( V_81 ) ;
F_39 ( V_80 ) ;
goto V_86;
}
V_75 = F_40 ( V_11 , F_28 ( V_6 ) , & V_91 ,
V_81 , V_92 , V_93 , V_14 ) ;
if ( V_75 ) {
F_39 ( V_80 ) ;
goto V_86;
}
V_14 ++ ;
}
V_86:
F_39 ( V_79 ) ;
return V_75 ;
}
void F_41 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int V_14 ;
F_42 (ctu, priv, i) {
F_43 ( F_28 ( V_6 ) ) ;
}
}
