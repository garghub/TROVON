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
int V_9 ;
if ( F_4 ( V_2 , V_3 , V_4 ,
V_5 , & V_8 ) )
return - V_10 ;
V_7 . V_11 = V_2 -> V_12 ;
V_7 . V_13 = V_3 [ V_8 ] . V_14 ;
if ( V_7 . V_11 == V_7 . V_13 )
return 0 ;
F_5 ( V_2 , & V_7 , V_15 ) ;
V_9 = F_6 ( V_16 , V_7 . V_13 * 1000 ) ;
if ( V_9 ) {
F_7 ( L_1 ,
V_7 . V_13 * 1000 , V_9 ) ;
V_7 . V_13 = V_7 . V_11 ;
}
F_5 ( V_2 , & V_7 , V_17 ) ;
return V_9 ;
}
static unsigned int F_8 ( unsigned int V_18 )
{
int V_19 = 0 ;
unsigned long V_20 = F_9 ( V_16 ) / 1000 ;
while ( V_3 [ V_19 + 1 ] . V_14 != V_21 ) {
if ( V_20 < V_3 [ V_19 ] . V_14 +
( V_3 [ V_19 + 1 ] . V_14 - V_3 [ V_19 ] . V_14 ) / 2 )
return V_3 [ V_19 ] . V_14 ;
V_19 ++ ;
}
return V_3 [ V_19 ] . V_14 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_11 ( V_2 , V_3 ) ;
if ( ! V_22 )
F_12 ( V_3 , V_2 -> V_18 ) ;
else {
F_7 ( L_2 ) ;
return V_22 ;
}
V_2 -> V_23 = V_2 -> V_24 . V_25 ;
V_2 -> V_26 = V_2 -> V_24 . V_27 ;
V_2 -> V_12 = F_8 ( V_2 -> V_18 ) ;
V_2 -> V_28 = V_29 ;
V_2 -> V_24 . V_30 = 20 * 1000 ;
F_13 ( V_2 -> V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_32 * V_33 )
{
int V_19 = 0 ;
V_3 = F_15 ( & V_33 -> V_34 ) ;
if ( ! V_3 ) {
F_7 ( L_3 ) ;
return - V_35 ;
}
V_16 = F_16 ( & V_33 -> V_34 , L_4 ) ;
if ( F_17 ( V_16 ) ) {
F_7 ( L_5 ) ;
return F_18 ( V_16 ) ;
}
F_19 ( L_6 ) ;
while ( V_3 [ V_19 ] . V_14 != V_21 ) {
F_19 ( L_7 , V_3 [ V_19 ] . V_14 / 1000 ) ;
V_19 ++ ;
}
return F_20 ( & V_36 ) ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_37 ) ;
}
