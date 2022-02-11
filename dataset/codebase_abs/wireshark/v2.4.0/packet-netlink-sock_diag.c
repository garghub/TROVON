static int
F_1 ( T_1 * V_1 , int V_2 , int V_3 )
{
while ( V_3 >= 0 ) {
if ( F_2 ( V_1 , V_2 ) != 0 )
return 1 ;
V_2 ++ ;
V_3 -- ;
}
return 0 ;
}
static void
F_3 ( T_2 * T_3 V_4 , T_1 * V_1 , int V_2 , int V_3 )
{
if ( F_1 ( V_1 , V_2 , V_3 ) ) {
}
}
static int
F_4 ( T_2 * T_3 , T_4 * V_5 , T_1 * V_1 , int V_2 , int V_3 )
{
static T_5 * V_6 [] = {
& V_7 ,
& V_8 ,
& V_9 ,
& V_10 ,
& V_11 ,
& V_12 ,
} ;
T_6 V_13 ;
if ( V_3 == 0 || ( V_3 % 4 ) != 0 )
return 0 ;
for ( V_13 = 0 ; V_3 >= 4 && V_13 < F_5 ( V_6 ) ; V_13 ++ ) {
F_6 ( T_3 , V_6 [ V_13 ] , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ; V_3 -= 4 ;
}
if ( V_3 != 0 ) {
}
return 1 ;
}
static void
F_7 ( T_2 * T_3 , T_4 * V_5 V_4 , T_1 * V_1 , int V_2 )
{
T_7 V_15 ;
V_15 = F_8 ( V_1 , V_2 + 4 ) ;
V_15 <<= 32 ;
V_15 |= F_8 ( V_1 , V_2 ) ;
F_9 ( T_3 , V_16 . V_17 , V_1 , V_2 , 8 , V_15 ) ;
}
static void
F_10 ( T_2 * T_3 , T_1 * V_1 , int V_2 )
{
T_8 V_18 = F_2 ( V_1 , V_2 ) ;
F_6 ( T_3 , & V_19 , V_1 , V_2 , 1 , V_20 ) ;
F_11 ( T_3 , L_1 , F_12 ( V_18 , V_21 , L_2 ) ) ;
}
static int
F_13 ( T_1 * V_1 , void * V_22 , T_2 * T_3 , int V_23 , int V_2 , int V_3 )
{
enum V_24 type = (enum V_24 ) V_23 ;
T_4 * V_5 = ( T_4 * ) V_22 ;
switch ( type ) {
case V_25 :
{
const char * V_26 ;
if ( V_3 > 0 && F_2 ( V_1 , V_2 ) == '\0' ) {
V_26 = F_14 ( F_15 () ,
L_3 ,
F_16 ( F_15 () , V_1 , V_2 + 1 , V_3 - 1 , V_27 | V_20 ) ,
NULL ) ;
} else
V_26 = F_16 ( F_15 () , V_1 , V_2 , V_3 , V_27 | V_20 ) ;
F_11 ( T_3 , L_1 , V_26 ) ;
F_17 ( T_3 , & V_28 , V_1 , V_2 , V_3 , V_26 ) ;
return 1 ;
}
case V_29 :
if ( V_3 == 4 ) {
F_11 ( T_3 , L_4 , F_8 ( V_1 , V_2 ) ) ;
F_6 ( T_3 , & V_30 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
return 1 ;
}
return 0 ;
case V_31 :
if ( V_3 == 8 ) {
F_6 ( T_3 , & V_32 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( T_3 , & V_33 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
return 1 ;
}
return 0 ;
case V_34 :
return F_4 ( T_3 , V_5 , V_1 , V_2 , V_3 ) ;
case V_35 :
if ( V_3 == 1 )
F_10 ( T_3 , V_1 , V_2 ) ;
return 0 ;
case V_36 :
case V_37 :
default:
return 0 ;
}
}
static int
F_18 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_39 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_40 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_3 ( T_3 , V_1 , V_2 , 1 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return F_19 ( V_1 , & V_42 , V_43 , V_5 , V_5 -> V_22 , T_3 , V_2 , - 1 , F_13 ) ;
}
static int
F_20 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_9 * V_44 ;
T_2 * V_45 ;
V_44 = F_6 ( T_3 , & V_46 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_45 = F_21 ( V_44 , V_47 ) ;
F_6 ( V_45 , & V_48 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_49 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_50 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_51 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_52 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_53 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
return V_2 ;
}
static int
F_22 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
V_2 += 1 ;
F_3 ( T_3 , V_1 , V_2 , 2 ) ;
V_2 += 2 ;
V_2 += 4 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
V_2 = F_20 ( V_1 , V_5 , T_3 , V_2 ) ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return V_2 ;
}
static int
F_23 ( T_1 * V_1 , void * V_22 , T_2 * T_3 , int V_23 , int V_2 , int V_3 )
{
enum V_54 type = (enum V_54 ) V_23 ;
T_4 * V_5 = ( T_4 * ) V_22 ;
switch ( type ) {
case V_55 :
if ( V_3 == 16 ) {
F_6 ( T_3 , & V_7 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_12 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_11 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_9 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
return 1 ;
}
return 0 ;
case V_56 :
return F_4 ( T_3 , V_5 , V_1 , V_2 , V_3 ) ;
case V_57 :
if ( V_3 == 1 )
F_10 ( T_3 , V_1 , V_2 ) ;
return 0 ;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
default:
return 0 ;
}
}
static int
F_24 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 , int V_71 )
{
F_6 ( T_3 , & V_72 , V_1 , V_2 , 2 , V_73 ) ;
V_2 += 2 ;
F_6 ( T_3 , & V_74 , V_1 , V_2 , 2 , V_73 ) ;
V_2 += 2 ;
switch ( V_71 ) {
case V_75 :
F_6 ( T_3 , & V_76 , V_1 , V_2 , 4 , V_73 ) ;
V_2 += 4 ;
F_3 ( T_3 , V_1 , V_2 , 12 ) ;
V_2 += 12 ;
F_6 ( T_3 , & V_77 , V_1 , V_2 , 4 , V_73 ) ;
V_2 += 4 ;
F_3 ( T_3 , V_1 , V_2 , 12 ) ;
V_2 += 12 ;
break;
case V_78 :
F_6 ( T_3 , & V_79 , V_1 , V_2 , 16 , V_20 ) ;
V_2 += 16 ;
F_6 ( T_3 , & V_80 , V_1 , V_2 , 16 , V_20 ) ;
V_2 += 16 ;
break;
default:
F_25 () ;
break;
}
F_6 ( T_3 , & V_81 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return V_2 ;
}
static int
F_26 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_8 V_82 ;
V_82 = F_2 ( V_1 , V_2 ) ;
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_40 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
V_2 += 2 ;
V_2 = F_24 ( V_1 , V_5 , T_3 , V_2 , V_82 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_32 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_33 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
V_2 += 4 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
return F_19 ( V_1 , & V_83 , V_43 , V_5 , V_5 -> V_22 , T_3 , V_2 , - 1 , F_23 ) ;
}
static int
F_27 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_8 V_82 ;
V_82 = F_2 ( V_1 , V_2 ) ;
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_84 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
V_2 += 1 ;
F_3 ( T_3 , V_1 , V_2 , 1 ) ;
V_2 += 1 ;
V_2 += 4 ;
V_2 = F_24 ( V_1 , V_5 , T_3 , V_2 , V_82 ) ;
return V_2 ;
}
static int
F_28 ( T_1 * V_1 , void * V_22 , T_2 * T_3 , int V_23 , int V_2 , int V_3 )
{
enum V_85 type = (enum V_85 ) V_23 ;
T_4 * V_5 = ( T_4 * ) V_22 ;
switch ( type ) {
case V_86 :
return F_4 ( T_3 , V_5 , V_1 , V_2 , V_3 ) ;
case V_87 :
case V_88 :
case V_89 :
default:
return 0 ;
}
}
static int
F_29 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_39 , V_1 , V_2 , 1 , V_20 ) ;
switch ( F_2 ( V_1 , V_2 ) ) {
case V_90 :
case V_91 :
break;
default:
break;
}
V_2 += 1 ;
F_6 ( T_3 , & V_92 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_40 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_93 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_94 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
V_2 += 4 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return F_19 ( V_1 , & V_95 , V_43 , V_5 , V_5 -> V_22 , T_3 , V_2 , - 1 , F_28 ) ;
}
static int
F_30 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_9 * V_44 ;
T_2 * V_45 ;
V_44 = F_6 ( T_3 , & V_96 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_45 = F_21 ( V_44 , V_47 ) ;
F_6 ( V_45 , & V_97 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_98 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_99 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
return V_2 ;
}
static int
F_31 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_92 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_3 ( T_3 , V_1 , V_2 , 2 ) ;
V_2 += 2 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
V_2 = F_30 ( V_1 , V_5 , T_3 , V_2 ) ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return V_2 ;
}
static int
F_32 ( T_1 * V_1 , void * V_22 , T_2 * T_3 , int V_23 , int V_2 , int V_3 )
{
enum V_100 type = (enum V_100 ) V_23 ;
T_4 * V_5 = ( T_4 * ) V_22 ;
switch ( type ) {
case V_101 :
return F_4 ( T_3 , V_5 , V_1 , V_2 , V_3 ) ;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
default:
return 0 ;
}
}
static int
F_33 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_39 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_109 , V_1 , V_2 , 2 , V_5 -> V_14 ) ;
V_2 += 2 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return F_19 ( V_1 , & V_110 , V_43 , V_5 , V_5 -> V_22 , T_3 , V_2 , - 1 , F_32 ) ;
}
static int
F_34 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_9 * V_44 ;
T_2 * V_45 ;
V_44 = F_6 ( T_3 , & V_111 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_45 = F_21 ( V_44 , V_47 ) ;
F_6 ( V_45 , & V_112 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_113 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_114 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_115 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_116 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_117 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
return V_2 ;
}
static int
F_35 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_109 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_3 ( T_3 , V_1 , V_2 , 2 ) ;
V_2 += 2 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
V_2 = F_34 ( V_1 , V_5 , T_3 , V_2 ) ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return V_2 ;
}
static int
F_36 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
const T_10 V_118 = ( V_5 -> V_119 -> V_120 == V_121 ) ;
T_8 V_82 ;
V_82 = F_2 ( V_1 , V_2 ) ;
switch ( V_82 ) {
case V_122 :
V_2 = ( V_118 ) ?
F_22 ( V_1 , V_5 , T_3 , V_2 ) :
F_18 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
case V_75 :
case V_78 :
V_2 = ( V_118 ) ?
F_27 ( V_1 , V_5 , T_3 , V_2 ) :
F_26 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
case V_123 :
V_2 = ( V_118 ) ?
F_31 ( V_1 , V_5 , T_3 , V_2 ) :
F_29 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
case V_124 :
V_2 = ( V_118 ) ?
F_35 ( V_1 , V_5 , T_3 , V_2 ) :
F_33 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
}
return V_2 ;
}
static int
F_37 ( T_1 * V_1 , T_11 * V_119 , T_2 * T_3 , void * V_125 )
{
struct V_126 * V_22 = (struct V_126 * ) V_125 ;
T_4 V_5 ;
T_2 * V_127 ;
T_9 * V_128 ;
int V_2 = 0 ;
F_38 ( V_22 && V_22 -> V_129 == V_130 ) ;
F_39 ( V_119 -> V_131 , V_132 , L_5 ) ;
F_40 ( V_119 -> V_131 , V_133 ) ;
V_128 = F_6 ( T_3 , F_41 ( V_134 ) , V_1 , 0 , - 1 , V_20 ) ;
V_127 = F_21 ( V_128 , V_135 ) ;
V_2 = F_42 ( V_1 , V_127 , V_2 , V_22 -> V_14 , & V_136 , NULL ) ;
V_5 . V_14 = V_22 -> V_14 ;
V_5 . V_119 = V_119 ;
V_5 . V_22 = V_22 ;
switch ( V_22 -> type ) {
case V_137 :
case V_138 :
break;
case V_139 :
V_2 = F_36 ( V_1 , & V_5 , V_127 , V_2 ) ;
break;
}
return V_2 ;
}
void
F_43 ( void )
{
#ifndef F_44
static T_5 * V_140 [] = {
& V_136 ,
& V_38 ,
& V_39 ,
& V_40 ,
& V_41 ,
& V_32 ,
& V_33 ,
& V_19 ,
& V_16 ,
& V_7 ,
& V_8 ,
& V_9 ,
& V_10 ,
& V_11 ,
& V_12 ,
& V_46 ,
& V_48 ,
& V_49 ,
& V_50 ,
& V_51 ,
& V_52 ,
& V_53 ,
& V_42 ,
& V_28 ,
& V_30 ,
& V_84 ,
& V_83 ,
& V_72 ,
& V_74 ,
& V_76 ,
& V_77 ,
& V_79 ,
& V_80 ,
& V_81 ,
& V_96 ,
& V_97 ,
& V_98 ,
& V_99 ,
& V_92 ,
& V_95 ,
& V_93 ,
& V_94 ,
& V_111 ,
& V_112 ,
& V_113 ,
& V_114 ,
& V_115 ,
& V_116 ,
& V_117 ,
& V_109 ,
& V_110
} ;
#endif
static T_12 * V_141 [] = {
& V_135 ,
& V_47 ,
& V_43
} ;
V_134 = F_45 ( L_6 , L_7 , L_8 ) ;
V_142 = F_41 ( V_134 ) ;
F_46 ( V_134 , V_140 , F_47 ( V_140 ) ) ;
F_48 ( V_141 , F_47 ( V_141 ) ) ;
V_143 = F_49 ( F_37 , V_134 ) ;
}
void
F_50 ( void )
{
F_51 ( L_9 , V_144 , V_143 ) ;
}
