static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_4 -> V_6 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
if ( V_2 -> type == V_9 && ! ( V_2 -> V_10 & V_11 ) )
V_5 = F_4 ( V_5 ) ;
else
V_5 = F_5 ( V_5 ) ;
#elif F_3 ( V_12 )
F_6 ( V_5 ) |= V_13 ;
if ( V_2 -> type == V_9 )
F_6 ( V_5 ) |= V_14 ;
#elif F_3 ( V_15 )
if ( F_7 ( V_4 -> V_16 , V_4 -> V_17 -
V_4 -> V_16 ) )
V_5 = F_5 ( V_5 ) ;
else
V_5 = F_4 ( V_5 ) ;
#elif F_3 ( V_18 ) || F_3 ( V_19 ) || F_3 ( V_20 )
V_5 = F_4 ( V_5 ) ;
#endif
return V_5 ;
}
static T_1 F_8 ( T_2 V_21 , struct V_3 * V_4 )
{
T_1 V_5 = F_2 ( V_4 -> V_6 ) ;
#if F_3 ( V_12 ) && F_3 ( V_22 )
V_5 |= V_13 ;
#endif
return V_5 ;
}
static int F_9 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_1 * V_2 = NULL ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
if ( ! F_10 ( V_30 ) )
goto V_36;
if ( ! V_30 -> V_37 || ! V_30 -> V_37 -> V_38 )
goto V_36;
if ( F_11 ( & V_30 -> V_39 , V_4 -> V_40 , & V_35 ) )
goto V_36;
V_33 = F_12 ( V_35 , struct V_32 , V_35 ) ;
V_2 = V_33 -> V_2 ;
if ( V_2 && V_2 -> type == V_41 ) {
T_3 V_42 = ( unsigned long ) V_24 -> V_43 -
V_4 -> V_16 ;
T_3 V_44 = V_2 -> V_42 + V_42 ;
struct V_45 * V_46 ;
struct V_47 * V_47 ;
#ifdef F_13
V_44 -= V_30 -> V_48 -> V_49 -> V_50 ;
#endif
F_14 (agpmem, &dev->agp->memory, head) {
if ( V_46 -> V_51 <= V_44 &&
V_46 -> V_51 + V_46 -> V_52 * V_53 > V_44 )
break;
}
if ( & V_46 -> V_54 == & V_30 -> V_37 -> V_55 )
goto V_36;
V_42 = ( V_44 - V_46 -> V_51 ) >> V_56 ;
V_47 = V_46 -> V_55 -> V_52 [ V_42 ] ;
F_15 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
F_16
( L_1 ,
( unsigned long long ) V_44 ,
V_46 -> V_55 -> V_52 [ V_42 ] ,
( unsigned long long ) V_42 ,
F_17 ( V_47 ) ) ;
return 0 ;
}
V_36:
return V_57 ;
}
static int F_9 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return V_57 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_1 * V_2 = V_4 -> V_58 ;
unsigned long V_42 ;
unsigned long V_59 ;
struct V_47 * V_47 ;
if ( ! V_2 )
return V_57 ;
V_42 = ( unsigned long ) V_24 -> V_43 - V_4 -> V_16 ;
V_59 = ( unsigned long ) V_2 -> V_60 + V_42 ;
V_47 = F_19 ( ( void * ) V_59 ) ;
if ( ! V_47 )
return V_57 ;
F_15 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
F_16 ( L_2 , V_42 ) ;
return 0 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_61 * V_62 , * V_63 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_64 = 0 ;
F_16 ( L_3 ,
V_4 -> V_16 , V_4 -> V_17 - V_4 -> V_16 ) ;
F_21 ( & V_30 -> V_65 ) ;
V_2 = V_4 -> V_58 ;
F_22 ( & V_30 -> V_66 ) ;
F_23 (pt, temp, &dev->vmalist, head) {
if ( V_62 -> V_4 -> V_58 == V_2 )
V_64 ++ ;
if ( V_62 -> V_4 == V_4 ) {
F_24 ( & V_62 -> V_54 ) ;
F_25 ( V_62 ) ;
}
}
if ( V_64 == 1 && V_2 -> V_10 & V_67 ) {
V_64 = 0 ;
F_14 (r_list, &dev->maplist, head) {
if ( V_33 -> V_2 == V_2 )
V_64 ++ ;
}
if ( ! V_64 ) {
T_4 V_68 ;
switch ( V_2 -> type ) {
case V_9 :
case V_69 :
F_26 ( V_2 -> V_70 ) ;
F_27 ( V_2 -> V_60 ) ;
break;
case V_71 :
F_28 ( V_2 -> V_60 ) ;
break;
case V_41 :
case V_72 :
break;
case V_73 :
V_68 . V_74 = V_2 -> V_60 ;
V_68 . V_75 = V_2 -> V_42 ;
V_68 . V_76 = V_2 -> V_76 ;
F_29 ( V_30 , & V_68 ) ;
break;
case V_77 :
F_30 ( L_4 ) ;
break;
}
F_25 ( V_2 ) ;
}
}
F_31 ( & V_30 -> V_66 ) ;
}
static int F_32 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_78 * V_79 = V_30 -> V_79 ;
unsigned long V_42 ;
unsigned long V_80 ;
struct V_47 * V_47 ;
if ( ! V_79 )
return V_57 ;
if ( ! V_79 -> V_81 )
return V_57 ;
V_42 = ( unsigned long ) V_24 -> V_43 - V_4 -> V_16 ;
V_80 = V_42 >> V_56 ;
V_47 = F_33 ( ( V_79 -> V_81 [ V_80 ] + ( V_42 & ( ~ V_82 ) ) ) ) ;
F_15 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
F_16 ( L_5 , V_42 , V_80 ) ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_1 * V_2 = V_4 -> V_58 ;
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_83 * V_84 = V_30 -> V_85 ;
unsigned long V_42 ;
unsigned long V_86 ;
unsigned long V_87 ;
struct V_47 * V_47 ;
if ( ! V_84 )
return V_57 ;
if ( ! V_84 -> V_81 )
return V_57 ;
V_42 = ( unsigned long ) V_24 -> V_43 - V_4 -> V_16 ;
V_86 = V_2 -> V_42 - ( unsigned long ) V_30 -> V_85 -> V_88 ;
V_87 = ( V_42 >> V_56 ) + ( V_86 >> V_56 ) ;
V_47 = V_84 -> V_81 [ V_87 ] ;
F_15 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_9 ( V_4 , V_24 ) ;
}
static int F_36 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_18 ( V_4 , V_24 ) ;
}
static int F_37 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_32 ( V_4 , V_24 ) ;
}
static int F_38 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_34 ( V_4 , V_24 ) ;
}
void F_39 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
struct V_61 * V_89 ;
F_16 ( L_3 ,
V_4 -> V_16 , V_4 -> V_17 - V_4 -> V_16 ) ;
F_40 ( & V_30 -> V_65 ) ;
V_89 = F_41 ( sizeof( * V_89 ) , V_90 ) ;
if ( V_89 ) {
V_89 -> V_4 = V_4 ;
V_89 -> V_91 = V_92 -> V_91 ;
F_42 ( & V_89 -> V_54 , & V_30 -> V_93 ) ;
}
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
F_22 ( & V_30 -> V_66 ) ;
F_39 ( V_30 , V_4 ) ;
F_31 ( & V_30 -> V_66 ) ;
}
void F_44 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
struct V_61 * V_62 , * V_63 ;
F_16 ( L_3 ,
V_4 -> V_16 , V_4 -> V_17 - V_4 -> V_16 ) ;
F_21 ( & V_30 -> V_65 ) ;
F_23 (pt, temp, &dev->vmalist, head) {
if ( V_62 -> V_4 == V_4 ) {
F_24 ( & V_62 -> V_54 ) ;
F_25 ( V_62 ) ;
break;
}
}
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
F_22 ( & V_30 -> V_66 ) ;
F_44 ( V_30 , V_4 ) ;
F_31 ( & V_30 -> V_66 ) ;
}
static int F_46 ( struct V_94 * V_95 , struct V_3 * V_4 )
{
struct V_25 * V_26 = V_95 -> V_28 ;
struct V_29 * V_30 ;
struct V_78 * V_79 ;
unsigned long V_96 = V_4 -> V_17 - V_4 -> V_16 ;
V_30 = V_26 -> V_31 -> V_30 ;
V_79 = V_30 -> V_79 ;
F_16 ( L_6 ,
V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_40 ) ;
if ( ! V_79 || ( V_96 >> V_56 ) != V_79 -> F_17 ) {
return - V_97 ;
}
if ( ! F_47 ( V_98 ) &&
( V_79 -> V_10 & V_99 ) ) {
V_4 -> V_6 &= ~ ( V_100 | V_101 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_6 ( V_4 -> V_102 ) &= ~ V_103 ;
#else
V_4 -> V_102 =
F_48 ( F_49
( F_50
( F_51 ( F_6 ( V_4 -> V_102 ) ) ) ) ) ;
#endif
}
V_4 -> V_104 = & V_105 ;
V_4 -> V_6 |= V_106 | V_107 ;
F_39 ( V_30 , V_4 ) ;
return 0 ;
}
static T_3 F_52 ( struct V_29 * V_30 )
{
#ifdef F_13
return V_30 -> V_48 -> V_108 ;
#else
return 0 ;
#endif
}
int F_53 ( struct V_94 * V_95 , struct V_3 * V_4 )
{
struct V_25 * V_26 = V_95 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_1 * V_2 = NULL ;
T_3 V_42 = 0 ;
struct V_34 * V_35 ;
F_16 ( L_6 ,
V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_40 ) ;
if ( ! V_26 -> V_109 )
return - V_110 ;
if ( ! V_4 -> V_40
#if V_111
&& ( ! V_30 -> V_37
|| V_30 -> V_37 -> V_112 . V_113 -> V_114 != V_115 )
#endif
)
return F_46 ( V_95 , V_4 ) ;
if ( F_11 ( & V_30 -> V_39 , V_4 -> V_40 , & V_35 ) ) {
F_30 ( L_7 ) ;
return - V_97 ;
}
V_2 = F_12 ( V_35 , struct V_32 , V_35 ) -> V_2 ;
if ( ! V_2 || ( ( V_2 -> V_10 & V_116 ) && ! F_47 ( V_98 ) ) )
return - V_117 ;
if ( V_2 -> V_76 < V_4 -> V_17 - V_4 -> V_16 )
return - V_97 ;
if ( ! F_47 ( V_98 ) && ( V_2 -> V_10 & V_118 ) ) {
V_4 -> V_6 &= ~ ( V_100 | V_101 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_6 ( V_4 -> V_102 ) &= ~ V_103 ;
#else
V_4 -> V_102 =
F_48 ( F_49
( F_50
( F_51 ( F_6 ( V_4 -> V_102 ) ) ) ) ) ;
#endif
}
switch ( V_2 -> type ) {
#if ! F_3 ( V_19 )
case V_41 :
if ( F_10 ( V_30 ) && V_30 -> V_37 -> V_38 ) {
#if F_3 ( V_12 )
F_6 ( V_4 -> V_102 ) |= V_13 ;
#endif
V_4 -> V_104 = & V_119 ;
break;
}
#endif
case V_69 :
case V_9 :
V_42 = F_52 ( V_30 ) ;
V_4 -> V_102 = F_1 ( V_2 , V_4 ) ;
if ( F_54 ( V_4 , V_4 -> V_16 ,
( V_2 -> V_42 + V_42 ) >> V_56 ,
V_4 -> V_17 - V_4 -> V_16 ,
V_4 -> V_102 ) )
return - V_120 ;
F_16 ( L_8
L_9 ,
V_2 -> type ,
V_4 -> V_16 , V_4 -> V_17 , ( unsigned long long ) ( V_2 -> V_42 + V_42 ) ) ;
V_4 -> V_104 = & V_119 ;
break;
case V_73 :
if ( F_55 ( V_4 , V_4 -> V_16 ,
F_56 ( F_33 ( V_2 -> V_60 ) ) ,
V_4 -> V_17 - V_4 -> V_16 , V_4 -> V_102 ) )
return - V_120 ;
V_4 -> V_102 = F_8 ( V_2 -> type , V_4 ) ;
case V_71 :
V_4 -> V_104 = & V_121 ;
V_4 -> V_58 = ( void * ) V_2 ;
break;
case V_72 :
V_4 -> V_104 = & V_122 ;
V_4 -> V_58 = ( void * ) V_2 ;
V_4 -> V_102 = F_8 ( V_2 -> type , V_4 ) ;
break;
default:
return - V_97 ;
}
V_4 -> V_6 |= V_106 | V_107 ;
F_39 ( V_30 , V_4 ) ;
return 0 ;
}
int F_57 ( struct V_94 * V_95 , struct V_3 * V_4 )
{
struct V_25 * V_26 = V_95 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
int V_123 ;
if ( F_58 ( V_30 ) )
return - V_124 ;
F_22 ( & V_30 -> V_66 ) ;
V_123 = F_53 ( V_95 , V_4 ) ;
F_31 ( & V_30 -> V_66 ) ;
return V_123 ;
}
