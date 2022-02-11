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
void F_23 ( void )
{
F_24 ( V_59 [ 0 ] , V_59 [ 1 ] ) ;
}
void T_1 F_25 ( void )
{
switch( V_60 ) {
case V_61 :
case V_62 :
case V_63 :
F_26 () ;
V_64 = 0xe0000000 ;
F_27 ( V_64 , 0xe0000000 ) ;
break;
case V_65 :
F_28 () ;
case V_66 :
case V_67 :
F_29 () ;
V_64 = 0x50000000 ;
F_27 ( V_64 , 0x50000000 ) ;
break;
default:
F_30 ( L_8 ) ;
F_30 ( L_9 , V_60 ) ;
F_30 ( L_10 ) ;
F_31 () ;
}
V_68 [ 0 ] = V_69 ;
V_68 [ 1 ] = V_70 ;
V_68 [ 2 ] = V_71 ;
V_68 [ 3 ] = V_71 ;
V_68 [ 4 ] = V_70 ;
V_68 [ 5 ] = V_70 ;
V_68 [ 6 ] = V_71 ;
V_68 [ 7 ] = V_71 ;
V_68 [ 8 ] = V_69 ;
V_68 [ 9 ] = V_70 ;
V_68 [ 10 ] = V_72 ;
V_68 [ 11 ] = V_72 ;
V_68 [ 12 ] = V_70 ;
V_68 [ 13 ] = V_70 ;
V_68 [ 14 ] = V_72 ;
V_68 [ 15 ] = V_72 ;
F_32 () ;
F_33 () ;
F_34 () ;
F_35 () ;
}
static void T_1 F_36 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_26 ; V_23 ++ ) {
unsigned long V_73 , V_74 ;
V_73 = V_25 [ V_23 ] . V_28 ;
V_74 = V_73 + V_25 [ V_23 ] . V_26 ;
while ( V_73 < V_74 ) {
F_37 ( V_73 >> 20 , V_75 ) ;
V_73 += V_50 ;
}
}
}
static void F_38 ( unsigned long V_27 , unsigned long V_29 )
{
unsigned long V_31 ;
#ifdef F_39
F_6 ( L_11 , V_27 , V_29 ) ;
#endif
for ( V_31 = V_27 ; V_31 < V_29 ; V_31 ++ ) {
struct V_76 * V_76 = F_40 ( V_31 ) ;
F_41 ( V_76 ) ;
F_42 ( V_76 ) ;
F_43 ( V_76 ) ;
V_77 ++ ;
}
}
void T_1 F_44 ( void )
{
int V_78 = 0 ;
int V_79 = 0 ;
int V_80 = 0 ;
int V_81 = 0 ;
int V_23 ;
if ( V_82 + V_83 * V_50 >= V_84 ) {
F_30 ( L_12 ) ;
F_30 ( L_13 ,
V_82 ,
( unsigned long ) V_82 + V_83 * V_50 ,
V_84 ) ;
F_30 ( L_14 ) ;
F_31 () ;
}
memset ( ( void * ) & V_85 , 0 , V_50 ) ;
V_23 = V_86 >> ( ( 20 - V_9 ) + 5 ) ;
V_23 += 1 ;
V_75 = ( unsigned long * )
F_11 ( V_23 << 2 , V_15 , 0UL ) ;
if ( V_75 == NULL ) {
F_30 ( L_15 ) ;
F_31 () ;
}
memset ( V_75 , 0 , V_23 << 2 ) ;
F_36 () ;
V_87 = V_86 - V_32 ;
V_88 = F_45 ( V_30 << V_9 ) ;
V_10 = F_46 () ;
for ( V_23 = 0 ; V_25 [ V_23 ] . V_26 != 0 ; V_23 ++ ) {
unsigned long V_27 = V_25 [ V_23 ] . V_28 >> V_9 ;
unsigned long V_29 = ( V_25 [ V_23 ] . V_28 + V_25 [ V_23 ] . V_26 ) >> V_9 ;
V_89 += V_25 [ V_23 ] . V_26 >> V_9 ;
if ( V_29 <= V_46 )
continue;
if ( V_27 < V_46 )
V_27 = V_46 ;
F_38 ( V_27 , V_29 ) ;
}
V_10 += V_77 ;
V_78 = ( ( ( unsigned long ) & V_90 ) - ( ( unsigned long ) & V_91 ) ) ;
V_78 = F_17 ( V_78 ) >> V_9 ;
V_79 = ( ( ( unsigned long ) & V_92 ) - ( ( unsigned long ) & V_90 ) ) ;
V_79 = F_17 ( V_79 ) >> V_9 ;
V_80 = ( ( ( unsigned long ) & V_93 ) - ( ( unsigned long ) & V_94 ) ) ;
V_80 = F_17 ( V_80 ) >> V_9 ;
for ( V_23 = 0 ; V_23 < V_30 ; V_23 ++ )
if ( F_47 ( V_23 >> ( 20 - V_9 ) , V_75 )
&& F_48 ( F_40 ( V_23 ) ) )
V_81 ++ ;
F_6 ( V_95 L_16 ,
F_8 () << ( V_9 - 10 ) ,
V_89 << ( V_9 - 10 ) ,
V_78 << ( V_9 - 10 ) ,
V_81 << ( V_9 - 10 ) ,
V_79 << ( V_9 - 10 ) ,
V_80 << ( V_9 - 10 ) ,
V_77 << ( V_9 - 10 ) ) ;
}
void F_49 ( void )
{
unsigned long V_96 ;
unsigned long V_97 ;
V_96 = ( unsigned long ) ( & V_94 ) ;
V_97 = ( unsigned long ) ( & V_93 ) - V_96 ;
for (; V_96 < ( unsigned long ) ( & V_93 ) ; V_96 += V_50 ) {
struct V_76 * V_98 ;
memset ( ( void * ) V_96 , V_99 , V_50 ) ;
V_98 = F_50 ( V_96 ) ;
F_41 ( V_98 ) ;
F_42 ( V_98 ) ;
F_43 ( V_98 ) ;
V_10 ++ ;
V_89 ++ ;
}
F_6 ( V_95 L_17 ,
V_97 >> 10 ) ;
}
void F_51 ( unsigned long V_73 , unsigned long V_74 )
{
if ( V_73 < V_74 )
F_6 ( V_95 L_18 ,
( V_74 - V_73 ) >> 10 ) ;
for (; V_73 < V_74 ; V_73 += V_50 ) {
struct V_76 * V_98 ;
memset ( ( void * ) V_73 , V_99 , V_50 ) ;
V_98 = F_50 ( V_73 ) ;
F_41 ( V_98 ) ;
F_42 ( V_98 ) ;
F_43 ( V_98 ) ;
V_10 ++ ;
V_89 ++ ;
}
}
void F_52 ( struct V_76 * V_76 )
{
unsigned long V_100 = ( unsigned long ) F_53 ( V_76 ) ;
if ( V_100 )
F_54 ( V_100 ) ;
}
