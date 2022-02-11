static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_3 -> V_7 -> V_6 ;
unsigned long V_8 ;
int V_9 = V_1 -> V_9 ;
int V_10 ;
switch ( V_9 ) {
case 0 :
break;
case - V_11 :
F_2 ( V_6 ,
L_1 ,
V_12 , V_3 -> V_1 -> V_13 ) ;
case - V_14 :
case - V_15 :
case - V_16 :
F_3 ( V_6 , L_2 ,
V_17 , V_9 ) ;
return;
default:
F_3 ( V_6 , L_3 ,
V_17 , V_9 ) ;
goto exit;
}
F_4 ( & V_3 -> V_18 , V_8 ) ;
switch( V_3 -> V_19 [ 1 ] ) {
case V_20 :
case V_21 :
V_3 -> V_22 = 1 ;
F_5 ( & V_3 -> V_23 , 0 ) ;
break;
case V_24 :
default:
V_3 -> V_22 = 0 ;
break;
}
F_6 ( & V_3 -> V_18 , V_8 ) ;
exit:
V_10 = F_7 ( V_3 -> V_1 , V_25 ) ;
if ( V_10 ) {
F_2 ( V_6 , L_4 ,
V_17 , V_10 ) ;
}
}
static int F_8 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_9 ( V_27 ) ;
int V_10 ;
F_10 ( & V_3 -> V_28 ) ;
V_3 -> V_29 [ 0 ] = 0x10 ;
V_3 -> V_29 [ 1 ] = V_27 -> V_30 . V_31 ;
V_10 = F_11 (
V_3 -> V_7 ,
F_12 ( V_3 -> V_7 , 0 ) ,
V_32 ,
V_33 | V_34 | V_35 ,
V_36 ,
0 ,
V_3 -> V_29 , 2 ,
V_37 ) ;
F_13 ( & V_3 -> V_28 ) ;
return V_10 ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = F_9 ( V_27 ) ;
int V_10 , V_31 ;
F_10 ( & V_3 -> V_28 ) ;
V_10 = F_11 (
V_3 -> V_7 ,
F_15 ( V_3 -> V_7 , 0 ) ,
V_38 ,
V_39 | V_34 | V_35 ,
V_36 ,
0 ,
V_3 -> V_29 , 2 ,
V_37 ) ;
V_31 = V_3 -> V_29 [ 1 ] ;
F_13 ( & V_3 -> V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return V_31 ;
}
static void F_16 ( struct V_40 * V_23 )
{
struct V_2 * V_3 =
F_17 ( V_23 , struct V_2 , V_23 . V_23 ) ;
int V_10 ;
V_10 = F_14 ( V_3 -> V_27 ) ;
if ( V_10 >= 0 )
V_3 -> V_27 -> V_30 . V_31 = V_10 ;
if ( V_3 -> V_22 )
F_5 ( & V_3 -> V_23 , V_41 / 8 ) ;
}
static int F_18 ( struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_46 V_30 ;
struct V_2 * V_3 ;
struct V_47 * V_7 = F_19 ( V_43 ) ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
int V_52 = 0 ;
int V_53 , V_10 = - V_54 , V_31 ;
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
F_2 ( & V_43 -> V_6 , L_5 ) ;
return - V_60 ;
}
V_3 = F_21 ( sizeof( struct V_2 ) , V_61 ) ;
if ( ! V_3 ) {
V_10 = - V_54 ;
goto error;
}
V_3 -> V_7 = V_7 ;
F_22 ( & V_3 -> V_18 ) ;
F_23 ( & V_3 -> V_23 , F_16 ) ;
F_24 ( & V_3 -> V_28 ) ;
V_3 -> V_29 = F_25 ( V_62 , V_61 ) ;
if ( ! V_3 -> V_29 ) {
V_10 = - V_54 ;
goto error;
}
V_3 -> V_1 = F_26 ( 0 , V_61 ) ;
if ( ! V_3 -> V_1 ) {
V_10 = - V_54 ;
goto error;
}
V_3 -> V_19 = F_27 ( V_3 -> V_7 , V_12 ,
V_61 , & V_3 -> V_1 -> V_63 ) ;
if ( ! V_3 -> V_19 ) {
V_10 = - V_54 ;
F_2 ( & V_43 -> V_6 , L_6 ) ;
goto error;
}
F_28 ( V_3 -> V_1 , V_7 ,
F_29 ( V_7 , V_52 ) ,
V_3 -> V_19 , V_12 , F_1 ,
V_3 , 1 ) ;
if ( F_7 ( V_3 -> V_1 , V_61 ) ) {
V_10 = - V_60 ;
F_2 ( & V_43 -> V_6 , L_7 ) ;
goto error;
}
snprintf ( V_55 , sizeof( V_55 ) , L_8 ,
F_30 ( & V_64 ) - 1 ) ;
memset ( & V_30 , 0 , sizeof( struct V_46 ) ) ;
V_30 . type = V_65 ;
V_30 . V_66 = 0xff ;
V_3 -> V_27 = F_31 ( V_55 , NULL , V_3 ,
& V_67 , & V_30 ) ;
if ( F_32 ( V_3 -> V_27 ) ) {
F_2 ( & V_43 -> V_6 , L_9 ) ;
V_10 = F_33 ( V_3 -> V_27 ) ;
goto error;
}
V_31 = F_14 ( V_3 -> V_27 ) ;
if ( V_31 < 0 ) {
V_10 = V_31 ;
F_2 ( & V_43 -> V_6 ,
L_10 , V_10 ) ;
goto error;
}
V_3 -> V_27 -> V_30 . V_31 = V_31 ;
F_34 ( V_43 , V_3 ) ;
F_35 ( V_68 L_11 ) ;
return 0 ;
error:
if ( V_3 ) {
if ( V_3 -> V_1 ) {
F_36 ( V_3 -> V_1 ) ;
if ( V_3 -> V_19 )
F_37 ( V_3 -> V_7 , V_12 ,
V_3 -> V_19 , V_3 -> V_1 -> V_63 ) ;
F_38 ( V_3 -> V_1 ) ;
}
if ( ! F_32 ( V_3 -> V_27 ) )
F_39 ( V_3 -> V_27 ) ;
F_40 ( V_3 -> V_29 ) ;
}
F_34 ( V_43 , NULL ) ;
F_40 ( V_3 ) ;
return V_10 ;
}
static void F_41 ( struct V_42 * V_43 )
{
struct V_2 * V_3 = F_42 ( V_43 ) ;
if ( V_3 ) {
F_36 ( V_3 -> V_1 ) ;
F_43 ( & V_3 -> V_23 ) ;
F_39 ( V_3 -> V_27 ) ;
F_37 ( V_3 -> V_7 , V_12 ,
V_3 -> V_19 , V_3 -> V_1 -> V_63 ) ;
F_38 ( V_3 -> V_1 ) ;
F_40 ( V_3 -> V_29 ) ;
F_40 ( V_3 ) ;
}
F_35 ( V_68 L_12 ) ;
}
static int T_1 F_44 ( void )
{
return F_45 ( & V_69 ) ;
}
static void T_2 F_46 ( void )
{
F_47 ( & V_69 ) ;
}
