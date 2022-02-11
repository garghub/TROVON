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
struct V_14 * V_15 = F_13 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_19 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_19 = F_1 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) ) ;
F_10 ( V_17 -> V_20 ) ;
return ! ( V_19 & 1 << V_12 ) ;
}
static int F_15 ( struct V_10 * V_11 , unsigned V_12 )
{
int V_13 ;
struct V_14 * V_15 = F_13 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_19 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_19 = F_1 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) ) ;
V_19 &= ~ F_16 ( V_12 ) ;
F_5 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) , V_19 ) ;
F_10 ( V_17 -> V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 , unsigned V_12 )
{
int V_13 ;
struct V_14 * V_15 = F_13 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_19 , V_18 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_19 = F_1 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) ) ;
V_19 = ! ! ( V_19 & F_16 ( V_12 ) ) ;
if ( V_19 )
V_18 = F_1 ( V_17 -> V_20 , F_18 ( V_15 -> V_22 ) ) ;
else
V_18 = F_1 ( V_17 -> V_20 , F_19 ( V_15 -> V_22 ) ) ;
F_10 ( V_17 -> V_20 ) ;
return ! ! ( V_18 & F_16 ( V_12 ) ) ;
}
static int F_20 ( struct V_10 * V_11 ,
unsigned V_12 , int V_23 )
{
int V_13 ;
struct V_14 * V_15 = F_13 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_19 , V_24 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_24 = F_1 ( V_17 -> V_20 , F_18 ( V_15 -> V_22 ) ) ;
if ( V_23 )
V_24 |= F_16 ( V_12 ) ;
else
V_24 &= ~ F_16 ( V_12 ) ;
F_5 ( V_17 -> V_20 , F_18 ( V_15 -> V_22 ) , V_24 ) ;
V_19 = F_1 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) ) ;
V_19 |= F_16 ( V_12 ) ;
F_5 ( V_17 -> V_20 , F_14 ( V_15 -> V_22 ) , V_19 ) ;
F_10 ( V_17 -> V_20 ) ;
return 0 ;
}
static void F_21 ( struct V_10 * V_11 , unsigned V_12 , int V_23 )
{
int V_13 ;
struct V_14 * V_15 = F_13 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_24 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_24 = F_1 ( V_17 -> V_20 , F_18 ( V_15 -> V_22 ) ) ;
if ( V_23 )
V_24 |= F_16 ( V_12 ) ;
else
V_24 &= ~ F_16 ( V_12 ) ;
F_5 ( V_17 -> V_20 , F_18 ( V_15 -> V_22 ) , V_24 ) ;
F_10 ( V_17 -> V_20 ) ;
}
static int F_22 ( struct V_10 * V_11 , unsigned V_12 ,
unsigned long V_25 )
{
int V_13 ;
enum V_26 V_27 = F_23 ( V_25 ) ;
struct V_14 * V_15 = F_13 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_18 -> V_17 ;
T_1 V_18 ;
if ( V_27 != V_28 &&
V_27 != V_29 )
return - V_30 ;
V_13 = F_6 ( V_17 -> V_20 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_17 -> V_20 , V_21 ) ;
V_18 = F_1 ( V_17 -> V_20 , F_24 ( V_15 -> V_22 ) ) ;
if ( V_27 == V_28 )
V_18 &= ~ F_16 ( V_12 ) ;
else
V_18 |= F_16 ( V_12 ) ;
F_5 ( V_17 -> V_20 , F_24 ( V_15 -> V_22 ) , V_18 ) ;
F_10 ( V_17 -> V_20 ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 )
{
int V_13 ;
int V_33 ;
struct V_16 * V_17 = F_26 ( & V_32 -> V_34 ) ;
struct V_35 * V_18 ;
V_18 = F_27 ( & V_32 -> V_34 , sizeof( * V_18 ) , V_36 ) ;
if ( ! V_18 )
return - V_37 ;
switch ( V_17 -> type ) {
case V_38 :
V_18 -> V_39 = F_28 ( V_40 ) ;
V_18 -> V_15 = V_40 ;
break;
case V_41 :
V_18 -> V_39 = F_28 ( V_42 ) ;
V_18 -> V_15 = V_42 ;
break;
case V_43 :
V_18 -> V_39 = F_28 ( V_44 ) ;
V_18 -> V_15 = V_44 ;
break;
case V_45 :
V_18 -> V_39 = F_28 ( V_46 ) ;
V_18 -> V_15 = V_46 ;
break;
case V_47 :
V_18 -> V_39 = F_28 ( V_48 ) ;
V_18 -> V_15 = V_48 ;
break;
default:
return - V_49 ;
}
V_18 -> V_17 = V_17 ;
F_29 ( V_32 , V_18 ) ;
for ( V_33 = 0 ; V_33 < V_18 -> V_39 ; V_33 ++ ) {
struct V_14 * V_15 = & V_18 -> V_15 [ V_33 ] ;
V_15 -> V_11 . V_50 = & V_32 -> V_34 ;
V_15 -> V_18 = V_18 ;
V_13 = F_30 ( & V_32 -> V_34 , & V_15 -> V_11 , V_15 ) ;
if ( V_13 ) {
F_31 ( & V_32 -> V_34 ,
L_2 ,
V_33 , V_13 ) ;
return V_13 ;
}
}
return 0 ;
}
static int T_2 F_32 ( int V_20 , struct V_16 * V_17 )
{
int V_13 ;
T_3 V_51 ;
V_13 = F_6 ( V_20 ) ;
if ( V_13 )
return V_13 ;
V_13 = - V_49 ;
V_51 = F_4 ( V_20 , V_52 ) ;
if ( V_51 != V_53 ) {
F_33 ( V_4 L_3 , V_20 ) ;
goto V_13;
}
V_51 = F_4 ( V_20 , V_54 ) ;
switch ( V_51 ) {
case V_55 :
V_17 -> type = V_38 ;
break;
case V_56 :
V_17 -> type = V_41 ;
break;
case V_57 :
V_17 -> type = V_43 ;
break;
case V_58 :
V_17 -> type = V_45 ;
break;
case V_59 :
V_17 -> type = V_47 ;
break;
default:
F_34 ( V_4 L_4 , V_51 ) ;
goto V_13;
}
V_17 -> V_20 = V_20 ;
V_13 = 0 ;
F_34 ( V_4 L_5 ,
V_60 [ V_17 -> type ] ,
( unsigned int ) V_20 ,
( int ) F_1 ( V_20 , V_61 ) ) ;
V_13:
F_10 ( V_20 ) ;
return V_13 ;
}
static int T_2
F_35 ( const struct V_16 * V_17 )
{
int V_13 ;
V_62 = F_36 ( V_4 , - 1 ) ;
if ( ! V_62 )
return - V_37 ;
V_13 = F_37 ( V_62 ,
V_17 , sizeof( * V_17 ) ) ;
if ( V_13 ) {
F_8 ( V_4 L_6 ) ;
goto V_13;
}
V_13 = F_38 ( V_62 ) ;
if ( V_13 ) {
F_8 ( V_4 L_7 ) ;
goto V_13;
}
return 0 ;
V_13:
F_39 ( V_62 ) ;
return V_13 ;
}
static int T_2 F_40 ( void )
{
int V_13 ;
struct V_16 V_17 ;
if ( F_32 ( 0x2e , & V_17 ) &&
F_32 ( 0x4e , & V_17 ) )
return - V_49 ;
V_13 = F_41 ( & V_63 ) ;
if ( ! V_13 ) {
V_13 = F_35 ( & V_17 ) ;
if ( V_13 )
F_42 ( & V_63 ) ;
}
return V_13 ;
}
static void T_4 F_43 ( void )
{
F_44 ( V_62 ) ;
F_42 ( & V_63 ) ;
}
