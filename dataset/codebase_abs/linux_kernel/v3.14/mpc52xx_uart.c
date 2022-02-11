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
return F_5 ( & F_6 ( V_9 ) -> V_10 )
& V_41 ;
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
static void F_29 ( struct V_8 * V_9 , unsigned char V_42 )
{
F_3 ( & F_6 ( V_9 ) -> V_43 , V_42 ) ;
}
static unsigned char F_30 ( struct V_8 * V_9 )
{
return F_8 ( & F_6 ( V_9 ) -> V_43 ) ;
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
struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned int V_47 ;
unsigned int V_4 ;
V_47 = F_34 ( V_9 , V_45 , V_46 ,
V_9 -> V_48 / ( 32 * 0xffff ) + 1 ,
V_9 -> V_48 / 32 ) ;
V_4 = ( V_9 -> V_48 + 16 * V_47 ) / ( 32 * V_47 ) ;
F_1 ( F_6 ( V_9 ) , 0xdd00 , V_4 ) ;
return V_47 ;
}
static unsigned int F_35 ( struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned int V_47 ;
unsigned int V_4 ;
T_2 V_3 ;
V_47 = F_34 ( V_9 , V_45 , V_46 ,
V_9 -> V_48 / ( 32 * 0xffff ) + 1 ,
V_9 -> V_48 / 4 ) ;
V_4 = ( V_9 -> V_48 + 2 * V_47 ) / ( 4 * V_47 ) ;
if ( V_4 > 0xffff || V_47 <= 115200 ) {
V_4 = ( V_4 + 4 ) / 8 ;
V_3 = 0xdd00 ;
} else
V_3 = 0xff00 ;
F_1 ( F_6 ( V_9 ) , V_3 , V_4 ) ;
return V_47 ;
}
static void F_36 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
V_9 -> V_51 = 0 ;
V_9 -> V_52 = F_37 ( V_50 , 0 ) ;
}
static T_5 F_38 ( struct V_8 * V_9 )
{
return F_39 ( V_9 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
F_2 ( & F_6 ( V_9 ) -> V_5 , 0xdd00 ) ;
F_14 ( & F_41 ( V_9 ) -> V_53 , V_54 ) ;
F_14 ( & F_41 ( V_9 ) -> V_53 , V_55 ) ;
F_14 ( & F_41 ( V_9 ) -> V_56 , 1 ) ;
F_14 ( & F_41 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_41 ( V_9 ) -> V_58 , V_54 ) ;
F_14 ( & F_41 ( V_9 ) -> V_58 , V_55 ) ;
F_14 ( & F_41 ( V_9 ) -> V_59 , 1 ) ;
F_14 ( & F_41 ( V_9 ) -> V_60 , 0 ) ;
F_14 ( & F_41 ( V_9 ) -> V_57 , V_61 ) ;
F_14 ( & F_41 ( V_9 ) -> V_60 , V_61 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_41 ( V_9 ) -> V_62 ) & V_63 ) ;
}
static int F_44 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_41 ( V_9 ) -> V_64 ) & V_65 ) ;
}
static int F_45 ( struct V_8 * V_9 )
{
return F_43 ( & F_41 ( V_9 ) -> V_62 )
& F_43 ( & F_41 ( V_9 ) -> V_60 )
& V_61 ;
}
static int F_46 ( struct V_8 * V_9 )
{
return F_43 ( & F_41 ( V_9 ) -> V_64 )
& F_43 ( & F_41 ( V_9 ) -> V_57 )
& V_61 ;
}
static int F_47 ( struct V_8 * V_9 )
{
return F_43 ( & F_41 ( V_9 ) -> V_64 )
& V_63 ;
}
static void F_48 ( struct V_8 * V_9 )
{
unsigned long V_66 ;
V_66 = F_43 ( & F_41 ( V_9 ) -> V_60 ) ;
V_66 &= ~ V_61 ;
F_14 ( & F_41 ( V_9 ) -> V_60 , V_66 ) ;
}
static void F_49 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_41 ( V_9 ) -> V_57 ) ;
V_67 |= V_61 ;
F_14 ( & F_41 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_50 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_41 ( V_9 ) -> V_57 ) ;
V_67 &= ~ V_61 ;
F_14 ( & F_41 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
F_14 ( & F_41 ( V_9 ) -> V_68 , F_43 ( & F_41 ( V_9 ) -> V_68 ) ) ;
}
static void F_52 ( struct V_8 * V_9 )
{
F_14 ( & F_41 ( V_9 ) -> V_69 , F_43 ( & F_41 ( V_9 ) -> V_69 ) ) ;
}
static void F_53 ( struct V_8 * V_9 , unsigned char V_42 )
{
F_3 ( & F_41 ( V_9 ) -> V_70 , V_42 ) ;
}
static unsigned char F_54 ( struct V_8 * V_9 )
{
return F_8 ( & F_41 ( V_9 ) -> V_71 ) ;
}
static void F_55 ( struct V_8 * V_9 )
{
V_9 -> V_25 =
F_43 ( & F_41 ( V_9 ) -> V_57 ) << 16 |
F_43 ( & F_41 ( V_9 ) -> V_60 ) ;
F_14 ( & F_41 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_41 ( V_9 ) -> V_60 , 0 ) ;
}
static void F_56 ( struct V_8 * V_9 )
{
F_14 ( & F_41 ( V_9 ) -> V_57 ,
( V_9 -> V_25 >> 16 ) & 0x7f ) ;
F_14 ( & F_41 ( V_9 ) -> V_60 , V_9 -> V_25 & 0x7f ) ;
}
static unsigned int F_57 ( struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned int V_47 ;
unsigned int V_4 ;
V_47 = F_34 ( V_9 , V_45 , V_46 ,
V_9 -> V_48 / ( 16 * 0xffff ) + 1 ,
V_9 -> V_48 / 16 ) ;
V_4 = ( V_9 -> V_48 + 8 * V_47 ) / ( 16 * V_47 ) ;
F_1 ( F_6 ( V_9 ) , 0xdd00 , V_4 ) ;
return V_47 ;
}
static int T_6 F_58 ( void )
{
int V_72 ;
struct V_49 * V_50 ;
struct V_73 * V_73 ;
V_72 = - V_74 ;
V_50 = F_59 ( NULL , NULL ,
L_1 ) ;
if ( ! V_50 ) {
F_60 ( L_2 , V_75 ) ;
goto V_76;
}
V_73 = F_61 ( V_50 , 0 ) ;
if ( F_62 ( V_73 ) ) {
V_73 = F_63 ( V_50 -> V_77 , L_3 ) ;
}
if ( F_62 ( V_73 ) ) {
F_60 ( L_4 , V_75 ) ;
V_72 = F_64 ( V_73 ) ;
goto V_78;
}
if ( F_65 ( V_73 ) ) {
F_60 ( L_5 , V_75 ) ;
F_66 ( V_73 ) ;
goto V_78;
}
V_79 = V_73 ;
V_80 = F_67 ( V_50 , 0 ) ;
if ( ! V_80 ) {
F_60 ( L_6 , V_75 ) ;
goto V_81;
}
V_82 = F_37 ( V_50 , 0 ) ;
if ( V_82 == 0 ) {
F_60 ( L_7 , V_75 ) ;
goto V_83;
}
F_68 ( V_50 ) ;
return 0 ;
V_83:
F_69 ( V_80 ) ;
V_81:
F_70 ( V_79 ) ;
F_66 ( V_79 ) ;
V_78:
F_68 ( V_50 ) ;
V_76:
return V_72 ;
}
static void T_7 F_71 ( void )
{
F_69 ( V_80 ) ;
if ( V_79 ) {
F_70 ( V_79 ) ;
F_66 ( V_79 ) ;
V_79 = NULL ;
}
}
static T_5 F_72 ( struct V_8 * V_9 )
{
unsigned long V_84 ;
int V_85 ;
V_84 = F_43 ( & V_80 -> V_84 ) ;
V_85 = ( V_9 -> V_86 & 0xf00 ) >> 8 ;
if ( F_73 ( V_85 , & V_84 ) ||
F_73 ( V_85 + 16 , & V_84 ) )
return F_39 ( V_9 ) ;
return V_87 ;
}
static int F_74 ( struct V_8 * V_9 )
{
int V_85 ;
struct V_73 * V_73 ;
int V_72 ;
V_85 = ( V_9 -> V_86 & 0xf00 ) >> 8 ;
V_73 = F_75 ( V_9 -> V_88 , L_8 ) ;
if ( F_62 ( V_73 ) ) {
F_76 ( V_9 -> V_88 , L_9 ) ;
V_72 = F_64 ( V_73 ) ;
goto V_76;
}
V_72 = F_65 ( V_73 ) ;
if ( V_72 ) {
F_76 ( V_9 -> V_88 , L_10 ) ;
goto V_76;
}
V_89 [ V_85 ] = V_73 ;
V_73 = F_75 ( V_9 -> V_88 , L_3 ) ;
if ( F_62 ( V_73 ) ) {
F_76 ( V_9 -> V_88 , L_11 ) ;
V_72 = F_64 ( V_73 ) ;
goto V_76;
}
V_72 = F_65 ( V_73 ) ;
if ( V_72 ) {
F_76 ( V_9 -> V_88 , L_12 ) ;
goto V_76;
}
V_90 [ V_85 ] = V_73 ;
return 0 ;
V_76:
if ( V_89 [ V_85 ] ) {
F_70 ( V_89 [ V_85 ] ) ;
V_89 [ V_85 ] = NULL ;
}
if ( V_90 [ V_85 ] ) {
F_70 ( V_90 [ V_85 ] ) ;
V_90 [ V_85 ] = NULL ;
}
return V_72 ;
}
static void F_77 ( struct V_8 * V_9 )
{
int V_85 ;
struct V_73 * V_73 ;
V_85 = ( V_9 -> V_86 & 0xf00 ) >> 8 ;
V_73 = V_89 [ V_85 ] ;
if ( V_73 ) {
F_70 ( V_73 ) ;
V_89 [ V_85 ] = NULL ;
}
if ( V_90 [ V_85 ] ) {
F_70 ( V_90 [ V_85 ] ) ;
V_90 [ V_85 ] = NULL ;
}
}
static int F_78 ( struct V_8 * V_9 , int V_91 )
{
int V_85 ;
struct V_73 * V_92 ;
int V_93 ;
if ( F_79 ( V_9 ) )
return 0 ;
V_85 = ( V_9 -> V_86 & 0xf00 ) >> 8 ;
V_92 = V_89 [ V_85 ] ;
if ( ! V_92 ) {
F_76 ( V_9 -> V_88 , L_13 ) ;
return - V_74 ;
}
F_80 ( V_9 -> V_88 , L_14 , V_91 ? L_15 : L_16 ) ;
if ( V_91 ) {
V_93 = F_81 ( V_92 ) ;
if ( V_93 )
F_76 ( V_9 -> V_88 , L_10 ) ;
return V_93 ;
} else {
F_82 ( V_92 ) ;
return 0 ;
}
}
static void F_83 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
V_9 -> V_51 = V_94 ;
V_9 -> V_52 = V_82 ;
}
static void F_84 ( struct V_8 * V_9 )
{
F_3 ( & F_85 ( V_9 ) -> V_5 , 0xdd ) ;
F_14 ( & F_86 ( V_9 ) -> V_53 , V_54 ) ;
F_14 ( & F_86 ( V_9 ) -> V_53 , V_55 ) ;
F_14 ( & F_86 ( V_9 ) -> V_56 , 1 ) ;
F_14 ( & F_86 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_86 ( V_9 ) -> V_58 , V_54 ) ;
F_14 ( & F_86 ( V_9 ) -> V_58 , V_55 ) ;
F_14 ( & F_86 ( V_9 ) -> V_59 , 1 ) ;
F_14 ( & F_86 ( V_9 ) -> V_60 , 0 ) ;
F_14 ( & F_86 ( V_9 ) -> V_57 , V_61 ) ;
F_14 ( & F_86 ( V_9 ) -> V_60 , V_61 ) ;
}
static int F_87 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_86 ( V_9 ) -> V_62 ) & V_63 ) ;
}
static int F_88 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_86 ( V_9 ) -> V_64 ) & V_65 ) ;
}
static int F_89 ( struct V_8 * V_9 )
{
return F_43 ( & F_86 ( V_9 ) -> V_62 ) &
F_43 ( & F_86 ( V_9 ) -> V_60 ) & V_61 ;
}
static int F_90 ( struct V_8 * V_9 )
{
return F_43 ( & F_86 ( V_9 ) -> V_64 ) &
F_43 ( & F_86 ( V_9 ) -> V_57 ) & V_61 ;
}
static int F_91 ( struct V_8 * V_9 )
{
return F_43 ( & F_86 ( V_9 ) -> V_64 ) & V_63 ;
}
static void F_92 ( struct V_8 * V_9 )
{
unsigned long V_66 ;
V_66 = F_43 ( & F_86 ( V_9 ) -> V_60 ) ;
V_66 &= ~ V_61 ;
F_14 ( & F_86 ( V_9 ) -> V_60 , V_66 ) ;
}
static void F_93 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_86 ( V_9 ) -> V_57 ) ;
V_67 |= V_61 ;
F_14 ( & F_86 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_94 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_86 ( V_9 ) -> V_57 ) ;
V_67 &= ~ V_61 ;
F_14 ( & F_86 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_95 ( struct V_8 * V_9 )
{
F_14 ( & F_86 ( V_9 ) -> V_68 , F_43 ( & F_86 ( V_9 ) -> V_68 ) ) ;
}
static void F_96 ( struct V_8 * V_9 )
{
F_14 ( & F_86 ( V_9 ) -> V_69 , F_43 ( & F_86 ( V_9 ) -> V_69 ) ) ;
}
static void F_97 ( struct V_8 * V_9 , unsigned char V_42 )
{
F_3 ( & F_86 ( V_9 ) -> V_70 , V_42 ) ;
}
static unsigned char F_98 ( struct V_8 * V_9 )
{
return F_8 ( & F_86 ( V_9 ) -> V_71 ) ;
}
static void F_99 ( struct V_8 * V_9 )
{
V_9 -> V_25 =
F_43 ( & F_86 ( V_9 ) -> V_57 ) << 16 |
F_43 ( & F_86 ( V_9 ) -> V_60 ) ;
F_14 ( & F_86 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_86 ( V_9 ) -> V_60 , 0 ) ;
}
static void F_100 ( struct V_8 * V_9 )
{
F_14 ( & F_86 ( V_9 ) -> V_57 ,
( V_9 -> V_25 >> 16 ) & 0x7f ) ;
F_14 ( & F_86 ( V_9 ) -> V_60 , V_9 -> V_25 & 0x7f ) ;
}
static inline void F_101 ( struct V_95 T_1 * V_2 ,
T_3 V_3 , unsigned int V_4 )
{
F_3 ( & V_2 -> V_5 , V_3 ) ;
F_3 ( & V_2 -> V_6 , V_4 >> 8 ) ;
F_3 ( & V_2 -> V_7 , V_4 & 0xff ) ;
}
static unsigned int F_102 ( struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned int V_47 ;
unsigned int V_4 ;
V_47 = F_34 ( V_9 , V_45 , V_46 ,
V_9 -> V_48 / ( 16 * 0xffff ) + 1 ,
V_9 -> V_48 / 16 ) ;
V_4 = ( V_9 -> V_48 + 8 * V_47 ) / ( 16 * V_47 ) ;
F_101 ( F_85 ( V_9 ) , 0xdd , V_4 ) ;
return V_47 ;
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
if ( V_18 & V_96 )
F_3 ( & F_85 ( V_9 ) -> V_19 , V_20 ) ;
else
F_3 ( & F_85 ( V_9 ) -> V_21 , V_20 ) ;
}
static void F_108 ( struct V_8 * V_9 )
{
struct V_95 T_1 * V_2 = F_85 ( V_9 ) ;
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
return V_97 -> V_98 ( V_9 ) ? V_99 : 0 ;
}
static void
F_113 ( struct V_8 * V_9 , unsigned int V_100 )
{
V_97 -> V_101 ( V_9 , V_100 & V_96 ) ;
}
static unsigned int
F_114 ( struct V_8 * V_9 )
{
unsigned int V_93 = V_102 ;
T_3 V_103 = V_97 -> V_104 ( V_9 ) ;
if ( ! ( V_103 & V_105 ) )
V_93 |= V_106 ;
if ( ! ( V_103 & V_107 ) )
V_93 |= V_108 ;
return V_93 ;
}
static void
F_115 ( struct V_8 * V_9 )
{
V_97 -> V_109 ( V_9 ) ;
}
static void
F_116 ( struct V_8 * V_9 )
{
V_97 -> V_110 ( V_9 ) ;
}
static void
F_117 ( struct V_8 * V_9 , char V_111 )
{
unsigned long V_112 ;
F_118 ( & V_9 -> V_113 , V_112 ) ;
V_9 -> V_114 = V_111 ;
if ( V_111 ) {
V_97 -> V_110 ( V_9 ) ;
}
F_119 ( & V_9 -> V_113 , V_112 ) ;
}
static void
F_120 ( struct V_8 * V_9 )
{
V_97 -> V_115 ( V_9 ) ;
}
static void
F_121 ( struct V_8 * V_9 )
{
V_97 -> V_116 ( V_9 ) ;
}
static void
F_122 ( struct V_8 * V_9 , int V_117 )
{
unsigned long V_112 ;
F_118 ( & V_9 -> V_113 , V_112 ) ;
if ( V_117 == - 1 )
V_97 -> V_13 ( V_9 , V_118 ) ;
else
V_97 -> V_13 ( V_9 , V_119 ) ;
F_119 ( & V_9 -> V_113 , V_112 ) ;
}
static int
F_123 ( struct V_8 * V_9 )
{
int V_93 ;
if ( V_97 -> clock ) {
V_93 = V_97 -> clock ( V_9 , 1 ) ;
if ( V_93 )
return V_93 ;
}
V_93 = F_124 ( V_9 -> V_52 , V_120 ,
V_9 -> V_51 , L_17 , V_9 ) ;
if ( V_93 )
return V_93 ;
V_97 -> V_13 ( V_9 , V_121 ) ;
V_97 -> V_13 ( V_9 , V_122 ) ;
V_97 -> V_123 ( V_9 , 0 ) ;
V_97 -> V_124 ( V_9 ) ;
V_97 -> V_13 ( V_9 , V_125 ) ;
V_97 -> V_13 ( V_9 , V_126 ) ;
return 0 ;
}
static void
F_125 ( struct V_8 * V_9 )
{
V_97 -> V_13 ( V_9 , V_121 ) ;
if ( ! F_79 ( V_9 ) )
V_97 -> V_13 ( V_9 , V_122 ) ;
V_9 -> V_25 = 0 ;
V_97 -> V_127 ( V_9 , V_9 -> V_25 ) ;
if ( V_97 -> clock )
V_97 -> clock ( V_9 , 0 ) ;
V_97 -> V_128 ( V_9 ) ;
F_126 ( V_9 -> V_52 , V_9 ) ;
}
static void
F_127 ( struct V_8 * V_9 , struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned long V_112 ;
unsigned char V_14 , V_15 ;
unsigned int V_129 ;
unsigned int V_47 ;
V_14 = 0 ;
switch ( V_45 -> V_130 & V_131 ) {
case V_132 : V_14 |= V_133 ;
break;
case V_134 : V_14 |= V_135 ;
break;
case V_136 : V_14 |= V_137 ;
break;
case V_138 :
default: V_14 |= V_139 ;
}
if ( V_45 -> V_130 & V_140 ) {
if ( V_45 -> V_130 & V_141 )
V_14 |= V_142 ;
V_14 |= ( V_45 -> V_130 & V_143 ) ?
V_144 : V_145 ;
} else {
V_14 |= V_146 ;
}
V_15 = 0 ;
if ( V_45 -> V_130 & V_147 )
V_15 |= V_148 ;
else
V_15 |= ( ( V_45 -> V_130 & V_131 ) == V_132 ) ?
V_149 :
V_150 ;
if ( V_45 -> V_130 & V_151 ) {
V_14 |= V_152 ;
V_15 |= V_153 ;
}
F_118 ( & V_9 -> V_113 , V_112 ) ;
V_129 = 5000000 ;
while ( ! F_112 ( V_9 ) && -- V_129 )
F_128 ( 1 ) ;
if ( ! V_129 )
F_129 ( V_154 L_18
L_19
L_20 ) ;
V_97 -> V_13 ( V_9 , V_121 ) ;
V_97 -> V_13 ( V_9 , V_122 ) ;
V_97 -> V_155 ( V_9 , V_14 , V_15 ) ;
V_47 = V_97 -> V_156 ( V_9 , V_45 , V_46 ) ;
F_130 ( V_9 , V_45 -> V_130 , V_47 ) ;
if ( F_131 ( V_9 , V_45 -> V_130 ) )
F_121 ( V_9 ) ;
V_97 -> V_13 ( V_9 , V_125 ) ;
V_97 -> V_13 ( V_9 , V_126 ) ;
F_119 ( & V_9 -> V_113 , V_112 ) ;
}
static const char *
F_132 ( struct V_8 * V_9 )
{
return V_9 -> type == V_157 ? L_21 : NULL ;
}
static void
F_133 ( struct V_8 * V_9 )
{
if ( V_97 -> V_158 )
V_97 -> V_158 ( V_9 ) ;
if ( V_9 -> V_112 & V_159 ) {
F_69 ( V_9 -> V_160 ) ;
V_9 -> V_160 = NULL ;
}
F_134 ( V_9 -> V_86 , sizeof( struct V_1 ) ) ;
}
static int
F_135 ( struct V_8 * V_9 )
{
int V_72 ;
if ( V_9 -> V_112 & V_159 )
V_9 -> V_160 = F_136 ( V_9 -> V_86 ,
sizeof( struct V_1 ) ) ;
if ( ! V_9 -> V_160 )
return - V_161 ;
V_72 = F_137 ( V_9 -> V_86 , sizeof( struct V_1 ) ,
L_17 ) != NULL ? 0 : - V_162 ;
if ( V_72 )
goto V_163;
if ( V_97 -> V_164 ) {
V_72 = V_97 -> V_164 ( V_9 ) ;
if ( V_72 )
goto V_165;
}
return 0 ;
V_165:
F_134 ( V_9 -> V_86 , sizeof( struct V_1 ) ) ;
V_163:
if ( V_9 -> V_112 & V_159 ) {
F_69 ( V_9 -> V_160 ) ;
V_9 -> V_160 = NULL ;
}
return V_72 ;
}
static void
F_138 ( struct V_8 * V_9 , int V_112 )
{
if ( ( V_112 & V_166 )
&& ( F_135 ( V_9 ) == 0 ) )
V_9 -> type = V_157 ;
}
static int
F_139 ( struct V_8 * V_9 , struct V_167 * V_168 )
{
if ( V_168 -> type != V_169 && V_168 -> type != V_157 )
return - V_161 ;
if ( ( V_168 -> V_52 != V_9 -> V_52 ) ||
( V_168 -> V_170 != V_171 ) ||
( V_168 -> V_172 != V_9 -> V_48 ) ||
( V_168 -> V_173 != ( void * ) V_9 -> V_86 ) ||
( V_168 -> V_174 != 0 ) )
return - V_161 ;
return 0 ;
}
static inline int
F_140 ( struct V_8 * V_9 )
{
struct V_175 * V_176 = & V_9 -> V_18 -> V_9 ;
unsigned char V_111 , V_177 ;
unsigned short V_103 ;
while ( V_97 -> V_178 ( V_9 ) ) {
V_111 = V_97 -> V_179 ( V_9 ) ;
#ifdef F_141
if ( F_142 ( V_9 , V_111 ) ) {
V_9 -> V_180 = 0 ;
continue;
}
#endif
V_177 = V_181 ;
V_9 -> V_182 . V_183 ++ ;
V_103 = V_97 -> V_184 ( V_9 ) ;
if ( V_103 & ( V_185 |
V_186 |
V_187 ) ) {
if ( V_103 & V_187 ) {
V_177 = V_188 ;
F_143 ( V_9 ) ;
V_9 -> V_182 . V_189 ++ ;
} else if ( V_103 & V_185 ) {
V_177 = V_190 ;
V_9 -> V_182 . V_191 ++ ;
}
else if ( V_103 & V_186 ) {
V_177 = V_192 ;
V_9 -> V_182 . V_193 ++ ;
}
V_97 -> V_13 ( V_9 , V_194 ) ;
}
F_144 ( V_176 , V_111 , V_177 ) ;
if ( V_103 & V_195 ) {
F_144 ( V_176 , 0 , V_196 ) ;
V_9 -> V_182 . V_197 ++ ;
}
}
F_145 ( & V_9 -> V_113 ) ;
F_146 ( V_176 ) ;
F_147 ( & V_9 -> V_113 ) ;
return V_97 -> V_178 ( V_9 ) ;
}
static inline int
F_148 ( struct V_8 * V_9 )
{
struct V_198 * V_199 = & V_9 -> V_18 -> V_199 ;
if ( V_9 -> V_114 ) {
V_97 -> V_200 ( V_9 , V_9 -> V_114 ) ;
V_9 -> V_182 . V_201 ++ ;
V_9 -> V_114 = 0 ;
return 1 ;
}
if ( F_149 ( V_199 ) || F_150 ( V_9 ) ) {
F_115 ( V_9 ) ;
return 0 ;
}
while ( V_97 -> V_202 ( V_9 ) ) {
V_97 -> V_200 ( V_9 , V_199 -> V_203 [ V_199 -> V_204 ] ) ;
V_199 -> V_204 = ( V_199 -> V_204 + 1 ) & ( V_205 - 1 ) ;
V_9 -> V_182 . V_201 ++ ;
if ( F_149 ( V_199 ) )
break;
}
if ( F_151 ( V_199 ) < V_206 )
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
unsigned long V_207 = V_208 ;
unsigned int V_209 ;
T_3 V_103 ;
do {
V_209 = 0 ;
V_97 -> V_210 ( V_9 ) ;
if ( V_97 -> V_211 ( V_9 ) )
V_209 |= F_140 ( V_9 ) ;
V_97 -> V_212 ( V_9 ) ;
if ( V_97 -> V_213 ( V_9 ) )
V_209 |= F_148 ( V_9 ) ;
V_103 = V_97 -> V_104 ( V_9 ) ;
if ( V_103 & V_214 )
F_153 ( V_9 , ! ( V_103 & V_107 ) ) ;
if ( V_103 & V_215 )
F_154 ( V_9 , ! ( V_103 & V_105 ) ) ;
if ( ! ( -- V_207 ) )
V_209 = 0 ;
} while ( V_209 );
return V_216 ;
}
static T_5
V_120 ( int V_52 , void * V_217 )
{
struct V_8 * V_9 = V_217 ;
T_5 V_93 ;
F_147 ( & V_9 -> V_113 ) ;
V_93 = V_97 -> V_218 ( V_9 ) ;
F_145 ( & V_9 -> V_113 ) ;
return V_93 ;
}
static void T_6
F_155 ( struct V_8 * V_9 ,
int * V_47 , int * V_191 , int * V_219 , int * V_220 )
{
unsigned char V_14 ;
F_156 ( L_22 , V_9 ) ;
V_14 = V_97 -> V_221 ( V_9 ) ;
* V_47 = V_222 ;
switch ( V_14 & V_223 ) {
case V_133 :
* V_219 = 5 ;
break;
case V_135 :
* V_219 = 6 ;
break;
case V_137 :
* V_219 = 7 ;
break;
case V_139 :
default:
* V_219 = 8 ;
}
if ( V_14 & V_146 )
* V_191 = 'n' ;
else
* V_191 = V_14 & V_144 ? 'o' : 'e' ;
}
static void
F_157 ( struct V_224 * V_225 , const char * V_226 , unsigned int V_227 )
{
struct V_8 * V_9 = & V_228 [ V_225 -> V_229 ] ;
unsigned int V_230 , V_129 ;
V_97 -> V_128 ( V_9 ) ;
V_129 = 5000000 ;
while ( ! F_112 ( V_9 ) && -- V_129 )
F_128 ( 1 ) ;
for ( V_230 = 0 ; V_230 < V_227 ; V_230 ++ , V_226 ++ ) {
if ( * V_226 == '\n' )
V_97 -> V_200 ( V_9 , '\r' ) ;
V_97 -> V_200 ( V_9 , * V_226 ) ;
V_129 = 20000 ;
while ( ! F_112 ( V_9 ) && -- V_129 )
F_128 ( 1 ) ;
}
V_97 -> V_231 ( V_9 ) ;
}
static int T_6
F_158 ( struct V_224 * V_225 , char * V_232 )
{
struct V_8 * V_9 = & V_228 [ V_225 -> V_229 ] ;
struct V_49 * V_50 = V_233 [ V_225 -> V_229 ] ;
unsigned int V_48 ;
struct V_234 V_235 ;
int V_93 ;
int V_47 = V_222 ;
int V_219 = 8 ;
int V_191 = 'n' ;
int V_220 = 'n' ;
F_156 ( L_23 ,
V_225 , V_225 -> V_229 , V_232 ) ;
if ( ( V_225 -> V_229 < 0 ) || ( V_225 -> V_229 >= V_236 ) ) {
F_156 ( L_24 , V_225 -> V_229 ) ;
return - V_161 ;
}
if ( ! V_50 ) {
F_156 ( L_25 , V_225 -> V_229 ) ;
return - V_161 ;
}
F_156 ( L_26 ,
V_225 -> V_229 , V_233 [ V_225 -> V_229 ] -> V_237 ) ;
V_93 = F_159 ( V_50 , 0 , & V_235 ) ;
if ( V_93 ) {
F_156 ( L_27 , V_225 -> V_229 ) ;
return V_93 ;
}
V_48 = F_160 ( V_50 ) ;
if ( V_48 == 0 ) {
F_156 ( L_28 ) ;
return - V_161 ;
}
F_161 ( & V_9 -> V_113 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_238 = & V_239 ;
V_9 -> V_86 = V_235 . V_240 ;
V_9 -> V_160 = F_136 ( V_235 . V_240 , sizeof( struct V_1 ) ) ;
V_9 -> V_52 = F_37 ( V_50 , 0 ) ;
if ( V_9 -> V_160 == NULL )
return - V_161 ;
F_156 ( L_29 ,
( void * ) V_9 -> V_86 , V_9 -> V_160 ,
V_9 -> V_52 , V_9 -> V_48 ) ;
if ( V_232 )
F_162 ( V_232 , & V_47 , & V_191 , & V_219 , & V_220 ) ;
else
F_155 ( V_9 , & V_47 , & V_191 , & V_219 , & V_220 ) ;
F_156 ( L_30 ,
V_47 , V_219 , V_191 , V_220 ) ;
return F_163 ( V_9 , V_225 , V_47 , V_191 , V_219 , V_220 ) ;
}
static int T_6
F_164 ( void )
{
F_165 () ;
F_166 ( & V_241 ) ;
return 0 ;
}
static int F_167 ( struct V_242 * V_243 )
{
int V_244 = - 1 ;
unsigned int V_48 ;
struct V_8 * V_9 = NULL ;
struct V_234 V_235 ;
int V_93 ;
for ( V_244 = 0 ; V_244 < V_236 ; V_244 ++ )
if ( V_233 [ V_244 ] == V_243 -> V_88 . V_245 )
break;
if ( V_244 >= V_236 )
return - V_161 ;
F_156 ( L_31 ,
V_233 [ V_244 ] -> V_237 , V_244 ) ;
V_48 = F_160 ( V_243 -> V_88 . V_245 ) ;
if ( V_48 == 0 ) {
F_80 ( & V_243 -> V_88 , L_28 ) ;
return - V_161 ;
}
V_9 = & V_228 [ V_244 ] ;
F_161 ( & V_9 -> V_113 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_246 = 512 ;
V_9 -> V_247 = V_171 ;
V_9 -> V_112 = V_248 |
( F_79 ( V_9 ) ? 0 : V_159 ) ;
V_9 -> line = V_244 ;
V_9 -> V_238 = & V_239 ;
V_9 -> V_88 = & V_243 -> V_88 ;
V_93 = F_159 ( V_243 -> V_88 . V_245 , 0 , & V_235 ) ;
if ( V_93 )
return V_93 ;
V_9 -> V_86 = V_235 . V_240 ;
if ( ! V_9 -> V_86 ) {
F_80 ( & V_243 -> V_88 , L_32 ) ;
return - V_161 ;
}
V_97 -> V_249 ( V_9 , V_243 -> V_88 . V_245 ) ;
if ( V_9 -> V_52 == 0 ) {
F_80 ( & V_243 -> V_88 , L_33 ) ;
return - V_161 ;
}
F_80 ( & V_243 -> V_88 , L_34 ,
( void * ) V_9 -> V_86 , V_9 -> V_52 , V_9 -> V_48 ) ;
V_93 = F_168 ( & V_250 , V_9 ) ;
if ( V_93 )
return V_93 ;
F_169 ( V_243 , ( void * ) V_9 ) ;
return 0 ;
}
static int
F_170 ( struct V_242 * V_243 )
{
struct V_8 * V_9 = F_171 ( V_243 ) ;
if ( V_9 )
F_172 ( & V_250 , V_9 ) ;
return 0 ;
}
static int
F_173 ( struct V_242 * V_243 , T_8 V_18 )
{
struct V_8 * V_9 = F_171 ( V_243 ) ;
if ( V_9 )
F_174 ( & V_250 , V_9 ) ;
return 0 ;
}
static int
F_175 ( struct V_242 * V_243 )
{
struct V_8 * V_9 = F_171 ( V_243 ) ;
if ( V_9 )
F_176 ( & V_250 , V_9 ) ;
return 0 ;
}
static void
F_177 ( struct V_49 * V_50 )
{
int V_230 ;
for ( V_230 = 0 ; V_230 < V_236 ; V_230 ++ ) {
if ( V_233 [ V_230 ] == NULL ) {
F_178 ( V_50 ) ;
V_233 [ V_230 ] = V_50 ;
return;
}
}
}
static void
F_165 ( void )
{
static int V_251 ;
struct V_49 * V_50 ;
const struct V_252 * V_253 ;
int V_230 ;
if ( V_251 )
return;
F_179 (np, mpc52xx_uart_of_match) {
V_253 = F_180 ( V_254 , V_50 ) ;
V_97 = V_253 -> V_255 ;
F_177 ( V_50 ) ;
}
V_251 = 1 ;
for ( V_230 = 0 ; V_230 < V_236 ; V_230 ++ ) {
if ( V_233 [ V_230 ] )
F_156 ( L_35 ,
V_233 [ V_230 ] -> V_237 , V_230 ) ;
}
}
static int T_6
F_181 ( void )
{
int V_93 ;
F_129 ( V_256 L_36 ) ;
V_93 = F_182 ( & V_250 ) ;
if ( V_93 ) {
F_129 ( V_154 L_37 ,
__FILE__ , V_93 ) ;
return V_93 ;
}
F_165 () ;
if ( V_97 && V_97 -> V_257 ) {
V_93 = V_97 -> V_257 () ;
if ( V_93 )
goto V_258;
}
V_93 = F_183 ( & V_259 ) ;
if ( V_93 ) {
F_129 ( V_154 L_38 ,
__FILE__ , V_93 ) ;
goto V_260;
}
return 0 ;
V_260:
if ( V_97 && V_97 -> V_261 )
V_97 -> V_261 () ;
V_258:
F_184 ( & V_250 ) ;
return V_93 ;
}
static void T_7
F_185 ( void )
{
if ( V_97 -> V_261 )
V_97 -> V_261 () ;
F_186 ( & V_259 ) ;
F_184 ( & V_250 ) ;
}
