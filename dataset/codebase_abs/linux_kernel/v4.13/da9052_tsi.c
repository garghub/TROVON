static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
F_2 ( V_2 -> V_4 , V_5 , 1 << 0 , V_3 ) ;
V_2 -> V_6 = V_3 ;
}
static T_1 F_3 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
if ( ! V_2 -> V_9 ) {
F_4 ( V_2 -> V_4 , V_10 ) ;
F_5 ( V_2 -> V_4 , V_11 ) ;
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
F_15 ( V_2 -> V_4 , V_11 ) ;
F_5 ( V_2 -> V_4 , V_10 ) ;
}
}
}
static int F_16 ( struct V_4 * V_4 )
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
static int F_17 ( struct V_1 * V_2 )
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
F_5 ( V_2 -> V_4 , V_10 ) ;
return F_2 ( V_2 -> V_4 , V_5 ,
1 << 1 , 1 << 1 ) ;
}
static void F_22 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_20 ( V_15 ) ;
V_2 -> V_9 = true ;
F_21 () ;
F_15 ( V_2 -> V_4 , V_10 ) ;
F_23 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_6 ) {
F_15 ( V_2 -> V_4 , V_11 ) ;
F_1 ( V_2 , false ) ;
F_5 ( V_2 -> V_4 , V_10 ) ;
}
F_2 ( V_2 -> V_4 , V_5 , 1 << 1 , 0 ) ;
}
static int F_24 ( struct V_40 * V_41 )
{
struct V_4 * V_4 ;
struct V_1 * V_2 ;
struct V_15 * V_15 ;
int error ;
V_4 = F_25 ( V_41 -> V_17 . V_42 ) ;
if ( ! V_4 )
return - V_43 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_44 ) ;
V_15 = F_27 () ;
if ( ! V_2 || ! V_15 ) {
error = - V_45 ;
goto V_46;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_17 = V_15 ;
V_2 -> V_9 = true ;
F_28 ( & V_2 -> V_12 , F_13 ) ;
V_15 -> V_47 . V_48 = 0x0101 ;
V_15 -> V_47 . V_49 = 0x15B6 ;
V_15 -> V_47 . V_50 = 0x9052 ;
V_15 -> V_51 = L_1 ;
V_15 -> V_17 . V_42 = & V_41 -> V_17 ;
V_15 -> V_52 = F_19 ;
V_15 -> V_53 = F_22 ;
F_29 ( V_54 , V_15 -> V_55 ) ;
F_29 ( V_56 , V_15 -> V_55 ) ;
F_29 ( V_27 , V_15 -> V_57 ) ;
F_30 ( V_15 , V_28 , 0 , 1023 , 0 , 0 ) ;
F_30 ( V_15 , V_29 , 0 , 1023 , 0 , 0 ) ;
F_30 ( V_15 , V_30 , 0 , 1023 , 0 , 0 ) ;
F_31 ( V_15 , V_2 ) ;
F_2 ( V_2 -> V_4 , V_5 , 1 << 1 , 0 ) ;
F_1 ( V_2 , false ) ;
error = F_32 ( V_2 -> V_4 , V_10 ,
L_2 , F_3 , V_2 ) ;
if ( error ) {
F_33 ( V_2 -> V_4 -> V_17 ,
L_3 , error ) ;
goto V_46;
}
error = F_32 ( V_2 -> V_4 , V_11 ,
L_4 , F_12 , V_2 ) ;
if ( error ) {
F_33 ( V_2 -> V_4 -> V_17 ,
L_5 , error ) ;
goto V_58;
}
F_15 ( V_2 -> V_4 , V_10 ) ;
F_15 ( V_2 -> V_4 , V_11 ) ;
error = F_17 ( V_2 ) ;
if ( error )
goto V_59;
error = F_34 ( V_2 -> V_17 ) ;
if ( error )
goto V_59;
F_35 ( V_41 , V_2 ) ;
return 0 ;
V_59:
F_36 ( V_2 -> V_4 , V_11 , V_2 ) ;
V_58:
F_36 ( V_2 -> V_4 , V_10 , V_2 ) ;
V_46:
F_37 ( V_2 ) ;
F_38 ( V_15 ) ;
return error ;
}
static int F_39 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
F_18 ( V_2 -> V_4 , V_39 , 0x19 ) ;
F_36 ( V_2 -> V_4 , V_11 , V_2 ) ;
F_36 ( V_2 -> V_4 , V_10 , V_2 ) ;
F_41 ( V_2 -> V_17 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
