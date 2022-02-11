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
static int F_20 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_21 , V_1 , V_2 ) ;
}
static unsigned long F_21 ( struct V_1 * V_1 )
{
return V_1 -> V_22 ;
}
static int F_22 ( struct V_1 * V_1 , unsigned long V_22 )
{
unsigned int V_23 , V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int V_28 ;
unsigned int V_29 ;
if ( V_1 -> V_22 == V_22 )
return 0 ;
if ( V_1 -> V_30 )
V_27 = F_23 ( V_1 -> V_30 ) ;
else
V_27 = V_31 . V_22 ;
if ( V_27 != 24000000 ) {
F_24 ( L_1 ) ;
return - V_32 ;
}
V_23 = F_25 ( V_33 ) ;
V_23 &= ~ ( 0x1 << 27 | \
V_34 << V_35 | \
V_36 << V_37 | \
V_38 << V_39 ) ;
for ( V_25 = 0 ; V_25 < F_26 ( V_40 ) ; V_25 ++ ) {
if ( V_40 [ V_25 ] [ 0 ] == V_22 ) {
V_24 = V_40 [ V_25 ] [ 5 ] << 0 ;
V_23 |= V_40 [ V_25 ] [ 1 ] << 27 ;
V_23 |= V_40 [ V_25 ] [ 2 ] << V_35 ;
V_23 |= V_40 [ V_25 ] [ 3 ] << V_37 ;
V_23 |= V_40 [ V_25 ] [ 4 ] << V_39 ;
break;
}
}
if ( V_25 == F_26 ( V_40 ) ) {
F_27 ( V_41 L_2 ,
V_42 ) ;
return - V_32 ;
}
V_27 /= 1000000 ;
V_28 = 3000 / V_27 * V_40 [ V_25 ] [ 3 ] ;
V_29 = V_28 * 10000 / ( 10000 / V_27 ) ;
F_28 ( V_29 , V_43 ) ;
F_28 ( V_23 , V_33 ) ;
F_28 ( V_24 , V_44 ) ;
do {
V_26 = F_25 ( V_33 ) ;
} while ( ! ( V_26 & 0x1 << V_45 ) );
V_1 -> V_22 = V_22 ;
return 0 ;
}
static unsigned long F_29 ( struct V_1 * V_1 )
{
return F_30 ( V_46 , F_25 ( V_47 ) ) ;
}
static int F_31 ( void )
{
F_32 ( V_48 , F_26 ( V_48 ) ) ;
return 0 ;
}
static void F_33 ( void )
{
F_34 ( V_48 , F_26 ( V_48 ) ) ;
}
void T_1 F_35 ( void )
{
struct V_1 * V_49 ;
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
unsigned long V_65 ;
unsigned int V_66 ;
F_27 ( V_67 L_3 , V_42 ) ;
V_49 = F_36 ( NULL , L_4 ) ;
F_37 ( F_38 ( V_49 ) ) ;
V_57 = F_23 ( V_49 ) ;
V_46 = V_57 ;
F_39 ( V_49 ) ;
F_27 ( V_67 L_5 , V_42 , V_57 ) ;
V_50 = F_30 ( V_57 , F_25 ( V_47 ) ) ;
V_51 = F_30 ( V_57 , F_25 ( V_68 ) ) ;
V_52 = F_30 ( V_57 , F_25 ( V_69 ) ) ;
V_53 = F_30 ( V_57 , F_25 ( V_70 ) ) ;
V_54 = F_40 ( V_57 , F_25 ( V_33 ) ,
F_25 ( V_44 ) ) ;
V_56 = F_23 ( & V_71 . V_1 ) ;
V_55 = F_40 ( V_56 , F_25 ( V_72 ) ,
F_25 ( V_73 ) ) ;
V_74 . V_75 = & V_76 ;
V_77 . V_22 = V_51 ;
V_78 . V_22 = V_51 >> 1 ;
V_79 . V_22 = V_52 ;
V_80 . V_22 = V_53 ;
V_81 . V_22 = V_53 >> 1 ;
V_82 . V_22 = V_54 ;
V_83 . V_22 = V_55 ;
F_27 ( V_84 L_6
L_7 ,
V_50 , V_51 , V_52 , V_53 , V_54 , V_55 ) ;
V_58 = F_23 ( & V_85 ) ;
V_59 = F_23 ( & V_86 . V_1 ) ;
V_60 = F_23 ( & V_87 . V_1 ) ;
V_61 = F_23 ( & V_88 . V_1 ) ;
V_62 = F_23 ( & V_89 . V_1 ) ;
V_63 = F_23 ( & V_90 . V_1 ) ;
V_64 = F_23 ( & V_91 . V_1 ) ;
V_65 = F_23 ( & V_92 . V_1 ) ;
F_27 ( V_84 L_8
L_9
L_10 ,
V_58 , V_59 , V_60 ,
V_61 , V_62 , V_63 ,
V_64 , V_65 ) ;
V_82 . V_75 = & V_93 ;
if ( F_41 ( & V_94 . V_1 , & V_82 ) )
F_27 ( V_41 L_11 ,
V_82 . V_95 , V_94 . V_1 . V_95 ) ;
F_42 ( & V_96 . V_1 , 100000000 ) ;
F_42 ( & V_89 . V_1 , 300000000 ) ;
F_42 ( & V_97 . V_1 , 267000000 ) ;
F_42 ( & V_98 . V_1 , 134000000 ) ;
for ( V_66 = 0 ; V_66 < F_26 ( V_99 ) ; V_66 ++ )
F_43 ( & V_99 [ V_66 ] , true ) ;
}
void T_2 F_44 ( void )
{
int V_66 ;
F_45 ( V_100 , F_26 ( V_100 ) ) ;
for ( V_66 = 0 ; V_66 < F_26 ( V_101 ) ; V_66 ++ )
F_46 ( V_101 [ V_66 ] , 1 ) ;
for ( V_66 = 0 ; V_66 < F_26 ( V_102 ) ; V_66 ++ )
F_46 ( V_102 [ V_66 ] , 1 ) ;
for ( V_66 = 0 ; V_66 < F_26 ( V_103 ) ; V_66 ++ )
F_46 ( V_103 [ V_66 ] , 1 ) ;
F_46 ( V_99 , F_26 ( V_99 ) ) ;
F_47 ( V_104 , F_26 ( V_104 ) ) ;
F_45 ( V_105 , F_26 ( V_105 ) ) ;
for ( V_66 = 0 ; V_66 < F_26 ( V_105 ) ; V_66 ++ )
F_48 ( V_105 [ V_66 ] , 1 ) ;
F_47 ( V_106 , F_26 ( V_106 ) ) ;
F_48 ( V_106 , F_26 ( V_106 ) ) ;
F_49 ( V_107 , F_26 ( V_107 ) ) ;
F_50 ( & V_108 ) ;
F_51 () ;
}
