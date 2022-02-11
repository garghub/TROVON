static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_5 , V_6 ) ;
++ V_2 -> V_7 ;
V_2 -> V_4 += V_2 -> V_5 ;
if ( V_2 -> V_7 >= V_2 -> V_8 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_4 = V_2 -> V_9 ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_5 , V_6 ) ;
++ V_2 -> V_7 ;
V_2 -> V_4 += V_2 -> V_5 ;
if ( V_2 -> V_7 >= V_2 -> V_8 ) {
V_2 -> V_7 = 0 ;
V_2 -> V_4 = V_2 -> V_9 ;
}
}
static void F_5 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
V_2 -> V_12 += V_2 -> V_5 ;
if ( ++ V_2 -> V_13 >= V_2 -> V_8 ) {
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
}
F_6 ( V_2 -> V_14 ) ;
F_1 ( V_2 ) ;
}
static void F_7 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
V_2 -> V_12 += V_2 -> V_5 ;
if ( ++ V_2 -> V_13 >= V_2 -> V_8 ) {
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
}
F_6 ( V_2 -> V_14 ) ;
F_3 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_15 )
{
if ( V_15 -> V_3 ) {
F_9 ( V_15 -> V_3 ) ;
F_10 ( V_15 -> V_3 ) ;
F_11 ( V_15 -> V_3 ) ;
V_15 -> V_3 = 0 ;
V_15 -> V_16 = 0 ;
}
}
static int F_12 ( struct V_1 * V_15 ,
int V_17 , int V_16 )
{
if ( V_16 == 24 )
V_16 = 32 ;
if ( ( V_15 -> V_3 ) && ( V_16 == V_15 -> V_16 ) )
goto V_18;
F_8 ( V_15 ) ;
if ( V_17 == V_19 )
V_15 -> V_3 = F_13 ( V_15 -> V_20 ,
V_21 ,
F_7 , ( void * ) V_15 ) ;
else
V_15 -> V_3 = F_13 ( V_21 ,
V_15 -> V_20 ,
F_5 , ( void * ) V_15 ) ;
if ( ! V_15 -> V_3 )
return - V_22 ;
F_14 ( V_15 -> V_3 , V_16 ) ;
F_15 ( V_15 -> V_3 , 2 ) ;
V_15 -> V_16 = V_16 ;
F_9 ( V_15 -> V_3 ) ;
F_10 ( V_15 -> V_3 ) ;
V_18:
return 0 ;
}
static inline struct V_1 * F_16 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_1 * V_15 =
F_17 ( V_26 -> V_28 ) ;
return & V_15 [ V_24 -> V_29 ] ;
}
static int F_18 ( struct V_23 * V_14 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = V_14 -> V_33 ;
struct V_1 * V_15 ;
int V_17 , V_34 ;
V_34 = F_19 ( V_14 , F_20 ( V_31 ) ) ;
if ( V_34 < 0 )
goto V_18;
V_17 = V_14 -> V_29 ;
V_15 = F_16 ( V_14 ) ;
F_21 ( L_1
L_2 ,
( unsigned long ) V_33 -> V_4 ,
( unsigned long ) V_33 -> V_35 , V_33 -> V_36 ,
V_33 -> V_37 ) ;
F_21 ( L_3 , V_31 -> V_16 ,
F_22 ( V_31 ) , F_23 ( V_31 ) , V_17 ) ;
V_34 = F_12 ( V_15 , V_17 , V_31 -> V_16 ) ;
if ( V_34 ) {
F_24 ( L_4 ) ;
goto V_18;
}
V_15 -> V_14 = V_14 ;
V_15 -> V_5 = F_23 ( V_31 ) ;
V_15 -> V_8 = F_22 ( V_31 ) ;
V_15 -> V_9 = V_15 -> V_4 = V_33 -> V_35 ;
V_15 -> V_7 = 0 ;
V_15 -> V_13 = 0 ;
V_15 -> V_12 = 0 ;
V_34 = 0 ;
V_18:
return V_34 ;
}
static int F_25 ( struct V_23 * V_14 )
{
F_26 ( V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_23 * V_14 )
{
struct V_1 * V_15 = F_16 ( V_14 ) ;
F_10 ( V_15 -> V_3 ) ;
if ( V_14 -> V_29 == V_19 ) {
F_3 ( V_15 ) ;
F_3 ( V_15 ) ;
} else {
F_1 ( V_15 ) ;
F_1 ( V_15 ) ;
}
return 0 ;
}
static int F_28 ( struct V_23 * V_14 , int V_38 )
{
T_1 V_39 = F_16 ( V_14 ) -> V_3 ;
switch ( V_38 ) {
case V_40 :
case V_41 :
F_29 ( V_39 ) ;
break;
case V_42 :
case V_43 :
F_9 ( V_39 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static T_2
F_30 ( struct V_23 * V_14 )
{
return F_31 ( V_14 -> V_33 , F_16 ( V_14 ) -> V_12 ) ;
}
static int F_32 ( struct V_23 * V_14 )
{
struct V_1 * V_15 = F_16 ( V_14 ) ;
struct V_25 * V_26 = V_14 -> V_27 ;
int V_17 = V_14 -> V_29 , * V_45 ;
V_45 = F_33 ( V_26 -> V_46 , V_14 ) ;
if ( ! V_45 )
return - V_47 ;
V_15 -> V_20 = V_45 [ V_17 ] ;
F_34 ( V_14 , & V_48 ) ;
return 0 ;
}
static int F_35 ( struct V_23 * V_14 )
{
F_8 ( F_16 ( V_14 ) ) ;
return 0 ;
}
static int F_36 ( struct V_25 * V_26 )
{
struct V_49 * V_50 = V_26 -> V_50 -> V_49 ;
struct V_51 * V_52 = V_26 -> V_52 ;
F_37 ( V_52 , V_53 ,
V_50 -> V_54 , V_55 , ( 4096 * 1024 ) - 1 ) ;
return 0 ;
}
static int F_38 ( struct V_56 * V_57 )
{
struct V_1 * V_58 ;
V_58 = F_39 ( & V_57 -> V_54 ,
2 * sizeof( struct V_1 ) ,
V_59 ) ;
if ( ! V_58 )
return - V_22 ;
F_40 ( V_57 , V_58 ) ;
return F_41 ( & V_57 -> V_54 , & V_60 ) ;
}
static int F_42 ( struct V_56 * V_57 )
{
F_43 ( & V_57 -> V_54 ) ;
return 0 ;
}
