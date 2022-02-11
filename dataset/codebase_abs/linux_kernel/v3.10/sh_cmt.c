static unsigned long F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
return F_2 ( V_1 + ( V_2 << 1 ) ) ;
}
static unsigned long F_3 ( void T_1 * V_1 , unsigned long V_2 )
{
return F_4 ( V_1 + ( V_2 << 2 ) ) ;
}
static void F_5 ( void T_1 * V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
F_6 ( V_3 , V_1 + ( V_2 << 1 ) ) ;
}
static void F_7 ( void T_1 * V_1 , unsigned long V_2 ,
unsigned long V_3 )
{
F_8 ( V_3 , V_1 + ( V_2 << 2 ) ) ;
}
static inline unsigned long F_9 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_9 . V_10 ;
return V_5 -> V_11 ( V_5 -> V_12 - V_7 -> V_13 , 0 ) ;
}
static inline unsigned long F_10 ( struct V_4 * V_5 )
{
return V_5 -> V_11 ( V_5 -> V_12 , V_14 ) ;
}
static inline unsigned long F_11 ( struct V_4 * V_5 )
{
return V_5 -> V_15 ( V_5 -> V_12 , V_16 ) ;
}
static inline void F_12 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_9 . V_10 ;
V_5 -> V_17 ( V_5 -> V_12 - V_7 -> V_13 , 0 , V_3 ) ;
}
static inline void F_13 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
V_5 -> V_17 ( V_5 -> V_12 , V_14 , V_3 ) ;
}
static inline void F_14 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
V_5 -> V_18 ( V_5 -> V_12 , V_16 , V_3 ) ;
}
static inline void F_15 ( struct V_4 * V_5 ,
unsigned long V_3 )
{
V_5 -> V_18 ( V_5 -> V_12 , V_19 , V_3 ) ;
}
static unsigned long F_16 ( struct V_4 * V_5 ,
int * V_20 )
{
unsigned long V_21 , V_22 , V_23 ;
int V_24 , V_25 ;
V_24 = F_10 ( V_5 ) & V_5 -> V_26 ;
do {
V_25 = V_24 ;
V_21 = F_11 ( V_5 ) ;
V_22 = F_11 ( V_5 ) ;
V_23 = F_11 ( V_5 ) ;
V_24 = F_10 ( V_5 ) & V_5 -> V_26 ;
} while ( F_17 ( ( V_24 != V_25 ) || ( V_21 > V_22 && V_21 < V_23 )
|| ( V_22 > V_23 && V_22 < V_21 ) || ( V_23 > V_21 && V_23 < V_22 ) ) );
* V_20 = V_24 ;
return V_22 ;
}
static void F_18 ( struct V_4 * V_5 , int V_27 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_9 . V_10 ;
unsigned long V_28 , V_3 ;
F_19 ( & V_29 , V_28 ) ;
V_3 = F_9 ( V_5 ) ;
if ( V_27 )
V_3 |= 1 << V_7 -> V_30 ;
else
V_3 &= ~ ( 1 << V_7 -> V_30 ) ;
F_12 ( V_5 , V_3 ) ;
F_20 ( & V_29 , V_28 ) ;
}
static int F_21 ( struct V_4 * V_5 , unsigned long * V_31 )
{
int V_32 , V_33 ;
F_22 ( & V_5 -> V_8 -> V_9 ) ;
F_23 ( & V_5 -> V_8 -> V_9 , true ) ;
V_33 = F_24 ( V_5 -> V_34 ) ;
if ( V_33 ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_1 ) ;
goto V_35;
}
F_18 ( V_5 , 0 ) ;
if ( V_5 -> V_36 == 16 ) {
* V_31 = F_26 ( V_5 -> V_34 ) / 512 ;
F_13 ( V_5 , 0x43 ) ;
} else {
* V_31 = F_26 ( V_5 -> V_34 ) / 8 ;
F_13 ( V_5 , 0x01a4 ) ;
}
F_15 ( V_5 , 0xffffffff ) ;
F_14 ( V_5 , 0 ) ;
for ( V_32 = 0 ; V_32 < 100 ; V_32 ++ ) {
if ( ! F_11 ( V_5 ) )
break;
F_27 ( 1 ) ;
}
if ( F_11 ( V_5 ) ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_2 ) ;
V_33 = - V_37 ;
goto V_38;
}
F_18 ( V_5 , 1 ) ;
return 0 ;
V_38:
F_28 ( V_5 -> V_34 ) ;
V_35:
return V_33 ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_18 ( V_5 , 0 ) ;
F_13 ( V_5 , 0 ) ;
F_28 ( V_5 -> V_34 ) ;
F_23 ( & V_5 -> V_8 -> V_9 , false ) ;
F_30 ( & V_5 -> V_8 -> V_9 ) ;
}
static void F_31 ( struct V_4 * V_5 ,
int V_39 )
{
unsigned long V_40 ;
unsigned long V_3 = V_5 -> V_41 ;
unsigned long V_42 = 0 ;
unsigned long V_43 = 0 ;
int V_20 ;
V_43 = F_16 ( V_5 , & V_20 ) ;
V_5 -> V_28 |= V_44 ;
if ( V_20 ) {
V_5 -> V_28 |= V_45 ;
return;
}
if ( V_39 )
V_43 = 0 ;
do {
V_40 = V_43 + V_3 + V_42 ;
if ( V_40 > V_5 -> V_46 )
V_40 = V_5 -> V_46 ;
F_15 ( V_5 , V_40 ) ;
V_43 = F_16 ( V_5 , & V_20 ) ;
if ( V_20 && ( V_40 > V_5 -> V_47 ) ) {
V_5 -> V_28 |= V_45 ;
break;
}
if ( V_20 ) {
V_5 -> V_47 = V_40 ;
break;
}
if ( V_43 < V_40 ) {
V_5 -> V_47 = V_40 ;
break;
}
if ( V_42 )
V_42 <<= 1 ;
else
V_42 = 1 ;
if ( ! V_42 )
F_32 ( & V_5 -> V_8 -> V_9 , L_3 ) ;
} while ( V_42 );
}
static void F_33 ( struct V_4 * V_5 , unsigned long V_48 )
{
if ( V_48 > V_5 -> V_46 )
F_32 ( & V_5 -> V_8 -> V_9 , L_4 ) ;
V_5 -> V_41 = V_48 ;
F_31 ( V_5 , 0 ) ;
}
static void F_34 ( struct V_4 * V_5 , unsigned long V_48 )
{
unsigned long V_28 ;
F_19 ( & V_5 -> V_49 , V_28 ) ;
F_33 ( V_5 , V_48 ) ;
F_20 ( & V_5 -> V_49 , V_28 ) ;
}
static T_2 F_35 ( int V_50 , void * V_51 )
{
struct V_4 * V_5 = V_51 ;
F_13 ( V_5 , F_10 ( V_5 ) & V_5 -> V_52 ) ;
if ( V_5 -> V_28 & V_53 )
V_5 -> V_54 += V_5 -> V_47 + 1 ;
if ( ! ( V_5 -> V_28 & V_44 ) )
V_5 -> V_41 = V_5 -> V_46 ;
V_5 -> V_28 |= V_55 ;
if ( V_5 -> V_28 & V_56 ) {
if ( ! ( V_5 -> V_28 & V_45 ) ) {
if ( V_5 -> V_57 . V_58 == V_59 ) {
V_5 -> V_41 = V_5 -> V_46 ;
V_5 -> V_28 |= V_44 ;
}
V_5 -> V_57 . V_60 ( & V_5 -> V_57 ) ;
}
}
V_5 -> V_28 &= ~ V_45 ;
if ( V_5 -> V_28 & V_44 ) {
V_5 -> V_28 &= ~ V_44 ;
F_31 ( V_5 , 1 ) ;
if ( V_5 -> V_28 & V_56 )
if ( ( V_5 -> V_57 . V_58 == V_61 )
|| ( V_5 -> V_47 == V_5 -> V_41 ) )
V_5 -> V_28 &= ~ V_44 ;
}
V_5 -> V_28 &= ~ V_55 ;
return V_62 ;
}
static int F_36 ( struct V_4 * V_5 , unsigned long V_63 )
{
int V_33 = 0 ;
unsigned long V_28 ;
F_19 ( & V_5 -> V_49 , V_28 ) ;
if ( ! ( V_5 -> V_28 & ( V_56 | V_53 ) ) )
V_33 = F_21 ( V_5 , & V_5 -> V_31 ) ;
if ( V_33 )
goto V_64;
V_5 -> V_28 |= V_63 ;
if ( ( V_63 == V_53 ) && ( ! ( V_5 -> V_28 & V_56 ) ) )
F_33 ( V_5 , V_5 -> V_46 ) ;
V_64:
F_20 ( & V_5 -> V_49 , V_28 ) ;
return V_33 ;
}
static void F_37 ( struct V_4 * V_5 , unsigned long V_63 )
{
unsigned long V_28 ;
unsigned long V_65 ;
F_19 ( & V_5 -> V_49 , V_28 ) ;
V_65 = V_5 -> V_28 & ( V_56 | V_53 ) ;
V_5 -> V_28 &= ~ V_63 ;
if ( V_65 && ! ( V_5 -> V_28 & ( V_56 | V_53 ) ) )
F_29 ( V_5 ) ;
if ( ( V_63 == V_56 ) && ( V_5 -> V_28 & V_53 ) )
F_33 ( V_5 , V_5 -> V_46 ) ;
F_20 ( & V_5 -> V_49 , V_28 ) ;
}
static struct V_4 * F_38 ( struct V_66 * V_67 )
{
return F_39 ( V_67 , struct V_4 , V_67 ) ;
}
static T_3 F_40 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = F_38 ( V_67 ) ;
unsigned long V_28 , V_68 ;
unsigned long V_3 ;
int V_20 ;
F_19 ( & V_5 -> V_49 , V_28 ) ;
V_3 = V_5 -> V_54 ;
V_68 = F_16 ( V_5 , & V_20 ) ;
if ( F_17 ( V_20 ) )
V_68 += V_5 -> V_47 + 1 ;
F_20 ( & V_5 -> V_49 , V_28 ) ;
return V_3 + V_68 ;
}
static int F_41 ( struct V_66 * V_67 )
{
int V_33 ;
struct V_4 * V_5 = F_38 ( V_67 ) ;
F_42 ( V_5 -> V_69 ) ;
V_5 -> V_54 = 0 ;
V_33 = F_36 ( V_5 , V_53 ) ;
if ( ! V_33 ) {
F_43 ( V_67 , V_5 -> V_31 ) ;
V_5 -> V_69 = true ;
}
return V_33 ;
}
static void F_44 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = F_38 ( V_67 ) ;
F_42 ( ! V_5 -> V_69 ) ;
F_37 ( V_5 , V_53 ) ;
V_5 -> V_69 = false ;
}
static void F_45 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = F_38 ( V_67 ) ;
F_37 ( V_5 , V_53 ) ;
F_46 ( & V_5 -> V_8 -> V_9 ) ;
}
static void F_47 ( struct V_66 * V_67 )
{
struct V_4 * V_5 = F_38 ( V_67 ) ;
F_48 ( & V_5 -> V_8 -> V_9 ) ;
F_36 ( V_5 , V_53 ) ;
}
static int F_49 ( struct V_4 * V_5 ,
char * V_70 , unsigned long V_71 )
{
struct V_66 * V_67 = & V_5 -> V_67 ;
V_67 -> V_70 = V_70 ;
V_67 -> V_71 = V_71 ;
V_67 -> V_72 = F_40 ;
V_67 -> V_73 = F_41 ;
V_67 -> V_74 = F_44 ;
V_67 -> V_75 = F_45 ;
V_67 -> V_76 = F_47 ;
V_67 -> V_77 = F_50 ( sizeof( unsigned long ) * 8 ) ;
V_67 -> V_28 = V_78 ;
F_51 ( & V_5 -> V_8 -> V_9 , L_5 ) ;
F_52 ( V_67 , 1 ) ;
return 0 ;
}
static struct V_4 * F_53 ( struct V_79 * V_57 )
{
return F_39 ( V_57 , struct V_4 , V_57 ) ;
}
static void F_54 ( struct V_4 * V_5 , int V_80 )
{
struct V_79 * V_57 = & V_5 -> V_57 ;
F_36 ( V_5 , V_56 ) ;
V_57 -> V_81 = 32 ;
V_57 -> V_82 = F_55 ( V_5 -> V_31 , V_83 , V_57 -> V_81 ) ;
V_57 -> V_84 = F_56 ( V_5 -> V_46 , V_57 ) ;
V_57 -> V_85 = F_56 ( 0x1f , V_57 ) ;
if ( V_80 )
F_34 ( V_5 , ( ( V_5 -> V_31 + V_86 / 2 ) / V_86 ) - 1 ) ;
else
F_34 ( V_5 , V_5 -> V_46 ) ;
}
static void F_57 ( enum V_87 V_58 ,
struct V_79 * V_57 )
{
struct V_4 * V_5 = F_53 ( V_57 ) ;
switch ( V_57 -> V_58 ) {
case V_88 :
case V_59 :
F_37 ( V_5 , V_56 ) ;
break;
default:
break;
}
switch ( V_58 ) {
case V_88 :
F_51 ( & V_5 -> V_8 -> V_9 , L_6 ) ;
F_54 ( V_5 , 1 ) ;
break;
case V_59 :
F_51 ( & V_5 -> V_8 -> V_9 , L_7 ) ;
F_54 ( V_5 , 0 ) ;
break;
case V_61 :
case V_89 :
F_37 ( V_5 , V_56 ) ;
break;
default:
break;
}
}
static int F_58 ( unsigned long V_48 ,
struct V_79 * V_57 )
{
struct V_4 * V_5 = F_53 ( V_57 ) ;
F_59 ( V_57 -> V_58 != V_59 ) ;
if ( F_60 ( V_5 -> V_28 & V_55 ) )
V_5 -> V_41 = V_48 - 1 ;
else
F_34 ( V_5 , V_48 - 1 ) ;
return 0 ;
}
static void F_61 ( struct V_79 * V_57 )
{
F_46 ( & F_53 ( V_57 ) -> V_8 -> V_9 ) ;
}
static void F_62 ( struct V_79 * V_57 )
{
F_48 ( & F_53 ( V_57 ) -> V_8 -> V_9 ) ;
}
static void F_63 ( struct V_4 * V_5 ,
char * V_70 , unsigned long V_71 )
{
struct V_79 * V_57 = & V_5 -> V_57 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_70 = V_70 ;
V_57 -> V_90 = V_91 ;
V_57 -> V_90 |= V_92 ;
V_57 -> V_71 = V_71 ;
V_57 -> V_93 = F_64 ( 0 ) ;
V_57 -> V_94 = F_58 ;
V_57 -> V_95 = F_57 ;
V_57 -> V_75 = F_61 ;
V_57 -> V_76 = F_62 ;
F_51 ( & V_5 -> V_8 -> V_9 , L_8 ) ;
F_65 ( V_57 ) ;
}
static int F_66 ( struct V_4 * V_5 , char * V_70 ,
unsigned long V_96 ,
unsigned long V_97 )
{
if ( V_96 )
F_63 ( V_5 , V_70 , V_96 ) ;
if ( V_97 )
F_49 ( V_5 , V_70 , V_97 ) ;
return 0 ;
}
static int F_67 ( struct V_4 * V_5 , struct V_98 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_9 . V_10 ;
struct V_99 * V_100 ;
int V_50 , V_33 ;
V_33 = - V_101 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_8 = V_8 ;
if ( ! V_7 ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_9 ) ;
goto V_35;
}
V_100 = F_68 ( V_5 -> V_8 , V_102 , 0 ) ;
if ( ! V_100 ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_10 ) ;
goto V_35;
}
V_50 = F_69 ( V_5 -> V_8 , 0 ) ;
if ( V_50 < 0 ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_11 ) ;
goto V_35;
}
V_5 -> V_12 = F_70 ( V_100 -> V_27 , F_71 ( V_100 ) ) ;
if ( V_5 -> V_12 == NULL ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_12 ) ;
goto V_35;
}
V_5 -> V_103 . V_70 = F_72 ( & V_5 -> V_8 -> V_9 ) ;
V_5 -> V_103 . V_104 = F_35 ;
V_5 -> V_103 . V_51 = V_5 ;
V_5 -> V_103 . V_28 = V_105 | V_106 | \
V_107 | V_108 ;
V_5 -> V_34 = F_73 ( & V_5 -> V_8 -> V_9 , L_13 ) ;
if ( F_74 ( V_5 -> V_34 ) ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_14 ) ;
V_33 = F_75 ( V_5 -> V_34 ) ;
goto V_38;
}
V_5 -> V_11 = F_1 ;
V_5 -> V_17 = F_5 ;
if ( F_71 ( V_100 ) == 6 ) {
V_5 -> V_36 = 16 ;
V_5 -> V_15 = F_1 ;
V_5 -> V_18 = F_5 ;
V_5 -> V_26 = 0x80 ;
V_5 -> V_52 = ~ 0x80 ;
} else {
V_5 -> V_36 = 32 ;
V_5 -> V_15 = F_3 ;
V_5 -> V_18 = F_7 ;
V_5 -> V_26 = 0x8000 ;
V_5 -> V_52 = ~ 0xc000 ;
}
if ( V_5 -> V_36 == ( sizeof( V_5 -> V_46 ) * 8 ) )
V_5 -> V_46 = ~ 0 ;
else
V_5 -> V_46 = ( 1 << V_5 -> V_36 ) - 1 ;
V_5 -> V_47 = V_5 -> V_46 ;
F_76 ( & V_5 -> V_49 ) ;
V_33 = F_66 ( V_5 , ( char * ) F_72 ( & V_5 -> V_8 -> V_9 ) ,
V_7 -> V_96 ,
V_7 -> V_97 ) ;
if ( V_33 ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_15 ) ;
goto V_109;
}
V_5 -> V_69 = false ;
V_33 = F_77 ( V_50 , & V_5 -> V_103 ) ;
if ( V_33 ) {
F_25 ( & V_5 -> V_8 -> V_9 , L_16 , V_50 ) ;
goto V_109;
}
F_78 ( V_8 , V_5 ) ;
return 0 ;
V_109:
F_79 ( V_5 -> V_34 ) ;
V_38:
F_80 ( V_5 -> V_12 ) ;
V_35:
return V_33 ;
}
static int F_81 ( struct V_98 * V_8 )
{
struct V_4 * V_5 = F_82 ( V_8 ) ;
struct V_6 * V_7 = V_8 -> V_9 . V_10 ;
int V_33 ;
if ( ! F_83 ( V_8 ) ) {
F_84 ( & V_8 -> V_9 ) ;
F_85 ( & V_8 -> V_9 ) ;
}
if ( V_5 ) {
F_51 ( & V_8 -> V_9 , L_17 ) ;
goto V_64;
}
V_5 = F_86 ( sizeof( * V_5 ) , V_110 ) ;
if ( V_5 == NULL ) {
F_25 ( & V_8 -> V_9 , L_18 ) ;
return - V_111 ;
}
V_33 = F_67 ( V_5 , V_8 ) ;
if ( V_33 ) {
F_87 ( V_5 ) ;
F_88 ( & V_8 -> V_9 ) ;
return V_33 ;
}
if ( F_83 ( V_8 ) )
return 0 ;
V_64:
if ( V_7 -> V_96 || V_7 -> V_97 )
F_89 ( & V_8 -> V_9 ) ;
else
F_88 ( & V_8 -> V_9 ) ;
return 0 ;
}
static int F_90 ( struct V_98 * V_8 )
{
return - V_112 ;
}
static int T_4 F_91 ( void )
{
return F_92 ( & V_113 ) ;
}
static void T_5 F_93 ( void )
{
F_94 ( & V_113 ) ;
}
