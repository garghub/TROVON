static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( F_2 ( V_4 -> V_5 + V_6 ) ) {
F_3 ( V_7 , V_4 -> V_8 ,
L_1 ) ;
F_4 ( 1 , V_4 -> V_5 + V_6 ) ;
return V_9 ;
}
return V_10 ;
}
static void F_5 ( struct V_3 * V_4 )
{
unsigned long V_11 ;
F_6 ( & V_12 ) ;
V_11 = F_7 ( V_4 -> V_5 + V_13 ) ;
V_11 = ( 0xFFFFFFFFU - V_11 ) * ( V_14 / 5 ) ;
V_11 = ( V_11 / 256 ) * V_15 ;
F_4 ( V_11 + V_4 -> V_16 , V_4 -> V_5 + V_17 ) ;
V_4 -> V_16 = V_4 -> V_16 ? 0 : 1 ;
F_8 ( & V_12 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
F_6 ( & V_12 ) ;
F_4 ( 0x12345678 , V_4 -> V_5 + V_18 ) ;
F_4 ( 0x87654321 , V_4 -> V_5 + V_18 ) ;
F_4 ( 0x0 , V_4 -> V_5 + V_19 ) ;
F_8 ( & V_12 ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_3 ( V_20 , V_4 -> V_8 , L_2 ) ;
F_5 ( V_4 ) ;
if ( V_21 ) {
F_4 ( 0x0000FF01 , V_4 -> V_5 + V_19 ) ;
} else {
F_4 ( 0x0000FF09 , V_4 -> V_5 + V_19 ) ;
}
}
static int F_11 ( int V_22 )
{
if ( V_22 < 0x0001 || V_22 > 0xFFFF )
return - V_23 ;
V_15 = V_22 ;
return 0 ;
}
static int F_12 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_3 * V_4 = F_13 ( V_26 ) ;
if ( F_14 ( 0 , & V_4 -> V_27 ) )
return - V_28 ;
if ( V_29 )
F_15 ( V_30 ) ;
V_25 -> V_31 = V_4 ;
F_10 ( V_4 ) ;
return F_16 ( V_24 , V_25 ) ;
}
static int F_17 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_3 * V_4 = V_25 -> V_31 ;
if ( V_4 -> V_32 == 42 )
F_9 ( V_4 ) ;
else {
F_3 ( V_7 , V_4 -> V_8 ,
L_3 ) ;
F_5 ( V_4 ) ;
}
F_18 ( 0 , & V_4 -> V_27 ) ;
V_4 -> V_32 = 0 ;
return 0 ;
}
static T_2 F_19 ( struct V_25 * V_25 , const char * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
struct V_3 * V_4 = V_25 -> V_31 ;
if ( V_34 ) {
if ( ! V_29 ) {
T_3 V_36 ;
V_4 -> V_32 = 0 ;
for ( V_36 = 0 ; V_36 != V_34 ; V_36 ++ ) {
char V_37 ;
if ( F_20 ( V_37 , V_33 + V_36 ) )
return - V_38 ;
if ( V_37 == 'V' )
V_4 -> V_32 = 42 ;
}
}
F_5 ( V_4 ) ;
}
return V_34 ;
}
static long F_21 ( struct V_25 * V_25 , unsigned int V_39 ,
unsigned long V_2 )
{
struct V_3 * V_4 = V_25 -> V_31 ;
int V_40 ;
union {
struct V_41 V_42 ;
int V_36 ;
} V_43 ;
if ( F_22 ( V_39 ) && F_23 ( V_39 ) > sizeof( V_43 ) )
return - V_44 ;
if ( F_22 ( V_39 ) & V_45 ) {
V_40 = F_24 ( & V_43 , ( void V_46 * ) V_2 , F_23 ( V_39 ) ) ;
if ( V_40 )
return - V_38 ;
}
switch ( V_39 ) {
case V_47 :
V_43 . V_42 = V_42 ;
V_40 = 0 ;
break;
case V_48 :
case V_49 :
V_43 . V_36 = 0 ;
V_40 = 0 ;
break;
case V_50 :
V_40 = - V_23 ;
if ( V_43 . V_36 & V_51 ) {
F_9 ( V_4 ) ;
V_40 = 0 ;
}
if ( V_43 . V_36 & V_52 ) {
F_10 ( V_4 ) ;
V_40 = 0 ;
}
break;
case V_53 :
F_5 ( V_4 ) ;
V_40 = 0 ;
break;
case V_54 :
V_40 = F_11 ( V_43 . V_36 ) ;
if ( V_40 )
break;
F_5 ( V_4 ) ;
case V_55 :
V_43 . V_36 = V_15 ;
V_40 = 0 ;
break;
default:
return - V_44 ;
}
if ( V_40 == 0 && F_22 ( V_39 ) & V_56 ) {
V_40 = F_25 ( ( void V_46 * ) V_2 , & V_43 , F_23 ( V_39 ) ) ;
if ( V_40 )
V_40 = - V_38 ;
}
return V_40 ;
}
static void F_26 ( struct V_57 * V_8 )
{
struct V_3 * V_4 = F_13 ( V_8 ) ;
if ( V_58 == V_59 || V_58 == V_60 )
F_9 ( V_4 ) ;
}
static int T_5 F_27 ( struct V_57 * V_8 )
{
struct V_3 * V_4 ;
struct V_61 * V_62 ;
int V_40 ;
if ( V_8 -> V_63 != - 1 )
return - V_64 ;
V_62 = F_28 ( V_8 , V_65 , 0 ) ;
if ( ! V_62 ) {
V_40 = - V_64 ;
goto V_66;
}
V_4 = F_29 ( sizeof( struct V_3 ) , V_67 ) ;
if ( ! V_4 ) {
V_40 = - V_68 ;
goto V_66;
}
V_4 -> V_8 = & V_8 -> V_8 ;
V_4 -> V_1 = F_30 ( V_8 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
V_40 = - V_69 ;
goto V_70;
}
V_4 -> V_5 = F_31 ( V_62 -> V_71 , F_32 ( V_62 ) ) ;
if ( ! V_4 -> V_5 ) {
V_40 = - V_68 ;
goto V_70;
}
V_72 . V_73 = & V_8 -> V_8 ;
V_40 = F_33 ( & V_72 ) ;
if ( V_40 ) {
F_3 ( V_74 , V_4 -> V_8 ,
L_4 ,
V_75 , V_40 ) ;
goto V_76;
}
V_40 = F_34 ( V_4 -> V_1 , F_1 , 0 , L_5 , V_4 ) ;
if ( V_40 ) {
F_3 ( V_74 , V_4 -> V_8 ,
L_6 , V_4 -> V_1 ) ;
goto V_77;
}
F_9 ( V_4 ) ;
F_35 ( V_8 , V_4 ) ;
V_26 = V_8 ;
return 0 ;
V_77:
F_36 ( & V_72 ) ;
V_76:
F_37 ( V_4 -> V_5 ) ;
V_70:
F_38 ( V_4 ) ;
V_66:
return V_40 ;
}
static int T_6 F_39 ( struct V_57 * V_8 )
{
struct V_3 * V_4 = F_13 ( V_8 ) ;
F_35 ( V_8 , NULL ) ;
F_36 ( & V_72 ) ;
V_26 = NULL ;
F_40 ( V_4 -> V_1 , V_4 ) ;
F_37 ( V_4 -> V_5 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_41 ( struct V_57 * V_8 , T_7 V_78 )
{
struct V_3 * V_4 = F_13 ( V_8 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_42 ( struct V_57 * V_8 )
{
struct V_3 * V_4 = F_13 ( V_8 ) ;
if ( F_43 ( 0 , & V_4 -> V_27 ) )
F_10 ( V_4 ) ;
return 0 ;
}
static int T_8 F_44 ( void )
{
if ( F_11 ( V_15 ) ) {
F_11 ( V_79 ) ;
F_45 ( V_20 L_7 ,
V_79 ) ;
}
F_45 ( V_80 , V_21 , V_15 , V_29 ) ;
return F_46 ( & V_81 ) ;
}
static void T_9 F_47 ( void )
{
F_48 ( & V_81 ) ;
}
