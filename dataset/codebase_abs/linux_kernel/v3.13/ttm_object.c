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
if ( V_7 -> F_9 ) {
F_6 ( & V_7 -> V_2 ) ;
V_7 -> F_9 ( & V_7 ) ;
}
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
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_6 * V_24 ( V_7 ) ;
struct V_25 * V_18 ;
int V_15 ;
F_21 () ;
V_15 = F_22 ( & V_14 -> V_17 , V_23 , & V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
V_7 = F_24 ( V_18 , struct V_6 , V_18 ) ;
V_15 = F_25 ( & V_7 -> V_3 ) ? 0 : - V_26 ;
}
F_26 () ;
if ( F_15 ( V_15 != 0 ) )
return NULL ;
if ( V_2 != V_7 -> V_2 && ! V_7 -> V_8 ) {
F_27 ( L_1 ) ;
F_17 ( & V_7 ) ;
return NULL ;
}
return V_7 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
enum V_11 V_12 , bool * V_27 )
{
struct V_28 * V_29 = & V_2 -> V_30 [ V_12 ] ;
struct V_31 * V_32 ;
struct V_25 * V_18 ;
struct V_33 * V_34 = V_2 -> V_14 -> V_34 ;
int V_15 = - V_26 ;
if ( V_27 != NULL )
* V_27 = true ;
while ( V_15 == - V_26 ) {
F_28 ( & V_2 -> V_35 ) ;
V_15 = F_29 ( V_29 , V_7 -> V_18 . V_23 , & V_18 ) ;
if ( V_15 == 0 ) {
V_32 = F_24 ( V_18 , struct V_31 , V_18 ) ;
F_2 ( & V_32 -> V_4 ) ;
F_30 ( & V_2 -> V_35 ) ;
break;
}
F_30 ( & V_2 -> V_35 ) ;
V_15 = F_31 ( V_34 , sizeof( * V_32 ) ,
false , false ) ;
if ( F_15 ( V_15 != 0 ) )
return V_15 ;
V_32 = F_32 ( sizeof( * V_32 ) , V_36 ) ;
if ( F_15 ( V_32 == NULL ) ) {
F_33 ( V_34 , sizeof( * V_32 ) ) ;
return - V_37 ;
}
V_32 -> V_18 . V_23 = V_7 -> V_18 . V_23 ;
V_32 -> V_38 = V_7 ;
V_32 -> V_2 = V_2 ;
V_32 -> V_12 = V_12 ;
F_11 ( & V_32 -> V_4 ) ;
F_34 ( & V_2 -> V_35 ) ;
V_15 = F_35 ( V_29 , & V_32 -> V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
F_36 ( & V_32 -> V_39 , & V_2 -> V_40 ) ;
F_2 ( & V_7 -> V_3 ) ;
F_37 ( & V_2 -> V_35 ) ;
if ( V_27 != NULL )
* V_27 = false ;
break;
}
F_37 ( & V_2 -> V_35 ) ;
F_38 ( V_15 != - V_26 ) ;
F_33 ( V_34 , sizeof( * V_32 ) ) ;
F_5 ( V_32 ) ;
}
return V_15 ;
}
static void F_39 ( struct V_4 * V_4 )
{
struct V_31 * V_32 =
F_4 ( V_4 , struct V_31 , V_4 ) ;
struct V_6 * V_7 = V_32 -> V_38 ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_28 * V_29 ;
struct V_33 * V_34 = V_2 -> V_14 -> V_34 ;
V_29 = & V_2 -> V_30 [ V_32 -> V_12 ] ;
( void ) F_40 ( V_29 , & V_32 -> V_18 ) ;
F_41 ( & V_32 -> V_39 ) ;
F_37 ( & V_2 -> V_35 ) ;
if ( V_32 -> V_12 != V_20 && V_7 -> F_10 )
V_7 -> F_10 ( V_7 , V_32 -> V_12 ) ;
F_17 ( & V_32 -> V_38 ) ;
F_33 ( V_34 , sizeof( * V_32 ) ) ;
F_5 ( V_32 ) ;
F_34 ( & V_2 -> V_35 ) ;
}
int F_42 ( struct V_1 * V_2 ,
unsigned long V_23 , enum V_11 V_12 )
{
struct V_28 * V_29 = & V_2 -> V_30 [ V_12 ] ;
struct V_31 * V_32 ;
struct V_25 * V_18 ;
int V_15 ;
F_34 ( & V_2 -> V_35 ) ;
V_15 = F_29 ( V_29 , V_23 , & V_18 ) ;
if ( F_15 ( V_15 != 0 ) ) {
F_37 ( & V_2 -> V_35 ) ;
return - V_26 ;
}
V_32 = F_24 ( V_18 , struct V_31 , V_18 ) ;
F_7 ( & V_32 -> V_4 , F_39 ) ;
F_37 ( & V_2 -> V_35 ) ;
return 0 ;
}
void F_43 ( struct V_1 * * V_5 )
{
struct V_31 * V_32 ;
struct V_41 * V_42 ;
unsigned int V_43 ;
struct V_1 * V_2 = * V_5 ;
* V_5 = NULL ;
F_34 ( & V_2 -> V_35 ) ;
while ( ! F_44 ( & V_2 -> V_40 ) ) {
V_42 = V_2 -> V_40 . V_44 ;
V_32 = F_45 ( V_42 , struct V_31 , V_39 ) ;
F_39 ( & V_32 -> V_4 ) ;
}
for ( V_43 = 0 ; V_43 < V_45 ; ++ V_43 )
F_46 ( & V_2 -> V_30 [ V_43 ] ) ;
F_37 ( & V_2 -> V_35 ) ;
F_6 ( & V_2 ) ;
}
struct V_1 * F_47 ( struct V_13 * V_14 ,
unsigned int V_46 )
{
struct V_1 * V_2 = F_32 ( sizeof( * V_2 ) , V_36 ) ;
unsigned int V_43 ;
unsigned int V_47 = 0 ;
int V_15 ;
if ( F_15 ( V_2 == NULL ) )
return NULL ;
F_48 ( & V_2 -> V_35 ) ;
V_2 -> V_14 = V_14 ;
F_11 ( & V_2 -> V_3 ) ;
F_49 ( & V_2 -> V_40 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; ++ V_43 ) {
V_15 = F_50 ( & V_2 -> V_30 [ V_43 ] , V_46 ) ;
if ( V_15 ) {
V_47 = V_43 ;
goto V_48;
}
}
return V_2 ;
V_48:
for ( V_43 = 0 ; V_43 < V_47 ; ++ V_43 )
F_46 ( & V_2 -> V_30 [ V_43 ] ) ;
F_5 ( V_2 ) ;
return NULL ;
}
struct V_13 *
F_51 ( struct V_33 * V_34 ,
unsigned int V_46 ,
const struct V_49 * V_50 )
{
struct V_13 * V_14 = F_32 ( sizeof( * V_14 ) , V_36 ) ;
int V_15 ;
if ( F_15 ( V_14 == NULL ) )
return NULL ;
V_14 -> V_34 = V_34 ;
F_52 ( & V_14 -> V_16 ) ;
F_53 ( & V_14 -> V_51 , 0 ) ;
V_15 = F_50 ( & V_14 -> V_17 , V_46 ) ;
if ( V_15 != 0 )
goto V_52;
V_14 -> V_50 = * V_50 ;
V_14 -> V_53 = V_14 -> V_50 . V_54 ;
V_14 -> V_50 . V_54 = V_55 ;
V_14 -> V_56 = F_54 ( sizeof( struct V_57 ) ) +
F_54 ( sizeof( struct V_58 ) ) ;
return V_14 ;
V_52:
F_5 ( V_14 ) ;
return NULL ;
}
void F_55 ( struct V_13 * * V_59 )
{
struct V_13 * V_14 = * V_59 ;
* V_59 = NULL ;
F_12 ( & V_14 -> V_16 ) ;
F_46 ( & V_14 -> V_17 ) ;
F_14 ( & V_14 -> V_16 ) ;
F_5 ( V_14 ) ;
}
static bool T_2 F_56 ( struct V_57 * V_60 )
{
return F_57 ( & V_60 -> V_58 -> V_61 ) != 0L ;
}
static void F_58 ( struct V_6 * * V_22 )
{
struct V_6 * V_7 = * V_22 ;
struct V_62 * V_63 ;
* V_22 = NULL ;
V_63 = F_4 ( V_7 , struct V_62 , V_7 ) ;
F_38 ( V_63 -> V_57 != NULL ) ;
F_59 ( & V_63 -> V_64 ) ;
if ( V_63 -> F_9 )
V_63 -> F_9 ( & V_7 ) ;
}
static void V_55 ( struct V_57 * V_57 )
{
struct V_62 * V_63 =
(struct V_62 * ) V_57 -> V_65 ;
struct V_6 * V_7 = & V_63 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_2 -> V_14 ;
if ( V_14 -> V_53 )
V_14 -> V_53 ( V_57 ) ;
F_60 ( & V_63 -> V_64 ) ;
if ( V_63 -> V_57 == V_57 )
V_63 -> V_57 = NULL ;
F_61 ( & V_63 -> V_64 ) ;
F_33 ( V_14 -> V_34 , V_14 -> V_56 ) ;
F_17 ( & V_7 ) ;
}
int F_62 ( struct V_1 * V_2 ,
int V_66 , T_3 * V_67 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_57 * V_57 ;
struct V_62 * V_63 ;
struct V_6 * V_7 ;
int V_15 ;
V_57 = F_63 ( V_66 ) ;
if ( F_64 ( V_57 ) )
return F_65 ( V_57 ) ;
if ( V_57 -> V_50 != & V_14 -> V_50 )
return - V_68 ;
V_63 = (struct V_62 * ) V_57 -> V_65 ;
V_7 = & V_63 -> V_7 ;
* V_67 = V_7 -> V_18 . V_23 ;
V_15 = F_16 ( V_2 , V_7 , V_20 , NULL ) ;
F_66 ( V_57 ) ;
return V_15 ;
}
int F_67 ( struct V_1 * V_2 ,
T_1 V_67 , T_1 V_69 ,
int * V_70 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_6 * V_7 ;
struct V_57 * V_57 ;
struct V_62 * V_63 ;
int V_15 ;
V_7 = F_20 ( V_2 , V_67 ) ;
if ( F_15 ( V_7 == NULL ||
V_7 -> V_10 != V_71 ) ) {
V_15 = - V_72 ;
goto V_73;
}
V_63 = F_4 ( V_7 , struct V_62 , V_7 ) ;
if ( F_15 ( ! V_7 -> V_8 ) ) {
V_15 = - V_74 ;
goto V_73;
}
V_15 = F_68 ( & V_63 -> V_64 ) ;
if ( F_15 ( V_15 != 0 ) ) {
V_15 = - V_75 ;
goto V_73;
}
V_57 = V_63 -> V_57 ;
if ( ! V_57 || ! F_56 ( V_57 ) ) {
V_15 = F_31 ( V_14 -> V_34 , V_14 -> V_56 ,
false , true ) ;
if ( F_15 ( V_15 != 0 ) ) {
F_61 ( & V_63 -> V_64 ) ;
goto V_73;
}
V_57 = F_69 ( V_63 , & V_14 -> V_50 ,
V_63 -> V_76 , V_69 ) ;
if ( F_64 ( V_57 ) ) {
V_15 = F_65 ( V_57 ) ;
F_33 ( V_14 -> V_34 ,
V_14 -> V_56 ) ;
F_61 ( & V_63 -> V_64 ) ;
goto V_73;
}
V_7 = NULL ;
V_63 -> V_57 = V_57 ;
}
F_61 ( & V_63 -> V_64 ) ;
V_15 = F_70 ( V_57 , V_69 ) ;
if ( V_15 >= 0 ) {
* V_70 = V_15 ;
V_15 = 0 ;
} else
F_66 ( V_57 ) ;
V_73:
if ( V_7 )
F_17 ( & V_7 ) ;
return V_15 ;
}
int F_71 ( struct V_1 * V_2 , T_4 V_76 ,
struct V_62 * V_63 , bool V_8 ,
enum V_9 type ,
void (* F_9) ( struct V_6 * * ) ,
void (* F_10) ( struct V_6 * ,
enum V_11 V_12 ) )
{
F_72 ( & V_63 -> V_64 ) ;
V_63 -> V_76 = F_73 ( V_76 ) ;
V_63 -> V_77 = type ;
V_63 -> V_57 = NULL ;
V_63 -> F_9 = F_9 ;
return F_8 ( V_2 , & V_63 -> V_7 , V_8 ,
V_71 ,
F_58 ,
F_10 ) ;
}
