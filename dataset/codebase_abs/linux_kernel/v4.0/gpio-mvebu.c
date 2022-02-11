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
static int F_16 ( struct V_18 * V_19 , unsigned V_20 )
{
return F_17 ( V_19 -> V_21 + V_20 ) ;
}
static void F_18 ( struct V_18 * V_19 , unsigned V_20 )
{
F_19 ( V_19 -> V_21 + V_20 ) ;
}
static void F_20 ( struct V_18 * V_19 , unsigned V_20 , int V_22 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
unsigned long V_23 ;
T_2 V_24 ;
F_22 ( & V_2 -> V_25 , V_23 ) ;
V_24 = F_23 ( F_1 ( V_2 ) ) ;
if ( V_22 )
V_24 |= 1 << V_20 ;
else
V_24 &= ~ ( 1 << V_20 ) ;
F_24 ( V_24 , F_1 ( V_2 ) ) ;
F_25 ( & V_2 -> V_25 , V_23 ) ;
}
static int F_26 ( struct V_18 * V_19 , unsigned V_20 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
T_2 V_24 ;
if ( F_23 ( F_3 ( V_2 ) ) & ( 1 << V_20 ) ) {
V_24 = F_23 ( F_5 ( V_2 ) ) ^
F_23 ( F_4 ( V_2 ) ) ;
} else {
V_24 = F_23 ( F_1 ( V_2 ) ) ;
}
return ( V_24 >> V_20 ) & 1 ;
}
static void F_27 ( struct V_18 * V_19 , unsigned V_20 , int V_22 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
unsigned long V_23 ;
T_2 V_24 ;
F_22 ( & V_2 -> V_25 , V_23 ) ;
V_24 = F_23 ( F_2 ( V_2 ) ) ;
if ( V_22 )
V_24 |= 1 << V_20 ;
else
V_24 &= ~ ( 1 << V_20 ) ;
F_24 ( V_24 , F_2 ( V_2 ) ) ;
F_25 ( & V_2 -> V_25 , V_23 ) ;
}
static int F_28 ( struct V_18 * V_19 , unsigned V_20 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
unsigned long V_23 ;
int V_26 ;
T_2 V_24 ;
V_26 = F_29 ( V_19 -> V_21 + V_20 ) ;
if ( V_26 )
return V_26 ;
F_22 ( & V_2 -> V_25 , V_23 ) ;
V_24 = F_23 ( F_3 ( V_2 ) ) ;
V_24 |= 1 << V_20 ;
F_24 ( V_24 , F_3 ( V_2 ) ) ;
F_25 ( & V_2 -> V_25 , V_23 ) ;
return 0 ;
}
static int F_30 ( struct V_18 * V_19 , unsigned V_20 ,
int V_22 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
unsigned long V_23 ;
int V_26 ;
T_2 V_24 ;
V_26 = F_31 ( V_19 -> V_21 + V_20 ) ;
if ( V_26 )
return V_26 ;
F_27 ( V_19 , V_20 , 0 ) ;
F_20 ( V_19 , V_20 , V_22 ) ;
F_22 ( & V_2 -> V_25 , V_23 ) ;
V_24 = F_23 ( F_3 ( V_2 ) ) ;
V_24 &= ~ ( 1 << V_20 ) ;
F_24 ( V_24 , F_3 ( V_2 ) ) ;
F_25 ( & V_2 -> V_25 , V_23 ) ;
return 0 ;
}
static int F_32 ( struct V_18 * V_19 , unsigned V_20 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
return F_33 ( V_2 -> V_27 , V_20 ) ;
}
static void F_34 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_35 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
T_2 V_33 = ~ ( 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ) ;
F_36 ( V_31 ) ;
F_24 ( V_33 , F_6 ( V_2 ) ) ;
F_37 ( V_31 ) ;
}
static void F_38 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_35 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_36 ( V_31 ) ;
V_31 -> V_36 &= ~ V_33 ;
F_24 ( V_31 -> V_36 , F_10 ( V_2 ) ) ;
F_37 ( V_31 ) ;
}
static void F_39 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_35 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_36 ( V_31 ) ;
V_31 -> V_36 |= V_33 ;
F_24 ( V_31 -> V_36 , F_10 ( V_2 ) ) ;
F_37 ( V_31 ) ;
}
static void F_40 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_35 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_36 ( V_31 ) ;
V_31 -> V_36 &= ~ V_33 ;
F_24 ( V_31 -> V_36 , F_13 ( V_2 ) ) ;
F_37 ( V_31 ) ;
}
static void F_41 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_35 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
T_2 V_33 = 1 << ( V_29 -> V_34 - V_31 -> V_35 ) ;
F_36 ( V_31 ) ;
V_31 -> V_36 |= V_33 ;
F_24 ( V_31 -> V_36 , F_13 ( V_2 ) ) ;
F_37 ( V_31 ) ;
}
static int F_42 ( struct V_28 * V_29 , unsigned int type )
{
struct V_30 * V_31 = F_35 ( V_29 ) ;
struct V_37 * V_38 = F_43 ( V_29 ) ;
struct V_1 * V_2 = V_31 -> V_32 ;
int V_20 ;
T_2 V_24 ;
V_20 = V_29 -> V_39 ;
V_24 = F_23 ( F_3 ( V_2 ) ) & ( 1 << V_20 ) ;
if ( ! V_24 )
return - V_40 ;
type &= V_41 ;
if ( type == V_42 )
return - V_40 ;
if ( ! ( V_38 -> type & type ) )
if ( F_44 ( V_29 , type ) )
return - V_40 ;
switch ( type ) {
case V_43 :
case V_44 :
V_24 = F_23 ( F_4 ( V_2 ) ) ;
V_24 &= ~ ( 1 << V_20 ) ;
F_24 ( V_24 , F_4 ( V_2 ) ) ;
break;
case V_45 :
case V_46 :
V_24 = F_23 ( F_4 ( V_2 ) ) ;
V_24 |= 1 << V_20 ;
F_24 ( V_24 , F_4 ( V_2 ) ) ;
break;
case V_47 : {
T_2 V_48 ;
V_48 = F_23 ( F_4 ( V_2 ) ) ^
F_23 ( F_5 ( V_2 ) ) ;
V_24 = F_23 ( F_4 ( V_2 ) ) ;
if ( V_48 & ( 1 << V_20 ) )
V_24 |= 1 << V_20 ;
else
V_24 &= ~ ( 1 << V_20 ) ;
F_24 ( V_24 , F_4 ( V_2 ) ) ;
break;
}
}
return 0 ;
}
static void F_45 ( unsigned int V_34 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_46 ( V_34 ) ;
struct V_51 * V_19 = F_47 ( V_50 ) ;
T_2 V_52 , type ;
int V_53 ;
if ( V_2 == NULL )
return;
F_48 ( V_19 , V_50 ) ;
V_52 = F_23 ( F_5 ( V_2 ) ) &
F_23 ( F_13 ( V_2 ) ) ;
V_52 |= F_23 ( F_6 ( V_2 ) ) &
F_23 ( F_10 ( V_2 ) ) ;
for ( V_53 = 0 ; V_53 < V_2 -> V_19 . V_54 ; V_53 ++ ) {
int V_34 ;
V_34 = V_2 -> V_55 + V_53 ;
if ( ! ( V_52 & ( 1 << V_53 ) ) )
continue;
type = F_49 ( V_34 ) ;
if ( ( type & V_41 ) == V_47 ) {
T_2 V_56 ;
V_56 = F_23 ( F_4 ( V_2 ) ) ;
V_56 ^= 1 << V_53 ;
F_24 ( V_56 , F_4 ( V_2 ) ) ;
}
F_50 ( V_34 ) ;
}
F_51 ( V_19 , V_50 ) ;
}
static void F_52 ( struct V_57 * V_58 , struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
T_2 V_59 , V_60 , V_61 , V_62 , V_63 , V_52 , V_64 , V_65 ;
int V_53 ;
V_59 = F_23 ( F_1 ( V_2 ) ) ;
V_60 = F_23 ( F_3 ( V_2 ) ) ;
V_61 = F_23 ( F_2 ( V_2 ) ) ;
V_62 = F_23 ( F_4 ( V_2 ) ) ;
V_63 = F_23 ( F_5 ( V_2 ) ) ;
V_52 = F_23 ( F_6 ( V_2 ) ) ;
V_64 = F_23 ( F_10 ( V_2 ) ) ;
V_65 = F_23 ( F_13 ( V_2 ) ) ;
for ( V_53 = 0 ; V_53 < V_19 -> V_54 ; V_53 ++ ) {
const char * V_66 ;
T_2 V_67 ;
bool V_68 ;
V_66 = F_53 ( V_19 , V_53 ) ;
if ( ! V_66 )
continue;
V_67 = 1 << V_53 ;
V_68 = ! ( V_60 & V_67 ) ;
F_54 ( V_58 , L_1 , V_19 -> V_21 + V_53 , V_66 ) ;
if ( V_68 ) {
F_54 ( V_58 , L_2 ,
V_59 & V_67 ? L_3 : L_4 ,
V_61 & V_67 ? L_5 : L_6 ) ;
continue;
}
F_54 ( V_58 , L_7 ,
( V_63 ^ V_62 ) & V_67 ? L_3 : L_4 ,
V_62 & V_67 ? L_4 : L_3 ) ;
if ( ! ( ( V_64 | V_65 ) & V_67 ) ) {
F_55 ( V_58 , L_8 ) ;
continue;
}
if ( V_64 & V_67 )
F_55 ( V_58 , L_9 ) ;
if ( V_65 & V_67 )
F_55 ( V_58 , L_10 ) ;
F_54 ( V_58 , L_11 , V_52 & V_67 ? L_12 : L_13 ) ;
}
}
static int F_56 ( struct V_69 * V_70 , T_3 V_71 )
{
struct V_1 * V_2 = F_57 ( V_70 ) ;
int V_53 ;
V_2 -> V_72 = F_58 ( F_1 ( V_2 ) ) ;
V_2 -> V_73 = F_58 ( F_3 ( V_2 ) ) ;
V_2 -> V_74 = F_58 ( F_2 ( V_2 ) ) ;
V_2 -> V_75 = F_58 ( F_4 ( V_2 ) ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_2 -> V_76 [ 0 ] =
F_58 ( V_2 -> V_3 + V_16 ) ;
V_2 -> V_77 [ 0 ] =
F_58 ( V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
V_2 -> V_76 [ V_53 ] =
F_58 ( V_2 -> V_3 +
F_11 ( V_53 ) ) ;
V_2 -> V_77 [ V_53 ] =
F_58 ( V_2 -> V_3 +
F_14 ( V_53 ) ) ;
}
break;
case V_14 :
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
V_2 -> V_76 [ V_53 ] =
F_58 ( V_2 -> V_3 +
F_12 ( V_53 ) ) ;
V_2 -> V_77 [ V_53 ] =
F_58 ( V_2 -> V_3 +
F_15 ( V_53 ) ) ;
}
break;
default:
F_9 () ;
}
return 0 ;
}
static int F_59 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_57 ( V_70 ) ;
int V_53 ;
F_60 ( V_2 -> V_72 , F_1 ( V_2 ) ) ;
F_60 ( V_2 -> V_73 , F_3 ( V_2 ) ) ;
F_60 ( V_2 -> V_74 , F_2 ( V_2 ) ) ;
F_60 ( V_2 -> V_75 , F_4 ( V_2 ) ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
F_60 ( V_2 -> V_76 [ 0 ] ,
V_2 -> V_3 + V_16 ) ;
F_60 ( V_2 -> V_77 [ 0 ] ,
V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
F_60 ( V_2 -> V_76 [ V_53 ] ,
V_2 -> V_3 + F_11 ( V_53 ) ) ;
F_60 ( V_2 -> V_77 [ V_53 ] ,
V_2 -> V_3 +
F_14 ( V_53 ) ) ;
}
break;
case V_14 :
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
F_60 ( V_2 -> V_76 [ V_53 ] ,
V_2 -> V_3 +
F_12 ( V_53 ) ) ;
F_60 ( V_2 -> V_77 [ V_53 ] ,
V_2 -> V_3 +
F_15 ( V_53 ) ) ;
}
break;
default:
F_9 () ;
}
return 0 ;
}
static int F_61 ( struct V_69 * V_70 )
{
struct V_1 * V_2 ;
const struct V_78 * V_79 ;
struct V_80 * V_81 = V_70 -> V_82 . V_83 ;
struct V_84 * V_85 ;
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_86 * V_86 ;
unsigned int V_87 ;
int V_10 ;
int V_53 , V_9 , V_88 ;
int V_89 ;
V_79 = F_62 ( V_90 , & V_70 -> V_82 ) ;
if ( V_79 )
V_10 = ( int ) V_79 -> V_91 ;
else
V_10 = V_11 ;
V_2 = F_63 ( & V_70 -> V_82 , sizeof( struct V_1 ) ,
V_92 ) ;
if ( ! V_2 )
return - V_93 ;
F_64 ( V_70 , V_2 ) ;
if ( F_65 ( V_70 -> V_82 . V_83 , L_14 , & V_87 ) ) {
F_66 ( & V_70 -> V_82 , L_15 ) ;
return - V_94 ;
}
V_88 = F_67 ( V_70 -> V_82 . V_83 , L_16 ) ;
if ( V_88 < 0 ) {
F_66 ( & V_70 -> V_82 , L_17 ) ;
return V_88 ;
}
V_86 = F_68 ( & V_70 -> V_82 , NULL ) ;
if ( ! F_69 ( V_86 ) )
F_70 ( V_86 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_19 . V_66 = F_71 ( & V_70 -> V_82 ) ;
V_2 -> V_19 . V_82 = & V_70 -> V_82 ;
V_2 -> V_19 . V_95 = F_16 ;
V_2 -> V_19 . free = F_18 ;
V_2 -> V_19 . V_96 = F_28 ;
V_2 -> V_19 . V_97 = F_26 ;
V_2 -> V_19 . V_98 = F_30 ;
V_2 -> V_19 . V_99 = F_20 ;
V_2 -> V_19 . V_100 = F_32 ;
V_2 -> V_19 . V_21 = V_88 * V_101 ;
V_2 -> V_19 . V_54 = V_87 ;
V_2 -> V_19 . V_102 = false ;
V_2 -> V_19 . V_83 = V_81 ;
V_2 -> V_19 . V_103 = F_52 ;
F_72 ( & V_2 -> V_25 ) ;
V_85 = F_73 ( V_70 , V_104 , 0 ) ;
V_2 -> V_3 = F_74 ( & V_70 -> V_82 , V_85 ) ;
if ( F_69 ( V_2 -> V_3 ) )
return F_75 ( V_2 -> V_3 ) ;
if ( V_10 == V_14 ) {
V_85 = F_73 ( V_70 , V_104 , 1 ) ;
V_2 -> V_15 = F_74 ( & V_70 -> V_82 ,
V_85 ) ;
if ( F_69 ( V_2 -> V_15 ) )
return F_75 ( V_2 -> V_15 ) ;
}
switch ( V_10 ) {
case V_11 :
F_24 ( 0 , V_2 -> V_3 + V_13 ) ;
F_24 ( 0 , V_2 -> V_3 + V_16 ) ;
F_24 ( 0 , V_2 -> V_3 + V_17 ) ;
break;
case V_12 :
F_24 ( 0 , V_2 -> V_3 + V_13 ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
F_24 ( 0 , V_2 -> V_3 +
F_11 ( V_9 ) ) ;
F_24 ( 0 , V_2 -> V_3 +
F_14 ( V_9 ) ) ;
}
break;
case V_14 :
F_24 ( 0 , V_2 -> V_3 + V_13 ) ;
F_24 ( 0 , V_2 -> V_3 + V_16 ) ;
F_24 ( 0 , V_2 -> V_3 + V_17 ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
F_24 ( 0 , V_2 -> V_15 +
F_8 ( V_9 ) ) ;
F_24 ( 0 , V_2 -> V_15 +
F_12 ( V_9 ) ) ;
F_24 ( 0 , V_2 -> V_15 +
F_15 ( V_9 ) ) ;
}
break;
default:
F_9 () ;
}
F_76 ( & V_2 -> V_19 ) ;
if ( ! F_77 ( V_81 ) )
return 0 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
int V_34 = F_78 ( V_70 , V_53 ) ;
if ( V_34 < 0 )
continue;
F_79 ( V_34 , V_2 ) ;
F_80 ( V_34 , F_45 ) ;
}
V_2 -> V_55 = F_81 ( - 1 , 0 , V_87 , - 1 ) ;
if ( V_2 -> V_55 < 0 ) {
F_66 ( & V_70 -> V_82 , L_18 ) ;
V_89 = V_2 -> V_55 ;
goto V_105;
}
V_31 = F_82 ( L_19 , 2 , V_2 -> V_55 ,
V_2 -> V_3 , V_106 ) ;
if ( ! V_31 ) {
F_66 ( & V_70 -> V_82 , L_20 ) ;
V_89 = - V_93 ;
goto V_105;
}
V_31 -> V_32 = V_2 ;
V_38 = & V_31 -> V_107 [ 0 ] ;
V_38 -> type = V_44 | V_46 ;
V_38 -> V_19 . V_108 = F_40 ;
V_38 -> V_19 . V_109 = F_41 ;
V_38 -> V_19 . V_110 = F_42 ;
V_38 -> V_19 . V_111 = V_2 -> V_19 . V_66 ;
V_38 = & V_31 -> V_107 [ 1 ] ;
V_38 -> type = V_43 | V_45 ;
V_38 -> V_19 . V_112 = F_34 ;
V_38 -> V_19 . V_108 = F_38 ;
V_38 -> V_19 . V_109 = F_39 ;
V_38 -> V_19 . V_110 = F_42 ;
V_38 -> V_113 = V_114 ;
V_38 -> V_19 . V_111 = V_2 -> V_19 . V_66 ;
F_83 ( V_31 , F_84 ( V_87 ) , 0 ,
V_115 , V_116 | V_117 ) ;
V_2 -> V_27 = F_85 ( V_81 , V_2 -> V_19 . V_54 ,
V_2 -> V_55 ,
& V_118 ,
V_2 ) ;
if ( ! V_2 -> V_27 ) {
F_66 ( & V_70 -> V_82 , L_21 ,
V_2 -> V_19 . V_66 ) ;
V_89 = - V_94 ;
goto V_119;
}
return 0 ;
V_119:
F_86 ( V_31 , F_84 ( V_87 ) , V_115 ,
V_116 | V_117 ) ;
F_87 ( V_31 ) ;
V_105:
F_88 ( & V_2 -> V_19 ) ;
return V_89 ;
}
