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
static int T_5 F_15 ( struct V_43 * V_44 , int V_45 )
{
int V_46 ;
struct V_22 * V_47 = V_44 -> V_22 [ 2 ] ;
int V_35 = V_44 -> V_35 [ 2 ] ;
V_46 = F_16 ( V_47 ) ;
if ( V_46 )
return V_46 ;
F_11 ( V_47 ) ;
V_10 . V_15 = V_44 -> V_15 ;
V_10 . V_22 = V_47 ;
V_48 . V_49 = & V_10 ;
V_23 = V_45 ;
V_10 . V_10 . V_50 = F_17 ( 0 ) ;
V_46 = F_18 ( V_35 , & V_48 ) ;
if ( V_46 )
return V_46 ;
F_19 ( & V_10 . V_10 , 32768 , 1 , 0xffff ) ;
return V_46 ;
}
static int T_5 F_15 ( struct V_43 * V_44 , int V_45 )
{
return 0 ;
}
static void T_5 F_20 ( struct V_43 * V_44 , int V_51 )
{
F_10 ( V_51
| V_24
| V_52
| V_53
| V_54 ,
V_6 + F_4 ( 0 , V_26 ) ) ;
F_10 ( 0x0000 , V_6 + F_4 ( 0 , V_55 ) ) ;
F_10 ( 0x8000 , V_6 + F_4 ( 0 , V_28 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_10 ( V_56
| V_24
| V_52 ,
V_6 + F_4 ( 1 , V_26 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 1 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 1 , V_21 ) ) ;
F_10 ( V_57 , V_6 + V_58 ) ;
F_10 ( V_59 , V_6 + V_60 ) ;
}
static void T_5 F_21 ( struct V_43 * V_44 , int V_51 )
{
F_10 ( V_51
| V_24
| V_52 ,
V_6 + F_4 ( 0 , V_26 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_10 ( V_59 , V_6 + V_60 ) ;
}
static int T_5 F_22 ( void )
{
static char V_61 [] V_62
= V_63 L_1 ;
struct V_64 * V_65 ;
struct V_43 * V_44 ;
struct V_22 * V_66 ;
T_2 V_67 , V_68 = 0 ;
int V_69 = - 1 ;
int V_45 = - 1 ;
int V_70 ;
int V_46 ;
V_44 = F_23 ( V_71 , V_72 . V_73 ) ;
if ( ! V_44 ) {
F_24 ( L_2 ) ;
return - V_74 ;
}
V_6 = V_44 -> V_15 ;
V_65 = V_44 -> V_65 ;
V_66 = V_44 -> V_22 [ 0 ] ;
V_46 = F_16 ( V_66 ) ;
if ( V_46 ) {
F_24 ( L_3 ) ;
goto V_75;
}
V_67 = ( T_2 ) F_25 ( V_66 ) ;
for ( V_70 = 0 ; V_70 < 5 ; V_70 ++ ) {
unsigned V_76 = V_77 [ V_70 ] ;
unsigned V_78 ;
if ( ! V_76 ) {
V_45 = V_70 ;
continue;
}
V_78 = V_67 / V_76 ;
F_24 ( L_4 , V_67 , V_76 , V_70 , V_78 ) ;
if ( V_69 > 0 ) {
if ( V_78 < 5 * 1000 * 1000 )
continue;
}
V_68 = V_78 ;
V_69 = V_70 ;
}
F_26 ( V_61 , V_72 . V_73 , V_71 ,
V_68 / 1000000 ,
( ( V_68 + 500000 ) % 1000000 ) / 1000 ) ;
if ( V_44 -> V_79 && V_44 -> V_79 -> V_80 == 32 ) {
V_72 . V_81 = F_6 ;
F_21 ( V_44 , V_69 ) ;
} else {
V_46 = F_16 ( V_44 -> V_22 [ 1 ] ) ;
if ( V_46 ) {
F_24 ( L_5 ) ;
goto V_82;
}
F_20 ( V_44 , V_69 ) ;
}
V_46 = F_27 ( & V_72 , V_68 ) ;
if ( V_46 )
goto V_83;
V_46 = F_15 ( V_44 , V_45 ) ;
if ( V_46 )
goto V_84;
return 0 ;
V_84:
F_28 ( & V_72 ) ;
V_83:
if ( ! V_44 -> V_79 || V_44 -> V_79 -> V_80 != 32 )
F_29 ( V_44 -> V_22 [ 1 ] ) ;
V_82:
F_29 ( V_66 ) ;
V_75:
F_30 ( V_44 ) ;
return V_46 ;
}
