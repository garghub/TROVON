static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
F_2 ( V_2 -> V_4 , V_5 , 1 << 0 , V_3 ) ;
V_2 -> V_6 = V_3 ;
}
static T_1 F_3 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
if ( ! V_2 -> V_9 ) {
F_4 ( V_2 -> V_10 ) ;
F_5 ( V_2 -> V_11 ) ;
F_1 ( V_2 , true ) ;
F_6 ( & V_2 -> V_12 , V_13 / 50 ) ;
}
return V_14 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_18 ;
T_2 V_19 , V_20 , V_21 ;
T_3 V_22 ;
V_18 = F_8 ( V_2 -> V_4 , V_23 ) ;
if ( V_18 < 0 )
return;
V_19 = ( T_2 ) V_18 ;
V_18 = F_8 ( V_2 -> V_4 , V_24 ) ;
if ( V_18 < 0 )
return;
V_20 = ( T_2 ) V_18 ;
V_18 = F_8 ( V_2 -> V_4 , V_25 ) ;
if ( V_18 < 0 )
return;
V_21 = ( T_2 ) V_18 ;
V_18 = F_8 ( V_2 -> V_4 , V_26 ) ;
if ( V_18 < 0 )
return;
V_22 = ( T_3 ) V_18 ;
V_19 = ( ( V_19 << 2 ) & 0x3fc ) | ( V_22 & 0x3 ) ;
V_20 = ( ( V_20 << 2 ) & 0x3fc ) | ( ( V_22 & 0xc ) >> 2 ) ;
V_21 = ( ( V_21 << 2 ) & 0x3fc ) | ( ( V_22 & 0x30 ) >> 4 ) ;
F_9 ( V_16 , V_27 , 1 ) ;
F_10 ( V_16 , V_28 , V_19 ) ;
F_10 ( V_16 , V_29 , V_20 ) ;
F_10 ( V_16 , V_30 , V_21 ) ;
F_11 ( V_16 ) ;
}
static T_1 F_12 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
F_7 ( V_2 ) ;
return V_14 ;
}
static void F_13 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_14 ( V_32 , struct V_1 ,
V_12 . V_32 ) ;
if ( ! V_2 -> V_9 ) {
int V_18 = F_8 ( V_2 -> V_4 , V_26 ) ;
if ( V_18 < 0 || ( V_18 & V_33 ) ) {
F_6 ( & V_2 -> V_12 , V_13 / 50 ) ;
} else {
struct V_15 * V_16 = V_2 -> V_17 ;
F_1 ( V_2 , false ) ;
F_9 ( V_16 , V_27 , 0 ) ;
F_10 ( V_16 , V_30 , 0 ) ;
F_11 ( V_16 ) ;
V_18 = F_2 ( V_2 -> V_4 ,
V_34 , 0xC0 , 0xC0 ) ;
if ( V_18 < 0 )
return;
F_15 ( V_2 -> V_11 ) ;
F_5 ( V_2 -> V_10 ) ;
}
}
}
static int T_4 F_16 ( struct V_4 * V_4 )
{
int error ;
error = F_2 ( V_4 , V_35 , 0x30 , 0 ) ;
if ( error < 0 )
return error ;
error = F_2 ( V_4 , V_36 , 0x33 , 0 ) ;
if ( error < 0 )
return error ;
error = F_2 ( V_4 , V_37 , 0x33 , 0 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int T_4 F_17 ( struct V_1 * V_2 )
{
int error ;
error = F_16 ( V_2 -> V_4 ) ;
if ( error )
return error ;
error = F_2 ( V_2 -> V_4 , V_38 ,
1 << 6 , 1 << 6 ) ;
if ( error < 0 )
return error ;
error = F_2 ( V_2 -> V_4 , V_5 , 0xFC , 0xC0 ) ;
if ( error < 0 )
return error ;
error = F_18 ( V_2 -> V_4 , V_39 , 0x59 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_19 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_20 ( V_15 ) ;
V_2 -> V_9 = false ;
F_21 () ;
F_5 ( V_2 -> V_10 ) ;
return F_2 ( V_2 -> V_4 , V_5 ,
1 << 1 , 1 << 1 ) ;
}
static void F_22 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_20 ( V_15 ) ;
V_2 -> V_9 = true ;
F_21 () ;
F_15 ( V_2 -> V_10 ) ;
F_23 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_6 ) {
F_15 ( V_2 -> V_11 ) ;
F_1 ( V_2 , false ) ;
F_5 ( V_2 -> V_10 ) ;
}
F_2 ( V_2 -> V_4 , V_5 , 1 << 1 , 0 ) ;
}
static int T_4 F_24 ( struct V_40 * V_41 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_15 * V_15 ;
int V_10 ;
int V_11 ;
int error ;
V_4 = F_25 ( V_41 -> V_17 . V_42 ) ;
if ( ! V_4 )
return - V_43 ;
V_10 = F_26 ( V_41 , L_1 ) ;
V_11 = F_26 ( V_41 , L_2 ) ;
if ( V_10 < 0 || V_11 < 0 ) {
F_27 ( V_4 -> V_17 , L_3 ) ;
return - V_44 ;
}
V_2 = F_28 ( sizeof( struct V_1 ) , V_45 ) ;
V_15 = F_29 () ;
if ( ! V_2 || ! V_15 ) {
error = - V_46 ;
goto V_47;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_17 = V_15 ;
V_2 -> V_10 = V_4 -> V_48 + V_10 ;
V_2 -> V_11 = V_4 -> V_48 + V_11 ;
V_2 -> V_9 = true ;
F_30 ( & V_2 -> V_12 , F_13 ) ;
V_15 -> V_49 . V_50 = 0x0101 ;
V_15 -> V_49 . V_51 = 0x15B6 ;
V_15 -> V_49 . V_52 = 0x9052 ;
V_15 -> V_53 = L_4 ;
V_15 -> V_17 . V_42 = & V_41 -> V_17 ;
V_15 -> V_54 = F_19 ;
V_15 -> V_55 = F_22 ;
F_31 ( V_56 , V_15 -> V_57 ) ;
F_31 ( V_58 , V_15 -> V_57 ) ;
F_31 ( V_27 , V_15 -> V_59 ) ;
F_32 ( V_15 , V_28 , 0 , 1023 , 0 , 0 ) ;
F_32 ( V_15 , V_29 , 0 , 1023 , 0 , 0 ) ;
F_32 ( V_15 , V_30 , 0 , 1023 , 0 , 0 ) ;
F_33 ( V_15 , V_2 ) ;
F_2 ( V_2 -> V_4 , V_5 , 1 << 1 , 0 ) ;
F_1 ( V_2 , false ) ;
error = F_34 ( V_2 -> V_10 ,
NULL , F_3 ,
V_60 | V_61 ,
L_1 , V_2 ) ;
if ( error ) {
F_27 ( V_2 -> V_4 -> V_17 ,
L_5 ,
V_2 -> V_10 , error ) ;
goto V_47;
}
error = F_34 ( V_2 -> V_11 ,
NULL , F_12 ,
V_60 | V_61 ,
L_2 , V_2 ) ;
if ( error ) {
F_27 ( V_2 -> V_4 -> V_17 ,
L_6 ,
V_2 -> V_11 , error ) ;
goto V_62;
}
F_15 ( V_2 -> V_10 ) ;
F_15 ( V_2 -> V_11 ) ;
error = F_17 ( V_2 ) ;
if ( error )
goto V_63;
error = F_35 ( V_2 -> V_17 ) ;
if ( error )
goto V_63;
F_36 ( V_41 , V_2 ) ;
return 0 ;
V_63:
F_37 ( V_2 -> V_11 , V_2 ) ;
V_62:
F_37 ( V_2 -> V_10 , V_2 ) ;
V_47:
F_38 ( V_2 ) ;
F_39 ( V_15 ) ;
return error ;
}
static int T_5 F_40 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_41 ( V_41 ) ;
F_18 ( V_2 -> V_4 , V_39 , 0x19 ) ;
F_37 ( V_2 -> V_10 , V_2 ) ;
F_37 ( V_2 -> V_11 , V_2 ) ;
F_42 ( V_2 -> V_17 ) ;
F_38 ( V_2 ) ;
F_36 ( V_41 , NULL ) ;
return 0 ;
}
