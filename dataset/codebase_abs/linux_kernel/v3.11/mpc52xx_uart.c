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
struct V_49 * V_50 ;
V_50 = F_59 ( NULL , NULL ,
L_1 ) ;
if ( ! V_50 ) {
F_60 ( L_2 , V_72 ) ;
return - V_73 ;
}
V_74 = F_61 ( V_50 , 0 ) ;
if ( ! V_74 ) {
F_60 ( L_3 , V_72 ) ;
F_62 ( V_50 ) ;
return - V_73 ;
}
V_75 = F_37 ( V_50 , 0 ) ;
F_62 ( V_50 ) ;
if ( V_75 == 0 ) {
F_60 ( L_4 , V_72 ) ;
F_63 ( V_74 ) ;
return - V_73 ;
}
return 0 ;
}
static void T_7 F_64 ( void )
{
F_63 ( V_74 ) ;
}
static T_5 F_65 ( struct V_8 * V_9 )
{
unsigned long V_76 ;
int V_77 ;
V_76 = F_43 ( & V_74 -> V_76 ) ;
V_77 = ( V_9 -> V_78 & 0xf00 ) >> 8 ;
if ( F_66 ( V_77 , & V_76 ) ||
F_66 ( V_77 + 16 , & V_76 ) )
return F_39 ( V_9 ) ;
return V_79 ;
}
static int F_67 ( struct V_8 * V_9 , int V_80 )
{
struct V_81 * V_82 ;
int V_77 ;
char V_83 [ 10 ] ;
if ( F_68 ( V_9 ) )
return 0 ;
V_77 = ( V_9 -> V_78 & 0xf00 ) >> 8 ;
snprintf ( V_83 , sizeof( V_83 ) , L_5 , V_77 ) ;
V_82 = F_69 ( V_9 -> V_84 , V_83 ) ;
if ( F_70 ( V_82 ) ) {
F_71 ( V_9 -> V_84 , L_6 ) ;
return - V_73 ;
}
F_72 ( V_9 -> V_84 , L_7 , V_83 , V_80 ? L_8 : L_9 ) ;
if ( V_80 )
F_73 ( V_82 ) ;
else
F_74 ( V_82 ) ;
return 0 ;
}
static void F_75 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
V_9 -> V_51 = V_85 ;
V_9 -> V_52 = V_75 ;
}
static void F_76 ( struct V_8 * V_9 )
{
F_3 ( & F_77 ( V_9 ) -> V_5 , 0xdd ) ;
F_14 ( & F_78 ( V_9 ) -> V_53 , V_54 ) ;
F_14 ( & F_78 ( V_9 ) -> V_53 , V_55 ) ;
F_14 ( & F_78 ( V_9 ) -> V_56 , 1 ) ;
F_14 ( & F_78 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_78 ( V_9 ) -> V_58 , V_54 ) ;
F_14 ( & F_78 ( V_9 ) -> V_58 , V_55 ) ;
F_14 ( & F_78 ( V_9 ) -> V_59 , 1 ) ;
F_14 ( & F_78 ( V_9 ) -> V_60 , 0 ) ;
F_14 ( & F_78 ( V_9 ) -> V_57 , V_61 ) ;
F_14 ( & F_78 ( V_9 ) -> V_60 , V_61 ) ;
}
static int F_79 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_78 ( V_9 ) -> V_62 ) & V_63 ) ;
}
static int F_80 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_78 ( V_9 ) -> V_64 ) & V_65 ) ;
}
static int F_81 ( struct V_8 * V_9 )
{
return F_43 ( & F_78 ( V_9 ) -> V_62 ) &
F_43 ( & F_78 ( V_9 ) -> V_60 ) & V_61 ;
}
static int F_82 ( struct V_8 * V_9 )
{
return F_43 ( & F_78 ( V_9 ) -> V_64 ) &
F_43 ( & F_78 ( V_9 ) -> V_57 ) & V_61 ;
}
static int F_83 ( struct V_8 * V_9 )
{
return F_43 ( & F_78 ( V_9 ) -> V_64 ) & V_63 ;
}
static void F_84 ( struct V_8 * V_9 )
{
unsigned long V_66 ;
V_66 = F_43 ( & F_78 ( V_9 ) -> V_60 ) ;
V_66 &= ~ V_61 ;
F_14 ( & F_78 ( V_9 ) -> V_60 , V_66 ) ;
}
static void F_85 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_78 ( V_9 ) -> V_57 ) ;
V_67 |= V_61 ;
F_14 ( & F_78 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_86 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_78 ( V_9 ) -> V_57 ) ;
V_67 &= ~ V_61 ;
F_14 ( & F_78 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_87 ( struct V_8 * V_9 )
{
F_14 ( & F_78 ( V_9 ) -> V_68 , F_43 ( & F_78 ( V_9 ) -> V_68 ) ) ;
}
static void F_88 ( struct V_8 * V_9 )
{
F_14 ( & F_78 ( V_9 ) -> V_69 , F_43 ( & F_78 ( V_9 ) -> V_69 ) ) ;
}
static void F_89 ( struct V_8 * V_9 , unsigned char V_42 )
{
F_3 ( & F_78 ( V_9 ) -> V_70 , V_42 ) ;
}
static unsigned char F_90 ( struct V_8 * V_9 )
{
return F_8 ( & F_78 ( V_9 ) -> V_71 ) ;
}
static void F_91 ( struct V_8 * V_9 )
{
V_9 -> V_25 =
F_43 ( & F_78 ( V_9 ) -> V_57 ) << 16 |
F_43 ( & F_78 ( V_9 ) -> V_60 ) ;
F_14 ( & F_78 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_78 ( V_9 ) -> V_60 , 0 ) ;
}
static void F_92 ( struct V_8 * V_9 )
{
F_14 ( & F_78 ( V_9 ) -> V_57 ,
( V_9 -> V_25 >> 16 ) & 0x7f ) ;
F_14 ( & F_78 ( V_9 ) -> V_60 , V_9 -> V_25 & 0x7f ) ;
}
static inline void F_93 ( struct V_86 T_1 * V_2 ,
T_3 V_3 , unsigned int V_4 )
{
F_3 ( & V_2 -> V_5 , V_3 ) ;
F_3 ( & V_2 -> V_6 , V_4 >> 8 ) ;
F_3 ( & V_2 -> V_7 , V_4 & 0xff ) ;
}
static unsigned int F_94 ( struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned int V_47 ;
unsigned int V_4 ;
V_47 = F_34 ( V_9 , V_45 , V_46 ,
V_9 -> V_48 / ( 16 * 0xffff ) + 1 ,
V_9 -> V_48 / 16 ) ;
V_4 = ( V_9 -> V_48 + 8 * V_47 ) / ( 16 * V_47 ) ;
F_93 ( F_77 ( V_9 ) , 0xdd , V_4 ) ;
return V_47 ;
}
static T_2 F_95 ( struct V_8 * V_9 )
{
return F_5 ( & F_77 ( V_9 ) -> V_10 ) ;
}
static T_3 F_96 ( struct V_8 * V_9 )
{
return F_8 ( & F_77 ( V_9 ) -> V_11 ) ;
}
static void F_97 ( struct V_8 * V_9 , T_3 V_12 )
{
F_3 ( & F_77 ( V_9 ) -> V_13 , V_12 ) ;
}
static void F_98 ( struct V_8 * V_9 , T_3 V_14 , T_3 V_15 )
{
F_3 ( & F_77 ( V_9 ) -> V_14 , V_14 ) ;
F_3 ( & F_77 ( V_9 ) -> V_15 , V_15 ) ;
}
static void F_99 ( struct V_8 * V_9 , int V_18 )
{
if ( V_18 & V_87 )
F_3 ( & F_77 ( V_9 ) -> V_19 , V_20 ) ;
else
F_3 ( & F_77 ( V_9 ) -> V_21 , V_20 ) ;
}
static void F_100 ( struct V_8 * V_9 )
{
struct V_86 T_1 * V_2 = F_77 ( V_9 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_22 , V_23 | V_24 ) ;
V_9 -> V_25 |= V_26 ;
F_2 ( & V_2 -> V_27 , V_9 -> V_25 ) ;
}
static void F_101 ( struct V_8 * V_9 , T_4 V_28 )
{
F_14 ( & F_77 ( V_9 ) -> V_29 , V_28 ) ;
}
static void F_102 ( struct V_8 * V_9 , T_2 V_28 )
{
F_2 ( & F_77 ( V_9 ) -> V_27 , V_28 ) ;
}
static T_3 F_103 ( struct V_8 * V_9 )
{
return F_8 ( & F_77 ( V_9 ) -> V_14 ) ;
}
static unsigned int
F_104 ( struct V_8 * V_9 )
{
return V_88 -> V_89 ( V_9 ) ? V_90 : 0 ;
}
static void
F_105 ( struct V_8 * V_9 , unsigned int V_91 )
{
V_88 -> V_92 ( V_9 , V_91 & V_87 ) ;
}
static unsigned int
F_106 ( struct V_8 * V_9 )
{
unsigned int V_93 = V_94 ;
T_3 V_95 = V_88 -> V_96 ( V_9 ) ;
if ( ! ( V_95 & V_97 ) )
V_93 |= V_98 ;
if ( ! ( V_95 & V_99 ) )
V_93 |= V_100 ;
return V_93 ;
}
static void
F_107 ( struct V_8 * V_9 )
{
V_88 -> V_101 ( V_9 ) ;
}
static void
F_108 ( struct V_8 * V_9 )
{
V_88 -> V_102 ( V_9 ) ;
}
static void
F_109 ( struct V_8 * V_9 , char V_103 )
{
unsigned long V_104 ;
F_110 ( & V_9 -> V_105 , V_104 ) ;
V_9 -> V_106 = V_103 ;
if ( V_103 ) {
V_88 -> V_102 ( V_9 ) ;
}
F_111 ( & V_9 -> V_105 , V_104 ) ;
}
static void
F_112 ( struct V_8 * V_9 )
{
V_88 -> V_107 ( V_9 ) ;
}
static void
F_113 ( struct V_8 * V_9 )
{
V_88 -> V_108 ( V_9 ) ;
}
static void
F_114 ( struct V_8 * V_9 , int V_109 )
{
unsigned long V_104 ;
F_110 ( & V_9 -> V_105 , V_104 ) ;
if ( V_109 == - 1 )
V_88 -> V_13 ( V_9 , V_110 ) ;
else
V_88 -> V_13 ( V_9 , V_111 ) ;
F_111 ( & V_9 -> V_105 , V_104 ) ;
}
static int
F_115 ( struct V_8 * V_9 )
{
int V_93 ;
if ( V_88 -> clock ) {
V_93 = V_88 -> clock ( V_9 , 1 ) ;
if ( V_93 )
return V_93 ;
}
V_93 = F_116 ( V_9 -> V_52 , V_112 ,
V_9 -> V_51 , L_10 , V_9 ) ;
if ( V_93 )
return V_93 ;
V_88 -> V_13 ( V_9 , V_113 ) ;
V_88 -> V_13 ( V_9 , V_114 ) ;
V_88 -> V_115 ( V_9 , 0 ) ;
V_88 -> V_116 ( V_9 ) ;
V_88 -> V_13 ( V_9 , V_117 ) ;
V_88 -> V_13 ( V_9 , V_118 ) ;
return 0 ;
}
static void
F_117 ( struct V_8 * V_9 )
{
V_88 -> V_13 ( V_9 , V_113 ) ;
if ( ! F_68 ( V_9 ) )
V_88 -> V_13 ( V_9 , V_114 ) ;
V_9 -> V_25 = 0 ;
V_88 -> V_119 ( V_9 , V_9 -> V_25 ) ;
if ( V_88 -> clock )
V_88 -> clock ( V_9 , 0 ) ;
V_88 -> V_120 ( V_9 ) ;
F_118 ( V_9 -> V_52 , V_9 ) ;
}
static void
F_119 ( struct V_8 * V_9 , struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned long V_104 ;
unsigned char V_14 , V_15 ;
unsigned int V_121 ;
unsigned int V_47 ;
V_14 = 0 ;
switch ( V_45 -> V_122 & V_123 ) {
case V_124 : V_14 |= V_125 ;
break;
case V_126 : V_14 |= V_127 ;
break;
case V_128 : V_14 |= V_129 ;
break;
case V_130 :
default: V_14 |= V_131 ;
}
if ( V_45 -> V_122 & V_132 ) {
if ( V_45 -> V_122 & V_133 )
V_14 |= V_134 ;
V_14 |= ( V_45 -> V_122 & V_135 ) ?
V_136 : V_137 ;
} else {
V_14 |= V_138 ;
}
V_15 = 0 ;
if ( V_45 -> V_122 & V_139 )
V_15 |= V_140 ;
else
V_15 |= ( ( V_45 -> V_122 & V_123 ) == V_124 ) ?
V_141 :
V_142 ;
if ( V_45 -> V_122 & V_143 ) {
V_14 |= V_144 ;
V_15 |= V_145 ;
}
F_110 ( & V_9 -> V_105 , V_104 ) ;
V_121 = 5000000 ;
while ( ! F_104 ( V_9 ) && -- V_121 )
F_120 ( 1 ) ;
if ( ! V_121 )
F_121 ( V_146 L_11
L_12
L_13 ) ;
V_88 -> V_13 ( V_9 , V_113 ) ;
V_88 -> V_13 ( V_9 , V_114 ) ;
V_88 -> V_147 ( V_9 , V_14 , V_15 ) ;
V_47 = V_88 -> V_148 ( V_9 , V_45 , V_46 ) ;
F_122 ( V_9 , V_45 -> V_122 , V_47 ) ;
if ( F_123 ( V_9 , V_45 -> V_122 ) )
F_113 ( V_9 ) ;
V_88 -> V_13 ( V_9 , V_117 ) ;
V_88 -> V_13 ( V_9 , V_118 ) ;
F_111 ( & V_9 -> V_105 , V_104 ) ;
}
static const char *
F_124 ( struct V_8 * V_9 )
{
return V_9 -> type == V_149 ? L_14 : NULL ;
}
static void
F_125 ( struct V_8 * V_9 )
{
if ( V_9 -> V_104 & V_150 ) {
F_63 ( V_9 -> V_151 ) ;
V_9 -> V_151 = NULL ;
}
F_126 ( V_9 -> V_78 , sizeof( struct V_1 ) ) ;
}
static int
F_127 ( struct V_8 * V_9 )
{
int V_152 ;
if ( V_9 -> V_104 & V_150 )
V_9 -> V_151 = F_128 ( V_9 -> V_78 ,
sizeof( struct V_1 ) ) ;
if ( ! V_9 -> V_151 )
return - V_153 ;
V_152 = F_129 ( V_9 -> V_78 , sizeof( struct V_1 ) ,
L_10 ) != NULL ? 0 : - V_154 ;
if ( V_152 && ( V_9 -> V_104 & V_150 ) ) {
F_63 ( V_9 -> V_151 ) ;
V_9 -> V_151 = NULL ;
}
return V_152 ;
}
static void
F_130 ( struct V_8 * V_9 , int V_104 )
{
if ( ( V_104 & V_155 )
&& ( F_127 ( V_9 ) == 0 ) )
V_9 -> type = V_149 ;
}
static int
F_131 ( struct V_8 * V_9 , struct V_156 * V_157 )
{
if ( V_157 -> type != V_158 && V_157 -> type != V_149 )
return - V_153 ;
if ( ( V_157 -> V_52 != V_9 -> V_52 ) ||
( V_157 -> V_159 != V_160 ) ||
( V_157 -> V_161 != V_9 -> V_48 ) ||
( V_157 -> V_162 != ( void * ) V_9 -> V_78 ) ||
( V_157 -> V_163 != 0 ) )
return - V_153 ;
return 0 ;
}
static inline int
F_132 ( struct V_8 * V_9 )
{
struct V_164 * V_165 = & V_9 -> V_18 -> V_9 ;
unsigned char V_103 , V_166 ;
unsigned short V_95 ;
while ( V_88 -> V_167 ( V_9 ) ) {
V_103 = V_88 -> V_168 ( V_9 ) ;
#ifdef F_133
if ( F_134 ( V_9 , V_103 ) ) {
V_9 -> V_169 = 0 ;
continue;
}
#endif
V_166 = V_170 ;
V_9 -> V_171 . V_172 ++ ;
V_95 = V_88 -> V_173 ( V_9 ) ;
if ( V_95 & ( V_174 |
V_175 |
V_176 ) ) {
if ( V_95 & V_176 ) {
V_166 = V_177 ;
F_135 ( V_9 ) ;
V_9 -> V_171 . V_178 ++ ;
} else if ( V_95 & V_174 ) {
V_166 = V_179 ;
V_9 -> V_171 . V_180 ++ ;
}
else if ( V_95 & V_175 ) {
V_166 = V_181 ;
V_9 -> V_171 . V_182 ++ ;
}
V_88 -> V_13 ( V_9 , V_183 ) ;
}
F_136 ( V_165 , V_103 , V_166 ) ;
if ( V_95 & V_184 ) {
F_136 ( V_165 , 0 , V_185 ) ;
V_9 -> V_171 . V_186 ++ ;
}
}
F_137 ( & V_9 -> V_105 ) ;
F_138 ( V_165 ) ;
F_139 ( & V_9 -> V_105 ) ;
return V_88 -> V_167 ( V_9 ) ;
}
static inline int
F_140 ( struct V_8 * V_9 )
{
struct V_187 * V_188 = & V_9 -> V_18 -> V_188 ;
if ( V_9 -> V_106 ) {
V_88 -> V_189 ( V_9 , V_9 -> V_106 ) ;
V_9 -> V_171 . V_190 ++ ;
V_9 -> V_106 = 0 ;
return 1 ;
}
if ( F_141 ( V_188 ) || F_142 ( V_9 ) ) {
F_107 ( V_9 ) ;
return 0 ;
}
while ( V_88 -> V_191 ( V_9 ) ) {
V_88 -> V_189 ( V_9 , V_188 -> V_192 [ V_188 -> V_193 ] ) ;
V_188 -> V_193 = ( V_188 -> V_193 + 1 ) & ( V_194 - 1 ) ;
V_9 -> V_171 . V_190 ++ ;
if ( F_141 ( V_188 ) )
break;
}
if ( F_143 ( V_188 ) < V_195 )
F_144 ( V_9 ) ;
if ( F_141 ( V_188 ) ) {
F_107 ( V_9 ) ;
return 0 ;
}
return 1 ;
}
static T_5
F_39 ( struct V_8 * V_9 )
{
unsigned long V_196 = V_197 ;
unsigned int V_198 ;
T_3 V_95 ;
do {
V_198 = 0 ;
V_88 -> V_199 ( V_9 ) ;
if ( V_88 -> V_200 ( V_9 ) )
V_198 |= F_132 ( V_9 ) ;
V_88 -> V_201 ( V_9 ) ;
if ( V_88 -> V_202 ( V_9 ) )
V_198 |= F_140 ( V_9 ) ;
V_95 = V_88 -> V_96 ( V_9 ) ;
if ( V_95 & V_203 )
F_145 ( V_9 , ! ( V_95 & V_99 ) ) ;
if ( V_95 & V_204 )
F_146 ( V_9 , ! ( V_95 & V_97 ) ) ;
if ( ! ( -- V_196 ) )
V_198 = 0 ;
} while ( V_198 );
return V_205 ;
}
static T_5
V_112 ( int V_52 , void * V_206 )
{
struct V_8 * V_9 = V_206 ;
T_5 V_93 ;
F_139 ( & V_9 -> V_105 ) ;
V_93 = V_88 -> V_207 ( V_9 ) ;
F_137 ( & V_9 -> V_105 ) ;
return V_93 ;
}
static void T_6
F_147 ( struct V_8 * V_9 ,
int * V_47 , int * V_180 , int * V_208 , int * V_209 )
{
unsigned char V_14 ;
F_148 ( L_15 , V_9 ) ;
V_14 = V_88 -> V_210 ( V_9 ) ;
* V_47 = V_211 ;
switch ( V_14 & V_212 ) {
case V_125 :
* V_208 = 5 ;
break;
case V_127 :
* V_208 = 6 ;
break;
case V_129 :
* V_208 = 7 ;
break;
case V_131 :
default:
* V_208 = 8 ;
}
if ( V_14 & V_138 )
* V_180 = 'n' ;
else
* V_180 = V_14 & V_136 ? 'o' : 'e' ;
}
static void
F_149 ( struct V_213 * V_214 , const char * V_215 , unsigned int V_216 )
{
struct V_8 * V_9 = & V_217 [ V_214 -> V_218 ] ;
unsigned int V_219 , V_121 ;
V_88 -> V_120 ( V_9 ) ;
V_121 = 5000000 ;
while ( ! F_104 ( V_9 ) && -- V_121 )
F_120 ( 1 ) ;
for ( V_219 = 0 ; V_219 < V_216 ; V_219 ++ , V_215 ++ ) {
if ( * V_215 == '\n' )
V_88 -> V_189 ( V_9 , '\r' ) ;
V_88 -> V_189 ( V_9 , * V_215 ) ;
V_121 = 20000 ;
while ( ! F_104 ( V_9 ) && -- V_121 )
F_120 ( 1 ) ;
}
V_88 -> V_220 ( V_9 ) ;
}
static int T_6
F_150 ( struct V_213 * V_214 , char * V_221 )
{
struct V_8 * V_9 = & V_217 [ V_214 -> V_218 ] ;
struct V_49 * V_50 = V_222 [ V_214 -> V_218 ] ;
unsigned int V_48 ;
struct V_223 V_224 ;
int V_93 ;
int V_47 = V_211 ;
int V_208 = 8 ;
int V_180 = 'n' ;
int V_209 = 'n' ;
F_148 ( L_16 ,
V_214 , V_214 -> V_218 , V_221 ) ;
if ( ( V_214 -> V_218 < 0 ) || ( V_214 -> V_218 >= V_225 ) ) {
F_148 ( L_17 , V_214 -> V_218 ) ;
return - V_153 ;
}
if ( ! V_50 ) {
F_148 ( L_18 , V_214 -> V_218 ) ;
return - V_153 ;
}
F_148 ( L_19 ,
V_214 -> V_218 , V_222 [ V_214 -> V_218 ] -> V_226 ) ;
V_93 = F_151 ( V_50 , 0 , & V_224 ) ;
if ( V_93 ) {
F_148 ( L_20 , V_214 -> V_218 ) ;
return V_93 ;
}
V_48 = F_152 ( V_50 ) ;
if ( V_48 == 0 ) {
F_148 ( L_21 ) ;
return - V_153 ;
}
F_153 ( & V_9 -> V_105 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_227 = & V_228 ;
V_9 -> V_78 = V_224 . V_229 ;
V_9 -> V_151 = F_128 ( V_224 . V_229 , sizeof( struct V_1 ) ) ;
V_9 -> V_52 = F_37 ( V_50 , 0 ) ;
if ( V_9 -> V_151 == NULL )
return - V_153 ;
F_148 ( L_22 ,
( void * ) V_9 -> V_78 , V_9 -> V_151 ,
V_9 -> V_52 , V_9 -> V_48 ) ;
if ( V_221 )
F_154 ( V_221 , & V_47 , & V_180 , & V_208 , & V_209 ) ;
else
F_147 ( V_9 , & V_47 , & V_180 , & V_208 , & V_209 ) ;
F_148 ( L_23 ,
V_47 , V_208 , V_180 , V_209 ) ;
return F_155 ( V_9 , V_214 , V_47 , V_180 , V_208 , V_209 ) ;
}
static int T_6
F_156 ( void )
{
F_157 () ;
F_158 ( & V_230 ) ;
return 0 ;
}
static int F_159 ( struct V_231 * V_232 )
{
int V_233 = - 1 ;
unsigned int V_48 ;
struct V_8 * V_9 = NULL ;
struct V_223 V_224 ;
int V_93 ;
for ( V_233 = 0 ; V_233 < V_225 ; V_233 ++ )
if ( V_222 [ V_233 ] == V_232 -> V_84 . V_234 )
break;
if ( V_233 >= V_225 )
return - V_153 ;
F_148 ( L_24 ,
V_222 [ V_233 ] -> V_226 , V_233 ) ;
V_48 = F_152 ( V_232 -> V_84 . V_234 ) ;
if ( V_48 == 0 ) {
F_72 ( & V_232 -> V_84 , L_21 ) ;
return - V_153 ;
}
V_9 = & V_217 [ V_233 ] ;
F_153 ( & V_9 -> V_105 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_235 = 512 ;
V_9 -> V_236 = V_160 ;
V_9 -> V_104 = V_237 |
( F_68 ( V_9 ) ? 0 : V_150 ) ;
V_9 -> line = V_233 ;
V_9 -> V_227 = & V_228 ;
V_9 -> V_84 = & V_232 -> V_84 ;
V_93 = F_151 ( V_232 -> V_84 . V_234 , 0 , & V_224 ) ;
if ( V_93 )
return V_93 ;
V_9 -> V_78 = V_224 . V_229 ;
if ( ! V_9 -> V_78 ) {
F_72 ( & V_232 -> V_84 , L_25 ) ;
return - V_153 ;
}
V_88 -> V_238 ( V_9 , V_232 -> V_84 . V_234 ) ;
if ( V_9 -> V_52 == 0 ) {
F_72 ( & V_232 -> V_84 , L_26 ) ;
return - V_153 ;
}
F_72 ( & V_232 -> V_84 , L_27 ,
( void * ) V_9 -> V_78 , V_9 -> V_52 , V_9 -> V_48 ) ;
V_93 = F_160 ( & V_239 , V_9 ) ;
if ( V_93 )
return V_93 ;
F_161 ( V_232 , ( void * ) V_9 ) ;
return 0 ;
}
static int
F_162 ( struct V_231 * V_232 )
{
struct V_8 * V_9 = F_163 ( V_232 ) ;
if ( V_9 )
F_164 ( & V_239 , V_9 ) ;
return 0 ;
}
static int
F_165 ( struct V_231 * V_232 , T_8 V_18 )
{
struct V_8 * V_9 = (struct V_8 * ) F_163 ( V_232 ) ;
if ( V_9 )
F_166 ( & V_239 , V_9 ) ;
return 0 ;
}
static int
F_167 ( struct V_231 * V_232 )
{
struct V_8 * V_9 = (struct V_8 * ) F_163 ( V_232 ) ;
if ( V_9 )
F_168 ( & V_239 , V_9 ) ;
return 0 ;
}
static void
F_169 ( struct V_49 * V_50 )
{
int V_219 ;
for ( V_219 = 0 ; V_219 < V_225 ; V_219 ++ ) {
if ( V_222 [ V_219 ] == NULL ) {
F_170 ( V_50 ) ;
V_222 [ V_219 ] = V_50 ;
return;
}
}
}
static void
F_157 ( void )
{
static int V_240 ;
struct V_49 * V_50 ;
const struct V_241 * V_242 ;
int V_219 ;
if ( V_240 )
return;
F_171 (np, mpc52xx_uart_of_match) {
V_242 = F_172 ( V_243 , V_50 ) ;
V_88 = V_242 -> V_244 ;
F_169 ( V_50 ) ;
}
V_240 = 1 ;
for ( V_219 = 0 ; V_219 < V_225 ; V_219 ++ ) {
if ( V_222 [ V_219 ] )
F_148 ( L_28 ,
V_222 [ V_219 ] -> V_226 , V_219 ) ;
}
}
static int T_6
F_173 ( void )
{
int V_93 ;
F_121 ( V_245 L_29 ) ;
V_93 = F_174 ( & V_239 ) ;
if ( V_93 ) {
F_121 ( V_146 L_30 ,
__FILE__ , V_93 ) ;
return V_93 ;
}
F_157 () ;
if ( V_88 && V_88 -> V_246 ) {
V_93 = V_88 -> V_246 () ;
if ( V_93 )
goto V_247;
}
V_93 = F_175 ( & V_248 ) ;
if ( V_93 ) {
F_121 ( V_146 L_31 ,
__FILE__ , V_93 ) ;
goto V_249;
}
return 0 ;
V_249:
if ( V_88 && V_88 -> V_250 )
V_88 -> V_250 () ;
V_247:
F_176 ( & V_239 ) ;
return V_93 ;
}
static void T_7
F_177 ( void )
{
if ( V_88 -> V_250 )
V_88 -> V_250 () ;
F_178 ( & V_248 ) ;
F_176 ( & V_239 ) ;
}
