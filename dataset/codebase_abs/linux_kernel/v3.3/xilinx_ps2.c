static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 ;
int V_5 = - 1 ;
V_4 = F_2 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 & V_8 ) {
* V_3 = F_2 ( V_2 -> V_6 + V_9 ) ;
V_5 = 0 ;
}
return V_5 ;
}
static T_3 F_3 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
T_2 V_12 ;
T_1 V_13 ;
int V_5 ;
V_12 = F_2 ( V_2 -> V_6 + V_14 ) ;
F_4 ( V_2 -> V_6 + V_14 , V_12 ) ;
if ( V_12 & V_15 )
F_5 ( V_2 -> V_16 . V_17 . V_18 , L_1 ) ;
if ( V_12 & V_19 )
V_2 -> V_20 |= V_21 ;
if ( V_12 & ( V_22 | V_23 ) )
V_2 -> V_20 |= V_24 ;
if ( V_12 & V_25 ) {
V_5 = F_1 ( V_2 , & V_13 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_16 . V_17 . V_18 ,
L_2 , V_5 ) ;
} else {
F_7 ( & V_2 -> V_16 , V_13 , V_2 -> V_20 ) ;
V_2 -> V_20 = 0 ;
}
}
return V_26 ;
}
static int F_8 ( struct V_16 * V_27 , unsigned char V_13 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
unsigned long V_20 ;
T_2 V_4 ;
int V_5 = - 1 ;
F_9 ( & V_2 -> V_29 , V_20 ) ;
V_4 = F_2 ( V_2 -> V_6 + V_7 ) ;
if ( ! ( V_4 & V_30 ) ) {
F_4 ( V_2 -> V_6 + V_31 , V_13 ) ;
V_5 = 0 ;
}
F_10 ( & V_2 -> V_29 , V_20 ) ;
return V_5 ;
}
static int F_11 ( struct V_16 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
int error ;
T_1 V_13 ;
error = F_12 ( V_2 -> V_10 , & F_3 , 0 ,
V_32 , V_2 ) ;
if ( error ) {
F_6 ( V_2 -> V_16 . V_17 . V_18 ,
L_3 , V_2 -> V_10 ) ;
return error ;
}
F_4 ( V_2 -> V_6 + V_33 , V_34 ) ;
F_4 ( V_2 -> V_6 + V_35 , V_36 ) ;
( void ) F_1 ( V_2 , & V_13 ) ;
return 0 ;
}
static void F_13 ( struct V_16 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_4 ( V_2 -> V_6 + V_33 , 0x00 ) ;
F_4 ( V_2 -> V_6 + V_35 , 0x00 ) ;
F_14 ( V_2 -> V_10 , V_2 ) ;
}
static int T_4 F_15 ( struct V_37 * V_38 )
{
struct V_39 V_40 ;
struct V_39 V_41 ;
struct V_1 * V_2 ;
struct V_16 * V_16 ;
struct V_42 * V_17 = & V_38 -> V_17 ;
T_5 V_43 , V_44 ;
int error ;
F_16 ( V_17 , L_4 ,
V_38 -> V_17 . V_45 -> V_46 ) ;
error = F_17 ( V_38 -> V_17 . V_45 , 0 , & V_41 ) ;
if ( error ) {
F_6 ( V_17 , L_5 ) ;
return error ;
}
if ( ! F_18 ( V_38 -> V_17 . V_45 , 0 , & V_40 ) ) {
F_6 ( V_17 , L_6 ) ;
return - V_47 ;
}
V_2 = F_19 ( sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_2 ) {
F_6 ( V_17 , L_7 ) ;
return - V_49 ;
}
F_20 ( V_17 , V_2 ) ;
F_21 ( & V_2 -> V_29 ) ;
V_2 -> V_10 = V_40 . V_50 ;
V_44 = V_41 . V_50 ;
V_43 = F_22 ( & V_41 ) ;
if ( ! F_23 ( V_44 , V_43 , V_32 ) ) {
F_6 ( V_17 , L_8 ,
( unsigned long long ) V_44 ) ;
error = - V_51 ;
goto V_52;
}
V_2 -> V_6 = F_24 ( V_44 , V_43 ) ;
if ( V_2 -> V_6 == NULL ) {
F_6 ( V_17 , L_9 ,
( unsigned long long ) V_44 ) ;
error = - V_53 ;
goto V_54;
}
F_4 ( V_2 -> V_6 + V_35 , 0 ) ;
F_4 ( V_2 -> V_6 + V_55 , V_56 ) ;
F_16 ( V_17 , L_10 ,
( unsigned long long ) V_44 , V_2 -> V_6 ,
V_2 -> V_10 ) ;
V_16 = & V_2 -> V_16 ;
V_16 -> V_57 . type = V_58 ;
V_16 -> V_59 = F_8 ;
V_16 -> V_60 = F_11 ;
V_16 -> V_61 = F_13 ;
V_16 -> V_28 = V_2 ;
V_16 -> V_17 . V_18 = V_17 ;
snprintf ( V_16 -> V_46 , sizeof( V_16 -> V_46 ) ,
L_11 , ( unsigned long long ) V_44 ) ;
snprintf ( V_16 -> V_62 , sizeof( V_16 -> V_62 ) ,
L_12 , ( unsigned long long ) V_44 ) ;
F_25 ( V_16 ) ;
return 0 ;
V_54:
F_26 ( V_44 , V_43 ) ;
V_52:
F_27 ( V_2 ) ;
F_20 ( V_17 , NULL ) ;
return error ;
}
static int T_6 F_28 ( struct V_37 * V_63 )
{
struct V_42 * V_17 = & V_63 -> V_17 ;
struct V_1 * V_2 = F_29 ( V_17 ) ;
struct V_39 V_41 ;
F_30 ( & V_2 -> V_16 ) ;
F_31 ( V_2 -> V_6 ) ;
if ( F_17 ( V_63 -> V_17 . V_45 , 0 , & V_41 ) )
F_6 ( V_17 , L_5 ) ;
else
F_26 ( V_41 . V_50 , F_22 ( & V_41 ) ) ;
F_27 ( V_2 ) ;
F_20 ( V_17 , NULL ) ;
return 0 ;
}
