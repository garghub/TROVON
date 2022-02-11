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
F_15 ( V_3 , L_8 ,
V_44 -> V_46 , V_44 -> V_47 , V_44 -> V_48 , 0 ,
0 , 0 , 0 , 0 ,
V_44 -> V_49 , V_44 -> V_50 ) ;
return 0 ;
}
static int F_25 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_26 ( V_51 , V_52 , & V_53 ,
sizeof( struct V_54 ) ) ;
}
static int F_27 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_28 ( V_52 , & V_55 ) ;
}
static void * F_29 ( T_1 V_4 )
{
struct V_56 * V_57 = NULL ;
T_1 V_58 = 0 ;
int V_59 ;
F_30 (pt, &ptype_all, list) {
if ( V_58 == V_4 )
return V_57 ;
++ V_58 ;
}
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
F_30 (pt, &ptype_base[t], list) {
if ( V_58 == V_4 )
return V_57 ;
++ V_58 ;
}
}
return NULL ;
}
static void * F_31 ( struct V_2 * V_3 , T_1 * V_4 )
__acquires( T_2 )
{
F_9 () ;
return * V_4 ? F_29 ( * V_4 - 1 ) : V_14 ;
}
static void * F_32 ( struct V_2 * V_3 , void * V_15 , T_1 * V_4 )
{
struct V_56 * V_57 ;
struct V_61 * V_62 ;
int V_63 ;
++ * V_4 ;
if ( V_15 == V_14 )
return F_29 ( 0 ) ;
V_57 = V_15 ;
V_62 = V_57 -> V_64 . V_65 ;
if ( V_57 -> type == F_33 ( V_66 ) ) {
if ( V_62 != & V_67 )
goto V_68;
V_63 = 0 ;
V_62 = V_69 [ 0 ] . V_65 ;
} else
V_63 = F_34 ( V_57 -> type ) & V_70 ;
while ( V_62 == & V_69 [ V_63 ] ) {
if ( ++ V_63 >= V_60 )
return NULL ;
V_62 = V_69 [ V_63 ] . V_65 ;
}
V_68:
return F_35 ( V_62 , struct V_56 , V_64 ) ;
}
static void F_36 ( struct V_2 * V_3 , void * V_15 )
__releases( T_2 )
{
F_12 () ;
}
static int F_37 ( struct V_2 * V_3 , void * V_15 )
{
struct V_56 * V_57 = V_15 ;
if ( V_15 == V_14 )
F_17 ( V_3 , L_9 ) ;
else if ( V_57 -> V_6 == NULL || F_38 ( V_57 -> V_6 ) == F_2 ( V_3 ) ) {
if ( V_57 -> type == F_33 ( V_66 ) )
F_17 ( V_3 , L_10 ) ;
else
F_15 ( V_3 , L_11 , F_34 ( V_57 -> type ) ) ;
F_15 ( V_3 , L_12 ,
V_57 -> V_6 ? V_57 -> V_6 -> V_19 : L_13 , V_57 -> V_71 ) ;
}
return 0 ;
}
static int F_39 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_26 ( V_51 , V_52 , & V_72 ,
sizeof( struct V_54 ) ) ;
}
static int T_3 F_40 ( struct V_5 * V_5 )
{
int V_73 = - V_74 ;
if ( ! F_41 ( L_14 , V_75 , V_5 -> V_76 , & V_77 ) )
goto V_78;
if ( ! F_41 ( L_15 , V_75 , V_5 -> V_76 ,
& V_79 ) )
goto V_80;
if ( ! F_41 ( L_16 , V_75 , V_5 -> V_76 , & V_81 ) )
goto V_82;
if ( F_42 ( V_5 ) )
goto V_83;
V_73 = 0 ;
V_78:
return V_73 ;
V_83:
F_43 ( L_16 , V_5 -> V_76 ) ;
V_82:
F_43 ( L_15 , V_5 -> V_76 ) ;
V_80:
F_43 ( L_14 , V_5 -> V_76 ) ;
goto V_78;
}
static void T_4 F_44 ( struct V_5 * V_5 )
{
F_45 ( V_5 ) ;
F_43 ( L_16 , V_5 -> V_76 ) ;
F_43 ( L_15 , V_5 -> V_76 ) ;
F_43 ( L_14 , V_5 -> V_76 ) ;
}
static int F_46 ( struct V_2 * V_3 , void * V_15 )
{
struct V_84 * V_85 ;
struct V_1 * V_6 = V_15 ;
if ( V_15 == V_14 )
return 0 ;
F_47 ( V_6 ) ;
F_48 (ha, dev) {
int V_58 ;
F_15 ( V_3 , L_17 , V_6 -> V_86 ,
V_6 -> V_19 , V_85 -> V_87 , V_85 -> V_88 ) ;
for ( V_58 = 0 ; V_58 < V_6 -> V_89 ; V_58 ++ )
F_15 ( V_3 , L_18 , V_85 -> V_90 [ V_58 ] ) ;
F_49 ( V_3 , '\n' ) ;
}
F_50 ( V_6 ) ;
return 0 ;
}
static int F_51 ( struct V_51 * V_51 , struct V_52 * V_52 )
{
return F_26 ( V_51 , V_52 , & V_91 ,
sizeof( struct V_54 ) ) ;
}
static int T_3 F_52 ( struct V_5 * V_5 )
{
if ( ! F_41 ( L_19 , 0 , V_5 -> V_76 , & V_92 ) )
return - V_74 ;
return 0 ;
}
static void T_4 F_53 ( struct V_5 * V_5 )
{
F_43 ( L_19 , V_5 -> V_76 ) ;
}
int T_5 F_54 ( void )
{
int V_93 = F_55 ( & V_94 ) ;
if ( ! V_93 )
return F_55 ( & V_95 ) ;
return V_93 ;
}
