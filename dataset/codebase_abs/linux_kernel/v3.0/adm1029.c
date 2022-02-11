static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
T_2 V_12 ;
if ( V_9 -> V_13 [ V_7 -> V_11 ] == 0
|| ( V_9 -> V_14 [ V_7 -> V_11 ] & 0xC0 ) == 0
|| V_9 -> V_13 [ V_7 -> V_11 ] == 255 ) {
return sprintf ( V_5 , L_2 ) ;
}
V_12 = 1880 * 120 / F_6 ( V_9 -> V_14 [ V_7 -> V_11 ] )
/ V_9 -> V_13 [ V_7 -> V_11 ] ;
return sprintf ( V_5 , L_1 , V_12 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
if ( ( V_9 -> V_14 [ V_7 -> V_11 ] & 0xC0 ) == 0 )
return sprintf ( V_5 , L_2 ) ;
return sprintf ( V_5 , L_1 , F_6 ( V_9 -> V_14 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_3 V_15 )
{
struct V_16 * V_17 = F_9 ( V_2 ) ;
struct V_8 * V_9 = F_10 ( V_17 ) ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
long V_12 = F_11 ( V_5 , NULL , 10 ) ;
T_4 V_18 ;
F_12 ( & V_9 -> V_19 ) ;
V_18 = F_13 ( V_17 ,
V_20 [ V_7 -> V_11 ] ) ;
switch ( V_12 ) {
case 1 :
V_12 = 1 ;
break;
case 2 :
V_12 = 2 ;
break;
case 4 :
V_12 = 3 ;
break;
default:
F_14 ( & V_9 -> V_19 ) ;
F_15 ( & V_17 -> V_2 , L_3
L_4 , V_12 ) ;
return - V_21 ;
}
V_18 = ( V_18 & 0x3F ) | ( V_12 << 6 ) ;
F_16 ( V_17 ,
V_20 [ V_7 -> V_11 ] , V_18 ) ;
F_14 ( & V_9 -> V_19 ) ;
return V_15 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_17 -> V_25 ;
T_4 V_26 , V_27 , V_28 , V_29 ;
if ( ! F_18 ( V_25 , V_30 ) )
return - V_31 ;
V_26 = F_13 ( V_17 , V_32 ) ;
V_27 = F_13 ( V_17 , V_33 ) ;
V_28 = F_13 ( V_17 ,
V_34 ) ;
V_29 = F_13 ( V_17 ,
V_35 ) ;
if ( V_26 != 0x41 || ( V_28 & 0xf9 ) != 0x01
|| V_29 != 0x03 )
return - V_31 ;
if ( ( V_27 & 0xF0 ) != 0x00 ) {
F_19 ( L_5
L_6 , V_27 ) ;
return - V_31 ;
}
F_20 ( V_23 -> type , L_7 , V_36 ) ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 ,
const struct V_37 * V_38 )
{
struct V_8 * V_9 ;
int V_39 ;
V_9 = F_22 ( sizeof( struct V_8 ) , V_40 ) ;
if ( ! V_9 ) {
V_39 = - V_41 ;
goto exit;
}
F_23 ( V_17 , V_9 ) ;
F_24 ( & V_9 -> V_19 ) ;
if ( F_25 ( V_17 ) == 0 ) {
V_39 = - V_31 ;
goto V_42;
}
if ( ( V_39 = F_26 ( & V_17 -> V_2 . V_43 , & V_44 ) ) )
goto V_42;
V_9 -> V_45 = F_27 ( & V_17 -> V_2 ) ;
if ( F_28 ( V_9 -> V_45 ) ) {
V_39 = F_29 ( V_9 -> V_45 ) ;
goto V_46;
}
return 0 ;
V_46:
F_30 ( & V_17 -> V_2 . V_43 , & V_44 ) ;
V_42:
F_31 ( V_9 ) ;
exit:
return V_39 ;
}
static int F_25 ( struct V_16 * V_17 )
{
T_4 V_47 ;
V_47 = F_13 ( V_17 , V_48 ) ;
if ( ( V_47 & 0x10 ) == 0 ) {
F_16 ( V_17 , V_48 ,
V_47 | 0x10 ) ;
}
V_47 = F_13 ( V_17 , V_48 ) ;
if ( ( V_47 & 0x10 ) == 0 ) {
F_15 ( & V_17 -> V_2 , L_8 ) ;
return 0 ;
}
return 1 ;
}
static int F_32 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = F_10 ( V_17 ) ;
F_33 ( V_9 -> V_45 ) ;
F_30 ( & V_17 -> V_2 . V_43 , & V_44 ) ;
F_31 ( V_9 ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_9 ( V_2 ) ;
struct V_8 * V_9 = F_10 ( V_17 ) ;
F_12 ( & V_9 -> V_19 ) ;
if ( F_34 ( V_49 , V_9 -> V_50 + V_51 * 2 )
|| ! V_9 -> V_52 ) {
int V_53 ;
F_35 ( & V_17 -> V_2 , L_9 ) ;
for ( V_53 = 0 ; V_53 < F_36 ( V_54 ) ; V_53 ++ ) {
V_9 -> V_10 [ V_53 ] =
F_13 ( V_17 ,
V_54 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < F_36 ( V_55 ) ; V_53 ++ ) {
V_9 -> V_13 [ V_53 ] =
F_13 ( V_17 ,
V_55 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < F_36 ( V_20 ) ; V_53 ++ ) {
V_9 -> V_14 [ V_53 ] =
F_13 ( V_17 ,
V_20 [ V_53 ] ) ;
}
V_9 -> V_50 = V_49 ;
V_9 -> V_52 = 1 ;
}
F_14 ( & V_9 -> V_19 ) ;
return V_9 ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_56 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_56 ) ;
}
