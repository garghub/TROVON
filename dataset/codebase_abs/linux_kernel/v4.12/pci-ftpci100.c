static int F_1 ( T_1 V_1 ,
T_1 V_2 , T_2 * V_3 )
{
T_2 V_4 ;
switch ( V_2 ) {
case V_5 :
V_4 = V_6 ;
break;
case V_7 :
V_4 = V_8 ;
break;
case V_9 :
V_4 = V_10 ;
break;
case V_11 :
V_4 = V_12 ;
break;
case V_13 :
V_4 = V_14 ;
break;
case V_15 :
V_4 = V_16 ;
break;
case V_17 :
V_4 = V_18 ;
break;
case V_19 :
V_4 = V_20 ;
break;
case V_21 :
V_4 = V_22 ;
break;
case V_23 :
V_4 = V_24 ;
break;
case V_25 :
V_4 = V_26 ;
break;
case V_27 :
V_4 = V_28 ;
break;
default:
return - V_29 ;
}
V_4 <<= V_30 ;
if ( V_1 & ~ ( V_31 ) )
F_2 ( L_1 ) ;
V_4 |= ( V_1 & V_31 ) ;
F_3 ( L_2 ,
& V_1 , & V_2 , V_4 ) ;
* V_3 = V_4 ;
return 0 ;
}
static int F_4 ( struct V_32 * V_33 , unsigned int V_34 ,
int V_35 , int V_36 , T_2 * V_37 )
{
struct V_38 * V_39 = V_33 -> V_40 ;
F_5 ( F_6 ( V_33 -> V_41 ) |
F_7 ( F_8 ( V_34 ) ) |
F_9 ( F_10 ( V_34 ) ) |
F_11 ( V_35 ) |
V_42 ,
V_39 -> V_43 + V_44 ) ;
* V_37 = F_12 ( V_39 -> V_43 + V_45 ) ;
if ( V_36 == 1 )
* V_37 = ( * V_37 >> ( 8 * ( V_35 & 3 ) ) ) & 0xFF ;
else if ( V_36 == 2 )
* V_37 = ( * V_37 >> ( 8 * ( V_35 & 3 ) ) ) & 0xFFFF ;
F_13 ( & V_33 -> V_46 ,
L_3 ,
F_8 ( V_34 ) , F_10 ( V_34 ) , V_35 , V_36 , * V_37 ) ;
return V_47 ;
}
static int F_14 ( struct V_32 * V_33 , unsigned int V_34 ,
int V_35 , int V_36 , T_2 V_37 )
{
struct V_38 * V_39 = V_33 -> V_40 ;
int V_48 = V_47 ;
F_13 ( & V_33 -> V_46 ,
L_4 ,
F_8 ( V_34 ) , F_10 ( V_34 ) , V_35 , V_36 , V_37 ) ;
F_5 ( F_6 ( V_33 -> V_41 ) |
F_7 ( F_8 ( V_34 ) ) |
F_9 ( F_10 ( V_34 ) ) |
F_11 ( V_35 ) |
V_42 ,
V_39 -> V_43 + V_44 ) ;
switch ( V_36 ) {
case 4 :
F_5 ( V_37 , V_39 -> V_43 + V_45 ) ;
break;
case 2 :
F_15 ( V_37 , V_39 -> V_43 + V_45 + ( V_35 & 3 ) ) ;
break;
case 1 :
F_16 ( V_37 , V_39 -> V_43 + V_45 + ( V_35 & 3 ) ) ;
break;
default:
V_48 = V_49 ;
}
return V_48 ;
}
static void F_17 ( struct V_50 * V_51 )
{
struct V_38 * V_39 = F_18 ( V_51 ) ;
unsigned int V_52 ;
F_4 ( V_39 -> V_33 , 0 , V_53 , 4 , & V_52 ) ;
V_52 &= ~ ( 0xF << V_54 ) ;
V_52 |= F_19 ( F_20 ( V_51 ) + V_54 ) ;
F_14 ( V_39 -> V_33 , 0 , V_53 , 4 , V_52 ) ;
}
static void F_21 ( struct V_50 * V_51 )
{
struct V_38 * V_39 = F_18 ( V_51 ) ;
unsigned int V_52 ;
F_4 ( V_39 -> V_33 , 0 , V_53 , 4 , & V_52 ) ;
V_52 &= ~ ( ( 0xF << V_54 )
| F_19 ( F_20 ( V_51 ) + V_55 ) ) ;
F_14 ( V_39 -> V_33 , 0 , V_53 , 4 , V_52 ) ;
}
static void F_22 ( struct V_50 * V_51 )
{
struct V_38 * V_39 = F_18 ( V_51 ) ;
unsigned int V_52 ;
F_4 ( V_39 -> V_33 , 0 , V_53 , 4 , & V_52 ) ;
V_52 &= ~ ( 0xF << V_54 ) ;
V_52 |= F_19 ( F_20 ( V_51 ) + V_55 ) ;
F_14 ( V_39 -> V_33 , 0 , V_53 , 4 , V_52 ) ;
}
static void F_23 ( struct V_56 * V_57 )
{
struct V_38 * V_39 = F_24 ( V_57 ) ;
struct V_58 * V_59 = F_25 ( V_57 ) ;
unsigned int V_60 , V_52 , V_61 ;
F_4 ( V_39 -> V_33 , 0 , V_53 , 4 , & V_52 ) ;
V_60 = V_52 >> V_54 ;
F_26 ( V_59 , V_57 ) ;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
if ( ( V_60 & F_19 ( V_61 ) ) == 0 )
continue;
F_27 ( F_28 ( V_39 -> V_62 , V_61 ) ) ;
}
F_29 ( V_59 , V_57 ) ;
}
static int F_30 ( struct V_63 * V_64 , unsigned int V_65 ,
T_3 V_66 )
{
F_31 ( V_65 , & V_67 , V_68 ) ;
F_32 ( V_65 , V_64 -> V_69 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
struct V_70 * V_71 = F_34 ( V_39 -> V_46 -> V_72 , NULL ) ;
int V_65 ;
int V_61 ;
if ( ! V_71 ) {
F_35 ( V_39 -> V_46 , L_5 ) ;
return - V_29 ;
}
V_65 = F_36 ( V_71 , 0 ) ;
if ( ! V_65 ) {
F_35 ( V_39 -> V_46 , L_6 ) ;
return - V_29 ;
}
V_39 -> V_62 = F_37 ( V_71 , 4 ,
& V_73 , V_39 ) ;
if ( ! V_39 -> V_62 ) {
F_35 ( V_39 -> V_46 , L_7 ) ;
return - V_29 ;
}
F_38 ( V_65 , F_23 , V_39 ) ;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ )
F_39 ( V_39 -> V_62 , V_61 ) ;
return 0 ;
}
static int F_40 ( struct V_74 * V_75 ,
struct V_70 * V_76 )
{
const int V_77 = 3 , V_78 = 2 ;
int V_79 ;
V_75 -> V_76 = V_76 ;
V_75 -> V_80 = F_41 ( V_76 ) ;
V_75 -> V_81 = V_75 -> V_80 + V_77 + V_78 ;
V_75 -> V_82 = F_42 ( V_76 , L_8 , & V_79 ) ;
if ( ! V_75 -> V_82 )
return - V_83 ;
V_75 -> V_84 = V_75 -> V_82 + V_79 / sizeof( V_85 ) ;
return 0 ;
}
static int F_43 ( struct V_38 * V_39 ,
struct V_70 * V_81 )
{
struct V_86 V_82 ;
struct V_74 V_75 ;
struct V_87 * V_46 = V_39 -> V_46 ;
T_2 V_88 [ 3 ] = {
V_89 ,
V_90 ,
V_91 ,
} ;
int V_61 = 0 ;
T_2 V_3 ;
if ( F_40 ( & V_75 , V_81 ) ) {
F_35 ( V_46 , L_9 ) ;
return - V_29 ;
}
F_44 (&parser, &range) {
T_4 V_84 = V_82 . V_92 + V_82 . V_36 - 1 ;
int V_48 ;
V_48 = F_1 ( V_82 . V_92 , V_82 . V_36 , & V_3 ) ;
if ( V_48 ) {
F_35 ( V_46 ,
L_10 , V_61 ) ;
return - V_29 ;
}
F_45 ( V_46 , L_11 ,
V_61 + 1 , V_82 . V_92 , V_84 , V_3 ) ;
if ( V_61 <= 2 ) {
F_14 ( V_39 -> V_33 , 0 , V_88 [ V_61 ] ,
4 , V_3 ) ;
} else {
F_35 ( V_46 , L_12 , V_61 ) ;
break;
}
V_61 ++ ;
}
return 0 ;
}
static int F_46 ( struct V_93 * V_94 )
{
struct V_87 * V_46 = & V_94 -> V_46 ;
const struct V_95 * V_96 =
F_47 ( V_46 ) ;
struct V_97 * V_98 ;
T_1 V_99 ;
struct V_100 * V_101 ;
struct V_38 * V_39 ;
struct V_97 * V_102 ;
struct V_97 * V_103 ;
struct V_104 * V_105 ;
int V_48 ;
T_2 V_3 ;
F_48 ( V_106 ) ;
V_105 = F_49 ( sizeof( * V_39 ) ) ;
if ( ! V_105 )
return - V_107 ;
V_105 -> V_46 . V_108 = V_46 ;
V_105 -> V_109 = & V_110 ;
V_105 -> V_111 = 0 ;
V_105 -> V_112 = NULL ;
V_39 = F_50 ( V_105 ) ;
V_105 -> V_40 = V_39 ;
V_39 -> V_46 = V_46 ;
V_98 = F_51 ( V_94 , V_113 , 0 ) ;
V_39 -> V_43 = F_52 ( V_46 , V_98 ) ;
if ( F_53 ( V_39 -> V_43 ) )
return F_54 ( V_39 -> V_43 ) ;
V_48 = F_55 ( V_46 -> V_72 , 0 , 0xff ,
& V_106 , & V_99 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_56 ( V_46 , & V_106 ) ;
if ( V_48 )
return V_48 ;
F_57 (win, &res) {
switch ( F_58 ( V_101 -> V_106 ) ) {
case V_114 :
V_103 = V_101 -> V_106 ;
V_103 -> V_115 = L_13 ;
if ( ! F_1 ( V_103 -> V_116 - V_101 -> V_117 ,
F_59 ( V_103 ) , & V_3 ) ) {
F_5 ( V_3 , V_39 -> V_43 + V_118 ) ;
} else {
F_35 ( V_46 , L_14 ) ;
return - V_29 ;
}
V_48 = F_60 ( V_103 , V_99 ) ;
if ( V_48 ) {
F_61 ( V_46 , L_15 ,
V_48 , V_103 ) ;
continue;
}
break;
case V_113 :
V_102 = V_101 -> V_106 ;
V_102 -> V_115 = L_16 ;
break;
case V_119 :
break;
default:
break;
}
}
V_3 = F_12 ( V_39 -> V_43 + V_120 ) ;
V_3 |= V_121 ;
V_3 |= V_122 ;
V_3 |= V_123 ;
F_5 ( V_3 , V_39 -> V_43 + V_120 ) ;
F_62 ( & V_106 , & V_105 -> V_124 ) ;
V_48 = F_63 ( V_105 ) ;
if ( V_48 ) {
F_35 ( V_46 , L_17 , V_48 ) ;
return V_48 ;
}
V_39 -> V_33 = V_105 -> V_33 ;
F_14 ( V_39 -> V_33 , 0 , V_53 + 2 , 2 , 0xF000 ) ;
if ( V_96 -> V_125 ) {
V_48 = F_33 ( V_39 ) ;
if ( V_48 ) {
F_35 ( V_46 , L_18 ) ;
return V_48 ;
}
}
V_48 = F_43 ( V_39 , V_46 -> V_72 ) ;
if ( V_48 )
return V_48 ;
F_64 ( V_39 -> V_33 ) ;
F_65 ( V_126 , V_127 ) ;
F_66 ( V_39 -> V_33 ) ;
F_67 ( V_39 -> V_33 ) ;
F_68 ( & V_106 ) ;
return 0 ;
}
