static int
F_1 ( int V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int * V_6 , struct V_7 * * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
T_1 V_16 , * V_17 ;
T_2 * V_18 , V_19 ;
V_18 = F_2 ( V_3 , V_10 -> V_20 , sizeof( V_19 ) , & V_19 ) ;
if ( V_18 == NULL ) {
* V_6 = V_21 ;
return 0 ;
}
V_17 = F_2 ( V_3 , V_10 -> V_20 + sizeof( T_2 ) ,
sizeof( V_16 ) , & V_16 ) ;
if ( V_17 == NULL ) {
* V_6 = V_21 ;
return 0 ;
}
V_11 = F_3 ( V_3 ) ;
V_15 = F_4 ( V_11 ) ;
F_5 () ;
if ( ( V_17 -> type == V_22 || F_6 ( V_15 ) ) &&
( V_13 = F_7 ( V_11 , V_1 , V_3 -> V_23 , V_10 -> V_24 ,
& V_10 -> V_25 , V_18 -> V_26 ) ) ) {
int V_27 ;
if ( F_8 ( V_15 ) ) {
F_9 () ;
* V_6 = V_21 ;
return 0 ;
}
* V_8 = F_10 ( V_13 , V_3 , V_5 , & V_27 , V_10 ) ;
if ( ! * V_8 && V_27 <= 0 ) {
if ( ! V_27 )
* V_6 = F_11 ( V_13 , V_3 , V_5 , V_10 ) ;
else
* V_6 = V_21 ;
F_9 () ;
return 0 ;
}
}
F_9 () ;
return 1 ;
}
static void F_12 ( struct V_2 * V_3 , T_2 * V_28 ,
unsigned int V_29 )
{
V_28 -> V_30 = F_13 ( V_3 , V_29 ) ;
V_3 -> V_31 = V_32 ;
}
static int
F_14 ( struct V_2 * V_3 , struct V_33 * V_34 ,
struct V_7 * V_35 , struct V_9 * V_10 )
{
T_2 * V_28 ;
unsigned int V_29 = V_10 -> V_20 ;
bool V_36 = false ;
#ifdef F_15
if ( V_35 -> V_1 == V_37 && V_10 -> V_38 )
return 1 ;
#endif
if ( ! F_16 ( V_3 , V_29 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_17 ( V_35 -> V_39 != NULL ) ) {
int V_40 ;
if ( V_34 -> V_41 && ! V_34 -> V_41 ( V_35 -> V_1 , V_3 , V_34 ) )
return 0 ;
V_40 = F_18 ( V_35 , V_3 ) ;
if ( V_40 == 0 )
return 0 ;
if ( V_40 == 2 )
V_36 = true ;
}
V_28 = ( void * ) F_19 ( V_3 ) + V_29 ;
if ( V_28 -> V_42 != V_35 -> V_43 || V_36 ||
V_3 -> V_31 == V_44 ) {
V_28 -> V_42 = V_35 -> V_43 ;
F_12 ( V_3 , V_28 , V_29 ) ;
} else {
V_3 -> V_31 = V_32 ;
}
return 1 ;
}
static int
F_20 ( struct V_2 * V_3 , struct V_33 * V_34 ,
struct V_7 * V_35 , struct V_9 * V_10 )
{
T_2 * V_28 ;
unsigned int V_29 = V_10 -> V_20 ;
bool V_36 = false ;
#ifdef F_15
if ( V_35 -> V_1 == V_37 && V_10 -> V_38 )
return 1 ;
#endif
if ( ! F_16 ( V_3 , V_29 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_17 ( V_35 -> V_39 != NULL ) ) {
int V_40 ;
if ( V_34 -> V_41 && ! V_34 -> V_41 ( V_35 -> V_1 , V_3 , V_34 ) )
return 0 ;
V_40 = F_21 ( V_35 , V_3 ) ;
if ( V_40 == 0 )
return 0 ;
if ( V_40 == 2 )
V_36 = true ;
}
V_28 = ( void * ) F_19 ( V_3 ) + V_29 ;
if ( V_28 -> V_26 != V_35 -> V_45 || V_36 ||
( V_3 -> V_31 == V_44 &&
! ( F_22 ( V_3 ) -> V_46 -> V_47 & V_48 ) ) ) {
V_28 -> V_26 = V_35 -> V_45 ;
F_12 ( V_3 , V_28 , V_29 ) ;
} else if ( V_3 -> V_31 != V_44 ) {
V_3 -> V_31 = V_32 ;
}
return 1 ;
}
static int
F_23 ( int V_1 , struct V_2 * V_3 , struct V_33 * V_34 )
{
unsigned int V_29 ;
struct V_49 * V_18 , V_19 ;
T_3 V_50 , V_51 ;
#ifdef F_15
if ( V_1 == V_37 )
V_29 = sizeof( struct V_52 ) ;
else
#endif
V_29 = F_24 ( V_3 ) ;
V_18 = F_2 ( V_3 , V_29 , sizeof( V_19 ) , & V_19 ) ;
if ( V_18 == NULL )
return 0 ;
V_50 = V_18 -> V_30 ;
V_51 = F_13 ( V_3 , V_29 ) ;
if ( V_51 != V_50 ) {
F_25 ( 0 , V_1 , V_34 , V_3 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_26 ( int V_53 )
{
if ( V_53 >= V_54 )
return L_2 ;
if ( V_55 [ V_53 ] )
return V_55 [ V_53 ] ;
return L_3 ;
}
static inline void
F_27 ( struct V_4 * V_5 , struct V_7 * V_35 ,
int V_56 , const struct V_2 * V_3 )
{
T_1 V_57 , * V_17 ;
unsigned char V_58 ;
int V_59 , V_60 ;
int V_61 , V_62 ;
#ifdef F_15
V_61 = V_35 -> V_1 == V_63 ? F_24 ( V_3 ) : sizeof( struct V_52 ) ;
#else
V_61 = F_24 ( V_3 ) ;
#endif
V_62 = V_61 + sizeof( T_2 ) ;
V_17 = F_2 ( V_3 , V_62 , sizeof( V_57 ) , & V_57 ) ;
if ( V_17 == NULL )
return;
V_58 = V_17 -> type ;
if ( ( V_17 -> type == V_64 ) ||
( V_17 -> type == V_65 ) ) {
int V_66 = F_28 ( V_17 -> V_67 ) ;
if ( V_66 >= sizeof( T_1 ) ) {
V_17 = F_2 ( V_3 , V_62 + F_29 ( V_66 , 4 ) ,
sizeof( V_57 ) , & V_57 ) ;
if ( V_17 && V_17 -> type == V_68 )
V_58 = V_17 -> type ;
}
}
V_59 = ( V_58 < sizeof( V_69 ) ) ?
V_69 [ V_58 ] : V_70 ;
if ( V_35 -> V_71 & V_72 ) {
if ( V_56 == V_73 )
V_35 -> V_71 &= ~ V_72 ;
else
V_56 = V_74 ;
}
V_60 = V_75 [ V_56 ] [ V_59 ] [ V_35 -> V_53 ] ;
if ( V_60 != V_35 -> V_53 ) {
struct V_76 * V_26 = V_35 -> V_26 ;
F_30 ( 8 , L_4
L_5 ,
V_5 -> V_34 -> V_77 ,
( ( V_56 == V_73 ) ?
L_6 : L_7 ) ,
F_31 ( V_35 -> V_1 , & V_35 -> V_25 ) ,
F_28 ( V_35 -> V_45 ) ,
F_31 ( V_35 -> V_1 , & V_35 -> V_78 ) ,
F_28 ( V_35 -> V_79 ) ,
F_26 ( V_35 -> V_53 ) ,
F_26 ( V_60 ) ,
F_32 ( & V_35 -> V_80 ) ) ;
if ( V_26 ) {
if ( ! ( V_35 -> V_71 & V_81 ) &&
( V_60 != V_82 ) ) {
F_33 ( & V_26 -> V_83 ) ;
F_34 ( & V_26 -> V_84 ) ;
V_35 -> V_71 |= V_81 ;
} else if ( ( V_35 -> V_71 & V_81 ) &&
( V_60 == V_82 ) ) {
F_34 ( & V_26 -> V_83 ) ;
F_33 ( & V_26 -> V_84 ) ;
V_35 -> V_71 &= ~ V_81 ;
}
}
}
if ( F_35 ( V_5 ) )
V_35 -> V_85 = V_5 -> V_86 [ V_35 -> V_53 = V_60 ] ;
else
V_35 -> V_85 = V_87 [ V_35 -> V_53 = V_60 ] ;
}
static void
F_36 ( struct V_7 * V_35 , int V_56 ,
const struct V_2 * V_3 , struct V_4 * V_5 )
{
F_37 ( & V_35 -> V_88 ) ;
F_27 ( V_5 , V_35 , V_56 , V_3 ) ;
F_38 ( & V_35 -> V_88 ) ;
}
static inline T_4 F_39 ( T_5 V_89 )
{
return ( ( ( V_90 V_91 ) V_89 >> V_92 ) ^ ( V_90 V_91 ) V_89 )
& V_93 ;
}
static int F_40 ( struct V_11 * V_11 , struct V_94 * V_95 )
{
struct V_94 * V_96 ;
T_4 V_97 ;
T_5 V_89 = V_95 -> V_89 ;
int V_40 = 0 ;
struct V_14 * V_15 = F_4 ( V_11 ) ;
struct V_4 * V_5 = F_41 ( V_11 , V_98 ) ;
V_97 = F_39 ( V_89 ) ;
F_42 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_96 -> V_89 == V_89 ) {
V_40 = - V_99 ;
goto V_100;
}
}
F_43 ( & V_95 -> V_101 , & V_15 -> V_102 [ V_97 ] ) ;
F_34 ( & V_5 -> V_103 ) ;
V_100:
return V_40 ;
}
static void F_44 ( struct V_11 * V_11 , struct V_94 * V_95 )
{
struct V_4 * V_5 = F_41 ( V_11 , V_98 ) ;
F_33 ( & V_5 -> V_103 ) ;
F_45 ( & V_95 -> V_101 ) ;
}
static int F_46 ( struct V_7 * V_35 )
{
struct V_14 * V_15 = F_4 ( F_47 ( V_35 ) ) ;
int V_97 ;
struct V_94 * V_95 ;
int V_104 = 0 ;
if ( F_48 ( V_35 ) != V_105 )
return 0 ;
V_97 = F_39 ( V_35 -> V_43 ) ;
F_5 () ;
F_49 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_95 -> V_89 == V_35 -> V_43 ) {
if ( F_17 ( ! F_50 ( V_95 ) ) )
break;
F_9 () ;
F_30 ( 9 , L_8
L_9 ,
V_106 ,
F_31 ( V_35 -> V_1 , & V_35 -> V_78 ) ,
F_28 ( V_35 -> V_79 ) ,
F_31 ( V_35 -> V_1 , & V_35 -> V_107 ) ,
F_28 ( V_35 -> V_43 ) ,
V_95 -> V_77 , F_28 ( V_95 -> V_89 ) ) ;
V_35 -> V_39 = V_95 ;
if ( V_95 -> V_108 )
V_104 = V_95 -> V_108 ( V_95 , V_35 ) ;
goto V_100;
}
}
F_9 () ;
V_100:
return V_104 ;
}
static int F_51 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_14 * V_15 = F_4 ( V_11 ) ;
F_52 ( V_15 -> V_102 , V_109 ) ;
V_5 -> V_86 = F_53 ( ( int * ) V_87 ,
sizeof( V_87 ) ) ;
if ( ! V_5 -> V_86 )
return - V_110 ;
return 0 ;
}
static void F_54 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_55 ( V_5 -> V_86 ) ;
}
