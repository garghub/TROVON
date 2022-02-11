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
T_2 V_33 = V_29 -> V_33 ;
F_32 ( V_31 ) ;
F_20 ( ~ V_33 , F_6 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_34 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_34 * V_35 = F_35 ( V_29 ) ;
T_2 V_33 = V_29 -> V_33 ;
F_32 ( V_31 ) ;
V_35 -> V_36 &= ~ V_33 ;
F_20 ( V_35 -> V_36 , F_10 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_36 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_34 * V_35 = F_35 ( V_29 ) ;
T_2 V_33 = V_29 -> V_33 ;
F_32 ( V_31 ) ;
V_35 -> V_36 |= V_33 ;
F_20 ( V_35 -> V_36 , F_10 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_37 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_34 * V_35 = F_35 ( V_29 ) ;
T_2 V_33 = V_29 -> V_33 ;
F_32 ( V_31 ) ;
V_35 -> V_36 &= ~ V_33 ;
F_20 ( V_35 -> V_36 , F_13 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static void F_38 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_34 * V_35 = F_35 ( V_29 ) ;
T_2 V_33 = V_29 -> V_33 ;
F_32 ( V_31 ) ;
V_35 -> V_36 |= V_33 ;
F_20 ( V_35 -> V_36 , F_13 ( V_2 ) ) ;
F_33 ( V_31 ) ;
}
static int F_39 ( struct V_28 * V_29 , unsigned int type )
{
struct V_30 * V_31 = F_31 ( V_29 ) ;
struct V_34 * V_35 = F_35 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
int V_20 ;
T_2 V_23 ;
V_20 = V_29 -> V_37 ;
V_23 = F_19 ( F_3 ( V_2 ) ) & ( 1 << V_20 ) ;
if ( ! V_23 )
return - V_38 ;
type &= V_39 ;
if ( type == V_40 )
return - V_38 ;
if ( ! ( V_35 -> type & type ) )
if ( F_40 ( V_29 , type ) )
return - V_38 ;
switch ( type ) {
case V_41 :
case V_42 :
V_23 = F_19 ( F_4 ( V_2 ) ) ;
V_23 &= ~ ( 1 << V_20 ) ;
F_20 ( V_23 , F_4 ( V_2 ) ) ;
break;
case V_43 :
case V_44 :
V_23 = F_19 ( F_4 ( V_2 ) ) ;
V_23 |= 1 << V_20 ;
F_20 ( V_23 , F_4 ( V_2 ) ) ;
break;
case V_45 : {
T_2 V_46 ;
V_46 = F_19 ( F_4 ( V_2 ) ) ^
F_19 ( F_5 ( V_2 ) ) ;
V_23 = F_19 ( F_4 ( V_2 ) ) ;
if ( V_46 & ( 1 << V_20 ) )
V_23 |= 1 << V_20 ;
else
V_23 &= ~ ( 1 << V_20 ) ;
F_20 ( V_23 , F_4 ( V_2 ) ) ;
break;
}
}
return 0 ;
}
static void F_41 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_42 ( V_48 ) ;
struct V_49 * V_19 = F_43 ( V_48 ) ;
T_2 V_50 , type ;
int V_51 ;
if ( V_2 == NULL )
return;
F_44 ( V_19 , V_48 ) ;
V_50 = F_19 ( F_5 ( V_2 ) ) &
F_19 ( F_13 ( V_2 ) ) ;
V_50 |= F_19 ( F_6 ( V_2 ) ) &
F_19 ( F_10 ( V_2 ) ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_19 . V_52 ; V_51 ++ ) {
int V_53 ;
V_53 = F_45 ( V_2 -> V_27 , V_51 ) ;
if ( ! ( V_50 & ( 1 << V_51 ) ) )
continue;
type = F_46 ( V_53 ) ;
if ( ( type & V_39 ) == V_45 ) {
T_2 V_54 ;
V_54 = F_19 ( F_4 ( V_2 ) ) ;
V_54 ^= 1 << V_51 ;
F_20 ( V_54 , F_4 ( V_2 ) ) ;
}
F_47 ( V_53 ) ;
}
F_48 ( V_19 , V_48 ) ;
}
static void F_49 ( struct V_55 * V_56 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_17 ( V_19 ) ;
T_2 V_57 , V_58 , V_59 , V_60 , V_61 , V_50 , V_62 , V_63 ;
int V_51 ;
V_57 = F_19 ( F_1 ( V_2 ) ) ;
V_58 = F_19 ( F_3 ( V_2 ) ) ;
V_59 = F_19 ( F_2 ( V_2 ) ) ;
V_60 = F_19 ( F_4 ( V_2 ) ) ;
V_61 = F_19 ( F_5 ( V_2 ) ) ;
V_50 = F_19 ( F_6 ( V_2 ) ) ;
V_62 = F_19 ( F_10 ( V_2 ) ) ;
V_63 = F_19 ( F_13 ( V_2 ) ) ;
for ( V_51 = 0 ; V_51 < V_19 -> V_52 ; V_51 ++ ) {
const char * V_64 ;
T_2 V_65 ;
bool V_66 ;
V_64 = F_50 ( V_19 , V_51 ) ;
if ( ! V_64 )
continue;
V_65 = 1 << V_51 ;
V_66 = ! ( V_58 & V_65 ) ;
F_51 ( V_56 , L_1 , V_19 -> V_26 + V_51 , V_64 ) ;
if ( V_66 ) {
F_51 ( V_56 , L_2 ,
V_57 & V_65 ? L_3 : L_4 ,
V_59 & V_65 ? L_5 : L_6 ) ;
continue;
}
F_51 ( V_56 , L_7 ,
( V_61 ^ V_60 ) & V_65 ? L_3 : L_4 ,
V_60 & V_65 ? L_4 : L_3 ) ;
if ( ! ( ( V_62 | V_63 ) & V_65 ) ) {
F_52 ( V_56 , L_8 ) ;
continue;
}
if ( V_62 & V_65 )
F_52 ( V_56 , L_9 ) ;
if ( V_63 & V_65 )
F_52 ( V_56 , L_10 ) ;
F_51 ( V_56 , L_11 , V_50 & V_65 ? L_12 : L_13 ) ;
}
}
static int F_53 ( struct V_67 * V_68 , T_3 V_69 )
{
struct V_1 * V_2 = F_54 ( V_68 ) ;
int V_51 ;
V_2 -> V_70 = F_55 ( F_1 ( V_2 ) ) ;
V_2 -> V_71 = F_55 ( F_3 ( V_2 ) ) ;
V_2 -> V_72 = F_55 ( F_2 ( V_2 ) ) ;
V_2 -> V_73 = F_55 ( F_4 ( V_2 ) ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_2 -> V_74 [ 0 ] =
F_55 ( V_2 -> V_3 + V_16 ) ;
V_2 -> V_75 [ 0 ] =
F_55 ( V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
V_2 -> V_74 [ V_51 ] =
F_55 ( V_2 -> V_3 +
F_11 ( V_51 ) ) ;
V_2 -> V_75 [ V_51 ] =
F_55 ( V_2 -> V_3 +
F_14 ( V_51 ) ) ;
}
break;
case V_14 :
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
V_2 -> V_74 [ V_51 ] =
F_55 ( V_2 -> V_3 +
F_12 ( V_51 ) ) ;
V_2 -> V_75 [ V_51 ] =
F_55 ( V_2 -> V_3 +
F_15 ( V_51 ) ) ;
}
break;
default:
F_9 () ;
}
return 0 ;
}
static int F_56 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_54 ( V_68 ) ;
int V_51 ;
F_57 ( V_2 -> V_70 , F_1 ( V_2 ) ) ;
F_57 ( V_2 -> V_71 , F_3 ( V_2 ) ) ;
F_57 ( V_2 -> V_72 , F_2 ( V_2 ) ) ;
F_57 ( V_2 -> V_73 , F_4 ( V_2 ) ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
F_57 ( V_2 -> V_74 [ 0 ] ,
V_2 -> V_3 + V_16 ) ;
F_57 ( V_2 -> V_75 [ 0 ] ,
V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
F_57 ( V_2 -> V_74 [ V_51 ] ,
V_2 -> V_3 + F_11 ( V_51 ) ) ;
F_57 ( V_2 -> V_75 [ V_51 ] ,
V_2 -> V_3 +
F_14 ( V_51 ) ) ;
}
break;
case V_14 :
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
F_57 ( V_2 -> V_74 [ V_51 ] ,
V_2 -> V_3 +
F_12 ( V_51 ) ) ;
F_57 ( V_2 -> V_75 [ V_51 ] ,
V_2 -> V_3 +
F_15 ( V_51 ) ) ;
}
break;
default:
F_9 () ;
}
return 0 ;
}
static int F_58 ( struct V_67 * V_68 )
{
struct V_1 * V_2 ;
const struct V_76 * V_77 ;
struct V_78 * V_79 = V_68 -> V_80 . V_81 ;
struct V_82 * V_83 ;
struct V_30 * V_31 ;
struct V_34 * V_35 ;
struct V_84 * V_84 ;
unsigned int V_85 ;
bool V_86 ;
int V_10 ;
int V_51 , V_9 , V_87 ;
int V_88 ;
V_77 = F_59 ( V_89 , & V_68 -> V_80 ) ;
if ( V_77 )
V_10 = ( int ) V_77 -> V_90 ;
else
V_10 = V_11 ;
V_86 = F_60 ( V_79 ) != 0 ;
V_2 = F_61 ( & V_68 -> V_80 , sizeof( struct V_1 ) ,
V_91 ) ;
if ( ! V_2 )
return - V_92 ;
F_62 ( V_68 , V_2 ) ;
if ( F_63 ( V_68 -> V_80 . V_81 , L_14 , & V_85 ) ) {
F_64 ( & V_68 -> V_80 , L_15 ) ;
return - V_93 ;
}
V_87 = F_65 ( V_68 -> V_80 . V_81 , L_16 ) ;
if ( V_87 < 0 ) {
F_64 ( & V_68 -> V_80 , L_17 ) ;
return V_87 ;
}
V_84 = F_66 ( & V_68 -> V_80 , NULL ) ;
if ( ! F_67 ( V_84 ) )
F_68 ( V_84 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_19 . V_64 = F_69 ( & V_68 -> V_80 ) ;
V_2 -> V_19 . V_94 = & V_68 -> V_80 ;
V_2 -> V_19 . V_95 = V_96 ;
V_2 -> V_19 . free = V_97 ;
V_2 -> V_19 . V_98 = F_24 ;
V_2 -> V_19 . V_99 = F_22 ;
V_2 -> V_19 . V_100 = F_26 ;
V_2 -> V_19 . V_101 = F_16 ;
if ( V_86 )
V_2 -> V_19 . V_102 = F_28 ;
V_2 -> V_19 . V_26 = V_87 * V_103 ;
V_2 -> V_19 . V_52 = V_85 ;
V_2 -> V_19 . V_104 = false ;
V_2 -> V_19 . V_81 = V_79 ;
V_2 -> V_19 . V_105 = F_49 ;
F_70 ( & V_2 -> V_24 ) ;
V_83 = F_71 ( V_68 , V_106 , 0 ) ;
V_2 -> V_3 = F_72 ( & V_68 -> V_80 , V_83 ) ;
if ( F_67 ( V_2 -> V_3 ) )
return F_73 ( V_2 -> V_3 ) ;
if ( V_10 == V_14 ) {
V_83 = F_71 ( V_68 , V_106 , 1 ) ;
V_2 -> V_15 = F_72 ( & V_68 -> V_80 ,
V_83 ) ;
if ( F_67 ( V_2 -> V_15 ) )
return F_73 ( V_2 -> V_15 ) ;
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
F_74 ( & V_68 -> V_80 , & V_2 -> V_19 , V_2 ) ;
if ( ! V_86 )
return 0 ;
V_2 -> V_27 =
F_75 ( V_79 , V_85 , & V_107 , NULL ) ;
if ( ! V_2 -> V_27 ) {
F_64 ( & V_68 -> V_80 , L_18 ,
V_2 -> V_19 . V_64 ) ;
return - V_93 ;
}
V_88 = F_76 (
V_2 -> V_27 , V_85 , 2 , V_79 -> V_108 , V_109 ,
V_110 | V_111 | V_112 , 0 , 0 ) ;
if ( V_88 ) {
F_64 ( & V_68 -> V_80 , L_19 ,
V_2 -> V_19 . V_64 ) ;
goto V_113;
}
V_31 = F_77 ( V_2 -> V_27 , 0 ) ;
V_31 -> V_32 = V_2 ;
V_35 = & V_31 -> V_114 [ 0 ] ;
V_35 -> type = V_42 | V_44 ;
V_35 -> V_19 . V_115 = F_37 ;
V_35 -> V_19 . V_116 = F_38 ;
V_35 -> V_19 . V_117 = F_39 ;
V_35 -> V_19 . V_108 = V_2 -> V_19 . V_64 ;
V_35 = & V_31 -> V_114 [ 1 ] ;
V_35 -> type = V_41 | V_43 ;
V_35 -> V_19 . V_118 = F_30 ;
V_35 -> V_19 . V_115 = F_34 ;
V_35 -> V_19 . V_116 = F_36 ;
V_35 -> V_19 . V_117 = F_39 ;
V_35 -> V_119 = V_120 ;
V_35 -> V_19 . V_108 = V_2 -> V_19 . V_64 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
int V_53 = F_78 ( V_68 , V_51 ) ;
if ( V_53 < 0 )
continue;
F_79 ( V_53 , F_41 ,
V_2 ) ;
}
return 0 ;
V_113:
F_80 ( V_2 -> V_27 ) ;
return V_88 ;
}
