int F_1 ( void )
{
int V_1 = 0 ;
V_2 = F_2 ( L_1 ,
sizeof( struct V_3 ) ,
0 ,
V_4 ,
NULL ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
V_1 = - V_5 ;
}
return V_1 ;
}
void F_4 ( void )
{
F_5 ( V_2 ) ;
}
struct V_3 * F_6 ( void )
{
return F_7 ( V_2 , V_6 ) ;
}
void F_8 ( struct V_3 * V_3 )
{
F_9 ( V_2 , V_3 ) ;
}
void
F_10 ( struct V_7 * V_8 , unsigned long V_9 ,
unsigned long V_10 , unsigned long V_11 )
{
F_11 ( ( V_9 > V_12 ) || ! F_12 ( V_9 ) ) ;
F_13 ( & V_8 -> V_13 ) ;
V_8 -> V_14 = V_15 ;
V_8 -> V_16 = NULL ;
V_8 -> V_9 = V_9 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_17 = V_11 ;
}
static struct V_18 *
F_14 ( struct V_7 * V_8 , unsigned long * V_19 )
{
if ( ( * V_19 != V_8 -> V_17 ) ||
( V_8 -> V_16 == NULL ) )
return F_15 ( & V_8 -> V_14 ) ;
else {
struct V_18 * V_20 = F_16 ( V_8 -> V_16 ) ;
struct V_3 * V_21 =
F_17 ( V_8 -> V_16 , struct V_3 , V_22 ) ;
* V_19 = V_21 -> V_23 - 1 ;
return V_20 ;
}
}
static void
F_18 ( struct V_7 * V_8 ,
unsigned long V_19 , struct V_3 * V_24 )
{
if ( V_19 != V_8 -> V_17 )
return;
V_8 -> V_16 = & V_24 -> V_22 ;
}
static void
F_19 ( struct V_7 * V_8 , struct V_3 * free )
{
struct V_3 * V_25 ;
struct V_18 * V_26 ;
if ( ! V_8 -> V_16 )
return;
V_26 = V_8 -> V_16 ;
V_25 = F_17 ( V_26 , struct V_3 , V_22 ) ;
if ( free -> V_23 >= V_25 -> V_23 ) {
struct V_18 * V_22 = F_20 ( & free -> V_22 ) ;
struct V_3 * V_3 = F_17 ( V_22 , struct V_3 , V_22 ) ;
if ( V_22 && V_3 -> V_23 < V_8 -> V_17 )
V_8 -> V_16 = V_22 ;
else
V_8 -> V_16 = NULL ;
}
}
static int
F_21 ( int V_27 , unsigned int V_19 )
{
unsigned int V_28 = 0 ;
unsigned int V_29 = F_22 ( V_27 ) ;
if ( V_29 )
V_28 = ( V_19 + 1 ) % ( 1 << V_29 ) ;
return V_28 ;
}
static int F_23 ( struct V_7 * V_8 ,
unsigned long V_27 , unsigned long V_19 ,
struct V_3 * V_24 , bool V_30 )
{
struct V_18 * V_31 , * V_26 = NULL ;
unsigned long V_32 ;
unsigned long V_33 ;
unsigned int V_28 = 0 ;
F_24 ( & V_8 -> V_13 , V_32 ) ;
V_33 = V_19 ;
V_26 = F_14 ( V_8 , & V_19 ) ;
V_31 = V_26 ;
while ( V_26 ) {
struct V_3 * V_21 = F_17 ( V_26 , struct V_3 , V_22 ) ;
if ( V_19 < V_21 -> V_23 )
goto V_34;
else if ( V_19 < V_21 -> V_35 )
goto V_36;
else {
if ( V_30 )
V_28 = F_21 ( V_27 , V_19 ) ;
if ( ( V_21 -> V_35 + V_27 + V_28 ) <= V_19 )
break;
}
V_36:
V_19 = V_21 -> V_23 - 1 ;
V_34:
V_31 = V_26 ;
V_26 = F_16 ( V_26 ) ;
}
if ( ! V_26 ) {
if ( V_30 )
V_28 = F_21 ( V_27 , V_19 ) ;
if ( ( V_8 -> V_10 + V_27 + V_28 ) > V_19 ) {
F_25 ( & V_8 -> V_13 , V_32 ) ;
return - V_5 ;
}
}
V_24 -> V_23 = V_19 - ( V_27 + V_28 ) + 1 ;
V_24 -> V_35 = V_24 -> V_23 + V_27 - 1 ;
{
struct V_18 * * V_37 , * V_38 = NULL ;
if ( V_31 )
V_37 = & V_31 ;
else
V_37 = & V_8 -> V_14 . V_18 ;
while ( * V_37 ) {
struct V_3 * V_39 = F_17 ( * V_37 ,
struct V_3 , V_22 ) ;
V_38 = * V_37 ;
if ( V_24 -> V_23 < V_39 -> V_23 )
V_37 = & ( ( * V_37 ) -> V_40 ) ;
else if ( V_24 -> V_23 > V_39 -> V_23 )
V_37 = & ( ( * V_37 ) -> V_41 ) ;
else
F_26 () ;
}
F_27 ( & V_24 -> V_22 , V_38 , V_37 ) ;
F_28 ( & V_24 -> V_22 , & V_8 -> V_14 ) ;
}
F_18 ( V_8 , V_33 , V_24 ) ;
F_25 ( & V_8 -> V_13 , V_32 ) ;
return 0 ;
}
static void
F_29 ( struct V_42 * V_43 , struct V_3 * V_3 )
{
struct V_18 * * V_24 = & ( V_43 -> V_18 ) , * V_38 = NULL ;
while ( * V_24 ) {
struct V_3 * V_39 = F_17 ( * V_24 , struct V_3 , V_22 ) ;
V_38 = * V_24 ;
if ( V_3 -> V_23 < V_39 -> V_23 )
V_24 = & ( ( * V_24 ) -> V_40 ) ;
else if ( V_3 -> V_23 > V_39 -> V_23 )
V_24 = & ( ( * V_24 ) -> V_41 ) ;
else
F_26 () ;
}
F_27 ( & V_3 -> V_22 , V_38 , V_24 ) ;
F_28 ( & V_3 -> V_22 , V_43 ) ;
}
struct V_3 *
F_30 ( struct V_7 * V_8 , unsigned long V_27 ,
unsigned long V_19 ,
bool V_30 )
{
struct V_3 * V_44 ;
int V_1 ;
V_44 = F_6 () ;
if ( ! V_44 )
return NULL ;
if ( V_30 )
V_27 = F_31 ( V_27 ) ;
V_1 = F_23 ( V_8 , V_27 , V_19 ,
V_44 , V_30 ) ;
if ( V_1 ) {
F_8 ( V_44 ) ;
return NULL ;
}
return V_44 ;
}
struct V_3 * F_32 ( struct V_7 * V_8 , unsigned long V_45 )
{
unsigned long V_32 ;
struct V_18 * V_22 ;
F_24 ( & V_8 -> V_13 , V_32 ) ;
V_22 = V_8 -> V_14 . V_18 ;
while ( V_22 ) {
struct V_3 * V_3 = F_17 ( V_22 , struct V_3 , V_22 ) ;
if ( ( V_45 >= V_3 -> V_23 ) && ( V_45 <= V_3 -> V_35 ) ) {
F_25 ( & V_8 -> V_13 , V_32 ) ;
return V_3 ;
}
if ( V_45 < V_3 -> V_23 )
V_22 = V_22 -> V_40 ;
else if ( V_45 > V_3 -> V_23 )
V_22 = V_22 -> V_41 ;
}
F_25 ( & V_8 -> V_13 , V_32 ) ;
return NULL ;
}
void
F_33 ( struct V_7 * V_8 , struct V_3 * V_3 )
{
unsigned long V_32 ;
F_24 ( & V_8 -> V_13 , V_32 ) ;
F_19 ( V_8 , V_3 ) ;
F_34 ( & V_3 -> V_22 , & V_8 -> V_14 ) ;
F_25 ( & V_8 -> V_13 , V_32 ) ;
F_8 ( V_3 ) ;
}
void
F_35 ( struct V_7 * V_8 , unsigned long V_45 )
{
struct V_3 * V_3 = F_32 ( V_8 , V_45 ) ;
if ( V_3 )
F_33 ( V_8 , V_3 ) ;
}
void F_36 ( struct V_7 * V_8 )
{
struct V_18 * V_22 ;
unsigned long V_32 ;
F_24 ( & V_8 -> V_13 , V_32 ) ;
V_22 = F_37 ( & V_8 -> V_14 ) ;
while ( V_22 ) {
struct V_3 * V_3 = F_17 ( V_22 , struct V_3 , V_22 ) ;
F_34 ( V_22 , & V_8 -> V_14 ) ;
F_8 ( V_3 ) ;
V_22 = F_37 ( & V_8 -> V_14 ) ;
}
F_25 ( & V_8 -> V_13 , V_32 ) ;
}
static int
F_38 ( struct V_18 * V_22 ,
unsigned long V_23 , unsigned long V_35 )
{
struct V_3 * V_3 = F_17 ( V_22 , struct V_3 , V_22 ) ;
if ( ( V_23 <= V_3 -> V_35 ) && ( V_35 >= V_3 -> V_23 ) )
return 1 ;
return 0 ;
}
static inline struct V_3 *
F_39 ( unsigned long V_23 , unsigned long V_35 )
{
struct V_3 * V_3 ;
V_3 = F_6 () ;
if ( V_3 ) {
V_3 -> V_23 = V_23 ;
V_3 -> V_35 = V_35 ;
}
return V_3 ;
}
static struct V_3 *
F_40 ( struct V_7 * V_8 ,
unsigned long V_23 , unsigned long V_35 )
{
struct V_3 * V_3 ;
V_3 = F_39 ( V_23 , V_35 ) ;
if ( V_3 )
F_29 ( & V_8 -> V_14 , V_3 ) ;
return V_3 ;
}
static void
F_41 ( struct V_3 * V_3 ,
unsigned long * V_23 , unsigned long * V_35 )
{
if ( * V_23 < V_3 -> V_23 )
V_3 -> V_23 = * V_23 ;
if ( * V_35 > V_3 -> V_35 )
* V_23 = V_3 -> V_35 + 1 ;
}
struct V_3 *
F_42 ( struct V_7 * V_8 ,
unsigned long V_23 , unsigned long V_35 )
{
struct V_18 * V_22 ;
unsigned long V_32 ;
struct V_3 * V_3 ;
unsigned int V_46 = 0 ;
F_24 ( & V_8 -> V_13 , V_32 ) ;
for ( V_22 = F_37 ( & V_8 -> V_14 ) ; V_22 ; V_22 = F_20 ( V_22 ) ) {
if ( F_38 ( V_22 , V_23 , V_35 ) ) {
V_3 = F_17 ( V_22 , struct V_3 , V_22 ) ;
F_41 ( V_3 , & V_23 , & V_35 ) ;
if ( ( V_23 >= V_3 -> V_23 ) &&
( V_35 <= V_3 -> V_35 ) )
goto V_47;
V_46 = 1 ;
} else if ( V_46 )
break;
}
V_3 = F_40 ( V_8 , V_23 , V_35 ) ;
V_47:
F_25 ( & V_8 -> V_13 , V_32 ) ;
return V_3 ;
}
void
F_43 ( struct V_7 * V_48 , struct V_7 * V_49 )
{
unsigned long V_32 ;
struct V_18 * V_22 ;
F_24 ( & V_48 -> V_13 , V_32 ) ;
for ( V_22 = F_37 ( & V_48 -> V_14 ) ; V_22 ; V_22 = F_20 ( V_22 ) ) {
struct V_3 * V_3 = F_17 ( V_22 , struct V_3 , V_22 ) ;
struct V_3 * V_44 ;
V_44 = F_42 ( V_49 , V_3 -> V_23 , V_3 -> V_35 ) ;
if ( ! V_44 )
F_44 ( V_50 L_3 ,
V_3 -> V_23 , V_3 -> V_23 ) ;
}
F_25 ( & V_48 -> V_13 , V_32 ) ;
}
struct V_3 *
F_45 ( struct V_7 * V_8 , struct V_3 * V_3 ,
unsigned long V_23 , unsigned long V_35 )
{
unsigned long V_32 ;
struct V_3 * V_31 = NULL , * V_51 = NULL ;
F_24 ( & V_8 -> V_13 , V_32 ) ;
if ( V_3 -> V_23 < V_23 ) {
V_31 = F_39 ( V_3 -> V_23 , V_23 - 1 ) ;
if ( V_31 == NULL )
goto error;
}
if ( V_3 -> V_35 > V_35 ) {
V_51 = F_39 ( V_35 + 1 , V_3 -> V_35 ) ;
if ( V_51 == NULL )
goto error;
}
F_19 ( V_8 , V_3 ) ;
F_34 ( & V_3 -> V_22 , & V_8 -> V_14 ) ;
if ( V_31 ) {
F_29 ( & V_8 -> V_14 , V_31 ) ;
V_3 -> V_23 = V_23 ;
}
if ( V_51 ) {
F_29 ( & V_8 -> V_14 , V_51 ) ;
V_3 -> V_35 = V_35 ;
}
F_25 ( & V_8 -> V_13 , V_32 ) ;
return V_3 ;
error:
F_25 ( & V_8 -> V_13 , V_32 ) ;
if ( V_31 )
F_8 ( V_31 ) ;
return NULL ;
}
