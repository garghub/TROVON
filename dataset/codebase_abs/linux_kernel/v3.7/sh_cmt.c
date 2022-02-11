static inline unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 ;
if ( V_3 == V_12 ) {
V_11 = 0 ;
V_9 -= V_5 -> V_13 ;
} else
V_11 = V_3 ;
if ( V_2 -> V_14 == 16 )
V_11 <<= 1 ;
else {
V_11 <<= 2 ;
if ( ( V_3 == V_15 ) || ( V_3 == V_16 ) )
return F_2 ( V_9 + V_11 ) ;
}
return F_3 ( V_9 + V_11 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 ;
if ( V_3 == V_12 ) {
V_11 = 0 ;
V_9 -= V_5 -> V_13 ;
} else
V_11 = V_3 ;
if ( V_2 -> V_14 == 16 )
V_11 <<= 1 ;
else {
V_11 <<= 2 ;
if ( ( V_3 == V_15 ) || ( V_3 == V_16 ) ) {
F_5 ( V_17 , V_9 + V_11 ) ;
return;
}
}
F_6 ( V_17 , V_9 + V_11 ) ;
}
static unsigned long F_7 ( struct V_1 * V_2 ,
int * V_18 )
{
unsigned long V_19 , V_20 , V_21 ;
int V_22 , V_23 ;
V_22 = F_1 ( V_2 , V_24 ) & V_2 -> V_25 ;
do {
V_23 = V_22 ;
V_19 = F_1 ( V_2 , V_15 ) ;
V_20 = F_1 ( V_2 , V_15 ) ;
V_21 = F_1 ( V_2 , V_15 ) ;
V_22 = F_1 ( V_2 , V_24 ) & V_2 -> V_25 ;
} while ( F_8 ( ( V_22 != V_23 ) || ( V_19 > V_20 && V_19 < V_21 )
|| ( V_20 > V_21 && V_20 < V_19 ) || ( V_21 > V_19 && V_21 < V_20 ) ) );
* V_18 = V_22 ;
return V_20 ;
}
static void F_9 ( struct V_1 * V_2 , int V_26 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
unsigned long V_27 , V_17 ;
F_10 ( & V_28 , V_27 ) ;
V_17 = F_1 ( V_2 , V_12 ) ;
if ( V_26 )
V_17 |= 1 << V_5 -> V_29 ;
else
V_17 &= ~ ( 1 << V_5 -> V_29 ) ;
F_4 ( V_2 , V_12 , V_17 ) ;
F_11 ( & V_28 , V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long * V_30 )
{
int V_31 , V_32 ;
F_13 ( & V_2 -> V_6 -> V_7 ) ;
F_14 ( & V_2 -> V_6 -> V_7 , true ) ;
V_32 = F_15 ( V_2 -> V_33 ) ;
if ( V_32 ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
goto V_34;
}
F_9 ( V_2 , 0 ) ;
if ( V_2 -> V_14 == 16 ) {
* V_30 = F_17 ( V_2 -> V_33 ) / 512 ;
F_4 ( V_2 , V_24 , 0x43 ) ;
} else {
* V_30 = F_17 ( V_2 -> V_33 ) / 8 ;
F_4 ( V_2 , V_24 , 0x01a4 ) ;
}
F_4 ( V_2 , V_16 , 0xffffffff ) ;
F_4 ( V_2 , V_15 , 0 ) ;
for ( V_31 = 0 ; V_31 < 100 ; V_31 ++ ) {
if ( ! F_1 ( V_2 , V_15 ) )
break;
F_18 ( 1 ) ;
}
if ( F_1 ( V_2 , V_15 ) ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
V_32 = - V_35 ;
goto V_36;
}
F_9 ( V_2 , 1 ) ;
return 0 ;
V_36:
F_19 ( V_2 -> V_33 ) ;
V_34:
return V_32 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_4 ( V_2 , V_24 , 0 ) ;
F_19 ( V_2 -> V_33 ) ;
F_14 ( & V_2 -> V_6 -> V_7 , false ) ;
F_21 ( & V_2 -> V_6 -> V_7 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
int V_37 )
{
unsigned long V_38 ;
unsigned long V_17 = V_2 -> V_39 ;
unsigned long V_40 = 0 ;
unsigned long V_41 = 0 ;
int V_18 ;
V_41 = F_7 ( V_2 , & V_18 ) ;
V_2 -> V_27 |= V_42 ;
if ( V_18 ) {
V_2 -> V_27 |= V_43 ;
return;
}
if ( V_37 )
V_41 = 0 ;
do {
V_38 = V_41 + V_17 + V_40 ;
if ( V_38 > V_2 -> V_44 )
V_38 = V_2 -> V_44 ;
F_4 ( V_2 , V_16 , V_38 ) ;
V_41 = F_7 ( V_2 , & V_18 ) ;
if ( V_18 && ( V_38 > V_2 -> V_45 ) ) {
V_2 -> V_27 |= V_43 ;
break;
}
if ( V_18 ) {
V_2 -> V_45 = V_38 ;
break;
}
if ( V_41 < V_38 ) {
V_2 -> V_45 = V_38 ;
break;
}
if ( V_40 )
V_40 <<= 1 ;
else
V_40 = 1 ;
if ( ! V_40 )
F_23 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
} while ( V_40 );
}
static void F_24 ( struct V_1 * V_2 , unsigned long V_46 )
{
if ( V_46 > V_2 -> V_44 )
F_23 ( & V_2 -> V_6 -> V_7 , L_4 ) ;
V_2 -> V_39 = V_46 ;
F_22 ( V_2 , 0 ) ;
}
static void F_25 ( struct V_1 * V_2 , unsigned long V_46 )
{
unsigned long V_27 ;
F_10 ( & V_2 -> V_47 , V_27 ) ;
F_24 ( V_2 , V_46 ) ;
F_11 ( & V_2 -> V_47 , V_27 ) ;
}
static T_2 F_26 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
F_4 ( V_2 , V_24 , F_1 ( V_2 , V_24 ) & V_2 -> V_50 ) ;
if ( V_2 -> V_27 & V_51 )
V_2 -> V_52 += V_2 -> V_45 + 1 ;
if ( ! ( V_2 -> V_27 & V_42 ) )
V_2 -> V_39 = V_2 -> V_44 ;
V_2 -> V_27 |= V_53 ;
if ( V_2 -> V_27 & V_54 ) {
if ( ! ( V_2 -> V_27 & V_43 ) ) {
if ( V_2 -> V_55 . V_56 == V_57 ) {
V_2 -> V_39 = V_2 -> V_44 ;
V_2 -> V_27 |= V_42 ;
}
V_2 -> V_55 . V_58 ( & V_2 -> V_55 ) ;
}
}
V_2 -> V_27 &= ~ V_43 ;
if ( V_2 -> V_27 & V_42 ) {
V_2 -> V_27 &= ~ V_42 ;
F_22 ( V_2 , 1 ) ;
if ( V_2 -> V_27 & V_54 )
if ( ( V_2 -> V_55 . V_56 == V_59 )
|| ( V_2 -> V_45 == V_2 -> V_39 ) )
V_2 -> V_27 &= ~ V_42 ;
}
V_2 -> V_27 &= ~ V_53 ;
return V_60 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_61 )
{
int V_32 = 0 ;
unsigned long V_27 ;
F_10 ( & V_2 -> V_47 , V_27 ) ;
if ( ! ( V_2 -> V_27 & ( V_54 | V_51 ) ) )
V_32 = F_12 ( V_2 , & V_2 -> V_30 ) ;
if ( V_32 )
goto V_62;
V_2 -> V_27 |= V_61 ;
if ( ( V_61 == V_51 ) && ( ! ( V_2 -> V_27 & V_54 ) ) )
F_24 ( V_2 , V_2 -> V_44 ) ;
V_62:
F_11 ( & V_2 -> V_47 , V_27 ) ;
return V_32 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned long V_61 )
{
unsigned long V_27 ;
unsigned long V_63 ;
F_10 ( & V_2 -> V_47 , V_27 ) ;
V_63 = V_2 -> V_27 & ( V_54 | V_51 ) ;
V_2 -> V_27 &= ~ V_61 ;
if ( V_63 && ! ( V_2 -> V_27 & ( V_54 | V_51 ) ) )
F_20 ( V_2 ) ;
if ( ( V_61 == V_54 ) && ( V_2 -> V_27 & V_51 ) )
F_24 ( V_2 , V_2 -> V_44 ) ;
F_11 ( & V_2 -> V_47 , V_27 ) ;
}
static struct V_1 * F_29 ( struct V_64 * V_65 )
{
return F_30 ( V_65 , struct V_1 , V_65 ) ;
}
static T_3 F_31 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
unsigned long V_27 , V_66 ;
unsigned long V_17 ;
int V_18 ;
F_10 ( & V_2 -> V_47 , V_27 ) ;
V_17 = V_2 -> V_52 ;
V_66 = F_7 ( V_2 , & V_18 ) ;
if ( F_8 ( V_18 ) )
V_66 += V_2 -> V_45 + 1 ;
F_11 ( & V_2 -> V_47 , V_27 ) ;
return V_17 + V_66 ;
}
static int F_32 ( struct V_64 * V_65 )
{
int V_32 ;
struct V_1 * V_2 = F_29 ( V_65 ) ;
F_33 ( V_2 -> V_67 ) ;
V_2 -> V_52 = 0 ;
V_32 = F_27 ( V_2 , V_51 ) ;
if ( ! V_32 ) {
F_34 ( V_65 , V_2 -> V_30 ) ;
V_2 -> V_67 = true ;
}
return V_32 ;
}
static void F_35 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
F_33 ( ! V_2 -> V_67 ) ;
F_28 ( V_2 , V_51 ) ;
V_2 -> V_67 = false ;
}
static void F_36 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
F_28 ( V_2 , V_51 ) ;
F_37 ( & V_2 -> V_6 -> V_7 ) ;
}
static void F_38 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
F_39 ( & V_2 -> V_6 -> V_7 ) ;
F_27 ( V_2 , V_51 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
char * V_68 , unsigned long V_69 )
{
struct V_64 * V_65 = & V_2 -> V_65 ;
V_65 -> V_68 = V_68 ;
V_65 -> V_69 = V_69 ;
V_65 -> V_70 = F_31 ;
V_65 -> V_71 = F_32 ;
V_65 -> V_72 = F_35 ;
V_65 -> V_73 = F_36 ;
V_65 -> V_74 = F_38 ;
V_65 -> V_75 = F_41 ( sizeof( unsigned long ) * 8 ) ;
V_65 -> V_27 = V_76 ;
F_42 ( & V_2 -> V_6 -> V_7 , L_5 ) ;
F_43 ( V_65 , 1 ) ;
return 0 ;
}
static struct V_1 * F_44 ( struct V_77 * V_55 )
{
return F_30 ( V_55 , struct V_1 , V_55 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_78 )
{
struct V_77 * V_55 = & V_2 -> V_55 ;
F_27 ( V_2 , V_54 ) ;
V_55 -> V_79 = 32 ;
V_55 -> V_80 = F_46 ( V_2 -> V_30 , V_81 , V_55 -> V_79 ) ;
V_55 -> V_82 = F_47 ( V_2 -> V_44 , V_55 ) ;
V_55 -> V_83 = F_47 ( 0x1f , V_55 ) ;
if ( V_78 )
F_25 ( V_2 , ( ( V_2 -> V_30 + V_84 / 2 ) / V_84 ) - 1 ) ;
else
F_25 ( V_2 , V_2 -> V_44 ) ;
}
static void F_48 ( enum V_85 V_56 ,
struct V_77 * V_55 )
{
struct V_1 * V_2 = F_44 ( V_55 ) ;
switch ( V_55 -> V_56 ) {
case V_86 :
case V_57 :
F_28 ( V_2 , V_54 ) ;
break;
default:
break;
}
switch ( V_56 ) {
case V_86 :
F_42 ( & V_2 -> V_6 -> V_7 , L_6 ) ;
F_45 ( V_2 , 1 ) ;
break;
case V_57 :
F_42 ( & V_2 -> V_6 -> V_7 , L_7 ) ;
F_45 ( V_2 , 0 ) ;
break;
case V_59 :
case V_87 :
F_28 ( V_2 , V_54 ) ;
break;
default:
break;
}
}
static int F_49 ( unsigned long V_46 ,
struct V_77 * V_55 )
{
struct V_1 * V_2 = F_44 ( V_55 ) ;
F_50 ( V_55 -> V_56 != V_57 ) ;
if ( F_51 ( V_2 -> V_27 & V_53 ) )
V_2 -> V_39 = V_46 - 1 ;
else
F_25 ( V_2 , V_46 - 1 ) ;
return 0 ;
}
static void F_52 ( struct V_77 * V_55 )
{
F_37 ( & F_44 ( V_55 ) -> V_6 -> V_7 ) ;
}
static void F_53 ( struct V_77 * V_55 )
{
F_39 ( & F_44 ( V_55 ) -> V_6 -> V_7 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
char * V_68 , unsigned long V_69 )
{
struct V_77 * V_55 = & V_2 -> V_55 ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
V_55 -> V_68 = V_68 ;
V_55 -> V_88 = V_89 ;
V_55 -> V_88 |= V_90 ;
V_55 -> V_69 = V_69 ;
V_55 -> V_91 = F_55 ( 0 ) ;
V_55 -> V_92 = F_49 ;
V_55 -> V_93 = F_48 ;
V_55 -> V_73 = F_52 ;
V_55 -> V_74 = F_53 ;
F_42 ( & V_2 -> V_6 -> V_7 , L_8 ) ;
F_56 ( V_55 ) ;
}
static int F_57 ( struct V_1 * V_2 , char * V_68 ,
unsigned long V_94 ,
unsigned long V_95 )
{
if ( V_2 -> V_14 == ( sizeof( V_2 -> V_44 ) * 8 ) )
V_2 -> V_44 = ~ 0 ;
else
V_2 -> V_44 = ( 1 << V_2 -> V_14 ) - 1 ;
V_2 -> V_45 = V_2 -> V_44 ;
F_58 ( & V_2 -> V_47 ) ;
if ( V_94 )
F_54 ( V_2 , V_68 , V_94 ) ;
if ( V_95 )
F_40 ( V_2 , V_68 , V_95 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_96 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_97 * V_98 ;
int V_48 , V_32 ;
V_32 = - V_99 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = V_6 ;
if ( ! V_5 ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
goto V_34;
}
F_60 ( V_6 , V_2 ) ;
V_98 = F_61 ( V_2 -> V_6 , V_100 , 0 ) ;
if ( ! V_98 ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
goto V_34;
}
V_48 = F_62 ( V_2 -> V_6 , 0 ) ;
if ( V_48 < 0 ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_11 ) ;
goto V_34;
}
V_2 -> V_10 = F_63 ( V_98 -> V_26 , F_64 ( V_98 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_12 ) ;
goto V_34;
}
V_2 -> V_101 . V_68 = F_65 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_101 . V_102 = F_26 ;
V_2 -> V_101 . V_49 = V_2 ;
V_2 -> V_101 . V_27 = V_103 | V_104 | \
V_105 | V_106 ;
V_2 -> V_33 = F_66 ( & V_2 -> V_6 -> V_7 , L_13 ) ;
if ( F_67 ( V_2 -> V_33 ) ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_14 ) ;
V_32 = F_68 ( V_2 -> V_33 ) ;
goto V_36;
}
if ( F_64 ( V_98 ) == 6 ) {
V_2 -> V_14 = 16 ;
V_2 -> V_25 = 0x80 ;
V_2 -> V_50 = ~ 0x80 ;
} else {
V_2 -> V_14 = 32 ;
V_2 -> V_25 = 0x8000 ;
V_2 -> V_50 = ~ 0xc000 ;
}
V_32 = F_57 ( V_2 , ( char * ) F_65 ( & V_2 -> V_6 -> V_7 ) ,
V_5 -> V_94 ,
V_5 -> V_95 ) ;
if ( V_32 ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_15 ) ;
goto V_36;
}
V_2 -> V_67 = false ;
V_32 = F_69 ( V_48 , & V_2 -> V_101 ) ;
if ( V_32 ) {
F_16 ( & V_2 -> V_6 -> V_7 , L_16 , V_48 ) ;
goto V_36;
}
return 0 ;
V_36:
F_70 ( V_2 -> V_10 ) ;
V_34:
return V_32 ;
}
static int T_4 F_71 ( struct V_96 * V_6 )
{
struct V_1 * V_2 = F_72 ( V_6 ) ;
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
int V_32 ;
if ( ! F_73 ( V_6 ) ) {
F_74 ( & V_6 -> V_7 ) ;
F_75 ( & V_6 -> V_7 ) ;
}
if ( V_2 ) {
F_42 ( & V_6 -> V_7 , L_17 ) ;
goto V_62;
}
V_2 = F_76 ( sizeof( * V_2 ) , V_107 ) ;
if ( V_2 == NULL ) {
F_16 ( & V_6 -> V_7 , L_18 ) ;
return - V_108 ;
}
V_32 = F_59 ( V_2 , V_6 ) ;
if ( V_32 ) {
F_77 ( V_2 ) ;
F_60 ( V_6 , NULL ) ;
F_78 ( & V_6 -> V_7 ) ;
return V_32 ;
}
if ( F_73 ( V_6 ) )
return 0 ;
V_62:
if ( V_5 -> V_94 || V_5 -> V_95 )
F_79 ( & V_6 -> V_7 ) ;
else
F_78 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int T_5 F_80 ( struct V_96 * V_6 )
{
return - V_109 ;
}
static int T_6 F_81 ( void )
{
return F_82 ( & V_110 ) ;
}
static void T_7 F_83 ( void )
{
F_84 ( & V_110 ) ;
}
