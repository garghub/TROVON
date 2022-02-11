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
V_6 = F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_4 -> V_12 . V_13 , V_4 -> V_12 . V_14 ) ;
if ( V_6 ) {
F_2 ( 1 , L_3 , V_10 ) ;
return V_6 ;
}
V_6 = F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_2 -> V_15 , F_5 ( V_2 -> V_16 ) ) ;
if ( V_6 ) {
F_2 ( 1 , L_4 , V_10 ) ;
return V_6 ;
}
V_6 = F_6 ( & V_4 -> V_8 . V_9 -> V_11 , V_5 ) ;
if ( V_6 )
F_2 ( 1 , L_5 , V_10 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * V_17 )
{
int V_6 = 0 ;
char V_18 [ 20 ] ;
if ( ( V_2 == NULL ) || ( V_4 == NULL ) )
return - V_7 ;
if ( ! ( V_2 -> V_19 & V_20 ) ||
V_4 -> V_21 == V_22 )
return V_6 ;
if ( ! V_4 -> V_23 ) {
strncpy ( V_2 -> V_24 . V_25 , L_6 , 8 ) ;
return V_6 ;
}
V_2 -> V_24 . V_26 . V_27 =
F_8 ( V_4 -> V_28 ) ;
V_2 -> V_24 . V_26 . V_29 = 0 ;
* V_17 = V_4 -> V_28 ++ ;
V_4 -> V_28 ++ ;
V_6 = F_1 ( V_2 , V_4 , V_18 ) ;
if ( V_6 )
memset ( V_2 -> V_24 . V_25 , 0 , 8 ) ;
else
memcpy ( V_2 -> V_24 . V_25 , V_18 , 8 ) ;
return V_6 ;
}
static int F_9 ( const struct V_30 * V_31 , int V_32 ,
struct V_3 * V_4 , char * V_5 )
{
int V_33 ;
int V_6 ;
if ( V_31 == NULL || V_5 == NULL || V_4 == NULL )
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
V_6 = F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_4 -> V_12 . V_13 , V_4 -> V_12 . V_14 ) ;
if ( V_6 ) {
F_2 ( 1 , L_3 , V_10 ) ;
return V_6 ;
}
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
if ( V_31 [ V_33 ] . V_34 == 0 )
continue;
if ( V_31 [ V_33 ] . V_35 == NULL ) {
F_2 ( 1 , L_7 ) ;
return - V_36 ;
}
if ( V_33 == 0 ) {
if ( V_31 [ 0 ] . V_34 <= 8 )
break;
V_6 =
F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_31 [ V_33 ] . V_35 + 4 , V_31 [ V_33 ] . V_34 - 4 ) ;
} else {
V_6 =
F_4 ( & V_4 -> V_8 . V_9 -> V_11 ,
V_31 [ V_33 ] . V_35 , V_31 [ V_33 ] . V_34 ) ;
}
if ( V_6 ) {
F_2 ( 1 , L_4 ,
V_10 ) ;
return V_6 ;
}
}
V_6 = F_6 ( & V_4 -> V_8 . V_9 -> V_11 , V_5 ) ;
if ( V_6 )
F_2 ( 1 , L_5 , V_10 ) ;
return V_6 ;
}
int F_10 ( struct V_30 * V_31 , int V_32 , struct V_3 * V_4 ,
T_1 * V_17 )
{
int V_6 = 0 ;
char V_18 [ 20 ] ;
struct V_1 * V_2 = V_31 [ 0 ] . V_35 ;
if ( ( V_2 == NULL ) || ( V_4 == NULL ) )
return - V_7 ;
if ( ! ( V_2 -> V_19 & V_20 ) ||
V_4 -> V_21 == V_22 )
return V_6 ;
if ( ! V_4 -> V_23 ) {
strncpy ( V_2 -> V_24 . V_25 , L_6 , 8 ) ;
return V_6 ;
}
V_2 -> V_24 . V_26 . V_27 =
F_8 ( V_4 -> V_28 ) ;
V_2 -> V_24 . V_26 . V_29 = 0 ;
* V_17 = V_4 -> V_28 ++ ;
V_4 -> V_28 ++ ;
V_6 = F_9 ( V_31 , V_32 , V_4 , V_18 ) ;
if ( V_6 )
memset ( V_2 -> V_24 . V_25 , 0 , 8 ) ;
else
memcpy ( V_2 -> V_24 . V_25 , V_18 , 8 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_37 )
{
unsigned int V_6 ;
char V_38 [ 8 ] ;
char V_39 [ 20 ] ;
if ( V_2 == NULL || V_4 == NULL )
return - V_7 ;
if ( ! V_4 -> V_23 )
return 0 ;
if ( V_2 -> V_40 == V_41 ) {
struct V_42 * V_43 =
(struct V_42 * ) V_2 ;
if ( V_43 -> V_44 & V_45 )
return 0 ;
}
if ( memcmp ( V_2 -> V_24 . V_25 , L_8 , 8 ) == 0 )
F_12 ( 1 , L_9 ,
V_2 -> V_40 ) ;
memcpy ( V_38 , V_2 -> V_24 . V_25 , 8 ) ;
V_2 -> V_24 . V_26 . V_27 =
F_8 ( V_37 ) ;
V_2 -> V_24 . V_26 . V_29 = 0 ;
F_13 ( & V_4 -> V_46 ) ;
V_6 = F_1 ( V_2 , V_4 ,
V_39 ) ;
F_14 ( & V_4 -> V_46 ) ;
if ( V_6 )
return V_6 ;
if ( memcmp ( V_38 , V_39 , 8 ) )
return - V_47 ;
else
return 0 ;
}
int F_15 ( struct V_48 * V_49 )
{
int V_6 = 0 ;
unsigned int V_50 = V_51 + V_52 ;
char V_53 [ V_51 ] ;
if ( ! V_49 )
return - V_7 ;
V_49 -> V_54 . V_13 = F_16 ( V_50 , V_55 ) ;
if ( ! V_49 -> V_54 . V_13 ) {
F_2 ( 1 , L_10 , V_50 ) ;
return - V_56 ;
}
V_49 -> V_54 . V_14 = V_50 ;
V_6 = F_17 ( V_49 -> V_57 , V_49 -> V_4 -> V_58 ,
V_49 -> V_54 . V_13 + V_51 ) ;
if ( V_6 ) {
F_12 ( 1 , L_11 ,
V_10 , V_6 ) ;
return V_6 ;
}
V_6 = F_18 ( V_49 -> V_57 , V_53 ) ;
if ( V_6 ) {
F_12 ( 1 , L_12 , V_10 , V_6 ) ;
return V_6 ;
}
V_6 = F_19 ( V_49 -> V_54 . V_13 , V_53 , V_51 ) ;
if ( V_6 )
F_12 ( 1 , L_13 ,
V_10 , V_6 ) ;
return V_6 ;
}
int F_20 ( const char * V_57 , const char * V_58 , bool V_59 ,
char * V_60 )
{
int V_33 ;
int V_6 ;
char V_61 [ V_62 ] ;
memset ( V_61 , 0 , V_62 ) ;
if ( V_57 )
strncpy ( V_61 , V_57 , V_62 ) ;
if ( ! V_59 && V_63 & V_64 ) {
memset ( V_60 , 0 , V_51 ) ;
memcpy ( V_60 , V_61 ,
V_62 ) ;
return 0 ;
}
for ( V_33 = 0 ; V_33 < V_62 ; V_33 ++ )
V_61 [ V_33 ] = toupper ( V_61 [ V_33 ] ) ;
V_6 = F_21 ( V_61 , V_58 , V_60 ) ;
return V_6 ;
}
static int
F_22 ( struct V_48 * V_49 , const struct V_65 * V_66 )
{
unsigned int V_67 ;
unsigned int V_68 = 2 * sizeof( struct V_69 ) ;
char * V_70 = L_14 ;
unsigned char * V_71 ;
struct V_69 * V_72 ;
if ( ! V_49 -> V_73 ) {
V_49 -> V_73 = F_23 ( V_70 , V_55 ) ;
if ( ! V_49 -> V_73 )
return - V_56 ;
}
V_67 = strlen ( V_49 -> V_73 ) ;
V_49 -> V_54 . V_14 = V_68 + 2 * V_67 ;
V_49 -> V_54 . V_13 = F_24 ( V_49 -> V_54 . V_14 , V_55 ) ;
if ( ! V_49 -> V_54 . V_13 ) {
V_49 -> V_54 . V_14 = 0 ;
F_2 ( 1 , L_15 ) ;
return - V_56 ;
}
V_71 = V_49 -> V_54 . V_13 ;
V_72 = (struct V_69 * ) V_71 ;
V_72 -> type = F_25 ( V_74 ) ;
V_72 -> V_75 = F_25 ( 2 * V_67 ) ;
V_71 = ( unsigned char * ) V_72 + sizeof( struct V_69 ) ;
F_26 ( ( V_76 * ) V_71 , V_49 -> V_73 , V_67 , V_66 ) ;
return 0 ;
}
static int
F_27 ( struct V_48 * V_49 , const struct V_65 * V_66 )
{
unsigned int V_77 ;
unsigned int type ;
unsigned int V_78 = sizeof( struct V_69 ) ;
unsigned char * V_71 ;
unsigned char * V_79 ;
struct V_69 * V_72 ;
if ( ! V_49 -> V_54 . V_14 || ! V_49 -> V_54 . V_13 )
return 0 ;
V_71 = V_49 -> V_54 . V_13 ;
V_79 = V_71 + V_49 -> V_54 . V_14 ;
while ( V_71 + V_78 < V_79 ) {
V_72 = (struct V_69 * ) V_71 ;
type = F_28 ( V_72 -> type ) ;
if ( type == V_80 )
break;
V_71 += 2 ;
V_77 = F_28 ( V_72 -> V_75 ) ;
V_71 += 2 ;
if ( V_71 + V_77 > V_79 )
break;
if ( type == V_74 ) {
if ( ! V_77 )
break;
if ( ! V_49 -> V_73 ) {
V_49 -> V_73 =
F_16 ( V_77 + 1 , V_55 ) ;
if ( ! V_49 -> V_73 )
return - V_56 ;
F_29 ( V_49 -> V_73 ,
( V_76 * ) V_71 , V_77 , V_77 ,
V_66 , false ) ;
break;
}
}
V_71 += V_77 ;
}
return 0 ;
}
static int F_30 ( struct V_48 * V_49 , char * V_81 ,
const struct V_65 * V_66 )
{
int V_6 = 0 ;
int V_14 ;
char V_82 [ V_83 ] ;
T_2 * V_84 ;
T_2 * V_85 ;
T_2 * V_4 ;
if ( ! V_49 -> V_4 -> V_8 . V_86 ) {
F_2 ( 1 , L_16 ) ;
return - 1 ;
}
F_18 ( V_49 -> V_57 , V_82 ) ;
V_6 = F_31 ( V_49 -> V_4 -> V_8 . V_87 , V_82 ,
V_83 ) ;
if ( V_6 ) {
F_2 ( 1 , L_17 , V_10 ) ;
return V_6 ;
}
V_6 = F_3 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_18 ) ;
return V_6 ;
}
V_14 = strlen ( V_49 -> V_88 ) ;
V_84 = F_16 ( 2 + ( V_14 * 2 ) , V_55 ) ;
if ( V_84 == NULL ) {
F_2 ( 1 , L_19 ) ;
V_6 = - V_56 ;
return V_6 ;
}
V_14 = F_26 ( ( V_76 * ) V_84 , V_49 -> V_88 , V_14 , V_66 ) ;
F_32 ( V_84 ) ;
V_6 = F_4 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
( char * ) V_84 , 2 * V_14 ) ;
F_33 ( V_84 ) ;
if ( V_6 ) {
F_2 ( 1 , L_20 , V_10 ) ;
return V_6 ;
}
if ( V_49 -> V_73 ) {
V_14 = strlen ( V_49 -> V_73 ) ;
V_85 = F_16 ( 2 + ( V_14 * 2 ) , V_55 ) ;
if ( V_85 == NULL ) {
F_2 ( 1 , L_21 ) ;
V_6 = - V_56 ;
return V_6 ;
}
V_14 = F_26 ( ( V_76 * ) V_85 , V_49 -> V_73 , V_14 ,
V_66 ) ;
V_6 =
F_4 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
( char * ) V_85 , 2 * V_14 ) ;
F_33 ( V_85 ) ;
if ( V_6 ) {
F_2 ( 1 , L_22 ,
V_10 ) ;
return V_6 ;
}
} else if ( V_49 -> V_89 ) {
V_14 = strlen ( V_49 -> V_89 ) ;
V_4 = F_16 ( 2 + ( V_14 * 2 ) , V_55 ) ;
if ( V_4 == NULL ) {
F_2 ( 1 , L_23 ) ;
V_6 = - V_56 ;
return V_6 ;
}
V_14 = F_26 ( ( V_76 * ) V_4 , V_49 -> V_89 , V_14 ,
V_66 ) ;
V_6 =
F_4 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
( char * ) V_4 , 2 * V_14 ) ;
F_33 ( V_4 ) ;
if ( V_6 ) {
F_2 ( 1 , L_24 ,
V_10 ) ;
return V_6 ;
}
}
V_6 = F_6 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
V_81 ) ;
if ( V_6 )
F_2 ( 1 , L_5 , V_10 ) ;
return V_6 ;
}
static int
F_34 ( const struct V_48 * V_49 , char * V_81 )
{
int V_6 ;
unsigned int V_90 = V_51 + 8 ;
if ( ! V_49 -> V_4 -> V_8 . V_86 ) {
F_2 ( 1 , L_16 ) ;
return - 1 ;
}
V_6 = F_31 ( V_49 -> V_4 -> V_8 . V_87 ,
V_81 , V_91 ) ;
if ( V_6 ) {
F_2 ( 1 , L_25 , V_10 ) ;
return V_6 ;
}
V_6 = F_3 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_26 ) ;
return V_6 ;
}
if ( V_49 -> V_4 -> V_92 == V_93 )
memcpy ( V_49 -> V_54 . V_13 + V_90 ,
V_49 -> V_94 -> V_58 , V_95 ) ;
else
memcpy ( V_49 -> V_54 . V_13 + V_90 ,
V_49 -> V_4 -> V_58 , V_95 ) ;
V_6 = F_4 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
V_49 -> V_54 . V_13 + V_90 , V_49 -> V_54 . V_14 - V_90 ) ;
if ( V_6 ) {
F_2 ( 1 , L_3 , V_10 ) ;
return V_6 ;
}
V_6 = F_6 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
V_49 -> V_54 . V_13 + V_51 ) ;
if ( V_6 )
F_2 ( 1 , L_5 , V_10 ) ;
return V_6 ;
}
int
F_35 ( struct V_48 * V_49 , const struct V_65 * V_66 )
{
int V_6 ;
int V_96 ;
unsigned int V_97 ;
struct V_98 * V_99 ;
char V_81 [ 16 ] ;
unsigned char * V_100 = NULL ;
if ( V_49 -> V_4 -> V_92 == V_93 ) {
if ( ! V_49 -> V_73 ) {
V_6 = F_27 ( V_49 , V_66 ) ;
if ( V_6 ) {
F_2 ( 1 , L_27 , V_6 ) ;
goto V_101;
}
}
} else {
V_6 = F_22 ( V_49 , V_66 ) ;
if ( V_6 ) {
F_2 ( 1 , L_28 , V_6 ) ;
goto V_101;
}
}
V_96 = V_51 + sizeof( struct V_98 ) ;
V_97 = V_49 -> V_54 . V_14 ;
V_100 = V_49 -> V_54 . V_13 ;
V_49 -> V_54 . V_13 = F_16 ( V_96 + V_97 , V_55 ) ;
if ( ! V_49 -> V_54 . V_13 ) {
V_6 = V_56 ;
V_49 -> V_54 . V_14 = 0 ;
F_2 ( 1 , L_29 , V_10 ) ;
goto V_101;
}
V_49 -> V_54 . V_14 += V_96 ;
V_99 = (struct V_98 * )
( V_49 -> V_54 . V_13 + V_51 ) ;
V_99 -> V_102 = F_8 ( 0x00000101 ) ;
V_99 -> V_103 = 0 ;
V_99 -> time = F_36 ( F_37 ( V_104 ) ) ;
F_38 ( & V_99 -> V_105 , sizeof( V_99 -> V_105 ) ) ;
V_99 -> V_106 = 0 ;
memcpy ( V_49 -> V_54 . V_13 + V_96 , V_100 , V_97 ) ;
V_6 = F_30 ( V_49 , V_81 , V_66 ) ;
if ( V_6 ) {
F_2 ( 1 , L_30 , V_6 ) ;
goto V_101;
}
V_6 = F_34 ( V_49 , V_81 ) ;
if ( V_6 ) {
F_2 ( 1 , L_31 , V_6 ) ;
goto V_101;
}
V_6 = F_31 ( V_49 -> V_4 -> V_8 . V_87 ,
V_81 , V_91 ) ;
if ( V_6 ) {
F_2 ( 1 , L_25 , V_10 ) ;
goto V_101;
}
V_6 = F_3 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ) ;
if ( V_6 ) {
F_2 ( 1 , L_32 , V_10 ) ;
goto V_101;
}
V_6 = F_4 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
V_49 -> V_54 . V_13 + V_51 ,
V_91 ) ;
if ( V_6 ) {
F_2 ( 1 , L_3 , V_10 ) ;
goto V_101;
}
V_6 = F_6 ( & V_49 -> V_4 -> V_8 . V_86 -> V_11 ,
V_49 -> V_54 . V_13 ) ;
if ( V_6 )
F_2 ( 1 , L_5 , V_10 ) ;
V_101:
F_33 ( V_100 ) ;
return V_6 ;
}
int
F_39 ( struct V_48 * V_49 )
{
int V_6 ;
struct V_107 * V_108 ;
struct V_109 V_110 , V_111 ;
struct V_112 V_113 ;
unsigned char V_114 [ V_51 ] ;
F_38 ( V_114 , V_51 ) ;
V_108 = F_40 ( L_33 , 0 , V_115 ) ;
if ( F_41 ( V_108 ) ) {
V_6 = F_42 ( V_108 ) ;
F_2 ( 1 , L_34 ) ;
return V_6 ;
}
V_113 . V_116 = V_108 ;
V_6 = F_43 ( V_108 , V_49 -> V_54 . V_13 ,
V_51 ) ;
if ( V_6 ) {
F_2 ( 1 , L_35 , V_10 ) ;
return V_6 ;
}
F_44 ( & V_110 , V_114 , V_51 ) ;
F_44 ( & V_111 , V_49 -> V_94 -> V_117 , V_118 ) ;
V_6 = F_45 ( & V_113 , & V_111 , & V_110 , V_118 ) ;
if ( V_6 ) {
F_2 ( 1 , L_36 , V_6 ) ;
F_46 ( V_108 ) ;
return V_6 ;
}
memcpy ( V_49 -> V_54 . V_13 , V_114 , V_51 ) ;
V_49 -> V_54 . V_14 = V_51 ;
F_46 ( V_108 ) ;
return V_6 ;
}
void
F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_8 . V_119 )
F_48 ( V_4 -> V_8 . V_119 ) ;
if ( V_4 -> V_8 . V_87 )
F_48 ( V_4 -> V_8 . V_87 ) ;
F_33 ( V_4 -> V_8 . V_86 ) ;
F_33 ( V_4 -> V_8 . V_9 ) ;
}
int
F_49 ( struct V_3 * V_4 )
{
int V_6 ;
unsigned int V_68 ;
V_4 -> V_8 . V_87 = F_50 ( L_37 , 0 , 0 ) ;
if ( F_41 ( V_4 -> V_8 . V_87 ) ) {
F_2 ( 1 , L_38 ) ;
return F_42 ( V_4 -> V_8 . V_87 ) ;
}
V_4 -> V_8 . V_119 = F_50 ( L_39 , 0 , 0 ) ;
if ( F_41 ( V_4 -> V_8 . V_119 ) ) {
F_2 ( 1 , L_40 ) ;
V_6 = F_42 ( V_4 -> V_8 . V_119 ) ;
goto V_120;
}
V_68 = sizeof( struct V_121 ) +
F_51 ( V_4 -> V_8 . V_87 ) ;
V_4 -> V_8 . V_86 = F_16 ( V_68 , V_55 ) ;
if ( ! V_4 -> V_8 . V_86 ) {
F_2 ( 1 , L_41 ) ;
V_6 = - V_56 ;
goto V_122;
}
V_4 -> V_8 . V_86 -> V_11 . V_116 = V_4 -> V_8 . V_87 ;
V_4 -> V_8 . V_86 -> V_11 . V_123 = 0x0 ;
V_68 = sizeof( struct V_121 ) +
F_51 ( V_4 -> V_8 . V_119 ) ;
V_4 -> V_8 . V_9 = F_16 ( V_68 , V_55 ) ;
if ( ! V_4 -> V_8 . V_9 ) {
F_2 ( 1 , L_42 ) ;
V_6 = - V_56 ;
goto V_124;
}
V_4 -> V_8 . V_9 -> V_11 . V_116 = V_4 -> V_8 . V_119 ;
V_4 -> V_8 . V_9 -> V_11 . V_123 = 0x0 ;
return 0 ;
V_124:
F_33 ( V_4 -> V_8 . V_86 ) ;
V_122:
F_48 ( V_4 -> V_8 . V_119 ) ;
V_120:
F_48 ( V_4 -> V_8 . V_87 ) ;
return V_6 ;
}
