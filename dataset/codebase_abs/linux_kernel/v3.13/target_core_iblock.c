static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
F_4 ( L_1
L_2 , V_5 -> V_7 ,
V_8 , V_9 ) ;
return 0 ;
}
static void F_5 ( struct V_4 * V_5 )
{
}
static struct V_2 * F_6 ( struct V_4 * V_5 , const char * V_10 )
{
struct V_1 * V_11 = NULL ;
V_11 = F_7 ( sizeof( struct V_1 ) , V_12 ) ;
if ( ! V_11 ) {
F_8 ( L_3 ) ;
return NULL ;
}
F_4 ( L_4 , V_10 ) ;
return & V_11 -> V_3 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 = NULL ;
T_2 V_17 ;
int V_18 = - V_19 ;
if ( ! ( V_11 -> V_20 & V_21 ) ) {
F_8 ( L_5 ) ;
return - V_22 ;
}
V_11 -> V_23 = F_10 ( V_24 , 0 ) ;
if ( ! V_11 -> V_23 ) {
F_8 ( L_6 ) ;
goto V_25;
}
F_4 ( L_7 ,
V_11 -> V_26 ) ;
V_17 = V_27 | V_28 ;
if ( ! V_11 -> V_29 )
V_17 |= V_30 ;
V_16 = F_11 ( V_11 -> V_26 , V_17 , V_11 ) ;
if ( F_12 ( V_16 ) ) {
V_18 = F_13 ( V_16 ) ;
goto V_31;
}
V_11 -> V_32 = V_16 ;
V_14 = F_14 ( V_16 ) ;
V_3 -> V_33 . V_34 = F_15 ( V_16 ) ;
V_3 -> V_33 . V_35 = V_36 ;
V_3 -> V_33 . V_37 = V_14 -> V_38 ;
if ( F_16 ( V_14 ) ) {
V_3 -> V_33 . V_39 =
V_14 -> V_40 . V_41 ;
V_3 -> V_33 . V_42 = 1 ;
V_3 -> V_33 . V_43 =
V_14 -> V_40 . V_44 >> 9 ;
V_3 -> V_33 . V_45 =
V_14 -> V_40 . V_46 ;
F_4 ( L_8
L_9 ) ;
}
V_3 -> V_33 . V_47 = 0xFFFF ;
if ( F_17 ( V_14 ) )
V_3 -> V_33 . V_48 = 1 ;
return 0 ;
V_31:
F_18 ( V_11 -> V_23 ) ;
V_11 -> V_23 = NULL ;
V_25:
return V_18 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_11 -> V_32 != NULL )
F_20 ( V_11 -> V_32 , V_30 | V_27 | V_28 ) ;
if ( V_11 -> V_23 != NULL )
F_18 ( V_11 -> V_23 ) ;
F_21 ( V_11 ) ;
}
static unsigned long long F_22 (
struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_13 * V_14 )
{
unsigned long long V_49 = ( F_23 ( F_24 ( V_16 -> V_50 ) ,
F_15 ( V_16 ) ) - 1 ) ;
T_1 V_51 = F_15 ( V_16 ) ;
if ( V_51 == V_3 -> V_33 . V_51 )
return V_49 ;
switch ( V_51 ) {
case 4096 :
switch ( V_3 -> V_33 . V_51 ) {
case 2048 :
V_49 <<= 1 ;
break;
case 1024 :
V_49 <<= 2 ;
break;
case 512 :
V_49 <<= 3 ;
default:
break;
}
break;
case 2048 :
switch ( V_3 -> V_33 . V_51 ) {
case 4096 :
V_49 >>= 1 ;
break;
case 1024 :
V_49 <<= 1 ;
break;
case 512 :
V_49 <<= 2 ;
break;
default:
break;
}
break;
case 1024 :
switch ( V_3 -> V_33 . V_51 ) {
case 4096 :
V_49 >>= 2 ;
break;
case 2048 :
V_49 >>= 1 ;
break;
case 512 :
V_49 <<= 1 ;
break;
default:
break;
}
break;
case 512 :
switch ( V_3 -> V_33 . V_51 ) {
case 4096 :
V_49 >>= 3 ;
break;
case 2048 :
V_49 >>= 2 ;
break;
case 1024 :
V_49 >>= 1 ;
break;
default:
break;
}
break;
default:
break;
}
return V_49 ;
}
static void F_25 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_53 -> V_56 ;
T_3 V_57 ;
if ( ! F_26 ( & V_55 -> V_58 ) )
return;
if ( F_27 ( & V_55 -> V_59 ) )
V_57 = V_60 ;
else
V_57 = V_61 ;
F_28 ( V_53 , V_57 ) ;
F_21 ( V_55 ) ;
}
static void F_29 ( struct V_62 * V_62 , int V_63 )
{
struct V_52 * V_53 = V_62 -> V_64 ;
struct V_54 * V_55 = V_53 -> V_56 ;
if ( ! F_30 ( V_65 , & V_62 -> V_66 ) && ! V_63 )
V_63 = - V_67 ;
if ( V_63 != 0 ) {
F_8 ( L_10
L_11 , V_62 , V_63 ) ;
F_31 ( & V_55 -> V_59 ) ;
F_32 () ;
}
F_33 ( V_62 ) ;
F_25 ( V_53 ) ;
}
static struct V_62 *
F_34 ( struct V_52 * V_53 , T_4 V_68 , T_1 V_69 )
{
struct V_1 * V_11 = F_1 ( V_53 -> V_70 ) ;
struct V_62 * V_62 ;
if ( V_69 > V_71 )
V_69 = V_71 ;
V_62 = F_35 ( V_72 , V_69 , V_11 -> V_23 ) ;
if ( ! V_62 ) {
F_8 ( L_12 ) ;
return NULL ;
}
V_62 -> V_73 = V_11 -> V_32 ;
V_62 -> V_64 = V_53 ;
V_62 -> V_74 = & F_29 ;
V_62 -> V_75 = V_68 ;
return V_62 ;
}
static void F_36 ( struct V_76 * V_77 , int V_78 )
{
struct V_79 V_80 ;
struct V_62 * V_62 ;
F_37 ( & V_80 ) ;
while ( ( V_62 = F_38 ( V_77 ) ) )
F_39 ( V_78 , V_62 ) ;
F_40 ( & V_80 ) ;
}
static void F_41 ( struct V_62 * V_62 , int V_63 )
{
struct V_52 * V_53 = V_62 -> V_64 ;
if ( V_63 )
F_8 ( L_13 , V_63 ) ;
if ( V_53 ) {
if ( V_63 )
F_28 ( V_53 , V_60 ) ;
else
F_28 ( V_53 , V_61 ) ;
}
F_33 ( V_62 ) ;
}
static T_5
F_42 ( struct V_52 * V_53 )
{
struct V_1 * V_11 = F_1 ( V_53 -> V_70 ) ;
int V_81 = ( V_53 -> V_82 [ 1 ] & 0x2 ) ;
struct V_62 * V_62 ;
if ( V_81 )
F_28 ( V_53 , V_61 ) ;
V_62 = F_43 ( V_12 , 0 ) ;
V_62 -> V_74 = F_41 ;
V_62 -> V_73 = V_11 -> V_32 ;
if ( ! V_81 )
V_62 -> V_64 = V_53 ;
F_39 ( V_83 , V_62 ) ;
return 0 ;
}
static T_5
F_44 ( struct V_52 * V_53 , void * V_56 ,
T_4 V_68 , T_4 V_84 )
{
struct V_15 * V_85 = V_56 ;
int V_18 ;
V_18 = F_45 ( V_85 , V_68 , V_84 , V_12 , 0 ) ;
if ( V_18 < 0 ) {
F_8 ( L_14 , V_18 ) ;
return V_86 ;
}
return 0 ;
}
static T_5
F_46 ( struct V_52 * V_53 )
{
struct V_15 * V_85 = F_1 ( V_53 -> V_70 ) -> V_32 ;
return F_47 ( V_53 , F_44 , V_85 ) ;
}
static T_5
F_48 ( struct V_52 * V_53 )
{
struct V_15 * V_85 = F_1 ( V_53 -> V_70 ) -> V_32 ;
T_4 V_68 = V_53 -> V_87 ;
T_4 V_84 = F_49 ( V_53 ) ;
int V_18 ;
V_18 = F_44 ( V_53 , V_85 , V_68 , V_84 ) ;
if ( V_18 )
return V_18 ;
F_28 ( V_53 , V_88 ) ;
return 0 ;
}
static T_5
F_50 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_89 * V_90 ;
struct V_62 * V_62 ;
struct V_76 V_77 ;
T_4 V_91 = V_53 -> V_87 ;
T_4 V_92 = F_49 ( V_53 ) ;
V_90 = & V_53 -> V_93 [ 0 ] ;
if ( V_53 -> V_94 > 1 ||
V_90 -> V_95 != V_53 -> V_70 -> V_33 . V_51 ) {
F_8 ( L_15
L_16 , V_53 -> V_94 , V_90 -> V_95 ,
V_53 -> V_70 -> V_33 . V_51 ) ;
return V_96 ;
}
V_55 = F_7 ( sizeof( struct V_54 ) , V_12 ) ;
if ( ! V_55 )
goto V_97;
V_53 -> V_56 = V_55 ;
V_62 = F_34 ( V_53 , V_91 , 1 ) ;
if ( ! V_62 )
goto V_98;
F_51 ( & V_77 ) ;
F_52 ( & V_77 , V_62 ) ;
F_53 ( & V_55 -> V_58 , 1 ) ;
while ( V_92 ) {
while ( F_54 ( V_62 , F_55 ( V_90 ) , V_90 -> V_95 , V_90 -> V_99 )
!= V_90 -> V_95 ) {
V_62 = F_34 ( V_53 , V_91 , 1 ) ;
if ( ! V_62 )
goto V_100;
F_31 ( & V_55 -> V_58 ) ;
F_52 ( & V_77 , V_62 ) ;
}
V_91 += V_90 -> V_95 >> V_101 ;
V_92 -= 1 ;
}
F_36 ( & V_77 , V_102 ) ;
return 0 ;
V_100:
while ( ( V_62 = F_38 ( & V_77 ) ) )
F_33 ( V_62 ) ;
V_98:
F_21 ( V_55 ) ;
V_97:
return V_86 ;
}
static T_6 F_56 ( struct V_2 * V_3 ,
const char * V_103 , T_6 V_104 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
char * V_105 , * V_106 , * V_107 , * V_108 ;
T_7 args [ V_109 ] ;
int V_18 = 0 , V_110 ;
unsigned long V_111 ;
V_108 = F_57 ( V_103 , V_12 ) ;
if ( ! V_108 )
return - V_19 ;
V_105 = V_108 ;
while ( ( V_106 = F_58 ( & V_108 , L_17 ) ) != NULL ) {
if ( ! * V_106 )
continue;
V_110 = F_59 ( V_106 , V_112 , args ) ;
switch ( V_110 ) {
case V_113 :
if ( V_11 -> V_32 ) {
F_8 ( L_18
L_19 ) ;
V_18 = - V_114 ;
goto V_25;
}
if ( F_60 ( V_11 -> V_26 , & args [ 0 ] ,
V_115 ) == 0 ) {
V_18 = - V_22 ;
break;
}
F_4 ( L_20 ,
V_11 -> V_26 ) ;
V_11 -> V_20 |= V_21 ;
break;
case V_116 :
V_107 = F_61 ( & args [ 0 ] ) ;
if ( ! V_107 ) {
V_18 = - V_19 ;
break;
}
V_18 = F_62 ( V_107 , 0 , & V_111 ) ;
F_21 ( V_107 ) ;
if ( V_18 < 0 ) {
F_8 ( L_21
L_22 ) ;
goto V_25;
}
V_11 -> V_29 = V_111 ;
F_4 ( L_23 , V_11 -> V_29 ) ;
break;
case V_117 :
break;
default:
break;
}
}
V_25:
F_21 ( V_105 ) ;
return ( ! V_18 ) ? V_104 : V_18 ;
}
static T_6 F_63 ( struct V_2 * V_3 , char * V_118 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
char V_119 [ V_120 ] ;
T_6 V_121 = 0 ;
if ( V_16 )
V_121 += sprintf ( V_118 + V_121 , L_24 ,
F_64 ( V_16 , V_119 ) ) ;
if ( V_11 -> V_20 & V_21 )
V_121 += sprintf ( V_118 + V_121 , L_25 ,
V_11 -> V_26 ) ;
V_121 += sprintf ( V_118 + V_121 , L_26 , V_11 -> V_29 ) ;
V_121 += sprintf ( V_118 + V_121 , L_27 ) ;
if ( V_16 ) {
V_121 += sprintf ( V_118 + V_121 , L_28 ,
F_65 ( V_16 -> V_122 ) , F_66 ( V_16 -> V_122 ) , ( ! V_16 -> V_123 ) ?
L_29 : ( V_16 -> V_124 == V_11 ) ?
L_30 : L_31 ) ;
} else {
V_121 += sprintf ( V_118 + V_121 , L_32 ) ;
}
return V_121 ;
}
static T_5
F_67 ( struct V_52 * V_53 , struct V_89 * V_125 , T_1 V_126 ,
enum V_127 V_128 )
{
struct V_2 * V_3 = V_53 -> V_70 ;
struct V_54 * V_55 ;
struct V_62 * V_62 ;
struct V_76 V_77 ;
struct V_89 * V_90 ;
T_1 V_69 = V_126 ;
T_4 V_91 ;
unsigned V_129 ;
int V_78 = 0 ;
int V_130 ;
if ( V_128 == V_131 ) {
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_13 * V_14 = F_14 ( V_11 -> V_32 ) ;
if ( V_14 -> V_132 & V_133 ) {
if ( V_53 -> V_134 & V_135 )
V_78 = V_136 ;
else if ( ! ( V_14 -> V_132 & V_137 ) )
V_78 = V_136 ;
else
V_78 = V_102 ;
} else {
V_78 = V_102 ;
}
} else {
V_78 = V_138 ;
}
if ( V_3 -> V_33 . V_51 == 4096 )
V_91 = ( V_53 -> V_87 << 3 ) ;
else if ( V_3 -> V_33 . V_51 == 2048 )
V_91 = ( V_53 -> V_87 << 2 ) ;
else if ( V_3 -> V_33 . V_51 == 1024 )
V_91 = ( V_53 -> V_87 << 1 ) ;
else if ( V_3 -> V_33 . V_51 == 512 )
V_91 = V_53 -> V_87 ;
else {
F_8 ( L_33
L_34 , V_3 -> V_33 . V_51 ) ;
return V_86 ;
}
V_55 = F_7 ( sizeof( struct V_54 ) , V_12 ) ;
if ( ! V_55 )
goto V_97;
V_53 -> V_56 = V_55 ;
if ( ! V_126 ) {
F_53 ( & V_55 -> V_58 , 1 ) ;
F_25 ( V_53 ) ;
return 0 ;
}
V_62 = F_34 ( V_53 , V_91 , V_126 ) ;
if ( ! V_62 )
goto V_98;
F_51 ( & V_77 ) ;
F_52 ( & V_77 , V_62 ) ;
F_53 ( & V_55 -> V_58 , 2 ) ;
V_129 = 1 ;
F_68 (sgl, sg, sgl_nents, i) {
while ( F_54 ( V_62 , F_55 ( V_90 ) , V_90 -> V_95 , V_90 -> V_99 )
!= V_90 -> V_95 ) {
if ( V_129 >= V_139 ) {
F_36 ( & V_77 , V_78 ) ;
V_129 = 0 ;
}
V_62 = F_34 ( V_53 , V_91 , V_69 ) ;
if ( ! V_62 )
goto V_100;
F_31 ( & V_55 -> V_58 ) ;
F_52 ( & V_77 , V_62 ) ;
V_129 ++ ;
}
V_91 += V_90 -> V_95 >> V_101 ;
V_69 -- ;
}
F_36 ( & V_77 , V_78 ) ;
F_25 ( V_53 ) ;
return 0 ;
V_100:
while ( ( V_62 = F_38 ( & V_77 ) ) )
F_33 ( V_62 ) ;
V_98:
F_21 ( V_55 ) ;
V_97:
return V_86 ;
}
static T_4 F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return F_22 ( V_3 , V_16 , V_14 ) ;
}
static T_4 F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
int V_18 ;
V_18 = F_71 ( V_16 ) ;
if ( V_18 == - 1 )
return 0 ;
return V_18 / F_15 ( V_16 ) ;
}
static unsigned int F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
int V_140 = F_73 ( V_16 ) / F_15 ( V_16 ) ;
return F_74 ( V_140 ) ;
}
static unsigned int F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
return F_76 ( V_16 ) ;
}
static unsigned int F_77 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
return F_78 ( V_16 ) ;
}
static T_5
F_79 ( struct V_52 * V_53 )
{
return F_80 ( V_53 , & V_141 ) ;
}
bool F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_11 -> V_32 ;
struct V_13 * V_14 = F_14 ( V_16 ) ;
return V_14 -> V_132 & V_137 ;
}
static int T_8 F_82 ( void )
{
return F_83 ( & V_142 ) ;
}
static void T_9 F_84 ( void )
{
F_85 ( & V_142 ) ;
}
