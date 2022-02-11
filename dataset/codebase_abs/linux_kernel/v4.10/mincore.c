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
V_14 = F_12 ( F_13 ( V_15 ) ,
F_14 ( V_15 ) ) ;
}
} else
V_14 = F_12 ( V_12 , V_13 ) ;
#else
V_14 = F_12 ( V_12 , V_13 ) ;
#endif
if ( V_14 ) {
V_7 = F_15 ( V_14 ) ;
F_16 ( V_14 ) ;
}
return V_7 ;
}
static int F_17 ( unsigned long V_3 , unsigned long V_4 ,
struct V_16 * V_17 , unsigned char * V_8 )
{
unsigned long V_18 = ( V_4 - V_3 ) >> V_19 ;
int V_20 ;
if ( V_17 -> V_21 ) {
T_2 V_13 ;
V_13 = F_18 ( V_17 , V_3 ) ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ , V_13 ++ )
V_8 [ V_20 ] = F_6 ( V_17 -> V_21 -> V_22 , V_13 ) ;
} else {
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ )
V_8 [ V_20 ] = 0 ;
}
return V_18 ;
}
static int F_19 ( unsigned long V_3 , unsigned long V_4 ,
struct V_5 * V_6 )
{
V_6 -> V_9 += F_17 ( V_3 , V_4 ,
V_6 -> V_17 , V_6 -> V_9 ) ;
return 0 ;
}
static int F_20 ( T_4 * V_23 , unsigned long V_3 , unsigned long V_4 ,
struct V_5 * V_6 )
{
T_5 * V_24 ;
struct V_16 * V_17 = V_6 -> V_17 ;
T_1 * V_25 ;
unsigned char * V_8 = V_6 -> V_9 ;
int V_18 = ( V_4 - V_3 ) >> V_19 ;
V_24 = F_21 ( V_23 , V_17 ) ;
if ( V_24 ) {
memset ( V_8 , 1 , V_18 ) ;
F_22 ( V_24 ) ;
goto V_26;
}
if ( F_23 ( V_23 ) ) {
F_17 ( V_3 , V_4 , V_17 , V_8 ) ;
goto V_26;
}
V_25 = F_24 ( V_6 -> V_27 , V_23 , V_3 , & V_24 ) ;
for (; V_3 != V_4 ; V_25 ++ , V_3 += V_10 ) {
T_1 V_1 = * V_25 ;
if ( F_25 ( V_1 ) )
F_17 ( V_3 , V_3 + V_10 ,
V_17 , V_8 ) ;
else if ( F_26 ( V_1 ) )
* V_8 = 1 ;
else {
T_3 V_28 = F_27 ( V_1 ) ;
if ( F_28 ( V_28 ) ) {
* V_8 = 1 ;
} else {
#ifdef F_7
* V_8 = F_6 ( F_13 ( V_28 ) ,
F_14 ( V_28 ) ) ;
#else
F_29 ( 1 ) ;
* V_8 = 1 ;
#endif
}
}
V_8 ++ ;
}
F_30 ( V_25 - 1 , V_24 ) ;
V_26:
V_6 -> V_9 += V_18 ;
F_31 () ;
return 0 ;
}
static long F_32 ( unsigned long V_3 , unsigned long V_29 , unsigned char * V_8 )
{
struct V_16 * V_17 ;
unsigned long V_4 ;
int V_30 ;
struct V_5 V_31 = {
. V_32 = F_20 ,
. V_33 = F_19 ,
. V_34 = F_1 ,
. V_9 = V_8 ,
} ;
V_17 = F_33 ( V_35 -> V_27 , V_3 ) ;
if ( ! V_17 || V_3 < V_17 -> V_36 )
return - V_37 ;
V_31 . V_27 = V_17 -> V_38 ;
V_4 = F_34 ( V_17 -> V_39 , V_3 + ( V_29 << V_19 ) ) ;
V_30 = F_35 ( V_3 , V_4 , & V_31 ) ;
if ( V_30 < 0 )
return V_30 ;
return ( V_4 - V_3 ) >> V_19 ;
}
