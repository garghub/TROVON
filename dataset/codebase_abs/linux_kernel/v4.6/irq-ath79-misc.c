static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
void T_1 * V_7 = V_4 -> V_8 ;
T_2 V_9 ;
F_4 ( V_6 , V_2 ) ;
V_9 = F_5 ( V_7 + V_10 ) &
F_5 ( V_7 + V_11 ) ;
if ( ! V_9 ) {
F_6 () ;
F_7 ( V_6 , V_2 ) ;
return;
}
while ( V_9 ) {
int V_12 = F_8 ( V_9 ) ;
F_9 ( F_10 ( V_4 , V_12 ) ) ;
V_9 &= ~ F_11 ( V_12 ) ;
}
F_7 ( V_6 , V_2 ) ;
}
static void F_12 ( struct V_13 * V_14 )
{
void T_1 * V_7 = F_13 ( V_14 ) ;
unsigned int V_15 = V_14 -> V_16 ;
T_2 V_17 ;
V_17 = F_5 ( V_7 + V_11 ) ;
F_14 ( V_17 | F_11 ( V_15 ) , V_7 + V_11 ) ;
F_5 ( V_7 + V_11 ) ;
}
static void F_15 ( struct V_13 * V_14 )
{
void T_1 * V_7 = F_13 ( V_14 ) ;
unsigned int V_15 = V_14 -> V_16 ;
T_2 V_17 ;
V_17 = F_5 ( V_7 + V_11 ) ;
F_14 ( V_17 & ~ F_11 ( V_15 ) , V_7 + V_11 ) ;
F_5 ( V_7 + V_11 ) ;
}
static void F_16 ( struct V_13 * V_14 )
{
void T_1 * V_7 = F_13 ( V_14 ) ;
unsigned int V_15 = V_14 -> V_16 ;
T_2 V_17 ;
V_17 = F_5 ( V_7 + V_10 ) ;
F_14 ( V_17 & ~ F_11 ( V_15 ) , V_7 + V_10 ) ;
F_5 ( V_7 + V_10 ) ;
}
static int F_17 ( struct V_3 * V_14 , unsigned int V_15 , T_3 V_18 )
{
F_18 ( V_15 , & V_19 , V_20 ) ;
F_19 ( V_15 , V_14 -> V_8 ) ;
return 0 ;
}
static void T_4 F_20 (
struct V_3 * V_4 , int V_15 )
{
void T_1 * V_7 = V_4 -> V_8 ;
F_14 ( 0 , V_7 + V_11 ) ;
F_14 ( 0 , V_7 + V_10 ) ;
F_21 ( V_15 , F_1 , V_4 ) ;
}
static int T_4 F_22 (
struct V_21 * V_22 , struct V_21 * V_23 )
{
struct V_3 * V_4 ;
void T_1 * V_7 ;
int V_15 ;
V_15 = F_23 ( V_22 , 0 ) ;
if ( ! V_15 ) {
F_24 ( L_1 ) ;
return - V_24 ;
}
V_7 = F_25 ( V_22 , 0 ) ;
if ( ! V_7 ) {
F_24 ( L_2 ) ;
return - V_25 ;
}
V_4 = F_26 ( V_22 , V_26 ,
& V_27 , V_7 ) ;
if ( ! V_4 ) {
F_24 ( L_3 ) ;
return - V_24 ;
}
F_20 ( V_4 , V_15 ) ;
return 0 ;
}
static int T_4 F_27 (
struct V_21 * V_22 , struct V_21 * V_23 )
{
V_19 . V_28 = F_15 ;
return F_22 ( V_22 , V_23 ) ;
}
static int T_4 F_28 (
struct V_21 * V_22 , struct V_21 * V_23 )
{
V_19 . V_29 = F_16 ;
return F_22 ( V_22 , V_23 ) ;
}
void T_4 F_29 ( void T_1 * V_30 , int V_15 ,
int V_31 , bool V_32 )
{
struct V_3 * V_4 ;
if ( V_32 )
V_19 . V_28 = F_15 ;
else
V_19 . V_29 = F_16 ;
V_4 = F_30 ( NULL , V_26 ,
V_31 , 0 , & V_27 , V_30 ) ;
if ( ! V_4 )
F_31 ( L_4 ) ;
F_20 ( V_4 , V_15 ) ;
}
