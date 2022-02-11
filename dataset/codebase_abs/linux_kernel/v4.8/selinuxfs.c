static int T_1 F_1 ( char * V_1 )
{
unsigned long V_2 ;
if ( ! F_2 ( V_1 , 0 , & V_2 ) )
V_3 = V_2 ? 1 : 0 ;
return 1 ;
}
static int F_3 ( struct V_4 * V_5 ,
T_2 V_6 )
{
const struct V_7 * V_8 ;
T_2 V_9 = 0 ;
F_4 () ;
V_8 = F_5 ( V_5 ) -> V_10 ;
if ( V_8 )
V_9 = V_8 -> V_9 ;
F_6 () ;
if ( ! V_8 )
return - V_11 ;
return F_7 ( V_9 , V_12 ,
V_13 , V_6 , NULL ) ;
}
static T_3 F_8 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_22 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_11 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
if ( V_17 >= V_25 )
return - V_26 ;
if ( * V_18 != 0 )
return - V_27 ;
V_23 = F_12 ( V_16 , V_17 ) ;
if ( F_13 ( V_23 ) )
return F_14 ( V_23 ) ;
V_21 = - V_27 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_28;
if ( V_24 != V_22 ) {
V_21 = F_3 ( V_29 , V_30 ) ;
if ( V_21 )
goto V_28;
F_15 ( V_29 -> V_31 , V_32 , V_33 ,
L_2 ,
V_24 , V_22 ,
F_16 ( & V_34 , F_17 ( V_29 ) ) ,
F_18 ( V_29 ) ) ;
V_22 = V_24 ;
if ( V_22 )
F_19 ( 0 ) ;
F_20 ( V_22 ) ;
F_21 ( V_22 ) ;
}
V_21 = V_17 ;
V_28:
F_22 ( V_23 ) ;
return V_21 ;
}
static T_3 F_23 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
T_7 V_35 = F_24 ( V_15 ) -> V_36 ;
int V_37 = ( V_35 == V_38 ) ?
F_25 () : ! F_26 () ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_37 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_27 ( struct V_39 * V_39 , struct V_14 * V_15 )
{
struct V_23 * V_40 = F_28 () ;
if ( ! V_40 )
return - V_26 ;
V_15 -> V_41 = V_40 ;
return 0 ;
}
static T_3 F_29 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
struct V_23 * V_40 = V_15 -> V_41 ;
F_30 ( ! V_40 ) ;
return F_10 ( V_16 , V_17 , V_18 ,
F_31 ( V_40 ) ,
sizeof( struct V_42 ) ) ;
}
static int F_32 ( struct V_14 * V_15 ,
struct V_43 * V_44 )
{
struct V_23 * V_40 = V_15 -> V_41 ;
unsigned long V_45 = V_44 -> V_46 - V_44 -> V_47 ;
F_30 ( ! V_40 ) ;
if ( V_44 -> V_48 > 0 || V_45 != V_25 )
return - V_49 ;
if ( V_44 -> V_50 & V_51 )
return - V_52 ;
V_44 -> V_50 &= ~ V_53 ;
return F_33 ( V_44 , V_44 -> V_47 ,
F_34 ( V_40 ) ,
V_45 , V_44 -> V_54 ) ;
}
static T_3 F_35 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_21 ;
int V_24 ;
if ( V_17 >= V_25 )
return - V_26 ;
if ( * V_18 != 0 )
return - V_27 ;
V_23 = F_12 ( V_16 , V_17 ) ;
if ( F_13 ( V_23 ) )
return F_14 ( V_23 ) ;
V_21 = - V_27 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_28;
if ( V_24 ) {
V_21 = F_36 () ;
if ( V_21 )
goto V_28;
F_15 ( V_29 -> V_31 , V_32 , V_33 ,
L_3 ,
F_16 ( & V_34 , F_17 ( V_29 ) ) ,
F_18 ( V_29 ) ) ;
}
V_21 = V_17 ;
V_28:
F_22 ( V_23 ) ;
return V_21 ;
}
static T_3 F_37 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_55 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_38 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_1 ,
F_39 () ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_40 ( struct V_39 * V_39 , struct V_14 * V_15 )
{
struct V_56 * V_57 = NULL ;
int V_58 ;
F_30 ( V_15 -> V_41 ) ;
F_41 ( & V_59 ) ;
V_58 = F_3 ( V_29 , V_60 ) ;
if ( V_58 )
goto V_61;
V_58 = - V_62 ;
if ( V_63 )
goto V_61;
V_58 = - V_26 ;
V_57 = F_42 ( sizeof( * V_57 ) , V_32 ) ;
if ( ! V_57 )
goto V_61;
if ( F_43 ( V_39 ) != F_44 () ) {
F_45 ( V_39 ) ;
F_46 ( V_39 , F_44 () ) ;
F_47 ( V_39 ) ;
}
V_58 = F_48 ( & V_57 -> V_64 , & V_57 -> V_65 ) ;
if ( V_58 )
goto V_61;
V_63 = 1 ;
V_15 -> V_41 = V_57 ;
F_49 ( & V_59 ) ;
return 0 ;
V_61:
F_49 ( & V_59 ) ;
if ( V_57 )
F_50 ( V_57 -> V_64 ) ;
F_22 ( V_57 ) ;
return V_58 ;
}
static int F_51 ( struct V_39 * V_39 , struct V_14 * V_15 )
{
struct V_56 * V_57 = V_15 -> V_41 ;
F_30 ( ! V_57 ) ;
V_63 = 0 ;
F_50 ( V_57 -> V_64 ) ;
F_22 ( V_57 ) ;
return 0 ;
}
static T_3 F_52 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
struct V_56 * V_57 = V_15 -> V_41 ;
int V_66 ;
F_41 ( & V_59 ) ;
V_66 = F_3 ( V_29 , V_60 ) ;
if ( V_66 )
goto V_28;
V_66 = F_10 ( V_16 , V_17 , V_18 , V_57 -> V_64 , V_57 -> V_65 ) ;
V_28:
F_49 ( & V_59 ) ;
return V_66 ;
}
static int F_53 ( struct V_43 * V_44 ,
struct V_67 * V_68 )
{
struct V_56 * V_57 = V_44 -> V_69 -> V_41 ;
unsigned long V_70 ;
struct V_23 * V_23 ;
if ( V_68 -> V_71 & ( V_72 | V_73 ) )
return V_74 ;
V_70 = V_68 -> V_75 << V_76 ;
if ( V_70 >= F_54 ( V_57 -> V_65 , V_25 ) )
return V_74 ;
V_23 = F_55 ( V_57 -> V_64 + V_70 ) ;
F_56 ( V_23 ) ;
V_68 -> V_23 = V_23 ;
return 0 ;
}
static int F_57 ( struct V_14 * V_15 , struct V_43 * V_44 )
{
if ( V_44 -> V_50 & V_77 ) {
V_44 -> V_50 &= ~ V_53 ;
if ( V_44 -> V_50 & V_51 )
return - V_11 ;
}
V_44 -> V_50 |= V_78 | V_79 ;
V_44 -> V_80 = & V_81 ;
return 0 ;
}
static T_3 F_58 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
T_3 V_21 ;
void * V_64 = NULL ;
F_41 ( & V_59 ) ;
V_21 = F_3 ( V_29 , V_82 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_27 ;
if ( * V_18 != 0 )
goto V_28;
V_21 = - V_83 ;
if ( V_17 > 64 * 1024 * 1024 )
goto V_28;
V_21 = - V_26 ;
V_64 = F_59 ( V_17 ) ;
if ( ! V_64 )
goto V_28;
V_21 = - V_84 ;
if ( F_60 ( V_64 , V_16 , V_17 ) != 0 )
goto V_28;
V_21 = F_61 ( V_64 , V_17 ) ;
if ( V_21 )
goto V_28;
V_21 = F_62 () ;
if ( V_21 )
goto V_85;
V_21 = F_63 () ;
if ( V_21 )
goto V_85;
V_21 = F_64 () ;
if ( V_21 )
goto V_85;
V_21 = V_17 ;
V_85:
F_15 ( V_29 -> V_31 , V_32 , V_86 ,
L_5 ,
F_16 ( & V_34 , F_17 ( V_29 ) ) ,
F_18 ( V_29 ) ) ;
V_28:
F_49 ( & V_59 ) ;
F_50 ( V_64 ) ;
return V_21 ;
}
static T_3 F_65 ( struct V_14 * V_14 , char * V_16 , T_5 V_45 )
{
char * V_87 = NULL ;
T_2 V_9 , V_65 ;
T_3 V_21 ;
V_21 = F_3 ( V_29 , V_88 ) ;
if ( V_21 )
goto V_28;
V_21 = F_66 ( V_16 , V_45 , & V_9 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_67 ( V_9 , & V_87 , & V_65 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_89 ;
if ( V_65 > V_90 ) {
F_68 ( V_91 L_6
L_7 , V_92 , V_65 ) ;
goto V_28;
}
memcpy ( V_16 , V_87 , V_65 ) ;
V_21 = V_65 ;
V_28:
F_22 ( V_87 ) ;
return V_21 ;
}
static T_3 F_69 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_3 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_70 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_21 ;
unsigned int V_24 ;
V_21 = F_3 ( V_29 , V_93 ) ;
if ( V_21 )
return V_21 ;
if ( V_17 >= V_25 )
return - V_26 ;
if ( * V_18 != 0 )
return - V_27 ;
V_23 = F_12 ( V_16 , V_17 ) ;
if ( F_13 ( V_23 ) )
return F_14 ( V_23 ) ;
V_21 = - V_27 ;
if ( sscanf ( V_23 , L_4 , & V_24 ) != 1 )
goto V_28;
V_3 = V_24 ? 1 : 0 ;
V_21 = V_17 ;
V_28:
F_22 ( V_23 ) ;
return V_21 ;
}
static T_3 F_71 ( struct V_14 * V_14 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_94 = NULL , * V_95 = NULL , * V_96 = NULL ;
char * V_97 = NULL ;
T_2 V_98 , V_99 , V_100 ;
T_8 V_101 ;
int V_58 ;
V_58 = F_3 ( V_29 , V_102 ) ;
if ( V_58 )
goto V_28;
V_58 = - V_26 ;
if ( V_17 >= V_25 )
goto V_28;
V_58 = - V_27 ;
if ( * V_18 != 0 )
goto V_28;
V_58 = - V_26 ;
V_97 = F_42 ( V_17 + 1 , V_32 ) ;
if ( ! V_97 )
goto V_28;
V_58 = - V_84 ;
if ( F_60 ( V_97 , V_16 , V_17 ) )
goto V_28;
V_58 = - V_26 ;
V_94 = F_42 ( V_17 + 1 , V_32 ) ;
if ( ! V_94 )
goto V_28;
V_95 = F_42 ( V_17 + 1 , V_32 ) ;
if ( ! V_95 )
goto V_28;
V_96 = F_42 ( V_17 + 1 , V_32 ) ;
if ( ! V_96 )
goto V_28;
V_58 = - V_27 ;
if ( sscanf ( V_97 , L_8 , V_94 , V_95 , & V_101 , V_96 ) != 4 )
goto V_28;
V_58 = F_72 ( V_94 , & V_98 , V_32 ) ;
if ( V_58 )
goto V_28;
V_58 = F_72 ( V_95 , & V_99 , V_32 ) ;
if ( V_58 )
goto V_28;
V_58 = F_72 ( V_96 , & V_100 , V_32 ) ;
if ( V_58 )
goto V_28;
V_58 = F_73 ( V_98 , V_99 , V_100 , V_101 ) ;
if ( ! V_58 )
V_58 = V_17 ;
V_28:
F_22 ( V_97 ) ;
F_22 ( V_94 ) ;
F_22 ( V_95 ) ;
F_22 ( V_96 ) ;
return V_58 ;
}
static T_3 F_74 ( struct V_14 * V_14 , const char T_4 * V_16 , T_5 V_45 , T_6 * V_103 )
{
T_7 V_35 = F_24 ( V_14 ) -> V_36 ;
char * V_64 ;
T_3 V_104 ;
if ( V_35 >= F_75 ( V_105 ) || ! V_105 [ V_35 ] )
return - V_27 ;
V_64 = F_76 ( V_14 , V_16 , V_45 ) ;
if ( F_13 ( V_64 ) )
return F_14 ( V_64 ) ;
V_104 = V_105 [ V_35 ] ( V_14 , V_64 , V_45 ) ;
if ( V_104 > 0 ) {
F_77 ( V_14 , V_104 ) ;
V_104 = V_45 ;
}
return V_104 ;
}
static T_3 F_78 ( struct V_14 * V_14 , char * V_16 , T_5 V_45 )
{
char * V_106 = NULL , * V_107 = NULL ;
T_2 V_108 , V_100 ;
T_8 V_101 ;
struct V_109 V_110 ;
T_3 V_21 ;
V_21 = F_3 ( V_29 , V_111 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_26 ;
V_106 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_106 )
goto V_28;
V_21 = - V_26 ;
V_107 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_107 )
goto V_28;
V_21 = - V_27 ;
if ( sscanf ( V_16 , L_9 , V_106 , V_107 , & V_101 ) != 3 )
goto V_28;
V_21 = F_72 ( V_106 , & V_108 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_72 ( V_107 , & V_100 , V_32 ) ;
if ( V_21 )
goto V_28;
F_79 ( V_108 , V_100 , V_101 , & V_110 ) ;
V_21 = F_9 ( V_16 , V_90 ,
L_10 ,
V_110 . V_112 , 0xffffffff ,
V_110 . V_113 , V_110 . V_114 ,
V_110 . V_115 , V_110 . V_71 ) ;
V_28:
F_22 ( V_107 ) ;
F_22 ( V_106 ) ;
return V_21 ;
}
static T_3 F_80 ( struct V_14 * V_14 , char * V_16 , T_5 V_45 )
{
char * V_106 = NULL , * V_107 = NULL ;
char * V_116 = NULL , * V_117 = NULL ;
T_2 V_108 , V_100 , V_118 ;
T_8 V_101 ;
T_3 V_21 ;
char * V_95 = NULL ;
T_2 V_65 ;
int V_119 ;
V_21 = F_3 ( V_29 , V_120 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_26 ;
V_106 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_106 )
goto V_28;
V_21 = - V_26 ;
V_107 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_107 )
goto V_28;
V_21 = - V_26 ;
V_116 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_116 )
goto V_28;
V_21 = - V_27 ;
V_119 = sscanf ( V_16 , L_8 , V_106 , V_107 , & V_101 , V_116 ) ;
if ( V_119 < 3 || V_119 > 4 )
goto V_28;
if ( V_119 == 4 ) {
char * V_121 , * V_122 ;
int V_123 , V_124 ;
V_121 = V_122 = V_116 ;
do {
V_123 = * V_121 ++ ;
if ( V_123 == '+' )
V_123 = ' ' ;
else if ( V_123 == '%' ) {
V_123 = F_81 ( * V_121 ++ ) ;
if ( V_123 < 0 )
goto V_28;
V_124 = F_81 ( * V_121 ++ ) ;
if ( V_124 < 0 )
goto V_28;
V_123 = ( V_123 << 4 ) | V_124 ;
}
* V_122 ++ = V_123 ;
} while ( V_123 != '\0' );
V_117 = V_116 ;
}
V_21 = F_72 ( V_106 , & V_108 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_72 ( V_107 , & V_100 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_82 ( V_108 , V_100 , V_101 ,
V_117 , & V_118 ) ;
if ( V_21 )
goto V_28;
V_21 = F_67 ( V_118 , & V_95 , & V_65 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_89 ;
if ( V_65 > V_90 ) {
F_68 ( V_91 L_6
L_7 , V_92 , V_65 ) ;
goto V_28;
}
memcpy ( V_16 , V_95 , V_65 ) ;
V_21 = V_65 ;
V_28:
F_22 ( V_95 ) ;
F_22 ( V_116 ) ;
F_22 ( V_107 ) ;
F_22 ( V_106 ) ;
return V_21 ;
}
static T_3 F_83 ( struct V_14 * V_14 , char * V_16 , T_5 V_45 )
{
char * V_106 = NULL , * V_107 = NULL ;
T_2 V_108 , V_100 , V_118 ;
T_8 V_101 ;
T_3 V_21 ;
char * V_95 = NULL ;
T_2 V_65 ;
V_21 = F_3 ( V_29 , V_125 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_26 ;
V_106 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_106 )
goto V_28;
V_21 = - V_26 ;
V_107 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_107 )
goto V_28;
V_21 = - V_27 ;
if ( sscanf ( V_16 , L_9 , V_106 , V_107 , & V_101 ) != 3 )
goto V_28;
V_21 = F_72 ( V_106 , & V_108 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_72 ( V_107 , & V_100 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_84 ( V_108 , V_100 , V_101 , & V_118 ) ;
if ( V_21 )
goto V_28;
V_21 = F_67 ( V_118 , & V_95 , & V_65 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_89 ;
if ( V_65 > V_90 )
goto V_28;
memcpy ( V_16 , V_95 , V_65 ) ;
V_21 = V_65 ;
V_28:
F_22 ( V_95 ) ;
F_22 ( V_107 ) ;
F_22 ( V_106 ) ;
return V_21 ;
}
static T_3 F_85 ( struct V_14 * V_14 , char * V_16 , T_5 V_45 )
{
char * V_126 = NULL , * V_127 = NULL , * V_128 ;
T_2 V_9 , * V_129 = NULL ;
T_3 V_21 ;
char * V_95 ;
int V_130 , V_58 ;
T_2 V_65 , V_131 ;
V_21 = F_3 ( V_29 , V_132 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_26 ;
V_126 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_126 )
goto V_28;
V_21 = - V_26 ;
V_127 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_127 )
goto V_28;
V_21 = - V_27 ;
if ( sscanf ( V_16 , L_11 , V_126 , V_127 ) != 2 )
goto V_28;
V_21 = F_72 ( V_126 , & V_9 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_86 ( V_9 , V_127 , & V_129 , & V_131 ) ;
if ( V_21 )
goto V_28;
V_21 = sprintf ( V_16 , L_4 , V_131 ) + 1 ;
V_128 = V_16 + V_21 ;
for ( V_130 = 0 ; V_130 < V_131 ; V_130 ++ ) {
V_58 = F_67 ( V_129 [ V_130 ] , & V_95 , & V_65 ) ;
if ( V_58 ) {
V_21 = V_58 ;
goto V_28;
}
if ( ( V_21 + V_65 ) >= V_90 ) {
F_22 ( V_95 ) ;
V_21 = - V_89 ;
goto V_28;
}
memcpy ( V_128 , V_95 , V_65 ) ;
F_22 ( V_95 ) ;
V_128 += V_65 ;
V_21 += V_65 ;
}
V_28:
F_22 ( V_129 ) ;
F_22 ( V_127 ) ;
F_22 ( V_126 ) ;
return V_21 ;
}
static T_3 F_87 ( struct V_14 * V_14 , char * V_16 , T_5 V_45 )
{
char * V_106 = NULL , * V_107 = NULL ;
T_2 V_108 , V_100 , V_118 ;
T_8 V_101 ;
T_3 V_21 ;
char * V_95 = NULL ;
T_2 V_65 ;
V_21 = F_3 ( V_29 , V_133 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_26 ;
V_106 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_106 )
goto V_28;
V_21 = - V_26 ;
V_107 = F_42 ( V_45 + 1 , V_32 ) ;
if ( ! V_107 )
goto V_28;
V_21 = - V_27 ;
if ( sscanf ( V_16 , L_9 , V_106 , V_107 , & V_101 ) != 3 )
goto V_28;
V_21 = F_72 ( V_106 , & V_108 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_72 ( V_107 , & V_100 , V_32 ) ;
if ( V_21 )
goto V_28;
V_21 = F_88 ( V_108 , V_100 , V_101 , & V_118 ) ;
if ( V_21 )
goto V_28;
V_21 = F_67 ( V_118 , & V_95 , & V_65 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_89 ;
if ( V_65 > V_90 ) {
F_68 ( V_91 L_6
L_7 , V_92 , V_65 ) ;
goto V_28;
}
memcpy ( V_16 , V_95 , V_65 ) ;
V_21 = V_65 ;
V_28:
F_22 ( V_95 ) ;
F_22 ( V_107 ) ;
F_22 ( V_106 ) ;
return V_21 ;
}
static struct V_39 * F_89 ( struct V_134 * V_135 , int V_136 )
{
struct V_39 * V_66 = F_90 ( V_135 ) ;
if ( V_66 ) {
V_66 -> V_137 = V_136 ;
V_66 -> V_138 = V_66 -> V_139 = V_66 -> V_140 = V_141 ;
}
return V_66 ;
}
static T_3 F_91 ( struct V_14 * V_142 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
T_3 V_66 ;
int V_143 ;
unsigned V_144 = F_24 ( V_142 ) -> V_36 & V_145 ;
const char * V_146 = V_142 -> V_147 . V_148 -> V_149 . V_146 ;
F_41 ( & V_59 ) ;
V_66 = - V_27 ;
if ( V_144 >= V_150 || strcmp ( V_146 , V_151 [ V_144 ] ) )
goto V_28;
V_66 = - V_26 ;
V_23 = ( char * ) F_92 ( V_32 ) ;
if ( ! V_23 )
goto V_28;
V_143 = F_93 ( V_144 ) ;
if ( V_143 < 0 ) {
V_66 = V_143 ;
goto V_28;
}
V_21 = F_9 ( V_23 , V_25 , L_12 , V_143 ,
V_152 [ V_144 ] ) ;
V_66 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
V_28:
F_49 ( & V_59 ) ;
F_94 ( ( unsigned long ) V_23 ) ;
return V_66 ;
}
static T_3 F_95 ( struct V_14 * V_142 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
unsigned V_144 = F_24 ( V_142 ) -> V_36 & V_145 ;
const char * V_146 = V_142 -> V_147 . V_148 -> V_149 . V_146 ;
F_41 ( & V_59 ) ;
V_21 = F_3 ( V_29 , V_153 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_27 ;
if ( V_144 >= V_150 || strcmp ( V_146 , V_151 [ V_144 ] ) )
goto V_28;
V_21 = - V_26 ;
if ( V_17 >= V_25 )
goto V_28;
V_21 = - V_27 ;
if ( * V_18 != 0 )
goto V_28;
V_23 = F_12 ( V_16 , V_17 ) ;
if ( F_13 ( V_23 ) ) {
V_21 = F_14 ( V_23 ) ;
V_23 = NULL ;
goto V_28;
}
V_21 = - V_27 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_28;
if ( V_24 )
V_24 = 1 ;
V_152 [ V_144 ] = V_24 ;
V_21 = V_17 ;
V_28:
F_49 ( & V_59 ) ;
F_22 ( V_23 ) ;
return V_21 ;
}
static T_3 F_96 ( struct V_14 * V_142 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
F_41 ( & V_59 ) ;
V_21 = F_3 ( V_29 , V_153 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_26 ;
if ( V_17 >= V_25 )
goto V_28;
V_21 = - V_27 ;
if ( * V_18 != 0 )
goto V_28;
V_23 = F_12 ( V_16 , V_17 ) ;
if ( F_13 ( V_23 ) ) {
V_21 = F_14 ( V_23 ) ;
V_23 = NULL ;
goto V_28;
}
V_21 = - V_27 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_28;
V_21 = 0 ;
if ( V_24 && V_152 )
V_21 = F_97 ( V_150 , V_152 ) ;
if ( ! V_21 )
V_21 = V_17 ;
V_28:
F_49 ( & V_59 ) ;
F_22 ( V_23 ) ;
return V_21 ;
}
static void F_98 ( struct V_148 * V_154 )
{
F_99 ( V_154 ) ;
F_100 ( V_154 ) ;
}
static int F_62 ( void )
{
int V_130 , V_66 ;
T_3 V_65 ;
struct V_148 * V_148 = NULL ;
struct V_148 * V_155 = V_156 ;
struct V_39 * V_39 = NULL ;
struct V_157 * V_158 ;
char * * V_159 = NULL , * V_23 ;
int V_160 ;
int * V_161 = NULL ;
T_2 V_9 ;
for ( V_130 = 0 ; V_130 < V_150 ; V_130 ++ )
F_22 ( V_151 [ V_130 ] ) ;
F_22 ( V_151 ) ;
F_22 ( V_152 ) ;
V_150 = 0 ;
V_151 = NULL ;
V_152 = NULL ;
F_98 ( V_155 ) ;
V_66 = - V_26 ;
V_23 = ( char * ) F_92 ( V_32 ) ;
if ( ! V_23 )
goto V_28;
V_66 = F_101 ( & V_160 , & V_159 , & V_161 ) ;
if ( V_66 )
goto V_28;
for ( V_130 = 0 ; V_130 < V_160 ; V_130 ++ ) {
V_66 = - V_26 ;
V_148 = F_102 ( V_155 , V_159 [ V_130 ] ) ;
if ( ! V_148 )
goto V_28;
V_66 = - V_26 ;
V_39 = F_89 ( V_155 -> V_162 , V_163 | V_164 | V_165 ) ;
if ( ! V_39 )
goto V_28;
V_66 = - V_166 ;
V_65 = snprintf ( V_23 , V_25 , L_13 , V_167 , V_159 [ V_130 ] ) ;
if ( V_65 >= V_25 )
goto V_28;
V_158 = (struct V_157 * ) V_39 -> V_168 ;
V_66 = F_103 ( L_14 , V_23 , V_169 , & V_9 ) ;
if ( V_66 )
goto V_28;
V_158 -> V_9 = V_9 ;
V_158 -> V_170 = 1 ;
V_39 -> V_171 = & V_172 ;
V_39 -> V_36 = V_130 | V_173 ;
F_104 ( V_148 , V_39 ) ;
}
V_150 = V_160 ;
V_151 = V_159 ;
V_152 = V_161 ;
F_94 ( ( unsigned long ) V_23 ) ;
return 0 ;
V_28:
F_94 ( ( unsigned long ) V_23 ) ;
if ( V_159 ) {
for ( V_130 = 0 ; V_130 < V_160 ; V_130 ++ )
F_22 ( V_159 [ V_130 ] ) ;
F_22 ( V_159 ) ;
}
F_22 ( V_161 ) ;
F_98 ( V_155 ) ;
return V_66 ;
}
static T_3 F_105 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_174 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_106 ( struct V_14 * V_14 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_66 ;
unsigned int V_24 ;
V_66 = F_3 ( V_29 , V_175 ) ;
if ( V_66 )
return V_66 ;
if ( V_17 >= V_25 )
return - V_26 ;
if ( * V_18 != 0 )
return - V_27 ;
V_23 = F_12 ( V_16 , V_17 ) ;
if ( F_13 ( V_23 ) )
return F_14 ( V_23 ) ;
V_66 = - V_27 ;
if ( sscanf ( V_23 , L_4 , & V_24 ) != 1 )
goto V_28;
V_174 = V_24 ;
V_66 = V_17 ;
V_28:
F_22 ( V_23 ) ;
return V_66 ;
}
static T_3 F_107 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_21 ;
V_23 = ( char * ) F_108 ( V_32 ) ;
if ( ! V_23 )
return - V_26 ;
V_21 = F_109 ( V_23 ) ;
if ( V_21 >= 0 )
V_21 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
F_94 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static struct V_176 * F_110 ( T_6 * V_177 )
{
int V_178 ;
for ( V_178 = * V_177 ; V_178 < V_179 ; ++ V_178 ) {
if ( ! F_111 ( V_178 ) )
continue;
* V_177 = V_178 + 1 ;
return & F_112 ( V_176 , V_178 ) ;
}
return NULL ;
}
static void * F_113 ( struct V_180 * V_181 , T_6 * V_103 )
{
T_6 V_182 = * V_103 - 1 ;
if ( * V_103 == 0 )
return V_183 ;
return F_110 ( & V_182 ) ;
}
static void * F_114 ( struct V_180 * V_181 , void * V_184 , T_6 * V_103 )
{
return F_110 ( V_103 ) ;
}
static int F_115 ( struct V_180 * V_181 , void * V_184 )
{
struct V_176 * V_185 = V_184 ;
if ( V_184 == V_183 )
F_116 ( V_181 , L_15
L_16 ) ;
else {
unsigned int V_186 = V_185 -> V_186 ;
unsigned int V_187 = V_185 -> V_187 ;
unsigned int V_188 = V_186 - V_187 ;
F_116 ( V_181 , L_17 , V_186 ,
V_188 , V_187 , V_185 -> V_189 ,
V_185 -> V_190 , V_185 -> V_191 ) ;
}
return 0 ;
}
static void F_117 ( struct V_180 * V_181 , void * V_184 )
{ }
static int F_118 ( struct V_39 * V_39 , struct V_14 * V_14 )
{
return F_119 ( V_14 , & V_192 ) ;
}
static int F_120 ( struct V_148 * V_155 )
{
int V_130 ;
static struct V_193 V_194 [] = {
{ L_18 ,
& V_195 , V_164 | V_165 } ,
{ L_19 , & V_196 , V_164 } ,
#ifdef F_121
{ L_20 , & V_197 , V_164 } ,
#endif
} ;
for ( V_130 = 0 ; V_130 < F_75 ( V_194 ) ; V_130 ++ ) {
struct V_39 * V_39 ;
struct V_148 * V_148 ;
V_148 = F_102 ( V_155 , V_194 [ V_130 ] . V_146 ) ;
if ( ! V_148 )
return - V_26 ;
V_39 = F_89 ( V_155 -> V_162 , V_163 | V_194 [ V_130 ] . V_136 ) ;
if ( ! V_39 )
return - V_26 ;
V_39 -> V_171 = V_194 [ V_130 ] . V_198 ;
V_39 -> V_36 = ++ V_199 ;
F_104 ( V_148 , V_39 ) ;
}
return 0 ;
}
static T_3 F_122 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_126 ;
T_2 V_9 , V_65 ;
T_3 V_66 ;
V_9 = F_24 ( V_14 ) -> V_36 & V_145 ;
V_66 = F_67 ( V_9 , & V_126 , & V_65 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_10 ( V_16 , V_17 , V_18 , V_126 , V_65 ) ;
F_22 ( V_126 ) ;
return V_66 ;
}
static int F_123 ( struct V_148 * V_155 )
{
int V_130 ;
for ( V_130 = 1 ; V_130 <= V_200 ; V_130 ++ ) {
struct V_39 * V_39 ;
struct V_148 * V_148 ;
V_148 = F_102 ( V_155 , F_124 ( V_130 ) ) ;
if ( ! V_148 )
return - V_26 ;
V_39 = F_89 ( V_155 -> V_162 , V_163 | V_164 ) ;
if ( ! V_39 )
return - V_26 ;
V_39 -> V_171 = & V_201 ;
V_39 -> V_36 = V_130 | V_202 ;
F_104 ( V_148 , V_39 ) ;
}
return 0 ;
}
static inline unsigned long F_125 ( T_8 V_203 )
{
return ( V_203 * ( V_204 + 1 ) ) | V_205 ;
}
static inline T_8 F_126 ( unsigned long V_35 )
{
return ( V_35 & V_145 ) / ( V_204 + 1 ) ;
}
static inline unsigned long F_127 ( T_8 V_203 , T_2 V_206 )
{
return ( V_203 * ( V_204 + 1 ) + V_206 ) | V_205 ;
}
static inline T_2 F_128 ( unsigned long V_35 )
{
return ( V_35 & V_145 ) % ( V_204 + 1 ) ;
}
static T_3 F_129 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
unsigned long V_35 = F_24 ( V_14 ) -> V_36 ;
char V_207 [ V_20 ] ;
T_3 V_65 = snprintf ( V_207 , sizeof( V_207 ) , L_1 , F_126 ( V_35 ) ) ;
return F_10 ( V_16 , V_17 , V_18 , V_207 , V_65 ) ;
}
static T_3 F_130 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
unsigned long V_35 = F_24 ( V_14 ) -> V_36 ;
char V_207 [ V_20 ] ;
T_3 V_65 = snprintf ( V_207 , sizeof( V_207 ) , L_1 , F_128 ( V_35 ) ) ;
return F_10 ( V_16 , V_17 , V_18 , V_207 , V_65 ) ;
}
static T_3 F_131 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
int V_208 ;
char V_19 [ V_20 ] ;
T_3 V_21 ;
unsigned long V_36 = F_24 ( V_14 ) -> V_36 ;
V_208 = F_132 ( V_36 & V_145 ) ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_208 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_133 ( char * V_209 , int V_210 ,
struct V_148 * V_155 )
{
int V_130 , V_58 , V_211 ;
char * * V_6 ;
V_58 = F_134 ( V_209 , & V_6 , & V_211 ) ;
if ( V_58 )
return V_58 ;
for ( V_130 = 0 ; V_130 < V_211 ; V_130 ++ ) {
struct V_39 * V_39 ;
struct V_148 * V_148 ;
V_58 = - V_26 ;
V_148 = F_102 ( V_155 , V_6 [ V_130 ] ) ;
if ( ! V_148 )
goto V_28;
V_58 = - V_26 ;
V_39 = F_89 ( V_155 -> V_162 , V_163 | V_164 ) ;
if ( ! V_39 )
goto V_28;
V_39 -> V_171 = & V_212 ;
V_39 -> V_36 = F_127 ( V_210 , V_130 + 1 ) ;
F_104 ( V_148 , V_39 ) ;
}
V_58 = 0 ;
V_28:
for ( V_130 = 0 ; V_130 < V_211 ; V_130 ++ )
F_22 ( V_6 [ V_130 ] ) ;
F_22 ( V_6 ) ;
return V_58 ;
}
static int F_135 ( char * V_213 , int V_144 ,
struct V_148 * V_155 )
{
struct V_148 * V_148 = NULL ;
struct V_39 * V_39 = NULL ;
int V_58 ;
V_148 = F_102 ( V_155 , L_21 ) ;
if ( ! V_148 )
return - V_26 ;
V_39 = F_89 ( V_155 -> V_162 , V_163 | V_164 ) ;
if ( ! V_39 )
return - V_26 ;
V_39 -> V_171 = & V_214 ;
V_39 -> V_36 = F_125 ( V_144 ) ;
F_104 ( V_148 , V_39 ) ;
V_148 = F_136 ( V_155 , L_22 , & V_215 ) ;
if ( F_13 ( V_148 ) )
return F_14 ( V_148 ) ;
V_58 = F_133 ( V_213 , V_144 , V_148 ) ;
return V_58 ;
}
static int F_63 ( void )
{
int V_58 , V_216 , V_130 ;
char * * V_217 ;
F_98 ( V_218 ) ;
V_58 = F_137 ( & V_217 , & V_216 ) ;
if ( V_58 )
return V_58 ;
V_215 = F_125 ( V_216 + 2 ) ;
for ( V_130 = 0 ; V_130 < V_216 ; V_130 ++ ) {
struct V_148 * V_219 ;
V_219 = F_136 ( V_218 , V_217 [ V_130 ] ,
& V_215 ) ;
if ( F_13 ( V_219 ) ) {
V_58 = F_14 ( V_219 ) ;
goto V_28;
}
V_58 = F_135 ( V_217 [ V_130 ] , V_130 + 1 ,
V_219 ) ;
if ( V_58 )
goto V_28;
}
V_58 = 0 ;
V_28:
for ( V_130 = 0 ; V_130 < V_216 ; V_130 ++ )
F_22 ( V_217 [ V_130 ] ) ;
F_22 ( V_217 ) ;
return V_58 ;
}
static int F_64 ( void )
{
unsigned int V_220 ;
struct V_148 * V_148 = NULL ;
struct V_39 * V_39 = NULL ;
F_98 ( V_221 ) ;
for ( V_220 = 0 ; V_220 <= V_222 ; V_220 ++ ) {
if ( V_220 < F_75 ( V_223 ) )
V_148 = F_102 ( V_221 ,
V_223 [ V_220 ] ) ;
else
V_148 = F_102 ( V_221 , L_23 ) ;
if ( V_148 == NULL )
return - V_26 ;
V_39 = F_89 ( V_221 -> V_162 , V_163 | V_164 ) ;
if ( V_39 == NULL )
return - V_26 ;
V_39 -> V_171 = & V_224 ;
V_39 -> V_36 = V_220 | V_225 ;
F_104 ( V_148 , V_39 ) ;
}
return 0 ;
}
static struct V_148 * F_136 ( struct V_148 * V_155 , const char * V_146 ,
unsigned long * V_35 )
{
struct V_148 * V_148 = F_102 ( V_155 , V_146 ) ;
struct V_39 * V_39 ;
if ( ! V_148 )
return F_138 ( - V_26 ) ;
V_39 = F_89 ( V_155 -> V_162 , V_226 | V_164 | V_227 ) ;
if ( ! V_39 ) {
F_139 ( V_148 ) ;
return F_138 ( - V_26 ) ;
}
V_39 -> V_228 = & V_229 ;
V_39 -> V_171 = & V_230 ;
V_39 -> V_36 = ++ ( * V_35 ) ;
F_140 ( V_39 ) ;
F_104 ( V_148 , V_39 ) ;
F_140 ( F_141 ( V_155 ) ) ;
return V_148 ;
}
static int F_142 ( struct V_134 * V_135 , void * V_64 , int V_231 )
{
int V_66 ;
struct V_148 * V_148 ;
struct V_39 * V_39 ;
struct V_157 * V_158 ;
static struct V_193 V_232 [] = {
[ V_233 ] = { L_24 , & V_234 , V_235 | V_165 } ,
[ V_236 ] = { L_25 , & V_237 , V_164 | V_165 } ,
[ V_238 ] = { L_26 , & V_239 , V_164 | V_240 } ,
[ V_241 ] = { L_27 , & V_239 , V_164 | V_240 } ,
[ V_242 ] = { L_28 , & V_239 , V_164 | V_240 } ,
[ V_243 ] = { L_29 , & V_239 , V_164 | V_240 } ,
[ V_244 ] = { L_30 , & V_239 , V_164 | V_240 } ,
[ V_245 ] = { L_31 , & V_246 , V_164 } ,
[ V_247 ] = { L_32 , & V_248 , V_165 } ,
[ V_249 ] = { L_33 , & V_250 , V_164 } ,
[ V_251 ] = { L_34 , & V_252 , V_165 } ,
[ V_253 ] = { L_35 , & V_239 , V_164 | V_240 } ,
[ V_254 ] = { L_36 , & V_255 , V_164 | V_165 } ,
[ V_38 ] = { L_37 , & V_256 , V_164 } ,
[ V_257 ] = { L_38 , & V_256 , V_164 } ,
[ V_258 ] = { L_39 , & V_259 , V_164 } ,
[ V_260 ] = { L_40 , & V_261 , V_164 } ,
[ V_262 ] = { L_41 , & V_263 ,
V_240 } ,
{ L_42 }
} ;
V_66 = F_143 ( V_135 , V_264 , V_232 ) ;
if ( V_66 )
goto V_61;
V_156 = F_136 ( V_135 -> V_265 , V_167 , & V_199 ) ;
if ( F_13 ( V_156 ) ) {
V_66 = F_14 ( V_156 ) ;
V_156 = NULL ;
goto V_61;
}
V_66 = - V_26 ;
V_148 = F_102 ( V_135 -> V_265 , V_266 ) ;
if ( ! V_148 )
goto V_61;
V_66 = - V_26 ;
V_39 = F_89 ( V_135 , V_267 | V_164 | V_240 ) ;
if ( ! V_39 )
goto V_61;
V_39 -> V_36 = ++ V_199 ;
V_158 = (struct V_157 * ) V_39 -> V_168 ;
V_158 -> V_9 = V_268 ;
V_158 -> V_269 = V_270 ;
V_158 -> V_170 = 1 ;
F_144 ( V_39 , V_267 | V_164 | V_240 , F_145 ( V_271 , 3 ) ) ;
F_104 ( V_148 , V_39 ) ;
V_272 . V_148 = V_148 ;
V_148 = F_136 ( V_135 -> V_265 , L_43 , & V_199 ) ;
if ( F_13 ( V_148 ) ) {
V_66 = F_14 ( V_148 ) ;
goto V_61;
}
V_66 = F_120 ( V_148 ) ;
if ( V_66 )
goto V_61;
V_148 = F_136 ( V_135 -> V_265 , L_44 , & V_199 ) ;
if ( F_13 ( V_148 ) ) {
V_66 = F_14 ( V_148 ) ;
goto V_61;
}
V_66 = F_123 ( V_148 ) ;
if ( V_66 )
goto V_61;
V_218 = F_136 ( V_135 -> V_265 , L_45 , & V_199 ) ;
if ( F_13 ( V_218 ) ) {
V_66 = F_14 ( V_218 ) ;
V_218 = NULL ;
goto V_61;
}
V_221 = F_136 ( V_135 -> V_265 , L_46 , & V_199 ) ;
if ( F_13 ( V_221 ) ) {
V_66 = F_14 ( V_221 ) ;
V_221 = NULL ;
goto V_61;
}
return 0 ;
V_61:
F_68 ( V_91 L_47 ,
V_92 ) ;
return V_66 ;
}
static struct V_148 * F_146 ( struct V_273 * V_274 ,
int V_71 , const char * V_275 , void * V_64 )
{
return F_147 ( V_274 , V_71 , V_64 , F_142 ) ;
}
static int T_1 F_148 ( void )
{
int V_61 ;
if ( ! V_276 )
return 0 ;
V_61 = F_149 ( V_277 , L_48 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_150 ( & V_278 ) ;
if ( V_61 ) {
F_151 ( V_277 , L_48 ) ;
return V_61 ;
}
V_272 . V_279 = V_280 = F_152 ( & V_278 ) ;
if ( F_13 ( V_280 ) ) {
F_68 ( V_91 L_49 ) ;
V_61 = F_14 ( V_280 ) ;
V_280 = NULL ;
}
return V_61 ;
}
void F_153 ( void )
{
F_151 ( V_277 , L_48 ) ;
F_154 ( V_280 ) ;
F_155 ( & V_278 ) ;
}
