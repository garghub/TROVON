T_1 * T_2 F_1 ( int V_1 )
{
int V_2 ;
T_3 V_3 ;
for ( V_2 = 0 ; V_4 [ V_2 ] != 0 ; V_2 ++ ) {
V_5 = ( T_1 * ) V_4 [ V_2 ] ;
F_2 ( TRUE ) ;
V_3 . V_6 = F_3 ( V_7 ) ;
F_2 ( FALSE ) ;
if ( V_3 . V_8 . V_9 == V_10 ) {
V_11 = V_12 [ V_1 ] ;
V_13 = V_14 ;
F_2 ( TRUE ) ;
F_4 ( ) ;
F_2 ( FALSE ) ;
break;
}
else {
V_5 = NULL ;
}
}
return V_5 ;
}
unsigned int T_2 F_5 ( unsigned int V_15 )
{
unsigned int V_16 = FALSE ;
F_2 ( TRUE ) ;
switch ( V_15 ) {
case V_17 :
{
T_4 V_18 ;
T_5 V_19 ;
V_19 . V_6 =
F_3 ( V_20 ) ;
V_19 . V_8 . V_21 =
F_6 (
F_7 ( V_22 [ V_15 ] . V_19 )
) ;
F_8 ( V_20 , V_19 . V_6 ) ;
V_18 . V_6 = 0 ;
V_18 . V_8 . V_23 = V_22 [ V_15 ] . V_24 >> 3 ;
F_8 (
V_25 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_26 :
{
T_4 V_18 ;
T_5 V_19 ;
V_19 . V_6 =
F_3 ( V_20 ) ;
V_19 . V_8 . V_27 =
F_6 (
F_7 ( V_22 [ V_15 ] . V_19 )
) ;
F_8 ( V_20 , V_19 . V_6 ) ;
V_18 . V_6 = 0 ;
V_18 . V_8 . V_23 = V_22 [ V_15 ] . V_24 >> 3 ;
F_8 (
V_28 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_29 :
{
T_6 V_18 ;
T_7 V_19 ;
T_8 V_30 ;
V_30 . V_6 =
F_3 ( V_31 ) ;
V_30 . V_8 . V_32 =
F_9 (
F_10 ( V_22 [ V_15 ] . V_30 )
) ;
F_8 (
V_31 ,
V_30 . V_6
) ;
V_19 . V_6 =
F_3 ( V_33 ) ;
V_19 . V_8 . V_34 =
F_6 (
F_7 ( V_22 [ V_15 ] . V_19 )
) ;
F_8 (
V_33 ,
V_19 . V_6
) ;
V_18 . V_6 = 0 ;
V_18 . V_8 . V_35 = V_22 [ V_15 ] . V_24 >> 2 ;
F_8 (
V_36 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_37 :
{
T_9 V_18 ;
T_7 V_19 ;
T_8 V_30 ;
V_30 . V_6 =
F_3 ( V_31 ) ;
V_30 . V_8 . V_38 =
F_9 (
F_10 ( V_22 [ V_15 ] . V_30 )
) ;
F_8 (
V_31 ,
V_30 . V_6
) ;
V_19 . V_6 =
F_3 ( V_33 ) ;
V_19 . V_8 . V_39 =
F_6 (
F_7 ( V_22 [ V_15 ] . V_19 )
) ;
F_8 (
V_33 ,
V_19 . V_6
) ;
V_18 . V_6 = 0 ;
V_18 . V_8 . V_40 = V_22 [ V_15 ] . V_24 >> 4 ;
F_8 (
V_41 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_42 :
{
T_10 V_43 ;
V_43 . V_6 = 0 ;
V_43 . V_8 . V_40 = V_22 [ V_15 ] . V_44 >> 4 ;
F_8 (
V_45 ,
V_43 . V_6
) ;
V_43 . V_6 = 0 ;
V_43 . V_8 . V_40 = V_22 [ V_15 ] . V_24 >> 4 ;
F_8 (
V_46 ,
V_43 . V_6
) ;
V_16 = TRUE ;
break;
}
}
F_2 ( FALSE ) ;
return V_16 ;
}
unsigned int T_2 F_11 ( unsigned int V_15 )
{
unsigned int V_16 = FALSE ;
F_2 ( TRUE ) ;
switch ( V_15 ) {
case V_17 :
{
T_4 V_18 ;
T_5 V_19 ;
V_19 . V_6 =
F_3 ( V_20 ) ;
V_19 . V_8 . V_21 = 0 ;
F_8 ( V_20 , V_19 . V_6 ) ;
V_18 . V_6 = 0 ;
F_8 (
V_25 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_26 :
{
T_4 V_18 ;
T_5 V_19 ;
V_19 . V_6 =
F_3 ( V_20 ) ;
V_19 . V_8 . V_27 = 0 ;
F_8 ( V_20 , V_19 . V_6 ) ;
V_18 . V_6 = 0 ;
F_8 (
V_28 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_29 :
{
T_6 V_18 ;
T_7 V_19 ;
T_8 V_30 ;
V_30 . V_6 =
F_3 ( V_31 ) ;
V_30 . V_8 . V_32 = 0 ;
F_8 (
V_31 ,
V_30 . V_6
) ;
V_19 . V_6 =
F_3 ( V_33 ) ;
V_19 . V_8 . V_34 = 0 ;
F_8 (
V_33 ,
V_19 . V_6
) ;
V_18 . V_6 = 0 ;
F_8 (
V_36 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_37 :
{
T_9 V_18 ;
T_7 V_19 ;
T_8 V_30 ;
V_30 . V_6 =
F_3 ( V_31 ) ;
V_30 . V_8 . V_38 = 0 ;
F_8 (
V_31 ,
V_30 . V_6
) ;
V_19 . V_6 =
F_3 ( V_33 ) ;
V_19 . V_8 . V_39 = 0 ;
F_8 (
V_33 ,
V_19 . V_6
) ;
V_18 . V_6 = 0 ;
F_8 (
V_41 ,
V_18 . V_6
) ;
V_16 = TRUE ;
break;
}
case V_42 :
{
T_10 V_43 ;
V_43 . V_6 = 0 ;
F_8 (
V_45 ,
V_43 . V_6
) ;
V_43 . V_6 = 0 ;
F_8 (
V_46 ,
V_43 . V_6
) ;
V_16 = TRUE ;
break;
}
}
F_2 ( FALSE ) ;
return V_16 ;
}
unsigned int T_2 F_12 (
unsigned int V_15 ,
int V_47 ,
int V_19 ,
int V_30 )
{
struct V_48 * V_49 ;
if ( ( V_49 = F_13 ( V_15 ) ) != NULL ) {
if ( ( V_30 & ~ 0xFF ) == 0 ) {
V_49 -> V_30 = V_30 ;
}
if ( ( V_19 & ~ 0xFF ) == 0 ) {
V_49 -> V_19 = V_19 ;
}
if ( ( V_47 & ~ 0xFFFF ) == 0 ) {
V_49 -> V_24 = V_47 ;
}
if ( F_14 ( V_15 ) ) {
F_5 ( V_15 ) ;
}
return TRUE ;
}
return FALSE ;
}
static unsigned int T_2 F_14 ( unsigned int V_15 )
{
unsigned char V_18 = 0 ;
unsigned int V_50 = FALSE ;
unsigned int V_16 = FALSE ;
F_2 ( TRUE ) ;
switch ( V_15 ) {
case V_17 :
V_18 =
F_3 ( V_25 ) ;
V_50 = TRUE ;
break;
case V_26 :
V_18 =
F_3 ( V_28 ) ;
V_50 = TRUE ;
break;
case V_29 :
V_18 =
F_3 ( V_36 ) ;
V_50 = TRUE ;
break;
case V_37 :
V_18 =
F_3 ( V_41 ) ;
V_50 = TRUE ;
break;
case V_42 :
V_18 =
F_3 ( V_46 ) ;
V_50 = TRUE ;
break;
}
if ( ( V_50 ) && ( ( V_18 & 0xC0 ) != 0 ) ) {
V_16 = TRUE ;
}
F_2 ( FALSE ) ;
return V_16 ;
}
void T_2 F_15 ( void )
{
if ( F_14 ( V_17 ) ) {
F_16 ( L_1 ,
V_22 [ V_17 ] . V_24 ,
V_22 [ V_17 ] . V_19
) ;
}
else {
F_16 ( L_2 ) ;
}
if ( F_14 ( V_26 ) ) {
F_16 ( L_3 ,
V_22 [ V_26 ] . V_24 ,
V_22 [ V_26 ] . V_19
) ;
}
else {
F_16 ( L_4 ) ;
}
if ( F_14 ( V_29 ) ) {
F_16 ( L_5 ,
V_22 [ V_29 ] . V_24 ,
V_22 [ V_29 ] . V_19 ,
V_22 [ V_29 ] . V_30
) ;
}
else {
F_16 ( L_6 ) ;
}
if ( F_14 ( V_37 ) ) {
F_16 ( L_7 ,
V_22 [ V_37 ] . V_24 ,
V_22 [ V_37 ] . V_19 ,
V_22 [ V_37 ] . V_30
) ;
}
else {
F_16 ( L_8 ) ;
}
if ( F_14 ( V_42 ) ) {
F_16 ( L_9 ,
V_22 [ V_42 ] . V_24 ,
V_22 [ V_42 ] . V_19
) ;
}
else {
F_16 ( L_10 ) ;
}
}
static void T_2 F_2 (
unsigned int V_51 )
{
if ( V_51 ) {
F_17 ( & V_52 ) ;
F_18 ( & V_5 -> V_53 , V_54 ) ;
F_18 ( & V_5 -> V_53 , V_54 ) ;
F_19 ( & V_52 ) ;
}
else {
F_18 ( & V_5 -> V_53 , V_55 ) ;
}
}
static unsigned char T_2 F_3 (
unsigned char V_1 )
{
unsigned char V_56 ;
F_18 ( & V_5 -> V_53 , V_1 ) ;
V_56 = F_20 ( & V_5 -> V_57 ) ;
return V_56 ;
}
static void T_2 F_8 (
unsigned char V_1 ,
unsigned char V_56 )
{
F_18 ( & V_5 -> V_53 , V_1 ) ;
F_18 ( & V_5 -> V_57 , V_56 ) ;
}
static void T_2 F_4 ( void )
{
T_4 V_58 ;
T_5 V_59 ;
T_6 V_60 ;
T_7 V_61 ;
T_8 V_62 ;
T_9 V_63 ;
T_10 V_64 ;
T_10 V_65 ;
V_58 . V_6 =
F_3 ( V_25 ) ;
V_59 . V_6 =
F_3 ( V_20 ) ;
V_22 [ V_17 ] . V_24 = V_58 . V_8 . V_23 << 3 ;
V_22 [ V_17 ] . V_19 =
F_7 (
F_21 ( V_59 . V_8 . V_21 )
) ;
V_58 . V_6 =
F_3 ( V_28 ) ;
V_22 [ V_26 ] . V_24 = V_58 . V_8 . V_23 << 3 ;
V_22 [ V_26 ] . V_19 =
F_7 (
F_21 ( V_59 . V_8 . V_27 )
) ;
V_60 . V_6 =
F_3 ( V_36 ) ;
V_61 . V_6 =
F_3 ( V_33 ) ;
V_62 . V_6 =
F_3 ( V_31 ) ;
V_22 [ V_29 ] . V_24 = V_60 . V_8 . V_35 << 2 ;
V_22 [ V_29 ] . V_19 =
F_7 (
F_21 ( V_61 . V_8 . V_34 )
) ;
V_22 [ V_29 ] . V_30 =
F_10 (
F_22 ( V_62 . V_8 . V_32 )
) ;
V_63 . V_6 =
F_3 ( V_41 ) ;
V_22 [ V_37 ] . V_24 = V_63 . V_8 . V_40 << 4 ;
V_22 [ V_37 ] . V_19 =
F_7 (
F_21 ( V_61 . V_8 . V_39 )
) ;
V_22 [ V_37 ] . V_30 =
F_10 (
F_22 ( V_62 . V_8 . V_38 )
) ;
V_64 . V_6 =
F_3 ( V_46 ) ;
V_65 . V_6 =
F_3 ( V_45 ) ;
V_22 [ V_42 ] . V_24 = V_64 . V_8 . V_40 << 4 ;
V_22 [ V_42 ] . V_44 = V_65 . V_8 . V_40 << 4 ;
V_22 [ V_42 ] . V_19 = 14 ;
}
static struct V_48 * T_2 F_13 ( unsigned int V_15 )
{
struct V_48 * V_49 = NULL ;
switch ( V_15 ) {
case V_17 :
V_49 = & V_22 [ V_17 ] ;
break;
case V_26 :
V_49 = & V_22 [ V_26 ] ;
break;
case V_29 :
V_49 = & V_22 [ V_29 ] ;
break;
case V_37 :
V_49 = & V_22 [ V_37 ] ;
break;
case V_42 :
V_49 = & V_22 [ V_42 ] ;
break;
}
return V_49 ;
}
static int T_2 F_7 ( int V_19 )
{
int V_2 , V_66 = - 1 ;
if ( F_23 ( V_19 ) ) {
for ( V_2 = 0 ; ( V_11 [ V_2 ] . V_67 != - 1 ) || ( V_11 [ V_2 ] . V_68 != - 1 ) ; V_2 ++ ) {
if ( V_19 == V_11 [ V_2 ] . V_67 ) {
V_66 = V_11 [ V_2 ] . V_68 ;
break;
}
}
}
else {
for ( V_2 = 0 ; ( V_11 [ V_2 ] . V_68 != - 1 ) || ( V_11 [ V_2 ] . V_67 != - 1 ) ; V_2 ++ ) {
if ( V_19 == V_11 [ V_2 ] . V_68 ) {
V_66 = V_11 [ V_2 ] . V_67 ;
break;
}
}
}
return V_66 ;
}
static int T_2 F_10 ( int V_30 )
{
int V_2 , V_69 = - 1 ;
if ( F_24 ( V_30 ) ) {
for ( V_2 = 0 ; ( V_13 [ V_2 ] . V_70 != - 1 ) || ( V_13 [ V_2 ] . V_71 != - 1 ) ; V_2 ++ ) {
if ( V_30 == V_13 [ V_2 ] . V_70 ) {
V_69 = V_13 [ V_2 ] . V_71 ;
break;
}
}
}
else {
for ( V_2 = 0 ; ( V_13 [ V_2 ] . V_71 != - 1 ) || ( V_13 [ V_2 ] . V_70 != - 1 ) ; V_2 ++ ) {
if ( V_30 == V_13 [ V_2 ] . V_71 ) {
V_69 = V_13 [ V_2 ] . V_70 ;
break;
}
}
}
return V_69 ;
}
void T_2
F_25 ( void )
{
int V_2 ;
for ( V_2 = 0 ; V_2 <= 0x29 ; V_2 ++ )
F_16 ( L_11 , V_2 , F_3 ( V_2 ) ) ;
}
void T_2 F_26 ( int V_1 )
{
T_1 * V_72 ;
unsigned long V_73 ;
F_27 ( V_73 ) ;
if ( ( V_72 = F_1 ( V_1 ) ) != NULL ) {
#if V_74
F_2 ( TRUE ) ;
F_25 ( ) ;
F_2 ( FALSE ) ;
F_15 ( ) ;
#endif
F_11 ( V_17 ) ;
F_12 (
V_17 ,
V_75 ,
V_76 ,
- 1
) ;
F_5 ( V_17 ) ;
F_11 ( V_26 ) ;
F_12 (
V_26 ,
V_77 ,
V_78 ,
- 1
) ;
F_5 ( V_26 ) ;
F_11 ( V_29 ) ;
F_12 (
V_29 ,
V_79 ,
V_80 ,
V_81
) ;
F_5 ( V_29 ) ;
F_11 ( V_37 ) ;
F_12 (
V_37 ,
V_82 ,
V_83 ,
V_84
) ;
F_5 ( V_37 ) ;
F_28 ( 0xc , 0x3f2 ) ;
F_11 ( V_42 ) ;
#if V_74
F_2 ( TRUE ) ;
F_25 ( ) ;
F_2 ( FALSE ) ;
F_15 ( ) ;
#endif
F_29 ( V_73 ) ;
F_16 ( L_12 ,
V_72 ) ;
}
else {
F_29 ( V_73 ) ;
#if V_74
F_16 ( L_13 ) ;
#endif
}
}
