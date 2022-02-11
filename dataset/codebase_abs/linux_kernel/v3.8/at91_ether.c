static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
T_2 V_6 ;
int V_7 ;
V_4 -> V_8 = F_3 ( & V_4 -> V_9 -> V_2 ,
V_10 * sizeof( struct V_11 ) ,
& V_4 -> V_12 , V_13 ) ;
if ( ! V_4 -> V_8 ) {
F_4 ( V_2 , L_1 ) ;
return - V_14 ;
}
V_4 -> V_15 = F_3 ( & V_4 -> V_9 -> V_2 ,
V_10 * V_16 ,
& V_4 -> V_17 , V_13 ) ;
if ( ! V_4 -> V_15 ) {
F_4 ( V_2 , L_2 ) ;
F_5 ( & V_4 -> V_9 -> V_2 ,
V_10 * sizeof( struct V_11 ) ,
V_4 -> V_8 , V_4 -> V_12 ) ;
V_4 -> V_8 = NULL ;
return - V_14 ;
}
V_5 = V_4 -> V_17 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
V_4 -> V_8 [ V_7 ] . V_5 = V_5 ;
V_4 -> V_8 [ V_7 ] . V_18 = 0 ;
V_5 += V_16 ;
}
V_4 -> V_8 [ V_10 - 1 ] . V_5 |= F_6 ( V_19 ) ;
V_4 -> V_20 = 0 ;
F_7 ( V_4 , V_21 , V_4 -> V_12 ) ;
V_6 = F_8 ( V_4 , V_22 ) ;
F_7 ( V_4 , V_22 , V_6 | F_6 ( V_23 ) | F_6 ( V_24 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_6 ;
int V_25 ;
V_6 = F_8 ( V_4 , V_22 ) ;
F_7 ( V_4 , V_22 , V_6 | F_6 ( V_26 ) ) ;
F_10 ( V_4 ) ;
V_25 = F_1 ( V_2 ) ;
if ( V_25 )
return V_25 ;
F_7 ( V_4 , V_27 , F_6 ( V_28 ) |
F_6 ( V_29 ) |
F_6 ( V_30 ) |
F_6 ( V_31 ) |
F_6 ( V_32 ) |
F_6 ( V_33 ) |
F_6 ( V_34 ) ) ;
F_11 ( V_4 -> V_35 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_6 = F_8 ( V_4 , V_22 ) ;
F_7 ( V_4 , V_22 , V_6 & ~ ( F_6 ( V_24 ) | F_6 ( V_23 ) ) ) ;
F_7 ( V_4 , V_36 , F_6 ( V_28 ) |
F_6 ( V_29 ) |
F_6 ( V_30 ) |
F_6 ( V_31 ) |
F_6 ( V_32 ) |
F_6 ( V_33 ) |
F_6 ( V_34 ) ) ;
F_14 ( V_2 ) ;
F_5 ( & V_4 -> V_9 -> V_2 ,
V_10 * sizeof( struct V_11 ) ,
V_4 -> V_8 , V_4 -> V_12 ) ;
V_4 -> V_8 = NULL ;
F_5 ( & V_4 -> V_9 -> V_2 ,
V_10 * V_16 ,
V_4 -> V_15 , V_4 -> V_17 ) ;
V_4 -> V_15 = NULL ;
return 0 ;
}
static int F_15 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_8 ( V_4 , V_39 ) & F_6 ( V_40 ) ) {
F_14 ( V_2 ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_41 = V_38 -> V_42 ;
V_4 -> V_43 = F_16 ( NULL , V_38 -> V_44 , V_38 -> V_42 ,
V_45 ) ;
F_7 ( V_4 , V_46 , V_4 -> V_43 ) ;
F_7 ( V_4 , V_47 , V_38 -> V_42 ) ;
} else {
F_4 ( V_2 , L_3 , V_48 ) ;
return V_49 ;
}
return V_50 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char * V_51 ;
struct V_37 * V_38 ;
unsigned int V_52 ;
while ( V_4 -> V_8 [ V_4 -> V_20 ] . V_5 & F_6 ( V_53 ) ) {
V_51 = V_4 -> V_15 + V_4 -> V_20 * V_16 ;
V_52 = F_18 ( V_54 , V_4 -> V_8 [ V_4 -> V_20 ] . V_18 ) ;
V_38 = F_19 ( V_2 , V_52 + 2 ) ;
if ( V_38 ) {
F_20 ( V_38 , 2 ) ;
memcpy ( F_21 ( V_38 , V_52 ) , V_51 , V_52 ) ;
V_38 -> V_55 = F_22 ( V_38 , V_2 ) ;
V_4 -> V_56 . V_57 ++ ;
V_4 -> V_56 . V_58 += V_52 ;
F_23 ( V_38 ) ;
} else {
V_4 -> V_56 . V_59 ++ ;
F_24 ( V_2 , L_4 ) ;
}
if ( V_4 -> V_8 [ V_4 -> V_20 ] . V_18 & F_6 ( V_60 ) )
V_4 -> V_56 . V_61 ++ ;
V_4 -> V_8 [ V_4 -> V_20 ] . V_5 &= ~ F_6 ( V_53 ) ;
if ( V_4 -> V_20 == V_10 - 1 )
V_4 -> V_20 = 0 ;
else
V_4 -> V_20 ++ ;
}
}
static T_3 F_25 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_64 , V_6 ;
V_64 = F_8 ( V_4 , V_65 ) ;
if ( V_64 & F_6 ( V_28 ) )
F_17 ( V_2 ) ;
if ( V_64 & F_6 ( V_32 ) ) {
if ( V_64 & ( F_6 ( V_30 ) | F_6 ( V_31 ) ) )
V_4 -> V_56 . V_66 ++ ;
if ( V_4 -> V_38 ) {
F_26 ( V_4 -> V_38 ) ;
V_4 -> V_38 = NULL ;
F_27 ( NULL , V_4 -> V_43 , V_4 -> V_41 , V_45 ) ;
V_4 -> V_56 . V_67 ++ ;
V_4 -> V_56 . V_68 += V_4 -> V_41 ;
}
F_28 ( V_2 ) ;
}
if ( V_64 & F_6 ( V_29 ) ) {
V_6 = F_8 ( V_4 , V_22 ) ;
F_7 ( V_4 , V_22 , V_6 & ~ F_6 ( V_23 ) ) ;
F_7 ( V_4 , V_22 , V_6 | F_6 ( V_23 ) ) ;
}
if ( V_64 & F_6 ( V_33 ) )
F_4 ( V_2 , L_5 ) ;
return V_69 ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned long V_70 ;
F_30 ( V_70 ) ;
F_25 ( V_2 -> V_62 , V_2 ) ;
F_31 ( V_70 ) ;
}
static int F_32 ( struct V_71 * V_9 )
{
struct V_72 * V_73 = V_9 -> V_2 . V_74 ;
if ( V_73 )
return F_33 ( V_73 ) ;
return - V_75 ;
}
static int F_34 ( struct V_3 * V_76 )
{
struct V_72 * V_73 = V_76 -> V_9 -> V_2 . V_74 ;
if ( V_73 ) {
const char * V_77 = F_35 ( V_73 ) ;
if ( V_77 ) {
memcpy ( V_76 -> V_2 -> V_78 , V_77 , V_79 ) ;
return 0 ;
}
}
return - V_75 ;
}
static int F_32 ( struct V_71 * V_9 )
{
return - V_75 ;
}
static int F_34 ( struct V_3 * V_76 )
{
return - V_75 ;
}
static int T_4 F_36 ( struct V_71 * V_9 )
{
struct V_80 * V_81 = V_9 -> V_2 . V_82 ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
struct V_85 * V_86 ;
struct V_87 * V_87 ;
struct V_3 * V_4 ;
int V_88 ;
T_2 V_89 ;
V_84 = F_37 ( V_9 , V_90 , 0 ) ;
if ( ! V_84 )
return - V_91 ;
V_87 = F_38 ( & V_9 -> V_2 ) ;
if ( F_39 ( V_87 ) ) {
V_88 = F_40 ( V_87 ) ;
if ( V_88 == - V_92 )
return V_88 ;
F_41 ( & V_9 -> V_2 , L_6 ) ;
}
V_2 = F_42 ( sizeof( struct V_3 ) ) ;
if ( ! V_2 )
return - V_14 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_2 = V_2 ;
F_43 ( & V_4 -> V_93 ) ;
V_2 -> V_94 = V_84 -> V_95 ;
V_4 -> V_84 = F_44 ( & V_9 -> V_2 , V_84 -> V_95 , F_45 ( V_84 ) ) ;
if ( ! V_4 -> V_84 ) {
V_88 = - V_14 ;
goto V_96;
}
V_4 -> V_97 = F_46 ( & V_9 -> V_2 , L_7 ) ;
if ( F_39 ( V_4 -> V_97 ) ) {
V_88 = F_40 ( V_4 -> V_97 ) ;
goto V_96;
}
F_47 ( V_4 -> V_97 ) ;
V_2 -> V_62 = F_48 ( V_9 , 0 ) ;
V_88 = F_49 ( & V_9 -> V_2 , V_2 -> V_62 , F_25 , 0 , V_2 -> V_98 , V_2 ) ;
if ( V_88 )
goto V_99;
F_50 ( V_2 ) ;
V_2 -> V_100 = & V_101 ;
V_2 -> V_102 = & V_103 ;
F_51 ( V_9 , V_2 ) ;
F_52 ( V_2 , & V_9 -> V_2 ) ;
V_88 = F_34 ( V_4 ) ;
if ( V_88 < 0 )
F_53 ( V_4 ) ;
V_88 = F_32 ( V_9 ) ;
if ( V_88 < 0 ) {
if ( V_81 && V_81 -> V_104 )
V_4 -> V_105 = V_106 ;
else
V_4 -> V_105 = V_107 ;
} else {
V_4 -> V_105 = V_88 ;
}
F_7 ( V_4 , V_22 , 0 ) ;
V_89 = F_18 ( V_108 , V_109 ) | F_6 ( V_110 ) ;
if ( V_4 -> V_105 == V_106 )
V_89 |= F_6 ( V_111 ) ;
F_7 ( V_4 , V_112 , V_89 ) ;
V_88 = F_54 ( V_2 ) ;
if ( V_88 )
goto V_99;
if ( F_55 ( V_4 ) != 0 )
goto V_113;
F_56 ( V_2 ) ;
V_86 = V_4 -> V_35 ;
F_57 ( V_2 , L_8 ,
V_86 -> V_114 -> V_98 , F_58 ( & V_86 -> V_2 ) ,
V_86 -> V_62 ) ;
F_57 ( V_2 , L_9 ,
V_2 -> V_94 , V_2 -> V_62 , V_2 -> V_78 ) ;
return 0 ;
V_113:
F_59 ( V_2 ) ;
V_99:
F_60 ( V_4 -> V_97 ) ;
V_96:
F_61 ( V_2 ) ;
return V_88 ;
}
static int F_62 ( struct V_71 * V_9 )
{
struct V_1 * V_2 = F_63 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_35 )
F_64 ( V_4 -> V_35 ) ;
F_65 ( V_4 -> V_115 ) ;
F_66 ( V_4 -> V_115 -> V_62 ) ;
F_67 ( V_4 -> V_115 ) ;
F_59 ( V_2 ) ;
F_60 ( V_4 -> V_97 ) ;
F_61 ( V_2 ) ;
F_51 ( V_9 , NULL ) ;
return 0 ;
}
static int F_68 ( struct V_71 * V_9 , T_5 V_116 )
{
struct V_1 * V_117 = F_63 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_117 ) ;
if ( F_69 ( V_117 ) ) {
F_14 ( V_117 ) ;
F_70 ( V_117 ) ;
F_60 ( V_4 -> V_97 ) ;
}
return 0 ;
}
static int F_71 ( struct V_71 * V_9 )
{
struct V_1 * V_117 = F_63 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_117 ) ;
if ( F_69 ( V_117 ) ) {
F_47 ( V_4 -> V_97 ) ;
F_72 ( V_117 ) ;
F_12 ( V_117 ) ;
}
return 0 ;
}
static int T_4 F_73 ( void )
{
return F_74 ( & V_118 , F_36 ) ;
}
static void T_6 F_75 ( void )
{
F_76 ( & V_118 ) ;
}
