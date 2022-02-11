static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_7 + ( V_6 * V_8 ) + V_4 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_4 )
{
return F_4 ( V_2 -> V_7 + ( V_6 * V_8 ) + V_4 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_6 , V_9 ) ;
V_4 &= ~ V_10 ;
F_5 ( V_2 , V_6 , V_4 , V_9 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_6 , V_9 ) ;
V_4 |= V_10 ;
F_5 ( V_2 , V_6 , V_4 , V_9 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_3 ( V_2 , V_11 ) ;
V_4 &= ~ V_12 ;
F_1 ( V_2 , V_4 , V_11 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_3 ( V_2 , V_11 ) ;
V_4 |= V_12 ;
F_1 ( V_2 , V_4 , V_11 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
int V_13 ;
T_1 V_4 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ ) {
V_4 = F_6 ( V_2 , V_13 , V_9 ) ;
V_4 |= V_15 ;
F_5 ( V_2 , V_13 , V_4 , V_9 ) ;
V_4 &= ~ V_15 ;
F_5 ( V_2 , V_13 , V_4 , V_9 ) ;
}
}
static int F_12 ( struct V_16 * V_17 , int V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
switch ( V_18 ) {
case V_21 :
case V_22 :
case V_23 :
F_10 ( V_2 ) ;
break;
case V_24 :
case V_25 :
case V_26 :
F_9 ( V_2 ) ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_28 , unsigned int V_29 ,
unsigned int * V_30 ,
unsigned int * V_31 )
{
unsigned int V_32 , V_33 ;
V_32 = V_28 * V_29 ;
V_33 = F_15 ( V_2 -> V_34 ) ;
if ( V_33 >= V_32 * 8 ) {
* V_30 = 1 ;
* V_31 = 0 ;
} else if ( V_33 >= V_32 * 7 ) {
* V_30 = 1 ;
* V_31 = 1 ;
} else if ( V_33 >= V_32 * 6 ) {
* V_30 = 0 ;
* V_31 = 0 ;
} else {
F_16 ( V_2 -> V_35 ,
L_1 ,
V_33 , V_28 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_36 * V_37 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
unsigned int V_38 , V_39 , V_40 , V_29 ;
unsigned int V_30 , V_31 ;
int V_13 , V_41 = 0 ;
T_1 V_4 , V_42 , V_43 ;
T_1 V_44 = 0 , V_45 = 0 ;
T_2 V_46 ;
V_38 = F_18 ( V_37 ) ;
V_46 = F_19 ( V_37 ) ;
V_39 = F_20 ( V_37 ) ;
V_40 = V_39 / 2 ;
switch ( V_46 ) {
case V_47 :
V_29 = 64 ;
V_45 |= V_48 ;
V_45 |= V_49 ;
V_45 |= V_50 ;
break;
case V_51 :
V_29 = 64 ;
V_45 |= V_48 ;
V_45 |= V_49 ;
break;
case V_52 :
V_29 = 32 ;
V_44 |= V_53 ;
V_45 |= V_54 ;
break;
default:
return - V_27 ;
}
if ( ( V_39 < 2 ) ||
( V_39 > ( V_2 -> V_55 * 2 ) ) ||
( V_39 % 2 ) )
return - V_27 ;
V_44 |= ( ( V_40 - 1 ) << V_56 ) ;
V_41 = F_14 ( V_2 , V_38 , V_29 ,
& V_30 , & V_31 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_30 )
V_45 |= V_57 ;
if ( V_31 )
V_45 |= V_58 ;
V_42 = V_53 |
V_59 ;
V_43 = V_54 |
V_57 |
V_58 |
V_48 |
V_49 |
V_50 ;
V_4 = F_3 ( V_2 , V_11 ) ;
V_4 = ( V_4 & ~ V_42 ) | V_44 ;
F_1 ( V_2 , V_4 , V_11 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ )
F_7 ( V_2 , V_13 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_55 ; V_13 ++ ) {
V_4 = F_6 ( V_2 , V_13 , V_9 ) ;
V_4 = ( V_4 & ~ V_43 ) | V_45 ;
F_5 ( V_2 , V_13 , V_4 , V_9 ) ;
}
V_2 -> V_14 = V_40 ;
F_11 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ )
F_8 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , unsigned int V_60 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
int V_13 ;
T_1 V_43 , V_61 = 0 , V_62 = 0 , V_45 = 0 ;
T_1 V_4 ;
switch ( V_60 & V_63 ) {
case V_64 :
V_61 |= V_65 ;
break;
case V_66 :
break;
case V_67 :
V_61 |= V_65 ;
V_62 |= V_68 ;
break;
case V_69 :
V_62 |= V_68 ;
break;
default:
return - V_27 ;
}
switch ( V_60 & V_70 ) {
case V_71 :
V_45 |= V_72 ;
break;
case V_73 :
break;
default:
return - V_27 ;
}
switch ( V_60 & V_74 ) {
case V_75 :
break;
default:
return - V_27 ;
}
V_43 = V_72 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ )
F_7 ( V_2 , V_13 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_55 ; V_13 ++ ) {
V_4 = F_6 ( V_2 , V_13 , V_9 ) ;
V_4 = ( V_4 & ~ V_43 ) | V_45 ;
F_5 ( V_2 , V_13 , V_4 , V_9 ) ;
V_4 = ( V_4 & ~ V_68 ) | V_62 ;
F_5 ( V_2 , V_13 , V_4 , V_9 ) ;
V_4 = ( V_4 & ~ V_65 ) | V_61 ;
F_5 ( V_2 , V_13 , V_4 , V_9 ) ;
}
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ )
F_8 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
F_23 ( V_20 , NULL , & V_2 -> V_76 ) ;
return 0 ;
}
static int F_24 ( struct V_16 * V_77 ,
struct V_36 * V_37 , struct V_78 * V_79 )
{
unsigned int V_40 = F_20 ( V_37 ) / 2 ;
struct V_80 * V_81 = V_77 -> V_82 ;
struct V_83 * V_76 ;
int V_41 ;
V_76 = F_25 ( V_81 -> V_84 , V_77 ) ;
V_41 = F_26 ( V_77 , V_37 , V_79 ) ;
if ( V_41 )
return V_41 ;
V_79 -> V_85 = V_76 -> V_86 ;
V_79 -> V_87 = V_76 -> V_88 ;
V_79 -> V_89 = 4 * V_40 ;
return 0 ;
}
static int F_27 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
struct V_92 * V_93 ;
void T_3 * V_5 ;
int V_41 , V_13 ;
struct V_94 * V_95 ;
unsigned int V_96 ;
struct V_97 * V_35 = & V_91 -> V_35 ;
V_2 = F_28 ( V_35 , sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
F_29 ( V_91 , V_2 ) ;
V_2 -> V_35 = V_35 ;
V_93 = F_30 ( V_91 , V_100 , 0 ) ;
V_5 = F_31 ( V_35 , V_93 ) ;
if ( F_32 ( V_5 ) )
return F_33 ( V_5 ) ;
V_2 -> V_5 = V_5 ;
if ( F_34 ( V_91 -> V_35 . V_101 , L_2 ,
& V_2 -> V_55 ) ) {
F_16 ( V_35 , L_3 ) ;
return - V_27 ;
}
V_96 = 1 << F_35 ( V_2 -> V_55 ) ;
V_2 -> V_7 = V_5 + ( V_96 * 0x20 ) ;
V_2 -> V_34 = F_36 ( V_35 , L_4 ) ;
if ( F_32 ( V_2 -> V_34 ) ) {
if ( F_33 ( V_2 -> V_34 ) != - V_102 )
F_16 ( V_35 , L_5 ) ;
return F_33 ( V_2 -> V_34 ) ;
}
V_41 = F_37 ( V_2 -> V_34 ) ;
if ( V_41 )
return V_41 ;
V_2 -> V_14 = 1 ;
V_2 -> V_76 . V_86 = V_93 -> V_103 + V_104 ;
V_2 -> V_76 . V_88 = 4 ;
V_2 -> V_105 . V_106 = F_22 ;
V_2 -> V_105 . V_107 . V_108 = 2 ;
V_2 -> V_105 . V_107 . V_109 = V_2 -> V_55 * 2 ;
V_2 -> V_105 . V_107 . V_110 = V_111 ;
V_2 -> V_105 . V_107 . V_112 = V_113 |
V_114 | V_115 ;
V_2 -> V_105 . V_116 = & V_117 ;
V_95 = F_38 ( V_35 , L_6 ) ;
if ( F_32 ( V_95 ) ) {
if ( F_33 ( V_95 ) == - V_102 ) {
V_41 = - V_102 ;
goto V_118;
}
F_39 ( V_35 , L_7 ) ;
F_9 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_55 ; V_13 ++ )
F_7 ( V_2 , V_13 ) ;
} else {
F_40 ( V_95 ) ;
F_41 ( V_95 ) ;
}
F_1 ( V_2 , 0 , V_11 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_55 ; V_13 ++ )
F_5 ( V_2 , V_13 ,
( 4 << V_119 ) |
V_120 |
V_49 , V_9 ) ;
V_41 = F_42 ( V_35 , & V_121 ,
& V_2 -> V_105 , 1 ) ;
if ( V_41 )
goto V_118;
V_41 = F_43 ( V_35 , & V_122 , 0 ) ;
if ( V_41 )
goto V_118;
return 0 ;
V_118:
F_44 ( V_2 -> V_34 ) ;
return V_41 ;
}
static int F_45 ( struct V_90 * V_91 )
{
struct V_1 * V_2 = F_46 ( V_91 ) ;
F_44 ( V_2 -> V_34 ) ;
return 0 ;
}
