static int F_1 ( struct V_1 * V_2 , const void * V_3 )
{
const int * V_4 = V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_4 == * V_4 )
return 1 ;
return 0 ;
}
static struct V_5 * F_3 ( int V_4 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
V_2 = F_4 ( & V_7 , NULL , & V_4 , F_1 ) ;
if ( V_2 )
V_6 = F_2 ( V_2 ) ;
return V_6 ;
}
static int F_5 ( void )
{
int V_4 = 0 ;
for (; ; ) {
if ( ! F_3 ( V_4 ) )
return V_4 ;
if ( ++ V_4 < 0 )
V_4 = 0 ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_7 ( V_2 , struct V_8 , V_2 ) ;
struct V_5 * V_6 = F_7 ( V_8 , struct V_5 , V_8 ) ;
F_8 ( V_6 ) ;
F_9 ( V_6 ) ;
}
void F_10 ( struct V_5 * V_6 )
{
struct V_8 * V_8 = & V_6 -> V_8 ;
F_11 ( V_8 ) ;
V_6 -> V_8 . V_2 . V_9 = & V_7 ;
V_6 -> V_8 . V_2 . V_10 = F_6 ;
F_12 ( V_6 ) ;
V_6 -> V_11 = - 1 ;
V_6 -> V_12 = V_13 ;
F_13 ( & V_6 -> V_14 . V_15 ) ;
F_14 ( & V_6 -> V_14 . V_16 ) ;
F_13 ( & V_6 -> V_17 . V_15 ) ;
F_14 ( & V_6 -> V_17 . V_16 ) ;
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
}
struct V_5 * F_19 ( void )
{
struct V_5 * V_6 ;
V_6 = F_20 ( sizeof( * V_6 ) , V_18 ) ;
if ( V_6 == NULL )
return NULL ;
F_10 ( V_6 ) ;
return V_6 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_8 * V_8 = F_22 ( V_2 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
struct V_22 * V_23 ;
void * V_24 ;
T_2 V_25 ;
int V_26 = 0 ;
V_26 = F_23 ( V_21 , V_27 , L_1 ) ;
F_24 ( & V_6 -> V_28 ) ;
V_24 = V_6 -> V_29 -> V_30 ;
V_25 = F_25 ( V_6 -> V_29 -> V_31 ) ;
for (; ; ) {
V_23 = F_26 ( & V_24 , & V_25 ) ;
if ( ! V_23 )
break;
if ( V_23 -> V_32 == V_33 ) {
V_26 = F_27 ( V_23 ,
V_23 -> V_34 + sizeof( struct V_22 ) ,
V_21 , V_27 ) ;
break;
}
}
F_28 ( & V_6 -> V_28 ) ;
return V_26 ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const char * V_21 , T_2 V_35 )
{
struct V_8 * V_8 = F_22 ( V_2 ) ;
struct V_5 * V_6 = V_8 -> V_6 ;
char V_36 [ 255 ] ;
int V_26 , V_37 = 0 ;
const char * V_38 = V_21 ;
struct V_22 * V_23 ;
if ( strlen ( V_21 ) <= 1 ) {
F_30 ( V_6 , V_33 ) ;
return V_35 ;
}
while ( V_37 < sizeof( V_36 ) ) {
int V_39 ;
if ( sscanf ( V_38 , L_2 ,
& ( V_36 [ V_37 ] ) , & V_39 ) > 0 ) {
++ V_37 ;
V_38 += V_39 ;
} else {
break;
}
}
if ( V_37 < sizeof( struct V_22 ) ) {
F_31 ( V_2 , L_3 , V_40 , V_37 ) ;
return - V_41 ;
}
V_23 = (struct V_22 * ) V_36 ;
if ( V_23 -> V_32 != V_33 ) {
F_31 ( V_2 , L_4 ,
V_40 , V_23 -> V_32 ) ;
return - V_41 ;
}
if ( V_23 -> V_34 > ( V_37 - sizeof( struct V_22 ) ) )
V_23 -> V_34 = V_37 - sizeof( struct V_22 ) ;
F_30 ( V_6 , V_33 ) ;
V_26 = F_32 ( V_6 , V_23 , V_23 -> V_34 + sizeof( struct V_22 ) ) ;
return V_26 >= 0 ? V_35 : V_26 ;
}
static int F_33 ( struct V_5 * V_6 )
{
return F_34 ( & V_6 -> V_8 . V_2 . V_42 , & V_43 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
F_36 ( & V_6 -> V_8 . V_2 . V_42 , & V_43 ) ;
}
static
int F_37 ( struct V_5 * V_6 )
{
int V_26 ;
struct V_1 * V_2 = & V_6 -> V_8 . V_2 ;
struct V_8 * V_8 = & V_6 -> V_8 ;
char V_44 [ V_45 ] ;
struct V_46 V_47 ;
V_26 = F_38 ( V_6 , & V_47 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 , L_5 , V_26 ) ;
return V_26 ;
}
if ( F_39 ( & V_47 ) || F_40 ( & V_47 ) ) {
V_47 . V_3 [ 0 ] = 0x02 ;
F_41 ( & V_47 . V_3 [ 1 ] , sizeof( V_47 . V_3 ) - 1 ) ;
V_26 = F_42 ( V_6 , & V_47 ) ;
if ( V_26 < 0 ) {
F_43 ( V_44 , sizeof( V_44 ) , & V_47 ) ;
F_31 ( V_2 , L_6 ,
V_44 , V_26 ) ;
return V_26 ;
}
}
V_8 -> V_48 = V_47 ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
int V_26 ;
struct V_1 * V_2 = & V_6 -> V_8 . V_2 ;
V_26 = F_45 ( V_6 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 , L_7 , V_26 ) ;
goto error;
}
V_26 = F_37 ( V_6 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 , L_8 , V_26 ) ;
goto error;
}
V_26 = F_46 ( V_6 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 , L_9 , V_26 ) ;
goto error;
}
V_26 = F_47 ( V_6 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 , L_10 , V_26 ) ;
goto V_49;
}
V_26 = F_48 ( V_6 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 , L_11 , V_26 ) ;
goto V_50;
}
F_49 ( V_6 ) ;
return 0 ;
V_50:
F_8 ( V_6 ) ;
V_49:
error:
return V_26 ;
}
int F_50 ( struct V_5 * V_6 , struct V_1 * V_51 , void * V_52 )
{
int V_26 ;
struct V_1 * V_2 ;
char V_53 [ V_45 ] , V_54 [ V_45 ] ;
V_6 -> V_4 = F_5 () ;
V_2 = & V_6 -> V_8 . V_2 ;
F_51 ( V_2 , L_12 , V_6 -> V_4 ) ;
V_6 -> V_52 = V_52 ;
F_52 ( & V_6 -> V_55 . V_56 ) ;
F_13 ( & V_6 -> V_55 . V_57 ) ;
F_53 ( & V_6 -> V_55 . V_58 ) ;
F_54 ( V_6 ) ;
V_26 = V_6 -> V_59 ( V_6 ) ;
if ( V_26 < 0 )
goto V_60;
V_26 = F_44 ( V_6 ) ;
if ( V_26 < 0 ) {
F_31 ( V_2 , L_13 , V_26 ) ;
goto V_61;
}
V_26 = F_55 ( & V_6 -> V_8 , V_51 , V_6 ) ;
if ( V_26 < 0 && V_26 != - V_62 )
goto V_63;
V_26 = F_33 ( V_6 ) ;
if ( V_26 < 0 ) {
F_31 ( V_51 , L_14
L_15 , V_26 ) ;
goto V_64;
}
F_43 ( V_53 , sizeof( V_53 ) , & V_6 -> V_8 . V_48 ) ;
F_56 ( V_54 , sizeof( V_54 ) , & V_6 -> V_8 . V_65 ) ;
F_57 ( V_2 ,
L_16 ,
V_53 , V_54 , V_51 -> V_66 -> V_67 , F_58 ( V_51 ) ) ;
V_6 -> V_68 = 1 ;
return 0 ;
V_64:
F_59 ( & V_6 -> V_8 ) ;
V_63:
V_61:
V_6 -> V_69 ( V_6 ) ;
V_60:
F_60 ( V_6 ) ;
return V_26 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_52 )
{
struct V_8 * V_8 = F_22 ( V_2 ) ;
return F_62 ( V_8 , V_8 -> V_6 ) ;
}
void F_63 ( struct V_5 * V_6 )
{
V_6 -> V_68 = 0 ;
F_64 ( V_6 ) ;
F_65 ( V_6 ) ;
F_66 ( V_6 ) ;
V_6 -> V_69 ( V_6 ) ;
F_60 ( V_6 ) ;
F_67 ( V_6 ) ;
F_68 ( & V_6 -> V_8 ) ;
V_6 -> V_52 = NULL ;
V_6 -> V_70 = NULL ;
F_69 ( & V_6 -> V_8 ) ;
F_24 ( & V_6 -> V_17 . V_16 ) ;
F_70 ( V_6 , F_61 , NULL ) ;
F_35 ( V_6 ) ;
F_28 ( & V_6 -> V_17 . V_16 ) ;
F_71 ( V_6 ) ;
F_72 ( V_6 ) ;
F_59 ( & V_6 -> V_8 ) ;
}
static int F_73 ( struct V_1 * V_2 , const void * V_3 )
{
const struct V_5 * V_71 = V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 == NULL ) {
F_74 ( 1 ) ;
return 0 ;
}
if ( V_6 == V_71 ) {
if ( V_6 -> V_68 == 0 )
return 0 ;
else
return 1 ;
}
return 0 ;
}
struct V_5 * F_75 ( struct V_5 * V_71 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
V_2 = F_4 ( & V_7 , NULL , V_71 ,
F_73 ) ;
if ( V_2 ) {
V_6 = F_2 ( V_2 ) ;
F_76 ( V_6 ) ;
}
return V_6 ;
}
static inline struct V_5 * F_77 ( struct V_5 * V_6 )
{
if ( V_6 -> V_68 == 0 )
return NULL ;
F_78 ( & V_6 -> V_8 ) ;
return V_6 ;
}
static int F_79 ( struct V_1 * V_2 , const void * V_3 )
{
const struct V_1 * V_72 = V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_2 . V_73 -> V_73 == V_72 ) {
V_6 = F_77 ( V_6 ) ;
return 1 ;
}
return 0 ;
}
struct V_5 * F_80 ( const struct V_1 * V_72 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
V_2 = F_4 ( & V_7 , NULL , V_72 ,
F_79 ) ;
if ( V_2 )
V_6 = F_2 ( V_2 ) ;
return V_6 ;
}
static int F_81 ( struct V_1 * V_2 , const void * V_3 )
{
const struct V_74 * V_47 = V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 == NULL ) {
F_74 ( 1 ) ;
return 0 ;
}
if ( ! F_82 ( & V_6 -> V_8 . V_65 , V_47 ) ) {
V_6 = F_77 ( V_6 ) ;
return 1 ;
}
return 0 ;
}
struct V_5 * F_83 ( const struct V_74 * V_47 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
V_2 = F_4 ( & V_7 , NULL , V_47 , F_81 ) ;
if ( V_2 )
V_6 = F_2 ( V_2 ) ;
return V_6 ;
}
void F_84 ( struct V_5 * V_6 )
{
F_85 ( V_6 ) ;
}
