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
F_4 ( & V_3 -> V_17 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_18 && V_14 -> V_16 ; V_5 ++ , V_14 ++ )
;
if ( V_5 >= V_3 -> V_6 -> V_18 )
goto V_19;
if ( V_13 & V_20 ) {
V_14 -> V_9 = F_1 ( V_3 ) ;
if ( ! V_14 -> V_9 )
goto V_19;
}
V_16 = F_5 ( V_21 , L_1 , V_14 -> V_22 ,
V_12 ? F_6 ( V_12 ) : NULL ) ;
if ( ! V_16 )
goto V_23;
V_14 -> V_12 = V_12 ;
V_14 -> V_16 = V_16 ;
if ( V_13 & V_24 )
V_14 -> V_25 = true ;
else
V_14 -> V_25 = false ;
F_7 ( & V_3 -> V_17 ) ;
return V_14 ;
V_23:
F_2 ( V_14 -> V_9 ) ;
V_14 -> V_9 = NULL ;
V_19:
F_7 ( & V_3 -> V_17 ) ;
return NULL ;
}
T_1 F_8 ( struct V_10 * V_14 )
{
return V_14 -> V_22 ;
}
T_1 F_9 ( struct V_10 * V_14 , T_1 V_26 )
{
return ( T_1 ) F_10 ( V_26 , & V_14 -> V_27 ) ;
}
void F_11 ( struct V_2 * V_3 )
{
struct V_10 * V_28 = V_3 -> V_15 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_12 ( V_3 ) ; V_5 ++ )
F_13 ( V_3 , V_28 + V_5 ) ;
for ( V_5 = 0 ; V_5 < F_14 ( V_3 ) ; V_5 ++ )
F_15 ( V_3 , V_28 + V_5 ) ;
F_16 () ;
}
void F_17 ( struct V_2 * V_3 )
{
struct V_10 * V_28 = V_3 -> V_15 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < F_12 ( V_3 ) ; V_5 ++ ) {
if ( F_18 ( V_28 + V_5 ) )
F_19 ( V_3 , V_28 + V_5 ) ;
else
F_20 ( ! F_21 ( V_28 + V_5 ) ) ;
}
for ( V_5 = 0 ; V_5 < F_14 ( V_3 ) ; V_5 ++ )
F_22 ( V_3 , V_28 + V_5 ) ;
}
T_1 F_23 ( struct V_10 * V_14 )
{
T_1 V_29 ;
V_29 = F_19 ( V_14 -> V_3 , V_14 ) ;
F_24 ( V_14 -> V_22 , V_29 ) ;
return V_29 ;
}
T_1 F_25 ( struct V_10 * V_14 )
{
F_22 ( V_14 -> V_3 , V_14 ) ;
return V_14 -> V_30 ;
}
int F_26 ( struct V_10 * V_14 )
{
return F_27 ( V_14 -> V_3 , V_14 ) ;
}
static bool F_28 ( struct V_10 * V_14 , T_1 V_31 )
{
F_19 ( V_14 -> V_3 , V_14 ) ;
return F_29 ( V_14 , V_31 ) ;
}
int F_30 ( struct V_10 * V_14 , T_1 V_31 , long V_32 ,
T_1 * V_33 )
{
F_31 ( V_34 ) ;
void * V_35 ;
struct V_36 * V_37 ;
int V_38 = 0 , V_39 = 0 ;
T_1 V_29 ;
if ( V_33 )
* V_33 = 0 ;
if ( F_29 ( V_14 , V_31 ) ) {
if ( V_33 )
* V_33 = F_23 ( V_14 ) ;
return 0 ;
}
V_29 = F_19 ( V_14 -> V_3 , V_14 ) ;
if ( F_29 ( V_14 , V_31 ) ) {
if ( V_33 )
* V_33 = V_29 ;
goto V_40;
}
if ( ! V_32 ) {
V_38 = - V_41 ;
goto V_40;
}
V_37 = F_32 ( sizeof( * V_37 ) , V_21 ) ;
if ( ! V_37 ) {
V_38 = - V_42 ;
goto V_40;
}
V_38 = F_33 ( V_14 -> V_3 , V_14 -> V_22 , V_31 ,
V_43 ,
& V_34 , V_37 , & V_35 ) ;
if ( V_38 )
goto V_40;
V_38 = - V_41 ;
if ( V_32 < 0 )
V_32 = V_44 ;
while ( V_32 ) {
long V_45 = F_34 ( long , V_46 , V_32 ) ;
int V_47 ;
V_47 = F_35 ( V_34 ,
F_28 ( V_14 , V_31 ) ,
V_45 ) ;
if ( V_47 > 0 || F_29 ( V_14 , V_31 ) ) {
if ( V_33 )
* V_33 = F_23 ( V_14 ) ;
V_38 = 0 ;
break;
}
if ( V_47 < 0 ) {
V_38 = V_47 ;
break;
}
V_32 -= V_45 ;
if ( V_32 && V_39 <= V_48 ) {
F_36 ( V_14 -> V_3 -> V_12 ,
L_2 ,
V_49 -> V_50 , V_14 -> V_22 , V_14 -> V_16 ,
V_31 , V_32 ) ;
F_37 ( V_14 -> V_3 ) ;
if ( V_39 == V_48 )
F_38 ( V_14 -> V_3 ) ;
V_39 ++ ;
}
}
F_39 ( V_14 -> V_3 , V_14 -> V_22 , V_35 ) ;
V_40:
return V_38 ;
}
bool F_29 ( struct V_10 * V_14 , T_1 V_31 )
{
T_1 V_51 ;
T_1 V_52 ;
F_40 () ;
V_51 = ( T_1 ) F_41 ( & V_14 -> V_53 ) ;
V_52 = ( T_1 ) F_41 ( & V_14 -> V_27 ) ;
if ( ! F_18 ( V_14 ) )
return V_52 - V_31 >= V_51 - V_31 ;
else
return ( V_54 ) ( V_51 - V_31 ) >= 0 ;
}
int F_42 ( struct V_10 * V_14 , void * V_55 )
{
return F_43 ( V_14 -> V_3 , V_14 , V_55 ) ;
}
int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_10 * V_15 ;
unsigned int V_5 ;
V_15 = F_45 ( V_3 -> V_12 , V_3 -> V_6 -> V_18 , sizeof( * V_15 ) ,
V_21 ) ;
if ( ! V_15 )
return - V_42 ;
V_4 = F_45 ( V_3 -> V_12 , V_3 -> V_6 -> V_7 , sizeof( * V_4 ) ,
V_21 ) ;
if ( ! V_4 )
return - V_42 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_18 ; V_5 ++ ) {
V_15 [ V_5 ] . V_22 = V_5 ;
V_15 [ V_5 ] . V_3 = V_3 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_7 ; V_5 ++ )
V_4 [ V_5 ] . V_22 = V_5 ;
F_46 ( & V_3 -> V_17 ) ;
V_3 -> V_15 = V_15 ;
V_3 -> V_4 = V_4 ;
F_11 ( V_3 ) ;
V_3 -> V_56 = F_3 ( V_3 , NULL , 0 ) ;
if ( ! V_3 -> V_56 )
return - V_42 ;
return 0 ;
}
struct V_10 * F_47 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_2 * V_3 = F_48 ( V_12 -> V_57 ) ;
return F_3 ( V_3 , V_12 , V_13 ) ;
}
void F_49 ( struct V_10 * V_14 )
{
if ( ! V_14 )
return;
F_4 ( & V_14 -> V_3 -> V_17 ) ;
F_2 ( V_14 -> V_9 ) ;
F_50 ( V_14 -> V_16 ) ;
V_14 -> V_9 = NULL ;
V_14 -> V_12 = NULL ;
V_14 -> V_16 = NULL ;
V_14 -> V_25 = false ;
F_7 ( & V_14 -> V_3 -> V_17 ) ;
}
void F_51 ( struct V_2 * V_3 )
{
struct V_10 * V_14 = V_3 -> V_15 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 -> V_18 ; V_5 ++ , V_14 ++ )
F_50 ( V_14 -> V_16 ) ;
}
T_1 F_52 ( struct V_10 * V_14 )
{
F_40 () ;
return ( T_1 ) F_41 ( & V_14 -> V_27 ) ;
}
T_1 F_53 ( struct V_10 * V_14 )
{
F_40 () ;
return ( T_1 ) F_41 ( & V_14 -> V_53 ) ;
}
T_1 F_54 ( struct V_10 * V_14 )
{
return F_23 ( V_14 ) ;
}
unsigned int F_12 ( struct V_2 * V_3 )
{
return V_3 -> V_6 -> V_18 ;
}
unsigned int F_14 ( struct V_2 * V_3 )
{
return V_3 -> V_6 -> V_7 ;
}
unsigned int F_55 ( struct V_2 * V_3 )
{
return V_3 -> V_6 -> V_58 ;
}
struct V_10 * F_56 ( struct V_2 * V_3 , unsigned int V_22 )
{
if ( V_22 >= V_3 -> V_6 -> V_18 )
return NULL ;
return V_3 -> V_15 + V_22 ;
}
struct V_1 * F_57 ( struct V_10 * V_14 )
{
return V_14 ? V_14 -> V_9 : NULL ;
}
T_1 F_58 ( struct V_1 * V_9 )
{
return V_9 -> V_22 ;
}
