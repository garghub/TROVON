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
}
V_11 = V_7 ;
V_18:
F_19 ( V_13 ) ;
return V_11 ;
}
static T_2 F_20 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
T_6 V_27 = F_21 ( V_5 ) -> V_28 ;
int V_29 = ( V_27 == V_30 ) ?
F_22 () : ! F_23 () ;
V_11 = F_4 ( V_9 , V_10 , L_1 , V_29 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static int F_24 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
struct V_13 * V_32 = F_25 () ;
if ( ! V_32 )
return - V_16 ;
V_5 -> V_33 = V_32 ;
return 0 ;
}
static T_2 F_26 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
struct V_13 * V_32 = V_5 -> V_33 ;
F_27 ( ! V_32 ) ;
return F_5 ( V_6 , V_7 , V_8 ,
F_28 ( V_32 ) ,
sizeof( struct V_34 ) ) ;
}
static int F_29 ( struct V_4 * V_5 ,
struct V_35 * V_36 )
{
struct V_13 * V_32 = V_5 -> V_33 ;
unsigned long V_37 = V_36 -> V_38 - V_36 -> V_39 ;
F_27 ( ! V_32 ) ;
if ( V_36 -> V_40 > 0 || V_37 != V_15 )
return - V_41 ;
if ( V_36 -> V_42 & V_43 )
return - V_44 ;
V_36 -> V_42 &= ~ V_45 ;
return F_30 ( V_36 , V_36 -> V_39 ,
F_31 ( V_32 ) ,
V_37 , V_36 -> V_46 ) ;
}
static T_2 F_32 ( struct V_4 * V_4 , const char T_3 * V_6 ,
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
V_11 = F_33 () ;
if ( V_11 )
goto V_18;
F_12 ( V_22 -> V_23 , V_24 , V_25 ,
L_3 ,
F_13 ( & V_26 , F_14 ( V_22 ) ) ,
F_15 ( V_22 ) ) ;
}
V_11 = V_7 ;
V_18:
F_19 ( V_13 ) ;
return V_11 ;
}
static T_2 F_34 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_4 , V_47 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static T_2 F_35 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_1 ,
F_36 () ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static int F_37 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
struct V_48 * V_49 = NULL ;
int V_50 ;
F_27 ( V_5 -> V_33 ) ;
F_38 ( & V_51 ) ;
V_50 = F_10 ( F_11 () , V_19 ,
V_20 , V_52 , NULL ) ;
if ( V_50 )
goto V_53;
V_50 = - V_54 ;
if ( V_55 )
goto V_53;
V_50 = - V_16 ;
V_49 = F_39 ( sizeof( * V_49 ) , V_24 ) ;
if ( ! V_49 )
goto V_53;
if ( F_40 ( V_31 ) != F_41 () ) {
F_42 ( V_31 ) ;
F_43 ( V_31 , F_41 () ) ;
F_44 ( V_31 ) ;
}
V_50 = F_45 ( & V_49 -> V_56 , & V_49 -> V_57 ) ;
if ( V_50 )
goto V_53;
V_55 = 1 ;
V_5 -> V_33 = V_49 ;
F_46 ( & V_51 ) ;
return 0 ;
V_53:
F_46 ( & V_51 ) ;
if ( V_49 )
F_47 ( V_49 -> V_56 ) ;
F_19 ( V_49 ) ;
return V_50 ;
}
static int F_48 ( struct V_31 * V_31 , struct V_4 * V_5 )
{
struct V_48 * V_49 = V_5 -> V_33 ;
F_27 ( ! V_49 ) ;
V_55 = 0 ;
F_47 ( V_49 -> V_56 ) ;
F_19 ( V_49 ) ;
return 0 ;
}
static T_2 F_49 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
struct V_48 * V_49 = V_5 -> V_33 ;
int V_58 ;
F_38 ( & V_51 ) ;
V_58 = F_10 ( F_11 () , V_19 ,
V_20 , V_52 , NULL ) ;
if ( V_58 )
goto V_18;
V_58 = F_5 ( V_6 , V_7 , V_8 , V_49 -> V_56 , V_49 -> V_57 ) ;
V_18:
F_46 ( & V_51 ) ;
return V_58 ;
}
static int F_50 ( struct V_59 * V_60 )
{
struct V_48 * V_49 = V_60 -> V_36 -> V_61 -> V_33 ;
unsigned long V_62 ;
struct V_13 * V_13 ;
if ( V_60 -> V_63 & ( V_64 | V_65 ) )
return V_66 ;
V_62 = V_60 -> V_67 << V_68 ;
if ( V_62 >= F_51 ( V_49 -> V_57 , V_15 ) )
return V_66 ;
V_13 = F_52 ( V_49 -> V_56 + V_62 ) ;
F_53 ( V_13 ) ;
V_60 -> V_13 = V_13 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 , struct V_35 * V_36 )
{
if ( V_36 -> V_42 & V_69 ) {
V_36 -> V_42 &= ~ V_45 ;
if ( V_36 -> V_42 & V_43 )
return - V_70 ;
}
V_36 -> V_42 |= V_71 | V_72 ;
V_36 -> V_73 = & V_74 ;
return 0 ;
}
static T_2 F_55 ( struct V_4 * V_4 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
T_2 V_11 ;
void * V_56 = NULL ;
F_38 ( & V_51 ) ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_75 , NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_17 ;
if ( * V_8 != 0 )
goto V_18;
V_11 = - V_76 ;
if ( V_7 > 64 * 1024 * 1024 )
goto V_18;
V_11 = - V_16 ;
V_56 = F_56 ( V_7 ) ;
if ( ! V_56 )
goto V_18;
V_11 = - V_77 ;
if ( F_57 ( V_56 , V_6 , V_7 ) != 0 )
goto V_18;
V_11 = F_58 ( V_56 , V_7 ) ;
if ( V_11 ) {
F_59 ( L_5 ) ;
goto V_18;
}
V_11 = F_60 () ;
if ( V_11 ) {
F_61 ( L_6 ) ;
goto V_78;
}
V_11 = F_62 () ;
if ( V_11 ) {
F_61 ( L_7 ) ;
goto V_78;
}
V_11 = F_63 () ;
if ( V_11 ) {
F_61 ( L_8 ) ;
goto V_78;
}
V_11 = V_7 ;
V_78:
F_12 ( V_22 -> V_23 , V_24 , V_79 ,
L_9 ,
F_13 ( & V_26 , F_14 ( V_22 ) ) ,
F_15 ( V_22 ) ) ;
V_18:
F_46 ( & V_51 ) ;
F_47 ( V_56 ) ;
return V_11 ;
}
static T_2 F_64 ( struct V_4 * V_4 , char * V_6 , T_4 V_37 )
{
char * V_80 = NULL ;
T_7 V_81 , V_57 ;
T_2 V_11 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_82 , NULL ) ;
if ( V_11 )
goto V_18;
V_11 = F_65 ( V_6 , V_37 , & V_81 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_66 ( V_81 , & V_80 , & V_57 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_83 ;
if ( V_57 > V_84 ) {
F_67 ( V_85 L_10
L_11 , V_86 , V_57 ) ;
goto V_18;
}
memcpy ( V_6 , V_80 , V_57 ) ;
V_11 = V_57 ;
V_18:
F_19 ( V_80 ) ;
return V_11 ;
}
static T_2 F_68 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_4 , V_3 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static T_2 F_69 ( struct V_4 * V_4 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 ;
T_2 V_11 ;
unsigned int V_14 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_87 ,
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
F_19 ( V_13 ) ;
return V_11 ;
}
static T_2 F_70 ( struct V_4 * V_4 ,
const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_88 = NULL , * V_89 = NULL , * V_90 = NULL ;
char * V_91 = NULL ;
T_7 V_92 , V_93 , V_94 ;
T_8 V_95 ;
int V_50 ;
V_50 = F_10 ( F_11 () , V_19 ,
V_20 , V_96 , NULL ) ;
if ( V_50 )
goto V_18;
V_50 = - V_16 ;
if ( V_7 >= V_15 )
goto V_18;
V_50 = - V_17 ;
if ( * V_8 != 0 )
goto V_18;
V_50 = - V_16 ;
V_91 = F_39 ( V_7 + 1 , V_24 ) ;
if ( ! V_91 )
goto V_18;
V_50 = - V_77 ;
if ( F_57 ( V_91 , V_6 , V_7 ) )
goto V_18;
V_50 = - V_16 ;
V_88 = F_39 ( V_7 + 1 , V_24 ) ;
if ( ! V_88 )
goto V_18;
V_89 = F_39 ( V_7 + 1 , V_24 ) ;
if ( ! V_89 )
goto V_18;
V_90 = F_39 ( V_7 + 1 , V_24 ) ;
if ( ! V_90 )
goto V_18;
V_50 = - V_17 ;
if ( sscanf ( V_91 , L_12 , V_88 , V_89 , & V_95 , V_90 ) != 4 )
goto V_18;
V_50 = F_71 ( V_88 , & V_92 , V_24 ) ;
if ( V_50 )
goto V_18;
V_50 = F_71 ( V_89 , & V_93 , V_24 ) ;
if ( V_50 )
goto V_18;
V_50 = F_71 ( V_90 , & V_94 , V_24 ) ;
if ( V_50 )
goto V_18;
V_50 = F_72 ( V_92 , V_93 , V_94 , V_95 ) ;
if ( ! V_50 )
V_50 = V_7 ;
V_18:
F_19 ( V_91 ) ;
F_19 ( V_88 ) ;
F_19 ( V_89 ) ;
F_19 ( V_90 ) ;
return V_50 ;
}
static T_2 F_73 ( struct V_4 * V_4 , const char T_3 * V_6 , T_4 V_37 , T_5 * V_97 )
{
T_6 V_27 = F_21 ( V_4 ) -> V_28 ;
char * V_56 ;
T_2 V_98 ;
if ( V_27 >= F_74 ( V_99 ) || ! V_99 [ V_27 ] )
return - V_17 ;
V_56 = F_75 ( V_4 , V_6 , V_37 ) ;
if ( F_8 ( V_56 ) )
return F_9 ( V_56 ) ;
V_98 = V_99 [ V_27 ] ( V_4 , V_56 , V_37 ) ;
if ( V_98 > 0 ) {
F_76 ( V_4 , V_98 ) ;
V_98 = V_37 ;
}
return V_98 ;
}
static T_2 F_77 ( struct V_4 * V_4 , char * V_6 , T_4 V_37 )
{
char * V_100 = NULL , * V_101 = NULL ;
T_7 V_102 , V_94 ;
T_8 V_95 ;
struct V_103 V_104 ;
T_2 V_11 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_105 , NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_100 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_100 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_13 , V_100 , V_101 , & V_95 ) != 3 )
goto V_18;
V_11 = F_71 ( V_100 , & V_102 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_71 ( V_101 , & V_94 , V_24 ) ;
if ( V_11 )
goto V_18;
F_78 ( V_102 , V_94 , V_95 , & V_104 ) ;
V_11 = F_4 ( V_6 , V_84 ,
L_14 ,
V_104 . V_106 , 0xffffffff ,
V_104 . V_107 , V_104 . V_108 ,
V_104 . V_109 , V_104 . V_63 ) ;
V_18:
F_19 ( V_101 ) ;
F_19 ( V_100 ) ;
return V_11 ;
}
static T_2 F_79 ( struct V_4 * V_4 , char * V_6 , T_4 V_37 )
{
char * V_100 = NULL , * V_101 = NULL ;
char * V_110 = NULL , * V_111 = NULL ;
T_7 V_102 , V_94 , V_112 ;
T_8 V_95 ;
T_2 V_11 ;
char * V_89 = NULL ;
T_7 V_57 ;
int V_113 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_114 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_100 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_100 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_16 ;
V_110 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_110 )
goto V_18;
V_11 = - V_17 ;
V_113 = sscanf ( V_6 , L_12 , V_100 , V_101 , & V_95 , V_110 ) ;
if ( V_113 < 3 || V_113 > 4 )
goto V_18;
if ( V_113 == 4 ) {
char * V_115 , * V_116 ;
int V_117 , V_118 ;
V_115 = V_116 = V_110 ;
do {
V_117 = * V_115 ++ ;
if ( V_117 == '+' )
V_117 = ' ' ;
else if ( V_117 == '%' ) {
V_117 = F_80 ( * V_115 ++ ) ;
if ( V_117 < 0 )
goto V_18;
V_118 = F_80 ( * V_115 ++ ) ;
if ( V_118 < 0 )
goto V_18;
V_117 = ( V_117 << 4 ) | V_118 ;
}
* V_116 ++ = V_117 ;
} while ( V_117 != '\0' );
V_111 = V_110 ;
}
V_11 = F_71 ( V_100 , & V_102 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_71 ( V_101 , & V_94 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_81 ( V_102 , V_94 , V_95 ,
V_111 , & V_112 ) ;
if ( V_11 )
goto V_18;
V_11 = F_66 ( V_112 , & V_89 , & V_57 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_83 ;
if ( V_57 > V_84 ) {
F_67 ( V_85 L_10
L_11 , V_86 , V_57 ) ;
goto V_18;
}
memcpy ( V_6 , V_89 , V_57 ) ;
V_11 = V_57 ;
V_18:
F_19 ( V_89 ) ;
F_19 ( V_110 ) ;
F_19 ( V_101 ) ;
F_19 ( V_100 ) ;
return V_11 ;
}
static T_2 F_82 ( struct V_4 * V_4 , char * V_6 , T_4 V_37 )
{
char * V_100 = NULL , * V_101 = NULL ;
T_7 V_102 , V_94 , V_112 ;
T_8 V_95 ;
T_2 V_11 ;
char * V_89 = NULL ;
T_7 V_57 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_119 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_100 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_100 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_13 , V_100 , V_101 , & V_95 ) != 3 )
goto V_18;
V_11 = F_71 ( V_100 , & V_102 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_71 ( V_101 , & V_94 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_83 ( V_102 , V_94 , V_95 , & V_112 ) ;
if ( V_11 )
goto V_18;
V_11 = F_66 ( V_112 , & V_89 , & V_57 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_83 ;
if ( V_57 > V_84 )
goto V_18;
memcpy ( V_6 , V_89 , V_57 ) ;
V_11 = V_57 ;
V_18:
F_19 ( V_89 ) ;
F_19 ( V_101 ) ;
F_19 ( V_100 ) ;
return V_11 ;
}
static T_2 F_84 ( struct V_4 * V_4 , char * V_6 , T_4 V_37 )
{
char * V_120 = NULL , * V_121 = NULL , * V_122 ;
T_7 V_81 , * V_123 = NULL ;
T_2 V_11 ;
char * V_89 ;
int V_124 , V_50 ;
T_7 V_57 , V_125 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_126 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_120 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_120 )
goto V_18;
V_11 = - V_16 ;
V_121 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_121 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_15 , V_120 , V_121 ) != 2 )
goto V_18;
V_11 = F_71 ( V_120 , & V_81 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_85 ( V_81 , V_121 , & V_123 , & V_125 ) ;
if ( V_11 )
goto V_18;
V_11 = sprintf ( V_6 , L_4 , V_125 ) + 1 ;
V_122 = V_6 + V_11 ;
for ( V_124 = 0 ; V_124 < V_125 ; V_124 ++ ) {
V_50 = F_66 ( V_123 [ V_124 ] , & V_89 , & V_57 ) ;
if ( V_50 ) {
V_11 = V_50 ;
goto V_18;
}
if ( ( V_11 + V_57 ) >= V_84 ) {
F_19 ( V_89 ) ;
V_11 = - V_83 ;
goto V_18;
}
memcpy ( V_122 , V_89 , V_57 ) ;
F_19 ( V_89 ) ;
V_122 += V_57 ;
V_11 += V_57 ;
}
V_18:
F_19 ( V_123 ) ;
F_19 ( V_121 ) ;
F_19 ( V_120 ) ;
return V_11 ;
}
static T_2 F_86 ( struct V_4 * V_4 , char * V_6 , T_4 V_37 )
{
char * V_100 = NULL , * V_101 = NULL ;
T_7 V_102 , V_94 , V_112 ;
T_8 V_95 ;
T_2 V_11 ;
char * V_89 = NULL ;
T_7 V_57 ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_127 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_16 ;
V_100 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_100 )
goto V_18;
V_11 = - V_16 ;
V_101 = F_39 ( V_37 + 1 , V_24 ) ;
if ( ! V_101 )
goto V_18;
V_11 = - V_17 ;
if ( sscanf ( V_6 , L_13 , V_100 , V_101 , & V_95 ) != 3 )
goto V_18;
V_11 = F_71 ( V_100 , & V_102 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_71 ( V_101 , & V_94 , V_24 ) ;
if ( V_11 )
goto V_18;
V_11 = F_87 ( V_102 , V_94 , V_95 , & V_112 ) ;
if ( V_11 )
goto V_18;
V_11 = F_66 ( V_112 , & V_89 , & V_57 ) ;
if ( V_11 )
goto V_18;
V_11 = - V_83 ;
if ( V_57 > V_84 ) {
F_67 ( V_85 L_10
L_11 , V_86 , V_57 ) ;
goto V_18;
}
memcpy ( V_6 , V_89 , V_57 ) ;
V_11 = V_57 ;
V_18:
F_19 ( V_89 ) ;
F_19 ( V_101 ) ;
F_19 ( V_100 ) ;
return V_11 ;
}
static struct V_31 * F_88 ( struct V_128 * V_129 , int V_130 )
{
struct V_31 * V_58 = F_89 ( V_129 ) ;
if ( V_58 ) {
V_58 -> V_131 = V_130 ;
V_58 -> V_132 = V_58 -> V_133 = V_58 -> V_134 = F_90 ( V_58 ) ;
}
return V_58 ;
}
static T_2 F_91 ( struct V_4 * V_135 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 = NULL ;
T_2 V_11 ;
T_2 V_58 ;
int V_136 ;
unsigned V_137 = F_21 ( V_135 ) -> V_28 & V_138 ;
const char * V_139 = V_135 -> V_140 . V_141 -> V_142 . V_139 ;
F_38 ( & V_51 ) ;
V_58 = - V_17 ;
if ( V_137 >= V_143 || strcmp ( V_139 , V_144 [ V_137 ] ) )
goto V_18;
V_58 = - V_16 ;
V_13 = ( char * ) F_92 ( V_24 ) ;
if ( ! V_13 )
goto V_18;
V_136 = F_93 ( V_137 ) ;
if ( V_136 < 0 ) {
V_58 = V_136 ;
goto V_18;
}
V_11 = F_4 ( V_13 , V_15 , L_16 , V_136 ,
V_145 [ V_137 ] ) ;
V_58 = F_5 ( V_6 , V_7 , V_8 , V_13 , V_11 ) ;
V_18:
F_46 ( & V_51 ) ;
F_94 ( ( unsigned long ) V_13 ) ;
return V_58 ;
}
static T_2 F_95 ( struct V_4 * V_135 , const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 = NULL ;
T_2 V_11 ;
int V_14 ;
unsigned V_137 = F_21 ( V_135 ) -> V_28 & V_138 ;
const char * V_139 = V_135 -> V_140 . V_141 -> V_142 . V_139 ;
F_38 ( & V_51 ) ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_146 ,
NULL ) ;
if ( V_11 )
goto V_18;
V_11 = - V_17 ;
if ( V_137 >= V_143 || strcmp ( V_139 , V_144 [ V_137 ] ) )
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
V_145 [ V_137 ] = V_14 ;
V_11 = V_7 ;
V_18:
F_46 ( & V_51 ) ;
F_19 ( V_13 ) ;
return V_11 ;
}
static T_2 F_96 ( struct V_4 * V_135 ,
const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 = NULL ;
T_2 V_11 ;
int V_14 ;
F_38 ( & V_51 ) ;
V_11 = F_10 ( F_11 () , V_19 ,
V_20 , V_146 ,
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
if ( V_14 && V_145 )
V_11 = F_97 ( V_143 , V_145 ) ;
if ( ! V_11 )
V_11 = V_7 ;
V_18:
F_46 ( & V_51 ) ;
F_19 ( V_13 ) ;
return V_11 ;
}
static void F_98 ( struct V_141 * V_147 )
{
F_99 ( V_147 ) ;
F_100 ( V_147 ) ;
}
static int F_60 ( void )
{
int V_124 , V_58 ;
T_2 V_57 ;
struct V_141 * V_141 = NULL ;
struct V_141 * V_148 = V_149 ;
struct V_31 * V_31 = NULL ;
struct V_150 * V_151 ;
char * * V_152 = NULL , * V_13 ;
int V_153 ;
int * V_154 = NULL ;
T_7 V_81 ;
for ( V_124 = 0 ; V_124 < V_143 ; V_124 ++ )
F_19 ( V_144 [ V_124 ] ) ;
F_19 ( V_144 ) ;
F_19 ( V_145 ) ;
V_143 = 0 ;
V_144 = NULL ;
V_145 = NULL ;
F_98 ( V_148 ) ;
V_58 = - V_16 ;
V_13 = ( char * ) F_92 ( V_24 ) ;
if ( ! V_13 )
goto V_18;
V_58 = F_101 ( & V_153 , & V_152 , & V_154 ) ;
if ( V_58 )
goto V_18;
for ( V_124 = 0 ; V_124 < V_153 ; V_124 ++ ) {
V_58 = - V_16 ;
V_141 = F_102 ( V_148 , V_152 [ V_124 ] ) ;
if ( ! V_141 )
goto V_18;
V_58 = - V_16 ;
V_31 = F_88 ( V_148 -> V_155 , V_156 | V_157 | V_158 ) ;
if ( ! V_31 )
goto V_18;
V_58 = - V_159 ;
V_57 = snprintf ( V_13 , V_15 , L_17 , V_160 , V_152 [ V_124 ] ) ;
if ( V_57 >= V_15 )
goto V_18;
V_151 = (struct V_150 * ) V_31 -> V_161 ;
V_58 = F_103 ( L_18 , V_13 , V_162 , & V_81 ) ;
if ( V_58 ) {
F_59 ( L_19 ,
V_13 ) ;
V_81 = V_19 ;
}
V_151 -> V_81 = V_81 ;
V_151 -> V_163 = V_164 ;
V_31 -> V_165 = & V_166 ;
V_31 -> V_28 = V_124 | V_167 ;
F_104 ( V_141 , V_31 ) ;
}
V_143 = V_153 ;
V_144 = V_152 ;
V_145 = V_154 ;
F_94 ( ( unsigned long ) V_13 ) ;
return 0 ;
V_18:
F_94 ( ( unsigned long ) V_13 ) ;
if ( V_152 ) {
for ( V_124 = 0 ; V_124 < V_153 ; V_124 ++ )
F_19 ( V_152 [ V_124 ] ) ;
F_19 ( V_152 ) ;
}
F_19 ( V_154 ) ;
F_98 ( V_148 ) ;
return V_58 ;
}
static T_2 F_105 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char V_9 [ V_10 ] ;
T_2 V_11 ;
V_11 = F_4 ( V_9 , V_10 , L_4 , V_168 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static T_2 F_106 ( struct V_4 * V_4 ,
const char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 ;
T_2 V_58 ;
unsigned int V_14 ;
V_58 = F_10 ( F_11 () , V_19 ,
V_20 , V_169 ,
NULL ) ;
if ( V_58 )
return V_58 ;
if ( V_7 >= V_15 )
return - V_16 ;
if ( * V_8 != 0 )
return - V_17 ;
V_13 = F_7 ( V_6 , V_7 ) ;
if ( F_8 ( V_13 ) )
return F_9 ( V_13 ) ;
V_58 = - V_17 ;
if ( sscanf ( V_13 , L_4 , & V_14 ) != 1 )
goto V_18;
V_168 = V_14 ;
V_58 = V_7 ;
V_18:
F_19 ( V_13 ) ;
return V_58 ;
}
static T_2 F_107 ( struct V_4 * V_5 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_13 ;
T_2 V_11 ;
V_13 = ( char * ) F_108 ( V_24 ) ;
if ( ! V_13 )
return - V_16 ;
V_11 = F_109 ( V_13 ) ;
if ( V_11 >= 0 )
V_11 = F_5 ( V_6 , V_7 , V_8 , V_13 , V_11 ) ;
F_94 ( ( unsigned long ) V_13 ) ;
return V_11 ;
}
static struct V_170 * F_110 ( T_5 * V_171 )
{
int V_172 ;
for ( V_172 = * V_171 ; V_172 < V_173 ; ++ V_172 ) {
if ( ! F_111 ( V_172 ) )
continue;
* V_171 = V_172 + 1 ;
return & F_112 ( V_170 , V_172 ) ;
}
return NULL ;
}
static void * F_113 ( struct V_174 * V_175 , T_5 * V_97 )
{
T_5 V_176 = * V_97 - 1 ;
if ( * V_97 == 0 )
return V_177 ;
return F_110 ( & V_176 ) ;
}
static void * F_114 ( struct V_174 * V_175 , void * V_178 , T_5 * V_97 )
{
return F_110 ( V_97 ) ;
}
static int F_115 ( struct V_174 * V_175 , void * V_178 )
{
struct V_170 * V_179 = V_178 ;
if ( V_178 == V_177 )
F_116 ( V_175 , L_20
L_21 ) ;
else {
unsigned int V_180 = V_179 -> V_180 ;
unsigned int V_181 = V_179 -> V_181 ;
unsigned int V_182 = V_180 - V_181 ;
F_116 ( V_175 , L_22 , V_180 ,
V_182 , V_181 , V_179 -> V_183 ,
V_179 -> V_184 , V_179 -> V_185 ) ;
}
return 0 ;
}
static void F_117 ( struct V_174 * V_175 , void * V_178 )
{ }
static int F_118 ( struct V_31 * V_31 , struct V_4 * V_4 )
{
return F_119 ( V_4 , & V_186 ) ;
}
static int F_120 ( struct V_141 * V_148 )
{
int V_124 ;
static struct V_187 V_188 [] = {
{ L_23 ,
& V_189 , V_157 | V_158 } ,
{ L_24 , & V_190 , V_157 } ,
#ifdef F_121
{ L_25 , & V_191 , V_157 } ,
#endif
} ;
for ( V_124 = 0 ; V_124 < F_74 ( V_188 ) ; V_124 ++ ) {
struct V_31 * V_31 ;
struct V_141 * V_141 ;
V_141 = F_102 ( V_148 , V_188 [ V_124 ] . V_139 ) ;
if ( ! V_141 )
return - V_16 ;
V_31 = F_88 ( V_148 -> V_155 , V_156 | V_188 [ V_124 ] . V_130 ) ;
if ( ! V_31 )
return - V_16 ;
V_31 -> V_165 = V_188 [ V_124 ] . V_192 ;
V_31 -> V_28 = ++ V_193 ;
F_104 ( V_141 , V_31 ) ;
}
return 0 ;
}
static T_2 F_122 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
char * V_120 ;
T_7 V_81 , V_57 ;
T_2 V_58 ;
V_81 = F_21 ( V_4 ) -> V_28 & V_138 ;
V_58 = F_66 ( V_81 , & V_120 , & V_57 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_5 ( V_6 , V_7 , V_8 , V_120 , V_57 ) ;
F_19 ( V_120 ) ;
return V_58 ;
}
static int F_123 ( struct V_141 * V_148 )
{
int V_124 ;
for ( V_124 = 1 ; V_124 <= V_194 ; V_124 ++ ) {
struct V_31 * V_31 ;
struct V_141 * V_141 ;
V_141 = F_102 ( V_148 , F_124 ( V_124 ) ) ;
if ( ! V_141 )
return - V_16 ;
V_31 = F_88 ( V_148 -> V_155 , V_156 | V_157 ) ;
if ( ! V_31 )
return - V_16 ;
V_31 -> V_165 = & V_195 ;
V_31 -> V_28 = V_124 | V_196 ;
F_104 ( V_141 , V_31 ) ;
}
return 0 ;
}
static inline unsigned long F_125 ( T_8 V_197 )
{
return ( V_197 * ( V_198 + 1 ) ) | V_199 ;
}
static inline T_8 F_126 ( unsigned long V_27 )
{
return ( V_27 & V_138 ) / ( V_198 + 1 ) ;
}
static inline unsigned long F_127 ( T_8 V_197 , T_7 V_200 )
{
return ( V_197 * ( V_198 + 1 ) + V_200 ) | V_199 ;
}
static inline T_7 F_128 ( unsigned long V_27 )
{
return ( V_27 & V_138 ) % ( V_198 + 1 ) ;
}
static T_2 F_129 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
unsigned long V_27 = F_21 ( V_4 ) -> V_28 ;
char V_201 [ V_10 ] ;
T_2 V_57 = snprintf ( V_201 , sizeof( V_201 ) , L_1 , F_126 ( V_27 ) ) ;
return F_5 ( V_6 , V_7 , V_8 , V_201 , V_57 ) ;
}
static T_2 F_130 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
unsigned long V_27 = F_21 ( V_4 ) -> V_28 ;
char V_201 [ V_10 ] ;
T_2 V_57 = snprintf ( V_201 , sizeof( V_201 ) , L_1 , F_128 ( V_27 ) ) ;
return F_5 ( V_6 , V_7 , V_8 , V_201 , V_57 ) ;
}
static T_2 F_131 ( struct V_4 * V_4 , char T_3 * V_6 ,
T_4 V_7 , T_5 * V_8 )
{
int V_202 ;
char V_9 [ V_10 ] ;
T_2 V_11 ;
unsigned long V_28 = F_21 ( V_4 ) -> V_28 ;
V_202 = F_132 ( V_28 & V_138 ) ;
V_11 = F_4 ( V_9 , V_10 , L_1 , V_202 ) ;
return F_5 ( V_6 , V_7 , V_8 , V_9 , V_11 ) ;
}
static int F_133 ( char * V_203 , int V_204 ,
struct V_141 * V_148 )
{
int V_124 , V_50 , V_205 ;
char * * V_206 ;
V_50 = F_134 ( V_203 , & V_206 , & V_205 ) ;
if ( V_50 )
return V_50 ;
for ( V_124 = 0 ; V_124 < V_205 ; V_124 ++ ) {
struct V_31 * V_31 ;
struct V_141 * V_141 ;
V_50 = - V_16 ;
V_141 = F_102 ( V_148 , V_206 [ V_124 ] ) ;
if ( ! V_141 )
goto V_18;
V_50 = - V_16 ;
V_31 = F_88 ( V_148 -> V_155 , V_156 | V_157 ) ;
if ( ! V_31 )
goto V_18;
V_31 -> V_165 = & V_207 ;
V_31 -> V_28 = F_127 ( V_204 , V_124 + 1 ) ;
F_104 ( V_141 , V_31 ) ;
}
V_50 = 0 ;
V_18:
for ( V_124 = 0 ; V_124 < V_205 ; V_124 ++ )
F_19 ( V_206 [ V_124 ] ) ;
F_19 ( V_206 ) ;
return V_50 ;
}
static int F_135 ( char * V_208 , int V_137 ,
struct V_141 * V_148 )
{
struct V_141 * V_141 = NULL ;
struct V_31 * V_31 = NULL ;
int V_50 ;
V_141 = F_102 ( V_148 , L_26 ) ;
if ( ! V_141 )
return - V_16 ;
V_31 = F_88 ( V_148 -> V_155 , V_156 | V_157 ) ;
if ( ! V_31 )
return - V_16 ;
V_31 -> V_165 = & V_209 ;
V_31 -> V_28 = F_125 ( V_137 ) ;
F_104 ( V_141 , V_31 ) ;
V_141 = F_136 ( V_148 , L_27 , & V_210 ) ;
if ( F_8 ( V_141 ) )
return F_9 ( V_141 ) ;
V_50 = F_133 ( V_208 , V_137 , V_141 ) ;
return V_50 ;
}
static int F_62 ( void )
{
int V_50 , V_211 , V_124 ;
char * * V_212 ;
F_98 ( V_213 ) ;
V_50 = F_137 ( & V_212 , & V_211 ) ;
if ( V_50 )
return V_50 ;
V_210 = F_125 ( V_211 + 2 ) ;
for ( V_124 = 0 ; V_124 < V_211 ; V_124 ++ ) {
struct V_141 * V_214 ;
V_214 = F_136 ( V_213 , V_212 [ V_124 ] ,
& V_210 ) ;
if ( F_8 ( V_214 ) ) {
V_50 = F_9 ( V_214 ) ;
goto V_18;
}
V_50 = F_135 ( V_212 [ V_124 ] , V_124 + 1 ,
V_214 ) ;
if ( V_50 )
goto V_18;
}
V_50 = 0 ;
V_18:
for ( V_124 = 0 ; V_124 < V_211 ; V_124 ++ )
F_19 ( V_212 [ V_124 ] ) ;
F_19 ( V_212 ) ;
return V_50 ;
}
static int F_63 ( void )
{
unsigned int V_215 ;
struct V_141 * V_141 = NULL ;
struct V_31 * V_31 = NULL ;
F_98 ( V_216 ) ;
for ( V_215 = 0 ; V_215 <= V_217 ; V_215 ++ ) {
if ( V_215 < F_74 ( V_218 ) )
V_141 = F_102 ( V_216 ,
V_218 [ V_215 ] ) ;
else
V_141 = F_102 ( V_216 , L_28 ) ;
if ( V_141 == NULL )
return - V_16 ;
V_31 = F_88 ( V_216 -> V_155 , V_156 | V_157 ) ;
if ( V_31 == NULL )
return - V_16 ;
V_31 -> V_165 = & V_219 ;
V_31 -> V_28 = V_215 | V_220 ;
F_104 ( V_141 , V_31 ) ;
}
return 0 ;
}
static struct V_141 * F_136 ( struct V_141 * V_148 , const char * V_139 ,
unsigned long * V_27 )
{
struct V_141 * V_141 = F_102 ( V_148 , V_139 ) ;
struct V_31 * V_31 ;
if ( ! V_141 )
return F_138 ( - V_16 ) ;
V_31 = F_88 ( V_148 -> V_155 , V_221 | V_157 | V_222 ) ;
if ( ! V_31 ) {
F_139 ( V_141 ) ;
return F_138 ( - V_16 ) ;
}
V_31 -> V_223 = & V_224 ;
V_31 -> V_165 = & V_225 ;
V_31 -> V_28 = ++ ( * V_27 ) ;
F_140 ( V_31 ) ;
F_104 ( V_141 , V_31 ) ;
F_140 ( F_141 ( V_148 ) ) ;
return V_141 ;
}
static int F_142 ( struct V_128 * V_129 , void * V_56 , int V_226 )
{
int V_58 ;
struct V_141 * V_141 ;
struct V_31 * V_31 ;
struct V_150 * V_151 ;
static struct V_187 V_227 [] = {
[ V_228 ] = { L_29 , & V_229 , V_230 | V_158 } ,
[ V_231 ] = { L_30 , & V_232 , V_157 | V_158 } ,
[ V_233 ] = { L_31 , & V_234 , V_157 | V_235 } ,
[ V_236 ] = { L_32 , & V_234 , V_157 | V_235 } ,
[ V_237 ] = { L_33 , & V_234 , V_157 | V_235 } ,
[ V_238 ] = { L_34 , & V_234 , V_157 | V_235 } ,
[ V_239 ] = { L_35 , & V_234 , V_157 | V_235 } ,
[ V_240 ] = { L_36 , & V_241 , V_157 } ,
[ V_242 ] = { L_37 , & V_243 , V_158 } ,
[ V_244 ] = { L_38 , & V_245 , V_157 } ,
[ V_246 ] = { L_39 , & V_247 , V_158 } ,
[ V_248 ] = { L_40 , & V_234 , V_157 | V_235 } ,
[ V_249 ] = { L_41 , & V_250 , V_157 | V_158 } ,
[ V_30 ] = { L_42 , & V_251 , V_157 } ,
[ V_252 ] = { L_43 , & V_251 , V_157 } ,
[ V_253 ] = { L_44 , & V_254 , V_157 } ,
[ V_255 ] = { L_45 , & V_256 , V_157 } ,
[ V_257 ] = { L_46 , & V_258 ,
V_235 } ,
{ L_47 }
} ;
V_58 = F_143 ( V_129 , V_259 , V_227 ) ;
if ( V_58 )
goto V_53;
V_149 = F_136 ( V_129 -> V_260 , V_160 , & V_193 ) ;
if ( F_8 ( V_149 ) ) {
V_58 = F_9 ( V_149 ) ;
V_149 = NULL ;
goto V_53;
}
V_58 = - V_16 ;
V_141 = F_102 ( V_129 -> V_260 , V_261 ) ;
if ( ! V_141 )
goto V_53;
V_58 = - V_16 ;
V_31 = F_88 ( V_129 , V_262 | V_157 | V_235 ) ;
if ( ! V_31 )
goto V_53;
V_31 -> V_28 = ++ V_193 ;
V_151 = (struct V_150 * ) V_31 -> V_161 ;
V_151 -> V_81 = V_263 ;
V_151 -> V_264 = V_265 ;
V_151 -> V_163 = V_164 ;
F_144 ( V_31 , V_262 | V_157 | V_235 , F_145 ( V_266 , 3 ) ) ;
F_104 ( V_141 , V_31 ) ;
V_267 . V_141 = V_141 ;
V_141 = F_136 ( V_129 -> V_260 , L_48 , & V_193 ) ;
if ( F_8 ( V_141 ) ) {
V_58 = F_9 ( V_141 ) ;
goto V_53;
}
V_58 = F_120 ( V_141 ) ;
if ( V_58 )
goto V_53;
V_141 = F_136 ( V_129 -> V_260 , L_49 , & V_193 ) ;
if ( F_8 ( V_141 ) ) {
V_58 = F_9 ( V_141 ) ;
goto V_53;
}
V_58 = F_123 ( V_141 ) ;
if ( V_58 )
goto V_53;
V_213 = F_136 ( V_129 -> V_260 , L_50 , & V_193 ) ;
if ( F_8 ( V_213 ) ) {
V_58 = F_9 ( V_213 ) ;
V_213 = NULL ;
goto V_53;
}
V_216 = F_136 ( V_129 -> V_260 , L_51 , & V_193 ) ;
if ( F_8 ( V_216 ) ) {
V_58 = F_9 ( V_216 ) ;
V_216 = NULL ;
goto V_53;
}
return 0 ;
V_53:
F_67 ( V_85 L_52 ,
V_86 ) ;
return V_58 ;
}
static struct V_141 * F_146 ( struct V_268 * V_269 ,
int V_63 , const char * V_270 , void * V_56 )
{
return F_147 ( V_269 , V_63 , V_56 , F_142 ) ;
}
static int T_1 F_148 ( void )
{
int V_53 ;
if ( ! V_271 )
return 0 ;
V_53 = F_149 ( V_272 , L_53 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_150 ( & V_273 ) ;
if ( V_53 ) {
F_151 ( V_272 , L_53 ) ;
return V_53 ;
}
V_267 . V_274 = V_275 = F_152 ( & V_273 ) ;
if ( F_8 ( V_275 ) ) {
F_67 ( V_85 L_54 ) ;
V_53 = F_9 ( V_275 ) ;
V_275 = NULL ;
}
return V_53 ;
}
void F_153 ( void )
{
F_151 ( V_272 , L_53 ) ;
F_154 ( V_275 ) ;
F_155 ( & V_273 ) ;
}
