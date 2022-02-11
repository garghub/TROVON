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
T_2 V_20 = V_24 | V_25 ;
V_20 |= ( V_26 << V_27 ) |
V_28 ;
if ( V_29 & V_30 )
V_20 |= V_22 ;
else
V_20 &= ~ V_22 ;
if ( V_29 & V_31 )
V_20 |= V_23 ;
else
V_20 &= ~ V_23 ;
if ( V_29 & V_32 )
V_20 |= V_33 ;
else
V_20 &= ~ V_33 ;
if ( V_29 & V_34 )
V_20 |= V_35 ;
else
V_20 &= ~ V_35 ;
F_6 ( V_20 , V_19 + V_21 ) ;
}
static int F_8 ( struct V_36 * V_37 ,
void T_1 * V_19 )
{
T_3 V_38 = F_5 ( V_19 + V_39 ) ;
int V_40 ;
switch ( ( V_38 >> 4 ) & 0xf ) {
case 0 :
V_40 = 40 ;
break;
case 1 :
V_40 = 54 ;
break;
case 2 :
V_40 = 66 ;
break;
case 3 :
V_40 = 83 ;
break;
case 4 :
V_40 = 104 ;
break;
default:
F_9 ( L_1 ) ;
V_40 = 0 ;
}
return V_40 ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned int V_41 ,
int V_40 )
{
struct V_3 V_4 ;
const int V_5 = 15 ;
const int V_6 = 12 ;
const int V_11 = 20 ;
const int V_12 = 40 ;
const int V_13 = 30 ;
int V_42 , V_43 , V_44 , V_45 , V_46 , V_7 , V_47 ;
int div , V_48 ;
if ( V_41 & V_49 )
V_29 = V_30 ;
else if ( V_41 & V_50 )
V_29 = V_30 | V_31 ;
switch ( V_40 ) {
case 104 :
V_42 = 9600 ;
V_43 = 3 ;
V_44 = 4 ;
V_45 = 2 ;
V_46 = 3 ;
V_7 = 6 ;
V_47 = 6 ;
break;
case 83 :
V_42 = 12000 ;
V_43 = 5 ;
V_44 = 4 ;
V_45 = 2 ;
V_46 = 6 ;
V_7 = 6 ;
V_47 = 9 ;
break;
case 66 :
V_42 = 15000 ;
V_43 = 6 ;
V_44 = 5 ;
V_45 = 2 ;
V_46 = 6 ;
V_7 = 6 ;
V_47 = 11 ;
break;
default:
V_42 = 18500 ;
V_43 = 7 ;
V_44 = 7 ;
V_45 = 7 ;
V_46 = 9 ;
V_7 = 7 ;
V_47 = 15 ;
V_29 &= ~ V_31 ;
break;
}
div = F_11 ( V_42 ) ;
V_48 = F_12 ( div ) ;
if ( V_48 < 15 )
V_29 |= V_32 ;
else
V_29 &= ~ V_32 ;
if ( V_48 < 12 )
V_29 |= V_34 ;
else
V_29 &= ~ V_34 ;
if ( V_29 & V_34 )
V_26 = 8 ;
else if ( V_29 & V_32 )
V_26 = 6 ;
else if ( V_48 >= 25 )
V_26 = 3 ;
else
V_26 = 4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( V_29 & V_30 )
V_51 . V_52 = true ;
if ( V_29 & V_31 ) {
V_51 . V_53 = true ;
V_51 . V_54 = true ;
} else {
V_4 . V_15 = F_13 ( V_6 , V_5 ) * 1000 ;
V_4 . V_12 = V_12 * 1000 ;
V_4 . V_13 = V_13 * 1000 ;
V_4 . V_7 = V_7 * 1000 ;
}
V_4 . V_55 = true ;
V_4 . V_56 = true ;
V_4 . V_57 = true ;
V_4 . V_58 = true ;
V_4 . V_59 = V_42 ;
V_4 . V_60 = V_4 . V_59 ;
V_4 . V_43 = V_43 * 1000 ;
V_4 . V_44 = V_44 * 1000 ;
V_4 . V_45 = V_45 * 1000 ;
V_4 . V_46 = V_46 * 1000 ;
V_4 . V_61 = ( V_26 + 1 ) ;
V_4 . V_16 = V_11 * 1000 ;
V_4 . V_17 = V_4 . V_16 ;
V_4 . V_62 = 1 ;
V_4 . V_47 = V_47 * 1000 + V_42 ;
F_3 ( V_2 , & V_51 , & V_4 ) ;
}
static int F_14 ( void T_1 * V_19 )
{
struct V_1 V_2 ;
int V_63 ;
if ( V_64 -> V_65 ) {
F_15 ( V_64 -> V_65 ,
& V_18 ) ;
if ( V_18 . V_52 || V_18 . V_53 ) {
if ( V_18 . V_53 )
V_64 -> V_41 |=
V_50 ;
else
V_64 -> V_41 |= V_49 ;
V_18 . V_52 = false ;
}
}
V_18 . V_53 = true ;
F_1 ( & V_2 ) ;
V_63 = F_16 ( V_64 -> V_66 , & V_18 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_17 ( V_64 -> V_66 , & V_2 , & V_18 ) ;
if ( V_63 < 0 )
return V_63 ;
F_4 ( V_19 ) ;
return 0 ;
}
static int F_18 ( void T_1 * V_19 , int * V_67 )
{
int V_63 , V_40 = * V_67 ;
struct V_1 V_2 ;
if ( ! V_40 ) {
V_40 = F_8 ( V_64 , V_19 ) ;
if ( ! V_40 )
return - V_68 ;
F_7 ( V_19 ) ;
}
if ( V_64 -> V_65 ) {
F_15 ( V_64 -> V_65 ,
& V_51 ) ;
} else {
if ( ! F_19 () )
V_51 . V_69 = true ;
}
F_10 ( & V_2 , V_64 -> V_41 , V_40 ) ;
V_63 = F_16 ( V_64 -> V_66 , & V_51 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_17 ( V_64 -> V_66 , & V_2 , & V_51 ) ;
if ( V_63 < 0 )
return V_63 ;
F_7 ( V_19 ) ;
* V_67 = V_40 ;
return 0 ;
}
static int F_20 ( void T_1 * V_19 , int * V_67 )
{
struct V_70 * V_71 = & V_72 . V_71 ;
unsigned V_73 = V_49 | V_50 ;
int V_63 ;
V_63 = F_14 ( V_19 ) ;
if ( V_63 ) {
F_21 ( V_71 , L_2 ) ;
return V_63 ;
}
if ( ! ( V_64 -> V_41 & V_73 ) )
return 0 ;
V_63 = F_18 ( V_19 , V_67 ) ;
if ( V_63 )
F_21 ( V_71 , L_3 ) ;
return V_63 ;
}
void F_22 ( struct V_36 * V_74 )
{
int V_75 ;
struct V_70 * V_71 = & V_72 . V_71 ;
V_64 = V_74 ;
V_64 -> V_76 = F_20 ;
V_72 . V_71 . V_77 = V_64 ;
if ( F_23 () &&
( V_64 -> V_41 & V_50 ) ) {
F_24 ( V_71 , L_4 ) ;
V_64 -> V_41 &= ~ V_50 ;
V_64 -> V_41 |= V_49 ;
}
if ( F_19 () )
V_64 -> V_41 |= V_78 ;
else
V_64 -> V_41 &= ~ V_78 ;
V_75 = F_25 ( V_64 -> V_66 , V_79 ,
( unsigned long * ) & V_80 . V_81 ) ;
if ( V_75 < 0 ) {
F_21 ( V_71 , L_5 ,
V_64 -> V_66 , V_75 ) ;
return;
}
V_80 . V_82 = V_80 . V_81 +
V_79 - 1 ;
if ( F_26 ( & V_72 ) < 0 ) {
F_21 ( V_71 , L_6 ) ;
F_27 ( V_64 -> V_66 ) ;
return;
}
}
