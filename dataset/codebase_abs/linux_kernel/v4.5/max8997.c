int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_4 ( V_2 , V_3 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 &= 0xff ;
* V_4 = V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , int V_9 , T_1 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_7 ( V_2 , V_3 , V_9 , V_10 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_9 ( V_2 , V_3 , V_11 ) ;
F_5 ( & V_6 -> V_8 ) ;
return V_7 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_3 , int V_9 , T_1 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_11 ( V_2 , V_3 , V_9 , V_10 ) ;
F_5 ( & V_6 -> V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 , T_1 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
F_3 ( & V_6 -> V_8 ) ;
V_7 = F_4 ( V_2 , V_3 ) ;
if ( V_7 >= 0 ) {
T_1 V_14 = V_7 & 0xff ;
T_1 V_15 = ( V_12 & V_13 ) | ( V_14 & ( ~ V_13 ) ) ;
V_7 = F_9 ( V_2 , V_3 , V_15 ) ;
}
F_5 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static struct V_16 * F_13 (
struct V_17 * V_18 )
{
struct V_16 * V_19 ;
V_19 = F_14 ( V_18 , sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 ) {
F_15 ( V_18 , L_1 ) ;
return F_16 ( - V_21 ) ;
}
V_19 -> V_22 = F_17 ( V_18 -> V_23 , 1 ) ;
return V_19 ;
}
static inline unsigned long F_18 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
if ( F_19 ( V_26 ) && V_2 -> V_18 . V_23 ) {
const struct V_27 * V_28 ;
V_28 = F_20 ( V_29 , V_2 -> V_18 . V_23 ) ;
return ( unsigned long ) V_28 -> V_30 ;
}
return V_25 -> V_31 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_5 * V_6 ;
struct V_16 * V_32 = F_22 ( & V_2 -> V_18 ) ;
int V_7 = 0 ;
V_6 = F_14 ( & V_2 -> V_18 , sizeof( struct V_5 ) ,
V_20 ) ;
if ( V_6 == NULL )
return - V_21 ;
F_23 ( V_2 , V_6 ) ;
V_6 -> V_18 = & V_2 -> V_18 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = F_18 ( V_2 , V_25 ) ;
V_6 -> V_33 = V_2 -> V_33 ;
if ( F_19 ( V_26 ) && V_6 -> V_18 -> V_23 ) {
V_32 = F_13 ( V_6 -> V_18 ) ;
if ( F_24 ( V_32 ) )
return F_25 ( V_32 ) ;
}
if ( ! V_32 )
return V_7 ;
V_6 -> V_32 = V_32 ;
V_6 -> V_22 = V_32 -> V_22 ;
F_26 ( & V_6 -> V_8 ) ;
V_6 -> V_34 = F_27 ( V_2 -> V_35 , V_36 ) ;
if ( ! V_6 -> V_34 ) {
F_15 ( V_6 -> V_18 , L_2 ) ;
return - V_37 ;
}
F_23 ( V_6 -> V_34 , V_6 ) ;
V_6 -> V_38 = F_27 ( V_2 -> V_35 , V_39 ) ;
if ( ! V_6 -> V_38 ) {
F_15 ( V_6 -> V_18 , L_3 ) ;
V_7 = - V_37 ;
goto V_40;
}
F_23 ( V_6 -> V_38 , V_6 ) ;
V_6 -> V_41 = F_27 ( V_2 -> V_35 , V_42 ) ;
if ( ! V_6 -> V_41 ) {
F_15 ( V_6 -> V_18 , L_4 ) ;
V_7 = - V_37 ;
goto V_43;
}
F_23 ( V_6 -> V_41 , V_6 ) ;
F_28 ( V_6 -> V_18 ) ;
F_29 ( V_6 ) ;
V_7 = F_30 ( V_6 -> V_18 , - 1 , V_44 ,
F_31 ( V_44 ) ,
NULL , 0 , NULL ) ;
if ( V_7 < 0 ) {
F_15 ( V_6 -> V_18 , L_5 , V_7 ) ;
goto V_45;
}
F_32 ( V_6 -> V_18 , V_32 -> V_46 ) ;
return V_7 ;
V_45:
F_33 ( V_6 -> V_18 ) ;
F_34 ( V_6 -> V_41 ) ;
V_43:
F_34 ( V_6 -> V_38 ) ;
V_40:
F_34 ( V_6 -> V_34 ) ;
return V_7 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_33 ( V_6 -> V_18 ) ;
F_34 ( V_6 -> V_41 ) ;
F_34 ( V_6 -> V_38 ) ;
F_34 ( V_6 -> V_34 ) ;
return 0 ;
}
static int F_36 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_31 ( V_48 ) ; V_47 ++ )
F_1 ( V_2 , V_48 [ V_47 ] ,
& V_6 -> V_49 [ V_47 ] ) ;
for ( V_47 = 0 ; V_47 < F_31 ( V_50 ) ; V_47 ++ )
F_1 ( V_2 , V_50 [ V_47 ] ,
& V_6 -> V_49 [ V_47 + V_51 ] ) ;
for ( V_47 = 0 ; V_47 < F_31 ( V_52 ) ; V_47 ++ )
F_1 ( V_2 , V_52 [ V_47 ] ,
& V_6 -> V_49 [ V_47 + V_51 +
V_53 ] ) ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_31 ( V_48 ) ; V_47 ++ )
F_8 ( V_2 , V_48 [ V_47 ] ,
V_6 -> V_49 [ V_47 ] ) ;
for ( V_47 = 0 ; V_47 < F_31 ( V_50 ) ; V_47 ++ )
F_8 ( V_2 , V_50 [ V_47 ] ,
V_6 -> V_49 [ V_47 + V_51 ] ) ;
for ( V_47 = 0 ; V_47 < F_31 ( V_52 ) ; V_47 ++ )
F_8 ( V_2 , V_52 [ V_47 ] ,
V_6 -> V_49 [ V_47 + V_51 +
V_53 ] ) ;
return 0 ;
}
static int F_39 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_40 ( V_18 ) )
F_41 ( V_6 -> V_33 , 1 ) ;
return 0 ;
}
static int F_42 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_40 ( V_18 ) )
F_41 ( V_6 -> V_33 , 0 ) ;
return F_43 ( V_6 ) ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_54 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_54 ) ;
}
