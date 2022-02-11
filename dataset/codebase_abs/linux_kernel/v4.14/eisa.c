static inline unsigned long F_1 ( unsigned short V_1 )
{
if ( V_1 & 0x300 ) {
return 0xfc000000 | ( ( V_1 & 0xfc00 ) >> 6 )
| ( ( V_1 & 0x3f8 ) << 9 ) | ( V_1 & 7 ) ;
} else {
return 0xfc000000 | V_1 ;
}
}
unsigned char F_2 ( unsigned short V_1 )
{
if ( V_2 )
return F_3 ( F_1 ( V_1 ) ) ;
return 0xff ;
}
unsigned short F_4 ( unsigned short V_1 )
{
if ( V_2 )
return F_5 ( F_6 ( F_1 ( V_1 ) ) ) ;
return 0xffff ;
}
unsigned int F_7 ( unsigned short V_1 )
{
if ( V_2 )
return F_8 ( F_9 ( F_1 ( V_1 ) ) ) ;
return 0xffffffff ;
}
void F_10 ( unsigned char V_3 , unsigned short V_1 )
{
if ( V_2 )
F_11 ( V_3 , F_1 ( V_1 ) ) ;
}
void F_12 ( unsigned short V_3 , unsigned short V_1 )
{
if ( V_2 )
F_13 ( F_14 ( V_3 ) , F_1 ( V_1 ) ) ;
}
void F_15 ( unsigned int V_3 , unsigned short V_1 )
{
if ( V_2 )
F_16 ( F_17 ( V_3 ) , F_1 ( V_1 ) ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
unsigned int V_6 = V_5 -> V_6 ;
unsigned long V_7 ;
F_19 ( L_1 , V_6 ) ;
F_20 ( & V_8 , V_7 ) ;
if ( V_6 & 8 ) {
V_9 |= ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_9 , 0xa1 ) ;
} else {
V_10 |= ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_10 , 0x21 ) ;
}
F_21 ( & V_8 , V_7 ) ;
F_19 ( L_2 , F_2 ( 0x21 ) ) ;
F_19 ( L_3 , F_2 ( 0xa1 ) ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
unsigned int V_6 = V_5 -> V_6 ;
unsigned long V_7 ;
F_19 ( L_4 , V_6 ) ;
F_20 ( & V_8 , V_7 ) ;
if ( V_6 & 8 ) {
V_9 &= ~ ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_9 , 0xa1 ) ;
} else {
V_10 &= ~ ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_10 , 0x21 ) ;
}
F_21 ( & V_8 , V_7 ) ;
F_19 ( L_2 , F_2 ( 0x21 ) ) ;
F_19 ( L_3 , F_2 ( 0xa1 ) ) ;
}
static T_1 F_23 ( int V_11 , void * V_12 )
{
int V_6 = F_3 ( 0xfc01f000 ) ;
unsigned long V_7 ;
F_20 ( & V_8 , V_7 ) ;
F_10 ( 0x0a , 0x20 ) ;
F_10 ( 0x0a , 0xa0 ) ;
F_19 ( L_5 ,
V_6 , F_2 ( 0x20 ) , F_2 ( 0xa0 ) ) ;
F_10 ( 0x0a , 0x20 ) ;
F_10 ( 0x0a , 0xa0 ) ;
F_19 ( L_6 ,
F_2 ( 0x20 ) , F_2 ( 0x21 ) , F_2 ( 0xa0 ) , F_2 ( 0xa1 ) ) ;
V_6 &= 0xf ;
if ( V_6 & 8 ) {
V_9 |= ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_9 , 0xa1 ) ;
F_10 ( 0x60 | ( V_6 & 7 ) , 0xa0 ) ;
F_10 ( 0x62 , 0x20 ) ;
} else {
V_10 |= ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_10 , 0x21 ) ;
F_10 ( 0x60 | V_6 , 0x20 ) ;
}
F_21 ( & V_8 , V_7 ) ;
F_24 ( V_6 ) ;
F_20 ( & V_8 , V_7 ) ;
if ( V_6 & 8 ) {
V_9 &= ~ ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_9 , 0xa1 ) ;
} else {
V_10 &= ~ ( 1 << ( V_6 & 7 ) ) ;
F_10 ( V_10 , 0x21 ) ;
}
F_21 ( & V_8 , V_7 ) ;
return V_13 ;
}
static T_1 F_25 ( int _ , void * V_14 )
{
F_26 ( V_15 L_7 ) ;
return V_13 ;
}
static void F_27 ( void )
{
unsigned long V_7 ;
F_20 ( & V_8 , V_7 ) ;
F_10 ( 0xff , 0x21 ) ;
F_10 ( 0xff , 0xa1 ) ;
F_10 ( 0x11 , 0x20 ) ;
F_10 ( 0x00 , 0x21 ) ;
F_10 ( 0x04 , 0x21 ) ;
F_10 ( 0x01 , 0x21 ) ;
F_10 ( 0x40 , 0x20 ) ;
F_10 ( 0x11 , 0xa0 ) ;
F_10 ( 0x08 , 0xa1 ) ;
F_10 ( 0x02 , 0xa1 ) ;
F_10 ( 0x01 , 0xa1 ) ;
F_10 ( 0x40 , 0xa0 ) ;
F_28 ( 100 ) ;
V_9 = 0xff ;
V_10 = 0xfb ;
F_10 ( V_9 , 0xa1 ) ;
F_10 ( V_10 , 0x21 ) ;
F_19 ( L_8 , V_16 ) ;
F_10 ( V_16 & 0xff , 0x4d0 ) ;
F_10 ( ( V_16 >> 8 ) & 0xff , 0x4d1 ) ;
F_19 ( L_2 , F_2 ( 0x21 ) ) ;
F_19 ( L_3 , F_2 ( 0xa1 ) ) ;
F_19 ( L_9 , F_2 ( 0x4d0 ) ) ;
F_19 ( L_10 , F_2 ( 0x4d1 ) ) ;
F_21 ( & V_8 , V_7 ) ;
}
static int T_2 F_29 ( struct V_17 * V_14 )
{
int V_18 , V_19 ;
char * V_20 = F_30 ( V_14 ) ? L_11 : L_12 ;
F_26 ( V_21 L_13 ,
V_20 , ( unsigned long ) V_14 -> V_22 . V_23 ) ;
V_24 . V_25 . V_14 = V_14 ;
V_24 . V_25 . V_26 = F_31 ( V_14 ) ;
V_24 . V_25 . V_27 . V_20 = L_14 ;
V_24 . V_25 . V_27 . V_23 = F_32 ( 0xfc000000 ) ;
V_24 . V_25 . V_27 . V_28 = F_32 ( 0xffbfffff ) ;
V_24 . V_25 . V_27 . V_7 = V_29 ;
V_19 = F_33 ( V_14 , & V_24 . V_25 . V_27 ) ;
if ( V_19 < 0 ) {
F_26 ( V_30 L_15 ) ;
return V_19 ;
}
V_24 . V_25 . V_31 . V_20 = L_14 ;
V_24 . V_25 . V_31 . V_23 = 0 ;
V_24 . V_25 . V_31 . V_28 = 0xffff ;
V_24 . V_25 . V_27 . V_7 = V_32 ;
V_19 = F_34 ( & V_33 , & V_24 . V_25 . V_31 ) ;
if ( V_19 < 0 ) {
F_26 ( V_30 L_16 ) ;
return V_19 ;
}
F_35 ( & V_24 . V_25 ) ;
V_19 = F_36 ( V_14 -> V_6 , F_23 , V_34 , L_14 , & V_24 ) ;
if ( V_19 ) {
F_26 ( V_30 L_17 ) ;
goto V_35;
}
F_37 ( 2 , & V_36 ) ;
for ( V_18 = 0 ; V_18 < 16 ; V_18 ++ ) {
F_38 ( V_18 , & V_37 ,
V_38 ) ;
}
V_2 = 1 ;
if ( V_14 -> V_39 ) {
V_24 . V_40 = V_14 -> V_41 [ 0 ] ;
} else {
if ( F_30 ( V_14 ) ) {
V_24 . V_40 = V_42 ;
} else {
V_24 . V_40 = V_43 ;
}
}
V_44 = F_39 ( V_24 . V_40 , V_45 ) ;
if ( ! V_44 ) {
V_19 = - V_46 ;
F_26 ( V_30 L_18 ) ;
goto V_47;
}
V_19 = F_40 ( V_24 . V_40 , & V_24 . V_25 . V_31 ,
& V_24 . V_25 . V_27 ) ;
F_27 () ;
if ( V_19 >= 0 ) {
V_24 . V_48 . V_14 = & V_14 -> V_14 ;
F_41 ( & V_14 -> V_14 , & V_24 . V_48 ) ;
V_24 . V_48 . V_49 = 0 ;
V_24 . V_48 . V_50 = & V_24 . V_25 . V_31 ;
V_24 . V_48 . V_51 = V_19 ;
V_24 . V_48 . V_52 = 0xffffffff ;
if ( F_42 ( & V_24 . V_48 ) ) {
F_26 ( V_30 L_19 ) ;
V_19 = - V_46 ;
goto V_53;
}
}
return 0 ;
V_53:
F_43 ( V_44 ) ;
V_47:
F_44 ( V_14 -> V_6 , & V_24 ) ;
V_35:
F_45 ( & V_24 . V_25 . V_31 ) ;
return V_19 ;
}
void T_2 F_46 ( void )
{
F_47 ( & V_54 ) ;
}
void F_48 ( int V_55 )
{
if ( V_56 & ( 1 << V_55 ) ) {
F_26 ( V_57
L_20 ,
V_55 ) ;
}
V_16 |= ( 1 << V_55 ) ;
V_56 |= ( 1 << V_55 ) ;
}
void F_49 ( int V_55 )
{
if ( V_56 & ( 1 << V_55 ) ) {
F_26 ( V_57
L_21 ,
V_55 ) ;
}
V_16 &= ~ ( 1 << V_55 ) ;
V_56 |= ( 1 << V_55 ) ;
}
static int T_2 F_50 ( char * V_58 )
{
char * V_59 = V_58 ;
int V_60 ;
F_19 ( L_22 ) ;
while ( V_59 != NULL ) {
char * V_61 ;
V_60 = ( int ) F_51 ( V_59 , & V_61 , 0 ) ;
if ( V_60 > 15 || V_60 < 0 ) {
F_26 ( V_30 L_23 ) ;
continue;
}
if ( V_60 == 2 ) {
V_60 = 9 ;
}
F_49 ( V_60 ) ;
F_19 ( L_24 , V_60 ) ;
if ( ( V_59 = strchr ( V_59 , ',' ) ) ) {
V_59 ++ ;
} else {
break;
}
}
return 1 ;
}
