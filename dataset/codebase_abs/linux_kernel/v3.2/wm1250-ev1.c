static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
int V_8 ;
if ( V_6 )
V_8 = V_6 -> V_9 [ V_10 ] . V_11 ;
else
V_8 = - 1 ;
switch ( V_4 ) {
case V_12 :
break;
case V_13 :
break;
case V_14 :
if ( V_8 >= 0 )
F_3 ( V_8 , 1 ) ;
break;
case V_15 :
if ( V_8 >= 0 )
F_3 ( V_8 , 0 ) ;
break;
}
V_2 -> V_16 . V_17 = V_4 ;
return 0 ;
}
static int T_1 F_4 ( struct V_18 * V_19 )
{
struct F_4 * V_20 = F_5 ( & V_19 -> V_7 ) ;
struct V_5 * V_6 ;
int V_21 , V_22 ;
if ( ! V_20 )
return 0 ;
V_6 = F_6 ( sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 ) {
F_7 ( & V_19 -> V_7 , L_1 ) ;
V_22 = - V_24 ;
goto V_25;
}
for ( V_21 = 0 ; V_21 < F_8 ( V_6 -> V_9 ) ; V_21 ++ ) {
V_6 -> V_9 [ V_21 ] . V_11 = V_20 -> V_9 [ V_21 ] ;
V_6 -> V_9 [ V_21 ] . V_26 = V_27 [ V_21 ] ;
V_6 -> V_9 [ V_21 ] . V_28 = V_29 ;
}
V_6 -> V_9 [ V_30 ] . V_28 = V_31 ;
V_6 -> V_9 [ V_32 ] . V_28 = V_31 ;
V_22 = F_9 ( V_6 -> V_9 , F_8 ( V_6 -> V_9 ) ) ;
if ( V_22 != 0 ) {
F_7 ( & V_19 -> V_7 , L_2 , V_22 ) ;
goto V_33;
}
F_10 ( & V_19 -> V_7 , V_6 ) ;
return V_22 ;
V_33:
F_11 ( V_6 ) ;
V_25:
return V_22 ;
}
static void F_12 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_2 ( & V_19 -> V_7 ) ;
if ( V_6 ) {
F_13 ( V_6 -> V_9 , F_8 ( V_6 -> V_9 ) ) ;
F_11 ( V_6 ) ;
}
}
static int T_1 F_14 ( struct V_18 * V_19 ,
const struct V_34 * V_35 )
{
int V_36 , V_37 , V_38 , V_22 ;
F_10 ( & V_19 -> V_7 , NULL ) ;
V_37 = F_15 ( V_19 , 0 ) ;
if ( V_37 < 0 ) {
F_7 ( & V_19 -> V_7 , L_3 , V_37 ) ;
return V_37 ;
}
V_36 = ( V_37 & 0xfe ) >> 2 ;
V_38 = V_37 & 0x3 ;
if ( V_36 != 1 ) {
F_7 ( & V_19 -> V_7 , L_4 , V_36 ) ;
return - V_39 ;
}
F_16 ( & V_19 -> V_7 , L_5 , V_38 + 1 ) ;
V_22 = F_4 ( V_19 ) ;
if ( V_22 != 0 )
return V_22 ;
V_22 = F_17 ( & V_19 -> V_7 , & V_40 ,
& V_41 , 1 ) ;
if ( V_22 != 0 ) {
F_7 ( & V_19 -> V_7 , L_6 , V_22 ) ;
F_12 ( V_19 ) ;
return V_22 ;
}
return 0 ;
}
static int T_2 F_18 ( struct V_18 * V_19 )
{
F_19 ( & V_19 -> V_7 ) ;
F_12 ( V_19 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
int V_22 = 0 ;
V_22 = F_21 ( & V_42 ) ;
if ( V_22 != 0 )
F_22 ( L_7 , V_22 ) ;
return V_22 ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_42 ) ;
}
