static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
return V_5 -> V_6 ( V_3 , V_5 -> V_7 ) ;
}
struct V_4 * F_3 ( struct V_8 * V_9 ,
int (* V_6)( T_1 * V_3 ,
void * V_7 ) ,
void * V_7 )
{
int V_10 ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_5 = F_4 ( sizeof( * V_5 ) , V_15 ) ;
if ( V_5 == NULL ) {
V_10 = - V_16 ;
goto V_17;
}
V_5 -> V_7 = V_7 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_2 . V_18 = & V_19 ;
F_5 ( & V_5 -> V_2 . V_20 ) ;
V_5 -> V_21 = F_6 ( V_9 ) ;
if ( F_7 ( V_5 -> V_21 ) ) {
V_10 = F_8 ( V_5 -> V_21 ) ;
goto V_22;
}
V_12 = V_5 -> V_21 [ 0 ] . V_12 ;
V_5 -> V_2 . V_23
= F_9 ( F_10 ( V_12 -> V_24 ) , sizeof( long ) ,
V_15 ) ;
if ( V_5 -> V_2 . V_23 == NULL ) {
V_10 = - V_16 ;
goto V_25;
}
V_14 = & V_5 -> V_21 [ 0 ] ;
while ( V_14 -> V_12 ) {
if ( V_14 -> V_12 != V_12 ) {
V_10 = - V_26 ;
goto V_27;
}
F_11 ( V_14 -> V_28 -> V_29 ,
V_5 -> V_2 . V_23 ) ;
V_14 ++ ;
}
return V_5 ;
V_27:
F_12 ( V_5 -> V_2 . V_23 ) ;
V_25:
F_13 ( V_5 -> V_21 ) ;
V_22:
F_12 ( V_5 ) ;
V_17:
return F_14 ( V_10 ) ;
}
int F_15 ( struct V_4 * V_5 )
{
return F_16 ( V_5 -> V_21 [ 0 ] . V_12 ,
& V_5 -> V_2 ,
NULL ) ;
}
void F_17 ( struct V_4 * V_5 )
{
F_16 ( V_5 -> V_21 [ 0 ] . V_12 ,
NULL ,
& V_5 -> V_2 ) ;
}
void F_18 ( struct V_4 * V_5 )
{
F_12 ( V_5 -> V_2 . V_23 ) ;
F_13 ( V_5 -> V_21 ) ;
F_12 ( V_5 ) ;
}
struct V_13
* F_19 ( const struct V_4 * V_30 )
{
return V_30 -> V_21 ;
}
