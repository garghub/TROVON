int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 , L_1 ,
- V_5 ) ;
goto V_7;
}
V_5 = F_4 ( V_2 , V_8 ) ;
if ( V_5 ) {
F_5 ( V_2 , L_2 , - V_5 ) ;
goto V_9;
}
V_5 = F_6 ( V_2 , F_7 ( 64 ) ) ;
if ( V_5 ) {
V_5 = F_6 ( V_2 , F_7 ( 32 ) ) ;
if ( V_5 ) {
F_5 ( V_2 , L_3 , V_5 ) ;
goto V_9;
}
V_5 = F_8 ( V_2 , F_7 ( 32 ) ) ;
} else
V_5 = F_8 ( V_2 , F_7 ( 64 ) ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 ,
L_4 , V_5 ) ;
goto V_9;
}
F_9 ( V_2 ) ;
V_5 = F_10 ( V_2 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_6 ,
L_5 ,
V_5 ) ;
V_5 = 0 ;
}
goto V_7;
V_9:
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_7:
return V_5 ;
}
int F_13 ( struct V_10 * V_11 , struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned long V_12 ;
T_1 V_13 ;
V_11 -> V_14 = V_2 ;
F_14 ( V_2 , V_11 ) ;
V_13 = F_15 ( V_2 , 0 ) ;
V_12 = F_16 ( V_2 , 0 ) ;
V_11 -> V_15 = F_17 ( V_13 , V_12 ) ;
if ( ! V_11 -> V_15 )
return - V_16 ;
V_11 -> V_17 = ( V_18 V_19 * ) ( ( void V_19 * ) V_11 -> V_15 + V_12 ) ;
V_11 -> V_20 = V_13 ;
V_11 -> V_21 = V_13 ;
V_11 -> V_22 = V_13 >> 32 ;
V_11 -> V_23 = V_4 -> V_24 ;
V_11 -> V_25 = V_4 -> V_26 ;
return 0 ;
}
void F_18 ( struct V_10 * V_11 )
{
V_18 V_19 * V_27 = ( void V_19 * ) V_11 -> V_15 ;
V_11 -> V_15 = NULL ;
F_19 ( V_27 ) ;
if ( V_11 -> V_28 )
F_19 ( V_11 -> V_28 ) ;
if ( V_11 -> V_29 )
F_19 ( V_11 -> V_29 ) ;
if ( V_11 -> V_30 )
F_19 ( V_11 -> V_30 ) ;
F_11 ( V_11 -> V_14 ) ;
F_12 ( V_11 -> V_14 ) ;
F_14 ( V_11 -> V_14 , NULL ) ;
}
static void F_20 ( struct V_10 * V_11 , int V_31 , T_2 * V_32 ,
struct V_33 * V_33 )
{
int V_5 ;
int V_34 = * V_32 ;
struct V_35 * V_35 ;
int V_36 ;
V_5 = F_21 ( V_11 -> V_14 ) ;
if ( V_5 < 0 )
goto V_37;
V_34 = F_22 ( V_34 , V_5 ) ;
V_35 = F_23 ( V_34 , sizeof( * V_35 ) , V_38 ) ;
if ( ! V_35 )
goto V_37;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ )
V_35 [ V_36 ] = V_33 [ V_36 ] . V_39 ;
V_5 = F_24 ( V_11 -> V_14 , V_35 , 1 , V_34 ) ;
if ( V_5 < 0 )
goto V_40;
else
V_34 = V_5 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ )
V_33 [ V_36 ] . V_39 = V_35 [ V_36 ] ;
F_25 ( V_35 ) ;
* V_32 = V_34 ;
return;
V_40:
F_25 ( V_35 ) ;
V_37:
F_26 (
V_11 ,
L_6 ,
V_34 , V_5 ) ;
* V_32 = 0 ;
F_27 ( V_11 -> V_14 ) ;
}
static int F_28 ( struct V_10 * V_11 , int V_31 )
{
struct V_1 * V_2 = V_11 -> V_14 ;
T_3 V_41 ;
int V_5 ;
V_5 = F_29 ( V_2 ) ;
if ( V_5 )
F_26 ( V_11 ,
L_7 ,
V_5 ) ;
F_30 ( V_2 , V_31 + V_42 ,
& V_11 -> V_43 ) ;
F_30 ( V_2 , V_31 + V_44 ,
& V_11 -> V_45 ) ;
F_31 ( V_2 , V_31 + V_46 , & V_41 ) ;
F_31 ( V_2 , V_31 + ( ( V_41 & V_47 )
? 12 : 8 ) ,
& V_11 -> V_48 ) ;
return V_5 ;
}
int F_32 ( struct V_10 * V_11 , T_2 V_49 , T_2 * V_50 ,
struct V_33 * V_51 )
{
T_3 V_52 , V_53 ;
int V_31 = 0 , V_5 = 1 ;
if ( ! F_33 ( V_11 -> V_14 ) ) {
F_26 ( V_11 , L_8 ) ;
V_11 -> V_54 = 1 ;
V_11 -> V_55 = 2500 ;
goto V_9;
}
V_31 = V_11 -> V_14 -> V_56 ;
if ( V_50 && * V_50 && V_31 ) {
F_20 ( V_11 , V_31 , V_50 , V_51 ) ;
V_5 = 0 ;
} else {
V_31 = V_11 -> V_14 -> V_57 ;
if ( V_31 )
V_5 = F_28 ( V_11 , V_31 ) ;
else
F_26 ( V_11 , L_9 ) ;
}
if ( ! V_31 )
F_27 ( V_11 -> V_14 ) ;
F_34 ( V_11 -> V_14 , V_58 , & V_52 ) ;
V_53 = V_52 & 0xf ;
V_52 >>= 4 ;
V_52 &= 0x1f ;
V_11 -> V_54 = V_52 ;
switch ( V_53 ) {
case 1 :
V_11 -> V_55 = 2500 ;
break;
case 2 :
V_11 -> V_55 = 5000 ;
break;
default:
V_11 -> V_55 = 2500 ;
break;
}
if ( V_49 && V_52 < V_49 )
F_26 ( V_11 ,
L_10 ,
V_52 , V_49 ) ;
F_35 ( V_11 ) ;
F_36 ( V_11 ) ;
V_9:
snprintf ( V_11 -> V_59 , sizeof( V_11 -> V_59 ) ,
L_11 , V_11 -> V_55 , V_11 -> V_54 ) ;
return V_5 ;
}
int F_37 ( struct V_10 * V_11 )
{
int V_31 ;
T_3 V_41 ;
int V_5 = 0 ;
if ( ! V_11 -> V_43 )
goto V_9;
V_31 = V_11 -> V_14 -> V_57 ;
if ( ! V_31 ) {
F_26 ( V_11 ,
L_12 ) ;
V_5 = 0 ;
goto V_9;
}
F_38 ( V_11 -> V_14 , V_31 + V_42 ,
V_11 -> V_43 ) ;
F_38 ( V_11 -> V_14 , V_31 + V_44 ,
V_11 -> V_45 ) ;
F_31 ( V_11 -> V_14 , V_31 + V_46 , & V_41 ) ;
if ( ! ( V_41 & V_60 ) ) {
V_41 |= V_60 ;
F_39 ( V_11 -> V_14 , V_31 + V_46 ,
V_41 ) ;
}
F_39 ( V_11 -> V_14 , V_31 +
( ( V_41 & V_47 ) ? 12 : 8 ) ,
V_11 -> V_48 ) ;
V_5 = 1 ;
V_9:
if ( ! V_5 && ( V_11 -> V_61 & V_62 ) ) {
F_27 ( V_11 -> V_14 ) ;
V_5 = 1 ;
}
F_9 ( V_11 -> V_14 ) ;
return V_5 ;
}
void F_40 ( struct V_10 * V_11 )
{
V_11 -> V_43 = 0 ;
F_41 ( V_11 -> V_14 ) ;
}
void F_42 ( struct V_10 * V_11 )
{
F_43 ( V_11 -> V_14 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
T_3 V_63 , V_64 ;
int V_31 ;
F_31 ( V_2 , V_65 , & V_63 ) ;
V_64 = V_63 & ~ V_66 ;
if ( V_64 != V_63 )
F_39 ( V_2 , V_65 , V_64 ) ;
V_31 = V_2 -> V_57 ;
if ( V_31 ) {
F_31 ( V_2 , V_31 + V_46 , & V_63 ) ;
V_64 = V_63 & ~ V_60 ;
if ( V_64 != V_63 )
F_39 ( V_2 , V_31 + V_46 , V_64 ) ;
}
V_31 = V_2 -> V_56 ;
if ( V_31 ) {
F_31 ( V_2 , V_31 + V_67 , & V_63 ) ;
V_64 = V_63 & ~ V_68 ;
if ( V_64 != V_63 )
F_39 ( V_2 , V_31 + V_67 , V_64 ) ;
}
}
void F_44 ( struct V_10 * V_11 , T_3 * V_69 , T_4 * V_70 , T_4 * V_71 )
{
F_31 ( V_11 -> V_14 , V_65 , V_69 ) ;
F_45 ( V_11 -> V_14 , V_72 , V_70 ) ;
F_45 ( V_11 -> V_14 , V_73 , V_71 ) ;
}
void F_46 ( struct V_10 * V_11 , T_3 V_69 , T_4 V_70 , T_4 V_71 )
{
int V_74 ;
V_74 = F_38 ( V_11 -> V_14 , V_75 ,
V_11 -> V_21 ) ;
if ( V_74 )
F_26 ( V_11 , L_13 , V_74 ) ;
V_74 = F_38 ( V_11 -> V_14 , V_76 ,
V_11 -> V_22 ) ;
if ( V_74 )
F_26 ( V_11 , L_14 , V_74 ) ;
F_39 ( V_11 -> V_14 , V_65 , V_69 ) ;
F_47 ( V_11 -> V_14 , V_72 , V_70 ) ;
F_47 ( V_11 -> V_14 , V_73 , V_71 ) ;
V_74 = F_2 ( V_11 -> V_14 ) ;
if ( V_74 )
F_26 ( V_11 ,
L_15 , V_74 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
int V_74 ;
struct V_1 * V_77 ;
T_3 V_78 ;
T_2 V_79 , V_80 , V_81 ;
if ( ! V_82 )
return;
V_77 = V_11 -> V_14 -> V_83 -> V_84 ;
if ( V_77 -> V_83 -> V_77 ) {
F_5 ( V_11 -> V_14 , L_16 ) ;
return;
}
if ( ! F_33 ( V_77 ) )
return;
if ( V_77 -> V_26 != 0x8086 )
return;
V_78 = V_77 -> V_24 ;
if ( V_78 >= 0x25e2 && V_78 <= 0x25fa ) {
if ( V_77 -> V_85 <= 0xb2 )
V_80 = 1U << 10 ;
else
V_80 = 7U << 10 ;
V_79 = ( 3U << 24 ) | ( 7U << 10 ) ;
} else if ( V_78 >= 0x65e2 && V_78 <= 0x65fa ) {
V_80 = 1U << 10 ;
V_79 = ( 3U << 24 ) | ( 7U << 10 ) ;
} else if ( V_78 >= 0x4021 && V_78 <= 0x402e ) {
V_80 = 7U << 10 ;
V_79 = 7U << 10 ;
} else if ( V_78 >= 0x3604 && V_78 <= 0x360a ) {
V_80 = 7U << 10 ;
V_79 = ( 3U << 24 ) | ( 7U << 10 ) ;
} else {
return;
}
F_30 ( V_77 , 0x48 , & V_81 ) ;
V_81 &= ~ V_79 ;
V_81 |= V_80 ;
V_74 = F_38 ( V_77 , 0x48 , V_81 ) ;
}
static void F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_77 ;
T_3 V_86 , V_87 , V_88 , V_89 ;
T_3 V_90 , V_91 , V_92 ;
V_77 = V_11 -> V_14 -> V_83 -> V_84 ;
if ( ! F_48 ( V_77 -> V_83 ) ) {
F_5 ( V_11 -> V_14 , L_16 ) ;
return;
}
if ( ! F_33 ( V_77 ) || ! F_33 ( V_11 -> V_14 ) )
return;
V_86 = V_77 -> V_93 ;
V_87 = F_49 ( F_50 ( V_77 ) ) - 8 ;
V_88 = V_11 -> V_14 -> V_93 ;
V_89 = F_49 ( F_50 ( V_11 -> V_14 ) ) - 8 ;
if ( V_86 > V_88 )
V_86 = V_88 ;
if ( V_86 > ( V_94 & 7 ) )
V_86 = V_94 & 7 ;
if ( V_86 > V_87 ) {
V_87 = V_86 ;
F_51 ( V_77 , 128 << V_87 ) ;
}
if ( V_86 > V_89 ) {
V_89 = V_86 ;
F_51 ( V_11 -> V_14 , 128 << V_89 ) ;
}
V_92 = 5 ;
if ( V_92 > ( ( V_94 >> 4 ) & 7 ) )
V_92 = ( V_94 >> 4 ) & 7 ;
V_92 = 128 << V_92 ;
V_90 = F_52 ( V_77 ) ;
V_91 = F_52 ( V_11 -> V_14 ) ;
if ( V_92 > V_90 ) {
V_90 = V_92 ;
F_53 ( V_77 , V_90 ) ;
}
if ( V_92 > V_91 ) {
V_91 = V_92 ;
F_53 ( V_11 -> V_14 , V_91 ) ;
}
}
static T_5
F_54 ( struct V_1 * V_2 , T_6 V_95 )
{
struct V_10 * V_11 = F_55 ( V_2 ) ;
T_5 V_5 = V_96 ;
switch ( V_95 ) {
case V_97 :
F_5 ( V_2 , L_17 ) ;
break;
case V_98 :
F_5 ( V_2 , L_18 ) ;
F_11 ( V_2 ) ;
V_5 = V_99 ;
break;
case V_100 :
F_5 ( V_2 , L_19 ) ;
if ( V_11 ) {
V_11 -> V_61 &= ~ V_101 ;
F_56 ( V_11 ) ;
}
V_5 = V_102 ;
break;
default:
F_5 ( V_2 , L_20 ,
V_95 ) ;
break;
}
return V_5 ;
}
static T_5
F_57 ( struct V_1 * V_2 )
{
V_18 V_103 = 0U ;
struct V_10 * V_11 = F_55 ( V_2 ) ;
T_5 V_5 = V_96 ;
if ( V_11 && V_11 -> V_104 ) {
V_103 = V_11 -> V_105 ( V_11 -> V_104 , V_106 ) ;
if ( V_103 == ~ 0ULL )
V_5 = V_99 ;
}
F_5 ( V_2 ,
L_21 ,
V_103 , V_5 ) ;
return V_5 ;
}
static T_5
F_58 ( struct V_1 * V_2 )
{
F_5 ( V_2 , L_22 ) ;
return V_107 ;
}
static void
F_59 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_55 ( V_2 ) ;
F_5 ( V_2 , L_23 ) ;
F_60 ( V_2 ) ;
F_61 ( V_11 , 1 ) ;
}
