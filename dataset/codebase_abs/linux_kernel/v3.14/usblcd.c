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
F_10 ( V_14 L_1 ,
V_15 , V_10 ) ;
return - V_16 ;
}
F_6 ( & V_17 ) ;
V_3 = F_11 ( V_9 ) ;
if ( ! V_3 ) {
F_9 ( & V_17 ) ;
F_9 ( & V_12 ) ;
return - V_16 ;
}
F_12 ( & V_3 -> V_1 ) ;
F_9 ( & V_17 ) ;
V_11 = F_13 ( V_9 ) ;
if ( V_11 < 0 ) {
F_14 ( & V_3 -> V_1 , F_1 ) ;
F_9 ( & V_12 ) ;
return V_11 ;
}
V_7 -> V_18 = V_3 ;
F_9 ( & V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
struct V_2 * V_3 ;
V_3 = V_7 -> V_18 ;
if ( V_3 == NULL )
return - V_16 ;
F_16 ( V_3 -> V_9 ) ;
F_14 ( & V_3 -> V_1 , F_1 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_7 * V_7 , char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_2 * V_3 ;
int V_22 = 0 ;
int V_23 ;
V_3 = V_7 -> V_18 ;
V_22 = F_18 ( V_3 -> V_4 ,
F_19 ( V_3 -> V_4 ,
V_3 -> V_24 ) ,
V_3 -> V_5 ,
F_20 ( V_3 -> V_25 , V_20 ) ,
& V_23 , 10000 ) ;
if ( ! V_22 ) {
if ( F_21 ( V_19 , V_3 -> V_5 , V_23 ) )
V_22 = - V_26 ;
else
V_22 = V_23 ;
}
return V_22 ;
}
static long F_22 ( struct V_7 * V_7 , unsigned int V_27 , unsigned long V_28 )
{
struct V_2 * V_3 ;
T_5 V_29 ;
char V_30 [ 30 ] ;
V_3 = V_7 -> V_18 ;
if ( V_3 == NULL )
return - V_16 ;
switch ( V_27 ) {
case V_31 :
F_6 ( & V_12 ) ;
V_29 = F_23 ( ( V_3 -> V_4 ) -> V_32 . V_29 ) ;
sprintf ( V_30 , L_2 ,
( V_29 & 0xF000 ) >> 12 ,
( V_29 & 0xF00 ) >> 8 ,
( V_29 & 0xF0 ) >> 4 ,
( V_29 & 0xF ) ) ;
F_9 ( & V_12 ) ;
if ( F_21 ( ( void T_2 * ) V_28 , V_30 , strlen ( V_30 ) ) != 0 )
return - V_26 ;
break;
case V_33 :
sprintf ( V_30 , V_34 ) ;
if ( F_21 ( ( void T_2 * ) V_28 , V_30 , strlen ( V_30 ) ) != 0 )
return - V_26 ;
break;
default:
return - V_35 ;
break;
}
return 0 ;
}
static void F_24 ( struct V_36 * V_36 )
{
struct V_2 * V_3 ;
int V_37 = V_36 -> V_37 ;
V_3 = V_36 -> V_38 ;
if ( V_37 &&
! ( V_37 == - V_39 ||
V_37 == - V_40 ||
V_37 == - V_41 ) ) {
F_25 ( & V_3 -> V_9 -> V_3 ,
L_3 , V_37 ) ;
}
F_26 ( V_36 -> V_3 , V_36 -> V_42 ,
V_36 -> V_43 , V_36 -> V_44 ) ;
F_27 ( & V_3 -> V_45 ) ;
}
static T_1 F_28 ( struct V_7 * V_7 , const char T_2 * V_46 ,
T_3 V_20 , T_4 * V_21 )
{
struct V_2 * V_3 ;
int V_22 = 0 , V_11 ;
struct V_36 * V_36 = NULL ;
char * V_30 = NULL ;
V_3 = V_7 -> V_18 ;
if ( V_20 == 0 )
goto exit;
V_11 = F_29 ( & V_3 -> V_45 ) ;
if ( V_11 < 0 )
return - V_47 ;
V_36 = F_30 ( 0 , V_48 ) ;
if ( ! V_36 ) {
V_22 = - V_49 ;
goto V_50;
}
V_30 = F_31 ( V_3 -> V_4 , V_20 , V_48 ,
& V_36 -> V_44 ) ;
if ( ! V_30 ) {
V_22 = - V_49 ;
goto error;
}
if ( F_32 ( V_30 , V_46 , V_20 ) ) {
V_22 = - V_26 ;
goto error;
}
F_33 ( V_36 , V_3 -> V_4 ,
F_34 ( V_3 -> V_4 ,
V_3 -> V_51 ) ,
V_30 , V_20 , F_24 , V_3 ) ;
V_36 -> V_52 |= V_53 ;
F_35 ( V_36 , & V_3 -> V_54 ) ;
V_22 = F_36 ( V_36 , V_48 ) ;
if ( V_22 ) {
F_37 ( & V_3 -> V_4 -> V_3 ,
L_4 ,
V_15 , V_22 ) ;
goto V_55;
}
F_38 ( V_36 ) ;
exit:
return V_20 ;
V_55:
F_39 ( V_36 ) ;
error:
F_26 ( V_3 -> V_4 , V_20 , V_30 , V_36 -> V_44 ) ;
F_38 ( V_36 ) ;
V_50:
F_27 ( & V_3 -> V_45 ) ;
return V_22 ;
}
static int F_40 ( struct V_8 * V_9 ,
const struct V_56 * V_57 )
{
struct V_2 * V_3 = NULL ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_3 V_62 ;
int V_63 ;
int V_22 = - V_49 ;
V_3 = F_41 ( sizeof( * V_3 ) , V_48 ) ;
if ( V_3 == NULL ) {
F_37 ( & V_9 -> V_3 , L_5 ) ;
goto error;
}
F_42 ( & V_3 -> V_1 ) ;
F_43 ( & V_3 -> V_45 , V_64 ) ;
F_44 ( & V_3 -> V_54 ) ;
V_3 -> V_4 = F_45 ( F_46 ( V_9 ) ) ;
V_3 -> V_9 = V_9 ;
if ( F_23 ( V_3 -> V_4 -> V_32 . V_65 ) != 0x0001 ) {
F_47 ( & V_9 -> V_3 , L_6 ) ;
V_22 = - V_16 ;
goto error;
}
V_59 = V_9 -> V_66 ;
for ( V_63 = 0 ; V_63 < V_59 -> V_67 . V_68 ; ++ V_63 ) {
V_61 = & V_59 -> V_61 [ V_63 ] . V_67 ;
if ( ! V_3 -> V_24 &&
F_48 ( V_61 ) ) {
V_62 = F_49 ( V_61 ) ;
V_3 -> V_25 = V_62 ;
V_3 -> V_24 = V_61 -> V_69 ;
V_3 -> V_5 = F_50 ( V_62 , V_48 ) ;
if ( ! V_3 -> V_5 ) {
F_37 ( & V_9 -> V_3 ,
L_7 ) ;
goto error;
}
}
if ( ! V_3 -> V_51 &&
F_51 ( V_61 ) ) {
V_3 -> V_51 = V_61 -> V_69 ;
}
}
if ( ! ( V_3 -> V_24 && V_3 -> V_51 ) ) {
F_37 ( & V_9 -> V_3 ,
L_8 ) ;
goto error;
}
F_52 ( V_9 , V_3 ) ;
V_22 = F_53 ( V_9 , & V_70 ) ;
if ( V_22 ) {
F_37 ( & V_9 -> V_3 ,
L_9 ) ;
F_52 ( V_9 , NULL ) ;
goto error;
}
V_63 = F_23 ( V_3 -> V_4 -> V_32 . V_29 ) ;
F_54 ( & V_9 -> V_3 , L_10
L_11 , ( V_63 & 0xF000 ) >> 12 , ( V_63 & 0xF00 ) >> 8 ,
( V_63 & 0xF0 ) >> 4 , ( V_63 & 0xF ) , V_3 -> V_4 -> V_71 ) ;
F_54 ( & V_9 -> V_3 , L_12 ,
V_9 -> V_72 ) ;
return 0 ;
error:
if ( V_3 )
F_14 ( & V_3 -> V_1 , F_1 ) ;
return V_22 ;
}
static void F_55 ( struct V_2 * V_3 )
{
int time ;
time = F_56 ( & V_3 -> V_54 , 1000 ) ;
if ( ! time )
F_57 ( & V_3 -> V_54 ) ;
}
static int F_58 ( struct V_8 * V_73 , T_6 V_74 )
{
struct V_2 * V_3 = F_11 ( V_73 ) ;
if ( ! V_3 )
return 0 ;
F_55 ( V_3 ) ;
return 0 ;
}
static int F_59 ( struct V_8 * V_73 )
{
return 0 ;
}
static void F_60 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
int V_72 = V_9 -> V_72 ;
F_6 ( & V_17 ) ;
V_3 = F_11 ( V_9 ) ;
F_52 ( V_9 , NULL ) ;
F_9 ( & V_17 ) ;
F_61 ( V_9 , & V_70 ) ;
F_14 ( & V_3 -> V_1 , F_1 ) ;
F_54 ( & V_9 -> V_3 , L_13 , V_72 ) ;
}
