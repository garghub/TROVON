static int F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
int error ;
error = F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_5 -> V_6 ,
L_1 ,
V_7 , V_3 , V_4 , error ) ;
return error ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
int error ;
error = F_5 ( V_2 -> V_5 , V_3 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_5 -> V_6 ,
L_2 ,
V_7 , V_3 , error ) ;
return error ;
}
* V_4 = ( T_1 ) error ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned short * V_10 = V_9 -> V_11 ;
int error , V_12 , V_13 ;
T_1 V_3 , V_14 , V_15 ;
do {
error = F_4 ( V_2 , V_16 , & V_3 ) ;
if ( error < 0 ) {
F_3 ( & V_2 -> V_5 -> V_6 ,
L_3 ) ;
break;
}
if ( V_3 <= 0 )
break;
V_14 = V_3 & V_17 ;
V_15 = V_3 & V_18 ;
V_13 = V_15 / V_19 ;
V_12 = V_15 % V_19 ;
V_13 = ( V_12 ) ? V_13 : V_13 - 1 ;
V_12 = ( V_12 ) ? V_12 - 1 : V_19 - 1 ;
V_15 = F_7 ( V_13 , V_12 , V_2 -> V_20 ) ;
F_8 ( V_9 , V_21 , V_22 , V_15 ) ;
F_9 ( V_9 , V_10 [ V_15 ] , V_14 ) ;
error = F_4 ( V_2 , V_16 , & V_3 ) ;
} while ( 1 );
F_10 ( V_9 ) ;
}
static T_2 F_11 ( int V_23 , void * V_24 )
{
struct V_1 * V_2 = V_24 ;
T_1 V_3 ;
int error ;
error = F_4 ( V_2 , V_25 , & V_3 ) ;
if ( error ) {
F_3 ( & V_2 -> V_5 -> V_6 ,
L_4 ) ;
return V_26 ;
}
if ( ! V_3 )
return V_26 ;
if ( V_3 & V_27 )
F_12 ( & V_2 -> V_5 -> V_6 , L_5 ) ;
if ( V_3 & V_28 )
F_6 ( V_2 ) ;
V_3 = 0xff ;
error = F_1 ( V_2 , V_25 , V_3 ) ;
if ( error )
F_3 ( & V_2 -> V_5 -> V_6 ,
L_6 ) ;
return V_29 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_3 V_30 , T_3 V_31 )
{
int V_3 , error ;
error = F_1 ( V_2 , V_32 ,
V_33 | V_34 | V_35 ) ;
if ( error < 0 )
return - V_36 ;
V_3 = ~ ( ~ 0 << V_30 ) ;
V_3 += ( ~ ( ~ 0 << V_31 ) ) << 8 ;
error |= F_1 ( V_2 , V_37 , V_3 ) ;
error |= F_1 ( V_2 , V_38 , V_3 >> 8 ) ;
error |= F_1 ( V_2 , V_39 , V_3 >> 16 ) ;
error |= F_1 ( V_2 , V_40 , V_3 ) ;
error |= F_1 ( V_2 , V_41 , V_3 >> 8 ) ;
error |= F_1 ( V_2 , V_42 , V_3 >> 16 ) ;
return error ;
}
static int F_14 ( struct V_43 * V_5 ,
const struct V_44 * V_45 )
{
struct V_46 * V_6 = & V_5 -> V_6 ;
const struct V_47 * V_48 =
F_15 ( V_6 ) ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
const struct V_49 * V_50 = NULL ;
T_3 V_30 = 0 , V_31 = 0 ;
bool V_51 = false ;
bool V_52 = false ;
int V_23 ;
int error , V_20 , V_53 ;
if ( V_48 ) {
if ( ! V_48 -> V_50 ) {
F_3 ( V_6 , L_7 ) ;
return - V_54 ;
}
V_50 = V_48 -> V_50 ;
V_30 = V_48 -> V_30 ;
V_31 = V_48 -> V_31 ;
V_51 = V_48 -> V_51 ;
V_52 = V_48 -> V_52 ;
} else {
struct V_55 * V_56 = V_6 -> V_57 ;
int V_58 ;
V_58 = F_16 ( V_6 , & V_30 , & V_31 ) ;
if ( V_58 )
return V_58 ;
V_51 = F_17 ( V_56 , L_8 ) ;
}
if ( ! V_30 || V_30 > V_59 ) {
F_3 ( V_6 , L_9 ) ;
return - V_54 ;
}
if ( ! V_31 || V_31 > V_19 ) {
F_3 ( V_6 , L_10 ) ;
return - V_54 ;
}
if ( ! F_18 ( V_5 -> V_60 , V_61 ) ) {
F_3 ( V_6 , L_11 ,
F_19 ( & V_5 -> V_60 -> V_6 ) ) ;
return - V_36 ;
}
V_20 = F_20 ( V_31 ) ;
V_53 = V_30 << V_20 ;
V_2 = F_21 ( V_6 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_20 = V_20 ;
error = F_13 ( V_2 , V_30 , V_31 ) ;
if ( error < 0 )
return error ;
V_9 = F_22 ( V_6 ) ;
if ( ! V_9 )
return - V_63 ;
V_2 -> V_9 = V_9 ;
V_9 -> V_64 = V_5 -> V_64 ;
V_9 -> V_45 . V_65 = V_66 ;
V_9 -> V_45 . V_67 = 0x0001 ;
V_9 -> V_45 . V_68 = 0x001 ;
V_9 -> V_45 . V_69 = 0x0001 ;
error = F_23 ( V_50 , NULL , V_30 , V_31 ,
NULL , V_9 ) ;
if ( error ) {
F_3 ( V_6 , L_12 ) ;
return error ;
}
if ( V_51 )
F_24 ( V_70 , V_9 -> V_71 ) ;
F_25 ( V_9 , V_21 , V_22 ) ;
F_26 ( V_9 , V_2 ) ;
V_23 = V_5 -> V_23 ;
if ( V_52 )
V_23 = F_27 ( V_23 ) ;
error = F_28 ( V_6 , V_23 , NULL , F_11 ,
V_72 |
V_73 |
V_74 ,
V_5 -> V_64 , V_2 ) ;
if ( error ) {
F_3 ( V_6 , L_13 ,
V_5 -> V_23 , error ) ;
return error ;
}
error = F_29 ( V_9 ) ;
if ( error ) {
F_3 ( V_6 , L_14 ,
error ) ;
return error ;
}
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_75 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_75 ) ;
}
