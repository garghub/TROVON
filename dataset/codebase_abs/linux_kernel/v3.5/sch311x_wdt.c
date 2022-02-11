static inline void F_1 ( int V_1 )
{
F_2 ( 0x55 , V_1 ) ;
}
static inline void F_3 ( int V_1 )
{
F_2 ( 0xaa , V_1 ) ;
}
static inline int F_4 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_5 ( V_1 + 1 ) ;
}
static inline void F_6 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static void F_7 ( int V_4 )
{
unsigned char V_5 = 0x80 ;
if ( V_4 > 255 ) {
V_5 = 0 ;
V_4 /= 60 ;
}
F_2 ( V_5 , V_6 . V_7 + V_8 ) ;
F_2 ( V_4 , V_6 . V_7 + V_9 ) ;
}
static void F_8 ( void )
{
F_9 ( & V_6 . V_10 ) ;
F_7 ( V_11 ) ;
F_2 ( 0x0e , V_6 . V_7 + V_12 ) ;
F_10 ( & V_6 . V_10 ) ;
}
static void F_11 ( void )
{
F_9 ( & V_6 . V_10 ) ;
F_2 ( 0x01 , V_6 . V_7 + V_12 ) ;
F_7 ( 0 ) ;
F_10 ( & V_6 . V_10 ) ;
}
static void F_12 ( void )
{
F_9 ( & V_6 . V_10 ) ;
F_7 ( V_11 ) ;
F_10 ( & V_6 . V_10 ) ;
}
static int F_13 ( int V_4 )
{
if ( V_4 < 1 || V_4 > ( 255 * 60 ) )
return - V_13 ;
if ( V_4 > 255 )
V_4 = ( ( ( V_4 - 1 ) / 60 ) + 1 ) * 60 ;
V_11 = V_4 ;
return 0 ;
}
static void F_14 ( int * V_14 )
{
unsigned char V_15 ;
* V_14 = 0 ;
F_9 ( & V_6 . V_10 ) ;
V_15 = F_5 ( V_6 . V_7 + V_16 ) ;
if ( V_15 & 0x01 )
* V_14 |= V_17 ;
F_10 ( & V_6 . V_10 ) ;
}
static T_1 F_15 ( struct V_18 * V_18 , const char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
if ( V_20 ) {
if ( ! V_22 ) {
T_3 V_23 ;
V_24 = 0 ;
for ( V_23 = 0 ; V_23 != V_20 ; V_23 ++ ) {
char V_25 ;
if ( F_16 ( V_25 , V_19 + V_23 ) )
return - V_26 ;
if ( V_25 == 'V' )
V_24 = 42 ;
}
}
F_12 () ;
}
return V_20 ;
}
static long F_17 ( struct V_18 * V_18 , unsigned int V_27 ,
unsigned long V_28 )
{
int V_14 ;
int V_29 ;
void T_2 * V_30 = ( void T_2 * ) V_28 ;
int T_2 * V_31 = V_30 ;
static const struct V_32 V_33 = {
. V_34 = V_35 |
V_36 |
V_37 ,
. V_38 = 1 ,
. V_39 = V_40 ,
} ;
switch ( V_27 ) {
case V_41 :
if ( F_18 ( V_30 , & V_33 , sizeof( V_33 ) ) )
return - V_26 ;
break;
case V_42 :
{
F_14 ( & V_14 ) ;
return F_19 ( V_14 , V_31 ) ;
}
case V_43 :
return F_19 ( V_6 . V_44 , V_31 ) ;
case V_45 :
{
int V_34 , V_46 = - V_13 ;
if ( F_16 ( V_34 , V_31 ) )
return - V_26 ;
if ( V_34 & V_47 ) {
F_11 () ;
V_46 = 0 ;
}
if ( V_34 & V_48 ) {
F_8 () ;
V_46 = 0 ;
}
return V_46 ;
}
case V_49 :
F_12 () ;
break;
case V_50 :
if ( F_16 ( V_29 , V_31 ) )
return - V_26 ;
if ( F_13 ( V_29 ) )
return - V_13 ;
F_12 () ;
case V_51 :
return F_19 ( V_11 , V_31 ) ;
default:
return - V_52 ;
}
return 0 ;
}
static int F_20 ( struct V_53 * V_53 , struct V_18 * V_18 )
{
if ( F_21 ( 0 , & V_54 ) )
return - V_55 ;
F_8 () ;
return F_22 ( V_53 , V_18 ) ;
}
static int F_23 ( struct V_53 * V_53 , struct V_18 * V_18 )
{
if ( V_24 == 42 ) {
F_11 () ;
} else {
F_24 ( L_1 ) ;
F_12 () ;
}
F_25 ( 0 , & V_54 ) ;
V_24 = 0 ;
return 0 ;
}
static int T_5 F_26 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = & V_57 -> V_59 ;
int V_60 ;
F_27 ( & V_6 . V_10 ) ;
if ( ! F_28 ( V_6 . V_7 + V_12 , 1 , V_40 ) ) {
F_29 ( V_59 , L_2 ,
V_6 . V_7 + V_12 ,
V_6 . V_7 + V_12 ) ;
V_60 = - V_55 ;
goto exit;
}
if ( ! F_28 ( V_6 . V_7 + V_8 , 4 ,
V_40 ) ) {
F_29 ( V_59 , L_2 ,
V_6 . V_7 + V_8 ,
V_6 . V_7 + V_16 ) ;
V_60 = - V_55 ;
goto V_61;
}
F_11 () ;
F_2 ( 0 , V_6 . V_7 + V_62 ) ;
if ( F_13 ( V_11 ) ) {
F_13 ( V_63 ) ;
F_30 ( V_59 , L_3 ,
V_11 ) ;
}
F_14 ( & V_6 . V_44 ) ;
V_64 . V_65 = V_59 ;
V_60 = F_31 ( & V_64 ) ;
if ( V_60 != 0 ) {
F_29 ( V_59 , L_4 ,
V_66 , V_60 ) ;
goto V_67;
}
F_30 ( V_59 ,
L_5 ,
V_11 , V_22 ) ;
return 0 ;
V_67:
F_32 ( V_6 . V_7 + V_8 , 4 ) ;
V_61:
F_32 ( V_6 . V_7 + V_12 , 1 ) ;
V_6 . V_7 = 0 ;
exit:
return V_60 ;
}
static int T_6 F_33 ( struct V_56 * V_57 )
{
if ( ! V_22 )
F_11 () ;
F_34 ( & V_64 ) ;
F_32 ( V_6 . V_7 + V_8 , 4 ) ;
F_32 ( V_6 . V_7 + V_12 , 1 ) ;
V_6 . V_7 = 0 ;
return 0 ;
}
static void F_35 ( struct V_56 * V_59 )
{
F_11 () ;
}
static int T_7 F_36 ( int V_1 , unsigned short * V_68 )
{
int V_60 = 0 , V_2 ;
unsigned short V_69 ;
unsigned char V_70 ;
F_1 ( V_1 ) ;
V_2 = V_71 ? V_71 : F_4 ( V_1 , 0x20 ) ;
if ( ! ( V_2 == 0x7c || V_2 == 0x7d || V_2 == 0x7f ) ) {
V_60 = - V_72 ;
goto exit;
}
V_70 = V_2 == 0x7c ? 2 : V_2 == 0x7d ? 4 : 6 ;
F_6 ( V_1 , 0x07 , 0x0a ) ;
if ( ( F_4 ( V_1 , 0x30 ) & 0x01 ) == 0 )
F_37 ( L_6 ) ;
V_69 = ( F_4 ( V_1 , 0x60 ) << 8 ) |
F_4 ( V_1 , 0x61 ) ;
if ( ! V_69 ) {
F_38 ( L_7 ) ;
V_60 = - V_72 ;
goto exit;
}
* V_68 = V_69 ;
F_37 ( L_8 , V_70 , V_69 ) ;
exit:
F_3 ( V_1 ) ;
return V_60 ;
}
static int T_7 F_39 ( void )
{
int V_60 , V_23 , V_73 = 0 ;
unsigned short V_68 = 0 ;
for ( V_23 = 0 ; ! V_73 && V_74 [ V_23 ] ; V_23 ++ )
if ( F_36 ( V_74 [ V_23 ] , & V_68 ) == 0 )
V_73 ++ ;
if ( ! V_73 )
return - V_72 ;
V_6 . V_7 = V_68 ;
V_60 = F_40 ( & V_75 ) ;
if ( V_60 )
return V_60 ;
V_76 = F_41 ( V_40 , V_68 ,
NULL , 0 ) ;
if ( F_42 ( V_76 ) ) {
V_60 = F_43 ( V_76 ) ;
goto V_77;
}
return 0 ;
V_77:
F_44 ( & V_75 ) ;
return V_60 ;
}
static void T_8 F_45 ( void )
{
F_46 ( V_76 ) ;
F_44 ( & V_75 ) ;
}
