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
static int F_15 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_11 [ V_13 ] != F_2 ( V_4 -> V_7 ) )
return - V_14 ;
F_3 () ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_15 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_10 ( V_15 [ V_13 ] , V_4 -> V_9 ) ;
F_3 () ;
}
}
static void F_17 ( struct V_1 * V_2 , T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_15 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_15 [ V_13 ] = F_8 ( V_4 -> V_7 ) ;
F_3 () ;
}
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 * V_15 = ( V_10 * ) V_11 ;
V_12 >>= 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_15 [ V_13 ] != F_8 ( V_4 -> V_7 ) )
return - V_14 ;
F_3 () ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 = F_20 ( V_2 , struct V_17 , V_19 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_16 ) {
case V_20 :
V_4 -> V_9 = V_18 -> V_21 + V_22 ;
break;
case V_23 :
V_4 -> V_9 = V_18 -> V_21 + V_24 ;
break;
case V_25 :
V_4 -> V_9 = V_18 -> V_21 + V_26 ;
break;
case V_27 :
V_4 -> V_9 = V_18 -> V_21 + V_24 ;
F_21 ( 1 ) ;
break;
case V_28 :
F_22 ( ( 1 << ( 4 + V_18 -> V_29 ) ) , V_30 ) ;
break;
case V_31 :
F_22 ( 0 , V_30 ) ;
break;
}
V_4 -> V_7 = V_4 -> V_9 ;
F_3 () ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_6 = ( F_24 ( V_32 ) & 0x1 ) ? 1 : 0 ;
F_3 () ;
return V_6 ;
}
static void F_25 ( struct V_1 * V_2 , int V_33 )
{
}
static void F_26 ( struct V_1 * V_2 , unsigned V_34 , int V_35 , int V_36 )
{
struct V_17 * V_18 = F_20 ( V_2 , struct V_17 , V_19 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_37 = 0 , V_13 ;
unsigned long V_38 = 0 ;
F_19 ( V_2 , V_20 ) ;
if ( V_34 == V_39 ) {
int V_40 ;
if ( V_35 >= V_2 -> V_41 ) {
V_35 -= V_2 -> V_41 ;
V_40 = V_42 ;
} else if ( V_35 < 256 ) {
V_40 = V_43 ;
} else {
V_35 -= 256 ;
V_40 = V_44 ;
}
V_18 -> V_45 ( V_2 , V_40 ) ;
}
V_18 -> V_45 ( V_2 , V_34 ) ;
F_19 ( V_2 , V_23 ) ;
if ( V_35 != - 1 || V_36 != - 1 ) {
F_19 ( V_2 , V_25 ) ;
if ( V_35 != - 1 ) {
if ( V_4 -> V_46 & V_47 )
V_35 >>= 1 ;
V_18 -> V_45 ( V_2 , V_35 ) ;
}
if ( V_36 != - 1 ) {
V_18 -> V_45 ( V_2 , ( V_48 ) ( V_36 & 0xff ) ) ;
if ( V_34 == V_43 ||
V_34 == V_44 ||
V_34 == V_42 ) {
V_37 = 1 ;
F_27 ( V_38 ) ;
F_19 ( V_2 , V_28 ) ;
}
V_18 -> V_45 ( V_2 , ( V_48 ) ( V_36 >> 8 ) ) ;
if ( V_4 -> V_49 > ( 32 << 20 ) )
V_18 -> V_45 ( V_2 ,
( ( V_36 >> 16 ) & 0x0f ) ) ;
}
F_19 ( V_2 , V_27 ) ;
}
switch ( V_34 ) {
case V_50 :
case V_51 :
case V_52 :
case V_39 :
case V_53 :
return;
case V_54 :
break;
case V_43 :
case V_44 :
case V_42 :
if ( F_28 ( ! V_37 ) )
break;
F_29 ( 100 ) ;
for ( V_13 = V_4 -> V_55 ; ! V_4 -> V_56 ( V_2 ) && V_13 > 0 ; -- V_13 )
F_21 ( 1 ) ;
F_19 ( V_2 , V_31 ) ;
F_30 ( V_38 ) ;
return;
}
F_29 ( 100 ) ;
while( ! V_4 -> V_56 ( V_2 ) ) ;
}
static int T_2 F_31 ( unsigned long V_57 )
{
void T_3 * V_21 =
( void T_3 * ) F_32 ( V_58 ) ;
unsigned long V_59 , V_60 , V_61 , V_62 , V_63 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_59 = 0x1000 + ( V_13 * 0x10 ) ;
V_60 = F_33 ( V_21 + V_59 + 0x08 ) ;
V_61 = ( V_60 << 4 ) & 0xfffc0000 ;
V_62 = ( V_60 << 18 ) & 0xfffc0000 ;
V_63 = ( V_61 | ( V_61 - 1 ) ) & ~ ( V_61 ^ V_62 ) ;
if ( ( V_57 >= V_61 ) && ( V_57 < V_63 ) )
return V_13 ;
}
return - V_64 ;
}
static int T_2 F_34 ( struct V_65 * V_66 )
{
struct V_67 * V_68 ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
struct V_69 * V_70 ;
int V_6 , V_29 ;
V_68 = V_66 -> V_71 . V_72 ;
if ( ! V_68 ) {
F_35 ( & V_66 -> V_71 , L_1 ) ;
return - V_64 ;
}
V_18 = F_36 ( sizeof( * V_18 ) , V_73 ) ;
if ( ! V_18 ) {
F_35 ( & V_66 -> V_71 , L_2 ) ;
return - V_74 ;
}
V_70 = F_37 ( V_66 , V_75 , 0 ) ;
if ( ! V_70 ) {
F_35 ( & V_66 -> V_71 , L_3 ) ;
V_6 = - V_64 ;
goto V_76;
}
if ( F_38 ( V_70 -> V_61 , F_39 ( V_70 ) , L_4 ) ) {
F_35 ( & V_66 -> V_71 , L_5 ) ;
V_6 = - V_74 ;
goto V_76;
}
V_18 -> V_21 = F_40 ( V_70 -> V_61 , 0x1000 ) ;
if ( ! V_18 -> V_21 ) {
F_35 ( & V_66 -> V_71 , L_6 ) ;
V_6 = - V_64 ;
goto V_77;
}
V_4 = & V_18 -> V_33 ;
V_18 -> V_19 . V_5 = V_4 ;
V_18 -> V_19 . V_78 = V_79 ;
V_29 = F_31 ( V_70 -> V_61 ) ;
if ( V_29 < 0 ) {
F_35 ( & V_66 -> V_71 , L_7 ) ;
V_6 = - V_64 ;
goto V_80;
}
V_18 -> V_29 = V_29 ;
V_4 -> V_56 = F_23 ;
V_4 -> V_81 = F_25 ;
V_4 -> V_82 = F_26 ;
V_4 -> V_55 = 30 ;
V_4 -> V_83 . V_84 = V_85 ;
if ( V_68 -> V_86 )
V_4 -> V_46 |= V_47 ;
V_4 -> V_87 = ( V_68 -> V_86 ) ? F_6 : F_1 ;
V_18 -> V_45 = ( V_68 -> V_86 ) ? F_9 : F_4 ;
V_4 -> V_88 = F_12 ;
V_4 -> V_89 = ( V_68 -> V_86 ) ? F_16 : F_13 ;
V_4 -> V_90 = ( V_68 -> V_86 ) ? F_17 : F_14 ;
V_4 -> V_91 = ( V_68 -> V_86 ) ? F_18 : F_15 ;
V_6 = F_41 ( & V_18 -> V_19 , 1 ) ;
if ( V_6 ) {
F_35 ( & V_66 -> V_71 , L_8 , V_6 ) ;
goto V_80;
}
F_42 ( & V_18 -> V_19 , V_68 -> V_92 , V_68 -> V_93 ) ;
return 0 ;
V_80:
F_43 ( V_18 -> V_21 ) ;
V_77:
F_44 ( V_70 -> V_61 , F_39 ( V_70 ) ) ;
V_76:
F_45 ( V_18 ) ;
return V_6 ;
}
static int T_4 F_46 ( struct V_65 * V_66 )
{
struct V_17 * V_18 = F_47 ( V_66 ) ;
struct V_69 * V_70 = F_37 ( V_66 , V_75 , 0 ) ;
F_48 ( & V_18 -> V_19 ) ;
F_43 ( V_18 -> V_21 ) ;
F_44 ( V_70 -> V_61 , 0x1000 ) ;
F_45 ( V_18 ) ;
return 0 ;
}
