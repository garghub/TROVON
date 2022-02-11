static int
F_1 ( int V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int * V_6 , struct V_7 * * V_8 )
{
struct V_9 * V_9 ;
struct V_10 * V_11 ;
T_1 V_12 , * V_13 ;
T_2 * V_14 , V_15 ;
struct V_16 V_17 ;
F_2 ( V_1 , F_3 ( V_3 ) , & V_17 ) ;
V_14 = F_4 ( V_3 , V_17 . V_18 , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return 0 ;
V_13 = F_4 ( V_3 , V_17 . V_18 + sizeof( T_2 ) ,
sizeof( V_12 ) , & V_12 ) ;
if ( V_13 == NULL )
return 0 ;
V_9 = F_5 ( V_3 ) ;
if ( ( V_13 -> type == V_19 ) &&
( V_11 = F_6 ( V_9 , V_1 , V_3 -> V_20 , V_17 . V_21 ,
& V_17 . V_22 , V_14 -> V_23 ) ) ) {
int V_24 ;
if ( F_7 ( F_8 ( V_9 ) ) ) {
F_9 ( V_11 ) ;
* V_6 = V_25 ;
return 0 ;
}
* V_8 = F_10 ( V_11 , V_3 , V_5 , & V_24 ) ;
if ( ! * V_8 && V_24 <= 0 ) {
if ( ! V_24 )
* V_6 = F_11 ( V_11 , V_3 , V_5 ) ;
else {
F_9 ( V_11 ) ;
* V_6 = V_25 ;
}
return 0 ;
}
F_9 ( V_11 ) ;
}
return 1 ;
}
static int
F_12 ( struct V_2 * V_3 ,
struct V_26 * V_27 , struct V_7 * V_28 )
{
T_2 * V_29 ;
unsigned int V_30 ;
struct V_2 * V_31 ;
T_3 V_32 ;
#ifdef F_13
if ( V_28 -> V_1 == V_33 )
V_30 = sizeof( struct V_34 ) ;
else
#endif
V_30 = F_14 ( V_3 ) ;
if ( ! F_15 ( V_3 , V_30 + sizeof( * V_29 ) ) )
return 0 ;
if ( F_16 ( V_28 -> V_35 != NULL ) ) {
if ( V_27 -> V_36 && ! V_27 -> V_36 ( V_28 -> V_1 , V_3 , V_27 ) )
return 0 ;
if ( ! F_17 ( V_28 , V_3 ) )
return 0 ;
}
V_29 = ( void * ) F_3 ( V_3 ) + V_30 ;
V_29 -> V_37 = V_28 -> V_38 ;
V_32 = F_18 ( ( V_39 * ) V_29 , F_19 ( V_3 ) - V_30 ) ;
F_20 (skb, iter)
V_32 = F_21 ( ( V_39 * ) V_31 -> V_40 , F_19 ( V_31 ) ,
V_32 ) ;
V_32 = F_22 ( V_32 ) ;
V_29 -> V_41 = V_32 ;
return 1 ;
}
static int
F_23 ( struct V_2 * V_3 ,
struct V_26 * V_27 , struct V_7 * V_28 )
{
T_2 * V_29 ;
unsigned int V_30 ;
struct V_2 * V_31 ;
T_3 V_32 ;
#ifdef F_13
if ( V_28 -> V_1 == V_33 )
V_30 = sizeof( struct V_34 ) ;
else
#endif
V_30 = F_14 ( V_3 ) ;
if ( ! F_15 ( V_3 , V_30 + sizeof( * V_29 ) ) )
return 0 ;
if ( F_16 ( V_28 -> V_35 != NULL ) ) {
if ( V_27 -> V_36 && ! V_27 -> V_36 ( V_28 -> V_1 , V_3 , V_27 ) )
return 0 ;
if ( ! F_24 ( V_28 , V_3 ) )
return 0 ;
}
V_29 = ( void * ) F_3 ( V_3 ) + V_30 ;
V_29 -> V_23 = V_28 -> V_42 ;
V_32 = F_18 ( ( V_39 * ) V_29 , F_19 ( V_3 ) - V_30 ) ;
F_20 (skb, iter)
V_32 = F_21 ( ( V_39 * ) V_31 -> V_40 , F_19 ( V_31 ) ,
V_32 ) ;
V_32 = F_22 ( V_32 ) ;
V_29 -> V_41 = V_32 ;
return 1 ;
}
static int
F_25 ( int V_1 , struct V_2 * V_3 , struct V_26 * V_27 )
{
unsigned int V_30 ;
struct V_43 * V_14 , V_15 ;
struct V_2 * V_31 ;
T_4 V_44 ;
T_4 V_45 ;
T_5 V_46 ;
#ifdef F_13
if ( V_1 == V_33 )
V_30 = sizeof( struct V_34 ) ;
else
#endif
V_30 = F_14 ( V_3 ) ;
V_14 = F_4 ( V_3 , V_30 , sizeof( V_15 ) , & V_15 ) ;
if ( V_14 == NULL )
return 0 ;
V_44 = V_14 -> V_41 ;
V_46 = F_18 ( ( V_47 * ) V_14 , F_19 ( V_3 ) ) ;
F_20 (skb, iter)
V_46 = F_21 ( ( V_47 * ) V_31 -> V_40 ,
F_19 ( V_31 ) , V_46 ) ;
V_45 = F_22 ( V_46 ) ;
if ( V_45 != V_44 ) {
F_26 ( 0 , V_1 , V_27 , V_3 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_27 ( int V_48 )
{
if ( V_48 >= V_49 )
return L_2 ;
if ( V_50 [ V_48 ] )
return V_50 [ V_48 ] ;
return L_3 ;
}
static inline void
F_28 ( struct V_4 * V_5 , struct V_7 * V_28 ,
int V_51 , const struct V_2 * V_3 )
{
T_1 V_52 , * V_13 ;
unsigned char V_53 ;
int V_54 , V_55 ;
int V_56 ;
#ifdef F_13
V_56 = V_28 -> V_1 == V_57 ? F_14 ( V_3 ) : sizeof( struct V_34 ) ;
#else
V_56 = F_14 ( V_3 ) ;
#endif
V_13 = F_4 ( V_3 , V_56 + sizeof( T_2 ) ,
sizeof( V_52 ) , & V_52 ) ;
if ( V_13 == NULL )
return;
V_53 = V_13 -> type ;
if ( ( V_13 -> type == V_58 ) ||
( V_13 -> type == V_59 ) ) {
V_13 = F_4 ( V_3 , ( V_56 + sizeof( T_2 ) +
V_13 -> V_60 ) , sizeof( V_52 ) , & V_52 ) ;
if ( V_13 ) {
if ( V_13 -> type == V_61 )
V_53 = V_13 -> type ;
}
}
V_54 = V_62 [ V_53 ] ;
if ( V_51 == V_63 )
V_54 ++ ;
V_55 = V_64 [ V_28 -> V_48 ] [ V_54 ] . V_55 ;
if ( V_55 != V_28 -> V_48 ) {
struct V_65 * V_23 = V_28 -> V_23 ;
F_29 ( 8 , L_4
L_5 ,
V_5 -> V_27 -> V_66 ,
( ( V_51 == V_63 ) ?
L_6 : L_7 ) ,
F_30 ( V_28 -> V_1 , & V_28 -> V_22 ) ,
F_31 ( V_28 -> V_42 ) ,
F_30 ( V_28 -> V_1 , & V_28 -> V_67 ) ,
F_31 ( V_28 -> V_68 ) ,
F_27 ( V_28 -> V_48 ) ,
F_27 ( V_55 ) ,
F_32 ( & V_28 -> V_69 ) ) ;
if ( V_23 ) {
if ( ! ( V_28 -> V_70 & V_71 ) &&
( V_55 != V_72 ) ) {
F_33 ( & V_23 -> V_73 ) ;
F_34 ( & V_23 -> V_74 ) ;
V_28 -> V_70 |= V_71 ;
} else if ( ( V_28 -> V_70 & V_71 ) &&
( V_55 == V_72 ) ) {
F_34 ( & V_23 -> V_73 ) ;
F_33 ( & V_23 -> V_74 ) ;
V_28 -> V_70 &= ~ V_71 ;
}
}
}
if ( F_35 ( V_5 ) )
V_28 -> V_75 = V_5 -> V_76 [ V_28 -> V_48 = V_55 ] ;
else
V_28 -> V_75 = V_77 [ V_28 -> V_48 = V_55 ] ;
}
static void
F_36 ( struct V_7 * V_28 , int V_51 ,
const struct V_2 * V_3 , struct V_4 * V_5 )
{
F_37 ( & V_28 -> V_78 ) ;
F_28 ( V_5 , V_28 , V_51 , V_3 ) ;
F_38 ( & V_28 -> V_78 ) ;
}
static inline T_6 F_39 ( T_7 V_79 )
{
return ( ( ( V_80 V_81 ) V_79 >> V_82 ) ^ ( V_80 V_81 ) V_79 )
& V_83 ;
}
static int F_40 ( struct V_9 * V_9 , struct V_84 * V_85 )
{
struct V_84 * V_86 ;
T_6 V_87 ;
T_7 V_79 = V_85 -> V_79 ;
int V_88 = 0 ;
struct V_89 * V_90 = F_8 ( V_9 ) ;
struct V_4 * V_5 = F_41 ( V_9 , V_91 ) ;
V_87 = F_39 ( V_79 ) ;
F_42 ( & V_90 -> V_92 ) ;
F_43 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_86 -> V_79 == V_79 ) {
V_88 = - V_93 ;
goto V_94;
}
}
F_44 ( & V_85 -> V_95 , & V_90 -> V_96 [ V_87 ] ) ;
F_34 ( & V_5 -> V_97 ) ;
V_94:
F_45 ( & V_90 -> V_92 ) ;
return V_88 ;
}
static void F_46 ( struct V_9 * V_9 , struct V_84 * V_85 )
{
struct V_89 * V_90 = F_8 ( V_9 ) ;
struct V_4 * V_5 = F_41 ( V_9 , V_91 ) ;
F_42 ( & V_90 -> V_92 ) ;
F_33 ( & V_5 -> V_97 ) ;
F_47 ( & V_85 -> V_95 ) ;
F_45 ( & V_90 -> V_92 ) ;
}
static int F_48 ( struct V_7 * V_28 )
{
struct V_89 * V_90 = F_8 ( F_49 ( V_28 ) ) ;
int V_87 ;
struct V_84 * V_85 ;
int V_98 = 0 ;
if ( F_50 ( V_28 ) != V_99 )
return 0 ;
V_87 = F_39 ( V_28 -> V_38 ) ;
F_37 ( & V_90 -> V_92 ) ;
F_43 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_85 -> V_79 == V_28 -> V_38 ) {
if ( F_16 ( ! F_51 ( V_85 ) ) )
break;
F_38 ( & V_90 -> V_92 ) ;
F_29 ( 9 , L_8
L_9 ,
V_100 ,
F_30 ( V_28 -> V_1 , & V_28 -> V_67 ) ,
F_31 ( V_28 -> V_68 ) ,
F_30 ( V_28 -> V_1 , & V_28 -> V_101 ) ,
F_31 ( V_28 -> V_38 ) ,
V_85 -> V_66 , F_31 ( V_85 -> V_79 ) ) ;
V_28 -> V_35 = V_85 ;
if ( V_85 -> V_102 )
V_98 = V_85 -> V_102 ( V_85 , V_28 ) ;
goto V_94;
}
}
F_38 ( & V_90 -> V_92 ) ;
V_94:
return V_98 ;
}
static void F_52 ( struct V_9 * V_9 , struct V_4 * V_5 )
{
struct V_89 * V_90 = F_8 ( V_9 ) ;
F_53 ( V_90 -> V_96 , V_103 ) ;
F_54 ( & V_90 -> V_92 ) ;
V_5 -> V_76 = F_55 ( ( int * ) V_77 ,
sizeof( V_77 ) ) ;
}
static void F_56 ( struct V_9 * V_9 , struct V_4 * V_5 )
{
F_57 ( V_5 -> V_76 ) ;
}
