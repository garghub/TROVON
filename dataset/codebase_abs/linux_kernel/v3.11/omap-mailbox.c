static inline T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 ( V_2 ) ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 V_5 )
{
V_2 -> V_3 -> V_6 ( V_2 , V_5 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_7 ( V_2 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_8 ( V_2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_9 )
{
if ( V_2 -> V_3 -> V_10 )
V_2 -> V_3 -> V_10 ( V_2 , V_9 ) ;
}
static inline int F_6 ( struct V_1 * V_2 , T_2 V_9 )
{
return V_2 -> V_3 -> V_11 ( V_2 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_12 = 0 , V_13 = 1000 ;
while ( F_4 ( V_2 ) ) {
if ( V_2 -> V_3 -> type == V_14 )
return - 1 ;
if ( -- V_13 == 0 )
return - 1 ;
F_8 ( 1 ) ;
}
return V_12 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_12 = 0 , V_18 ;
F_10 ( & V_16 -> V_19 ) ;
if ( F_11 ( & V_16 -> V_20 ) < sizeof( V_5 ) ) {
V_12 = - V_21 ;
goto V_22;
}
if ( F_12 ( & V_16 -> V_20 ) && ! F_7 ( V_2 ) ) {
F_2 ( V_2 , V_5 ) ;
goto V_22;
}
V_18 = F_13 ( & V_16 -> V_20 , ( unsigned char * ) & V_5 , sizeof( V_5 ) ) ;
F_14 ( V_18 != sizeof( V_5 ) ) ;
F_15 ( & V_2 -> V_17 -> V_23 ) ;
V_22:
F_16 ( & V_16 -> V_19 ) ;
return V_12 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_24 ) {
F_18 ( V_2 -> V_25 , L_1 , V_26 ) ;
return;
}
V_2 -> V_3 -> V_24 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_27 ) {
F_18 ( V_2 -> V_25 , L_2 , V_26 ) ;
return;
}
V_2 -> V_3 -> V_27 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 , T_2 V_9 )
{
V_2 -> V_3 -> V_28 ( V_2 , V_9 ) ;
}
void F_21 ( struct V_1 * V_2 , T_2 V_9 )
{
V_2 -> V_3 -> V_29 ( V_2 , V_9 ) ;
}
static void F_22 ( unsigned long V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_30 ;
struct V_15 * V_16 = V_2 -> V_17 ;
T_1 V_5 ;
int V_12 ;
while ( F_23 ( & V_16 -> V_20 ) ) {
if ( F_7 ( V_2 ) ) {
F_20 ( V_2 , V_31 ) ;
break;
}
V_12 = F_24 ( & V_16 -> V_20 , ( unsigned char * ) & V_5 ,
sizeof( V_5 ) ) ;
F_14 ( V_12 != sizeof( V_5 ) ) ;
F_2 ( V_2 , V_5 ) ;
}
}
static void F_25 ( struct V_32 * V_33 )
{
struct V_15 * V_16 =
F_26 ( V_33 , struct V_15 , V_33 ) ;
T_1 V_5 ;
int V_18 ;
while ( F_23 ( & V_16 -> V_20 ) >= sizeof( V_5 ) ) {
V_18 = F_24 ( & V_16 -> V_20 , ( unsigned char * ) & V_5 , sizeof( V_5 ) ) ;
F_14 ( V_18 != sizeof( V_5 ) ) ;
F_27 ( & V_16 -> V_2 -> V_34 , V_18 ,
( void * ) V_5 ) ;
F_28 ( & V_16 -> V_19 ) ;
if ( V_16 -> V_35 ) {
V_16 -> V_35 = false ;
F_20 ( V_16 -> V_2 , V_36 ) ;
}
F_29 ( & V_16 -> V_19 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_31 ) ;
F_5 ( V_2 , V_31 ) ;
F_15 ( & V_2 -> V_17 -> V_23 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_37 ;
T_1 V_5 ;
int V_18 ;
while ( ! F_3 ( V_2 ) ) {
if ( F_32 ( F_11 ( & V_16 -> V_20 ) < sizeof( V_5 ) ) ) {
F_21 ( V_2 , V_36 ) ;
V_16 -> V_35 = true ;
goto V_38;
}
V_5 = F_1 ( V_2 ) ;
V_18 = F_13 ( & V_16 -> V_20 , ( unsigned char * ) & V_5 , sizeof( V_5 ) ) ;
F_14 ( V_18 != sizeof( V_5 ) ) ;
if ( V_2 -> V_3 -> type == V_39 )
break;
}
F_5 ( V_2 , V_36 ) ;
V_38:
F_33 ( & V_2 -> V_37 -> V_33 ) ;
}
static T_3 F_34 ( int V_9 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
if ( F_6 ( V_2 , V_31 ) )
F_30 ( V_2 ) ;
if ( F_6 ( V_2 , V_36 ) )
F_31 ( V_2 ) ;
return V_41 ;
}
static struct V_15 * F_35 ( struct V_1 * V_2 ,
void (* V_33) ( struct V_32 * ) ,
void (* V_23)( unsigned long ) )
{
struct V_15 * V_16 ;
V_16 = F_36 ( sizeof( struct V_15 ) , V_42 ) ;
if ( ! V_16 )
return NULL ;
F_37 ( & V_16 -> V_19 ) ;
if ( F_38 ( & V_16 -> V_20 , V_43 , V_42 ) )
goto error;
if ( V_33 )
F_39 ( & V_16 -> V_33 , V_33 ) ;
if ( V_23 )
F_40 ( & V_16 -> V_23 , V_23 , ( unsigned long ) V_2 ) ;
return V_16 ;
error:
F_41 ( V_16 ) ;
return NULL ;
}
static void F_42 ( struct V_15 * V_44 )
{
F_43 ( & V_44 -> V_20 ) ;
F_41 ( V_44 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
struct V_15 * V_16 ;
F_45 ( & V_45 ) ;
if ( ! V_46 ++ ) {
if ( F_46 ( V_2 -> V_3 -> V_47 ) ) {
V_12 = V_2 -> V_3 -> V_47 ( V_2 ) ;
if ( F_32 ( V_12 ) )
goto V_48;
} else
goto V_48;
}
if ( ! V_2 -> V_49 ++ ) {
V_16 = F_35 ( V_2 , NULL , F_22 ) ;
if ( ! V_16 ) {
V_12 = - V_21 ;
goto V_50;
}
V_2 -> V_17 = V_16 ;
V_16 = F_35 ( V_2 , F_25 , NULL ) ;
if ( ! V_16 ) {
V_12 = - V_21 ;
goto V_51;
}
V_2 -> V_37 = V_16 ;
V_16 -> V_2 = V_2 ;
V_12 = F_47 ( V_2 -> V_9 , F_34 , V_52 ,
V_2 -> V_53 , V_2 ) ;
if ( F_32 ( V_12 ) ) {
F_48 ( L_3 ,
V_12 ) ;
goto V_54;
}
F_20 ( V_2 , V_36 ) ;
}
F_49 ( & V_45 ) ;
return 0 ;
V_54:
F_42 ( V_2 -> V_37 ) ;
V_51:
F_42 ( V_2 -> V_17 ) ;
V_50:
if ( V_2 -> V_3 -> V_55 )
V_2 -> V_3 -> V_55 ( V_2 ) ;
V_2 -> V_49 -- ;
V_48:
V_46 -- ;
F_49 ( & V_45 ) ;
return V_12 ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_45 ( & V_45 ) ;
if ( ! -- V_2 -> V_49 ) {
F_21 ( V_2 , V_36 ) ;
F_51 ( V_2 -> V_9 , V_2 ) ;
F_52 ( & V_2 -> V_17 -> V_23 ) ;
F_53 ( & V_2 -> V_37 -> V_33 ) ;
F_42 ( V_2 -> V_17 ) ;
F_42 ( V_2 -> V_37 ) ;
}
if ( F_46 ( V_2 -> V_3 -> V_55 ) ) {
if ( ! -- V_46 )
V_2 -> V_3 -> V_55 ( V_2 ) ;
}
F_49 ( & V_45 ) ;
}
struct V_1 * F_54 ( const char * V_53 , struct V_56 * V_57 )
{
struct V_1 * V_58 , * V_2 = NULL ;
int V_13 , V_12 ;
if ( ! V_59 )
return F_55 ( - V_60 ) ;
for ( V_13 = 0 ; ( V_58 = V_59 [ V_13 ] ) ; V_13 ++ ) {
if ( ! strcmp ( V_58 -> V_53 , V_53 ) ) {
V_2 = V_58 ;
break;
}
}
if ( ! V_2 )
return F_55 ( - V_61 ) ;
if ( V_57 )
F_56 ( & V_2 -> V_34 , V_57 ) ;
V_12 = F_44 ( V_2 ) ;
if ( V_12 ) {
F_57 ( & V_2 -> V_34 , V_57 ) ;
return F_55 ( - V_62 ) ;
}
return V_2 ;
}
void F_58 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
F_57 ( & V_2 -> V_34 , V_57 ) ;
F_50 ( V_2 ) ;
}
int F_59 ( struct V_63 * V_64 , struct V_1 * * V_65 )
{
int V_12 ;
int V_13 ;
V_59 = V_65 ;
if ( ! V_59 )
return - V_60 ;
for ( V_13 = 0 ; V_59 [ V_13 ] ; V_13 ++ ) {
struct V_1 * V_2 = V_59 [ V_13 ] ;
V_2 -> V_25 = F_60 ( & V_66 ,
V_64 , 0 , V_2 , L_4 , V_2 -> V_53 ) ;
if ( F_61 ( V_2 -> V_25 ) ) {
V_12 = F_62 ( V_2 -> V_25 ) ;
goto V_67;
}
F_63 ( & V_2 -> V_34 ) ;
}
return 0 ;
V_67:
while ( V_13 -- )
F_64 ( V_59 [ V_13 ] -> V_25 ) ;
return V_12 ;
}
int F_65 ( void )
{
int V_13 ;
if ( ! V_59 )
return - V_60 ;
for ( V_13 = 0 ; V_59 [ V_13 ] ; V_13 ++ )
F_64 ( V_59 [ V_13 ] -> V_25 ) ;
V_59 = NULL ;
return 0 ;
}
static int T_4 F_66 ( void )
{
int V_68 ;
V_68 = F_67 ( & V_66 ) ;
if ( V_68 )
return V_68 ;
V_43 = F_68 ( V_43 , sizeof( T_1 ) ) ;
V_43 = F_69 (unsigned int, mbox_kfifo_size,
sizeof(mbox_msg_t)) ;
return 0 ;
}
static void T_5 F_70 ( void )
{
F_71 ( & V_66 ) ;
}
