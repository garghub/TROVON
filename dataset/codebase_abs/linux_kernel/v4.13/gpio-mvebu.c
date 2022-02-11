static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , unsigned int * V_5 )
{
int V_6 ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_9 :
case V_10 :
* V_4 = V_2 -> V_11 ;
* V_5 = V_12 + V_2 -> V_5 ;
break;
case V_13 :
V_6 = F_2 () ;
* V_4 = V_2 -> V_14 ;
* V_5 = F_3 ( V_6 ) ;
break;
default:
F_4 () ;
}
}
static T_1
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
T_1 V_15 ;
F_1 ( V_2 , & V_4 , & V_5 ) ;
F_6 ( V_4 , V_5 , & V_15 ) ;
return V_15 ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
F_1 ( V_2 , & V_4 , & V_5 ) ;
F_8 ( V_4 , V_5 , V_15 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , unsigned int * V_5 )
{
int V_6 ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_10 :
* V_4 = V_2 -> V_11 ;
* V_5 = V_16 + V_2 -> V_5 ;
break;
case V_9 :
V_6 = F_2 () ;
* V_4 = V_2 -> V_11 ;
* V_5 = F_10 ( V_6 ) ;
break;
case V_13 :
V_6 = F_2 () ;
* V_4 = V_2 -> V_14 ;
* V_5 = F_11 ( V_6 ) ;
break;
default:
F_4 () ;
}
}
static T_1
F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
T_1 V_15 ;
F_9 ( V_2 , & V_4 , & V_5 ) ;
F_6 ( V_4 , V_5 , & V_15 ) ;
return V_15 ;
}
static void
F_13 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
F_9 ( V_2 , & V_4 , & V_5 ) ;
F_8 ( V_4 , V_5 , V_15 ) ;
}
static void
F_14 ( struct V_1 * V_2 ,
struct V_3 * * V_4 , unsigned int * V_5 )
{
int V_6 ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_10 :
* V_4 = V_2 -> V_11 ;
* V_5 = V_17 + V_2 -> V_5 ;
break;
case V_9 :
V_6 = F_2 () ;
* V_4 = V_2 -> V_11 ;
* V_5 = F_15 ( V_6 ) ;
break;
case V_13 :
V_6 = F_2 () ;
* V_4 = V_2 -> V_14 ;
* V_5 = F_16 ( V_6 ) ;
break;
default:
F_4 () ;
}
}
static T_1
F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
T_1 V_15 ;
F_14 ( V_2 , & V_4 , & V_5 ) ;
F_6 ( V_4 , V_5 , & V_15 ) ;
return V_15 ;
}
static void
F_18 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
F_14 ( V_2 , & V_4 , & V_5 ) ;
F_8 ( V_4 , V_5 , V_15 ) ;
}
static void T_2 * F_19 ( struct V_18 * V_19 )
{
return V_19 -> V_20 + V_21 ;
}
static void T_2 * F_20 ( struct V_18 * V_19 )
{
return V_19 -> V_20 + V_22 ;
}
static void F_21 ( struct V_23 * V_24 , unsigned int V_25 , int V_26 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
F_23 ( V_2 -> V_11 , V_27 + V_2 -> V_5 ,
F_24 ( V_25 ) , V_26 ? F_24 ( V_25 ) : 0 ) ;
}
static int F_25 ( struct V_23 * V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
T_1 V_28 ;
F_6 ( V_2 -> V_11 , V_29 + V_2 -> V_5 , & V_28 ) ;
if ( V_28 & F_24 ( V_25 ) ) {
T_1 V_30 , V_31 ;
F_6 ( V_2 -> V_11 , V_32 + V_2 -> V_5 ,
& V_30 ) ;
F_6 ( V_2 -> V_11 , V_33 + V_2 -> V_5 ,
& V_31 ) ;
V_28 = V_30 ^ V_31 ;
} else {
F_6 ( V_2 -> V_11 , V_27 + V_2 -> V_5 , & V_28 ) ;
}
return ( V_28 >> V_25 ) & 1 ;
}
static void F_26 ( struct V_23 * V_24 , unsigned int V_25 ,
int V_26 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
F_23 ( V_2 -> V_11 , V_34 + V_2 -> V_5 ,
F_24 ( V_25 ) , V_26 ? F_24 ( V_25 ) : 0 ) ;
}
static int F_27 ( struct V_23 * V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_35 ;
V_35 = F_28 ( V_24 -> V_36 + V_25 ) ;
if ( V_35 )
return V_35 ;
F_23 ( V_2 -> V_11 , V_29 + V_2 -> V_5 ,
F_24 ( V_25 ) , F_24 ( V_25 ) ) ;
return 0 ;
}
static int F_29 ( struct V_23 * V_24 , unsigned int V_25 ,
int V_26 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
int V_35 ;
V_35 = F_30 ( V_24 -> V_36 + V_25 ) ;
if ( V_35 )
return V_35 ;
F_26 ( V_24 , V_25 , 0 ) ;
F_21 ( V_24 , V_25 , V_26 ) ;
F_23 ( V_2 -> V_11 , V_29 + V_2 -> V_5 ,
F_24 ( V_25 ) , 0 ) ;
return 0 ;
}
static int F_31 ( struct V_23 * V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
return F_32 ( V_2 -> V_37 , V_25 ) ;
}
static void F_33 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_34 ( V_39 ) ;
struct V_1 * V_2 = V_41 -> V_42 ;
T_1 V_43 = V_39 -> V_43 ;
F_35 ( V_41 ) ;
F_7 ( V_2 , ~ V_43 ) ;
F_36 ( V_41 ) ;
}
static void F_37 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_34 ( V_39 ) ;
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_44 * V_45 = F_38 ( V_39 ) ;
T_1 V_43 = V_39 -> V_43 ;
F_35 ( V_41 ) ;
V_45 -> V_46 &= ~ V_43 ;
F_13 ( V_2 , V_45 -> V_46 ) ;
F_36 ( V_41 ) ;
}
static void F_39 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_34 ( V_39 ) ;
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_44 * V_45 = F_38 ( V_39 ) ;
T_1 V_43 = V_39 -> V_43 ;
F_35 ( V_41 ) ;
V_45 -> V_46 |= V_43 ;
F_13 ( V_2 , V_45 -> V_46 ) ;
F_36 ( V_41 ) ;
}
static void F_40 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_34 ( V_39 ) ;
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_44 * V_45 = F_38 ( V_39 ) ;
T_1 V_43 = V_39 -> V_43 ;
F_35 ( V_41 ) ;
V_45 -> V_46 &= ~ V_43 ;
F_18 ( V_2 , V_45 -> V_46 ) ;
F_36 ( V_41 ) ;
}
static void F_41 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_34 ( V_39 ) ;
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_44 * V_45 = F_38 ( V_39 ) ;
T_1 V_43 = V_39 -> V_43 ;
F_35 ( V_41 ) ;
V_45 -> V_46 |= V_43 ;
F_18 ( V_2 , V_45 -> V_46 ) ;
F_36 ( V_41 ) ;
}
static int F_42 ( struct V_38 * V_39 , unsigned int type )
{
struct V_40 * V_41 = F_34 ( V_39 ) ;
struct V_44 * V_45 = F_38 ( V_39 ) ;
struct V_1 * V_2 = V_41 -> V_42 ;
int V_25 ;
T_1 V_28 ;
V_25 = V_39 -> V_47 ;
F_6 ( V_2 -> V_11 , V_29 + V_2 -> V_5 , & V_28 ) ;
if ( ( V_28 & F_24 ( V_25 ) ) == 0 )
return - V_48 ;
type &= V_49 ;
if ( type == V_50 )
return - V_48 ;
if ( ! ( V_45 -> type & type ) )
if ( F_43 ( V_39 , type ) )
return - V_48 ;
switch ( type ) {
case V_51 :
case V_52 :
F_23 ( V_2 -> V_11 ,
V_33 + V_2 -> V_5 ,
F_24 ( V_25 ) , 0 ) ;
break;
case V_53 :
case V_54 :
F_23 ( V_2 -> V_11 ,
V_33 + V_2 -> V_5 ,
F_24 ( V_25 ) , F_24 ( V_25 ) ) ;
break;
case V_55 : {
T_1 V_30 , V_31 , V_15 ;
F_6 ( V_2 -> V_11 ,
V_33 + V_2 -> V_5 , & V_31 ) ;
F_6 ( V_2 -> V_11 ,
V_32 + V_2 -> V_5 , & V_30 ) ;
if ( ( V_30 ^ V_31 ) & F_24 ( V_25 ) )
V_15 = F_24 ( V_25 ) ;
else
V_15 = 0 ;
F_23 ( V_2 -> V_11 ,
V_33 + V_2 -> V_5 ,
F_24 ( V_25 ) , V_15 ) ;
break;
}
}
return 0 ;
}
static void F_44 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_45 ( V_57 ) ;
struct V_58 * V_24 = F_46 ( V_57 ) ;
T_1 V_59 , type , V_30 , V_60 , V_61 , V_62 ;
int V_63 ;
if ( V_2 == NULL )
return;
F_47 ( V_24 , V_57 ) ;
F_6 ( V_2 -> V_11 , V_32 + V_2 -> V_5 , & V_30 ) ;
V_60 = F_17 ( V_2 ) ;
V_61 = F_5 ( V_2 ) ;
V_62 = F_12 ( V_2 ) ;
V_59 = ( V_30 & V_60 ) | ( V_61 & V_62 ) ;
for ( V_63 = 0 ; V_63 < V_2 -> V_24 . V_64 ; V_63 ++ ) {
int V_65 ;
V_65 = F_48 ( V_2 -> V_37 , V_63 ) ;
if ( ! ( V_59 & F_24 ( V_63 ) ) )
continue;
type = F_49 ( V_65 ) ;
if ( ( type & V_49 ) == V_55 ) {
T_1 V_66 ;
F_6 ( V_2 -> V_11 ,
V_33 + V_2 -> V_5 ,
& V_66 ) ;
V_66 ^= F_24 ( V_63 ) ;
F_8 ( V_2 -> V_11 ,
V_33 + V_2 -> V_5 ,
V_66 ) ;
}
F_50 ( V_65 ) ;
}
F_51 ( V_24 , V_57 ) ;
}
static struct V_18 * F_52 ( struct V_67 * V_24 )
{
return F_53 ( V_24 , struct V_18 , V_24 ) ;
}
static int F_54 ( struct V_67 * V_24 , struct V_68 * V_69 )
{
struct V_18 * V_19 = F_52 ( V_24 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_70 * V_57 ;
unsigned long V_71 ;
int V_35 = 0 ;
F_55 ( & V_19 -> V_72 , V_71 ) ;
if ( V_19 -> V_73 ) {
V_35 = - V_74 ;
} else {
V_57 = F_56 ( V_2 -> V_24 . V_36 + V_69 -> V_75 ) ;
if ( ! V_57 ) {
V_35 = - V_76 ;
goto V_77;
}
V_35 = F_57 ( V_57 , L_1 ) ;
if ( V_35 )
goto V_77;
V_35 = F_58 ( V_57 , 0 ) ;
if ( V_35 ) {
F_59 ( V_57 ) ;
goto V_77;
}
V_19 -> V_73 = V_57 ;
}
V_77:
F_60 ( & V_19 -> V_72 , V_71 ) ;
return V_35 ;
}
static void F_61 ( struct V_67 * V_24 , struct V_68 * V_69 )
{
struct V_18 * V_19 = F_52 ( V_24 ) ;
unsigned long V_71 ;
F_55 ( & V_19 -> V_72 , V_71 ) ;
F_59 ( V_19 -> V_73 ) ;
V_19 -> V_73 = NULL ;
F_60 ( & V_19 -> V_72 , V_71 ) ;
}
static void F_62 ( struct V_67 * V_24 ,
struct V_68 * V_69 ,
struct V_78 * V_79 ) {
struct V_18 * V_19 = F_52 ( V_24 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long long V_15 ;
unsigned long V_71 ;
T_1 V_28 ;
F_55 ( & V_19 -> V_72 , V_71 ) ;
V_15 = ( unsigned long long )
F_63 ( F_19 ( V_19 ) ) ;
V_15 *= V_80 ;
F_64 ( V_15 , V_19 -> V_81 ) ;
if ( V_15 > V_82 )
V_79 -> V_83 = V_82 ;
else if ( V_15 )
V_79 -> V_83 = V_15 ;
else
V_79 -> V_83 = 1 ;
V_15 = ( unsigned long long )
F_63 ( F_20 ( V_19 ) ) ;
V_15 *= V_80 ;
F_64 ( V_15 , V_19 -> V_81 ) ;
if ( V_15 < V_79 -> V_83 ) {
V_79 -> V_84 = 1 ;
} else {
V_15 -= V_79 -> V_83 ;
if ( V_15 > V_82 )
V_79 -> V_84 = V_82 ;
else if ( V_15 )
V_79 -> V_84 = V_15 ;
else
V_79 -> V_84 = 1 ;
}
F_6 ( V_2 -> V_11 , V_34 + V_2 -> V_5 , & V_28 ) ;
if ( V_28 )
V_79 -> V_85 = true ;
else
V_79 -> V_85 = false ;
F_60 ( & V_19 -> V_72 , V_71 ) ;
}
static int F_65 ( struct V_67 * V_24 , struct V_68 * V_69 ,
struct V_78 * V_79 )
{
struct V_18 * V_19 = F_52 ( V_24 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
unsigned long long V_15 ;
unsigned long V_71 ;
unsigned int V_86 , V_87 ;
V_15 = ( unsigned long long ) V_19 -> V_81 * V_79 -> V_83 ;
F_64 ( V_15 , V_80 ) ;
if ( V_15 > V_82 )
return - V_48 ;
if ( V_15 )
V_86 = V_15 ;
else
V_86 = 1 ;
V_15 = ( unsigned long long ) V_19 -> V_81 *
( V_79 -> V_84 - V_79 -> V_83 ) ;
F_64 ( V_15 , V_80 ) ;
if ( V_15 > V_82 )
return - V_48 ;
if ( V_15 )
V_87 = V_15 ;
else
V_87 = 1 ;
F_55 ( & V_19 -> V_72 , V_71 ) ;
F_66 ( V_86 , F_19 ( V_19 ) ) ;
F_66 ( V_87 , F_20 ( V_19 ) ) ;
if ( V_79 -> V_85 )
F_26 ( & V_2 -> V_24 , V_69 -> V_75 , 1 ) ;
else
F_26 ( & V_2 -> V_24 , V_69 -> V_75 , 0 ) ;
F_60 ( & V_19 -> V_72 , V_71 ) ;
return 0 ;
}
static void T_3 F_67 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_6 ( V_2 -> V_11 , V_88 + V_2 -> V_5 ,
& V_19 -> V_89 ) ;
V_19 -> V_90 =
F_63 ( F_19 ( V_19 ) ) ;
V_19 -> V_91 =
F_63 ( F_20 ( V_19 ) ) ;
}
static void T_3 F_68 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
F_8 ( V_2 -> V_11 , V_88 + V_2 -> V_5 ,
V_19 -> V_89 ) ;
F_66 ( V_19 -> V_90 ,
F_19 ( V_19 ) ) ;
F_66 ( V_19 -> V_91 ,
F_20 ( V_19 ) ) ;
}
static int F_69 ( struct V_92 * V_93 ,
struct V_1 * V_2 ,
int V_94 )
{
struct V_95 * V_96 = & V_93 -> V_96 ;
struct V_18 * V_19 ;
struct V_97 * V_98 ;
T_1 V_99 ;
if ( ! F_70 ( V_2 -> V_24 . V_100 ,
L_2 ) )
return 0 ;
if ( F_71 ( V_2 -> V_101 ) )
return F_72 ( V_2 -> V_101 ) ;
V_98 = F_73 ( V_93 , V_102 , L_3 ) ;
if ( ! V_98 )
return 0 ;
if ( V_94 == 0 )
V_99 = 0 ;
else if ( V_94 == 1 )
V_99 = V_103 ;
else
return - V_48 ;
F_8 ( V_2 -> V_11 ,
V_88 + V_2 -> V_5 , V_99 ) ;
V_19 = F_74 ( V_96 , sizeof( struct V_18 ) , V_104 ) ;
if ( ! V_19 )
return - V_105 ;
V_2 -> V_19 = V_19 ;
V_19 -> V_2 = V_2 ;
V_19 -> V_20 = F_75 ( V_96 , V_98 ) ;
if ( F_71 ( V_19 -> V_20 ) )
return F_72 ( V_19 -> V_20 ) ;
V_19 -> V_81 = F_76 ( V_2 -> V_101 ) ;
if ( ! V_19 -> V_81 ) {
F_77 ( V_96 , L_4 ) ;
return - V_48 ;
}
V_19 -> V_24 . V_96 = V_96 ;
V_19 -> V_24 . V_106 = & V_107 ;
V_19 -> V_24 . V_108 = V_2 -> V_24 . V_64 ;
V_19 -> V_24 . V_36 = - 1 ;
F_78 ( & V_19 -> V_72 ) ;
return F_79 ( & V_19 -> V_24 ) ;
}
static void F_80 ( struct V_109 * V_110 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
T_1 V_77 , V_111 , V_112 , V_31 , V_30 , V_59 , V_113 , V_114 ;
int V_63 ;
F_6 ( V_2 -> V_11 , V_27 + V_2 -> V_5 , & V_77 ) ;
F_6 ( V_2 -> V_11 , V_29 + V_2 -> V_5 , & V_111 ) ;
F_6 ( V_2 -> V_11 , V_34 + V_2 -> V_5 , & V_112 ) ;
F_6 ( V_2 -> V_11 , V_33 + V_2 -> V_5 , & V_31 ) ;
F_6 ( V_2 -> V_11 , V_32 + V_2 -> V_5 , & V_30 ) ;
V_59 = F_5 ( V_2 ) ;
V_113 = F_12 ( V_2 ) ;
V_114 = F_17 ( V_2 ) ;
for ( V_63 = 0 ; V_63 < V_24 -> V_64 ; V_63 ++ ) {
const char * V_115 ;
T_1 V_116 ;
bool V_117 ;
V_115 = F_81 ( V_24 , V_63 ) ;
if ( ! V_115 )
continue;
V_116 = F_24 ( V_63 ) ;
V_117 = ! ( V_111 & V_116 ) ;
F_82 ( V_110 , L_5 , V_24 -> V_36 + V_63 , V_115 ) ;
if ( V_117 ) {
F_82 ( V_110 , L_6 ,
V_77 & V_116 ? L_7 : L_8 ,
V_112 & V_116 ? L_9 : L_10 ) ;
continue;
}
F_82 ( V_110 , L_11 ,
( V_30 ^ V_31 ) & V_116 ? L_7 : L_8 ,
V_31 & V_116 ? L_8 : L_7 ) ;
if ( ! ( ( V_113 | V_114 ) & V_116 ) ) {
F_83 ( V_110 , L_12 ) ;
continue;
}
if ( V_113 & V_116 )
F_83 ( V_110 , L_13 ) ;
if ( V_114 & V_116 )
F_83 ( V_110 , L_14 ) ;
F_82 ( V_110 , L_15 , V_59 & V_116 ? L_16 : L_17 ) ;
}
}
static int F_84 ( struct V_92 * V_93 , T_4 V_79 )
{
struct V_1 * V_2 = F_85 ( V_93 ) ;
int V_63 ;
F_6 ( V_2 -> V_11 , V_27 + V_2 -> V_5 ,
& V_2 -> V_118 ) ;
F_6 ( V_2 -> V_11 , V_29 + V_2 -> V_5 ,
& V_2 -> V_119 ) ;
F_6 ( V_2 -> V_11 , V_34 + V_2 -> V_5 ,
& V_2 -> V_120 ) ;
F_6 ( V_2 -> V_11 , V_33 + V_2 -> V_5 ,
& V_2 -> V_121 ) ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_10 :
F_6 ( V_2 -> V_11 , V_16 + V_2 -> V_5 ,
& V_2 -> V_122 [ 0 ] ) ;
F_6 ( V_2 -> V_11 , V_17 + V_2 -> V_5 ,
& V_2 -> V_123 [ 0 ] ) ;
break;
case V_9 :
for ( V_63 = 0 ; V_63 < 2 ; V_63 ++ ) {
F_6 ( V_2 -> V_11 ,
F_10 ( V_63 ) ,
& V_2 -> V_122 [ V_63 ] ) ;
F_6 ( V_2 -> V_11 ,
F_15 ( V_63 ) ,
& V_2 -> V_123 [ V_63 ] ) ;
}
break;
case V_13 :
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
F_6 ( V_2 -> V_11 ,
F_11 ( V_63 ) ,
& V_2 -> V_122 [ V_63 ] ) ;
F_6 ( V_2 -> V_11 ,
F_16 ( V_63 ) ,
& V_2 -> V_123 [ V_63 ] ) ;
}
break;
default:
F_4 () ;
}
if ( F_86 ( V_124 ) )
F_67 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_85 ( V_93 ) ;
int V_63 ;
F_8 ( V_2 -> V_11 , V_27 + V_2 -> V_5 ,
V_2 -> V_118 ) ;
F_8 ( V_2 -> V_11 , V_29 + V_2 -> V_5 ,
V_2 -> V_119 ) ;
F_8 ( V_2 -> V_11 , V_34 + V_2 -> V_5 ,
V_2 -> V_120 ) ;
F_8 ( V_2 -> V_11 , V_33 + V_2 -> V_5 ,
V_2 -> V_121 ) ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_10 :
F_8 ( V_2 -> V_11 , V_16 + V_2 -> V_5 ,
V_2 -> V_122 [ 0 ] ) ;
F_8 ( V_2 -> V_11 , V_17 + V_2 -> V_5 ,
V_2 -> V_123 [ 0 ] ) ;
break;
case V_9 :
for ( V_63 = 0 ; V_63 < 2 ; V_63 ++ ) {
F_8 ( V_2 -> V_11 ,
F_10 ( V_63 ) ,
V_2 -> V_122 [ V_63 ] ) ;
F_8 ( V_2 -> V_11 ,
F_15 ( V_63 ) ,
V_2 -> V_123 [ V_63 ] ) ;
}
break;
case V_13 :
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
F_8 ( V_2 -> V_11 ,
F_11 ( V_63 ) ,
V_2 -> V_122 [ V_63 ] ) ;
F_8 ( V_2 -> V_11 ,
F_16 ( V_63 ) ,
V_2 -> V_123 [ V_63 ] ) ;
}
break;
default:
F_4 () ;
}
if ( F_86 ( V_124 ) )
F_68 ( V_2 ) ;
return 0 ;
}
static int F_88 ( struct V_92 * V_93 ,
struct V_1 * V_2 )
{
struct V_97 * V_98 ;
void T_2 * V_36 ;
V_98 = F_89 ( V_93 , V_102 , 0 ) ;
V_36 = F_75 ( & V_93 -> V_96 , V_98 ) ;
if ( F_71 ( V_36 ) )
return F_72 ( V_36 ) ;
V_2 -> V_11 = F_90 ( & V_93 -> V_96 , V_36 ,
& V_125 ) ;
if ( F_71 ( V_2 -> V_11 ) )
return F_72 ( V_2 -> V_11 ) ;
V_2 -> V_5 = 0 ;
if ( V_2 -> V_7 == V_13 ) {
V_98 = F_89 ( V_93 , V_102 , 1 ) ;
V_36 = F_75 ( & V_93 -> V_96 , V_98 ) ;
if ( F_71 ( V_36 ) )
return F_72 ( V_36 ) ;
V_2 -> V_14 =
F_90 ( & V_93 -> V_96 , V_36 ,
& V_125 ) ;
if ( F_71 ( V_2 -> V_14 ) )
return F_72 ( V_2 -> V_14 ) ;
}
return 0 ;
}
static int F_91 ( struct V_92 * V_93 ,
struct V_1 * V_2 )
{
V_2 -> V_11 = F_92 ( V_93 -> V_96 . V_126 -> V_100 ) ;
if ( F_71 ( V_2 -> V_11 ) )
return F_72 ( V_2 -> V_11 ) ;
if ( F_93 ( V_93 -> V_96 . V_100 , L_18 , & V_2 -> V_5 ) )
return - V_48 ;
return 0 ;
}
static int F_94 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
const struct V_127 * V_128 ;
struct V_129 * V_130 = V_93 -> V_96 . V_100 ;
struct V_40 * V_41 ;
struct V_44 * V_45 ;
unsigned int V_131 ;
bool V_132 ;
int V_7 ;
int V_63 , V_6 , V_94 ;
int V_133 ;
V_128 = F_95 ( V_134 , & V_93 -> V_96 ) ;
if ( V_128 )
V_7 = ( unsigned long ) V_128 -> V_135 ;
else
V_7 = V_8 ;
V_132 = F_96 ( V_130 ) != 0 ;
V_2 = F_74 ( & V_93 -> V_96 , sizeof( struct V_1 ) ,
V_104 ) ;
if ( ! V_2 )
return - V_105 ;
F_97 ( V_93 , V_2 ) ;
if ( F_93 ( V_93 -> V_96 . V_100 , L_19 , & V_131 ) ) {
F_77 ( & V_93 -> V_96 , L_20 ) ;
return - V_76 ;
}
V_94 = F_98 ( V_93 -> V_96 . V_100 , L_21 ) ;
if ( V_94 < 0 ) {
F_77 ( & V_93 -> V_96 , L_22 ) ;
return V_94 ;
}
V_2 -> V_101 = F_99 ( & V_93 -> V_96 , NULL ) ;
if ( ! F_71 ( V_2 -> V_101 ) )
F_100 ( V_2 -> V_101 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_24 . V_115 = F_101 ( & V_93 -> V_96 ) ;
V_2 -> V_24 . V_126 = & V_93 -> V_96 ;
V_2 -> V_24 . V_136 = V_137 ;
V_2 -> V_24 . free = V_138 ;
V_2 -> V_24 . V_139 = F_27 ;
V_2 -> V_24 . V_140 = F_25 ;
V_2 -> V_24 . V_141 = F_29 ;
V_2 -> V_24 . V_99 = F_21 ;
if ( V_132 )
V_2 -> V_24 . V_142 = F_31 ;
V_2 -> V_24 . V_36 = V_94 * V_143 ;
V_2 -> V_24 . V_64 = V_131 ;
V_2 -> V_24 . V_144 = false ;
V_2 -> V_24 . V_100 = V_130 ;
V_2 -> V_24 . V_145 = F_80 ;
if ( V_7 == V_10 )
V_133 = F_91 ( V_93 , V_2 ) ;
else
V_133 = F_88 ( V_93 , V_2 ) ;
if ( V_133 )
return V_133 ;
switch ( V_7 ) {
case V_8 :
case V_10 :
F_8 ( V_2 -> V_11 ,
V_12 + V_2 -> V_5 , 0 ) ;
F_8 ( V_2 -> V_11 ,
V_16 + V_2 -> V_5 , 0 ) ;
F_8 ( V_2 -> V_11 ,
V_17 + V_2 -> V_5 , 0 ) ;
break;
case V_9 :
F_8 ( V_2 -> V_11 , V_12 , 0 ) ;
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
F_8 ( V_2 -> V_11 ,
F_10 ( V_6 ) , 0 ) ;
F_8 ( V_2 -> V_11 ,
F_15 ( V_6 ) , 0 ) ;
}
break;
case V_13 :
F_8 ( V_2 -> V_11 , V_12 , 0 ) ;
F_8 ( V_2 -> V_11 , V_16 , 0 ) ;
F_8 ( V_2 -> V_11 , V_17 , 0 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
F_8 ( V_2 -> V_14 ,
F_3 ( V_6 ) , 0 ) ;
F_8 ( V_2 -> V_14 ,
F_11 ( V_6 ) , 0 ) ;
F_8 ( V_2 -> V_14 ,
F_16 ( V_6 ) , 0 ) ;
}
break;
default:
F_4 () ;
}
F_102 ( & V_93 -> V_96 , & V_2 -> V_24 , V_2 ) ;
if ( ! V_132 )
return 0 ;
V_2 -> V_37 =
F_103 ( V_130 , V_131 , & V_146 , NULL ) ;
if ( ! V_2 -> V_37 ) {
F_77 ( & V_93 -> V_96 , L_23 ,
V_2 -> V_24 . V_115 ) ;
return - V_76 ;
}
V_133 = F_104 (
V_2 -> V_37 , V_131 , 2 , V_130 -> V_147 , V_148 ,
V_149 | V_150 | V_151 , 0 , 0 ) ;
if ( V_133 ) {
F_77 ( & V_93 -> V_96 , L_24 ,
V_2 -> V_24 . V_115 ) ;
goto V_152;
}
V_41 = F_105 ( V_2 -> V_37 , 0 ) ;
V_41 -> V_42 = V_2 ;
V_45 = & V_41 -> V_153 [ 0 ] ;
V_45 -> type = V_52 | V_54 ;
V_45 -> V_24 . V_154 = F_40 ;
V_45 -> V_24 . V_155 = F_41 ;
V_45 -> V_24 . V_156 = F_42 ;
V_45 -> V_24 . V_147 = V_2 -> V_24 . V_115 ;
V_45 = & V_41 -> V_153 [ 1 ] ;
V_45 -> type = V_51 | V_53 ;
V_45 -> V_24 . V_157 = F_33 ;
V_45 -> V_24 . V_154 = F_37 ;
V_45 -> V_24 . V_155 = F_39 ;
V_45 -> V_24 . V_156 = F_42 ;
V_45 -> V_158 = V_159 ;
V_45 -> V_24 . V_147 = V_2 -> V_24 . V_115 ;
for ( V_63 = 0 ; V_63 < 4 ; V_63 ++ ) {
int V_65 = F_106 ( V_93 , V_63 ) ;
if ( V_65 < 0 )
continue;
F_107 ( V_65 , F_44 ,
V_2 ) ;
}
if ( F_86 ( V_124 ) )
return F_69 ( V_93 , V_2 , V_94 ) ;
return 0 ;
V_152:
F_108 ( V_2 -> V_37 ) ;
return V_133 ;
}
