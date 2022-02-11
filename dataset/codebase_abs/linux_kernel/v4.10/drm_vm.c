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
V_5 = F_8 ( V_5 ) ;
#endif
return V_5 ;
}
static int F_9 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
struct V_23 * V_24 = V_4 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
struct V_1 * V_2 = NULL ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
if ( ! V_28 -> V_34 )
goto V_35;
if ( ! V_28 -> V_34 || ! V_28 -> V_34 -> V_36 )
goto V_35;
if ( F_10 ( & V_28 -> V_37 , V_4 -> V_38 , & V_33 ) )
goto V_35;
V_31 = F_11 ( V_33 , struct V_30 , V_33 ) ;
V_2 = V_31 -> V_2 ;
if ( V_2 && V_2 -> type == V_39 ) {
T_3 V_40 = V_22 -> V_41 - V_4 -> V_14 ;
T_3 V_42 = V_2 -> V_40 + V_40 ;
struct V_43 * V_44 ;
struct V_45 * V_45 ;
#ifdef F_12
V_42 -= V_28 -> V_46 -> V_47 -> V_48 ;
#endif
F_13 (agpmem, &dev->agp->memory, head) {
if ( V_44 -> V_49 <= V_42 &&
V_44 -> V_49 + V_44 -> V_50 * V_51 > V_42 )
break;
}
if ( & V_44 -> V_52 == & V_28 -> V_34 -> V_53 )
goto V_35;
V_40 = ( V_42 - V_44 -> V_49 ) >> V_54 ;
V_45 = V_44 -> V_53 -> V_50 [ V_40 ] ;
F_14 ( V_45 ) ;
V_22 -> V_45 = V_45 ;
F_15
( L_1 ,
( unsigned long long ) V_42 ,
V_44 -> V_53 -> V_50 [ V_40 ] ,
( unsigned long long ) V_40 ,
F_16 ( V_45 ) ) ;
return 0 ;
}
V_35:
return V_55 ;
}
static int F_9 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
return V_55 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
struct V_1 * V_2 = V_4 -> V_56 ;
unsigned long V_40 ;
unsigned long V_57 ;
struct V_45 * V_45 ;
if ( ! V_2 )
return V_55 ;
V_40 = V_22 -> V_41 - V_4 -> V_14 ;
V_57 = ( unsigned long ) V_2 -> V_58 + V_40 ;
V_45 = F_18 ( ( void * ) V_57 ) ;
if ( ! V_45 )
return V_55 ;
F_14 ( V_45 ) ;
V_22 -> V_45 = V_45 ;
F_15 ( L_2 , V_40 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
struct V_59 * V_60 , * V_61 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
int V_62 = 0 ;
F_15 ( L_3 ,
V_4 -> V_14 , V_4 -> V_15 - V_4 -> V_14 ) ;
V_2 = V_4 -> V_56 ;
F_20 ( & V_28 -> V_63 ) ;
F_21 (pt, temp, &dev->vmalist, head) {
if ( V_60 -> V_4 -> V_56 == V_2 )
V_62 ++ ;
if ( V_60 -> V_4 == V_4 ) {
F_22 ( & V_60 -> V_52 ) ;
F_23 ( V_60 ) ;
}
}
if ( V_62 == 1 && V_2 -> V_11 & V_64 ) {
V_62 = 0 ;
F_13 (r_list, &dev->maplist, head) {
if ( V_31 -> V_2 == V_2 )
V_62 ++ ;
}
if ( ! V_62 ) {
T_4 V_65 ;
switch ( V_2 -> type ) {
case V_10 :
case V_66 :
F_24 ( V_2 -> V_67 ) ;
F_25 ( V_2 -> V_58 ) ;
break;
case V_68 :
F_26 ( V_2 -> V_58 ) ;
break;
case V_39 :
case V_69 :
break;
case V_70 :
V_65 . V_71 = V_2 -> V_58 ;
V_65 . V_72 = V_2 -> V_40 ;
V_65 . V_73 = V_2 -> V_73 ;
F_27 ( V_28 , & V_65 ) ;
break;
}
F_23 ( V_2 ) ;
}
}
F_28 ( & V_28 -> V_63 ) ;
}
static int F_29 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
struct V_23 * V_24 = V_4 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
struct V_74 * V_75 = V_28 -> V_75 ;
unsigned long V_40 ;
unsigned long V_76 ;
struct V_45 * V_45 ;
if ( ! V_75 )
return V_55 ;
if ( ! V_75 -> V_77 )
return V_55 ;
V_40 = V_22 -> V_41 - V_4 -> V_14 ;
V_76 = V_40 >> V_54 ;
V_45 = F_30 ( ( void * ) V_75 -> V_77 [ V_76 ] ) ;
F_14 ( V_45 ) ;
V_22 -> V_45 = V_45 ;
F_15 ( L_4 , V_40 , V_76 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
struct V_1 * V_2 = V_4 -> V_56 ;
struct V_23 * V_24 = V_4 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
struct V_78 * V_79 = V_28 -> V_80 ;
unsigned long V_40 ;
unsigned long V_81 ;
unsigned long V_82 ;
struct V_45 * V_45 ;
if ( ! V_79 )
return V_55 ;
if ( ! V_79 -> V_77 )
return V_55 ;
V_40 = V_22 -> V_41 - V_4 -> V_14 ;
V_81 = V_2 -> V_40 - ( unsigned long ) V_28 -> V_80 -> V_83 ;
V_82 = ( V_40 >> V_54 ) + ( V_81 >> V_54 ) ;
V_45 = V_79 -> V_77 [ V_82 ] ;
F_14 ( V_45 ) ;
V_22 -> V_45 = V_45 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
return F_9 ( V_4 , V_22 ) ;
}
static int F_33 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
return F_17 ( V_4 , V_22 ) ;
}
static int F_34 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
return F_29 ( V_4 , V_22 ) ;
}
static int F_35 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
return F_31 ( V_4 , V_22 ) ;
}
static void F_36 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
struct V_59 * V_84 ;
F_15 ( L_3 ,
V_4 -> V_14 , V_4 -> V_15 - V_4 -> V_14 ) ;
V_84 = F_37 ( sizeof( * V_84 ) , V_85 ) ;
if ( V_84 ) {
V_84 -> V_4 = V_4 ;
V_84 -> V_86 = V_87 -> V_86 ;
F_38 ( & V_84 -> V_52 , & V_28 -> V_88 ) ;
}
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
F_20 ( & V_28 -> V_63 ) ;
F_36 ( V_28 , V_4 ) ;
F_28 ( & V_28 -> V_63 ) ;
}
static void F_40 ( struct V_27 * V_28 ,
struct V_3 * V_4 )
{
struct V_59 * V_60 , * V_61 ;
F_15 ( L_3 ,
V_4 -> V_14 , V_4 -> V_15 - V_4 -> V_14 ) ;
F_21 (pt, temp, &dev->vmalist, head) {
if ( V_60 -> V_4 == V_4 ) {
F_22 ( & V_60 -> V_52 ) ;
F_23 ( V_60 ) ;
break;
}
}
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
F_20 ( & V_28 -> V_63 ) ;
F_40 ( V_28 , V_4 ) ;
F_28 ( & V_28 -> V_63 ) ;
}
static int F_42 ( struct V_89 * V_90 , struct V_3 * V_4 )
{
struct V_23 * V_24 = V_90 -> V_26 ;
struct V_27 * V_28 ;
struct V_74 * V_75 ;
unsigned long V_91 = V_4 -> V_15 - V_4 -> V_14 ;
V_28 = V_24 -> V_29 -> V_28 ;
V_75 = V_28 -> V_75 ;
F_15 ( L_5 ,
V_4 -> V_14 , V_4 -> V_15 , V_4 -> V_38 ) ;
if ( ! V_75 || ( V_91 >> V_54 ) != V_75 -> F_16 ) {
return - V_92 ;
}
if ( ! F_43 ( V_93 ) &&
( V_75 -> V_11 & V_94 ) ) {
V_4 -> V_6 &= ~ ( V_95 | V_96 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_44 ( V_4 -> V_97 ) &= ~ V_98 ;
#else
V_4 -> V_97 =
F_45 ( F_46
( F_47
( F_48 ( F_44 ( V_4 -> V_97 ) ) ) ) ) ;
#endif
}
V_4 -> V_99 = & V_100 ;
V_4 -> V_6 |= V_101 | V_102 ;
F_36 ( V_28 , V_4 ) ;
return 0 ;
}
static T_3 F_49 ( struct V_27 * V_28 )
{
#ifdef F_12
return V_28 -> V_46 -> V_103 ;
#else
return 0 ;
#endif
}
static int F_50 ( struct V_89 * V_90 , struct V_3 * V_4 )
{
struct V_23 * V_24 = V_90 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
struct V_1 * V_2 = NULL ;
T_3 V_40 = 0 ;
struct V_32 * V_33 ;
F_15 ( L_5 ,
V_4 -> V_14 , V_4 -> V_15 , V_4 -> V_38 ) ;
if ( ! V_24 -> V_104 )
return - V_105 ;
if ( ! V_4 -> V_38
#if F_51 ( V_106 )
&& ( ! V_28 -> V_34
|| V_28 -> V_34 -> V_107 . V_108 -> V_109 != V_110 )
#endif
)
return F_42 ( V_90 , V_4 ) ;
if ( F_10 ( & V_28 -> V_37 , V_4 -> V_38 , & V_33 ) ) {
F_52 ( L_6 ) ;
return - V_92 ;
}
V_2 = F_11 ( V_33 , struct V_30 , V_33 ) -> V_2 ;
if ( ! V_2 || ( ( V_2 -> V_11 & V_111 ) && ! F_43 ( V_93 ) ) )
return - V_112 ;
if ( V_2 -> V_73 < V_4 -> V_15 - V_4 -> V_14 )
return - V_92 ;
if ( ! F_43 ( V_93 ) && ( V_2 -> V_11 & V_113 ) ) {
V_4 -> V_6 &= ~ ( V_95 | V_96 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_44 ( V_4 -> V_97 ) &= ~ V_98 ;
#else
V_4 -> V_97 =
F_45 ( F_46
( F_47
( F_48 ( F_44 ( V_4 -> V_97 ) ) ) ) ) ;
#endif
}
switch ( V_2 -> type ) {
#if ! F_3 ( V_17 )
case V_39 :
if ( V_28 -> V_34 && V_28 -> V_34 -> V_36 ) {
#if F_3 ( V_9 )
V_4 -> V_97 = F_4 ( V_4 -> V_97 ) ;
#endif
V_4 -> V_99 = & V_114 ;
break;
}
#endif
case V_66 :
case V_10 :
V_40 = F_49 ( V_28 ) ;
V_4 -> V_97 = F_1 ( V_2 , V_4 ) ;
if ( F_53 ( V_4 , V_4 -> V_14 ,
( V_2 -> V_40 + V_40 ) >> V_54 ,
V_4 -> V_15 - V_4 -> V_14 ,
V_4 -> V_97 ) )
return - V_115 ;
F_15 ( L_7
L_8 ,
V_2 -> type ,
V_4 -> V_14 , V_4 -> V_15 , ( unsigned long long ) ( V_2 -> V_40 + V_40 ) ) ;
V_4 -> V_99 = & V_114 ;
break;
case V_70 :
if ( F_54 ( V_4 , V_4 -> V_14 ,
F_55 ( F_30 ( V_2 -> V_58 ) ) ,
V_4 -> V_15 - V_4 -> V_14 , V_4 -> V_97 ) )
return - V_115 ;
V_4 -> V_97 = F_7 ( V_2 -> type , V_4 ) ;
case V_68 :
V_4 -> V_99 = & V_116 ;
V_4 -> V_56 = ( void * ) V_2 ;
break;
case V_69 :
V_4 -> V_99 = & V_117 ;
V_4 -> V_56 = ( void * ) V_2 ;
V_4 -> V_97 = F_7 ( V_2 -> type , V_4 ) ;
break;
default:
return - V_92 ;
}
V_4 -> V_6 |= V_101 | V_102 ;
F_36 ( V_28 , V_4 ) ;
return 0 ;
}
int F_56 ( struct V_89 * V_90 , struct V_3 * V_4 )
{
struct V_23 * V_24 = V_90 -> V_26 ;
struct V_27 * V_28 = V_24 -> V_29 -> V_28 ;
int V_118 ;
if ( F_57 ( V_28 ) )
return - V_119 ;
F_20 ( & V_28 -> V_63 ) ;
V_118 = F_50 ( V_90 , V_4 ) ;
F_28 ( & V_28 -> V_63 ) ;
return V_118 ;
}
void F_58 ( struct V_27 * V_28 )
{
struct V_59 * V_4 , * V_120 ;
F_21 (vma, vma_temp, &dev->vmalist, head) {
F_22 ( & V_4 -> V_52 ) ;
F_23 ( V_4 ) ;
}
}
