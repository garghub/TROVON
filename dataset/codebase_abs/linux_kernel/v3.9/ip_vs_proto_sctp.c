static int
F_1 ( int V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int * V_6 , struct V_7 * * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_11 ;
struct V_12 * V_13 ;
T_1 V_14 , * V_15 ;
T_2 * V_16 , V_17 ;
V_16 = F_2 ( V_3 , V_10 -> V_18 , sizeof( V_17 ) , & V_17 ) ;
if ( V_16 == NULL )
return 0 ;
V_15 = F_2 ( V_3 , V_10 -> V_18 + sizeof( T_2 ) ,
sizeof( V_14 ) , & V_14 ) ;
if ( V_15 == NULL )
return 0 ;
V_11 = F_3 ( V_3 ) ;
if ( ( V_15 -> type == V_19 ) &&
( V_13 = F_4 ( V_11 , V_1 , V_3 -> V_20 , V_10 -> V_21 ,
& V_10 -> V_22 , V_16 -> V_23 ) ) ) {
int V_24 ;
if ( F_5 ( F_6 ( V_11 ) ) ) {
F_7 ( V_13 ) ;
* V_6 = V_25 ;
return 0 ;
}
* V_8 = F_8 ( V_13 , V_3 , V_5 , & V_24 , V_10 ) ;
if ( ! * V_8 && V_24 <= 0 ) {
if ( ! V_24 )
* V_6 = F_9 ( V_13 , V_3 , V_5 , V_10 ) ;
else {
F_7 ( V_13 ) ;
* V_6 = V_25 ;
}
return 0 ;
}
F_7 ( V_13 ) ;
}
return 1 ;
}
static void F_10 ( struct V_2 * V_3 , T_2 * V_26 ,
unsigned int V_27 )
{
T_3 V_28 ;
struct V_2 * V_29 ;
V_28 = F_11 ( ( V_30 * ) V_26 , F_12 ( V_3 ) - V_27 ) ;
F_13 (skb, iter)
V_28 = F_14 ( ( V_31 * ) V_29 -> V_32 ,
F_12 ( V_29 ) , V_28 ) ;
V_26 -> V_33 = F_15 ( V_28 ) ;
V_3 -> V_34 = V_35 ;
}
static int
F_16 ( struct V_2 * V_3 , struct V_36 * V_37 ,
struct V_7 * V_38 , struct V_9 * V_10 )
{
T_2 * V_26 ;
unsigned int V_27 = V_10 -> V_18 ;
#ifdef F_17
if ( V_38 -> V_1 == V_39 && V_10 -> V_40 )
return 1 ;
#endif
if ( ! F_18 ( V_3 , V_27 + sizeof( * V_26 ) ) )
return 0 ;
if ( F_19 ( V_38 -> V_41 != NULL ) ) {
if ( V_37 -> V_42 && ! V_37 -> V_42 ( V_38 -> V_1 , V_3 , V_37 ) )
return 0 ;
if ( ! F_20 ( V_38 , V_3 ) )
return 0 ;
}
V_26 = ( void * ) F_21 ( V_3 ) + V_27 ;
V_26 -> V_43 = V_38 -> V_44 ;
F_10 ( V_3 , V_26 , V_27 ) ;
return 1 ;
}
static int
F_22 ( struct V_2 * V_3 , struct V_36 * V_37 ,
struct V_7 * V_38 , struct V_9 * V_10 )
{
T_2 * V_26 ;
unsigned int V_27 = V_10 -> V_18 ;
#ifdef F_17
if ( V_38 -> V_1 == V_39 && V_10 -> V_40 )
return 1 ;
#endif
if ( ! F_18 ( V_3 , V_27 + sizeof( * V_26 ) ) )
return 0 ;
if ( F_19 ( V_38 -> V_41 != NULL ) ) {
if ( V_37 -> V_42 && ! V_37 -> V_42 ( V_38 -> V_1 , V_3 , V_37 ) )
return 0 ;
if ( ! F_23 ( V_38 , V_3 ) )
return 0 ;
}
V_26 = ( void * ) F_21 ( V_3 ) + V_27 ;
V_26 -> V_23 = V_38 -> V_45 ;
F_10 ( V_3 , V_26 , V_27 ) ;
return 1 ;
}
static int
F_24 ( int V_1 , struct V_2 * V_3 , struct V_36 * V_37 )
{
unsigned int V_27 ;
struct V_46 * V_16 , V_17 ;
struct V_2 * V_29 ;
T_4 V_47 ;
T_4 V_48 ;
T_3 V_49 ;
#ifdef F_17
if ( V_1 == V_39 )
V_27 = sizeof( struct V_50 ) ;
else
#endif
V_27 = F_25 ( V_3 ) ;
V_16 = F_2 ( V_3 , V_27 , sizeof( V_17 ) , & V_17 ) ;
if ( V_16 == NULL )
return 0 ;
V_47 = V_16 -> V_33 ;
V_49 = F_11 ( ( V_30 * ) V_16 , F_12 ( V_3 ) ) ;
F_13 (skb, iter)
V_49 = F_14 ( ( V_30 * ) V_29 -> V_32 ,
F_12 ( V_29 ) , V_49 ) ;
V_48 = F_15 ( V_49 ) ;
if ( V_48 != V_47 ) {
F_26 ( 0 , V_1 , V_37 , V_3 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_27 ( int V_51 )
{
if ( V_51 >= V_52 )
return L_2 ;
if ( V_53 [ V_51 ] )
return V_53 [ V_51 ] ;
return L_3 ;
}
static inline void
F_28 ( struct V_4 * V_5 , struct V_7 * V_38 ,
int V_54 , const struct V_2 * V_3 )
{
T_1 V_55 , * V_15 ;
unsigned char V_56 ;
int V_57 , V_58 ;
int V_59 , V_60 ;
#ifdef F_17
V_59 = V_38 -> V_1 == V_61 ? F_25 ( V_3 ) : sizeof( struct V_50 ) ;
#else
V_59 = F_25 ( V_3 ) ;
#endif
V_60 = V_59 + sizeof( T_2 ) ;
V_15 = F_2 ( V_3 , V_60 , sizeof( V_55 ) , & V_55 ) ;
if ( V_15 == NULL )
return;
V_56 = V_15 -> type ;
if ( ( V_15 -> type == V_62 ) ||
( V_15 -> type == V_63 ) ) {
int V_64 = F_29 ( V_15 -> V_65 ) ;
if ( V_64 >= sizeof( T_1 ) ) {
V_15 = F_2 ( V_3 , V_60 + F_30 ( V_64 , 4 ) ,
sizeof( V_55 ) , & V_55 ) ;
if ( V_15 && V_15 -> type == V_66 )
V_56 = V_15 -> type ;
}
}
V_57 = V_67 [ V_56 ] ;
if ( V_54 == V_68 )
V_57 ++ ;
V_58 = V_69 [ V_38 -> V_51 ] [ V_57 ] . V_58 ;
if ( V_58 != V_38 -> V_51 ) {
struct V_70 * V_23 = V_38 -> V_23 ;
F_31 ( 8 , L_4
L_5 ,
V_5 -> V_37 -> V_71 ,
( ( V_54 == V_68 ) ?
L_6 : L_7 ) ,
F_32 ( V_38 -> V_1 , & V_38 -> V_22 ) ,
F_29 ( V_38 -> V_45 ) ,
F_32 ( V_38 -> V_1 , & V_38 -> V_72 ) ,
F_29 ( V_38 -> V_73 ) ,
F_27 ( V_38 -> V_51 ) ,
F_27 ( V_58 ) ,
F_33 ( & V_38 -> V_74 ) ) ;
if ( V_23 ) {
if ( ! ( V_38 -> V_75 & V_76 ) &&
( V_58 != V_77 ) ) {
F_34 ( & V_23 -> V_78 ) ;
F_35 ( & V_23 -> V_79 ) ;
V_38 -> V_75 |= V_76 ;
} else if ( ( V_38 -> V_75 & V_76 ) &&
( V_58 == V_77 ) ) {
F_35 ( & V_23 -> V_78 ) ;
F_34 ( & V_23 -> V_79 ) ;
V_38 -> V_75 &= ~ V_76 ;
}
}
}
if ( F_36 ( V_5 ) )
V_38 -> V_80 = V_5 -> V_81 [ V_38 -> V_51 = V_58 ] ;
else
V_38 -> V_80 = V_82 [ V_38 -> V_51 = V_58 ] ;
}
static void
F_37 ( struct V_7 * V_38 , int V_54 ,
const struct V_2 * V_3 , struct V_4 * V_5 )
{
F_38 ( & V_38 -> V_83 ) ;
F_28 ( V_5 , V_38 , V_54 , V_3 ) ;
F_39 ( & V_38 -> V_83 ) ;
}
static inline T_5 F_40 ( T_6 V_84 )
{
return ( ( ( V_85 V_86 ) V_84 >> V_87 ) ^ ( V_85 V_86 ) V_84 )
& V_88 ;
}
static int F_41 ( struct V_11 * V_11 , struct V_89 * V_90 )
{
struct V_89 * V_91 ;
T_5 V_92 ;
T_6 V_84 = V_90 -> V_84 ;
int V_93 = 0 ;
struct V_94 * V_95 = F_6 ( V_11 ) ;
struct V_4 * V_5 = F_42 ( V_11 , V_96 ) ;
V_92 = F_40 ( V_84 ) ;
F_43 ( & V_95 -> V_97 ) ;
F_44 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_91 -> V_84 == V_84 ) {
V_93 = - V_98 ;
goto V_99;
}
}
F_45 ( & V_90 -> V_100 , & V_95 -> V_101 [ V_92 ] ) ;
F_35 ( & V_5 -> V_102 ) ;
V_99:
F_46 ( & V_95 -> V_97 ) ;
return V_93 ;
}
static void F_47 ( struct V_11 * V_11 , struct V_89 * V_90 )
{
struct V_94 * V_95 = F_6 ( V_11 ) ;
struct V_4 * V_5 = F_42 ( V_11 , V_96 ) ;
F_43 ( & V_95 -> V_97 ) ;
F_34 ( & V_5 -> V_102 ) ;
F_48 ( & V_90 -> V_100 ) ;
F_46 ( & V_95 -> V_97 ) ;
}
static int F_49 ( struct V_7 * V_38 )
{
struct V_94 * V_95 = F_6 ( F_50 ( V_38 ) ) ;
int V_92 ;
struct V_89 * V_90 ;
int V_103 = 0 ;
if ( F_51 ( V_38 ) != V_104 )
return 0 ;
V_92 = F_40 ( V_38 -> V_44 ) ;
F_38 ( & V_95 -> V_97 ) ;
F_44 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_90 -> V_84 == V_38 -> V_44 ) {
if ( F_19 ( ! F_52 ( V_90 ) ) )
break;
F_39 ( & V_95 -> V_97 ) ;
F_31 ( 9 , L_8
L_9 ,
V_105 ,
F_32 ( V_38 -> V_1 , & V_38 -> V_72 ) ,
F_29 ( V_38 -> V_73 ) ,
F_32 ( V_38 -> V_1 , & V_38 -> V_106 ) ,
F_29 ( V_38 -> V_44 ) ,
V_90 -> V_71 , F_29 ( V_90 -> V_84 ) ) ;
V_38 -> V_41 = V_90 ;
if ( V_90 -> V_107 )
V_103 = V_90 -> V_107 ( V_90 , V_38 ) ;
goto V_99;
}
}
F_39 ( & V_95 -> V_97 ) ;
V_99:
return V_103 ;
}
static int F_53 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_94 * V_95 = F_6 ( V_11 ) ;
F_54 ( V_95 -> V_101 , V_108 ) ;
F_55 ( & V_95 -> V_97 ) ;
V_5 -> V_81 = F_56 ( ( int * ) V_82 ,
sizeof( V_82 ) ) ;
if ( ! V_5 -> V_81 )
return - V_109 ;
return 0 ;
}
static void F_57 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_58 ( V_5 -> V_81 ) ;
}
