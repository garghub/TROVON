static int
F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 ,
int * V_8 , struct V_9 * * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 V_16 , * V_17 ;
struct V_18 * V_19 , V_20 ;
T_1 V_21 [ 2 ] , * V_22 = NULL ;
if ( F_2 ( ! F_3 ( V_12 ) ) ) {
V_19 = F_4 ( V_5 , V_12 -> V_23 , sizeof( V_20 ) , & V_20 ) ;
if ( V_19 ) {
V_17 = F_4 ( V_5 , V_12 -> V_23 + sizeof( V_20 ) ,
sizeof( V_16 ) , & V_16 ) ;
if ( V_17 && ( V_17 -> type == V_24 ||
F_5 ( V_2 ) ) )
V_22 = & V_19 -> V_25 ;
}
} else {
V_22 = F_4 (
V_5 , V_12 -> V_23 , sizeof( V_21 ) , & V_21 ) ;
}
if ( ! V_22 ) {
* V_8 = V_26 ;
return 0 ;
}
F_6 () ;
if ( F_2 ( ! F_7 ( V_12 ) ) )
V_14 = F_8 ( V_2 , V_3 , V_5 -> V_27 , V_12 -> V_28 ,
& V_12 -> V_29 , V_22 [ 1 ] ) ;
else
V_14 = F_8 ( V_2 , V_3 , V_5 -> V_27 , V_12 -> V_28 ,
& V_12 -> V_30 , V_22 [ 0 ] ) ;
if ( V_14 ) {
int V_31 ;
if ( F_9 ( V_2 ) ) {
F_10 () ;
* V_8 = V_26 ;
return 0 ;
}
* V_10 = F_11 ( V_14 , V_5 , V_7 , & V_31 , V_12 ) ;
if ( ! * V_10 && V_31 <= 0 ) {
if ( ! V_31 )
* V_8 = F_12 ( V_14 , V_5 , V_7 , V_12 ) ;
else
* V_8 = V_26 ;
F_10 () ;
return 0 ;
}
}
F_10 () ;
return 1 ;
}
static void F_13 ( struct V_4 * V_5 , struct V_18 * V_32 ,
unsigned int V_33 )
{
V_32 -> V_34 = F_14 ( V_5 , V_33 ) ;
V_5 -> V_35 = V_36 ;
}
static int
F_15 ( struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_9 * V_39 , struct V_11 * V_12 )
{
struct V_18 * V_32 ;
unsigned int V_33 = V_12 -> V_23 ;
bool V_40 = false ;
#ifdef F_16
if ( V_39 -> V_3 == V_41 && V_12 -> V_42 )
return 1 ;
#endif
if ( ! F_17 ( V_5 , V_33 + sizeof( * V_32 ) ) )
return 0 ;
if ( F_18 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_3 , V_5 , V_38 ) )
return 0 ;
V_44 = F_19 ( V_39 , V_5 ) ;
if ( V_44 == 0 )
return 0 ;
if ( V_44 == 2 )
V_40 = true ;
}
V_32 = ( void * ) F_20 ( V_5 ) + V_33 ;
if ( V_32 -> V_25 != V_39 -> V_46 || V_40 ||
V_5 -> V_35 == V_47 ) {
V_32 -> V_25 = V_39 -> V_46 ;
F_13 ( V_5 , V_32 , V_33 ) ;
} else {
V_5 -> V_35 = V_36 ;
}
return 1 ;
}
static int
F_21 ( struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_9 * V_39 , struct V_11 * V_12 )
{
struct V_18 * V_32 ;
unsigned int V_33 = V_12 -> V_23 ;
bool V_40 = false ;
#ifdef F_16
if ( V_39 -> V_3 == V_41 && V_12 -> V_42 )
return 1 ;
#endif
if ( ! F_17 ( V_5 , V_33 + sizeof( * V_32 ) ) )
return 0 ;
if ( F_18 ( V_39 -> V_43 != NULL ) ) {
int V_44 ;
if ( V_38 -> V_45 && ! V_38 -> V_45 ( V_39 -> V_3 , V_5 , V_38 ) )
return 0 ;
V_44 = F_22 ( V_39 , V_5 ) ;
if ( V_44 == 0 )
return 0 ;
if ( V_44 == 2 )
V_40 = true ;
}
V_32 = ( void * ) F_20 ( V_5 ) + V_33 ;
if ( V_32 -> V_48 != V_39 -> V_49 || V_40 ||
( V_5 -> V_35 == V_47 &&
! ( F_23 ( V_5 ) -> V_50 -> V_51 & V_52 ) ) ) {
V_32 -> V_48 = V_39 -> V_49 ;
F_13 ( V_5 , V_32 , V_33 ) ;
} else if ( V_5 -> V_35 != V_47 ) {
V_5 -> V_35 = V_36 ;
}
return 1 ;
}
static int
F_24 ( int V_3 , struct V_4 * V_5 , struct V_37 * V_38 )
{
unsigned int V_33 ;
struct V_18 * V_19 , V_20 ;
T_2 V_53 , V_54 ;
#ifdef F_16
if ( V_3 == V_41 )
V_33 = sizeof( struct V_55 ) ;
else
#endif
V_33 = F_25 ( V_5 ) ;
V_19 = F_4 ( V_5 , V_33 , sizeof( V_20 ) , & V_20 ) ;
if ( V_19 == NULL )
return 0 ;
V_53 = V_19 -> V_34 ;
V_54 = F_14 ( V_5 , V_33 ) ;
if ( V_54 != V_53 ) {
F_26 ( 0 , V_3 , V_38 , V_5 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_27 ( int V_56 )
{
if ( V_56 >= V_57 )
return L_2 ;
if ( V_58 [ V_56 ] )
return V_58 [ V_56 ] ;
return L_3 ;
}
static inline void
F_28 ( struct V_6 * V_7 , struct V_9 * V_39 ,
int V_59 , const struct V_4 * V_5 )
{
struct V_15 V_60 , * V_17 ;
unsigned char V_61 ;
int V_62 , V_63 ;
int V_64 , V_65 ;
#ifdef F_16
V_64 = V_39 -> V_3 == V_66 ? F_25 ( V_5 ) : sizeof( struct V_55 ) ;
#else
V_64 = F_25 ( V_5 ) ;
#endif
V_65 = V_64 + sizeof( struct V_18 ) ;
V_17 = F_4 ( V_5 , V_65 , sizeof( V_60 ) , & V_60 ) ;
if ( V_17 == NULL )
return;
V_61 = V_17 -> type ;
if ( ( V_17 -> type == V_67 ) ||
( V_17 -> type == V_68 ) ) {
int V_69 = F_29 ( V_17 -> V_70 ) ;
if ( V_69 >= sizeof( V_60 ) ) {
V_17 = F_4 ( V_5 , V_65 + F_30 ( V_69 , 4 ) ,
sizeof( V_60 ) , & V_60 ) ;
if ( V_17 && V_17 -> type == V_71 )
V_61 = V_17 -> type ;
}
}
V_62 = ( V_61 < sizeof( V_72 ) ) ?
V_72 [ V_61 ] : V_73 ;
if ( V_39 -> V_74 & V_75 ) {
if ( V_59 == V_76 )
V_39 -> V_74 &= ~ V_75 ;
else
V_59 = V_77 ;
}
V_63 = V_78 [ V_59 ] [ V_62 ] [ V_39 -> V_56 ] ;
if ( V_63 != V_39 -> V_56 ) {
struct V_79 * V_48 = V_39 -> V_48 ;
F_31 ( 8 , L_4
L_5 ,
V_7 -> V_38 -> V_80 ,
( ( V_59 == V_76 ) ?
L_6 : L_7 ) ,
F_32 ( V_39 -> V_81 , & V_39 -> V_29 ) ,
F_29 ( V_39 -> V_49 ) ,
F_32 ( V_39 -> V_3 , & V_39 -> V_82 ) ,
F_29 ( V_39 -> V_83 ) ,
F_27 ( V_39 -> V_56 ) ,
F_27 ( V_63 ) ,
F_33 ( & V_39 -> V_84 ) ) ;
if ( V_48 ) {
if ( ! ( V_39 -> V_74 & V_85 ) &&
( V_63 != V_86 ) ) {
F_34 ( & V_48 -> V_87 ) ;
F_35 ( & V_48 -> V_88 ) ;
V_39 -> V_74 |= V_85 ;
} else if ( ( V_39 -> V_74 & V_85 ) &&
( V_63 == V_86 ) ) {
F_35 ( & V_48 -> V_87 ) ;
F_34 ( & V_48 -> V_88 ) ;
V_39 -> V_74 &= ~ V_85 ;
}
}
}
if ( F_2 ( V_7 ) )
V_39 -> V_89 = V_7 -> V_90 [ V_39 -> V_56 = V_63 ] ;
else
V_39 -> V_89 = V_91 [ V_39 -> V_56 = V_63 ] ;
}
static void
F_36 ( struct V_9 * V_39 , int V_59 ,
const struct V_4 * V_5 , struct V_6 * V_7 )
{
F_37 ( & V_39 -> V_92 ) ;
F_28 ( V_7 , V_39 , V_59 , V_5 ) ;
F_38 ( & V_39 -> V_92 ) ;
}
static inline T_3 F_39 ( T_1 V_93 )
{
return ( ( ( V_94 V_95 ) V_93 >> V_96 ) ^ ( V_94 V_95 ) V_93 )
& V_97 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_98 * V_100 ;
T_3 V_101 ;
T_1 V_93 = V_99 -> V_93 ;
int V_44 = 0 ;
struct V_6 * V_7 = F_41 ( V_2 , V_102 ) ;
V_101 = F_39 ( V_93 ) ;
F_42 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_100 -> V_93 == V_93 ) {
V_44 = - V_103 ;
goto V_104;
}
}
F_43 ( & V_99 -> V_105 , & V_2 -> V_106 [ V_101 ] ) ;
F_35 ( & V_7 -> V_107 ) ;
V_104:
return V_44 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_6 * V_7 = F_41 ( V_2 , V_102 ) ;
F_34 ( & V_7 -> V_107 ) ;
F_45 ( & V_99 -> V_105 ) ;
}
static int F_46 ( struct V_9 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_2 ;
int V_101 ;
struct V_98 * V_99 ;
int V_108 = 0 ;
if ( F_47 ( V_39 ) != V_109 )
return 0 ;
V_101 = F_39 ( V_39 -> V_46 ) ;
F_6 () ;
F_48 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_99 -> V_93 == V_39 -> V_46 ) {
if ( F_18 ( ! F_49 ( V_99 ) ) )
break;
F_10 () ;
F_31 ( 9 , L_8
L_9 ,
V_110 ,
F_32 ( V_39 -> V_3 , & V_39 -> V_82 ) ,
F_29 ( V_39 -> V_83 ) ,
F_32 ( V_39 -> V_3 , & V_39 -> V_111 ) ,
F_29 ( V_39 -> V_46 ) ,
V_99 -> V_80 , F_29 ( V_99 -> V_93 ) ) ;
V_39 -> V_43 = V_99 ;
if ( V_99 -> V_112 )
V_108 = V_99 -> V_112 ( V_99 , V_39 ) ;
goto V_104;
}
}
F_10 () ;
V_104:
return V_108 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_51 ( V_2 -> V_106 , V_113 ) ;
V_7 -> V_90 = F_52 ( ( int * ) V_91 ,
sizeof( V_91 ) ) ;
if ( ! V_7 -> V_90 )
return - V_114 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_54 ( V_7 -> V_90 ) ;
}
