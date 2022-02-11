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
static int F_67 ( struct V_8 * V_9 )
{
int V_77 ;
char V_80 [ 16 ] ;
struct V_81 * V_81 ;
int V_82 ;
V_77 = ( V_9 -> V_78 & 0xf00 ) >> 8 ;
snprintf ( V_80 , sizeof( V_80 ) , L_5 , V_77 ) ;
V_81 = F_68 ( V_9 -> V_83 , V_80 ) ;
if ( F_69 ( V_81 ) ) {
F_70 ( V_9 -> V_83 , L_6 ) ;
return F_71 ( V_81 ) ;
}
V_82 = F_72 ( V_81 ) ;
if ( V_82 ) {
F_70 ( V_9 -> V_83 , L_7 ) ;
return V_82 ;
}
V_84 [ V_77 ] = V_81 ;
return 0 ;
}
static void F_73 ( struct V_8 * V_9 )
{
int V_77 ;
struct V_81 * V_81 ;
V_77 = ( V_9 -> V_78 & 0xf00 ) >> 8 ;
V_81 = V_84 [ V_77 ] ;
if ( V_81 ) {
F_74 ( V_81 ) ;
V_84 [ V_77 ] = NULL ;
}
}
static int F_75 ( struct V_8 * V_9 , int V_85 )
{
int V_77 ;
struct V_81 * V_86 ;
int V_87 ;
if ( F_76 ( V_9 ) )
return 0 ;
V_77 = ( V_9 -> V_78 & 0xf00 ) >> 8 ;
V_86 = V_84 [ V_77 ] ;
if ( ! V_86 ) {
F_70 ( V_9 -> V_83 , L_8 ) ;
return - V_73 ;
}
F_77 ( V_9 -> V_83 , L_9 , V_85 ? L_10 : L_11 ) ;
if ( V_85 ) {
V_87 = F_78 ( V_86 ) ;
if ( V_87 )
F_70 ( V_9 -> V_83 , L_7 ) ;
return V_87 ;
} else {
F_79 ( V_86 ) ;
return 0 ;
}
}
static void F_80 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
V_9 -> V_51 = V_88 ;
V_9 -> V_52 = V_75 ;
}
static void F_81 ( struct V_8 * V_9 )
{
F_3 ( & F_82 ( V_9 ) -> V_5 , 0xdd ) ;
F_14 ( & F_83 ( V_9 ) -> V_53 , V_54 ) ;
F_14 ( & F_83 ( V_9 ) -> V_53 , V_55 ) ;
F_14 ( & F_83 ( V_9 ) -> V_56 , 1 ) ;
F_14 ( & F_83 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_83 ( V_9 ) -> V_58 , V_54 ) ;
F_14 ( & F_83 ( V_9 ) -> V_58 , V_55 ) ;
F_14 ( & F_83 ( V_9 ) -> V_59 , 1 ) ;
F_14 ( & F_83 ( V_9 ) -> V_60 , 0 ) ;
F_14 ( & F_83 ( V_9 ) -> V_57 , V_61 ) ;
F_14 ( & F_83 ( V_9 ) -> V_60 , V_61 ) ;
}
static int F_84 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_83 ( V_9 ) -> V_62 ) & V_63 ) ;
}
static int F_85 ( struct V_8 * V_9 )
{
return ! ( F_43 ( & F_83 ( V_9 ) -> V_64 ) & V_65 ) ;
}
static int F_86 ( struct V_8 * V_9 )
{
return F_43 ( & F_83 ( V_9 ) -> V_62 ) &
F_43 ( & F_83 ( V_9 ) -> V_60 ) & V_61 ;
}
static int F_87 ( struct V_8 * V_9 )
{
return F_43 ( & F_83 ( V_9 ) -> V_64 ) &
F_43 ( & F_83 ( V_9 ) -> V_57 ) & V_61 ;
}
static int F_88 ( struct V_8 * V_9 )
{
return F_43 ( & F_83 ( V_9 ) -> V_64 ) & V_63 ;
}
static void F_89 ( struct V_8 * V_9 )
{
unsigned long V_66 ;
V_66 = F_43 ( & F_83 ( V_9 ) -> V_60 ) ;
V_66 &= ~ V_61 ;
F_14 ( & F_83 ( V_9 ) -> V_60 , V_66 ) ;
}
static void F_90 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_83 ( V_9 ) -> V_57 ) ;
V_67 |= V_61 ;
F_14 ( & F_83 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_91 ( struct V_8 * V_9 )
{
unsigned long V_67 ;
V_67 = F_43 ( & F_83 ( V_9 ) -> V_57 ) ;
V_67 &= ~ V_61 ;
F_14 ( & F_83 ( V_9 ) -> V_57 , V_67 ) ;
}
static void F_92 ( struct V_8 * V_9 )
{
F_14 ( & F_83 ( V_9 ) -> V_68 , F_43 ( & F_83 ( V_9 ) -> V_68 ) ) ;
}
static void F_93 ( struct V_8 * V_9 )
{
F_14 ( & F_83 ( V_9 ) -> V_69 , F_43 ( & F_83 ( V_9 ) -> V_69 ) ) ;
}
static void F_94 ( struct V_8 * V_9 , unsigned char V_42 )
{
F_3 ( & F_83 ( V_9 ) -> V_70 , V_42 ) ;
}
static unsigned char F_95 ( struct V_8 * V_9 )
{
return F_8 ( & F_83 ( V_9 ) -> V_71 ) ;
}
static void F_96 ( struct V_8 * V_9 )
{
V_9 -> V_25 =
F_43 ( & F_83 ( V_9 ) -> V_57 ) << 16 |
F_43 ( & F_83 ( V_9 ) -> V_60 ) ;
F_14 ( & F_83 ( V_9 ) -> V_57 , 0 ) ;
F_14 ( & F_83 ( V_9 ) -> V_60 , 0 ) ;
}
static void F_97 ( struct V_8 * V_9 )
{
F_14 ( & F_83 ( V_9 ) -> V_57 ,
( V_9 -> V_25 >> 16 ) & 0x7f ) ;
F_14 ( & F_83 ( V_9 ) -> V_60 , V_9 -> V_25 & 0x7f ) ;
}
static inline void F_98 ( struct V_89 T_1 * V_2 ,
T_3 V_3 , unsigned int V_4 )
{
F_3 ( & V_2 -> V_5 , V_3 ) ;
F_3 ( & V_2 -> V_6 , V_4 >> 8 ) ;
F_3 ( & V_2 -> V_7 , V_4 & 0xff ) ;
}
static unsigned int F_99 ( struct V_8 * V_9 ,
struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned int V_47 ;
unsigned int V_4 ;
V_47 = F_34 ( V_9 , V_45 , V_46 ,
V_9 -> V_48 / ( 16 * 0xffff ) + 1 ,
V_9 -> V_48 / 16 ) ;
V_4 = ( V_9 -> V_48 + 8 * V_47 ) / ( 16 * V_47 ) ;
F_98 ( F_82 ( V_9 ) , 0xdd , V_4 ) ;
return V_47 ;
}
static T_2 F_100 ( struct V_8 * V_9 )
{
return F_5 ( & F_82 ( V_9 ) -> V_10 ) ;
}
static T_3 F_101 ( struct V_8 * V_9 )
{
return F_8 ( & F_82 ( V_9 ) -> V_11 ) ;
}
static void F_102 ( struct V_8 * V_9 , T_3 V_12 )
{
F_3 ( & F_82 ( V_9 ) -> V_13 , V_12 ) ;
}
static void F_103 ( struct V_8 * V_9 , T_3 V_14 , T_3 V_15 )
{
F_3 ( & F_82 ( V_9 ) -> V_14 , V_14 ) ;
F_3 ( & F_82 ( V_9 ) -> V_15 , V_15 ) ;
}
static void F_104 ( struct V_8 * V_9 , int V_18 )
{
if ( V_18 & V_90 )
F_3 ( & F_82 ( V_9 ) -> V_19 , V_20 ) ;
else
F_3 ( & F_82 ( V_9 ) -> V_21 , V_20 ) ;
}
static void F_105 ( struct V_8 * V_9 )
{
struct V_89 T_1 * V_2 = F_82 ( V_9 ) ;
F_8 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_22 , V_23 | V_24 ) ;
V_9 -> V_25 |= V_26 ;
F_2 ( & V_2 -> V_27 , V_9 -> V_25 ) ;
}
static void F_106 ( struct V_8 * V_9 , T_4 V_28 )
{
F_14 ( & F_82 ( V_9 ) -> V_29 , V_28 ) ;
}
static void F_107 ( struct V_8 * V_9 , T_2 V_28 )
{
F_2 ( & F_82 ( V_9 ) -> V_27 , V_28 ) ;
}
static T_3 F_108 ( struct V_8 * V_9 )
{
return F_8 ( & F_82 ( V_9 ) -> V_14 ) ;
}
static unsigned int
F_109 ( struct V_8 * V_9 )
{
return V_91 -> V_92 ( V_9 ) ? V_93 : 0 ;
}
static void
F_110 ( struct V_8 * V_9 , unsigned int V_94 )
{
V_91 -> V_95 ( V_9 , V_94 & V_90 ) ;
}
static unsigned int
F_111 ( struct V_8 * V_9 )
{
unsigned int V_87 = V_96 ;
T_3 V_97 = V_91 -> V_98 ( V_9 ) ;
if ( ! ( V_97 & V_99 ) )
V_87 |= V_100 ;
if ( ! ( V_97 & V_101 ) )
V_87 |= V_102 ;
return V_87 ;
}
static void
F_112 ( struct V_8 * V_9 )
{
V_91 -> V_103 ( V_9 ) ;
}
static void
F_113 ( struct V_8 * V_9 )
{
V_91 -> V_104 ( V_9 ) ;
}
static void
F_114 ( struct V_8 * V_9 , char V_105 )
{
unsigned long V_106 ;
F_115 ( & V_9 -> V_107 , V_106 ) ;
V_9 -> V_108 = V_105 ;
if ( V_105 ) {
V_91 -> V_104 ( V_9 ) ;
}
F_116 ( & V_9 -> V_107 , V_106 ) ;
}
static void
F_117 ( struct V_8 * V_9 )
{
V_91 -> V_109 ( V_9 ) ;
}
static void
F_118 ( struct V_8 * V_9 )
{
V_91 -> V_110 ( V_9 ) ;
}
static void
F_119 ( struct V_8 * V_9 , int V_111 )
{
unsigned long V_106 ;
F_115 ( & V_9 -> V_107 , V_106 ) ;
if ( V_111 == - 1 )
V_91 -> V_13 ( V_9 , V_112 ) ;
else
V_91 -> V_13 ( V_9 , V_113 ) ;
F_116 ( & V_9 -> V_107 , V_106 ) ;
}
static int
F_120 ( struct V_8 * V_9 )
{
int V_87 ;
if ( V_91 -> clock ) {
V_87 = V_91 -> clock ( V_9 , 1 ) ;
if ( V_87 )
return V_87 ;
}
V_87 = F_121 ( V_9 -> V_52 , V_114 ,
V_9 -> V_51 , L_12 , V_9 ) ;
if ( V_87 )
return V_87 ;
V_91 -> V_13 ( V_9 , V_115 ) ;
V_91 -> V_13 ( V_9 , V_116 ) ;
V_91 -> V_117 ( V_9 , 0 ) ;
V_91 -> V_118 ( V_9 ) ;
V_91 -> V_13 ( V_9 , V_119 ) ;
V_91 -> V_13 ( V_9 , V_120 ) ;
return 0 ;
}
static void
F_122 ( struct V_8 * V_9 )
{
V_91 -> V_13 ( V_9 , V_115 ) ;
if ( ! F_76 ( V_9 ) )
V_91 -> V_13 ( V_9 , V_116 ) ;
V_9 -> V_25 = 0 ;
V_91 -> V_121 ( V_9 , V_9 -> V_25 ) ;
if ( V_91 -> clock )
V_91 -> clock ( V_9 , 0 ) ;
V_91 -> V_122 ( V_9 ) ;
F_123 ( V_9 -> V_52 , V_9 ) ;
}
static void
F_124 ( struct V_8 * V_9 , struct V_44 * V_45 ,
struct V_44 * V_46 )
{
unsigned long V_106 ;
unsigned char V_14 , V_15 ;
unsigned int V_123 ;
unsigned int V_47 ;
V_14 = 0 ;
switch ( V_45 -> V_124 & V_125 ) {
case V_126 : V_14 |= V_127 ;
break;
case V_128 : V_14 |= V_129 ;
break;
case V_130 : V_14 |= V_131 ;
break;
case V_132 :
default: V_14 |= V_133 ;
}
if ( V_45 -> V_124 & V_134 ) {
if ( V_45 -> V_124 & V_135 )
V_14 |= V_136 ;
V_14 |= ( V_45 -> V_124 & V_137 ) ?
V_138 : V_139 ;
} else {
V_14 |= V_140 ;
}
V_15 = 0 ;
if ( V_45 -> V_124 & V_141 )
V_15 |= V_142 ;
else
V_15 |= ( ( V_45 -> V_124 & V_125 ) == V_126 ) ?
V_143 :
V_144 ;
if ( V_45 -> V_124 & V_145 ) {
V_14 |= V_146 ;
V_15 |= V_147 ;
}
F_115 ( & V_9 -> V_107 , V_106 ) ;
V_123 = 5000000 ;
while ( ! F_109 ( V_9 ) && -- V_123 )
F_125 ( 1 ) ;
if ( ! V_123 )
F_126 ( V_148 L_13
L_14
L_15 ) ;
V_91 -> V_13 ( V_9 , V_115 ) ;
V_91 -> V_13 ( V_9 , V_116 ) ;
V_91 -> V_149 ( V_9 , V_14 , V_15 ) ;
V_47 = V_91 -> V_150 ( V_9 , V_45 , V_46 ) ;
F_127 ( V_9 , V_45 -> V_124 , V_47 ) ;
if ( F_128 ( V_9 , V_45 -> V_124 ) )
F_118 ( V_9 ) ;
V_91 -> V_13 ( V_9 , V_119 ) ;
V_91 -> V_13 ( V_9 , V_120 ) ;
F_116 ( & V_9 -> V_107 , V_106 ) ;
}
static const char *
F_129 ( struct V_8 * V_9 )
{
return V_9 -> type == V_151 ? L_16 : NULL ;
}
static void
F_130 ( struct V_8 * V_9 )
{
if ( V_91 -> V_152 )
V_91 -> V_152 ( V_9 ) ;
if ( V_9 -> V_106 & V_153 ) {
F_63 ( V_9 -> V_154 ) ;
V_9 -> V_154 = NULL ;
}
F_131 ( V_9 -> V_78 , sizeof( struct V_1 ) ) ;
}
static int
F_132 ( struct V_8 * V_9 )
{
int V_82 ;
if ( V_9 -> V_106 & V_153 )
V_9 -> V_154 = F_133 ( V_9 -> V_78 ,
sizeof( struct V_1 ) ) ;
if ( ! V_9 -> V_154 )
return - V_155 ;
V_82 = F_134 ( V_9 -> V_78 , sizeof( struct V_1 ) ,
L_12 ) != NULL ? 0 : - V_156 ;
if ( V_82 )
goto V_157;
if ( V_91 -> V_158 ) {
V_82 = V_91 -> V_158 ( V_9 ) ;
if ( V_82 )
goto V_159;
}
return 0 ;
V_159:
F_131 ( V_9 -> V_78 , sizeof( struct V_1 ) ) ;
V_157:
if ( V_9 -> V_106 & V_153 ) {
F_63 ( V_9 -> V_154 ) ;
V_9 -> V_154 = NULL ;
}
return V_82 ;
}
static void
F_135 ( struct V_8 * V_9 , int V_106 )
{
if ( ( V_106 & V_160 )
&& ( F_132 ( V_9 ) == 0 ) )
V_9 -> type = V_151 ;
}
static int
F_136 ( struct V_8 * V_9 , struct V_161 * V_162 )
{
if ( V_162 -> type != V_163 && V_162 -> type != V_151 )
return - V_155 ;
if ( ( V_162 -> V_52 != V_9 -> V_52 ) ||
( V_162 -> V_164 != V_165 ) ||
( V_162 -> V_166 != V_9 -> V_48 ) ||
( V_162 -> V_167 != ( void * ) V_9 -> V_78 ) ||
( V_162 -> V_168 != 0 ) )
return - V_155 ;
return 0 ;
}
static inline int
F_137 ( struct V_8 * V_9 )
{
struct V_169 * V_170 = & V_9 -> V_18 -> V_9 ;
unsigned char V_105 , V_171 ;
unsigned short V_97 ;
while ( V_91 -> V_172 ( V_9 ) ) {
V_105 = V_91 -> V_173 ( V_9 ) ;
#ifdef F_138
if ( F_139 ( V_9 , V_105 ) ) {
V_9 -> V_174 = 0 ;
continue;
}
#endif
V_171 = V_175 ;
V_9 -> V_176 . V_177 ++ ;
V_97 = V_91 -> V_178 ( V_9 ) ;
if ( V_97 & ( V_179 |
V_180 |
V_181 ) ) {
if ( V_97 & V_181 ) {
V_171 = V_182 ;
F_140 ( V_9 ) ;
V_9 -> V_176 . V_183 ++ ;
} else if ( V_97 & V_179 ) {
V_171 = V_184 ;
V_9 -> V_176 . V_185 ++ ;
}
else if ( V_97 & V_180 ) {
V_171 = V_186 ;
V_9 -> V_176 . V_187 ++ ;
}
V_91 -> V_13 ( V_9 , V_188 ) ;
}
F_141 ( V_170 , V_105 , V_171 ) ;
if ( V_97 & V_189 ) {
F_141 ( V_170 , 0 , V_190 ) ;
V_9 -> V_176 . V_191 ++ ;
}
}
F_142 ( & V_9 -> V_107 ) ;
F_143 ( V_170 ) ;
F_144 ( & V_9 -> V_107 ) ;
return V_91 -> V_172 ( V_9 ) ;
}
static inline int
F_145 ( struct V_8 * V_9 )
{
struct V_192 * V_193 = & V_9 -> V_18 -> V_193 ;
if ( V_9 -> V_108 ) {
V_91 -> V_194 ( V_9 , V_9 -> V_108 ) ;
V_9 -> V_176 . V_195 ++ ;
V_9 -> V_108 = 0 ;
return 1 ;
}
if ( F_146 ( V_193 ) || F_147 ( V_9 ) ) {
F_112 ( V_9 ) ;
return 0 ;
}
while ( V_91 -> V_196 ( V_9 ) ) {
V_91 -> V_194 ( V_9 , V_193 -> V_197 [ V_193 -> V_198 ] ) ;
V_193 -> V_198 = ( V_193 -> V_198 + 1 ) & ( V_199 - 1 ) ;
V_9 -> V_176 . V_195 ++ ;
if ( F_146 ( V_193 ) )
break;
}
if ( F_148 ( V_193 ) < V_200 )
F_149 ( V_9 ) ;
if ( F_146 ( V_193 ) ) {
F_112 ( V_9 ) ;
return 0 ;
}
return 1 ;
}
static T_5
F_39 ( struct V_8 * V_9 )
{
unsigned long V_201 = V_202 ;
unsigned int V_203 ;
T_3 V_97 ;
do {
V_203 = 0 ;
V_91 -> V_204 ( V_9 ) ;
if ( V_91 -> V_205 ( V_9 ) )
V_203 |= F_137 ( V_9 ) ;
V_91 -> V_206 ( V_9 ) ;
if ( V_91 -> V_207 ( V_9 ) )
V_203 |= F_145 ( V_9 ) ;
V_97 = V_91 -> V_98 ( V_9 ) ;
if ( V_97 & V_208 )
F_150 ( V_9 , ! ( V_97 & V_101 ) ) ;
if ( V_97 & V_209 )
F_151 ( V_9 , ! ( V_97 & V_99 ) ) ;
if ( ! ( -- V_201 ) )
V_203 = 0 ;
} while ( V_203 );
return V_210 ;
}
static T_5
V_114 ( int V_52 , void * V_211 )
{
struct V_8 * V_9 = V_211 ;
T_5 V_87 ;
F_144 ( & V_9 -> V_107 ) ;
V_87 = V_91 -> V_212 ( V_9 ) ;
F_142 ( & V_9 -> V_107 ) ;
return V_87 ;
}
static void T_6
F_152 ( struct V_8 * V_9 ,
int * V_47 , int * V_185 , int * V_213 , int * V_214 )
{
unsigned char V_14 ;
F_153 ( L_17 , V_9 ) ;
V_14 = V_91 -> V_215 ( V_9 ) ;
* V_47 = V_216 ;
switch ( V_14 & V_217 ) {
case V_127 :
* V_213 = 5 ;
break;
case V_129 :
* V_213 = 6 ;
break;
case V_131 :
* V_213 = 7 ;
break;
case V_133 :
default:
* V_213 = 8 ;
}
if ( V_14 & V_140 )
* V_185 = 'n' ;
else
* V_185 = V_14 & V_138 ? 'o' : 'e' ;
}
static void
F_154 ( struct V_218 * V_219 , const char * V_220 , unsigned int V_221 )
{
struct V_8 * V_9 = & V_222 [ V_219 -> V_223 ] ;
unsigned int V_224 , V_123 ;
V_91 -> V_122 ( V_9 ) ;
V_123 = 5000000 ;
while ( ! F_109 ( V_9 ) && -- V_123 )
F_125 ( 1 ) ;
for ( V_224 = 0 ; V_224 < V_221 ; V_224 ++ , V_220 ++ ) {
if ( * V_220 == '\n' )
V_91 -> V_194 ( V_9 , '\r' ) ;
V_91 -> V_194 ( V_9 , * V_220 ) ;
V_123 = 20000 ;
while ( ! F_109 ( V_9 ) && -- V_123 )
F_125 ( 1 ) ;
}
V_91 -> V_225 ( V_9 ) ;
}
static int T_6
F_155 ( struct V_218 * V_219 , char * V_226 )
{
struct V_8 * V_9 = & V_222 [ V_219 -> V_223 ] ;
struct V_49 * V_50 = V_227 [ V_219 -> V_223 ] ;
unsigned int V_48 ;
struct V_228 V_229 ;
int V_87 ;
int V_47 = V_216 ;
int V_213 = 8 ;
int V_185 = 'n' ;
int V_214 = 'n' ;
F_153 ( L_18 ,
V_219 , V_219 -> V_223 , V_226 ) ;
if ( ( V_219 -> V_223 < 0 ) || ( V_219 -> V_223 >= V_230 ) ) {
F_153 ( L_19 , V_219 -> V_223 ) ;
return - V_155 ;
}
if ( ! V_50 ) {
F_153 ( L_20 , V_219 -> V_223 ) ;
return - V_155 ;
}
F_153 ( L_21 ,
V_219 -> V_223 , V_227 [ V_219 -> V_223 ] -> V_231 ) ;
V_87 = F_156 ( V_50 , 0 , & V_229 ) ;
if ( V_87 ) {
F_153 ( L_22 , V_219 -> V_223 ) ;
return V_87 ;
}
V_48 = F_157 ( V_50 ) ;
if ( V_48 == 0 ) {
F_153 ( L_23 ) ;
return - V_155 ;
}
F_158 ( & V_9 -> V_107 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_232 = & V_233 ;
V_9 -> V_78 = V_229 . V_234 ;
V_9 -> V_154 = F_133 ( V_229 . V_234 , sizeof( struct V_1 ) ) ;
V_9 -> V_52 = F_37 ( V_50 , 0 ) ;
if ( V_9 -> V_154 == NULL )
return - V_155 ;
F_153 ( L_24 ,
( void * ) V_9 -> V_78 , V_9 -> V_154 ,
V_9 -> V_52 , V_9 -> V_48 ) ;
if ( V_226 )
F_159 ( V_226 , & V_47 , & V_185 , & V_213 , & V_214 ) ;
else
F_152 ( V_9 , & V_47 , & V_185 , & V_213 , & V_214 ) ;
F_153 ( L_25 ,
V_47 , V_213 , V_185 , V_214 ) ;
return F_160 ( V_9 , V_219 , V_47 , V_185 , V_213 , V_214 ) ;
}
static int T_6
F_161 ( void )
{
F_162 () ;
F_163 ( & V_235 ) ;
return 0 ;
}
static int F_164 ( struct V_236 * V_237 )
{
int V_238 = - 1 ;
unsigned int V_48 ;
struct V_8 * V_9 = NULL ;
struct V_228 V_229 ;
int V_87 ;
for ( V_238 = 0 ; V_238 < V_230 ; V_238 ++ )
if ( V_227 [ V_238 ] == V_237 -> V_83 . V_239 )
break;
if ( V_238 >= V_230 )
return - V_155 ;
F_153 ( L_26 ,
V_227 [ V_238 ] -> V_231 , V_238 ) ;
V_48 = F_157 ( V_237 -> V_83 . V_239 ) ;
if ( V_48 == 0 ) {
F_77 ( & V_237 -> V_83 , L_23 ) ;
return - V_155 ;
}
V_9 = & V_222 [ V_238 ] ;
F_158 ( & V_9 -> V_107 ) ;
V_9 -> V_48 = V_48 ;
V_9 -> V_240 = 512 ;
V_9 -> V_241 = V_165 ;
V_9 -> V_106 = V_242 |
( F_76 ( V_9 ) ? 0 : V_153 ) ;
V_9 -> line = V_238 ;
V_9 -> V_232 = & V_233 ;
V_9 -> V_83 = & V_237 -> V_83 ;
V_87 = F_156 ( V_237 -> V_83 . V_239 , 0 , & V_229 ) ;
if ( V_87 )
return V_87 ;
V_9 -> V_78 = V_229 . V_234 ;
if ( ! V_9 -> V_78 ) {
F_77 ( & V_237 -> V_83 , L_27 ) ;
return - V_155 ;
}
V_91 -> V_243 ( V_9 , V_237 -> V_83 . V_239 ) ;
if ( V_9 -> V_52 == 0 ) {
F_77 ( & V_237 -> V_83 , L_28 ) ;
return - V_155 ;
}
F_77 ( & V_237 -> V_83 , L_29 ,
( void * ) V_9 -> V_78 , V_9 -> V_52 , V_9 -> V_48 ) ;
V_87 = F_165 ( & V_244 , V_9 ) ;
if ( V_87 )
return V_87 ;
F_166 ( V_237 , ( void * ) V_9 ) ;
return 0 ;
}
static int
F_167 ( struct V_236 * V_237 )
{
struct V_8 * V_9 = F_168 ( V_237 ) ;
if ( V_9 )
F_169 ( & V_244 , V_9 ) ;
return 0 ;
}
static int
F_170 ( struct V_236 * V_237 , T_8 V_18 )
{
struct V_8 * V_9 = F_168 ( V_237 ) ;
if ( V_9 )
F_171 ( & V_244 , V_9 ) ;
return 0 ;
}
static int
F_172 ( struct V_236 * V_237 )
{
struct V_8 * V_9 = F_168 ( V_237 ) ;
if ( V_9 )
F_173 ( & V_244 , V_9 ) ;
return 0 ;
}
static void
F_174 ( struct V_49 * V_50 )
{
int V_224 ;
for ( V_224 = 0 ; V_224 < V_230 ; V_224 ++ ) {
if ( V_227 [ V_224 ] == NULL ) {
F_175 ( V_50 ) ;
V_227 [ V_224 ] = V_50 ;
return;
}
}
}
static void
F_162 ( void )
{
static int V_245 ;
struct V_49 * V_50 ;
const struct V_246 * V_247 ;
int V_224 ;
if ( V_245 )
return;
F_176 (np, mpc52xx_uart_of_match) {
V_247 = F_177 ( V_248 , V_50 ) ;
V_91 = V_247 -> V_249 ;
F_174 ( V_50 ) ;
}
V_245 = 1 ;
for ( V_224 = 0 ; V_224 < V_230 ; V_224 ++ ) {
if ( V_227 [ V_224 ] )
F_153 ( L_30 ,
V_227 [ V_224 ] -> V_231 , V_224 ) ;
}
}
static int T_6
F_178 ( void )
{
int V_87 ;
F_126 ( V_250 L_31 ) ;
V_87 = F_179 ( & V_244 ) ;
if ( V_87 ) {
F_126 ( V_148 L_32 ,
__FILE__ , V_87 ) ;
return V_87 ;
}
F_162 () ;
if ( V_91 && V_91 -> V_251 ) {
V_87 = V_91 -> V_251 () ;
if ( V_87 )
goto V_252;
}
V_87 = F_180 ( & V_253 ) ;
if ( V_87 ) {
F_126 ( V_148 L_33 ,
__FILE__ , V_87 ) ;
goto V_254;
}
return 0 ;
V_254:
if ( V_91 && V_91 -> V_255 )
V_91 -> V_255 () ;
V_252:
F_181 ( & V_244 ) ;
return V_87 ;
}
static void T_7
F_182 ( void )
{
if ( V_91 -> V_255 )
V_91 -> V_255 () ;
F_183 ( & V_253 ) ;
F_181 ( & V_244 ) ;
}
