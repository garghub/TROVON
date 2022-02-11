static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 ;
if ( V_2 == NULL || V_5 == NULL || V_4 == NULL )
return - V_7 ;
if ( ! V_4 -> V_8 . V_9 ) {
F_2 ( 1 , L_1 , V_10 ) ;
return - 1 ;
}
V_6 = F_3 ( & V_4 -> V_8 . V_9 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_2 , V_10 ) ;
return V_6 ;
}
F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_4 -> V_12 . V_13 , V_4 -> V_12 . V_14 ) ;
F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_2 -> V_15 , F_5 ( V_2 -> V_16 ) ) ;
V_6 = F_6 ( & V_4 -> V_8 . V_9 -> V_11 , V_5 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_17 )
{
int V_6 = 0 ;
char V_18 [ 20 ] ;
if ( ( V_2 == NULL ) || ( V_4 == NULL ) )
return - V_7 ;
if ( ( V_2 -> V_19 & V_20 ) == 0 )
return V_6 ;
V_2 -> V_21 . V_22 . V_23 =
F_8 ( V_4 -> V_24 ) ;
V_2 -> V_21 . V_22 . V_25 = 0 ;
* V_17 = V_4 -> V_24 ++ ;
V_4 -> V_24 ++ ;
V_6 = F_1 ( V_2 , V_4 , V_18 ) ;
if ( V_6 )
memset ( V_2 -> V_21 . V_26 , 0 , 8 ) ;
else
memcpy ( V_2 -> V_21 . V_26 , V_18 , 8 ) ;
return V_6 ;
}
static int F_9 ( const struct V_27 * V_28 , int V_29 ,
struct V_3 * V_4 , char * V_5 )
{
int V_30 ;
int V_6 ;
if ( V_28 == NULL || V_5 == NULL || V_4 == NULL )
return - V_7 ;
if ( ! V_4 -> V_8 . V_9 ) {
F_2 ( 1 , L_1 , V_10 ) ;
return - 1 ;
}
V_6 = F_3 ( & V_4 -> V_8 . V_9 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_2 , V_10 ) ;
return V_6 ;
}
F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_4 -> V_12 . V_13 , V_4 -> V_12 . V_14 ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
if ( V_28 [ V_30 ] . V_31 == 0 )
continue;
if ( V_28 [ V_30 ] . V_32 == NULL ) {
F_2 ( 1 , L_3 ) ;
return - V_33 ;
}
if ( V_30 == 0 ) {
if ( V_28 [ 0 ] . V_31 <= 8 )
break;
F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_28 [ V_30 ] . V_32 + 4 , V_28 [ V_30 ] . V_31 - 4 ) ;
} else
F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_28 [ V_30 ] . V_32 , V_28 [ V_30 ] . V_31 ) ;
}
V_6 = F_6 ( & V_4 -> V_8 . V_9 -> V_11 , V_5 ) ;
return V_6 ;
}
int F_10 ( struct V_27 * V_28 , int V_29 , struct V_3 * V_4 ,
T_1 * V_17 )
{
int V_6 = 0 ;
char V_18 [ 20 ] ;
struct V_1 * V_2 = V_28 [ 0 ] . V_32 ;
if ( ( V_2 == NULL ) || ( V_4 == NULL ) )
return - V_7 ;
if ( ( V_2 -> V_19 & V_20 ) == 0 )
return V_6 ;
V_2 -> V_21 . V_22 . V_23 =
F_8 ( V_4 -> V_24 ) ;
V_2 -> V_21 . V_22 . V_25 = 0 ;
* V_17 = V_4 -> V_24 ++ ;
V_4 -> V_24 ++ ;
V_6 = F_9 ( V_28 , V_29 , V_4 , V_18 ) ;
if ( V_6 )
memset ( V_2 -> V_21 . V_26 , 0 , 8 ) ;
else
memcpy ( V_2 -> V_21 . V_26 , V_18 , 8 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_34 )
{
unsigned int V_6 ;
char V_35 [ 8 ] ;
char V_36 [ 20 ] ;
if ( V_2 == NULL || V_4 == NULL )
return - V_7 ;
if ( ! V_4 -> V_37 )
return 0 ;
if ( V_2 -> V_38 == V_39 ) {
struct V_40 * V_41 =
(struct V_40 * ) V_2 ;
if ( V_41 -> V_42 & V_43 )
return 0 ;
}
if ( memcmp ( V_2 -> V_21 . V_26 , L_4 , 8 ) == 0 )
F_12 ( 1 , L_5 ,
V_2 -> V_38 ) ;
memcpy ( V_35 , V_2 -> V_21 . V_26 , 8 ) ;
V_2 -> V_21 . V_22 . V_23 =
F_8 ( V_34 ) ;
V_2 -> V_21 . V_22 . V_25 = 0 ;
F_13 ( & V_4 -> V_44 ) ;
V_6 = F_1 ( V_2 , V_4 ,
V_36 ) ;
F_14 ( & V_4 -> V_44 ) ;
if ( V_6 )
return V_6 ;
if ( memcmp ( V_35 , V_36 , 8 ) )
return - V_45 ;
else
return 0 ;
}
int F_15 ( struct V_46 * V_47 )
{
int V_6 = 0 ;
unsigned int V_48 = V_49 + V_50 ;
char V_51 [ V_49 ] ;
if ( ! V_47 )
return - V_7 ;
V_47 -> V_52 . V_13 = F_16 ( V_48 , V_53 ) ;
if ( ! V_47 -> V_52 . V_13 ) {
F_2 ( 1 , L_6 , V_48 ) ;
return - V_54 ;
}
V_47 -> V_52 . V_14 = V_48 ;
V_6 = F_17 ( V_47 -> V_55 , V_47 -> V_4 -> V_56 ,
V_47 -> V_52 . V_13 + V_49 ) ;
if ( V_6 ) {
F_12 ( 1 , L_7 ,
V_10 , V_6 ) ;
return V_6 ;
}
V_6 = F_18 ( V_47 -> V_55 , V_51 ) ;
if ( V_6 ) {
F_12 ( 1 , L_8 , V_10 , V_6 ) ;
return V_6 ;
}
V_6 = F_19 ( V_47 -> V_52 . V_13 , V_51 , V_49 ) ;
if ( V_6 )
F_12 ( 1 , L_9 ,
V_10 , V_6 ) ;
return V_6 ;
}
int F_20 ( const char * V_55 , const char * V_56 , bool V_57 ,
char * V_58 )
{
int V_30 ;
int V_6 ;
char V_59 [ V_60 ] ;
memset ( V_59 , 0 , V_60 ) ;
if ( V_55 )
strncpy ( V_59 , V_55 , V_60 ) ;
if ( ! V_57 && V_61 & V_62 ) {
memset ( V_58 , 0 , V_49 ) ;
memcpy ( V_58 , V_59 ,
V_60 ) ;
return 0 ;
}
for ( V_30 = 0 ; V_30 < V_60 ; V_30 ++ )
V_59 [ V_30 ] = toupper ( V_59 [ V_30 ] ) ;
V_6 = F_21 ( V_59 , V_56 , V_58 ) ;
return V_6 ;
}
static int
F_22 ( struct V_46 * V_47 , const struct V_63 * V_64 )
{
unsigned int V_65 ;
unsigned int V_66 ;
unsigned int V_67 = 6 * sizeof( struct V_68 ) ;
T_2 V_69 ;
char * V_70 = L_10 ;
unsigned char * V_71 ;
struct V_68 * V_72 ;
if ( ! V_47 -> V_73 ) {
V_47 -> V_73 = F_23 ( V_70 , V_53 ) ;
if ( ! V_47 -> V_73 )
return - V_54 ;
}
V_65 = strlen ( V_47 -> V_73 ) ;
V_66 = strlen ( V_47 -> V_4 -> V_74 ) ;
V_47 -> V_52 . V_14 = V_67 + 2 * ( 2 * V_65 ) + 2 * ( 2 * V_66 ) + 8 ;
V_47 -> V_52 . V_13 = F_24 ( V_47 -> V_52 . V_14 , V_53 ) ;
if ( ! V_47 -> V_52 . V_13 ) {
V_47 -> V_52 . V_14 = 0 ;
F_2 ( 1 , L_11 ) ;
return - V_54 ;
}
V_71 = V_47 -> V_52 . V_13 ;
V_72 = (struct V_68 * ) V_71 ;
V_72 -> type = F_25 ( V_75 ) ;
V_72 -> V_76 = F_25 ( 2 * V_65 ) ;
V_71 = ( unsigned char * ) V_72 + sizeof( struct V_68 ) ;
F_26 ( ( V_77 * ) V_71 , V_47 -> V_73 , V_65 , V_64 ) ;
V_71 += 2 * V_65 ;
V_72 = (struct V_68 * ) V_71 ;
V_72 -> type = F_25 ( V_78 ) ;
V_72 -> V_76 = F_25 ( 2 * V_66 ) ;
V_71 = ( unsigned char * ) V_72 + sizeof( struct V_68 ) ;
F_26 ( ( V_77 * ) V_71 , V_47 -> V_4 -> V_74 , V_66 , V_64 ) ;
V_71 += 2 * V_66 ;
V_72 = (struct V_68 * ) V_71 ;
V_72 -> type = F_25 ( V_79 ) ;
V_72 -> V_76 = F_25 ( 2 * V_65 ) ;
V_71 = ( unsigned char * ) V_72 + sizeof( struct V_68 ) ;
F_26 ( ( V_77 * ) V_71 , V_47 -> V_73 , V_65 , V_64 ) ;
V_71 += 2 * V_65 ;
V_72 = (struct V_68 * ) V_71 ;
V_72 -> type = F_25 ( V_80 ) ;
V_72 -> V_76 = F_25 ( 2 * V_66 ) ;
V_71 = ( unsigned char * ) V_72 + sizeof( struct V_68 ) ;
F_26 ( ( V_77 * ) V_71 , V_47 -> V_4 -> V_74 , V_66 , V_64 ) ;
V_71 += 2 * V_66 ;
V_72 = (struct V_68 * ) V_71 ;
V_72 -> type = F_25 ( V_81 ) ;
V_72 -> V_76 = F_25 ( sizeof( T_2 ) ) ;
V_71 = ( unsigned char * ) V_72 + sizeof( struct V_68 ) ;
V_69 = F_27 ( F_28 ( V_82 ) ) ;
memcpy ( V_71 , & V_69 , sizeof( T_2 ) ) ;
return 0 ;
}
static int
F_29 ( struct V_46 * V_47 , const struct V_63 * V_64 )
{
unsigned int V_83 ;
unsigned int type ;
unsigned int V_84 = sizeof( struct V_68 ) ;
unsigned char * V_71 ;
unsigned char * V_85 ;
struct V_68 * V_72 ;
if ( ! V_47 -> V_52 . V_14 || ! V_47 -> V_52 . V_13 )
return 0 ;
V_71 = V_47 -> V_52 . V_13 ;
V_85 = V_71 + V_47 -> V_52 . V_14 ;
while ( V_71 + V_84 < V_85 ) {
V_72 = (struct V_68 * ) V_71 ;
type = F_30 ( V_72 -> type ) ;
if ( type == V_86 )
break;
V_71 += 2 ;
V_83 = F_30 ( V_72 -> V_76 ) ;
V_71 += 2 ;
if ( V_71 + V_83 > V_85 )
break;
if ( type == V_75 ) {
if ( ! V_83 )
break;
if ( ! V_47 -> V_73 ) {
V_47 -> V_73 =
F_16 ( V_83 + 1 , V_53 ) ;
if ( ! V_47 -> V_73 )
return - V_54 ;
F_31 ( V_47 -> V_73 ,
( V_77 * ) V_71 , V_83 , V_83 ,
V_64 , false ) ;
break;
}
}
V_71 += V_83 ;
}
return 0 ;
}
static int F_32 ( struct V_46 * V_47 , char * V_87 ,
const struct V_63 * V_64 )
{
int V_6 = 0 ;
int V_14 ;
char V_88 [ V_89 ] ;
T_3 * V_90 ;
T_3 * V_91 ;
T_3 * V_4 ;
if ( ! V_47 -> V_4 -> V_8 . V_92 ) {
F_2 ( 1 , L_12 ) ;
return - 1 ;
}
F_18 ( V_47 -> V_55 , V_88 ) ;
F_33 ( V_47 -> V_4 -> V_8 . V_93 , V_88 ,
V_89 ) ;
V_6 = F_3 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_13 ) ;
return V_6 ;
}
V_14 = strlen ( V_47 -> V_94 ) ;
V_90 = F_16 ( 2 + ( V_14 * 2 ) , V_53 ) ;
if ( V_90 == NULL ) {
F_2 ( 1 , L_14 ) ;
V_6 = - V_54 ;
goto V_95;
}
V_14 = F_26 ( ( V_77 * ) V_90 , V_47 -> V_94 , V_14 , V_64 ) ;
F_34 ( V_90 ) ;
F_4 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
( char * ) V_90 , 2 * V_14 ) ;
if ( V_47 -> V_73 ) {
V_14 = strlen ( V_47 -> V_73 ) ;
V_91 = F_16 ( 2 + ( V_14 * 2 ) , V_53 ) ;
if ( V_91 == NULL ) {
F_2 ( 1 , L_15 ) ;
V_6 = - V_54 ;
goto V_96;
}
V_14 = F_26 ( ( V_77 * ) V_91 , V_47 -> V_73 , V_14 ,
V_64 ) ;
F_4 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
( char * ) V_91 , 2 * V_14 ) ;
F_35 ( V_91 ) ;
} else if ( V_47 -> V_97 ) {
V_14 = strlen ( V_47 -> V_97 ) ;
V_4 = F_16 ( 2 + ( V_14 * 2 ) , V_53 ) ;
if ( V_4 == NULL ) {
F_2 ( 1 , L_16 ) ;
V_6 = - V_54 ;
goto V_96;
}
V_14 = F_26 ( ( V_77 * ) V_4 , V_47 -> V_97 , V_14 ,
V_64 ) ;
F_4 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
( char * ) V_4 , 2 * V_14 ) ;
F_35 ( V_4 ) ;
}
V_6 = F_6 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
V_87 ) ;
V_96:
F_35 ( V_90 ) ;
V_95:
return V_6 ;
}
static int
F_36 ( const struct V_46 * V_47 , char * V_87 )
{
int V_6 ;
unsigned int V_98 = V_49 + 8 ;
if ( ! V_47 -> V_4 -> V_8 . V_92 ) {
F_2 ( 1 , L_12 ) ;
return - 1 ;
}
F_33 ( V_47 -> V_4 -> V_8 . V_93 ,
V_87 , V_99 ) ;
V_6 = F_3 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_17 ) ;
return V_6 ;
}
if ( V_47 -> V_4 -> V_100 == V_101 )
memcpy ( V_47 -> V_52 . V_13 + V_98 ,
V_47 -> V_102 -> V_56 , V_103 ) ;
else
memcpy ( V_47 -> V_52 . V_13 + V_98 ,
V_47 -> V_4 -> V_56 , V_103 ) ;
F_4 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
V_47 -> V_52 . V_13 + V_98 , V_47 -> V_52 . V_14 - V_98 ) ;
V_6 = F_6 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
V_47 -> V_52 . V_13 + V_49 ) ;
return V_6 ;
}
int
F_37 ( struct V_46 * V_47 , const struct V_63 * V_64 )
{
int V_6 ;
int V_104 ;
unsigned int V_105 ;
struct V_106 * V_107 ;
char V_87 [ 16 ] ;
unsigned char * V_108 = NULL ;
if ( V_47 -> V_4 -> V_100 == V_101 ) {
if ( ! V_47 -> V_73 ) {
V_6 = F_29 ( V_47 , V_64 ) ;
if ( V_6 ) {
F_2 ( 1 , L_18 , V_6 ) ;
goto V_109;
}
}
} else {
V_6 = F_22 ( V_47 , V_64 ) ;
if ( V_6 ) {
F_2 ( 1 , L_19 , V_6 ) ;
goto V_109;
}
}
V_104 = V_49 + sizeof( struct V_106 ) ;
V_105 = V_47 -> V_52 . V_14 ;
V_108 = V_47 -> V_52 . V_13 ;
V_47 -> V_52 . V_13 = F_16 ( V_104 + V_105 , V_53 ) ;
if ( ! V_47 -> V_52 . V_13 ) {
V_6 = V_54 ;
V_47 -> V_52 . V_14 = 0 ;
F_2 ( 1 , L_20 , V_10 ) ;
goto V_109;
}
V_47 -> V_52 . V_14 += V_104 ;
V_107 = (struct V_106 * )
( V_47 -> V_52 . V_13 + V_49 ) ;
V_107 -> V_110 = F_8 ( 0x00000101 ) ;
V_107 -> V_111 = 0 ;
V_107 -> time = F_27 ( F_28 ( V_82 ) ) ;
F_38 ( & V_107 -> V_112 , sizeof( V_107 -> V_112 ) ) ;
V_107 -> V_113 = 0 ;
memcpy ( V_47 -> V_52 . V_13 + V_104 , V_108 , V_105 ) ;
V_6 = F_32 ( V_47 , V_87 , V_64 ) ;
if ( V_6 ) {
F_2 ( 1 , L_21 , V_6 ) ;
goto V_109;
}
V_6 = F_36 ( V_47 , V_87 ) ;
if ( V_6 ) {
F_2 ( 1 , L_22 , V_6 ) ;
goto V_109;
}
F_33 ( V_47 -> V_4 -> V_8 . V_93 ,
V_87 , V_99 ) ;
V_6 = F_3 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_23 , V_10 ) ;
goto V_109;
}
F_4 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
V_47 -> V_52 . V_13 + V_49 ,
V_99 ) ;
V_6 = F_6 ( & V_47 -> V_4 -> V_8 . V_92 -> V_11 ,
V_47 -> V_52 . V_13 ) ;
V_109:
F_35 ( V_108 ) ;
return V_6 ;
}
int
F_39 ( struct V_46 * V_47 )
{
int V_6 ;
struct V_114 * V_115 ;
struct V_116 V_117 , V_118 ;
struct V_119 V_120 ;
unsigned char V_121 [ V_49 ] ;
F_38 ( V_121 , V_49 ) ;
V_115 = F_40 ( L_24 , 0 , V_122 ) ;
if ( F_41 ( V_115 ) ) {
V_6 = F_42 ( V_115 ) ;
F_2 ( 1 , L_25 ) ;
return V_6 ;
}
V_120 . V_123 = V_115 ;
F_43 ( V_115 , V_47 -> V_52 . V_13 ,
V_49 ) ;
F_44 ( & V_117 , V_121 , V_49 ) ;
F_44 ( & V_118 , V_47 -> V_102 -> V_124 , V_125 ) ;
V_6 = F_45 ( & V_120 , & V_118 , & V_117 , V_125 ) ;
if ( V_6 ) {
F_2 ( 1 , L_26 , V_6 ) ;
F_46 ( V_115 ) ;
return V_6 ;
}
memcpy ( V_47 -> V_52 . V_13 , V_121 , V_49 ) ;
V_47 -> V_52 . V_14 = V_49 ;
F_46 ( V_115 ) ;
return 0 ;
}
void
F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_8 . V_126 )
F_48 ( V_4 -> V_8 . V_126 ) ;
if ( V_4 -> V_8 . V_93 )
F_48 ( V_4 -> V_8 . V_93 ) ;
F_35 ( V_4 -> V_8 . V_92 ) ;
F_35 ( V_4 -> V_8 . V_9 ) ;
}
int
F_49 ( struct V_3 * V_4 )
{
int V_6 ;
unsigned int V_67 ;
V_4 -> V_8 . V_93 = F_50 ( L_27 , 0 , 0 ) ;
if ( F_41 ( V_4 -> V_8 . V_93 ) ) {
F_2 ( 1 , L_28 ) ;
return F_42 ( V_4 -> V_8 . V_93 ) ;
}
V_4 -> V_8 . V_126 = F_50 ( L_29 , 0 , 0 ) ;
if ( F_41 ( V_4 -> V_8 . V_126 ) ) {
F_2 ( 1 , L_30 ) ;
V_6 = F_42 ( V_4 -> V_8 . V_126 ) ;
goto V_127;
}
V_67 = sizeof( struct V_128 ) +
F_51 ( V_4 -> V_8 . V_93 ) ;
V_4 -> V_8 . V_92 = F_16 ( V_67 , V_53 ) ;
if ( ! V_4 -> V_8 . V_92 ) {
F_2 ( 1 , L_31 ) ;
V_6 = - V_54 ;
goto V_129;
}
V_4 -> V_8 . V_92 -> V_11 . V_123 = V_4 -> V_8 . V_93 ;
V_4 -> V_8 . V_92 -> V_11 . V_130 = 0x0 ;
V_67 = sizeof( struct V_128 ) +
F_51 ( V_4 -> V_8 . V_126 ) ;
V_4 -> V_8 . V_9 = F_16 ( V_67 , V_53 ) ;
if ( ! V_4 -> V_8 . V_9 ) {
F_2 ( 1 , L_32 ) ;
V_6 = - V_54 ;
goto V_131;
}
V_4 -> V_8 . V_9 -> V_11 . V_123 = V_4 -> V_8 . V_126 ;
V_4 -> V_8 . V_9 -> V_11 . V_130 = 0x0 ;
return 0 ;
V_131:
F_35 ( V_4 -> V_8 . V_92 ) ;
V_129:
F_48 ( V_4 -> V_8 . V_126 ) ;
V_127:
F_48 ( V_4 -> V_8 . V_93 ) ;
return V_6 ;
}
