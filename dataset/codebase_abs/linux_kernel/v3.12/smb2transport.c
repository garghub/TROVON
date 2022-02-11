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
int
F_22 ( struct V_18 * V_21 )
{
unsigned char V_48 = 0x0 ;
T_1 V_27 [ 4 ] = { 0 , 0 , 0 , 1 } ;
T_1 V_49 [ 4 ] = { 0 , 0 , 0 , 128 } ;
int V_3 = 0 ;
unsigned char V_50 [ V_29 ] ;
unsigned char * V_51 = V_50 ;
memset ( V_50 , 0x0 , V_29 ) ;
memset ( V_21 -> V_52 , 0x0 , V_53 ) ;
V_3 = F_9 ( V_21 -> V_2 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_13 , V_17 ) ;
goto V_54;
}
V_3 = F_16 ( V_21 -> V_2 -> V_5 . V_7 ,
V_21 -> V_40 . V_41 , V_42 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_14 , V_17 ) ;
goto V_54;
}
V_3 = F_17 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_15 , V_17 ) ;
goto V_54;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_27 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_16 , V_17 ) ;
goto V_54;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
L_17 , 12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_18 , V_17 ) ;
goto V_54;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
& V_48 , 1 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_19 , V_17 ) ;
goto V_54;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
L_20 , 8 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_21 , V_17 ) ;
goto V_54;
}
V_3 = F_18 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_49 , 4 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_22 , V_17 ) ;
goto V_54;
}
V_3 = F_21 ( & V_21 -> V_2 -> V_5 . V_6 -> V_12 ,
V_51 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_12 , V_17 ) ;
goto V_54;
}
memcpy ( V_21 -> V_52 , V_51 , V_53 ) ;
V_54:
return V_3 ;
}
int
F_23 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_27 ;
int V_3 = 0 ;
unsigned char V_55 [ V_56 ] ;
unsigned char * V_30 = V_55 ;
struct V_31 * V_32 = V_26 -> V_33 ;
int V_34 = V_26 -> V_35 ;
struct V_19 * V_36 = (struct V_19 * ) V_32 [ 0 ] . V_37 ;
struct V_18 * V_21 ;
V_21 = F_11 ( V_36 , V_2 ) ;
if ( ! V_21 ) {
F_4 ( V_8 , L_6 , V_17 ) ;
return 0 ;
}
memset ( V_55 , 0x0 , V_56 ) ;
memset ( V_36 -> V_38 , 0x0 , V_39 ) ;
V_3 = F_16 ( V_2 -> V_5 . V_16 ,
V_21 -> V_52 , V_56 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_23 , V_17 ) ;
return V_3 ;
}
V_3 = F_17 ( & V_2 -> V_5 . V_15 -> V_12 ) ;
if ( V_3 ) {
F_4 ( V_8 , L_24 , V_17 ) ;
return V_3 ;
}
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ ) {
if ( V_32 [ V_27 ] . V_43 == 0 )
continue;
if ( V_32 [ V_27 ] . V_37 == NULL ) {
F_4 ( V_8 , L_25 ) ;
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
F_4 ( V_8 , L_26 ,
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
F_4 ( V_8 , L_27 , V_17 ) ;
memcpy ( V_36 -> V_38 , V_30 , V_39 ) ;
return V_3 ;
}
static int
F_24 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_19 * V_36 = V_26 -> V_33 [ 0 ] . V_37 ;
if ( ! ( V_36 -> V_57 & V_58 ) ||
V_2 -> V_59 == V_60 )
return V_3 ;
if ( ! V_2 -> V_61 ) {
strncpy ( V_36 -> V_38 , L_28 , 8 ) ;
return V_3 ;
}
V_3 = V_2 -> V_62 -> V_63 ( V_26 , V_2 ) ;
return V_3 ;
}
int
F_25 ( struct V_25 * V_26 , struct V_1 * V_2 )
{
unsigned int V_3 ;
char V_64 [ 16 ] ;
struct V_19 * V_36 = (struct V_19 * ) V_26 -> V_33 [ 0 ] . V_37 ;
if ( ( V_36 -> V_65 == V_66 ) ||
( V_36 -> V_65 == V_67 ) ||
( V_36 -> V_65 == V_68 ) ||
( ! V_2 -> V_61 ) )
return 0 ;
if ( memcmp ( V_36 -> V_38 , L_29 , 8 ) == 0 )
F_4 ( V_69 , L_30 ,
V_36 -> V_65 ) ;
memcpy ( V_64 , V_36 -> V_38 , V_39 ) ;
memset ( V_36 -> V_38 , 0 , V_39 ) ;
F_26 ( & V_2 -> V_70 ) ;
V_3 = V_2 -> V_62 -> V_63 ( V_26 , V_2 ) ;
F_27 ( & V_2 -> V_70 ) ;
if ( V_3 )
return V_3 ;
if ( memcmp ( V_64 , V_36 -> V_38 ,
V_39 ) )
return - V_71 ;
else
return 0 ;
}
static inline void
F_28 ( struct V_1 * V_2 , struct V_19 * V_72 )
{
V_72 -> V_73 = F_29 ( V_2 ) ;
}
static struct V_74 *
F_30 ( const struct V_19 * V_75 ,
struct V_1 * V_2 )
{
struct V_74 * V_76 ;
if ( V_2 == NULL ) {
F_4 ( V_8 , L_31 ) ;
return NULL ;
}
V_76 = F_31 ( V_77 , V_78 ) ;
if ( V_76 == NULL )
return V_76 ;
else {
memset ( V_76 , 0 , sizeof( struct V_74 ) ) ;
V_76 -> V_79 = V_75 -> V_73 ;
V_76 -> V_80 = V_81 -> V_80 ;
V_76 -> V_82 = V_75 -> V_65 ;
V_76 -> V_83 = V_84 ;
V_76 -> V_2 = V_2 ;
V_76 -> V_85 = V_86 ;
V_76 -> V_87 = V_81 ;
}
F_32 ( & V_88 ) ;
V_76 -> V_89 = V_90 ;
return V_76 ;
}
static int
F_33 ( struct V_18 * V_21 , struct V_19 * V_91 ,
struct V_74 * * V_79 )
{
if ( V_21 -> V_2 -> V_59 == V_92 )
return - V_93 ;
if ( V_21 -> V_2 -> V_59 == V_94 ) {
F_4 ( V_69 , L_32 ) ;
return - V_95 ;
}
if ( V_21 -> V_96 != V_97 ) {
if ( ( V_91 -> V_65 != V_67 ) &&
( V_91 -> V_65 != V_66 ) )
return - V_95 ;
}
* V_79 = F_30 ( V_91 , V_21 -> V_2 ) ;
if ( * V_79 == NULL )
return - V_11 ;
F_12 ( & V_98 ) ;
F_34 ( & ( * V_79 ) -> V_99 , & V_21 -> V_2 -> V_100 ) ;
F_14 ( & V_98 ) ;
return 0 ;
}
int
F_35 ( struct V_74 * V_79 , struct V_1 * V_2 ,
bool V_101 )
{
unsigned int V_102 = F_36 ( V_79 -> V_103 ) ;
struct V_31 V_32 ;
struct V_25 V_26 = { . V_33 = & V_32 ,
. V_35 = 1 } ;
V_32 . V_37 = ( char * ) V_79 -> V_103 ;
V_32 . V_43 = F_36 ( V_79 -> V_103 ) + 4 ;
F_37 ( V_79 -> V_103 , F_38 ( V_104 , 80 , V_102 ) ) ;
if ( V_102 > 24 && V_2 -> V_105 ) {
int V_3 ;
V_3 = F_25 ( & V_26 , V_2 ) ;
if ( V_3 )
F_4 ( V_8 , L_33 ,
V_3 ) ;
}
return F_39 ( V_79 -> V_103 , V_101 ) ;
}
struct V_74 *
F_40 ( struct V_18 * V_21 , struct V_25 * V_26 )
{
int V_3 ;
struct V_19 * V_72 = (struct V_19 * ) V_26 -> V_33 [ 0 ] . V_37 ;
struct V_74 * V_79 ;
F_28 ( V_21 -> V_2 , V_72 ) ;
V_3 = F_33 ( V_21 , V_72 , & V_79 ) ;
if ( V_3 )
return F_41 ( V_3 ) ;
V_3 = F_24 ( V_26 , V_21 -> V_2 ) ;
if ( V_3 ) {
F_42 ( V_79 ) ;
return F_41 ( V_3 ) ;
}
return V_79 ;
}
struct V_74 *
F_43 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_3 ;
struct V_19 * V_72 = (struct V_19 * ) V_26 -> V_33 [ 0 ] . V_37 ;
struct V_74 * V_79 ;
F_28 ( V_2 , V_72 ) ;
V_79 = F_30 ( V_72 , V_2 ) ;
if ( V_79 == NULL )
return F_41 ( - V_11 ) ;
V_3 = F_24 ( V_26 , V_2 ) ;
if ( V_3 ) {
F_44 ( V_79 ) ;
return F_41 ( V_3 ) ;
}
return V_79 ;
}
