struct V_1 * F_1 (
struct V_2 * V_2 ,
T_1 V_3 ,
const struct V_4 * V_5 ,
char * V_6 ,
char * V_7 )
{
struct V_1 * V_8 ;
int V_9 ;
char * V_10 ;
V_8 = F_2 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_8 )
return F_3 ( - V_12 ) ;
strncpy ( V_8 -> V_6 , V_6 , V_13 ) ;
for ( V_10 = strchr ( V_8 -> V_6 , '/' ) ; V_10 ; V_10 = strchr ( V_10 , '/' ) )
* V_10 = '!' ;
strncpy ( V_8 -> V_7 , V_7 , V_13 ) ;
for ( V_10 = strchr ( V_8 -> V_7 , '/' ) ; V_10 ; V_10 = strchr ( V_10 , '/' ) )
* V_10 = '!' ;
V_8 -> V_14 = F_4 () ;
if ( ! V_8 -> V_14 ) {
V_9 = - V_12 ;
goto V_15;
}
V_8 -> V_14 -> V_16 = V_5 -> V_16 ;
V_8 -> V_14 -> V_17 = V_5 ;
V_8 -> V_14 -> V_3 = V_3 ;
V_9 = F_5 ( V_8 -> V_14 , V_8 -> V_14 -> V_3 , 1 ) ;
if ( V_9 )
goto V_18;
V_8 -> V_19 = F_6 ( V_20 , V_2 ,
V_8 -> V_14 -> V_3 , NULL ,
L_1 , V_8 -> V_6 ) ;
V_9 = F_7 ( V_8 -> V_19 ) ? F_8 ( V_8 -> V_19 ) : 0 ;
if ( V_9 )
goto V_18;
V_9 = F_9 (
& V_2 -> V_21 ,
& V_8 -> V_19 -> V_21 ,
V_8 -> V_7
) ;
if ( V_9 )
goto V_22;
return V_8 ;
V_22:
F_10 ( V_20 , V_8 -> V_14 -> V_3 ) ;
V_18:
F_11 ( V_8 -> V_14 ) ;
V_15:
F_12 ( V_8 ) ;
return F_3 ( V_9 ) ;
}
void F_13 ( struct V_2 * V_2 , struct V_1 * V_8 )
{
if ( V_8 != NULL && ! F_7 ( V_8 ) ) {
F_14 ( & V_2 -> V_21 , V_8 -> V_7 ) ;
F_10 ( V_20 , V_8 -> V_14 -> V_3 ) ;
F_11 ( V_8 -> V_14 ) ;
F_12 ( V_8 ) ;
}
}
static int T_2 F_15 ( void )
{
V_20 = F_16 ( V_23 , L_2 ) ;
return 0 ;
}
static void T_3 F_17 ( void )
{
F_18 ( V_20 ) ;
V_20 = NULL ;
}
