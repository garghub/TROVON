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
F_6 ( & V_5 -> V_10 ) ;
V_9 = F_7 ( V_5 -> V_11 ,
V_5 -> V_12 ,
V_5 -> V_6 ,
V_5 -> V_13 . V_14 ) ;
if ( V_9 ) {
F_5 ( L_2 , V_9 ) ;
goto V_15;
}
V_1 = F_8 ( V_5 -> V_6 [ V_5 -> V_12 - 1 ] . V_1 ) ;
V_15:
if ( V_5 -> V_16 )
V_5 -> V_16 ( V_5 ) ;
F_9 ( & V_5 -> V_10 ) ;
F_10 ( & V_5 -> V_13 . V_17 -> V_13 ) ;
F_11 ( V_5 ) ;
return V_1 ? & V_1 -> V_13 : NULL ;
}
int F_12 ( struct V_18 * V_11 ,
struct V_19 * V_20 ,
struct V_21 * V_6 ,
unsigned V_12 ,
int (* V_16)( struct V_4 * ) ,
void * V_14 ,
struct V_1 * * V_22 )
{
int V_9 = 0 ;
if ( V_23 ) {
struct V_4 * V_5 =
F_13 ( sizeof( struct V_4 ) , V_24 ) ;
if ( ! V_5 )
return - V_25 ;
V_5 -> V_13 . V_26 = & V_20 -> V_26 ;
V_5 -> V_13 . V_27 = & V_11 -> V_28 . V_29 [ V_20 -> V_30 ] . V_31 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_13 . V_14 = V_14 ;
F_14 ( & V_5 -> V_10 ) ;
V_5 -> V_16 = V_16 ;
F_6 ( & V_5 -> V_10 ) ;
V_9 = F_15 ( & V_5 -> V_13 ) ;
if ( V_9 ) {
F_9 ( & V_5 -> V_10 ) ;
F_11 ( V_5 ) ;
return V_9 ;
}
* V_22 = F_16 ( & V_5 -> V_13 . V_17 -> V_13 ) ;
F_9 ( & V_5 -> V_10 ) ;
} else {
V_9 = F_7 ( V_11 , V_12 , V_6 , V_14 ) ;
if ( V_9 )
return V_9 ;
* V_22 = F_16 ( & V_6 [ V_12 - 1 ] . V_1 -> V_13 ) ;
}
return 0 ;
}
