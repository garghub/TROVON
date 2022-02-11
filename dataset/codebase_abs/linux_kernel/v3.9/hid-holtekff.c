static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const T_1 V_5 [ V_6 ] )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
V_2 -> V_8 -> V_9 [ V_7 ] = V_5 [ V_7 ] ;
}
F_2 ( L_1 , 7 , V_5 ) ;
F_3 ( V_4 , V_2 -> V_8 -> V_10 , V_11 ) ;
}
static int F_4 ( struct V_12 * V_13 , void * V_5 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_5 ( V_13 ) ;
struct V_1 * V_2 = V_5 ;
int V_16 , V_17 ;
T_1 V_18 [ V_6 ] =
{ 0x01 , 0x01 , 0xff , 0xff , 0x10 , 0xe0 , 0x00 } ;
V_16 = V_15 -> V_19 . V_20 . V_21 ;
V_17 = V_15 -> V_19 . V_20 . V_22 ;
F_2 ( L_2 , V_16 , V_17 ) ;
if ( ! V_16 && ! V_17 ) {
F_1 ( V_2 , V_4 , V_23 ) ;
return 0 ;
}
if ( V_16 )
V_18 [ 1 ] |= 0x80 ;
if ( V_17 )
V_18 [ 1 ] |= 0x40 ;
V_18 [ 6 ] = F_6 ( 0xf , ( V_16 >> 12 ) + ( V_17 >> 12 ) ) ;
F_1 ( V_2 , V_4 , V_18 ) ;
F_1 ( V_2 , V_4 , V_24 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_25 * V_10 ;
struct V_26 * V_27 = F_8 ( V_4 -> V_28 . V_29 ,
struct V_26 , V_30 ) ;
struct V_31 * V_32 =
& V_4 -> V_33 [ V_34 ] . V_32 ;
struct V_12 * V_13 = V_27 -> V_35 ;
int error ;
if ( F_9 ( V_32 ) ) {
F_10 ( V_4 , L_3 ) ;
return - V_36 ;
}
V_10 = F_8 ( V_32 -> V_29 , struct V_25 , V_30 ) ;
if ( V_10 -> V_37 < 1 || V_10 -> V_8 [ 0 ] -> V_38 != 7 ) {
F_10 ( V_4 , L_4 ) ;
return - V_36 ;
}
V_2 = F_11 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
F_12 ( V_41 , V_13 -> V_42 ) ;
V_2 -> V_8 = V_10 -> V_8 [ 0 ] ;
F_1 ( V_2 , V_4 , V_43 ) ;
F_1 ( V_2 , V_4 , V_23 ) ;
error = F_13 ( V_13 , V_2 , F_4 ) ;
if ( error ) {
F_14 ( V_2 ) ;
return error ;
}
F_15 ( V_4 , L_5 ) ;
return 0 ;
}
static inline int F_7 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_16 ( struct V_3 * V_44 , const struct V_45 * V_46 )
{
int V_47 ;
V_47 = F_17 ( V_44 ) ;
if ( V_47 ) {
F_10 ( V_44 , L_6 ) ;
goto V_48;
}
V_47 = F_18 ( V_44 , V_49 & ~ V_50 ) ;
if ( V_47 ) {
F_10 ( V_44 , L_7 ) ;
goto V_48;
}
F_7 ( V_44 ) ;
return 0 ;
V_48:
return V_47 ;
}
