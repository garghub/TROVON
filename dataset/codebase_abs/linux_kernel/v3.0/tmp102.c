static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 , V_3 ) ;
return V_4 < 0 ? V_4 : F_3 ( V_4 ) ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_5 )
{
return F_5 ( V_2 , V_3 , F_3 ( V_5 ) ) ;
}
static inline int F_6 ( T_3 V_5 )
{
return ( ( V_5 & ~ 0x01 ) * 1000 ) / 128 ;
}
static inline T_2 F_7 ( int V_5 )
{
return ( V_5 * 128 ) / 1000 ;
}
static struct V_6 * F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_9 ( V_2 ) ;
F_10 ( & V_6 -> V_7 ) ;
if ( F_11 ( V_8 , V_6 -> V_9 + V_10 / 3 ) ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < F_12 ( V_6 -> V_12 ) ; ++ V_11 ) {
int V_13 = F_1 ( V_2 , V_14 [ V_11 ] ) ;
if ( V_13 > - 1 )
V_6 -> V_12 [ V_11 ] = F_6 ( V_13 ) ;
}
V_6 -> V_9 = V_8 ;
}
F_13 ( & V_6 -> V_7 ) ;
return V_6 ;
}
static T_4 F_14 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_20 * V_21 = F_15 ( V_18 ) ;
struct V_6 * V_6 = F_8 ( F_16 ( V_16 ) ) ;
return sprintf ( V_19 , L_1 , V_6 -> V_12 [ V_21 -> V_22 ] ) ;
}
static T_4 F_17 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_5 V_23 )
{
struct V_20 * V_21 = F_15 ( V_18 ) ;
struct V_1 * V_2 = F_16 ( V_16 ) ;
struct V_6 * V_6 = F_9 ( V_2 ) ;
long V_5 ;
int V_13 ;
if ( F_18 ( V_19 , 10 , & V_5 ) < 0 )
return - V_24 ;
V_5 = F_19 ( V_5 , - 256000 , 255000 ) ;
F_10 ( & V_6 -> V_7 ) ;
V_6 -> V_12 [ V_21 -> V_22 ] = V_5 ;
V_13 = F_4 ( V_2 , V_14 [ V_21 -> V_22 ] ,
F_7 ( V_5 ) ) ;
F_13 ( & V_6 -> V_7 ) ;
return V_13 ? : V_23 ;
}
static int T_6 F_20 ( struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_6 * V_6 ;
int V_13 ;
if ( ! F_21 ( V_2 -> V_27 ,
V_28 ) ) {
F_22 ( & V_2 -> V_16 , L_2
L_3 ) ;
return - V_29 ;
}
V_6 = F_23 ( sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 ) {
F_24 ( & V_2 -> V_16 , L_4 ) ;
return - V_31 ;
}
F_25 ( V_2 , V_6 ) ;
V_13 = F_1 ( V_2 , V_32 ) ;
if ( V_13 < 0 ) {
F_22 ( & V_2 -> V_16 , L_5 ) ;
goto V_33;
}
V_6 -> V_34 = V_13 ;
V_13 = F_4 ( V_2 , V_32 , V_35 ) ;
if ( V_13 < 0 ) {
F_22 ( & V_2 -> V_16 , L_6 ) ;
goto V_36;
}
V_13 = F_1 ( V_2 , V_32 ) ;
if ( V_13 < 0 ) {
F_22 ( & V_2 -> V_16 , L_5 ) ;
goto V_36;
}
V_13 &= ~ V_37 ;
if ( V_13 != V_35 ) {
F_22 ( & V_2 -> V_16 , L_7 ) ;
V_13 = - V_29 ;
goto V_36;
}
V_6 -> V_9 = V_8 - V_10 ;
F_26 ( & V_6 -> V_7 ) ;
V_13 = F_27 ( & V_2 -> V_16 . V_38 , & V_39 ) ;
if ( V_13 ) {
F_24 ( & V_2 -> V_16 , L_8 ) ;
goto V_36;
}
V_6 -> V_40 = F_28 ( & V_2 -> V_16 ) ;
if ( F_29 ( V_6 -> V_40 ) ) {
F_24 ( & V_2 -> V_16 , L_9 ) ;
V_13 = F_30 ( V_6 -> V_40 ) ;
goto V_41;
}
F_31 ( & V_2 -> V_16 , L_10 ) ;
return 0 ;
V_41:
F_32 ( & V_2 -> V_16 . V_38 , & V_39 ) ;
V_36:
F_4 ( V_2 , V_32 , V_6 -> V_34 ) ;
V_33:
F_33 ( V_6 ) ;
return V_13 ;
}
static int T_7 F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_9 ( V_2 ) ;
F_35 ( V_6 -> V_40 ) ;
F_32 ( & V_2 -> V_16 . V_38 , & V_39 ) ;
if ( V_6 -> V_34 & V_42 ) {
int V_43 ;
V_43 = F_1 ( V_2 , V_32 ) ;
if ( V_43 >= 0 )
F_4 ( V_2 , V_32 ,
V_43 | V_42 ) ;
}
F_33 ( V_6 ) ;
return 0 ;
}
static int F_36 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_16 ( V_16 ) ;
int V_43 ;
V_43 = F_1 ( V_2 , V_32 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 |= V_42 ;
return F_4 ( V_2 , V_32 , V_43 ) ;
}
static int F_37 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_16 ( V_16 ) ;
int V_43 ;
V_43 = F_1 ( V_2 , V_32 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 &= ~ V_42 ;
return F_4 ( V_2 , V_32 , V_43 ) ;
}
static int T_8 F_38 ( void )
{
return F_39 ( & V_44 ) ;
}
static void T_9 F_40 ( void )
{
F_41 ( & V_44 ) ;
}
