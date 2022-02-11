static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct {
T_1 V_5 ;
T_2 V_6 ;
} * V_7 ;
F_2 ( V_4 ) ;
V_7 = F_3 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_4 ( V_7 == NULL ) ) {
F_5 ( L_1
L_2 ) ;
return;
}
V_7 -> V_5 . V_8 = F_6 ( V_9 ) ;
V_7 -> V_5 . V_10 = F_6 ( sizeof( V_7 -> V_6 ) ) ;
V_7 -> V_6 . V_11 = F_6 ( V_2 -> V_8 ) ;
F_7 ( V_4 , sizeof( * V_7 ) ) ;
F_8 ( V_4 , false ) ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
void (* F_10) ( struct V_1 * V_2 ) )
{
int V_12 ;
struct {
T_1 V_5 ;
T_3 V_6 ;
} * V_7 ;
V_12 = F_11 ( V_4 , V_2 , false ,
F_10 , & V_13 ) ;
if ( F_4 ( V_12 != 0 ) ) {
F_5 ( L_3 ) ;
goto V_14;
}
if ( F_4 ( V_2 -> V_8 >= V_15 ) ) {
F_5 ( L_4 ) ;
F_12 ( & V_2 ) ;
return - V_16 ;
}
V_7 = F_3 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_4 ( V_7 == NULL ) ) {
F_5 ( L_5 ) ;
F_12 ( & V_2 ) ;
return - V_16 ;
}
V_7 -> V_5 . V_8 = F_6 ( V_17 ) ;
V_7 -> V_5 . V_10 = F_6 ( sizeof( V_7 -> V_6 ) ) ;
V_7 -> V_6 . V_11 = F_6 ( V_2 -> V_8 ) ;
F_7 ( V_4 , sizeof( * V_7 ) ) ;
( void ) F_13 ( V_4 , false ) ;
F_14 ( V_2 , F_1 ) ;
return 0 ;
V_14:
if ( F_10 == NULL )
F_15 ( V_2 ) ;
else
F_10 ( V_2 ) ;
return V_12 ;
}
struct V_1 * F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( sizeof( * V_2 ) , V_18 ) ;
int V_12 ;
if ( F_4 ( V_2 == NULL ) )
return NULL ;
V_12 = F_9 ( V_4 , V_2 , NULL ) ;
return ( V_12 == 0 ) ? V_2 : NULL ;
}
static struct V_1 *
F_18 ( struct V_19 * V_20 )
{
return & ( F_19 ( V_20 , struct V_21 , V_20 ) -> V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_21 * V_22 =
F_19 ( V_2 , struct V_21 , V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_21 ( V_22 , V_20 ) ;
F_22 ( F_23 ( V_4 ) ,
V_23 ) ;
}
static void F_24 ( struct V_19 * * V_24 )
{
struct V_19 * V_20 = * V_24 ;
struct V_21 * V_22 =
F_19 ( V_20 , struct V_21 , V_20 ) ;
struct V_1 * V_2 = & V_22 -> V_2 ;
* V_24 = NULL ;
F_12 ( & V_2 ) ;
}
int F_25 ( struct V_25 * V_26 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = (struct V_30 * ) V_27 ;
struct V_32 * V_33 = F_26 ( V_29 ) -> V_33 ;
return F_27 ( V_33 , V_31 -> V_11 , V_34 ) ;
}
int F_28 ( struct V_25 * V_26 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_29 ( V_26 ) ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_1 * V_35 ;
struct V_30 * V_31 = (struct V_30 * ) V_27 ;
struct V_32 * V_33 = F_26 ( V_29 ) -> V_33 ;
struct V_36 * V_37 = V_36 ( V_29 -> V_38 ) ;
int V_12 ;
if ( F_4 ( V_23 == 0 ) )
V_23 = F_30 ( sizeof( * V_22 ) ) + 128 ;
V_12 = F_31 ( & V_37 -> V_39 , true ) ;
if ( F_4 ( V_12 != 0 ) )
return V_12 ;
V_12 = F_32 ( F_23 ( V_4 ) ,
V_23 ,
false , true ) ;
if ( F_4 ( V_12 != 0 ) ) {
if ( V_12 != - V_40 )
F_5 ( L_6
L_7 ) ;
goto V_41;
}
V_22 = F_33 ( sizeof( * V_22 ) , V_18 ) ;
if ( F_4 ( V_22 == NULL ) ) {
F_22 ( F_23 ( V_4 ) ,
V_23 ) ;
V_12 = - V_16 ;
goto V_41;
}
V_2 = & V_22 -> V_2 ;
V_22 -> V_20 . V_42 = false ;
V_22 -> V_20 . V_33 = NULL ;
V_12 = F_9 ( V_4 , V_2 , F_20 ) ;
if ( F_4 ( V_12 != 0 ) )
goto V_41;
V_35 = F_34 ( & V_22 -> V_2 ) ;
V_12 = F_35 ( V_33 , & V_22 -> V_20 , false , V_43 ,
& F_24 , NULL ) ;
if ( F_4 ( V_12 != 0 ) ) {
F_12 ( & V_35 ) ;
goto V_44;
}
V_31 -> V_11 = V_22 -> V_20 . V_45 . V_46 ;
V_44:
F_12 ( & V_2 ) ;
V_41:
F_36 ( & V_37 -> V_39 ) ;
return V_12 ;
}
