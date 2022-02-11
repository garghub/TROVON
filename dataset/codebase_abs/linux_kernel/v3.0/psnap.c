static struct V_1 * F_1 ( const unsigned char * V_2 )
{
struct V_1 * V_3 = NULL , * V_4 ;
F_2 (p, &snap_list, node) {
if ( ! memcmp ( V_4 -> type , V_2 , 5 ) ) {
V_3 = V_4 ;
break;
}
}
return V_3 ;
}
static int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_7 * V_11 )
{
int V_12 = 1 ;
struct V_1 * V_3 ;
static struct V_9 V_13 = {
. type = F_4 ( V_14 ) ,
} ;
if ( F_5 ( ! F_6 ( V_6 , 5 ) ) )
goto V_15;
F_7 () ;
V_3 = F_1 ( F_8 ( V_6 ) ) ;
if ( V_3 ) {
V_6 -> V_16 += 5 ;
F_9 ( V_6 , 5 ) ;
V_12 = V_3 -> V_17 ( V_6 , V_8 , & V_13 , V_11 ) ;
}
F_10 () ;
if ( F_5 ( ! V_3 ) )
goto V_15;
V_18:
return V_12 ;
V_15:
F_11 ( V_6 ) ;
goto V_18;
}
static int F_12 ( struct V_1 * V_19 ,
struct V_5 * V_6 , T_1 * V_20 )
{
memcpy ( F_13 ( V_6 , 5 ) , V_19 -> type , 5 ) ;
F_14 ( V_21 , V_6 , V_20 , V_21 -> V_22 . V_23 ) ;
return 0 ;
}
static int T_2 F_15 ( void )
{
V_21 = F_16 ( 0xAA , F_3 ) ;
if ( ! V_21 ) {
F_17 ( V_24 ) ;
return - V_25 ;
}
return 0 ;
}
static void T_3 F_18 ( void )
{
F_19 ( V_21 ) ;
}
struct V_1 * F_20 ( const unsigned char * V_2 ,
int (* V_17)( struct V_5 * ,
struct V_7 * ,
struct V_9 * ,
struct V_7 * ) )
{
struct V_1 * V_3 = NULL ;
F_21 ( & V_26 ) ;
if ( F_1 ( V_2 ) )
goto V_18;
V_3 = F_22 ( sizeof( * V_3 ) , V_27 ) ;
if ( V_3 ) {
memcpy ( V_3 -> type , V_2 , 5 ) ;
V_3 -> V_17 = V_17 ;
V_3 -> V_28 = 5 + 3 ;
V_3 -> V_29 = F_12 ;
F_23 ( & V_3 -> V_30 , & V_31 ) ;
}
V_18:
F_24 ( & V_26 ) ;
return V_3 ;
}
void F_25 ( struct V_1 * V_3 )
{
F_21 ( & V_26 ) ;
F_26 ( & V_3 -> V_30 ) ;
F_24 ( & V_26 ) ;
F_27 () ;
F_28 ( V_3 ) ;
}
