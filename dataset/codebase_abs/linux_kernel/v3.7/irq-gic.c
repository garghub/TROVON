unsigned int F_1 ( void )
{
unsigned int V_1 ;
F_2 ( F_3 ( V_2 , V_3 ) , 0 ) ;
F_4 ( F_3 ( V_4 , V_5 ) , V_1 ) ;
return ( V_1 & V_6 ) ;
}
void F_5 ( int V_7 , int V_8 )
{
V_7 -= V_9 ;
F_2 ( F_6 ( V_2 , F_7 ( V_7 ) ) , V_8 ) ;
}
void F_8 ( unsigned int V_10 )
{
F_2 ( F_3 ( V_11 , V_12 ) , 0x80000000 | V_10 ) ;
}
static void F_9 ( void )
{
unsigned int V_13 = F_10 () ;
int V_7 ;
V_7 = ( V_13 & V_14 ) >> V_15 ;
if ( V_7 == 0 )
V_7 = - 1 ;
if ( V_7 >= 0 )
F_11 ( V_16 + V_7 ) ;
else
F_12 () ;
}
static void T_1 F_13 ( unsigned int V_17 )
{
unsigned long V_18 = V_19 ;
unsigned long V_20 = V_21 ;
unsigned int V_22 ;
int V_23 ;
if ( V_24 ) {
V_18 += ( V_25 - V_9 ) ;
V_20 += ( V_25 - V_9 ) ;
}
for ( V_23 = 0 ; V_23 < V_17 ; V_23 ++ ) {
F_2 ( F_3 ( V_2 , V_3 ) , V_23 ) ;
F_4 ( F_3 ( V_4 , V_26 ) , V_22 ) ;
if ( V_22 & V_27 )
F_2 ( F_3 ( V_4 , V_28 ) ,
V_29 | V_18 ) ;
if ( V_24 ) {
F_14 ( V_18 + V_9 ,
F_9 ) ;
V_30 [ V_18 + V_9 ] . V_31 |= V_32 ;
}
if ( V_22 & V_33 )
F_2 ( F_3 ( V_4 , V_34 ) ,
V_29 | V_20 ) ;
if ( V_24 ) {
F_14 ( V_20 + V_9 , F_9 ) ;
V_30 [ V_20 + V_9 ] . V_31 |= V_35 ;
}
}
}
unsigned int F_15 ( void )
{
unsigned int V_23 ;
unsigned long * V_36 , * V_37 , * V_38 ;
unsigned long * V_39 , * V_40 ;
V_36 = V_41 [ F_16 () ] . V_36 ;
V_37 = V_42 [ F_16 () ] . V_37 ;
V_38 = V_43 [ F_16 () ] . V_38 ;
V_39 = ( unsigned long * ) F_17 ( V_11 ,
V_44 ) ;
V_40 = ( unsigned long * ) F_17 ( V_11 ,
V_45 ) ;
for ( V_23 = 0 ; V_23 < F_18 ( V_46 ) ; V_23 ++ ) {
F_4 ( * V_39 , V_36 [ V_23 ] ) ;
F_4 ( * V_40 , V_37 [ V_23 ] ) ;
V_39 ++ ;
V_40 ++ ;
}
F_19 ( V_36 , V_36 , V_37 , V_46 ) ;
F_19 ( V_36 , V_36 , V_38 , V_46 ) ;
return F_20 ( V_36 , V_46 ) ;
}
static void F_21 ( struct V_47 * V_48 )
{
F_22 ( V_48 -> V_7 - V_16 ) ;
}
static void F_23 ( struct V_47 * V_48 )
{
F_24 ( V_48 -> V_7 - V_16 ) ;
}
static int F_25 ( struct V_47 * V_48 , const struct V_49 * V_49 ,
bool V_50 )
{
unsigned int V_7 = ( V_48 -> V_7 - V_16 ) ;
T_2 V_51 = V_52 ;
unsigned long V_53 ;
int V_23 ;
F_26 ( & V_51 , V_49 , V_54 ) ;
if ( F_27 ( V_51 ) )
return - 1 ;
F_28 ( & V_55 , V_53 ) ;
for (; ; ) {
F_29 ( V_7 , F_30 ( V_51 ) ) ;
for ( V_23 = 0 ; V_23 < V_56 ; V_23 ++ )
F_31 ( V_7 , V_43 [ V_23 ] . V_38 ) ;
F_32 ( V_7 , V_43 [ F_30 ( V_51 ) ] . V_38 ) ;
}
F_33 ( V_48 -> V_57 , V_49 ) ;
F_34 ( & V_55 , V_53 ) ;
return V_58 ;
}
static void T_1 F_35 ( unsigned int V_10 , unsigned int V_59 ,
unsigned int V_60 , unsigned int V_61 , unsigned int V_62 ,
unsigned int V_53 )
{
struct V_30 * V_63 ;
if ( V_60 & V_64 ) {
F_2 ( F_6 ( V_11 , F_36 ( V_10 ) ) , V_60 ) ;
for ( V_59 = 0 ; V_59 < V_56 ; V_59 += 32 ) {
F_2 ( F_6 ( V_11 ,
F_37 ( V_10 , V_59 ) ) ,
0xffffffff ) ;
}
} else {
F_2 ( F_6 ( V_11 , F_36 ( V_10 ) ) ,
V_29 | V_60 ) ;
F_29 ( V_10 , V_59 ) ;
if ( V_24 ) {
F_14 ( V_60 + V_9 ,
F_9 ) ;
V_63 = & V_30 [ V_60 + V_9 ] ;
if ( V_63 -> V_65 >= V_66 )
F_38 () ;
V_63 -> V_67 [ V_63 -> V_65 ++ ] = V_10 ;
}
}
F_39 ( V_10 , V_61 ) ;
F_40 ( V_10 , V_62 ) ;
F_22 ( V_10 ) ;
if ( V_53 & V_68 )
F_32 ( V_10 , V_43 [ V_59 ] . V_38 ) ;
if ( ( V_53 & V_69 ) && ( V_24 == 0 ) )
F_24 ( V_10 ) ;
if ( V_62 == V_70 )
V_71 [ V_10 ] |= V_70 ;
}
static void T_1 F_41 ( int V_72 , int V_17 ,
struct V_73 * V_74 , int V_75 )
{
unsigned int V_23 , V_59 ;
unsigned int V_76 = 0 ;
V_77 = & F_5 ;
for ( V_23 = 0 ; V_23 < V_72 ; V_23 ++ ) {
F_39 ( V_23 , V_78 ) ;
F_40 ( V_23 , V_79 ) ;
F_22 ( V_23 ) ;
if ( V_23 < V_46 ) {
V_71 [ V_23 ] = 0 ;
V_30 [ V_23 ] . V_65 = 0 ;
V_30 [ V_23 ] . V_31 = 0 ;
}
}
if ( V_24 )
V_76 = ( V_25 - V_9 ) ;
for ( V_23 = 0 ; V_23 < V_75 ; V_23 ++ ) {
V_59 = V_74 [ V_23 ] . V_80 ;
if ( V_59 == V_81 )
continue;
if ( V_59 == 0 && V_23 != 0 && V_74 [ V_23 ] . V_53 == 0 )
continue;
F_35 ( V_23 ,
V_74 [ V_23 ] . V_80 ,
V_74 [ V_23 ] . V_60 + V_76 ,
V_74 [ V_23 ] . V_61 ,
V_74 [ V_23 ] . V_62 ,
V_74 [ V_23 ] . V_53 ) ;
}
F_13 ( V_17 ) ;
}
void T_1 F_42 ( unsigned long V_82 ,
unsigned long V_83 ,
struct V_73 * V_84 , unsigned int V_85 ,
unsigned int V_86 )
{
unsigned int V_87 ;
int V_17 , V_72 ;
V_88 = ( unsigned long ) F_43 ( V_82 ,
V_83 ) ;
V_16 = V_86 ;
F_4 ( F_3 ( V_11 , V_89 ) , V_87 ) ;
V_72 = ( V_87 & V_90 ) >>
V_91 ;
V_72 = ( ( V_72 + 1 ) * 8 ) ;
V_17 = ( V_87 & V_92 ) >>
V_93 ;
V_17 = V_17 + 1 ;
F_41 ( V_72 , V_17 , V_84 , V_85 ) ;
F_44 ( V_72 , & V_94 ) ;
}
