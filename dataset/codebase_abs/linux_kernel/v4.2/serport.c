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
F_4 ( V_11 , & V_3 -> V_8 ) ;
F_5 ( & V_3 -> V_9 , V_8 ) ;
F_8 ( & V_3 -> V_12 ) ;
}
static int F_9 ( struct V_13 * V_5 )
{
struct V_3 * V_3 ;
if ( ! F_10 ( V_14 ) )
return - V_15 ;
V_3 = F_11 ( sizeof( struct V_3 ) , V_16 ) ;
if ( ! V_3 )
return - V_17 ;
V_3 -> V_5 = V_5 ;
F_12 ( & V_3 -> V_9 ) ;
F_13 ( & V_3 -> V_12 ) ;
V_5 -> V_18 = V_3 ;
V_5 -> V_19 = 256 ;
F_4 ( V_20 , & V_5 -> V_8 ) ;
return 0 ;
}
static void F_14 ( struct V_13 * V_5 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_18 ;
F_15 ( V_3 ) ;
}
static void F_16 ( struct V_13 * V_5 , const unsigned char * V_21 , char * V_22 , int V_23 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_18 ;
unsigned long V_8 ;
unsigned int V_24 = 0 ;
int V_25 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
if ( ! F_17 ( V_10 , & V_3 -> V_8 ) )
goto V_26;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
if ( V_22 ) {
switch ( V_22 [ V_25 ] ) {
case V_27 :
V_24 = V_28 ;
break;
case V_29 :
V_24 = V_30 ;
break;
default:
V_24 = 0 ;
break;
}
}
F_18 ( V_3 -> V_1 , V_21 [ V_25 ] , V_24 ) ;
}
V_26:
F_5 ( & V_3 -> V_9 , V_8 ) ;
}
static T_1 F_19 ( struct V_13 * V_5 , struct V_31 * V_31 , unsigned char T_2 * V_32 , T_3 V_33 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_18 ;
struct V_1 * V_1 ;
if ( F_20 ( V_34 , & V_3 -> V_8 ) )
return - V_35 ;
V_3 -> V_1 = V_1 = F_11 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_1 )
return - V_17 ;
F_21 ( V_1 -> V_36 , L_1 , sizeof( V_1 -> V_36 ) ) ;
snprintf ( V_1 -> V_37 , sizeof( V_1 -> V_37 ) , L_2 , F_22 ( V_5 ) ) ;
V_1 -> V_38 = V_3 -> V_38 ;
V_1 -> V_38 . type = V_39 ;
V_1 -> V_7 = F_1 ;
V_1 -> V_40 = F_2 ;
V_1 -> V_41 = F_6 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_42 . V_43 = V_5 -> V_42 ;
F_23 ( V_3 -> V_1 ) ;
F_24 ( V_44 L_3 , F_22 ( V_5 ) ) ;
F_25 ( V_3 -> V_12 , F_17 ( V_11 , & V_3 -> V_8 ) ) ;
F_26 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
F_7 ( V_11 , & V_3 -> V_8 ) ;
F_7 ( V_34 , & V_3 -> V_8 ) ;
return 0 ;
}
static void F_27 ( struct V_13 * V_5 , unsigned long type )
{
struct V_3 * V_3 = V_5 -> V_18 ;
V_3 -> V_38 . V_45 = type & 0x000000ff ;
V_3 -> V_38 . V_38 = ( type & 0x0000ff00 ) >> 8 ;
V_3 -> V_38 . V_46 = ( type & 0x00ff0000 ) >> 16 ;
}
static int F_28 ( struct V_13 * V_5 , struct V_31 * V_31 ,
unsigned int V_47 , unsigned long V_48 )
{
if ( V_47 == V_49 ) {
unsigned long type ;
if ( F_29 ( type , ( unsigned long T_2 * ) V_48 ) )
return - V_50 ;
F_27 ( V_5 , type ) ;
return 0 ;
}
return - V_51 ;
}
static long F_30 ( struct V_13 * V_5 ,
struct V_31 * V_31 ,
unsigned int V_47 , unsigned long V_48 )
{
if ( V_47 == V_52 ) {
void T_2 * V_53 = F_31 ( V_48 ) ;
T_4 V_54 ;
if ( F_29 ( V_54 , ( T_4 T_2 * ) V_53 ) )
return - V_50 ;
F_27 ( V_5 , V_54 ) ;
return 0 ;
}
return - V_51 ;
}
static void F_32 ( struct V_13 * V_5 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_18 ;
unsigned long V_8 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
if ( F_17 ( V_10 , & V_3 -> V_8 ) )
F_33 ( V_3 -> V_1 ) ;
F_5 ( & V_3 -> V_9 , V_8 ) ;
}
static int T_5 F_34 ( void )
{
int V_55 ;
V_55 = F_35 ( V_56 , & V_57 ) ;
if ( V_55 )
F_24 ( V_58 L_4 ) ;
return V_55 ;
}
static void T_6 F_36 ( void )
{
F_37 ( V_56 ) ;
}
