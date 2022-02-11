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
F_5 ( V_2 -> V_16 , L_1 ) ;
if ( V_12 & V_17 )
V_2 -> V_18 |= V_19 ;
if ( V_12 & ( V_20 | V_21 ) )
V_2 -> V_18 |= V_22 ;
if ( V_12 & V_23 ) {
V_5 = F_1 ( V_2 , & V_13 ) ;
if ( V_5 ) {
F_6 ( V_2 -> V_16 ,
L_2 , V_5 ) ;
} else {
F_7 ( V_2 -> V_24 , V_13 , V_2 -> V_18 ) ;
V_2 -> V_18 = 0 ;
}
}
return V_25 ;
}
static int F_8 ( struct V_24 * V_26 , unsigned char V_13 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
unsigned long V_18 ;
T_2 V_4 ;
int V_5 = - 1 ;
F_9 ( & V_2 -> V_28 , V_18 ) ;
V_4 = F_2 ( V_2 -> V_6 + V_7 ) ;
if ( ! ( V_4 & V_29 ) ) {
F_4 ( V_2 -> V_6 + V_30 , V_13 ) ;
V_5 = 0 ;
}
F_10 ( & V_2 -> V_28 , V_18 ) ;
return V_5 ;
}
static int F_11 ( struct V_24 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int error ;
T_1 V_13 ;
error = F_12 ( V_2 -> V_10 , & F_3 , 0 ,
V_31 , V_2 ) ;
if ( error ) {
F_6 ( V_2 -> V_16 ,
L_3 , V_2 -> V_10 ) ;
return error ;
}
F_4 ( V_2 -> V_6 + V_32 , V_33 ) ;
F_4 ( V_2 -> V_6 + V_34 , V_35 ) ;
( void ) F_1 ( V_2 , & V_13 ) ;
return 0 ;
}
static void F_13 ( struct V_24 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
F_4 ( V_2 -> V_6 + V_32 , 0x00 ) ;
F_4 ( V_2 -> V_6 + V_34 , 0x00 ) ;
F_14 ( V_2 -> V_10 , V_2 ) ;
}
static int F_15 ( struct V_36 * V_37 )
{
struct V_38 V_39 ;
struct V_1 * V_2 ;
struct V_24 * V_24 ;
struct V_40 * V_16 = & V_37 -> V_16 ;
T_4 V_41 , V_42 ;
unsigned int V_10 ;
int error ;
F_16 ( V_16 , L_4 ,
V_37 -> V_16 . V_43 -> V_44 ) ;
error = F_17 ( V_37 -> V_16 . V_43 , 0 , & V_39 ) ;
if ( error ) {
F_6 ( V_16 , L_5 ) ;
return error ;
}
V_10 = F_18 ( V_37 -> V_16 . V_43 , 0 ) ;
if ( ! V_10 ) {
F_6 ( V_16 , L_6 ) ;
return - V_45 ;
}
V_2 = F_19 ( sizeof( struct V_1 ) , V_46 ) ;
V_24 = F_19 ( sizeof( struct V_24 ) , V_46 ) ;
if ( ! V_2 || ! V_24 ) {
error = - V_47 ;
goto V_48;
}
F_20 ( & V_2 -> V_28 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_16 = V_16 ;
V_42 = V_39 . V_49 ;
V_41 = F_21 ( & V_39 ) ;
if ( ! F_22 ( V_42 , V_41 , V_31 ) ) {
F_6 ( V_16 , L_7 ,
( unsigned long long ) V_42 ) ;
error = - V_50 ;
goto V_48;
}
V_2 -> V_6 = F_23 ( V_42 , V_41 ) ;
if ( V_2 -> V_6 == NULL ) {
F_6 ( V_16 , L_8 ,
( unsigned long long ) V_42 ) ;
error = - V_51 ;
goto V_52;
}
F_4 ( V_2 -> V_6 + V_34 , 0 ) ;
F_4 ( V_2 -> V_6 + V_53 , V_54 ) ;
F_16 ( V_16 , L_9 ,
( unsigned long long ) V_42 , V_2 -> V_6 ,
V_2 -> V_10 ) ;
V_24 -> V_55 . type = V_56 ;
V_24 -> V_57 = F_8 ;
V_24 -> V_58 = F_11 ;
V_24 -> V_59 = F_13 ;
V_24 -> V_27 = V_2 ;
V_24 -> V_16 . V_60 = V_16 ;
snprintf ( V_24 -> V_44 , sizeof( V_24 -> V_44 ) ,
L_10 , ( unsigned long long ) V_42 ) ;
snprintf ( V_24 -> V_61 , sizeof( V_24 -> V_61 ) ,
L_11 , ( unsigned long long ) V_42 ) ;
F_24 ( V_24 ) ;
F_25 ( V_37 , V_2 ) ;
return 0 ;
V_52:
F_26 ( V_42 , V_41 ) ;
V_48:
F_27 ( V_24 ) ;
F_27 ( V_2 ) ;
return error ;
}
static int F_28 ( struct V_36 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_62 ) ;
struct V_38 V_39 ;
F_30 ( V_2 -> V_24 ) ;
F_31 ( V_2 -> V_6 ) ;
if ( F_17 ( V_62 -> V_16 . V_43 , 0 , & V_39 ) )
F_6 ( V_2 -> V_16 , L_5 ) ;
else
F_26 ( V_39 . V_49 , F_21 ( & V_39 ) ) ;
F_27 ( V_2 ) ;
return 0 ;
}
