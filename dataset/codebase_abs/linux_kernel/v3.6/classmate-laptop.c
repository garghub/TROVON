static int F_1 ( struct V_1 * V_2 , char * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
int error ;
V_6 = F_2 () ;
if ( ! V_6 )
return - V_7 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_8 . V_9 = & V_2 -> V_8 ;
V_4 ( V_6 ) ;
error = F_3 ( V_6 ) ;
if ( error ) {
F_4 ( V_6 ) ;
return error ;
}
F_5 ( & V_2 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_7 ( & V_2 -> V_8 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
static T_2 F_9 ( T_3 V_10 )
{
union V_11 V_12 [ 4 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x3 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = 0 ;
V_12 [ 2 ] . type = V_16 ;
V_12 [ 2 ] . integer . V_17 = 0 ;
V_12 [ 3 ] . type = V_16 ;
V_12 [ 3 ] . integer . V_17 = 0 ;
V_14 . V_18 = 4 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
return V_15 ;
}
static T_2 F_11 ( T_3 V_10 )
{
union V_11 V_12 [ 4 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x4 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = 0 ;
V_12 [ 2 ] . type = V_16 ;
V_12 [ 2 ] . integer . V_17 = 0 ;
V_12 [ 3 ] . type = V_16 ;
V_12 [ 3 ] . integer . V_17 = 0 ;
V_14 . V_18 = 4 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
return V_15 ;
}
static T_2 F_12 ( T_3 V_10 , int V_20 )
{
union V_11 V_12 [ 4 ] ;
struct V_13 V_14 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x02 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_20 ;
V_12 [ 2 ] . type = V_16 ;
V_12 [ 2 ] . integer . V_17 = 0 ;
V_12 [ 3 ] . type = V_16 ;
V_12 [ 3 ] . integer . V_17 = 0 ;
V_14 . V_18 = 4 ;
V_14 . V_19 = V_12 ;
return F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
}
static T_2 F_13 ( T_3 V_10 , int V_20 )
{
union V_11 V_12 [ 4 ] ;
struct V_13 V_14 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x05 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_20 ;
V_12 [ 2 ] . type = V_16 ;
V_12 [ 2 ] . integer . V_17 = 0 ;
V_12 [ 3 ] . type = V_16 ;
V_12 [ 3 ] . integer . V_17 = 0 ;
V_14 . V_18 = 4 ;
V_14 . V_19 = V_12 ;
return F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
}
static T_2 F_14 ( T_3 V_10 ,
T_4 * V_21 ,
T_4 * V_22 ,
T_4 * V_23 )
{
union V_11 V_12 [ 4 ] ;
struct V_13 V_14 ;
struct V_24 V_25 = { V_26 , NULL } ;
T_4 * V_27 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x01 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = 0 ;
V_12 [ 2 ] . type = V_16 ;
V_12 [ 2 ] . integer . V_17 = 0 ;
V_12 [ 3 ] . type = V_16 ;
V_12 [ 3 ] . integer . V_17 = 0 ;
V_14 . V_18 = 4 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , & V_25 ) ;
if ( F_15 ( V_15 ) ) {
union V_11 * V_28 ;
V_28 = V_25 . V_19 ;
V_27 = ( T_4 * ) V_28 -> V_29 . V_19 ;
* V_21 = V_27 [ 0 ] ;
* V_22 = V_27 [ 1 ] ;
* V_23 = V_27 [ 2 ] ;
F_16 ( V_25 . V_19 ) ;
}
return V_15 ;
}
static void F_17 ( struct V_1 * V_8 , T_5 V_30 )
{
if ( V_30 == 0x81 ) {
T_4 V_21 , V_22 , V_23 ;
T_2 V_15 ;
V_15 = F_14 ( V_8 -> V_10 , & V_21 , & V_22 , & V_23 ) ;
if ( F_15 ( V_15 ) ) {
struct V_5 * V_6 = F_7 ( & V_8 -> V_8 ) ;
F_18 ( V_6 , V_31 , V_21 ) ;
F_18 ( V_6 , V_32 , V_22 ) ;
F_18 ( V_6 , V_33 , V_23 ) ;
F_19 ( V_6 ) ;
}
}
}
static T_6 F_20 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_2 = F_21 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
return sprintf ( V_37 , L_2 , V_39 -> V_40 ) ;
}
static T_6 F_22 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
const char * V_37 , T_7 V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
unsigned long V_40 ;
int V_41 ;
V_2 = F_21 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
V_41 = F_23 ( V_37 , 0 , & V_40 ) ;
if ( V_41 )
return V_41 ;
if ( V_40 < 1 || V_40 > 127 )
return - V_42 ;
V_39 -> V_40 = V_40 ;
F_12 ( V_2 -> V_10 , V_40 ) ;
return F_24 ( V_37 , V_18 ) ;
}
static T_6 F_25 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_2 = F_21 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
return sprintf ( V_37 , L_2 , V_39 -> V_43 ) ;
}
static T_6 F_26 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
const char * V_37 , T_7 V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
unsigned long V_43 ;
int V_41 ;
V_2 = F_21 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
V_41 = F_23 ( V_37 , 0 , & V_43 ) ;
if ( V_41 )
return V_41 ;
if ( V_43 != 0 && V_43 != 1 )
return - V_42 ;
V_39 -> V_43 = V_43 ;
F_13 ( V_2 -> V_10 , V_43 ) ;
return F_24 ( V_37 , V_18 ) ;
}
static int F_27 ( struct V_5 * V_14 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
V_2 = F_21 ( V_14 -> V_8 . V_9 ) ;
V_39 = F_7 ( & V_14 -> V_8 ) ;
F_12 ( V_2 -> V_10 , V_39 -> V_40 ) ;
F_13 ( V_2 -> V_10 , V_39 -> V_43 ) ;
if ( F_15 ( F_9 ( V_2 -> V_10 ) ) ) {
V_39 -> V_44 = V_45 ;
return 0 ;
}
return - V_46 ;
}
static void F_28 ( struct V_5 * V_14 )
{
struct V_1 * V_2 ;
struct V_38 * V_39 ;
V_2 = F_21 ( V_14 -> V_8 . V_9 ) ;
V_39 = F_7 ( & V_14 -> V_8 ) ;
F_11 ( V_2 -> V_10 ) ;
V_39 -> V_44 = V_47 ;
}
static void F_29 ( struct V_5 * V_6 )
{
F_30 ( V_48 , V_6 -> V_49 ) ;
F_31 ( V_6 , V_31 , - 255 , 255 , 16 , 0 ) ;
F_31 ( V_6 , V_32 , - 255 , 255 , 16 , 0 ) ;
F_31 ( V_6 , V_33 , - 255 , 255 , 16 , 0 ) ;
V_6 -> V_50 = F_27 ;
V_6 -> V_51 = F_28 ;
}
static int F_32 ( struct V_34 * V_8 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_6 = F_7 ( V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
if ( V_39 -> V_44 == V_45 )
return F_11 ( F_21 ( V_8 ) -> V_10 ) ;
return 0 ;
}
static int F_33 ( struct V_34 * V_8 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_6 = F_7 ( V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
if ( V_39 -> V_44 == V_45 ) {
F_12 ( F_21 ( V_8 ) -> V_10 ,
V_39 -> V_40 ) ;
F_13 ( F_21 ( V_8 ) -> V_10 ,
V_39 -> V_43 ) ;
if ( F_34 ( F_9 ( F_21 ( V_8 ) -> V_10 ) ) )
return - V_46 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int error ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_39 = F_36 ( sizeof( * V_39 ) , V_52 ) ;
if ( ! V_39 )
return - V_7 ;
V_39 -> V_44 = V_47 ;
V_39 -> V_40 = V_53 ;
F_12 ( V_2 -> V_10 , V_39 -> V_40 ) ;
error = F_37 ( & V_2 -> V_8 , & V_54 ) ;
if ( error )
goto V_55;
V_39 -> V_43 = V_56 ;
F_13 ( V_2 -> V_10 , V_39 -> V_43 ) ;
error = F_37 ( & V_2 -> V_8 , & V_57 ) ;
if ( error )
goto V_58;
error = F_1 ( V_2 , L_3 ,
F_29 ) ;
if ( error )
goto V_59;
V_6 = F_7 ( & V_2 -> V_8 ) ;
F_5 ( & V_6 -> V_8 , V_39 ) ;
return 0 ;
V_59:
F_38 ( & V_2 -> V_8 , & V_57 ) ;
V_58:
F_38 ( & V_2 -> V_8 , & V_54 ) ;
V_55:
F_16 ( V_39 ) ;
return error ;
}
static int F_39 ( struct V_1 * V_2 , int type )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
F_38 ( & V_2 -> V_8 , & V_54 ) ;
F_38 ( & V_2 -> V_8 , & V_57 ) ;
return F_6 ( V_2 ) ;
}
static T_2 F_40 ( T_3 V_10 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x3 ;
V_12 [ 1 ] . type = V_16 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
return V_15 ;
}
static T_2 F_41 ( T_3 V_10 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x4 ;
V_12 [ 1 ] . type = V_16 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
return V_15 ;
}
static T_2 F_42 ( T_3 V_10 , int V_20 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x02 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_20 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
return F_10 ( V_10 , L_1 , & V_14 , NULL ) ;
}
static T_2 F_43 ( T_3 V_10 ,
unsigned char * V_21 ,
unsigned char * V_22 ,
unsigned char * V_23 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
struct V_24 V_25 = { V_26 , 0 } ;
unsigned char * V_27 ;
T_2 V_15 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0x01 ;
V_12 [ 1 ] . type = V_16 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_10 ( V_10 , L_1 , & V_14 , & V_25 ) ;
if ( F_15 ( V_15 ) ) {
union V_11 * V_28 ;
V_28 = V_25 . V_19 ;
V_27 = V_28 -> V_29 . V_19 ;
* V_21 = V_27 [ 0 ] ;
* V_22 = V_27 [ 1 ] ;
* V_23 = V_27 [ 2 ] ;
F_16 ( V_25 . V_19 ) ;
}
return V_15 ;
}
static void F_44 ( struct V_1 * V_8 , T_5 V_30 )
{
if ( V_30 == 0x81 ) {
unsigned char V_21 , V_22 , V_23 ;
T_2 V_15 ;
V_15 = F_43 ( V_8 -> V_10 , & V_21 , & V_22 , & V_23 ) ;
if ( F_15 ( V_15 ) ) {
struct V_5 * V_6 = F_7 ( & V_8 -> V_8 ) ;
F_18 ( V_6 , V_31 , V_21 ) ;
F_18 ( V_6 , V_32 , V_22 ) ;
F_18 ( V_6 , V_33 , V_23 ) ;
F_19 ( V_6 ) ;
}
}
}
static T_6 F_45 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
char * V_37 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_2 = F_21 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
return sprintf ( V_37 , L_2 , V_39 -> V_40 ) ;
}
static T_6 F_46 ( struct V_34 * V_8 ,
struct V_35 * V_36 ,
const char * V_37 , T_7 V_18 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
unsigned long V_40 ;
int V_41 ;
V_2 = F_21 ( V_8 ) ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
V_41 = F_47 ( V_37 , 0 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_39 -> V_40 = V_40 ;
F_42 ( V_2 -> V_10 , V_40 ) ;
return F_24 ( V_37 , V_18 ) ;
}
static int F_48 ( struct V_5 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_14 -> V_8 . V_9 ) ;
if ( F_15 ( F_40 ( V_2 -> V_10 ) ) )
return 0 ;
return - V_46 ;
}
static void F_49 ( struct V_5 * V_14 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_14 -> V_8 . V_9 ) ;
F_41 ( V_2 -> V_10 ) ;
}
static void F_50 ( struct V_5 * V_6 )
{
F_30 ( V_48 , V_6 -> V_49 ) ;
F_31 ( V_6 , V_31 , 0 , 255 , 8 , 0 ) ;
F_31 ( V_6 , V_32 , 0 , 255 , 8 , 0 ) ;
F_31 ( V_6 , V_33 , 0 , 255 , 8 , 0 ) ;
V_6 -> V_50 = F_48 ;
V_6 -> V_51 = F_49 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int error ;
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_39 = F_36 ( sizeof( * V_39 ) , V_52 ) ;
if ( ! V_39 )
return - V_7 ;
V_39 -> V_40 = V_53 ;
F_42 ( V_2 -> V_10 , V_39 -> V_40 ) ;
error = F_37 ( & V_2 -> V_8 , & V_60 ) ;
if ( error )
goto V_61;
error = F_1 ( V_2 , L_4 ,
F_50 ) ;
if ( error )
goto V_59;
V_6 = F_7 ( & V_2 -> V_8 ) ;
F_5 ( & V_6 -> V_8 , V_39 ) ;
return 0 ;
V_59:
F_38 ( & V_2 -> V_8 , & V_60 ) ;
V_61:
F_16 ( V_39 ) ;
return error ;
}
static int F_52 ( struct V_1 * V_2 , int type )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
V_6 = F_7 ( & V_2 -> V_8 ) ;
V_39 = F_7 ( & V_6 -> V_8 ) ;
F_38 ( & V_2 -> V_8 , & V_60 ) ;
return F_6 ( V_2 ) ;
}
static T_2 F_53 ( T_3 V_10 ,
unsigned long long * V_17 )
{
union V_11 V_12 ;
struct V_13 V_14 ;
unsigned long long V_25 ;
T_2 V_15 ;
V_12 . type = V_16 ;
V_12 . integer . V_17 = 0x01 ;
V_14 . V_18 = 1 ;
V_14 . V_19 = & V_12 ;
V_15 = F_54 ( V_10 , L_5 , & V_14 , & V_25 ) ;
if ( F_15 ( V_15 ) )
* V_17 = V_25 ;
return V_15 ;
}
static void F_55 ( struct V_1 * V_8 , T_5 V_30 )
{
unsigned long long V_20 = 0 ;
struct V_5 * V_6 = F_7 ( & V_8 -> V_8 ) ;
if ( V_30 == 0x81 ) {
if ( F_15 ( F_53 ( V_8 -> V_10 , & V_20 ) ) ) {
F_56 ( V_6 , V_62 , ! V_20 ) ;
F_19 ( V_6 ) ;
}
}
}
static void F_57 ( struct V_5 * V_6 )
{
unsigned long long V_20 = 0 ;
struct V_1 * V_2 ;
F_30 ( V_63 , V_6 -> V_49 ) ;
F_30 ( V_62 , V_6 -> V_64 ) ;
V_2 = F_21 ( V_6 -> V_8 . V_9 ) ;
if ( F_15 ( F_53 ( V_2 -> V_10 , & V_20 ) ) ) {
F_56 ( V_6 , V_62 , ! V_20 ) ;
F_19 ( V_6 ) ;
}
}
static int F_58 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , L_6 ,
F_57 ) ;
}
static int F_59 ( struct V_1 * V_2 , int type )
{
return F_6 ( V_2 ) ;
}
static int F_60 ( struct V_34 * V_8 )
{
struct V_5 * V_6 = F_7 ( V_8 ) ;
unsigned long long V_20 = 0 ;
if ( F_15 ( F_53 ( F_21 ( V_8 ) -> V_10 , & V_20 ) ) ) {
F_56 ( V_6 , V_62 , ! V_20 ) ;
F_19 ( V_6 ) ;
}
return 0 ;
}
static T_2 F_61 ( T_3 V_10 ,
unsigned long long * V_17 )
{
union V_11 V_12 ;
struct V_13 V_14 ;
unsigned long long V_25 ;
T_2 V_15 ;
V_12 . type = V_16 ;
V_12 . integer . V_17 = 0xC0 ;
V_14 . V_18 = 1 ;
V_14 . V_19 = & V_12 ;
V_15 = F_54 ( V_10 , L_7 , & V_14 , & V_25 ) ;
if ( F_15 ( V_15 ) )
* V_17 = V_25 ;
return V_15 ;
}
static T_2 F_62 ( T_3 V_10 ,
unsigned long long V_17 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
unsigned long long V_25 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0xC0 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_17 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_54 ( V_10 , L_8 , & V_14 , & V_25 ) ;
return V_15 ;
}
static int F_63 ( struct V_65 * V_66 )
{
T_2 V_15 ;
T_3 V_10 ;
unsigned long long V_67 ;
V_10 = F_64 ( V_66 ) ;
V_15 = F_61 ( V_10 , & V_67 ) ;
if ( F_15 ( V_15 ) )
return V_67 ;
else
return - 1 ;
}
static int F_65 ( struct V_65 * V_66 )
{
T_2 V_15 ;
T_3 V_10 ;
V_10 = F_64 ( V_66 ) ;
V_15 = F_62 ( V_10 , V_66 -> V_68 . V_67 ) ;
if ( F_15 ( V_15 ) )
return 0 ;
else
return - 1 ;
}
static T_2 F_66 ( T_3 V_10 ,
unsigned long long * V_17 )
{
union V_11 V_12 ;
struct V_13 V_14 ;
unsigned long long V_25 ;
T_2 V_15 ;
V_12 . type = V_16 ;
V_12 . integer . V_17 = 0xC1 ;
V_14 . V_18 = 1 ;
V_14 . V_19 = & V_12 ;
V_15 = F_54 ( V_10 , L_7 , & V_14 , & V_25 ) ;
if ( F_15 ( V_15 ) )
* V_17 = V_25 ;
return V_15 ;
}
static T_2 F_67 ( T_3 V_10 ,
unsigned long long V_17 )
{
union V_11 V_12 [ 2 ] ;
struct V_13 V_14 ;
T_2 V_15 ;
unsigned long long V_25 ;
V_12 [ 0 ] . type = V_16 ;
V_12 [ 0 ] . integer . V_17 = 0xC1 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . integer . V_17 = V_17 ;
V_14 . V_18 = 2 ;
V_14 . V_19 = V_12 ;
V_15 = F_54 ( V_10 , L_8 , & V_14 , & V_25 ) ;
return V_15 ;
}
static void F_68 ( struct V_69 * V_69 , void * V_70 )
{
T_2 V_15 ;
T_3 V_10 ;
unsigned long long V_71 ;
bool V_72 ;
V_10 = V_70 ;
V_15 = F_66 ( V_10 , & V_71 ) ;
if ( F_15 ( V_15 ) ) {
V_72 = V_71 & 1 ? false : true ;
F_69 ( V_69 , V_72 ) ;
}
}
static int F_70 ( void * V_70 , bool V_72 )
{
T_2 V_15 ;
T_3 V_10 ;
unsigned long long V_71 ;
bool V_73 ;
V_10 = V_70 ;
V_15 = F_66 ( V_10 , & V_71 ) ;
if ( F_34 ( V_15 ) )
return - V_74 ;
V_73 = V_71 & 1 ? false : true ;
if ( V_73 != V_72 ) {
V_71 = V_72 ? 0 : 1 ;
V_15 = F_67 ( V_10 , V_71 ) ;
if ( F_34 ( V_15 ) )
return - V_74 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_75 ;
struct V_76 * V_77 ;
struct V_78 V_68 ;
V_77 = F_36 ( sizeof( * V_77 ) , V_52 ) ;
if ( V_77 == NULL )
return - V_7 ;
memset ( & V_68 , 0 , sizeof( struct V_78 ) ) ;
V_68 . type = V_79 ;
V_68 . V_80 = 7 ;
V_77 -> V_66 = F_72 ( L_9 , & V_2 -> V_8 ,
V_2 -> V_10 , & V_81 ,
& V_68 ) ;
if ( F_73 ( V_77 -> V_66 ) ) {
V_75 = F_74 ( V_77 -> V_66 ) ;
goto V_82;
}
V_77 -> V_83 = F_75 ( L_10 , & V_2 -> V_8 , V_84 ,
& V_85 , V_2 -> V_10 ) ;
if ( V_77 -> V_83 ) {
V_75 = F_76 ( V_77 -> V_83 ) ;
if ( V_75 ) {
F_77 ( V_77 -> V_83 ) ;
V_77 -> V_83 = NULL ;
}
}
F_5 ( & V_2 -> V_8 , V_77 ) ;
return 0 ;
V_82:
F_16 ( V_77 ) ;
return V_75 ;
}
static int F_78 ( struct V_1 * V_2 , int type )
{
struct V_76 * V_77 ;
V_77 = F_7 ( & V_2 -> V_8 ) ;
F_79 ( V_77 -> V_66 ) ;
if ( V_77 -> V_83 ) {
F_80 ( V_77 -> V_83 ) ;
F_77 ( V_77 -> V_83 ) ;
}
F_16 ( V_77 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_8 , T_5 V_30 )
{
struct V_5 * V_6 ;
int V_86 = V_87 ;
if ( ( V_30 & 0x0F ) < F_82 ( V_88 ) )
V_86 = V_88 [ V_30 & 0x0F ] ;
V_6 = F_7 ( & V_8 -> V_8 ) ;
F_83 ( V_6 , V_86 , ! ( V_30 & 0x10 ) ) ;
F_19 ( V_6 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
int V_89 ;
F_30 ( V_90 , V_6 -> V_49 ) ;
for ( V_89 = 0 ; V_88 [ V_89 ] != V_87 ; V_89 ++ )
F_30 ( V_88 [ V_89 ] , V_6 -> V_91 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , L_11 ,
F_84 ) ;
}
static int F_86 ( struct V_1 * V_2 , int type )
{
return F_6 ( V_2 ) ;
}
static int F_87 ( void )
{
int V_41 ;
V_41 = F_88 ( & V_92 ) ;
if ( V_41 )
goto V_93;
V_41 = F_88 ( & V_94 ) ;
if ( V_41 )
goto V_95;
V_41 = F_88 ( & V_96 ) ;
if ( V_41 )
goto V_97;
V_41 = F_88 ( & V_98 ) ;
if ( V_41 )
goto V_99;
V_41 = F_88 ( & V_100 ) ;
if ( V_41 )
goto V_101;
return V_41 ;
V_101:
F_89 ( & V_98 ) ;
V_99:
F_89 ( & V_96 ) ;
V_97:
F_89 ( & V_94 ) ;
V_95:
F_89 ( & V_92 ) ;
V_93:
return V_41 ;
}
static void F_90 ( void )
{
F_89 ( & V_100 ) ;
F_89 ( & V_98 ) ;
F_89 ( & V_96 ) ;
F_89 ( & V_94 ) ;
F_89 ( & V_92 ) ;
}
