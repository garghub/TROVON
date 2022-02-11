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
F_15 ( V_39 , V_40 * 2 ) ;
}
static int T_1 F_16 ( void )
{
int V_41 , V_14 ;
F_17 ( 0 ) ;
if ( V_40 == 0 )
V_42 [ V_40 ++ ] = V_43 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
F_18 ( & V_39 [ 2 * V_41 ] , V_44 , V_29 , L_7 ,
V_43 , V_42 [ V_41 ] , V_41 , & V_45 ,
0 , F_1 , NULL , V_46 ) ;
F_18 ( & V_39 [ 2 * V_41 + 1 ] , V_47 , V_29 , L_7 ,
V_43 , V_42 [ V_41 ] , V_41 , & V_45 ,
0 , F_1 , NULL , V_46 ) ;
}
V_14 = F_19 ( V_39 , V_40 * 2 ) ;
if ( V_14 < 0 ) {
F_20 ( L_8 ) ;
return V_14 ;
}
return 0 ;
}
