static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
T_2 V_8 ;
T_2 V_9 = V_3 << ( 8 + 1 ) ;
int V_10 = ( V_6 == NULL || V_7 == 0 ) ;
T_1 V_11 , type ;
if ( V_10 ) {
V_11 = V_12 ;
type = V_13 ;
} else {
V_11 = V_14 ;
type = V_15 ;
}
switch ( V_5 ) {
case 1 :
V_8 = V_4 [ 0 ] ;
break;
case 2 :
V_8 = V_4 [ 0 ] ;
V_9 = V_9 + V_4 [ 1 ] ;
break;
default:
F_2 ( L_1 , V_5 ) ;
return - V_16 ;
}
F_3 ( 1 ) ;
return F_4 ( V_2 -> V_17 , F_5 ( V_2 -> V_17 , 0 ) , V_11 , type ,
V_9 , V_8 , V_6 , V_7 , 2000 ) ;
}
static int F_6 ( struct V_18 * V_19 , struct V_20 V_21 [] ,
int V_22 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_23 ;
if ( V_22 > 2 )
return - V_16 ;
if ( F_8 ( & V_2 -> V_24 ) < 0 )
return - V_25 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
if ( V_23 + 1 < V_22 && ( V_21 [ V_23 + 1 ] . V_26 & V_27 ) ) {
if ( F_1 ( V_2 , V_21 [ V_23 ] . V_3 , V_21 [ V_23 ] . V_28 ,
V_21 [ V_23 ] . V_29 , V_21 [ V_23 + 1 ] . V_28 , V_21 [ V_23 + 1 ] . V_29 ) < 0 )
break;
V_23 ++ ;
} else
if ( F_1 ( V_2 , V_21 [ V_23 ] . V_3 , V_21 [ V_23 ] . V_28 ,
V_21 [ V_23 ] . V_29 , NULL , 0 ) < 0 )
break;
}
F_9 ( & V_2 -> V_24 ) ;
return V_23 ;
}
static T_3 F_10 ( struct V_18 * V_30 )
{
return V_31 ;
}
static int F_11 ( struct V_32 * V_19 )
{
V_19 -> V_33 = F_12 ( V_34 , & V_35 ,
& V_19 -> V_36 -> V_37 ) ;
if ( V_19 -> V_33 == NULL )
return - V_38 ;
return 0 ;
}
static int F_13 ( struct V_32 * V_19 )
{
return F_12 ( V_39 ,
V_19 -> V_33 , & V_19 -> V_36 -> V_37 ,
& V_40 ) == NULL ? - V_41 : 0 ;
}
static int F_14 ( struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
int V_48 ;
if ( V_43 -> V_49 < 2 )
return - V_41 ;
V_48 = F_15 ( V_43 , & V_50 , V_51 , & V_2 ,
V_52 ) ;
if ( V_48 == 0 ) {
V_47 = F_16 ( V_43 , 0 ) ;
if ( V_47 == NULL ) {
F_17 ( L_2 ) ;
return - V_41 ;
}
V_48 = F_18 ( V_2 -> V_17 , V_47 -> V_53 . V_54 ,
V_47 -> V_53 . V_55 ) ;
}
return V_48 ;
}
static int T_4 F_19 ( void )
{
int V_48 ;
V_48 = F_20 ( & V_56 ) ;
if ( V_48 )
F_21 ( L_3 , V_48 ) ;
return V_48 ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_56 ) ;
}
