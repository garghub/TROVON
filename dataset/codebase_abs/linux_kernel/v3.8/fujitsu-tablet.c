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
if ( V_1 . V_7 . V_8 & V_9 )
V_5 = ! V_5 ;
if ( ( V_1 . V_7 . V_8 & V_10 ) && ( ! V_5 ) ) {
V_6 = 1 ;
} else{
V_6 = V_4 & 0x01 ;
if ( V_1 . V_7 . V_8 & V_11 )
V_6 = ! V_6 ;
}
F_7 ( V_1 . V_12 , V_13 , V_5 ) ;
F_7 ( V_1 . V_12 , V_14 , V_6 ) ;
F_8 ( V_1 . V_12 ) ;
}
static void F_9 ( void )
{
int V_15 = 50 ;
F_1 () ;
while ( ( F_3 () & 0x02 ) && ( -- V_15 ) )
F_10 ( 20 ) ;
F_6 () ;
}
static int F_11 ( struct V_16 * V_17 , const char * V_18 ,
const char * V_19 )
{
struct V_20 * V_12 ;
int error ;
int V_21 ;
V_12 = F_12 () ;
if ( ! V_12 )
return - V_22 ;
V_12 -> V_23 . V_17 = V_17 ;
V_12 -> V_19 = V_19 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_24 . V_25 = V_26 ;
V_12 -> V_24 . V_27 = 0x1734 ;
V_12 -> V_24 . V_28 = 0x0001 ;
V_12 -> V_24 . V_29 = 0x0101 ;
V_12 -> V_30 = V_1 . V_7 . V_31 ;
V_12 -> V_32 = sizeof( V_1 . V_7 . V_31 [ 0 ] ) ;
V_12 -> V_33 = F_13 ( V_1 . V_7 . V_31 ) ;
F_14 ( V_34 , V_12 -> V_35 ) ;
for ( V_21 = 0 ; V_21 < F_13 ( V_1 . V_7 . V_31 ) ; V_21 ++ )
if ( V_1 . V_7 . V_31 [ V_21 ] )
F_15 ( V_12 , V_36 , V_1 . V_7 . V_31 [ V_21 ] ) ;
F_15 ( V_12 , V_37 , V_38 ) ;
F_15 ( V_12 , V_39 , V_13 ) ;
F_15 ( V_12 , V_39 , V_14 ) ;
error = F_16 ( V_12 ) ;
if ( error ) {
F_17 ( V_12 ) ;
return error ;
}
V_1 . V_12 = V_12 ;
return 0 ;
}
static void F_18 ( void )
{
F_19 ( V_1 . V_12 ) ;
}
static T_2 F_20 ( int V_40 , void * V_41 )
{
unsigned long V_42 , V_43 ;
unsigned int V_30 ;
int V_44 ;
int V_21 ;
if ( F_21 ( ! ( F_3 () & 0x01 ) ) )
return V_45 ;
F_6 () ;
V_42 = F_4 ( 0xde ) ;
V_42 |= F_4 ( 0xdf ) << 8 ;
V_42 ^= 0xffff ;
V_43 = V_42 ^ V_1 . V_46 ;
if ( V_43 ) {
V_1 . V_46 = V_42 ;
F_22 (i, &changed, KEYMAP_LEN) {
V_30 = V_1 . V_7 . V_31 [ V_21 ] ;
V_44 = V_42 & V_43 & F_23 ( V_21 ) ;
if ( V_44 )
F_24 ( V_1 . V_12 , V_37 , V_38 , V_21 ) ;
F_25 ( V_1 . V_12 , V_30 , V_44 ) ;
F_8 ( V_1 . V_12 ) ;
}
}
F_1 () ;
return V_47 ;
}
static void F_26 ( const struct V_48 * V_49 )
{
F_27 ( L_1 , V_49 -> V_50 ) ;
memcpy ( V_1 . V_7 . V_31 , V_49 -> V_51 ,
sizeof( V_1 . V_7 . V_31 ) ) ;
}
static int F_28 ( const struct V_48 * V_49 )
{
F_26 ( V_49 ) ;
V_1 . V_7 . V_8 |= V_11 ;
return 1 ;
}
static int F_29 ( const struct V_48 * V_49 )
{
F_26 ( V_49 ) ;
V_1 . V_7 . V_8 |= V_10 ;
V_1 . V_7 . V_8 |= V_9 ;
return 1 ;
}
static T_3 F_30 ( struct V_52 * V_53 , void * V_54 )
{
switch ( V_53 -> type ) {
case V_55 :
V_1 . V_40 = V_53 -> V_54 . V_40 . V_56 [ 0 ] ;
return V_57 ;
case V_58 :
V_1 . V_2 = V_53 -> V_54 . V_59 . V_60 ;
V_1 . V_61 = V_53 -> V_54 . V_59 . V_62 ;
return V_57 ;
case V_63 :
if ( V_1 . V_40 && V_1 . V_2 )
return V_57 ;
else
return V_64 ;
default:
return V_65 ;
}
}
static int F_31 ( struct V_66 * V_67 )
{
T_3 V_68 ;
int error ;
if ( ! V_67 )
return - V_69 ;
V_68 = F_32 ( V_67 -> V_70 , V_71 ,
F_30 , NULL ) ;
if ( F_33 ( V_68 ) || ! V_1 . V_40 || ! V_1 . V_2 )
return - V_72 ;
sprintf ( F_34 ( V_67 ) , L_2 , F_35 ( V_67 ) ) ;
sprintf ( F_36 ( V_67 ) , L_3 , V_73 ) ;
snprintf ( V_1 . V_19 , sizeof( V_1 . V_19 ) ,
L_4 , F_35 ( V_67 ) ) ;
error = F_11 ( & V_67 -> V_23 ,
F_34 ( V_67 ) , V_1 . V_19 ) ;
if ( error )
return error ;
if ( ! F_37 ( V_1 . V_2 , V_1 . V_61 , V_74 ) ) {
F_18 () ;
return - V_75 ;
}
F_9 () ;
error = F_38 ( V_1 . V_40 , F_20 ,
V_76 , V_74 , F_20 ) ;
if ( error ) {
F_39 ( V_1 . V_2 , V_1 . V_61 ) ;
F_18 () ;
return error ;
}
return 0 ;
}
static int F_40 ( struct V_66 * V_67 , int type )
{
F_41 ( V_1 . V_40 , F_20 ) ;
F_39 ( V_1 . V_2 , V_1 . V_61 ) ;
F_18 () ;
return 0 ;
}
static int F_42 ( struct V_16 * V_23 )
{
F_9 () ;
return 0 ;
}
static int T_4 F_43 ( void )
{
int error ;
F_44 ( V_77 ) ;
error = F_45 ( & V_78 ) ;
if ( error )
return error ;
return 0 ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_78 ) ;
}
