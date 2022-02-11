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
if ( V_16 -> V_19 &&
( V_13 = F_4 ( V_11 , V_1 , V_3 -> V_20 , V_10 -> V_21 ,
& V_10 -> V_22 , V_16 -> V_23 ) ) ) {
int V_24 ;
if ( F_5 ( F_6 ( V_11 ) ) ) {
F_7 ( V_13 ) ;
* V_6 = V_18 ;
return 0 ;
}
* V_8 = F_8 ( V_13 , V_3 , V_5 , & V_24 , V_10 ) ;
if ( ! * V_8 && V_24 <= 0 ) {
if ( ! V_24 )
* V_6 = F_9 ( V_13 , V_3 , V_5 , V_10 ) ;
else {
F_7 ( V_13 ) ;
* V_6 = V_18 ;
}
return 0 ;
}
F_7 ( V_13 ) ;
}
return 1 ;
}
static inline void
F_10 ( int V_1 , struct V_14 * V_25 ,
const union V_26 * V_27 ,
const union V_26 * V_28 ,
T_1 V_29 , T_1 V_30 )
{
#ifdef F_11
if ( V_1 == V_31 )
V_25 -> V_32 =
F_12 ( F_13 ( V_27 -> V_33 , V_28 -> V_33 ,
F_14 ( V_29 , V_30 ,
~ F_15 ( V_25 -> V_32 ) ) ) ) ;
else
#endif
V_25 -> V_32 =
F_12 ( F_16 ( V_27 -> V_34 , V_28 -> V_34 ,
F_14 ( V_29 , V_30 ,
~ F_15 ( V_25 -> V_32 ) ) ) ) ;
}
static inline void
F_17 ( int V_1 , struct V_14 * V_25 ,
const union V_26 * V_27 ,
const union V_26 * V_28 ,
T_1 V_35 , T_1 V_36 )
{
#ifdef F_11
if ( V_1 == V_31 )
V_25 -> V_32 =
~ F_12 ( F_13 ( V_27 -> V_33 , V_28 -> V_33 ,
F_14 ( V_35 , V_36 ,
F_15 ( V_25 -> V_32 ) ) ) ) ;
else
#endif
V_25 -> V_32 =
~ F_12 ( F_16 ( V_27 -> V_34 , V_28 -> V_34 ,
F_14 ( V_35 , V_36 ,
F_15 ( V_25 -> V_32 ) ) ) ) ;
}
static int
F_18 ( struct V_2 * V_3 , struct V_37 * V_38 ,
struct V_7 * V_39 , struct V_9 * V_10 )
{
struct V_14 * V_25 ;
unsigned int V_40 = V_10 -> V_17 ;
int V_35 ;
int V_41 = 0 ;
#ifdef F_11
if ( V_39 -> V_1 == V_31 && V_10 -> V_42 )
return 1 ;
#endif
V_35 = V_3 -> V_17 - V_40 ;
if ( ! F_19 ( V_3 , V_40 + sizeof( * V_25 ) ) )
return 0 ;
if ( F_20 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_44 = F_21 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_44 == 1 )
V_35 = V_3 -> V_17 - V_40 ;
else
V_41 = 1 ;
}
V_25 = ( void * ) F_22 ( V_3 ) + V_40 ;
V_25 -> V_46 = V_39 -> V_47 ;
if ( V_3 -> V_48 == V_49 ) {
F_17 ( V_39 -> V_1 , V_25 , & V_39 -> V_22 , & V_39 -> V_50 ,
F_23 ( V_35 ) ,
F_23 ( V_3 -> V_17 - V_40 ) ) ;
} else if ( ! V_41 ) {
F_10 ( V_39 -> V_1 , V_25 , & V_39 -> V_22 , & V_39 -> V_50 ,
V_39 -> V_51 , V_39 -> V_47 ) ;
if ( V_3 -> V_48 == V_52 )
V_3 -> V_48 = ( V_39 -> V_43 && V_38 -> V_45 ) ?
V_53 : V_54 ;
} else {
V_25 -> V_32 = 0 ;
V_3 -> V_55 = F_24 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
#ifdef F_11
if ( V_39 -> V_1 == V_31 )
V_25 -> V_32 = F_25 ( & V_39 -> V_50 . V_56 ,
& V_39 -> V_57 . V_56 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 , V_3 -> V_55 ) ;
else
#endif
V_25 -> V_32 = F_26 ( V_39 -> V_50 . V_34 ,
V_39 -> V_57 . V_34 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 ,
V_3 -> V_55 ) ;
V_3 -> V_48 = V_53 ;
F_27 ( 11 , L_1 ,
V_38 -> V_58 , V_25 -> V_32 ,
( char * ) & ( V_25 -> V_32 ) - ( char * ) V_25 ) ;
}
return 1 ;
}
static int
F_28 ( struct V_2 * V_3 , struct V_37 * V_38 ,
struct V_7 * V_39 , struct V_9 * V_10 )
{
struct V_14 * V_25 ;
unsigned int V_40 = V_10 -> V_17 ;
int V_35 ;
int V_41 = 0 ;
#ifdef F_11
if ( V_39 -> V_1 == V_31 && V_10 -> V_42 )
return 1 ;
#endif
V_35 = V_3 -> V_17 - V_40 ;
if ( ! F_19 ( V_3 , V_40 + sizeof( * V_25 ) ) )
return 0 ;
if ( F_20 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_44 = F_29 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_44 == 1 )
V_35 = V_3 -> V_17 - V_40 ;
else
V_41 = 1 ;
}
V_25 = ( void * ) F_22 ( V_3 ) + V_40 ;
V_25 -> V_23 = V_39 -> V_51 ;
if ( V_3 -> V_48 == V_49 ) {
F_17 ( V_39 -> V_1 , V_25 , & V_39 -> V_50 , & V_39 -> V_22 ,
F_23 ( V_35 ) ,
F_23 ( V_3 -> V_17 - V_40 ) ) ;
} else if ( ! V_41 ) {
F_10 ( V_39 -> V_1 , V_25 , & V_39 -> V_50 , & V_39 -> V_22 ,
V_39 -> V_47 , V_39 -> V_51 ) ;
if ( V_3 -> V_48 == V_52 )
V_3 -> V_48 = ( V_39 -> V_43 && V_38 -> V_45 ) ?
V_53 : V_54 ;
} else {
V_25 -> V_32 = 0 ;
V_3 -> V_55 = F_24 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
#ifdef F_11
if ( V_39 -> V_1 == V_31 )
V_25 -> V_32 = F_25 ( & V_39 -> V_57 . V_56 ,
& V_39 -> V_22 . V_56 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 , V_3 -> V_55 ) ;
else
#endif
V_25 -> V_32 = F_26 ( V_39 -> V_57 . V_34 ,
V_39 -> V_22 . V_34 ,
V_3 -> V_17 - V_40 ,
V_39 -> V_21 ,
V_3 -> V_55 ) ;
V_3 -> V_48 = V_53 ;
}
return 1 ;
}
static int
F_30 ( int V_1 , struct V_2 * V_3 , struct V_37 * V_38 )
{
unsigned int V_40 ;
#ifdef F_11
if ( V_1 == V_31 )
V_40 = sizeof( struct V_59 ) ;
else
#endif
V_40 = F_31 ( V_3 ) ;
switch ( V_3 -> V_48 ) {
case V_54 :
V_3 -> V_55 = F_24 ( V_3 , V_40 , V_3 -> V_17 - V_40 , 0 ) ;
case V_52 :
#ifdef F_11
if ( V_1 == V_31 ) {
if ( F_25 ( & F_32 ( V_3 ) -> V_60 ,
& F_32 ( V_3 ) -> V_22 ,
V_3 -> V_17 - V_40 ,
F_32 ( V_3 ) -> V_61 ,
V_3 -> V_55 ) ) {
F_33 ( 0 , V_1 , V_38 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_26 ( F_34 ( V_3 ) -> V_60 ,
F_34 ( V_3 ) -> V_22 ,
V_3 -> V_17 - V_40 ,
F_34 ( V_3 ) -> V_21 ,
V_3 -> V_55 ) ) {
F_33 ( 0 , V_1 , V_38 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
break;
default:
break;
}
return 1 ;
}
static const char * F_35 ( int V_62 )
{
if ( V_62 >= V_63 )
return L_3 ;
return V_64 [ V_62 ] ? V_64 [ V_62 ] : L_4 ;
}
static void F_36 ( struct V_4 * V_5 , int V_65 )
{
int V_66 = ( V_65 & 1 ) ;
V_5 -> V_67 = ( V_66 ? V_68 : V_69 ) ;
}
static inline int F_37 ( struct V_14 * V_16 )
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
F_38 ( struct V_4 * V_5 , struct V_7 * V_39 ,
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
if ( ( V_74 = F_37 ( V_16 ) ) < 0 ) {
F_27 ( 8 , L_5 , V_74 ) ;
goto V_82;
}
V_75 =
V_5 -> V_67 [ V_77 + V_74 ] . V_83 [ V_39 -> V_62 ] ;
V_82:
if ( V_75 != V_39 -> V_62 ) {
struct V_84 * V_23 = V_39 -> V_23 ;
F_39 ( 8 , L_6
L_7 ,
V_5 -> V_38 -> V_58 ,
( ( V_77 == V_80 ) ?
L_8 : L_9 ) ,
V_16 -> V_19 ? 'S' : '.' ,
V_16 -> V_71 ? 'F' : '.' ,
V_16 -> V_72 ? 'A' : '.' ,
V_16 -> V_70 ? 'R' : '.' ,
F_40 ( V_39 -> V_1 , & V_39 -> V_22 ) ,
F_41 ( V_39 -> V_51 ) ,
F_40 ( V_39 -> V_1 , & V_39 -> V_57 ) ,
F_41 ( V_39 -> V_85 ) ,
F_35 ( V_39 -> V_62 ) ,
F_35 ( V_75 ) ,
F_42 ( & V_39 -> V_86 ) ) ;
if ( V_23 ) {
if ( ! ( V_39 -> V_65 & V_87 ) &&
( V_75 != V_88 ) ) {
F_43 ( & V_23 -> V_89 ) ;
F_44 ( & V_23 -> V_90 ) ;
V_39 -> V_65 |= V_87 ;
} else if ( ( V_39 -> V_65 & V_87 ) &&
( V_75 == V_88 ) ) {
F_44 ( & V_23 -> V_89 ) ;
F_43 ( & V_23 -> V_90 ) ;
V_39 -> V_65 &= ~ V_87 ;
}
}
}
if ( F_45 ( V_5 ) )
V_39 -> V_91 = V_5 -> V_92 [ V_39 -> V_62 = V_75 ] ;
else
V_39 -> V_91 = V_93 [ V_39 -> V_62 = V_75 ] ;
}
static void
F_46 ( struct V_7 * V_39 , int V_73 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_14 V_15 , * V_16 ;
#ifdef F_11
int V_94 = V_39 -> V_1 == V_95 ? F_31 ( V_3 ) : sizeof( struct V_59 ) ;
#else
int V_94 = F_31 ( V_3 ) ;
#endif
V_16 = F_2 ( V_3 , V_94 , sizeof( V_15 ) , & V_15 ) ;
if ( V_16 == NULL )
return;
F_47 ( & V_39 -> V_96 ) ;
F_38 ( V_5 , V_39 , V_73 , V_16 ) ;
F_48 ( & V_39 -> V_96 ) ;
}
static inline T_2 F_49 ( T_1 V_97 )
{
return ( ( ( V_98 V_99 ) V_97 >> V_100 ) ^ ( V_98 V_99 ) V_97 )
& V_101 ;
}
static int F_50 ( struct V_11 * V_11 , struct V_102 * V_103 )
{
struct V_102 * V_104 ;
T_2 V_105 ;
T_1 V_97 = V_103 -> V_97 ;
int V_44 = 0 ;
struct V_106 * V_107 = F_6 ( V_11 ) ;
struct V_4 * V_5 = F_51 ( V_11 , V_108 ) ;
V_105 = F_49 ( V_97 ) ;
F_52 ( & V_107 -> V_109 ) ;
F_53 (i, &ipvs->tcp_apps[hash], p_list) {
if ( V_104 -> V_97 == V_97 ) {
V_44 = - V_110 ;
goto V_111;
}
}
F_54 ( & V_103 -> V_112 , & V_107 -> V_113 [ V_105 ] ) ;
F_44 ( & V_5 -> V_114 ) ;
V_111:
F_55 ( & V_107 -> V_109 ) ;
return V_44 ;
}
static void
F_56 ( struct V_11 * V_11 , struct V_102 * V_103 )
{
struct V_106 * V_107 = F_6 ( V_11 ) ;
struct V_4 * V_5 = F_51 ( V_11 , V_108 ) ;
F_52 ( & V_107 -> V_109 ) ;
F_43 ( & V_5 -> V_114 ) ;
F_57 ( & V_103 -> V_112 ) ;
F_55 ( & V_107 -> V_109 ) ;
}
static int
F_58 ( struct V_7 * V_39 )
{
struct V_106 * V_107 = F_6 ( F_59 ( V_39 ) ) ;
int V_105 ;
struct V_102 * V_103 ;
int V_115 = 0 ;
if ( F_60 ( V_39 ) != V_116 )
return 0 ;
V_105 = F_49 ( V_39 -> V_47 ) ;
F_47 ( & V_107 -> V_109 ) ;
F_53 (inc, &ipvs->tcp_apps[hash], p_list) {
if ( V_103 -> V_97 == V_39 -> V_47 ) {
if ( F_20 ( ! F_61 ( V_103 ) ) )
break;
F_48 ( & V_107 -> V_109 ) ;
F_39 ( 9 , L_10
L_11 ,
V_117 ,
F_40 ( V_39 -> V_1 , & V_39 -> V_57 ) ,
F_41 ( V_39 -> V_85 ) ,
F_40 ( V_39 -> V_1 , & V_39 -> V_50 ) ,
F_41 ( V_39 -> V_47 ) ,
V_103 -> V_58 , F_41 ( V_103 -> V_97 ) ) ;
V_39 -> V_43 = V_103 ;
if ( V_103 -> V_118 )
V_115 = V_103 -> V_118 ( V_103 , V_39 ) ;
goto V_111;
}
}
F_48 ( & V_107 -> V_109 ) ;
V_111:
return V_115 ;
}
void F_62 ( struct V_11 * V_11 , struct V_7 * V_39 )
{
struct V_4 * V_5 = F_51 ( V_11 , V_108 ) ;
F_47 ( & V_39 -> V_96 ) ;
V_39 -> V_62 = V_119 ;
V_39 -> V_91 = ( V_5 ? V_5 -> V_92 [ V_119 ]
: V_93 [ V_119 ] ) ;
F_48 ( & V_39 -> V_96 ) ;
}
static int F_63 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_106 * V_107 = F_6 ( V_11 ) ;
F_64 ( V_107 -> V_113 , V_120 ) ;
F_65 ( & V_107 -> V_109 ) ;
V_5 -> V_92 = F_66 ( ( int * ) V_93 ,
sizeof( V_93 ) ) ;
if ( ! V_5 -> V_92 )
return - V_121 ;
V_5 -> V_67 = V_69 ;
return 0 ;
}
static void F_67 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_68 ( V_5 -> V_92 ) ;
}
