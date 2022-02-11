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
if ( V_18 == NULL )
return 0 ;
V_17 = F_2 ( V_3 , V_10 -> V_20 + sizeof( T_2 ) ,
sizeof( V_16 ) , & V_16 ) ;
if ( V_17 == NULL )
return 0 ;
V_11 = F_3 ( V_3 ) ;
V_15 = F_4 ( V_11 ) ;
F_5 () ;
if ( ( V_17 -> type == V_21 || F_6 ( V_15 ) ) &&
( V_13 = F_7 ( V_11 , V_1 , V_3 -> V_22 , V_10 -> V_23 ,
& V_10 -> V_24 , V_18 -> V_25 ) ) ) {
int V_26 ;
if ( F_8 ( V_15 ) ) {
F_9 () ;
* V_6 = V_27 ;
return 0 ;
}
* V_8 = F_10 ( V_13 , V_3 , V_5 , & V_26 , V_10 ) ;
if ( ! * V_8 && V_26 <= 0 ) {
if ( ! V_26 )
* V_6 = F_11 ( V_13 , V_3 , V_5 , V_10 ) ;
else
* V_6 = V_27 ;
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
T_3 V_30 ;
struct V_2 * V_31 ;
V_30 = F_13 ( ( V_32 * ) V_28 , F_14 ( V_3 ) - V_29 ) ;
F_15 (skb, iter)
V_30 = F_16 ( ( V_33 * ) V_31 -> V_34 ,
F_14 ( V_31 ) , V_30 ) ;
V_28 -> V_35 = F_17 ( V_30 ) ;
V_3 -> V_36 = V_37 ;
}
static int
F_18 ( struct V_2 * V_3 , struct V_38 * V_39 ,
struct V_7 * V_40 , struct V_9 * V_10 )
{
T_2 * V_28 ;
unsigned int V_29 = V_10 -> V_20 ;
#ifdef F_19
if ( V_40 -> V_1 == V_41 && V_10 -> V_42 )
return 1 ;
#endif
if ( ! F_20 ( V_3 , V_29 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_21 ( V_40 -> V_43 != NULL ) ) {
if ( V_39 -> V_44 && ! V_39 -> V_44 ( V_40 -> V_1 , V_3 , V_39 ) )
return 0 ;
if ( ! F_22 ( V_40 , V_3 ) )
return 0 ;
}
V_28 = ( void * ) F_23 ( V_3 ) + V_29 ;
V_28 -> V_45 = V_40 -> V_46 ;
F_12 ( V_3 , V_28 , V_29 ) ;
return 1 ;
}
static int
F_24 ( struct V_2 * V_3 , struct V_38 * V_39 ,
struct V_7 * V_40 , struct V_9 * V_10 )
{
T_2 * V_28 ;
unsigned int V_29 = V_10 -> V_20 ;
#ifdef F_19
if ( V_40 -> V_1 == V_41 && V_10 -> V_42 )
return 1 ;
#endif
if ( ! F_20 ( V_3 , V_29 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_21 ( V_40 -> V_43 != NULL ) ) {
if ( V_39 -> V_44 && ! V_39 -> V_44 ( V_40 -> V_1 , V_3 , V_39 ) )
return 0 ;
if ( ! F_25 ( V_40 , V_3 ) )
return 0 ;
}
V_28 = ( void * ) F_23 ( V_3 ) + V_29 ;
V_28 -> V_25 = V_40 -> V_47 ;
F_12 ( V_3 , V_28 , V_29 ) ;
return 1 ;
}
static int
F_26 ( int V_1 , struct V_2 * V_3 , struct V_38 * V_39 )
{
unsigned int V_29 ;
struct V_48 * V_18 , V_19 ;
struct V_2 * V_31 ;
T_4 V_49 ;
T_4 V_50 ;
T_3 V_51 ;
#ifdef F_19
if ( V_1 == V_41 )
V_29 = sizeof( struct V_52 ) ;
else
#endif
V_29 = F_27 ( V_3 ) ;
V_18 = F_2 ( V_3 , V_29 , sizeof( V_19 ) , & V_19 ) ;
if ( V_18 == NULL )
return 0 ;
V_49 = V_18 -> V_35 ;
V_51 = F_13 ( ( V_32 * ) V_18 , F_14 ( V_3 ) ) ;
F_15 (skb, iter)
V_51 = F_16 ( ( V_32 * ) V_31 -> V_34 ,
F_14 ( V_31 ) , V_51 ) ;
V_50 = F_17 ( V_51 ) ;
if ( V_50 != V_49 ) {
F_28 ( 0 , V_1 , V_39 , V_3 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_29 ( int V_53 )
{
if ( V_53 >= V_54 )
return L_2 ;
if ( V_55 [ V_53 ] )
return V_55 [ V_53 ] ;
return L_3 ;
}
static inline void
F_30 ( struct V_4 * V_5 , struct V_7 * V_40 ,
int V_56 , const struct V_2 * V_3 )
{
T_1 V_57 , * V_17 ;
unsigned char V_58 ;
int V_59 , V_60 ;
int V_61 , V_62 ;
#ifdef F_19
V_61 = V_40 -> V_1 == V_63 ? F_27 ( V_3 ) : sizeof( struct V_52 ) ;
#else
V_61 = F_27 ( V_3 ) ;
#endif
V_62 = V_61 + sizeof( T_2 ) ;
V_17 = F_2 ( V_3 , V_62 , sizeof( V_57 ) , & V_57 ) ;
if ( V_17 == NULL )
return;
V_58 = V_17 -> type ;
if ( ( V_17 -> type == V_64 ) ||
( V_17 -> type == V_65 ) ) {
int V_66 = F_31 ( V_17 -> V_67 ) ;
if ( V_66 >= sizeof( T_1 ) ) {
V_17 = F_2 ( V_3 , V_62 + F_32 ( V_66 , 4 ) ,
sizeof( V_57 ) , & V_57 ) ;
if ( V_17 && V_17 -> type == V_68 )
V_58 = V_17 -> type ;
}
}
V_59 = ( V_58 < sizeof( V_69 ) ) ?
V_69 [ V_58 ] : V_70 ;
if ( V_40 -> V_71 & V_72 ) {
if ( V_56 == V_73 )
V_40 -> V_71 &= ~ V_72 ;
else
V_56 = V_74 ;
}
V_60 = V_75 [ V_56 ] [ V_59 ] [ V_40 -> V_53 ] ;
if ( V_60 != V_40 -> V_53 ) {
struct V_76 * V_25 = V_40 -> V_25 ;
F_33 ( 8 , L_4
L_5 ,
V_5 -> V_39 -> V_77 ,
( ( V_56 == V_73 ) ?
L_6 : L_7 ) ,
F_34 ( V_40 -> V_1 , & V_40 -> V_24 ) ,
F_31 ( V_40 -> V_47 ) ,
F_34 ( V_40 -> V_1 , & V_40 -> V_78 ) ,
F_31 ( V_40 -> V_79 ) ,
F_29 ( V_40 -> V_53 ) ,
F_29 ( V_60 ) ,
F_35 ( & V_40 -> V_80 ) ) ;
if ( V_25 ) {
if ( ! ( V_40 -> V_71 & V_81 ) &&
( V_60 != V_82 ) ) {
F_36 ( & V_25 -> V_83 ) ;
F_37 ( & V_25 -> V_84 ) ;
V_40 -> V_71 |= V_81 ;
} else if ( ( V_40 -> V_71 & V_81 ) &&
( V_60 == V_82 ) ) {
F_37 ( & V_25 -> V_83 ) ;
F_36 ( & V_25 -> V_84 ) ;
V_40 -> V_71 &= ~ V_81 ;
}
}
}
if ( F_38 ( V_5 ) )
V_40 -> V_85 = V_5 -> V_86 [ V_40 -> V_53 = V_60 ] ;
else
V_40 -> V_85 = V_87 [ V_40 -> V_53 = V_60 ] ;
}
static void
F_39 ( struct V_7 * V_40 , int V_56 ,
const struct V_2 * V_3 , struct V_4 * V_5 )
{
F_40 ( & V_40 -> V_88 ) ;
F_30 ( V_5 , V_40 , V_56 , V_3 ) ;
F_41 ( & V_40 -> V_88 ) ;
}
static inline T_5 F_42 ( T_6 V_89 )
{
return ( ( ( V_90 V_91 ) V_89 >> V_92 ) ^ ( V_90 V_91 ) V_89 )
& V_93 ;
}
static int F_43 ( struct V_11 * V_11 , struct V_94 * V_95 )
{
struct V_94 * V_96 ;
T_5 V_97 ;
T_6 V_89 = V_95 -> V_89 ;
int V_98 = 0 ;
struct V_14 * V_15 = F_4 ( V_11 ) ;
struct V_4 * V_5 = F_44 ( V_11 , V_99 ) ;
V_97 = F_42 ( V_89 ) ;
F_45 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_96 -> V_89 == V_89 ) {
V_98 = - V_100 ;
goto V_101;
}
}
F_46 ( & V_95 -> V_102 , & V_15 -> V_103 [ V_97 ] ) ;
F_37 ( & V_5 -> V_104 ) ;
V_101:
return V_98 ;
}
static void F_47 ( struct V_11 * V_11 , struct V_94 * V_95 )
{
struct V_4 * V_5 = F_44 ( V_11 , V_99 ) ;
F_36 ( & V_5 -> V_104 ) ;
F_48 ( & V_95 -> V_102 ) ;
}
static int F_49 ( struct V_7 * V_40 )
{
struct V_14 * V_15 = F_4 ( F_50 ( V_40 ) ) ;
int V_97 ;
struct V_94 * V_95 ;
int V_105 = 0 ;
if ( F_51 ( V_40 ) != V_106 )
return 0 ;
V_97 = F_42 ( V_40 -> V_46 ) ;
F_5 () ;
F_52 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_95 -> V_89 == V_40 -> V_46 ) {
if ( F_21 ( ! F_53 ( V_95 ) ) )
break;
F_9 () ;
F_33 ( 9 , L_8
L_9 ,
V_107 ,
F_34 ( V_40 -> V_1 , & V_40 -> V_78 ) ,
F_31 ( V_40 -> V_79 ) ,
F_34 ( V_40 -> V_1 , & V_40 -> V_108 ) ,
F_31 ( V_40 -> V_46 ) ,
V_95 -> V_77 , F_31 ( V_95 -> V_89 ) ) ;
V_40 -> V_43 = V_95 ;
if ( V_95 -> V_109 )
V_105 = V_95 -> V_109 ( V_95 , V_40 ) ;
goto V_101;
}
}
F_9 () ;
V_101:
return V_105 ;
}
static int F_54 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_14 * V_15 = F_4 ( V_11 ) ;
F_55 ( V_15 -> V_103 , V_110 ) ;
V_5 -> V_86 = F_56 ( ( int * ) V_87 ,
sizeof( V_87 ) ) ;
if ( ! V_5 -> V_86 )
return - V_111 ;
return 0 ;
}
static void F_57 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_58 ( V_5 -> V_86 ) ;
}
