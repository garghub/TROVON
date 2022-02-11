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
(struct V_5 * ) F_5 ( V_4 ) ;
return (struct V_4 * ) F_2 ( V_6 , V_9 -> V_7 ) ;
}
static int F_6 ( struct V_4 * V_4 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
struct V_5 * V_6 =
(struct V_5 * ) F_5 ( V_4 ) ;
return F_1 ( V_6 -> V_7 , V_9 -> V_7 ) >= 0 ;
}
static int F_7 ( struct V_4 * V_1 , struct V_4 * V_2 )
{
struct V_8 * V_10 = (struct V_8 * ) V_1 ;
struct V_8 * V_11 = (struct V_8 * ) V_2 ;
return F_1 ( V_10 -> V_7 , V_11 -> V_7 ) ;
}
static int F_8 ( struct V_4 * V_4 ,
void * V_12 , int V_13 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
if ( V_13 < sizeof( V_9 -> V_7 ) )
return - V_14 ;
memcpy ( V_12 , & V_9 -> V_7 , sizeof( V_9 -> V_7 ) ) ;
return sizeof( V_9 -> V_7 ) ;
}
static void F_9 ( struct V_15 * V_15 ,
char * V_16 , int V_13 )
{
struct V_5 * V_17 =
(struct V_5 * ) V_15 ;
snprintf ( V_16 , V_13 , L_1 , V_17 -> V_7 ) ;
}
static void F_10 ( struct V_4 * V_4 ,
char * V_16 , int V_13 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 ;
snprintf ( V_16 , V_13 , L_1 , V_9 -> V_7 ) ;
}
struct V_5 * F_11 ( const char * V_18 )
{
struct V_5 * V_6 = (struct V_5 * )
F_12 ( & V_19 ,
sizeof( struct V_5 ) ,
V_18 ) ;
return V_6 ;
}
void F_13 ( struct V_5 * V_6 , T_1 V_20 )
{
V_6 -> V_7 += V_20 ;
F_14 ( & V_6 -> V_6 ) ;
}
static int F_15 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_5 * V_6 ;
char V_23 [ V_24 ] ;
F_16 ( V_23 , V_25 ) ;
V_6 = F_11 ( V_23 ) ;
if ( ! V_6 )
return - V_14 ;
V_22 -> V_26 = V_6 ;
return 0 ;
}
static int F_17 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
struct V_5 * V_6 = V_22 -> V_26 ;
F_18 ( & V_6 -> V_6 ) ;
return 0 ;
}
static long F_19 ( struct V_5 * V_6 ,
unsigned long V_27 )
{
int V_28 = F_20 ( V_29 ) ;
int V_30 ;
struct V_4 * V_9 ;
struct V_31 * V_32 ;
struct V_33 V_12 ;
if ( V_28 < 0 )
return V_28 ;
if ( F_21 ( & V_12 , ( void V_34 * ) V_27 , sizeof( V_12 ) ) ) {
V_30 = - V_35 ;
goto V_30;
}
V_9 = F_2 ( V_6 , V_12 . V_7 ) ;
if ( ! V_9 ) {
V_30 = - V_14 ;
goto V_30;
}
V_12 . V_18 [ sizeof( V_12 . V_18 ) - 1 ] = '\0' ;
V_32 = F_22 ( V_12 . V_18 , V_9 ) ;
if ( ! V_32 ) {
F_23 ( V_9 ) ;
V_30 = - V_14 ;
goto V_30;
}
V_12 . V_32 = V_28 ;
if ( F_24 ( ( void V_34 * ) V_27 , & V_12 , sizeof( V_12 ) ) ) {
F_25 ( V_32 ) ;
V_30 = - V_35 ;
goto V_30;
}
F_26 ( V_32 , V_28 ) ;
return 0 ;
V_30:
F_27 ( V_28 ) ;
return V_30 ;
}
static long F_28 ( struct V_5 * V_6 , unsigned long V_27 )
{
T_1 V_7 ;
if ( F_21 ( & V_7 , ( void V_34 * ) V_27 , sizeof( V_7 ) ) )
return - V_35 ;
F_13 ( V_6 , V_7 ) ;
return 0 ;
}
static long F_29 ( struct V_22 * V_22 , unsigned int V_36 ,
unsigned long V_27 )
{
struct V_5 * V_6 = V_22 -> V_26 ;
switch ( V_36 ) {
case V_37 :
return F_19 ( V_6 , V_27 ) ;
case V_38 :
return F_28 ( V_6 , V_27 ) ;
default:
return - V_39 ;
}
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_40 ) ;
}
