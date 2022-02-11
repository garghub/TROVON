static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return F_2 ( V_2 ,
V_4 ,
( V_3 & 0x03 ) ) ;
}
static int F_3 ( struct V_5 * V_6 ,
int V_7 ,
int * V_8 )
{
struct V_1 * V_2 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
T_1 V_13 ;
F_6 ( & V_12 -> V_14 ) ;
V_13 = F_7 ( V_2 , V_15 ) ;
while ( ! ( V_13 & V_16 ) )
V_13 = F_7 ( V_2 , V_15 ) ;
V_13 = F_8 ( V_2 , V_7 ) ;
F_9 ( & V_12 -> V_14 ) ;
if ( V_13 < 0 )
return - V_17 ;
* V_8 = ( V_18 ) F_10 ( ( V_19 ) V_13 ) ;
return V_20 ;
}
static T_3 F_11 ( struct V_21 * V_9 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
return sprintf ( V_24 , L_1 , V_12 -> V_3 ) ;
}
static T_3 F_13 ( struct V_21 * V_9 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_4 V_25 )
{
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_1 * V_2 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
struct V_26 * V_27 = F_14 ( V_23 ) ;
unsigned long V_3 = 0 ;
T_1 V_28 ;
int error ;
F_6 ( & V_12 -> V_14 ) ;
error = F_15 ( V_24 , 10 , & V_3 ) ;
if ( error ) {
V_25 = error ;
goto exit;
}
F_16 ( V_9 , L_2 , V_3 ) ;
if ( V_3 > V_29 ) {
V_25 = - V_17 ;
goto exit;
}
V_28 = F_2 ( V_2 , V_27 -> V_7 ,
V_3 ) ;
if ( V_28 ) {
V_25 = - V_17 ;
goto exit;
}
V_12 -> V_3 = V_3 ;
exit:
F_9 ( & V_12 -> V_14 ) ;
return V_25 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
T_2 V_30 )
{
struct V_11 * V_12 = F_18 ( V_2 ) ;
T_2 V_31 ;
V_31 = ( V_30 & V_32 ) | ( V_12 -> V_33 << V_34 ) ;
return F_2 ( V_2 , V_35 , V_31 ) ;
}
static T_3 F_19 ( struct V_21 * V_9 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
return sprintf ( V_24 , L_1 , V_12 -> V_30 ) ;
}
static T_3 F_20 ( struct V_21 * V_9 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_4 V_25 )
{
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_1 * V_2 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_11 * V_12 = F_18 ( V_2 ) ;
unsigned long V_30 = 0 ;
int error = F_15 ( V_24 , 10 , & V_30 ) ;
if ( error )
return error ;
F_6 ( & V_12 -> V_14 ) ;
F_16 ( V_9 , L_3 , V_30 ) ;
if ( F_17 ( V_2 , V_30 ) ) {
V_25 = - V_17 ;
goto exit;
}
V_12 -> V_30 = V_30 ;
exit:
F_9 ( & V_12 -> V_14 ) ;
return V_25 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
T_2 V_33 )
{
struct V_11 * V_12 = F_18 ( V_2 ) ;
T_2 V_31 ;
V_31 = ( V_12 -> V_30 ) | ( V_33 << V_34 ) ;
if ( V_33 >= V_36 ) {
F_22 ( & V_2 -> V_9 ,
L_4 ) ;
return - V_17 ;
}
return F_2 ( V_2 , V_35 , V_31 ) ;
}
static T_3 F_23 ( struct V_21 * V_9 ,
struct V_22 * V_23 ,
const char * V_24 , T_4 V_25 )
{
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_1 * V_2 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
unsigned long V_33 = 0 ;
if ( strncmp ( V_24 , L_5 , 3 ) == 0 )
V_33 = V_37 ;
else if ( strncmp ( V_24 , L_6 , 1 ) == 0 )
V_33 = V_38 ;
else if ( strncmp ( V_24 , L_7 , 1 ) == 0 )
V_33 = V_39 ;
else if ( strncmp ( V_24 , L_8 , 1 ) == 0 )
V_33 = V_40 ;
else if ( strncmp ( V_24 , L_9 , 2 ) == 0 )
V_33 = V_41 ;
else if ( strncmp ( V_24 , L_10 , 2 ) == 0 )
V_33 = V_42 ;
else if ( strncmp ( V_24 , L_11 , 2 ) == 0 )
V_33 = V_43 ;
else
return - V_17 ;
F_6 ( & V_12 -> V_14 ) ;
F_16 ( V_9 , L_12 , V_33 ) ;
if ( F_21 ( V_2 , V_33 ) ) {
V_25 = - V_17 ;
goto exit;
}
V_12 -> V_33 = V_33 ;
exit:
F_9 ( & V_12 -> V_14 ) ;
return V_25 ;
}
static T_3 F_24 ( struct V_21 * V_9 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_1 * V_2 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_26 * V_27 = F_14 ( V_23 ) ;
T_1 V_33 ;
V_33 = F_7 ( V_2 , V_27 -> V_7 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = ( V_33 & V_44 ) >> V_34 ;
return sprintf ( V_24 , L_13 , V_45 [ V_33 ] ) ;
}
static T_3 F_25 ( struct V_21 * V_9 ,
struct V_22 * V_23 ,
char * V_24 )
{
T_2 V_46 ;
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
V_46 = V_12 -> V_46 ;
return sprintf ( V_24 , L_1 , V_47 [ V_46 ] ) ;
}
static T_3 F_26 ( struct V_21 * V_9 ,
struct V_22 * V_23 ,
const char * V_24 ,
T_4 V_25 )
{
struct V_5 * V_6 = F_12 ( V_9 ) ;
struct V_1 * V_2 = F_4 ( V_6 -> V_9 . V_10 ) ;
struct V_26 * V_27 = F_14 ( V_23 ) ;
struct V_11 * V_12 = F_5 ( V_6 ) ;
unsigned long V_46 = 0 ;
int error ;
F_6 ( & V_12 -> V_14 ) ;
error = F_15 ( V_24 , 10 , & V_46 ) ;
if ( error ) {
V_25 = error ;
goto exit;
}
F_16 ( V_9 , L_14 , V_46 ) ;
if ( V_46 > V_48 ) {
V_25 = - V_17 ;
goto exit;
}
V_12 -> V_46 = V_46 ;
V_46 = V_46 << V_49 ;
if ( F_2 ( V_2 , V_27 -> V_7 , V_46 ) )
V_25 = - V_17 ;
exit:
F_9 ( & V_12 -> V_14 ) ;
return V_25 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_50 const * V_51 ,
int * V_8 , int * V_52 ,
long V_53 )
{
struct V_11 * V_12 = F_5 ( V_6 ) ;
switch ( V_53 ) {
case 0 :
return F_3 ( V_6 ,
V_51 -> V_7 ,
V_8 ) ;
case V_54 :
* V_8 = 0 ;
* V_52 = V_55 [ V_12 -> V_46 ] ;
return V_56 ;
} ;
return - V_17 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
unsigned char V_59 [ V_60 ] ;
if ( V_2 -> V_61 != V_62 )
return - V_63 ;
if ( F_29 ( V_2 , V_64 ,
V_60 , V_59 )
!= V_60 )
return - V_63 ;
if ( 0 != strncmp ( V_59 , V_65 , V_60 ) )
return - V_63 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_18 ( V_2 ) ;
F_17 ( V_2 , V_12 -> V_30 ) ;
F_21 ( V_2 , V_12 -> V_33 ) ;
F_1 ( V_2 , V_12 -> V_3 ) ;
F_2 ( V_2 , V_66 , V_12 -> V_46 ) ;
F_31 ( & V_12 -> V_14 ) ;
F_32 ( L_15 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
struct V_11 * V_12 ;
struct V_5 * V_6 ;
int V_69 = 0 ;
V_6 = F_34 ( sizeof( * V_12 ) ) ;
if ( V_6 == NULL ) {
V_69 = - V_70 ;
goto exit;
}
V_12 = F_5 ( V_6 ) ;
V_12 -> V_30 = V_71 ;
V_12 -> V_46 = V_72 ;
V_12 -> V_3 = V_73 ;
F_35 ( V_2 , V_6 ) ;
F_30 ( V_2 ) ;
V_6 -> V_58 = & V_74 ;
V_6 -> V_75 = V_68 -> V_75 ;
V_6 -> V_76 = V_77 ;
V_6 -> V_78 = F_36 ( V_77 ) ;
V_6 -> V_9 . V_10 = & V_2 -> V_9 ;
V_6 -> V_79 = V_80 ;
V_69 = F_37 ( V_6 ) ;
if ( V_69 )
goto V_81;
return 0 ;
V_81:
F_38 ( V_6 ) ;
exit:
return V_69 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
F_40 ( V_6 ) ;
F_1 ( V_2 , V_29 ) ;
F_38 ( V_6 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , T_5 V_82 )
{
F_1 ( V_2 , V_29 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_18 ( V_2 ) ;
F_1 ( V_2 , V_12 -> V_3 ) ;
return 0 ;
}
