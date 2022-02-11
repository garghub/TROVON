static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_5 + V_6 ) ;
if ( V_3 )
V_4 |= V_7 ;
else
V_4 &= ~ V_7 ;
F_3 ( V_4 , V_5 + V_6 ) ;
}
unsigned int F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 , struct V_10 , V_9 ) ;
T_1 V_12 ;
if ( V_11 -> V_13 . V_14 == V_15 )
V_12 = 1 ;
else
V_12 = 2 ;
return F_2 ( V_5 + V_16 ) & V_12 ;
}
static void F_6 ( struct V_17 * V_18 )
{
void T_2 * V_19 = V_5 + V_20 ;
T_1 V_4 ;
V_4 = F_2 ( V_19 ) ;
V_4 &= ~ V_21 | V_22 ;
F_3 ( V_4 , V_19 ) ;
if ( F_7 ( L_1 ) && V_23 ) {
unsigned long V_24 ;
V_24 = F_2 ( V_25 ) ;
V_24 &= ~ 0x01 ;
F_3 ( V_24 , V_25 ) ;
}
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_26 * V_27 = & V_18 -> V_18 . V_27 ;
void T_2 * V_19 = V_5 + V_20 ;
T_1 V_4 ;
V_4 = F_2 ( V_19 ) ;
V_4 &= ~ V_28 ;
switch ( V_27 -> V_29 . V_30 ) {
case 5 :
V_4 |= V_31 ;
break;
case 6 :
if ( V_27 -> V_32 . V_33 == 0 )
V_4 |= V_34 ;
else
V_4 |= V_35 ;
break;
case 8 :
V_4 |= V_36 ;
break;
}
F_3 ( V_4 , V_19 ) ;
V_4 |= V_21 | V_22 ;
F_3 ( V_4 , V_19 ) ;
if ( F_7 ( L_1 ) && V_23 ) {
unsigned long V_24 ;
V_24 = F_2 ( V_25 ) ;
V_24 |= 0x01 ;
F_3 ( V_24 , V_25 ) ;
}
}
static int F_9 ( struct V_17 * V_18 )
{
void T_2 * V_19 = V_5 + V_20 ;
const char * V_37 ;
T_1 V_4 ;
V_23 = false ;
V_4 = F_2 ( V_19 ) & V_38 ;
if ( V_4 == V_39 )
V_37 = L_2 ;
else if ( V_4 == V_40 ) {
V_37 = L_3 ;
V_23 = true ;
} else if ( V_4 == V_41 )
V_37 = L_4 ;
else if ( V_4 == V_42 )
V_37 = L_5 ;
else {
F_10 ( V_43 L_6 ,
V_4 ) ;
V_37 = L_5 ;
}
V_18 -> V_44 = F_11 ( V_37 ) ;
if ( ! V_18 -> V_44 )
return - V_45 ;
return F_12 ( V_18 , V_46 ) ;
}
static void F_13 ( struct V_17 * V_18 , struct V_47 * V_48 )
{
F_14 ( V_18 , V_48 ) ;
if ( V_18 -> V_18 . V_27 . V_29 . V_30 == 6 )
V_48 -> V_49 &= ~ V_50 ;
}
static void T_3 F_15 ( void )
{
F_16 () ;
F_17 ( V_51 , F_18 ( V_51 ) ) ;
}
static void T_3 F_19 ( void )
{
T_1 V_4 ;
V_4 = F_2 ( F_20 ( V_52 ) ) ;
F_3 ( ( V_53 << V_54 ) |
( V_53 << V_55 ) |
( V_53 << V_56 ) |
( V_53 << V_57 ) | V_4 ,
F_20 ( V_52 ) ) ;
}
static void T_3 F_21 ( void )
{
T_1 V_4 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
V_59 = F_22 ( NULL , NULL , L_7 ) ;
if ( ! V_59 )
return;
V_4 = F_2 ( V_5 + V_62 ) ;
if ( V_4 & 1 ) {
F_3 ( 1 , V_5 + V_62 ) ;
return;
}
V_61 = F_23 ( sizeof( * V_61 ) , V_63 ) ;
if ( ! V_61 )
return;
V_61 -> V_64 = F_24 ( L_8 , V_63 ) ;
V_61 -> V_65 = F_24 ( L_9 , V_63 ) ;
V_61 -> V_30 = sizeof( L_9 ) ;
F_25 ( V_59 , V_61 ) ;
F_26 ( L_10 ) ;
}
static void T_3 F_27 ( void )
{
struct V_58 * V_59 ;
V_59 = F_22 ( NULL , NULL , L_11 ) ;
if ( V_59 )
V_5 = F_28 ( V_59 , 0 ) ;
F_29 ( ! V_5 ) ;
V_25 = F_30 ( V_66 , V_67 ) ;
F_21 () ;
F_31 ( & V_68 ) ;
F_32 ( NULL , V_69 ,
V_70 , NULL ) ;
}
