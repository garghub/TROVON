static int
F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 ,
int * V_8 , struct V_9 * * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 V_16 , * V_17 ;
T_1 V_18 [ 2 ] , * V_19 = NULL ;
if ( F_2 ( ! F_3 ( V_12 ) ) ) {
V_17 = F_4 ( V_5 , V_12 -> V_20 , sizeof( V_16 ) , & V_16 ) ;
if ( V_17 ) {
if ( V_17 -> V_21 || ! ( F_5 ( V_2 ) || V_17 -> V_22 ) )
return 1 ;
V_19 = & V_17 -> V_23 ;
}
} else {
V_19 = F_4 (
V_5 , V_12 -> V_20 , sizeof( V_18 ) , & V_18 ) ;
}
if ( ! V_19 ) {
* V_8 = V_24 ;
return 0 ;
}
F_6 () ;
if ( F_2 ( ! F_7 ( V_12 ) ) )
V_14 = F_8 ( V_2 , V_3 , V_5 -> V_25 , V_12 -> V_26 ,
& V_12 -> V_27 , V_19 [ 1 ] ) ;
else
V_14 = F_8 ( V_2 , V_3 , V_5 -> V_25 , V_12 -> V_26 ,
& V_12 -> V_28 , V_19 [ 0 ] ) ;
if ( V_14 ) {
int V_29 ;
if ( F_9 ( V_2 ) ) {
F_10 () ;
* V_8 = V_24 ;
return 0 ;
}
* V_10 = F_11 ( V_14 , V_5 , V_7 , & V_29 , V_12 ) ;
if ( ! * V_10 && V_29 <= 0 ) {
if ( ! V_29 )
* V_8 = F_12 ( V_14 , V_5 , V_7 , V_12 ) ;
else
* V_8 = V_24 ;
F_10 () ;
return 0 ;
}
}
F_10 () ;
return 1 ;
}
static inline void
F_13 ( int V_3 , struct V_15 * V_30 ,
const union V_31 * V_32 ,
const union V_31 * V_33 ,
T_1 V_34 , T_1 V_35 )
{
#ifdef F_14
if ( V_3 == V_36 )
V_30 -> V_37 =
F_15 ( F_16 ( V_32 -> V_38 , V_33 -> V_38 ,
F_17 ( V_34 , V_35 ,
~ F_18 ( V_30 -> V_37 ) ) ) ) ;
else
#endif
V_30 -> V_37 =
F_15 ( F_19 ( V_32 -> V_39 , V_33 -> V_39 ,
F_17 ( V_34 , V_35 ,
~ F_18 ( V_30 -> V_37 ) ) ) ) ;
}
static inline void
F_20 ( int V_3 , struct V_15 * V_30 ,
const union V_31 * V_32 ,
const union V_31 * V_33 ,
T_1 V_40 , T_1 V_41 )
{
#ifdef F_14
if ( V_3 == V_36 )
V_30 -> V_37 =
~ F_15 ( F_16 ( V_32 -> V_38 , V_33 -> V_38 ,
F_17 ( V_40 , V_41 ,
F_18 ( V_30 -> V_37 ) ) ) ) ;
else
#endif
V_30 -> V_37 =
~ F_15 ( F_19 ( V_32 -> V_39 , V_33 -> V_39 ,
F_17 ( V_40 , V_41 ,
F_18 ( V_30 -> V_37 ) ) ) ) ;
}
static int
F_21 ( struct V_4 * V_5 , struct V_42 * V_43 ,
struct V_9 * V_44 , struct V_11 * V_12 )
{
struct V_15 * V_30 ;
unsigned int V_45 = V_12 -> V_20 ;
int V_40 ;
int V_46 = 0 ;
#ifdef F_14
if ( V_44 -> V_3 == V_36 && V_12 -> V_47 )
return 1 ;
#endif
V_40 = V_5 -> V_20 - V_45 ;
if ( ! F_22 ( V_5 , V_45 + sizeof( * V_30 ) ) )
return 0 ;
if ( F_23 ( V_44 -> V_48 != NULL ) ) {
int V_49 ;
if ( V_43 -> V_50 && ! V_43 -> V_50 ( V_44 -> V_3 , V_5 , V_43 ) )
return 0 ;
if ( ! ( V_49 = F_24 ( V_44 , V_5 ) ) )
return 0 ;
if ( V_49 == 1 )
V_40 = V_5 -> V_20 - V_45 ;
else
V_46 = 1 ;
}
V_30 = ( void * ) F_25 ( V_5 ) + V_45 ;
V_30 -> V_23 = V_44 -> V_51 ;
if ( V_5 -> V_52 == V_53 ) {
F_20 ( V_44 -> V_3 , V_30 , & V_44 -> V_27 , & V_44 -> V_54 ,
F_26 ( V_40 ) ,
F_26 ( V_5 -> V_20 - V_45 ) ) ;
} else if ( ! V_46 ) {
F_13 ( V_44 -> V_3 , V_30 , & V_44 -> V_27 , & V_44 -> V_54 ,
V_44 -> V_55 , V_44 -> V_51 ) ;
if ( V_5 -> V_52 == V_56 )
V_5 -> V_52 = ( V_44 -> V_48 && V_43 -> V_50 ) ?
V_57 : V_58 ;
} else {
V_30 -> V_37 = 0 ;
V_5 -> V_59 = F_27 ( V_5 , V_45 , V_5 -> V_20 - V_45 , 0 ) ;
#ifdef F_14
if ( V_44 -> V_3 == V_36 )
V_30 -> V_37 = F_28 ( & V_44 -> V_54 . V_60 ,
& V_44 -> V_61 . V_60 ,
V_5 -> V_20 - V_45 ,
V_44 -> V_26 , V_5 -> V_59 ) ;
else
#endif
V_30 -> V_37 = F_29 ( V_44 -> V_54 . V_39 ,
V_44 -> V_61 . V_39 ,
V_5 -> V_20 - V_45 ,
V_44 -> V_26 ,
V_5 -> V_59 ) ;
V_5 -> V_52 = V_57 ;
F_30 ( 11 , L_1 ,
V_43 -> V_62 , V_30 -> V_37 ,
( char * ) & ( V_30 -> V_37 ) - ( char * ) V_30 ) ;
}
return 1 ;
}
static int
F_31 ( struct V_4 * V_5 , struct V_42 * V_43 ,
struct V_9 * V_44 , struct V_11 * V_12 )
{
struct V_15 * V_30 ;
unsigned int V_45 = V_12 -> V_20 ;
int V_40 ;
int V_46 = 0 ;
#ifdef F_14
if ( V_44 -> V_3 == V_36 && V_12 -> V_47 )
return 1 ;
#endif
V_40 = V_5 -> V_20 - V_45 ;
if ( ! F_22 ( V_5 , V_45 + sizeof( * V_30 ) ) )
return 0 ;
if ( F_23 ( V_44 -> V_48 != NULL ) ) {
int V_49 ;
if ( V_43 -> V_50 && ! V_43 -> V_50 ( V_44 -> V_3 , V_5 , V_43 ) )
return 0 ;
if ( ! ( V_49 = F_32 ( V_44 , V_5 ) ) )
return 0 ;
if ( V_49 == 1 )
V_40 = V_5 -> V_20 - V_45 ;
else
V_46 = 1 ;
}
V_30 = ( void * ) F_25 ( V_5 ) + V_45 ;
V_30 -> V_63 = V_44 -> V_55 ;
if ( V_5 -> V_52 == V_53 ) {
F_20 ( V_44 -> V_3 , V_30 , & V_44 -> V_54 , & V_44 -> V_27 ,
F_26 ( V_40 ) ,
F_26 ( V_5 -> V_20 - V_45 ) ) ;
} else if ( ! V_46 ) {
F_13 ( V_44 -> V_3 , V_30 , & V_44 -> V_54 , & V_44 -> V_27 ,
V_44 -> V_51 , V_44 -> V_55 ) ;
if ( V_5 -> V_52 == V_56 )
V_5 -> V_52 = ( V_44 -> V_48 && V_43 -> V_50 ) ?
V_57 : V_58 ;
} else {
V_30 -> V_37 = 0 ;
V_5 -> V_59 = F_27 ( V_5 , V_45 , V_5 -> V_20 - V_45 , 0 ) ;
#ifdef F_14
if ( V_44 -> V_3 == V_36 )
V_30 -> V_37 = F_28 ( & V_44 -> V_61 . V_60 ,
& V_44 -> V_27 . V_60 ,
V_5 -> V_20 - V_45 ,
V_44 -> V_26 , V_5 -> V_59 ) ;
else
#endif
V_30 -> V_37 = F_29 ( V_44 -> V_61 . V_39 ,
V_44 -> V_27 . V_39 ,
V_5 -> V_20 - V_45 ,
V_44 -> V_26 ,
V_5 -> V_59 ) ;
V_5 -> V_52 = V_57 ;
}
return 1 ;
}
static int
F_33 ( int V_3 , struct V_4 * V_5 , struct V_42 * V_43 )
{
unsigned int V_45 ;
#ifdef F_14
if ( V_3 == V_36 )
V_45 = sizeof( struct V_64 ) ;
else
#endif
V_45 = F_34 ( V_5 ) ;
switch ( V_5 -> V_52 ) {
case V_58 :
V_5 -> V_59 = F_27 ( V_5 , V_45 , V_5 -> V_20 - V_45 , 0 ) ;
case V_56 :
#ifdef F_14
if ( V_3 == V_36 ) {
if ( F_28 ( & F_35 ( V_5 ) -> V_28 ,
& F_35 ( V_5 ) -> V_27 ,
V_5 -> V_20 - V_45 ,
F_35 ( V_5 ) -> V_65 ,
V_5 -> V_59 ) ) {
F_36 ( 0 , V_3 , V_43 , V_5 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_29 ( F_37 ( V_5 ) -> V_28 ,
F_37 ( V_5 ) -> V_27 ,
V_5 -> V_20 - V_45 ,
F_37 ( V_5 ) -> V_26 ,
V_5 -> V_59 ) ) {
F_36 ( 0 , V_3 , V_43 , V_5 , 0 ,
L_2 ) ;
return 0 ;
}
break;
default:
break;
}
return 1 ;
}
static const char * F_38 ( int V_66 )
{
if ( V_66 >= V_67 )
return L_3 ;
return V_68 [ V_66 ] ? V_68 [ V_66 ] : L_4 ;
}
static void F_39 ( struct V_6 * V_7 , int V_69 )
{
int V_70 = ( V_69 & 1 ) ;
V_7 -> V_71 = ( V_70 ? V_72 : V_73 ) ;
}
static inline int F_40 ( struct V_15 * V_17 )
{
if ( V_17 -> V_21 )
return 3 ;
if ( V_17 -> V_22 )
return 0 ;
if ( V_17 -> V_74 )
return 1 ;
if ( V_17 -> V_75 )
return 2 ;
return - 1 ;
}
static inline void
F_41 ( struct V_6 * V_7 , struct V_9 * V_44 ,
int V_76 , struct V_15 * V_17 )
{
int V_77 ;
int V_78 = V_79 ;
int V_80 = V_81 [ V_76 ] ;
if ( V_44 -> V_69 & V_82 ) {
if ( V_80 == V_83 )
V_44 -> V_69 &= ~ V_82 ;
else
V_80 = V_84 ;
}
if ( ( V_77 = F_40 ( V_17 ) ) < 0 ) {
F_30 ( 8 , L_5 , V_77 ) ;
goto V_85;
}
V_78 =
V_7 -> V_71 [ V_80 + V_77 ] . V_86 [ V_44 -> V_66 ] ;
V_85:
if ( V_78 != V_44 -> V_66 ) {
struct V_87 * V_63 = V_44 -> V_63 ;
F_42 ( 8 , L_6
L_7 ,
V_7 -> V_43 -> V_62 ,
( ( V_80 == V_83 ) ?
L_8 : L_9 ) ,
V_17 -> V_22 ? 'S' : '.' ,
V_17 -> V_74 ? 'F' : '.' ,
V_17 -> V_75 ? 'A' : '.' ,
V_17 -> V_21 ? 'R' : '.' ,
F_43 ( V_44 -> V_88 , & V_44 -> V_27 ) ,
F_44 ( V_44 -> V_55 ) ,
F_43 ( V_44 -> V_3 , & V_44 -> V_61 ) ,
F_44 ( V_44 -> V_89 ) ,
F_38 ( V_44 -> V_66 ) ,
F_38 ( V_78 ) ,
F_45 ( & V_44 -> V_90 ) ) ;
if ( V_63 ) {
if ( ! ( V_44 -> V_69 & V_91 ) &&
( V_78 != V_92 ) ) {
F_46 ( & V_63 -> V_93 ) ;
F_47 ( & V_63 -> V_94 ) ;
V_44 -> V_69 |= V_91 ;
} else if ( ( V_44 -> V_69 & V_91 ) &&
( V_78 == V_92 ) ) {
F_47 ( & V_63 -> V_93 ) ;
F_46 ( & V_63 -> V_94 ) ;
V_44 -> V_69 &= ~ V_91 ;
}
}
}
if ( F_2 ( V_7 ) )
V_44 -> V_95 = V_7 -> V_96 [ V_44 -> V_66 = V_78 ] ;
else
V_44 -> V_95 = V_97 [ V_44 -> V_66 = V_78 ] ;
}
static void
F_48 ( struct V_9 * V_44 , int V_76 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_15 V_16 , * V_17 ;
#ifdef F_14
int V_98 = V_44 -> V_3 == V_99 ? F_34 ( V_5 ) : sizeof( struct V_64 ) ;
#else
int V_98 = F_34 ( V_5 ) ;
#endif
V_17 = F_4 ( V_5 , V_98 , sizeof( V_16 ) , & V_16 ) ;
if ( V_17 == NULL )
return;
F_49 ( & V_44 -> V_100 ) ;
F_41 ( V_7 , V_44 , V_76 , V_17 ) ;
F_50 ( & V_44 -> V_100 ) ;
}
static inline T_2 F_51 ( T_1 V_101 )
{
return ( ( ( V_102 V_103 ) V_101 >> V_104 ) ^ ( V_102 V_103 ) V_101 )
& V_105 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
struct V_106 * V_108 ;
T_2 V_109 ;
T_1 V_101 = V_107 -> V_101 ;
int V_49 = 0 ;
struct V_6 * V_7 = F_53 ( V_2 , V_110 ) ;
V_109 = F_51 ( V_101 ) ;
F_54 (i, &ipvs->tcp_apps[hash], p_list) {
if ( V_108 -> V_101 == V_101 ) {
V_49 = - V_111 ;
goto V_112;
}
}
F_55 ( & V_107 -> V_113 , & V_2 -> V_114 [ V_109 ] ) ;
F_47 ( & V_7 -> V_115 ) ;
V_112:
return V_49 ;
}
static void
F_56 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
struct V_6 * V_7 = F_53 ( V_2 , V_110 ) ;
F_46 ( & V_7 -> V_115 ) ;
F_57 ( & V_107 -> V_113 ) ;
}
static int
F_58 ( struct V_9 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
int V_109 ;
struct V_106 * V_107 ;
int V_116 = 0 ;
if ( F_59 ( V_44 ) != V_117 )
return 0 ;
V_109 = F_51 ( V_44 -> V_51 ) ;
F_6 () ;
F_60 (inc, &ipvs->tcp_apps[hash], p_list) {
if ( V_107 -> V_101 == V_44 -> V_51 ) {
if ( F_23 ( ! F_61 ( V_107 ) ) )
break;
F_10 () ;
F_42 ( 9 , L_10
L_11 ,
V_118 ,
F_43 ( V_44 -> V_3 , & V_44 -> V_61 ) ,
F_44 ( V_44 -> V_89 ) ,
F_43 ( V_44 -> V_3 , & V_44 -> V_54 ) ,
F_44 ( V_44 -> V_51 ) ,
V_107 -> V_62 , F_44 ( V_107 -> V_101 ) ) ;
V_44 -> V_48 = V_107 ;
if ( V_107 -> V_119 )
V_116 = V_107 -> V_119 ( V_107 , V_44 ) ;
goto V_112;
}
}
F_10 () ;
V_112:
return V_116 ;
}
void F_62 ( struct V_9 * V_44 )
{
struct V_6 * V_7 = F_53 ( V_44 -> V_2 , V_110 ) ;
F_49 ( & V_44 -> V_100 ) ;
V_44 -> V_66 = V_120 ;
V_44 -> V_95 = ( V_7 ? V_7 -> V_96 [ V_120 ]
: V_97 [ V_120 ] ) ;
F_50 ( & V_44 -> V_100 ) ;
}
static int F_63 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_64 ( V_2 -> V_114 , V_121 ) ;
V_7 -> V_96 = F_65 ( ( int * ) V_97 ,
sizeof( V_97 ) ) ;
if ( ! V_7 -> V_96 )
return - V_122 ;
V_7 -> V_71 = V_73 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_67 ( V_7 -> V_96 ) ;
}
