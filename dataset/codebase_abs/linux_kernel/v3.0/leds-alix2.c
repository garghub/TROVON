static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( V_4 )
F_3 ( V_6 -> V_8 , V_9 + V_6 -> V_10 ) ;
else
F_3 ( V_6 -> V_11 , V_9 + V_6 -> V_10 ) ;
}
static int T_1 F_4 ( struct V_12 * V_13 )
{
int V_14 ;
int V_15 ;
for ( V_14 = 0 ; V_14 < F_5 ( V_16 ) ; V_14 ++ ) {
V_16 [ V_14 ] . V_7 . V_17 |= V_18 ;
V_15 = F_6 ( & V_13 -> V_19 , & V_16 [ V_14 ] . V_7 ) ;
if ( V_15 < 0 )
goto V_20;
}
return 0 ;
V_20:
while ( -- V_14 >= 0 )
F_7 ( & V_16 [ V_14 ] . V_7 ) ;
return V_15 ;
}
static int F_8 ( struct V_12 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_5 ( V_16 ) ; V_14 ++ )
F_7 ( & V_16 [ V_14 ] . V_7 ) ;
return 0 ;
}
static int T_1 F_9 ( unsigned long V_21 ,
const char * V_22 ,
T_2 V_23 )
{
const T_2 V_24 = 0x00010000 ;
const char * V_25 ;
const char * V_26 ;
const char * V_27 ;
char V_28 [ 64 ] ;
if ( V_29 ) {
F_10 ( V_30 L_1
L_2 ,
V_31 ) ;
return 1 ;
}
V_25 = F_11 ( V_21 ) ;
V_26 = V_25 + V_24 - ( V_23 + 2 ) ;
for ( V_27 = V_25 ; V_27 < V_26 ; V_27 ++ ) {
const char * V_32 ;
char * V_33 ;
if ( memcmp ( V_27 , V_22 , V_23 ) != 0 )
continue;
memcpy ( V_28 , V_27 , sizeof( V_28 ) ) ;
V_33 = strchr ( V_28 , '\0' ) ;
if ( V_33 )
* V_33 = ' ' ;
V_33 = strchr ( V_28 , '\r' ) ;
if ( V_33 )
* V_33 = '\0' ;
V_32 = V_27 + V_23 ;
if ( ( V_32 [ 0 ] == '2' || V_32 [ 0 ] == '3' ) ) {
F_10 ( V_34
L_3 ,
V_31 , V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static int T_1 F_12 ( void )
{
T_3 V_35 , V_36 ;
if ( F_13 ( V_37 ) == 0 ) {
F_10 (KERN_WARNING KBUILD_MODNAMEL_4 ) ;
return - V_38 ;
}
F_14 ( V_39 , V_35 , V_36 ) ;
if ( V_36 != 0x0000f001 ) {
F_10 (KERN_WARNING KBUILD_MODNAMEL_5 ) ;
return - V_38 ;
}
V_9 = V_35 & 0x0000ff00 ;
if ( ! F_15 ( V_9 , V_40 , V_31 ) ) {
F_10 (KERN_ERR KBUILD_MODNAMEL_6 ) ;
return - V_38 ;
}
F_3 ( 1 << 6 , V_9 + 0x04 ) ;
F_3 ( 1 << 9 , V_9 + 0x84 ) ;
F_3 ( 1 << 11 , V_9 + 0x84 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
int V_15 = - V_38 ;
const char V_41 [] = L_7 ;
const char V_42 [] = L_8 ;
if ( F_9 ( 0xf0000 , V_41 , sizeof( V_41 ) - 1 ) ||
F_9 ( 0x500 , V_42 , sizeof( V_42 ) - 1 ) )
V_15 = F_12 () ;
if ( V_15 < 0 )
return V_15 ;
V_13 = F_17 ( V_31 , - 1 , NULL , 0 ) ;
if ( ! F_18 ( V_13 ) ) {
V_15 = F_19 ( & V_43 , F_4 ) ;
if ( V_15 )
F_20 ( V_13 ) ;
} else
V_15 = F_21 ( V_13 ) ;
return V_15 ;
}
static void T_4 F_22 ( void )
{
F_20 ( V_13 ) ;
F_23 ( & V_43 ) ;
F_24 ( V_9 , V_40 ) ;
}
