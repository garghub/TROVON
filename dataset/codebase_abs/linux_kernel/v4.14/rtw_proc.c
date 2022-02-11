inline struct V_1 * F_1 ( const char * V_2 , struct V_1 * V_3 , void * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_2 , V_6 | V_7 , V_3 , V_4 ) ;
return V_5 ;
}
inline struct V_1 * F_3 ( const char * V_2 , struct V_1 * V_3 ,
const struct V_8 * V_9 , void * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_4 ( V_2 , V_10 | V_6 , V_3 , V_9 , V_4 ) ;
return V_5 ;
}
static int F_5 ( struct V_11 * V_12 , void * V_13 )
{
return 0 ;
}
static int F_6 ( struct V_11 * V_12 , void * V_13 )
{
F_7 ( V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 , void * V_13 )
{
F_9 ( V_12 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
char V_18 [ 32 ] ;
int V_19 ;
if ( V_16 < 1 )
return - V_20 ;
if ( V_15 && ! F_11 ( V_18 , V_15 , sizeof( V_18 ) ) ) {
sscanf ( V_18 , L_1 , & V_19 ) ;
if ( V_19 >= V_21 && V_19 <= V_22 )
{
V_23 = V_19 ;
F_12 ( L_2 , V_23 ) ;
}
} else {
return - V_24 ;
}
return V_16 ;
}
static int F_13 ( struct V_25 * V_25 , struct V_14 * V_14 )
{
T_1 V_26 = ( T_1 ) F_14 ( V_25 ) ;
const struct V_27 * V_28 = V_29 + V_26 ;
return F_15 ( V_14 , V_28 -> V_30 , NULL ) ;
}
static T_1 F_16 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 )
{
T_1 V_26 = ( T_1 ) F_14 ( F_17 ( V_14 ) ) ;
const struct V_27 * V_28 = V_29 + V_26 ;
T_1 (* F_18)( struct V_14 * , const char T_2 * , T_3 , T_4 * , void * ) = V_28 -> F_18 ;
if ( F_18 )
return F_18 ( V_14 , V_15 , V_16 , V_17 , NULL ) ;
return - V_31 ;
}
int F_19 ( void )
{
int V_32 = V_33 ;
T_1 V_34 ;
struct V_1 * V_5 = NULL ;
if ( V_35 != NULL ) {
F_20 ( 1 ) ;
goto exit;
}
V_35 = F_1 ( V_36 , V_37 , NULL ) ;
if ( V_35 == NULL ) {
F_20 ( 1 ) ;
goto exit;
}
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ ) {
V_5 = F_3 ( V_29 [ V_34 ] . V_2 , V_35 , & V_39 , ( void * ) V_34 ) ;
if ( ! V_5 ) {
F_20 ( 1 ) ;
goto exit;
}
}
V_32 = V_40 ;
exit:
return V_32 ;
}
void F_21 ( void )
{
int V_34 ;
if ( V_35 == NULL )
return;
for ( V_34 = 0 ; V_34 < V_38 ; V_34 ++ )
F_22 ( V_29 [ V_34 ] . V_2 , V_35 ) ;
F_22 ( V_36 , V_37 ) ;
V_35 = NULL ;
}
static int F_23 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
F_25 ( V_12 , V_44 ) ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
F_27 ( V_12 , V_44 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
F_29 ( V_12 , V_44 ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
F_31 ( V_12 , V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_45 = (struct V_44 * ) F_24 ( V_42 ) ;
if ( V_45 )
F_33 ( V_12 , L_3 , ( V_45 -> V_46 ) ? L_4 : L_5 ) ;
return 0 ;
}
static T_1 F_34 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
struct V_41 * V_42 = V_4 ;
struct V_44 * V_45 = (struct V_44 * ) F_24 ( V_42 ) ;
char V_18 [ 2 ] ;
int V_47 = 0 ;
if ( V_16 < 1 )
return - V_24 ;
if ( V_15 && ! F_11 ( V_18 , V_15 , sizeof( V_18 ) ) ) {
if ( V_45 )
{
F_35 ( V_45 , V_47 ) ;
}
}
return V_16 ;
}
static int F_36 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_45 = (struct V_44 * ) F_24 ( V_42 ) ;
struct V_48 * V_49 = V_45 -> V_50 ;
struct V_51 * V_52 = & V_49 -> V_53 ;
F_33 ( V_12 , L_6 , ( unsigned long long ) V_52 -> V_54 ) ;
F_33 ( V_12 , L_7 , ( unsigned long long ) V_52 -> V_55 ) ;
F_33 ( V_12 , L_8 , ( unsigned long long ) V_52 -> V_56 ) ;
F_33 ( V_12 , L_9 , ( unsigned long long ) V_52 -> V_57 ) ;
F_33 ( V_12 , L_10 , ( unsigned long long ) V_52 -> V_58 ) ;
return 0 ;
}
static T_1 F_37 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
struct V_41 * V_42 = V_4 ;
struct V_44 * V_45 = (struct V_44 * ) F_24 ( V_42 ) ;
struct V_48 * V_49 = V_45 -> V_50 ;
struct V_51 * V_52 = & V_49 -> V_53 ;
char V_59 [ 32 ] ;
if ( V_15 && ! F_11 ( V_59 , V_15 , sizeof( V_59 ) ) ) {
if ( '0' == V_59 [ 0 ] ) {
V_52 -> V_54 = 0 ;
V_52 -> V_55 = 0 ;
V_52 -> V_56 = 0 ;
V_52 -> V_57 = 0 ;
V_52 -> V_58 = 0 ;
}
}
return V_16 ;
}
static int F_38 ( struct V_11 * V_12 , void * V_13 )
{
return 0 ;
}
static T_1 F_39 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
struct V_41 * V_42 = V_4 ;
struct V_44 * V_44 ;
char V_18 [ 32 ] ;
char V_59 [ 5 ] ;
T_5 V_60 ;
V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
if ( ! V_44 )
return - V_24 ;
if ( V_15 && ! F_11 ( V_18 , V_15 , sizeof( V_18 ) ) ) {
int V_61 = sscanf ( V_18 , L_11 , V_59 , & V_60 ) ;
if ( V_61 < 2 )
return V_16 ;
if ( V_60 >= V_62 )
return - V_20 ;
if ( strcmp ( L_12 , V_59 ) == 0 ) {
F_40 ( V_44 , V_60 ) ;
V_44 -> V_63 . V_64 = false ;
} else if ( strcmp ( L_13 , V_59 ) == 0 ) {
F_41 ( V_44 , V_60 ) ;
}
}
return V_16 ;
}
static int F_42 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
struct V_48 * V_50 = F_43 ( V_44 ) ;
T_5 V_34 ;
F_33 ( V_12 , L_14 , V_50 -> V_65 . V_66 ) ;
F_33 ( V_12 , L_15
L_16
, L_17 , L_18 , L_19 , L_20 , L_21 , L_22
) ;
for ( V_34 = 0 ; V_34 < 32 ; V_34 ++ ) {
if ( V_50 -> V_67 [ V_34 ] . V_68 != 0 )
F_33 ( V_12 , L_23 V_69 L_24 V_70 L_25
L_16 , V_34
, V_50 -> V_67 [ V_34 ] . V_68
, F_44 ( V_50 -> V_67 [ V_34 ] . V_71 )
, F_45 ( V_50 -> V_67 [ V_34 ] . V_72 )
, ( V_50 -> V_67 [ V_34 ] . V_68 ) & 0x03
, F_46 ( ( ( V_50 -> V_67 [ V_34 ] . V_68 ) >> 2 ) & 0x07 )
) ;
}
return 0 ;
}
static int F_47 ( struct V_25 * V_25 , struct V_14 * V_14 )
{
T_1 V_26 = ( T_1 ) F_14 ( V_25 ) ;
const struct V_27 * V_28 = V_73 + V_26 ;
return F_15 ( V_14 , V_28 -> V_30 , F_48 ( V_25 ) ) ;
}
static T_1 F_49 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 )
{
T_1 V_26 = ( T_1 ) F_14 ( F_17 ( V_14 ) ) ;
const struct V_27 * V_28 = V_73 + V_26 ;
T_1 (* F_18)( struct V_14 * , const char T_2 * , T_3 , T_4 * , void * ) = V_28 -> F_18 ;
if ( F_18 )
return F_18 ( V_14 , V_15 , V_16 , V_17 , ( (struct V_11 * ) V_14 -> V_74 ) -> V_43 ) ;
return - V_31 ;
}
int F_50 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
F_51 ( V_12 , V_44 ) ;
return 0 ;
}
T_1 F_52 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
struct V_41 * V_42 = V_4 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
char V_18 [ 32 ] ;
T_6 V_75 ;
if ( V_16 < 1 )
return - V_24 ;
if ( V_15 && ! F_11 ( V_18 , V_15 , sizeof( V_18 ) ) ) {
int V_61 = sscanf ( V_18 , L_26 , & V_75 ) ;
if ( V_61 != 1 )
return V_16 ;
F_53 ( V_44 , V_75 ) ;
}
return V_16 ;
}
int F_54 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
F_55 ( V_12 , V_44 ) ;
return 0 ;
}
T_1 F_56 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
struct V_41 * V_42 = V_4 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
char V_18 [ 32 ] ;
T_7 V_76 ;
if ( V_16 < 1 )
return - V_24 ;
if ( V_15 && ! F_11 ( V_18 , V_15 , sizeof( V_18 ) ) ) {
int V_61 = sscanf ( V_18 , L_27 , & V_76 ) ;
if ( V_61 != 1 )
return V_16 ;
F_57 ( V_44 , V_76 ) ;
}
return V_16 ;
}
static int F_58 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
F_59 ( V_12 , V_44 ) ;
return 0 ;
}
static T_1 F_60 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
struct V_41 * V_42 = V_4 ;
struct V_44 * V_44 = (struct V_44 * ) F_24 ( V_42 ) ;
char V_18 [ 32 ] ;
T_7 V_77 ;
if ( V_16 < 1 )
return - V_24 ;
if ( V_15 && ! F_11 ( V_18 , V_15 , sizeof( V_18 ) ) ) {
int V_61 = sscanf ( V_18 , L_28 , & V_77 ) ;
if ( V_61 != 1 )
return V_16 ;
F_61 ( V_44 , V_77 ) ;
}
return V_16 ;
}
int F_62 ( struct V_11 * V_12 , void * V_13 )
{
struct V_41 * V_42 = V_12 -> V_43 ;
struct V_44 * V_45 = (struct V_44 * ) F_24 ( V_42 ) ;
F_63 ( V_12 , V_45 ) ;
return 0 ;
}
T_1 F_64 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 , void * V_4 )
{
struct V_41 * V_42 = V_4 ;
struct V_44 * V_45 = (struct V_44 * ) F_24 ( V_42 ) ;
char V_18 [ 32 ] ;
T_7 V_78 ;
T_8 V_79 ;
T_7 V_80 ;
int V_81 ;
T_5 V_82 ;
T_5 V_83 ;
if ( V_16 < 1 )
return - V_24 ;
if ( V_15 && ! F_11 ( V_18 , V_15 , sizeof( V_18 ) ) ) {
int V_61 = sscanf ( V_18 , L_29 ,
& V_78 , & V_79 , & V_80 , & V_81 , & V_82 , & V_83 ) ;
if ( V_61 != 6 )
return V_16 ;
F_65 ( V_45 , ( T_8 ) V_78 , V_79 , ( T_8 ) V_80 , ( bool ) V_81 , V_82 , V_83 ) ;
}
return V_16 ;
}
static int F_66 ( struct V_25 * V_25 , struct V_14 * V_14 )
{
T_1 V_26 = ( T_1 ) F_14 ( V_25 ) ;
const struct V_27 * V_28 = V_84 + V_26 ;
return F_15 ( V_14 , V_28 -> V_30 , F_48 ( V_25 ) ) ;
}
static T_1 F_67 ( struct V_14 * V_14 , const char T_2 * V_15 , T_3 V_16 , T_4 * V_17 )
{
T_1 V_26 = ( T_1 ) F_14 ( F_17 ( V_14 ) ) ;
const struct V_27 * V_28 = V_84 + V_26 ;
T_1 (* F_18)( struct V_14 * , const char T_2 * , T_3 , T_4 * , void * ) = V_28 -> F_18 ;
if ( F_18 )
return F_18 ( V_14 , V_15 , V_16 , V_17 , ( (struct V_11 * ) V_14 -> V_74 ) -> V_43 ) ;
return - V_31 ;
}
static struct V_1 * F_68 ( struct V_41 * V_42 )
{
struct V_1 * V_85 = NULL ;
struct V_1 * V_5 = NULL ;
struct V_44 * V_44 = F_24 ( V_42 ) ;
T_1 V_34 ;
if ( V_44 -> V_86 == NULL ) {
F_20 ( 1 ) ;
goto exit;
}
if ( V_44 -> V_85 != NULL ) {
F_20 ( 1 ) ;
goto exit;
}
V_85 = F_1 ( L_30 , V_44 -> V_86 , V_42 ) ;
if ( V_85 == NULL ) {
F_20 ( 1 ) ;
goto exit;
}
V_44 -> V_85 = V_85 ;
for ( V_34 = 0 ; V_34 < V_87 ; V_34 ++ ) {
V_5 = F_3 ( V_84 [ V_34 ] . V_2 , V_85 , & V_88 , ( void * ) V_34 ) ;
if ( ! V_5 ) {
F_20 ( 1 ) ;
goto exit;
}
}
exit:
return V_85 ;
}
static void F_69 ( struct V_44 * V_44 )
{
struct V_1 * V_85 = NULL ;
int V_34 ;
V_85 = V_44 -> V_85 ;
if ( V_85 == NULL ) {
F_20 ( 1 ) ;
return;
}
for ( V_34 = 0 ; V_34 < V_87 ; V_34 ++ )
F_22 ( V_84 [ V_34 ] . V_2 , V_85 ) ;
F_22 ( L_30 , V_44 -> V_86 ) ;
V_44 -> V_85 = NULL ;
}
struct V_1 * F_70 ( struct V_41 * V_42 )
{
struct V_1 * V_89 = V_35 ;
struct V_1 * V_86 = NULL ;
struct V_1 * V_5 = NULL ;
struct V_44 * V_44 = F_24 ( V_42 ) ;
T_1 V_34 ;
if ( V_89 == NULL ) {
F_20 ( 1 ) ;
goto exit;
}
if ( V_44 -> V_86 != NULL ) {
F_20 ( 1 ) ;
goto exit;
}
V_86 = F_1 ( V_42 -> V_2 , V_89 , V_42 ) ;
if ( V_86 == NULL ) {
F_20 ( 1 ) ;
goto exit;
}
V_44 -> V_86 = V_86 ;
for ( V_34 = 0 ; V_34 < V_90 ; V_34 ++ ) {
V_5 = F_3 ( V_73 [ V_34 ] . V_2 , V_86 , & V_91 , ( void * ) V_34 ) ;
if ( ! V_5 ) {
F_20 ( 1 ) ;
goto exit;
}
}
F_68 ( V_42 ) ;
exit:
return V_86 ;
}
void F_71 ( struct V_41 * V_42 )
{
struct V_1 * V_89 = V_35 ;
struct V_1 * V_86 = NULL ;
struct V_44 * V_44 = F_24 ( V_42 ) ;
int V_34 ;
V_86 = V_44 -> V_86 ;
if ( V_86 == NULL ) {
F_20 ( 1 ) ;
return;
}
for ( V_34 = 0 ; V_34 < V_90 ; V_34 ++ )
F_22 ( V_73 [ V_34 ] . V_2 , V_86 ) ;
F_69 ( V_44 ) ;
F_22 ( V_42 -> V_2 , V_89 ) ;
V_44 -> V_86 = NULL ;
}
void F_72 ( struct V_41 * V_42 )
{
struct V_1 * V_89 = V_35 ;
struct V_1 * V_86 = NULL ;
struct V_44 * V_44 = F_24 ( V_42 ) ;
int V_34 ;
V_86 = V_44 -> V_86 ;
if ( V_86 == NULL ) {
F_20 ( 1 ) ;
return;
}
for ( V_34 = 0 ; V_34 < V_90 ; V_34 ++ )
F_22 ( V_73 [ V_34 ] . V_2 , V_86 ) ;
F_69 ( V_44 ) ;
F_22 ( V_44 -> V_92 , V_89 ) ;
V_44 -> V_86 = NULL ;
F_70 ( V_42 ) ;
}
