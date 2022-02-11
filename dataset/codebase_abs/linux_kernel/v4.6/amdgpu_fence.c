static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 , struct V_1 , V_5 ) ;
if ( V_4 -> V_5 . V_6 == & V_7 )
return V_4 ;
return NULL ;
}
static void F_3 ( struct V_8 * V_9 , T_1 V_10 )
{
struct V_11 * V_12 = & V_9 -> V_13 ;
if ( V_12 -> V_14 )
* V_12 -> V_14 = F_4 ( V_10 ) ;
}
static T_1 F_5 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = & V_9 -> V_13 ;
T_1 V_10 = 0 ;
if ( V_12 -> V_14 )
V_10 = F_6 ( * V_12 -> V_14 ) ;
else
V_10 = F_7 ( & V_12 -> V_15 ) ;
return V_10 ;
}
int F_8 ( struct V_8 * V_9 , struct V_2 * * V_3 )
{
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_2 ;
struct V_2 * V_18 , * * V_19 ;
T_2 V_10 ;
V_2 = F_9 ( V_20 , V_21 ) ;
if ( V_2 == NULL )
return - V_22 ;
V_10 = ++ V_9 -> V_13 . V_23 ;
V_2 -> V_9 = V_9 ;
F_10 ( & V_2 -> V_5 , & V_7 ,
& V_9 -> V_13 . V_24 ,
V_17 -> V_25 + V_9 -> V_26 ,
V_10 ) ;
F_11 ( V_9 , V_9 -> V_13 . V_27 ,
V_10 , V_28 ) ;
V_19 = & V_9 -> V_13 . V_29 [ V_10 & V_9 -> V_13 . V_30 ] ;
V_18 = F_12 ( * V_19 , 1 ) ;
if ( V_18 && ! F_13 ( V_18 ) ) {
F_14 ( L_1 ) ;
F_15 ( V_18 , false ) ;
}
F_16 ( * V_19 , F_17 ( & V_2 -> V_5 ) ) ;
* V_3 = & V_2 -> V_5 ;
return 0 ;
}
static void F_18 ( struct V_8 * V_9 )
{
F_19 ( & V_9 -> V_13 . V_31 ,
V_32 + V_33 ) ;
}
void F_20 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = & V_9 -> V_13 ;
T_2 V_10 , V_15 ;
int V_34 ;
do {
V_15 = F_7 ( & V_9 -> V_13 . V_15 ) ;
V_10 = F_5 ( V_9 ) ;
} while ( F_21 ( & V_12 -> V_15 , V_15 , V_10 ) != V_15 );
if ( V_10 != V_9 -> V_13 . V_23 )
F_18 ( V_9 ) ;
while ( V_15 != V_10 ) {
struct V_2 * V_2 , * * V_19 ;
V_19 = & V_12 -> V_29 [ ++ V_15 & V_12 -> V_30 ] ;
V_2 = F_12 ( * V_19 , 1 ) ;
F_16 ( * V_19 , NULL ) ;
F_22 ( ! V_2 ) ;
V_34 = F_23 ( V_2 ) ;
if ( ! V_34 )
F_24 ( V_2 , L_2 ) ;
else
F_25 () ;
F_26 ( V_2 ) ;
}
}
static void F_27 ( unsigned long V_35 )
{
struct V_8 * V_9 = ( void * ) V_35 ;
F_20 ( V_9 ) ;
}
int F_28 ( struct V_8 * V_9 )
{
T_3 V_10 = F_29 ( V_9 -> V_13 . V_23 ) ;
struct V_2 * V_2 , * * V_19 ;
int V_34 ;
if ( ! V_10 )
return 0 ;
V_19 = & V_9 -> V_13 . V_29 [ V_10 & V_9 -> V_13 . V_30 ] ;
F_30 () ;
V_2 = F_31 ( * V_19 ) ;
if ( ! V_2 || ! F_32 ( V_2 ) ) {
F_33 () ;
return 0 ;
}
F_33 () ;
V_34 = F_15 ( V_2 , false ) ;
F_26 ( V_2 ) ;
return V_34 ;
}
unsigned F_34 ( struct V_8 * V_9 )
{
T_3 V_36 ;
F_20 ( V_9 ) ;
V_36 = 0x100000000ull ;
V_36 -= F_7 ( & V_9 -> V_13 . V_15 ) ;
V_36 += F_29 ( V_9 -> V_13 . V_23 ) ;
return F_35 ( V_36 ) ;
}
int F_36 ( struct V_8 * V_9 ,
struct V_37 * V_38 ,
unsigned V_39 )
{
struct V_16 * V_17 = V_9 -> V_17 ;
T_3 V_40 ;
if ( V_9 != & V_17 -> V_41 . V_9 ) {
V_9 -> V_13 . V_14 = & V_17 -> V_42 . V_42 [ V_9 -> V_43 ] ;
V_9 -> V_13 . V_27 = V_17 -> V_42 . V_27 + ( V_9 -> V_43 * 4 ) ;
} else {
V_40 = F_37 ( V_17 -> V_41 . V_44 -> V_45 , 8 ) ;
V_9 -> V_13 . V_14 = V_17 -> V_41 . V_14 + V_40 ;
V_9 -> V_13 . V_27 = V_17 -> V_41 . V_27 + V_40 ;
}
F_3 ( V_9 , F_7 ( & V_9 -> V_13 . V_15 ) ) ;
F_38 ( V_17 , V_38 , V_39 ) ;
V_9 -> V_13 . V_38 = V_38 ;
V_9 -> V_13 . V_39 = V_39 ;
V_9 -> V_13 . V_46 = true ;
F_39 ( V_17 -> V_47 , L_3
L_4 , V_9 -> V_26 ,
V_9 -> V_13 . V_27 , V_9 -> V_13 . V_14 ) ;
return 0 ;
}
int F_40 ( struct V_8 * V_9 ,
unsigned V_48 )
{
long V_49 ;
int V_34 ;
if ( ( V_48 & ( V_48 - 1 ) ) != 0 )
return - V_50 ;
V_9 -> V_13 . V_14 = NULL ;
V_9 -> V_13 . V_27 = 0 ;
V_9 -> V_13 . V_23 = 0 ;
F_41 ( & V_9 -> V_13 . V_15 , 0 ) ;
V_9 -> V_13 . V_46 = false ;
F_42 ( & V_9 -> V_13 . V_31 , F_27 ,
( unsigned long ) V_9 ) ;
V_9 -> V_13 . V_30 = V_48 - 1 ;
F_43 ( & V_9 -> V_13 . V_24 ) ;
V_9 -> V_13 . V_29 = F_44 ( V_48 , sizeof( void * ) ,
V_21 ) ;
if ( ! V_9 -> V_13 . V_29 )
return - V_22 ;
V_49 = F_45 ( V_51 ) ;
if ( V_49 == 0 ) {
V_49 = V_52 ;
}
V_34 = F_46 ( & V_9 -> V_53 , & V_54 ,
V_48 ,
V_49 , V_9 -> V_55 ) ;
if ( V_34 ) {
F_47 ( L_5 ,
V_9 -> V_55 ) ;
return V_34 ;
}
return 0 ;
}
int F_48 ( struct V_16 * V_17 )
{
if ( F_49 ( & V_56 ) == 1 ) {
V_20 = F_50 (
L_6 , sizeof( struct V_1 ) , 0 ,
V_57 , NULL ) ;
if ( ! V_20 )
return - V_22 ;
}
if ( F_51 ( V_17 ) )
F_52 ( V_17 -> V_47 , L_7 ) ;
return 0 ;
}
void F_53 ( struct V_16 * V_17 )
{
unsigned V_58 , V_59 ;
int V_34 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
struct V_8 * V_9 = V_17 -> V_61 [ V_58 ] ;
if ( ! V_9 || ! V_9 -> V_13 . V_46 )
continue;
V_34 = F_28 ( V_9 ) ;
if ( V_34 ) {
F_54 ( V_17 ) ;
}
F_55 ( V_17 , V_9 -> V_13 . V_38 ,
V_9 -> V_13 . V_39 ) ;
F_56 ( & V_9 -> V_53 ) ;
F_57 ( & V_9 -> V_13 . V_31 ) ;
for ( V_59 = 0 ; V_59 <= V_9 -> V_13 . V_30 ; ++ V_59 )
F_26 ( V_9 -> V_13 . V_29 [ V_58 ] ) ;
F_58 ( V_9 -> V_13 . V_29 ) ;
V_9 -> V_13 . V_46 = false ;
}
if ( F_59 ( & V_56 ) )
F_60 ( V_20 ) ;
}
void F_61 ( struct V_16 * V_17 )
{
int V_58 , V_34 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
struct V_8 * V_9 = V_17 -> V_61 [ V_58 ] ;
if ( ! V_9 || ! V_9 -> V_13 . V_46 )
continue;
V_34 = F_28 ( V_9 ) ;
if ( V_34 ) {
F_54 ( V_17 ) ;
}
F_55 ( V_17 , V_9 -> V_13 . V_38 ,
V_9 -> V_13 . V_39 ) ;
}
}
void F_62 ( struct V_16 * V_17 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
struct V_8 * V_9 = V_17 -> V_61 [ V_58 ] ;
if ( ! V_9 || ! V_9 -> V_13 . V_46 )
continue;
F_38 ( V_17 , V_9 -> V_13 . V_38 ,
V_9 -> V_13 . V_39 ) ;
}
}
void F_54 ( struct V_16 * V_17 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ ) {
struct V_8 * V_9 = V_17 -> V_61 [ V_58 ] ;
if ( ! V_9 || ! V_9 -> V_13 . V_46 )
continue;
F_3 ( V_9 , V_9 -> V_13 . V_23 ) ;
}
}
static const char * F_63 ( struct V_2 * V_2 )
{
return L_8 ;
}
static const char * F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_2 = F_1 ( V_3 ) ;
return ( const char * ) V_2 -> V_9 -> V_55 ;
}
static bool F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_2 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( ! F_66 ( & V_9 -> V_13 . V_31 ) )
F_18 ( V_9 ) ;
F_24 ( & V_2 -> V_5 , L_9 , V_9 -> V_26 ) ;
return true ;
}
static void F_67 ( struct V_62 * V_63 )
{
struct V_2 * V_3 = F_2 ( V_63 , struct V_2 , V_63 ) ;
struct V_1 * V_2 = F_1 ( V_3 ) ;
F_68 ( V_20 , V_2 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
F_70 ( & V_3 -> V_63 , F_67 ) ;
}
static int F_71 ( struct V_64 * V_65 , void * V_66 )
{
struct V_67 * V_68 = (struct V_67 * ) V_65 -> V_69 ;
struct V_70 * V_47 = V_68 -> V_71 -> V_47 ;
struct V_16 * V_17 = V_47 -> V_72 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_60 ; ++ V_58 ) {
struct V_8 * V_9 = V_17 -> V_61 [ V_58 ] ;
if ( ! V_9 || ! V_9 -> V_13 . V_46 )
continue;
F_20 ( V_9 ) ;
F_72 ( V_65 , L_10 , V_58 , V_9 -> V_55 ) ;
F_72 ( V_65 , L_11 ,
F_7 ( & V_9 -> V_13 . V_15 ) ) ;
F_72 ( V_65 , L_12 ,
V_9 -> V_13 . V_23 ) ;
}
return 0 ;
}
static int F_73 ( struct V_64 * V_65 , void * V_66 )
{
struct V_67 * V_68 = (struct V_67 * ) V_65 -> V_69 ;
struct V_70 * V_47 = V_68 -> V_71 -> V_47 ;
struct V_16 * V_17 = V_47 -> V_72 ;
F_72 ( V_65 , L_13 ) ;
F_74 ( V_17 ) ;
return 0 ;
}
int F_51 ( struct V_16 * V_17 )
{
#if F_75 ( V_73 )
return F_76 ( V_17 , V_74 , 2 ) ;
#else
return 0 ;
#endif
}
