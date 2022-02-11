static inline int F_1 ( T_1 V_1 )
{
return ( ( V_1 & ~ 0x01 ) * 1000 ) / 128 ;
}
static inline T_2 F_2 ( int V_1 )
{
return ( V_1 * 128 ) / 1000 ;
}
static struct V_2 * F_3 ( struct V_3 * V_4 )
{
struct V_2 * V_2 = F_4 ( V_4 ) ;
F_5 ( & V_2 -> V_5 ) ;
if ( F_6 ( V_6 , V_2 -> V_7 + V_8 / 3 ) ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < F_7 ( V_2 -> V_10 ) ; ++ V_9 ) {
int V_11 = F_8 ( V_4 ,
V_12 [ V_9 ] ) ;
if ( V_11 > - 1 )
V_2 -> V_10 [ V_9 ] = F_1 ( V_11 ) ;
}
V_2 -> V_7 = V_6 ;
}
F_9 ( & V_2 -> V_5 ) ;
return V_2 ;
}
static T_3 F_10 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_11 ( V_16 ) ;
struct V_2 * V_2 = F_3 ( F_12 ( V_14 ) ) ;
return sprintf ( V_17 , L_1 , V_2 -> V_10 [ V_19 -> V_20 ] ) ;
}
static T_3 F_13 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
const char * V_17 , T_4 V_21 )
{
struct V_18 * V_19 = F_11 ( V_16 ) ;
struct V_3 * V_4 = F_12 ( V_14 ) ;
struct V_2 * V_2 = F_4 ( V_4 ) ;
long V_1 ;
int V_11 ;
if ( F_14 ( V_17 , 10 , & V_1 ) < 0 )
return - V_22 ;
V_1 = F_15 ( V_1 , - 256000 , 255000 ) ;
F_5 ( & V_2 -> V_5 ) ;
V_2 -> V_10 [ V_19 -> V_20 ] = V_1 ;
V_11 = F_16 ( V_4 , V_12 [ V_19 -> V_20 ] ,
F_2 ( V_1 ) ) ;
F_9 ( & V_2 -> V_5 ) ;
return V_11 ? : V_21 ;
}
static int T_5 F_17 ( struct V_3 * V_4 ,
const struct V_23 * V_24 )
{
struct V_2 * V_2 ;
int V_11 ;
if ( ! F_18 ( V_4 -> V_25 ,
V_26 ) ) {
F_19 ( & V_4 -> V_14 , L_2
L_3 ) ;
return - V_27 ;
}
V_2 = F_20 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 ) {
F_21 ( & V_4 -> V_14 , L_4 ) ;
return - V_29 ;
}
F_22 ( V_4 , V_2 ) ;
V_11 = F_8 ( V_4 , V_30 ) ;
if ( V_11 < 0 ) {
F_19 ( & V_4 -> V_14 , L_5 ) ;
goto V_31;
}
V_2 -> V_32 = V_11 ;
V_11 = F_16 ( V_4 , V_30 ,
V_33 ) ;
if ( V_11 < 0 ) {
F_19 ( & V_4 -> V_14 , L_6 ) ;
goto V_34;
}
V_11 = F_8 ( V_4 , V_30 ) ;
if ( V_11 < 0 ) {
F_19 ( & V_4 -> V_14 , L_5 ) ;
goto V_34;
}
V_11 &= ~ V_35 ;
if ( V_11 != V_33 ) {
F_19 ( & V_4 -> V_14 , L_7 ) ;
V_11 = - V_27 ;
goto V_34;
}
V_2 -> V_7 = V_6 - V_8 ;
F_23 ( & V_2 -> V_5 ) ;
V_11 = F_24 ( & V_4 -> V_14 . V_36 , & V_37 ) ;
if ( V_11 ) {
F_21 ( & V_4 -> V_14 , L_8 ) ;
goto V_34;
}
V_2 -> V_38 = F_25 ( & V_4 -> V_14 ) ;
if ( F_26 ( V_2 -> V_38 ) ) {
F_21 ( & V_4 -> V_14 , L_9 ) ;
V_11 = F_27 ( V_2 -> V_38 ) ;
goto V_39;
}
F_28 ( & V_4 -> V_14 , L_10 ) ;
return 0 ;
V_39:
F_29 ( & V_4 -> V_14 . V_36 , & V_37 ) ;
V_34:
F_16 ( V_4 , V_30 ,
V_2 -> V_32 ) ;
V_31:
F_30 ( V_2 ) ;
return V_11 ;
}
static int T_6 F_31 ( struct V_3 * V_4 )
{
struct V_2 * V_2 = F_4 ( V_4 ) ;
F_32 ( V_2 -> V_38 ) ;
F_29 ( & V_4 -> V_14 . V_36 , & V_37 ) ;
if ( V_2 -> V_32 & V_40 ) {
int V_41 ;
V_41 = F_8 ( V_4 , V_30 ) ;
if ( V_41 >= 0 )
F_16 ( V_4 , V_30 ,
V_41 | V_40 ) ;
}
F_30 ( V_2 ) ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_12 ( V_14 ) ;
int V_41 ;
V_41 = F_8 ( V_4 , V_30 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 |= V_40 ;
return F_16 ( V_4 , V_30 , V_41 ) ;
}
static int F_34 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_12 ( V_14 ) ;
int V_41 ;
V_41 = F_8 ( V_4 , V_30 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 &= ~ V_40 ;
return F_16 ( V_4 , V_30 , V_41 ) ;
}
static int T_7 F_35 ( void )
{
return F_36 ( & V_42 ) ;
}
static void T_8 F_37 ( void )
{
F_38 ( & V_42 ) ;
}
