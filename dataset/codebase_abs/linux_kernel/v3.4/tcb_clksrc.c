static T_1 F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_2 V_4 , V_5 ;
F_2 ( V_3 ) ;
do {
V_5 = F_3 ( V_6 + F_4 ( 1 , V_7 ) ) ;
V_4 = F_3 ( V_6 + F_4 ( 0 , V_7 ) ) ;
} while ( V_5 != F_3 ( V_6 + F_4 ( 1 , V_7 ) ) );
F_5 ( V_3 ) ;
return ( V_5 << 16 ) | V_4 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
return F_3 ( V_6 + F_4 ( 0 , V_7 ) ) ;
}
static struct V_8 * F_7 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , struct V_8 , V_10 ) ;
}
static void F_9 ( enum V_11 V_12 , struct V_9 * V_13 )
{
struct V_8 * V_14 = F_7 ( V_13 ) ;
void T_3 * V_15 = V_14 -> V_15 ;
if ( V_14 -> V_10 . V_16 == V_17
|| V_14 -> V_10 . V_16 == V_18 ) {
F_10 ( 0xff , V_15 + F_4 ( 2 , V_19 ) ) ;
F_10 ( V_20 , V_15 + F_4 ( 2 , V_21 ) ) ;
F_11 ( V_14 -> V_22 ) ;
}
switch ( V_12 ) {
case V_17 :
F_12 ( V_14 -> V_22 ) ;
F_10 ( V_23
| V_24 | V_25 ,
V_15 + F_4 ( 2 , V_26 ) ) ;
F_10 ( ( 32768 + V_27 / 2 ) / V_27 , V_6 + F_4 ( 2 , V_28 ) ) ;
F_10 ( V_29 , V_15 + F_4 ( 2 , V_30 ) ) ;
F_10 ( V_31 | V_32 ,
V_15 + F_4 ( 2 , V_21 ) ) ;
break;
case V_18 :
F_12 ( V_14 -> V_22 ) ;
F_10 ( V_23 | V_33
| V_24 | V_25 ,
V_15 + F_4 ( 2 , V_26 ) ) ;
F_10 ( V_29 , V_15 + F_4 ( 2 , V_30 ) ) ;
break;
default:
break;
}
}
static int F_13 ( unsigned long V_34 , struct V_9 * V_13 )
{
F_10 ( V_34 , V_6 + F_4 ( 2 , V_28 ) ) ;
F_10 ( V_31 | V_32 ,
V_6 + F_4 ( 2 , V_21 ) ) ;
return 0 ;
}
static T_4 F_14 ( int V_35 , void * V_36 )
{
struct V_8 * V_37 = V_36 ;
unsigned int V_38 ;
V_38 = F_3 ( V_37 -> V_15 + F_4 ( 2 , V_39 ) ) ;
if ( V_38 & V_29 ) {
V_37 -> V_10 . V_40 ( & V_37 -> V_10 ) ;
return V_41 ;
}
return V_42 ;
}
static void T_5 F_15 ( struct V_43 * V_44 , int V_45 )
{
struct V_22 * V_46 = V_44 -> V_22 [ 2 ] ;
int V_35 = V_44 -> V_35 [ 2 ] ;
V_10 . V_15 = V_44 -> V_15 ;
V_10 . V_22 = V_46 ;
V_47 . V_48 = & V_10 ;
V_23 = V_45 ;
V_10 . V_10 . V_49 = F_16 ( 32768 , V_50 , V_10 . V_10 . V_51 ) ;
V_10 . V_10 . V_52
= F_17 ( 0xffff , & V_10 . V_10 ) ;
V_10 . V_10 . V_53 = F_17 ( 1 , & V_10 . V_10 ) + 1 ;
V_10 . V_10 . V_54 = F_18 ( 0 ) ;
F_19 ( & V_10 . V_10 ) ;
F_20 ( V_35 , & V_47 ) ;
}
static void T_5 F_15 ( struct V_43 * V_44 , int V_45 )
{
}
static void T_5 F_21 ( struct V_43 * V_44 , int V_55 )
{
F_10 ( V_55
| V_24
| V_56
| V_57
| V_58 ,
V_6 + F_4 ( 0 , V_26 ) ) ;
F_10 ( 0x0000 , V_6 + F_4 ( 0 , V_59 ) ) ;
F_10 ( 0x8000 , V_6 + F_4 ( 0 , V_28 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_10 ( V_60
| V_24
| V_56 ,
V_6 + F_4 ( 1 , V_26 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 1 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 1 , V_21 ) ) ;
F_10 ( V_61 , V_6 + V_62 ) ;
F_10 ( V_63 , V_6 + V_64 ) ;
}
static void T_5 F_22 ( struct V_43 * V_44 , int V_55 )
{
F_10 ( V_55
| V_24
| V_56 ,
V_6 + F_4 ( 0 , V_26 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_10 ( V_63 , V_6 + V_64 ) ;
}
static int T_5 F_23 ( void )
{
static char V_65 [] V_66
= V_67 L_1 ;
struct V_68 * V_69 ;
struct V_43 * V_44 ;
struct V_22 * V_70 ;
T_2 V_71 , V_72 = 0 ;
int V_73 = - 1 ;
int V_45 = - 1 ;
int V_74 ;
V_44 = F_24 ( V_75 , V_76 . V_77 ) ;
if ( ! V_44 ) {
F_25 ( L_2 ) ;
return - V_78 ;
}
V_6 = V_44 -> V_15 ;
V_69 = V_44 -> V_69 ;
V_70 = V_44 -> V_22 [ 0 ] ;
F_12 ( V_70 ) ;
V_71 = ( T_2 ) F_26 ( V_70 ) ;
for ( V_74 = 0 ; V_74 < 5 ; V_74 ++ ) {
unsigned V_79 = V_80 [ V_74 ] ;
unsigned V_81 ;
if ( ! V_79 ) {
V_45 = V_74 ;
continue;
}
V_81 = V_71 / V_79 ;
F_25 ( L_3 , V_71 , V_79 , V_74 , V_81 ) ;
if ( V_73 > 0 ) {
if ( V_81 < 5 * 1000 * 1000 )
continue;
}
V_72 = V_81 ;
V_73 = V_74 ;
}
F_27 ( V_65 , V_76 . V_77 , V_75 ,
V_72 / 1000000 ,
( ( V_72 + 500000 ) % 1000000 ) / 1000 ) ;
if ( V_44 -> V_82 && V_44 -> V_82 -> V_83 == 32 ) {
V_76 . V_84 = F_6 ;
F_22 ( V_44 , V_73 ) ;
} else {
F_12 ( V_44 -> V_22 [ 1 ] ) ;
F_21 ( V_44 , V_73 ) ;
}
F_28 ( & V_76 , V_72 ) ;
F_15 ( V_44 , V_45 ) ;
return 0 ;
}
