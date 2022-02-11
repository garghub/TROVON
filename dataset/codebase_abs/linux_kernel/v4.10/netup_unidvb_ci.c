T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x101 , V_2 -> V_3 + V_4 ) ;
return V_5 ;
}
static int F_3 ( struct V_6 * V_7 ,
int V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
T_2 V_13 = ( V_10 -> V_14 == 1 ) ? V_15 : 0 ;
F_4 ( & V_12 -> V_16 -> V_12 , L_1 ,
V_17 , F_5 ( V_12 -> V_3 + V_18 ) ) ;
if ( V_8 != 0 )
return - V_19 ;
F_2 ( V_20 << V_13 , V_12 -> V_3 + V_4 ) ;
F_4 ( & V_12 -> V_16 -> V_12 , L_2 ,
V_17 , F_5 ( V_12 -> V_3 + V_18 ) ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
int V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
F_4 ( & V_12 -> V_16 -> V_12 , L_3 , V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
int V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
unsigned long V_21 = 0 ;
T_2 V_13 = ( V_10 -> V_14 == 1 ) ? V_15 : 0 ;
T_2 V_22 = 0 ;
int V_23 = 3 ;
F_4 ( & V_12 -> V_16 -> V_12 , L_4 ,
V_17 , F_5 ( V_12 -> V_3 + V_18 ) ) ;
V_24:
V_21 = V_25 + F_8 ( 5000 ) ;
F_2 ( V_26 << V_13 , V_12 -> V_3 + V_18 ) ;
F_4 ( & V_12 -> V_16 -> V_12 , L_5 , V_17 ) ;
while ( F_9 ( V_25 , V_21 ) ) {
V_22 = F_5 ( V_12 -> V_3 + V_18 ) ;
if ( V_22 & ( V_27 << V_13 ) )
break;
F_10 ( 1000 ) ;
}
if ( ! ( V_22 & ( V_27 << V_13 ) ) && V_23 > 0 ) {
F_4 ( & V_12 -> V_16 -> V_12 ,
L_6 ,
V_17 ) ;
V_23 -- ;
goto V_24;
}
return 0 ;
}
static int F_11 ( struct V_6 * V_7 ,
int V_8 , int V_28 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
T_2 V_13 = ( V_10 -> V_14 == 1 ) ? V_15 : 0 ;
T_2 V_22 = 0 ;
F_4 ( & V_12 -> V_16 -> V_12 , L_4 ,
V_17 , F_5 ( V_12 -> V_3 + V_18 ) ) ;
V_22 = F_5 ( V_12 -> V_3 + V_18 ) ;
if ( V_22 & ( V_27 << V_13 ) ) {
V_10 -> V_29 = V_30 |
V_31 ;
} else if ( V_22 & ( V_32 << V_13 ) ) {
V_10 -> V_29 = V_30 ;
} else {
V_10 -> V_29 = 0 ;
}
return V_10 -> V_29 ;
}
static int F_12 ( struct V_6 * V_7 ,
int V_8 , int V_33 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
T_3 V_34 = * ( ( T_3 V_35 * ) V_10 -> V_36 + V_33 ) ;
F_4 ( & V_12 -> V_16 -> V_12 ,
L_7 , V_17 , V_33 , V_34 ) ;
return V_34 ;
}
static int F_13 ( struct V_6 * V_7 ,
int V_8 , int V_33 , T_3 V_11 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
F_4 ( & V_12 -> V_16 -> V_12 ,
L_8 , V_17 , V_33 , V_11 ) ;
* ( ( T_3 V_35 * ) V_10 -> V_36 + V_33 ) = V_11 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
int V_8 , T_3 V_33 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
T_3 V_34 = * ( ( T_3 V_35 * ) V_10 -> V_37 + V_33 ) ;
F_4 ( & V_12 -> V_16 -> V_12 ,
L_7 , V_17 , V_33 , V_34 ) ;
return V_34 ;
}
static int F_15 ( struct V_6 * V_7 ,
int V_8 , T_3 V_33 , T_3 V_11 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = V_10 -> V_12 ;
F_4 ( & V_12 -> V_16 -> V_12 ,
L_8 , V_17 , V_33 , V_11 ) ;
* ( ( T_3 V_35 * ) V_10 -> V_37 + V_33 ) = V_11 ;
return 0 ;
}
int F_16 ( struct V_1 * V_12 ,
int V_38 , struct V_16 * V_16 )
{
int V_39 ;
struct V_9 * V_10 ;
if ( V_38 < 0 || V_38 > 1 ) {
F_17 ( & V_16 -> V_12 , L_9 ,
V_17 , V_38 ) ;
return - V_19 ;
}
V_10 = & V_12 -> V_40 [ V_38 ] ;
V_10 -> V_14 = V_38 ;
V_10 -> V_36 = V_12 -> V_41 +
( ( V_38 == 0 ) ? V_42 : V_43 ) ;
V_10 -> V_37 = V_12 -> V_41 +
( ( V_38 == 0 ) ? V_44 : V_45 ) ;
V_10 -> V_12 = V_12 ;
V_10 -> V_46 . V_47 = V_48 ;
V_10 -> V_46 . V_49 = F_12 ;
V_10 -> V_46 . V_50 = F_13 ;
V_10 -> V_46 . V_51 = F_14 ;
V_10 -> V_46 . V_52 = F_15 ;
V_10 -> V_46 . V_53 = F_7 ;
V_10 -> V_46 . V_54 = F_6 ;
V_10 -> V_46 . V_55 = F_3 ;
V_10 -> V_46 . V_56 = F_11 ;
V_10 -> V_46 . V_11 = V_10 ;
V_39 = F_18 ( & V_12 -> V_57 [ V_38 ] . V_58 ,
& V_10 -> V_46 , 0 , 1 ) ;
if ( V_39 < 0 ) {
F_17 ( & V_16 -> V_12 ,
L_10 ,
V_17 , V_39 ) ;
return V_39 ;
}
F_2 ( V_59 , V_12 -> V_3 + V_60 ) ;
F_19 ( & V_16 -> V_12 ,
L_11 , V_17 , V_38 ) ;
return 0 ;
}
void F_20 ( struct V_1 * V_12 , int V_38 )
{
struct V_9 * V_10 ;
F_4 ( & V_12 -> V_16 -> V_12 , L_3 , V_17 ) ;
if ( V_38 < 0 || V_38 > 1 ) {
F_17 ( & V_12 -> V_16 -> V_12 , L_9 ,
V_17 , V_38 ) ;
return;
}
V_10 = & V_12 -> V_40 [ V_38 ] ;
F_21 ( & V_10 -> V_46 ) ;
}
