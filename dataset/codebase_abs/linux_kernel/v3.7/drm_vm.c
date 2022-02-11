static T_1 F_1 ( T_2 V_1 , struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 -> V_5 ) ;
#if F_3 ( V_6 ) || F_3 ( V_7 )
if ( V_8 . V_9 > 3 && V_1 != V_10 ) {
F_4 ( V_4 ) |= V_11 ;
F_4 ( V_4 ) &= ~ V_12 ;
}
#elif F_3 ( V_13 )
F_4 ( V_4 ) |= V_14 ;
if ( V_1 == V_15 )
F_4 ( V_4 ) |= V_16 ;
#elif F_3 ( V_17 )
if ( F_5 ( V_3 -> V_18 , V_3 -> V_19 -
V_3 -> V_18 ) )
V_4 = F_6 ( V_4 ) ;
else
V_4 = F_7 ( V_4 ) ;
#elif F_3 ( V_20 ) || F_3 ( V_21 ) || F_3 ( V_22 )
V_4 = F_7 ( V_4 ) ;
#endif
return V_4 ;
}
static T_1 F_8 ( T_2 V_1 , struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 -> V_5 ) ;
#if F_3 ( V_13 ) && F_3 ( V_23 )
V_4 |= V_14 ;
#endif
return V_4 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_26 * V_27 = V_3 -> V_28 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
struct V_33 * V_34 = NULL ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
if ( ! F_10 ( V_31 ) )
goto V_39;
if ( ! V_31 -> V_40 || ! V_31 -> V_40 -> V_41 )
goto V_39;
if ( F_11 ( & V_31 -> V_42 , V_3 -> V_43 , & V_38 ) )
goto V_39;
V_36 = F_12 ( V_38 , struct V_35 , V_38 ) ;
V_34 = V_36 -> V_34 ;
if ( V_34 && V_34 -> type == V_10 ) {
T_3 V_44 = ( unsigned long ) V_25 -> V_45 -
V_3 -> V_18 ;
T_3 V_46 = V_34 -> V_44 + V_44 ;
struct V_47 * V_48 ;
struct V_49 * V_49 ;
#ifdef F_13
V_46 -= V_31 -> V_50 -> V_51 -> V_52 ;
#endif
F_14 (agpmem, &dev->agp->memory, head) {
if ( V_48 -> V_53 <= V_46 &&
V_48 -> V_53 + V_48 -> V_54 * V_55 > V_46 )
break;
}
if ( & V_48 -> V_56 == & V_31 -> V_40 -> V_57 )
goto V_39;
V_44 = ( V_46 - V_48 -> V_53 ) >> V_58 ;
V_49 = V_48 -> V_57 -> V_54 [ V_44 ] ;
F_15 ( V_49 ) ;
V_25 -> V_49 = V_49 ;
F_16
( L_1 ,
( unsigned long long ) V_46 ,
V_48 -> V_57 -> V_54 [ V_44 ] ,
( unsigned long long ) V_44 ,
F_17 ( V_49 ) ) ;
return 0 ;
}
V_39:
return V_59 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
return V_59 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_33 * V_34 = V_3 -> V_60 ;
unsigned long V_44 ;
unsigned long V_61 ;
struct V_49 * V_49 ;
if ( ! V_34 )
return V_59 ;
V_44 = ( unsigned long ) V_25 -> V_45 - V_3 -> V_18 ;
V_61 = ( unsigned long ) V_34 -> V_62 + V_44 ;
V_49 = F_19 ( ( void * ) V_61 ) ;
if ( ! V_49 )
return V_59 ;
F_15 ( V_49 ) ;
V_25 -> V_49 = V_49 ;
F_16 ( L_2 , V_44 ) ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = V_3 -> V_28 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
struct V_63 * V_64 , * V_65 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_66 = 0 ;
F_16 ( L_3 ,
V_3 -> V_18 , V_3 -> V_19 - V_3 -> V_18 ) ;
F_21 ( & V_31 -> V_67 ) ;
V_34 = V_3 -> V_60 ;
F_22 ( & V_31 -> V_68 ) ;
F_23 (pt, temp, &dev->vmalist, head) {
if ( V_64 -> V_3 -> V_60 == V_34 )
V_66 ++ ;
if ( V_64 -> V_3 == V_3 ) {
F_24 ( & V_64 -> V_56 ) ;
F_25 ( V_64 ) ;
}
}
if ( V_66 == 1 && V_34 -> V_69 & V_70 ) {
V_66 = 0 ;
F_14 (r_list, &dev->maplist, head) {
if ( V_36 -> V_34 == V_34 )
V_66 ++ ;
}
if ( ! V_66 ) {
T_4 V_71 ;
switch ( V_34 -> type ) {
case V_15 :
case V_72 :
if ( F_26 ( V_31 ) && V_34 -> V_73 >= 0 ) {
int V_74 ;
V_74 = F_27 ( V_34 -> V_73 ,
V_34 -> V_44 ,
V_34 -> V_75 ) ;
F_16 ( L_4 , V_74 ) ;
}
F_28 ( V_34 -> V_62 ) ;
break;
case V_76 :
F_29 ( V_34 -> V_62 ) ;
break;
case V_10 :
case V_77 :
break;
case V_78 :
V_71 . V_79 = V_34 -> V_62 ;
V_71 . V_80 = V_34 -> V_44 ;
V_71 . V_75 = V_34 -> V_75 ;
F_30 ( V_31 , & V_71 ) ;
break;
case V_81 :
F_31 ( L_5 ) ;
break;
}
F_25 ( V_34 ) ;
}
}
F_32 ( & V_31 -> V_68 ) ;
}
static int F_33 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_26 * V_27 = V_3 -> V_28 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
struct V_82 * V_83 = V_31 -> V_83 ;
unsigned long V_44 ;
unsigned long V_84 ;
struct V_49 * V_49 ;
if ( ! V_83 )
return V_59 ;
if ( ! V_83 -> V_85 )
return V_59 ;
V_44 = ( unsigned long ) V_25 -> V_45 - V_3 -> V_18 ;
V_84 = V_44 >> V_58 ;
V_49 = F_34 ( ( V_83 -> V_85 [ V_84 ] + ( V_44 & ( ~ V_86 ) ) ) ) ;
F_15 ( V_49 ) ;
V_25 -> V_49 = V_49 ;
F_16 ( L_6 , V_44 , V_84 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
struct V_33 * V_34 = V_3 -> V_60 ;
struct V_26 * V_27 = V_3 -> V_28 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
struct V_87 * V_88 = V_31 -> V_89 ;
unsigned long V_44 ;
unsigned long V_90 ;
unsigned long V_91 ;
struct V_49 * V_49 ;
if ( ! V_88 )
return V_59 ;
if ( ! V_88 -> V_85 )
return V_59 ;
V_44 = ( unsigned long ) V_25 -> V_45 - V_3 -> V_18 ;
V_90 = V_34 -> V_44 - ( unsigned long ) V_31 -> V_89 -> V_92 ;
V_91 = ( V_44 >> V_58 ) + ( V_90 >> V_58 ) ;
V_49 = V_88 -> V_85 [ V_91 ] ;
F_15 ( V_49 ) ;
V_25 -> V_49 = V_49 ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
return F_9 ( V_3 , V_25 ) ;
}
static int F_37 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
return F_18 ( V_3 , V_25 ) ;
}
static int F_38 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
return F_33 ( V_3 , V_25 ) ;
}
static int F_39 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
return F_35 ( V_3 , V_25 ) ;
}
void F_40 ( struct V_30 * V_31 ,
struct V_2 * V_3 )
{
struct V_63 * V_93 ;
F_16 ( L_3 ,
V_3 -> V_18 , V_3 -> V_19 - V_3 -> V_18 ) ;
F_41 ( & V_31 -> V_67 ) ;
V_93 = F_42 ( sizeof( * V_93 ) , V_94 ) ;
if ( V_93 ) {
V_93 -> V_3 = V_3 ;
V_93 -> V_95 = V_96 -> V_95 ;
F_43 ( & V_93 -> V_56 , & V_31 -> V_97 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = V_3 -> V_28 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
F_22 ( & V_31 -> V_68 ) ;
F_40 ( V_31 , V_3 ) ;
F_32 ( & V_31 -> V_68 ) ;
}
void F_45 ( struct V_30 * V_31 ,
struct V_2 * V_3 )
{
struct V_63 * V_64 , * V_65 ;
F_16 ( L_3 ,
V_3 -> V_18 , V_3 -> V_19 - V_3 -> V_18 ) ;
F_21 ( & V_31 -> V_67 ) ;
F_23 (pt, temp, &dev->vmalist, head) {
if ( V_64 -> V_3 == V_3 ) {
F_24 ( & V_64 -> V_56 ) ;
F_25 ( V_64 ) ;
break;
}
}
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_26 * V_27 = V_3 -> V_28 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
F_22 ( & V_31 -> V_68 ) ;
F_45 ( V_31 , V_3 ) ;
F_32 ( & V_31 -> V_68 ) ;
}
static int F_47 ( struct V_98 * V_99 , struct V_2 * V_3 )
{
struct V_26 * V_27 = V_99 -> V_29 ;
struct V_30 * V_31 ;
struct V_82 * V_83 ;
unsigned long V_100 = V_3 -> V_19 - V_3 -> V_18 ;
V_31 = V_27 -> V_32 -> V_31 ;
V_83 = V_31 -> V_83 ;
F_16 ( L_7 ,
V_3 -> V_18 , V_3 -> V_19 , V_3 -> V_43 ) ;
if ( ! V_83 || ( V_100 >> V_58 ) != V_83 -> F_17 ) {
return - V_101 ;
}
if ( ! F_48 ( V_102 ) &&
( V_83 -> V_69 & V_103 ) ) {
V_3 -> V_5 &= ~ ( V_104 | V_105 ) ;
#if F_3 ( V_6 ) || F_3 ( V_7 )
F_4 ( V_3 -> V_106 ) &= ~ V_107 ;
#else
V_3 -> V_106 =
F_49 ( F_50
( F_51
( F_52 ( F_4 ( V_3 -> V_106 ) ) ) ) ) ;
#endif
}
V_3 -> V_108 = & V_109 ;
V_3 -> V_5 |= V_110 | V_111 ;
F_40 ( V_31 , V_3 ) ;
return 0 ;
}
static T_3 F_53 ( struct V_30 * V_31 )
{
#ifdef F_13
return V_31 -> V_50 -> V_112 ;
#else
return 0 ;
#endif
}
int F_54 ( struct V_98 * V_99 , struct V_2 * V_3 )
{
struct V_26 * V_27 = V_99 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
struct V_33 * V_34 = NULL ;
T_3 V_44 = 0 ;
struct V_37 * V_38 ;
F_16 ( L_7 ,
V_3 -> V_18 , V_3 -> V_19 , V_3 -> V_43 ) ;
if ( ! V_27 -> V_113 )
return - V_114 ;
if ( ! V_3 -> V_43
#if V_115
&& ( ! V_31 -> V_40
|| V_31 -> V_40 -> V_116 . V_117 -> V_118 != V_119 )
#endif
)
return F_47 ( V_99 , V_3 ) ;
if ( F_11 ( & V_31 -> V_42 , V_3 -> V_43 , & V_38 ) ) {
F_31 ( L_8 ) ;
return - V_101 ;
}
V_34 = F_12 ( V_38 , struct V_35 , V_38 ) -> V_34 ;
if ( ! V_34 || ( ( V_34 -> V_69 & V_120 ) && ! F_48 ( V_102 ) ) )
return - V_121 ;
if ( V_34 -> V_75 < V_3 -> V_19 - V_3 -> V_18 )
return - V_101 ;
if ( ! F_48 ( V_102 ) && ( V_34 -> V_69 & V_122 ) ) {
V_3 -> V_5 &= ~ ( V_104 | V_105 ) ;
#if F_3 ( V_6 ) || F_3 ( V_7 )
F_4 ( V_3 -> V_106 ) &= ~ V_107 ;
#else
V_3 -> V_106 =
F_49 ( F_50
( F_51
( F_52 ( F_4 ( V_3 -> V_106 ) ) ) ) ) ;
#endif
}
switch ( V_34 -> type ) {
#if ! F_3 ( V_21 )
case V_10 :
if ( F_10 ( V_31 ) && V_31 -> V_40 -> V_41 ) {
#if F_3 ( V_13 )
F_4 ( V_3 -> V_106 ) |= V_14 ;
#endif
V_3 -> V_108 = & V_123 ;
break;
}
#endif
case V_72 :
case V_15 :
V_44 = F_53 ( V_31 ) ;
V_3 -> V_5 |= V_124 ;
V_3 -> V_106 = F_1 ( V_34 -> type , V_3 ) ;
if ( F_55 ( V_3 , V_3 -> V_18 ,
( V_34 -> V_44 + V_44 ) >> V_58 ,
V_3 -> V_19 - V_3 -> V_18 ,
V_3 -> V_106 ) )
return - V_125 ;
F_16 ( L_9
L_10 ,
V_34 -> type ,
V_3 -> V_18 , V_3 -> V_19 , ( unsigned long long ) ( V_34 -> V_44 + V_44 ) ) ;
V_3 -> V_108 = & V_123 ;
break;
case V_78 :
if ( F_56 ( V_3 , V_3 -> V_18 ,
F_57 ( F_34 ( V_34 -> V_62 ) ) ,
V_3 -> V_19 - V_3 -> V_18 , V_3 -> V_106 ) )
return - V_125 ;
V_3 -> V_106 = F_8 ( V_34 -> type , V_3 ) ;
case V_76 :
V_3 -> V_108 = & V_126 ;
V_3 -> V_60 = ( void * ) V_34 ;
break;
case V_77 :
V_3 -> V_108 = & V_127 ;
V_3 -> V_60 = ( void * ) V_34 ;
V_3 -> V_106 = F_8 ( V_34 -> type , V_3 ) ;
break;
default:
return - V_101 ;
}
V_3 -> V_5 |= V_110 | V_111 ;
F_40 ( V_31 , V_3 ) ;
return 0 ;
}
int F_58 ( struct V_98 * V_99 , struct V_2 * V_3 )
{
struct V_26 * V_27 = V_99 -> V_29 ;
struct V_30 * V_31 = V_27 -> V_32 -> V_31 ;
int V_128 ;
if ( F_59 ( V_31 ) )
return - V_129 ;
F_22 ( & V_31 -> V_68 ) ;
V_128 = F_54 ( V_99 , V_3 ) ;
F_32 ( & V_31 -> V_68 ) ;
return V_128 ;
}
