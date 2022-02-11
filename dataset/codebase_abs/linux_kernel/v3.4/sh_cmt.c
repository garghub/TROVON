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
V_32 = F_13 ( V_2 -> V_33 ) ;
if ( V_32 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
goto V_34;
}
F_9 ( V_2 , 0 ) ;
if ( V_2 -> V_14 == 16 ) {
* V_30 = F_15 ( V_2 -> V_33 ) / 512 ;
F_4 ( V_2 , V_24 , 0x43 ) ;
} else {
* V_30 = F_15 ( V_2 -> V_33 ) / 8 ;
F_4 ( V_2 , V_24 , 0x01a4 ) ;
}
F_4 ( V_2 , V_16 , 0xffffffff ) ;
F_4 ( V_2 , V_15 , 0 ) ;
for ( V_31 = 0 ; V_31 < 100 ; V_31 ++ ) {
if ( ! F_1 ( V_2 , V_15 ) )
break;
F_16 ( 1 ) ;
}
if ( F_1 ( V_2 , V_15 ) ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
V_32 = - V_35 ;
goto V_36;
}
F_9 ( V_2 , 1 ) ;
return 0 ;
V_36:
F_17 ( V_2 -> V_33 ) ;
V_34:
return V_32 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_4 ( V_2 , V_24 , 0 ) ;
F_17 ( V_2 -> V_33 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
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
F_20 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
} while ( V_40 );
}
static void F_21 ( struct V_1 * V_2 , unsigned long V_46 )
{
if ( V_46 > V_2 -> V_44 )
F_20 ( & V_2 -> V_6 -> V_7 , L_4 ) ;
V_2 -> V_39 = V_46 ;
F_19 ( V_2 , 0 ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned long V_46 )
{
unsigned long V_27 ;
F_10 ( & V_2 -> V_47 , V_27 ) ;
F_21 ( V_2 , V_46 ) ;
F_11 ( & V_2 -> V_47 , V_27 ) ;
}
static T_2 F_23 ( int V_48 , void * V_49 )
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
F_19 ( V_2 , 1 ) ;
if ( V_2 -> V_27 & V_54 )
if ( ( V_2 -> V_55 . V_56 == V_59 )
|| ( V_2 -> V_45 == V_2 -> V_39 ) )
V_2 -> V_27 &= ~ V_42 ;
}
V_2 -> V_27 &= ~ V_53 ;
return V_60 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_61 )
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
F_21 ( V_2 , V_2 -> V_44 ) ;
V_62:
F_11 ( & V_2 -> V_47 , V_27 ) ;
return V_32 ;
}
static void F_25 ( struct V_1 * V_2 , unsigned long V_61 )
{
unsigned long V_27 ;
unsigned long V_63 ;
F_10 ( & V_2 -> V_47 , V_27 ) ;
V_63 = V_2 -> V_27 & ( V_54 | V_51 ) ;
V_2 -> V_27 &= ~ V_61 ;
if ( V_63 && ! ( V_2 -> V_27 & ( V_54 | V_51 ) ) )
F_18 ( V_2 ) ;
if ( ( V_61 == V_54 ) && ( V_2 -> V_27 & V_51 ) )
F_21 ( V_2 , V_2 -> V_44 ) ;
F_11 ( & V_2 -> V_47 , V_27 ) ;
}
static struct V_1 * F_26 ( struct V_64 * V_65 )
{
return F_27 ( V_65 , struct V_1 , V_65 ) ;
}
static T_3 F_28 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_26 ( V_65 ) ;
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
static int F_29 ( struct V_64 * V_65 )
{
int V_32 ;
struct V_1 * V_2 = F_26 ( V_65 ) ;
V_2 -> V_52 = 0 ;
V_32 = F_24 ( V_2 , V_51 ) ;
if ( ! V_32 )
F_30 ( V_65 , V_2 -> V_30 ) ;
return V_32 ;
}
static void F_31 ( struct V_64 * V_65 )
{
F_25 ( F_26 ( V_65 ) , V_51 ) ;
}
static void F_32 ( struct V_64 * V_65 )
{
F_24 ( F_26 ( V_65 ) , V_51 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
char * V_67 , unsigned long V_68 )
{
struct V_64 * V_65 = & V_2 -> V_65 ;
V_65 -> V_67 = V_67 ;
V_65 -> V_68 = V_68 ;
V_65 -> V_69 = F_28 ;
V_65 -> V_70 = F_29 ;
V_65 -> V_71 = F_31 ;
V_65 -> V_72 = F_31 ;
V_65 -> V_73 = F_32 ;
V_65 -> V_74 = F_34 ( sizeof( unsigned long ) * 8 ) ;
V_65 -> V_27 = V_75 ;
F_35 ( & V_2 -> V_6 -> V_7 , L_5 ) ;
F_36 ( V_65 , 1 ) ;
return 0 ;
}
static struct V_1 * F_37 ( struct V_76 * V_55 )
{
return F_27 ( V_55 , struct V_1 , V_55 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_77 )
{
struct V_76 * V_55 = & V_2 -> V_55 ;
F_24 ( V_2 , V_54 ) ;
V_55 -> V_78 = 32 ;
V_55 -> V_79 = F_39 ( V_2 -> V_30 , V_80 , V_55 -> V_78 ) ;
V_55 -> V_81 = F_40 ( V_2 -> V_44 , V_55 ) ;
V_55 -> V_82 = F_40 ( 0x1f , V_55 ) ;
if ( V_77 )
F_22 ( V_2 , ( ( V_2 -> V_30 + V_83 / 2 ) / V_83 ) - 1 ) ;
else
F_22 ( V_2 , V_2 -> V_44 ) ;
}
static void F_41 ( enum V_84 V_56 ,
struct V_76 * V_55 )
{
struct V_1 * V_2 = F_37 ( V_55 ) ;
switch ( V_55 -> V_56 ) {
case V_85 :
case V_57 :
F_25 ( V_2 , V_54 ) ;
break;
default:
break;
}
switch ( V_56 ) {
case V_85 :
F_35 ( & V_2 -> V_6 -> V_7 , L_6 ) ;
F_38 ( V_2 , 1 ) ;
break;
case V_57 :
F_35 ( & V_2 -> V_6 -> V_7 , L_7 ) ;
F_38 ( V_2 , 0 ) ;
break;
case V_59 :
case V_86 :
F_25 ( V_2 , V_54 ) ;
break;
default:
break;
}
}
static int F_42 ( unsigned long V_46 ,
struct V_76 * V_55 )
{
struct V_1 * V_2 = F_37 ( V_55 ) ;
F_43 ( V_55 -> V_56 != V_57 ) ;
if ( F_44 ( V_2 -> V_27 & V_53 ) )
V_2 -> V_39 = V_46 - 1 ;
else
F_22 ( V_2 , V_46 - 1 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
char * V_67 , unsigned long V_68 )
{
struct V_76 * V_55 = & V_2 -> V_55 ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
V_55 -> V_67 = V_67 ;
V_55 -> V_87 = V_88 ;
V_55 -> V_87 |= V_89 ;
V_55 -> V_68 = V_68 ;
V_55 -> V_90 = F_46 ( 0 ) ;
V_55 -> V_91 = F_42 ;
V_55 -> V_92 = F_41 ;
F_35 ( & V_2 -> V_6 -> V_7 , L_8 ) ;
F_47 ( V_55 ) ;
}
static int F_48 ( struct V_1 * V_2 , char * V_67 ,
unsigned long V_93 ,
unsigned long V_94 )
{
if ( V_2 -> V_14 == ( sizeof( V_2 -> V_44 ) * 8 ) )
V_2 -> V_44 = ~ 0 ;
else
V_2 -> V_44 = ( 1 << V_2 -> V_14 ) - 1 ;
V_2 -> V_45 = V_2 -> V_44 ;
F_49 ( & V_2 -> V_47 ) ;
if ( V_93 )
F_45 ( V_2 , V_67 , V_93 ) ;
if ( V_94 )
F_33 ( V_2 , V_67 , V_94 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_95 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_96 * V_97 ;
int V_48 , V_32 ;
V_32 = - V_98 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = V_6 ;
if ( ! V_5 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
goto V_34;
}
F_51 ( V_6 , V_2 ) ;
V_97 = F_52 ( V_2 -> V_6 , V_99 , 0 ) ;
if ( ! V_97 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
goto V_34;
}
V_48 = F_53 ( V_2 -> V_6 , 0 ) ;
if ( V_48 < 0 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_11 ) ;
goto V_34;
}
V_2 -> V_10 = F_54 ( V_97 -> V_26 , F_55 ( V_97 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_12 ) ;
goto V_34;
}
V_2 -> V_100 . V_67 = F_56 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_100 . V_101 = F_23 ;
V_2 -> V_100 . V_49 = V_2 ;
V_2 -> V_100 . V_27 = V_102 | V_103 | \
V_104 | V_105 ;
V_2 -> V_33 = F_57 ( & V_2 -> V_6 -> V_7 , L_13 ) ;
if ( F_58 ( V_2 -> V_33 ) ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_14 ) ;
V_32 = F_59 ( V_2 -> V_33 ) ;
goto V_36;
}
if ( F_55 ( V_97 ) == 6 ) {
V_2 -> V_14 = 16 ;
V_2 -> V_25 = 0x80 ;
V_2 -> V_50 = ~ 0x80 ;
} else {
V_2 -> V_14 = 32 ;
V_2 -> V_25 = 0x8000 ;
V_2 -> V_50 = ~ 0xc000 ;
}
V_32 = F_48 ( V_2 , ( char * ) F_56 ( & V_2 -> V_6 -> V_7 ) ,
V_5 -> V_93 ,
V_5 -> V_94 ) ;
if ( V_32 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_15 ) ;
goto V_36;
}
V_32 = F_60 ( V_48 , & V_2 -> V_100 ) ;
if ( V_32 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_16 , V_48 ) ;
goto V_36;
}
return 0 ;
V_36:
F_61 ( V_2 -> V_10 ) ;
V_34:
return V_32 ;
}
static int T_4 F_62 ( struct V_95 * V_6 )
{
struct V_1 * V_2 = F_63 ( V_6 ) ;
int V_32 ;
if ( ! F_64 ( V_6 ) )
F_65 ( & V_6 -> V_7 , true ) ;
if ( V_2 ) {
F_35 ( & V_6 -> V_7 , L_17 ) ;
return 0 ;
}
V_2 = F_66 ( sizeof( * V_2 ) , V_106 ) ;
if ( V_2 == NULL ) {
F_14 ( & V_6 -> V_7 , L_18 ) ;
return - V_107 ;
}
V_32 = F_50 ( V_2 , V_6 ) ;
if ( V_32 ) {
F_67 ( V_2 ) ;
F_51 ( V_6 , NULL ) ;
}
return V_32 ;
}
static int T_5 F_68 ( struct V_95 * V_6 )
{
return - V_108 ;
}
static int T_6 F_69 ( void )
{
return F_70 ( & V_109 ) ;
}
static void T_7 F_71 ( void )
{
F_72 ( & V_109 ) ;
}
