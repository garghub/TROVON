static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static int F_4 ( int V_1 , int V_2 )
{
int V_3 ;
F_2 ( V_2 ++ , V_1 ) ;
V_3 = F_3 ( V_1 + 1 ) << 8 ;
F_2 ( V_2 , V_1 ) ;
V_3 |= F_3 ( V_1 + 1 ) ;
return V_3 ;
}
static inline void F_5 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static inline int F_6 ( int V_1 )
{
if ( ! F_7 ( V_1 , 2 , V_4 ) ) {
F_8 ( V_4 L_1 , V_1 ) ;
return - V_5 ;
}
F_2 ( V_6 , V_1 ) ;
F_2 ( V_6 , V_1 ) ;
return 0 ;
}
static inline void F_9 ( int V_1 , int V_7 )
{
F_2 ( V_8 , V_1 ) ;
F_2 ( V_7 , V_1 + 1 ) ;
}
static inline void F_10 ( int V_1 )
{
F_2 ( V_9 , V_1 ) ;
F_11 ( V_1 , 2 ) ;
}
static int F_12 ( struct V_10 * V_11 , unsigned V_12 )
{
int V_13 ;
struct V_14 * V_15 =
F_13 ( V_11 , struct V_14 , V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_19 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_19 = F_1 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) ) ;
V_19 &= ~ ( 1 << V_12 ) ;
F_5 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) , V_19 ) ;
F_10 ( V_17 -> V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 , unsigned V_12 )
{
int V_13 ;
struct V_14 * V_15 =
F_13 ( V_11 , struct V_14 , V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_19 , V_18 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_19 = F_1 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) ) ;
V_19 = ! ! ( V_19 & ( 1 << V_12 ) ) ;
if ( V_19 )
V_18 = F_1 ( V_17 -> V_20 , F_16 ( V_15 -> V_22 ) ) ;
else
V_18 = F_1 ( V_17 -> V_20 , F_17 ( V_15 -> V_22 ) ) ;
F_10 ( V_17 -> V_20 ) ;
return ! ! ( V_18 & 1 << V_12 ) ;
}
static int F_18 ( struct V_10 * V_11 ,
unsigned V_12 , int V_23 )
{
int V_13 ;
struct V_14 * V_15 =
F_13 ( V_11 , struct V_14 , V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_19 , V_24 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_24 = F_1 ( V_17 -> V_20 , F_16 ( V_15 -> V_22 ) ) ;
if ( V_23 )
V_24 |= ( 1 << V_12 ) ;
else
V_24 &= ~ ( 1 << V_12 ) ;
F_5 ( V_17 -> V_20 , F_16 ( V_15 -> V_22 ) , V_24 ) ;
V_19 = F_1 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) ) ;
V_19 |= ( 1 << V_12 ) ;
F_5 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) , V_19 ) ;
F_10 ( V_17 -> V_20 ) ;
return 0 ;
}
static void F_19 ( struct V_10 * V_11 , unsigned V_12 , int V_23 )
{
int V_13 ;
struct V_14 * V_15 =
F_13 ( V_11 , struct V_14 , V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_24 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_24 = F_1 ( V_17 -> V_20 , F_16 ( V_15 -> V_22 ) ) ;
if ( V_23 )
V_24 |= ( 1 << V_12 ) ;
else
V_24 &= ~ ( 1 << V_12 ) ;
F_5 ( V_17 -> V_20 , F_16 ( V_15 -> V_22 ) , V_24 ) ;
F_10 ( V_17 -> V_20 ) ;
}
static int F_20 ( struct V_25 * V_26 )
{
int V_13 ;
int V_27 ;
struct V_16 * V_17 = V_26 -> V_28 . V_29 ;
struct V_30 * V_18 ;
V_18 = F_21 ( & V_26 -> V_28 , sizeof( * V_18 ) , V_31 ) ;
if ( ! V_18 )
return - V_32 ;
switch ( V_17 -> type ) {
case V_33 :
V_18 -> V_34 = F_22 ( V_35 ) ;
V_18 -> V_15 = V_35 ;
break;
case V_36 :
V_18 -> V_34 = F_22 ( V_37 ) ;
V_18 -> V_15 = V_37 ;
break;
case V_38 :
V_18 -> V_34 = F_22 ( V_39 ) ;
V_18 -> V_15 = V_39 ;
break;
case V_40 :
V_18 -> V_34 = F_22 ( V_41 ) ;
V_18 -> V_15 = V_41 ;
break;
default:
return - V_42 ;
}
V_18 -> V_17 = V_17 ;
F_23 ( V_26 , V_18 ) ;
for ( V_27 = 0 ; V_27 < V_18 -> V_34 ; V_27 ++ ) {
struct V_14 * V_15 = & V_18 -> V_15 [ V_27 ] ;
V_15 -> V_11 . V_28 = & V_26 -> V_28 ;
V_15 -> V_18 = V_18 ;
V_13 = F_24 ( & V_15 -> V_11 ) ;
if ( V_13 ) {
F_25 ( & V_26 -> V_28 ,
L_2 ,
V_27 , V_13 ) ;
goto V_43;
}
}
return 0 ;
V_43:
for ( V_27 = V_27 - 1 ; V_27 >= 0 ; V_27 -- ) {
struct V_14 * V_15 = & V_18 -> V_15 [ V_27 ] ;
F_26 ( & V_15 -> V_11 ) ;
}
return V_13 ;
}
static int F_27 ( struct V_25 * V_26 )
{
int V_27 ;
struct V_30 * V_18 = F_28 ( V_26 ) ;
for ( V_27 = 0 ; V_27 < V_18 -> V_34 ; V_27 ++ ) {
struct V_14 * V_15 = & V_18 -> V_15 [ V_27 ] ;
F_26 ( & V_15 -> V_11 ) ;
}
return 0 ;
}
static int T_2 F_29 ( int V_20 , struct V_16 * V_17 )
{
int V_13 ;
T_3 V_44 ;
V_13 = F_6 ( V_20 ) ;
if ( V_13 )
return V_13 ;
V_13 = - V_42 ;
V_44 = F_4 ( V_20 , V_45 ) ;
if ( V_44 != V_46 ) {
F_30 ( V_4 L_3 , V_20 ) ;
goto V_13;
}
V_44 = F_4 ( V_20 , V_47 ) ;
switch ( V_44 ) {
case V_48 :
V_17 -> type = V_33 ;
break;
case V_49 :
V_17 -> type = V_36 ;
break;
case V_50 :
V_17 -> type = V_38 ;
break;
case V_51 :
V_17 -> type = V_40 ;
break;
default:
F_31 ( V_4 L_4 , V_44 ) ;
goto V_13;
}
V_17 -> V_20 = V_20 ;
V_13 = 0 ;
F_31 ( V_4 L_5 ,
V_52 [ V_17 -> type ] ,
( unsigned int ) V_20 ,
( int ) F_1 ( V_20 , V_53 ) ) ;
V_13:
F_10 ( V_20 ) ;
return V_13 ;
}
static int T_2
F_32 ( const struct V_16 * V_17 )
{
int V_13 ;
V_54 = F_33 ( V_4 , - 1 ) ;
if ( ! V_54 )
return - V_32 ;
V_13 = F_34 ( V_54 ,
V_17 , sizeof( * V_17 ) ) ;
if ( V_13 ) {
F_8 ( V_4 L_6 ) ;
goto V_13;
}
V_13 = F_35 ( V_54 ) ;
if ( V_13 ) {
F_8 ( V_4 L_7 ) ;
goto V_13;
}
return 0 ;
V_13:
F_36 ( V_54 ) ;
return V_13 ;
}
static int T_2 F_37 ( void )
{
int V_13 ;
struct V_16 V_17 ;
if ( F_29 ( 0x2e , & V_17 ) &&
F_29 ( 0x4e , & V_17 ) )
return - V_42 ;
V_13 = F_38 ( & V_55 ) ;
if ( ! V_13 ) {
V_13 = F_32 ( & V_17 ) ;
if ( V_13 )
F_39 ( & V_55 ) ;
}
return V_13 ;
}
static void T_4 F_40 ( void )
{
F_41 ( V_54 ) ;
F_39 ( & V_55 ) ;
}
