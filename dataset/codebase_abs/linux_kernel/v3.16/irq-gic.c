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
unsigned int F_22 ( void )
{
unsigned int V_33 ;
unsigned long * V_46 , * V_48 , * V_49 ;
unsigned long * V_50 , * V_51 ;
V_46 = V_52 [ F_23 () ] . V_46 ;
V_48 = V_53 [ F_23 () ] . V_48 ;
V_49 = V_54 [ F_23 () ] . V_49 ;
V_50 = ( unsigned long * ) F_24 ( V_4 ,
V_55 ) ;
V_51 = ( unsigned long * ) F_24 ( V_4 ,
V_56 ) ;
for ( V_33 = 0 ; V_33 < F_25 ( V_57 ) ; V_33 ++ ) {
F_2 ( * V_50 , V_46 [ V_33 ] ) ;
F_2 ( * V_51 , V_48 [ V_33 ] ) ;
V_50 ++ ;
V_51 ++ ;
}
F_26 ( V_46 , V_46 , V_48 , V_57 ) ;
F_26 ( V_46 , V_46 , V_49 , V_57 ) ;
return F_27 ( V_46 , V_57 ) ;
}
static void F_28 ( struct V_58 * V_59 )
{
F_29 ( V_59 -> V_18 - V_26 ) ;
}
static void F_30 ( struct V_58 * V_59 )
{
F_31 ( V_59 -> V_18 - V_26 ) ;
}
static int F_32 ( struct V_58 * V_59 , const struct V_60 * V_60 ,
bool V_61 )
{
unsigned int V_18 = ( V_59 -> V_18 - V_26 ) ;
T_3 V_62 = V_63 ;
unsigned long V_12 ;
int V_33 ;
F_33 ( & V_62 , V_60 , V_64 ) ;
if ( F_34 ( V_62 ) )
return - 1 ;
F_35 ( & V_65 , V_12 ) ;
F_36 ( V_18 , F_37 ( V_62 ) ) ;
for ( V_33 = 0 ; V_33 < V_66 ; V_33 ++ )
F_38 ( V_18 , V_54 [ V_33 ] . V_49 ) ;
F_39 ( V_18 , V_54 [ F_37 ( V_62 ) ] . V_49 ) ;
F_40 ( V_59 -> V_67 , V_60 ) ;
F_41 ( & V_65 , V_12 ) ;
return V_68 ;
}
static void T_2 F_42 ( unsigned int V_21 , unsigned int V_11 ,
unsigned int V_69 , unsigned int V_70 , unsigned int V_71 ,
unsigned int V_12 )
{
struct V_40 * V_72 ;
if ( V_69 & V_73 ) {
F_5 ( F_12 ( V_4 , F_43 ( V_21 ) ) , V_69 ) ;
for ( V_11 = 0 ; V_11 < V_66 ; V_11 += 32 ) {
F_5 ( F_12 ( V_4 ,
F_44 ( V_21 , V_11 ) ) ,
0xffffffff ) ;
}
} else {
F_5 ( F_12 ( V_4 , F_43 ( V_21 ) ) ,
V_39 | V_69 ) ;
F_36 ( V_21 , V_11 ) ;
if ( V_34 ) {
F_20 ( V_69 + V_20 ,
F_15 ) ;
V_72 = & V_40 [ V_69 + V_20 ] ;
if ( V_72 -> V_74 >= V_75 )
F_45 () ;
V_72 -> V_76 [ V_72 -> V_74 ++ ] = V_21 ;
}
}
F_46 ( V_21 , V_70 ) ;
F_47 ( V_21 , V_71 ) ;
F_29 ( V_21 ) ;
if ( V_12 & V_77 )
F_39 ( V_21 , V_54 [ V_11 ] . V_49 ) ;
if ( ( V_12 & V_78 ) && ( V_34 == 0 ) )
F_31 ( V_21 ) ;
if ( V_71 == V_79 )
V_80 [ V_21 ] |= V_79 ;
}
static void T_2 F_48 ( int V_81 , int V_27 ,
struct V_82 * V_83 , int V_84 )
{
unsigned int V_33 , V_11 ;
unsigned int V_85 = 0 ;
V_86 = & F_11 ;
for ( V_33 = 0 ; V_33 < V_81 ; V_33 ++ ) {
F_46 ( V_33 , V_87 ) ;
F_47 ( V_33 , V_88 ) ;
F_29 ( V_33 ) ;
if ( V_33 < V_57 ) {
V_80 [ V_33 ] = 0 ;
V_40 [ V_33 ] . V_74 = 0 ;
V_40 [ V_33 ] . V_41 = 0 ;
}
}
if ( V_34 )
V_85 = ( V_35 - V_20 ) ;
for ( V_33 = 0 ; V_33 < V_84 ; V_33 ++ ) {
V_11 = V_83 [ V_33 ] . V_89 ;
if ( V_11 == V_90 )
continue;
if ( V_11 == 0 && V_33 != 0 && V_83 [ V_33 ] . V_12 == 0 )
continue;
F_42 ( V_33 ,
V_83 [ V_33 ] . V_89 ,
V_83 [ V_33 ] . V_69 + V_85 ,
V_83 [ V_33 ] . V_70 ,
V_83 [ V_33 ] . V_71 ,
V_83 [ V_33 ] . V_12 ) ;
}
F_19 ( V_27 ) ;
}
void T_2 F_49 ( unsigned long V_91 ,
unsigned long V_92 ,
struct V_82 * V_93 , unsigned int V_94 ,
unsigned int V_95 )
{
unsigned int V_96 ;
int V_27 , V_81 ;
V_97 = ( unsigned long ) F_50 ( V_91 ,
V_92 ) ;
V_26 = V_95 ;
F_2 ( F_3 ( V_4 , V_98 ) , V_96 ) ;
V_81 = ( V_96 & V_99 ) >>
V_100 ;
V_81 = ( ( V_81 + 1 ) * 8 ) ;
V_27 = ( V_96 & V_101 ) >>
V_102 ;
V_27 = V_27 + 1 ;
F_48 ( V_81 , V_27 , V_93 , V_94 ) ;
F_51 ( V_81 , & V_103 ) ;
}
