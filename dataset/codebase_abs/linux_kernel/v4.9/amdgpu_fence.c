int F_1 ( void )
{
V_1 = F_2 (
L_1 , sizeof( struct V_2 ) , 0 ,
V_3 , NULL ) ;
if ( ! V_1 )
return - V_4 ;
return 0 ;
}
void F_3 ( void )
{
F_4 () ;
F_5 ( V_1 ) ;
}
static inline struct V_2 * F_6 ( struct V_5 * V_6 )
{
struct V_2 * V_7 = F_7 ( V_6 , struct V_2 , V_8 ) ;
if ( V_7 -> V_8 . V_9 == & V_10 )
return V_7 ;
return NULL ;
}
static void F_8 ( struct V_11 * V_12 , T_1 V_13 )
{
struct V_14 * V_15 = & V_12 -> V_16 ;
if ( V_15 -> V_17 )
* V_15 -> V_17 = F_9 ( V_13 ) ;
}
static T_1 F_10 ( struct V_11 * V_12 )
{
struct V_14 * V_15 = & V_12 -> V_16 ;
T_1 V_13 = 0 ;
if ( V_15 -> V_17 )
V_13 = F_11 ( * V_15 -> V_17 ) ;
else
V_13 = F_12 ( & V_15 -> V_18 ) ;
return V_13 ;
}
int F_13 ( struct V_11 * V_12 , struct V_5 * * V_6 )
{
struct V_19 * V_20 = V_12 -> V_20 ;
struct V_2 * V_5 ;
struct V_5 * V_21 , * * V_22 ;
T_2 V_13 ;
V_5 = F_14 ( V_1 , V_23 ) ;
if ( V_5 == NULL )
return - V_4 ;
V_13 = ++ V_12 -> V_16 . V_24 ;
V_5 -> V_12 = V_12 ;
F_15 ( & V_5 -> V_8 , & V_10 ,
& V_12 -> V_16 . V_25 ,
V_20 -> V_26 + V_12 -> V_27 ,
V_13 ) ;
F_16 ( V_12 , V_12 -> V_16 . V_28 ,
V_13 , V_29 ) ;
V_22 = & V_12 -> V_16 . V_30 [ V_13 & V_12 -> V_16 . V_31 ] ;
V_21 = F_17 ( * V_22 , 1 ) ;
if ( V_21 && ! F_18 ( V_21 ) ) {
F_19 ( L_2 ) ;
F_20 ( V_21 , false ) ;
}
F_21 ( * V_22 , F_22 ( & V_5 -> V_8 ) ) ;
* V_6 = & V_5 -> V_8 ;
return 0 ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_24 ( & V_12 -> V_16 . V_32 ,
V_33 + V_34 ) ;
}
void F_25 ( struct V_11 * V_12 )
{
struct V_14 * V_15 = & V_12 -> V_16 ;
T_2 V_13 , V_18 ;
int V_35 ;
do {
V_18 = F_12 ( & V_12 -> V_16 . V_18 ) ;
V_13 = F_10 ( V_12 ) ;
} while ( F_26 ( & V_15 -> V_18 , V_18 , V_13 ) != V_18 );
if ( V_13 != V_12 -> V_16 . V_24 )
F_23 ( V_12 ) ;
if ( F_27 ( V_13 == V_18 ) )
return;
V_18 &= V_15 -> V_31 ;
V_13 &= V_15 -> V_31 ;
do {
struct V_5 * V_5 , * * V_22 ;
++ V_18 ;
V_18 &= V_15 -> V_31 ;
V_22 = & V_15 -> V_30 [ V_18 ] ;
V_5 = F_17 ( * V_22 , 1 ) ;
F_28 ( * V_22 , NULL ) ;
if ( ! V_5 )
continue;
V_35 = F_29 ( V_5 ) ;
if ( ! V_35 )
F_30 ( V_5 , L_3 ) ;
else
F_31 () ;
F_32 ( V_5 ) ;
} while ( V_18 != V_13 );
}
static void F_33 ( unsigned long V_36 )
{
struct V_11 * V_12 = ( void * ) V_36 ;
F_25 ( V_12 ) ;
}
int F_34 ( struct V_11 * V_12 )
{
T_3 V_13 = F_35 ( V_12 -> V_16 . V_24 ) ;
struct V_5 * V_5 , * * V_22 ;
int V_35 ;
if ( ! V_13 )
return 0 ;
V_22 = & V_12 -> V_16 . V_30 [ V_13 & V_12 -> V_16 . V_31 ] ;
F_36 () ;
V_5 = F_37 ( * V_22 ) ;
if ( ! V_5 || ! F_38 ( V_5 ) ) {
F_39 () ;
return 0 ;
}
F_39 () ;
V_35 = F_20 ( V_5 , false ) ;
F_32 ( V_5 ) ;
return V_35 ;
}
unsigned F_40 ( struct V_11 * V_12 )
{
T_3 V_37 ;
F_25 ( V_12 ) ;
V_37 = 0x100000000ull ;
V_37 -= F_12 ( & V_12 -> V_16 . V_18 ) ;
V_37 += F_35 ( V_12 -> V_16 . V_24 ) ;
return F_41 ( V_37 ) ;
}
int F_42 ( struct V_11 * V_12 ,
struct V_38 * V_39 ,
unsigned V_40 )
{
struct V_19 * V_20 = V_12 -> V_20 ;
T_3 V_41 ;
if ( V_12 != & V_20 -> V_42 . V_12 ) {
V_12 -> V_16 . V_17 = & V_20 -> V_43 . V_43 [ V_12 -> V_44 ] ;
V_12 -> V_16 . V_28 = V_20 -> V_43 . V_28 + ( V_12 -> V_44 * 4 ) ;
} else {
V_41 = F_43 ( V_20 -> V_42 . V_45 -> V_46 , 8 ) ;
V_12 -> V_16 . V_17 = V_20 -> V_42 . V_17 + V_41 ;
V_12 -> V_16 . V_28 = V_20 -> V_42 . V_28 + V_41 ;
}
F_8 ( V_12 , F_12 ( & V_12 -> V_16 . V_18 ) ) ;
F_44 ( V_20 , V_39 , V_40 ) ;
V_12 -> V_16 . V_39 = V_39 ;
V_12 -> V_16 . V_40 = V_40 ;
V_12 -> V_16 . V_47 = true ;
F_45 ( V_20 -> V_48 , L_4
L_5 , V_12 -> V_27 ,
V_12 -> V_16 . V_28 , V_12 -> V_16 . V_17 ) ;
return 0 ;
}
int F_46 ( struct V_11 * V_12 ,
unsigned V_49 )
{
long V_50 ;
int V_35 ;
if ( ( V_49 & ( V_49 - 1 ) ) != 0 )
return - V_51 ;
V_12 -> V_16 . V_17 = NULL ;
V_12 -> V_16 . V_28 = 0 ;
V_12 -> V_16 . V_24 = 0 ;
F_47 ( & V_12 -> V_16 . V_18 , 0 ) ;
V_12 -> V_16 . V_47 = false ;
F_48 ( & V_12 -> V_16 . V_32 , F_33 ,
( unsigned long ) V_12 ) ;
V_12 -> V_16 . V_31 = V_49 * 2 - 1 ;
F_49 ( & V_12 -> V_16 . V_25 ) ;
V_12 -> V_16 . V_30 = F_50 ( V_49 * 2 , sizeof( void * ) ,
V_23 ) ;
if ( ! V_12 -> V_16 . V_30 )
return - V_4 ;
V_50 = F_51 ( V_52 ) ;
if ( V_50 == 0 ) {
V_50 = V_53 ;
}
V_35 = F_52 ( & V_12 -> V_54 , & V_55 ,
V_49 ,
V_50 , V_12 -> V_56 ) ;
if ( V_35 ) {
F_53 ( L_6 ,
V_12 -> V_56 ) ;
return V_35 ;
}
return 0 ;
}
int F_54 ( struct V_19 * V_20 )
{
if ( F_55 ( V_20 ) )
F_56 ( V_20 -> V_48 , L_7 ) ;
return 0 ;
}
void F_57 ( struct V_19 * V_20 )
{
unsigned V_57 , V_58 ;
int V_35 ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
struct V_11 * V_12 = V_20 -> V_60 [ V_57 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_47 )
continue;
V_35 = F_34 ( V_12 ) ;
if ( V_35 ) {
F_58 ( V_20 ) ;
}
F_59 ( V_20 , V_12 -> V_16 . V_39 ,
V_12 -> V_16 . V_40 ) ;
F_60 ( & V_12 -> V_54 ) ;
F_61 ( & V_12 -> V_16 . V_32 ) ;
for ( V_58 = 0 ; V_58 <= V_12 -> V_16 . V_31 ; ++ V_58 )
F_32 ( V_12 -> V_16 . V_30 [ V_58 ] ) ;
F_62 ( V_12 -> V_16 . V_30 ) ;
V_12 -> V_16 . V_30 = NULL ;
V_12 -> V_16 . V_47 = false ;
}
}
void F_63 ( struct V_19 * V_20 )
{
int V_57 , V_35 ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
struct V_11 * V_12 = V_20 -> V_60 [ V_57 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_47 )
continue;
V_35 = F_34 ( V_12 ) ;
if ( V_35 ) {
F_58 ( V_20 ) ;
}
F_59 ( V_20 , V_12 -> V_16 . V_39 ,
V_12 -> V_16 . V_40 ) ;
}
}
void F_64 ( struct V_19 * V_20 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
struct V_11 * V_12 = V_20 -> V_60 [ V_57 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_47 )
continue;
F_44 ( V_20 , V_12 -> V_16 . V_39 ,
V_12 -> V_16 . V_40 ) ;
}
}
void F_58 ( struct V_19 * V_20 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
struct V_11 * V_12 = V_20 -> V_60 [ V_57 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_47 )
continue;
F_8 ( V_12 , V_12 -> V_16 . V_24 ) ;
}
}
static const char * F_65 ( struct V_5 * V_5 )
{
return L_8 ;
}
static const char * F_66 ( struct V_5 * V_6 )
{
struct V_2 * V_5 = F_6 ( V_6 ) ;
return ( const char * ) V_5 -> V_12 -> V_56 ;
}
static bool F_67 ( struct V_5 * V_6 )
{
struct V_2 * V_5 = F_6 ( V_6 ) ;
struct V_11 * V_12 = V_5 -> V_12 ;
if ( ! F_68 ( & V_12 -> V_16 . V_32 ) )
F_23 ( V_12 ) ;
F_30 ( & V_5 -> V_8 , L_9 , V_12 -> V_27 ) ;
return true ;
}
static void F_69 ( struct V_61 * V_62 )
{
struct V_5 * V_6 = F_7 ( V_62 , struct V_5 , V_62 ) ;
struct V_2 * V_5 = F_6 ( V_6 ) ;
F_70 ( V_1 , V_5 ) ;
}
static void F_71 ( struct V_5 * V_6 )
{
F_72 ( & V_6 -> V_62 , F_69 ) ;
}
static int F_73 ( struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = (struct V_66 * ) V_64 -> V_68 ;
struct V_69 * V_48 = V_67 -> V_70 -> V_48 ;
struct V_19 * V_20 = V_48 -> V_71 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_59 ; ++ V_57 ) {
struct V_11 * V_12 = V_20 -> V_60 [ V_57 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_47 )
continue;
F_25 ( V_12 ) ;
F_74 ( V_64 , L_10 , V_57 , V_12 -> V_56 ) ;
F_74 ( V_64 , L_11 ,
F_12 ( & V_12 -> V_16 . V_18 ) ) ;
F_74 ( V_64 , L_12 ,
V_12 -> V_16 . V_24 ) ;
}
return 0 ;
}
static int F_75 ( struct V_63 * V_64 , void * V_65 )
{
struct V_66 * V_67 = (struct V_66 * ) V_64 -> V_68 ;
struct V_69 * V_48 = V_67 -> V_70 -> V_48 ;
struct V_19 * V_20 = V_48 -> V_71 ;
F_74 ( V_64 , L_13 ) ;
F_76 ( V_20 ) ;
return 0 ;
}
int F_55 ( struct V_19 * V_20 )
{
#if F_77 ( V_72 )
return F_78 ( V_20 , V_73 , 2 ) ;
#else
return 0 ;
#endif
}
