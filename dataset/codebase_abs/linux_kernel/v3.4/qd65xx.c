static void F_1 ( T_1 * V_1 )
{
T_2 V_2 = ( ( ( F_2 ( V_1 ) ) & 0x80 ) >> 7 ) |
( F_2 ( V_1 ) & 0x02 ) ;
if ( V_3 [ V_2 ] != F_3 ( V_1 ) )
F_4 ( V_3 [ V_2 ] = F_3 ( V_1 ) , F_2 ( V_1 ) ) ;
F_4 ( V_1 -> V_4 | V_5 , V_1 -> V_6 -> V_7 . V_8 ) ;
}
static T_2 F_5 ( T_3 * V_6 , int V_9 , int V_10 )
{
int V_11 = V_12 ? V_12 : 50 ;
T_2 V_13 , V_14 ;
if ( V_11 <= 33 ) {
V_13 = 9 - F_6 ( V_9 * V_11 / 1000 + 1 , 2 , 9 ) ;
V_14 = 15 - F_6 ( V_10 * V_11 / 1000 + 1 , 0 , 15 ) ;
} else {
V_13 = 8 - F_6 ( V_9 * V_11 / 1000 + 1 , 1 , 8 ) ;
V_14 = 18 - F_6 ( V_10 * V_11 / 1000 + 1 , 3 , 18 ) ;
}
return ( V_14 << 4 ) | 0x08 | V_13 ;
}
static T_2 F_7 ( int V_9 , int V_10 )
{
int V_11 = V_12 ? V_12 : 50 ;
T_2 V_13 , V_14 ;
V_13 = 17 - F_6 ( V_9 * V_11 / 1000 + 1 , 2 , 17 ) ;
V_14 = 15 - F_6 ( V_10 * V_11 / 1000 + 1 , 2 , 15 ) ;
return ( V_14 << 4 ) | V_13 ;
}
static int F_8 ( T_1 * V_1 ,
int * V_9 , int * V_10 )
{
struct V_15 * V_16 ;
char * V_17 = ( char * ) & V_1 -> V_18 [ V_19 ] ;
char V_20 [ V_21 ] ;
if ( * V_17 == 0 )
return 0 ;
strncpy ( V_20 , V_17 , V_21 ) ;
F_9 ( V_20 , V_21 , 1 ) ;
for ( V_16 = V_22 ; V_16 -> V_23 != - 1 ; V_16 ++ ) {
if ( ! strncmp ( V_16 -> V_20 , V_20 + V_16 -> V_23 , 4 ) ) {
F_10 ( V_24 L_1 , V_1 -> V_25 ) ;
* V_9 = V_16 -> V_26 ;
* V_10 = V_16 -> V_27 ;
return 1 ;
}
}
return 0 ;
}
static void F_11 ( T_1 * V_1 , T_2 V_28 )
{
unsigned long V_29 = ( unsigned long ) F_12 ( V_1 ) ;
V_29 &= 0xff00 ;
V_29 |= V_28 ;
F_13 ( V_1 , ( void * ) V_29 ) ;
F_10 ( V_24 L_2 , V_1 -> V_25 , V_28 ) ;
}
static void F_14 ( T_3 * V_6 , T_1 * V_1 )
{
T_4 * V_18 = V_1 -> V_18 ;
int V_9 = 175 ;
int V_10 = 415 ;
if ( ! F_8 ( V_1 , & V_9 , & V_10 ) &&
( V_18 [ V_30 ] & 0xff ) && ( V_18 [ V_31 ] & 2 ) &&
V_18 [ V_32 ] >= 240 ) {
F_10 ( V_33 L_3 , V_1 -> V_25 ,
V_18 [ V_30 ] & 0xff ) ;
V_9 = 110 ;
V_10 = V_1 -> V_18 [ V_32 ] - 120 ;
}
F_11 ( V_1 , F_5 ( V_1 -> V_6 ,
V_9 , V_10 ) ) ;
}
static void F_15 ( T_3 * V_6 , T_1 * V_1 )
{
const T_2 V_34 = V_1 -> V_35 - V_36 ;
struct V_37 * V_38 = F_16 ( V_36 + V_34 ) ;
unsigned int V_39 ;
int V_9 = 175 ;
int V_10 = 415 ;
T_2 V_40 = ( V_6 -> V_41 & 0xff00 ) >> 8 ;
if ( V_1 -> V_18 && ! F_8 ( V_1 , & V_9 , & V_10 ) ) {
V_39 = F_17 ( V_1 , V_34 ) ;
switch ( V_34 ) {
case 0 : break;
case 3 :
if ( V_39 >= 110 ) {
V_9 = 86 ;
V_10 = V_39 - 102 ;
} else
F_10 ( V_42 L_4 , V_1 -> V_25 ) ;
break;
case 4 :
if ( V_39 >= 69 ) {
V_9 = 70 ;
V_10 = V_39 - 61 ;
} else
F_10 ( V_42 L_4 , V_1 -> V_25 ) ;
break;
default:
if ( V_39 >= 180 ) {
V_9 = 110 ;
V_10 = V_39 - 120 ;
} else {
V_9 = V_38 -> V_26 ;
V_10 = V_39 - V_9 ;
}
}
F_10 ( V_33 L_3 , V_1 -> V_25 , V_34 ) ;
}
if ( ! V_6 -> V_43 && V_1 -> V_44 != V_45 ) {
F_4 ( 0x5f , V_46 ) ;
F_10 ( V_42 L_5
L_6 ,
V_1 -> V_25 , V_6 -> V_25 ) ;
}
F_11 ( V_1 , F_7 ( V_9 , V_10 ) ) ;
}
static int T_5 F_18 ( int V_47 )
{
unsigned long V_48 ;
T_2 V_49 , V_50 ;
F_19 ( V_48 ) ;
V_49 = F_20 ( V_47 ) ;
F_21 ( V_51 , V_47 ) ;
V_50 = F_20 ( V_47 ) ;
F_4 ( V_49 , V_47 ) ;
F_22 ( V_48 ) ;
if ( V_49 == V_51 ) {
F_10 ( V_52 L_7 ) ;
F_10 ( V_52 L_8 ) ;
F_10 ( V_52 L_9 ) ;
return 1 ;
}
return ( V_50 != V_51 ) ;
}
static void T_5 F_23 ( T_1 * V_1 )
{
T_3 * V_6 = V_1 -> V_6 ;
T_2 V_40 = ( V_6 -> V_41 & 0xff00 ) >> 8 ;
T_2 V_53 = F_24 ( V_6 ) ;
F_13 ( V_1 , ( void * ) V_54 ) ;
}
static void T_5 F_25 ( T_1 * V_1 )
{
T_3 * V_6 = V_1 -> V_6 ;
T_4 V_55 , V_56 ;
T_2 V_40 = ( V_6 -> V_41 & 0xff00 ) >> 8 ;
T_2 V_53 = F_24 ( V_6 ) ;
if ( V_6 -> V_57 & V_58 ) {
V_55 = V_59 ;
V_56 = V_60 ;
} else
V_56 = V_55 = V_6 -> V_43 ? V_60 : V_59 ;
F_13 ( V_1 , ( void * ) ( ( V_1 -> V_61 & 1 ) ? V_56 : V_55 ) ) ;
}
static int T_5 F_26 ( int V_40 )
{
int V_62 ;
T_2 V_53 , V_63 , V_64 ;
struct V_65 V_66 = V_67 ;
V_53 = F_27 ( V_68 ) ;
if ( ! ( ( V_53 & V_69 ) >> 1 == ( V_40 == 0xb0 ) ) )
return - V_70 ;
V_63 = ! ( V_53 & V_71 ) ;
if ( V_63 )
V_66 . V_57 |= V_72 ;
switch ( V_53 & 0xf0 ) {
case V_73 :
if ( F_18 ( V_40 ) )
return - V_70 ;
if ( V_53 & V_74 ) {
F_10 ( V_42 L_10 ) ;
return - V_70 ;
}
F_10 ( V_75 L_11 , V_40 ) ;
F_10 ( V_24 L_12 ,
V_53 , V_76 ) ;
V_66 . V_77 = & V_78 ;
V_66 . V_57 |= V_58 ;
break;
case V_79 :
case V_80 :
if ( F_18 ( V_40 ) || F_18 ( V_40 + 0x02 ) )
return - V_70 ;
V_64 = F_27 ( V_46 ) ;
F_10 ( V_75 L_13 , V_40 ) ;
F_10 ( V_24 L_14 ,
V_53 , V_64 , V_76 ) ;
F_4 ( V_81 , V_46 ) ;
V_66 . V_77 = & V_82 ;
if ( V_64 & V_83 )
V_66 . V_57 |= V_58 ;
F_10 ( V_33 L_15 ,
( V_64 & V_83 ) ? L_16 : L_17 ) ;
break;
default:
return - V_70 ;
}
V_62 = F_28 ( & V_66 , ( V_40 << 8 ) | V_53 ) ;
if ( V_66 . V_57 & V_58 )
return ( V_62 == 0 ) ? 1 : V_62 ;
return V_62 ;
}
static int T_5 F_29 ( void )
{
int V_84 , V_85 = - V_70 ;
if ( V_86 == 0 )
return - V_70 ;
V_84 = F_26 ( 0x30 ) ;
if ( V_84 )
V_85 = F_26 ( 0xb0 ) ;
if ( V_84 < 0 && V_85 < 0 )
return - V_70 ;
return 0 ;
}
