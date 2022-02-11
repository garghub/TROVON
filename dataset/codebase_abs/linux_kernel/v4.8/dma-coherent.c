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
static void * F_17 ( struct V_1 * V_2 , T_1 V_4 ,
T_2 * V_11 , T_3 V_12 , unsigned long V_17 )
{
struct V_10 * V_10 ;
T_2 V_18 ;
V_10 = F_7 ( V_2 , V_4 , V_11 , V_12 ) ;
if ( ! V_10 )
return NULL ;
V_18 = F_13 ( V_10 ) ;
if ( V_17 & V_19 ) {
* V_11 = V_18 ;
return F_18 ( V_18 , V_4 , V_20 ) ;
} else {
return F_19 ( V_18 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , T_1 V_4 ,
void * V_21 , T_2 V_11 , unsigned long V_17 )
{
struct V_10 * V_10 ;
if ( V_17 & V_19 ) {
F_21 ( V_21 ) ;
V_10 = F_22 ( V_11 ) ;
} else {
void * V_22 = F_23 ( F_24 ( V_21 ) ) ;
F_25 ( L_1 ,
V_21 , ( unsigned long ) V_11 , ( unsigned ) V_4 ) ;
F_26 ( ! F_27 ( V_22 ) ) ;
V_10 = F_28 ( V_22 ) ;
}
F_16 ( V_2 , V_4 , V_10 , V_11 ) ;
}
static T_2 F_29 ( struct V_1 * V_2 , struct V_10 * V_10 ,
unsigned long V_23 , T_1 V_4 ,
enum V_24 V_5 , unsigned long V_17 )
{
void * V_21 = F_30 ( V_10 ) + V_23 ;
F_1 ( V_2 , V_21 , V_4 , V_5 ) ;
return F_31 ( V_21 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_27 , enum V_24 V_5 ,
unsigned long V_17 )
{
int V_28 ;
struct V_25 * V_29 ;
F_33 (sglist, sg, nents, i) {
char * V_30 ;
V_29 -> V_31 = F_14 ( F_34 ( V_29 ) ) + V_29 -> V_23 ;
V_30 = F_35 ( V_29 ) ;
F_1 ( V_2 , V_30 , V_29 -> V_32 , V_5 ) ;
}
return V_27 ;
}
static void F_36 ( struct V_1 * V_2 ,
T_2 V_33 , T_1 V_4 ,
enum V_24 V_5 )
{
F_1 ( V_2 , F_37 ( V_33 ) , V_4 , V_5 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_25 * V_26 , int V_27 ,
enum V_24 V_5 )
{
int V_28 ;
struct V_25 * V_29 ;
F_33 (sglist, sg, nents, i)
F_1 ( V_2 , F_35 ( V_29 ) , V_29 -> V_32 , V_5 ) ;
}
