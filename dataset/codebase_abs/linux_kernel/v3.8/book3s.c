void F_1 ( struct V_1 * V_2 )
{
}
void F_2 ( struct V_1 * V_2 )
{
}
void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
V_2 -> V_5 . V_6 -> V_7 = F_4 ( V_2 ) ;
V_2 -> V_5 . V_6 -> V_8 = V_2 -> V_5 . V_6 -> V_9 | V_4 ;
F_5 ( V_2 , F_6 ( V_2 ) + V_3 ) ;
V_2 -> V_5 . V_10 . V_11 ( V_2 ) ;
}
static int F_7 ( unsigned int V_3 )
{
unsigned int V_12 ;
switch ( V_3 ) {
case 0x100 : V_12 = V_13 ; break;
case 0x200 : V_12 = V_14 ; break;
case 0x300 : V_12 = V_15 ; break;
case 0x380 : V_12 = V_16 ; break;
case 0x400 : V_12 = V_17 ; break;
case 0x480 : V_12 = V_18 ; break;
case 0x500 : V_12 = V_19 ; break;
case 0x501 : V_12 = V_20 ; break;
case 0x600 : V_12 = V_21 ; break;
case 0x700 : V_12 = V_22 ; break;
case 0x800 : V_12 = V_23 ; break;
case 0x900 : V_12 = V_24 ; break;
case 0xc00 : V_12 = V_25 ; break;
case 0xd00 : V_12 = V_26 ; break;
case 0xf20 : V_12 = V_27 ; break;
case 0xf40 : V_12 = V_28 ; break;
default: V_12 = V_29 ; break;
}
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long V_30 = V_2 -> V_5 . V_31 ;
F_9 ( F_7 ( V_3 ) ,
& V_2 -> V_5 . V_31 ) ;
F_10 ( V_2 , V_2 -> V_5 . V_31 ,
V_30 ) ;
}
void F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
V_2 -> V_32 . V_33 ++ ;
F_12 ( F_7 ( V_3 ) ,
& V_2 -> V_5 . V_31 ) ;
#ifdef F_13
F_14 ( V_34 L_1 , V_3 ) ;
#endif
}
void F_15 ( struct V_1 * V_2 , T_2 V_4 )
{
F_3 ( V_2 , V_35 , V_4 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_36 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
return F_18 ( V_24 , & V_2 -> V_5 . V_31 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_36 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
unsigned int V_3 = V_39 ;
if ( V_38 -> V_38 == V_40 )
V_3 = V_41 ;
F_11 ( V_2 , V_3 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
F_8 ( V_2 , V_39 ) ;
F_8 ( V_2 , V_41 ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_42 )
{
int V_43 = 1 ;
int V_3 = 0 ;
bool V_44 = F_23 ( V_2 ) ;
switch ( V_42 ) {
case V_24 :
V_43 = ( V_2 -> V_5 . V_6 -> V_9 & V_45 ) && ! V_44 ;
V_3 = V_36 ;
break;
case V_19 :
case V_20 :
V_43 = ( V_2 -> V_5 . V_6 -> V_9 & V_45 ) && ! V_44 ;
V_3 = V_39 ;
break;
case V_13 :
V_3 = V_46 ;
break;
case V_14 :
V_3 = V_47 ;
break;
case V_15 :
V_3 = V_48 ;
break;
case V_17 :
V_3 = V_49 ;
break;
case V_16 :
V_3 = V_50 ;
break;
case V_18 :
V_3 = V_51 ;
break;
case V_21 :
V_3 = V_52 ;
break;
case V_22 :
V_3 = V_35 ;
break;
case V_28 :
V_3 = V_53 ;
break;
case V_27 :
V_3 = V_54 ;
break;
case V_23 :
V_3 = V_55 ;
break;
case V_25 :
V_3 = V_56 ;
break;
case V_26 :
V_3 = V_57 ;
break;
case V_58 :
V_3 = V_59 ;
break;
default:
V_43 = 0 ;
F_14 ( V_60 L_2 , V_42 ) ;
break;
}
#if 0
printk(KERN_INFO "Deliver interrupt 0x%x? %x\n", vec, deliver);
#endif
if ( V_43 )
F_3 ( V_2 , V_3 , 0 ) ;
return V_43 ;
}
static bool F_24 ( struct V_1 * V_2 , unsigned int V_42 )
{
switch ( V_42 ) {
case V_24 :
return false ;
case V_20 :
return false ;
}
return true ;
}
int F_25 ( struct V_1 * V_2 )
{
unsigned long * V_61 = & V_2 -> V_5 . V_31 ;
unsigned long V_30 = V_2 -> V_5 . V_31 ;
unsigned int V_42 ;
#ifdef F_13
if ( V_2 -> V_5 . V_31 )
F_14 ( V_62 L_3 , V_2 -> V_5 . V_31 ) ;
#endif
V_42 = F_26 ( * V_61 ) ;
while ( V_42 < V_29 ) {
if ( F_22 ( V_2 , V_42 ) &&
F_24 ( V_2 , V_42 ) ) {
F_9 ( V_42 , & V_2 -> V_5 . V_31 ) ;
break;
}
V_42 = F_27 ( V_61 ,
V_63 * sizeof( * V_61 ) ,
V_42 + 1 ) ;
}
F_10 ( V_2 , * V_61 , V_30 ) ;
return 0 ;
}
T_3 F_28 ( struct V_1 * V_2 , T_4 V_64 )
{
T_2 V_65 = V_2 -> V_5 . V_66 ;
if ( ! ( V_2 -> V_5 . V_6 -> V_9 & V_67 ) )
V_65 = ( V_68 ) V_65 ;
if ( F_29 ( V_65 ) &&
F_29 ( ( ( V_64 << V_69 ) & V_70 ) ==
( ( V_65 & V_71 ) & V_70 ) ) ) {
T_2 V_72 = ( ( T_2 ) V_2 -> V_5 . V_6 ) & V_71 ;
T_3 V_73 ;
V_73 = ( T_3 ) F_30 ( ( void * ) V_72 ) >> V_69 ;
F_31 ( F_32 ( V_73 ) ) ;
return V_73 ;
}
return F_33 ( V_2 -> V_74 , V_64 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_2 V_75 , bool V_76 ,
struct V_77 * V_78 )
{
int V_79 = ( V_2 -> V_5 . V_6 -> V_9 & ( V_76 ? V_80 : V_81 ) ) ;
int V_82 ;
if ( V_79 ) {
V_82 = V_2 -> V_5 . V_10 . V_83 ( V_2 , V_75 , V_78 , V_76 ) ;
} else {
V_78 -> V_75 = V_75 ;
V_78 -> V_84 = V_75 & V_70 ;
V_78 -> V_85 = V_86 | V_75 >> 12 ;
V_78 -> V_87 = true ;
V_78 -> V_88 = true ;
V_78 -> V_89 = true ;
V_82 = 0 ;
}
return V_82 ;
}
static T_5 F_35 ( void )
{
return V_90 ;
}
static T_5 F_36 ( struct V_1 * V_2 , struct V_77 * V_78 ,
bool V_91 )
{
T_5 V_92 ;
if ( V_91 && ! V_78 -> V_87 )
goto V_93;
if ( ! V_91 && ! V_78 -> V_88 )
goto V_93;
V_92 = F_37 ( V_2 -> V_74 , V_78 -> V_84 >> V_69 ) ;
if ( F_38 ( V_92 ) )
goto V_93;
return V_92 | ( V_78 -> V_84 & ~ V_71 ) ;
V_93:
return F_35 () ;
}
int F_39 ( struct V_1 * V_2 , T_2 * V_75 , int V_94 , void * V_95 ,
bool V_76 )
{
struct V_77 V_78 ;
V_2 -> V_32 . V_96 ++ ;
if ( F_34 ( V_2 , * V_75 , V_76 , & V_78 ) )
return - V_97 ;
* V_75 = V_78 . V_84 ;
if ( ! V_78 . V_88 )
return - V_98 ;
if ( F_40 ( V_2 -> V_74 , V_78 . V_84 , V_95 , V_94 ) )
return V_99 ;
return V_100 ;
}
int F_41 ( struct V_1 * V_2 , T_2 * V_75 , int V_94 , void * V_95 ,
bool V_76 )
{
struct V_77 V_78 ;
T_5 V_101 = * V_75 ;
V_2 -> V_32 . V_102 ++ ;
if ( F_34 ( V_2 , * V_75 , V_76 , & V_78 ) )
goto V_103;
* V_75 = V_78 . V_84 ;
V_101 = F_36 ( V_2 , & V_78 , true ) ;
if ( F_38 ( V_101 ) )
goto V_104;
if ( F_42 ( V_95 , ( void V_105 * ) V_101 , V_94 ) ) {
F_14 ( V_34 L_4 , V_101 ) ;
goto V_104;
}
return V_100 ;
V_103:
return - V_97 ;
V_104:
return V_99 ;
}
int F_43 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
}
int F_46 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
int V_108 ;
V_107 -> V_109 = F_4 ( V_2 ) ;
V_107 -> V_110 = F_47 ( V_2 ) ;
V_107 -> V_111 = F_48 ( V_2 ) ;
V_107 -> V_112 = F_49 ( V_2 ) ;
V_107 -> V_113 = F_50 ( V_2 ) ;
V_107 -> V_9 = V_2 -> V_5 . V_6 -> V_9 ;
V_107 -> V_7 = V_2 -> V_5 . V_6 -> V_7 ;
V_107 -> V_8 = V_2 -> V_5 . V_6 -> V_8 ;
V_107 -> V_114 = V_2 -> V_5 . V_114 ;
V_107 -> V_115 = V_2 -> V_5 . V_6 -> V_115 ;
V_107 -> V_116 = V_2 -> V_5 . V_6 -> V_116 ;
V_107 -> V_117 = V_2 -> V_5 . V_6 -> V_117 ;
V_107 -> V_118 = V_2 -> V_5 . V_6 -> V_118 ;
V_107 -> V_119 = V_2 -> V_5 . V_6 -> V_119 ;
V_107 -> V_120 = V_2 -> V_5 . V_6 -> V_120 ;
V_107 -> V_121 = V_2 -> V_5 . V_6 -> V_121 ;
V_107 -> V_122 = V_2 -> V_5 . V_6 -> V_122 ;
for ( V_108 = 0 ; V_108 < F_51 ( V_107 -> V_123 ) ; V_108 ++ )
V_107 -> V_123 [ V_108 ] = F_52 ( V_2 , V_108 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
int V_108 ;
F_5 ( V_2 , V_107 -> V_109 ) ;
F_54 ( V_2 , V_107 -> V_110 ) ;
F_55 ( V_2 , V_107 -> V_111 ) ;
F_56 ( V_2 , V_107 -> V_112 ) ;
F_57 ( V_2 , V_107 -> V_113 ) ;
F_58 ( V_2 , V_107 -> V_9 ) ;
V_2 -> V_5 . V_6 -> V_7 = V_107 -> V_7 ;
V_2 -> V_5 . V_6 -> V_8 = V_107 -> V_8 ;
V_2 -> V_5 . V_6 -> V_115 = V_107 -> V_115 ;
V_2 -> V_5 . V_6 -> V_116 = V_107 -> V_116 ;
V_2 -> V_5 . V_6 -> V_117 = V_107 -> V_117 ;
V_2 -> V_5 . V_6 -> V_118 = V_107 -> V_118 ;
V_2 -> V_5 . V_6 -> V_119 = V_107 -> V_119 ;
V_2 -> V_5 . V_6 -> V_120 = V_107 -> V_120 ;
V_2 -> V_5 . V_6 -> V_121 = V_107 -> V_121 ;
V_2 -> V_5 . V_6 -> V_122 = V_107 -> V_122 ;
for ( V_108 = 0 ; V_108 < F_51 ( V_107 -> V_123 ) ; V_108 ++ )
F_59 ( V_2 , V_108 , V_107 -> V_123 [ V_108 ] ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
return - V_126 ;
}
int F_61 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
return - V_126 ;
}
int F_62 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
int V_82 ;
union V_129 V_130 ;
int V_94 ;
long int V_108 ;
V_94 = F_63 ( V_128 -> V_131 ) ;
if ( V_94 > sizeof( V_130 ) )
return - V_132 ;
V_82 = F_64 ( V_2 , V_128 -> V_131 , & V_130 ) ;
if ( V_82 == - V_132 ) {
V_82 = 0 ;
switch ( V_128 -> V_131 ) {
case V_133 :
V_130 = F_65 ( V_128 -> V_131 , V_2 -> V_5 . V_6 -> V_134 ) ;
break;
case V_135 :
V_130 = F_65 ( V_128 -> V_131 , V_2 -> V_5 . V_6 -> V_136 ) ;
break;
case V_137 ... V_138 :
V_108 = V_128 -> V_131 - V_137 ;
V_130 = F_65 ( V_128 -> V_131 , V_2 -> V_5 . V_139 [ V_108 ] ) ;
break;
case V_140 :
V_130 = F_65 ( V_128 -> V_131 , V_2 -> V_5 . V_141 ) ;
break;
#ifdef F_66
case V_142 ... V_143 :
if ( ! F_67 ( V_144 ) ) {
V_82 = - V_145 ;
break;
}
V_130 . V_146 = V_2 -> V_5 . V_147 [ V_128 -> V_131 - V_142 ] ;
break;
case V_148 :
if ( ! F_67 ( V_144 ) ) {
V_82 = - V_145 ;
break;
}
V_130 = F_65 ( V_128 -> V_131 , V_2 -> V_5 . V_149 . V_150 [ 3 ] ) ;
break;
#endif
default:
V_82 = - V_132 ;
break;
}
}
if ( V_82 )
return V_82 ;
if ( F_68 ( ( char V_105 * ) ( unsigned long ) V_128 -> V_151 , & V_130 , V_94 ) )
V_82 = - V_152 ;
return V_82 ;
}
int F_69 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
int V_82 ;
union V_129 V_130 ;
int V_94 ;
long int V_108 ;
V_94 = F_63 ( V_128 -> V_131 ) ;
if ( V_94 > sizeof( V_130 ) )
return - V_132 ;
if ( F_42 ( & V_130 , ( char V_105 * ) ( unsigned long ) V_128 -> V_151 , V_94 ) )
return - V_152 ;
V_82 = F_70 ( V_2 , V_128 -> V_131 , & V_130 ) ;
if ( V_82 == - V_132 ) {
V_82 = 0 ;
switch ( V_128 -> V_131 ) {
case V_133 :
V_2 -> V_5 . V_6 -> V_134 = F_71 ( V_128 -> V_131 , V_130 ) ;
break;
case V_135 :
V_2 -> V_5 . V_6 -> V_136 = F_71 ( V_128 -> V_131 , V_130 ) ;
break;
case V_137 ... V_138 :
V_108 = V_128 -> V_131 - V_137 ;
V_2 -> V_5 . V_139 [ V_108 ] = F_71 ( V_128 -> V_131 , V_130 ) ;
break;
case V_140 :
V_2 -> V_5 . V_141 = F_71 ( V_128 -> V_131 , V_130 ) ;
break;
#ifdef F_66
case V_142 ... V_143 :
if ( ! F_67 ( V_144 ) ) {
V_82 = - V_145 ;
break;
}
V_2 -> V_5 . V_147 [ V_128 -> V_131 - V_142 ] = V_130 . V_146 ;
break;
case V_148 :
if ( ! F_67 ( V_144 ) ) {
V_82 = - V_145 ;
break;
}
V_2 -> V_5 . V_149 . V_150 [ 3 ] = F_71 ( V_128 -> V_131 , V_130 ) ;
break;
#endif
default:
V_82 = - V_132 ;
break;
}
}
return V_82 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
return 0 ;
}
void F_73 ( unsigned long V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
F_16 ( V_2 ) ;
F_74 ( V_2 ) ;
}
