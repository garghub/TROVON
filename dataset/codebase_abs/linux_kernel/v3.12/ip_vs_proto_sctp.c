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
V_28 -> V_30 = F_13 ( V_3 , V_29 ) ;
V_3 -> V_31 = V_32 ;
}
static int
F_14 ( struct V_2 * V_3 , struct V_33 * V_34 ,
struct V_7 * V_35 , struct V_9 * V_10 )
{
T_2 * V_28 ;
unsigned int V_29 = V_10 -> V_20 ;
#ifdef F_15
if ( V_35 -> V_1 == V_36 && V_10 -> V_37 )
return 1 ;
#endif
if ( ! F_16 ( V_3 , V_29 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_17 ( V_35 -> V_38 != NULL ) ) {
if ( V_34 -> V_39 && ! V_34 -> V_39 ( V_35 -> V_1 , V_3 , V_34 ) )
return 0 ;
if ( ! F_18 ( V_35 , V_3 ) )
return 0 ;
}
V_28 = ( void * ) F_19 ( V_3 ) + V_29 ;
V_28 -> V_40 = V_35 -> V_41 ;
F_12 ( V_3 , V_28 , V_29 ) ;
return 1 ;
}
static int
F_20 ( struct V_2 * V_3 , struct V_33 * V_34 ,
struct V_7 * V_35 , struct V_9 * V_10 )
{
T_2 * V_28 ;
unsigned int V_29 = V_10 -> V_20 ;
#ifdef F_15
if ( V_35 -> V_1 == V_36 && V_10 -> V_37 )
return 1 ;
#endif
if ( ! F_16 ( V_3 , V_29 + sizeof( * V_28 ) ) )
return 0 ;
if ( F_17 ( V_35 -> V_38 != NULL ) ) {
if ( V_34 -> V_39 && ! V_34 -> V_39 ( V_35 -> V_1 , V_3 , V_34 ) )
return 0 ;
if ( ! F_21 ( V_35 , V_3 ) )
return 0 ;
}
V_28 = ( void * ) F_19 ( V_3 ) + V_29 ;
V_28 -> V_25 = V_35 -> V_42 ;
F_12 ( V_3 , V_28 , V_29 ) ;
return 1 ;
}
static int
F_22 ( int V_1 , struct V_2 * V_3 , struct V_33 * V_34 )
{
unsigned int V_29 ;
struct V_43 * V_18 , V_19 ;
T_3 V_44 , V_45 ;
#ifdef F_15
if ( V_1 == V_36 )
V_29 = sizeof( struct V_46 ) ;
else
#endif
V_29 = F_23 ( V_3 ) ;
V_18 = F_2 ( V_3 , V_29 , sizeof( V_19 ) , & V_19 ) ;
if ( V_18 == NULL )
return 0 ;
V_44 = V_18 -> V_30 ;
V_45 = F_13 ( V_3 , V_29 ) ;
if ( V_45 != V_44 ) {
F_24 ( 0 , V_1 , V_34 , V_3 , 0 ,
L_1 ) ;
return 0 ;
}
return 1 ;
}
static const char * F_25 ( int V_47 )
{
if ( V_47 >= V_48 )
return L_2 ;
if ( V_49 [ V_47 ] )
return V_49 [ V_47 ] ;
return L_3 ;
}
static inline void
F_26 ( struct V_4 * V_5 , struct V_7 * V_35 ,
int V_50 , const struct V_2 * V_3 )
{
T_1 V_51 , * V_17 ;
unsigned char V_52 ;
int V_53 , V_54 ;
int V_55 , V_56 ;
#ifdef F_15
V_55 = V_35 -> V_1 == V_57 ? F_23 ( V_3 ) : sizeof( struct V_46 ) ;
#else
V_55 = F_23 ( V_3 ) ;
#endif
V_56 = V_55 + sizeof( T_2 ) ;
V_17 = F_2 ( V_3 , V_56 , sizeof( V_51 ) , & V_51 ) ;
if ( V_17 == NULL )
return;
V_52 = V_17 -> type ;
if ( ( V_17 -> type == V_58 ) ||
( V_17 -> type == V_59 ) ) {
int V_60 = F_27 ( V_17 -> V_61 ) ;
if ( V_60 >= sizeof( T_1 ) ) {
V_17 = F_2 ( V_3 , V_56 + F_28 ( V_60 , 4 ) ,
sizeof( V_51 ) , & V_51 ) ;
if ( V_17 && V_17 -> type == V_62 )
V_52 = V_17 -> type ;
}
}
V_53 = ( V_52 < sizeof( V_63 ) ) ?
V_63 [ V_52 ] : V_64 ;
if ( V_35 -> V_65 & V_66 ) {
if ( V_50 == V_67 )
V_35 -> V_65 &= ~ V_66 ;
else
V_50 = V_68 ;
}
V_54 = V_69 [ V_50 ] [ V_53 ] [ V_35 -> V_47 ] ;
if ( V_54 != V_35 -> V_47 ) {
struct V_70 * V_25 = V_35 -> V_25 ;
F_29 ( 8 , L_4
L_5 ,
V_5 -> V_34 -> V_71 ,
( ( V_50 == V_67 ) ?
L_6 : L_7 ) ,
F_30 ( V_35 -> V_1 , & V_35 -> V_24 ) ,
F_27 ( V_35 -> V_42 ) ,
F_30 ( V_35 -> V_1 , & V_35 -> V_72 ) ,
F_27 ( V_35 -> V_73 ) ,
F_25 ( V_35 -> V_47 ) ,
F_25 ( V_54 ) ,
F_31 ( & V_35 -> V_74 ) ) ;
if ( V_25 ) {
if ( ! ( V_35 -> V_65 & V_75 ) &&
( V_54 != V_76 ) ) {
F_32 ( & V_25 -> V_77 ) ;
F_33 ( & V_25 -> V_78 ) ;
V_35 -> V_65 |= V_75 ;
} else if ( ( V_35 -> V_65 & V_75 ) &&
( V_54 == V_76 ) ) {
F_33 ( & V_25 -> V_77 ) ;
F_32 ( & V_25 -> V_78 ) ;
V_35 -> V_65 &= ~ V_75 ;
}
}
}
if ( F_34 ( V_5 ) )
V_35 -> V_79 = V_5 -> V_80 [ V_35 -> V_47 = V_54 ] ;
else
V_35 -> V_79 = V_81 [ V_35 -> V_47 = V_54 ] ;
}
static void
F_35 ( struct V_7 * V_35 , int V_50 ,
const struct V_2 * V_3 , struct V_4 * V_5 )
{
F_36 ( & V_35 -> V_82 ) ;
F_26 ( V_5 , V_35 , V_50 , V_3 ) ;
F_37 ( & V_35 -> V_82 ) ;
}
static inline T_4 F_38 ( T_5 V_83 )
{
return ( ( ( V_84 V_85 ) V_83 >> V_86 ) ^ ( V_84 V_85 ) V_83 )
& V_87 ;
}
static int F_39 ( struct V_11 * V_11 , struct V_88 * V_89 )
{
struct V_88 * V_90 ;
T_4 V_91 ;
T_5 V_83 = V_89 -> V_83 ;
int V_92 = 0 ;
struct V_14 * V_15 = F_4 ( V_11 ) ;
struct V_4 * V_5 = F_40 ( V_11 , V_93 ) ;
V_91 = F_38 ( V_83 ) ;
F_41 (i, &ipvs->sctp_apps[hash], p_list) {
if ( V_90 -> V_83 == V_83 ) {
V_92 = - V_94 ;
goto V_95;
}
}
F_42 ( & V_89 -> V_96 , & V_15 -> V_97 [ V_91 ] ) ;
F_33 ( & V_5 -> V_98 ) ;
V_95:
return V_92 ;
}
static void F_43 ( struct V_11 * V_11 , struct V_88 * V_89 )
{
struct V_4 * V_5 = F_40 ( V_11 , V_93 ) ;
F_32 ( & V_5 -> V_98 ) ;
F_44 ( & V_89 -> V_96 ) ;
}
static int F_45 ( struct V_7 * V_35 )
{
struct V_14 * V_15 = F_4 ( F_46 ( V_35 ) ) ;
int V_91 ;
struct V_88 * V_89 ;
int V_99 = 0 ;
if ( F_47 ( V_35 ) != V_100 )
return 0 ;
V_91 = F_38 ( V_35 -> V_41 ) ;
F_5 () ;
F_48 (inc, &ipvs->sctp_apps[hash], p_list) {
if ( V_89 -> V_83 == V_35 -> V_41 ) {
if ( F_17 ( ! F_49 ( V_89 ) ) )
break;
F_9 () ;
F_29 ( 9 , L_8
L_9 ,
V_101 ,
F_30 ( V_35 -> V_1 , & V_35 -> V_72 ) ,
F_27 ( V_35 -> V_73 ) ,
F_30 ( V_35 -> V_1 , & V_35 -> V_102 ) ,
F_27 ( V_35 -> V_41 ) ,
V_89 -> V_71 , F_27 ( V_89 -> V_83 ) ) ;
V_35 -> V_38 = V_89 ;
if ( V_89 -> V_103 )
V_99 = V_89 -> V_103 ( V_89 , V_35 ) ;
goto V_95;
}
}
F_9 () ;
V_95:
return V_99 ;
}
static int F_50 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_14 * V_15 = F_4 ( V_11 ) ;
F_51 ( V_15 -> V_97 , V_104 ) ;
V_5 -> V_80 = F_52 ( ( int * ) V_81 ,
sizeof( V_81 ) ) ;
if ( ! V_5 -> V_80 )
return - V_105 ;
return 0 ;
}
static void F_53 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_54 ( V_5 -> V_80 ) ;
}
