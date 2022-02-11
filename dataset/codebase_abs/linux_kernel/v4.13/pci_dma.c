static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( ! F_3 ( V_2 ) ) ;
if ( V_3 < 0x7fffffff )
return 0 ;
return 1 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( ! F_3 ( V_2 ) ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return 0 ;
* V_2 -> V_4 = V_4 ;
return 1 ;
}
static void * F_5 ( struct V_1 * V_2 , T_2 V_5 ,
T_3 * V_6 , T_4 V_7 ,
unsigned long V_8 )
{
void * V_9 ;
unsigned long V_10 ;
int V_11 ;
struct V_12 * V_13 = F_6 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
F_2 ( ! F_3 ( V_2 ) ) ;
V_11 = F_8 ( V_13 -> V_16 ) ;
if ( F_9 ( V_11 >= 0 ) ) {
struct V_17 * V_18 = F_10 ( V_11 ,
V_7 , F_11 ( V_5 ) ) ;
if ( F_9 ( V_18 ) )
V_9 = F_12 ( V_18 ) ;
else
return NULL ;
} else
V_9 = ( void * ) F_13 ( V_7 , F_11 ( V_5 ) ) ;
if ( F_14 ( ! V_9 ) )
return NULL ;
memset ( V_9 , 0x0 , V_5 ) ;
V_10 = F_15 ( V_9 ) ;
* V_6 = V_15 -> V_19 ( V_13 , V_10 , V_5 ,
V_20 ) ;
if ( ! * V_6 ) {
F_16 ( V_21 L_1 , V_22 ) ;
F_17 ( ( unsigned long ) V_9 , F_11 ( V_5 ) ) ;
return NULL ;
}
return V_9 ;
}
static void F_18 ( struct V_1 * V_2 , T_2 V_5 , void * V_23 ,
T_3 V_6 , unsigned long V_8 )
{
struct V_12 * V_13 = F_6 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
F_2 ( ! F_3 ( V_2 ) ) ;
V_15 -> V_24 ( V_13 , V_6 , 0 ) ;
F_17 ( ( unsigned long ) V_23 , F_11 ( V_5 ) ) ;
}
static T_3 F_19 ( struct V_1 * V_2 , struct V_17 * V_17 ,
unsigned long V_25 , T_2 V_5 ,
enum V_26 V_27 ,
unsigned long V_8 )
{
void * V_23 = F_12 ( V_17 ) + V_25 ;
T_3 V_28 ;
unsigned long V_10 ;
struct V_12 * V_13 = F_6 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
F_2 ( ! F_3 ( V_2 ) ) ;
V_10 = F_15 ( V_23 ) ;
if ( V_8 & V_29 )
V_28 = V_15 -> V_19 ( V_13 , V_10 ,
V_5 , V_20 ) ;
else
V_28 = V_15 -> V_30 ( V_13 , V_10 , V_5 ,
V_20 ) ;
if ( ! V_28 ) {
F_16 ( V_21 L_1 , V_22 ) ;
return 0 ;
}
return V_28 ;
}
static void F_20 ( struct V_1 * V_2 , T_3 V_28 ,
T_2 V_5 , enum V_26 V_27 ,
unsigned long V_8 )
{
struct V_12 * V_13 = F_6 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
F_2 ( ! F_3 ( V_2 ) ) ;
V_15 -> V_24 ( V_13 , V_28 , V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_31 * V_32 ,
int V_33 , enum V_26 V_27 ,
unsigned long V_8 )
{
int V_34 ;
struct V_12 * V_13 = F_6 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_31 * V_35 ;
F_2 ( ! F_3 ( V_2 ) ) ;
F_22 (sgl, sg, nhwentries, i) {
V_15 -> V_24 ( V_13 , V_35 -> V_36 , V_27 ) ;
V_35 -> V_36 = ( T_3 ) NULL ;
V_35 -> V_37 = 0 ;
}
}
static int F_23 ( struct V_1 * V_2 , struct V_31 * V_32 ,
int V_33 , enum V_26 V_27 ,
unsigned long V_8 )
{
unsigned long V_10 ;
struct V_31 * V_38 = V_32 , * V_35 ;
struct V_12 * V_13 = F_6 ( V_2 ) ;
struct V_14 * V_15 = F_7 ( V_13 ) ;
int V_34 ;
F_2 ( ! F_3 ( V_2 ) ) ;
F_22 (sgl, sg, nhwentries, i) {
T_3 V_28 ;
V_10 = F_24 ( V_35 ) ;
if ( V_8 & V_29 )
V_28 = V_15 -> V_19 ( V_13 ,
V_10 ,
V_35 -> V_39 ,
V_20 ) ;
else
V_28 = V_15 -> V_30 ( V_13 , V_10 ,
V_35 -> V_39 ,
V_20 ) ;
V_35 -> V_36 = V_28 ;
if ( ! V_35 -> V_36 ) {
F_16 ( V_21 L_1 , V_22 ) ;
if ( V_34 > 0 )
F_21 ( V_2 , V_38 , V_34 , V_27 , V_8 ) ;
return 0 ;
}
V_35 -> V_37 = V_35 -> V_39 ;
}
return V_33 ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_6 ,
T_2 V_5 , enum V_26 V_27 )
{
F_2 ( ! F_3 ( V_2 ) ) ;
}
static void F_26 ( struct V_1 * V_2 , T_3 V_6 ,
T_2 V_5 ,
enum V_26 V_27 )
{
F_2 ( ! F_3 ( V_2 ) ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_31 * V_35 ,
int V_40 , enum V_26 V_27 )
{
F_2 ( ! F_3 ( V_2 ) ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_31 * V_35 ,
int V_40 , enum V_26 V_27 )
{
F_2 ( ! F_3 ( V_2 ) ) ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_28 )
{
return 0 ;
}
T_1 F_30 ( struct V_1 * V_2 )
{
return F_31 ( 64 ) ;
}
char * F_32 ( struct V_41 * V_16 )
{
if ( ! F_33 ( V_16 ) )
return F_34 ( - V_42 ) ;
return ( char * ) ( F_33 ( V_16 ) -> V_43 | V_44 ) ;
}
int F_35 ( struct V_41 * V_16 , T_5 V_45 , T_6 * V_46 , T_7 V_5 )
{
unsigned long V_47 ;
int V_48 ;
struct V_49 V_50 ;
F_36 ( V_50 , V_51 ,
F_37 ( V_16 ) , V_16 -> V_52 ,
0 ,
0 ,
V_45 , V_5 , F_15 ( V_46 ) ) ;
if ( V_50 . V_53 == 0 )
return V_5 ;
if ( ! F_33 ( V_16 ) )
return - V_42 ;
V_47 = F_33 ( V_16 ) -> V_54 | V_44 ;
V_47 += V_45 ;
V_48 = F_38 ( V_47 , ( long ) V_5 , ( void * ) V_46 ) ;
if ( V_48 == 2 )
return - V_55 ;
if ( V_48 == 1 )
* V_46 = - 1 ;
return V_5 ;
}
int F_39 ( struct V_41 * V_16 , T_5 V_45 , T_6 V_46 , T_7 V_5 )
{
int V_48 = V_5 ;
unsigned long V_56 ;
unsigned long * V_47 ;
struct V_49 V_50 ;
F_36 ( V_50 , V_51 ,
F_37 ( V_16 ) , V_16 -> V_52 ,
0 ,
1 ,
V_45 , V_5 , F_15 ( & V_46 ) ) ;
if ( V_50 . V_53 == 0 )
return V_5 ;
if ( ! F_33 ( V_16 ) ) {
V_48 = - V_42 ;
goto V_57;
}
V_56 = F_33 ( V_16 ) -> V_54 | V_44 ;
V_56 += V_45 ;
V_47 = ( unsigned long * ) V_56 ;
switch ( V_5 ) {
case 1 :
* ( volatile T_7 * ) ( V_47 ) = ( T_7 ) ( V_46 ) ;
break;
case 2 :
* ( volatile T_5 * ) ( V_47 ) = ( T_5 ) ( V_46 ) ;
break;
case 4 :
* ( volatile T_6 * ) ( V_47 ) = ( T_6 ) ( V_46 ) ;
break;
default:
V_48 = - V_55 ;
break;
}
V_57:
return V_48 ;
}
void F_40 ( void )
{
V_58 = & V_59 ;
}
