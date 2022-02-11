static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 , NULL , 0 , 0 , V_5 ) ;
F_4 ( & V_4 ) ;
if ( F_5 ( V_3 < 0 ) )
return V_3 ;
* V_2 = V_3 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( & V_4 ) ;
F_7 ( V_1 , V_2 ) ;
F_4 ( & V_4 ) ;
}
static int F_8 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
int V_9 ;
struct V_10 * V_11 = V_7 -> V_12 -> V_11 . V_13 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_14 ; V_9 ++ ) {
struct V_15 * V_16 ;
int V_3 = 0 ;
unsigned int V_17 = V_7 -> V_18 [ V_9 ] ;
bool V_19 = V_9 >= V_8 ? true : false ;
F_9 () ;
V_16 = F_10 ( V_11 , V_17 , ! V_19 ) ;
F_11 () ;
if ( F_12 ( V_16 ) == - V_20 )
continue;
else if ( F_13 ( V_16 ) )
return F_12 ( V_16 ) ;
if ( V_19 )
V_3 = F_14 ( V_11 , V_17 ) ;
else
V_3 = F_15 ( V_11 , V_17 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_16 ( struct V_21 * V_22 ,
unsigned long * V_23 )
{
struct V_6 * V_7 = V_22 -> V_24 ;
* V_23 = V_7 -> V_14 - 1 ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 ,
unsigned long * V_23 )
{
struct V_6 * V_7 = V_22 -> V_24 ;
* V_23 = V_7 -> V_25 ;
return 0 ;
}
static int F_18 ( struct V_21 * V_22 ,
unsigned long V_23 )
{
struct V_6 * V_7 = V_22 -> V_24 ;
struct V_12 * V_26 = V_7 -> V_12 ;
struct V_10 * V_11 = V_26 -> V_11 . V_13 ;
int V_3 ;
if ( V_23 == V_7 -> V_25 )
return 0 ;
F_19 ( V_11 , L_1 , V_23 ) ;
if ( V_23 >= V_7 -> V_14 )
return - V_27 ;
V_3 = F_8 ( V_7 , V_23 ) ;
if ( V_3 )
return V_3 ;
V_7 -> V_25 = V_23 ;
return 0 ;
}
static unsigned long
F_20 ( struct V_6 * V_7 , unsigned long V_17 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_14 ; V_9 ++ ) {
if ( V_7 -> V_18 [ V_9 ] == V_17 )
return V_9 ;
}
return V_28 ;
}
static unsigned long
F_21 ( struct V_6 * V_7 , unsigned long V_17 )
{
struct V_12 * V_26 = V_7 -> V_12 ;
struct V_10 * V_11 = V_26 -> V_11 . V_13 ;
unsigned long V_29 ;
struct V_15 * V_16 ;
if ( ! V_7 -> V_30 -> F_21 )
return 0 ;
F_9 () ;
V_16 = F_10 ( V_11 , V_17 , true ) ;
if ( F_13 ( V_16 ) && ( F_12 ( V_16 ) == - V_20 ) )
V_16 = F_10 ( V_11 , V_17 , false ) ;
V_29 = F_22 ( V_16 ) / 1000 ;
F_11 () ;
if ( V_29 == 0 ) {
F_23 ( V_11 ,
L_2 ,
V_17 , F_13 ( V_16 ) ? F_12 ( V_16 ) : 0 ) ;
return 0 ;
}
return V_7 -> V_30 -> F_21 ( V_29 ) ;
}
static unsigned long
F_24 ( struct V_6 * V_7 , unsigned long V_17 ,
unsigned long V_29 )
{
T_1 V_31 ;
T_2 V_32 ;
struct V_33 * V_34 = V_7 -> V_30 ;
if ( V_34 -> F_24 )
return V_34 -> F_24 ( V_17 , V_29 ) ;
V_32 = V_17 / 1000000 ;
V_31 = ( T_1 ) V_34 -> V_35 * V_32 * V_29 * V_29 ;
F_25 ( V_31 , 1000000000 ) ;
return V_31 ;
}
static int F_26 ( struct V_21 * V_22 ,
struct V_36 * V_37 ,
T_2 * V_31 )
{
struct V_6 * V_7 = V_22 -> V_24 ;
struct V_12 * V_26 = V_7 -> V_12 ;
struct V_38 * V_39 = & V_26 -> V_40 ;
unsigned long V_23 ;
unsigned long V_17 = V_39 -> V_41 ;
T_2 V_42 , V_43 ;
V_23 = F_20 ( V_7 , V_17 ) ;
if ( V_23 == V_28 )
return - V_44 ;
V_42 = V_7 -> V_45 [ V_23 ] ;
V_42 = ( V_42 * V_39 -> V_46 ) / V_39 -> V_47 ;
V_43 = F_21 ( V_7 , V_17 ) ;
F_27 ( V_22 , V_39 , V_17 , V_42 ,
V_43 ) ;
* V_31 = V_42 + V_43 ;
return 0 ;
}
static int F_28 ( struct V_21 * V_22 ,
struct V_36 * V_37 ,
unsigned long V_23 ,
T_2 * V_31 )
{
struct V_6 * V_7 = V_22 -> V_24 ;
unsigned long V_17 ;
T_2 V_43 ;
if ( V_23 < 0 || V_23 >= V_7 -> V_14 )
return - V_27 ;
V_17 = V_7 -> V_18 [ V_23 ] ;
V_43 = F_21 ( V_7 , V_17 ) ;
* V_31 = V_7 -> V_45 [ V_23 ] + V_43 ;
return 0 ;
}
static int F_29 ( struct V_21 * V_22 ,
struct V_36 * V_37 ,
T_2 V_31 , unsigned long * V_23 )
{
struct V_6 * V_7 = V_22 -> V_24 ;
struct V_12 * V_26 = V_7 -> V_12 ;
struct V_38 * V_39 = & V_26 -> V_40 ;
unsigned long V_17 = V_39 -> V_41 ;
unsigned long V_46 ;
T_3 V_42 ;
T_2 V_43 ;
int V_9 ;
V_43 = F_21 ( V_7 , V_17 ) ;
V_42 = V_31 - V_43 ;
V_42 = V_42 > 0 ? V_42 : 0 ;
V_46 = V_39 -> V_46 ? : 1 ;
V_42 = ( V_42 * V_39 -> V_47 ) / V_46 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_14 - 1 ; V_9 ++ )
if ( V_42 >= V_7 -> V_45 [ V_9 ] )
break;
* V_23 = V_9 ;
F_30 ( V_22 , V_17 , * V_23 , V_31 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_12 * V_26 = V_7 -> V_12 ;
struct V_10 * V_11 = V_26 -> V_11 . V_13 ;
int V_3 , V_48 ;
unsigned long V_17 ;
T_2 * V_45 = NULL ;
T_2 * V_18 ;
int V_9 ;
V_48 = F_32 ( V_11 ) ;
if ( V_7 -> V_30 ) {
V_45 = F_33 ( V_48 , sizeof( * V_45 ) ,
V_5 ) ;
if ( ! V_45 )
return - V_49 ;
}
V_18 = F_33 ( V_48 , sizeof( * V_18 ) ,
V_5 ) ;
if ( ! V_18 ) {
V_3 = - V_49 ;
goto V_50;
}
for ( V_9 = 0 , V_17 = V_51 ; V_9 < V_48 ; V_9 ++ , V_17 -- ) {
unsigned long V_52 , V_29 ;
struct V_15 * V_16 ;
F_9 () ;
V_16 = F_34 ( V_11 , & V_17 ) ;
if ( F_13 ( V_16 ) ) {
F_11 () ;
V_3 = F_12 ( V_16 ) ;
goto V_53;
}
V_29 = F_22 ( V_16 ) / 1000 ;
F_11 () ;
if ( V_7 -> V_30 ) {
V_52 = F_24 ( V_7 , V_17 , V_29 ) ;
F_19 ( V_11 , L_3 ,
V_17 / 1000000 , V_29 , V_52 , V_52 ) ;
V_45 [ V_9 ] = V_52 ;
}
V_18 [ V_9 ] = V_17 ;
}
if ( V_7 -> V_30 )
V_7 -> V_45 = V_45 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_14 = V_48 ;
return 0 ;
V_53:
F_35 ( V_18 ) ;
V_50:
F_35 ( V_45 ) ;
return V_3 ;
}
struct V_21 *
F_36 ( struct V_54 * V_55 , struct V_12 * V_26 ,
struct V_33 * V_34 )
{
struct V_21 * V_22 ;
struct V_6 * V_7 ;
char V_56 [ V_57 ] ;
int V_58 ;
V_7 = F_37 ( sizeof( * V_7 ) , V_5 ) ;
if ( ! V_7 )
return F_38 ( - V_49 ) ;
V_7 -> V_12 = V_26 ;
if ( V_34 ) {
V_7 -> V_30 = V_34 ;
V_59 . V_60 =
F_26 ;
V_59 . V_61 = F_28 ;
V_59 . V_62 = F_29 ;
}
V_58 = F_31 ( V_7 ) ;
if ( V_58 )
goto V_63;
V_58 = F_1 ( & V_64 , & V_7 -> V_2 ) ;
if ( V_58 )
goto V_53;
snprintf ( V_56 , sizeof( V_56 ) , L_4 , V_7 -> V_2 ) ;
V_22 = F_39 ( V_55 , V_56 , V_7 ,
& V_59 ) ;
if ( F_13 ( V_22 ) ) {
V_58 = F_12 ( V_22 ) ;
F_40 ( V_26 -> V_11 . V_13 ,
L_5 ,
V_58 ) ;
goto F_6;
}
V_7 -> V_22 = V_22 ;
return V_22 ;
F_6:
F_6 ( & V_64 , V_7 -> V_2 ) ;
V_53:
F_35 ( V_7 -> V_45 ) ;
F_35 ( V_7 -> V_18 ) ;
V_63:
F_35 ( V_7 ) ;
return F_38 ( V_58 ) ;
}
struct V_21 *
F_41 ( struct V_54 * V_55 , struct V_12 * V_26 )
{
return F_36 ( V_55 , V_26 , NULL ) ;
}
struct V_21 * F_42 ( struct V_12 * V_26 )
{
return F_41 ( NULL , V_26 ) ;
}
void F_43 ( struct V_21 * V_22 )
{
struct V_6 * V_7 ;
if ( ! V_22 )
return;
V_7 = V_22 -> V_24 ;
F_44 ( V_7 -> V_22 ) ;
F_6 ( & V_64 , V_7 -> V_2 ) ;
F_35 ( V_7 -> V_45 ) ;
F_35 ( V_7 -> V_18 ) ;
F_35 ( V_7 ) ;
}
