int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
if ( ! V_4 -> V_6 )
F_3 ( V_4 -> V_7 , V_8 ) ;
V_4 -> V_6 ++ ;
F_4 ( & V_4 -> V_5 ) ;
return 0 ;
}
static void F_5 ( struct V_3 * V_4 )
{
unsigned long V_9 = V_10 + F_6 ( 1000 ) ;
while ( ( F_7 ( V_4 -> V_11 + V_12 ) & 0x02fff000 ) != 0x02fff000 ) {
if ( F_8 ( V_10 , V_9 ) ) {
F_9 ( V_4 -> V_13 ,
L_1 ) ;
break;
}
F_10 () ;
}
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
V_4 -> V_6 -- ;
if ( ! V_4 -> V_6 ) {
F_5 ( V_4 ) ;
F_12 ( V_4 -> V_7 , V_8 ) ;
}
if ( V_4 -> V_6 < 0 )
V_4 -> V_6 = 0 ;
F_4 ( & V_4 -> V_5 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_14 ,
int V_15 , int V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_17 , V_18 ;
F_14 ( V_4 -> V_13 ,
L_2 ,
V_14 , V_15 , V_2 -> V_19 -> V_20 ) ;
switch ( V_14 ) {
case 1 :
V_18 = V_21 ;
break;
case 2 :
V_18 = V_22 ;
break;
case 4 :
V_18 = V_23 ;
break;
case 8 :
V_18 = V_24 ;
break;
default:
return - V_25 ;
}
switch ( V_16 ) {
case 16 :
V_18 |= V_26 ;
break;
case 32 :
V_18 |= V_27 ;
break;
case 64 :
V_18 |= V_28 ;
break;
case 128 :
V_18 |= V_29 ;
break;
}
V_18 |= F_15 ( V_15 ) ;
V_17 = F_7 ( V_4 -> V_11 + V_2 -> V_19 -> V_30 ) ;
V_17 &= ~ ( 0xff << V_2 -> V_19 -> V_31 ) ;
V_17 |= V_18 << V_2 -> V_19 -> V_31 ;
F_16 ( V_17 , V_4 -> V_11 + V_2 -> V_19 -> V_30 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_32 = ( ( 1 << V_14 ) - 1 ) << V_15 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
unsigned long V_33 )
{
int V_14 = 1 ;
while ( V_14 * V_4 -> V_34 < V_33 )
V_14 *= 2 ;
return V_14 ;
}
static int F_18 ( struct V_3 * V_4 , int V_14 )
{
unsigned V_35 , V_36 = 0 ;
int V_37 , V_15 = 0 ;
V_35 = ( 1 << V_14 ) - 1 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_36 |= V_4 -> V_39 [ V_37 ] . V_32 ;
while ( V_35 <= 0xff ) {
if ( ! ( V_36 & V_35 ) )
return V_15 ;
V_35 <<= 1 ;
V_15 ++ ;
}
return - V_40 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_37 ;
F_14 ( V_4 -> V_13 , L_3 ,
V_2 -> V_14 , V_2 -> V_15 ) ;
F_2 ( & V_4 -> V_5 ) ;
if ( ! V_2 -> V_14 )
goto V_41;
V_2 -> V_32 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_4 -> V_39 [ V_37 ] . V_32 = 0 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( V_4 -> V_39 [ V_37 ] . V_14 > 0 ) {
V_4 -> V_39 [ V_37 ] . V_15 =
F_18 ( V_4 , V_4 -> V_39 [ V_37 ] . V_14 ) ;
V_4 -> V_39 [ V_37 ] . V_32 =
( ( 1 << V_4 -> V_39 [ V_37 ] . V_14 ) - 1 ) <<
V_4 -> V_39 [ V_37 ] . V_15 ;
}
}
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( V_4 -> V_39 [ V_37 ] . V_14 > 0 )
F_13 ( & V_4 -> V_39 [ V_37 ] ,
V_4 -> V_39 [ V_37 ] . V_14 ,
V_4 -> V_39 [ V_37 ] . V_15 ,
V_4 -> V_39 [ V_37 ] . V_16 ) ;
}
V_41:
F_4 ( & V_4 -> V_5 ) ;
}
int F_20 ( struct V_1 * V_2 ,
unsigned long V_42 , int V_16 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_14 = F_17 ( V_4 , V_42 ) ;
int V_15 = - 1 , V_43 = 0 ;
F_14 ( V_4 -> V_13 , L_4 ,
V_42 / 1000000 ,
V_2 -> V_19 -> V_20 ) ;
F_19 ( V_2 ) ;
F_2 ( & V_4 -> V_5 ) ;
if ( V_14 > 8 ) {
V_43 = - V_40 ;
goto V_41;
}
if ( V_2 -> V_19 -> V_20 == V_44 )
V_15 = F_18 ( V_4 , V_14 * 2 ) ;
else if ( V_14 < 2 )
V_14 = 2 ;
if ( V_15 >= 0 )
V_14 *= 2 ;
else
V_15 = F_18 ( V_4 , V_14 ) ;
if ( V_15 < 0 ) {
V_43 = - V_40 ;
goto V_41;
}
F_13 ( V_2 , V_14 , V_15 , V_16 ) ;
V_41:
F_4 ( & V_4 -> V_5 ) ;
return V_43 ;
}
void F_21 ( struct V_1 * V_2 , int V_45 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_46 ;
F_2 ( & V_4 -> V_5 ) ;
V_46 = F_7 ( V_4 -> V_11 + V_47 ) ;
if ( ( V_2 -> V_14 * 64 * 4 ) / V_45 > V_2 -> V_19 -> V_48 )
V_46 |= 1 << V_2 -> V_19 -> V_49 ;
else
V_46 &= ~ ( 1 << V_2 -> V_19 -> V_49 ) ;
F_16 ( V_46 , V_4 -> V_11 + V_47 ) ;
F_4 ( & V_4 -> V_5 ) ;
}
struct V_1 * F_22 ( struct V_50 * V_7 , int V_20 )
{
struct V_3 * V_4 = V_7 -> V_51 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_52 [ V_37 ] . V_20 == V_20 )
return & V_4 -> V_39 [ V_37 ] ;
return F_23 ( - V_53 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
}
int F_25 ( struct V_50 * V_7 , struct V_54 * V_13 , unsigned long V_11 ,
struct V_55 * V_56 )
{
struct V_3 * V_4 ;
int V_37 ;
V_4 = F_26 ( V_13 , sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 )
return - V_58 ;
V_4 -> V_11 = F_27 ( V_13 , V_11 , V_59 ) ;
if ( ! V_4 -> V_11 )
return - V_58 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_7 = V_7 ;
F_28 ( & V_4 -> V_5 ) ;
V_7 -> V_51 = V_4 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
V_4 -> V_39 [ V_37 ] . V_4 = V_4 ;
V_4 -> V_39 [ V_37 ] . V_7 = V_7 ;
V_4 -> V_39 [ V_37 ] . V_19 = & V_52 [ V_37 ] ;
}
F_16 ( 0x0 , V_4 -> V_11 + V_60 ) ;
F_16 ( 0x0 , V_4 -> V_11 + V_61 ) ;
V_4 -> V_34 = F_29 ( V_56 ) * 4 / 8 ;
F_14 ( V_13 , L_5 ,
V_4 -> V_34 / 1000000 ) ;
F_16 ( 0x202020f6 , V_4 -> V_11 + V_62 ) ;
F_16 ( 0x2020f6f6 , V_4 -> V_11 + V_63 ) ;
F_16 ( 0x00000003 , V_4 -> V_11 + V_47 ) ;
return 0 ;
}
void F_30 ( struct V_50 * V_7 )
{
}
