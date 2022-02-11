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
V_66 -> V_138 = V_66 -> V_139 = V_66 -> V_140 = F_91 ( V_66 ) ;
}
return V_66 ;
}
static T_3 F_92 ( struct V_14 * V_141 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
T_3 V_66 ;
int V_142 ;
unsigned V_143 = F_24 ( V_141 ) -> V_36 & V_144 ;
const char * V_145 = V_141 -> V_146 . V_147 -> V_148 . V_145 ;
F_41 ( & V_59 ) ;
V_66 = - V_27 ;
if ( V_143 >= V_149 || strcmp ( V_145 , V_150 [ V_143 ] ) )
goto V_28;
V_66 = - V_26 ;
V_23 = ( char * ) F_93 ( V_32 ) ;
if ( ! V_23 )
goto V_28;
V_142 = F_94 ( V_143 ) ;
if ( V_142 < 0 ) {
V_66 = V_142 ;
goto V_28;
}
V_21 = F_9 ( V_23 , V_25 , L_12 , V_142 ,
V_151 [ V_143 ] ) ;
V_66 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
V_28:
F_49 ( & V_59 ) ;
F_95 ( ( unsigned long ) V_23 ) ;
return V_66 ;
}
static T_3 F_96 ( struct V_14 * V_141 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
unsigned V_143 = F_24 ( V_141 ) -> V_36 & V_144 ;
const char * V_145 = V_141 -> V_146 . V_147 -> V_148 . V_145 ;
F_41 ( & V_59 ) ;
V_21 = F_3 ( V_29 , V_152 ) ;
if ( V_21 )
goto V_28;
V_21 = - V_27 ;
if ( V_143 >= V_149 || strcmp ( V_145 , V_150 [ V_143 ] ) )
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
V_151 [ V_143 ] = V_24 ;
V_21 = V_17 ;
V_28:
F_49 ( & V_59 ) ;
F_22 ( V_23 ) ;
return V_21 ;
}
static T_3 F_97 ( struct V_14 * V_141 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
F_41 ( & V_59 ) ;
V_21 = F_3 ( V_29 , V_152 ) ;
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
if ( V_24 && V_151 )
V_21 = F_98 ( V_149 , V_151 ) ;
if ( ! V_21 )
V_21 = V_17 ;
V_28:
F_49 ( & V_59 ) ;
F_22 ( V_23 ) ;
return V_21 ;
}
static void F_99 ( struct V_147 * V_153 )
{
F_100 ( V_153 ) ;
F_101 ( V_153 ) ;
}
static int F_62 ( void )
{
int V_130 , V_66 ;
T_3 V_65 ;
struct V_147 * V_147 = NULL ;
struct V_147 * V_154 = V_155 ;
struct V_39 * V_39 = NULL ;
struct V_156 * V_157 ;
char * * V_158 = NULL , * V_23 ;
int V_159 ;
int * V_160 = NULL ;
T_2 V_9 ;
for ( V_130 = 0 ; V_130 < V_149 ; V_130 ++ )
F_22 ( V_150 [ V_130 ] ) ;
F_22 ( V_150 ) ;
F_22 ( V_151 ) ;
V_149 = 0 ;
V_150 = NULL ;
V_151 = NULL ;
F_99 ( V_154 ) ;
V_66 = - V_26 ;
V_23 = ( char * ) F_93 ( V_32 ) ;
if ( ! V_23 )
goto V_28;
V_66 = F_102 ( & V_159 , & V_158 , & V_160 ) ;
if ( V_66 )
goto V_28;
for ( V_130 = 0 ; V_130 < V_159 ; V_130 ++ ) {
V_66 = - V_26 ;
V_147 = F_103 ( V_154 , V_158 [ V_130 ] ) ;
if ( ! V_147 )
goto V_28;
V_66 = - V_26 ;
V_39 = F_89 ( V_154 -> V_161 , V_162 | V_163 | V_164 ) ;
if ( ! V_39 )
goto V_28;
V_66 = - V_165 ;
V_65 = snprintf ( V_23 , V_25 , L_13 , V_166 , V_158 [ V_130 ] ) ;
if ( V_65 >= V_25 )
goto V_28;
V_157 = (struct V_156 * ) V_39 -> V_167 ;
V_66 = F_104 ( L_14 , V_23 , V_168 , & V_9 ) ;
if ( V_66 )
goto V_28;
V_157 -> V_9 = V_9 ;
V_157 -> V_169 = 1 ;
V_39 -> V_170 = & V_171 ;
V_39 -> V_36 = V_130 | V_172 ;
F_105 ( V_147 , V_39 ) ;
}
V_149 = V_159 ;
V_150 = V_158 ;
V_151 = V_160 ;
F_95 ( ( unsigned long ) V_23 ) ;
return 0 ;
V_28:
F_95 ( ( unsigned long ) V_23 ) ;
if ( V_158 ) {
for ( V_130 = 0 ; V_130 < V_159 ; V_130 ++ )
F_22 ( V_158 [ V_130 ] ) ;
F_22 ( V_158 ) ;
}
F_22 ( V_160 ) ;
F_99 ( V_154 ) ;
return V_66 ;
}
static T_3 F_106 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_173 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_107 ( struct V_14 * V_14 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_66 ;
unsigned int V_24 ;
V_66 = F_3 ( V_29 , V_174 ) ;
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
V_173 = V_24 ;
V_66 = V_17 ;
V_28:
F_22 ( V_23 ) ;
return V_66 ;
}
static T_3 F_108 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_21 ;
V_23 = ( char * ) F_109 ( V_32 ) ;
if ( ! V_23 )
return - V_26 ;
V_21 = F_110 ( V_23 ) ;
if ( V_21 >= 0 )
V_21 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
F_95 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static struct V_175 * F_111 ( T_6 * V_176 )
{
int V_177 ;
for ( V_177 = * V_176 ; V_177 < V_178 ; ++ V_177 ) {
if ( ! F_112 ( V_177 ) )
continue;
* V_176 = V_177 + 1 ;
return & F_113 ( V_175 , V_177 ) ;
}
return NULL ;
}
static void * F_114 ( struct V_179 * V_180 , T_6 * V_103 )
{
T_6 V_181 = * V_103 - 1 ;
if ( * V_103 == 0 )
return V_182 ;
return F_111 ( & V_181 ) ;
}
static void * F_115 ( struct V_179 * V_180 , void * V_183 , T_6 * V_103 )
{
return F_111 ( V_103 ) ;
}
static int F_116 ( struct V_179 * V_180 , void * V_183 )
{
struct V_175 * V_184 = V_183 ;
if ( V_183 == V_182 )
F_117 ( V_180 , L_15
L_16 ) ;
else {
unsigned int V_185 = V_184 -> V_185 ;
unsigned int V_186 = V_184 -> V_186 ;
unsigned int V_187 = V_185 - V_186 ;
F_117 ( V_180 , L_17 , V_185 ,
V_187 , V_186 , V_184 -> V_188 ,
V_184 -> V_189 , V_184 -> V_190 ) ;
}
return 0 ;
}
static void F_118 ( struct V_179 * V_180 , void * V_183 )
{ }
static int F_119 ( struct V_39 * V_39 , struct V_14 * V_14 )
{
return F_120 ( V_14 , & V_191 ) ;
}
static int F_121 ( struct V_147 * V_154 )
{
int V_130 ;
static struct V_192 V_193 [] = {
{ L_18 ,
& V_194 , V_163 | V_164 } ,
{ L_19 , & V_195 , V_163 } ,
#ifdef F_122
{ L_20 , & V_196 , V_163 } ,
#endif
} ;
for ( V_130 = 0 ; V_130 < F_75 ( V_193 ) ; V_130 ++ ) {
struct V_39 * V_39 ;
struct V_147 * V_147 ;
V_147 = F_103 ( V_154 , V_193 [ V_130 ] . V_145 ) ;
if ( ! V_147 )
return - V_26 ;
V_39 = F_89 ( V_154 -> V_161 , V_162 | V_193 [ V_130 ] . V_136 ) ;
if ( ! V_39 )
return - V_26 ;
V_39 -> V_170 = V_193 [ V_130 ] . V_197 ;
V_39 -> V_36 = ++ V_198 ;
F_105 ( V_147 , V_39 ) ;
}
return 0 ;
}
static T_3 F_123 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_126 ;
T_2 V_9 , V_65 ;
T_3 V_66 ;
V_9 = F_24 ( V_14 ) -> V_36 & V_144 ;
V_66 = F_67 ( V_9 , & V_126 , & V_65 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_10 ( V_16 , V_17 , V_18 , V_126 , V_65 ) ;
F_22 ( V_126 ) ;
return V_66 ;
}
static int F_124 ( struct V_147 * V_154 )
{
int V_130 ;
for ( V_130 = 1 ; V_130 <= V_199 ; V_130 ++ ) {
struct V_39 * V_39 ;
struct V_147 * V_147 ;
V_147 = F_103 ( V_154 , F_125 ( V_130 ) ) ;
if ( ! V_147 )
return - V_26 ;
V_39 = F_89 ( V_154 -> V_161 , V_162 | V_163 ) ;
if ( ! V_39 )
return - V_26 ;
V_39 -> V_170 = & V_200 ;
V_39 -> V_36 = V_130 | V_201 ;
F_105 ( V_147 , V_39 ) ;
}
return 0 ;
}
static inline unsigned long F_126 ( T_8 V_202 )
{
return ( V_202 * ( V_203 + 1 ) ) | V_204 ;
}
static inline T_8 F_127 ( unsigned long V_35 )
{
return ( V_35 & V_144 ) / ( V_203 + 1 ) ;
}
static inline unsigned long F_128 ( T_8 V_202 , T_2 V_205 )
{
return ( V_202 * ( V_203 + 1 ) + V_205 ) | V_204 ;
}
static inline T_2 F_129 ( unsigned long V_35 )
{
return ( V_35 & V_144 ) % ( V_203 + 1 ) ;
}
static T_3 F_130 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
unsigned long V_35 = F_24 ( V_14 ) -> V_36 ;
char V_206 [ V_20 ] ;
T_3 V_65 = snprintf ( V_206 , sizeof( V_206 ) , L_1 , F_127 ( V_35 ) ) ;
return F_10 ( V_16 , V_17 , V_18 , V_206 , V_65 ) ;
}
static T_3 F_131 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
unsigned long V_35 = F_24 ( V_14 ) -> V_36 ;
char V_206 [ V_20 ] ;
T_3 V_65 = snprintf ( V_206 , sizeof( V_206 ) , L_1 , F_129 ( V_35 ) ) ;
return F_10 ( V_16 , V_17 , V_18 , V_206 , V_65 ) ;
}
static T_3 F_132 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
int V_207 ;
char V_19 [ V_20 ] ;
T_3 V_21 ;
unsigned long V_36 = F_24 ( V_14 ) -> V_36 ;
V_207 = F_133 ( V_36 & V_144 ) ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_207 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_134 ( char * V_208 , int V_209 ,
struct V_147 * V_154 )
{
int V_130 , V_58 , V_210 ;
char * * V_6 ;
V_58 = F_135 ( V_208 , & V_6 , & V_210 ) ;
if ( V_58 )
return V_58 ;
for ( V_130 = 0 ; V_130 < V_210 ; V_130 ++ ) {
struct V_39 * V_39 ;
struct V_147 * V_147 ;
V_58 = - V_26 ;
V_147 = F_103 ( V_154 , V_6 [ V_130 ] ) ;
if ( ! V_147 )
goto V_28;
V_58 = - V_26 ;
V_39 = F_89 ( V_154 -> V_161 , V_162 | V_163 ) ;
if ( ! V_39 )
goto V_28;
V_39 -> V_170 = & V_211 ;
V_39 -> V_36 = F_128 ( V_209 , V_130 + 1 ) ;
F_105 ( V_147 , V_39 ) ;
}
V_58 = 0 ;
V_28:
for ( V_130 = 0 ; V_130 < V_210 ; V_130 ++ )
F_22 ( V_6 [ V_130 ] ) ;
F_22 ( V_6 ) ;
return V_58 ;
}
static int F_136 ( char * V_212 , int V_143 ,
struct V_147 * V_154 )
{
struct V_147 * V_147 = NULL ;
struct V_39 * V_39 = NULL ;
int V_58 ;
V_147 = F_103 ( V_154 , L_21 ) ;
if ( ! V_147 )
return - V_26 ;
V_39 = F_89 ( V_154 -> V_161 , V_162 | V_163 ) ;
if ( ! V_39 )
return - V_26 ;
V_39 -> V_170 = & V_213 ;
V_39 -> V_36 = F_126 ( V_143 ) ;
F_105 ( V_147 , V_39 ) ;
V_147 = F_137 ( V_154 , L_22 , & V_214 ) ;
if ( F_13 ( V_147 ) )
return F_14 ( V_147 ) ;
V_58 = F_134 ( V_212 , V_143 , V_147 ) ;
return V_58 ;
}
static int F_63 ( void )
{
int V_58 , V_215 , V_130 ;
char * * V_216 ;
F_99 ( V_217 ) ;
V_58 = F_138 ( & V_216 , & V_215 ) ;
if ( V_58 )
return V_58 ;
V_214 = F_126 ( V_215 + 2 ) ;
for ( V_130 = 0 ; V_130 < V_215 ; V_130 ++ ) {
struct V_147 * V_218 ;
V_218 = F_137 ( V_217 , V_216 [ V_130 ] ,
& V_214 ) ;
if ( F_13 ( V_218 ) ) {
V_58 = F_14 ( V_218 ) ;
goto V_28;
}
V_58 = F_136 ( V_216 [ V_130 ] , V_130 + 1 ,
V_218 ) ;
if ( V_58 )
goto V_28;
}
V_58 = 0 ;
V_28:
for ( V_130 = 0 ; V_130 < V_215 ; V_130 ++ )
F_22 ( V_216 [ V_130 ] ) ;
F_22 ( V_216 ) ;
return V_58 ;
}
static int F_64 ( void )
{
unsigned int V_219 ;
struct V_147 * V_147 = NULL ;
struct V_39 * V_39 = NULL ;
F_99 ( V_220 ) ;
for ( V_219 = 0 ; V_219 <= V_221 ; V_219 ++ ) {
if ( V_219 < F_75 ( V_222 ) )
V_147 = F_103 ( V_220 ,
V_222 [ V_219 ] ) ;
else
V_147 = F_103 ( V_220 , L_23 ) ;
if ( V_147 == NULL )
return - V_26 ;
V_39 = F_89 ( V_220 -> V_161 , V_162 | V_163 ) ;
if ( V_39 == NULL )
return - V_26 ;
V_39 -> V_170 = & V_223 ;
V_39 -> V_36 = V_219 | V_224 ;
F_105 ( V_147 , V_39 ) ;
}
return 0 ;
}
static struct V_147 * F_137 ( struct V_147 * V_154 , const char * V_145 ,
unsigned long * V_35 )
{
struct V_147 * V_147 = F_103 ( V_154 , V_145 ) ;
struct V_39 * V_39 ;
if ( ! V_147 )
return F_139 ( - V_26 ) ;
V_39 = F_89 ( V_154 -> V_161 , V_225 | V_163 | V_226 ) ;
if ( ! V_39 ) {
F_140 ( V_147 ) ;
return F_139 ( - V_26 ) ;
}
V_39 -> V_227 = & V_228 ;
V_39 -> V_170 = & V_229 ;
V_39 -> V_36 = ++ ( * V_35 ) ;
F_141 ( V_39 ) ;
F_105 ( V_147 , V_39 ) ;
F_141 ( F_142 ( V_154 ) ) ;
return V_147 ;
}
static int F_143 ( struct V_134 * V_135 , void * V_64 , int V_230 )
{
int V_66 ;
struct V_147 * V_147 ;
struct V_39 * V_39 ;
struct V_156 * V_157 ;
static struct V_192 V_231 [] = {
[ V_232 ] = { L_24 , & V_233 , V_234 | V_164 } ,
[ V_235 ] = { L_25 , & V_236 , V_163 | V_164 } ,
[ V_237 ] = { L_26 , & V_238 , V_163 | V_239 } ,
[ V_240 ] = { L_27 , & V_238 , V_163 | V_239 } ,
[ V_241 ] = { L_28 , & V_238 , V_163 | V_239 } ,
[ V_242 ] = { L_29 , & V_238 , V_163 | V_239 } ,
[ V_243 ] = { L_30 , & V_238 , V_163 | V_239 } ,
[ V_244 ] = { L_31 , & V_245 , V_163 } ,
[ V_246 ] = { L_32 , & V_247 , V_164 } ,
[ V_248 ] = { L_33 , & V_249 , V_163 } ,
[ V_250 ] = { L_34 , & V_251 , V_164 } ,
[ V_252 ] = { L_35 , & V_238 , V_163 | V_239 } ,
[ V_253 ] = { L_36 , & V_254 , V_163 | V_164 } ,
[ V_38 ] = { L_37 , & V_255 , V_163 } ,
[ V_256 ] = { L_38 , & V_255 , V_163 } ,
[ V_257 ] = { L_39 , & V_258 , V_163 } ,
[ V_259 ] = { L_40 , & V_260 , V_163 } ,
[ V_261 ] = { L_41 , & V_262 ,
V_239 } ,
{ L_42 }
} ;
V_66 = F_144 ( V_135 , V_263 , V_231 ) ;
if ( V_66 )
goto V_61;
V_155 = F_137 ( V_135 -> V_264 , V_166 , & V_198 ) ;
if ( F_13 ( V_155 ) ) {
V_66 = F_14 ( V_155 ) ;
V_155 = NULL ;
goto V_61;
}
V_66 = - V_26 ;
V_147 = F_103 ( V_135 -> V_264 , V_265 ) ;
if ( ! V_147 )
goto V_61;
V_66 = - V_26 ;
V_39 = F_89 ( V_135 , V_266 | V_163 | V_239 ) ;
if ( ! V_39 )
goto V_61;
V_39 -> V_36 = ++ V_198 ;
V_157 = (struct V_156 * ) V_39 -> V_167 ;
V_157 -> V_9 = V_267 ;
V_157 -> V_268 = V_269 ;
V_157 -> V_169 = 1 ;
F_145 ( V_39 , V_266 | V_163 | V_239 , F_146 ( V_270 , 3 ) ) ;
F_105 ( V_147 , V_39 ) ;
V_271 . V_147 = V_147 ;
V_147 = F_137 ( V_135 -> V_264 , L_43 , & V_198 ) ;
if ( F_13 ( V_147 ) ) {
V_66 = F_14 ( V_147 ) ;
goto V_61;
}
V_66 = F_121 ( V_147 ) ;
if ( V_66 )
goto V_61;
V_147 = F_137 ( V_135 -> V_264 , L_44 , & V_198 ) ;
if ( F_13 ( V_147 ) ) {
V_66 = F_14 ( V_147 ) ;
goto V_61;
}
V_66 = F_124 ( V_147 ) ;
if ( V_66 )
goto V_61;
V_217 = F_137 ( V_135 -> V_264 , L_45 , & V_198 ) ;
if ( F_13 ( V_217 ) ) {
V_66 = F_14 ( V_217 ) ;
V_217 = NULL ;
goto V_61;
}
V_220 = F_137 ( V_135 -> V_264 , L_46 , & V_198 ) ;
if ( F_13 ( V_220 ) ) {
V_66 = F_14 ( V_220 ) ;
V_220 = NULL ;
goto V_61;
}
return 0 ;
V_61:
F_68 ( V_91 L_47 ,
V_92 ) ;
return V_66 ;
}
static struct V_147 * F_147 ( struct V_272 * V_273 ,
int V_71 , const char * V_274 , void * V_64 )
{
return F_148 ( V_273 , V_71 , V_64 , F_143 ) ;
}
static int T_1 F_149 ( void )
{
int V_61 ;
if ( ! V_275 )
return 0 ;
V_61 = F_150 ( V_276 , L_48 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_151 ( & V_277 ) ;
if ( V_61 ) {
F_152 ( V_276 , L_48 ) ;
return V_61 ;
}
V_271 . V_278 = V_279 = F_153 ( & V_277 ) ;
if ( F_13 ( V_279 ) ) {
F_68 ( V_91 L_49 ) ;
V_61 = F_14 ( V_279 ) ;
V_279 = NULL ;
}
return V_61 ;
}
void F_154 ( void )
{
F_152 ( V_276 , L_48 ) ;
F_155 ( V_279 ) ;
F_156 ( & V_277 ) ;
}
