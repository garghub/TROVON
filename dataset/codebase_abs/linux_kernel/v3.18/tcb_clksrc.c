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
V_23 = V_45 ;
V_10 . V_10 . V_48 = F_17 ( 0 ) ;
V_46 = F_18 ( V_35 , F_14 , V_49 , L_1 , & V_10 ) ;
if ( V_46 ) {
F_19 ( V_47 ) ;
return V_46 ;
}
F_20 ( & V_10 . V_10 , 32768 , 1 , 0xffff ) ;
return V_46 ;
}
static int T_5 F_15 ( struct V_43 * V_44 , int V_45 )
{
return 0 ;
}
static void T_5 F_21 ( struct V_43 * V_44 , int V_50 )
{
F_10 ( V_50
| V_24
| V_51
| V_52
| V_53 ,
V_6 + F_4 ( 0 , V_26 ) ) ;
F_10 ( 0x0000 , V_6 + F_4 ( 0 , V_54 ) ) ;
F_10 ( 0x8000 , V_6 + F_4 ( 0 , V_28 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_10 ( V_55
| V_24
| V_51 ,
V_6 + F_4 ( 1 , V_26 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 1 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 1 , V_21 ) ) ;
F_10 ( V_56 , V_6 + V_57 ) ;
F_10 ( V_58 , V_6 + V_59 ) ;
}
static void T_5 F_22 ( struct V_43 * V_44 , int V_50 )
{
F_10 ( V_50
| V_24
| V_51 ,
V_6 + F_4 ( 0 , V_26 ) ) ;
F_10 ( 0xff , V_6 + F_4 ( 0 , V_19 ) ) ;
F_10 ( V_31 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_10 ( V_58 , V_6 + V_59 ) ;
}
static int T_5 F_23 ( void )
{
static char V_60 [] V_61
= V_62 L_2 ;
struct V_63 * V_64 ;
struct V_43 * V_44 ;
struct V_22 * V_65 ;
T_2 V_66 , V_67 = 0 ;
int V_68 = - 1 ;
int V_45 = - 1 ;
int V_69 ;
int V_46 ;
V_44 = F_24 ( V_70 ) ;
if ( ! V_44 ) {
F_25 ( L_3 ) ;
return - V_71 ;
}
V_6 = V_44 -> V_15 ;
V_64 = V_44 -> V_64 ;
V_65 = V_44 -> V_22 [ 0 ] ;
V_46 = F_16 ( V_65 ) ;
if ( V_46 ) {
F_25 ( L_4 ) ;
goto V_72;
}
V_66 = ( T_2 ) F_26 ( V_65 ) ;
for ( V_69 = 0 ; V_69 < 5 ; V_69 ++ ) {
unsigned V_73 = V_74 [ V_69 ] ;
unsigned V_75 ;
if ( ! V_73 ) {
V_45 = V_69 ;
continue;
}
V_75 = V_66 / V_73 ;
F_25 ( L_5 , V_66 , V_73 , V_69 , V_75 ) ;
if ( V_68 > 0 ) {
if ( V_75 < 5 * 1000 * 1000 )
continue;
}
V_67 = V_75 ;
V_68 = V_69 ;
}
F_27 ( V_60 , V_76 . V_77 , V_70 ,
V_67 / 1000000 ,
( ( V_67 + 500000 ) % 1000000 ) / 1000 ) ;
if ( V_44 -> V_78 && V_44 -> V_78 -> V_79 == 32 ) {
V_76 . V_80 = F_6 ;
F_22 ( V_44 , V_68 ) ;
} else {
V_46 = F_16 ( V_44 -> V_22 [ 1 ] ) ;
if ( V_46 ) {
F_25 ( L_6 ) ;
goto V_81;
}
F_21 ( V_44 , V_68 ) ;
}
V_46 = F_28 ( & V_76 , V_67 ) ;
if ( V_46 )
goto V_82;
V_46 = F_15 ( V_44 , V_45 ) ;
if ( V_46 )
goto V_83;
return 0 ;
V_83:
F_29 ( & V_76 ) ;
V_82:
if ( ! V_44 -> V_78 || V_44 -> V_78 -> V_79 != 32 )
F_19 ( V_44 -> V_22 [ 1 ] ) ;
V_81:
F_19 ( V_65 ) ;
V_72:
F_30 ( V_44 ) ;
return V_46 ;
}
