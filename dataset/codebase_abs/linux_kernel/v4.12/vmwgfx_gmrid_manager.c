static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_2 -> V_11 ;
int V_12 = 0 ;
int V_13 ;
V_8 -> V_14 = NULL ;
F_2 ( & V_10 -> V_15 ) ;
if ( V_10 -> V_16 > 0 ) {
V_10 -> V_17 += V_4 -> V_18 ;
if ( F_3 ( V_10 -> V_17 > V_10 -> V_16 ) )
goto V_19;
}
do {
F_4 ( & V_10 -> V_15 ) ;
if ( F_3 ( F_5 ( & V_10 -> V_20 , V_21 ) == 0 ) ) {
V_12 = - V_22 ;
goto V_23;
}
F_2 ( & V_10 -> V_15 ) ;
V_12 = F_6 ( & V_10 -> V_20 , & V_13 ) ;
if ( F_3 ( V_12 == 0 && V_13 >= V_10 -> V_24 ) ) {
F_7 ( & V_10 -> V_20 , V_13 ) ;
V_12 = 0 ;
goto V_19;
}
} while ( V_12 == - V_25 );
if ( F_8 ( V_12 == 0 ) ) {
V_8 -> V_14 = V_10 ;
V_8 -> V_26 = V_13 ;
V_8 -> V_18 = V_4 -> V_18 ;
} else
goto V_19;
F_4 ( & V_10 -> V_15 ) ;
return 0 ;
V_23:
F_2 ( & V_10 -> V_15 ) ;
V_19:
V_10 -> V_17 -= V_4 -> V_18 ;
F_4 ( & V_10 -> V_15 ) ;
return V_12 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_2 -> V_11 ;
if ( V_8 -> V_14 ) {
F_2 ( & V_10 -> V_15 ) ;
F_7 ( & V_10 -> V_20 , V_8 -> V_26 ) ;
V_10 -> V_17 -= V_8 -> V_18 ;
F_4 ( & V_10 -> V_15 ) ;
V_8 -> V_14 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_27 )
{
struct V_28 * V_29 =
F_11 ( V_2 -> V_30 , struct V_28 , V_30 ) ;
struct V_9 * V_10 =
F_12 ( sizeof( * V_10 ) , V_21 ) ;
if ( F_3 ( V_10 == NULL ) )
return - V_22 ;
F_13 ( & V_10 -> V_15 ) ;
V_10 -> V_17 = 0 ;
F_14 ( & V_10 -> V_20 ) ;
switch ( V_27 ) {
case V_31 :
V_10 -> V_24 = V_29 -> V_24 ;
V_10 -> V_16 = V_29 -> V_16 ;
break;
case V_32 :
V_10 -> V_24 = V_33 ;
V_10 -> V_16 = V_29 -> V_34 ;
break;
default:
F_15 () ;
}
V_2 -> V_11 = ( void * ) V_10 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_2 -> V_11 ;
if ( V_10 ) {
F_17 ( & V_10 -> V_20 ) ;
F_18 ( V_10 ) ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
const char * V_35 )
{
F_20 ( L_1 , V_35 ) ;
}
