static int F_1 ( T_1 V_1 , T_1 V_2 )
{
if ( V_1 == V_2 )
return 0 ;
return ( ( V_3 ) V_1 - ( V_3 ) V_2 ) < 0 ? - 1 : 1 ;
}
struct V_4 * F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * )
F_3 ( & V_6 -> V_6 , sizeof( struct V_8 ) ) ;
V_9 -> V_7 = V_7 ;
return (struct V_4 * ) V_9 ;
}
static struct V_4 * F_4 ( struct V_4 * V_4 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_10 ;
return (struct V_4 * ) F_2 ( V_6 , V_9 -> V_7 ) ;
}
static int F_5 ( struct V_4 * V_4 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_10 ;
return F_1 ( V_6 -> V_7 , V_9 -> V_7 ) >= 0 ;
}
static int F_6 ( struct V_4 * V_1 , struct V_4 * V_2 )
{
struct V_8 * V_11 = (struct V_8 * ) V_1 ;
struct V_8 * V_12 = (struct V_8 * ) V_2 ;
return F_1 ( V_11 -> V_7 , V_12 -> V_7 ) ;
}
static int F_7 ( struct V_4 * V_4 ,
void * V_13 , int V_14 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
if ( V_14 < sizeof( V_9 -> V_7 ) )
return - V_15 ;
memcpy ( V_13 , & V_9 -> V_7 , sizeof( V_9 -> V_7 ) ) ;
return sizeof( V_9 -> V_7 ) ;
}
static void F_8 ( struct V_16 * V_16 ,
char * V_17 , int V_14 )
{
struct V_5 * V_18 =
(struct V_5 * ) V_16 ;
snprintf ( V_17 , V_14 , L_1 , V_18 -> V_7 ) ;
}
static void F_9 ( struct V_4 * V_4 ,
char * V_17 , int V_14 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
snprintf ( V_17 , V_14 , L_1 , V_9 -> V_7 ) ;
}
struct V_5 * F_10 ( const char * V_19 )
{
struct V_5 * V_6 = (struct V_5 * )
F_11 ( & V_20 ,
sizeof( struct V_5 ) ,
V_19 ) ;
return V_6 ;
}
void F_12 ( struct V_5 * V_6 , T_1 V_21 )
{
V_6 -> V_7 += V_21 ;
F_13 ( & V_6 -> V_6 ) ;
}
static int F_14 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
struct V_5 * V_6 ;
char V_24 [ V_25 ] ;
F_15 ( V_24 , V_26 ) ;
V_6 = F_10 ( V_24 ) ;
if ( V_6 == NULL )
return - V_15 ;
V_23 -> V_27 = V_6 ;
return 0 ;
}
static int F_16 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
struct V_5 * V_6 = V_23 -> V_27 ;
F_17 ( & V_6 -> V_6 ) ;
return 0 ;
}
static long F_18 ( struct V_5 * V_6 , unsigned long V_28 )
{
int V_29 = F_19 () ;
int V_30 ;
struct V_4 * V_9 ;
struct V_31 * V_32 ;
struct V_33 V_13 ;
if ( V_29 < 0 )
return V_29 ;
if ( F_20 ( & V_13 , ( void V_34 * ) V_28 , sizeof( V_13 ) ) ) {
V_30 = - V_35 ;
goto V_30;
}
V_9 = F_2 ( V_6 , V_13 . V_7 ) ;
if ( V_9 == NULL ) {
V_30 = - V_15 ;
goto V_30;
}
V_13 . V_19 [ sizeof( V_13 . V_19 ) - 1 ] = '\0' ;
V_32 = F_21 ( V_13 . V_19 , V_9 ) ;
if ( V_32 == NULL ) {
F_22 ( V_9 ) ;
V_30 = - V_15 ;
goto V_30;
}
V_13 . V_32 = V_29 ;
if ( F_23 ( ( void V_34 * ) V_28 , & V_13 , sizeof( V_13 ) ) ) {
F_24 ( V_32 ) ;
V_30 = - V_35 ;
goto V_30;
}
F_25 ( V_32 , V_29 ) ;
return 0 ;
V_30:
F_26 ( V_29 ) ;
return V_30 ;
}
static long F_27 ( struct V_5 * V_6 , unsigned long V_28 )
{
T_1 V_7 ;
if ( F_20 ( & V_7 , ( void V_34 * ) V_28 , sizeof( V_7 ) ) )
return - V_35 ;
F_12 ( V_6 , V_7 ) ;
return 0 ;
}
static long F_28 ( struct V_23 * V_23 , unsigned int V_36 , unsigned long V_28 )
{
struct V_5 * V_6 = V_23 -> V_27 ;
switch ( V_36 ) {
case V_37 :
return F_18 ( V_6 , V_28 ) ;
case V_38 :
return F_27 ( V_6 , V_28 ) ;
default:
return - V_39 ;
}
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_40 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_40 ) ;
}
