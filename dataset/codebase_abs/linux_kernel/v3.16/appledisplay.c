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
F_5 ( V_23 , & V_3 -> V_24 , 0 ) ;
break;
case V_25 :
default:
V_3 -> V_22 = 0 ;
break;
}
F_6 ( & V_3 -> V_18 , V_8 ) ;
exit:
V_10 = F_7 ( V_3 -> V_1 , V_26 ) ;
if ( V_10 ) {
F_2 ( V_6 , L_4 ,
V_17 , V_10 ) ;
}
}
static int F_8 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = F_9 ( V_28 ) ;
int V_10 ;
F_10 ( & V_3 -> V_29 ) ;
V_3 -> V_30 [ 0 ] = 0x10 ;
V_3 -> V_30 [ 1 ] = V_28 -> V_31 . V_32 ;
V_10 = F_11 (
V_3 -> V_7 ,
F_12 ( V_3 -> V_7 , 0 ) ,
V_33 ,
V_34 | V_35 | V_36 ,
V_37 ,
0 ,
V_3 -> V_30 , 2 ,
V_38 ) ;
F_13 ( & V_3 -> V_29 ) ;
return V_10 ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_2 * V_3 = F_9 ( V_28 ) ;
int V_10 , V_32 ;
F_10 ( & V_3 -> V_29 ) ;
V_10 = F_11 (
V_3 -> V_7 ,
F_15 ( V_3 -> V_7 , 0 ) ,
V_39 ,
V_40 | V_35 | V_36 ,
V_37 ,
0 ,
V_3 -> V_30 , 2 ,
V_38 ) ;
V_32 = V_3 -> V_30 [ 1 ] ;
F_13 ( & V_3 -> V_29 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return V_32 ;
}
static void F_16 ( struct V_41 * V_24 )
{
struct V_2 * V_3 =
F_17 ( V_24 , struct V_2 , V_24 . V_24 ) ;
int V_10 ;
V_10 = F_14 ( V_3 -> V_28 ) ;
if ( V_10 >= 0 )
V_3 -> V_28 -> V_31 . V_32 = V_10 ;
if ( V_3 -> V_22 )
F_18 ( & V_3 -> V_24 , V_42 / 8 ) ;
}
static int F_19 ( struct V_43 * V_44 ,
const struct V_45 * V_46 )
{
struct V_47 V_31 ;
struct V_2 * V_3 ;
struct V_48 * V_7 = F_20 ( V_44 ) ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_53 = 0 ;
int V_54 , V_10 = - V_55 , V_32 ;
char V_56 [ 20 ] ;
V_50 = V_44 -> V_57 ;
for ( V_54 = 0 ; V_54 < V_50 -> V_58 . V_59 ; V_54 ++ ) {
V_52 = & V_50 -> V_52 [ V_54 ] . V_58 ;
if ( ! V_53 && F_21 ( V_52 ) ) {
V_53 = V_52 -> V_60 ;
break;
}
}
if ( ! V_53 ) {
F_2 ( & V_44 -> V_6 , L_5 ) ;
return - V_61 ;
}
V_3 = F_22 ( sizeof( struct V_2 ) , V_62 ) ;
if ( ! V_3 ) {
V_10 = - V_55 ;
F_2 ( & V_44 -> V_6 , L_6 ) ;
goto error;
}
V_3 -> V_7 = V_7 ;
F_23 ( & V_3 -> V_18 ) ;
F_24 ( & V_3 -> V_24 , F_16 ) ;
F_25 ( & V_3 -> V_29 ) ;
V_3 -> V_30 = F_26 ( V_63 , V_62 ) ;
if ( ! V_3 -> V_30 ) {
V_10 = - V_55 ;
F_2 ( & V_44 -> V_6 ,
L_7 ) ;
goto error;
}
V_3 -> V_1 = F_27 ( 0 , V_62 ) ;
if ( ! V_3 -> V_1 ) {
V_10 = - V_55 ;
F_2 ( & V_44 -> V_6 , L_8 ) ;
goto error;
}
V_3 -> V_19 = F_28 ( V_3 -> V_7 , V_12 ,
V_62 , & V_3 -> V_1 -> V_64 ) ;
if ( ! V_3 -> V_19 ) {
V_10 = - V_55 ;
F_2 ( & V_44 -> V_6 , L_9 ) ;
goto error;
}
F_29 ( V_3 -> V_1 , V_7 ,
F_30 ( V_7 , V_53 ) ,
V_3 -> V_19 , V_12 , F_1 ,
V_3 , 1 ) ;
if ( F_7 ( V_3 -> V_1 , V_62 ) ) {
V_10 = - V_61 ;
F_2 ( & V_44 -> V_6 , L_10 ) ;
goto error;
}
snprintf ( V_56 , sizeof( V_56 ) , L_11 ,
F_31 ( & V_65 ) - 1 ) ;
memset ( & V_31 , 0 , sizeof( struct V_47 ) ) ;
V_31 . type = V_66 ;
V_31 . V_67 = 0xff ;
V_3 -> V_28 = F_32 ( V_56 , NULL , V_3 ,
& V_68 , & V_31 ) ;
if ( F_33 ( V_3 -> V_28 ) ) {
F_2 ( & V_44 -> V_6 , L_12 ) ;
V_10 = F_34 ( V_3 -> V_28 ) ;
goto error;
}
V_32 = F_14 ( V_3 -> V_28 ) ;
if ( V_32 < 0 ) {
V_10 = V_32 ;
F_2 ( & V_44 -> V_6 ,
L_13 , V_10 ) ;
goto error;
}
V_3 -> V_28 -> V_31 . V_32 = V_32 ;
F_35 ( V_44 , V_3 ) ;
F_36 ( V_69 L_14 ) ;
return 0 ;
error:
if ( V_3 ) {
if ( V_3 -> V_1 ) {
F_37 ( V_3 -> V_1 ) ;
if ( V_3 -> V_19 )
F_38 ( V_3 -> V_7 , V_12 ,
V_3 -> V_19 , V_3 -> V_1 -> V_64 ) ;
F_39 ( V_3 -> V_1 ) ;
}
if ( V_3 -> V_28 && ! F_33 ( V_3 -> V_28 ) )
F_40 ( V_3 -> V_28 ) ;
F_41 ( V_3 -> V_30 ) ;
}
F_35 ( V_44 , NULL ) ;
F_41 ( V_3 ) ;
return V_10 ;
}
static void F_42 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_43 ( V_44 ) ;
if ( V_3 ) {
F_37 ( V_3 -> V_1 ) ;
F_44 ( & V_3 -> V_24 ) ;
F_40 ( V_3 -> V_28 ) ;
F_38 ( V_3 -> V_7 , V_12 ,
V_3 -> V_19 , V_3 -> V_1 -> V_64 ) ;
F_39 ( V_3 -> V_1 ) ;
F_41 ( V_3 -> V_30 ) ;
F_41 ( V_3 ) ;
}
F_36 ( V_69 L_15 ) ;
}
static int T_1 F_45 ( void )
{
V_23 = F_46 ( L_16 ) ;
if ( ! V_23 ) {
F_36 ( V_70 L_17 ) ;
return - V_55 ;
}
return F_47 ( & V_71 ) ;
}
static void T_2 F_48 ( void )
{
F_49 ( V_23 ) ;
F_50 ( V_23 ) ;
F_51 ( & V_71 ) ;
}
