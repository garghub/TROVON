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
if ( V_17 ) {
if ( V_17 -> type == V_24 ||
! ( F_5 ( V_2 ) ||
V_17 -> type == V_25 ) )
return 1 ;
V_22 = & V_19 -> V_26 ;
}
}
} else {
V_22 = F_4 (
V_5 , V_12 -> V_23 , sizeof( V_21 ) , & V_21 ) ;
}
if ( ! V_22 ) {
* V_8 = V_27 ;
return 0 ;
}
if ( F_2 ( ! F_6 ( V_12 ) ) )
V_14 = F_7 ( V_2 , V_3 , V_5 -> V_28 , V_12 -> V_29 ,
& V_12 -> V_30 , V_22 [ 1 ] ) ;
else
V_14 = F_7 ( V_2 , V_3 , V_5 -> V_28 , V_12 -> V_29 ,
& V_12 -> V_31 , V_22 [ 0 ] ) ;
if ( V_14 ) {
int V_32 ;
if ( F_8 ( V_2 ) ) {
* V_8 = V_27 ;
return 0 ;
}
* V_10 = F_9 ( V_14 , V_5 , V_7 , & V_32 , V_12 ) ;
if ( ! * V_10 && V_32 <= 0 ) {
if ( ! V_32 )
* V_8 = F_10 ( V_14 , V_5 , V_7 , V_12 ) ;
else
* V_8 = V_27 ;
return 0 ;
}
}
return 1 ;
}
static void F_11 ( struct V_4 * V_5 , struct V_18 * V_33 ,
unsigned int V_34 )
{
V_33 -> V_35 = F_12 ( V_5 , V_34 ) ;
V_5 -> V_36 = V_37 ;
}
static int
F_13 ( struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_9 * V_40 , struct V_11 * V_12 )
{
struct V_18 * V_33 ;
unsigned int V_34 = V_12 -> V_23 ;
bool V_41 = false ;
#ifdef F_14
if ( V_40 -> V_3 == V_42 && V_12 -> V_43 )
return 1 ;
#endif
if ( ! F_15 ( V_5 , V_34 + sizeof( * V_33 ) ) )
return 0 ;
if ( F_16 ( V_40 -> V_44 != NULL ) ) {
int V_45 ;
if ( V_39 -> V_46 && ! V_39 -> V_46 ( V_40 -> V_3 , V_5 , V_39 ) )
return 0 ;
V_45 = F_17 ( V_40 , V_5 ) ;
if ( V_45 == 0 )
return 0 ;
if ( V_45 == 2 )
V_41 = true ;
}
V_33 = ( void * ) F_18 ( V_5 ) + V_34 ;
if ( V_33 -> V_26 != V_40 -> V_47 || V_41 ||
V_5 -> V_36 == V_48 ) {
V_33 -> V_26 = V_40 -> V_47 ;
F_11 ( V_5 , V_33 , V_34 ) ;
} else {
V_5 -> V_36 = V_37 ;
}
return 1 ;
}
static int
F_19 ( struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_9 * V_40 , struct V_11 * V_12 )
{
struct V_18 * V_33 ;
unsigned int V_34 = V_12 -> V_23 ;
bool V_41 = false ;
#ifdef F_14
if ( V_40 -> V_3 == V_42 && V_12 -> V_43 )
return 1 ;
#endif
if ( ! F_15 ( V_5 , V_34 + sizeof( * V_33 ) ) )
return 0 ;
if ( F_16 ( V_40 -> V_44 != NULL ) ) {
int V_45 ;
if ( V_39 -> V_46 && ! V_39 -> V_46 ( V_40 -> V_3 , V_5 , V_39 ) )
return 0 ;
V_45 = F_20 ( V_40 , V_5 ) ;
if ( V_45 == 0 )
return 0 ;
if ( V_45 == 2 )
V_41 = true ;
}
V_33 = ( void * ) F_18 ( V_5 ) + V_34 ;
if ( V_33 -> V_49 != V_40 -> V_50 || V_41 ||
( V_5 -> V_36 == V_48 &&
! ( F_21 ( V_5 ) -> V_51 -> V_52 & V_53 ) ) ) {
V_33 -> V_49 = V_40 -> V_50 ;
F_11 ( V_5 , V_33 , V_34 ) ;
} else if ( V_5 -> V_36 != V_48 ) {
V_5 -> V_36 = V_37 ;
}
return 1 ;
}
static int
F_22 ( int V_3 , struct V_4 * V_5 , struct V_38 * V_39 )
{
unsigned int V_34 ;
struct V_18 * V_19 , V_20 ;
T_2 V_54 , V_55 ;
#ifdef F_14
if ( V_3 == V_42 )
V_34 = sizeof( struct V_56 ) ;
else
#endif
V_34 = F_23 ( V_5 ) ;
V_19 = F_4 ( V_5 , V_34 , sizeof( V_20 ) , & V_20 ) ;
if ( V_19 == NULL )
return 0 ;
V_54 = V_19 -> V_35 ;
V_55 = F_12 ( V_5 , V_34 ) ;
if ( V_55 != V_54 ) {
F_24 ( 0 , V_3 , V_39 , V_5 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_25 ( int V_57 )
{
if ( V_57 >= V_58 )
return L_2 ;
if ( V_59 [ V_57 ] )
return V_59 [ V_57 ] ;
return L_3 ;
}
static inline void
F_26 ( struct V_6 * V_7 , struct V_9 * V_40 ,
int V_60 , const struct V_4 * V_5 )
{
struct V_15 V_61 , * V_17 ;
unsigned char V_62 ;
int V_63 , V_64 ;
int V_65 , V_66 ;
#ifdef F_14
V_65 = V_40 -> V_3 == V_67 ? F_23 ( V_5 ) : sizeof( struct V_56 ) ;
#else
V_65 = F_23 ( V_5 ) ;
#endif
V_66 = V_65 + sizeof( struct V_18 ) ;
V_17 = F_4 ( V_5 , V_66 , sizeof( V_61 ) , & V_61 ) ;
if ( V_17 == NULL )
return;
V_62 = V_17 -> type ;
if ( ( V_17 -> type == V_68 ) ||
( V_17 -> type == V_69 ) ) {
int V_70 = F_27 ( V_17 -> V_71 ) ;
if ( V_70 >= sizeof( V_61 ) ) {
V_17 = F_4 ( V_5 , V_66 + F_28 ( V_70 , 4 ) ,
sizeof( V_61 ) , & V_61 ) ;
if ( V_17 && V_17 -> type == V_24 )
V_62 = V_17 -> type ;
}
}
V_63 = ( V_62 < sizeof( V_72 ) ) ?
V_72 [ V_62 ] : V_73 ;
if ( V_40 -> V_74 & V_75 ) {
if ( V_60 == V_76 )
V_40 -> V_74 &= ~ V_75 ;
else
V_60 = V_77 ;
}
V_64 = V_78 [ V_60 ] [ V_63 ] [ V_40 -> V_57 ] ;
if ( V_64 != V_40 -> V_57 ) {
struct V_79 * V_49 = V_40 -> V_49 ;
F_29 ( 8 , L_4
L_5 ,
V_7 -> V_39 -> V_80 ,
( ( V_60 == V_76 ) ?
L_6 : L_7 ) ,
F_30 ( V_40 -> V_81 , & V_40 -> V_30 ) ,
F_27 ( V_40 -> V_50 ) ,
F_30 ( V_40 -> V_3 , & V_40 -> V_82 ) ,
F_27 ( V_40 -> V_83 ) ,
F_25 ( V_40 -> V_57 ) ,
F_25 ( V_64 ) ,
F_31 ( & V_40 -> V_84 ) ) ;
if ( V_49 ) {
if ( ! ( V_40 -> V_74 & V_85 ) &&
( V_64 != V_86 ) ) {
F_32 ( & V_49 -> V_87 ) ;
F_33 ( & V_49 -> V_88 ) ;
V_40 -> V_74 |= V_85 ;
} else if ( ( V_40 -> V_74 & V_85 ) &&
( V_64 == V_86 ) ) {
F_33 ( & V_49 -> V_87 ) ;
F_32 ( & V_49 -> V_88 ) ;
V_40 -> V_74 &= ~ V_85 ;
}
}
}
if ( F_2 ( V_7 ) )
V_40 -> V_89 = V_7 -> V_90 [ V_40 -> V_57 = V_64 ] ;
else
V_40 -> V_89 = V_91 [ V_40 -> V_57 = V_64 ] ;
}
static void
F_34 ( struct V_9 * V_40 , int V_60 ,
const struct V_4 * V_5 , struct V_6 * V_7 )
{
F_35 ( & V_40 -> V_92 ) ;
F_26 ( V_7 , V_40 , V_60 , V_5 ) ;
F_36 ( & V_40 -> V_92 ) ;
}
static inline T_3 F_37 ( T_1 V_93 )
{
return ( ( ( V_94 V_95 ) V_93 >> V_96 ) ^ ( V_94 V_95 ) V_93 )
& V_97 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_98 * V_100 ;
T_3 V_101 ;
T_1 V_93 = V_99 -> V_93 ;
int V_45 = 0 ;
struct V_6 * V_7 = F_39 ( V_2 , V_102 ) ;
V_101 = F_37 ( V_93 ) ;
F_40 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_100 -> V_93 == V_93 ) {
V_45 = - V_103 ;
goto V_104;
}
}
F_41 ( & V_99 -> V_105 , & V_2 -> V_106 [ V_101 ] ) ;
F_33 ( & V_7 -> V_107 ) ;
V_104:
return V_45 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
struct V_6 * V_7 = F_39 ( V_2 , V_102 ) ;
F_32 ( & V_7 -> V_107 ) ;
F_43 ( & V_99 -> V_105 ) ;
}
static int F_44 ( struct V_9 * V_40 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
int V_101 ;
struct V_98 * V_99 ;
int V_108 = 0 ;
if ( F_45 ( V_40 ) != V_109 )
return 0 ;
V_101 = F_37 ( V_40 -> V_47 ) ;
F_46 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_99 -> V_93 == V_40 -> V_47 ) {
if ( F_16 ( ! F_47 ( V_99 ) ) )
break;
F_29 ( 9 , L_8
L_9 ,
V_110 ,
F_30 ( V_40 -> V_3 , & V_40 -> V_82 ) ,
F_27 ( V_40 -> V_83 ) ,
F_30 ( V_40 -> V_3 , & V_40 -> V_111 ) ,
F_27 ( V_40 -> V_47 ) ,
V_99 -> V_80 , F_27 ( V_99 -> V_93 ) ) ;
V_40 -> V_44 = V_99 ;
if ( V_99 -> V_112 )
V_108 = V_99 -> V_112 ( V_99 , V_40 ) ;
break;
}
}
return V_108 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_49 ( V_2 -> V_106 , V_113 ) ;
V_7 -> V_90 = F_50 ( ( int * ) V_91 ,
sizeof( V_91 ) ) ;
if ( ! V_7 -> V_90 )
return - V_114 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_52 ( V_7 -> V_90 ) ;
}
