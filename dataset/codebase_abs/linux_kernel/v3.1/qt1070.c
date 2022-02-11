static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 ,
L_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
int V_4 ;
V_4 = F_5 ( V_2 , V_3 , V_6 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 ,
L_2 , V_4 ) ;
return V_4 ;
}
static bool T_2 F_6 ( struct V_1 * V_2 )
{
int V_7 , V_8 ;
V_7 = F_1 ( V_2 , V_9 ) ;
if ( V_7 != V_10 ) {
F_3 ( & V_2 -> V_5 , L_3 , V_7 ) ;
return false ;
}
V_8 = F_1 ( V_2 , V_11 ) ;
if ( V_8 < 0 ) {
F_3 ( & V_2 -> V_5 , L_4 ) ;
return false ;
}
F_7 ( & V_2 -> V_5 , L_5 , V_8 ) ;
return true ;
}
static T_3 F_8 ( int V_12 , void * V_13 )
{
struct V_14 * V_6 = V_13 ;
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_15 * V_16 = V_6 -> V_16 ;
int V_17 ;
T_1 V_18 , V_19 , V_20 = 0x01 ;
F_1 ( V_2 , V_21 ) ;
V_18 = F_1 ( V_2 , V_22 ) ;
for ( V_17 = 0 ; V_17 < F_9 ( V_23 ) ; V_17 ++ ) {
V_19 = V_18 & V_20 ;
if ( ( V_6 -> V_24 & V_20 ) != V_19 )
F_10 ( V_16 , V_6 -> V_25 [ V_17 ] , V_19 ) ;
V_20 <<= 1 ;
}
F_11 ( V_16 ) ;
V_6 -> V_24 = V_18 ;
return V_26 ;
}
static int T_2 F_12 ( struct V_1 * V_2 ,
const struct V_27 * V_7 )
{
struct V_14 * V_6 ;
struct V_15 * V_16 ;
int V_17 ;
int V_28 ;
V_28 = F_13 ( V_2 -> V_29 , V_30 ) ;
if ( ! V_28 ) {
F_3 ( & V_2 -> V_5 , L_6 ,
F_14 ( & V_2 -> V_29 -> V_5 ) ) ;
return - V_31 ;
}
if ( ! V_2 -> V_12 ) {
F_3 ( & V_2 -> V_5 , L_7 ) ;
return - V_32 ;
}
if ( ! F_6 ( V_2 ) )
return - V_31 ;
V_6 = F_15 ( sizeof( struct V_14 ) , V_33 ) ;
V_16 = F_16 () ;
if ( ! V_6 || ! V_16 ) {
F_3 ( & V_2 -> V_5 , L_8 ) ;
V_28 = - V_34 ;
goto V_35;
}
V_6 -> V_2 = V_2 ;
V_6 -> V_16 = V_16 ;
V_6 -> V_12 = V_2 -> V_12 ;
V_16 -> V_36 = L_9 ;
V_16 -> V_5 . V_37 = & V_2 -> V_5 ;
V_16 -> V_7 . V_38 = V_39 ;
V_16 -> V_40 = V_6 -> V_25 ;
V_16 -> V_41 = sizeof( V_6 -> V_25 [ 0 ] ) ;
V_16 -> V_42 = F_9 ( V_23 ) ;
F_17 ( V_43 , V_16 -> V_44 ) ;
for ( V_17 = 0 ; V_17 < F_9 ( V_23 ) ; V_17 ++ ) {
V_6 -> V_25 [ V_17 ] = V_23 [ V_17 ] ;
F_17 ( V_23 [ V_17 ] , V_16 -> V_45 ) ;
}
F_4 ( V_2 , V_46 , 1 ) ;
F_18 ( V_47 ) ;
F_4 ( V_2 , V_48 , 1 ) ;
F_18 ( V_49 ) ;
V_28 = F_19 ( V_2 -> V_12 , NULL , F_8 ,
V_50 , V_2 -> V_5 . V_51 -> V_36 , V_6 ) ;
if ( V_28 ) {
F_3 ( & V_2 -> V_5 , L_10 ) ;
goto V_35;
}
V_28 = F_20 ( V_6 -> V_16 ) ;
if ( V_28 ) {
F_3 ( & V_2 -> V_5 , L_11 ) ;
goto V_52;
}
F_21 ( V_2 , V_6 ) ;
F_1 ( V_2 , V_21 ) ;
return 0 ;
V_52:
F_22 ( V_2 -> V_12 , V_6 ) ;
V_35:
F_23 ( V_16 ) ;
F_24 ( V_6 ) ;
return V_28 ;
}
static int T_4 F_25 ( struct V_1 * V_2 )
{
struct V_14 * V_6 = F_26 ( V_2 ) ;
F_22 ( V_2 -> V_12 , V_6 ) ;
F_27 ( V_6 -> V_16 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_53 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_53 ) ;
}
