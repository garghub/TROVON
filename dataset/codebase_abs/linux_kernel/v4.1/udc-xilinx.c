static void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static unsigned int F_3 ( void T_1 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_6 ( V_3 , V_1 + V_2 ) ;
}
static unsigned int F_7 ( void T_1 * V_1 )
{
return F_8 ( V_1 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 [ V_9 ] ;
T_2 V_10 ;
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_7 -> V_2 ) |
V_12 ;
V_5 -> V_13 ( V_5 -> V_1 , V_7 -> V_2 , V_10 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_7 -> V_2 + V_14 , 0 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_15 , 1 ) ;
}
static void F_10 ( struct V_6 * V_8 , struct V_4 * V_5 )
{
T_2 V_10 ;
V_10 = ( ( V_8 -> V_16 << 29 ) | ( V_8 -> V_17 << 28 ) |
( V_8 -> V_18 . V_19 << 15 ) | ( V_8 -> V_20 ) ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_10 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 + V_14 ,
V_8 -> V_21 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 + V_22 ,
V_8 -> V_23 ) ;
if ( V_8 -> V_24 )
V_5 -> V_13 ( V_5 -> V_1 , V_15 ,
1 << V_8 -> V_25 ) ;
if ( V_8 -> V_26 )
V_5 -> V_13 ( V_5 -> V_1 , V_15 ,
1 << ( V_8 -> V_25 + V_27 ) ) ;
}
static int F_11 ( struct V_6 * V_8 , T_3 V_28 ,
T_3 V_29 , T_2 V_30 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
int V_31 = 0 ;
T_2 V_32 = 500 ;
T_2 V_33 ;
V_5 -> V_13 ( V_5 -> V_1 , V_34 , V_28 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_35 , V_29 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_36 , V_30 ) ;
do {
V_33 = V_5 -> V_11 ( V_5 -> V_1 + V_37 ) ;
if ( ! ( V_33 & V_38 ) )
break;
V_32 -- ;
if ( ! V_32 ) {
F_12 ( V_5 -> V_39 , L_1 ) ;
return - V_40 ;
}
F_13 ( 1 ) ;
} while ( 1 );
if ( ( V_5 -> V_11 ( V_5 -> V_1 + V_37 ) &
V_41 ) == V_41 ) {
F_12 ( V_5 -> V_39 , L_2 ) ;
V_31 = - V_42 ;
}
return V_31 ;
}
static int F_14 ( struct V_6 * V_8 , struct V_43 * V_44 ,
T_4 * V_45 , T_2 V_30 )
{
T_2 * V_46 ;
T_3 V_28 ;
T_3 V_29 ;
struct V_4 * V_5 = V_8 -> V_5 ;
V_28 = V_44 -> V_47 . V_48 + V_44 -> V_47 . V_49 ;
if ( V_44 -> V_47 . V_30 )
F_15 ( V_5 -> V_39 , V_28 ,
V_30 , V_50 ) ;
if ( ! V_8 -> V_51 && ! V_8 -> V_24 ) {
V_46 = ( T_2 V_52 * ) ( V_5 -> V_1 + V_8 -> V_20 ) ;
V_29 = F_16 ( V_46 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 +
V_14 , V_30 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_53 ,
V_54 | ( 1 << V_8 -> V_25 ) ) ;
V_8 -> V_24 = 1 ;
V_8 -> V_51 = 1 ;
} else if ( V_8 -> V_51 && ! V_8 -> V_26 ) {
V_46 = ( T_2 V_52 * ) ( V_5 -> V_1 + V_8 -> V_20 +
V_8 -> V_18 . V_19 ) ;
V_29 = F_16 ( V_46 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 +
V_22 , V_30 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_53 ,
V_54 | ( 1 << ( V_8 -> V_25 +
V_27 ) ) ) ;
V_8 -> V_26 = 1 ;
V_8 -> V_51 = 0 ;
} else {
return - V_55 ;
}
return F_11 ( V_8 , V_28 , V_29 , V_30 ) ;
}
static int F_17 ( struct V_6 * V_8 , struct V_43 * V_44 ,
T_4 * V_45 , T_2 V_30 )
{
T_2 * V_46 ;
T_3 V_28 ;
T_3 V_29 ;
struct V_4 * V_5 = V_8 -> V_5 ;
V_29 = V_44 -> V_47 . V_48 + V_44 -> V_47 . V_49 ;
if ( ! V_8 -> V_51 && ! V_8 -> V_24 ) {
V_46 = ( T_2 V_52 * ) ( V_5 -> V_1 + V_8 -> V_20 ) ;
V_28 = F_16 ( V_46 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_53 ,
V_54 | V_56 |
( 1 << V_8 -> V_25 ) ) ;
V_8 -> V_24 = 1 ;
V_8 -> V_51 = 1 ;
} else if ( V_8 -> V_51 && ! V_8 -> V_26 ) {
V_46 = ( T_2 V_52 * ) ( V_5 -> V_1 +
V_8 -> V_20 + V_8 -> V_18 . V_19 ) ;
V_28 = F_16 ( V_46 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_53 ,
V_54 | V_56 |
( 1 << ( V_8 -> V_25 +
V_27 ) ) ) ;
V_8 -> V_26 = 1 ;
V_8 -> V_51 = 0 ;
} else {
return - V_55 ;
}
return F_11 ( V_8 , V_28 , V_29 , V_30 ) ;
}
static int F_18 ( struct V_6 * V_8 , struct V_43 * V_44 ,
T_4 * V_57 , T_2 V_58 )
{
T_2 * V_46 ;
T_2 V_59 ;
int V_31 = 0 ;
struct V_4 * V_5 = V_8 -> V_5 ;
V_59 = V_58 ;
if ( V_5 -> V_60 ) {
if ( V_8 -> V_16 )
V_31 = F_14 ( V_8 , V_44 , V_57 , V_58 ) ;
else
V_31 = F_17 ( V_8 , V_44 , V_57 , V_58 ) ;
return V_31 ;
}
if ( ! V_8 -> V_51 && ! V_8 -> V_24 ) {
V_46 = ( T_2 V_52 * ) ( V_5 -> V_1 + V_8 -> V_20 ) ;
if ( V_8 -> V_16 ) {
memcpy ( V_46 , V_57 , V_59 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 +
V_14 , V_58 ) ;
} else {
memcpy ( V_57 , V_46 , V_59 ) ;
}
V_5 -> V_13 ( V_5 -> V_1 , V_15 ,
1 << V_8 -> V_25 ) ;
V_8 -> V_24 = 1 ;
V_8 -> V_51 = 1 ;
} else if ( V_8 -> V_51 && ! V_8 -> V_26 ) {
V_46 = ( T_2 V_52 * ) ( V_5 -> V_1 + V_8 -> V_20 +
V_8 -> V_18 . V_19 ) ;
if ( V_8 -> V_16 ) {
memcpy ( V_46 , V_57 , V_59 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 +
V_22 , V_58 ) ;
} else {
memcpy ( V_57 , V_46 , V_59 ) ;
}
V_5 -> V_13 ( V_5 -> V_1 , V_15 ,
1 << ( V_8 -> V_25 + V_27 ) ) ;
V_8 -> V_26 = 1 ;
V_8 -> V_51 = 0 ;
} else {
return - V_55 ;
}
return V_31 ;
}
static void F_19 ( struct V_6 * V_8 , struct V_43 * V_44 , int V_61 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
F_20 ( & V_44 -> V_62 ) ;
if ( V_44 -> V_47 . V_61 == - V_63 )
V_44 -> V_47 . V_61 = V_61 ;
else
V_61 = V_44 -> V_47 . V_61 ;
if ( V_61 && V_61 != - V_64 )
F_21 ( V_5 -> V_39 , L_3 ,
V_8 -> V_18 . V_65 , V_44 , V_61 ) ;
if ( V_5 -> V_60 && V_8 -> V_25 && V_44 -> V_47 . V_30 )
F_22 ( & V_5 -> V_66 , & V_44 -> V_47 ,
V_8 -> V_16 ) ;
if ( V_44 -> V_47 . V_67 ) {
F_23 ( & V_5 -> V_68 ) ;
V_44 -> V_47 . V_67 ( & V_8 -> V_18 , & V_44 -> V_47 ) ;
F_24 ( & V_5 -> V_68 ) ;
}
}
static int F_25 ( struct V_6 * V_8 , struct V_43 * V_44 )
{
T_4 * V_69 ;
T_2 V_70 , V_71 , V_72 ;
T_4 V_73 ;
T_4 V_74 = 0 ;
int V_75 ;
int V_76 = - V_55 ;
struct V_4 * V_5 = V_8 -> V_5 ;
if ( V_8 -> V_24 && V_8 -> V_26 ) {
F_21 ( V_5 -> V_39 , L_4 ) ;
return V_76 ;
}
V_77:
if ( V_8 -> V_51 )
V_73 = V_22 ;
else
V_73 = V_14 ;
V_71 = V_5 -> V_11 ( V_5 -> V_1 + V_8 -> V_2 + V_73 ) ;
if ( ! V_8 -> V_24 && ! V_8 -> V_26 )
V_74 = 1 ;
V_69 = V_44 -> V_47 . V_69 + V_44 -> V_47 . V_49 ;
F_26 ( V_69 ) ;
V_72 = V_44 -> V_47 . V_30 - V_44 -> V_47 . V_49 ;
V_70 = V_71 < V_8 -> V_18 . V_19 ;
if ( F_27 ( ! V_72 ) ) {
if ( V_44 -> V_47 . V_61 != - V_78 )
F_21 ( V_5 -> V_39 , L_5 ,
V_8 -> V_18 . V_65 , V_71 ) ;
V_44 -> V_47 . V_61 = - V_78 ;
F_19 ( V_8 , V_44 , - V_78 ) ;
return 0 ;
}
V_75 = F_18 ( V_8 , V_44 , V_69 , V_71 ) ;
switch ( V_75 ) {
case 0 :
V_44 -> V_47 . V_49 += F_28 ( V_71 , V_72 ) ;
F_21 ( V_5 -> V_39 , L_6 ,
V_8 -> V_18 . V_65 , V_71 , V_70 ? L_7 : L_8 , V_44 ,
V_44 -> V_47 . V_49 , V_44 -> V_47 . V_30 ) ;
V_72 -= V_71 ;
if ( ( V_44 -> V_47 . V_49 == V_44 -> V_47 . V_30 ) || V_70 ) {
if ( V_5 -> V_60 && V_44 -> V_47 . V_30 )
F_29 ( V_5 -> V_39 ,
V_44 -> V_47 . V_48 ,
V_44 -> V_47 . V_49 ,
V_79 ) ;
F_19 ( V_8 , V_44 , 0 ) ;
return 0 ;
}
if ( V_74 ) {
V_74 = 0 ;
goto V_77;
}
break;
case - V_55 :
F_21 ( V_5 -> V_39 , L_9 ) ;
break;
case - V_42 :
case - V_40 :
F_19 ( V_8 , V_44 , - V_80 ) ;
V_76 = 0 ;
break;
}
return V_76 ;
}
static int F_30 ( struct V_6 * V_8 , struct V_43 * V_44 )
{
T_2 V_81 ;
T_2 V_30 ;
int V_75 ;
int V_76 = - V_55 ;
struct V_4 * V_5 = V_8 -> V_5 ;
int V_82 , V_70 = 0 ;
T_4 * V_69 ;
V_81 = F_31 ( V_8 -> V_83 -> V_84 ) ;
V_69 = V_44 -> V_47 . V_69 + V_44 -> V_47 . V_49 ;
F_32 ( V_69 ) ;
V_30 = V_44 -> V_47 . V_30 - V_44 -> V_47 . V_49 ;
V_30 = F_28 ( V_30 , V_81 ) ;
V_75 = F_18 ( V_8 , V_44 , V_69 , V_30 ) ;
switch ( V_75 ) {
case 0 :
V_44 -> V_47 . V_49 += V_30 ;
if ( F_27 ( V_30 != V_81 ) ) {
V_82 = V_70 = 1 ;
} else {
if ( F_33 ( V_44 -> V_47 . V_30 !=
V_44 -> V_47 . V_49 ) || V_44 -> V_47 . V_85 )
V_82 = 0 ;
else
V_82 = 1 ;
}
F_21 ( V_5 -> V_39 , L_10 ,
V_86 , V_8 -> V_18 . V_65 , V_30 , V_82 ? L_11 : L_8 ,
V_70 ? L_7 : L_8 ,
V_44 -> V_47 . V_30 - V_44 -> V_47 . V_49 , V_44 ) ;
if ( V_82 ) {
F_19 ( V_8 , V_44 , 0 ) ;
V_76 = 0 ;
}
break;
case - V_55 :
F_21 ( V_5 -> V_39 , L_12 ) ;
break;
case - V_42 :
case - V_40 :
F_19 ( V_8 , V_44 , - V_80 ) ;
V_76 = 0 ;
break;
}
return V_76 ;
}
static void F_34 ( struct V_6 * V_8 , int V_61 )
{
struct V_43 * V_44 ;
while ( ! F_35 ( & V_8 -> V_62 ) ) {
V_44 = F_36 ( & V_8 -> V_62 , struct V_43 , V_62 ) ;
F_19 ( V_8 , V_44 , V_61 ) ;
}
}
static int F_37 ( struct V_87 * V_88 , int V_89 )
{
struct V_6 * V_8 = F_38 ( V_88 ) ;
struct V_4 * V_5 ;
unsigned long V_90 ;
T_2 V_10 ;
if ( ! V_88 || ( ! V_8 -> V_83 && V_8 -> V_25 ) ) {
F_39 ( L_13 , V_86 ) ;
return - V_42 ;
}
V_5 = V_8 -> V_5 ;
if ( V_8 -> V_16 && ( ! F_35 ( & V_8 -> V_62 ) ) && V_89 ) {
F_21 ( V_5 -> V_39 , L_14 ) ;
return - V_55 ;
}
if ( V_8 -> V_24 || V_8 -> V_26 ) {
F_21 ( V_5 -> V_39 , L_15 ) ;
return - V_55 ;
}
F_40 ( & V_5 -> V_68 , V_90 ) ;
if ( V_89 ) {
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_8 -> V_2 ) ;
V_10 |= V_91 ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_10 ) ;
} else {
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_8 -> V_2 ) ;
V_10 &= ~ V_91 ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_10 ) ;
if ( V_8 -> V_25 ) {
V_10 = V_5 -> V_11 ( V_8 -> V_5 -> V_1 + V_8 -> V_2 ) ;
V_10 &= ~ V_12 ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_10 ) ;
}
}
F_41 ( & V_5 -> V_68 , V_90 ) ;
return 0 ;
}
static int F_42 ( struct V_6 * V_8 ,
const struct V_92 * V_83 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
T_2 V_93 ;
T_2 V_94 ;
T_2 V_95 ;
T_5 V_19 ;
V_8 -> V_16 = ( ( V_83 -> V_96 & V_97 ) != 0 ) ;
V_8 -> V_25 = ( V_83 -> V_96 & 0x0f ) ;
V_8 -> V_83 = V_83 ;
V_8 -> V_18 . V_83 = V_83 ;
V_93 = V_83 -> V_98 & V_99 ;
V_8 -> V_18 . V_19 = V_19 = F_31 ( V_83 -> V_84 ) ;
switch ( V_93 ) {
case V_100 :
F_21 ( V_5 -> V_39 , L_16 ) ;
V_8 -> V_17 = 0 ;
return - V_42 ;
case V_101 :
V_8 -> V_17 = 0 ;
if ( V_19 > 64 ) {
F_21 ( V_5 -> V_39 , L_17 , V_19 ) ;
return - V_42 ;
}
break;
case V_102 :
V_8 -> V_17 = 0 ;
if ( ! ( F_43 ( V_19 ) && V_19 >= 8 &&
V_19 <= 512 ) ) {
F_21 ( V_5 -> V_39 , L_17 , V_19 ) ;
return - V_42 ;
}
break;
case V_103 :
V_8 -> V_17 = 1 ;
break;
}
V_8 -> V_24 = 0 ;
V_8 -> V_26 = 0 ;
V_8 -> V_51 = 0 ;
V_8 -> V_20 = V_20 [ V_8 -> V_25 ] ;
F_10 ( V_8 , V_5 ) ;
F_21 ( V_5 -> V_39 , L_18 ,
V_8 -> V_25 , V_19 ) ;
V_94 = V_5 -> V_11 ( V_5 -> V_1 + V_8 -> V_2 ) ;
V_94 |= V_104 ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_94 ) ;
if ( V_8 -> V_25 )
V_8 -> V_20 <<= 2 ;
V_95 = V_5 -> V_11 ( V_5 -> V_1 + V_105 ) ;
V_95 |= ( V_106 << V_8 -> V_25 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_95 ) ;
if ( V_8 -> V_25 && ! V_8 -> V_16 ) {
V_5 -> V_13 ( V_5 -> V_1 , V_15 ,
1 << V_8 -> V_25 ) ;
V_8 -> V_24 = 1 ;
V_5 -> V_13 ( V_5 -> V_1 , V_15 ,
( 1 << ( V_8 -> V_25 +
V_27 ) ) ) ;
V_8 -> V_26 = 1 ;
}
return 0 ;
}
static int F_44 ( struct V_87 * V_88 ,
const struct V_92 * V_83 )
{
struct V_6 * V_8 ;
struct V_4 * V_5 ;
unsigned long V_90 ;
int V_75 ;
if ( ! V_88 || ! V_83 || V_83 -> V_107 != V_108 ) {
F_39 ( L_13 , V_86 ) ;
return - V_42 ;
}
V_8 = F_38 ( V_88 ) ;
V_5 = V_8 -> V_5 ;
if ( ! V_5 -> V_109 || V_5 -> V_66 . V_110 == V_111 ) {
F_21 ( V_5 -> V_39 , L_19 ) ;
return - V_64 ;
}
F_40 ( & V_5 -> V_68 , V_90 ) ;
V_75 = F_42 ( V_8 , V_83 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return V_75 ;
}
static int F_45 ( struct V_87 * V_88 )
{
struct V_6 * V_8 ;
unsigned long V_90 ;
T_2 V_94 ;
struct V_4 * V_5 ;
if ( ! V_88 ) {
F_39 ( L_20 , V_86 ) ;
return - V_42 ;
}
V_8 = F_38 ( V_88 ) ;
V_5 = V_8 -> V_5 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
F_34 ( V_8 , - V_64 ) ;
V_8 -> V_83 = NULL ;
V_8 -> V_18 . V_83 = NULL ;
F_21 ( V_5 -> V_39 , L_21 , V_8 -> V_25 ) ;
V_94 = V_5 -> V_11 ( V_5 -> V_1 + V_8 -> V_2 ) ;
V_94 &= ~ V_104 ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_94 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return 0 ;
}
static struct V_112 * F_46 ( struct V_87 * V_88 ,
T_6 V_113 )
{
struct V_6 * V_8 = F_38 ( V_88 ) ;
struct V_4 * V_5 ;
struct V_43 * V_44 ;
V_5 = V_8 -> V_5 ;
V_44 = F_47 ( sizeof( * V_44 ) , V_113 ) ;
if ( ! V_44 ) {
F_12 ( V_5 -> V_39 , L_22 , V_86 ) ;
return NULL ;
}
V_44 -> V_8 = V_8 ;
F_48 ( & V_44 -> V_62 ) ;
return & V_44 -> V_47 ;
}
static void F_49 ( struct V_87 * V_88 , struct V_112 * V_114 )
{
struct V_43 * V_44 = F_50 ( V_114 ) ;
F_51 ( V_44 ) ;
}
static int F_52 ( struct V_6 * V_7 , struct V_43 * V_44 )
{
struct V_4 * V_5 = V_7 -> V_5 ;
T_2 V_30 ;
T_4 * V_115 ;
if ( ! V_5 -> V_109 || V_5 -> V_66 . V_110 == V_111 ) {
F_21 ( V_5 -> V_39 , L_23 , V_86 ) ;
return - V_42 ;
}
if ( ! F_35 ( & V_7 -> V_62 ) ) {
F_21 ( V_5 -> V_39 , L_24 , V_86 ) ;
return - V_116 ;
}
V_44 -> V_47 . V_61 = - V_63 ;
V_44 -> V_47 . V_49 = 0 ;
F_53 ( & V_44 -> V_62 , & V_7 -> V_62 ) ;
if ( V_5 -> V_117 . V_118 & V_97 ) {
F_32 ( V_44 -> V_47 . V_69 ) ;
V_30 = V_44 -> V_47 . V_30 ;
V_115 = ( void V_52 * ) ( ( V_7 -> V_20 << 2 ) +
V_5 -> V_1 ) ;
V_30 = V_44 -> V_47 . V_49 = F_54 ( T_2 , V_30 ,
V_119 ) ;
memcpy ( V_115 , V_44 -> V_47 . V_69 , V_30 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_14 , V_30 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_15 , 1 ) ;
} else {
if ( V_5 -> V_117 . V_120 ) {
V_5 -> V_13 ( V_5 -> V_1 , V_14 , 0 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_15 , 1 ) ;
} else {
F_9 ( V_5 ) ;
}
}
return 0 ;
}
static int F_55 ( struct V_87 * V_88 , struct V_112 * V_114 ,
T_6 V_113 )
{
struct V_43 * V_44 = F_50 ( V_114 ) ;
struct V_6 * V_7 = F_38 ( V_88 ) ;
struct V_4 * V_5 = V_7 -> V_5 ;
unsigned long V_90 ;
int V_75 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
V_75 = F_52 ( V_7 , V_44 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return V_75 ;
}
static int F_56 ( struct V_87 * V_88 , struct V_112 * V_114 ,
T_6 V_113 )
{
struct V_43 * V_44 = F_50 ( V_114 ) ;
struct V_6 * V_8 = F_38 ( V_88 ) ;
struct V_4 * V_5 = V_8 -> V_5 ;
int V_75 ;
unsigned long V_90 ;
if ( ! V_8 -> V_83 ) {
F_21 ( V_5 -> V_39 , L_25 ,
V_86 , V_8 -> V_65 ) ;
return - V_64 ;
}
if ( ! V_5 -> V_109 || V_5 -> V_66 . V_110 == V_111 ) {
F_21 ( V_5 -> V_39 , L_23 , V_86 ) ;
return - V_42 ;
}
F_40 ( & V_5 -> V_68 , V_90 ) ;
V_114 -> V_61 = - V_63 ;
V_114 -> V_49 = 0 ;
if ( V_5 -> V_60 ) {
V_75 = F_57 ( & V_5 -> V_66 , & V_44 -> V_47 ,
V_8 -> V_16 ) ;
if ( V_75 ) {
F_21 ( V_5 -> V_39 , L_26 ,
V_8 -> V_25 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return - V_55 ;
}
}
if ( F_35 ( & V_8 -> V_62 ) ) {
if ( V_8 -> V_16 ) {
F_21 ( V_5 -> V_39 , L_27 ) ;
if ( ! F_30 ( V_8 , V_44 ) )
V_44 = NULL ;
} else {
F_21 ( V_5 -> V_39 , L_28 ) ;
if ( ! F_25 ( V_8 , V_44 ) )
V_44 = NULL ;
}
}
if ( V_44 != NULL )
F_53 ( & V_44 -> V_62 , & V_8 -> V_62 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return 0 ;
}
static int F_58 ( struct V_87 * V_88 , struct V_112 * V_114 )
{
struct V_6 * V_8 = F_38 ( V_88 ) ;
struct V_43 * V_44 = F_50 ( V_114 ) ;
struct V_4 * V_5 = V_8 -> V_5 ;
unsigned long V_90 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
F_59 (req, &ep->queue, queue) {
if ( & V_44 -> V_47 == V_114 )
break;
}
if ( & V_44 -> V_47 != V_114 ) {
F_41 ( & V_8 -> V_5 -> V_68 , V_90 ) ;
return - V_42 ;
}
F_19 ( V_8 , V_44 , - V_80 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return 0 ;
}
static int F_60 ( struct V_87 * V_8 ,
const struct V_92 * V_83 )
{
return - V_42 ;
}
static int F_61 ( struct V_87 * V_8 )
{
return - V_42 ;
}
static int F_62 ( struct V_121 * V_66 )
{
struct V_4 * V_5 ;
int V_122 ;
if ( ! V_66 )
return - V_123 ;
V_5 = F_63 ( V_66 ) ;
V_122 = V_5 -> V_11 ( V_5 -> V_1 + V_124 ) ;
return V_122 ;
}
static int F_64 ( struct V_121 * V_66 )
{
struct V_4 * V_5 = F_63 ( V_66 ) ;
T_2 V_125 ;
int V_61 = - V_42 ;
unsigned long V_90 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
if ( ! V_5 -> V_126 )
goto V_127;
V_125 = V_5 -> V_11 ( V_5 -> V_1 + V_128 ) ;
V_125 |= V_129 ;
V_5 -> V_13 ( V_5 -> V_1 , V_128 , V_125 ) ;
F_65 ( 2 ) ;
V_125 &= ~ V_129 ;
V_5 -> V_13 ( V_5 -> V_1 , V_128 , V_125 ) ;
V_61 = 0 ;
V_127:
F_41 ( & V_5 -> V_68 , V_90 ) ;
return V_61 ;
}
static int F_66 ( struct V_121 * V_66 , int V_130 )
{
struct V_4 * V_5 = F_63 ( V_66 ) ;
unsigned long V_90 ;
T_2 V_125 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
V_125 = V_5 -> V_11 ( V_5 -> V_1 + V_128 ) ;
if ( V_130 )
V_125 |= V_131 ;
else
V_125 &= ~ V_131 ;
V_5 -> V_13 ( V_5 -> V_1 , V_128 , V_125 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return 0 ;
}
static void F_67 ( struct V_4 * V_5 )
{
T_2 V_132 ;
F_48 ( & V_5 -> V_66 . V_133 ) ;
for ( V_132 = 0 ; V_132 < V_134 ; V_132 ++ ) {
struct V_6 * V_8 = & V_5 -> V_8 [ V_132 ] ;
if ( V_132 ) {
F_53 ( & V_8 -> V_18 . V_133 ,
& V_5 -> V_66 . V_133 ) ;
F_68 ( & V_8 -> V_18 ,
( unsigned short ) ~ 0 ) ;
snprintf ( V_8 -> V_65 , V_135 , L_29 , V_132 ) ;
V_8 -> V_18 . V_65 = V_8 -> V_65 ;
V_8 -> V_18 . V_136 = & V_137 ;
} else {
V_8 -> V_18 . V_65 = V_138 ;
F_68 ( & V_8 -> V_18 , V_119 ) ;
V_8 -> V_18 . V_136 = & V_139 ;
}
V_8 -> V_5 = V_5 ;
V_8 -> V_25 = V_132 ;
V_8 -> V_83 = NULL ;
V_8 -> V_2 = V_140 + ( V_132 * 0x10 ) ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = 0 ;
V_8 -> V_19 = 0 ;
F_10 ( V_8 , V_5 ) ;
F_48 ( & V_8 -> V_62 ) ;
}
}
static void F_69 ( struct V_4 * V_5 )
{
int V_141 ;
struct V_6 * V_8 ;
for ( V_141 = 0 ; V_141 < V_134 ; V_141 ++ ) {
V_8 = & V_5 -> V_8 [ V_141 ] ;
F_34 ( V_8 , - V_64 ) ;
}
}
static int F_70 ( struct V_121 * V_66 ,
struct V_142 * V_109 )
{
struct V_4 * V_5 = F_63 ( V_66 ) ;
struct V_6 * V_7 = & V_5 -> V_8 [ V_9 ] ;
const struct V_92 * V_83 = & V_143 ;
unsigned long V_90 ;
int V_75 = 0 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
if ( V_5 -> V_109 ) {
F_12 ( V_5 -> V_39 , L_30 ,
V_5 -> V_66 . V_65 , V_5 -> V_109 -> V_109 . V_65 ) ;
V_75 = - V_116 ;
goto V_144;
}
V_5 -> V_109 = V_109 ;
V_5 -> V_66 . V_110 = V_109 -> V_145 ;
V_75 = F_42 ( V_7 , V_83 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_146 , 0 ) ;
V_5 -> V_126 = 0 ;
V_144:
F_41 ( & V_5 -> V_68 , V_90 ) ;
return V_75 ;
}
static int F_71 ( struct V_121 * V_66 )
{
struct V_4 * V_5 = F_63 ( V_66 ) ;
unsigned long V_90 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
V_5 -> V_66 . V_110 = V_111 ;
V_5 -> V_109 = NULL ;
V_5 -> V_13 ( V_5 -> V_1 , V_146 , 0 ) ;
V_5 -> V_126 = 0 ;
F_69 ( V_5 ) ;
F_41 ( & V_5 -> V_68 , V_90 ) ;
return 0 ;
}
static void F_72 ( struct V_4 * V_5 )
{
struct V_6 * V_8 ;
T_2 V_10 ;
int V_141 ;
for ( V_141 = 0 ; V_141 < V_134 ; V_141 ++ ) {
V_8 = & V_5 -> V_8 [ V_141 ] ;
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_8 -> V_2 ) ;
V_10 &= ~ V_91 ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_10 ) ;
if ( V_8 -> V_25 ) {
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_8 -> V_2 ) ;
V_10 &= ~ V_12 ;
V_5 -> V_13 ( V_5 -> V_1 , V_8 -> V_2 , V_10 ) ;
}
}
}
static void F_73 ( struct V_4 * V_5 , T_2 V_147 )
{
T_2 V_148 ;
if ( V_147 & V_149 ) {
F_21 ( V_5 -> V_39 , L_31 ) ;
if ( V_147 & V_150 )
V_5 -> V_66 . V_110 = V_151 ;
else
V_5 -> V_66 . V_110 = V_152 ;
F_69 ( V_5 ) ;
F_72 ( V_5 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_153 , 0 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_146 , 0 ) ;
V_5 -> V_126 = 0 ;
V_148 = V_5 -> V_11 ( V_5 -> V_1 + V_105 ) ;
V_148 |= V_154 | V_155 |
V_156 ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_148 ) ;
}
if ( V_147 & V_154 ) {
F_21 ( V_5 -> V_39 , L_32 ) ;
V_148 = V_5 -> V_11 ( V_5 -> V_1 + V_105 ) ;
V_148 |= V_149 | V_155 |
V_156 ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_148 ) ;
V_5 -> V_157 = V_158 ;
if ( V_5 -> V_109 -> V_159 ) {
F_23 ( & V_5 -> V_68 ) ;
V_5 -> V_109 -> V_159 ( & V_5 -> V_66 ) ;
F_24 ( & V_5 -> V_68 ) ;
}
}
if ( V_147 & V_155 ) {
bool V_160 = ( V_5 -> V_157 != V_158 ) ;
F_74 ( V_5 -> V_39 , V_160 ,
L_33 ) ;
F_21 ( V_5 -> V_39 , L_34 ) ;
V_148 = V_5 -> V_11 ( V_5 -> V_1 + V_105 ) ;
V_148 |= V_149 | V_154 |
V_156 ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_148 ) ;
V_5 -> V_157 = 0 ;
if ( V_5 -> V_109 -> V_161 ) {
F_23 ( & V_5 -> V_68 ) ;
V_5 -> V_109 -> V_161 ( & V_5 -> V_66 ) ;
F_24 ( & V_5 -> V_68 ) ;
}
}
if ( V_147 & V_156 ) {
F_21 ( V_5 -> V_39 , L_35 ) ;
V_148 = V_5 -> V_11 ( V_5 -> V_1 + V_105 ) ;
V_148 |= V_149 | V_155 |
V_154 ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_148 ) ;
if ( V_5 -> V_109 && V_5 -> V_109 -> V_162 ) {
F_23 ( & V_5 -> V_68 ) ;
V_5 -> V_109 -> V_162 ( & V_5 -> V_66 ) ;
F_24 ( & V_5 -> V_68 ) ;
}
}
}
static void F_75 ( struct V_4 * V_5 )
{
T_2 V_10 ;
struct V_6 * V_7 = & V_5 -> V_8 [ V_9 ] ;
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_7 -> V_2 ) ;
V_10 |= V_91 ;
V_5 -> V_13 ( V_5 -> V_1 , V_7 -> V_2 , V_10 ) ;
}
static void F_76 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 [ 0 ] ;
struct V_43 * V_44 = V_5 -> V_44 ;
int V_75 ;
V_44 -> V_47 . V_30 = 0 ;
V_75 = F_52 ( V_7 , V_44 ) ;
if ( V_75 == 0 )
return;
F_12 ( V_5 -> V_39 , L_36 ) ;
F_75 ( V_5 ) ;
}
static void F_77 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 [ 0 ] ;
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_6 * V_163 ;
T_5 V_61 = 0 ;
T_2 V_10 ;
int V_164 ;
T_2 V_165 ;
int V_75 ;
switch ( V_5 -> V_117 . V_118 & V_166 ) {
case V_167 :
V_61 = 1 << V_168 ;
if ( V_5 -> V_126 )
V_61 |= ( 1 << V_169 ) ;
break;
case V_170 :
break;
case V_171 :
V_164 = V_5 -> V_117 . V_172 & V_173 ;
V_163 = & V_5 -> V_8 [ V_164 ] ;
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_163 -> V_2 ) ;
V_165 = V_10 & V_91 ;
if ( V_5 -> V_117 . V_172 & V_97 ) {
if ( ! V_163 -> V_16 )
goto V_174;
} else {
if ( V_163 -> V_16 )
goto V_174;
}
if ( V_165 )
V_61 = 1 << V_175 ;
break;
default:
goto V_174;
}
V_44 -> V_47 . V_30 = 2 ;
* ( T_5 * ) V_44 -> V_47 . V_69 = F_78 ( V_61 ) ;
V_75 = F_52 ( V_7 , V_44 ) ;
if ( V_75 == 0 )
return;
V_174:
F_12 ( V_5 -> V_39 , L_37 ) ;
F_75 ( V_5 ) ;
}
static void F_79 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 [ 0 ] ;
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_6 * V_163 ;
T_4 V_176 ;
T_4 V_177 ;
T_2 V_10 ;
int V_178 = ( V_5 -> V_117 . V_179 == V_180 ? 1 : 0 ) ;
int V_75 ;
switch ( V_5 -> V_117 . V_118 ) {
case V_167 :
switch ( V_5 -> V_117 . V_181 ) {
case V_182 :
break;
case V_169 :
if ( V_178 )
V_5 -> V_126 = 1 ;
else
V_5 -> V_126 = 0 ;
break;
default:
F_75 ( V_5 ) ;
break;
}
break;
case V_171 :
if ( ! V_5 -> V_117 . V_181 ) {
V_176 = V_5 -> V_117 . V_172 & V_173 ;
V_163 = & V_5 -> V_8 [ V_176 ] ;
V_177 = V_5 -> V_117 . V_172 & V_183 ;
V_177 = V_177 >> 7 ;
if ( V_177 != V_163 -> V_16 ) {
F_75 ( V_5 ) ;
return;
}
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_163 -> V_2 ) ;
if ( ! V_176 ) {
V_10 &= ~ V_91 ;
V_5 -> V_13 ( V_5 -> V_1 ,
V_163 -> V_2 , V_10 ) ;
} else {
if ( V_178 ) {
V_10 |= V_91 ;
V_5 -> V_13 ( V_5 -> V_1 ,
V_163 -> V_2 ,
V_10 ) ;
} else {
V_10 &= ~ ( V_91 |
V_12 ) ;
V_5 -> V_13 ( V_5 -> V_1 ,
V_163 -> V_2 ,
V_10 ) ;
}
}
}
break;
default:
F_75 ( V_5 ) ;
return;
}
V_44 -> V_47 . V_30 = 0 ;
V_75 = F_52 ( V_7 , V_44 ) ;
if ( V_75 == 0 )
return;
F_12 ( V_5 -> V_39 , L_38 ) ;
F_75 ( V_5 ) ;
}
static void F_80 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 [ 0 ] ;
struct V_184 V_117 ;
T_2 * V_185 ;
V_185 = ( T_2 V_52 * ) ( V_5 -> V_1 + V_186 ) ;
memcpy ( & V_117 , V_185 , 8 ) ;
V_5 -> V_117 = V_117 ;
V_5 -> V_117 . V_181 = F_78 ( V_117 . V_181 ) ;
V_5 -> V_117 . V_172 = F_78 ( V_117 . V_172 ) ;
V_5 -> V_117 . V_120 = F_78 ( V_117 . V_120 ) ;
F_34 ( V_7 , - V_80 ) ;
if ( V_5 -> V_117 . V_118 & V_97 ) {
V_5 -> V_187 = V_188 ;
V_5 -> V_189 = V_190 ;
} else {
V_5 -> V_187 = V_190 ;
V_5 -> V_189 = V_188 ;
}
switch ( V_5 -> V_117 . V_179 ) {
case V_191 :
if ( ( V_5 -> V_117 . V_118 &
( V_97 | V_192 ) ) !=
( V_97 | V_193 ) )
break;
F_77 ( V_5 ) ;
return;
case V_194 :
if ( V_5 -> V_117 . V_118 != ( V_195 |
V_193 | V_167 ) )
break;
F_76 ( V_5 ) ;
return;
case V_196 :
case V_180 :
if ( ( V_5 -> V_117 . V_118 & V_192 )
!= V_193 )
break;
F_79 ( V_5 ) ;
return;
default:
break;
}
F_23 ( & V_5 -> V_68 ) ;
if ( V_5 -> V_109 -> V_117 ( & V_5 -> V_66 , & V_117 ) < 0 )
F_75 ( V_5 ) ;
F_24 ( & V_5 -> V_68 ) ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 [ 0 ] ;
struct V_43 * V_44 ;
T_4 * V_185 ;
unsigned int V_197 ;
void * V_45 ;
V_44 = F_36 ( & V_7 -> V_62 , struct V_43 , V_62 ) ;
switch ( V_5 -> V_187 ) {
case V_188 :
V_5 -> V_187 = V_198 ;
V_5 -> V_189 = V_198 ;
V_44 -> V_47 . V_49 = V_44 -> V_47 . V_30 ;
F_19 ( V_7 , V_44 , 0 ) ;
break;
case V_190 :
V_197 = V_5 -> V_11 ( V_5 -> V_1 +
V_14 ) ;
V_185 = ( T_4 V_52 * ) ( V_5 -> V_1 +
( V_7 -> V_20 << 2 ) ) ;
V_45 = V_44 -> V_47 . V_69 + V_44 -> V_47 . V_49 ;
V_44 -> V_47 . V_49 = V_44 -> V_47 . V_49 + V_197 ;
memcpy ( V_45 , V_185 , V_197 ) ;
if ( V_44 -> V_47 . V_30 == V_44 -> V_47 . V_49 ) {
F_9 ( V_5 ) ;
} else {
V_5 -> V_13 ( V_5 -> V_1 , V_14 , 0 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_15 , 1 ) ;
}
break;
default:
break;
}
}
static void F_82 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_8 [ 0 ] ;
struct V_43 * V_44 ;
unsigned int V_199 ;
void * V_45 ;
T_2 V_10 ;
T_5 V_71 = 0 ;
T_5 V_30 ;
T_4 * V_185 ;
T_4 V_200 = V_5 -> V_117 . V_172 >> 8 ;
V_44 = F_36 ( & V_7 -> V_62 , struct V_43 , V_62 ) ;
V_199 = V_44 -> V_47 . V_30 - V_44 -> V_47 . V_49 ;
switch ( V_5 -> V_189 ) {
case V_188 :
switch ( V_5 -> V_117 . V_179 ) {
case V_194 :
V_5 -> V_13 ( V_5 -> V_1 , V_146 ,
V_5 -> V_117 . V_181 ) ;
break;
case V_180 :
if ( V_5 -> V_117 . V_118 ==
V_167 ) {
if ( V_5 -> V_117 . V_181 ==
V_182 )
V_5 -> V_13 ( V_5 -> V_1 ,
V_153 ,
V_200 ) ;
}
break;
}
V_44 -> V_47 . V_49 = V_44 -> V_47 . V_30 ;
F_19 ( V_7 , V_44 , 0 ) ;
break;
case V_190 :
if ( ! V_199 ) {
V_10 = V_5 -> V_11 ( V_5 -> V_1 + V_7 -> V_2 ) ;
V_10 |= V_12 ;
V_5 -> V_13 ( V_5 -> V_1 , V_7 -> V_2 , V_10 ) ;
V_5 -> V_189 = V_188 ;
} else {
V_30 = V_71 = F_54 ( T_2 , V_199 ,
V_119 ) ;
V_185 = ( T_4 V_52 * ) ( V_5 -> V_1 +
( V_7 -> V_20 << 2 ) ) ;
V_45 = V_44 -> V_47 . V_69 + V_44 -> V_47 . V_49 ;
V_44 -> V_47 . V_49 = V_44 -> V_47 . V_49 + V_30 ;
memcpy ( V_185 , V_45 , V_30 ) ;
}
V_5 -> V_13 ( V_5 -> V_1 , V_14 , V_71 ) ;
V_5 -> V_13 ( V_5 -> V_1 , V_15 , 1 ) ;
break;
default:
break;
}
}
static void F_83 ( struct V_4 * V_5 , T_2 V_147 )
{
if ( V_147 & V_201 ) {
F_80 ( V_5 ) ;
} else {
if ( V_147 & V_202 )
F_81 ( V_5 ) ;
else if ( V_147 & V_203 )
F_82 ( V_5 ) ;
}
}
static void F_84 ( struct V_4 * V_5 , T_4 V_164 ,
T_2 V_147 )
{
struct V_43 * V_44 ;
struct V_6 * V_8 ;
V_8 = & V_5 -> V_8 [ V_164 ] ;
if ( V_147 & ( V_204 << V_164 ) )
V_8 -> V_24 = 0 ;
if ( V_147 & ( V_205 << V_164 ) )
V_8 -> V_26 = 0 ;
if ( F_35 ( & V_8 -> V_62 ) )
return;
V_44 = F_36 ( & V_8 -> V_62 , struct V_43 , V_62 ) ;
if ( V_8 -> V_16 )
F_30 ( V_8 , V_44 ) ;
else
F_25 ( V_8 , V_44 ) ;
}
static T_7 F_85 ( int V_206 , void * V_207 )
{
struct V_4 * V_5 = V_207 ;
T_2 V_147 ;
T_2 V_95 ;
T_4 V_208 ;
T_2 V_209 ;
unsigned long V_90 ;
F_40 ( & V_5 -> V_68 , V_90 ) ;
V_95 = V_5 -> V_11 ( V_5 -> V_1 + V_105 ) ;
V_95 &= ~ V_210 ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_95 ) ;
V_147 = V_5 -> V_11 ( V_5 -> V_1 + V_211 ) ;
if ( V_147 & V_210 ) {
F_73 ( V_5 , V_147 ) ;
}
if ( V_147 & V_212 ) {
V_95 = V_5 -> V_11 ( V_5 -> V_1 + V_105 ) ;
V_95 |= V_210 ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_95 ) ;
if ( V_147 & V_204 )
F_83 ( V_5 , V_147 ) ;
for ( V_208 = 1 ; V_208 < 8 ; V_208 ++ ) {
V_209 = ( ( V_147 &
( V_213 <<
( V_208 - 1 ) ) ) || ( V_147 &
( V_214 <<
( V_208 - 1 ) ) ) ) ;
if ( V_209 ) {
F_84 ( V_5 , V_208 ,
V_147 ) ;
}
}
}
F_41 ( & V_5 -> V_68 , V_90 ) ;
return V_215 ;
}
static int F_86 ( struct V_216 * V_217 )
{
struct V_218 * V_219 = V_217 -> V_39 . V_220 ;
struct V_221 * V_222 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_206 ;
int V_75 ;
T_2 V_95 ;
T_4 * V_223 ;
V_5 = F_87 ( & V_217 -> V_39 , sizeof( * V_5 ) , V_224 ) ;
if ( ! V_5 )
return - V_225 ;
V_5 -> V_44 = F_87 ( & V_217 -> V_39 , sizeof( struct V_43 ) ,
V_224 ) ;
if ( ! V_5 -> V_44 )
return - V_225 ;
V_223 = F_87 ( & V_217 -> V_39 , V_226 , V_224 ) ;
if ( ! V_223 )
return - V_225 ;
V_5 -> V_44 -> V_47 . V_69 = V_223 ;
V_222 = F_88 ( V_217 , V_227 , 0 ) ;
V_5 -> V_1 = F_89 ( & V_217 -> V_39 , V_222 ) ;
if ( F_90 ( V_5 -> V_1 ) )
return F_91 ( V_5 -> V_1 ) ;
V_206 = F_92 ( V_217 , 0 ) ;
if ( V_206 < 0 ) {
F_12 ( & V_217 -> V_39 , L_39 ) ;
return V_206 ;
}
V_75 = F_93 ( & V_217 -> V_39 , V_206 , F_85 , 0 ,
F_94 ( & V_217 -> V_39 ) , V_5 ) ;
if ( V_75 < 0 ) {
F_21 ( & V_217 -> V_39 , L_40 , V_206 ) ;
goto V_228;
}
V_5 -> V_60 = F_95 ( V_219 , L_41 ) ;
V_5 -> V_66 . V_136 = & V_229 ;
V_5 -> V_66 . V_145 = V_151 ;
V_5 -> V_66 . V_110 = V_111 ;
V_5 -> V_66 . V_7 = & V_5 -> V_8 [ V_9 ] . V_18 ;
V_5 -> V_66 . V_65 = V_230 ;
F_96 ( & V_5 -> V_68 ) ;
V_5 -> V_13 = F_5 ;
V_5 -> V_11 = F_7 ;
V_5 -> V_13 ( V_5 -> V_1 , V_153 , V_231 ) ;
if ( ( V_5 -> V_11 ( V_5 -> V_1 + V_153 ) )
!= V_231 ) {
V_5 -> V_13 = F_1 ;
V_5 -> V_11 = F_3 ;
}
V_5 -> V_13 ( V_5 -> V_1 , V_153 , 0 ) ;
F_67 ( V_5 ) ;
V_7 = & V_5 -> V_8 [ 0 ] ;
V_5 -> V_13 ( V_5 -> V_1 , V_146 , 0 ) ;
V_75 = F_97 ( & V_217 -> V_39 , & V_5 -> V_66 ) ;
if ( V_75 )
goto V_228;
V_5 -> V_39 = & V_5 -> V_66 . V_39 ;
V_95 = V_232 | V_210 |
V_202 | V_203 |
V_201 |
V_212 ;
V_5 -> V_13 ( V_5 -> V_1 , V_105 , V_95 ) ;
F_98 ( V_217 , V_5 ) ;
F_99 ( & V_217 -> V_39 , L_42 ,
V_230 , ( T_2 ) V_222 -> V_233 , V_5 -> V_1 ,
V_5 -> V_60 ? L_43 : L_44 ) ;
return 0 ;
V_228:
F_12 ( & V_217 -> V_39 , L_45 , V_75 ) ;
return V_75 ;
}
static int F_100 ( struct V_216 * V_217 )
{
struct V_4 * V_5 = F_101 ( V_217 ) ;
F_102 ( & V_5 -> V_66 ) ;
return 0 ;
}
