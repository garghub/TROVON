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
static int F_24 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = & V_29 -> V_12 ;
struct V_6 * V_7 ;
struct V_11 * V_30 ;
struct V_31 * V_8 ;
V_8 = F_25 ( V_29 , V_32 , 0 ) ;
if ( ! F_26 ( V_12 , V_8 -> V_33 , V_34 ,
V_35 . V_36 . V_37 ) ) {
F_27 ( V_12 , L_4 ,
( unsigned long ) V_8 -> V_33 ,
( unsigned long ) V_8 -> V_33 + V_34 - 1 ) ;
return - V_38 ;
}
V_7 = F_28 ( V_12 , sizeof( struct V_6 ) , V_39 ) ;
if ( ! V_7 )
return - V_40 ;
V_7 -> V_10 = V_8 -> V_33 ;
F_29 ( & V_7 -> V_9 ) ;
F_29 ( & V_7 -> V_14 ) ;
V_30 = F_30 ( V_12 , L_5 ,
V_7 ,
V_41 ) ;
return F_31 ( V_30 ) ;
}
static int T_4 F_32 ( unsigned short V_42 )
{
struct V_31 V_8 = {
. V_33 = V_42 ,
. V_43 = V_42 + V_34 - 1 ,
. V_37 = V_44 ,
. V_45 = V_32 ,
} ;
int V_46 ;
V_46 = F_33 ( & V_8 ) ;
if ( V_46 )
goto exit;
V_29 = F_34 ( V_44 , V_42 ) ;
if ( ! V_29 ) {
V_46 = - V_40 ;
F_35 ( L_6 ) ;
goto exit;
}
V_46 = F_36 ( V_29 , & V_8 , 1 ) ;
if ( V_46 ) {
F_35 ( L_7 , V_46 ) ;
goto V_47;
}
V_46 = F_37 ( V_29 ) ;
if ( V_46 ) {
F_35 ( L_8 , V_46 ) ;
goto V_47;
}
return 0 ;
V_47:
F_38 ( V_29 ) ;
exit:
return V_46 ;
}
static int T_4 F_39 ( void )
{
T_1 V_48 , V_49 ;
char * V_37 ;
unsigned short V_10 ;
F_6 () ;
V_48 = V_50 ? V_50 : F_3 ( V_51 ) ;
switch ( V_48 ) {
case 0x81 :
V_37 = L_9 ;
break;
case 0x6f :
V_37 = L_10 ;
break;
case 0x85 :
case 0x8c :
V_37 = L_11 ;
break;
default:
F_7 () ;
return - V_52 ;
}
V_49 = F_3 ( V_53 ) ;
F_5 ( V_54 ) ;
V_10 = ( F_3 ( V_55 ) << 8 )
| F_3 ( V_56 ) ;
F_40 ( L_12 ,
V_37 , V_10 , V_49 ) ;
F_7 () ;
return V_10 ;
}
static int T_4 F_41 ( void )
{
unsigned short V_42 ;
int V_57 ;
V_57 = F_39 () ;
if ( V_57 < 0 )
return V_57 ;
V_42 = V_57 ;
V_57 = F_42 ( & V_35 ) ;
if ( V_57 )
goto exit;
V_57 = F_32 ( V_42 ) ;
if ( V_57 )
goto V_58;
return 0 ;
V_58:
F_43 ( & V_35 ) ;
exit:
return V_57 ;
}
static void T_5 F_44 ( void )
{
F_45 ( V_29 ) ;
F_43 ( & V_35 ) ;
}
