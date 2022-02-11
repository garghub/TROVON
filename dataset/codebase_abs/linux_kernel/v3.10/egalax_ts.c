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
struct V_33 * V_34 = V_7 -> V_28 . V_35 ;
int V_36 ;
int V_11 ;
if ( ! V_34 )
return - V_37 ;
V_36 = F_10 ( V_34 , L_5 , 0 ) ;
if ( ! F_11 ( V_36 ) )
return - V_37 ;
V_11 = F_12 ( V_36 , L_6 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_7 -> V_28 ,
L_7 ,
V_11 ) ;
return V_11 ;
}
F_14 ( V_36 , 0 ) ;
F_15 ( V_36 , 1 ) ;
F_16 ( V_36 ) ;
F_17 ( V_36 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
static const T_2 V_38 [ V_9 ] = { 0x03 , 0x03 , 0xa , 0x01 , 0x41 } ;
int V_11 ;
V_11 = F_19 ( V_7 , V_38 , V_9 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 ,
const struct V_39 * V_10 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
int V_11 ;
int error ;
V_4 = F_21 ( sizeof( struct V_3 ) , V_40 ) ;
if ( ! V_4 ) {
F_13 ( & V_7 -> V_28 , L_8 ) ;
return - V_41 ;
}
V_5 = F_22 () ;
if ( ! V_5 ) {
F_13 ( & V_7 -> V_28 , L_8 ) ;
error = - V_41 ;
goto V_42;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_5 = V_5 ;
error = F_9 ( V_7 ) ;
if ( error ) {
F_13 ( & V_7 -> V_28 , L_9 ) ;
goto V_43;
}
V_11 = F_18 ( V_7 ) ;
if ( V_11 < 0 ) {
F_13 ( & V_7 -> V_28 , L_10 ) ;
error = - V_44 ;
goto V_43;
}
V_5 -> V_45 = L_11 ;
V_5 -> V_10 . V_46 = V_47 ;
V_5 -> V_28 . V_48 = & V_7 -> V_28 ;
F_23 ( V_49 , V_5 -> V_50 ) ;
F_23 ( V_51 , V_5 -> V_50 ) ;
F_23 ( V_52 , V_5 -> V_53 ) ;
F_24 ( V_5 , V_54 , 0 , V_55 , 0 , 0 ) ;
F_24 ( V_5 , V_56 , 0 , V_57 , 0 , 0 ) ;
F_24 ( V_5 ,
V_30 , 0 , V_55 , 0 , 0 ) ;
F_24 ( V_5 ,
V_31 , 0 , V_57 , 0 , 0 ) ;
F_25 ( V_5 , V_27 , 0 ) ;
F_26 ( V_5 , V_4 ) ;
error = F_27 ( V_7 -> V_1 , NULL , F_1 ,
V_58 | V_59 ,
L_12 , V_4 ) ;
if ( error < 0 ) {
F_13 ( & V_7 -> V_28 , L_13 ) ;
goto V_43;
}
error = F_28 ( V_4 -> V_5 ) ;
if ( error )
goto V_60;
F_29 ( V_7 , V_4 ) ;
return 0 ;
V_60:
F_30 ( V_7 -> V_1 , V_4 ) ;
V_43:
F_31 ( V_5 ) ;
V_42:
F_32 ( V_4 ) ;
return error ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_34 ( V_7 ) ;
F_30 ( V_7 -> V_1 , V_4 ) ;
F_35 ( V_4 -> V_5 ) ;
F_32 ( V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_61 * V_28 )
{
static const T_2 V_62 [ V_9 ] = {
0x3 , 0x6 , 0xa , 0x3 , 0x36 , 0x3f , 0x2 , 0 , 0 , 0
} ;
struct V_6 * V_7 = F_37 ( V_28 ) ;
int V_11 ;
V_11 = F_19 ( V_7 , V_62 , V_9 ) ;
return V_11 > 0 ? 0 : V_11 ;
}
static int F_38 ( struct V_61 * V_28 )
{
struct V_6 * V_7 = F_37 ( V_28 ) ;
return F_9 ( V_7 ) ;
}
