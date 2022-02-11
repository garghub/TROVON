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
void F_25 ( struct V_1 * V_2 )
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
}
T_3 F_28 ( struct V_1 * V_2 , T_4 V_64 )
{
T_2 V_65 = V_2 -> V_5 . V_66 ;
if ( F_29 ( V_65 ) &&
F_29 ( ( ( V_64 << V_67 ) & V_68 ) ==
( ( V_65 & V_69 ) & V_68 ) ) ) {
T_2 V_70 = ( ( T_2 ) V_2 -> V_5 . V_6 ) & V_69 ;
T_3 V_71 ;
V_71 = ( T_3 ) F_30 ( ( void * ) V_70 ) >> V_67 ;
F_31 ( F_32 ( V_71 ) ) ;
return V_71 ;
}
return F_33 ( V_2 -> V_72 , V_64 ) ;
}
static int F_34 ( struct V_1 * V_2 , T_2 V_73 , bool V_74 ,
struct V_75 * V_76 )
{
int V_77 = ( V_2 -> V_5 . V_6 -> V_9 & ( V_74 ? V_78 : V_79 ) ) ;
int V_80 ;
if ( V_77 ) {
V_80 = V_2 -> V_5 . V_10 . V_81 ( V_2 , V_73 , V_76 , V_74 ) ;
} else {
V_76 -> V_73 = V_73 ;
V_76 -> V_82 = V_73 & V_68 ;
V_76 -> V_83 = V_84 | V_73 >> 12 ;
V_76 -> V_85 = true ;
V_76 -> V_86 = true ;
V_76 -> V_87 = true ;
V_80 = 0 ;
}
return V_80 ;
}
static T_5 F_35 ( void )
{
return V_88 ;
}
static T_5 F_36 ( struct V_1 * V_2 , struct V_75 * V_76 ,
bool V_89 )
{
T_5 V_90 ;
if ( V_89 && ! V_76 -> V_85 )
goto V_91;
if ( ! V_89 && ! V_76 -> V_86 )
goto V_91;
V_90 = F_37 ( V_2 -> V_72 , V_76 -> V_82 >> V_67 ) ;
if ( F_38 ( V_90 ) )
goto V_91;
return V_90 | ( V_76 -> V_82 & ~ V_69 ) ;
V_91:
return F_35 () ;
}
int F_39 ( struct V_1 * V_2 , T_2 * V_73 , int V_92 , void * V_93 ,
bool V_74 )
{
struct V_75 V_76 ;
V_2 -> V_32 . V_94 ++ ;
if ( F_34 ( V_2 , * V_73 , V_74 , & V_76 ) )
return - V_95 ;
* V_73 = V_76 . V_82 ;
if ( ! V_76 . V_86 )
return - V_96 ;
if ( F_40 ( V_2 -> V_72 , V_76 . V_82 , V_93 , V_92 ) )
return V_97 ;
return V_98 ;
}
int F_41 ( struct V_1 * V_2 , T_2 * V_73 , int V_92 , void * V_93 ,
bool V_74 )
{
struct V_75 V_76 ;
T_5 V_99 = * V_73 ;
V_2 -> V_32 . V_100 ++ ;
if ( F_34 ( V_2 , * V_73 , V_74 , & V_76 ) )
goto V_101;
* V_73 = V_76 . V_82 ;
V_99 = F_36 ( V_2 , & V_76 , true ) ;
if ( F_38 ( V_99 ) )
goto V_102;
if ( F_42 ( V_93 , ( void V_103 * ) V_99 , V_92 ) ) {
F_14 ( V_34 L_4 , V_99 ) ;
goto V_102;
}
return V_98 ;
V_101:
return - V_95 ;
V_102:
return V_97 ;
}
int F_43 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_44 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
int V_106 ;
V_105 -> V_107 = F_4 ( V_2 ) ;
V_105 -> V_108 = F_45 ( V_2 ) ;
V_105 -> V_109 = F_46 ( V_2 ) ;
V_105 -> V_110 = F_47 ( V_2 ) ;
V_105 -> V_111 = F_48 ( V_2 ) ;
V_105 -> V_9 = V_2 -> V_5 . V_6 -> V_9 ;
V_105 -> V_7 = V_2 -> V_5 . V_6 -> V_7 ;
V_105 -> V_8 = V_2 -> V_5 . V_6 -> V_8 ;
V_105 -> V_112 = V_2 -> V_5 . V_112 ;
V_105 -> V_113 = V_2 -> V_5 . V_6 -> V_113 ;
V_105 -> V_114 = V_2 -> V_5 . V_6 -> V_114 ;
V_105 -> V_115 = V_2 -> V_5 . V_6 -> V_115 ;
V_105 -> V_116 = V_2 -> V_5 . V_6 -> V_116 ;
V_105 -> V_117 = V_2 -> V_5 . V_117 ;
V_105 -> V_118 = V_2 -> V_5 . V_118 ;
V_105 -> V_119 = V_2 -> V_5 . V_119 ;
V_105 -> V_120 = V_2 -> V_5 . V_120 ;
for ( V_106 = 0 ; V_106 < F_49 ( V_105 -> V_121 ) ; V_106 ++ )
V_105 -> V_121 [ V_106 ] = F_50 ( V_2 , V_106 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
int V_106 ;
F_5 ( V_2 , V_105 -> V_107 ) ;
F_52 ( V_2 , V_105 -> V_108 ) ;
F_53 ( V_2 , V_105 -> V_109 ) ;
F_54 ( V_2 , V_105 -> V_110 ) ;
F_55 ( V_2 , V_105 -> V_111 ) ;
F_56 ( V_2 , V_105 -> V_9 ) ;
V_2 -> V_5 . V_6 -> V_7 = V_105 -> V_7 ;
V_2 -> V_5 . V_6 -> V_8 = V_105 -> V_8 ;
V_2 -> V_5 . V_6 -> V_113 = V_105 -> V_113 ;
V_2 -> V_5 . V_6 -> V_114 = V_105 -> V_114 ;
V_2 -> V_5 . V_6 -> V_115 = V_105 -> V_115 ;
V_2 -> V_5 . V_6 -> V_116 = V_105 -> V_116 ;
V_2 -> V_5 . V_117 = V_105 -> V_117 ;
V_2 -> V_5 . V_118 = V_105 -> V_118 ;
V_2 -> V_5 . V_119 = V_105 -> V_119 ;
V_2 -> V_5 . V_120 = V_105 -> V_120 ;
for ( V_106 = 0 ; V_106 < F_49 ( V_105 -> V_121 ) ; V_106 ++ )
F_57 ( V_2 , V_106 , V_105 -> V_121 [ V_106 ] ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
return - V_124 ;
}
int F_59 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
return - V_124 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
return 0 ;
}
int F_61 ( struct V_72 * V_72 ,
struct V_127 * log )
{
struct V_128 * V_129 ;
struct V_1 * V_2 ;
T_2 V_130 , V_131 ;
int V_132 = 0 ;
int V_80 ;
unsigned long V_133 ;
F_62 ( & V_72 -> V_134 ) ;
V_80 = F_63 ( V_72 , log , & V_132 ) ;
if ( V_80 )
goto V_135;
if ( V_132 ) {
V_129 = F_64 ( V_72 -> V_136 , log -> V_137 ) ;
V_130 = V_129 -> V_138 << V_67 ;
V_131 = V_130 + ( V_129 -> V_139 << V_67 ) ;
F_65 (n, vcpu, kvm)
F_66 ( V_2 , V_130 , V_131 ) ;
V_133 = F_67 ( V_129 ) ;
memset ( V_129 -> V_140 , 0 , V_133 ) ;
}
V_80 = 0 ;
V_135:
F_68 ( & V_72 -> V_134 ) ;
return V_80 ;
}
