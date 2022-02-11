static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 <= V_4 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_9 , V_10 , V_11 ;
if ( V_8 -> V_12 ) {
V_11 = 1 ;
for ( V_10 = 2 ; V_10 < F_5 ( V_13 ) ; V_10 ++ ) {
if ( abs ( V_13 [ V_10 ] - V_8 -> V_14 ) <
abs ( V_13 [ V_11 ] - V_8 -> V_14 ) )
V_11 = V_10 ;
}
V_9 = V_11 << 1 ;
} else {
V_11 = 0 ;
V_9 = 0 ;
}
F_6 ( V_6 -> V_2 , L_1 ,
V_11 , V_13 [ V_11 ] ) ;
return F_7 ( V_6 , V_15 , 0x6 , V_9 ) ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_9 ( V_17 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
V_19 -> V_20 . integer . V_20 [ 0 ] = V_8 -> V_12 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_9 ( V_17 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_12 = V_19 -> V_20 . integer . V_20 [ 0 ] ;
int V_21 = 0 ;
if ( V_12 > 1 )
return - V_22 ;
F_11 ( & V_8 -> V_23 ) ;
if ( V_8 -> V_12 != V_12 ) {
V_8 -> V_12 = V_12 ;
F_3 ( V_6 ) ;
V_21 = 1 ;
}
F_12 ( & V_8 -> V_23 ) ;
return V_21 ;
}
static int F_13 ( struct V_24 * V_25 ,
struct V_24 * V_26 )
{
struct V_5 * V_6 = F_14 ( V_25 -> V_27 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
return V_8 -> V_28 == V_29 ;
}
static inline int F_15 ( int V_30 , int V_31 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_32 ) ; V_10 ++ ) {
if ( V_32 [ V_10 ] . V_31 == V_31 && V_32 [ V_10 ] . V_30 == V_30 )
return V_10 ;
}
return 0 ;
}
static int F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = V_38 -> V_6 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
T_1 V_39 = F_17 ( V_6 , V_40 ) & 0xfff3 ;
int V_10 = F_15 ( V_8 -> V_41 , F_18 ( V_36 ) ) ;
T_1 V_42 = ( V_32 [ V_10 ] . V_43 << 2 ) |
( V_32 [ V_10 ] . V_44 << 1 ) | V_32 [ V_10 ] . V_45 ;
V_8 -> V_14 = F_18 ( V_36 ) ;
F_19 ( V_6 , V_46 , V_42 ) ;
switch ( F_20 ( V_36 ) ) {
case 16 :
break;
case 20 :
V_39 |= 0x0004 ;
break;
case 24 :
V_39 |= 0x0008 ;
break;
}
F_3 ( V_6 ) ;
F_19 ( V_6 , V_40 , V_39 ) ;
return 0 ;
}
static int F_21 ( struct V_37 * V_38 , int V_47 )
{
struct V_5 * V_6 = V_38 -> V_6 ;
T_1 V_48 = F_17 ( V_6 , V_15 ) & 0xfff7 ;
if ( V_47 )
F_19 ( V_6 , V_15 , V_48 | 0x8 ) ;
else
F_19 ( V_6 , V_15 , V_48 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_49 ,
int V_50 , unsigned int V_51 , int V_52 )
{
struct V_5 * V_6 = V_49 -> V_6 ;
struct V_53 * V_27 = F_23 ( V_6 ) ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
switch ( V_50 ) {
case V_29 :
case V_54 :
if ( V_8 -> V_30 && F_24 ( V_8 -> V_30 , V_51 ) )
return - V_22 ;
V_8 -> V_28 = V_50 ;
break;
default:
return - V_22 ;
}
switch ( V_51 ) {
case 0 :
V_8 -> V_55 = NULL ;
break;
case 12000000 :
V_8 -> V_55 = & V_56 ;
break;
case 12288000 :
case 18432000 :
V_8 -> V_55 = & V_57 ;
break;
case 16934400 :
case 11289600 :
V_8 -> V_55 = & V_58 ;
break;
default:
return - V_22 ;
}
V_8 -> V_41 = V_51 ;
F_25 ( V_27 ) ;
return 0 ;
}
static int F_26 ( struct V_37 * V_49 ,
unsigned int V_59 )
{
struct V_5 * V_6 = V_49 -> V_6 ;
T_1 V_39 = 0 ;
switch ( V_59 & V_60 ) {
case V_61 :
V_39 |= 0x0040 ;
break;
case V_62 :
break;
default:
return - V_22 ;
}
switch ( V_59 & V_63 ) {
case V_64 :
V_39 |= 0x0002 ;
break;
case V_65 :
break;
case V_66 :
V_39 |= 0x0001 ;
break;
case V_67 :
V_39 |= 0x0013 ;
break;
case V_68 :
V_39 |= 0x0003 ;
break;
default:
return - V_22 ;
}
switch ( V_59 & V_69 ) {
case V_70 :
break;
case V_71 :
V_39 |= 0x0090 ;
break;
case V_72 :
V_39 |= 0x0080 ;
break;
case V_73 :
V_39 |= 0x0010 ;
break;
default:
return - V_22 ;
}
F_19 ( V_6 , V_40 , V_39 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
enum V_74 V_75 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_21 ;
T_1 V_3 ;
switch ( V_75 ) {
case V_76 :
if ( V_8 -> V_30 )
F_28 ( V_8 -> V_30 ) ;
break;
case V_77 :
break;
case V_78 :
if ( F_29 ( V_6 ) == V_79 ) {
V_21 = F_30 ( F_5 ( V_8 -> V_80 ) ,
V_8 -> V_80 ) ;
if ( V_21 != 0 )
return V_21 ;
F_31 ( V_8 -> V_81 ) ;
}
V_3 = F_17 ( V_6 , V_82 ) & 0xff7f ;
F_19 ( V_6 , V_82 , V_3 | 0x0040 ) ;
break;
case V_79 :
if ( V_8 -> V_30 )
F_32 ( V_8 -> V_30 ) ;
F_19 ( V_6 , V_82 , 0xffff ) ;
F_33 ( F_5 ( V_8 -> V_80 ) ,
V_8 -> V_80 ) ;
F_34 ( V_8 -> V_81 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_33 * V_34 ,
struct V_37 * V_38 )
{
struct V_7 * V_8 = F_4 ( V_38 -> V_6 ) ;
if ( V_8 -> V_55 )
F_36 ( V_34 -> V_83 , 0 ,
V_84 ,
V_8 -> V_55 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
int V_21 = 0 , V_10 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_8 -> V_80 ) ; V_10 ++ )
V_8 -> V_80 [ V_10 ] . V_85 = V_86 [ V_10 ] ;
V_21 = F_38 ( V_6 -> V_2 , F_5 ( V_8 -> V_80 ) ,
V_8 -> V_80 ) ;
if ( V_21 != 0 ) {
F_39 ( V_6 -> V_2 , L_2 , V_21 ) ;
return V_21 ;
}
V_21 = F_30 ( F_5 ( V_8 -> V_80 ) ,
V_8 -> V_80 ) ;
if ( V_21 != 0 ) {
F_39 ( V_6 -> V_2 , L_3 , V_21 ) ;
return V_21 ;
}
V_21 = F_40 ( V_6 ) ;
if ( V_21 < 0 ) {
F_39 ( V_6 -> V_2 , L_4 , V_21 ) ;
goto V_87;
}
F_41 ( V_6 , V_78 ) ;
F_7 ( V_6 , V_88 , 0x100 , 0 ) ;
F_7 ( V_6 , V_89 , 0x100 , 0 ) ;
F_7 ( V_6 , V_90 , 0x100 , 0 ) ;
F_7 ( V_6 , V_91 , 0x100 , 0 ) ;
F_7 ( V_6 , V_92 , 0x8 , 0 ) ;
F_33 ( F_5 ( V_8 -> V_80 ) , V_8 -> V_80 ) ;
return 0 ;
V_87:
F_33 ( F_5 ( V_8 -> V_80 ) , V_8 -> V_80 ) ;
return V_21 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
F_33 ( F_5 ( V_8 -> V_80 ) , V_8 -> V_80 ) ;
return 0 ;
}
static int F_43 ( struct V_93 * V_94 )
{
struct V_7 * V_8 ;
int V_21 ;
V_8 = F_44 ( & V_94 -> V_2 , sizeof( * V_8 ) , V_95 ) ;
if ( V_8 == NULL )
return - V_96 ;
V_8 -> V_30 = F_45 ( & V_94 -> V_2 , L_5 ) ;
if ( F_46 ( V_8 -> V_30 ) ) {
V_21 = F_47 ( V_8 -> V_30 ) ;
if ( V_21 == - V_97 ) {
V_8 -> V_30 = NULL ;
F_48 ( & V_94 -> V_2 , L_6 ) ;
} else {
F_39 ( & V_94 -> V_2 , L_7 ,
V_21 ) ;
return V_21 ;
}
}
F_49 ( & V_8 -> V_23 ) ;
V_8 -> V_81 = F_50 ( V_94 , & V_98 ) ;
if ( F_46 ( V_8 -> V_81 ) ) {
V_21 = F_47 ( V_8 -> V_81 ) ;
F_39 ( & V_94 -> V_2 , L_8 ,
V_21 ) ;
return V_21 ;
}
F_51 ( V_94 , V_8 ) ;
V_21 = F_52 ( & V_94 -> V_2 ,
& V_99 , & V_100 , 1 ) ;
if ( V_21 != 0 ) {
F_39 ( & V_94 -> V_2 , L_9 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_53 ( struct V_93 * V_94 )
{
F_54 ( & V_94 -> V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_101 * V_102 ,
const struct V_103 * V_104 )
{
struct V_7 * V_8 ;
int V_21 ;
V_8 = F_44 ( & V_102 -> V_2 , sizeof( struct V_7 ) ,
V_95 ) ;
if ( V_8 == NULL )
return - V_96 ;
V_8 -> V_30 = F_45 ( & V_102 -> V_2 , L_5 ) ;
if ( F_46 ( V_8 -> V_30 ) ) {
V_21 = F_47 ( V_8 -> V_30 ) ;
if ( V_21 == - V_97 ) {
V_8 -> V_30 = NULL ;
F_48 ( & V_102 -> V_2 , L_6 ) ;
} else {
F_39 ( & V_102 -> V_2 , L_7 ,
V_21 ) ;
return V_21 ;
}
}
F_49 ( & V_8 -> V_23 ) ;
V_8 -> V_81 = F_56 ( V_102 , & V_98 ) ;
if ( F_46 ( V_8 -> V_81 ) ) {
V_21 = F_47 ( V_8 -> V_81 ) ;
F_39 ( & V_102 -> V_2 , L_8 ,
V_21 ) ;
return V_21 ;
}
F_57 ( V_102 , V_8 ) ;
V_21 = F_52 ( & V_102 -> V_2 ,
& V_99 , & V_100 , 1 ) ;
if ( V_21 != 0 ) {
F_39 ( & V_102 -> V_2 , L_9 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
static int F_58 ( struct V_101 * V_105 )
{
F_54 ( & V_105 -> V_2 ) ;
return 0 ;
}
static int T_2 F_59 ( void )
{
int V_21 = 0 ;
#if F_60 ( V_106 )
V_21 = F_61 ( & V_107 ) ;
if ( V_21 != 0 ) {
F_62 ( V_108 L_10 ,
V_21 ) ;
}
#endif
#if F_63 ( V_109 )
V_21 = F_64 ( & V_110 ) ;
if ( V_21 != 0 ) {
F_62 ( V_108 L_11 ,
V_21 ) ;
}
#endif
return V_21 ;
}
static void T_3 F_65 ( void )
{
#if F_60 ( V_106 )
F_66 ( & V_107 ) ;
#endif
#if F_63 ( V_109 )
F_67 ( & V_110 ) ;
#endif
}
