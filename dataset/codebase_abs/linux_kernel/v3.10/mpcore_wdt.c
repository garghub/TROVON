static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( F_2 ( V_4 -> V_5 + V_6 ) ) {
F_3 ( V_4 -> V_7 , L_1 ) ;
F_4 ( 1 , V_4 -> V_5 + V_6 ) ;
return V_8 ;
}
return V_9 ;
}
static void F_5 ( struct V_3 * V_4 )
{
unsigned long V_10 ;
F_6 ( & V_11 ) ;
V_10 = F_7 ( V_4 -> V_5 + V_12 ) ;
V_10 = ( 0xFFFFFFFFU - V_10 ) * ( V_13 / 5 ) ;
V_10 = ( V_10 / 256 ) * V_14 ;
F_4 ( V_10 + V_4 -> V_15 , V_4 -> V_5 + V_16 ) ;
V_4 -> V_15 = V_4 -> V_15 ? 0 : 1 ;
F_8 ( & V_11 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_6 ( & V_11 ) ;
F_4 ( 0x12345678 , V_4 -> V_5 + V_17 ) ;
F_4 ( 0x87654321 , V_4 -> V_5 + V_17 ) ;
F_4 ( 0x0 , V_4 -> V_5 + V_18 ) ;
F_8 ( & V_11 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_11 ( V_4 -> V_7 , L_2 ) ;
F_5 ( V_4 ) ;
if ( V_19 ) {
F_4 ( 0x0000FF01 , V_4 -> V_5 + V_18 ) ;
} else {
F_4 ( 0x0000FF09 , V_4 -> V_5 + V_18 ) ;
}
}
static int F_12 ( int V_20 )
{
if ( V_20 < 0x0001 || V_20 > 0xFFFF )
return - V_21 ;
V_14 = V_20 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
struct V_3 * V_4 = F_14 ( V_24 ) ;
if ( F_15 ( 0 , & V_4 -> V_25 ) )
return - V_26 ;
if ( V_27 )
F_16 ( V_28 ) ;
V_23 -> V_29 = V_4 ;
F_10 ( V_4 ) ;
return F_17 ( V_22 , V_23 ) ;
}
static int F_18 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_29 ;
if ( V_4 -> V_30 == 42 )
F_9 ( V_4 ) ;
else {
F_3 ( V_4 -> V_7 ,
L_3 ) ;
F_5 ( V_4 ) ;
}
F_19 ( 0 , & V_4 -> V_25 ) ;
V_4 -> V_30 = 0 ;
return 0 ;
}
static T_2 F_20 ( struct V_23 * V_23 , const char * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
struct V_3 * V_4 = V_23 -> V_29 ;
if ( V_32 ) {
if ( ! V_27 ) {
T_3 V_34 ;
V_4 -> V_30 = 0 ;
for ( V_34 = 0 ; V_34 != V_32 ; V_34 ++ ) {
char V_35 ;
if ( F_21 ( V_35 , V_31 + V_34 ) )
return - V_36 ;
if ( V_35 == 'V' )
V_4 -> V_30 = 42 ;
}
}
F_5 ( V_4 ) ;
}
return V_32 ;
}
static long F_22 ( struct V_23 * V_23 , unsigned int V_37 ,
unsigned long V_2 )
{
struct V_3 * V_4 = V_23 -> V_29 ;
int V_38 ;
union {
struct V_39 V_40 ;
int V_34 ;
} V_41 ;
if ( F_23 ( V_37 ) && F_24 ( V_37 ) > sizeof( V_41 ) )
return - V_42 ;
if ( F_23 ( V_37 ) & V_43 ) {
V_38 = F_25 ( & V_41 , ( void V_44 * ) V_2 , F_24 ( V_37 ) ) ;
if ( V_38 )
return - V_36 ;
}
switch ( V_37 ) {
case V_45 :
V_41 . V_40 = V_40 ;
V_38 = 0 ;
break;
case V_46 :
case V_47 :
V_41 . V_34 = 0 ;
V_38 = 0 ;
break;
case V_48 :
V_38 = - V_21 ;
if ( V_41 . V_34 & V_49 ) {
F_9 ( V_4 ) ;
V_38 = 0 ;
}
if ( V_41 . V_34 & V_50 ) {
F_10 ( V_4 ) ;
V_38 = 0 ;
}
break;
case V_51 :
F_5 ( V_4 ) ;
V_38 = 0 ;
break;
case V_52 :
V_38 = F_12 ( V_41 . V_34 ) ;
if ( V_38 )
break;
F_5 ( V_4 ) ;
case V_53 :
V_41 . V_34 = V_14 ;
V_38 = 0 ;
break;
default:
return - V_42 ;
}
if ( V_38 == 0 && F_23 ( V_37 ) & V_54 ) {
V_38 = F_26 ( ( void V_44 * ) V_2 , & V_41 , F_24 ( V_37 ) ) ;
if ( V_38 )
V_38 = - V_36 ;
}
return V_38 ;
}
static void F_27 ( struct V_55 * V_56 )
{
struct V_3 * V_4 = F_14 ( V_56 ) ;
if ( V_57 == V_58 || V_57 == V_59 )
F_9 ( V_4 ) ;
}
static int F_28 ( struct V_55 * V_56 )
{
struct V_3 * V_4 ;
struct V_60 * V_61 ;
int V_38 ;
if ( V_56 -> V_62 != - 1 )
return - V_63 ;
V_61 = F_29 ( V_56 , V_64 , 0 ) ;
if ( ! V_61 )
return - V_63 ;
V_4 = F_30 ( & V_56 -> V_7 , sizeof( struct V_3 ) , V_65 ) ;
if ( ! V_4 )
return - V_66 ;
V_4 -> V_7 = & V_56 -> V_7 ;
V_4 -> V_1 = F_31 ( V_56 , 0 ) ;
if ( V_4 -> V_1 >= 0 ) {
V_38 = F_32 ( V_4 -> V_7 , V_4 -> V_1 , F_1 , 0 ,
L_4 , V_4 ) ;
if ( V_38 ) {
F_33 ( V_4 -> V_7 ,
L_5 ,
V_4 -> V_1 ) ;
return V_38 ;
}
}
V_4 -> V_5 = F_34 ( V_4 -> V_7 , V_61 -> V_67 , F_35 ( V_61 ) ) ;
if ( ! V_4 -> V_5 )
return - V_66 ;
V_68 . V_69 = & V_56 -> V_7 ;
V_38 = F_36 ( & V_68 ) ;
if ( V_38 ) {
F_33 ( V_4 -> V_7 ,
L_6 ,
V_70 , V_38 ) ;
return V_38 ;
}
F_9 ( V_4 ) ;
F_37 ( V_56 , V_4 ) ;
V_24 = V_56 ;
return 0 ;
}
static int F_38 ( struct V_55 * V_56 )
{
F_37 ( V_56 , NULL ) ;
F_39 ( & V_68 ) ;
V_24 = NULL ;
return 0 ;
}
static int F_40 ( struct V_55 * V_56 , T_5 V_71 )
{
struct V_3 * V_4 = F_14 ( V_56 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_41 ( struct V_55 * V_56 )
{
struct V_3 * V_4 = F_14 ( V_56 ) ;
if ( F_42 ( 0 , & V_4 -> V_25 ) )
F_10 ( V_4 ) ;
return 0 ;
}
static int T_6 F_43 ( void )
{
if ( F_12 ( V_14 ) ) {
F_12 ( V_72 ) ;
F_44 ( L_7 ,
V_72 ) ;
}
F_44 ( L_8 ,
V_19 , V_14 , V_27 ) ;
return F_45 ( & V_73 ) ;
}
static void T_7 F_46 ( void )
{
F_47 ( & V_73 ) ;
}
