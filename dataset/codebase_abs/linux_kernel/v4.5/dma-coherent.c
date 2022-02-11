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
T_2 * V_11 , T_3 V_12 , struct V_17 * V_18 )
{
struct V_10 * V_10 ;
T_2 V_19 ;
V_10 = F_7 ( V_2 , V_4 , V_11 , V_12 ) ;
if ( ! V_10 )
return NULL ;
V_19 = F_13 ( V_10 ) ;
if ( F_18 ( V_20 , V_18 ) ) {
* V_11 = V_19 ;
return F_19 ( V_19 , V_4 , V_21 ) ;
} else {
return F_20 ( V_19 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , T_1 V_4 ,
void * V_22 , T_2 V_11 , struct V_17 * V_18 )
{
struct V_10 * V_10 ;
if ( F_18 ( V_20 , V_18 ) ) {
F_22 ( V_22 ) ;
V_10 = F_23 ( V_11 ) ;
} else {
void * V_23 = F_24 ( F_25 ( V_22 ) ) ;
F_26 ( L_1 ,
V_22 , ( unsigned long ) V_11 , ( unsigned ) V_4 ) ;
F_27 ( ! F_28 ( V_23 ) ) ;
V_10 = F_29 ( V_23 ) ;
}
F_16 ( V_2 , V_4 , V_10 , V_11 ) ;
}
static T_2 F_30 ( struct V_1 * V_2 , struct V_10 * V_10 ,
unsigned long V_24 , T_1 V_4 ,
enum V_25 V_5 , struct V_17 * V_18 )
{
void * V_22 = F_31 ( V_10 ) + V_24 ;
F_1 ( V_2 , V_22 , V_4 , V_5 ) ;
return F_32 ( V_22 ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_26 * V_27 ,
int V_28 , enum V_25 V_5 ,
struct V_17 * V_18 )
{
int V_29 ;
struct V_26 * V_30 ;
F_34 (sglist, sg, nents, i) {
char * V_31 ;
V_30 -> V_32 = F_14 ( F_35 ( V_30 ) ) + V_30 -> V_24 ;
V_31 = F_36 ( V_30 ) ;
F_1 ( V_2 , V_31 , V_30 -> V_33 , V_5 ) ;
}
return V_28 ;
}
static void F_37 ( struct V_1 * V_2 ,
T_2 V_34 , T_1 V_4 ,
enum V_25 V_5 )
{
F_1 ( V_2 , F_38 ( V_34 ) , V_4 , V_5 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_26 * V_27 , int V_28 ,
enum V_25 V_5 )
{
int V_29 ;
struct V_26 * V_30 ;
F_34 (sglist, sg, nents, i)
F_1 ( V_2 , F_36 ( V_30 ) , V_30 -> V_33 , V_5 ) ;
}
