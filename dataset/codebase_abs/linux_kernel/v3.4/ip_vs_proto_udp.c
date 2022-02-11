static int
F_1 ( int V_1 , struct V_2 * V_3 , struct V_4 * V_5 ,
int * V_6 , struct V_7 * * V_8 )
{
struct V_9 * V_9 ;
struct V_10 * V_11 ;
struct V_12 V_13 , * V_14 ;
struct V_15 V_16 ;
F_2 ( V_1 , F_3 ( V_3 ) , & V_16 ) ;
V_14 = F_4 ( V_3 , V_16 . V_17 , sizeof( V_13 ) , & V_13 ) ;
if ( V_14 == NULL ) {
* V_6 = V_18 ;
return 0 ;
}
V_9 = F_5 ( V_3 ) ;
V_11 = F_6 ( V_9 , V_1 , V_3 -> V_19 , V_16 . V_20 ,
& V_16 . V_21 , V_14 -> V_22 ) ;
if ( V_11 ) {
int V_23 ;
if ( F_7 ( F_8 ( V_9 ) ) ) {
F_9 ( V_11 ) ;
* V_6 = V_18 ;
return 0 ;
}
* V_8 = F_10 ( V_11 , V_3 , V_5 , & V_23 ) ;
if ( ! * V_8 && V_23 <= 0 ) {
if ( ! V_23 )
* V_6 = F_11 ( V_11 , V_3 , V_5 ) ;
else {
F_9 ( V_11 ) ;
* V_6 = V_18 ;
}
return 0 ;
}
F_9 ( V_11 ) ;
}
return 1 ;
}
static inline void
F_12 ( int V_1 , struct V_12 * V_24 ,
const union V_25 * V_26 ,
const union V_25 * V_27 ,
T_1 V_28 , T_1 V_29 )
{
#ifdef F_13
if ( V_1 == V_30 )
V_24 -> V_31 =
F_14 ( F_15 ( V_26 -> V_32 , V_27 -> V_32 ,
F_16 ( V_28 , V_29 ,
~ F_17 ( V_24 -> V_31 ) ) ) ) ;
else
#endif
V_24 -> V_31 =
F_14 ( F_18 ( V_26 -> V_33 , V_27 -> V_33 ,
F_16 ( V_28 , V_29 ,
~ F_17 ( V_24 -> V_31 ) ) ) ) ;
if ( ! V_24 -> V_31 )
V_24 -> V_31 = V_34 ;
}
static inline void
F_19 ( int V_1 , struct V_12 * V_24 ,
const union V_25 * V_26 ,
const union V_25 * V_27 ,
T_1 V_35 , T_1 V_36 )
{
#ifdef F_13
if ( V_1 == V_30 )
V_24 -> V_31 =
~ F_14 ( F_15 ( V_26 -> V_32 , V_27 -> V_32 ,
F_16 ( V_35 , V_36 ,
F_17 ( V_24 -> V_31 ) ) ) ) ;
else
#endif
V_24 -> V_31 =
~ F_14 ( F_18 ( V_26 -> V_33 , V_27 -> V_33 ,
F_16 ( V_35 , V_36 ,
F_17 ( V_24 -> V_31 ) ) ) ) ;
}
static int
F_20 ( struct V_2 * V_3 ,
struct V_37 * V_38 , struct V_7 * V_39 )
{
struct V_12 * V_40 ;
unsigned int V_41 ;
int V_35 ;
int V_42 = 0 ;
#ifdef F_13
if ( V_39 -> V_1 == V_30 )
V_41 = sizeof( struct V_43 ) ;
else
#endif
V_41 = F_21 ( V_3 ) ;
V_35 = V_3 -> V_17 - V_41 ;
if ( ! F_22 ( V_3 , V_41 + sizeof( * V_40 ) ) )
return 0 ;
if ( F_23 ( V_39 -> V_44 != NULL ) ) {
int V_45 ;
if ( V_38 -> V_46 && ! V_38 -> V_46 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_45 = F_24 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_45 == 1 )
V_35 = V_3 -> V_17 - V_41 ;
else
V_42 = 1 ;
}
V_40 = ( void * ) F_3 ( V_3 ) + V_41 ;
V_40 -> V_47 = V_39 -> V_48 ;
if ( V_3 -> V_49 == V_50 ) {
F_19 ( V_39 -> V_1 , V_40 , & V_39 -> V_21 , & V_39 -> V_51 ,
F_25 ( V_35 ) ,
F_25 ( V_3 -> V_17 - V_41 ) ) ;
} else if ( ! V_42 && ( V_40 -> V_31 != 0 ) ) {
F_12 ( V_39 -> V_1 , V_40 , & V_39 -> V_21 , & V_39 -> V_51 ,
V_39 -> V_52 , V_39 -> V_48 ) ;
if ( V_3 -> V_49 == V_53 )
V_3 -> V_49 = ( V_39 -> V_44 && V_38 -> V_46 ) ?
V_54 : V_55 ;
} else {
V_40 -> V_31 = 0 ;
V_3 -> V_56 = F_26 ( V_3 , V_41 , V_3 -> V_17 - V_41 , 0 ) ;
#ifdef F_13
if ( V_39 -> V_1 == V_30 )
V_40 -> V_31 = F_27 ( & V_39 -> V_51 . V_57 ,
& V_39 -> V_58 . V_57 ,
V_3 -> V_17 - V_41 ,
V_39 -> V_20 , V_3 -> V_56 ) ;
else
#endif
V_40 -> V_31 = F_28 ( V_39 -> V_51 . V_33 ,
V_39 -> V_58 . V_33 ,
V_3 -> V_17 - V_41 ,
V_39 -> V_20 ,
V_3 -> V_56 ) ;
if ( V_40 -> V_31 == 0 )
V_40 -> V_31 = V_34 ;
V_3 -> V_49 = V_54 ;
F_29 ( 11 , L_1 ,
V_38 -> V_59 , V_40 -> V_31 ,
( char * ) & ( V_40 -> V_31 ) - ( char * ) V_40 ) ;
}
return 1 ;
}
static int
F_30 ( struct V_2 * V_3 ,
struct V_37 * V_38 , struct V_7 * V_39 )
{
struct V_12 * V_40 ;
unsigned int V_41 ;
int V_35 ;
int V_42 = 0 ;
#ifdef F_13
if ( V_39 -> V_1 == V_30 )
V_41 = sizeof( struct V_43 ) ;
else
#endif
V_41 = F_21 ( V_3 ) ;
V_35 = V_3 -> V_17 - V_41 ;
if ( ! F_22 ( V_3 , V_41 + sizeof( * V_40 ) ) )
return 0 ;
if ( F_23 ( V_39 -> V_44 != NULL ) ) {
int V_45 ;
if ( V_38 -> V_46 && ! V_38 -> V_46 ( V_39 -> V_1 , V_3 , V_38 ) )
return 0 ;
if ( ! ( V_45 = F_31 ( V_39 , V_3 ) ) )
return 0 ;
if ( V_45 == 1 )
V_35 = V_3 -> V_17 - V_41 ;
else
V_42 = 1 ;
}
V_40 = ( void * ) F_3 ( V_3 ) + V_41 ;
V_40 -> V_22 = V_39 -> V_52 ;
if ( V_3 -> V_49 == V_50 ) {
F_19 ( V_39 -> V_1 , V_40 , & V_39 -> V_51 , & V_39 -> V_21 ,
F_25 ( V_35 ) ,
F_25 ( V_3 -> V_17 - V_41 ) ) ;
} else if ( ! V_42 && ( V_40 -> V_31 != 0 ) ) {
F_12 ( V_39 -> V_1 , V_40 , & V_39 -> V_51 , & V_39 -> V_21 ,
V_39 -> V_48 , V_39 -> V_52 ) ;
if ( V_3 -> V_49 == V_53 )
V_3 -> V_49 = ( V_39 -> V_44 && V_38 -> V_46 ) ?
V_54 : V_55 ;
} else {
V_40 -> V_31 = 0 ;
V_3 -> V_56 = F_26 ( V_3 , V_41 , V_3 -> V_17 - V_41 , 0 ) ;
#ifdef F_13
if ( V_39 -> V_1 == V_30 )
V_40 -> V_31 = F_27 ( & V_39 -> V_58 . V_57 ,
& V_39 -> V_21 . V_57 ,
V_3 -> V_17 - V_41 ,
V_39 -> V_20 , V_3 -> V_56 ) ;
else
#endif
V_40 -> V_31 = F_28 ( V_39 -> V_58 . V_33 ,
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
F_32 ( int V_1 , struct V_2 * V_3 , struct V_37 * V_38 )
{
struct V_12 V_13 , * V_14 ;
unsigned int V_41 ;
#ifdef F_13
if ( V_1 == V_30 )
V_41 = sizeof( struct V_43 ) ;
else
#endif
V_41 = F_21 ( V_3 ) ;
V_14 = F_4 ( V_3 , V_41 , sizeof( V_13 ) , & V_13 ) ;
if ( V_14 == NULL )
return 0 ;
if ( V_14 -> V_31 != 0 ) {
switch ( V_3 -> V_49 ) {
case V_55 :
V_3 -> V_56 = F_26 ( V_3 , V_41 ,
V_3 -> V_17 - V_41 , 0 ) ;
case V_53 :
#ifdef F_13
if ( V_1 == V_30 ) {
if ( F_27 ( & F_33 ( V_3 ) -> V_60 ,
& F_33 ( V_3 ) -> V_21 ,
V_3 -> V_17 - V_41 ,
F_33 ( V_3 ) -> V_61 ,
V_3 -> V_56 ) ) {
F_34 ( 0 , V_1 , V_38 , V_3 , 0 ,
L_2 ) ;
return 0 ;
}
} else
#endif
if ( F_28 ( F_35 ( V_3 ) -> V_60 ,
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
static inline T_2 F_36 ( T_1 V_62 )
{
return ( ( ( V_63 V_64 ) V_62 >> V_65 ) ^ ( V_63 V_64 ) V_62 )
& V_66 ;
}
static int F_37 ( struct V_9 * V_9 , struct V_67 * V_68 )
{
struct V_67 * V_69 ;
T_2 V_70 ;
T_1 V_62 = V_68 -> V_62 ;
int V_45 = 0 ;
struct V_71 * V_72 = F_8 ( V_9 ) ;
struct V_4 * V_5 = F_38 ( V_9 , V_73 ) ;
V_70 = F_36 ( V_62 ) ;
F_39 ( & V_72 -> V_74 ) ;
F_40 (i, &ipvs->udp_apps[hash], p_list) {
if ( V_69 -> V_62 == V_62 ) {
V_45 = - V_75 ;
goto V_76;
}
}
F_41 ( & V_68 -> V_77 , & V_72 -> V_78 [ V_70 ] ) ;
F_42 ( & V_5 -> V_79 ) ;
V_76:
F_43 ( & V_72 -> V_74 ) ;
return V_45 ;
}
static void
F_44 ( struct V_9 * V_9 , struct V_67 * V_68 )
{
struct V_4 * V_5 = F_38 ( V_9 , V_73 ) ;
struct V_71 * V_72 = F_8 ( V_9 ) ;
F_39 ( & V_72 -> V_74 ) ;
F_45 ( & V_5 -> V_79 ) ;
F_46 ( & V_68 -> V_77 ) ;
F_43 ( & V_72 -> V_74 ) ;
}
static int F_47 ( struct V_7 * V_39 )
{
struct V_71 * V_72 = F_8 ( F_48 ( V_39 ) ) ;
int V_70 ;
struct V_67 * V_68 ;
int V_80 = 0 ;
if ( F_49 ( V_39 ) != V_81 )
return 0 ;
V_70 = F_36 ( V_39 -> V_48 ) ;
F_50 ( & V_72 -> V_74 ) ;
F_40 (inc, &ipvs->udp_apps[hash], p_list) {
if ( V_68 -> V_62 == V_39 -> V_48 ) {
if ( F_23 ( ! F_51 ( V_68 ) ) )
break;
F_52 ( & V_72 -> V_74 ) ;
F_53 ( 9 , L_3
L_4 ,
V_82 ,
F_54 ( V_39 -> V_1 , & V_39 -> V_58 ) ,
F_55 ( V_39 -> V_83 ) ,
F_54 ( V_39 -> V_1 , & V_39 -> V_51 ) ,
F_55 ( V_39 -> V_48 ) ,
V_68 -> V_59 , F_55 ( V_68 -> V_62 ) ) ;
V_39 -> V_44 = V_68 ;
if ( V_68 -> V_84 )
V_80 = V_68 -> V_84 ( V_68 , V_39 ) ;
goto V_76;
}
}
F_52 ( & V_72 -> V_74 ) ;
V_76:
return V_80 ;
}
static const char * F_56 ( int V_85 )
{
if ( V_85 >= V_86 )
return L_5 ;
return V_87 [ V_85 ] ? V_87 [ V_85 ] : L_6 ;
}
static void
F_57 ( struct V_7 * V_39 , int V_88 ,
const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
if ( F_23 ( ! V_5 ) ) {
F_58 ( L_7 ) ;
return;
}
V_39 -> V_89 = V_5 -> V_90 [ V_91 ] ;
}
static int F_59 ( struct V_9 * V_9 , struct V_4 * V_5 )
{
struct V_71 * V_72 = F_8 ( V_9 ) ;
F_60 ( V_72 -> V_78 , V_92 ) ;
F_61 ( & V_72 -> V_74 ) ;
V_5 -> V_90 = F_62 ( ( int * ) V_93 ,
sizeof( V_93 ) ) ;
if ( ! V_5 -> V_90 )
return - V_94 ;
return 0 ;
}
static void F_63 ( struct V_9 * V_9 , struct V_4 * V_5 )
{
F_64 ( V_5 -> V_90 ) ;
}
