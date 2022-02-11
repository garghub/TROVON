static int F_1 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_4 , V_1 , V_2 ) ;
}
static int F_4 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_5 , V_1 , V_2 ) ;
}
static int F_5 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_6 , V_1 , V_2 ) ;
}
static int F_6 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_7 , V_1 , V_2 ) ;
}
static int F_7 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_8 , V_1 , V_2 ) ;
}
static int F_8 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_9 , V_1 , V_2 ) ;
}
static int F_9 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_10 , V_1 , V_2 ) ;
}
static int F_10 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_11 , V_1 , V_2 ) ;
}
static int F_11 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_12 , V_1 , V_2 ) ;
}
static int F_12 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_13 , V_1 , V_2 ) ;
}
static int F_13 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_14 , V_1 , V_2 ) ;
}
static int F_14 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_15 , V_1 , V_2 ) ;
}
static int F_15 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_16 , V_1 , V_2 ) ;
}
static int F_16 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_17 , V_1 , V_2 ) ;
}
static int F_17 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_18 , V_1 , V_2 ) ;
}
static int F_18 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_19 , V_1 , V_2 ) ;
}
static int F_19 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_20 , V_1 , V_2 ) ;
}
static unsigned long F_20 ( struct V_1 * V_1 )
{
return V_1 -> V_21 ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_21 )
{
unsigned int V_22 , V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int V_28 ;
if ( V_1 -> V_21 == V_21 )
return 0 ;
if ( V_1 -> V_29 )
V_26 = F_22 ( V_1 -> V_29 ) ;
else
V_26 = V_30 . V_21 ;
if ( V_26 != 24000000 ) {
F_23 ( L_1 ) ;
return - V_31 ;
}
V_22 = F_24 ( V_32 ) ;
V_22 &= ~ ( 0x1 << 27 | \
V_33 << V_34 | \
V_35 << V_36 | \
V_37 << V_38 ) ;
for ( V_24 = 0 ; V_24 < F_25 ( V_39 ) ; V_24 ++ ) {
if ( V_39 [ V_24 ] [ 0 ] == V_21 ) {
V_23 = V_39 [ V_24 ] [ 5 ] << 0 ;
V_22 |= V_39 [ V_24 ] [ 1 ] << 27 ;
V_22 |= V_39 [ V_24 ] [ 2 ] << V_34 ;
V_22 |= V_39 [ V_24 ] [ 3 ] << V_36 ;
V_22 |= V_39 [ V_24 ] [ 4 ] << V_38 ;
break;
}
}
if ( V_24 == F_25 ( V_39 ) ) {
F_26 ( V_40 L_2 ,
V_41 ) ;
return - V_31 ;
}
V_26 /= 1000000 ;
V_27 = 3000 / V_26 * V_39 [ V_24 ] [ 3 ] ;
V_28 = V_27 * 10000 / ( 10000 / V_26 ) ;
F_27 ( V_28 , V_42 ) ;
F_27 ( V_22 , V_32 ) ;
F_27 ( V_23 , V_43 ) ;
do {
V_25 = F_24 ( V_32 ) ;
} while ( ! ( V_25 & 0x1 << V_44 ) );
V_1 -> V_21 = V_21 ;
return 0 ;
}
static unsigned long F_28 ( struct V_1 * V_1 )
{
return F_29 ( V_45 , F_24 ( V_46 ) ) ;
}
static int F_30 ( void )
{
F_31 ( V_47 , F_25 ( V_47 ) ) ;
return 0 ;
}
static void F_32 ( void )
{
F_33 ( V_47 , F_25 ( V_47 ) ) ;
}
void T_1 F_34 ( void )
{
struct V_1 * V_48 ;
unsigned long V_49 ;
unsigned long V_50 ;
unsigned long V_51 ;
unsigned long V_52 ;
unsigned long V_53 ;
unsigned long V_54 ;
unsigned long V_55 ;
unsigned long V_56 ;
unsigned long V_57 ;
unsigned long V_58 ;
unsigned long V_59 ;
unsigned long V_60 ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned int V_65 ;
F_26 ( V_66 L_3 , V_41 ) ;
V_48 = F_35 ( NULL , L_4 ) ;
F_36 ( F_37 ( V_48 ) ) ;
V_56 = F_22 ( V_48 ) ;
V_45 = V_56 ;
F_38 ( V_48 ) ;
F_26 ( V_66 L_5 , V_41 , V_56 ) ;
V_49 = F_29 ( V_56 , F_24 ( V_46 ) ) ;
V_50 = F_29 ( V_56 , F_24 ( V_67 ) ) ;
V_51 = F_29 ( V_56 , F_24 ( V_68 ) ) ;
V_52 = F_29 ( V_56 , F_24 ( V_69 ) ) ;
V_53 = F_39 ( V_56 , F_24 ( V_32 ) ,
F_24 ( V_43 ) ) ;
V_55 = F_22 ( & V_70 . V_1 ) ;
V_54 = F_39 ( V_55 , F_24 ( V_71 ) ,
F_24 ( V_72 ) ) ;
V_73 . V_74 = & V_75 ;
V_76 . V_21 = V_50 ;
V_77 . V_21 = V_50 >> 1 ;
V_78 . V_21 = V_51 ;
V_79 . V_21 = V_52 ;
V_80 . V_21 = V_52 >> 1 ;
V_81 . V_21 = V_53 ;
V_82 . V_21 = V_54 ;
F_26 ( V_83 L_6
L_7 ,
V_49 , V_50 , V_51 , V_52 , V_53 , V_54 ) ;
V_57 = F_22 ( & V_84 ) ;
V_58 = F_22 ( & V_85 . V_1 ) ;
V_59 = F_22 ( & V_86 . V_1 ) ;
V_60 = F_22 ( & V_87 . V_1 ) ;
V_61 = F_22 ( & V_88 . V_1 ) ;
V_62 = F_22 ( & V_89 . V_1 ) ;
V_63 = F_22 ( & V_90 . V_1 ) ;
V_64 = F_22 ( & V_91 . V_1 ) ;
F_26 ( V_83 L_8
L_9
L_10 ,
V_57 , V_58 , V_59 ,
V_60 , V_61 , V_62 ,
V_63 , V_64 ) ;
V_81 . V_74 = & V_92 ;
if ( F_40 ( & V_93 . V_1 , & V_81 ) )
F_26 ( V_40 L_11 ,
V_81 . V_94 , V_93 . V_1 . V_94 ) ;
F_41 ( & V_95 . V_1 , 100000000 ) ;
F_41 ( & V_88 . V_1 , 300000000 ) ;
F_41 ( & V_96 . V_1 , 267000000 ) ;
F_41 ( & V_97 . V_1 , 134000000 ) ;
for ( V_65 = 0 ; V_65 < F_25 ( V_98 ) ; V_65 ++ )
F_42 ( & V_98 [ V_65 ] , true ) ;
}
void T_2 F_43 ( void )
{
int V_65 ;
F_44 ( V_99 , F_25 ( V_99 ) ) ;
for ( V_65 = 0 ; V_65 < F_25 ( V_100 ) ; V_65 ++ )
F_45 ( V_100 [ V_65 ] , 1 ) ;
for ( V_65 = 0 ; V_65 < F_25 ( V_101 ) ; V_65 ++ )
F_45 ( V_101 [ V_65 ] , 1 ) ;
for ( V_65 = 0 ; V_65 < F_25 ( V_102 ) ; V_65 ++ )
F_45 ( V_102 [ V_65 ] , 1 ) ;
F_45 ( V_98 , F_25 ( V_98 ) ) ;
F_46 ( V_103 , F_25 ( V_103 ) ) ;
F_44 ( V_104 , F_25 ( V_104 ) ) ;
for ( V_65 = 0 ; V_65 < F_25 ( V_104 ) ; V_65 ++ )
F_47 ( V_104 [ V_65 ] , 1 ) ;
F_46 ( V_105 , F_25 ( V_105 ) ) ;
F_47 ( V_105 , F_25 ( V_105 ) ) ;
F_48 ( V_106 , F_25 ( V_106 ) ) ;
F_49 ( & V_107 ) ;
F_50 () ;
}
