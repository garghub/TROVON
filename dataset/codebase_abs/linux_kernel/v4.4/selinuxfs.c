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
if ( V_24 != V_22 ) {
V_21 = F_3 ( V_31 , V_32 ) ;
if ( V_21 )
goto V_27;
F_14 ( V_31 -> V_33 , V_29 , V_34 ,
L_2 ,
V_24 , V_22 ,
F_15 ( & V_35 , F_16 ( V_31 ) ) ,
F_17 ( V_31 ) ) ;
V_22 = V_24 ;
if ( V_22 )
F_18 ( 0 ) ;
F_19 ( V_22 ) ;
F_20 ( V_22 ) ;
}
V_21 = V_17 ;
V_27:
F_21 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_22 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
T_7 V_36 = F_23 ( V_15 ) -> V_37 ;
int V_38 = ( V_36 == V_39 ) ?
F_24 () : ! F_25 () ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_38 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_26 ( struct V_40 * V_40 , struct V_14 * V_15 )
{
struct V_23 * V_41 = F_27 () ;
if ( ! V_41 )
return - V_25 ;
V_15 -> V_42 = V_41 ;
return 0 ;
}
static T_3 F_28 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
struct V_23 * V_41 = V_15 -> V_42 ;
F_29 ( ! V_41 ) ;
return F_10 ( V_16 , V_17 , V_18 ,
F_30 ( V_41 ) ,
sizeof( struct V_43 ) ) ;
}
static int F_31 ( struct V_14 * V_15 ,
struct V_44 * V_45 )
{
struct V_23 * V_41 = V_15 -> V_42 ;
unsigned long V_46 = V_45 -> V_47 - V_45 -> V_48 ;
F_29 ( ! V_41 ) ;
if ( V_45 -> V_49 > 0 || V_46 != V_26 )
return - V_50 ;
if ( V_45 -> V_51 & V_52 )
return - V_53 ;
V_45 -> V_51 &= ~ V_54 ;
return F_32 ( V_45 , V_45 -> V_48 ,
F_33 ( V_41 ) ,
V_46 , V_45 -> V_55 ) ;
}
static T_3 F_34 ( struct V_14 * V_14 , const char T_4 * V_16 ,
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
V_21 = F_35 () ;
if ( V_21 )
goto V_27;
F_14 ( V_31 -> V_33 , V_29 , V_34 ,
L_3 ,
F_15 ( & V_35 , F_16 ( V_31 ) ) ,
F_17 ( V_31 ) ) ;
}
V_21 = V_17 ;
V_27:
F_21 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_36 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_56 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_37 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_1 ,
F_38 () ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_39 ( struct V_40 * V_40 , struct V_14 * V_15 )
{
struct V_57 * V_58 = NULL ;
int V_59 ;
F_29 ( V_15 -> V_42 ) ;
F_40 ( & V_60 ) ;
V_59 = F_3 ( V_31 , V_61 ) ;
if ( V_59 )
goto V_62;
V_59 = - V_63 ;
if ( V_64 )
goto V_62;
V_59 = - V_25 ;
V_58 = F_41 ( sizeof( * V_58 ) , V_29 ) ;
if ( ! V_58 )
goto V_62;
if ( F_42 ( V_40 ) != F_43 () ) {
F_40 ( & V_40 -> V_65 ) ;
F_44 ( V_40 , F_43 () ) ;
F_45 ( & V_40 -> V_65 ) ;
}
V_59 = F_46 ( & V_58 -> V_66 , & V_58 -> V_67 ) ;
if ( V_59 )
goto V_62;
V_64 = 1 ;
V_15 -> V_42 = V_58 ;
F_45 ( & V_60 ) ;
return 0 ;
V_62:
F_45 ( & V_60 ) ;
if ( V_58 )
F_47 ( V_58 -> V_66 ) ;
F_48 ( V_58 ) ;
return V_59 ;
}
static int F_49 ( struct V_40 * V_40 , struct V_14 * V_15 )
{
struct V_57 * V_58 = V_15 -> V_42 ;
F_29 ( ! V_58 ) ;
V_64 = 0 ;
F_47 ( V_58 -> V_66 ) ;
F_48 ( V_58 ) ;
return 0 ;
}
static T_3 F_50 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
struct V_57 * V_58 = V_15 -> V_42 ;
int V_68 ;
F_40 ( & V_60 ) ;
V_68 = F_3 ( V_31 , V_61 ) ;
if ( V_68 )
goto V_27;
V_68 = F_10 ( V_16 , V_17 , V_18 , V_58 -> V_66 , V_58 -> V_67 ) ;
V_27:
F_45 ( & V_60 ) ;
return V_68 ;
}
static int F_51 ( struct V_44 * V_45 ,
struct V_69 * V_70 )
{
struct V_57 * V_58 = V_45 -> V_71 -> V_42 ;
unsigned long V_72 ;
struct V_23 * V_23 ;
if ( V_70 -> V_73 & ( V_74 | V_75 ) )
return V_76 ;
V_72 = V_70 -> V_77 << V_78 ;
if ( V_72 >= F_52 ( V_58 -> V_67 , V_26 ) )
return V_76 ;
V_23 = F_53 ( V_58 -> V_66 + V_72 ) ;
F_54 ( V_23 ) ;
V_70 -> V_23 = V_23 ;
return 0 ;
}
static int F_55 ( struct V_14 * V_15 , struct V_44 * V_45 )
{
if ( V_45 -> V_51 & V_79 ) {
V_45 -> V_51 &= ~ V_54 ;
if ( V_45 -> V_51 & V_52 )
return - V_11 ;
}
V_45 -> V_51 |= V_80 | V_81 ;
V_45 -> V_82 = & V_83 ;
return 0 ;
}
static T_3 F_56 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
T_3 V_21 ;
void * V_66 = NULL ;
F_40 ( & V_60 ) ;
V_21 = F_3 ( V_31 , V_84 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_21 = - V_85 ;
if ( V_17 > 64 * 1024 * 1024 )
goto V_27;
V_21 = - V_25 ;
V_66 = F_57 ( V_17 ) ;
if ( ! V_66 )
goto V_27;
V_21 = - V_30 ;
if ( F_13 ( V_66 , V_16 , V_17 ) != 0 )
goto V_27;
V_21 = F_58 ( V_66 , V_17 ) ;
if ( V_21 )
goto V_27;
V_21 = F_59 () ;
if ( V_21 )
goto V_86;
V_21 = F_60 () ;
if ( V_21 )
goto V_86;
V_21 = F_61 () ;
if ( V_21 )
goto V_86;
V_21 = V_17 ;
V_86:
F_14 ( V_31 -> V_33 , V_29 , V_87 ,
L_5 ,
F_15 ( & V_35 , F_16 ( V_31 ) ) ,
F_17 ( V_31 ) ) ;
V_27:
F_45 ( & V_60 ) ;
F_47 ( V_66 ) ;
return V_21 ;
}
static T_3 F_62 ( struct V_14 * V_14 , char * V_16 , T_5 V_46 )
{
char * V_88 = NULL ;
T_2 V_9 , V_67 ;
T_3 V_21 ;
V_21 = F_3 ( V_31 , V_89 ) ;
if ( V_21 )
goto V_27;
V_21 = F_63 ( V_16 , V_46 , & V_9 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_64 ( V_9 , & V_88 , & V_67 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_90 ;
if ( V_67 > V_91 ) {
F_65 ( V_92 L_6
L_7 , V_93 , V_67 ) ;
goto V_27;
}
memcpy ( V_16 , V_88 , V_67 ) ;
V_21 = V_67 ;
V_27:
F_48 ( V_88 ) ;
return V_21 ;
}
static T_3 F_66 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_3 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_67 ( struct V_14 * V_14 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
unsigned int V_24 ;
V_21 = F_3 ( V_31 , V_94 ) ;
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
F_21 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_68 ( struct V_14 * V_14 , const char T_4 * V_16 , T_5 V_46 , T_6 * V_95 )
{
T_7 V_36 = F_23 ( V_14 ) -> V_37 ;
char * V_66 ;
T_3 V_96 ;
if ( V_36 >= F_69 ( V_97 ) || ! V_97 [ V_36 ] )
return - V_28 ;
V_66 = F_70 ( V_14 , V_16 , V_46 ) ;
if ( F_71 ( V_66 ) )
return F_72 ( V_66 ) ;
V_96 = V_97 [ V_36 ] ( V_14 , V_66 , V_46 ) ;
if ( V_96 > 0 ) {
F_73 ( V_14 , V_96 ) ;
V_96 = V_46 ;
}
return V_96 ;
}
static T_3 F_74 ( struct V_14 * V_14 , char * V_16 , T_5 V_46 )
{
char * V_98 = NULL , * V_99 = NULL ;
T_2 V_100 , V_101 ;
T_8 V_102 ;
struct V_103 V_104 ;
T_3 V_21 ;
V_21 = F_3 ( V_31 , V_105 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_98 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_98 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_8 , V_98 , V_99 , & V_102 ) != 3 )
goto V_27;
V_21 = F_75 ( V_98 , & V_100 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_75 ( V_99 , & V_101 , V_29 ) ;
if ( V_21 )
goto V_27;
F_76 ( V_100 , V_101 , V_102 , & V_104 ) ;
V_21 = F_9 ( V_16 , V_91 ,
L_9 ,
V_104 . V_106 , 0xffffffff ,
V_104 . V_107 , V_104 . V_108 ,
V_104 . V_109 , V_104 . V_73 ) ;
V_27:
F_48 ( V_99 ) ;
F_48 ( V_98 ) ;
return V_21 ;
}
static T_3 F_77 ( struct V_14 * V_14 , char * V_16 , T_5 V_46 )
{
char * V_98 = NULL , * V_99 = NULL ;
char * V_110 = NULL , * V_111 = NULL ;
T_2 V_100 , V_101 , V_112 ;
T_8 V_102 ;
T_3 V_21 ;
char * V_113 = NULL ;
T_2 V_67 ;
int V_114 ;
V_21 = F_3 ( V_31 , V_115 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_98 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_98 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_25 ;
V_110 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_110 )
goto V_27;
V_21 = - V_28 ;
V_114 = sscanf ( V_16 , L_10 , V_98 , V_99 , & V_102 , V_110 ) ;
if ( V_114 < 3 || V_114 > 4 )
goto V_27;
if ( V_114 == 4 ) {
char * V_116 , * V_117 ;
int V_118 , V_119 ;
V_116 = V_117 = V_110 ;
do {
V_118 = * V_116 ++ ;
if ( V_118 == '+' )
V_118 = ' ' ;
else if ( V_118 == '%' ) {
V_118 = F_78 ( * V_116 ++ ) ;
if ( V_118 < 0 )
goto V_27;
V_119 = F_78 ( * V_116 ++ ) ;
if ( V_119 < 0 )
goto V_27;
V_118 = ( V_118 << 4 ) | V_119 ;
}
* V_117 ++ = V_118 ;
} while ( V_118 != '\0' );
V_111 = V_110 ;
}
V_21 = F_75 ( V_98 , & V_100 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_75 ( V_99 , & V_101 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_79 ( V_100 , V_101 , V_102 ,
V_111 , & V_112 ) ;
if ( V_21 )
goto V_27;
V_21 = F_64 ( V_112 , & V_113 , & V_67 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_90 ;
if ( V_67 > V_91 ) {
F_65 ( V_92 L_6
L_7 , V_93 , V_67 ) ;
goto V_27;
}
memcpy ( V_16 , V_113 , V_67 ) ;
V_21 = V_67 ;
V_27:
F_48 ( V_113 ) ;
F_48 ( V_110 ) ;
F_48 ( V_99 ) ;
F_48 ( V_98 ) ;
return V_21 ;
}
static T_3 F_80 ( struct V_14 * V_14 , char * V_16 , T_5 V_46 )
{
char * V_98 = NULL , * V_99 = NULL ;
T_2 V_100 , V_101 , V_112 ;
T_8 V_102 ;
T_3 V_21 ;
char * V_113 = NULL ;
T_2 V_67 ;
V_21 = F_3 ( V_31 , V_120 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_98 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_98 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_8 , V_98 , V_99 , & V_102 ) != 3 )
goto V_27;
V_21 = F_75 ( V_98 , & V_100 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_75 ( V_99 , & V_101 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_81 ( V_100 , V_101 , V_102 , & V_112 ) ;
if ( V_21 )
goto V_27;
V_21 = F_64 ( V_112 , & V_113 , & V_67 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_90 ;
if ( V_67 > V_91 )
goto V_27;
memcpy ( V_16 , V_113 , V_67 ) ;
V_21 = V_67 ;
V_27:
F_48 ( V_113 ) ;
F_48 ( V_99 ) ;
F_48 ( V_98 ) ;
return V_21 ;
}
static T_3 F_82 ( struct V_14 * V_14 , char * V_16 , T_5 V_46 )
{
char * V_121 = NULL , * V_122 = NULL , * V_123 ;
T_2 V_9 , * V_124 = NULL ;
T_3 V_21 ;
char * V_113 ;
int V_125 , V_59 ;
T_2 V_67 , V_126 ;
V_21 = F_3 ( V_31 , V_127 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_121 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_121 )
goto V_27;
V_21 = - V_25 ;
V_122 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_122 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_11 , V_121 , V_122 ) != 2 )
goto V_27;
V_21 = F_75 ( V_121 , & V_9 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_83 ( V_9 , V_122 , & V_124 , & V_126 ) ;
if ( V_21 )
goto V_27;
V_21 = sprintf ( V_16 , L_4 , V_126 ) + 1 ;
V_123 = V_16 + V_21 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
V_59 = F_64 ( V_124 [ V_125 ] , & V_113 , & V_67 ) ;
if ( V_59 ) {
V_21 = V_59 ;
goto V_27;
}
if ( ( V_21 + V_67 ) >= V_91 ) {
F_48 ( V_113 ) ;
V_21 = - V_90 ;
goto V_27;
}
memcpy ( V_123 , V_113 , V_67 ) ;
F_48 ( V_113 ) ;
V_123 += V_67 ;
V_21 += V_67 ;
}
V_27:
F_48 ( V_124 ) ;
F_48 ( V_122 ) ;
F_48 ( V_121 ) ;
return V_21 ;
}
static T_3 F_84 ( struct V_14 * V_14 , char * V_16 , T_5 V_46 )
{
char * V_98 = NULL , * V_99 = NULL ;
T_2 V_100 , V_101 , V_112 ;
T_8 V_102 ;
T_3 V_21 ;
char * V_113 = NULL ;
T_2 V_67 ;
V_21 = F_3 ( V_31 , V_128 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_25 ;
V_98 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_98 )
goto V_27;
V_21 = - V_25 ;
V_99 = F_41 ( V_46 + 1 , V_29 ) ;
if ( ! V_99 )
goto V_27;
V_21 = - V_28 ;
if ( sscanf ( V_16 , L_8 , V_98 , V_99 , & V_102 ) != 3 )
goto V_27;
V_21 = F_75 ( V_98 , & V_100 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_75 ( V_99 , & V_101 , V_29 ) ;
if ( V_21 )
goto V_27;
V_21 = F_85 ( V_100 , V_101 , V_102 , & V_112 ) ;
if ( V_21 )
goto V_27;
V_21 = F_64 ( V_112 , & V_113 , & V_67 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_90 ;
if ( V_67 > V_91 ) {
F_65 ( V_92 L_6
L_7 , V_93 , V_67 ) ;
goto V_27;
}
memcpy ( V_16 , V_113 , V_67 ) ;
V_21 = V_67 ;
V_27:
F_48 ( V_113 ) ;
F_48 ( V_99 ) ;
F_48 ( V_98 ) ;
return V_21 ;
}
static struct V_40 * F_86 ( struct V_129 * V_130 , int V_131 )
{
struct V_40 * V_68 = F_87 ( V_130 ) ;
if ( V_68 ) {
V_68 -> V_132 = V_131 ;
V_68 -> V_133 = V_68 -> V_134 = V_68 -> V_135 = V_136 ;
}
return V_68 ;
}
static T_3 F_88 ( struct V_14 * V_137 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
T_3 V_68 ;
int V_138 ;
unsigned V_139 = F_23 ( V_137 ) -> V_37 & V_140 ;
const char * V_141 = V_137 -> V_142 . V_143 -> V_144 . V_141 ;
F_40 ( & V_60 ) ;
V_68 = - V_28 ;
if ( V_139 >= V_145 || strcmp ( V_141 , V_146 [ V_139 ] ) )
goto V_27;
V_68 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_138 = F_89 ( V_139 ) ;
if ( V_138 < 0 ) {
V_68 = V_138 ;
goto V_27;
}
V_21 = F_9 ( V_23 , V_26 , L_12 , V_138 ,
V_147 [ V_139 ] ) ;
V_68 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
V_27:
F_45 ( & V_60 ) ;
F_21 ( ( unsigned long ) V_23 ) ;
return V_68 ;
}
static T_3 F_90 ( struct V_14 * V_137 , const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
unsigned V_139 = F_23 ( V_137 ) -> V_37 & V_140 ;
const char * V_141 = V_137 -> V_142 . V_143 -> V_144 . V_141 ;
F_40 ( & V_60 ) ;
V_21 = F_3 ( V_31 , V_148 ) ;
if ( V_21 )
goto V_27;
V_21 = - V_28 ;
if ( V_139 >= V_145 || strcmp ( V_141 , V_146 [ V_139 ] ) )
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
V_147 [ V_139 ] = V_24 ;
V_21 = V_17 ;
V_27:
F_45 ( & V_60 ) ;
F_21 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static T_3 F_91 ( struct V_14 * V_137 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_21 ;
int V_24 ;
F_40 ( & V_60 ) ;
V_21 = F_3 ( V_31 , V_148 ) ;
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
if ( V_24 && V_147 )
V_21 = F_92 ( V_145 , V_147 ) ;
if ( ! V_21 )
V_21 = V_17 ;
V_27:
F_45 ( & V_60 ) ;
F_21 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static void F_93 ( struct V_143 * V_149 )
{
F_94 ( V_149 ) ;
F_95 ( V_149 ) ;
}
static int F_59 ( void )
{
int V_125 , V_68 ;
T_3 V_67 ;
struct V_143 * V_143 = NULL ;
struct V_143 * V_150 = V_151 ;
struct V_40 * V_40 = NULL ;
struct V_152 * V_153 ;
char * * V_154 = NULL , * V_23 ;
int V_155 ;
int * V_156 = NULL ;
T_2 V_9 ;
for ( V_125 = 0 ; V_125 < V_145 ; V_125 ++ )
F_48 ( V_146 [ V_125 ] ) ;
F_48 ( V_146 ) ;
F_48 ( V_147 ) ;
V_145 = 0 ;
V_146 = NULL ;
V_147 = NULL ;
F_93 ( V_150 ) ;
V_68 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_68 = F_96 ( & V_155 , & V_154 , & V_156 ) ;
if ( V_68 )
goto V_27;
for ( V_125 = 0 ; V_125 < V_155 ; V_125 ++ ) {
V_68 = - V_25 ;
V_143 = F_97 ( V_150 , V_154 [ V_125 ] ) ;
if ( ! V_143 )
goto V_27;
V_68 = - V_25 ;
V_40 = F_86 ( V_150 -> V_157 , V_158 | V_159 | V_160 ) ;
if ( ! V_40 )
goto V_27;
V_68 = - V_161 ;
V_67 = snprintf ( V_23 , V_26 , L_13 , V_162 , V_154 [ V_125 ] ) ;
if ( V_67 >= V_26 )
goto V_27;
V_153 = (struct V_152 * ) V_40 -> V_163 ;
V_68 = F_98 ( L_14 , V_23 , V_164 , & V_9 ) ;
if ( V_68 )
goto V_27;
V_153 -> V_9 = V_9 ;
V_153 -> V_165 = 1 ;
V_40 -> V_166 = & V_167 ;
V_40 -> V_37 = V_125 | V_168 ;
F_99 ( V_143 , V_40 ) ;
}
V_145 = V_155 ;
V_146 = V_154 ;
V_147 = V_156 ;
F_21 ( ( unsigned long ) V_23 ) ;
return 0 ;
V_27:
F_21 ( ( unsigned long ) V_23 ) ;
if ( V_154 ) {
for ( V_125 = 0 ; V_125 < V_155 ; V_125 ++ )
F_48 ( V_154 [ V_125 ] ) ;
F_48 ( V_154 ) ;
}
F_48 ( V_156 ) ;
F_93 ( V_150 ) ;
return V_68 ;
}
static T_3 F_100 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char V_19 [ V_20 ] ;
T_3 V_21 ;
V_21 = F_9 ( V_19 , V_20 , L_4 , V_169 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static T_3 F_101 ( struct V_14 * V_14 ,
const char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 = NULL ;
T_3 V_68 ;
int V_24 ;
V_68 = F_3 ( V_31 , V_170 ) ;
if ( V_68 )
goto V_27;
V_68 = - V_25 ;
if ( V_17 >= V_26 )
goto V_27;
V_68 = - V_28 ;
if ( * V_18 != 0 )
goto V_27;
V_68 = - V_25 ;
V_23 = ( char * ) F_12 ( V_29 ) ;
if ( ! V_23 )
goto V_27;
V_68 = - V_30 ;
if ( F_13 ( V_23 , V_16 , V_17 ) )
goto V_27;
V_68 = - V_28 ;
if ( sscanf ( V_23 , L_4 , & V_24 ) != 1 )
goto V_27;
V_169 = V_24 ;
V_68 = V_17 ;
V_27:
F_21 ( ( unsigned long ) V_23 ) ;
return V_68 ;
}
static T_3 F_102 ( struct V_14 * V_15 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_23 ;
T_3 V_21 ;
V_23 = ( char * ) F_103 ( V_29 ) ;
if ( ! V_23 )
return - V_25 ;
V_21 = F_104 ( V_23 ) ;
if ( V_21 >= 0 )
V_21 = F_10 ( V_16 , V_17 , V_18 , V_23 , V_21 ) ;
F_21 ( ( unsigned long ) V_23 ) ;
return V_21 ;
}
static struct V_171 * F_105 ( T_6 * V_172 )
{
int V_173 ;
for ( V_173 = * V_172 ; V_173 < V_174 ; ++ V_173 ) {
if ( ! F_106 ( V_173 ) )
continue;
* V_172 = V_173 + 1 ;
return & F_107 ( V_171 , V_173 ) ;
}
return NULL ;
}
static void * F_108 ( struct V_175 * V_176 , T_6 * V_95 )
{
T_6 V_177 = * V_95 - 1 ;
if ( * V_95 == 0 )
return V_178 ;
return F_105 ( & V_177 ) ;
}
static void * F_109 ( struct V_175 * V_176 , void * V_179 , T_6 * V_95 )
{
return F_105 ( V_95 ) ;
}
static int F_110 ( struct V_175 * V_176 , void * V_179 )
{
struct V_171 * V_180 = V_179 ;
if ( V_179 == V_178 )
F_111 ( V_176 , L_15
L_16 ) ;
else {
unsigned int V_181 = V_180 -> V_181 ;
unsigned int V_182 = V_180 -> V_182 ;
unsigned int V_183 = V_181 - V_182 ;
F_111 ( V_176 , L_17 , V_181 ,
V_183 , V_182 , V_180 -> V_184 ,
V_180 -> V_185 , V_180 -> V_186 ) ;
}
return 0 ;
}
static void F_112 ( struct V_175 * V_176 , void * V_179 )
{ }
static int F_113 ( struct V_40 * V_40 , struct V_14 * V_14 )
{
return F_114 ( V_14 , & V_187 ) ;
}
static int F_115 ( struct V_143 * V_150 )
{
int V_125 ;
static struct V_188 V_189 [] = {
{ L_18 ,
& V_190 , V_159 | V_160 } ,
{ L_19 , & V_191 , V_159 } ,
#ifdef F_116
{ L_20 , & V_192 , V_159 } ,
#endif
} ;
for ( V_125 = 0 ; V_125 < F_69 ( V_189 ) ; V_125 ++ ) {
struct V_40 * V_40 ;
struct V_143 * V_143 ;
V_143 = F_97 ( V_150 , V_189 [ V_125 ] . V_141 ) ;
if ( ! V_143 )
return - V_25 ;
V_40 = F_86 ( V_150 -> V_157 , V_158 | V_189 [ V_125 ] . V_131 ) ;
if ( ! V_40 )
return - V_25 ;
V_40 -> V_166 = V_189 [ V_125 ] . V_193 ;
V_40 -> V_37 = ++ V_194 ;
F_99 ( V_143 , V_40 ) ;
}
return 0 ;
}
static T_3 F_117 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
char * V_121 ;
T_2 V_9 , V_67 ;
T_3 V_68 ;
V_9 = F_23 ( V_14 ) -> V_37 & V_140 ;
V_68 = F_64 ( V_9 , & V_121 , & V_67 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_10 ( V_16 , V_17 , V_18 , V_121 , V_67 ) ;
F_48 ( V_121 ) ;
return V_68 ;
}
static int F_118 ( struct V_143 * V_150 )
{
int V_125 ;
for ( V_125 = 1 ; V_125 <= V_195 ; V_125 ++ ) {
struct V_40 * V_40 ;
struct V_143 * V_143 ;
V_143 = F_97 ( V_150 , F_119 ( V_125 ) ) ;
if ( ! V_143 )
return - V_25 ;
V_40 = F_86 ( V_150 -> V_157 , V_158 | V_159 ) ;
if ( ! V_40 )
return - V_25 ;
V_40 -> V_166 = & V_196 ;
V_40 -> V_37 = V_125 | V_197 ;
F_99 ( V_143 , V_40 ) ;
}
return 0 ;
}
static inline unsigned long F_120 ( T_8 V_198 )
{
return ( V_198 * ( V_199 + 1 ) ) | V_200 ;
}
static inline T_8 F_121 ( unsigned long V_36 )
{
return ( V_36 & V_140 ) / ( V_199 + 1 ) ;
}
static inline unsigned long F_122 ( T_8 V_198 , T_2 V_201 )
{
return ( V_198 * ( V_199 + 1 ) + V_201 ) | V_200 ;
}
static inline T_2 F_123 ( unsigned long V_36 )
{
return ( V_36 & V_140 ) % ( V_199 + 1 ) ;
}
static T_3 F_124 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
unsigned long V_36 = F_23 ( V_14 ) -> V_37 ;
char V_202 [ V_20 ] ;
T_3 V_67 = snprintf ( V_202 , sizeof( V_202 ) , L_1 , F_121 ( V_36 ) ) ;
return F_10 ( V_16 , V_17 , V_18 , V_202 , V_67 ) ;
}
static T_3 F_125 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
unsigned long V_36 = F_23 ( V_14 ) -> V_37 ;
char V_202 [ V_20 ] ;
T_3 V_67 = snprintf ( V_202 , sizeof( V_202 ) , L_1 , F_123 ( V_36 ) ) ;
return F_10 ( V_16 , V_17 , V_18 , V_202 , V_67 ) ;
}
static T_3 F_126 ( struct V_14 * V_14 , char T_4 * V_16 ,
T_5 V_17 , T_6 * V_18 )
{
int V_203 ;
char V_19 [ V_20 ] ;
T_3 V_21 ;
unsigned long V_37 = F_23 ( V_14 ) -> V_37 ;
V_203 = F_127 ( V_37 & V_140 ) ;
V_21 = F_9 ( V_19 , V_20 , L_1 , V_203 ) ;
return F_10 ( V_16 , V_17 , V_18 , V_19 , V_21 ) ;
}
static int F_128 ( char * V_204 , int V_205 ,
struct V_143 * V_150 )
{
int V_125 , V_59 , V_206 ;
char * * V_6 ;
V_59 = F_129 ( V_204 , & V_6 , & V_206 ) ;
if ( V_59 )
return V_59 ;
for ( V_125 = 0 ; V_125 < V_206 ; V_125 ++ ) {
struct V_40 * V_40 ;
struct V_143 * V_143 ;
V_59 = - V_25 ;
V_143 = F_97 ( V_150 , V_6 [ V_125 ] ) ;
if ( ! V_143 )
goto V_27;
V_59 = - V_25 ;
V_40 = F_86 ( V_150 -> V_157 , V_158 | V_159 ) ;
if ( ! V_40 )
goto V_27;
V_40 -> V_166 = & V_207 ;
V_40 -> V_37 = F_122 ( V_205 , V_125 + 1 ) ;
F_99 ( V_143 , V_40 ) ;
}
V_59 = 0 ;
V_27:
for ( V_125 = 0 ; V_125 < V_206 ; V_125 ++ )
F_48 ( V_6 [ V_125 ] ) ;
F_48 ( V_6 ) ;
return V_59 ;
}
static int F_130 ( char * V_208 , int V_139 ,
struct V_143 * V_150 )
{
struct V_143 * V_143 = NULL ;
struct V_40 * V_40 = NULL ;
int V_59 ;
V_143 = F_97 ( V_150 , L_21 ) ;
if ( ! V_143 )
return - V_25 ;
V_40 = F_86 ( V_150 -> V_157 , V_158 | V_159 ) ;
if ( ! V_40 )
return - V_25 ;
V_40 -> V_166 = & V_209 ;
V_40 -> V_37 = F_120 ( V_139 ) ;
F_99 ( V_143 , V_40 ) ;
V_143 = F_131 ( V_150 , L_22 , & V_210 ) ;
if ( F_71 ( V_143 ) )
return F_72 ( V_143 ) ;
V_59 = F_128 ( V_208 , V_139 , V_143 ) ;
return V_59 ;
}
static int F_60 ( void )
{
int V_59 , V_211 , V_125 ;
char * * V_212 ;
F_93 ( V_213 ) ;
V_59 = F_132 ( & V_212 , & V_211 ) ;
if ( V_59 )
return V_59 ;
V_210 = F_120 ( V_211 + 2 ) ;
for ( V_125 = 0 ; V_125 < V_211 ; V_125 ++ ) {
struct V_143 * V_214 ;
V_214 = F_131 ( V_213 , V_212 [ V_125 ] ,
& V_210 ) ;
if ( F_71 ( V_214 ) ) {
V_59 = F_72 ( V_214 ) ;
goto V_27;
}
V_59 = F_130 ( V_212 [ V_125 ] , V_125 + 1 ,
V_214 ) ;
if ( V_59 )
goto V_27;
}
V_59 = 0 ;
V_27:
for ( V_125 = 0 ; V_125 < V_211 ; V_125 ++ )
F_48 ( V_212 [ V_125 ] ) ;
F_48 ( V_212 ) ;
return V_59 ;
}
static int F_61 ( void )
{
unsigned int V_215 ;
struct V_143 * V_143 = NULL ;
struct V_40 * V_40 = NULL ;
F_93 ( V_216 ) ;
for ( V_215 = 0 ; V_215 <= V_217 ; V_215 ++ ) {
if ( V_215 < F_69 ( V_218 ) )
V_143 = F_97 ( V_216 ,
V_218 [ V_215 ] ) ;
else
V_143 = F_97 ( V_216 , L_23 ) ;
if ( V_143 == NULL )
return - V_25 ;
V_40 = F_86 ( V_216 -> V_157 , V_158 | V_159 ) ;
if ( V_40 == NULL )
return - V_25 ;
V_40 -> V_166 = & V_219 ;
V_40 -> V_37 = V_215 | V_220 ;
F_99 ( V_143 , V_40 ) ;
}
return 0 ;
}
static struct V_143 * F_131 ( struct V_143 * V_150 , const char * V_141 ,
unsigned long * V_36 )
{
struct V_143 * V_143 = F_97 ( V_150 , V_141 ) ;
struct V_40 * V_40 ;
if ( ! V_143 )
return F_133 ( - V_25 ) ;
V_40 = F_86 ( V_150 -> V_157 , V_221 | V_159 | V_222 ) ;
if ( ! V_40 ) {
F_134 ( V_143 ) ;
return F_133 ( - V_25 ) ;
}
V_40 -> V_223 = & V_224 ;
V_40 -> V_166 = & V_225 ;
V_40 -> V_37 = ++ ( * V_36 ) ;
F_135 ( V_40 ) ;
F_99 ( V_143 , V_40 ) ;
F_135 ( F_136 ( V_150 ) ) ;
return V_143 ;
}
static int F_137 ( struct V_129 * V_130 , void * V_66 , int V_226 )
{
int V_68 ;
struct V_143 * V_143 ;
struct V_40 * V_40 ;
struct V_152 * V_153 ;
static struct V_188 V_227 [] = {
[ V_228 ] = { L_24 , & V_229 , V_230 | V_160 } ,
[ V_231 ] = { L_25 , & V_232 , V_159 | V_160 } ,
[ V_233 ] = { L_26 , & V_234 , V_159 | V_235 } ,
[ V_236 ] = { L_27 , & V_234 , V_159 | V_235 } ,
[ V_237 ] = { L_28 , & V_234 , V_159 | V_235 } ,
[ V_238 ] = { L_29 , & V_234 , V_159 | V_235 } ,
[ V_239 ] = { L_30 , & V_234 , V_159 | V_235 } ,
[ V_240 ] = { L_31 , & V_241 , V_159 } ,
[ V_242 ] = { L_32 , & V_243 , V_160 } ,
[ V_244 ] = { L_33 , & V_245 , V_159 } ,
[ V_246 ] = { L_34 , & V_247 , V_160 } ,
[ V_248 ] = { L_35 , & V_234 , V_159 | V_235 } ,
[ V_249 ] = { L_36 , & V_250 , V_159 | V_160 } ,
[ V_39 ] = { L_37 , & V_251 , V_159 } ,
[ V_252 ] = { L_38 , & V_251 , V_159 } ,
[ V_253 ] = { L_39 , & V_254 , V_159 } ,
[ V_255 ] = { L_40 , & V_256 , V_159 } ,
{ L_41 }
} ;
V_68 = F_138 ( V_130 , V_257 , V_227 ) ;
if ( V_68 )
goto V_62;
V_151 = F_131 ( V_130 -> V_258 , V_162 , & V_194 ) ;
if ( F_71 ( V_151 ) ) {
V_68 = F_72 ( V_151 ) ;
V_151 = NULL ;
goto V_62;
}
V_68 = - V_25 ;
V_143 = F_97 ( V_130 -> V_258 , V_259 ) ;
if ( ! V_143 )
goto V_62;
V_68 = - V_25 ;
V_40 = F_86 ( V_130 , V_260 | V_159 | V_235 ) ;
if ( ! V_40 )
goto V_62;
V_40 -> V_37 = ++ V_194 ;
V_153 = (struct V_152 * ) V_40 -> V_163 ;
V_153 -> V_9 = V_261 ;
V_153 -> V_262 = V_263 ;
V_153 -> V_165 = 1 ;
F_139 ( V_40 , V_260 | V_159 | V_235 , F_140 ( V_264 , 3 ) ) ;
F_99 ( V_143 , V_40 ) ;
V_265 . V_143 = V_143 ;
V_143 = F_131 ( V_130 -> V_258 , L_42 , & V_194 ) ;
if ( F_71 ( V_143 ) ) {
V_68 = F_72 ( V_143 ) ;
goto V_62;
}
V_68 = F_115 ( V_143 ) ;
if ( V_68 )
goto V_62;
V_143 = F_131 ( V_130 -> V_258 , L_43 , & V_194 ) ;
if ( F_71 ( V_143 ) ) {
V_68 = F_72 ( V_143 ) ;
goto V_62;
}
V_68 = F_118 ( V_143 ) ;
if ( V_68 )
goto V_62;
V_213 = F_131 ( V_130 -> V_258 , L_44 , & V_194 ) ;
if ( F_71 ( V_213 ) ) {
V_68 = F_72 ( V_213 ) ;
V_213 = NULL ;
goto V_62;
}
V_216 = F_131 ( V_130 -> V_258 , L_45 , & V_194 ) ;
if ( F_71 ( V_216 ) ) {
V_68 = F_72 ( V_216 ) ;
V_216 = NULL ;
goto V_62;
}
return 0 ;
V_62:
F_65 ( V_92 L_46 ,
V_93 ) ;
return V_68 ;
}
static struct V_143 * F_141 ( struct V_266 * V_267 ,
int V_73 , const char * V_268 , void * V_66 )
{
return F_142 ( V_267 , V_73 , V_66 , F_137 ) ;
}
static int T_1 F_143 ( void )
{
int V_62 ;
if ( ! V_269 )
return 0 ;
V_62 = F_144 ( V_270 , L_47 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_145 ( & V_271 ) ;
if ( V_62 ) {
F_146 ( V_270 , L_47 ) ;
return V_62 ;
}
V_265 . V_272 = V_273 = F_147 ( & V_271 ) ;
if ( F_71 ( V_273 ) ) {
F_65 ( V_92 L_48 ) ;
V_62 = F_72 ( V_273 ) ;
V_273 = NULL ;
}
return V_62 ;
}
void F_148 ( void )
{
F_146 ( V_270 , L_47 ) ;
F_149 ( V_273 ) ;
F_150 ( & V_271 ) ;
}
