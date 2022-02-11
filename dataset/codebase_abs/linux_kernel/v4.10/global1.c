int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
int V_5 = V_2 -> V_6 -> V_7 ;
return F_2 ( V_2 , V_5 , V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int V_5 = V_2 -> V_6 -> V_7 ;
return F_4 ( V_2 , V_5 , V_3 , V_4 ) ;
}
int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_8 )
{
return F_6 ( V_2 , V_2 -> V_6 -> V_7 , V_3 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
V_11 = F_1 ( V_2 , V_12 , & V_9 ) ;
if ( V_11 )
return V_11 ;
V_9 &= V_13 ;
if ( V_9 != V_14 )
return 0 ;
F_8 ( 1000 , 2000 ) ;
}
return - V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < 16 ; ++ V_10 ) {
V_11 = F_1 ( V_2 , V_12 , & V_9 ) ;
if ( V_11 )
return V_11 ;
V_9 &= V_13 ;
if ( V_9 == V_14 )
return 0 ;
F_8 ( 1000 , 2000 ) ;
}
return - V_15 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < 16 ; ++ V_10 ) {
V_11 = F_1 ( V_2 , V_12 , & V_9 ) ;
if ( V_11 )
return V_11 ;
if ( V_9 & V_16 )
return 0 ;
F_8 ( 1000 , 2000 ) ;
}
return - V_15 ;
}
static int F_11 ( struct V_1 * V_2 )
{
const unsigned long V_17 = V_18 + 1 * V_19 ;
T_1 V_4 ;
int V_11 ;
while ( F_12 ( V_18 , V_17 ) ) {
V_11 = F_1 ( V_2 , V_12 , & V_4 ) ;
if ( V_11 )
return V_11 ;
if ( V_4 & V_20 )
break;
F_8 ( 1000 , 2000 ) ;
}
if ( F_13 ( V_18 , V_17 ) )
return - V_15 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_21 , & V_4 ) ;
if ( V_11 )
return V_11 ;
V_4 |= V_22 ;
V_4 |= V_23 ;
V_11 = F_3 ( V_2 , V_21 , V_4 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_11 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return F_9 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_21 , & V_4 ) ;
if ( V_11 )
return V_11 ;
V_4 |= V_22 ;
V_11 = F_3 ( V_2 , V_21 , V_4 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_11 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return F_10 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_21 , & V_4 ) ;
if ( V_11 )
return V_11 ;
V_4 |= V_23 ;
V_11 = F_3 ( V_2 , V_21 , V_4 ) ;
if ( V_11 )
return V_11 ;
return F_9 ( V_2 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_21 , & V_4 ) ;
if ( V_11 )
return V_11 ;
V_4 &= ~ V_23 ;
V_11 = F_3 ( V_2 , V_21 , V_4 ) ;
if ( V_11 )
return V_11 ;
return F_7 ( V_2 ) ;
}
int F_18 ( struct V_1 * V_2 , int V_24 )
{
T_1 V_3 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_25 , & V_3 ) ;
if ( V_11 )
return V_11 ;
V_3 &= ~ ( V_26 |
V_27 ) ;
V_3 |= V_24 << V_28 |
V_24 << V_29 ;
return F_3 ( V_2 , V_25 , V_3 ) ;
}
int F_19 ( struct V_1 * V_2 , int V_24 )
{
T_1 V_3 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_25 , & V_3 ) ;
if ( V_11 )
return V_11 ;
V_3 &= ~ V_30 ;
V_3 |= V_24 << V_31 ;
return F_3 ( V_2 , V_25 , V_3 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
T_1 V_32 , T_2 V_33 )
{
T_1 V_3 ;
V_3 = V_34 | V_32 | V_33 ;
return F_3 ( V_2 , V_25 , V_3 ) ;
}
int F_21 ( struct V_1 * V_2 , int V_24 )
{
int V_11 ;
V_11 = F_20 ( V_2 , V_35 ,
V_24 ) ;
if ( V_11 )
return V_11 ;
return F_20 ( V_2 , V_36 ,
V_24 ) ;
}
int F_22 ( struct V_1 * V_2 , int V_24 )
{
return F_20 ( V_2 , V_37 ,
V_24 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_20 (
V_2 , V_38 , 0xff ) ;
if ( V_11 )
return V_11 ;
V_11 = F_20 (
V_2 , V_39 , 0xff ) ;
if ( V_11 )
return V_11 ;
V_11 = F_20 (
V_2 , V_40 , 0xff ) ;
if ( V_11 )
return V_11 ;
return F_20 (
V_2 , V_41 , 0xff ) ;
}
int F_24 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_42 , & V_4 ) ;
if ( V_11 )
return V_11 ;
V_4 |= V_43 ;
V_11 = F_3 ( V_2 , V_42 , V_4 ) ;
return V_11 ;
}
int F_25 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_44 , V_45 ) ;
}
int F_26 ( struct V_1 * V_2 , int V_24 )
{
int V_11 ;
V_11 = F_3 ( V_2 , V_44 ,
V_46 |
V_47 | V_24 ) ;
if ( V_11 )
return V_11 ;
return F_25 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 , int V_24 )
{
V_24 = ( V_24 + 1 ) << 5 ;
return F_26 ( V_2 , V_24 ) ;
}
int F_28 ( struct V_1 * V_2 , int V_24 )
{
int V_11 ;
V_24 = ( V_24 + 1 ) << 5 ;
V_11 = F_3 ( V_2 , V_44 ,
V_46 | V_24 ) ;
if ( V_11 )
return V_11 ;
return F_25 ( V_2 ) ;
}
void F_29 ( struct V_1 * V_2 , int V_48 , T_3 * V_4 )
{
T_3 V_49 ;
T_1 V_3 ;
int V_11 ;
* V_4 = 0 ;
V_11 = F_3 ( V_2 , V_44 ,
V_50 | V_48 ) ;
if ( V_11 )
return;
V_11 = F_25 ( V_2 ) ;
if ( V_11 )
return;
V_11 = F_1 ( V_2 , V_51 , & V_3 ) ;
if ( V_11 )
return;
V_49 = V_3 << 16 ;
V_11 = F_1 ( V_2 , V_52 , & V_3 ) ;
if ( V_11 )
return;
* V_4 = V_49 | V_3 ;
}
