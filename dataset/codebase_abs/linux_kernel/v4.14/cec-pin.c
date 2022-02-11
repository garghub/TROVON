static void F_1 ( struct V_1 * V_2 , bool V_3 , bool V_4 )
{
if ( ! V_4 && V_3 == V_2 -> V_5 -> V_6 )
return;
V_2 -> V_5 -> V_6 = V_3 ;
if ( F_2 ( & V_2 -> V_7 ) < V_8 ) {
V_2 -> V_9 [ V_2 -> V_10 ] = V_3 ;
V_2 -> V_11 [ V_2 -> V_10 ] = F_3 () ;
V_2 -> V_10 =
( V_2 -> V_10 + 1 ) % V_8 ;
F_4 ( & V_2 -> V_7 ) ;
}
F_5 ( & V_2 -> V_12 ) ;
}
static bool F_6 ( struct V_1 * V_2 )
{
bool V_3 = V_2 -> V_13 -> V_14 ( V_2 -> V_5 ) ;
F_1 ( V_2 , V_3 , false ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_13 -> V_15 ( V_2 -> V_5 ) ;
F_1 ( V_2 , false , false ) ;
}
static bool F_8 ( struct V_1 * V_2 )
{
V_2 -> V_13 -> V_16 ( V_2 -> V_5 ) ;
return F_6 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_17 = V_2 -> V_18 = 0 ;
V_2 -> V_19 . V_20 = 0 ;
memset ( V_2 -> V_19 . V_21 , 0 , sizeof( V_2 -> V_19 . V_21 ) ) ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = 0 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_24 )
{
bool V_3 ;
bool V_25 , V_26 ;
switch ( V_2 -> V_22 ) {
case V_27 :
if ( F_6 ( V_2 ) )
F_9 ( V_2 ) ;
break;
case V_28 :
V_2 -> V_22 = V_29 ;
F_8 ( V_2 ) ;
break;
case V_30 :
if ( ! F_6 ( V_2 ) ) {
V_2 -> V_31 . V_20 = 0 ;
V_2 -> V_32 = V_24 ;
V_2 -> V_33 = V_34 ;
V_2 -> V_22 = V_27 ;
F_5 ( & V_2 -> V_12 ) ;
break;
}
if ( V_2 -> V_35 ) {
F_9 ( V_2 ) ;
V_2 -> V_31 . V_20 = 0 ;
V_2 -> V_32 = V_24 ;
V_2 -> V_33 = V_36 ;
F_5 ( & V_2 -> V_12 ) ;
break;
}
case V_37 :
case V_38 :
V_2 -> V_18 ++ ;
case V_29 :
if ( V_2 -> V_18 / 10 >= V_2 -> V_31 . V_20 ) {
F_9 ( V_2 ) ;
V_2 -> V_31 . V_20 = 0 ;
V_2 -> V_32 = V_24 ;
V_2 -> V_33 = V_39 ;
F_5 ( & V_2 -> V_12 ) ;
break;
}
switch ( V_2 -> V_18 % 10 ) {
default:
V_3 = V_2 -> V_31 . V_21 [ V_2 -> V_18 / 10 ] &
( 1 << ( 7 - ( V_2 -> V_18 % 10 ) ) ) ;
V_2 -> V_22 = V_3 ? V_40 :
V_41 ;
break;
case 8 :
V_3 = V_2 -> V_18 / 10 == V_2 -> V_31 . V_20 - 1 ;
V_2 -> V_22 = V_3 ? V_40 :
V_41 ;
break;
case 9 :
V_2 -> V_22 = V_40 ;
break;
}
F_7 ( V_2 ) ;
break;
case V_41 :
case V_40 :
V_3 = V_2 -> V_22 == V_40 ;
V_2 -> V_22 = V_3 ? V_38 :
V_37 ;
V_25 = V_2 -> V_18 % 10 == 9 ;
if ( V_3 && ( V_2 -> V_18 < 4 || V_25 ) )
V_2 -> V_22 = V_42 ;
F_8 ( V_2 ) ;
break;
case V_42 :
V_3 = F_6 ( V_2 ) ;
V_25 = V_2 -> V_18 % 10 == 9 ;
if ( ! V_3 && ! V_25 ) {
V_2 -> V_31 . V_20 = 0 ;
V_2 -> V_32 = V_24 ;
V_2 -> V_33 = V_43 ;
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_17 = V_2 -> V_18 ;
V_2 -> V_18 = 0 ;
memset ( V_2 -> V_19 . V_21 , 0 , sizeof( V_2 -> V_19 . V_21 ) ) ;
V_2 -> V_19 . V_21 [ 0 ] = V_2 -> V_31 . V_21 [ 0 ] ;
V_2 -> V_19 . V_21 [ 0 ] &= ~ ( 1 << ( 7 - V_2 -> V_17 ) ) ;
V_2 -> V_19 . V_20 = 0 ;
V_2 -> V_22 = V_44 ;
V_2 -> V_17 ++ ;
break;
}
V_2 -> V_22 = V_30 ;
if ( ! V_25 )
break;
V_26 = F_11 ( & V_2 -> V_31 ) ? V_3 : ! V_3 ;
if ( ! V_26 ) {
V_2 -> V_35 = true ;
}
break;
default:
break;
}
}
static void F_12 ( struct V_1 * V_2 , T_1 V_24 )
{
T_2 V_45 ;
bool V_3 ;
bool V_26 ;
bool V_46 , V_47 ;
T_3 V_48 ;
switch ( V_2 -> V_22 ) {
case V_49 :
V_3 = F_6 ( V_2 ) ;
if ( ! V_3 )
break;
V_2 -> V_22 = V_50 ;
V_45 = F_13 ( V_24 , V_2 -> V_24 ) ;
V_2 -> V_24 = V_24 ;
if ( V_45 < V_51 -
V_52 ) {
F_9 ( V_2 ) ;
}
break;
case V_50 :
V_3 = F_6 ( V_2 ) ;
V_45 = F_13 ( V_24 , V_2 -> V_24 ) ;
if ( V_3 && V_45 > V_53 -
V_51 ) {
F_9 ( V_2 ) ;
break;
}
if ( V_3 )
break;
V_2 -> V_22 = V_54 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_55 = false ;
break;
case V_54 :
V_3 = F_6 ( V_2 ) ;
V_2 -> V_22 = V_44 ;
switch ( V_2 -> V_17 % 10 ) {
default:
if ( V_2 -> V_17 / 10 < V_56 )
V_2 -> V_19 . V_21 [ V_2 -> V_17 / 10 ] |=
V_3 << ( 7 - ( V_2 -> V_17 % 10 ) ) ;
break;
case 8 :
V_2 -> V_55 = V_3 ;
V_2 -> V_19 . V_20 = V_2 -> V_17 / 10 + 1 ;
break;
case 9 :
break;
}
V_2 -> V_17 ++ ;
break;
case V_44 :
V_2 -> V_22 = V_57 ;
break;
case V_57 :
V_3 = F_6 ( V_2 ) ;
V_45 = F_13 ( V_24 , V_2 -> V_24 ) ;
if ( V_3 && V_45 > V_58 ) {
F_9 ( V_2 ) ;
break;
}
if ( V_3 )
break;
if ( V_45 < V_59 ) {
F_7 ( V_2 ) ;
V_2 -> V_22 = V_60 ;
break;
}
V_2 -> V_24 = V_24 ;
if ( V_2 -> V_17 % 10 != 9 ) {
V_2 -> V_22 = V_54 ;
break;
}
V_48 = F_14 ( & V_2 -> V_19 ) ;
V_46 = V_48 == V_61 ;
V_47 = V_46 || ( V_2 -> V_62 & ( 1 << V_48 ) ) ;
V_26 = V_46 ? 1 : ! V_47 ;
if ( V_26 ) {
V_2 -> V_22 = V_63 ;
break;
}
F_7 ( V_2 ) ;
V_2 -> V_22 = V_64 ;
break;
case V_64 :
F_8 ( V_2 ) ;
V_2 -> V_22 = V_65 ;
break;
case V_65 :
case V_63 :
V_3 = F_6 ( V_2 ) ;
if ( V_3 && V_2 -> V_55 ) {
V_2 -> V_66 = V_2 -> V_19 ;
V_2 -> V_66 . V_67 = V_24 ;
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_22 = V_68 ;
break;
}
V_2 -> V_17 ++ ;
V_2 -> V_22 = V_57 ;
break;
case V_68 :
F_9 ( V_2 ) ;
break;
default:
break;
}
}
static enum V_69 F_15 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_16 ( V_71 , struct V_1 , V_71 ) ;
struct V_72 * V_5 = V_2 -> V_5 ;
T_1 V_24 ;
T_2 V_45 ;
V_24 = F_3 () ;
if ( V_2 -> V_73 ) {
V_45 = F_13 ( V_24 , V_2 -> V_73 ) ;
V_2 -> V_74 ++ ;
if ( V_45 > 100 && V_2 -> V_22 != V_23 ) {
V_2 -> V_75 += V_45 ;
V_2 -> V_76 ++ ;
if ( V_45 > 300 )
V_2 -> V_77 ++ ;
if ( V_45 > V_2 -> V_78 )
V_2 -> V_78 = V_45 ;
}
}
if ( V_5 -> V_79 )
F_6 ( V_2 ) ;
if ( V_2 -> V_80 ) {
if ( V_2 -> V_80 > 150 ) {
V_2 -> V_80 -= 100 ;
V_2 -> V_73 = F_17 ( V_24 , 100 ) ;
F_18 ( V_71 , 100000 ) ;
return V_81 ;
}
if ( V_2 -> V_80 > 100 ) {
V_2 -> V_80 /= 2 ;
V_2 -> V_73 = F_17 ( V_24 , V_2 -> V_80 ) ;
F_18 ( V_71 , V_2 -> V_80 * 1000 ) ;
return V_81 ;
}
V_2 -> V_73 = F_17 ( V_24 , V_2 -> V_80 ) ;
F_18 ( V_71 , V_2 -> V_80 * 1000 ) ;
V_2 -> V_80 = 0 ;
return V_81 ;
}
switch ( V_2 -> V_22 ) {
case V_27 :
case V_28 :
case V_30 :
case V_37 :
case V_38 :
case V_29 :
case V_41 :
case V_40 :
case V_42 :
F_10 ( V_2 , V_24 ) ;
break;
case V_49 :
case V_50 :
case V_54 :
case V_44 :
case V_57 :
case V_64 :
case V_65 :
case V_63 :
case V_68 :
F_12 ( V_2 , V_24 ) ;
break;
case V_23 :
case V_82 :
if ( ! F_8 ( V_2 ) ) {
V_2 -> V_24 = V_24 ;
V_2 -> V_22 = V_49 ;
break;
}
if ( V_2 -> V_24 == 0 )
V_2 -> V_24 = V_24 ;
if ( V_2 -> V_31 . V_20 ) {
V_45 = F_13 ( V_24 , V_2 -> V_24 ) ;
if ( V_45 / V_83 >
V_2 -> V_84 ) {
V_2 -> V_35 = false ;
V_2 -> V_22 = V_28 ;
F_7 ( V_2 ) ;
break;
}
if ( V_45 / V_83 >
V_2 -> V_84 - 1 )
V_2 -> V_22 = V_82 ;
break;
}
if ( V_2 -> V_22 != V_23 || V_2 -> V_13 -> V_85 == NULL ||
V_2 -> V_86 || V_5 -> V_87 ||
V_5 -> V_88 || V_5 -> V_89 )
break;
F_19 ( & V_2 -> V_90 , V_91 ) ;
V_2 -> V_22 = V_92 ;
F_5 ( & V_2 -> V_12 ) ;
return V_93 ;
case V_60 :
F_9 ( V_2 ) ;
break;
default:
break;
}
if ( ! V_5 -> V_79 || V_94 [ V_2 -> V_22 ] . V_95 <= 150 ) {
V_2 -> V_80 = 0 ;
V_2 -> V_73 = F_17 ( V_24 , V_94 [ V_2 -> V_22 ] . V_95 ) ;
F_18 ( V_71 , V_94 [ V_2 -> V_22 ] . V_95 * 1000 ) ;
return V_81 ;
}
V_2 -> V_80 = V_94 [ V_2 -> V_22 ] . V_95 - 100 ;
V_2 -> V_73 = F_17 ( V_24 , 100 ) ;
F_18 ( V_71 , 100000 ) ;
return V_81 ;
}
static int F_20 ( void * V_96 )
{
struct V_72 * V_5 = V_96 ;
struct V_1 * V_2 = V_5 -> V_2 ;
for (; ; ) {
F_21 ( V_2 -> V_12 ,
F_22 () ||
V_2 -> V_66 . V_20 ||
V_2 -> V_33 ||
F_2 ( & V_2 -> V_90 ) ||
F_2 ( & V_2 -> V_7 ) ) ;
if ( V_2 -> V_66 . V_20 ) {
F_23 ( V_5 , & V_2 -> V_66 ,
V_2 -> V_66 . V_67 ) ;
V_2 -> V_66 . V_20 = 0 ;
}
if ( V_2 -> V_33 ) {
unsigned int V_97 = V_2 -> V_33 ;
V_2 -> V_33 = 0 ;
F_24 ( V_5 , V_97 ,
V_2 -> V_32 ) ;
}
while ( F_2 ( & V_2 -> V_7 ) ) {
unsigned int V_98 = V_2 -> V_99 ;
F_25 ( V_5 ,
V_2 -> V_9 [ V_98 ] ,
V_2 -> V_11 [ V_98 ] ) ;
V_2 -> V_99 = ( V_98 + 1 ) % V_8 ;
F_26 ( & V_2 -> V_7 ) ;
}
switch ( F_27 ( & V_2 -> V_90 ,
V_100 ) ) {
case V_101 :
V_2 -> V_13 -> V_102 ( V_5 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_28 ( & V_2 -> V_71 , 0 , V_103 ) ;
break;
case V_91 :
V_2 -> V_86 = ! V_2 -> V_13 -> V_85 ( V_5 ) ;
if ( V_2 -> V_86 ) {
F_9 ( V_2 ) ;
F_28 ( & V_2 -> V_71 , 0 , V_103 ) ;
}
break;
default:
break;
}
if ( F_22 () )
break;
}
return 0 ;
}
static int F_29 ( struct V_72 * V_5 , bool V_104 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
V_2 -> V_105 = V_104 ;
if ( V_104 ) {
F_19 ( & V_2 -> V_7 , 0 ) ;
V_2 -> V_99 = V_2 -> V_10 = 0 ;
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 -> V_31 . V_20 = 0 ;
V_2 -> V_73 = 0 ;
F_19 ( & V_2 -> V_90 , V_100 ) ;
V_2 -> V_106 = F_30 ( F_20 , V_5 ,
L_1 ) ;
if ( F_31 ( V_2 -> V_106 ) ) {
F_32 ( L_2 ) ;
return F_33 ( V_2 -> V_106 ) ;
}
F_28 ( & V_2 -> V_71 , 0 , V_103 ) ;
} else {
if ( V_2 -> V_13 -> V_102 )
V_2 -> V_13 -> V_102 ( V_5 ) ;
F_34 ( & V_2 -> V_71 ) ;
F_35 ( V_2 -> V_106 ) ;
F_6 ( V_2 ) ;
F_9 ( V_2 ) ;
V_2 -> V_22 = V_107 ;
}
return 0 ;
}
static int F_36 ( struct V_72 * V_5 , T_3 V_108 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_108 == V_109 )
V_2 -> V_62 = 0 ;
else
V_2 -> V_62 |= ( 1 << V_108 ) ;
return 0 ;
}
static int F_37 ( struct V_72 * V_5 , T_3 V_110 ,
T_4 V_111 , struct V_112 * V_21 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
V_2 -> V_84 = V_111 ;
V_2 -> V_31 = * V_21 ;
V_2 -> V_33 = 0 ;
V_2 -> V_18 = 0 ;
if ( V_2 -> V_22 == V_92 ) {
F_19 ( & V_2 -> V_90 , V_100 ) ;
V_2 -> V_13 -> V_102 ( V_5 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_28 ( & V_2 -> V_71 , 0 , V_103 ) ;
}
return 0 ;
}
static void F_38 ( struct V_72 * V_5 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
F_39 ( V_114 , L_3 , V_94 [ V_2 -> V_22 ] . V_115 ) ;
F_39 ( V_114 , L_4 , V_2 -> V_18 ) ;
F_39 ( V_114 , L_5 , V_2 -> V_17 ) ;
F_39 ( V_114 , L_6 , V_2 -> V_13 -> V_14 ( V_5 ) ) ;
F_39 ( V_114 , L_7 , V_2 -> V_86 ) ;
if ( V_2 -> V_76 ) {
F_39 ( V_114 , L_8 ,
V_2 -> V_76 , V_2 -> V_74 ) ;
F_39 ( V_114 , L_9 ,
V_2 -> V_77 , V_2 -> V_74 ) ;
F_39 ( V_114 , L_10 ,
V_2 -> V_78 ) ;
F_39 ( V_114 , L_11 ,
V_2 -> V_75 / V_2 -> V_76 ) ;
}
V_2 -> V_74 = 0 ;
V_2 -> V_76 = 0 ;
V_2 -> V_77 = 0 ;
V_2 -> V_78 = 0 ;
V_2 -> V_75 = 0 ;
if ( V_2 -> V_13 -> V_116 )
V_2 -> V_13 -> V_116 ( V_5 , V_114 ) ;
}
static int F_40 ( struct V_72 * V_5 ,
bool V_104 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
V_2 -> V_117 = V_104 ;
return 0 ;
}
static void F_41 ( struct V_72 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_2 -> V_13 -> free )
V_2 -> V_13 -> free ( V_5 ) ;
V_5 -> V_2 = NULL ;
F_42 ( V_2 ) ;
}
void F_43 ( struct V_72 * V_5 , bool V_118 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
F_1 ( V_2 , V_118 , false ) ;
if ( ! V_118 && ( V_5 -> V_87 || V_5 -> V_88 ||
V_5 -> V_89 ) )
F_19 ( & V_2 -> V_90 , V_101 ) ;
}
struct V_72 * F_44 ( const struct V_119 * V_120 ,
void * V_121 , const char * V_115 , T_4 V_122 )
{
struct V_72 * V_5 ;
struct V_1 * V_2 = F_45 ( sizeof( * V_2 ) , V_123 ) ;
if ( V_2 == NULL )
return F_46 ( - V_124 ) ;
V_2 -> V_13 = V_120 ;
F_47 ( & V_2 -> V_71 , V_125 , V_103 ) ;
V_2 -> V_71 . V_126 = F_15 ;
F_48 ( & V_2 -> V_12 ) ;
V_5 = F_49 ( & V_127 , V_121 , V_115 ,
V_122 | V_128 | V_129 ,
V_130 ) ;
if ( F_50 ( V_5 ) ) {
F_42 ( V_2 ) ;
return V_5 ;
}
V_5 -> V_2 = V_2 ;
V_2 -> V_5 = V_5 ;
F_1 ( V_2 , F_8 ( V_2 ) , true ) ;
return V_5 ;
}
