static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 ) ;
F_2 ( V_2 , V_4 ) ;
}
static inline int F_3 ( int V_1 )
{
F_2 ( V_1 , V_3 ) ;
return F_4 ( V_4 ) ;
}
static inline void F_5 ( int V_5 )
{
F_1 ( 0x07 , V_5 ) ;
}
static inline void F_6 ( void )
{
F_2 ( 0x55 , V_3 ) ;
}
static inline void F_7 ( void )
{
F_2 ( 0xAA , V_3 ) ;
}
static int F_8 ( struct V_6 * V_7 , T_1 V_1 )
{
int V_8 ;
F_9 ( & V_7 -> V_9 ) ;
F_2 ( V_1 , V_7 -> V_10 ) ;
V_8 = F_10 ( V_7 -> V_10 + 1 ) ;
F_11 ( & V_7 -> V_9 ) ;
return V_8 ;
}
static struct V_6 * F_12 ( struct V_11 * V_12 )
{
struct V_6 * V_7 = F_13 ( V_12 ) ;
int V_13 ;
F_9 ( & V_7 -> V_14 ) ;
if ( F_14 ( V_15 , V_7 -> V_16 + V_17 ) || ! V_7 -> V_18 ) {
F_15 ( V_12 , L_1 ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_7 -> V_19 [ V_13 ] = F_8 ( V_7 ,
F_16 ( V_13 ) ) ;
V_7 -> V_20 [ V_13 ] = F_8 ( V_7 ,
F_17 ( V_13 ) ) ;
V_7 -> V_20 [ V_13 ] |= F_8 ( V_7 ,
F_18 ( V_13 ) ) << 8 ;
}
V_7 -> V_16 = V_15 ;
V_7 -> V_18 = 1 ;
F_15 ( V_12 , L_2 ) ;
}
F_11 ( & V_7 -> V_14 ) ;
return V_7 ;
}
static int F_19 ( T_1 V_1 )
{
return ( V_21 ) V_1 * 1000 ;
}
static T_2 F_20 ( struct V_11 * V_12 , struct V_22
* V_23 , char * V_24 )
{
struct V_25 * V_26 = F_21 ( V_23 ) ;
struct V_6 * V_7 = F_12 ( V_12 ) ;
return sprintf ( V_24 , L_3 , F_19 ( V_7 -> V_19 [ V_26 -> V_27 ] ) ) ;
}
static int F_22 ( T_3 V_1 )
{
if ( V_1 == 0 || V_1 == 0xffff )
return 0 ;
return 90000 * 60 / V_1 ;
}
static T_2 F_23 ( struct V_11 * V_12 , struct V_22
* V_23 , char * V_24 )
{
struct V_25 * V_26 = F_21 ( V_23 ) ;
struct V_6 * V_7 = F_12 ( V_12 ) ;
return sprintf ( V_24 , L_3 , F_22 ( V_7 -> V_20 [ V_26 -> V_27 ] ) ) ;
}
static T_2 F_24 ( struct V_11 * V_12 , struct V_22
* V_23 , char * V_24 )
{
struct V_6 * V_7 = F_13 ( V_12 ) ;
return sprintf ( V_24 , L_4 , V_7 -> V_28 ) ;
}
static int T_4 F_25 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = F_26 ( V_30 ) ;
F_27 ( V_7 -> V_31 ) ;
F_28 ( & V_30 -> V_12 . V_32 , & V_33 ) ;
return 0 ;
}
static int T_5 F_29 ( struct V_29 * V_30 )
{
struct V_11 * V_12 = & V_30 -> V_12 ;
struct V_6 * V_7 ;
struct V_34 * V_8 ;
int V_35 = 0 ;
V_8 = F_30 ( V_30 , V_36 , 0 ) ;
if ( ! F_31 ( V_12 , V_8 -> V_37 , V_38 ,
V_39 . V_40 . V_28 ) ) {
F_32 ( V_12 , L_5 ,
( unsigned long ) V_8 -> V_37 ,
( unsigned long ) V_8 -> V_37 + V_38 - 1 ) ;
return - V_41 ;
}
V_7 = F_33 ( V_12 , sizeof( struct V_6 ) , V_42 ) ;
if ( ! V_7 )
return - V_43 ;
V_7 -> V_10 = V_8 -> V_37 ;
V_7 -> V_28 = L_6 ;
F_34 ( & V_7 -> V_9 ) ;
F_34 ( & V_7 -> V_14 ) ;
F_35 ( V_30 , V_7 ) ;
V_35 = F_36 ( & V_12 -> V_32 , & V_33 ) ;
if ( V_35 )
return V_35 ;
V_7 -> V_31 = F_37 ( V_12 ) ;
if ( F_38 ( V_7 -> V_31 ) ) {
V_35 = F_39 ( V_7 -> V_31 ) ;
goto V_44;
}
return 0 ;
V_44:
F_28 ( & V_12 -> V_32 , & V_33 ) ;
return V_35 ;
}
static int T_6 F_40 ( unsigned short V_45 )
{
struct V_34 V_8 = {
. V_37 = V_45 ,
. V_46 = V_45 + V_38 - 1 ,
. V_28 = V_47 ,
. V_48 = V_36 ,
} ;
int V_35 ;
V_35 = F_41 ( & V_8 ) ;
if ( V_35 )
goto exit;
V_30 = F_42 ( V_47 , V_45 ) ;
if ( ! V_30 ) {
V_35 = - V_43 ;
F_43 ( L_7 ) ;
goto exit;
}
V_35 = F_44 ( V_30 , & V_8 , 1 ) ;
if ( V_35 ) {
F_43 ( L_8 , V_35 ) ;
goto V_49;
}
V_35 = F_45 ( V_30 ) ;
if ( V_35 ) {
F_43 ( L_9 , V_35 ) ;
goto V_49;
}
return 0 ;
V_49:
F_46 ( V_30 ) ;
exit:
return V_35 ;
}
static int T_6 F_47 ( void )
{
T_1 V_50 , V_51 ;
char * V_28 ;
unsigned short V_10 ;
F_6 () ;
V_50 = V_52 ? V_52 : F_3 ( V_53 ) ;
switch ( V_50 ) {
case 0x81 :
V_28 = L_10 ;
break;
case 0x6f :
V_28 = L_11 ;
break;
case 0x85 :
case 0x8c :
V_28 = L_12 ;
break;
default:
F_7 () ;
return - V_54 ;
}
V_51 = F_3 ( V_55 ) ;
F_5 ( V_56 ) ;
V_10 = ( F_3 ( V_57 ) << 8 )
| F_3 ( V_58 ) ;
F_48 ( L_13 ,
V_28 , V_10 , V_51 ) ;
F_7 () ;
return V_10 ;
}
static int T_6 F_49 ( void )
{
unsigned short V_45 ;
int V_59 ;
V_59 = F_47 () ;
if ( V_59 < 0 )
return V_59 ;
V_45 = V_59 ;
V_59 = F_50 ( & V_39 ) ;
if ( V_59 )
goto exit;
V_59 = F_40 ( V_45 ) ;
if ( V_59 )
goto V_60;
return 0 ;
V_60:
F_51 ( & V_39 ) ;
exit:
return V_59 ;
}
static void T_7 F_52 ( void )
{
F_53 ( V_30 ) ;
F_51 ( & V_39 ) ;
}
