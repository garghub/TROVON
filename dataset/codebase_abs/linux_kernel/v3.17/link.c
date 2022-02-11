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
if ( V_41 -> V_48 -> V_49 -> V_50 -> F_19 )
V_4 = V_41 -> V_48 -> V_49 -> V_50 -> F_19 ( V_39 , V_41 ,
V_43 , V_44 , V_19 , & V_46 ) ;
else
V_4 = - V_51 ;
if ( V_4 )
goto V_47;
if ( V_46 != V_25 )
V_4 = - V_52 ;
V_47:
F_12 ( V_19 ) ;
return V_4 ;
}
static int
F_20 ( const unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , const unsigned char * V_53 ,
char * * V_54 )
{
int V_4 ;
T_1 * V_19 = NULL ;
unsigned int V_1 = 0 ;
unsigned int V_55 = 0 ;
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 )
return - V_14 ;
if ( V_41 -> V_48 -> V_49 -> V_50 -> F_20 )
V_4 = V_41 -> V_48 -> V_49 -> V_50 -> F_20 ( V_39 , V_41 ,
V_43 , V_53 , V_19 , & V_55 ) ;
else
V_4 = - V_56 ;
if ( V_4 )
goto V_47;
if ( V_55 == 0 ) {
V_4 = - V_26 ;
goto V_47;
}
V_4 = F_13 ( V_19 , V_55 , & V_1 , V_54 ) ;
V_47:
F_12 ( V_19 ) ;
return V_4 ;
}
int
F_21 ( unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , struct V_35 * V_36 ,
const unsigned char * V_53 )
{
int V_4 ;
T_1 * V_19 = NULL ;
unsigned int V_1 = 0 ;
unsigned int V_55 = 0 ;
if ( ! F_17 ( V_36 ) )
return 0 ;
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 )
return - V_14 ;
if ( V_41 -> V_48 -> V_49 -> V_50 -> F_20 )
V_4 = V_41 -> V_48 -> V_49 -> V_50 -> F_20 ( V_39 , V_41 ,
V_43 , V_53 , V_19 , & V_55 ) ;
else
V_4 = - V_56 ;
if ( V_4 )
goto V_47;
if ( V_55 == 0 )
goto V_47;
V_4 = F_13 ( V_19 , V_55 , & V_1 , NULL ) ;
if ( V_4 == - V_26 ) {
V_4 = 0 ;
goto V_47;
}
if ( V_4 != 0 )
goto V_47;
V_36 -> V_38 = V_1 ;
V_36 -> V_37 &= ~ V_57 ;
V_36 -> V_37 |= V_58 | V_59 | V_60 | V_61 ;
V_36 -> V_62 = V_63 ;
V_47:
F_12 ( V_19 ) ;
return V_4 ;
}
int
F_22 ( unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , const unsigned char * V_53 ,
char * V_64 , unsigned int * V_65 )
{
int V_4 ;
int V_66 = 0 ;
struct V_67 V_68 ;
struct V_69 V_70 ;
struct V_71 V_72 ;
int V_73 = V_74 ;
T_2 V_75 ;
V_70 . V_41 = V_41 ;
V_70 . V_43 = V_43 ;
V_70 . V_76 = V_77 ;
V_70 . V_78 = V_79 ;
V_70 . V_80 = V_81 ;
V_70 . V_53 = V_53 ;
V_70 . V_68 = & V_68 ;
V_70 . V_82 = false ;
V_4 = F_23 ( V_39 , & V_70 , & V_66 , & V_75 ) ;
if ( V_4 )
return V_4 ;
if ( V_75 . V_83 != F_24 ( V_25 ) ) {
V_4 = - V_84 ;
goto V_47;
}
V_72 . V_85 = V_68 . V_85 ;
V_72 . V_86 = V_87 -> V_88 ;
V_72 . V_41 = V_41 ;
V_72 . V_89 = 0 ;
V_72 . V_90 = V_25 ;
V_4 = F_25 ( V_39 , & V_72 , V_65 , & V_64 , & V_73 ) ;
V_47:
F_26 ( V_39 , V_41 , V_68 . V_85 ) ;
return V_4 ;
}
int
F_27 ( unsigned int V_39 , struct V_40 * V_41 ,
struct V_42 * V_43 , const unsigned char * V_53 ,
char * V_64 , unsigned int * V_91 )
{
int V_4 ;
int V_66 = 0 ;
struct V_67 V_68 ;
struct V_69 V_70 ;
struct V_71 V_72 ;
int V_78 = V_79 ;
if ( F_28 ( V_43 ) )
V_78 |= V_92 ;
V_70 . V_41 = V_41 ;
V_70 . V_43 = V_43 ;
V_70 . V_76 = V_93 ;
V_70 . V_78 = V_78 ;
V_70 . V_80 = V_94 ;
V_70 . V_53 = V_53 ;
V_70 . V_68 = & V_68 ;
V_70 . V_82 = false ;
V_4 = F_23 ( V_39 , & V_70 , & V_66 , NULL ) ;
if ( V_4 )
return V_4 ;
V_72 . V_85 = V_68 . V_85 ;
V_72 . V_86 = V_87 -> V_88 ;
V_72 . V_41 = V_41 ;
V_72 . V_89 = 0 ;
V_72 . V_90 = V_25 ;
V_4 = F_29 ( V_39 , & V_72 , V_91 , V_64 , NULL , 0 ) ;
F_26 ( V_39 , V_41 , V_68 . V_85 ) ;
return V_4 ;
}
int
F_30 ( struct V_95 * V_96 , struct V_97 * V_97 ,
struct V_95 * V_98 )
{
int V_4 = - V_99 ;
unsigned int V_39 ;
char * V_100 = NULL ;
char * V_101 = NULL ;
struct V_42 * V_43 = F_31 ( V_97 -> V_102 ) ;
struct V_103 * V_104 ;
struct V_40 * V_41 ;
struct V_105 * V_49 ;
struct V_106 * V_107 ;
V_104 = F_32 ( V_43 ) ;
if ( F_3 ( V_104 ) )
return F_4 ( V_104 ) ;
V_41 = F_33 ( V_104 ) ;
V_39 = F_34 () ;
V_100 = F_35 ( V_96 ) ;
V_101 = F_35 ( V_98 ) ;
if ( ( V_100 == NULL ) || ( V_101 == NULL ) ) {
V_4 = - V_14 ;
goto V_108;
}
if ( V_41 -> V_109 )
V_4 = F_36 ( V_39 , V_41 , V_100 , V_101 ,
V_43 -> V_110 ,
V_43 -> V_111 &
V_112 ) ;
else {
V_49 = V_41 -> V_48 -> V_49 ;
if ( ! V_49 -> V_50 -> V_113 ) {
V_4 = - V_56 ;
goto V_108;
}
V_4 = V_49 -> V_50 -> V_113 ( V_39 , V_41 , V_100 , V_101 ,
V_43 ) ;
if ( ( V_4 == - V_52 ) || ( V_4 == - V_26 ) )
V_4 = - V_51 ;
}
F_37 ( V_98 ) ;
if ( V_96 -> V_114 ) {
V_107 = F_38 ( V_96 -> V_114 ) ;
if ( V_4 == 0 ) {
F_39 ( & V_96 -> V_114 -> V_115 ) ;
F_40 ( V_96 -> V_114 ) ;
F_41 ( & V_96 -> V_114 -> V_115 ) ;
}
V_107 -> time = 0 ;
}
V_108:
F_12 ( V_100 ) ;
F_12 ( V_101 ) ;
F_42 ( V_39 ) ;
F_43 ( V_104 ) ;
return V_4 ;
}
void *
F_44 ( struct V_95 * V_98 , struct V_116 * V_117 )
{
struct V_97 * V_97 = V_98 -> V_114 ;
int V_4 = - V_14 ;
unsigned int V_39 ;
char * V_118 = NULL ;
char * V_119 = NULL ;
struct V_42 * V_43 = F_31 ( V_97 -> V_102 ) ;
struct V_103 * V_104 = NULL ;
struct V_40 * V_41 ;
struct V_105 * V_49 ;
V_39 = F_34 () ;
V_104 = F_32 ( V_43 ) ;
if ( F_3 ( V_104 ) ) {
V_4 = F_4 ( V_104 ) ;
V_104 = NULL ;
goto V_47;
}
V_41 = F_33 ( V_104 ) ;
V_49 = V_41 -> V_48 -> V_49 ;
V_118 = F_35 ( V_98 ) ;
if ( ! V_118 )
goto V_47;
F_5 ( V_30 , L_7 , V_118 , V_97 ) ;
V_4 = - V_99 ;
if ( V_43 -> V_111 & V_120 )
V_4 = F_20 ( V_39 , V_41 , V_43 , V_118 ,
& V_119 ) ;
if ( V_4 != 0 && V_49 -> V_50 -> V_121 )
V_4 = V_49 -> V_50 -> V_121 ( V_39 , V_41 , V_118 ,
& V_119 , V_43 ) ;
F_12 ( V_118 ) ;
V_47:
if ( V_4 != 0 ) {
F_12 ( V_119 ) ;
V_119 = F_45 ( V_4 ) ;
}
F_42 ( V_39 ) ;
if ( V_104 )
F_43 ( V_104 ) ;
F_46 ( V_117 , V_119 ) ;
return NULL ;
}
int
F_47 ( struct V_97 * V_97 , struct V_95 * V_98 , const char * V_122 )
{
int V_4 = - V_51 ;
unsigned int V_39 ;
struct V_42 * V_43 = F_31 ( V_97 -> V_102 ) ;
struct V_103 * V_104 ;
struct V_40 * V_123 ;
char * V_118 = NULL ;
struct V_97 * V_124 = NULL ;
V_39 = F_34 () ;
V_104 = F_32 ( V_43 ) ;
if ( F_3 ( V_104 ) ) {
V_4 = F_4 ( V_104 ) ;
goto V_125;
}
V_123 = F_33 ( V_104 ) ;
V_118 = F_35 ( V_98 ) ;
if ( V_118 == NULL ) {
V_4 = - V_14 ;
goto V_125;
}
F_5 ( V_30 , L_8 , V_118 ) ;
F_5 ( V_30 , L_9 , V_122 ) ;
if ( V_43 -> V_111 & V_120 )
V_4 = F_19 ( V_39 , V_123 , V_43 , V_118 , V_122 ) ;
else if ( V_123 -> V_109 )
V_4 = F_48 ( V_39 , V_123 , V_118 , V_122 ,
V_43 -> V_110 ) ;
if ( V_4 == 0 ) {
if ( V_123 -> V_109 )
V_4 = F_49 ( & V_124 , V_118 ,
V_97 -> V_102 , V_39 ) ;
else
V_4 = F_50 ( & V_124 , V_118 , NULL ,
V_97 -> V_102 , V_39 , NULL ) ;
if ( V_4 != 0 ) {
F_5 ( V_30 , L_10 ,
V_4 ) ;
} else {
F_51 ( V_98 , V_124 ) ;
}
}
V_125:
F_12 ( V_118 ) ;
F_43 ( V_104 ) ;
F_42 ( V_39 ) ;
return V_4 ;
}
