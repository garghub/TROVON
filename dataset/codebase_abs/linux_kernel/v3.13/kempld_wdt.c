static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_10 ;
F_2 ( V_7 ) ;
V_8 = F_3 ( V_7 , F_4 ( V_4 -> V_11 ) ) ;
V_8 &= ~ V_12 ;
V_8 |= ( V_5 & V_12 ) ;
if ( V_5 == V_13 )
V_8 |= V_14 ;
else
V_8 &= ~ V_14 ;
F_5 ( V_7 , F_4 ( V_4 -> V_11 ) , V_8 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_15 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 V_16 = V_17 [ V_18 ] ;
T_3 V_19 ;
T_2 V_20 ;
T_2 V_21 ;
T_1 V_8 ;
if ( ! V_4 )
return - V_10 ;
V_19 = ( T_3 ) V_15 * V_7 -> V_22 ;
V_21 = F_8 ( V_19 , V_16 ) ;
if ( V_21 )
V_19 ++ ;
if ( V_19 > V_4 -> V_9 )
return - V_10 ;
V_20 = V_19 & V_4 -> V_9 ;
F_2 ( V_7 ) ;
V_8 = F_3 ( V_7 , F_4 ( V_4 -> V_11 ) ) ;
V_8 &= ~ V_23 ;
V_8 |= F_9 ( V_16 ) ;
F_5 ( V_7 , F_4 ( V_4 -> V_11 ) , V_8 ) ;
F_10 ( V_7 , F_11 ( V_4 -> V_11 ) ,
V_20 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static unsigned int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned int V_15 ;
T_3 V_20 ;
T_2 V_16 ;
T_2 V_21 ;
T_1 V_8 ;
if ( ! V_4 -> V_9 )
return 0 ;
V_8 = F_3 ( V_7 , F_4 ( V_4 -> V_11 ) ) ;
V_20 = F_13 ( V_7 , F_11 ( V_4 -> V_11 ) ) ;
V_16 = V_17 [ F_14 ( V_8 ) ] ;
V_20 = ( V_20 & V_4 -> V_9 ) * V_16 ;
V_21 = F_8 ( V_20 , V_7 -> V_22 ) ;
if ( V_21 )
V_20 ++ ;
V_15 = V_20 ;
F_15 ( V_15 != V_20 ) ;
return V_15 ;
}
static int F_16 ( struct V_24 * V_25 ,
unsigned int V_15 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_3 * V_26 ;
struct V_3 * V_27 ;
int V_28 ;
V_27 = & V_2 -> V_4 [ V_29 ] ;
V_26 = & V_2 -> V_4 [ V_30 ] ;
if ( V_26 -> V_9 && V_2 -> V_31 > 0 )
V_15 = V_2 -> V_31 ;
V_28 = F_1 ( V_2 , V_27 ,
V_13 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_27 ,
V_15 ) ;
if ( V_28 )
return V_28 ;
V_25 -> V_15 = V_15 ;
return 0 ;
}
static int F_18 ( struct V_24 * V_25 ,
unsigned int V_31 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_3 * V_26 ;
T_1 V_5 = V_32 ;
int V_28 ;
V_26 = & V_2 -> V_4 [ V_30 ] ;
if ( ! V_26 -> V_9 )
return - V_33 ;
if ( V_31 > V_25 -> V_15 )
return - V_10 ;
if ( V_31 > 0 )
V_5 = V_34 ;
V_28 = F_1 ( V_2 , V_26 ,
V_5 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , V_26 ,
V_25 -> V_15 - V_31 ) ;
if ( V_28 )
return V_28 ;
V_2 -> V_31 = V_31 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_26 ;
struct V_3 * V_27 ;
unsigned int V_31 , V_15 ;
V_26 = & V_2 -> V_4 [ V_30 ] ;
V_27 = & V_2 -> V_4 [ V_29 ] ;
F_2 ( V_7 ) ;
V_31 = F_12 ( V_2 , V_26 ) ;
V_15 = F_12 ( V_2 , V_27 ) ;
F_6 ( V_7 ) ;
if ( V_31 )
V_2 -> V_31 = V_15 ;
else
V_2 -> V_31 = 0 ;
V_2 -> V_25 . V_15 = V_31 + V_15 ;
}
static int F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_35 ;
int V_28 ;
V_28 = F_16 ( V_25 , V_25 -> V_15 ) ;
if ( V_28 )
return V_28 ;
F_2 ( V_7 ) ;
V_35 = F_3 ( V_7 , V_36 ) ;
V_35 |= V_37 ;
F_5 ( V_7 , V_36 , V_35 ) ;
V_35 = F_3 ( V_7 , V_36 ) ;
F_6 ( V_7 ) ;
if ( ! ( V_35 & V_37 ) )
return - V_38 ;
return 0 ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_35 ;
F_2 ( V_7 ) ;
V_35 = F_3 ( V_7 , V_36 ) ;
V_35 &= ~ V_37 ;
F_5 ( V_7 , V_36 , V_35 ) ;
V_35 = F_3 ( V_7 , V_36 ) ;
F_6 ( V_7 ) ;
if ( V_35 & V_37 )
return - V_38 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( V_7 ) ;
F_5 ( V_7 , V_39 , 'K' ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static long F_23 ( struct V_24 * V_25 , unsigned int V_40 ,
unsigned long V_41 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
void T_4 * V_42 = ( void T_4 * ) V_41 ;
int V_28 = - V_43 ;
int T_4 * V_44 = V_42 ;
int V_45 ;
switch ( V_40 ) {
case V_46 :
if ( F_24 ( V_45 , V_44 ) )
return - V_47 ;
V_28 = F_18 ( V_25 , V_45 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_22 ( V_25 ) ;
break;
case V_48 :
V_28 = F_25 ( V_2 -> V_31 , ( int T_4 * ) V_41 ) ;
break;
}
return V_28 ;
}
static int F_26 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_25 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_26 ;
struct V_3 * V_27 ;
T_1 V_49 , V_50 , V_51 ;
T_2 V_9 ;
int V_52 , V_53 ;
V_26 = & V_2 -> V_4 [ V_30 ] ;
V_27 = & V_2 -> V_4 [ V_29 ] ;
V_26 -> V_9 = 0 ;
V_27 -> V_9 = 0 ;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
V_49 = F_11 ( V_52 ) ;
V_9 = 0 ;
F_2 ( V_7 ) ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
V_51 = F_3 ( V_7 , V_49 + V_53 ) ;
F_5 ( V_7 , V_49 + V_53 , 0x00 ) ;
V_50 = F_3 ( V_7 , V_49 + V_53 ) ;
if ( V_50 != 0x00 )
break;
F_5 ( V_7 , V_49 + V_53 , V_51 ) ;
V_9 |= 0xff << ( V_53 * 8 ) ;
}
F_6 ( V_7 ) ;
if ( ! V_27 -> V_9 ) {
V_27 -> V_9 = V_9 ;
V_27 -> V_11 = V_52 ;
} else {
if ( V_7 -> V_54 & V_55 ) {
V_26 -> V_9 = V_27 -> V_9 ;
V_27 -> V_9 = V_9 ;
V_26 -> V_11 = V_27 -> V_11 ;
V_27 -> V_11 = V_52 ;
}
break;
}
}
if ( ! V_27 -> V_9 )
return - V_56 ;
return 0 ;
}
static int F_27 ( struct V_57 * V_58 )
{
struct V_6 * V_7 = F_28 ( V_58 -> V_59 . V_60 ) ;
struct V_1 * V_2 ;
struct V_61 * V_59 = & V_58 -> V_59 ;
struct V_24 * V_25 ;
T_1 V_35 ;
int V_28 = 0 ;
V_2 = F_29 ( V_59 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_7 = V_7 ;
V_25 = & V_2 -> V_25 ;
V_25 -> V_60 = V_59 ;
F_2 ( V_7 ) ;
V_35 = F_3 ( V_7 , V_36 ) ;
F_6 ( V_7 ) ;
if ( V_35 & ( V_64 |
V_65 ) ) {
if ( ! V_66 )
F_30 ( V_59 ,
L_1 ) ;
V_66 = true ;
}
V_25 -> V_67 = & V_68 ;
V_25 -> V_69 = & V_70 ;
F_31 ( V_25 , V_2 ) ;
F_32 ( V_25 , V_66 ) ;
V_28 = F_26 ( V_25 ) ;
if ( V_28 )
return V_28 ;
F_16 ( V_25 , V_15 ) ;
F_18 ( V_25 , V_31 ) ;
if ( V_35 & V_37 ) {
F_19 ( V_2 ) ;
F_33 ( V_59 , L_2 ) ;
}
F_34 ( V_58 , V_2 ) ;
V_28 = F_35 ( V_25 ) ;
if ( V_28 )
return V_28 ;
F_33 ( V_59 , L_3 , V_25 -> V_15 ) ;
return 0 ;
}
static void F_36 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_37 ( V_58 ) ;
F_21 ( & V_2 -> V_25 ) ;
}
static int F_38 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_37 ( V_58 ) ;
struct V_24 * V_25 = & V_2 -> V_25 ;
int V_28 = 0 ;
if ( ! V_66 )
V_28 = F_21 ( V_25 ) ;
F_39 ( V_25 ) ;
return V_28 ;
}
static int F_40 ( struct V_57 * V_58 ,
T_5 V_71 )
{
struct V_1 * V_2 = F_37 ( V_58 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
F_2 ( V_7 ) ;
V_2 -> V_72 = F_3 ( V_7 , V_36 ) ;
F_6 ( V_7 ) ;
F_19 ( V_2 ) ;
if ( V_2 -> V_72 & V_37 )
return F_21 ( V_25 ) ;
return 0 ;
}
static int F_41 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_37 ( V_58 ) ;
struct V_24 * V_25 = & V_2 -> V_25 ;
if ( V_2 -> V_72 & V_37 )
return F_20 ( V_25 ) ;
else
return F_21 ( V_25 ) ;
}
