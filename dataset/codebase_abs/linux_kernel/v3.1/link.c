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
F_18 ( const int V_33 , struct V_34 * V_35 ,
const char * V_36 , const char * V_37 ,
const struct V_38 * V_39 , int V_40 )
{
int V_4 ;
int V_41 = 0 ;
T_2 V_42 = 0 ;
T_1 * V_18 ;
unsigned int V_43 = 0 ;
struct V_44 V_45 ;
V_18 = F_7 ( V_24 , V_12 ) ;
if ( ! V_18 )
return - V_13 ;
V_4 = F_17 ( V_18 , V_24 , V_37 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
return V_4 ;
}
V_4 = F_19 ( V_33 , V_35 , V_36 , V_46 , V_47 ,
V_48 , & V_42 , & V_41 , NULL ,
V_39 , V_40 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
return V_4 ;
}
V_45 . V_42 = V_42 ;
V_45 . V_49 = V_50 -> V_51 ;
V_45 . V_35 = V_35 ;
V_45 . V_52 = 0 ;
V_45 . V_53 = V_24 ;
V_4 = F_20 ( V_33 , & V_45 , & V_43 , V_18 , NULL , 0 ) ;
F_21 ( V_33 , V_35 , V_42 ) ;
F_12 ( V_18 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_43 != V_24 )
return - V_54 ;
return 0 ;
}
static int
F_22 ( const int V_33 , struct V_34 * V_35 ,
const unsigned char * V_55 , char * * V_56 ,
const struct V_38 * V_39 , int V_40 )
{
int V_4 ;
int V_41 = 0 ;
T_2 V_42 = 0 ;
T_1 * V_18 ;
char * V_57 ;
unsigned int V_58 = 0 ;
int V_59 = V_60 ;
unsigned int V_1 = 0 ;
struct V_44 V_45 ;
T_3 V_61 ;
V_4 = F_19 ( V_33 , V_35 , V_55 , V_62 , V_63 ,
V_48 , & V_42 , & V_41 , & V_61 ,
V_39 , V_40 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_61 . V_64 != F_23 ( V_24 ) ) {
F_21 ( V_33 , V_35 , V_42 ) ;
return - V_25 ;
}
V_18 = F_7 ( V_24 , V_12 ) ;
if ( ! V_18 )
return - V_13 ;
V_57 = V_18 ;
V_45 . V_42 = V_42 ;
V_45 . V_49 = V_50 -> V_51 ;
V_45 . V_35 = V_35 ;
V_45 . V_52 = 0 ;
V_45 . V_53 = V_24 ;
V_4 = F_24 ( V_33 , & V_45 , & V_58 , & V_57 , & V_59 ) ;
F_21 ( V_33 , V_35 , V_42 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
return V_4 ;
}
V_4 = F_13 ( V_18 , V_58 , & V_1 , V_56 ) ;
F_12 ( V_18 ) ;
if ( V_4 != 0 )
return V_4 ;
return 0 ;
}
bool
F_25 ( const struct V_65 * V_66 )
{
if ( ! ( V_66 -> V_67 & V_68 ) )
return false ;
if ( V_66 -> V_69 != V_24 )
return false ;
return true ;
}
int
F_26 ( struct V_65 * V_66 ,
const unsigned char * V_70 ,
struct V_71 * V_72 , int V_33 )
{
int V_4 ;
int V_41 = 0 ;
T_2 V_42 = 0 ;
struct V_73 * V_74 ;
struct V_34 * V_75 ;
struct V_44 V_45 ;
T_1 * V_18 ;
char * V_57 ;
unsigned int V_58 = 0 ;
int V_59 = V_60 ;
unsigned int V_1 = 0 ;
T_3 V_61 ;
if ( ! F_25 ( V_66 ) )
return 0 ;
V_74 = F_27 ( V_72 ) ;
if ( F_3 ( V_74 ) )
return F_4 ( V_74 ) ;
V_75 = F_28 ( V_74 ) ;
V_4 = F_19 ( V_33 , V_75 , V_70 , V_62 , V_63 ,
V_48 , & V_42 , & V_41 , & V_61 ,
V_72 -> V_76 ,
V_72 -> V_77 &
V_78 ) ;
if ( V_4 != 0 )
goto V_79;
if ( V_61 . V_64 != F_23 ( V_24 ) ) {
F_21 ( V_33 , V_75 , V_42 ) ;
goto V_79;
}
V_18 = F_7 ( V_24 , V_12 ) ;
if ( ! V_18 ) {
V_4 = - V_13 ;
goto V_79;
}
V_57 = V_18 ;
V_45 . V_42 = V_42 ;
V_45 . V_49 = V_50 -> V_51 ;
V_45 . V_35 = V_75 ;
V_45 . V_52 = 0 ;
V_45 . V_53 = V_24 ;
V_4 = F_24 ( V_33 , & V_45 , & V_58 , & V_57 , & V_59 ) ;
F_21 ( V_33 , V_75 , V_42 ) ;
if ( V_4 != 0 ) {
F_12 ( V_18 ) ;
goto V_79;
}
V_4 = F_13 ( V_18 , V_58 , & V_1 , NULL ) ;
F_12 ( V_18 ) ;
if ( V_4 == - V_25 ) {
V_4 = 0 ;
goto V_79;
}
if ( V_4 != 0 )
goto V_79;
V_66 -> V_69 = V_1 ;
V_66 -> V_67 &= ~ V_80 ;
V_66 -> V_67 |= V_81 | V_82 | V_83 | V_84 ;
V_66 -> V_85 = V_86 ;
V_79:
F_29 ( V_74 ) ;
return V_4 ;
}
int
F_30 ( struct V_87 * V_88 , struct V_89 * V_89 ,
struct V_87 * V_90 )
{
int V_4 = - V_91 ;
int V_33 ;
char * V_36 = NULL ;
char * V_37 = NULL ;
struct V_71 * V_72 = F_31 ( V_89 -> V_92 ) ;
struct V_73 * V_74 ;
struct V_34 * V_75 ;
struct V_93 * V_94 ;
V_74 = F_27 ( V_72 ) ;
if ( F_3 ( V_74 ) )
return F_4 ( V_74 ) ;
V_75 = F_28 ( V_74 ) ;
V_33 = F_32 () ;
V_36 = F_33 ( V_88 ) ;
V_37 = F_33 ( V_90 ) ;
if ( ( V_36 == NULL ) || ( V_37 == NULL ) ) {
V_4 = - V_13 ;
goto V_95;
}
if ( V_75 -> V_96 )
V_4 = F_34 ( V_33 , V_75 , V_36 , V_37 ,
V_72 -> V_76 ,
V_72 -> V_77 &
V_78 ) ;
else {
V_4 = F_35 ( V_33 , V_75 , V_36 , V_37 ,
V_72 -> V_76 ,
V_72 -> V_77 &
V_78 ) ;
if ( ( V_4 == - V_54 ) || ( V_4 == - V_25 ) )
V_4 = - V_97 ;
}
F_36 ( V_90 ) ;
if ( V_88 -> V_98 ) {
V_94 = F_37 ( V_88 -> V_98 ) ;
if ( V_4 == 0 ) {
V_88 -> V_98 -> V_99 ++ ;
}
V_94 -> time = 0 ;
}
V_95:
F_12 ( V_36 ) ;
F_12 ( V_37 ) ;
F_38 ( V_33 ) ;
F_29 ( V_74 ) ;
return V_4 ;
}
void *
F_39 ( struct V_87 * V_90 , struct V_100 * V_101 )
{
struct V_89 * V_89 = V_90 -> V_98 ;
int V_4 = - V_13 ;
int V_33 ;
char * V_102 = NULL ;
char * V_103 = NULL ;
struct V_71 * V_72 = F_31 ( V_89 -> V_92 ) ;
struct V_73 * V_74 = NULL ;
struct V_34 * V_35 ;
V_33 = F_32 () ;
V_74 = F_27 ( V_72 ) ;
if ( F_3 ( V_74 ) ) {
V_4 = F_4 ( V_74 ) ;
V_74 = NULL ;
goto V_79;
}
V_35 = F_28 ( V_74 ) ;
if ( ! ( V_72 -> V_77 & V_104 )
&& ! ( V_35 -> V_105 -> V_106 & V_107 ) ) {
V_4 = - V_91 ;
goto V_79;
}
V_102 = F_33 ( V_90 ) ;
if ( ! V_102 )
goto V_79;
F_14 ( 1 , L_8 , V_102 , V_89 ) ;
V_4 = - V_91 ;
if ( V_72 -> V_77 & V_104 )
V_4 = F_22 ( V_33 , V_35 , V_102 , & V_103 ,
V_72 -> V_76 ,
V_72 -> V_77 &
V_78 ) ;
if ( ( V_4 != 0 ) && ( V_35 -> V_105 -> V_106 & V_107 ) )
V_4 = F_40 ( V_33 , V_35 , V_102 , & V_103 ,
V_72 -> V_76 ) ;
F_12 ( V_102 ) ;
V_79:
if ( V_4 != 0 ) {
F_12 ( V_103 ) ;
V_103 = F_41 ( V_4 ) ;
}
F_38 ( V_33 ) ;
if ( V_74 )
F_29 ( V_74 ) ;
F_42 ( V_101 , V_103 ) ;
return NULL ;
}
int
F_43 ( struct V_89 * V_89 , struct V_87 * V_90 , const char * V_108 )
{
int V_4 = - V_97 ;
int V_33 ;
struct V_71 * V_72 = F_31 ( V_89 -> V_92 ) ;
struct V_73 * V_74 ;
struct V_34 * V_75 ;
char * V_102 = NULL ;
struct V_89 * V_109 = NULL ;
V_33 = F_32 () ;
V_74 = F_27 ( V_72 ) ;
if ( F_3 ( V_74 ) ) {
V_4 = F_4 ( V_74 ) ;
goto V_110;
}
V_75 = F_28 ( V_74 ) ;
V_102 = F_33 ( V_90 ) ;
if ( V_102 == NULL ) {
V_4 = - V_13 ;
goto V_110;
}
F_14 ( 1 , L_9 , V_102 ) ;
F_14 ( 1 , L_10 , V_108 ) ;
if ( V_72 -> V_77 & V_104 )
V_4 = F_18 ( V_33 , V_75 , V_102 , V_108 ,
V_72 -> V_76 ,
V_72 -> V_77 &
V_78 ) ;
else if ( V_75 -> V_96 )
V_4 = F_44 ( V_33 , V_75 , V_102 , V_108 ,
V_72 -> V_76 ) ;
if ( V_4 == 0 ) {
if ( V_75 -> V_96 )
V_4 = F_45 ( & V_109 , V_102 ,
V_89 -> V_92 , V_33 ) ;
else
V_4 = F_46 ( & V_109 , V_102 , NULL ,
V_89 -> V_92 , V_33 , NULL ) ;
if ( V_4 != 0 ) {
F_14 ( 1 , L_11 ,
V_4 ) ;
} else {
F_47 ( V_90 , V_109 ) ;
}
}
V_110:
F_12 ( V_102 ) ;
F_29 ( V_74 ) ;
F_38 ( V_33 ) ;
return V_4 ;
}
void F_48 ( struct V_87 * V_90 , struct V_100 * V_101 , void * V_111 )
{
char * V_112 = F_49 ( V_101 ) ;
if ( ! F_3 ( V_112 ) )
F_12 ( V_112 ) ;
}
