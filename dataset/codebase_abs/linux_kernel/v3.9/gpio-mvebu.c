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
switch( V_2 -> V_10 ) {
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
switch( V_2 -> V_10 ) {
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
switch( V_2 -> V_10 ) {
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
switch( type ) {
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
type = F_47 ( F_48 ( V_34 ) ) ;
if ( ( type & V_41 ) == V_47 ) {
T_2 V_55 ;
V_55 = F_23 ( F_4 ( V_2 ) ) ;
V_55 ^= 1 << V_52 ;
F_24 ( V_55 , F_4 ( V_2 ) ) ;
}
F_49 ( V_34 ) ;
}
}
static int F_50 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
const struct V_58 * V_59 ;
struct V_60 * V_61 = V_57 -> V_62 . V_63 ;
struct V_64 * V_65 ;
struct V_30 * V_31 ;
struct V_37 * V_38 ;
struct V_66 * V_66 ;
unsigned int V_67 ;
int V_10 ;
int V_52 , V_9 , V_68 ;
V_59 = F_51 ( V_69 , & V_57 -> V_62 ) ;
if ( V_59 )
V_10 = ( int ) V_59 -> V_70 ;
else
V_10 = V_11 ;
V_65 = F_52 ( V_57 , V_71 , 0 ) ;
if ( ! V_65 ) {
F_53 ( & V_57 -> V_62 , L_1 ) ;
return - V_72 ;
}
V_2 = F_54 ( & V_57 -> V_62 , sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 ) {
F_53 ( & V_57 -> V_62 , L_2 ) ;
return - V_74 ;
}
if ( F_55 ( V_57 -> V_62 . V_63 , L_3 , & V_67 ) ) {
F_53 ( & V_57 -> V_62 , L_4 ) ;
return - V_72 ;
}
V_68 = F_56 ( V_57 -> V_62 . V_63 , L_5 ) ;
if ( V_68 < 0 ) {
F_53 ( & V_57 -> V_62 , L_6 ) ;
return V_68 ;
}
V_66 = F_57 ( & V_57 -> V_62 , NULL ) ;
if ( ! F_58 ( V_66 ) )
F_59 ( V_66 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_19 . V_75 = F_60 ( & V_57 -> V_62 ) ;
V_2 -> V_19 . V_62 = & V_57 -> V_62 ;
V_2 -> V_19 . V_76 = F_16 ;
V_2 -> V_19 . free = F_18 ;
V_2 -> V_19 . V_77 = F_28 ;
V_2 -> V_19 . V_78 = F_26 ;
V_2 -> V_19 . V_79 = F_30 ;
V_2 -> V_19 . V_80 = F_20 ;
V_2 -> V_19 . V_81 = F_32 ;
V_2 -> V_19 . V_21 = V_68 * V_82 ;
V_2 -> V_19 . V_53 = V_67 ;
V_2 -> V_19 . V_83 = 0 ;
V_2 -> V_19 . V_63 = V_61 ;
F_61 ( & V_2 -> V_25 ) ;
V_2 -> V_3 = F_62 ( & V_57 -> V_62 , V_65 ) ;
if ( F_58 ( V_2 -> V_3 ) )
return F_63 ( V_2 -> V_3 ) ;
if ( V_10 == V_14 ) {
V_65 = F_52 ( V_57 , V_71 , 1 ) ;
if ( ! V_65 ) {
F_53 ( & V_57 -> V_62 , L_1 ) ;
return - V_72 ;
}
V_2 -> V_15 = F_62 ( & V_57 -> V_62 ,
V_65 ) ;
if ( F_58 ( V_2 -> V_15 ) )
return F_63 ( V_2 -> V_15 ) ;
}
switch( V_10 ) {
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
F_64 ( & V_2 -> V_19 ) ;
if ( ! F_65 ( V_61 ) )
return 0 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
int V_34 ;
V_34 = F_66 ( V_57 , V_52 ) ;
if ( V_34 < 0 )
continue;
F_67 ( V_34 , V_2 ) ;
F_68 ( V_34 , F_45 ) ;
}
V_2 -> V_54 = F_69 ( - 1 , 0 , V_67 , - 1 ) ;
if ( V_2 -> V_54 < 0 ) {
F_53 ( & V_57 -> V_62 , L_7 ) ;
return - V_74 ;
}
V_31 = F_70 ( L_8 , 2 , V_2 -> V_54 ,
V_2 -> V_3 , V_84 ) ;
if ( ! V_31 ) {
F_53 ( & V_57 -> V_62 , L_9 ) ;
return - V_74 ;
}
V_31 -> V_32 = V_2 ;
V_38 = & V_31 -> V_85 [ 0 ] ;
V_38 -> type = V_44 | V_46 ;
V_38 -> V_19 . V_86 = F_40 ;
V_38 -> V_19 . V_87 = F_41 ;
V_38 -> V_19 . V_88 = F_42 ;
V_38 -> V_19 . V_89 = V_2 -> V_19 . V_75 ;
V_38 = & V_31 -> V_85 [ 1 ] ;
V_38 -> type = V_43 | V_45 ;
V_38 -> V_19 . V_90 = F_34 ;
V_38 -> V_19 . V_86 = F_38 ;
V_38 -> V_19 . V_87 = F_39 ;
V_38 -> V_19 . V_88 = F_42 ;
V_38 -> V_91 = V_92 ;
V_38 -> V_19 . V_89 = V_2 -> V_19 . V_75 ;
F_71 ( V_31 , F_72 ( V_67 ) , 0 ,
V_93 , V_94 | V_95 ) ;
V_2 -> V_27 = F_73 ( V_61 , V_2 -> V_19 . V_53 ,
V_2 -> V_54 ,
& V_96 ,
V_2 ) ;
if ( ! V_2 -> V_27 ) {
F_53 ( & V_57 -> V_62 , L_10 ,
V_2 -> V_19 . V_75 ) ;
F_74 ( V_31 , F_72 ( V_67 ) , V_93 ,
V_94 | V_95 ) ;
F_75 ( V_31 ) ;
return - V_72 ;
}
return 0 ;
}
static int T_3 F_76 ( void )
{
return F_77 ( & V_97 ) ;
}
