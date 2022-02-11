static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_6 )
{
int V_7 ;
struct V_1 * V_8 = V_3 -> V_9 ;
char * V_10 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_11 -> V_12 && V_8 -> V_10 ; V_7 ++ , V_8 ++ )
;
if ( V_7 >= V_3 -> V_11 -> V_12 )
return NULL ;
V_10 = F_2 ( V_13 , L_1 , V_8 -> V_14 ,
V_5 ? F_3 ( V_5 ) : NULL ) ;
if ( ! V_10 )
return NULL ;
V_8 -> V_5 = V_5 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_6 = V_6 ;
return V_8 ;
}
T_1 F_4 ( struct V_1 * V_8 )
{
return V_8 -> V_14 ;
}
T_1 F_5 ( struct V_1 * V_8 , T_1 V_15 )
{
return ( T_1 ) F_6 ( V_15 , & V_8 -> V_16 ) ;
}
void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = V_3 -> V_9 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < F_8 ( V_3 ) ; V_7 ++ )
F_9 ( V_3 , V_17 + V_7 ) ;
for ( V_7 = 0 ; V_7 < F_10 ( V_3 ) ; V_7 ++ )
F_11 ( V_3 , V_17 + V_7 ) ;
F_12 () ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = V_3 -> V_9 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < F_8 ( V_3 ) ; V_7 ++ ) {
if ( F_14 ( V_17 + V_7 ) )
F_15 ( V_3 , V_17 + V_7 ) ;
else
F_16 ( ! F_17 ( V_17 + V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_10 ( V_3 ) ; V_7 ++ )
F_18 ( V_3 , V_17 + V_7 ) ;
}
T_1 F_19 ( struct V_1 * V_8 )
{
T_1 V_18 ;
V_18 = F_15 ( V_8 -> V_3 , V_8 ) ;
F_20 ( V_8 -> V_14 , V_18 ) ;
return V_18 ;
}
T_1 F_21 ( struct V_1 * V_8 )
{
T_1 V_18 ;
F_18 ( V_8 -> V_3 , V_8 ) ;
V_18 = V_8 -> V_19 ;
return V_18 ;
}
int F_22 ( struct V_1 * V_8 )
{
return F_23 ( V_8 -> V_3 , V_8 ) ;
}
static bool F_24 ( struct V_1 * V_8 , T_1 V_20 )
{
F_15 ( V_8 -> V_3 , V_8 ) ;
return F_25 ( V_8 , V_20 ) ;
}
int F_26 ( struct V_1 * V_8 , T_1 V_20 , long V_21 ,
T_1 * V_22 )
{
F_27 ( V_23 ) ;
void * V_24 ;
struct V_25 * V_26 ;
int V_27 = 0 , V_28 = 0 ;
T_1 V_18 ;
if ( V_22 )
* V_22 = 0 ;
if ( F_25 ( V_8 , V_20 ) ) {
if ( V_22 )
* V_22 = F_19 ( V_8 ) ;
return 0 ;
}
V_18 = F_15 ( V_8 -> V_3 , V_8 ) ;
if ( F_25 ( V_8 , V_20 ) ) {
if ( V_22 )
* V_22 = V_18 ;
goto V_29;
}
if ( ! V_21 ) {
V_27 = - V_30 ;
goto V_29;
}
V_26 = F_28 ( sizeof( * V_26 ) , V_13 ) ;
if ( ! V_26 ) {
V_27 = - V_31 ;
goto V_29;
}
V_27 = F_29 ( V_8 -> V_3 , V_8 -> V_14 , V_20 ,
V_32 ,
& V_23 , V_26 , & V_24 ) ;
if ( V_27 )
goto V_29;
V_27 = - V_30 ;
if ( V_21 < 0 )
V_21 = V_33 ;
while ( V_21 ) {
long V_34 = F_30 ( long , V_35 , V_21 ) ;
int V_36 = F_31 ( V_23 ,
F_24 ( V_8 , V_20 ) ,
V_34 ) ;
if ( V_36 > 0 || F_25 ( V_8 , V_20 ) ) {
if ( V_22 )
* V_22 = F_19 ( V_8 ) ;
V_27 = 0 ;
break;
}
if ( V_36 < 0 ) {
V_27 = V_36 ;
break;
}
V_21 -= V_34 ;
if ( V_21 && V_28 <= V_37 ) {
F_32 ( V_8 -> V_3 -> V_5 ,
L_2 ,
V_38 -> V_39 , V_8 -> V_14 , V_8 -> V_10 ,
V_20 , V_21 ) ;
F_33 ( V_8 -> V_3 ) ;
if ( V_28 == V_37 )
F_34 ( V_8 -> V_3 ) ;
V_28 ++ ;
}
}
F_35 ( V_8 -> V_3 , V_8 -> V_14 , V_24 ) ;
V_29:
return V_27 ;
}
bool F_25 ( struct V_1 * V_8 , T_1 V_20 )
{
T_1 V_40 ;
T_1 V_41 ;
F_36 () ;
V_40 = ( T_1 ) F_37 ( & V_8 -> V_42 ) ;
V_41 = ( T_1 ) F_37 ( & V_8 -> V_16 ) ;
if ( ! F_14 ( V_8 ) )
return V_41 - V_20 >= V_40 - V_20 ;
else
return ( V_43 ) ( V_40 - V_20 ) >= 0 ;
}
int F_38 ( struct V_1 * V_8 , void * V_44 )
{
return F_39 ( V_8 -> V_3 , V_8 , V_44 ) ;
}
int F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
int V_7 ;
V_9 = F_41 ( V_3 -> V_5 , sizeof( * V_9 ) * V_3 -> V_11 -> V_12 ,
V_13 ) ;
if ( ! V_9 )
return - V_31 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_11 -> V_12 ; ++ V_7 ) {
V_9 [ V_7 ] . V_14 = V_7 ;
V_9 [ V_7 ] . V_3 = V_3 ;
}
V_3 -> V_9 = V_9 ;
F_7 ( V_3 ) ;
V_3 -> V_45 = F_1 ( V_3 , NULL , false ) ;
if ( ! V_3 -> V_45 )
return - V_31 ;
return 0 ;
}
struct V_1 * F_42 ( struct V_4 * V_5 ,
bool V_6 )
{
struct V_2 * V_3 = F_43 ( V_5 -> V_46 ) ;
return F_1 ( V_3 , V_5 , V_6 ) ;
}
void F_44 ( struct V_1 * V_8 )
{
if ( ! V_8 )
return;
F_45 ( V_8 -> V_10 ) ;
V_8 -> V_5 = NULL ;
V_8 -> V_10 = NULL ;
V_8 -> V_6 = false ;
}
void F_46 ( struct V_2 * V_3 )
{
int V_7 ;
struct V_1 * V_8 = V_3 -> V_9 ;
for ( V_7 = 0 ; V_7 < V_3 -> V_11 -> V_12 ; V_7 ++ , V_8 ++ )
F_45 ( V_8 -> V_10 ) ;
}
int F_8 ( struct V_2 * V_3 )
{
return V_3 -> V_11 -> V_12 ;
}
int F_10 ( struct V_2 * V_3 )
{
return V_3 -> V_11 -> V_47 ;
}
int F_47 ( struct V_2 * V_3 )
{
return V_3 -> V_11 -> V_48 ;
}
struct V_1 * F_48 ( struct V_2 * V_3 , T_1 V_14 )
{
if ( V_3 -> V_11 -> V_12 < V_14 )
return NULL ;
return V_3 -> V_9 + V_14 ;
}
