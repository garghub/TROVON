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
struct V_31 * V_8 ;
F_27 ( V_7 -> V_32 ) ;
F_28 ( & V_30 -> V_12 . V_33 , & V_34 ) ;
V_8 = F_29 ( V_30 , V_35 , 0 ) ;
F_30 ( V_8 -> V_36 , V_37 ) ;
F_31 ( V_7 ) ;
return 0 ;
}
static int T_5 F_32 ( struct V_29 * V_30 )
{
struct V_11 * V_12 = & V_30 -> V_12 ;
struct V_6 * V_7 ;
struct V_31 * V_8 ;
int V_38 = 0 ;
V_8 = F_29 ( V_30 , V_35 , 0 ) ;
if ( ! F_33 ( V_8 -> V_36 , V_37 ,
V_39 . V_40 . V_28 ) ) {
F_34 ( V_12 , L_5 ,
( unsigned long ) V_8 -> V_36 ,
( unsigned long ) V_8 -> V_36 + V_37 - 1 ) ;
return - V_41 ;
}
V_7 = F_35 ( sizeof( struct V_6 ) , V_42 ) ;
if ( ! V_7 ) {
V_38 = - V_43 ;
goto V_44;
}
V_7 -> V_10 = V_8 -> V_36 ;
V_7 -> V_28 = L_6 ;
F_36 ( & V_7 -> V_9 ) ;
F_36 ( & V_7 -> V_14 ) ;
F_37 ( V_30 , V_7 ) ;
V_38 = F_38 ( & V_12 -> V_33 , & V_34 ) ;
if ( V_38 )
goto V_45;
V_7 -> V_32 = F_39 ( V_12 ) ;
if ( F_40 ( V_7 -> V_32 ) ) {
V_38 = F_41 ( V_7 -> V_32 ) ;
goto V_46;
}
return 0 ;
V_46:
F_28 ( & V_12 -> V_33 , & V_34 ) ;
V_45:
F_31 ( V_7 ) ;
V_44:
F_30 ( V_8 -> V_36 , V_37 ) ;
return V_38 ;
}
static int T_6 F_42 ( unsigned short V_47 )
{
struct V_31 V_8 = {
. V_36 = V_47 ,
. V_48 = V_47 + V_37 - 1 ,
. V_28 = V_49 ,
. V_50 = V_35 ,
} ;
int V_38 ;
V_38 = F_43 ( & V_8 ) ;
if ( V_38 )
goto exit;
V_30 = F_44 ( V_49 , V_47 ) ;
if ( ! V_30 ) {
V_38 = - V_43 ;
F_45 ( L_7 ) ;
goto exit;
}
V_38 = F_46 ( V_30 , & V_8 , 1 ) ;
if ( V_38 ) {
F_45 ( L_8 , V_38 ) ;
goto V_51;
}
V_38 = F_47 ( V_30 ) ;
if ( V_38 ) {
F_45 ( L_9 , V_38 ) ;
goto V_51;
}
return 0 ;
V_51:
F_48 ( V_30 ) ;
exit:
return V_38 ;
}
static int T_6 F_49 ( unsigned short * V_10 )
{
T_1 V_52 , V_53 ;
char * V_28 ;
F_6 () ;
V_52 = V_54 ? V_54 : F_3 ( V_55 ) ;
switch ( V_52 ) {
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
return - V_56 ;
}
V_53 = F_3 ( V_57 ) ;
F_5 ( V_58 ) ;
* V_10 = ( F_3 ( V_59 ) << 8 )
| F_3 ( V_60 ) ;
F_50 ( L_13 ,
V_28 , * V_10 , V_53 ) ;
F_7 () ;
return 0 ;
}
static int T_6 F_51 ( void )
{
unsigned short V_47 ;
int V_61 ;
V_61 = F_49 ( & V_47 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_52 ( & V_39 ) ;
if ( V_61 )
goto exit;
V_61 = F_42 ( V_47 ) ;
if ( V_61 )
goto V_62;
return 0 ;
V_62:
F_53 ( & V_39 ) ;
exit:
return V_61 ;
}
static void T_7 F_54 ( void )
{
F_55 ( V_30 ) ;
F_53 ( & V_39 ) ;
}
