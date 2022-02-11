static int F_1 ( unsigned long V_1 , unsigned long V_2 , T_1 V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
T_5 * V_7 ;
int V_8 = - V_9 ;
V_4 = F_2 ( V_1 ) ;
V_5 = F_3 ( V_4 , V_1 ) ;
V_6 = F_4 ( V_5 , V_1 ) ;
V_7 = F_5 ( V_6 , V_1 ) ;
if ( V_7 != 0 ) {
V_8 = 0 ;
F_6 ( V_7 , F_7 ( V_2 & V_10 , V_3 ) ) ;
}
return V_8 ;
}
void * F_8 ( T_6 V_11 , T_7 V_12 , T_8 * V_13 )
{
struct V_14 * V_15 ;
unsigned long V_16 , V_1 , V_2 ;
void * V_17 ;
int V_18 , V_8 , V_19 ;
if ( F_9 () )
F_10 () ;
V_12 = F_11 ( V_12 ) ;
V_18 = F_12 ( V_12 ) ;
V_16 = F_13 ( V_11 , V_18 ) ;
if ( ! V_16 ) {
F_10 () ;
return NULL ;
}
V_15 = F_14 ( V_12 , V_20 ) ;
if ( V_15 == 0 ) {
F_15 ( V_16 , V_18 ) ;
return NULL ;
}
V_1 = F_16 ( V_15 -> V_21 ) ;
V_17 = ( void * ) V_1 ;
* V_13 = V_2 = F_17 ( ( void * ) V_16 ) ;
if ( V_18 > 0 ) {
struct V_16 * V_22 = F_18 ( V_16 ) ;
F_19 ( V_22 , V_18 ) ;
}
V_8 = 0 ;
for ( V_19 = 0 ; V_19 < V_12 && V_8 == 0 ; V_19 += V_23 )
V_8 = F_1 ( V_1 + V_19 , V_2 + V_19 , V_24 ) ;
if ( V_8 ) {
F_20 ( ( void * ) V_1 ) ;
return NULL ;
}
F_21 ( V_1 , V_1 + V_12 ) ;
return V_17 ;
}
void F_22 ( void * V_25 )
{
if ( F_9 () )
F_10 () ;
F_20 ( V_25 ) ;
}
void F_23 ( void * V_25 , T_7 V_12 , int V_26 )
{
unsigned long V_27 = ( unsigned long ) V_25 ;
unsigned long V_28 = V_27 + V_12 ;
switch ( V_26 ) {
case V_29 :
F_10 () ;
case V_30 :
F_21 ( V_27 , V_28 ) ;
break;
case V_31 :
F_24 ( V_27 , V_28 ) ;
break;
case V_32 :
F_24 ( V_27 , V_28 ) ;
break;
}
}
void F_25 ( struct V_16 * V_16 , unsigned long V_33 ,
T_7 V_12 , int V_26 )
{
void * V_27 ;
V_27 = F_26 ( V_16 ) + V_33 ;
F_23 ( V_27 , V_12 , V_26 ) ;
}
