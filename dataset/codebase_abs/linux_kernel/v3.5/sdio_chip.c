T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
if ( V_3 == V_2 -> V_6 [ V_4 ] . V_7 )
return V_4 ;
return V_5 ;
}
static T_3
F_2 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_10 ;
T_1 V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_12 ) ,
NULL ) ;
return F_5 ( V_10 ) ;
}
static T_3
F_6 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
return ( V_2 -> V_6 [ V_4 ] . V_13 & V_14 ) >> V_15 ;
}
static bool
F_7 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_10 ;
T_1 V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_16 ) ,
NULL ) ;
V_10 &= ( V_17 | V_18 |
V_19 | V_20 ) ;
return ( V_20 == V_10 ) ;
}
static bool
F_8 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_10 ;
T_1 V_4 ;
bool V_21 ;
V_4 = F_1 ( V_2 , V_3 ) ;
V_10 = F_3 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_23 ,
NULL ) ;
V_21 = ( V_10 & ( V_24 | V_25 ) ) == V_25 ;
V_10 = F_3 ( V_9 ,
V_2 -> V_6 [ V_4 ] . V_22 + V_26 ,
NULL ) ;
V_21 = V_21 && ( ( V_10 & V_27 ) == 0 ) ;
return V_21 ;
}
static void
F_9 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_10 , V_11 ;
T_1 V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
V_11 = V_2 -> V_6 [ V_4 ] . V_11 ;
V_10 = F_3 ( V_9 , F_4 ( V_11 , V_16 ) , NULL ) ;
if ( V_10 & V_17 )
return;
V_10 = F_3 ( V_9 , F_4 ( V_11 , V_16 ) , NULL ) ;
if ( ( V_10 & V_20 ) != 0 ) {
V_10 = F_3 ( V_9 , F_4 ( V_11 , V_16 ) ,
NULL ) ;
F_10 ( V_9 , F_4 ( V_11 , V_16 ) ,
V_10 | V_18 , NULL ) ;
V_10 = F_3 ( V_9 , F_4 ( V_11 , V_16 ) ,
NULL ) ;
F_11 ( 1 ) ;
F_12 ( ( F_3 ( V_9 ,
F_4 ( V_11 , V_28 ) ,
NULL ) &
V_29 ) , 100000 ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_11 , V_28 ) ,
NULL ) ;
if ( V_10 & V_29 )
F_13 ( ERROR , L_1 ) ;
V_10 = F_3 ( V_9 , F_4 ( V_11 , V_30 ) ,
NULL ) ;
if ( V_10 & V_31 ) {
V_10 = F_3 ( V_9 ,
F_4 ( V_11 , V_32 ) ,
NULL ) ;
V_10 |= V_19 ;
F_10 ( V_9 , F_4 ( V_11 , V_32 ) ,
V_10 , NULL ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_11 , V_32 ) ,
NULL ) ;
F_11 ( 1 ) ;
F_12 ( ( F_3 ( V_9 ,
F_4 ( V_11 , V_32 ) ,
NULL ) &
V_33 ) , 100000 ) ;
}
V_10 = V_34 | V_20 |
V_18 | V_17 ;
F_10 ( V_9 , F_4 ( V_11 , V_16 ) ,
V_10 , NULL ) ;
V_10 = F_3 ( V_9 , F_4 ( V_11 , V_16 ) ,
NULL ) ;
F_11 ( 10 ) ;
V_10 = F_3 ( V_9 , F_4 ( V_11 , V_30 ) ,
NULL ) ;
if ( V_10 & V_31 ) {
V_10 = F_3 ( V_9 ,
F_4 ( V_11 , V_32 ) ,
NULL ) ;
V_10 &= ~ V_19 ;
F_10 ( V_9 , F_4 ( V_11 , V_32 ) ,
V_10 , NULL ) ;
}
}
F_10 ( V_9 , F_4 ( V_11 , V_16 ) ,
( V_18 | V_17 ) , NULL ) ;
F_11 ( 1 ) ;
}
static void
F_14 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
T_3 V_10 ;
V_4 = F_1 ( V_2 , V_3 ) ;
V_10 = F_3 ( V_9 ,
V_2 -> V_6 [ V_4 ] . V_22 + V_26 ,
NULL ) ;
if ( ( V_10 & V_27 ) != 0 )
return;
F_10 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_23 , 0 , NULL ) ;
V_10 = F_3 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_23 ,
NULL ) ;
F_11 ( 10 ) ;
F_10 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_26 ,
V_27 , NULL ) ;
F_11 ( 1 ) ;
}
static void
F_15 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_10 ;
T_1 V_4 ;
V_4 = F_1 ( V_2 , V_3 ) ;
F_9 ( V_9 , V_2 , V_3 ) ;
F_10 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_16 ) ,
V_34 | V_20 | V_17 ,
NULL ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_16 ) ,
NULL ) ;
F_11 ( 1 ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_28 ) ,
NULL ) ;
if ( V_10 & V_35 )
F_10 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_28 ) ,
0 , NULL ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_32 ) ,
NULL ) ;
if ( V_10 & ( V_36 | V_37 ) )
F_10 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_32 ) ,
V_10 & ~ ( V_36 | V_37 ) ,
NULL ) ;
F_10 ( V_9 , F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_16 ) ,
V_34 | V_20 , NULL ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_16 ) ,
NULL ) ;
F_11 ( 1 ) ;
F_10 ( V_9 , F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_16 ) ,
V_20 , NULL ) ;
V_10 = F_3 ( V_9 ,
F_4 ( V_2 -> V_6 [ V_4 ] . V_11 , V_16 ) ,
NULL ) ;
F_11 ( 1 ) ;
}
static void
F_16 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
T_3 V_10 ;
V_4 = F_1 ( V_2 , V_3 ) ;
F_14 ( V_9 , V_2 , V_3 ) ;
F_10 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_23 ,
V_24 | V_25 , NULL ) ;
V_10 = F_3 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_23 ,
NULL ) ;
F_10 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_26 ,
0 , NULL ) ;
F_11 ( 1 ) ;
F_10 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_23 ,
V_25 , NULL ) ;
V_10 = F_3 ( V_9 , V_2 -> V_6 [ V_4 ] . V_22 + V_23 ,
NULL ) ;
F_11 ( 1 ) ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_3 V_38 )
{
T_3 V_10 ;
V_2 -> V_6 [ 0 ] . V_7 = V_39 ;
V_2 -> V_6 [ 0 ] . V_11 = V_38 ;
V_10 = F_3 ( V_9 ,
F_18 ( V_2 -> V_6 [ 0 ] . V_11 , V_40 ) ,
NULL ) ;
V_2 -> V_41 = V_10 & V_42 ;
V_2 -> V_43 = ( V_10 & V_44 ) >> V_45 ;
V_2 -> V_46 = ( V_10 & V_47 ) >> V_48 ;
F_13 ( V_49 , L_2 , V_2 -> V_41 , V_2 -> V_43 ) ;
switch ( V_2 -> V_41 ) {
case V_50 :
V_2 -> V_6 [ 1 ] . V_7 = V_51 ;
V_2 -> V_6 [ 1 ] . V_11 = V_52 ;
V_2 -> V_6 [ 2 ] . V_7 = V_53 ;
V_2 -> V_6 [ 2 ] . V_11 = V_54 ;
V_2 -> V_6 [ 3 ] . V_7 = V_55 ;
V_2 -> V_6 [ 3 ] . V_11 = V_56 ;
V_2 -> V_57 = V_58 ;
break;
case V_59 :
V_2 -> V_6 [ 0 ] . V_22 = 0x18100000 ;
V_2 -> V_6 [ 0 ] . V_13 = 0x27004211 ;
V_2 -> V_6 [ 1 ] . V_7 = V_51 ;
V_2 -> V_6 [ 1 ] . V_11 = 0x18002000 ;
V_2 -> V_6 [ 1 ] . V_22 = 0x18102000 ;
V_2 -> V_6 [ 1 ] . V_13 = 0x07004211 ;
V_2 -> V_6 [ 2 ] . V_7 = V_53 ;
V_2 -> V_6 [ 2 ] . V_11 = 0x18004000 ;
V_2 -> V_6 [ 2 ] . V_22 = 0x18104000 ;
V_2 -> V_6 [ 2 ] . V_13 = 0x0d080401 ;
V_2 -> V_6 [ 3 ] . V_7 = V_55 ;
V_2 -> V_6 [ 3 ] . V_11 = 0x18003000 ;
V_2 -> V_6 [ 3 ] . V_22 = 0x18103000 ;
V_2 -> V_6 [ 3 ] . V_13 = 0x03004211 ;
V_2 -> V_57 = 0x48000 ;
break;
default:
F_13 ( ERROR , L_3 , V_2 -> V_41 ) ;
return - V_60 ;
}
switch ( V_2 -> V_46 ) {
case V_61 :
V_2 -> V_62 = F_7 ;
V_2 -> V_63 = F_2 ;
V_2 -> V_64 = F_9 ;
V_2 -> V_65 = F_15 ;
break;
case V_66 :
V_2 -> V_62 = F_8 ;
V_2 -> V_63 = F_6 ;
V_2 -> V_64 = F_14 ;
V_2 -> V_65 = F_16 ;
break;
default:
F_13 ( ERROR , L_4 , V_2 -> V_46 ) ;
return - V_60 ;
}
return 0 ;
}
static int
F_19 ( struct V_8 * V_9 )
{
int V_67 = 0 ;
T_1 V_68 , V_69 ;
V_69 = V_70 | V_71 ;
F_20 ( V_9 , V_72 , V_69 , & V_67 ) ;
if ( V_67 ) {
F_13 ( ERROR , L_5 ) ;
return V_67 ;
}
V_68 = F_21 ( V_9 ,
V_72 , NULL ) ;
if ( ( V_68 & ~ V_73 ) != V_69 ) {
F_13 ( ERROR , L_6 ,
V_69 , V_68 ) ;
return - V_74 ;
}
F_12 ( ( ( V_68 = F_21 ( V_9 ,
V_72 , NULL ) ) ,
! F_22 ( V_68 ) ) ,
V_75 ) ;
if ( ! F_22 ( V_68 ) ) {
F_13 ( ERROR , L_7 ,
V_68 ) ;
return - V_76 ;
}
V_69 = V_70 | V_77 ;
F_20 ( V_9 , V_72 , V_69 , & V_67 ) ;
F_11 ( 65 ) ;
F_20 ( V_9 , V_78 , 0 , NULL ) ;
return 0 ;
}
static void
F_23 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
T_3 V_11 = V_2 -> V_6 [ 0 ] . V_11 ;
V_2 -> V_6 [ 0 ] . V_79 = V_2 -> V_63 ( V_9 , V_2 , V_2 -> V_6 [ 0 ] . V_7 ) ;
V_2 -> V_6 [ 0 ] . V_80 = F_3 ( V_9 ,
F_18 ( V_11 , V_81 ) ,
NULL ) ;
if ( V_2 -> V_6 [ 0 ] . V_80 & V_82 ) {
V_2 -> V_83 =
F_3 ( V_9 ,
F_18 ( V_11 , V_84 ) ,
NULL ) ;
V_2 -> V_85 = V_2 -> V_83 & V_86 ;
}
V_2 -> V_6 [ 1 ] . V_79 = V_2 -> V_63 ( V_9 , V_2 , V_2 -> V_6 [ 1 ] . V_7 ) ;
F_13 ( V_49 , L_8 ,
V_2 -> V_6 [ 0 ] . V_79 , V_2 -> V_85 ,
V_2 -> V_6 [ 1 ] . V_79 , V_2 -> V_6 [ 1 ] . V_7 ) ;
V_2 -> V_64 ( V_9 , V_2 , V_55 ) ;
}
int F_24 ( struct V_8 * V_9 ,
struct V_1 * * V_87 , T_3 V_38 )
{
int V_21 ;
struct V_1 * V_2 ;
F_13 ( V_88 , L_9 ) ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
V_21 = F_19 ( V_9 ) ;
if ( V_21 != 0 )
goto V_67;
V_21 = F_17 ( V_9 , V_2 , V_38 ) ;
if ( V_21 != 0 )
goto V_67;
F_23 ( V_9 , V_2 ) ;
F_10 ( V_9 , F_18 ( V_2 -> V_6 [ 0 ] . V_11 , V_91 ) ,
0 , NULL ) ;
F_10 ( V_9 , F_18 ( V_2 -> V_6 [ 0 ] . V_11 , V_92 ) ,
0 , NULL ) ;
* V_87 = V_2 ;
return 0 ;
V_67:
F_26 ( V_2 ) ;
return V_21 ;
}
void
F_27 ( struct V_1 * * V_87 )
{
F_13 ( V_88 , L_9 ) ;
F_26 ( * V_87 ) ;
* V_87 = NULL ;
}
static char * F_28 ( T_4 V_40 , char * V_93 , T_4 V_94 )
{
const char * V_95 ;
V_95 = ( ( V_40 > 0xa000 ) || ( V_40 < 0x4000 ) ) ? L_10 : L_11 ;
snprintf ( V_93 , V_94 , V_95 , V_40 ) ;
return V_93 ;
}
void
F_29 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_3 V_96 )
{
struct V_97 * V_98 = NULL ;
T_3 V_99 = 0 ;
T_3 V_100 = 0 ;
char V_101 [ 8 ] ;
T_3 V_11 = V_2 -> V_6 [ 0 ] . V_11 ;
if ( ! ( V_2 -> V_6 [ 0 ] . V_80 & V_82 ) )
return;
switch ( F_30 ( V_2 -> V_41 , V_2 -> V_85 ) ) {
case F_30 ( V_59 , 12 ) :
V_98 = (struct V_97 * ) & V_102 ;
V_99 = 0x00003800 ;
V_100 = 11 ;
break;
default:
F_13 ( ERROR , L_12 ,
F_28 ( V_2 -> V_41 , V_101 , 8 ) ,
V_2 -> V_43 , V_2 -> V_85 ) ;
break;
}
if ( V_98 != NULL ) {
T_3 V_103 = 0 ;
T_3 V_104 ;
int V_105 ;
for ( V_105 = 0 ; V_98 [ V_105 ] . V_106 != 0 ; V_105 ++ ) {
if ( V_96 >= V_98 [ V_105 ] . V_106 ) {
V_103 = V_98 [ V_105 ] . V_107 ;
break;
}
}
F_10 ( V_9 , F_18 ( V_11 , V_108 ) ,
1 , NULL ) ;
V_104 =
F_3 ( V_9 ,
F_18 ( V_11 , V_108 ) ,
NULL ) ;
V_104 &= ~ V_99 ;
V_103 <<= V_100 ;
V_104 |= V_103 ;
F_10 ( V_9 , F_18 ( V_11 , V_108 ) ,
V_104 , NULL ) ;
F_13 ( V_49 , L_13 ,
V_96 , V_104 ) ;
}
}
