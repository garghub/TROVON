static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static T_1 F_3 ( T_1 V_4 )
{
V_4 &= V_5 ;
V_4 >>= V_6 ;
return V_4 ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_8 = F_5 ( V_3 -> V_9 + V_10 ) ;
if ( F_3 ( V_8 ) != V_7 -> V_11 ) {
F_6 ( & V_7 -> V_12 -> V_13 , L_1 ) ;
V_8 &= ~ V_5 ;
V_8 |= V_7 -> V_11 << V_6 ;
F_7 ( V_8 , V_3 -> V_9 + 0x80 ) ;
}
}
static unsigned int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_14 * V_15 ;
unsigned int V_16 , V_17 ;
int V_14 ;
F_4 ( V_3 ) ;
for ( V_17 = 0 , V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
V_15 = V_7 -> V_19 [ V_14 ] ;
if ( ! V_15 )
continue;
V_16 = F_9 ( V_15 ) ;
if ( V_16 > V_17 )
V_17 = V_16 ;
}
return V_17 ;
}
static unsigned int F_10 ( struct V_1 * V_7 ,
unsigned int V_20 ,
unsigned int V_21 )
{
unsigned long V_16 ;
struct V_14 * V_22 = V_7 -> V_19 [ V_20 ] ;
int div ;
if ( ! V_22 )
return V_23 ;
if ( V_7 -> V_24 -> V_25 ) {
V_16 = F_11 ( V_22 , V_21 ) ;
return V_21 - V_16 ;
}
V_16 = F_9 ( V_22 ) ;
for ( div = 1 ; div < 256 ; div *= 2 ) {
if ( ( V_16 / div ) <= V_21 )
break;
}
F_6 ( & V_7 -> V_12 -> V_13 , L_2 ,
V_20 , V_16 , V_21 , V_16 / div ) ;
return ( V_21 - ( V_16 / div ) ) ;
}
static void F_12 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_26 = V_23 ;
unsigned int V_27 ;
int V_28 = 0 ;
int V_20 ;
T_1 V_29 ;
if ( clock == 0 )
return;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
V_27 = F_10 ( V_7 , V_20 , clock ) ;
if ( V_27 < V_26 ) {
V_26 = V_27 ;
V_28 = V_20 ;
}
}
F_6 ( & V_7 -> V_12 -> V_13 ,
L_3 ,
V_28 , clock , V_26 ) ;
if ( V_7 -> V_11 != V_28 ) {
struct V_14 * V_14 = V_7 -> V_19 [ V_28 ] ;
F_13 ( 0 , V_3 -> V_9 + V_30 ) ;
V_7 -> V_11 = V_28 ;
V_3 -> V_31 = F_9 ( V_14 ) ;
V_29 = F_5 ( V_3 -> V_9 + V_10 ) ;
V_29 &= ~ V_5 ;
V_29 |= V_28 << V_6 ;
F_7 ( V_29 , V_3 -> V_9 + V_10 ) ;
}
{
struct V_32 V_33 ;
V_33 . clock = clock ;
if ( V_7 -> V_24 -> V_34 )
( V_7 -> V_24 -> V_34 ) ( V_7 -> V_12 , V_3 -> V_9 ,
& V_33 , NULL ) ;
}
}
static unsigned int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_27 , V_35 = V_23 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
V_27 = F_10 ( V_7 , V_20 , 0 ) ;
if ( V_27 == V_23 )
continue;
if ( - V_27 < V_35 )
V_35 = - V_27 ;
}
return V_35 ;
}
static unsigned int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_11 ( V_7 -> V_19 [ V_7 -> V_11 ] , V_23 ) ;
}
static unsigned int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_11 ( V_7 -> V_19 [ V_7 -> V_11 ] , 400000 ) ;
}
static void F_17 ( struct V_2 * V_3 , unsigned int clock )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( clock == 0 )
return;
F_12 ( V_3 , clock ) ;
F_18 ( V_7 -> V_19 [ V_7 -> V_11 ] , clock ) ;
V_3 -> clock = clock ;
}
static int F_19 ( struct V_2 * V_3 , int V_36 )
{
T_2 V_29 ;
V_29 = F_20 ( V_3 , V_37 ) ;
switch ( V_36 ) {
case V_38 :
V_29 |= V_39 ;
V_29 &= ~ V_40 ;
break;
case V_41 :
V_29 |= V_40 ;
V_29 &= ~ V_39 ;
break;
default:
break;
}
F_21 ( V_3 , V_29 , V_37 ) ;
return 0 ;
}
static void F_22 ( struct V_42 * V_13 , int V_43 )
{
struct V_2 * V_3 = F_23 ( V_13 ) ;
unsigned long V_44 ;
if ( V_3 ) {
F_24 ( & V_3 -> V_45 , V_44 ) ;
if ( V_43 ) {
F_6 ( & V_13 -> V_13 , L_4 ) ;
V_3 -> V_44 &= ~ V_46 ;
V_3 -> V_47 |= V_48 ;
} else {
F_6 ( & V_13 -> V_13 , L_5 ) ;
V_3 -> V_44 |= V_46 ;
V_3 -> V_47 &= ~ V_48 ;
}
F_25 ( & V_3 -> V_49 ) ;
F_26 ( & V_3 -> V_45 , V_44 ) ;
}
}
static T_3 F_27 ( int V_50 , void * V_51 )
{
struct V_1 * V_52 = V_51 ;
int V_53 = F_28 ( V_52 -> V_54 ) ;
if ( V_52 -> V_24 -> V_55 )
V_53 = ! V_53 ;
F_22 ( V_52 -> V_12 , V_53 ) ;
return V_56 ;
}
static void F_29 ( struct V_1 * V_52 )
{
struct V_57 * V_24 = V_52 -> V_24 ;
struct V_58 * V_13 = & V_52 -> V_12 -> V_13 ;
if ( F_30 ( V_24 -> V_54 , L_6 ) == 0 ) {
V_52 -> V_54 = V_24 -> V_54 ;
V_52 -> V_59 = F_31 ( V_24 -> V_54 ) ;
if ( V_52 -> V_59 &&
F_32 ( V_52 -> V_59 , NULL ,
F_27 ,
V_60 | V_61 ,
F_33 ( V_13 ) , V_52 ) == 0 ) {
int V_53 = F_28 ( V_52 -> V_54 ) ;
if ( V_24 -> V_55 )
V_53 = ! V_53 ;
F_22 ( V_52 -> V_12 , V_53 ) ;
} else {
F_34 ( V_13 , L_7 ) ;
V_52 -> V_59 = 0 ;
}
} else {
F_35 ( V_13 , L_8 ) ;
}
}
static int T_4 F_36 ( struct V_42 * V_12 )
{
struct V_57 * V_24 = V_12 -> V_13 . V_62 ;
struct V_58 * V_13 = & V_12 -> V_13 ;
struct V_2 * V_3 ;
struct V_1 * V_52 ;
struct V_63 * V_64 ;
int V_65 , V_50 , V_66 , V_67 ;
if ( ! V_24 ) {
F_35 ( V_13 , L_9 ) ;
return - V_68 ;
}
V_50 = F_37 ( V_12 , 0 ) ;
if ( V_50 < 0 ) {
F_35 ( V_13 , L_10 ) ;
return V_50 ;
}
V_64 = F_38 ( V_12 , V_69 , 0 ) ;
if ( ! V_64 ) {
F_35 ( V_13 , L_11 ) ;
return - V_68 ;
}
V_3 = F_39 ( V_13 , sizeof( struct V_1 ) ) ;
if ( F_40 ( V_3 ) ) {
F_35 ( V_13 , L_12 ) ;
return F_41 ( V_3 ) ;
}
V_52 = F_2 ( V_3 ) ;
V_52 -> V_3 = V_3 ;
V_52 -> V_12 = V_12 ;
V_52 -> V_24 = V_24 ;
V_52 -> V_54 = - 1 ;
F_42 ( V_12 , V_3 ) ;
V_52 -> V_70 = F_43 ( V_13 , L_13 ) ;
if ( F_40 ( V_52 -> V_70 ) ) {
F_35 ( V_13 , L_14 ) ;
V_65 = F_41 ( V_52 -> V_70 ) ;
goto V_71;
}
F_44 ( V_52 -> V_70 ) ;
for ( V_67 = 0 , V_66 = 0 ; V_66 < V_18 ; V_66 ++ ) {
struct V_14 * V_14 ;
char * V_72 = V_24 -> V_73 [ V_66 ] ;
if ( V_72 == NULL )
continue;
V_14 = F_43 ( V_13 , V_72 ) ;
if ( F_40 ( V_14 ) ) {
F_35 ( V_13 , L_15 , V_72 ) ;
continue;
}
V_67 ++ ;
V_52 -> V_19 [ V_66 ] = V_14 ;
V_52 -> V_11 = V_66 ;
F_44 ( V_14 ) ;
F_45 ( V_13 , L_16 ,
V_66 , V_72 , F_9 ( V_14 ) ) ;
}
if ( V_67 == 0 ) {
F_35 ( V_13 , L_17 ) ;
V_65 = - V_68 ;
goto V_74;
}
V_52 -> V_75 = F_46 ( V_64 -> V_76 , F_47 ( V_64 ) ,
F_48 ( V_3 -> V_77 ) ) ;
if ( ! V_52 -> V_75 ) {
F_35 ( V_13 , L_18 ) ;
V_65 = - V_78 ;
goto V_79;
}
V_3 -> V_9 = F_49 ( V_64 -> V_76 , F_47 ( V_64 ) ) ;
if ( ! V_3 -> V_9 ) {
F_35 ( V_13 , L_19 ) ;
V_65 = - V_78 ;
goto V_79;
}
if ( V_24 -> V_80 )
V_24 -> V_80 ( V_12 , V_24 -> V_81 ) ;
V_3 -> V_82 = L_20 ;
V_3 -> V_83 = & V_84 ;
V_3 -> V_47 = 0 ;
V_3 -> V_50 = V_50 ;
V_3 -> V_47 |= V_85 ;
V_3 -> V_47 |= V_86 ;
#ifndef F_50
V_3 -> V_47 |= V_87 ;
#endif
V_3 -> V_47 |= V_88 ;
V_3 -> V_47 |= V_89 ;
if ( V_24 -> V_90 == V_91 ||
V_24 -> V_90 == V_92 )
V_3 -> V_47 |= V_48 ;
if ( V_24 -> V_90 == V_92 )
V_3 -> V_77 -> V_93 = V_94 ;
if ( V_24 -> V_95 )
V_3 -> V_77 -> V_93 |= V_24 -> V_95 ;
V_3 -> V_47 |= ( V_96 |
V_97 ) ;
V_3 -> V_47 |= V_98 ;
if ( V_24 -> V_25 ) {
V_84 . V_99 = F_17 ;
V_84 . V_100 = F_16 ;
V_84 . V_101 = F_15 ;
}
if ( V_24 -> V_95 )
V_3 -> V_77 -> V_93 |= V_24 -> V_95 ;
V_65 = F_51 ( V_3 ) ;
if ( V_65 ) {
F_35 ( V_13 , L_21 ) ;
goto V_102;
}
if ( V_24 -> V_90 == V_103 && V_24 -> V_104 )
V_24 -> V_104 ( & F_22 ) ;
if ( V_24 -> V_90 == V_105 &&
F_52 ( V_24 -> V_54 ) )
F_29 ( V_52 ) ;
return 0 ;
V_102:
F_53 ( V_52 -> V_75 ) ;
F_54 ( V_52 -> V_75 ) ;
V_79:
for ( V_66 = 0 ; V_66 < V_18 ; V_66 ++ ) {
F_55 ( V_52 -> V_19 [ V_66 ] ) ;
F_56 ( V_52 -> V_19 [ V_66 ] ) ;
}
V_74:
F_55 ( V_52 -> V_70 ) ;
F_56 ( V_52 -> V_70 ) ;
V_71:
F_57 ( V_3 ) ;
return V_65 ;
}
static int T_5 F_58 ( struct V_42 * V_12 )
{
struct V_57 * V_24 = V_12 -> V_13 . V_62 ;
struct V_2 * V_3 = F_23 ( V_12 ) ;
struct V_1 * V_52 = F_2 ( V_3 ) ;
int V_66 ;
if ( V_24 -> V_90 == V_103 && V_24 -> V_106 )
V_24 -> V_106 ( & F_22 ) ;
if ( V_52 -> V_59 )
F_59 ( V_52 -> V_59 , V_52 ) ;
if ( F_52 ( V_52 -> V_54 ) )
F_60 ( V_52 -> V_54 ) ;
F_61 ( V_3 , 1 ) ;
for ( V_66 = 0 ; V_66 < 3 ; V_66 ++ ) {
if ( V_52 -> V_19 [ V_66 ] ) {
F_55 ( V_52 -> V_19 [ V_66 ] ) ;
F_56 ( V_52 -> V_19 [ V_66 ] ) ;
}
}
F_55 ( V_52 -> V_70 ) ;
F_56 ( V_52 -> V_70 ) ;
F_62 ( V_3 -> V_9 ) ;
F_53 ( V_52 -> V_75 ) ;
F_54 ( V_52 -> V_75 ) ;
F_57 ( V_3 ) ;
F_42 ( V_12 , NULL ) ;
return 0 ;
}
static int F_63 ( struct V_42 * V_13 , T_6 V_107 )
{
struct V_2 * V_3 = F_23 ( V_13 ) ;
F_64 ( V_3 , V_107 ) ;
return 0 ;
}
static int F_65 ( struct V_42 * V_13 )
{
struct V_2 * V_3 = F_23 ( V_13 ) ;
F_66 ( V_3 ) ;
return 0 ;
}
static int T_7 F_67 ( void )
{
return F_68 ( & V_108 ) ;
}
static void T_8 F_69 ( void )
{
F_70 ( & V_108 ) ;
}
