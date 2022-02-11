static void F_1 ( struct V_1 T_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) | ( 1 << V_4 ) ,
& V_2 -> V_3 ) ;
F_2 ( F_3 ( & V_2 -> V_5 ) | ( 1 << V_4 ) ,
& V_2 -> V_5 ) ;
}
static void F_4 ( struct V_1 T_1 * V_2 )
{
F_2 ( F_3 ( & V_2 -> V_3 ) & ~ ( 1 << V_4 ) ,
& V_2 -> V_3 ) ;
F_2 ( F_3 ( & V_2 -> V_5 ) & ~ ( 1 << V_4 ) ,
& V_2 -> V_5 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
int V_8 , int V_9 , T_2 * V_10 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_12 ;
F_1 ( V_2 ) ;
V_12 = ( T_3 ) V_7 -> V_13 + ( V_8 & ~ 0x3 ) ;
* V_10 = F_3 ( V_12 ) ;
if ( V_9 == 1 )
* V_10 = ( * V_10 >> ( 8 * ( V_8 & 3 ) ) ) & 0xff ;
else if ( V_9 == 2 )
* V_10 = ( * V_10 >> ( 8 * ( V_8 & 3 ) ) ) & 0xffff ;
F_4 ( V_2 ) ;
}
static void F_6 ( struct V_6 * V_7 ,
int V_8 , int V_9 , T_2 V_10 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_12 ;
F_1 ( V_2 ) ;
V_12 = ( T_3 ) V_7 -> V_13 + ( V_8 & ~ 0x3 ) ;
if ( V_9 == 4 )
F_2 ( V_10 , V_12 ) ;
else if ( V_9 == 2 )
F_7 ( V_10 , V_12 + ( V_8 & 2 ) ) ;
else if ( V_9 == 1 )
F_8 ( V_10 , V_12 + ( V_8 & 3 ) ) ;
F_4 ( V_2 ) ;
}
static int F_9 ( struct V_6 * V_7 ,
T_2 V_14 , int V_15 , int * V_16 )
{
T_2 V_17 ;
while ( ( * V_16 ) -- ) {
F_5 ( V_7 , V_14 , 1 , & V_14 ) ;
if ( V_14 < 0x40 )
break;
V_14 &= ~ 3 ;
F_5 ( V_7 , V_14 + V_18 , 1 , & V_17 ) ;
if ( V_17 == 0xff )
break;
if ( V_17 == V_15 )
return V_14 ;
V_14 += V_19 ;
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
T_2 V_14 , int V_15 )
{
int V_16 = V_20 ;
return F_9 ( V_7 , V_14 , V_15 , & V_16 ) ;
}
static int F_11 ( struct V_6 * V_7 ,
T_4 V_21 )
{
T_2 V_22 ;
F_5 ( V_7 , V_23 , 2 , & V_22 ) ;
if ( ! ( V_22 & V_24 ) )
return 0 ;
switch ( V_21 ) {
case V_25 :
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
default:
return 0 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
int V_15 )
{
T_2 V_14 ;
T_2 V_21 ;
F_5 ( V_7 , V_30 , 1 , & V_21 ) ;
V_14 = F_11 ( V_7 , V_21 ) ;
if ( V_14 )
V_14 = F_10 ( V_7 , V_14 , V_15 ) ;
return V_14 ;
}
static T_5 F_13 ( int V_31 , void * V_32 )
{
return 0 ;
}
static struct V_33 * F_14 ( struct V_34 * V_35 )
{
return V_35 ?
F_15 ( F_16 ( F_17 ( V_35 ) ) ,
struct V_33 , V_36 ) : NULL ;
}
static T_6 F_18 ( struct V_34 * V_35 , char * V_37 )
{
struct V_1 T_1 * V_2 = F_14 ( V_35 ) -> V_11 ;
if ( F_3 ( & V_2 -> V_38 ) & ( ( T_2 ) 1 << V_39 ) )
return sprintf ( V_37 , L_1 ) ;
else
return sprintf ( V_37 , L_2 ) ;
}
static T_6 F_19 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
struct V_1 T_1 * V_2 = F_14 ( V_35 ) -> V_11 ;
if ( F_20 ( V_37 , L_1 ) )
F_2 ( F_3 ( & V_2 -> V_41 ) | ( 1 << V_42 ) ,
& V_2 -> V_41 ) ;
else if ( F_20 ( V_37 , L_2 ) )
F_2 ( F_3 ( & V_2 -> V_41 )
& ~ ( 1 << V_42 ) ,
& V_2 -> V_41 ) ;
else
return - V_43 ;
return V_40 ;
}
static T_6 F_21 ( struct V_34 * V_35 , char * V_37 )
{
return sprintf ( V_37 , L_3 , F_14 ( V_35 ) -> V_44 ) ;
}
static T_6 F_22 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
struct V_6 * V_7 = F_14 (item)
T_2 V_15 , V_45 , V_46 ;
T_3 V_47 ;
if ( F_20 ( V_37 , L_4 ) )
F_6 ( V_7 , V_48 , 1 , 1 ) ;
else if ( F_20 ( V_37 , L_5 ) ) {
V_47 = V_7 -> V_49 ;
V_45 = 0 ;
while ( V_47 > 1 ) {
V_47 /= 2 ;
V_45 ++ ;
}
F_6 ( V_7 , V_48 , 1 , 0 ) ;
V_15 = F_12 ( V_7 , V_50 ) ;
F_5 ( V_7 , V_15 + V_51 , 1 , & V_46 ) ;
V_46 &= ~ V_52 ;
V_46 |= V_45 << 1 ;
F_6 ( V_7 , V_15 + V_51 , 1 , V_46 ) ;
} else
return - V_43 ;
strcpy ( V_7 -> V_44 , V_37 ) ;
return V_40 ;
}
static T_6 F_23 ( struct V_34 * V_35 , char * V_37 )
{
struct V_6 * V_7 = F_14 (item)
struct V_1 T_1 * V_2 = F_14 ( V_35 ) -> V_11 ;
T_2 V_15 , V_45 , V_46 ;
T_3 V_47 ;
if ( ( F_3 ( & V_2 -> V_53 ) & ( 1 << V_54 ) )
!= ( 1 << V_54 ) )
V_47 = 0 ;
else {
V_15 = F_12 ( V_7 , V_50 ) ;
F_5 ( V_7 , V_15 + V_51 , 1 , & V_46 ) ;
V_46 &= ~ V_55 ;
V_45 = V_46 >> 4 ;
V_47 = 1 ;
while ( V_45 -- )
V_47 *= 2 ;
}
V_7 -> V_56 = V_47 ;
return sprintf ( V_37 , L_6 , V_47 ) ;
}
static T_6 F_24 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & F_14 ( V_35 ) -> V_49 ) ;
if ( V_57 )
return V_57 ;
if ( V_7 -> V_49 > 32 )
V_7 -> V_49 = 32 ;
return V_40 ;
}
static T_6 F_26 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
struct V_1 T_1 * V_2 = F_14 ( V_35 ) -> V_11 ;
T_3 V_58 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_58 ) ;
if ( V_57 )
return V_57 ;
if ( V_58 )
F_2 ( F_3 ( & V_2 -> V_41 ) | ( 1 << V_59 ) ,
& V_2 -> V_41 ) ;
else
F_2 ( F_3 ( & V_2 -> V_41 ) & ~ ( 1 << V_59 ) ,
& V_2 -> V_41 ) ;
return V_40 ;
}
static T_6 F_27 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
struct V_6 * V_7 = F_14 (item)
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_47 ;
T_2 V_60 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_47 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_7 -> V_56 )
return - V_43 ;
if ( V_47 >= V_7 -> V_56 )
return - V_43 ;
V_60 = F_3 ( & V_2 -> V_61 ) ;
V_60 &= ~ V_62 ;
V_60 |= 0 << V_63 ;
V_60 &= ~ V_64 ;
V_60 |= 0 << V_65 ;
V_60 &= ~ V_66 ;
V_60 |= V_47 << V_67 ;
V_60 |= V_68 ;
F_2 ( V_60 , & V_2 -> V_61 ) ;
F_28 ( 1 ) ;
V_60 &= ~ V_68 ;
F_2 ( V_60 , & V_2 -> V_61 ) ;
return V_40 ;
}
static T_6 F_29 ( struct V_34 * V_35 , char * V_37 )
{
T_2 V_17 ;
F_5 ( F_14 ( V_35 ) , V_69 , 2 , & V_17 ) ;
return sprintf ( V_37 , L_7 , V_17 ) ;
}
static T_6 F_30 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
T_3 V_17 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_17 ) ;
if ( V_57 )
return V_57 ;
F_6 ( F_14 ( V_35 ) , V_69 , 2 , V_17 ) ;
return V_40 ;
}
static T_6 F_31 ( struct V_34 * V_35 , char * V_37 )
{
T_2 V_17 ;
F_5 ( F_14 ( V_35 ) , V_70 , 2 , & V_17 ) ;
return sprintf ( V_37 , L_7 , V_17 ) ;
}
static T_6 F_32 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
T_3 V_17 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_17 ) ;
if ( V_57 )
return V_57 ;
F_6 ( F_14 ( V_35 ) , V_70 , 2 , V_17 ) ;
return V_40 ;
}
static T_6 F_33 ( struct V_34 * V_35 , char * V_37 )
{
return sprintf ( V_37 , L_8 , F_14 ( V_35 ) -> V_71 ) ;
}
static T_6 F_34 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
struct V_6 * V_7 = F_14 (item)
T_3 V_9 ;
T_2 V_14 , V_72 ;
T_2 V_73 = 0 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_9 ) ;
if ( V_57 )
return V_57 ;
if ( V_9 <= 0x100 )
V_9 = 0x100 ;
else if ( V_9 >= 0x100000 )
V_9 = 0x100000 ;
else {
V_14 = 0 ;
V_72 = 0 ;
while ( V_14 < 21 ) {
V_14 = F_35 ( ( T_3 * ) & V_9 , 21 , V_14 ) ;
if ( V_14 != 21 )
V_72 = V_14 + 1 ;
V_14 ++ ;
V_73 ++ ;
}
if ( V_73 == 2 )
V_72 -- ;
V_9 = 1 << V_72 ;
}
V_7 -> V_71 = V_9 ;
F_6 ( V_7 , V_74 , 4 , V_9 - 1 ) ;
return V_40 ;
}
static T_6 F_36 ( struct V_34 * V_35 ,
char * V_37 )
{
struct V_1 T_1 * V_2 = F_14 ( V_35 ) -> V_11 ;
T_2 V_75 = F_3 ( & V_2 -> V_76 ) ;
return sprintf ( V_37 , L_7 , V_75 ) ;
}
static T_6 F_37 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
struct V_6 * V_7 = F_14 (item)
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
T_3 V_75 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_75 ) ;
if ( V_57 )
return V_57 ;
V_75 &= ~ ( V_7 -> V_71 - 1 ) ;
if ( V_7 -> V_77 )
F_38 ( V_7 -> V_77 ) ;
V_7 -> V_77 = F_39 ( V_75 , V_7 -> V_71 ) ;
if ( ! V_7 -> V_77 )
return - V_78 ;
F_2 ( V_75 , & V_2 -> V_76 ) ;
return V_40 ;
}
static T_6 F_40 ( struct V_34 * V_35 ,
char * V_37 )
{
return sprintf ( V_37 , L_8 , F_14 ( V_35 ) -> V_79 ) ;
}
static T_6 F_41 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
T_3 V_80 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_80 ) ;
if ( V_57 )
return V_57 ;
if ( V_80 % 4 )
return - V_43 ;
F_14 ( V_35 ) -> V_79 = V_80 ;
return V_40 ;
}
static T_6 F_42 ( struct V_34 * V_35 , char * V_37 )
{
struct V_6 * V_7 = F_14 (item)
T_3 V_81 ;
if ( ! V_7 -> V_77 )
return - V_78 ;
V_81 = F_3 ( ( T_3 ) V_7 -> V_77 + V_7 -> V_79 ) ;
return sprintf ( V_37 , L_8 , V_81 ) ;
}
static T_6 F_43 ( struct V_34 * V_35 ,
const char * V_37 , T_7 V_40 )
{
struct V_6 * V_7 = F_14 (item)
T_3 V_81 ;
int V_57 ;
V_57 = F_25 ( V_37 , 0 , & V_81 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_7 -> V_77 )
return - V_78 ;
F_2 ( V_81 , ( T_3 ) V_7 -> V_77 + V_7 -> V_79 ) ;
return V_40 ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_1 T_1 * V_2 = V_7 -> V_11 ;
F_2 ( V_7 -> V_82 , & V_2 -> V_83 ) ;
F_2 ( V_2 -> V_83 + V_84 ,
& V_2 -> V_85 ) ;
F_2 ( V_2 -> V_85 + 1 , & V_2 -> V_86 ) ;
F_2 ( V_2 -> V_86 + V_87 ,
& V_2 -> V_88 ) ;
F_2 ( V_2 -> V_88 + 1 , & V_2 -> V_89 ) ;
F_2 ( V_2 -> V_89 + V_90 ,
& V_2 -> V_91 ) ;
F_2 ( V_2 -> V_91 + 1 , & V_2 -> V_92 ) ;
F_2 ( V_2 -> V_92 + V_93 ,
& V_2 -> V_94 ) ;
F_2 ( V_2 -> V_94 + 1 , & V_2 -> V_95 ) ;
F_2 ( V_2 -> V_95 + V_96 ,
& V_2 -> V_97 ) ;
F_2 ( V_2 -> V_97 + 1 , & V_2 -> V_98 ) ;
F_2 ( V_2 -> V_98 + V_99 ,
& V_2 -> V_100 ) ;
F_2 ( V_2 -> V_83 , & V_2 -> V_101 ) ;
F_2 ( V_2 -> V_86 , & V_2 -> V_102 ) ;
F_2 ( V_2 -> V_89 , & V_2 -> V_103 ) ;
V_7 -> V_71 = V_104 + 1 ;
F_6 ( V_7 , V_74 , 4 , V_104 ) ;
F_6 ( V_7 , V_105 , 4 , 0xC ) ;
V_7 -> V_77 = F_39 ( V_106 ,
V_7 -> V_71 ) ;
F_2 ( V_106 , & V_2 -> V_76 ) ;
F_2 ( 0 , & V_2 -> V_107 ) ;
F_2 ( V_104 + 1 , & V_2 -> V_108 ) ;
F_2 ( 0x0 , & V_2 -> V_109 ) ;
F_2 ( 0x0 , & V_2 -> V_109 ) ;
F_2 ( 0x0 , & V_2 -> V_110 ) ;
F_2 ( V_111 | ( 1 << V_112 )
| ( ( T_2 ) 1 << V_113 ) ,
& V_2 -> V_41 ) ;
F_2 ( 0 , & V_2 -> V_114 ) ;
F_6 ( V_7 , V_48 , 1 , 1 ) ;
}
static int F_45 ( struct V_115 * V_116 )
{
struct V_117 * V_118 , * V_119 ;
unsigned int V_22 = 0 ;
int V_31 ;
struct V_120 * V_120 ;
static struct V_33 * V_121 ;
struct V_6 * V_7 ;
struct V_34 * V_122 ;
struct V_123 * V_36 ;
V_121 = F_46 ( & V_116 -> V_124 , sizeof( * V_121 ) , V_125 ) ;
if ( ! V_121 ) {
F_47 ( & V_116 -> V_124 , L_9 ) ;
return - V_78 ;
}
V_122 = & V_121 -> V_36 . V_126 . V_122 ;
sprintf ( V_122 -> V_127 , L_10 , V_116 -> V_17 ) ;
V_122 -> V_128 = & V_129 ;
V_7 = & V_121 -> V_7 ;
V_118 = F_48 ( V_116 , V_130 , 0 ) ;
V_7 -> V_11 = F_49 ( & V_116 -> V_124 , V_118 ) ;
if ( F_50 ( V_7 -> V_11 ) ) {
F_47 ( & V_116 -> V_124 , L_11 ) ;
return F_51 ( V_7 -> V_11 ) ;
}
V_119 = F_48 ( V_116 , V_130 , 1 ) ;
V_7 -> V_82 = ( void T_1 * ) V_119 -> V_131 ;
V_7 -> V_13 = F_49 ( & V_116 -> V_124 , V_119 ) ;
if ( F_50 ( V_7 -> V_13 ) ) {
F_47 ( & V_116 -> V_124 , L_11 ) ;
return F_51 ( V_7 -> V_13 ) ;
}
F_52 ( V_116 , V_121 ) ;
V_31 = F_53 ( V_116 , 0 ) ;
if ( V_31 < 0 ) {
F_47 ( & V_116 -> V_124 , L_12 ) ;
return V_31 ;
}
V_22 = F_54 ( & V_116 -> V_124 , V_31 , F_13 ,
0 , V_116 -> V_132 , NULL ) ;
if ( V_22 ) {
F_47 ( & V_116 -> V_124 ,
L_13 , V_31 ) ;
return V_22 ;
}
V_36 = & V_121 -> V_36 ;
F_55 ( & V_36 -> V_126 ) ;
F_56 ( & V_36 -> V_133 ) ;
V_22 = F_57 ( V_36 ) ;
if ( V_22 )
return V_22 ;
if ( V_116 -> V_17 == 1 ) {
V_120 = F_58 ( L_14 , NULL ) ;
if ( F_50 ( V_120 ) ) {
F_59 ( L_15 , V_134 ) ;
return F_51 ( V_120 ) ;
}
V_22 = F_60 ( V_120 ) ;
if ( V_22 ) {
F_59 ( L_16 , V_134 ) ;
return V_22 ;
}
} else if ( V_116 -> V_17 == 2 ) {
V_120 = F_58 ( L_17 , NULL ) ;
if ( F_50 ( V_120 ) ) {
F_59 ( L_18 , V_134 ) ;
return F_51 ( V_120 ) ;
}
V_22 = F_60 ( V_120 ) ;
if ( V_22 ) {
F_59 ( L_19 , V_134 ) ;
return V_22 ;
}
}
F_44 ( V_7 ) ;
return 0 ;
}
static int F_61 ( struct V_115 * V_116 )
{
static struct V_33 * V_121 ;
V_121 = F_62 ( V_116 ) ;
F_63 ( & V_121 -> V_36 ) ;
return 0 ;
}
static void F_64 ( struct V_115 * V_116 )
{
}
