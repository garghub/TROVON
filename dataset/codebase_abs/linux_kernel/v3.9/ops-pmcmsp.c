static int F_1 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
int V_7 ;
int V_8 = 0 ;
unsigned int V_9 , V_10 = 0 ;
for ( V_7 = 0 ; V_7 < 32 ; ++ V_7 ) {
V_9 = V_11 [ V_7 ] ;
if ( V_9 != 0 ) {
V_8 += sprintf ( V_1 + V_8 , L_1 , V_7 , V_9 ) ;
V_10 += V_9 ;
}
}
V_8 += sprintf ( V_1 + V_8 , L_2 , V_10 ) ;
if ( V_8 <= V_3 + V_4 )
* V_5 = 1 ;
* V_2 = V_1 + V_3 ;
V_8 -= V_3 ;
if ( V_8 > V_4 )
V_8 = V_4 ;
if ( V_8 < 0 )
V_8 = 0 ;
return V_8 ;
}
static int F_2 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
unsigned char V_12 = 0 ;
unsigned char V_13 = 0 ;
unsigned char V_14 = 0xF ;
T_2 V_15 = 0xFF00AA00 ;
struct V_16 * V_17 = ( void * ) V_18 ;
int V_8 = 0 ;
unsigned long V_19 ;
int V_20 ;
V_8 += sprintf ( V_1 + V_8 , L_3 ) ;
if ( V_21 == 0 ) {
F_3 () ;
V_21 = ~ 0 ;
}
V_8 += sprintf ( V_1 + V_8 , L_4 ) ;
V_17 -> V_22 = ~ ( V_23 | V_24 ) ;
V_17 -> V_25 = V_26 |
( V_13 << V_27 ) |
( V_14 << V_28 ) |
( V_12 & 0xFC ) ;
V_19 = F_4 ( V_15 ) ;
* V_29 = V_19 ;
V_20 = V_17 -> V_22 ;
V_8 += sprintf ( V_1 + V_8 , L_5 ) ;
if ( V_8 <= V_3 + V_4 )
* V_5 = 1 ;
* V_2 = V_1 + V_3 ;
V_8 -= V_3 ;
if ( V_8 > V_4 )
V_8 = V_4 ;
if ( V_8 < 0 )
V_8 = 0 ;
return V_8 ;
}
static void F_3 ( void )
{
F_5 ( L_6 , 0 , NULL ,
F_1 , NULL ) ;
F_5 ( L_7 , 0 , NULL ,
F_2 , NULL ) ;
}
static T_3 F_6 ( int V_30 , void * V_31 )
{
struct V_16 * V_17 = ( void * ) V_18 ;
unsigned int V_32 = V_17 -> V_22 ;
#if F_7 ( V_33 ) && F_7 ( V_34 )
int V_7 ;
for ( V_7 = 0 ; V_7 < 32 ; ++ V_7 ) {
if ( ( 1 << V_7 ) & V_32 )
++ V_11 [ V_7 ] ;
}
#endif
V_17 -> V_22 = V_32 ;
return V_35 ;
}
int F_8 ( unsigned char V_36 ,
struct V_37 * V_38 ,
unsigned int V_39 ,
unsigned char V_12 ,
T_2 * V_6 )
{
struct V_16 * V_17 = ( void * ) V_18 ;
unsigned char V_13 = V_38 -> V_40 ;
unsigned char V_14 = ( unsigned char ) V_39 ;
unsigned long V_41 ;
unsigned long V_20 ;
unsigned long V_19 ;
static char V_42 ;
int V_43 ;
#if F_7 ( V_44 ) || F_7 ( V_45 )
unsigned int V_46 ;
#endif
#if F_7 ( V_33 ) && F_7 ( V_34 )
if ( V_21 == 0 ) {
F_3 () ;
V_21 = ~ 0 ;
}
#endif
if ( V_42 == 0 ) {
V_43 = F_9 ( V_47 ,
F_6 ,
V_48 ,
L_8 ,
V_17 ) ;
if ( V_43 != 0 )
return V_43 ;
V_42 = ~ 0 ;
}
#if F_7 ( V_44 ) || F_7 ( V_45 )
F_10 ( V_41 ) ;
V_46 = F_11 () ;
#else
F_12 ( & V_49 , V_41 ) ;
#endif
V_17 -> V_22 = ~ ( V_23 | V_24 ) ;
V_17 -> V_25 = V_26 |
( V_13 << V_27 ) |
( V_14 << V_28 ) |
( V_12 & 0xFC ) ;
if ( V_36 == V_50 ) {
V_19 = F_4 ( * V_6 ) ;
* V_29 = V_19 ;
} else {
V_19 = F_13 ( * V_29 ) ;
* V_6 = V_19 ;
}
V_20 = V_17 -> V_22 ;
V_17 -> V_25 = 0 ;
if ( V_20 & ~ ( V_23 | V_24 ) ) {
V_17 -> V_22 = ~ ( V_23 | V_24 ) ;
#if F_7 ( V_44 ) || F_7 ( V_45 )
F_14 ( V_46 ) ;
F_15 ( V_41 ) ;
#else
F_16 ( & V_49 , V_41 ) ;
#endif
return - 1 ;
}
#if F_7 ( V_44 ) || F_7 ( V_45 )
F_14 ( V_46 ) ;
F_15 ( V_41 ) ;
#else
F_16 ( & V_49 , V_41 ) ;
#endif
return V_51 ;
}
static int
F_17 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
T_2 * V_52 )
{
T_2 V_6 = 0 ;
if ( F_8 ( V_53 , V_38 , V_39 ,
V_12 , & V_6 ) ) {
* V_52 = 0xFFFFFFFF ;
return - 1 ;
}
* V_52 = ( V_6 >> ( ( V_12 & 3 ) << 3 ) ) & 0x0ff ;
return V_51 ;
}
static int
F_18 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
T_2 * V_52 )
{
T_2 V_6 = 0 ;
if ( ( V_12 & 3 ) == 3 ) {
* V_52 = 0xFFFFFFFF ;
return V_54 ;
}
if ( F_8 ( V_53 , V_38 , V_39 ,
V_12 , & V_6 ) ) {
* V_52 = 0xFFFFFFFF ;
return - 1 ;
}
* V_52 = ( V_6 >> ( ( V_12 & 3 ) << 3 ) ) & 0x0ffff ;
return V_51 ;
}
static int
F_19 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
T_2 * V_52 )
{
T_2 V_6 = 0 ;
if ( V_12 & 3 ) {
* V_52 = 0xFFFFFFFF ;
return V_54 ;
}
if ( F_8 ( V_53 , V_38 , V_39 ,
V_12 , & V_6 ) ) {
* V_52 = 0xFFFFFFFF ;
return - 1 ;
}
* V_52 = V_6 ;
return V_51 ;
}
static int
F_20 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
T_4 V_52 )
{
T_2 V_6 = 0 ;
if ( F_8 ( V_53 , V_38 , V_39 ,
V_12 , & V_6 ) )
return - 1 ;
V_6 = ( V_6 & ~ ( 0xff << ( ( V_12 & 3 ) << 3 ) ) ) |
( V_52 << ( ( V_12 & 3 ) << 3 ) ) ;
if ( F_8 ( V_50 , V_38 , V_39 ,
V_12 , & V_6 ) )
return - 1 ;
return V_51 ;
}
static int
F_21 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
T_5 V_52 )
{
T_2 V_6 = 0 ;
if ( ( V_12 & 3 ) == 3 )
return V_54 ;
if ( F_8 ( V_53 , V_38 , V_39 ,
V_12 , & V_6 ) )
return - 1 ;
V_6 = ( V_6 & ~ ( 0xffff << ( ( V_12 & 3 ) << 3 ) ) ) |
( V_52 << ( ( V_12 & 3 ) << 3 ) ) ;
if ( F_8 ( V_50 , V_38 , V_39 ,
V_12 , & V_6 ) )
return - 1 ;
return V_51 ;
}
static int
F_22 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
T_2 V_52 )
{
if ( V_12 & 3 )
return V_54 ;
if ( F_8 ( V_50 , V_38 , V_39 ,
V_12 , & V_52 ) )
return - 1 ;
return V_51 ;
}
int
F_23 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
int V_55 ,
T_2 * V_52 )
{
if ( V_55 == 1 ) {
if ( F_17 ( V_38 , V_39 , V_12 , V_52 ) ) {
return - 1 ;
}
} else if ( V_55 == 2 ) {
if ( F_18 ( V_38 , V_39 , V_12 , V_52 ) ) {
return - 1 ;
}
} else if ( V_55 == 4 ) {
if ( F_19 ( V_38 , V_39 , V_12 , V_52 ) ) {
return - 1 ;
}
} else {
* V_52 = 0xFFFFFFFF ;
return - 1 ;
}
return V_51 ;
}
int
F_24 ( struct V_37 * V_38 ,
unsigned int V_39 ,
int V_12 ,
int V_55 ,
T_2 V_52 )
{
if ( V_55 == 1 ) {
if ( F_20 ( V_38 , V_39 ,
V_12 , ( T_4 ) ( 0xFF & V_52 ) ) ) {
return - 1 ;
}
} else if ( V_55 == 2 ) {
if ( F_21 ( V_38 , V_39 ,
V_12 , ( T_5 ) ( 0xFFFF & V_52 ) ) ) {
return - 1 ;
}
} else if ( V_55 == 4 ) {
if ( F_22 ( V_38 , V_39 , V_12 , V_52 ) ) {
return - 1 ;
}
} else {
return - 1 ;
}
return V_51 ;
}
void T_6 F_25 ( void )
{
struct V_16 * V_17 = ( void * ) V_18 ;
T_2 V_56 ;
V_56 = F_26 ( V_57 , 0xFFFF ) >> 12 ;
if ( ! F_27 ( V_56 ) ) {
F_28 ( V_58 L_9 , V_56 ) ;
goto V_59;
}
* ( unsigned long * ) V_60 = 3 ;
V_17 -> V_22 = ~ 0 ;
V_17 -> V_25 = 0 ;
V_17 -> V_61 = V_62 ;
V_17 -> V_63 = 0xF8BF87C0 ;
F_29 ( V_64 ) ;
F_30 ( & V_65 ) ;
return;
V_59:
F_28 ( V_58 L_10 ) ;
}
