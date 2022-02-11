static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
T_2 V_4 ;
V_4 = F_5 ( V_5 + V_6 ) ;
V_4 |= V_7 ;
F_6 ( V_4 , V_5 + V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_2 * V_3 )
{
T_2 V_4 ;
V_4 = F_5 ( V_5 + V_6 ) ;
V_4 &= ~ ( V_8 | V_7 ) ;
F_6 ( V_4 , V_5 + V_6 ) ;
}
static void F_8 ( struct V_2 * V_9 , int V_10 )
{
T_2 V_4 ;
V_4 = F_5 ( V_5 + V_6 ) ;
if ( V_10 )
V_4 |= V_8 ;
else
V_4 &= ~ V_8 ;
F_6 ( V_4 , V_5 + V_6 ) ;
}
static unsigned int F_9 ( struct V_11 * V_3 )
{
unsigned int V_12 = F_5 ( F_10 ( 0xca000000 + 4 ) ) ;
F_6 ( 8 , F_10 ( V_13 + 8 ) ) ;
return V_12 & 8 ;
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_15 . V_17 ;
T_2 V_4 = V_18 | V_19 ;
if ( V_17 -> V_20 <= 8 ||
( V_17 -> V_20 == 16 && V_17 -> V_21 . V_22 == 5 ) )
V_4 |= V_23 ;
else if ( V_15 -> V_15 . V_17 . V_20 <= 16 )
V_4 |= V_24 ;
else
V_4 = 0 ;
F_12 ( V_25 |
V_26 |
V_27 |
V_18 |
V_19 |
V_28 |
V_29 , V_4 ) ;
}
static int F_13 ( struct V_14 * V_15 )
{
V_15 -> V_30 = F_14 ( L_1 ) ;
if ( ! V_15 -> V_30 )
return - V_31 ;
return F_15 ( V_15 , V_32 ) ;
}
static void T_1 F_16 ( void )
{
#ifdef F_17
F_18 ( V_33 , 24000000 ) ;
#endif
}
static void T_1 F_19 ( void )
{
struct V_34 * V_35 ;
const char * V_36 ;
void T_3 * V_37 ;
int V_38 ;
int V_39 ;
V_38 = F_20 ( V_40 ,
L_2 , & V_36 ) ;
if ( F_21 ( V_38 ) )
return;
V_35 = F_22 ( V_36 ) ;
V_37 = F_23 ( V_35 , 0 ) ;
if ( F_21 ( ! V_37 ) )
return;
F_6 ( 0 , V_37 + V_41 ) ;
F_24 ( V_37 , V_35 -> V_42 ) ;
V_38 = F_20 ( V_40 ,
L_3 , & V_36 ) ;
if ( F_21 ( V_38 ) )
return;
V_35 = F_22 ( V_36 ) ;
V_37 = F_23 ( V_35 , 0 ) ;
if ( F_21 ( ! V_37 ) )
return;
V_39 = F_25 ( V_35 , 0 ) ;
F_6 ( 0 , V_37 + V_41 ) ;
F_26 ( V_37 , V_39 , V_35 -> V_42 ) ;
}
static void T_1 F_27 ( void )
{
F_28 ( V_43 ) ;
F_29 ( true ) ;
}
static void T_1 F_30 ( void )
{
F_31 ( NULL , V_44 ,
V_45 , NULL ) ;
}
static void T_1 F_32 ( void )
{
T_2 V_46 , V_47 , V_48 ;
V_46 = ~ ( ( ~ 0u ) << ( 11 - V_49 ) ) ;
V_46 |= ( ~ ( ( ~ 0u ) << ( 29 - 22 ) ) ) << 22 ;
V_47 = ~ ( ( ~ 0u ) << ( 1 + V_50 - V_51 ) ) ;
V_48 = ~ ( ( ~ 0u ) << ( 1 + V_52 - V_53 ) ) ;
F_6 ( 0xffffffff , V_54 + V_55 ) ;
F_6 ( 0xffffffff , V_54 + V_56 ) ;
F_6 ( 0xffffffff , V_57 + V_55 ) ;
F_6 ( 0xffffffff , V_57 + V_56 ) ;
F_6 ( V_48 , V_58 + V_55 ) ;
F_6 ( V_48 , V_58 + V_56 ) ;
F_33 ( V_54 , L_4 , V_49 ,
- 1 , V_46 , NULL ) ;
F_33 ( V_57 , L_5 , V_51 ,
- 1 , V_47 , NULL ) ;
F_33 ( V_58 , L_6 , V_53 ,
V_59 , V_48 , NULL ) ;
F_29 ( true ) ;
}
static void T_1 F_34 ( void )
{
F_6 ( 0 , V_60 + V_41 ) ;
F_6 ( 0 , V_61 + V_41 ) ;
F_6 ( 0 , V_62 + V_41 ) ;
F_24 ( V_62 , L_7 ) ;
F_26 ( V_61 , V_63 , L_8 ) ;
}
static void T_1 F_35 ( void )
{
int V_64 ;
F_36 ( V_65 , F_3 ( V_65 ) ) ;
for ( V_64 = 0 ; V_64 < F_3 ( V_66 ) ; V_64 ++ ) {
struct V_67 * V_68 = V_66 [ V_64 ] ;
F_37 ( V_68 , & V_69 ) ;
}
F_38 ( true ) ;
}
