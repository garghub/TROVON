void T_1 F_1 ( void )
{
V_1 = F_2 ( F_3 ( V_2 ) ) ;
V_3 = F_4 ( V_4 | V_5 | V_6 ) ;
}
void F_5 ( unsigned int V_7 )
{
F_6 ( L_1 ) ;
F_7 ( V_7 ) ;
F_6 ( L_2 ,
V_8 << ( V_9 - 10 ) ) ;
F_6 ( L_3 , V_10 ) ;
F_6 ( L_4 , F_8 () ) ;
#if 0
printk("%ld pages in page table cache\n",pgtable_cache_size);
#ifndef F_9
if (sparc_cpu_model == sun4m || sparc_cpu_model == sun4d)
printk("%ld entries in page dir cache\n",pgd_cache_size);
#endif
#endif
}
void T_1 F_10 ( int V_11 )
{
int V_12 ;
V_13 = F_11 ( V_11 * sizeof( struct V_14 ) , V_15 , 0UL ) ;
for( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
struct V_14 * V_16 ;
V_16 = ( V_13 + V_12 ) ;
V_16 -> V_17 = V_12 ;
V_16 -> V_18 = NULL ;
}
V_19 . V_20 = V_19 . V_21 = & V_19 ;
V_22 . V_20 = V_22 . V_21 = & V_22 ;
for( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
F_12 ( V_13 + V_12 ) ;
}
unsigned long F_13 ( void )
{
int V_23 ;
int V_24 = 0 ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_26 != 0 ; V_23 ++ ) {
unsigned long V_27 = V_25 [ V_23 ] . V_28 >> V_9 ;
unsigned long V_29 = ( V_25 [ V_23 ] . V_28 + V_25 [ V_23 ] . V_26 ) >> V_9 ;
if ( V_29 <= V_30 )
continue;
if ( V_27 < V_30 )
V_27 = V_30 ;
V_24 += V_29 - V_27 ;
}
return V_24 ;
}
static unsigned long F_14 ( void )
{
int V_23 ;
unsigned long V_31 = V_32 + ( V_33 >> V_9 ) ;
unsigned long V_34 , V_35 ;
V_35 = ( V_25 [ 0 ] . V_28 + V_25 [ 0 ] . V_26 ) >> V_9 ;
for ( V_23 = 1 ; V_25 [ V_23 ] . V_26 != 0 ; V_23 ++ ) {
V_34 = V_25 [ V_23 ] . V_28 >> V_9 ;
if ( V_34 >= V_31 ) {
if ( V_35 < V_31 )
V_31 = V_35 ;
break;
}
V_35 = ( V_25 [ V_23 ] . V_28 + V_25 [ V_23 ] . V_26 ) >> V_9 ;
}
return V_31 ;
}
unsigned long T_1 F_15 ( unsigned long * V_36 )
{
unsigned long V_37 , V_27 ;
unsigned long V_38 = 0UL ;
unsigned long V_39 , V_40 , V_41 ;
int V_23 ;
V_40 = 0UL ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_26 != 0 ; V_23 ++ ) {
V_38 = V_25 [ V_23 ] . V_28 +
V_25 [ V_23 ] . V_26 ;
V_40 += V_25 [ V_23 ] . V_26 ;
if ( V_42 ) {
if ( V_40 > V_42 ) {
unsigned long V_43 = V_40 - V_42 ;
V_40 -= V_43 ;
V_38 -= V_43 ;
V_25 [ V_23 ] . V_26 -= V_43 ;
if ( V_25 [ V_23 ] . V_26 == 0 ) {
V_25 [ V_23 ] . V_28 = 0xdeadbeef ;
} else {
V_25 [ V_23 + 1 ] . V_26 = 0 ;
V_25 [ V_23 + 1 ] . V_28 = 0xdeadbeef ;
}
break;
}
}
}
V_27 = ( unsigned long ) F_16 ( F_17 ( ( unsigned long ) & V_44 ) ) ;
V_27 >>= V_9 ;
V_39 = V_27 ;
V_45 = V_38 >> V_9 ;
V_30 = V_45 ;
V_46 = V_47 = V_45 ;
if ( V_30 > V_32 + ( V_33 >> V_9 ) ) {
V_46 = V_32 + ( V_33 >> V_9 ) ;
V_30 = F_14 () ;
F_6 ( V_48 L_5 ,
F_13 () >> ( 20 - V_9 ) ) ;
}
#ifdef F_18
if ( V_49 ) {
if ( V_49 >= ( unsigned long ) & V_44 - 2 * V_50 )
V_49 -= V_51 ;
V_52 = V_49 + V_53 ;
V_54 = V_52 + V_55 ;
if ( V_54 > V_38 ) {
F_6 ( V_56 L_6
L_7 ,
V_54 , V_38 ) ;
V_52 = 0 ;
}
if ( V_52 ) {
if ( V_52 >= ( V_27 << V_9 ) &&
V_52 < ( V_27 << V_9 ) + 2 * V_50 )
V_39 = F_17 ( V_54 ) >> V_9 ;
}
}
#endif
V_37 = F_19 ( F_20 ( 0 ) , V_39 , V_32 ,
V_30 ) ;
* V_36 = 0 ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_26 != 0 ; V_23 ++ ) {
unsigned long V_34 , V_35 ;
V_34 = V_25 [ V_23 ] . V_28 >> V_9 ;
if ( V_34 >= V_30 )
break;
V_35 = ( V_25 [ V_23 ] . V_28 + V_25 [ V_23 ] . V_26 ) >> V_9 ;
if ( V_35 > V_30 )
V_35 = V_30 ;
if ( V_35 <= V_34 )
continue;
V_41 = ( V_35 - V_34 ) << V_9 ;
* V_36 += V_35 - V_34 ;
F_21 ( V_25 [ V_23 ] . V_28 , V_41 ) ;
}
#ifdef F_18
if ( V_52 ) {
V_41 = V_54 - V_52 ;
F_22 ( V_52 , V_41 , V_57 ) ;
* V_36 -= F_17 ( V_41 ) >> V_9 ;
V_52 = ( V_52 - V_53 ) + V_58 ;
V_54 = ( V_54 - V_53 ) + V_58 ;
}
#endif
V_41 = ( V_27 << V_9 ) - V_53 ;
F_22 ( V_53 , V_41 , V_57 ) ;
* V_36 -= F_17 ( V_41 ) >> V_9 ;
V_41 = V_37 ;
F_22 ( ( V_39 << V_9 ) , V_41 , V_57 ) ;
* V_36 -= F_17 ( V_41 ) >> V_9 ;
return V_45 ;
}
void T_1 F_23 ( void )
{
switch( V_59 ) {
case V_60 :
F_24 () ;
case V_61 :
case V_62 :
F_25 () ;
V_63 = 0x50000000 ;
break;
default:
F_26 ( L_8 ) ;
F_26 ( L_9 , V_59 ) ;
F_26 ( L_10 ) ;
F_27 () ;
}
F_28 () ;
F_29 () ;
F_30 () ;
}
static void T_1 F_31 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_26 ; V_23 ++ ) {
unsigned long V_64 , V_65 ;
V_64 = V_25 [ V_23 ] . V_28 ;
V_65 = V_64 + V_25 [ V_23 ] . V_26 ;
while ( V_64 < V_65 ) {
F_32 ( V_64 >> 20 , V_66 ) ;
V_64 += V_50 ;
}
}
}
static void F_33 ( unsigned long V_27 , unsigned long V_29 )
{
unsigned long V_31 ;
#ifdef F_34
F_6 ( L_11 , V_27 , V_29 ) ;
#endif
for ( V_31 = V_27 ; V_31 < V_29 ; V_31 ++ ) {
struct V_67 * V_67 = F_35 ( V_31 ) ;
F_36 ( V_67 ) ;
F_37 ( V_67 ) ;
F_38 ( V_67 ) ;
V_68 ++ ;
}
}
void T_1 F_39 ( void )
{
int V_69 = 0 ;
int V_70 = 0 ;
int V_71 = 0 ;
int V_72 = 0 ;
int V_23 ;
if ( V_73 + V_74 * V_50 >= V_75 ) {
F_26 ( L_12 ) ;
F_26 ( L_13 ,
V_73 ,
( unsigned long ) V_73 + V_74 * V_50 ,
V_75 ) ;
F_26 ( L_14 ) ;
F_27 () ;
}
memset ( ( void * ) & V_76 , 0 , V_50 ) ;
V_23 = V_77 >> ( ( 20 - V_9 ) + 5 ) ;
V_23 += 1 ;
V_66 = ( unsigned long * )
F_11 ( V_23 << 2 , V_15 , 0UL ) ;
if ( V_66 == NULL ) {
F_26 ( L_15 ) ;
F_27 () ;
}
memset ( V_66 , 0 , V_23 << 2 ) ;
F_31 () ;
V_78 = V_77 - V_32 ;
V_79 = F_40 ( V_30 << V_9 ) ;
V_10 = F_41 () ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_26 != 0 ; V_23 ++ ) {
unsigned long V_27 = V_25 [ V_23 ] . V_28 >> V_9 ;
unsigned long V_29 = ( V_25 [ V_23 ] . V_28 + V_25 [ V_23 ] . V_26 ) >> V_9 ;
V_80 += V_25 [ V_23 ] . V_26 >> V_9 ;
if ( V_29 <= V_46 )
continue;
if ( V_27 < V_46 )
V_27 = V_46 ;
F_33 ( V_27 , V_29 ) ;
}
V_10 += V_68 ;
V_69 = ( ( ( unsigned long ) & V_81 ) - ( ( unsigned long ) & V_82 ) ) ;
V_69 = F_17 ( V_69 ) >> V_9 ;
V_70 = ( ( ( unsigned long ) & V_83 ) - ( ( unsigned long ) & V_81 ) ) ;
V_70 = F_17 ( V_70 ) >> V_9 ;
V_71 = ( ( ( unsigned long ) & V_84 ) - ( ( unsigned long ) & V_85 ) ) ;
V_71 = F_17 ( V_71 ) >> V_9 ;
for ( V_23 = 0 ; V_23 < V_30 ; V_23 ++ )
if ( F_42 ( V_23 >> ( 20 - V_9 ) , V_66 )
&& F_43 ( F_35 ( V_23 ) ) )
V_72 ++ ;
F_6 ( V_86 L_16 ,
F_8 () << ( V_9 - 10 ) ,
V_80 << ( V_9 - 10 ) ,
V_69 << ( V_9 - 10 ) ,
V_72 << ( V_9 - 10 ) ,
V_70 << ( V_9 - 10 ) ,
V_71 << ( V_9 - 10 ) ,
V_68 << ( V_9 - 10 ) ) ;
}
void F_44 ( void )
{
unsigned long V_87 ;
unsigned long V_88 ;
V_87 = ( unsigned long ) ( & V_85 ) ;
V_88 = ( unsigned long ) ( & V_84 ) - V_87 ;
for (; V_87 < ( unsigned long ) ( & V_84 ) ; V_87 += V_50 ) {
struct V_67 * V_89 ;
memset ( ( void * ) V_87 , V_90 , V_50 ) ;
V_89 = F_45 ( V_87 ) ;
F_36 ( V_89 ) ;
F_37 ( V_89 ) ;
F_38 ( V_89 ) ;
V_10 ++ ;
V_80 ++ ;
}
F_6 ( V_86 L_17 ,
V_88 >> 10 ) ;
}
void F_46 ( unsigned long V_64 , unsigned long V_65 )
{
if ( V_64 < V_65 )
F_6 ( V_86 L_18 ,
( V_65 - V_64 ) >> 10 ) ;
for (; V_64 < V_65 ; V_64 += V_50 ) {
struct V_67 * V_89 ;
memset ( ( void * ) V_64 , V_90 , V_50 ) ;
V_89 = F_45 ( V_64 ) ;
F_36 ( V_89 ) ;
F_37 ( V_89 ) ;
F_38 ( V_89 ) ;
V_10 ++ ;
V_80 ++ ;
}
}
void F_47 ( struct V_67 * V_67 )
{
unsigned long V_91 = ( unsigned long ) F_48 ( V_67 ) ;
if ( V_91 )
F_49 ( V_91 ) ;
}
