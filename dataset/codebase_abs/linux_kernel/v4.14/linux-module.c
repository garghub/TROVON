static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 > F_2 ( 30 ) ) {
F_3 ( L_1 ) ;
return 1 ;
}
if ( V_2 -> V_4 > F_2 ( 30 ) ) {
F_3 ( L_2 ) ;
return 1 ;
}
if ( V_2 -> V_5 > F_2 ( 30 ) ) {
F_3 ( L_3 ) ;
return 1 ;
}
if ( V_2 -> V_6 > F_2 ( 30 ) ) {
F_3 ( L_4 ) ;
return 1 ;
}
if ( V_2 -> V_7 > F_2 ( 30 ) ) {
F_3 ( L_5 ) ;
return 1 ;
}
if ( V_2 -> V_8 && V_2 -> V_4 == 0 ) {
F_3 ( L_6 ) ;
return 1 ;
}
if ( V_2 -> V_9 && V_2 -> V_5 == 0 ) {
F_3 ( L_7 ) ;
return 1 ;
}
if ( V_2 -> V_10 && V_2 -> V_6 == 0 ) {
F_3 ( L_8 ) ;
return 1 ;
}
if ( V_2 -> V_11 && V_2 -> V_7 == 0 ) {
F_3 ( L_9 ) ;
return 1 ;
}
if ( V_2 -> V_12 && V_2 -> V_13 == 0 ) {
F_3 ( L_10 ) ;
return 1 ;
}
if ( V_2 -> V_14 && V_2 -> V_15 == 0 ) {
F_3 ( L_11 ) ;
return 1 ;
}
if ( ! V_2 -> V_12 && V_2 -> V_13 != 0 ) {
F_3 ( L_12 ) ;
return 1 ;
}
if ( ! V_2 -> V_14 && V_2 -> V_15 != 0 ) {
F_3 ( L_13 ) ;
return 1 ;
}
if ( F_4 ( V_2 ) > V_2 -> V_3 ) {
F_3 ( L_14 ,
F_4 ( V_2 ) , V_2 -> V_3 ) ;
return 1 ;
}
return 0 ;
}
int F_5 ( char * * V_16 , int * V_17 , void T_1 * V_18 )
{
struct V_19 V_20 ;
struct V_1 * V_2 ;
int V_21 ;
int V_22 = 0 ;
if ( F_6 ( & V_20 , V_18 , sizeof( V_20 ) ) )
return - V_23 ;
if ( V_20 . V_24 != V_25 ) {
F_3 ( L_15 ,
V_25 , V_20 . V_24 ) ;
return - V_26 ;
}
if ( V_20 . V_3 > V_27 ) {
F_3 ( L_16 ,
V_20 . V_3 , V_27 ) ;
return - V_26 ;
}
if ( V_20 . V_3 < sizeof( struct V_1 ) ) {
F_3 ( L_17 , V_20 . V_3 ) ;
return - V_26 ;
}
* V_16 = F_7 ( V_20 . V_3 , V_28 ) ;
if ( ! * V_16 ) {
F_3 ( L_18 ,
V_20 . V_3 ) ;
return - V_26 ;
}
* V_17 = V_20 . V_3 ;
V_2 = (struct V_1 * ) * V_16 ;
if ( F_6 ( * V_16 , V_18 , V_20 . V_3 ) ) {
V_21 = - V_23 ;
goto V_29;
}
if ( V_20 . V_3 != V_2 -> V_3 ) {
V_21 = - V_26 ;
goto V_29;
}
if ( F_1 ( V_2 ) ) {
F_3 ( L_19 ) ;
V_21 = - V_26 ;
goto V_29;
}
if ( V_2 -> V_4 ) {
V_2 -> V_8 = & V_2 -> V_30 [ 0 ] ;
V_22 += F_8 ( V_2 -> V_4 ) ;
}
if ( V_2 -> V_5 ) {
V_2 -> V_9 = & V_2 -> V_30 [ 0 ] + V_22 ;
V_22 += F_8 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_6 ) {
V_2 -> V_10 = & V_2 -> V_30 [ 0 ] + V_22 ;
V_22 += F_8 ( V_2 -> V_6 ) ;
}
if ( V_2 -> V_7 )
V_2 -> V_11 = & V_2 -> V_30 [ 0 ] + V_22 ;
return 0 ;
V_29:
F_9 ( * V_16 ) ;
return V_21 ;
}
static int F_10 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
F_11 ( V_33 ) ;
return 0 ;
}
static int F_12 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
F_13 ( V_33 ) ;
return 0 ;
}
static long F_14 ( struct V_32 * V_34 , unsigned int V_35 ,
unsigned long V_18 )
{
int V_21 = 0 ;
if ( ! F_15 ( V_36 ) && ( V_35 != V_37 ) )
return V_21 = - V_38 ;
if ( ( V_35 & 0xffffff00 ) == ( ( int ) 'T' ) << 8 )
return V_21 = - V_39 ;
V_21 = F_16 ( V_35 , ( unsigned long ) V_18 ) ;
return V_21 ;
}
static T_2 F_17 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_16 )
{
return sprintf ( V_16 , L_20 , V_44 ) ;
}
static T_2 F_18 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_16 )
{
return sprintf ( V_16 , L_20 , L_21 ) ;
}
static T_2
F_19 ( struct V_40 * V_41 , struct V_42 * V_43 , char * V_16 )
{
bool V_45 = true ;
int V_46 ;
T_3 V_17 = 0 ;
if ( V_47 )
return sprintf ( V_16 , L_22 ) ;
F_20 ( & V_48 ) ;
for ( V_46 = 0 ; V_46 < F_21 () ; V_46 ++ ) {
struct V_49 * V_50 ;
V_50 = F_22 ( V_46 ) ;
if ( ! V_50 || ! V_50 -> V_51 || ! V_50 -> V_52 )
continue;
F_23 ( V_50 -> V_53 == V_54 ) ;
if ( V_50 -> V_55 )
continue;
F_24 ( V_50 , V_56 , V_57 ) ;
F_25 ( & V_48 ) ;
if ( F_26 ( NULL , V_50 ) )
V_45 = false ;
F_27 ( V_50 , V_56 , V_57 ) ;
F_20 ( & V_48 ) ;
}
F_25 ( & V_48 ) ;
if ( V_45 )
V_17 = sprintf ( V_16 , L_23 ) ;
else
V_17 = sprintf ( V_16 , L_24 ) ;
return V_17 ;
}
static T_2 F_28 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_16 )
{
return snprintf ( V_16 , V_58 , L_20 , V_59 ) ;
}
static T_2 F_29 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const char * V_60 ,
T_3 V_61 )
{
if ( ! V_61 || V_61 > V_62 )
return - V_26 ;
memset ( V_59 , 0 , V_62 + 1 ) ;
memcpy ( V_59 , V_60 , V_61 ) ;
if ( V_59 [ V_61 - 1 ] == '\n' )
V_59 [ V_61 - 1 ] = 0 ;
return V_61 ;
}
static T_2 F_30 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_16 )
{
return snprintf ( V_16 , V_58 , L_20 , V_63 ) ;
}
static T_2 F_31 ( struct V_40 * V_41 , struct V_42 * V_43 ,
const char * V_60 ,
T_3 V_61 )
{
if ( ! V_61 || V_61 > V_64 )
return - V_26 ;
memcpy ( V_63 , V_60 , V_61 ) ;
V_63 [ V_61 ] = 0 ;
if ( V_63 [ V_61 - 1 ] == '\n' )
V_63 [ V_61 - 1 ] = 0 ;
return V_61 ;
}
static void * F_32 ( struct V_65 * V_66 , T_4 * V_67 )
{
if ( * V_67 >= F_21 () )
return NULL ;
return V_67 ;
}
static void F_33 ( struct V_65 * V_66 , void * V_68 )
{
}
static void * F_34 ( struct V_65 * V_66 , void * V_68 , T_4 * V_67 )
{
++ * V_67 ;
if ( * V_67 >= F_21 () )
return NULL ;
return V_67 ;
}
static int F_35 ( struct V_65 * V_66 , void * V_68 )
{
T_4 V_69 = * ( T_4 * ) V_68 ;
struct V_49 * V_50 = F_22 ( ( int ) V_69 ) ;
char * V_70 ;
if ( ! V_50 )
return 0 ;
F_23 ( V_50 -> V_53 == V_54 ) ;
if ( V_50 -> V_55 )
V_70 = L_25 ;
else if ( V_50 -> V_71 )
V_70 = L_26 ;
else if ( V_50 -> V_52 )
V_70 = L_27 ;
else if ( V_50 -> V_51 )
V_70 = L_28 ;
else
V_70 = L_29 ;
F_36 ( V_66 , L_30 ,
( int ) V_69 , V_70 , V_50 -> V_72 -> V_73 ,
V_50 -> V_74 , V_50 -> V_75 . V_76 ,
F_37 ( & V_50 -> V_77 ) ) ;
return 0 ;
}
static int F_38 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
struct V_65 * V_78 ;
int V_79 = F_39 ( V_32 , & V_80 ) ;
if ( V_79 )
return V_79 ;
V_78 = V_32 -> V_81 ;
V_78 -> V_82 = V_31 -> V_83 ;
return 0 ;
}
int F_40 ( void )
{
int V_79 = - V_84 ;
struct V_85 * V_32 ;
V_86 = F_41 ( L_31 , V_87 ) ;
if ( ! V_86 )
goto V_88;
V_79 = F_42 ( V_86 , & V_89 ) ;
if ( V_79 ) {
F_43 ( V_86 ) ;
goto V_88;
}
V_90 = F_44 ( L_31 , NULL ) ;
if ( F_45 ( V_90 ) ) {
V_79 = V_90 ? F_46 ( V_90 )
: - V_84 ;
V_90 = NULL ;
F_43 ( V_86 ) ;
goto V_88;
}
V_32 = F_47 ( L_32 , 0444 , V_90 , NULL ,
& V_91 ) ;
if ( F_45 ( V_32 ) ) {
V_79 = V_32 ? F_46 ( V_32 ) : - V_84 ;
F_43 ( V_86 ) ;
goto V_88;
}
V_88:
return V_79 ;
}
int F_48 ( void )
{
F_49 ( V_90 ) ;
V_90 = NULL ;
F_43 ( V_86 ) ;
return 0 ;
}
