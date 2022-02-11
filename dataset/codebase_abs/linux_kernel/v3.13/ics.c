static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( F_4 ( V_2 -> V_7 ) , V_8 | F_5 ( V_3 ) ) ;
V_5 = F_6 ( F_7 ( V_2 -> V_7 ) ) ;
F_8 ( & V_2 -> V_6 , V_4 ) ;
return V_5 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_5 )
{
V_5 &= ~ V_9 ;
V_5 |= ( V_3 & V_9 ) ;
V_5 |= V_10 ;
F_3 ( F_10 ( V_2 -> V_7 ) , V_5 ) ;
}
static T_1 F_11 ( T_1 V_5 , unsigned int V_11 )
{
T_1 V_12 = ~ ( V_13 << V_14 ) ;
V_5 &= V_12 ;
V_5 |= ( V_11 & V_13 ) << V_14 ;
return V_5 ;
}
static T_1 F_12 ( T_1 V_5 , unsigned int V_15 )
{
T_1 V_12 = ~ ( V_16 << V_17 ) ;
V_5 &= V_12 ;
V_5 |= ( V_15 & V_16 ) << V_17 ;
return V_5 ;
}
void F_13 ( int V_18 , T_2 * V_12 , T_2 * V_19 )
{
int V_20 , V_21 ;
struct V_22 * V_23 , * V_24 ;
const T_3 * V_25 ;
F_14 ( V_19 ) ;
F_15 (cpu, mask) {
V_23 = F_16 ( V_20 , NULL ) ;
if ( ! V_23 )
continue;
V_25 = F_17 ( V_23 , L_1 , NULL ) ;
if ( ! V_25 ) {
F_18 ( V_23 ) ;
continue;
}
V_24 = F_19 ( * V_25 ) ;
F_18 ( V_23 ) ;
V_21 = F_20 ( V_24 ) ;
if ( V_21 == V_18 )
F_21 ( V_20 , V_19 ) ;
F_18 ( V_24 ) ;
}
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_26 ,
const T_2 * V_27 )
{
T_4 V_28 , V_29 ;
int V_19 = - V_30 , V_20 , V_31 = 0 , V_32 ;
int V_33 = V_26 - V_2 -> V_34 ;
unsigned int V_35 ;
F_23 ( V_33 < 0 || V_33 >= V_2 -> V_36 ) ;
if ( ! V_2 -> V_37 )
return - V_30 ;
if ( ! V_38 ) {
V_2 -> V_37 [ V_26 - V_2 -> V_34 ] = V_39 ;
return 0 ;
}
if ( ! F_24 ( & V_28 , V_40 ) )
goto V_19;
if ( ! F_24 ( & V_29 , V_40 ) )
goto V_41;
V_35 = ( V_26 >> V_42 ) & 0x3 ;
if ( V_27 )
F_25 ( V_28 , V_43 , V_27 ) ;
else
F_26 ( V_28 , V_43 ) ;
F_13 ( V_35 , V_28 , V_29 ) ;
if ( F_27 ( F_28 ( V_29 ) ) ) {
if ( F_27 ( F_28 ( V_28 ) ) ) {
V_19 = - 1 ;
goto V_44;
}
F_26 ( V_29 , V_28 ) ;
}
V_32 = V_26 % F_29 ( V_29 ) ;
F_15 (cpu, newmask) {
if ( V_31 ++ >= V_32 ) {
V_2 -> V_37 [ V_33 ] = F_30 ( V_20 ) ;
V_19 = 0 ;
goto V_44;
}
}
F_31 ( 1 ) ;
V_44:
F_32 ( V_29 ) ;
V_41:
F_32 ( V_28 ) ;
V_19:
if ( V_19 < 0 ) {
V_2 -> V_37 [ V_33 ] = F_33 ( V_43 ) ;
F_34 ( L_2 ,
V_26 , V_2 -> V_37 [ V_33 ] ) ;
}
return V_19 ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_45 ;
V_2 -> V_37 = F_36 ( sizeof( int ) * V_2 -> V_36 , V_40 ) ;
if ( ! V_2 -> V_37 ) {
F_34 ( L_3
L_4 ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_2 -> V_36 ; V_45 ++ )
V_2 -> V_37 [ V_45 ] = V_39 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_26 )
{
int V_33 = V_26 - V_2 -> V_34 ;
F_23 ( V_33 < 0 || V_33 >= V_2 -> V_36 ) ;
if ( ! V_2 -> V_37 )
return V_39 ;
return V_2 -> V_37 [ V_33 ] ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_26 ,
const T_2 * V_27 )
{
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_26 )
{
return V_39 ;
}
static void F_35 ( struct V_1 * V_2 ) { }
static void F_38 ( struct V_46 * V_47 )
{
unsigned int V_48 = ( unsigned int ) F_39 ( V_47 ) ;
struct V_1 * V_2 ;
int V_11 ;
T_1 V_5 ;
if ( V_48 == V_49 || V_48 == V_50 )
return;
V_2 = V_47 -> V_51 ;
if ( F_31 ( ! V_2 ) )
return;
V_11 = F_37 ( V_2 , V_48 ) ;
V_5 = F_1 ( V_2 , V_48 ) ;
V_5 = F_11 ( V_5 , V_11 ) ;
V_5 = F_12 ( V_5 , V_52 ) ;
F_9 ( V_2 , V_48 , V_5 ) ;
}
static unsigned int F_40 ( struct V_46 * V_47 )
{
F_38 ( V_47 ) ;
return 0 ;
}
static void F_41 ( unsigned int V_48 , struct V_1 * V_2 )
{
T_1 V_5 ;
if ( V_48 == V_49 )
return;
if ( F_31 ( ! V_2 ) )
return;
V_5 = F_1 ( V_2 , V_48 ) ;
V_5 = F_11 ( V_5 , V_39 ) ;
V_5 = F_12 ( V_5 , V_53 ) ;
F_9 ( V_2 , V_48 , V_5 ) ;
}
static void F_42 ( struct V_46 * V_47 )
{
unsigned int V_48 = ( unsigned int ) F_39 ( V_47 ) ;
struct V_1 * V_2 = V_47 -> V_51 ;
if ( V_48 == V_49 || V_48 == V_50 )
return;
F_41 ( V_48 , V_2 ) ;
}
static int F_43 ( struct V_46 * V_47 ,
const struct V_54 * V_54 , bool V_55 )
{
unsigned int V_48 = ( unsigned int ) F_39 ( V_47 ) ;
struct V_1 * V_2 ;
int V_19 ;
T_1 V_5 ;
if ( V_48 == V_49 || V_48 == V_50 )
return - 1 ;
V_2 = V_47 -> V_51 ;
if ( F_31 ( ! V_2 ) )
return - 1 ;
V_5 = F_1 ( V_2 , V_48 ) ;
V_19 = F_22 ( V_2 , V_48 , V_54 ) ;
if ( V_19 == - 1 ) {
char V_56 [ 128 ] ;
F_44 ( V_56 , sizeof( V_56 ) , V_54 ) ;
F_34 ( L_5 ,
V_57 , V_56 , V_47 -> V_3 ) ;
return - 1 ;
} else if ( V_19 == - V_30 ) {
F_34 ( L_6 , V_57 ) ;
return - 1 ;
}
V_5 = F_11 ( V_5 , F_37 ( V_2 , V_48 ) ) ;
F_9 ( V_2 , V_48 , V_5 ) ;
return V_58 ;
}
static int F_45 ( struct V_2 * V_2 , struct V_22 * V_24 )
{
return F_46 ( V_24 , L_7 ) ;
}
static int F_47 ( struct V_1 * V_1 , unsigned int V_26 )
{
if ( V_26 >= V_1 -> V_34 &&
V_26 < V_1 -> V_34 + V_1 -> V_36 )
return 1 ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , unsigned int V_59 )
{
struct V_1 * V_1 = F_49 ( V_2 ) ;
unsigned int V_48 = F_50 ( V_59 ) ;
unsigned long V_4 ;
if ( ! F_47 ( V_1 , V_48 ) )
return - V_60 ;
F_51 ( V_59 , & V_61 , V_62 ) ;
F_52 ( V_59 , V_1 ) ;
F_2 ( & V_1 -> V_6 , V_4 ) ;
F_53 ( V_1 -> V_63 , V_48 - V_1 -> V_34 , 0 ) ;
F_8 ( & V_1 -> V_6 , V_4 ) ;
return 0 ;
}
static void F_54 ( struct V_2 * V_2 , unsigned long V_48 )
{
struct V_1 * V_1 = F_49 ( V_2 ) ;
if ( ! F_47 ( V_1 , V_48 ) )
return;
F_55 ( L_8 , V_57 , V_48 ) ;
F_41 ( V_48 , V_1 ) ;
}
static long F_56 ( struct V_2 * V_2 , unsigned long V_48 )
{
struct V_1 * V_1 = F_49 ( V_2 ) ;
if ( ! F_47 ( V_1 , V_48 ) )
return - V_60 ;
return F_37 ( V_1 , V_48 ) ;
}
static struct V_1 * F_57 ( struct V_22 * V_24 )
{
struct V_22 * V_64 ;
int V_45 ;
V_64 = F_58 ( V_24 ) ;
if ( ! V_64 ) {
F_55 ( L_9 ) ;
return NULL ;
}
for( V_45 = 0 ; V_45 < V_65 ; V_45 ++ ) {
if( V_66 [ V_45 ] . V_24 == V_64 )
break;
}
if ( V_45 >= V_65 ) {
F_55 ( L_10 ) ;
return NULL ;
}
return & V_66 [ V_45 ] ;
}
int F_59 ( struct V_22 * V_24 , int V_67 )
{
struct V_1 * V_2 ;
int V_68 , V_69 ;
V_2 = F_57 ( V_24 ) ;
if ( ! V_2 )
return - V_70 ;
V_68 = F_60 ( V_67 ) ;
F_61 ( & V_2 -> V_6 ) ;
V_69 = F_62 ( V_2 -> V_63 , V_2 -> V_36 , V_68 ) ;
F_63 ( & V_2 -> V_6 ) ;
if ( V_69 < 0 )
return V_69 ;
return V_69 + V_2 -> V_34 ;
}
void F_64 ( struct V_22 * V_24 , unsigned int V_3 )
{
struct V_1 * V_2 ;
V_2 = F_57 ( V_24 ) ;
if ( F_31 ( ! V_2 ) )
return;
F_61 ( & V_2 -> V_6 ) ;
F_65 ( V_2 -> V_63 , V_3 , 0 ) ;
F_63 ( & V_2 -> V_6 ) ;
}
static int T_5 F_66 ( struct V_1 * V_2 ,
struct V_22 * V_24 )
{
int V_71 , V_45 , V_72 , V_73 ;
T_3 V_74 , V_36 ;
const T_3 * V_75 ;
V_73 = F_67 ( V_2 -> V_36 ) * sizeof( long ) ;
V_2 -> V_63 = F_68 ( V_73 , V_40 ) ;
if ( ! V_2 -> V_63 ) {
F_55 ( L_11 ) ;
return - V_30 ;
}
F_69 ( & V_2 -> V_6 ) ;
V_75 = F_17 ( V_24 , L_12 , & V_71 ) ;
if ( ! V_75 || ! V_71 ) {
F_55 ( L_13 ,
V_24 -> V_76 ) ;
return 0 ;
}
if ( V_71 % ( 2 * sizeof( T_3 ) ) != 0 ) {
F_55 ( L_14 ,
V_24 -> V_76 ) ;
return 0 ;
}
F_70 ( V_2 -> V_63 , V_2 -> V_36 ) ;
for ( V_45 = 0 ; V_45 < V_71 / sizeof( T_3 ) ; V_45 += 2 ) {
V_74 = F_71 ( V_75 + V_45 , 1 ) ;
V_36 = F_71 ( V_75 + V_45 + 1 , 1 ) ;
F_72 ( L_15 , V_57 , V_74 , V_36 ) ;
if ( ( V_74 + V_36 ) > ( V_2 -> V_34 + V_2 -> V_36 ) ||
V_74 < V_2 -> V_34 ) {
F_55 ( L_16 ,
V_74 , V_74 + V_36 ) ;
break;
}
for ( V_72 = 0 ; V_72 < V_36 ; V_72 ++ )
F_65 ( V_2 -> V_63 ,
( V_74 + V_72 ) - V_2 -> V_34 , 0 ) ;
}
F_53 ( V_2 -> V_63 , V_2 -> V_77 ,
F_60 ( V_2 -> V_78 ) ) ;
return 0 ;
}
static int T_5 F_73 ( struct V_1 * V_2 , struct V_22 * V_24 )
{
T_3 V_79 , V_80 , V_81 , V_82 ;
void T_6 * V_7 ;
const T_3 * V_75 ;
int V_83 , V_71 , V_45 ;
T_1 V_84 , V_85 ;
V_75 = F_17 ( V_24 , L_17 , & V_71 ) ;
if ( ! V_75 || V_71 < ( 2 * sizeof( T_3 ) ) ) {
F_55 ( L_18 ,
V_24 -> V_76 ) ;
return - V_60 ;
}
if ( V_71 > ( 2 * sizeof( T_3 ) ) ) {
F_55 ( L_19 ) ;
return - V_86 ;
}
V_7 = F_74 ( V_24 , 0 ) ;
if ( ! V_7 ) {
F_55 ( L_20 , V_24 -> V_76 ) ;
return - V_87 ;
}
V_2 -> V_34 = F_71 ( V_75 , 1 ) ;
V_2 -> V_36 = F_71 ( V_75 + 1 , 1 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_18 = F_20 ( V_24 ) ;
if ( F_31 ( V_2 -> V_18 < 0 ) )
V_2 -> V_18 = 0 ;
V_84 = F_6 ( F_75 ( V_2 -> V_7 ) ) ;
V_85 = F_6 ( F_76 ( V_2 -> V_7 ) ) ;
V_2 -> V_78 = V_84 >> 56 ;
V_82 = ( V_84 >> 44 ) & 0x7ff ;
V_79 = ( V_85 >> 48 ) & 0x1ff ;
V_2 -> V_77 = ( V_2 -> V_18 << V_42 ) | V_79 << 5 ;
V_80 = ( V_85 >> 37 ) & 0x7 ;
V_81 = ( V_2 -> V_18 << V_42 ) | V_80 << 11 ;
F_77 ( L_21 , V_24 -> V_76 ) ;
F_77 ( L_22 ,
V_2 -> V_34 , V_2 -> V_34 + V_2 -> V_36 - 1 ) ;
F_77 ( L_23 ,
V_2 -> V_78 , V_2 -> V_77 ,
V_2 -> V_77 + V_2 -> V_78 - 1 ) ;
F_77 ( L_24 ,
V_82 , V_81 ,
V_81 + V_82 - 1 ) ;
if ( V_2 -> V_77 < V_2 -> V_34 ||
( V_2 -> V_77 + V_2 -> V_78 ) > ( V_2 -> V_34 + V_2 -> V_36 ) )
F_34 ( L_25 ) ;
if ( V_81 < V_2 -> V_34 ||
( V_81 + V_82 ) > ( V_2 -> V_34 + V_2 -> V_36 ) )
F_34 ( L_26 ) ;
V_83 = F_66 ( V_2 , V_24 ) ;
if ( V_83 ) {
F_78 ( V_7 ) ;
return V_83 ;
}
V_2 -> V_24 = F_79 ( V_24 ) ;
F_35 ( V_2 ) ;
for( V_45 = 0 ; V_45 < V_2 -> V_36 ; V_45 ++ )
F_41 ( V_2 -> V_34 + V_45 , V_2 ) ;
V_2 -> V_2 . V_88 = F_48 ;
V_2 -> V_2 . V_89 = F_54 ;
V_2 -> V_2 . V_90 = F_56 ;
V_2 -> V_2 . V_91 = F_45 ;
F_80 ( & V_2 -> V_2 ) ;
return 0 ;
}
static void T_5 F_81 ( void )
{
struct V_22 * V_92 ;
T_3 V_93 ;
V_92 = F_16 ( V_94 , NULL ) ;
F_23 ( ! V_92 ) ;
V_93 = F_30 ( V_94 ) ;
F_77 ( L_27 , V_93 , V_92 -> V_76 ) ;
V_39 = V_93 ;
F_18 ( V_92 ) ;
}
static int T_5 F_82 ( void )
{
struct V_22 * V_24 ;
struct V_1 * V_2 ;
int V_83 , V_95 ;
F_81 () ;
V_95 = 0 ;
F_83 (dn, NULL, L_7 )
V_95 ++ ;
if ( V_95 == 0 ) {
F_55 ( L_28 ) ;
return - V_70 ;
}
V_66 = F_36 ( sizeof( * V_2 ) * V_95 , V_40 ) ;
if ( ! V_66 ) {
F_55 ( L_29 ) ;
return - V_30 ;
}
V_65 = 0 ;
V_2 = V_66 ;
F_83 (dn, NULL, L_30 ) {
V_83 = F_73 ( V_2 , V_24 ) ;
if ( V_83 == 0 ) {
V_2 ++ ;
V_65 ++ ;
}
}
if ( V_95 != V_65 ) {
F_55 ( L_31 ,
V_95 - V_65 ) ;
return - 1 ;
}
return 0 ;
}
void T_5 F_84 ( void )
{
F_82 () ;
F_85 () ;
V_61 . V_96 = V_97 -> V_98 ;
}
static void F_86 ( struct V_46 * V_47 )
{
F_38 ( V_47 ) ;
F_87 ( V_47 ) ;
}
static unsigned int F_88 ( struct V_46 * V_47 )
{
F_86 ( V_47 ) ;
return 0 ;
}
static void F_89 ( struct V_46 * V_47 )
{
F_90 ( V_47 ) ;
F_42 ( V_47 ) ;
}
static void F_91 ( struct V_46 * V_99 )
{
V_61 . V_96 ( V_99 ) ;
}
void F_92 ( unsigned int V_3 )
{
F_93 ( V_3 , & V_100 ) ;
}
void F_94 ( unsigned int V_3 )
{
F_93 ( V_3 , & V_61 ) ;
}
