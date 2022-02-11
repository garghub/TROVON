static
struct V_1 * F_1 ( const char * V_2 ,
unsigned V_3 )
{
struct V_1 * V_4 = NULL , * V_5 ;
F_2 (iter, &iio_trigger_types_list, list)
if ( ! strcmp ( V_5 -> V_2 , V_2 ) ) {
V_4 = V_5 ;
break;
}
return V_4 ;
}
int F_3 ( struct V_1 * V_4 )
{
struct V_1 * V_5 ;
int V_6 = 0 ;
F_4 ( & V_7 ) ;
V_5 = F_1 ( V_4 -> V_2 , strlen ( V_4 -> V_2 ) ) ;
if ( V_5 )
V_6 = - V_8 ;
else
F_5 ( & V_4 -> V_9 , & V_10 ) ;
F_6 ( & V_7 ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_11 = F_7 ( V_12 , V_4 -> V_2 ,
& V_13 ) ;
if ( F_8 ( V_4 -> V_11 ) )
V_6 = F_9 ( V_4 -> V_11 ) ;
return V_6 ;
}
void F_10 ( struct V_1 * V_4 )
{
struct V_1 * V_5 ;
F_4 ( & V_7 ) ;
V_5 = F_1 ( V_4 -> V_2 , strlen ( V_4 -> V_2 ) ) ;
if ( V_5 )
F_11 ( & V_4 -> V_9 ) ;
F_6 ( & V_7 ) ;
F_12 ( V_4 -> V_11 ) ;
}
static
struct V_1 * F_13 ( const char * V_2 )
{
struct V_1 * V_4 ;
F_4 ( & V_7 ) ;
V_4 = F_1 ( V_2 , strlen ( V_2 ) ) ;
if ( V_4 && ! F_14 ( V_4 -> V_14 ) )
V_4 = NULL ;
F_6 ( & V_7 ) ;
return V_4 ;
}
struct V_15 * F_15 ( const char * type , const char * V_2 )
{
struct V_15 * V_4 ;
struct V_1 * V_16 ;
V_16 = F_13 ( type ) ;
if ( ! V_16 ) {
F_16 ( L_1 , type ) ;
return F_17 ( - V_17 ) ;
}
V_4 = V_16 -> V_18 -> V_19 ( V_2 ) ;
if ( F_8 ( V_4 ) )
goto V_20;
V_4 -> V_21 = V_16 ;
return V_4 ;
V_20:
F_18 ( V_16 -> V_14 ) ;
return V_4 ;
}
void F_19 ( struct V_15 * V_4 )
{
struct V_1 * V_16 = V_4 -> V_21 ;
V_16 -> V_18 -> remove ( V_4 ) ;
F_18 ( V_16 -> V_14 ) ;
}
static struct V_22 * F_20 ( struct V_22 * V_11 ,
const char * V_2 )
{
struct V_15 * V_4 ;
V_4 = F_15 ( V_11 -> V_23 . V_24 , V_2 ) ;
if ( F_8 ( V_4 ) )
return F_21 ( V_4 ) ;
F_22 ( & V_4 -> V_11 . V_23 , L_2 , V_2 ) ;
return & V_4 -> V_11 ;
}
static void F_23 ( struct V_22 * V_11 ,
struct V_25 * V_26 )
{
struct V_15 * V_4 = F_24 ( V_26 ) ;
F_19 ( V_4 ) ;
F_25 ( V_26 ) ;
}
static int T_1 F_26 ( void )
{
V_12 =
F_7 ( & V_27 . V_28 ,
L_3 ,
& V_29 ) ;
return F_27 ( V_12 ) ;
}
static void T_2 F_28 ( void )
{
F_12 ( V_12 ) ;
}
