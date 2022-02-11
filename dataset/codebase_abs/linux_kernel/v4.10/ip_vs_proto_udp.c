static int
F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 ,
int * V_8 , struct V_9 * * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 V_16 , * V_17 ;
T_1 V_18 [ 2 ] , * V_19 = NULL ;
if ( F_2 ( ! F_3 ( V_12 ) ) ) {
V_17 = F_4 ( V_5 , V_12 -> V_20 , sizeof( V_16 ) , & V_16 ) ;
if ( V_17 )
V_19 = & V_17 -> V_21 ;
} else {
V_19 = F_4 (
V_5 , V_12 -> V_20 , sizeof( V_18 ) , & V_18 ) ;
}
if ( ! V_19 ) {
* V_8 = V_22 ;
return 0 ;
}
F_5 () ;
if ( F_2 ( ! F_6 ( V_12 ) ) )
V_14 = F_7 ( V_2 , V_3 , V_5 -> V_23 , V_12 -> V_24 ,
& V_12 -> V_25 , V_19 [ 1 ] ) ;
else
V_14 = F_7 ( V_2 , V_3 , V_5 -> V_23 , V_12 -> V_24 ,
& V_12 -> V_26 , V_19 [ 0 ] ) ;
if ( V_14 ) {
int V_27 ;
if ( F_8 ( V_2 ) ) {
F_9 () ;
* V_8 = V_22 ;
return 0 ;
}
* V_10 = F_10 ( V_14 , V_5 , V_7 , & V_27 , V_12 ) ;
if ( ! * V_10 && V_27 <= 0 ) {
if ( ! V_27 )
* V_8 = F_11 ( V_14 , V_5 , V_7 , V_12 ) ;
else
* V_8 = V_22 ;
F_9 () ;
return 0 ;
}
}
F_9 () ;
return 1 ;
}
static inline void
F_12 ( int V_3 , struct V_15 * V_28 ,
const union V_29 * V_30 ,
const union V_29 * V_31 ,
T_1 V_32 , T_1 V_33 )
{
#ifdef F_13
if ( V_3 == V_34 )
V_28 -> V_35 =
F_14 ( F_15 ( V_30 -> V_36 , V_31 -> V_36 ,
F_16 ( V_32 , V_33 ,
~ F_17 ( V_28 -> V_35 ) ) ) ) ;
else
#endif
V_28 -> V_35 =
F_14 ( F_18 ( V_30 -> V_37 , V_31 -> V_37 ,
F_16 ( V_32 , V_33 ,
~ F_17 ( V_28 -> V_35 ) ) ) ) ;
if ( ! V_28 -> V_35 )
V_28 -> V_35 = V_38 ;
}
static inline void
F_19 ( int V_3 , struct V_15 * V_28 ,
const union V_29 * V_30 ,
const union V_29 * V_31 ,
T_1 V_39 , T_1 V_40 )
{
#ifdef F_13
if ( V_3 == V_34 )
V_28 -> V_35 =
~ F_14 ( F_15 ( V_30 -> V_36 , V_31 -> V_36 ,
F_16 ( V_39 , V_40 ,
F_17 ( V_28 -> V_35 ) ) ) ) ;
else
#endif
V_28 -> V_35 =
~ F_14 ( F_18 ( V_30 -> V_37 , V_31 -> V_37 ,
F_16 ( V_39 , V_40 ,
F_17 ( V_28 -> V_35 ) ) ) ) ;
}
static int
F_20 ( struct V_4 * V_5 , struct V_41 * V_42 ,
struct V_9 * V_43 , struct V_11 * V_12 )
{
struct V_15 * V_44 ;
unsigned int V_45 = V_12 -> V_20 ;
int V_39 ;
int V_46 = 0 ;
#ifdef F_13
if ( V_43 -> V_3 == V_34 && V_12 -> V_47 )
return 1 ;
#endif
V_39 = V_5 -> V_20 - V_45 ;
if ( ! F_21 ( V_5 , V_45 + sizeof( * V_44 ) ) )
return 0 ;
if ( F_22 ( V_43 -> V_48 != NULL ) ) {
int V_49 ;
if ( V_42 -> V_50 && ! V_42 -> V_50 ( V_43 -> V_3 , V_5 , V_42 ) )
return 0 ;
if ( ! ( V_49 = F_23 ( V_43 , V_5 ) ) )
return 0 ;
if ( V_49 == 1 )
V_39 = V_5 -> V_20 - V_45 ;
else
V_46 = 1 ;
}
V_44 = ( void * ) F_24 ( V_5 ) + V_45 ;
V_44 -> V_21 = V_43 -> V_51 ;
if ( V_5 -> V_52 == V_53 ) {
F_19 ( V_43 -> V_3 , V_44 , & V_43 -> V_25 , & V_43 -> V_54 ,
F_25 ( V_39 ) ,
F_25 ( V_5 -> V_20 - V_45 ) ) ;
} else if ( ! V_46 && ( V_44 -> V_35 != 0 ) ) {
F_12 ( V_43 -> V_3 , V_44 , & V_43 -> V_25 , & V_43 -> V_54 ,
V_43 -> V_55 , V_43 -> V_51 ) ;
if ( V_5 -> V_52 == V_56 )
V_5 -> V_52 = ( V_43 -> V_48 && V_42 -> V_50 ) ?
V_57 : V_58 ;
} else {
V_44 -> V_35 = 0 ;
V_5 -> V_59 = F_26 ( V_5 , V_45 , V_5 -> V_20 - V_45 , 0 ) ;
#ifdef F_13
if ( V_43 -> V_3 == V_34 )
V_44 -> V_35 = F_27 ( & V_43 -> V_54 . V_60 ,
& V_43 -> V_61 . V_60 ,
V_5 -> V_20 - V_45 ,
V_43 -> V_24 , V_5 -> V_59 ) ;
else
#endif
V_44 -> V_35 = F_28 ( V_43 -> V_54 . V_37 ,
V_43 -> V_61 . V_37 ,
V_5 -> V_20 - V_45 ,
V_43 -> V_24 ,
V_5 -> V_59 ) ;
if ( V_44 -> V_35 == 0 )
V_44 -> V_35 = V_38 ;
V_5 -> V_52 = V_57 ;
F_29 ( 11 , L_1 ,
V_42 -> V_62 , V_44 -> V_35 ,
( char * ) & ( V_44 -> V_35 ) - ( char * ) V_44 ) ;
}
return 1 ;
}
static int
F_30 ( struct V_4 * V_5 , struct V_41 * V_42 ,
struct V_9 * V_43 , struct V_11 * V_12 )
{
struct V_15 * V_44 ;
unsigned int V_45 = V_12 -> V_20 ;
int V_39 ;
int V_46 = 0 ;
#ifdef F_13
if ( V_43 -> V_3 == V_34 && V_12 -> V_47 )
return 1 ;
#endif
V_39 = V_5 -> V_20 - V_45 ;
if ( ! F_21 ( V_5 , V_45 + sizeof( * V_44 ) ) )
return 0 ;
if ( F_22 ( V_43 -> V_48 != NULL ) ) {
int V_49 ;
if ( V_42 -> V_50 && ! V_42 -> V_50 ( V_43 -> V_3 , V_5 , V_42 ) )
return 0 ;
if ( ! ( V_49 = F_31 ( V_43 , V_5 ) ) )
return 0 ;
if ( V_49 == 1 )
V_39 = V_5 -> V_20 - V_45 ;
else
V_46 = 1 ;
}
V_44 = ( void * ) F_24 ( V_5 ) + V_45 ;
V_44 -> V_63 = V_43 -> V_55 ;
if ( V_5 -> V_52 == V_53 ) {
F_19 ( V_43 -> V_3 , V_44 , & V_43 -> V_54 , & V_43 -> V_25 ,
F_25 ( V_39 ) ,
F_25 ( V_5 -> V_20 - V_45 ) ) ;
} else if ( ! V_46 && ( V_44 -> V_35 != 0 ) ) {
F_12 ( V_43 -> V_3 , V_44 , & V_43 -> V_54 , & V_43 -> V_25 ,
V_43 -> V_51 , V_43 -> V_55 ) ;
if ( V_5 -> V_52 == V_56 )
V_5 -> V_52 = ( V_43 -> V_48 && V_42 -> V_50 ) ?
V_57 : V_58 ;
} else {
V_44 -> V_35 = 0 ;
V_5 -> V_59 = F_26 ( V_5 , V_45 , V_5 -> V_20 - V_45 , 0 ) ;
#ifdef F_13
if ( V_43 -> V_3 == V_34 )
V_44 -> V_35 = F_27 ( & V_43 -> V_61 . V_60 ,
& V_43 -> V_25 . V_60 ,
V_5 -> V_20 - V_45 ,
V_43 -> V_24 , V_5 -> V_59 ) ;
else
#endif
V_44 -> V_35 = F_28 ( V_43 -> V_61 . V_37 ,
V_43 -> V_25 . V_37 ,
V_5 -> V_20 - V_45 ,
V_43 -> V_24 ,
V_5 -> V_59 ) ;
if ( V_44 -> V_35 == 0 )
V_44 -> V_35 = V_38 ;
V_5 -> V_52 = V_57 ;
}
return 1 ;
}
static int
F_32 ( int V_3 , struct V_4 * V_5 , struct V_41 * V_42 )
{
struct V_15 V_16 , * V_17 ;
unsigned int V_45 ;
#ifdef F_13
if ( V_3 == V_34 )
V_45 = sizeof( struct V_64 ) ;
else
#endif
V_45 = F_33 ( V_5 ) ;
V_17 = F_4 ( V_5 , V_45 , sizeof( V_16 ) , & V_16 ) ;
if ( V_17 == NULL )
return 0 ;
if ( V_17 -> V_35 != 0 ) {
switch ( V_5 -> V_52 ) {
case V_58 :
V_5 -> V_59 = F_26 ( V_5 , V_45 ,
V_5 -> V_20 - V_45 , 0 ) ;
case V_56 :
#ifdef F_13
if ( V_3 == V_34 ) {
if ( F_27 ( & F_34 ( V_5 ) -> V_26 ,
& F_34 ( V_5 ) -> V_25 ,
V_5 -> V_20 - V_45 ,
F_34 ( V_5 ) -> V_65 ,
V_5 -> V_59 ) ) {
F_35 ( 0 , V_3 , V_42 , V_5 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_28 ( F_36 ( V_5 ) -> V_26 ,
F_36 ( V_5 ) -> V_25 ,
V_5 -> V_20 - V_45 ,
F_36 ( V_5 ) -> V_24 ,
V_5 -> V_59 ) ) {
F_35 ( 0 , V_3 , V_42 , V_5 , 0 ,
L_2 ) ;
return 0 ;
}
break;
default:
break;
}
}
return 1 ;
}
static inline T_2 F_37 ( T_1 V_66 )
{
return ( ( ( V_67 V_68 ) V_66 >> V_69 ) ^ ( V_67 V_68 ) V_66 )
& V_70 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_71 * V_73 ;
T_2 V_74 ;
T_1 V_66 = V_72 -> V_66 ;
int V_49 = 0 ;
struct V_6 * V_7 = F_39 ( V_2 , V_75 ) ;
V_74 = F_37 ( V_66 ) ;
F_40 (i, &ipvs->udp_apps[hash], p_list) {
if ( V_73 -> V_66 == V_66 ) {
V_49 = - V_76 ;
goto V_77;
}
}
F_41 ( & V_72 -> V_78 , & V_2 -> V_79 [ V_74 ] ) ;
F_42 ( & V_7 -> V_80 ) ;
V_77:
return V_49 ;
}
static void
F_43 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_6 * V_7 = F_39 ( V_2 , V_75 ) ;
F_44 ( & V_7 -> V_80 ) ;
F_45 ( & V_72 -> V_78 ) ;
}
static int F_46 ( struct V_9 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
int V_74 ;
struct V_71 * V_72 ;
int V_81 = 0 ;
if ( F_47 ( V_43 ) != V_82 )
return 0 ;
V_74 = F_37 ( V_43 -> V_51 ) ;
F_5 () ;
F_48 (inc, &ipvs->udp_apps[hash], p_list) {
if ( V_72 -> V_66 == V_43 -> V_51 ) {
if ( F_22 ( ! F_49 ( V_72 ) ) )
break;
F_9 () ;
F_50 ( 9 , L_3
L_4 ,
V_83 ,
F_51 ( V_43 -> V_3 , & V_43 -> V_61 ) ,
F_52 ( V_43 -> V_84 ) ,
F_51 ( V_43 -> V_3 , & V_43 -> V_54 ) ,
F_52 ( V_43 -> V_51 ) ,
V_72 -> V_62 , F_52 ( V_72 -> V_66 ) ) ;
V_43 -> V_48 = V_72 ;
if ( V_72 -> V_85 )
V_81 = V_72 -> V_85 ( V_72 , V_43 ) ;
goto V_77;
}
}
F_9 () ;
V_77:
return V_81 ;
}
static const char * F_53 ( int V_86 )
{
if ( V_86 >= V_87 )
return L_5 ;
return V_88 [ V_86 ] ? V_88 [ V_86 ] : L_6 ;
}
static void
F_54 ( struct V_9 * V_43 , int V_89 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( F_22 ( ! V_7 ) ) {
F_55 ( L_7 ) ;
return;
}
V_43 -> V_90 = V_7 -> V_91 [ V_92 ] ;
}
static int F_56 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_57 ( V_2 -> V_79 , V_93 ) ;
V_7 -> V_91 = F_58 ( ( int * ) V_94 ,
sizeof( V_94 ) ) ;
if ( ! V_7 -> V_91 )
return - V_95 ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_60 ( V_7 -> V_91 ) ;
}
