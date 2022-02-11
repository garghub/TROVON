static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static int T_1 F_3 ( void )
{
int V_5 , V_6 = 0 ;
if ( V_7 > 0 ) {
if ( F_4 ( V_7 , L_1 , & V_8 ) ) {
F_5 ( L_2 , V_7 ) ;
V_6 = - V_9 ;
goto V_10;
}
} else {
if ( ! ( V_7 = F_4 ( 0 , L_1 , & V_8 ) ) ) {
F_5 ( L_3 ) ;
V_6 = - V_9 ;
goto V_10;
}
}
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ )
V_12 [ V_5 ] . V_13 = - 1 ;
for ( V_5 = 0 ; V_14 [ V_5 ] != 0 && V_5 < V_11 ; V_5 ++ )
F_6 ( V_14 [ V_5 ] , V_15 [ V_5 ] , V_16 [ V_5 ] ) ;
if ( ! V_17 ) {
F_5 ( L_4 ) ;
F_7 ( V_7 , L_1 ) ;
V_6 = - V_18 ;
goto V_10;
}
V_19 = F_8 ( V_20 , L_1 ) ;
if ( F_9 ( V_19 ) ) {
V_6 = F_10 ( V_19 ) ;
goto V_21;
}
for ( V_5 = 0 ; V_5 < V_17 ; V_5 ++ )
F_11 ( V_19 , NULL , F_12 ( V_7 , V_5 ) , NULL ,
L_5 , V_5 ) ;
V_6 = 0 ;
goto V_10;
V_21:
F_7 ( V_7 , L_1 ) ;
V_10:
return V_6 ;
}
static void T_2 F_13 ( void )
{
struct V_22 * V_23 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_17 ; V_5 ++ )
F_14 ( V_19 , F_12 ( V_7 , V_5 ) ) ;
F_15 ( V_19 ) ;
for ( V_23 = V_12 ; V_17 -- ; V_23 ++ ) {
for ( V_5 = 0 ; V_5 < V_23 -> V_24 ; V_5 ++ ) {
F_16 ( V_23 -> V_25 [ V_5 ] . V_26 ) ;
F_17 ( V_23 -> V_25 [ V_5 ] . V_26 ) ;
}
F_18 ( V_23 -> V_25 ) ;
F_18 ( V_23 -> V_27 ) ;
F_19 ( V_23 -> V_15 , V_23 ) ;
F_20 ( V_23 -> V_16 ) ;
F_21 ( V_23 -> V_28 , F_22 ( V_23 ) ? 2 : 4 ) ;
}
F_7 ( V_7 , L_1 ) ;
}
static int F_6 ( int V_29 , int V_15 , int V_16 )
{
struct V_22 * V_23 = V_12 + V_17 ;
int V_5 , V_6 = 0 ;
memset ( V_23 , 0 , sizeof( struct V_22 ) ) ;
if ( ( V_15 >= 0 && V_15 < 2 ) || V_15 > 15 || ( V_15 < 10 && V_15 > 7 ) ) {
F_23 ( L_6 , V_15 ) ;
return - 1 ;
}
if ( V_29 < 0x100 || V_29 > 0x3ff || V_29 & 0x7 ) {
F_23 ( L_7 , V_29 ) ;
return - 1 ;
}
if ( V_16 < 0 || V_16 == 4 || V_16 > 7 ) {
F_23 ( L_8 , V_16 ) ;
return - 1 ;
}
if ( ( ( V_29 & 0x8 ) && V_16 < 4 ) || ( ! ( V_29 & 0x8 ) && V_16 > 3 ) ) {
F_23 ( L_9 ,
V_29 , V_16 ) ;
return - 1 ;
}
V_23 -> V_16 = V_16 ;
V_23 -> V_28 = V_29 ;
V_23 -> V_30 = F_22 ( V_23 ) ? V_29 + 1 : V_29 + 2 ;
F_24 ( & V_23 -> V_31 ) ;
if ( ! F_25 ( V_29 , F_22 ( V_23 ) ? 2 : 4 , L_1 ) )
return - 1 ;
if ( F_26 ( V_23 , V_23 -> V_32 ) < 0 ) {
F_27 ( V_33 L_10 , V_29 ) ;
V_6 = - 1 ;
goto V_34;
}
if ( ! strncmp ( V_23 -> V_32 , L_11 , 3 ) )
V_23 -> type = L_12 ;
else if ( ! strncmp ( V_23 -> V_32 , L_13 , 4 ) )
V_23 -> type = F_22 ( V_23 ) ? L_14 : L_15 ;
else {
#ifndef F_28
F_23 ( L_16 , V_29 ) ;
#endif
V_6 = - 1 ;
goto V_34;
}
F_21 ( V_29 , F_22 ( V_23 ) ? 2 : 4 ) ;
if ( ! F_25 ( V_29 , F_22 ( V_23 ) ? 2 : 4 , V_23 -> type ) ) {
F_27 ( V_33 L_17 , V_29 ) ;
return - 1 ;
}
if ( V_15 < 0 ) {
unsigned long V_35 ;
V_35 = F_29 () ;
F_30 ( V_36 ) ;
F_31 ( V_23 , V_37 ) ;
F_32 ( 30 ) ;
V_15 = F_33 ( V_35 ) ;
F_31 ( V_23 , 0 ) ;
F_34 ( V_23 ) ;
if ( V_15 < 0 ) {
F_23 ( L_18 ,
V_15 , V_23 -> V_28 ) ;
V_6 = - 1 ;
goto V_34;
}
if ( V_15 == 0 ) {
F_23 ( L_19 ,
V_23 -> V_28 ) ;
}
}
V_23 -> V_15 = V_15 ;
V_23 -> V_13 = V_17 ;
V_23 -> V_38 = 0 ;
V_23 -> V_24 = 2 ;
if ( F_35 ( V_23 -> V_15 , V_39 , 0 , V_23 -> type , V_23 ) ) {
V_6 = - 1 ;
goto V_34;
}
if ( F_36 ( V_23 -> V_16 , V_23 -> type ) ) {
V_6 = - 1 ;
goto V_40;
}
V_23 -> V_27 = F_37 ( V_41 , V_42 | V_43 ) ;
if ( ! V_23 -> V_27 ) {
V_6 = - V_44 ;
goto V_45;
}
sprintf ( V_23 -> V_46 , L_5 , V_23 -> V_13 ) ;
V_23 -> V_25 = F_38 ( V_23 -> V_24 , sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_23 -> V_25 ) {
V_6 = - V_44 ;
goto V_47;
}
for ( V_5 = 0 ; V_5 < V_23 -> V_24 ; V_5 ++ ) {
struct V_1 * V_25 = & V_23 -> V_25 [ V_5 ] ;
V_25 -> V_23 = V_23 ;
V_25 -> V_13 = V_5 ;
sprintf ( V_25 -> V_46 , L_20 , V_25 -> V_23 -> V_13 , V_5 ) ;
F_39 ( & V_25 -> V_48 ) ;
F_40 ( & V_25 -> V_49 , 1 ) ;
if ( ! ( V_25 -> V_26 = F_41 ( V_25 ) ) ) {
F_5 ( L_21 , V_25 -> V_46 ) ;
goto V_50;
}
F_2 ( V_25 -> V_26 ) -> V_51 = V_52 ;
F_2 ( V_25 -> V_26 ) -> V_53 = V_54 ;
V_25 -> V_26 -> V_55 = & V_56 ;
V_25 -> V_26 -> V_57 = V_58 ;
V_25 -> V_26 -> V_59 = V_25 -> V_23 -> V_28 ;
V_25 -> V_26 -> V_15 = V_25 -> V_23 -> V_15 ;
V_25 -> V_26 -> V_16 = V_25 -> V_23 -> V_16 ;
if ( F_42 ( V_25 -> V_26 ) ) {
F_43 ( V_25 -> V_26 ,
L_22 ) ;
F_17 ( V_25 -> V_26 ) ;
goto V_50;
}
}
F_23 ( L_23 ,
V_23 -> V_13 , V_23 -> V_32 , V_23 -> type ,
V_23 -> V_28 , V_23 -> V_15 , V_23 -> V_16 , V_23 -> V_24 ) ;
return V_17 ++ ;
V_50:
while ( V_5 -- > 0 ) {
F_16 ( V_23 -> V_25 [ V_5 ] . V_26 ) ;
F_17 ( V_23 -> V_25 [ V_5 ] . V_26 ) ;
}
F_18 ( V_23 -> V_25 ) ;
V_47:
F_18 ( V_23 -> V_27 ) ;
V_45:
F_20 ( V_23 -> V_16 ) ;
V_40:
F_19 ( V_23 -> V_15 , V_23 ) ;
V_34:
F_21 ( V_23 -> V_28 , F_22 ( V_23 ) ? 2 : 4 ) ;
F_44 ( L_24 , V_23 -> V_13 ) ;
return V_6 ;
}
static int V_52 ( struct V_2 * V_3 , unsigned short V_60 ,
unsigned short V_61 )
{
if ( V_60 == V_62 && V_61 == V_63 )
return 0 ;
return - V_64 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_6 ;
unsigned long V_65 ;
if ( ! ( V_25 -> V_23 -> V_66 & V_67 ) ) {
F_44 ( L_25 ,
V_25 -> V_23 -> V_46 , V_25 -> V_23 -> V_66 ) ;
return - V_68 ;
}
F_46 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
if ( V_25 -> V_38 != 0 ) {
F_5 ( L_26 ,
V_25 -> V_46 , V_25 -> V_38 ) ;
F_47 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
return - V_69 ;
}
V_25 -> V_70 = V_71 ;
V_25 -> V_72 = V_73 ;
V_25 -> V_74 = V_75 ;
V_25 -> V_38 = - 1 ;
V_25 -> V_23 -> V_38 ++ ;
F_47 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
V_6 = F_48 ( V_3 ) ;
if ( V_6 ) {
F_46 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
V_25 -> V_38 = 0 ;
V_25 -> V_23 -> V_38 -- ;
F_47 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
return V_6 ;
}
F_49 ( V_3 ) ;
F_50 ( V_25 ) ;
return 0 ;
}
static T_3 V_54 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_51 ( V_3 ) ;
V_25 -> V_78 = V_77 ;
F_52 ( V_25 , V_77 -> V_79 , V_77 -> V_80 ) ;
return V_81 ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( F_54 ( V_82 , & V_25 -> V_23 -> V_83 ) ) {
V_25 -> V_26 -> V_84 . V_85 ++ ;
V_25 -> V_26 -> V_84 . V_86 ++ ;
} else {
V_25 -> V_26 -> V_84 . V_87 ++ ;
V_25 -> V_26 -> V_84 . V_88 ++ ;
}
F_55 ( V_25 -> V_23 ) ;
if ( V_25 -> V_78 ) {
F_56 ( V_25 -> V_78 ) ;
V_25 -> V_78 = NULL ;
}
F_57 ( V_3 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_65 ;
F_51 ( V_3 ) ;
F_59 ( V_3 ) ;
F_60 ( V_25 ) ;
F_46 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
if ( V_25 -> V_89 ) {
F_61 ( V_25 -> V_89 ) ;
V_25 -> V_89 = NULL ;
}
if ( V_25 -> V_78 ) {
F_61 ( V_25 -> V_78 ) ;
V_25 -> V_78 = NULL ;
}
V_25 -> V_38 = 0 ;
V_25 -> V_23 -> V_38 -- ;
F_47 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
return 0 ;
}
static char * V_71 ( struct V_1 * V_25 , int V_90 )
{
F_61 ( V_25 -> V_89 ) ;
V_25 -> V_89 = F_62 ( V_90 ) ;
if ( V_25 -> V_89 == NULL ) {
F_44 ( L_27 , V_25 -> V_46 ) ;
V_25 -> V_26 -> V_84 . V_91 ++ ;
return NULL ;
}
V_25 -> V_26 -> V_92 = V_93 ;
return F_63 ( V_25 -> V_89 , V_90 ) ;
}
static int V_75 ( struct V_1 * V_25 )
{
if ( ! V_25 -> V_89 ) {
F_5 ( L_28 , V_25 -> V_46 ) ;
V_25 -> V_26 -> V_84 . V_85 ++ ;
V_25 -> V_26 -> V_84 . V_94 ++ ;
return 0 ;
}
V_25 -> V_89 -> V_95 = F_64 ( V_25 -> V_89 , V_25 -> V_26 ) ;
V_25 -> V_89 -> V_3 = V_25 -> V_26 ;
F_65 ( V_25 -> V_89 ) ;
V_25 -> V_26 -> V_84 . V_96 ++ ;
V_25 -> V_26 -> V_84 . V_97 += V_25 -> V_23 -> V_98 ;
F_66 ( V_25 -> V_89 ) ;
V_25 -> V_89 = NULL ;
return 0 ;
}
static int V_73 ( struct V_1 * V_25 , int V_90 )
{
if ( ! V_25 -> V_78 ) {
F_5 ( L_29 , V_25 -> V_46 ) ;
V_25 -> V_26 -> V_84 . V_87 ++ ;
V_25 -> V_26 -> V_84 . V_88 ++ ;
return 1 ;
}
F_67 ( V_25 -> V_78 ) ;
V_25 -> V_78 = NULL ;
V_25 -> V_26 -> V_84 . V_99 ++ ;
V_25 -> V_26 -> V_84 . V_100 += V_90 ;
F_57 ( V_25 -> V_26 ) ;
return 1 ;
}
static T_4 F_68 ( struct V_101 * V_101 ,
char T_5 * V_102 , T_6 V_103 , T_7 * V_104 )
{
F_69 ( V_105 , V_106 ) ;
unsigned long V_65 ;
struct V_1 * V_25 = V_101 -> V_107 ;
struct V_22 * V_23 = V_25 -> V_23 ;
char * V_108 ;
if ( ! ( V_23 -> V_66 & V_67 ) ) {
F_44 ( L_25 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_70 ( & V_25 -> V_48 ) )
return - V_109 ;
if ( ( V_25 -> V_110 = F_37 ( V_41 , V_43 | V_42 ) ) == NULL ) {
F_23 ( L_30 , V_23 -> V_46 ) ;
F_71 ( & V_25 -> V_48 ) ;
return - V_44 ;
}
V_25 -> V_111 = 0 ;
F_50 ( V_25 ) ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_72 ( & V_25 -> V_112 , & V_105 ) ;
while ( ! V_25 -> V_111 ) {
V_106 -> V_113 = V_36 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_73 () ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
if ( F_74 ( V_106 ) && V_25 -> V_111 == 0 ) {
V_25 -> V_111 = 1 ;
F_75 ( & V_25 -> V_112 , & V_105 ) ;
V_106 -> V_113 = V_114 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_71 ( & V_25 -> V_48 ) ;
return - V_109 ;
}
}
F_75 ( & V_25 -> V_112 , & V_105 ) ;
V_106 -> V_113 = V_114 ;
V_108 = V_25 -> V_110 ;
V_103 = V_25 -> V_98 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_71 ( & V_25 -> V_48 ) ;
if ( F_76 ( V_102 , V_108 , V_103 ) ) {
F_18 ( V_108 ) ;
return - V_115 ;
}
F_18 ( V_108 ) ;
return V_103 ;
}
static char * F_77 ( struct V_1 * V_25 , int V_90 )
{
V_25 -> V_98 = V_90 ;
return V_25 -> V_110 ;
}
static int F_78 ( struct V_1 * V_25 )
{
if ( V_25 -> V_111 ) {
F_18 ( V_25 -> V_110 ) ;
F_79 ( & V_25 -> V_49 ) ;
}
V_25 -> V_111 = 1 ;
F_80 ( & V_25 -> V_112 ) ;
return 1 ;
}
static T_4 F_81 ( struct V_101 * V_101 ,
const char T_5 * V_102 , T_6 V_103 , T_7 * V_104 )
{
F_69 ( V_105 , V_106 ) ;
struct V_1 * V_25 = V_101 -> V_107 ;
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned long V_65 ;
char * V_108 ;
if ( ! ( V_23 -> V_66 & V_67 ) ) {
F_44 ( L_25 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_82 ( & V_25 -> V_49 ) )
return - V_109 ;
if ( V_103 > V_41 )
V_103 = V_41 ;
if ( ( V_108 = F_37 ( V_103 , V_42 | V_43 ) ) == NULL ) {
F_44 ( L_31 ,
V_23 -> V_46 ) ;
F_79 ( & V_25 -> V_49 ) ;
return - V_44 ;
}
if ( F_83 ( V_108 , V_102 , V_103 ) ) {
F_79 ( & V_25 -> V_49 ) ;
F_18 ( V_108 ) ;
return - V_115 ;
}
V_25 -> V_116 = 0 ;
F_52 ( V_25 , V_108 , V_103 ) ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_72 ( & V_25 -> V_117 , & V_105 ) ;
while ( ! V_25 -> V_116 ) {
V_106 -> V_113 = V_36 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_73 () ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
if ( F_74 ( V_106 ) && V_25 -> V_116 == 0 ) {
V_25 -> V_116 = 1 ;
F_75 ( & V_25 -> V_117 , & V_105 ) ;
V_106 -> V_113 = V_114 ;
V_25 -> V_116 = 1 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_79 ( & V_25 -> V_49 ) ;
return - V_109 ;
}
}
F_75 ( & V_25 -> V_117 , & V_105 ) ;
V_106 -> V_113 = V_114 ;
F_79 ( & V_25 -> V_49 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_18 ( V_108 ) ;
return V_103 ;
}
static int F_84 ( struct V_1 * V_25 , int V_90 )
{
if ( V_25 -> V_116 ) {
F_18 ( V_25 -> V_118 ) ;
F_79 ( & V_25 -> V_49 ) ;
}
V_25 -> V_116 = 1 ;
F_80 ( & V_25 -> V_117 ) ;
return 1 ;
}
static unsigned int F_85 ( struct V_101 * V_101 , T_8 * V_119 )
{
F_23 ( L_32 ) ;
return 0 ;
}
static int F_86 ( struct V_120 * V_120 , struct V_101 * V_101 )
{
struct V_22 * V_23 ;
struct V_1 * V_25 ;
unsigned long V_65 ;
int V_121 ;
int V_122 = 0 ;
F_87 ( & V_123 ) ;
if ( ( V_121 = F_88 ( V_101 -> V_124 . V_125 -> V_126 ) >> V_127 )
>= V_17 ) {
V_122 = - V_18 ;
goto V_10;
}
V_23 = V_12 + V_121 ;
if ( ( V_121 = F_88 ( V_101 -> V_124 . V_125 -> V_126 )
& ( ( 1 << V_127 ) - 1 ) ) >= V_23 -> V_24 ) {
V_122 = - V_18 ;
goto V_10;
}
V_25 = V_23 -> V_25 + V_121 ;
V_101 -> V_107 = V_25 ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
if ( V_25 -> V_38 < 0 ) {
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_122 = - V_69 ;
goto V_10;
}
V_23 -> V_38 ++ ;
V_25 -> V_38 ++ ;
V_25 -> V_72 = F_84 ;
V_25 -> V_70 = F_77 ;
V_25 -> V_74 = F_78 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_10:
F_71 ( & V_123 ) ;
return V_122 ;
}
static int F_89 ( struct V_120 * V_120 , struct V_101 * V_101 )
{
struct V_1 * V_128 = V_101 -> V_107 ;
struct V_22 * V_23 ;
unsigned long V_65 ;
V_23 = V_128 -> V_23 ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_38 -- ;
V_128 -> V_38 -- ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
return 0 ;
}
static int F_90 ( struct V_120 * V_120 , struct V_101 * V_101 , int V_129 )
{
int V_130 = F_88 ( V_120 ) ;
return F_91 ( V_120 , V_101 , V_129 , & V_131 [ V_130 ] ) ;
}
static inline int F_92 ( struct V_22 * V_23 )
{
char V_132 [ V_133 ] ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_33 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
V_23 -> V_66 &= ~ ( V_134 | V_67 ) ;
if ( F_26 ( V_23 , V_132 ) < 0 ) {
F_44 ( L_34 , V_23 -> V_13 ) ;
return - V_9 ;
}
F_23 ( L_35 , V_23 -> V_13 , V_132 ) ;
V_23 -> V_66 |= V_134 ;
return 0 ;
}
static inline int F_93 ( struct V_22 * V_23 , void T_5 * V_135 )
{
struct F_93 V_136 ;
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_36 ,
V_23 -> V_46 , V_23 -> V_38 ) ;
if ( ! ( V_23 -> V_66 & V_134 ) ) {
F_44 ( L_37 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_83 ( & V_136 , V_135 , sizeof( V_136 ) ) )
return - V_115 ;
if ( V_136 . V_137 < 0 || V_136 . V_137 > V_138 )
return - V_64 ;
if ( V_136 . V_80 < 0 || V_136 . V_80 > V_138 )
return - V_64 ;
V_23 -> V_66 &= ~ ( V_134 | V_139 ) ;
V_5 = F_94 ( V_23 , V_136 . V_140 , V_136 . V_80 , V_136 . V_137 ) ;
if ( V_5 < 0 ) {
F_44 ( L_38 ,
V_23 -> V_13 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_39 ,
V_23 -> V_13 , V_136 . V_80 , V_136 . V_137 ) ;
V_23 -> V_66 |= V_134 | V_139 ;
return 0 ;
}
static inline int F_95 ( struct V_22 * V_23 , void T_5 * V_135 )
{
struct F_93 V_136 ;
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_40 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
if ( ! ( V_23 -> V_66 & V_134 ) ) {
F_44 ( L_37 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_83 ( & V_136 , V_135 , sizeof( V_136 ) ) )
return - V_115 ;
V_23 -> V_66 &= ~ V_134 ;
V_5 = F_96 ( V_23 , V_136 . V_140 , V_136 . V_80 , V_136 . V_137 ) ;
if ( V_5 < 0 ) {
F_44 ( L_41 , V_23 -> V_13 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_42 ,
V_23 -> V_13 , V_136 . V_80 , V_136 . V_137 ) ;
V_23 -> V_66 |= V_134 ;
return 0 ;
}
static inline int F_97 ( struct V_22 * V_23 , int V_141 )
{
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_43 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
if ( ( V_23 -> V_66 & ( V_134 | V_139 ) )
!= ( V_134 | V_139 ) ) {
F_44 ( L_44 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
V_23 -> V_66 &= ~ V_134 ;
if ( ( V_5 = F_98 ( V_23 , V_141 ) ) < 0 ) {
F_44 ( L_45 ,
V_23 -> V_13 , V_141 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_46 , V_23 -> V_13 , V_141 ) ;
V_23 -> V_142 = V_141 ;
V_23 -> V_66 |= V_67 ;
return 0 ;
}
static inline int F_99 ( struct V_22 * V_23 , char T_5 * string )
{
int V_143 = strlen ( V_23 -> V_32 ) + 1 ;
if ( F_76 ( string , V_23 -> V_32 , V_143 ) )
return - V_115 ;
return V_143 ;
}
static inline int F_100 ( struct V_22 * V_23 , char T_5 * string )
{
int V_143 = strlen ( V_23 -> type ) + 1 ;
if ( F_76 ( string , V_23 -> type , V_143 ) )
return - V_115 ;
return V_143 ;
}
static int F_101 ( struct V_22 * V_23 ,
struct V_1 * V_128 , unsigned int V_144 , unsigned long V_135 )
{
void T_5 * V_145 = ( void T_5 * ) V_135 ;
switch ( V_144 ) {
case V_146 :
if ( ! F_102 ( V_147 ) )
return - V_148 ;
return F_92 ( V_23 ) ;
case V_149 :
if ( ! F_102 ( V_150 ) )
return - V_148 ;
return F_97 ( V_23 , V_135 ) ;
case V_151 :
if ( ! F_102 ( V_150 ) )
return - V_148 ;
return F_93 ( V_23 , V_145 ) ;
case V_152 :
if ( ! F_102 ( V_150 ) )
return - V_148 ;
return F_95 ( V_23 , V_145 ) ;
case V_153 :
return F_100 ( V_23 , V_145 ) ;
case V_154 :
return F_99 ( V_23 , V_145 ) ;
case V_155 :
return V_17 ;
case V_156 :
return V_23 -> V_24 ;
case V_157 :
if ( ! F_102 ( V_150 ) )
return - V_148 ;
if ( F_22 ( V_23 ) )
return - V_64 ;
if ( V_135 != V_158 && V_135 != V_159 )
return - V_64 ;
V_23 -> V_160 = V_135 ;
return 0 ;
case V_161 :
return V_23 -> V_160 ;
}
return - V_162 ;
}
static int F_103 ( struct V_2 * V_3 , struct V_163 * V_164 , int V_144 )
{
int V_165 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
V_165 = F_101 ( V_25 -> V_23 , V_25 , V_144 ,
( unsigned long ) V_164 -> V_166 ) ;
if ( V_165 != - V_162 )
return V_165 ;
return F_104 ( V_3 , V_164 , V_144 ) ;
}
static long F_105 ( struct V_101 * V_101 , unsigned int V_144 ,
unsigned long V_135 )
{
struct V_1 * V_128 = V_101 -> V_107 ;
struct V_22 * V_23 ;
long V_122 ;
F_87 ( & V_123 ) ;
V_23 = V_128 -> V_23 ;
V_122 = F_101 ( V_23 , V_128 , V_144 , V_135 ) ;
F_71 ( & V_123 ) ;
return V_122 ;
}
static void F_50 ( struct V_1 * V_25 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
if ( ! F_106 ( V_25 -> V_13 , & V_23 -> V_167 ) )
F_107 ( V_23 ) ;
}
static void F_60 ( struct V_1 * V_25 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
if ( F_108 ( V_25 -> V_13 , & V_23 -> V_167 ) )
F_107 ( V_23 ) ;
}
static int F_52 ( struct V_1 * V_25 , char * V_102 , int V_80 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned long V_65 ;
#ifdef F_109
int V_5 ;
F_23 ( L_47 ,
V_25 -> V_23 -> V_13 , V_25 -> V_13 , V_80 ) ;
for ( V_5 = 0 ; V_5 < V_80 ; V_5 ++ )
F_110 ( L_48 , V_102 [ V_5 ] & 0xff ) ;
F_110 ( L_49 ) ;
#endif
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_25 -> V_118 = V_102 ;
V_25 -> V_168 = V_80 ;
if ( V_80 > V_41 )
V_25 -> V_168 = V_41 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_111 ( V_25 -> V_13 , & V_23 -> V_169 ) ;
F_107 ( V_23 ) ;
return 0 ;
}
static void F_107 ( struct V_22 * V_23 )
{
unsigned long V_65 ;
int V_170 ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_170 = ( V_23 -> V_167 ? V_171 : 0 )
| ( V_23 -> V_169 ? V_172 : 0 )
| ( V_23 -> V_169 ? ~ ( V_23 -> V_169 << V_173 )
& V_174 : 0 ) ;
if ( ! V_23 -> V_83 ) {
if ( V_23 -> V_167 | V_23 -> V_169 ) {
if ( ! V_23 -> V_175 ) {
F_31 ( V_23 , V_176 ) ;
#ifdef F_112
F_113 ( V_23 , V_176 ) ;
#endif
V_23 -> V_175 = 1 ;
}
} else if ( V_23 -> V_175 ) {
V_23 -> V_175 = 0 ;
F_31 ( V_23 , 0 ) ;
#ifdef F_112
F_113 ( V_23 , 0 ) ;
#endif
}
F_114 ( V_23 , V_170 ) ;
#ifdef F_112
F_115 ( V_23 , V_170 ) ;
#endif
}
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static void F_116 ( struct V_22 * V_23 )
{
int V_170 ;
V_170 = ( V_23 -> V_167 ? V_171 : 0 )
| ( V_23 -> V_169 ? V_172 : 0 )
| ( V_23 -> V_169 ? ~ ( V_23 -> V_169 << V_173 )
& V_174 : 0 ) ;
if ( V_23 -> V_167 | V_23 -> V_169 ) {
F_31 ( V_23 , V_176 ) ;
#ifdef F_112
F_113 ( V_23 , V_176 ) ;
#endif
V_23 -> V_175 = 1 ;
} else {
F_31 ( V_23 , 0 ) ;
#ifdef F_112
F_113 ( V_23 , 0 ) ;
#endif
V_23 -> V_175 = 0 ;
}
F_114 ( V_23 , V_170 ) ;
#ifdef F_112
F_115 ( V_23 , V_170 ) ;
#endif
}
static void F_55 ( struct V_22 * V_23 )
{
unsigned long V_65 , V_177 ;
char * V_178 = L_50 ;
if ( F_54 ( V_82 , & V_23 -> V_83 ) )
V_178 = L_51 ;
if ( F_54 ( V_179 , & V_23 -> V_83 ) )
V_178 = L_52 ;
F_23 ( L_53 , V_23 -> V_46 , V_178 ) ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_83 = 0 ;
V_177 = F_117 () ;
F_118 ( V_23 -> V_16 ) ;
F_119 ( V_23 -> V_16 ) ;
F_120 ( V_177 ) ;
F_121 ( 100 ) ;
F_31 ( V_23 , 0 ) ;
F_121 ( 100 ) ;
( void ) F_34 ( V_23 ) ;
F_121 ( 100 ) ;
F_114 ( V_23 , 0 ) ;
F_121 ( 100 ) ;
F_116 ( V_23 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static int F_122 ( struct V_1 * V_25 , char * V_102 , int V_80 )
{
static int V_103 ;
unsigned long V_180 = ( unsigned long ) V_102 ;
if ( V_180 + V_80 >= V_181 )
return 0 ;
if ( ( V_180 ^ ( V_180 + V_80 ) ) & 0x10000 ) {
if ( V_103 ++ < 5 )
F_23 ( L_54 ,
V_25 -> V_46 ) ;
return 0 ;
}
return 1 ;
}
static int F_94 ( struct V_22 * V_23 , const char T_5 * V_182 , int V_183 , int V_141 )
{
int V_5 ;
if ( F_123 ( V_23 , 'w' ) == - 1 ) return - 1 ;
if ( ( V_5 = F_124 ( V_23 ) ) != 'w' ) { F_27 ( L_55 , V_5 ) ; return - 2 ; }
if ( F_124 ( V_23 ) != '=' ) return - 3 ;
if ( F_125 ( V_23 , V_141 ) < 0 ) return - 4 ;
if ( F_123 ( V_23 , ' ' ) == - 1 ) return - 10 ;
if ( F_124 ( V_23 ) != ' ' ) return - 11 ;
if ( F_124 ( V_23 ) != '=' ) return - 12 ;
if ( F_125 ( V_23 , V_141 + V_183 - 1 ) < 0 ) return - 13 ;
if ( F_123 ( V_23 , ' ' ) == - 1 ) return - 18 ;
if ( F_124 ( V_23 ) != ' ' ) return - 19 ;
while ( V_183 -- ) {
char V_184 ;
#ifndef F_126
if ( F_127 ( V_184 , V_182 ) )
return - 23 ;
#else
V_184 = * V_182 ;
#endif
if ( F_123 ( V_23 , V_184 ) == - 1 )
return - 20 ;
V_182 ++ ;
}
if ( F_124 ( V_23 ) != '\r' ) return - 21 ;
if ( F_124 ( V_23 ) != '\n' ) return - 22 ;
if ( F_124 ( V_23 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: download completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_98 ( struct V_22 * V_23 , int V_141 )
{
if ( F_123 ( V_23 , 'g' ) == - 1 ) return - 1 ;
if ( F_124 ( V_23 ) != 'g' ) return - 2 ;
if ( F_124 ( V_23 ) != '=' ) return - 3 ;
if ( F_125 ( V_23 , V_141 ) < 0 ) return - 4 ;
if ( F_123 ( V_23 , '\r' ) == - 1 ) return - 5 ;
if ( F_124 ( V_23 ) != '\r' ) return - 6 ;
if ( F_124 ( V_23 ) != '\r' ) return - 7 ;
if ( F_124 ( V_23 ) != '\n' ) return - 8 ;
if ( F_124 ( V_23 ) != '\r' ) return - 9 ;
if ( F_124 ( V_23 ) != '\n' ) return - 10 ;
#if 0
printk(KERN_DEBUG "cosa%d: microcode started\n", cosa->num);
#endif
return 0 ;
}
static int F_96 ( struct V_22 * V_23 , char T_5 * V_182 , int V_183 , int V_141 )
{
if ( F_123 ( V_23 , 'r' ) == - 1 ) return - 1 ;
if ( ( F_124 ( V_23 ) ) != 'r' ) return - 2 ;
if ( ( F_124 ( V_23 ) ) != '=' ) return - 3 ;
if ( F_125 ( V_23 , V_141 ) < 0 ) return - 4 ;
if ( F_123 ( V_23 , ' ' ) == - 1 ) return - 5 ;
if ( F_124 ( V_23 ) != ' ' ) return - 6 ;
if ( F_124 ( V_23 ) != '=' ) return - 7 ;
if ( F_125 ( V_23 , V_141 + V_183 - 1 ) < 0 ) return - 8 ;
if ( F_123 ( V_23 , ' ' ) == - 1 ) return - 9 ;
if ( F_124 ( V_23 ) != ' ' ) return - 10 ;
while ( V_183 -- ) {
char V_184 ;
int V_5 ;
if ( ( V_5 = F_124 ( V_23 ) ) == - 1 ) {
F_23 ( L_56 , V_183 ) ;
return - 11 ;
}
V_184 = V_5 ;
#if 1
if ( F_128 ( V_184 , V_182 ) )
return - 23 ;
#else
* V_182 = V_184 ;
#endif
V_182 ++ ;
}
if ( F_124 ( V_23 ) != '\r' ) return - 21 ;
if ( F_124 ( V_23 ) != '\n' ) return - 22 ;
if ( F_124 ( V_23 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: readmem completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_26 ( struct V_22 * V_23 , char * V_132 )
{
int V_5 = 0 , V_185 = 0 , V_186 = 0 , V_187 = 0 ;
F_31 ( V_23 , 0 ) ;
F_34 ( V_23 ) ;
F_31 ( V_23 , V_188 ) ;
#ifdef F_129
F_130 ( 500 ) ;
#else
F_121 ( 5 * 100000 ) ;
#endif
F_31 ( V_23 , 0 ) ;
for ( V_5 = 0 ; V_5 < V_133 - 1 ; V_5 ++ , V_186 = V_187 ) {
if ( ( V_187 = F_124 ( V_23 ) ) == - 1 ) {
return - 1 ;
}
V_187 &= 0xff ;
if ( V_187 != '\r' && V_187 != '\n' && V_187 != 0x2e )
V_132 [ V_185 ++ ] = V_187 ;
if ( V_187 == 0x2e && V_186 == '\n' )
break;
}
V_132 [ V_185 ] = '\0' ;
return V_185 ;
}
static int F_124 ( struct V_22 * V_23 )
{
int V_189 = 1000 ;
while ( -- V_189 ) {
if ( F_131 ( V_23 ) & V_190 ) {
short V_191 ;
V_191 = F_34 ( V_23 ) ;
#if 0
pr_info("get_wait_data returning after %d retries\n",
999-retries);
#endif
return V_191 ;
}
F_132 ( 1 ) ;
}
F_23 ( L_57 ,
F_131 ( V_23 ) ) ;
return - 1 ;
}
static int F_123 ( struct V_22 * V_23 , int V_79 )
{
int V_189 = 1000 ;
while ( -- V_189 ) {
if ( F_131 ( V_23 ) & V_192 ) {
F_114 ( V_23 , V_79 ) ;
#if 0
pr_info("Putdata: %d retries\n", 999-retries);
#endif
return 0 ;
}
#if 0
schedule_timeout_interruptible(1);
#endif
}
F_23 ( L_58 ,
V_23 -> V_13 , F_131 ( V_23 ) ) ;
return - 1 ;
}
static int F_125 ( struct V_22 * V_23 , int V_193 )
{
char V_194 [ 5 ] ;
int V_5 ;
sprintf ( V_194 , L_59 , V_193 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
if ( F_123 ( V_23 , V_194 [ V_5 ] ) == - 1 ) {
F_44 ( L_60 ,
V_23 -> V_13 , V_5 ) ;
return - 1 - 2 * V_5 ;
}
if ( F_124 ( V_23 ) != V_194 [ V_5 ] ) {
F_44 ( L_61 ,
V_23 -> V_13 , V_5 ) ;
return - 2 - 2 * V_5 ;
}
}
return 0 ;
}
static inline void F_133 ( struct V_22 * V_23 , int V_170 )
{
unsigned long V_65 , V_177 ;
#ifdef F_134
F_23 ( L_62 , V_23 -> V_13 , V_170 ) ;
#endif
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_111 ( V_179 , & V_23 -> V_83 ) ;
if ( ! F_54 ( V_195 , & V_23 -> V_83 ) ) {
int V_5 = 0 ;
if ( ! V_23 -> V_169 ) {
F_5 ( L_63 ,
V_23 -> V_46 ) ;
F_116 ( V_23 ) ;
F_135 ( V_179 , & V_23 -> V_83 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
return;
}
while ( 1 ) {
V_23 -> V_196 ++ ;
V_5 ++ ;
if ( V_23 -> V_196 >= V_23 -> V_24 )
V_23 -> V_196 = 0 ;
if ( ! ( V_23 -> V_169 & ( 1 << V_23 -> V_196 ) ) )
continue;
if ( ~ V_170 & ( 1 << ( V_23 -> V_196 + V_173 ) ) )
break;
if ( V_5 > V_23 -> V_24 ) {
#ifdef F_134
F_27 ( V_33 L_64
L_65 ,
V_23 -> V_46 , V_23 -> V_196 ) ;
#endif
break;
}
}
V_23 -> V_168 = V_23 -> V_25 [ V_23 -> V_196 ] . V_168 ;
if ( F_122 ( V_23 -> V_25 + V_23 -> V_196 ,
V_23 -> V_25 [ V_23 -> V_196 ] . V_118 , V_23 -> V_168 ) ) {
V_23 -> V_118 = V_23 -> V_25 [ V_23 -> V_196 ] . V_118 ;
} else {
memcpy ( V_23 -> V_27 , V_23 -> V_25 [ V_23 -> V_196 ] . V_118 ,
V_23 -> V_168 ) ;
V_23 -> V_118 = V_23 -> V_27 ;
}
}
if ( F_22 ( V_23 ) ) {
if ( ! F_54 ( V_195 , & V_23 -> V_83 ) ) {
F_31 ( V_23 , V_37 ) ;
F_114 ( V_23 , ( ( V_23 -> V_196 << 5 ) & 0xe0 ) |
( ( V_23 -> V_168 >> 8 ) & 0x1f ) ) ;
#ifdef F_112
F_113 ( V_23 , V_37 ) ;
F_136 ( V_23 , ( ( V_23 -> V_196 << 5 ) & 0xe0 ) |
( ( V_23 -> V_168 >> 8 ) & 0x1f ) ) ;
F_137 ( V_23 , F_34 ( V_23 ) ) ;
#else
F_34 ( V_23 ) ;
#endif
F_111 ( V_195 , & V_23 -> V_83 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
return;
} else {
F_135 ( V_195 , & V_23 -> V_83 ) ;
F_31 ( V_23 , 0 ) ;
F_114 ( V_23 , V_23 -> V_168 & 0xff ) ;
#ifdef F_112
F_113 ( V_23 , 0 ) ;
F_136 ( V_23 , V_23 -> V_168 & 0xff ) ;
#endif
}
} else {
F_31 ( V_23 , V_37 ) ;
F_138 ( V_23 , ( ( V_23 -> V_196 << 13 ) & 0xe000 )
| ( V_23 -> V_168 & 0x1fff ) ) ;
#ifdef F_112
F_113 ( V_23 , V_37 ) ;
F_136 ( V_23 , ( ( V_23 -> V_196 << 13 ) & 0xe000 )
| ( V_23 -> V_168 & 0x1fff ) ) ;
F_137 ( V_23 , F_34 ( V_23 ) ) ;
F_113 ( V_23 , 0 ) ;
#else
F_34 ( V_23 ) ;
#endif
F_31 ( V_23 , 0 ) ;
}
if ( V_23 -> V_160 ) {
unsigned long V_137 = F_139 ( V_23 -> V_118 ) ;
int V_103 = 0 ;
F_23 ( L_66 ) ;
while ( ! ( F_131 ( V_23 ) & V_192 ) ) {
V_103 ++ ;
F_121 ( 10 ) ;
if ( V_103 > 1000 ) break;
}
F_23 ( L_67 , F_131 ( V_23 ) ) ;
F_23 ( L_68 , V_103 ) ;
F_138 ( V_23 , ( V_137 >> 16 ) & 0xffff ) ;
V_103 = 0 ;
while ( ! ( F_131 ( V_23 ) & V_192 ) ) {
V_103 ++ ;
if ( V_103 > 1000 ) break;
F_121 ( 10 ) ;
}
F_23 ( L_68 , V_103 ) ;
F_138 ( V_23 , V_137 & 0xffff ) ;
V_177 = F_117 () ;
F_140 ( V_23 -> V_16 , V_197 ) ;
F_141 ( V_23 -> V_16 ) ;
F_120 ( V_177 ) ;
} else {
V_177 = F_117 () ;
F_118 ( V_23 -> V_16 ) ;
F_119 ( V_23 -> V_16 ) ;
F_140 ( V_23 -> V_16 , V_198 ) ;
F_142 ( V_23 -> V_16 , F_139 ( V_23 -> V_118 ) ) ;
F_143 ( V_23 -> V_16 , V_23 -> V_168 ) ;
F_141 ( V_23 -> V_16 ) ;
F_120 ( V_177 ) ;
}
F_31 ( V_23 , V_199 | V_200 ) ;
#ifdef F_112
F_113 ( V_23 , V_199 | V_200 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static inline void F_144 ( struct V_22 * V_23 , int V_170 )
{
unsigned long V_65 ;
#ifdef F_134
F_23 ( L_69 , V_23 -> V_13 ) ;
#endif
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_111 ( V_82 , & V_23 -> V_83 ) ;
if ( F_22 ( V_23 ) ) {
if ( ! F_54 ( V_195 , & V_23 -> V_83 ) ) {
F_111 ( V_195 , & V_23 -> V_83 ) ;
F_116 ( V_23 ) ;
V_23 -> V_98 = F_34 ( V_23 ) << 8 ;
#ifdef F_112
F_137 ( V_23 , V_23 -> V_98 >> 8 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
return;
} else {
F_135 ( V_195 , & V_23 -> V_83 ) ;
V_23 -> V_98 |= F_34 ( V_23 ) & 0xff ;
#ifdef F_112
F_137 ( V_23 , V_23 -> V_98 & 0xff ) ;
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
} else {
V_23 -> V_98 = F_145 ( V_23 ) ;
#ifdef F_112
F_137 ( V_23 , V_23 -> V_98 ) ;
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
if ( ( ( V_23 -> V_98 & 0xe000 ) >> 13 ) >= V_23 -> V_24 ) {
F_5 ( L_70 ,
V_23 -> V_46 , V_23 -> V_98 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
goto V_201;
}
V_23 -> V_202 = V_23 -> V_25 + ( ( V_23 -> V_98 & 0xe000 ) >> 13 ) ;
V_23 -> V_98 &= 0x1fff ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_203 = NULL ;
if ( V_23 -> V_202 -> V_70 )
V_23 -> V_203 = V_23 -> V_202 -> V_70 ( V_23 -> V_202 , V_23 -> V_98 ) ;
if ( ! V_23 -> V_203 ) {
V_201:
F_23 ( L_71 ,
V_23 -> V_13 , V_23 -> V_202 -> V_13 ) ;
V_23 -> V_203 = V_23 -> V_27 ;
}
V_65 = F_117 () ;
F_118 ( V_23 -> V_16 ) ;
F_119 ( V_23 -> V_16 ) ;
F_140 ( V_23 -> V_16 , V_204 ) ;
if ( F_122 ( V_23 -> V_202 , V_23 -> V_203 , V_23 -> V_98 & 0x1fff ) ) {
F_142 ( V_23 -> V_16 , F_139 ( V_23 -> V_203 ) ) ;
} else {
F_142 ( V_23 -> V_16 , F_139 ( V_23 -> V_27 ) ) ;
}
F_143 ( V_23 -> V_16 , ( V_23 -> V_98 & 0x1fff ) ) ;
F_141 ( V_23 -> V_16 ) ;
F_120 ( V_65 ) ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_31 ( V_23 , V_205 | V_200 ) ;
if ( ! F_22 ( V_23 ) && ( V_170 & V_192 ) )
F_114 ( V_23 , V_171 ) ;
#ifdef F_112
F_113 ( V_23 , V_205 | V_200 ) ;
if ( ! F_22 ( V_23 ) && ( V_170 & V_192 ) )
F_115 ( V_23 , V_171 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static inline void F_146 ( struct V_22 * V_23 , int V_170 )
{
unsigned long V_65 , V_177 ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_177 = F_117 () ;
F_118 ( V_23 -> V_16 ) ;
F_119 ( V_23 -> V_16 ) ;
F_120 ( V_177 ) ;
if ( F_54 ( V_179 , & V_23 -> V_83 ) ) {
struct V_1 * V_25 = V_23 -> V_25 + V_23 -> V_196 ;
if ( V_25 -> V_72 )
if ( V_25 -> V_72 ( V_25 , V_23 -> V_168 ) )
F_135 ( V_25 -> V_13 , & V_23 -> V_169 ) ;
} else if ( F_54 ( V_82 , & V_23 -> V_83 ) ) {
#ifdef F_109
{
int V_5 ;
F_23 ( L_72 ,
V_23 -> V_13 , V_23 -> V_202 -> V_13 , V_23 -> V_98 ) ;
for ( V_5 = 0 ; V_5 < V_23 -> V_98 ; V_5 ++ )
F_110 ( L_48 , V_23 -> V_203 [ V_5 ] & 0xff ) ;
F_110 ( L_49 ) ;
}
#endif
if ( V_23 -> V_203 == V_23 -> V_27 )
goto V_10;
if ( ! F_122 ( V_23 -> V_202 , V_23 -> V_203 , V_23 -> V_98 ) )
memcpy ( V_23 -> V_203 , V_23 -> V_27 , V_23 -> V_98 ) ;
if ( V_23 -> V_202 -> V_74 )
if ( V_23 -> V_202 -> V_74 ( V_23 -> V_202 ) )
F_135 ( V_23 -> V_202 -> V_13 , & V_23 -> V_167 ) ;
} else {
F_44 ( L_73 , V_23 -> V_13 ) ;
}
V_10:
V_23 -> V_83 = 0 ;
F_116 ( V_23 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static T_9 V_39 ( int V_15 , void * V_206 )
{
unsigned V_170 ;
int V_103 = 0 ;
struct V_22 * V_23 = V_206 ;
V_207:
V_170 = F_131 ( V_23 ) ;
#ifdef F_134
F_23 ( L_74 , V_23 -> V_13 , V_170 & 0xff ) ;
#endif
#ifdef F_112
F_147 ( V_23 , V_170 ) ;
#endif
switch ( V_170 & V_208 ) {
case V_209 :
F_133 ( V_23 , V_170 ) ;
break;
case V_210 :
F_144 ( V_23 , V_170 ) ;
break;
case V_211 :
F_146 ( V_23 , V_170 ) ;
break;
default:
if ( V_103 ++ < 100 ) {
F_121 ( 100 ) ;
goto V_207;
}
F_23 ( L_75 ,
V_23 -> V_13 , V_170 & 0xff , V_103 ) ;
}
#ifdef F_134
if ( V_103 )
F_23 ( L_76 ,
V_23 -> V_46 , V_103 ) ;
else
F_23 ( L_77 , V_23 -> V_46 ) ;
#endif
return V_212 ;
}
static void F_147 ( struct V_22 * V_23 , int V_170 )
{
char * V_178 ;
switch ( V_170 & V_208 ) {
case V_210 :
V_178 = L_78 ;
break;
case V_209 :
V_178 = L_79 ;
break;
case V_211 :
V_178 = L_80 ;
break;
default:
V_178 = L_81 ;
break;
}
F_23 ( L_82 ,
V_23 -> V_46 ,
V_170 ,
V_170 & V_213 ? L_83 : L_84 ,
V_170 & V_192 ? L_85 : L_84 ,
V_170 & V_190 ? L_86 : L_84 ,
V_178 ) ;
}
static void F_113 ( struct V_22 * V_23 , int V_170 )
{
F_23 ( L_87 ,
V_23 -> V_46 ,
V_170 ,
V_170 & V_205 ? L_88 : L_89 ,
V_170 & V_199 ? L_90 : L_91 ,
V_170 & V_188 ? L_92 : L_84 ,
V_170 & V_200 ? L_93 : L_94 ,
V_170 & V_37 ? L_95 : L_96 ,
V_170 & V_176 ? L_97 : L_98 ) ;
}
static void F_137 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_99 , V_23 -> V_46 , V_79 ) ;
}
static void F_136 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_100 , V_23 -> V_46 , V_79 ) ;
}
static void F_115 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_101 ,
V_23 -> V_46 , V_79 ,
V_79 & V_214 ? L_102 : L_103 ,
V_79 & V_215 ? L_104 : L_105 ) ;
}
