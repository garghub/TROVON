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
return F_19 ( V_1 , & V_42 , V_43 , V_5 , T_3 , V_2 , F_13 ) ;
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
default:
return 0 ;
}
}
static int
F_24 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 , int V_63 )
{
F_6 ( T_3 , & V_64 , V_1 , V_2 , 2 , V_65 ) ;
V_2 += 2 ;
F_6 ( T_3 , & V_66 , V_1 , V_2 , 2 , V_65 ) ;
V_2 += 2 ;
switch ( V_63 ) {
case V_67 :
F_6 ( T_3 , & V_68 , V_1 , V_2 , 4 , V_65 ) ;
V_2 += 4 ;
F_3 ( T_3 , V_1 , V_2 , 12 ) ;
V_2 += 12 ;
F_6 ( T_3 , & V_69 , V_1 , V_2 , 4 , V_65 ) ;
V_2 += 4 ;
F_3 ( T_3 , V_1 , V_2 , 12 ) ;
V_2 += 12 ;
break;
case V_70 :
F_6 ( T_3 , & V_71 , V_1 , V_2 , 16 , V_20 ) ;
V_2 += 16 ;
F_6 ( T_3 , & V_72 , V_1 , V_2 , 16 , V_20 ) ;
V_2 += 16 ;
break;
default:
F_25 () ;
break;
}
F_6 ( T_3 , & V_73 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return V_2 ;
}
static int
F_26 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_8 V_74 ;
V_74 = F_2 ( V_1 , V_2 ) ;
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_40 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
V_2 += 2 ;
V_2 = F_24 ( V_1 , V_5 , T_3 , V_2 , V_74 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_32 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_33 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
V_2 += 4 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
return F_19 ( V_1 , & V_75 , V_43 , V_5 , T_3 , V_2 , F_23 ) ;
}
static int
F_27 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_8 V_74 ;
V_74 = F_2 ( V_1 , V_2 ) ;
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_76 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
V_2 += 1 ;
F_3 ( T_3 , V_1 , V_2 , 1 ) ;
V_2 += 1 ;
V_2 += 4 ;
V_2 = F_24 ( V_1 , V_5 , T_3 , V_2 , V_74 ) ;
return V_2 ;
}
static int
F_28 ( T_1 * V_1 , void * V_22 , T_2 * T_3 , int V_23 , int V_2 , int V_3 )
{
enum V_77 type = (enum V_77 ) V_23 ;
T_4 * V_5 = ( T_4 * ) V_22 ;
switch ( type ) {
case V_78 :
return F_4 ( T_3 , V_5 , V_1 , V_2 , V_3 ) ;
case V_79 :
case V_80 :
case V_81 :
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
case V_82 :
case V_83 :
break;
default:
break;
}
V_2 += 1 ;
F_6 ( T_3 , & V_84 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_40 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_85 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_6 ( T_3 , & V_86 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
V_2 += 4 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return F_19 ( V_1 , & V_87 , V_43 , V_5 , T_3 , V_2 , F_28 ) ;
}
static int
F_30 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_9 * V_44 ;
T_2 * V_45 ;
V_44 = F_6 ( T_3 , & V_88 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_45 = F_21 ( V_44 , V_47 ) ;
F_6 ( V_45 , & V_89 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_90 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_91 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
return V_2 ;
}
static int
F_31 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_84 , V_1 , V_2 , 1 , V_20 ) ;
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
enum V_92 type = (enum V_92 ) V_23 ;
T_4 * V_5 = ( T_4 * ) V_22 ;
switch ( type ) {
case V_93 :
return F_4 ( T_3 , V_5 , V_1 , V_2 , V_3 ) ;
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
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
F_6 ( T_3 , & V_101 , V_1 , V_2 , 2 , V_5 -> V_14 ) ;
V_2 += 2 ;
F_6 ( T_3 , & V_41 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
F_7 ( T_3 , V_5 , V_1 , V_2 ) ;
V_2 += 8 ;
return F_19 ( V_1 , & V_102 , V_43 , V_5 , T_3 , V_2 , F_32 ) ;
}
static int
F_34 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
T_9 * V_44 ;
T_2 * V_45 ;
V_44 = F_6 ( T_3 , & V_103 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_45 = F_21 ( V_44 , V_47 ) ;
F_6 ( V_45 , & V_104 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_105 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_106 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_107 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_108 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
F_6 ( V_45 , & V_109 , V_1 , V_2 , 4 , V_5 -> V_14 ) ;
V_2 += 4 ;
return V_2 ;
}
static int
F_35 ( T_1 * V_1 , T_4 * V_5 , T_2 * T_3 , int V_2 )
{
F_6 ( T_3 , & V_38 , V_1 , V_2 , 1 , V_20 ) ;
V_2 += 1 ;
F_6 ( T_3 , & V_101 , V_1 , V_2 , 1 , V_20 ) ;
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
const T_10 V_110 = ( V_5 -> V_111 -> V_112 == V_113 ) ;
T_8 V_74 ;
V_74 = F_2 ( V_1 , V_2 ) ;
switch ( V_74 ) {
case V_114 :
V_2 = ( V_110 ) ?
F_22 ( V_1 , V_5 , T_3 , V_2 ) :
F_18 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
case V_67 :
case V_70 :
V_2 = ( V_110 ) ?
F_27 ( V_1 , V_5 , T_3 , V_2 ) :
F_26 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
case V_115 :
V_2 = ( V_110 ) ?
F_31 ( V_1 , V_5 , T_3 , V_2 ) :
F_29 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
case V_116 :
V_2 = ( V_110 ) ?
F_35 ( V_1 , V_5 , T_3 , V_2 ) :
F_33 ( V_1 , V_5 , T_3 , V_2 ) ;
break;
}
return V_2 ;
}
static int
F_37 ( T_1 * V_1 , T_11 * V_111 , T_2 * T_3 , void * V_117 )
{
struct V_118 * V_22 = NULL ;
T_4 V_5 ;
int V_2 ;
if ( V_117 ) {
if ( ( (struct V_118 * ) V_117 ) -> V_119 == V_120 )
V_22 = (struct V_118 * ) V_117 ;
}
F_38 ( V_22 ) ;
F_39 ( V_111 -> V_121 , V_122 , L_5 ) ;
F_40 ( V_111 -> V_121 , V_123 ) ;
if ( T_3 ) {
F_41 ( T_3 , L_6 ) ;
F_42 ( T_3 , & V_124 , NULL , 0 , 0 , V_22 -> type ) ;
}
V_5 . V_14 = V_22 -> V_14 ;
V_5 . V_111 = V_111 ;
V_5 . V_22 = V_22 ;
V_2 = 0 ;
switch ( V_22 -> type ) {
case V_125 :
case V_126 :
break;
case V_127 :
V_2 = F_36 ( V_1 , & V_5 , T_3 , V_2 ) ;
break;
}
return V_2 ;
}
void
F_43 ( void )
{
#ifndef F_44
static T_5 * V_128 [] = {
& V_124 ,
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
& V_76 ,
& V_75 ,
& V_64 ,
& V_66 ,
& V_68 ,
& V_69 ,
& V_71 ,
& V_72 ,
& V_73 ,
& V_88 ,
& V_89 ,
& V_90 ,
& V_91 ,
& V_84 ,
& V_87 ,
& V_85 ,
& V_86 ,
& V_103 ,
& V_104 ,
& V_105 ,
& V_106 ,
& V_107 ,
& V_108 ,
& V_109 ,
& V_101 ,
& V_102
} ;
#endif
static T_12 * V_129 [] = {
& V_130 ,
& V_47 ,
& V_43
} ;
int V_131 ;
V_131 = F_45 ( L_7 , L_8 , L_9 ) ;
V_132 = F_46 ( V_131 ) ;
F_47 ( V_131 , V_128 , F_48 ( V_128 ) ) ;
F_49 ( V_129 , F_48 ( V_129 ) ) ;
V_133 = F_50 ( F_37 , V_131 ) ;
}
void
F_51 ( void )
{
F_52 ( L_10 , V_134 , V_133 ) ;
}
