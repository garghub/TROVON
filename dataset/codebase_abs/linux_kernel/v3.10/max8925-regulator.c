static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 = V_2 -> V_7 -> V_8 - 1 ;
return F_3 ( V_5 -> V_9 , V_5 -> V_10 , V_6 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_11 , V_6 ;
int V_12 ;
V_12 = F_5 ( V_5 -> V_9 , V_5 -> V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 = V_2 -> V_7 -> V_8 - 1 ;
V_11 = V_12 & V_6 ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_13 ,
V_14 << V_15 |
V_16 << V_17 ,
V_18 << V_15 |
V_19 << V_17 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_13 ,
V_14 << V_15 |
V_16 << V_17 ,
V_18 << V_15 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 , V_12 ;
V_12 = F_5 ( V_5 -> V_9 , V_5 -> V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = ( V_12 >> V_15 ) & V_14 ;
if ( V_20 != V_18 )
return 1 ;
else
return V_12 & ( V_16 << V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_21 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_11 , V_6 ;
if ( V_21 < V_22 || V_21 > V_23 )
return - V_24 ;
V_11 = F_10 ( V_21 - V_22 , V_25 ) ;
V_11 <<= V_26 ;
V_6 = 3 << V_26 ;
return F_3 ( V_5 -> V_9 , V_5 -> V_13 , V_6 , V_11 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_10 , 1 << V_27 ,
1 << V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_10 , 1 << V_27 , 0 ) ;
}
static int F_13 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
int V_32 )
{
struct V_33 * V_34 , * V_35 ;
int V_36 ;
V_34 = F_14 ( V_29 -> V_37 . V_38 -> V_39 ) ;
if ( ! V_34 )
return - V_40 ;
V_35 = F_15 ( V_34 , L_1 ) ;
if ( ! V_35 ) {
F_16 ( & V_29 -> V_37 , L_2 ) ;
return - V_40 ;
}
V_36 = F_17 ( & V_29 -> V_37 , V_35 ,
& V_41 [ V_32 ] , 1 ) ;
F_18 ( V_35 ) ;
if ( V_36 < 0 )
return - V_40 ;
V_31 -> V_42 = V_41 [ V_32 ] . V_42 ;
V_31 -> V_39 = V_41 [ V_32 ] . V_39 ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 )
{
struct V_43 * V_44 = F_20 ( V_29 -> V_37 . V_38 ) ;
struct V_45 * V_46 = V_29 -> V_37 . V_47 ;
struct V_30 V_31 = { } ;
struct V_4 * V_48 ;
struct V_49 * V_50 ;
struct V_1 * V_2 ;
int V_51 , V_52 ;
V_50 = F_21 ( V_29 , V_53 , 0 ) ;
if ( ! V_50 ) {
F_16 ( & V_29 -> V_37 , L_3 ) ;
return - V_24 ;
}
for ( V_51 = 0 ; V_51 < F_22 ( V_4 ) ; V_51 ++ ) {
V_48 = & V_4 [ V_51 ] ;
if ( V_48 -> V_10 == V_50 -> V_54 ) {
V_52 = V_51 ;
break;
}
}
if ( V_51 == F_22 ( V_4 ) ) {
F_16 ( & V_29 -> V_37 , L_4 ,
( unsigned long long ) V_50 -> V_54 ) ;
return - V_24 ;
}
V_48 -> V_9 = V_44 -> V_9 ;
V_48 -> V_44 = V_44 ;
V_31 . V_37 = & V_29 -> V_37 ;
V_31 . V_55 = V_48 ;
if ( F_13 ( V_29 , & V_31 , V_52 ) )
if ( V_46 )
V_31 . V_42 = V_46 ;
V_2 = F_23 ( & V_48 -> V_7 , & V_31 ) ;
if ( F_24 ( V_2 ) ) {
F_16 ( & V_29 -> V_37 , L_5 ,
V_48 -> V_7 . V_56 ) ;
return F_25 ( V_2 ) ;
}
F_26 ( V_29 , V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_28 ( V_29 ) ;
F_26 ( V_29 , NULL ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
return F_31 ( & V_57 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_57 ) ;
}
