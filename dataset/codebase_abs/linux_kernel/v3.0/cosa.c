static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static int T_1 F_3 ( void )
{
int V_5 , V_6 = 0 ;
if ( V_7 > 0 ) {
if ( F_4 ( V_7 , L_1 , & V_8 ) ) {
F_5 ( V_9 L_2 ,
V_7 ) ;
V_6 = - V_10 ;
goto V_11;
}
} else {
if ( ! ( V_7 = F_4 ( 0 , L_1 , & V_8 ) ) ) {
F_5 ( V_9 L_3 ) ;
V_6 = - V_10 ;
goto V_11;
}
}
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ )
V_13 [ V_5 ] . V_14 = - 1 ;
for ( V_5 = 0 ; V_15 [ V_5 ] != 0 && V_5 < V_12 ; V_5 ++ )
F_6 ( V_15 [ V_5 ] , V_16 [ V_5 ] , V_17 [ V_5 ] ) ;
if ( ! V_18 ) {
F_5 ( V_9 L_4 ) ;
F_7 ( V_7 , L_1 ) ;
V_6 = - V_19 ;
goto V_11;
}
V_20 = F_8 ( V_21 , L_1 ) ;
if ( F_9 ( V_20 ) ) {
V_6 = F_10 ( V_20 ) ;
goto V_22;
}
for ( V_5 = 0 ; V_5 < V_18 ; V_5 ++ )
F_11 ( V_20 , NULL , F_12 ( V_7 , V_5 ) , NULL ,
L_5 , V_5 ) ;
V_6 = 0 ;
goto V_11;
V_22:
F_7 ( V_7 , L_1 ) ;
V_11:
return V_6 ;
}
static void T_2 F_13 ( void )
{
struct V_23 * V_24 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 ; V_5 ++ )
F_14 ( V_20 , F_12 ( V_7 , V_5 ) ) ;
F_15 ( V_20 ) ;
for ( V_24 = V_13 ; V_18 -- ; V_24 ++ ) {
for ( V_5 = 0 ; V_5 < V_24 -> V_25 ; V_5 ++ ) {
F_16 ( V_24 -> V_26 [ V_5 ] . V_27 ) ;
F_17 ( V_24 -> V_26 [ V_5 ] . V_27 ) ;
}
F_18 ( V_24 -> V_26 ) ;
F_18 ( V_24 -> V_28 ) ;
F_19 ( V_24 -> V_16 , V_24 ) ;
F_20 ( V_24 -> V_17 ) ;
F_21 ( V_24 -> V_29 , F_22 ( V_24 ) ? 2 : 4 ) ;
}
F_7 ( V_7 , L_1 ) ;
}
static int F_6 ( int V_30 , int V_16 , int V_17 )
{
struct V_23 * V_24 = V_13 + V_18 ;
int V_5 , V_6 = 0 ;
memset ( V_24 , 0 , sizeof( struct V_23 ) ) ;
if ( ( V_16 >= 0 && V_16 < 2 ) || V_16 > 15 || ( V_16 < 10 && V_16 > 7 ) ) {
F_5 ( V_31 L_6 , V_16 ) ;
return - 1 ;
}
if ( V_30 < 0x100 || V_30 > 0x3ff || V_30 & 0x7 ) {
F_5 ( V_31 L_7 ,
V_30 ) ;
return - 1 ;
}
if ( V_17 < 0 || V_17 == 4 || V_17 > 7 ) {
F_5 ( V_31 L_8 , V_17 ) ;
return - 1 ;
}
if ( ( ( V_30 & 0x8 ) && V_17 < 4 ) || ( ! ( V_30 & 0x8 ) && V_17 > 3 ) ) {
F_5 ( V_31 L_9
L_10 , V_30 , V_17 ) ;
return - 1 ;
}
V_24 -> V_17 = V_17 ;
V_24 -> V_29 = V_30 ;
V_24 -> V_32 = F_22 ( V_24 ) ? V_30 + 1 : V_30 + 2 ;
F_23 ( & V_24 -> V_33 ) ;
if ( ! F_24 ( V_30 , F_22 ( V_24 ) ? 2 : 4 , L_1 ) )
return - 1 ;
if ( F_25 ( V_24 , V_24 -> V_34 ) < 0 ) {
F_5 ( V_35 L_11 , V_30 ) ;
V_6 = - 1 ;
goto V_36;
}
if ( ! strncmp ( V_24 -> V_34 , L_12 , 3 ) )
V_24 -> type = L_13 ;
else if ( ! strncmp ( V_24 -> V_34 , L_14 , 4 ) )
V_24 -> type = F_22 ( V_24 ) ? L_15 : L_16 ;
else {
#ifndef F_26
F_5 ( V_31 L_17 ,
V_30 ) ;
#endif
V_6 = - 1 ;
goto V_36;
}
F_21 ( V_30 , F_22 ( V_24 ) ? 2 : 4 ) ;
if ( ! F_24 ( V_30 , F_22 ( V_24 ) ? 2 : 4 , V_24 -> type ) ) {
F_5 ( V_35 L_18 , V_30 ) ;
return - 1 ;
}
if ( V_16 < 0 ) {
unsigned long V_37 ;
V_37 = F_27 () ;
F_28 ( V_38 ) ;
F_29 ( V_24 , V_39 ) ;
F_30 ( 30 ) ;
V_16 = F_31 ( V_37 ) ;
F_29 ( V_24 , 0 ) ;
F_32 ( V_24 ) ;
if ( V_16 < 0 ) {
F_5 ( V_31 L_19 ,
V_16 , V_24 -> V_29 ) ;
V_6 = - 1 ;
goto V_36;
}
if ( V_16 == 0 ) {
F_5 ( V_31 L_20 ,
V_24 -> V_29 ) ;
}
}
V_24 -> V_16 = V_16 ;
V_24 -> V_14 = V_18 ;
V_24 -> V_40 = 0 ;
V_24 -> V_25 = 2 ;
if ( F_33 ( V_24 -> V_16 , V_41 , 0 , V_24 -> type , V_24 ) ) {
V_6 = - 1 ;
goto V_36;
}
if ( F_34 ( V_24 -> V_17 , V_24 -> type ) ) {
V_6 = - 1 ;
goto V_42;
}
V_24 -> V_28 = F_35 ( V_43 , V_44 | V_45 ) ;
if ( ! V_24 -> V_28 ) {
V_6 = - V_46 ;
goto V_47;
}
sprintf ( V_24 -> V_48 , L_5 , V_24 -> V_14 ) ;
V_24 -> V_26 = F_36 ( V_24 -> V_25 , sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_24 -> V_26 ) {
V_6 = - V_46 ;
goto V_49;
}
for ( V_5 = 0 ; V_5 < V_24 -> V_25 ; V_5 ++ ) {
struct V_1 * V_26 = & V_24 -> V_26 [ V_5 ] ;
V_26 -> V_24 = V_24 ;
V_26 -> V_14 = V_5 ;
sprintf ( V_26 -> V_48 , L_21 , V_26 -> V_24 -> V_14 , V_5 ) ;
F_37 ( & V_26 -> V_50 ) ;
F_38 ( & V_26 -> V_51 , 1 ) ;
if ( ! ( V_26 -> V_27 = F_39 ( V_26 ) ) ) {
F_5 ( V_9 L_22 ,
V_26 -> V_48 ) ;
goto V_52;
}
F_2 ( V_26 -> V_27 ) -> V_53 = V_54 ;
F_2 ( V_26 -> V_27 ) -> V_55 = V_56 ;
V_26 -> V_27 -> V_57 = & V_58 ;
V_26 -> V_27 -> V_59 = V_60 ;
V_26 -> V_27 -> V_61 = V_26 -> V_24 -> V_29 ;
V_26 -> V_27 -> V_16 = V_26 -> V_24 -> V_16 ;
V_26 -> V_27 -> V_17 = V_26 -> V_24 -> V_17 ;
if ( F_40 ( V_26 -> V_27 ) ) {
F_5 ( V_9 L_23
L_24 , V_26 -> V_27 -> V_48 ) ;
F_17 ( V_26 -> V_27 ) ;
goto V_52;
}
}
F_5 ( V_31 L_25 ,
V_24 -> V_14 , V_24 -> V_34 , V_24 -> type ,
V_24 -> V_29 , V_24 -> V_16 , V_24 -> V_17 , V_24 -> V_25 ) ;
return V_18 ++ ;
V_52:
while ( V_5 -- > 0 ) {
F_16 ( V_24 -> V_26 [ V_5 ] . V_27 ) ;
F_17 ( V_24 -> V_26 [ V_5 ] . V_27 ) ;
}
F_18 ( V_24 -> V_26 ) ;
V_49:
F_18 ( V_24 -> V_28 ) ;
V_47:
F_20 ( V_24 -> V_17 ) ;
V_42:
F_19 ( V_24 -> V_16 , V_24 ) ;
V_36:
F_21 ( V_24 -> V_29 , F_22 ( V_24 ) ? 2 : 4 ) ;
F_5 ( V_62 L_26 ,
V_24 -> V_14 ) ;
return V_6 ;
}
static int V_54 ( struct V_2 * V_3 , unsigned short V_63 ,
unsigned short V_64 )
{
if ( V_63 == V_65 && V_64 == V_66 )
return 0 ;
return - V_67 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_26 = F_1 ( V_3 ) ;
int V_6 ;
unsigned long V_68 ;
if ( ! ( V_26 -> V_24 -> V_69 & V_70 ) ) {
F_5 ( V_62 L_27 ,
V_26 -> V_24 -> V_48 , V_26 -> V_24 -> V_69 ) ;
return - V_71 ;
}
F_42 ( & V_26 -> V_24 -> V_33 , V_68 ) ;
if ( V_26 -> V_40 != 0 ) {
F_5 ( V_9 L_28
L_29 , V_26 -> V_48 , V_26 -> V_40 ) ;
F_43 ( & V_26 -> V_24 -> V_33 , V_68 ) ;
return - V_72 ;
}
V_26 -> V_73 = V_74 ;
V_26 -> V_75 = V_76 ;
V_26 -> V_77 = V_78 ;
V_26 -> V_40 = - 1 ;
V_26 -> V_24 -> V_40 ++ ;
F_43 ( & V_26 -> V_24 -> V_33 , V_68 ) ;
V_6 = F_44 ( V_3 ) ;
if ( V_6 ) {
F_42 ( & V_26 -> V_24 -> V_33 , V_68 ) ;
V_26 -> V_40 = 0 ;
V_26 -> V_24 -> V_40 -- ;
F_43 ( & V_26 -> V_24 -> V_33 , V_68 ) ;
return V_6 ;
}
F_45 ( V_3 ) ;
F_46 ( V_26 ) ;
return 0 ;
}
static T_3 V_56 ( struct V_79 * V_80 ,
struct V_2 * V_3 )
{
struct V_1 * V_26 = F_1 ( V_3 ) ;
F_47 ( V_3 ) ;
V_26 -> V_81 = V_80 ;
F_48 ( V_26 , V_80 -> V_82 , V_80 -> V_83 ) ;
return V_84 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_26 = F_1 ( V_3 ) ;
if ( F_50 ( V_85 , & V_26 -> V_24 -> V_86 ) ) {
V_26 -> V_27 -> V_87 . V_88 ++ ;
V_26 -> V_27 -> V_87 . V_89 ++ ;
} else {
V_26 -> V_27 -> V_87 . V_90 ++ ;
V_26 -> V_27 -> V_87 . V_91 ++ ;
}
F_51 ( V_26 -> V_24 ) ;
if ( V_26 -> V_81 ) {
F_52 ( V_26 -> V_81 ) ;
V_26 -> V_81 = NULL ;
}
F_53 ( V_3 ) ;
}
static int F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_26 = F_1 ( V_3 ) ;
unsigned long V_68 ;
F_47 ( V_3 ) ;
F_55 ( V_3 ) ;
F_56 ( V_26 ) ;
F_42 ( & V_26 -> V_24 -> V_33 , V_68 ) ;
if ( V_26 -> V_92 ) {
F_57 ( V_26 -> V_92 ) ;
V_26 -> V_92 = NULL ;
}
if ( V_26 -> V_81 ) {
F_57 ( V_26 -> V_81 ) ;
V_26 -> V_81 = NULL ;
}
V_26 -> V_40 = 0 ;
V_26 -> V_24 -> V_40 -- ;
F_43 ( & V_26 -> V_24 -> V_33 , V_68 ) ;
return 0 ;
}
static char * V_74 ( struct V_1 * V_26 , int V_93 )
{
F_57 ( V_26 -> V_92 ) ;
V_26 -> V_92 = F_58 ( V_93 ) ;
if ( V_26 -> V_92 == NULL ) {
F_5 ( V_62 L_30 ,
V_26 -> V_48 ) ;
V_26 -> V_27 -> V_87 . V_94 ++ ;
return NULL ;
}
V_26 -> V_27 -> V_95 = V_96 ;
return F_59 ( V_26 -> V_92 , V_93 ) ;
}
static int V_78 ( struct V_1 * V_26 )
{
if ( ! V_26 -> V_92 ) {
F_5 ( V_9 L_31 ,
V_26 -> V_48 ) ;
V_26 -> V_27 -> V_87 . V_88 ++ ;
V_26 -> V_27 -> V_87 . V_97 ++ ;
return 0 ;
}
V_26 -> V_92 -> V_98 = F_60 ( V_26 -> V_92 , V_26 -> V_27 ) ;
V_26 -> V_92 -> V_3 = V_26 -> V_27 ;
F_61 ( V_26 -> V_92 ) ;
V_26 -> V_27 -> V_87 . V_99 ++ ;
V_26 -> V_27 -> V_87 . V_100 += V_26 -> V_24 -> V_101 ;
F_62 ( V_26 -> V_92 ) ;
V_26 -> V_92 = NULL ;
return 0 ;
}
static int V_76 ( struct V_1 * V_26 , int V_93 )
{
if ( ! V_26 -> V_81 ) {
F_5 ( V_9 L_32 ,
V_26 -> V_48 ) ;
V_26 -> V_27 -> V_87 . V_90 ++ ;
V_26 -> V_27 -> V_87 . V_91 ++ ;
return 1 ;
}
F_63 ( V_26 -> V_81 ) ;
V_26 -> V_81 = NULL ;
V_26 -> V_27 -> V_87 . V_102 ++ ;
V_26 -> V_27 -> V_87 . V_103 += V_93 ;
F_53 ( V_26 -> V_27 ) ;
return 1 ;
}
static T_4 F_64 ( struct V_104 * V_104 ,
char T_5 * V_105 , T_6 V_106 , T_7 * V_107 )
{
F_65 ( V_108 , V_109 ) ;
unsigned long V_68 ;
struct V_1 * V_26 = V_104 -> V_110 ;
struct V_23 * V_24 = V_26 -> V_24 ;
char * V_111 ;
if ( ! ( V_24 -> V_69 & V_70 ) ) {
F_5 ( V_62 L_27 ,
V_24 -> V_48 , V_24 -> V_69 ) ;
return - V_71 ;
}
if ( F_66 ( & V_26 -> V_50 ) )
return - V_112 ;
if ( ( V_26 -> V_113 = F_35 ( V_43 , V_45 | V_44 ) ) == NULL ) {
F_5 ( V_31 L_33 , V_24 -> V_48 ) ;
F_67 ( & V_26 -> V_50 ) ;
return - V_46 ;
}
V_26 -> V_114 = 0 ;
F_46 ( V_26 ) ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
F_68 ( & V_26 -> V_115 , & V_108 ) ;
while ( ! V_26 -> V_114 ) {
V_109 -> V_116 = V_38 ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
F_69 () ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
if ( F_70 ( V_109 ) && V_26 -> V_114 == 0 ) {
V_26 -> V_114 = 1 ;
F_71 ( & V_26 -> V_115 , & V_108 ) ;
V_109 -> V_116 = V_117 ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
F_67 ( & V_26 -> V_50 ) ;
return - V_112 ;
}
}
F_71 ( & V_26 -> V_115 , & V_108 ) ;
V_109 -> V_116 = V_117 ;
V_111 = V_26 -> V_113 ;
V_106 = V_26 -> V_101 ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
F_67 ( & V_26 -> V_50 ) ;
if ( F_72 ( V_105 , V_111 , V_106 ) ) {
F_18 ( V_111 ) ;
return - V_118 ;
}
F_18 ( V_111 ) ;
return V_106 ;
}
static char * F_73 ( struct V_1 * V_26 , int V_93 )
{
V_26 -> V_101 = V_93 ;
return V_26 -> V_113 ;
}
static int F_74 ( struct V_1 * V_26 )
{
if ( V_26 -> V_114 ) {
F_18 ( V_26 -> V_113 ) ;
F_75 ( & V_26 -> V_51 ) ;
}
V_26 -> V_114 = 1 ;
F_76 ( & V_26 -> V_115 ) ;
return 1 ;
}
static T_4 F_77 ( struct V_104 * V_104 ,
const char T_5 * V_105 , T_6 V_106 , T_7 * V_107 )
{
F_65 ( V_108 , V_109 ) ;
struct V_1 * V_26 = V_104 -> V_110 ;
struct V_23 * V_24 = V_26 -> V_24 ;
unsigned long V_68 ;
char * V_111 ;
if ( ! ( V_24 -> V_69 & V_70 ) ) {
F_5 ( V_62 L_27 ,
V_24 -> V_48 , V_24 -> V_69 ) ;
return - V_71 ;
}
if ( F_78 ( & V_26 -> V_51 ) )
return - V_112 ;
if ( V_106 > V_43 )
V_106 = V_43 ;
if ( ( V_111 = F_35 ( V_106 , V_44 | V_45 ) ) == NULL ) {
F_5 ( V_62 L_34 ,
V_24 -> V_48 ) ;
F_75 ( & V_26 -> V_51 ) ;
return - V_46 ;
}
if ( F_79 ( V_111 , V_105 , V_106 ) ) {
F_75 ( & V_26 -> V_51 ) ;
F_18 ( V_111 ) ;
return - V_118 ;
}
V_26 -> V_119 = 0 ;
F_48 ( V_26 , V_111 , V_106 ) ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
F_68 ( & V_26 -> V_120 , & V_108 ) ;
while ( ! V_26 -> V_119 ) {
V_109 -> V_116 = V_38 ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
F_69 () ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
if ( F_70 ( V_109 ) && V_26 -> V_119 == 0 ) {
V_26 -> V_119 = 1 ;
F_71 ( & V_26 -> V_120 , & V_108 ) ;
V_109 -> V_116 = V_117 ;
V_26 -> V_119 = 1 ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
F_75 ( & V_26 -> V_51 ) ;
return - V_112 ;
}
}
F_71 ( & V_26 -> V_120 , & V_108 ) ;
V_109 -> V_116 = V_117 ;
F_75 ( & V_26 -> V_51 ) ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
F_18 ( V_111 ) ;
return V_106 ;
}
static int F_80 ( struct V_1 * V_26 , int V_93 )
{
if ( V_26 -> V_119 ) {
F_18 ( V_26 -> V_121 ) ;
F_75 ( & V_26 -> V_51 ) ;
}
V_26 -> V_119 = 1 ;
F_76 ( & V_26 -> V_120 ) ;
return 1 ;
}
static unsigned int F_81 ( struct V_104 * V_104 , T_8 * V_122 )
{
F_5 ( V_31 L_35 ) ;
return 0 ;
}
static int F_82 ( struct V_123 * V_123 , struct V_104 * V_104 )
{
struct V_23 * V_24 ;
struct V_1 * V_26 ;
unsigned long V_68 ;
int V_124 ;
int V_125 = 0 ;
F_83 ( & V_126 ) ;
if ( ( V_124 = F_84 ( V_104 -> V_127 . V_128 -> V_129 ) >> V_130 )
>= V_18 ) {
V_125 = - V_19 ;
goto V_11;
}
V_24 = V_13 + V_124 ;
if ( ( V_124 = F_84 ( V_104 -> V_127 . V_128 -> V_129 )
& ( ( 1 << V_130 ) - 1 ) ) >= V_24 -> V_25 ) {
V_125 = - V_19 ;
goto V_11;
}
V_26 = V_24 -> V_26 + V_124 ;
V_104 -> V_110 = V_26 ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
if ( V_26 -> V_40 < 0 ) {
F_43 ( & V_24 -> V_33 , V_68 ) ;
V_125 = - V_72 ;
goto V_11;
}
V_24 -> V_40 ++ ;
V_26 -> V_40 ++ ;
V_26 -> V_75 = F_80 ;
V_26 -> V_73 = F_73 ;
V_26 -> V_77 = F_74 ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
V_11:
F_67 ( & V_126 ) ;
return V_125 ;
}
static int F_85 ( struct V_123 * V_123 , struct V_104 * V_104 )
{
struct V_1 * V_131 = V_104 -> V_110 ;
struct V_23 * V_24 ;
unsigned long V_68 ;
V_24 = V_131 -> V_24 ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
V_24 -> V_40 -- ;
V_131 -> V_40 -- ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
return 0 ;
}
static int F_86 ( struct V_123 * V_123 , struct V_104 * V_104 , int V_132 )
{
int V_133 = F_84 ( V_123 ) ;
return F_87 ( V_123 , V_104 , V_132 , & V_134 [ V_133 ] ) ;
}
static inline int F_88 ( struct V_23 * V_24 )
{
char V_135 [ V_136 ] ;
if ( V_24 -> V_40 > 1 )
F_5 ( V_31 L_36 ,
V_24 -> V_14 , V_24 -> V_40 ) ;
V_24 -> V_69 &= ~ ( V_137 | V_70 ) ;
if ( F_25 ( V_24 , V_135 ) < 0 ) {
F_5 ( V_62 L_37 , V_24 -> V_14 ) ;
return - V_10 ;
}
F_5 ( V_31 L_38 , V_24 -> V_14 ,
V_135 ) ;
V_24 -> V_69 |= V_137 ;
return 0 ;
}
static inline int F_89 ( struct V_23 * V_24 , void T_5 * V_138 )
{
struct F_89 V_139 ;
int V_5 ;
if ( V_24 -> V_40 > 1 )
F_5 ( V_31 L_39 ,
V_24 -> V_48 , V_24 -> V_40 ) ;
if ( ! ( V_24 -> V_69 & V_137 ) ) {
F_5 ( V_62 L_40 ,
V_24 -> V_48 , V_24 -> V_69 ) ;
return - V_71 ;
}
if ( F_79 ( & V_139 , V_138 , sizeof( V_139 ) ) )
return - V_118 ;
if ( V_139 . V_140 < 0 || V_139 . V_140 > V_141 )
return - V_67 ;
if ( V_139 . V_83 < 0 || V_139 . V_83 > V_141 )
return - V_67 ;
V_24 -> V_69 &= ~ ( V_137 | V_142 ) ;
V_5 = F_90 ( V_24 , V_139 . V_143 , V_139 . V_83 , V_139 . V_140 ) ;
if ( V_5 < 0 ) {
F_5 ( V_62 L_41 ,
V_24 -> V_14 , V_5 ) ;
return - V_10 ;
}
F_5 ( V_31 L_42 ,
V_24 -> V_14 , V_139 . V_83 , V_139 . V_140 ) ;
V_24 -> V_69 |= V_137 | V_142 ;
return 0 ;
}
static inline int F_91 ( struct V_23 * V_24 , void T_5 * V_138 )
{
struct F_89 V_139 ;
int V_5 ;
if ( V_24 -> V_40 > 1 )
F_5 ( V_31 L_43
L_44 ,
V_24 -> V_14 , V_24 -> V_40 ) ;
if ( ! ( V_24 -> V_69 & V_137 ) ) {
F_5 ( V_62 L_40 ,
V_24 -> V_48 , V_24 -> V_69 ) ;
return - V_71 ;
}
if ( F_79 ( & V_139 , V_138 , sizeof( V_139 ) ) )
return - V_118 ;
V_24 -> V_69 &= ~ V_137 ;
V_5 = F_92 ( V_24 , V_139 . V_143 , V_139 . V_83 , V_139 . V_140 ) ;
if ( V_5 < 0 ) {
F_5 ( V_62 L_45 ,
V_24 -> V_14 , V_5 ) ;
return - V_10 ;
}
F_5 ( V_31 L_46 ,
V_24 -> V_14 , V_139 . V_83 , V_139 . V_140 ) ;
V_24 -> V_69 |= V_137 ;
return 0 ;
}
static inline int F_93 ( struct V_23 * V_24 , int V_144 )
{
int V_5 ;
if ( V_24 -> V_40 > 1 )
F_5 ( V_31 L_47 ,
V_24 -> V_14 , V_24 -> V_40 ) ;
if ( ( V_24 -> V_69 & ( V_137 | V_142 ) )
!= ( V_137 | V_142 ) ) {
F_5 ( V_62 L_48 ,
V_24 -> V_48 , V_24 -> V_69 ) ;
return - V_71 ;
}
V_24 -> V_69 &= ~ V_137 ;
if ( ( V_5 = F_94 ( V_24 , V_144 ) ) < 0 ) {
F_5 ( V_62 L_49 ,
V_24 -> V_14 , V_144 , V_5 ) ;
return - V_10 ;
}
F_5 ( V_31 L_50 ,
V_24 -> V_14 , V_144 ) ;
V_24 -> V_145 = V_144 ;
V_24 -> V_69 |= V_70 ;
return 0 ;
}
static inline int F_95 ( struct V_23 * V_24 , char T_5 * string )
{
int V_146 = strlen ( V_24 -> V_34 ) + 1 ;
if ( F_72 ( string , V_24 -> V_34 , V_146 ) )
return - V_118 ;
return V_146 ;
}
static inline int F_96 ( struct V_23 * V_24 , char T_5 * string )
{
int V_146 = strlen ( V_24 -> type ) + 1 ;
if ( F_72 ( string , V_24 -> type , V_146 ) )
return - V_118 ;
return V_146 ;
}
static int F_97 ( struct V_23 * V_24 ,
struct V_1 * V_131 , unsigned int V_147 , unsigned long V_138 )
{
void T_5 * V_148 = ( void T_5 * ) V_138 ;
switch ( V_147 ) {
case V_149 :
if ( ! F_98 ( V_150 ) )
return - V_151 ;
return F_88 ( V_24 ) ;
case V_152 :
if ( ! F_98 ( V_153 ) )
return - V_151 ;
return F_93 ( V_24 , V_138 ) ;
case V_154 :
if ( ! F_98 ( V_153 ) )
return - V_151 ;
return F_89 ( V_24 , V_148 ) ;
case V_155 :
if ( ! F_98 ( V_153 ) )
return - V_151 ;
return F_91 ( V_24 , V_148 ) ;
case V_156 :
return F_96 ( V_24 , V_148 ) ;
case V_157 :
return F_95 ( V_24 , V_148 ) ;
case V_158 :
return V_18 ;
case V_159 :
return V_24 -> V_25 ;
case V_160 :
if ( ! F_98 ( V_153 ) )
return - V_151 ;
if ( F_22 ( V_24 ) )
return - V_67 ;
if ( V_138 != V_161 && V_138 != V_162 )
return - V_67 ;
V_24 -> V_163 = V_138 ;
return 0 ;
case V_164 :
return V_24 -> V_163 ;
}
return - V_165 ;
}
static int F_99 ( struct V_2 * V_3 , struct V_166 * V_167 , int V_147 )
{
int V_168 ;
struct V_1 * V_26 = F_1 ( V_3 ) ;
V_168 = F_97 ( V_26 -> V_24 , V_26 , V_147 ,
( unsigned long ) V_167 -> V_169 ) ;
if ( V_168 != - V_165 )
return V_168 ;
return F_100 ( V_3 , V_167 , V_147 ) ;
}
static long F_101 ( struct V_104 * V_104 , unsigned int V_147 ,
unsigned long V_138 )
{
struct V_1 * V_131 = V_104 -> V_110 ;
struct V_23 * V_24 ;
long V_125 ;
F_83 ( & V_126 ) ;
V_24 = V_131 -> V_24 ;
V_125 = F_97 ( V_24 , V_131 , V_147 , V_138 ) ;
F_67 ( & V_126 ) ;
return V_125 ;
}
static void F_46 ( struct V_1 * V_26 )
{
struct V_23 * V_24 = V_26 -> V_24 ;
if ( ! F_102 ( V_26 -> V_14 , & V_24 -> V_170 ) )
F_103 ( V_24 ) ;
}
static void F_56 ( struct V_1 * V_26 )
{
struct V_23 * V_24 = V_26 -> V_24 ;
if ( F_104 ( V_26 -> V_14 , & V_24 -> V_170 ) )
F_103 ( V_24 ) ;
}
static int F_48 ( struct V_1 * V_26 , char * V_105 , int V_83 )
{
struct V_23 * V_24 = V_26 -> V_24 ;
unsigned long V_68 ;
#ifdef F_105
int V_5 ;
F_5 ( V_31 L_51 , V_26 -> V_24 -> V_14 ,
V_26 -> V_14 , V_83 ) ;
for ( V_5 = 0 ; V_5 < V_83 ; V_5 ++ )
F_5 ( L_52 , V_105 [ V_5 ] & 0xff ) ;
F_5 ( L_53 ) ;
#endif
F_42 ( & V_24 -> V_33 , V_68 ) ;
V_26 -> V_121 = V_105 ;
V_26 -> V_171 = V_83 ;
if ( V_83 > V_43 )
V_26 -> V_171 = V_43 ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
F_106 ( V_26 -> V_14 , & V_24 -> V_172 ) ;
F_103 ( V_24 ) ;
return 0 ;
}
static void F_103 ( struct V_23 * V_24 )
{
unsigned long V_68 ;
int V_173 ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
V_173 = ( V_24 -> V_170 ? V_174 : 0 )
| ( V_24 -> V_172 ? V_175 : 0 )
| ( V_24 -> V_172 ? ~ ( V_24 -> V_172 << V_176 )
& V_177 : 0 ) ;
if ( ! V_24 -> V_86 ) {
if ( V_24 -> V_170 | V_24 -> V_172 ) {
if ( ! V_24 -> V_178 ) {
F_29 ( V_24 , V_179 ) ;
#ifdef F_107
F_108 ( V_24 , V_179 ) ;
#endif
V_24 -> V_178 = 1 ;
}
} else if ( V_24 -> V_178 ) {
V_24 -> V_178 = 0 ;
F_29 ( V_24 , 0 ) ;
#ifdef F_107
F_108 ( V_24 , 0 ) ;
#endif
}
F_109 ( V_24 , V_173 ) ;
#ifdef F_107
F_110 ( V_24 , V_173 ) ;
#endif
}
F_43 ( & V_24 -> V_33 , V_68 ) ;
}
static void F_111 ( struct V_23 * V_24 )
{
int V_173 ;
V_173 = ( V_24 -> V_170 ? V_174 : 0 )
| ( V_24 -> V_172 ? V_175 : 0 )
| ( V_24 -> V_172 ? ~ ( V_24 -> V_172 << V_176 )
& V_177 : 0 ) ;
if ( V_24 -> V_170 | V_24 -> V_172 ) {
F_29 ( V_24 , V_179 ) ;
#ifdef F_107
F_108 ( V_24 , V_179 ) ;
#endif
V_24 -> V_178 = 1 ;
} else {
F_29 ( V_24 , 0 ) ;
#ifdef F_107
F_108 ( V_24 , 0 ) ;
#endif
V_24 -> V_178 = 0 ;
}
F_109 ( V_24 , V_173 ) ;
#ifdef F_107
F_110 ( V_24 , V_173 ) ;
#endif
}
static void F_51 ( struct V_23 * V_24 )
{
unsigned long V_68 , V_180 ;
char * V_181 = L_54 ;
if ( F_50 ( V_85 , & V_24 -> V_86 ) )
V_181 = L_55 ;
if ( F_50 ( V_182 , & V_24 -> V_86 ) )
V_181 = L_56 ;
F_5 ( V_31 L_57 , V_24 -> V_48 , V_181 ) ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
V_24 -> V_86 = 0 ;
V_180 = F_112 () ;
F_113 ( V_24 -> V_17 ) ;
F_114 ( V_24 -> V_17 ) ;
F_115 ( V_180 ) ;
F_116 ( 100 ) ;
F_29 ( V_24 , 0 ) ;
F_116 ( 100 ) ;
( void ) F_32 ( V_24 ) ;
F_116 ( 100 ) ;
F_109 ( V_24 , 0 ) ;
F_116 ( 100 ) ;
F_111 ( V_24 ) ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
}
static int F_117 ( struct V_1 * V_26 , char * V_105 , int V_83 )
{
static int V_106 ;
unsigned long V_183 = ( unsigned long ) V_105 ;
if ( V_183 + V_83 >= V_184 )
return 0 ;
if ( ( V_183 ^ ( V_183 + V_83 ) ) & 0x10000 ) {
if ( V_106 ++ < 5 )
F_5 ( V_31 L_58 ,
V_26 -> V_48 ) ;
return 0 ;
}
return 1 ;
}
static int F_90 ( struct V_23 * V_24 , const char T_5 * V_185 , int V_186 , int V_144 )
{
int V_5 ;
if ( F_118 ( V_24 , 'w' ) == - 1 ) return - 1 ;
if ( ( V_5 = F_119 ( V_24 ) ) != 'w' ) { F_5 ( L_59 , V_5 ) ; return - 2 ; }
if ( F_119 ( V_24 ) != '=' ) return - 3 ;
if ( F_120 ( V_24 , V_144 ) < 0 ) return - 4 ;
if ( F_118 ( V_24 , ' ' ) == - 1 ) return - 10 ;
if ( F_119 ( V_24 ) != ' ' ) return - 11 ;
if ( F_119 ( V_24 ) != '=' ) return - 12 ;
if ( F_120 ( V_24 , V_144 + V_186 - 1 ) < 0 ) return - 13 ;
if ( F_118 ( V_24 , ' ' ) == - 1 ) return - 18 ;
if ( F_119 ( V_24 ) != ' ' ) return - 19 ;
while ( V_186 -- ) {
char V_187 ;
#ifndef F_121
if ( F_122 ( V_187 , V_185 ) )
return - 23 ;
#else
V_187 = * V_185 ;
#endif
if ( F_118 ( V_24 , V_187 ) == - 1 )
return - 20 ;
V_185 ++ ;
}
if ( F_119 ( V_24 ) != '\r' ) return - 21 ;
if ( F_119 ( V_24 ) != '\n' ) return - 22 ;
if ( F_119 ( V_24 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: download completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_94 ( struct V_23 * V_24 , int V_144 )
{
if ( F_118 ( V_24 , 'g' ) == - 1 ) return - 1 ;
if ( F_119 ( V_24 ) != 'g' ) return - 2 ;
if ( F_119 ( V_24 ) != '=' ) return - 3 ;
if ( F_120 ( V_24 , V_144 ) < 0 ) return - 4 ;
if ( F_118 ( V_24 , '\r' ) == - 1 ) return - 5 ;
if ( F_119 ( V_24 ) != '\r' ) return - 6 ;
if ( F_119 ( V_24 ) != '\r' ) return - 7 ;
if ( F_119 ( V_24 ) != '\n' ) return - 8 ;
if ( F_119 ( V_24 ) != '\r' ) return - 9 ;
if ( F_119 ( V_24 ) != '\n' ) return - 10 ;
#if 0
printk(KERN_DEBUG "cosa%d: microcode started\n", cosa->num);
#endif
return 0 ;
}
static int F_92 ( struct V_23 * V_24 , char T_5 * V_185 , int V_186 , int V_144 )
{
if ( F_118 ( V_24 , 'r' ) == - 1 ) return - 1 ;
if ( ( F_119 ( V_24 ) ) != 'r' ) return - 2 ;
if ( ( F_119 ( V_24 ) ) != '=' ) return - 3 ;
if ( F_120 ( V_24 , V_144 ) < 0 ) return - 4 ;
if ( F_118 ( V_24 , ' ' ) == - 1 ) return - 5 ;
if ( F_119 ( V_24 ) != ' ' ) return - 6 ;
if ( F_119 ( V_24 ) != '=' ) return - 7 ;
if ( F_120 ( V_24 , V_144 + V_186 - 1 ) < 0 ) return - 8 ;
if ( F_118 ( V_24 , ' ' ) == - 1 ) return - 9 ;
if ( F_119 ( V_24 ) != ' ' ) return - 10 ;
while ( V_186 -- ) {
char V_187 ;
int V_5 ;
if ( ( V_5 = F_119 ( V_24 ) ) == - 1 ) {
F_5 ( V_31 L_60 ,
V_186 ) ;
return - 11 ;
}
V_187 = V_5 ;
#if 1
if ( F_123 ( V_187 , V_185 ) )
return - 23 ;
#else
* V_185 = V_187 ;
#endif
V_185 ++ ;
}
if ( F_119 ( V_24 ) != '\r' ) return - 21 ;
if ( F_119 ( V_24 ) != '\n' ) return - 22 ;
if ( F_119 ( V_24 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: readmem completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_25 ( struct V_23 * V_24 , char * V_135 )
{
int V_5 = 0 , V_188 = 0 , V_189 = 0 , V_190 = 0 ;
F_29 ( V_24 , 0 ) ;
F_32 ( V_24 ) ;
F_29 ( V_24 , V_191 ) ;
#ifdef F_124
F_125 ( 500 ) ;
#else
F_116 ( 5 * 100000 ) ;
#endif
F_29 ( V_24 , 0 ) ;
for ( V_5 = 0 ; V_5 < V_136 - 1 ; V_5 ++ , V_189 = V_190 ) {
if ( ( V_190 = F_119 ( V_24 ) ) == - 1 ) {
return - 1 ;
}
V_190 &= 0xff ;
if ( V_190 != '\r' && V_190 != '\n' && V_190 != 0x2e )
V_135 [ V_188 ++ ] = V_190 ;
if ( V_190 == 0x2e && V_189 == '\n' )
break;
}
V_135 [ V_188 ] = '\0' ;
return V_188 ;
}
static int F_119 ( struct V_23 * V_24 )
{
int V_192 = 1000 ;
while ( -- V_192 ) {
if ( F_126 ( V_24 ) & V_193 ) {
short V_194 ;
V_194 = F_32 ( V_24 ) ;
#if 0
printk(KERN_INFO "cosa: get_wait_data returning after %d retries\n", 999-retries);
#endif
return V_194 ;
}
F_127 ( 1 ) ;
}
F_5 ( V_31 L_61 ,
F_126 ( V_24 ) ) ;
return - 1 ;
}
static int F_118 ( struct V_23 * V_24 , int V_82 )
{
int V_192 = 1000 ;
while ( -- V_192 ) {
if ( F_126 ( V_24 ) & V_195 ) {
F_109 ( V_24 , V_82 ) ;
#if 0
printk(KERN_INFO "Putdata: %d retries\n", 999-retries);
#endif
return 0 ;
}
#if 0
schedule_timeout_interruptible(1);
#endif
}
F_5 ( V_31 L_62 ,
V_24 -> V_14 , F_126 ( V_24 ) ) ;
return - 1 ;
}
static int F_120 ( struct V_23 * V_24 , int V_196 )
{
char V_197 [ 5 ] ;
int V_5 ;
sprintf ( V_197 , L_63 , V_196 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
if ( F_118 ( V_24 , V_197 [ V_5 ] ) == - 1 ) {
F_5 ( V_62 L_64 ,
V_24 -> V_14 , V_5 ) ;
return - 1 - 2 * V_5 ;
}
if ( F_119 ( V_24 ) != V_197 [ V_5 ] ) {
F_5 ( V_62 L_65 ,
V_24 -> V_14 , V_5 ) ;
return - 2 - 2 * V_5 ;
}
}
return 0 ;
}
static inline void F_128 ( struct V_23 * V_24 , int V_173 )
{
unsigned long V_68 , V_180 ;
#ifdef F_129
F_5 ( V_31 L_66 ,
V_24 -> V_14 , V_173 ) ;
#endif
F_42 ( & V_24 -> V_33 , V_68 ) ;
F_106 ( V_182 , & V_24 -> V_86 ) ;
if ( ! F_50 ( V_198 , & V_24 -> V_86 ) ) {
int V_5 = 0 ;
if ( ! V_24 -> V_172 ) {
F_5 ( V_9 L_67
L_68 ,
V_24 -> V_48 ) ;
F_111 ( V_24 ) ;
F_130 ( V_182 , & V_24 -> V_86 ) ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
return;
}
while ( 1 ) {
V_24 -> V_199 ++ ;
V_5 ++ ;
if ( V_24 -> V_199 >= V_24 -> V_25 )
V_24 -> V_199 = 0 ;
if ( ! ( V_24 -> V_172 & ( 1 << V_24 -> V_199 ) ) )
continue;
if ( ~ V_173 & ( 1 << ( V_24 -> V_199 + V_176 ) ) )
break;
if ( V_5 > V_24 -> V_25 ) {
#ifdef F_129
F_5 ( V_35 L_69
L_70 ,
V_24 -> V_48 , V_24 -> V_199 ) ;
#endif
break;
}
}
V_24 -> V_171 = V_24 -> V_26 [ V_24 -> V_199 ] . V_171 ;
if ( F_117 ( V_24 -> V_26 + V_24 -> V_199 ,
V_24 -> V_26 [ V_24 -> V_199 ] . V_121 , V_24 -> V_171 ) ) {
V_24 -> V_121 = V_24 -> V_26 [ V_24 -> V_199 ] . V_121 ;
} else {
memcpy ( V_24 -> V_28 , V_24 -> V_26 [ V_24 -> V_199 ] . V_121 ,
V_24 -> V_171 ) ;
V_24 -> V_121 = V_24 -> V_28 ;
}
}
if ( F_22 ( V_24 ) ) {
if ( ! F_50 ( V_198 , & V_24 -> V_86 ) ) {
F_29 ( V_24 , V_39 ) ;
F_109 ( V_24 , ( ( V_24 -> V_199 << 5 ) & 0xe0 ) |
( ( V_24 -> V_171 >> 8 ) & 0x1f ) ) ;
#ifdef F_107
F_108 ( V_24 , V_39 ) ;
F_131 ( V_24 , ( ( V_24 -> V_199 << 5 ) & 0xe0 ) |
( ( V_24 -> V_171 >> 8 ) & 0x1f ) ) ;
F_132 ( V_24 , F_32 ( V_24 ) ) ;
#else
F_32 ( V_24 ) ;
#endif
F_106 ( V_198 , & V_24 -> V_86 ) ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
return;
} else {
F_130 ( V_198 , & V_24 -> V_86 ) ;
F_29 ( V_24 , 0 ) ;
F_109 ( V_24 , V_24 -> V_171 & 0xff ) ;
#ifdef F_107
F_108 ( V_24 , 0 ) ;
F_131 ( V_24 , V_24 -> V_171 & 0xff ) ;
#endif
}
} else {
F_29 ( V_24 , V_39 ) ;
F_133 ( V_24 , ( ( V_24 -> V_199 << 13 ) & 0xe000 )
| ( V_24 -> V_171 & 0x1fff ) ) ;
#ifdef F_107
F_108 ( V_24 , V_39 ) ;
F_131 ( V_24 , ( ( V_24 -> V_199 << 13 ) & 0xe000 )
| ( V_24 -> V_171 & 0x1fff ) ) ;
F_132 ( V_24 , F_32 ( V_24 ) ) ;
F_108 ( V_24 , 0 ) ;
#else
F_32 ( V_24 ) ;
#endif
F_29 ( V_24 , 0 ) ;
}
if ( V_24 -> V_163 ) {
unsigned long V_140 = F_134 ( V_24 -> V_121 ) ;
int V_106 = 0 ;
F_5 ( V_31 L_71 ) ;
while ( ! ( F_126 ( V_24 ) & V_195 ) ) {
V_106 ++ ;
F_116 ( 10 ) ;
if ( V_106 > 1000 ) break;
}
F_5 ( V_31 L_72 , F_126 ( V_24 ) ) ;
F_5 ( V_31 L_73 , V_106 ) ;
F_133 ( V_24 , ( V_140 >> 16 ) & 0xffff ) ;
V_106 = 0 ;
while ( ! ( F_126 ( V_24 ) & V_195 ) ) {
V_106 ++ ;
if ( V_106 > 1000 ) break;
F_116 ( 10 ) ;
}
F_5 ( V_31 L_73 , V_106 ) ;
F_133 ( V_24 , V_140 & 0xffff ) ;
V_180 = F_112 () ;
F_135 ( V_24 -> V_17 , V_200 ) ;
F_136 ( V_24 -> V_17 ) ;
F_115 ( V_180 ) ;
} else {
V_180 = F_112 () ;
F_113 ( V_24 -> V_17 ) ;
F_114 ( V_24 -> V_17 ) ;
F_135 ( V_24 -> V_17 , V_201 ) ;
F_137 ( V_24 -> V_17 , F_134 ( V_24 -> V_121 ) ) ;
F_138 ( V_24 -> V_17 , V_24 -> V_171 ) ;
F_136 ( V_24 -> V_17 ) ;
F_115 ( V_180 ) ;
}
F_29 ( V_24 , V_202 | V_203 ) ;
#ifdef F_107
F_108 ( V_24 , V_202 | V_203 ) ;
#endif
F_43 ( & V_24 -> V_33 , V_68 ) ;
}
static inline void F_139 ( struct V_23 * V_24 , int V_173 )
{
unsigned long V_68 ;
#ifdef F_129
F_5 ( V_31 L_74 , V_24 -> V_14 ) ;
#endif
F_42 ( & V_24 -> V_33 , V_68 ) ;
F_106 ( V_85 , & V_24 -> V_86 ) ;
if ( F_22 ( V_24 ) ) {
if ( ! F_50 ( V_198 , & V_24 -> V_86 ) ) {
F_106 ( V_198 , & V_24 -> V_86 ) ;
F_111 ( V_24 ) ;
V_24 -> V_101 = F_32 ( V_24 ) << 8 ;
#ifdef F_107
F_132 ( V_24 , V_24 -> V_101 >> 8 ) ;
#endif
F_43 ( & V_24 -> V_33 , V_68 ) ;
return;
} else {
F_130 ( V_198 , & V_24 -> V_86 ) ;
V_24 -> V_101 |= F_32 ( V_24 ) & 0xff ;
#ifdef F_107
F_132 ( V_24 , V_24 -> V_101 & 0xff ) ;
#endif
#if 0
printk(KERN_INFO "cosa%d: receive rxsize = (0x%04x).\n",
cosa->num, cosa->rxsize);
#endif
}
} else {
V_24 -> V_101 = F_140 ( V_24 ) ;
#ifdef F_107
F_132 ( V_24 , V_24 -> V_101 ) ;
#endif
#if 0
printk(KERN_INFO "cosa%d: receive rxsize = (0x%04x).\n",
cosa->num, cosa->rxsize);
#endif
}
if ( ( ( V_24 -> V_101 & 0xe000 ) >> 13 ) >= V_24 -> V_25 ) {
F_5 ( V_9 L_75 ,
V_24 -> V_48 , V_24 -> V_101 ) ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
goto V_204;
}
V_24 -> V_205 = V_24 -> V_26 + ( ( V_24 -> V_101 & 0xe000 ) >> 13 ) ;
V_24 -> V_101 &= 0x1fff ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
V_24 -> V_206 = NULL ;
if ( V_24 -> V_205 -> V_73 )
V_24 -> V_206 = V_24 -> V_205 -> V_73 ( V_24 -> V_205 , V_24 -> V_101 ) ;
if ( ! V_24 -> V_206 ) {
V_204:
F_5 ( V_31 L_76 ,
V_24 -> V_14 , V_24 -> V_205 -> V_14 ) ;
V_24 -> V_206 = V_24 -> V_28 ;
}
V_68 = F_112 () ;
F_113 ( V_24 -> V_17 ) ;
F_114 ( V_24 -> V_17 ) ;
F_135 ( V_24 -> V_17 , V_207 ) ;
if ( F_117 ( V_24 -> V_205 , V_24 -> V_206 , V_24 -> V_101 & 0x1fff ) ) {
F_137 ( V_24 -> V_17 , F_134 ( V_24 -> V_206 ) ) ;
} else {
F_137 ( V_24 -> V_17 , F_134 ( V_24 -> V_28 ) ) ;
}
F_138 ( V_24 -> V_17 , ( V_24 -> V_101 & 0x1fff ) ) ;
F_136 ( V_24 -> V_17 ) ;
F_115 ( V_68 ) ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
F_29 ( V_24 , V_208 | V_203 ) ;
if ( ! F_22 ( V_24 ) && ( V_173 & V_195 ) )
F_109 ( V_24 , V_174 ) ;
#ifdef F_107
F_108 ( V_24 , V_208 | V_203 ) ;
if ( ! F_22 ( V_24 ) && ( V_173 & V_195 ) )
F_110 ( V_24 , V_174 ) ;
#endif
F_43 ( & V_24 -> V_33 , V_68 ) ;
}
static inline void F_141 ( struct V_23 * V_24 , int V_173 )
{
unsigned long V_68 , V_180 ;
F_42 ( & V_24 -> V_33 , V_68 ) ;
V_180 = F_112 () ;
F_113 ( V_24 -> V_17 ) ;
F_114 ( V_24 -> V_17 ) ;
F_115 ( V_180 ) ;
if ( F_50 ( V_182 , & V_24 -> V_86 ) ) {
struct V_1 * V_26 = V_24 -> V_26 + V_24 -> V_199 ;
if ( V_26 -> V_75 )
if ( V_26 -> V_75 ( V_26 , V_24 -> V_171 ) )
F_130 ( V_26 -> V_14 , & V_24 -> V_172 ) ;
} else if ( F_50 ( V_85 , & V_24 -> V_86 ) ) {
#ifdef F_105
{
int V_5 ;
F_5 ( V_31 L_77 , V_24 -> V_14 ,
V_24 -> V_205 -> V_14 , V_24 -> V_101 ) ;
for ( V_5 = 0 ; V_5 < V_24 -> V_101 ; V_5 ++ )
F_5 ( L_52 , V_24 -> V_206 [ V_5 ] & 0xff ) ;
F_5 ( L_53 ) ;
}
#endif
if ( V_24 -> V_206 == V_24 -> V_28 )
goto V_11;
if ( ! F_117 ( V_24 -> V_205 , V_24 -> V_206 , V_24 -> V_101 ) )
memcpy ( V_24 -> V_206 , V_24 -> V_28 , V_24 -> V_101 ) ;
if ( V_24 -> V_205 -> V_77 )
if ( V_24 -> V_205 -> V_77 ( V_24 -> V_205 ) )
F_130 ( V_24 -> V_205 -> V_14 , & V_24 -> V_170 ) ;
} else {
F_5 ( V_62 L_78 ,
V_24 -> V_14 ) ;
}
V_11:
V_24 -> V_86 = 0 ;
F_111 ( V_24 ) ;
F_43 ( & V_24 -> V_33 , V_68 ) ;
}
static T_9 V_41 ( int V_16 , void * V_209 )
{
unsigned V_173 ;
int V_106 = 0 ;
struct V_23 * V_24 = V_209 ;
V_210:
V_173 = F_126 ( V_24 ) ;
#ifdef F_129
F_5 ( V_31 L_79 , V_24 -> V_14 ,
V_173 & 0xff ) ;
#endif
#ifdef F_107
F_142 ( V_24 , V_173 ) ;
#endif
switch ( V_173 & V_211 ) {
case V_212 :
F_128 ( V_24 , V_173 ) ;
break;
case V_213 :
F_139 ( V_24 , V_173 ) ;
break;
case V_214 :
F_141 ( V_24 , V_173 ) ;
break;
default:
if ( V_106 ++ < 100 ) {
F_116 ( 100 ) ;
goto V_210;
}
F_5 ( V_31 L_80 ,
V_24 -> V_14 , V_173 & 0xff , V_106 ) ;
}
#ifdef F_129
if ( V_106 )
F_5 ( V_31 L_81 ,
V_24 -> V_48 , V_106 ) ;
else
F_5 ( V_31 L_82 , V_24 -> V_48 ) ;
#endif
return V_215 ;
}
static void F_142 ( struct V_23 * V_24 , int V_173 )
{
char * V_181 ;
switch ( V_173 & V_211 ) {
case V_213 :
V_181 = L_83 ;
break;
case V_212 :
V_181 = L_84 ;
break;
case V_214 :
V_181 = L_85 ;
break;
default:
V_181 = L_86 ;
break;
}
F_5 ( V_31 L_87 ,
V_24 -> V_48 ,
V_173 ,
V_173 & V_216 ? L_88 : L_89 ,
V_173 & V_195 ? L_90 : L_89 ,
V_173 & V_193 ? L_91 : L_89 ,
V_181 ) ;
}
static void F_108 ( struct V_23 * V_24 , int V_173 )
{
F_5 ( V_31 L_92 ,
V_24 -> V_48 ,
V_173 ,
V_173 & V_208 ? L_93 : L_94 ,
V_173 & V_202 ? L_95 : L_96 ,
V_173 & V_191 ? L_97 : L_89 ,
V_173 & V_203 ? L_98 : L_99 ,
V_173 & V_39 ? L_100 : L_101 ,
V_173 & V_179 ? L_102 : L_103 ) ;
}
static void F_132 ( struct V_23 * V_24 , int V_82 )
{
F_5 ( V_31 L_104 , V_24 -> V_48 , V_82 ) ;
}
static void F_131 ( struct V_23 * V_24 , int V_82 )
{
F_5 ( V_31 L_105 , V_24 -> V_48 , V_82 ) ;
}
static void F_110 ( struct V_23 * V_24 , int V_82 )
{
F_5 ( V_31 L_106 ,
V_24 -> V_48 , V_82 ,
V_82 & V_217 ? L_107 : L_108 ,
V_82 & V_218 ? L_109 : L_110 ) ;
}
