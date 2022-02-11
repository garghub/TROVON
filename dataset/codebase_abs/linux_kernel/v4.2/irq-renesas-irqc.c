static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
F_2 ( & V_2 -> V_4 -> V_5 -> V_6 , L_1 ,
V_3 , V_2 -> V_7 , V_2 -> V_8 , V_2 -> V_9 ) ;
}
static void F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_4 = F_4 ( V_11 ) ;
int V_8 = F_5 ( V_11 ) ;
F_1 ( & V_4 -> V_13 [ V_8 ] , L_2 ) ;
F_6 ( F_7 ( V_8 ) , V_4 -> V_14 + V_15 ) ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_4 = F_4 ( V_11 ) ;
int V_8 = F_5 ( V_11 ) ;
F_1 ( & V_4 -> V_13 [ V_8 ] , L_3 ) ;
F_6 ( F_7 ( V_8 ) , V_4 -> V_14 + V_16 ) ;
}
static int F_9 ( struct V_10 * V_11 , unsigned int type )
{
struct V_12 * V_4 = F_4 ( V_11 ) ;
int V_8 = F_5 ( V_11 ) ;
unsigned char V_17 = V_18 [ type & V_19 ] ;
T_1 V_20 ;
F_1 ( & V_4 -> V_13 [ V_8 ] , L_4 ) ;
if ( ! V_17 )
return - V_21 ;
V_20 = F_10 ( V_4 -> V_22 + F_11 ( V_8 ) ) ;
V_20 &= ~ 0x3f ;
V_20 |= V_17 ;
F_6 ( V_20 , V_4 -> V_22 + F_11 ( V_8 ) ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 , unsigned int V_23 )
{
struct V_12 * V_4 = F_4 ( V_11 ) ;
if ( ! V_4 -> V_24 )
return 0 ;
if ( V_23 )
F_13 ( V_4 -> V_24 ) ;
else
F_14 ( V_4 -> V_24 ) ;
return 0 ;
}
static T_2 F_15 ( int V_13 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_12 * V_4 = V_2 -> V_4 ;
T_1 V_26 = F_7 ( V_2 -> V_8 ) ;
F_1 ( V_2 , L_5 ) ;
if ( F_10 ( V_4 -> V_22 + V_27 ) & V_26 ) {
F_6 ( V_26 , V_4 -> V_22 + V_27 ) ;
F_1 ( V_2 , L_6 ) ;
F_16 ( V_2 -> V_9 ) ;
return V_28 ;
}
return V_29 ;
}
static int F_17 ( struct V_30 * V_31 , unsigned int V_32 ,
T_3 V_33 )
{
struct V_12 * V_4 = V_31 -> V_34 ;
V_4 -> V_13 [ V_33 ] . V_9 = V_32 ;
V_4 -> V_13 [ V_33 ] . V_8 = V_33 ;
F_1 ( & V_4 -> V_13 [ V_33 ] , L_7 ) ;
F_18 ( V_32 , V_31 -> V_34 ) ;
F_19 ( V_32 , & V_4 -> V_35 , V_36 ) ;
F_20 ( V_32 , V_37 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_5 )
{
struct V_12 * V_4 ;
struct V_39 * V_40 ;
struct V_39 * V_13 ;
struct V_35 * V_35 ;
const char * V_41 = F_22 ( & V_5 -> V_6 ) ;
int V_42 ;
int V_43 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 ) {
F_24 ( & V_5 -> V_6 , L_8 ) ;
V_42 = - V_45 ;
goto V_46;
}
V_4 -> V_5 = V_5 ;
F_25 ( V_5 , V_4 ) ;
V_4 -> V_24 = F_26 ( & V_5 -> V_6 , NULL ) ;
if ( F_27 ( V_4 -> V_24 ) ) {
F_28 ( & V_5 -> V_6 , L_9 ) ;
V_4 -> V_24 = NULL ;
}
F_29 ( & V_5 -> V_6 ) ;
F_30 ( & V_5 -> V_6 ) ;
V_40 = F_31 ( V_5 , V_47 , 0 ) ;
if ( ! V_40 ) {
F_24 ( & V_5 -> V_6 , L_10 ) ;
V_42 = - V_21 ;
goto V_48;
}
for ( V_43 = 0 ; V_43 < V_49 ; V_43 ++ ) {
V_13 = F_31 ( V_5 , V_50 , V_43 ) ;
if ( ! V_13 )
break;
V_4 -> V_13 [ V_43 ] . V_4 = V_4 ;
V_4 -> V_13 [ V_43 ] . V_7 = V_13 -> V_51 ;
}
V_4 -> V_52 = V_43 ;
if ( V_4 -> V_52 < 1 ) {
F_24 ( & V_5 -> V_6 , L_11 ) ;
V_42 = - V_21 ;
goto V_48;
}
V_4 -> V_22 = F_32 ( V_40 -> V_51 , F_33 ( V_40 ) ) ;
if ( ! V_4 -> V_22 ) {
F_24 ( & V_5 -> V_6 , L_12 ) ;
V_42 = - V_53 ;
goto V_54;
}
V_4 -> V_14 = V_4 -> V_22 + F_34 ( 0 ) ;
V_35 = & V_4 -> V_35 ;
V_35 -> V_41 = V_41 ;
V_35 -> V_55 = F_8 ;
V_35 -> V_56 = F_3 ;
V_35 -> V_57 = F_9 ;
V_35 -> V_58 = F_12 ;
V_35 -> V_59 = V_60 ;
V_4 -> V_30 = F_35 ( V_5 -> V_6 . V_61 ,
V_4 -> V_52 , 0 ,
& V_62 , V_4 ) ;
if ( ! V_4 -> V_30 ) {
V_42 = - V_53 ;
F_24 ( & V_5 -> V_6 , L_13 ) ;
goto V_54;
}
for ( V_43 = 0 ; V_43 < V_4 -> V_52 ; V_43 ++ ) {
if ( F_36 ( V_4 -> V_13 [ V_43 ] . V_7 , F_15 ,
0 , V_41 , & V_4 -> V_13 [ V_43 ] ) ) {
F_24 ( & V_5 -> V_6 , L_14 ) ;
V_42 = - V_63 ;
goto V_64;
}
}
F_37 ( & V_5 -> V_6 , L_15 , V_4 -> V_52 ) ;
return 0 ;
V_64:
while ( -- V_43 >= 0 )
F_38 ( V_4 -> V_13 [ V_43 ] . V_7 , & V_4 -> V_13 [ V_43 ] ) ;
F_39 ( V_4 -> V_30 ) ;
V_54:
F_40 ( V_4 -> V_22 ) ;
V_48:
F_41 ( & V_5 -> V_6 ) ;
F_42 ( & V_5 -> V_6 ) ;
F_43 ( V_4 ) ;
V_46:
return V_42 ;
}
static int F_44 ( struct V_38 * V_5 )
{
struct V_12 * V_4 = F_45 ( V_5 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_4 -> V_52 ; V_43 ++ )
F_38 ( V_4 -> V_13 [ V_43 ] . V_7 , & V_4 -> V_13 [ V_43 ] ) ;
F_39 ( V_4 -> V_30 ) ;
F_40 ( V_4 -> V_22 ) ;
F_41 ( & V_5 -> V_6 ) ;
F_42 ( & V_5 -> V_6 ) ;
F_43 ( V_4 ) ;
return 0 ;
}
static int T_4 F_46 ( void )
{
return F_47 ( & V_65 ) ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_65 ) ;
}
