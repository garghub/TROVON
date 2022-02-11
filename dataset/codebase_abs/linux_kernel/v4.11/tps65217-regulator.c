static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
return F_4 ( V_4 , V_9 ,
V_2 -> V_10 -> V_11 , V_2 -> V_10 -> V_11 ,
V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
return F_6 ( V_4 , V_9 ,
V_2 -> V_10 -> V_11 , V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_13 )
{
int V_14 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_2 ) ;
V_14 = F_4 ( V_4 , V_2 -> V_10 -> V_15 , V_2 -> V_10 -> V_16 ,
V_13 , V_17 ) ;
switch ( V_5 ) {
case V_6 ... V_18 :
V_14 = F_4 ( V_4 , V_19 ,
V_20 , V_20 ,
V_17 ) ;
break;
}
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
return F_6 ( V_4 , V_2 -> V_10 -> V_21 ,
V_2 -> V_10 -> V_22 ,
V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
if ( ! V_4 -> V_23 [ V_5 ] )
return - V_8 ;
return F_4 ( V_4 , V_2 -> V_10 -> V_21 ,
V_2 -> V_10 -> V_22 ,
V_4 -> V_23 [ V_5 ] , V_12 ) ;
}
static int F_10 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = F_11 ( V_25 -> V_2 . V_26 ) ;
struct V_27 * V_28 = F_12 ( V_4 -> V_2 ) ;
struct V_1 * V_29 ;
struct V_30 V_31 = { } ;
int V_32 , V_14 ;
unsigned int V_33 ;
if ( F_13 ( V_4 ) != V_34 ) {
F_14 ( & V_25 -> V_2 , L_1 ) ;
return - V_35 ;
}
V_4 -> V_23 = F_15 ( & V_25 -> V_2 , sizeof( V_36 ) *
V_37 , V_38 ) ;
F_16 ( V_25 , V_4 ) ;
for ( V_32 = 0 ; V_32 < V_37 ; V_32 ++ ) {
V_31 . V_2 = V_4 -> V_2 ;
if ( V_28 )
V_31 . V_39 = V_28 -> V_40 [ V_32 ] ;
V_31 . V_41 = V_4 ;
V_31 . V_42 = V_4 -> V_42 ;
V_29 = F_17 ( & V_25 -> V_2 , & V_43 [ V_32 ] ,
& V_31 ) ;
if ( F_18 ( V_29 ) ) {
F_14 ( V_4 -> V_2 , L_2 ,
V_25 -> V_44 ) ;
return F_19 ( V_29 ) ;
}
V_14 = F_20 ( V_4 , V_43 [ V_32 ] . V_21 , & V_33 ) ;
V_4 -> V_23 [ V_32 ] = V_33 & V_43 [ V_32 ] . V_22 ;
}
return 0 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_45 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_45 ) ;
}
