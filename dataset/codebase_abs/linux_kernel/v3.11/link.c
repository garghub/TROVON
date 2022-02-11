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
F_13 ( const T_1 * V_19 ,
unsigned int V_20 ,
unsigned int * V_21 ,
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
static int
F_17 ( const unsigned int V_35 , struct V_36 * V_37 ,
const char * V_38 , const char * V_39 ,
struct V_40 * V_41 )
{
int V_4 ;
int V_42 = 0 ;
int V_43 ;
int V_44 = V_45 ;
T_2 V_46 = 0 ;
T_1 * V_19 ;
unsigned int V_47 = 0 ;
struct V_48 V_49 ;
struct V_50 * V_51 ;
V_51 = V_41 -> V_52 ;
V_43 = V_41 -> V_53 & V_54 ;
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 )
return - V_14 ;
V_4 = F_16 ( V_19 , V_25 , V_39 ) ;
if ( V_4 != 0 ) {
F_12 ( V_19 ) ;
return V_4 ;
}
if ( F_18 ( V_41 ) )
V_44 |= V_55 ;
V_4 = F_19 ( V_35 , V_37 , V_38 , V_56 , V_57 ,
V_44 , & V_46 , & V_42 , NULL ,
V_51 , V_43 ) ;
if ( V_4 != 0 ) {
F_12 ( V_19 ) ;
return V_4 ;
}
V_49 . V_46 = V_46 ;
V_49 . V_58 = V_59 -> V_60 ;
V_49 . V_37 = V_37 ;
V_49 . V_61 = 0 ;
V_49 . V_62 = V_25 ;
V_4 = F_20 ( V_35 , & V_49 , & V_47 , V_19 , NULL , 0 ) ;
F_21 ( V_35 , V_37 , V_46 ) ;
F_12 ( V_19 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_47 != V_25 )
return - V_63 ;
return 0 ;
}
static int
F_22 ( const unsigned int V_35 , struct V_36 * V_37 ,
const unsigned char * V_64 , char * * V_65 ,
const struct V_50 * V_51 , int V_43 )
{
int V_4 ;
int V_42 = 0 ;
T_2 V_46 = 0 ;
T_1 * V_19 ;
char * V_66 ;
unsigned int V_67 = 0 ;
int V_68 = V_69 ;
unsigned int V_1 = 0 ;
struct V_48 V_49 ;
T_3 V_70 ;
V_4 = F_19 ( V_35 , V_37 , V_64 , V_71 , V_72 ,
V_45 , & V_46 , & V_42 , & V_70 ,
V_51 , V_43 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_70 . V_73 != F_23 ( V_25 ) ) {
F_21 ( V_35 , V_37 , V_46 ) ;
return - V_26 ;
}
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 )
return - V_14 ;
V_66 = V_19 ;
V_49 . V_46 = V_46 ;
V_49 . V_58 = V_59 -> V_60 ;
V_49 . V_37 = V_37 ;
V_49 . V_61 = 0 ;
V_49 . V_62 = V_25 ;
V_4 = F_24 ( V_35 , & V_49 , & V_67 , & V_66 , & V_68 ) ;
F_21 ( V_35 , V_37 , V_46 ) ;
if ( V_4 != 0 ) {
F_12 ( V_19 ) ;
return V_4 ;
}
V_4 = F_13 ( V_19 , V_67 , & V_1 , V_65 ) ;
F_12 ( V_19 ) ;
if ( V_4 != 0 )
return V_4 ;
return 0 ;
}
bool
F_25 ( const struct V_74 * V_75 )
{
if ( ! ( V_75 -> V_76 & V_77 ) )
return false ;
if ( V_75 -> V_78 != V_25 )
return false ;
return true ;
}
int
F_26 ( const unsigned char * V_79 , char * V_66 ,
unsigned int * V_80 , struct V_40 * V_41 ,
unsigned int V_35 )
{
int V_4 ;
int V_42 = 0 ;
T_2 V_46 = 0 ;
struct V_81 * V_82 ;
struct V_36 * V_83 ;
struct V_48 V_49 ;
int V_68 = V_69 ;
T_3 V_70 ;
V_82 = F_27 ( V_41 ) ;
if ( F_3 ( V_82 ) )
return F_4 ( V_82 ) ;
V_83 = F_28 ( V_82 ) ;
V_4 = F_19 ( V_35 , V_83 , V_79 , V_71 , V_72 ,
V_45 , & V_46 , & V_42 , & V_70 ,
V_41 -> V_52 ,
V_41 -> V_53 &
V_54 ) ;
if ( V_4 != 0 ) {
F_29 ( V_82 ) ;
return V_4 ;
}
if ( V_70 . V_73 != F_23 ( V_25 ) ) {
F_21 ( V_35 , V_83 , V_46 ) ;
F_29 ( V_82 ) ;
return V_4 ;
}
V_49 . V_46 = V_46 ;
V_49 . V_58 = V_59 -> V_60 ;
V_49 . V_37 = V_83 ;
V_49 . V_61 = 0 ;
V_49 . V_62 = V_25 ;
V_4 = F_24 ( V_35 , & V_49 , V_80 , & V_66 , & V_68 ) ;
F_21 ( V_35 , V_83 , V_46 ) ;
F_29 ( V_82 ) ;
return V_4 ;
}
int
F_30 ( struct V_74 * V_75 ,
const unsigned char * V_79 ,
struct V_40 * V_41 , unsigned int V_35 )
{
int V_4 = 0 ;
T_1 * V_19 = NULL ;
unsigned int V_1 = 0 ;
unsigned int V_67 = 0 ;
struct V_36 * V_83 ;
if ( ! F_25 ( V_75 ) )
return 0 ;
V_19 = F_7 ( V_25 , V_13 ) ;
if ( ! V_19 ) {
V_4 = - V_14 ;
goto V_84;
}
V_83 = F_28 ( F_27 ( V_41 ) ) ;
if ( ( V_83 -> V_85 ) && ( V_83 -> V_85 -> V_86 -> V_87 -> V_88 ) )
V_4 = V_83 -> V_85 -> V_86 -> V_87 -> V_88 ( V_79 , V_19 ,
& V_67 , V_41 , V_35 ) ;
else
goto V_84;
if ( V_4 != 0 )
goto V_84;
if ( V_67 == 0 )
goto V_84;
V_4 = F_13 ( V_19 , V_67 , & V_1 , NULL ) ;
if ( V_4 == - V_26 ) {
V_4 = 0 ;
goto V_84;
}
if ( V_4 != 0 )
goto V_84;
V_75 -> V_78 = V_1 ;
V_75 -> V_76 &= ~ V_89 ;
V_75 -> V_76 |= V_90 | V_91 | V_92 | V_93 ;
V_75 -> V_94 = V_95 ;
V_84:
F_12 ( V_19 ) ;
return V_4 ;
}
int
F_31 ( struct V_96 * V_97 , struct V_98 * V_98 ,
struct V_96 * V_99 )
{
int V_4 = - V_100 ;
unsigned int V_35 ;
char * V_101 = NULL ;
char * V_102 = NULL ;
struct V_40 * V_41 = F_32 ( V_98 -> V_103 ) ;
struct V_81 * V_82 ;
struct V_36 * V_37 ;
struct V_104 * V_86 ;
struct V_105 * V_106 ;
V_82 = F_27 ( V_41 ) ;
if ( F_3 ( V_82 ) )
return F_4 ( V_82 ) ;
V_37 = F_28 ( V_82 ) ;
V_35 = F_33 () ;
V_101 = F_34 ( V_97 ) ;
V_102 = F_34 ( V_99 ) ;
if ( ( V_101 == NULL ) || ( V_102 == NULL ) ) {
V_4 = - V_14 ;
goto V_107;
}
if ( V_37 -> V_108 )
V_4 = F_35 ( V_35 , V_37 , V_101 , V_102 ,
V_41 -> V_52 ,
V_41 -> V_53 &
V_54 ) ;
else {
V_86 = V_37 -> V_85 -> V_86 ;
if ( ! V_86 -> V_87 -> V_109 )
return - V_110 ;
V_4 = V_86 -> V_87 -> V_109 ( V_35 , V_37 , V_101 , V_102 ,
V_41 ) ;
if ( ( V_4 == - V_63 ) || ( V_4 == - V_26 ) )
V_4 = - V_111 ;
}
F_36 ( V_99 ) ;
if ( V_97 -> V_112 ) {
V_106 = F_37 ( V_97 -> V_112 ) ;
if ( V_4 == 0 ) {
F_38 ( & V_97 -> V_112 -> V_113 ) ;
F_39 ( V_97 -> V_112 ) ;
F_40 ( & V_97 -> V_112 -> V_113 ) ;
}
V_106 -> time = 0 ;
}
V_107:
F_12 ( V_101 ) ;
F_12 ( V_102 ) ;
F_41 ( V_35 ) ;
F_29 ( V_82 ) ;
return V_4 ;
}
void *
F_42 ( struct V_96 * V_99 , struct V_114 * V_115 )
{
struct V_98 * V_98 = V_99 -> V_112 ;
int V_4 = - V_14 ;
unsigned int V_35 ;
char * V_116 = NULL ;
char * V_117 = NULL ;
struct V_40 * V_41 = F_32 ( V_98 -> V_103 ) ;
struct V_81 * V_82 = NULL ;
struct V_36 * V_37 ;
V_35 = F_33 () ;
V_82 = F_27 ( V_41 ) ;
if ( F_3 ( V_82 ) ) {
V_4 = F_4 ( V_82 ) ;
V_82 = NULL ;
goto V_84;
}
V_37 = F_28 ( V_82 ) ;
if ( ! ( V_41 -> V_53 & V_118 ) &&
! F_43 ( V_37 -> V_85 ) ) {
V_4 = - V_100 ;
goto V_84;
}
V_116 = F_34 ( V_99 ) ;
if ( ! V_116 )
goto V_84;
F_5 ( V_30 , L_7 , V_116 , V_98 ) ;
V_4 = - V_100 ;
if ( V_41 -> V_53 & V_118 )
V_4 = F_22 ( V_35 , V_37 , V_116 , & V_117 ,
V_41 -> V_52 ,
V_41 -> V_53 &
V_54 ) ;
if ( ( V_4 != 0 ) && F_43 ( V_37 -> V_85 ) )
V_4 = F_44 ( V_35 , V_37 , V_116 , & V_117 ,
V_41 -> V_52 ) ;
F_12 ( V_116 ) ;
V_84:
if ( V_4 != 0 ) {
F_12 ( V_117 ) ;
V_117 = F_45 ( V_4 ) ;
}
F_41 ( V_35 ) ;
if ( V_82 )
F_29 ( V_82 ) ;
F_46 ( V_115 , V_117 ) ;
return NULL ;
}
int
F_47 ( struct V_98 * V_98 , struct V_96 * V_99 , const char * V_119 )
{
int V_4 = - V_111 ;
unsigned int V_35 ;
struct V_40 * V_41 = F_32 ( V_98 -> V_103 ) ;
struct V_81 * V_82 ;
struct V_36 * V_120 ;
char * V_116 = NULL ;
struct V_98 * V_121 = NULL ;
V_35 = F_33 () ;
V_82 = F_27 ( V_41 ) ;
if ( F_3 ( V_82 ) ) {
V_4 = F_4 ( V_82 ) ;
goto V_122;
}
V_120 = F_28 ( V_82 ) ;
V_116 = F_34 ( V_99 ) ;
if ( V_116 == NULL ) {
V_4 = - V_14 ;
goto V_122;
}
F_5 ( V_30 , L_8 , V_116 ) ;
F_5 ( V_30 , L_9 , V_119 ) ;
if ( V_41 -> V_53 & V_118 )
V_4 = F_17 ( V_35 , V_120 , V_116 , V_119 ,
V_41 ) ;
else if ( V_120 -> V_108 )
V_4 = F_48 ( V_35 , V_120 , V_116 , V_119 ,
V_41 -> V_52 ) ;
if ( V_4 == 0 ) {
if ( V_120 -> V_108 )
V_4 = F_49 ( & V_121 , V_116 ,
V_98 -> V_103 , V_35 ) ;
else
V_4 = F_50 ( & V_121 , V_116 , NULL ,
V_98 -> V_103 , V_35 , NULL ) ;
if ( V_4 != 0 ) {
F_5 ( V_30 , L_10 ,
V_4 ) ;
} else {
F_51 ( V_99 , V_121 ) ;
}
}
V_122:
F_12 ( V_116 ) ;
F_29 ( V_82 ) ;
F_41 ( V_35 ) ;
return V_4 ;
}
void F_52 ( struct V_96 * V_99 , struct V_114 * V_115 , void * V_123 )
{
char * V_124 = F_53 ( V_115 ) ;
if ( ! F_3 ( V_124 ) )
F_12 ( V_124 ) ;
}
