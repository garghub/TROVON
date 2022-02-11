static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
int V_9 ;
T_2 V_10 ;
T_1 * V_11 ;
V_11 = F_2 ( 6 , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
switch ( V_6 ) {
case 1 :
V_10 = V_5 [ 0 ] << 8 ;
break;
case 2 :
V_10 = V_5 [ 0 ] << 8 ;
V_10 += V_5 [ 1 ] ;
break;
default:
F_3 ( L_1 , V_6 ) ;
V_9 = - V_14 ;
goto error;
}
V_9 = F_4 ( V_2 -> V_15 , F_5 ( V_2 -> V_15 , 0 ) , V_3 ,
V_16 | V_17 , V_4 << 1 , V_10 ,
V_11 , 6 , V_18 ) ;
if ( V_9 < 0 )
goto error;
switch ( V_3 ) {
case V_19 :
case V_20 :
V_7 [ 0 ] = V_11 [ 4 ] ;
}
error:
F_6 ( V_11 ) ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_4 ,
T_1 * V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
T_1 V_21 ;
T_1 V_22 = ( V_7 == NULL || V_8 == 0 ) ;
if ( V_22 ) {
V_21 = V_23 ;
} else {
V_21 = V_19 ;
}
return F_1 ( V_2 , V_21 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_8 ( struct V_24 * V_25 , struct V_26 V_27 [] ,
int V_28 )
{
struct V_1 * V_2 = F_9 ( V_25 ) ;
int V_29 ;
if ( V_28 > 2 )
return - V_14 ;
if ( F_10 ( & V_2 -> V_30 ) < 0 )
return - V_31 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
if ( V_29 + 1 < V_28 && ( V_27 [ V_29 + 1 ] . V_32 & V_33 ) ) {
if ( F_7 ( V_2 , V_27 [ V_29 ] . V_4 , V_27 [ V_29 ] . V_34 ,
V_27 [ V_29 ] . V_35 , V_27 [ V_29 + 1 ] . V_34 ,
V_27 [ V_29 + 1 ] . V_35 ) < 0 )
break;
V_29 ++ ;
} else if ( F_7 ( V_2 , V_27 [ V_29 ] . V_4 , V_27 [ V_29 ] . V_34 ,
V_27 [ V_29 ] . V_35 , NULL , 0 ) < 0 )
break;
}
F_11 ( & V_2 -> V_30 ) ;
return V_29 ;
}
static T_3 F_12 ( struct V_24 * V_36 )
{
return V_37 ;
}
static int F_13 ( struct V_38 * V_25 )
{
V_25 -> V_39 = F_14 ( V_40 , & V_41 ,
& V_25 -> V_42 -> V_43 ) ;
if ( V_25 -> V_39 == NULL )
return - V_44 ;
return 0 ;
}
static int F_15 ( struct V_38 * V_25 )
{
return F_14 ( V_45 ,
V_25 -> V_39 , & V_25 -> V_42 -> V_43 ,
& V_46 ) == NULL ? - V_44 : 0 ;
}
static int F_16 ( struct V_47 * V_48 ,
const struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_9 ;
if ( V_48 -> V_53 < V_54 )
return - V_44 ;
V_9 = F_17 ( V_48 , & V_55 , V_56 , & V_2 ,
V_57 ) ;
if ( V_9 == 0 ) {
V_52 = F_18 ( V_48 , V_58 ) ;
if ( V_52 == NULL ) {
F_19 ( L_2 , V_59 ) ;
return - V_44 ;
}
V_9 = F_20 ( V_2 -> V_15 , V_52 -> V_60 . V_61 ,
V_52 -> V_60 . V_62 ) ;
}
return V_9 ;
}
static int T_4 F_21 ( void )
{
int V_9 ;
V_9 = F_22 ( & V_63 ) ;
if ( V_9 )
F_23 ( L_3 , V_9 ) ;
return V_9 ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_63 ) ;
}
