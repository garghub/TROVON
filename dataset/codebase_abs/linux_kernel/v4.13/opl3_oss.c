static int F_1 ( struct V_1 * V_2 , int V_3 ,
void * V_4 , int V_5 , int V_6 )
{
struct V_7 * V_8 = V_4 ;
if ( V_2 -> type != V_9 )
F_2 ( & V_10 , V_2 , V_8 -> V_11 ) ;
return 0 ;
}
static void F_3 ( void * V_4 )
{
struct V_7 * V_8 = V_4 ;
F_4 ( V_8 -> V_11 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_12 V_13 ;
char V_14 [ 32 ] ;
int V_15 , V_16 ;
V_15 = ( V_8 -> V_17 < V_18 ) ?
V_19 : V_20 ;
V_8 -> V_11 = F_6 ( V_15 ) ;
if ( V_8 -> V_11 == NULL )
return - V_21 ;
V_8 -> V_11 -> V_4 = V_8 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_22 = V_23 ;
V_13 . V_24 = F_1 ;
V_13 . V_25 = F_3 ;
V_13 . V_4 = V_8 ;
V_16 = ( V_8 -> V_17 & V_26 ) >> 8 ;
sprintf ( V_14 , L_1 , V_16 ) ;
V_8 -> V_11 -> V_27 = V_8 -> V_28 ;
V_8 -> V_11 -> V_29 = F_7 ( V_8 -> V_28 , & V_13 ,
V_30 ,
V_31 |
V_32 |
V_33 |
V_34 ,
V_15 , V_15 ,
V_14 ) ;
if ( V_8 -> V_11 -> V_29 < 0 ) {
int V_29 ;
V_29 = V_8 -> V_11 -> V_29 ;
F_4 ( V_8 -> V_11 ) ;
return V_29 ;
}
return 0 ;
}
void F_8 ( struct V_7 * V_8 , char * V_14 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
if ( F_9 ( V_8 -> V_39 , 0 , V_40 ,
sizeof( struct V_35 ) , & V_38 ) < 0 )
return;
V_8 -> V_41 = V_38 ;
F_10 ( V_38 -> V_14 , V_14 , sizeof( V_38 -> V_14 ) ) ;
V_36 = F_11 ( V_38 ) ;
V_36 -> type = V_42 ;
if ( V_8 -> V_17 < V_18 ) {
V_36 -> V_43 = V_44 ;
V_36 -> V_45 = V_19 ;
} else {
V_36 -> V_43 = V_46 ;
V_36 -> V_45 = V_20 ;
}
V_36 -> V_47 = V_48 ;
V_36 -> V_4 = V_8 ;
if ( F_5 ( V_8 ) ) {
F_12 ( V_8 -> V_39 , V_38 ) ;
}
}
void F_13 ( struct V_7 * V_8 )
{
if ( V_8 -> V_41 ) {
V_8 -> V_41 = NULL ;
}
}
static int F_14 ( struct V_49 * V_36 , void * V_50 )
{
struct V_7 * V_8 = V_50 ;
int V_51 ;
if ( F_15 ( ! V_36 ) )
return - V_52 ;
if ( ( V_51 = F_16 ( V_8 ) ) < 0 )
return V_51 ;
V_36 -> V_4 = V_8 ;
V_36 -> V_53 . V_27 = V_8 -> V_11 -> V_27 ;
V_36 -> V_53 . V_29 = V_8 -> V_11 -> V_29 ;
if ( ( V_51 = F_17 ( V_8 ) ) < 0 )
return V_51 ;
V_8 -> V_54 = V_55 ;
return 0 ;
}
static int F_18 ( struct V_49 * V_36 )
{
struct V_7 * V_8 ;
if ( F_15 ( ! V_36 ) )
return - V_52 ;
V_8 = V_36 -> V_4 ;
F_19 ( V_8 ) ;
F_20 ( V_8 ) ;
return 0 ;
}
static int F_21 ( struct V_49 * V_36 , int V_56 ,
const char T_1 * V_57 , int V_58 , int V_59 )
{
struct V_7 * V_8 ;
struct V_60 V_61 ;
char V_14 [ 32 ] ;
int V_51 , type ;
if ( F_15 ( ! V_36 ) )
return - V_52 ;
V_8 = V_36 -> V_4 ;
if ( V_56 == V_62 )
type = V_63 ;
else if ( V_56 == V_64 )
type = V_65 ;
else
return - V_66 ;
if ( V_59 < ( int ) sizeof( V_61 ) ) {
F_22 ( V_67 L_2 ) ;
return - V_66 ;
}
if ( F_23 ( & V_61 , V_57 , sizeof( V_61 ) ) )
return - V_68 ;
if ( V_61 . V_69 < 0 || V_61 . V_69 >= V_70 ) {
F_22 ( V_67 L_3 ,
V_61 . V_69 ) ;
return - V_66 ;
}
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
sprintf ( V_14 , L_4 , V_61 . V_69 ) ;
V_51 = F_24 ( V_8 , V_61 . V_69 , 127 , type , V_14 , NULL ,
V_61 . V_71 ) ;
if ( V_51 < 0 )
return V_51 ;
return sizeof( V_61 ) ;
}
static int F_25 ( struct V_49 * V_36 , unsigned int V_72 ,
unsigned long V_73 )
{
struct V_7 * V_8 ;
if ( F_15 ( ! V_36 ) )
return - V_52 ;
V_8 = V_36 -> V_4 ;
switch ( V_72 ) {
case V_74 :
F_22 ( V_67 L_5
L_6
L_7 ) ;
return - V_66 ;
case V_75 :
return 0x7fffffff ;
case V_76 :
return 0 ;
default:
return - V_66 ;
}
return 0 ;
}
static int F_26 ( struct V_49 * V_36 )
{
struct V_7 * V_8 ;
if ( F_15 ( ! V_36 ) )
return - V_52 ;
V_8 = V_36 -> V_4 ;
return 0 ;
}
