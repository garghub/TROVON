static void F_1 ( int V_1 , int V_2 )
{
if ( V_3 -> V_4 [ V_1 ] == V_5 ) {
V_3 -> V_6 [ V_2 ] ++ ;
V_3 -> V_4 [ V_1 ] = V_2 ;
V_3 -> V_7 ++ ;
} else {
F_2 ( V_3 -> V_4 [ V_1 ] != V_2 ) ;
}
}
static int F_3 ( struct V_8 * V_9 )
{
return V_3 -> V_6 [ V_9 -> V_10 ] ;
}
static int F_4 ( struct V_8 * V_11 )
{
return V_3 -> V_4 [ V_11 -> V_10 ] ;
}
static int F_5 ( struct V_8 * V_12 )
{
struct V_8 * V_11 ;
int V_13 = 0 ;
F_6 (core, tree, CORE) {
if ( F_4 ( V_11 ) == V_5 )
V_13 ++ ;
}
return V_13 ;
}
static struct V_8 * F_7 ( struct V_8 * V_11 )
{
return V_11 -> V_14 -> V_14 -> V_14 ;
}
static struct V_8 * F_8 ( struct V_8 * V_11 )
{
return V_11 -> V_14 -> V_14 ;
}
static struct V_8 * F_9 ( struct V_8 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_10 ( struct V_8 * V_15 , struct V_8 * V_16 )
{
if ( F_8 ( V_15 ) -> V_10 != F_8 ( V_16 ) -> V_10 )
return V_17 ;
if ( F_9 ( V_15 ) -> V_10 != F_9 ( V_16 ) -> V_10 )
return V_18 ;
return V_19 ;
}
static int F_11 ( struct V_8 * V_9 , struct V_8 * V_11 )
{
struct V_8 * F_7 ;
int V_20 = V_21 ;
F_6 (core_node, node, CORE)
V_20 = F_12 ( V_20 , F_10 ( F_7 , V_11 ) ) ;
return V_20 == V_21 ? V_22 : V_20 ;
}
static void F_13 ( struct V_8 * V_12 )
{
int V_23 ;
F_14 ( V_12 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
F_15 ( V_12 , V_23 ) ;
}
static struct V_8 * F_16 ( struct V_8 * V_25 , struct V_8 * V_11 ,
int V_26 )
{
struct V_8 * V_9 , * V_27 = NULL ;
int V_28 , V_29 , V_30 ;
V_30 = V_3 -> V_31 + V_26 ;
V_29 = V_21 ;
V_27 = NULL ;
F_6 (node, numa, NODE) {
if ( F_4 ( V_11 ) == V_9 -> V_10 ) {
V_27 = V_9 ;
break;
}
if ( F_3 ( V_9 ) >= V_30 )
continue;
V_28 = F_11 ( V_9 , V_11 ) ;
if ( V_28 < V_29 ) {
V_29 = V_28 ;
V_27 = V_9 ;
}
}
return V_27 ;
}
static void F_17 ( struct V_8 * V_25 , struct V_8 * V_32 ,
int V_26 )
{
struct V_8 * V_9 , * V_11 , * V_33 ;
F_18 (core, tmp, phys, CORE) {
V_9 = F_16 ( V_25 , V_11 , V_26 ) ;
if ( ! V_9 )
return;
F_19 ( V_11 , V_9 ) ;
F_1 ( V_11 -> V_10 , V_9 -> V_10 ) ;
}
}
static void F_20 ( struct V_8 * V_9 , struct V_8 * V_32 ,
enum V_34 V_35 , bool V_36 )
{
int F_5 , V_30 = V_3 -> V_31 ;
struct V_8 * V_37 , * V_33 ;
F_18 (cur, tmp, phys, level) {
F_5 = V_30 - F_21 ( V_9 , V_38 ) ;
if ( V_36 ) {
if ( F_5 == F_21 ( V_37 , V_38 ) )
F_19 ( V_37 , V_9 ) ;
} else {
if ( F_5 >= F_21 ( V_37 , V_38 ) )
F_19 ( V_37 , V_9 ) ;
}
}
}
static void F_22 ( struct V_8 * V_25 , struct V_8 * V_32 ,
enum V_34 V_35 , bool V_36 )
{
struct V_8 * V_9 ;
F_6 (node, numa, NODE)
F_20 ( V_9 , V_32 , V_35 , V_36 ) ;
}
static void F_23 ( struct V_8 * V_25 , struct V_8 * V_32 )
{
struct V_8 * V_11 ;
F_22 ( V_25 , V_32 , V_39 , true ) ;
F_22 ( V_25 , V_32 , V_39 , false ) ;
F_22 ( V_25 , V_32 , V_40 , true ) ;
F_22 ( V_25 , V_32 , V_40 , false ) ;
F_6 (core, numa, CORE)
F_1 ( V_11 -> V_10 , F_7 ( V_11 ) -> V_10 ) ;
}
static struct V_8 * F_24 ( int V_10 , int V_41 )
{
struct V_8 * V_12 ;
int V_23 ;
V_12 = F_25 ( V_42 , V_10 ) ;
if ( ! V_12 )
goto V_43;
for ( V_23 = 0 ; V_23 < V_41 ; V_23 ++ ) {
if ( ! F_15 ( V_12 , V_23 ) )
goto V_43;
}
return V_12 ;
V_43:
F_26 ( L_1 ) ;
}
static void F_27 ( void )
{
int V_44 ;
V_3 = F_28 ( sizeof( * V_3 ) , V_45 ) ;
if ( V_3 == NULL )
F_26 ( L_2 ) ;
for ( V_44 = 0 ; V_44 < F_29 ( V_3 -> V_4 ) ; V_44 ++ )
V_3 -> V_4 [ V_44 ] = V_5 ;
}
static struct V_8 * F_30 ( struct V_8 * V_32 )
{
static int V_46 = 1 ;
struct V_8 * V_25 ;
int V_47 ;
V_47 = V_3 -> V_7 + F_5 ( V_32 ) ;
V_3 -> V_31 = V_47 / V_24 ;
V_25 = F_24 ( V_48 , V_24 ) ;
if ( V_46 ) {
F_23 ( V_25 , V_32 ) ;
V_46 = 0 ;
}
F_17 ( V_25 , V_32 , 0 ) ;
F_17 ( V_25 , V_32 , 1 ) ;
F_13 ( V_25 ) ;
F_2 ( F_31 ( & V_32 -> V_49 ) ) ;
return V_25 ;
}
static struct V_8 * F_32 ( void )
{
struct V_8 * V_32 , * V_9 , * V_50 , * V_51 , * V_11 ;
struct V_52 * V_53 ;
int V_54 ;
V_32 = F_24 ( V_55 , 1 ) ;
F_33 (cpu) {
V_53 = & F_34 ( V_56 , V_54 ) ;
V_9 = F_15 ( V_32 , 0 ) ;
V_50 = F_15 ( V_9 , V_53 -> V_57 ) ;
V_51 = F_15 ( V_50 , V_53 -> V_58 ) ;
V_11 = F_15 ( V_51 , V_53 -> V_1 ) ;
if ( ! V_50 || ! V_51 || ! V_11 )
F_26 ( L_3 ) ;
F_35 ( V_54 , & V_11 -> V_49 ) ;
F_36 ( V_51 ) ;
}
return V_32 ;
}
static void F_37 ( struct V_8 * V_11 )
{
struct V_52 * V_53 ;
int V_54 ;
F_38 (cpu, &core->mask) {
V_53 = & F_34 ( V_56 , V_54 ) ;
F_39 ( & V_53 -> V_59 , & V_11 -> V_49 ) ;
F_39 ( & V_53 -> V_60 , & F_9 ( V_11 ) -> V_49 ) ;
F_39 ( & V_53 -> V_61 , & F_8 ( V_11 ) -> V_49 ) ;
F_35 ( V_54 , & V_62 [ F_7 ( V_11 ) -> V_10 ] ) ;
V_53 -> V_2 = F_7 ( V_11 ) -> V_10 ;
}
}
static void F_40 ( struct V_8 * V_25 )
{
struct V_8 * V_11 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ )
F_41 ( & V_62 [ V_44 ] ) ;
F_6 (core, numa, CORE)
F_37 ( V_11 ) ;
}
static void F_42 ( void )
{
int V_23 , V_64 ;
if ( ! V_65 )
return;
F_43 ( V_66 L_4 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
F_43 ( V_66 L_5 , V_23 ) ;
for ( V_64 = 0 ; V_64 < F_29 ( V_3 -> V_4 ) ; V_64 ++ ) {
if ( V_3 -> V_4 [ V_64 ] == V_23 )
F_43 ( V_67 L_6 , V_64 ) ;
}
F_43 ( V_67 L_7 ) ;
}
}
static void F_44 ( void )
{
struct V_8 * V_32 , * V_25 ;
if ( V_3 == NULL )
F_27 () ;
V_32 = F_32 () ;
V_25 = F_30 ( V_32 ) ;
F_45 ( V_32 ) ;
F_40 ( V_25 ) ;
F_45 ( V_25 ) ;
F_42 () ;
}
static unsigned long F_46 ( unsigned long V_68 )
{
V_68 = V_68 ? : V_69 ;
V_68 = F_47 ( V_68 , F_48 () ) ;
return V_68 ;
}
static int F_49 ( int V_41 )
{
int V_70 ;
V_70 = V_71 . V_72 . V_73 / V_74 ;
V_70 = F_50 ( V_70 , 1 ) ;
if ( V_70 >= V_41 )
return V_41 ;
F_51 ( L_8 , V_41 ) ;
return V_70 ;
}
static void F_52 ( void )
{
V_74 = F_46 ( V_74 ) ;
V_24 = F_49 ( V_24 ) ;
F_53 ( L_9 ,
V_24 , V_74 >> 20 ) ;
}
static int F_54 ( unsigned long V_75 )
{
return ( V_75 / ( V_74 >> V_76 ) ) % V_24 ;
}
static unsigned long F_55 ( void )
{
return V_74 ;
}
static int F_56 ( int V_77 , int V_78 )
{
return ( V_77 != V_78 ) * V_79 ;
}
static int T_1 F_57 ( char * V_80 )
{
int V_13 ;
if ( F_58 ( V_80 , 0 , & V_13 ) != 0 || V_13 <= 0 )
return 0 ;
if ( V_13 <= 0 )
return 0 ;
V_24 = F_12 ( V_13 , V_63 ) ;
return 0 ;
}
static int T_1 F_59 ( char * V_80 )
{
V_74 = F_60 ( V_80 , NULL ) ;
return 0 ;
}
