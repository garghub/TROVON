static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 , T_1 V_5 )
{
int V_6 = F_2 ( V_7 , V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_8 ,
L_1 ,
V_4 , V_6 , V_6 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_6 = F_5 ( V_7 , V_3 , V_4 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_8 ,
L_2 ,
V_4 , V_6 , V_6 ) ;
return V_6 ;
}
static inline T_3 F_6 ( struct V_1 * V_2 , T_1 V_9 )
{
if ( V_9 == 0xFF )
return 1 << V_2 -> V_10 ;
else
return V_9 & ( ( 1 << V_2 -> V_10 ) - 1 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_3 * V_11 )
{
T_1 V_12 [ V_13 ] ;
int V_14 ;
int V_6 = F_1 ( V_2 , V_12 ,
V_15 , V_2 -> V_16 ) ;
if ( V_6 >= 0 )
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ )
V_11 [ V_14 ] = F_6 ( V_2 , V_12 [ V_14 ] ) ;
return V_6 ;
}
static bool F_8 ( struct V_1 * V_2 , T_3 * V_17 )
{
int V_18 ;
T_3 V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_16 ; V_18 ++ ) {
T_3 V_9 = V_17 [ V_18 ] ;
if ( ( V_9 & V_19 ) && F_9 ( V_9 ) > 1 )
return true ;
V_19 |= V_9 ;
}
return false ;
}
static void F_10 ( struct V_1 * V_2 , bool V_20 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
T_3 V_12 [ V_13 ] ;
int V_9 , V_14 ;
if ( V_20 )
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
else {
int V_6 = F_7 ( V_2 , V_12 ) ;
if ( V_6 < 0 )
return;
if ( F_8 ( V_2 , V_12 ) )
return;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_16 ; V_14 ++ ) {
int V_23 = V_12 [ V_14 ] ^ V_2 -> V_24 [ V_14 ] ;
if ( ! V_23 )
continue;
for ( V_9 = 0 ; V_9 < V_2 -> V_10 + 1 ; V_9 ++ ) {
int V_25 ;
if ( ! ( V_23 & ( 1 << V_9 ) ) )
continue;
F_11 ( V_2 -> V_8 , L_3 , V_14 , V_9 ,
( V_12 [ V_14 ] & ( 1 << V_9 ) ) ?
L_4 : L_5 ) ;
V_25 = F_12 ( V_14 , V_9 , V_26 ) ;
F_13 ( V_22 , V_27 , V_28 , V_25 ) ;
F_14 ( V_22 , V_2 -> V_29 [ V_25 ] ,
V_12 [ V_14 ] & ( 1 << V_9 ) ) ;
}
V_2 -> V_24 [ V_14 ] = V_12 [ V_14 ] ;
}
F_15 ( V_22 ) ;
}
static T_4 F_16 ( int V_30 , void * V_31 )
{
struct V_1 * V_2 = V_31 ;
T_1 V_4 ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_4 , V_32 , 1 ) ;
if ( V_6 >= 0 && ( V_4 & V_33 ) )
F_10 ( V_2 , false ) ;
else
F_10 ( V_2 , true ) ;
return V_34 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_18 ;
V_4 = V_35 | V_36
| V_37 | V_38 ;
if ( F_4 ( V_2 , V_4 , V_39 ) < 0 )
return - V_40 ;
V_4 = V_41 | V_42 ;
if ( F_4 ( V_2 , V_4 , V_43 ) < 0 )
return - V_40 ;
V_4 = ( V_44 << V_45 ) ;
if ( F_4 ( V_2 , V_4 , V_46 ) < 0 )
return - V_40 ;
V_18 = F_18 ( 20000 , V_44 ) ;
if ( F_4 ( V_2 , V_18 , V_47 ) < 0 )
return - V_40 ;
V_18 = F_18 ( 200000 , V_44 ) ;
if ( F_4 ( V_2 , ( V_18 & 0xFF ) , V_48 ) < 0 )
return - V_40 ;
if ( F_4 ( V_2 , ( V_18 >> 8 ) , V_49 ) < 0 )
return - V_40 ;
V_4 = V_50 | V_51 ;
if ( F_4 ( V_2 , V_4 , V_52 ) < 0 )
return - V_40 ;
if ( F_7 ( V_2 , V_2 -> V_24 ) < 0 )
return - V_40 ;
return 0 ;
}
static int F_19 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_20 ( & V_54 -> V_57 ) ;
const struct V_58 * V_59 = NULL ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
T_1 V_4 ;
int error ;
V_2 = F_21 ( & V_54 -> V_57 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
return - V_61 ;
V_22 = F_22 ( & V_54 -> V_57 ) ;
if ( ! V_22 )
return - V_61 ;
V_2 -> V_8 = & V_54 -> V_57 ;
V_2 -> V_22 = V_22 ;
V_22 -> V_62 = L_6 ;
V_22 -> V_63 = L_7 ;
V_22 -> V_64 . V_65 = V_66 ;
V_22 -> V_64 . V_67 = 0x0001 ;
V_22 -> V_64 . V_68 = 0x0001 ;
V_22 -> V_64 . V_69 = 0x0003 ;
if ( V_56 ) {
if ( ! V_56 -> V_70 || ! V_56 -> V_71 || ! V_56 -> V_59 ) {
F_23 ( & V_54 -> V_57 , L_8 ) ;
return - V_72 ;
}
V_2 -> V_16 = V_56 -> V_70 ;
V_2 -> V_10 = V_56 -> V_71 ;
V_2 -> V_73 = V_56 -> V_74 ;
V_59 = V_56 -> V_59 ;
} else {
error = F_24 ( & V_54 -> V_57 , & V_2 -> V_16 ,
& V_2 -> V_10 ) ;
if ( error )
return error ;
V_2 -> V_73 = true ;
}
if ( V_2 -> V_16 > V_13 || V_2 -> V_10 > V_75 ) {
F_23 ( & V_54 -> V_57 ,
L_9 ) ;
return - V_72 ;
}
V_2 -> V_30 = F_25 ( V_54 , 0 ) ;
if ( ! V_2 -> V_30 ) {
F_23 ( & V_54 -> V_57 , L_10 ) ;
return - V_72 ;
}
error = F_26 ( V_59 , NULL ,
V_13 ,
1 << V_26 ,
V_2 -> V_29 , V_22 ) ;
if ( error ) {
F_23 ( V_2 -> V_8 , L_11 ) ;
return error ;
}
F_27 ( V_22 , V_27 , V_28 ) ;
if ( V_2 -> V_73 )
F_28 ( V_76 , V_22 -> V_77 ) ;
error = F_29 ( V_22 ) ;
if ( error ) {
F_23 ( V_2 -> V_8 ,
L_12 ) ;
return error ;
}
error = F_17 ( V_2 ) ;
if ( error )
return error ;
error = F_30 ( & V_54 -> V_57 , V_2 -> V_30 , NULL , F_16 ,
0 , V_54 -> V_62 , V_2 ) ;
if ( error ) {
F_31 ( V_2 -> V_8 , L_13 ,
V_2 -> V_30 , error ) ;
return error ;
}
V_4 = ( T_1 ) ~ ( V_33 | V_78 ) ;
if ( F_4 ( V_2 , V_4 , V_79 ) ) {
( void ) F_4 ( V_2 , 0xff , V_79 ) ;
return - V_40 ;
}
F_32 ( V_54 , V_2 ) ;
return 0 ;
}
