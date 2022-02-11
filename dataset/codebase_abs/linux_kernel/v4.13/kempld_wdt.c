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
T_2 V_16 ;
T_3 V_17 ;
T_2 V_18 ;
T_2 V_19 ;
T_1 V_8 ;
#if V_20 < 40400
V_16 = F_8 ( V_21 [ V_22 ] ) ;
#else
V_16 = V_21 [ V_22 ] ;
#endif
if ( ! V_4 )
return - V_10 ;
V_17 = ( T_3 ) V_15 * V_7 -> V_23 ;
V_19 = F_9 ( V_17 , V_16 ) ;
if ( V_19 )
V_17 ++ ;
if ( V_17 > V_4 -> V_9 )
return - V_10 ;
V_18 = V_17 & V_4 -> V_9 ;
F_2 ( V_7 ) ;
V_8 = F_3 ( V_7 , F_4 ( V_4 -> V_11 ) ) ;
V_8 &= ~ V_24 ;
V_8 |= F_10 ( V_22 ) ;
F_5 ( V_7 , F_4 ( V_4 -> V_11 ) , V_8 ) ;
F_11 ( V_7 , F_12 ( V_4 -> V_11 ) ,
V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static unsigned int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned int V_15 ;
T_3 V_18 ;
T_2 V_16 ;
T_2 V_19 ;
T_1 V_8 ;
if ( ! V_4 -> V_9 )
return 0 ;
V_8 = F_3 ( V_7 , F_4 ( V_4 -> V_11 ) ) ;
V_18 = F_14 ( V_7 , F_12 ( V_4 -> V_11 ) ) ;
V_16 = V_21 [ F_15 ( V_8 ) ] ;
V_18 = ( V_18 & V_4 -> V_9 ) * V_16 ;
V_19 = F_9 ( V_18 , V_7 -> V_23 ) ;
if ( V_19 )
V_18 ++ ;
V_15 = V_18 ;
F_16 ( V_15 != V_18 ) ;
return V_15 ;
}
static int F_17 ( struct V_25 * V_26 ,
unsigned int V_15 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_3 * V_27 ;
struct V_3 * V_28 ;
int V_29 ;
V_28 = & V_2 -> V_4 [ V_30 ] ;
V_27 = & V_2 -> V_4 [ V_31 ] ;
if ( V_27 -> V_9 && V_2 -> V_32 > 0 )
V_15 = V_2 -> V_32 ;
V_29 = F_1 ( V_2 , V_28 ,
V_13 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_7 ( V_2 , V_28 ,
V_15 ) ;
if ( V_29 )
return V_29 ;
V_26 -> V_15 = V_15 ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 ,
unsigned int V_32 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_3 * V_27 ;
T_1 V_5 = V_33 ;
int V_29 ;
V_27 = & V_2 -> V_4 [ V_31 ] ;
if ( ! V_27 -> V_9 )
return - V_34 ;
if ( V_32 > V_26 -> V_15 )
return - V_10 ;
if ( V_32 > 0 )
V_5 = V_35 ;
V_29 = F_1 ( V_2 , V_27 ,
V_5 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_7 ( V_2 , V_27 ,
V_26 -> V_15 - V_32 ) ;
if ( V_29 )
return V_29 ;
V_2 -> V_32 = V_32 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_27 ;
struct V_3 * V_28 ;
unsigned int V_32 , V_15 ;
V_27 = & V_2 -> V_4 [ V_31 ] ;
V_28 = & V_2 -> V_4 [ V_30 ] ;
F_2 ( V_7 ) ;
V_32 = F_13 ( V_2 , V_27 ) ;
V_15 = F_13 ( V_2 , V_28 ) ;
F_6 ( V_7 ) ;
if ( V_32 )
V_2 -> V_32 = V_15 ;
else
V_2 -> V_32 = 0 ;
V_2 -> V_26 . V_15 = V_32 + V_15 ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_36 ;
int V_29 ;
V_29 = F_17 ( V_26 , V_26 -> V_15 ) ;
if ( V_29 )
return V_29 ;
F_2 ( V_7 ) ;
V_36 = F_3 ( V_7 , V_37 ) ;
V_36 |= V_38 ;
F_5 ( V_7 , V_37 , V_36 ) ;
V_36 = F_3 ( V_7 , V_37 ) ;
F_6 ( V_7 ) ;
if ( ! ( V_36 & V_38 ) )
return - V_39 ;
return 0 ;
}
static int F_22 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_36 ;
F_2 ( V_7 ) ;
V_36 = F_3 ( V_7 , V_37 ) ;
V_36 &= ~ V_38 ;
F_5 ( V_7 , V_37 , V_36 ) ;
V_36 = F_3 ( V_7 , V_37 ) ;
F_6 ( V_7 ) ;
if ( V_36 & V_38 )
return - V_39 ;
return 0 ;
}
static int F_23 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( V_7 ) ;
F_5 ( V_7 , V_40 , 'K' ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static long F_24 ( struct V_25 * V_26 , unsigned int V_41 ,
unsigned long V_42 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
void T_4 * V_43 = ( void T_4 * ) V_42 ;
int V_29 = - V_44 ;
int T_4 * V_45 = V_43 ;
int V_46 ;
switch ( V_41 ) {
case V_47 :
if ( F_25 ( V_46 , V_45 ) )
return - V_48 ;
V_29 = F_19 ( V_26 , V_46 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_23 ( V_26 ) ;
break;
case V_49 :
V_29 = F_26 ( V_2 -> V_32 , ( int T_4 * ) V_42 ) ;
break;
}
return V_29 ;
}
static int F_27 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_3 * V_27 ;
struct V_3 * V_28 ;
T_1 V_50 , V_51 , V_52 ;
T_2 V_9 ;
int V_53 , V_54 ;
V_27 = & V_2 -> V_4 [ V_31 ] ;
V_28 = & V_2 -> V_4 [ V_30 ] ;
V_27 -> V_9 = 0 ;
V_28 -> V_9 = 0 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
V_50 = F_12 ( V_53 ) ;
V_9 = 0 ;
F_2 ( V_7 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_52 = F_3 ( V_7 , V_50 + V_54 ) ;
F_5 ( V_7 , V_50 + V_54 , 0x00 ) ;
V_51 = F_3 ( V_7 , V_50 + V_54 ) ;
if ( V_51 != 0x00 )
break;
F_5 ( V_7 , V_50 + V_54 , V_52 ) ;
V_9 |= 0xff << ( V_54 * 8 ) ;
}
F_6 ( V_7 ) ;
if ( ! V_28 -> V_9 ) {
V_28 -> V_9 = V_9 ;
V_28 -> V_11 = V_53 ;
} else {
if ( V_7 -> V_55 & V_56 ) {
V_27 -> V_9 = V_28 -> V_9 ;
V_28 -> V_9 = V_9 ;
V_27 -> V_11 = V_28 -> V_11 ;
V_28 -> V_11 = V_53 ;
}
break;
}
}
if ( ! V_28 -> V_9 )
return - V_57 ;
return 0 ;
}
static int F_28 ( struct V_58 * V_59 )
{
struct V_6 * V_7 = F_29 ( V_59 -> V_60 . V_61 ) ;
struct V_1 * V_2 ;
struct V_62 * V_60 = & V_59 -> V_60 ;
struct V_25 * V_26 ;
T_1 V_36 ;
int V_29 = 0 ;
V_2 = F_30 ( V_60 , sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_2 -> V_7 = V_7 ;
V_26 = & V_2 -> V_26 ;
V_26 -> V_61 = V_60 ;
F_2 ( V_7 ) ;
V_36 = F_3 ( V_7 , V_37 ) ;
F_6 ( V_7 ) ;
if ( V_36 & ( V_65 |
V_66 ) ) {
if ( ! V_67 )
F_31 ( V_60 ,
L_1 ) ;
V_67 = true ;
}
V_26 -> V_68 = & V_69 ;
V_26 -> V_70 = & V_71 ;
F_32 ( V_26 , V_2 ) ;
F_33 ( V_26 , V_67 ) ;
V_29 = F_27 ( V_26 ) ;
if ( V_29 )
return V_29 ;
F_17 ( V_26 , V_15 ) ;
F_19 ( V_26 , V_32 ) ;
if ( V_36 & V_38 ) {
F_20 ( V_2 ) ;
F_34 ( V_60 , L_2 ) ;
}
F_35 ( V_59 , V_2 ) ;
V_29 = F_36 ( V_26 ) ;
if ( V_29 )
return V_29 ;
F_34 ( V_60 , L_3 , V_26 -> V_15 ) ;
return 0 ;
}
static void F_37 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_38 ( V_59 ) ;
F_22 ( & V_2 -> V_26 ) ;
}
static int F_39 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_38 ( V_59 ) ;
struct V_25 * V_26 = & V_2 -> V_26 ;
int V_29 = 0 ;
if ( ! V_67 )
V_29 = F_22 ( V_26 ) ;
F_40 ( V_26 ) ;
return V_29 ;
}
static int F_41 ( struct V_58 * V_59 ,
T_5 V_72 )
{
struct V_1 * V_2 = F_38 ( V_59 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_25 * V_26 = & V_2 -> V_26 ;
F_2 ( V_7 ) ;
V_2 -> V_73 = F_3 ( V_7 , V_37 ) ;
F_6 ( V_7 ) ;
F_20 ( V_2 ) ;
if ( V_2 -> V_73 & V_38 )
return F_22 ( V_26 ) ;
return 0 ;
}
static int F_42 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_38 ( V_59 ) ;
struct V_25 * V_26 = & V_2 -> V_26 ;
if ( V_2 -> V_73 & V_38 )
return F_21 ( V_26 ) ;
else
return F_22 ( V_26 ) ;
}
