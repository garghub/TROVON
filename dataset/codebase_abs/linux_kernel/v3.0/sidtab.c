int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = F_2 ( sizeof( * ( V_2 -> V_4 ) ) * V_5 , V_6 ) ;
if ( ! V_2 -> V_4 )
return - V_7 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
V_2 -> V_4 [ V_3 ] = NULL ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 1 ;
V_2 -> V_10 = 0 ;
F_3 ( & V_2 -> V_11 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_12 , struct V_13 * V_13 )
{
int V_14 , V_15 = 0 ;
struct V_16 * V_17 , * V_18 , * V_19 ;
if ( ! V_2 ) {
V_15 = - V_7 ;
goto V_20;
}
V_14 = F_5 ( V_12 ) ;
V_17 = NULL ;
V_18 = V_2 -> V_4 [ V_14 ] ;
while ( V_18 && V_12 > V_18 -> V_12 ) {
V_17 = V_18 ;
V_18 = V_18 -> V_21 ;
}
if ( V_18 && V_12 == V_18 -> V_12 ) {
V_15 = - V_22 ;
goto V_20;
}
V_19 = F_2 ( sizeof( * V_19 ) , V_6 ) ;
if ( V_19 == NULL ) {
V_15 = - V_7 ;
goto V_20;
}
V_19 -> V_12 = V_12 ;
if ( F_6 ( & V_19 -> V_13 , V_13 ) ) {
F_7 ( V_19 ) ;
V_15 = - V_7 ;
goto V_20;
}
if ( V_17 ) {
V_19 -> V_21 = V_17 -> V_21 ;
F_8 () ;
V_17 -> V_21 = V_19 ;
} else {
V_19 -> V_21 = V_2 -> V_4 [ V_14 ] ;
F_8 () ;
V_2 -> V_4 [ V_14 ] = V_19 ;
}
V_2 -> V_8 ++ ;
if ( V_12 >= V_2 -> V_9 )
V_2 -> V_9 = V_12 + 1 ;
V_20:
return V_15 ;
}
static struct V_13 * F_9 ( struct V_1 * V_2 , T_1 V_12 , int V_23 )
{
int V_14 ;
struct V_16 * V_18 ;
if ( ! V_2 )
return NULL ;
V_14 = F_5 ( V_12 ) ;
V_18 = V_2 -> V_4 [ V_14 ] ;
while ( V_18 && V_12 > V_18 -> V_12 )
V_18 = V_18 -> V_21 ;
if ( V_23 && V_18 && V_12 == V_18 -> V_12 && V_18 -> V_13 . V_24 )
return & V_18 -> V_13 ;
if ( V_18 == NULL || V_12 != V_18 -> V_12 || V_18 -> V_13 . V_24 ) {
V_12 = V_25 ;
V_14 = F_5 ( V_12 ) ;
V_18 = V_2 -> V_4 [ V_14 ] ;
while ( V_18 && V_12 > V_18 -> V_12 )
V_18 = V_18 -> V_21 ;
if ( ! V_18 || V_12 != V_18 -> V_12 )
return NULL ;
}
return & V_18 -> V_13 ;
}
struct V_13 * F_10 ( struct V_1 * V_2 , T_1 V_12 )
{
return F_9 ( V_2 , V_12 , 0 ) ;
}
struct V_13 * F_11 ( struct V_1 * V_2 , T_1 V_12 )
{
return F_9 ( V_2 , V_12 , 1 ) ;
}
int F_12 ( struct V_1 * V_2 ,
int (* F_13) ( T_1 V_12 ,
struct V_13 * V_13 ,
void * args ) ,
void * args )
{
int V_3 , V_15 = 0 ;
struct V_16 * V_18 ;
if ( ! V_2 )
goto V_20;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_18 = V_2 -> V_4 [ V_3 ] ;
while ( V_18 ) {
V_15 = F_13 ( V_18 -> V_12 , & V_18 -> V_13 , args ) ;
if ( V_15 )
goto V_20;
V_18 = V_18 -> V_21 ;
}
}
V_20:
return V_15 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_16 * V_26 , int V_27 )
{
F_15 ( V_27 >= V_28 ) ;
while ( V_27 > 0 ) {
V_2 -> V_29 [ V_27 ] = V_2 -> V_29 [ V_27 - 1 ] ;
V_27 -- ;
}
V_2 -> V_29 [ 0 ] = V_26 ;
}
static inline T_1 F_16 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
int V_3 ;
struct V_16 * V_18 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_18 = V_2 -> V_4 [ V_3 ] ;
while ( V_18 ) {
if ( F_17 ( & V_18 -> V_13 , V_13 ) ) {
F_14 ( V_2 , V_18 , V_28 - 1 ) ;
return V_18 -> V_12 ;
}
V_18 = V_18 -> V_21 ;
}
}
return 0 ;
}
static inline T_1 F_18 ( struct V_1 * V_2 , struct V_13 * V_13 )
{
int V_3 ;
struct V_16 * V_30 ;
for ( V_3 = 0 ; V_3 < V_28 ; V_3 ++ ) {
V_30 = V_2 -> V_29 [ V_3 ] ;
if ( F_19 ( ! V_30 ) )
return 0 ;
if ( F_17 ( & V_30 -> V_13 , V_13 ) ) {
F_14 ( V_2 , V_30 , V_3 ) ;
return V_30 -> V_12 ;
}
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_13 * V_13 ,
T_1 * V_31 )
{
T_1 V_12 ;
int V_32 = 0 ;
unsigned long V_33 ;
* V_31 = V_34 ;
V_12 = F_18 ( V_2 , V_13 ) ;
if ( ! V_12 )
V_12 = F_16 ( V_2 , V_13 ) ;
if ( ! V_12 ) {
F_21 ( & V_2 -> V_11 , V_33 ) ;
V_12 = F_16 ( V_2 , V_13 ) ;
if ( V_12 )
goto V_35;
if ( V_2 -> V_9 == V_36 || V_2 -> V_10 ) {
V_32 = - V_7 ;
goto V_35;
}
V_12 = V_2 -> V_9 ++ ;
if ( V_13 -> V_24 )
F_22 ( V_37
L_1 ,
V_13 -> V_38 ) ;
V_32 = F_4 ( V_2 , V_12 , V_13 ) ;
if ( V_32 )
V_2 -> V_9 -- ;
V_35:
F_23 ( & V_2 -> V_11 , V_33 ) ;
}
if ( V_32 )
return V_32 ;
* V_31 = V_12 ;
return 0 ;
}
void F_24 ( struct V_1 * V_39 , char * V_40 )
{
int V_3 , V_41 , V_42 , V_43 ;
struct V_16 * V_18 ;
V_42 = 0 ;
V_43 = 0 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_18 = V_39 -> V_4 [ V_3 ] ;
if ( V_18 ) {
V_42 ++ ;
V_41 = 0 ;
while ( V_18 ) {
V_41 ++ ;
V_18 = V_18 -> V_21 ;
}
if ( V_41 > V_43 )
V_43 = V_41 ;
}
}
F_22 ( V_44 L_2
L_3 , V_40 , V_39 -> V_8 , V_42 , V_5 ,
V_43 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_16 * V_18 , * V_45 ;
if ( ! V_2 )
return;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_18 = V_2 -> V_4 [ V_3 ] ;
while ( V_18 ) {
V_45 = V_18 ;
V_18 = V_18 -> V_21 ;
F_26 ( & V_45 -> V_13 ) ;
F_7 ( V_45 ) ;
}
V_2 -> V_4 [ V_3 ] = NULL ;
}
F_7 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 1 ;
}
void F_27 ( struct V_1 * V_46 , struct V_1 * V_47 )
{
unsigned long V_33 ;
int V_3 ;
F_21 ( & V_47 -> V_11 , V_33 ) ;
V_46 -> V_4 = V_47 -> V_4 ;
V_46 -> V_8 = V_47 -> V_8 ;
V_46 -> V_9 = V_47 -> V_9 ;
V_46 -> V_10 = 0 ;
for ( V_3 = 0 ; V_3 < V_28 ; V_3 ++ )
V_46 -> V_29 [ V_3 ] = NULL ;
F_23 ( & V_47 -> V_11 , V_33 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
unsigned long V_33 ;
F_21 ( & V_2 -> V_11 , V_33 ) ;
V_2 -> V_10 = 1 ;
F_23 ( & V_2 -> V_11 , V_33 ) ;
}
