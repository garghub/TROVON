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
F_4 () ;
V_13 = F_5 ( V_11 , V_1 , V_3 -> V_19 , V_10 -> V_20 ,
& V_10 -> V_21 , V_16 -> V_22 ) ;
if ( V_13 ) {
int V_23 ;
if ( F_6 ( F_7 ( V_11 ) ) ) {
F_8 () ;
* V_6 = V_18 ;
return 0 ;
}
* V_8 = F_9 ( V_13 , V_3 , V_5 , & V_23 , V_10 ) ;
if ( ! * V_8 && V_23 <= 0 ) {
if ( ! V_23 )
* V_6 = F_10 ( V_13 , V_3 , V_5 , V_10 ) ;
else
* V_6 = V_18 ;
F_8 () ;
return 0 ;
}
}
F_8 () ;
return 1 ;
}
static inline void
F_11 ( int V_1 , struct V_14 * V_24 ,
const union V_25 * V_26 ,
const union V_25 * V_27 ,
T_1 V_28 , T_1 V_29 )
{
#ifdef F_12
if ( V_1 == V_30 )
V_24 -> V_31 =
F_13 ( F_14 ( V_26 -> V_32 , V_27 -> V_32 ,
F_15 ( V_28 , V_29 ,
~ F_16 ( V_24 -> V_31 ) ) ) ) ;
else
#endif
V_24 -> V_31 =
F_13 ( F_17 ( V_26 -> V_33 , V_27 -> V_33 ,
F_15 ( V_28 , V_29 ,
~ F_16 ( V_24 -> V_31 ) ) ) ) ;
if ( ! V_24 -> V_31 )
V_24 -> V_31 = V_34 ;
}
static inline void
F_18 ( int V_1 , struct V_14 * V_24 ,
const union V_25 * V_26 ,
const union V_25 * V_27 ,
T_1 V_35 , T_1 V_36 )
{
#ifdef F_12
if ( V_1 == V_30 )
V_24 -> V_31 =
~ F_13 ( F_14 ( V_26 -> V_32 , V_27 -> V_32 ,
F_15 ( V_35 , V_36 ,
F_16 ( V_24 -> V_31 ) ) ) ) ;
else
#endif
V_24 -> V_31 =
~ F_13 ( F_17 ( V_26 -> V_33 , V_27 -> V_33 ,
F_15 ( V_35 , V_36 ,
F_16 ( V_24 -> V_31 ) ) ) ) ;
}
static int
F_19 ( struct V_2 * V_3 , struct V_37 * V_38 ,
struct V_7 * V_39 , struct V_9 * V_10 )
{
struct V_14 * V_40 ;
unsigned int V_41 = V_10 -> V_17 ;
int V_35 ;
int V_42 = 0 ;
#ifdef F_12
if ( V_39 -> V_1 == V_30 && V_10 -> V_43 )
return 1 ;
#endif
V_35 = V_3 -> V_17 - V_41 ;
if ( ! F_20 ( V_3 , V_41 + sizeof( * V_40 ) ) )
return 0 ;
if ( F_21 ( V_39 -> V_44 != NULL ) ) {
int V_45 ;
if ( V_38 -> V_46 && ! V_38 -> V_46 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_45 = F_22 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_45 == 1 )
V_35 = V_3 -> V_17 - V_41 ;
else
V_42 = 1 ;
}
V_40 = ( void * ) F_23 ( V_3 ) + V_41 ;
V_40 -> V_47 = V_39 -> V_48 ;
if ( V_3 -> V_49 == V_50 ) {
F_18 ( V_39 -> V_1 , V_40 , & V_39 -> V_21 , & V_39 -> V_51 ,
F_24 ( V_35 ) ,
F_24 ( V_3 -> V_17 - V_41 ) ) ;
} else if ( ! V_42 && ( V_40 -> V_31 != 0 ) ) {
F_11 ( V_39 -> V_1 , V_40 , & V_39 -> V_21 , & V_39 -> V_51 ,
V_39 -> V_52 , V_39 -> V_48 ) ;
if ( V_3 -> V_49 == V_53 )
V_3 -> V_49 = ( V_39 -> V_44 && V_38 -> V_46 ) ?
V_54 : V_55 ;
} else {
V_40 -> V_31 = 0 ;
V_3 -> V_56 = F_25 ( V_3 , V_41 , V_3 -> V_17 - V_41 , 0 ) ;
#ifdef F_12
if ( V_39 -> V_1 == V_30 )
V_40 -> V_31 = F_26 ( & V_39 -> V_51 . V_57 ,
& V_39 -> V_58 . V_57 ,
V_3 -> V_17 - V_41 ,
V_39 -> V_20 , V_3 -> V_56 ) ;
else
#endif
V_40 -> V_31 = F_27 ( V_39 -> V_51 . V_33 ,
V_39 -> V_58 . V_33 ,
V_3 -> V_17 - V_41 ,
V_39 -> V_20 ,
V_3 -> V_56 ) ;
if ( V_40 -> V_31 == 0 )
V_40 -> V_31 = V_34 ;
V_3 -> V_49 = V_54 ;
F_28 ( 11 , L_1 ,
V_38 -> V_59 , V_40 -> V_31 ,
( char * ) & ( V_40 -> V_31 ) - ( char * ) V_40 ) ;
}
return 1 ;
}
static int
F_29 ( struct V_2 * V_3 , struct V_37 * V_38 ,
struct V_7 * V_39 , struct V_9 * V_10 )
{
struct V_14 * V_40 ;
unsigned int V_41 = V_10 -> V_17 ;
int V_35 ;
int V_42 = 0 ;
#ifdef F_12
if ( V_39 -> V_1 == V_30 && V_10 -> V_43 )
return 1 ;
#endif
V_35 = V_3 -> V_17 - V_41 ;
if ( ! F_20 ( V_3 , V_41 + sizeof( * V_40 ) ) )
return 0 ;
if ( F_21 ( V_39 -> V_44 != NULL ) ) {
int V_45 ;
if ( V_38 -> V_46 && ! V_38 -> V_46 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_45 = F_30 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_45 == 1 )
V_35 = V_3 -> V_17 - V_41 ;
else
V_42 = 1 ;
}
V_40 = ( void * ) F_23 ( V_3 ) + V_41 ;
V_40 -> V_22 = V_39 -> V_52 ;
if ( V_3 -> V_49 == V_50 ) {
F_18 ( V_39 -> V_1 , V_40 , & V_39 -> V_51 , & V_39 -> V_21 ,
F_24 ( V_35 ) ,
F_24 ( V_3 -> V_17 - V_41 ) ) ;
} else if ( ! V_42 && ( V_40 -> V_31 != 0 ) ) {
F_11 ( V_39 -> V_1 , V_40 , & V_39 -> V_51 , & V_39 -> V_21 ,
V_39 -> V_48 , V_39 -> V_52 ) ;
if ( V_3 -> V_49 == V_53 )
V_3 -> V_49 = ( V_39 -> V_44 && V_38 -> V_46 ) ?
V_54 : V_55 ;
} else {
V_40 -> V_31 = 0 ;
V_3 -> V_56 = F_25 ( V_3 , V_41 , V_3 -> V_17 - V_41 , 0 ) ;
#ifdef F_12
if ( V_39 -> V_1 == V_30 )
V_40 -> V_31 = F_26 ( & V_39 -> V_58 . V_57 ,
& V_39 -> V_21 . V_57 ,
V_3 -> V_17 - V_41 ,
V_39 -> V_20 , V_3 -> V_56 ) ;
else
#endif
V_40 -> V_31 = F_27 ( V_39 -> V_58 . V_33 ,
V_39 -> V_21 . V_33 ,
V_3 -> V_17 - V_41 ,
V_39 -> V_20 ,
V_3 -> V_56 ) ;
if ( V_40 -> V_31 == 0 )
V_40 -> V_31 = V_34 ;
V_3 -> V_49 = V_54 ;
}
return 1 ;
}
static int
F_31 ( int V_1 , struct V_2 * V_3 , struct V_37 * V_38 )
{
struct V_14 V_15 , * V_16 ;
unsigned int V_41 ;
#ifdef F_12
if ( V_1 == V_30 )
V_41 = sizeof( struct V_60 ) ;
else
#endif
V_41 = F_32 ( V_3 ) ;
V_16 = F_2 ( V_3 , V_41 , sizeof( V_15 ) , & V_15 ) ;
if ( V_16 == NULL )
return 0 ;
if ( V_16 -> V_31 != 0 ) {
switch ( V_3 -> V_49 ) {
case V_55 :
V_3 -> V_56 = F_25 ( V_3 , V_41 ,
V_3 -> V_17 - V_41 , 0 ) ;
case V_53 :
#ifdef F_12
if ( V_1 == V_30 ) {
if ( F_26 ( & F_33 ( V_3 ) -> V_61 ,
& F_33 ( V_3 ) -> V_21 ,
V_3 -> V_17 - V_41 ,
F_33 ( V_3 ) -> V_62 ,
V_3 -> V_56 ) ) {
F_34 ( 0 , V_1 , V_38 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_27 ( F_35 ( V_3 ) -> V_61 ,
F_35 ( V_3 ) -> V_21 ,
V_3 -> V_17 - V_41 ,
F_35 ( V_3 ) -> V_20 ,
V_3 -> V_56 ) ) {
F_34 ( 0 , V_1 , V_38 , V_3 , 0 ,
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
static inline T_2 F_36 ( T_1 V_63 )
{
return ( ( ( V_64 V_65 ) V_63 >> V_66 ) ^ ( V_64 V_65 ) V_63 )
& V_67 ;
}
static int F_37 ( struct V_11 * V_11 , struct V_68 * V_69 )
{
struct V_68 * V_70 ;
T_2 V_71 ;
T_1 V_63 = V_69 -> V_63 ;
int V_45 = 0 ;
struct V_72 * V_73 = F_7 ( V_11 ) ;
struct V_4 * V_5 = F_38 ( V_11 , V_74 ) ;
V_71 = F_36 ( V_63 ) ;
F_39 (i, &ipvs->udp_apps[hash], p_list) {
if ( V_70 -> V_63 == V_63 ) {
V_45 = - V_75 ;
goto V_76;
}
}
F_40 ( & V_69 -> V_77 , & V_73 -> V_78 [ V_71 ] ) ;
F_41 ( & V_5 -> V_79 ) ;
V_76:
return V_45 ;
}
static void
F_42 ( struct V_11 * V_11 , struct V_68 * V_69 )
{
struct V_4 * V_5 = F_38 ( V_11 , V_74 ) ;
F_43 ( & V_5 -> V_79 ) ;
F_44 ( & V_69 -> V_77 ) ;
}
static int F_45 ( struct V_7 * V_39 )
{
struct V_72 * V_73 = F_7 ( F_46 ( V_39 ) ) ;
int V_71 ;
struct V_68 * V_69 ;
int V_80 = 0 ;
if ( F_47 ( V_39 ) != V_81 )
return 0 ;
V_71 = F_36 ( V_39 -> V_48 ) ;
F_4 () ;
F_48 (inc, &ipvs->udp_apps[hash], p_list) {
if ( V_69 -> V_63 == V_39 -> V_48 ) {
if ( F_21 ( ! F_49 ( V_69 ) ) )
break;
F_8 () ;
F_50 ( 9 , L_3
L_4 ,
V_82 ,
F_51 ( V_39 -> V_1 , & V_39 -> V_58 ) ,
F_52 ( V_39 -> V_83 ) ,
F_51 ( V_39 -> V_1 , & V_39 -> V_51 ) ,
F_52 ( V_39 -> V_48 ) ,
V_69 -> V_59 , F_52 ( V_69 -> V_63 ) ) ;
V_39 -> V_44 = V_69 ;
if ( V_69 -> V_84 )
V_80 = V_69 -> V_84 ( V_69 , V_39 ) ;
goto V_76;
}
}
F_8 () ;
V_76:
return V_80 ;
}
static const char * F_53 ( int V_85 )
{
if ( V_85 >= V_86 )
return L_5 ;
return V_87 [ V_85 ] ? V_87 [ V_85 ] : L_6 ;
}
static void
F_54 ( struct V_7 * V_39 , int V_88 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( F_21 ( ! V_5 ) ) {
F_55 ( L_7 ) ;
return;
}
V_39 -> V_89 = V_5 -> V_90 [ V_91 ] ;
}
static int F_56 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
struct V_72 * V_73 = F_7 ( V_11 ) ;
F_57 ( V_73 -> V_78 , V_92 ) ;
V_5 -> V_90 = F_58 ( ( int * ) V_93 ,
sizeof( V_93 ) ) ;
if ( ! V_5 -> V_90 )
return - V_94 ;
return 0 ;
}
static void F_59 ( struct V_11 * V_11 , struct V_4 * V_5 )
{
F_60 ( V_5 -> V_90 ) ;
}
