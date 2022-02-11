static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x08 )
F_3 () ;
V_2 -> V_5 = ~ V_2 -> V_5 ;
F_4 ( V_2 -> V_5 , ( V_3 + V_6 ) ) ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x08 )
F_3 () ;
}
static void F_5 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_4 ( 0xBBBB , V_3 + V_7 ) ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x10 )
F_3 () ;
F_4 ( 0x4444 , V_3 + V_7 ) ;
while ( ( F_2 ( V_3 + V_4 ) ) & 0x10 )
F_3 () ;
}
static void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_4 ( 0xAAAA , V_3 + V_7 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x10 )
F_3 () ;
F_4 ( 0x5555 , V_3 + V_7 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x10 )
F_3 () ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
T_2 V_9 = F_8 ( V_8 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
while ( F_2 ( V_3 + V_4 ) & 0x04 )
F_3 () ;
F_4 ( V_9 , V_3 + V_10 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x04 )
F_3 () ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_10 ( V_12 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
F_11 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = true ;
F_12 ( V_2 -> V_15 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x01 )
F_3 () ;
F_4 ( ( 1 << 5 ) | ( V_16 << 2 ) , V_3 + V_17 ) ;
while ( F_2 ( V_3 + V_4 ) & 0x01 )
F_3 () ;
F_7 ( V_2 , V_12 -> V_8 ) ;
F_1 ( V_2 ) ;
F_5 ( V_2 ) ;
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_6 ( V_2 ) ;
F_15 ( V_2 -> V_15 ) ;
V_2 -> V_14 = false ;
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 ,
unsigned int V_8 )
{
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 , V_8 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
V_12 -> V_8 = V_8 ;
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_19 ( & V_19 -> V_15 ) ;
struct V_11 * V_22 ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
T_2 V_25 ;
int V_26 ;
V_22 = F_20 ( & V_19 -> V_15 , sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 )
return - V_28 ;
V_2 = F_20 ( & V_19 -> V_15 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_14 = false ;
V_2 -> V_15 = & V_19 -> V_15 ;
V_2 -> V_5 = 0x1234 ;
F_21 ( & V_2 -> V_13 ) ;
V_24 = F_22 ( V_19 , V_29 , 0 ) ;
V_2 -> V_3 = F_23 ( & V_19 -> V_15 , V_24 ) ;
if ( F_24 ( V_2 -> V_3 ) )
return F_25 ( V_2 -> V_3 ) ;
V_22 -> V_30 = & V_31 ;
V_22 -> V_32 = & V_33 ;
V_22 -> V_34 = V_35 ;
V_22 -> V_36 = V_37 ;
if ( V_38 >= V_35 &&
V_38 <= V_37 )
V_22 -> V_8 = V_38 ;
else
V_22 -> V_8 = V_39 ;
F_26 ( V_22 , V_2 ) ;
F_27 ( V_22 , V_40 ) ;
F_28 ( V_19 , V_22 ) ;
F_29 ( V_2 -> V_15 ) ;
F_12 ( V_2 -> V_15 ) ;
if ( V_21 && V_21 -> V_41 )
V_25 = V_21 -> V_41 () ;
else
V_25 = 0 ;
V_22 -> V_42 = ( V_25 & ( 1 << V_43 ) ) ?
V_44 : 0 ;
F_6 ( V_2 ) ;
V_26 = F_30 ( V_22 ) ;
if ( V_26 ) {
F_31 ( V_2 -> V_15 ) ;
return V_26 ;
}
F_32 ( L_1 ,
F_2 ( V_2 -> V_3 + V_45 ) & 0xFF ,
V_22 -> V_8 ) ;
F_15 ( V_2 -> V_15 ) ;
return 0 ;
}
static void F_33 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_34 ( V_19 ) ;
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_6 ( V_2 ) ;
F_15 ( V_2 -> V_15 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_34 ( V_19 ) ;
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_31 ( V_2 -> V_15 ) ;
F_36 ( V_12 ) ;
return 0 ;
}
static int F_37 ( struct V_18 * V_19 , T_3 V_46 )
{
struct V_11 * V_12 = F_34 ( V_19 ) ;
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_6 ( V_2 ) ;
F_15 ( V_2 -> V_15 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_38 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_34 ( V_19 ) ;
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_12 ( V_2 -> V_15 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
