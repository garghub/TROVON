static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 &&
V_2 -> V_5 < 0x40 ;
}
static void F_2 ( void )
{
T_1 V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
V_6 = F_4 ( F_5 ( V_9 ) ) ;
V_6 |= V_10 ;
F_6 ( V_6 , F_5 ( V_9 ) ) ;
F_7 ( & V_8 , V_7 ) ;
}
static void F_8 ( void )
{
T_1 V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
V_6 = F_4 ( F_5 ( V_9 ) ) ;
V_6 &= ~ V_10 ;
F_6 ( V_6 , F_5 ( V_9 ) ) ;
F_7 ( & V_8 , V_7 ) ;
}
static void F_9 ( void )
{
T_1 V_6 ;
unsigned long V_7 ;
F_3 ( & V_8 , V_7 ) ;
V_6 = F_4 ( F_5 ( V_9 ) ) ;
V_6 |= V_11 ;
F_6 ( V_6 , F_5 ( V_9 ) ) ;
F_7 ( & V_8 , V_7 ) ;
}
static int F_10 ( int V_12 )
{
unsigned long V_7 ;
if ( V_12 < 0 || V_12 > 0xffff )
return - V_13 ;
F_3 ( & V_8 , V_7 ) ;
F_6 ( V_12 , F_11 ( V_9 ) ) ;
F_7 ( & V_8 , V_7 ) ;
V_14 = V_12 ;
return 0 ;
}
static void F_12 ( void )
{
int V_6 ;
if ( ! F_1 ( V_15 ) ) {
F_13 ( V_16 , V_17 ) ;
V_6 = F_14 ( V_18 ) ;
V_6 |= V_19 ;
F_13 ( V_6 , V_18 ) ;
F_13 ( V_20 , V_17 ) ;
V_6 = F_14 ( V_18 ) ;
V_6 |= V_21 ;
V_6 &= ~ V_22 ;
F_13 ( V_6 , V_18 ) ;
} else {
F_15 ( V_15 ,
V_23 ,
& V_6 ) ;
V_6 |= V_24 ;
F_16 ( V_15 ,
V_23 ,
V_6 ) ;
F_13 ( V_25 , V_26 ) ;
V_6 = F_14 ( V_27 ) ;
V_6 |= V_28 ;
V_6 &= ~ V_29 ;
F_13 ( V_6 , V_27 ) ;
}
}
static int F_17 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
if ( F_18 ( 0 , & V_32 ) )
return - V_33 ;
F_2 () ;
F_9 () ;
return F_19 ( V_30 , V_31 ) ;
}
static int F_20 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
if ( V_34 == 42 ) {
F_8 () ;
} else {
F_21 ( L_1 ) ;
F_9 () ;
}
F_22 ( 0 , & V_32 ) ;
V_34 = 0 ;
return 0 ;
}
static T_2 F_23 ( struct V_31 * V_31 , const char T_3 * V_35 ,
T_4 V_36 , T_5 * V_37 )
{
if ( V_36 ) {
if ( ! V_38 ) {
T_4 V_39 ;
V_34 = 0 ;
for ( V_39 = 0 ; V_39 != V_36 ; V_39 ++ ) {
char V_40 ;
if ( F_24 ( V_40 , V_35 + V_39 ) )
return - V_41 ;
if ( V_40 == 'V' )
V_34 = 42 ;
}
}
F_9 () ;
}
return V_36 ;
}
static long F_25 ( struct V_31 * V_31 , unsigned int V_42 ,
unsigned long V_43 )
{
int V_44 , V_45 = - V_13 ;
int V_46 ;
void T_3 * V_47 = ( void T_3 * ) V_43 ;
int T_3 * V_48 = V_47 ;
static const struct V_49 V_50 = {
. V_51 = V_52 |
V_53 |
V_54 ,
. V_55 = 0 ,
. V_56 = V_57 ,
} ;
switch ( V_42 ) {
case V_58 :
return F_26 ( V_47 , & V_50 ,
sizeof( V_50 ) ) ? - V_41 : 0 ;
case V_59 :
case V_60 :
return F_27 ( 0 , V_48 ) ;
case V_61 :
if ( F_24 ( V_44 , V_48 ) )
return - V_41 ;
if ( V_44 & V_62 ) {
F_8 () ;
V_45 = 0 ;
}
if ( V_44 & V_63 ) {
F_2 () ;
F_9 () ;
V_45 = 0 ;
}
return V_45 ;
case V_64 :
F_9 () ;
return 0 ;
case V_65 :
if ( F_24 ( V_46 , V_48 ) )
return - V_41 ;
if ( F_10 ( V_46 ) )
return - V_13 ;
F_9 () ;
case V_66 :
return F_27 ( V_14 , V_48 ) ;
default:
return - V_67 ;
}
}
static unsigned char F_28 ( void )
{
struct V_1 * V_2 = NULL ;
const char * V_68 = NULL ;
T_1 V_6 ;
T_1 V_69 , V_70 , V_71 ;
F_29 (dev) {
if ( F_30 ( V_72 , V_2 ) != NULL ) {
V_15 = V_2 ;
break;
}
}
if ( ! V_15 )
return 0 ;
F_31 ( L_2 ,
V_15 -> V_73 , V_15 -> V_3 ,
V_15 -> V_5 ) ;
if ( F_1 ( V_15 ) ) {
V_68 = V_74 ;
V_69 = V_26 ;
V_70 = V_27 ;
V_71 = V_75 ;
} else {
V_68 = V_76 ;
V_69 = V_17 ;
V_70 = V_18 ;
V_71 = V_77 ;
}
V_78 = V_26 ;
if ( ! F_32 ( V_78 , V_79 , V_68 ) ) {
F_33 ( L_3 , V_78 ) ;
goto exit;
}
F_13 ( V_71 + 3 , V_69 ) ;
V_6 = F_14 ( V_70 ) ;
F_13 ( V_71 + 2 , V_69 ) ;
V_6 = V_6 << 8 | F_14 ( V_70 ) ;
F_13 ( V_71 + 1 , V_69 ) ;
V_6 = V_6 << 8 | F_14 ( V_70 ) ;
F_13 ( V_71 + 0 , V_69 ) ;
V_6 = V_6 << 8 | ( F_14 ( V_70 ) & 0xf8 ) ;
F_34 ( L_4 , V_6 ) ;
if ( F_35 ( V_6 , V_80 ,
V_68 ) )
goto V_81;
else
F_34 ( L_5 , V_6 ) ;
if ( F_1 ( V_15 ) ) {
F_15 ( V_15 ,
V_82 , & V_6 ) ;
} else {
F_13 ( V_83 + 3 , V_17 ) ;
V_6 = F_14 ( V_18 ) ;
F_13 ( V_83 + 2 , V_17 ) ;
V_6 = V_6 << 8 | F_14 ( V_18 ) ;
F_13 ( V_83 + 1 , V_17 ) ;
V_6 = V_6 << 8 | F_14 ( V_18 ) ;
F_13 ( V_83 + 0 , V_17 ) ;
V_6 = V_6 << 8 | F_14 ( V_18 ) ;
}
if ( ( V_6 & ( V_84 | V_85 ) ) ==
V_84 ) {
V_6 &= ~ 0xFFF ;
V_6 += V_86 ;
if ( F_35 ( V_6 , V_80 ,
V_68 ) ) {
F_34 ( L_6 ,
V_6 ) ;
goto V_81;
} else
F_34 ( L_5 , V_6 ) ;
} else
F_34 ( L_7 , V_6 ) ;
F_36 ( L_8 ) ;
goto V_87;
V_81:
V_88 = V_6 ;
V_9 = F_37 ( V_6 , V_80 ) ;
if ( ! V_9 ) {
F_33 ( L_9 ) ;
goto V_89;
}
F_31 ( L_10 , V_6 ) ;
F_12 () ;
V_6 = F_4 ( F_5 ( V_9 ) ) ;
V_90 = V_6 & V_91 ;
V_6 &= ~ V_92 ;
F_6 ( V_6 , F_5 ( V_9 ) ) ;
F_10 ( V_14 ) ;
F_8 () ;
return 1 ;
V_89:
F_38 ( V_88 , V_80 ) ;
V_87:
F_39 ( V_78 , V_79 ) ;
exit:
return 0 ;
}
static int F_40 ( struct V_93 * V_2 )
{
int V_94 ;
if ( ! F_28 () )
return - V_95 ;
F_31 ( L_11 ,
V_90 ? L_12 : L_13 ) ;
if ( F_10 ( V_14 ) ) {
V_14 = V_96 ;
F_10 ( V_14 ) ;
}
V_94 = F_41 ( & V_97 ) ;
if ( V_94 != 0 ) {
F_33 ( L_14 ,
V_98 , V_94 ) ;
goto exit;
}
F_22 ( 0 , & V_32 ) ;
F_31 ( L_15 ,
V_9 , V_14 , V_38 ) ;
return 0 ;
exit:
F_42 ( V_9 ) ;
F_38 ( V_88 , V_80 ) ;
F_39 ( V_78 , V_79 ) ;
return V_94 ;
}
static void F_43 ( void )
{
if ( ! V_38 )
F_8 () ;
F_44 ( & V_97 ) ;
F_42 ( V_9 ) ;
F_38 ( V_88 , V_80 ) ;
F_39 ( V_78 , V_79 ) ;
}
static int F_45 ( struct V_93 * V_2 )
{
if ( V_9 )
F_43 () ;
return 0 ;
}
static void F_46 ( struct V_93 * V_2 )
{
F_8 () ;
}
static int T_6 F_47 ( void )
{
int V_99 ;
F_31 ( L_16 , V_100 ) ;
V_99 = F_48 ( & V_101 ) ;
if ( V_99 )
return V_99 ;
V_102 = F_49 (
V_57 , - 1 , NULL , 0 ) ;
if ( F_50 ( V_102 ) ) {
V_99 = F_51 ( V_102 ) ;
goto V_103;
}
return 0 ;
V_103:
F_52 ( & V_101 ) ;
return V_99 ;
}
static void T_7 F_53 ( void )
{
F_54 ( V_102 ) ;
F_52 ( & V_101 ) ;
F_31 ( L_17 ) ;
}
