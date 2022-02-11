static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
#ifdef F_2
struct V_6 * V_7 ;
V_7 = F_3 ( V_2 ) ;
while ( 1 ) {
unsigned char V_8 ;
T_1 * V_9 ;
V_9 = F_4 ( V_10 -> V_11 ,
V_3 & F_5 ( V_7 ) ) ;
V_8 = V_9 && ! F_6 ( F_7 ( V_9 ) ) ;
while ( 1 ) {
* V_5 = V_8 ;
V_5 ++ ;
V_3 += V_12 ;
if ( V_3 == V_4 )
return;
if ( ! ( V_3 & ~ F_5 ( V_7 ) ) )
break;
}
}
#else
F_8 () ;
#endif
}
static unsigned char F_9 ( struct V_13 * V_14 , T_2 V_15 )
{
unsigned char V_8 = 0 ;
struct V_16 * V_16 ;
V_16 = F_10 ( V_14 , V_15 ) ;
#ifdef F_11
if ( F_12 ( V_16 ) ) {
T_3 V_17 = F_13 ( V_16 ) ;
V_16 = F_10 ( F_14 ( V_17 ) , V_17 . V_18 ) ;
}
#endif
if ( V_16 ) {
V_8 = F_15 ( V_16 ) ;
F_16 ( V_16 ) ;
}
return V_8 ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_19 = ( V_4 - V_3 ) >> V_20 ;
int V_21 ;
if ( V_2 -> V_22 ) {
T_2 V_15 ;
V_15 = F_18 ( V_2 , V_3 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ , V_15 ++ )
V_5 [ V_21 ] = F_9 ( V_2 -> V_22 -> V_23 , V_15 ) ;
} else {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
V_5 [ V_21 ] = 0 ;
}
}
static void F_19 ( struct V_1 * V_2 , T_4 * V_24 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_25 ;
T_5 * V_26 ;
T_1 * V_9 ;
V_9 = F_20 ( V_2 -> V_27 , V_24 , V_3 , & V_26 ) ;
do {
T_1 V_28 = * V_9 ;
T_2 V_15 ;
V_25 = V_3 + V_12 ;
if ( F_21 ( V_28 ) )
F_17 ( V_2 , V_3 , V_25 , V_5 ) ;
else if ( F_22 ( V_28 ) )
* V_5 = 1 ;
else if ( F_23 ( V_28 ) ) {
V_15 = F_24 ( V_28 ) ;
* V_5 = F_9 ( V_2 -> V_22 -> V_23 , V_15 ) ;
} else {
T_3 V_29 = F_25 ( V_28 ) ;
if ( F_26 ( V_29 ) ) {
* V_5 = 1 ;
} else {
#ifdef F_11
V_15 = V_29 . V_18 ;
* V_5 = F_9 ( F_14 ( V_29 ) ,
V_15 ) ;
#else
F_27 ( 1 ) ;
* V_5 = 1 ;
#endif
}
}
V_5 ++ ;
} while ( V_9 ++ , V_3 = V_25 , V_3 != V_4 );
F_28 ( V_9 - 1 , V_26 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_6 * V_30 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_25 ;
T_4 * V_24 ;
V_24 = F_30 ( V_30 , V_3 ) ;
do {
V_25 = F_31 ( V_3 , V_4 ) ;
if ( F_32 ( * V_24 ) ) {
if ( F_33 ( V_2 , V_24 , V_3 , V_25 , V_5 ) ) {
V_5 += ( V_25 - V_3 ) >> V_20 ;
continue;
}
}
if ( F_34 ( V_24 ) )
F_17 ( V_2 , V_3 , V_25 , V_5 ) ;
else
F_19 ( V_2 , V_24 , V_3 , V_25 , V_5 ) ;
V_5 += ( V_25 - V_3 ) >> V_20 ;
} while ( V_24 ++ , V_3 = V_25 , V_3 != V_4 );
}
static void F_35 ( struct V_1 * V_2 , T_7 * V_31 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_25 ;
T_6 * V_30 ;
V_30 = F_36 ( V_31 , V_3 ) ;
do {
V_25 = F_37 ( V_3 , V_4 ) ;
if ( F_38 ( V_30 ) )
F_17 ( V_2 , V_3 , V_25 , V_5 ) ;
else
F_29 ( V_2 , V_30 , V_3 , V_25 , V_5 ) ;
V_5 += ( V_25 - V_3 ) >> V_20 ;
} while ( V_30 ++ , V_3 = V_25 , V_3 != V_4 );
}
static void F_39 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_25 ;
T_7 * V_31 ;
V_31 = F_40 ( V_2 -> V_27 , V_3 ) ;
do {
V_25 = F_41 ( V_3 , V_4 ) ;
if ( F_42 ( V_31 ) )
F_17 ( V_2 , V_3 , V_25 , V_5 ) ;
else
F_35 ( V_2 , V_31 , V_3 , V_25 , V_5 ) ;
V_5 += ( V_25 - V_3 ) >> V_20 ;
} while ( V_31 ++ , V_3 = V_25 , V_3 != V_4 );
}
static long F_43 ( unsigned long V_3 , unsigned long V_32 , unsigned char * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_4 ;
V_2 = F_44 ( V_10 -> V_11 , V_3 ) ;
if ( ! V_2 || V_3 < V_2 -> V_33 )
return - V_34 ;
V_4 = F_45 ( V_2 -> V_35 , V_3 + ( V_32 << V_20 ) ) ;
if ( F_46 ( V_2 ) )
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
else
F_39 ( V_2 , V_3 , V_4 , V_5 ) ;
return ( V_4 - V_3 ) >> V_20 ;
}
