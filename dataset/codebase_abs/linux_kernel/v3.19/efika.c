static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_9 = ( V_4 & 0xff ) | ( ( V_3 & 0xff ) << 8 )
| ( ( ( V_2 -> V_10 - V_8 -> V_11 ) & 0xff ) << 16 )
| ( V_8 -> V_12 << 24 ) ;
int V_13 = - 1 ;
int V_14 ;
V_14 = F_3 ( F_4 ( L_1 ) , 2 , 2 , & V_13 , V_9 , V_5 ) ;
* V_6 = V_13 ;
return V_14 ? V_15 : V_16 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_9 = ( V_4 & 0xff ) | ( ( V_3 & 0xff ) << 8 )
| ( ( ( V_2 -> V_10 - V_8 -> V_11 ) & 0xff ) << 16 )
| ( V_8 -> V_12 << 24 ) ;
int V_14 ;
V_14 = F_3 ( F_4 ( L_2 ) , 3 , 1 , NULL ,
V_9 , V_5 , V_6 ) ;
return V_14 ? V_15 : V_16 ;
}
static void T_2 F_6 ( void )
{
const int * V_17 ;
int V_5 ;
struct V_7 * V_8 ;
struct V_18 * V_19 ;
struct V_18 * V_20 ;
V_19 = F_7 ( L_3 ) ;
if ( V_19 == NULL ) {
F_8 (KERN_WARNING EFIKA_PLATFORM_NAME
L_4 ) ;
return;
}
for ( V_20 = NULL ; ; ) {
V_20 = F_9 ( V_19 , V_20 ) ;
if ( ( V_20 == NULL ) || ( strcmp ( V_20 -> V_21 , L_5 ) == 0 ) )
break;
}
F_10 ( V_19 ) ;
if ( V_20 == NULL ) {
F_8 (KERN_WARNING EFIKA_PLATFORM_NAME
L_6 ) ;
return;
}
V_17 = F_11 ( V_20 , L_7 , & V_5 ) ;
if ( V_17 == NULL || V_5 < 2 * sizeof( int ) ) {
F_8 (KERN_WARNING EFIKA_PLATFORM_NAME
L_8 , pcictrl->full_name) ;
goto V_22;
}
if ( V_17 [ 1 ] == V_17 [ 0 ] )
F_8 (KERN_INFO EFIKA_PLATFORM_NAME L_9 ,
bus_range[0]) ;
else
F_8 (KERN_INFO EFIKA_PLATFORM_NAME L_10 ,
bus_range[0], bus_range[1]) ;
F_8 ( L_11 , V_20 -> V_23 ) ;
F_8 ( L_12 ) ;
V_8 = F_12 ( V_20 ) ;
if ( ! V_8 ) {
F_8 (KERN_WARNING EFIKA_PLATFORM_NAME
L_13 ,
pcictrl->full_name) ;
goto V_22;
}
V_8 -> V_11 = V_17 [ 0 ] ;
V_8 -> V_24 = V_17 [ 1 ] ;
V_8 -> V_25 = & V_26 ;
F_13 ( V_8 , V_20 , 0 ) ;
return;
V_22:
F_10 ( V_20 ) ;
}
static void T_2 F_6 ( void )
{}
static void F_14 ( struct V_27 * V_28 )
{
struct V_18 * V_19 ;
const char * V_29 ;
const char * V_30 ;
const char * V_31 ;
V_19 = F_7 ( L_3 ) ;
if ( ! V_19 )
return;
V_29 = F_11 ( V_19 , L_14 , NULL ) ;
V_30 = F_11 ( V_19 , L_15 , NULL ) ;
V_31 = F_11 ( V_19 , L_16 , NULL ) ;
if ( V_30 )
F_15 ( V_28 , L_17 , V_30 ) ;
else
F_15 ( V_28 , L_18 ) ;
if ( V_29 )
F_15 ( V_28 , L_19 , V_29 ) ;
if ( V_31 )
F_15 ( V_28 , L_20 , V_31 ) ;
F_10 ( V_19 ) ;
}
static void F_16 ( void T_3 * V_32 )
{
T_4 V_33 = 4 ;
T_4 V_34 = 1 ;
F_17 ( V_33 , V_34 ) ;
}
static void T_2 F_18 ( void )
{
F_19 () ;
F_20 () ;
F_6 () ;
#ifdef F_21
V_35 . V_36 = F_16 ;
F_22 () ;
#endif
if ( V_37 . V_38 )
V_37 . V_38 ( L_21 V_39 L_22 , 0x0 ) ;
}
static int T_2 F_23 ( void )
{
const char * V_40 = F_24 ( F_25 () ,
L_23 , NULL ) ;
if ( V_40 == NULL )
return 0 ;
if ( strcmp ( V_40 , L_24 ) )
return 0 ;
V_41 = ~ 0L ;
V_42 = 0x44 ;
V_43 = 0x48 ;
V_44 = V_45 ;
return 1 ;
}
