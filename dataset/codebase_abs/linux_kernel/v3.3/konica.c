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
V_15 -> V_21 = V_22 ;
V_15 -> V_23 = V_24 ;
V_15 -> V_25 = V_26 ;
V_15 -> V_27 = V_28 ;
V_15 -> V_29 = V_30 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
F_5 ( V_1 , 0 , 0x10 ) ;
F_12 ( V_31 , L_2 ,
V_1 -> V_12 [ 0 ] , V_1 -> V_12 [ 1 ] ) ;
F_5 ( V_1 , 0 , 0x10 ) ;
F_12 ( V_31 , L_2 ,
V_1 -> V_12 [ 0 ] , V_1 -> V_12 [ 1 ] ) ;
F_1 ( V_1 , 0 , 0x0d ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
struct V_32 * V_32 ;
int V_33 , V_34 , V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
V_39 = F_14 ( V_15 -> V_1 . V_5 , V_15 -> V_1 . V_40 ) ;
V_37 = F_15 ( V_39 , V_15 -> V_1 . V_37 ) ;
if ( ! V_37 ) {
F_4 ( L_3 ) ;
return - V_41 ;
}
V_35 = F_16 ( V_37 -> V_42 [ 0 ] . V_43 . V_44 ) ;
F_1 ( V_1 , V_15 -> V_21 , V_45 ) ;
F_1 ( V_1 , V_15 -> V_27 , V_46 ) ;
F_1 ( V_1 , V_15 -> V_23 , V_47 ) ;
F_1 ( V_1 , V_15 -> V_25 , V_48 ) ;
F_1 ( V_1 , V_15 -> V_29 , V_49 ) ;
V_34 = V_1 -> V_16 . V_17 [ V_1 -> V_50 ] . V_51 ;
F_1 ( V_1 , V_34 , 0x08 ) ;
F_7 ( V_1 ) ;
if ( V_1 -> V_7 )
return V_1 -> V_7 ;
#if V_52 < 4
#error "Not enough URBs in the gspca table"
#endif
#define F_17 32
for ( V_34 = 0 ; V_34 < 4 ; V_34 ++ ) {
V_33 = V_34 & 1 ? 0 : 1 ;
V_35 =
F_16 ( V_37 -> V_42 [ V_33 ] . V_43 . V_44 ) ;
V_32 = F_18 ( F_17 , V_53 ) ;
if ( ! V_32 ) {
F_4 ( L_4 ) ;
return - V_54 ;
}
V_1 -> V_32 [ V_34 ] = V_32 ;
V_32 -> V_55 = F_19 ( V_1 -> V_5 ,
V_35 * F_17 ,
V_53 ,
& V_32 -> V_56 ) ;
if ( V_32 -> V_55 == NULL ) {
F_4 ( L_5 ) ;
return - V_54 ;
}
V_32 -> V_5 = V_1 -> V_5 ;
V_32 -> V_57 = V_1 ;
V_32 -> V_58 = V_35 * F_17 ;
V_32 -> V_59 = F_20 ( V_1 -> V_5 ,
V_34 & 1 ? 0x81 : 0x82 ) ;
V_32 -> V_60 = V_61
| V_62 ;
V_32 -> V_63 = 1 ;
V_32 -> V_64 = V_65 ;
V_32 -> V_66 = F_17 ;
for ( V_33 = 0 ; V_33 < F_17 ; V_33 ++ ) {
V_32 -> V_67 [ V_33 ] . V_68 = V_35 ;
V_32 -> V_67 [ V_33 ] . V_69 = V_35 * V_33 ;
}
}
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
F_8 ( V_1 ) ;
#if F_22 ( V_70 ) || F_22 ( V_71 )
if ( V_15 -> V_72 ) {
F_23 ( V_1 -> V_73 , V_74 , 0 ) ;
F_24 ( V_1 -> V_73 ) ;
V_15 -> V_72 = 0 ;
}
#endif
}
static void V_65 ( struct V_32 * V_32 )
{
struct V_1 * V_1 = (struct V_1 * ) V_32 -> V_57 ;
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
struct V_32 * V_75 , * V_76 ;
T_2 * V_77 ;
int V_33 , V_78 ;
F_12 ( V_79 , L_6 ) ;
if ( ! V_1 -> V_80 )
return;
if ( V_32 -> V_81 != 0 ) {
if ( V_32 -> V_81 == - V_82 )
return;
#ifdef F_25
if ( V_1 -> V_83 )
return;
#endif
F_12 ( V_84 , L_7 , V_32 -> V_81 ) ;
V_78 = F_26 ( V_32 , V_85 ) ;
if ( V_78 < 0 )
F_4 ( L_8 , V_78 ) ;
return;
}
if ( V_32 -> V_58 > 32 ) {
V_15 -> V_86 = V_32 ;
return;
}
V_76 = V_32 ;
V_75 = V_15 -> V_86 ;
V_15 -> V_86 = NULL ;
if ( ! V_75 || V_75 -> V_87 != V_76 -> V_87 ) {
F_12 ( V_84 | V_79 , L_9 ) ;
goto V_88;
}
if ( V_75 -> V_66 != V_76 -> V_66 ) {
F_12 ( V_84 | V_79 ,
L_10 ,
V_75 -> V_66 ,
V_76 -> V_66 ) ;
goto V_88;
}
for ( V_33 = 0 ; V_33 < V_76 -> V_66 ; V_33 ++ ) {
if ( V_75 -> V_67 [ V_33 ] . V_81 ||
V_76 -> V_67 [ V_33 ] . V_81 ) {
F_12 ( V_84 | V_79 ,
L_11 , V_33 ,
V_75 -> V_67 [ V_33 ] . V_81 ,
V_76 -> V_67 [ V_33 ] . V_81 ) ;
V_1 -> V_89 = V_90 ;
continue;
}
if ( V_76 -> V_67 [ V_33 ] . V_91 != 1 ) {
F_12 ( V_84 | V_79 ,
L_12 ,
V_76 -> V_67 [ V_33 ] . V_91 ) ;
V_1 -> V_89 = V_90 ;
continue;
}
V_78 = * ( ( T_2 * ) V_76 -> V_55
+ V_76 -> V_67 [ V_33 ] . V_69 ) ;
V_77 = ( T_2 * ) V_75 -> V_55
+ V_75 -> V_67 [ V_33 ] . V_69 ;
if ( V_78 & 0x80 ) {
F_27 ( V_1 , V_92 , NULL , 0 ) ;
F_27 ( V_1 , V_93 , NULL , 0 ) ;
} else {
#if F_22 ( V_70 ) || F_22 ( V_71 )
T_2 V_94 = V_78 & 0x40 ? 1 : 0 ;
if ( V_15 -> V_72 != V_94 ) {
F_23 ( V_1 -> V_73 ,
V_74 ,
V_94 ) ;
F_24 ( V_1 -> V_73 ) ;
V_15 -> V_72 = V_94 ;
}
#endif
if ( V_78 & 0x01 )
continue;
}
F_27 ( V_1 , V_95 , V_77 ,
V_75 -> V_67 [ V_33 ] . V_91 ) ;
}
V_88:
if ( V_75 ) {
V_78 = F_26 ( V_75 , V_85 ) ;
if ( V_78 < 0 )
F_12 ( V_84 | V_79 ,
L_13 , V_78 ) ;
}
V_78 = F_26 ( V_76 , V_85 ) ;
if ( V_78 < 0 )
F_4 ( L_14 , V_78 ) ;
}
static int F_28 ( struct V_1 * V_1 , T_3 V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_21 = V_96 ;
if ( V_1 -> V_80 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_21 , V_45 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , T_3 * V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_96 = V_15 -> V_21 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_3 V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_23 = V_96 ;
if ( V_1 -> V_80 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_23 , V_47 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , T_3 * V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_96 = V_15 -> V_23 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_3 V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_25 = V_96 ;
if ( V_1 -> V_80 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_25 , V_48 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , T_3 * V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_96 = V_15 -> V_25 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_3 V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_27 = V_96 ;
if ( V_1 -> V_80 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_27 , V_46 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_3 * V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_96 = V_15 -> V_27 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , T_3 V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
V_15 -> V_29 = V_96 ;
if ( V_1 -> V_80 ) {
F_8 ( V_1 ) ;
F_1 ( V_1 , V_15 -> V_29 , V_49 ) ;
F_7 ( V_1 ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_3 * V_96 )
{
struct V_15 * V_15 = (struct V_15 * ) V_1 ;
* V_96 = V_15 -> V_29 ;
return 0 ;
}
static int F_38 ( struct V_38 * V_39 ,
const struct V_13 * V_14 )
{
return F_39 ( V_39 , V_14 , & V_97 , sizeof( struct V_15 ) ,
V_98 ) ;
}
