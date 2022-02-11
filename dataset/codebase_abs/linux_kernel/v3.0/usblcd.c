static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( V_3 -> V_4 ) ;
F_4 ( V_3 -> V_5 ) ;
F_4 ( V_3 ) ;
}
static int F_5 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
struct V_2 * V_3 ;
struct V_8 * V_9 ;
int V_10 , V_11 ;
F_6 ( & V_12 ) ;
V_10 = F_7 ( V_6 ) ;
V_9 = F_8 ( & V_13 , V_10 ) ;
if ( ! V_9 ) {
F_9 ( & V_12 ) ;
F_10 ( L_1 ,
V_14 , V_10 ) ;
return - V_15 ;
}
F_6 ( & V_16 ) ;
V_3 = F_11 ( V_9 ) ;
if ( ! V_3 ) {
F_9 ( & V_16 ) ;
F_9 ( & V_12 ) ;
return - V_15 ;
}
F_12 ( & V_3 -> V_1 ) ;
F_9 ( & V_16 ) ;
V_11 = F_13 ( V_9 ) ;
if ( V_11 < 0 ) {
F_14 ( & V_3 -> V_1 , F_1 ) ;
F_9 ( & V_12 ) ;
return V_11 ;
}
V_7 -> V_17 = V_3 ;
F_9 ( & V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
struct V_2 * V_3 ;
V_3 = V_7 -> V_17 ;
if ( V_3 == NULL )
return - V_15 ;
F_16 ( V_3 -> V_9 ) ;
F_14 ( & V_3 -> V_1 , F_1 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_7 * V_7 , char T_2 * V_18 , T_3 V_19 , T_4 * V_20 )
{
struct V_2 * V_3 ;
int V_21 = 0 ;
int V_22 ;
V_3 = V_7 -> V_17 ;
V_21 = F_18 ( V_3 -> V_4 ,
F_19 ( V_3 -> V_4 , V_3 -> V_23 ) ,
V_3 -> V_5 ,
F_20 ( V_3 -> V_24 , V_19 ) ,
& V_22 , 10000 ) ;
if ( ! V_21 ) {
if ( F_21 ( V_18 , V_3 -> V_5 , V_22 ) )
V_21 = - V_25 ;
else
V_21 = V_22 ;
}
return V_21 ;
}
static long F_22 ( struct V_7 * V_7 , unsigned int V_26 , unsigned long V_27 )
{
struct V_2 * V_3 ;
T_5 V_28 ;
char V_29 [ 30 ] ;
V_3 = V_7 -> V_17 ;
if ( V_3 == NULL )
return - V_15 ;
switch ( V_26 ) {
case V_30 :
F_6 ( & V_12 ) ;
V_28 = F_23 ( ( V_3 -> V_4 ) -> V_31 . V_28 ) ;
sprintf ( V_29 , L_2 ,
( V_28 & 0xF000 ) >> 12 ,
( V_28 & 0xF00 ) >> 8 ,
( V_28 & 0xF0 ) >> 4 ,
( V_28 & 0xF ) ) ;
F_9 ( & V_12 ) ;
if ( F_21 ( ( void T_2 * ) V_27 , V_29 , strlen ( V_29 ) ) != 0 )
return - V_25 ;
break;
case V_32 :
sprintf ( V_29 , V_33 ) ;
if ( F_21 ( ( void T_2 * ) V_27 , V_29 , strlen ( V_29 ) ) != 0 )
return - V_25 ;
break;
default:
return - V_34 ;
break;
}
return 0 ;
}
static void F_24 ( struct V_35 * V_35 )
{
struct V_2 * V_3 ;
int V_36 = V_35 -> V_36 ;
V_3 = V_35 -> V_37 ;
if ( V_36 &&
! ( V_36 == - V_38 ||
V_36 == - V_39 ||
V_36 == - V_40 ) ) {
F_25 ( L_3 ,
V_14 , V_36 ) ;
}
F_26 ( V_35 -> V_3 , V_35 -> V_41 ,
V_35 -> V_42 , V_35 -> V_43 ) ;
F_27 ( & V_3 -> V_44 ) ;
}
static T_1 F_28 ( struct V_7 * V_7 , const char T_2 * V_45 , T_3 V_19 , T_4 * V_20 )
{
struct V_2 * V_3 ;
int V_21 = 0 , V_11 ;
struct V_35 * V_35 = NULL ;
char * V_29 = NULL ;
V_3 = V_7 -> V_17 ;
if ( V_19 == 0 )
goto exit;
V_11 = F_29 ( & V_3 -> V_44 ) ;
if ( V_11 < 0 )
return - V_46 ;
V_35 = F_30 ( 0 , V_47 ) ;
if ( ! V_35 ) {
V_21 = - V_48 ;
goto V_49;
}
V_29 = F_31 ( V_3 -> V_4 , V_19 , V_47 , & V_35 -> V_43 ) ;
if ( ! V_29 ) {
V_21 = - V_48 ;
goto error;
}
if ( F_32 ( V_29 , V_45 , V_19 ) ) {
V_21 = - V_25 ;
goto error;
}
F_33 ( V_35 , V_3 -> V_4 ,
F_34 ( V_3 -> V_4 , V_3 -> V_50 ) ,
V_29 , V_19 , F_24 , V_3 ) ;
V_35 -> V_51 |= V_52 ;
F_35 ( V_35 , & V_3 -> V_53 ) ;
V_21 = F_36 ( V_35 , V_47 ) ;
if ( V_21 ) {
F_10 ( L_4 , V_14 , V_21 ) ;
goto V_54;
}
F_37 ( V_35 ) ;
exit:
return V_19 ;
V_54:
F_38 ( V_35 ) ;
error:
F_26 ( V_3 -> V_4 , V_19 , V_29 , V_35 -> V_43 ) ;
F_37 ( V_35 ) ;
V_49:
F_27 ( & V_3 -> V_44 ) ;
return V_21 ;
}
static int F_39 ( struct V_8 * V_9 , const struct V_55 * V_56 )
{
struct V_2 * V_3 = NULL ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
T_3 V_61 ;
int V_62 ;
int V_21 = - V_48 ;
V_3 = F_40 ( sizeof( * V_3 ) , V_47 ) ;
if ( V_3 == NULL ) {
F_10 ( L_5 ) ;
goto error;
}
F_41 ( & V_3 -> V_1 ) ;
F_42 ( & V_3 -> V_44 , V_63 ) ;
F_43 ( & V_3 -> V_53 ) ;
V_3 -> V_4 = F_44 ( F_45 ( V_9 ) ) ;
V_3 -> V_9 = V_9 ;
if ( F_23 ( V_3 -> V_4 -> V_31 . V_64 ) != 0x0001 ) {
F_46 ( & V_9 -> V_3 , L_6 ) ;
V_21 = - V_15 ;
goto error;
}
V_58 = V_9 -> V_65 ;
for ( V_62 = 0 ; V_62 < V_58 -> V_66 . V_67 ; ++ V_62 ) {
V_60 = & V_58 -> V_60 [ V_62 ] . V_66 ;
if ( ! V_3 -> V_23 &&
F_47 ( V_60 ) ) {
V_61 = F_23 ( V_60 -> V_68 ) ;
V_3 -> V_24 = V_61 ;
V_3 -> V_23 = V_60 -> V_69 ;
V_3 -> V_5 = F_48 ( V_61 , V_47 ) ;
if ( ! V_3 -> V_5 ) {
F_10 ( L_7 ) ;
goto error;
}
}
if ( ! V_3 -> V_50 &&
F_49 ( V_60 ) ) {
V_3 -> V_50 = V_60 -> V_69 ;
}
}
if ( ! ( V_3 -> V_23 && V_3 -> V_50 ) ) {
F_10 ( L_8 ) ;
goto error;
}
F_50 ( V_9 , V_3 ) ;
V_21 = F_51 ( V_9 , & V_70 ) ;
if ( V_21 ) {
F_10 ( L_9 ) ;
F_50 ( V_9 , NULL ) ;
goto error;
}
V_62 = F_23 ( V_3 -> V_4 -> V_31 . V_28 ) ;
F_52 ( & V_9 -> V_3 , L_10
L_11 , ( V_62 & 0xF000 ) >> 12 , ( V_62 & 0xF00 ) >> 8 ,
( V_62 & 0xF0 ) >> 4 , ( V_62 & 0xF ) , V_3 -> V_4 -> V_71 ) ;
F_52 ( & V_9 -> V_3 , L_12 ,
V_9 -> V_72 ) ;
return 0 ;
error:
if ( V_3 )
F_14 ( & V_3 -> V_1 , F_1 ) ;
return V_21 ;
}
static void F_53 ( struct V_2 * V_3 )
{
int time ;
time = F_54 ( & V_3 -> V_53 , 1000 ) ;
if ( ! time )
F_55 ( & V_3 -> V_53 ) ;
}
static int F_56 ( struct V_8 * V_73 , T_6 V_74 )
{
struct V_2 * V_3 = F_11 ( V_73 ) ;
if ( ! V_3 )
return 0 ;
F_53 ( V_3 ) ;
return 0 ;
}
static int F_57 ( struct V_8 * V_73 )
{
return 0 ;
}
static void F_58 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
int V_72 = V_9 -> V_72 ;
F_6 ( & V_16 ) ;
V_3 = F_11 ( V_9 ) ;
F_50 ( V_9 , NULL ) ;
F_9 ( & V_16 ) ;
F_59 ( V_9 , & V_70 ) ;
F_14 ( & V_3 -> V_1 , F_1 ) ;
F_52 ( & V_9 -> V_3 , L_13 , V_72 ) ;
}
static int T_7 F_60 ( void )
{
int V_75 ;
V_75 = F_61 ( & V_13 ) ;
if ( V_75 )
F_10 ( L_14 , V_75 ) ;
return V_75 ;
}
static void T_8 F_62 ( void )
{
F_63 ( & V_13 ) ;
}
