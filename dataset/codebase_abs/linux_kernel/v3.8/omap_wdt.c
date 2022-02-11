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
struct V_20 * V_21 = V_19 -> V_15 . V_22 ;
bool V_23 = V_24 ;
struct V_11 * V_25 ;
struct V_26 * V_27 , * V_28 ;
struct V_1 * V_2 ;
T_2 V_29 ;
int V_30 ;
V_25 = F_19 ( & V_19 -> V_15 , sizeof( * V_25 ) , V_31 ) ;
if ( ! V_25 )
return - V_32 ;
V_27 = F_20 ( V_19 , V_33 , 0 ) ;
if ( ! V_27 )
return - V_34 ;
V_28 = F_21 ( & V_19 -> V_15 , V_27 -> V_35 ,
F_22 ( V_27 ) , V_19 -> V_36 ) ;
if ( ! V_28 )
return - V_37 ;
V_2 = F_19 ( & V_19 -> V_15 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_14 = false ;
V_2 -> V_28 = V_28 ;
V_2 -> V_15 = & V_19 -> V_15 ;
V_2 -> V_5 = 0x1234 ;
F_23 ( & V_2 -> V_13 ) ;
V_2 -> V_3 = F_24 ( & V_19 -> V_15 , V_27 -> V_35 , F_22 ( V_27 ) ) ;
if ( ! V_2 -> V_3 )
return - V_32 ;
V_25 -> V_38 = & V_39 ;
V_25 -> V_40 = & V_41 ;
V_25 -> V_42 = V_43 ;
V_25 -> V_44 = V_45 ;
if ( V_46 >= V_43 &&
V_46 <= V_45 )
V_25 -> V_8 = V_46 ;
else
V_25 -> V_8 = V_47 ;
F_25 ( V_25 , V_2 ) ;
F_26 ( V_25 , V_23 ) ;
F_27 ( V_19 , V_25 ) ;
F_28 ( V_2 -> V_15 ) ;
F_12 ( V_2 -> V_15 ) ;
if ( V_21 && V_21 -> V_48 )
V_29 = V_21 -> V_48 () ;
else
V_29 = 0 ;
V_25 -> V_49 = ( V_29 & ( 1 << V_50 ) ) ?
V_51 : 0 ;
F_6 ( V_2 ) ;
V_30 = F_29 ( V_25 ) ;
if ( V_30 ) {
F_30 ( V_2 -> V_15 ) ;
return V_30 ;
}
F_31 ( L_1 ,
F_2 ( V_2 -> V_3 + V_52 ) & 0xFF ,
V_25 -> V_8 ) ;
F_15 ( V_2 -> V_15 ) ;
return 0 ;
}
static void F_32 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_33 ( V_19 ) ;
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_6 ( V_2 ) ;
F_15 ( V_2 -> V_15 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
}
static int F_34 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_33 ( V_19 ) ;
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_30 ( V_2 -> V_15 ) ;
F_35 ( V_12 ) ;
return 0 ;
}
static int F_36 ( struct V_18 * V_19 , T_3 V_53 )
{
struct V_11 * V_12 = F_33 ( V_19 ) ;
struct V_1 * V_2 = F_10 ( V_12 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_6 ( V_2 ) ;
F_15 ( V_2 -> V_15 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_37 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_33 ( V_19 ) ;
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
