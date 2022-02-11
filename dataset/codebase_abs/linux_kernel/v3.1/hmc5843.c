static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return F_2 ( V_2 ,
V_4 ,
( V_3 & 0x03 ) ) ;
}
static T_3 F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
T_4 V_13 ;
struct V_14 * V_15 = F_6 ( V_8 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
T_1 V_18 ;
F_8 ( & V_17 -> V_19 ) ;
V_18 = F_9 ( V_2 , V_20 ) ;
while ( ! ( V_18 & V_21 ) )
V_18 = F_9 ( V_2 , V_20 ) ;
V_18 = F_10 ( V_2 , V_15 -> V_22 ) ;
F_11 ( & V_17 -> V_19 ) ;
if ( V_18 < 0 )
return - V_23 ;
V_13 = ( T_4 ) F_12 ( ( V_24 ) V_18 ) ;
return sprintf ( V_9 , L_1 , V_13 ) ;
}
static T_3 F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
return sprintf ( V_9 , L_1 , V_17 -> V_3 ) ;
}
static T_3 F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 ,
T_5 V_25 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
struct V_14 * V_15 = F_6 ( V_8 ) ;
unsigned long V_3 = 0 ;
T_1 V_26 ;
int error ;
F_8 ( & V_17 -> V_19 ) ;
error = F_15 ( V_9 , 10 , & V_3 ) ;
if ( error ) {
V_25 = error ;
goto exit;
}
F_16 ( V_6 , L_2 , V_3 ) ;
if ( V_3 > V_27 ) {
V_25 = - V_23 ;
goto exit;
}
V_26 = F_2 ( V_2 , V_15 -> V_22 ,
V_3 ) ;
if ( V_26 ) {
V_25 = - V_23 ;
goto exit;
}
V_17 -> V_3 = V_3 ;
exit:
F_11 ( & V_17 -> V_19 ) ;
return V_25 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
T_2 V_28 )
{
struct V_16 * V_17 = F_18 ( V_2 ) ;
T_2 V_29 ;
V_29 = ( V_28 & V_30 ) | ( V_17 -> V_31 << V_32 ) ;
return F_2 ( V_2 , V_33 , V_29 ) ;
}
static T_3 F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
return sprintf ( V_9 , L_1 , V_17 -> V_28 ) ;
}
static T_3 F_20 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 ,
T_5 V_25 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_16 * V_17 = F_18 ( V_2 ) ;
unsigned long V_28 = 0 ;
int error = F_15 ( V_9 , 10 , & V_28 ) ;
if ( error )
return error ;
F_8 ( & V_17 -> V_19 ) ;
F_16 ( V_6 , L_3 , V_28 ) ;
if ( F_17 ( V_2 , V_28 ) ) {
V_25 = - V_23 ;
goto exit;
}
V_17 -> V_28 = V_28 ;
exit:
F_11 ( & V_17 -> V_19 ) ;
return V_25 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
T_2 V_31 )
{
struct V_16 * V_17 = F_18 ( V_2 ) ;
T_2 V_29 ;
V_29 = ( V_17 -> V_28 ) | ( V_31 << V_32 ) ;
if ( V_31 >= V_34 ) {
F_22 ( & V_2 -> V_6 ,
L_4 ) ;
return - V_23 ;
}
return F_2 ( V_2 , V_33 , V_29 ) ;
}
static T_3 F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_5 V_25 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
unsigned long V_31 = 0 ;
if ( strncmp ( V_9 , L_5 , 3 ) == 0 )
V_31 = V_35 ;
else if ( strncmp ( V_9 , L_6 , 1 ) == 0 )
V_31 = V_36 ;
else if ( strncmp ( V_9 , L_7 , 1 ) == 0 )
V_31 = V_37 ;
else if ( strncmp ( V_9 , L_8 , 1 ) == 0 )
V_31 = V_38 ;
else if ( strncmp ( V_9 , L_9 , 2 ) == 0 )
V_31 = V_39 ;
else if ( strncmp ( V_9 , L_10 , 2 ) == 0 )
V_31 = V_40 ;
else if ( strncmp ( V_9 , L_11 , 2 ) == 0 )
V_31 = V_41 ;
else
return - V_23 ;
F_8 ( & V_17 -> V_19 ) ;
F_16 ( V_6 , L_12 , V_31 ) ;
if ( F_21 ( V_2 , V_31 ) ) {
V_25 = - V_23 ;
goto exit;
}
V_17 -> V_31 = V_31 ;
exit:
F_11 ( & V_17 -> V_19 ) ;
return V_25 ;
}
static T_3 F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_14 * V_15 = F_6 ( V_8 ) ;
T_1 V_31 ;
V_31 = F_9 ( V_2 , V_15 -> V_22 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = ( V_31 & V_42 ) >> V_32 ;
return sprintf ( V_9 , L_13 , V_43 [ V_31 ] ) ;
}
static T_3 F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
T_2 V_44 ;
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
V_44 = V_17 -> V_44 ;
return sprintf ( V_9 , L_1 , V_45 [ V_44 ] ) ;
}
static T_3 F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 ,
T_5 V_25 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_14 * V_15 = F_6 ( V_8 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
unsigned long V_44 = 0 ;
int error ;
F_8 ( & V_17 -> V_19 ) ;
error = F_15 ( V_9 , 10 , & V_44 ) ;
if ( error ) {
V_25 = error ;
goto exit;
}
F_16 ( V_6 , L_14 , V_44 ) ;
if ( V_44 > V_46 ) {
V_25 = - V_23 ;
goto exit;
}
V_17 -> V_44 = V_44 ;
V_44 = V_44 << V_47 ;
if ( F_2 ( V_2 , V_15 -> V_22 , V_44 ) )
V_25 = - V_23 ;
exit:
F_11 ( & V_17 -> V_19 ) ;
return V_25 ;
}
static T_3 F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = F_7 ( V_11 ) ;
return strlen ( strcpy ( V_9 , V_48 [ V_17 -> V_44 ] ) ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
unsigned char V_51 [ V_52 ] ;
if ( V_2 -> V_53 != V_54 )
return - V_55 ;
if ( F_29 ( V_2 , V_56 ,
V_52 , V_51 )
!= V_52 )
return - V_55 ;
if ( 0 != strncmp ( V_51 , V_57 , V_52 ) )
return - V_55 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_18 ( V_2 ) ;
F_17 ( V_2 , V_17 -> V_28 ) ;
F_21 ( V_2 , V_17 -> V_31 ) ;
F_1 ( V_2 , V_17 -> V_3 ) ;
F_2 ( V_2 , V_58 , V_17 -> V_44 ) ;
F_31 ( & V_17 -> V_19 ) ;
F_32 ( L_15 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_59 * V_60 )
{
struct V_16 * V_17 ;
struct V_10 * V_11 ;
int V_61 = 0 ;
V_11 = F_34 ( sizeof( * V_17 ) ) ;
if ( V_11 == NULL ) {
V_61 = - V_62 ;
goto exit;
}
V_17 = F_7 ( V_11 ) ;
V_17 -> V_28 = V_63 ;
V_17 -> V_44 = V_64 ;
V_17 -> V_3 = V_65 ;
F_35 ( V_2 , V_11 ) ;
F_30 ( V_2 ) ;
V_11 -> V_50 = & V_66 ;
V_11 -> V_6 . V_12 = & V_2 -> V_6 ;
V_11 -> V_67 = V_68 ;
V_61 = F_36 ( V_11 ) ;
if ( V_61 )
goto V_69;
return 0 ;
V_69:
F_37 ( V_11 ) ;
exit:
return V_61 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_18 ( V_2 ) ;
F_1 ( V_2 , V_27 ) ;
F_39 ( V_11 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_6 V_70 )
{
F_1 ( V_2 , V_27 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_18 ( V_2 ) ;
F_1 ( V_2 , V_17 -> V_3 ) ;
return 0 ;
}
static int T_7 F_42 ( void )
{
return F_43 ( & V_71 ) ;
}
static void T_8 F_44 ( void )
{
F_45 ( & V_71 ) ;
}
