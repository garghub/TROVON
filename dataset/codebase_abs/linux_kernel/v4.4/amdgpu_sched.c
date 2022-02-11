static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( & V_5 -> V_6 -> V_7 ) ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 )
{
struct V_8 * V_1 = NULL ;
struct V_4 * V_5 ;
int V_9 ;
if ( ! V_3 ) {
F_5 ( L_1 ) ;
return NULL ;
}
V_5 = F_2 ( V_3 ) ;
F_6 ( V_5 ) ;
V_9 = F_7 ( V_5 -> V_10 , V_5 -> V_11 , V_5 -> V_6 , V_5 -> V_12 ) ;
if ( V_9 ) {
F_5 ( L_2 , V_9 ) ;
goto V_13;
}
V_1 = V_5 -> V_6 [ V_5 -> V_11 - 1 ] . V_1 ;
F_8 ( & V_1 -> V_14 ) ;
V_13:
if ( V_5 -> V_15 )
V_5 -> V_15 ( V_5 ) ;
F_9 ( V_5 ) ;
return V_1 ? & V_1 -> V_14 : NULL ;
}
int F_10 ( struct V_16 * V_10 ,
struct V_17 * V_18 ,
struct V_19 * V_6 ,
unsigned V_11 ,
int (* V_15)( struct V_4 * ) ,
void * V_12 ,
struct V_1 * * V_20 )
{
int V_9 = 0 ;
if ( V_21 ) {
struct V_4 * V_5 =
F_11 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 )
return - V_23 ;
V_5 -> V_14 . V_24 = & V_18 -> V_24 ;
V_5 -> V_14 . V_25 = & V_10 -> V_26 . V_27 [ V_18 -> V_28 ] . V_29 ;
V_5 -> V_14 . V_30 = F_12 ( V_5 -> V_14 . V_25 , V_12 ) ;
if ( ! V_5 -> V_14 . V_30 ) {
F_9 ( V_5 ) ;
return - V_23 ;
}
* V_20 = F_8 ( & V_5 -> V_14 . V_30 -> V_14 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_15 = V_15 ;
F_13 ( & V_5 -> V_14 ) ;
} else {
V_9 = F_7 ( V_10 , V_11 , V_6 , V_12 ) ;
if ( V_9 )
return V_9 ;
* V_20 = F_8 ( & V_6 [ V_11 - 1 ] . V_1 -> V_14 ) ;
}
return 0 ;
}
