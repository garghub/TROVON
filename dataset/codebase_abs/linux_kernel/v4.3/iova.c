void
F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
F_2 ( ( V_3 > V_6 ) || ! F_3 ( V_3 ) ) ;
F_4 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = NULL ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_11 = V_5 ;
}
static struct V_12 *
F_5 ( struct V_1 * V_2 , unsigned long * V_13 )
{
if ( ( * V_13 != V_2 -> V_11 ) ||
( V_2 -> V_10 == NULL ) )
return F_6 ( & V_2 -> V_8 ) ;
else {
struct V_12 * V_14 = F_7 ( V_2 -> V_10 ) ;
struct V_15 * V_16 =
F_8 ( V_2 -> V_10 , struct V_15 , V_17 ) ;
* V_13 = V_16 -> V_18 - 1 ;
return V_14 ;
}
}
static void
F_9 ( struct V_1 * V_2 ,
unsigned long V_13 , struct V_15 * V_19 )
{
if ( V_13 != V_2 -> V_11 )
return;
V_2 -> V_10 = & V_19 -> V_17 ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_15 * free )
{
struct V_15 * V_20 ;
struct V_12 * V_21 ;
if ( ! V_2 -> V_10 )
return;
V_21 = V_2 -> V_10 ;
V_20 = F_8 ( V_21 , struct V_15 , V_17 ) ;
if ( free -> V_18 >= V_20 -> V_18 ) {
struct V_12 * V_17 = F_11 ( & free -> V_17 ) ;
struct V_15 * V_15 = F_8 ( V_17 , struct V_15 , V_17 ) ;
if ( V_17 && V_15 -> V_18 < V_2 -> V_11 )
V_2 -> V_10 = V_17 ;
else
V_2 -> V_10 = NULL ;
}
}
static unsigned int
F_12 ( unsigned int V_22 , unsigned int V_13 )
{
return ( V_13 + 1 - V_22 ) & ( F_13 ( V_22 ) - 1 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned long V_22 , unsigned long V_13 ,
struct V_15 * V_19 , bool V_23 )
{
struct V_12 * V_24 , * V_21 = NULL ;
unsigned long V_25 ;
unsigned long V_26 ;
unsigned int V_27 = 0 ;
F_15 ( & V_2 -> V_7 , V_25 ) ;
V_26 = V_13 ;
V_21 = F_5 ( V_2 , & V_13 ) ;
V_24 = V_21 ;
while ( V_21 ) {
struct V_15 * V_16 = F_8 ( V_21 , struct V_15 , V_17 ) ;
if ( V_13 < V_16 -> V_18 )
goto V_28;
else if ( V_13 < V_16 -> V_29 )
goto V_30;
else {
if ( V_23 )
V_27 = F_12 ( V_22 , V_13 ) ;
if ( ( V_16 -> V_29 + V_22 + V_27 ) <= V_13 )
break;
}
V_30:
V_13 = V_16 -> V_18 - 1 ;
V_28:
V_24 = V_21 ;
V_21 = F_7 ( V_21 ) ;
}
if ( ! V_21 ) {
if ( V_23 )
V_27 = F_12 ( V_22 , V_13 ) ;
if ( ( V_2 -> V_4 + V_22 + V_27 ) > V_13 ) {
F_16 ( & V_2 -> V_7 , V_25 ) ;
return - V_31 ;
}
}
V_19 -> V_18 = V_13 - ( V_22 + V_27 ) + 1 ;
V_19 -> V_29 = V_19 -> V_18 + V_22 - 1 ;
{
struct V_12 * * V_32 , * V_33 = NULL ;
if ( V_24 )
V_32 = & V_24 ;
else
V_32 = & V_2 -> V_8 . V_12 ;
while ( * V_32 ) {
struct V_15 * V_34 = F_8 ( * V_32 ,
struct V_15 , V_17 ) ;
V_33 = * V_32 ;
if ( V_19 -> V_18 < V_34 -> V_18 )
V_32 = & ( ( * V_32 ) -> V_35 ) ;
else if ( V_19 -> V_18 > V_34 -> V_18 )
V_32 = & ( ( * V_32 ) -> V_36 ) ;
else
F_17 () ;
}
F_18 ( & V_19 -> V_17 , V_33 , V_32 ) ;
F_19 ( & V_19 -> V_17 , & V_2 -> V_8 ) ;
}
F_9 ( V_2 , V_26 , V_19 ) ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
return 0 ;
}
static void
F_20 ( struct V_37 * V_38 , struct V_15 * V_15 )
{
struct V_12 * * V_19 = & ( V_38 -> V_12 ) , * V_33 = NULL ;
while ( * V_19 ) {
struct V_15 * V_34 = F_8 ( * V_19 , struct V_15 , V_17 ) ;
V_33 = * V_19 ;
if ( V_15 -> V_18 < V_34 -> V_18 )
V_19 = & ( ( * V_19 ) -> V_35 ) ;
else if ( V_15 -> V_18 > V_34 -> V_18 )
V_19 = & ( ( * V_19 ) -> V_36 ) ;
else
F_17 () ;
}
F_18 ( & V_15 -> V_17 , V_33 , V_19 ) ;
F_19 ( & V_15 -> V_17 , V_38 ) ;
}
struct V_15 * F_21 ( void )
{
return F_22 ( V_39 , V_40 ) ;
}
void F_23 ( struct V_15 * V_15 )
{
F_24 ( V_39 , V_15 ) ;
}
int F_25 ( void )
{
F_26 ( & V_41 ) ;
if ( ! V_42 ) {
V_39 = F_27 (
L_1 , sizeof( struct V_15 ) , 0 ,
V_43 , NULL ) ;
if ( ! V_39 ) {
F_28 ( & V_41 ) ;
F_29 ( V_44 L_2 ) ;
return - V_31 ;
}
}
V_42 ++ ;
F_28 ( & V_41 ) ;
return 0 ;
}
void F_30 ( void )
{
F_26 ( & V_41 ) ;
if ( F_31 ( ! V_42 ) ) {
F_28 ( & V_41 ) ;
return;
}
V_42 -- ;
if ( ! V_42 )
F_32 ( V_39 ) ;
F_28 ( & V_41 ) ;
}
struct V_15 *
F_33 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long V_13 ,
bool V_23 )
{
struct V_15 * V_45 ;
int V_46 ;
V_45 = F_21 () ;
if ( ! V_45 )
return NULL ;
V_46 = F_14 ( V_2 , V_22 , V_13 ,
V_45 , V_23 ) ;
if ( V_46 ) {
F_23 ( V_45 ) ;
return NULL ;
}
return V_45 ;
}
struct V_15 * F_34 ( struct V_1 * V_2 , unsigned long V_47 )
{
unsigned long V_25 ;
struct V_12 * V_17 ;
F_15 ( & V_2 -> V_7 , V_25 ) ;
V_17 = V_2 -> V_8 . V_12 ;
while ( V_17 ) {
struct V_15 * V_15 = F_8 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_47 >= V_15 -> V_18 ) && ( V_47 <= V_15 -> V_29 ) ) {
F_16 ( & V_2 -> V_7 , V_25 ) ;
return V_15 ;
}
if ( V_47 < V_15 -> V_18 )
V_17 = V_17 -> V_35 ;
else if ( V_47 > V_15 -> V_18 )
V_17 = V_17 -> V_36 ;
}
F_16 ( & V_2 -> V_7 , V_25 ) ;
return NULL ;
}
void
F_35 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
unsigned long V_25 ;
F_15 ( & V_2 -> V_7 , V_25 ) ;
F_10 ( V_2 , V_15 ) ;
F_36 ( & V_15 -> V_17 , & V_2 -> V_8 ) ;
F_16 ( & V_2 -> V_7 , V_25 ) ;
F_23 ( V_15 ) ;
}
void
F_37 ( struct V_1 * V_2 , unsigned long V_47 )
{
struct V_15 * V_15 = F_34 ( V_2 , V_47 ) ;
if ( V_15 )
F_35 ( V_2 , V_15 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_12 * V_17 ;
unsigned long V_25 ;
F_15 ( & V_2 -> V_7 , V_25 ) ;
V_17 = F_39 ( & V_2 -> V_8 ) ;
while ( V_17 ) {
struct V_15 * V_15 = F_8 ( V_17 , struct V_15 , V_17 ) ;
F_36 ( V_17 , & V_2 -> V_8 ) ;
F_23 ( V_15 ) ;
V_17 = F_39 ( & V_2 -> V_8 ) ;
}
F_16 ( & V_2 -> V_7 , V_25 ) ;
}
static int
F_40 ( struct V_12 * V_17 ,
unsigned long V_18 , unsigned long V_29 )
{
struct V_15 * V_15 = F_8 ( V_17 , struct V_15 , V_17 ) ;
if ( ( V_18 <= V_15 -> V_29 ) && ( V_29 >= V_15 -> V_18 ) )
return 1 ;
return 0 ;
}
static inline struct V_15 *
F_41 ( unsigned long V_18 , unsigned long V_29 )
{
struct V_15 * V_15 ;
V_15 = F_21 () ;
if ( V_15 ) {
V_15 -> V_18 = V_18 ;
V_15 -> V_29 = V_29 ;
}
return V_15 ;
}
static struct V_15 *
F_42 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_29 )
{
struct V_15 * V_15 ;
V_15 = F_41 ( V_18 , V_29 ) ;
if ( V_15 )
F_20 ( & V_2 -> V_8 , V_15 ) ;
return V_15 ;
}
static void
F_43 ( struct V_15 * V_15 ,
unsigned long * V_18 , unsigned long * V_29 )
{
if ( * V_18 < V_15 -> V_18 )
V_15 -> V_18 = * V_18 ;
if ( * V_29 > V_15 -> V_29 )
* V_18 = V_15 -> V_29 + 1 ;
}
struct V_15 *
F_44 ( struct V_1 * V_2 ,
unsigned long V_18 , unsigned long V_29 )
{
struct V_12 * V_17 ;
unsigned long V_25 ;
struct V_15 * V_15 ;
unsigned int V_48 = 0 ;
F_15 ( & V_2 -> V_7 , V_25 ) ;
for ( V_17 = F_39 ( & V_2 -> V_8 ) ; V_17 ; V_17 = F_11 ( V_17 ) ) {
if ( F_40 ( V_17 , V_18 , V_29 ) ) {
V_15 = F_8 ( V_17 , struct V_15 , V_17 ) ;
F_43 ( V_15 , & V_18 , & V_29 ) ;
if ( ( V_18 >= V_15 -> V_18 ) &&
( V_29 <= V_15 -> V_29 ) )
goto V_49;
V_48 = 1 ;
} else if ( V_48 )
break;
}
V_15 = F_42 ( V_2 , V_18 , V_29 ) ;
V_49:
F_16 ( & V_2 -> V_7 , V_25 ) ;
return V_15 ;
}
void
F_45 ( struct V_1 * V_50 , struct V_1 * V_51 )
{
unsigned long V_25 ;
struct V_12 * V_17 ;
F_15 ( & V_50 -> V_7 , V_25 ) ;
for ( V_17 = F_39 ( & V_50 -> V_8 ) ; V_17 ; V_17 = F_11 ( V_17 ) ) {
struct V_15 * V_15 = F_8 ( V_17 , struct V_15 , V_17 ) ;
struct V_15 * V_45 ;
V_45 = F_44 ( V_51 , V_15 -> V_18 , V_15 -> V_29 ) ;
if ( ! V_45 )
F_29 ( V_44 L_3 ,
V_15 -> V_18 , V_15 -> V_18 ) ;
}
F_16 ( & V_50 -> V_7 , V_25 ) ;
}
struct V_15 *
F_46 ( struct V_1 * V_2 , struct V_15 * V_15 ,
unsigned long V_18 , unsigned long V_29 )
{
unsigned long V_25 ;
struct V_15 * V_24 = NULL , * V_52 = NULL ;
F_15 ( & V_2 -> V_7 , V_25 ) ;
if ( V_15 -> V_18 < V_18 ) {
V_24 = F_41 ( V_15 -> V_18 , V_18 - 1 ) ;
if ( V_24 == NULL )
goto error;
}
if ( V_15 -> V_29 > V_29 ) {
V_52 = F_41 ( V_29 + 1 , V_15 -> V_29 ) ;
if ( V_52 == NULL )
goto error;
}
F_10 ( V_2 , V_15 ) ;
F_36 ( & V_15 -> V_17 , & V_2 -> V_8 ) ;
if ( V_24 ) {
F_20 ( & V_2 -> V_8 , V_24 ) ;
V_15 -> V_18 = V_18 ;
}
if ( V_52 ) {
F_20 ( & V_2 -> V_8 , V_52 ) ;
V_15 -> V_29 = V_29 ;
}
F_16 ( & V_2 -> V_7 , V_25 ) ;
return V_15 ;
error:
F_16 ( & V_2 -> V_7 , V_25 ) ;
if ( V_24 )
F_23 ( V_24 ) ;
return NULL ;
}
