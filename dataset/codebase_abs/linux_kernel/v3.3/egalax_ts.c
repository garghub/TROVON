static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
T_2 V_8 [ V_9 ] ;
int V_10 , V_11 , V_12 , V_13 , V_14 ;
int V_15 = 0 ;
bool V_16 , V_17 ;
T_2 V_18 ;
do {
V_11 = F_2 ( V_7 , V_8 , V_9 ) ;
} while ( V_11 == - V_19 && V_15 ++ < V_20 );
if ( V_11 < 0 )
return V_21 ;
if ( V_8 [ 0 ] != V_22 ) {
return V_21 ;
}
V_18 = V_8 [ 1 ] ;
V_12 = ( V_8 [ 3 ] << 8 ) | V_8 [ 2 ] ;
V_13 = ( V_8 [ 5 ] << 8 ) | V_8 [ 4 ] ;
V_14 = ( V_8 [ 7 ] << 8 ) | V_8 [ 6 ] ;
V_17 = V_18 & V_23 ;
V_10 = ( V_18 & V_24 ) >> V_25 ;
V_16 = V_18 & V_26 ;
if ( ! V_17 || V_10 > V_27 ) {
F_3 ( & V_7 -> V_28 , L_1 ) ;
return V_21 ;
}
F_4 ( V_5 , V_10 ) ;
F_5 ( V_5 , V_29 , V_16 ) ;
F_3 ( & V_7 -> V_28 , L_2 ,
V_16 ? L_3 : L_4 , V_10 , V_12 , V_13 , V_14 ) ;
if ( V_16 ) {
F_6 ( V_5 , V_30 , V_12 ) ;
F_6 ( V_5 , V_31 , V_13 ) ;
F_6 ( V_5 , V_32 , V_14 ) ;
}
F_7 ( V_5 , true ) ;
F_8 ( V_5 ) ;
return V_21 ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_33 = F_10 ( V_7 -> V_1 ) ;
int V_11 ;
V_11 = F_11 ( V_33 , L_5 ) ;
if ( V_11 < 0 ) {
F_12 ( & V_7 -> V_28 ,
L_6 ,
V_11 ) ;
return V_11 ;
}
F_13 ( V_33 , 0 ) ;
F_14 ( V_33 , 1 ) ;
F_15 ( V_33 ) ;
F_16 ( V_33 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_6 * V_7 )
{
static const T_2 V_34 [ V_9 ] = { 0x03 , 0x03 , 0xa , 0x01 , 0x41 } ;
int V_11 ;
V_11 = F_18 ( V_7 , V_34 , V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int T_3 F_19 ( struct V_6 * V_7 ,
const struct V_35 * V_10 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
int V_11 ;
int error ;
V_4 = F_20 ( sizeof( struct V_3 ) , V_36 ) ;
if ( ! V_4 ) {
F_12 ( & V_7 -> V_28 , L_7 ) ;
return - V_37 ;
}
V_5 = F_21 () ;
if ( ! V_5 ) {
F_12 ( & V_7 -> V_28 , L_7 ) ;
error = - V_37 ;
goto V_38;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_5 = V_5 ;
F_9 ( V_7 ) ;
V_11 = F_17 ( V_7 ) ;
if ( V_11 < 0 ) {
F_12 ( & V_7 -> V_28 , L_8 ) ;
error = - V_39 ;
goto V_40;
}
V_5 -> V_41 = L_9 ;
V_5 -> V_10 . V_42 = V_43 ;
V_5 -> V_28 . V_44 = & V_7 -> V_28 ;
F_22 ( V_45 , V_5 -> V_46 ) ;
F_22 ( V_47 , V_5 -> V_46 ) ;
F_22 ( V_48 , V_5 -> V_49 ) ;
F_23 ( V_5 , V_50 , 0 , V_51 , 0 , 0 ) ;
F_23 ( V_5 , V_52 , 0 , V_53 , 0 , 0 ) ;
F_23 ( V_5 ,
V_30 , 0 , V_51 , 0 , 0 ) ;
F_23 ( V_5 ,
V_30 , 0 , V_53 , 0 , 0 ) ;
F_24 ( V_5 , V_27 ) ;
F_25 ( V_5 , V_4 ) ;
error = F_26 ( V_7 -> V_1 , NULL , F_1 ,
V_54 | V_55 ,
L_10 , V_4 ) ;
if ( error < 0 ) {
F_12 ( & V_7 -> V_28 , L_11 ) ;
goto V_40;
}
error = F_27 ( V_4 -> V_5 ) ;
if ( error )
goto V_56;
F_28 ( V_7 , V_4 ) ;
return 0 ;
V_56:
F_29 ( V_7 -> V_1 , V_4 ) ;
V_40:
F_30 ( V_5 ) ;
V_38:
F_31 ( V_4 ) ;
return error ;
}
static T_4 int F_32 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_33 ( V_7 ) ;
F_29 ( V_7 -> V_1 , V_4 ) ;
F_34 ( V_4 -> V_5 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_57 * V_28 )
{
static const T_2 V_58 [ V_9 ] = {
0x3 , 0x6 , 0xa , 0x3 , 0x36 , 0x3f , 0x2 , 0 , 0 , 0
} ;
struct V_6 * V_7 = F_36 ( V_28 ) ;
int V_11 ;
V_11 = F_18 ( V_7 , V_58 , V_9 ) ;
return V_11 > 0 ? 0 : V_11 ;
}
static int F_37 ( struct V_57 * V_28 )
{
struct V_6 * V_7 = F_36 ( V_28 ) ;
return F_9 ( V_7 ) ;
}
static int T_5 F_38 ( void )
{
return F_39 ( & V_59 ) ;
}
static void T_6 F_40 ( void )
{
F_41 ( & V_59 ) ;
}
