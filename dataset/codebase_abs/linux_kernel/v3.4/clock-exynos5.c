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
static unsigned long F_16 ( struct V_1 * V_1 )
{
return V_1 -> V_17 ;
}
static int F_17 ( struct V_1 * V_1 , unsigned long V_17 )
{
unsigned int V_18 , V_19 ;
unsigned int V_20 ;
unsigned int V_21 ;
unsigned int V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
if ( V_1 -> V_17 == V_17 )
return 0 ;
if ( V_1 -> V_25 )
V_22 = F_18 ( V_1 -> V_25 ) ;
else
V_22 = V_26 . V_17 ;
if ( V_22 != 24000000 ) {
F_19 ( L_1 ) ;
return - V_27 ;
}
V_18 = F_20 ( V_28 ) ;
V_18 &= ~ ( 0x1 << 27 | \
V_29 << V_30 | \
V_31 << V_32 | \
V_33 << V_34 ) ;
for ( V_20 = 0 ; V_20 < F_21 ( V_35 ) ; V_20 ++ ) {
if ( V_35 [ V_20 ] [ 0 ] == V_17 ) {
V_19 = V_35 [ V_20 ] [ 5 ] << 0 ;
V_18 |= V_35 [ V_20 ] [ 1 ] << 27 ;
V_18 |= V_35 [ V_20 ] [ 2 ] << V_30 ;
V_18 |= V_35 [ V_20 ] [ 3 ] << V_32 ;
V_18 |= V_35 [ V_20 ] [ 4 ] << V_34 ;
break;
}
}
if ( V_20 == F_21 ( V_35 ) ) {
F_22 ( V_36 L_2 ,
V_37 ) ;
return - V_27 ;
}
V_22 /= 1000000 ;
V_23 = 3000 / V_22 * V_35 [ V_20 ] [ 3 ] ;
V_24 = V_23 * 10000 / ( 10000 / V_22 ) ;
F_23 ( V_24 , V_38 ) ;
F_23 ( V_18 , V_28 ) ;
F_23 ( V_19 , V_39 ) ;
do {
V_21 = F_20 ( V_28 ) ;
} while ( ! ( V_21 & 0x1 << V_40 ) );
V_1 -> V_17 = V_17 ;
return 0 ;
}
static unsigned long F_24 ( struct V_1 * V_1 )
{
return F_25 ( V_41 , F_20 ( V_42 ) ) ;
}
static int F_26 ( void )
{
F_27 ( V_43 , F_21 ( V_43 ) ) ;
return 0 ;
}
static void F_28 ( void )
{
F_29 ( V_43 , F_21 ( V_43 ) ) ;
}
void T_1 F_30 ( void )
{
struct V_1 * V_44 ;
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long V_47 ;
unsigned long V_48 ;
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
unsigned int V_61 ;
F_22 ( V_62 L_3 , V_37 ) ;
V_44 = F_31 ( NULL , L_4 ) ;
F_32 ( F_33 ( V_44 ) ) ;
V_52 = F_18 ( V_44 ) ;
V_41 = V_52 ;
F_34 ( V_44 ) ;
F_22 ( V_62 L_5 , V_37 , V_52 ) ;
V_45 = F_25 ( V_52 , F_20 ( V_42 ) ) ;
V_46 = F_25 ( V_52 , F_20 ( V_63 ) ) ;
V_47 = F_25 ( V_52 , F_20 ( V_64 ) ) ;
V_48 = F_25 ( V_52 , F_20 ( V_65 ) ) ;
V_49 = F_35 ( V_52 , F_20 ( V_28 ) ,
F_20 ( V_39 ) ) ;
V_51 = F_18 ( & V_66 . V_1 ) ;
V_50 = F_35 ( V_51 , F_20 ( V_67 ) ,
F_20 ( V_68 ) ) ;
V_69 . V_70 = & V_71 ;
V_72 . V_17 = V_46 ;
V_73 . V_17 = V_47 ;
V_74 . V_17 = V_48 ;
V_75 . V_17 = V_49 ;
V_76 . V_17 = V_50 ;
F_22 ( V_77 L_6
L_7 ,
V_45 , V_46 , V_47 , V_48 , V_49 , V_50 ) ;
V_53 = F_18 ( & V_78 ) ;
V_54 = F_18 ( & V_79 . V_1 ) ;
V_55 = F_18 ( & V_80 . V_1 ) ;
V_56 = F_18 ( & V_81 . V_1 ) ;
V_57 = F_18 ( & V_82 . V_1 ) ;
V_58 = F_18 ( & V_83 . V_1 ) ;
V_59 = F_18 ( & V_84 . V_1 ) ;
V_60 = F_18 ( & V_85 . V_1 ) ;
F_22 ( V_77 L_8
L_9
L_10 ,
V_53 , V_54 , V_55 ,
V_56 , V_57 , V_58 ,
V_59 , V_60 ) ;
V_75 . V_70 = & V_86 ;
if ( F_36 ( & V_87 . V_1 , & V_75 ) )
F_22 ( V_36 L_11 ,
V_75 . V_88 , V_87 . V_1 . V_88 ) ;
F_37 ( & V_89 . V_1 , 100000000 ) ;
F_37 ( & V_82 . V_1 , 300000000 ) ;
F_37 ( & V_90 . V_1 , 267000000 ) ;
F_37 ( & V_91 . V_1 , 134000000 ) ;
for ( V_61 = 0 ; V_61 < F_21 ( V_92 ) ; V_61 ++ )
F_38 ( & V_92 [ V_61 ] , true ) ;
}
void T_2 F_39 ( void )
{
int V_61 ;
F_40 ( V_93 , F_21 ( V_93 ) ) ;
for ( V_61 = 0 ; V_61 < F_21 ( V_94 ) ; V_61 ++ )
F_41 ( V_94 [ V_61 ] , 1 ) ;
for ( V_61 = 0 ; V_61 < F_21 ( V_95 ) ; V_61 ++ )
F_41 ( V_95 [ V_61 ] , 1 ) ;
for ( V_61 = 0 ; V_61 < F_21 ( V_96 ) ; V_61 ++ )
F_41 ( V_96 [ V_61 ] , 1 ) ;
F_41 ( V_92 , F_21 ( V_92 ) ) ;
F_42 ( V_97 , F_21 ( V_97 ) ) ;
F_40 ( V_98 , F_21 ( V_98 ) ) ;
for ( V_61 = 0 ; V_61 < F_21 ( V_98 ) ; V_61 ++ )
F_43 ( V_98 [ V_61 ] , 1 ) ;
F_42 ( V_99 , F_21 ( V_99 ) ) ;
F_43 ( V_99 , F_21 ( V_99 ) ) ;
F_44 ( V_100 , F_21 ( V_100 ) ) ;
F_45 ( & V_101 ) ;
F_46 () ;
}
