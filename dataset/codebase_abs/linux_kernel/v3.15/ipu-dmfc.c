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
void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_5 ) ;
V_4 -> V_6 -- ;
if ( ! V_4 -> V_6 )
F_6 ( V_4 -> V_7 , V_8 ) ;
if ( V_4 -> V_6 < 0 )
V_4 -> V_6 = 0 ;
F_4 ( & V_4 -> V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_9 ,
int V_10 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_12 , V_13 ;
F_8 ( V_4 -> V_14 ,
L_1 ,
V_9 , V_10 , V_2 -> V_15 -> V_16 ) ;
switch ( V_9 ) {
case 1 :
V_13 = V_17 ;
break;
case 2 :
V_13 = V_18 ;
break;
case 4 :
V_13 = V_19 ;
break;
case 8 :
V_13 = V_20 ;
break;
default:
return - V_21 ;
}
switch ( V_11 ) {
case 16 :
V_13 |= V_22 ;
break;
case 32 :
V_13 |= V_23 ;
break;
case 64 :
V_13 |= V_24 ;
break;
case 128 :
V_13 |= V_25 ;
break;
}
V_13 |= F_9 ( V_10 ) ;
V_12 = F_10 ( V_4 -> V_26 + V_2 -> V_15 -> V_27 ) ;
V_12 &= ~ ( 0xff << V_2 -> V_15 -> V_28 ) ;
V_12 |= V_13 << V_2 -> V_15 -> V_28 ;
F_11 ( V_12 , V_4 -> V_26 + V_2 -> V_15 -> V_27 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_29 = ( ( 1 << V_9 ) - 1 ) << V_10 ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
unsigned long V_30 )
{
int V_9 = 1 ;
while ( V_9 * V_4 -> V_31 < V_30 )
V_9 *= 2 ;
return V_9 ;
}
static int F_13 ( struct V_3 * V_4 , int V_9 )
{
unsigned V_32 , V_33 = 0 ;
int V_34 , V_10 = 0 ;
V_32 = ( 1 << V_9 ) - 1 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
V_33 |= V_4 -> V_36 [ V_34 ] . V_29 ;
while ( V_32 <= 0xff ) {
if ( ! ( V_33 & V_32 ) )
return V_10 ;
V_32 <<= 1 ;
V_10 ++ ;
}
return - V_37 ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_34 ;
F_8 ( V_4 -> V_14 , L_2 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
F_2 ( & V_4 -> V_5 ) ;
if ( ! V_2 -> V_9 )
goto V_38;
V_2 -> V_29 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
V_4 -> V_36 [ V_34 ] . V_29 = 0 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( V_4 -> V_36 [ V_34 ] . V_9 > 0 ) {
V_4 -> V_36 [ V_34 ] . V_10 =
F_13 ( V_4 , V_4 -> V_36 [ V_34 ] . V_9 ) ;
V_4 -> V_36 [ V_34 ] . V_29 =
( ( 1 << V_4 -> V_36 [ V_34 ] . V_9 ) - 1 ) <<
V_4 -> V_36 [ V_34 ] . V_10 ;
}
}
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( V_4 -> V_36 [ V_34 ] . V_9 > 0 )
F_7 ( & V_4 -> V_36 [ V_34 ] ,
V_4 -> V_36 [ V_34 ] . V_9 ,
V_4 -> V_36 [ V_34 ] . V_10 ,
V_4 -> V_36 [ V_34 ] . V_11 ) ;
}
V_38:
F_4 ( & V_4 -> V_5 ) ;
}
int F_15 ( struct V_1 * V_2 ,
unsigned long V_39 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_9 = F_12 ( V_4 , V_39 ) ;
int V_10 = - 1 , V_40 = 0 ;
F_8 ( V_4 -> V_14 , L_3 ,
V_39 / 1000000 ,
V_2 -> V_15 -> V_16 ) ;
F_14 ( V_2 ) ;
F_2 ( & V_4 -> V_5 ) ;
if ( V_9 > 8 ) {
V_40 = - V_37 ;
goto V_38;
}
if ( V_2 -> V_15 -> V_16 == V_41 )
V_10 = F_13 ( V_4 , V_9 * 2 ) ;
else if ( V_9 < 2 )
V_9 = 2 ;
if ( V_10 >= 0 )
V_9 *= 2 ;
else
V_10 = F_13 ( V_4 , V_9 ) ;
if ( V_10 < 0 ) {
V_40 = - V_37 ;
goto V_38;
}
F_7 ( V_2 , V_9 , V_10 , V_11 ) ;
V_38:
F_4 ( & V_4 -> V_5 ) ;
return V_40 ;
}
int F_16 ( struct V_1 * V_2 , int V_42 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_43 ;
V_43 = F_10 ( V_4 -> V_26 + V_44 ) ;
if ( ( V_2 -> V_9 * 64 * 4 ) / V_42 > V_2 -> V_15 -> V_45 )
V_43 |= 1 << V_2 -> V_15 -> V_46 ;
else
V_43 &= ~ ( 1 << V_2 -> V_15 -> V_46 ) ;
F_11 ( V_43 , V_4 -> V_26 + V_44 ) ;
return 0 ;
}
struct V_1 * F_17 ( struct V_47 * V_7 , int V_16 )
{
struct V_3 * V_4 = V_7 -> V_48 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
if ( V_49 [ V_34 ] . V_16 == V_16 )
return & V_4 -> V_36 [ V_34 ] ;
return F_18 ( - V_50 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
}
int F_20 ( struct V_47 * V_7 , struct V_51 * V_14 , unsigned long V_26 ,
struct V_52 * V_53 )
{
struct V_3 * V_4 ;
int V_34 ;
V_4 = F_21 ( V_14 , sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return - V_55 ;
V_4 -> V_26 = F_22 ( V_14 , V_26 , V_56 ) ;
if ( ! V_4 -> V_26 )
return - V_55 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_7 = V_7 ;
F_23 ( & V_4 -> V_5 ) ;
V_7 -> V_48 = V_4 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
V_4 -> V_36 [ V_34 ] . V_4 = V_4 ;
V_4 -> V_36 [ V_34 ] . V_7 = V_7 ;
V_4 -> V_36 [ V_34 ] . V_15 = & V_49 [ V_34 ] ;
}
F_11 ( 0x0 , V_4 -> V_26 + V_57 ) ;
F_11 ( 0x0 , V_4 -> V_26 + V_58 ) ;
V_4 -> V_31 = F_24 ( V_53 ) * 4 / 8 ;
F_8 ( V_14 , L_4 ,
V_4 -> V_31 / 1000000 ) ;
F_11 ( 0x202020f6 , V_4 -> V_26 + V_59 ) ;
F_11 ( 0x2020f6f6 , V_4 -> V_26 + V_60 ) ;
F_11 ( 0x00000003 , V_4 -> V_26 + V_44 ) ;
return 0 ;
}
void F_25 ( struct V_47 * V_7 )
{
}
