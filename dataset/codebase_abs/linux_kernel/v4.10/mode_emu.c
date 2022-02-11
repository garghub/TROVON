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
return V_11 -> V_14 -> V_14 -> V_14 -> V_14 ;
}
static struct V_8 * F_8 ( struct V_8 * V_11 )
{
return V_11 -> V_14 -> V_14 -> V_14 ;
}
static struct V_8 * F_9 ( struct V_8 * V_11 )
{
return V_11 -> V_14 -> V_14 ;
}
static struct V_8 * F_10 ( struct V_8 * V_11 )
{
return V_11 -> V_14 ;
}
static int F_11 ( struct V_8 * V_15 , struct V_8 * V_16 )
{
if ( F_8 ( V_15 ) -> V_10 != F_8 ( V_16 ) -> V_10 )
return V_17 ;
if ( F_9 ( V_15 ) -> V_10 != F_9 ( V_16 ) -> V_10 )
return V_18 ;
if ( F_10 ( V_15 ) -> V_10 != F_10 ( V_16 ) -> V_10 )
return V_19 ;
return V_20 ;
}
static int F_12 ( struct V_8 * V_9 , struct V_8 * V_11 )
{
struct V_8 * F_7 ;
int V_21 = V_22 ;
F_6 (core_node, node, CORE)
V_21 = F_13 ( V_21 , F_11 ( F_7 , V_11 ) ) ;
return V_21 == V_22 ? V_23 : V_21 ;
}
static void F_14 ( struct V_8 * V_12 )
{
int V_24 ;
F_15 ( V_12 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
F_16 ( V_12 , V_24 ) ;
}
static struct V_8 * F_17 ( struct V_8 * V_26 , struct V_8 * V_11 ,
int V_27 )
{
struct V_8 * V_9 , * V_28 = NULL ;
int V_29 , V_30 , V_31 ;
V_31 = V_3 -> V_32 + V_27 ;
V_30 = V_22 ;
V_28 = NULL ;
F_6 (node, numa, NODE) {
if ( F_4 ( V_11 ) == V_9 -> V_10 ) {
V_28 = V_9 ;
break;
}
if ( F_3 ( V_9 ) >= V_31 )
continue;
V_29 = F_12 ( V_9 , V_11 ) ;
if ( V_29 < V_30 ) {
V_30 = V_29 ;
V_28 = V_9 ;
}
}
return V_28 ;
}
static void F_18 ( struct V_8 * V_26 , struct V_8 * V_33 ,
int V_27 )
{
struct V_8 * V_9 , * V_11 , * V_34 ;
F_19 (core, tmp, phys, CORE) {
V_9 = F_17 ( V_26 , V_11 , V_27 ) ;
if ( ! V_9 )
return;
F_20 ( V_11 , V_9 ) ;
F_1 ( V_11 -> V_10 , V_9 -> V_10 ) ;
}
}
static void F_21 ( struct V_8 * V_9 , struct V_8 * V_33 ,
enum V_35 V_36 , bool V_37 )
{
int F_5 , V_31 = V_3 -> V_32 ;
struct V_8 * V_38 , * V_34 ;
F_19 (cur, tmp, phys, level) {
F_5 = V_31 - F_22 ( V_9 , V_39 ) ;
if ( V_37 ) {
if ( F_5 == F_22 ( V_38 , V_39 ) )
F_20 ( V_38 , V_9 ) ;
} else {
if ( F_5 >= F_22 ( V_38 , V_39 ) )
F_20 ( V_38 , V_9 ) ;
}
}
}
static void F_23 ( struct V_8 * V_26 , struct V_8 * V_33 ,
enum V_35 V_36 , bool V_37 )
{
struct V_8 * V_9 ;
F_6 (node, numa, NODE)
F_21 ( V_9 , V_33 , V_36 , V_37 ) ;
}
static void F_24 ( struct V_8 * V_26 , struct V_8 * V_33 )
{
struct V_8 * V_11 ;
F_23 ( V_26 , V_33 , V_40 , true ) ;
F_23 ( V_26 , V_33 , V_40 , false ) ;
F_23 ( V_26 , V_33 , V_41 , true ) ;
F_23 ( V_26 , V_33 , V_41 , false ) ;
F_23 ( V_26 , V_33 , V_42 , true ) ;
F_23 ( V_26 , V_33 , V_42 , false ) ;
F_6 (core, numa, CORE)
F_1 ( V_11 -> V_10 , F_7 ( V_11 ) -> V_10 ) ;
}
static struct V_8 * F_25 ( int V_10 , int V_43 )
{
struct V_8 * V_12 ;
int V_24 ;
V_12 = F_26 ( V_44 , V_10 ) ;
if ( ! V_12 )
goto V_45;
for ( V_24 = 0 ; V_24 < V_43 ; V_24 ++ ) {
if ( ! F_16 ( V_12 , V_24 ) )
goto V_45;
}
return V_12 ;
V_45:
F_27 ( L_1 ) ;
}
static void T_1 F_28 ( void )
{
int V_46 ;
V_3 = F_29 ( sizeof( * V_3 ) , 8 ) ;
for ( V_46 = 0 ; V_46 < F_30 ( V_3 -> V_4 ) ; V_46 ++ )
V_3 -> V_4 [ V_46 ] = V_5 ;
}
static struct V_8 * F_31 ( struct V_8 * V_33 )
{
static int V_47 = 1 ;
struct V_8 * V_26 ;
int V_48 ;
V_48 = V_3 -> V_7 + F_5 ( V_33 ) ;
V_3 -> V_32 = V_48 / V_25 ;
V_26 = F_25 ( V_49 , V_25 ) ;
if ( V_47 ) {
F_24 ( V_26 , V_33 ) ;
V_47 = 0 ;
}
F_18 ( V_26 , V_33 , 0 ) ;
F_18 ( V_26 , V_33 , 1 ) ;
F_14 ( V_26 ) ;
F_2 ( F_32 ( & V_33 -> V_50 ) ) ;
return V_26 ;
}
static struct V_8 * F_33 ( void )
{
struct V_8 * V_33 , * V_9 , * V_51 , * V_52 , * V_53 , * V_11 ;
struct V_54 * V_55 ;
int V_56 ;
V_33 = F_25 ( V_57 , 1 ) ;
F_34 (cpu, &cpus_with_topology) {
V_55 = & V_58 [ V_56 ] ;
V_9 = F_16 ( V_33 , 0 ) ;
V_51 = F_16 ( V_9 , V_55 -> V_59 ) ;
V_52 = F_16 ( V_51 , V_55 -> V_60 ) ;
V_53 = F_16 ( V_52 , V_55 -> V_61 ) ;
V_11 = F_16 ( V_53 , F_35 ( V_56 ) ) ;
if ( ! V_51 || ! V_52 || ! V_53 || ! V_11 )
F_27 ( L_2 ) ;
F_36 ( V_56 , & V_11 -> V_50 ) ;
F_37 ( V_53 ) ;
}
return V_33 ;
}
static void F_38 ( struct V_8 * V_11 )
{
struct V_54 * V_55 ;
int V_56 ;
F_34 (cpu, &core->mask) {
V_55 = & V_58 [ V_56 ] ;
F_39 ( & V_55 -> V_62 , & V_11 -> V_50 ) ;
F_39 ( & V_55 -> V_63 , & F_10 ( V_11 ) -> V_50 ) ;
F_39 ( & V_55 -> V_64 , & F_9 ( V_11 ) -> V_50 ) ;
F_39 ( & V_55 -> V_65 , & F_8 ( V_11 ) -> V_50 ) ;
F_36 ( V_56 , & V_66 [ F_7 ( V_11 ) -> V_10 ] ) ;
V_55 -> V_2 = F_7 ( V_11 ) -> V_10 ;
}
}
static void F_40 ( struct V_8 * V_26 )
{
struct V_8 * V_11 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_67 ; V_46 ++ )
F_41 ( & V_66 [ V_46 ] ) ;
F_6 (core, numa, CORE)
F_38 ( V_11 ) ;
}
static void F_42 ( void )
{
int V_24 , V_68 ;
if ( ! V_69 )
return;
F_43 ( V_70 L_3 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_43 ( V_70 L_4 , V_24 ) ;
for ( V_68 = 0 ; V_68 < F_30 ( V_3 -> V_4 ) ; V_68 ++ ) {
if ( V_3 -> V_4 [ V_68 ] == V_24 )
F_43 ( V_71 L_5 , V_68 ) ;
}
F_43 ( V_71 L_6 ) ;
}
}
static void F_44 ( void )
{
int V_1 , V_2 , V_56 ;
static int V_72 ;
if ( V_72 )
return;
F_42 () ;
V_2 = 0 ;
F_45 (cpu) {
V_1 = F_35 ( V_56 ) ;
if ( V_3 -> V_4 [ V_1 ] != V_5 )
continue;
F_1 ( V_1 , V_2 ) ;
V_58 [ V_56 ] . V_2 = V_2 ;
V_2 = ( V_2 + 1 ) % V_25 ;
}
F_42 () ;
V_72 = 1 ;
}
static void F_46 ( void )
{
struct V_8 * V_33 , * V_26 ;
if ( V_3 == NULL )
F_28 () ;
V_33 = F_33 () ;
V_26 = F_31 ( V_33 ) ;
F_47 ( V_33 ) ;
F_40 ( V_26 ) ;
F_47 ( V_26 ) ;
F_44 () ;
}
static unsigned long F_48 ( unsigned long V_73 )
{
unsigned long V_74 ;
V_73 = V_73 ? : V_75 ;
V_74 = F_49 ( V_73 , F_50 () ) ;
if ( V_74 == V_73 )
return V_73 ;
F_51 ( L_7 ,
V_73 >> 20 , V_74 >> 20 ) ;
return V_74 ;
}
static int F_52 ( int V_43 )
{
int V_76 ;
V_76 = V_77 . V_78 . V_79 / V_80 ;
V_76 = F_53 ( V_76 , 1 ) ;
if ( V_76 >= V_43 )
return V_43 ;
F_51 ( L_8 , V_43 ) ;
return V_76 ;
}
static void F_54 ( void )
{
int V_24 ;
V_80 = F_48 ( V_80 ) ;
V_25 = F_52 ( V_25 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
F_55 ( V_24 , V_81 ) ;
F_56 ( L_9 ,
V_25 , V_80 >> 20 ) ;
}
static int F_57 ( unsigned long V_82 )
{
return ( V_82 / ( V_80 >> V_83 ) ) % V_25 ;
}
static unsigned long F_58 ( void )
{
return V_80 ;
}
static int F_59 ( int V_84 , int V_85 )
{
return ( V_84 != V_85 ) * V_86 ;
}
static int T_2 F_60 ( char * V_87 )
{
int V_13 ;
if ( F_61 ( V_87 , 0 , & V_13 ) != 0 || V_13 <= 0 )
return 0 ;
if ( V_13 <= 0 )
return 0 ;
V_25 = F_13 ( V_13 , V_67 ) ;
return 0 ;
}
static int T_2 F_62 ( char * V_87 )
{
V_80 = F_63 ( V_87 , NULL ) ;
return 0 ;
}
