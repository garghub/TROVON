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
static struct V_16 * F_13 (
struct V_17 * V_18 )
{
return 0 ;
}
static inline int F_18 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
#ifdef F_19
if ( V_2 -> V_18 . V_23 ) {
const struct V_26 * V_27 ;
V_27 = F_20 ( V_28 , V_2 -> V_18 . V_23 ) ;
return ( int ) V_27 -> V_29 ;
}
#endif
return ( int ) V_25 -> V_30 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_5 * V_6 ;
struct V_16 * V_31 = V_2 -> V_18 . V_32 ;
int V_7 = 0 ;
V_6 = F_22 ( sizeof( struct V_5 ) , V_20 ) ;
if ( V_6 == NULL )
return - V_21 ;
F_23 ( V_2 , V_6 ) ;
V_6 -> V_18 = & V_2 -> V_18 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = F_18 ( V_2 , V_25 ) ;
V_6 -> V_33 = V_2 -> V_33 ;
if ( V_6 -> V_18 -> V_23 ) {
V_31 = F_13 ( V_6 -> V_18 ) ;
if ( F_24 ( V_31 ) ) {
V_7 = F_25 ( V_31 ) ;
goto V_34;
}
}
if ( ! V_31 )
goto V_34;
V_6 -> V_31 = V_31 ;
V_6 -> V_22 = V_31 -> V_22 ;
F_26 ( & V_6 -> V_8 ) ;
V_6 -> V_35 = F_27 ( V_2 -> V_36 , V_37 ) ;
F_23 ( V_6 -> V_35 , V_6 ) ;
V_6 -> V_38 = F_27 ( V_2 -> V_36 , V_39 ) ;
F_23 ( V_6 -> V_38 , V_6 ) ;
V_6 -> V_40 = F_27 ( V_2 -> V_36 , V_41 ) ;
F_23 ( V_6 -> V_40 , V_6 ) ;
F_28 ( V_6 -> V_18 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 -> V_18 , - 1 , V_42 ,
F_31 ( V_42 ) ,
NULL , 0 , NULL ) ;
if ( V_7 < 0 )
goto V_43;
F_32 ( V_6 -> V_18 , V_31 -> V_44 ) ;
return V_7 ;
V_43:
F_33 ( V_6 -> V_18 ) ;
F_34 ( V_6 -> V_40 ) ;
F_34 ( V_6 -> V_38 ) ;
F_34 ( V_6 -> V_35 ) ;
V_34:
F_35 ( V_6 ) ;
return V_7 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_33 ( V_6 -> V_18 ) ;
F_34 ( V_6 -> V_40 ) ;
F_34 ( V_6 -> V_38 ) ;
F_34 ( V_6 -> V_35 ) ;
F_35 ( V_6 ) ;
return 0 ;
}
static int F_37 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_38 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_31 ( V_46 ) ; V_45 ++ )
F_1 ( V_2 , V_46 [ V_45 ] ,
& V_6 -> V_47 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_31 ( V_48 ) ; V_45 ++ )
F_1 ( V_2 , V_48 [ V_45 ] ,
& V_6 -> V_47 [ V_45 + V_49 ] ) ;
for ( V_45 = 0 ; V_45 < F_31 ( V_50 ) ; V_45 ++ )
F_1 ( V_2 , V_50 [ V_45 ] ,
& V_6 -> V_47 [ V_45 + V_49 +
V_51 ] ) ;
return 0 ;
}
static int F_39 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_38 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < F_31 ( V_46 ) ; V_45 ++ )
F_8 ( V_2 , V_46 [ V_45 ] ,
V_6 -> V_47 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_31 ( V_48 ) ; V_45 ++ )
F_8 ( V_2 , V_48 [ V_45 ] ,
V_6 -> V_47 [ V_45 + V_49 ] ) ;
for ( V_45 = 0 ; V_45 < F_31 ( V_50 ) ; V_45 ++ )
F_8 ( V_2 , V_50 [ V_45 ] ,
V_6 -> V_47 [ V_45 + V_49 +
V_51 ] ) ;
return 0 ;
}
static int F_40 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_38 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_41 ( V_18 ) )
F_42 ( V_6 -> V_33 , 1 ) ;
return 0 ;
}
static int F_43 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_38 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_41 ( V_18 ) )
F_42 ( V_6 -> V_33 , 0 ) ;
return F_44 ( V_6 ) ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_52 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_52 ) ;
}
