static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( L_1 , NULL ) ;
if ( F_3 ( V_2 -> V_3 ) ) {
F_4 ( L_2 , V_4 ) ;
return F_5 ( V_2 -> V_3 ) ;
}
if ( V_2 -> V_5 ) {
V_2 -> V_6 = V_2 -> V_7 ;
} else {
V_2 -> V_6 = F_6 ( V_8 , V_9 ) ;
if ( ! V_2 -> V_6 ) {
F_4 ( L_3 , V_4 ) ;
F_7 ( V_2 -> V_3 ) ;
return - V_10 ;
}
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
F_9 ( V_2 -> V_6 ) ;
F_7 ( V_2 -> V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned long V_11 , V_12 ;
void T_1 * V_13 = V_2 -> V_6 ;
F_11 ( V_2 -> V_3 ) ;
F_12 ( & V_14 , V_12 ) ;
if ( V_15 ++ == 0 ) {
V_11 = F_13 ( V_13 + V_16 ) ;
V_11 &= ~ ( V_17 | V_18 ) ;
F_14 ( V_11 , V_13 + V_16 ) ;
}
F_15 ( & V_14 , V_12 ) ;
F_16 ( V_2 -> V_3 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_11 , V_12 ;
void T_1 * V_13 = V_2 -> V_6 ;
if ( ! V_15 ) {
F_4 ( L_4 , V_4 ) ;
return - V_19 ;
}
F_11 ( V_2 -> V_3 ) ;
F_12 ( & V_14 , V_12 ) ;
if ( -- V_15 == 0 ) {
V_11 = F_13 ( V_13 + V_16 ) ;
V_11 |= V_17 | V_18 ;
F_14 ( V_11 , V_13 + V_16 ) ;
}
F_15 ( & V_14 , V_12 ) ;
F_16 ( V_2 -> V_3 ) ;
return 0 ;
}
static int F_18 ( void T_1 * V_20 , T_2 V_21 , T_2 V_22 )
{
unsigned long V_23 = 2000 ;
do {
if ( ( F_13 ( V_20 ) & V_21 ) == V_22 )
return 0 ;
F_19 ( 1 ) ;
V_23 -- ;
} while ( V_23 );
return - 1 ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_25 ;
F_14 ( V_11 , V_13 + V_24 ) ;
F_19 ( 10 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_25 ;
F_14 ( V_11 , V_13 + V_24 ) ;
} else
V_2 -> V_26 ( & V_2 -> V_27 , true ) ;
if ( F_18 ( V_13 + V_24 , V_28 , 0 ) < 0 )
F_4 ( L_5 , V_4 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_29 ;
F_14 ( V_11 , V_13 + V_24 ) ;
F_19 ( 10 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_29 ;
F_14 ( V_11 , V_13 + V_24 ) ;
} else
V_2 -> V_26 ( & V_2 -> V_27 , false ) ;
if ( F_18 ( V_13 + V_24 , V_28 ,
V_28 ) )
F_4 ( L_5 , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
struct V_30 * V_31 = V_2 -> V_31 ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_32 ;
F_14 ( V_11 , V_13 + V_24 ) ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_33 ) ;
V_11 |= V_34 ;
F_14 ( V_11 , V_13 + V_33 ) ;
}
V_11 = F_13 ( V_13 + V_35 ) ;
V_11 &= ~ V_36 ;
F_14 ( V_11 , V_13 + V_35 ) ;
V_11 = F_13 ( V_13 + V_37 ) ;
V_11 &= ~ ( F_23 ( ~ 0 ) | F_24 ( ~ 0 ) ) ;
V_11 |= F_23 ( V_31 -> V_38 ) ;
V_11 |= F_24 ( V_31 -> V_39 ) ;
F_14 ( V_11 , V_13 + V_37 ) ;
V_11 = F_13 ( V_13 + V_40 ) ;
V_11 &= ~ F_25 ( ~ 0 ) ;
V_11 |= F_25 ( V_31 -> V_41 ) ;
F_14 ( V_11 , V_13 + V_40 ) ;
V_11 = F_13 ( V_13 + V_42 ) ;
V_11 &= ~ F_26 ( ~ 0 ) ;
V_11 |= F_26 ( V_2 -> V_43 -> V_44 ) ;
F_14 ( V_11 , V_13 + V_42 ) ;
V_11 = F_13 ( V_13 + V_45 ) ;
V_11 &= ~ V_46 ;
F_14 ( V_11 , V_13 + V_45 ) ;
V_11 = F_13 ( V_13 + V_47 ) ;
V_11 &= ~ ( F_27 ( ~ 0 ) | F_28 ( ~ 0 ) ) ;
V_11 |= F_27 ( V_2 -> V_43 -> V_48 ) |
F_28 ( V_2 -> V_43 -> V_49 ) ;
F_14 ( V_11 , V_13 + V_47 ) ;
V_11 = F_13 ( V_13 + V_50 ) ;
V_11 &= ~ ( F_29 ( ~ 0 ) | F_30 ( ~ 0 ) ) ;
V_11 |= F_29 ( V_2 -> V_43 -> V_51 ) |
F_30 ( V_2 -> V_43 -> V_52 ) ;
F_14 ( V_11 , V_13 + V_50 ) ;
if ( V_2 -> V_53 == V_54 ) {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ ( V_55 | V_56 ) ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
F_10 ( V_2 ) ;
V_11 = F_13 ( V_13 + V_57 ) ;
V_11 &= ~ ( V_58 | V_59 |
V_60 | F_31 ( ~ 0 ) |
F_32 ( ~ 0 ) | F_33 ( ~ 0 ) |
F_34 ( ~ 0 ) ) ;
V_11 |= F_31 ( V_31 -> V_61 ) ;
V_11 |= F_32 ( V_31 -> V_62 ) ;
V_11 |= F_33 ( V_31 -> V_63 ) ;
F_14 ( V_11 , V_13 + V_57 ) ;
V_11 = F_13 ( V_13 + V_64 ) ;
V_11 &= ~ ( V_65 | V_66 |
V_67 | F_35 ( ~ 0 ) ) ;
V_11 |= F_35 ( V_31 -> V_68 ) ;
F_14 ( V_11 , V_13 + V_64 ) ;
V_11 = F_13 ( V_13 + V_69 ) ;
V_11 &= ~ V_70 ;
F_14 ( V_11 , V_13 + V_69 ) ;
V_11 = F_13 ( V_13 + V_71 ) ;
V_11 &= ~ F_36 ( ~ 0 ) ;
V_11 |= F_36 ( 0x5 ) ;
F_14 ( V_11 , V_13 + V_71 ) ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_72 ) ;
if ( V_2 -> V_53 == V_54 )
V_11 &= ~ V_73 ;
else
V_11 |= V_73 ;
F_14 ( V_11 , V_13 + V_72 ) ;
} else {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_74 ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_32 ;
F_14 ( V_11 , V_13 + V_24 ) ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_33 ) ;
V_11 &= ~ V_75 ;
V_11 |= V_76 ;
F_14 ( V_11 , V_13 + V_33 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_25 ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
F_21 ( V_2 ) ;
if ( ! V_2 -> V_5 )
V_2 -> V_77 ( & V_2 -> V_27 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
F_20 ( V_2 ) ;
if ( V_2 -> V_53 == V_54 ) {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ F_38 ( ~ 0 ) ;
V_11 |= V_55 | F_38 ( 5 ) ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_32 ;
F_14 ( V_11 , V_13 + V_24 ) ;
V_11 = F_13 ( V_13 + V_69 ) ;
V_11 |= V_70 ;
F_14 ( V_11 , V_13 + V_69 ) ;
V_11 = F_13 ( V_13 + V_57 ) ;
V_11 |= V_58 | V_59 |
V_60 ;
F_14 ( V_11 , V_13 + V_57 ) ;
V_11 = F_13 ( V_13 + V_64 ) ;
V_11 |= V_65 | V_66 |
V_67 ;
F_14 ( V_11 , V_13 + V_64 ) ;
return F_17 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_35 ) ;
V_11 |= V_78 ;
F_14 ( V_11 , V_13 + V_35 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_35 ) ;
V_11 &= ~ V_78 ;
F_14 ( V_11 , V_13 + V_35 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_45 ) ;
V_11 &= ~ F_42 ( ~ 0 ) ;
if ( V_80 == V_81 )
V_11 |= V_82 ;
else
V_11 |= V_83 ;
F_14 ( V_11 , V_13 + V_45 ) ;
F_19 ( 1 ) ;
V_11 = F_13 ( V_13 + V_45 ) ;
V_11 |= V_84 ;
F_14 ( V_11 , V_13 + V_45 ) ;
F_19 ( 10 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_45 ) ;
V_11 &= ~ V_84 ;
F_14 ( V_11 , V_13 + V_45 ) ;
F_19 ( 10 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_85 ;
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
struct V_86 * V_31 = V_2 -> V_31 ;
F_45 ( V_31 -> V_87 , 0 ) ;
F_46 ( 5 ) ;
F_45 ( V_31 -> V_87 , 1 ) ;
F_11 ( V_2 -> V_88 ) ;
F_46 ( 1 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_89 ;
F_14 ( V_11 , V_13 + V_24 ) ;
V_11 = F_13 ( V_13 + V_90 ) ;
V_11 |= V_91 | V_92 ;
F_14 ( V_11 , V_13 + V_90 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_93 ;
F_14 ( V_11 , V_13 + V_24 ) ;
V_11 = 0 ;
F_14 ( V_11 , V_13 + V_94 ) ;
V_11 |= F_47 ( 4 ) ;
V_11 |= F_48 ( 4 ) ;
V_11 |= F_49 ( 4 ) ;
F_14 ( V_11 , V_13 + V_94 ) ;
F_19 ( 10 ) ;
V_11 |= V_95 ;
V_11 |= V_96 ;
V_11 |= V_97 ;
F_14 ( V_11 , V_13 + V_94 ) ;
V_85 = F_50 ( V_2 -> V_98 , 0x40 , 0x08 ) ;
if ( V_85 ) {
F_4 ( L_6 , V_4 ) ;
return V_85 ;
}
V_85 = F_50 ( V_2 -> V_98 , 0x80 , 0x0B ) ;
if ( V_85 ) {
F_4 ( L_6 , V_4 ) ;
return V_85 ;
}
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_29 ;
F_14 ( V_11 , V_13 + V_24 ) ;
F_19 ( 100 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_29 ;
F_14 ( V_11 , V_13 + V_24 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_86 * V_31 = V_2 -> V_31 ;
F_52 ( V_2 -> V_88 ) ;
return F_45 ( V_31 -> V_87 , 0 ) ;
}
static int F_53 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_54 ( V_100 , struct V_1 , V_27 ) ;
struct V_86 * V_101 ;
int V_102 ;
if ( V_2 -> V_103 ) {
V_101 = V_2 -> V_31 ;
V_2 -> V_88 = F_2 ( NULL , V_101 -> V_88 ) ;
if ( F_3 ( V_2 -> V_88 ) ) {
F_4 ( L_7 , V_4 ) ;
V_102 = - V_104 ;
goto V_105;
}
if ( ! F_55 ( V_101 -> V_87 ) )
V_101 -> V_87 =
F_56 ( V_2 -> V_106 -> V_107 ,
L_8 , 0 ) ;
if ( ! F_55 ( V_101 -> V_87 ) ) {
F_4 ( L_9 , V_4 ,
V_101 -> V_87 ) ;
V_102 = - V_19 ;
goto V_105;
}
F_57 ( V_101 -> V_87 , L_10 ) ;
F_45 ( V_101 -> V_87 , 0 ) ;
V_2 -> V_98 = F_58 ( & V_108 , 0 ) ;
V_2 -> V_98 -> V_109 = V_2 -> V_7 + V_110 ;
} else {
V_102 = F_1 ( V_2 ) ;
if ( V_102 < 0 )
goto V_105;
}
return 0 ;
V_105:
F_16 ( V_2 -> V_111 ) ;
F_7 ( V_2 -> V_111 ) ;
return V_102 ;
}
static void F_59 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_54 ( V_100 , struct V_1 , V_27 ) ;
if ( V_2 -> V_103 )
F_7 ( V_2 -> V_88 ) ;
else
F_8 ( V_2 ) ;
F_16 ( V_2 -> V_111 ) ;
F_7 ( V_2 -> V_111 ) ;
F_60 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_103 )
return F_44 ( V_2 ) ;
else
return F_22 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_103 )
return F_51 ( V_2 ) ;
else
return F_37 ( V_2 ) ;
}
static int F_63 ( struct V_99 * V_100 , int V_112 )
{
struct V_1 * V_2 = F_54 ( V_100 , struct V_1 , V_27 ) ;
if ( V_112 )
return F_62 ( V_2 ) ;
else
return F_61 ( V_2 ) ;
}
struct V_1 * F_64 ( struct V_113 * V_106 , int V_114 ,
void T_1 * V_7 , void * V_31 , enum V_115 V_116 ,
void (* V_77)( struct V_99 * V_100 , T_3 V_117 ) ,
void (* V_26)( struct V_99 * V_100 , bool V_118 ) )
{
struct V_1 * V_2 ;
unsigned long V_119 ;
int V_120 ;
int V_102 ;
struct V_121 * V_122 = V_106 -> V_107 ;
V_2 = F_65 ( sizeof( struct V_1 ) , V_123 ) ;
if ( ! V_2 )
return F_66 ( - V_10 ) ;
V_2 -> V_114 = V_114 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_53 = V_116 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_5 =
F_67 ( V_122 , L_11 ) ;
V_2 -> V_77 = V_77 ;
V_2 -> V_26 = V_26 ;
V_102 = F_68 ( V_122 , L_12 , L_13 ) ;
if ( V_102 < 0 )
V_2 -> V_103 = false ;
else
V_2 -> V_103 = true ;
if ( ! V_2 -> V_31 ) {
if ( V_2 -> V_103 ) {
F_4 ( L_14 , V_4 ) ;
V_102 = - V_19 ;
goto V_124;
} else {
V_2 -> V_31 = & V_125 [ V_114 ] ;
}
}
V_2 -> V_111 = F_2 ( NULL , L_15 ) ;
if ( F_3 ( V_2 -> V_111 ) ) {
F_4 ( L_16 ) ;
V_102 = F_5 ( V_2 -> V_111 ) ;
goto V_124;
}
F_11 ( V_2 -> V_111 ) ;
V_119 = F_69 ( F_70 ( V_2 -> V_111 ) ) ;
for ( V_120 = 0 ; V_120 < F_71 ( V_126 ) ; V_120 ++ ) {
if ( V_126 [ V_120 ] . V_43 == V_119 ) {
V_2 -> V_43 = & V_126 [ V_120 ] ;
break;
}
}
if ( ! V_2 -> V_43 ) {
F_4 ( L_17 , V_119 ) ;
V_102 = - V_19 ;
goto V_105;
}
V_2 -> V_27 . V_127 = F_53 ;
V_2 -> V_27 . V_128 = F_59 ;
V_2 -> V_27 . V_129 = F_63 ;
return V_2 ;
V_105:
F_16 ( V_2 -> V_111 ) ;
F_7 ( V_2 -> V_111 ) ;
V_124:
F_60 ( V_2 ) ;
return F_66 ( V_102 ) ;
}
void F_72 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_54 ( V_100 , struct V_1 , V_27 ) ;
if ( ! V_2 -> V_103 )
F_39 ( V_2 ) ;
}
void F_73 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_54 ( V_100 , struct V_1 , V_27 ) ;
if ( ! V_2 -> V_103 )
F_40 ( V_2 ) ;
}
void F_74 ( struct V_99 * V_100 ,
enum V_79 V_80 )
{
struct V_1 * V_2 = F_54 ( V_100 , struct V_1 , V_27 ) ;
if ( ! V_2 -> V_103 )
F_41 ( V_2 , V_80 ) ;
}
void F_75 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_54 ( V_100 , struct V_1 , V_27 ) ;
if ( ! V_2 -> V_103 )
F_43 ( V_2 ) ;
}
