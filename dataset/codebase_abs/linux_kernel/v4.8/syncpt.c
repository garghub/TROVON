static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_7 ; V_5 ++ )
if ( ! V_4 [ V_5 ] . V_8 )
break;
if ( V_5 >= V_3 -> V_6 -> V_7 )
return NULL ;
V_4 [ V_5 ] . V_8 = true ;
return & V_4 [ V_5 ] ;
}
static void F_2 ( struct V_1 * V_9 )
{
if ( V_9 )
V_9 -> V_8 = false ;
}
static struct V_10 * F_3 ( struct V_2 * V_3 ,
struct V_11 * V_12 ,
unsigned long V_13 )
{
int V_5 ;
struct V_10 * V_14 = V_3 -> V_15 ;
char * V_16 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_17 && V_14 -> V_16 ; V_5 ++ , V_14 ++ )
;
if ( V_5 >= V_3 -> V_6 -> V_17 )
return NULL ;
if ( V_13 & V_18 ) {
V_14 -> V_9 = F_1 ( V_3 ) ;
if ( ! V_14 -> V_9 )
return NULL ;
}
V_16 = F_4 ( V_19 , L_1 , V_14 -> V_20 ,
V_12 ? F_5 ( V_12 ) : NULL ) ;
if ( ! V_16 )
return NULL ;
V_14 -> V_12 = V_12 ;
V_14 -> V_16 = V_16 ;
if ( V_13 & V_21 )
V_14 -> V_22 = true ;
else
V_14 -> V_22 = false ;
return V_14 ;
}
T_1 F_6 ( struct V_10 * V_14 )
{
return V_14 -> V_20 ;
}
T_1 F_7 ( struct V_10 * V_14 , T_1 V_23 )
{
return ( T_1 ) F_8 ( V_23 , & V_14 -> V_24 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_10 * V_25 = V_3 -> V_15 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_10 ( V_3 ) ; V_5 ++ )
F_11 ( V_3 , V_25 + V_5 ) ;
for ( V_5 = 0 ; V_5 < F_12 ( V_3 ) ; V_5 ++ )
F_13 ( V_3 , V_25 + V_5 ) ;
F_14 () ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_10 * V_25 = V_3 -> V_15 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_10 ( V_3 ) ; V_5 ++ ) {
if ( F_16 ( V_25 + V_5 ) )
F_17 ( V_3 , V_25 + V_5 ) ;
else
F_18 ( ! F_19 ( V_25 + V_5 ) ) ;
}
for ( V_5 = 0 ; V_5 < F_12 ( V_3 ) ; V_5 ++ )
F_20 ( V_3 , V_25 + V_5 ) ;
}
T_1 F_21 ( struct V_10 * V_14 )
{
T_1 V_26 ;
V_26 = F_17 ( V_14 -> V_3 , V_14 ) ;
F_22 ( V_14 -> V_20 , V_26 ) ;
return V_26 ;
}
T_1 F_23 ( struct V_10 * V_14 )
{
F_20 ( V_14 -> V_3 , V_14 ) ;
return V_14 -> V_27 ;
}
int F_24 ( struct V_10 * V_14 )
{
return F_25 ( V_14 -> V_3 , V_14 ) ;
}
static bool F_26 ( struct V_10 * V_14 , T_1 V_28 )
{
F_17 ( V_14 -> V_3 , V_14 ) ;
return F_27 ( V_14 , V_28 ) ;
}
int F_28 ( struct V_10 * V_14 , T_1 V_28 , long V_29 ,
T_1 * V_30 )
{
F_29 ( V_31 ) ;
void * V_32 ;
struct V_33 * V_34 ;
int V_35 = 0 , V_36 = 0 ;
T_1 V_26 ;
if ( V_30 )
* V_30 = 0 ;
if ( F_27 ( V_14 , V_28 ) ) {
if ( V_30 )
* V_30 = F_21 ( V_14 ) ;
return 0 ;
}
V_26 = F_17 ( V_14 -> V_3 , V_14 ) ;
if ( F_27 ( V_14 , V_28 ) ) {
if ( V_30 )
* V_30 = V_26 ;
goto V_37;
}
if ( ! V_29 ) {
V_35 = - V_38 ;
goto V_37;
}
V_34 = F_30 ( sizeof( * V_34 ) , V_19 ) ;
if ( ! V_34 ) {
V_35 = - V_39 ;
goto V_37;
}
V_35 = F_31 ( V_14 -> V_3 , V_14 -> V_20 , V_28 ,
V_40 ,
& V_31 , V_34 , & V_32 ) ;
if ( V_35 )
goto V_37;
V_35 = - V_38 ;
if ( V_29 < 0 )
V_29 = V_41 ;
while ( V_29 ) {
long V_42 = F_32 ( long , V_43 , V_29 ) ;
int V_44 ;
V_44 = F_33 ( V_31 ,
F_26 ( V_14 , V_28 ) ,
V_42 ) ;
if ( V_44 > 0 || F_27 ( V_14 , V_28 ) ) {
if ( V_30 )
* V_30 = F_21 ( V_14 ) ;
V_35 = 0 ;
break;
}
if ( V_44 < 0 ) {
V_35 = V_44 ;
break;
}
V_29 -= V_42 ;
if ( V_29 && V_36 <= V_45 ) {
F_34 ( V_14 -> V_3 -> V_12 ,
L_2 ,
V_46 -> V_47 , V_14 -> V_20 , V_14 -> V_16 ,
V_28 , V_29 ) ;
F_35 ( V_14 -> V_3 ) ;
if ( V_36 == V_45 )
F_36 ( V_14 -> V_3 ) ;
V_36 ++ ;
}
}
F_37 ( V_14 -> V_3 , V_14 -> V_20 , V_32 ) ;
V_37:
return V_35 ;
}
bool F_27 ( struct V_10 * V_14 , T_1 V_28 )
{
T_1 V_48 ;
T_1 V_49 ;
F_38 () ;
V_48 = ( T_1 ) F_39 ( & V_14 -> V_50 ) ;
V_49 = ( T_1 ) F_39 ( & V_14 -> V_24 ) ;
if ( ! F_16 ( V_14 ) )
return V_49 - V_28 >= V_48 - V_28 ;
else
return ( V_51 ) ( V_48 - V_28 ) >= 0 ;
}
int F_40 ( struct V_10 * V_14 , void * V_52 )
{
return F_41 ( V_14 -> V_3 , V_14 , V_52 ) ;
}
int F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_10 * V_15 ;
unsigned int V_5 ;
V_15 = F_43 ( V_3 -> V_12 , V_3 -> V_6 -> V_17 , sizeof( * V_15 ) ,
V_19 ) ;
if ( ! V_15 )
return - V_39 ;
V_4 = F_43 ( V_3 -> V_12 , V_3 -> V_6 -> V_7 , sizeof( * V_4 ) ,
V_19 ) ;
if ( ! V_4 )
return - V_39 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_17 ; V_5 ++ ) {
V_15 [ V_5 ] . V_20 = V_5 ;
V_15 [ V_5 ] . V_3 = V_3 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_7 ; V_5 ++ )
V_4 [ V_5 ] . V_20 = V_5 ;
V_3 -> V_15 = V_15 ;
V_3 -> V_4 = V_4 ;
F_9 ( V_3 ) ;
V_3 -> V_53 = F_3 ( V_3 , NULL , 0 ) ;
if ( ! V_3 -> V_53 )
return - V_39 ;
return 0 ;
}
struct V_10 * F_44 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_2 * V_3 = F_45 ( V_12 -> V_54 ) ;
return F_3 ( V_3 , V_12 , V_13 ) ;
}
void F_46 ( struct V_10 * V_14 )
{
if ( ! V_14 )
return;
F_2 ( V_14 -> V_9 ) ;
F_47 ( V_14 -> V_16 ) ;
V_14 -> V_9 = NULL ;
V_14 -> V_12 = NULL ;
V_14 -> V_16 = NULL ;
V_14 -> V_22 = false ;
}
void F_48 ( struct V_2 * V_3 )
{
struct V_10 * V_14 = V_3 -> V_15 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_17 ; V_5 ++ , V_14 ++ )
F_47 ( V_14 -> V_16 ) ;
}
T_1 F_49 ( struct V_10 * V_14 )
{
F_38 () ;
return ( T_1 ) F_39 ( & V_14 -> V_24 ) ;
}
T_1 F_50 ( struct V_10 * V_14 )
{
F_38 () ;
return ( T_1 ) F_39 ( & V_14 -> V_50 ) ;
}
T_1 F_51 ( struct V_10 * V_14 )
{
return F_21 ( V_14 ) ;
}
unsigned int F_10 ( struct V_2 * V_3 )
{
return V_3 -> V_6 -> V_17 ;
}
unsigned int F_12 ( struct V_2 * V_3 )
{
return V_3 -> V_6 -> V_7 ;
}
unsigned int F_52 ( struct V_2 * V_3 )
{
return V_3 -> V_6 -> V_55 ;
}
struct V_10 * F_53 ( struct V_2 * V_3 , unsigned int V_20 )
{
if ( V_3 -> V_6 -> V_17 < V_20 )
return NULL ;
return V_3 -> V_15 + V_20 ;
}
struct V_1 * F_54 ( struct V_10 * V_14 )
{
return V_14 ? V_14 -> V_9 : NULL ;
}
T_1 F_55 ( struct V_1 * V_9 )
{
return V_9 -> V_20 ;
}
