static int
F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 ,
int * V_8 , struct V_9 * * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
T_1 V_15 , * V_16 ;
T_2 * V_17 , V_18 ;
T_3 V_19 [ 2 ] , * V_20 = NULL ;
if ( F_2 ( ! F_3 ( V_12 ) ) ) {
V_17 = F_4 ( V_5 , V_12 -> V_21 , sizeof( V_18 ) , & V_18 ) ;
if ( V_17 ) {
V_16 = F_4 (
V_5 , V_12 -> V_21 + sizeof( T_2 ) ,
sizeof( V_15 ) , & V_15 ) ;
if ( V_16 && ( V_16 -> type == V_22 ||
F_5 ( V_2 ) ) )
V_20 = & V_17 -> V_23 ;
}
} else {
V_20 = F_4 (
V_5 , V_12 -> V_21 , sizeof( V_19 ) , & V_19 ) ;
}
if ( ! V_20 ) {
* V_8 = V_24 ;
return 0 ;
}
F_6 () ;
if ( F_2 ( ! F_7 ( V_12 ) ) )
V_14 = F_8 ( V_2 , V_3 , V_5 -> V_25 , V_12 -> V_26 ,
& V_12 -> V_27 , V_20 [ 1 ] ) ;
else
V_14 = F_8 ( V_2 , V_3 , V_5 -> V_25 , V_12 -> V_26 ,
& V_12 -> V_28 , V_20 [ 0 ] ) ;
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
static void F_13 ( struct V_4 * V_5 , T_2 * V_30 ,
unsigned int V_31 )
{
V_30 -> V_32 = F_14 ( V_5 , V_31 ) ;
V_5 -> V_33 = V_34 ;
}
static int
F_15 ( struct V_4 * V_5 , struct V_35 * V_36 ,
struct V_9 * V_37 , struct V_11 * V_12 )
{
T_2 * V_30 ;
unsigned int V_31 = V_12 -> V_21 ;
bool V_38 = false ;
#ifdef F_16
if ( V_37 -> V_3 == V_39 && V_12 -> V_40 )
return 1 ;
#endif
if ( ! F_17 ( V_5 , V_31 + sizeof( * V_30 ) ) )
return 0 ;
if ( F_18 ( V_37 -> V_41 != NULL ) ) {
int V_42 ;
if ( V_36 -> V_43 && ! V_36 -> V_43 ( V_37 -> V_3 , V_5 , V_36 ) )
return 0 ;
V_42 = F_19 ( V_37 , V_5 ) ;
if ( V_42 == 0 )
return 0 ;
if ( V_42 == 2 )
V_38 = true ;
}
V_30 = ( void * ) F_20 ( V_5 ) + V_31 ;
if ( V_30 -> V_23 != V_37 -> V_44 || V_38 ||
V_5 -> V_33 == V_45 ) {
V_30 -> V_23 = V_37 -> V_44 ;
F_13 ( V_5 , V_30 , V_31 ) ;
} else {
V_5 -> V_33 = V_34 ;
}
return 1 ;
}
static int
F_21 ( struct V_4 * V_5 , struct V_35 * V_36 ,
struct V_9 * V_37 , struct V_11 * V_12 )
{
T_2 * V_30 ;
unsigned int V_31 = V_12 -> V_21 ;
bool V_38 = false ;
#ifdef F_16
if ( V_37 -> V_3 == V_39 && V_12 -> V_40 )
return 1 ;
#endif
if ( ! F_17 ( V_5 , V_31 + sizeof( * V_30 ) ) )
return 0 ;
if ( F_18 ( V_37 -> V_41 != NULL ) ) {
int V_42 ;
if ( V_36 -> V_43 && ! V_36 -> V_43 ( V_37 -> V_3 , V_5 , V_36 ) )
return 0 ;
V_42 = F_22 ( V_37 , V_5 ) ;
if ( V_42 == 0 )
return 0 ;
if ( V_42 == 2 )
V_38 = true ;
}
V_30 = ( void * ) F_20 ( V_5 ) + V_31 ;
if ( V_30 -> V_46 != V_37 -> V_47 || V_38 ||
( V_5 -> V_33 == V_45 &&
! ( F_23 ( V_5 ) -> V_48 -> V_49 & V_50 ) ) ) {
V_30 -> V_46 = V_37 -> V_47 ;
F_13 ( V_5 , V_30 , V_31 ) ;
} else if ( V_5 -> V_33 != V_45 ) {
V_5 -> V_33 = V_34 ;
}
return 1 ;
}
static int
F_24 ( int V_3 , struct V_4 * V_5 , struct V_35 * V_36 )
{
unsigned int V_31 ;
struct V_51 * V_17 , V_18 ;
T_4 V_52 , V_53 ;
#ifdef F_16
if ( V_3 == V_39 )
V_31 = sizeof( struct V_54 ) ;
else
#endif
V_31 = F_25 ( V_5 ) ;
V_17 = F_4 ( V_5 , V_31 , sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL )
return 0 ;
V_52 = V_17 -> V_32 ;
V_53 = F_14 ( V_5 , V_31 ) ;
if ( V_53 != V_52 ) {
F_26 ( 0 , V_3 , V_36 , V_5 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_27 ( int V_55 )
{
if ( V_55 >= V_56 )
return L_2 ;
if ( V_57 [ V_55 ] )
return V_57 [ V_55 ] ;
return L_3 ;
}
static inline void
F_28 ( struct V_6 * V_7 , struct V_9 * V_37 ,
int V_58 , const struct V_4 * V_5 )
{
T_1 V_59 , * V_16 ;
unsigned char V_60 ;
int V_61 , V_62 ;
int V_63 , V_64 ;
#ifdef F_16
V_63 = V_37 -> V_3 == V_65 ? F_25 ( V_5 ) : sizeof( struct V_54 ) ;
#else
V_63 = F_25 ( V_5 ) ;
#endif
V_64 = V_63 + sizeof( T_2 ) ;
V_16 = F_4 ( V_5 , V_64 , sizeof( V_59 ) , & V_59 ) ;
if ( V_16 == NULL )
return;
V_60 = V_16 -> type ;
if ( ( V_16 -> type == V_66 ) ||
( V_16 -> type == V_67 ) ) {
int V_68 = F_29 ( V_16 -> V_69 ) ;
if ( V_68 >= sizeof( T_1 ) ) {
V_16 = F_4 ( V_5 , V_64 + F_30 ( V_68 , 4 ) ,
sizeof( V_59 ) , & V_59 ) ;
if ( V_16 && V_16 -> type == V_70 )
V_60 = V_16 -> type ;
}
}
V_61 = ( V_60 < sizeof( V_71 ) ) ?
V_71 [ V_60 ] : V_72 ;
if ( V_37 -> V_73 & V_74 ) {
if ( V_58 == V_75 )
V_37 -> V_73 &= ~ V_74 ;
else
V_58 = V_76 ;
}
V_62 = V_77 [ V_58 ] [ V_61 ] [ V_37 -> V_55 ] ;
if ( V_62 != V_37 -> V_55 ) {
struct V_78 * V_46 = V_37 -> V_46 ;
F_31 ( 8 , L_4
L_5 ,
V_7 -> V_36 -> V_79 ,
( ( V_58 == V_75 ) ?
L_6 : L_7 ) ,
F_32 ( V_37 -> V_80 , & V_37 -> V_27 ) ,
F_29 ( V_37 -> V_47 ) ,
F_32 ( V_37 -> V_3 , & V_37 -> V_81 ) ,
F_29 ( V_37 -> V_82 ) ,
F_27 ( V_37 -> V_55 ) ,
F_27 ( V_62 ) ,
F_33 ( & V_37 -> V_83 ) ) ;
if ( V_46 ) {
if ( ! ( V_37 -> V_73 & V_84 ) &&
( V_62 != V_85 ) ) {
F_34 ( & V_46 -> V_86 ) ;
F_35 ( & V_46 -> V_87 ) ;
V_37 -> V_73 |= V_84 ;
} else if ( ( V_37 -> V_73 & V_84 ) &&
( V_62 == V_85 ) ) {
F_35 ( & V_46 -> V_86 ) ;
F_34 ( & V_46 -> V_87 ) ;
V_37 -> V_73 &= ~ V_84 ;
}
}
}
if ( F_2 ( V_7 ) )
V_37 -> V_88 = V_7 -> V_89 [ V_37 -> V_55 = V_62 ] ;
else
V_37 -> V_88 = V_90 [ V_37 -> V_55 = V_62 ] ;
}
static void
F_36 ( struct V_9 * V_37 , int V_58 ,
const struct V_4 * V_5 , struct V_6 * V_7 )
{
F_37 ( & V_37 -> V_91 ) ;
F_28 ( V_7 , V_37 , V_58 , V_5 ) ;
F_38 ( & V_37 -> V_91 ) ;
}
static inline T_5 F_39 ( T_3 V_92 )
{
return ( ( ( V_93 V_94 ) V_92 >> V_95 ) ^ ( V_93 V_94 ) V_92 )
& V_96 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_97 * V_99 ;
T_5 V_100 ;
T_3 V_92 = V_98 -> V_92 ;
int V_42 = 0 ;
struct V_6 * V_7 = F_41 ( V_2 , V_101 ) ;
V_100 = F_39 ( V_92 ) ;
F_42 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_99 -> V_92 == V_92 ) {
V_42 = - V_102 ;
goto V_103;
}
}
F_43 ( & V_98 -> V_104 , & V_2 -> V_105 [ V_100 ] ) ;
F_35 ( & V_7 -> V_106 ) ;
V_103:
return V_42 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_6 * V_7 = F_41 ( V_2 , V_101 ) ;
F_34 ( & V_7 -> V_106 ) ;
F_45 ( & V_98 -> V_104 ) ;
}
static int F_46 ( struct V_9 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
int V_100 ;
struct V_97 * V_98 ;
int V_107 = 0 ;
if ( F_47 ( V_37 ) != V_108 )
return 0 ;
V_100 = F_39 ( V_37 -> V_44 ) ;
F_6 () ;
F_48 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_98 -> V_92 == V_37 -> V_44 ) {
if ( F_18 ( ! F_49 ( V_98 ) ) )
break;
F_10 () ;
F_31 ( 9 , L_8
L_9 ,
V_109 ,
F_32 ( V_37 -> V_3 , & V_37 -> V_81 ) ,
F_29 ( V_37 -> V_82 ) ,
F_32 ( V_37 -> V_3 , & V_37 -> V_110 ) ,
F_29 ( V_37 -> V_44 ) ,
V_98 -> V_79 , F_29 ( V_98 -> V_92 ) ) ;
V_37 -> V_41 = V_98 ;
if ( V_98 -> V_111 )
V_107 = V_98 -> V_111 ( V_98 , V_37 ) ;
goto V_103;
}
}
F_10 () ;
V_103:
return V_107 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_51 ( V_2 -> V_105 , V_112 ) ;
V_7 -> V_89 = F_52 ( ( int * ) V_90 ,
sizeof( V_90 ) ) ;
if ( ! V_7 -> V_89 )
return - V_113 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_54 ( V_7 -> V_89 ) ;
}
