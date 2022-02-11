static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
F_2 ( & V_2 -> V_4 -> V_5 -> V_6 , L_1 ,
V_3 , V_2 -> V_7 , V_2 -> V_8 ) ;
}
static void F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_4 = F_4 ( V_10 ) ;
int V_8 = F_5 ( V_10 ) ;
F_1 ( & V_4 -> V_12 [ V_8 ] , L_2 ) ;
F_6 ( F_7 ( V_8 ) , V_4 -> V_13 + V_14 ) ;
}
static void F_8 ( struct V_9 * V_10 )
{
struct V_11 * V_4 = F_4 ( V_10 ) ;
int V_8 = F_5 ( V_10 ) ;
F_1 ( & V_4 -> V_12 [ V_8 ] , L_3 ) ;
F_6 ( F_7 ( V_8 ) , V_4 -> V_13 + V_15 ) ;
}
static int F_9 ( struct V_9 * V_10 , unsigned int type )
{
struct V_11 * V_4 = F_4 ( V_10 ) ;
int V_8 = F_5 ( V_10 ) ;
unsigned char V_16 = V_17 [ type & V_18 ] ;
T_1 V_19 ;
F_1 ( & V_4 -> V_12 [ V_8 ] , L_4 ) ;
if ( ! V_16 )
return - V_20 ;
V_19 = F_10 ( V_4 -> V_21 + F_11 ( V_8 ) ) ;
V_19 &= ~ 0x3f ;
V_19 |= V_16 ;
F_6 ( V_19 , V_4 -> V_21 + F_11 ( V_8 ) ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 , unsigned int V_22 )
{
struct V_11 * V_4 = F_4 ( V_10 ) ;
int V_8 = F_5 ( V_10 ) ;
F_13 ( V_4 -> V_12 [ V_8 ] . V_7 , V_22 ) ;
if ( ! V_4 -> V_23 )
return 0 ;
if ( V_22 )
F_14 ( V_4 -> V_23 ) ;
else
F_15 ( V_4 -> V_23 ) ;
return 0 ;
}
static T_2 F_16 ( int V_12 , void * V_24 )
{
struct V_1 * V_2 = V_24 ;
struct V_11 * V_4 = V_2 -> V_4 ;
T_1 V_25 = F_7 ( V_2 -> V_8 ) ;
F_1 ( V_2 , L_5 ) ;
if ( F_10 ( V_4 -> V_21 + V_26 ) & V_25 ) {
F_6 ( V_25 , V_4 -> V_21 + V_26 ) ;
F_1 ( V_2 , L_6 ) ;
F_17 ( F_18 ( V_4 -> V_27 , V_2 -> V_8 ) ) ;
return V_28 ;
}
return V_29 ;
}
static int F_19 ( struct V_27 * V_30 , unsigned int V_31 ,
T_3 V_32 )
{
struct V_11 * V_4 = V_30 -> V_33 ;
F_1 ( & V_4 -> V_12 [ V_32 ] , L_7 ) ;
F_20 ( V_31 , V_30 -> V_33 ) ;
F_21 ( V_31 , & V_34 ) ;
F_22 ( V_31 , & V_4 -> V_35 , V_36 ) ;
return 0 ;
}
static int F_23 ( struct V_37 * V_5 )
{
struct V_11 * V_4 ;
struct V_38 * V_39 ;
struct V_38 * V_12 ;
struct V_35 * V_35 ;
const char * V_40 = F_24 ( & V_5 -> V_6 ) ;
int V_41 ;
int V_42 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 ) {
F_26 ( & V_5 -> V_6 , L_8 ) ;
V_41 = - V_44 ;
goto V_45;
}
V_4 -> V_5 = V_5 ;
F_27 ( V_5 , V_4 ) ;
V_4 -> V_23 = F_28 ( & V_5 -> V_6 , NULL ) ;
if ( F_29 ( V_4 -> V_23 ) ) {
F_30 ( & V_5 -> V_6 , L_9 ) ;
V_4 -> V_23 = NULL ;
}
F_31 ( & V_5 -> V_6 ) ;
F_32 ( & V_5 -> V_6 ) ;
V_39 = F_33 ( V_5 , V_46 , 0 ) ;
if ( ! V_39 ) {
F_26 ( & V_5 -> V_6 , L_10 ) ;
V_41 = - V_20 ;
goto V_47;
}
for ( V_42 = 0 ; V_42 < V_48 ; V_42 ++ ) {
V_12 = F_33 ( V_5 , V_49 , V_42 ) ;
if ( ! V_12 )
break;
V_4 -> V_12 [ V_42 ] . V_4 = V_4 ;
V_4 -> V_12 [ V_42 ] . V_8 = V_42 ;
V_4 -> V_12 [ V_42 ] . V_7 = V_12 -> V_50 ;
}
V_4 -> V_51 = V_42 ;
if ( V_4 -> V_51 < 1 ) {
F_26 ( & V_5 -> V_6 , L_11 ) ;
V_41 = - V_20 ;
goto V_47;
}
V_4 -> V_21 = F_34 ( V_39 -> V_50 , F_35 ( V_39 ) ) ;
if ( ! V_4 -> V_21 ) {
F_26 ( & V_5 -> V_6 , L_12 ) ;
V_41 = - V_52 ;
goto V_53;
}
V_4 -> V_13 = V_4 -> V_21 + F_36 ( 0 ) ;
V_35 = & V_4 -> V_35 ;
V_35 -> V_40 = V_40 ;
V_35 -> V_54 = F_8 ;
V_35 -> V_55 = F_3 ;
V_35 -> V_56 = F_9 ;
V_35 -> V_57 = F_12 ;
V_35 -> V_58 = V_59 ;
V_4 -> V_27 = F_37 ( V_5 -> V_6 . V_60 ,
V_4 -> V_51 ,
& V_61 , V_4 ) ;
if ( ! V_4 -> V_27 ) {
V_41 = - V_52 ;
F_26 ( & V_5 -> V_6 , L_13 ) ;
goto V_53;
}
for ( V_42 = 0 ; V_42 < V_4 -> V_51 ; V_42 ++ ) {
if ( F_38 ( V_4 -> V_12 [ V_42 ] . V_7 , F_16 ,
0 , V_40 , & V_4 -> V_12 [ V_42 ] ) ) {
F_26 ( & V_5 -> V_6 , L_14 ) ;
V_41 = - V_62 ;
goto V_63;
}
}
F_39 ( & V_5 -> V_6 , L_15 , V_4 -> V_51 ) ;
return 0 ;
V_63:
while ( -- V_42 >= 0 )
F_40 ( V_4 -> V_12 [ V_42 ] . V_7 , & V_4 -> V_12 [ V_42 ] ) ;
F_41 ( V_4 -> V_27 ) ;
V_53:
F_42 ( V_4 -> V_21 ) ;
V_47:
F_43 ( & V_5 -> V_6 ) ;
F_44 ( & V_5 -> V_6 ) ;
F_45 ( V_4 ) ;
V_45:
return V_41 ;
}
static int F_46 ( struct V_37 * V_5 )
{
struct V_11 * V_4 = F_47 ( V_5 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_4 -> V_51 ; V_42 ++ )
F_40 ( V_4 -> V_12 [ V_42 ] . V_7 , & V_4 -> V_12 [ V_42 ] ) ;
F_41 ( V_4 -> V_27 ) ;
F_42 ( V_4 -> V_21 ) ;
F_43 ( & V_5 -> V_6 ) ;
F_44 ( & V_5 -> V_6 ) ;
F_45 ( V_4 ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_64 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_64 ) ;
}
