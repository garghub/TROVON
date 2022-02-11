static T_1 F_1 ( void )
{
return F_2 ( V_1 . V_2 + 2 ) ;
}
static T_1 F_3 ( void )
{
return F_2 ( V_1 . V_2 + 6 ) ;
}
static T_1 F_4 ( const T_1 V_3 )
{
F_5 ( V_3 , V_1 . V_2 ) ;
return F_2 ( V_1 . V_2 + 4 ) ;
}
static void F_6 ( void )
{
int V_4 ;
int V_5 , V_6 ;
V_4 = F_4 ( 0xdd ) ;
V_5 = V_4 & 0x02 ;
if ( ( V_1 . V_7 . V_8 & V_9 ) && ( ! V_5 ) ) {
V_6 = 1 ;
} else{
V_6 = V_4 & 0x01 ;
if ( V_1 . V_7 . V_8 & V_10 )
V_6 = ! V_6 ;
}
F_7 ( V_1 . V_11 , V_12 , V_5 ) ;
F_7 ( V_1 . V_11 , V_13 , V_6 ) ;
F_8 ( V_1 . V_11 ) ;
}
static void F_9 ( void )
{
int V_14 = 50 ;
F_1 () ;
while ( ( F_3 () & 0x02 ) && ( -- V_14 ) )
F_10 ( 20 ) ;
F_6 () ;
}
static int T_2 F_11 ( struct V_15 * V_16 ,
const char * V_17 , const char * V_18 )
{
struct V_19 * V_11 ;
int error ;
int V_20 ;
V_11 = F_12 () ;
if ( ! V_11 )
return - V_21 ;
V_11 -> V_22 . V_16 = V_16 ;
V_11 -> V_18 = V_18 ;
V_11 -> V_17 = V_17 ;
V_11 -> V_23 . V_24 = V_25 ;
V_11 -> V_23 . V_26 = 0x1734 ;
V_11 -> V_23 . V_27 = 0x0001 ;
V_11 -> V_23 . V_28 = 0x0101 ;
V_11 -> V_29 = V_1 . V_7 . V_30 ;
V_11 -> V_31 = sizeof( V_1 . V_7 . V_30 [ 0 ] ) ;
V_11 -> V_32 = F_13 ( V_1 . V_7 . V_30 ) ;
F_14 ( V_33 , V_11 -> V_34 ) ;
for ( V_20 = 0 ; V_20 < F_13 ( V_1 . V_7 . V_30 ) ; V_20 ++ )
if ( V_1 . V_7 . V_30 [ V_20 ] )
F_15 ( V_11 , V_35 , V_1 . V_7 . V_30 [ V_20 ] ) ;
F_15 ( V_11 , V_36 , V_37 ) ;
F_15 ( V_11 , V_38 , V_12 ) ;
F_15 ( V_11 , V_38 , V_13 ) ;
F_15 ( V_11 , V_38 , V_12 ) ;
F_15 ( V_11 , V_38 , V_13 ) ;
error = F_16 ( V_11 ) ;
if ( error ) {
F_17 ( V_11 ) ;
return error ;
}
V_1 . V_11 = V_11 ;
return 0 ;
}
static void F_18 ( void )
{
F_19 ( V_1 . V_11 ) ;
}
static T_3 F_20 ( int V_39 , void * V_40 )
{
unsigned long V_41 , V_42 ;
unsigned int V_29 ;
int V_43 ;
int V_20 ;
if ( F_21 ( ! ( F_3 () & 0x01 ) ) )
return V_44 ;
F_6 () ;
V_41 = F_4 ( 0xde ) ;
V_41 |= F_4 ( 0xdf ) << 8 ;
V_41 ^= 0xffff ;
V_42 = V_41 ^ V_1 . V_45 ;
if ( V_42 ) {
V_1 . V_45 = V_41 ;
F_22 (i, &changed, KEYMAP_LEN) {
V_29 = V_1 . V_7 . V_30 [ V_20 ] ;
V_43 = V_41 & V_42 & F_23 ( V_20 ) ;
if ( V_43 )
F_24 ( V_1 . V_11 , V_36 , V_37 , V_20 ) ;
F_25 ( V_1 . V_11 , V_29 , V_43 ) ;
F_8 ( V_1 . V_11 ) ;
}
}
F_1 () ;
return V_46 ;
}
static int T_2 F_26 ( const struct V_47 * V_48 )
{
F_27 (KERN_INFO MODULENAME L_1 , dmi->ident) ;
memcpy ( V_1 . V_7 . V_30 , V_48 -> V_49 ,
sizeof( V_1 . V_7 . V_30 ) ) ;
return 1 ;
}
static int T_2 F_28 ( const struct V_47 * V_48 )
{
F_26 ( V_48 ) ;
V_1 . V_7 . V_8 |= V_9 ;
V_1 . V_7 . V_8 |= V_10 ;
return 1 ;
}
static T_4 T_2
F_29 ( struct V_50 * V_51 , void * V_52 )
{
switch ( V_51 -> type ) {
case V_53 :
V_1 . V_39 = V_51 -> V_52 . V_39 . V_54 [ 0 ] ;
return V_55 ;
case V_56 :
V_1 . V_2 = V_51 -> V_52 . V_57 . V_58 ;
V_1 . V_59 = V_51 -> V_52 . V_57 . V_60 ;
return V_55 ;
case V_61 :
if ( V_1 . V_39 && V_1 . V_2 )
return V_55 ;
else
return V_62 ;
default:
return V_63 ;
}
}
static int T_2 F_30 ( struct V_64 * V_65 )
{
T_4 V_66 ;
int error ;
if ( ! V_65 )
return - V_67 ;
V_66 = F_31 ( V_65 -> V_68 , V_69 ,
F_29 , NULL ) ;
if ( F_32 ( V_66 ) || ! V_1 . V_39 || ! V_1 . V_2 )
return - V_70 ;
sprintf ( F_33 ( V_65 ) , L_2 , F_34 ( V_65 ) ) ;
sprintf ( F_35 ( V_65 ) , L_3 , V_71 ) ;
snprintf ( V_1 . V_18 , sizeof( V_1 . V_18 ) ,
L_4 , F_34 ( V_65 ) ) ;
error = F_11 ( & V_65 -> V_22 ,
F_33 ( V_65 ) , V_1 . V_18 ) ;
if ( error )
return error ;
if ( ! F_36 ( V_1 . V_2 , V_1 . V_59 , V_72 ) ) {
F_18 () ;
return - V_73 ;
}
F_9 () ;
error = F_37 ( V_1 . V_39 , F_20 ,
V_74 , V_72 , F_20 ) ;
if ( error ) {
F_38 ( V_1 . V_2 , V_1 . V_59 ) ;
F_18 () ;
return error ;
}
return 0 ;
}
static int T_5 F_39 ( struct V_64 * V_65 , int type )
{
F_40 ( V_1 . V_39 , F_20 ) ;
F_38 ( V_1 . V_2 , V_1 . V_59 ) ;
F_18 () ;
return 0 ;
}
static int F_41 ( struct V_64 * V_65 )
{
F_9 () ;
return 0 ;
}
static int T_6 F_42 ( void )
{
int error ;
F_43 ( V_75 ) ;
error = F_44 ( & V_76 ) ;
if ( error )
return error ;
return 0 ;
}
static void T_7 F_45 ( void )
{
F_46 ( & V_76 ) ;
}
