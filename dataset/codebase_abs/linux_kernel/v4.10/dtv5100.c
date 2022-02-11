static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_2 V_5 , T_1 * V_6 , T_2 V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
T_1 V_11 ;
T_1 type ;
T_2 V_12 ;
T_2 V_13 ;
switch ( V_5 ) {
case 1 :
V_11 = ( V_3 == V_14 ? V_15 :
V_16 ) ;
type = V_17 | V_18 ;
V_12 = 0 ;
break;
case 2 :
V_11 = ( V_3 == V_14 ? V_19 :
V_20 ) ;
type = V_17 | V_21 ;
V_12 = V_4 [ 1 ] ;
break;
default:
F_2 ( L_1 , V_5 ) ;
return - V_22 ;
}
V_13 = ( V_3 << 8 ) + V_4 [ 0 ] ;
memcpy ( V_9 -> V_23 , V_6 , V_7 ) ;
F_3 ( 1 ) ;
return F_4 ( V_2 -> V_24 , F_5 ( V_2 -> V_24 , 0 ) , V_11 ,
type , V_12 , V_13 , V_9 -> V_23 , V_7 ,
V_25 ) ;
}
static int F_6 ( struct V_26 * V_27 , struct V_28 V_29 [] ,
int V_30 )
{
struct V_1 * V_2 = F_7 ( V_27 ) ;
int V_31 ;
if ( V_30 > 2 )
return - V_22 ;
if ( F_8 ( & V_2 -> V_32 ) < 0 )
return - V_33 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
if ( V_31 + 1 < V_30 && ( V_29 [ V_31 + 1 ] . V_34 & V_35 ) ) {
if ( F_1 ( V_2 , V_29 [ V_31 ] . V_3 , V_29 [ V_31 ] . V_36 ,
V_29 [ V_31 ] . V_37 , V_29 [ V_31 + 1 ] . V_36 ,
V_29 [ V_31 + 1 ] . V_37 ) < 0 )
break;
V_31 ++ ;
} else if ( F_1 ( V_2 , V_29 [ V_31 ] . V_3 , V_29 [ V_31 ] . V_36 ,
V_29 [ V_31 ] . V_37 , NULL , 0 ) < 0 )
break;
}
F_9 ( & V_2 -> V_32 ) ;
return V_31 ;
}
static T_3 F_10 ( struct V_26 * V_38 )
{
return V_39 ;
}
static int F_11 ( struct V_40 * V_27 )
{
V_27 -> V_41 [ 0 ] . V_42 = F_12 ( V_43 , & V_44 ,
& V_27 -> V_45 -> V_46 ) ;
if ( V_27 -> V_41 [ 0 ] . V_42 == NULL )
return - V_47 ;
V_27 -> V_41 [ 0 ] . V_42 -> V_48 . V_49 = NULL ;
return 0 ;
}
static int F_13 ( struct V_40 * V_27 )
{
return F_12 ( V_50 ,
V_27 -> V_41 [ 0 ] . V_42 , & V_27 -> V_45 -> V_46 ,
& V_51 ) == NULL ? - V_52 : 0 ;
}
static int F_14 ( struct V_53 * V_54 ,
const struct V_55 * V_56 )
{
int V_31 , V_57 ;
struct V_58 * V_24 = F_15 ( V_54 ) ;
for ( V_31 = 0 ; V_59 [ V_31 ] . V_11 ; V_31 ++ ) {
V_57 = F_4 ( V_24 , F_5 ( V_24 , 0 ) ,
V_59 [ V_31 ] . V_11 ,
V_17 | V_21 ,
V_59 [ V_31 ] . V_12 ,
V_59 [ V_31 ] . V_13 , NULL , 0 ,
V_25 ) ;
if ( V_57 )
return V_57 ;
}
V_57 = F_16 ( V_54 , & V_60 ,
V_61 , NULL , V_62 ) ;
if ( V_57 )
return V_57 ;
return 0 ;
}
