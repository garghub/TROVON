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
static void F_16 ( void )
{
int V_1 ;
if ( V_10 -> V_11 >= 0x40 ) {
F_12 ( V_16 , V_13 ) ;
V_1 = F_13 ( V_14 ) ;
V_1 |= V_17 ;
V_1 |= V_18 ;
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
V_1 |= V_25 ;
F_12 ( V_1 , V_23 ) ;
}
}
static int F_17 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
if ( F_18 ( 0 , & V_28 ) )
return - V_29 ;
F_1 () ;
F_8 () ;
return F_19 ( V_26 , V_27 ) ;
}
static int F_20 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
if ( V_30 == 42 ) {
F_7 () ;
} else {
F_21 ( L_1 ) ;
F_8 () ;
}
F_22 ( 0 , & V_28 ) ;
V_30 = 0 ;
return 0 ;
}
static T_2 F_23 ( struct V_27 * V_27 , const char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
if ( V_32 ) {
if ( ! V_34 ) {
T_4 V_35 ;
V_30 = 0 ;
for ( V_35 = 0 ; V_35 != V_32 ; V_35 ++ ) {
char V_36 ;
if ( F_24 ( V_36 , V_31 + V_35 ) )
return - V_37 ;
if ( V_36 == 'V' )
V_30 = 42 ;
}
}
F_8 () ;
}
return V_32 ;
}
static long F_25 ( struct V_27 * V_27 , unsigned int V_38 ,
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
return F_26 ( V_43 , & V_46 ,
sizeof( V_46 ) ) ? - V_37 : 0 ;
case V_55 :
case V_56 :
return F_27 ( 0 , V_44 ) ;
case V_57 :
if ( F_24 ( V_40 , V_44 ) )
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
if ( F_24 ( V_42 , V_44 ) )
return - V_37 ;
if ( F_9 ( V_42 ) )
return - V_8 ;
F_8 () ;
case V_62 :
return F_27 ( V_9 , V_44 ) ;
default:
return - V_63 ;
}
}
static unsigned char F_28 ( void )
{
struct V_64 * V_65 = NULL ;
const char * V_66 = NULL ;
T_1 V_1 ;
T_1 V_67 , V_68 , V_69 ;
F_29 (dev) {
if ( F_30 ( V_70 , V_65 ) != NULL ) {
V_10 = V_65 ;
break;
}
}
if ( ! V_10 )
return 0 ;
F_31 ( L_2 , V_10 -> V_11 ) ;
if ( V_10 -> V_11 >= 0x40 ) {
V_66 = V_71 ;
V_67 = V_13 ;
V_68 = V_14 ;
V_69 = V_72 ;
} else {
V_66 = V_73 ;
V_67 = V_22 ;
V_68 = V_23 ;
V_69 = V_74 ;
}
V_75 = V_22 ;
if ( ! F_32 ( V_75 , V_76 , V_66 ) ) {
F_33 ( L_3 , V_75 ) ;
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
F_34 ( L_4 , V_1 ) ;
if ( F_35 ( V_1 , V_77 ,
V_66 ) )
goto V_78;
else
F_34 ( L_5 , V_1 ) ;
if ( V_10 -> V_11 >= 0x40 ) {
F_12 ( V_79 + 3 , V_13 ) ;
V_1 = F_13 ( V_14 ) ;
F_12 ( V_79 + 2 , V_13 ) ;
V_1 = V_1 << 8 | F_13 ( V_14 ) ;
F_12 ( V_79 + 1 , V_13 ) ;
V_1 = V_1 << 8 | F_13 ( V_14 ) ;
F_12 ( V_79 + 0 , V_13 ) ;
V_1 = V_1 << 8 | F_13 ( V_14 ) ;
} else {
F_14 ( V_10 ,
V_80 , & V_1 ) ;
}
if ( ( V_1 & ( V_81 | V_82 ) ) ==
V_81 ) {
V_1 &= ~ 0xFFF ;
V_1 += V_83 ;
if ( F_35 ( V_1 , V_77 ,
V_66 ) ) {
F_34 ( L_6 ,
V_1 ) ;
goto V_78;
} else
F_34 ( L_5 , V_1 ) ;
} else
F_34 ( L_7 , V_1 ) ;
F_16 () ;
if ( V_84 ) {
V_84 &= ~ 0x7 ;
V_1 = V_84 ;
F_31 ( L_8 , V_1 ) ;
} else {
if ( F_36 ( & V_85 ,
& V_86 ,
V_77 ,
0xf0000000 ,
0xfffffff8 ,
0x8 ,
NULL ,
NULL ) ) {
F_33 ( L_9 ) ;
goto V_87;
}
V_1 = V_88 = V_86 . V_89 ;
F_34 ( L_10 , V_1 ) ;
}
if ( V_10 -> V_11 >= 0x40 ) {
T_6 V_90 ;
V_90 = F_13 ( V_69 ) & 0x7 ;
V_1 |= ( T_1 ) V_90 ;
}
F_12 ( V_69 + 0 , V_67 ) ;
F_12 ( ( V_1 >> 0 ) & 0xf8 , V_68 ) ;
F_12 ( V_69 + 1 , V_67 ) ;
F_12 ( ( V_1 >> 8 ) & 0xff , V_68 ) ;
F_12 ( V_69 + 2 , V_67 ) ;
F_12 ( ( V_1 >> 16 ) & 0xff , V_68 ) ;
F_12 ( V_69 + 3 , V_67 ) ;
F_12 ( ( V_1 >> 24 ) & 0xff , V_68 ) ;
if ( V_10 -> V_11 >= 0x40 )
V_1 &= ~ 0x7 ;
if ( ! F_35 ( V_1 , V_77 ,
V_66 ) ) {
F_33 ( L_5 , V_1 ) ;
goto V_91;
}
V_78:
V_92 = V_1 ;
V_4 = F_37 ( V_1 , V_77 ) ;
if ( ! V_4 ) {
F_33 ( L_11 ) ;
goto V_93;
}
F_31 ( L_12 , V_1 ) ;
F_11 () ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_94 = V_1 & V_95 ;
V_1 &= ~ V_96 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_9 ( V_9 ) ;
F_7 () ;
return 1 ;
V_93:
F_38 ( V_92 , V_77 ) ;
V_91:
if ( V_88 )
F_39 ( & V_86 ) ;
V_87:
F_40 ( V_75 , V_76 ) ;
exit:
return 0 ;
}
static int F_41 ( struct V_97 * V_65 )
{
int V_98 ;
char V_99 [ 16 ] ;
if ( ! F_28 () )
return - V_100 ;
F_31 ( L_13 ,
V_94 ? L_14 : L_15 ) ;
if ( F_9 ( V_9 ) ) {
V_9 = V_101 ;
F_9 ( V_9 ) ;
}
V_98 = F_42 ( & V_102 ) ;
if ( V_98 != 0 ) {
F_33 ( L_16 ,
V_103 , V_98 ) ;
goto exit;
}
F_22 ( 0 , & V_28 ) ;
if ( V_84 == V_92 )
sprintf ( V_99 , L_17 , V_84 ) ;
else
strcpy ( V_99 , L_18 ) ;
F_31 ( L_19
L_20 ,
V_4 , V_9 , V_34 , V_99 ) ;
return 0 ;
exit:
F_43 ( V_4 ) ;
F_38 ( V_92 , V_77 ) ;
if ( V_88 )
F_39 ( & V_86 ) ;
F_40 ( V_75 , V_76 ) ;
return V_98 ;
}
static void F_44 ( void )
{
if ( ! V_34 )
F_7 () ;
F_45 ( & V_102 ) ;
F_43 ( V_4 ) ;
F_38 ( V_92 , V_77 ) ;
if ( V_88 )
F_39 ( & V_86 ) ;
F_40 ( V_75 , V_76 ) ;
}
static int F_46 ( struct V_97 * V_65 )
{
if ( V_4 )
F_44 () ;
return 0 ;
}
static void F_47 ( struct V_97 * V_65 )
{
F_7 () ;
}
static int T_7 F_48 ( void )
{
int V_104 ;
F_31 ( L_21 , V_105 ) ;
V_104 = F_49 ( & V_106 ) ;
if ( V_104 )
return V_104 ;
V_107 = F_50 (
V_53 , - 1 , NULL , 0 ) ;
if ( F_51 ( V_107 ) ) {
V_104 = F_52 ( V_107 ) ;
goto V_108;
}
return 0 ;
V_108:
F_53 ( & V_106 ) ;
return V_104 ;
}
static void T_8 F_54 ( void )
{
F_55 ( V_107 ) ;
F_53 ( & V_106 ) ;
F_31 ( L_22 ) ;
}
