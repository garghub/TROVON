static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( & V_2 -> V_3 ) )
F_3 ( & V_2 -> V_3 , V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_3 ) ;
}
static T_1 F_6 ( const struct V_6 * V_7 , int V_8 )
{
return F_7 ( V_7 -> V_9 + V_8 ) ;
}
static void F_8 ( const struct V_6 * V_7 , int V_8 , T_1 V_10 )
{
struct V_1 * V_2 = V_7 -> V_7 ;
int V_11 = ( V_7 -> V_9 - V_2 -> V_12 ) / V_13 ;
if ( V_8 == V_14 )
switch ( V_10 ) {
case V_15 :
F_9 ( V_2 , F_10 ( V_11 ) , V_16 ) ;
break;
case 0x00 :
F_9 ( V_2 , F_10 ( V_11 ) , V_17 ) ;
F_1 ( V_2 ) ;
break;
default:
break;
}
F_11 ( V_10 , V_7 -> V_9 + V_8 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , int V_8 )
{
return F_7 ( V_2 -> V_12 + V_18 + V_8 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_8 , T_1 V_10 )
{
if ( V_8 == V_19 ) {
if ( V_2 -> V_20 == V_10 )
return;
V_2 -> V_20 = V_10 ;
}
F_11 ( V_10 , V_2 -> V_12 + V_18 + V_8 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return ( ( F_12 ( V_2 , V_21 ) == V_2 -> V_22 ) &&
( F_12 ( V_2 , V_23 ) == V_2 -> V_24 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_25 = V_4 +
F_16 ( V_26 ) + 1 ;
while ( F_12 ( V_2 , V_27 ) & V_28 ) {
if ( F_17 ( V_4 , V_25 ) )
return - V_29 ;
F_18 () ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_30 , T_1 V_10 )
{
T_1 V_31 ;
int V_32 , V_33 ;
F_13 ( V_2 , V_34 , V_35 ) ;
V_32 = F_15 ( V_2 ) ;
if ( V_32 )
goto V_36;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
F_13 ( V_2 , V_34 , V_38 ) ;
V_32 = F_15 ( V_2 ) ;
if ( V_32 )
goto V_36;
V_31 = F_12 ( V_2 , V_39 ) ;
if ( V_31 & V_40 )
break;
}
if ( V_33 >= V_37 ) {
F_20 ( & V_2 -> V_41 -> V_42 ,
L_1 ) ;
return - V_43 ;
}
F_13 ( V_2 , V_44 , V_30 & 0xff ) ;
F_13 ( V_2 , V_45 , V_10 ) ;
F_13 ( V_2 , V_34 , F_21 ( V_30 ) ) ;
V_32 = F_15 ( V_2 ) ;
if ( V_32 )
goto V_36;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
F_13 ( V_2 , V_34 , V_38 ) ;
V_32 = F_15 ( V_2 ) ;
if ( V_32 )
goto V_36;
V_31 = F_12 ( V_2 , V_39 ) ;
if ( ! ( V_31 & V_46 ) )
break;
}
if ( V_33 >= V_37 ) {
F_20 ( & V_2 -> V_41 -> V_42 ,
L_2 ) ;
return - V_43 ;
}
F_13 ( V_2 , V_34 , V_47 ) ;
V_32 = F_15 ( V_2 ) ;
if ( V_32 )
goto V_36;
return 0 ;
V_36:
F_20 ( & V_2 -> V_41 -> V_42 ,
L_3 , V_32 ) ;
return V_32 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_48 , T_1 V_49 )
{
T_1 V_20 = V_2 -> V_20 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_50 ; V_33 ++ )
if ( V_48 & F_10 ( V_33 ) ) {
V_20 &= ~ F_22 ( V_33 ) ;
V_20 |= F_23 ( V_49 , V_33 ) ;
}
F_13 ( V_2 , V_19 , V_20 ) ;
}
static inline void F_24 ( struct V_1 * V_2 , int V_51 )
{
int V_32 ;
V_32 = F_19 ( V_2 , 0 , ! ! V_51 ) ;
if ( V_32 )
F_20 ( & V_2 -> V_41 -> V_42 ,
L_4 ,
( V_51 ) ? L_5 : L_6 , V_32 ) ;
}
static void F_25 ( unsigned long V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
struct V_53 * V_54 ;
int V_33 , V_55 = 0 ;
T_1 V_20 ;
V_20 = V_2 -> V_20 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_50 ; V_33 ++ ) {
V_20 &= ~ F_22 ( V_33 ) ;
V_20 |= F_26 ( V_33 ) ;
V_54 = V_2 -> V_56 [ V_33 ] . V_54 ;
if ( ! V_54 || ! ( V_54 -> V_57 & V_58 ) )
continue;
V_55 ++ ;
V_20 &= ~ F_22 ( V_33 ) ;
V_20 |= F_27 ( V_33 ) ;
if ( V_54 -> V_59 . V_60 != V_2 -> V_56 [ V_33 ] . V_61 ) {
V_2 -> V_56 [ V_33 ] . V_61 = V_54 -> V_59 . V_60 ;
V_20 &= ~ F_22 ( V_33 ) ;
V_20 |= F_28 ( V_33 ) ;
}
if ( V_54 -> V_59 . V_62 != V_2 -> V_56 [ V_33 ] . V_63 ) {
V_2 -> V_56 [ V_33 ] . V_63 = V_54 -> V_59 . V_62 ;
V_20 &= ~ F_22 ( V_33 ) ;
V_20 |= F_28 ( V_33 ) ;
}
}
F_13 ( V_2 , V_19 , V_20 ) ;
if ( V_55 )
F_3 ( & V_2 -> V_3 , V_4 + V_5 ) ;
}
static T_3 F_29 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
int V_68 = 1 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_50 ; V_33 ++ ) {
struct V_53 * V_54 ;
if ( ! F_14 ( V_2 ) ) {
return V_69 ;
}
V_54 = V_2 -> V_56 [ V_33 ] . V_54 ;
if ( V_54 &&
F_30 ( V_64 , V_54 ) == V_70 )
V_68 = 0 ;
}
if ( V_68 )
break;
}
return ( V_66 ) ? V_70 : V_69 ;
}
static void F_31 ( struct V_1 * V_2 )
{
int V_33 ;
T_1 V_48 = 0 ;
for ( V_33 = 0 ; V_33 < V_2 -> V_50 ; V_33 ++ ) {
struct V_53 * V_54 ;
char V_71 [ V_72 ] ;
V_48 |= F_10 ( V_33 ) ;
V_54 = V_2 -> V_56 [ V_33 ] . V_54 ;
if ( ! V_54 )
continue;
strncpy ( V_71 , V_54 -> V_71 , V_72 ) ;
F_32 ( V_54 ) ;
F_33 ( V_54 ) ;
F_34 ( & V_2 -> V_41 -> V_42 , L_7 , V_71 ) ;
}
if ( F_14 ( V_2 ) ) {
F_9 ( V_2 , V_48 , V_73 ) ;
F_24 ( V_2 , 0 ) ;
}
}
static inline int F_35 ( struct V_6 * V_7 )
{
F_8 ( V_7 , V_14 , 1 ) ;
F_8 ( V_7 , V_74 , V_75 ) ;
if ( F_6 ( V_7 , V_74 ) == V_75 )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_76 * V_41 = V_2 -> V_41 ;
int V_33 , V_32 = 0 ;
T_1 V_20 = V_77 ;
V_2 -> V_20 = ~ V_20 ;
F_13 ( V_2 , V_19 , V_20 ) ;
F_37 ( 2 ) ;
V_20 &= ~ V_78 ;
F_13 ( V_2 , V_19 , V_20 ) ;
for ( V_33 = 0 ; V_33 < F_38 ( V_2 -> V_56 ) ; V_33 ++ ) {
struct V_53 * V_54 ;
struct V_6 * V_7 ;
V_54 = F_39 ( 0 ) ;
if ( ! V_54 ) {
V_32 = - V_79 ;
break;
}
V_7 = F_40 ( V_54 ) ;
V_7 -> V_7 = V_2 ;
F_41 ( V_54 , & V_41 -> V_42 ) ;
V_7 -> V_80 = V_81 ;
V_54 -> V_64 = V_41 -> V_64 ;
V_7 -> V_9 = V_2 -> V_12 + F_42 ( V_33 ) ;
if ( ! F_35 ( V_7 ) ) {
F_20 ( & V_41 -> V_42 , L_8 , V_33 ) ;
F_33 ( V_54 ) ;
continue;
}
V_7 -> V_82 = F_6 ;
V_7 -> V_83 = F_8 ;
V_7 -> V_84 . clock . V_85 = V_86 ;
V_7 -> V_87 = V_88 ;
V_7 -> V_89 = V_90 ;
if ( V_33 > 0 )
V_7 -> V_89 |= V_91 ;
V_7 -> V_57 |= V_92 ;
V_32 = F_43 ( V_54 ) ;
if ( V_32 ) {
F_33 ( V_54 ) ;
continue;
}
V_2 -> V_56 [ V_33 ] . V_54 = V_54 ;
V_2 -> V_50 ++ ;
V_20 &= ~ F_44 ( V_33 ) ;
F_34 ( & V_41 -> V_42 ,
L_9 ,
V_54 -> V_71 , V_33 , V_7 -> V_9 , V_41 -> V_64 ) ;
}
F_13 ( V_2 , V_19 , V_20 ) ;
return V_32 ;
}
static int F_45 ( struct V_76 * V_41 , void * V_93 )
{
V_41 -> V_94 [ 0 ] -> V_57 &= ~ V_95 ;
V_41 -> V_94 [ 0 ] -> V_57 |= V_96 ;
V_41 -> V_97 = 10 ;
return F_46 ( V_41 ) ;
}
static void F_47 ( struct V_76 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_7 ;
if ( ! V_2 )
return;
F_48 ( V_41 -> V_64 , V_2 ) ;
F_4 ( V_2 ) ;
F_31 ( V_2 ) ;
F_49 ( V_2 -> V_12 ) ;
F_50 ( V_2 ) ;
V_41 -> V_7 = NULL ;
}
static int T_4 F_51 ( struct V_76 * V_41 )
{
struct V_1 * V_2 ;
int V_32 ;
V_41 -> V_98 |= V_99 | V_100 ;
V_32 = F_52 ( V_41 , F_45 , NULL ) ;
if ( V_32 ) {
F_20 ( & V_41 -> V_42 , L_10 , V_32 ) ;
goto V_101;
}
if ( ! V_41 -> V_64 ) {
F_20 ( & V_41 -> V_42 , L_11 ) ;
V_32 = - V_102 ;
goto V_101;
}
V_32 = F_53 ( V_41 ) ;
if ( V_32 ) {
F_20 ( & V_41 -> V_42 , L_12 ,
V_32 ) ;
goto V_101;
}
V_2 = F_54 ( sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 ) {
F_20 ( & V_41 -> V_42 , L_13 ) ;
V_32 = - V_79 ;
goto V_104;
}
V_2 -> V_41 = V_41 ;
V_41 -> V_7 = V_2 ;
V_2 -> V_12 = F_55 ( V_41 -> V_94 [ 0 ] -> V_105 ,
F_56 ( V_41 -> V_94 [ 0 ] ) ) ;
if ( ! V_2 -> V_12 ) {
F_20 ( & V_41 -> V_42 , L_14 ) ;
V_32 = - V_79 ;
goto V_106;
}
V_2 -> V_22 = F_12 ( V_2 , V_21 ) ;
V_2 -> V_24 = F_12 ( V_2 , V_23 ) ;
F_34 ( & V_41 -> V_42 , L_15 ,
V_41 -> V_107 [ 1 ] ? V_41 -> V_107 [ 1 ] : L_16 ,
V_2 -> V_22 , V_2 -> V_24 ) ;
F_36 ( V_2 ) ;
if ( ! V_2 -> V_50 )
goto V_108;
F_57 ( & V_2 -> V_3 ) ;
V_2 -> V_3 . V_109 = F_25 ;
V_2 -> V_3 . V_110 = ( unsigned long ) V_2 ;
V_32 = F_58 ( V_41 -> V_64 , & F_29 , V_81 , V_111 , V_2 ) ;
if ( V_32 ) {
F_20 ( & V_41 -> V_42 , L_17 , V_41 -> V_64 ) ;
goto V_112;
}
F_24 ( V_2 , 1 ) ;
return 0 ;
V_112:
F_31 ( V_2 ) ;
V_108:
F_49 ( V_2 -> V_12 ) ;
V_106:
F_50 ( V_2 ) ;
V_41 -> V_7 = NULL ;
V_104:
F_59 ( V_41 ) ;
V_101:
return V_32 ;
}
static void F_60 ( struct V_76 * V_41 )
{
F_47 ( V_41 ) ;
F_59 ( V_41 ) ;
}
static int T_5 F_61 ( void )
{
return F_62 ( & V_113 ) ;
}
static void T_6 F_63 ( void )
{
F_64 ( & V_113 ) ;
}
