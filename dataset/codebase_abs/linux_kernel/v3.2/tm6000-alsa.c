static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( 1 , L_1 ) ;
F_3 ( V_4 , V_5 , 0x40 , 0x40 ) ;
F_4 ( V_4 , 48000 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( 1 , L_2 ) ;
F_3 ( V_4 , V_5 , 0x00 , 0x40 ) ;
return 0 ;
}
static void F_6 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
F_2 ( 2 , L_3 ) ;
F_8 ( V_7 -> V_8 -> V_9 ) ;
V_7 -> V_8 -> V_9 = NULL ;
V_7 -> V_8 -> V_10 = 0 ;
}
static int F_9 ( struct V_6 * V_7 , int V_11 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
F_2 ( 2 , L_4 ) ;
if ( V_7 -> V_8 -> V_9 ) {
if ( V_7 -> V_8 -> V_10 > V_11 )
return 0 ;
F_6 ( V_7 ) ;
}
V_7 -> V_8 -> V_9 = F_10 ( V_11 ) ;
if ( ! V_7 -> V_8 -> V_9 )
return - V_12 ;
V_7 -> V_8 -> V_10 = V_11 ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_13 * V_8 = V_7 -> V_8 ;
int V_14 ;
V_14 = F_12 ( V_8 , 0 ,
V_15 ) ;
if ( V_14 < 0 )
goto V_16;
V_2 -> V_7 = V_7 ;
V_8 -> V_17 = V_18 ;
return 0 ;
V_16:
F_2 ( 1 , L_5 ) ;
return V_14 ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_14 ( & V_4 -> V_19 ) > 0 ) {
F_15 ( & V_4 -> V_19 , 0 ) ;
F_16 ( & V_4 -> V_20 ) ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , char * V_21 , int V_11 )
{
struct V_1 * V_2 = V_4 -> V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_13 * V_8 ;
int V_23 = 0 ;
unsigned int V_24 , V_25 ;
int V_26 ;
if ( F_14 ( & V_4 -> V_19 ) == 0 )
return 0 ;
if ( ! V_11 || ! V_7 ) {
F_2 ( 1 , L_6 ) ;
return - V_27 ;
}
V_8 = V_7 -> V_8 ;
if ( ! V_8 || ! V_8 -> V_9 ) {
F_2 ( 1 , L_7 ) ;
return - V_27 ;
}
V_25 = V_2 -> V_25 ;
V_24 = V_8 -> V_28 >> 3 ;
if ( V_24 == 0 ) {
F_2 ( 1 , L_8 ) ;
return - V_27 ;
}
V_26 = V_11 / V_24 ;
if ( V_26 == 0 ) {
F_2 ( 1 , L_9 , V_29 ) ;
return - V_27 ;
}
F_2 ( 1 , L_10 , V_11 ,
V_8 -> V_9 , V_25 ,
( unsigned int ) V_8 -> V_30 , V_24 ) ;
if ( V_25 + V_26 >= V_8 -> V_30 ) {
unsigned int V_31 = V_8 -> V_30 - V_25 ;
memcpy ( V_8 -> V_9 + V_25 * V_24 , V_21 , V_31 * V_24 ) ;
memcpy ( V_8 -> V_9 , V_21 + V_31 * V_24 ,
V_26 * V_24 - V_31 * V_24 ) ;
} else
memcpy ( V_8 -> V_9 + V_25 * V_24 , V_21 ,
V_26 * V_24 ) ;
F_18 ( V_7 ) ;
V_2 -> V_25 += V_26 ;
if ( V_2 -> V_25 >= V_8 -> V_30 )
V_2 -> V_25 -= V_8 -> V_30 ;
V_2 -> V_32 += V_26 ;
if ( V_2 -> V_32 >= V_8 -> V_33 ) {
V_2 -> V_32 -= V_8 -> V_33 ;
V_23 = 1 ;
}
F_19 ( V_7 ) ;
if ( V_23 )
F_20 ( V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_34 * V_35 )
{
int V_11 , V_36 ;
V_11 = F_22 ( V_35 ) * F_23 ( V_35 ) ;
V_36 = F_9 ( V_7 , V_11 ) ;
if ( V_36 < 0 )
return V_36 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_14 ( & V_4 -> V_19 ) > 0 ) {
F_15 ( & V_4 -> V_19 , 0 ) ;
F_16 ( & V_4 -> V_20 ) ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_32 = 0 ;
return 0 ;
}
static void F_26 ( struct V_37 * V_38 )
{
struct V_3 * V_4 = F_27 ( V_38 , struct V_3 ,
V_20 ) ;
struct V_1 * V_2 = V_4 -> V_22 ;
if ( F_14 ( & V_4 -> V_19 ) ) {
F_2 ( 1 , L_11 ) ;
F_1 ( V_2 ) ;
} else {
F_2 ( 1 , L_12 ) ;
F_5 ( V_2 ) ;
}
}
static int F_28 ( struct V_6 * V_7 , int V_39 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_14 = 0 ;
switch ( V_39 ) {
case V_40 :
F_15 ( & V_4 -> V_19 , 1 ) ;
break;
case V_41 :
F_15 ( & V_4 -> V_19 , 0 ) ;
break;
default:
V_14 = - V_27 ;
break;
}
F_16 ( & V_4 -> V_20 ) ;
return V_14 ;
}
static T_1 F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_7 ( V_7 ) ;
return V_2 -> V_25 ;
}
static int F_30 ( struct V_3 * V_42 )
{
struct V_43 * V_44 ;
struct V_1 * V_2 ;
int V_36 ;
static int V_45 ;
char V_46 [ 14 ] ;
struct V_47 * V_48 ;
if ( ! V_42 )
return 0 ;
if ( V_45 >= V_49 )
return - V_50 ;
if ( ! V_51 [ V_45 ] )
return - V_52 ;
V_36 = F_31 ( V_53 [ V_45 ] , L_13 , V_54 , 0 , & V_44 ) ;
if ( V_36 < 0 ) {
F_32 ( V_55 L_14 , V_45 ) ;
return V_36 ;
}
strcpy ( V_44 -> V_56 , L_15 ) ;
strcpy ( V_44 -> V_57 , L_16 ) ;
sprintf ( V_44 -> V_58 , L_17 ,
V_42 -> V_59 -> V_60 -> V_61 , V_42 -> V_59 -> V_62 ) ;
sprintf ( V_46 , L_18 ,
F_33 ( V_42 -> V_59 -> V_63 . V_64 ) ,
F_33 ( V_42 -> V_59 -> V_63 . V_65 ) ) ;
F_34 ( V_44 , V_46 ) ;
F_35 ( V_44 , & V_42 -> V_59 -> V_42 ) ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_2 ) {
V_36 = - V_12 ;
goto error;
}
V_2 -> V_4 = V_42 ;
V_2 -> V_44 = V_44 ;
V_42 -> V_22 = V_2 ;
F_37 ( & V_2 -> V_67 ) ;
V_36 = F_38 ( V_44 , L_19 , 0 , 0 , 1 , & V_48 ) ;
if ( V_36 < 0 )
goto V_68;
V_48 -> V_69 = 0 ;
V_48 -> V_70 = V_2 ;
strcpy ( V_48 -> V_71 , L_20 ) ;
F_39 ( V_48 , V_72 , & V_73 ) ;
F_40 ( & V_42 -> V_20 , F_26 ) ;
V_36 = F_41 ( V_44 ) ;
if ( V_36 < 0 )
goto V_68;
F_2 ( 1 , L_21 , V_44 -> V_58 ) ;
return 0 ;
V_68:
F_42 ( V_2 ) ;
V_42 -> V_22 = NULL ;
error:
F_43 ( V_44 ) ;
return V_36 ;
}
static int F_44 ( struct V_3 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_22 ;
if ( ! V_42 )
return 0 ;
if ( ! V_2 )
return 0 ;
if ( ! V_2 -> V_44 )
return 0 ;
F_43 ( V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
F_42 ( V_2 ) ;
V_42 -> V_22 = NULL ;
return 0 ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_74 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_74 ) ;
}
