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
if ( ! V_30 -> V_36 )
goto V_37;
if ( ! V_30 -> V_36 || ! V_30 -> V_36 -> V_38 )
goto V_37;
if ( F_10 ( & V_30 -> V_39 , V_4 -> V_40 , & V_35 ) )
goto V_37;
V_33 = F_11 ( V_35 , struct V_32 , V_35 ) ;
V_2 = V_33 -> V_2 ;
if ( V_2 && V_2 -> type == V_41 ) {
T_3 V_42 = ( unsigned long ) V_24 -> V_43 -
V_4 -> V_16 ;
T_3 V_44 = V_2 -> V_42 + V_42 ;
struct V_45 * V_46 ;
struct V_47 * V_47 ;
#ifdef F_12
V_44 -= V_30 -> V_48 -> V_49 -> V_50 ;
#endif
F_13 (agpmem, &dev->agp->memory, head) {
if ( V_46 -> V_51 <= V_44 &&
V_46 -> V_51 + V_46 -> V_52 * V_53 > V_44 )
break;
}
if ( & V_46 -> V_54 == & V_30 -> V_36 -> V_55 )
goto V_37;
V_42 = ( V_44 - V_46 -> V_51 ) >> V_56 ;
V_47 = V_46 -> V_55 -> V_52 [ V_42 ] ;
F_14 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
F_15
( L_1 ,
( unsigned long long ) V_44 ,
V_46 -> V_55 -> V_52 [ V_42 ] ,
( unsigned long long ) V_42 ,
F_16 ( V_47 ) ) ;
return 0 ;
}
V_37:
return V_57 ;
}
static int F_9 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return V_57 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_1 * V_2 = V_4 -> V_58 ;
unsigned long V_42 ;
unsigned long V_59 ;
struct V_47 * V_47 ;
if ( ! V_2 )
return V_57 ;
V_42 = ( unsigned long ) V_24 -> V_43 - V_4 -> V_16 ;
V_59 = ( unsigned long ) V_2 -> V_60 + V_42 ;
V_47 = F_18 ( ( void * ) V_59 ) ;
if ( ! V_47 )
return V_57 ;
F_14 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
F_15 ( L_2 , V_42 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_61 * V_62 , * V_63 ;
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_64 = 0 ;
F_15 ( L_3 ,
V_4 -> V_16 , V_4 -> V_17 - V_4 -> V_16 ) ;
V_2 = V_4 -> V_58 ;
F_20 ( & V_30 -> V_65 ) ;
F_21 (pt, temp, &dev->vmalist, head) {
if ( V_62 -> V_4 -> V_58 == V_2 )
V_64 ++ ;
if ( V_62 -> V_4 == V_4 ) {
F_22 ( & V_62 -> V_54 ) ;
F_23 ( V_62 ) ;
}
}
if ( V_64 == 1 && V_2 -> V_10 & V_66 ) {
V_64 = 0 ;
F_13 (r_list, &dev->maplist, head) {
if ( V_33 -> V_2 == V_2 )
V_64 ++ ;
}
if ( ! V_64 ) {
T_4 V_67 ;
switch ( V_2 -> type ) {
case V_9 :
case V_68 :
F_24 ( V_2 -> V_69 ) ;
F_25 ( V_2 -> V_60 ) ;
break;
case V_70 :
F_26 ( V_2 -> V_60 ) ;
break;
case V_41 :
case V_71 :
break;
case V_72 :
V_67 . V_73 = V_2 -> V_60 ;
V_67 . V_74 = V_2 -> V_42 ;
V_67 . V_75 = V_2 -> V_75 ;
F_27 ( V_30 , & V_67 ) ;
break;
}
F_23 ( V_2 ) ;
}
}
F_28 ( & V_30 -> V_65 ) ;
}
static int F_29 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_76 * V_77 = V_30 -> V_77 ;
unsigned long V_42 ;
unsigned long V_78 ;
struct V_47 * V_47 ;
if ( ! V_77 )
return V_57 ;
if ( ! V_77 -> V_79 )
return V_57 ;
V_42 = ( unsigned long ) V_24 -> V_43 - V_4 -> V_16 ;
V_78 = V_42 >> V_56 ;
V_47 = F_30 ( ( void * ) V_77 -> V_79 [ V_78 ] ) ;
F_14 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
F_15 ( L_4 , V_42 , V_78 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_1 * V_2 = V_4 -> V_58 ;
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_80 * V_81 = V_30 -> V_82 ;
unsigned long V_42 ;
unsigned long V_83 ;
unsigned long V_84 ;
struct V_47 * V_47 ;
if ( ! V_81 )
return V_57 ;
if ( ! V_81 -> V_79 )
return V_57 ;
V_42 = ( unsigned long ) V_24 -> V_43 - V_4 -> V_16 ;
V_83 = V_2 -> V_42 - ( unsigned long ) V_30 -> V_82 -> V_85 ;
V_84 = ( V_42 >> V_56 ) + ( V_83 >> V_56 ) ;
V_47 = V_81 -> V_79 [ V_84 ] ;
F_14 ( V_47 ) ;
V_24 -> V_47 = V_47 ;
return 0 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_9 ( V_4 , V_24 ) ;
}
static int F_33 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_17 ( V_4 , V_24 ) ;
}
static int F_34 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_29 ( V_4 , V_24 ) ;
}
static int F_35 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
return F_31 ( V_4 , V_24 ) ;
}
void F_36 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
struct V_61 * V_86 ;
F_15 ( L_3 ,
V_4 -> V_16 , V_4 -> V_17 - V_4 -> V_16 ) ;
V_86 = F_37 ( sizeof( * V_86 ) , V_87 ) ;
if ( V_86 ) {
V_86 -> V_4 = V_4 ;
V_86 -> V_88 = V_89 -> V_88 ;
F_38 ( & V_86 -> V_54 , & V_30 -> V_90 ) ;
}
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
F_20 ( & V_30 -> V_65 ) ;
F_36 ( V_30 , V_4 ) ;
F_28 ( & V_30 -> V_65 ) ;
}
void F_40 ( struct V_29 * V_30 ,
struct V_3 * V_4 )
{
struct V_61 * V_62 , * V_63 ;
F_15 ( L_3 ,
V_4 -> V_16 , V_4 -> V_17 - V_4 -> V_16 ) ;
F_21 (pt, temp, &dev->vmalist, head) {
if ( V_62 -> V_4 == V_4 ) {
F_22 ( & V_62 -> V_54 ) ;
F_23 ( V_62 ) ;
break;
}
}
}
static void F_41 ( struct V_3 * V_4 )
{
struct V_25 * V_26 = V_4 -> V_27 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
F_20 ( & V_30 -> V_65 ) ;
F_40 ( V_30 , V_4 ) ;
F_28 ( & V_30 -> V_65 ) ;
}
static int F_42 ( struct V_91 * V_92 , struct V_3 * V_4 )
{
struct V_25 * V_26 = V_92 -> V_28 ;
struct V_29 * V_30 ;
struct V_76 * V_77 ;
unsigned long V_93 = V_4 -> V_17 - V_4 -> V_16 ;
V_30 = V_26 -> V_31 -> V_30 ;
V_77 = V_30 -> V_77 ;
F_15 ( L_5 ,
V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_40 ) ;
if ( ! V_77 || ( V_93 >> V_56 ) != V_77 -> F_16 ) {
return - V_94 ;
}
if ( ! F_43 ( V_95 ) &&
( V_77 -> V_10 & V_96 ) ) {
V_4 -> V_6 &= ~ ( V_97 | V_98 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_6 ( V_4 -> V_99 ) &= ~ V_100 ;
#else
V_4 -> V_99 =
F_44 ( F_45
( F_46
( F_47 ( F_6 ( V_4 -> V_99 ) ) ) ) ) ;
#endif
}
V_4 -> V_101 = & V_102 ;
V_4 -> V_6 |= V_103 | V_104 ;
F_36 ( V_30 , V_4 ) ;
return 0 ;
}
static T_3 F_48 ( struct V_29 * V_30 )
{
#ifdef F_12
return V_30 -> V_48 -> V_105 ;
#else
return 0 ;
#endif
}
int F_49 ( struct V_91 * V_92 , struct V_3 * V_4 )
{
struct V_25 * V_26 = V_92 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
struct V_1 * V_2 = NULL ;
T_3 V_42 = 0 ;
struct V_34 * V_35 ;
F_15 ( L_5 ,
V_4 -> V_16 , V_4 -> V_17 , V_4 -> V_40 ) ;
if ( ! V_26 -> V_106 )
return - V_107 ;
if ( ! V_4 -> V_40
#if V_108
&& ( ! V_30 -> V_36
|| V_30 -> V_36 -> V_109 . V_110 -> V_111 != V_112 )
#endif
)
return F_42 ( V_92 , V_4 ) ;
if ( F_10 ( & V_30 -> V_39 , V_4 -> V_40 , & V_35 ) ) {
F_50 ( L_6 ) ;
return - V_94 ;
}
V_2 = F_11 ( V_35 , struct V_32 , V_35 ) -> V_2 ;
if ( ! V_2 || ( ( V_2 -> V_10 & V_113 ) && ! F_43 ( V_95 ) ) )
return - V_114 ;
if ( V_2 -> V_75 < V_4 -> V_17 - V_4 -> V_16 )
return - V_94 ;
if ( ! F_43 ( V_95 ) && ( V_2 -> V_10 & V_115 ) ) {
V_4 -> V_6 &= ~ ( V_97 | V_98 ) ;
#if F_3 ( V_7 ) || F_3 ( V_8 )
F_6 ( V_4 -> V_99 ) &= ~ V_100 ;
#else
V_4 -> V_99 =
F_44 ( F_45
( F_46
( F_47 ( F_6 ( V_4 -> V_99 ) ) ) ) ) ;
#endif
}
switch ( V_2 -> type ) {
#if ! F_3 ( V_19 )
case V_41 :
if ( V_30 -> V_36 && V_30 -> V_36 -> V_38 ) {
#if F_3 ( V_12 )
F_6 ( V_4 -> V_99 ) |= V_13 ;
#endif
V_4 -> V_101 = & V_116 ;
break;
}
#endif
case V_68 :
case V_9 :
V_42 = F_48 ( V_30 ) ;
V_4 -> V_99 = F_1 ( V_2 , V_4 ) ;
if ( F_51 ( V_4 , V_4 -> V_16 ,
( V_2 -> V_42 + V_42 ) >> V_56 ,
V_4 -> V_17 - V_4 -> V_16 ,
V_4 -> V_99 ) )
return - V_117 ;
F_15 ( L_7
L_8 ,
V_2 -> type ,
V_4 -> V_16 , V_4 -> V_17 , ( unsigned long long ) ( V_2 -> V_42 + V_42 ) ) ;
V_4 -> V_101 = & V_116 ;
break;
case V_72 :
if ( F_52 ( V_4 , V_4 -> V_16 ,
F_53 ( F_30 ( V_2 -> V_60 ) ) ,
V_4 -> V_17 - V_4 -> V_16 , V_4 -> V_99 ) )
return - V_117 ;
V_4 -> V_99 = F_8 ( V_2 -> type , V_4 ) ;
case V_70 :
V_4 -> V_101 = & V_118 ;
V_4 -> V_58 = ( void * ) V_2 ;
break;
case V_71 :
V_4 -> V_101 = & V_119 ;
V_4 -> V_58 = ( void * ) V_2 ;
V_4 -> V_99 = F_8 ( V_2 -> type , V_4 ) ;
break;
default:
return - V_94 ;
}
V_4 -> V_6 |= V_103 | V_104 ;
F_36 ( V_30 , V_4 ) ;
return 0 ;
}
int F_54 ( struct V_91 * V_92 , struct V_3 * V_4 )
{
struct V_25 * V_26 = V_92 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_31 -> V_30 ;
int V_120 ;
if ( F_55 ( V_30 ) )
return - V_121 ;
F_20 ( & V_30 -> V_65 ) ;
V_120 = F_49 ( V_92 , V_4 ) ;
F_28 ( & V_30 -> V_65 ) ;
return V_120 ;
}
