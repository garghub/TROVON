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
F_6 ( V_2 ) ;
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
static unsigned int F_18 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_19 ( V_12 ) ;
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_18 ;
V_18 = F_2 ( V_3 + V_19 ) ;
return F_20 ( V_18 ) ;
}
static int F_21 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_22 ( & V_21 -> V_15 ) ;
struct V_24 * V_25 ;
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_23 ( & V_21 -> V_15 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_14 = false ;
V_2 -> V_15 = & V_21 -> V_15 ;
V_2 -> V_5 = 0x1234 ;
F_24 ( & V_2 -> V_13 ) ;
V_25 = F_25 ( V_21 , V_29 , 0 ) ;
V_2 -> V_3 = F_26 ( & V_21 -> V_15 , V_25 ) ;
if ( F_27 ( V_2 -> V_3 ) )
return F_28 ( V_2 -> V_3 ) ;
V_2 -> V_12 . V_30 = & V_31 ;
V_2 -> V_12 . V_32 = & V_33 ;
V_2 -> V_12 . V_34 = V_35 ;
V_2 -> V_12 . V_36 = V_37 ;
if ( F_29 ( & V_2 -> V_12 , V_38 , & V_21 -> V_15 ) < 0 )
V_2 -> V_12 . V_8 = V_39 ;
F_30 ( & V_2 -> V_12 , V_40 ) ;
F_31 ( V_21 , V_2 ) ;
F_32 ( V_2 -> V_15 ) ;
F_12 ( V_2 -> V_15 ) ;
if ( V_23 && V_23 -> V_41 ) {
T_2 V_42 = V_23 -> V_41 () ;
if ( V_42 & ( 1 << V_43 ) )
V_2 -> V_12 . V_44 = V_45 ;
}
F_6 ( V_2 ) ;
V_26 = F_33 ( & V_2 -> V_12 ) ;
if ( V_26 ) {
F_34 ( V_2 -> V_15 ) ;
return V_26 ;
}
F_35 ( L_1 ,
F_2 ( V_2 -> V_3 + V_46 ) & 0xFF ,
V_2 -> V_12 . V_8 ) ;
F_15 ( V_2 -> V_15 ) ;
if ( V_47 )
F_9 ( & V_2 -> V_12 ) ;
return 0 ;
}
static void F_36 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_37 ( V_21 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_6 ( V_2 ) ;
F_15 ( V_2 -> V_15 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
}
static int F_38 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_37 ( V_21 ) ;
F_34 ( V_2 -> V_15 ) ;
F_39 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_40 ( struct V_20 * V_21 , T_3 V_48 )
{
struct V_1 * V_2 = F_37 ( V_21 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_6 ( V_2 ) ;
F_15 ( V_2 -> V_15 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_41 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_37 ( V_21 ) ;
F_11 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_14 ) {
F_12 ( V_2 -> V_15 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
}
F_13 ( & V_2 -> V_13 ) ;
return 0 ;
}
