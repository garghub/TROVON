static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_4 ,
unsigned int V_5 )
{
struct V_6 V_7 ;
unsigned int V_8 ;
if ( V_4 < V_2 -> V_9 . V_10 )
V_4 = V_2 -> V_9 . V_10 ;
if ( V_4 > V_2 -> V_9 . V_11 )
V_4 = V_2 -> V_9 . V_11 ;
if ( F_4
( V_2 , V_3 , V_4 , V_5 , & V_8 ) ) {
return - V_12 ;
}
V_7 . V_13 = V_2 -> V_14 ;
V_7 . V_15 = V_3 [ V_8 ] . V_16 ;
V_7 . V_17 = V_2 -> V_17 ;
if ( V_7 . V_13 == V_7 . V_15 )
return 0 ;
F_5 ( & V_7 , V_18 ) ;
if ( F_6 ( V_19 [ V_8 ] ) ) {
F_7 ( L_1 ) ;
return - V_12 ;
}
F_5 ( & V_7 , V_20 ) ;
return 0 ;
}
static unsigned int F_8 ( unsigned int V_17 )
{
int V_21 ;
for ( V_21 = 0 ; F_9 () != V_19 [ V_21 ] ; V_21 ++ )
;
return V_3 [ V_21 ] . V_16 ;
}
static int T_1 F_10 ( struct V_1 * V_2 )
{
int V_22 ;
int V_21 ;
F_11 ( F_12 ( V_19 ) + 1 != F_12 ( V_3 ) ) ;
if ( F_13 () && ! F_14 () ) {
V_3 [ 0 ] . V_16 = 400000 ;
V_3 [ 1 ] . V_16 = 800000 ;
if ( F_15 () )
V_3 [ 2 ] . V_16 = 1000000 ;
}
V_22 = F_16 ( V_2 , V_3 ) ;
if ( ! V_22 )
F_17 ( V_3 , V_2 -> V_17 ) ;
else {
F_7 ( L_2 ) ;
return V_22 ;
}
V_2 -> V_23 = V_2 -> V_9 . V_10 ;
V_2 -> V_24 = V_2 -> V_9 . V_11 ;
V_2 -> V_14 = F_8 ( V_2 -> V_17 ) ;
for ( V_21 = 0 ; V_3 [ V_21 ] . V_16 != V_2 -> V_14 ; V_21 ++ )
;
V_2 -> V_25 = V_26 ;
V_2 -> V_9 . V_27 = 20 * 1000 ;
F_18 ( V_2 -> V_28 , & V_29 ) ;
V_2 -> V_30 = V_31 ;
return 0 ;
}
static int T_2 F_19 ( void )
{
if ( ! F_20 () )
return - V_32 ;
F_21 ( L_3 ) ;
return F_22 ( & V_33 ) ;
}
