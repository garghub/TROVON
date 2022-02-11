static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ,
V_2 -> V_3 ,
F_3 ( V_2 -> V_4 + V_5 ) ,
F_3 ( V_2 -> V_4 + V_6 ) ,
F_3 ( V_2 -> V_4 + V_7 ) ,
F_3 ( V_2 -> V_4 + V_8 ) ,
F_3 ( V_2 -> V_4 + V_9 ) ,
F_3 ( V_2 -> V_4 + V_10 ) ) ;
}
static void F_4 ( struct V_11 * V_12 )
{
F_2 ( L_2 ,
V_12 , V_12 -> V_13 , V_12 -> V_14 , V_12 -> V_15 ,
V_12 -> V_16 , V_12 -> V_17 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_18 * V_20 ;
F_2 ( L_3 ,
V_2 -> V_3 , V_2 -> V_21 , V_2 -> V_22 , V_2 -> V_20 ) ;
V_19 = V_2 -> V_21 ;
V_20 = V_2 -> V_20 ;
if ( V_23 ) {
for (; V_19 != NULL ; V_19 = V_19 -> V_21 ) {
F_2 ( L_4 ,
V_2 -> V_3 , V_19 -> V_24 ) ;
F_4 ( V_19 -> V_12 ) ;
}
}
}
static struct V_1 * F_6 ( unsigned int V_25 )
{
struct V_1 * V_2 ;
unsigned int V_26 , V_27 ;
V_26 = 0 ;
if ( V_25 >= V_28 )
V_26 = 8 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
V_2 = & V_29 [ V_26 + V_27 ] ;
if ( ! V_2 -> V_30 )
goto V_31;
}
return NULL ;
V_31:
V_32 [ V_25 ] = V_2 ;
return V_2 ;
}
int F_7 ( enum V_33 V_25 , int V_34 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
if ( V_2 == NULL )
return - V_35 ;
switch ( V_34 ) {
case 1 :
V_2 -> V_36 = 0 ;
break;
case 2 :
V_2 -> V_36 = 1 ;
break;
case 4 :
V_2 -> V_36 = 2 ;
break;
default:
F_9 ( V_37 L_5 , V_38 , V_34 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
T_1 V_39 , int V_40 )
{
T_1 V_41 , V_42 ;
T_2 V_16 , V_17 ;
switch ( V_2 -> V_43 ) {
case V_44 :
V_41 = V_2 -> V_45 ;
V_42 = V_39 ;
V_16 = V_46 ;
V_16 |= V_47 ;
break;
case V_48 :
V_41 = V_39 ;
V_42 = V_2 -> V_45 ;
V_16 = V_49 ;
V_16 |= V_50 ;
break;
default:
F_11 () ;
}
V_17 = V_40 >> V_2 -> V_36 ;
V_16 |= V_51 ;
V_16 |= V_52 ;
V_16 |= ( T_2 ) V_2 -> V_36 << V_53 ;
V_16 |= ( T_2 ) V_2 -> V_36 << V_54 ;
V_12 -> V_13 = V_41 ;
V_12 -> V_14 = V_42 ;
V_12 -> V_15 = 0 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_17 = V_17 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
void T_3 * V_4 = V_2 -> V_4 ;
F_2 ( L_6 , V_38 , V_12 ) ;
F_4 ( V_12 ) ;
F_13 ( V_12 -> V_13 , V_4 + V_5 ) ;
F_13 ( V_12 -> V_14 , V_4 + V_6 ) ;
F_13 ( V_12 -> V_15 , V_4 + V_7 ) ;
F_13 ( V_12 -> V_16 , V_4 + V_8 ) ;
F_13 ( V_12 -> V_17 , V_4 + V_9 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = V_2 -> V_56 ;
T_2 V_57 ;
T_2 V_58 = V_2 -> V_58 ;
F_1 ( V_2 ) ;
F_2 ( L_7 , V_38 ) ;
F_13 ( V_58 , V_56 -> V_4 + V_59 ) ;
F_13 ( V_58 , V_56 -> V_4 + V_60 ) ;
F_2 ( L_8 , V_38 ) ;
V_57 = F_3 ( V_2 -> V_4 + V_10 ) ;
V_57 |= V_61 ;
V_57 &= ~ V_62 ;
F_2 ( L_9 , V_38 , V_57 ) ;
F_13 ( V_57 , V_2 -> V_4 + V_10 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 V_57 ;
int V_63 ;
F_2 ( L_10 , V_38 ) ;
F_1 ( V_2 ) ;
V_57 = F_3 ( V_2 -> V_4 + V_10 ) ;
V_57 |= V_62 ;
F_13 ( V_57 , V_2 -> V_4 + V_10 ) ;
V_63 = 1000 ;
do {
V_57 = F_3 ( V_2 -> V_4 + V_10 ) ;
F_2 ( L_11 , V_38 , V_63 , V_57 ) ;
if ( V_57 & V_64 )
F_16 ( 10 ) ;
else
break;
} while ( -- V_63 > 0 );
if ( V_57 & V_64 ) {
F_9 ( V_37 L_12 , V_38 ) ;
return - V_65 ;
}
V_57 = F_3 ( V_2 -> V_4 + V_10 ) ;
V_57 &= ~ V_61 ;
F_13 ( V_57 , V_2 -> V_4 + V_10 ) ;
return 0 ;
}
static inline void F_17 ( struct V_1 * V_2 ,
struct V_18 * V_66 ,
enum V_67 V_68 )
{
if ( V_2 -> V_69 != NULL )
( V_2 -> V_69 ) ( V_2 , V_66 -> V_70 , 0 , V_68 ) ;
}
static void F_18 ( struct V_18 * V_71 )
{
F_19 ( V_72 , V_71 -> V_12 , V_71 -> V_24 ) ;
F_20 ( V_71 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_18 * V_71 , * V_21 ;
T_2 V_57 ;
F_1 ( V_2 ) ;
F_2 ( L_13 , V_38 ) ;
V_57 = F_3 ( V_2 -> V_4 + V_10 ) ;
V_57 &= ~ V_61 ;
F_13 ( V_57 , V_2 -> V_4 + V_10 ) ;
for ( V_71 = V_2 -> V_22 ; V_71 != NULL ; V_71 = V_21 ) {
V_21 = V_71 -> V_21 ;
F_2 ( L_14 , V_38 , V_71 , V_71 -> V_21 ) ;
F_17 ( V_2 , V_71 , V_73 ) ;
F_18 ( V_71 ) ;
}
V_2 -> V_22 = V_2 -> V_21 = V_2 -> V_20 = NULL ;
return 0 ;
}
int F_22 ( enum V_33 V_25 , enum V_74 V_75 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
F_23 ( ! V_2 ) ;
if ( ! V_2 )
return - V_35 ;
switch ( V_75 ) {
case V_76 :
return F_14 ( V_2 ) ;
case V_77 :
return F_15 ( V_2 ) ;
case V_78 :
return F_21 ( V_2 ) ;
case V_79 :
case V_80 :
case V_81 :
case V_82 :
return 0 ;
}
return - V_83 ;
}
int F_24 ( enum V_33 V_25 , void * V_84 ,
T_1 V_39 , int V_40 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
struct V_18 * V_21 ;
struct V_18 * V_71 ;
struct V_11 * V_12 ;
unsigned long V_85 ;
int V_86 ;
F_23 ( ! V_2 ) ;
if ( ! V_2 )
return - V_35 ;
V_71 = F_25 ( sizeof( struct V_18 ) , V_87 ) ;
if ( ! V_71 ) {
F_9 ( V_37 L_15 , V_38 ) ;
return - V_88 ;
}
V_12 = F_26 ( V_72 , V_87 , & V_71 -> V_24 ) ;
if ( ! V_12 ) {
F_9 ( V_37 L_16 , V_38 ) ;
V_86 = - V_88 ;
goto V_89;
}
F_2 ( L_17 ,
V_38 , V_71 , V_39 , V_12 , ( T_2 ) V_71 -> V_24 , V_40 ) ;
V_71 -> V_12 = V_12 ;
V_71 -> V_70 = V_84 ;
F_10 ( V_2 , V_12 , V_39 , V_40 ) ;
F_27 ( V_85 ) ;
if ( ( V_21 = V_2 -> V_21 ) != NULL ) {
struct V_18 * V_20 = V_2 -> V_20 ;
struct V_11 * V_90 = V_20 -> V_12 ;
F_2 ( L_18 ) ;
V_20 -> V_21 = V_71 ;
V_90 -> V_15 = V_71 -> V_24 ;
if ( V_2 -> V_85 & V_91 ) {
struct V_18 * V_22 = V_2 -> V_22 ;
V_12 -> V_15 = V_22 -> V_24 ;
}
if ( V_21 == V_2 -> V_22 ) {
F_13 ( V_71 -> V_24 , V_2 -> V_4 + V_7 ) ;
V_2 -> V_21 = V_71 ;
}
F_4 ( V_90 ) ;
V_2 -> V_20 = V_71 ;
} else {
F_2 ( L_19 ) ;
V_2 -> V_22 = V_71 ;
V_2 -> V_21 = V_71 ;
V_2 -> V_20 = V_71 ;
F_12 ( V_2 , V_12 ) ;
}
F_28 ( V_85 ) ;
F_4 ( V_12 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
return 0 ;
V_89:
F_20 ( V_71 ) ;
return V_86 ;
}
int F_29 ( enum V_33 V_25 ,
enum V_92 V_43 ,
unsigned long V_93 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
T_2 V_94 ;
T_2 V_57 = 0 ;
F_2 ( L_20 ,
V_38 , V_25 , V_43 , V_93 , V_2 ) ;
F_23 ( ! V_2 ) ;
if ( ! V_2 )
return - V_35 ;
V_94 = ( V_2 -> V_94 & 0xf ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_45 = V_93 ;
F_2 ( L_21 , V_38 , V_94 ) ;
switch ( V_43 ) {
case V_44 :
V_57 = 2 << V_95 ;
V_57 |= V_94 << V_96 ;
break;
case V_48 :
V_57 = 1 << V_95 ;
V_57 |= V_94 << V_97 ;
break;
default:
F_9 ( V_37 L_22 , V_38 ) ;
return - V_35 ;
}
V_57 |= V_98 ;
V_57 |= V_99 ;
F_2 ( L_23 , V_38 , V_57 ) ;
F_13 ( V_57 , V_2 -> V_4 + V_10 ) ;
return 0 ;
}
int F_30 ( enum V_33 V_25 ,
T_1 * V_41 , T_1 * V_42 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
F_23 ( ! V_2 ) ;
if ( ! V_2 )
return - V_35 ;
if ( V_41 != NULL )
* V_41 = F_3 ( V_2 -> V_4 + V_5 ) ;
if ( V_42 != NULL )
* V_42 = F_3 ( V_2 -> V_4 + V_6 ) ;
return 0 ;
}
int F_31 ( enum V_33 V_25 ,
struct V_100 * V_101 ,
void * V_102 )
{
struct V_1 * V_2 ;
unsigned long V_85 ;
F_2 ( L_24 ,
V_25 , V_101 -> V_103 , V_102 ) ;
F_27 ( V_85 ) ;
V_2 = F_6 ( V_25 ) ;
if ( V_2 == NULL ) {
F_28 ( V_85 ) ;
return - V_104 ;
}
F_1 ( V_2 ) ;
V_2 -> V_101 = V_101 ;
V_2 -> V_30 = 1 ;
V_2 -> V_94 = V_25 ;
V_2 -> V_85 = 0 ;
F_28 ( V_85 ) ;
F_2 ( L_25 , V_38 , V_2 ) ;
return V_2 -> V_3 | V_105 ;
}
int F_32 ( enum V_33 V_25 , struct V_100 * V_101 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
unsigned long V_85 ;
if ( V_2 == NULL )
return - V_35 ;
F_27 ( V_85 ) ;
if ( V_2 -> V_101 != V_101 ) {
F_9 ( V_106 L_26 ,
V_25 , V_2 -> V_101 , V_101 ) ;
}
V_2 -> V_101 = NULL ;
V_2 -> V_30 = 0 ;
if ( ! ( V_25 & V_105 ) )
V_32 [ V_25 ] = NULL ;
F_28 ( V_85 ) ;
return 0 ;
}
static T_4 F_33 ( int V_107 , void * V_70 )
{
struct V_55 * V_56 = V_70 ;
struct V_1 * V_2 ;
enum V_67 V_108 ;
T_2 V_109 , V_110 ;
T_2 V_58 ;
int V_27 ;
V_109 = F_3 ( V_56 -> V_4 + V_111 ) ;
V_110 = F_3 ( V_56 -> V_4 + V_112 ) ;
for ( V_27 = 0 , V_58 = 1 ; V_27 < 8 ; V_27 ++ , V_58 <<= 1 ) {
struct V_18 * V_71 ;
if ( ! ( V_110 & V_58 ) && ! ( V_109 & V_58 ) )
continue;
V_2 = V_56 -> V_113 + V_27 ;
V_108 = V_114 ;
if ( V_109 & V_58 ) {
F_13 ( V_58 , V_56 -> V_4 + V_59 ) ;
V_108 = V_115 ;
}
if ( V_110 & V_58 )
F_13 ( V_58 , V_56 -> V_4 + V_60 ) ;
V_71 = V_2 -> V_22 ;
while ( V_71 && V_71 != V_2 -> V_21
&& V_71 -> V_21 != V_2 -> V_21 )
V_71 = V_71 -> V_21 ;
if ( ! V_71 )
F_11 () ;
if ( V_71 == V_2 -> V_21 )
V_71 = V_2 -> V_20 ;
F_17 ( V_2 , V_71 , V_108 ) ;
if ( ! ( V_2 -> V_85 & V_91 ) ) {
V_2 -> V_22 = V_71 -> V_21 ;
F_18 ( V_71 ) ;
}
V_71 = V_2 -> V_21 ;
if ( V_2 -> V_21 == V_2 -> V_20 ) {
V_2 -> V_21 = V_2 -> V_22 ;
if ( ! ( V_2 -> V_85 & V_91 ) )
V_2 -> V_20 = NULL ;
} else {
V_2 -> V_21 = V_71 -> V_21 ;
}
}
return V_116 ;
}
static int F_34 ( int V_117 , enum V_33 V_118 ,
int V_107 , unsigned int V_119 )
{
struct V_1 * V_120 = & V_29 [ V_117 ] ;
struct V_55 * V_56 ;
char V_121 [ 16 ] ;
void T_3 * V_4 ;
void T_3 * V_122 ;
int V_123 , V_124 ;
V_56 = F_25 ( sizeof( struct V_55 ) , V_125 ) ;
if ( ! V_56 ) {
F_9 ( V_37 L_27 , V_38 ) ;
return - V_88 ;
}
V_56 -> V_102 . V_84 = V_117 / 8 ;
V_56 -> V_102 . V_126 = & V_127 ;
V_123 = F_35 ( & V_56 -> V_102 ) ;
if ( V_123 ) {
F_9 ( V_37 L_28 , V_38 ) ;
goto V_128;
}
V_4 = F_36 ( V_119 , 0x200 ) ;
if ( ! V_4 ) {
F_9 ( V_37 L_29 , V_38 ) ;
V_123 = - V_129 ;
goto V_130;
}
snprintf ( V_121 , sizeof( V_121 ) , L_30 , V_56 -> V_102 . V_84 ) ;
V_56 -> V_131 = F_37 ( NULL , V_121 ) ;
if ( F_38 ( V_56 -> V_131 ) ) {
F_9 ( V_37 L_31 , V_38 , V_121 ) ;
V_123 = F_39 ( V_56 -> V_131 ) ;
goto V_132;
}
F_40 ( V_56 -> V_131 ) ;
V_56 -> V_4 = V_4 ;
V_56 -> V_133 = V_118 ;
V_56 -> V_113 = V_120 ;
V_123 = F_41 ( V_107 , F_33 , 0 , L_32 , V_56 ) ;
if ( V_123 < 0 ) {
F_9 ( V_37 L_33 , V_38 ) ;
goto V_134;
}
V_122 = V_4 + F_42 ( 0 ) ;
for ( V_124 = 0 ; V_124 < 8 ; V_124 ++ , V_120 ++ ) {
F_2 ( L_34 ,
V_38 , V_117 + V_124 , V_122 ) ;
V_120 -> V_58 = 1 << V_124 ;
V_120 -> V_3 = V_117 + V_124 ;
V_120 -> V_56 = V_56 ;
V_120 -> V_4 = V_122 ;
V_122 += V_135 ;
}
F_13 ( V_61 , V_4 + V_136 ) ;
F_9 ( V_137 L_35 ,
V_107 , V_4 , V_117 , V_117 + 8 ) ;
return 0 ;
V_134:
F_43 ( V_56 -> V_131 ) ;
F_44 ( V_56 -> V_131 ) ;
V_132:
F_45 ( V_4 ) ;
V_130:
F_46 ( & V_56 -> V_102 ) ;
V_128:
F_20 ( V_56 ) ;
return V_123 ;
}
static int T_5 F_47 ( void )
{
int V_86 ;
if ( F_48 () )
return - V_138 ;
F_9 ( V_137 L_36 , V_38 ) ;
V_72 = F_49 ( L_37 , NULL , sizeof( struct V_11 ) , 16 , 0 ) ;
if ( ! V_72 ) {
F_9 ( V_37 L_38 , V_38 ) ;
return - V_88 ;
}
V_86 = F_50 ( & V_127 , NULL ) ;
if ( V_86 ) {
F_9 ( V_37 L_39 , V_38 ) ;
return - V_88 ;
}
F_13 ( 0xffffff , V_139 ) ;
F_34 ( 0 , V_140 , V_141 , 0x75000000 ) ;
F_34 ( 8 , V_28 , V_142 , 0x75100000 ) ;
return 0 ;
}
