static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 )
{
unsigned long V_5 = V_2 -> V_6 + 0x80 + V_4 ;
if ( V_4 != V_7 && V_4 != V_8 ) {
if ( V_3 & 0xffff )
V_3 |= ( F_2 ( V_5 ) & 0xffff ) ;
else
V_3 |= ( F_2 ( V_5 ) ^ ( V_3 >> 16 ) ) ;
}
F_3 ( V_3 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_9 ,
unsigned int V_4 )
{
if ( V_9 < 16 )
F_3 ( 1 << V_9 , V_2 -> V_6 + V_4 ) ;
else
F_1 ( V_2 , 1 << ( V_9 - 16 ) , V_4 ) ;
}
void F_5 ( unsigned V_9 , unsigned int V_4 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_10 ;
F_6 ( & V_2 -> V_11 , V_10 ) ;
F_4 ( V_2 , V_9 , V_4 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_9 ,
unsigned int V_4 )
{
if ( V_9 < 16 )
F_3 ( 1 << ( V_9 + 16 ) , V_2 -> V_6 + V_4 ) ;
else
F_1 ( V_2 , 1 << V_9 , V_4 ) ;
}
void F_9 ( unsigned V_9 , unsigned int V_4 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_10 ;
F_6 ( & V_2 -> V_11 , V_10 ) ;
F_8 ( V_2 , V_9 , V_4 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
}
int F_10 ( unsigned V_9 , unsigned int V_4 )
{
struct V_1 * V_2 = & V_1 ;
unsigned long V_10 ;
long V_3 ;
F_6 ( & V_2 -> V_11 , V_10 ) ;
if ( V_9 < 16 )
V_3 = F_2 ( V_2 -> V_6 + V_4 ) ;
else {
V_3 = F_2 ( V_2 -> V_6 + 0x80 + V_4 ) ;
V_9 -= 16 ;
}
F_7 ( & V_2 -> V_11 , V_10 ) ;
return ( V_3 & ( 1 << V_9 ) ) ? 1 : 0 ;
}
int F_11 ( unsigned V_12 , unsigned V_13 )
{
T_2 V_14 , V_15 ;
if ( V_12 > 7 || V_13 > 15 )
return - V_16 ;
F_12 ( V_17 , V_14 , V_15 ) ;
V_14 &= ~ ( 0xF << ( V_12 * 4 ) ) ;
V_14 |= ( V_13 & 0xF ) << ( V_12 * 4 ) ;
F_13 ( V_17 , V_14 , V_15 ) ;
return 0 ;
}
void F_14 ( unsigned V_9 , int V_18 , int V_19 )
{
struct V_1 * V_2 = & V_1 ;
T_2 V_20 = ( V_9 % 8 ) * 4 ;
unsigned long V_10 ;
T_2 V_3 ;
if ( V_9 >= 24 )
V_9 = V_21 ;
else if ( V_9 >= 16 )
V_9 = V_22 ;
else if ( V_9 >= 8 )
V_9 = V_23 ;
else
V_9 = V_24 ;
F_6 ( & V_2 -> V_11 , V_10 ) ;
V_3 = F_2 ( V_2 -> V_6 + V_9 ) ;
V_3 &= ~ ( 0xF << V_20 ) ;
V_3 |= ( ( V_18 & 7 ) << V_20 ) ;
if ( V_19 )
V_3 |= ( 1 << ( V_20 + 3 ) ) ;
F_3 ( V_3 , V_2 -> V_6 + V_9 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
}
static int F_15 ( struct V_25 * V_26 , unsigned V_9 )
{
struct V_1 * V_2 = F_16 ( V_26 ) ;
unsigned long V_10 ;
F_6 ( & V_2 -> V_11 , V_10 ) ;
if ( ( V_27 & ( 1 << V_9 ) ) == 0 ) {
F_17 ( & V_2 -> V_28 -> V_29 ,
L_1 , V_9 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
return - V_16 ;
}
F_8 ( V_2 , V_9 , V_30 ) ;
F_8 ( V_2 , V_9 , V_31 ) ;
F_8 ( V_2 , V_9 , V_32 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_2 , unsigned V_9 )
{
return F_10 ( V_9 , V_33 ) ;
}
static void F_19 ( struct V_25 * V_2 , unsigned V_9 , int V_3 )
{
if ( V_3 )
F_5 ( V_9 , V_34 ) ;
else
F_9 ( V_9 , V_34 ) ;
}
static int F_20 ( struct V_25 * V_26 , unsigned V_9 )
{
struct V_1 * V_2 = F_16 ( V_26 ) ;
unsigned long V_10 ;
F_6 ( & V_2 -> V_11 , V_10 ) ;
F_4 ( V_2 , V_9 , V_35 ) ;
F_8 ( V_2 , V_9 , V_36 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_21 ( struct V_25 * V_26 , unsigned V_9 , int V_3 )
{
struct V_1 * V_2 = F_16 ( V_26 ) ;
unsigned long V_10 ;
F_6 ( & V_2 -> V_11 , V_10 ) ;
F_4 ( V_2 , V_9 , V_35 ) ;
F_4 ( V_2 , V_9 , V_36 ) ;
if ( V_3 )
F_4 ( V_2 , V_9 , V_34 ) ;
else
F_8 ( V_2 , V_9 , V_34 ) ;
F_7 ( & V_2 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_28 )
{
struct V_38 * V_39 ;
int V_40 = - V_41 ;
T_3 V_42 = V_27 ;
V_39 = F_23 ( V_28 , V_43 , 0 ) ;
if ( ! V_39 ) {
F_24 ( & V_28 -> V_29 , L_2 ) ;
goto V_44;
}
if ( ! F_25 ( & V_28 -> V_29 , V_39 -> V_45 , F_26 ( V_39 ) ,
V_28 -> V_46 ) ) {
F_24 ( & V_28 -> V_29 , L_3 ) ;
goto V_44;
}
V_1 . V_6 = V_39 -> V_45 ;
V_1 . V_28 = V_28 ;
F_27 ( & V_1 . V_11 ) ;
F_17 ( & V_28 -> V_29 , L_4 , V_39 ) ;
V_27 &= 0x1F7FFFFF ;
V_27 &= ~ ( 1 << 28 ) ;
if ( V_42 != V_27 )
F_17 ( & V_28 -> V_29 , L_5 ,
V_42 , V_27 ) ;
V_40 = F_28 ( & V_1 . V_2 , & V_1 ) ;
if ( V_40 )
goto V_44;
return 0 ;
V_44:
return V_40 ;
}
static int F_29 ( struct V_37 * V_28 )
{
F_30 ( & V_1 . V_2 ) ;
return 0 ;
}
