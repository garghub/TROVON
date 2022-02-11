static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static inline
struct V_1 * F_3 ( struct V_2 * * V_3 )
{
return F_4 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_5 )
{
if ( V_5 == NULL )
return;
if ( V_5 -> V_3 != NULL )
F_2 ( V_5 -> V_3 ) -> V_4 = NULL ;
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
if ( V_7 == NULL )
return;
F_5 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
struct V_1 * * V_5 )
{
* V_5 = F_9 ( sizeof( struct V_1 ) , V_10 ) ;
if ( * V_5 == NULL )
return - V_11 ;
( * V_5 ) -> V_3 = V_3 ;
( * V_5 ) -> V_7 = V_7 ;
V_7 -> V_8 = * V_5 ;
V_7 -> V_9 = F_7 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_5 )
{
struct V_12 * V_13 = F_2 ( V_5 -> V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_11 ( V_7 -> V_14 , L_1 , sizeof( V_7 -> V_14 ) ) ;
snprintf ( V_7 -> V_15 , sizeof( V_7 -> V_15 ) , L_2 ,
V_13 -> V_16 ) ;
snprintf ( V_7 -> V_17 , sizeof( V_7 -> V_17 ) ,
L_3 ,
V_13 -> V_16 , V_13 -> V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = F_2 ( V_3 ) ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_5 ;
int V_19 ;
V_19 = F_13 ( V_20 ,
V_21 ,
V_22 , 0 , & V_7 ) ;
if ( V_19 ) {
F_14 ( L_4 ,
V_23 , V_19 ) ;
goto V_24;
}
V_19 = F_8 ( V_3 , V_7 , & V_5 ) ;
if ( V_19 ) {
F_14 ( L_5 ,
V_23 , V_19 ) ;
goto V_25;
}
F_10 ( V_5 ) ;
V_19 = F_15 ( V_5 ) ;
if ( V_19 ) {
F_14 ( L_6 ,
V_23 , V_19 ) ;
goto V_25;
}
V_13 -> V_4 = V_5 ;
V_19 = F_16 ( V_7 ) ;
if ( V_19 ) {
V_13 -> V_4 = NULL ;
F_14 ( L_7 ,
V_23 , V_19 ) ;
goto V_25;
}
return 0 ;
V_25:
if ( V_7 != NULL )
F_17 ( V_7 ) ;
V_24:
return V_19 ;
}
int F_18 ( struct V_12 * V_13 )
{
struct V_2 * V_3 = & V_13 -> V_3 ;
struct V_26 * V_27 ;
if ( V_3 == NULL ) {
F_19 ( V_28 L_8 ,
V_23 ) ;
return 0 ;
}
V_13 = F_2 ( V_3 ) ;
if ( V_13 == NULL ) {
F_19 ( V_28 L_9 ) ;
return 0 ;
}
V_27 = & V_13 -> V_29 [ V_30 ] ;
if ( V_27 -> V_31 == NULL ) {
F_20 ( L_10
L_11 , V_23 ) ;
return 0 ;
}
if ( V_13 -> V_4 != NULL ) {
F_14 ( L_12 ,
V_23 ) ;
return 0 ;
}
if ( F_12 ( V_3 ) ) {
F_14 ( L_13 ,
V_23 ) ;
} else {
F_20 ( L_14
L_15 , V_23 ) ;
}
return 0 ;
}
static int T_1 F_21 ( void )
{
F_19 ( V_32 L_16 ) ;
V_33 = & F_18 ;
return 0 ;
}
static void T_2 F_22 ( struct V_1 * V_5 )
{
struct V_12 * V_13 = F_2 ( V_5 -> V_3 ) ;
F_17 ( V_5 -> V_7 ) ;
V_13 -> V_4 = NULL ;
}
static int T_2 F_23 ( struct V_34 * V_35 , void * V_36 )
{
struct V_2 * V_3 = F_24 ( V_35 ) ;
struct V_1 * V_5 ;
if ( V_3 == NULL ) {
F_19 ( V_28 L_8 ,
V_23 ) ;
return 0 ;
}
V_5 = F_1 ( V_3 ) ;
if ( V_5 == NULL ) {
F_25 ( L_17 ,
V_23 ) ;
return 0 ;
}
F_22 ( V_5 ) ;
return 0 ;
}
static void T_2 F_26 ( void )
{
struct V_37 * V_38 ;
int V_19 ;
F_19 ( V_32 L_18 ) ;
V_38 = F_27 ( L_19 , & V_39 ) ;
V_19 = F_28 ( V_38 , NULL , NULL , F_23 ) ;
F_29 ( V_38 ) ;
V_33 = NULL ;
F_19 ( V_32 L_20 ) ;
}
