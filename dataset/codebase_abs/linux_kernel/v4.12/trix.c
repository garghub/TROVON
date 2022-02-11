static unsigned char F_1 ( int V_1 )
{
F_2 ( ( ( unsigned char ) V_1 ) , 0x390 ) ;
return F_3 ( 0x391 ) ;
}
static void F_4 ( int V_1 , int V_2 )
{
F_2 ( ( ( unsigned char ) V_1 ) , 0x390 ) ;
F_2 ( ( ( unsigned char ) V_2 ) , 0x391 ) ;
}
static void F_5 ( int V_3 )
{
int V_4 = 0 , V_5 = V_6 ;
if ( V_6 == 0 )
return;
F_4 ( 0xf8 , 0x00 ) ;
F_2 ( ( 0x01 ) , V_3 + 6 ) ;
F_2 ( ( 0x00 ) , V_3 + 6 ) ;
F_2 ( ( 0x01 ) , V_3 + 6 ) ;
F_2 ( ( 0x1A ) , 0x390 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
F_2 ( ( V_7 [ V_4 ] ) , 0x391 ) ;
for ( V_4 = V_5 ; V_4 < 10016 ; V_4 ++ )
F_2 ( ( 0x00 ) , 0x391 ) ;
F_2 ( ( 0x00 ) , V_3 + 6 ) ;
F_2 ( ( 0x50 ) , 0x390 ) ;
}
static int F_6 ( struct V_8 * V_9 )
{
unsigned char V_10 ;
if ( F_1 ( 0x15 ) != 0x71 )
{
F_7 ( F_8 ( V_11 L_1 ) ) ;
return 0 ;
}
F_4 ( 0x13 , 0 ) ;
F_4 ( 0x14 , 0 ) ;
switch ( V_9 -> V_12 )
{
case 0x530 :
V_10 = 0 ;
break;
case 0x604 :
V_10 = 1 ;
break;
case 0xE80 :
V_10 = 2 ;
break;
case 0xF40 :
V_10 = 3 ;
break;
default:
return 0 ;
}
F_4 ( 0x19 , ( F_1 ( 0x19 ) & 0x03 ) | V_10 ) ;
return 1 ;
}
static int T_1 F_9 ( struct V_8 * V_9 )
{
static unsigned char V_13 [ 4 ] = {
1 , 2 , 0 , 3
} ;
struct V_14 * V_15 ;
int V_16 = V_9 -> V_12 + 0 ;
int V_17 = V_9 -> V_18 , V_19 = V_9 -> V_19 ;
int V_20 = V_21 ;
T_2 V_22 , V_23 ;
int V_24 ;
switch( V_9 -> V_25 ) {
case 7 :
V_23 = 8 ;
break;
case 9 :
V_23 = 0x10 ;
break;
case 10 :
V_23 = 0x18 ;
break;
case 11 :
V_23 = 0x20 ;
break;
default:
F_8 ( V_11 L_2 , V_9 -> V_25 ) ;
return 0 ;
}
switch ( V_17 ) {
case 0 :
case 1 :
case 3 :
break;
default:
F_8 ( V_11 L_3 , V_17 ) ;
return 0 ;
}
switch ( V_19 ) {
case - 1 :
case 0 :
case 1 :
case 3 :
break;
default:
F_8 ( V_11 L_4 , V_19 ) ;
return 0 ;
}
V_15 = F_10 ( V_9 -> V_12 + 4 , 4 , L_5 ) ;
if ( ! V_15 ) {
F_8 ( V_11 L_6 , V_9 -> V_12 ) ;
return 0 ;
}
if ( ! F_10 ( V_9 -> V_12 , 4 , L_7 ) ) {
F_8 ( V_11 L_6 , V_9 -> V_12 ) ;
F_11 ( V_9 -> V_12 + 4 , 4 ) ;
return 0 ;
}
if ( ! F_6 ( V_9 ) )
goto V_26;
V_22 = F_3 ( V_9 -> V_12 + 3 ) ;
if ( ( V_22 & 0x3f ) != 0x00 )
{
F_7 ( F_8 ( V_11 L_8 , V_9 -> V_12 ) ) ;
goto V_26;
}
if ( V_17 == 0 && V_22 & 0x80 )
{
F_8 ( V_11 L_9 ) ;
goto V_26;
}
if ( V_9 -> V_25 > 9 && V_22 & 0x80 )
{
F_8 ( V_11 L_10 , V_9 -> V_25 ) ;
goto V_26;
}
V_24 = F_12 ( V_15 , NULL , V_9 -> V_27 ) ;
if ( ! V_24 )
goto V_26;
if ( V_28 == 1 )
F_4 ( 0x15 , 0x80 ) ;
F_2 ( ( V_23 | 0x40 ) , V_16 ) ;
if ( V_19 == - 1 || V_19 == V_17 )
{
V_23 |= V_13 [ V_17 ] ;
V_19 = V_17 ;
}
else
{
unsigned char V_29 ;
V_29 = F_1 ( 0x13 ) & ~ 30 ;
F_4 ( 0x13 , V_29 | 0x80 | ( V_17 << 4 ) ) ;
V_29 = F_1 ( 0x14 ) & ~ 30 ;
F_4 ( 0x14 , V_29 | 0x80 | ( V_19 << 4 ) ) ;
}
F_2 ( ( V_23 ) , V_16 ) ;
V_9 -> V_30 [ 0 ] = F_13 ( L_11 , V_15 ,
V_9 -> V_25 ,
V_17 ,
V_19 ,
0 ,
V_9 -> V_27 ,
V_31 ) ;
if ( V_21 > V_20 )
{
F_14 ( V_32 , V_33 ) ;
F_14 ( V_34 , V_35 ) ;
F_14 ( V_36 , V_37 ) ;
F_14 ( V_38 , V_39 ) ;
}
return 1 ;
V_26:
F_11 ( V_9 -> V_12 , 4 ) ;
F_11 ( V_9 -> V_12 + 4 , 4 ) ;
return 0 ;
}
static int T_1 F_15 ( struct V_8 * V_9 )
{
int V_29 ;
unsigned char V_40 ;
extern int V_41 ;
int V_42 ;
static signed char V_43 [] = {
- 1 , - 1 , - 1 , 0 , 1 , 2 , - 1 , 3
} ;
if ( V_6 == 0 )
return 0 ;
if ( ( V_9 -> V_12 & 0xffffff8f ) != 0x200 )
return 0 ;
V_29 = V_9 -> V_25 ;
if ( V_29 > 7 )
return 0 ;
if ( V_43 [ V_29 ] == - 1 )
return 0 ;
V_29 = V_9 -> V_18 ;
if ( V_29 != 1 && V_29 != 3 )
return 0 ;
if ( ! F_10 ( V_9 -> V_12 , 16 , L_12 ) ) {
F_8 ( V_11 L_13 , V_9 -> V_12 ) ;
return 0 ;
}
V_40 = 0x84 ;
V_40 |= V_9 -> V_12 & 0x70 ;
V_40 |= V_43 [ V_9 -> V_25 ] ;
if ( V_9 -> V_18 == 3 )
V_40 |= 0x08 ;
F_4 ( 0x1b , V_40 ) ;
F_5 ( V_9 -> V_12 ) ;
V_9 -> V_44 = L_14 ;
if ( ! F_16 ( V_9 , 0 , 0 , NULL ) ) {
F_11 ( V_9 -> V_12 , 16 ) ;
return 0 ;
}
V_9 -> V_45 = V_46 | V_47 | V_48 ;
V_42 = V_41 ;
V_41 = 1 ;
F_17 ( V_9 , V_31 ) ;
V_41 = V_42 ;
return 1 ;
}
static int T_1 F_18 ( struct V_8 * V_9 )
{
unsigned char V_40 ;
static int V_49 [] = {
- 1 , - 1 , - 1 , 1 , 2 , 3 , - 1 , 4 , - 1 , 5
} ;
if ( V_9 -> V_25 > 9 )
{
F_8 ( V_11 L_15 , V_9 -> V_25 ) ;
return 0 ;
}
if ( V_49 [ V_9 -> V_25 ] == - 1 )
{
F_8 ( V_11 L_15 , V_9 -> V_25 ) ;
return 0 ;
}
switch ( V_9 -> V_12 )
{
case 0x330 :
V_40 = 0x00 ;
break;
case 0x370 :
V_40 = 0x04 ;
break;
case 0x3b0 :
V_40 = 0x08 ;
break;
case 0x3f0 :
V_40 = 0x0c ;
break;
default:
return 0 ;
}
V_40 |= V_49 [ V_9 -> V_25 ] << 4 ;
F_4 ( 0x19 , ( F_1 ( 0x19 ) & 0x83 ) | V_40 ) ;
V_9 -> V_44 = L_11 ;
return F_19 ( V_9 , V_31 ) ;
}
static void T_3 F_20 ( struct V_8 * V_9 )
{
int V_19 = V_9 -> V_19 ;
if ( V_19 == - 1 )
V_19 = V_9 -> V_18 ;
F_11 ( 0x390 , 2 ) ;
F_11 ( V_9 -> V_12 , 4 ) ;
F_21 ( V_9 -> V_12 + 4 ,
V_9 -> V_25 ,
V_9 -> V_18 ,
V_19 ,
0 ) ;
F_22 ( V_9 -> V_30 [ 0 ] ) ;
}
static inline void T_3 F_23 ( struct V_8 * V_9 )
{
F_24 ( V_9 ) ;
}
static inline void T_3 F_25 ( struct V_8 * V_9 )
{
F_26 ( V_9 , V_50 ) ;
}
static int T_1 F_27 ( void )
{
F_8 ( V_51 L_16 ) ;
V_52 . V_12 = V_53 ;
V_52 . V_25 = V_25 ;
V_52 . V_18 = V_18 ;
V_52 . V_19 = V_19 ;
V_54 . V_12 = V_55 ;
V_54 . V_25 = V_56 ;
V_54 . V_18 = V_57 ;
V_58 . V_12 = V_59 ;
V_58 . V_25 = V_60 ;
if ( V_52 . V_12 == - 1 || V_52 . V_18 == - 1 || V_52 . V_25 == - 1 ) {
F_8 ( V_51 L_17 ) ;
return - V_61 ;
}
if ( V_54 . V_12 != - 1 && ( V_54 . V_25 == - 1 || V_54 . V_18 == - 1 ) ) {
F_8 ( V_51 L_18 ) ;
return - V_61 ;
}
if ( V_58 . V_12 != - 1 && V_58 . V_25 == - 1 ) {
F_8 ( V_51 L_19 ) ;
return - V_61 ;
}
if ( ! V_7 )
{
V_62 = 1 ;
V_6 = F_28 ( L_20 ,
( char * * ) & V_7 ) ;
}
if ( ! F_10 ( 0x390 , 2 , L_21 ) ) {
F_8 ( V_11 L_22 ) ;
return - V_63 ;
}
if ( ! F_9 ( & V_52 ) ) {
F_11 ( 0x390 , 2 ) ;
return - V_63 ;
}
if ( V_54 . V_12 != - 1 ) {
V_64 = F_15 ( & V_54 ) ;
}
if ( V_58 . V_12 != - 1 )
V_50 = F_18 ( & V_58 ) ;
return 0 ;
}
static void T_3 F_29 ( void )
{
if ( V_62 )
F_30 ( V_7 ) ;
if ( V_64 )
F_25 ( & V_54 ) ;
if ( V_50 )
F_23 ( & V_58 ) ;
F_20 ( & V_52 ) ;
}
static int T_1 F_31 ( char * V_65 )
{
int V_66 [ 9 ] ;
V_65 = F_32 ( V_65 , F_33 ( V_66 ) , V_66 ) ;
V_53 = V_66 [ 1 ] ;
V_25 = V_66 [ 2 ] ;
V_18 = V_66 [ 3 ] ;
V_19 = V_66 [ 4 ] ;
V_55 = V_66 [ 5 ] ;
V_56 = V_66 [ 6 ] ;
V_57 = V_66 [ 6 ] ;
V_59 = V_66 [ 7 ] ;
V_60 = V_66 [ 8 ] ;
return 1 ;
}
