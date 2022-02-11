static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
if ( V_3 ) {
V_5 = F_2 ( V_2 -> V_6 . V_7 , L_1 ) ;
if ( F_3 ( V_5 ) ) {
F_4 ( V_2 -> V_6 . V_7 , L_2 ) ;
return F_5 ( V_5 ) ;
}
V_4 = F_6 ( V_5 ,
V_8 ,
V_9 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_6 . V_7 , L_3
L_4 ) ;
F_7 ( V_5 ) ;
return V_4 ;
}
V_4 = F_8 ( V_5 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_6 . V_7 , L_5 ) ;
F_7 ( V_5 ) ;
}
} else {
V_4 = F_6 ( V_5 , 0 ,
V_9 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 . V_7 , L_3
L_4 ) ;
V_4 = F_9 ( V_5 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 . V_7 , L_6 ) ;
F_7 ( V_5 ) ;
}
return V_4 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 )
{
int V_10 = 0 ;
if ( V_3 ) {
V_11 = F_2 ( V_2 -> V_6 . V_7 , L_7 ) ;
if ( F_3 ( V_11 ) ) {
F_4 ( V_2 -> V_6 . V_7 , L_8 ) ;
return F_5 ( V_11 ) ;
}
V_10 = F_6 ( V_11 , V_12 ,
V_13 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 . V_7 , L_9
L_10 ) ;
goto V_14;
}
V_10 = F_8 ( V_11 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 . V_7 , L_11 ) ;
goto V_14;
}
V_15 = F_2 ( V_2 -> V_6 . V_7 , L_12 ) ;
if ( F_3 ( V_15 ) ) {
F_4 ( V_2 -> V_6 . V_7 , L_13 ) ;
V_10 = F_5 ( V_15 ) ;
goto V_16;
}
V_10 = F_6 ( V_15 , V_17 ,
V_18 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 . V_7 , L_9
L_14 ) ;
goto V_19;
}
V_10 = F_8 ( V_15 ) ;
if ( V_10 ) {
F_4 ( V_2 -> V_6 . V_7 , L_15 ) ;
goto V_19;
}
return 0 ;
}
F_9 ( V_15 ) ;
V_19:
F_7 ( V_15 ) ;
V_16:
F_9 ( V_11 ) ;
V_14:
F_7 ( V_11 ) ;
return V_10 ;
}
static int F_11 ( int V_20 )
{
int V_21 = V_9 ;
int V_22 ;
int V_4 ;
if ( V_20 )
V_22 = V_8 ;
else
V_22 = V_23 ;
V_4 = F_6 ( V_5 , V_22 , V_21 ) ;
if ( V_4 ) {
F_12 ( L_16
L_17 , V_24 ) ;
return V_4 ;
}
F_13 ( L_18 , V_24 , V_22 , V_21 ) ;
return V_4 ;
}
static int F_14 ( int V_25 )
{
int V_4 = 0 ;
if ( ! V_15 || F_3 ( V_15 ) ) {
F_12 ( L_19 , V_24 ) ;
return - V_26 ;
}
if ( ! V_11 || F_3 ( V_11 ) ) {
F_12 ( L_20 , V_24 ) ;
return - V_26 ;
}
if ( V_25 ) {
V_4 = F_15 ( V_15 ,
V_27 ) ;
if ( V_4 < 0 ) {
F_12 ( L_21
L_22 , V_24 ) ;
return V_4 ;
}
V_4 = F_15 ( V_11 ,
V_28 ) ;
if ( V_4 < 0 ) {
F_12 ( L_21
L_23 , V_24 ) ;
F_15 ( V_15 ,
V_29 ) ;
return V_4 ;
}
} else {
V_4 = F_15 ( V_15 ,
V_29 ) ;
if ( V_4 < 0 )
F_12 ( L_24
L_22 , V_24 ) ;
V_4 = F_15 ( V_11 ,
V_30 ) ;
if ( V_4 < 0 )
F_12 ( L_24
L_23 , V_24 ) ;
}
F_13 ( L_25 , V_25 ? L_26 : L_27 ) ;
return V_4 < 0 ? V_4 : 0 ;
}
static int F_16 ( struct V_31 * V_6 , T_1 V_32 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
int V_33 = 0 ;
F_18 ( V_34 | V_35 | F_19 ( V_32 ) ,
V_36 ) ;
while ( V_33 < V_37 ) {
if ( ! ( F_20 ( V_36 ) & V_34 ) )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_37 ) {
F_4 ( V_6 -> V_7 , L_28 ,
F_20 ( V_36 ) ) ;
return - V_38 ;
}
return F_22 ( F_20 ( V_36 ) ) ;
}
static int F_23 ( struct V_31 * V_6 , T_1 V_39 , T_1 V_32 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
int V_33 = 0 ;
F_18 ( V_34 | V_40 |
F_19 ( V_32 ) | F_24 ( V_39 ) ,
V_36 ) ;
while ( V_33 < V_37 ) {
if ( ! ( F_20 ( V_36 ) & V_34 ) )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_37 ) {
F_4 ( V_6 -> V_7 , L_29 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
int * V_43 = V_42 -> V_44 ;
if ( ! V_43 )
return;
while ( V_43 [ 0 ] >= 0 ) {
F_26 ( V_2 -> V_6 . V_7 , L_30 ,
V_43 [ 0 ] , V_43 [ 1 ] ) ;
F_23 ( & V_2 -> V_6 , V_43 [ 0 ] , V_43 [ 1 ] ) ;
V_43 += 2 ;
}
}
static int F_27 ( struct V_1 * V_2 , bool assert )
{
int V_4 ;
if ( assert ) {
V_4 = F_28 ( V_2 -> V_45 , V_46 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 . V_7 , L_31 ) ;
} else {
V_4 = F_28 ( V_2 -> V_45 , V_47 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 . V_7 , L_32 ) ;
}
return V_4 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_28 ( V_2 -> V_48 , V_46 ) ;
if ( V_4 ) {
F_4 ( V_2 -> V_6 . V_7 , L_33 ) ;
return V_4 ;
}
F_30 ( 10000 , 12000 ) ;
V_4 = F_28 ( V_2 -> V_48 , V_47 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 . V_7 , L_34 ) ;
return V_4 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_39 ;
int V_4 ;
int V_49 ;
V_4 = F_27 ( V_2 , 1 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_29 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_27 ( V_2 , 0 ) ;
if ( V_4 )
return V_4 ;
V_39 = F_20 ( V_50 ) & ~ V_51 ;
F_18 ( V_39 | V_52 , V_50 ) ;
for ( V_49 = 3 ; V_49 > 0 ; V_49 -- ) {
V_4 = F_23 ( & V_2 -> V_6 , V_53 ,
F_32 ( V_54 ) ) ;
if ( ! V_4 )
break;
V_4 = F_29 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
if ( ! V_49 )
return - V_38 ;
V_4 = F_29 ( V_2 ) ;
if ( V_4 )
return V_4 ;
for ( V_49 = 3 ; V_49 > 0 ; V_49 -- ) {
V_4 = F_16 ( & V_2 -> V_6 , V_55 ) ;
if ( V_4 != - V_38 )
break;
V_4 = F_29 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
if ( ! V_49 )
return - V_38 ;
F_33 ( V_2 -> V_6 . V_7 , L_35 ) ;
return 0 ;
}
static int F_34 ( struct V_31 * V_6 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_33 = 0 ;
int V_4 ;
T_1 V_39 = 0 ;
T_1 V_56 = 0 ;
V_4 = F_31 ( V_2 ) ;
if ( V_4 ) {
F_4 ( V_6 -> V_7 , L_36 ) ;
return V_4 ;
}
F_25 ( V_2 ) ;
F_18 ( V_57 , V_58 ) ;
while ( V_33 < V_59 ) {
if ( ! ( F_20 ( V_58 ) & V_57 ) )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_59 )
return - V_38 ;
F_18 ( 0x80000000 , V_50 ) ;
F_35 ( 100 ) ;
F_18 ( 0x0 , V_60 ) ;
F_18 ( 0x00 , V_61 ) ;
if ( V_42 -> V_62 == V_63 ) {
V_39 = F_20 ( V_64 ) ;
if ( V_42 -> V_65 == V_66 ) {
V_56 = V_67 | V_68 ;
V_39 |= V_69 | V_70 ;
} else if ( V_42 -> V_65 == V_71 ) {
V_56 = V_68 ;
V_39 |= V_70 ;
}
F_18 ( V_39 , V_64 ) ;
F_23 ( V_6 , V_56 , V_72 ) ;
F_23 ( V_6 , V_56 , V_73 ) ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
struct V_74 * V_75 = V_6 -> V_76 -> V_77 ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_33 = 0 ;
if ( F_37 ( & V_2 -> V_78 ) )
return 0 ;
F_38 ( V_2 -> V_79 ) ;
if ( V_2 -> V_42 -> V_80 == V_81 ) {
F_16 ( V_6 , 0x14 ) ;
if ( V_42 -> V_62 == V_63 )
F_23 ( V_6 , 0x01 , 0x30 ) ;
F_23 ( V_6 , 0x08 , 0x09 ) ;
}
F_18 ( F_20 ( V_50 ) | V_82 , V_50 ) ;
while ( V_33 < V_83 ) {
if ( F_20 ( V_50 ) & V_82 )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_83 ) {
F_4 ( V_6 -> V_7 , L_37 ) ;
F_34 ( V_6 ) ;
F_39 ( V_2 -> V_79 ) ;
return - V_38 ;
}
F_18 ( F_20 ( V_58 ) | V_84 | V_85 , V_58 ) ;
if ( V_2 -> V_42 -> V_80 == V_86 &&
V_2 -> V_42 -> V_62 == V_87 )
F_18 ( F_20 ( V_88 ) | V_89 , V_88 ) ;
F_40 ( V_2 -> V_90 ) ;
F_40 ( V_2 -> V_45 ) ;
if ( V_2 -> V_91 )
F_40 ( V_2 -> V_91 ) ;
if ( ! F_3 ( V_2 -> V_92 ) )
F_40 ( V_2 -> V_92 ) ;
if ( V_2 -> V_42 -> V_80 == V_86 &&
V_2 -> V_42 -> V_62 == V_87 ) {
F_14 ( 0 ) ;
F_11 ( 0 ) ;
}
if ( F_41 ( V_6 -> V_7 ) )
F_42 ( V_2 -> V_79 ) ;
if ( V_75 )
F_43 ( V_93 , & ( F_44 ( V_75 ) ) -> V_94 ) ;
F_45 ( & V_2 -> V_78 , 1 ) ;
F_39 ( V_2 -> V_79 ) ;
F_33 ( V_6 -> V_7 , L_38 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
struct V_74 * V_75 = V_6 -> V_76 -> V_77 ;
int V_33 = 0 ;
unsigned V_95 ;
if ( ! F_37 ( & V_2 -> V_78 ) )
return 0 ;
if ( ! F_3 ( V_2 -> V_92 ) )
F_47 ( V_2 -> V_92 ) ;
F_47 ( V_2 -> V_90 ) ;
F_47 ( V_2 -> V_45 ) ;
if ( V_2 -> V_91 )
F_47 ( V_2 -> V_91 ) ;
if ( V_2 -> V_42 -> V_80 == V_86 &&
V_2 -> V_42 -> V_62 == V_87 ) {
F_14 ( 1 ) ;
F_11 ( 1 ) ;
F_18 ( F_20 ( V_88 ) & ~ V_89 , V_88 ) ;
}
V_95 = F_20 ( V_58 ) ;
V_95 &= ~ V_84 ;
V_95 &= ~ V_85 ;
F_18 ( V_95 , V_58 ) ;
if ( ! ( F_20 ( V_50 ) & V_82 ) )
goto V_96;
F_18 ( F_20 ( V_50 ) & ~ V_82 , V_50 ) ;
while ( V_33 < V_97 ) {
if ( ! ( F_20 ( V_50 ) & V_82 ) )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_97 ) {
F_4 ( V_6 -> V_7 , L_39
L_40 ) ;
F_34 ( V_6 ) ;
}
V_96:
if ( F_41 ( V_6 -> V_7 ) )
F_48 ( V_2 -> V_79 ) ;
if ( V_75 )
F_49 ( V_93 , & ( F_44 ( V_75 ) ) -> V_94 ) ;
F_45 ( & V_2 -> V_78 , 0 ) ;
if ( V_2 -> V_98 ) {
V_2 -> V_98 = 0 ;
F_50 ( V_6 -> V_7 ) ;
F_39 ( V_2 -> V_79 ) ;
}
F_33 ( V_6 -> V_7 , L_41 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , unsigned V_99 )
{
if ( V_2 -> V_100 == V_99 )
return;
F_33 ( V_2 -> V_6 . V_7 , L_42 , V_99 ) ;
V_2 -> V_100 = V_99 ;
}
static int F_52 ( struct V_31 * V_6 , unsigned V_99 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_101 == V_102 )
F_51 ( V_2 , V_99 ) ;
return 0 ;
}
static void F_53 ( struct V_31 * V_6 , int V_25 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_103 * V_104 ;
if ( ! V_6 -> V_76 -> V_77 )
return;
V_104 = F_44 ( V_6 -> V_76 -> V_77 ) ;
if ( V_25 ) {
F_54 ( V_6 -> V_7 , L_43 ) ;
if ( V_42 -> V_105 )
V_42 -> V_105 ( 1 ) ;
if ( V_42 -> V_106 )
V_42 -> V_106 ( V_107 ) ;
#ifdef F_55
F_56 ( V_104 , V_104 -> V_79 , V_108 ) ;
#endif
} else {
F_54 ( V_6 -> V_7 , L_44 ) ;
#ifdef F_55
F_57 ( V_104 ) ;
#endif
if ( V_42 -> V_106 )
V_42 -> V_106 ( V_109 ) ;
if ( V_42 -> V_105 )
V_42 -> V_105 ( 0 ) ;
}
}
static int F_58 ( struct V_110 * V_76 , struct V_74 * V_77 )
{
struct V_1 * V_2 = F_17 ( V_76 -> V_6 , struct V_1 , V_6 ) ;
struct V_103 * V_104 ;
if ( V_2 -> V_42 -> V_65 == V_71 ) {
F_33 ( V_76 -> V_6 -> V_7 , L_45 ) ;
return - V_26 ;
}
if ( ! V_77 ) {
if ( V_76 -> V_6 -> V_111 == V_107 ) {
F_59 ( V_76 -> V_6 -> V_7 ) ;
F_53 ( V_76 -> V_6 , 0 ) ;
V_76 -> V_77 = NULL ;
V_76 -> V_6 -> V_111 = V_109 ;
F_60 ( & V_2 -> V_112 ) ;
} else {
V_76 -> V_77 = NULL ;
}
return 0 ;
}
V_104 = F_44 ( V_77 ) ;
V_104 -> V_113 = V_2 -> V_42 -> V_113 ;
V_76 -> V_77 = V_77 ;
F_54 ( V_76 -> V_6 -> V_7 , L_46 ) ;
if ( V_2 -> V_42 -> V_65 == V_114 || V_76 -> V_115 ) {
F_59 ( V_76 -> V_6 -> V_7 ) ;
F_60 ( & V_2 -> V_112 ) ;
}
return 0 ;
}
static void F_61 ( struct V_31 * V_6 , int V_25 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
if ( ! V_6 -> V_76 -> V_115 )
return;
if ( V_25 ) {
F_54 ( V_6 -> V_7 , L_47 ) ;
if ( V_42 -> V_106 )
V_42 -> V_106 ( V_116 ) ;
F_62 ( V_6 -> V_76 -> V_115 ) ;
} else {
F_54 ( V_6 -> V_7 , L_48 ) ;
F_63 ( V_6 -> V_76 -> V_115 ) ;
if ( V_42 -> V_106 )
V_42 -> V_106 ( V_109 ) ;
}
}
static int F_64 ( struct V_110 * V_76 ,
struct V_117 * V_115 )
{
struct V_1 * V_2 = F_17 ( V_76 -> V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_42 -> V_65 == V_114 ) {
F_33 ( V_76 -> V_6 -> V_7 , L_49 ) ;
return - V_26 ;
}
if ( ! V_115 ) {
if ( V_76 -> V_6 -> V_111 == V_116 ) {
F_59 ( V_76 -> V_6 -> V_7 ) ;
F_61 ( V_76 -> V_6 , 0 ) ;
V_76 -> V_115 = NULL ;
V_76 -> V_6 -> V_111 = V_109 ;
F_60 ( & V_2 -> V_112 ) ;
} else {
V_76 -> V_115 = NULL ;
}
return 0 ;
}
V_76 -> V_115 = V_115 ;
F_54 ( V_76 -> V_6 -> V_7 , L_50 ) ;
if ( V_2 -> V_42 -> V_65 == V_71 || V_76 -> V_77 ) {
F_59 ( V_76 -> V_6 -> V_7 ) ;
F_60 ( & V_2 -> V_112 ) ;
}
return 0 ;
}
static bool F_65 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_118 ;
bool V_4 = false ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_4 = V_118 & ( 1 << 4 ) ;
break;
case V_86 :
V_118 = F_16 ( V_6 , 0x87 ) ;
V_4 = V_118 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_118 ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_118 |= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
F_21 ( 20 ) ;
V_118 &= ~ ( 1 << 3 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
V_118 &= ~ ( 1 << 2 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
V_118 &= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
F_21 ( 20 ) ;
V_118 &= ~ ( 1 << 0 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
break;
case V_86 :
F_23 ( V_6 , 0x8 , 0x85 ) ;
F_23 ( V_6 , 0x2 , 0x85 ) ;
F_23 ( V_6 , 0x1 , 0x85 ) ;
break;
default:
break;
}
}
static bool F_67 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_118 ;
bool V_4 = false ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_4 = V_118 & ( 1 << 4 ) ;
break;
case V_86 :
V_118 = F_16 ( V_6 , 0x87 ) ;
V_4 = V_118 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_118 ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_118 &= ~ ( 1 << 0 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
break;
case V_86 :
F_23 ( V_6 , 0x2 , 0x85 ) ;
F_23 ( V_6 , 0x1 , 0x85 ) ;
break;
default:
break;
}
}
static bool F_69 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_119 ;
bool V_4 = false ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_119 = F_16 ( V_6 , 0x15 ) ;
V_4 = ! ( V_119 & 1 ) ;
break;
case V_86 :
V_119 = F_16 ( V_6 , 0x87 ) ;
V_4 = V_119 & 2 ;
break;
default:
break;
}
return V_4 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_118 ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_118 &= ~ ( 1 << 5 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
break;
case V_86 :
F_23 ( V_6 , 0x10 , 0x86 ) ;
break;
default:
break;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_118 ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_118 |= ( 1 << 5 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
break;
case V_86 :
F_23 ( V_6 , 0x10 , 0x85 ) ;
break;
default:
break;
}
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_120 , V_118 ;
V_120 = F_16 ( V_6 , V_54 ) ;
V_120 &= ~ V_121 ;
V_120 |= V_122 ;
F_23 ( V_6 , V_120 , V_54 ) ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_118 &= ~ ( 1 << 3 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
V_118 &= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
F_21 ( 20 ) ;
break;
case V_86 :
F_23 ( V_6 , 0x3F , 0x86 ) ;
F_23 ( V_6 , 0x1F , 0x92 ) ;
F_23 ( V_6 , 0x1F , 0x95 ) ;
F_21 ( 100 ) ;
break;
default:
break;
}
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_120 , V_118 ;
switch ( V_2 -> V_42 -> V_80 ) {
case V_81 :
V_118 = F_16 ( V_6 , 0x34 ) ;
V_118 |= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_118 , 0x34 ) ;
break;
case V_86 :
F_23 ( V_6 , 0x3F , 0x86 ) ;
F_23 ( V_6 , 0x1F , 0x92 ) ;
F_23 ( V_6 , 0x1F , 0x95 ) ;
break;
default:
break;
}
V_120 = F_16 ( V_6 , V_54 ) ;
V_120 &= ~ V_121 ;
V_120 |= V_123 ;
F_23 ( V_6 , V_120 , V_54 ) ;
}
static void F_74 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_17 ( V_125 , struct V_1 , V_126 . V_127 ) ;
struct V_31 * V_6 = & V_2 -> V_6 ;
bool V_128 , V_129 , V_130 ;
unsigned long V_131 ;
F_54 ( V_6 -> V_7 , L_51 ) ;
switch ( V_2 -> V_132 ) {
case V_133 :
F_59 ( V_6 -> V_7 ) ;
F_72 ( V_2 ) ;
F_71 ( V_2 ) ;
V_2 -> V_132 = V_134 ;
V_2 -> V_135 = 0 ;
V_131 = V_136 ;
break;
case V_134 :
V_128 = F_69 ( V_2 ) ;
V_129 = ++ V_2 -> V_135 == V_137 ;
if ( V_128 || V_129 ) {
F_70 ( V_2 ) ;
F_68 ( V_2 ) ;
V_131 = V_138 ;
V_2 -> V_132 = V_139 ;
} else {
V_131 = V_136 ;
}
break;
case V_139 :
V_130 = F_67 ( V_2 ) ;
if ( V_130 ) {
F_66 ( V_2 ) ;
V_131 = V_140 ;
V_2 -> V_132 = V_141 ;
} else {
V_2 -> V_101 = V_102 ;
V_2 -> V_132 = V_142 ;
V_131 = 0 ;
}
break;
case V_141 :
V_130 = F_65 ( V_2 ) ;
if ( V_130 )
V_2 -> V_101 = V_143 ;
else
V_2 -> V_101 = V_144 ;
V_2 -> V_132 = V_145 ;
case V_145 :
V_2 -> V_132 = V_142 ;
case V_142 :
F_73 ( V_2 ) ;
F_54 ( V_6 -> V_7 , L_52 , V_2 -> V_101 ) ;
F_60 ( & V_2 -> V_112 ) ;
return;
default:
return;
}
F_75 ( & V_2 -> V_126 , V_131 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_1 V_146 = F_20 ( V_64 ) ;
switch ( V_42 -> V_65 ) {
case V_66 :
if ( V_42 -> V_62 == V_63 ) {
if ( V_146 & V_147 )
F_49 ( V_148 , & V_2 -> V_149 ) ;
else
F_43 ( V_148 , & V_2 -> V_149 ) ;
if ( V_146 & V_150 )
F_49 ( V_151 , & V_2 -> V_149 ) ;
else
F_43 ( V_151 , & V_2 -> V_149 ) ;
} else if ( V_42 -> V_62 == V_152 ) {
if ( V_42 -> V_153 == V_114 ) {
F_43 ( V_148 , & V_2 -> V_149 ) ;
} else if ( V_42 -> V_153 == V_71 ) {
F_49 ( V_148 , & V_2 -> V_149 ) ;
F_49 ( V_151 , & V_2 -> V_149 ) ;
} else {
F_49 ( V_148 , & V_2 -> V_149 ) ;
F_43 ( V_151 , & V_2 -> V_149 ) ;
}
}
break;
case V_114 :
F_43 ( V_148 , & V_2 -> V_149 ) ;
break;
case V_71 :
F_49 ( V_148 , & V_2 -> V_149 ) ;
if ( V_146 & V_150 )
F_49 ( V_151 , & V_2 -> V_149 ) ;
else
F_43 ( V_151 , & V_2 -> V_149 ) ;
break;
default:
break;
}
}
static void F_77 ( struct V_124 * V_125 )
{
struct V_1 * V_2 = F_17 ( V_125 , struct V_1 , V_112 ) ;
struct V_110 * V_76 = V_2 -> V_6 . V_76 ;
switch ( V_76 -> V_6 -> V_111 ) {
case V_109 :
F_54 ( V_76 -> V_6 -> V_7 , L_53 ) ;
F_34 ( V_76 -> V_6 ) ;
F_76 ( V_2 ) ;
V_76 -> V_6 -> V_111 = V_154 ;
case V_154 :
F_54 ( V_76 -> V_6 -> V_7 , L_54 ) ;
if ( ! F_78 ( V_148 , & V_2 -> V_149 ) && V_76 -> V_77 ) {
F_18 ( F_20 ( V_64 ) & ~ V_70 , V_64 ) ;
F_53 ( V_76 -> V_6 , 1 ) ;
V_76 -> V_6 -> V_111 = V_107 ;
} else if ( F_78 ( V_151 , & V_2 -> V_149 ) ) {
switch ( V_2 -> V_132 ) {
case V_133 :
F_74 ( & V_2 -> V_126 . V_127 ) ;
break;
case V_142 :
switch ( V_2 -> V_101 ) {
case V_143 :
F_51 ( V_2 ,
V_155 ) ;
break;
case V_144 :
F_51 ( V_2 ,
V_155 ) ;
F_61 ( V_76 -> V_6 , 1 ) ;
V_76 -> V_6 -> V_111
= V_116 ;
break;
case V_102 :
F_51 ( V_2 , V_156 ) ;
F_61 ( V_76 -> V_6 , 1 ) ;
V_76 -> V_6 -> V_111
= V_116 ;
break;
default:
break;
}
break;
default:
break;
}
} else {
if ( F_79 ( & V_2 -> V_126 ) ) {
F_80 ( V_76 -> V_6 -> V_7 ) ;
F_34 ( V_76 -> V_6 ) ;
}
F_51 ( V_2 , 0 ) ;
V_2 -> V_132 = V_133 ;
V_2 -> V_101 = V_157 ;
}
F_80 ( V_76 -> V_6 -> V_7 ) ;
break;
case V_116 :
F_54 ( V_76 -> V_6 -> V_7 , L_55 ) ;
if ( ! F_78 ( V_151 , & V_2 -> V_149 ) ||
! F_78 ( V_148 , & V_2 -> V_149 ) ) {
F_51 ( V_2 , 0 ) ;
F_61 ( V_76 -> V_6 , 0 ) ;
V_2 -> V_132 = V_133 ;
V_2 -> V_101 = V_157 ;
V_76 -> V_6 -> V_111 = V_154 ;
F_34 ( V_76 -> V_6 ) ;
F_60 ( V_125 ) ;
}
break;
case V_107 :
F_54 ( V_76 -> V_6 -> V_7 , L_56 ) ;
if ( F_78 ( V_148 , & V_2 -> V_149 ) ) {
F_53 ( V_76 -> V_6 , 0 ) ;
V_76 -> V_6 -> V_111 = V_154 ;
F_34 ( V_76 -> V_6 ) ;
F_60 ( V_125 ) ;
}
break;
default:
break;
}
}
static T_2 F_81 ( int V_79 , void * V_158 )
{
struct V_1 * V_2 = V_158 ;
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_146 = 0 ;
if ( F_37 ( & V_2 -> V_78 ) ) {
F_82 ( V_79 ) ;
V_2 -> V_98 = 1 ;
F_83 ( V_6 -> V_7 ) ;
return V_159 ;
}
V_146 = F_20 ( V_64 ) ;
if ( ! ( V_146 & ( V_160 | V_161 ) ) )
return V_162 ;
if ( ( V_146 & V_160 ) && ( V_146 & V_69 ) ) {
if ( V_146 & V_147 )
F_49 ( V_148 , & V_2 -> V_149 ) ;
else
F_43 ( V_148 , & V_2 -> V_149 ) ;
F_54 ( V_6 -> V_7 , L_57 ) ;
F_84 ( V_6 -> V_7 ) ;
} else if ( ( V_146 & V_161 ) && ( V_146 & V_70 ) ) {
if ( V_146 & V_150 )
F_49 ( V_151 , & V_2 -> V_149 ) ;
else
F_43 ( V_151 , & V_2 -> V_149 ) ;
F_54 ( V_6 -> V_7 , L_58 ) ;
F_84 ( V_6 -> V_7 ) ;
}
F_18 ( V_146 , V_64 ) ;
F_60 ( & V_2 -> V_112 ) ;
return V_159 ;
}
static int F_85 ( struct V_163 * V_164 , void * V_165 )
{
struct V_1 * V_2 = V_164 -> V_166 ;
struct V_110 * V_76 = V_2 -> V_6 . V_76 ;
switch ( V_76 -> V_6 -> V_111 ) {
case V_107 :
F_86 ( V_164 , L_59 ) ;
break;
case V_116 :
F_86 ( V_164 , L_60 ) ;
break;
default:
F_86 ( V_164 , L_61 ) ;
break;
}
return 0 ;
}
static int F_87 ( struct V_167 * V_167 , struct V_168 * V_168 )
{
return F_88 ( V_168 , F_85 , V_167 -> V_169 ) ;
}
static T_3 F_89 ( struct V_168 * V_168 , const char T_4 * V_170 ,
T_5 V_171 , T_6 * V_172 )
{
struct V_163 * V_164 = V_168 -> V_173 ;
struct V_1 * V_2 = V_164 -> V_166 ;
char V_174 [ 16 ] ;
struct V_110 * V_76 = V_2 -> V_6 . V_76 ;
int V_175 = V_171 ;
enum V_176 V_177 ;
memset ( V_174 , 0x00 , sizeof( V_174 ) ) ;
if ( F_90 ( & V_174 , V_170 , F_91 ( T_5 , sizeof( V_174 ) - 1 , V_171 ) ) ) {
V_175 = - V_178 ;
goto V_179;
}
if ( ! strncmp ( V_174 , L_62 , 4 ) ) {
V_177 = V_114 ;
} else if ( ! strncmp ( V_174 , L_63 , 10 ) ) {
V_177 = V_71 ;
} else if ( ! strncmp ( V_174 , L_64 , 4 ) ) {
V_177 = V_180 ;
} else {
V_175 = - V_181 ;
goto V_179;
}
switch ( V_177 ) {
case V_180 :
switch ( V_76 -> V_6 -> V_111 ) {
case V_107 :
case V_116 :
F_49 ( V_148 , & V_2 -> V_149 ) ;
F_43 ( V_151 , & V_2 -> V_149 ) ;
break;
default:
goto V_179;
}
break;
case V_71 :
switch ( V_76 -> V_6 -> V_111 ) {
case V_154 :
case V_107 :
F_49 ( V_148 , & V_2 -> V_149 ) ;
F_49 ( V_151 , & V_2 -> V_149 ) ;
break;
default:
goto V_179;
}
break;
case V_114 :
switch ( V_76 -> V_6 -> V_111 ) {
case V_154 :
case V_116 :
F_43 ( V_148 , & V_2 -> V_149 ) ;
break;
default:
goto V_179;
}
break;
default:
goto V_179;
}
F_59 ( V_76 -> V_6 -> V_7 ) ;
F_60 ( & V_2 -> V_112 ) ;
V_179:
return V_175 ;
}
static int F_92 ( struct V_1 * V_2 )
{
V_182 = F_93 ( L_65 , NULL ) ;
if ( ! V_182 || F_3 ( V_182 ) )
return - V_26 ;
V_183 = F_94 ( L_66 , V_184 | V_185 ,
V_182 , V_2 , & V_186 ) ;
if ( ! V_183 ) {
F_95 ( V_182 ) ;
V_182 = NULL ;
return - V_26 ;
}
return 0 ;
}
static void F_96 ( void )
{
F_95 ( V_183 ) ;
F_95 ( V_182 ) ;
}
static int T_7 F_97 ( struct V_187 * V_188 )
{
int V_4 = 0 ;
struct V_189 * V_190 ;
struct V_1 * V_2 ;
struct V_31 * V_6 ;
F_33 ( & V_188 -> V_7 , L_67 ) ;
if ( ! V_188 -> V_7 . V_191 ) {
F_4 ( & V_188 -> V_7 , L_68 ) ;
return - V_26 ;
}
V_2 = F_98 ( sizeof( struct V_1 ) , V_192 ) ;
if ( ! V_2 ) {
F_4 ( & V_188 -> V_7 , L_69 ) ;
return - V_193 ;
}
V_2 -> V_6 . V_76 = F_98 ( sizeof( struct V_110 ) , V_192 ) ;
if ( ! V_2 -> V_6 . V_76 ) {
F_4 ( & V_188 -> V_7 , L_69 ) ;
return - V_193 ;
}
V_2 -> V_42 = V_188 -> V_7 . V_191 ;
V_6 = & V_2 -> V_6 ;
V_6 -> V_7 = & V_188 -> V_7 ;
V_2 -> V_48 = F_99 ( & V_188 -> V_7 , L_70 ) ;
if ( F_3 ( V_2 -> V_48 ) ) {
F_4 ( & V_188 -> V_7 , L_71 ) ;
V_4 = F_5 ( V_2 -> V_48 ) ;
goto V_194;
}
V_2 -> V_45 = F_99 ( & V_188 -> V_7 , L_72 ) ;
if ( F_3 ( V_2 -> V_45 ) ) {
F_4 ( & V_188 -> V_7 , L_73 ) ;
V_4 = F_5 ( V_2 -> V_45 ) ;
goto V_195;
}
F_100 ( V_2 -> V_45 , 60000000 ) ;
if ( V_2 -> V_42 -> V_196 ) {
V_2 -> V_92 = F_99 ( & V_188 -> V_7 ,
V_2 -> V_42 -> V_196 ) ;
if ( F_3 ( V_2 -> V_92 ) )
goto V_197;
F_100 ( V_2 -> V_92 , V_198 ) ;
F_47 ( V_2 -> V_92 ) ;
} else
V_2 -> V_92 = F_101 ( - V_199 ) ;
V_2 -> V_90 = F_99 ( & V_188 -> V_7 , L_74 ) ;
if ( F_3 ( V_2 -> V_90 ) ) {
F_4 ( & V_188 -> V_7 , L_75 ) ;
V_4 = F_5 ( V_2 -> V_90 ) ;
goto V_200;
}
V_2 -> V_91 = F_99 ( & V_188 -> V_7 , L_76 ) ;
if ( F_3 ( V_2 -> V_91 ) )
V_2 -> V_91 = NULL ;
V_190 = F_102 ( V_188 , V_201 , 0 ) ;
if ( ! V_190 ) {
F_4 ( & V_188 -> V_7 , L_77 ) ;
V_4 = - V_26 ;
goto V_202;
}
V_2 -> V_203 = F_103 ( V_190 -> V_204 , F_104 ( V_190 ) ) ;
if ( ! V_2 -> V_203 ) {
F_4 ( & V_188 -> V_7 , L_78 ) ;
V_4 = - V_193 ;
goto V_202;
}
F_33 ( & V_188 -> V_7 , L_79 , V_2 -> V_203 ) ;
V_2 -> V_79 = F_105 ( V_188 , 0 ) ;
if ( ! V_2 -> V_79 ) {
F_4 ( & V_188 -> V_7 , L_80 ) ;
V_4 = - V_26 ;
goto V_205;
}
F_47 ( V_2 -> V_45 ) ;
F_47 ( V_2 -> V_90 ) ;
V_4 = F_1 ( V_2 , 1 ) ;
if ( V_4 ) {
F_4 ( & V_188 -> V_7 , L_81 ) ;
goto V_205;
}
V_4 = F_10 ( V_2 , 1 ) ;
if ( V_4 ) {
F_4 ( & V_188 -> V_7 , L_82 ) ;
goto V_206;
}
V_4 = F_14 ( 1 ) ;
if ( V_4 ) {
F_4 ( & V_188 -> V_7 , L_83 ) ;
goto V_207;
}
if ( V_2 -> V_91 )
F_47 ( V_2 -> V_91 ) ;
F_18 ( 0 , V_208 ) ;
F_18 ( 0 , V_64 ) ;
F_106 ( & V_2 -> V_112 , F_77 ) ;
F_107 ( & V_2 -> V_126 , F_74 ) ;
V_4 = F_108 ( V_2 -> V_79 , F_81 , V_108 ,
L_65 , V_2 ) ;
if ( V_4 ) {
F_4 ( & V_188 -> V_7 , L_84 ) ;
goto V_209;
}
V_6 -> V_3 = F_34 ;
V_6 -> V_210 = F_52 ;
V_6 -> V_211 = & V_212 ;
V_6 -> V_76 -> V_6 = & V_2 -> V_6 ;
V_6 -> V_76 -> V_213 = F_58 ;
V_6 -> V_76 -> V_214 = F_64 ;
V_4 = F_109 ( & V_2 -> V_6 , V_215 ) ;
if ( V_4 ) {
F_4 ( & V_188 -> V_7 , L_85 ) ;
goto V_216;
}
F_110 ( V_188 , V_2 ) ;
F_111 ( & V_188 -> V_7 , 1 ) ;
if ( V_2 -> V_42 -> V_65 == V_66 &&
V_2 -> V_42 -> V_62 == V_152 ) {
V_4 = F_92 ( V_2 ) ;
if ( V_4 )
F_54 ( & V_188 -> V_7 , L_86
L_87 ) ;
}
F_112 ( & V_188 -> V_7 ) ;
F_113 ( & V_188 -> V_7 ) ;
return 0 ;
V_216:
V_216 ( V_2 -> V_79 , V_2 ) ;
V_209:
F_40 ( V_2 -> V_90 ) ;
F_40 ( V_2 -> V_45 ) ;
V_207:
F_10 ( V_2 , 0 ) ;
V_206:
F_1 ( V_2 , 0 ) ;
V_205:
F_114 ( V_2 -> V_203 ) ;
V_202:
if ( V_2 -> V_91 )
F_115 ( V_2 -> V_91 ) ;
F_115 ( V_2 -> V_90 ) ;
V_200:
if ( ! F_3 ( V_2 -> V_92 ) ) {
F_40 ( V_2 -> V_92 ) ;
F_115 ( V_2 -> V_92 ) ;
}
V_197:
F_115 ( V_2 -> V_45 ) ;
V_195:
F_115 ( V_2 -> V_48 ) ;
V_194:
F_116 ( V_2 -> V_6 . V_76 ) ;
F_116 ( V_2 ) ;
return V_4 ;
}
static int F_117 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_118 ( V_188 ) ;
struct V_31 * V_6 = & V_2 -> V_6 ;
int V_33 = 0 ;
if ( V_6 -> V_76 -> V_77 || V_6 -> V_76 -> V_115 )
return - V_217 ;
F_96 () ;
F_79 ( & V_2 -> V_126 ) ;
F_119 ( & V_2 -> V_112 ) ;
F_120 ( & V_188 -> V_7 ) ;
F_111 ( & V_188 -> V_7 , 0 ) ;
F_121 ( & V_188 -> V_7 ) ;
F_122 ( V_6 ) ;
V_216 ( V_2 -> V_79 , V_2 ) ;
F_16 ( V_6 , 0x14 ) ;
F_23 ( V_6 , 0x08 , 0x09 ) ;
F_18 ( F_20 ( V_50 ) | V_82 , V_50 ) ;
while ( V_33 < V_83 ) {
if ( F_20 ( V_50 ) & V_82 )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_83 )
F_4 ( V_6 -> V_7 , L_37 ) ;
F_40 ( V_2 -> V_90 ) ;
F_40 ( V_2 -> V_45 ) ;
if ( V_2 -> V_91 )
F_40 ( V_2 -> V_91 ) ;
if ( ! F_3 ( V_2 -> V_92 ) ) {
F_40 ( V_2 -> V_92 ) ;
F_115 ( V_2 -> V_92 ) ;
}
F_10 ( V_2 , 0 ) ;
F_114 ( V_2 -> V_203 ) ;
F_123 ( & V_188 -> V_7 ) ;
F_115 ( V_2 -> V_48 ) ;
F_115 ( V_2 -> V_90 ) ;
F_115 ( V_2 -> V_45 ) ;
if ( V_2 -> V_91 )
F_115 ( V_2 -> V_91 ) ;
F_116 ( V_2 -> V_6 . V_76 ) ;
F_116 ( V_2 ) ;
return 0 ;
}
static int F_124 ( struct V_218 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
struct V_110 * V_76 = V_2 -> V_6 . V_76 ;
F_54 ( V_7 , L_88 ) ;
if ( V_76 -> V_6 -> V_111 != V_109 )
F_126 ( V_7 , 1000 ) ;
return - V_219 ;
}
static int F_127 ( struct V_218 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
F_54 ( V_7 , L_89 ) ;
return F_36 ( V_2 ) ;
}
static int F_128 ( struct V_218 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
F_54 ( V_7 , L_90 ) ;
return F_46 ( V_2 ) ;
}
static int F_129 ( struct V_218 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
F_54 ( V_7 , L_91 ) ;
return F_36 ( V_2 ) ;
}
static int F_130 ( struct V_218 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
int V_4 ;
F_54 ( V_7 , L_92 ) ;
V_4 = F_46 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_121 ( V_7 ) ;
F_112 ( V_7 ) ;
F_113 ( V_7 ) ;
return 0 ;
}
static int T_7 F_131 ( void )
{
return F_132 ( & V_220 , F_97 ) ;
}
static void T_8 F_133 ( void )
{
F_134 ( & V_220 ) ;
}
