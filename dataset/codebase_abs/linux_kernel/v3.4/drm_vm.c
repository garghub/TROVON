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
#elif F_3 ( V_20 ) || F_3 ( V_21 )
V_4 = F_7 ( V_4 ) ;
#endif
return V_4 ;
}
static T_1 F_8 ( T_2 V_1 , struct V_2 * V_3 )
{
T_1 V_4 = F_2 ( V_3 -> V_5 ) ;
#if F_3 ( V_13 ) && F_3 ( V_22 )
V_4 |= V_14 ;
#endif
return V_4 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_32 * V_33 = NULL ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
if ( ! F_10 ( V_30 ) )
goto V_38;
if ( ! V_30 -> V_39 || ! V_30 -> V_39 -> V_40 )
goto V_38;
if ( F_11 ( & V_30 -> V_41 , V_3 -> V_42 , & V_37 ) )
goto V_38;
V_35 = F_12 ( V_37 , struct V_34 , V_37 ) ;
V_33 = V_35 -> V_33 ;
if ( V_33 && V_33 -> type == V_10 ) {
T_3 V_43 = ( unsigned long ) V_24 -> V_44 -
V_3 -> V_18 ;
T_3 V_45 = V_33 -> V_43 + V_43 ;
struct V_46 * V_47 ;
struct V_48 * V_48 ;
#ifdef F_13
V_45 -= V_30 -> V_49 -> V_50 -> V_51 ;
#endif
F_14 (agpmem, &dev->agp->memory, head) {
if ( V_47 -> V_52 <= V_45 &&
V_47 -> V_52 + V_47 -> V_53 * V_54 > V_45 )
break;
}
if ( & V_47 -> V_55 == & V_30 -> V_39 -> V_56 )
goto V_38;
V_43 = ( V_45 - V_47 -> V_52 ) >> V_57 ;
V_48 = V_47 -> V_56 -> V_53 [ V_43 ] ;
F_15 ( V_48 ) ;
V_24 -> V_48 = V_48 ;
F_16
( L_1 ,
( unsigned long long ) V_45 ,
V_47 -> V_56 -> V_53 [ V_43 ] ,
( unsigned long long ) V_43 ,
F_17 ( V_48 ) ) ;
return 0 ;
}
V_38:
return V_58 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
return V_58 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_32 * V_33 = V_3 -> V_59 ;
unsigned long V_43 ;
unsigned long V_60 ;
struct V_48 * V_48 ;
if ( ! V_33 )
return V_58 ;
V_43 = ( unsigned long ) V_24 -> V_44 - V_3 -> V_18 ;
V_60 = ( unsigned long ) V_33 -> V_61 + V_43 ;
V_48 = F_19 ( ( void * ) V_60 ) ;
if ( ! V_48 )
return V_58 ;
F_15 ( V_48 ) ;
V_24 -> V_48 = V_48 ;
F_16 ( L_2 , V_43 ) ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_62 * V_63 , * V_64 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
int V_65 = 0 ;
F_16 ( L_3 ,
V_3 -> V_18 , V_3 -> V_19 - V_3 -> V_18 ) ;
F_21 ( & V_30 -> V_66 ) ;
V_33 = V_3 -> V_59 ;
F_22 ( & V_30 -> V_67 ) ;
F_23 (pt, temp, &dev->vmalist, head) {
if ( V_63 -> V_3 -> V_59 == V_33 )
V_65 ++ ;
if ( V_63 -> V_3 == V_3 ) {
F_24 ( & V_63 -> V_55 ) ;
F_25 ( V_63 ) ;
}
}
if ( V_65 == 1 && V_33 -> V_68 & V_69 ) {
V_65 = 0 ;
F_14 (r_list, &dev->maplist, head) {
if ( V_35 -> V_33 == V_33 )
V_65 ++ ;
}
if ( ! V_65 ) {
T_4 V_70 ;
switch ( V_33 -> type ) {
case V_15 :
case V_71 :
if ( F_26 ( V_30 ) && V_33 -> V_72 >= 0 ) {
int V_73 ;
V_73 = F_27 ( V_33 -> V_72 ,
V_33 -> V_43 ,
V_33 -> V_74 ) ;
F_16 ( L_4 , V_73 ) ;
}
F_28 ( V_33 -> V_61 ) ;
break;
case V_75 :
F_29 ( V_33 -> V_61 ) ;
break;
case V_10 :
case V_76 :
break;
case V_77 :
V_70 . V_78 = V_33 -> V_61 ;
V_70 . V_79 = V_33 -> V_43 ;
V_70 . V_74 = V_33 -> V_74 ;
F_30 ( V_30 , & V_70 ) ;
break;
case V_80 :
F_31 ( L_5 ) ;
break;
}
F_25 ( V_33 ) ;
}
}
F_32 ( & V_30 -> V_67 ) ;
}
static int F_33 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_81 * V_82 = V_30 -> V_82 ;
unsigned long V_43 ;
unsigned long V_83 ;
struct V_48 * V_48 ;
if ( ! V_82 )
return V_58 ;
if ( ! V_82 -> V_84 )
return V_58 ;
V_43 = ( unsigned long ) V_24 -> V_44 - V_3 -> V_18 ;
V_83 = V_43 >> V_57 ;
V_48 = F_34 ( ( V_82 -> V_84 [ V_83 ] + ( V_43 & ( ~ V_85 ) ) ) ) ;
F_15 ( V_48 ) ;
V_24 -> V_48 = V_48 ;
F_16 ( L_6 , V_43 , V_83 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
struct V_32 * V_33 = V_3 -> V_59 ;
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_86 * V_87 = V_30 -> V_88 ;
unsigned long V_43 ;
unsigned long V_89 ;
unsigned long V_90 ;
struct V_48 * V_48 ;
if ( ! V_87 )
return V_58 ;
if ( ! V_87 -> V_84 )
return V_58 ;
V_43 = ( unsigned long ) V_24 -> V_44 - V_3 -> V_18 ;
V_89 = V_33 -> V_43 - ( unsigned long ) V_30 -> V_88 -> V_91 ;
V_90 = ( V_43 >> V_57 ) + ( V_89 >> V_57 ) ;
V_48 = V_87 -> V_84 [ V_90 ] ;
F_15 ( V_48 ) ;
V_24 -> V_48 = V_48 ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
return F_9 ( V_3 , V_24 ) ;
}
static int F_37 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
return F_18 ( V_3 , V_24 ) ;
}
static int F_38 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
return F_33 ( V_3 , V_24 ) ;
}
static int F_39 ( struct V_2 * V_3 , struct V_23 * V_24 )
{
return F_35 ( V_3 , V_24 ) ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_62 * V_92 ;
F_16 ( L_3 ,
V_3 -> V_18 , V_3 -> V_19 - V_3 -> V_18 ) ;
F_41 ( & V_30 -> V_66 ) ;
V_92 = F_42 ( sizeof( * V_92 ) , V_93 ) ;
if ( V_92 ) {
V_92 -> V_3 = V_3 ;
V_92 -> V_94 = V_95 -> V_94 ;
F_43 ( & V_92 -> V_55 , & V_30 -> V_96 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
F_22 ( & V_30 -> V_67 ) ;
F_40 ( V_3 ) ;
F_32 ( & V_30 -> V_67 ) ;
}
void F_45 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_62 * V_63 , * V_64 ;
F_16 ( L_3 ,
V_3 -> V_18 , V_3 -> V_19 - V_3 -> V_18 ) ;
F_21 ( & V_30 -> V_66 ) ;
F_23 (pt, temp, &dev->vmalist, head) {
if ( V_63 -> V_3 == V_3 ) {
F_24 ( & V_63 -> V_55 ) ;
F_25 ( V_63 ) ;
break;
}
}
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
F_22 ( & V_30 -> V_67 ) ;
F_45 ( V_3 ) ;
F_32 ( & V_30 -> V_67 ) ;
}
static int F_47 ( struct V_97 * V_98 , struct V_2 * V_3 )
{
struct V_25 * V_26 = V_98 -> V_28 ;
struct V_29 * V_30 ;
struct V_81 * V_82 ;
unsigned long V_99 = V_3 -> V_19 - V_3 -> V_18 ;
V_30 = V_26 -> V_31 -> V_30 ;
V_82 = V_30 -> V_82 ;
F_16 ( L_7 ,
V_3 -> V_18 , V_3 -> V_19 , V_3 -> V_42 ) ;
if ( ! V_82 || ( V_99 >> V_57 ) != V_82 -> F_17 ) {
return - V_100 ;
}
if ( ! F_48 ( V_101 ) &&
( V_82 -> V_68 & V_102 ) ) {
V_3 -> V_5 &= ~ ( V_103 | V_104 ) ;
#if F_3 ( V_6 ) || F_3 ( V_7 )
F_4 ( V_3 -> V_105 ) &= ~ V_106 ;
#else
V_3 -> V_105 =
F_49 ( F_50
( F_51
( F_52 ( F_4 ( V_3 -> V_105 ) ) ) ) ) ;
#endif
}
V_3 -> V_107 = & V_108 ;
V_3 -> V_5 |= V_109 ;
V_3 -> V_5 |= V_110 ;
F_40 ( V_3 ) ;
return 0 ;
}
static T_3 F_53 ( struct V_29 * V_30 )
{
#ifdef F_13
return V_30 -> V_49 -> V_111 ;
#else
return 0 ;
#endif
}
int F_54 ( struct V_97 * V_98 , struct V_2 * V_3 )
{
struct V_25 * V_26 = V_98 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_32 * V_33 = NULL ;
T_3 V_43 = 0 ;
struct V_36 * V_37 ;
F_16 ( L_7 ,
V_3 -> V_18 , V_3 -> V_19 , V_3 -> V_42 ) ;
if ( ! V_26 -> V_112 )
return - V_113 ;
if ( ! V_3 -> V_42
#if V_114
&& ( ! V_30 -> V_39
|| V_30 -> V_39 -> V_115 . V_116 -> V_117 != V_118 )
#endif
)
return F_47 ( V_98 , V_3 ) ;
if ( F_11 ( & V_30 -> V_41 , V_3 -> V_42 , & V_37 ) ) {
F_31 ( L_8 ) ;
return - V_100 ;
}
V_33 = F_12 ( V_37 , struct V_34 , V_37 ) -> V_33 ;
if ( ! V_33 || ( ( V_33 -> V_68 & V_119 ) && ! F_48 ( V_101 ) ) )
return - V_120 ;
if ( V_33 -> V_74 < V_3 -> V_19 - V_3 -> V_18 )
return - V_100 ;
if ( ! F_48 ( V_101 ) && ( V_33 -> V_68 & V_121 ) ) {
V_3 -> V_5 &= ~ ( V_103 | V_104 ) ;
#if F_3 ( V_6 ) || F_3 ( V_7 )
F_4 ( V_3 -> V_105 ) &= ~ V_106 ;
#else
V_3 -> V_105 =
F_49 ( F_50
( F_51
( F_52 ( F_4 ( V_3 -> V_105 ) ) ) ) ) ;
#endif
}
switch ( V_33 -> type ) {
#if ! F_3 ( V_21 )
case V_10 :
if ( F_10 ( V_30 ) && V_30 -> V_39 -> V_40 ) {
#if F_3 ( V_13 )
F_4 ( V_3 -> V_105 ) |= V_14 ;
#endif
V_3 -> V_107 = & V_122 ;
break;
}
#endif
case V_71 :
case V_15 :
V_43 = F_53 ( V_30 ) ;
V_3 -> V_5 |= V_123 ;
V_3 -> V_105 = F_1 ( V_33 -> type , V_3 ) ;
#if ! F_3 ( V_21 )
if ( F_55 ( V_3 , V_3 -> V_18 ,
( V_33 -> V_43 + V_43 ) >> V_57 ,
V_3 -> V_19 - V_3 -> V_18 ,
V_3 -> V_105 ) )
return - V_124 ;
#else
if ( F_56 ( V_3 , V_3 -> V_18 ,
( V_33 -> V_43 + V_43 ) >> V_57 ,
V_3 -> V_19 - V_3 -> V_18 ,
V_3 -> V_105 ) )
return - V_124 ;
#endif
F_16 ( L_9
L_10 ,
V_33 -> type ,
V_3 -> V_18 , V_3 -> V_19 , ( unsigned long long ) ( V_33 -> V_43 + V_43 ) ) ;
V_3 -> V_107 = & V_122 ;
break;
case V_77 :
if ( F_56 ( V_3 , V_3 -> V_18 ,
F_57 ( F_34 ( V_33 -> V_61 ) ) ,
V_3 -> V_19 - V_3 -> V_18 , V_3 -> V_105 ) )
return - V_124 ;
V_3 -> V_105 = F_8 ( V_33 -> type , V_3 ) ;
case V_75 :
V_3 -> V_107 = & V_125 ;
V_3 -> V_59 = ( void * ) V_33 ;
V_3 -> V_5 |= V_109 ;
break;
case V_76 :
V_3 -> V_107 = & V_126 ;
V_3 -> V_59 = ( void * ) V_33 ;
V_3 -> V_5 |= V_109 ;
V_3 -> V_105 = F_8 ( V_33 -> type , V_3 ) ;
break;
default:
return - V_100 ;
}
V_3 -> V_5 |= V_109 ;
V_3 -> V_5 |= V_110 ;
F_40 ( V_3 ) ;
return 0 ;
}
int F_58 ( struct V_97 * V_98 , struct V_2 * V_3 )
{
struct V_25 * V_26 = V_98 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
int V_127 ;
if ( F_59 ( V_30 ) )
return - V_128 ;
F_22 ( & V_30 -> V_67 ) ;
V_127 = F_54 ( V_98 , V_3 ) ;
F_32 ( & V_30 -> V_67 ) ;
return V_127 ;
}
