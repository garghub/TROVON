static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_12 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_13 * V_14 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_14 ) ;
long V_15 = F_8 ( V_5 , NULL , 10 ) ;
int V_16 = V_7 -> V_11 ;
F_9 ( & V_9 -> V_17 ) ;
V_9 -> V_10 [ V_16 ] = F_10 ( V_15 ) ;
F_11 ( V_14 , V_18 [ V_16 - 4 ] ,
V_9 -> V_10 [ V_16 ] ) ;
F_12 ( & V_9 -> V_17 ) ;
return V_12 ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_19 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_20 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_21 = V_7 -> V_11 ;
return sprintf ( V_5 , L_1 , ( V_9 -> V_20 >> V_21 ) & 1 ) ;
}
static int F_15 ( struct V_13 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_22 -> V_26 ;
const char * V_27 ;
T_3 V_28 , V_29 ;
if ( ! F_16 ( V_26 , V_30 ) )
return - V_31 ;
if ( ( F_17 ( V_22 , V_32 ) & 0xA8 ) ||
( F_17 ( V_22 , V_33 ) & 0x48 ) ||
( F_17 ( V_22 , V_34 ) & 0x41 ) ) {
F_18 ( & V_26 -> V_2 , L_2 ,
V_22 -> V_35 ) ;
return - V_31 ;
}
V_28 = F_17 ( V_22 , V_36 ) ;
if ( V_28 != 0x01 )
return - V_31 ;
V_29 = F_17 ( V_22 , V_37 ) ;
switch ( V_29 ) {
case 0x03 :
V_27 = L_3 ;
break;
case 0x01 :
V_27 = L_4 ;
break;
default:
F_19 ( & V_26 -> V_2 ,
L_5 ,
V_28 , V_29 ) ;
return - V_31 ;
}
F_20 ( V_24 -> type , V_27 , V_38 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_22 ,
const struct V_39 * V_40 )
{
struct V_8 * V_9 ;
int V_41 ;
V_9 = F_22 ( sizeof( struct V_8 ) , V_42 ) ;
if ( ! V_9 ) {
V_41 = - V_43 ;
goto exit;
}
F_23 ( V_22 , V_9 ) ;
V_9 -> V_44 = 0 ;
F_24 ( & V_9 -> V_17 ) ;
if ( ( V_41 = F_25 ( & V_22 -> V_2 . V_45 , & V_46 ) ) )
goto V_47;
if ( V_40 -> V_48 == V_49 ) {
if ( ( V_41 = F_25 ( & V_22 -> V_2 . V_45 ,
& V_50 ) ) )
goto V_51;
}
V_9 -> V_52 = F_26 ( & V_22 -> V_2 ) ;
if ( F_27 ( V_9 -> V_52 ) ) {
V_41 = F_28 ( V_9 -> V_52 ) ;
goto V_51;
}
return 0 ;
V_51:
F_29 ( & V_22 -> V_2 . V_45 , & V_46 ) ;
F_29 ( & V_22 -> V_2 . V_45 , & V_50 ) ;
V_47:
F_30 ( V_9 ) ;
exit:
return V_41 ;
}
static int F_31 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_7 ( V_14 ) ;
F_32 ( V_9 -> V_52 ) ;
F_29 ( & V_14 -> V_2 . V_45 , & V_46 ) ;
F_29 ( & V_14 -> V_2 . V_45 , & V_50 ) ;
F_30 ( V_9 ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_14 ) ;
F_9 ( & V_9 -> V_17 ) ;
if ( F_33 ( V_53 , V_9 -> V_54 + V_55 * 2 ) || ! V_9 -> V_44 ) {
int V_16 ;
F_18 ( & V_14 -> V_2 , L_6 ) ;
for ( V_16 = 0 ; V_16 < 9 ; V_16 ++ ) {
V_9 -> V_10 [ V_16 ] =
F_17 ( V_14 ,
V_56 [ V_16 ] ) ;
}
V_9 -> V_20 =
F_17 ( V_14 , V_32 )
+ ( F_17 ( V_14 , V_33 )
<< 8 ) ;
V_9 -> V_54 = V_53 ;
V_9 -> V_44 = 1 ;
}
F_12 ( & V_9 -> V_17 ) ;
return V_9 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_57 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_57 ) ;
}
