static int T_1 F_1 ( char * V_1 )
{
unsigned long V_2 ;
if ( ! F_2 ( V_1 , 0 , & V_2 ) )
V_3 = V_2 ? 1 : 0 ;
return 1 ;
}
static T_2 F_3 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_1 , V_12 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static T_2 F_6 ( struct V_4 * V_4 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 = NULL ;
T_2 V_11 ;
int V_14 ;
if ( V_7 >= V_15 )
return - V_16 ;
if ( * V_8 != 0 )
return - V_17 ;
V_13 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_13 ) )
return F_9 ( V_13 ) ;
V_11 = - V_17 ;
if ( sscanf ( V_13 , L_1 , & V_14 ) != 1 )
goto V_18;
V_14 = ! ! V_14 ;
if ( V_14 != V_12 ) {
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_21 ,
NULL ) ;
if ( V_11 )
goto V_18;
F_12 ( V_22 -> V_23 , V_24 , V_25 ,
L_2 ,
V_14 , V_12 ,
F_13 ( & V_26 , F_14 ( V_22 ) ) ,
F_15 ( V_22 ) ) ;
V_12 = V_14 ;
if ( V_12 )
F_16 ( 0 ) ;
F_17 ( V_12 ) ;
F_18 ( V_12 ) ;
if ( ! V_12 )
F_19 ( V_27 , NULL ) ;
}
V_11 = V_7 ;
V_18:
F_20 ( V_13 ) ;
return V_11 ;
}
static T_2 F_21 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
T_6 V_28 = F_22 ( V_5 ) -> V_29 ;
int V_30 = ( V_28 == V_31 ) ?
F_23 () : ! F_24 () ;
V_11 = F_4 ( V_9 , V_10 , L_1 , V_30 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static int F_25 ( struct V_32 * V_32 , struct V_4 * V_5 )
{
struct V_13 * V_33 = F_26 () ;
if ( ! V_33 )
return - V_16 ;
V_5 -> V_34 = V_33 ;
return 0 ;
}
static T_2 F_27 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
struct V_13 * V_33 = V_5 -> V_34 ;
F_28 ( ! V_33 ) ;
return F_5 ( V_6 , V_7 , V_8 ,
F_29 ( V_33 ) ,
sizeof( struct V_35 ) ) ;
}
static int F_30 ( struct V_4 * V_5 ,
struct V_36 * V_37 )
{
struct V_13 * V_33 = V_5 -> V_34 ;
unsigned long V_38 = V_37 -> V_39 - V_37 -> V_40 ;
F_28 ( ! V_33 ) ;
if ( V_37 -> V_41 > 0 || V_38 != V_15 )
return - V_42 ;
if ( V_37 -> V_43 & V_44 )
return - V_45 ;
V_37 -> V_43 &= ~ V_46 ;
return F_31 ( V_37 , V_37 -> V_40 ,
F_32 ( V_33 ) ,
V_38 , V_37 -> V_47 ) ;
}
static T_2 F_33 ( struct V_4 * V_4 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 ;
T_2 V_11 ;
int V_14 ;
if ( V_7 >= V_15 )
return - V_16 ;
if ( * V_8 != 0 )
return - V_17 ;
V_13 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_13 ) )
return F_9 ( V_13 ) ;
V_11 = - V_17 ;
if ( sscanf ( V_13 , L_1 , & V_14 ) != 1 )
goto V_18;
if ( V_14 ) {
V_11 = F_34 () ;
if ( V_11 )
goto V_18;
F_12 ( V_22 -> V_23 , V_24 , V_25 ,
L_3 ,
F_13 ( & V_26 , F_14 ( V_22 ) ) ,
F_15 ( V_22 ) ) ;
}
V_11 = V_7 ;
V_18:
F_20 ( V_13 ) ;
return V_11 ;
}
static T_2 F_35 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_4 , V_48 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static T_2 F_36 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_1 ,
F_37 () ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static int F_38 ( struct V_32 * V_32 , struct V_4 * V_5 )
{
struct V_49 * V_50 = NULL ;
int V_51 ;
F_28 ( V_5 -> V_34 ) ;
F_39 ( & V_52 ) ;
V_51 = F_10 ( F_11 () , V_19 ,
V_20 , V_53 , NULL ) ;
if ( V_51 )
goto V_54;
V_51 = - V_55 ;
if ( V_56 )
goto V_54;
V_51 = - V_16 ;
V_50 = F_40 ( sizeof( * V_50 ) , V_24 ) ;
if ( ! V_50 )
goto V_54;
if ( F_41 ( V_32 ) != F_42 () ) {
F_43 ( V_32 ) ;
F_44 ( V_32 , F_42 () ) ;
F_45 ( V_32 ) ;
}
V_51 = F_46 ( & V_50 -> V_57 , & V_50 -> V_58 ) ;
if ( V_51 )
goto V_54;
V_56 = 1 ;
V_5 -> V_34 = V_50 ;
F_47 ( & V_52 ) ;
return 0 ;
V_54:
F_47 ( & V_52 ) ;
if ( V_50 )
F_48 ( V_50 -> V_57 ) ;
F_20 ( V_50 ) ;
return V_51 ;
}
static int F_49 ( struct V_32 * V_32 , struct V_4 * V_5 )
{
struct V_49 * V_50 = V_5 -> V_34 ;
F_28 ( ! V_50 ) ;
V_56 = 0 ;
F_48 ( V_50 -> V_57 ) ;
F_20 ( V_50 ) ;
return 0 ;
}
static T_2 F_50 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
struct V_49 * V_50 = V_5 -> V_34 ;
int V_59 ;
F_39 ( & V_52 ) ;
V_59 = F_10 ( F_11 () , V_19 ,
V_20 , V_53 , NULL ) ;
if ( V_59 )
goto V_18;
V_59 = F_5 ( V_6 , V_7 , V_8 , V_50 -> V_57 , V_50 -> V_58 ) ;
V_18:
F_47 ( & V_52 ) ;
return V_59 ;
}
static int F_51 ( struct V_60 * V_61 )
{
struct V_49 * V_50 = V_61 -> V_37 -> V_62 -> V_34 ;
unsigned long V_63 ;
struct V_13 * V_13 ;
if ( V_61 -> V_64 & ( V_65 | V_66 ) )
return V_67 ;
V_63 = V_61 -> V_68 << V_69 ;
if ( V_63 >= F_52 ( V_50 -> V_58 , V_15 ) )
return V_67 ;
V_13 = F_53 ( V_50 -> V_57 + V_63 ) ;
F_54 ( V_13 ) ;
V_61 -> V_13 = V_13 ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
if ( V_37 -> V_43 & V_70 ) {
V_37 -> V_43 &= ~ V_46 ;
if ( V_37 -> V_43 & V_44 )
return - V_71 ;
}
V_37 -> V_43 |= V_72 | V_73 ;
V_37 -> V_74 = & V_75 ;
return 0 ;
}
static T_2 F_56 ( struct V_4 * V_4 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
T_2 V_11 ;
void * V_57 = NULL ;
F_39 ( & V_52 ) ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_76 , NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_17 ;
if ( * V_8 != 0 )
goto V_18;
V_11 = - V_77 ;
if ( V_7 > 64 * 1024 * 1024 )
goto V_18;
V_11 = - V_16 ;
V_57 = F_57 ( V_7 ) ;
if ( ! V_57 )
goto V_18;
V_11 = - V_78 ;
if ( F_58 ( V_57 , V_6 , V_7 ) != 0 )
goto V_18;
V_11 = F_59 ( V_57 , V_7 ) ;
if ( V_11 ) {
F_60 ( L_5 ) ;
goto V_18;
}
V_11 = F_61 () ;
if ( V_11 ) {
F_62 ( L_6 ) ;
goto V_79;
}
V_11 = F_63 () ;
if ( V_11 ) {
F_62 ( L_7 ) ;
goto V_79;
}
V_11 = F_64 () ;
if ( V_11 ) {
F_62 ( L_8 ) ;
goto V_79;
}
V_11 = V_7 ;
V_79:
F_12 ( V_22 -> V_23 , V_24 , V_80 ,
L_9 ,
F_13 ( & V_26 , F_14 ( V_22 ) ) ,
F_15 ( V_22 ) ) ;
V_18:
F_47 ( & V_52 ) ;
F_48 ( V_57 ) ;
return V_11 ;
}
static T_2 F_65 ( struct V_4 * V_4 , char * V_6 , T_4 V_38 )
{
char * V_81 = NULL ;
T_7 V_82 , V_58 ;
T_2 V_11 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_83 , NULL ) ;
if ( V_11 )
goto V_18;
V_11 = F_66 ( V_6 , V_38 , & V_82 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_67 ( V_82 , & V_81 , & V_58 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_84 ;
if ( V_58 > V_85 ) {
F_68 ( V_86 L_10
L_11 , V_87 , V_58 ) ;
goto V_18;
}
memcpy ( V_6 , V_81 , V_58 ) ;
V_11 = V_58 ;
V_18:
F_20 ( V_81 ) ;
return V_11 ;
}
static T_2 F_69 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_4 , V_3 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static T_2 F_70 ( struct V_4 * V_4 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 ;
T_2 V_11 ;
unsigned int V_14 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_88 ,
NULL ) ;
if ( V_11 )
return V_11 ;
if ( V_7 >= V_15 )
return - V_16 ;
if ( * V_8 != 0 )
return - V_17 ;
V_13 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_13 ) )
return F_9 ( V_13 ) ;
V_11 = - V_17 ;
if ( sscanf ( V_13 , L_4 , & V_14 ) != 1 )
goto V_18;
V_3 = V_14 ? 1 : 0 ;
V_11 = V_7 ;
V_18:
F_20 ( V_13 ) ;
return V_11 ;
}
static T_2 F_71 ( struct V_4 * V_4 ,
const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_89 = NULL , * V_90 = NULL , * V_91 = NULL ;
char * V_92 = NULL ;
T_7 V_93 , V_94 , V_95 ;
T_8 V_96 ;
int V_51 ;
V_51 = F_10 ( F_11 () , V_19 ,
V_20 , V_97 , NULL ) ;
if ( V_51 )
goto V_18;
V_51 = - V_16 ;
if ( V_7 >= V_15 )
goto V_18;
V_51 = - V_17 ;
if ( * V_8 != 0 )
goto V_18;
V_92 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_92 ) ) {
V_51 = F_9 ( V_92 ) ;
V_92 = NULL ;
goto V_18;
}
V_51 = - V_16 ;
V_89 = F_40 ( V_7 + 1 , V_24 ) ;
if ( ! V_89 )
goto V_18;
V_90 = F_40 ( V_7 + 1 , V_24 ) ;
if ( ! V_90 )
goto V_18;
V_91 = F_40 ( V_7 + 1 , V_24 ) ;
if ( ! V_91 )
goto V_18;
V_51 = - V_17 ;
if ( sscanf ( V_92 , L_12 , V_89 , V_90 , & V_96 , V_91 ) != 4 )
goto V_18;
V_51 = F_72 ( V_89 , & V_93 , V_24 ) ;
if ( V_51 )
goto V_18;
V_51 = F_72 ( V_90 , & V_94 , V_24 ) ;
if ( V_51 )
goto V_18;
V_51 = F_72 ( V_91 , & V_95 , V_24 ) ;
if ( V_51 )
goto V_18;
V_51 = F_73 ( V_93 , V_94 , V_95 , V_96 ) ;
if ( ! V_51 )
V_51 = V_7 ;
V_18:
F_20 ( V_92 ) ;
F_20 ( V_89 ) ;
F_20 ( V_90 ) ;
F_20 ( V_91 ) ;
return V_51 ;
}
static T_2 F_74 ( struct V_4 * V_4 , const char T_3 * V_6 , T_4 V_38 , T_5 * V_98 )
{
T_6 V_28 = F_22 ( V_4 ) -> V_29 ;
char * V_57 ;
T_2 V_99 ;
if ( V_28 >= F_75 ( V_100 ) || ! V_100 [ V_28 ] )
return - V_17 ;
V_57 = F_76 ( V_4 , V_6 , V_38 ) ;
if ( F_8 ( V_57 ) )
return F_9 ( V_57 ) ;
V_99 = V_100 [ V_28 ] ( V_4 , V_57 , V_38 ) ;
if ( V_99 > 0 ) {
F_77 ( V_4 , V_99 ) ;
V_99 = V_38 ;
}
return V_99 ;
}
static T_2 F_78 ( struct V_4 * V_4 , char * V_6 , T_4 V_38 )
{
char * V_101 = NULL , * V_102 = NULL ;
T_7 V_103 , V_95 ;
T_8 V_96 ;
struct V_104 V_105 ;
T_2 V_11 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_106 , NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_16 ;
V_102 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_102 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_13 , V_101 , V_102 , & V_96 ) != 3 )
goto V_18;
V_11 = F_72 ( V_101 , & V_103 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_72 ( V_102 , & V_95 , V_24 ) ;
if ( V_11 )
goto V_18;
F_79 ( V_103 , V_95 , V_96 , & V_105 ) ;
V_11 = F_4 ( V_6 , V_85 ,
L_14 ,
V_105 . V_107 , 0xffffffff ,
V_105 . V_108 , V_105 . V_109 ,
V_105 . V_110 , V_105 . V_64 ) ;
V_18:
F_20 ( V_102 ) ;
F_20 ( V_101 ) ;
return V_11 ;
}
static T_2 F_80 ( struct V_4 * V_4 , char * V_6 , T_4 V_38 )
{
char * V_101 = NULL , * V_102 = NULL ;
char * V_111 = NULL , * V_112 = NULL ;
T_7 V_103 , V_95 , V_113 ;
T_8 V_96 ;
T_2 V_11 ;
char * V_90 = NULL ;
T_7 V_58 ;
int V_114 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_115 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_16 ;
V_102 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_102 )
goto V_18;
V_11 = - V_16 ;
V_111 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_111 )
goto V_18;
V_11 = - V_17 ;
V_114 = sscanf ( V_6 , L_12 , V_101 , V_102 , & V_96 , V_111 ) ;
if ( V_114 < 3 || V_114 > 4 )
goto V_18;
if ( V_114 == 4 ) {
char * V_116 , * V_117 ;
int V_118 , V_119 ;
V_116 = V_117 = V_111 ;
do {
V_118 = * V_116 ++ ;
if ( V_118 == '+' )
V_118 = ' ' ;
else if ( V_118 == '%' ) {
V_118 = F_81 ( * V_116 ++ ) ;
if ( V_118 < 0 )
goto V_18;
V_119 = F_81 ( * V_116 ++ ) ;
if ( V_119 < 0 )
goto V_18;
V_118 = ( V_118 << 4 ) | V_119 ;
}
* V_117 ++ = V_118 ;
} while ( V_118 != '\0' );
V_112 = V_111 ;
}
V_11 = F_72 ( V_101 , & V_103 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_72 ( V_102 , & V_95 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_82 ( V_103 , V_95 , V_96 ,
V_112 , & V_113 ) ;
if ( V_11 )
goto V_18;
V_11 = F_67 ( V_113 , & V_90 , & V_58 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_84 ;
if ( V_58 > V_85 ) {
F_68 ( V_86 L_10
L_11 , V_87 , V_58 ) ;
goto V_18;
}
memcpy ( V_6 , V_90 , V_58 ) ;
V_11 = V_58 ;
V_18:
F_20 ( V_90 ) ;
F_20 ( V_111 ) ;
F_20 ( V_102 ) ;
F_20 ( V_101 ) ;
return V_11 ;
}
static T_2 F_83 ( struct V_4 * V_4 , char * V_6 , T_4 V_38 )
{
char * V_101 = NULL , * V_102 = NULL ;
T_7 V_103 , V_95 , V_113 ;
T_8 V_96 ;
T_2 V_11 ;
char * V_90 = NULL ;
T_7 V_58 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_120 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_16 ;
V_102 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_102 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_13 , V_101 , V_102 , & V_96 ) != 3 )
goto V_18;
V_11 = F_72 ( V_101 , & V_103 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_72 ( V_102 , & V_95 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_84 ( V_103 , V_95 , V_96 , & V_113 ) ;
if ( V_11 )
goto V_18;
V_11 = F_67 ( V_113 , & V_90 , & V_58 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_84 ;
if ( V_58 > V_85 )
goto V_18;
memcpy ( V_6 , V_90 , V_58 ) ;
V_11 = V_58 ;
V_18:
F_20 ( V_90 ) ;
F_20 ( V_102 ) ;
F_20 ( V_101 ) ;
return V_11 ;
}
static T_2 F_85 ( struct V_4 * V_4 , char * V_6 , T_4 V_38 )
{
char * V_121 = NULL , * V_122 = NULL , * V_123 ;
T_7 V_82 , * V_124 = NULL ;
T_2 V_11 ;
char * V_90 ;
int V_125 , V_51 ;
T_7 V_58 , V_126 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_127 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_121 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_121 )
goto V_18;
V_11 = - V_16 ;
V_122 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_122 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_15 , V_121 , V_122 ) != 2 )
goto V_18;
V_11 = F_72 ( V_121 , & V_82 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_86 ( V_82 , V_122 , & V_124 , & V_126 ) ;
if ( V_11 )
goto V_18;
V_11 = sprintf ( V_6 , L_4 , V_126 ) + 1 ;
V_123 = V_6 + V_11 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
V_51 = F_67 ( V_124 [ V_125 ] , & V_90 , & V_58 ) ;
if ( V_51 ) {
V_11 = V_51 ;
goto V_18;
}
if ( ( V_11 + V_58 ) >= V_85 ) {
F_20 ( V_90 ) ;
V_11 = - V_84 ;
goto V_18;
}
memcpy ( V_123 , V_90 , V_58 ) ;
F_20 ( V_90 ) ;
V_123 += V_58 ;
V_11 += V_58 ;
}
V_18:
F_20 ( V_124 ) ;
F_20 ( V_122 ) ;
F_20 ( V_121 ) ;
return V_11 ;
}
static T_2 F_87 ( struct V_4 * V_4 , char * V_6 , T_4 V_38 )
{
char * V_101 = NULL , * V_102 = NULL ;
T_7 V_103 , V_95 , V_113 ;
T_8 V_96 ;
T_2 V_11 ;
char * V_90 = NULL ;
T_7 V_58 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_128 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_16 ;
V_102 = F_40 ( V_38 + 1 , V_24 ) ;
if ( ! V_102 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_13 , V_101 , V_102 , & V_96 ) != 3 )
goto V_18;
V_11 = F_72 ( V_101 , & V_103 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_72 ( V_102 , & V_95 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_88 ( V_103 , V_95 , V_96 , & V_113 ) ;
if ( V_11 )
goto V_18;
V_11 = F_67 ( V_113 , & V_90 , & V_58 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_84 ;
if ( V_58 > V_85 ) {
F_68 ( V_86 L_10
L_11 , V_87 , V_58 ) ;
goto V_18;
}
memcpy ( V_6 , V_90 , V_58 ) ;
V_11 = V_58 ;
V_18:
F_20 ( V_90 ) ;
F_20 ( V_102 ) ;
F_20 ( V_101 ) ;
return V_11 ;
}
static struct V_32 * F_89 ( struct V_129 * V_130 , int V_131 )
{
struct V_32 * V_59 = F_90 ( V_130 ) ;
if ( V_59 ) {
V_59 -> V_132 = V_131 ;
V_59 -> V_133 = V_59 -> V_134 = V_59 -> V_135 = F_91 ( V_59 ) ;
}
return V_59 ;
}
static T_2 F_92 ( struct V_4 * V_136 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 = NULL ;
T_2 V_11 ;
T_2 V_59 ;
int V_137 ;
unsigned V_138 = F_22 ( V_136 ) -> V_29 & V_139 ;
const char * V_140 = V_136 -> V_141 . V_142 -> V_143 . V_140 ;
F_39 ( & V_52 ) ;
V_59 = - V_17 ;
if ( V_138 >= V_144 || strcmp ( V_140 , V_145 [ V_138 ] ) )
goto V_18;
V_59 = - V_16 ;
V_13 = ( char * ) F_93 ( V_24 ) ;
if ( ! V_13 )
goto V_18;
V_137 = F_94 ( V_138 ) ;
if ( V_137 < 0 ) {
V_59 = V_137 ;
goto V_18;
}
V_11 = F_4 ( V_13 , V_15 , L_16 , V_137 ,
V_146 [ V_138 ] ) ;
V_59 = F_5 ( V_6 , V_7 , V_8 , V_13 , V_11 ) ;
V_18:
F_47 ( & V_52 ) ;
F_95 ( ( unsigned long ) V_13 ) ;
return V_59 ;
}
static T_2 F_96 ( struct V_4 * V_136 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 = NULL ;
T_2 V_11 ;
int V_14 ;
unsigned V_138 = F_22 ( V_136 ) -> V_29 & V_139 ;
const char * V_140 = V_136 -> V_141 . V_142 -> V_143 . V_140 ;
F_39 ( & V_52 ) ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_147 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_17 ;
if ( V_138 >= V_144 || strcmp ( V_140 , V_145 [ V_138 ] ) )
goto V_18;
V_11 = - V_16 ;
if ( V_7 >= V_15 )
goto V_18;
V_11 = - V_17 ;
if ( * V_8 != 0 )
goto V_18;
V_13 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_13 ) ) {
V_11 = F_9 ( V_13 ) ;
V_13 = NULL ;
goto V_18;
}
V_11 = - V_17 ;
if ( sscanf ( V_13 , L_1 , & V_14 ) != 1 )
goto V_18;
if ( V_14 )
V_14 = 1 ;
V_146 [ V_138 ] = V_14 ;
V_11 = V_7 ;
V_18:
F_47 ( & V_52 ) ;
F_20 ( V_13 ) ;
return V_11 ;
}
static T_2 F_97 ( struct V_4 * V_136 ,
const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 = NULL ;
T_2 V_11 ;
int V_14 ;
F_39 ( & V_52 ) ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_147 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
if ( V_7 >= V_15 )
goto V_18;
V_11 = - V_17 ;
if ( * V_8 != 0 )
goto V_18;
V_13 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_13 ) ) {
V_11 = F_9 ( V_13 ) ;
V_13 = NULL ;
goto V_18;
}
V_11 = - V_17 ;
if ( sscanf ( V_13 , L_1 , & V_14 ) != 1 )
goto V_18;
V_11 = 0 ;
if ( V_14 && V_146 )
V_11 = F_98 ( V_144 , V_146 ) ;
if ( ! V_11 )
V_11 = V_7 ;
V_18:
F_47 ( & V_52 ) ;
F_20 ( V_13 ) ;
return V_11 ;
}
static void F_99 ( struct V_142 * V_148 )
{
F_100 ( V_148 ) ;
F_101 ( V_148 ) ;
}
static int F_61 ( void )
{
int V_125 , V_59 ;
T_2 V_58 ;
struct V_142 * V_142 = NULL ;
struct V_142 * V_149 = V_150 ;
struct V_32 * V_32 = NULL ;
struct V_151 * V_152 ;
char * * V_153 = NULL , * V_13 ;
int V_154 ;
int * V_155 = NULL ;
T_7 V_82 ;
for ( V_125 = 0 ; V_125 < V_144 ; V_125 ++ )
F_20 ( V_145 [ V_125 ] ) ;
F_20 ( V_145 ) ;
F_20 ( V_146 ) ;
V_144 = 0 ;
V_145 = NULL ;
V_146 = NULL ;
F_99 ( V_149 ) ;
V_59 = - V_16 ;
V_13 = ( char * ) F_93 ( V_24 ) ;
if ( ! V_13 )
goto V_18;
V_59 = F_102 ( & V_154 , & V_153 , & V_155 ) ;
if ( V_59 )
goto V_18;
for ( V_125 = 0 ; V_125 < V_154 ; V_125 ++ ) {
V_59 = - V_16 ;
V_142 = F_103 ( V_149 , V_153 [ V_125 ] ) ;
if ( ! V_142 )
goto V_18;
V_59 = - V_16 ;
V_32 = F_89 ( V_149 -> V_156 , V_157 | V_158 | V_159 ) ;
if ( ! V_32 )
goto V_18;
V_59 = - V_160 ;
V_58 = snprintf ( V_13 , V_15 , L_17 , V_161 , V_153 [ V_125 ] ) ;
if ( V_58 >= V_15 )
goto V_18;
V_152 = (struct V_151 * ) V_32 -> V_162 ;
V_59 = F_104 ( L_18 , V_13 , V_163 , & V_82 ) ;
if ( V_59 ) {
F_60 ( L_19 ,
V_13 ) ;
V_82 = V_19 ;
}
V_152 -> V_82 = V_82 ;
V_152 -> V_164 = V_165 ;
V_32 -> V_166 = & V_167 ;
V_32 -> V_29 = V_125 | V_168 ;
F_105 ( V_142 , V_32 ) ;
}
V_144 = V_154 ;
V_145 = V_153 ;
V_146 = V_155 ;
F_95 ( ( unsigned long ) V_13 ) ;
return 0 ;
V_18:
F_95 ( ( unsigned long ) V_13 ) ;
if ( V_153 ) {
for ( V_125 = 0 ; V_125 < V_154 ; V_125 ++ )
F_20 ( V_153 [ V_125 ] ) ;
F_20 ( V_153 ) ;
}
F_20 ( V_155 ) ;
F_99 ( V_149 ) ;
return V_59 ;
}
static T_2 F_106 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_4 , V_169 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static T_2 F_107 ( struct V_4 * V_4 ,
const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 ;
T_2 V_59 ;
unsigned int V_14 ;
V_59 = F_10 ( F_11 () , V_19 ,
V_20 , V_170 ,
NULL ) ;
if ( V_59 )
return V_59 ;
if ( V_7 >= V_15 )
return - V_16 ;
if ( * V_8 != 0 )
return - V_17 ;
V_13 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_13 ) )
return F_9 ( V_13 ) ;
V_59 = - V_17 ;
if ( sscanf ( V_13 , L_4 , & V_14 ) != 1 )
goto V_18;
V_169 = V_14 ;
V_59 = V_7 ;
V_18:
F_20 ( V_13 ) ;
return V_59 ;
}
static T_2 F_108 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 ;
T_2 V_11 ;
V_13 = ( char * ) F_109 ( V_24 ) ;
if ( ! V_13 )
return - V_16 ;
V_11 = F_110 ( V_13 ) ;
if ( V_11 >= 0 )
V_11 = F_5 ( V_6 , V_7 , V_8 , V_13 , V_11 ) ;
F_95 ( ( unsigned long ) V_13 ) ;
return V_11 ;
}
static struct V_171 * F_111 ( T_5 * V_172 )
{
int V_173 ;
for ( V_173 = * V_172 ; V_173 < V_174 ; ++ V_173 ) {
if ( ! F_112 ( V_173 ) )
continue;
* V_172 = V_173 + 1 ;
return & F_113 ( V_171 , V_173 ) ;
}
return NULL ;
}
static void * F_114 ( struct V_175 * V_176 , T_5 * V_98 )
{
T_5 V_177 = * V_98 - 1 ;
if ( * V_98 == 0 )
return V_178 ;
return F_111 ( & V_177 ) ;
}
static void * F_115 ( struct V_175 * V_176 , void * V_179 , T_5 * V_98 )
{
return F_111 ( V_98 ) ;
}
static int F_116 ( struct V_175 * V_176 , void * V_179 )
{
struct V_171 * V_180 = V_179 ;
if ( V_179 == V_178 ) {
F_117 ( V_176 ,
L_20 ) ;
} else {
unsigned int V_181 = V_180 -> V_181 ;
unsigned int V_182 = V_180 -> V_182 ;
unsigned int V_183 = V_181 - V_182 ;
F_118 ( V_176 , L_21 , V_181 ,
V_183 , V_182 , V_180 -> V_184 ,
V_180 -> V_185 , V_180 -> V_186 ) ;
}
return 0 ;
}
static void F_119 ( struct V_175 * V_176 , void * V_179 )
{ }
static int F_120 ( struct V_32 * V_32 , struct V_4 * V_4 )
{
return F_121 ( V_4 , & V_187 ) ;
}
static int F_122 ( struct V_142 * V_149 )
{
int V_125 ;
static const struct V_188 V_189 [] = {
{ L_22 ,
& V_190 , V_158 | V_159 } ,
{ L_23 , & V_191 , V_158 } ,
#ifdef F_123
{ L_24 , & V_192 , V_158 } ,
#endif
} ;
for ( V_125 = 0 ; V_125 < F_75 ( V_189 ) ; V_125 ++ ) {
struct V_32 * V_32 ;
struct V_142 * V_142 ;
V_142 = F_103 ( V_149 , V_189 [ V_125 ] . V_140 ) ;
if ( ! V_142 )
return - V_16 ;
V_32 = F_89 ( V_149 -> V_156 , V_157 | V_189 [ V_125 ] . V_131 ) ;
if ( ! V_32 )
return - V_16 ;
V_32 -> V_166 = V_189 [ V_125 ] . V_193 ;
V_32 -> V_29 = ++ V_194 ;
F_105 ( V_142 , V_32 ) ;
}
return 0 ;
}
static T_2 F_124 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_121 ;
T_7 V_82 , V_58 ;
T_2 V_59 ;
V_82 = F_22 ( V_4 ) -> V_29 & V_139 ;
V_59 = F_67 ( V_82 , & V_121 , & V_58 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_5 ( V_6 , V_7 , V_8 , V_121 , V_58 ) ;
F_20 ( V_121 ) ;
return V_59 ;
}
static int F_125 ( struct V_142 * V_149 )
{
int V_125 ;
for ( V_125 = 1 ; V_125 <= V_195 ; V_125 ++ ) {
struct V_32 * V_32 ;
struct V_142 * V_142 ;
V_142 = F_103 ( V_149 , F_126 ( V_125 ) ) ;
if ( ! V_142 )
return - V_16 ;
V_32 = F_89 ( V_149 -> V_156 , V_157 | V_158 ) ;
if ( ! V_32 )
return - V_16 ;
V_32 -> V_166 = & V_196 ;
V_32 -> V_29 = V_125 | V_197 ;
F_105 ( V_142 , V_32 ) ;
}
return 0 ;
}
static inline unsigned long F_127 ( T_8 V_198 )
{
return ( V_198 * ( V_199 + 1 ) ) | V_200 ;
}
static inline T_8 F_128 ( unsigned long V_28 )
{
return ( V_28 & V_139 ) / ( V_199 + 1 ) ;
}
static inline unsigned long F_129 ( T_8 V_198 , T_7 V_201 )
{
return ( V_198 * ( V_199 + 1 ) + V_201 ) | V_200 ;
}
static inline T_7 F_130 ( unsigned long V_28 )
{
return ( V_28 & V_139 ) % ( V_199 + 1 ) ;
}
static T_2 F_131 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
unsigned long V_28 = F_22 ( V_4 ) -> V_29 ;
char V_202 [ V_10 ] ;
T_2 V_58 = snprintf ( V_202 , sizeof( V_202 ) , L_1 , F_128 ( V_28 ) ) ;
return F_5 ( V_6 , V_7 , V_8 , V_202 , V_58 ) ;
}
static T_2 F_132 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
unsigned long V_28 = F_22 ( V_4 ) -> V_29 ;
char V_202 [ V_10 ] ;
T_2 V_58 = snprintf ( V_202 , sizeof( V_202 ) , L_1 , F_130 ( V_28 ) ) ;
return F_5 ( V_6 , V_7 , V_8 , V_202 , V_58 ) ;
}
static T_2 F_133 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
int V_203 ;
char V_9 [ V_10 ] ;
T_2 V_11 ;
unsigned long V_29 = F_22 ( V_4 ) -> V_29 ;
V_203 = F_134 ( V_29 & V_139 ) ;
V_11 = F_4 ( V_9 , V_10 , L_1 , V_203 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static int F_135 ( char * V_204 , int V_205 ,
struct V_142 * V_149 )
{
int V_125 , V_51 , V_206 ;
char * * V_207 ;
V_51 = F_136 ( V_204 , & V_207 , & V_206 ) ;
if ( V_51 )
return V_51 ;
for ( V_125 = 0 ; V_125 < V_206 ; V_125 ++ ) {
struct V_32 * V_32 ;
struct V_142 * V_142 ;
V_51 = - V_16 ;
V_142 = F_103 ( V_149 , V_207 [ V_125 ] ) ;
if ( ! V_142 )
goto V_18;
V_51 = - V_16 ;
V_32 = F_89 ( V_149 -> V_156 , V_157 | V_158 ) ;
if ( ! V_32 )
goto V_18;
V_32 -> V_166 = & V_208 ;
V_32 -> V_29 = F_129 ( V_205 , V_125 + 1 ) ;
F_105 ( V_142 , V_32 ) ;
}
V_51 = 0 ;
V_18:
for ( V_125 = 0 ; V_125 < V_206 ; V_125 ++ )
F_20 ( V_207 [ V_125 ] ) ;
F_20 ( V_207 ) ;
return V_51 ;
}
static int F_137 ( char * V_209 , int V_138 ,
struct V_142 * V_149 )
{
struct V_142 * V_142 = NULL ;
struct V_32 * V_32 = NULL ;
int V_51 ;
V_142 = F_103 ( V_149 , L_25 ) ;
if ( ! V_142 )
return - V_16 ;
V_32 = F_89 ( V_149 -> V_156 , V_157 | V_158 ) ;
if ( ! V_32 )
return - V_16 ;
V_32 -> V_166 = & V_210 ;
V_32 -> V_29 = F_127 ( V_138 ) ;
F_105 ( V_142 , V_32 ) ;
V_142 = F_138 ( V_149 , L_26 , & V_211 ) ;
if ( F_8 ( V_142 ) )
return F_9 ( V_142 ) ;
V_51 = F_135 ( V_209 , V_138 , V_142 ) ;
return V_51 ;
}
static int F_63 ( void )
{
int V_51 , V_212 , V_125 ;
char * * V_213 ;
F_99 ( V_214 ) ;
V_51 = F_139 ( & V_213 , & V_212 ) ;
if ( V_51 )
return V_51 ;
V_211 = F_127 ( V_212 + 2 ) ;
for ( V_125 = 0 ; V_125 < V_212 ; V_125 ++ ) {
struct V_142 * V_215 ;
V_215 = F_138 ( V_214 , V_213 [ V_125 ] ,
& V_211 ) ;
if ( F_8 ( V_215 ) ) {
V_51 = F_9 ( V_215 ) ;
goto V_18;
}
V_51 = F_137 ( V_213 [ V_125 ] , V_125 + 1 ,
V_215 ) ;
if ( V_51 )
goto V_18;
}
V_51 = 0 ;
V_18:
for ( V_125 = 0 ; V_125 < V_212 ; V_125 ++ )
F_20 ( V_213 [ V_125 ] ) ;
F_20 ( V_213 ) ;
return V_51 ;
}
static int F_64 ( void )
{
unsigned int V_216 ;
struct V_142 * V_142 = NULL ;
struct V_32 * V_32 = NULL ;
F_99 ( V_217 ) ;
for ( V_216 = 0 ; V_216 <= V_218 ; V_216 ++ ) {
if ( V_216 < F_75 ( V_219 ) )
V_142 = F_103 ( V_217 ,
V_219 [ V_216 ] ) ;
else
V_142 = F_103 ( V_217 , L_27 ) ;
if ( V_142 == NULL )
return - V_16 ;
V_32 = F_89 ( V_217 -> V_156 , V_157 | V_158 ) ;
if ( V_32 == NULL )
return - V_16 ;
V_32 -> V_166 = & V_220 ;
V_32 -> V_29 = V_216 | V_221 ;
F_105 ( V_142 , V_32 ) ;
}
return 0 ;
}
static struct V_142 * F_138 ( struct V_142 * V_149 , const char * V_140 ,
unsigned long * V_28 )
{
struct V_142 * V_142 = F_103 ( V_149 , V_140 ) ;
struct V_32 * V_32 ;
if ( ! V_142 )
return F_140 ( - V_16 ) ;
V_32 = F_89 ( V_149 -> V_156 , V_222 | V_158 | V_223 ) ;
if ( ! V_32 ) {
F_141 ( V_142 ) ;
return F_140 ( - V_16 ) ;
}
V_32 -> V_224 = & V_225 ;
V_32 -> V_166 = & V_226 ;
V_32 -> V_29 = ++ ( * V_28 ) ;
F_142 ( V_32 ) ;
F_105 ( V_142 , V_32 ) ;
F_142 ( F_143 ( V_149 ) ) ;
return V_142 ;
}
static int F_144 ( struct V_129 * V_130 , void * V_57 , int V_227 )
{
int V_59 ;
struct V_142 * V_142 ;
struct V_32 * V_32 ;
struct V_151 * V_152 ;
static const struct V_188 V_228 [] = {
[ V_229 ] = { L_28 , & V_230 , V_231 | V_159 } ,
[ V_232 ] = { L_29 , & V_233 , V_158 | V_159 } ,
[ V_234 ] = { L_30 , & V_235 , V_158 | V_236 } ,
[ V_237 ] = { L_31 , & V_235 , V_158 | V_236 } ,
[ V_238 ] = { L_32 , & V_235 , V_158 | V_236 } ,
[ V_239 ] = { L_33 , & V_235 , V_158 | V_236 } ,
[ V_240 ] = { L_34 , & V_235 , V_158 | V_236 } ,
[ V_241 ] = { L_35 , & V_242 , V_158 } ,
[ V_243 ] = { L_36 , & V_244 , V_159 } ,
[ V_245 ] = { L_37 , & V_246 , V_158 } ,
[ V_247 ] = { L_38 , & V_248 , V_159 } ,
[ V_249 ] = { L_39 , & V_235 , V_158 | V_236 } ,
[ V_250 ] = { L_40 , & V_251 , V_158 | V_159 } ,
[ V_31 ] = { L_41 , & V_252 , V_158 } ,
[ V_253 ] = { L_42 , & V_252 , V_158 } ,
[ V_254 ] = { L_43 , & V_255 , V_158 } ,
[ V_256 ] = { L_44 , & V_257 , V_158 } ,
[ V_258 ] = { L_45 , & V_259 ,
V_236 } ,
{ L_46 }
} ;
V_59 = F_145 ( V_130 , V_260 , V_228 ) ;
if ( V_59 )
goto V_54;
V_150 = F_138 ( V_130 -> V_261 , V_161 , & V_194 ) ;
if ( F_8 ( V_150 ) ) {
V_59 = F_9 ( V_150 ) ;
V_150 = NULL ;
goto V_54;
}
V_59 = - V_16 ;
V_142 = F_103 ( V_130 -> V_261 , V_262 ) ;
if ( ! V_142 )
goto V_54;
V_59 = - V_16 ;
V_32 = F_89 ( V_130 , V_263 | V_158 | V_236 ) ;
if ( ! V_32 )
goto V_54;
V_32 -> V_29 = ++ V_194 ;
V_152 = (struct V_151 * ) V_32 -> V_162 ;
V_152 -> V_82 = V_264 ;
V_152 -> V_265 = V_266 ;
V_152 -> V_164 = V_165 ;
F_146 ( V_32 , V_263 | V_158 | V_236 , F_147 ( V_267 , 3 ) ) ;
F_105 ( V_142 , V_32 ) ;
V_268 . V_142 = V_142 ;
V_142 = F_138 ( V_130 -> V_261 , L_47 , & V_194 ) ;
if ( F_8 ( V_142 ) ) {
V_59 = F_9 ( V_142 ) ;
goto V_54;
}
V_59 = F_122 ( V_142 ) ;
if ( V_59 )
goto V_54;
V_142 = F_138 ( V_130 -> V_261 , L_48 , & V_194 ) ;
if ( F_8 ( V_142 ) ) {
V_59 = F_9 ( V_142 ) ;
goto V_54;
}
V_59 = F_125 ( V_142 ) ;
if ( V_59 )
goto V_54;
V_214 = F_138 ( V_130 -> V_261 , L_49 , & V_194 ) ;
if ( F_8 ( V_214 ) ) {
V_59 = F_9 ( V_214 ) ;
V_214 = NULL ;
goto V_54;
}
V_217 = F_138 ( V_130 -> V_261 , L_50 , & V_194 ) ;
if ( F_8 ( V_217 ) ) {
V_59 = F_9 ( V_217 ) ;
V_217 = NULL ;
goto V_54;
}
return 0 ;
V_54:
F_68 ( V_86 L_51 ,
V_87 ) ;
return V_59 ;
}
static struct V_142 * F_148 ( struct V_269 * V_270 ,
int V_64 , const char * V_271 , void * V_57 )
{
return F_149 ( V_270 , V_64 , V_57 , F_144 ) ;
}
static int T_1 F_150 ( void )
{
int V_54 ;
if ( ! V_272 )
return 0 ;
V_54 = F_151 ( V_273 , L_52 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_152 ( & V_274 ) ;
if ( V_54 ) {
F_153 ( V_273 , L_52 ) ;
return V_54 ;
}
V_268 . V_275 = V_276 = F_154 ( & V_274 ) ;
if ( F_8 ( V_276 ) ) {
F_68 ( V_86 L_53 ) ;
V_54 = F_9 ( V_276 ) ;
V_276 = NULL ;
}
return V_54 ;
}
void F_155 ( void )
{
F_153 ( V_273 , L_52 ) ;
F_156 ( V_276 ) ;
F_157 ( & V_274 ) ;
}
