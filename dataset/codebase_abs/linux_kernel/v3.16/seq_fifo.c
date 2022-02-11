struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL ) {
F_3 ( L_1 ) ;
return NULL ;
}
V_3 -> V_5 = F_4 ( V_2 ) ;
if ( V_3 -> V_5 == NULL ) {
F_5 ( V_3 ) ;
return NULL ;
}
if ( F_6 ( V_3 -> V_5 ) < 0 ) {
F_7 ( & V_3 -> V_5 ) ;
F_5 ( V_3 ) ;
return NULL ;
}
F_8 ( & V_3 -> V_6 ) ;
F_9 ( & V_3 -> V_7 ) ;
F_10 ( & V_3 -> V_8 ) ;
F_11 ( & V_3 -> V_9 , 0 ) ;
V_3 -> V_10 = NULL ;
V_3 -> V_11 = NULL ;
V_3 -> V_12 = 0 ;
return V_3 ;
}
void F_12 ( struct V_1 * * V_13 )
{
struct V_1 * V_3 ;
if ( F_13 ( ! V_13 ) )
return;
V_3 = * V_13 ;
if ( F_13 ( ! V_3 ) )
return;
* V_13 = NULL ;
F_14 ( V_3 ) ;
if ( F_15 ( & V_3 -> V_8 ) )
F_16 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_5 ) {
F_17 ( V_3 -> V_5 ) ;
F_7 ( & V_3 -> V_5 ) ;
}
F_5 ( V_3 ) ;
}
void F_14 ( struct V_1 * V_3 )
{
struct V_14 * V_15 ;
unsigned long V_16 ;
F_11 ( & V_3 -> V_9 , 0 ) ;
F_18 ( & V_3 -> V_7 ) ;
F_19 ( & V_3 -> V_6 , V_16 ) ;
while ( ( V_15 = F_20 ( V_3 ) ) != NULL ) {
F_21 ( V_15 ) ;
}
F_22 ( & V_3 -> V_6 , V_16 ) ;
}
int F_23 ( struct V_1 * V_3 ,
struct V_17 * V_18 )
{
struct V_14 * V_15 ;
unsigned long V_16 ;
int V_19 ;
if ( F_13 ( ! V_3 ) )
return - V_20 ;
F_24 ( & V_3 -> V_7 ) ;
V_19 = F_25 ( V_3 -> V_5 , V_18 , & V_15 , 1 , NULL ) ;
if ( V_19 < 0 ) {
if ( ( V_19 == - V_21 ) || ( V_19 == - V_22 ) )
F_26 ( & V_3 -> V_9 ) ;
F_27 ( & V_3 -> V_7 ) ;
return V_19 ;
}
F_19 ( & V_3 -> V_6 , V_16 ) ;
if ( V_3 -> V_11 != NULL )
V_3 -> V_11 -> V_23 = V_15 ;
V_3 -> V_11 = V_15 ;
if ( V_3 -> V_10 == NULL )
V_3 -> V_10 = V_15 ;
V_3 -> V_12 ++ ;
F_22 ( & V_3 -> V_6 , V_16 ) ;
if ( F_15 ( & V_3 -> V_8 ) )
F_16 ( & V_3 -> V_8 ) ;
F_27 ( & V_3 -> V_7 ) ;
return 0 ;
}
static struct V_14 * F_20 ( struct V_1 * V_3 )
{
struct V_14 * V_15 ;
if ( ( V_15 = V_3 -> V_10 ) != NULL ) {
V_3 -> V_10 = V_15 -> V_23 ;
if ( V_3 -> V_11 == V_15 )
V_3 -> V_11 = NULL ;
V_15 -> V_23 = NULL ;
V_3 -> V_12 -- ;
}
return V_15 ;
}
int F_28 ( struct V_1 * V_3 ,
struct V_14 * * V_24 , int V_25 )
{
struct V_14 * V_15 ;
unsigned long V_16 ;
T_1 V_26 ;
if ( F_13 ( ! V_3 ) )
return - V_20 ;
* V_24 = NULL ;
F_29 ( & V_26 , V_27 ) ;
F_19 ( & V_3 -> V_6 , V_16 ) ;
while ( ( V_15 = F_20 ( V_3 ) ) == NULL ) {
if ( V_25 ) {
F_22 ( & V_3 -> V_6 , V_16 ) ;
return - V_22 ;
}
F_30 ( V_28 ) ;
F_31 ( & V_3 -> V_8 , & V_26 ) ;
F_32 ( & V_3 -> V_6 ) ;
F_33 () ;
F_34 ( & V_3 -> V_6 ) ;
F_35 ( & V_3 -> V_8 , & V_26 ) ;
if ( F_36 ( V_27 ) ) {
F_22 ( & V_3 -> V_6 , V_16 ) ;
return - V_29 ;
}
}
F_22 ( & V_3 -> V_6 , V_16 ) ;
* V_24 = V_15 ;
return 0 ;
}
void F_37 ( struct V_1 * V_3 ,
struct V_14 * V_15 )
{
unsigned long V_16 ;
if ( V_15 ) {
F_19 ( & V_3 -> V_6 , V_16 ) ;
V_15 -> V_23 = V_3 -> V_10 ;
V_3 -> V_10 = V_15 ;
V_3 -> V_12 ++ ;
F_22 ( & V_3 -> V_6 , V_16 ) ;
}
}
int F_38 ( struct V_1 * V_3 , struct V_30 * V_30 ,
T_2 * V_26 )
{
F_39 ( V_30 , & V_3 -> V_8 , V_26 ) ;
return ( V_3 -> V_12 > 0 ) ;
}
int F_40 ( struct V_1 * V_3 , int V_2 )
{
unsigned long V_16 ;
struct V_31 * V_32 , * V_33 ;
struct V_14 * V_15 , * V_23 , * V_34 ;
if ( F_13 ( ! V_3 || ! V_3 -> V_5 ) )
return - V_20 ;
V_32 = F_4 ( V_2 ) ;
if ( V_32 == NULL )
return - V_21 ;
if ( F_6 ( V_32 ) < 0 ) {
F_7 ( & V_32 ) ;
return - V_21 ;
}
F_19 ( & V_3 -> V_6 , V_16 ) ;
V_33 = V_3 -> V_5 ;
V_34 = V_3 -> V_10 ;
V_3 -> V_5 = V_32 ;
V_3 -> V_10 = NULL ;
V_3 -> V_11 = NULL ;
V_3 -> V_12 = 0 ;
F_22 ( & V_3 -> V_6 , V_16 ) ;
for ( V_15 = V_34 ; V_15 ; V_15 = V_23 ) {
V_23 = V_15 -> V_23 ;
F_21 ( V_15 ) ;
}
F_7 ( & V_33 ) ;
return 0 ;
}
