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
T_1 F_6 ( void )
{
unsigned int V_1 , V_3 ;
F_2 ( F_3 ( V_8 , V_9 ) , V_1 ) ;
F_2 ( F_3 ( V_8 , V_10 ) , V_3 ) ;
return ( ( ( T_1 ) V_1 ) << 32 ) + V_3 ;
}
unsigned int F_7 ( void )
{
unsigned int V_11 ;
F_5 ( F_3 ( V_8 , V_12 ) , 0 ) ;
F_2 ( F_3 ( V_13 , V_14 ) , V_11 ) ;
return ( V_11 & V_15 ) ;
}
void F_8 ( int V_16 , int V_17 )
{
V_16 -= V_18 ;
F_5 ( F_9 ( V_8 , F_10 ( V_16 ) ) , V_17 ) ;
}
void F_11 ( unsigned int V_19 )
{
F_5 ( F_3 ( V_4 , V_20 ) , 0x80000000 | V_19 ) ;
}
static void F_12 ( void )
{
unsigned int V_21 = F_13 () ;
int V_16 ;
V_16 = ( V_21 & V_22 ) >> V_23 ;
if ( V_16 == 0 )
V_16 = - 1 ;
if ( V_16 >= 0 )
F_14 ( V_24 + V_16 ) ;
else
F_15 () ;
}
static void T_2 F_16 ( unsigned int V_25 )
{
unsigned long V_26 = V_27 ;
unsigned long V_28 = V_29 ;
unsigned int V_30 ;
int V_31 ;
if ( V_32 ) {
V_26 += ( V_33 - V_18 ) ;
V_28 += ( V_33 - V_18 ) ;
}
for ( V_31 = 0 ; V_31 < V_25 ; V_31 ++ ) {
F_5 ( F_3 ( V_8 , V_12 ) , V_31 ) ;
F_2 ( F_3 ( V_13 , V_34 ) , V_30 ) ;
if ( V_30 & V_35 )
F_5 ( F_3 ( V_13 , V_36 ) ,
V_37 | V_26 ) ;
if ( V_32 ) {
F_17 ( V_26 + V_18 ,
F_12 ) ;
V_38 [ V_26 + V_18 ] . V_39 |= V_40 ;
}
if ( V_30 & V_41 )
F_5 ( F_3 ( V_13 , V_42 ) ,
V_37 | V_28 ) ;
if ( V_32 ) {
F_17 ( V_28 + V_18 , F_12 ) ;
V_38 [ V_28 + V_18 ] . V_39 |= V_43 ;
}
}
}
unsigned int F_18 ( void )
{
unsigned int V_44 ;
F_2 ( F_3 ( V_8 , V_14 ) , V_44 ) ;
if ( V_44 & V_45 )
return 1 ;
else
return 0 ;
}
unsigned int F_19 ( void )
{
unsigned int V_31 ;
unsigned long * V_44 , * V_46 , * V_47 ;
unsigned long * V_48 , * V_49 ;
V_44 = V_50 [ F_20 () ] . V_44 ;
V_46 = V_51 [ F_20 () ] . V_46 ;
V_47 = V_52 [ F_20 () ] . V_47 ;
V_48 = ( unsigned long * ) F_21 ( V_4 ,
V_53 ) ;
V_49 = ( unsigned long * ) F_21 ( V_4 ,
V_54 ) ;
for ( V_31 = 0 ; V_31 < F_22 ( V_55 ) ; V_31 ++ ) {
F_2 ( * V_48 , V_44 [ V_31 ] ) ;
F_2 ( * V_49 , V_46 [ V_31 ] ) ;
V_48 ++ ;
V_49 ++ ;
}
F_23 ( V_44 , V_44 , V_46 , V_55 ) ;
F_23 ( V_44 , V_44 , V_47 , V_55 ) ;
return F_24 ( V_44 , V_55 ) ;
}
static void F_25 ( struct V_56 * V_57 )
{
F_26 ( V_57 -> V_16 - V_24 ) ;
}
static void F_27 ( struct V_56 * V_57 )
{
F_28 ( V_57 -> V_16 - V_24 ) ;
}
static int F_29 ( struct V_56 * V_57 , const struct V_58 * V_58 ,
bool V_59 )
{
unsigned int V_16 = ( V_57 -> V_16 - V_24 ) ;
T_3 V_60 = V_61 ;
unsigned long V_62 ;
int V_31 ;
F_30 ( & V_60 , V_58 , V_63 ) ;
if ( F_31 ( V_60 ) )
return - 1 ;
F_32 ( & V_64 , V_62 ) ;
for (; ; ) {
F_33 ( V_16 , F_34 ( V_60 ) ) ;
for ( V_31 = 0 ; V_31 < V_65 ; V_31 ++ )
F_35 ( V_16 , V_52 [ V_31 ] . V_47 ) ;
F_36 ( V_16 , V_52 [ F_34 ( V_60 ) ] . V_47 ) ;
}
F_37 ( V_57 -> V_66 , V_58 ) ;
F_38 ( & V_64 , V_62 ) ;
return V_67 ;
}
static void T_2 F_39 ( unsigned int V_19 , unsigned int V_68 ,
unsigned int V_69 , unsigned int V_70 , unsigned int V_71 ,
unsigned int V_62 )
{
struct V_38 * V_72 ;
if ( V_69 & V_73 ) {
F_5 ( F_9 ( V_4 , F_40 ( V_19 ) ) , V_69 ) ;
for ( V_68 = 0 ; V_68 < V_65 ; V_68 += 32 ) {
F_5 ( F_9 ( V_4 ,
F_41 ( V_19 , V_68 ) ) ,
0xffffffff ) ;
}
} else {
F_5 ( F_9 ( V_4 , F_40 ( V_19 ) ) ,
V_37 | V_69 ) ;
F_33 ( V_19 , V_68 ) ;
if ( V_32 ) {
F_17 ( V_69 + V_18 ,
F_12 ) ;
V_72 = & V_38 [ V_69 + V_18 ] ;
if ( V_72 -> V_74 >= V_75 )
F_42 () ;
V_72 -> V_76 [ V_72 -> V_74 ++ ] = V_19 ;
}
}
F_43 ( V_19 , V_70 ) ;
F_44 ( V_19 , V_71 ) ;
F_26 ( V_19 ) ;
if ( V_62 & V_77 )
F_36 ( V_19 , V_52 [ V_68 ] . V_47 ) ;
if ( ( V_62 & V_78 ) && ( V_32 == 0 ) )
F_28 ( V_19 ) ;
if ( V_71 == V_79 )
V_80 [ V_19 ] |= V_79 ;
}
static void T_2 F_45 ( int V_81 , int V_25 ,
struct V_82 * V_83 , int V_84 )
{
unsigned int V_31 , V_68 ;
unsigned int V_85 = 0 ;
V_86 = & F_8 ;
for ( V_31 = 0 ; V_31 < V_81 ; V_31 ++ ) {
F_43 ( V_31 , V_87 ) ;
F_44 ( V_31 , V_88 ) ;
F_26 ( V_31 ) ;
if ( V_31 < V_55 ) {
V_80 [ V_31 ] = 0 ;
V_38 [ V_31 ] . V_74 = 0 ;
V_38 [ V_31 ] . V_39 = 0 ;
}
}
if ( V_32 )
V_85 = ( V_33 - V_18 ) ;
for ( V_31 = 0 ; V_31 < V_84 ; V_31 ++ ) {
V_68 = V_83 [ V_31 ] . V_89 ;
if ( V_68 == V_90 )
continue;
if ( V_68 == 0 && V_31 != 0 && V_83 [ V_31 ] . V_62 == 0 )
continue;
F_39 ( V_31 ,
V_83 [ V_31 ] . V_89 ,
V_83 [ V_31 ] . V_69 + V_85 ,
V_83 [ V_31 ] . V_70 ,
V_83 [ V_31 ] . V_71 ,
V_83 [ V_31 ] . V_62 ) ;
}
F_16 ( V_25 ) ;
}
void T_2 F_46 ( unsigned long V_91 ,
unsigned long V_92 ,
struct V_82 * V_93 , unsigned int V_94 ,
unsigned int V_95 )
{
unsigned int V_96 ;
int V_25 , V_81 ;
V_97 = ( unsigned long ) F_47 ( V_91 ,
V_92 ) ;
V_24 = V_95 ;
F_2 ( F_3 ( V_4 , V_98 ) , V_96 ) ;
V_81 = ( V_96 & V_99 ) >>
V_100 ;
V_81 = ( ( V_81 + 1 ) * 8 ) ;
V_25 = ( V_96 & V_101 ) >>
V_102 ;
V_25 = V_25 + 1 ;
F_45 ( V_81 , V_25 , V_93 , V_94 ) ;
F_48 ( V_81 , & V_103 ) ;
}
