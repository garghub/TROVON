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
unsigned int V_24 ;
int V_25 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
if ( ! F_17 ( V_10 , & V_3 -> V_8 ) )
goto V_26;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
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
F_18 ( V_3 -> V_1 , V_21 [ V_25 ] , V_24 ) ;
}
V_26:
F_5 ( & V_3 -> V_9 , V_8 ) ;
}
static T_1 F_19 ( struct V_13 * V_5 , struct V_31 * V_31 , unsigned char T_2 * V_32 , T_3 V_33 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_18 ;
struct V_1 * V_1 ;
char V_34 [ 64 ] ;
if ( F_20 ( V_35 , & V_3 -> V_8 ) )
return - V_36 ;
V_3 -> V_1 = V_1 = F_11 ( sizeof( struct V_1 ) , V_16 ) ;
if ( ! V_1 )
return - V_17 ;
F_21 ( V_1 -> V_34 , L_1 , sizeof( V_1 -> V_34 ) ) ;
snprintf ( V_1 -> V_37 , sizeof( V_1 -> V_37 ) , L_2 , F_22 ( V_5 , V_34 ) ) ;
V_1 -> V_38 = V_3 -> V_38 ;
V_1 -> V_38 . type = V_39 ;
V_1 -> V_7 = F_1 ;
V_1 -> V_40 = F_2 ;
V_1 -> V_41 = F_6 ;
V_1 -> V_4 = V_3 ;
V_1 -> V_42 . V_43 = V_5 -> V_42 ;
F_23 ( V_3 -> V_1 ) ;
F_24 ( V_44 L_3 , F_22 ( V_5 , V_34 ) ) ;
F_25 ( V_3 -> V_12 , F_17 ( V_11 , & V_3 -> V_8 ) ) ;
F_26 ( V_3 -> V_1 ) ;
V_3 -> V_1 = NULL ;
F_7 ( V_11 , & V_3 -> V_8 ) ;
F_7 ( V_35 , & V_3 -> V_8 ) ;
return 0 ;
}
static int F_27 ( struct V_13 * V_5 , struct V_31 * V_31 , unsigned int V_45 , unsigned long V_46 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_18 ;
unsigned long type ;
if ( V_45 == V_47 ) {
if ( F_28 ( type , ( unsigned long T_2 * ) V_46 ) )
return - V_48 ;
V_3 -> V_38 . V_49 = type & 0x000000ff ;
V_3 -> V_38 . V_38 = ( type & 0x0000ff00 ) >> 8 ;
V_3 -> V_38 . V_50 = ( type & 0x00ff0000 ) >> 16 ;
return 0 ;
}
return - V_51 ;
}
static void F_29 ( struct V_13 * V_5 )
{
struct V_3 * V_3 = (struct V_3 * ) V_5 -> V_18 ;
unsigned long V_8 ;
F_3 ( & V_3 -> V_9 , V_8 ) ;
if ( F_17 ( V_10 , & V_3 -> V_8 ) )
F_30 ( V_3 -> V_1 ) ;
F_5 ( & V_3 -> V_9 , V_8 ) ;
}
static int T_4 F_31 ( void )
{
int V_52 ;
V_52 = F_32 ( V_53 , & V_54 ) ;
if ( V_52 )
F_24 ( V_55 L_4 ) ;
return V_52 ;
}
static void T_5 F_33 ( void )
{
F_34 ( V_53 ) ;
}
