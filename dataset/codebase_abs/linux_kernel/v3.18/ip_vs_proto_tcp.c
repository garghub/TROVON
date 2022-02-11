static int
F_1 ( int V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int * V_6 , struct V_7 * * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 ;
struct V_12 * V_13 ;
struct V_14 V_15 , * V_16 ;
struct V_17 * V_18 ;
V_16 = F_2 ( V_3 , V_10 -> V_19 , sizeof( V_15 ) , & V_15 ) ;
if ( V_16 == NULL ) {
* V_6 = V_20 ;
return 0 ;
}
V_11 = F_3 ( V_3 ) ;
V_18 = F_4 ( V_11 ) ;
F_5 () ;
if ( ( V_16 -> V_21 || F_6 ( V_18 ) ) && ! V_16 -> V_22 &&
( V_13 = F_7 ( V_11 , V_1 , V_3 -> V_23 , V_10 -> V_24 ,
& V_10 -> V_25 , V_16 -> V_26 ) ) ) {
int V_27 ;
if ( F_8 ( V_18 ) ) {
F_9 () ;
* V_6 = V_20 ;
return 0 ;
}
* V_8 = F_10 ( V_13 , V_3 , V_5 , & V_27 , V_10 ) ;
if ( ! * V_8 && V_27 <= 0 ) {
if ( ! V_27 )
* V_6 = F_11 ( V_13 , V_3 , V_5 , V_10 ) ;
else
* V_6 = V_20 ;
F_9 () ;
return 0 ;
}
}
F_9 () ;
return 1 ;
}
static inline void
F_12 ( int V_1 , struct V_14 * V_28 ,
const union V_29 * V_30 ,
const union V_29 * V_31 ,
T_1 V_32 , T_1 V_33 )
{
#ifdef F_13
if ( V_1 == V_34 )
V_28 -> V_35 =
F_14 ( F_15 ( V_30 -> V_36 , V_31 -> V_36 ,
F_16 ( V_32 , V_33 ,
~ F_17 ( V_28 -> V_35 ) ) ) ) ;
else
#endif
V_28 -> V_35 =
F_14 ( F_18 ( V_30 -> V_37 , V_31 -> V_37 ,
F_16 ( V_32 , V_33 ,
~ F_17 ( V_28 -> V_35 ) ) ) ) ;
}
static inline void
F_19 ( int V_1 , struct V_14 * V_28 ,
const union V_29 * V_30 ,
const union V_29 * V_31 ,
T_1 V_38 , T_1 V_39 )
{
#ifdef F_13
if ( V_1 == V_34 )
V_28 -> V_35 =
~ F_14 ( F_15 ( V_30 -> V_36 , V_31 -> V_36 ,
F_16 ( V_38 , V_39 ,
F_17 ( V_28 -> V_35 ) ) ) ) ;
else
#endif
V_28 -> V_35 =
~ F_14 ( F_18 ( V_30 -> V_37 , V_31 -> V_37 ,
F_16 ( V_38 , V_39 ,
F_17 ( V_28 -> V_35 ) ) ) ) ;
}
static int
F_20 ( struct V_2 * V_3 , struct V_40 * V_41 ,
struct V_7 * V_42 , struct V_9 * V_10 )
{
struct V_14 * V_28 ;
unsigned int V_43 = V_10 -> V_19 ;
int V_38 ;
int V_44 = 0 ;
#ifdef F_13
if ( V_42 -> V_1 == V_34 && V_10 -> V_45 )
return 1 ;
#endif
V_38 = V_3 -> V_19 - V_43 ;
if ( ! F_21 ( V_3 , V_43 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_22 ( V_42 -> V_46 != NULL ) ) {
int V_47 ;
if ( V_41 -> V_48 && ! V_41 -> V_48 ( V_42 -> V_1 , V_3 , V_41 ) )
return 0 ;
if ( ! ( V_47 = F_23 ( V_42 , V_3 ) ) )
return 0 ;
if ( V_47 == 1 )
V_38 = V_3 -> V_19 - V_43 ;
else
V_44 = 1 ;
}
V_28 = ( void * ) F_24 ( V_3 ) + V_43 ;
V_28 -> V_49 = V_42 -> V_50 ;
if ( V_3 -> V_51 == V_52 ) {
F_19 ( V_42 -> V_1 , V_28 , & V_42 -> V_25 , & V_42 -> V_53 ,
F_25 ( V_38 ) ,
F_25 ( V_3 -> V_19 - V_43 ) ) ;
} else if ( ! V_44 ) {
F_12 ( V_42 -> V_1 , V_28 , & V_42 -> V_25 , & V_42 -> V_53 ,
V_42 -> V_54 , V_42 -> V_50 ) ;
if ( V_3 -> V_51 == V_55 )
V_3 -> V_51 = ( V_42 -> V_46 && V_41 -> V_48 ) ?
V_56 : V_57 ;
} else {
V_28 -> V_35 = 0 ;
V_3 -> V_58 = F_26 ( V_3 , V_43 , V_3 -> V_19 - V_43 , 0 ) ;
#ifdef F_13
if ( V_42 -> V_1 == V_34 )
V_28 -> V_35 = F_27 ( & V_42 -> V_53 . V_59 ,
& V_42 -> V_60 . V_59 ,
V_3 -> V_19 - V_43 ,
V_42 -> V_24 , V_3 -> V_58 ) ;
else
#endif
V_28 -> V_35 = F_28 ( V_42 -> V_53 . V_37 ,
V_42 -> V_60 . V_37 ,
V_3 -> V_19 - V_43 ,
V_42 -> V_24 ,
V_3 -> V_58 ) ;
V_3 -> V_51 = V_56 ;
F_29 ( 11 , L_1 ,
V_41 -> V_61 , V_28 -> V_35 ,
( char * ) & ( V_28 -> V_35 ) - ( char * ) V_28 ) ;
}
return 1 ;
}
static int
F_30 ( struct V_2 * V_3 , struct V_40 * V_41 ,
struct V_7 * V_42 , struct V_9 * V_10 )
{
struct V_14 * V_28 ;
unsigned int V_43 = V_10 -> V_19 ;
int V_38 ;
int V_44 = 0 ;
#ifdef F_13
if ( V_42 -> V_1 == V_34 && V_10 -> V_45 )
return 1 ;
#endif
V_38 = V_3 -> V_19 - V_43 ;
if ( ! F_21 ( V_3 , V_43 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_22 ( V_42 -> V_46 != NULL ) ) {
int V_47 ;
if ( V_41 -> V_48 && ! V_41 -> V_48 ( V_42 -> V_1 , V_3 , V_41 ) )
return 0 ;
if ( ! ( V_47 = F_31 ( V_42 , V_3 ) ) )
return 0 ;
if ( V_47 == 1 )
V_38 = V_3 -> V_19 - V_43 ;
else
V_44 = 1 ;
}
V_28 = ( void * ) F_24 ( V_3 ) + V_43 ;
V_28 -> V_26 = V_42 -> V_54 ;
if ( V_3 -> V_51 == V_52 ) {
F_19 ( V_42 -> V_1 , V_28 , & V_42 -> V_53 , & V_42 -> V_25 ,
F_25 ( V_38 ) ,
F_25 ( V_3 -> V_19 - V_43 ) ) ;
} else if ( ! V_44 ) {
F_12 ( V_42 -> V_1 , V_28 , & V_42 -> V_53 , & V_42 -> V_25 ,
V_42 -> V_50 , V_42 -> V_54 ) ;
if ( V_3 -> V_51 == V_55 )
V_3 -> V_51 = ( V_42 -> V_46 && V_41 -> V_48 ) ?
V_56 : V_57 ;
} else {
V_28 -> V_35 = 0 ;
V_3 -> V_58 = F_26 ( V_3 , V_43 , V_3 -> V_19 - V_43 , 0 ) ;
#ifdef F_13
if ( V_42 -> V_1 == V_34 )
V_28 -> V_35 = F_27 ( & V_42 -> V_60 . V_59 ,
& V_42 -> V_25 . V_59 ,
V_3 -> V_19 - V_43 ,
V_42 -> V_24 , V_3 -> V_58 ) ;
else
#endif
V_28 -> V_35 = F_28 ( V_42 -> V_60 . V_37 ,
V_42 -> V_25 . V_37 ,
V_3 -> V_19 - V_43 ,
V_42 -> V_24 ,
V_3 -> V_58 ) ;
V_3 -> V_51 = V_56 ;
}
return 1 ;
}
static int
F_32 ( int V_1 , struct V_2 * V_3 , struct V_40 * V_41 )
{
unsigned int V_43 ;
#ifdef F_13
if ( V_1 == V_34 )
V_43 = sizeof( struct V_62 ) ;
else
#endif
V_43 = F_33 ( V_3 ) ;
switch ( V_3 -> V_51 ) {
case V_57 :
V_3 -> V_58 = F_26 ( V_3 , V_43 , V_3 -> V_19 - V_43 , 0 ) ;
case V_55 :
#ifdef F_13
if ( V_1 == V_34 ) {
if ( F_27 ( & F_34 ( V_3 ) -> V_63 ,
& F_34 ( V_3 ) -> V_25 ,
V_3 -> V_19 - V_43 ,
F_34 ( V_3 ) -> V_64 ,
V_3 -> V_58 ) ) {
F_35 ( 0 , V_1 , V_41 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_28 ( F_36 ( V_3 ) -> V_63 ,
F_36 ( V_3 ) -> V_25 ,
V_3 -> V_19 - V_43 ,
F_36 ( V_3 ) -> V_24 ,
V_3 -> V_58 ) ) {
F_35 ( 0 , V_1 , V_41 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
break;
default:
break;
}
return 1 ;
}
static const char * F_37 ( int V_65 )
{
if ( V_65 >= V_66 )
return L_3 ;
return V_67 [ V_65 ] ? V_67 [ V_65 ] : L_4 ;
}
static void F_38 ( struct V_4 * V_5 , int V_68 )
{
int V_69 = ( V_68 & 1 ) ;
V_5 -> V_70 = ( V_69 ? V_71 : V_72 ) ;
}
static inline int F_39 ( struct V_14 * V_16 )
{
if ( V_16 -> V_22 )
return 3 ;
if ( V_16 -> V_21 )
return 0 ;
if ( V_16 -> V_73 )
return 1 ;
if ( V_16 -> V_74 )
return 2 ;
return - 1 ;
}
static inline void
F_40 ( struct V_4 * V_5 , struct V_7 * V_42 ,
int V_75 , struct V_14 * V_16 )
{
int V_76 ;
int V_77 = V_78 ;
int V_79 = V_80 [ V_75 ] ;
if ( V_42 -> V_68 & V_81 ) {
if ( V_79 == V_82 )
V_42 -> V_68 &= ~ V_81 ;
else
V_79 = V_83 ;
}
if ( ( V_76 = F_39 ( V_16 ) ) < 0 ) {
F_29 ( 8 , L_5 , V_76 ) ;
goto V_84;
}
V_77 =
V_5 -> V_70 [ V_79 + V_76 ] . V_85 [ V_42 -> V_65 ] ;
V_84:
if ( V_77 != V_42 -> V_65 ) {
struct V_86 * V_26 = V_42 -> V_26 ;
F_41 ( 8 , L_6
L_7 ,
V_5 -> V_41 -> V_61 ,
( ( V_79 == V_82 ) ?
L_8 : L_9 ) ,
V_16 -> V_21 ? 'S' : '.' ,
V_16 -> V_73 ? 'F' : '.' ,
V_16 -> V_74 ? 'A' : '.' ,
V_16 -> V_22 ? 'R' : '.' ,
F_42 ( V_42 -> V_87 , & V_42 -> V_25 ) ,
F_43 ( V_42 -> V_54 ) ,
F_42 ( V_42 -> V_1 , & V_42 -> V_60 ) ,
F_43 ( V_42 -> V_88 ) ,
F_37 ( V_42 -> V_65 ) ,
F_37 ( V_77 ) ,
F_44 ( & V_42 -> V_89 ) ) ;
if ( V_26 ) {
if ( ! ( V_42 -> V_68 & V_90 ) &&
( V_77 != V_91 ) ) {
F_45 ( & V_26 -> V_92 ) ;
F_46 ( & V_26 -> V_93 ) ;
V_42 -> V_68 |= V_90 ;
} else if ( ( V_42 -> V_68 & V_90 ) &&
( V_77 == V_91 ) ) {
F_46 ( & V_26 -> V_92 ) ;
F_45 ( & V_26 -> V_93 ) ;
V_42 -> V_68 &= ~ V_90 ;
}
}
}
if ( F_47 ( V_5 ) )
V_42 -> V_94 = V_5 -> V_95 [ V_42 -> V_65 = V_77 ] ;
else
V_42 -> V_94 = V_96 [ V_42 -> V_65 = V_77 ] ;
}
static void
F_48 ( struct V_7 * V_42 , int V_75 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_14 V_15 , * V_16 ;
#ifdef F_13
int V_97 = V_42 -> V_1 == V_98 ? F_33 ( V_3 ) : sizeof( struct V_62 ) ;
#else
int V_97 = F_33 ( V_3 ) ;
#endif
V_16 = F_2 ( V_3 , V_97 , sizeof( V_15 ) , & V_15 ) ;
if ( V_16 == NULL )
return;
F_49 ( & V_42 -> V_99 ) ;
F_40 ( V_5 , V_42 , V_75 , V_16 ) ;
F_50 ( & V_42 -> V_99 ) ;
}
static inline T_2 F_51 ( T_1 V_100 )
{
return ( ( ( V_101 V_102 ) V_100 >> V_103 ) ^ ( V_101 V_102 ) V_100 )
& V_104 ;
}
static int F_52 ( struct V_11 * V_11 , struct V_105 * V_106 )
{
struct V_105 * V_107 ;
T_2 V_108 ;
T_1 V_100 = V_106 -> V_100 ;
int V_47 = 0 ;
struct V_17 * V_18 = F_4 ( V_11 ) ;
struct V_4 * V_5 = F_53 ( V_11 , V_109 ) ;
V_108 = F_51 ( V_100 ) ;
F_54 (i, &ipvs->tcp_apps[hash], p_list) {
if ( V_107 -> V_100 == V_100 ) {
V_47 = - V_110 ;
goto V_111;
}
}
F_55 ( & V_106 -> V_112 , & V_18 -> V_113 [ V_108 ] ) ;
F_46 ( & V_5 -> V_114 ) ;
V_111:
return V_47 ;
}
static void
F_56 ( struct V_11 * V_11 , struct V_105 * V_106 )
{
struct V_4 * V_5 = F_53 ( V_11 , V_109 ) ;
F_45 ( & V_5 -> V_114 ) ;
F_57 ( & V_106 -> V_112 ) ;
}
static int
F_58 ( struct V_7 * V_42 )
{
struct V_17 * V_18 = F_4 ( F_59 ( V_42 ) ) ;
int V_108 ;
struct V_105 * V_106 ;
int V_115 = 0 ;
if ( F_60 ( V_42 ) != V_116 )
return 0 ;
V_108 = F_51 ( V_42 -> V_50 ) ;
F_5 () ;
F_61 (inc, &ipvs->tcp_apps[hash], p_list) {
if ( V_106 -> V_100 == V_42 -> V_50 ) {
if ( F_22 ( ! F_62 ( V_106 ) ) )
break;
F_9 () ;
F_41 ( 9 , L_10
L_11 ,
V_117 ,
F_42 ( V_42 -> V_1 , & V_42 -> V_60 ) ,
F_43 ( V_42 -> V_88 ) ,
F_42 ( V_42 -> V_1 , & V_42 -> V_53 ) ,
F_43 ( V_42 -> V_50 ) ,
V_106 -> V_61 , F_43 ( V_106 -> V_100 ) ) ;
V_42 -> V_46 = V_106 ;
if ( V_106 -> V_118 )
V_115 = V_106 -> V_118 ( V_106 , V_42 ) ;
goto V_111;
}
}
F_9 () ;
V_111:
return V_115 ;
}
void F_63 ( struct V_11 * V_11 , struct V_7 * V_42 )
{
struct V_4 * V_5 = F_53 ( V_11 , V_109 ) ;
F_49 ( & V_42 -> V_99 ) ;
V_42 -> V_65 = V_119 ;
V_42 -> V_94 = ( V_5 ? V_5 -> V_95 [ V_119 ]
: V_96 [ V_119 ] ) ;
F_50 ( & V_42 -> V_99 ) ;
}
static int F_64 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_17 * V_18 = F_4 ( V_11 ) ;
F_65 ( V_18 -> V_113 , V_120 ) ;
V_5 -> V_95 = F_66 ( ( int * ) V_96 ,
sizeof( V_96 ) ) ;
if ( ! V_5 -> V_95 )
return - V_121 ;
V_5 -> V_70 = V_72 ;
return 0 ;
}
static void F_67 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_68 ( V_5 -> V_95 ) ;
}
