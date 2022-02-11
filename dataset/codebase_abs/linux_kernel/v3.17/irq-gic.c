T_1 F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 ;
do {
F_2 ( F_3 ( V_4 , V_5 ) , V_1 ) ;
F_2 ( F_3 ( V_4 , V_6 ) , V_3 ) ;
F_2 ( F_3 ( V_4 , V_5 ) , V_2 ) ;
} while ( V_2 != V_1 );
return ( ( ( T_1 ) V_1 ) << 32 ) + V_3 ;
}
void F_4 ( T_1 V_7 )
{
F_5 ( F_3 ( V_8 , V_9 ) ,
( int ) ( V_7 >> 32 ) ) ;
F_5 ( F_3 ( V_8 , V_10 ) ,
( int ) ( V_7 & 0xffffffff ) ) ;
}
void F_6 ( T_1 V_7 , int V_11 )
{
unsigned long V_12 ;
F_7 ( V_12 ) ;
F_5 ( F_3 ( V_8 , V_13 ) , V_11 ) ;
F_5 ( F_3 ( V_14 , V_9 ) ,
( int ) ( V_7 >> 32 ) ) ;
F_5 ( F_3 ( V_14 , V_10 ) ,
( int ) ( V_7 & 0xffffffff ) ) ;
F_8 ( V_12 ) ;
}
T_1 F_9 ( void )
{
unsigned int V_1 , V_3 ;
F_2 ( F_3 ( V_8 , V_9 ) , V_1 ) ;
F_2 ( F_3 ( V_8 , V_10 ) , V_3 ) ;
return ( ( ( T_1 ) V_1 ) << 32 ) + V_3 ;
}
unsigned int F_10 ( void )
{
unsigned int V_15 ;
F_5 ( F_3 ( V_8 , V_13 ) , 0 ) ;
F_2 ( F_3 ( V_14 , V_16 ) , V_15 ) ;
return ( V_15 & V_17 ) ;
}
void F_11 ( int V_18 , int V_19 )
{
V_18 -= V_20 ;
F_5 ( F_12 ( V_8 , F_13 ( V_18 ) ) , V_19 ) ;
}
void F_14 ( unsigned int V_21 )
{
F_5 ( F_3 ( V_4 , V_22 ) , 0x80000000 | V_21 ) ;
}
static void F_15 ( void )
{
unsigned int V_23 = F_16 () ;
int V_18 ;
V_18 = ( V_23 & V_24 ) >> V_25 ;
if ( V_18 == 0 )
V_18 = - 1 ;
if ( V_18 >= 0 )
F_17 ( V_26 + V_18 ) ;
else
F_18 () ;
}
static void T_2 F_19 ( unsigned int V_27 )
{
unsigned long V_28 = V_29 ;
unsigned long V_30 = V_31 ;
unsigned int V_32 ;
int V_33 ;
if ( V_34 ) {
V_28 += ( V_35 - V_20 ) ;
V_30 += ( V_35 - V_20 ) ;
}
for ( V_33 = 0 ; V_33 < V_27 ; V_33 ++ ) {
F_5 ( F_3 ( V_8 , V_13 ) , V_33 ) ;
F_2 ( F_3 ( V_14 , V_36 ) , V_32 ) ;
if ( V_32 & V_37 )
F_5 ( F_3 ( V_14 , V_38 ) ,
V_39 | V_28 ) ;
if ( V_34 ) {
F_20 ( V_28 + V_20 ,
F_15 ) ;
V_40 [ V_28 + V_20 ] . V_41 |= V_42 ;
}
if ( V_32 & V_43 )
F_5 ( F_3 ( V_14 , V_44 ) ,
V_39 | V_30 ) ;
if ( V_34 ) {
F_20 ( V_30 + V_20 , F_15 ) ;
V_40 [ V_30 + V_20 ] . V_41 |= V_45 ;
}
}
}
unsigned int F_21 ( void )
{
unsigned int V_46 ;
F_2 ( F_3 ( V_8 , V_16 ) , V_46 ) ;
if ( V_46 & V_47 )
return 1 ;
else
return 0 ;
}
void F_22 ( unsigned long * V_48 , const unsigned long * V_49 )
{
unsigned int V_33 ;
unsigned long * V_46 , * V_50 , * V_51 ;
unsigned long * V_52 , * V_53 ;
V_46 = V_54 [ F_23 () ] . V_46 ;
V_50 = V_55 [ F_23 () ] . V_50 ;
V_51 = V_56 [ F_23 () ] . V_51 ;
V_52 = ( unsigned long * ) F_24 ( V_4 ,
V_57 ) ;
V_53 = ( unsigned long * ) F_24 ( V_4 ,
V_58 ) ;
for ( V_33 = 0 ; V_33 < F_25 ( V_59 ) ; V_33 ++ ) {
F_2 ( * V_52 , V_46 [ V_33 ] ) ;
F_2 ( * V_53 , V_50 [ V_33 ] ) ;
V_52 ++ ;
V_53 ++ ;
}
F_26 ( V_46 , V_46 , V_50 , V_59 ) ;
F_26 ( V_46 , V_46 , V_51 , V_59 ) ;
F_26 ( V_48 , V_49 , V_46 , V_59 ) ;
}
unsigned int F_27 ( void )
{
F_28 ( V_60 , V_59 ) ;
F_29 ( V_60 , V_59 ) ;
F_22 ( V_60 , V_60 ) ;
return F_30 ( V_60 , V_59 ) ;
}
static void F_31 ( struct V_61 * V_62 )
{
F_32 ( V_62 -> V_18 - V_26 ) ;
}
static void F_33 ( struct V_61 * V_62 )
{
F_34 ( V_62 -> V_18 - V_26 ) ;
}
static int F_35 ( struct V_61 * V_62 , const struct V_63 * V_63 ,
bool V_64 )
{
unsigned int V_18 = ( V_62 -> V_18 - V_26 ) ;
T_3 V_65 = V_66 ;
unsigned long V_12 ;
int V_33 ;
F_36 ( & V_65 , V_63 , V_67 ) ;
if ( F_37 ( V_65 ) )
return - 1 ;
F_38 ( & V_68 , V_12 ) ;
F_39 ( V_18 , F_40 ( V_65 ) ) ;
for ( V_33 = 0 ; V_33 < V_69 ; V_33 ++ )
F_41 ( V_18 , V_56 [ V_33 ] . V_51 ) ;
F_42 ( V_18 , V_56 [ F_40 ( V_65 ) ] . V_51 ) ;
F_43 ( V_62 -> V_70 , V_63 ) ;
F_44 ( & V_68 , V_12 ) ;
return V_71 ;
}
static void T_2 F_45 ( unsigned int V_21 , unsigned int V_11 ,
unsigned int V_72 , unsigned int V_73 , unsigned int V_74 ,
unsigned int V_12 )
{
struct V_40 * V_75 ;
if ( V_72 & V_76 ) {
int V_33 ;
F_5 ( F_12 ( V_4 , F_46 ( V_21 ) ) , V_72 ) ;
for ( V_33 = 0 ; V_33 < V_69 ; V_33 += 32 ) {
F_5 ( F_12 ( V_4 ,
F_47 ( V_21 , V_33 ) ) ,
0xffffffff ) ;
}
} else {
F_5 ( F_12 ( V_4 , F_46 ( V_21 ) ) ,
V_39 | V_72 ) ;
F_39 ( V_21 , V_11 ) ;
if ( V_34 ) {
F_20 ( V_72 + V_20 ,
F_15 ) ;
V_75 = & V_40 [ V_72 + V_20 ] ;
if ( V_75 -> V_77 >= V_78 )
F_48 () ;
V_75 -> V_79 [ V_75 -> V_77 ++ ] = V_21 ;
}
}
F_49 ( V_21 , V_73 ) ;
F_50 ( V_21 , V_74 ) ;
F_32 ( V_21 ) ;
F_42 ( V_21 , V_56 [ V_11 ] . V_51 ) ;
if ( ( V_12 & V_80 ) && ( V_34 == 0 ) )
F_34 ( V_21 ) ;
if ( V_74 == V_81 )
V_82 [ V_21 ] |= V_81 ;
}
static void T_2 F_51 ( int V_83 , int V_27 ,
struct V_84 * V_85 , int V_86 )
{
unsigned int V_33 , V_11 ;
unsigned int V_87 = 0 ;
V_88 = & F_11 ;
for ( V_33 = 0 ; V_33 < V_83 ; V_33 ++ ) {
F_49 ( V_33 , V_89 ) ;
F_50 ( V_33 , V_90 ) ;
F_32 ( V_33 ) ;
if ( V_33 < V_59 ) {
V_82 [ V_33 ] = 0 ;
V_40 [ V_33 ] . V_77 = 0 ;
V_40 [ V_33 ] . V_41 = 0 ;
}
}
if ( V_34 )
V_87 = ( V_35 - V_20 ) ;
for ( V_33 = 0 ; V_33 < V_86 ; V_33 ++ ) {
V_11 = V_85 [ V_33 ] . V_91 ;
if ( V_11 == V_92 )
continue;
F_45 ( V_33 ,
V_85 [ V_33 ] . V_91 ,
V_85 [ V_33 ] . V_72 + V_87 ,
V_85 [ V_33 ] . V_73 ,
V_85 [ V_33 ] . V_74 ,
V_85 [ V_33 ] . V_12 ) ;
}
F_19 ( V_27 ) ;
}
void T_2 F_52 ( unsigned long V_93 ,
unsigned long V_94 ,
struct V_84 * V_95 , unsigned int V_96 ,
unsigned int V_97 )
{
unsigned int V_98 ;
int V_27 , V_83 ;
V_99 = ( unsigned long ) F_53 ( V_93 ,
V_94 ) ;
V_26 = V_97 ;
F_2 ( F_3 ( V_4 , V_100 ) , V_98 ) ;
V_83 = ( V_98 & V_101 ) >>
V_102 ;
V_83 = ( ( V_83 + 1 ) * 8 ) ;
V_27 = ( V_98 & V_103 ) >>
V_104 ;
V_27 = V_27 + 1 ;
F_51 ( V_83 , V_27 , V_95 , V_96 ) ;
F_54 ( V_83 , & V_105 ) ;
}
