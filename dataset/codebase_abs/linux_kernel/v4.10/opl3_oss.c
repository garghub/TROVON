static inline T_1 F_1 ( void )
{
T_1 V_1 = F_2 () ;
F_3 ( F_4 () ) ;
return V_1 ;
}
static inline void F_5 ( T_1 V_1 )
{
F_3 ( V_1 ) ;
}
static int F_6 ( struct V_2 * V_3 , int V_4 ,
void * V_5 , int V_6 , int V_7 )
{
struct V_8 * V_9 = V_5 ;
if ( V_3 -> type != V_10 )
F_7 ( & V_11 , V_3 , V_9 -> V_12 ) ;
return 0 ;
}
static void F_8 ( void * V_5 )
{
struct V_8 * V_9 = V_5 ;
F_9 ( V_9 -> V_12 ) ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_13 V_14 ;
char V_15 [ 32 ] ;
int V_16 , V_17 ;
V_16 = ( V_9 -> V_18 < V_19 ) ?
V_20 : V_21 ;
V_9 -> V_12 = F_11 ( V_16 ) ;
if ( V_9 -> V_12 == NULL )
return - V_22 ;
V_9 -> V_12 -> V_5 = V_9 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_23 = V_24 ;
V_14 . V_25 = F_6 ;
V_14 . V_26 = F_8 ;
V_14 . V_5 = V_9 ;
V_17 = ( V_9 -> V_18 & V_27 ) >> 8 ;
sprintf ( V_15 , L_1 , V_17 ) ;
V_9 -> V_12 -> V_28 = V_9 -> V_29 ;
V_9 -> V_12 -> V_30 = F_12 ( V_9 -> V_29 , & V_14 ,
V_31 ,
V_32 |
V_33 |
V_34 |
V_35 ,
V_16 , V_16 ,
V_15 ) ;
if ( V_9 -> V_12 -> V_30 < 0 ) {
int V_30 ;
V_30 = V_9 -> V_12 -> V_30 ;
F_9 ( V_9 -> V_12 ) ;
return V_30 ;
}
return 0 ;
}
void F_13 ( struct V_8 * V_9 , char * V_15 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
if ( F_14 ( V_9 -> V_40 , 0 , V_41 ,
sizeof( struct V_36 ) , & V_39 ) < 0 )
return;
V_9 -> V_42 = V_39 ;
F_15 ( V_39 -> V_15 , V_15 , sizeof( V_39 -> V_15 ) ) ;
V_37 = F_16 ( V_39 ) ;
V_37 -> type = V_43 ;
if ( V_9 -> V_18 < V_19 ) {
V_37 -> V_44 = V_45 ;
V_37 -> V_46 = V_20 ;
} else {
V_37 -> V_44 = V_47 ;
V_37 -> V_46 = V_21 ;
}
V_37 -> V_48 = V_49 ;
V_37 -> V_5 = V_9 ;
if ( F_10 ( V_9 ) ) {
F_17 ( V_9 -> V_40 , V_39 ) ;
}
}
void F_18 ( struct V_8 * V_9 )
{
if ( V_9 -> V_42 ) {
V_9 -> V_42 = NULL ;
}
}
static int F_19 ( struct V_50 * V_37 , void * V_51 )
{
struct V_8 * V_9 = V_51 ;
int V_52 ;
if ( F_20 ( ! V_37 ) )
return - V_53 ;
if ( ( V_52 = F_21 ( V_9 ) ) < 0 )
return V_52 ;
V_37 -> V_5 = V_9 ;
V_37 -> V_54 . V_28 = V_9 -> V_12 -> V_28 ;
V_37 -> V_54 . V_30 = V_9 -> V_12 -> V_30 ;
if ( ( V_52 = F_22 ( V_9 ) ) < 0 )
return V_52 ;
V_9 -> V_55 = V_56 ;
return 0 ;
}
static int F_23 ( struct V_50 * V_37 )
{
struct V_8 * V_9 ;
if ( F_20 ( ! V_37 ) )
return - V_53 ;
V_9 = V_37 -> V_5 ;
F_24 ( V_9 ) ;
F_25 ( V_9 ) ;
return 0 ;
}
static int F_26 ( struct V_50 * V_37 , int V_57 ,
const char T_2 * V_58 , int V_59 , int V_60 )
{
struct V_8 * V_9 ;
struct V_61 V_62 ;
char V_15 [ 32 ] ;
int V_52 , type ;
if ( F_20 ( ! V_37 ) )
return - V_53 ;
V_9 = V_37 -> V_5 ;
if ( V_57 == V_63 )
type = V_64 ;
else if ( V_57 == V_65 )
type = V_66 ;
else
return - V_67 ;
if ( V_60 < ( int ) sizeof( V_62 ) ) {
F_27 ( V_68 L_2 ) ;
return - V_67 ;
}
if ( F_28 ( & V_62 , V_58 , sizeof( V_62 ) ) )
return - V_69 ;
if ( V_62 . V_70 < 0 || V_62 . V_70 >= V_71 ) {
F_27 ( V_68 L_3 ,
V_62 . V_70 ) ;
return - V_67 ;
}
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
sprintf ( V_15 , L_4 , V_62 . V_70 ) ;
V_52 = F_29 ( V_9 , V_62 . V_70 , 127 , type , V_15 , NULL ,
V_62 . V_72 ) ;
if ( V_52 < 0 )
return V_52 ;
return sizeof( V_62 ) ;
}
static int F_30 ( struct V_50 * V_37 , unsigned int V_73 ,
unsigned long V_74 )
{
struct V_8 * V_9 ;
if ( F_20 ( ! V_37 ) )
return - V_53 ;
V_9 = V_37 -> V_5 ;
switch ( V_73 ) {
case V_75 :
F_27 ( V_68 L_5
L_6
L_7 ) ;
return - V_67 ;
case V_76 :
return 0x7fffffff ;
case V_77 :
return 0 ;
default:
return - V_67 ;
}
return 0 ;
}
static int F_31 ( struct V_50 * V_37 )
{
struct V_8 * V_9 ;
if ( F_20 ( ! V_37 ) )
return - V_53 ;
V_9 = V_37 -> V_5 ;
return 0 ;
}
