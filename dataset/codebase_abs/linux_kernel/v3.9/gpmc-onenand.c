static struct V_1 F_1 ( void )
{
struct V_2 V_3 ;
struct V_1 V_4 ;
const int V_5 = 15 ;
const int V_6 = 12 ;
const int V_7 = 7 ;
const int V_8 = 76 ;
const int V_9 = 76 ;
const int V_10 = 20 ;
const int V_11 = 20 ;
const int V_12 = 40 ;
const int V_13 = 30 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_14 = true ;
V_3 . V_15 = F_2 ( int , V_6 , V_5 ) * 1000 ;
V_3 . V_16 = V_3 . V_15 ;
V_3 . V_7 = V_7 * 1000 ;
V_3 . V_9 = V_9 * 1000 ;
V_3 . V_8 = V_8 * 1000 ;
V_3 . V_10 = V_10 * 1000 ;
V_3 . V_17 = V_11 * 1000 ;
V_3 . V_18 = V_3 . V_17 ;
V_3 . V_12 = V_12 * 1000 ;
V_3 . V_13 = V_13 * 1000 ;
F_3 ( & V_4 , & V_3 ) ;
return V_4 ;
}
static int F_4 ( int V_19 , struct V_1 * V_4 )
{
F_5 ( V_19 , V_20 ,
V_21 |
V_22 ) ;
return F_6 ( V_19 , V_4 ) ;
}
static void F_7 ( void T_1 * V_23 )
{
T_2 V_24 ;
V_24 = F_8 ( V_23 + V_25 ) ;
V_24 &= ~ V_26 & ~ V_27 ;
F_9 ( V_24 , V_23 + V_25 ) ;
}
static void F_10 ( void T_1 * V_23 )
{
T_2 V_24 ;
V_24 = F_8 ( V_23 + V_25 ) ;
V_24 &= ~ ( ( 0x7 << V_28 ) | ( 0x7 << 9 ) ) ;
V_24 |= ( V_29 << V_28 ) |
V_30 ;
if ( V_31 & V_32 )
V_24 |= V_26 ;
else
V_24 &= ~ V_26 ;
if ( V_31 & V_33 )
V_24 |= V_27 ;
else
V_24 &= ~ V_27 ;
if ( V_31 & V_34 )
V_24 |= V_35 ;
else
V_24 &= ~ V_35 ;
if ( V_31 & V_36 )
V_24 |= V_37 ;
else
V_24 &= ~ V_37 ;
F_9 ( V_24 , V_23 + V_25 ) ;
}
static int F_11 ( struct V_38 * V_39 ,
void T_1 * V_23 )
{
T_3 V_40 = F_8 ( V_23 + V_41 ) ;
int V_42 ;
switch ( ( V_40 >> 4 ) & 0xf ) {
case 0 :
V_42 = 40 ;
break;
case 1 :
V_42 = 54 ;
break;
case 2 :
V_42 = 66 ;
break;
case 3 :
V_42 = 83 ;
break;
case 4 :
V_42 = 104 ;
break;
default:
V_42 = 54 ;
break;
}
return V_42 ;
}
static struct V_1
F_12 ( struct V_38 * V_39 ,
int V_42 )
{
struct V_2 V_3 ;
struct V_1 V_4 ;
const int V_5 = 15 ;
const int V_6 = 12 ;
const int V_11 = 20 ;
const int V_12 = 40 ;
const int V_13 = 30 ;
int V_43 , V_44 , V_45 , V_46 , V_47 , V_7 , V_48 ;
int div , V_49 ;
if ( V_39 -> V_50 & V_51 )
V_31 = V_32 ;
else if ( V_39 -> V_50 & V_52 )
V_31 = V_32 | V_33 ;
switch ( V_42 ) {
case 104 :
V_43 = 9600 ;
V_44 = 3 ;
V_45 = 4 ;
V_46 = 2 ;
V_47 = 3 ;
V_7 = 6 ;
V_48 = 6 ;
break;
case 83 :
V_43 = 12000 ;
V_44 = 5 ;
V_45 = 4 ;
V_46 = 2 ;
V_47 = 6 ;
V_7 = 6 ;
V_48 = 9 ;
break;
case 66 :
V_43 = 15000 ;
V_44 = 6 ;
V_45 = 5 ;
V_46 = 2 ;
V_47 = 6 ;
V_7 = 6 ;
V_48 = 11 ;
break;
default:
V_43 = 18500 ;
V_44 = 7 ;
V_45 = 7 ;
V_46 = 7 ;
V_47 = 9 ;
V_7 = 7 ;
V_48 = 15 ;
V_31 &= ~ V_33 ;
break;
}
div = F_13 ( V_43 ) ;
V_49 = F_14 ( div ) ;
if ( V_49 < 15 )
V_31 |= V_34 ;
else
V_31 &= ~ V_34 ;
if ( V_49 < 12 )
V_31 |= V_36 ;
else
V_31 &= ~ V_36 ;
if ( V_31 & V_36 )
V_29 = 8 ;
else if ( V_31 & V_34 )
V_29 = 6 ;
else if ( V_49 >= 25 )
V_29 = 3 ;
else
V_29 = 4 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_14 = true ;
V_3 . V_53 = true ;
if ( V_31 & V_33 ) {
V_3 . V_54 = true ;
} else {
V_3 . V_16 = F_15 ( V_6 , V_5 ) * 1000 ;
V_3 . V_12 = V_12 * 1000 ;
V_3 . V_13 = V_13 * 1000 ;
V_3 . V_7 = V_7 * 1000 ;
}
V_3 . V_55 = true ;
V_3 . V_56 = true ;
V_3 . V_57 = true ;
V_3 . V_58 = true ;
V_3 . V_59 = V_43 ;
V_3 . V_60 = V_3 . V_59 ;
V_3 . V_44 = V_44 * 1000 ;
V_3 . V_45 = V_45 * 1000 ;
V_3 . V_46 = V_46 * 1000 ;
V_3 . V_47 = V_47 * 1000 ;
V_3 . V_61 = ( V_29 + 1 ) ;
V_3 . V_17 = V_11 * 1000 ;
V_3 . V_18 = V_3 . V_17 ;
V_3 . V_62 = 1 ;
V_3 . V_48 = V_48 * 1000 + V_43 ;
F_3 ( & V_4 , & V_3 ) ;
return V_4 ;
}
static int F_16 ( int V_19 , struct V_1 * V_4 )
{
unsigned V_53 = V_31 & V_32 ;
unsigned V_54 = V_31 & V_33 ;
F_5 ( V_19 , V_20 ,
V_63 |
V_64 |
( V_53 ? V_65 : 0 ) |
( V_54 ? V_66 : 0 ) |
( V_54 ? V_67 : 0 ) |
F_17 ( 2 ) |
( F_18 () ? 0 :
( V_68 |
F_19 ( 0 ) ) ) |
V_21 |
V_69 |
V_22 ) ;
return F_6 ( V_19 , V_4 ) ;
}
static int F_20 ( void T_1 * V_23 )
{
struct V_1 V_4 ;
int V_70 ;
F_7 ( V_23 ) ;
V_4 = F_1 () ;
V_70 = F_4 ( V_71 -> V_19 , & V_4 ) ;
if ( F_21 ( V_70 ) )
return V_70 ;
F_7 ( V_23 ) ;
return 0 ;
}
static int F_22 ( void T_1 * V_23 , int * V_72 )
{
int V_70 , V_42 = * V_72 ;
struct V_1 V_4 ;
if ( ! V_42 ) {
V_42 = F_11 ( V_71 , V_23 ) ;
F_10 ( V_23 ) ;
}
V_4 = F_12 ( V_71 , V_42 ) ;
V_70 = F_16 ( V_71 -> V_19 , & V_4 ) ;
if ( F_21 ( V_70 ) )
return V_70 ;
F_10 ( V_23 ) ;
* V_72 = V_42 ;
return 0 ;
}
static int F_23 ( void T_1 * V_23 , int * V_72 )
{
struct V_73 * V_74 = & V_75 . V_74 ;
unsigned V_76 = V_51 | V_52 ;
int V_70 ;
V_70 = F_20 ( V_23 ) ;
if ( V_70 ) {
F_24 ( V_74 , L_1 ) ;
return V_70 ;
}
if ( ! ( V_71 -> V_50 & V_76 ) )
return 0 ;
V_70 = F_22 ( V_23 , V_72 ) ;
if ( V_70 )
F_24 ( V_74 , L_2 ) ;
return V_70 ;
}
void F_25 ( struct V_38 * V_77 )
{
int V_78 ;
V_71 = V_77 ;
V_71 -> V_79 = F_23 ;
V_75 . V_74 . V_80 = V_71 ;
if ( F_26 () &&
( V_71 -> V_50 & V_52 ) ) {
F_27 ( V_81 L_3 ) ;
V_71 -> V_50 &= ~ V_52 ;
V_71 -> V_50 |= V_51 ;
}
if ( F_18 () )
V_71 -> V_50 |= V_82 ;
else
V_71 -> V_50 &= ~ V_82 ;
V_78 = F_28 ( V_71 -> V_19 , V_83 ,
( unsigned long * ) & V_84 . V_85 ) ;
if ( V_78 < 0 ) {
F_29 ( L_4 , V_86 ) ;
return;
}
V_84 . V_87 = V_84 . V_85 +
V_83 - 1 ;
if ( F_30 ( & V_75 ) < 0 ) {
F_29 ( L_5 , V_86 ) ;
F_31 ( V_71 -> V_19 ) ;
return;
}
}
