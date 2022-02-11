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
int V_31 ;
V_31 = F_13 ( V_2 -> V_32 ) ;
if ( V_31 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return V_31 ;
}
F_9 ( V_2 , 0 ) ;
if ( V_2 -> V_14 == 16 ) {
* V_30 = F_15 ( V_2 -> V_32 ) / 512 ;
F_4 ( V_2 , V_24 , 0x43 ) ;
} else {
* V_30 = F_15 ( V_2 -> V_32 ) / 8 ;
F_4 ( V_2 , V_24 , 0x01a4 ) ;
}
F_4 ( V_2 , V_16 , 0xffffffff ) ;
F_4 ( V_2 , V_15 , 0 ) ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 0 ) ;
F_4 ( V_2 , V_24 , 0 ) ;
F_17 ( V_2 -> V_32 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
int V_33 )
{
unsigned long V_34 ;
unsigned long V_17 = V_2 -> V_35 ;
unsigned long V_36 = 0 ;
unsigned long V_37 = 0 ;
int V_18 ;
V_37 = F_7 ( V_2 , & V_18 ) ;
V_2 -> V_27 |= V_38 ;
if ( V_18 ) {
V_2 -> V_27 |= V_39 ;
return;
}
if ( V_33 )
V_37 = 0 ;
do {
V_34 = V_37 + V_17 + V_36 ;
if ( V_34 > V_2 -> V_40 )
V_34 = V_2 -> V_40 ;
F_4 ( V_2 , V_16 , V_34 ) ;
V_37 = F_7 ( V_2 , & V_18 ) ;
if ( V_18 && ( V_34 > V_2 -> V_41 ) ) {
V_2 -> V_27 |= V_39 ;
break;
}
if ( V_18 ) {
V_2 -> V_41 = V_34 ;
break;
}
if ( V_37 < V_34 ) {
V_2 -> V_41 = V_34 ;
break;
}
if ( V_36 )
V_36 <<= 1 ;
else
V_36 = 1 ;
if ( ! V_36 )
F_19 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
} while ( V_36 );
}
static void F_20 ( struct V_1 * V_2 , unsigned long V_42 )
{
if ( V_42 > V_2 -> V_40 )
F_19 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
V_2 -> V_35 = V_42 ;
F_18 ( V_2 , 0 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned long V_42 )
{
unsigned long V_27 ;
F_10 ( & V_2 -> V_43 , V_27 ) ;
F_20 ( V_2 , V_42 ) ;
F_11 ( & V_2 -> V_43 , V_27 ) ;
}
static T_2 F_22 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
F_4 ( V_2 , V_24 , F_1 ( V_2 , V_24 ) & V_2 -> V_46 ) ;
if ( V_2 -> V_27 & V_47 )
V_2 -> V_48 += V_2 -> V_41 + 1 ;
if ( ! ( V_2 -> V_27 & V_38 ) )
V_2 -> V_35 = V_2 -> V_40 ;
V_2 -> V_27 |= V_49 ;
if ( V_2 -> V_27 & V_50 ) {
if ( ! ( V_2 -> V_27 & V_39 ) ) {
if ( V_2 -> V_51 . V_52 == V_53 ) {
V_2 -> V_35 = V_2 -> V_40 ;
V_2 -> V_27 |= V_38 ;
}
V_2 -> V_51 . V_54 ( & V_2 -> V_51 ) ;
}
}
V_2 -> V_27 &= ~ V_39 ;
if ( V_2 -> V_27 & V_38 ) {
V_2 -> V_27 &= ~ V_38 ;
F_18 ( V_2 , 1 ) ;
if ( V_2 -> V_27 & V_50 )
if ( ( V_2 -> V_51 . V_52 == V_55 )
|| ( V_2 -> V_41 == V_2 -> V_35 ) )
V_2 -> V_27 &= ~ V_38 ;
}
V_2 -> V_27 &= ~ V_49 ;
return V_56 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned long V_57 )
{
int V_31 = 0 ;
unsigned long V_27 ;
F_10 ( & V_2 -> V_43 , V_27 ) ;
if ( ! ( V_2 -> V_27 & ( V_50 | V_47 ) ) )
V_31 = F_12 ( V_2 , & V_2 -> V_30 ) ;
if ( V_31 )
goto V_58;
V_2 -> V_27 |= V_57 ;
if ( ( V_57 == V_47 ) && ( ! ( V_2 -> V_27 & V_50 ) ) )
F_20 ( V_2 , V_2 -> V_40 ) ;
V_58:
F_11 ( & V_2 -> V_43 , V_27 ) ;
return V_31 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned long V_57 )
{
unsigned long V_27 ;
unsigned long V_59 ;
F_10 ( & V_2 -> V_43 , V_27 ) ;
V_59 = V_2 -> V_27 & ( V_50 | V_47 ) ;
V_2 -> V_27 &= ~ V_57 ;
if ( V_59 && ! ( V_2 -> V_27 & ( V_50 | V_47 ) ) )
F_16 ( V_2 ) ;
if ( ( V_57 == V_50 ) && ( V_2 -> V_27 & V_47 ) )
F_20 ( V_2 , V_2 -> V_40 ) ;
F_11 ( & V_2 -> V_43 , V_27 ) ;
}
static struct V_1 * F_25 ( struct V_60 * V_61 )
{
return F_26 ( V_61 , struct V_1 , V_61 ) ;
}
static T_3 F_27 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_25 ( V_61 ) ;
unsigned long V_27 , V_62 ;
unsigned long V_17 ;
int V_18 ;
F_10 ( & V_2 -> V_43 , V_27 ) ;
V_17 = V_2 -> V_48 ;
V_62 = F_7 ( V_2 , & V_18 ) ;
if ( F_8 ( V_18 ) )
V_62 += V_2 -> V_41 + 1 ;
F_11 ( & V_2 -> V_43 , V_27 ) ;
return V_17 + V_62 ;
}
static int F_28 ( struct V_60 * V_61 )
{
int V_31 ;
struct V_1 * V_2 = F_25 ( V_61 ) ;
V_2 -> V_48 = 0 ;
V_31 = F_23 ( V_2 , V_47 ) ;
if ( ! V_31 )
F_29 ( V_61 , V_2 -> V_30 ) ;
return V_31 ;
}
static void F_30 ( struct V_60 * V_61 )
{
F_24 ( F_25 ( V_61 ) , V_47 ) ;
}
static void F_31 ( struct V_60 * V_61 )
{
F_23 ( F_25 ( V_61 ) , V_47 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
char * V_63 , unsigned long V_64 )
{
struct V_60 * V_61 = & V_2 -> V_61 ;
V_61 -> V_63 = V_63 ;
V_61 -> V_64 = V_64 ;
V_61 -> V_65 = F_27 ;
V_61 -> V_66 = F_28 ;
V_61 -> V_67 = F_30 ;
V_61 -> V_68 = F_30 ;
V_61 -> V_69 = F_31 ;
V_61 -> V_70 = F_33 ( sizeof( unsigned long ) * 8 ) ;
V_61 -> V_27 = V_71 ;
F_34 ( & V_2 -> V_6 -> V_7 , L_4 ) ;
F_35 ( V_61 , 1 ) ;
return 0 ;
}
static struct V_1 * F_36 ( struct V_72 * V_51 )
{
return F_26 ( V_51 , struct V_1 , V_51 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_73 )
{
struct V_72 * V_51 = & V_2 -> V_51 ;
F_23 ( V_2 , V_50 ) ;
V_51 -> V_74 = 32 ;
V_51 -> V_75 = F_38 ( V_2 -> V_30 , V_76 , V_51 -> V_74 ) ;
V_51 -> V_77 = F_39 ( V_2 -> V_40 , V_51 ) ;
V_51 -> V_78 = F_39 ( 0x1f , V_51 ) ;
if ( V_73 )
F_21 ( V_2 , ( ( V_2 -> V_30 + V_79 / 2 ) / V_79 ) - 1 ) ;
else
F_21 ( V_2 , V_2 -> V_40 ) ;
}
static void F_40 ( enum V_80 V_52 ,
struct V_72 * V_51 )
{
struct V_1 * V_2 = F_36 ( V_51 ) ;
switch ( V_51 -> V_52 ) {
case V_81 :
case V_53 :
F_24 ( V_2 , V_50 ) ;
break;
default:
break;
}
switch ( V_52 ) {
case V_81 :
F_34 ( & V_2 -> V_6 -> V_7 , L_5 ) ;
F_37 ( V_2 , 1 ) ;
break;
case V_53 :
F_34 ( & V_2 -> V_6 -> V_7 , L_6 ) ;
F_37 ( V_2 , 0 ) ;
break;
case V_55 :
case V_82 :
F_24 ( V_2 , V_50 ) ;
break;
default:
break;
}
}
static int F_41 ( unsigned long V_42 ,
struct V_72 * V_51 )
{
struct V_1 * V_2 = F_36 ( V_51 ) ;
F_42 ( V_51 -> V_52 != V_53 ) ;
if ( F_43 ( V_2 -> V_27 & V_49 ) )
V_2 -> V_35 = V_42 - 1 ;
else
F_21 ( V_2 , V_42 - 1 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
char * V_63 , unsigned long V_64 )
{
struct V_72 * V_51 = & V_2 -> V_51 ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_63 = V_63 ;
V_51 -> V_83 = V_84 ;
V_51 -> V_83 |= V_85 ;
V_51 -> V_64 = V_64 ;
V_51 -> V_86 = F_45 ( 0 ) ;
V_51 -> V_87 = F_41 ;
V_51 -> V_88 = F_40 ;
F_34 ( & V_2 -> V_6 -> V_7 , L_7 ) ;
F_46 ( V_51 ) ;
}
static int F_47 ( struct V_1 * V_2 , char * V_63 ,
unsigned long V_89 ,
unsigned long V_90 )
{
if ( V_2 -> V_14 == ( sizeof( V_2 -> V_40 ) * 8 ) )
V_2 -> V_40 = ~ 0 ;
else
V_2 -> V_40 = ( 1 << V_2 -> V_14 ) - 1 ;
V_2 -> V_41 = V_2 -> V_40 ;
F_48 ( & V_2 -> V_43 ) ;
if ( V_89 )
F_44 ( V_2 , V_63 , V_89 ) ;
if ( V_90 )
F_32 ( V_2 , V_63 , V_90 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_91 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_92 * V_93 ;
int V_44 , V_31 ;
V_31 = - V_94 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_6 = V_6 ;
if ( ! V_5 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_8 ) ;
goto V_95;
}
F_50 ( V_6 , V_2 ) ;
V_93 = F_51 ( V_2 -> V_6 , V_96 , 0 ) ;
if ( ! V_93 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_9 ) ;
goto V_95;
}
V_44 = F_52 ( V_2 -> V_6 , 0 ) ;
if ( V_44 < 0 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_10 ) ;
goto V_95;
}
V_2 -> V_10 = F_53 ( V_93 -> V_26 , F_54 ( V_93 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_11 ) ;
goto V_95;
}
V_2 -> V_97 . V_63 = F_55 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_97 . V_98 = F_22 ;
V_2 -> V_97 . V_45 = V_2 ;
V_2 -> V_97 . V_27 = V_99 | V_100 | \
V_101 | V_102 ;
V_2 -> V_32 = F_56 ( & V_2 -> V_6 -> V_7 , L_12 ) ;
if ( F_57 ( V_2 -> V_32 ) ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_13 ) ;
V_31 = F_58 ( V_2 -> V_32 ) ;
goto V_103;
}
if ( F_54 ( V_93 ) == 6 ) {
V_2 -> V_14 = 16 ;
V_2 -> V_25 = 0x80 ;
V_2 -> V_46 = ~ 0x80 ;
} else {
V_2 -> V_14 = 32 ;
V_2 -> V_25 = 0x8000 ;
V_2 -> V_46 = ~ 0xc000 ;
}
V_31 = F_47 ( V_2 , ( char * ) F_55 ( & V_2 -> V_6 -> V_7 ) ,
V_5 -> V_89 ,
V_5 -> V_90 ) ;
if ( V_31 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_14 ) ;
goto V_103;
}
V_31 = F_59 ( V_44 , & V_2 -> V_97 ) ;
if ( V_31 ) {
F_14 ( & V_2 -> V_6 -> V_7 , L_15 , V_44 ) ;
goto V_103;
}
return 0 ;
V_103:
F_60 ( V_2 -> V_10 ) ;
V_95:
return V_31 ;
}
static int T_4 F_61 ( struct V_91 * V_6 )
{
struct V_1 * V_2 = F_62 ( V_6 ) ;
int V_31 ;
if ( V_2 ) {
F_34 ( & V_6 -> V_7 , L_16 ) ;
return 0 ;
}
V_2 = F_63 ( sizeof( * V_2 ) , V_104 ) ;
if ( V_2 == NULL ) {
F_14 ( & V_6 -> V_7 , L_17 ) ;
return - V_105 ;
}
V_31 = F_49 ( V_2 , V_6 ) ;
if ( V_31 ) {
F_64 ( V_2 ) ;
F_50 ( V_6 , NULL ) ;
}
return V_31 ;
}
static int T_5 F_65 ( struct V_91 * V_6 )
{
return - V_106 ;
}
static int T_6 F_66 ( void )
{
return F_67 ( & V_107 ) ;
}
static void T_7 F_68 ( void )
{
F_69 ( & V_107 ) ;
}
