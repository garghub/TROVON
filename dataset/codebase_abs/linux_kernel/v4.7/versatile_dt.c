unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
T_1 V_5 ;
if ( V_4 -> V_6 . V_7 == V_8 )
V_5 = 1 ;
else
V_5 = 2 ;
return F_3 ( V_9 + V_10 ) & V_5 ;
}
static void F_4 ( struct V_11 * V_12 )
{
void T_2 * V_13 = V_9 + V_14 ;
T_1 V_15 ;
V_15 = F_3 ( V_13 ) ;
V_15 &= ~ V_16 | V_17 ;
F_5 ( V_15 , V_13 ) ;
if ( F_6 ( L_1 ) && V_18 ) {
unsigned long V_19 ;
V_19 = F_3 ( V_20 ) ;
V_19 &= ~ 0x01 ;
F_5 ( V_19 , V_20 ) ;
}
}
static void F_7 ( struct V_11 * V_12 )
{
struct V_21 * V_22 = & V_12 -> V_12 . V_22 ;
void T_2 * V_13 = V_9 + V_14 ;
T_1 V_15 ;
V_15 = F_3 ( V_13 ) ;
V_15 &= ~ V_23 ;
switch ( V_22 -> V_24 . V_25 ) {
case 5 :
V_15 |= V_26 ;
break;
case 6 :
if ( V_22 -> V_27 . V_28 == 0 )
V_15 |= V_29 ;
else
V_15 |= V_30 ;
break;
case 8 :
V_15 |= V_31 ;
break;
}
F_5 ( V_15 , V_13 ) ;
V_15 |= V_16 | V_17 ;
F_5 ( V_15 , V_13 ) ;
if ( F_6 ( L_1 ) && V_18 ) {
unsigned long V_19 ;
V_19 = F_3 ( V_20 ) ;
V_19 |= 0x01 ;
F_5 ( V_19 , V_20 ) ;
}
}
static int F_8 ( struct V_11 * V_12 )
{
void T_2 * V_13 = V_9 + V_14 ;
const char * V_32 ;
T_1 V_15 ;
V_18 = false ;
V_15 = F_3 ( V_13 ) & V_33 ;
if ( V_15 == V_34 )
V_32 = L_2 ;
else if ( V_15 == V_35 ) {
V_32 = L_3 ;
V_18 = true ;
} else if ( V_15 == V_36 )
V_32 = L_4 ;
else if ( V_15 == V_37 )
V_32 = L_5 ;
else {
F_9 ( V_38 L_6 ,
V_15 ) ;
V_32 = L_5 ;
}
V_12 -> V_39 = F_10 ( V_32 ) ;
if ( ! V_12 -> V_39 )
return - V_40 ;
return F_11 ( V_12 , V_41 ) ;
}
static void F_12 ( struct V_11 * V_12 , struct V_42 * V_43 )
{
F_13 ( V_12 , V_43 ) ;
if ( V_12 -> V_12 . V_22 . V_24 . V_25 == 6 )
V_43 -> V_44 &= ~ V_45 ;
}
static void T_3 F_14 ( void )
{
F_15 () ;
F_16 ( V_46 , F_17 ( V_46 ) ) ;
}
static void T_3 F_18 ( void )
{
T_1 V_15 ;
V_15 = F_3 ( F_19 ( V_47 ) ) ;
F_5 ( ( V_48 << V_49 ) |
( V_48 << V_50 ) |
( V_48 << V_51 ) |
( V_48 << V_52 ) | V_15 ,
F_19 ( V_47 ) ) ;
}
static void T_3 F_20 ( void )
{
T_1 V_15 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
V_54 = F_21 ( NULL , NULL , L_7 ) ;
if ( ! V_54 )
return;
V_15 = F_3 ( V_9 + V_57 ) ;
if ( V_15 & 1 ) {
F_5 ( 1 , V_9 + V_57 ) ;
return;
}
V_56 = F_22 ( sizeof( * V_56 ) , V_58 ) ;
if ( ! V_56 )
return;
V_56 -> V_59 = F_23 ( L_8 , V_58 ) ;
V_56 -> V_60 = F_23 ( L_9 , V_58 ) ;
V_56 -> V_25 = sizeof( L_9 ) ;
F_24 ( V_54 , V_56 ) ;
F_25 ( L_10 ) ;
}
static void T_3 F_26 ( void )
{
struct V_53 * V_54 ;
V_54 = F_21 ( NULL , NULL , L_11 ) ;
if ( V_54 )
V_9 = F_27 ( V_54 , 0 ) ;
F_28 ( ! V_9 ) ;
V_20 = F_29 ( V_61 , V_62 ) ;
F_20 () ;
F_30 ( NULL , V_63 ,
V_64 , NULL ) ;
}
