static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_4 ;
}
static inline void T_1 * F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_5 ;
}
static inline void T_1 *
F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_6 ;
}
static inline void T_1 * F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_7 ;
}
static inline void T_1 *
F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_8 ;
}
static inline void T_1 *
F_6 ( struct V_1 * V_2 )
{
int V_9 ;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_12 :
return V_2 -> V_3 + V_13 ;
case V_14 :
V_9 = F_7 () ;
return V_2 -> V_15 +
F_8 ( V_9 ) ;
default:
F_9 () ;
}
}
static inline void T_1 *
F_10 ( struct V_1 * V_2 )
{
int V_9 ;
switch ( V_2 -> V_10 ) {
case V_11 :
return V_2 -> V_3 + V_16 ;
case V_12 :
V_9 = F_7 () ;
return V_2 -> V_3 + F_11 ( V_9 ) ;
case V_14 :
V_9 = F_7 () ;
return V_2 -> V_15 +
F_12 ( V_9 ) ;
default:
F_9 () ;
}
}
static void T_1 * F_13 ( struct V_1 * V_2 )
{
int V_9 ;
switch ( V_2 -> V_10 ) {
case V_11 :
return V_2 -> V_3 + V_17 ;
case V_12 :
V_9 = F_7 () ;
return V_2 -> V_3 + F_14 ( V_9 ) ;
case V_14 :
V_9 = F_7 () ;
return V_2 -> V_15 +
F_15 ( V_9 ) ;
default:
F_9 () ;
}
}
static void F_16 ( struct V_18 * V_19 , unsigned V_20 , int V_21 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
unsigned long V_22 ;
T_2 V_23 ;
F_18 ( & V_2 -> V_24 , V_22 ) ;
V_23 = F_19 ( F_1 ( V_2 ) ) ;
if ( V_21 )
V_23 |= 1 << V_20 ;
else
V_23 &= ~ ( 1 << V_20 ) ;
F_20 ( V_23 , F_1 ( V_2 ) ) ;
F_21 ( & V_2 -> V_24 , V_22 ) ;
}
static int F_22 ( struct V_18 * V_19 , unsigned V_20 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_2 V_23 ;
if ( F_19 ( F_3 ( V_2 ) ) & ( 1 << V_20 ) ) {
V_23 = F_19 ( F_5 ( V_2 ) ) ^
F_19 ( F_4 ( V_2 ) ) ;
} else {
V_23 = F_19 ( F_1 ( V_2 ) ) ;
}
return ( V_23 >> V_20 ) & 1 ;
}
static void F_23 ( struct V_18 * V_19 , unsigned V_20 , int V_21 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
unsigned long V_22 ;
T_2 V_23 ;
F_18 ( & V_2 -> V_24 , V_22 ) ;
V_23 = F_19 ( F_2 ( V_2 ) ) ;
if ( V_21 )
V_23 |= 1 << V_20 ;
else
V_23 &= ~ ( 1 << V_20 ) ;
F_20 ( V_23 , F_2 ( V_2 ) ) ;
F_21 ( & V_2 -> V_24 , V_22 ) ;
}
static int F_24 ( struct V_18 * V_19 , unsigned V_20 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
unsigned long V_22 ;
int V_25 ;
T_2 V_23 ;
V_25 = F_25 ( V_19 -> V_26 + V_20 ) ;
if ( V_25 )
return V_25 ;
F_18 ( & V_2 -> V_24 , V_22 ) ;
V_23 = F_19 ( F_3 ( V_2 ) ) ;
V_23 |= 1 << V_20 ;
F_20 ( V_23 , F_3 ( V_2 ) ) ;
F_21 ( & V_2 -> V_24 , V_22 ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , unsigned V_20 ,
int V_21 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
unsigned long V_22 ;
int V_25 ;
T_2 V_23 ;
V_25 = F_27 ( V_19 -> V_26 + V_20 ) ;
if ( V_25 )
return V_25 ;
F_23 ( V_19 , V_20 , 0 ) ;
F_16 ( V_19 , V_20 , V_21 ) ;
F_18 ( & V_2 -> V_24 , V_22 ) ;
V_23 = F_19 ( F_3 ( V_2 ) ) ;
V_23 &= ~ ( 1 << V_20 ) ;
F_20 ( V_23 , F_3 ( V_2 ) ) ;
F_21 ( & V_2 -> V_24 , V_22 ) ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 , unsigned V_20 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
return F_29 ( V_2 -> V_27 , V_20 ) ;
}
static void F_30 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
T_2 V_33 = ~ ( 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ) ;
F_32 ( V_31 ) ;
F_20 ( V_33 , F_6 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_34 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_36 * V_37 = F_35 ( V_29 ) ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_32 ( V_31 ) ;
V_37 -> V_38 &= ~ V_33 ;
F_20 ( V_37 -> V_38 , F_10 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_36 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_36 * V_37 = F_35 ( V_29 ) ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_32 ( V_31 ) ;
V_37 -> V_38 |= V_33 ;
F_20 ( V_37 -> V_38 , F_10 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_37 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_36 * V_37 = F_35 ( V_29 ) ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_32 ( V_31 ) ;
V_37 -> V_38 &= ~ V_33 ;
F_20 ( V_37 -> V_38 , F_13 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_38 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_36 * V_37 = F_35 ( V_29 ) ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_32 ( V_31 ) ;
V_37 -> V_38 |= V_33 ;
F_20 ( V_37 -> V_38 , F_13 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static int F_39 ( struct V_28 * V_29 , unsigned int type )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_36 * V_37 = F_35 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
int V_20 ;
T_2 V_23 ;
V_20 = V_29 -> V_39 ;
V_23 = F_19 ( F_3 ( V_2 ) ) & ( 1 << V_20 ) ;
if ( ! V_23 )
return - V_40 ;
type &= V_41 ;
if ( type == V_42 )
return - V_40 ;
if ( ! ( V_37 -> type & type ) )
if ( F_40 ( V_29 , type ) )
return - V_40 ;
switch ( type ) {
case V_43 :
case V_44 :
V_23 = F_19 ( F_4 ( V_2 ) ) ;
V_23 &= ~ ( 1 << V_20 ) ;
F_20 ( V_23 , F_4 ( V_2 ) ) ;
break;
case V_45 :
case V_46 :
V_23 = F_19 ( F_4 ( V_2 ) ) ;
V_23 |= 1 << V_20 ;
F_20 ( V_23 , F_4 ( V_2 ) ) ;
break;
case V_47 : {
T_2 V_48 ;
V_48 = F_19 ( F_4 ( V_2 ) ) ^
F_19 ( F_5 ( V_2 ) ) ;
V_23 = F_19 ( F_4 ( V_2 ) ) ;
if ( V_48 & ( 1 << V_20 ) )
V_23 |= 1 << V_20 ;
else
V_23 &= ~ ( 1 << V_20 ) ;
F_20 ( V_23 , F_4 ( V_2 ) ) ;
break;
}
}
return 0 ;
}
static void F_41 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_42 ( V_50 ) ;
struct V_51 * V_19 = F_43 ( V_50 ) ;
T_2 V_52 , type ;
int V_53 ;
if ( V_2 == NULL )
return;
F_44 ( V_19 , V_50 ) ;
V_52 = F_19 ( F_5 ( V_2 ) ) &
F_19 ( F_13 ( V_2 ) ) ;
V_52 |= F_19 ( F_6 ( V_2 ) ) &
F_19 ( F_10 ( V_2 ) ) ;
for ( V_53 = 0 ; V_53 < V_2 -> V_19 . V_54 ; V_53 ++ ) {
int V_34 ;
V_34 = V_2 -> V_55 + V_53 ;
if ( ! ( V_52 & ( 1 << V_53 ) ) )
continue;
type = F_45 ( V_34 ) ;
if ( ( type & V_41 ) == V_47 ) {
T_2 V_56 ;
V_56 = F_19 ( F_4 ( V_2 ) ) ;
V_56 ^= 1 << V_53 ;
F_20 ( V_56 , F_4 ( V_2 ) ) ;
}
F_46 ( V_34 ) ;
}
F_47 ( V_19 , V_50 ) ;
}
static void F_48 ( struct V_57 * V_58 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_2 V_59 , V_60 , V_61 , V_62 , V_63 , V_52 , V_64 , V_65 ;
int V_53 ;
V_59 = F_19 ( F_1 ( V_2 ) ) ;
V_60 = F_19 ( F_3 ( V_2 ) ) ;
V_61 = F_19 ( F_2 ( V_2 ) ) ;
V_62 = F_19 ( F_4 ( V_2 ) ) ;
V_63 = F_19 ( F_5 ( V_2 ) ) ;
V_52 = F_19 ( F_6 ( V_2 ) ) ;
V_64 = F_19 ( F_10 ( V_2 ) ) ;
V_65 = F_19 ( F_13 ( V_2 ) ) ;
for ( V_53 = 0 ; V_53 < V_19 -> V_54 ; V_53 ++ ) {
const char * V_66 ;
T_2 V_67 ;
bool V_68 ;
V_66 = F_49 ( V_19 , V_53 ) ;
if ( ! V_66 )
continue;
V_67 = 1 << V_53 ;
V_68 = ! ( V_60 & V_67 ) ;
F_50 ( V_58 , L_1 , V_19 -> V_26 + V_53 , V_66 ) ;
if ( V_68 ) {
F_50 ( V_58 , L_2 ,
V_59 & V_67 ? L_3 : L_4 ,
V_61 & V_67 ? L_5 : L_6 ) ;
continue;
}
F_50 ( V_58 , L_7 ,
( V_63 ^ V_62 ) & V_67 ? L_3 : L_4 ,
V_62 & V_67 ? L_4 : L_3 ) ;
if ( ! ( ( V_64 | V_65 ) & V_67 ) ) {
F_51 ( V_58 , L_8 ) ;
continue;
}
if ( V_64 & V_67 )
F_51 ( V_58 , L_9 ) ;
if ( V_65 & V_67 )
F_51 ( V_58 , L_10 ) ;
F_50 ( V_58 , L_11 , V_52 & V_67 ? L_12 : L_13 ) ;
}
}
static int F_52 ( struct V_69 * V_70 , T_3 V_71 )
{
struct V_1 * V_2 = F_53 ( V_70 ) ;
int V_53 ;
V_2 -> V_72 = F_54 ( F_1 ( V_2 ) ) ;
V_2 -> V_73 = F_54 ( F_3 ( V_2 ) ) ;
V_2 -> V_74 = F_54 ( F_2 ( V_2 ) ) ;
V_2 -> V_75 = F_54 ( F_4 ( V_2 ) ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_2 -> V_76 [ 0 ] =
F_54 ( V_2 -> V_3 + V_16 ) ;
V_2 -> V_77 [ 0 ] =
F_54 ( V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
V_2 -> V_76 [ V_53 ] =
F_54 ( V_2 -> V_3 +
F_11 ( V_53 ) ) ;
V_2 -> V_77 [ V_53 ] =
F_54 ( V_2 -> V_3 +
F_14 ( V_53 ) ) ;
}
break;
case V_14 :
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
V_2 -> V_76 [ V_53 ] =
F_54 ( V_2 -> V_3 +
F_12 ( V_53 ) ) ;
V_2 -> V_77 [ V_53 ] =
F_54 ( V_2 -> V_3 +
F_15 ( V_53 ) ) ;
}
break;
default:
F_9 () ;
}
return 0 ;
}
static int F_55 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_53 ( V_70 ) ;
int V_53 ;
F_56 ( V_2 -> V_72 , F_1 ( V_2 ) ) ;
F_56 ( V_2 -> V_73 , F_3 ( V_2 ) ) ;
F_56 ( V_2 -> V_74 , F_2 ( V_2 ) ) ;
F_56 ( V_2 -> V_75 , F_4 ( V_2 ) ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
F_56 ( V_2 -> V_76 [ 0 ] ,
V_2 -> V_3 + V_16 ) ;
F_56 ( V_2 -> V_77 [ 0 ] ,
V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
F_56 ( V_2 -> V_76 [ V_53 ] ,
V_2 -> V_3 + F_11 ( V_53 ) ) ;
F_56 ( V_2 -> V_77 [ V_53 ] ,
V_2 -> V_3 +
F_14 ( V_53 ) ) ;
}
break;
case V_14 :
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
F_56 ( V_2 -> V_76 [ V_53 ] ,
V_2 -> V_3 +
F_12 ( V_53 ) ) ;
F_56 ( V_2 -> V_77 [ V_53 ] ,
V_2 -> V_3 +
F_15 ( V_53 ) ) ;
}
break;
default:
F_9 () ;
}
return 0 ;
}
static int F_57 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
const struct V_78 * V_79 ;
struct V_80 * V_81 = V_70 -> V_82 . V_83 ;
struct V_84 * V_85 ;
struct V_30 * V_31 ;
struct V_36 * V_37 ;
struct V_86 * V_86 ;
unsigned int V_87 ;
int V_10 ;
int V_53 , V_9 , V_88 ;
int V_89 ;
V_79 = F_58 ( V_90 , & V_70 -> V_82 ) ;
if ( V_79 )
V_10 = ( int ) V_79 -> V_91 ;
else
V_10 = V_11 ;
V_2 = F_59 ( & V_70 -> V_82 , sizeof( struct V_1 ) ,
V_92 ) ;
if ( ! V_2 )
return - V_93 ;
F_60 ( V_70 , V_2 ) ;
if ( F_61 ( V_70 -> V_82 . V_83 , L_14 , & V_87 ) ) {
F_62 ( & V_70 -> V_82 , L_15 ) ;
return - V_94 ;
}
V_88 = F_63 ( V_70 -> V_82 . V_83 , L_16 ) ;
if ( V_88 < 0 ) {
F_62 ( & V_70 -> V_82 , L_17 ) ;
return V_88 ;
}
V_86 = F_64 ( & V_70 -> V_82 , NULL ) ;
if ( ! F_65 ( V_86 ) )
F_66 ( V_86 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_19 . V_66 = F_67 ( & V_70 -> V_82 ) ;
V_2 -> V_19 . V_95 = & V_70 -> V_82 ;
V_2 -> V_19 . V_96 = V_97 ;
V_2 -> V_19 . free = V_98 ;
V_2 -> V_19 . V_99 = F_24 ;
V_2 -> V_19 . V_100 = F_22 ;
V_2 -> V_19 . V_101 = F_26 ;
V_2 -> V_19 . V_102 = F_16 ;
V_2 -> V_19 . V_103 = F_28 ;
V_2 -> V_19 . V_26 = V_88 * V_104 ;
V_2 -> V_19 . V_54 = V_87 ;
V_2 -> V_19 . V_105 = false ;
V_2 -> V_19 . V_83 = V_81 ;
V_2 -> V_19 . V_106 = F_48 ;
F_68 ( & V_2 -> V_24 ) ;
V_85 = F_69 ( V_70 , V_107 , 0 ) ;
V_2 -> V_3 = F_70 ( & V_70 -> V_82 , V_85 ) ;
if ( F_65 ( V_2 -> V_3 ) )
return F_71 ( V_2 -> V_3 ) ;
if ( V_10 == V_14 ) {
V_85 = F_69 ( V_70 , V_107 , 1 ) ;
V_2 -> V_15 = F_70 ( & V_70 -> V_82 ,
V_85 ) ;
if ( F_65 ( V_2 -> V_15 ) )
return F_71 ( V_2 -> V_15 ) ;
}
switch ( V_10 ) {
case V_11 :
F_20 ( 0 , V_2 -> V_3 + V_13 ) ;
F_20 ( 0 , V_2 -> V_3 + V_16 ) ;
F_20 ( 0 , V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
F_20 ( 0 , V_2 -> V_3 + V_13 ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
F_20 ( 0 , V_2 -> V_3 +
F_11 ( V_9 ) ) ;
F_20 ( 0 , V_2 -> V_3 +
F_14 ( V_9 ) ) ;
}
break;
case V_14 :
F_20 ( 0 , V_2 -> V_3 + V_13 ) ;
F_20 ( 0 , V_2 -> V_3 + V_16 ) ;
F_20 ( 0 , V_2 -> V_3 + V_17 ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
F_20 ( 0 , V_2 -> V_15 +
F_8 ( V_9 ) ) ;
F_20 ( 0 , V_2 -> V_15 +
F_12 ( V_9 ) ) ;
F_20 ( 0 , V_2 -> V_15 +
F_15 ( V_9 ) ) ;
}
break;
default:
F_9 () ;
}
F_72 ( & V_70 -> V_82 , & V_2 -> V_19 , V_2 ) ;
if ( ! F_73 ( V_81 ) )
return 0 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
int V_34 = F_74 ( V_70 , V_53 ) ;
if ( V_34 < 0 )
continue;
F_75 ( V_34 , F_41 ,
V_2 ) ;
}
V_2 -> V_55 = F_76 ( - 1 , 0 , V_87 , - 1 ) ;
if ( V_2 -> V_55 < 0 ) {
F_62 ( & V_70 -> V_82 , L_18 ) ;
return V_2 -> V_55 ;
}
V_31 = F_77 ( L_19 , 2 , V_2 -> V_55 ,
V_2 -> V_3 , V_108 ) ;
if ( ! V_31 ) {
F_62 ( & V_70 -> V_82 , L_20 ) ;
return - V_93 ;
}
V_31 -> V_32 = V_2 ;
V_37 = & V_31 -> V_109 [ 0 ] ;
V_37 -> type = V_44 | V_46 ;
V_37 -> V_19 . V_110 = F_37 ;
V_37 -> V_19 . V_111 = F_38 ;
V_37 -> V_19 . V_112 = F_39 ;
V_37 -> V_19 . V_113 = V_2 -> V_19 . V_66 ;
V_37 = & V_31 -> V_109 [ 1 ] ;
V_37 -> type = V_43 | V_45 ;
V_37 -> V_19 . V_114 = F_30 ;
V_37 -> V_19 . V_110 = F_34 ;
V_37 -> V_19 . V_111 = F_36 ;
V_37 -> V_19 . V_112 = F_39 ;
V_37 -> V_115 = V_116 ;
V_37 -> V_19 . V_113 = V_2 -> V_19 . V_66 ;
F_78 ( V_31 , F_79 ( V_87 ) , 0 ,
V_117 , V_118 | V_119 ) ;
V_2 -> V_27 = F_80 ( V_81 , V_2 -> V_19 . V_54 ,
V_2 -> V_55 ,
& V_120 ,
V_2 ) ;
if ( ! V_2 -> V_27 ) {
F_62 ( & V_70 -> V_82 , L_21 ,
V_2 -> V_19 . V_66 ) ;
V_89 = - V_94 ;
goto V_121;
}
return 0 ;
V_121:
F_81 ( V_31 , F_79 ( V_87 ) , V_117 ,
V_118 | V_119 ) ;
F_82 ( V_31 ) ;
return V_89 ;
}
