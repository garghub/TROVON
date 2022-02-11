static int F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_2 * V_6 ;
int V_7 = 0 ;
V_6 = F_2 ( V_1 , V_2 ) ;
for (; ; ) {
V_7 = V_5 -> V_8 ( V_6 , V_2 , V_2 + V_9 , V_5 ) ;
if ( V_7 )
break;
V_2 += V_9 ;
if ( V_2 == V_3 )
break;
V_6 ++ ;
}
F_3 ( V_6 ) ;
return V_7 ;
}
static int F_4 ( T_3 * V_10 , unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_1 * V_1 ;
unsigned long V_11 ;
int V_7 = 0 ;
V_1 = F_5 ( V_10 , V_2 ) ;
do {
V_12:
V_11 = F_6 ( V_2 , V_3 ) ;
if ( F_7 ( * V_1 ) ) {
if ( V_5 -> V_13 )
V_7 = V_5 -> V_13 ( V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
continue;
}
if ( V_5 -> V_14 )
V_7 = V_5 -> V_14 ( V_1 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
if ( ! V_5 -> V_8 )
continue;
F_8 ( V_5 -> V_15 , V_1 ) ;
if ( F_9 ( V_1 ) )
goto V_12;
V_7 = F_1 ( V_1 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_1 ++ , V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
static int F_10 ( T_4 * V_16 , unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_3 * V_10 ;
unsigned long V_11 ;
int V_7 = 0 ;
V_10 = F_11 ( V_16 , V_2 ) ;
do {
V_11 = F_12 ( V_2 , V_3 ) ;
if ( F_13 ( V_10 ) ) {
if ( V_5 -> V_13 )
V_7 = V_5 -> V_13 ( V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
continue;
}
if ( V_5 -> V_17 )
V_7 = V_5 -> V_17 ( V_10 , V_2 , V_11 , V_5 ) ;
if ( ! V_7 && ( V_5 -> V_14 || V_5 -> V_8 ) )
V_7 = F_4 ( V_10 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
} while ( V_10 ++ , V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
static unsigned long F_14 ( struct V_18 * V_19 , unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_20 = ( V_2 & F_15 ( V_19 ) ) + F_16 ( V_19 ) ;
return V_20 < V_3 ? V_20 : V_3 ;
}
static int F_17 ( struct V_21 * V_22 ,
unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
struct V_18 * V_19 = F_18 ( V_22 ) ;
unsigned long V_11 ;
unsigned long V_23 = F_15 ( V_19 ) ;
T_2 * V_6 ;
int V_7 = 0 ;
do {
V_11 = F_14 ( V_19 , V_2 , V_3 ) ;
V_6 = F_19 ( V_5 -> V_15 , V_2 & V_23 ) ;
if ( V_6 && V_5 -> V_24 )
V_7 = V_5 -> V_24 ( V_6 , V_23 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
return V_7 ;
} while ( V_2 = V_11 , V_2 != V_3 );
return 0 ;
}
int F_20 ( unsigned long V_2 , unsigned long V_3 ,
struct V_4 * V_5 )
{
T_4 * V_16 ;
unsigned long V_11 ;
int V_7 = 0 ;
if ( V_2 >= V_3 )
return V_7 ;
if ( ! V_5 -> V_15 )
return - V_25 ;
V_16 = F_21 ( V_5 -> V_15 , V_2 ) ;
do {
struct V_21 * V_26 ( V_22 ) ;
V_11 = F_22 ( V_2 , V_3 ) ;
#ifdef F_23
V_22 = F_24 ( V_5 -> V_15 , V_2 ) ;
if ( V_22 && F_25 ( V_22 ) ) {
if ( V_22 -> V_27 < V_11 )
V_11 = V_22 -> V_27 ;
V_7 = F_17 ( V_22 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
V_16 = F_21 ( V_5 -> V_15 , V_11 ) ;
continue;
}
#endif
if ( F_26 ( V_16 ) ) {
if ( V_5 -> V_13 )
V_7 = V_5 -> V_13 ( V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
V_16 ++ ;
continue;
}
if ( V_5 -> V_28 )
V_7 = V_5 -> V_28 ( V_16 , V_2 , V_11 , V_5 ) ;
if ( ! V_7 &&
( V_5 -> V_17 || V_5 -> V_14 || V_5 -> V_8 ) )
V_7 = F_10 ( V_16 , V_2 , V_11 , V_5 ) ;
if ( V_7 )
break;
V_16 ++ ;
} while ( V_2 = V_11 , V_2 != V_3 );
return V_7 ;
}
