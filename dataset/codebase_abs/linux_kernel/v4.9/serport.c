static int F_1 ( struct V_1 * V_1 , unsigned char V_2 )
{
struct V_3 * V_3 = V_1 -> V_4 ;
return - ( V_3 -> V_5 -> V_6 -> V_7 ( V_3 -> V_5 , & V_2 , 1 ) != 1 ) ;
}
static int F_2 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_4 ;
unsigned long V_8 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
F_4 ( V_10 , & V_3 -> V_8 ) ;
F_5 ( & V_3 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_3 * V_3 = V_1 -> V_4 ;
unsigned long V_8 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
F_7 ( V_10 , & V_3 -> V_8 ) ;
F_5 ( & V_3 -> V_9 , V_8 ) ;
}
static int F_8 ( struct V_11 * V_5 )
{
struct V_3 * V_3 ;
if ( ! F_9 ( V_12 ) )
return - V_13 ;
V_3 = F_10 ( sizeof( struct V_3 ) , V_14 ) ;
if ( ! V_3 )
return - V_15 ;
V_3 -> V_5 = V_5 ;
F_11 ( & V_3 -> V_9 ) ;
F_12 ( & V_3 -> V_16 ) ;
V_5 -> V_17 = V_3 ;
V_5 -> V_18 = 256 ;
F_4 ( V_19 , & V_5 -> V_8 ) ;
return 0 ;
}
static void F_13 ( struct V_11 * V_5 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_17 ;
F_14 ( V_3 ) ;
}
static void F_15 ( struct V_11 * V_5 , const unsigned char * V_20 , char * V_21 , int V_22 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_17 ;
unsigned long V_8 ;
unsigned int V_23 = 0 ;
int V_24 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
if ( ! F_16 ( V_10 , & V_3 -> V_8 ) )
goto V_25;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
if ( V_21 ) {
switch ( V_21 [ V_24 ] ) {
case V_26 :
V_23 = V_27 ;
break;
case V_28 :
V_23 = V_29 ;
break;
default:
V_23 = 0 ;
break;
}
}
F_17 ( V_3 -> V_1 , V_20 [ V_24 ] , V_23 ) ;
}
V_25:
F_5 ( & V_3 -> V_9 , V_8 ) ;
}
static T_1 F_18 ( struct V_11 * V_5 , struct V_30 * V_30 , unsigned char T_2 * V_31 , T_3 V_32 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_17 ;
struct V_1 * V_1 ;
if ( F_19 ( V_33 , & V_3 -> V_8 ) )
return - V_34 ;
V_3 -> V_1 = V_1 = F_10 ( sizeof( struct V_1 ) , V_14 ) ;
if ( ! V_1 )
return - V_15 ;
F_20 ( V_1 -> V_35 , L_1 , sizeof( V_1 -> V_35 ) ) ;
snprintf ( V_1 -> V_36 , sizeof( V_1 -> V_36 ) , L_2 , F_21 ( V_5 ) ) ;
V_1 -> V_37 = V_3 -> V_37 ;
V_1 -> V_37 . type = V_38 ;
V_1 -> V_7 = F_1 ;
V_1 -> V_39 = F_2 ;
V_1 -> V_40 = F_6 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_41 . V_42 = V_5 -> V_41 ;
F_22 ( V_3 -> V_1 ) ;
F_23 ( V_43 L_3 , F_21 ( V_5 ) ) ;
F_24 ( V_3 -> V_16 , F_16 ( V_44 , & V_3 -> V_8 ) ) ;
F_25 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
F_7 ( V_44 , & V_3 -> V_8 ) ;
F_7 ( V_33 , & V_3 -> V_8 ) ;
return 0 ;
}
static void F_26 ( struct V_11 * V_5 , unsigned long type )
{
struct V_3 * V_3 = V_5 -> V_17 ;
V_3 -> V_37 . V_45 = type & 0x000000ff ;
V_3 -> V_37 . V_37 = ( type & 0x0000ff00 ) >> 8 ;
V_3 -> V_37 . V_46 = ( type & 0x00ff0000 ) >> 16 ;
}
static int F_27 ( struct V_11 * V_5 , struct V_30 * V_30 ,
unsigned int V_47 , unsigned long V_48 )
{
if ( V_47 == V_49 ) {
unsigned long type ;
if ( F_28 ( type , ( unsigned long T_2 * ) V_48 ) )
return - V_50 ;
F_26 ( V_5 , type ) ;
return 0 ;
}
return - V_51 ;
}
static long F_29 ( struct V_11 * V_5 ,
struct V_30 * V_30 ,
unsigned int V_47 , unsigned long V_48 )
{
if ( V_47 == V_52 ) {
void T_2 * V_53 = F_30 ( V_48 ) ;
T_4 V_54 ;
if ( F_28 ( V_54 , ( T_4 T_2 * ) V_53 ) )
return - V_50 ;
F_26 ( V_5 , V_54 ) ;
return 0 ;
}
return - V_51 ;
}
static int F_31 ( struct V_11 * V_5 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_17 ;
unsigned long V_8 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
F_4 ( V_44 , & V_3 -> V_8 ) ;
F_5 ( & V_3 -> V_9 , V_8 ) ;
F_32 ( & V_3 -> V_16 ) ;
return 0 ;
}
static void F_33 ( struct V_11 * V_5 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_17 ;
unsigned long V_8 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
if ( F_16 ( V_10 , & V_3 -> V_8 ) )
F_34 ( V_3 -> V_1 ) ;
F_5 ( & V_3 -> V_9 , V_8 ) ;
}
static int T_5 F_35 ( void )
{
int V_55 ;
V_55 = F_36 ( V_56 , & V_57 ) ;
if ( V_55 )
F_23 ( V_58 L_4 ) ;
return V_55 ;
}
static void T_6 F_37 ( void )
{
F_38 ( V_56 ) ;
}
