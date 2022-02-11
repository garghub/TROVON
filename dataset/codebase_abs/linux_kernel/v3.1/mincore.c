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
V_16 = F_10 ( & V_18 , V_17 . V_19 ) ;
}
#endif
if ( V_16 ) {
V_8 = F_14 ( V_16 ) ;
F_15 ( V_16 ) ;
}
return V_8 ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_20 = ( V_4 - V_3 ) >> V_21 ;
int V_22 ;
if ( V_2 -> V_23 ) {
T_2 V_15 ;
V_15 = F_17 ( V_2 , V_3 ) ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ , V_15 ++ )
V_5 [ V_22 ] = F_9 ( V_2 -> V_23 -> V_24 , V_15 ) ;
} else {
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
V_5 [ V_22 ] = 0 ;
}
}
static void F_18 ( struct V_1 * V_2 , T_4 * V_25 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_26 ;
T_5 * V_27 ;
T_1 * V_9 ;
V_9 = F_19 ( V_2 -> V_28 , V_25 , V_3 , & V_27 ) ;
do {
T_1 V_29 = * V_9 ;
T_2 V_15 ;
V_26 = V_3 + V_12 ;
if ( F_20 ( V_29 ) )
F_16 ( V_2 , V_3 , V_26 , V_5 ) ;
else if ( F_21 ( V_29 ) )
* V_5 = 1 ;
else if ( F_22 ( V_29 ) ) {
V_15 = F_23 ( V_29 ) ;
* V_5 = F_9 ( V_2 -> V_23 -> V_24 , V_15 ) ;
} else {
T_3 V_30 = F_24 ( V_29 ) ;
if ( F_25 ( V_30 ) ) {
* V_5 = 1 ;
} else {
#ifdef F_11
V_15 = V_30 . V_19 ;
* V_5 = F_9 ( & V_18 , V_15 ) ;
#else
F_26 ( 1 ) ;
* V_5 = 1 ;
#endif
}
}
V_5 ++ ;
} while ( V_9 ++ , V_3 = V_26 , V_3 != V_4 );
F_27 ( V_9 - 1 , V_27 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_6 * V_31 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_26 ;
T_4 * V_25 ;
V_25 = F_29 ( V_31 , V_3 ) ;
do {
V_26 = F_30 ( V_3 , V_4 ) ;
if ( F_31 ( * V_25 ) ) {
if ( F_32 ( V_2 , V_25 , V_3 , V_26 , V_5 ) ) {
V_5 += ( V_26 - V_3 ) >> V_21 ;
continue;
}
}
if ( F_33 ( V_25 ) )
F_16 ( V_2 , V_3 , V_26 , V_5 ) ;
else
F_18 ( V_2 , V_25 , V_3 , V_26 , V_5 ) ;
V_5 += ( V_26 - V_3 ) >> V_21 ;
} while ( V_25 ++ , V_3 = V_26 , V_3 != V_4 );
}
static void F_34 ( struct V_1 * V_2 , T_7 * V_32 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_26 ;
T_6 * V_31 ;
V_31 = F_35 ( V_32 , V_3 ) ;
do {
V_26 = F_36 ( V_3 , V_4 ) ;
if ( F_37 ( V_31 ) )
F_16 ( V_2 , V_3 , V_26 , V_5 ) ;
else
F_28 ( V_2 , V_31 , V_3 , V_26 , V_5 ) ;
V_5 += ( V_26 - V_3 ) >> V_21 ;
} while ( V_31 ++ , V_3 = V_26 , V_3 != V_4 );
}
static void F_38 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned char * V_5 )
{
unsigned long V_26 ;
T_7 * V_32 ;
V_32 = F_39 ( V_2 -> V_28 , V_3 ) ;
do {
V_26 = F_40 ( V_3 , V_4 ) ;
if ( F_41 ( V_32 ) )
F_16 ( V_2 , V_3 , V_26 , V_5 ) ;
else
F_34 ( V_2 , V_32 , V_3 , V_26 , V_5 ) ;
V_5 += ( V_26 - V_3 ) >> V_21 ;
} while ( V_32 ++ , V_3 = V_26 , V_3 != V_4 );
}
static long F_42 ( unsigned long V_3 , unsigned long V_33 , unsigned char * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_4 ;
V_2 = F_43 ( V_10 -> V_11 , V_3 ) ;
if ( ! V_2 || V_3 < V_2 -> V_34 )
return - V_35 ;
V_4 = F_44 ( V_2 -> V_36 , V_3 + ( V_33 << V_21 ) ) ;
if ( F_45 ( V_2 ) ) {
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
return ( V_4 - V_3 ) >> V_21 ;
}
V_4 = F_30 ( V_3 , V_4 ) ;
if ( F_45 ( V_2 ) )
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
else
F_38 ( V_2 , V_3 , V_4 , V_5 ) ;
return ( V_4 - V_3 ) >> V_21 ;
}
