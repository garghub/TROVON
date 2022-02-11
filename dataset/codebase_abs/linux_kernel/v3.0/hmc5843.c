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
struct V_16 * V_17 = V_11 -> V_18 ;
T_1 V_19 ;
F_7 ( & V_17 -> V_20 ) ;
V_19 = F_8 ( V_2 , V_21 ) ;
while ( ! ( V_19 & V_22 ) )
V_19 = F_8 ( V_2 , V_21 ) ;
V_19 = F_9 ( V_2 , V_15 -> V_23 ) ;
F_10 ( & V_17 -> V_20 ) ;
if ( V_19 < 0 )
return - V_24 ;
V_13 = ( T_4 ) F_11 ( ( V_25 ) V_19 ) ;
return sprintf ( V_9 , L_1 , V_13 ) ;
}
static T_3 F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
return sprintf ( V_9 , L_1 , V_17 -> V_3 ) ;
}
static T_3 F_13 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 ,
T_5 V_26 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_14 * V_15 = F_6 ( V_8 ) ;
unsigned long V_3 = 0 ;
T_1 V_27 ;
int error ;
F_7 ( & V_17 -> V_20 ) ;
error = F_14 ( V_9 , 10 , & V_3 ) ;
if ( error ) {
V_26 = error ;
goto exit;
}
F_15 ( V_6 , L_2 , V_3 ) ;
if ( V_3 > V_28 ) {
V_26 = - V_24 ;
goto exit;
}
V_27 = F_2 ( V_2 , V_15 -> V_23 ,
V_3 ) ;
if ( V_27 ) {
V_26 = - V_24 ;
goto exit;
}
V_17 -> V_3 = V_3 ;
exit:
F_10 ( & V_17 -> V_20 ) ;
return V_26 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
T_2 V_29 )
{
struct V_16 * V_17 = F_17 ( V_2 ) ;
T_2 V_30 ;
V_30 = ( V_29 & V_31 ) | ( V_17 -> V_32 << V_33 ) ;
return F_2 ( V_2 , V_34 , V_30 ) ;
}
static T_3 F_18 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
return sprintf ( V_9 , L_1 , V_17 -> V_29 ) ;
}
static T_3 F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 ,
T_5 V_26 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_16 * V_17 = F_17 ( V_2 ) ;
unsigned long V_29 = 0 ;
int error = F_14 ( V_9 , 10 , & V_29 ) ;
if ( error )
return error ;
F_7 ( & V_17 -> V_20 ) ;
F_15 ( V_6 , L_3 , V_29 ) ;
if ( F_16 ( V_2 , V_29 ) ) {
V_26 = - V_24 ;
goto exit;
}
V_17 -> V_29 = V_29 ;
exit:
F_10 ( & V_17 -> V_20 ) ;
return V_26 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
T_2 V_32 )
{
struct V_16 * V_17 = F_17 ( V_2 ) ;
T_2 V_30 ;
V_30 = ( V_17 -> V_29 ) | ( V_32 << V_33 ) ;
if ( V_32 >= V_35 ) {
F_21 ( & V_2 -> V_6 ,
L_4 ) ;
return - V_24 ;
}
return F_2 ( V_2 , V_34 , V_30 ) ;
}
static T_3 F_22 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 , T_5 V_26 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
unsigned long V_32 = 0 ;
if ( strncmp ( V_9 , L_5 , 3 ) == 0 )
V_32 = V_36 ;
else if ( strncmp ( V_9 , L_6 , 1 ) == 0 )
V_32 = V_37 ;
else if ( strncmp ( V_9 , L_7 , 1 ) == 0 )
V_32 = V_38 ;
else if ( strncmp ( V_9 , L_8 , 1 ) == 0 )
V_32 = V_39 ;
else if ( strncmp ( V_9 , L_9 , 2 ) == 0 )
V_32 = V_40 ;
else if ( strncmp ( V_9 , L_10 , 2 ) == 0 )
V_32 = V_41 ;
else if ( strncmp ( V_9 , L_11 , 2 ) == 0 )
V_32 = V_42 ;
else
return - V_24 ;
F_7 ( & V_17 -> V_20 ) ;
F_15 ( V_6 , L_12 , V_32 ) ;
if ( F_20 ( V_2 , V_32 ) ) {
V_26 = - V_24 ;
goto exit;
}
V_17 -> V_32 = V_32 ;
exit:
F_10 ( & V_17 -> V_20 ) ;
return V_26 ;
}
static T_3 F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_14 * V_15 = F_6 ( V_8 ) ;
T_1 V_32 ;
V_32 = F_8 ( V_2 , V_15 -> V_23 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = ( V_32 & V_43 ) >> V_33 ;
return sprintf ( V_9 , L_13 , V_44 [ V_32 ] ) ;
}
static T_3 F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
T_2 V_45 ;
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
V_45 = V_17 -> V_45 ;
return sprintf ( V_9 , L_1 , V_46 [ V_45 ] ) ;
}
static T_3 F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * V_9 ,
T_5 V_26 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_11 -> V_6 . V_12 ) ;
struct V_14 * V_15 = F_6 ( V_8 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
unsigned long V_45 = 0 ;
int error ;
F_7 ( & V_17 -> V_20 ) ;
error = F_14 ( V_9 , 10 , & V_45 ) ;
if ( error ) {
V_26 = error ;
goto exit;
}
F_15 ( V_6 , L_14 , V_45 ) ;
if ( V_45 > V_47 ) {
V_26 = - V_24 ;
goto exit;
}
V_17 -> V_45 = V_45 ;
V_45 = V_45 << V_48 ;
if ( F_2 ( V_2 , V_15 -> V_23 , V_45 ) )
V_26 = - V_24 ;
exit:
F_10 ( & V_17 -> V_20 ) ;
return V_26 ;
}
static T_3 F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
return strlen ( strcpy ( V_9 , V_49 [ V_17 -> V_45 ] ) ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
unsigned char V_52 [ V_53 ] ;
if ( V_2 -> V_54 != V_55 )
return - V_56 ;
if ( F_28 ( V_2 , V_57 ,
V_53 , V_52 )
!= V_53 )
return - V_56 ;
if ( 0 != strncmp ( V_52 , V_58 , V_53 ) )
return - V_56 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_17 ( V_2 ) ;
F_16 ( V_2 , V_17 -> V_29 ) ;
F_20 ( V_2 , V_17 -> V_32 ) ;
F_1 ( V_2 , V_17 -> V_3 ) ;
F_2 ( V_2 , V_59 , V_17 -> V_45 ) ;
F_30 ( & V_17 -> V_20 ) ;
F_31 ( L_15 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_60 * V_61 )
{
struct V_16 * V_17 ;
int V_62 = 0 ;
V_17 = F_33 ( sizeof( struct V_16 ) , V_63 ) ;
if ( ! V_17 ) {
V_62 = - V_64 ;
goto exit;
}
V_17 -> V_29 = V_65 ;
V_17 -> V_45 = V_66 ;
V_17 -> V_3 = V_67 ;
F_34 ( V_2 , V_17 ) ;
F_29 ( V_2 ) ;
V_17 -> V_11 = F_35 ( 0 ) ;
if ( ! V_17 -> V_11 ) {
V_62 = - V_64 ;
goto V_68;
}
V_17 -> V_11 -> V_51 = & V_69 ;
V_17 -> V_11 -> V_6 . V_12 = & V_2 -> V_6 ;
V_17 -> V_11 -> V_18 = ( void * ) ( V_17 ) ;
V_17 -> V_11 -> V_70 = V_71 ;
V_62 = F_36 ( V_17 -> V_11 ) ;
if ( V_62 )
goto V_72;
return 0 ;
V_72:
F_37 ( V_17 -> V_11 ) ;
V_68:
F_38 ( V_17 ) ;
exit:
return V_62 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_17 ( V_2 ) ;
F_1 ( V_2 , V_28 ) ;
F_40 ( V_17 -> V_11 ) ;
F_38 ( F_17 ( V_2 ) ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_6 V_73 )
{
F_1 ( V_2 , V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_17 ( V_2 ) ;
F_1 ( V_2 , V_17 -> V_3 ) ;
return 0 ;
}
static int T_7 F_43 ( void )
{
return F_44 ( & V_74 ) ;
}
static void T_8 F_45 ( void )
{
F_46 ( & V_74 ) ;
}
