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
static struct V_8 * F_6 ( struct V_9 * V_10 )
{
return F_7 ( V_10 , struct V_8 , V_10 ) ;
}
static void F_8 ( enum V_11 V_12 , struct V_9 * V_13 )
{
struct V_8 * V_14 = F_6 ( V_13 ) ;
void T_3 * V_15 = V_14 -> V_15 ;
if ( V_14 -> V_10 . V_16 == V_17
|| V_14 -> V_10 . V_16 == V_18 ) {
F_9 ( 0xff , V_15 + F_4 ( 2 , V_19 ) ) ;
F_9 ( V_20 , V_15 + F_4 ( 2 , V_21 ) ) ;
F_10 ( V_14 -> V_22 ) ;
}
switch ( V_12 ) {
case V_17 :
F_11 ( V_14 -> V_22 ) ;
F_9 ( V_23
| V_24 | V_25 ,
V_15 + F_4 ( 2 , V_26 ) ) ;
F_9 ( ( 32768 + V_27 / 2 ) / V_27 , V_6 + F_4 ( 2 , V_28 ) ) ;
F_9 ( V_29 , V_15 + F_4 ( 2 , V_30 ) ) ;
F_9 ( V_31 | V_32 ,
V_15 + F_4 ( 2 , V_21 ) ) ;
break;
case V_18 :
F_11 ( V_14 -> V_22 ) ;
F_9 ( V_23 | V_33
| V_24 | V_25 ,
V_15 + F_4 ( 2 , V_26 ) ) ;
F_9 ( V_29 , V_15 + F_4 ( 2 , V_30 ) ) ;
break;
default:
break;
}
}
static int F_12 ( unsigned long V_34 , struct V_9 * V_13 )
{
F_9 ( V_34 , V_6 + F_4 ( 2 , V_28 ) ) ;
F_9 ( V_31 | V_32 ,
V_6 + F_4 ( 2 , V_21 ) ) ;
return 0 ;
}
static T_4 F_13 ( int V_35 , void * V_36 )
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
static void T_5 F_14 ( struct V_43 * V_44 , int V_45 )
{
struct V_22 * V_46 = V_44 -> V_22 [ 2 ] ;
int V_35 = V_44 -> V_35 [ 2 ] ;
V_10 . V_15 = V_44 -> V_15 ;
V_10 . V_22 = V_46 ;
V_47 . V_48 = & V_10 ;
V_23 = V_45 ;
V_10 . V_10 . V_49 = F_15 ( 32768 , V_50 , V_10 . V_10 . V_51 ) ;
V_10 . V_10 . V_52
= F_16 ( 0xffff , & V_10 . V_10 ) ;
V_10 . V_10 . V_53 = F_16 ( 1 , & V_10 . V_10 ) + 1 ;
V_10 . V_10 . V_54 = F_17 ( 0 ) ;
F_18 ( & V_10 . V_10 ) ;
F_19 ( V_35 , & V_47 ) ;
}
static void T_5 F_14 ( struct V_43 * V_44 , int V_45 )
{
}
static int T_5 F_20 ( void )
{
static char V_55 [] V_56
= V_57 L_1 ;
struct V_58 * V_59 ;
struct V_43 * V_44 ;
struct V_22 * V_60 ;
T_2 V_61 , V_62 = 0 ;
int V_63 = - 1 ;
int V_45 = - 1 ;
int V_64 ;
V_44 = F_21 ( V_65 , V_66 . V_67 ) ;
if ( ! V_44 ) {
F_22 ( L_2 ) ;
return - V_68 ;
}
V_6 = V_44 -> V_15 ;
V_59 = V_44 -> V_59 ;
V_60 = V_44 -> V_22 [ 0 ] ;
F_11 ( V_60 ) ;
V_61 = ( T_2 ) F_23 ( V_60 ) ;
for ( V_64 = 0 ; V_64 < 5 ; V_64 ++ ) {
unsigned V_69 = V_70 [ V_64 ] ;
unsigned V_71 ;
if ( ! V_69 ) {
V_45 = V_64 ;
continue;
}
V_71 = V_61 / V_69 ;
F_22 ( L_3 , V_61 , V_69 , V_64 , V_71 ) ;
if ( V_63 > 0 ) {
if ( V_71 < 5 * 1000 * 1000 )
continue;
}
V_62 = V_71 ;
V_63 = V_64 ;
}
V_66 . V_49 = F_24 ( V_62 , V_66 . V_51 ) ;
F_25 ( V_55 , V_66 . V_67 , V_65 ,
V_62 / 1000000 ,
( ( V_62 + 500000 ) % 1000000 ) / 1000 ) ;
F_11 ( V_44 -> V_22 [ 1 ] ) ;
F_9 ( V_63
| V_24
| V_72
| V_73
| V_74 ,
V_6 + F_4 ( 0 , V_26 ) ) ;
F_9 ( 0x0000 , V_6 + F_4 ( 0 , V_75 ) ) ;
F_9 ( 0x8000 , V_6 + F_4 ( 0 , V_28 ) ) ;
F_9 ( 0xff , V_6 + F_4 ( 0 , V_19 ) ) ;
F_9 ( V_31 , V_6 + F_4 ( 0 , V_21 ) ) ;
F_9 ( V_76
| V_24
| V_72 ,
V_6 + F_4 ( 1 , V_26 ) ) ;
F_9 ( 0xff , V_6 + F_4 ( 1 , V_19 ) ) ;
F_9 ( V_31 , V_6 + F_4 ( 1 , V_21 ) ) ;
F_9 ( V_77 , V_6 + V_78 ) ;
F_9 ( V_79 , V_6 + V_80 ) ;
F_26 ( & V_66 ) ;
F_14 ( V_44 , V_45 ) ;
return 0 ;
}
