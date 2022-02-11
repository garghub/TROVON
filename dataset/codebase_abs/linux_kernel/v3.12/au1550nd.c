static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = F_2 ( V_4 -> V_7 ) ;
F_3 () ;
return V_6 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_8 , V_4 -> V_9 ) ;
F_3 () ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 = ( T_1 ) F_7 ( F_8 ( V_4 -> V_7 ) ) ;
F_3 () ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_10 ( F_11 ( ( V_10 ) V_8 ) , V_4 -> V_9 ) ;
F_3 () ;
}
static V_10 F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 V_6 = F_8 ( V_4 -> V_7 ) ;
F_3 () ;
return V_6 ;
}
static void F_13 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_5 ( V_11 [ V_13 ] , V_4 -> V_9 ) ;
F_3 () ;
}
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_11 [ V_13 ] = F_2 ( V_4 -> V_7 ) ;
F_3 () ;
}
}
static void F_15 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_14 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_10 ( V_14 [ V_13 ] , V_4 -> V_9 ) ;
F_3 () ;
}
}
static void F_16 ( struct V_1 * V_2 , T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_14 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_14 [ V_13 ] = F_8 ( V_4 -> V_7 ) ;
F_3 () ;
}
}
static void F_17 ( struct V_1 * V_2 , int V_15 )
{
struct V_16 * V_17 = F_18 ( V_2 , struct V_16 , V_18 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_15 ) {
case V_19 :
V_4 -> V_9 = V_17 -> V_20 + V_21 ;
break;
case V_22 :
V_4 -> V_9 = V_17 -> V_20 + V_23 ;
break;
case V_24 :
V_4 -> V_9 = V_17 -> V_20 + V_25 ;
break;
case V_26 :
V_4 -> V_9 = V_17 -> V_20 + V_23 ;
F_19 ( 1 ) ;
break;
case V_27 :
F_20 ( ( 1 << ( 4 + V_17 -> V_28 ) ) , V_29 ) ;
break;
case V_30 :
F_20 ( 0 , V_29 ) ;
break;
}
V_4 -> V_7 = V_4 -> V_9 ;
F_3 () ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_6 = ( F_22 ( V_31 ) & 0x1 ) ? 1 : 0 ;
F_3 () ;
return V_6 ;
}
static void F_23 ( struct V_1 * V_2 , int V_32 )
{
}
static void F_24 ( struct V_1 * V_2 , unsigned V_33 , int V_34 , int V_35 )
{
struct V_16 * V_17 = F_18 ( V_2 , struct V_16 , V_18 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_36 = 0 , V_13 ;
unsigned long V_37 = 0 ;
F_17 ( V_2 , V_19 ) ;
if ( V_33 == V_38 ) {
int V_39 ;
if ( V_34 >= V_2 -> V_40 ) {
V_34 -= V_2 -> V_40 ;
V_39 = V_41 ;
} else if ( V_34 < 256 ) {
V_39 = V_42 ;
} else {
V_34 -= 256 ;
V_39 = V_43 ;
}
V_17 -> V_44 ( V_2 , V_39 ) ;
}
V_17 -> V_44 ( V_2 , V_33 ) ;
F_17 ( V_2 , V_22 ) ;
if ( V_34 != - 1 || V_35 != - 1 ) {
F_17 ( V_2 , V_24 ) ;
if ( V_34 != - 1 ) {
if ( V_4 -> V_45 & V_46 )
V_34 >>= 1 ;
V_17 -> V_44 ( V_2 , V_34 ) ;
}
if ( V_35 != - 1 ) {
V_17 -> V_44 ( V_2 , ( V_47 ) ( V_35 & 0xff ) ) ;
if ( V_33 == V_42 ||
V_33 == V_43 ||
V_33 == V_41 ) {
V_36 = 1 ;
F_25 ( V_37 ) ;
F_17 ( V_2 , V_27 ) ;
}
V_17 -> V_44 ( V_2 , ( V_47 ) ( V_35 >> 8 ) ) ;
if ( V_4 -> V_48 > ( 32 << 20 ) )
V_17 -> V_44 ( V_2 ,
( ( V_35 >> 16 ) & 0x0f ) ) ;
}
F_17 ( V_2 , V_26 ) ;
}
switch ( V_33 ) {
case V_49 :
case V_50 :
case V_51 :
case V_38 :
case V_52 :
return;
case V_53 :
break;
case V_42 :
case V_43 :
case V_41 :
if ( F_26 ( ! V_36 ) )
break;
F_27 ( 100 ) ;
for ( V_13 = V_4 -> V_54 ; ! V_4 -> V_55 ( V_2 ) && V_13 > 0 ; -- V_13 )
F_19 ( 1 ) ;
F_17 ( V_2 , V_30 ) ;
F_28 ( V_37 ) ;
return;
}
F_27 ( 100 ) ;
while( ! V_4 -> V_55 ( V_2 ) ) ;
}
static int F_29 ( unsigned long V_56 )
{
void T_2 * V_20 =
( void T_2 * ) F_30 ( V_57 ) ;
unsigned long V_58 , V_59 , V_60 , V_61 , V_62 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_58 = 0x1000 + ( V_13 * 0x10 ) ;
V_59 = F_31 ( V_20 + V_58 + 0x08 ) ;
V_60 = ( V_59 << 4 ) & 0xfffc0000 ;
V_61 = ( V_59 << 18 ) & 0xfffc0000 ;
V_62 = ( V_60 | ( V_60 - 1 ) ) & ~ ( V_60 ^ V_61 ) ;
if ( ( V_56 >= V_60 ) && ( V_56 < V_62 ) )
return V_13 ;
}
return - V_63 ;
}
static int F_32 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
struct V_16 * V_17 ;
struct V_3 * V_4 ;
struct V_68 * V_69 ;
int V_6 , V_28 ;
V_67 = F_33 ( & V_65 -> V_70 ) ;
if ( ! V_67 ) {
F_34 ( & V_65 -> V_70 , L_1 ) ;
return - V_63 ;
}
V_17 = F_35 ( sizeof( * V_17 ) , V_71 ) ;
if ( ! V_17 ) {
F_34 ( & V_65 -> V_70 , L_2 ) ;
return - V_72 ;
}
V_69 = F_36 ( V_65 , V_73 , 0 ) ;
if ( ! V_69 ) {
F_34 ( & V_65 -> V_70 , L_3 ) ;
V_6 = - V_63 ;
goto V_74;
}
if ( F_37 ( V_69 -> V_60 , F_38 ( V_69 ) , L_4 ) ) {
F_34 ( & V_65 -> V_70 , L_5 ) ;
V_6 = - V_72 ;
goto V_74;
}
V_17 -> V_20 = F_39 ( V_69 -> V_60 , 0x1000 ) ;
if ( ! V_17 -> V_20 ) {
F_34 ( & V_65 -> V_70 , L_6 ) ;
V_6 = - V_63 ;
goto V_75;
}
V_4 = & V_17 -> V_32 ;
V_17 -> V_18 . V_5 = V_4 ;
V_17 -> V_18 . V_76 = V_77 ;
V_28 = F_29 ( V_69 -> V_60 ) ;
if ( V_28 < 0 ) {
F_34 ( & V_65 -> V_70 , L_7 ) ;
V_6 = - V_63 ;
goto V_78;
}
V_17 -> V_28 = V_28 ;
V_4 -> V_55 = F_21 ;
V_4 -> V_79 = F_23 ;
V_4 -> V_80 = F_24 ;
V_4 -> V_54 = 30 ;
V_4 -> V_81 . V_82 = V_83 ;
if ( V_67 -> V_84 )
V_4 -> V_45 |= V_46 ;
V_4 -> V_85 = ( V_67 -> V_84 ) ? F_6 : F_1 ;
V_17 -> V_44 = ( V_67 -> V_84 ) ? F_9 : F_4 ;
V_4 -> V_86 = F_12 ;
V_4 -> V_87 = ( V_67 -> V_84 ) ? F_15 : F_13 ;
V_4 -> V_88 = ( V_67 -> V_84 ) ? F_16 : F_14 ;
V_6 = F_40 ( & V_17 -> V_18 , 1 ) ;
if ( V_6 ) {
F_34 ( & V_65 -> V_70 , L_8 , V_6 ) ;
goto V_78;
}
F_41 ( & V_17 -> V_18 , V_67 -> V_89 , V_67 -> V_90 ) ;
return 0 ;
V_78:
F_42 ( V_17 -> V_20 ) ;
V_75:
F_43 ( V_69 -> V_60 , F_38 ( V_69 ) ) ;
V_74:
F_44 ( V_17 ) ;
return V_6 ;
}
static int F_45 ( struct V_64 * V_65 )
{
struct V_16 * V_17 = F_46 ( V_65 ) ;
struct V_68 * V_69 = F_36 ( V_65 , V_73 , 0 ) ;
F_47 ( & V_17 -> V_18 ) ;
F_42 ( V_17 -> V_20 ) ;
F_43 ( V_69 -> V_60 , 0x1000 ) ;
F_44 ( V_17 ) ;
return 0 ;
}
