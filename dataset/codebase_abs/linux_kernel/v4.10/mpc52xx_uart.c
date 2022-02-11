static inline void F_1 ( struct V_1 T_1 * V_2 ,
T_2 V_3 , unsigned int V_4 )
{
F_2 ( & V_2 -> V_5 , V_3 ) ;
F_3 ( & V_2 -> V_6 , V_4 >> 8 ) ;
F_3 ( & V_2 -> V_7 , V_4 & 0xff ) ;
}
static T_2 F_4 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_10 ) ;
}
static T_3 F_7 ( struct V_8 * V_9 )
{
return F_8 ( & F_6 ( V_9 ) -> V_11 ) ;
}
static void F_9 ( struct V_8 * V_9 , T_3 V_12 )
{
F_3 ( & F_6 ( V_9 ) -> V_13 , V_12 ) ;
}
static void F_10 ( struct V_8 * V_9 , T_3 V_14 , T_3 V_15 )
{
F_3 ( & F_6 ( V_9 ) -> V_13 , V_16 ) ;
F_3 ( & F_6 ( V_9 ) -> V_17 , V_14 ) ;
F_3 ( & F_6 ( V_9 ) -> V_17 , V_15 ) ;
}
static void F_11 ( struct V_8 * V_9 , int V_18 )
{
if ( V_18 )
F_3 ( & F_6 ( V_9 ) -> V_19 , V_20 ) ;
else
F_3 ( & F_6 ( V_9 ) -> V_21 , V_20 ) ;
}
static void F_12 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_6 ( V_9 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_22 , V_23 | V_24 ) ;
V_9 -> V_25 |= V_26 ;
F_2 ( & V_2 -> V_27 , V_9 -> V_25 ) ;
}
static void F_13 ( struct V_8 * V_9 , T_4 V_28 )
{
F_14 ( & F_6 ( V_9 ) -> V_29 , V_28 ) ;
}
static void F_15 ( struct V_8 * V_9 , T_2 V_28 )
{
F_2 ( & F_6 ( V_9 ) -> V_27 , V_28 ) ;
}
static T_3 F_16 ( struct V_8 * V_9 )
{
F_3 ( & F_6 ( V_9 ) -> V_13 , V_16 ) ;
return F_8 ( & F_6 ( V_9 ) -> V_17 ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
struct V_1 T_1 * V_2 = F_6 ( V_9 ) ;
struct V_30 T_1 * V_31 = F_18 ( V_9 ) ;
F_3 ( & V_31 -> V_32 , 0x00 ) ;
F_2 ( & V_31 -> V_33 , 0x1ff ) ;
F_3 ( & V_31 -> V_34 , 0x07 ) ;
F_2 ( & V_31 -> V_35 , 0x80 ) ;
V_9 -> V_25 |= V_36 | V_37 ;
F_2 ( & V_2 -> V_27 , V_9 -> V_25 ) ;
}
static int F_19 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_10 )
& V_38 ;
}
static int F_20 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_10 )
& V_39 ;
}
static int F_21 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_40 )
& V_9 -> V_25
& V_36 ;
}
static int F_22 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_40 )
& V_9 -> V_25
& V_37 ;
}
static int F_23 ( struct V_8 * V_9 )
{
T_2 V_41 = F_5 ( & F_6 ( V_9 ) -> V_10 ) ;
return ( V_41 & V_42 ) ? V_43 : 0 ;
}
static void F_24 ( struct V_8 * V_9 )
{
V_9 -> V_25 |= V_37 ;
F_2 ( & F_6 ( V_9 ) -> V_27 , V_9 -> V_25 ) ;
}
static void F_25 ( struct V_8 * V_9 )
{
V_9 -> V_25 &= ~ V_37 ;
F_2 ( & F_6 ( V_9 ) -> V_27 , V_9 -> V_25 ) ;
}
static void F_26 ( struct V_8 * V_9 )
{
V_9 -> V_25 &= ~ V_36 ;
F_2 ( & F_6 ( V_9 ) -> V_27 , V_9 -> V_25 ) ;
}
static void F_27 ( struct V_8 * V_9 )
{
}
static void F_28 ( struct V_8 * V_9 )
{
}
static void F_29 ( struct V_8 * V_9 , unsigned char V_44 )
{
F_3 ( & F_6 ( V_9 ) -> V_45 , V_44 ) ;
}
static unsigned char F_30 ( struct V_8 * V_9 )
{
return F_8 ( & F_6 ( V_9 ) -> V_45 ) ;
}
static void F_31 ( struct V_8 * V_9 )
{
F_2 ( & F_6 ( V_9 ) -> V_27 , 0 ) ;
}
static void F_32 ( struct V_8 * V_9 )
{
F_2 ( & F_6 ( V_9 ) -> V_27 , V_9 -> V_25 ) ;
}
static unsigned int F_33 ( struct V_8 * V_9 ,
struct V_46 * V_47 ,
struct V_46 * V_48 )
{
unsigned int V_49 ;
unsigned int V_4 ;
V_49 = F_34 ( V_9 , V_47 , V_48 ,
V_9 -> V_50 / ( 32 * 0xffff ) + 1 ,
V_9 -> V_50 / 32 ) ;
V_4 = ( V_9 -> V_50 + 16 * V_49 ) / ( 32 * V_49 ) ;
F_1 ( F_6 ( V_9 ) , 0xdd00 , V_4 ) ;
return V_49 ;
}
static unsigned int F_35 ( struct V_8 * V_9 ,
struct V_46 * V_47 ,
struct V_46 * V_48 )
{
unsigned int V_49 ;
unsigned int V_4 ;
T_2 V_3 ;
V_49 = F_34 ( V_9 , V_47 , V_48 ,
V_9 -> V_50 / ( 32 * 0xffff ) + 1 ,
V_9 -> V_50 / 4 ) ;
V_4 = ( V_9 -> V_50 + 2 * V_49 ) / ( 4 * V_49 ) ;
if ( V_4 > 0xffff || V_49 <= 115200 ) {
V_4 = ( V_4 + 4 ) / 8 ;
V_3 = 0xdd00 ;
} else
V_3 = 0xff00 ;
F_1 ( F_6 ( V_9 ) , V_3 , V_4 ) ;
return V_49 ;
}
static void F_36 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
V_9 -> V_53 = 0 ;
V_9 -> V_54 = F_37 ( V_52 , 0 ) ;
}
static T_5 F_38 ( struct V_8 * V_9 )
{
return F_39 ( V_9 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
F_2 ( & F_6 ( V_9 ) -> V_5 , 0xdd00 ) ;
F_14 ( & F_41 ( V_9 ) -> V_55 , V_56 ) ;
F_14 ( & F_41 ( V_9 ) -> V_55 , V_57 ) ;
F_14 ( & F_41 ( V_9 ) -> V_58 , 1 ) ;
F_14 ( & F_41 ( V_9 ) -> V_59 , 0 ) ;
F_14 ( & F_41 ( V_9 ) -> V_60 , V_56 ) ;
F_14 ( & F_41 ( V_9 ) -> V_60 , V_57 ) ;
F_14 ( & F_41 ( V_9 ) -> V_61 , 1 ) ;
F_14 ( & F_41 ( V_9 ) -> V_62 , 0 ) ;
F_14 ( & F_41 ( V_9 ) -> V_59 , V_63 ) ;
F_14 ( & F_41 ( V_9 ) -> V_62 , V_63 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_41 ( V_9 ) -> V_64 ) & V_65 ) ;
}
static int F_44 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_41 ( V_9 ) -> V_66 ) & V_67 ) ;
}
static int F_45 ( struct V_8 * V_9 )
{
return F_43 ( & F_41 ( V_9 ) -> V_64 )
& F_43 ( & F_41 ( V_9 ) -> V_62 )
& V_63 ;
}
static int F_46 ( struct V_8 * V_9 )
{
return F_43 ( & F_41 ( V_9 ) -> V_66 )
& F_43 ( & F_41 ( V_9 ) -> V_59 )
& V_63 ;
}
static int F_47 ( struct V_8 * V_9 )
{
return F_43 ( & F_41 ( V_9 ) -> V_66 )
& V_65 ;
}
static void F_48 ( struct V_8 * V_9 )
{
unsigned long V_68 ;
V_68 = F_43 ( & F_41 ( V_9 ) -> V_62 ) ;
V_68 &= ~ V_63 ;
F_14 ( & F_41 ( V_9 ) -> V_62 , V_68 ) ;
}
static void F_49 ( struct V_8 * V_9 )
{
unsigned long V_69 ;
V_69 = F_43 ( & F_41 ( V_9 ) -> V_59 ) ;
V_69 |= V_63 ;
F_14 ( & F_41 ( V_9 ) -> V_59 , V_69 ) ;
}
static void F_50 ( struct V_8 * V_9 )
{
unsigned long V_69 ;
V_69 = F_43 ( & F_41 ( V_9 ) -> V_59 ) ;
V_69 &= ~ V_63 ;
F_14 ( & F_41 ( V_9 ) -> V_59 , V_69 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
F_14 ( & F_41 ( V_9 ) -> V_70 , F_43 ( & F_41 ( V_9 ) -> V_70 ) ) ;
}
static void F_52 ( struct V_8 * V_9 )
{
F_14 ( & F_41 ( V_9 ) -> V_71 , F_43 ( & F_41 ( V_9 ) -> V_71 ) ) ;
}
static void F_53 ( struct V_8 * V_9 , unsigned char V_44 )
{
F_3 ( & F_41 ( V_9 ) -> V_72 , V_44 ) ;
}
static unsigned char F_54 ( struct V_8 * V_9 )
{
return F_8 ( & F_41 ( V_9 ) -> V_73 ) ;
}
static void F_55 ( struct V_8 * V_9 )
{
V_9 -> V_25 =
F_43 ( & F_41 ( V_9 ) -> V_59 ) << 16 |
F_43 ( & F_41 ( V_9 ) -> V_62 ) ;
F_14 ( & F_41 ( V_9 ) -> V_59 , 0 ) ;
F_14 ( & F_41 ( V_9 ) -> V_62 , 0 ) ;
}
static void F_56 ( struct V_8 * V_9 )
{
F_14 ( & F_41 ( V_9 ) -> V_59 ,
( V_9 -> V_25 >> 16 ) & 0x7f ) ;
F_14 ( & F_41 ( V_9 ) -> V_62 , V_9 -> V_25 & 0x7f ) ;
}
static unsigned int F_57 ( struct V_8 * V_9 ,
struct V_46 * V_47 ,
struct V_46 * V_48 )
{
unsigned int V_49 ;
unsigned int V_4 ;
V_49 = F_34 ( V_9 , V_47 , V_48 ,
V_9 -> V_50 / ( 16 * 0xffff ) + 1 ,
V_9 -> V_50 / 16 ) ;
V_4 = ( V_9 -> V_50 + 8 * V_49 ) / ( 16 * V_49 ) ;
F_1 ( F_6 ( V_9 ) , 0xdd00 , V_4 ) ;
return V_49 ;
}
static int T_6 F_58 ( void )
{
int V_74 ;
struct V_51 * V_52 ;
struct V_75 * V_75 ;
V_74 = - V_76 ;
V_52 = F_59 ( NULL , NULL ,
L_1 ) ;
if ( ! V_52 ) {
F_60 ( L_2 , V_77 ) ;
goto V_78;
}
V_75 = F_61 ( V_52 , 0 ) ;
if ( F_62 ( V_75 ) ) {
V_75 = F_63 ( V_52 -> V_79 , L_3 ) ;
}
if ( F_62 ( V_75 ) ) {
F_60 ( L_4 , V_77 ) ;
V_74 = F_64 ( V_75 ) ;
goto V_80;
}
if ( F_65 ( V_75 ) ) {
F_60 ( L_5 , V_77 ) ;
F_66 ( V_75 ) ;
goto V_80;
}
V_81 = V_75 ;
V_82 = F_67 ( V_52 , 0 ) ;
if ( ! V_82 ) {
F_60 ( L_6 , V_77 ) ;
goto V_83;
}
V_84 = F_37 ( V_52 , 0 ) ;
if ( V_84 == 0 ) {
F_60 ( L_7 , V_77 ) ;
goto V_85;
}
F_68 ( V_52 ) ;
return 0 ;
V_85:
F_69 ( V_82 ) ;
V_83:
F_70 ( V_81 ) ;
F_66 ( V_81 ) ;
V_80:
F_68 ( V_52 ) ;
V_78:
return V_74 ;
}
static void T_7 F_71 ( void )
{
F_69 ( V_82 ) ;
if ( V_81 ) {
F_70 ( V_81 ) ;
F_66 ( V_81 ) ;
V_81 = NULL ;
}
}
static T_5 F_72 ( struct V_8 * V_9 )
{
unsigned long V_86 ;
int V_87 ;
V_86 = F_43 ( & V_82 -> V_86 ) ;
V_87 = ( V_9 -> V_88 & 0xf00 ) >> 8 ;
if ( F_73 ( V_87 , & V_86 ) ||
F_73 ( V_87 + 16 , & V_86 ) )
return F_39 ( V_9 ) ;
return V_89 ;
}
static int F_74 ( struct V_8 * V_9 )
{
int V_87 ;
struct V_75 * V_75 ;
int V_74 ;
V_87 = ( V_9 -> V_88 & 0xf00 ) >> 8 ;
V_75 = F_75 ( V_9 -> V_90 , L_8 ) ;
if ( F_62 ( V_75 ) ) {
F_76 ( V_9 -> V_90 , L_9 ) ;
V_74 = F_64 ( V_75 ) ;
goto V_78;
}
V_74 = F_65 ( V_75 ) ;
if ( V_74 ) {
F_76 ( V_9 -> V_90 , L_10 ) ;
goto V_78;
}
V_91 [ V_87 ] = V_75 ;
V_75 = F_75 ( V_9 -> V_90 , L_3 ) ;
if ( F_62 ( V_75 ) ) {
F_76 ( V_9 -> V_90 , L_11 ) ;
V_74 = F_64 ( V_75 ) ;
goto V_78;
}
V_74 = F_65 ( V_75 ) ;
if ( V_74 ) {
F_76 ( V_9 -> V_90 , L_12 ) ;
goto V_78;
}
V_92 [ V_87 ] = V_75 ;
return 0 ;
V_78:
if ( V_91 [ V_87 ] ) {
F_70 ( V_91 [ V_87 ] ) ;
V_91 [ V_87 ] = NULL ;
}
if ( V_92 [ V_87 ] ) {
F_70 ( V_92 [ V_87 ] ) ;
V_92 [ V_87 ] = NULL ;
}
return V_74 ;
}
static void F_77 ( struct V_8 * V_9 )
{
int V_87 ;
struct V_75 * V_75 ;
V_87 = ( V_9 -> V_88 & 0xf00 ) >> 8 ;
V_75 = V_91 [ V_87 ] ;
if ( V_75 ) {
F_70 ( V_75 ) ;
V_91 [ V_87 ] = NULL ;
}
if ( V_92 [ V_87 ] ) {
F_70 ( V_92 [ V_87 ] ) ;
V_92 [ V_87 ] = NULL ;
}
}
static int F_78 ( struct V_8 * V_9 , int V_93 )
{
int V_87 ;
struct V_75 * V_94 ;
int V_95 ;
if ( F_79 ( V_9 ) )
return 0 ;
V_87 = ( V_9 -> V_88 & 0xf00 ) >> 8 ;
V_94 = V_91 [ V_87 ] ;
if ( ! V_94 ) {
F_76 ( V_9 -> V_90 , L_13 ) ;
return - V_76 ;
}
F_80 ( V_9 -> V_90 , L_14 , V_93 ? L_15 : L_16 ) ;
if ( V_93 ) {
V_95 = F_81 ( V_94 ) ;
if ( V_95 )
F_76 ( V_9 -> V_90 , L_10 ) ;
return V_95 ;
} else {
F_82 ( V_94 ) ;
return 0 ;
}
}
static void F_83 ( struct V_8 * V_9 , struct V_51 * V_52 )
{
V_9 -> V_53 = V_96 ;
V_9 -> V_54 = V_84 ;
}
static void F_84 ( struct V_8 * V_9 )
{
F_3 ( & F_85 ( V_9 ) -> V_5 , 0xdd ) ;
F_14 ( & F_86 ( V_9 ) -> V_55 , V_56 ) ;
F_14 ( & F_86 ( V_9 ) -> V_55 , V_57 ) ;
F_14 ( & F_86 ( V_9 ) -> V_58 , 1 ) ;
F_14 ( & F_86 ( V_9 ) -> V_59 , 0 ) ;
F_14 ( & F_86 ( V_9 ) -> V_60 , V_56 ) ;
F_14 ( & F_86 ( V_9 ) -> V_60 , V_57 ) ;
F_14 ( & F_86 ( V_9 ) -> V_61 , 1 ) ;
F_14 ( & F_86 ( V_9 ) -> V_62 , 0 ) ;
F_14 ( & F_86 ( V_9 ) -> V_59 , V_63 ) ;
F_14 ( & F_86 ( V_9 ) -> V_62 , V_63 ) ;
}
static int F_87 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_86 ( V_9 ) -> V_64 ) & V_65 ) ;
}
static int F_88 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_86 ( V_9 ) -> V_66 ) & V_67 ) ;
}
static int F_89 ( struct V_8 * V_9 )
{
return F_43 ( & F_86 ( V_9 ) -> V_64 ) &
F_43 ( & F_86 ( V_9 ) -> V_62 ) & V_63 ;
}
static int F_90 ( struct V_8 * V_9 )
{
return F_43 ( & F_86 ( V_9 ) -> V_66 ) &
F_43 ( & F_86 ( V_9 ) -> V_59 ) & V_63 ;
}
static int F_91 ( struct V_8 * V_9 )
{
return F_43 ( & F_86 ( V_9 ) -> V_66 ) & V_65 ;
}
static void F_92 ( struct V_8 * V_9 )
{
unsigned long V_68 ;
V_68 = F_43 ( & F_86 ( V_9 ) -> V_62 ) ;
V_68 &= ~ V_63 ;
F_14 ( & F_86 ( V_9 ) -> V_62 , V_68 ) ;
}
static void F_93 ( struct V_8 * V_9 )
{
unsigned long V_69 ;
V_69 = F_43 ( & F_86 ( V_9 ) -> V_59 ) ;
V_69 |= V_63 ;
F_14 ( & F_86 ( V_9 ) -> V_59 , V_69 ) ;
}
static void F_94 ( struct V_8 * V_9 )
{
unsigned long V_69 ;
V_69 = F_43 ( & F_86 ( V_9 ) -> V_59 ) ;
V_69 &= ~ V_63 ;
F_14 ( & F_86 ( V_9 ) -> V_59 , V_69 ) ;
}
static void F_95 ( struct V_8 * V_9 )
{
F_14 ( & F_86 ( V_9 ) -> V_70 , F_43 ( & F_86 ( V_9 ) -> V_70 ) ) ;
}
static void F_96 ( struct V_8 * V_9 )
{
F_14 ( & F_86 ( V_9 ) -> V_71 , F_43 ( & F_86 ( V_9 ) -> V_71 ) ) ;
}
static void F_97 ( struct V_8 * V_9 , unsigned char V_44 )
{
F_3 ( & F_86 ( V_9 ) -> V_72 , V_44 ) ;
}
static unsigned char F_98 ( struct V_8 * V_9 )
{
return F_8 ( & F_86 ( V_9 ) -> V_73 ) ;
}
static void F_99 ( struct V_8 * V_9 )
{
V_9 -> V_25 =
F_43 ( & F_86 ( V_9 ) -> V_59 ) << 16 |
F_43 ( & F_86 ( V_9 ) -> V_62 ) ;
F_14 ( & F_86 ( V_9 ) -> V_59 , 0 ) ;
F_14 ( & F_86 ( V_9 ) -> V_62 , 0 ) ;
}
static void F_100 ( struct V_8 * V_9 )
{
F_14 ( & F_86 ( V_9 ) -> V_59 ,
( V_9 -> V_25 >> 16 ) & 0x7f ) ;
F_14 ( & F_86 ( V_9 ) -> V_62 , V_9 -> V_25 & 0x7f ) ;
}
static inline void F_101 ( struct V_97 T_1 * V_2 ,
T_3 V_3 , unsigned int V_4 )
{
F_3 ( & V_2 -> V_5 , V_3 ) ;
F_3 ( & V_2 -> V_6 , V_4 >> 8 ) ;
F_3 ( & V_2 -> V_7 , V_4 & 0xff ) ;
}
static unsigned int F_102 ( struct V_8 * V_9 ,
struct V_46 * V_47 ,
struct V_46 * V_48 )
{
unsigned int V_49 ;
unsigned int V_4 ;
V_49 = F_34 ( V_9 , V_47 , V_48 ,
V_9 -> V_50 / ( 16 * 0xffff ) + 1 ,
V_9 -> V_50 / 16 ) ;
V_4 = ( V_9 -> V_50 + 8 * V_49 ) / ( 16 * V_49 ) ;
F_101 ( F_85 ( V_9 ) , 0xdd , V_4 ) ;
return V_49 ;
}
static T_2 F_103 ( struct V_8 * V_9 )
{
return F_5 ( & F_85 ( V_9 ) -> V_10 ) ;
}
static T_3 F_104 ( struct V_8 * V_9 )
{
return F_8 ( & F_85 ( V_9 ) -> V_11 ) ;
}
static void F_105 ( struct V_8 * V_9 , T_3 V_12 )
{
F_3 ( & F_85 ( V_9 ) -> V_13 , V_12 ) ;
}
static void F_106 ( struct V_8 * V_9 , T_3 V_14 , T_3 V_15 )
{
F_3 ( & F_85 ( V_9 ) -> V_14 , V_14 ) ;
F_3 ( & F_85 ( V_9 ) -> V_15 , V_15 ) ;
}
static void F_107 ( struct V_8 * V_9 , int V_18 )
{
if ( V_18 & V_98 )
F_3 ( & F_85 ( V_9 ) -> V_19 , V_20 ) ;
else
F_3 ( & F_85 ( V_9 ) -> V_21 , V_20 ) ;
}
static void F_108 ( struct V_8 * V_9 )
{
struct V_97 T_1 * V_2 = F_85 ( V_9 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_22 , V_23 | V_24 ) ;
V_9 -> V_25 |= V_26 ;
F_2 ( & V_2 -> V_27 , V_9 -> V_25 ) ;
}
static void F_109 ( struct V_8 * V_9 , T_4 V_28 )
{
F_14 ( & F_85 ( V_9 ) -> V_29 , V_28 ) ;
}
static void F_110 ( struct V_8 * V_9 , T_2 V_28 )
{
F_2 ( & F_85 ( V_9 ) -> V_27 , V_28 ) ;
}
static T_3 F_111 ( struct V_8 * V_9 )
{
return F_8 ( & F_85 ( V_9 ) -> V_14 ) ;
}
static unsigned int
F_112 ( struct V_8 * V_9 )
{
return V_99 -> V_100 ( V_9 ) ? V_43 : 0 ;
}
static void
F_113 ( struct V_8 * V_9 , unsigned int V_101 )
{
V_99 -> V_102 ( V_9 , V_101 & V_98 ) ;
}
static unsigned int
F_114 ( struct V_8 * V_9 )
{
unsigned int V_95 = V_103 ;
T_3 V_104 = V_99 -> V_105 ( V_9 ) ;
if ( ! ( V_104 & V_106 ) )
V_95 |= V_107 ;
if ( ! ( V_104 & V_108 ) )
V_95 |= V_109 ;
return V_95 ;
}
static void
F_115 ( struct V_8 * V_9 )
{
V_99 -> V_110 ( V_9 ) ;
}
static void
F_116 ( struct V_8 * V_9 )
{
V_99 -> V_111 ( V_9 ) ;
}
static void
F_117 ( struct V_8 * V_9 )
{
V_99 -> V_112 ( V_9 ) ;
}
static void
F_118 ( struct V_8 * V_9 )
{
V_99 -> V_113 ( V_9 ) ;
}
static void
F_119 ( struct V_8 * V_9 , int V_114 )
{
unsigned long V_115 ;
F_120 ( & V_9 -> V_116 , V_115 ) ;
if ( V_114 == - 1 )
V_99 -> V_13 ( V_9 , V_117 ) ;
else
V_99 -> V_13 ( V_9 , V_118 ) ;
F_121 ( & V_9 -> V_116 , V_115 ) ;
}
static int
F_122 ( struct V_8 * V_9 )
{
int V_95 ;
if ( V_99 -> clock ) {
V_95 = V_99 -> clock ( V_9 , 1 ) ;
if ( V_95 )
return V_95 ;
}
V_95 = F_123 ( V_9 -> V_54 , V_119 ,
V_9 -> V_53 , L_17 , V_9 ) ;
if ( V_95 )
return V_95 ;
V_99 -> V_13 ( V_9 , V_120 ) ;
V_99 -> V_13 ( V_9 , V_121 ) ;
F_124 ( 1 ) ;
V_99 -> V_122 ( V_9 , 0 ) ;
V_99 -> V_123 ( V_9 ) ;
V_99 -> V_13 ( V_9 , V_124 ) ;
V_99 -> V_13 ( V_9 , V_125 ) ;
return 0 ;
}
static void
F_125 ( struct V_8 * V_9 )
{
V_99 -> V_13 ( V_9 , V_120 ) ;
if ( ! F_79 ( V_9 ) )
V_99 -> V_13 ( V_9 , V_121 ) ;
V_9 -> V_25 = 0 ;
V_99 -> V_126 ( V_9 , V_9 -> V_25 ) ;
if ( V_99 -> clock )
V_99 -> clock ( V_9 , 0 ) ;
V_99 -> V_127 ( V_9 ) ;
F_126 ( V_9 -> V_54 , V_9 ) ;
}
static void
F_127 ( struct V_8 * V_9 , struct V_46 * V_47 ,
struct V_46 * V_48 )
{
unsigned long V_115 ;
unsigned char V_14 , V_15 ;
unsigned int V_128 ;
unsigned int V_49 ;
V_14 = 0 ;
switch ( V_47 -> V_129 & V_130 ) {
case V_131 : V_14 |= V_132 ;
break;
case V_133 : V_14 |= V_134 ;
break;
case V_135 : V_14 |= V_136 ;
break;
case V_137 :
default: V_14 |= V_138 ;
}
if ( V_47 -> V_129 & V_139 ) {
if ( V_47 -> V_129 & V_140 )
V_14 |= V_141 ;
V_14 |= ( V_47 -> V_129 & V_142 ) ?
V_143 : V_144 ;
} else {
V_14 |= V_145 ;
}
V_15 = 0 ;
if ( V_47 -> V_129 & V_146 )
V_15 |= V_147 ;
else
V_15 |= ( ( V_47 -> V_129 & V_130 ) == V_131 ) ?
V_148 :
V_149 ;
if ( V_47 -> V_129 & V_150 ) {
V_14 |= V_151 ;
V_15 |= V_152 ;
}
F_120 ( & V_9 -> V_116 , V_115 ) ;
V_128 = 5000000 ;
while ( ! F_112 ( V_9 ) && -- V_128 )
F_128 ( 1 ) ;
if ( ! V_128 )
F_129 ( V_153 L_18
L_19
L_20 ) ;
V_99 -> V_13 ( V_9 , V_120 ) ;
V_99 -> V_13 ( V_9 , V_121 ) ;
V_99 -> V_154 ( V_9 , V_14 , V_15 ) ;
V_49 = V_99 -> V_155 ( V_9 , V_47 , V_48 ) ;
F_130 ( V_9 , V_47 -> V_129 , V_49 ) ;
if ( F_131 ( V_9 , V_47 -> V_129 ) )
F_118 ( V_9 ) ;
V_99 -> V_13 ( V_9 , V_124 ) ;
V_99 -> V_13 ( V_9 , V_125 ) ;
F_121 ( & V_9 -> V_116 , V_115 ) ;
}
static const char *
F_132 ( struct V_8 * V_9 )
{
return V_9 -> type == V_156 ? L_21 : NULL ;
}
static void
F_133 ( struct V_8 * V_9 )
{
if ( V_99 -> V_157 )
V_99 -> V_157 ( V_9 ) ;
if ( V_9 -> V_115 & V_158 ) {
F_69 ( V_9 -> V_159 ) ;
V_9 -> V_159 = NULL ;
}
F_134 ( V_9 -> V_88 , sizeof( struct V_1 ) ) ;
}
static int
F_135 ( struct V_8 * V_9 )
{
int V_74 ;
if ( V_9 -> V_115 & V_158 )
V_9 -> V_159 = F_136 ( V_9 -> V_88 ,
sizeof( struct V_1 ) ) ;
if ( ! V_9 -> V_159 )
return - V_160 ;
V_74 = F_137 ( V_9 -> V_88 , sizeof( struct V_1 ) ,
L_17 ) != NULL ? 0 : - V_161 ;
if ( V_74 )
goto V_162;
if ( V_99 -> V_163 ) {
V_74 = V_99 -> V_163 ( V_9 ) ;
if ( V_74 )
goto V_164;
}
return 0 ;
V_164:
F_134 ( V_9 -> V_88 , sizeof( struct V_1 ) ) ;
V_162:
if ( V_9 -> V_115 & V_158 ) {
F_69 ( V_9 -> V_159 ) ;
V_9 -> V_159 = NULL ;
}
return V_74 ;
}
static void
F_138 ( struct V_8 * V_9 , int V_115 )
{
if ( ( V_115 & V_165 )
&& ( F_135 ( V_9 ) == 0 ) )
V_9 -> type = V_156 ;
}
static int
F_139 ( struct V_8 * V_9 , struct V_166 * V_167 )
{
if ( V_167 -> type != V_168 && V_167 -> type != V_156 )
return - V_160 ;
if ( ( V_167 -> V_54 != V_9 -> V_54 ) ||
( V_167 -> V_169 != V_170 ) ||
( V_167 -> V_171 != V_9 -> V_50 ) ||
( V_167 -> V_172 != ( void * ) V_9 -> V_88 ) ||
( V_167 -> V_173 != 0 ) )
return - V_160 ;
return 0 ;
}
static inline int
F_140 ( struct V_8 * V_9 )
{
struct V_174 * V_175 = & V_9 -> V_18 -> V_9 ;
unsigned char V_176 , V_177 ;
unsigned short V_104 ;
while ( V_99 -> V_178 ( V_9 ) ) {
V_176 = V_99 -> V_179 ( V_9 ) ;
#ifdef F_141
if ( F_142 ( V_9 , V_176 ) ) {
V_9 -> V_180 = 0 ;
continue;
}
#endif
V_177 = V_181 ;
V_9 -> V_182 . V_183 ++ ;
V_104 = V_99 -> V_184 ( V_9 ) ;
if ( V_104 & ( V_185 |
V_186 |
V_187 ) ) {
if ( V_104 & V_187 ) {
V_177 = V_188 ;
F_143 ( V_9 ) ;
V_9 -> V_182 . V_189 ++ ;
} else if ( V_104 & V_185 ) {
V_177 = V_190 ;
V_9 -> V_182 . V_191 ++ ;
}
else if ( V_104 & V_186 ) {
V_177 = V_192 ;
V_9 -> V_182 . V_193 ++ ;
}
V_99 -> V_13 ( V_9 , V_194 ) ;
}
F_144 ( V_175 , V_176 , V_177 ) ;
if ( V_104 & V_195 ) {
F_144 ( V_175 , 0 , V_196 ) ;
V_9 -> V_182 . V_197 ++ ;
}
}
F_145 ( & V_9 -> V_116 ) ;
F_146 ( V_175 ) ;
F_147 ( & V_9 -> V_116 ) ;
return V_99 -> V_178 ( V_9 ) ;
}
static inline int
F_148 ( struct V_8 * V_9 )
{
struct V_198 * V_199 = & V_9 -> V_18 -> V_199 ;
if ( V_9 -> V_200 ) {
V_99 -> V_201 ( V_9 , V_9 -> V_200 ) ;
V_9 -> V_182 . V_202 ++ ;
V_9 -> V_200 = 0 ;
return 1 ;
}
if ( F_149 ( V_199 ) || F_150 ( V_9 ) ) {
F_115 ( V_9 ) ;
return 0 ;
}
while ( V_99 -> V_203 ( V_9 ) ) {
V_99 -> V_201 ( V_9 , V_199 -> V_204 [ V_199 -> V_205 ] ) ;
V_199 -> V_205 = ( V_199 -> V_205 + 1 ) & ( V_206 - 1 ) ;
V_9 -> V_182 . V_202 ++ ;
if ( F_149 ( V_199 ) )
break;
}
if ( F_151 ( V_199 ) < V_207 )
F_152 ( V_9 ) ;
if ( F_149 ( V_199 ) ) {
F_115 ( V_9 ) ;
return 0 ;
}
return 1 ;
}
static T_5
F_39 ( struct V_8 * V_9 )
{
unsigned long V_208 = V_209 ;
unsigned int V_210 ;
T_3 V_104 ;
do {
V_210 = 0 ;
V_99 -> V_211 ( V_9 ) ;
if ( V_99 -> V_212 ( V_9 ) )
V_210 |= F_140 ( V_9 ) ;
V_99 -> V_213 ( V_9 ) ;
if ( V_99 -> V_214 ( V_9 ) )
V_210 |= F_148 ( V_9 ) ;
V_104 = V_99 -> V_105 ( V_9 ) ;
if ( V_104 & V_215 )
F_153 ( V_9 , ! ( V_104 & V_108 ) ) ;
if ( V_104 & V_216 )
F_154 ( V_9 , ! ( V_104 & V_106 ) ) ;
if ( ! ( -- V_208 ) )
V_210 = 0 ;
} while ( V_210 );
return V_217 ;
}
static T_5
V_119 ( int V_54 , void * V_218 )
{
struct V_8 * V_9 = V_218 ;
T_5 V_95 ;
F_147 ( & V_9 -> V_116 ) ;
V_95 = V_99 -> V_219 ( V_9 ) ;
F_145 ( & V_9 -> V_116 ) ;
return V_95 ;
}
static void T_6
F_155 ( struct V_8 * V_9 ,
int * V_49 , int * V_191 , int * V_220 , int * V_221 )
{
unsigned char V_14 ;
F_156 ( L_22 , V_9 ) ;
V_14 = V_99 -> V_222 ( V_9 ) ;
* V_49 = V_223 ;
switch ( V_14 & V_224 ) {
case V_132 :
* V_220 = 5 ;
break;
case V_134 :
* V_220 = 6 ;
break;
case V_136 :
* V_220 = 7 ;
break;
case V_138 :
default:
* V_220 = 8 ;
}
if ( V_14 & V_145 )
* V_191 = 'n' ;
else
* V_191 = V_14 & V_143 ? 'o' : 'e' ;
}
static void
F_157 ( struct V_225 * V_226 , const char * V_227 , unsigned int V_228 )
{
struct V_8 * V_9 = & V_229 [ V_226 -> V_230 ] ;
unsigned int V_231 , V_128 ;
V_99 -> V_127 ( V_9 ) ;
V_128 = 5000000 ;
while ( ! F_112 ( V_9 ) && -- V_128 )
F_128 ( 1 ) ;
for ( V_231 = 0 ; V_231 < V_228 ; V_231 ++ , V_227 ++ ) {
if ( * V_227 == '\n' )
V_99 -> V_201 ( V_9 , '\r' ) ;
V_99 -> V_201 ( V_9 , * V_227 ) ;
V_128 = 20000 ;
while ( ! F_112 ( V_9 ) && -- V_128 )
F_128 ( 1 ) ;
}
V_99 -> V_232 ( V_9 ) ;
}
static int T_6
F_158 ( struct V_225 * V_226 , char * V_233 )
{
struct V_8 * V_9 = & V_229 [ V_226 -> V_230 ] ;
struct V_51 * V_52 = V_234 [ V_226 -> V_230 ] ;
unsigned int V_50 ;
struct V_235 V_236 ;
int V_95 ;
int V_49 = V_223 ;
int V_220 = 8 ;
int V_191 = 'n' ;
int V_221 = 'n' ;
F_156 ( L_23 ,
V_226 , V_226 -> V_230 , V_233 ) ;
if ( ( V_226 -> V_230 < 0 ) || ( V_226 -> V_230 >= V_237 ) ) {
F_156 ( L_24 , V_226 -> V_230 ) ;
return - V_160 ;
}
if ( ! V_52 ) {
F_156 ( L_25 , V_226 -> V_230 ) ;
return - V_160 ;
}
F_156 ( L_26 ,
V_226 -> V_230 , V_234 [ V_226 -> V_230 ] -> V_238 ) ;
V_95 = F_159 ( V_52 , 0 , & V_236 ) ;
if ( V_95 ) {
F_156 ( L_27 , V_226 -> V_230 ) ;
return V_95 ;
}
V_50 = F_160 ( V_52 ) ;
if ( V_50 == 0 ) {
F_156 ( L_28 ) ;
return - V_160 ;
}
F_161 ( & V_9 -> V_116 ) ;
V_9 -> V_50 = V_50 ;
V_9 -> V_239 = & V_240 ;
V_9 -> V_88 = V_236 . V_241 ;
V_9 -> V_159 = F_136 ( V_236 . V_241 , sizeof( struct V_1 ) ) ;
V_9 -> V_54 = F_37 ( V_52 , 0 ) ;
if ( V_9 -> V_159 == NULL )
return - V_160 ;
F_156 ( L_29 ,
( void * ) V_9 -> V_88 , V_9 -> V_159 ,
V_9 -> V_54 , V_9 -> V_50 ) ;
if ( V_233 )
F_162 ( V_233 , & V_49 , & V_191 , & V_220 , & V_221 ) ;
else
F_155 ( V_9 , & V_49 , & V_191 , & V_220 , & V_221 ) ;
F_156 ( L_30 ,
V_49 , V_220 , V_191 , V_221 ) ;
return F_163 ( V_9 , V_226 , V_49 , V_191 , V_220 , V_221 ) ;
}
static int T_6
F_164 ( void )
{
F_165 () ;
F_166 ( & V_242 ) ;
return 0 ;
}
static int F_167 ( struct V_243 * V_244 )
{
int V_245 = - 1 ;
unsigned int V_50 ;
struct V_8 * V_9 = NULL ;
struct V_235 V_236 ;
int V_95 ;
for ( V_245 = 0 ; V_245 < V_237 ; V_245 ++ )
if ( V_234 [ V_245 ] == V_244 -> V_90 . V_246 )
break;
if ( V_245 >= V_237 )
return - V_160 ;
F_156 ( L_31 ,
V_234 [ V_245 ] -> V_238 , V_245 ) ;
V_50 = F_160 ( V_244 -> V_90 . V_246 ) ;
if ( V_50 == 0 ) {
F_80 ( & V_244 -> V_90 , L_28 ) ;
return - V_160 ;
}
V_9 = & V_229 [ V_245 ] ;
F_161 ( & V_9 -> V_116 ) ;
V_9 -> V_50 = V_50 ;
V_9 -> V_247 = 512 ;
V_9 -> V_248 = V_170 ;
V_9 -> V_115 = V_249 |
( F_79 ( V_9 ) ? 0 : V_158 ) ;
V_9 -> line = V_245 ;
V_9 -> V_239 = & V_240 ;
V_9 -> V_90 = & V_244 -> V_90 ;
V_95 = F_159 ( V_244 -> V_90 . V_246 , 0 , & V_236 ) ;
if ( V_95 )
return V_95 ;
V_9 -> V_88 = V_236 . V_241 ;
if ( ! V_9 -> V_88 ) {
F_80 ( & V_244 -> V_90 , L_32 ) ;
return - V_160 ;
}
V_99 -> V_250 ( V_9 , V_244 -> V_90 . V_246 ) ;
if ( V_9 -> V_54 == 0 ) {
F_80 ( & V_244 -> V_90 , L_33 ) ;
return - V_160 ;
}
F_80 ( & V_244 -> V_90 , L_34 ,
( void * ) V_9 -> V_88 , V_9 -> V_54 , V_9 -> V_50 ) ;
V_95 = F_168 ( & V_251 , V_9 ) ;
if ( V_95 )
return V_95 ;
F_169 ( V_244 , ( void * ) V_9 ) ;
return 0 ;
}
static int
F_170 ( struct V_243 * V_244 )
{
struct V_8 * V_9 = F_171 ( V_244 ) ;
if ( V_9 )
F_172 ( & V_251 , V_9 ) ;
return 0 ;
}
static int
F_173 ( struct V_243 * V_244 , T_8 V_18 )
{
struct V_8 * V_9 = F_171 ( V_244 ) ;
if ( V_9 )
F_174 ( & V_251 , V_9 ) ;
return 0 ;
}
static int
F_175 ( struct V_243 * V_244 )
{
struct V_8 * V_9 = F_171 ( V_244 ) ;
if ( V_9 )
F_176 ( & V_251 , V_9 ) ;
return 0 ;
}
static void
F_177 ( struct V_51 * V_52 )
{
int V_231 ;
for ( V_231 = 0 ; V_231 < V_237 ; V_231 ++ ) {
if ( V_234 [ V_231 ] == NULL ) {
F_178 ( V_52 ) ;
V_234 [ V_231 ] = V_52 ;
return;
}
}
}
static void
F_165 ( void )
{
static int V_252 ;
struct V_51 * V_52 ;
const struct V_253 * V_254 ;
int V_231 ;
if ( V_252 )
return;
F_179 (np, mpc52xx_uart_of_match) {
V_254 = F_180 ( V_255 , V_52 ) ;
V_99 = V_254 -> V_256 ;
F_177 ( V_52 ) ;
}
V_252 = 1 ;
for ( V_231 = 0 ; V_231 < V_237 ; V_231 ++ ) {
if ( V_234 [ V_231 ] )
F_156 ( L_35 ,
V_234 [ V_231 ] -> V_238 , V_231 ) ;
}
}
static int T_6
F_181 ( void )
{
int V_95 ;
F_129 ( V_257 L_36 ) ;
V_95 = F_182 ( & V_251 ) ;
if ( V_95 ) {
F_129 ( V_153 L_37 ,
__FILE__ , V_95 ) ;
return V_95 ;
}
F_165 () ;
if ( V_99 && V_99 -> V_258 ) {
V_95 = V_99 -> V_258 () ;
if ( V_95 )
goto V_259;
}
V_95 = F_183 ( & V_260 ) ;
if ( V_95 ) {
F_129 ( V_153 L_38 ,
__FILE__ , V_95 ) ;
goto V_261;
}
return 0 ;
V_261:
if ( V_99 && V_99 -> V_262 )
V_99 -> V_262 () ;
V_259:
F_184 ( & V_251 ) ;
return V_95 ;
}
static void T_7
F_185 ( void )
{
if ( V_99 -> V_262 )
V_99 -> V_262 () ;
F_186 ( & V_260 ) ;
F_184 ( & V_251 ) ;
}
