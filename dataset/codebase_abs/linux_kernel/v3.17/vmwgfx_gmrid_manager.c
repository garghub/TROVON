static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 =
(struct V_10 * ) V_2 -> V_12 ;
int V_13 = 0 ;
int V_14 ;
V_9 -> V_15 = NULL ;
F_2 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_17 > 0 ) {
V_11 -> V_18 += V_4 -> V_19 ;
if ( F_3 ( V_11 -> V_18 > V_11 -> V_17 ) )
goto V_20;
}
do {
F_4 ( & V_11 -> V_16 ) ;
if ( F_3 ( F_5 ( & V_11 -> V_21 , V_22 ) == 0 ) ) {
V_13 = - V_23 ;
goto V_24;
}
F_2 ( & V_11 -> V_16 ) ;
V_13 = F_6 ( & V_11 -> V_21 , & V_14 ) ;
if ( F_3 ( V_13 == 0 && V_14 >= V_11 -> V_25 ) ) {
F_7 ( & V_11 -> V_21 , V_14 ) ;
V_13 = 0 ;
goto V_20;
}
} while ( V_13 == - V_26 );
if ( F_8 ( V_13 == 0 ) ) {
V_9 -> V_15 = V_11 ;
V_9 -> V_27 = V_14 ;
V_9 -> V_19 = V_4 -> V_19 ;
} else
goto V_20;
F_4 ( & V_11 -> V_16 ) ;
return 0 ;
V_24:
F_2 ( & V_11 -> V_16 ) ;
V_20:
V_11 -> V_18 -= V_4 -> V_19 ;
F_4 ( & V_11 -> V_16 ) ;
return V_13 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 =
(struct V_10 * ) V_2 -> V_12 ;
if ( V_9 -> V_15 ) {
F_2 ( & V_11 -> V_16 ) ;
F_7 ( & V_11 -> V_21 , V_9 -> V_27 ) ;
V_11 -> V_18 -= V_9 -> V_19 ;
F_4 ( & V_11 -> V_16 ) ;
V_9 -> V_15 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_28 )
{
struct V_29 * V_30 =
F_11 ( V_2 -> V_31 , struct V_29 , V_31 ) ;
struct V_10 * V_11 =
F_12 ( sizeof( * V_11 ) , V_22 ) ;
if ( F_3 ( V_11 == NULL ) )
return - V_23 ;
F_13 ( & V_11 -> V_16 ) ;
V_11 -> V_18 = 0 ;
F_14 ( & V_11 -> V_21 ) ;
switch ( V_28 ) {
case V_32 :
V_11 -> V_25 = V_30 -> V_25 ;
V_11 -> V_17 = V_30 -> V_17 ;
break;
case V_33 :
V_11 -> V_25 = V_34 ;
V_11 -> V_17 = V_30 -> V_35 ;
break;
default:
F_15 () ;
}
V_2 -> V_12 = ( void * ) V_11 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 =
(struct V_10 * ) V_2 -> V_12 ;
if ( V_11 ) {
F_17 ( & V_11 -> V_21 ) ;
F_18 ( V_11 ) ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
const char * V_36 )
{
F_20 ( V_37 L_1
L_2 , V_36 ) ;
}
