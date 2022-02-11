static void
F_1 ( unsigned int V_1 , unsigned char V_2 )
{
F_2 ( 0x0001 , ( unsigned long ) V_3 ) ;
F_2 ( ( ( V_2 << 8 ) | ( V_1 & 0xff ) ) , ( unsigned long ) V_4 ) ;
F_2 ( 0x0002 , ( unsigned long ) V_5 ) ;
while( F_3 ( ( unsigned long ) V_5 ) ) ;
F_2 ( 0x0000 , ( unsigned long ) V_3 ) ;
}
static unsigned char
F_4 ( unsigned int V_1 )
{
unsigned char V_6 ;
F_2 ( 0x0001 , ( unsigned long ) V_3 ) ;
F_2 ( ( V_1 & 0xff ) , ( unsigned long ) V_7 ) ;
F_2 ( 0x0001 , ( unsigned long ) V_5 ) ;
while( F_3 ( ( unsigned long ) V_5 ) ) ;
V_6 = ( F_3 ( ( unsigned long ) V_7 ) & 0xff00 ) >> 8 ;
F_2 ( 0x0000 , ( unsigned long ) V_3 ) ;
return V_6 ;
}
static void
F_5 ( void )
{
F_1 ( 0x8e , 0x00 ) ;
}
static void
F_6 ( void )
{
F_1 ( 0x8e , 0x80 ) ;
}
unsigned char
F_7 ( int V_8 )
{
unsigned char V_2 ;
V_2 = F_4 ( ( 0x81 | ( V_8 << 1 ) ) ) ;
return V_2 ;
}
void
F_8 ( int V_8 , unsigned char V_9 )
{
F_5 () ;
F_1 ( ( 0x80 | ( V_8 << 1 ) ) , V_9 ) ;
F_6 () ;
}
void
F_9 ( struct V_10 * V_11 )
{
unsigned long V_12 ;
F_10 ( V_12 ) ;
V_11 -> V_13 = F_11 ( V_14 ) ;
V_11 -> V_15 = F_11 ( V_16 ) ;
V_11 -> V_17 = F_11 ( V_18 ) ;
V_11 -> V_19 = F_11 ( V_20 ) ;
V_11 -> V_21 = F_11 ( V_22 ) ;
V_11 -> V_23 = F_11 ( V_24 ) ;
F_12 ( V_12 ) ;
V_11 -> V_13 = F_13 ( V_11 -> V_13 ) ;
V_11 -> V_15 = F_13 ( V_11 -> V_15 ) ;
V_11 -> V_17 = F_13 ( V_11 -> V_17 ) ;
V_11 -> V_19 = F_13 ( V_11 -> V_19 ) ;
V_11 -> V_21 = F_13 ( V_11 -> V_21 ) ;
V_11 -> V_23 = F_13 ( V_11 -> V_23 ) ;
if ( V_11 -> V_23 <= 69 )
V_11 -> V_23 += 100 ;
V_11 -> V_21 -- ;
}
static long F_14 ( struct V_25 * V_25 , unsigned int V_26 , unsigned long V_27 )
{
unsigned long V_12 ;
switch( V_26 ) {
case V_28 :
{
struct V_10 V_11 ;
memset ( & V_11 , 0 , sizeof ( struct V_10 ) ) ;
F_15 ( & V_29 ) ;
F_9 ( & V_11 ) ;
F_16 ( & V_29 ) ;
if ( F_17 ( (struct V_10 * ) V_27 , & V_11 , sizeof( struct V_10 ) ) )
return - V_30 ;
return 0 ;
}
case V_31 :
{
struct V_10 V_11 ;
unsigned char V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
unsigned int V_38 ;
if ( ! F_18 ( V_39 ) )
return - V_40 ;
if ( F_19 ( & V_11 , (struct V_10 * ) V_27 , sizeof( struct V_10 ) ) )
return - V_30 ;
V_38 = V_11 . V_23 + 1900 ;
V_32 = V_11 . V_21 + 1 ;
V_33 = V_11 . V_19 ;
V_34 = V_11 . V_17 ;
V_35 = V_11 . V_15 ;
V_36 = V_11 . V_13 ;
if ( ( V_38 < 1970 ) || ( V_38 > 2069 ) )
return - V_41 ;
V_37 = ( ( ! ( V_38 % 4 ) && ( V_38 % 100 ) ) || ! ( V_38 % 400 ) ) ;
if ( ( V_32 > 12 ) || ( V_33 == 0 ) )
return - V_41 ;
if ( V_33 > ( V_42 [ V_32 ] + ( ( V_32 == 2 ) && V_37 ) ) )
return - V_41 ;
if ( ( V_34 >= 24 ) || ( V_35 >= 60 ) || ( V_36 >= 60 ) )
return - V_41 ;
if ( V_38 >= 2000 )
V_38 -= 2000 ;
else
V_38 -= 1900 ;
V_36 = F_20 ( V_36 ) ;
V_35 = F_20 ( V_35 ) ;
V_34 = F_20 ( V_34 ) ;
V_33 = F_20 ( V_33 ) ;
V_32 = F_20 ( V_32 ) ;
V_38 = F_20 ( V_38 ) ;
F_15 ( & V_29 ) ;
F_10 ( V_12 ) ;
F_21 ( V_38 , V_24 ) ;
F_21 ( V_32 , V_22 ) ;
F_21 ( V_33 , V_20 ) ;
F_21 ( V_34 , V_18 ) ;
F_21 ( V_35 , V_16 ) ;
F_21 ( V_36 , V_14 ) ;
F_12 ( V_12 ) ;
F_16 ( & V_29 ) ;
return 0 ;
}
case V_43 :
{
int V_44 ;
if ( ! F_18 ( V_39 ) )
return - V_40 ;
if( F_19 ( & V_44 , ( int * ) V_27 , sizeof( int ) ) )
return - V_30 ;
F_15 ( & V_29 ) ;
V_44 = V_45 | ( V_44 & 0x0F ) ;
F_8 ( V_46 , V_44 ) ;
F_16 ( & V_29 ) ;
return 0 ;
}
default:
return - V_41 ;
}
}
int
F_22 ( char * V_47 )
{
char * V_48 ;
struct V_10 V_49 ;
V_48 = V_47 ;
F_9 ( & V_49 ) ;
V_48 += sprintf ( V_48 ,
L_1
L_2 ,
V_49 . V_17 , V_49 . V_15 , V_49 . V_13 ,
V_49 . V_23 + 1900 , V_49 . V_21 + 1 , V_49 . V_19 ) ;
return V_48 - V_47 ;
}
static int T_1
F_23 ( void )
{
int V_6 , V_50 , V_51 ;
V_51 = ( V_52 . V_53 / ( 2 * 1000 * 1000 ) ) ;
F_24 ( L_3 , V_54 , V_51 ) ;
F_2 ( 0x0000 , ( unsigned long ) V_5 ) ;
F_2 ( 0x0000 , ( unsigned long ) V_3 ) ;
F_2 ( V_51 , ( unsigned long ) V_55 ) ;
F_5 () ;
F_1 ( 0xc0 , V_56 ) ;
if( ( V_50 = F_4 ( 0xc1 ) ) == V_56 ) {
char V_47 [ 100 ] ;
F_6 () ;
F_24 ( L_4 , V_54 ) ;
F_22 ( V_47 ) ;
F_24 ( V_47 ) ;
V_6 = 1 ;
} else {
F_24 ( L_5 , V_54 ) ;
V_6 = 0 ;
}
return V_6 ;
}
int T_1
F_25 ( void )
{
if ( ! F_23 () ) {
return - 1 ;
}
return 0 ;
}
static int T_1 F_26 ( void )
{
F_25 () ;
if ( F_27 ( V_57 , V_54 , & V_58 ) ) {
F_24 ( V_59 L_6 ,
V_54 , V_57 ) ;
return - 1 ;
}
return 0 ;
}
