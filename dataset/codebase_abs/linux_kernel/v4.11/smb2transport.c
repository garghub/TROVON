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
F_11 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_18 * V_20 ;
F_12 (ses, &server->smb_ses_list, smb_ses_list) {
if ( V_20 -> V_21 != V_19 )
continue;
return V_20 ;
}
return NULL ;
}
struct V_18 *
F_13 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_18 * V_20 ;
F_14 ( & V_22 ) ;
V_20 = F_11 ( V_2 , V_19 ) ;
F_15 ( & V_22 ) ;
return V_20 ;
}
static struct V_23 *
F_16 ( struct V_18 * V_20 , T_2 V_24 )
{
struct V_23 * V_25 ;
F_12 (tcon, &ses->tcon_list, tcon_list) {
if ( V_25 -> V_24 != V_24 )
continue;
++ V_25 -> V_26 ;
return V_25 ;
}
return NULL ;
}
struct V_23 *
F_17 ( struct V_1 * V_2 , T_1 V_19 , T_2 V_24 )
{
struct V_18 * V_20 ;
struct V_23 * V_25 ;
F_14 ( & V_22 ) ;
V_20 = F_11 ( V_2 , V_19 ) ;
if ( ! V_20 ) {
F_15 ( & V_22 ) ;
return NULL ;
}
V_25 = F_16 ( V_20 , V_24 ) ;
F_15 ( & V_22 ) ;
return V_25 ;
}
int
F_18 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_29 [ V_30 ] ;
unsigned char * V_31 = V_29 ;
struct V_32 * V_33 = V_28 -> V_34 ;
struct V_35 * V_36 = (struct V_35 * ) V_33 [ 1 ] . V_37 ;
struct V_18 * V_20 ;
V_20 = F_13 ( V_2 , V_36 -> V_38 ) ;
if ( ! V_20 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return 0 ;
}
memset ( V_29 , 0x0 , V_30 ) ;
memset ( V_36 -> V_39 , 0x0 , V_40 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_7 , V_17 ) ;
return V_3 ;
}
V_3 = F_19 ( V_2 -> V_5 . V_7 ,
V_20 -> V_41 . V_42 , V_43 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_8 , V_17 ) ;
return V_3 ;
}
V_3 = F_20 ( & V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_9 , V_17 ) ;
return V_3 ;
}
V_3 = F_21 ( V_28 , V_2 , V_31 ,
& V_2 -> V_5 . V_6 -> V_12 ) ;
if ( ! V_3 )
memcpy ( V_36 -> V_39 , V_31 , V_40 ) ;
return V_3 ;
}
static int F_22 ( struct V_18 * V_20 , struct V_32 V_44 ,
struct V_32 V_45 , T_3 * V_46 , unsigned int V_47 )
{
unsigned char V_48 = 0x0 ;
T_3 V_49 [ 4 ] = { 0 , 0 , 0 , 1 } ;
T_3 V_50 [ 4 ] = { 0 , 0 , 0 , 128 } ;
int V_3 = 0 ;
unsigned char V_51 [ V_30 ] ;
unsigned char * V_52 = V_51 ;
memset ( V_51 , 0x0 , V_30 ) ;
memset ( V_46 , 0x0 , V_47 ) ;
V_3 = F_9 ( V_20 -> V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_10 , V_17 ) ;
goto V_53;
}
V_3 = F_19 ( V_20 -> V_2 -> V_5 . V_7 ,
V_20 -> V_41 . V_42 , V_43 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_11 , V_17 ) ;
goto V_53;
}
V_3 = F_20 ( & V_20 -> V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_12 , V_17 ) ;
goto V_53;
}
V_3 = F_23 ( & V_20 -> V_2 -> V_5 . V_6 -> V_12 ,
V_49 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_13 , V_17 ) ;
goto V_53;
}
V_3 = F_23 ( & V_20 -> V_2 -> V_5 . V_6 -> V_12 ,
V_44 . V_37 , V_44 . V_54 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_14 , V_17 ) ;
goto V_53;
}
V_3 = F_23 ( & V_20 -> V_2 -> V_5 . V_6 -> V_12 ,
& V_48 , 1 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_15 , V_17 ) ;
goto V_53;
}
V_3 = F_23 ( & V_20 -> V_2 -> V_5 . V_6 -> V_12 ,
V_45 . V_37 , V_45 . V_54 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_16 , V_17 ) ;
goto V_53;
}
V_3 = F_23 ( & V_20 -> V_2 -> V_5 . V_6 -> V_12 ,
V_50 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_17 , V_17 ) ;
goto V_53;
}
V_3 = F_24 ( & V_20 -> V_2 -> V_5 . V_6 -> V_12 ,
V_52 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_18 , V_17 ) ;
goto V_53;
}
memcpy ( V_46 , V_52 , V_47 ) ;
V_53:
return V_3 ;
}
static int
F_25 ( struct V_18 * V_20 ,
const struct V_55 * V_56 )
{
int V_3 ;
V_3 = F_22 ( V_20 , V_56 -> V_57 . V_44 ,
V_56 -> V_57 . V_45 , V_20 -> V_58 ,
V_59 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_22 ( V_20 , V_56 -> V_60 . V_44 ,
V_56 -> V_60 . V_45 , V_20 -> V_61 ,
V_59 ) ;
if ( V_3 )
return V_3 ;
return F_22 ( V_20 , V_56 -> V_62 . V_44 ,
V_56 -> V_62 . V_45 ,
V_20 -> V_63 , V_59 ) ;
}
int
F_26 ( struct V_18 * V_20 )
{
struct V_55 V_64 ;
struct V_65 * V_66 ;
V_66 = & V_64 . V_57 ;
V_66 -> V_44 . V_37 = L_19 ;
V_66 -> V_44 . V_54 = 12 ;
V_66 -> V_45 . V_37 = L_20 ;
V_66 -> V_45 . V_54 = 8 ;
V_66 = & V_64 . V_60 ;
V_66 -> V_44 . V_37 = L_21 ;
V_66 -> V_44 . V_54 = 11 ;
V_66 -> V_45 . V_37 = L_22 ;
V_66 -> V_45 . V_54 = 10 ;
V_66 = & V_64 . V_62 ;
V_66 -> V_44 . V_37 = L_21 ;
V_66 -> V_44 . V_54 = 11 ;
V_66 -> V_45 . V_37 = L_23 ;
V_66 -> V_45 . V_54 = 10 ;
return F_25 ( V_20 , & V_64 ) ;
}
int
F_27 ( struct V_18 * V_20 )
{
struct V_55 V_64 ;
struct V_65 * V_66 ;
V_66 = & V_64 . V_57 ;
V_66 -> V_44 . V_37 = L_19 ;
V_66 -> V_44 . V_54 = 12 ;
V_66 -> V_45 . V_37 = L_20 ;
V_66 -> V_45 . V_54 = 8 ;
V_66 = & V_64 . V_60 ;
V_66 -> V_44 . V_37 = L_21 ;
V_66 -> V_44 . V_54 = 11 ;
V_66 -> V_45 . V_37 = L_22 ;
V_66 -> V_45 . V_54 = 10 ;
V_66 = & V_64 . V_62 ;
V_66 -> V_44 . V_37 = L_21 ;
V_66 -> V_44 . V_54 = 11 ;
V_66 -> V_45 . V_37 = L_23 ;
V_66 -> V_45 . V_54 = 10 ;
return F_25 ( V_20 , & V_64 ) ;
}
int
F_28 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
int V_3 = 0 ;
unsigned char V_67 [ V_68 ] ;
unsigned char * V_31 = V_67 ;
struct V_32 * V_33 = V_28 -> V_34 ;
struct V_35 * V_36 = (struct V_35 * ) V_33 [ 1 ] . V_37 ;
struct V_18 * V_20 ;
V_20 = F_13 ( V_2 , V_36 -> V_38 ) ;
if ( ! V_20 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return 0 ;
}
memset ( V_67 , 0x0 , V_68 ) ;
memset ( V_36 -> V_39 , 0x0 , V_40 ) ;
V_3 = F_19 ( V_2 -> V_5 . V_16 ,
V_20 -> V_58 , V_68 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_24 , V_17 ) ;
return V_3 ;
}
V_3 = F_20 ( & V_2 -> V_5 . V_15 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_25 , V_17 ) ;
return V_3 ;
}
V_3 = F_21 ( V_28 , V_2 , V_31 ,
& V_2 -> V_5 . V_15 -> V_12 ) ;
if ( ! V_3 )
memcpy ( V_36 -> V_39 , V_31 , V_40 ) ;
return V_3 ;
}
static int
F_29 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_35 * V_36 =
(struct V_35 * ) V_28 -> V_34 [ 1 ] . V_37 ;
if ( ! ( V_36 -> V_69 & V_70 ) ||
V_2 -> V_71 == V_72 )
return V_3 ;
if ( ! V_2 -> V_73 ) {
strncpy ( V_36 -> V_39 , L_26 , 8 ) ;
return V_3 ;
}
V_3 = V_2 -> V_74 -> V_75 ( V_28 , V_2 ) ;
return V_3 ;
}
int
F_30 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
unsigned int V_3 ;
char V_76 [ 16 ] ;
struct V_35 * V_36 =
(struct V_35 * ) V_28 -> V_34 [ 1 ] . V_37 ;
if ( ( V_36 -> V_77 == V_78 ) ||
( V_36 -> V_77 == V_79 ) ||
( V_36 -> V_77 == V_80 ) ||
( ! V_2 -> V_73 ) )
return 0 ;
if ( memcmp ( V_36 -> V_39 , L_27 , 8 ) == 0 )
F_4 ( V_81 , L_28 ,
V_36 -> V_77 ) ;
memcpy ( V_76 , V_36 -> V_39 , V_40 ) ;
memset ( V_36 -> V_39 , 0 , V_40 ) ;
F_31 ( & V_2 -> V_82 ) ;
V_3 = V_2 -> V_74 -> V_75 ( V_28 , V_2 ) ;
F_32 ( & V_2 -> V_82 ) ;
if ( V_3 )
return V_3 ;
if ( memcmp ( V_76 , V_36 -> V_39 , V_40 ) )
return - V_83 ;
else
return 0 ;
}
static inline void
F_33 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
unsigned int V_49 , V_84 = F_34 ( V_36 -> V_85 ) ;
V_36 -> V_86 = F_35 ( V_2 ) ;
for ( V_49 = 1 ; V_49 < V_84 ; V_49 ++ )
F_36 ( V_2 ) ;
}
static struct V_87 *
F_37 ( const struct V_35 * V_36 ,
struct V_1 * V_2 )
{
struct V_87 * V_88 ;
if ( V_2 == NULL ) {
F_4 ( V_8 , L_29 ) ;
return NULL ;
}
V_88 = F_38 ( V_89 , V_90 ) ;
if ( V_88 == NULL )
return V_88 ;
else {
memset ( V_88 , 0 , sizeof( struct V_87 ) ) ;
V_88 -> V_91 = F_39 ( V_36 -> V_86 ) ;
V_88 -> V_92 = V_93 -> V_92 ;
V_88 -> V_94 = V_36 -> V_77 ;
V_88 -> V_95 = V_96 ;
V_88 -> V_2 = V_2 ;
V_88 -> V_97 = V_98 ;
V_88 -> V_99 = V_93 ;
}
F_40 ( & V_100 ) ;
V_88 -> V_101 = V_102 ;
return V_88 ;
}
static int
F_41 ( struct V_18 * V_20 , struct V_35 * V_36 ,
struct V_87 * * V_91 )
{
if ( V_20 -> V_2 -> V_71 == V_103 )
return - V_104 ;
if ( V_20 -> V_2 -> V_71 == V_105 ) {
F_4 ( V_81 , L_30 ) ;
return - V_106 ;
}
if ( V_20 -> V_107 == V_108 ) {
if ( ( V_36 -> V_77 != V_79 ) &&
( V_36 -> V_77 != V_78 ) )
return - V_106 ;
}
if ( V_20 -> V_107 == V_103 ) {
if ( V_36 -> V_77 != V_109 )
return - V_106 ;
}
* V_91 = F_37 ( V_36 , V_20 -> V_2 ) ;
if ( * V_91 == NULL )
return - V_11 ;
F_14 ( & V_110 ) ;
F_42 ( & ( * V_91 ) -> V_111 , & V_20 -> V_2 -> V_112 ) ;
F_15 ( & V_110 ) ;
return 0 ;
}
int
F_43 ( struct V_87 * V_91 , struct V_1 * V_2 ,
bool V_113 )
{
unsigned int V_114 = F_44 ( V_91 -> V_115 ) ;
struct V_32 V_33 [ 2 ] ;
struct V_27 V_28 = { . V_34 = V_33 ,
. V_116 = 2 } ;
V_33 [ 0 ] . V_37 = ( char * ) V_91 -> V_115 ;
V_33 [ 0 ] . V_54 = 4 ;
V_33 [ 1 ] . V_37 = ( char * ) V_91 -> V_115 + 4 ;
V_33 [ 1 ] . V_54 = V_114 ;
F_45 ( V_91 -> V_115 , F_46 ( V_117 , 80 , V_114 ) ) ;
if ( V_114 > 24 && V_2 -> V_118 && ! V_91 -> V_119 ) {
int V_3 ;
V_3 = F_30 ( & V_28 , V_2 ) ;
if ( V_3 )
F_4 ( V_8 , L_31 ,
V_3 ) ;
}
return F_47 ( V_91 -> V_115 , V_113 ) ;
}
struct V_87 *
F_48 ( struct V_18 * V_20 , struct V_27 * V_28 )
{
int V_3 ;
struct V_35 * V_36 =
(struct V_35 * ) V_28 -> V_34 [ 1 ] . V_37 ;
struct V_87 * V_91 ;
F_33 ( V_20 -> V_2 , V_36 ) ;
V_3 = F_41 ( V_20 , V_36 , & V_91 ) ;
if ( V_3 )
return F_49 ( V_3 ) ;
V_3 = F_29 ( V_28 , V_20 -> V_2 ) ;
if ( V_3 ) {
F_50 ( V_91 ) ;
return F_49 ( V_3 ) ;
}
return V_91 ;
}
struct V_87 *
F_51 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_3 ;
struct V_35 * V_36 =
(struct V_35 * ) V_28 -> V_34 [ 1 ] . V_37 ;
struct V_87 * V_91 ;
F_33 ( V_2 , V_36 ) ;
V_91 = F_37 ( V_36 , V_2 ) ;
if ( V_91 == NULL )
return F_49 ( - V_11 ) ;
V_3 = F_29 ( V_28 , V_2 ) ;
if ( V_3 ) {
F_52 ( V_91 ) ;
return F_49 ( V_3 ) ;
}
return V_91 ;
}
int
F_53 ( struct V_1 * V_2 )
{
struct V_120 * V_13 ;
if ( ! V_2 -> V_5 . V_121 ) {
V_13 = F_54 ( L_32 , 0 , 0 ) ;
if ( F_3 ( V_13 ) ) {
F_4 ( V_8 , L_33 ,
V_17 ) ;
return F_5 ( V_13 ) ;
}
V_2 -> V_5 . V_121 = V_13 ;
}
if ( ! V_2 -> V_5 . V_122 ) {
V_13 = F_54 ( L_32 , 0 , 0 ) ;
if ( F_3 ( V_13 ) ) {
F_55 ( V_2 -> V_5 . V_121 ) ;
V_2 -> V_5 . V_121 = NULL ;
F_4 ( V_8 , L_34 ,
V_17 ) ;
return F_5 ( V_13 ) ;
}
V_2 -> V_5 . V_122 = V_13 ;
}
return 0 ;
}
