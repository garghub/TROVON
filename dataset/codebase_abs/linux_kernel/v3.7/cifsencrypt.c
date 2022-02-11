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
F_2 ( 1 , L_1 , V_16 ) ;
return - 1 ;
}
V_7 = F_3 ( & V_4 -> V_14 . V_15 -> V_17 ) ;
if ( V_7 ) {
F_2 ( 1 , L_2 , V_16 ) ;
return V_7 ;
}
V_7 = F_4 ( & V_4 -> V_14 . V_15 -> V_17 ,
V_4 -> V_18 . V_19 , V_4 -> V_18 . V_20 ) ;
if ( V_7 ) {
F_2 ( 1 , L_3 , V_16 ) ;
return V_7 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
if ( V_9 [ V_6 ] . V_21 == 0 )
continue;
if ( V_9 [ V_6 ] . V_22 == NULL ) {
F_2 ( 1 , L_4 ) ;
return - V_23 ;
}
if ( V_6 == 0 ) {
if ( V_9 [ 0 ] . V_21 <= 8 )
break;
V_7 =
F_4 ( & V_4 -> V_14 . V_15 -> V_17 ,
V_9 [ V_6 ] . V_22 + 4 , V_9 [ V_6 ] . V_21 - 4 ) ;
} else {
V_7 =
F_4 ( & V_4 -> V_14 . V_15 -> V_17 ,
V_9 [ V_6 ] . V_22 , V_9 [ V_6 ] . V_21 ) ;
}
if ( V_7 ) {
F_2 ( 1 , L_5 ,
V_16 ) ;
return V_7 ;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_24 ; V_6 ++ ) {
struct V_8 V_25 ;
F_5 ( V_2 , V_6 , & V_25 ) ;
F_4 ( & V_4 -> V_14 . V_15 -> V_17 ,
V_25 . V_22 , V_25 . V_21 ) ;
F_6 ( V_2 -> V_26 [ V_6 ] ) ;
}
V_7 = F_7 ( & V_4 -> V_14 . V_15 -> V_17 , V_5 ) ;
if ( V_7 )
F_2 ( 1 , L_6 , V_16 ) ;
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_27 )
{
int V_7 = 0 ;
char V_28 [ 20 ] ;
struct V_29 * V_30 = (struct V_29 * ) V_2 -> V_10 [ 0 ] . V_22 ;
if ( ( V_30 == NULL ) || ( V_4 == NULL ) )
return - V_13 ;
if ( ! ( V_30 -> V_31 & V_32 ) ||
V_4 -> V_33 == V_34 )
return V_7 ;
if ( ! V_4 -> V_35 ) {
memcpy ( V_30 -> V_36 . V_37 , L_7 , 8 ) ;
return V_7 ;
}
V_30 -> V_36 . V_38 . V_39 =
F_9 ( V_4 -> V_40 ) ;
V_30 -> V_36 . V_38 . V_41 = 0 ;
* V_27 = V_4 -> V_40 ++ ;
V_4 -> V_40 ++ ;
V_7 = F_1 ( V_2 , V_4 , V_28 ) ;
if ( V_7 )
memset ( V_30 -> V_36 . V_37 , 0 , 8 ) ;
else
memcpy ( V_30 -> V_36 . V_37 , V_28 , 8 ) ;
return V_7 ;
}
int F_10 ( struct V_8 * V_9 , int V_11 , struct V_3 * V_4 ,
T_1 * V_42 )
{
struct V_1 V_2 = { . V_10 = V_9 ,
. V_12 = V_11 } ;
return F_8 ( & V_2 , V_4 , V_42 ) ;
}
int F_11 ( struct V_29 * V_30 , struct V_3 * V_4 ,
T_1 * V_27 )
{
struct V_8 V_9 ;
V_9 . V_22 = V_30 ;
V_9 . V_21 = F_12 ( V_30 -> V_43 ) + 4 ;
return F_10 ( & V_9 , 1 , V_4 ,
V_27 ) ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_44 )
{
unsigned int V_7 ;
char V_45 [ 8 ] ;
char V_46 [ 20 ] ;
struct V_29 * V_30 = (struct V_29 * ) V_2 -> V_10 [ 0 ] . V_22 ;
if ( V_30 == NULL || V_4 == NULL )
return - V_13 ;
if ( ! V_4 -> V_35 )
return 0 ;
if ( V_30 -> V_47 == V_48 ) {
struct V_49 * V_50 =
(struct V_49 * ) V_30 ;
if ( V_50 -> V_51 & V_52 )
return 0 ;
}
if ( memcmp ( V_30 -> V_36 . V_37 , L_8 , 8 ) == 0 )
F_14 ( 1 , L_9 ,
V_30 -> V_47 ) ;
memcpy ( V_45 , V_30 -> V_36 . V_37 , 8 ) ;
V_30 -> V_36 . V_38 . V_39 =
F_9 ( V_44 ) ;
V_30 -> V_36 . V_38 . V_41 = 0 ;
F_15 ( & V_4 -> V_53 ) ;
V_7 = F_1 ( V_2 , V_4 , V_46 ) ;
F_16 ( & V_4 -> V_53 ) ;
if ( V_7 )
return V_7 ;
if ( memcmp ( V_45 , V_46 , 8 ) )
return - V_54 ;
else
return 0 ;
}
int F_17 ( struct V_55 * V_56 , const struct V_57 * V_58 )
{
int V_7 = 0 ;
unsigned int V_59 = V_60 + V_61 ;
char V_62 [ V_60 ] ;
if ( ! V_56 )
return - V_13 ;
V_56 -> V_63 . V_19 = F_18 ( V_59 , V_64 ) ;
if ( ! V_56 -> V_63 . V_19 ) {
F_2 ( 1 , L_10 , V_59 ) ;
return - V_65 ;
}
V_56 -> V_63 . V_20 = V_59 ;
V_7 = F_19 ( V_56 -> V_66 , V_56 -> V_4 -> V_67 ,
V_56 -> V_63 . V_19 + V_60 , V_58 ) ;
if ( V_7 ) {
F_14 ( 1 , L_11 ,
V_16 , V_7 ) ;
return V_7 ;
}
V_7 = F_20 ( V_56 -> V_66 , V_62 , V_58 ) ;
if ( V_7 ) {
F_14 ( 1 , L_12 , V_16 , V_7 ) ;
return V_7 ;
}
V_7 = F_21 ( V_56 -> V_63 . V_19 , V_62 , V_60 ) ;
if ( V_7 )
F_14 ( 1 , L_13 ,
V_16 , V_7 ) ;
return V_7 ;
}
int F_22 ( const char * V_66 , const char * V_67 , bool V_68 ,
char * V_69 )
{
int V_6 ;
int V_7 ;
char V_70 [ V_71 ] ;
memset ( V_70 , 0 , V_71 ) ;
if ( V_66 )
strncpy ( V_70 , V_66 , V_71 ) ;
if ( ! V_68 && V_72 & V_73 ) {
memset ( V_69 , 0 , V_60 ) ;
memcpy ( V_69 , V_70 ,
V_71 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_71 ; V_6 ++ )
V_70 [ V_6 ] = toupper ( V_70 [ V_6 ] ) ;
V_7 = F_23 ( V_70 , V_67 , V_69 ) ;
return V_7 ;
}
static int
F_24 ( struct V_55 * V_56 , const struct V_57 * V_58 )
{
unsigned int V_74 ;
unsigned int V_75 = 2 * sizeof( struct V_76 ) ;
char * V_77 = L_14 ;
unsigned char * V_78 ;
struct V_76 * V_79 ;
if ( ! V_56 -> V_80 ) {
V_56 -> V_80 = F_25 ( V_77 , V_64 ) ;
if ( ! V_56 -> V_80 )
return - V_65 ;
}
V_74 = strlen ( V_56 -> V_80 ) ;
V_56 -> V_63 . V_20 = V_75 + 2 * V_74 ;
V_56 -> V_63 . V_19 = F_26 ( V_56 -> V_63 . V_20 , V_64 ) ;
if ( ! V_56 -> V_63 . V_19 ) {
V_56 -> V_63 . V_20 = 0 ;
F_2 ( 1 , L_15 ) ;
return - V_65 ;
}
V_78 = V_56 -> V_63 . V_19 ;
V_79 = (struct V_76 * ) V_78 ;
V_79 -> type = F_27 ( V_81 ) ;
V_79 -> V_82 = F_27 ( 2 * V_74 ) ;
V_78 = ( unsigned char * ) V_79 + sizeof( struct V_76 ) ;
F_28 ( ( V_83 * ) V_78 , V_56 -> V_80 , V_74 , V_58 ) ;
return 0 ;
}
static int
F_29 ( struct V_55 * V_56 , const struct V_57 * V_58 )
{
unsigned int V_84 ;
unsigned int type ;
unsigned int V_85 = sizeof( struct V_76 ) ;
unsigned char * V_78 ;
unsigned char * V_86 ;
struct V_76 * V_79 ;
if ( ! V_56 -> V_63 . V_20 || ! V_56 -> V_63 . V_19 )
return 0 ;
V_78 = V_56 -> V_63 . V_19 ;
V_86 = V_78 + V_56 -> V_63 . V_20 ;
while ( V_78 + V_85 < V_86 ) {
V_79 = (struct V_76 * ) V_78 ;
type = F_30 ( V_79 -> type ) ;
if ( type == V_87 )
break;
V_78 += 2 ;
V_84 = F_30 ( V_79 -> V_82 ) ;
V_78 += 2 ;
if ( V_78 + V_84 > V_86 )
break;
if ( type == V_81 ) {
if ( ! V_84 )
break;
if ( ! V_56 -> V_80 ) {
V_56 -> V_80 =
F_18 ( V_84 + 1 , V_64 ) ;
if ( ! V_56 -> V_80 )
return - V_65 ;
F_31 ( V_56 -> V_80 ,
( V_83 * ) V_78 , V_84 , V_84 ,
V_58 , false ) ;
break;
}
}
V_78 += V_84 ;
}
return 0 ;
}
static int F_32 ( struct V_55 * V_56 , char * V_88 ,
const struct V_57 * V_58 )
{
int V_7 = 0 ;
int V_20 ;
char V_89 [ V_90 ] ;
T_2 * V_91 ;
T_2 * V_92 ;
T_2 * V_4 ;
if ( ! V_56 -> V_4 -> V_14 . V_93 ) {
F_2 ( 1 , L_16 ) ;
return - 1 ;
}
F_20 ( V_56 -> V_66 , V_89 , V_58 ) ;
V_7 = F_33 ( V_56 -> V_4 -> V_14 . V_94 , V_89 ,
V_90 ) ;
if ( V_7 ) {
F_2 ( 1 , L_17 , V_16 ) ;
return V_7 ;
}
V_7 = F_3 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ) ;
if ( V_7 ) {
F_2 ( 1 , L_18 ) ;
return V_7 ;
}
V_20 = V_56 -> V_95 ? strlen ( V_56 -> V_95 ) : 0 ;
V_91 = F_18 ( 2 + ( V_20 * 2 ) , V_64 ) ;
if ( V_91 == NULL ) {
F_2 ( 1 , L_19 ) ;
V_7 = - V_65 ;
return V_7 ;
}
if ( V_20 ) {
V_20 = F_28 ( ( V_83 * ) V_91 , V_56 -> V_95 , V_20 , V_58 ) ;
F_34 ( V_91 ) ;
} else {
memset ( V_91 , '\0' , 2 ) ;
}
V_7 = F_4 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
( char * ) V_91 , 2 * V_20 ) ;
F_35 ( V_91 ) ;
if ( V_7 ) {
F_2 ( 1 , L_20 , V_16 ) ;
return V_7 ;
}
if ( V_56 -> V_80 ) {
V_20 = strlen ( V_56 -> V_80 ) ;
V_92 = F_18 ( 2 + ( V_20 * 2 ) , V_64 ) ;
if ( V_92 == NULL ) {
F_2 ( 1 , L_21 ) ;
V_7 = - V_65 ;
return V_7 ;
}
V_20 = F_28 ( ( V_83 * ) V_92 , V_56 -> V_80 , V_20 ,
V_58 ) ;
V_7 =
F_4 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
( char * ) V_92 , 2 * V_20 ) ;
F_35 ( V_92 ) ;
if ( V_7 ) {
F_2 ( 1 , L_22 ,
V_16 ) ;
return V_7 ;
}
} else if ( V_56 -> V_96 ) {
V_20 = strlen ( V_56 -> V_96 ) ;
V_4 = F_18 ( 2 + ( V_20 * 2 ) , V_64 ) ;
if ( V_4 == NULL ) {
F_2 ( 1 , L_23 ) ;
V_7 = - V_65 ;
return V_7 ;
}
V_20 = F_28 ( ( V_83 * ) V_4 , V_56 -> V_96 , V_20 ,
V_58 ) ;
V_7 =
F_4 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
( char * ) V_4 , 2 * V_20 ) ;
F_35 ( V_4 ) ;
if ( V_7 ) {
F_2 ( 1 , L_24 ,
V_16 ) ;
return V_7 ;
}
}
V_7 = F_7 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
V_88 ) ;
if ( V_7 )
F_2 ( 1 , L_6 , V_16 ) ;
return V_7 ;
}
static int
F_36 ( const struct V_55 * V_56 , char * V_88 )
{
int V_7 ;
unsigned int V_97 = V_60 + 8 ;
if ( ! V_56 -> V_4 -> V_14 . V_93 ) {
F_2 ( 1 , L_16 ) ;
return - 1 ;
}
V_7 = F_33 ( V_56 -> V_4 -> V_14 . V_94 ,
V_88 , V_98 ) ;
if ( V_7 ) {
F_2 ( 1 , L_25 , V_16 ) ;
return V_7 ;
}
V_7 = F_3 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ) ;
if ( V_7 ) {
F_2 ( 1 , L_26 ) ;
return V_7 ;
}
if ( V_56 -> V_4 -> V_99 == V_100 )
memcpy ( V_56 -> V_63 . V_19 + V_97 ,
V_56 -> V_101 -> V_67 , V_102 ) ;
else
memcpy ( V_56 -> V_63 . V_19 + V_97 ,
V_56 -> V_4 -> V_67 , V_102 ) ;
V_7 = F_4 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
V_56 -> V_63 . V_19 + V_97 , V_56 -> V_63 . V_20 - V_97 ) ;
if ( V_7 ) {
F_2 ( 1 , L_3 , V_16 ) ;
return V_7 ;
}
V_7 = F_7 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
V_56 -> V_63 . V_19 + V_60 ) ;
if ( V_7 )
F_2 ( 1 , L_6 , V_16 ) ;
return V_7 ;
}
int
F_37 ( struct V_55 * V_56 , const struct V_57 * V_58 )
{
int V_7 ;
int V_103 ;
unsigned int V_104 ;
struct V_105 * V_106 ;
char V_88 [ 16 ] ;
unsigned char * V_107 = NULL ;
if ( V_56 -> V_4 -> V_99 == V_100 ) {
if ( ! V_56 -> V_80 ) {
V_7 = F_29 ( V_56 , V_58 ) ;
if ( V_7 ) {
F_2 ( 1 , L_27 , V_7 ) ;
goto V_108;
}
}
} else {
V_7 = F_24 ( V_56 , V_58 ) ;
if ( V_7 ) {
F_2 ( 1 , L_28 , V_7 ) ;
goto V_108;
}
}
V_103 = V_60 + sizeof( struct V_105 ) ;
V_104 = V_56 -> V_63 . V_20 ;
V_107 = V_56 -> V_63 . V_19 ;
V_56 -> V_63 . V_19 = F_18 ( V_103 + V_104 , V_64 ) ;
if ( ! V_56 -> V_63 . V_19 ) {
V_7 = V_65 ;
V_56 -> V_63 . V_20 = 0 ;
F_2 ( 1 , L_29 , V_16 ) ;
goto V_108;
}
V_56 -> V_63 . V_20 += V_103 ;
V_106 = (struct V_105 * )
( V_56 -> V_63 . V_19 + V_60 ) ;
V_106 -> V_109 = F_9 ( 0x00000101 ) ;
V_106 -> V_110 = 0 ;
V_106 -> time = F_38 ( F_39 ( V_111 ) ) ;
F_40 ( & V_106 -> V_112 , sizeof( V_106 -> V_112 ) ) ;
V_106 -> V_113 = 0 ;
memcpy ( V_56 -> V_63 . V_19 + V_103 , V_107 , V_104 ) ;
V_7 = F_32 ( V_56 , V_88 , V_58 ) ;
if ( V_7 ) {
F_2 ( 1 , L_30 , V_7 ) ;
goto V_108;
}
V_7 = F_36 ( V_56 , V_88 ) ;
if ( V_7 ) {
F_2 ( 1 , L_31 , V_7 ) ;
goto V_108;
}
V_7 = F_33 ( V_56 -> V_4 -> V_14 . V_94 ,
V_88 , V_98 ) ;
if ( V_7 ) {
F_2 ( 1 , L_25 , V_16 ) ;
goto V_108;
}
V_7 = F_3 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ) ;
if ( V_7 ) {
F_2 ( 1 , L_32 , V_16 ) ;
goto V_108;
}
V_7 = F_4 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
V_56 -> V_63 . V_19 + V_60 ,
V_98 ) ;
if ( V_7 ) {
F_2 ( 1 , L_3 , V_16 ) ;
goto V_108;
}
V_7 = F_7 ( & V_56 -> V_4 -> V_14 . V_93 -> V_17 ,
V_56 -> V_63 . V_19 ) ;
if ( V_7 )
F_2 ( 1 , L_6 , V_16 ) ;
V_108:
F_35 ( V_107 ) ;
return V_7 ;
}
int
F_41 ( struct V_55 * V_56 )
{
int V_7 ;
struct V_114 * V_115 ;
struct V_116 V_117 , V_118 ;
struct V_119 V_120 ;
unsigned char V_121 [ V_60 ] ;
F_40 ( V_121 , V_60 ) ;
V_115 = F_42 ( L_33 , 0 , V_122 ) ;
if ( F_43 ( V_115 ) ) {
V_7 = F_44 ( V_115 ) ;
F_2 ( 1 , L_34 ) ;
return V_7 ;
}
V_120 . V_123 = V_115 ;
V_7 = F_45 ( V_115 , V_56 -> V_63 . V_19 ,
V_60 ) ;
if ( V_7 ) {
F_2 ( 1 , L_35 , V_16 ) ;
return V_7 ;
}
F_46 ( & V_117 , V_121 , V_60 ) ;
F_46 ( & V_118 , V_56 -> V_101 -> V_124 , V_125 ) ;
V_7 = F_47 ( & V_120 , & V_118 , & V_117 , V_125 ) ;
if ( V_7 ) {
F_2 ( 1 , L_36 , V_7 ) ;
F_48 ( V_115 ) ;
return V_7 ;
}
memcpy ( V_56 -> V_63 . V_19 , V_121 , V_60 ) ;
V_56 -> V_63 . V_20 = V_60 ;
F_48 ( V_115 ) ;
return V_7 ;
}
void
F_49 ( struct V_3 * V_4 )
{
if ( V_4 -> V_14 . V_126 )
F_50 ( V_4 -> V_14 . V_126 ) ;
if ( V_4 -> V_14 . V_127 )
F_50 ( V_4 -> V_14 . V_127 ) ;
if ( V_4 -> V_14 . V_94 )
F_50 ( V_4 -> V_14 . V_94 ) ;
F_35 ( V_4 -> V_14 . V_128 ) ;
F_35 ( V_4 -> V_14 . V_93 ) ;
F_35 ( V_4 -> V_14 . V_15 ) ;
}
int
F_51 ( struct V_3 * V_4 )
{
int V_7 ;
unsigned int V_75 ;
V_4 -> V_14 . V_94 = F_52 ( L_37 , 0 , 0 ) ;
if ( F_43 ( V_4 -> V_14 . V_94 ) ) {
F_2 ( 1 , L_38 ) ;
return F_44 ( V_4 -> V_14 . V_94 ) ;
}
V_4 -> V_14 . V_127 = F_52 ( L_39 , 0 , 0 ) ;
if ( F_43 ( V_4 -> V_14 . V_127 ) ) {
F_2 ( 1 , L_40 ) ;
V_7 = F_44 ( V_4 -> V_14 . V_127 ) ;
goto V_129;
}
V_4 -> V_14 . V_126 = F_52 ( L_41 , 0 , 0 ) ;
if ( F_43 ( V_4 -> V_14 . V_126 ) ) {
F_2 ( 1 , L_42 ) ;
V_7 = F_44 ( V_4 -> V_14 . V_126 ) ;
goto V_130;
}
V_75 = sizeof( struct V_131 ) +
F_53 ( V_4 -> V_14 . V_94 ) ;
V_4 -> V_14 . V_93 = F_18 ( V_75 , V_64 ) ;
if ( ! V_4 -> V_14 . V_93 ) {
F_2 ( 1 , L_43 ) ;
V_7 = - V_65 ;
goto V_132;
}
V_4 -> V_14 . V_93 -> V_17 . V_123 = V_4 -> V_14 . V_94 ;
V_4 -> V_14 . V_93 -> V_17 . V_133 = 0x0 ;
V_75 = sizeof( struct V_131 ) +
F_53 ( V_4 -> V_14 . V_127 ) ;
V_4 -> V_14 . V_15 = F_18 ( V_75 , V_64 ) ;
if ( ! V_4 -> V_14 . V_15 ) {
F_2 ( 1 , L_44 ) ;
V_7 = - V_65 ;
goto V_134;
}
V_4 -> V_14 . V_15 -> V_17 . V_123 = V_4 -> V_14 . V_127 ;
V_4 -> V_14 . V_15 -> V_17 . V_133 = 0x0 ;
V_75 = sizeof( struct V_131 ) +
F_53 ( V_4 -> V_14 . V_126 ) ;
V_4 -> V_14 . V_128 = F_18 ( V_75 , V_64 ) ;
if ( ! V_4 -> V_14 . V_128 ) {
F_2 ( 1 , L_45 , V_16 ) ;
V_7 = - V_65 ;
goto V_135;
}
V_4 -> V_14 . V_128 -> V_17 . V_123 = V_4 -> V_14 . V_126 ;
V_4 -> V_14 . V_128 -> V_17 . V_133 = 0x0 ;
return 0 ;
V_135:
F_35 ( V_4 -> V_14 . V_15 ) ;
V_134:
F_35 ( V_4 -> V_14 . V_93 ) ;
V_132:
F_50 ( V_4 -> V_14 . V_126 ) ;
V_130:
F_50 ( V_4 -> V_14 . V_127 ) ;
V_129:
F_50 ( V_4 -> V_14 . V_94 ) ;
return V_7 ;
}
