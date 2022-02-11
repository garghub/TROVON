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
if ( V_16 ) {
V_8 = F_11 ( V_16 ) ;
F_12 ( V_16 ) ;
}
return V_8 ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_17 = ( V_4 - V_3 ) >> V_18 ;
int V_19 ;
if ( V_2 -> V_20 ) {
T_2 V_15 ;
V_15 = F_14 ( V_2 , V_3 ) ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ , V_15 ++ )
V_5 [ V_19 ] = F_9 ( V_2 -> V_20 -> V_21 , V_15 ) ;
} else {
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ )
V_5 [ V_19 ] = 0 ;
}
}
static void F_15 ( struct V_1 * V_2 , T_3 * V_22 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_23 ;
T_4 * V_24 ;
T_1 * V_9 ;
V_9 = F_16 ( V_2 -> V_25 , V_22 , V_3 , & V_24 ) ;
do {
T_1 V_26 = * V_9 ;
T_2 V_15 ;
V_23 = V_3 + V_12 ;
if ( F_17 ( V_26 ) )
F_13 ( V_2 , V_3 , V_23 , V_5 ) ;
else if ( F_18 ( V_26 ) )
* V_5 = 1 ;
else if ( F_19 ( V_26 ) ) {
V_15 = F_20 ( V_26 ) ;
* V_5 = F_9 ( V_2 -> V_20 -> V_21 , V_15 ) ;
} else {
T_5 V_27 = F_21 ( V_26 ) ;
if ( F_22 ( V_27 ) ) {
* V_5 = 1 ;
} else {
#ifdef F_23
V_15 = V_27 . V_28 ;
* V_5 = F_9 ( & V_29 , V_15 ) ;
#else
F_24 ( 1 ) ;
* V_5 = 1 ;
#endif
}
}
V_5 ++ ;
} while ( V_9 ++ , V_3 = V_23 , V_3 != V_4 );
F_25 ( V_9 - 1 , V_24 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_6 * V_30 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_23 ;
T_3 * V_22 ;
V_22 = F_27 ( V_30 , V_3 ) ;
do {
V_23 = F_28 ( V_3 , V_4 ) ;
if ( F_29 ( * V_22 ) ) {
if ( F_30 ( V_2 , V_22 , V_3 , V_23 , V_5 ) ) {
V_5 += ( V_23 - V_3 ) >> V_18 ;
continue;
}
}
if ( F_31 ( V_22 ) )
F_13 ( V_2 , V_3 , V_23 , V_5 ) ;
else
F_15 ( V_2 , V_22 , V_3 , V_23 , V_5 ) ;
V_5 += ( V_23 - V_3 ) >> V_18 ;
} while ( V_22 ++ , V_3 = V_23 , V_3 != V_4 );
}
static void F_32 ( struct V_1 * V_2 , T_7 * V_31 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_23 ;
T_6 * V_30 ;
V_30 = F_33 ( V_31 , V_3 ) ;
do {
V_23 = F_34 ( V_3 , V_4 ) ;
if ( F_35 ( V_30 ) )
F_13 ( V_2 , V_3 , V_23 , V_5 ) ;
else
F_26 ( V_2 , V_30 , V_3 , V_23 , V_5 ) ;
V_5 += ( V_23 - V_3 ) >> V_18 ;
} while ( V_30 ++ , V_3 = V_23 , V_3 != V_4 );
}
static void F_36 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_23 ;
T_7 * V_31 ;
V_31 = F_37 ( V_2 -> V_25 , V_3 ) ;
do {
V_23 = F_38 ( V_3 , V_4 ) ;
if ( F_39 ( V_31 ) )
F_13 ( V_2 , V_3 , V_23 , V_5 ) ;
else
F_32 ( V_2 , V_31 , V_3 , V_23 , V_5 ) ;
V_5 += ( V_23 - V_3 ) >> V_18 ;
} while ( V_31 ++ , V_3 = V_23 , V_3 != V_4 );
}
static long F_40 ( unsigned long V_3 , unsigned long V_32 , unsigned char * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_4 ;
V_2 = F_41 ( V_10 -> V_11 , V_3 ) ;
if ( ! V_2 || V_3 < V_2 -> V_33 )
return - V_34 ;
V_4 = F_42 ( V_2 -> V_35 , V_3 + ( V_32 << V_18 ) ) ;
if ( F_43 ( V_2 ) ) {
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
return ( V_4 - V_3 ) >> V_18 ;
}
V_4 = F_28 ( V_3 , V_4 ) ;
if ( F_43 ( V_2 ) )
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
else
F_36 ( V_2 , V_3 , V_4 , V_5 ) ;
return ( V_4 - V_3 ) >> V_18 ;
}
