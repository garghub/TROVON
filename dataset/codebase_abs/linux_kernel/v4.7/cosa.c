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
F_32 ( F_33 ( 300 ) ) ;
V_15 = F_34 ( V_35 ) ;
F_31 ( V_23 , 0 ) ;
F_35 ( V_23 ) ;
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
if ( F_36 ( V_23 -> V_15 , V_39 , 0 , V_23 -> type , V_23 ) ) {
V_6 = - 1 ;
goto V_34;
}
if ( F_37 ( V_23 -> V_16 , V_23 -> type ) ) {
V_6 = - 1 ;
goto V_40;
}
V_23 -> V_27 = F_38 ( V_41 , V_42 | V_43 ) ;
if ( ! V_23 -> V_27 ) {
V_6 = - V_44 ;
goto V_45;
}
sprintf ( V_23 -> V_46 , L_5 , V_23 -> V_13 ) ;
V_23 -> V_25 = F_39 ( V_23 -> V_24 , sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_23 -> V_25 ) {
V_6 = - V_44 ;
goto V_47;
}
for ( V_5 = 0 ; V_5 < V_23 -> V_24 ; V_5 ++ ) {
struct V_1 * V_25 = & V_23 -> V_25 [ V_5 ] ;
V_25 -> V_23 = V_23 ;
V_25 -> V_13 = V_5 ;
sprintf ( V_25 -> V_46 , L_20 , V_25 -> V_23 -> V_13 , V_5 ) ;
F_40 ( & V_25 -> V_48 ) ;
F_41 ( & V_25 -> V_49 , 1 ) ;
if ( ! ( V_25 -> V_26 = F_42 ( V_25 ) ) ) {
F_5 ( L_21 , V_25 -> V_46 ) ;
V_6 = - V_44 ;
goto V_50;
}
F_2 ( V_25 -> V_26 ) -> V_51 = V_52 ;
F_2 ( V_25 -> V_26 ) -> V_53 = V_54 ;
V_25 -> V_26 -> V_55 = & V_56 ;
V_25 -> V_26 -> V_57 = V_58 ;
V_25 -> V_26 -> V_59 = V_25 -> V_23 -> V_28 ;
V_25 -> V_26 -> V_15 = V_25 -> V_23 -> V_15 ;
V_25 -> V_26 -> V_16 = V_25 -> V_23 -> V_16 ;
V_6 = F_43 ( V_25 -> V_26 ) ;
if ( V_6 ) {
F_44 ( V_25 -> V_26 ,
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
F_45 ( L_24 , V_23 -> V_13 ) ;
return V_6 ;
}
static int V_52 ( struct V_2 * V_3 , unsigned short V_60 ,
unsigned short V_61 )
{
if ( V_60 == V_62 && V_61 == V_63 )
return 0 ;
return - V_64 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_6 ;
unsigned long V_65 ;
if ( ! ( V_25 -> V_23 -> V_66 & V_67 ) ) {
F_45 ( L_25 ,
V_25 -> V_23 -> V_46 , V_25 -> V_23 -> V_66 ) ;
return - V_68 ;
}
F_47 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
if ( V_25 -> V_38 != 0 ) {
F_5 ( L_26 ,
V_25 -> V_46 , V_25 -> V_38 ) ;
F_48 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
return - V_69 ;
}
V_25 -> V_70 = V_71 ;
V_25 -> V_72 = V_73 ;
V_25 -> V_74 = V_75 ;
V_25 -> V_38 = - 1 ;
V_25 -> V_23 -> V_38 ++ ;
F_48 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
V_6 = F_49 ( V_3 ) ;
if ( V_6 ) {
F_47 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
V_25 -> V_38 = 0 ;
V_25 -> V_23 -> V_38 -- ;
F_48 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
return V_6 ;
}
F_50 ( V_3 ) ;
F_51 ( V_25 ) ;
return 0 ;
}
static T_3 V_54 ( struct V_76 * V_77 ,
struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_52 ( V_3 ) ;
V_25 -> V_78 = V_77 ;
F_53 ( V_25 , V_77 -> V_79 , V_77 -> V_80 ) ;
return V_81 ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( F_55 ( V_82 , & V_25 -> V_23 -> V_83 ) ) {
V_25 -> V_26 -> V_84 . V_85 ++ ;
V_25 -> V_26 -> V_84 . V_86 ++ ;
} else {
V_25 -> V_26 -> V_84 . V_87 ++ ;
V_25 -> V_26 -> V_84 . V_88 ++ ;
}
F_56 ( V_25 -> V_23 ) ;
if ( V_25 -> V_78 ) {
F_57 ( V_25 -> V_78 ) ;
V_25 -> V_78 = NULL ;
}
F_58 ( V_3 ) ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_65 ;
F_52 ( V_3 ) ;
F_60 ( V_3 ) ;
F_61 ( V_25 ) ;
F_47 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
if ( V_25 -> V_89 ) {
F_62 ( V_25 -> V_89 ) ;
V_25 -> V_89 = NULL ;
}
if ( V_25 -> V_78 ) {
F_62 ( V_25 -> V_78 ) ;
V_25 -> V_78 = NULL ;
}
V_25 -> V_38 = 0 ;
V_25 -> V_23 -> V_38 -- ;
F_48 ( & V_25 -> V_23 -> V_31 , V_65 ) ;
return 0 ;
}
static char * V_71 ( struct V_1 * V_25 , int V_90 )
{
F_62 ( V_25 -> V_89 ) ;
V_25 -> V_89 = F_63 ( V_90 ) ;
if ( V_25 -> V_89 == NULL ) {
F_45 ( L_27 , V_25 -> V_46 ) ;
V_25 -> V_26 -> V_84 . V_91 ++ ;
return NULL ;
}
F_64 ( V_25 -> V_26 ) ;
return F_65 ( V_25 -> V_89 , V_90 ) ;
}
static int V_75 ( struct V_1 * V_25 )
{
if ( ! V_25 -> V_89 ) {
F_5 ( L_28 , V_25 -> V_46 ) ;
V_25 -> V_26 -> V_84 . V_85 ++ ;
V_25 -> V_26 -> V_84 . V_92 ++ ;
return 0 ;
}
V_25 -> V_89 -> V_93 = F_66 ( V_25 -> V_89 , V_25 -> V_26 ) ;
V_25 -> V_89 -> V_3 = V_25 -> V_26 ;
F_67 ( V_25 -> V_89 ) ;
V_25 -> V_26 -> V_84 . V_94 ++ ;
V_25 -> V_26 -> V_84 . V_95 += V_25 -> V_23 -> V_96 ;
F_68 ( V_25 -> V_89 ) ;
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
F_69 ( V_25 -> V_78 ) ;
V_25 -> V_78 = NULL ;
V_25 -> V_26 -> V_84 . V_97 ++ ;
V_25 -> V_26 -> V_84 . V_98 += V_90 ;
F_58 ( V_25 -> V_26 ) ;
return 1 ;
}
static T_4 F_70 ( struct V_99 * V_99 ,
char T_5 * V_100 , T_6 V_101 , T_7 * V_102 )
{
F_71 ( V_103 , V_104 ) ;
unsigned long V_65 ;
struct V_1 * V_25 = V_99 -> V_105 ;
struct V_22 * V_23 = V_25 -> V_23 ;
char * V_106 ;
if ( ! ( V_23 -> V_66 & V_67 ) ) {
F_45 ( L_25 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_72 ( & V_25 -> V_48 ) )
return - V_107 ;
V_25 -> V_108 = F_38 ( V_41 , V_43 | V_42 ) ;
if ( V_25 -> V_108 == NULL ) {
F_73 ( & V_25 -> V_48 ) ;
return - V_44 ;
}
V_25 -> V_109 = 0 ;
F_51 ( V_25 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_74 ( & V_25 -> V_110 , & V_103 ) ;
while ( ! V_25 -> V_109 ) {
F_30 ( V_36 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
F_75 () ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
if ( F_76 ( V_104 ) && V_25 -> V_109 == 0 ) {
V_25 -> V_109 = 1 ;
F_77 ( & V_25 -> V_110 , & V_103 ) ;
F_78 ( V_111 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
F_73 ( & V_25 -> V_48 ) ;
return - V_107 ;
}
}
F_77 ( & V_25 -> V_110 , & V_103 ) ;
F_78 ( V_111 ) ;
V_106 = V_25 -> V_108 ;
V_101 = V_25 -> V_96 ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
F_73 ( & V_25 -> V_48 ) ;
if ( F_79 ( V_100 , V_106 , V_101 ) ) {
F_18 ( V_106 ) ;
return - V_112 ;
}
F_18 ( V_106 ) ;
return V_101 ;
}
static char * F_80 ( struct V_1 * V_25 , int V_90 )
{
V_25 -> V_96 = V_90 ;
return V_25 -> V_108 ;
}
static int F_81 ( struct V_1 * V_25 )
{
if ( V_25 -> V_109 ) {
F_18 ( V_25 -> V_108 ) ;
F_82 ( & V_25 -> V_49 ) ;
}
V_25 -> V_109 = 1 ;
F_83 ( & V_25 -> V_110 ) ;
return 1 ;
}
static T_4 F_84 ( struct V_99 * V_99 ,
const char T_5 * V_100 , T_6 V_101 , T_7 * V_102 )
{
F_71 ( V_103 , V_104 ) ;
struct V_1 * V_25 = V_99 -> V_105 ;
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned long V_65 ;
char * V_106 ;
if ( ! ( V_23 -> V_66 & V_67 ) ) {
F_45 ( L_25 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_85 ( & V_25 -> V_49 ) )
return - V_107 ;
if ( V_101 > V_41 )
V_101 = V_41 ;
V_106 = F_38 ( V_101 , V_42 | V_43 ) ;
if ( V_106 == NULL ) {
F_82 ( & V_25 -> V_49 ) ;
return - V_44 ;
}
if ( F_86 ( V_106 , V_100 , V_101 ) ) {
F_82 ( & V_25 -> V_49 ) ;
F_18 ( V_106 ) ;
return - V_112 ;
}
V_25 -> V_113 = 0 ;
F_53 ( V_25 , V_106 , V_101 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_74 ( & V_25 -> V_114 , & V_103 ) ;
while ( ! V_25 -> V_113 ) {
F_30 ( V_36 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
F_75 () ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
if ( F_76 ( V_104 ) && V_25 -> V_113 == 0 ) {
V_25 -> V_113 = 1 ;
F_77 ( & V_25 -> V_114 , & V_103 ) ;
F_78 ( V_111 ) ;
V_25 -> V_113 = 1 ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
F_82 ( & V_25 -> V_49 ) ;
return - V_107 ;
}
}
F_77 ( & V_25 -> V_114 , & V_103 ) ;
F_78 ( V_111 ) ;
F_82 ( & V_25 -> V_49 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
F_18 ( V_106 ) ;
return V_101 ;
}
static int F_87 ( struct V_1 * V_25 , int V_90 )
{
if ( V_25 -> V_113 ) {
F_18 ( V_25 -> V_115 ) ;
F_82 ( & V_25 -> V_49 ) ;
}
V_25 -> V_113 = 1 ;
F_83 ( & V_25 -> V_114 ) ;
return 1 ;
}
static unsigned int F_88 ( struct V_99 * V_99 , T_8 * V_116 )
{
F_23 ( L_30 ) ;
return 0 ;
}
static int F_89 ( struct V_117 * V_117 , struct V_99 * V_99 )
{
struct V_22 * V_23 ;
struct V_1 * V_25 ;
unsigned long V_65 ;
int V_118 ;
int V_119 = 0 ;
F_90 ( & V_120 ) ;
if ( ( V_118 = F_91 ( F_92 ( V_99 ) ) >> V_121 )
>= V_17 ) {
V_119 = - V_18 ;
goto V_10;
}
V_23 = V_12 + V_118 ;
if ( ( V_118 = F_91 ( F_92 ( V_99 ) )
& ( ( 1 << V_121 ) - 1 ) ) >= V_23 -> V_24 ) {
V_119 = - V_18 ;
goto V_10;
}
V_25 = V_23 -> V_25 + V_118 ;
V_99 -> V_105 = V_25 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
if ( V_25 -> V_38 < 0 ) {
F_48 ( & V_23 -> V_31 , V_65 ) ;
V_119 = - V_69 ;
goto V_10;
}
V_23 -> V_38 ++ ;
V_25 -> V_38 ++ ;
V_25 -> V_72 = F_87 ;
V_25 -> V_70 = F_80 ;
V_25 -> V_74 = F_81 ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
V_10:
F_73 ( & V_120 ) ;
return V_119 ;
}
static int F_93 ( struct V_117 * V_117 , struct V_99 * V_99 )
{
struct V_1 * V_122 = V_99 -> V_105 ;
struct V_22 * V_23 ;
unsigned long V_65 ;
V_23 = V_122 -> V_23 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_38 -- ;
V_122 -> V_38 -- ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
return 0 ;
}
static int F_94 ( struct V_117 * V_117 , struct V_99 * V_99 , int V_123 )
{
int V_124 = F_91 ( V_117 ) ;
return F_95 ( V_117 , V_99 , V_123 , & V_125 [ V_124 ] ) ;
}
static inline int F_96 ( struct V_22 * V_23 )
{
char V_126 [ V_127 ] ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_31 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
V_23 -> V_66 &= ~ ( V_128 | V_67 ) ;
if ( F_26 ( V_23 , V_126 ) < 0 ) {
F_45 ( L_32 , V_23 -> V_13 ) ;
return - V_9 ;
}
F_23 ( L_33 , V_23 -> V_13 , V_126 ) ;
V_23 -> V_66 |= V_128 ;
return 0 ;
}
static inline int F_97 ( struct V_22 * V_23 , void T_5 * V_129 )
{
struct F_97 V_130 ;
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_34 ,
V_23 -> V_46 , V_23 -> V_38 ) ;
if ( ! ( V_23 -> V_66 & V_128 ) ) {
F_45 ( L_35 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_86 ( & V_130 , V_129 , sizeof( V_130 ) ) )
return - V_112 ;
if ( V_130 . V_131 < 0 || V_130 . V_131 > V_132 )
return - V_64 ;
if ( V_130 . V_80 < 0 || V_130 . V_80 > V_132 )
return - V_64 ;
V_23 -> V_66 &= ~ ( V_128 | V_133 ) ;
V_5 = F_98 ( V_23 , V_130 . V_134 , V_130 . V_80 , V_130 . V_131 ) ;
if ( V_5 < 0 ) {
F_45 ( L_36 ,
V_23 -> V_13 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_37 ,
V_23 -> V_13 , V_130 . V_80 , V_130 . V_131 ) ;
V_23 -> V_66 |= V_128 | V_133 ;
return 0 ;
}
static inline int F_99 ( struct V_22 * V_23 , void T_5 * V_129 )
{
struct F_97 V_130 ;
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_38 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
if ( ! ( V_23 -> V_66 & V_128 ) ) {
F_45 ( L_35 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
if ( F_86 ( & V_130 , V_129 , sizeof( V_130 ) ) )
return - V_112 ;
V_23 -> V_66 &= ~ V_128 ;
V_5 = F_100 ( V_23 , V_130 . V_134 , V_130 . V_80 , V_130 . V_131 ) ;
if ( V_5 < 0 ) {
F_45 ( L_39 , V_23 -> V_13 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_40 ,
V_23 -> V_13 , V_130 . V_80 , V_130 . V_131 ) ;
V_23 -> V_66 |= V_128 ;
return 0 ;
}
static inline int F_101 ( struct V_22 * V_23 , int V_135 )
{
int V_5 ;
if ( V_23 -> V_38 > 1 )
F_23 ( L_41 ,
V_23 -> V_13 , V_23 -> V_38 ) ;
if ( ( V_23 -> V_66 & ( V_128 | V_133 ) )
!= ( V_128 | V_133 ) ) {
F_45 ( L_42 ,
V_23 -> V_46 , V_23 -> V_66 ) ;
return - V_68 ;
}
V_23 -> V_66 &= ~ V_128 ;
if ( ( V_5 = F_102 ( V_23 , V_135 ) ) < 0 ) {
F_45 ( L_43 ,
V_23 -> V_13 , V_135 , V_5 ) ;
return - V_9 ;
}
F_23 ( L_44 , V_23 -> V_13 , V_135 ) ;
V_23 -> V_136 = V_135 ;
V_23 -> V_66 |= V_67 ;
return 0 ;
}
static inline int F_103 ( struct V_22 * V_23 , char T_5 * string )
{
int V_137 = strlen ( V_23 -> V_32 ) + 1 ;
if ( F_79 ( string , V_23 -> V_32 , V_137 ) )
return - V_112 ;
return V_137 ;
}
static inline int F_104 ( struct V_22 * V_23 , char T_5 * string )
{
int V_137 = strlen ( V_23 -> type ) + 1 ;
if ( F_79 ( string , V_23 -> type , V_137 ) )
return - V_112 ;
return V_137 ;
}
static int F_105 ( struct V_22 * V_23 ,
struct V_1 * V_122 , unsigned int V_138 , unsigned long V_129 )
{
void T_5 * V_139 = ( void T_5 * ) V_129 ;
switch ( V_138 ) {
case V_140 :
if ( ! F_106 ( V_141 ) )
return - V_142 ;
return F_96 ( V_23 ) ;
case V_143 :
if ( ! F_106 ( V_144 ) )
return - V_142 ;
return F_101 ( V_23 , V_129 ) ;
case V_145 :
if ( ! F_106 ( V_144 ) )
return - V_142 ;
return F_97 ( V_23 , V_139 ) ;
case V_146 :
if ( ! F_106 ( V_144 ) )
return - V_142 ;
return F_99 ( V_23 , V_139 ) ;
case V_147 :
return F_104 ( V_23 , V_139 ) ;
case V_148 :
return F_103 ( V_23 , V_139 ) ;
case V_149 :
return V_17 ;
case V_150 :
return V_23 -> V_24 ;
case V_151 :
if ( ! F_106 ( V_144 ) )
return - V_142 ;
if ( F_22 ( V_23 ) )
return - V_64 ;
if ( V_129 != V_152 && V_129 != V_153 )
return - V_64 ;
V_23 -> V_154 = V_129 ;
return 0 ;
case V_155 :
return V_23 -> V_154 ;
}
return - V_156 ;
}
static int F_107 ( struct V_2 * V_3 , struct V_157 * V_158 , int V_138 )
{
int V_159 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
V_159 = F_105 ( V_25 -> V_23 , V_25 , V_138 ,
( unsigned long ) V_158 -> V_160 ) ;
if ( V_159 != - V_156 )
return V_159 ;
return F_108 ( V_3 , V_158 , V_138 ) ;
}
static long F_109 ( struct V_99 * V_99 , unsigned int V_138 ,
unsigned long V_129 )
{
struct V_1 * V_122 = V_99 -> V_105 ;
struct V_22 * V_23 ;
long V_119 ;
F_90 ( & V_120 ) ;
V_23 = V_122 -> V_23 ;
V_119 = F_105 ( V_23 , V_122 , V_138 , V_129 ) ;
F_73 ( & V_120 ) ;
return V_119 ;
}
static void F_51 ( struct V_1 * V_25 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
if ( ! F_110 ( V_25 -> V_13 , & V_23 -> V_161 ) )
F_111 ( V_23 ) ;
}
static void F_61 ( struct V_1 * V_25 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
if ( F_112 ( V_25 -> V_13 , & V_23 -> V_161 ) )
F_111 ( V_23 ) ;
}
static int F_53 ( struct V_1 * V_25 , char * V_100 , int V_80 )
{
struct V_22 * V_23 = V_25 -> V_23 ;
unsigned long V_65 ;
#ifdef F_113
int V_5 ;
F_23 ( L_45 ,
V_25 -> V_23 -> V_13 , V_25 -> V_13 , V_80 ) ;
for ( V_5 = 0 ; V_5 < V_80 ; V_5 ++ )
F_114 ( L_46 , V_100 [ V_5 ] & 0xff ) ;
F_114 ( L_47 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_25 -> V_115 = V_100 ;
V_25 -> V_162 = V_80 ;
if ( V_80 > V_41 )
V_25 -> V_162 = V_41 ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
F_115 ( V_25 -> V_13 , & V_23 -> V_163 ) ;
F_111 ( V_23 ) ;
return 0 ;
}
static void F_111 ( struct V_22 * V_23 )
{
unsigned long V_65 ;
int V_164 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_164 = ( V_23 -> V_161 ? V_165 : 0 )
| ( V_23 -> V_163 ? V_166 : 0 )
| ( V_23 -> V_163 ? ~ ( V_23 -> V_163 << V_167 )
& V_168 : 0 ) ;
if ( ! V_23 -> V_83 ) {
if ( V_23 -> V_161 | V_23 -> V_163 ) {
if ( ! V_23 -> V_169 ) {
F_31 ( V_23 , V_170 ) ;
#ifdef F_116
F_117 ( V_23 , V_170 ) ;
#endif
V_23 -> V_169 = 1 ;
}
} else if ( V_23 -> V_169 ) {
V_23 -> V_169 = 0 ;
F_31 ( V_23 , 0 ) ;
#ifdef F_116
F_117 ( V_23 , 0 ) ;
#endif
}
F_118 ( V_23 , V_164 ) ;
#ifdef F_116
F_119 ( V_23 , V_164 ) ;
#endif
}
F_48 ( & V_23 -> V_31 , V_65 ) ;
}
static void F_120 ( struct V_22 * V_23 )
{
int V_164 ;
V_164 = ( V_23 -> V_161 ? V_165 : 0 )
| ( V_23 -> V_163 ? V_166 : 0 )
| ( V_23 -> V_163 ? ~ ( V_23 -> V_163 << V_167 )
& V_168 : 0 ) ;
if ( V_23 -> V_161 | V_23 -> V_163 ) {
F_31 ( V_23 , V_170 ) ;
#ifdef F_116
F_117 ( V_23 , V_170 ) ;
#endif
V_23 -> V_169 = 1 ;
} else {
F_31 ( V_23 , 0 ) ;
#ifdef F_116
F_117 ( V_23 , 0 ) ;
#endif
V_23 -> V_169 = 0 ;
}
F_118 ( V_23 , V_164 ) ;
#ifdef F_116
F_119 ( V_23 , V_164 ) ;
#endif
}
static void F_56 ( struct V_22 * V_23 )
{
unsigned long V_65 , V_171 ;
char * V_172 = L_48 ;
if ( F_55 ( V_82 , & V_23 -> V_83 ) )
V_172 = L_49 ;
if ( F_55 ( V_173 , & V_23 -> V_83 ) )
V_172 = L_50 ;
F_23 ( L_51 , V_23 -> V_46 , V_172 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_83 = 0 ;
V_171 = F_121 () ;
F_122 ( V_23 -> V_16 ) ;
F_123 ( V_23 -> V_16 ) ;
F_124 ( V_171 ) ;
F_125 ( 100 ) ;
F_31 ( V_23 , 0 ) ;
F_125 ( 100 ) ;
( void ) F_35 ( V_23 ) ;
F_125 ( 100 ) ;
F_118 ( V_23 , 0 ) ;
F_125 ( 100 ) ;
F_120 ( V_23 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
}
static int F_126 ( struct V_1 * V_25 , char * V_100 , int V_80 )
{
static int V_101 ;
unsigned long V_174 = ( unsigned long ) V_100 ;
if ( V_174 + V_80 >= V_175 )
return 0 ;
if ( ( V_174 ^ ( V_174 + V_80 ) ) & 0x10000 ) {
if ( V_101 ++ < 5 )
F_23 ( L_52 ,
V_25 -> V_46 ) ;
return 0 ;
}
return 1 ;
}
static int F_98 ( struct V_22 * V_23 , const char T_5 * V_176 , int V_177 , int V_135 )
{
int V_5 ;
if ( F_127 ( V_23 , 'w' ) == - 1 ) return - 1 ;
if ( ( V_5 = F_128 ( V_23 ) ) != 'w' ) { F_27 ( L_53 , V_5 ) ; return - 2 ; }
if ( F_128 ( V_23 ) != '=' ) return - 3 ;
if ( F_129 ( V_23 , V_135 ) < 0 ) return - 4 ;
if ( F_127 ( V_23 , ' ' ) == - 1 ) return - 10 ;
if ( F_128 ( V_23 ) != ' ' ) return - 11 ;
if ( F_128 ( V_23 ) != '=' ) return - 12 ;
if ( F_129 ( V_23 , V_135 + V_177 - 1 ) < 0 ) return - 13 ;
if ( F_127 ( V_23 , ' ' ) == - 1 ) return - 18 ;
if ( F_128 ( V_23 ) != ' ' ) return - 19 ;
while ( V_177 -- ) {
char V_178 ;
#ifndef F_130
if ( F_131 ( V_178 , V_176 ) )
return - 23 ;
#else
V_178 = * V_176 ;
#endif
if ( F_127 ( V_23 , V_178 ) == - 1 )
return - 20 ;
V_176 ++ ;
}
if ( F_128 ( V_23 ) != '\r' ) return - 21 ;
if ( F_128 ( V_23 ) != '\n' ) return - 22 ;
if ( F_128 ( V_23 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: download completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_102 ( struct V_22 * V_23 , int V_135 )
{
if ( F_127 ( V_23 , 'g' ) == - 1 ) return - 1 ;
if ( F_128 ( V_23 ) != 'g' ) return - 2 ;
if ( F_128 ( V_23 ) != '=' ) return - 3 ;
if ( F_129 ( V_23 , V_135 ) < 0 ) return - 4 ;
if ( F_127 ( V_23 , '\r' ) == - 1 ) return - 5 ;
if ( F_128 ( V_23 ) != '\r' ) return - 6 ;
if ( F_128 ( V_23 ) != '\r' ) return - 7 ;
if ( F_128 ( V_23 ) != '\n' ) return - 8 ;
if ( F_128 ( V_23 ) != '\r' ) return - 9 ;
if ( F_128 ( V_23 ) != '\n' ) return - 10 ;
#if 0
printk(KERN_DEBUG "cosa%d: microcode started\n", cosa->num);
#endif
return 0 ;
}
static int F_100 ( struct V_22 * V_23 , char T_5 * V_176 , int V_177 , int V_135 )
{
if ( F_127 ( V_23 , 'r' ) == - 1 ) return - 1 ;
if ( ( F_128 ( V_23 ) ) != 'r' ) return - 2 ;
if ( ( F_128 ( V_23 ) ) != '=' ) return - 3 ;
if ( F_129 ( V_23 , V_135 ) < 0 ) return - 4 ;
if ( F_127 ( V_23 , ' ' ) == - 1 ) return - 5 ;
if ( F_128 ( V_23 ) != ' ' ) return - 6 ;
if ( F_128 ( V_23 ) != '=' ) return - 7 ;
if ( F_129 ( V_23 , V_135 + V_177 - 1 ) < 0 ) return - 8 ;
if ( F_127 ( V_23 , ' ' ) == - 1 ) return - 9 ;
if ( F_128 ( V_23 ) != ' ' ) return - 10 ;
while ( V_177 -- ) {
char V_178 ;
int V_5 ;
if ( ( V_5 = F_128 ( V_23 ) ) == - 1 ) {
F_23 ( L_54 , V_177 ) ;
return - 11 ;
}
V_178 = V_5 ;
#if 1
if ( F_132 ( V_178 , V_176 ) )
return - 23 ;
#else
* V_176 = V_178 ;
#endif
V_176 ++ ;
}
if ( F_128 ( V_23 ) != '\r' ) return - 21 ;
if ( F_128 ( V_23 ) != '\n' ) return - 22 ;
if ( F_128 ( V_23 ) != '.' ) return - 23 ;
#if 0
printk(KERN_DEBUG "cosa%d: readmem completed.\n", cosa->num);
#endif
return 0 ;
}
static int F_26 ( struct V_22 * V_23 , char * V_126 )
{
int V_5 = 0 , V_179 = 0 , V_180 = 0 , V_181 = 0 ;
F_31 ( V_23 , 0 ) ;
F_35 ( V_23 ) ;
F_31 ( V_23 , V_182 ) ;
F_133 ( 500 ) ;
F_31 ( V_23 , 0 ) ;
for ( V_5 = 0 ; V_5 < V_127 - 1 ; V_5 ++ , V_180 = V_181 ) {
if ( ( V_181 = F_128 ( V_23 ) ) == - 1 ) {
return - 1 ;
}
V_181 &= 0xff ;
if ( V_181 != '\r' && V_181 != '\n' && V_181 != 0x2e )
V_126 [ V_179 ++ ] = V_181 ;
if ( V_181 == 0x2e && V_180 == '\n' )
break;
}
V_126 [ V_179 ] = '\0' ;
return V_179 ;
}
static int F_128 ( struct V_22 * V_23 )
{
int V_183 = 1000 ;
while ( -- V_183 ) {
if ( F_134 ( V_23 ) & V_184 ) {
short V_185 ;
V_185 = F_35 ( V_23 ) ;
#if 0
pr_info("get_wait_data returning after %d retries\n",
999-retries);
#endif
return V_185 ;
}
F_135 ( 1 ) ;
}
F_23 ( L_55 ,
F_134 ( V_23 ) ) ;
return - 1 ;
}
static int F_127 ( struct V_22 * V_23 , int V_79 )
{
int V_183 = 1000 ;
while ( -- V_183 ) {
if ( F_134 ( V_23 ) & V_186 ) {
F_118 ( V_23 , V_79 ) ;
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
V_23 -> V_13 , F_134 ( V_23 ) ) ;
return - 1 ;
}
static int F_129 ( struct V_22 * V_23 , int V_187 )
{
char V_188 [ 5 ] ;
int V_5 ;
sprintf ( V_188 , L_57 , V_187 ) ;
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
if ( F_127 ( V_23 , V_188 [ V_5 ] ) == - 1 ) {
F_45 ( L_58 ,
V_23 -> V_13 , V_5 ) ;
return - 1 - 2 * V_5 ;
}
if ( F_128 ( V_23 ) != V_188 [ V_5 ] ) {
F_45 ( L_59 ,
V_23 -> V_13 , V_5 ) ;
return - 2 - 2 * V_5 ;
}
}
return 0 ;
}
static inline void F_136 ( struct V_22 * V_23 , int V_164 )
{
unsigned long V_65 , V_171 ;
#ifdef F_137
F_23 ( L_60 , V_23 -> V_13 , V_164 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_115 ( V_173 , & V_23 -> V_83 ) ;
if ( ! F_55 ( V_189 , & V_23 -> V_83 ) ) {
int V_5 = 0 ;
if ( ! V_23 -> V_163 ) {
F_5 ( L_61 ,
V_23 -> V_46 ) ;
F_120 ( V_23 ) ;
F_138 ( V_173 , & V_23 -> V_83 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
return;
}
while ( 1 ) {
V_23 -> V_190 ++ ;
V_5 ++ ;
if ( V_23 -> V_190 >= V_23 -> V_24 )
V_23 -> V_190 = 0 ;
if ( ! ( V_23 -> V_163 & ( 1 << V_23 -> V_190 ) ) )
continue;
if ( ~ V_164 & ( 1 << ( V_23 -> V_190 + V_167 ) ) )
break;
if ( V_5 > V_23 -> V_24 ) {
#ifdef F_137
F_27 ( V_33 L_62
L_63 ,
V_23 -> V_46 , V_23 -> V_190 ) ;
#endif
break;
}
}
V_23 -> V_162 = V_23 -> V_25 [ V_23 -> V_190 ] . V_162 ;
if ( F_126 ( V_23 -> V_25 + V_23 -> V_190 ,
V_23 -> V_25 [ V_23 -> V_190 ] . V_115 , V_23 -> V_162 ) ) {
V_23 -> V_115 = V_23 -> V_25 [ V_23 -> V_190 ] . V_115 ;
} else {
memcpy ( V_23 -> V_27 , V_23 -> V_25 [ V_23 -> V_190 ] . V_115 ,
V_23 -> V_162 ) ;
V_23 -> V_115 = V_23 -> V_27 ;
}
}
if ( F_22 ( V_23 ) ) {
if ( ! F_55 ( V_189 , & V_23 -> V_83 ) ) {
F_31 ( V_23 , V_37 ) ;
F_118 ( V_23 , ( ( V_23 -> V_190 << 5 ) & 0xe0 ) |
( ( V_23 -> V_162 >> 8 ) & 0x1f ) ) ;
#ifdef F_116
F_117 ( V_23 , V_37 ) ;
F_139 ( V_23 , ( ( V_23 -> V_190 << 5 ) & 0xe0 ) |
( ( V_23 -> V_162 >> 8 ) & 0x1f ) ) ;
F_140 ( V_23 , F_35 ( V_23 ) ) ;
#else
F_35 ( V_23 ) ;
#endif
F_115 ( V_189 , & V_23 -> V_83 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
return;
} else {
F_138 ( V_189 , & V_23 -> V_83 ) ;
F_31 ( V_23 , 0 ) ;
F_118 ( V_23 , V_23 -> V_162 & 0xff ) ;
#ifdef F_116
F_117 ( V_23 , 0 ) ;
F_139 ( V_23 , V_23 -> V_162 & 0xff ) ;
#endif
}
} else {
F_31 ( V_23 , V_37 ) ;
F_141 ( V_23 , ( ( V_23 -> V_190 << 13 ) & 0xe000 )
| ( V_23 -> V_162 & 0x1fff ) ) ;
#ifdef F_116
F_117 ( V_23 , V_37 ) ;
F_139 ( V_23 , ( ( V_23 -> V_190 << 13 ) & 0xe000 )
| ( V_23 -> V_162 & 0x1fff ) ) ;
F_140 ( V_23 , F_35 ( V_23 ) ) ;
F_117 ( V_23 , 0 ) ;
#else
F_35 ( V_23 ) ;
#endif
F_31 ( V_23 , 0 ) ;
}
if ( V_23 -> V_154 ) {
unsigned long V_131 = F_142 ( V_23 -> V_115 ) ;
int V_101 = 0 ;
F_23 ( L_64 ) ;
while ( ! ( F_134 ( V_23 ) & V_186 ) ) {
V_101 ++ ;
F_125 ( 10 ) ;
if ( V_101 > 1000 ) break;
}
F_23 ( L_65 , F_134 ( V_23 ) ) ;
F_23 ( L_66 , V_101 ) ;
F_141 ( V_23 , ( V_131 >> 16 ) & 0xffff ) ;
V_101 = 0 ;
while ( ! ( F_134 ( V_23 ) & V_186 ) ) {
V_101 ++ ;
if ( V_101 > 1000 ) break;
F_125 ( 10 ) ;
}
F_23 ( L_66 , V_101 ) ;
F_141 ( V_23 , V_131 & 0xffff ) ;
V_171 = F_121 () ;
F_143 ( V_23 -> V_16 , V_191 ) ;
F_144 ( V_23 -> V_16 ) ;
F_124 ( V_171 ) ;
} else {
V_171 = F_121 () ;
F_122 ( V_23 -> V_16 ) ;
F_123 ( V_23 -> V_16 ) ;
F_143 ( V_23 -> V_16 , V_192 ) ;
F_145 ( V_23 -> V_16 , F_142 ( V_23 -> V_115 ) ) ;
F_146 ( V_23 -> V_16 , V_23 -> V_162 ) ;
F_144 ( V_23 -> V_16 ) ;
F_124 ( V_171 ) ;
}
F_31 ( V_23 , V_193 | V_194 ) ;
#ifdef F_116
F_117 ( V_23 , V_193 | V_194 ) ;
#endif
F_48 ( & V_23 -> V_31 , V_65 ) ;
}
static inline void F_147 ( struct V_22 * V_23 , int V_164 )
{
unsigned long V_65 ;
#ifdef F_137
F_23 ( L_67 , V_23 -> V_13 ) ;
#endif
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_115 ( V_82 , & V_23 -> V_83 ) ;
if ( F_22 ( V_23 ) ) {
if ( ! F_55 ( V_189 , & V_23 -> V_83 ) ) {
F_115 ( V_189 , & V_23 -> V_83 ) ;
F_120 ( V_23 ) ;
V_23 -> V_96 = F_35 ( V_23 ) << 8 ;
#ifdef F_116
F_140 ( V_23 , V_23 -> V_96 >> 8 ) ;
#endif
F_48 ( & V_23 -> V_31 , V_65 ) ;
return;
} else {
F_138 ( V_189 , & V_23 -> V_83 ) ;
V_23 -> V_96 |= F_35 ( V_23 ) & 0xff ;
#ifdef F_116
F_140 ( V_23 , V_23 -> V_96 & 0xff ) ;
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
} else {
V_23 -> V_96 = F_148 ( V_23 ) ;
#ifdef F_116
F_140 ( V_23 , V_23 -> V_96 ) ;
#endif
#if 0
pr_info("cosa%d: receive rxsize = (0x%04x)\n",
cosa->num, cosa->rxsize);
#endif
}
if ( ( ( V_23 -> V_96 & 0xe000 ) >> 13 ) >= V_23 -> V_24 ) {
F_5 ( L_68 ,
V_23 -> V_46 , V_23 -> V_96 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
goto V_195;
}
V_23 -> V_196 = V_23 -> V_25 + ( ( V_23 -> V_96 & 0xe000 ) >> 13 ) ;
V_23 -> V_96 &= 0x1fff ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
V_23 -> V_197 = NULL ;
if ( V_23 -> V_196 -> V_70 )
V_23 -> V_197 = V_23 -> V_196 -> V_70 ( V_23 -> V_196 , V_23 -> V_96 ) ;
if ( ! V_23 -> V_197 ) {
V_195:
F_23 ( L_69 ,
V_23 -> V_13 , V_23 -> V_196 -> V_13 ) ;
V_23 -> V_197 = V_23 -> V_27 ;
}
V_65 = F_121 () ;
F_122 ( V_23 -> V_16 ) ;
F_123 ( V_23 -> V_16 ) ;
F_143 ( V_23 -> V_16 , V_198 ) ;
if ( F_126 ( V_23 -> V_196 , V_23 -> V_197 , V_23 -> V_96 & 0x1fff ) ) {
F_145 ( V_23 -> V_16 , F_142 ( V_23 -> V_197 ) ) ;
} else {
F_145 ( V_23 -> V_16 , F_142 ( V_23 -> V_27 ) ) ;
}
F_146 ( V_23 -> V_16 , ( V_23 -> V_96 & 0x1fff ) ) ;
F_144 ( V_23 -> V_16 ) ;
F_124 ( V_65 ) ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
F_31 ( V_23 , V_199 | V_194 ) ;
if ( ! F_22 ( V_23 ) && ( V_164 & V_186 ) )
F_118 ( V_23 , V_165 ) ;
#ifdef F_116
F_117 ( V_23 , V_199 | V_194 ) ;
if ( ! F_22 ( V_23 ) && ( V_164 & V_186 ) )
F_119 ( V_23 , V_165 ) ;
#endif
F_48 ( & V_23 -> V_31 , V_65 ) ;
}
static inline void F_149 ( struct V_22 * V_23 , int V_164 )
{
unsigned long V_65 , V_171 ;
F_47 ( & V_23 -> V_31 , V_65 ) ;
V_171 = F_121 () ;
F_122 ( V_23 -> V_16 ) ;
F_123 ( V_23 -> V_16 ) ;
F_124 ( V_171 ) ;
if ( F_55 ( V_173 , & V_23 -> V_83 ) ) {
struct V_1 * V_25 = V_23 -> V_25 + V_23 -> V_190 ;
if ( V_25 -> V_72 )
if ( V_25 -> V_72 ( V_25 , V_23 -> V_162 ) )
F_138 ( V_25 -> V_13 , & V_23 -> V_163 ) ;
} else if ( F_55 ( V_82 , & V_23 -> V_83 ) ) {
#ifdef F_113
{
int V_5 ;
F_23 ( L_70 ,
V_23 -> V_13 , V_23 -> V_196 -> V_13 , V_23 -> V_96 ) ;
for ( V_5 = 0 ; V_5 < V_23 -> V_96 ; V_5 ++ )
F_114 ( L_46 , V_23 -> V_197 [ V_5 ] & 0xff ) ;
F_114 ( L_47 ) ;
}
#endif
if ( V_23 -> V_197 == V_23 -> V_27 )
goto V_10;
if ( ! F_126 ( V_23 -> V_196 , V_23 -> V_197 , V_23 -> V_96 ) )
memcpy ( V_23 -> V_197 , V_23 -> V_27 , V_23 -> V_96 ) ;
if ( V_23 -> V_196 -> V_74 )
if ( V_23 -> V_196 -> V_74 ( V_23 -> V_196 ) )
F_138 ( V_23 -> V_196 -> V_13 , & V_23 -> V_161 ) ;
} else {
F_45 ( L_71 , V_23 -> V_13 ) ;
}
V_10:
V_23 -> V_83 = 0 ;
F_120 ( V_23 ) ;
F_48 ( & V_23 -> V_31 , V_65 ) ;
}
static T_9 V_39 ( int V_15 , void * V_200 )
{
unsigned V_164 ;
int V_101 = 0 ;
struct V_22 * V_23 = V_200 ;
V_201:
V_164 = F_134 ( V_23 ) ;
#ifdef F_137
F_23 ( L_72 , V_23 -> V_13 , V_164 & 0xff ) ;
#endif
#ifdef F_116
F_150 ( V_23 , V_164 ) ;
#endif
switch ( V_164 & V_202 ) {
case V_203 :
F_136 ( V_23 , V_164 ) ;
break;
case V_204 :
F_147 ( V_23 , V_164 ) ;
break;
case V_205 :
F_149 ( V_23 , V_164 ) ;
break;
default:
if ( V_101 ++ < 100 ) {
F_125 ( 100 ) ;
goto V_201;
}
F_23 ( L_73 ,
V_23 -> V_13 , V_164 & 0xff , V_101 ) ;
}
#ifdef F_137
if ( V_101 )
F_23 ( L_74 ,
V_23 -> V_46 , V_101 ) ;
else
F_23 ( L_75 , V_23 -> V_46 ) ;
#endif
return V_206 ;
}
static void F_150 ( struct V_22 * V_23 , int V_164 )
{
char * V_172 ;
switch ( V_164 & V_202 ) {
case V_204 :
V_172 = L_76 ;
break;
case V_203 :
V_172 = L_77 ;
break;
case V_205 :
V_172 = L_78 ;
break;
default:
V_172 = L_79 ;
break;
}
F_23 ( L_80 ,
V_23 -> V_46 ,
V_164 ,
V_164 & V_207 ? L_81 : L_82 ,
V_164 & V_186 ? L_83 : L_82 ,
V_164 & V_184 ? L_84 : L_82 ,
V_172 ) ;
}
static void F_117 ( struct V_22 * V_23 , int V_164 )
{
F_23 ( L_85 ,
V_23 -> V_46 ,
V_164 ,
V_164 & V_199 ? L_86 : L_87 ,
V_164 & V_193 ? L_88 : L_89 ,
V_164 & V_182 ? L_90 : L_82 ,
V_164 & V_194 ? L_91 : L_92 ,
V_164 & V_37 ? L_93 : L_94 ,
V_164 & V_170 ? L_95 : L_96 ) ;
}
static void F_140 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_97 , V_23 -> V_46 , V_79 ) ;
}
static void F_139 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_98 , V_23 -> V_46 , V_79 ) ;
}
static void F_119 ( struct V_22 * V_23 , int V_79 )
{
F_23 ( L_99 ,
V_23 -> V_46 , V_79 ,
V_79 & V_208 ? L_100 : L_101 ,
V_79 & V_209 ? L_102 : L_103 ) ;
}
