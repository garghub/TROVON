static unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( V_4 . V_5 , V_4 . V_6 [ V_1 ] ) ;
F_3 ( V_4 . V_5 , V_4 . V_6 [ V_1 ] , V_3 | V_2 ) ;
return V_3 ;
}
static void F_4 ( void )
{
unsigned long V_7 ;
V_7 = F_5 () ;
F_6 () ;
F_7 ( V_7 | V_8 | V_9 | V_10 | V_11 ) ;
F_8 () ;
F_7 ( V_7 ) ;
F_8 () ;
}
static void F_9 ( unsigned int V_2 )
{
unsigned int V_12 ;
V_12 = F_1 ( V_13 , V_2 ) ;
F_4 () ;
F_3 ( V_4 . V_5 , V_4 . V_6 [ V_13 ] , V_12 ) ;
}
static void F_10 ( void )
{
F_9 ( V_4 . V_14 ) ;
}
static void F_11 ( int V_15 )
{
int V_16 ;
if ( V_17 [ V_15 ] . V_18 )
return;
for ( V_16 = 0 ; V_16 < F_12 ( V_17 ) ; V_16 ++ )
V_17 [ V_16 ] . V_18 = 0 ;
V_17 [ V_15 ] . V_18 = 1 ;
}
static T_1 F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
char * V_24 = V_23 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_12 ( V_17 ) ; V_16 ++ ) {
if ( V_17 [ V_16 ] . V_18 )
V_24 += sprintf ( V_24 , L_1 , V_17 [ V_16 ] . V_25 ) ;
else
V_24 += sprintf ( V_24 , L_2 , V_17 [ V_16 ] . V_25 ) ;
}
* ( V_24 - 1 ) = '\n' ;
return V_24 - V_23 ;
}
static T_1 F_14 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_2 V_26 )
{
int V_16 ;
char * V_27 ;
int V_28 ;
V_27 = memchr ( V_23 , '\n' , V_26 ) ;
V_28 = V_27 ? V_27 - V_23 : V_26 ;
for ( V_16 = 0 ; V_16 < F_12 ( V_17 ) ; V_16 ++ ) {
if ( strncmp ( V_23 , V_17 [ V_16 ] . V_25 , V_28 ) == 0 ) {
F_11 ( V_16 ) ;
return V_26 ;
}
}
return - V_29 ;
}
static void F_15 ( void )
{
struct V_30 * V_31 ;
unsigned long V_32 ;
V_31 = F_16 ( 0 ) ;
V_32 = F_17 ( & V_31 -> V_20 ,
& V_33 . V_22 ) ;
if ( V_32 )
F_18 ( V_34
L_3 ) ;
}
static void F_19 ( void )
{
if ( V_17 [ V_35 ] . V_18 )
F_10 () ;
else
F_4 () ;
}
static int F_20 ( T_3 V_36 )
{
switch ( V_36 ) {
case V_37 :
return ! ! V_4 . V_38 ;
case V_39 :
return ! ! V_4 . V_40 ;
default:
return 0 ;
}
}
static void F_21 ( unsigned int V_2 )
{
unsigned long V_41 ;
V_41 = F_22 ( V_42 ) ;
F_23 ( V_42 , V_41 & ~ V_43 ) ;
F_9 ( V_2 ) ;
F_23 ( V_42 , V_41 ) ;
}
static int F_24 ( T_3 V_36 )
{
switch ( V_36 ) {
case V_37 :
F_21 ( V_4 . V_38 ) ;
break;
case V_39 :
F_21 ( V_4 . V_40 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_44 * V_45 ,
const char * V_25 )
{
int V_28 ;
const unsigned int * V_46 = F_26 ( V_45 , V_25 , & V_28 ) ;
if ( V_46 == NULL || V_28 < sizeof( V_47 ) )
return 0 ;
return * V_46 ;
}
static int T_4 F_27 ( void )
{
struct V_44 * V_45 ;
int V_48 , V_49 ;
int V_32 = 0 ;
if ( ! V_4 . V_50 ) {
F_11 ( V_51 ) ;
V_52 . V_53 = & F_19 ;
}
V_45 = F_28 ( NULL , NULL , L_4 ) ;
if ( ! V_45 ) {
V_32 = - V_29 ;
goto V_54;
}
V_48 = F_29 ( V_45 , 0 ) ;
V_49 = F_30 ( V_45 , 0 ) ;
if ( V_48 == 0 || V_49 == 0 ) {
F_18 ( V_55 L_5 ,
V_45 -> V_56 ) ;
V_32 = - V_29 ;
goto V_54;
}
V_4 . V_5 = F_31 ( V_45 , V_48 , V_49 ) ;
if ( ! F_32 ( V_4 . V_5 ) ) {
F_18 ( V_55 L_6 ,
V_45 -> V_56 ) ;
V_32 = - V_29 ;
goto V_54;
}
if ( F_25 ( V_45 , L_7 ) == 0 ) {
V_4 . V_6 [ V_13 ] = 0 ;
V_4 . V_6 [ V_57 ] = 1 ;
V_4 . V_6 [ V_58 ] = 2 ;
} else {
V_4 . V_6 [ V_13 ] = 1 ;
V_4 . V_6 [ V_57 ] = 2 ;
V_4 . V_6 [ V_58 ] = 0 ;
}
V_4 . V_59 = F_25 ( V_45 , L_8 ) ;
V_4 . V_14 = F_25 ( V_45 , L_9 ) ;
V_4 . V_38 = F_25 ( V_45 , L_10 ) ;
V_4 . V_40 = F_25 ( V_45 , L_11 ) ;
if ( V_4 . V_59 ) {
F_1 ( V_13 , V_4 . V_59 ) ;
F_1 ( V_57 , V_4 . V_59 ) ;
}
if ( ! V_4 . V_50 && V_4 . V_14 )
F_15 () ;
if ( V_4 . V_38 || V_4 . V_40 )
F_33 ( & V_60 ) ;
V_54:
if ( V_45 )
F_34 ( V_45 ) ;
return V_32 ;
}
static int T_4 F_35 ( char * V_61 )
{
V_4 . V_50 = 1 ;
return 0 ;
}
