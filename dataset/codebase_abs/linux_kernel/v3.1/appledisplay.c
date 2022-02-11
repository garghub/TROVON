static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned long V_5 ;
int V_6 = V_1 -> V_6 ;
int V_7 ;
switch ( V_6 ) {
case 0 :
break;
case - V_8 :
F_2 ( V_9 L_1
L_2 ,
V_10 , V_3 -> V_1 -> V_11 ) ;
case - V_12 :
case - V_13 :
case - V_14 :
F_3 ( L_3 ,
V_15 , V_6 ) ;
return;
default:
F_3 ( L_4 ,
V_15 , V_6 ) ;
goto exit;
}
F_4 ( & V_3 -> V_16 , V_5 ) ;
switch( V_3 -> V_17 [ 1 ] ) {
case V_18 :
case V_19 :
V_3 -> V_20 = 1 ;
F_5 ( V_21 , & V_3 -> V_22 , 0 ) ;
break;
case V_23 :
default:
V_3 -> V_20 = 0 ;
break;
}
F_6 ( & V_3 -> V_16 , V_5 ) ;
exit:
V_7 = F_7 ( V_3 -> V_1 , V_24 ) ;
if ( V_7 ) {
F_8 ( & V_3 -> V_25 -> V_26 ,
L_5 ,
V_15 , V_7 ) ;
}
}
static int F_9 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = F_10 ( V_28 ) ;
int V_7 ;
V_3 -> V_29 [ 0 ] = 0x10 ;
V_3 -> V_29 [ 1 ] = V_28 -> V_30 . V_31 ;
V_7 = F_11 (
V_3 -> V_25 ,
F_12 ( V_3 -> V_25 , 0 ) ,
V_32 ,
V_33 | V_34 | V_35 ,
V_36 ,
0 ,
V_3 -> V_29 , 2 ,
V_37 ) ;
return V_7 ;
}
static int F_13 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = F_10 ( V_28 ) ;
int V_7 ;
V_7 = F_11 (
V_3 -> V_25 ,
F_14 ( V_3 -> V_25 , 0 ) ,
V_38 ,
V_39 | V_34 | V_35 ,
V_36 ,
0 ,
V_3 -> V_29 , 2 ,
V_37 ) ;
if ( V_7 < 0 )
return V_7 ;
else
return V_3 -> V_29 [ 1 ] ;
}
static void F_15 ( struct V_40 * V_22 )
{
struct V_2 * V_3 =
F_16 ( V_22 , struct V_2 , V_22 . V_22 ) ;
int V_7 ;
V_7 = F_13 ( V_3 -> V_28 ) ;
if ( V_7 >= 0 )
V_3 -> V_28 -> V_30 . V_31 = V_7 ;
if ( V_3 -> V_20 )
F_17 ( & V_3 -> V_22 , V_41 / 8 ) ;
}
static int F_18 ( struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_46 V_30 ;
struct V_2 * V_3 ;
struct V_47 * V_25 = F_19 ( V_43 ) ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
int V_52 = 0 ;
int V_53 , V_7 = - V_54 , V_31 ;
char V_55 [ 20 ] ;
V_49 = V_43 -> V_56 ;
for ( V_53 = 0 ; V_53 < V_49 -> V_57 . V_58 ; V_53 ++ ) {
V_51 = & V_49 -> V_51 [ V_53 ] . V_57 ;
if ( ! V_52 && F_20 ( V_51 ) ) {
V_52 = V_51 -> V_59 ;
break;
}
}
if ( ! V_52 ) {
F_8 ( & V_43 -> V_26 , L_6 ) ;
return - V_60 ;
}
V_3 = F_21 ( sizeof( struct V_2 ) , V_61 ) ;
if ( ! V_3 ) {
V_7 = - V_54 ;
F_8 ( & V_43 -> V_26 , L_7 ) ;
goto error;
}
V_3 -> V_25 = V_25 ;
F_22 ( & V_3 -> V_16 ) ;
F_23 ( & V_3 -> V_22 , F_15 ) ;
V_3 -> V_29 = F_24 ( V_62 , V_61 ) ;
if ( ! V_3 -> V_29 ) {
V_7 = - V_54 ;
F_8 ( & V_43 -> V_26 ,
L_8 ) ;
goto error;
}
V_3 -> V_1 = F_25 ( 0 , V_61 ) ;
if ( ! V_3 -> V_1 ) {
V_7 = - V_54 ;
F_8 ( & V_43 -> V_26 , L_9 ) ;
goto error;
}
V_3 -> V_17 = F_26 ( V_3 -> V_25 , V_10 ,
V_61 , & V_3 -> V_1 -> V_63 ) ;
if ( ! V_3 -> V_17 ) {
V_7 = - V_54 ;
F_8 ( & V_43 -> V_26 , L_10 ) ;
goto error;
}
F_27 ( V_3 -> V_1 , V_25 ,
F_28 ( V_25 , V_52 ) ,
V_3 -> V_17 , V_10 , F_1 ,
V_3 , 1 ) ;
if ( F_7 ( V_3 -> V_1 , V_61 ) ) {
V_7 = - V_60 ;
F_8 ( & V_43 -> V_26 , L_11 ) ;
goto error;
}
snprintf ( V_55 , sizeof( V_55 ) , L_12 ,
F_29 ( & V_64 ) - 1 ) ;
memset ( & V_30 , 0 , sizeof( struct V_46 ) ) ;
V_30 . type = V_65 ;
V_30 . V_66 = 0xff ;
V_3 -> V_28 = F_30 ( V_55 , NULL , V_3 ,
& V_67 , & V_30 ) ;
if ( F_31 ( V_3 -> V_28 ) ) {
F_8 ( & V_43 -> V_26 , L_13 ) ;
V_7 = F_32 ( V_3 -> V_28 ) ;
goto error;
}
V_31 = F_13 ( V_3 -> V_28 ) ;
if ( V_31 < 0 ) {
V_7 = V_31 ;
F_8 ( & V_43 -> V_26 ,
L_14 , V_7 ) ;
goto error;
}
V_3 -> V_28 -> V_30 . V_31 = V_31 ;
F_33 ( V_43 , V_3 ) ;
F_2 ( V_68 L_15 ) ;
return 0 ;
error:
if ( V_3 ) {
if ( V_3 -> V_1 ) {
F_34 ( V_3 -> V_1 ) ;
if ( V_3 -> V_17 )
F_35 ( V_3 -> V_25 , V_10 ,
V_3 -> V_17 , V_3 -> V_1 -> V_63 ) ;
F_36 ( V_3 -> V_1 ) ;
}
if ( V_3 -> V_28 && ! F_31 ( V_3 -> V_28 ) )
F_37 ( V_3 -> V_28 ) ;
F_38 ( V_3 -> V_29 ) ;
}
F_33 ( V_43 , NULL ) ;
F_38 ( V_3 ) ;
return V_7 ;
}
static void F_39 ( struct V_42 * V_43 )
{
struct V_2 * V_3 = F_40 ( V_43 ) ;
if ( V_3 ) {
F_34 ( V_3 -> V_1 ) ;
F_41 ( & V_3 -> V_22 ) ;
F_37 ( V_3 -> V_28 ) ;
F_35 ( V_3 -> V_25 , V_10 ,
V_3 -> V_17 , V_3 -> V_1 -> V_63 ) ;
F_36 ( V_3 -> V_1 ) ;
F_38 ( V_3 -> V_29 ) ;
F_38 ( V_3 ) ;
}
F_2 ( V_68 L_16 ) ;
}
static int T_1 F_42 ( void )
{
V_21 = F_43 ( L_17 ) ;
if ( ! V_21 ) {
F_2 ( V_9 L_18 ) ;
return - V_54 ;
}
return F_44 ( & V_69 ) ;
}
static void T_2 F_45 ( void )
{
F_46 ( V_21 ) ;
F_47 ( V_21 ) ;
F_48 ( & V_69 ) ;
}
