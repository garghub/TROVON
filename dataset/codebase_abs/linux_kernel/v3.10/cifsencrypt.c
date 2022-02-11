static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 ;
int V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = V_2 -> V_12 ;
if ( V_9 == NULL || V_5 == NULL || V_4 == NULL )
return - V_13 ;
if ( ! V_4 -> V_14 . V_15 ) {
F_2 ( V_16 , L_1 , V_17 ) ;
return - 1 ;
}
V_7 = F_3 ( & V_4 -> V_14 . V_15 -> V_18 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_2 , V_17 ) ;
return V_7 ;
}
V_7 = F_4 ( & V_4 -> V_14 . V_15 -> V_18 ,
V_4 -> V_19 . V_20 , V_4 -> V_19 . V_21 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_3 , V_17 ) ;
return V_7 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
if ( V_9 [ V_6 ] . V_22 == 0 )
continue;
if ( V_9 [ V_6 ] . V_23 == NULL ) {
F_2 ( V_16 , L_4 ) ;
return - V_24 ;
}
if ( V_6 == 0 ) {
if ( V_9 [ 0 ] . V_22 <= 8 )
break;
V_7 =
F_4 ( & V_4 -> V_14 . V_15 -> V_18 ,
V_9 [ V_6 ] . V_23 + 4 , V_9 [ V_6 ] . V_22 - 4 ) ;
} else {
V_7 =
F_4 ( & V_4 -> V_14 . V_15 -> V_18 ,
V_9 [ V_6 ] . V_23 , V_9 [ V_6 ] . V_22 ) ;
}
if ( V_7 ) {
F_2 ( V_16 , L_5 ,
V_17 ) ;
return V_7 ;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_25 ; V_6 ++ ) {
struct V_8 V_26 ;
F_5 ( V_2 , V_6 , & V_26 ) ;
F_4 ( & V_4 -> V_14 . V_15 -> V_18 ,
V_26 . V_23 , V_26 . V_22 ) ;
F_6 ( V_2 -> V_27 [ V_6 ] ) ;
}
V_7 = F_7 ( & V_4 -> V_14 . V_15 -> V_18 , V_5 ) ;
if ( V_7 )
F_2 ( V_16 , L_6 , V_17 ) ;
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_28 )
{
int V_7 = 0 ;
char V_29 [ 20 ] ;
struct V_30 * V_31 = (struct V_30 * ) V_2 -> V_10 [ 0 ] . V_23 ;
if ( ( V_31 == NULL ) || ( V_4 == NULL ) )
return - V_13 ;
if ( ! ( V_31 -> V_32 & V_33 ) ||
V_4 -> V_34 == V_35 )
return V_7 ;
if ( ! V_4 -> V_36 ) {
memcpy ( V_31 -> V_37 . V_38 , L_7 , 8 ) ;
return V_7 ;
}
V_31 -> V_37 . V_39 . V_40 =
F_9 ( V_4 -> V_41 ) ;
V_31 -> V_37 . V_39 . V_42 = 0 ;
* V_28 = ++ V_4 -> V_41 ;
++ V_4 -> V_41 ;
V_7 = F_1 ( V_2 , V_4 , V_29 ) ;
if ( V_7 )
memset ( V_31 -> V_37 . V_38 , 0 , 8 ) ;
else
memcpy ( V_31 -> V_37 . V_38 , V_29 , 8 ) ;
return V_7 ;
}
int F_10 ( struct V_8 * V_9 , int V_11 , struct V_3 * V_4 ,
T_1 * V_43 )
{
struct V_1 V_2 = { . V_10 = V_9 ,
. V_12 = V_11 } ;
return F_8 ( & V_2 , V_4 , V_43 ) ;
}
int F_11 ( struct V_30 * V_31 , struct V_3 * V_4 ,
T_1 * V_28 )
{
struct V_8 V_9 ;
V_9 . V_23 = V_31 ;
V_9 . V_22 = F_12 ( V_31 -> V_44 ) + 4 ;
return F_10 ( & V_9 , 1 , V_4 ,
V_28 ) ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_45 )
{
unsigned int V_7 ;
char V_46 [ 8 ] ;
char V_47 [ 20 ] ;
struct V_30 * V_31 = (struct V_30 * ) V_2 -> V_10 [ 0 ] . V_23 ;
if ( V_31 == NULL || V_4 == NULL )
return - V_13 ;
if ( ! V_4 -> V_36 )
return 0 ;
if ( V_31 -> V_48 == V_49 ) {
struct V_50 * V_51 =
(struct V_50 * ) V_31 ;
if ( V_51 -> V_52 & V_53 )
return 0 ;
}
if ( memcmp ( V_31 -> V_37 . V_38 , L_8 , 8 ) == 0 )
F_2 ( V_54 , L_9 ,
V_31 -> V_48 ) ;
memcpy ( V_46 , V_31 -> V_37 . V_38 , 8 ) ;
V_31 -> V_37 . V_39 . V_40 =
F_9 ( V_45 ) ;
V_31 -> V_37 . V_39 . V_42 = 0 ;
F_14 ( & V_4 -> V_55 ) ;
V_7 = F_1 ( V_2 , V_4 , V_47 ) ;
F_15 ( & V_4 -> V_55 ) ;
if ( V_7 )
return V_7 ;
if ( memcmp ( V_46 , V_47 , 8 ) )
return - V_56 ;
else
return 0 ;
}
int F_16 ( struct V_57 * V_58 , const struct V_59 * V_60 )
{
int V_7 = 0 ;
unsigned int V_61 = V_62 + V_63 ;
char V_64 [ V_62 ] ;
if ( ! V_58 )
return - V_13 ;
V_58 -> V_65 . V_20 = F_17 ( V_61 , V_66 ) ;
if ( ! V_58 -> V_65 . V_20 )
return - V_67 ;
V_58 -> V_65 . V_21 = V_61 ;
V_7 = F_18 ( V_58 -> V_68 , V_58 -> V_4 -> V_69 ,
V_58 -> V_65 . V_20 + V_62 , V_60 ) ;
if ( V_7 ) {
F_2 ( V_54 , L_10 ,
V_17 , V_7 ) ;
return V_7 ;
}
V_7 = F_19 ( V_58 -> V_68 , V_64 , V_60 ) ;
if ( V_7 ) {
F_2 ( V_54 , L_11 ,
V_17 , V_7 ) ;
return V_7 ;
}
V_7 = F_20 ( V_58 -> V_65 . V_20 , V_64 , V_62 ) ;
if ( V_7 )
F_2 ( V_54 , L_12 ,
V_17 , V_7 ) ;
return V_7 ;
}
int F_21 ( const char * V_68 , const char * V_69 , bool V_70 ,
char * V_71 )
{
int V_6 ;
int V_7 ;
char V_72 [ V_73 ] ;
memset ( V_72 , 0 , V_73 ) ;
if ( V_68 )
strncpy ( V_72 , V_68 , V_73 ) ;
if ( ! V_70 && V_74 & V_75 ) {
memset ( V_71 , 0 , V_62 ) ;
memcpy ( V_71 , V_72 ,
V_73 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_73 ; V_6 ++ )
V_72 [ V_6 ] = toupper ( V_72 [ V_6 ] ) ;
V_7 = F_22 ( V_72 , V_69 , V_71 ) ;
return V_7 ;
}
static int
F_23 ( struct V_57 * V_58 , const struct V_59 * V_60 )
{
unsigned int V_76 ;
unsigned int V_77 = 2 * sizeof( struct V_78 ) ;
char * V_79 = L_13 ;
unsigned char * V_80 ;
struct V_78 * V_81 ;
if ( ! V_58 -> V_82 ) {
V_58 -> V_82 = F_24 ( V_79 , V_66 ) ;
if ( ! V_58 -> V_82 )
return - V_67 ;
}
V_76 = strlen ( V_58 -> V_82 ) ;
V_58 -> V_65 . V_21 = V_77 + 2 * V_76 ;
V_58 -> V_65 . V_20 = F_25 ( V_58 -> V_65 . V_21 , V_66 ) ;
if ( ! V_58 -> V_65 . V_20 ) {
V_58 -> V_65 . V_21 = 0 ;
return - V_67 ;
}
V_80 = V_58 -> V_65 . V_20 ;
V_81 = (struct V_78 * ) V_80 ;
V_81 -> type = F_26 ( V_83 ) ;
V_81 -> V_84 = F_26 ( 2 * V_76 ) ;
V_80 = ( unsigned char * ) V_81 + sizeof( struct V_78 ) ;
F_27 ( ( V_85 * ) V_80 , V_58 -> V_82 , V_76 , V_60 ) ;
return 0 ;
}
static int
F_28 ( struct V_57 * V_58 , const struct V_59 * V_60 )
{
unsigned int V_86 ;
unsigned int type ;
unsigned int V_87 = sizeof( struct V_78 ) ;
unsigned char * V_80 ;
unsigned char * V_88 ;
struct V_78 * V_81 ;
if ( ! V_58 -> V_65 . V_21 || ! V_58 -> V_65 . V_20 )
return 0 ;
V_80 = V_58 -> V_65 . V_20 ;
V_88 = V_80 + V_58 -> V_65 . V_21 ;
while ( V_80 + V_87 < V_88 ) {
V_81 = (struct V_78 * ) V_80 ;
type = F_29 ( V_81 -> type ) ;
if ( type == V_89 )
break;
V_80 += 2 ;
V_86 = F_29 ( V_81 -> V_84 ) ;
V_80 += 2 ;
if ( V_80 + V_86 > V_88 )
break;
if ( type == V_83 ) {
if ( ! V_86 )
break;
if ( ! V_58 -> V_82 ) {
V_58 -> V_82 =
F_17 ( V_86 + 1 , V_66 ) ;
if ( ! V_58 -> V_82 )
return - V_67 ;
F_30 ( V_58 -> V_82 ,
( V_85 * ) V_80 , V_86 , V_86 ,
V_60 , false ) ;
break;
}
}
V_80 += V_86 ;
}
return 0 ;
}
static int F_31 ( struct V_57 * V_58 , char * V_90 ,
const struct V_59 * V_60 )
{
int V_7 = 0 ;
int V_21 ;
char V_91 [ V_92 ] ;
T_2 * V_93 ;
T_2 * V_94 ;
T_2 * V_4 ;
if ( ! V_58 -> V_4 -> V_14 . V_95 ) {
F_2 ( V_16 , L_14 , V_17 ) ;
return - 1 ;
}
F_19 ( V_58 -> V_68 , V_91 , V_60 ) ;
V_7 = F_32 ( V_58 -> V_4 -> V_14 . V_96 , V_91 ,
V_92 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_15 , V_17 ) ;
return V_7 ;
}
V_7 = F_3 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_16 , V_17 ) ;
return V_7 ;
}
V_21 = V_58 -> V_97 ? strlen ( V_58 -> V_97 ) : 0 ;
V_93 = F_17 ( 2 + ( V_21 * 2 ) , V_66 ) ;
if ( V_93 == NULL ) {
V_7 = - V_67 ;
return V_7 ;
}
if ( V_21 ) {
V_21 = F_27 ( ( V_85 * ) V_93 , V_58 -> V_97 , V_21 , V_60 ) ;
F_33 ( V_93 ) ;
} else {
memset ( V_93 , '\0' , 2 ) ;
}
V_7 = F_4 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
( char * ) V_93 , 2 * V_21 ) ;
F_34 ( V_93 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_17 , V_17 ) ;
return V_7 ;
}
if ( V_58 -> V_82 ) {
V_21 = strlen ( V_58 -> V_82 ) ;
V_94 = F_17 ( 2 + ( V_21 * 2 ) , V_66 ) ;
if ( V_94 == NULL ) {
V_7 = - V_67 ;
return V_7 ;
}
V_21 = F_27 ( ( V_85 * ) V_94 , V_58 -> V_82 , V_21 ,
V_60 ) ;
V_7 =
F_4 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
( char * ) V_94 , 2 * V_21 ) ;
F_34 ( V_94 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_18 ,
V_17 ) ;
return V_7 ;
}
} else if ( V_58 -> V_98 ) {
V_21 = strlen ( V_58 -> V_98 ) ;
V_4 = F_17 ( 2 + ( V_21 * 2 ) , V_66 ) ;
if ( V_4 == NULL ) {
V_7 = - V_67 ;
return V_7 ;
}
V_21 = F_27 ( ( V_85 * ) V_4 , V_58 -> V_98 , V_21 ,
V_60 ) ;
V_7 =
F_4 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
( char * ) V_4 , 2 * V_21 ) ;
F_34 ( V_4 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_19 ,
V_17 ) ;
return V_7 ;
}
}
V_7 = F_7 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
V_90 ) ;
if ( V_7 )
F_2 ( V_16 , L_6 , V_17 ) ;
return V_7 ;
}
static int
F_35 ( const struct V_57 * V_58 , char * V_90 )
{
int V_7 ;
unsigned int V_99 = V_62 + 8 ;
if ( ! V_58 -> V_4 -> V_14 . V_95 ) {
F_2 ( V_16 , L_14 , V_17 ) ;
return - 1 ;
}
V_7 = F_32 ( V_58 -> V_4 -> V_14 . V_96 ,
V_90 , V_100 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_20 ,
V_17 ) ;
return V_7 ;
}
V_7 = F_3 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_16 , V_17 ) ;
return V_7 ;
}
if ( V_58 -> V_4 -> V_101 == V_102 )
memcpy ( V_58 -> V_65 . V_20 + V_99 ,
V_58 -> V_103 -> V_69 , V_104 ) ;
else
memcpy ( V_58 -> V_65 . V_20 + V_99 ,
V_58 -> V_4 -> V_69 , V_104 ) ;
V_7 = F_4 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
V_58 -> V_65 . V_20 + V_99 , V_58 -> V_65 . V_21 - V_99 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_3 , V_17 ) ;
return V_7 ;
}
V_7 = F_7 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
V_58 -> V_65 . V_20 + V_62 ) ;
if ( V_7 )
F_2 ( V_16 , L_6 , V_17 ) ;
return V_7 ;
}
int
F_36 ( struct V_57 * V_58 , const struct V_59 * V_60 )
{
int V_7 ;
int V_105 ;
unsigned int V_106 ;
struct V_107 * V_108 ;
char V_90 [ 16 ] ;
unsigned char * V_109 = NULL ;
if ( V_58 -> V_4 -> V_101 == V_102 ) {
if ( ! V_58 -> V_82 ) {
V_7 = F_28 ( V_58 , V_60 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_21 ,
V_7 ) ;
goto V_110;
}
}
} else {
V_7 = F_23 ( V_58 , V_60 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_22 , V_7 ) ;
goto V_110;
}
}
V_105 = V_62 + sizeof( struct V_107 ) ;
V_106 = V_58 -> V_65 . V_21 ;
V_109 = V_58 -> V_65 . V_20 ;
V_58 -> V_65 . V_20 = F_17 ( V_105 + V_106 , V_66 ) ;
if ( ! V_58 -> V_65 . V_20 ) {
V_7 = V_67 ;
V_58 -> V_65 . V_21 = 0 ;
goto V_110;
}
V_58 -> V_65 . V_21 += V_105 ;
V_108 = (struct V_107 * )
( V_58 -> V_65 . V_20 + V_62 ) ;
V_108 -> V_111 = F_9 ( 0x00000101 ) ;
V_108 -> V_112 = 0 ;
V_108 -> time = F_37 ( F_38 ( V_113 ) ) ;
F_39 ( & V_108 -> V_114 , sizeof( V_108 -> V_114 ) ) ;
V_108 -> V_115 = 0 ;
memcpy ( V_58 -> V_65 . V_20 + V_105 , V_109 , V_106 ) ;
V_7 = F_31 ( V_58 , V_90 , V_60 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_23 , V_7 ) ;
goto V_110;
}
V_7 = F_35 ( V_58 , V_90 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_24 , V_7 ) ;
goto V_110;
}
V_7 = F_32 ( V_58 -> V_4 -> V_14 . V_96 ,
V_90 , V_100 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_20 ,
V_17 ) ;
goto V_110;
}
V_7 = F_3 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_25 , V_17 ) ;
goto V_110;
}
V_7 = F_4 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
V_58 -> V_65 . V_20 + V_62 ,
V_100 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_3 , V_17 ) ;
goto V_110;
}
V_7 = F_7 ( & V_58 -> V_4 -> V_14 . V_95 -> V_18 ,
V_58 -> V_65 . V_20 ) ;
if ( V_7 )
F_2 ( V_16 , L_6 , V_17 ) ;
V_110:
F_34 ( V_109 ) ;
return V_7 ;
}
int
F_40 ( struct V_57 * V_58 )
{
int V_7 ;
struct V_116 * V_117 ;
struct V_118 V_119 , V_120 ;
struct V_121 V_122 ;
unsigned char V_123 [ V_62 ] ;
F_39 ( V_123 , V_62 ) ;
V_117 = F_41 ( L_26 , 0 , V_124 ) ;
if ( F_42 ( V_117 ) ) {
V_7 = F_43 ( V_117 ) ;
F_2 ( V_16 , L_27 ) ;
return V_7 ;
}
V_122 . V_125 = V_117 ;
V_7 = F_44 ( V_117 , V_58 -> V_65 . V_20 ,
V_62 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_28 ,
V_17 ) ;
return V_7 ;
}
F_45 ( & V_119 , V_123 , V_62 ) ;
F_45 ( & V_120 , V_58 -> V_103 -> V_126 , V_127 ) ;
V_7 = F_46 ( & V_122 , & V_120 , & V_119 , V_127 ) ;
if ( V_7 ) {
F_2 ( V_16 , L_29 , V_7 ) ;
F_47 ( V_117 ) ;
return V_7 ;
}
memcpy ( V_58 -> V_65 . V_20 , V_123 , V_62 ) ;
V_58 -> V_65 . V_21 = V_62 ;
F_47 ( V_117 ) ;
return V_7 ;
}
void
F_48 ( struct V_3 * V_4 )
{
if ( V_4 -> V_14 . V_128 )
F_49 ( V_4 -> V_14 . V_128 ) ;
if ( V_4 -> V_14 . V_129 )
F_49 ( V_4 -> V_14 . V_129 ) ;
if ( V_4 -> V_14 . V_96 )
F_49 ( V_4 -> V_14 . V_96 ) ;
F_34 ( V_4 -> V_14 . V_130 ) ;
F_34 ( V_4 -> V_14 . V_95 ) ;
F_34 ( V_4 -> V_14 . V_15 ) ;
}
int
F_50 ( struct V_3 * V_4 )
{
int V_7 ;
unsigned int V_77 ;
V_4 -> V_14 . V_96 = F_51 ( L_30 , 0 , 0 ) ;
if ( F_42 ( V_4 -> V_14 . V_96 ) ) {
F_2 ( V_16 , L_31 ) ;
return F_43 ( V_4 -> V_14 . V_96 ) ;
}
V_4 -> V_14 . V_129 = F_51 ( L_32 , 0 , 0 ) ;
if ( F_42 ( V_4 -> V_14 . V_129 ) ) {
F_2 ( V_16 , L_33 ) ;
V_7 = F_43 ( V_4 -> V_14 . V_129 ) ;
goto V_131;
}
V_4 -> V_14 . V_128 = F_51 ( L_34 , 0 , 0 ) ;
if ( F_42 ( V_4 -> V_14 . V_128 ) ) {
F_2 ( V_16 , L_35 ) ;
V_7 = F_43 ( V_4 -> V_14 . V_128 ) ;
goto V_132;
}
V_77 = sizeof( struct V_133 ) +
F_52 ( V_4 -> V_14 . V_96 ) ;
V_4 -> V_14 . V_95 = F_17 ( V_77 , V_66 ) ;
if ( ! V_4 -> V_14 . V_95 ) {
V_7 = - V_67 ;
goto V_134;
}
V_4 -> V_14 . V_95 -> V_18 . V_125 = V_4 -> V_14 . V_96 ;
V_4 -> V_14 . V_95 -> V_18 . V_135 = 0x0 ;
V_77 = sizeof( struct V_133 ) +
F_52 ( V_4 -> V_14 . V_129 ) ;
V_4 -> V_14 . V_15 = F_17 ( V_77 , V_66 ) ;
if ( ! V_4 -> V_14 . V_15 ) {
V_7 = - V_67 ;
goto V_136;
}
V_4 -> V_14 . V_15 -> V_18 . V_125 = V_4 -> V_14 . V_129 ;
V_4 -> V_14 . V_15 -> V_18 . V_135 = 0x0 ;
V_77 = sizeof( struct V_133 ) +
F_52 ( V_4 -> V_14 . V_128 ) ;
V_4 -> V_14 . V_130 = F_17 ( V_77 , V_66 ) ;
if ( ! V_4 -> V_14 . V_130 ) {
V_7 = - V_67 ;
goto V_137;
}
V_4 -> V_14 . V_130 -> V_18 . V_125 = V_4 -> V_14 . V_128 ;
V_4 -> V_14 . V_130 -> V_18 . V_135 = 0x0 ;
return 0 ;
V_137:
F_34 ( V_4 -> V_14 . V_15 ) ;
V_136:
F_34 ( V_4 -> V_14 . V_95 ) ;
V_134:
F_49 ( V_4 -> V_14 . V_128 ) ;
V_132:
F_49 ( V_4 -> V_14 . V_129 ) ;
V_131:
F_49 ( V_4 -> V_14 . V_96 ) ;
return V_7 ;
}
