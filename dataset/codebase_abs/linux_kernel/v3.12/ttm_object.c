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
struct V_13 * F_51 ( struct V_33
* V_34 ,
unsigned int V_46 )
{
struct V_13 * V_14 = F_32 ( sizeof( * V_14 ) , V_36 ) ;
int V_15 ;
if ( F_15 ( V_14 == NULL ) )
return NULL ;
V_14 -> V_34 = V_34 ;
F_52 ( & V_14 -> V_16 ) ;
F_53 ( & V_14 -> V_49 , 0 ) ;
V_15 = F_50 ( & V_14 -> V_17 , V_46 ) ;
if ( F_23 ( V_15 == 0 ) )
return V_14 ;
F_5 ( V_14 ) ;
return NULL ;
}
void F_54 ( struct V_13 * * V_50 )
{
struct V_13 * V_14 = * V_50 ;
* V_50 = NULL ;
F_12 ( & V_14 -> V_16 ) ;
F_46 ( & V_14 -> V_17 ) ;
F_14 ( & V_14 -> V_16 ) ;
F_5 ( V_14 ) ;
}
