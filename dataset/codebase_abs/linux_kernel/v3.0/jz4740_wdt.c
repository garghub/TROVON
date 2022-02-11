static void F_1 ( void )
{
F_2 ( 0x0 , V_1 . V_2 + V_3 ) ;
}
static void F_3 ( int V_4 )
{
unsigned int V_5 ;
unsigned int V_6 ;
unsigned short V_7 = V_8 ;
V_9 = V_4 ;
V_5 = F_4 ( V_1 . V_10 ) ;
V_6 = V_5 * V_9 ;
while ( V_6 > 0xffff ) {
if ( V_7 == V_11 ) {
V_6 = 0xffff ;
break;
}
V_6 >>= 2 ;
V_7 += ( 1 << V_12 ) ;
}
F_5 ( 0x0 , V_1 . V_2 + V_13 ) ;
F_2 ( V_7 , V_1 . V_2 + V_14 ) ;
F_2 ( ( V_15 ) V_6 , V_1 . V_2 + V_16 ) ;
F_2 ( 0x0 , V_1 . V_2 + V_3 ) ;
F_2 ( V_7 | V_17 ,
V_1 . V_2 + V_14 ) ;
F_5 ( 0x1 , V_1 . V_2 + V_13 ) ;
}
static void F_6 ( void )
{
F_7 () ;
F_3 ( V_9 ) ;
}
static void F_8 ( void )
{
F_9 () ;
F_5 ( 0x0 , V_1 . V_2 + V_13 ) ;
}
static int F_10 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
if ( F_11 ( V_20 , & V_1 . V_21 ) )
return - V_22 ;
F_6 () ;
return F_12 ( V_18 , V_19 ) ;
}
static T_1 F_13 ( struct V_19 * V_19 , const char * V_23 ,
T_2 V_24 , T_3 * V_25 )
{
if ( V_24 ) {
T_2 V_26 ;
F_14 ( V_27 , & V_1 . V_21 ) ;
for ( V_26 = 0 ; V_26 != V_24 ; V_26 ++ ) {
char V_28 ;
if ( F_15 ( V_28 , V_23 + V_26 ) )
return - V_29 ;
if ( V_28 == 'V' )
F_16 ( V_27 , & V_1 . V_21 ) ;
}
F_1 () ;
}
return V_24 ;
}
static long F_17 ( struct V_19 * V_19 ,
unsigned int V_30 , unsigned long V_31 )
{
int V_32 = - V_33 ;
int V_34 ;
switch ( V_30 ) {
case V_35 :
V_32 = F_18 ( (struct V_36 * ) V_31 , & V_37 ,
sizeof( V_37 ) ) ? - V_29 : 0 ;
break;
case V_38 :
case V_39 :
V_32 = F_19 ( 0 , ( int * ) V_31 ) ;
break;
case V_40 :
F_1 () ;
return 0 ;
case V_41 :
if ( F_15 ( V_34 , ( int V_42 * ) V_31 ) )
return - V_29 ;
F_3 ( V_34 ) ;
return 0 ;
case V_43 :
return F_19 ( V_9 , ( int * ) V_31 ) ;
default:
break;
}
return V_32 ;
}
static int F_20 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
F_1 () ;
if ( F_21 ( V_27 , & V_1 . V_21 ) )
F_8 () ;
F_14 ( V_20 , & V_1 . V_21 ) ;
return 0 ;
}
static int T_4 F_22 ( struct V_44 * V_45 )
{
int V_32 = 0 , V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 = & V_45 -> V_50 ;
V_48 = F_23 ( V_45 , V_51 , 0 ) ;
if ( V_48 == NULL ) {
F_24 ( V_50 , L_1 ) ;
return - V_52 ;
}
V_46 = F_25 ( V_48 ) ;
V_1 . V_53 = F_26 ( V_48 -> V_54 , V_46 , V_45 -> V_55 ) ;
if ( V_1 . V_53 == NULL ) {
F_24 ( V_50 , L_2 ) ;
return - V_22 ;
}
V_1 . V_2 = F_27 ( V_48 -> V_54 , V_46 ) ;
if ( V_1 . V_2 == NULL ) {
F_24 ( V_50 , L_3 ) ;
V_32 = - V_22 ;
goto V_56;
}
V_1 . V_10 = F_28 ( NULL , L_4 ) ;
if ( F_29 ( V_1 . V_10 ) ) {
F_24 ( V_50 , L_5 ) ;
V_32 = F_30 ( V_1 . V_10 ) ;
goto V_57;
}
V_32 = F_31 ( & V_58 ) ;
if ( V_32 < 0 ) {
F_24 ( V_50 , L_6 ) ;
goto V_59;
}
return 0 ;
V_59:
F_32 ( V_1 . V_10 ) ;
V_57:
F_33 ( V_1 . V_2 ) ;
V_56:
F_34 ( V_1 . V_53 -> V_54 ,
F_25 ( V_1 . V_53 ) ) ;
return V_32 ;
}
static int T_5 F_35 ( struct V_44 * V_45 )
{
F_8 () ;
F_36 ( & V_58 ) ;
F_32 ( V_1 . V_10 ) ;
F_33 ( V_1 . V_2 ) ;
V_1 . V_2 = NULL ;
F_34 ( V_1 . V_53 -> V_54 ,
F_25 ( V_1 . V_53 ) ) ;
V_1 . V_53 = NULL ;
return 0 ;
}
static int T_6 F_37 ( void )
{
return F_38 ( & V_60 ) ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_60 ) ;
}
