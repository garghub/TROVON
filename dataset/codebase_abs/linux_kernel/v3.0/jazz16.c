static T_1 F_1 ( int V_1 , void * V_2 )
{
return F_2 ( V_2 ) ;
}
static int T_2 F_3 ( unsigned long V_3 ,
unsigned long V_4 , int V_5 )
{
unsigned char V_6 ;
if ( ! F_4 ( 0x201 , 1 , L_1 ) ) {
F_5 ( V_7 L_2 ) ;
return - V_8 ;
}
F_6 ( V_9 - V_5 , 0x201 ) ;
F_7 ( 100 ) ;
F_6 ( V_10 + V_5 , 0x201 ) ;
F_7 ( 100 ) ;
V_6 = V_3 & 0x70 ;
V_6 |= ( V_4 & 0x30 ) >> 4 ;
F_6 ( V_6 , 0x201 ) ;
F_8 ( 0x201 , 1 ) ;
return 0 ;
}
static int T_2 F_9 ( unsigned long V_3 ,
unsigned long V_4 )
{
int V_11 ;
int V_6 ;
struct V_12 V_2 ;
if ( ! F_4 ( V_3 , 0x10 , L_3 ) ) {
F_5 ( V_7 L_4 ) ;
return - V_8 ;
}
V_2 . V_3 = V_3 ;
V_11 = F_10 ( & V_2 ) ;
if ( V_11 < 0 )
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_11 = F_3 ( V_3 , V_4 , V_6 ) ;
if ( V_11 < 0 )
break;
V_11 = F_10 ( & V_2 ) ;
if ( ! V_11 )
break;
}
if ( V_11 < 0 ) {
V_11 = - V_13 ;
goto V_14;
}
if ( ! F_11 ( & V_2 , V_15 ) ) {
V_11 = - V_8 ;
goto V_14;
}
V_6 = F_12 ( & V_2 ) ;
if ( V_6 >= 0x30 )
F_12 ( & V_2 ) ;
if ( ( V_6 & 0xf0 ) != 0x10 ) {
V_11 = - V_13 ;
goto V_14;
}
if ( ! F_11 ( & V_2 , V_16 ) ) {
V_11 = - V_8 ;
goto V_14;
}
F_12 ( & V_2 ) ;
V_11 = F_12 ( & V_2 ) ;
F_13 ( L_5 ,
V_6 , V_11 ) ;
V_11 = 0 ;
V_14:
F_8 ( V_3 , 0x10 ) ;
return V_11 ;
}
static int T_2 F_14 ( struct V_12 * V_2 , int V_17 )
{
static unsigned char V_18 [] = { 0 , 0 , 2 , 3 , 0 , 1 , 0 , 4 ,
0 , 2 , 5 , 0 , 0 , 0 , 0 , 6 } ;
static unsigned char V_19 [] = { 0 , 1 , 0 , 2 , 0 , 3 , 0 , 4 } ;
if ( V_19 [ V_2 -> V_20 ] == 0 ||
V_19 [ V_2 -> V_21 ] == 0 ||
V_18 [ V_2 -> V_1 ] == 0 )
return - V_22 ;
if ( ! F_11 ( V_2 , V_23 ) )
return - V_8 ;
if ( ! F_11 ( V_2 ,
V_19 [ V_2 -> V_20 ] |
( V_19 [ V_2 -> V_21 ] << 4 ) ) )
return - V_8 ;
if ( ! F_11 ( V_2 ,
V_18 [ V_2 -> V_1 ] |
( V_18 [ V_17 ] << 4 ) ) )
return - V_8 ;
return 0 ;
}
static int T_2 F_15 ( struct V_24 * V_25 , unsigned int V_26 )
{
if ( ! V_27 [ V_26 ] )
return 0 ;
if ( V_3 [ V_26 ] == V_28 ) {
F_5 ( V_7 L_6 ) ;
return 0 ;
} else if ( V_3 [ V_26 ] == 0x200 || ( V_3 [ V_26 ] & ~ 0x270 ) ) {
F_5 ( V_7 L_7 ) ;
return 0 ;
}
if ( V_20 [ V_26 ] != V_29 &&
V_20 [ V_26 ] != 1 && V_20 [ V_26 ] != 3 ) {
F_5 ( V_7 L_8 ) ;
return 0 ;
}
if ( V_21 [ V_26 ] != V_29 &&
V_21 [ V_26 ] != 5 && V_21 [ V_26 ] != 7 ) {
F_5 ( V_7 L_9 ) ;
return 0 ;
}
if ( V_4 [ V_26 ] != V_28 &&
( V_4 [ V_26 ] & ~ 0x030 ) != 0x300 ) {
F_5 ( V_7 L_10 ) ;
return 0 ;
}
if ( V_17 [ V_26 ] != V_29 &&
V_17 [ V_26 ] != 2 && V_17 [ V_26 ] != 3 &&
V_17 [ V_26 ] != 5 && V_17 [ V_26 ] != 7 ) {
F_5 ( V_7 L_11 ) ;
return 0 ;
}
return 1 ;
}
static int T_2 F_16 ( struct V_24 * V_25 , unsigned int V_26 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_12 * V_2 ;
struct V_34 * V_35 ;
static int V_36 [] = { 2 , 3 , 5 , 7 , 9 , 10 , 15 , - 1 } ;
static int V_37 [] = { 1 , 3 , - 1 } ;
static int V_38 [] = { 5 , 7 , - 1 } ;
int V_11 , V_39 , V_40 , V_41 , V_42 , V_43 ;
V_11 = F_17 ( V_44 [ V_26 ] , V_45 [ V_26 ] , V_46 ,
sizeof( struct V_32 ) , & V_31 ) ;
if ( V_11 < 0 )
return V_11 ;
V_33 = V_31 -> V_47 ;
V_39 = V_1 [ V_26 ] ;
if ( V_39 == V_48 ) {
V_39 = F_18 ( V_36 ) ;
if ( V_39 < 0 ) {
F_5 ( V_7 L_12 ) ;
V_11 = - V_8 ;
goto V_49;
}
}
V_40 = V_20 [ V_26 ] ;
if ( V_40 == V_29 ) {
V_40 = F_19 ( V_37 ) ;
if ( V_40 < 0 ) {
F_5 ( V_7 L_13 ) ;
V_11 = - V_8 ;
goto V_49;
}
}
V_41 = V_21 [ V_26 ] ;
if ( V_41 == V_29 ) {
V_41 = F_19 ( V_38 ) ;
if ( V_41 < 0 ) {
F_5 ( V_7 L_14 ) ;
V_11 = - V_8 ;
goto V_49;
}
}
V_42 = V_4 [ V_26 ] ;
if ( V_42 == V_28 )
V_42 = 0 ;
V_11 = F_9 ( V_3 [ V_26 ] , V_42 ) ;
if ( V_11 < 0 ) {
F_20 ( V_7 L_15 ) ;
goto V_49;
}
V_11 = F_21 ( V_31 , V_3 [ V_26 ] , V_1 [ V_26 ] ,
F_1 ,
V_20 [ V_26 ] , V_21 [ V_26 ] ,
V_50 ,
& V_2 ) ;
if ( V_11 < 0 )
goto V_49;
V_43 = V_17 [ V_26 ] ;
if ( V_43 == V_48 || V_4 [ V_26 ] == V_28 )
V_43 = 0 ;
V_11 = F_14 ( V_2 , V_43 ) ;
if ( V_11 < 0 ) {
F_20 ( V_7 L_16 ) ;
goto V_49;
}
V_33 -> V_2 = V_2 ;
strcpy ( V_31 -> V_51 , L_3 ) ;
strcpy ( V_31 -> V_52 , L_17 ) ;
sprintf ( V_31 -> V_53 ,
L_18 ,
V_3 [ V_26 ] , V_39 , V_40 , V_41 ) ;
V_11 = F_22 ( V_2 , 0 , NULL ) ;
if ( V_11 < 0 )
goto V_49;
V_11 = F_23 ( V_2 ) ;
if ( V_11 < 0 )
goto V_49;
V_11 = F_24 ( V_31 , V_2 -> V_3 , V_2 -> V_3 + 2 ,
V_54 , 1 , & V_35 ) ;
if ( V_11 < 0 )
F_5 ( V_55 L_19 ,
V_2 -> V_3 , V_2 -> V_3 + 2 ) ;
else {
V_11 = F_25 ( V_35 , 0 , 1 , NULL ) ;
if ( V_11 < 0 )
goto V_49;
}
if ( V_4 [ V_26 ] > 0 && V_4 [ V_26 ] != V_28 ) {
if ( V_17 [ V_26 ] == V_48 )
V_17 [ V_26 ] = - 1 ;
if ( F_26 ( V_31 , 0 ,
V_56 ,
V_4 [ V_26 ] , 0 ,
V_17 [ V_26 ] ,
V_17 [ V_26 ] >= 0 ? V_57 : 0 ,
NULL ) < 0 )
F_5 ( V_7 L_20 ,
V_4 [ V_26 ] ) ;
}
F_27 ( V_31 , V_25 ) ;
V_11 = F_28 ( V_31 ) ;
if ( V_11 < 0 )
goto V_49;
F_29 ( V_25 , V_31 ) ;
return 0 ;
V_49:
F_30 ( V_31 ) ;
return V_11 ;
}
static int T_3 F_31 ( struct V_24 * V_25 , unsigned int V_26 )
{
struct V_30 * V_31 = F_32 ( V_25 ) ;
F_29 ( V_25 , NULL ) ;
F_30 ( V_31 ) ;
return 0 ;
}
static int F_33 ( struct V_24 * V_58 , unsigned int V_59 ,
T_4 V_60 )
{
struct V_30 * V_31 = F_32 ( V_58 ) ;
struct V_32 * V_61 = V_31 -> V_47 ;
struct V_12 * V_2 = V_61 -> V_2 ;
F_34 ( V_31 , V_62 ) ;
F_35 ( V_2 -> V_63 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_24 * V_58 , unsigned int V_59 )
{
struct V_30 * V_31 = F_32 ( V_58 ) ;
struct V_32 * V_61 = V_31 -> V_47 ;
struct V_12 * V_2 = V_61 -> V_2 ;
F_10 ( V_2 ) ;
F_38 ( V_2 ) ;
F_34 ( V_31 , V_64 ) ;
return 0 ;
}
static int T_5 F_39 ( void )
{
return F_40 ( & V_65 , V_66 ) ;
}
static void T_6 F_41 ( void )
{
F_42 ( & V_65 ) ;
}
