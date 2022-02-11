static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 = 0 , V_10 = F_3 ( * V_4 ) ;
V_8 = & V_5 -> V_11 [ F_4 ( * V_4 ) ] ;
F_5 (dev, h, name_hlist) {
if ( ++ V_9 == V_10 )
return V_6 ;
}
return NULL ;
}
static inline struct V_1 * F_6 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_1 * V_6 ;
unsigned int V_12 ;
do {
V_6 = F_1 ( V_3 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_12 = F_4 ( * V_4 ) + 1 ;
* V_4 = F_7 ( V_12 , 1 ) ;
} while ( V_12 < V_13 );
return NULL ;
}
static void * F_8 ( struct V_2 * V_3 , T_1 * V_4 )
__acquires( T_2 )
{
F_9 () ;
if ( ! * V_4 )
return V_14 ;
if ( F_4 ( * V_4 ) >= V_13 )
return NULL ;
return F_6 ( V_3 , V_4 ) ;
}
static void * F_10 ( struct V_2 * V_3 , void * V_15 , T_1 * V_4 )
{
++ * V_4 ;
return F_6 ( V_3 , V_4 ) ;
}
static void F_11 ( struct V_2 * V_3 , void * V_15 )
__releases( T_2 )
{
F_12 () ;
}
static void F_13 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_16 V_17 ;
const struct V_16 * V_18 = F_14 ( V_6 , & V_17 ) ;
F_15 ( V_3 , L_1
L_2 ,
V_6 -> V_19 , V_18 -> V_20 , V_18 -> V_21 ,
V_18 -> V_22 ,
V_18 -> V_23 + V_18 -> V_24 ,
V_18 -> V_25 ,
V_18 -> V_26 + V_18 -> V_27 +
V_18 -> V_28 + V_18 -> V_29 ,
V_18 -> V_30 , V_18 -> V_31 ,
V_18 -> V_32 , V_18 -> V_33 ,
V_18 -> V_34 , V_18 -> V_35 ,
V_18 -> V_36 , V_18 -> V_37 ,
V_18 -> V_38 +
V_18 -> V_39 +
V_18 -> V_40 +
V_18 -> V_41 ,
V_18 -> V_42 ) ;
}
static int F_16 ( struct V_2 * V_3 , void * V_15 )
{
if ( V_15 == V_14 )
F_17 ( V_3 , L_3
L_4
L_5
L_6
L_7 ) ;
else
F_13 ( V_3 , V_15 ) ;
return 0 ;
}
static struct V_43 * F_18 ( T_1 * V_4 )
{
struct V_43 * V_44 = NULL ;
while ( * V_4 < V_45 )
if ( F_19 ( * V_4 ) ) {
V_44 = & F_20 ( V_43 , * V_4 ) ;
break;
} else
++ * V_4 ;
return V_44 ;
}
static void * F_21 ( struct V_2 * V_3 , T_1 * V_4 )
{
return F_18 ( V_4 ) ;
}
static void * F_22 ( struct V_2 * V_3 , void * V_15 , T_1 * V_4 )
{
++ * V_4 ;
return F_18 ( V_4 ) ;
}
static void F_23 ( struct V_2 * V_3 , void * V_15 )
{
}
static int F_24 ( struct V_2 * V_3 , void * V_15 )
{
struct V_43 * V_44 = V_15 ;
unsigned int V_46 = 0 ;
#ifdef F_25
struct V_47 * V_48 ;
F_9 () ;
V_48 = F_26 ( V_44 -> V_49 ) ;
if ( V_48 )
V_46 = V_48 -> V_9 ;
F_12 () ;
#endif
F_15 ( V_3 ,
L_8 ,
V_44 -> V_50 , V_44 -> V_51 , V_44 -> V_52 , 0 ,
0 , 0 , 0 , 0 ,
0 ,
V_44 -> V_53 , V_46 ) ;
return 0 ;
}
static int F_27 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_28 ( V_54 , V_55 , & V_56 ,
sizeof( struct V_57 ) ) ;
}
static int F_29 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_30 ( V_55 , & V_58 ) ;
}
static void * F_31 ( T_1 V_4 )
{
struct V_59 * V_60 = NULL ;
T_1 V_61 = 0 ;
int V_62 ;
F_32 (pt, &ptype_all, list) {
if ( V_61 == V_4 )
return V_60 ;
++ V_61 ;
}
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
F_32 (pt, &ptype_base[t], list) {
if ( V_61 == V_4 )
return V_60 ;
++ V_61 ;
}
}
return NULL ;
}
static void * F_33 ( struct V_2 * V_3 , T_1 * V_4 )
__acquires( T_2 )
{
F_9 () ;
return * V_4 ? F_31 ( * V_4 - 1 ) : V_14 ;
}
static void * F_34 ( struct V_2 * V_3 , void * V_15 , T_1 * V_4 )
{
struct V_59 * V_60 ;
struct V_64 * V_65 ;
int V_66 ;
++ * V_4 ;
if ( V_15 == V_14 )
return F_31 ( 0 ) ;
V_60 = V_15 ;
V_65 = V_60 -> V_67 . V_68 ;
if ( V_60 -> type == F_35 ( V_69 ) ) {
if ( V_65 != & V_70 )
goto V_71;
V_66 = 0 ;
V_65 = V_72 [ 0 ] . V_68 ;
} else
V_66 = F_36 ( V_60 -> type ) & V_73 ;
while ( V_65 == & V_72 [ V_66 ] ) {
if ( ++ V_66 >= V_63 )
return NULL ;
V_65 = V_72 [ V_66 ] . V_68 ;
}
V_71:
return F_37 ( V_65 , struct V_59 , V_67 ) ;
}
static void F_38 ( struct V_2 * V_3 , void * V_15 )
__releases( T_2 )
{
F_12 () ;
}
static int F_39 ( struct V_2 * V_3 , void * V_15 )
{
struct V_59 * V_60 = V_15 ;
if ( V_15 == V_14 )
F_17 ( V_3 , L_9 ) ;
else if ( V_60 -> V_6 == NULL || F_40 ( V_60 -> V_6 ) == F_2 ( V_3 ) ) {
if ( V_60 -> type == F_35 ( V_69 ) )
F_17 ( V_3 , L_10 ) ;
else
F_15 ( V_3 , L_11 , F_36 ( V_60 -> type ) ) ;
F_15 ( V_3 , L_12 ,
V_60 -> V_6 ? V_60 -> V_6 -> V_19 : L_13 , V_60 -> V_74 ) ;
}
return 0 ;
}
static int F_41 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_28 ( V_54 , V_55 , & V_75 ,
sizeof( struct V_57 ) ) ;
}
static int T_3 F_42 ( struct V_5 * V_5 )
{
int V_76 = - V_77 ;
if ( ! F_43 ( L_14 , V_78 , V_5 -> V_79 , & V_80 ) )
goto V_81;
if ( ! F_43 ( L_15 , V_78 , V_5 -> V_79 ,
& V_82 ) )
goto V_83;
if ( ! F_43 ( L_16 , V_78 , V_5 -> V_79 , & V_84 ) )
goto V_85;
if ( F_44 ( V_5 ) )
goto V_86;
V_76 = 0 ;
V_81:
return V_76 ;
V_86:
F_45 ( L_16 , V_5 -> V_79 ) ;
V_85:
F_45 ( L_15 , V_5 -> V_79 ) ;
V_83:
F_45 ( L_14 , V_5 -> V_79 ) ;
goto V_81;
}
static void T_4 F_46 ( struct V_5 * V_5 )
{
F_47 ( V_5 ) ;
F_45 ( L_16 , V_5 -> V_79 ) ;
F_45 ( L_15 , V_5 -> V_79 ) ;
F_45 ( L_14 , V_5 -> V_79 ) ;
}
static int F_48 ( struct V_2 * V_3 , void * V_15 )
{
struct V_87 * V_88 ;
struct V_1 * V_6 = V_15 ;
if ( V_15 == V_14 )
return 0 ;
F_49 ( V_6 ) ;
F_50 (ha, dev) {
int V_61 ;
F_15 ( V_3 , L_17 , V_6 -> V_89 ,
V_6 -> V_19 , V_88 -> V_90 , V_88 -> V_91 ) ;
for ( V_61 = 0 ; V_61 < V_6 -> V_92 ; V_61 ++ )
F_15 ( V_3 , L_18 , V_88 -> V_93 [ V_61 ] ) ;
F_51 ( V_3 , '\n' ) ;
}
F_52 ( V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_28 ( V_54 , V_55 , & V_94 ,
sizeof( struct V_57 ) ) ;
}
static int T_3 F_54 ( struct V_5 * V_5 )
{
if ( ! F_43 ( L_19 , 0 , V_5 -> V_79 , & V_95 ) )
return - V_77 ;
return 0 ;
}
static void T_4 F_55 ( struct V_5 * V_5 )
{
F_45 ( L_19 , V_5 -> V_79 ) ;
}
int T_5 F_56 ( void )
{
int V_96 = F_57 ( & V_97 ) ;
if ( ! V_96 )
return F_57 ( & V_98 ) ;
return V_96 ;
}
