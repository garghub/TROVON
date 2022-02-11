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
F_5 ( 1 , L_2 , V_10 , V_4 ) ;
return V_4 ;
}
V_5 = sizeof( struct V_11 ) + F_6 ( V_7 ) ;
V_9 = F_7 ( V_5 , V_12 ) ;
if ( ! V_9 ) {
V_4 = - V_13 ;
F_5 ( 1 , L_3 , V_10 ) ;
goto V_14;
}
V_9 -> V_15 . V_16 = V_7 ;
V_9 -> V_15 . V_17 = 0x0 ;
V_4 = F_8 ( & V_9 -> V_15 ) ;
if ( V_4 ) {
F_5 ( 1 , L_4 , V_10 ) ;
goto V_14;
}
V_4 = F_9 ( & V_9 -> V_15 , V_2 , V_1 ) ;
if ( V_4 ) {
F_5 ( 1 , L_5 , V_10 ) ;
goto V_14;
}
V_4 = F_10 ( & V_9 -> V_15 , V_3 ) ;
if ( V_4 )
F_5 ( 1 , L_6 , V_10 ) ;
V_14:
F_11 ( V_7 ) ;
F_12 ( V_9 ) ;
return V_4 ;
}
static int
F_13 ( const T_1 * V_18 ,
unsigned int V_19 ,
unsigned int * V_20 ,
char * * V_21 )
{
int V_4 ;
unsigned int V_1 ;
const char * V_22 ;
const char * V_2 ;
T_1 V_3 [ 16 ] ;
char V_23 [ 34 ] ;
if ( V_19 != V_24 )
return - V_25 ;
V_22 = ( const char * ) & V_18 [ V_26 ] ;
V_2 = ( const char * ) & V_18 [ V_27 ] ;
V_4 = sscanf ( V_18 , V_28 , & V_1 ) ;
if ( V_4 != 1 )
return - V_25 ;
V_4 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_4 ) {
F_14 ( 1 , L_7 , V_10 , V_4 ) ;
return V_4 ;
}
snprintf ( V_23 , sizeof( V_23 ) ,
V_29 ,
F_15 ( V_3 ) ) ;
if ( strncmp ( V_22 , V_23 , 17 ) != 0 )
return - V_25 ;
if ( V_21 ) {
* V_21 = F_16 ( V_2 , V_1 , V_12 ) ;
if ( ! * V_21 )
return - V_13 ;
}
* V_20 = V_1 ;
return 0 ;
}
static int
F_17 ( T_1 * V_18 , unsigned int V_19 , const char * V_2 )
{
int V_4 ;
unsigned int V_1 ;
unsigned int V_30 ;
T_1 V_3 [ 16 ] ;
if ( V_19 != V_24 )
return - V_25 ;
V_1 = strlen ( V_2 ) ;
if ( V_1 > V_31 )
return - V_32 ;
V_4 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_4 ) {
F_14 ( 1 , L_7 , V_10 , V_4 ) ;
return V_4 ;
}
snprintf (buf, buf_len,
CIFS_MF_SYMLINK_LEN_FORMAT CIFS_MF_SYMLINK_MD5_FORMAT,
link_len,
CIFS_MF_SYMLINK_MD5_ARGS(md5_hash)) ;
V_30 = V_27 ;
memcpy ( V_18 + V_30 , V_2 , V_1 ) ;
V_30 += V_1 ;
if ( V_30 < V_24 ) {
V_18 [ V_30 ] = '\n' ;
V_30 ++ ;
}
while ( V_30 < V_24 ) {
V_18 [ V_30 ] = ' ' ;
V_30 ++ ;
}
return 0 ;
}
static int
F_18 ( const unsigned int V_33 , struct V_34 * V_35 ,
const char * V_36 , const char * V_37 ,
struct V_38 * V_39 )
{
int V_4 ;
int V_40 = 0 ;
int V_41 ;
int V_42 = V_43 ;
T_2 V_44 = 0 ;
T_1 * V_18 ;
unsigned int V_45 = 0 ;
struct V_46 V_47 ;
struct V_48 * V_49 ;
V_49 = V_39 -> V_50 ;
V_41 = V_39 -> V_51 & V_52 ;
V_18 = F_7 ( V_24 , V_12 ) ;
if ( ! V_18 )
return - V_13 ;
V_4 = F_17 ( V_18 , V_24 , V_37 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
return V_4 ;
}
if ( F_19 ( V_39 ) )
V_42 |= V_53 ;
V_4 = F_20 ( V_33 , V_35 , V_36 , V_54 , V_55 ,
V_42 , & V_44 , & V_40 , NULL ,
V_49 , V_41 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
return V_4 ;
}
V_47 . V_44 = V_44 ;
V_47 . V_56 = V_57 -> V_58 ;
V_47 . V_35 = V_35 ;
V_47 . V_59 = 0 ;
V_47 . V_60 = V_24 ;
V_4 = F_21 ( V_33 , & V_47 , & V_45 , V_18 , NULL , 0 ) ;
F_22 ( V_33 , V_35 , V_44 ) ;
F_12 ( V_18 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_45 != V_24 )
return - V_61 ;
return 0 ;
}
static int
F_23 ( const unsigned int V_33 , struct V_34 * V_35 ,
const unsigned char * V_62 , char * * V_63 ,
const struct V_48 * V_49 , int V_41 )
{
int V_4 ;
int V_40 = 0 ;
T_2 V_44 = 0 ;
T_1 * V_18 ;
char * V_64 ;
unsigned int V_65 = 0 ;
int V_66 = V_67 ;
unsigned int V_1 = 0 ;
struct V_46 V_47 ;
T_3 V_68 ;
V_4 = F_20 ( V_33 , V_35 , V_62 , V_69 , V_70 ,
V_43 , & V_44 , & V_40 , & V_68 ,
V_49 , V_41 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_68 . V_71 != F_24 ( V_24 ) ) {
F_22 ( V_33 , V_35 , V_44 ) ;
return - V_25 ;
}
V_18 = F_7 ( V_24 , V_12 ) ;
if ( ! V_18 )
return - V_13 ;
V_64 = V_18 ;
V_47 . V_44 = V_44 ;
V_47 . V_56 = V_57 -> V_58 ;
V_47 . V_35 = V_35 ;
V_47 . V_59 = 0 ;
V_47 . V_60 = V_24 ;
V_4 = F_25 ( V_33 , & V_47 , & V_65 , & V_64 , & V_66 ) ;
F_22 ( V_33 , V_35 , V_44 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
return V_4 ;
}
V_4 = F_13 ( V_18 , V_65 , & V_1 , V_63 ) ;
F_12 ( V_18 ) ;
if ( V_4 != 0 )
return V_4 ;
return 0 ;
}
bool
F_26 ( const struct V_72 * V_73 )
{
if ( ! ( V_73 -> V_74 & V_75 ) )
return false ;
if ( V_73 -> V_76 != V_24 )
return false ;
return true ;
}
int
F_27 ( struct V_72 * V_73 ,
const unsigned char * V_77 ,
struct V_38 * V_39 , unsigned int V_33 )
{
int V_4 ;
int V_40 = 0 ;
T_2 V_44 = 0 ;
struct V_78 * V_79 ;
struct V_34 * V_80 ;
struct V_46 V_47 ;
T_1 * V_18 ;
char * V_64 ;
unsigned int V_65 = 0 ;
int V_66 = V_67 ;
unsigned int V_1 = 0 ;
T_3 V_68 ;
if ( ! F_26 ( V_73 ) )
return 0 ;
V_79 = F_28 ( V_39 ) ;
if ( F_3 ( V_79 ) )
return F_4 ( V_79 ) ;
V_80 = F_29 ( V_79 ) ;
V_4 = F_20 ( V_33 , V_80 , V_77 , V_69 , V_70 ,
V_43 , & V_44 , & V_40 , & V_68 ,
V_39 -> V_50 ,
V_39 -> V_51 &
V_52 ) ;
if ( V_4 != 0 )
goto V_81;
if ( V_68 . V_71 != F_24 ( V_24 ) ) {
F_22 ( V_33 , V_80 , V_44 ) ;
goto V_81;
}
V_18 = F_7 ( V_24 , V_12 ) ;
if ( ! V_18 ) {
V_4 = - V_13 ;
goto V_81;
}
V_64 = V_18 ;
V_47 . V_44 = V_44 ;
V_47 . V_56 = V_57 -> V_58 ;
V_47 . V_35 = V_80 ;
V_47 . V_59 = 0 ;
V_47 . V_60 = V_24 ;
V_4 = F_25 ( V_33 , & V_47 , & V_65 , & V_64 , & V_66 ) ;
F_22 ( V_33 , V_80 , V_44 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
goto V_81;
}
V_4 = F_13 ( V_18 , V_65 , & V_1 , NULL ) ;
F_12 ( V_18 ) ;
if ( V_4 == - V_25 ) {
V_4 = 0 ;
goto V_81;
}
if ( V_4 != 0 )
goto V_81;
V_73 -> V_76 = V_1 ;
V_73 -> V_74 &= ~ V_82 ;
V_73 -> V_74 |= V_83 | V_84 | V_85 | V_86 ;
V_73 -> V_87 = V_88 ;
V_81:
F_30 ( V_79 ) ;
return V_4 ;
}
int
F_31 ( struct V_89 * V_90 , struct V_91 * V_91 ,
struct V_89 * V_92 )
{
int V_4 = - V_93 ;
unsigned int V_33 ;
char * V_94 = NULL ;
char * V_95 = NULL ;
struct V_38 * V_39 = F_32 ( V_91 -> V_96 ) ;
struct V_78 * V_79 ;
struct V_34 * V_35 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
V_79 = F_28 ( V_39 ) ;
if ( F_3 ( V_79 ) )
return F_4 ( V_79 ) ;
V_35 = F_29 ( V_79 ) ;
V_33 = F_33 () ;
V_94 = F_34 ( V_90 ) ;
V_95 = F_34 ( V_92 ) ;
if ( ( V_94 == NULL ) || ( V_95 == NULL ) ) {
V_4 = - V_13 ;
goto V_101;
}
if ( V_35 -> V_102 )
V_4 = F_35 ( V_33 , V_35 , V_94 , V_95 ,
V_39 -> V_50 ,
V_39 -> V_51 &
V_52 ) ;
else {
V_98 = V_35 -> V_103 -> V_98 ;
if ( ! V_98 -> V_104 -> V_105 )
return - V_106 ;
V_4 = V_98 -> V_104 -> V_105 ( V_33 , V_35 , V_94 , V_95 ,
V_39 ) ;
if ( ( V_4 == - V_61 ) || ( V_4 == - V_25 ) )
V_4 = - V_107 ;
}
F_36 ( V_92 ) ;
if ( V_90 -> V_108 ) {
V_100 = F_37 ( V_90 -> V_108 ) ;
if ( V_4 == 0 ) {
F_38 ( & V_90 -> V_108 -> V_109 ) ;
F_39 ( V_90 -> V_108 ) ;
F_40 ( & V_90 -> V_108 -> V_109 ) ;
}
V_100 -> time = 0 ;
}
V_101:
F_12 ( V_94 ) ;
F_12 ( V_95 ) ;
F_41 ( V_33 ) ;
F_30 ( V_79 ) ;
return V_4 ;
}
void *
F_42 ( struct V_89 * V_92 , struct V_110 * V_111 )
{
struct V_91 * V_91 = V_92 -> V_108 ;
int V_4 = - V_13 ;
unsigned int V_33 ;
char * V_112 = NULL ;
char * V_113 = NULL ;
struct V_38 * V_39 = F_32 ( V_91 -> V_96 ) ;
struct V_78 * V_79 = NULL ;
struct V_34 * V_35 ;
V_33 = F_33 () ;
V_79 = F_28 ( V_39 ) ;
if ( F_3 ( V_79 ) ) {
V_4 = F_4 ( V_79 ) ;
V_79 = NULL ;
goto V_81;
}
V_35 = F_29 ( V_79 ) ;
if ( ! ( V_39 -> V_51 & V_114 ) &&
! F_43 ( V_35 -> V_103 ) ) {
V_4 = - V_93 ;
goto V_81;
}
V_112 = F_34 ( V_92 ) ;
if ( ! V_112 )
goto V_81;
F_14 ( 1 , L_8 , V_112 , V_91 ) ;
V_4 = - V_93 ;
if ( V_39 -> V_51 & V_114 )
V_4 = F_23 ( V_33 , V_35 , V_112 , & V_113 ,
V_39 -> V_50 ,
V_39 -> V_51 &
V_52 ) ;
if ( ( V_4 != 0 ) && F_43 ( V_35 -> V_103 ) )
V_4 = F_44 ( V_33 , V_35 , V_112 , & V_113 ,
V_39 -> V_50 ) ;
F_12 ( V_112 ) ;
V_81:
if ( V_4 != 0 ) {
F_12 ( V_113 ) ;
V_113 = F_45 ( V_4 ) ;
}
F_41 ( V_33 ) ;
if ( V_79 )
F_30 ( V_79 ) ;
F_46 ( V_111 , V_113 ) ;
return NULL ;
}
int
F_47 ( struct V_91 * V_91 , struct V_89 * V_92 , const char * V_115 )
{
int V_4 = - V_107 ;
unsigned int V_33 ;
struct V_38 * V_39 = F_32 ( V_91 -> V_96 ) ;
struct V_78 * V_79 ;
struct V_34 * V_80 ;
char * V_112 = NULL ;
struct V_91 * V_116 = NULL ;
V_33 = F_33 () ;
V_79 = F_28 ( V_39 ) ;
if ( F_3 ( V_79 ) ) {
V_4 = F_4 ( V_79 ) ;
goto V_117;
}
V_80 = F_29 ( V_79 ) ;
V_112 = F_34 ( V_92 ) ;
if ( V_112 == NULL ) {
V_4 = - V_13 ;
goto V_117;
}
F_14 ( 1 , L_9 , V_112 ) ;
F_14 ( 1 , L_10 , V_115 ) ;
if ( V_39 -> V_51 & V_114 )
V_4 = F_18 ( V_33 , V_80 , V_112 , V_115 ,
V_39 ) ;
else if ( V_80 -> V_102 )
V_4 = F_48 ( V_33 , V_80 , V_112 , V_115 ,
V_39 -> V_50 ) ;
if ( V_4 == 0 ) {
if ( V_80 -> V_102 )
V_4 = F_49 ( & V_116 , V_112 ,
V_91 -> V_96 , V_33 ) ;
else
V_4 = F_50 ( & V_116 , V_112 , NULL ,
V_91 -> V_96 , V_33 , NULL ) ;
if ( V_4 != 0 ) {
F_14 ( 1 , L_11 ,
V_4 ) ;
} else {
F_51 ( V_92 , V_116 ) ;
}
}
V_117:
F_12 ( V_112 ) ;
F_30 ( V_79 ) ;
F_41 ( V_33 ) ;
return V_4 ;
}
void F_52 ( struct V_89 * V_92 , struct V_110 * V_111 , void * V_118 )
{
char * V_119 = F_53 ( V_111 ) ;
if ( ! F_3 ( V_119 ) )
F_12 ( V_119 ) ;
}
