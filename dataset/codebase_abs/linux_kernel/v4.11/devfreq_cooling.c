static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 . V_8 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
struct V_10 * V_11 ;
int V_12 = 0 ;
unsigned int V_13 = V_2 -> V_14 [ V_4 ] ;
bool V_15 = V_4 >= V_3 ? true : false ;
V_11 = F_2 ( V_6 , V_13 , ! V_15 ) ;
if ( F_3 ( V_11 ) == - V_16 )
continue;
else if ( F_4 ( V_11 ) )
return F_3 ( V_11 ) ;
F_5 ( V_11 ) ;
if ( V_15 )
V_12 = F_6 ( V_6 , V_13 ) ;
else
V_12 = F_7 ( V_6 , V_13 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_8 ( struct V_17 * V_18 ,
unsigned long * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
* V_19 = V_2 -> V_9 - 1 ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
unsigned long * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
* V_19 = V_2 -> V_21 ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 ,
unsigned long V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_5 * V_6 = V_22 -> V_6 . V_8 ;
int V_12 ;
if ( V_19 == V_2 -> V_21 )
return 0 ;
F_11 ( V_6 , L_1 , V_19 ) ;
if ( V_19 >= V_2 -> V_9 )
return - V_23 ;
V_12 = F_1 ( V_2 , V_19 ) ;
if ( V_12 )
return V_12 ;
V_2 -> V_21 = V_19 ;
return 0 ;
}
static unsigned long
F_12 ( struct V_1 * V_2 , unsigned long V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
if ( V_2 -> V_14 [ V_4 ] == V_13 )
return V_4 ;
}
return V_24 ;
}
static unsigned long
F_13 ( struct V_1 * V_2 , unsigned long V_13 )
{
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_5 * V_6 = V_22 -> V_6 . V_8 ;
unsigned long V_25 ;
struct V_10 * V_11 ;
if ( ! V_2 -> V_26 -> F_13 )
return 0 ;
V_11 = F_2 ( V_6 , V_13 , true ) ;
if ( F_3 ( V_11 ) == - V_16 )
V_11 = F_2 ( V_6 , V_13 , false ) ;
if ( F_4 ( V_11 ) ) {
F_14 ( V_6 , L_2 ,
V_13 , F_3 ( V_11 ) ) ;
return 0 ;
}
V_25 = F_15 ( V_11 ) / 1000 ;
F_5 ( V_11 ) ;
if ( V_25 == 0 ) {
F_14 ( V_6 ,
L_3 ,
V_13 ) ;
return 0 ;
}
return V_2 -> V_26 -> F_13 ( V_22 , V_25 ) ;
}
static unsigned long
F_16 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_25 )
{
T_1 V_27 ;
T_2 V_28 ;
struct V_29 * V_30 = V_2 -> V_26 ;
if ( V_30 -> F_16 )
return V_30 -> F_16 ( V_2 -> V_7 , V_13 ,
V_25 ) ;
V_28 = V_13 / 1000000 ;
V_27 = ( T_1 ) V_30 -> V_31 * V_28 * V_25 * V_25 ;
F_17 ( V_27 , 1000000000 ) ;
return V_27 ;
}
static int F_18 ( struct V_17 * V_18 ,
struct V_32 * V_33 ,
T_2 * V_27 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_34 * V_35 = & V_22 -> V_36 ;
unsigned long V_19 ;
unsigned long V_13 = V_35 -> V_37 ;
T_2 V_38 , V_39 ;
V_19 = F_12 ( V_2 , V_13 ) ;
if ( V_19 == V_24 )
return - V_40 ;
V_38 = V_2 -> V_41 [ V_19 ] ;
V_38 = ( V_38 * V_35 -> V_42 ) / V_35 -> V_43 ;
V_39 = F_13 ( V_2 , V_13 ) ;
F_19 ( V_18 , V_35 , V_13 , V_38 ,
V_39 ) ;
* V_27 = V_38 + V_39 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 ,
struct V_32 * V_33 ,
unsigned long V_19 ,
T_2 * V_27 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
unsigned long V_13 ;
T_2 V_39 ;
if ( V_19 >= V_2 -> V_9 )
return - V_23 ;
V_13 = V_2 -> V_14 [ V_19 ] ;
V_39 = F_13 ( V_2 , V_13 ) ;
* V_27 = V_2 -> V_41 [ V_19 ] + V_39 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 ,
struct V_32 * V_33 ,
T_2 V_27 , unsigned long * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_34 * V_35 = & V_22 -> V_36 ;
unsigned long V_13 = V_35 -> V_37 ;
unsigned long V_42 ;
T_3 V_38 ;
T_2 V_39 ;
int V_4 ;
V_39 = F_13 ( V_2 , V_13 ) ;
V_38 = V_27 - V_39 ;
V_38 = V_38 > 0 ? V_38 : 0 ;
V_42 = V_35 -> V_42 ? : 1 ;
V_38 = ( V_38 * V_35 -> V_43 ) / V_42 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 - 1 ; V_4 ++ )
if ( V_38 >= V_2 -> V_41 [ V_4 ] )
break;
* V_19 = V_4 ;
F_22 ( V_18 , V_13 , * V_19 , V_27 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_22 = V_2 -> V_7 ;
struct V_5 * V_6 = V_22 -> V_6 . V_8 ;
int V_12 , V_44 ;
unsigned long V_13 ;
T_2 * V_41 = NULL ;
T_2 * V_14 ;
int V_4 ;
V_44 = F_24 ( V_6 ) ;
if ( V_2 -> V_26 ) {
V_41 = F_25 ( V_44 , sizeof( * V_41 ) ,
V_45 ) ;
if ( ! V_41 )
return - V_46 ;
}
V_14 = F_25 ( V_44 , sizeof( * V_14 ) ,
V_45 ) ;
if ( ! V_14 ) {
V_12 = - V_46 ;
goto V_47;
}
for ( V_4 = 0 , V_13 = V_48 ; V_4 < V_44 ; V_4 ++ , V_13 -- ) {
unsigned long V_49 , V_25 ;
struct V_10 * V_11 ;
V_11 = F_26 ( V_6 , & V_13 ) ;
if ( F_4 ( V_11 ) ) {
V_12 = F_3 ( V_11 ) ;
goto V_50;
}
V_25 = F_15 ( V_11 ) / 1000 ;
F_5 ( V_11 ) ;
if ( V_2 -> V_26 ) {
V_49 = F_16 ( V_2 , V_13 , V_25 ) ;
F_11 ( V_6 , L_4 ,
V_13 / 1000000 , V_25 , V_49 , V_49 ) ;
V_41 [ V_4 ] = V_49 ;
}
V_14 [ V_4 ] = V_13 ;
}
if ( V_2 -> V_26 )
V_2 -> V_41 = V_41 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_9 = V_44 ;
return 0 ;
V_50:
F_27 ( V_14 ) ;
V_47:
F_27 ( V_41 ) ;
return V_12 ;
}
struct V_17 *
F_28 ( struct V_51 * V_52 , struct V_7 * V_22 ,
struct V_29 * V_30 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
char V_53 [ V_54 ] ;
int V_55 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return F_30 ( - V_46 ) ;
V_2 -> V_7 = V_22 ;
if ( V_30 ) {
V_2 -> V_26 = V_30 ;
V_56 . V_57 =
F_18 ;
V_56 . V_58 = F_20 ;
V_56 . V_59 = F_21 ;
}
V_55 = F_23 ( V_2 ) ;
if ( V_55 )
goto V_60;
V_55 = F_31 ( & V_61 , 0 , 0 , V_45 ) ;
if ( V_55 < 0 )
goto V_50;
V_2 -> V_62 = V_55 ;
snprintf ( V_53 , sizeof( V_53 ) , L_5 , V_2 -> V_62 ) ;
V_18 = F_32 ( V_52 , V_53 , V_2 ,
& V_56 ) ;
if ( F_4 ( V_18 ) ) {
V_55 = F_3 ( V_18 ) ;
F_33 ( V_22 -> V_6 . V_8 ,
L_6 ,
V_55 ) ;
goto V_63;
}
V_2 -> V_18 = V_18 ;
return V_18 ;
V_63:
F_34 ( & V_61 , V_2 -> V_62 ) ;
V_50:
F_27 ( V_2 -> V_41 ) ;
F_27 ( V_2 -> V_14 ) ;
V_60:
F_27 ( V_2 ) ;
return F_30 ( V_55 ) ;
}
struct V_17 *
F_35 ( struct V_51 * V_52 , struct V_7 * V_22 )
{
return F_28 ( V_52 , V_22 , NULL ) ;
}
struct V_17 * F_36 ( struct V_7 * V_22 )
{
return F_35 ( NULL , V_22 ) ;
}
void F_37 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
if ( ! V_18 )
return;
V_2 = V_18 -> V_20 ;
F_38 ( V_2 -> V_18 ) ;
F_34 ( & V_61 , V_2 -> V_62 ) ;
F_27 ( V_2 -> V_41 ) ;
F_27 ( V_2 -> V_14 ) ;
F_27 ( V_2 ) ;
}
