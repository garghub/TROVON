static int
F_1 ( int V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int * V_6 , struct V_7 * * V_8 )
{
struct V_9 * V_9 ;
struct V_10 * V_11 ;
struct V_12 V_13 , * V_14 ;
struct V_15 V_16 ;
F_2 ( V_1 , F_3 ( V_3 ) , & V_16 ) ;
V_14 = F_4 ( V_3 , V_16 . V_17 , sizeof( V_13 ) , & V_13 ) ;
if ( V_14 == NULL ) {
* V_6 = V_18 ;
return 0 ;
}
V_9 = F_5 ( V_3 ) ;
if ( V_14 -> V_19 &&
( V_11 = F_6 ( V_9 , V_1 , V_3 -> V_20 , V_16 . V_21 ,
& V_16 . V_22 , V_14 -> V_23 ) ) ) {
int V_24 ;
if ( F_7 ( F_8 ( V_9 ) ) ) {
F_9 ( V_11 ) ;
* V_6 = V_18 ;
return 0 ;
}
* V_8 = F_10 ( V_11 , V_3 , V_5 , & V_24 ) ;
if ( ! * V_8 && V_24 <= 0 ) {
if ( ! V_24 )
* V_6 = F_11 ( V_11 , V_3 , V_5 ) ;
else {
F_9 ( V_11 ) ;
* V_6 = V_18 ;
}
return 0 ;
}
F_9 ( V_11 ) ;
}
return 1 ;
}
static inline void
F_12 ( int V_1 , struct V_12 * V_25 ,
const union V_26 * V_27 ,
const union V_26 * V_28 ,
T_1 V_29 , T_1 V_30 )
{
#ifdef F_13
if ( V_1 == V_31 )
V_25 -> V_32 =
F_14 ( F_15 ( V_27 -> V_33 , V_28 -> V_33 ,
F_16 ( V_29 , V_30 ,
~ F_17 ( V_25 -> V_32 ) ) ) ) ;
else
#endif
V_25 -> V_32 =
F_14 ( F_18 ( V_27 -> V_34 , V_28 -> V_34 ,
F_16 ( V_29 , V_30 ,
~ F_17 ( V_25 -> V_32 ) ) ) ) ;
}
static inline void
F_19 ( int V_1 , struct V_12 * V_25 ,
const union V_26 * V_27 ,
const union V_26 * V_28 ,
T_1 V_35 , T_1 V_36 )
{
#ifdef F_13
if ( V_1 == V_31 )
V_25 -> V_32 =
~ F_14 ( F_15 ( V_27 -> V_33 , V_28 -> V_33 ,
F_16 ( V_35 , V_36 ,
F_17 ( V_25 -> V_32 ) ) ) ) ;
else
#endif
V_25 -> V_32 =
~ F_14 ( F_18 ( V_27 -> V_34 , V_28 -> V_34 ,
F_16 ( V_35 , V_36 ,
F_17 ( V_25 -> V_32 ) ) ) ) ;
}
static int
F_20 ( struct V_2 * V_3 ,
struct V_37 * V_38 , struct V_7 * V_39 )
{
struct V_12 * V_25 ;
unsigned int V_40 ;
int V_35 ;
int V_41 = 0 ;
#ifdef F_13
if ( V_39 -> V_1 == V_31 )
V_40 = sizeof( struct V_42 ) ;
else
#endif
V_40 = F_21 ( V_3 ) ;
V_35 = V_3 -> V_17 - V_40 ;
if ( ! F_22 ( V_3 , V_40 + sizeof( * V_25 ) ) )
return 0 ;
if ( F_23 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_44 = F_24 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_44 == 1 )
V_35 = V_3 -> V_17 - V_40 ;
else
V_41 = 1 ;
}
V_25 = ( void * ) F_3 ( V_3 ) + V_40 ;
V_25 -> V_46 = V_39 -> V_47 ;
if ( V_3 -> V_48 == V_49 ) {
F_19 ( V_39 -> V_1 , V_25 , & V_39 -> V_22 , & V_39 -> V_50 ,
F_25 ( V_35 ) ,
F_25 ( V_3 -> V_17 - V_40 ) ) ;
} else if ( ! V_41 ) {
F_12 ( V_39 -> V_1 , V_25 , & V_39 -> V_22 , & V_39 -> V_50 ,
V_39 -> V_51 , V_39 -> V_47 ) ;
if ( V_3 -> V_48 == V_52 )
V_3 -> V_48 = ( V_39 -> V_43 && V_38 -> V_45 ) ?
V_53 : V_54 ;
} else {
V_25 -> V_32 = 0 ;
V_3 -> V_55 = F_26 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
#ifdef F_13
if ( V_39 -> V_1 == V_31 )
V_25 -> V_32 = F_27 ( & V_39 -> V_50 . V_56 ,
& V_39 -> V_57 . V_56 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 , V_3 -> V_55 ) ;
else
#endif
V_25 -> V_32 = F_28 ( V_39 -> V_50 . V_34 ,
V_39 -> V_57 . V_34 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 ,
V_3 -> V_55 ) ;
V_3 -> V_48 = V_53 ;
F_29 ( 11 , L_1 ,
V_38 -> V_58 , V_25 -> V_32 ,
( char * ) & ( V_25 -> V_32 ) - ( char * ) V_25 ) ;
}
return 1 ;
}
static int
F_30 ( struct V_2 * V_3 ,
struct V_37 * V_38 , struct V_7 * V_39 )
{
struct V_12 * V_25 ;
unsigned int V_40 ;
int V_35 ;
int V_41 = 0 ;
#ifdef F_13
if ( V_39 -> V_1 == V_31 )
V_40 = sizeof( struct V_42 ) ;
else
#endif
V_40 = F_21 ( V_3 ) ;
V_35 = V_3 -> V_17 - V_40 ;
if ( ! F_22 ( V_3 , V_40 + sizeof( * V_25 ) ) )
return 0 ;
if ( F_23 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_44 = F_31 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_44 == 1 )
V_35 = V_3 -> V_17 - V_40 ;
else
V_41 = 1 ;
}
V_25 = ( void * ) F_3 ( V_3 ) + V_40 ;
V_25 -> V_23 = V_39 -> V_51 ;
if ( V_3 -> V_48 == V_49 ) {
F_19 ( V_39 -> V_1 , V_25 , & V_39 -> V_50 , & V_39 -> V_22 ,
F_25 ( V_35 ) ,
F_25 ( V_3 -> V_17 - V_40 ) ) ;
} else if ( ! V_41 ) {
F_12 ( V_39 -> V_1 , V_25 , & V_39 -> V_50 , & V_39 -> V_22 ,
V_39 -> V_47 , V_39 -> V_51 ) ;
if ( V_3 -> V_48 == V_52 )
V_3 -> V_48 = ( V_39 -> V_43 && V_38 -> V_45 ) ?
V_53 : V_54 ;
} else {
V_25 -> V_32 = 0 ;
V_3 -> V_55 = F_26 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
#ifdef F_13
if ( V_39 -> V_1 == V_31 )
V_25 -> V_32 = F_27 ( & V_39 -> V_57 . V_56 ,
& V_39 -> V_22 . V_56 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 , V_3 -> V_55 ) ;
else
#endif
V_25 -> V_32 = F_28 ( V_39 -> V_57 . V_34 ,
V_39 -> V_22 . V_34 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 ,
V_3 -> V_55 ) ;
V_3 -> V_48 = V_53 ;
}
return 1 ;
}
static int
F_32 ( int V_1 , struct V_2 * V_3 , struct V_37 * V_38 )
{
unsigned int V_40 ;
#ifdef F_13
if ( V_1 == V_31 )
V_40 = sizeof( struct V_42 ) ;
else
#endif
V_40 = F_21 ( V_3 ) ;
switch ( V_3 -> V_48 ) {
case V_54 :
V_3 -> V_55 = F_26 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
case V_52 :
#ifdef F_13
if ( V_1 == V_31 ) {
if ( F_27 ( & F_33 ( V_3 ) -> V_59 ,
& F_33 ( V_3 ) -> V_22 ,
V_3 -> V_17 - V_40 ,
F_33 ( V_3 ) -> V_60 ,
V_3 -> V_55 ) ) {
F_34 ( 0 , V_1 , V_38 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_28 ( F_35 ( V_3 ) -> V_59 ,
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
static const char * F_36 ( int V_61 )
{
if ( V_61 >= V_62 )
return L_3 ;
return V_63 [ V_61 ] ? V_63 [ V_61 ] : L_4 ;
}
static void F_37 ( struct V_4 * V_5 , int V_64 )
{
int V_65 = ( V_64 & 1 ) ;
V_5 -> V_66 = ( V_65 ? V_67 : V_68 ) ;
}
static inline int F_38 ( struct V_12 * V_14 )
{
if ( V_14 -> V_69 )
return 3 ;
if ( V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_70 )
return 1 ;
if ( V_14 -> V_71 )
return 2 ;
return - 1 ;
}
static inline void
F_39 ( struct V_4 * V_5 , struct V_7 * V_39 ,
int V_72 , struct V_12 * V_14 )
{
int V_73 ;
int V_74 = V_75 ;
int V_76 = V_77 [ V_72 ] ;
if ( V_39 -> V_64 & V_78 ) {
if ( V_76 == V_79 )
V_39 -> V_64 &= ~ V_78 ;
else
V_76 = V_80 ;
}
if ( ( V_73 = F_38 ( V_14 ) ) < 0 ) {
F_29 ( 8 , L_5 , V_73 ) ;
goto V_81;
}
V_74 =
V_5 -> V_66 [ V_76 + V_73 ] . V_82 [ V_39 -> V_61 ] ;
V_81:
if ( V_74 != V_39 -> V_61 ) {
struct V_83 * V_23 = V_39 -> V_23 ;
F_40 ( 8 , L_6
L_7 ,
V_5 -> V_38 -> V_58 ,
( ( V_76 == V_79 ) ?
L_8 : L_9 ) ,
V_14 -> V_19 ? 'S' : '.' ,
V_14 -> V_70 ? 'F' : '.' ,
V_14 -> V_71 ? 'A' : '.' ,
V_14 -> V_69 ? 'R' : '.' ,
F_41 ( V_39 -> V_1 , & V_39 -> V_22 ) ,
F_42 ( V_39 -> V_51 ) ,
F_41 ( V_39 -> V_1 , & V_39 -> V_57 ) ,
F_42 ( V_39 -> V_84 ) ,
F_36 ( V_39 -> V_61 ) ,
F_36 ( V_74 ) ,
F_43 ( & V_39 -> V_85 ) ) ;
if ( V_23 ) {
if ( ! ( V_39 -> V_64 & V_86 ) &&
( V_74 != V_87 ) ) {
F_44 ( & V_23 -> V_88 ) ;
F_45 ( & V_23 -> V_89 ) ;
V_39 -> V_64 |= V_86 ;
} else if ( ( V_39 -> V_64 & V_86 ) &&
( V_74 == V_87 ) ) {
F_45 ( & V_23 -> V_88 ) ;
F_44 ( & V_23 -> V_89 ) ;
V_39 -> V_64 &= ~ V_86 ;
}
}
}
if ( F_46 ( V_5 ) )
V_39 -> V_90 = V_5 -> V_91 [ V_39 -> V_61 = V_74 ] ;
else
V_39 -> V_90 = V_92 [ V_39 -> V_61 = V_74 ] ;
}
static void
F_47 ( struct V_7 * V_39 , int V_72 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_12 V_13 , * V_14 ;
#ifdef F_13
int V_93 = V_39 -> V_1 == V_94 ? F_21 ( V_3 ) : sizeof( struct V_42 ) ;
#else
int V_93 = F_21 ( V_3 ) ;
#endif
V_14 = F_4 ( V_3 , V_93 , sizeof( V_13 ) , & V_13 ) ;
if ( V_14 == NULL )
return;
F_48 ( & V_39 -> V_95 ) ;
F_39 ( V_5 , V_39 , V_72 , V_14 ) ;
F_49 ( & V_39 -> V_95 ) ;
}
static inline T_2 F_50 ( T_1 V_96 )
{
return ( ( ( V_97 V_98 ) V_96 >> V_99 ) ^ ( V_97 V_98 ) V_96 )
& V_100 ;
}
static int F_51 ( struct V_9 * V_9 , struct V_101 * V_102 )
{
struct V_101 * V_103 ;
T_2 V_104 ;
T_1 V_96 = V_102 -> V_96 ;
int V_44 = 0 ;
struct V_105 * V_106 = F_8 ( V_9 ) ;
struct V_4 * V_5 = F_52 ( V_9 , V_107 ) ;
V_104 = F_50 ( V_96 ) ;
F_53 ( & V_106 -> V_108 ) ;
F_54 (i, &ipvs->tcp_apps[hash], p_list) {
if ( V_103 -> V_96 == V_96 ) {
V_44 = - V_109 ;
goto V_110;
}
}
F_55 ( & V_102 -> V_111 , & V_106 -> V_112 [ V_104 ] ) ;
F_45 ( & V_5 -> V_113 ) ;
V_110:
F_56 ( & V_106 -> V_108 ) ;
return V_44 ;
}
static void
F_57 ( struct V_9 * V_9 , struct V_101 * V_102 )
{
struct V_105 * V_106 = F_8 ( V_9 ) ;
struct V_4 * V_5 = F_52 ( V_9 , V_107 ) ;
F_53 ( & V_106 -> V_108 ) ;
F_44 ( & V_5 -> V_113 ) ;
F_58 ( & V_102 -> V_111 ) ;
F_56 ( & V_106 -> V_108 ) ;
}
static int
F_59 ( struct V_7 * V_39 )
{
struct V_105 * V_106 = F_8 ( F_60 ( V_39 ) ) ;
int V_104 ;
struct V_101 * V_102 ;
int V_114 = 0 ;
if ( F_61 ( V_39 ) != V_115 )
return 0 ;
V_104 = F_50 ( V_39 -> V_47 ) ;
F_48 ( & V_106 -> V_108 ) ;
F_54 (inc, &ipvs->tcp_apps[hash], p_list) {
if ( V_102 -> V_96 == V_39 -> V_47 ) {
if ( F_23 ( ! F_62 ( V_102 ) ) )
break;
F_49 ( & V_106 -> V_108 ) ;
F_40 ( 9 , L_10
L_11 ,
V_116 ,
F_41 ( V_39 -> V_1 , & V_39 -> V_57 ) ,
F_42 ( V_39 -> V_84 ) ,
F_41 ( V_39 -> V_1 , & V_39 -> V_50 ) ,
F_42 ( V_39 -> V_47 ) ,
V_102 -> V_58 , F_42 ( V_102 -> V_96 ) ) ;
V_39 -> V_43 = V_102 ;
if ( V_102 -> V_117 )
V_114 = V_102 -> V_117 ( V_102 , V_39 ) ;
goto V_110;
}
}
F_49 ( & V_106 -> V_108 ) ;
V_110:
return V_114 ;
}
void F_63 ( struct V_9 * V_9 , struct V_7 * V_39 )
{
struct V_4 * V_5 = F_52 ( V_9 , V_107 ) ;
F_48 ( & V_39 -> V_95 ) ;
V_39 -> V_61 = V_118 ;
V_39 -> V_90 = ( V_5 ? V_5 -> V_91 [ V_118 ]
: V_92 [ V_118 ] ) ;
F_49 ( & V_39 -> V_95 ) ;
}
static int F_64 ( struct V_9 * V_9 , struct V_4 * V_5 )
{
struct V_105 * V_106 = F_8 ( V_9 ) ;
F_65 ( V_106 -> V_112 , V_119 ) ;
F_66 ( & V_106 -> V_108 ) ;
V_5 -> V_91 = F_67 ( ( int * ) V_92 ,
sizeof( V_92 ) ) ;
if ( ! V_5 -> V_91 )
return - V_120 ;
V_5 -> V_66 = V_68 ;
return 0 ;
}
static void F_68 ( struct V_9 * V_9 , struct V_4 * V_5 )
{
F_69 ( V_5 -> V_91 ) ;
}
