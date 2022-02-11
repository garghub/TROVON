int F_1 ( char * * V_1 , int * V_2 , void T_1 * V_3 )
{
struct V_4 V_5 ;
struct V_6 * V_7 ;
int V_8 ;
int V_9 = 0 ;
if ( F_2 ( & V_5 , V_3 , sizeof( V_5 ) ) )
return - V_10 ;
if ( V_5 . V_11 != V_12 ) {
F_3 ( L_1 ,
V_12 , V_5 . V_11 ) ;
return - V_13 ;
}
if ( V_5 . V_14 > V_15 ) {
F_3 ( L_2 ,
V_5 . V_14 , V_15 ) ;
return - V_13 ;
}
if ( V_5 . V_14 < sizeof( struct V_6 ) ) {
F_3 ( L_3 , V_5 . V_14 ) ;
return - V_13 ;
}
* V_1 = F_4 ( V_5 . V_14 , V_16 ) ;
if ( ! * V_1 ) {
F_3 ( L_4 ,
V_5 . V_14 ) ;
return - V_13 ;
}
* V_2 = V_5 . V_14 ;
V_7 = (struct V_6 * ) * V_1 ;
if ( F_2 ( * V_1 , V_3 , V_5 . V_14 ) ) {
V_8 = - V_10 ;
goto V_17;
}
if ( V_5 . V_14 != V_7 -> V_14 ) {
V_8 = - V_13 ;
goto V_17;
}
if ( F_5 ( V_7 ) ) {
F_3 ( L_5 ) ;
V_8 = - V_13 ;
goto V_17;
}
if ( V_7 -> V_18 ) {
V_7 -> V_19 = & V_7 -> V_20 [ 0 ] ;
V_9 += F_6 ( V_7 -> V_18 ) ;
}
if ( V_7 -> V_21 ) {
V_7 -> V_22 = & V_7 -> V_20 [ 0 ] + V_9 ;
V_9 += F_6 ( V_7 -> V_21 ) ;
}
if ( V_7 -> V_23 ) {
V_7 -> V_24 = & V_7 -> V_20 [ 0 ] + V_9 ;
V_9 += F_6 ( V_7 -> V_23 ) ;
}
if ( V_7 -> V_25 )
V_7 -> V_26 = & V_7 -> V_20 [ 0 ] + V_9 ;
return 0 ;
V_17:
F_7 ( * V_1 ) ;
return V_8 ;
}
int F_8 ( void T_1 * V_3 , void * V_7 , int V_2 )
{
int V_8 ;
V_8 = F_9 ( V_3 , V_7 , V_2 ) ? - V_10 : 0 ;
return V_8 ;
}
static int F_10 ( struct V_27 * V_27 , struct V_28 * V_28 )
{
F_11 ( V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_27 * V_27 , struct V_28 * V_28 )
{
F_13 ( V_29 ) ;
return 0 ;
}
static long F_14 ( struct V_28 * V_30 , unsigned int V_31 ,
unsigned long V_3 )
{
int V_8 = 0 ;
if ( ! F_15 ( V_32 ) && ( V_31 != V_33 ) )
return V_8 = - V_34 ;
if ( ( V_31 & 0xffffff00 ) == ( ( int ) 'T' ) << 8 )
return V_8 = - V_35 ;
V_8 = F_16 ( V_31 , ( unsigned long ) V_3 ) ;
return V_8 ;
}
static T_2 F_17 ( struct V_36 * V_37 , struct V_38 * V_39 ,
char * V_1 )
{
return sprintf ( V_1 , L_6 , V_40 ) ;
}
static T_2 F_18 ( struct V_36 * V_37 , struct V_38 * V_39 ,
char * V_1 )
{
return sprintf ( V_1 , L_6 , L_7 ) ;
}
static T_2
F_19 ( struct V_36 * V_37 , struct V_38 * V_39 , char * V_1 )
{
bool V_41 = true ;
int V_42 ;
T_3 V_2 = 0 ;
if ( V_43 )
return sprintf ( V_1 , L_8 ) ;
F_20 ( & V_44 ) ;
for ( V_42 = 0 ; V_42 < F_21 () ; V_42 ++ ) {
struct V_45 * V_46 ;
V_46 = F_22 ( V_42 ) ;
if ( ! V_46 || ! V_46 -> V_47 || ! V_46 -> V_48 )
continue;
F_23 ( V_46 -> V_49 == V_50 ) ;
if ( V_46 -> V_51 )
continue;
F_24 ( V_46 , V_52 , V_53 ) ;
F_25 ( & V_44 ) ;
if ( F_26 ( NULL , V_46 ) )
V_41 = false ;
F_27 ( V_46 , V_52 , V_53 ) ;
F_20 ( & V_44 ) ;
}
F_25 ( & V_44 ) ;
if ( V_41 )
V_2 = sprintf ( V_1 , L_9 ) ;
else
V_2 = sprintf ( V_1 , L_10 ) ;
return V_2 ;
}
static T_2 F_28 ( struct V_36 * V_37 , struct V_38 * V_39 ,
char * V_1 )
{
return snprintf ( V_1 , V_54 , L_6 , V_55 ) ;
}
static T_2 F_29 ( struct V_36 * V_37 , struct V_38 * V_39 ,
const char * V_56 ,
T_3 V_57 )
{
if ( ! V_57 || V_57 > V_58 )
return - V_13 ;
memset ( V_55 , 0 , V_58 + 1 ) ;
memcpy ( V_55 , V_56 , V_57 ) ;
if ( V_55 [ V_57 - 1 ] == '\n' )
V_55 [ V_57 - 1 ] = 0 ;
return V_57 ;
}
static T_2 F_30 ( struct V_36 * V_37 , struct V_38 * V_39 ,
char * V_1 )
{
return snprintf ( V_1 , V_54 , L_6 , V_59 ) ;
}
static T_2 F_31 ( struct V_36 * V_37 , struct V_38 * V_39 ,
const char * V_56 ,
T_3 V_57 )
{
if ( ! V_57 || V_57 > V_60 )
return - V_13 ;
memcpy ( V_59 , V_56 , V_57 ) ;
V_59 [ V_57 ] = 0 ;
if ( V_59 [ V_57 - 1 ] == '\n' )
V_59 [ V_57 - 1 ] = 0 ;
return V_57 ;
}
static void * F_32 ( struct V_61 * V_62 , T_4 * V_63 )
{
if ( * V_63 >= F_21 () )
return NULL ;
return V_63 ;
}
static void F_33 ( struct V_61 * V_62 , void * V_64 )
{
}
static void * F_34 ( struct V_61 * V_62 , void * V_64 , T_4 * V_63 )
{
++ * V_63 ;
if ( * V_63 >= F_21 () )
return NULL ;
return V_63 ;
}
static int F_35 ( struct V_61 * V_62 , void * V_64 )
{
T_4 V_65 = * ( T_4 * ) V_64 ;
struct V_45 * V_46 = F_22 ( ( int ) V_65 ) ;
char * V_66 ;
if ( ! V_46 )
return 0 ;
F_23 ( V_46 -> V_49 == V_50 ) ;
if ( V_46 -> V_51 )
V_66 = L_11 ;
else if ( V_46 -> V_67 )
V_66 = L_12 ;
else if ( V_46 -> V_48 )
V_66 = L_13 ;
else if ( V_46 -> V_47 )
V_66 = L_14 ;
else
V_66 = L_15 ;
F_36 ( V_62 , L_16 ,
( int ) V_65 , V_66 , V_46 -> V_68 -> V_69 ,
V_46 -> V_70 , V_46 -> V_71 . V_72 ,
F_37 ( & V_46 -> V_73 ) ) ;
return 0 ;
}
static int F_38 ( struct V_27 * V_27 , struct V_28 * V_28 )
{
struct V_61 * V_74 ;
int V_75 = F_39 ( V_28 , & V_76 ) ;
if ( V_75 )
return V_75 ;
V_74 = V_28 -> V_77 ;
V_74 -> V_78 = V_27 -> V_79 ;
return 0 ;
}
int F_40 ( void )
{
int V_75 = - V_80 ;
struct V_81 * V_28 ;
V_82 = F_41 ( L_17 , V_83 ) ;
if ( ! V_82 )
goto V_84;
V_75 = F_42 ( V_82 , & V_85 ) ;
if ( V_75 ) {
F_43 ( V_82 ) ;
goto V_84;
}
V_86 = F_44 ( L_17 , NULL ) ;
if ( F_45 ( V_86 ) ) {
V_75 = V_86 ? F_46 ( V_86 )
: - V_80 ;
V_86 = NULL ;
F_43 ( V_82 ) ;
goto V_84;
}
V_28 = F_47 ( L_18 , 0444 , V_86 , NULL ,
& V_87 ) ;
if ( F_45 ( V_28 ) ) {
V_75 = V_28 ? F_46 ( V_28 ) : - V_80 ;
F_43 ( V_82 ) ;
goto V_84;
}
V_84:
return V_75 ;
}
int F_48 ( void )
{
F_49 ( V_86 ) ;
V_86 = NULL ;
F_43 ( V_82 ) ;
return 0 ;
}
