static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , const void * V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return V_5 -> V_6 ( V_4 , V_5 -> V_7 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_5 ( V_5 -> V_3 . V_8 ) ;
F_5 ( V_5 ) ;
}
struct V_1 * F_6 ( struct V_9 * V_10 ,
int (* V_6)( const void * V_4 ,
void * V_7 ) ,
void * V_7 )
{
int V_11 ;
struct V_1 * V_5 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_5 = F_7 ( sizeof( * V_5 ) , V_16 ) ;
if ( V_5 == NULL ) {
V_11 = - V_17 ;
goto V_18;
}
F_8 ( & V_5 -> V_3 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_3 . V_19 = & V_20 ;
F_9 ( & V_5 -> V_3 . V_21 ) ;
V_5 -> V_22 = F_10 ( V_10 ) ;
if ( F_11 ( V_5 -> V_22 ) ) {
V_11 = F_12 ( V_5 -> V_22 ) ;
goto V_23;
}
V_13 = V_5 -> V_22 [ 0 ] . V_13 ;
V_5 -> V_3 . V_8
= F_13 ( F_14 ( V_13 -> V_24 ) , sizeof( long ) ,
V_16 ) ;
if ( V_5 -> V_3 . V_8 == NULL ) {
V_11 = - V_17 ;
goto V_25;
}
V_15 = & V_5 -> V_22 [ 0 ] ;
while ( V_15 -> V_13 ) {
if ( V_15 -> V_13 != V_13 ) {
V_11 = - V_26 ;
goto V_27;
}
F_15 ( V_15 -> V_28 -> V_29 ,
V_5 -> V_3 . V_8 ) ;
V_15 ++ ;
}
return V_5 ;
V_27:
F_5 ( V_5 -> V_3 . V_8 ) ;
V_25:
F_16 ( V_5 -> V_22 ) ;
V_23:
F_5 ( V_5 ) ;
V_18:
return F_17 ( V_11 ) ;
}
int F_18 ( struct V_1 * V_5 )
{
return F_19 ( V_5 -> V_22 [ 0 ] . V_13 ,
& V_5 -> V_3 ,
NULL ) ;
}
void F_20 ( struct V_1 * V_5 )
{
F_19 ( V_5 -> V_22 [ 0 ] . V_13 ,
NULL ,
& V_5 -> V_3 ) ;
}
void F_21 ( struct V_1 * V_5 )
{
F_16 ( V_5 -> V_22 ) ;
F_22 ( & V_5 -> V_3 ) ;
}
struct V_14
* F_23 ( const struct V_1 * V_30 )
{
return V_30 -> V_22 ;
}
