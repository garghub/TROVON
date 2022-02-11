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
F_6 ( 8 , V_5 + 8 ) ;
return V_12 & 8 ;
}
static void F_11 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_14 . V_16 ;
T_2 V_4 = V_17 | V_18 ;
if ( V_16 -> V_19 <= 8 ||
( V_16 -> V_19 == 16 && V_16 -> V_20 . V_21 == 5 ) )
V_4 |= V_22 ;
else if ( V_14 -> V_14 . V_16 . V_19 <= 16 )
V_4 |= V_23 ;
else
V_4 = 0 ;
F_12 ( V_24 |
V_25 |
V_26 |
V_17 |
V_18 |
V_27 |
V_28 , V_4 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
V_14 -> V_29 = F_14 ( L_1 ) ;
if ( ! V_14 -> V_29 )
return - V_30 ;
return F_15 ( V_14 , V_31 ) ;
}
static void T_1 F_16 ( void )
{
#ifdef F_17
F_18 ( V_32 , 24000000 ) ;
#endif
}
static void T_1 F_19 ( void )
{
struct V_33 * V_34 ;
const char * V_35 ;
void T_3 * V_36 ;
int V_37 ;
int V_38 ;
V_37 = F_20 ( V_39 ,
L_2 , & V_35 ) ;
if ( F_21 ( V_37 ) )
return;
V_34 = F_22 ( V_35 ) ;
V_36 = F_23 ( V_34 , 0 ) ;
if ( F_21 ( ! V_36 ) )
return;
F_6 ( 0 , V_36 + V_40 ) ;
F_24 ( V_36 , V_34 -> V_41 ) ;
V_37 = F_20 ( V_39 ,
L_3 , & V_35 ) ;
if ( F_21 ( V_37 ) )
return;
V_34 = F_22 ( V_35 ) ;
V_36 = F_23 ( V_34 , 0 ) ;
if ( F_21 ( ! V_36 ) )
return;
V_38 = F_25 ( V_34 , 0 ) ;
F_6 ( 0 , V_36 + V_40 ) ;
F_26 ( V_36 , V_38 , V_34 -> V_41 ) ;
}
static void T_1 F_27 ( void )
{
F_28 ( V_42 ) ;
F_29 ( true ) ;
}
static void T_1 F_30 ( void )
{
struct V_33 * V_43 ;
struct V_33 * V_44 ;
struct V_11 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
T_2 V_50 ;
int V_37 ;
V_43 = F_22 ( L_4 ) ;
if ( ! V_43 )
return;
V_44 = F_22 ( L_5 ) ;
if ( ! V_44 )
return;
V_5 = F_23 ( V_44 , 0 ) ;
if ( ! V_5 )
return;
V_50 = F_5 ( V_5 ) ;
V_49 = F_31 ( sizeof( * V_49 ) , V_51 ) ;
if ( ! V_49 )
return;
V_37 = F_20 ( V_43 , L_6 ,
& V_49 -> V_52 ) ;
if ( V_37 )
return;
V_37 = F_20 ( V_43 , L_7 , & V_49 -> V_53 ) ;
if ( V_37 )
return;
V_49 -> V_54 = L_8 ;
V_49 -> V_55 = F_32 ( V_51 , L_9 ,
'A' + ( V_50 & 0x0f ) ) ;
V_47 = F_33 ( V_49 ) ;
if ( F_34 ( V_47 ) ) {
F_35 ( V_49 -> V_55 ) ;
F_35 ( V_49 ) ;
return;
}
V_45 = F_36 ( V_47 ) ;
if ( ! F_34 ( V_45 ) )
F_37 ( V_45 , V_50 ) ;
F_38 ( V_43 , V_56 ,
V_57 , V_45 ) ;
}
static void T_1 F_39 ( void )
{
F_2 ( V_58 , F_3 ( V_58 ) ) ;
V_5 = F_10 ( V_59 ) ;
F_1 () ;
}
static void T_1 F_40 ( void )
{
T_2 V_60 , V_61 , V_62 ;
V_60 = ~ ( ( ~ 0u ) << ( 11 - 0 ) ) ;
V_60 |= ( ~ ( ( ~ 0u ) << ( 29 - 22 ) ) ) << 22 ;
V_61 = ~ ( ( ~ 0u ) << ( 1 + V_63 - V_64 ) ) ;
V_62 = ~ ( ( ~ 0u ) << ( 1 + V_65 - V_66 ) ) ;
F_6 ( 0xffffffff , V_67 + V_68 ) ;
F_6 ( 0xffffffff , V_67 + V_69 ) ;
F_6 ( 0xffffffff , V_70 + V_68 ) ;
F_6 ( 0xffffffff , V_70 + V_69 ) ;
F_6 ( V_62 , V_71 + V_68 ) ;
F_6 ( V_62 , V_71 + V_69 ) ;
F_41 ( V_67 , L_10 , V_72 ,
- 1 , V_60 , NULL ) ;
F_41 ( V_70 , L_11 , V_64 ,
- 1 , V_61 , NULL ) ;
F_41 ( V_71 , L_12 , V_66 ,
V_73 , V_62 , NULL ) ;
F_29 ( true ) ;
}
static void T_1 F_42 ( void )
{
F_6 ( 0 , V_74 + V_40 ) ;
F_6 ( 0 , V_75 + V_40 ) ;
F_6 ( 0 , V_76 + V_40 ) ;
F_24 ( V_76 , L_13 ) ;
F_26 ( V_75 , V_77 , L_14 ) ;
}
static void T_1 F_43 ( void )
{
int V_78 ;
F_44 ( V_79 , F_3 ( V_79 ) ) ;
for ( V_78 = 0 ; V_78 < F_3 ( V_80 ) ; V_78 ++ ) {
struct V_81 * V_82 = V_80 [ V_78 ] ;
F_45 ( V_82 , & V_83 ) ;
}
F_46 ( true ) ;
}
