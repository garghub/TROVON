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
V_21 = - V_25 ;
if ( V_17 >= V_26 )
goto V_27;
V_21 = V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_21 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_21 = - V_30 ;
if ( F_13 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_27;
if ( V_24 != V_22 ) {
V_21 = F_3 ( V_31 , V_32 ) ;
if ( V_21 )
goto V_27;
F_14 ( V_31 -> V_33 , V_29 , V_34 ,
L_2 ,
V_24 , V_22 ,
F_15 ( V_31 ) ,
F_16 ( V_31 ) ) ;
V_22 = V_24 ;
if ( V_22 )
F_17 ( 0 ) ;
F_18 ( V_22 ) ;
F_19 ( V_22 ) ;
}
V_21 = V_17 ;
V_27:
F_20 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_21 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
T_7 V_35 = V_15 -> V_36 . V_37 -> V_38 -> V_39 ;
int V_40 = ( V_35 == V_41 ) ?
F_22 () : ! F_23 () ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_40 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_24 ( struct V_42 * V_42 , struct V_14 * V_15 )
{
struct V_23 * V_43 = F_25 () ;
if ( ! V_43 )
return - V_25 ;
V_15 -> V_44 = V_43 ;
return 0 ;
}
static T_3 F_26 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
struct V_23 * V_43 = V_15 -> V_44 ;
F_27 ( ! V_43 ) ;
return F_10 ( V_16 , V_17 , V_18 ,
F_28 ( V_43 ) ,
sizeof( struct V_45 ) ) ;
}
static int F_29 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
struct V_23 * V_43 = V_15 -> V_44 ;
unsigned long V_48 = V_47 -> V_49 - V_47 -> V_50 ;
F_27 ( ! V_43 ) ;
if ( V_47 -> V_51 > 0 || V_48 != V_26 )
return - V_52 ;
if ( V_47 -> V_53 & V_54 )
return - V_55 ;
V_47 -> V_53 &= ~ V_56 ;
return F_30 ( V_47 , V_47 -> V_50 ,
F_31 ( V_43 ) ,
V_48 , V_47 -> V_57 ) ;
}
static T_3 F_32 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
V_21 = - V_25 ;
if ( V_17 >= V_26 )
goto V_27;
V_21 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_21 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_21 = - V_30 ;
if ( F_13 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_27;
if ( V_24 ) {
V_21 = F_33 () ;
if ( V_21 )
goto V_27;
F_14 ( V_31 -> V_33 , V_29 , V_34 ,
L_3 ,
F_15 ( V_31 ) ,
F_16 ( V_31 ) ) ;
}
V_21 = V_17 ;
V_27:
F_20 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_34 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_58 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_35 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_1 ,
F_36 () ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_37 ( struct V_42 * V_42 , struct V_14 * V_15 )
{
struct V_59 * V_60 = NULL ;
int V_61 ;
F_27 ( V_15 -> V_44 ) ;
F_38 ( & V_62 ) ;
V_61 = F_3 ( V_31 , V_63 ) ;
if ( V_61 )
goto V_64;
V_61 = - V_65 ;
if ( V_66 )
goto V_64;
V_61 = - V_25 ;
V_60 = F_39 ( sizeof( * V_60 ) , V_29 ) ;
if ( ! V_60 )
goto V_64;
if ( F_40 ( V_42 ) != F_41 () ) {
F_38 ( & V_42 -> V_67 ) ;
F_42 ( V_42 , F_41 () ) ;
F_43 ( & V_42 -> V_67 ) ;
}
V_61 = F_44 ( & V_60 -> V_68 , & V_60 -> V_69 ) ;
if ( V_61 )
goto V_64;
V_66 = 1 ;
V_15 -> V_44 = V_60 ;
F_43 ( & V_62 ) ;
return 0 ;
V_64:
F_43 ( & V_62 ) ;
if ( V_60 )
F_45 ( V_60 -> V_68 ) ;
F_46 ( V_60 ) ;
return V_61 ;
}
static int F_47 ( struct V_42 * V_42 , struct V_14 * V_15 )
{
struct V_59 * V_60 = V_15 -> V_44 ;
F_27 ( ! V_60 ) ;
V_66 = 0 ;
F_45 ( V_60 -> V_68 ) ;
F_46 ( V_60 ) ;
return 0 ;
}
static T_3 F_48 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
struct V_59 * V_60 = V_15 -> V_44 ;
int V_70 ;
F_38 ( & V_62 ) ;
V_70 = F_3 ( V_31 , V_63 ) ;
if ( V_70 )
goto V_27;
V_70 = F_10 ( V_16 , V_17 , V_18 , V_60 -> V_68 , V_60 -> V_69 ) ;
V_27:
F_43 ( & V_62 ) ;
return V_70 ;
}
static int F_49 ( struct V_46 * V_47 ,
struct V_71 * V_72 )
{
struct V_59 * V_60 = V_47 -> V_73 -> V_44 ;
unsigned long V_74 ;
struct V_23 * V_23 ;
if ( V_72 -> V_75 & ( V_76 | V_77 ) )
return V_78 ;
V_74 = V_72 -> V_79 << V_80 ;
if ( V_74 >= F_50 ( V_60 -> V_69 , V_26 ) )
return V_78 ;
V_23 = F_51 ( V_60 -> V_68 + V_74 ) ;
F_52 ( V_23 ) ;
V_72 -> V_23 = V_23 ;
return 0 ;
}
static int F_53 ( struct V_14 * V_15 , struct V_46 * V_47 )
{
if ( V_47 -> V_53 & V_81 ) {
V_47 -> V_53 &= ~ V_56 ;
if ( V_47 -> V_53 & V_54 )
return - V_11 ;
}
V_47 -> V_53 |= V_82 ;
V_47 -> V_83 = & V_84 ;
return 0 ;
}
static T_3 F_54 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
T_3 V_21 ;
void * V_68 = NULL ;
F_38 ( & V_62 ) ;
V_21 = F_3 ( V_31 , V_85 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_21 = - V_86 ;
if ( V_17 > 64 * 1024 * 1024 )
goto V_27;
V_21 = - V_25 ;
V_68 = F_55 ( V_17 ) ;
if ( ! V_68 )
goto V_27;
V_21 = - V_30 ;
if ( F_13 ( V_68 , V_16 , V_17 ) != 0 )
goto V_27;
V_21 = F_56 ( V_68 , V_17 ) ;
if ( V_21 )
goto V_27;
V_21 = F_57 () ;
if ( V_21 )
goto V_87;
V_21 = F_58 () ;
if ( V_21 )
goto V_87;
V_21 = F_59 () ;
if ( V_21 )
goto V_87;
V_21 = V_17 ;
V_87:
F_14 ( V_31 -> V_33 , V_29 , V_88 ,
L_5 ,
F_15 ( V_31 ) ,
F_16 ( V_31 ) ) ;
V_27:
F_43 ( & V_62 ) ;
F_45 ( V_68 ) ;
return V_21 ;
}
static T_3 F_60 ( struct V_14 * V_14 , char * V_16 , T_5 V_48 )
{
char * V_89 = NULL ;
T_2 V_9 , V_69 ;
T_3 V_21 ;
V_21 = F_3 ( V_31 , V_90 ) ;
if ( V_21 )
goto V_27;
V_21 = F_61 ( V_16 , V_48 , & V_9 ) ;
if ( V_21 )
goto V_27;
V_21 = F_62 ( V_9 , & V_89 , & V_69 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_91 ;
if ( V_69 > V_92 ) {
F_63 ( V_93 L_6
L_7 , V_94 , V_69 ) ;
goto V_27;
}
memcpy ( V_16 , V_89 , V_69 ) ;
V_21 = V_69 ;
V_27:
F_46 ( V_89 ) ;
return V_21 ;
}
static T_3 F_64 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_3 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_65 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
unsigned int V_24 ;
V_21 = F_3 ( V_31 , V_95 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
if ( V_17 >= V_26 )
goto V_27;
V_21 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_21 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_21 = - V_30 ;
if ( F_13 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_23 , L_4 , & V_24 ) != 1 )
goto V_27;
V_3 = V_24 ? 1 : 0 ;
V_21 = V_17 ;
V_27:
F_20 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_66 ( struct V_14 * V_14 , const char T_4 * V_16 , T_5 V_48 , T_6 * V_96 )
{
T_7 V_35 = V_14 -> V_36 . V_37 -> V_38 -> V_39 ;
char * V_68 ;
T_3 V_97 ;
if ( V_35 >= F_67 ( V_98 ) || ! V_98 [ V_35 ] )
return - V_28 ;
V_68 = F_68 ( V_14 , V_16 , V_48 ) ;
if ( F_69 ( V_68 ) )
return F_70 ( V_68 ) ;
V_97 = V_98 [ V_35 ] ( V_14 , V_68 , V_48 ) ;
if ( V_97 > 0 ) {
F_71 ( V_14 , V_97 ) ;
V_97 = V_48 ;
}
return V_97 ;
}
static T_3 F_72 ( struct V_14 * V_14 , char * V_16 , T_5 V_48 )
{
char * V_99 = NULL , * V_100 = NULL ;
T_2 V_101 , V_102 ;
T_8 V_103 ;
struct V_104 V_105 ;
T_3 V_21 ;
V_21 = F_3 ( V_31 , V_106 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_25 ;
V_100 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_100 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_8 , V_99 , V_100 , & V_103 ) != 3 )
goto V_27;
V_21 = F_61 ( V_99 , strlen ( V_99 ) + 1 , & V_101 ) ;
if ( V_21 )
goto V_27;
V_21 = F_61 ( V_100 , strlen ( V_100 ) + 1 , & V_102 ) ;
if ( V_21 )
goto V_27;
F_73 ( V_101 , V_102 , V_103 , & V_105 ) ;
V_21 = F_9 ( V_16 , V_92 ,
L_9 ,
V_105 . V_107 , 0xffffffff ,
V_105 . V_108 , V_105 . V_109 ,
V_105 . V_110 , V_105 . V_75 ) ;
V_27:
F_46 ( V_100 ) ;
F_46 ( V_99 ) ;
return V_21 ;
}
static T_3 F_74 ( struct V_14 * V_14 , char * V_16 , T_5 V_48 )
{
char * V_99 = NULL , * V_100 = NULL ;
char * V_111 = NULL , * V_112 = NULL ;
T_2 V_101 , V_102 , V_113 ;
T_8 V_103 ;
T_3 V_21 ;
char * V_114 = NULL ;
T_2 V_69 ;
int V_115 ;
V_21 = F_3 ( V_31 , V_116 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_25 ;
V_100 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_100 )
goto V_27;
V_21 = - V_25 ;
V_111 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_111 )
goto V_27;
V_21 = - V_28 ;
V_115 = sscanf ( V_16 , L_10 , V_99 , V_100 , & V_103 , V_111 ) ;
if ( V_115 < 3 || V_115 > 4 )
goto V_27;
if ( V_115 == 4 ) {
char * V_117 , * V_118 ;
int V_119 , V_120 ;
V_117 = V_118 = V_111 ;
do {
V_119 = * V_117 ++ ;
if ( V_119 == '+' )
V_119 = ' ' ;
else if ( V_119 == '%' ) {
V_119 = F_75 ( * V_117 ++ ) ;
if ( V_119 < 0 )
goto V_27;
V_120 = F_75 ( * V_117 ++ ) ;
if ( V_120 < 0 )
goto V_27;
V_119 = ( V_119 << 4 ) | V_120 ;
}
* V_118 ++ = V_119 ;
} while ( V_119 != '\0' );
V_112 = V_111 ;
}
V_21 = F_61 ( V_99 , strlen ( V_99 ) + 1 , & V_101 ) ;
if ( V_21 )
goto V_27;
V_21 = F_61 ( V_100 , strlen ( V_100 ) + 1 , & V_102 ) ;
if ( V_21 )
goto V_27;
V_21 = F_76 ( V_101 , V_102 , V_103 ,
V_112 , & V_113 ) ;
if ( V_21 )
goto V_27;
V_21 = F_62 ( V_113 , & V_114 , & V_69 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_91 ;
if ( V_69 > V_92 ) {
F_63 ( V_93 L_6
L_7 , V_94 , V_69 ) ;
goto V_27;
}
memcpy ( V_16 , V_114 , V_69 ) ;
V_21 = V_69 ;
V_27:
F_46 ( V_114 ) ;
F_46 ( V_111 ) ;
F_46 ( V_100 ) ;
F_46 ( V_99 ) ;
return V_21 ;
}
static T_3 F_77 ( struct V_14 * V_14 , char * V_16 , T_5 V_48 )
{
char * V_99 = NULL , * V_100 = NULL ;
T_2 V_101 , V_102 , V_113 ;
T_8 V_103 ;
T_3 V_21 ;
char * V_114 = NULL ;
T_2 V_69 ;
V_21 = F_3 ( V_31 , V_121 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_25 ;
V_100 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_100 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_8 , V_99 , V_100 , & V_103 ) != 3 )
goto V_27;
V_21 = F_61 ( V_99 , strlen ( V_99 ) + 1 , & V_101 ) ;
if ( V_21 )
goto V_27;
V_21 = F_61 ( V_100 , strlen ( V_100 ) + 1 , & V_102 ) ;
if ( V_21 )
goto V_27;
V_21 = F_78 ( V_101 , V_102 , V_103 , & V_113 ) ;
if ( V_21 )
goto V_27;
V_21 = F_62 ( V_113 , & V_114 , & V_69 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_91 ;
if ( V_69 > V_92 )
goto V_27;
memcpy ( V_16 , V_114 , V_69 ) ;
V_21 = V_69 ;
V_27:
F_46 ( V_114 ) ;
F_46 ( V_100 ) ;
F_46 ( V_99 ) ;
return V_21 ;
}
static T_3 F_79 ( struct V_14 * V_14 , char * V_16 , T_5 V_48 )
{
char * V_122 = NULL , * V_123 = NULL , * V_124 ;
T_2 V_9 , * V_125 = NULL ;
T_3 V_21 ;
char * V_114 ;
int V_126 , V_61 ;
T_2 V_69 , V_127 ;
V_21 = F_3 ( V_31 , V_128 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_122 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_122 )
goto V_27;
V_21 = - V_25 ;
V_123 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_123 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_11 , V_122 , V_123 ) != 2 )
goto V_27;
V_21 = F_61 ( V_122 , strlen ( V_122 ) + 1 , & V_9 ) ;
if ( V_21 )
goto V_27;
V_21 = F_80 ( V_9 , V_123 , & V_125 , & V_127 ) ;
if ( V_21 )
goto V_27;
V_21 = sprintf ( V_16 , L_4 , V_127 ) + 1 ;
V_124 = V_16 + V_21 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
V_61 = F_62 ( V_125 [ V_126 ] , & V_114 , & V_69 ) ;
if ( V_61 ) {
V_21 = V_61 ;
goto V_27;
}
if ( ( V_21 + V_69 ) >= V_92 ) {
F_46 ( V_114 ) ;
V_21 = - V_91 ;
goto V_27;
}
memcpy ( V_124 , V_114 , V_69 ) ;
F_46 ( V_114 ) ;
V_124 += V_69 ;
V_21 += V_69 ;
}
V_27:
F_46 ( V_125 ) ;
F_46 ( V_123 ) ;
F_46 ( V_122 ) ;
return V_21 ;
}
static T_3 F_81 ( struct V_14 * V_14 , char * V_16 , T_5 V_48 )
{
char * V_99 = NULL , * V_100 = NULL ;
T_2 V_101 , V_102 , V_113 ;
T_8 V_103 ;
T_3 V_21 ;
char * V_114 = NULL ;
T_2 V_69 ;
V_21 = F_3 ( V_31 , V_129 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_25 ;
V_100 = F_39 ( V_48 + 1 , V_29 ) ;
if ( ! V_100 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_8 , V_99 , V_100 , & V_103 ) != 3 )
goto V_27;
V_21 = F_61 ( V_99 , strlen ( V_99 ) + 1 , & V_101 ) ;
if ( V_21 )
goto V_27;
V_21 = F_61 ( V_100 , strlen ( V_100 ) + 1 , & V_102 ) ;
if ( V_21 )
goto V_27;
V_21 = F_82 ( V_101 , V_102 , V_103 , & V_113 ) ;
if ( V_21 )
goto V_27;
V_21 = F_62 ( V_113 , & V_114 , & V_69 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_91 ;
if ( V_69 > V_92 ) {
F_63 ( V_93 L_6
L_7 , V_94 , V_69 ) ;
goto V_27;
}
memcpy ( V_16 , V_114 , V_69 ) ;
V_21 = V_69 ;
V_27:
F_46 ( V_114 ) ;
F_46 ( V_100 ) ;
F_46 ( V_99 ) ;
return V_21 ;
}
static struct V_42 * F_83 ( struct V_130 * V_131 , int V_132 )
{
struct V_42 * V_70 = F_84 ( V_131 ) ;
if ( V_70 ) {
V_70 -> V_133 = V_132 ;
V_70 -> V_134 = V_70 -> V_135 = V_70 -> V_136 = V_137 ;
}
return V_70 ;
}
static T_3 F_85 ( struct V_14 * V_138 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
T_3 V_70 ;
int V_139 ;
struct V_42 * V_42 = V_138 -> V_36 . V_37 -> V_38 ;
unsigned V_140 = V_42 -> V_39 & V_141 ;
const char * V_142 = V_138 -> V_36 . V_37 -> V_143 . V_142 ;
F_38 ( & V_62 ) ;
V_70 = - V_28 ;
if ( V_140 >= V_144 || strcmp ( V_142 , V_145 [ V_140 ] ) )
goto V_27;
V_70 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_139 = F_86 ( V_140 ) ;
if ( V_139 < 0 ) {
V_70 = V_139 ;
goto V_27;
}
V_21 = F_9 ( V_23 , V_26 , L_12 , V_139 ,
V_146 [ V_140 ] ) ;
V_70 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
V_27:
F_43 ( & V_62 ) ;
F_20 ( ( unsigned long ) V_23 ) ;
return V_70 ;
}
static T_3 F_87 ( struct V_14 * V_138 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
struct V_42 * V_42 = V_138 -> V_36 . V_37 -> V_38 ;
unsigned V_140 = V_42 -> V_39 & V_141 ;
const char * V_142 = V_138 -> V_36 . V_37 -> V_143 . V_142 ;
F_38 ( & V_62 ) ;
V_21 = F_3 ( V_31 , V_147 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_28 ;
if ( V_140 >= V_144 || strcmp ( V_142 , V_145 [ V_140 ] ) )
goto V_27;
V_21 = - V_25 ;
if ( V_17 >= V_26 )
goto V_27;
V_21 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_21 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_21 = - V_30 ;
if ( F_13 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_27;
if ( V_24 )
V_24 = 1 ;
V_146 [ V_140 ] = V_24 ;
V_21 = V_17 ;
V_27:
F_43 ( & V_62 ) ;
F_20 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_88 ( struct V_14 * V_138 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
F_38 ( & V_62 ) ;
V_21 = F_3 ( V_31 , V_147 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
if ( V_17 >= V_26 )
goto V_27;
V_21 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_21 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_21 = - V_30 ;
if ( F_13 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_23 , L_1 , & V_24 ) != 1 )
goto V_27;
V_21 = 0 ;
if ( V_24 && V_146 )
V_21 = F_89 ( V_144 , V_146 ) ;
if ( ! V_21 )
V_21 = V_17 ;
V_27:
F_43 ( & V_62 ) ;
F_20 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static void F_90 ( struct V_37 * V_148 )
{
struct V_149 * V_150 ;
F_91 ( & V_148 -> V_151 ) ;
V_150 = V_148 -> V_152 . V_153 ;
while ( V_150 != & V_148 -> V_152 ) {
struct V_37 * V_154 = F_92 ( V_150 , struct V_37 , V_155 . V_156 ) ;
F_93 ( & V_154 -> V_151 , V_157 ) ;
F_94 ( V_150 ) ;
if ( V_154 -> V_38 ) {
F_95 ( V_154 ) ;
F_96 ( & V_148 -> V_151 ) ;
F_96 ( & V_154 -> V_151 ) ;
F_97 ( V_154 ) ;
F_98 ( V_148 -> V_38 , V_154 ) ;
F_99 ( V_154 ) ;
F_91 ( & V_148 -> V_151 ) ;
} else
F_96 ( & V_154 -> V_151 ) ;
V_150 = V_148 -> V_152 . V_153 ;
}
F_96 ( & V_148 -> V_151 ) ;
}
static int F_57 ( void )
{
int V_126 , V_70 ;
T_3 V_69 ;
struct V_37 * V_37 = NULL ;
struct V_37 * V_158 = V_159 ;
struct V_42 * V_42 = NULL ;
struct V_160 * V_161 ;
char * * V_162 = NULL , * V_23 ;
int V_163 ;
int * V_164 = NULL ;
T_2 V_9 ;
for ( V_126 = 0 ; V_126 < V_144 ; V_126 ++ )
F_46 ( V_145 [ V_126 ] ) ;
F_46 ( V_145 ) ;
F_46 ( V_146 ) ;
V_145 = NULL ;
V_146 = NULL ;
F_90 ( V_158 ) ;
V_70 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_70 = F_100 ( & V_163 , & V_162 , & V_164 ) ;
if ( V_70 )
goto V_27;
for ( V_126 = 0 ; V_126 < V_163 ; V_126 ++ ) {
V_70 = - V_25 ;
V_37 = F_101 ( V_158 , V_162 [ V_126 ] ) ;
if ( ! V_37 )
goto V_27;
V_70 = - V_25 ;
V_42 = F_83 ( V_158 -> V_165 , V_166 | V_167 | V_168 ) ;
if ( ! V_42 )
goto V_27;
V_70 = - V_28 ;
V_69 = snprintf ( V_23 , V_26 , L_13 , V_169 , V_162 [ V_126 ] ) ;
if ( V_69 < 0 )
goto V_27;
V_70 = - V_170 ;
if ( V_69 >= V_26 )
goto V_27;
V_161 = (struct V_160 * ) V_42 -> V_171 ;
V_70 = F_102 ( L_14 , V_23 , V_172 , & V_9 ) ;
if ( V_70 )
goto V_27;
V_161 -> V_9 = V_9 ;
V_161 -> V_173 = 1 ;
V_42 -> V_174 = & V_175 ;
V_42 -> V_39 = V_126 | V_176 ;
F_103 ( V_37 , V_42 ) ;
}
V_144 = V_163 ;
V_145 = V_162 ;
V_146 = V_164 ;
F_20 ( ( unsigned long ) V_23 ) ;
return 0 ;
V_27:
F_20 ( ( unsigned long ) V_23 ) ;
if ( V_162 ) {
for ( V_126 = 0 ; V_126 < V_163 ; V_126 ++ )
F_46 ( V_162 [ V_126 ] ) ;
F_46 ( V_162 ) ;
}
F_46 ( V_164 ) ;
F_90 ( V_158 ) ;
return V_70 ;
}
static T_3 F_104 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_177 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_105 ( struct V_14 * V_14 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_70 ;
int V_24 ;
V_70 = F_3 ( V_31 , V_178 ) ;
if ( V_70 )
goto V_27;
V_70 = - V_25 ;
if ( V_17 >= V_26 )
goto V_27;
V_70 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_70 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_70 = - V_30 ;
if ( F_13 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_70 = - V_28 ;
if ( sscanf ( V_23 , L_4 , & V_24 ) != 1 )
goto V_27;
V_177 = V_24 ;
V_70 = V_17 ;
V_27:
F_20 ( ( unsigned long ) V_23 ) ;
return V_70 ;
}
static T_3 F_106 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_21 ;
V_23 = ( char * ) F_107 ( V_29 ) ;
if ( ! V_23 )
return - V_25 ;
V_21 = F_108 ( V_23 ) ;
if ( V_21 >= 0 )
V_21 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
F_20 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static struct V_179 * F_109 ( T_6 * V_180 )
{
int V_181 ;
for ( V_181 = * V_180 ; V_181 < V_182 ; ++ V_181 ) {
if ( ! F_110 ( V_181 ) )
continue;
* V_180 = V_181 + 1 ;
return & F_111 ( V_179 , V_181 ) ;
}
return NULL ;
}
static void * F_112 ( struct V_183 * V_184 , T_6 * V_96 )
{
T_6 V_185 = * V_96 - 1 ;
if ( * V_96 == 0 )
return V_186 ;
return F_109 ( & V_185 ) ;
}
static void * F_113 ( struct V_183 * V_184 , void * V_187 , T_6 * V_96 )
{
return F_109 ( V_96 ) ;
}
static int F_114 ( struct V_183 * V_184 , void * V_187 )
{
struct V_179 * V_188 = V_187 ;
if ( V_187 == V_186 )
F_115 ( V_184 , L_15
L_16 ) ;
else {
unsigned int V_189 = V_188 -> V_189 ;
unsigned int V_190 = V_188 -> V_190 ;
unsigned int V_191 = V_189 - V_190 ;
F_115 ( V_184 , L_17 , V_189 ,
V_191 , V_190 , V_188 -> V_192 ,
V_188 -> V_193 , V_188 -> V_194 ) ;
}
return 0 ;
}
static void F_116 ( struct V_183 * V_184 , void * V_187 )
{ }
static int F_117 ( struct V_42 * V_42 , struct V_14 * V_14 )
{
return F_118 ( V_14 , & V_195 ) ;
}
static int F_119 ( struct V_37 * V_158 )
{
int V_126 ;
static struct V_196 V_197 [] = {
{ L_18 ,
& V_198 , V_167 | V_168 } ,
{ L_19 , & V_199 , V_167 } ,
#ifdef F_120
{ L_20 , & V_200 , V_167 } ,
#endif
} ;
for ( V_126 = 0 ; V_126 < F_67 ( V_197 ) ; V_126 ++ ) {
struct V_42 * V_42 ;
struct V_37 * V_37 ;
V_37 = F_101 ( V_158 , V_197 [ V_126 ] . V_142 ) ;
if ( ! V_37 )
return - V_25 ;
V_42 = F_83 ( V_158 -> V_165 , V_166 | V_197 [ V_126 ] . V_132 ) ;
if ( ! V_42 )
return - V_25 ;
V_42 -> V_174 = V_197 [ V_126 ] . V_201 ;
V_42 -> V_39 = ++ V_202 ;
F_103 ( V_37 , V_42 ) ;
}
return 0 ;
}
static T_3 F_121 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
struct V_42 * V_42 ;
char * V_122 ;
T_2 V_9 , V_69 ;
T_3 V_70 ;
V_42 = V_14 -> V_36 . V_37 -> V_38 ;
V_9 = V_42 -> V_39 & V_141 ;
V_70 = F_62 ( V_9 , & V_122 , & V_69 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_10 ( V_16 , V_17 , V_18 , V_122 , V_69 ) ;
F_46 ( V_122 ) ;
return V_70 ;
}
static int F_122 ( struct V_37 * V_158 )
{
int V_126 ;
for ( V_126 = 1 ; V_126 <= V_203 ; V_126 ++ ) {
struct V_42 * V_42 ;
struct V_37 * V_37 ;
V_37 = F_101 ( V_158 , F_123 ( V_126 ) ) ;
if ( ! V_37 )
return - V_25 ;
V_42 = F_83 ( V_158 -> V_165 , V_166 | V_167 ) ;
if ( ! V_42 )
return - V_25 ;
V_42 -> V_174 = & V_204 ;
V_42 -> V_39 = V_126 | V_205 ;
F_103 ( V_37 , V_42 ) ;
}
return 0 ;
}
static inline unsigned int F_124 ( unsigned long V_206 , unsigned long V_207 )
{
return V_206 / V_207 - ( V_206 % V_207 < 0 ) ;
}
static inline unsigned long F_125 ( T_8 V_208 )
{
return ( V_208 * ( V_209 + 1 ) ) | V_210 ;
}
static inline T_8 F_126 ( unsigned long V_35 )
{
return F_124 ( V_35 & V_141 , V_209 + 1 ) ;
}
static inline unsigned long F_127 ( T_8 V_208 , T_2 V_211 )
{
return ( V_208 * ( V_209 + 1 ) + V_211 ) | V_210 ;
}
static inline T_2 F_128 ( unsigned long V_35 )
{
return ( V_35 & V_141 ) % ( V_209 + 1 ) ;
}
static T_3 F_129 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
T_3 V_61 , V_69 ;
char * V_23 ;
unsigned long V_35 = V_14 -> V_36 . V_37 -> V_38 -> V_39 ;
V_23 = ( char * ) F_107 ( V_29 ) ;
if ( ! V_23 )
return - V_25 ;
V_69 = snprintf ( V_23 , V_26 , L_1 , F_126 ( V_35 ) ) ;
V_61 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_69 ) ;
F_20 ( ( unsigned long ) V_23 ) ;
return V_61 ;
}
static T_3 F_130 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
T_3 V_61 , V_69 ;
char * V_23 ;
unsigned long V_35 = V_14 -> V_36 . V_37 -> V_38 -> V_39 ;
V_23 = ( char * ) F_107 ( V_29 ) ;
if ( ! V_23 )
return - V_25 ;
V_69 = snprintf ( V_23 , V_26 , L_1 , F_128 ( V_35 ) ) ;
V_61 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_69 ) ;
F_20 ( ( unsigned long ) V_23 ) ;
return V_61 ;
}
static T_3 F_131 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
int V_212 ;
char V_19 [ V_20 ] ;
T_3 V_21 ;
unsigned long V_39 = V_14 -> V_36 . V_37 -> V_38 -> V_39 ;
V_212 = F_132 ( V_39 & V_141 ) ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_212 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_133 ( char * V_213 , int V_214 ,
struct V_37 * V_158 )
{
int V_126 , V_61 , V_215 ;
char * * V_6 ;
V_61 = F_134 ( V_213 , & V_6 , & V_215 ) ;
if ( V_61 )
return V_61 ;
for ( V_126 = 0 ; V_126 < V_215 ; V_126 ++ ) {
struct V_42 * V_42 ;
struct V_37 * V_37 ;
V_61 = - V_25 ;
V_37 = F_101 ( V_158 , V_6 [ V_126 ] ) ;
if ( ! V_37 )
goto V_27;
V_61 = - V_25 ;
V_42 = F_83 ( V_158 -> V_165 , V_166 | V_167 ) ;
if ( ! V_42 )
goto V_27;
V_42 -> V_174 = & V_216 ;
V_42 -> V_39 = F_127 ( V_214 , V_126 + 1 ) ;
F_103 ( V_37 , V_42 ) ;
}
V_61 = 0 ;
V_27:
for ( V_126 = 0 ; V_126 < V_215 ; V_126 ++ )
F_46 ( V_6 [ V_126 ] ) ;
F_46 ( V_6 ) ;
return V_61 ;
}
static int F_135 ( char * V_217 , int V_140 ,
struct V_37 * V_158 )
{
struct V_37 * V_37 = NULL ;
struct V_42 * V_42 = NULL ;
int V_61 ;
V_37 = F_101 ( V_158 , L_21 ) ;
if ( ! V_37 )
return - V_25 ;
V_42 = F_83 ( V_158 -> V_165 , V_166 | V_167 ) ;
if ( ! V_42 )
return - V_25 ;
V_42 -> V_174 = & V_218 ;
V_42 -> V_39 = F_125 ( V_140 ) ;
F_103 ( V_37 , V_42 ) ;
V_37 = F_101 ( V_158 , L_22 ) ;
if ( ! V_37 )
return - V_25 ;
V_61 = F_136 ( V_158 -> V_38 , V_37 , & V_219 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_133 ( V_217 , V_140 , V_37 ) ;
return V_61 ;
}
static void F_137 ( void )
{
struct V_149 * V_220 ;
F_138 (class_node, &class_dir->d_subdirs) {
struct V_37 * V_221 = F_92 ( V_220 ,
struct V_37 , V_155 . V_156 ) ;
struct V_149 * V_222 ;
F_138 (class_subdir_node, &class_subdir->d_subdirs) {
struct V_37 * V_154 = F_92 ( V_222 ,
struct V_37 , V_155 . V_156 ) ;
if ( V_154 -> V_38 )
if ( V_154 -> V_38 -> V_133 & V_223 )
F_90 ( V_154 ) ;
}
F_90 ( V_221 ) ;
}
F_90 ( V_224 ) ;
}
static int F_58 ( void )
{
int V_61 , V_225 , V_126 ;
char * * V_226 ;
F_137 () ;
V_61 = F_139 ( & V_226 , & V_225 ) ;
if ( V_61 )
return V_61 ;
V_219 = F_125 ( V_225 + 2 ) ;
for ( V_126 = 0 ; V_126 < V_225 ; V_126 ++ ) {
struct V_37 * V_227 ;
V_61 = - V_25 ;
V_227 = F_101 ( V_224 , V_226 [ V_126 ] ) ;
if ( ! V_227 )
goto V_27;
V_61 = F_136 ( V_224 -> V_38 , V_227 ,
& V_219 ) ;
if ( V_61 )
goto V_27;
V_61 = F_135 ( V_226 [ V_126 ] , V_126 + 1 ,
V_227 ) ;
if ( V_61 )
goto V_27;
}
V_61 = 0 ;
V_27:
for ( V_126 = 0 ; V_126 < V_225 ; V_126 ++ )
F_46 ( V_226 [ V_126 ] ) ;
F_46 ( V_226 ) ;
return V_61 ;
}
static int F_59 ( void )
{
unsigned int V_228 ;
struct V_37 * V_37 = NULL ;
struct V_42 * V_42 = NULL ;
F_90 ( V_229 ) ;
for ( V_228 = 0 ; V_228 <= V_230 ; V_228 ++ ) {
if ( V_228 < F_67 ( V_231 ) )
V_37 = F_101 ( V_229 ,
V_231 [ V_228 ] ) ;
else
V_37 = F_101 ( V_229 , L_23 ) ;
if ( V_37 == NULL )
return - V_25 ;
V_42 = F_83 ( V_229 -> V_165 , V_166 | V_167 ) ;
if ( V_42 == NULL )
return - V_25 ;
V_42 -> V_174 = & V_232 ;
V_42 -> V_39 = V_228 | V_233 ;
F_103 ( V_37 , V_42 ) ;
}
return 0 ;
}
static int F_136 ( struct V_42 * V_158 , struct V_37 * V_37 ,
unsigned long * V_35 )
{
struct V_42 * V_42 ;
V_42 = F_83 ( V_158 -> V_234 , V_223 | V_167 | V_235 ) ;
if ( ! V_42 )
return - V_25 ;
V_42 -> V_236 = & V_237 ;
V_42 -> V_174 = & V_238 ;
V_42 -> V_39 = ++ ( * V_35 ) ;
F_140 ( V_42 ) ;
F_103 ( V_37 , V_42 ) ;
F_140 ( V_158 ) ;
return 0 ;
}
static int F_141 ( struct V_130 * V_131 , void * V_68 , int V_239 )
{
int V_70 ;
struct V_37 * V_37 ;
struct V_42 * V_42 , * V_240 ;
struct V_160 * V_161 ;
static struct V_196 V_241 [] = {
[ V_242 ] = { L_24 , & V_243 , V_244 | V_168 } ,
[ V_245 ] = { L_25 , & V_246 , V_167 | V_168 } ,
[ V_247 ] = { L_26 , & V_248 , V_167 | V_249 } ,
[ V_250 ] = { L_27 , & V_248 , V_167 | V_249 } ,
[ V_251 ] = { L_28 , & V_248 , V_167 | V_249 } ,
[ V_252 ] = { L_29 , & V_248 , V_167 | V_249 } ,
[ V_253 ] = { L_30 , & V_248 , V_167 | V_249 } ,
[ V_254 ] = { L_31 , & V_255 , V_167 } ,
[ V_256 ] = { L_32 , & V_257 , V_168 } ,
[ V_258 ] = { L_33 , & V_259 , V_167 } ,
[ V_260 ] = { L_34 , & V_261 , V_168 } ,
[ V_262 ] = { L_35 , & V_248 , V_167 | V_249 } ,
[ V_263 ] = { L_36 , & V_264 , V_167 | V_168 } ,
[ V_41 ] = { L_37 , & V_265 , V_167 } ,
[ V_266 ] = { L_38 , & V_265 , V_167 } ,
[ V_267 ] = { L_39 , & V_268 , V_167 } ,
[ V_269 ] = { L_40 , & V_270 , V_244 } ,
{ L_41 }
} ;
V_70 = F_142 ( V_131 , V_271 , V_241 ) ;
if ( V_70 )
goto V_64;
V_240 = V_131 -> V_272 -> V_38 ;
V_70 = - V_25 ;
V_37 = F_101 ( V_131 -> V_272 , V_169 ) ;
if ( ! V_37 )
goto V_64;
V_70 = F_136 ( V_240 , V_37 , & V_202 ) ;
if ( V_70 )
goto V_64;
V_159 = V_37 ;
V_70 = - V_25 ;
V_37 = F_101 ( V_131 -> V_272 , V_273 ) ;
if ( ! V_37 )
goto V_64;
V_70 = - V_25 ;
V_42 = F_83 ( V_131 , V_274 | V_167 | V_249 ) ;
if ( ! V_42 )
goto V_64;
V_42 -> V_39 = ++ V_202 ;
V_161 = (struct V_160 * ) V_42 -> V_171 ;
V_161 -> V_9 = V_275 ;
V_161 -> V_276 = V_277 ;
V_161 -> V_173 = 1 ;
F_143 ( V_42 , V_274 | V_167 | V_249 , F_144 ( V_278 , 3 ) ) ;
F_103 ( V_37 , V_42 ) ;
V_279 = V_37 ;
V_70 = - V_25 ;
V_37 = F_101 ( V_131 -> V_272 , L_42 ) ;
if ( ! V_37 )
goto V_64;
V_70 = F_136 ( V_240 , V_37 , & V_202 ) ;
if ( V_70 )
goto V_64;
V_70 = F_119 ( V_37 ) ;
if ( V_70 )
goto V_64;
V_70 = - V_25 ;
V_37 = F_101 ( V_131 -> V_272 , L_43 ) ;
if ( ! V_37 )
goto V_64;
V_70 = F_136 ( V_240 , V_37 , & V_202 ) ;
if ( V_70 )
goto V_64;
V_70 = F_122 ( V_37 ) ;
if ( V_70 )
goto V_64;
V_70 = - V_25 ;
V_37 = F_101 ( V_131 -> V_272 , L_44 ) ;
if ( ! V_37 )
goto V_64;
V_70 = F_136 ( V_240 , V_37 , & V_202 ) ;
if ( V_70 )
goto V_64;
V_224 = V_37 ;
V_70 = - V_25 ;
V_37 = F_101 ( V_131 -> V_272 , L_45 ) ;
if ( ! V_37 )
goto V_64;
V_70 = F_136 ( V_240 , V_37 , & V_202 ) ;
if ( V_70 )
goto V_64;
V_229 = V_37 ;
return 0 ;
V_64:
F_63 ( V_93 L_46 ,
V_94 ) ;
return V_70 ;
}
static struct V_37 * F_145 ( struct V_280 * V_281 ,
int V_75 , const char * V_282 , void * V_68 )
{
return F_146 ( V_281 , V_75 , V_68 , F_141 ) ;
}
static int T_1 F_147 ( void )
{
int V_64 ;
if ( ! V_283 )
return 0 ;
V_284 = F_148 ( L_47 , V_285 ) ;
if ( ! V_284 )
return - V_25 ;
V_64 = F_149 ( & V_286 ) ;
if ( V_64 ) {
F_150 ( V_284 ) ;
return V_64 ;
}
V_287 = F_151 ( & V_286 ) ;
if ( F_69 ( V_287 ) ) {
F_63 ( V_93 L_48 ) ;
V_64 = F_70 ( V_287 ) ;
V_287 = NULL ;
}
return V_64 ;
}
void F_152 ( void )
{
F_150 ( V_284 ) ;
F_153 ( V_287 ) ;
F_154 ( & V_286 ) ;
}
