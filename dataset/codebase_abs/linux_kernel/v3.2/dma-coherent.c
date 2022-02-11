void F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , int V_5 )
{
if ( F_2 ( V_3 ) == V_6 )
return;
switch ( V_5 ) {
case V_7 :
F_3 ( V_3 , V_4 ) ;
break;
case V_8 :
F_4 ( V_3 , V_4 ) ;
break;
case V_9 :
F_5 ( V_3 , V_4 ) ;
break;
default:
F_6 () ;
}
}
static struct V_10 * F_7 ( struct V_1 * V_2 , T_1 V_4 ,
T_2 * V_11 , T_3 V_12 )
{
struct V_10 * V_10 , * free , * V_13 ;
int V_14 ;
V_12 &= ~ ( V_15 ) ;
V_4 = F_8 ( V_4 ) ;
V_14 = F_9 ( V_4 ) ;
V_10 = F_10 ( V_12 , V_14 ) ;
if ( ! V_10 )
return NULL ;
F_11 ( V_10 , V_14 ) ;
F_3 ( F_12 ( F_13 ( V_10 ) ) , V_4 ) ;
* V_11 = F_14 ( V_10 ) ;
free = V_10 + ( V_4 >> V_16 ) ;
V_13 = V_10 + ( 1 << V_14 ) ;
while ( free < V_13 ) {
F_15 ( free ) ;
free ++ ;
}
return V_10 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_4 ,
struct V_10 * V_10 , T_2 V_11 )
{
struct V_10 * V_13 = V_10 + ( F_8 ( V_4 ) >> V_16 ) ;
while ( V_10 < V_13 )
F_15 ( V_10 ++ ) ;
}
void * F_17 ( struct V_1 * V_2 , T_1 V_4 ,
T_2 * V_11 , T_3 V_12 )
{
struct V_10 * V_10 ;
void * V_17 = NULL ;
V_10 = F_7 ( V_2 , V_4 , V_11 , V_12 ) ;
if ( V_10 )
V_17 = F_18 ( F_13 ( V_10 ) ) ;
return V_17 ;
}
void F_19 ( struct V_1 * V_2 , T_1 V_4 ,
void * V_18 , T_2 V_11 )
{
void * V_19 = F_20 ( F_21 ( V_18 ) ) ;
struct V_10 * V_10 ;
F_22 ( L_1 ,
V_18 , ( unsigned long ) V_11 , ( unsigned ) V_4 ) ;
F_23 ( ! F_24 ( V_19 ) ) ;
V_10 = F_25 ( V_19 ) ;
F_16 ( V_2 , V_4 , V_10 , V_11 ) ;
}
void * F_26 ( struct V_1 * V_2 , T_1 V_4 ,
T_2 * V_11 , T_3 V_12 )
{
struct V_10 * V_10 ;
T_2 V_20 ;
V_10 = F_7 ( V_2 , V_4 , V_11 , V_12 ) ;
if ( ! V_10 )
return NULL ;
V_20 = F_13 ( V_10 ) ;
* V_11 = V_20 ;
return F_27 ( V_20 , V_4 , V_21 ) ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_4 ,
void * V_18 , T_2 V_11 )
{
struct V_10 * V_10 ;
F_29 ( V_18 ) ;
V_10 = F_30 ( V_11 ) ;
F_16 ( V_2 , V_4 , V_10 , V_11 ) ;
}
