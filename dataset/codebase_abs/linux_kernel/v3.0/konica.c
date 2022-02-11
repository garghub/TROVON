static void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
if ( V_1 -> V_7 < 0 )
return;
V_6 = F_2 ( V_5 , F_3 ( V_5 , 0 ) ,
0x02 ,
V_8 | V_9 | V_10 ,
V_2 ,
V_3 ,
NULL ,
0 ,
1000 ) ;
if ( V_6 < 0 ) {
F_4 ( L_1 , V_6 ) ;
V_1 -> V_7 = V_6 ;
}
}
static void F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_6 ;
if ( V_1 -> V_7 < 0 )
return;
V_6 = F_2 ( V_5 , F_6 ( V_5 , 0 ) ,
0x03 ,
V_11 | V_9 | V_10 ,
V_2 ,
V_3 ,
V_1 -> V_12 ,
2 ,
1000 ) ;
if ( V_6 < 0 ) {
F_4 ( L_1 , V_6 ) ;
V_1 -> V_7 = V_6 ;
}
}
static void F_7 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 1 , 0x0b ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0 , 0x0b ) ;
}
static int F_9 ( struct V_1 * V_1 ,
const struct V_13 * V_14 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_1 -> V_16 . V_17 = V_18 ;
V_1 -> V_16 . V_19 = F_10 ( V_18 ) ;
V_1 -> V_16 . V_20 = 1 ;
V_1 -> V_21 -- ;
V_15 -> V_22 = V_23 ;
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = V_27 ;
V_15 -> V_28 = V_29 ;
V_15 -> V_30 = V_31 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0 , 0x10 ) ;
F_12 ( V_32 , L_2 ,
V_1 -> V_12 [ 0 ] , V_1 -> V_12 [ 1 ] ) ;
F_5 ( V_1 , 0 , 0x10 ) ;
F_12 ( V_32 , L_2 ,
V_1 -> V_12 [ 0 ] , V_1 -> V_12 [ 1 ] ) ;
F_1 ( V_1 , 0 , 0x0d ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
struct V_33 * V_33 ;
int V_34 , V_35 , V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
V_40 = F_14 ( V_15 -> V_1 . V_5 , V_15 -> V_1 . V_41 ) ;
V_38 = F_15 ( V_40 , V_15 -> V_1 . V_38 ) ;
if ( ! V_38 ) {
F_4 ( L_3 ) ;
return - V_42 ;
}
V_36 = F_16 ( V_38 -> V_43 [ 0 ] . V_44 . V_45 ) ;
F_1 ( V_1 , V_15 -> V_22 , V_46 ) ;
F_1 ( V_1 , V_15 -> V_28 , V_47 ) ;
F_1 ( V_1 , V_15 -> V_24 , V_48 ) ;
F_1 ( V_1 , V_15 -> V_26 , V_49 ) ;
F_1 ( V_1 , V_15 -> V_30 , V_50 ) ;
V_35 = V_1 -> V_16 . V_17 [ V_1 -> V_51 ] . V_52 ;
F_1 ( V_1 , V_35 , 0x08 ) ;
F_7 ( V_1 ) ;
if ( V_1 -> V_7 )
return V_1 -> V_7 ;
#if V_53 < 4
#error "Not enough URBs in the gspca table"
#endif
#define F_17 32
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_34 = V_35 & 1 ? 0 : 1 ;
V_36 =
F_16 ( V_38 -> V_43 [ V_34 ] . V_44 . V_45 ) ;
V_33 = F_18 ( F_17 , V_54 ) ;
if ( ! V_33 ) {
F_4 ( L_4 ) ;
return - V_55 ;
}
V_1 -> V_33 [ V_35 ] = V_33 ;
V_33 -> V_56 = F_19 ( V_1 -> V_5 ,
V_36 * F_17 ,
V_54 ,
& V_33 -> V_57 ) ;
if ( V_33 -> V_56 == NULL ) {
F_4 ( L_5 ) ;
return - V_55 ;
}
V_33 -> V_5 = V_1 -> V_5 ;
V_33 -> V_58 = V_1 ;
V_33 -> V_59 = V_36 * F_17 ;
V_33 -> V_60 = F_20 ( V_1 -> V_5 ,
V_35 & 1 ? 0x81 : 0x82 ) ;
V_33 -> V_61 = V_62
| V_63 ;
V_33 -> V_64 = 1 ;
V_33 -> V_65 = V_66 ;
V_33 -> V_67 = F_17 ;
for ( V_34 = 0 ; V_34 < F_17 ; V_34 ++ ) {
V_33 -> V_68 [ V_34 ] . V_69 = V_36 ;
V_33 -> V_68 [ V_34 ] . V_70 = V_36 * V_34 ;
}
}
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
F_8 ( V_1 ) ;
#if F_22 ( V_71 ) || F_22 ( V_72 )
if ( V_15 -> V_73 ) {
F_23 ( V_1 -> V_74 , V_75 , 0 ) ;
F_24 ( V_1 -> V_74 ) ;
V_15 -> V_73 = 0 ;
}
#endif
}
static void V_66 ( struct V_33 * V_33 )
{
struct V_1 * V_1 = (struct V_1 * ) V_33 -> V_58 ;
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
struct V_33 * V_76 , * V_77 ;
T_2 * V_78 ;
int V_34 , V_79 ;
F_12 ( V_80 , L_6 ) ;
if ( ! V_1 -> V_81 )
return;
if ( V_33 -> V_82 != 0 ) {
if ( V_33 -> V_82 == - V_83 )
return;
#ifdef F_25
if ( V_1 -> V_84 )
return;
#endif
F_12 ( V_85 , L_7 , V_33 -> V_82 ) ;
V_79 = F_26 ( V_33 , V_86 ) ;
if ( V_79 < 0 )
F_4 ( L_8 , V_79 ) ;
return;
}
if ( V_33 -> V_59 > 32 ) {
V_15 -> V_87 = V_33 ;
return;
}
V_77 = V_33 ;
V_76 = V_15 -> V_87 ;
V_15 -> V_87 = NULL ;
if ( ! V_76 || V_76 -> V_88 != V_77 -> V_88 ) {
F_12 ( V_85 | V_80 , L_9 ) ;
goto V_89;
}
if ( V_76 -> V_67 != V_77 -> V_67 ) {
F_12 ( V_85 | V_80 ,
L_10 ,
V_76 -> V_67 ,
V_77 -> V_67 ) ;
goto V_89;
}
for ( V_34 = 0 ; V_34 < V_77 -> V_67 ; V_34 ++ ) {
if ( V_76 -> V_68 [ V_34 ] . V_82 ||
V_77 -> V_68 [ V_34 ] . V_82 ) {
F_12 ( V_85 | V_80 ,
L_11 , V_34 ,
V_76 -> V_68 [ V_34 ] . V_82 ,
V_77 -> V_68 [ V_34 ] . V_82 ) ;
V_1 -> V_90 = V_91 ;
continue;
}
if ( V_77 -> V_68 [ V_34 ] . V_92 != 1 ) {
F_12 ( V_85 | V_80 ,
L_12 ,
V_77 -> V_68 [ V_34 ] . V_92 ) ;
V_1 -> V_90 = V_91 ;
continue;
}
V_79 = * ( ( T_2 * ) V_77 -> V_56
+ V_77 -> V_68 [ V_34 ] . V_70 ) ;
V_78 = ( T_2 * ) V_76 -> V_56
+ V_76 -> V_68 [ V_34 ] . V_70 ;
if ( V_79 & 0x80 ) {
F_27 ( V_1 , V_93 , NULL , 0 ) ;
F_27 ( V_1 , V_94 , NULL , 0 ) ;
} else {
#if F_22 ( V_71 ) || F_22 ( V_72 )
T_2 V_95 = V_79 & 0x40 ? 1 : 0 ;
if ( V_15 -> V_73 != V_95 ) {
F_23 ( V_1 -> V_74 ,
V_75 ,
V_95 ) ;
F_24 ( V_1 -> V_74 ) ;
V_15 -> V_73 = V_95 ;
}
#endif
if ( V_79 & 0x01 )
continue;
}
F_27 ( V_1 , V_96 , V_78 ,
V_76 -> V_68 [ V_34 ] . V_92 ) ;
}
V_89:
if ( V_76 ) {
V_79 = F_26 ( V_76 , V_86 ) ;
if ( V_79 < 0 )
F_12 ( V_85 | V_80 ,
L_13 , V_79 ) ;
}
V_79 = F_26 ( V_77 , V_86 ) ;
if ( V_79 < 0 )
F_4 ( L_14 , V_79 ) ;
}
static int F_28 ( struct V_1 * V_1 , T_3 V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_22 = V_97 ;
if ( V_1 -> V_81 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_22 , V_46 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , T_3 * V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_97 = V_15 -> V_22 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_3 V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_24 = V_97 ;
if ( V_1 -> V_81 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_24 , V_48 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , T_3 * V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_97 = V_15 -> V_24 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_3 V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_26 = V_97 ;
if ( V_1 -> V_81 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_26 , V_49 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , T_3 * V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_97 = V_15 -> V_26 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_3 V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_28 = V_97 ;
if ( V_1 -> V_81 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_28 , V_47 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_3 * V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_97 = V_15 -> V_28 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , T_3 V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_30 = V_97 ;
if ( V_1 -> V_81 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_30 , V_50 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_3 * V_97 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_97 = V_15 -> V_30 ;
return 0 ;
}
static int F_38 ( struct V_39 * V_40 ,
const struct V_13 * V_14 )
{
return F_39 ( V_40 , V_14 , & V_98 , sizeof( struct V_15 ) ,
V_99 ) ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_100 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_100 ) ;
}
