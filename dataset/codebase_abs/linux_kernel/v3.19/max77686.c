static unsigned int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 ... V_4 :
return 0 ;
case V_5 ... V_6 :
return V_7 ;
default:
return V_8 ;
}
}
static int F_2 ( struct V_9 * V_10 )
{
unsigned int V_11 , V_12 ;
struct V_13 * V_14 = F_3 ( V_10 ) ;
int V_15 , V_1 = F_4 ( V_10 ) ;
V_12 = F_1 ( V_1 ) ;
V_11 = V_16 ;
V_15 = F_5 ( V_10 -> V_17 , V_10 -> V_18 -> V_19 ,
V_10 -> V_18 -> V_20 , V_11 << V_12 ) ;
if ( V_15 )
return V_15 ;
V_14 -> V_21 [ V_1 ] = V_11 ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
unsigned int V_22 )
{
struct V_13 * V_14 = F_3 ( V_10 ) ;
unsigned int V_11 ;
int V_15 , V_1 = F_4 ( V_10 ) ;
if ( V_1 >= V_3 )
return 0 ;
switch ( V_22 ) {
case V_23 :
V_11 = V_24 ;
break;
case V_25 :
V_11 = V_26 ;
break;
default:
F_7 ( L_1 ,
V_10 -> V_18 -> V_27 , V_22 ) ;
return - V_28 ;
}
V_15 = F_5 ( V_10 -> V_17 , V_10 -> V_18 -> V_19 ,
V_10 -> V_18 -> V_20 ,
V_11 << V_8 ) ;
if ( V_15 )
return V_15 ;
V_14 -> V_21 [ V_1 ] = V_11 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
unsigned int V_22 )
{
unsigned int V_11 ;
struct V_13 * V_14 = F_3 ( V_10 ) ;
int V_15 ;
switch ( V_22 ) {
case V_29 :
V_11 = V_16 ;
break;
case V_23 :
V_11 = V_24 ;
break;
case V_25 :
V_11 = V_26 ;
break;
default:
F_7 ( L_1 ,
V_10 -> V_18 -> V_27 , V_22 ) ;
return - V_28 ;
}
V_15 = F_5 ( V_10 -> V_17 , V_10 -> V_18 -> V_19 ,
V_10 -> V_18 -> V_20 ,
V_11 << V_8 ) ;
if ( V_15 )
return V_15 ;
V_14 -> V_21 [ F_4 ( V_10 ) ] = V_11 ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_3 ( V_10 ) ;
unsigned int V_12 ;
int V_1 = F_4 ( V_10 ) ;
V_12 = F_1 ( V_1 ) ;
if ( V_14 -> V_21 [ V_1 ] == V_16 )
V_14 -> V_21 [ V_1 ] = V_26 ;
return F_5 ( V_10 -> V_17 , V_10 -> V_18 -> V_19 ,
V_10 -> V_18 -> V_20 ,
V_14 -> V_21 [ V_1 ] << V_12 ) ;
}
static int F_10 ( struct V_9 * V_10 , int V_30 )
{
unsigned int V_31 = V_32 ;
switch ( V_30 ) {
case 1 ... 13750 :
V_31 = V_33 ;
break;
case 13751 ... 27500 :
V_31 = V_34 ;
break;
case 27501 ... 55000 :
V_31 = V_35 ;
break;
case 55001 ... 100000 :
break;
default:
F_7 ( L_2 ,
V_10 -> V_18 -> V_27 , V_30 ) ;
}
return F_5 ( V_10 -> V_17 , V_10 -> V_18 -> V_19 ,
V_36 , V_31 << 6 ) ;
}
static int F_11 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_12 ( V_38 -> V_41 . V_42 ) ;
struct V_13 * V_14 ;
int V_43 ;
struct V_44 V_45 = { } ;
F_13 ( & V_38 -> V_41 , L_3 , V_46 ) ;
V_14 = F_14 ( & V_38 -> V_41 , sizeof( struct V_13 ) ,
V_47 ) ;
if ( ! V_14 )
return - V_48 ;
V_45 . V_41 = V_40 -> V_41 ;
V_45 . V_17 = V_40 -> V_17 ;
V_45 . V_49 = V_14 ;
F_15 ( V_38 , V_14 ) ;
for ( V_43 = 0 ; V_43 < V_50 ; V_43 ++ ) {
struct V_9 * V_10 ;
int V_1 = V_51 [ V_43 ] . V_1 ;
V_14 -> V_21 [ V_1 ] = V_26 ;
V_10 = F_16 ( & V_38 -> V_41 ,
& V_51 [ V_43 ] , & V_45 ) ;
if ( F_17 ( V_10 ) ) {
int V_15 = F_18 ( V_10 ) ;
F_19 ( & V_38 -> V_41 ,
L_4 , V_43 , V_15 ) ;
return V_15 ;
}
}
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_52 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_52 ) ;
}
