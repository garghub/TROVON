static void F_1 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 |= V_5 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
}
static void F_7 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 &= ~ V_5 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
}
static void F_8 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 |= V_6 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
}
static int F_9 ( int V_7 )
{
unsigned long V_2 ;
if ( V_7 < 0 || V_7 > 0xffff )
return - V_8 ;
F_2 ( & V_3 , V_2 ) ;
F_5 ( V_7 , F_10 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
V_9 = V_7 ;
return 0 ;
}
static void F_11 ( void )
{
int V_1 ;
if ( V_10 -> V_11 >= 0x40 ) {
F_12 ( V_12 , V_13 ) ;
V_1 = F_13 ( V_14 ) ;
V_1 |= V_15 ;
F_12 ( V_1 , V_14 ) ;
F_12 ( V_16 , V_13 ) ;
V_1 = F_13 ( V_14 ) ;
V_1 |= V_17 ;
V_1 &= ~ V_18 ;
F_12 ( V_1 , V_14 ) ;
} else {
F_14 ( V_10 ,
V_19 ,
& V_1 ) ;
V_1 |= V_20 ;
F_15 ( V_10 ,
V_19 ,
V_1 ) ;
F_12 ( V_21 , V_22 ) ;
V_1 = F_13 ( V_23 ) ;
V_1 |= V_24 ;
V_1 &= ~ V_25 ;
F_12 ( V_1 , V_23 ) ;
}
}
static int F_16 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
if ( F_17 ( 0 , & V_28 ) )
return - V_29 ;
F_1 () ;
F_8 () ;
return F_18 ( V_26 , V_27 ) ;
}
static int F_19 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
if ( V_30 == 42 ) {
F_7 () ;
} else {
F_20 ( L_1 ) ;
F_8 () ;
}
F_21 ( 0 , & V_28 ) ;
V_30 = 0 ;
return 0 ;
}
static T_2 F_22 ( struct V_27 * V_27 , const char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
if ( V_32 ) {
if ( ! V_34 ) {
T_4 V_35 ;
V_30 = 0 ;
for ( V_35 = 0 ; V_35 != V_32 ; V_35 ++ ) {
char V_36 ;
if ( F_23 ( V_36 , V_31 + V_35 ) )
return - V_37 ;
if ( V_36 == 'V' )
V_30 = 42 ;
}
}
F_8 () ;
}
return V_32 ;
}
static long F_24 ( struct V_27 * V_27 , unsigned int V_38 ,
unsigned long V_39 )
{
int V_40 , V_41 = - V_8 ;
int V_42 ;
void T_3 * V_43 = ( void T_3 * ) V_39 ;
int T_3 * V_44 = V_43 ;
static const struct V_45 V_46 = {
. V_47 = V_48 |
V_49 |
V_50 ,
. V_51 = 0 ,
. V_52 = V_53 ,
} ;
switch ( V_38 ) {
case V_54 :
return F_25 ( V_43 , & V_46 ,
sizeof( V_46 ) ) ? - V_37 : 0 ;
case V_55 :
case V_56 :
return F_26 ( 0 , V_44 ) ;
case V_57 :
if ( F_23 ( V_40 , V_44 ) )
return - V_37 ;
if ( V_40 & V_58 ) {
F_7 () ;
V_41 = 0 ;
}
if ( V_40 & V_59 ) {
F_1 () ;
F_8 () ;
V_41 = 0 ;
}
return V_41 ;
case V_60 :
F_8 () ;
return 0 ;
case V_61 :
if ( F_23 ( V_42 , V_44 ) )
return - V_37 ;
if ( F_9 ( V_42 ) )
return - V_8 ;
F_8 () ;
case V_62 :
return F_26 ( V_9 , V_44 ) ;
default:
return - V_63 ;
}
}
static unsigned char F_27 ( void )
{
struct V_64 * V_65 = NULL ;
const char * V_66 = NULL ;
T_1 V_1 ;
T_1 V_67 , V_68 , V_69 ;
F_28 (dev) {
if ( F_29 ( V_70 , V_65 ) != NULL ) {
V_10 = V_65 ;
break;
}
}
if ( ! V_10 )
return 0 ;
F_30 ( L_2 ,
V_10 -> V_71 , V_10 -> V_72 ,
V_10 -> V_11 ) ;
if ( V_10 -> V_72 == V_73 &&
V_10 -> V_11 < 0x40 ) {
V_66 = V_74 ;
V_67 = V_22 ;
V_68 = V_23 ;
V_69 = V_75 ;
} else {
V_66 = V_76 ;
V_67 = V_13 ;
V_68 = V_14 ;
V_69 = V_77 ;
}
V_78 = V_22 ;
if ( ! F_31 ( V_78 , V_79 , V_66 ) ) {
F_32 ( L_3 , V_78 ) ;
goto exit;
}
F_12 ( V_69 + 3 , V_67 ) ;
V_1 = F_13 ( V_68 ) ;
F_12 ( V_69 + 2 , V_67 ) ;
V_1 = V_1 << 8 | F_13 ( V_68 ) ;
F_12 ( V_69 + 1 , V_67 ) ;
V_1 = V_1 << 8 | F_13 ( V_68 ) ;
F_12 ( V_69 + 0 , V_67 ) ;
V_1 = V_1 << 8 | ( F_13 ( V_68 ) & 0xf8 ) ;
F_33 ( L_4 , V_1 ) ;
if ( F_34 ( V_1 , V_80 ,
V_66 ) )
goto V_81;
else
F_33 ( L_5 , V_1 ) ;
if ( V_10 -> V_72 == V_73 &&
V_10 -> V_11 < 0x40 ) {
F_14 ( V_10 ,
V_82 , & V_1 ) ;
} else {
F_12 ( V_83 + 3 , V_13 ) ;
V_1 = F_13 ( V_14 ) ;
F_12 ( V_83 + 2 , V_13 ) ;
V_1 = V_1 << 8 | F_13 ( V_14 ) ;
F_12 ( V_83 + 1 , V_13 ) ;
V_1 = V_1 << 8 | F_13 ( V_14 ) ;
F_12 ( V_83 + 0 , V_13 ) ;
V_1 = V_1 << 8 | F_13 ( V_14 ) ;
}
if ( ( V_1 & ( V_84 | V_85 ) ) ==
V_84 ) {
V_1 &= ~ 0xFFF ;
V_1 += V_86 ;
if ( F_34 ( V_1 , V_80 ,
V_66 ) ) {
F_33 ( L_6 ,
V_1 ) ;
goto V_81;
} else
F_33 ( L_5 , V_1 ) ;
} else
F_33 ( L_7 , V_1 ) ;
F_35 ( L_8 ) ;
goto V_87;
V_81:
V_88 = V_1 ;
V_4 = F_36 ( V_1 , V_80 ) ;
if ( ! V_4 ) {
F_32 ( L_9 ) ;
goto V_89;
}
F_30 ( L_10 , V_1 ) ;
F_11 () ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_90 = V_1 & V_91 ;
V_1 &= ~ V_92 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_9 ( V_9 ) ;
F_7 () ;
return 1 ;
V_89:
F_37 ( V_88 , V_80 ) ;
V_87:
F_38 ( V_78 , V_79 ) ;
exit:
return 0 ;
}
static int F_39 ( struct V_93 * V_65 )
{
int V_94 ;
if ( ! F_27 () )
return - V_95 ;
F_30 ( L_11 ,
V_90 ? L_12 : L_13 ) ;
if ( F_9 ( V_9 ) ) {
V_9 = V_96 ;
F_9 ( V_9 ) ;
}
V_94 = F_40 ( & V_97 ) ;
if ( V_94 != 0 ) {
F_32 ( L_14 ,
V_98 , V_94 ) ;
goto exit;
}
F_21 ( 0 , & V_28 ) ;
F_30 ( L_15 ,
V_4 , V_9 , V_34 ) ;
return 0 ;
exit:
F_41 ( V_4 ) ;
F_37 ( V_88 , V_80 ) ;
F_38 ( V_78 , V_79 ) ;
return V_94 ;
}
static void F_42 ( void )
{
if ( ! V_34 )
F_7 () ;
F_43 ( & V_97 ) ;
F_41 ( V_4 ) ;
F_37 ( V_88 , V_80 ) ;
F_38 ( V_78 , V_79 ) ;
}
static int F_44 ( struct V_93 * V_65 )
{
if ( V_4 )
F_42 () ;
return 0 ;
}
static void F_45 ( struct V_93 * V_65 )
{
F_7 () ;
}
static int T_6 F_46 ( void )
{
int V_99 ;
F_30 ( L_16 , V_100 ) ;
V_99 = F_47 ( & V_101 ) ;
if ( V_99 )
return V_99 ;
V_102 = F_48 (
V_53 , - 1 , NULL , 0 ) ;
if ( F_49 ( V_102 ) ) {
V_99 = F_50 ( V_102 ) ;
goto V_103;
}
return 0 ;
V_103:
F_51 ( & V_101 ) ;
return V_99 ;
}
static void T_7 F_52 ( void )
{
F_53 ( V_102 ) ;
F_51 ( & V_101 ) ;
F_30 ( L_17 ) ;
}
