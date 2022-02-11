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
V_25 -> V_110 = F_37 ( V_41 , V_43 | V_42 ) ;
if ( V_25 -> V_110 == NULL ) {
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
V_108 = F_37 ( V_103 , V_42 | V_43 ) ;
if ( V_108 == NULL ) {
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
F_23 ( L_30 ) ;
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
if ( ( V_121 = F_88 ( F_89 ( V_101 ) ) >> V_124 )
>= V_17 ) {
V_122 = - V_18 ;
goto V_10;
}
V_23 = V_12 + V_121 ;
if ( ( V_121 = F_88 ( F_89 ( V_101 ) )
& ( ( 1 << V_124 ) - 1 ) ) >= V_23 -> V_24 ) {
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
static int F_90 ( struct V_120 * V_120 , struct V_101 * V_101 )
{
struct V_1 * V_125 = V_101 -> V_107 ;
struct V_22 * V_23 ;
unsigned long V_65 ;
V_23 = V_125 -> V_23 ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_38 -- ;
V_125 -> V_38 -- ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
return 0 ;
}
static int F_91 ( struct V_120 * V_120 , struct V_101 * V_101 , int V_126 )
{
int V_127 = F_88 ( V_120 ) ;
return F_92 ( V_120 , V_101 , V_126 , & V_128 [ V_127 ] ) ;
}
static inline int F_93 ( struct V_22 * V_23 )
{
char V_129 [ V_130 ] ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_31 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
V_23 -> V_66 &= ~ ( V_131 | V_67 ) ;
if ( F_26 ( V_23 , V_129 ) < 0 ) {
F_44 ( L_32 , V_23 -> V_13 ) ;
return - V_9 ;
}
F_23 ( L_33 , V_23 -> V_13 , V_129 ) ;
V_23 -> V_66 |= V_131 ;
return 0 ;
}
static inline int F_94 ( struct V_22 * V_23 , void T_5 * V_132 )
{
struct F_94 V_133 ;
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_34 ,
V_23 -> V_46 , V_23 -> V_38 ) ;
if ( ! ( V_23 -> V_66 & V_131 ) ) {
F_44 ( L_35 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_83 ( & V_133 , V_132 , sizeof( V_133 ) ) )
return - V_115 ;
if ( V_133 . V_134 < 0 || V_133 . V_134 > V_135 )
return - V_64 ;
if ( V_133 . V_80 < 0 || V_133 . V_80 > V_135 )
return - V_64 ;
V_23 -> V_66 &= ~ ( V_131 | V_136 ) ;
V_5 = F_95 ( V_23 , V_133 . V_137 , V_133 . V_80 , V_133 . V_134 ) ;
if ( V_5 < 0 ) {
F_44 ( L_36 ,
V_23 -> V_13 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_37 ,
V_23 -> V_13 , V_133 . V_80 , V_133 . V_134 ) ;
V_23 -> V_66 |= V_131 | V_136 ;
return 0 ;
}
static inline int F_96 ( struct V_22 * V_23 , void T_5 * V_132 )
{
struct F_94 V_133 ;
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_38 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
if ( ! ( V_23 -> V_66 & V_131 ) ) {
F_44 ( L_35 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_83 ( & V_133 , V_132 , sizeof( V_133 ) ) )
return - V_115 ;
V_23 -> V_66 &= ~ V_131 ;
V_5 = F_97 ( V_23 , V_133 . V_137 , V_133 . V_80 , V_133 . V_134 ) ;
if ( V_5 < 0 ) {
F_44 ( L_39 , V_23 -> V_13 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_40 ,
V_23 -> V_13 , V_133 . V_80 , V_133 . V_134 ) ;
V_23 -> V_66 |= V_131 ;
return 0 ;
}
static inline int F_98 ( struct V_22 * V_23 , int V_138 )
{
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_41 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
if ( ( V_23 -> V_66 & ( V_131 | V_136 ) )
!= ( V_131 | V_136 ) ) {
F_44 ( L_42 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
V_23 -> V_66 &= ~ V_131 ;
if ( ( V_5 = F_99 ( V_23 , V_138 ) ) < 0 ) {
F_44 ( L_43 ,
V_23 -> V_13 , V_138 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_44 , V_23 -> V_13 , V_138 ) ;
V_23 -> V_139 = V_138 ;
V_23 -> V_66 |= V_67 ;
return 0 ;
}
static inline int F_100 ( struct V_22 * V_23 , char T_5 * string )
{
int V_140 = strlen ( V_23 -> V_32 ) + 1 ;
if ( F_76 ( string , V_23 -> V_32 , V_140 ) )
return - V_115 ;
return V_140 ;
}
static inline int F_101 ( struct V_22 * V_23 , char T_5 * string )
{
int V_140 = strlen ( V_23 -> type ) + 1 ;
if ( F_76 ( string , V_23 -> type , V_140 ) )
return - V_115 ;
return V_140 ;
}
static int F_102 ( struct V_22 * V_23 ,
struct V_1 * V_125 , unsigned int V_141 , unsigned long V_132 )
{
void T_5 * V_142 = ( void T_5 * ) V_132 ;
switch ( V_141 ) {
case V_143 :
if ( ! F_103 ( V_144 ) )
return - V_145 ;
return F_93 ( V_23 ) ;
case V_146 :
if ( ! F_103 ( V_147 ) )
return - V_145 ;
return F_98 ( V_23 , V_132 ) ;
case V_148 :
if ( ! F_103 ( V_147 ) )
return - V_145 ;
return F_94 ( V_23 , V_142 ) ;
case V_149 :
if ( ! F_103 ( V_147 ) )
return - V_145 ;
return F_96 ( V_23 , V_142 ) ;
case V_150 :
return F_101 ( V_23 , V_142 ) ;
case V_151 :
return F_100 ( V_23 , V_142 ) ;
case V_152 :
return V_17 ;
case V_153 :
return V_23 -> V_24 ;
case V_154 :
if ( ! F_103 ( V_147 ) )
return - V_145 ;
if ( F_22 ( V_23 ) )
return - V_64 ;
if ( V_132 != V_155 && V_132 != V_156 )
return - V_64 ;
V_23 -> V_157 = V_132 ;
return 0 ;
case V_158 :
return V_23 -> V_157 ;
}
return - V_159 ;
}
static int F_104 ( struct V_2 * V_3 , struct V_160 * V_161 , int V_141 )
{
int V_162 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
V_162 = F_102 ( V_25 -> V_23 , V_25 , V_141 ,
( unsigned long ) V_161 -> V_163 ) ;
if ( V_162 != - V_159 )
return V_162 ;
return F_105 ( V_3 , V_161 , V_141 ) ;
}
static long F_106 ( struct V_101 * V_101 , unsigned int V_141 ,
unsigned long V_132 )
{
struct V_1 * V_125 = V_101 -> V_107 ;
struct V_22 * V_23 ;
long V_122 ;
F_87 ( & V_123 ) ;
V_23 = V_125 -> V_23 ;
V_122 = F_102 ( V_23 , V_125 , V_141 , V_132 ) ;
F_71 ( & V_123 ) ;
return V_122 ;
}
static void F_50 ( struct V_1 * V_25 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
if ( ! F_107 ( V_25 -> V_13 , & V_23 -> V_164 ) )
F_108 ( V_23 ) ;
}
static void F_60 ( struct V_1 * V_25 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
if ( F_109 ( V_25 -> V_13 , & V_23 -> V_164 ) )
F_108 ( V_23 ) ;
}
static int F_52 ( struct V_1 * V_25 , char * V_102 , int V_80 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned long V_65 ;
#ifdef F_110
int V_5 ;
F_23 ( L_45 ,
V_25 -> V_23 -> V_13 , V_25 -> V_13 , V_80 ) ;
for ( V_5 = 0 ; V_5 < V_80 ; V_5 ++ )
F_111 ( L_46 , V_102 [ V_5 ] & 0xff ) ;
F_111 ( L_47 ) ;
#endif
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_25 -> V_118 = V_102 ;
V_25 -> V_165 = V_80 ;
if ( V_80 > V_41 )
V_25 -> V_165 = V_41 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_112 ( V_25 -> V_13 , & V_23 -> V_166 ) ;
F_108 ( V_23 ) ;
return 0 ;
}
static void F_108 ( struct V_22 * V_23 )
{
unsigned long V_65 ;
int V_167 ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_167 = ( V_23 -> V_164 ? V_168 : 0 )
| ( V_23 -> V_166 ? V_169 : 0 )
| ( V_23 -> V_166 ? ~ ( V_23 -> V_166 << V_170 )
& V_171 : 0 ) ;
if ( ! V_23 -> V_83 ) {
if ( V_23 -> V_164 | V_23 -> V_166 ) {
if ( ! V_23 -> V_172 ) {
F_31 ( V_23 , V_173 ) ;
#ifdef F_113
F_114 ( V_23 , V_173 ) ;
#endif
V_23 -> V_172 = 1 ;
}
} else if ( V_23 -> V_172 ) {
V_23 -> V_172 = 0 ;
F_31 ( V_23 , 0 ) ;
#ifdef F_113
F_114 ( V_23 , 0 ) ;
#endif
}
F_115 ( V_23 , V_167 ) ;
#ifdef F_113
F_116 ( V_23 , V_167 ) ;
#endif
}
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static void F_117 ( struct V_22 * V_23 )
{
int V_167 ;
V_167 = ( V_23 -> V_164 ? V_168 : 0 )
| ( V_23 -> V_166 ? V_169 : 0 )
| ( V_23 -> V_166 ? ~ ( V_23 -> V_166 << V_170 )
& V_171 : 0 ) ;
if ( V_23 -> V_164 | V_23 -> V_166 ) {
F_31 ( V_23 , V_173 ) ;
#ifdef F_113
F_114 ( V_23 , V_173 ) ;
#endif
V_23 -> V_172 = 1 ;
} else {
F_31 ( V_23 , 0 ) ;
#ifdef F_113
F_114 ( V_23 , 0 ) ;
#endif
V_23 -> V_172 = 0 ;
}
F_115 ( V_23 , V_167 ) ;
#ifdef F_113
F_116 ( V_23 , V_167 ) ;
#endif
}
static void F_55 ( struct V_22 * V_23 )
{
unsigned long V_65 , V_174 ;
char * V_175 = L_48 ;
if ( F_54 ( V_82 , & V_23 -> V_83 ) )
V_175 = L_49 ;
if ( F_54 ( V_176 , & V_23 -> V_83 ) )
V_175 = L_50 ;
F_23 ( L_51 , V_23 -> V_46 , V_175 ) ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_83 = 0 ;
V_174 = F_118 () ;
F_119 ( V_23 -> V_16 ) ;
F_120 ( V_23 -> V_16 ) ;
F_121 ( V_174 ) ;
F_122 ( 100 ) ;
F_31 ( V_23 , 0 ) ;
F_122 ( 100 ) ;
( void ) F_34 ( V_23 ) ;
F_122 ( 100 ) ;
F_115 ( V_23 , 0 ) ;
F_122 ( 100 ) ;
F_117 ( V_23 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static int F_123 ( struct V_1 * V_25 , char * V_102 , int V_80 )
{
static int V_103 ;
unsigned long V_177 = ( unsigned long ) V_102 ;
if ( V_177 + V_80 >= V_178 )
return 0 ;
if ( ( V_177 ^ ( V_177 + V_80 ) ) & 0x10000 ) {
if ( V_103 ++ < 5 )
F_23 ( L_52 ,
V_25 -> V_46 ) ;
return 0 ;
}
return 1 ;
}
static int F_95 ( struct V_22 * V_23 , const char T_5 * V_179 , int V_180 , int V_138 )
{
int V_5 ;
if ( F_124 ( V_23 , 'w' ) == - 1 ) return - 1 ;
if ( ( V_5 = F_125 ( V_23 ) ) != 'w' ) { F_27 ( L_53 , V_5 ) ; return - 2 ; }
if ( F_125 ( V_23 ) != '=' ) return - 3 ;
if ( F_126 ( V_23 , V_138 ) < 0 ) return - 4 ;
if ( F_124 ( V_23 , ' ' ) == - 1 ) return - 10 ;
if ( F_125 ( V_23 ) != ' ' ) return - 11 ;
if ( F_125 ( V_23 ) != '=' ) return - 12 ;
if ( F_126 ( V_23 , V_138 + V_180 - 1 ) < 0 ) return - 13 ;
if ( F_124 ( V_23 , ' ' ) == - 1 ) return - 18 ;
if ( F_125 ( V_23 ) != ' ' ) return - 19 ;
while ( V_180 -- ) {
char V_181 ;
#ifndef F_127
if ( F_128 ( V_181 , V_179 ) )
return - 23 ;
#else
V_181 = * V_179 ;
#endif
if ( F_124 ( V_23 , V_181 ) == - 1 )
return - 20 ;
V_179 ++ ;
}
if ( F_125 ( V_23 ) != '\r' ) return - 21 ;
if ( F_125 ( V_23 ) != '\n' ) return - 22 ;
if ( F_125 ( V_23 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: download completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_99 ( struct V_22 * V_23 , int V_138 )
{
if ( F_124 ( V_23 , 'g' ) == - 1 ) return - 1 ;
if ( F_125 ( V_23 ) != 'g' ) return - 2 ;
if ( F_125 ( V_23 ) != '=' ) return - 3 ;
if ( F_126 ( V_23 , V_138 ) < 0 ) return - 4 ;
if ( F_124 ( V_23 , '\r' ) == - 1 ) return - 5 ;
if ( F_125 ( V_23 ) != '\r' ) return - 6 ;
if ( F_125 ( V_23 ) != '\r' ) return - 7 ;
if ( F_125 ( V_23 ) != '\n' ) return - 8 ;
if ( F_125 ( V_23 ) != '\r' ) return - 9 ;
if ( F_125 ( V_23 ) != '\n' ) return - 10 ;
#if 0
printk(KERN_DEBUG "cosa%d: microcode started\n", cosa->num);
#endif
return 0 ;
}
static int F_97 ( struct V_22 * V_23 , char T_5 * V_179 , int V_180 , int V_138 )
{
if ( F_124 ( V_23 , 'r' ) == - 1 ) return - 1 ;
if ( ( F_125 ( V_23 ) ) != 'r' ) return - 2 ;
if ( ( F_125 ( V_23 ) ) != '=' ) return - 3 ;
if ( F_126 ( V_23 , V_138 ) < 0 ) return - 4 ;
if ( F_124 ( V_23 , ' ' ) == - 1 ) return - 5 ;
if ( F_125 ( V_23 ) != ' ' ) return - 6 ;
if ( F_125 ( V_23 ) != '=' ) return - 7 ;
if ( F_126 ( V_23 , V_138 + V_180 - 1 ) < 0 ) return - 8 ;
if ( F_124 ( V_23 , ' ' ) == - 1 ) return - 9 ;
if ( F_125 ( V_23 ) != ' ' ) return - 10 ;
while ( V_180 -- ) {
char V_181 ;
int V_5 ;
if ( ( V_5 = F_125 ( V_23 ) ) == - 1 ) {
F_23 ( L_54 , V_180 ) ;
return - 11 ;
}
V_181 = V_5 ;
#if 1
if ( F_129 ( V_181 , V_179 ) )
return - 23 ;
#else
* V_179 = V_181 ;
#endif
V_179 ++ ;
}
if ( F_125 ( V_23 ) != '\r' ) return - 21 ;
if ( F_125 ( V_23 ) != '\n' ) return - 22 ;
if ( F_125 ( V_23 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: readmem completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_26 ( struct V_22 * V_23 , char * V_129 )
{
int V_5 = 0 , V_182 = 0 , V_183 = 0 , V_184 = 0 ;
F_31 ( V_23 , 0 ) ;
F_34 ( V_23 ) ;
F_31 ( V_23 , V_185 ) ;
#ifdef F_130
F_131 ( 500 ) ;
#else
F_122 ( 5 * 100000 ) ;
#endif
F_31 ( V_23 , 0 ) ;
for ( V_5 = 0 ; V_5 < V_130 - 1 ; V_5 ++ , V_183 = V_184 ) {
if ( ( V_184 = F_125 ( V_23 ) ) == - 1 ) {
return - 1 ;
}
V_184 &= 0xff ;
if ( V_184 != '\r' && V_184 != '\n' && V_184 != 0x2e )
V_129 [ V_182 ++ ] = V_184 ;
if ( V_184 == 0x2e && V_183 == '\n' )
break;
}
V_129 [ V_182 ] = '\0' ;
return V_182 ;
}
static int F_125 ( struct V_22 * V_23 )
{
int V_186 = 1000 ;
while ( -- V_186 ) {
if ( F_132 ( V_23 ) & V_187 ) {
short V_188 ;
V_188 = F_34 ( V_23 ) ;
#if 0
pr_info("get_wait_data returning after %d retries\n",
999-retries);
#endif
return V_188 ;
}
F_133 ( 1 ) ;
}
F_23 ( L_55 ,
F_132 ( V_23 ) ) ;
return - 1 ;
}
static int F_124 ( struct V_22 * V_23 , int V_79 )
{
int V_186 = 1000 ;
while ( -- V_186 ) {
if ( F_132 ( V_23 ) & V_189 ) {
F_115 ( V_23 , V_79 ) ;
#if 0
pr_info("Putdata: %d retries\n", 999-retries);
#endif
return 0 ;
}
#if 0
schedule_timeout_interruptible(1);
#endif
}
F_23 ( L_56 ,
V_23 -> V_13 , F_132 ( V_23 ) ) ;
return - 1 ;
}
static int F_126 ( struct V_22 * V_23 , int V_190 )
{
char V_191 [ 5 ] ;
int V_5 ;
sprintf ( V_191 , L_57 , V_190 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
if ( F_124 ( V_23 , V_191 [ V_5 ] ) == - 1 ) {
F_44 ( L_58 ,
V_23 -> V_13 , V_5 ) ;
return - 1 - 2 * V_5 ;
}
if ( F_125 ( V_23 ) != V_191 [ V_5 ] ) {
F_44 ( L_59 ,
V_23 -> V_13 , V_5 ) ;
return - 2 - 2 * V_5 ;
}
}
return 0 ;
}
static inline void F_134 ( struct V_22 * V_23 , int V_167 )
{
unsigned long V_65 , V_174 ;
#ifdef F_135
F_23 ( L_60 , V_23 -> V_13 , V_167 ) ;
#endif
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_112 ( V_176 , & V_23 -> V_83 ) ;
if ( ! F_54 ( V_192 , & V_23 -> V_83 ) ) {
int V_5 = 0 ;
if ( ! V_23 -> V_166 ) {
F_5 ( L_61 ,
V_23 -> V_46 ) ;
F_117 ( V_23 ) ;
F_136 ( V_176 , & V_23 -> V_83 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
return;
}
while ( 1 ) {
V_23 -> V_193 ++ ;
V_5 ++ ;
if ( V_23 -> V_193 >= V_23 -> V_24 )
V_23 -> V_193 = 0 ;
if ( ! ( V_23 -> V_166 & ( 1 << V_23 -> V_193 ) ) )
continue;
if ( ~ V_167 & ( 1 << ( V_23 -> V_193 + V_170 ) ) )
break;
if ( V_5 > V_23 -> V_24 ) {
#ifdef F_135
F_27 ( V_33 L_62
L_63 ,
V_23 -> V_46 , V_23 -> V_193 ) ;
#endif
break;
}
}
V_23 -> V_165 = V_23 -> V_25 [ V_23 -> V_193 ] . V_165 ;
if ( F_123 ( V_23 -> V_25 + V_23 -> V_193 ,
V_23 -> V_25 [ V_23 -> V_193 ] . V_118 , V_23 -> V_165 ) ) {
V_23 -> V_118 = V_23 -> V_25 [ V_23 -> V_193 ] . V_118 ;
} else {
memcpy ( V_23 -> V_27 , V_23 -> V_25 [ V_23 -> V_193 ] . V_118 ,
V_23 -> V_165 ) ;
V_23 -> V_118 = V_23 -> V_27 ;
}
}
if ( F_22 ( V_23 ) ) {
if ( ! F_54 ( V_192 , & V_23 -> V_83 ) ) {
F_31 ( V_23 , V_37 ) ;
F_115 ( V_23 , ( ( V_23 -> V_193 << 5 ) & 0xe0 ) |
( ( V_23 -> V_165 >> 8 ) & 0x1f ) ) ;
#ifdef F_113
F_114 ( V_23 , V_37 ) ;
F_137 ( V_23 , ( ( V_23 -> V_193 << 5 ) & 0xe0 ) |
( ( V_23 -> V_165 >> 8 ) & 0x1f ) ) ;
F_138 ( V_23 , F_34 ( V_23 ) ) ;
#else
F_34 ( V_23 ) ;
#endif
F_112 ( V_192 , & V_23 -> V_83 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
return;
} else {
F_136 ( V_192 , & V_23 -> V_83 ) ;
F_31 ( V_23 , 0 ) ;
F_115 ( V_23 , V_23 -> V_165 & 0xff ) ;
#ifdef F_113
F_114 ( V_23 , 0 ) ;
F_137 ( V_23 , V_23 -> V_165 & 0xff ) ;
#endif
}
} else {
F_31 ( V_23 , V_37 ) ;
F_139 ( V_23 , ( ( V_23 -> V_193 << 13 ) & 0xe000 )
| ( V_23 -> V_165 & 0x1fff ) ) ;
#ifdef F_113
F_114 ( V_23 , V_37 ) ;
F_137 ( V_23 , ( ( V_23 -> V_193 << 13 ) & 0xe000 )
| ( V_23 -> V_165 & 0x1fff ) ) ;
F_138 ( V_23 , F_34 ( V_23 ) ) ;
F_114 ( V_23 , 0 ) ;
#else
F_34 ( V_23 ) ;
#endif
F_31 ( V_23 , 0 ) ;
}
if ( V_23 -> V_157 ) {
unsigned long V_134 = F_140 ( V_23 -> V_118 ) ;
int V_103 = 0 ;
F_23 ( L_64 ) ;
while ( ! ( F_132 ( V_23 ) & V_189 ) ) {
V_103 ++ ;
F_122 ( 10 ) ;
if ( V_103 > 1000 ) break;
}
F_23 ( L_65 , F_132 ( V_23 ) ) ;
F_23 ( L_66 , V_103 ) ;
F_139 ( V_23 , ( V_134 >> 16 ) & 0xffff ) ;
V_103 = 0 ;
while ( ! ( F_132 ( V_23 ) & V_189 ) ) {
V_103 ++ ;
if ( V_103 > 1000 ) break;
F_122 ( 10 ) ;
}
F_23 ( L_66 , V_103 ) ;
F_139 ( V_23 , V_134 & 0xffff ) ;
V_174 = F_118 () ;
F_141 ( V_23 -> V_16 , V_194 ) ;
F_142 ( V_23 -> V_16 ) ;
F_121 ( V_174 ) ;
} else {
V_174 = F_118 () ;
F_119 ( V_23 -> V_16 ) ;
F_120 ( V_23 -> V_16 ) ;
F_141 ( V_23 -> V_16 , V_195 ) ;
F_143 ( V_23 -> V_16 , F_140 ( V_23 -> V_118 ) ) ;
F_144 ( V_23 -> V_16 , V_23 -> V_165 ) ;
F_142 ( V_23 -> V_16 ) ;
F_121 ( V_174 ) ;
}
F_31 ( V_23 , V_196 | V_197 ) ;
#ifdef F_113
F_114 ( V_23 , V_196 | V_197 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static inline void F_145 ( struct V_22 * V_23 , int V_167 )
{
unsigned long V_65 ;
#ifdef F_135
F_23 ( L_67 , V_23 -> V_13 ) ;
#endif
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_112 ( V_82 , & V_23 -> V_83 ) ;
if ( F_22 ( V_23 ) ) {
if ( ! F_54 ( V_192 , & V_23 -> V_83 ) ) {
F_112 ( V_192 , & V_23 -> V_83 ) ;
F_117 ( V_23 ) ;
V_23 -> V_98 = F_34 ( V_23 ) << 8 ;
#ifdef F_113
F_138 ( V_23 , V_23 -> V_98 >> 8 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
return;
} else {
F_136 ( V_192 , & V_23 -> V_83 ) ;
V_23 -> V_98 |= F_34 ( V_23 ) & 0xff ;
#ifdef F_113
F_138 ( V_23 , V_23 -> V_98 & 0xff ) ;
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
} else {
V_23 -> V_98 = F_146 ( V_23 ) ;
#ifdef F_113
F_138 ( V_23 , V_23 -> V_98 ) ;
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
if ( ( ( V_23 -> V_98 & 0xe000 ) >> 13 ) >= V_23 -> V_24 ) {
F_5 ( L_68 ,
V_23 -> V_46 , V_23 -> V_98 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
goto V_198;
}
V_23 -> V_199 = V_23 -> V_25 + ( ( V_23 -> V_98 & 0xe000 ) >> 13 ) ;
V_23 -> V_98 &= 0x1fff ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_200 = NULL ;
if ( V_23 -> V_199 -> V_70 )
V_23 -> V_200 = V_23 -> V_199 -> V_70 ( V_23 -> V_199 , V_23 -> V_98 ) ;
if ( ! V_23 -> V_200 ) {
V_198:
F_23 ( L_69 ,
V_23 -> V_13 , V_23 -> V_199 -> V_13 ) ;
V_23 -> V_200 = V_23 -> V_27 ;
}
V_65 = F_118 () ;
F_119 ( V_23 -> V_16 ) ;
F_120 ( V_23 -> V_16 ) ;
F_141 ( V_23 -> V_16 , V_201 ) ;
if ( F_123 ( V_23 -> V_199 , V_23 -> V_200 , V_23 -> V_98 & 0x1fff ) ) {
F_143 ( V_23 -> V_16 , F_140 ( V_23 -> V_200 ) ) ;
} else {
F_143 ( V_23 -> V_16 , F_140 ( V_23 -> V_27 ) ) ;
}
F_144 ( V_23 -> V_16 , ( V_23 -> V_98 & 0x1fff ) ) ;
F_142 ( V_23 -> V_16 ) ;
F_121 ( V_65 ) ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
F_31 ( V_23 , V_202 | V_197 ) ;
if ( ! F_22 ( V_23 ) && ( V_167 & V_189 ) )
F_115 ( V_23 , V_168 ) ;
#ifdef F_113
F_114 ( V_23 , V_202 | V_197 ) ;
if ( ! F_22 ( V_23 ) && ( V_167 & V_189 ) )
F_116 ( V_23 , V_168 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static inline void F_147 ( struct V_22 * V_23 , int V_167 )
{
unsigned long V_65 , V_174 ;
F_46 ( & V_23 -> V_31 , V_65 ) ;
V_174 = F_118 () ;
F_119 ( V_23 -> V_16 ) ;
F_120 ( V_23 -> V_16 ) ;
F_121 ( V_174 ) ;
if ( F_54 ( V_176 , & V_23 -> V_83 ) ) {
struct V_1 * V_25 = V_23 -> V_25 + V_23 -> V_193 ;
if ( V_25 -> V_72 )
if ( V_25 -> V_72 ( V_25 , V_23 -> V_165 ) )
F_136 ( V_25 -> V_13 , & V_23 -> V_166 ) ;
} else if ( F_54 ( V_82 , & V_23 -> V_83 ) ) {
#ifdef F_110
{
int V_5 ;
F_23 ( L_70 ,
V_23 -> V_13 , V_23 -> V_199 -> V_13 , V_23 -> V_98 ) ;
for ( V_5 = 0 ; V_5 < V_23 -> V_98 ; V_5 ++ )
F_111 ( L_46 , V_23 -> V_200 [ V_5 ] & 0xff ) ;
F_111 ( L_47 ) ;
}
#endif
if ( V_23 -> V_200 == V_23 -> V_27 )
goto V_10;
if ( ! F_123 ( V_23 -> V_199 , V_23 -> V_200 , V_23 -> V_98 ) )
memcpy ( V_23 -> V_200 , V_23 -> V_27 , V_23 -> V_98 ) ;
if ( V_23 -> V_199 -> V_74 )
if ( V_23 -> V_199 -> V_74 ( V_23 -> V_199 ) )
F_136 ( V_23 -> V_199 -> V_13 , & V_23 -> V_164 ) ;
} else {
F_44 ( L_71 , V_23 -> V_13 ) ;
}
V_10:
V_23 -> V_83 = 0 ;
F_117 ( V_23 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
}
static T_9 V_39 ( int V_15 , void * V_203 )
{
unsigned V_167 ;
int V_103 = 0 ;
struct V_22 * V_23 = V_203 ;
V_204:
V_167 = F_132 ( V_23 ) ;
#ifdef F_135
F_23 ( L_72 , V_23 -> V_13 , V_167 & 0xff ) ;
#endif
#ifdef F_113
F_148 ( V_23 , V_167 ) ;
#endif
switch ( V_167 & V_205 ) {
case V_206 :
F_134 ( V_23 , V_167 ) ;
break;
case V_207 :
F_145 ( V_23 , V_167 ) ;
break;
case V_208 :
F_147 ( V_23 , V_167 ) ;
break;
default:
if ( V_103 ++ < 100 ) {
F_122 ( 100 ) ;
goto V_204;
}
F_23 ( L_73 ,
V_23 -> V_13 , V_167 & 0xff , V_103 ) ;
}
#ifdef F_135
if ( V_103 )
F_23 ( L_74 ,
V_23 -> V_46 , V_103 ) ;
else
F_23 ( L_75 , V_23 -> V_46 ) ;
#endif
return V_209 ;
}
static void F_148 ( struct V_22 * V_23 , int V_167 )
{
char * V_175 ;
switch ( V_167 & V_205 ) {
case V_207 :
V_175 = L_76 ;
break;
case V_206 :
V_175 = L_77 ;
break;
case V_208 :
V_175 = L_78 ;
break;
default:
V_175 = L_79 ;
break;
}
F_23 ( L_80 ,
V_23 -> V_46 ,
V_167 ,
V_167 & V_210 ? L_81 : L_82 ,
V_167 & V_189 ? L_83 : L_82 ,
V_167 & V_187 ? L_84 : L_82 ,
V_175 ) ;
}
static void F_114 ( struct V_22 * V_23 , int V_167 )
{
F_23 ( L_85 ,
V_23 -> V_46 ,
V_167 ,
V_167 & V_202 ? L_86 : L_87 ,
V_167 & V_196 ? L_88 : L_89 ,
V_167 & V_185 ? L_90 : L_82 ,
V_167 & V_197 ? L_91 : L_92 ,
V_167 & V_37 ? L_93 : L_94 ,
V_167 & V_173 ? L_95 : L_96 ) ;
}
static void F_138 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_97 , V_23 -> V_46 , V_79 ) ;
}
static void F_137 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_98 , V_23 -> V_46 , V_79 ) ;
}
static void F_116 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_99 ,
V_23 -> V_46 , V_79 ,
V_79 & V_211 ? L_100 : L_101 ,
V_79 & V_212 ? L_102 : L_103 ) ;
}
