static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
unsigned int V_5 , V_6 = 0 ;
for ( V_4 = 0 ; V_4 < 32 ; ++ V_4 ) {
V_5 = V_7 [ V_4 ] ;
if ( V_5 != 0 ) {
F_2 ( V_2 , L_1 , V_4 , V_5 ) ;
V_6 += V_5 ;
}
}
F_2 ( V_2 , L_2 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
return F_4 ( V_9 , F_1 , NULL ) ;
}
static int F_5 ( struct V_1 * V_2 , void * V_3 )
{
unsigned char V_10 = 0 ;
unsigned char V_11 = 0 ;
unsigned char V_12 = 0xF ;
T_1 V_13 = 0xFF00AA00 ;
struct V_14 * V_15 = ( void * ) V_16 ;
unsigned long V_17 ;
int V_18 ;
F_6 ( V_2 , L_3 ) ;
if ( V_19 == 0 ) {
F_7 () ;
V_19 = ~ 0 ;
}
F_6 ( V_2 , L_4 ) ;
V_15 -> V_20 = ~ ( V_21 | V_22 ) ;
V_15 -> V_23 = V_24 |
( V_11 << V_25 ) |
( V_12 << V_26 ) |
( V_10 & 0xFC ) ;
V_17 = F_8 ( V_13 ) ;
* V_27 = V_17 ;
V_18 = V_15 -> V_20 ;
F_6 ( V_2 , L_5 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
return F_4 ( V_9 , F_5 , NULL ) ;
}
static void F_7 ( void )
{
F_10 ( L_6 , 0 , NULL , & V_28 ) ;
F_10 ( L_7 , 0 , NULL , & V_29 ) ;
}
static T_2 F_11 ( int V_30 , void * V_31 )
{
struct V_14 * V_15 = ( void * ) V_16 ;
unsigned int V_32 = V_15 -> V_20 ;
#if F_12 ( V_33 ) && F_12 ( V_34 )
int V_4 ;
for ( V_4 = 0 ; V_4 < 32 ; ++ V_4 ) {
if ( ( 1 << V_4 ) & V_32 )
++ V_7 [ V_4 ] ;
}
#endif
V_15 -> V_20 = V_32 ;
return V_35 ;
}
int F_13 ( unsigned char V_36 ,
struct V_37 * V_38 ,
unsigned int V_39 ,
unsigned char V_10 ,
T_1 * V_40 )
{
struct V_14 * V_15 = ( void * ) V_16 ;
unsigned char V_11 = V_38 -> V_41 ;
unsigned char V_12 = ( unsigned char ) V_39 ;
unsigned long V_42 ;
unsigned long V_18 ;
unsigned long V_17 ;
static char V_43 ;
int V_44 ;
#if F_12 ( V_45 ) || F_12 ( V_46 )
unsigned int V_47 ;
#endif
#if F_12 ( V_33 ) && F_12 ( V_34 )
if ( V_19 == 0 ) {
F_7 () ;
V_19 = ~ 0 ;
}
#endif
if ( V_43 == 0 ) {
V_44 = F_14 ( V_48 ,
F_11 ,
V_49 ,
L_8 ,
V_15 ) ;
if ( V_44 != 0 )
return V_44 ;
V_43 = ~ 0 ;
}
#if F_12 ( V_45 ) || F_12 ( V_46 )
F_15 ( V_42 ) ;
V_47 = F_16 () ;
#else
F_17 ( & V_50 , V_42 ) ;
#endif
V_15 -> V_20 = ~ ( V_21 | V_22 ) ;
V_15 -> V_23 = V_24 |
( V_11 << V_25 ) |
( V_12 << V_26 ) |
( V_10 & 0xFC ) ;
if ( V_36 == V_51 ) {
V_17 = F_8 ( * V_40 ) ;
* V_27 = V_17 ;
} else {
V_17 = F_18 ( * V_27 ) ;
* V_40 = V_17 ;
}
V_18 = V_15 -> V_20 ;
V_15 -> V_23 = 0 ;
if ( V_18 & ~ ( V_21 | V_22 ) ) {
V_15 -> V_20 = ~ ( V_21 | V_22 ) ;
#if F_12 ( V_45 ) || F_12 ( V_46 )
F_19 ( V_47 ) ;
F_20 ( V_42 ) ;
#else
F_21 ( & V_50 , V_42 ) ;
#endif
return - 1 ;
}
#if F_12 ( V_45 ) || F_12 ( V_46 )
F_19 ( V_47 ) ;
F_20 ( V_42 ) ;
#else
F_21 ( & V_50 , V_42 ) ;
#endif
return V_52 ;
}
static int
F_22 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
T_1 * V_53 )
{
T_1 V_40 = 0 ;
if ( F_13 ( V_54 , V_38 , V_39 ,
V_10 , & V_40 ) ) {
* V_53 = 0xFFFFFFFF ;
return - 1 ;
}
* V_53 = ( V_40 >> ( ( V_10 & 3 ) << 3 ) ) & 0x0ff ;
return V_52 ;
}
static int
F_23 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
T_1 * V_53 )
{
T_1 V_40 = 0 ;
if ( ( V_10 & 3 ) == 3 ) {
* V_53 = 0xFFFFFFFF ;
return V_55 ;
}
if ( F_13 ( V_54 , V_38 , V_39 ,
V_10 , & V_40 ) ) {
* V_53 = 0xFFFFFFFF ;
return - 1 ;
}
* V_53 = ( V_40 >> ( ( V_10 & 3 ) << 3 ) ) & 0x0ffff ;
return V_52 ;
}
static int
F_24 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
T_1 * V_53 )
{
T_1 V_40 = 0 ;
if ( V_10 & 3 ) {
* V_53 = 0xFFFFFFFF ;
return V_55 ;
}
if ( F_13 ( V_54 , V_38 , V_39 ,
V_10 , & V_40 ) ) {
* V_53 = 0xFFFFFFFF ;
return - 1 ;
}
* V_53 = V_40 ;
return V_52 ;
}
static int
F_25 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
T_3 V_53 )
{
T_1 V_40 = 0 ;
if ( F_13 ( V_54 , V_38 , V_39 ,
V_10 , & V_40 ) )
return - 1 ;
V_40 = ( V_40 & ~ ( 0xff << ( ( V_10 & 3 ) << 3 ) ) ) |
( V_53 << ( ( V_10 & 3 ) << 3 ) ) ;
if ( F_13 ( V_51 , V_38 , V_39 ,
V_10 , & V_40 ) )
return - 1 ;
return V_52 ;
}
static int
F_26 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
T_4 V_53 )
{
T_1 V_40 = 0 ;
if ( ( V_10 & 3 ) == 3 )
return V_55 ;
if ( F_13 ( V_54 , V_38 , V_39 ,
V_10 , & V_40 ) )
return - 1 ;
V_40 = ( V_40 & ~ ( 0xffff << ( ( V_10 & 3 ) << 3 ) ) ) |
( V_53 << ( ( V_10 & 3 ) << 3 ) ) ;
if ( F_13 ( V_51 , V_38 , V_39 ,
V_10 , & V_40 ) )
return - 1 ;
return V_52 ;
}
static int
F_27 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
T_1 V_53 )
{
if ( V_10 & 3 )
return V_55 ;
if ( F_13 ( V_51 , V_38 , V_39 ,
V_10 , & V_53 ) )
return - 1 ;
return V_52 ;
}
int
F_28 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
int V_56 ,
T_1 * V_53 )
{
if ( V_56 == 1 ) {
if ( F_22 ( V_38 , V_39 , V_10 , V_53 ) ) {
return - 1 ;
}
} else if ( V_56 == 2 ) {
if ( F_23 ( V_38 , V_39 , V_10 , V_53 ) ) {
return - 1 ;
}
} else if ( V_56 == 4 ) {
if ( F_24 ( V_38 , V_39 , V_10 , V_53 ) ) {
return - 1 ;
}
} else {
* V_53 = 0xFFFFFFFF ;
return - 1 ;
}
return V_52 ;
}
int
F_29 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_10 ,
int V_56 ,
T_1 V_53 )
{
if ( V_56 == 1 ) {
if ( F_25 ( V_38 , V_39 ,
V_10 , ( T_3 ) ( 0xFF & V_53 ) ) ) {
return - 1 ;
}
} else if ( V_56 == 2 ) {
if ( F_26 ( V_38 , V_39 ,
V_10 , ( T_4 ) ( 0xFFFF & V_53 ) ) ) {
return - 1 ;
}
} else if ( V_56 == 4 ) {
if ( F_27 ( V_38 , V_39 , V_10 , V_53 ) ) {
return - 1 ;
}
} else {
return - 1 ;
}
return V_52 ;
}
void T_5 F_30 ( void )
{
struct V_14 * V_15 = ( void * ) V_16 ;
T_1 V_57 ;
V_57 = F_31 ( V_58 , 0xFFFF ) >> 12 ;
if ( ! F_32 ( V_57 ) ) {
F_33 ( V_59 L_9 , V_57 ) ;
goto V_60;
}
* ( unsigned long * ) V_61 = 3 ;
V_15 -> V_20 = ~ 0 ;
V_15 -> V_23 = 0 ;
V_15 -> V_62 = V_63 ;
V_15 -> V_64 = 0xF8BF87C0 ;
F_34 ( V_65 ) ;
F_35 ( & V_66 ) ;
return;
V_60:
F_33 ( V_59 L_10 ) ;
}
