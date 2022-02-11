static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 * V_4 , int V_5 )
{
struct V_6 V_7 [ 2 ] ;
T_1 V_8 = F_2 ( V_3 ) ;
int V_9 ;
V_7 [ 0 ] . V_10 = 0 ;
V_7 [ 0 ] . V_11 = V_2 -> V_11 ;
V_7 [ 0 ] . V_5 = 2 ;
V_7 [ 0 ] . V_4 = ( T_2 * ) & V_8 ;
V_7 [ 1 ] . V_10 = V_12 ;
V_7 [ 1 ] . V_11 = V_2 -> V_11 ;
V_7 [ 1 ] . V_5 = V_5 ;
V_7 [ 1 ] . V_4 = V_4 ;
V_9 = F_3 ( V_2 -> V_13 , V_7 , 2 ) ;
return V_9 < 0 ? V_9 : ( V_9 != F_4 ( V_7 ) ? - V_14 : 0 ) ;
}
static int F_5 ( struct V_15 * V_16 , T_2 * V_17 )
{
int V_18 ;
int error ;
error = F_1 ( V_16 -> V_2 , V_19 , V_17 ,
V_20 + 1 ) ;
if ( error ) {
F_6 ( & V_16 -> V_2 -> V_21 , L_1 , error ) ;
return error ;
}
if ( ! ( V_17 [ 0 ] & 0x80 ) )
return - V_22 ;
V_18 = V_17 [ 0 ] & 0x0f ;
if ( V_18 > V_16 -> V_23 )
return - V_24 ;
if ( V_18 > 1 ) {
V_17 += 1 + V_20 ;
error = F_1 ( V_16 -> V_2 ,
V_19 +
1 + V_20 ,
V_17 ,
V_20 * ( V_18 - 1 ) ) ;
if ( error )
return error ;
}
return V_18 ;
}
static void F_7 ( struct V_15 * V_16 , T_2 * V_25 )
{
int V_26 = V_25 [ 0 ] & 0x0F ;
int V_27 = F_8 ( & V_25 [ 1 ] ) ;
int V_28 = F_8 ( & V_25 [ 3 ] ) ;
int V_29 = F_8 ( & V_25 [ 5 ] ) ;
if ( V_16 -> V_30 ) {
V_27 = V_16 -> V_31 - V_27 ;
V_28 = V_16 -> V_32 - V_28 ;
}
F_9 ( V_16 -> V_33 , V_26 ) ;
F_10 ( V_16 -> V_33 , V_34 , true ) ;
F_11 ( V_16 -> V_33 , V_35 , V_27 ) ;
F_11 ( V_16 -> V_33 , V_36 , V_28 ) ;
F_11 ( V_16 -> V_33 , V_37 , V_29 ) ;
F_11 ( V_16 -> V_33 , V_38 , V_29 ) ;
}
static void F_12 ( struct V_15 * V_16 )
{
T_2 V_39 [ 1 + V_20 * V_40 ] ;
int V_18 ;
int V_41 ;
V_18 = F_5 ( V_16 , V_39 ) ;
if ( V_18 < 0 )
return;
for ( V_41 = 0 ; V_41 < V_18 ; V_41 ++ )
F_7 ( V_16 ,
& V_39 [ 1 + V_20 * V_41 ] ) ;
F_13 ( V_16 -> V_33 ) ;
F_14 ( V_16 -> V_33 ) ;
}
static T_3 F_15 ( int V_42 , void * V_43 )
{
static const T_2 V_44 [] = {
V_19 >> 8 ,
V_19 & 0xff ,
0
} ;
struct V_15 * V_16 = V_43 ;
F_12 ( V_16 ) ;
if ( F_16 ( V_16 -> V_2 , V_44 , sizeof( V_44 ) ) < 0 )
F_6 ( & V_16 -> V_2 -> V_21 , L_2 ) ;
return V_45 ;
}
static void F_17 ( struct V_15 * V_16 )
{
T_2 V_46 [ V_47 ] ;
int error ;
error = F_1 ( V_16 -> V_2 , V_48 ,
V_46 ,
V_47 ) ;
if ( error ) {
F_18 ( & V_16 -> V_2 -> V_21 ,
L_3 ,
error ) ;
V_16 -> V_31 = V_49 ;
V_16 -> V_32 = V_50 ;
V_16 -> V_51 = V_52 ;
V_16 -> V_23 = V_40 ;
return;
}
V_16 -> V_31 = F_8 ( & V_46 [ V_53 ] ) ;
V_16 -> V_32 = F_8 ( & V_46 [ V_53 + 2 ] ) ;
V_16 -> V_51 = V_46 [ V_54 ] & 0x03 ;
V_16 -> V_23 = V_46 [ V_55 ] & 0x0f ;
if ( ! V_16 -> V_31 || ! V_16 -> V_32 || ! V_16 -> V_23 ) {
F_6 ( & V_16 -> V_2 -> V_21 ,
L_4 ) ;
V_16 -> V_31 = V_49 ;
V_16 -> V_32 = V_50 ;
V_16 -> V_23 = V_40 ;
}
V_16 -> V_30 = F_19 ( V_30 ) ;
if ( V_16 -> V_30 )
F_20 ( & V_16 -> V_2 -> V_21 ,
L_5 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_1 * V_56 , T_1 * V_26 )
{
int error ;
T_2 V_4 [ 6 ] ;
char V_57 [ 5 ] ;
error = F_1 ( V_2 , V_58 , V_4 , sizeof( V_4 ) ) ;
if ( error ) {
F_6 ( & V_2 -> V_21 , L_6 , error ) ;
return error ;
}
memcpy ( V_57 , V_4 , 4 ) ;
V_57 [ 4 ] = 0 ;
if ( F_22 ( V_57 , 10 , V_26 ) )
* V_26 = 0x1001 ;
* V_56 = F_8 ( & V_4 [ 4 ] ) ;
F_23 ( & V_2 -> V_21 , L_7 , * V_26 , * V_56 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_59 = 0 ;
int error ;
T_2 V_60 ;
while ( V_59 ++ < 2 ) {
error = F_1 ( V_2 , V_48 ,
& V_60 , 1 ) ;
if ( ! error )
return 0 ;
F_6 ( & V_2 -> V_21 , L_8 ,
V_59 , error ) ;
F_25 ( 20 ) ;
}
return error ;
}
static int F_26 ( struct V_15 * V_16 , T_1 V_56 ,
T_1 V_26 )
{
int error ;
V_16 -> V_33 = F_27 ( & V_16 -> V_2 -> V_21 ) ;
if ( ! V_16 -> V_33 ) {
F_6 ( & V_16 -> V_2 -> V_21 , L_9 ) ;
return - V_61 ;
}
F_28 ( V_16 -> V_33 , V_35 ,
0 , V_16 -> V_31 , 0 , 0 ) ;
F_28 ( V_16 -> V_33 , V_36 ,
0 , V_16 -> V_32 , 0 , 0 ) ;
F_28 ( V_16 -> V_33 , V_38 , 0 , 255 , 0 , 0 ) ;
F_28 ( V_16 -> V_33 , V_37 , 0 , 255 , 0 , 0 ) ;
F_29 ( V_16 -> V_33 , V_16 -> V_23 ,
V_62 | V_63 ) ;
V_16 -> V_33 -> V_64 = L_10 ;
V_16 -> V_33 -> V_65 = L_11 ;
V_16 -> V_33 -> V_26 . V_66 = V_67 ;
V_16 -> V_33 -> V_26 . V_68 = 0x0416 ;
V_16 -> V_33 -> V_26 . V_69 = V_26 ;
V_16 -> V_33 -> V_26 . V_56 = V_56 ;
error = F_30 ( V_16 -> V_33 ) ;
if ( error ) {
F_6 ( & V_16 -> V_2 -> V_21 ,
L_12 , error ) ;
return error ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_70 * V_26 )
{
struct V_15 * V_16 ;
unsigned long V_71 ;
int error ;
T_1 V_72 , V_73 ;
F_20 ( & V_2 -> V_21 , L_13 , V_2 -> V_11 ) ;
if ( ! F_32 ( V_2 -> V_13 , V_74 ) ) {
F_6 ( & V_2 -> V_21 , L_14 ) ;
return - V_75 ;
}
V_16 = F_33 ( & V_2 -> V_21 , sizeof( * V_16 ) , V_76 ) ;
if ( ! V_16 )
return - V_61 ;
V_16 -> V_2 = V_2 ;
F_34 ( V_2 , V_16 ) ;
error = F_24 ( V_2 ) ;
if ( error ) {
F_6 ( & V_2 -> V_21 , L_15 , error ) ;
return error ;
}
error = F_21 ( V_2 , & V_72 , & V_73 ) ;
if ( error ) {
F_6 ( & V_2 -> V_21 , L_16 ) ;
return error ;
}
F_17 ( V_16 ) ;
error = F_26 ( V_16 , V_72 , V_73 ) ;
if ( error )
return error ;
V_71 = V_77 [ V_16 -> V_51 ] | V_78 ;
error = F_35 ( & V_16 -> V_2 -> V_21 , V_2 -> V_42 ,
NULL , F_15 ,
V_71 , V_2 -> V_64 , V_16 ) ;
if ( error ) {
F_6 ( & V_2 -> V_21 , L_17 , error ) ;
return error ;
}
return 0 ;
}
