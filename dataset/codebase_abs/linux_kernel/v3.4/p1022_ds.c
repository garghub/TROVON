static T_1 F_1 ( enum V_1 V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case 32 :
return F_2 ( 3 , 2 , 0 , 1 , 3 , 8 , 8 , 8 , 8 ) ;
case 24 :
return F_2 ( 4 , 0 , 1 , 2 , 2 , 0 , 8 , 8 , 8 ) ;
case 16 :
return F_2 ( 4 , 2 , 1 , 0 , 1 , 5 , 6 , 5 , 0 ) ;
default:
F_3 ( L_1 , V_3 ) ;
return 0 ;
}
}
static void F_4 ( enum V_1 V_2 ,
char * V_4 )
{
}
static void F_5 ( enum V_1 V_2 )
{
struct V_5 * V_6 ;
struct V_5 * V_7 = NULL ;
struct V_8 T_2 * V_9 ;
T_3 T_2 * V_10 = NULL ;
T_3 T_2 * V_11 = NULL ;
T_3 V_12 ;
V_6 = F_6 ( NULL , NULL , L_2 ) ;
if ( ! V_6 ) {
F_3 ( L_3 ) ;
return;
}
V_9 = F_7 ( V_6 , 0 ) ;
if ( ! V_9 ) {
F_3 ( L_4 ) ;
goto exit;
}
V_7 = F_6 ( NULL , NULL ,
L_5 ) ;
if ( ! V_7 ) {
F_3 ( L_6 ) ;
goto exit;
}
V_10 = F_7 ( V_7 , 0 ) ;
if ( ! V_10 ) {
F_3 ( L_7 ) ;
goto exit;
}
V_11 = F_7 ( V_7 , 1 ) ;
if ( ! V_11 ) {
F_3 ( L_8 ) ;
goto exit;
}
if ( ( F_8 ( & V_9 -> V_13 ) & V_14 ) !=
V_15 ) {
struct V_5 * V_16 ;
void T_2 * V_17 ;
V_16 =
F_6 ( NULL , NULL , L_9 ) ;
if ( ! V_16 ) {
F_3 ( L_10 ) ;
goto exit;
}
V_17 = F_7 ( V_16 , 0 ) ;
F_9 ( V_16 ) ;
if ( ! V_17 ) {
F_3 ( L_11 ) ;
goto exit;
}
F_10 ( V_17 + V_18 , V_19 ) ;
F_11 ( V_17 ) ;
F_12 ( V_10 , V_20 ) ;
V_12 = F_13 ( V_11 ) ;
V_12 |= V_21 ;
F_12 ( V_11 , V_12 ) ;
F_14 ( & V_9 -> V_13 , V_14 ,
V_15 ) ;
F_8 ( & V_9 -> V_13 ) ;
}
switch ( V_2 ) {
case V_22 :
F_12 ( V_10 , V_23 ) ;
V_12 = F_13 ( V_11 ) ;
V_12 &= ~ ( V_24 | V_25 ) ;
V_12 |= V_26 ;
F_12 ( V_11 , V_12 ) ;
break;
case V_27 :
F_12 ( V_10 , V_23 ) ;
V_12 = F_13 ( V_11 ) ;
V_12 &= ~ V_26 ;
V_12 |= V_24 | V_25 ;
F_12 ( V_11 , V_12 ) ;
break;
default:
F_3 ( L_12 , V_2 ) ;
}
exit:
if ( V_11 )
F_11 ( V_11 ) ;
if ( V_10 )
F_11 ( V_10 ) ;
if ( V_9 )
F_11 ( V_9 ) ;
F_9 ( V_7 ) ;
F_9 ( V_6 ) ;
}
void F_15 ( unsigned int V_28 )
{
struct V_5 * V_29 = NULL ;
struct V_8 T_2 * V_9 ;
unsigned long V_30 ;
T_4 V_31 ;
T_1 V_32 ;
V_29 = F_6 ( NULL , NULL , L_2 ) ;
if ( ! V_29 ) {
F_3 ( L_3 ) ;
return;
}
V_9 = F_7 ( V_29 , 0 ) ;
F_9 ( V_29 ) ;
if ( ! V_9 ) {
F_3 ( L_4 ) ;
return;
}
V_31 = 1000000000000ULL ;
F_16 ( V_31 , V_28 ) ;
V_30 = V_31 ;
V_32 = F_17 ( F_18 () , V_30 ) ;
V_32 = F_19 ( T_1 , V_32 , 2 , 255 ) ;
F_20 ( & V_9 -> V_33 ,
V_34 | V_35 | V_36 ) ;
F_21 ( & V_9 -> V_33 , V_34 | ( V_32 << 16 ) ) ;
F_11 ( V_9 ) ;
}
enum V_1
F_22 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_22 :
case V_27 :
return V_2 ;
default:
return V_22 ;
}
}
void T_5 F_23 ( void )
{
struct V_37 * V_37 = F_24 ( NULL , 0 , V_38 |
V_39 ,
0 , 256 , L_13 ) ;
F_25 ( V_37 == NULL ) ;
F_26 ( V_37 ) ;
}
static void T_5 F_27 ( struct V_5 * V_40 , struct V_41 * V_42 )
{
struct V_41 * V_43 ;
V_43 = F_28 ( V_40 , V_42 -> V_44 , NULL ) ;
if ( V_43 )
F_29 ( V_40 , V_42 , V_43 ) ;
else
F_30 ( V_40 , V_42 ) ;
}
static int T_5 F_31 ( char * V_45 )
{
V_46 = ( strncmp ( V_45 , L_14 , 6 ) == 0 ) ;
return 0 ;
}
static void T_5 F_32 ( void )
{
#ifdef F_33
struct V_5 * V_40 ;
#endif
T_6 V_47 = 0xffffffff ;
if ( V_48 . V_49 )
V_48 . V_49 ( L_15 , 0 ) ;
#ifdef F_33
F_34 (np, L_16 , L_17 ) {
struct V_50 V_51 ;
struct V_52 * V_53 ;
F_35 ( V_40 , 0 , & V_51 ) ;
if ( ( V_51 . V_54 & 0xfffff ) == 0x8000 )
F_36 ( V_40 , 1 ) ;
else
F_36 ( V_40 , 0 ) ;
V_53 = F_37 ( V_40 ) ;
V_47 = F_38 ( V_47 , V_53 -> V_55 +
V_53 -> V_56 ) ;
}
#endif
#if F_39 ( V_57 ) || F_39 ( V_58 )
V_59 . V_60 = F_1 ;
V_59 . V_61 = F_4 ;
V_59 . V_62 = F_5 ;
V_59 . V_63 = F_15 ;
V_59 . V_64 = F_22 ;
if ( V_46 ) {
struct V_5 * V_40 =
F_6 ( NULL , NULL , L_18 ) ;
if ( V_40 ) {
V_40 = F_6 ( V_40 , NULL , L_19 ) ;
if ( V_40 ) {
static struct V_41 V_65 = {
. V_44 = L_20 ,
. V_66 = L_21 ,
. V_67 = sizeof( L_21 ) ,
} ;
F_40 ( L_22 ,
V_40 -> V_68 ) ;
F_27 ( V_40 , & V_65 ) ;
F_9 ( V_40 ) ;
}
}
}
#endif
F_41 () ;
#ifdef F_42
if ( F_43 () > V_47 ) {
V_69 = 1 ;
F_44 ( & V_70 ) ;
V_48 . V_71 = V_72 ;
}
#endif
F_40 ( L_23 ) ;
}
static int T_5 F_45 ( void )
{
unsigned long V_73 = F_46 () ;
return F_47 ( V_73 , L_24 ) ;
}
