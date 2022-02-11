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
F_11 ( & V_14 -> V_16 ) ;
F_12 ( & V_7 -> V_3 ) ;
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
( void ) F_18 ( & V_14 -> V_17 , & V_7 -> V_18 ) ;
V_19:
return V_15 ;
}
static void F_19 ( struct V_4 * V_4 )
{
struct V_6 * V_7 =
F_4 ( V_4 , struct V_6 , V_3 ) ;
struct V_13 * V_14 = V_7 -> V_2 -> V_14 ;
( void ) F_18 ( & V_14 -> V_17 , & V_7 -> V_18 ) ;
F_14 ( & V_14 -> V_16 ) ;
if ( V_7 -> F_9 ) {
F_6 ( & V_7 -> V_2 ) ;
V_7 -> F_9 ( & V_7 ) ;
}
F_11 ( & V_14 -> V_16 ) ;
}
void F_17 ( struct V_6 * * V_22 )
{
struct V_6 * V_7 = * V_22 ;
struct V_13 * V_14 = V_7 -> V_2 -> V_14 ;
* V_22 = NULL ;
F_11 ( & V_14 -> V_16 ) ;
F_7 ( & V_7 -> V_3 , F_19 ) ;
F_14 ( & V_14 -> V_16 ) ;
}
struct V_6 * F_20 ( struct V_1 * V_2 ,
T_1 V_23 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_6 * V_7 ;
struct V_24 * V_18 ;
int V_15 ;
F_21 ( & V_14 -> V_16 ) ;
V_15 = F_22 ( & V_14 -> V_17 , V_23 , & V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
V_7 = F_24 ( V_18 , struct V_6 , V_18 ) ;
F_2 ( & V_7 -> V_3 ) ;
}
F_25 ( & V_14 -> V_16 ) ;
if ( F_15 ( V_15 != 0 ) )
return NULL ;
if ( V_2 != V_7 -> V_2 && ! V_7 -> V_8 ) {
F_26 ( L_1 ) ;
F_17 ( & V_7 ) ;
return NULL ;
}
return V_7 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
enum V_11 V_12 , bool * V_25 )
{
struct V_26 * V_27 = & V_2 -> V_28 [ V_12 ] ;
struct V_29 * V_30 ;
struct V_24 * V_18 ;
struct V_31 * V_32 = V_2 -> V_14 -> V_32 ;
int V_15 = - V_33 ;
if ( V_25 != NULL )
* V_25 = true ;
while ( V_15 == - V_33 ) {
F_21 ( & V_2 -> V_34 ) ;
V_15 = F_22 ( V_27 , V_7 -> V_18 . V_23 , & V_18 ) ;
if ( V_15 == 0 ) {
V_30 = F_24 ( V_18 , struct V_29 , V_18 ) ;
F_2 ( & V_30 -> V_4 ) ;
F_25 ( & V_2 -> V_34 ) ;
break;
}
F_25 ( & V_2 -> V_34 ) ;
V_15 = F_27 ( V_32 , sizeof( * V_30 ) ,
false , false ) ;
if ( F_15 ( V_15 != 0 ) )
return V_15 ;
V_30 = F_28 ( sizeof( * V_30 ) , V_35 ) ;
if ( F_15 ( V_30 == NULL ) ) {
F_29 ( V_32 , sizeof( * V_30 ) ) ;
return - V_36 ;
}
V_30 -> V_18 . V_23 = V_7 -> V_18 . V_23 ;
V_30 -> V_37 = V_7 ;
V_30 -> V_2 = V_2 ;
V_30 -> V_12 = V_12 ;
F_12 ( & V_30 -> V_4 ) ;
F_11 ( & V_2 -> V_34 ) ;
V_15 = F_30 ( V_27 , & V_30 -> V_18 ) ;
if ( F_23 ( V_15 == 0 ) ) {
F_31 ( & V_30 -> V_38 , & V_2 -> V_39 ) ;
F_2 ( & V_7 -> V_3 ) ;
F_14 ( & V_2 -> V_34 ) ;
if ( V_25 != NULL )
* V_25 = false ;
break;
}
F_14 ( & V_2 -> V_34 ) ;
F_32 ( V_15 != - V_33 ) ;
F_29 ( V_32 , sizeof( * V_30 ) ) ;
F_5 ( V_30 ) ;
}
return V_15 ;
}
static void F_33 ( struct V_4 * V_4 )
{
struct V_29 * V_30 =
F_4 ( V_4 , struct V_29 , V_4 ) ;
struct V_6 * V_7 = V_30 -> V_37 ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_26 * V_27 ;
struct V_31 * V_32 = V_2 -> V_14 -> V_32 ;
V_27 = & V_2 -> V_28 [ V_30 -> V_12 ] ;
( void ) F_18 ( V_27 , & V_30 -> V_18 ) ;
F_34 ( & V_30 -> V_38 ) ;
F_14 ( & V_2 -> V_34 ) ;
if ( V_30 -> V_12 != V_20 && V_7 -> F_10 )
V_7 -> F_10 ( V_7 , V_30 -> V_12 ) ;
F_17 ( & V_30 -> V_37 ) ;
F_29 ( V_32 , sizeof( * V_30 ) ) ;
F_5 ( V_30 ) ;
F_11 ( & V_2 -> V_34 ) ;
}
int F_35 ( struct V_1 * V_2 ,
unsigned long V_23 , enum V_11 V_12 )
{
struct V_26 * V_27 = & V_2 -> V_28 [ V_12 ] ;
struct V_29 * V_30 ;
struct V_24 * V_18 ;
int V_15 ;
F_11 ( & V_2 -> V_34 ) ;
V_15 = F_22 ( V_27 , V_23 , & V_18 ) ;
if ( F_15 ( V_15 != 0 ) ) {
F_14 ( & V_2 -> V_34 ) ;
return - V_33 ;
}
V_30 = F_24 ( V_18 , struct V_29 , V_18 ) ;
F_7 ( & V_30 -> V_4 , F_33 ) ;
F_14 ( & V_2 -> V_34 ) ;
return 0 ;
}
void F_36 ( struct V_1 * * V_5 )
{
struct V_29 * V_30 ;
struct V_40 * V_41 ;
unsigned int V_42 ;
struct V_1 * V_2 = * V_5 ;
* V_5 = NULL ;
F_11 ( & V_2 -> V_34 ) ;
while ( ! F_37 ( & V_2 -> V_39 ) ) {
V_41 = V_2 -> V_39 . V_43 ;
V_30 = F_38 ( V_41 , struct V_29 , V_38 ) ;
F_33 ( & V_30 -> V_4 ) ;
}
for ( V_42 = 0 ; V_42 < V_44 ; ++ V_42 )
F_39 ( & V_2 -> V_28 [ V_42 ] ) ;
F_14 ( & V_2 -> V_34 ) ;
F_6 ( & V_2 ) ;
}
struct V_1 * F_40 ( struct V_13 * V_14 ,
unsigned int V_45 )
{
struct V_1 * V_2 = F_28 ( sizeof( * V_2 ) , V_35 ) ;
unsigned int V_42 ;
unsigned int V_46 = 0 ;
int V_15 ;
if ( F_15 ( V_2 == NULL ) )
return NULL ;
F_41 ( & V_2 -> V_34 ) ;
V_2 -> V_14 = V_14 ;
F_12 ( & V_2 -> V_3 ) ;
F_42 ( & V_2 -> V_39 ) ;
for ( V_42 = 0 ; V_42 < V_44 ; ++ V_42 ) {
V_15 = F_43 ( & V_2 -> V_28 [ V_42 ] , V_45 ) ;
if ( V_15 ) {
V_46 = V_42 ;
goto V_47;
}
}
return V_2 ;
V_47:
for ( V_42 = 0 ; V_42 < V_46 ; ++ V_42 )
F_39 ( & V_2 -> V_28 [ V_42 ] ) ;
F_5 ( V_2 ) ;
return NULL ;
}
struct V_13 * F_44 ( struct V_31
* V_32 ,
unsigned int V_45 )
{
struct V_13 * V_14 = F_28 ( sizeof( * V_14 ) , V_35 ) ;
int V_15 ;
if ( F_15 ( V_14 == NULL ) )
return NULL ;
V_14 -> V_32 = V_32 ;
F_41 ( & V_14 -> V_16 ) ;
F_45 ( & V_14 -> V_48 , 0 ) ;
V_15 = F_43 ( & V_14 -> V_17 , V_45 ) ;
if ( F_23 ( V_15 == 0 ) )
return V_14 ;
F_5 ( V_14 ) ;
return NULL ;
}
void F_46 ( struct V_13 * * V_49 )
{
struct V_13 * V_14 = * V_49 ;
* V_49 = NULL ;
F_11 ( & V_14 -> V_16 ) ;
F_39 ( & V_14 -> V_17 ) ;
F_14 ( & V_14 -> V_16 ) ;
F_5 ( V_14 ) ;
}
