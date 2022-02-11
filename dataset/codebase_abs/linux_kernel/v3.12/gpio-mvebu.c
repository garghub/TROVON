static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_4 ;
}
static inline void T_1 * F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_5 ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_6 ;
}
static inline void T_1 * F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_7 ;
}
static inline void T_1 * F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_8 ;
}
static inline void T_1 * F_6 ( struct V_1 * V_2 )
{
int V_9 ;
switch ( V_2 -> V_10 ) {
case V_11 :
case V_12 :
return V_2 -> V_3 + V_13 ;
case V_14 :
V_9 = F_7 () ;
return V_2 -> V_15 + F_8 ( V_9 ) ;
default:
F_9 () ;
}
}
static inline void T_1 * F_10 ( struct V_1 * V_2 )
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
return V_2 -> V_15 + F_12 ( V_9 ) ;
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
return V_2 -> V_15 + F_15 ( V_9 ) ;
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
if ( ! V_24 ) {
return - V_40 ;
}
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
T_2 V_51 , type ;
int V_52 ;
if ( V_2 == NULL )
return;
V_51 = F_23 ( F_5 ( V_2 ) ) &
F_23 ( F_13 ( V_2 ) ) ;
V_51 |= F_23 ( F_6 ( V_2 ) ) &
F_23 ( F_10 ( V_2 ) ) ;
for ( V_52 = 0 ; V_52 < V_2 -> V_19 . V_53 ; V_52 ++ ) {
int V_34 ;
V_34 = V_2 -> V_54 + V_52 ;
if ( ! ( V_51 & ( 1 << V_52 ) ) )
continue;
type = F_47 ( V_34 ) ;
if ( ( type & V_41 ) == V_47 ) {
T_2 V_55 ;
V_55 = F_23 ( F_4 ( V_2 ) ) ;
V_55 ^= 1 << V_52 ;
F_24 ( V_55 , F_4 ( V_2 ) ) ;
}
F_48 ( V_34 ) ;
}
}
static void F_49 ( struct V_56 * V_57 , struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_21 ( V_19 , struct V_1 , V_19 ) ;
T_2 V_58 , V_59 , V_60 , V_61 , V_62 , V_51 , V_63 , V_64 ;
int V_52 ;
V_58 = F_23 ( F_1 ( V_2 ) ) ;
V_59 = F_23 ( F_3 ( V_2 ) ) ;
V_60 = F_23 ( F_2 ( V_2 ) ) ;
V_61 = F_23 ( F_4 ( V_2 ) ) ;
V_62 = F_23 ( F_5 ( V_2 ) ) ;
V_51 = F_23 ( F_6 ( V_2 ) ) ;
V_63 = F_23 ( F_10 ( V_2 ) ) ;
V_64 = F_23 ( F_13 ( V_2 ) ) ;
for ( V_52 = 0 ; V_52 < V_19 -> V_53 ; V_52 ++ ) {
const char * V_65 ;
T_2 V_66 ;
bool V_67 ;
V_65 = F_50 ( V_19 , V_52 ) ;
if ( ! V_65 )
continue;
V_66 = 1 << V_52 ;
V_67 = ! ( V_59 & V_66 ) ;
F_51 ( V_57 , L_1 , V_19 -> V_21 + V_52 , V_65 ) ;
if ( V_67 ) {
F_51 ( V_57 , L_2 ,
V_58 & V_66 ? L_3 : L_4 ,
V_60 & V_66 ? L_5 : L_6 ) ;
continue;
}
F_51 ( V_57 , L_7 ,
( V_62 ^ V_61 ) & V_66 ? L_3 : L_4 ,
V_61 & V_66 ? L_4 : L_3 ) ;
if ( ! ( ( V_63 | V_64 ) & V_66 ) ) {
F_51 ( V_57 , L_8 ) ;
continue;
}
if ( V_63 & V_66 )
F_51 ( V_57 , L_9 ) ;
if ( V_64 & V_66 )
F_51 ( V_57 , L_10 ) ;
F_51 ( V_57 , L_11 , V_51 & V_66 ? L_12 : L_13 ) ;
}
}
static int F_52 ( struct V_68 * V_69 )
{
struct V_1 * V_2 ;
const struct V_70 * V_71 ;
struct V_72 * V_73 = V_69 -> V_74 . V_75 ;
struct V_76 * V_77 ;
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_78 * V_78 ;
unsigned int V_79 ;
int V_10 ;
int V_52 , V_9 , V_80 ;
V_71 = F_53 ( V_81 , & V_69 -> V_74 ) ;
if ( V_71 )
V_10 = ( int ) V_71 -> V_82 ;
else
V_10 = V_11 ;
V_2 = F_54 ( & V_69 -> V_74 , sizeof( struct V_1 ) , V_83 ) ;
if ( ! V_2 ) {
F_55 ( & V_69 -> V_74 , L_14 ) ;
return - V_84 ;
}
if ( F_56 ( V_69 -> V_74 . V_75 , L_15 , & V_79 ) ) {
F_55 ( & V_69 -> V_74 , L_16 ) ;
return - V_85 ;
}
V_80 = F_57 ( V_69 -> V_74 . V_75 , L_17 ) ;
if ( V_80 < 0 ) {
F_55 ( & V_69 -> V_74 , L_18 ) ;
return V_80 ;
}
V_78 = F_58 ( & V_69 -> V_74 , NULL ) ;
if ( ! F_59 ( V_78 ) )
F_60 ( V_78 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_19 . V_65 = F_61 ( & V_69 -> V_74 ) ;
V_2 -> V_19 . V_74 = & V_69 -> V_74 ;
V_2 -> V_19 . V_86 = F_16 ;
V_2 -> V_19 . free = F_18 ;
V_2 -> V_19 . V_87 = F_28 ;
V_2 -> V_19 . V_88 = F_26 ;
V_2 -> V_19 . V_89 = F_30 ;
V_2 -> V_19 . V_90 = F_20 ;
V_2 -> V_19 . V_91 = F_32 ;
V_2 -> V_19 . V_21 = V_80 * V_92 ;
V_2 -> V_19 . V_53 = V_79 ;
V_2 -> V_19 . V_93 = 0 ;
V_2 -> V_19 . V_75 = V_73 ;
V_2 -> V_19 . V_94 = F_49 ;
F_62 ( & V_2 -> V_25 ) ;
V_77 = F_63 ( V_69 , V_95 , 0 ) ;
V_2 -> V_3 = F_64 ( & V_69 -> V_74 , V_77 ) ;
if ( F_59 ( V_2 -> V_3 ) )
return F_65 ( V_2 -> V_3 ) ;
if ( V_10 == V_14 ) {
V_77 = F_63 ( V_69 , V_95 , 1 ) ;
V_2 -> V_15 = F_64 ( & V_69 -> V_74 ,
V_77 ) ;
if ( F_59 ( V_2 -> V_15 ) )
return F_65 ( V_2 -> V_15 ) ;
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
F_66 ( & V_2 -> V_19 ) ;
if ( ! F_67 ( V_73 ) )
return 0 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
int V_34 ;
V_34 = F_68 ( V_69 , V_52 ) ;
if ( V_34 < 0 )
continue;
F_69 ( V_34 , V_2 ) ;
F_70 ( V_34 , F_45 ) ;
}
V_2 -> V_54 = F_71 ( - 1 , 0 , V_79 , - 1 ) ;
if ( V_2 -> V_54 < 0 ) {
F_55 ( & V_69 -> V_74 , L_19 ) ;
return - V_84 ;
}
V_31 = F_72 ( L_20 , 2 , V_2 -> V_54 ,
V_2 -> V_3 , V_96 ) ;
if ( ! V_31 ) {
F_55 ( & V_69 -> V_74 , L_21 ) ;
return - V_84 ;
}
V_31 -> V_32 = V_2 ;
V_38 = & V_31 -> V_97 [ 0 ] ;
V_38 -> type = V_44 | V_46 ;
V_38 -> V_19 . V_98 = F_40 ;
V_38 -> V_19 . V_99 = F_41 ;
V_38 -> V_19 . V_100 = F_42 ;
V_38 -> V_19 . V_101 = V_2 -> V_19 . V_65 ;
V_38 = & V_31 -> V_97 [ 1 ] ;
V_38 -> type = V_43 | V_45 ;
V_38 -> V_19 . V_102 = F_34 ;
V_38 -> V_19 . V_98 = F_38 ;
V_38 -> V_19 . V_99 = F_39 ;
V_38 -> V_19 . V_100 = F_42 ;
V_38 -> V_103 = V_104 ;
V_38 -> V_19 . V_101 = V_2 -> V_19 . V_65 ;
F_73 ( V_31 , F_74 ( V_79 ) , 0 ,
V_105 , V_106 | V_107 ) ;
V_2 -> V_27 = F_75 ( V_73 , V_2 -> V_19 . V_53 ,
V_2 -> V_54 ,
& V_108 ,
V_2 ) ;
if ( ! V_2 -> V_27 ) {
F_55 ( & V_69 -> V_74 , L_22 ,
V_2 -> V_19 . V_65 ) ;
F_76 ( V_31 , F_74 ( V_79 ) , V_105 ,
V_106 | V_107 ) ;
F_77 ( V_31 ) ;
return - V_85 ;
}
return 0 ;
}
static int T_3 F_78 ( void )
{
return F_79 ( & V_109 ) ;
}
