static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_3 > V_6 )
return 0 ;
switch ( V_3 ) {
case V_7 :
V_2 -> V_8 = F_2 ( V_5 ,
V_9 ) ;
if ( V_2 -> V_8 < 0 )
return V_2 -> V_8 ;
V_2 -> V_8 = ( V_2 -> V_8 &
V_10 ) >> V_11 ;
return V_2 -> V_8 ;
case V_12 :
V_2 -> V_13 = F_2 ( V_5 ,
V_14 ) ;
if ( V_2 -> V_13 < 0 )
return V_2 -> V_13 ;
V_2 -> V_13 = ( V_2 -> V_13 &
V_10 ) >> V_11 ;
return V_2 -> V_13 ;
case V_15 :
V_2 -> V_16 = F_2 ( V_5 ,
V_17 ) ;
if ( V_2 -> V_16 < 0 )
return V_2 -> V_16 ;
V_2 -> V_16 = ( V_2 -> V_16 &
V_10 ) >> V_11 ;
return V_2 -> V_16 ;
case V_6 :
V_2 -> V_18 = F_2 ( V_5 ,
V_19 ) ;
if ( V_2 -> V_18 < 0 )
return V_2 -> V_18 ;
V_2 -> V_18 = ( V_2 -> V_18 &
V_10 ) >> V_11 ;
return V_2 -> V_18 ;
default:
return 0 ;
}
}
static unsigned long F_3 ( T_1 V_20 )
{
unsigned long V_21 ;
V_21 = ( ( V_20 * 12500 ) + 500000 ) ;
return V_21 ;
}
static unsigned long F_4 ( T_1 V_20 )
{
unsigned long V_21 ;
V_21 = ( ( V_20 * 12500 ) + 700000 ) ;
return V_21 ;
}
static unsigned long F_5 ( T_1 V_20 )
{
unsigned long V_21 ;
V_21 = ( ( V_20 * 25000 ) + 500000 ) ;
return V_21 ;
}
static unsigned long F_6 ( T_1 V_20 )
{
unsigned long V_21 ;
if ( V_20 == 0x3f )
V_21 = 3800000 ;
else
V_21 = ( ( V_20 * 50000 ) + 500000 ) ;
return V_21 ;
}
static unsigned long F_7 ( T_1 V_20 )
{
unsigned long V_21 = 0 ;
if ( V_20 <= 32 )
V_21 = ( ( V_20 * 25000 ) + 800000 ) ;
else if ( V_20 > 32 && V_20 <= 60 )
V_21 = ( ( ( V_20 - 32 ) * 50000 ) + 1600000 ) ;
else if ( V_20 > 60 )
V_21 = ( ( ( V_20 - 60 ) * 100000 ) + 3000000 ) ;
return V_21 ;
}
static int F_8 ( int V_3 )
{
switch ( V_3 ) {
case V_7 :
return V_22 ;
case V_12 :
return V_23 ;
case V_15 :
return V_24 ;
case V_6 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
case V_44 :
return V_45 ;
default:
return - V_46 ;
}
}
static int F_9 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_47 = 0 , V_48 = 0 ;
T_1 V_49 = 0 ;
if ( V_3 < V_7 || V_3 > V_6 )
return - V_46 ;
switch ( V_3 ) {
case V_7 :
V_47 = F_2 ( V_5 , V_50 ) ;
V_48 = ( ( V_47 & V_51 ) >> V_52 ) ;
if ( V_48 )
V_49 = V_22 ;
else
V_49 = V_50 ;
break;
case V_12 :
V_47 = F_2 ( V_5 , V_53 ) ;
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_49 = V_23 ;
else
V_49 = V_53 ;
break;
case V_15 :
V_47 = F_2 ( V_5 , V_54 ) ;
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_49 = V_24 ;
else
V_49 = V_54 ;
break;
case V_6 :
V_47 = F_2 ( V_5 , V_55 ) ;
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_49 = V_25 ;
else
V_49 = V_55 ;
break;
}
return V_49 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_47 = 0 , V_48 = 0 ;
T_1 V_49 = 0 ;
if ( V_3 < V_26 || V_3 > V_44 )
return - V_46 ;
switch ( V_3 ) {
case V_26 :
V_47 = F_2 ( V_5 , V_56 ) ;
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_49 = V_27 ;
else
V_49 = V_56 ;
break;
case V_28 :
V_47 = F_2 ( V_5 , V_57 ) ;
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_49 = V_29 ;
else
V_49 = V_57 ;
break;
case V_30 :
V_47 = F_2 ( V_5 , V_58 ) ;
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_49 = V_31 ;
else
V_49 = V_58 ;
break;
case V_32 :
V_47 = F_2 ( V_5 , V_59 ) ;
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_49 = V_33 ;
else
V_49 = V_59 ;
break;
case V_34 :
V_49 = V_35 ;
break;
case V_36 :
V_49 = V_37 ;
break;
case V_38 :
V_49 = V_39 ;
break;
case V_40 :
V_49 = V_41 ;
break;
case V_42 :
V_49 = V_43 ;
break;
case V_44 :
V_49 = V_45 ;
break;
}
return V_49 ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_7 :
V_2 -> V_60 = V_61 ;
V_2 -> V_62 = V_22 ;
break;
case V_12 :
V_2 -> V_60 = V_63 ;
V_2 -> V_62 = V_23 ;
break;
case V_15 :
V_2 -> V_60 = V_64 ;
V_2 -> V_62 = V_24 ;
break;
case V_6 :
V_2 -> V_60 = V_65 ;
V_2 -> V_62 = V_25 ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_12 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_49 , V_68 , V_3 = F_14 ( V_67 ) ;
if ( V_3 < V_7 || V_3 > V_44 )
return - V_46 ;
V_49 = V_2 -> V_69 ( V_3 ) ;
if ( V_49 < 0 )
return V_49 ;
V_68 = F_2 ( V_5 , V_49 ) ;
if ( V_68 < 0 )
return V_68 ;
return V_68 & V_70 ;
}
static int F_15 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_14 ( V_67 ) ;
int V_49 ;
if ( V_3 < V_7 || V_3 > V_44 )
return - V_46 ;
V_49 = V_2 -> V_69 ( V_3 ) ;
if ( V_49 < 0 )
return V_49 ;
return F_16 ( V_5 , V_49 , V_70 ) ;
}
static int F_17 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_14 ( V_67 ) , V_49 ;
V_49 = V_2 -> V_69 ( V_3 ) ;
if ( V_49 < 0 )
return V_49 ;
return F_18 ( V_5 , V_49 , V_70 ) ;
}
static int F_19 ( struct V_66 * V_67 , unsigned int V_71 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_72 , V_73 , V_3 = F_14 ( V_67 ) ;
F_11 ( V_2 , V_3 ) ;
V_72 = F_2 ( V_5 , V_2 -> V_60 ) ;
V_73 = F_2 ( V_5 , V_2 -> V_62 ) ;
V_72 &= V_74 ;
V_73 &= V_75 ;
switch ( V_71 ) {
case V_76 :
if ( V_72 && ! V_73 )
break;
F_16 ( V_5 , V_2 -> V_60 , V_74 ) ;
F_18 ( V_5 , V_2 -> V_62 , V_75 ) ;
break;
case V_77 :
case V_78 :
if ( ! V_72 && ! V_73 )
break;
F_18 ( V_5 , V_2 -> V_60 , V_74 ) ;
F_18 ( V_5 , V_2 -> V_62 , V_75 ) ;
break;
case V_79 :
if ( ! V_72 && V_73 )
break;
F_18 ( V_5 , V_2 -> V_60 , V_74 ) ;
F_16 ( V_5 , V_2 -> V_62 , V_75 ) ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static unsigned int F_20 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_72 , V_73 , V_71 = 0 , V_3 = F_14 ( V_67 ) ;
F_11 ( V_2 , V_3 ) ;
V_72 = F_2 ( V_5 , V_2 -> V_60 ) ;
V_73 = F_2 ( V_5 , V_2 -> V_62 ) ;
V_72 &= V_74 ;
V_73 &= V_75 ;
if ( V_72 && ! V_73 )
V_71 = V_76 ;
else if ( ! V_72 && ! V_73 )
V_71 = V_77 ;
else if ( ! V_72 && V_73 )
V_71 = V_79 ;
return V_71 ;
}
static int F_21 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_14 ( V_67 ) , V_80 = 0 , V_81 ;
int V_47 = 0 , V_82 = 0 , V_48 , V_20 ;
switch ( V_3 ) {
case V_7 :
V_47 = F_2 ( V_5 , V_50 ) ;
V_82 = F_2 ( V_5 , V_22 ) ;
V_81 = V_2 -> V_8 ;
break;
case V_12 :
V_47 = F_2 ( V_5 , V_53 ) ;
V_82 = F_2 ( V_5 , V_23 ) ;
V_81 = V_2 -> V_13 ;
break;
case V_15 :
V_47 = F_2 ( V_5 , V_54 ) ;
V_82 = F_2 ( V_5 , V_24 ) ;
V_81 = V_2 -> V_16 ;
break;
case V_6 :
V_47 = F_2 ( V_5 , V_55 ) ;
V_82 = F_2 ( V_5 , V_25 ) ;
V_81 = V_2 -> V_18 ;
break;
default:
return - V_46 ;
}
V_48 = ( V_47 & V_51 ) >> V_52 ;
if ( V_48 )
V_20 = V_82 ;
else
V_20 = V_47 ;
V_20 &= 0x3F ;
switch ( V_81 ) {
case 0 :
V_80 = F_3 ( V_20 ) ;
break;
case 1 :
V_80 = F_4 ( V_20 ) ;
break;
case 2 :
V_80 = F_5 ( V_20 ) ;
break;
case 3 :
V_80 = F_6 ( V_20 ) ;
break;
}
return V_80 ;
}
static int F_22 ( struct V_66 * V_67 ,
unsigned V_83 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_14 ( V_67 ) ;
int V_68 ;
T_1 V_49 ;
V_49 = F_9 ( V_2 , V_3 ) ;
V_68 = F_2 ( V_5 , V_49 ) ;
V_68 &= 0xC0 ;
return F_23 ( V_5 , V_49 , V_83 | V_68 ) ;
}
static int F_24 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_14 ( V_67 ) ;
int V_20 = 0 ;
T_1 V_49 ;
V_49 = F_10 ( V_2 , V_3 ) ;
V_20 = F_2 ( V_5 , V_49 ) ;
V_20 &= 0x3F ;
return F_7 ( V_20 ) ;
}
static int F_25 ( struct V_66 * V_67 ,
unsigned V_83 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = F_14 ( V_67 ) , V_49 , V_68 ;
V_49 = F_10 ( V_2 , V_3 ) ;
V_68 = F_2 ( V_5 , V_49 ) ;
V_68 &= 0xC0 ;
return F_23 ( V_5 , V_49 , V_83 | V_68 ) ;
}
static int F_26 ( struct V_66 * V_67 ,
unsigned V_83 )
{
struct V_1 * V_2 = F_13 ( V_67 ) ;
int V_81 , V_80 = 0 , V_3 = F_14 ( V_67 ) ;
switch ( V_3 ) {
case V_7 :
V_81 = V_2 -> V_8 ;
break;
case V_12 :
V_81 = V_2 -> V_13 ;
break;
case V_15 :
V_81 = V_2 -> V_16 ;
break;
case V_6 :
V_81 = V_2 -> V_18 ;
break;
default:
return - V_46 ;
}
switch ( V_81 ) {
case 0 :
V_80 = F_3 ( V_83 ) ;
break;
case 1 :
V_80 = F_4 ( V_83 ) ;
break;
case 2 :
V_80 = F_5 ( V_83 ) ;
break;
case 3 :
V_80 = F_6 ( V_83 ) ;
break;
}
return V_80 ;
}
static int F_27 ( struct V_66 * V_67 ,
unsigned V_83 )
{
int V_84 = F_14 ( V_67 ) ;
if ( V_84 < V_26 || V_84 > V_44 )
return - V_46 ;
return F_7 ( V_83 ) ;
}
static T_2 int F_28 ( struct V_85 * V_86 )
{
struct V_4 * V_4 = F_29 ( V_86 -> V_67 . V_87 ) ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
struct V_66 * V_92 ;
struct V_1 * V_2 ;
struct V_93 * V_94 ;
int V_95 , V_96 ;
V_94 = F_30 ( V_4 -> V_67 ) ;
if ( ! V_94 )
return - V_46 ;
V_91 = V_94 -> V_97 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
F_32 ( & V_2 -> V_100 ) ;
V_2 -> V_5 = V_4 ;
F_33 ( V_86 , V_2 ) ;
V_2 -> V_69 = & F_8 ;
V_89 = V_101 ;
for ( V_95 = 0 ; V_95 < V_102 ; V_95 ++ , V_89 ++ , V_91 ++ ) {
int V_81 = 0 ;
V_2 -> V_89 [ V_95 ] = V_89 ;
V_2 -> V_103 [ V_95 ] . V_104 = V_89 -> V_104 ;
V_2 -> V_103 [ V_95 ] . V_3 = V_95 ;
V_2 -> V_103 [ V_95 ] . V_105 = 64 ;
V_2 -> V_103 [ V_95 ] . V_106 = ( V_95 > V_6 ?
& V_107 : & V_108 ) ;
V_2 -> V_103 [ V_95 ] . type = V_109 ;
V_2 -> V_103 [ V_95 ] . V_110 = V_111 ;
V_81 = F_1 ( V_2 , V_95 ) ;
V_92 = F_34 ( & V_2 -> V_103 [ V_95 ] ,
V_4 -> V_67 , V_91 , V_2 ) ;
if ( F_35 ( V_92 ) ) {
F_36 ( V_4 -> V_67 ,
L_1 ,
V_86 -> V_104 ) ;
V_96 = F_37 ( V_92 ) ;
goto V_96;
}
V_2 -> V_92 [ V_95 ] = V_92 ;
}
return 0 ;
V_96:
while ( -- V_95 >= 0 )
F_38 ( V_2 -> V_92 [ V_95 ] ) ;
F_39 ( V_2 ) ;
return V_96 ;
}
static int T_3 F_40 ( struct V_85 * V_86 )
{
struct V_1 * V_1 = F_41 ( V_86 ) ;
int V_95 ;
for ( V_95 = 0 ; V_95 < V_102 ; V_95 ++ )
F_38 ( V_1 -> V_92 [ V_95 ] ) ;
F_39 ( V_1 ) ;
return 0 ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_112 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_112 ) ;
}
