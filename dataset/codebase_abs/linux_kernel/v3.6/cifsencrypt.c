static int F_1 ( const struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , char * V_6 )
{
int V_7 ;
int V_8 ;
if ( V_2 == NULL || V_6 == NULL || V_5 == NULL )
return - V_9 ;
if ( ! V_5 -> V_10 . V_11 ) {
F_2 ( 1 , L_1 , V_12 ) ;
return - 1 ;
}
V_8 = F_3 ( & V_5 -> V_10 . V_11 -> V_13 ) ;
if ( V_8 ) {
F_2 ( 1 , L_2 , V_12 ) ;
return V_8 ;
}
V_8 = F_4 ( & V_5 -> V_10 . V_11 -> V_13 ,
V_5 -> V_14 . V_15 , V_5 -> V_14 . V_16 ) ;
if ( V_8 ) {
F_2 ( 1 , L_3 , V_12 ) ;
return V_8 ;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
if ( V_2 [ V_7 ] . V_17 == 0 )
continue;
if ( V_2 [ V_7 ] . V_18 == NULL ) {
F_2 ( 1 , L_4 ) ;
return - V_19 ;
}
if ( V_7 == 0 ) {
if ( V_2 [ 0 ] . V_17 <= 8 )
break;
V_8 =
F_4 ( & V_5 -> V_10 . V_11 -> V_13 ,
V_2 [ V_7 ] . V_18 + 4 , V_2 [ V_7 ] . V_17 - 4 ) ;
} else {
V_8 =
F_4 ( & V_5 -> V_10 . V_11 -> V_13 ,
V_2 [ V_7 ] . V_18 , V_2 [ V_7 ] . V_17 ) ;
}
if ( V_8 ) {
F_2 ( 1 , L_5 ,
V_12 ) ;
return V_8 ;
}
}
V_8 = F_5 ( & V_5 -> V_10 . V_11 -> V_13 , V_6 ) ;
if ( V_8 )
F_2 ( 1 , L_6 , V_12 ) ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 ,
T_1 * V_20 )
{
int V_8 = 0 ;
char V_21 [ 20 ] ;
struct V_22 * V_23 = (struct V_22 * ) V_2 [ 0 ] . V_18 ;
if ( ( V_23 == NULL ) || ( V_5 == NULL ) )
return - V_9 ;
if ( ! ( V_23 -> V_24 & V_25 ) ||
V_5 -> V_26 == V_27 )
return V_8 ;
if ( ! V_5 -> V_28 ) {
memcpy ( V_23 -> V_29 . V_30 , L_7 , 8 ) ;
return V_8 ;
}
V_23 -> V_29 . V_31 . V_32 =
F_7 ( V_5 -> V_33 ) ;
V_23 -> V_29 . V_31 . V_34 = 0 ;
* V_20 = V_5 -> V_33 ++ ;
V_5 -> V_33 ++ ;
V_8 = F_1 ( V_2 , V_3 , V_5 , V_21 ) ;
if ( V_8 )
memset ( V_23 -> V_29 . V_30 , 0 , 8 ) ;
else
memcpy ( V_23 -> V_29 . V_30 , V_21 , 8 ) ;
return V_8 ;
}
int F_8 ( struct V_22 * V_23 , struct V_4 * V_5 ,
T_1 * V_20 )
{
struct V_1 V_2 ;
V_2 . V_18 = V_23 ;
V_2 . V_17 = F_9 ( V_23 -> V_35 ) + 4 ;
return F_6 ( & V_2 , 1 , V_5 ,
V_20 ) ;
}
int F_10 ( struct V_1 * V_2 , unsigned int V_36 ,
struct V_4 * V_5 ,
T_1 V_37 )
{
unsigned int V_8 ;
char V_38 [ 8 ] ;
char V_39 [ 20 ] ;
struct V_22 * V_23 = (struct V_22 * ) V_2 [ 0 ] . V_18 ;
if ( V_23 == NULL || V_5 == NULL )
return - V_9 ;
if ( ! V_5 -> V_28 )
return 0 ;
if ( V_23 -> V_40 == V_41 ) {
struct V_42 * V_43 =
(struct V_42 * ) V_23 ;
if ( V_43 -> V_44 & V_45 )
return 0 ;
}
if ( memcmp ( V_23 -> V_29 . V_30 , L_8 , 8 ) == 0 )
F_11 ( 1 , L_9 ,
V_23 -> V_40 ) ;
memcpy ( V_38 , V_23 -> V_29 . V_30 , 8 ) ;
V_23 -> V_29 . V_31 . V_32 =
F_7 ( V_37 ) ;
V_23 -> V_29 . V_31 . V_34 = 0 ;
F_12 ( & V_5 -> V_46 ) ;
V_8 = F_1 ( V_2 , V_36 , V_5 ,
V_39 ) ;
F_13 ( & V_5 -> V_46 ) ;
if ( V_8 )
return V_8 ;
if ( memcmp ( V_38 , V_39 , 8 ) )
return - V_47 ;
else
return 0 ;
}
int F_14 ( struct V_48 * V_49 , const struct V_50 * V_51 )
{
int V_8 = 0 ;
unsigned int V_52 = V_53 + V_54 ;
char V_55 [ V_53 ] ;
if ( ! V_49 )
return - V_9 ;
V_49 -> V_56 . V_15 = F_15 ( V_52 , V_57 ) ;
if ( ! V_49 -> V_56 . V_15 ) {
F_2 ( 1 , L_10 , V_52 ) ;
return - V_58 ;
}
V_49 -> V_56 . V_16 = V_52 ;
V_8 = F_16 ( V_49 -> V_59 , V_49 -> V_5 -> V_60 ,
V_49 -> V_56 . V_15 + V_53 , V_51 ) ;
if ( V_8 ) {
F_11 ( 1 , L_11 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_17 ( V_49 -> V_59 , V_55 , V_51 ) ;
if ( V_8 ) {
F_11 ( 1 , L_12 , V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_18 ( V_49 -> V_56 . V_15 , V_55 , V_53 ) ;
if ( V_8 )
F_11 ( 1 , L_13 ,
V_12 , V_8 ) ;
return V_8 ;
}
int F_19 ( const char * V_59 , const char * V_60 , bool V_61 ,
char * V_62 )
{
int V_7 ;
int V_8 ;
char V_63 [ V_64 ] ;
memset ( V_63 , 0 , V_64 ) ;
if ( V_59 )
strncpy ( V_63 , V_59 , V_64 ) ;
if ( ! V_61 && V_65 & V_66 ) {
memset ( V_62 , 0 , V_53 ) ;
memcpy ( V_62 , V_63 ,
V_64 ) ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < V_64 ; V_7 ++ )
V_63 [ V_7 ] = toupper ( V_63 [ V_7 ] ) ;
V_8 = F_20 ( V_63 , V_60 , V_62 ) ;
return V_8 ;
}
static int
F_21 ( struct V_48 * V_49 , const struct V_50 * V_51 )
{
unsigned int V_67 ;
unsigned int V_68 = 2 * sizeof( struct V_69 ) ;
char * V_70 = L_14 ;
unsigned char * V_71 ;
struct V_69 * V_72 ;
if ( ! V_49 -> V_73 ) {
V_49 -> V_73 = F_22 ( V_70 , V_57 ) ;
if ( ! V_49 -> V_73 )
return - V_58 ;
}
V_67 = strlen ( V_49 -> V_73 ) ;
V_49 -> V_56 . V_16 = V_68 + 2 * V_67 ;
V_49 -> V_56 . V_15 = F_23 ( V_49 -> V_56 . V_16 , V_57 ) ;
if ( ! V_49 -> V_56 . V_15 ) {
V_49 -> V_56 . V_16 = 0 ;
F_2 ( 1 , L_15 ) ;
return - V_58 ;
}
V_71 = V_49 -> V_56 . V_15 ;
V_72 = (struct V_69 * ) V_71 ;
V_72 -> type = F_24 ( V_74 ) ;
V_72 -> V_75 = F_24 ( 2 * V_67 ) ;
V_71 = ( unsigned char * ) V_72 + sizeof( struct V_69 ) ;
F_25 ( ( V_76 * ) V_71 , V_49 -> V_73 , V_67 , V_51 ) ;
return 0 ;
}
static int
F_26 ( struct V_48 * V_49 , const struct V_50 * V_51 )
{
unsigned int V_77 ;
unsigned int type ;
unsigned int V_78 = sizeof( struct V_69 ) ;
unsigned char * V_71 ;
unsigned char * V_79 ;
struct V_69 * V_72 ;
if ( ! V_49 -> V_56 . V_16 || ! V_49 -> V_56 . V_15 )
return 0 ;
V_71 = V_49 -> V_56 . V_15 ;
V_79 = V_71 + V_49 -> V_56 . V_16 ;
while ( V_71 + V_78 < V_79 ) {
V_72 = (struct V_69 * ) V_71 ;
type = F_27 ( V_72 -> type ) ;
if ( type == V_80 )
break;
V_71 += 2 ;
V_77 = F_27 ( V_72 -> V_75 ) ;
V_71 += 2 ;
if ( V_71 + V_77 > V_79 )
break;
if ( type == V_74 ) {
if ( ! V_77 )
break;
if ( ! V_49 -> V_73 ) {
V_49 -> V_73 =
F_15 ( V_77 + 1 , V_57 ) ;
if ( ! V_49 -> V_73 )
return - V_58 ;
F_28 ( V_49 -> V_73 ,
( V_76 * ) V_71 , V_77 , V_77 ,
V_51 , false ) ;
break;
}
}
V_71 += V_77 ;
}
return 0 ;
}
static int F_29 ( struct V_48 * V_49 , char * V_81 ,
const struct V_50 * V_51 )
{
int V_8 = 0 ;
int V_16 ;
char V_82 [ V_83 ] ;
T_2 * V_84 ;
T_2 * V_85 ;
T_2 * V_5 ;
if ( ! V_49 -> V_5 -> V_10 . V_86 ) {
F_2 ( 1 , L_16 ) ;
return - 1 ;
}
F_17 ( V_49 -> V_59 , V_82 , V_51 ) ;
V_8 = F_30 ( V_49 -> V_5 -> V_10 . V_87 , V_82 ,
V_83 ) ;
if ( V_8 ) {
F_2 ( 1 , L_17 , V_12 ) ;
return V_8 ;
}
V_8 = F_3 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ) ;
if ( V_8 ) {
F_2 ( 1 , L_18 ) ;
return V_8 ;
}
V_16 = V_49 -> V_88 ? strlen ( V_49 -> V_88 ) : 0 ;
V_84 = F_15 ( 2 + ( V_16 * 2 ) , V_57 ) ;
if ( V_84 == NULL ) {
F_2 ( 1 , L_19 ) ;
V_8 = - V_58 ;
return V_8 ;
}
if ( V_16 ) {
V_16 = F_25 ( ( V_76 * ) V_84 , V_49 -> V_88 , V_16 , V_51 ) ;
F_31 ( V_84 ) ;
} else {
memset ( V_84 , '\0' , 2 ) ;
}
V_8 = F_4 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
( char * ) V_84 , 2 * V_16 ) ;
F_32 ( V_84 ) ;
if ( V_8 ) {
F_2 ( 1 , L_20 , V_12 ) ;
return V_8 ;
}
if ( V_49 -> V_73 ) {
V_16 = strlen ( V_49 -> V_73 ) ;
V_85 = F_15 ( 2 + ( V_16 * 2 ) , V_57 ) ;
if ( V_85 == NULL ) {
F_2 ( 1 , L_21 ) ;
V_8 = - V_58 ;
return V_8 ;
}
V_16 = F_25 ( ( V_76 * ) V_85 , V_49 -> V_73 , V_16 ,
V_51 ) ;
V_8 =
F_4 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
( char * ) V_85 , 2 * V_16 ) ;
F_32 ( V_85 ) ;
if ( V_8 ) {
F_2 ( 1 , L_22 ,
V_12 ) ;
return V_8 ;
}
} else if ( V_49 -> V_89 ) {
V_16 = strlen ( V_49 -> V_89 ) ;
V_5 = F_15 ( 2 + ( V_16 * 2 ) , V_57 ) ;
if ( V_5 == NULL ) {
F_2 ( 1 , L_23 ) ;
V_8 = - V_58 ;
return V_8 ;
}
V_16 = F_25 ( ( V_76 * ) V_5 , V_49 -> V_89 , V_16 ,
V_51 ) ;
V_8 =
F_4 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
( char * ) V_5 , 2 * V_16 ) ;
F_32 ( V_5 ) ;
if ( V_8 ) {
F_2 ( 1 , L_24 ,
V_12 ) ;
return V_8 ;
}
}
V_8 = F_5 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
V_81 ) ;
if ( V_8 )
F_2 ( 1 , L_6 , V_12 ) ;
return V_8 ;
}
static int
F_33 ( const struct V_48 * V_49 , char * V_81 )
{
int V_8 ;
unsigned int V_90 = V_53 + 8 ;
if ( ! V_49 -> V_5 -> V_10 . V_86 ) {
F_2 ( 1 , L_16 ) ;
return - 1 ;
}
V_8 = F_30 ( V_49 -> V_5 -> V_10 . V_87 ,
V_81 , V_91 ) ;
if ( V_8 ) {
F_2 ( 1 , L_25 , V_12 ) ;
return V_8 ;
}
V_8 = F_3 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ) ;
if ( V_8 ) {
F_2 ( 1 , L_26 ) ;
return V_8 ;
}
if ( V_49 -> V_5 -> V_92 == V_93 )
memcpy ( V_49 -> V_56 . V_15 + V_90 ,
V_49 -> V_94 -> V_60 , V_95 ) ;
else
memcpy ( V_49 -> V_56 . V_15 + V_90 ,
V_49 -> V_5 -> V_60 , V_95 ) ;
V_8 = F_4 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
V_49 -> V_56 . V_15 + V_90 , V_49 -> V_56 . V_16 - V_90 ) ;
if ( V_8 ) {
F_2 ( 1 , L_3 , V_12 ) ;
return V_8 ;
}
V_8 = F_5 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
V_49 -> V_56 . V_15 + V_53 ) ;
if ( V_8 )
F_2 ( 1 , L_6 , V_12 ) ;
return V_8 ;
}
int
F_34 ( struct V_48 * V_49 , const struct V_50 * V_51 )
{
int V_8 ;
int V_96 ;
unsigned int V_97 ;
struct V_98 * V_99 ;
char V_81 [ 16 ] ;
unsigned char * V_100 = NULL ;
if ( V_49 -> V_5 -> V_92 == V_93 ) {
if ( ! V_49 -> V_73 ) {
V_8 = F_26 ( V_49 , V_51 ) ;
if ( V_8 ) {
F_2 ( 1 , L_27 , V_8 ) ;
goto V_101;
}
}
} else {
V_8 = F_21 ( V_49 , V_51 ) ;
if ( V_8 ) {
F_2 ( 1 , L_28 , V_8 ) ;
goto V_101;
}
}
V_96 = V_53 + sizeof( struct V_98 ) ;
V_97 = V_49 -> V_56 . V_16 ;
V_100 = V_49 -> V_56 . V_15 ;
V_49 -> V_56 . V_15 = F_15 ( V_96 + V_97 , V_57 ) ;
if ( ! V_49 -> V_56 . V_15 ) {
V_8 = V_58 ;
V_49 -> V_56 . V_16 = 0 ;
F_2 ( 1 , L_29 , V_12 ) ;
goto V_101;
}
V_49 -> V_56 . V_16 += V_96 ;
V_99 = (struct V_98 * )
( V_49 -> V_56 . V_15 + V_53 ) ;
V_99 -> V_102 = F_7 ( 0x00000101 ) ;
V_99 -> V_103 = 0 ;
V_99 -> time = F_35 ( F_36 ( V_104 ) ) ;
F_37 ( & V_99 -> V_105 , sizeof( V_99 -> V_105 ) ) ;
V_99 -> V_106 = 0 ;
memcpy ( V_49 -> V_56 . V_15 + V_96 , V_100 , V_97 ) ;
V_8 = F_29 ( V_49 , V_81 , V_51 ) ;
if ( V_8 ) {
F_2 ( 1 , L_30 , V_8 ) ;
goto V_101;
}
V_8 = F_33 ( V_49 , V_81 ) ;
if ( V_8 ) {
F_2 ( 1 , L_31 , V_8 ) ;
goto V_101;
}
V_8 = F_30 ( V_49 -> V_5 -> V_10 . V_87 ,
V_81 , V_91 ) ;
if ( V_8 ) {
F_2 ( 1 , L_25 , V_12 ) ;
goto V_101;
}
V_8 = F_3 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ) ;
if ( V_8 ) {
F_2 ( 1 , L_32 , V_12 ) ;
goto V_101;
}
V_8 = F_4 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
V_49 -> V_56 . V_15 + V_53 ,
V_91 ) ;
if ( V_8 ) {
F_2 ( 1 , L_3 , V_12 ) ;
goto V_101;
}
V_8 = F_5 ( & V_49 -> V_5 -> V_10 . V_86 -> V_13 ,
V_49 -> V_56 . V_15 ) ;
if ( V_8 )
F_2 ( 1 , L_6 , V_12 ) ;
V_101:
F_32 ( V_100 ) ;
return V_8 ;
}
int
F_38 ( struct V_48 * V_49 )
{
int V_8 ;
struct V_107 * V_108 ;
struct V_109 V_110 , V_111 ;
struct V_112 V_113 ;
unsigned char V_114 [ V_53 ] ;
F_37 ( V_114 , V_53 ) ;
V_108 = F_39 ( L_33 , 0 , V_115 ) ;
if ( F_40 ( V_108 ) ) {
V_8 = F_41 ( V_108 ) ;
F_2 ( 1 , L_34 ) ;
return V_8 ;
}
V_113 . V_116 = V_108 ;
V_8 = F_42 ( V_108 , V_49 -> V_56 . V_15 ,
V_53 ) ;
if ( V_8 ) {
F_2 ( 1 , L_35 , V_12 ) ;
return V_8 ;
}
F_43 ( & V_110 , V_114 , V_53 ) ;
F_43 ( & V_111 , V_49 -> V_94 -> V_117 , V_118 ) ;
V_8 = F_44 ( & V_113 , & V_111 , & V_110 , V_118 ) ;
if ( V_8 ) {
F_2 ( 1 , L_36 , V_8 ) ;
F_45 ( V_108 ) ;
return V_8 ;
}
memcpy ( V_49 -> V_56 . V_15 , V_114 , V_53 ) ;
V_49 -> V_56 . V_16 = V_53 ;
F_45 ( V_108 ) ;
return V_8 ;
}
void
F_46 ( struct V_4 * V_5 )
{
if ( V_5 -> V_10 . V_119 )
F_47 ( V_5 -> V_10 . V_119 ) ;
if ( V_5 -> V_10 . V_87 )
F_47 ( V_5 -> V_10 . V_87 ) ;
F_32 ( V_5 -> V_10 . V_86 ) ;
F_32 ( V_5 -> V_10 . V_11 ) ;
}
int
F_48 ( struct V_4 * V_5 )
{
int V_8 ;
unsigned int V_68 ;
V_5 -> V_10 . V_87 = F_49 ( L_37 , 0 , 0 ) ;
if ( F_40 ( V_5 -> V_10 . V_87 ) ) {
F_2 ( 1 , L_38 ) ;
return F_41 ( V_5 -> V_10 . V_87 ) ;
}
V_5 -> V_10 . V_119 = F_49 ( L_39 , 0 , 0 ) ;
if ( F_40 ( V_5 -> V_10 . V_119 ) ) {
F_2 ( 1 , L_40 ) ;
V_8 = F_41 ( V_5 -> V_10 . V_119 ) ;
goto V_120;
}
V_68 = sizeof( struct V_121 ) +
F_50 ( V_5 -> V_10 . V_87 ) ;
V_5 -> V_10 . V_86 = F_15 ( V_68 , V_57 ) ;
if ( ! V_5 -> V_10 . V_86 ) {
F_2 ( 1 , L_41 ) ;
V_8 = - V_58 ;
goto V_122;
}
V_5 -> V_10 . V_86 -> V_13 . V_116 = V_5 -> V_10 . V_87 ;
V_5 -> V_10 . V_86 -> V_13 . V_123 = 0x0 ;
V_68 = sizeof( struct V_121 ) +
F_50 ( V_5 -> V_10 . V_119 ) ;
V_5 -> V_10 . V_11 = F_15 ( V_68 , V_57 ) ;
if ( ! V_5 -> V_10 . V_11 ) {
F_2 ( 1 , L_42 ) ;
V_8 = - V_58 ;
goto V_124;
}
V_5 -> V_10 . V_11 -> V_13 . V_116 = V_5 -> V_10 . V_119 ;
V_5 -> V_10 . V_11 -> V_13 . V_123 = 0x0 ;
return 0 ;
V_124:
F_32 ( V_5 -> V_10 . V_86 ) ;
V_122:
F_47 ( V_5 -> V_10 . V_119 ) ;
V_120:
F_47 ( V_5 -> V_10 . V_87 ) ;
return V_8 ;
}
