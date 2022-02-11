static int
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
if ( V_2 -> V_5 . V_6 != NULL )
return 0 ;
V_2 -> V_5 . V_7 = F_2 ( L_1 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_5 . V_7 ) ) {
F_4 ( V_8 , L_2 ) ;
V_3 = F_5 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
return V_3 ;
}
V_4 = sizeof( struct V_9 ) +
F_6 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_6 = F_7 ( V_4 , V_10 ) ;
if ( ! V_2 -> V_5 . V_6 ) {
F_8 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
return - V_11 ;
}
V_2 -> V_5 . V_6 -> V_12 . V_13 = V_2 -> V_5 . V_7 ;
V_2 -> V_5 . V_6 -> V_12 . V_14 = 0x0 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
int V_3 ;
if ( V_2 -> V_5 . V_15 != NULL )
return 0 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_5 . V_16 = F_2 ( L_3 , 0 , 0 ) ;
if ( F_3 ( V_2 -> V_5 . V_16 ) ) {
F_4 ( V_8 , L_4 ) ;
F_10 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
F_8 ( V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_7 = NULL ;
V_3 = F_5 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_16 = NULL ;
return V_3 ;
}
V_4 = sizeof( struct V_9 ) +
F_6 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_15 = F_7 ( V_4 , V_10 ) ;
if ( ! V_2 -> V_5 . V_15 ) {
F_4 ( V_8 , L_5 , V_17 ) ;
F_10 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
F_8 ( V_2 -> V_5 . V_7 ) ;
F_8 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_7 = NULL ;
V_2 -> V_5 . V_16 = NULL ;
return - V_11 ;
}
V_2 -> V_5 . V_15 -> V_12 . V_13 = V_2 -> V_5 . V_16 ;
V_2 -> V_5 . V_15 -> V_12 . V_14 = 0x0 ;
return 0 ;
}
static struct V_18 *
F_11 ( struct V_19 * V_20 , struct V_1 * V_2 )
{
struct V_18 * V_21 ;
F_12 ( & V_22 ) ;
F_13 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_21 -> V_23 != V_20 -> V_24 )
continue;
F_14 ( & V_22 ) ;
return V_21 ;
}
F_14 ( & V_22 ) ;
return NULL ;
}
int
F_15 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_27 [ V_28 ] ;
unsigned char * V_29 = V_27 ;
struct V_30 * V_31 = V_26 -> V_32 ;
struct V_19 * V_33 = (struct V_19 * ) V_31 [ 0 ] . V_34 ;
struct V_18 * V_21 ;
V_21 = F_11 ( V_33 , V_2 ) ;
if ( ! V_21 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return 0 ;
}
memset ( V_27 , 0x0 , V_28 ) ;
memset ( V_33 -> V_35 , 0x0 , V_36 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_7 , V_17 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 -> V_5 . V_7 ,
V_21 -> V_37 . V_38 , V_39 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_8 , V_17 ) ;
return V_3 ;
}
V_3 = F_17 ( & V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_9 , V_17 ) ;
return V_3 ;
}
V_3 = F_18 ( V_26 , V_2 , V_29 ,
& V_2 -> V_5 . V_6 -> V_12 ) ;
if ( ! V_3 )
memcpy ( V_33 -> V_35 , V_29 , V_36 ) ;
return V_3 ;
}
static int F_19 ( struct V_18 * V_21 , struct V_30 V_40 ,
struct V_30 V_41 , T_1 * V_42 , unsigned int V_43 )
{
unsigned char V_44 = 0x0 ;
T_1 V_45 [ 4 ] = { 0 , 0 , 0 , 1 } ;
T_1 V_46 [ 4 ] = { 0 , 0 , 0 , 128 } ;
int V_3 = 0 ;
unsigned char V_47 [ V_28 ] ;
unsigned char * V_48 = V_47 ;
memset ( V_47 , 0x0 , V_28 ) ;
memset ( V_42 , 0x0 , V_43 ) ;
V_3 = F_9 ( V_21 -> V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_10 , V_17 ) ;
goto V_49;
}
V_3 = F_16 ( V_21 -> V_2 -> V_5 . V_7 ,
V_21 -> V_37 . V_38 , V_39 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_11 , V_17 ) ;
goto V_49;
}
V_3 = F_17 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_12 , V_17 ) ;
goto V_49;
}
V_3 = F_20 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_45 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_13 , V_17 ) ;
goto V_49;
}
V_3 = F_20 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_40 . V_34 , V_40 . V_50 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_14 , V_17 ) ;
goto V_49;
}
V_3 = F_20 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
& V_44 , 1 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_15 , V_17 ) ;
goto V_49;
}
V_3 = F_20 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_41 . V_34 , V_41 . V_50 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_16 , V_17 ) ;
goto V_49;
}
V_3 = F_20 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_46 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_17 , V_17 ) ;
goto V_49;
}
V_3 = F_21 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_48 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_18 , V_17 ) ;
goto V_49;
}
memcpy ( V_42 , V_48 , V_43 ) ;
V_49:
return V_3 ;
}
static int
F_22 ( struct V_18 * V_21 ,
const struct V_51 * V_52 )
{
int V_3 ;
V_3 = F_19 ( V_21 , V_52 -> V_53 . V_40 ,
V_52 -> V_53 . V_41 , V_21 -> V_54 ,
V_55 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_19 ( V_21 , V_52 -> V_56 . V_40 ,
V_52 -> V_56 . V_41 , V_21 -> V_57 ,
V_55 ) ;
if ( V_3 )
return V_3 ;
return F_19 ( V_21 , V_52 -> V_58 . V_40 ,
V_52 -> V_58 . V_41 ,
V_21 -> V_59 , V_55 ) ;
}
int
F_23 ( struct V_18 * V_21 )
{
struct V_51 V_60 ;
struct V_61 * V_62 ;
V_62 = & V_60 . V_53 ;
V_62 -> V_40 . V_34 = L_19 ;
V_62 -> V_40 . V_50 = 12 ;
V_62 -> V_41 . V_34 = L_20 ;
V_62 -> V_41 . V_50 = 8 ;
V_62 = & V_60 . V_56 ;
V_62 -> V_40 . V_34 = L_21 ;
V_62 -> V_40 . V_50 = 11 ;
V_62 -> V_41 . V_34 = L_22 ;
V_62 -> V_41 . V_50 = 10 ;
V_62 = & V_60 . V_58 ;
V_62 -> V_40 . V_34 = L_21 ;
V_62 -> V_40 . V_50 = 11 ;
V_62 -> V_41 . V_34 = L_23 ;
V_62 -> V_41 . V_50 = 10 ;
return F_22 ( V_21 , & V_60 ) ;
}
int
F_24 ( struct V_18 * V_21 )
{
struct V_51 V_60 ;
struct V_61 * V_62 ;
V_62 = & V_60 . V_53 ;
V_62 -> V_40 . V_34 = L_19 ;
V_62 -> V_40 . V_50 = 12 ;
V_62 -> V_41 . V_34 = L_20 ;
V_62 -> V_41 . V_50 = 8 ;
V_62 = & V_60 . V_56 ;
V_62 -> V_40 . V_34 = L_21 ;
V_62 -> V_40 . V_50 = 11 ;
V_62 -> V_41 . V_34 = L_22 ;
V_62 -> V_41 . V_50 = 10 ;
V_62 = & V_60 . V_58 ;
V_62 -> V_40 . V_34 = L_21 ;
V_62 -> V_40 . V_50 = 11 ;
V_62 -> V_41 . V_34 = L_23 ;
V_62 -> V_41 . V_50 = 10 ;
return F_22 ( V_21 , & V_60 ) ;
}
int
F_25 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_3 = 0 ;
unsigned char V_63 [ V_64 ] ;
unsigned char * V_29 = V_63 ;
struct V_30 * V_31 = V_26 -> V_32 ;
struct V_19 * V_33 = (struct V_19 * ) V_31 [ 0 ] . V_34 ;
struct V_18 * V_21 ;
V_21 = F_11 ( V_33 , V_2 ) ;
if ( ! V_21 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return 0 ;
}
memset ( V_63 , 0x0 , V_64 ) ;
memset ( V_33 -> V_35 , 0x0 , V_36 ) ;
V_3 = F_16 ( V_2 -> V_5 . V_16 ,
V_21 -> V_54 , V_64 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_24 , V_17 ) ;
return V_3 ;
}
V_3 = F_17 ( & V_2 -> V_5 . V_15 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_25 , V_17 ) ;
return V_3 ;
}
V_3 = F_18 ( V_26 , V_2 , V_29 ,
& V_2 -> V_5 . V_15 -> V_12 ) ;
if ( ! V_3 )
memcpy ( V_33 -> V_35 , V_29 , V_36 ) ;
return V_3 ;
}
static int
F_26 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_19 * V_33 = V_26 -> V_32 [ 0 ] . V_34 ;
if ( ! ( V_33 -> V_65 & V_66 ) ||
V_2 -> V_67 == V_68 )
return V_3 ;
if ( ! V_2 -> V_69 ) {
strncpy ( V_33 -> V_35 , L_26 , 8 ) ;
return V_3 ;
}
V_3 = V_2 -> V_70 -> V_71 ( V_26 , V_2 ) ;
return V_3 ;
}
int
F_27 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
unsigned int V_3 ;
char V_72 [ 16 ] ;
struct V_19 * V_33 = (struct V_19 * ) V_26 -> V_32 [ 0 ] . V_34 ;
if ( ( V_33 -> V_73 == V_74 ) ||
( V_33 -> V_73 == V_75 ) ||
( V_33 -> V_73 == V_76 ) ||
( ! V_2 -> V_69 ) )
return 0 ;
if ( memcmp ( V_33 -> V_35 , L_27 , 8 ) == 0 )
F_4 ( V_77 , L_28 ,
V_33 -> V_73 ) ;
memcpy ( V_72 , V_33 -> V_35 , V_36 ) ;
memset ( V_33 -> V_35 , 0 , V_36 ) ;
F_28 ( & V_2 -> V_78 ) ;
V_3 = V_2 -> V_70 -> V_71 ( V_26 , V_2 ) ;
F_29 ( & V_2 -> V_78 ) ;
if ( V_3 )
return V_3 ;
if ( memcmp ( V_72 , V_33 -> V_35 ,
V_36 ) )
return - V_79 ;
else
return 0 ;
}
static inline void
F_30 ( struct V_1 * V_2 , struct V_19 * V_80 )
{
unsigned int V_45 , V_81 = F_31 ( V_80 -> V_82 ) ;
V_80 -> V_83 = F_32 ( V_2 ) ;
for ( V_45 = 1 ; V_45 < V_81 ; V_45 ++ )
F_33 ( V_2 ) ;
}
static struct V_84 *
F_34 ( const struct V_19 * V_85 ,
struct V_1 * V_2 )
{
struct V_84 * V_86 ;
if ( V_2 == NULL ) {
F_4 ( V_8 , L_29 ) ;
return NULL ;
}
V_86 = F_35 ( V_87 , V_88 ) ;
if ( V_86 == NULL )
return V_86 ;
else {
memset ( V_86 , 0 , sizeof( struct V_84 ) ) ;
V_86 -> V_89 = F_36 ( V_85 -> V_83 ) ;
V_86 -> V_90 = V_91 -> V_90 ;
V_86 -> V_92 = V_85 -> V_73 ;
V_86 -> V_93 = V_94 ;
V_86 -> V_2 = V_2 ;
V_86 -> V_95 = V_96 ;
V_86 -> V_97 = V_91 ;
}
F_37 ( & V_98 ) ;
V_86 -> V_99 = V_100 ;
return V_86 ;
}
static int
F_38 ( struct V_18 * V_21 , struct V_19 * V_101 ,
struct V_84 * * V_89 )
{
if ( V_21 -> V_2 -> V_67 == V_102 )
return - V_103 ;
if ( V_21 -> V_2 -> V_67 == V_104 ) {
F_4 ( V_77 , L_30 ) ;
return - V_105 ;
}
if ( V_21 -> V_106 == V_107 ) {
if ( ( V_101 -> V_73 != V_75 ) &&
( V_101 -> V_73 != V_74 ) )
return - V_105 ;
}
if ( V_21 -> V_106 == V_102 ) {
if ( V_101 -> V_73 != V_108 )
return - V_105 ;
}
* V_89 = F_34 ( V_101 , V_21 -> V_2 ) ;
if ( * V_89 == NULL )
return - V_11 ;
F_12 ( & V_109 ) ;
F_39 ( & ( * V_89 ) -> V_110 , & V_21 -> V_2 -> V_111 ) ;
F_14 ( & V_109 ) ;
return 0 ;
}
int
F_40 ( struct V_84 * V_89 , struct V_1 * V_2 ,
bool V_112 )
{
unsigned int V_113 = F_41 ( V_89 -> V_114 ) ;
struct V_30 V_31 ;
struct V_25 V_26 = { . V_32 = & V_31 ,
. V_115 = 1 } ;
V_31 . V_34 = ( char * ) V_89 -> V_114 ;
V_31 . V_50 = F_41 ( V_89 -> V_114 ) + 4 ;
F_42 ( V_89 -> V_114 , F_43 ( V_116 , 80 , V_113 ) ) ;
if ( V_113 > 24 && V_2 -> V_117 ) {
int V_3 ;
V_3 = F_27 ( & V_26 , V_2 ) ;
if ( V_3 )
F_4 ( V_8 , L_31 ,
V_3 ) ;
}
return F_44 ( V_89 -> V_114 , V_112 ) ;
}
struct V_84 *
F_45 ( struct V_18 * V_21 , struct V_25 * V_26 )
{
int V_3 ;
struct V_19 * V_80 = (struct V_19 * ) V_26 -> V_32 [ 0 ] . V_34 ;
struct V_84 * V_89 ;
F_30 ( V_21 -> V_2 , V_80 ) ;
V_3 = F_38 ( V_21 , V_80 , & V_89 ) ;
if ( V_3 )
return F_46 ( V_3 ) ;
V_3 = F_26 ( V_26 , V_21 -> V_2 ) ;
if ( V_3 ) {
F_47 ( V_89 ) ;
return F_46 ( V_3 ) ;
}
return V_89 ;
}
struct V_84 *
F_48 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_3 ;
struct V_19 * V_80 = (struct V_19 * ) V_26 -> V_32 [ 0 ] . V_34 ;
struct V_84 * V_89 ;
F_30 ( V_2 , V_80 ) ;
V_89 = F_34 ( V_80 , V_2 ) ;
if ( V_89 == NULL )
return F_46 ( - V_11 ) ;
V_3 = F_26 ( V_26 , V_2 ) ;
if ( V_3 ) {
F_49 ( V_89 ) ;
return F_46 ( V_3 ) ;
}
return V_89 ;
}
