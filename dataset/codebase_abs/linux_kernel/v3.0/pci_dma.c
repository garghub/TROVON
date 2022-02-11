static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_4 != & V_5 ) ;
if ( V_3 < 0x7fffffff )
return 0 ;
return 1 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_6 )
{
F_2 ( V_2 -> V_4 != & V_5 ) ;
if ( ! F_1 ( V_2 , V_6 ) )
return 0 ;
* V_2 -> V_6 = V_6 ;
return 1 ;
}
static void * F_4 ( struct V_1 * V_2 , T_2 V_7 ,
T_3 * V_8 , T_4 V_9 )
{
void * V_10 ;
unsigned long V_11 ;
int V_12 ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_14 ) ;
F_2 ( V_2 -> V_4 != & V_5 ) ;
V_12 = F_7 ( V_14 -> V_4 ) ;
if ( F_8 ( V_12 >= 0 ) ) {
struct V_17 * V_18 = F_9 ( V_12 ,
V_9 , F_10 ( V_7 ) ) ;
if ( F_8 ( V_18 ) )
V_10 = F_11 ( V_18 ) ;
else
return NULL ;
} else
V_10 = ( void * ) F_12 ( V_9 , F_10 ( V_7 ) ) ;
if ( F_13 ( ! V_10 ) )
return NULL ;
memset ( V_10 , 0x0 , V_7 ) ;
V_11 = F_14 ( V_10 ) ;
* V_8 = V_16 -> V_19 ( V_14 , V_11 , V_7 ,
V_20 ) ;
if ( ! * V_8 ) {
F_15 ( V_21 L_1 , V_22 ) ;
F_16 ( ( unsigned long ) V_10 , F_10 ( V_7 ) ) ;
return NULL ;
}
return V_10 ;
}
static void F_17 ( struct V_1 * V_2 , T_2 V_7 , void * V_23 ,
T_3 V_8 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_14 ) ;
F_2 ( V_2 -> V_4 != & V_5 ) ;
V_16 -> V_24 ( V_14 , V_8 , 0 ) ;
F_16 ( ( unsigned long ) V_23 , F_10 ( V_7 ) ) ;
}
static T_3 F_18 ( struct V_1 * V_2 , struct V_17 * V_17 ,
unsigned long V_25 , T_2 V_7 ,
enum V_26 V_27 ,
struct V_28 * V_29 )
{
void * V_23 = F_11 ( V_17 ) + V_25 ;
T_3 V_30 ;
unsigned long V_11 ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_14 ) ;
int V_31 ;
V_31 = F_19 ( V_32 , V_29 ) ;
F_2 ( V_2 -> V_4 != & V_5 ) ;
V_11 = F_14 ( V_23 ) ;
if ( V_31 )
V_30 = V_16 -> V_19 ( V_14 , V_11 ,
V_7 , V_20 ) ;
else
V_30 = V_16 -> V_33 ( V_14 , V_11 , V_7 ,
V_20 ) ;
if ( ! V_30 ) {
F_15 ( V_21 L_1 , V_22 ) ;
return 0 ;
}
return V_30 ;
}
static void F_20 ( struct V_1 * V_2 , T_3 V_30 ,
T_2 V_7 , enum V_26 V_27 ,
struct V_28 * V_29 )
{
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_14 ) ;
F_2 ( V_2 -> V_4 != & V_5 ) ;
V_16 -> V_24 ( V_14 , V_30 , V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 , enum V_26 V_27 ,
struct V_28 * V_29 )
{
int V_37 ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_14 ) ;
struct V_34 * V_38 ;
F_2 ( V_2 -> V_4 != & V_5 ) ;
F_22 (sgl, sg, nhwentries, i) {
V_16 -> V_24 ( V_14 , V_38 -> V_39 , V_27 ) ;
V_38 -> V_39 = ( T_3 ) NULL ;
V_38 -> V_40 = 0 ;
}
}
static int F_23 ( struct V_1 * V_2 , struct V_34 * V_35 ,
int V_36 , enum V_26 V_27 ,
struct V_28 * V_29 )
{
unsigned long V_11 ;
struct V_34 * V_41 = V_35 , * V_38 ;
struct V_13 * V_14 = F_5 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_14 ) ;
int V_37 ;
int V_31 ;
V_31 = F_19 ( V_32 , V_29 ) ;
F_2 ( V_2 -> V_4 != & V_5 ) ;
F_22 (sgl, sg, nhwentries, i) {
T_3 V_30 ;
V_11 = F_24 ( V_38 ) ;
if ( V_31 )
V_30 = V_16 -> V_19 ( V_14 ,
V_11 ,
V_38 -> V_42 ,
V_20 ) ;
else
V_30 = V_16 -> V_33 ( V_14 , V_11 ,
V_38 -> V_42 ,
V_20 ) ;
V_38 -> V_39 = V_30 ;
if ( ! V_38 -> V_39 ) {
F_15 ( V_21 L_1 , V_22 ) ;
if ( V_37 > 0 )
F_21 ( V_2 , V_41 , V_37 , V_27 , V_29 ) ;
return 0 ;
}
V_38 -> V_40 = V_38 -> V_42 ;
}
return V_36 ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_8 ,
T_2 V_7 , enum V_26 V_27 )
{
F_2 ( V_2 -> V_4 != & V_5 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_3 V_8 ,
T_2 V_7 ,
enum V_26 V_27 )
{
F_2 ( V_2 -> V_4 != & V_5 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_34 * V_38 ,
int V_43 , enum V_26 V_27 )
{
F_2 ( V_2 -> V_4 != & V_5 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_34 * V_38 ,
int V_43 , enum V_26 V_27 )
{
F_2 ( V_2 -> V_4 != & V_5 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_30 )
{
return 0 ;
}
T_1 F_30 ( struct V_1 * V_2 )
{
return F_31 ( 64 ) ;
}
char * F_32 ( struct V_44 * V_4 )
{
if ( ! F_33 ( V_4 ) )
return F_34 ( - V_45 ) ;
return ( char * ) ( F_33 ( V_4 ) -> V_46 | V_47 ) ;
}
int F_35 ( struct V_44 * V_4 , T_5 V_48 , T_6 * V_49 , T_7 V_7 )
{
unsigned long V_50 ;
int V_51 ;
struct V_52 V_53 ;
F_36 ( V_53 , V_54 ,
F_37 ( V_4 ) , V_4 -> V_55 ,
0 ,
0 ,
V_48 , V_7 , F_14 ( V_49 ) ) ;
if ( V_53 . V_56 == 0 )
return V_7 ;
if ( ! F_33 ( V_4 ) )
return - V_45 ;
V_50 = F_33 ( V_4 ) -> V_57 | V_47 ;
V_50 += V_48 ;
V_51 = F_38 ( V_50 , ( long ) V_7 , ( void * ) V_49 ) ;
if ( V_51 == 2 )
return - V_58 ;
if ( V_51 == 1 )
* V_49 = - 1 ;
return V_7 ;
}
int F_39 ( struct V_44 * V_4 , T_5 V_48 , T_6 V_49 , T_7 V_7 )
{
int V_51 = V_7 ;
unsigned long V_59 ;
unsigned long * V_50 ;
struct V_52 V_53 ;
F_36 ( V_53 , V_54 ,
F_37 ( V_4 ) , V_4 -> V_55 ,
0 ,
1 ,
V_48 , V_7 , F_14 ( & V_49 ) ) ;
if ( V_53 . V_56 == 0 )
return V_7 ;
if ( ! F_33 ( V_4 ) ) {
V_51 = - V_45 ;
goto V_60;
}
V_59 = F_33 ( V_4 ) -> V_57 | V_47 ;
V_59 += V_48 ;
V_50 = ( unsigned long * ) V_59 ;
switch ( V_7 ) {
case 1 :
* ( volatile T_7 * ) ( V_50 ) = ( T_7 ) ( V_49 ) ;
break;
case 2 :
* ( volatile T_5 * ) ( V_50 ) = ( T_5 ) ( V_49 ) ;
break;
case 4 :
* ( volatile T_6 * ) ( V_50 ) = ( T_6 ) ( V_49 ) ;
break;
default:
V_51 = - V_58 ;
break;
}
V_60:
return V_51 ;
}
void F_40 ( void )
{
V_61 = & V_62 ;
}
