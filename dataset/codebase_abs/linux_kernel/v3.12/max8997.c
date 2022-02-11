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
struct V_16 * V_31 = F_22 ( & V_2 -> V_18 ) ;
int V_7 = 0 ;
V_6 = F_14 ( & V_2 -> V_18 , sizeof( struct V_5 ) ,
V_20 ) ;
if ( V_6 == NULL )
return - V_21 ;
F_23 ( V_2 , V_6 ) ;
V_6 -> V_18 = & V_2 -> V_18 ;
V_6 -> V_2 = V_2 ;
V_6 -> type = F_18 ( V_2 , V_25 ) ;
V_6 -> V_32 = V_2 -> V_32 ;
if ( V_6 -> V_18 -> V_23 ) {
V_31 = F_13 ( V_6 -> V_18 ) ;
if ( F_24 ( V_31 ) )
return F_25 ( V_31 ) ;
}
if ( ! V_31 )
return V_7 ;
V_6 -> V_31 = V_31 ;
V_6 -> V_22 = V_31 -> V_22 ;
F_26 ( & V_6 -> V_8 ) ;
V_6 -> V_33 = F_27 ( V_2 -> V_34 , V_35 ) ;
F_23 ( V_6 -> V_33 , V_6 ) ;
V_6 -> V_36 = F_27 ( V_2 -> V_34 , V_37 ) ;
F_23 ( V_6 -> V_36 , V_6 ) ;
V_6 -> V_38 = F_27 ( V_2 -> V_34 , V_39 ) ;
F_23 ( V_6 -> V_38 , V_6 ) ;
F_28 ( V_6 -> V_18 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 -> V_18 , - 1 , V_40 ,
F_31 ( V_40 ) ,
NULL , 0 , NULL ) ;
if ( V_7 < 0 )
goto V_41;
F_32 ( V_6 -> V_18 , V_31 -> V_42 ) ;
return V_7 ;
V_41:
F_33 ( V_6 -> V_18 ) ;
F_34 ( V_6 -> V_38 ) ;
F_34 ( V_6 -> V_36 ) ;
F_34 ( V_6 -> V_33 ) ;
return V_7 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_33 ( V_6 -> V_18 ) ;
F_34 ( V_6 -> V_38 ) ;
F_34 ( V_6 -> V_36 ) ;
F_34 ( V_6 -> V_33 ) ;
return 0 ;
}
static int F_36 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < F_31 ( V_44 ) ; V_43 ++ )
F_1 ( V_2 , V_44 [ V_43 ] ,
& V_6 -> V_45 [ V_43 ] ) ;
for ( V_43 = 0 ; V_43 < F_31 ( V_46 ) ; V_43 ++ )
F_1 ( V_2 , V_46 [ V_43 ] ,
& V_6 -> V_45 [ V_43 + V_47 ] ) ;
for ( V_43 = 0 ; V_43 < F_31 ( V_48 ) ; V_43 ++ )
F_1 ( V_2 , V_48 [ V_43 ] ,
& V_6 -> V_45 [ V_43 + V_47 +
V_49 ] ) ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < F_31 ( V_44 ) ; V_43 ++ )
F_8 ( V_2 , V_44 [ V_43 ] ,
V_6 -> V_45 [ V_43 ] ) ;
for ( V_43 = 0 ; V_43 < F_31 ( V_46 ) ; V_43 ++ )
F_8 ( V_2 , V_46 [ V_43 ] ,
V_6 -> V_45 [ V_43 + V_47 ] ) ;
for ( V_43 = 0 ; V_43 < F_31 ( V_48 ) ; V_43 ++ )
F_8 ( V_2 , V_48 [ V_43 ] ,
V_6 -> V_45 [ V_43 + V_47 +
V_49 ] ) ;
return 0 ;
}
static int F_39 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_40 ( V_18 ) )
F_41 ( V_6 -> V_32 , 1 ) ;
return 0 ;
}
static int F_42 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_37 ( V_18 , struct V_1 , V_18 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_40 ( V_18 ) )
F_41 ( V_6 -> V_32 , 0 ) ;
return F_43 ( V_6 ) ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_50 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_50 ) ;
}
