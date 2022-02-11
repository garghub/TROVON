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
struct V_5 * V_6 = V_2 -> V_6 ;
F_5 ( & V_2 -> V_7 ) ;
if ( F_6 ( V_8 , V_2 -> V_9 + V_10 / 3 ) ) {
int V_11 ;
for ( V_11 = 0 ; V_11 < F_7 ( V_2 -> V_12 ) ; ++ V_11 ) {
int V_13 = F_8 ( V_6 ,
V_14 [ V_11 ] ) ;
if ( V_13 > - 1 )
V_2 -> V_12 [ V_11 ] = F_1 ( V_13 ) ;
}
V_2 -> V_9 = V_8 ;
}
F_9 ( & V_2 -> V_7 ) ;
return V_2 ;
}
static int F_10 ( void * V_4 , int * V_12 )
{
struct V_2 * V_2 = F_3 ( V_4 ) ;
* V_12 = V_2 -> V_12 [ 0 ] ;
return 0 ;
}
static T_3 F_11 ( struct V_3 * V_4 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_12 ( V_16 ) ;
struct V_2 * V_2 = F_3 ( V_4 ) ;
return sprintf ( V_17 , L_1 , V_2 -> V_12 [ V_19 -> V_20 ] ) ;
}
static T_3 F_13 ( struct V_3 * V_4 ,
struct V_15 * V_16 ,
const char * V_17 , T_4 V_21 )
{
struct V_18 * V_19 = F_12 ( V_16 ) ;
struct V_2 * V_2 = F_4 ( V_4 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
long V_1 ;
int V_13 ;
if ( F_14 ( V_17 , 10 , & V_1 ) < 0 )
return - V_22 ;
V_1 = F_15 ( V_1 , - 256000 , 255000 ) ;
F_5 ( & V_2 -> V_7 ) ;
V_2 -> V_12 [ V_19 -> V_20 ] = V_1 ;
V_13 = F_16 ( V_6 , V_14 [ V_19 -> V_20 ] ,
F_2 ( V_1 ) ) ;
F_9 ( & V_2 -> V_7 ) ;
return V_13 ? : V_21 ;
}
static int F_17 ( struct V_5 * V_6 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
struct V_3 * V_25 ;
struct V_2 * V_2 ;
int V_13 ;
if ( ! F_18 ( V_6 -> V_26 ,
V_27 ) ) {
F_19 ( V_4 ,
L_2 ) ;
return - V_28 ;
}
V_2 = F_20 ( V_4 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
F_21 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_13 = F_8 ( V_6 , V_31 ) ;
if ( V_13 < 0 ) {
F_19 ( V_4 , L_3 ) ;
return V_13 ;
}
V_2 -> V_32 = V_13 ;
V_13 = F_16 ( V_6 , V_31 ,
V_33 ) ;
if ( V_13 < 0 ) {
F_19 ( V_4 , L_4 ) ;
goto V_34;
}
V_13 = F_8 ( V_6 , V_31 ) ;
if ( V_13 < 0 ) {
F_19 ( V_4 , L_3 ) ;
goto V_34;
}
V_13 &= ~ V_35 ;
if ( V_13 != V_33 ) {
F_19 ( V_4 , L_5 ) ;
V_13 = - V_28 ;
goto V_34;
}
V_2 -> V_9 = V_8 - V_10 ;
F_22 ( & V_2 -> V_7 ) ;
V_25 = F_23 ( V_4 , V_6 -> V_36 ,
V_2 , V_37 ) ;
if ( F_24 ( V_25 ) ) {
F_25 ( V_4 , L_6 ) ;
V_13 = F_26 ( V_25 ) ;
goto V_34;
}
V_2 -> V_25 = V_25 ;
V_2 -> V_38 = F_27 ( V_25 , 0 , V_25 ,
& V_39 ) ;
if ( F_24 ( V_2 -> V_38 ) )
V_2 -> V_38 = NULL ;
F_28 ( V_4 , L_7 ) ;
return 0 ;
V_34:
F_16 ( V_6 , V_31 ,
V_2 -> V_32 ) ;
return V_13 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_2 * V_2 = F_30 ( V_6 ) ;
F_31 ( V_2 -> V_25 , V_2 -> V_38 ) ;
F_32 ( V_2 -> V_25 ) ;
if ( V_2 -> V_32 & V_40 ) {
int V_41 ;
V_41 = F_8 ( V_6 , V_31 ) ;
if ( V_41 >= 0 )
F_16 ( V_6 , V_31 ,
V_41 | V_40 ) ;
}
return 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_34 ( V_4 ) ;
int V_41 ;
V_41 = F_8 ( V_6 , V_31 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 |= V_40 ;
return F_16 ( V_6 , V_31 , V_41 ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_34 ( V_4 ) ;
int V_41 ;
V_41 = F_8 ( V_6 , V_31 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 &= ~ V_40 ;
return F_16 ( V_6 , V_31 , V_41 ) ;
}
