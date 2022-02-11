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
int F_16 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
enum V_11 V_12 , bool * V_30 )
{
struct V_25 * V_26 = & V_2 -> V_27 [ V_12 ] ;
struct V_28 * V_31 ;
struct V_24 * V_18 ;
struct V_32 * V_33 = V_2 -> V_14 -> V_33 ;
int V_15 = - V_34 ;
if ( V_7 -> V_2 != V_2 && ! V_7 -> V_8 )
return - V_35 ;
if ( V_30 != NULL )
* V_30 = true ;
while ( V_15 == - V_34 ) {
F_21 () ;
V_15 = F_22 ( V_26 , V_7 -> V_18 . V_23 , & V_18 ) ;
if ( V_15 == 0 ) {
V_31 = F_24 ( V_18 , struct V_28 , V_18 ) ;
if ( F_25 ( & V_31 -> V_4 ) ) {
F_26 () ;
break;
}
}
F_26 () ;
V_15 = F_28 ( V_33 , sizeof( * V_31 ) ,
false , false ) ;
if ( F_15 ( V_15 != 0 ) )
return V_15 ;
V_31 = F_29 ( sizeof( * V_31 ) , V_36 ) ;
if ( F_15 ( V_31 == NULL ) ) {
F_30 ( V_33 , sizeof( * V_31 ) ) ;
return - V_37 ;
}
V_31 -> V_18 . V_23 = V_7 -> V_18 . V_23 ;
V_31 -> V_29 = V_7 ;
V_31 -> V_2 = V_2 ;
V_31 -> V_12 = V_12 ;
F_11 ( & V_31 -> V_4 ) ;
F_12 ( & V_2 -> V_38 ) ;
V_15 = F_31 ( V_26 , & V_31 -> V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
F_32 ( & V_31 -> V_39 , & V_2 -> V_40 ) ;
F_2 ( & V_7 -> V_3 ) ;
F_14 ( & V_2 -> V_38 ) ;
if ( V_30 != NULL )
* V_30 = false ;
break;
}
F_14 ( & V_2 -> V_38 ) ;
F_33 ( V_15 != - V_34 ) ;
F_30 ( V_33 , sizeof( * V_31 ) ) ;
F_5 ( V_31 ) ;
}
return V_15 ;
}
static void F_34 ( struct V_4 * V_4 )
{
struct V_28 * V_31 =
F_4 ( V_4 , struct V_28 , V_4 ) ;
struct V_6 * V_7 = V_31 -> V_29 ;
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_25 * V_26 ;
struct V_32 * V_33 = V_2 -> V_14 -> V_33 ;
V_26 = & V_2 -> V_27 [ V_31 -> V_12 ] ;
( void ) F_18 ( V_26 , & V_31 -> V_18 ) ;
F_35 ( & V_31 -> V_39 ) ;
F_14 ( & V_2 -> V_38 ) ;
if ( V_31 -> V_12 != V_20 && V_7 -> F_10 )
V_7 -> F_10 ( V_7 , V_31 -> V_12 ) ;
F_17 ( & V_31 -> V_29 ) ;
F_30 ( V_33 , sizeof( * V_31 ) ) ;
F_36 ( V_31 , V_41 ) ;
F_12 ( & V_2 -> V_38 ) ;
}
int F_37 ( struct V_1 * V_2 ,
unsigned long V_23 , enum V_11 V_12 )
{
struct V_25 * V_26 = & V_2 -> V_27 [ V_12 ] ;
struct V_28 * V_31 ;
struct V_24 * V_18 ;
int V_15 ;
F_12 ( & V_2 -> V_38 ) ;
V_15 = F_38 ( V_26 , V_23 , & V_18 ) ;
if ( F_15 ( V_15 != 0 ) ) {
F_14 ( & V_2 -> V_38 ) ;
return - V_34 ;
}
V_31 = F_24 ( V_18 , struct V_28 , V_18 ) ;
F_7 ( & V_31 -> V_4 , F_34 ) ;
F_14 ( & V_2 -> V_38 ) ;
return 0 ;
}
void F_39 ( struct V_1 * * V_5 )
{
struct V_28 * V_31 ;
struct V_42 * V_43 ;
unsigned int V_44 ;
struct V_1 * V_2 = * V_5 ;
* V_5 = NULL ;
F_12 ( & V_2 -> V_38 ) ;
while ( ! F_40 ( & V_2 -> V_40 ) ) {
V_43 = V_2 -> V_40 . V_45 ;
V_31 = F_41 ( V_43 , struct V_28 , V_39 ) ;
F_34 ( & V_31 -> V_4 ) ;
}
for ( V_44 = 0 ; V_44 < V_46 ; ++ V_44 )
F_42 ( & V_2 -> V_27 [ V_44 ] ) ;
F_14 ( & V_2 -> V_38 ) ;
F_6 ( & V_2 ) ;
}
struct V_1 * F_43 ( struct V_13 * V_14 ,
unsigned int V_47 )
{
struct V_1 * V_2 = F_29 ( sizeof( * V_2 ) , V_36 ) ;
unsigned int V_44 ;
unsigned int V_48 = 0 ;
int V_15 ;
if ( F_15 ( V_2 == NULL ) )
return NULL ;
F_44 ( & V_2 -> V_38 ) ;
V_2 -> V_14 = V_14 ;
F_11 ( & V_2 -> V_3 ) ;
F_45 ( & V_2 -> V_40 ) ;
for ( V_44 = 0 ; V_44 < V_46 ; ++ V_44 ) {
V_15 = F_46 ( & V_2 -> V_27 [ V_44 ] , V_47 ) ;
if ( V_15 ) {
V_48 = V_44 ;
goto V_49;
}
}
return V_2 ;
V_49:
for ( V_44 = 0 ; V_44 < V_48 ; ++ V_44 )
F_42 ( & V_2 -> V_27 [ V_44 ] ) ;
F_5 ( V_2 ) ;
return NULL ;
}
struct V_13 *
F_47 ( struct V_32 * V_33 ,
unsigned int V_47 ,
const struct V_50 * V_51 )
{
struct V_13 * V_14 = F_29 ( sizeof( * V_14 ) , V_36 ) ;
int V_15 ;
if ( F_15 ( V_14 == NULL ) )
return NULL ;
V_14 -> V_33 = V_33 ;
F_44 ( & V_14 -> V_16 ) ;
F_48 ( & V_14 -> V_52 , 0 ) ;
V_15 = F_46 ( & V_14 -> V_17 , V_47 ) ;
if ( V_15 != 0 )
goto V_53;
V_14 -> V_51 = * V_51 ;
V_14 -> V_54 = V_14 -> V_51 . V_55 ;
V_14 -> V_51 . V_55 = V_56 ;
V_14 -> V_57 = F_49 ( sizeof( struct V_58 ) ) +
F_49 ( sizeof( struct V_59 ) ) ;
return V_14 ;
V_53:
F_5 ( V_14 ) ;
return NULL ;
}
void F_50 ( struct V_13 * * V_60 )
{
struct V_13 * V_14 = * V_60 ;
* V_60 = NULL ;
F_12 ( & V_14 -> V_16 ) ;
F_42 ( & V_14 -> V_17 ) ;
F_14 ( & V_14 -> V_16 ) ;
F_5 ( V_14 ) ;
}
static bool T_2 F_51 ( struct V_58 * V_61 )
{
return F_52 ( & V_61 -> V_59 -> V_62 ) != 0L ;
}
static void F_53 ( struct V_6 * * V_22 )
{
struct V_6 * V_7 = * V_22 ;
struct V_63 * V_64 ;
* V_22 = NULL ;
V_64 = F_4 ( V_7 , struct V_63 , V_7 ) ;
F_33 ( V_64 -> V_58 != NULL ) ;
F_54 ( & V_64 -> V_65 ) ;
if ( V_64 -> F_9 )
V_64 -> F_9 ( & V_7 ) ;
}
static void V_56 ( struct V_58 * V_58 )
{
struct V_63 * V_64 =
(struct V_63 * ) V_58 -> V_66 ;
struct V_6 * V_7 = & V_64 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_2 -> V_14 ;
if ( V_14 -> V_54 )
V_14 -> V_54 ( V_58 ) ;
F_55 ( & V_64 -> V_65 ) ;
if ( V_64 -> V_58 == V_58 )
V_64 -> V_58 = NULL ;
F_56 ( & V_64 -> V_65 ) ;
F_30 ( V_14 -> V_33 , V_14 -> V_57 ) ;
F_17 ( & V_7 ) ;
}
int F_57 ( struct V_1 * V_2 ,
int V_67 , T_3 * V_68 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_58 * V_58 ;
struct V_63 * V_64 ;
struct V_6 * V_7 ;
int V_15 ;
V_58 = F_58 ( V_67 ) ;
if ( F_59 ( V_58 ) )
return F_60 ( V_58 ) ;
if ( V_58 -> V_51 != & V_14 -> V_51 )
return - V_69 ;
V_64 = (struct V_63 * ) V_58 -> V_66 ;
V_7 = & V_64 -> V_7 ;
* V_68 = V_7 -> V_18 . V_23 ;
V_15 = F_16 ( V_2 , V_7 , V_20 , NULL ) ;
F_61 ( V_58 ) ;
return V_15 ;
}
int F_62 ( struct V_1 * V_2 ,
T_1 V_68 , T_1 V_70 ,
int * V_71 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_6 * V_7 ;
struct V_58 * V_58 ;
struct V_63 * V_64 ;
int V_15 ;
V_7 = F_20 ( V_2 , V_68 ) ;
if ( F_15 ( V_7 == NULL ||
V_7 -> V_10 != V_72 ) ) {
V_15 = - V_73 ;
goto V_74;
}
V_64 = F_4 ( V_7 , struct V_63 , V_7 ) ;
if ( F_15 ( ! V_7 -> V_8 ) ) {
V_15 = - V_35 ;
goto V_74;
}
V_15 = F_63 ( & V_64 -> V_65 ) ;
if ( F_15 ( V_15 != 0 ) ) {
V_15 = - V_75 ;
goto V_74;
}
V_58 = V_64 -> V_58 ;
if ( ! V_58 || ! F_51 ( V_58 ) ) {
V_15 = F_28 ( V_14 -> V_33 , V_14 -> V_57 ,
false , true ) ;
if ( F_15 ( V_15 != 0 ) ) {
F_56 ( & V_64 -> V_65 ) ;
goto V_74;
}
V_58 = F_64 ( V_64 , & V_14 -> V_51 ,
V_64 -> V_76 , V_70 ) ;
if ( F_59 ( V_58 ) ) {
V_15 = F_60 ( V_58 ) ;
F_30 ( V_14 -> V_33 ,
V_14 -> V_57 ) ;
F_56 ( & V_64 -> V_65 ) ;
goto V_74;
}
V_7 = NULL ;
V_64 -> V_58 = V_58 ;
}
F_56 ( & V_64 -> V_65 ) ;
V_15 = F_65 ( V_58 , V_70 ) ;
if ( V_15 >= 0 ) {
* V_71 = V_15 ;
V_15 = 0 ;
} else
F_61 ( V_58 ) ;
V_74:
if ( V_7 )
F_17 ( & V_7 ) ;
return V_15 ;
}
int F_66 ( struct V_1 * V_2 , T_4 V_76 ,
struct V_63 * V_64 , bool V_8 ,
enum V_9 type ,
void (* F_9) ( struct V_6 * * ) ,
void (* F_10) ( struct V_6 * ,
enum V_11 V_12 ) )
{
F_67 ( & V_64 -> V_65 ) ;
V_64 -> V_76 = F_68 ( V_76 ) ;
V_64 -> V_77 = type ;
V_64 -> V_58 = NULL ;
V_64 -> F_9 = F_9 ;
return F_8 ( V_2 , & V_64 -> V_7 , V_8 ,
V_72 ,
F_53 ,
F_10 ) ;
}
