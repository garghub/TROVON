static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 ,
enum V_6 V_7 )
{
const struct V_8 * V_9 ;
struct V_8 V_10 ;
struct V_11 * exp ;
struct V_12 * V_13 ;
unsigned int V_14 = V_15 ;
F_2 (nf_nat_tftp_hook) V_16 ;
V_9 = F_3 ( V_2 , V_3 + sizeof( struct V_17 ) ,
sizeof( V_10 ) , & V_10 ) ;
if ( V_9 == NULL )
return V_15 ;
switch ( F_4 ( V_9 -> V_18 ) ) {
case V_19 :
case V_20 :
F_5 ( & V_5 -> V_21 [ V_22 ] . V_13 ) ;
F_5 ( & V_5 -> V_21 [ V_23 ] . V_13 ) ;
exp = F_6 ( V_5 ) ;
if ( exp == NULL ) {
F_7 ( V_2 , V_5 , L_1 ) ;
return V_24 ;
}
V_13 = & V_5 -> V_21 [ V_23 ] . V_13 ;
F_8 ( exp , V_25 ,
F_9 ( V_5 ) ,
& V_13 -> V_26 . V_27 , & V_13 -> V_28 . V_27 ,
V_29 , NULL , & V_13 -> V_28 . V_30 . V_31 . V_32 ) ;
F_10 ( L_2 ) ;
F_5 ( & exp -> V_13 ) ;
V_16 = F_11 ( V_33 ) ;
if ( V_16 && V_5 -> V_34 & V_35 )
V_14 = V_16 ( V_2 , V_7 , exp ) ;
else if ( F_12 ( exp ) != 0 ) {
F_7 ( V_2 , V_5 , L_3 ) ;
V_14 = V_24 ;
}
F_13 ( exp ) ;
break;
case V_36 :
case V_37 :
F_10 ( L_4 ) ;
break;
case V_38 :
F_10 ( L_5 ) ;
break;
default:
F_10 ( L_6 ) ;
}
return V_14 ;
}
static void F_14 ( void )
{
int V_39 , V_40 ;
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ ) {
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ )
F_15 ( & V_42 [ V_39 ] [ V_40 ] ) ;
}
}
static int T_1 F_16 ( void )
{
int V_39 , V_40 , V_14 ;
if ( V_41 == 0 )
V_43 [ V_41 ++ ] = V_44 ;
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ ) {
memset ( & V_42 [ V_39 ] , 0 , sizeof( V_42 [ V_39 ] ) ) ;
V_42 [ V_39 ] [ 0 ] . V_13 . V_26 . V_45 = V_46 ;
V_42 [ V_39 ] [ 1 ] . V_13 . V_26 . V_45 = V_47 ;
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
V_42 [ V_39 ] [ V_40 ] . V_13 . V_28 . V_48 = V_29 ;
V_42 [ V_39 ] [ V_40 ] . V_13 . V_26 . V_30 . V_31 . V_32 = F_17 ( V_43 [ V_39 ] ) ;
V_42 [ V_39 ] [ V_40 ] . V_49 = & V_50 ;
V_42 [ V_39 ] [ V_40 ] . V_51 = V_52 ;
V_42 [ V_39 ] [ V_40 ] . V_53 = F_1 ;
if ( V_43 [ V_39 ] == V_44 )
sprintf ( V_42 [ V_39 ] [ V_40 ] . V_54 , L_7 ) ;
else
sprintf ( V_42 [ V_39 ] [ V_40 ] . V_54 , L_8 , V_39 ) ;
V_14 = F_18 ( & V_42 [ V_39 ] [ V_40 ] ) ;
if ( V_14 ) {
F_19 ( V_55 L_9
L_10 ,
V_42 [ V_39 ] [ V_40 ] . V_13 . V_26 . V_45 , V_43 [ V_39 ] ) ;
F_14 () ;
return V_14 ;
}
}
}
return 0 ;
}
