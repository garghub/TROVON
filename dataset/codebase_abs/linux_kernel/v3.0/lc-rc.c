static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int * V_4 = V_3 ;
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
static int F_21 ( struct V_5 * V_6 )
{
return F_22 ( & V_6 -> V_8 . V_2 . V_19 , & V_20 ) ;
}
static void F_23 ( struct V_5 * V_6 )
{
F_24 ( & V_6 -> V_8 . V_2 . V_19 , & V_20 ) ;
}
static
int F_25 ( struct V_5 * V_6 )
{
int V_21 ;
struct V_1 * V_2 = & V_6 -> V_8 . V_2 ;
struct V_8 * V_8 = & V_6 -> V_8 ;
char V_22 [ V_23 ] ;
struct V_24 V_25 ;
V_21 = F_26 ( V_6 , & V_25 ) ;
if ( V_21 < 0 ) {
F_27 ( V_2 , L_1 , V_21 ) ;
return V_21 ;
}
if ( F_28 ( & V_25 ) || F_29 ( & V_25 ) ) {
V_25 . V_3 [ 0 ] = 0x02 ;
F_30 ( & V_25 . V_3 [ 1 ] , sizeof( V_25 . V_3 ) - 1 ) ;
V_21 = F_31 ( V_6 , & V_25 ) ;
if ( V_21 < 0 ) {
F_32 ( V_22 , sizeof( V_22 ) , & V_25 ) ;
F_27 ( V_2 , L_2 ,
V_22 , V_21 ) ;
return V_21 ;
}
}
V_8 -> V_26 = V_25 ;
return 0 ;
}
static int F_33 ( struct V_5 * V_6 )
{
int V_21 ;
struct V_1 * V_2 = & V_6 -> V_8 . V_2 ;
V_21 = F_34 ( V_6 ) ;
if ( V_21 < 0 ) {
F_27 ( V_2 , L_3 , V_21 ) ;
goto error;
}
V_21 = F_25 ( V_6 ) ;
if ( V_21 < 0 ) {
F_27 ( V_2 , L_4 , V_21 ) ;
goto error;
}
V_21 = F_35 ( V_6 ) ;
if ( V_21 < 0 ) {
F_27 ( V_2 , L_5 , V_21 ) ;
goto error;
}
V_21 = F_36 ( V_6 ) ;
if ( V_21 < 0 ) {
F_27 ( V_2 , L_6 , V_21 ) ;
goto V_27;
}
V_21 = F_37 ( V_6 ) ;
if ( V_21 < 0 ) {
F_27 ( V_2 , L_7 , V_21 ) ;
goto V_28;
}
F_38 ( V_6 ) ;
return 0 ;
V_28:
F_8 ( V_6 ) ;
V_27:
error:
return V_21 ;
}
int F_39 ( struct V_5 * V_6 , struct V_1 * V_29 , void * V_30 )
{
int V_21 ;
struct V_1 * V_2 ;
char V_31 [ V_23 ] , V_32 [ V_23 ] ;
V_6 -> V_4 = F_5 () ;
V_2 = & V_6 -> V_8 . V_2 ;
F_40 ( V_2 , L_8 , V_6 -> V_4 ) ;
V_6 -> V_30 = V_30 ;
F_41 ( & V_6 -> V_33 . V_34 ) ;
F_13 ( & V_6 -> V_33 . V_35 ) ;
F_42 ( & V_6 -> V_33 . V_36 ) ;
F_43 ( V_6 ) ;
V_21 = V_6 -> V_37 ( V_6 ) ;
if ( V_21 < 0 )
goto V_38;
V_21 = F_33 ( V_6 ) ;
if ( V_21 < 0 ) {
F_27 ( V_2 , L_9 , V_21 ) ;
goto V_39;
}
V_21 = F_44 ( & V_6 -> V_8 , V_29 , V_6 ) ;
if ( V_21 < 0 && V_21 != - V_40 )
goto V_41;
V_21 = F_21 ( V_6 ) ;
if ( V_21 < 0 ) {
F_27 ( V_29 , L_10
L_11 , V_21 ) ;
goto V_42;
}
F_32 ( V_31 , sizeof( V_31 ) , & V_6 -> V_8 . V_26 ) ;
F_45 ( V_32 , sizeof( V_32 ) , & V_6 -> V_8 . V_43 ) ;
F_46 ( V_2 ,
L_12 ,
V_31 , V_32 , V_29 -> V_44 -> V_45 , F_47 ( V_29 ) ) ;
V_6 -> V_46 = 1 ;
return 0 ;
V_42:
F_48 ( & V_6 -> V_8 ) ;
V_41:
V_39:
V_6 -> V_47 ( V_6 ) ;
V_38:
F_49 ( V_6 ) ;
return V_21 ;
}
static int F_50 ( struct V_1 * V_2 , void * V_30 )
{
struct V_8 * V_8 = F_51 ( V_2 ) ;
return F_52 ( V_8 , V_8 -> V_6 ) ;
}
void F_53 ( struct V_5 * V_6 )
{
V_6 -> V_46 = 0 ;
F_54 ( V_6 ) ;
F_55 ( V_6 ) ;
F_56 ( V_6 ) ;
V_6 -> V_47 ( V_6 ) ;
F_49 ( V_6 ) ;
F_57 ( V_6 ) ;
F_58 ( & V_6 -> V_8 ) ;
V_6 -> V_30 = NULL ;
V_6 -> V_48 = NULL ;
F_59 ( & V_6 -> V_8 ) ;
F_60 ( & V_6 -> V_17 . V_16 ) ;
F_61 ( V_6 , F_50 , NULL ) ;
F_23 ( V_6 ) ;
F_62 ( & V_6 -> V_17 . V_16 ) ;
F_63 ( V_6 ) ;
F_64 ( V_6 ) ;
F_48 ( & V_6 -> V_8 ) ;
}
static int F_65 ( struct V_1 * V_2 , void * V_3 )
{
struct V_5 * V_49 = V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 == NULL ) {
F_66 ( 1 ) ;
return 0 ;
}
if ( V_6 == V_49 ) {
if ( V_6 -> V_46 == 0 )
return 0 ;
else
return 1 ;
}
return 0 ;
}
struct V_5 * F_67 ( struct V_5 * V_49 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
V_2 = F_4 ( & V_7 , NULL , V_49 ,
F_65 ) ;
if ( V_2 ) {
V_6 = F_2 ( V_2 ) ;
F_68 ( V_6 ) ;
}
return V_6 ;
}
static inline struct V_5 * F_69 ( struct V_5 * V_6 )
{
if ( V_6 -> V_46 == 0 )
return NULL ;
F_70 ( & V_6 -> V_8 ) ;
return V_6 ;
}
static int F_71 ( struct V_1 * V_2 , void * V_3 )
{
struct V_1 * V_50 = V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_2 . V_51 -> V_51 == V_50 ) {
V_6 = F_69 ( V_6 ) ;
return 1 ;
}
return 0 ;
}
struct V_5 * F_72 ( const struct V_1 * V_50 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
V_2 = F_4 ( & V_7 , NULL , ( void * ) V_50 ,
F_71 ) ;
if ( V_2 )
V_6 = F_2 ( V_2 ) ;
return V_6 ;
}
static int F_73 ( struct V_1 * V_2 , void * V_3 )
{
struct V_52 * V_25 = V_3 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 == NULL ) {
F_66 ( 1 ) ;
return 0 ;
}
if ( ! F_74 ( & V_6 -> V_8 . V_43 , V_25 ) ) {
V_6 = F_69 ( V_6 ) ;
return 1 ;
}
return 0 ;
}
struct V_5 * F_75 ( const struct V_52 * V_25 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
V_2 = F_4 ( & V_7 , NULL , ( void * ) V_25 ,
F_73 ) ;
if ( V_2 )
V_6 = F_2 ( V_2 ) ;
return V_6 ;
}
void F_76 ( struct V_5 * V_6 )
{
F_77 ( V_6 ) ;
}
