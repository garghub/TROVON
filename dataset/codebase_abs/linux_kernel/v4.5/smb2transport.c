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
int V_27 , V_3 ;
unsigned char V_28 [ V_29 ] ;
unsigned char * V_30 = V_28 ;
struct V_31 * V_32 = V_26 -> V_33 ;
int V_34 = V_26 -> V_35 ;
struct V_19 * V_36 = (struct V_19 * ) V_32 [ 0 ] . V_37 ;
struct V_18 * V_21 ;
V_21 = F_11 ( V_36 , V_2 ) ;
if ( ! V_21 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return 0 ;
}
memset ( V_28 , 0x0 , V_29 ) ;
memset ( V_36 -> V_38 , 0x0 , V_39 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_7 , V_17 ) ;
return V_3 ;
}
V_3 = F_16 ( V_2 -> V_5 . V_7 ,
V_21 -> V_40 . V_41 , V_42 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_8 , V_17 ) ;
return V_3 ;
}
V_3 = F_17 ( & V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_9 , V_17 ) ;
return V_3 ;
}
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ ) {
if ( V_32 [ V_27 ] . V_43 == 0 )
continue;
if ( V_32 [ V_27 ] . V_37 == NULL ) {
F_4 ( V_8 , L_10 ) ;
return - V_44 ;
}
if ( V_27 == 0 ) {
if ( V_32 [ 0 ] . V_43 <= 8 )
break;
V_3 =
F_18 (
& V_2 -> V_5 . V_6 -> V_12 ,
V_32 [ V_27 ] . V_37 + 4 , V_32 [ V_27 ] . V_43 - 4 ) ;
} else {
V_3 =
F_18 (
& V_2 -> V_5 . V_6 -> V_12 ,
V_32 [ V_27 ] . V_37 , V_32 [ V_27 ] . V_43 ) ;
}
if ( V_3 ) {
F_4 ( V_8 , L_11 ,
V_17 ) ;
return V_3 ;
}
}
for ( V_27 = 0 ; V_27 < V_26 -> V_45 ; V_27 ++ ) {
struct V_31 V_46 ;
F_19 ( V_26 , V_27 , & V_46 ) ;
F_18 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_46 . V_37 , V_46 . V_43 ) ;
F_20 ( V_26 -> V_47 [ V_27 ] ) ;
}
V_3 = F_21 ( & V_2 -> V_5 . V_6 -> V_12 ,
V_30 ) ;
if ( V_3 )
F_4 ( V_8 , L_12 , V_17 ) ;
memcpy ( V_36 -> V_38 , V_30 , V_39 ) ;
return V_3 ;
}
static int F_22 ( struct V_18 * V_21 , struct V_31 V_48 ,
struct V_31 V_49 , T_1 * V_50 , unsigned int V_51 )
{
unsigned char V_52 = 0x0 ;
T_1 V_27 [ 4 ] = { 0 , 0 , 0 , 1 } ;
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 128 } ;
int V_3 = 0 ;
unsigned char V_54 [ V_29 ] ;
unsigned char * V_55 = V_54 ;
memset ( V_54 , 0x0 , V_29 ) ;
memset ( V_50 , 0x0 , V_51 ) ;
V_3 = F_9 ( V_21 -> V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_13 , V_17 ) ;
goto V_56;
}
V_3 = F_16 ( V_21 -> V_2 -> V_5 . V_7 ,
V_21 -> V_40 . V_41 , V_42 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_14 , V_17 ) ;
goto V_56;
}
V_3 = F_17 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_15 , V_17 ) ;
goto V_56;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_27 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_16 , V_17 ) ;
goto V_56;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_48 . V_37 , V_48 . V_43 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_17 , V_17 ) ;
goto V_56;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
& V_52 , 1 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_18 , V_17 ) ;
goto V_56;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_49 . V_37 , V_49 . V_43 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_19 , V_17 ) ;
goto V_56;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_53 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_20 , V_17 ) ;
goto V_56;
}
V_3 = F_21 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_55 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_12 , V_17 ) ;
goto V_56;
}
memcpy ( V_50 , V_55 , V_51 ) ;
V_56:
return V_3 ;
}
static int
F_23 ( struct V_18 * V_21 ,
const struct V_57 * V_58 )
{
int V_3 ;
V_3 = F_22 ( V_21 , V_58 -> V_59 . V_48 ,
V_58 -> V_59 . V_49 , V_21 -> V_60 ,
V_61 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_22 ( V_21 , V_58 -> V_62 . V_48 ,
V_58 -> V_62 . V_49 , V_21 -> V_63 ,
V_61 ) ;
if ( V_3 )
return V_3 ;
return F_22 ( V_21 , V_58 -> V_64 . V_48 ,
V_58 -> V_64 . V_49 ,
V_21 -> V_65 , V_61 ) ;
}
int
F_24 ( struct V_18 * V_21 )
{
struct V_57 V_66 ;
struct V_67 * V_68 ;
V_68 = & V_66 . V_59 ;
V_68 -> V_48 . V_37 = L_21 ;
V_68 -> V_48 . V_43 = 12 ;
V_68 -> V_49 . V_37 = L_22 ;
V_68 -> V_49 . V_43 = 8 ;
V_68 = & V_66 . V_62 ;
V_68 -> V_48 . V_37 = L_23 ;
V_68 -> V_48 . V_43 = 11 ;
V_68 -> V_49 . V_37 = L_24 ;
V_68 -> V_49 . V_43 = 10 ;
V_68 = & V_66 . V_64 ;
V_68 -> V_48 . V_37 = L_23 ;
V_68 -> V_48 . V_43 = 11 ;
V_68 -> V_49 . V_37 = L_25 ;
V_68 -> V_49 . V_43 = 10 ;
return F_23 ( V_21 , & V_66 ) ;
}
int
F_25 ( struct V_18 * V_21 )
{
struct V_57 V_66 ;
struct V_67 * V_68 ;
V_68 = & V_66 . V_59 ;
V_68 -> V_48 . V_37 = L_21 ;
V_68 -> V_48 . V_43 = 12 ;
V_68 -> V_49 . V_37 = L_22 ;
V_68 -> V_49 . V_43 = 8 ;
V_68 = & V_66 . V_62 ;
V_68 -> V_48 . V_37 = L_23 ;
V_68 -> V_48 . V_43 = 11 ;
V_68 -> V_49 . V_37 = L_24 ;
V_68 -> V_49 . V_43 = 10 ;
V_68 = & V_66 . V_64 ;
V_68 -> V_48 . V_37 = L_23 ;
V_68 -> V_48 . V_43 = 11 ;
V_68 -> V_49 . V_37 = L_25 ;
V_68 -> V_49 . V_43 = 10 ;
return F_23 ( V_21 , & V_66 ) ;
}
int
F_26 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_27 ;
int V_3 = 0 ;
unsigned char V_69 [ V_70 ] ;
unsigned char * V_30 = V_69 ;
struct V_31 * V_32 = V_26 -> V_33 ;
int V_34 = V_26 -> V_35 ;
struct V_19 * V_36 = (struct V_19 * ) V_32 [ 0 ] . V_37 ;
struct V_18 * V_21 ;
V_21 = F_11 ( V_36 , V_2 ) ;
if ( ! V_21 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return 0 ;
}
memset ( V_69 , 0x0 , V_70 ) ;
memset ( V_36 -> V_38 , 0x0 , V_39 ) ;
V_3 = F_16 ( V_2 -> V_5 . V_16 ,
V_21 -> V_60 , V_70 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_26 , V_17 ) ;
return V_3 ;
}
V_3 = F_17 ( & V_2 -> V_5 . V_15 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_27 , V_17 ) ;
return V_3 ;
}
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ ) {
if ( V_32 [ V_27 ] . V_43 == 0 )
continue;
if ( V_32 [ V_27 ] . V_37 == NULL ) {
F_4 ( V_8 , L_28 ) ;
return - V_44 ;
}
if ( V_27 == 0 ) {
if ( V_32 [ 0 ] . V_43 <= 8 )
break;
V_3 =
F_18 (
& V_2 -> V_5 . V_15 -> V_12 ,
V_32 [ V_27 ] . V_37 + 4 , V_32 [ V_27 ] . V_43 - 4 ) ;
} else {
V_3 =
F_18 (
& V_2 -> V_5 . V_15 -> V_12 ,
V_32 [ V_27 ] . V_37 , V_32 [ V_27 ] . V_43 ) ;
}
if ( V_3 ) {
F_4 ( V_8 , L_29 ,
V_17 ) ;
return V_3 ;
}
}
for ( V_27 = 0 ; V_27 < V_26 -> V_45 ; V_27 ++ ) {
struct V_31 V_46 ;
F_19 ( V_26 , V_27 , & V_46 ) ;
F_18 ( & V_2 -> V_5 . V_15 -> V_12 ,
V_46 . V_37 , V_46 . V_43 ) ;
F_20 ( V_26 -> V_47 [ V_27 ] ) ;
}
V_3 = F_21 ( & V_2 -> V_5 . V_15 -> V_12 ,
V_30 ) ;
if ( V_3 )
F_4 ( V_8 , L_30 , V_17 ) ;
memcpy ( V_36 -> V_38 , V_30 , V_39 ) ;
return V_3 ;
}
static int
F_27 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_19 * V_36 = V_26 -> V_33 [ 0 ] . V_37 ;
if ( ! ( V_36 -> V_71 & V_72 ) ||
V_2 -> V_73 == V_74 )
return V_3 ;
if ( ! V_2 -> V_75 ) {
strncpy ( V_36 -> V_38 , L_31 , 8 ) ;
return V_3 ;
}
V_3 = V_2 -> V_76 -> V_77 ( V_26 , V_2 ) ;
return V_3 ;
}
int
F_28 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
unsigned int V_3 ;
char V_78 [ 16 ] ;
struct V_19 * V_36 = (struct V_19 * ) V_26 -> V_33 [ 0 ] . V_37 ;
if ( ( V_36 -> V_79 == V_80 ) ||
( V_36 -> V_79 == V_81 ) ||
( V_36 -> V_79 == V_82 ) ||
( ! V_2 -> V_75 ) )
return 0 ;
if ( memcmp ( V_36 -> V_38 , L_32 , 8 ) == 0 )
F_4 ( V_83 , L_33 ,
V_36 -> V_79 ) ;
memcpy ( V_78 , V_36 -> V_38 , V_39 ) ;
memset ( V_36 -> V_38 , 0 , V_39 ) ;
F_29 ( & V_2 -> V_84 ) ;
V_3 = V_2 -> V_76 -> V_77 ( V_26 , V_2 ) ;
F_30 ( & V_2 -> V_84 ) ;
if ( V_3 )
return V_3 ;
if ( memcmp ( V_78 , V_36 -> V_38 ,
V_39 ) )
return - V_85 ;
else
return 0 ;
}
static inline void
F_31 ( struct V_1 * V_2 , struct V_19 * V_86 )
{
unsigned int V_27 , V_87 = F_32 ( V_86 -> V_88 ) ;
V_86 -> V_89 = F_33 ( V_2 ) ;
for ( V_27 = 1 ; V_27 < V_87 ; V_27 ++ )
F_34 ( V_2 ) ;
}
static struct V_90 *
F_35 ( const struct V_19 * V_91 ,
struct V_1 * V_2 )
{
struct V_90 * V_92 ;
if ( V_2 == NULL ) {
F_4 ( V_8 , L_34 ) ;
return NULL ;
}
V_92 = F_36 ( V_93 , V_94 ) ;
if ( V_92 == NULL )
return V_92 ;
else {
memset ( V_92 , 0 , sizeof( struct V_90 ) ) ;
V_92 -> V_95 = F_37 ( V_91 -> V_89 ) ;
V_92 -> V_96 = V_97 -> V_96 ;
V_92 -> V_98 = V_91 -> V_79 ;
V_92 -> V_99 = V_100 ;
V_92 -> V_2 = V_2 ;
V_92 -> V_101 = V_102 ;
V_92 -> V_103 = V_97 ;
}
F_38 ( & V_104 ) ;
V_92 -> V_105 = V_106 ;
return V_92 ;
}
static int
F_39 ( struct V_18 * V_21 , struct V_19 * V_107 ,
struct V_90 * * V_95 )
{
if ( V_21 -> V_2 -> V_73 == V_108 )
return - V_109 ;
if ( V_21 -> V_2 -> V_73 == V_110 ) {
F_4 ( V_83 , L_35 ) ;
return - V_111 ;
}
if ( V_21 -> V_112 == V_113 ) {
if ( ( V_107 -> V_79 != V_81 ) &&
( V_107 -> V_79 != V_80 ) )
return - V_111 ;
}
if ( V_21 -> V_112 == V_108 ) {
if ( V_107 -> V_79 != V_114 )
return - V_111 ;
}
* V_95 = F_35 ( V_107 , V_21 -> V_2 ) ;
if ( * V_95 == NULL )
return - V_11 ;
F_12 ( & V_115 ) ;
F_40 ( & ( * V_95 ) -> V_116 , & V_21 -> V_2 -> V_117 ) ;
F_14 ( & V_115 ) ;
return 0 ;
}
int
F_41 ( struct V_90 * V_95 , struct V_1 * V_2 ,
bool V_118 )
{
unsigned int V_119 = F_42 ( V_95 -> V_120 ) ;
struct V_31 V_32 ;
struct V_25 V_26 = { . V_33 = & V_32 ,
. V_35 = 1 } ;
V_32 . V_37 = ( char * ) V_95 -> V_120 ;
V_32 . V_43 = F_42 ( V_95 -> V_120 ) + 4 ;
F_43 ( V_95 -> V_120 , F_44 ( V_121 , 80 , V_119 ) ) ;
if ( V_119 > 24 && V_2 -> V_122 ) {
int V_3 ;
V_3 = F_28 ( & V_26 , V_2 ) ;
if ( V_3 )
F_4 ( V_8 , L_36 ,
V_3 ) ;
}
return F_45 ( V_95 -> V_120 , V_118 ) ;
}
struct V_90 *
F_46 ( struct V_18 * V_21 , struct V_25 * V_26 )
{
int V_3 ;
struct V_19 * V_86 = (struct V_19 * ) V_26 -> V_33 [ 0 ] . V_37 ;
struct V_90 * V_95 ;
F_31 ( V_21 -> V_2 , V_86 ) ;
V_3 = F_39 ( V_21 , V_86 , & V_95 ) ;
if ( V_3 )
return F_47 ( V_3 ) ;
V_3 = F_27 ( V_26 , V_21 -> V_2 ) ;
if ( V_3 ) {
F_48 ( V_95 ) ;
return F_47 ( V_3 ) ;
}
return V_95 ;
}
struct V_90 *
F_49 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_3 ;
struct V_19 * V_86 = (struct V_19 * ) V_26 -> V_33 [ 0 ] . V_37 ;
struct V_90 * V_95 ;
F_31 ( V_2 , V_86 ) ;
V_95 = F_35 ( V_86 , V_2 ) ;
if ( V_95 == NULL )
return F_47 ( - V_11 ) ;
V_3 = F_27 ( V_26 , V_2 ) ;
if ( V_3 ) {
F_50 ( V_95 ) ;
return F_47 ( V_3 ) ;
}
return V_95 ;
}
