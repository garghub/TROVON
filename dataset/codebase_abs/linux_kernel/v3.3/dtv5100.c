static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
T_1 V_8 ;
T_1 type ;
T_2 V_9 ;
T_2 V_10 ;
switch ( V_5 ) {
case 1 :
V_8 = ( V_3 == V_11 ? V_12 :
V_13 ) ;
type = V_14 | V_15 ;
V_9 = 0 ;
break;
case 2 :
V_8 = ( V_3 == V_11 ? V_16 :
V_17 ) ;
type = V_14 | V_18 ;
V_9 = V_4 [ 1 ] ;
break;
default:
F_2 ( L_1 , V_5 ) ;
return - V_19 ;
}
V_10 = ( V_3 << 8 ) + V_4 [ 0 ] ;
F_3 ( 1 ) ;
return F_4 ( V_2 -> V_20 , F_5 ( V_2 -> V_20 , 0 ) , V_8 ,
type , V_9 , V_10 , V_6 , V_7 ,
V_21 ) ;
}
static int F_6 ( struct V_22 * V_23 , struct V_24 V_25 [] ,
int V_26 )
{
struct V_1 * V_2 = F_7 ( V_23 ) ;
int V_27 ;
if ( V_26 > 2 )
return - V_19 ;
if ( F_8 ( & V_2 -> V_28 ) < 0 )
return - V_29 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
if ( V_27 + 1 < V_26 && ( V_25 [ V_27 + 1 ] . V_30 & V_31 ) ) {
if ( F_1 ( V_2 , V_25 [ V_27 ] . V_3 , V_25 [ V_27 ] . V_32 ,
V_25 [ V_27 ] . V_33 , V_25 [ V_27 + 1 ] . V_32 ,
V_25 [ V_27 + 1 ] . V_33 ) < 0 )
break;
V_27 ++ ;
} else if ( F_1 ( V_2 , V_25 [ V_27 ] . V_3 , V_25 [ V_27 ] . V_32 ,
V_25 [ V_27 ] . V_33 , NULL , 0 ) < 0 )
break;
}
F_9 ( & V_2 -> V_28 ) ;
return V_27 ;
}
static T_3 F_10 ( struct V_22 * V_34 )
{
return V_35 ;
}
static int F_11 ( struct V_36 * V_23 )
{
V_23 -> V_37 [ 0 ] . V_38 = F_12 ( V_39 , & V_40 ,
& V_23 -> V_41 -> V_42 ) ;
if ( V_23 -> V_37 [ 0 ] . V_38 == NULL )
return - V_43 ;
V_23 -> V_37 [ 0 ] . V_38 -> V_44 . V_45 = NULL ;
return 0 ;
}
static int F_13 ( struct V_36 * V_23 )
{
return F_12 ( V_46 ,
V_23 -> V_37 [ 0 ] . V_38 , & V_23 -> V_41 -> V_42 ,
& V_47 ) == NULL ? - V_48 : 0 ;
}
static int F_14 ( struct V_49 * V_50 ,
const struct V_51 * V_52 )
{
int V_27 , V_53 ;
struct V_54 * V_20 = F_15 ( V_50 ) ;
for ( V_27 = 0 ; V_55 [ V_27 ] . V_8 ; V_27 ++ ) {
V_53 = F_4 ( V_20 , F_5 ( V_20 , 0 ) ,
V_55 [ V_27 ] . V_8 ,
V_14 | V_18 ,
V_55 [ V_27 ] . V_9 ,
V_55 [ V_27 ] . V_10 , NULL , 0 ,
V_21 ) ;
if ( V_53 )
return V_53 ;
}
V_53 = F_16 ( V_50 , & V_56 ,
V_57 , NULL , V_58 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
