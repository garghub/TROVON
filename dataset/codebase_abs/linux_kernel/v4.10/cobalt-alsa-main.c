static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
V_2 -> V_3 -> V_4 = NULL ;
F_2 ( V_2 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
if ( V_6 == NULL )
return;
F_1 ( V_6 -> V_7 ) ;
V_6 -> V_7 = NULL ;
V_6 -> V_8 = NULL ;
}
static int F_4 ( struct V_9 * V_3 ,
struct V_5 * V_6 ,
struct V_1 * * V_2 )
{
* V_2 = F_5 ( sizeof( struct V_1 ) , V_10 ) ;
if ( * V_2 == NULL )
return - V_11 ;
( * V_2 ) -> V_3 = V_3 ;
( * V_2 ) -> V_6 = V_6 ;
V_6 -> V_7 = * V_2 ;
V_6 -> V_8 = F_3 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_3 = V_2 -> V_3 ;
struct V_12 * V_12 = V_3 -> V_12 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_7 ( V_6 -> V_13 , L_1 , sizeof( V_6 -> V_13 ) ) ;
snprintf ( V_6 -> V_14 , sizeof( V_6 -> V_14 ) , L_2 ,
V_12 -> V_15 , V_3 -> V_16 ) ;
snprintf ( V_6 -> V_17 , sizeof( V_6 -> V_17 ) ,
L_3 ,
V_12 -> V_15 , V_3 -> V_16 ) ;
return 0 ;
}
int F_8 ( struct V_9 * V_3 )
{
struct V_12 * V_12 = V_3 -> V_12 ;
struct V_5 * V_6 = NULL ;
struct V_1 * V_2 ;
int V_18 ;
V_18 = F_9 ( & V_12 -> V_19 -> V_20 , V_21 ,
V_22 , V_23 , 0 , & V_6 ) ;
if ( V_18 ) {
F_10 ( L_4 , V_18 ) ;
goto V_24;
}
V_18 = F_4 ( V_3 , V_6 , & V_2 ) ;
if ( V_18 ) {
F_10 ( L_5 ,
V_18 ) ;
goto V_25;
}
F_6 ( V_2 ) ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 ) {
F_10 ( L_6 ,
V_18 ) ;
goto V_25;
}
V_3 -> V_4 = V_2 ;
V_18 = F_12 ( V_6 ) ;
if ( V_18 ) {
V_3 -> V_4 = NULL ;
F_10 ( L_7 , V_18 ) ;
goto V_25;
}
return 0 ;
V_25:
if ( V_6 != NULL )
F_13 ( V_6 ) ;
F_2 ( V_2 ) ;
V_24:
return V_18 ;
}
void F_14 ( struct V_9 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_4 ;
if ( V_2 )
F_13 ( V_2 -> V_6 ) ;
V_3 -> V_4 = NULL ;
}
