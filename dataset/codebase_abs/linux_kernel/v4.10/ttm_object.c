static inline struct V_1 *
F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
return V_2 ;
}
static void F_3 ( struct V_4 * V_4 )
{
struct V_1 * V_2 =
F_4 ( V_4 , struct V_1 , V_3 ) ;
F_5 ( V_2 ) ;
}
static inline void F_6 ( struct V_1 * * V_5 )
{
struct V_1 * V_2 = * V_5 ;
* V_5 = NULL ;
F_7 ( & V_2 -> V_3 , F_3 ) ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
bool V_8 ,
enum V_9 V_10 ,
void (* F_9) ( struct V_6 * * ) ,
void (* F_10) ( struct V_6 * ,
enum V_11 V_12 ) )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_15 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_2 = F_1 ( V_2 ) ;
V_7 -> F_9 = F_9 ;
V_7 -> F_10 = F_10 ;
V_7 -> V_10 = V_10 ;
F_11 ( & V_7 -> V_3 ) ;
F_12 ( & V_14 -> V_16 ) ;
V_15 = F_13 ( & V_14 -> V_17 ,
& V_7 -> V_18 ,
( unsigned long ) V_7 , 31 , 0 , 0 ) ;
F_14 ( & V_14 -> V_16 ) ;
if ( F_15 ( V_15 != 0 ) )
goto V_19;
V_15 = F_16 ( V_2 , V_7 , V_20 , NULL ) ;
if ( F_15 ( V_15 != 0 ) )
goto V_21;
F_17 ( & V_7 ) ;
return 0 ;
V_21:
F_12 ( & V_14 -> V_16 ) ;
( void ) F_18 ( & V_14 -> V_17 , & V_7 -> V_18 ) ;
F_14 ( & V_14 -> V_16 ) ;
V_19:
return V_15 ;
}
static void F_19 ( struct V_4 * V_4 )
{
struct V_6 * V_7 =
F_4 ( V_4 , struct V_6 , V_3 ) ;
struct V_13 * V_14 = V_7 -> V_2 -> V_14 ;
F_12 ( & V_14 -> V_16 ) ;
( void ) F_18 ( & V_14 -> V_17 , & V_7 -> V_18 ) ;
F_14 ( & V_14 -> V_16 ) ;
F_6 ( & V_7 -> V_2 ) ;
if ( V_7 -> F_9 )
V_7 -> F_9 ( & V_7 ) ;
}
void F_17 ( struct V_6 * * V_22 )
{
struct V_6 * V_7 = * V_22 ;
* V_22 = NULL ;
F_7 ( & V_7 -> V_3 , F_19 ) ;
}
struct V_6 * F_20 ( struct V_1 * V_2 ,
T_1 V_23 )
{
struct V_6 * V_7 = NULL ;
struct V_24 * V_18 ;
struct V_25 * V_26 = & V_2 -> V_27 [ V_20 ] ;
int V_15 ;
F_21 () ;
V_15 = F_22 ( V_26 , V_23 , & V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
V_7 = F_24 ( V_18 , struct V_28 , V_18 ) -> V_29 ;
if ( ! F_25 ( & V_7 -> V_3 ) )
V_7 = NULL ;
}
F_26 () ;
return V_7 ;
}
struct V_6 *
F_27 ( struct V_13 * V_14 , T_1 V_23 )
{
struct V_6 * V_7 = NULL ;
struct V_24 * V_18 ;
struct V_25 * V_26 = & V_14 -> V_17 ;
int V_15 ;
F_21 () ;
V_15 = F_22 ( V_26 , V_23 , & V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
V_7 = F_24 ( V_18 , struct V_6 , V_18 ) ;
if ( ! F_25 ( & V_7 -> V_3 ) )
V_7 = NULL ;
}
F_26 () ;
return V_7 ;
}
bool F_28 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_25 * V_26 = & V_2 -> V_27 [ V_20 ] ;
struct V_24 * V_18 ;
struct V_28 * V_30 ;
F_21 () ;
if ( F_15 ( F_22 ( V_26 , V_7 -> V_18 . V_23 , & V_18 ) != 0 ) )
goto V_31;
V_30 = F_24 ( V_18 , struct V_28 , V_18 ) ;
if ( F_15 ( V_7 != V_30 -> V_29 ) )
goto V_31;
F_29 () ;
if ( F_15 ( F_30 ( & V_30 -> V_4 . V_3 ) == 0 ) )
goto V_31;
F_26 () ;
return true ;
V_31:
F_26 () ;
return false ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
enum V_11 V_12 , bool * V_32 )
{
struct V_25 * V_26 = & V_2 -> V_27 [ V_12 ] ;
struct V_28 * V_30 ;
struct V_24 * V_18 ;
struct V_33 * V_34 = V_2 -> V_14 -> V_34 ;
int V_15 = - V_35 ;
if ( V_7 -> V_2 != V_2 && ! V_7 -> V_8 )
return - V_36 ;
if ( V_32 != NULL )
* V_32 = true ;
while ( V_15 == - V_35 ) {
F_21 () ;
V_15 = F_22 ( V_26 , V_7 -> V_18 . V_23 , & V_18 ) ;
if ( V_15 == 0 ) {
V_30 = F_24 ( V_18 , struct V_28 , V_18 ) ;
if ( F_25 ( & V_30 -> V_4 ) ) {
F_26 () ;
break;
}
}
F_26 () ;
V_15 = F_31 ( V_34 , sizeof( * V_30 ) ,
false , false ) ;
if ( F_15 ( V_15 != 0 ) )
return V_15 ;
V_30 = F_32 ( sizeof( * V_30 ) , V_37 ) ;
if ( F_15 ( V_30 == NULL ) ) {
F_33 ( V_34 , sizeof( * V_30 ) ) ;
return - V_38 ;
}
V_30 -> V_18 . V_23 = V_7 -> V_18 . V_23 ;
V_30 -> V_29 = V_7 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_12 = V_12 ;
F_11 ( & V_30 -> V_4 ) ;
F_12 ( & V_2 -> V_39 ) ;
V_15 = F_34 ( V_26 , & V_30 -> V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
F_35 ( & V_30 -> V_40 , & V_2 -> V_41 ) ;
F_2 ( & V_7 -> V_3 ) ;
F_14 ( & V_2 -> V_39 ) ;
if ( V_32 != NULL )
* V_32 = false ;
break;
}
F_14 ( & V_2 -> V_39 ) ;
F_36 ( V_15 != - V_35 ) ;
F_33 ( V_34 , sizeof( * V_30 ) ) ;
F_5 ( V_30 ) ;
}
return V_15 ;
}
static void F_37 ( struct V_4 * V_4 )
{
struct V_28 * V_30 =
F_4 ( V_4 , struct V_28 , V_4 ) ;
struct V_6 * V_7 = V_30 -> V_29 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_25 * V_26 ;
struct V_33 * V_34 = V_2 -> V_14 -> V_34 ;
V_26 = & V_2 -> V_27 [ V_30 -> V_12 ] ;
( void ) F_18 ( V_26 , & V_30 -> V_18 ) ;
F_38 ( & V_30 -> V_40 ) ;
F_14 ( & V_2 -> V_39 ) ;
if ( V_30 -> V_12 != V_20 && V_7 -> F_10 )
V_7 -> F_10 ( V_7 , V_30 -> V_12 ) ;
F_17 ( & V_30 -> V_29 ) ;
F_33 ( V_34 , sizeof( * V_30 ) ) ;
F_39 ( V_30 , V_42 ) ;
F_12 ( & V_2 -> V_39 ) ;
}
int F_40 ( struct V_1 * V_2 ,
unsigned long V_23 , enum V_11 V_12 )
{
struct V_25 * V_26 = & V_2 -> V_27 [ V_12 ] ;
struct V_28 * V_30 ;
struct V_24 * V_18 ;
int V_15 ;
F_12 ( & V_2 -> V_39 ) ;
V_15 = F_41 ( V_26 , V_23 , & V_18 ) ;
if ( F_15 ( V_15 != 0 ) ) {
F_14 ( & V_2 -> V_39 ) ;
return - V_35 ;
}
V_30 = F_24 ( V_18 , struct V_28 , V_18 ) ;
F_7 ( & V_30 -> V_4 , F_37 ) ;
F_14 ( & V_2 -> V_39 ) ;
return 0 ;
}
void F_42 ( struct V_1 * * V_5 )
{
struct V_28 * V_30 ;
struct V_43 * V_44 ;
unsigned int V_45 ;
struct V_1 * V_2 = * V_5 ;
* V_5 = NULL ;
F_12 ( & V_2 -> V_39 ) ;
while ( ! F_43 ( & V_2 -> V_41 ) ) {
V_44 = V_2 -> V_41 . V_46 ;
V_30 = F_44 ( V_44 , struct V_28 , V_40 ) ;
F_37 ( & V_30 -> V_4 ) ;
}
for ( V_45 = 0 ; V_45 < V_47 ; ++ V_45 )
F_45 ( & V_2 -> V_27 [ V_45 ] ) ;
F_14 ( & V_2 -> V_39 ) ;
F_6 ( & V_2 ) ;
}
struct V_1 * F_46 ( struct V_13 * V_14 ,
unsigned int V_48 )
{
struct V_1 * V_2 = F_32 ( sizeof( * V_2 ) , V_37 ) ;
unsigned int V_45 ;
unsigned int V_49 = 0 ;
int V_15 ;
if ( F_15 ( V_2 == NULL ) )
return NULL ;
F_47 ( & V_2 -> V_39 ) ;
V_2 -> V_14 = V_14 ;
F_11 ( & V_2 -> V_3 ) ;
F_48 ( & V_2 -> V_41 ) ;
for ( V_45 = 0 ; V_45 < V_47 ; ++ V_45 ) {
V_15 = F_49 ( & V_2 -> V_27 [ V_45 ] , V_48 ) ;
if ( V_15 ) {
V_49 = V_45 ;
goto V_50;
}
}
return V_2 ;
V_50:
for ( V_45 = 0 ; V_45 < V_49 ; ++ V_45 )
F_45 ( & V_2 -> V_27 [ V_45 ] ) ;
F_5 ( V_2 ) ;
return NULL ;
}
struct V_13 *
F_50 ( struct V_33 * V_34 ,
unsigned int V_48 ,
const struct V_51 * V_52 )
{
struct V_13 * V_14 = F_32 ( sizeof( * V_14 ) , V_37 ) ;
int V_15 ;
if ( F_15 ( V_14 == NULL ) )
return NULL ;
V_14 -> V_34 = V_34 ;
F_47 ( & V_14 -> V_16 ) ;
F_51 ( & V_14 -> V_53 , 0 ) ;
V_15 = F_49 ( & V_14 -> V_17 , V_48 ) ;
if ( V_15 != 0 )
goto V_54;
V_14 -> V_52 = * V_52 ;
V_14 -> V_55 = V_14 -> V_52 . V_56 ;
V_14 -> V_52 . V_56 = V_57 ;
V_14 -> V_58 = F_52 ( sizeof( struct V_59 ) ) +
F_52 ( sizeof( struct V_60 ) ) ;
return V_14 ;
V_54:
F_5 ( V_14 ) ;
return NULL ;
}
void F_53 ( struct V_13 * * V_61 )
{
struct V_13 * V_14 = * V_61 ;
* V_61 = NULL ;
F_12 ( & V_14 -> V_16 ) ;
F_45 ( & V_14 -> V_17 ) ;
F_14 ( & V_14 -> V_16 ) ;
F_5 ( V_14 ) ;
}
static bool T_2 F_54 ( struct V_59 * V_62 )
{
return F_55 ( & V_62 -> V_60 -> V_63 ) != 0L ;
}
static void F_56 ( struct V_6 * * V_22 )
{
struct V_6 * V_7 = * V_22 ;
struct V_64 * V_65 ;
* V_22 = NULL ;
V_65 = F_4 ( V_7 , struct V_64 , V_7 ) ;
F_36 ( V_65 -> V_59 != NULL ) ;
F_57 ( & V_65 -> V_66 ) ;
if ( V_65 -> F_9 )
V_65 -> F_9 ( & V_7 ) ;
}
static void V_57 ( struct V_59 * V_59 )
{
struct V_64 * V_65 =
(struct V_64 * ) V_59 -> V_67 ;
struct V_6 * V_7 = & V_65 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_2 -> V_14 ;
if ( V_14 -> V_55 )
V_14 -> V_55 ( V_59 ) ;
F_58 ( & V_65 -> V_66 ) ;
if ( V_65 -> V_59 == V_59 )
V_65 -> V_59 = NULL ;
F_59 ( & V_65 -> V_66 ) ;
F_33 ( V_14 -> V_34 , V_14 -> V_58 ) ;
F_17 ( & V_7 ) ;
}
int F_60 ( struct V_1 * V_2 ,
int V_68 , T_3 * V_69 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_59 * V_59 ;
struct V_64 * V_65 ;
struct V_6 * V_7 ;
int V_15 ;
V_59 = F_61 ( V_68 ) ;
if ( F_62 ( V_59 ) )
return F_63 ( V_59 ) ;
if ( V_59 -> V_52 != & V_14 -> V_52 )
return - V_70 ;
V_65 = (struct V_64 * ) V_59 -> V_67 ;
V_7 = & V_65 -> V_7 ;
* V_69 = V_7 -> V_18 . V_23 ;
V_15 = F_16 ( V_2 , V_7 , V_20 , NULL ) ;
F_64 ( V_59 ) ;
return V_15 ;
}
int F_65 ( struct V_1 * V_2 ,
T_1 V_69 , T_1 V_71 ,
int * V_72 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_6 * V_7 ;
struct V_59 * V_59 ;
struct V_64 * V_65 ;
int V_15 ;
V_7 = F_20 ( V_2 , V_69 ) ;
if ( F_15 ( V_7 == NULL ||
V_7 -> V_10 != V_73 ) ) {
V_15 = - V_74 ;
goto V_75;
}
V_65 = F_4 ( V_7 , struct V_64 , V_7 ) ;
if ( F_15 ( ! V_7 -> V_8 ) ) {
V_15 = - V_36 ;
goto V_75;
}
V_15 = F_66 ( & V_65 -> V_66 ) ;
if ( F_15 ( V_15 != 0 ) ) {
V_15 = - V_76 ;
goto V_75;
}
V_59 = V_65 -> V_59 ;
if ( ! V_59 || ! F_54 ( V_59 ) ) {
F_67 ( V_77 ) ;
V_77 . V_52 = & V_14 -> V_52 ;
V_77 . V_78 = V_65 -> V_78 ;
V_77 . V_71 = V_71 ;
V_77 . V_67 = V_65 ;
V_15 = F_31 ( V_14 -> V_34 , V_14 -> V_58 ,
false , true ) ;
if ( F_15 ( V_15 != 0 ) ) {
F_59 ( & V_65 -> V_66 ) ;
goto V_75;
}
V_59 = F_68 ( & V_77 ) ;
if ( F_62 ( V_59 ) ) {
V_15 = F_63 ( V_59 ) ;
F_33 ( V_14 -> V_34 ,
V_14 -> V_58 ) ;
F_59 ( & V_65 -> V_66 ) ;
goto V_75;
}
V_7 = NULL ;
V_65 -> V_59 = V_59 ;
}
F_59 ( & V_65 -> V_66 ) ;
V_15 = F_69 ( V_59 , V_71 ) ;
if ( V_15 >= 0 ) {
* V_72 = V_15 ;
V_15 = 0 ;
} else
F_64 ( V_59 ) ;
V_75:
if ( V_7 )
F_17 ( & V_7 ) ;
return V_15 ;
}
int F_70 ( struct V_1 * V_2 , T_4 V_78 ,
struct V_64 * V_65 , bool V_8 ,
enum V_9 type ,
void (* F_9) ( struct V_6 * * ) ,
void (* F_10) ( struct V_6 * ,
enum V_11 V_12 ) )
{
F_71 ( & V_65 -> V_66 ) ;
V_65 -> V_78 = F_72 ( V_78 ) ;
V_65 -> V_79 = type ;
V_65 -> V_59 = NULL ;
V_65 -> F_9 = F_9 ;
return F_8 ( V_2 , & V_65 -> V_7 , V_8 ,
V_73 ,
F_56 ,
F_10 ) ;
}
