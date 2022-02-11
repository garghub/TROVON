void F_1 ( T_1 V_1 )
{
#if 0
unsigned long val = pte_val (pte);
pr_cont(" pte=%lx [addr=%lx",
val, (val & SUN3_PAGE_PGNUM_MASK) << PAGE_SHIFT);
if (val & SUN3_PAGE_VALID) pr_cont(" valid");
if (val & SUN3_PAGE_WRITEABLE) pr_cont(" write");
if (val & SUN3_PAGE_SYSTEM) pr_cont(" sys");
if (val & SUN3_PAGE_NOCACHE) pr_cont(" nocache");
if (val & SUN3_PAGE_ACCESSED) pr_cont(" accessed");
if (val & SUN3_PAGE_MODIFIED) pr_cont(" modified");
switch (val & SUN3_PAGE_TYPE_MASK) {
case SUN3_PAGE_TYPE_MEMORY: pr_cont(" memory"); break;
case SUN3_PAGE_TYPE_IO: pr_cont(" io"); break;
case SUN3_PAGE_TYPE_VME16: pr_cont(" vme16"); break;
case SUN3_PAGE_TYPE_VME32: pr_cont(" vme32"); break;
}
pr_cont("]\n");
#else
unsigned long V_2 = F_2 ( V_1 ) ;
char V_3 [ 7 ] , * type ;
V_3 [ 0 ] = ( V_2 & V_4 ) ? 'v' : '-' ;
V_3 [ 1 ] = ( V_2 & V_5 ) ? 'w' : '-' ;
V_3 [ 2 ] = ( V_2 & V_6 ) ? 's' : '-' ;
V_3 [ 3 ] = ( V_2 & V_7 ) ? 'x' : '-' ;
V_3 [ 4 ] = ( V_2 & V_8 ) ? 'a' : '-' ;
V_3 [ 5 ] = ( V_2 & V_9 ) ? 'm' : '-' ;
V_3 [ 6 ] = '\0' ;
switch ( V_2 & V_10 ) {
case V_11 : type = L_1 ; break;
case V_12 : type = L_2 ; break;
case V_13 : type = L_3 ; break;
case V_14 : type = L_4 ; break;
default: type = L_5 ; break;
}
F_3 ( L_6 ,
V_2 , ( V_2 & V_15 ) << V_16 , V_3 , type ) ;
#endif
}
void F_4 ( unsigned long V_17 )
{
F_3 ( L_7 , V_17 , F_5 ( V_17 ) ) ;
F_1 ( F_6 ( F_7 ( V_17 ) ) ) ;
}
void T_2 F_8 ( unsigned long V_18 )
{
unsigned long V_19 , V_20 ;
int V_21 , V_22 ;
memset ( V_23 , 0 , sizeof( V_23 ) ) ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
memset ( V_25 , 0 , sizeof( V_25 ) ) ;
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
V_18 = ( V_18 + ( 2 * V_27 ) ) & ~ V_28 ;
for ( V_21 = 0 ; V_21 < F_9 ( V_18 ) / V_27 ; ++ V_21 )
V_25 [ V_21 ] = 2 ;
for( V_20 = 0xf0 ; V_20 <= 0xff ; V_20 ++ )
V_25 [ V_20 ] = 2 ;
for( V_19 = V_18 ; V_19 < 0x0f800000 ; V_19 += V_27 ) {
V_21 = F_5 ( V_19 ) ;
if( ! V_25 [ V_21 ] ) {
#ifdef F_10
F_11 ( L_8 ) ;
F_4 ( V_19 ) ;
#endif
F_12 ( V_19 , V_29 ) ;
}
}
V_22 = 0 ;
for ( V_20 = 0 , V_19 = 0x0F800000 ; V_19 < 0x10000000 ; V_19 += 16 * V_30 ) {
if ( F_5 ( V_19 ) != V_29 ) {
#ifdef F_13
for( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
F_11 ( L_9 ) ;
F_4 ( V_19 + ( V_21 * V_30 ) ) ;
break;
}
#endif
if ( ! V_31 )
V_31 = V_19 ;
V_25 [ F_5 ( V_19 ) ] = 2 ;
}
}
F_14 () ;
for( V_19 = 0 ; V_19 < V_32 ; V_19 += V_27 )
F_12 ( V_19 , V_29 ) ;
F_15 ( F_16 ( 3 ) ) ;
for( V_19 = 0 ; V_19 < 0x10000000 ; V_19 += V_27 ) {
V_21 = F_5 ( V_19 ) ;
for( V_22 = 1 ; V_22 < V_33 ; V_22 ++ )
( * ( V_34 -> V_35 ) ) ( V_22 , ( void * ) V_19 , V_21 ) ;
}
F_15 ( V_36 ) ;
}
void F_17 ( unsigned long V_37 )
{
unsigned char V_38 ;
unsigned long V_21 ;
if( V_37 ) {
if( ! V_39 [ V_37 ] )
F_18 ( L_10 ) ;
V_39 [ V_37 ] -> V_37 = V_40 ;
V_39 [ V_37 ] = (struct V_41 * ) 0 ;
V_42 ++ ;
}
V_38 = F_19 () ;
F_20 ( V_37 ) ;
for( V_21 = 0 ; V_21 < V_29 ; V_21 ++ ) {
if( ( V_26 [ V_21 ] == V_37 ) && ( V_25 [ V_21 ] == 1 ) ) {
F_12 ( V_24 [ V_21 ] , V_29 ) ;
V_26 [ V_21 ] = 0 ;
V_25 [ V_21 ] = 0 ;
V_24 [ V_21 ] = 0 ;
}
}
F_20 ( V_38 ) ;
}
unsigned long F_21 ( struct V_41 * V_43 )
{
unsigned long V_44 = 1 ;
static unsigned char V_45 = 1 ;
if( ! V_42 ) {
V_44 = V_45 ;
F_17 ( V_44 ) ;
V_45 = ( V_45 + 1 ) & 0x7 ;
if( ! V_45 )
V_45 ++ ;
} else {
while( V_44 < V_33 ) {
if( V_39 [ V_44 ] )
V_44 ++ ;
else
break;
}
if( V_44 == V_33 )
F_18 ( L_11 ) ;
}
V_39 [ V_44 ] = V_43 ;
V_42 -- ;
return V_44 ;
}
inline void F_22 ( int V_37 , int V_17 )
{
static unsigned char V_46 = 128 ;
int V_21 ;
V_17 &= ~ V_28 ;
while ( V_25 [ V_46 ] == 2 )
++ V_46 ;
#ifdef F_10
F_11 ( L_12 ,
V_46 , V_37 , V_17 ) ;
#endif
if ( V_25 [ V_46 ] == 1 ) {
F_20 ( V_26 [ V_46 ] ) ;
F_12 ( V_24 [ V_46 ] , V_29 ) ;
F_20 ( V_37 ) ;
}
if( V_17 >= V_32 ) {
unsigned char V_21 ;
for( V_21 = 0 ; V_21 < V_33 ; V_21 ++ ) {
F_20 ( V_21 ) ;
F_12 ( V_17 , V_46 ) ;
}
F_20 ( V_37 ) ;
V_25 [ V_46 ] = 2 ;
V_26 [ V_46 ] = 0 ;
}
else {
V_25 [ V_46 ] = 1 ;
V_26 [ V_46 ] = V_37 ;
F_12 ( V_17 , V_46 ) ;
}
V_24 [ V_46 ] = V_17 ;
for ( V_21 = 0 ; V_21 < V_27 ; V_21 += V_47 )
F_23 ( V_17 + V_21 , V_6 ) ;
++ V_46 ;
}
int F_24 ( unsigned long V_17 , int V_48 , int V_49 )
{
unsigned long V_50 , V_51 ;
unsigned char V_37 ;
T_1 * V_1 ;
T_3 * V_52 ;
if( V_53 -> V_43 == NULL ) {
V_52 = V_54 ;
V_37 = 0 ;
} else {
V_37 = V_53 -> V_43 -> V_37 ;
if( V_49 )
V_52 = V_54 ;
else
V_52 = V_53 -> V_43 -> V_55 ;
}
#ifdef F_10
F_11 ( L_13 ,
V_17 , V_48 ? L_14 : L_15 , V_52 ) ;
#endif
V_50 = ( V_17 >> V_56 ) & 0x7FF ;
V_51 = ( V_17 >> V_57 ) & 0xF ;
#ifdef F_10
F_11 ( L_16 , V_50 ,
V_51 ) ;
#endif
V_1 = ( T_1 * ) F_25 ( * ( V_52 + V_50 ) ) ;
if ( ! V_1 ) {
return 0 ;
}
V_1 = ( T_1 * ) F_26 ( ( unsigned long ) ( V_1 + V_51 ) ) ;
if ( ! ( F_2 ( * V_1 ) & V_4 ) )
return 0 ;
if ( F_5 ( V_17 & ~ V_28 ) == V_29 )
F_22 ( V_37 , V_17 ) ;
F_23 ( V_17 & V_58 , F_2 ( * V_1 ) ) ;
if ( ! V_48 ) {
if ( F_2 ( * V_1 ) & V_5 )
F_2 ( * V_1 ) |= ( V_8
| V_9 ) ;
else
return 0 ;
} else
F_2 ( * V_1 ) |= V_8 ;
#ifdef F_10
F_11 ( L_17 , F_27 () . V_19 , V_52 ) ;
F_4 ( V_17 ) ;
F_3 ( L_18 ) ;
#endif
return 1 ;
}
