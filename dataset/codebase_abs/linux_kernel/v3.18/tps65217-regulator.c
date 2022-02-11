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
static int F_8 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_9 ( V_22 -> V_2 . V_23 ) ;
struct V_24 * V_25 = F_10 ( V_4 -> V_2 ) ;
struct V_1 * V_26 ;
struct V_27 V_28 = { } ;
int V_29 ;
if ( F_11 ( V_4 ) != V_30 ) {
F_12 ( & V_22 -> V_2 , L_1 ) ;
return - V_31 ;
}
F_13 ( V_22 , V_4 ) ;
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
V_28 . V_2 = V_4 -> V_2 ;
if ( V_25 )
V_28 . V_33 = V_25 -> V_34 [ V_29 ] ;
V_28 . V_35 = V_4 ;
V_28 . V_36 = V_4 -> V_36 ;
V_26 = F_14 ( & V_22 -> V_2 , & V_37 [ V_29 ] ,
& V_28 ) ;
if ( F_15 ( V_26 ) ) {
F_12 ( V_4 -> V_2 , L_2 ,
V_22 -> V_38 ) ;
return F_16 ( V_26 ) ;
}
}
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_39 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_39 ) ;
}
