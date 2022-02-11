static int
F_1 ( unsigned int V_1 , const char * V_2 , T_1 * V_3 )
{
int V_4 ;
unsigned int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_2 ( L_1 , 0 , 0 ) ;
if ( F_3 ( V_7 ) ) {
V_4 = F_4 ( V_7 ) ;
F_5 ( V_10 , L_2 ,
V_11 , V_4 ) ;
return V_4 ;
}
V_5 = sizeof( struct V_12 ) + F_6 ( V_7 ) ;
V_9 = F_7 ( V_5 , V_13 ) ;
if ( ! V_9 ) {
V_4 = - V_14 ;
goto V_15;
}
V_9 -> V_16 . V_17 = V_7 ;
V_9 -> V_16 . V_18 = 0x0 ;
V_4 = F_8 ( & V_9 -> V_16 ) ;
if ( V_4 ) {
F_5 ( V_10 , L_3 , V_11 ) ;
goto V_15;
}
V_4 = F_9 ( & V_9 -> V_16 , V_2 , V_1 ) ;
if ( V_4 ) {
F_5 ( V_10 , L_4 , V_11 ) ;
goto V_15;
}
V_4 = F_10 ( & V_9 -> V_16 , V_3 ) ;
if ( V_4 )
F_5 ( V_10 , L_5 , V_11 ) ;
V_15:
F_11 ( V_7 ) ;
F_12 ( V_9 ) ;
return V_4 ;
}
static int
F_13 ( const T_1 * V_19 , unsigned int V_20 , unsigned int * V_21 ,
char * * V_22 )
{
int V_4 ;
unsigned int V_1 ;
const char * V_23 ;
const char * V_2 ;
T_1 V_3 [ 16 ] ;
char V_24 [ 34 ] ;
if ( V_20 != V_25 )
return - V_26 ;
V_23 = ( const char * ) & V_19 [ V_27 ] ;
V_2 = ( const char * ) & V_19 [ V_28 ] ;
V_4 = sscanf ( V_19 , V_29 , & V_1 ) ;
if ( V_4 != 1 )
return - V_26 ;
V_4 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_4 ) {
F_5 ( V_30 , L_6 , V_11 , V_4 ) ;
return V_4 ;
}
snprintf ( V_24 , sizeof( V_24 ) ,
V_31 ,
F_14 ( V_3 ) ) ;
if ( strncmp ( V_23 , V_24 , 17 ) != 0 )
return - V_26 ;
if ( V_22 ) {
* V_22 = F_15 ( V_2 , V_1 , V_13 ) ;
if ( ! * V_22 )
return - V_14 ;
}
* V_21 = V_1 ;
return 0 ;
}
static int
F_16 ( T_1 * V_19 , unsigned int V_20 , const char * V_2 )
{
int V_4 ;
unsigned int V_1 ;
unsigned int V_32 ;
T_1 V_3 [ 16 ] ;
if ( V_20 != V_25 )
return - V_26 ;
V_1 = strlen ( V_2 ) ;
if ( V_1 > V_33 )
return - V_34 ;
V_4 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_4 ) {
F_5 ( V_30 , L_6 , V_11 , V_4 ) ;
return V_4 ;
}
snprintf (buf, buf_len,
CIFS_MF_SYMLINK_LEN_FORMAT CIFS_MF_SYMLINK_MD5_FORMAT,
link_len,
CIFS_MF_SYMLINK_MD5_ARGS(md5_hash)) ;
V_32 = V_28 ;
memcpy ( V_19 + V_32 , V_2 , V_1 ) ;
V_32 += V_1 ;
if ( V_32 < V_25 ) {
V_19 [ V_32 ] = '\n' ;
V_32 ++ ;
}
while ( V_32 < V_25 ) {
V_19 [ V_32 ] = ' ' ;
V_32 ++ ;
}
return 0 ;
}
bool
F_17 ( const struct V_35 * V_36 )
{
if ( ! F_18 ( V_36 -> V_37 ) )
return false ;
if ( V_36 -> V_38 != V_25 )
return false ;
return true ;
}
static int
F_19 ( const unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , const char * V_44 ,
const char * V_45 )
{
int V_4 ;
T_1 * V_19 ;
unsigned int V_46 = 0 ;
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 )
return - V_14 ;
V_4 = F_16 ( V_19 , V_25 , V_45 ) ;
if ( V_4 )
goto V_47;
V_4 = V_41 -> V_48 -> V_49 -> V_50 -> F_19 ( V_39 , V_41 , V_43 ,
V_44 , V_19 , & V_46 ) ;
if ( V_4 )
goto V_47;
if ( V_46 != V_25 )
V_4 = - V_51 ;
V_47:
F_12 ( V_19 ) ;
return V_4 ;
}
static int
F_20 ( const unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , const unsigned char * V_52 ,
char * * V_53 )
{
int V_4 ;
T_1 * V_19 = NULL ;
unsigned int V_1 = 0 ;
unsigned int V_54 = 0 ;
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 )
return - V_14 ;
if ( V_41 -> V_48 -> V_49 -> V_50 -> F_20 )
V_4 = V_41 -> V_48 -> V_49 -> V_50 -> F_20 ( V_39 , V_41 ,
V_43 , V_52 , V_19 , & V_54 ) ;
else
V_4 = - V_55 ;
if ( V_4 )
goto V_47;
if ( V_54 == 0 ) {
V_4 = - V_26 ;
goto V_47;
}
V_4 = F_13 ( V_19 , V_54 , & V_1 , V_53 ) ;
V_47:
F_12 ( V_19 ) ;
return V_4 ;
}
int
F_21 ( unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , struct V_35 * V_36 ,
const unsigned char * V_52 )
{
int V_4 ;
T_1 * V_19 = NULL ;
unsigned int V_1 = 0 ;
unsigned int V_54 = 0 ;
if ( ! F_17 ( V_36 ) )
return 0 ;
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 )
return - V_14 ;
if ( V_41 -> V_48 -> V_49 -> V_50 -> F_20 )
V_4 = V_41 -> V_48 -> V_49 -> V_50 -> F_20 ( V_39 , V_41 ,
V_43 , V_52 , V_19 , & V_54 ) ;
else
V_4 = - V_55 ;
if ( V_4 )
goto V_47;
if ( V_54 == 0 )
goto V_47;
V_4 = F_13 ( V_19 , V_54 , & V_1 , NULL ) ;
if ( V_4 == - V_26 ) {
V_4 = 0 ;
goto V_47;
}
if ( V_4 != 0 )
goto V_47;
V_36 -> V_38 = V_1 ;
V_36 -> V_37 &= ~ V_56 ;
V_36 -> V_37 |= V_57 | V_58 | V_59 | V_60 ;
V_36 -> V_61 = V_62 ;
V_47:
F_12 ( V_19 ) ;
return V_4 ;
}
int
F_22 ( unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , const unsigned char * V_52 ,
char * V_63 , unsigned int * V_64 )
{
int V_4 ;
int V_65 = 0 ;
struct V_66 V_67 ;
struct V_68 V_69 ;
struct V_70 V_71 ;
int V_72 = V_73 ;
T_2 V_74 ;
V_69 . V_41 = V_41 ;
V_69 . V_43 = V_43 ;
V_69 . V_75 = V_76 ;
V_69 . V_77 = V_78 ;
V_69 . V_79 = V_80 ;
V_69 . V_52 = V_52 ;
V_69 . V_67 = & V_67 ;
V_69 . V_81 = false ;
V_4 = F_23 ( V_39 , & V_69 , & V_65 , & V_74 ) ;
if ( V_4 )
return V_4 ;
if ( V_74 . V_82 != F_24 ( V_25 ) )
goto V_47;
V_71 . V_83 = V_67 . V_83 ;
V_71 . V_84 = V_85 -> V_86 ;
V_71 . V_41 = V_41 ;
V_71 . V_87 = 0 ;
V_71 . V_88 = V_25 ;
V_4 = F_25 ( V_39 , & V_71 , V_64 , & V_63 , & V_72 ) ;
V_47:
F_26 ( V_39 , V_41 , V_67 . V_83 ) ;
return V_4 ;
}
int
F_27 ( unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , const unsigned char * V_52 ,
char * V_63 , unsigned int * V_89 )
{
int V_4 ;
int V_65 = 0 ;
struct V_66 V_67 ;
struct V_68 V_69 ;
struct V_70 V_71 ;
int V_77 = V_78 ;
if ( F_28 ( V_43 ) )
V_77 |= V_90 ;
V_69 . V_41 = V_41 ;
V_69 . V_43 = V_43 ;
V_69 . V_75 = V_91 ;
V_69 . V_77 = V_77 ;
V_69 . V_79 = V_92 ;
V_69 . V_52 = V_52 ;
V_69 . V_67 = & V_67 ;
V_69 . V_81 = false ;
V_4 = F_23 ( V_39 , & V_69 , & V_65 , NULL ) ;
if ( V_4 )
return V_4 ;
V_71 . V_83 = V_67 . V_83 ;
V_71 . V_84 = V_85 -> V_86 ;
V_71 . V_41 = V_41 ;
V_71 . V_87 = 0 ;
V_71 . V_88 = V_25 ;
V_4 = F_29 ( V_39 , & V_71 , V_89 , V_63 , NULL , 0 ) ;
F_26 ( V_39 , V_41 , V_67 . V_83 ) ;
return V_4 ;
}
int
F_30 ( struct V_93 * V_94 , struct V_95 * V_95 ,
struct V_93 * V_96 )
{
int V_4 = - V_97 ;
unsigned int V_39 ;
char * V_98 = NULL ;
char * V_99 = NULL ;
struct V_42 * V_43 = F_31 ( V_95 -> V_100 ) ;
struct V_101 * V_102 ;
struct V_40 * V_41 ;
struct V_103 * V_49 ;
struct V_104 * V_105 ;
V_102 = F_32 ( V_43 ) ;
if ( F_3 ( V_102 ) )
return F_4 ( V_102 ) ;
V_41 = F_33 ( V_102 ) ;
V_39 = F_34 () ;
V_98 = F_35 ( V_94 ) ;
V_99 = F_35 ( V_96 ) ;
if ( ( V_98 == NULL ) || ( V_99 == NULL ) ) {
V_4 = - V_14 ;
goto V_106;
}
if ( V_41 -> V_107 )
V_4 = F_36 ( V_39 , V_41 , V_98 , V_99 ,
V_43 -> V_108 ,
V_43 -> V_109 &
V_110 ) ;
else {
V_49 = V_41 -> V_48 -> V_49 ;
if ( ! V_49 -> V_50 -> V_111 ) {
V_4 = - V_55 ;
goto V_106;
}
V_4 = V_49 -> V_50 -> V_111 ( V_39 , V_41 , V_98 , V_99 ,
V_43 ) ;
if ( ( V_4 == - V_51 ) || ( V_4 == - V_26 ) )
V_4 = - V_112 ;
}
F_37 ( V_96 ) ;
if ( V_94 -> V_113 ) {
V_105 = F_38 ( V_94 -> V_113 ) ;
if ( V_4 == 0 ) {
F_39 ( & V_94 -> V_113 -> V_114 ) ;
F_40 ( V_94 -> V_113 ) ;
F_41 ( & V_94 -> V_113 -> V_114 ) ;
}
V_105 -> time = 0 ;
}
V_106:
F_12 ( V_98 ) ;
F_12 ( V_99 ) ;
F_42 ( V_39 ) ;
F_43 ( V_102 ) ;
return V_4 ;
}
void *
F_44 ( struct V_93 * V_96 , struct V_115 * V_116 )
{
struct V_95 * V_95 = V_96 -> V_113 ;
int V_4 = - V_14 ;
unsigned int V_39 ;
char * V_117 = NULL ;
char * V_118 = NULL ;
struct V_42 * V_43 = F_31 ( V_95 -> V_100 ) ;
struct V_101 * V_102 = NULL ;
struct V_40 * V_41 ;
struct V_103 * V_49 ;
V_39 = F_34 () ;
V_102 = F_32 ( V_43 ) ;
if ( F_3 ( V_102 ) ) {
V_4 = F_4 ( V_102 ) ;
V_102 = NULL ;
goto V_47;
}
V_41 = F_33 ( V_102 ) ;
V_49 = V_41 -> V_48 -> V_49 ;
V_117 = F_35 ( V_96 ) ;
if ( ! V_117 )
goto V_47;
F_5 ( V_30 , L_7 , V_117 , V_95 ) ;
V_4 = - V_97 ;
if ( V_43 -> V_109 & V_119 )
V_4 = F_20 ( V_39 , V_41 , V_43 , V_117 ,
& V_118 ) ;
if ( V_4 != 0 && V_49 -> V_50 -> V_120 )
V_4 = V_49 -> V_50 -> V_120 ( V_39 , V_41 , V_117 ,
& V_118 , V_43 ) ;
F_12 ( V_117 ) ;
V_47:
if ( V_4 != 0 ) {
F_12 ( V_118 ) ;
V_118 = F_45 ( V_4 ) ;
}
F_42 ( V_39 ) ;
if ( V_102 )
F_43 ( V_102 ) ;
F_46 ( V_116 , V_118 ) ;
return NULL ;
}
int
F_47 ( struct V_95 * V_95 , struct V_93 * V_96 , const char * V_121 )
{
int V_4 = - V_112 ;
unsigned int V_39 ;
struct V_42 * V_43 = F_31 ( V_95 -> V_100 ) ;
struct V_101 * V_102 ;
struct V_40 * V_122 ;
char * V_117 = NULL ;
struct V_95 * V_123 = NULL ;
V_39 = F_34 () ;
V_102 = F_32 ( V_43 ) ;
if ( F_3 ( V_102 ) ) {
V_4 = F_4 ( V_102 ) ;
goto V_124;
}
V_122 = F_33 ( V_102 ) ;
V_117 = F_35 ( V_96 ) ;
if ( V_117 == NULL ) {
V_4 = - V_14 ;
goto V_124;
}
F_5 ( V_30 , L_8 , V_117 ) ;
F_5 ( V_30 , L_9 , V_121 ) ;
if ( V_43 -> V_109 & V_119 )
V_4 = F_19 ( V_39 , V_122 , V_43 , V_117 , V_121 ) ;
else if ( V_122 -> V_107 )
V_4 = F_48 ( V_39 , V_122 , V_117 , V_121 ,
V_43 -> V_108 ) ;
if ( V_4 == 0 ) {
if ( V_122 -> V_107 )
V_4 = F_49 ( & V_123 , V_117 ,
V_95 -> V_100 , V_39 ) ;
else
V_4 = F_50 ( & V_123 , V_117 , NULL ,
V_95 -> V_100 , V_39 , NULL ) ;
if ( V_4 != 0 ) {
F_5 ( V_30 , L_10 ,
V_4 ) ;
} else {
F_51 ( V_96 , V_123 ) ;
}
}
V_124:
F_12 ( V_117 ) ;
F_43 ( V_102 ) ;
F_42 ( V_39 ) ;
return V_4 ;
}
