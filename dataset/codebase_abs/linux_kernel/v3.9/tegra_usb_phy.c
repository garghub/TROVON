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
F_21 ( & V_2 -> V_26 , true ) ;
if ( F_18 ( V_13 + V_24 , V_27 , 0 ) < 0 )
F_4 ( L_5 , V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_28 ;
F_14 ( V_11 , V_13 + V_24 ) ;
F_19 ( 10 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_28 ;
F_14 ( V_11 , V_13 + V_24 ) ;
} else
F_21 ( & V_2 -> V_26 , false ) ;
if ( F_18 ( V_13 + V_24 , V_27 ,
V_27 ) )
F_4 ( L_5 , V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
struct V_29 * V_30 = V_2 -> V_30 ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_31 ;
F_14 ( V_11 , V_13 + V_24 ) ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_32 ) ;
V_11 |= V_33 ;
F_14 ( V_11 , V_13 + V_32 ) ;
}
V_11 = F_13 ( V_13 + V_34 ) ;
V_11 &= ~ V_35 ;
F_14 ( V_11 , V_13 + V_34 ) ;
V_11 = F_13 ( V_13 + V_36 ) ;
V_11 &= ~ ( F_24 ( ~ 0 ) | F_25 ( ~ 0 ) ) ;
V_11 |= F_24 ( V_30 -> V_37 ) ;
V_11 |= F_25 ( V_30 -> V_38 ) ;
F_14 ( V_11 , V_13 + V_36 ) ;
V_11 = F_13 ( V_13 + V_39 ) ;
V_11 &= ~ F_26 ( ~ 0 ) ;
V_11 |= F_26 ( V_30 -> V_40 ) ;
F_14 ( V_11 , V_13 + V_39 ) ;
V_11 = F_13 ( V_13 + V_41 ) ;
V_11 &= ~ F_27 ( ~ 0 ) ;
V_11 |= F_27 ( V_2 -> V_42 -> V_43 ) ;
F_14 ( V_11 , V_13 + V_41 ) ;
V_11 = F_13 ( V_13 + V_44 ) ;
V_11 &= ~ V_45 ;
F_14 ( V_11 , V_13 + V_44 ) ;
V_11 = F_13 ( V_13 + V_46 ) ;
V_11 &= ~ ( F_28 ( ~ 0 ) | F_29 ( ~ 0 ) ) ;
V_11 |= F_28 ( V_2 -> V_42 -> V_47 ) |
F_29 ( V_2 -> V_42 -> V_48 ) ;
F_14 ( V_11 , V_13 + V_46 ) ;
V_11 = F_13 ( V_13 + V_49 ) ;
V_11 &= ~ ( F_30 ( ~ 0 ) | F_31 ( ~ 0 ) ) ;
V_11 |= F_30 ( V_2 -> V_42 -> V_50 ) |
F_31 ( V_2 -> V_42 -> V_51 ) ;
F_14 ( V_11 , V_13 + V_49 ) ;
if ( V_2 -> V_52 == V_53 ) {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ ( V_54 | V_55 ) ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
F_10 ( V_2 ) ;
V_11 = F_13 ( V_13 + V_56 ) ;
V_11 &= ~ ( V_57 | V_58 |
V_59 | F_32 ( ~ 0 ) |
F_33 ( ~ 0 ) | F_34 ( ~ 0 ) |
F_35 ( ~ 0 ) ) ;
V_11 |= F_32 ( V_30 -> V_60 ) ;
V_11 |= F_33 ( V_30 -> V_61 ) ;
V_11 |= F_34 ( V_30 -> V_62 ) ;
F_14 ( V_11 , V_13 + V_56 ) ;
V_11 = F_13 ( V_13 + V_63 ) ;
V_11 &= ~ ( V_64 | V_65 |
V_66 | F_36 ( ~ 0 ) ) ;
V_11 |= F_36 ( V_30 -> V_67 ) ;
F_14 ( V_11 , V_13 + V_63 ) ;
V_11 = F_13 ( V_13 + V_68 ) ;
V_11 &= ~ V_69 ;
F_14 ( V_11 , V_13 + V_68 ) ;
V_11 = F_13 ( V_13 + V_70 ) ;
V_11 &= ~ F_37 ( ~ 0 ) ;
V_11 |= F_37 ( 0x5 ) ;
F_14 ( V_11 , V_13 + V_70 ) ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_71 ) ;
if ( V_2 -> V_52 == V_53 )
V_11 &= ~ V_72 ;
else
V_11 |= V_72 ;
F_14 ( V_11 , V_13 + V_71 ) ;
} else {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_73 ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_31 ;
F_14 ( V_11 , V_13 + V_24 ) ;
if ( V_2 -> V_5 ) {
V_11 = F_13 ( V_13 + V_32 ) ;
V_11 &= ~ V_74 ;
V_11 |= V_75 ;
F_14 ( V_11 , V_13 + V_32 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_25 ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
F_22 ( V_2 ) ;
if ( ! V_2 -> V_5 )
F_38 ( & V_2 -> V_26 , 0 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
F_20 ( V_2 ) ;
if ( V_2 -> V_52 == V_53 ) {
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ F_40 ( ~ 0 ) ;
V_11 |= V_54 | F_40 ( 5 ) ;
F_14 ( V_11 , V_13 + V_24 ) ;
}
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_31 ;
F_14 ( V_11 , V_13 + V_24 ) ;
V_11 = F_13 ( V_13 + V_68 ) ;
V_11 |= V_69 ;
F_14 ( V_11 , V_13 + V_68 ) ;
V_11 = F_13 ( V_13 + V_56 ) ;
V_11 |= V_57 | V_58 |
V_59 ;
F_14 ( V_11 , V_13 + V_56 ) ;
V_11 = F_13 ( V_13 + V_63 ) ;
V_11 |= V_64 | V_65 |
V_66 ;
F_14 ( V_11 , V_13 + V_63 ) ;
return F_17 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_34 ) ;
V_11 |= V_76 ;
F_14 ( V_11 , V_13 + V_34 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_34 ) ;
V_11 &= ~ V_76 ;
F_14 ( V_11 , V_13 + V_34 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
enum V_77 V_78 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_44 ) ;
V_11 &= ~ F_44 ( ~ 0 ) ;
if ( V_78 == V_79 )
V_11 |= V_80 ;
else
V_11 |= V_81 ;
F_14 ( V_11 , V_13 + V_44 ) ;
F_19 ( 1 ) ;
V_11 = F_13 ( V_13 + V_44 ) ;
V_11 |= V_82 ;
F_14 ( V_11 , V_13 + V_44 ) ;
F_19 ( 10 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
V_11 = F_13 ( V_13 + V_44 ) ;
V_11 &= ~ V_82 ;
F_14 ( V_11 , V_13 + V_44 ) ;
F_19 ( 10 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_83 ;
unsigned long V_11 ;
void T_1 * V_13 = V_2 -> V_7 ;
struct V_84 * V_30 = V_2 -> V_30 ;
F_47 ( V_30 -> V_85 , 0 ) ;
F_48 ( 5 ) ;
F_47 ( V_30 -> V_85 , 1 ) ;
F_11 ( V_2 -> V_86 ) ;
F_48 ( 1 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_87 ;
F_14 ( V_11 , V_13 + V_24 ) ;
V_11 = F_13 ( V_13 + V_88 ) ;
V_11 |= V_89 | V_90 ;
F_14 ( V_11 , V_13 + V_88 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_91 ;
F_14 ( V_11 , V_13 + V_24 ) ;
V_11 = 0 ;
F_14 ( V_11 , V_13 + V_92 ) ;
V_11 |= F_49 ( 4 ) ;
V_11 |= F_50 ( 4 ) ;
V_11 |= F_51 ( 4 ) ;
F_14 ( V_11 , V_13 + V_92 ) ;
F_19 ( 10 ) ;
V_11 |= V_93 ;
V_11 |= V_94 ;
V_11 |= V_95 ;
F_14 ( V_11 , V_13 + V_92 ) ;
V_83 = F_52 ( V_2 -> V_96 , 0x40 , 0x08 ) ;
if ( V_83 ) {
F_4 ( L_6 , V_4 ) ;
return V_83 ;
}
V_83 = F_52 ( V_2 -> V_96 , 0x80 , 0x0B ) ;
if ( V_83 ) {
F_4 ( L_6 , V_4 ) ;
return V_83 ;
}
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 |= V_28 ;
F_14 ( V_11 , V_13 + V_24 ) ;
F_19 ( 100 ) ;
V_11 = F_13 ( V_13 + V_24 ) ;
V_11 &= ~ V_28 ;
F_14 ( V_11 , V_13 + V_24 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_84 * V_30 = V_2 -> V_30 ;
F_54 ( V_2 -> V_86 ) ;
return F_47 ( V_30 -> V_85 , 0 ) ;
}
static int F_55 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_56 ( V_98 , struct V_1 , V_26 ) ;
struct V_84 * V_99 ;
int V_100 ;
if ( V_2 -> V_101 ) {
V_99 = V_2 -> V_30 ;
V_2 -> V_86 = F_2 ( NULL , V_99 -> V_86 ) ;
if ( F_3 ( V_2 -> V_86 ) ) {
F_4 ( L_7 , V_4 ) ;
V_100 = - V_102 ;
goto V_103;
}
if ( ! F_57 ( V_99 -> V_85 ) )
V_99 -> V_85 =
F_58 ( V_2 -> V_104 -> V_105 ,
L_8 , 0 ) ;
if ( ! F_57 ( V_99 -> V_85 ) ) {
F_4 ( L_9 , V_4 ,
V_99 -> V_85 ) ;
V_100 = - V_19 ;
goto V_103;
}
F_59 ( V_99 -> V_85 , L_10 ) ;
F_47 ( V_99 -> V_85 , 0 ) ;
V_2 -> V_96 = F_60 ( & V_106 , 0 ) ;
V_2 -> V_96 -> V_107 = V_2 -> V_7 + V_108 ;
} else {
V_100 = F_1 ( V_2 ) ;
if ( V_100 < 0 )
goto V_103;
}
return 0 ;
V_103:
F_16 ( V_2 -> V_109 ) ;
F_7 ( V_2 -> V_109 ) ;
return V_100 ;
}
static void F_61 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_56 ( V_98 , struct V_1 , V_26 ) ;
if ( V_2 -> V_101 )
F_7 ( V_2 -> V_86 ) ;
else
F_8 ( V_2 ) ;
F_16 ( V_2 -> V_109 ) ;
F_7 ( V_2 -> V_109 ) ;
F_62 ( V_2 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_101 )
return F_46 ( V_2 ) ;
else
return F_23 ( V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_101 )
return F_53 ( V_2 ) ;
else
return F_39 ( V_2 ) ;
}
static int F_65 ( struct V_97 * V_98 , int V_110 )
{
struct V_1 * V_2 = F_56 ( V_98 , struct V_1 , V_26 ) ;
if ( V_110 )
return F_64 ( V_2 ) ;
else
return F_63 ( V_2 ) ;
}
struct V_1 * F_66 ( struct V_111 * V_104 , int V_112 ,
void T_1 * V_7 , void * V_30 , enum V_113 V_114 )
{
struct V_1 * V_2 ;
unsigned long V_115 ;
int V_116 ;
int V_100 ;
struct V_117 * V_118 = V_104 -> V_105 ;
V_2 = F_67 ( sizeof( struct V_1 ) , V_119 ) ;
if ( ! V_2 )
return F_68 ( - V_10 ) ;
V_2 -> V_112 = V_112 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_52 = V_114 ;
V_2 -> V_104 = V_104 ;
V_2 -> V_5 =
F_69 ( V_118 , L_11 ) ;
V_100 = F_70 ( V_118 , L_12 , L_13 ) ;
if ( V_100 < 0 )
V_2 -> V_101 = false ;
else
V_2 -> V_101 = true ;
if ( ! V_2 -> V_30 ) {
if ( V_2 -> V_101 ) {
F_4 ( L_14 , V_4 ) ;
V_100 = - V_19 ;
goto V_120;
} else {
V_2 -> V_30 = & V_121 [ V_112 ] ;
}
}
V_2 -> V_109 = F_2 ( NULL , L_15 ) ;
if ( F_3 ( V_2 -> V_109 ) ) {
F_4 ( L_16 ) ;
V_100 = F_5 ( V_2 -> V_109 ) ;
goto V_120;
}
F_11 ( V_2 -> V_109 ) ;
V_115 = F_71 ( F_72 ( V_2 -> V_109 ) ) ;
for ( V_116 = 0 ; V_116 < F_73 ( V_122 ) ; V_116 ++ ) {
if ( V_122 [ V_116 ] . V_42 == V_115 ) {
V_2 -> V_42 = & V_122 [ V_116 ] ;
break;
}
}
if ( ! V_2 -> V_42 ) {
F_4 ( L_17 , V_115 ) ;
V_100 = - V_19 ;
goto V_103;
}
V_2 -> V_26 . V_123 = F_55 ;
V_2 -> V_26 . V_124 = F_61 ;
V_2 -> V_26 . V_125 = F_65 ;
return V_2 ;
V_103:
F_16 ( V_2 -> V_109 ) ;
F_7 ( V_2 -> V_109 ) ;
V_120:
F_62 ( V_2 ) ;
return F_68 ( V_100 ) ;
}
void F_74 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_56 ( V_98 , struct V_1 , V_26 ) ;
if ( ! V_2 -> V_101 )
F_41 ( V_2 ) ;
}
void F_75 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_56 ( V_98 , struct V_1 , V_26 ) ;
if ( ! V_2 -> V_101 )
F_42 ( V_2 ) ;
}
void F_76 ( struct V_97 * V_98 ,
enum V_77 V_78 )
{
struct V_1 * V_2 = F_56 ( V_98 , struct V_1 , V_26 ) ;
if ( ! V_2 -> V_101 )
F_43 ( V_2 , V_78 ) ;
}
void F_77 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_56 ( V_98 , struct V_1 , V_26 ) ;
if ( ! V_2 -> V_101 )
F_45 ( V_2 ) ;
}
