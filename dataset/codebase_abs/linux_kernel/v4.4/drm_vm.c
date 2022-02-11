static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_4 -> V_6 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 ) || F_3 ( V_9 )
if ( V_2 -> type == V_10 && ! ( V_2 -> V_11 & V_12 ) )
V_5 = F_4 ( V_5 ) ;
else
V_5 = F_5 ( V_5 ) ;
#elif F_3 ( V_13 )
if ( F_6 ( V_4 -> V_14 , V_4 -> V_15 -
V_4 -> V_14 ) )
V_5 = F_5 ( V_5 ) ;
else
V_5 = F_4 ( V_5 ) ;
#elif F_3 ( V_16 ) || F_3 ( V_17 ) || F_3 ( V_18 )
V_5 = F_4 ( V_5 ) ;
#endif
return V_5 ;
}
static T_1 F_7 ( T_2 V_19 , struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_4 -> V_6 ) ;
#if F_3 ( V_9 ) && F_3 ( V_20 )
V_5 |= V_21 ;
#endif
return V_5 ;
}
static int F_8 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
struct V_24 * V_25 = V_4 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
struct V_1 * V_2 = NULL ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
if ( ! V_29 -> V_35 )
goto V_36;
if ( ! V_29 -> V_35 || ! V_29 -> V_35 -> V_37 )
goto V_36;
if ( F_9 ( & V_29 -> V_38 , V_4 -> V_39 , & V_34 ) )
goto V_36;
V_32 = F_10 ( V_34 , struct V_31 , V_34 ) ;
V_2 = V_32 -> V_2 ;
if ( V_2 && V_2 -> type == V_40 ) {
T_3 V_41 = ( unsigned long ) V_23 -> V_42 -
V_4 -> V_14 ;
T_3 V_43 = V_2 -> V_41 + V_41 ;
struct V_44 * V_45 ;
struct V_46 * V_46 ;
#ifdef F_11
V_43 -= V_29 -> V_47 -> V_48 -> V_49 ;
#endif
F_12 (agpmem, &dev->agp->memory, head) {
if ( V_45 -> V_50 <= V_43 &&
V_45 -> V_50 + V_45 -> V_51 * V_52 > V_43 )
break;
}
if ( & V_45 -> V_53 == & V_29 -> V_35 -> V_54 )
goto V_36;
V_41 = ( V_43 - V_45 -> V_50 ) >> V_55 ;
V_46 = V_45 -> V_54 -> V_51 [ V_41 ] ;
F_13 ( V_46 ) ;
V_23 -> V_46 = V_46 ;
F_14
( L_1 ,
( unsigned long long ) V_43 ,
V_45 -> V_54 -> V_51 [ V_41 ] ,
( unsigned long long ) V_41 ,
F_15 ( V_46 ) ) ;
return 0 ;
}
V_36:
return V_56 ;
}
static int F_8 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
return V_56 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_4 -> V_57 ;
unsigned long V_41 ;
unsigned long V_58 ;
struct V_46 * V_46 ;
if ( ! V_2 )
return V_56 ;
V_41 = ( unsigned long ) V_23 -> V_42 - V_4 -> V_14 ;
V_58 = ( unsigned long ) V_2 -> V_59 + V_41 ;
V_46 = F_17 ( ( void * ) V_58 ) ;
if ( ! V_46 )
return V_56 ;
F_13 ( V_46 ) ;
V_23 -> V_46 = V_46 ;
F_14 ( L_2 , V_41 ) ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
struct V_60 * V_61 , * V_62 ;
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_63 = 0 ;
F_14 ( L_3 ,
V_4 -> V_14 , V_4 -> V_15 - V_4 -> V_14 ) ;
V_2 = V_4 -> V_57 ;
F_19 ( & V_29 -> V_64 ) ;
F_20 (pt, temp, &dev->vmalist, head) {
if ( V_61 -> V_4 -> V_57 == V_2 )
V_63 ++ ;
if ( V_61 -> V_4 == V_4 ) {
F_21 ( & V_61 -> V_53 ) ;
F_22 ( V_61 ) ;
}
}
if ( V_63 == 1 && V_2 -> V_11 & V_65 ) {
V_63 = 0 ;
F_12 (r_list, &dev->maplist, head) {
if ( V_32 -> V_2 == V_2 )
V_63 ++ ;
}
if ( ! V_63 ) {
T_4 V_66 ;
switch ( V_2 -> type ) {
case V_10 :
case V_67 :
F_23 ( V_2 -> V_68 ) ;
F_24 ( V_2 -> V_59 ) ;
break;
case V_69 :
F_25 ( V_2 -> V_59 ) ;
break;
case V_40 :
case V_70 :
break;
case V_71 :
V_66 . V_72 = V_2 -> V_59 ;
V_66 . V_73 = V_2 -> V_41 ;
V_66 . V_74 = V_2 -> V_74 ;
F_26 ( V_29 , & V_66 ) ;
break;
}
F_22 ( V_2 ) ;
}
}
F_27 ( & V_29 -> V_64 ) ;
}
static int F_28 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
struct V_24 * V_25 = V_4 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
struct V_75 * V_76 = V_29 -> V_76 ;
unsigned long V_41 ;
unsigned long V_77 ;
struct V_46 * V_46 ;
if ( ! V_76 )
return V_56 ;
if ( ! V_76 -> V_78 )
return V_56 ;
V_41 = ( unsigned long ) V_23 -> V_42 - V_4 -> V_14 ;
V_77 = V_41 >> V_55 ;
V_46 = F_29 ( ( void * ) V_76 -> V_78 [ V_77 ] ) ;
F_13 ( V_46 ) ;
V_23 -> V_46 = V_46 ;
F_14 ( L_4 , V_41 , V_77 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
struct V_1 * V_2 = V_4 -> V_57 ;
struct V_24 * V_25 = V_4 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
struct V_79 * V_80 = V_29 -> V_81 ;
unsigned long V_41 ;
unsigned long V_82 ;
unsigned long V_83 ;
struct V_46 * V_46 ;
if ( ! V_80 )
return V_56 ;
if ( ! V_80 -> V_78 )
return V_56 ;
V_41 = ( unsigned long ) V_23 -> V_42 - V_4 -> V_14 ;
V_82 = V_2 -> V_41 - ( unsigned long ) V_29 -> V_81 -> V_84 ;
V_83 = ( V_41 >> V_55 ) + ( V_82 >> V_55 ) ;
V_46 = V_80 -> V_78 [ V_83 ] ;
F_13 ( V_46 ) ;
V_23 -> V_46 = V_46 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
return F_8 ( V_4 , V_23 ) ;
}
static int F_32 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
return F_16 ( V_4 , V_23 ) ;
}
static int F_33 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
return F_28 ( V_4 , V_23 ) ;
}
static int F_34 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
return F_30 ( V_4 , V_23 ) ;
}
void F_35 ( struct V_28 * V_29 ,
struct V_3 * V_4 )
{
struct V_60 * V_85 ;
F_14 ( L_3 ,
V_4 -> V_14 , V_4 -> V_15 - V_4 -> V_14 ) ;
V_85 = F_36 ( sizeof( * V_85 ) , V_86 ) ;
if ( V_85 ) {
V_85 -> V_4 = V_4 ;
V_85 -> V_87 = V_88 -> V_87 ;
F_37 ( & V_85 -> V_53 , & V_29 -> V_89 ) ;
}
}
static void F_38 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
F_19 ( & V_29 -> V_64 ) ;
F_35 ( V_29 , V_4 ) ;
F_27 ( & V_29 -> V_64 ) ;
}
void F_39 ( struct V_28 * V_29 ,
struct V_3 * V_4 )
{
struct V_60 * V_61 , * V_62 ;
F_14 ( L_3 ,
V_4 -> V_14 , V_4 -> V_15 - V_4 -> V_14 ) ;
F_20 (pt, temp, &dev->vmalist, head) {
if ( V_61 -> V_4 == V_4 ) {
F_21 ( & V_61 -> V_53 ) ;
F_22 ( V_61 ) ;
break;
}
}
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_24 * V_25 = V_4 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
F_19 ( & V_29 -> V_64 ) ;
F_39 ( V_29 , V_4 ) ;
F_27 ( & V_29 -> V_64 ) ;
}
static int F_41 ( struct V_90 * V_91 , struct V_3 * V_4 )
{
struct V_24 * V_25 = V_91 -> V_27 ;
struct V_28 * V_29 ;
struct V_75 * V_76 ;
unsigned long V_92 = V_4 -> V_15 - V_4 -> V_14 ;
V_29 = V_25 -> V_30 -> V_29 ;
V_76 = V_29 -> V_76 ;
F_14 ( L_5 ,
V_4 -> V_14 , V_4 -> V_15 , V_4 -> V_39 ) ;
if ( ! V_76 || ( V_92 >> V_55 ) != V_76 -> F_15 ) {
return - V_93 ;
}
if ( ! F_42 ( V_94 ) &&
( V_76 -> V_11 & V_95 ) ) {
V_4 -> V_6 &= ~ ( V_96 | V_97 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_43 ( V_4 -> V_98 ) &= ~ V_99 ;
#else
V_4 -> V_98 =
F_44 ( F_45
( F_46
( F_47 ( F_43 ( V_4 -> V_98 ) ) ) ) ) ;
#endif
}
V_4 -> V_100 = & V_101 ;
V_4 -> V_6 |= V_102 | V_103 ;
F_35 ( V_29 , V_4 ) ;
return 0 ;
}
static T_3 F_48 ( struct V_28 * V_29 )
{
#ifdef F_11
return V_29 -> V_47 -> V_104 ;
#else
return 0 ;
#endif
}
static int F_49 ( struct V_90 * V_91 , struct V_3 * V_4 )
{
struct V_24 * V_25 = V_91 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
struct V_1 * V_2 = NULL ;
T_3 V_41 = 0 ;
struct V_33 * V_34 ;
F_14 ( L_5 ,
V_4 -> V_14 , V_4 -> V_15 , V_4 -> V_39 ) ;
if ( ! V_25 -> V_105 )
return - V_106 ;
if ( ! V_4 -> V_39
#if F_50 ( V_107 )
&& ( ! V_29 -> V_35
|| V_29 -> V_35 -> V_108 . V_109 -> V_110 != V_111 )
#endif
)
return F_41 ( V_91 , V_4 ) ;
if ( F_9 ( & V_29 -> V_38 , V_4 -> V_39 , & V_34 ) ) {
F_51 ( L_6 ) ;
return - V_93 ;
}
V_2 = F_10 ( V_34 , struct V_31 , V_34 ) -> V_2 ;
if ( ! V_2 || ( ( V_2 -> V_11 & V_112 ) && ! F_42 ( V_94 ) ) )
return - V_113 ;
if ( V_2 -> V_74 < V_4 -> V_15 - V_4 -> V_14 )
return - V_93 ;
if ( ! F_42 ( V_94 ) && ( V_2 -> V_11 & V_114 ) ) {
V_4 -> V_6 &= ~ ( V_96 | V_97 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_43 ( V_4 -> V_98 ) &= ~ V_99 ;
#else
V_4 -> V_98 =
F_44 ( F_45
( F_46
( F_47 ( F_43 ( V_4 -> V_98 ) ) ) ) ) ;
#endif
}
switch ( V_2 -> type ) {
#if ! F_3 ( V_17 )
case V_40 :
if ( V_29 -> V_35 && V_29 -> V_35 -> V_37 ) {
#if F_3 ( V_9 )
F_43 ( V_4 -> V_98 ) |= V_21 ;
#endif
V_4 -> V_100 = & V_115 ;
break;
}
#endif
case V_67 :
case V_10 :
V_41 = F_48 ( V_29 ) ;
V_4 -> V_98 = F_1 ( V_2 , V_4 ) ;
if ( F_52 ( V_4 , V_4 -> V_14 ,
( V_2 -> V_41 + V_41 ) >> V_55 ,
V_4 -> V_15 - V_4 -> V_14 ,
V_4 -> V_98 ) )
return - V_116 ;
F_14 ( L_7
L_8 ,
V_2 -> type ,
V_4 -> V_14 , V_4 -> V_15 , ( unsigned long long ) ( V_2 -> V_41 + V_41 ) ) ;
V_4 -> V_100 = & V_115 ;
break;
case V_71 :
if ( F_53 ( V_4 , V_4 -> V_14 ,
F_54 ( F_29 ( V_2 -> V_59 ) ) ,
V_4 -> V_15 - V_4 -> V_14 , V_4 -> V_98 ) )
return - V_116 ;
V_4 -> V_98 = F_7 ( V_2 -> type , V_4 ) ;
case V_69 :
V_4 -> V_100 = & V_117 ;
V_4 -> V_57 = ( void * ) V_2 ;
break;
case V_70 :
V_4 -> V_100 = & V_118 ;
V_4 -> V_57 = ( void * ) V_2 ;
V_4 -> V_98 = F_7 ( V_2 -> type , V_4 ) ;
break;
default:
return - V_93 ;
}
V_4 -> V_6 |= V_102 | V_103 ;
F_35 ( V_29 , V_4 ) ;
return 0 ;
}
int F_55 ( struct V_90 * V_91 , struct V_3 * V_4 )
{
struct V_24 * V_25 = V_91 -> V_27 ;
struct V_28 * V_29 = V_25 -> V_30 -> V_29 ;
int V_119 ;
if ( F_56 ( V_29 ) )
return - V_120 ;
F_19 ( & V_29 -> V_64 ) ;
V_119 = F_49 ( V_91 , V_4 ) ;
F_27 ( & V_29 -> V_64 ) ;
return V_119 ;
}
void F_57 ( struct V_28 * V_29 )
{
struct V_60 * V_4 , * V_121 ;
F_20 (vma, vma_temp, &dev->vmalist, head) {
F_21 ( & V_4 -> V_53 ) ;
F_22 ( V_4 ) ;
}
}
int F_58 ( struct V_122 * V_123 , void * V_124 )
{
struct V_125 * V_126 = (struct V_125 * ) V_123 -> V_127 ;
struct V_28 * V_29 = V_126 -> V_30 -> V_29 ;
struct V_60 * V_61 ;
struct V_3 * V_4 ;
unsigned long V_128 = 0 ;
#if F_3 ( V_7 )
unsigned int V_129 ;
#endif
F_19 ( & V_29 -> V_64 ) ;
F_12 (pt, &dev->vmalist, head)
V_128 ++ ;
F_59 ( V_123 , L_9 ,
V_128 , V_130 ,
( void * ) ( unsigned long ) F_60 ( V_130 ) ) ;
F_12 (pt, &dev->vmalist, head) {
V_4 = V_61 -> V_4 ;
if ( ! V_4 )
continue;
F_59 ( V_123 ,
L_10 ,
V_61 -> V_87 ,
( void * ) V_4 -> V_14 , ( void * ) V_4 -> V_15 ,
V_4 -> V_6 & V_131 ? 'r' : '-' ,
V_4 -> V_6 & V_96 ? 'w' : '-' ,
V_4 -> V_6 & V_132 ? 'x' : '-' ,
V_4 -> V_6 & V_133 ? 's' : 'p' ,
V_4 -> V_6 & V_134 ? 'l' : '-' ,
V_4 -> V_6 & V_135 ? 'i' : '-' ,
V_4 -> V_39 ) ;
#if F_3 ( V_7 )
V_129 = F_43 ( V_4 -> V_98 ) ;
F_59 ( V_123 , L_11 ,
V_129 & V_136 ? 'p' : '-' ,
V_129 & V_99 ? 'w' : 'r' ,
V_129 & V_137 ? 'u' : 's' ,
V_129 & V_138 ? 't' : 'b' ,
V_129 & V_139 ? 'u' : 'c' ,
V_129 & V_140 ? 'a' : '-' ,
V_129 & V_141 ? 'd' : '-' ,
V_129 & V_142 ? 'm' : 'k' ,
V_129 & V_143 ? 'g' : 'l' ) ;
#endif
F_59 ( V_123 , L_12 ) ;
}
F_27 ( & V_29 -> V_64 ) ;
return 0 ;
}
