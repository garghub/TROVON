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
struct V_74 * V_75 = V_6 -> V_76 ;
struct V_41 * V_42 = V_2 -> V_42 ;
int V_33 = 0 ;
if ( F_37 ( & V_2 -> V_77 ) )
return 0 ;
F_38 ( V_2 -> V_78 ) ;
if ( V_2 -> V_42 -> V_79 == V_80 ) {
F_16 ( V_6 , 0x14 ) ;
if ( V_42 -> V_62 == V_63 )
F_23 ( V_6 , 0x01 , 0x30 ) ;
F_23 ( V_6 , 0x08 , 0x09 ) ;
}
F_18 ( F_20 ( V_50 ) | V_81 , V_50 ) ;
while ( V_33 < V_82 ) {
if ( F_20 ( V_50 ) & V_81 )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_82 ) {
F_4 ( V_6 -> V_7 , L_37 ) ;
F_34 ( V_6 ) ;
F_39 ( V_2 -> V_78 ) ;
return - V_38 ;
}
F_18 ( F_20 ( V_58 ) | V_83 | V_84 , V_58 ) ;
if ( V_2 -> V_42 -> V_79 == V_85 &&
V_2 -> V_42 -> V_62 == V_86 )
F_18 ( F_20 ( V_87 ) | V_88 , V_87 ) ;
F_40 ( V_2 -> V_89 ) ;
F_40 ( V_2 -> V_45 ) ;
if ( V_2 -> V_90 )
F_40 ( V_2 -> V_90 ) ;
if ( ! F_3 ( V_2 -> V_91 ) )
F_40 ( V_2 -> V_91 ) ;
if ( V_2 -> V_42 -> V_79 == V_85 &&
V_2 -> V_42 -> V_62 == V_86 ) {
F_14 ( 0 ) ;
F_11 ( 0 ) ;
}
if ( F_41 ( V_6 -> V_7 ) )
F_42 ( V_2 -> V_78 ) ;
if ( V_75 )
F_43 ( V_92 , & ( F_44 ( V_75 ) ) -> V_93 ) ;
F_45 ( & V_2 -> V_77 , 1 ) ;
F_39 ( V_2 -> V_78 ) ;
F_33 ( V_6 -> V_7 , L_38 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
struct V_74 * V_75 = V_6 -> V_76 ;
int V_33 = 0 ;
unsigned V_94 ;
if ( ! F_37 ( & V_2 -> V_77 ) )
return 0 ;
if ( ! F_3 ( V_2 -> V_91 ) )
F_47 ( V_2 -> V_91 ) ;
F_47 ( V_2 -> V_89 ) ;
F_47 ( V_2 -> V_45 ) ;
if ( V_2 -> V_90 )
F_47 ( V_2 -> V_90 ) ;
if ( V_2 -> V_42 -> V_79 == V_85 &&
V_2 -> V_42 -> V_62 == V_86 ) {
F_14 ( 1 ) ;
F_11 ( 1 ) ;
F_18 ( F_20 ( V_87 ) & ~ V_88 , V_87 ) ;
}
V_94 = F_20 ( V_58 ) ;
V_94 &= ~ V_83 ;
V_94 &= ~ V_84 ;
F_18 ( V_94 , V_58 ) ;
if ( ! ( F_20 ( V_50 ) & V_81 ) )
goto V_95;
F_18 ( F_20 ( V_50 ) & ~ V_81 , V_50 ) ;
while ( V_33 < V_96 ) {
if ( ! ( F_20 ( V_50 ) & V_81 ) )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_96 ) {
F_4 ( V_6 -> V_7 , L_39
L_40 ) ;
F_34 ( V_6 ) ;
}
V_95:
if ( F_41 ( V_6 -> V_7 ) )
F_48 ( V_2 -> V_78 ) ;
if ( V_75 )
F_49 ( V_92 , & ( F_44 ( V_75 ) ) -> V_93 ) ;
F_45 ( & V_2 -> V_77 , 0 ) ;
if ( V_2 -> V_97 ) {
V_2 -> V_97 = 0 ;
F_50 ( V_6 -> V_7 ) ;
F_39 ( V_2 -> V_78 ) ;
}
F_33 ( V_6 -> V_7 , L_41 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , unsigned V_98 )
{
if ( V_2 -> V_99 == V_98 )
return;
F_33 ( V_2 -> V_6 . V_7 , L_42 , V_98 ) ;
V_2 -> V_99 = V_98 ;
}
static int F_52 ( struct V_31 * V_6 , unsigned V_98 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_100 == V_101 )
F_51 ( V_2 , V_98 ) ;
return 0 ;
}
static void F_53 ( struct V_31 * V_6 , int V_25 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
struct V_102 * V_103 ;
if ( ! V_6 -> V_76 )
return;
V_103 = F_44 ( V_6 -> V_76 ) ;
if ( V_25 ) {
F_54 ( V_6 -> V_7 , L_43 ) ;
if ( V_42 -> V_104 )
V_42 -> V_104 ( 1 ) ;
if ( V_42 -> V_105 )
V_42 -> V_105 ( V_106 ) ;
#ifdef F_55
F_56 ( V_103 , V_103 -> V_78 , V_107 ) ;
#endif
} else {
F_54 ( V_6 -> V_7 , L_44 ) ;
#ifdef F_55
F_57 ( V_103 ) ;
#endif
if ( V_42 -> V_105 )
V_42 -> V_105 ( V_108 ) ;
if ( V_42 -> V_104 )
V_42 -> V_104 ( 0 ) ;
}
}
static int F_58 ( struct V_31 * V_6 , struct V_74 * V_76 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
struct V_102 * V_103 ;
if ( V_2 -> V_42 -> V_65 == V_71 ) {
F_33 ( V_6 -> V_7 , L_45 ) ;
return - V_26 ;
}
if ( ! V_76 ) {
if ( V_6 -> V_109 == V_106 ) {
F_59 ( V_6 -> V_7 ) ;
F_53 ( V_6 , 0 ) ;
V_6 -> V_76 = NULL ;
V_6 -> V_109 = V_108 ;
F_60 ( & V_2 -> V_110 ) ;
} else {
V_6 -> V_76 = NULL ;
}
return 0 ;
}
V_103 = F_44 ( V_76 ) ;
V_103 -> V_111 = V_2 -> V_42 -> V_111 ;
V_6 -> V_76 = V_76 ;
F_54 ( V_6 -> V_7 , L_46 ) ;
if ( V_2 -> V_42 -> V_65 == V_112 || V_6 -> V_113 ) {
F_59 ( V_6 -> V_7 ) ;
F_60 ( & V_2 -> V_110 ) ;
}
return 0 ;
}
static void F_61 ( struct V_31 * V_6 , int V_25 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
struct V_41 * V_42 = V_2 -> V_42 ;
if ( ! V_6 -> V_113 )
return;
if ( V_25 ) {
F_54 ( V_6 -> V_7 , L_47 ) ;
if ( V_42 -> V_105 )
V_42 -> V_105 ( V_114 ) ;
F_62 ( V_6 -> V_113 ) ;
} else {
F_54 ( V_6 -> V_7 , L_48 ) ;
F_63 ( V_6 -> V_113 ) ;
if ( V_42 -> V_105 )
V_42 -> V_105 ( V_108 ) ;
}
}
static int F_64 ( struct V_31 * V_6 ,
struct V_115 * V_113 )
{
struct V_1 * V_2 = F_17 ( V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_42 -> V_65 == V_112 ) {
F_33 ( V_6 -> V_7 , L_49 ) ;
return - V_26 ;
}
if ( ! V_113 ) {
if ( V_6 -> V_109 == V_114 ) {
F_59 ( V_6 -> V_7 ) ;
F_61 ( V_6 , 0 ) ;
V_6 -> V_113 = NULL ;
V_6 -> V_109 = V_108 ;
F_60 ( & V_2 -> V_110 ) ;
} else {
V_6 -> V_113 = NULL ;
}
return 0 ;
}
V_6 -> V_113 = V_113 ;
F_54 ( V_6 -> V_7 , L_50 ) ;
if ( V_2 -> V_42 -> V_65 == V_71 || V_6 -> V_76 ) {
F_59 ( V_6 -> V_7 ) ;
F_60 ( & V_2 -> V_110 ) ;
}
return 0 ;
}
static bool F_65 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_116 ;
bool V_4 = false ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_4 = V_116 & ( 1 << 4 ) ;
break;
case V_85 :
V_116 = F_16 ( V_6 , 0x87 ) ;
V_4 = V_116 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_116 ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_116 |= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
F_21 ( 20 ) ;
V_116 &= ~ ( 1 << 3 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
V_116 &= ~ ( 1 << 2 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
V_116 &= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
F_21 ( 20 ) ;
V_116 &= ~ ( 1 << 0 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
break;
case V_85 :
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
T_1 V_116 ;
bool V_4 = false ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_4 = V_116 & ( 1 << 4 ) ;
break;
case V_85 :
V_116 = F_16 ( V_6 , 0x87 ) ;
V_4 = V_116 & 1 ;
break;
default:
break;
}
return V_4 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_116 ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_116 &= ~ ( 1 << 0 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
break;
case V_85 :
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
T_1 V_117 ;
bool V_4 = false ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_117 = F_16 ( V_6 , 0x15 ) ;
V_4 = ! ( V_117 & 1 ) ;
break;
case V_85 :
V_117 = F_16 ( V_6 , 0x87 ) ;
V_4 = V_117 & 2 ;
break;
default:
break;
}
return V_4 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_116 ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_116 &= ~ ( 1 << 5 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
break;
case V_85 :
F_23 ( V_6 , 0x10 , 0x86 ) ;
break;
default:
break;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_116 ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_116 |= ( 1 << 5 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
break;
case V_85 :
F_23 ( V_6 , 0x10 , 0x85 ) ;
break;
default:
break;
}
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_118 , V_116 ;
V_118 = F_16 ( V_6 , V_54 ) ;
V_118 &= ~ V_119 ;
V_118 |= V_120 ;
F_23 ( V_6 , V_118 , V_54 ) ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_116 &= ~ ( 1 << 3 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
V_116 &= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
F_21 ( 20 ) ;
break;
case V_85 :
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
T_1 V_118 , V_116 ;
switch ( V_2 -> V_42 -> V_79 ) {
case V_80 :
V_116 = F_16 ( V_6 , 0x34 ) ;
V_116 |= ~ ( 1 << 1 ) ;
F_23 ( V_6 , V_116 , 0x34 ) ;
break;
case V_85 :
F_23 ( V_6 , 0x3F , 0x86 ) ;
F_23 ( V_6 , 0x1F , 0x92 ) ;
F_23 ( V_6 , 0x1F , 0x95 ) ;
break;
default:
break;
}
V_118 = F_16 ( V_6 , V_54 ) ;
V_118 &= ~ V_119 ;
V_118 |= V_121 ;
F_23 ( V_6 , V_118 , V_54 ) ;
}
static void F_74 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_17 ( V_123 , struct V_1 , V_124 . V_125 ) ;
struct V_31 * V_6 = & V_2 -> V_6 ;
bool V_126 , V_127 , V_128 ;
unsigned long V_129 ;
F_54 ( V_6 -> V_7 , L_51 ) ;
switch ( V_2 -> V_130 ) {
case V_131 :
F_59 ( V_6 -> V_7 ) ;
F_72 ( V_2 ) ;
F_71 ( V_2 ) ;
V_2 -> V_130 = V_132 ;
V_2 -> V_133 = 0 ;
V_129 = V_134 ;
break;
case V_132 :
V_126 = F_69 ( V_2 ) ;
V_127 = ++ V_2 -> V_133 == V_135 ;
if ( V_126 || V_127 ) {
F_70 ( V_2 ) ;
F_68 ( V_2 ) ;
V_129 = V_136 ;
V_2 -> V_130 = V_137 ;
} else {
V_129 = V_134 ;
}
break;
case V_137 :
V_128 = F_67 ( V_2 ) ;
if ( V_128 ) {
F_66 ( V_2 ) ;
V_129 = V_138 ;
V_2 -> V_130 = V_139 ;
} else {
V_2 -> V_100 = V_101 ;
V_2 -> V_130 = V_140 ;
V_129 = 0 ;
}
break;
case V_139 :
V_128 = F_65 ( V_2 ) ;
if ( V_128 )
V_2 -> V_100 = V_141 ;
else
V_2 -> V_100 = V_142 ;
V_2 -> V_130 = V_143 ;
case V_143 :
V_2 -> V_130 = V_140 ;
case V_140 :
F_73 ( V_2 ) ;
F_54 ( V_6 -> V_7 , L_52 , V_2 -> V_100 ) ;
F_60 ( & V_2 -> V_110 ) ;
return;
default:
return;
}
F_75 ( & V_2 -> V_124 , V_129 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_1 V_144 = F_20 ( V_64 ) ;
switch ( V_42 -> V_65 ) {
case V_66 :
if ( V_42 -> V_62 == V_63 ) {
if ( V_144 & V_145 )
F_49 ( V_146 , & V_2 -> V_147 ) ;
else
F_43 ( V_146 , & V_2 -> V_147 ) ;
if ( V_144 & V_148 )
F_49 ( V_149 , & V_2 -> V_147 ) ;
else
F_43 ( V_149 , & V_2 -> V_147 ) ;
} else if ( V_42 -> V_62 == V_150 ) {
if ( V_42 -> V_151 == V_112 ) {
F_43 ( V_146 , & V_2 -> V_147 ) ;
} else if ( V_42 -> V_151 == V_71 ) {
F_49 ( V_146 , & V_2 -> V_147 ) ;
F_49 ( V_149 , & V_2 -> V_147 ) ;
} else {
F_49 ( V_146 , & V_2 -> V_147 ) ;
F_43 ( V_149 , & V_2 -> V_147 ) ;
}
}
break;
case V_112 :
F_43 ( V_146 , & V_2 -> V_147 ) ;
break;
case V_71 :
F_49 ( V_146 , & V_2 -> V_147 ) ;
if ( V_144 & V_148 )
F_49 ( V_149 , & V_2 -> V_147 ) ;
else
F_43 ( V_149 , & V_2 -> V_147 ) ;
break;
default:
break;
}
}
static void F_77 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = F_17 ( V_123 , struct V_1 , V_110 ) ;
struct V_31 * V_6 = & V_2 -> V_6 ;
switch ( V_6 -> V_109 ) {
case V_108 :
F_54 ( V_6 -> V_7 , L_53 ) ;
F_34 ( V_6 ) ;
F_76 ( V_2 ) ;
V_6 -> V_109 = V_152 ;
case V_152 :
F_54 ( V_6 -> V_7 , L_54 ) ;
if ( ! F_78 ( V_146 , & V_2 -> V_147 ) && V_6 -> V_76 ) {
F_18 ( F_20 ( V_64 ) & ~ V_70 , V_64 ) ;
F_53 ( V_6 , 1 ) ;
V_6 -> V_109 = V_106 ;
} else if ( F_78 ( V_149 , & V_2 -> V_147 ) ) {
switch ( V_2 -> V_130 ) {
case V_131 :
F_74 ( & V_2 -> V_124 . V_125 ) ;
break;
case V_140 :
switch ( V_2 -> V_100 ) {
case V_141 :
F_51 ( V_2 ,
V_153 ) ;
break;
case V_142 :
F_51 ( V_2 ,
V_153 ) ;
F_61 ( V_6 , 1 ) ;
V_6 -> V_109 = V_114 ;
break;
case V_101 :
F_51 ( V_2 , V_154 ) ;
F_61 ( V_6 , 1 ) ;
V_6 -> V_109 = V_114 ;
break;
default:
break;
}
break;
default:
break;
}
} else {
if ( F_79 ( & V_2 -> V_124 ) ) {
F_80 ( V_6 -> V_7 ) ;
F_34 ( V_6 ) ;
}
F_51 ( V_2 , 0 ) ;
V_2 -> V_130 = V_131 ;
V_2 -> V_100 = V_155 ;
}
F_80 ( V_6 -> V_7 ) ;
break;
case V_114 :
F_54 ( V_6 -> V_7 , L_55 ) ;
if ( ! F_78 ( V_149 , & V_2 -> V_147 ) ||
! F_78 ( V_146 , & V_2 -> V_147 ) ) {
F_51 ( V_2 , 0 ) ;
F_61 ( V_6 , 0 ) ;
V_2 -> V_130 = V_131 ;
V_2 -> V_100 = V_155 ;
V_6 -> V_109 = V_152 ;
F_34 ( V_6 ) ;
F_60 ( V_123 ) ;
}
break;
case V_106 :
F_54 ( V_6 -> V_7 , L_56 ) ;
if ( F_78 ( V_146 , & V_2 -> V_147 ) ) {
F_53 ( V_6 , 0 ) ;
V_6 -> V_109 = V_152 ;
F_34 ( V_6 ) ;
F_60 ( V_123 ) ;
}
break;
default:
break;
}
}
static T_2 F_81 ( int V_78 , void * V_156 )
{
struct V_1 * V_2 = V_156 ;
struct V_31 * V_6 = & V_2 -> V_6 ;
T_1 V_144 = 0 ;
if ( F_37 ( & V_2 -> V_77 ) ) {
F_82 ( V_78 ) ;
V_2 -> V_97 = 1 ;
F_83 ( V_6 -> V_7 ) ;
return V_157 ;
}
V_144 = F_20 ( V_64 ) ;
if ( ! ( V_144 & ( V_158 | V_159 ) ) )
return V_160 ;
if ( ( V_144 & V_158 ) && ( V_144 & V_69 ) ) {
if ( V_144 & V_145 )
F_49 ( V_146 , & V_2 -> V_147 ) ;
else
F_43 ( V_146 , & V_2 -> V_147 ) ;
F_54 ( V_6 -> V_7 , L_57 ) ;
F_84 ( V_6 -> V_7 ) ;
} else if ( ( V_144 & V_159 ) && ( V_144 & V_70 ) ) {
if ( V_144 & V_148 )
F_49 ( V_149 , & V_2 -> V_147 ) ;
else
F_43 ( V_149 , & V_2 -> V_147 ) ;
F_54 ( V_6 -> V_7 , L_58 ) ;
F_84 ( V_6 -> V_7 ) ;
}
F_18 ( V_144 , V_64 ) ;
F_60 ( & V_2 -> V_110 ) ;
return V_157 ;
}
static int F_85 ( struct V_161 * V_162 , void * V_163 )
{
struct V_1 * V_2 = V_162 -> V_164 ;
struct V_31 * V_6 = & V_2 -> V_6 ;
switch ( V_6 -> V_109 ) {
case V_106 :
F_86 ( V_162 , L_59 ) ;
break;
case V_114 :
F_86 ( V_162 , L_60 ) ;
break;
default:
F_86 ( V_162 , L_61 ) ;
break;
}
return 0 ;
}
static int F_87 ( struct V_165 * V_165 , struct V_166 * V_166 )
{
return F_88 ( V_166 , F_85 , V_165 -> V_167 ) ;
}
static T_3 F_89 ( struct V_166 * V_166 , const char T_4 * V_168 ,
T_5 V_169 , T_6 * V_170 )
{
struct V_161 * V_162 = V_166 -> V_171 ;
struct V_1 * V_2 = V_162 -> V_164 ;
char V_172 [ 16 ] ;
struct V_31 * V_6 = & V_2 -> V_6 ;
int V_173 = V_169 ;
enum V_174 V_175 ;
memset ( V_172 , 0x00 , sizeof( V_172 ) ) ;
if ( F_90 ( & V_172 , V_168 , F_91 ( T_5 , sizeof( V_172 ) - 1 , V_169 ) ) ) {
V_173 = - V_176 ;
goto V_177;
}
if ( ! strncmp ( V_172 , L_62 , 4 ) ) {
V_175 = V_112 ;
} else if ( ! strncmp ( V_172 , L_63 , 10 ) ) {
V_175 = V_71 ;
} else if ( ! strncmp ( V_172 , L_64 , 4 ) ) {
V_175 = V_178 ;
} else {
V_173 = - V_179 ;
goto V_177;
}
switch ( V_175 ) {
case V_178 :
switch ( V_6 -> V_109 ) {
case V_106 :
case V_114 :
F_49 ( V_146 , & V_2 -> V_147 ) ;
F_43 ( V_149 , & V_2 -> V_147 ) ;
break;
default:
goto V_177;
}
break;
case V_71 :
switch ( V_6 -> V_109 ) {
case V_152 :
case V_106 :
F_49 ( V_146 , & V_2 -> V_147 ) ;
F_49 ( V_149 , & V_2 -> V_147 ) ;
break;
default:
goto V_177;
}
break;
case V_112 :
switch ( V_6 -> V_109 ) {
case V_152 :
case V_114 :
F_43 ( V_146 , & V_2 -> V_147 ) ;
break;
default:
goto V_177;
}
break;
default:
goto V_177;
}
F_59 ( V_6 -> V_7 ) ;
F_60 ( & V_2 -> V_110 ) ;
V_177:
return V_173 ;
}
static int F_92 ( struct V_1 * V_2 )
{
V_180 = F_93 ( L_65 , NULL ) ;
if ( ! V_180 || F_3 ( V_180 ) )
return - V_26 ;
V_181 = F_94 ( L_66 , V_182 | V_183 ,
V_180 , V_2 , & V_184 ) ;
if ( ! V_181 ) {
F_95 ( V_180 ) ;
V_180 = NULL ;
return - V_26 ;
}
return 0 ;
}
static void F_96 ( void )
{
F_95 ( V_181 ) ;
F_95 ( V_180 ) ;
}
static int T_7 F_97 ( struct V_185 * V_186 )
{
int V_4 = 0 ;
struct V_187 * V_188 ;
struct V_1 * V_2 ;
struct V_31 * V_6 ;
F_33 ( & V_186 -> V_7 , L_67 ) ;
if ( ! V_186 -> V_7 . V_189 ) {
F_4 ( & V_186 -> V_7 , L_68 ) ;
return - V_26 ;
}
V_2 = F_98 ( sizeof( struct V_1 ) , V_190 ) ;
if ( ! V_2 ) {
F_4 ( & V_186 -> V_7 , L_69 ) ;
return - V_191 ;
}
V_2 -> V_42 = V_186 -> V_7 . V_189 ;
V_6 = & V_2 -> V_6 ;
V_6 -> V_7 = & V_186 -> V_7 ;
V_2 -> V_48 = F_99 ( & V_186 -> V_7 , L_70 ) ;
if ( F_3 ( V_2 -> V_48 ) ) {
F_4 ( & V_186 -> V_7 , L_71 ) ;
V_4 = F_5 ( V_2 -> V_48 ) ;
goto V_192;
}
V_2 -> V_45 = F_99 ( & V_186 -> V_7 , L_72 ) ;
if ( F_3 ( V_2 -> V_45 ) ) {
F_4 ( & V_186 -> V_7 , L_73 ) ;
V_4 = F_5 ( V_2 -> V_45 ) ;
goto V_193;
}
F_100 ( V_2 -> V_45 , 60000000 ) ;
if ( V_2 -> V_42 -> V_194 ) {
V_2 -> V_91 = F_99 ( & V_186 -> V_7 ,
V_2 -> V_42 -> V_194 ) ;
if ( F_3 ( V_2 -> V_91 ) )
goto V_195;
F_100 ( V_2 -> V_91 , V_196 ) ;
F_47 ( V_2 -> V_91 ) ;
} else
V_2 -> V_91 = F_101 ( - V_197 ) ;
V_2 -> V_89 = F_99 ( & V_186 -> V_7 , L_74 ) ;
if ( F_3 ( V_2 -> V_89 ) ) {
F_4 ( & V_186 -> V_7 , L_75 ) ;
V_4 = F_5 ( V_2 -> V_89 ) ;
goto V_198;
}
V_2 -> V_90 = F_99 ( & V_186 -> V_7 , L_76 ) ;
if ( F_3 ( V_2 -> V_90 ) )
V_2 -> V_90 = NULL ;
V_188 = F_102 ( V_186 , V_199 , 0 ) ;
if ( ! V_188 ) {
F_4 ( & V_186 -> V_7 , L_77 ) ;
V_4 = - V_26 ;
goto V_200;
}
V_2 -> V_201 = F_103 ( V_188 -> V_202 , F_104 ( V_188 ) ) ;
if ( ! V_2 -> V_201 ) {
F_4 ( & V_186 -> V_7 , L_78 ) ;
V_4 = - V_191 ;
goto V_200;
}
F_33 ( & V_186 -> V_7 , L_79 , V_2 -> V_201 ) ;
V_2 -> V_78 = F_105 ( V_186 , 0 ) ;
if ( ! V_2 -> V_78 ) {
F_4 ( & V_186 -> V_7 , L_80 ) ;
V_4 = - V_26 ;
goto V_203;
}
F_47 ( V_2 -> V_45 ) ;
F_47 ( V_2 -> V_89 ) ;
V_4 = F_1 ( V_2 , 1 ) ;
if ( V_4 ) {
F_4 ( & V_186 -> V_7 , L_81 ) ;
goto V_203;
}
V_4 = F_10 ( V_2 , 1 ) ;
if ( V_4 ) {
F_4 ( & V_186 -> V_7 , L_82 ) ;
goto V_204;
}
V_4 = F_14 ( 1 ) ;
if ( V_4 ) {
F_4 ( & V_186 -> V_7 , L_83 ) ;
goto V_205;
}
if ( V_2 -> V_90 )
F_47 ( V_2 -> V_90 ) ;
F_18 ( 0 , V_206 ) ;
F_18 ( 0 , V_64 ) ;
F_106 ( & V_2 -> V_110 , F_77 ) ;
F_107 ( & V_2 -> V_124 , F_74 ) ;
V_4 = F_108 ( V_2 -> V_78 , F_81 , V_107 ,
L_65 , V_2 ) ;
if ( V_4 ) {
F_4 ( & V_186 -> V_7 , L_84 ) ;
goto V_207;
}
V_6 -> V_3 = F_34 ;
V_6 -> V_208 = F_58 ;
V_6 -> V_209 = F_64 ;
V_6 -> V_210 = F_52 ;
V_6 -> V_211 = & V_212 ;
V_4 = F_109 ( & V_2 -> V_6 ) ;
if ( V_4 ) {
F_4 ( & V_186 -> V_7 , L_85 ) ;
goto V_213;
}
F_110 ( V_186 , V_2 ) ;
F_111 ( & V_186 -> V_7 , 1 ) ;
if ( V_2 -> V_42 -> V_65 == V_66 &&
V_2 -> V_42 -> V_62 == V_150 ) {
V_4 = F_92 ( V_2 ) ;
if ( V_4 )
F_54 ( & V_186 -> V_7 , L_86
L_87 ) ;
}
F_112 ( & V_186 -> V_7 ) ;
F_113 ( & V_186 -> V_7 ) ;
return 0 ;
V_213:
V_213 ( V_2 -> V_78 , V_2 ) ;
V_207:
F_40 ( V_2 -> V_89 ) ;
F_40 ( V_2 -> V_45 ) ;
V_205:
F_10 ( V_2 , 0 ) ;
V_204:
F_1 ( V_2 , 0 ) ;
V_203:
F_114 ( V_2 -> V_201 ) ;
V_200:
if ( V_2 -> V_90 )
F_115 ( V_2 -> V_90 ) ;
F_115 ( V_2 -> V_89 ) ;
V_198:
if ( ! F_3 ( V_2 -> V_91 ) ) {
F_40 ( V_2 -> V_91 ) ;
F_115 ( V_2 -> V_91 ) ;
}
V_195:
F_115 ( V_2 -> V_45 ) ;
V_193:
F_115 ( V_2 -> V_48 ) ;
V_192:
F_116 ( V_2 ) ;
return V_4 ;
}
static int T_8 F_117 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_118 ( V_186 ) ;
struct V_31 * V_6 = & V_2 -> V_6 ;
int V_33 = 0 ;
if ( V_6 -> V_76 || V_6 -> V_113 )
return - V_214 ;
F_96 () ;
F_79 ( & V_2 -> V_124 ) ;
F_119 ( & V_2 -> V_110 ) ;
F_120 ( & V_186 -> V_7 ) ;
F_111 ( & V_186 -> V_7 , 0 ) ;
F_121 ( & V_186 -> V_7 ) ;
F_109 ( NULL ) ;
V_213 ( V_2 -> V_78 , V_2 ) ;
F_16 ( V_6 , 0x14 ) ;
F_23 ( V_6 , 0x08 , 0x09 ) ;
F_18 ( F_20 ( V_50 ) | V_81 , V_50 ) ;
while ( V_33 < V_82 ) {
if ( F_20 ( V_50 ) & V_81 )
break;
F_21 ( 1 ) ;
V_33 ++ ;
}
if ( V_33 >= V_82 )
F_4 ( V_6 -> V_7 , L_37 ) ;
F_40 ( V_2 -> V_89 ) ;
F_40 ( V_2 -> V_45 ) ;
if ( V_2 -> V_90 )
F_40 ( V_2 -> V_90 ) ;
if ( ! F_3 ( V_2 -> V_91 ) ) {
F_40 ( V_2 -> V_91 ) ;
F_115 ( V_2 -> V_91 ) ;
}
F_10 ( V_2 , 0 ) ;
F_114 ( V_2 -> V_201 ) ;
F_122 ( & V_186 -> V_7 ) ;
F_115 ( V_2 -> V_48 ) ;
F_115 ( V_2 -> V_89 ) ;
F_115 ( V_2 -> V_45 ) ;
if ( V_2 -> V_90 )
F_115 ( V_2 -> V_90 ) ;
F_116 ( V_2 ) ;
return 0 ;
}
static int F_123 ( struct V_215 * V_7 )
{
struct V_1 * V_2 = F_124 ( V_7 ) ;
struct V_31 * V_6 = & V_2 -> V_6 ;
F_54 ( V_7 , L_88 ) ;
if ( V_6 -> V_109 != V_108 )
F_125 ( V_7 , 1000 ) ;
return - V_216 ;
}
static int F_126 ( struct V_215 * V_7 )
{
struct V_1 * V_2 = F_124 ( V_7 ) ;
F_54 ( V_7 , L_89 ) ;
return F_36 ( V_2 ) ;
}
static int F_127 ( struct V_215 * V_7 )
{
struct V_1 * V_2 = F_124 ( V_7 ) ;
F_54 ( V_7 , L_90 ) ;
return F_46 ( V_2 ) ;
}
static int F_128 ( struct V_215 * V_7 )
{
struct V_1 * V_2 = F_124 ( V_7 ) ;
F_54 ( V_7 , L_91 ) ;
return F_36 ( V_2 ) ;
}
static int F_129 ( struct V_215 * V_7 )
{
struct V_1 * V_2 = F_124 ( V_7 ) ;
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
static int T_7 F_130 ( void )
{
return F_131 ( & V_217 , F_97 ) ;
}
static void T_9 F_132 ( void )
{
F_133 ( & V_217 ) ;
}
