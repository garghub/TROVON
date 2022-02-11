static inline void F_1 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 -> V_3 ) ;
V_1 = F_3 ( V_2 , V_4 ) & F_4 ( V_5 , 0x0f ) ;
F_5 ( V_2 , V_4 , V_1 | F_4 ( V_6 , 0x55 ) ) ;
F_5 ( V_2 , V_4 , V_1 | F_4 ( V_6 , 0xaa ) ) ;
F_6 ( & V_2 -> V_3 ) ;
}
static inline void F_7 ( void )
{
unsigned long V_1 = ( V_2 -> V_7 > 1 ) ? 0xf : 0xe ;
F_2 ( & V_2 -> V_3 ) ;
F_5 ( V_2 , V_4 , F_8 ( V_8 )
| F_4 ( V_5 , V_1 )
| F_4 ( V_6 , 0x55 ) ) ;
F_5 ( V_2 , V_4 , F_8 ( V_8 )
| F_4 ( V_5 , V_1 )
| F_4 ( V_6 , 0xaa ) ) ;
F_6 ( & V_2 -> V_3 ) ;
}
static inline void F_9 ( void )
{
F_2 ( & V_2 -> V_3 ) ;
F_5 ( V_2 , V_9 , 0x42 ) ;
F_6 ( & V_2 -> V_3 ) ;
}
static int F_10 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_11 ( 1 , & V_2 -> V_12 ) )
return - V_13 ;
F_7 () ;
return F_12 ( V_10 , V_11 ) ;
}
static int F_13 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( V_14 == 42 ) {
F_1 () ;
} else {
F_14 ( V_2 -> V_15 . V_16 ,
L_1 ) ;
F_9 () ;
}
F_15 ( 1 , & V_2 -> V_12 ) ;
V_14 = 0 ;
return 0 ;
}
static int F_16 ( int time )
{
if ( ( time < V_17 ) || ( time > V_18 ) )
return - V_19 ;
V_2 -> V_7 = time ;
return 0 ;
}
static int F_17 ( void )
{
int V_20 ;
int V_21 = 0 ;
V_20 = F_3 ( V_2 , V_22 ) ;
switch ( V_20 ) {
case F_8 ( V_23 ) :
V_21 = V_24 ;
break;
case F_8 ( V_25 ) :
V_21 = V_26 ;
break;
case F_8 ( V_27 ) :
case F_8 ( V_28 ) :
case F_8 ( V_29 ) :
default:
break;
}
return V_21 ;
}
static long F_18 ( struct V_11 * V_11 ,
unsigned int V_30 , unsigned long V_31 )
{
int V_32 = - V_33 ;
int time ;
void T_1 * V_34 = ( void T_1 * ) V_31 ;
int T_1 * V_35 = V_34 ;
switch ( V_30 ) {
case V_36 :
V_32 = F_19 ( V_34 , & V_37 ,
sizeof( V_37 ) ) ? - V_38 : 0 ;
break;
case V_39 :
V_32 = F_20 ( 0 , V_35 ) ;
break;
case V_40 :
V_32 = F_20 ( V_2 -> V_41 , V_35 ) ;
break;
case V_42 :
V_32 = F_21 ( time , V_35 ) ;
if ( V_32 )
break;
if ( time & V_43 )
F_1 () ;
if ( time & V_44 )
F_7 () ;
V_32 = 0 ;
break;
case V_45 :
F_9 () ;
V_32 = 0 ;
break;
case V_46 :
V_32 = F_21 ( time , V_35 ) ;
if ( V_32 )
break;
V_32 = F_16 ( time ) ;
if ( V_32 )
break;
F_7 () ;
case V_47 :
V_32 = F_20 ( V_2 -> V_7 , V_35 ) ;
break;
}
return V_32 ;
}
static T_2 F_22 ( struct V_11 * V_11 , const char T_1 * V_48 ,
T_3 V_49 , T_4 * V_50 )
{
if ( V_49 ) {
if ( ! V_51 ) {
T_3 V_52 ;
V_14 = 0 ;
for ( V_52 = 0 ; V_52 != V_49 ; V_52 ++ ) {
char V_53 ;
if ( F_21 ( V_53 , V_48 + V_52 ) )
return - V_38 ;
if ( V_53 == 'V' )
V_14 = 42 ;
}
}
F_9 () ;
}
return V_49 ;
}
static int T_5 F_23 ( struct V_54 * V_55 )
{
struct V_56 * V_57 ;
int V_32 ;
if ( V_2 ) {
F_14 ( & V_55 -> V_58 , L_2 ) ;
return - V_13 ;
}
V_57 = F_24 ( V_55 , V_59 , 0 ) ;
if ( ! V_57 ) {
F_14 ( & V_55 -> V_58 , L_3 ) ;
return - V_60 ;
}
V_2 = F_25 ( & V_55 -> V_58 , sizeof( struct V_61 ) ,
V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_57 = F_26 ( & V_55 -> V_58 , V_57 -> V_64 , F_27 ( V_57 ) ) ;
if ( ! V_2 -> V_57 ) {
V_32 = - V_63 ;
F_14 ( & V_55 -> V_58 , L_4 ) ;
goto V_65;
}
F_28 ( & V_2 -> V_3 ) ;
V_2 -> V_41 = F_17 () ;
if ( V_2 -> V_41 & V_26 ) {
F_29 ( & V_55 -> V_58 , L_5
L_6 ) ;
V_32 = - V_66 ;
goto V_65;
} else {
V_2 -> V_12 = 0 ;
}
V_2 -> V_15 . V_67 = V_68 ;
V_2 -> V_15 . V_69 = L_7 ;
V_2 -> V_15 . V_70 = & V_71 ;
V_2 -> V_15 . V_16 = & V_55 -> V_58 ;
F_30 ( V_55 , V_2 ) ;
if ( F_16 ( V_7 ) ) {
F_16 ( V_72 ) ;
F_14 ( & V_55 -> V_58 ,
L_8 ,
V_72 ) ;
}
V_32 = F_31 ( & V_2 -> V_15 ) ;
if ( V_32 ) {
F_14 ( & V_55 -> V_58 , L_9 ) ;
goto V_65;
}
F_29 ( & V_55 -> V_58 ,
L_10 ,
V_2 -> V_57 , V_2 -> V_7 , V_51 ) ;
return 0 ;
V_65:
V_2 = NULL ;
return V_32 ;
}
static int T_6 F_32 ( struct V_54 * V_55 )
{
if ( V_2 && F_33 ( V_55 ) == V_2 ) {
if ( ! V_51 )
F_1 () ;
F_34 ( & V_2 -> V_15 ) ;
V_2 = NULL ;
}
return 0 ;
}
static void F_35 ( struct V_54 * V_55 )
{
F_1 () ;
}
static int F_36 ( struct V_54 * V_55 , T_7 V_73 )
{
F_1 () ;
return 0 ;
}
static int F_37 ( struct V_54 * V_55 )
{
if ( V_2 -> V_12 )
F_7 () ;
return 0 ;
}
