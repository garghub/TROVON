static int
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
if ( V_2 -> V_5 . V_6 != NULL )
return 0 ;
V_2 -> V_5 . V_7 = F_2 ( L_1 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_5 . V_7 ) ) {
F_4 ( V_8 , L_2 ) ;
V_3 = F_5 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
return V_3 ;
}
V_4 = sizeof( struct V_9 ) +
F_6 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_6 = F_7 ( V_4 , V_10 ) ;
if ( ! V_2 -> V_5 . V_6 ) {
F_8 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
return - V_11 ;
}
V_2 -> V_5 . V_6 -> V_12 . V_13 = V_2 -> V_5 . V_7 ;
V_2 -> V_5 . V_6 -> V_12 . V_14 = 0x0 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_1 * V_2 , char * V_17 )
{
int V_18 ;
int V_3 ;
struct V_19 * V_20 = V_16 -> V_21 ;
int V_22 = V_16 -> V_23 ;
if ( V_20 == NULL || V_17 == NULL || V_2 == NULL )
return - V_24 ;
if ( ! V_2 -> V_5 . V_6 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_3 , V_25 ) ;
return - 1 ;
}
}
V_3 = F_10 ( & V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_4 , V_25 ) ;
return V_3 ;
}
V_3 = F_11 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_2 -> V_26 . V_27 , V_2 -> V_26 . V_28 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_5 , V_25 ) ;
return V_3 ;
}
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
if ( V_20 [ V_18 ] . V_29 == 0 )
continue;
if ( V_20 [ V_18 ] . V_30 == NULL ) {
F_4 ( V_8 , L_6 ) ;
return - V_31 ;
}
if ( V_18 == 0 ) {
if ( V_20 [ 0 ] . V_29 <= 8 )
break;
V_3 =
F_11 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_20 [ V_18 ] . V_30 + 4 , V_20 [ V_18 ] . V_29 - 4 ) ;
} else {
V_3 =
F_11 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_20 [ V_18 ] . V_30 , V_20 [ V_18 ] . V_29 ) ;
}
if ( V_3 ) {
F_4 ( V_8 , L_7 ,
V_25 ) ;
return V_3 ;
}
}
for ( V_18 = 0 ; V_18 < V_16 -> V_32 ; V_18 ++ ) {
struct V_19 V_33 ;
F_12 ( V_16 , V_18 , & V_33 ) ;
F_11 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_33 . V_30 , V_33 . V_29 ) ;
F_13 ( V_16 -> V_34 [ V_18 ] ) ;
}
V_3 = F_14 ( & V_2 -> V_5 . V_6 -> V_12 , V_17 ) ;
if ( V_3 )
F_4 ( V_8 , L_8 , V_25 ) ;
return V_3 ;
}
int F_15 ( struct V_15 * V_16 , struct V_1 * V_2 ,
T_1 * V_35 )
{
int V_3 = 0 ;
char V_36 [ 20 ] ;
struct V_37 * V_38 = (struct V_37 * ) V_16 -> V_21 [ 0 ] . V_30 ;
if ( ( V_38 == NULL ) || ( V_2 == NULL ) )
return - V_24 ;
if ( ! ( V_38 -> V_39 & V_40 ) ||
V_2 -> V_41 == V_42 )
return V_3 ;
if ( ! V_2 -> V_43 ) {
memcpy ( V_38 -> V_44 . V_45 , L_9 , 8 ) ;
return V_3 ;
}
V_38 -> V_44 . V_46 . V_47 =
F_16 ( V_2 -> V_48 ) ;
V_38 -> V_44 . V_46 . V_49 = 0 ;
* V_35 = ++ V_2 -> V_48 ;
++ V_2 -> V_48 ;
V_3 = F_9 ( V_16 , V_2 , V_36 ) ;
if ( V_3 )
memset ( V_38 -> V_44 . V_45 , 0 , 8 ) ;
else
memcpy ( V_38 -> V_44 . V_45 , V_36 , 8 ) ;
return V_3 ;
}
int F_17 ( struct V_19 * V_20 , int V_22 , struct V_1 * V_2 ,
T_1 * V_50 )
{
struct V_15 V_16 = { . V_21 = V_20 ,
. V_23 = V_22 } ;
return F_15 ( & V_16 , V_2 , V_50 ) ;
}
int F_18 ( struct V_37 * V_38 , struct V_1 * V_2 ,
T_1 * V_35 )
{
struct V_19 V_20 ;
V_20 . V_30 = V_38 ;
V_20 . V_29 = F_19 ( V_38 -> V_51 ) + 4 ;
return F_17 ( & V_20 , 1 , V_2 ,
V_35 ) ;
}
int F_20 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
T_1 V_52 )
{
unsigned int V_3 ;
char V_53 [ 8 ] ;
char V_54 [ 20 ] ;
struct V_37 * V_38 = (struct V_37 * ) V_16 -> V_21 [ 0 ] . V_30 ;
if ( V_38 == NULL || V_2 == NULL )
return - V_24 ;
if ( ! V_2 -> V_43 )
return 0 ;
if ( V_38 -> V_55 == V_56 ) {
struct V_57 * V_58 =
(struct V_57 * ) V_38 ;
if ( V_58 -> V_59 & V_60 )
return 0 ;
}
if ( memcmp ( V_38 -> V_44 . V_45 , L_10 , 8 ) == 0 )
F_4 ( V_61 , L_11 ,
V_38 -> V_55 ) ;
memcpy ( V_53 , V_38 -> V_44 . V_45 , 8 ) ;
V_38 -> V_44 . V_46 . V_47 =
F_16 ( V_52 ) ;
V_38 -> V_44 . V_46 . V_49 = 0 ;
F_21 ( & V_2 -> V_62 ) ;
V_3 = F_9 ( V_16 , V_2 , V_54 ) ;
F_22 ( & V_2 -> V_62 ) ;
if ( V_3 )
return V_3 ;
if ( memcmp ( V_53 , V_54 , 8 ) )
return - V_63 ;
else
return 0 ;
}
int F_23 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
int V_3 = 0 ;
unsigned int V_68 = V_69 + V_70 ;
char V_71 [ V_69 ] ;
if ( ! V_65 )
return - V_24 ;
V_65 -> V_72 . V_27 = F_7 ( V_68 , V_10 ) ;
if ( ! V_65 -> V_72 . V_27 )
return - V_11 ;
V_65 -> V_72 . V_28 = V_68 ;
V_3 = F_24 ( V_65 -> V_73 , V_65 -> V_2 -> V_74 ,
V_65 -> V_72 . V_27 + V_69 , V_67 ) ;
if ( V_3 ) {
F_4 ( V_61 , L_12 ,
V_25 , V_3 ) ;
return V_3 ;
}
V_3 = F_25 ( V_65 -> V_73 , V_71 , V_67 ) ;
if ( V_3 ) {
F_4 ( V_61 , L_13 ,
V_25 , V_3 ) ;
return V_3 ;
}
V_3 = F_26 ( V_65 -> V_72 . V_27 , V_71 , V_69 ) ;
if ( V_3 )
F_4 ( V_61 , L_14 ,
V_25 , V_3 ) ;
return V_3 ;
}
int F_27 ( const char * V_73 , const char * V_74 , bool V_75 ,
char * V_76 )
{
int V_18 ;
int V_3 ;
char V_77 [ V_78 ] ;
memset ( V_77 , 0 , V_78 ) ;
if ( V_73 )
strncpy ( V_77 , V_73 , V_78 ) ;
if ( ! V_75 && V_79 & V_80 ) {
memcpy ( V_76 , V_77 ,
V_78 ) ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_78 ; V_18 ++ )
V_77 [ V_18 ] = toupper ( V_77 [ V_18 ] ) ;
V_3 = F_28 ( V_77 , V_74 , V_76 ) ;
return V_3 ;
}
static int
F_29 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
unsigned int V_81 ;
unsigned int V_4 = 2 * sizeof( struct V_82 ) ;
char * V_83 = L_15 ;
unsigned char * V_84 ;
struct V_82 * V_85 ;
if ( ! V_65 -> V_86 ) {
V_65 -> V_86 = F_30 ( V_83 , V_10 ) ;
if ( ! V_65 -> V_86 )
return - V_11 ;
}
V_81 = strlen ( V_65 -> V_86 ) ;
V_65 -> V_72 . V_28 = V_4 + 2 * V_81 ;
V_65 -> V_72 . V_27 = F_31 ( V_65 -> V_72 . V_28 , V_10 ) ;
if ( ! V_65 -> V_72 . V_27 ) {
V_65 -> V_72 . V_28 = 0 ;
return - V_11 ;
}
V_84 = V_65 -> V_72 . V_27 ;
V_85 = (struct V_82 * ) V_84 ;
V_85 -> type = F_32 ( V_87 ) ;
V_85 -> V_88 = F_32 ( 2 * V_81 ) ;
V_84 = ( unsigned char * ) V_85 + sizeof( struct V_82 ) ;
F_33 ( ( V_89 * ) V_84 , V_65 -> V_86 , V_81 , V_67 ) ;
return 0 ;
}
static int
F_34 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
unsigned int V_90 ;
unsigned int type ;
unsigned int V_91 = sizeof( struct V_82 ) ;
unsigned char * V_84 ;
unsigned char * V_92 ;
struct V_82 * V_85 ;
if ( ! V_65 -> V_72 . V_28 || ! V_65 -> V_72 . V_27 )
return 0 ;
V_84 = V_65 -> V_72 . V_27 ;
V_92 = V_84 + V_65 -> V_72 . V_28 ;
while ( V_84 + V_91 < V_92 ) {
V_85 = (struct V_82 * ) V_84 ;
type = F_35 ( V_85 -> type ) ;
if ( type == V_93 )
break;
V_84 += 2 ;
V_90 = F_35 ( V_85 -> V_88 ) ;
V_84 += 2 ;
if ( V_84 + V_90 > V_92 )
break;
if ( type == V_87 ) {
if ( ! V_90 || V_90 >= V_94 )
break;
if ( ! V_65 -> V_86 ) {
V_65 -> V_86 =
F_7 ( V_90 + 1 , V_10 ) ;
if ( ! V_65 -> V_86 )
return - V_11 ;
F_36 ( V_65 -> V_86 ,
( V_89 * ) V_84 , V_90 , V_90 ,
V_67 , false ) ;
break;
}
}
V_84 += V_90 ;
}
return 0 ;
}
static int F_37 ( struct V_64 * V_65 , char * V_95 ,
const struct V_66 * V_67 )
{
int V_3 = 0 ;
int V_28 ;
char V_96 [ V_97 ] ;
V_89 * V_98 ;
T_2 * V_99 ;
T_2 * V_2 ;
if ( ! V_65 -> V_2 -> V_5 . V_100 ) {
F_4 ( V_8 , L_16 , V_25 ) ;
return - 1 ;
}
F_25 ( V_65 -> V_73 , V_96 , V_67 ) ;
V_3 = F_38 ( V_65 -> V_2 -> V_5 . V_101 , V_96 ,
V_97 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_17 , V_25 ) ;
return V_3 ;
}
V_3 = F_10 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_18 , V_25 ) ;
return V_3 ;
}
V_28 = V_65 -> V_102 ? strlen ( V_65 -> V_102 ) : 0 ;
V_98 = F_7 ( 2 + ( V_28 * 2 ) , V_10 ) ;
if ( V_98 == NULL ) {
V_3 = - V_11 ;
return V_3 ;
}
if ( V_28 ) {
V_28 = F_33 ( V_98 , V_65 -> V_102 , V_28 , V_67 ) ;
F_39 ( V_98 ) ;
} else {
memset ( V_98 , '\0' , 2 ) ;
}
V_3 = F_11 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
( char * ) V_98 , 2 * V_28 ) ;
F_40 ( V_98 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_19 , V_25 ) ;
return V_3 ;
}
if ( V_65 -> V_86 ) {
V_28 = strlen ( V_65 -> V_86 ) ;
V_99 = F_7 ( 2 + ( V_28 * 2 ) , V_10 ) ;
if ( V_99 == NULL ) {
V_3 = - V_11 ;
return V_3 ;
}
V_28 = F_33 ( ( V_89 * ) V_99 , V_65 -> V_86 , V_28 ,
V_67 ) ;
V_3 =
F_11 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
( char * ) V_99 , 2 * V_28 ) ;
F_40 ( V_99 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_20 ,
V_25 ) ;
return V_3 ;
}
} else if ( V_65 -> V_103 ) {
V_28 = strlen ( V_65 -> V_103 ) ;
V_2 = F_7 ( 2 + ( V_28 * 2 ) , V_10 ) ;
if ( V_2 == NULL ) {
V_3 = - V_11 ;
return V_3 ;
}
V_28 = F_33 ( ( V_89 * ) V_2 , V_65 -> V_103 , V_28 ,
V_67 ) ;
V_3 =
F_11 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
( char * ) V_2 , 2 * V_28 ) ;
F_40 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_21 ,
V_25 ) ;
return V_3 ;
}
}
V_3 = F_14 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
V_95 ) ;
if ( V_3 )
F_4 ( V_8 , L_8 , V_25 ) ;
return V_3 ;
}
static int
F_41 ( const struct V_64 * V_65 , char * V_95 )
{
int V_3 ;
struct V_104 * V_105 = (struct V_104 * )
( V_65 -> V_72 . V_27 + V_69 ) ;
unsigned int V_106 ;
V_106 = V_65 -> V_72 . V_28 - ( V_69 +
F_42 ( struct V_104 , V_107 . V_108 [ 0 ] ) ) ;
if ( ! V_65 -> V_2 -> V_5 . V_100 ) {
F_4 ( V_8 , L_16 , V_25 ) ;
return - 1 ;
}
V_3 = F_38 ( V_65 -> V_2 -> V_5 . V_101 ,
V_95 , V_109 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_22 ,
V_25 ) ;
return V_3 ;
}
V_3 = F_10 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_18 , V_25 ) ;
return V_3 ;
}
if ( V_65 -> V_2 -> V_110 == V_111 )
memcpy ( V_105 -> V_107 . V_108 ,
V_65 -> V_112 -> V_74 , V_113 ) ;
else
memcpy ( V_105 -> V_107 . V_108 ,
V_65 -> V_2 -> V_74 , V_113 ) ;
V_3 = F_11 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
V_105 -> V_107 . V_108 , V_106 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_5 , V_25 ) ;
return V_3 ;
}
V_3 = F_14 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
V_105 -> V_95 ) ;
if ( V_3 )
F_4 ( V_8 , L_8 , V_25 ) ;
return V_3 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
if ( V_2 -> V_5 . V_100 )
return 0 ;
V_2 -> V_5 . V_101 = F_2 ( L_23 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_5 . V_101 ) ) {
F_4 ( V_8 , L_24 ) ;
V_3 = F_5 ( V_2 -> V_5 . V_101 ) ;
V_2 -> V_5 . V_101 = NULL ;
return V_3 ;
}
V_4 = sizeof( struct V_9 ) +
F_6 ( V_2 -> V_5 . V_101 ) ;
V_2 -> V_5 . V_100 = F_7 ( V_4 , V_10 ) ;
if ( ! V_2 -> V_5 . V_100 ) {
F_8 ( V_2 -> V_5 . V_101 ) ;
V_2 -> V_5 . V_101 = NULL ;
return - V_11 ;
}
V_2 -> V_5 . V_100 -> V_12 . V_13 = V_2 -> V_5 . V_101 ;
V_2 -> V_5 . V_100 -> V_12 . V_14 = 0x0 ;
return 0 ;
}
int
F_44 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
int V_3 ;
int V_114 ;
unsigned int V_115 ;
struct V_104 * V_105 ;
char V_95 [ 16 ] ;
unsigned char * V_116 = NULL ;
if ( V_65 -> V_2 -> V_110 == V_111 ) {
if ( ! V_65 -> V_86 ) {
V_3 = F_34 ( V_65 , V_67 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_25 ,
V_3 ) ;
goto V_117;
}
}
} else {
V_3 = F_29 ( V_65 , V_67 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_26 , V_3 ) ;
goto V_117;
}
}
V_114 = V_69 + sizeof( struct V_104 ) ;
V_115 = V_65 -> V_72 . V_28 ;
V_116 = V_65 -> V_72 . V_27 ;
V_65 -> V_72 . V_27 = F_7 ( V_114 + V_115 , V_10 ) ;
if ( ! V_65 -> V_72 . V_27 ) {
V_3 = V_11 ;
V_65 -> V_72 . V_28 = 0 ;
goto V_117;
}
V_65 -> V_72 . V_28 += V_114 ;
V_105 = (struct V_104 * )
( V_65 -> V_72 . V_27 + V_69 ) ;
V_105 -> V_118 = F_16 ( 0x00000101 ) ;
V_105 -> V_119 = 0 ;
V_105 -> time = F_45 ( F_46 ( V_120 ) ) ;
F_47 ( & V_105 -> V_121 , sizeof( V_105 -> V_121 ) ) ;
V_105 -> V_122 = 0 ;
memcpy ( V_65 -> V_72 . V_27 + V_114 , V_116 , V_115 ) ;
V_3 = F_43 ( V_65 -> V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_27 , V_3 ) ;
goto V_117;
}
V_3 = F_37 ( V_65 , V_95 , V_67 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_28 , V_3 ) ;
goto V_117;
}
V_3 = F_41 ( V_65 , V_95 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_29 , V_3 ) ;
goto V_117;
}
V_3 = F_38 ( V_65 -> V_2 -> V_5 . V_101 ,
V_95 , V_109 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_22 ,
V_25 ) ;
goto V_117;
}
V_3 = F_10 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_30 , V_25 ) ;
goto V_117;
}
V_3 = F_11 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
V_105 -> V_95 ,
V_109 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_5 , V_25 ) ;
goto V_117;
}
V_3 = F_14 ( & V_65 -> V_2 -> V_5 . V_100 -> V_12 ,
V_65 -> V_72 . V_27 ) ;
if ( V_3 )
F_4 ( V_8 , L_8 , V_25 ) ;
V_117:
F_40 ( V_116 ) ;
return V_3 ;
}
int
F_48 ( struct V_64 * V_65 )
{
int V_3 ;
struct V_123 * V_124 ;
struct V_125 V_126 , V_127 ;
struct V_128 V_129 ;
unsigned char V_130 [ V_69 ] ;
F_47 ( V_130 , V_69 ) ;
V_124 = F_49 ( L_31 , 0 , V_131 ) ;
if ( F_3 ( V_124 ) ) {
V_3 = F_5 ( V_124 ) ;
F_4 ( V_8 , L_32 ) ;
return V_3 ;
}
V_129 . V_13 = V_124 ;
V_3 = F_50 ( V_124 , V_65 -> V_72 . V_27 ,
V_69 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_33 ,
V_25 ) ;
return V_3 ;
}
F_51 ( & V_126 , V_130 , V_69 ) ;
F_51 ( & V_127 , V_65 -> V_112 -> V_132 , V_133 ) ;
V_3 = F_52 ( & V_129 , & V_127 , & V_126 , V_133 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_34 , V_3 ) ;
F_53 ( V_124 ) ;
return V_3 ;
}
memcpy ( V_65 -> V_72 . V_27 , V_130 , V_69 ) ;
V_65 -> V_72 . V_28 = V_69 ;
F_53 ( V_124 ) ;
return V_3 ;
}
void
F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_134 ) {
F_8 ( V_2 -> V_5 . V_134 ) ;
V_2 -> V_5 . V_134 = NULL ;
}
if ( V_2 -> V_5 . V_135 ) {
F_8 ( V_2 -> V_5 . V_135 ) ;
V_2 -> V_5 . V_135 = NULL ;
}
if ( V_2 -> V_5 . V_7 ) {
F_8 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
}
if ( V_2 -> V_5 . V_101 ) {
F_8 ( V_2 -> V_5 . V_101 ) ;
V_2 -> V_5 . V_101 = NULL ;
}
F_40 ( V_2 -> V_5 . V_136 ) ;
V_2 -> V_5 . V_136 = NULL ;
F_40 ( V_2 -> V_5 . V_137 ) ;
V_2 -> V_5 . V_137 = NULL ;
F_40 ( V_2 -> V_5 . V_100 ) ;
V_2 -> V_5 . V_100 = NULL ;
F_40 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
}
