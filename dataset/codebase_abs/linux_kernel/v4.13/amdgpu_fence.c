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
struct V_2 * V_21 ;
struct V_5 * V_22 , * * V_23 ;
T_2 V_13 ;
V_21 = F_14 ( V_1 , V_24 ) ;
if ( V_21 == NULL )
return - V_4 ;
V_13 = ++ V_12 -> V_16 . V_25 ;
V_21 -> V_12 = V_12 ;
F_15 ( & V_21 -> V_8 , & V_10 ,
& V_12 -> V_16 . V_26 ,
V_20 -> V_27 + V_12 -> V_28 ,
V_13 ) ;
F_16 ( V_12 , V_12 -> V_16 . V_29 ,
V_13 , V_30 ) ;
V_23 = & V_12 -> V_16 . V_31 [ V_13 & V_12 -> V_16 . V_32 ] ;
V_22 = F_17 ( * V_23 , 1 ) ;
if ( V_22 && ! F_18 ( V_22 ) ) {
F_19 ( L_2 ) ;
F_20 ( V_22 , false ) ;
}
F_21 ( * V_23 , F_22 ( & V_21 -> V_8 ) ) ;
* V_6 = & V_21 -> V_8 ;
return 0 ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_24 ( & V_12 -> V_16 . V_33 ,
V_34 + V_35 ) ;
}
void F_25 ( struct V_11 * V_12 )
{
struct V_14 * V_15 = & V_12 -> V_16 ;
T_2 V_13 , V_18 ;
int V_36 ;
do {
V_18 = F_12 ( & V_12 -> V_16 . V_18 ) ;
V_13 = F_10 ( V_12 ) ;
} while ( F_26 ( & V_15 -> V_18 , V_18 , V_13 ) != V_18 );
if ( V_13 != V_12 -> V_16 . V_25 )
F_23 ( V_12 ) ;
if ( F_27 ( V_13 == V_18 ) )
return;
V_18 &= V_15 -> V_32 ;
V_13 &= V_15 -> V_32 ;
do {
struct V_5 * V_21 , * * V_23 ;
++ V_18 ;
V_18 &= V_15 -> V_32 ;
V_23 = & V_15 -> V_31 [ V_18 ] ;
V_21 = F_17 ( * V_23 , 1 ) ;
F_28 ( * V_23 , NULL ) ;
if ( ! V_21 )
continue;
V_36 = F_29 ( V_21 ) ;
if ( ! V_36 )
F_30 ( V_21 , L_3 ) ;
else
F_31 () ;
F_32 ( V_21 ) ;
} while ( V_18 != V_13 );
}
static void F_33 ( unsigned long V_37 )
{
struct V_11 * V_12 = ( void * ) V_37 ;
F_25 ( V_12 ) ;
}
int F_34 ( struct V_11 * V_12 )
{
T_3 V_13 = F_35 ( V_12 -> V_16 . V_25 ) ;
struct V_5 * V_21 , * * V_23 ;
int V_36 ;
if ( ! V_13 )
return 0 ;
V_23 = & V_12 -> V_16 . V_31 [ V_13 & V_12 -> V_16 . V_32 ] ;
F_36 () ;
V_21 = F_37 ( * V_23 ) ;
if ( ! V_21 || ! F_38 ( V_21 ) ) {
F_39 () ;
return 0 ;
}
F_39 () ;
V_36 = F_20 ( V_21 , false ) ;
F_32 ( V_21 ) ;
return V_36 ;
}
unsigned F_40 ( struct V_11 * V_12 )
{
T_3 V_38 ;
F_25 ( V_12 ) ;
V_38 = 0x100000000ull ;
V_38 -= F_12 ( & V_12 -> V_16 . V_18 ) ;
V_38 += F_35 ( V_12 -> V_16 . V_25 ) ;
return F_41 ( V_38 ) ;
}
int F_42 ( struct V_11 * V_12 ,
struct V_39 * V_40 ,
unsigned V_41 )
{
struct V_19 * V_20 = V_12 -> V_20 ;
T_3 V_42 ;
if ( V_12 != & V_20 -> V_43 . V_12 ) {
V_12 -> V_16 . V_17 = & V_20 -> V_44 . V_44 [ V_12 -> V_45 ] ;
V_12 -> V_16 . V_29 = V_20 -> V_44 . V_29 + ( V_12 -> V_45 * 4 ) ;
} else {
V_42 = F_43 ( V_20 -> V_43 . V_46 -> V_47 , 8 ) ;
V_12 -> V_16 . V_17 = V_20 -> V_43 . V_17 + V_42 ;
V_12 -> V_16 . V_29 = V_20 -> V_43 . V_29 + V_42 ;
}
F_8 ( V_12 , F_12 ( & V_12 -> V_16 . V_18 ) ) ;
F_44 ( V_20 , V_40 , V_41 ) ;
V_12 -> V_16 . V_40 = V_40 ;
V_12 -> V_16 . V_41 = V_41 ;
V_12 -> V_16 . V_48 = true ;
F_45 ( V_20 -> V_49 , L_4
L_5 , V_12 -> V_28 ,
V_12 -> V_16 . V_29 , V_12 -> V_16 . V_17 ) ;
return 0 ;
}
int F_46 ( struct V_11 * V_12 ,
unsigned V_50 )
{
long V_51 ;
int V_36 ;
if ( ( V_50 & ( V_50 - 1 ) ) != 0 )
return - V_52 ;
V_12 -> V_16 . V_17 = NULL ;
V_12 -> V_16 . V_29 = 0 ;
V_12 -> V_16 . V_25 = 0 ;
F_47 ( & V_12 -> V_16 . V_18 , 0 ) ;
V_12 -> V_16 . V_48 = false ;
F_48 ( & V_12 -> V_16 . V_33 , F_33 ,
( unsigned long ) V_12 ) ;
V_12 -> V_16 . V_32 = V_50 * 2 - 1 ;
F_49 ( & V_12 -> V_16 . V_26 ) ;
V_12 -> V_16 . V_31 = F_50 ( V_50 * 2 , sizeof( void * ) ,
V_24 ) ;
if ( ! V_12 -> V_16 . V_31 )
return - V_4 ;
if ( V_12 -> V_53 -> type != V_54 ) {
V_51 = F_51 ( V_55 ) ;
if ( V_51 == 0 ) {
V_51 = V_56 ;
}
V_36 = F_52 ( & V_12 -> V_57 , & V_58 ,
V_50 ,
V_51 , V_12 -> V_59 ) ;
if ( V_36 ) {
F_53 ( L_6 ,
V_12 -> V_59 ) ;
return V_36 ;
}
}
return 0 ;
}
int F_54 ( struct V_19 * V_20 )
{
if ( F_55 ( V_20 ) )
F_56 ( V_20 -> V_49 , L_7 ) ;
return 0 ;
}
void F_57 ( struct V_19 * V_20 )
{
unsigned V_60 , V_61 ;
int V_36 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
struct V_11 * V_12 = V_20 -> V_63 [ V_60 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_48 )
continue;
V_36 = F_34 ( V_12 ) ;
if ( V_36 ) {
F_58 ( V_20 ) ;
}
F_59 ( V_20 , V_12 -> V_16 . V_40 ,
V_12 -> V_16 . V_41 ) ;
F_60 ( & V_12 -> V_57 ) ;
F_61 ( & V_12 -> V_16 . V_33 ) ;
for ( V_61 = 0 ; V_61 <= V_12 -> V_16 . V_32 ; ++ V_61 )
F_32 ( V_12 -> V_16 . V_31 [ V_61 ] ) ;
F_62 ( V_12 -> V_16 . V_31 ) ;
V_12 -> V_16 . V_31 = NULL ;
V_12 -> V_16 . V_48 = false ;
}
}
void F_63 ( struct V_19 * V_20 )
{
int V_60 , V_36 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
struct V_11 * V_12 = V_20 -> V_63 [ V_60 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_48 )
continue;
V_36 = F_34 ( V_12 ) ;
if ( V_36 ) {
F_58 ( V_20 ) ;
}
F_59 ( V_20 , V_12 -> V_16 . V_40 ,
V_12 -> V_16 . V_41 ) ;
}
}
void F_64 ( struct V_19 * V_20 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
struct V_11 * V_12 = V_20 -> V_63 [ V_60 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_48 )
continue;
F_44 ( V_20 , V_12 -> V_16 . V_40 ,
V_12 -> V_16 . V_41 ) ;
}
}
void F_58 ( struct V_19 * V_20 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
struct V_11 * V_12 = V_20 -> V_63 [ V_60 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_48 )
continue;
F_8 ( V_12 , V_12 -> V_16 . V_25 ) ;
}
}
void F_65 ( struct V_11 * V_12 )
{
if ( V_12 )
F_8 ( V_12 , V_12 -> V_16 . V_25 ) ;
}
static const char * F_66 ( struct V_5 * V_21 )
{
return L_8 ;
}
static const char * F_67 ( struct V_5 * V_6 )
{
struct V_2 * V_21 = F_6 ( V_6 ) ;
return ( const char * ) V_21 -> V_12 -> V_59 ;
}
static bool F_68 ( struct V_5 * V_6 )
{
struct V_2 * V_21 = F_6 ( V_6 ) ;
struct V_11 * V_12 = V_21 -> V_12 ;
if ( ! F_69 ( & V_12 -> V_16 . V_33 ) )
F_23 ( V_12 ) ;
F_30 ( & V_21 -> V_8 , L_9 , V_12 -> V_28 ) ;
return true ;
}
static void F_70 ( struct V_64 * V_65 )
{
struct V_5 * V_6 = F_7 ( V_65 , struct V_5 , V_65 ) ;
struct V_2 * V_21 = F_6 ( V_6 ) ;
F_71 ( V_1 , V_21 ) ;
}
static void F_72 ( struct V_5 * V_6 )
{
F_73 ( & V_6 -> V_65 , F_70 ) ;
}
static int F_74 ( struct V_66 * V_67 , void * V_68 )
{
struct V_69 * V_70 = (struct V_69 * ) V_67 -> V_71 ;
struct V_72 * V_49 = V_70 -> V_73 -> V_49 ;
struct V_19 * V_20 = V_49 -> V_74 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 ) {
struct V_11 * V_12 = V_20 -> V_63 [ V_60 ] ;
if ( ! V_12 || ! V_12 -> V_16 . V_48 )
continue;
F_25 ( V_12 ) ;
F_75 ( V_67 , L_10 , V_60 , V_12 -> V_59 ) ;
F_75 ( V_67 , L_11 ,
F_12 ( & V_12 -> V_16 . V_18 ) ) ;
F_75 ( V_67 , L_12 ,
V_12 -> V_16 . V_25 ) ;
}
return 0 ;
}
static int F_76 ( struct V_66 * V_67 , void * V_68 )
{
struct V_69 * V_70 = (struct V_69 * ) V_67 -> V_71 ;
struct V_72 * V_49 = V_70 -> V_73 -> V_49 ;
struct V_19 * V_20 = V_49 -> V_74 ;
F_75 ( V_67 , L_13 ) ;
F_77 ( V_20 ) ;
return 0 ;
}
int F_55 ( struct V_19 * V_20 )
{
#if F_78 ( V_75 )
if ( F_79 ( V_20 ) )
return F_80 ( V_20 , V_76 , 1 ) ;
return F_80 ( V_20 , V_77 , 2 ) ;
#else
return 0 ;
#endif
}
