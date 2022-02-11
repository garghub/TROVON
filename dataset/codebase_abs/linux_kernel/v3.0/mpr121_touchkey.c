static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_7 ;
unsigned int V_9 , V_10 , V_11 ;
int V_12 ;
V_12 = F_2 ( V_6 , V_13 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_1 , V_12 ) ;
goto V_15;
}
V_12 <<= 8 ;
V_12 |= F_2 ( V_6 , V_16 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_6 -> V_14 , L_1 , V_12 ) ;
goto V_15;
}
V_12 &= V_17 ;
V_9 = F_4 ( V_12 ^ V_4 -> V_18 ) - 1 ;
V_11 = V_12 & ( 1 << V_9 ) ;
V_4 -> V_18 = V_12 ;
V_10 = V_4 -> V_19 [ V_9 ] ;
F_5 ( V_8 , V_20 , V_21 , V_9 ) ;
F_6 ( V_8 , V_10 , V_11 ) ;
F_7 ( V_8 ) ;
F_8 ( & V_6 -> V_14 , L_2 , V_9 , V_10 ,
V_11 ? L_3 : L_4 ) ;
V_15:
return V_22 ;
}
static int T_2 F_9 ( const struct V_23 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
const struct V_25 * V_12 ;
unsigned char V_26 , V_27 , V_28 ;
int V_29 , V_30 , V_31 , V_32 ;
for ( V_29 = 0 ; V_29 <= V_33 ; V_29 ++ ) {
V_30 = V_34 + ( V_29 * 2 ) ;
V_32 = F_10 ( V_6 , V_30 , V_35 ) ;
if ( V_32 < 0 )
goto V_36;
V_32 = F_10 ( V_6 , V_30 + 1 ,
V_37 ) ;
if ( V_32 < 0 )
goto V_36;
}
for ( V_29 = 0 ; V_29 < F_11 ( V_38 ) ; V_29 ++ ) {
V_12 = & V_38 [ V_29 ] ;
V_32 = F_10 ( V_6 , V_12 -> V_39 , V_12 -> V_40 ) ;
if ( V_32 < 0 )
goto V_36;
}
V_31 = V_24 -> V_41 / 1000 ;
V_26 = ( ( V_31 - 700 ) * 256 ) / V_31 ;
V_27 = ( V_26 * 65 ) / 100 ;
V_28 = ( V_26 * 90 ) / 100 ;
V_32 = F_10 ( V_6 , V_42 , V_26 ) ;
V_32 |= F_10 ( V_6 , V_43 , V_27 ) ;
V_32 |= F_10 ( V_6 , V_44 , V_28 ) ;
V_32 |= F_10 ( V_6 , V_45 ,
V_4 -> V_46 ) ;
if ( V_32 != 0 )
goto V_36;
F_8 ( & V_6 -> V_14 , L_5 , V_4 -> V_46 ) ;
return 0 ;
V_36:
F_3 ( & V_6 -> V_14 , L_6 , V_32 ) ;
return V_32 ;
}
static int T_2 F_12 ( struct V_5 * V_6 ,
const struct V_47 * V_48 )
{
const struct V_23 * V_24 = V_6 -> V_14 . V_49 ;
struct V_3 * V_4 ;
struct V_7 * V_7 ;
int error ;
int V_29 ;
if ( ! V_24 ) {
F_3 ( & V_6 -> V_14 , L_7 ) ;
return - V_50 ;
}
if ( ! V_24 -> V_51 || ! V_24 -> V_52 ) {
F_3 ( & V_6 -> V_14 , L_8 ) ;
return - V_50 ;
}
if ( V_24 -> V_52 > V_33 ) {
F_3 ( & V_6 -> V_14 , L_9 ) ;
return - V_50 ;
}
if ( ! V_6 -> V_1 ) {
F_3 ( & V_6 -> V_14 , L_10 ) ;
return - V_50 ;
}
V_4 = F_13 ( sizeof( struct V_3 ) , V_53 ) ;
V_7 = F_14 () ;
if ( ! V_4 || ! V_7 ) {
F_3 ( & V_6 -> V_14 , L_11 ) ;
error = - V_54 ;
goto V_55;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_46 = V_24 -> V_52 ;
V_7 -> V_56 = L_12 ;
V_7 -> V_48 . V_57 = V_58 ;
V_7 -> V_14 . V_59 = & V_6 -> V_14 ;
V_7 -> V_60 [ 0 ] = F_15 ( V_61 ) | F_15 ( V_62 ) ;
V_7 -> V_63 = V_4 -> V_19 ;
V_7 -> V_64 = sizeof( V_4 -> V_19 [ 0 ] ) ;
V_7 -> V_65 = V_4 -> V_46 ;
for ( V_29 = 0 ; V_29 < V_24 -> V_52 ; V_29 ++ ) {
F_16 ( V_7 , V_61 , V_24 -> V_51 [ V_29 ] ) ;
V_4 -> V_19 [ V_29 ] = V_24 -> V_51 [ V_29 ] ;
}
error = F_9 ( V_24 , V_4 , V_6 ) ;
if ( error ) {
F_3 ( & V_6 -> V_14 , L_13 ) ;
goto V_55;
}
error = F_17 ( V_6 -> V_1 , NULL ,
F_1 ,
V_66 ,
V_6 -> V_14 . V_67 -> V_56 , V_4 ) ;
if ( error ) {
F_3 ( & V_6 -> V_14 , L_14 ) ;
goto V_55;
}
error = F_18 ( V_7 ) ;
if ( error )
goto V_68;
F_19 ( V_6 , V_4 ) ;
F_20 ( & V_6 -> V_14 , V_24 -> V_69 ) ;
return 0 ;
V_68:
F_21 ( V_6 -> V_1 , V_4 ) ;
V_55:
F_22 ( V_7 ) ;
F_23 ( V_4 ) ;
return error ;
}
static int T_3 F_24 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_25 ( V_6 ) ;
F_21 ( V_6 -> V_1 , V_4 ) ;
F_26 ( V_4 -> V_7 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
static int F_27 ( struct V_70 * V_14 )
{
struct V_5 * V_6 = F_28 ( V_14 ) ;
if ( F_29 ( & V_6 -> V_14 ) )
F_30 ( V_6 -> V_1 ) ;
F_10 ( V_6 , V_45 , 0x00 ) ;
return 0 ;
}
static int F_31 ( struct V_70 * V_14 )
{
struct V_5 * V_6 = F_28 ( V_14 ) ;
struct V_3 * V_4 = F_25 ( V_6 ) ;
if ( F_29 ( & V_6 -> V_14 ) )
F_32 ( V_6 -> V_1 ) ;
F_10 ( V_6 , V_45 ,
V_4 -> V_46 ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
return F_34 ( & V_71 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_71 ) ;
}
