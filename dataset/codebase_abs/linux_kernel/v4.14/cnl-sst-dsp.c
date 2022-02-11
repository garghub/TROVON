static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_2 ,
V_4 , F_3 ( V_3 ) ,
F_3 ( V_3 ) ) ;
return F_4 ( V_2 ,
V_4 ,
F_3 ( V_3 ) ,
F_3 ( V_3 ) ,
V_5 ,
L_1 ) ;
}
static int
F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_2 , V_4 ,
F_3 ( V_3 ) , 0 ) ;
return F_4 ( V_2 ,
V_4 ,
F_3 ( V_3 ) ,
0 ,
V_5 ,
L_2 ) ;
}
static bool F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_6 ;
bool V_7 ;
V_6 = F_7 ( V_2 , V_4 ) ;
V_7 = ( V_6 & F_8 ( V_3 ) ) &&
( V_6 & F_9 ( V_3 ) ) &&
! ( V_6 & F_3 ( V_3 ) ) &&
! ( V_6 & F_10 ( V_3 ) ) ;
F_11 ( V_2 -> V_8 , L_3 ,
V_7 , V_3 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_2 , V_4 ,
F_10 ( V_3 ) ,
F_10 ( V_3 ) ) ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_9 ;
V_9 = F_5 ( V_2 , V_3 ) ;
if ( V_9 < 0 )
return V_9 ;
F_2 ( V_2 , V_4 ,
F_10 ( V_3 ) , 0 ) ;
if ( ! F_6 ( V_2 , V_3 ) ) {
F_12 ( V_2 , V_3 ) ;
F_14 ( V_2 -> V_8 , L_4 ,
V_3 ) ;
V_9 = - V_10 ;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_2 , V_4 ,
F_9 ( V_3 ) ,
F_9 ( V_3 ) ) ;
return F_4 ( V_2 , V_4 ,
F_8 ( V_3 ) ,
F_8 ( V_3 ) ,
V_11 ,
L_5 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_2 , V_4 ,
F_9 ( V_3 ) , 0 ) ;
return F_4 ( V_2 ,
V_4 ,
F_8 ( V_3 ) ,
0 ,
V_12 ,
L_6 ) ;
}
int F_17 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_9 ;
V_9 = F_15 ( V_2 , V_3 ) ;
if ( V_9 < 0 ) {
F_11 ( V_2 -> V_8 , L_7 ,
V_3 ) ;
return V_9 ;
}
return F_13 ( V_2 , V_3 ) ;
}
int F_18 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_9 ;
V_9 = F_12 ( V_2 , V_3 ) ;
if ( V_9 < 0 ) {
F_14 ( V_2 -> V_8 , L_8 ,
V_3 ) ;
return V_9 ;
}
V_9 = F_16 ( V_2 , V_3 ) ;
if ( V_9 < 0 ) {
F_14 ( V_2 -> V_8 , L_9 ,
V_3 ) ;
return V_9 ;
}
if ( F_6 ( V_2 , V_3 ) ) {
F_14 ( V_2 -> V_8 , L_10 ,
V_3 ) ;
V_9 = - V_10 ;
}
return V_9 ;
}
T_1 F_19 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
T_2 V_6 ;
T_1 V_9 = V_15 ;
F_20 ( & V_2 -> V_16 ) ;
V_6 = F_7 ( V_2 , V_17 ) ;
V_2 -> V_18 = V_6 ;
if ( V_6 == 0xffffffff ) {
F_21 ( & V_2 -> V_16 ) ;
return V_15 ;
}
if ( V_6 & V_19 ) {
F_22 ( V_2 ) ;
V_9 = V_20 ;
}
F_21 ( & V_2 -> V_16 ) ;
return V_9 ;
}
void F_23 ( struct V_1 * V_21 )
{
F_22 ( V_21 ) ;
F_24 ( V_21 -> V_13 , V_21 ) ;
F_25 ( V_21 ) ;
F_18 ( V_21 , V_22 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_23 ,
V_24 , V_24 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_23 ,
V_24 , 0 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_25 ,
V_26 ,
V_26 ) ;
F_27 ( V_2 , V_25 ,
V_27 ,
V_27 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_27 ( V_2 , V_25 ,
V_26 , 0 ) ;
F_27 ( V_2 , V_25 ,
V_27 , 0 ) ;
}
bool F_29 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , V_17 ) &
V_19 ;
}
void F_30 ( struct V_28 * V_29 )
{
F_25 ( V_29 -> V_21 ) ;
F_31 ( V_29 ) ;
}
