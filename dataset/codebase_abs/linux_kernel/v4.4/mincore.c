static int F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned long V_3 ,
unsigned long V_4 , struct V_5 * V_6 )
{
#ifdef F_2
unsigned char V_7 ;
unsigned char * V_8 = V_6 -> V_9 ;
V_7 = V_1 && ! F_3 ( F_4 ( V_1 ) ) ;
for (; V_3 != V_4 ; V_8 ++ , V_3 += V_10 )
* V_8 = V_7 ;
V_6 -> V_9 = V_8 ;
#else
F_5 () ;
#endif
return 0 ;
}
static unsigned char F_6 ( struct V_11 * V_12 , T_2 V_13 )
{
unsigned char V_7 = 0 ;
struct V_14 * V_14 ;
#ifdef F_7
if ( F_8 ( V_12 ) ) {
V_14 = F_9 ( V_12 , V_13 ) ;
if ( F_10 ( V_14 ) ) {
T_3 V_15 = F_11 ( V_14 ) ;
V_14 = F_12 ( F_13 ( V_15 ) , V_15 . V_16 ) ;
}
} else
V_14 = F_12 ( V_12 , V_13 ) ;
#else
V_14 = F_12 ( V_12 , V_13 ) ;
#endif
if ( V_14 ) {
V_7 = F_14 ( V_14 ) ;
F_15 ( V_14 ) ;
}
return V_7 ;
}
static int F_16 ( unsigned long V_3 , unsigned long V_4 ,
struct V_17 * V_18 , unsigned char * V_8 )
{
unsigned long V_19 = ( V_4 - V_3 ) >> V_20 ;
int V_21 ;
if ( V_18 -> V_22 ) {
T_2 V_13 ;
V_13 = F_17 ( V_18 , V_3 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ , V_13 ++ )
V_8 [ V_21 ] = F_6 ( V_18 -> V_22 -> V_23 , V_13 ) ;
} else {
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
V_8 [ V_21 ] = 0 ;
}
return V_19 ;
}
static int F_18 ( unsigned long V_3 , unsigned long V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_9 += F_16 ( V_3 , V_4 ,
V_6 -> V_18 , V_6 -> V_9 ) ;
return 0 ;
}
static int F_19 ( T_4 * V_24 , unsigned long V_3 , unsigned long V_4 ,
struct V_5 * V_6 )
{
T_5 * V_25 ;
struct V_17 * V_18 = V_6 -> V_18 ;
T_1 * V_26 ;
unsigned char * V_8 = V_6 -> V_9 ;
int V_19 = ( V_4 - V_3 ) >> V_20 ;
if ( F_20 ( V_24 , V_18 , & V_25 ) == 1 ) {
memset ( V_8 , 1 , V_19 ) ;
F_21 ( V_25 ) ;
goto V_27;
}
if ( F_22 ( V_24 ) ) {
F_16 ( V_3 , V_4 , V_18 , V_8 ) ;
goto V_27;
}
V_26 = F_23 ( V_6 -> V_28 , V_24 , V_3 , & V_25 ) ;
for (; V_3 != V_4 ; V_26 ++ , V_3 += V_10 ) {
T_1 V_1 = * V_26 ;
if ( F_24 ( V_1 ) )
F_16 ( V_3 , V_3 + V_10 ,
V_18 , V_8 ) ;
else if ( F_25 ( V_1 ) )
* V_8 = 1 ;
else {
T_3 V_29 = F_26 ( V_1 ) ;
if ( F_27 ( V_29 ) ) {
* V_8 = 1 ;
} else {
#ifdef F_7
* V_8 = F_6 ( F_13 ( V_29 ) ,
V_29 . V_16 ) ;
#else
F_28 ( 1 ) ;
* V_8 = 1 ;
#endif
}
}
V_8 ++ ;
}
F_29 ( V_26 - 1 , V_25 ) ;
V_27:
V_6 -> V_9 += V_19 ;
F_30 () ;
return 0 ;
}
static long F_31 ( unsigned long V_3 , unsigned long V_30 , unsigned char * V_8 )
{
struct V_17 * V_18 ;
unsigned long V_4 ;
int V_31 ;
struct V_5 V_32 = {
. V_33 = F_19 ,
. V_34 = F_18 ,
. V_35 = F_1 ,
. V_9 = V_8 ,
} ;
V_18 = F_32 ( V_36 -> V_28 , V_3 ) ;
if ( ! V_18 || V_3 < V_18 -> V_37 )
return - V_38 ;
V_32 . V_28 = V_18 -> V_39 ;
V_4 = F_33 ( V_18 -> V_40 , V_3 + ( V_30 << V_20 ) ) ;
V_31 = F_34 ( V_3 , V_4 , & V_32 ) ;
if ( V_31 < 0 )
return V_31 ;
return ( V_4 - V_3 ) >> V_20 ;
}
