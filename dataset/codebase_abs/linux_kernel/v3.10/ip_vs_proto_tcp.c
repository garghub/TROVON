static int
F_1 ( int V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int * V_6 , struct V_7 * * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 ;
struct V_12 * V_13 ;
struct V_14 V_15 , * V_16 ;
V_16 = F_2 ( V_3 , V_10 -> V_17 , sizeof( V_15 ) , & V_15 ) ;
if ( V_16 == NULL ) {
* V_6 = V_18 ;
return 0 ;
}
V_11 = F_3 ( V_3 ) ;
F_4 () ;
if ( V_16 -> V_19 &&
( V_13 = F_5 ( V_11 , V_1 , V_3 -> V_20 , V_10 -> V_21 ,
& V_10 -> V_22 , V_16 -> V_23 ) ) ) {
int V_24 ;
if ( F_6 ( F_7 ( V_11 ) ) ) {
F_8 () ;
* V_6 = V_18 ;
return 0 ;
}
* V_8 = F_9 ( V_13 , V_3 , V_5 , & V_24 , V_10 ) ;
if ( ! * V_8 && V_24 <= 0 ) {
if ( ! V_24 )
* V_6 = F_10 ( V_13 , V_3 , V_5 , V_10 ) ;
else
* V_6 = V_18 ;
F_8 () ;
return 0 ;
}
}
F_8 () ;
return 1 ;
}
static inline void
F_11 ( int V_1 , struct V_14 * V_25 ,
const union V_26 * V_27 ,
const union V_26 * V_28 ,
T_1 V_29 , T_1 V_30 )
{
#ifdef F_12
if ( V_1 == V_31 )
V_25 -> V_32 =
F_13 ( F_14 ( V_27 -> V_33 , V_28 -> V_33 ,
F_15 ( V_29 , V_30 ,
~ F_16 ( V_25 -> V_32 ) ) ) ) ;
else
#endif
V_25 -> V_32 =
F_13 ( F_17 ( V_27 -> V_34 , V_28 -> V_34 ,
F_15 ( V_29 , V_30 ,
~ F_16 ( V_25 -> V_32 ) ) ) ) ;
}
static inline void
F_18 ( int V_1 , struct V_14 * V_25 ,
const union V_26 * V_27 ,
const union V_26 * V_28 ,
T_1 V_35 , T_1 V_36 )
{
#ifdef F_12
if ( V_1 == V_31 )
V_25 -> V_32 =
~ F_13 ( F_14 ( V_27 -> V_33 , V_28 -> V_33 ,
F_15 ( V_35 , V_36 ,
F_16 ( V_25 -> V_32 ) ) ) ) ;
else
#endif
V_25 -> V_32 =
~ F_13 ( F_17 ( V_27 -> V_34 , V_28 -> V_34 ,
F_15 ( V_35 , V_36 ,
F_16 ( V_25 -> V_32 ) ) ) ) ;
}
static int
F_19 ( struct V_2 * V_3 , struct V_37 * V_38 ,
struct V_7 * V_39 , struct V_9 * V_10 )
{
struct V_14 * V_25 ;
unsigned int V_40 = V_10 -> V_17 ;
int V_35 ;
int V_41 = 0 ;
#ifdef F_12
if ( V_39 -> V_1 == V_31 && V_10 -> V_42 )
return 1 ;
#endif
V_35 = V_3 -> V_17 - V_40 ;
if ( ! F_20 ( V_3 , V_40 + sizeof( * V_25 ) ) )
return 0 ;
if ( F_21 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_44 = F_22 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_44 == 1 )
V_35 = V_3 -> V_17 - V_40 ;
else
V_41 = 1 ;
}
V_25 = ( void * ) F_23 ( V_3 ) + V_40 ;
V_25 -> V_46 = V_39 -> V_47 ;
if ( V_3 -> V_48 == V_49 ) {
F_18 ( V_39 -> V_1 , V_25 , & V_39 -> V_22 , & V_39 -> V_50 ,
F_24 ( V_35 ) ,
F_24 ( V_3 -> V_17 - V_40 ) ) ;
} else if ( ! V_41 ) {
F_11 ( V_39 -> V_1 , V_25 , & V_39 -> V_22 , & V_39 -> V_50 ,
V_39 -> V_51 , V_39 -> V_47 ) ;
if ( V_3 -> V_48 == V_52 )
V_3 -> V_48 = ( V_39 -> V_43 && V_38 -> V_45 ) ?
V_53 : V_54 ;
} else {
V_25 -> V_32 = 0 ;
V_3 -> V_55 = F_25 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
#ifdef F_12
if ( V_39 -> V_1 == V_31 )
V_25 -> V_32 = F_26 ( & V_39 -> V_50 . V_56 ,
& V_39 -> V_57 . V_56 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 , V_3 -> V_55 ) ;
else
#endif
V_25 -> V_32 = F_27 ( V_39 -> V_50 . V_34 ,
V_39 -> V_57 . V_34 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 ,
V_3 -> V_55 ) ;
V_3 -> V_48 = V_53 ;
F_28 ( 11 , L_1 ,
V_38 -> V_58 , V_25 -> V_32 ,
( char * ) & ( V_25 -> V_32 ) - ( char * ) V_25 ) ;
}
return 1 ;
}
static int
F_29 ( struct V_2 * V_3 , struct V_37 * V_38 ,
struct V_7 * V_39 , struct V_9 * V_10 )
{
struct V_14 * V_25 ;
unsigned int V_40 = V_10 -> V_17 ;
int V_35 ;
int V_41 = 0 ;
#ifdef F_12
if ( V_39 -> V_1 == V_31 && V_10 -> V_42 )
return 1 ;
#endif
V_35 = V_3 -> V_17 - V_40 ;
if ( ! F_20 ( V_3 , V_40 + sizeof( * V_25 ) ) )
return 0 ;
if ( F_21 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_44 = F_30 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_44 == 1 )
V_35 = V_3 -> V_17 - V_40 ;
else
V_41 = 1 ;
}
V_25 = ( void * ) F_23 ( V_3 ) + V_40 ;
V_25 -> V_23 = V_39 -> V_51 ;
if ( V_3 -> V_48 == V_49 ) {
F_18 ( V_39 -> V_1 , V_25 , & V_39 -> V_50 , & V_39 -> V_22 ,
F_24 ( V_35 ) ,
F_24 ( V_3 -> V_17 - V_40 ) ) ;
} else if ( ! V_41 ) {
F_11 ( V_39 -> V_1 , V_25 , & V_39 -> V_50 , & V_39 -> V_22 ,
V_39 -> V_47 , V_39 -> V_51 ) ;
if ( V_3 -> V_48 == V_52 )
V_3 -> V_48 = ( V_39 -> V_43 && V_38 -> V_45 ) ?
V_53 : V_54 ;
} else {
V_25 -> V_32 = 0 ;
V_3 -> V_55 = F_25 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
#ifdef F_12
if ( V_39 -> V_1 == V_31 )
V_25 -> V_32 = F_26 ( & V_39 -> V_57 . V_56 ,
& V_39 -> V_22 . V_56 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 , V_3 -> V_55 ) ;
else
#endif
V_25 -> V_32 = F_27 ( V_39 -> V_57 . V_34 ,
V_39 -> V_22 . V_34 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 ,
V_3 -> V_55 ) ;
V_3 -> V_48 = V_53 ;
}
return 1 ;
}
static int
F_31 ( int V_1 , struct V_2 * V_3 , struct V_37 * V_38 )
{
unsigned int V_40 ;
#ifdef F_12
if ( V_1 == V_31 )
V_40 = sizeof( struct V_59 ) ;
else
#endif
V_40 = F_32 ( V_3 ) ;
switch ( V_3 -> V_48 ) {
case V_54 :
V_3 -> V_55 = F_25 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
case V_52 :
#ifdef F_12
if ( V_1 == V_31 ) {
if ( F_26 ( & F_33 ( V_3 ) -> V_60 ,
& F_33 ( V_3 ) -> V_22 ,
V_3 -> V_17 - V_40 ,
F_33 ( V_3 ) -> V_61 ,
V_3 -> V_55 ) ) {
F_34 ( 0 , V_1 , V_38 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_27 ( F_35 ( V_3 ) -> V_60 ,
F_35 ( V_3 ) -> V_22 ,
V_3 -> V_17 - V_40 ,
F_35 ( V_3 ) -> V_21 ,
V_3 -> V_55 ) ) {
F_34 ( 0 , V_1 , V_38 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
break;
default:
break;
}
return 1 ;
}
static const char * F_36 ( int V_62 )
{
if ( V_62 >= V_63 )
return L_3 ;
return V_64 [ V_62 ] ? V_64 [ V_62 ] : L_4 ;
}
static void F_37 ( struct V_4 * V_5 , int V_65 )
{
int V_66 = ( V_65 & 1 ) ;
V_5 -> V_67 = ( V_66 ? V_68 : V_69 ) ;
}
static inline int F_38 ( struct V_14 * V_16 )
{
if ( V_16 -> V_70 )
return 3 ;
if ( V_16 -> V_19 )
return 0 ;
if ( V_16 -> V_71 )
return 1 ;
if ( V_16 -> V_72 )
return 2 ;
return - 1 ;
}
static inline void
F_39 ( struct V_4 * V_5 , struct V_7 * V_39 ,
int V_73 , struct V_14 * V_16 )
{
int V_74 ;
int V_75 = V_76 ;
int V_77 = V_78 [ V_73 ] ;
if ( V_39 -> V_65 & V_79 ) {
if ( V_77 == V_80 )
V_39 -> V_65 &= ~ V_79 ;
else
V_77 = V_81 ;
}
if ( ( V_74 = F_38 ( V_16 ) ) < 0 ) {
F_28 ( 8 , L_5 , V_74 ) ;
goto V_82;
}
V_75 =
V_5 -> V_67 [ V_77 + V_74 ] . V_83 [ V_39 -> V_62 ] ;
V_82:
if ( V_75 != V_39 -> V_62 ) {
struct V_84 * V_23 = V_39 -> V_23 ;
F_40 ( 8 , L_6
L_7 ,
V_5 -> V_38 -> V_58 ,
( ( V_77 == V_80 ) ?
L_8 : L_9 ) ,
V_16 -> V_19 ? 'S' : '.' ,
V_16 -> V_71 ? 'F' : '.' ,
V_16 -> V_72 ? 'A' : '.' ,
V_16 -> V_70 ? 'R' : '.' ,
F_41 ( V_39 -> V_1 , & V_39 -> V_22 ) ,
F_42 ( V_39 -> V_51 ) ,
F_41 ( V_39 -> V_1 , & V_39 -> V_57 ) ,
F_42 ( V_39 -> V_85 ) ,
F_36 ( V_39 -> V_62 ) ,
F_36 ( V_75 ) ,
F_43 ( & V_39 -> V_86 ) ) ;
if ( V_23 ) {
if ( ! ( V_39 -> V_65 & V_87 ) &&
( V_75 != V_88 ) ) {
F_44 ( & V_23 -> V_89 ) ;
F_45 ( & V_23 -> V_90 ) ;
V_39 -> V_65 |= V_87 ;
} else if ( ( V_39 -> V_65 & V_87 ) &&
( V_75 == V_88 ) ) {
F_45 ( & V_23 -> V_89 ) ;
F_44 ( & V_23 -> V_90 ) ;
V_39 -> V_65 &= ~ V_87 ;
}
}
}
if ( F_46 ( V_5 ) )
V_39 -> V_91 = V_5 -> V_92 [ V_39 -> V_62 = V_75 ] ;
else
V_39 -> V_91 = V_93 [ V_39 -> V_62 = V_75 ] ;
}
static void
F_47 ( struct V_7 * V_39 , int V_73 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_14 V_15 , * V_16 ;
#ifdef F_12
int V_94 = V_39 -> V_1 == V_95 ? F_32 ( V_3 ) : sizeof( struct V_59 ) ;
#else
int V_94 = F_32 ( V_3 ) ;
#endif
V_16 = F_2 ( V_3 , V_94 , sizeof( V_15 ) , & V_15 ) ;
if ( V_16 == NULL )
return;
F_48 ( & V_39 -> V_96 ) ;
F_39 ( V_5 , V_39 , V_73 , V_16 ) ;
F_49 ( & V_39 -> V_96 ) ;
}
static inline T_2 F_50 ( T_1 V_97 )
{
return ( ( ( V_98 V_99 ) V_97 >> V_100 ) ^ ( V_98 V_99 ) V_97 )
& V_101 ;
}
static int F_51 ( struct V_11 * V_11 , struct V_102 * V_103 )
{
struct V_102 * V_104 ;
T_2 V_105 ;
T_1 V_97 = V_103 -> V_97 ;
int V_44 = 0 ;
struct V_106 * V_107 = F_7 ( V_11 ) ;
struct V_4 * V_5 = F_52 ( V_11 , V_108 ) ;
V_105 = F_50 ( V_97 ) ;
F_53 (i, &ipvs->tcp_apps[hash], p_list) {
if ( V_104 -> V_97 == V_97 ) {
V_44 = - V_109 ;
goto V_110;
}
}
F_54 ( & V_103 -> V_111 , & V_107 -> V_112 [ V_105 ] ) ;
F_45 ( & V_5 -> V_113 ) ;
V_110:
return V_44 ;
}
static void
F_55 ( struct V_11 * V_11 , struct V_102 * V_103 )
{
struct V_4 * V_5 = F_52 ( V_11 , V_108 ) ;
F_44 ( & V_5 -> V_113 ) ;
F_56 ( & V_103 -> V_111 ) ;
}
static int
F_57 ( struct V_7 * V_39 )
{
struct V_106 * V_107 = F_7 ( F_58 ( V_39 ) ) ;
int V_105 ;
struct V_102 * V_103 ;
int V_114 = 0 ;
if ( F_59 ( V_39 ) != V_115 )
return 0 ;
V_105 = F_50 ( V_39 -> V_47 ) ;
F_4 () ;
F_60 (inc, &ipvs->tcp_apps[hash], p_list) {
if ( V_103 -> V_97 == V_39 -> V_47 ) {
if ( F_21 ( ! F_61 ( V_103 ) ) )
break;
F_8 () ;
F_40 ( 9 , L_10
L_11 ,
V_116 ,
F_41 ( V_39 -> V_1 , & V_39 -> V_57 ) ,
F_42 ( V_39 -> V_85 ) ,
F_41 ( V_39 -> V_1 , & V_39 -> V_50 ) ,
F_42 ( V_39 -> V_47 ) ,
V_103 -> V_58 , F_42 ( V_103 -> V_97 ) ) ;
V_39 -> V_43 = V_103 ;
if ( V_103 -> V_117 )
V_114 = V_103 -> V_117 ( V_103 , V_39 ) ;
goto V_110;
}
}
F_8 () ;
V_110:
return V_114 ;
}
void F_62 ( struct V_11 * V_11 , struct V_7 * V_39 )
{
struct V_4 * V_5 = F_52 ( V_11 , V_108 ) ;
F_48 ( & V_39 -> V_96 ) ;
V_39 -> V_62 = V_118 ;
V_39 -> V_91 = ( V_5 ? V_5 -> V_92 [ V_118 ]
: V_93 [ V_118 ] ) ;
F_49 ( & V_39 -> V_96 ) ;
}
static int F_63 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_106 * V_107 = F_7 ( V_11 ) ;
F_64 ( V_107 -> V_112 , V_119 ) ;
V_5 -> V_92 = F_65 ( ( int * ) V_93 ,
sizeof( V_93 ) ) ;
if ( ! V_5 -> V_92 )
return - V_120 ;
V_5 -> V_67 = V_69 ;
return 0 ;
}
static void F_66 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_67 ( V_5 -> V_92 ) ;
}
