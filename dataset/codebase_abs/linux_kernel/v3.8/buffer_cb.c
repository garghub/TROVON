static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ,
struct V_4 ,
V_2 ) ;
return V_5 -> V_6 ( V_3 , V_5 -> V_7 ) ;
}
struct V_4 * F_3 ( const char * V_8 ,
int (* V_6)( T_1 * V_3 ,
void * V_7 ) ,
void * V_7 )
{
int V_9 ;
struct V_4 * V_5 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_5 = F_4 ( sizeof( * V_5 ) , V_14 ) ;
if ( V_5 == NULL ) {
V_9 = - V_15 ;
goto V_16;
}
V_5 -> V_7 = V_7 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_2 . V_17 = & V_18 ;
F_5 ( & V_5 -> V_2 . V_19 ) ;
V_5 -> V_20 = F_6 ( V_8 ) ;
if ( F_7 ( V_5 -> V_20 ) ) {
V_9 = F_8 ( V_5 -> V_20 ) ;
goto V_21;
}
V_11 = V_5 -> V_20 [ 0 ] . V_11 ;
V_5 -> V_2 . V_22
= F_9 ( F_10 ( V_11 -> V_23 ) , sizeof( long ) ,
V_14 ) ;
if ( V_5 -> V_2 . V_22 == NULL ) {
V_9 = - V_15 ;
goto V_24;
}
V_13 = & V_5 -> V_20 [ 0 ] ;
while ( V_13 -> V_11 ) {
if ( V_13 -> V_11 != V_11 ) {
V_9 = - V_25 ;
goto V_24;
}
F_11 ( V_13 -> V_26 -> V_27 ,
V_5 -> V_2 . V_22 ) ;
V_13 ++ ;
}
return V_5 ;
V_24:
F_12 ( V_5 -> V_20 ) ;
V_21:
F_13 ( V_5 ) ;
V_16:
return F_14 ( V_9 ) ;
}
int F_15 ( struct V_4 * V_5 )
{
return F_16 ( V_5 -> V_20 [ 0 ] . V_11 ,
& V_5 -> V_2 ,
NULL ) ;
}
void F_17 ( struct V_4 * V_5 )
{
F_16 ( V_5 -> V_20 [ 0 ] . V_11 ,
NULL ,
& V_5 -> V_2 ) ;
}
void F_18 ( struct V_4 * V_5 )
{
F_12 ( V_5 -> V_20 ) ;
F_13 ( V_5 ) ;
}
struct V_12
* F_19 ( const struct V_4 * V_28 )
{
return V_28 -> V_20 ;
}
