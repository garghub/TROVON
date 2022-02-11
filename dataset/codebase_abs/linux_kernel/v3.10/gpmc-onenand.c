static void F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
const int V_5 = 15 ;
const int V_6 = 12 ;
const int V_7 = 7 ;
const int V_8 = 76 ;
const int V_9 = 76 ;
const int V_10 = 20 ;
const int V_11 = 20 ;
const int V_12 = 40 ;
const int V_13 = 30 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_14 = F_2 ( int , V_6 , V_5 ) * 1000 ;
V_4 . V_15 = V_4 . V_14 ;
V_4 . V_7 = V_7 * 1000 ;
V_4 . V_9 = V_9 * 1000 ;
V_4 . V_8 = V_8 * 1000 ;
V_4 . V_10 = V_10 * 1000 ;
V_4 . V_16 = V_11 * 1000 ;
V_4 . V_17 = V_4 . V_16 ;
V_4 . V_12 = V_12 * 1000 ;
V_4 . V_13 = V_13 * 1000 ;
F_3 ( V_2 , & V_18 , & V_4 ) ;
}
static void F_4 ( void T_1 * V_19 )
{
T_2 V_20 ;
V_20 = F_5 ( V_19 + V_21 ) ;
V_20 &= ~ V_22 & ~ V_23 ;
F_6 ( V_20 , V_19 + V_21 ) ;
}
static void F_7 ( void T_1 * V_19 )
{
T_2 V_20 ;
V_20 = F_5 ( V_19 + V_21 ) ;
V_20 &= ~ ( ( 0x7 << V_24 ) | ( 0x7 << 9 ) ) ;
V_20 |= ( V_25 << V_24 ) |
V_26 ;
if ( V_27 & V_28 )
V_20 |= V_22 ;
else
V_20 &= ~ V_22 ;
if ( V_27 & V_29 )
V_20 |= V_23 ;
else
V_20 &= ~ V_23 ;
if ( V_27 & V_30 )
V_20 |= V_31 ;
else
V_20 &= ~ V_31 ;
if ( V_27 & V_32 )
V_20 |= V_33 ;
else
V_20 &= ~ V_33 ;
F_6 ( V_20 , V_19 + V_21 ) ;
}
static int F_8 ( struct V_34 * V_35 ,
void T_1 * V_19 )
{
T_3 V_36 = F_5 ( V_19 + V_37 ) ;
int V_38 ;
switch ( ( V_36 >> 4 ) & 0xf ) {
case 0 :
V_38 = 40 ;
break;
case 1 :
V_38 = 54 ;
break;
case 2 :
V_38 = 66 ;
break;
case 3 :
V_38 = 83 ;
break;
case 4 :
V_38 = 104 ;
break;
default:
V_38 = 54 ;
break;
}
return V_38 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_39 ,
int V_38 )
{
struct V_3 V_4 ;
const int V_5 = 15 ;
const int V_6 = 12 ;
const int V_11 = 20 ;
const int V_12 = 40 ;
const int V_13 = 30 ;
int V_40 , V_41 , V_42 , V_43 , V_44 , V_7 , V_45 ;
int div , V_46 ;
if ( V_39 & V_47 )
V_27 = V_28 ;
else if ( V_39 & V_48 )
V_27 = V_28 | V_29 ;
switch ( V_38 ) {
case 104 :
V_40 = 9600 ;
V_41 = 3 ;
V_42 = 4 ;
V_43 = 2 ;
V_44 = 3 ;
V_7 = 6 ;
V_45 = 6 ;
break;
case 83 :
V_40 = 12000 ;
V_41 = 5 ;
V_42 = 4 ;
V_43 = 2 ;
V_44 = 6 ;
V_7 = 6 ;
V_45 = 9 ;
break;
case 66 :
V_40 = 15000 ;
V_41 = 6 ;
V_42 = 5 ;
V_43 = 2 ;
V_44 = 6 ;
V_7 = 6 ;
V_45 = 11 ;
break;
default:
V_40 = 18500 ;
V_41 = 7 ;
V_42 = 7 ;
V_43 = 7 ;
V_44 = 9 ;
V_7 = 7 ;
V_45 = 15 ;
V_27 &= ~ V_29 ;
break;
}
div = F_10 ( V_40 ) ;
V_46 = F_11 ( div ) ;
if ( V_46 < 15 )
V_27 |= V_30 ;
else
V_27 &= ~ V_30 ;
if ( V_46 < 12 )
V_27 |= V_32 ;
else
V_27 &= ~ V_32 ;
if ( V_27 & V_32 )
V_25 = 8 ;
else if ( V_27 & V_30 )
V_25 = 6 ;
else if ( V_46 >= 25 )
V_25 = 3 ;
else
V_25 = 4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( V_27 & V_28 )
V_49 . V_50 = true ;
if ( V_27 & V_29 ) {
V_49 . V_51 = true ;
V_49 . V_52 = true ;
} else {
V_4 . V_15 = F_12 ( V_6 , V_5 ) * 1000 ;
V_4 . V_12 = V_12 * 1000 ;
V_4 . V_13 = V_13 * 1000 ;
V_4 . V_7 = V_7 * 1000 ;
}
V_4 . V_53 = true ;
V_4 . V_54 = true ;
V_4 . V_55 = true ;
V_4 . V_56 = true ;
V_4 . V_57 = V_40 ;
V_4 . V_58 = V_4 . V_57 ;
V_4 . V_41 = V_41 * 1000 ;
V_4 . V_42 = V_42 * 1000 ;
V_4 . V_43 = V_43 * 1000 ;
V_4 . V_44 = V_44 * 1000 ;
V_4 . V_59 = ( V_25 + 1 ) ;
V_4 . V_16 = V_11 * 1000 ;
V_4 . V_17 = V_4 . V_16 ;
V_4 . V_60 = 1 ;
V_4 . V_45 = V_45 * 1000 + V_40 ;
F_3 ( V_2 , & V_49 , & V_4 ) ;
}
static int F_13 ( void T_1 * V_19 )
{
struct V_1 V_2 ;
int V_61 ;
if ( V_62 -> V_63 )
F_14 ( V_62 -> V_63 ,
& V_18 ) ;
F_4 ( V_19 ) ;
F_1 ( & V_2 ) ;
V_61 = F_15 ( V_62 -> V_64 , & V_18 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_16 ( V_62 -> V_64 , & V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
F_4 ( V_19 ) ;
return 0 ;
}
static int F_17 ( void T_1 * V_19 , int * V_65 )
{
int V_61 , V_38 = * V_65 ;
struct V_1 V_2 ;
if ( ! V_38 ) {
V_38 = F_8 ( V_62 , V_19 ) ;
F_7 ( V_19 ) ;
}
if ( V_62 -> V_63 ) {
F_14 ( V_62 -> V_63 ,
& V_49 ) ;
} else {
if ( ! F_18 () )
V_49 . V_66 = true ;
}
F_9 ( & V_2 , V_62 -> V_39 , V_38 ) ;
V_61 = F_15 ( V_62 -> V_64 , & V_49 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_16 ( V_62 -> V_64 , & V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
F_7 ( V_19 ) ;
* V_65 = V_38 ;
return 0 ;
}
static int F_19 ( void T_1 * V_19 , int * V_65 )
{
struct V_67 * V_68 = & V_69 . V_68 ;
unsigned V_70 = V_47 | V_48 ;
int V_61 ;
V_61 = F_13 ( V_19 ) ;
if ( V_61 ) {
F_20 ( V_68 , L_1 ) ;
return V_61 ;
}
if ( ! ( V_62 -> V_39 & V_70 ) )
return 0 ;
V_61 = F_17 ( V_19 , V_65 ) ;
if ( V_61 )
F_20 ( V_68 , L_2 ) ;
return V_61 ;
}
void F_21 ( struct V_34 * V_71 )
{
int V_72 ;
struct V_67 * V_68 = & V_69 . V_68 ;
V_62 = V_71 ;
V_62 -> V_73 = F_19 ;
V_69 . V_68 . V_74 = V_62 ;
if ( F_22 () &&
( V_62 -> V_39 & V_48 ) ) {
F_23 ( V_68 , L_3 ) ;
V_62 -> V_39 &= ~ V_48 ;
V_62 -> V_39 |= V_47 ;
}
if ( F_18 () )
V_62 -> V_39 |= V_75 ;
else
V_62 -> V_39 &= ~ V_75 ;
V_72 = F_24 ( V_62 -> V_64 , V_76 ,
( unsigned long * ) & V_77 . V_78 ) ;
if ( V_72 < 0 ) {
F_20 ( V_68 , L_4 ,
V_62 -> V_64 , V_72 ) ;
return;
}
V_77 . V_79 = V_77 . V_78 +
V_76 - 1 ;
if ( F_25 ( & V_69 ) < 0 ) {
F_20 ( V_68 , L_5 ) ;
F_26 ( V_62 -> V_64 ) ;
return;
}
}
