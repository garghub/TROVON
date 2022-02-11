int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_4 , V_2 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_1 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_6 )
{
int V_3 ;
V_3 = F_5 ( V_1 -> V_4 , V_2 , V_6 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_2 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_6 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 , T_1 * V_8 )
{
int V_3 ;
V_3 = F_7 ( V_1 -> V_4 , V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_3 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_8 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 ,
const T_1 * V_8 )
{
int V_3 ;
V_3 = F_9 ( V_1 -> V_4 , V_2 , V_7 ,
V_8 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_4 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_10 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_9 , T_1 V_10 )
{
int V_3 ;
F_11 ( & V_1 -> V_11 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 < 0 )
goto V_12;
V_3 &= ~ V_9 ;
V_3 |= V_10 ;
V_3 = F_4 ( V_1 , V_2 , V_3 ) ;
V_12:
F_12 ( & V_1 -> V_11 ) ;
return V_3 ;
}
static T_2 F_13 ( int V_13 , void * V_6 )
{
struct V_1 * V_1 = V_6 ;
int V_14 ;
V_15:
V_14 = F_1 ( V_1 , V_16 ) ;
if ( V_14 < 0 )
return V_17 ;
while ( V_14 ) {
int V_18 = F_14 ( V_14 ) ;
F_15 ( V_1 -> V_19 + V_18 ) ;
V_14 &= ~ ( 1 << V_18 ) ;
}
V_14 = F_1 ( V_1 , V_16 ) ;
if ( V_14 )
goto V_15;
return V_20 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_21 = V_1 -> V_19 ;
int V_13 ;
for ( V_13 = V_21 ; V_13 < V_21 + V_22 ; V_13 ++ ) {
F_17 ( V_13 , V_1 ) ;
F_18 ( V_13 , & V_23 ,
V_24 ) ;
F_19 ( V_13 , 1 ) ;
#ifdef F_20
F_21 ( V_13 , V_25 ) ;
#else
F_22 ( V_13 ) ;
#endif
}
return 0 ;
}
static void F_23 ( struct V_1 * V_1 )
{
int V_21 = V_1 -> V_19 ;
int V_13 ;
for ( V_13 = V_21 ; V_13 < V_21 + V_22 ; V_13 ++ ) {
#ifdef F_20
F_21 ( V_13 , 0 ) ;
#endif
F_18 ( V_13 , NULL , NULL ) ;
F_17 ( V_13 , NULL ) ;
}
}
static int F_24 ( struct V_1 * V_1 )
{
int V_26 , V_27 , V_3 ;
V_26 = F_1 ( V_1 , V_28 ) ;
if ( V_26 < 0 )
return V_26 ;
V_27 = F_1 ( V_1 , V_29 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_26 != V_30 ) {
F_3 ( V_1 -> V_5 , L_5 , V_26 ) ;
return - V_31 ;
}
F_25 ( V_1 -> V_5 , L_6 , V_26 , V_27 ) ;
V_3 = F_4 ( V_1 , V_32 ,
V_33
| V_34
| V_35 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_1 , V_36 , 0x1 ) ;
}
static int T_3 F_26 ( struct V_1 * V_1 )
{
int V_3 = 0 ;
unsigned int V_37 = V_1 -> V_38 -> V_39 ;
if ( V_37 & V_40 ) {
V_3 = F_27 ( V_1 -> V_5 , - 1 , V_41 ,
F_28 ( V_41 ) , NULL ,
V_1 -> V_19 , NULL ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_7 ) ;
return V_3 ;
}
F_25 ( V_1 -> V_5 , L_8 ) ;
}
if ( V_37 & V_42 ) {
V_3 = F_27 ( V_1 -> V_5 , - 1 , V_43 ,
F_28 ( V_43 ) , NULL ,
V_1 -> V_19 , NULL ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_9 ) ;
return V_3 ;
}
F_25 ( V_1 -> V_5 , L_10 ) ;
}
return V_3 ;
}
static int T_3 F_29 ( struct V_44 * V_4 ,
const struct V_45 * V_46 )
{
struct V_47 * V_38 = V_4 -> V_5 . V_48 ;
struct V_1 * V_1 ;
int V_3 ;
if ( ! F_30 ( V_4 -> V_49 , V_50
| V_51 ) )
return - V_52 ;
V_1 = F_31 ( sizeof( struct V_1 ) , V_53 ) ;
if ( ! V_1 )
return - V_54 ;
F_32 ( & V_1 -> V_11 ) ;
V_1 -> V_5 = & V_4 -> V_5 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_38 = V_38 ;
V_1 -> V_19 = V_38 -> V_19 ;
V_1 -> V_55 = V_46 -> V_56 ;
F_33 ( V_4 , V_1 ) ;
V_3 = F_24 ( V_1 ) ;
if ( V_3 )
goto V_57;
V_3 = F_16 ( V_1 ) ;
if ( V_3 )
goto V_57;
V_3 = F_34 ( V_1 -> V_4 -> V_13 , NULL , F_13 ,
V_58 | V_59 ,
L_11 , V_1 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_12 , V_3 ) ;
goto V_60;
}
V_3 = F_26 ( V_1 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_13 ) ;
goto V_61;
}
return 0 ;
V_61:
F_35 ( V_1 -> V_4 -> V_13 , V_1 ) ;
V_60:
F_23 ( V_1 ) ;
V_57:
F_36 ( V_1 ) ;
return V_3 ;
}
static int T_4 F_37 ( struct V_44 * V_62 )
{
struct V_1 * V_1 = F_38 ( V_62 ) ;
F_39 ( V_1 -> V_5 ) ;
F_35 ( V_1 -> V_4 -> V_13 , V_1 ) ;
F_23 ( V_1 ) ;
F_36 ( V_1 ) ;
return 0 ;
}
static int F_40 ( struct V_63 * V_5 )
{
struct V_1 * V_1 = F_41 ( V_5 ) ;
struct V_44 * V_62 = V_1 -> V_4 ;
int V_3 = 0 ;
if ( ! F_42 ( & V_62 -> V_5 ) )
V_3 = F_4 ( V_1 , V_64 ,
V_65 ) ;
return V_3 ;
}
static int F_43 ( struct V_63 * V_5 )
{
struct V_1 * V_1 = F_41 ( V_5 ) ;
struct V_44 * V_62 = V_1 -> V_4 ;
int V_3 = 0 ;
if ( ! F_42 ( & V_62 -> V_5 ) )
V_3 = F_4 ( V_1 , V_64 ,
V_66 ) ;
return V_3 ;
}
static int T_5 F_44 ( void )
{
return F_45 ( & V_67 ) ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_67 ) ;
}
