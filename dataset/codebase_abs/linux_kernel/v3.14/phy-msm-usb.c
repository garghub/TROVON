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
int V_4 = 0 ;
if ( ! V_15 || F_3 ( V_15 ) ) {
F_12 ( L_16 , V_21 ) ;
return - V_22 ;
}
if ( ! V_11 || F_3 ( V_11 ) ) {
F_12 ( L_17 , V_21 ) ;
return - V_22 ;
}
if ( V_20 ) {
V_4 = F_13 ( V_15 ,
V_23 ) ;
if ( V_4 < 0 ) {
F_12 ( L_18
L_19 , V_21 ) ;
return V_4 ;
}
V_4 = F_13 ( V_11 ,
V_24 ) ;
if ( V_4 < 0 ) {
F_12 ( L_18
L_20 , V_21 ) ;
F_13 ( V_15 ,
V_25 ) ;
return V_4 ;
}
} else {
V_4 = F_13 ( V_15 ,
V_25 ) ;
if ( V_4 < 0 )
F_12 ( L_21
L_19 , V_21 ) ;
V_4 = F_13 ( V_11 ,
V_26 ) ;
if ( V_4 < 0 )
F_12 ( L_21
L_20 , V_21 ) ;
}
F_14 ( L_22 , V_20 ? L_23 : L_24 ) ;
return V_4 < 0 ? V_4 : 0 ;
}
static int F_15 ( struct V_27 * V_6 , T_1 V_28 )
{
struct V_1 * V_2 = F_16 ( V_6 , struct V_1 , V_6 ) ;
int V_29 = 0 ;
F_17 ( V_30 | V_31 | F_18 ( V_28 ) ,
V_32 ) ;
while ( V_29 < V_33 ) {
if ( ! ( F_19 ( V_32 ) & V_30 ) )
break;
F_20 ( 1 ) ;
V_29 ++ ;
}
if ( V_29 >= V_33 ) {
F_4 ( V_6 -> V_7 , L_25 ,
F_19 ( V_32 ) ) ;
return - V_34 ;
}
return F_21 ( F_19 ( V_32 ) ) ;
}
static int F_22 ( struct V_27 * V_6 , T_1 V_35 , T_1 V_28 )
{
struct V_1 * V_2 = F_16 ( V_6 , struct V_1 , V_6 ) ;
int V_29 = 0 ;
F_17 ( V_30 | V_36 |
F_18 ( V_28 ) | F_23 ( V_35 ) ,
V_32 ) ;
while ( V_29 < V_33 ) {
if ( ! ( F_19 ( V_32 ) & V_30 ) )
break;
F_20 ( 1 ) ;
V_29 ++ ;
}
if ( V_29 >= V_33 ) {
F_4 ( V_6 -> V_7 , L_26 ) ;
return - V_34 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int * V_39 = V_38 -> V_40 ;
if ( ! V_39 )
return;
while ( V_39 [ 0 ] >= 0 ) {
F_25 ( V_2 -> V_6 . V_7 , L_27 ,
V_39 [ 0 ] , V_39 [ 1 ] ) ;
F_22 ( & V_2 -> V_6 , V_39 [ 0 ] , V_39 [ 1 ] ) ;
V_39 += 2 ;
}
}
static int F_26 ( struct V_1 * V_2 , bool assert )
{
int V_4 = 0 ;
if ( ! V_2 -> V_38 -> V_41 )
return V_4 ;
V_4 = V_2 -> V_38 -> V_41 ( V_2 -> V_42 , assert ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 . V_7 , L_28 ,
assert ? L_29 : L_30 ) ;
return V_4 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( ! V_2 -> V_38 -> V_43 )
return V_4 ;
V_4 = V_2 -> V_38 -> V_43 ( V_2 -> V_44 ) ;
if ( V_4 )
F_4 ( V_2 -> V_6 . V_7 , L_31 ) ;
return V_4 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_35 ;
int V_4 ;
int V_45 ;
V_4 = F_26 ( V_2 , 1 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_26 ( V_2 , 0 ) ;
if ( V_4 )
return V_4 ;
V_35 = F_19 ( V_46 ) & ~ V_47 ;
F_17 ( V_35 | V_48 , V_46 ) ;
for ( V_45 = 3 ; V_45 > 0 ; V_45 -- ) {
V_4 = F_22 ( & V_2 -> V_6 , V_49 ,
F_29 ( V_50 ) ) ;
if ( ! V_4 )
break;
V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
if ( ! V_45 )
return - V_34 ;
V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return V_4 ;
for ( V_45 = 3 ; V_45 > 0 ; V_45 -- ) {
V_4 = F_15 ( & V_2 -> V_6 , V_51 ) ;
if ( V_4 != - V_34 )
break;
V_4 = F_27 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
if ( ! V_45 )
return - V_34 ;
F_30 ( V_2 -> V_6 . V_7 , L_32 ) ;
return 0 ;
}
static int F_31 ( struct V_27 * V_6 )
{
struct V_1 * V_2 = F_16 ( V_6 , struct V_1 , V_6 ) ;
struct V_37 * V_38 = V_2 -> V_38 ;
int V_29 = 0 ;
int V_4 ;
T_1 V_35 = 0 ;
T_1 V_52 = 0 ;
V_4 = F_28 ( V_2 ) ;
if ( V_4 ) {
F_4 ( V_6 -> V_7 , L_33 ) ;
return V_4 ;
}
F_24 ( V_2 ) ;
F_17 ( V_53 , V_54 ) ;
while ( V_29 < V_55 ) {
if ( ! ( F_19 ( V_54 ) & V_53 ) )
break;
F_20 ( 1 ) ;
V_29 ++ ;
}
if ( V_29 >= V_55 )
return - V_34 ;
F_17 ( 0x80000000 , V_46 ) ;
F_32 ( 100 ) ;
F_17 ( 0x0 , V_56 ) ;
F_17 ( 0x00 , V_57 ) ;
if ( V_38 -> V_58 == V_59 ) {
V_35 = F_19 ( V_60 ) ;
if ( V_38 -> V_61 == V_62 ) {
V_52 = V_63 | V_64 ;
V_35 |= V_65 | V_66 ;
} else if ( V_38 -> V_61 == V_67 ) {
V_52 = V_64 ;
V_35 |= V_66 ;
}
F_17 ( V_35 , V_60 ) ;
F_22 ( V_6 , V_52 , V_68 ) ;
F_22 ( V_6 , V_52 , V_69 ) ;
}
return 0 ;
}
static int F_33 ( int V_70 )
{
int V_71 = V_9 ;
int V_72 ;
int V_4 ;
if ( V_70 )
V_72 = V_8 ;
else
V_72 = V_73 ;
V_4 = F_6 ( V_5 , V_72 , V_71 ) ;
if ( V_4 ) {
F_12 ( L_34
L_35 , V_21 ) ;
return V_4 ;
}
F_14 ( L_36 , V_21 , V_72 , V_71 ) ;
return V_4 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
struct V_74 * V_75 = V_6 -> V_76 -> V_77 ;
struct V_37 * V_38 = V_2 -> V_38 ;
int V_29 = 0 ;
if ( F_35 ( & V_2 -> V_78 ) )
return 0 ;
F_36 ( V_2 -> V_79 ) ;
if ( V_2 -> V_38 -> V_80 == V_81 ) {
F_15 ( V_6 , 0x14 ) ;
if ( V_38 -> V_58 == V_59 )
F_22 ( V_6 , 0x01 , 0x30 ) ;
F_22 ( V_6 , 0x08 , 0x09 ) ;
}
F_17 ( F_19 ( V_46 ) | V_82 , V_46 ) ;
while ( V_29 < V_83 ) {
if ( F_19 ( V_46 ) & V_82 )
break;
F_20 ( 1 ) ;
V_29 ++ ;
}
if ( V_29 >= V_83 ) {
F_4 ( V_6 -> V_7 , L_37 ) ;
F_31 ( V_6 ) ;
F_37 ( V_2 -> V_79 ) ;
return - V_34 ;
}
F_17 ( F_19 ( V_54 ) | V_84 | V_85 , V_54 ) ;
if ( V_2 -> V_38 -> V_80 == V_86 &&
V_2 -> V_38 -> V_58 == V_87 )
F_17 ( F_19 ( V_88 ) | V_89 , V_88 ) ;
F_38 ( V_2 -> V_90 ) ;
F_38 ( V_2 -> V_42 ) ;
if ( V_2 -> V_91 )
F_38 ( V_2 -> V_91 ) ;
if ( ! F_3 ( V_2 -> V_92 ) )
F_38 ( V_2 -> V_92 ) ;
if ( V_2 -> V_38 -> V_80 == V_86 &&
V_2 -> V_38 -> V_58 == V_87 ) {
F_11 ( 0 ) ;
F_33 ( 0 ) ;
}
if ( F_39 ( V_6 -> V_7 ) )
F_40 ( V_2 -> V_79 ) ;
if ( V_75 )
F_41 ( V_93 , & ( F_42 ( V_75 ) ) -> V_94 ) ;
F_43 ( & V_2 -> V_78 , 1 ) ;
F_37 ( V_2 -> V_79 ) ;
F_30 ( V_6 -> V_7 , L_38 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
struct V_74 * V_75 = V_6 -> V_76 -> V_77 ;
int V_29 = 0 ;
unsigned V_95 ;
if ( ! F_35 ( & V_2 -> V_78 ) )
return 0 ;
if ( ! F_3 ( V_2 -> V_92 ) )
F_45 ( V_2 -> V_92 ) ;
F_45 ( V_2 -> V_90 ) ;
F_45 ( V_2 -> V_42 ) ;
if ( V_2 -> V_91 )
F_45 ( V_2 -> V_91 ) ;
if ( V_2 -> V_38 -> V_80 == V_86 &&
V_2 -> V_38 -> V_58 == V_87 ) {
F_11 ( 1 ) ;
F_33 ( 1 ) ;
F_17 ( F_19 ( V_88 ) & ~ V_89 , V_88 ) ;
}
V_95 = F_19 ( V_54 ) ;
V_95 &= ~ V_84 ;
V_95 &= ~ V_85 ;
F_17 ( V_95 , V_54 ) ;
if ( ! ( F_19 ( V_46 ) & V_82 ) )
goto V_96;
F_17 ( F_19 ( V_46 ) & ~ V_82 , V_46 ) ;
while ( V_29 < V_97 ) {
if ( ! ( F_19 ( V_46 ) & V_82 ) )
break;
F_20 ( 1 ) ;
V_29 ++ ;
}
if ( V_29 >= V_97 ) {
F_4 ( V_6 -> V_7 , L_39
L_40 ) ;
F_31 ( V_6 ) ;
}
V_96:
if ( F_39 ( V_6 -> V_7 ) )
F_46 ( V_2 -> V_79 ) ;
if ( V_75 )
F_47 ( V_93 , & ( F_42 ( V_75 ) ) -> V_94 ) ;
F_43 ( & V_2 -> V_78 , 0 ) ;
if ( V_2 -> V_98 ) {
V_2 -> V_98 = 0 ;
F_48 ( V_6 -> V_7 ) ;
F_37 ( V_2 -> V_79 ) ;
}
F_30 ( V_6 -> V_7 , L_41 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , unsigned V_99 )
{
if ( V_2 -> V_100 == V_99 )
return;
F_30 ( V_2 -> V_6 . V_7 , L_42 , V_99 ) ;
V_2 -> V_100 = V_99 ;
}
static int F_50 ( struct V_27 * V_6 , unsigned V_99 )
{
struct V_1 * V_2 = F_16 ( V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_101 == V_102 )
F_49 ( V_2 , V_99 ) ;
return 0 ;
}
static void F_51 ( struct V_27 * V_6 , int V_20 )
{
struct V_1 * V_2 = F_16 ( V_6 , struct V_1 , V_6 ) ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_103 * V_104 ;
if ( ! V_6 -> V_76 -> V_77 )
return;
V_104 = F_42 ( V_6 -> V_76 -> V_77 ) ;
if ( V_20 ) {
F_52 ( V_6 -> V_7 , L_43 ) ;
if ( V_38 -> V_105 )
V_38 -> V_105 ( 1 ) ;
if ( V_38 -> V_106 )
V_38 -> V_106 ( V_107 ) ;
#ifdef F_53
F_54 ( V_104 , V_104 -> V_79 , V_108 ) ;
F_55 ( V_104 -> V_109 . V_110 ) ;
#endif
} else {
F_52 ( V_6 -> V_7 , L_44 ) ;
#ifdef F_53
F_56 ( V_104 ) ;
#endif
if ( V_38 -> V_106 )
V_38 -> V_106 ( V_111 ) ;
if ( V_38 -> V_105 )
V_38 -> V_105 ( 0 ) ;
}
}
static int F_57 ( struct V_112 * V_76 , struct V_74 * V_77 )
{
struct V_1 * V_2 = F_16 ( V_76 -> V_6 , struct V_1 , V_6 ) ;
struct V_103 * V_104 ;
if ( V_2 -> V_38 -> V_61 == V_67 ) {
F_30 ( V_76 -> V_6 -> V_7 , L_45 ) ;
return - V_22 ;
}
if ( ! V_77 ) {
if ( V_76 -> V_6 -> V_113 == V_107 ) {
F_58 ( V_76 -> V_6 -> V_7 ) ;
F_51 ( V_76 -> V_6 , 0 ) ;
V_76 -> V_77 = NULL ;
V_76 -> V_6 -> V_113 = V_111 ;
F_59 ( & V_2 -> V_114 ) ;
} else {
V_76 -> V_77 = NULL ;
}
return 0 ;
}
V_104 = F_42 ( V_77 ) ;
V_104 -> V_115 = V_2 -> V_38 -> V_115 ;
V_76 -> V_77 = V_77 ;
F_52 ( V_76 -> V_6 -> V_7 , L_46 ) ;
if ( V_2 -> V_38 -> V_61 == V_116 || V_76 -> V_117 ) {
F_58 ( V_76 -> V_6 -> V_7 ) ;
F_59 ( & V_2 -> V_114 ) ;
}
return 0 ;
}
static void F_60 ( struct V_27 * V_6 , int V_20 )
{
struct V_1 * V_2 = F_16 ( V_6 , struct V_1 , V_6 ) ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_6 -> V_76 -> V_117 )
return;
if ( V_20 ) {
F_52 ( V_6 -> V_7 , L_47 ) ;
if ( V_38 -> V_106 )
V_38 -> V_106 ( V_118 ) ;
F_61 ( V_6 -> V_76 -> V_117 ) ;
} else {
F_52 ( V_6 -> V_7 , L_48 ) ;
F_62 ( V_6 -> V_76 -> V_117 ) ;
if ( V_38 -> V_106 )
V_38 -> V_106 ( V_111 ) ;
}
}
static int F_63 ( struct V_112 * V_76 ,
struct V_119 * V_117 )
{
struct V_1 * V_2 = F_16 ( V_76 -> V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_38 -> V_61 == V_116 ) {
F_30 ( V_76 -> V_6 -> V_7 , L_49 ) ;
return - V_22 ;
}
if ( ! V_117 ) {
if ( V_76 -> V_6 -> V_113 == V_118 ) {
F_58 ( V_76 -> V_6 -> V_7 ) ;
F_60 ( V_76 -> V_6 , 0 ) ;
V_76 -> V_117 = NULL ;
V_76 -> V_6 -> V_113 = V_111 ;
F_59 ( & V_2 -> V_114 ) ;
} else {
V_76 -> V_117 = NULL ;
}
return 0 ;
}
V_76 -> V_117 = V_117 ;
F_52 ( V_76 -> V_6 -> V_7 , L_50 ) ;
if ( V_2 -> V_38 -> V_61 == V_67 || V_76 -> V_77 ) {
F_58 ( V_76 -> V_6 -> V_7 ) ;
F_59 ( & V_2 -> V_114 ) ;
}
return 0 ;
}
static bool F_64 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_120 ;
bool V_4 = false ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_4 = V_120 & ( 1 << 4 ) ;
break;
case V_86 :
V_120 = F_15 ( V_6 , 0x87 ) ;
V_4 = V_120 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_120 ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_120 |= ~ ( 1 << 1 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
F_20 ( 20 ) ;
V_120 &= ~ ( 1 << 3 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
V_120 &= ~ ( 1 << 2 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
V_120 &= ~ ( 1 << 1 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
F_20 ( 20 ) ;
V_120 &= ~ ( 1 << 0 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
break;
case V_86 :
F_22 ( V_6 , 0x8 , 0x85 ) ;
F_22 ( V_6 , 0x2 , 0x85 ) ;
F_22 ( V_6 , 0x1 , 0x85 ) ;
break;
default:
break;
}
}
static bool F_66 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_120 ;
bool V_4 = false ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_4 = V_120 & ( 1 << 4 ) ;
break;
case V_86 :
V_120 = F_15 ( V_6 , 0x87 ) ;
V_4 = V_120 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_120 ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_120 &= ~ ( 1 << 0 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
break;
case V_86 :
F_22 ( V_6 , 0x2 , 0x85 ) ;
F_22 ( V_6 , 0x1 , 0x85 ) ;
break;
default:
break;
}
}
static bool F_68 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_121 ;
bool V_4 = false ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_121 = F_15 ( V_6 , 0x15 ) ;
V_4 = ! ( V_121 & 1 ) ;
break;
case V_86 :
V_121 = F_15 ( V_6 , 0x87 ) ;
V_4 = V_121 & 2 ;
break;
default:
break;
}
return V_4 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_120 ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_120 &= ~ ( 1 << 5 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
break;
case V_86 :
F_22 ( V_6 , 0x10 , 0x86 ) ;
break;
default:
break;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_120 ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_120 |= ( 1 << 5 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
break;
case V_86 :
F_22 ( V_6 , 0x10 , 0x85 ) ;
break;
default:
break;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_122 , V_120 ;
V_122 = F_15 ( V_6 , V_50 ) ;
V_122 &= ~ V_123 ;
V_122 |= V_124 ;
F_22 ( V_6 , V_122 , V_50 ) ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_120 &= ~ ( 1 << 3 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
V_120 &= ~ ( 1 << 1 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
F_20 ( 20 ) ;
break;
case V_86 :
F_22 ( V_6 , 0x3F , 0x86 ) ;
F_22 ( V_6 , 0x1F , 0x92 ) ;
F_22 ( V_6 , 0x1F , 0x95 ) ;
F_20 ( 100 ) ;
break;
default:
break;
}
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_122 , V_120 ;
switch ( V_2 -> V_38 -> V_80 ) {
case V_81 :
V_120 = F_15 ( V_6 , 0x34 ) ;
V_120 |= ~ ( 1 << 1 ) ;
F_22 ( V_6 , V_120 , 0x34 ) ;
break;
case V_86 :
F_22 ( V_6 , 0x3F , 0x86 ) ;
F_22 ( V_6 , 0x1F , 0x92 ) ;
F_22 ( V_6 , 0x1F , 0x95 ) ;
break;
default:
break;
}
V_122 = F_15 ( V_6 , V_50 ) ;
V_122 &= ~ V_123 ;
V_122 |= V_125 ;
F_22 ( V_6 , V_122 , V_50 ) ;
}
static void F_73 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_16 ( V_127 , struct V_1 , V_128 . V_129 ) ;
struct V_27 * V_6 = & V_2 -> V_6 ;
bool V_130 , V_131 , V_132 ;
unsigned long V_133 ;
F_52 ( V_6 -> V_7 , L_51 ) ;
switch ( V_2 -> V_134 ) {
case V_135 :
F_58 ( V_6 -> V_7 ) ;
F_71 ( V_2 ) ;
F_70 ( V_2 ) ;
V_2 -> V_134 = V_136 ;
V_2 -> V_137 = 0 ;
V_133 = V_138 ;
break;
case V_136 :
V_130 = F_68 ( V_2 ) ;
V_131 = ++ V_2 -> V_137 == V_139 ;
if ( V_130 || V_131 ) {
F_69 ( V_2 ) ;
F_67 ( V_2 ) ;
V_133 = V_140 ;
V_2 -> V_134 = V_141 ;
} else {
V_133 = V_138 ;
}
break;
case V_141 :
V_132 = F_66 ( V_2 ) ;
if ( V_132 ) {
F_65 ( V_2 ) ;
V_133 = V_142 ;
V_2 -> V_134 = V_143 ;
} else {
V_2 -> V_101 = V_102 ;
V_2 -> V_134 = V_144 ;
V_133 = 0 ;
}
break;
case V_143 :
V_132 = F_64 ( V_2 ) ;
if ( V_132 )
V_2 -> V_101 = V_145 ;
else
V_2 -> V_101 = V_146 ;
V_2 -> V_134 = V_147 ;
case V_147 :
V_2 -> V_134 = V_144 ;
case V_144 :
F_72 ( V_2 ) ;
F_52 ( V_6 -> V_7 , L_52 , V_2 -> V_101 ) ;
F_59 ( & V_2 -> V_114 ) ;
return;
default:
return;
}
F_74 ( & V_2 -> V_128 , V_133 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
T_1 V_148 = F_19 ( V_60 ) ;
switch ( V_38 -> V_61 ) {
case V_62 :
if ( V_38 -> V_58 == V_59 ) {
if ( V_148 & V_149 )
F_47 ( V_150 , & V_2 -> V_151 ) ;
else
F_41 ( V_150 , & V_2 -> V_151 ) ;
if ( V_148 & V_152 )
F_47 ( V_153 , & V_2 -> V_151 ) ;
else
F_41 ( V_153 , & V_2 -> V_151 ) ;
} else if ( V_38 -> V_58 == V_154 ) {
if ( V_38 -> V_155 == V_116 ) {
F_41 ( V_150 , & V_2 -> V_151 ) ;
} else if ( V_38 -> V_155 == V_67 ) {
F_47 ( V_150 , & V_2 -> V_151 ) ;
F_47 ( V_153 , & V_2 -> V_151 ) ;
} else {
F_47 ( V_150 , & V_2 -> V_151 ) ;
F_41 ( V_153 , & V_2 -> V_151 ) ;
}
}
break;
case V_116 :
F_41 ( V_150 , & V_2 -> V_151 ) ;
break;
case V_67 :
F_47 ( V_150 , & V_2 -> V_151 ) ;
if ( V_148 & V_152 )
F_47 ( V_153 , & V_2 -> V_151 ) ;
else
F_41 ( V_153 , & V_2 -> V_151 ) ;
break;
default:
break;
}
}
static void F_76 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_16 ( V_127 , struct V_1 , V_114 ) ;
struct V_112 * V_76 = V_2 -> V_6 . V_76 ;
switch ( V_76 -> V_6 -> V_113 ) {
case V_111 :
F_52 ( V_76 -> V_6 -> V_7 , L_53 ) ;
F_31 ( V_76 -> V_6 ) ;
F_75 ( V_2 ) ;
V_76 -> V_6 -> V_113 = V_156 ;
case V_156 :
F_52 ( V_76 -> V_6 -> V_7 , L_54 ) ;
if ( ! F_77 ( V_150 , & V_2 -> V_151 ) && V_76 -> V_77 ) {
F_17 ( F_19 ( V_60 ) & ~ V_66 , V_60 ) ;
F_51 ( V_76 -> V_6 , 1 ) ;
V_76 -> V_6 -> V_113 = V_107 ;
} else if ( F_77 ( V_153 , & V_2 -> V_151 ) ) {
switch ( V_2 -> V_134 ) {
case V_135 :
F_73 ( & V_2 -> V_128 . V_129 ) ;
break;
case V_144 :
switch ( V_2 -> V_101 ) {
case V_145 :
F_49 ( V_2 ,
V_157 ) ;
break;
case V_146 :
F_49 ( V_2 ,
V_157 ) ;
F_60 ( V_76 -> V_6 , 1 ) ;
V_76 -> V_6 -> V_113
= V_118 ;
break;
case V_102 :
F_49 ( V_2 , V_158 ) ;
F_60 ( V_76 -> V_6 , 1 ) ;
V_76 -> V_6 -> V_113
= V_118 ;
break;
default:
break;
}
break;
default:
break;
}
} else {
if ( F_78 ( & V_2 -> V_128 ) ) {
F_79 ( V_76 -> V_6 -> V_7 ) ;
F_31 ( V_76 -> V_6 ) ;
}
F_49 ( V_2 , 0 ) ;
V_2 -> V_134 = V_135 ;
V_2 -> V_101 = V_159 ;
}
F_79 ( V_76 -> V_6 -> V_7 ) ;
break;
case V_118 :
F_52 ( V_76 -> V_6 -> V_7 , L_55 ) ;
if ( ! F_77 ( V_153 , & V_2 -> V_151 ) ||
! F_77 ( V_150 , & V_2 -> V_151 ) ) {
F_49 ( V_2 , 0 ) ;
F_60 ( V_76 -> V_6 , 0 ) ;
V_2 -> V_134 = V_135 ;
V_2 -> V_101 = V_159 ;
V_76 -> V_6 -> V_113 = V_156 ;
F_31 ( V_76 -> V_6 ) ;
F_59 ( V_127 ) ;
}
break;
case V_107 :
F_52 ( V_76 -> V_6 -> V_7 , L_56 ) ;
if ( F_77 ( V_150 , & V_2 -> V_151 ) ) {
F_51 ( V_76 -> V_6 , 0 ) ;
V_76 -> V_6 -> V_113 = V_156 ;
F_31 ( V_76 -> V_6 ) ;
F_59 ( V_127 ) ;
}
break;
default:
break;
}
}
static T_2 F_80 ( int V_79 , void * V_160 )
{
struct V_1 * V_2 = V_160 ;
struct V_27 * V_6 = & V_2 -> V_6 ;
T_1 V_148 = 0 ;
if ( F_35 ( & V_2 -> V_78 ) ) {
F_81 ( V_79 ) ;
V_2 -> V_98 = 1 ;
F_82 ( V_6 -> V_7 ) ;
return V_161 ;
}
V_148 = F_19 ( V_60 ) ;
if ( ! ( V_148 & ( V_162 | V_163 ) ) )
return V_164 ;
if ( ( V_148 & V_162 ) && ( V_148 & V_65 ) ) {
if ( V_148 & V_149 )
F_47 ( V_150 , & V_2 -> V_151 ) ;
else
F_41 ( V_150 , & V_2 -> V_151 ) ;
F_52 ( V_6 -> V_7 , L_57 ) ;
F_83 ( V_6 -> V_7 ) ;
} else if ( ( V_148 & V_163 ) && ( V_148 & V_66 ) ) {
if ( V_148 & V_152 )
F_47 ( V_153 , & V_2 -> V_151 ) ;
else
F_41 ( V_153 , & V_2 -> V_151 ) ;
F_52 ( V_6 -> V_7 , L_58 ) ;
F_83 ( V_6 -> V_7 ) ;
}
F_17 ( V_148 , V_60 ) ;
F_59 ( & V_2 -> V_114 ) ;
return V_161 ;
}
static int F_84 ( struct V_165 * V_166 , void * V_167 )
{
struct V_1 * V_2 = V_166 -> V_168 ;
struct V_112 * V_76 = V_2 -> V_6 . V_76 ;
switch ( V_76 -> V_6 -> V_113 ) {
case V_107 :
F_85 ( V_166 , L_59 ) ;
break;
case V_118 :
F_85 ( V_166 , L_60 ) ;
break;
default:
F_85 ( V_166 , L_61 ) ;
break;
}
return 0 ;
}
static int F_86 ( struct V_169 * V_169 , struct V_170 * V_170 )
{
return F_87 ( V_170 , F_84 , V_169 -> V_171 ) ;
}
static T_3 F_88 ( struct V_170 * V_170 , const char T_4 * V_172 ,
T_5 V_173 , T_6 * V_174 )
{
struct V_165 * V_166 = V_170 -> V_175 ;
struct V_1 * V_2 = V_166 -> V_168 ;
char V_176 [ 16 ] ;
struct V_112 * V_76 = V_2 -> V_6 . V_76 ;
int V_177 = V_173 ;
enum V_178 V_179 ;
memset ( V_176 , 0x00 , sizeof( V_176 ) ) ;
if ( F_89 ( & V_176 , V_172 , F_90 ( T_5 , sizeof( V_176 ) - 1 , V_173 ) ) ) {
V_177 = - V_180 ;
goto V_181;
}
if ( ! strncmp ( V_176 , L_62 , 4 ) ) {
V_179 = V_116 ;
} else if ( ! strncmp ( V_176 , L_63 , 10 ) ) {
V_179 = V_67 ;
} else if ( ! strncmp ( V_176 , L_64 , 4 ) ) {
V_179 = V_182 ;
} else {
V_177 = - V_183 ;
goto V_181;
}
switch ( V_179 ) {
case V_182 :
switch ( V_76 -> V_6 -> V_113 ) {
case V_107 :
case V_118 :
F_47 ( V_150 , & V_2 -> V_151 ) ;
F_41 ( V_153 , & V_2 -> V_151 ) ;
break;
default:
goto V_181;
}
break;
case V_67 :
switch ( V_76 -> V_6 -> V_113 ) {
case V_156 :
case V_107 :
F_47 ( V_150 , & V_2 -> V_151 ) ;
F_47 ( V_153 , & V_2 -> V_151 ) ;
break;
default:
goto V_181;
}
break;
case V_116 :
switch ( V_76 -> V_6 -> V_113 ) {
case V_156 :
case V_118 :
F_41 ( V_150 , & V_2 -> V_151 ) ;
break;
default:
goto V_181;
}
break;
default:
goto V_181;
}
F_58 ( V_76 -> V_6 -> V_7 ) ;
F_59 ( & V_2 -> V_114 ) ;
V_181:
return V_177 ;
}
static int F_91 ( struct V_1 * V_2 )
{
V_184 = F_92 ( L_65 , NULL ) ;
if ( ! V_184 || F_3 ( V_184 ) )
return - V_22 ;
V_185 = F_93 ( L_66 , V_186 | V_187 ,
V_184 , V_2 , & V_188 ) ;
if ( ! V_185 ) {
F_94 ( V_184 ) ;
V_184 = NULL ;
return - V_22 ;
}
return 0 ;
}
static void F_95 ( void )
{
F_94 ( V_185 ) ;
F_94 ( V_184 ) ;
}
static int T_7 F_96 ( struct V_189 * V_190 )
{
int V_4 = 0 ;
struct V_191 * V_192 ;
struct V_1 * V_2 ;
struct V_27 * V_6 ;
F_30 ( & V_190 -> V_7 , L_67 ) ;
if ( ! F_97 ( & V_190 -> V_7 ) ) {
F_4 ( & V_190 -> V_7 , L_68 ) ;
return - V_22 ;
}
V_2 = F_98 ( sizeof( struct V_1 ) , V_193 ) ;
if ( ! V_2 ) {
F_4 ( & V_190 -> V_7 , L_69 ) ;
return - V_194 ;
}
V_2 -> V_6 . V_76 = F_98 ( sizeof( struct V_112 ) , V_193 ) ;
if ( ! V_2 -> V_6 . V_76 ) {
F_4 ( & V_190 -> V_7 , L_69 ) ;
return - V_194 ;
}
V_2 -> V_38 = F_97 ( & V_190 -> V_7 ) ;
V_6 = & V_2 -> V_6 ;
V_6 -> V_7 = & V_190 -> V_7 ;
V_2 -> V_44 = F_99 ( & V_190 -> V_7 , L_70 ) ;
if ( F_3 ( V_2 -> V_44 ) ) {
F_4 ( & V_190 -> V_7 , L_71 ) ;
V_4 = F_5 ( V_2 -> V_44 ) ;
goto V_195;
}
V_2 -> V_42 = F_99 ( & V_190 -> V_7 , L_72 ) ;
if ( F_3 ( V_2 -> V_42 ) ) {
F_4 ( & V_190 -> V_7 , L_73 ) ;
V_4 = F_5 ( V_2 -> V_42 ) ;
goto V_196;
}
F_100 ( V_2 -> V_42 , 60000000 ) ;
if ( V_2 -> V_38 -> V_197 ) {
V_2 -> V_92 = F_99 ( & V_190 -> V_7 ,
V_2 -> V_38 -> V_197 ) ;
if ( F_3 ( V_2 -> V_92 ) )
goto V_198;
F_100 ( V_2 -> V_92 , V_199 ) ;
F_45 ( V_2 -> V_92 ) ;
} else
V_2 -> V_92 = F_101 ( - V_200 ) ;
V_2 -> V_90 = F_99 ( & V_190 -> V_7 , L_74 ) ;
if ( F_3 ( V_2 -> V_90 ) ) {
F_4 ( & V_190 -> V_7 , L_75 ) ;
V_4 = F_5 ( V_2 -> V_90 ) ;
goto V_201;
}
V_2 -> V_91 = F_99 ( & V_190 -> V_7 , L_76 ) ;
if ( F_3 ( V_2 -> V_91 ) )
V_2 -> V_91 = NULL ;
V_192 = F_102 ( V_190 , V_202 , 0 ) ;
if ( ! V_192 ) {
F_4 ( & V_190 -> V_7 , L_77 ) ;
V_4 = - V_22 ;
goto V_203;
}
V_2 -> V_204 = F_103 ( V_192 -> V_205 , F_104 ( V_192 ) ) ;
if ( ! V_2 -> V_204 ) {
F_4 ( & V_190 -> V_7 , L_78 ) ;
V_4 = - V_194 ;
goto V_203;
}
F_30 ( & V_190 -> V_7 , L_79 , V_2 -> V_204 ) ;
V_2 -> V_79 = F_105 ( V_190 , 0 ) ;
if ( ! V_2 -> V_79 ) {
F_4 ( & V_190 -> V_7 , L_80 ) ;
V_4 = - V_22 ;
goto V_206;
}
F_45 ( V_2 -> V_42 ) ;
F_45 ( V_2 -> V_90 ) ;
V_4 = F_1 ( V_2 , 1 ) ;
if ( V_4 ) {
F_4 ( & V_190 -> V_7 , L_81 ) ;
goto V_206;
}
V_4 = F_10 ( V_2 , 1 ) ;
if ( V_4 ) {
F_4 ( & V_190 -> V_7 , L_82 ) ;
goto V_207;
}
V_4 = F_11 ( 1 ) ;
if ( V_4 ) {
F_4 ( & V_190 -> V_7 , L_83 ) ;
goto V_208;
}
if ( V_2 -> V_91 )
F_45 ( V_2 -> V_91 ) ;
F_17 ( 0 , V_209 ) ;
F_17 ( 0 , V_60 ) ;
F_106 ( & V_2 -> V_114 , F_76 ) ;
F_107 ( & V_2 -> V_128 , F_73 ) ;
V_4 = F_108 ( V_2 -> V_79 , F_80 , V_108 ,
L_65 , V_2 ) ;
if ( V_4 ) {
F_4 ( & V_190 -> V_7 , L_84 ) ;
goto V_210;
}
V_6 -> V_3 = F_31 ;
V_6 -> V_211 = F_50 ;
V_6 -> V_212 = & V_213 ;
V_6 -> V_76 -> V_6 = & V_2 -> V_6 ;
V_6 -> V_76 -> V_214 = F_57 ;
V_6 -> V_76 -> V_215 = F_63 ;
V_4 = F_109 ( & V_2 -> V_6 , V_216 ) ;
if ( V_4 ) {
F_4 ( & V_190 -> V_7 , L_85 ) ;
goto V_217;
}
F_110 ( V_190 , V_2 ) ;
F_111 ( & V_190 -> V_7 , 1 ) ;
if ( V_2 -> V_38 -> V_61 == V_62 &&
V_2 -> V_38 -> V_58 == V_154 ) {
V_4 = F_91 ( V_2 ) ;
if ( V_4 )
F_52 ( & V_190 -> V_7 , L_86
L_87 ) ;
}
F_112 ( & V_190 -> V_7 ) ;
F_113 ( & V_190 -> V_7 ) ;
return 0 ;
V_217:
V_217 ( V_2 -> V_79 , V_2 ) ;
V_210:
F_38 ( V_2 -> V_90 ) ;
F_38 ( V_2 -> V_42 ) ;
V_208:
F_10 ( V_2 , 0 ) ;
V_207:
F_1 ( V_2 , 0 ) ;
V_206:
F_114 ( V_2 -> V_204 ) ;
V_203:
if ( V_2 -> V_91 )
F_115 ( V_2 -> V_91 ) ;
F_115 ( V_2 -> V_90 ) ;
V_201:
if ( ! F_3 ( V_2 -> V_92 ) ) {
F_38 ( V_2 -> V_92 ) ;
F_115 ( V_2 -> V_92 ) ;
}
V_198:
F_115 ( V_2 -> V_42 ) ;
V_196:
F_115 ( V_2 -> V_44 ) ;
V_195:
F_116 ( V_2 -> V_6 . V_76 ) ;
F_116 ( V_2 ) ;
return V_4 ;
}
static int F_117 ( struct V_189 * V_190 )
{
struct V_1 * V_2 = F_118 ( V_190 ) ;
struct V_27 * V_6 = & V_2 -> V_6 ;
int V_29 = 0 ;
if ( V_6 -> V_76 -> V_77 || V_6 -> V_76 -> V_117 )
return - V_218 ;
F_95 () ;
F_78 ( & V_2 -> V_128 ) ;
F_119 ( & V_2 -> V_114 ) ;
F_120 ( & V_190 -> V_7 ) ;
F_111 ( & V_190 -> V_7 , 0 ) ;
F_121 ( & V_190 -> V_7 ) ;
F_122 ( V_6 ) ;
V_217 ( V_2 -> V_79 , V_2 ) ;
F_15 ( V_6 , 0x14 ) ;
F_22 ( V_6 , 0x08 , 0x09 ) ;
F_17 ( F_19 ( V_46 ) | V_82 , V_46 ) ;
while ( V_29 < V_83 ) {
if ( F_19 ( V_46 ) & V_82 )
break;
F_20 ( 1 ) ;
V_29 ++ ;
}
if ( V_29 >= V_83 )
F_4 ( V_6 -> V_7 , L_37 ) ;
F_38 ( V_2 -> V_90 ) ;
F_38 ( V_2 -> V_42 ) ;
if ( V_2 -> V_91 )
F_38 ( V_2 -> V_91 ) ;
if ( ! F_3 ( V_2 -> V_92 ) ) {
F_38 ( V_2 -> V_92 ) ;
F_115 ( V_2 -> V_92 ) ;
}
F_10 ( V_2 , 0 ) ;
F_114 ( V_2 -> V_204 ) ;
F_123 ( & V_190 -> V_7 ) ;
F_115 ( V_2 -> V_44 ) ;
F_115 ( V_2 -> V_90 ) ;
F_115 ( V_2 -> V_42 ) ;
if ( V_2 -> V_91 )
F_115 ( V_2 -> V_91 ) ;
F_116 ( V_2 -> V_6 . V_76 ) ;
F_116 ( V_2 ) ;
return 0 ;
}
static int F_124 ( struct V_219 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
struct V_112 * V_76 = V_2 -> V_6 . V_76 ;
F_52 ( V_7 , L_88 ) ;
if ( V_76 -> V_6 -> V_113 != V_111 )
F_126 ( V_7 , 1000 ) ;
return - V_220 ;
}
static int F_127 ( struct V_219 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
F_52 ( V_7 , L_89 ) ;
return F_34 ( V_2 ) ;
}
static int F_128 ( struct V_219 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
F_52 ( V_7 , L_90 ) ;
return F_44 ( V_2 ) ;
}
static int F_129 ( struct V_219 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
F_52 ( V_7 , L_91 ) ;
return F_34 ( V_2 ) ;
}
static int F_130 ( struct V_219 * V_7 )
{
struct V_1 * V_2 = F_125 ( V_7 ) ;
int V_4 ;
F_52 ( V_7 , L_92 ) ;
V_4 = F_44 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_121 ( V_7 ) ;
F_112 ( V_7 ) ;
F_113 ( V_7 ) ;
return 0 ;
}
