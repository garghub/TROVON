int F_1 ( struct V_1 * V_2 , char * V_3 )
{
static char * V_4 [] = { L_1 ,
L_2 ,
L_3 ,
NULL
} ;
char * V_5 [] = {
V_6 ,
V_2 -> V_7 ,
V_3 ,
NULL
} ;
int V_8 = - V_9 ;
if ( V_6 [ 0 ] == '\0' )
goto V_10;
V_8 = F_2 ( V_5 [ 0 ] , V_5 , V_4 , V_11 ) ;
if ( V_8 == - V_12 || V_8 == - V_9 )
V_6 [ 0 ] = '\0' ;
V_10:
return V_8 > 0 ? 0 : V_8 ;
}
void F_3 ( struct V_13 * V_14 )
{
if ( F_4 ( & V_14 -> V_15 ) )
F_5 ( V_14 ) ;
}
static void F_6 ( struct V_16 * V_17 , int V_18 )
{
struct V_13 * V_14 ;
V_14 = F_7 ( V_17 , struct V_13 , V_19 ) ;
F_8 ( & V_14 -> V_20 ) ;
F_3 ( V_14 ) ;
}
static struct V_16 * F_9 ( struct V_21 * V_22 )
{
struct V_13 * V_14 ;
V_14 = F_7 ( V_22 , struct V_13 , V_22 ) ;
V_14 -> V_19 . V_23 = F_6 ;
F_10 ( & V_14 -> V_15 ) ;
return & V_14 -> V_19 ;
}
struct V_13 * F_11 ( void )
{
struct V_13 * V_14 ;
V_14 = F_12 ( sizeof( * V_14 ) , V_24 ) ;
if ( V_14 ) {
F_13 ( & V_14 -> V_20 ) ;
F_14 ( & V_14 -> V_15 , 1 ) ;
V_14 -> V_22 . V_25 = F_9 ;
}
return V_14 ;
}
int F_15 ( struct V_13 * V_14 )
{
if ( F_16 ( & V_14 -> V_20 ,
V_26 * V_27 ) == 0 )
return - V_28 ;
return 0 ;
}
int F_17 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
int V_8 ;
struct V_31 * V_32 ;
V_32 = F_18 ( V_30 , L_4 ) ;
V_8 = F_19 ( V_32 , V_2 -> V_7 , 0600 , V_2 ) ;
F_20 ( V_32 ) ;
return V_8 ;
}
int F_21 ( struct V_33 * V_33 , struct V_1 * V_2 )
{
struct V_29 * V_34 ;
int V_8 = 0 ;
V_34 = F_22 ( V_33 ) ;
if ( V_34 ) {
V_8 = F_17 ( V_34 , V_2 ) ;
F_23 ( V_33 ) ;
}
return V_8 ;
}
void F_24 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
if ( V_2 -> V_35 . V_36 . V_32 )
F_25 ( V_2 ) ;
}
void F_26 ( struct V_33 * V_33 , struct V_1 * V_2 )
{
struct V_29 * V_34 ;
V_34 = F_22 ( V_33 ) ;
if ( V_34 ) {
F_24 ( V_34 , V_2 ) ;
F_23 ( V_33 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
}
