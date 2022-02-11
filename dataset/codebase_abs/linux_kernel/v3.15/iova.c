void
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = V_3 ;
}
static struct V_9 *
F_3 ( struct V_1 * V_2 , unsigned long * V_10 )
{
if ( ( * V_10 != V_2 -> V_8 ) ||
( V_2 -> V_7 == NULL ) )
return F_4 ( & V_2 -> V_5 ) ;
else {
struct V_9 * V_11 = F_5 ( V_2 -> V_7 ) ;
struct V_12 * V_13 =
F_6 ( V_2 -> V_7 , struct V_12 , V_14 ) ;
* V_10 = V_13 -> V_15 - 1 ;
return V_11 ;
}
}
static void
F_7 ( struct V_1 * V_2 ,
unsigned long V_10 , struct V_12 * V_16 )
{
if ( V_10 != V_2 -> V_8 )
return;
V_2 -> V_7 = & V_16 -> V_14 ;
}
static void
F_8 ( struct V_1 * V_2 , struct V_12 * free )
{
struct V_12 * V_17 ;
struct V_9 * V_18 ;
if ( ! V_2 -> V_7 )
return;
V_18 = V_2 -> V_7 ;
V_17 = F_6 ( V_18 , struct V_12 , V_14 ) ;
if ( free -> V_15 >= V_17 -> V_15 ) {
struct V_9 * V_14 = F_9 ( & free -> V_14 ) ;
struct V_12 * V_12 = F_6 ( V_14 , struct V_12 , V_14 ) ;
if ( V_14 && V_12 -> V_15 < V_2 -> V_8 )
V_2 -> V_7 = V_14 ;
else
V_2 -> V_7 = NULL ;
}
}
static int
F_10 ( int V_19 , unsigned int V_10 )
{
unsigned int V_20 = 0 ;
unsigned int V_21 = F_11 ( V_19 ) ;
if ( V_21 )
V_20 = ( V_10 + 1 ) % ( 1 << V_21 ) ;
return V_20 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned long V_19 , unsigned long V_10 ,
struct V_12 * V_16 , bool V_22 )
{
struct V_9 * V_23 , * V_18 = NULL ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned int V_20 = 0 ;
F_13 ( & V_2 -> V_4 , V_24 ) ;
V_25 = V_10 ;
V_18 = F_3 ( V_2 , & V_10 ) ;
V_23 = V_18 ;
while ( V_18 ) {
struct V_12 * V_13 = F_6 ( V_18 , struct V_12 , V_14 ) ;
if ( V_10 < V_13 -> V_15 )
goto V_26;
else if ( V_10 < V_13 -> V_27 )
goto V_28;
else {
if ( V_22 )
V_20 = F_10 ( V_19 , V_10 ) ;
if ( ( V_13 -> V_27 + V_19 + V_20 ) <= V_10 )
break;
}
V_28:
V_10 = V_13 -> V_15 - 1 ;
V_26:
V_23 = V_18 ;
V_18 = F_5 ( V_18 ) ;
}
if ( ! V_18 ) {
if ( V_22 )
V_20 = F_10 ( V_19 , V_10 ) ;
if ( ( V_29 + V_19 + V_20 ) > V_10 ) {
F_14 ( & V_2 -> V_4 , V_24 ) ;
return - V_30 ;
}
}
V_16 -> V_15 = V_10 - ( V_19 + V_20 ) + 1 ;
V_16 -> V_27 = V_16 -> V_15 + V_19 - 1 ;
{
struct V_9 * * V_31 , * V_32 = NULL ;
if ( V_23 )
V_31 = & V_23 ;
else
V_31 = & V_2 -> V_5 . V_9 ;
while ( * V_31 ) {
struct V_12 * V_33 = F_6 ( * V_31 ,
struct V_12 , V_14 ) ;
V_32 = * V_31 ;
if ( V_16 -> V_15 < V_33 -> V_15 )
V_31 = & ( ( * V_31 ) -> V_34 ) ;
else if ( V_16 -> V_15 > V_33 -> V_15 )
V_31 = & ( ( * V_31 ) -> V_35 ) ;
else
F_15 () ;
}
F_16 ( & V_16 -> V_14 , V_32 , V_31 ) ;
F_17 ( & V_16 -> V_14 , & V_2 -> V_5 ) ;
}
F_7 ( V_2 , V_25 , V_16 ) ;
F_14 ( & V_2 -> V_4 , V_24 ) ;
return 0 ;
}
static void
F_18 ( struct V_36 * V_37 , struct V_12 * V_12 )
{
struct V_9 * * V_16 = & ( V_37 -> V_9 ) , * V_32 = NULL ;
while ( * V_16 ) {
struct V_12 * V_33 = F_6 ( * V_16 , struct V_12 , V_14 ) ;
V_32 = * V_16 ;
if ( V_12 -> V_15 < V_33 -> V_15 )
V_16 = & ( ( * V_16 ) -> V_34 ) ;
else if ( V_12 -> V_15 > V_33 -> V_15 )
V_16 = & ( ( * V_16 ) -> V_35 ) ;
else
F_15 () ;
}
F_16 ( & V_12 -> V_14 , V_32 , V_16 ) ;
F_17 ( & V_12 -> V_14 , V_37 ) ;
}
struct V_12 *
F_19 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long V_10 ,
bool V_22 )
{
struct V_12 * V_38 ;
int V_39 ;
V_38 = F_20 () ;
if ( ! V_38 )
return NULL ;
if ( V_22 )
V_19 = F_21 ( V_19 ) ;
V_39 = F_12 ( V_2 , V_19 , V_10 ,
V_38 , V_22 ) ;
if ( V_39 ) {
F_22 ( V_38 ) ;
return NULL ;
}
return V_38 ;
}
struct V_12 * F_23 ( struct V_1 * V_2 , unsigned long V_40 )
{
unsigned long V_24 ;
struct V_9 * V_14 ;
F_13 ( & V_2 -> V_4 , V_24 ) ;
V_14 = V_2 -> V_5 . V_9 ;
while ( V_14 ) {
struct V_12 * V_12 = F_6 ( V_14 , struct V_12 , V_14 ) ;
if ( ( V_40 >= V_12 -> V_15 ) && ( V_40 <= V_12 -> V_27 ) ) {
F_14 ( & V_2 -> V_4 , V_24 ) ;
return V_12 ;
}
if ( V_40 < V_12 -> V_15 )
V_14 = V_14 -> V_34 ;
else if ( V_40 > V_12 -> V_15 )
V_14 = V_14 -> V_35 ;
}
F_14 ( & V_2 -> V_4 , V_24 ) ;
return NULL ;
}
void
F_24 ( struct V_1 * V_2 , struct V_12 * V_12 )
{
unsigned long V_24 ;
F_13 ( & V_2 -> V_4 , V_24 ) ;
F_8 ( V_2 , V_12 ) ;
F_25 ( & V_12 -> V_14 , & V_2 -> V_5 ) ;
F_14 ( & V_2 -> V_4 , V_24 ) ;
F_22 ( V_12 ) ;
}
void
F_26 ( struct V_1 * V_2 , unsigned long V_40 )
{
struct V_12 * V_12 = F_23 ( V_2 , V_40 ) ;
if ( V_12 )
F_24 ( V_2 , V_12 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_14 ;
unsigned long V_24 ;
F_13 ( & V_2 -> V_4 , V_24 ) ;
V_14 = F_28 ( & V_2 -> V_5 ) ;
while ( V_14 ) {
struct V_12 * V_12 = F_6 ( V_14 , struct V_12 , V_14 ) ;
F_25 ( V_14 , & V_2 -> V_5 ) ;
F_22 ( V_12 ) ;
V_14 = F_28 ( & V_2 -> V_5 ) ;
}
F_14 ( & V_2 -> V_4 , V_24 ) ;
}
static int
F_29 ( struct V_9 * V_14 ,
unsigned long V_15 , unsigned long V_27 )
{
struct V_12 * V_12 = F_6 ( V_14 , struct V_12 , V_14 ) ;
if ( ( V_15 <= V_12 -> V_27 ) && ( V_27 >= V_12 -> V_15 ) )
return 1 ;
return 0 ;
}
static inline struct V_12 *
F_30 ( unsigned long V_15 , unsigned long V_27 )
{
struct V_12 * V_12 ;
V_12 = F_20 () ;
if ( V_12 ) {
V_12 -> V_15 = V_15 ;
V_12 -> V_27 = V_27 ;
}
return V_12 ;
}
static struct V_12 *
F_31 ( struct V_1 * V_2 ,
unsigned long V_15 , unsigned long V_27 )
{
struct V_12 * V_12 ;
V_12 = F_30 ( V_15 , V_27 ) ;
if ( V_12 )
F_18 ( & V_2 -> V_5 , V_12 ) ;
return V_12 ;
}
static void
F_32 ( struct V_12 * V_12 ,
unsigned long * V_15 , unsigned long * V_27 )
{
if ( * V_15 < V_12 -> V_15 )
V_12 -> V_15 = * V_15 ;
if ( * V_27 > V_12 -> V_27 )
* V_15 = V_12 -> V_27 + 1 ;
}
struct V_12 *
F_33 ( struct V_1 * V_2 ,
unsigned long V_15 , unsigned long V_27 )
{
struct V_9 * V_14 ;
unsigned long V_24 ;
struct V_12 * V_12 ;
unsigned int V_41 = 0 ;
F_13 ( & V_2 -> V_4 , V_24 ) ;
for ( V_14 = F_28 ( & V_2 -> V_5 ) ; V_14 ; V_14 = F_9 ( V_14 ) ) {
if ( F_29 ( V_14 , V_15 , V_27 ) ) {
V_12 = F_6 ( V_14 , struct V_12 , V_14 ) ;
F_32 ( V_12 , & V_15 , & V_27 ) ;
if ( ( V_15 >= V_12 -> V_15 ) &&
( V_27 <= V_12 -> V_27 ) )
goto V_42;
V_41 = 1 ;
} else if ( V_41 )
break;
}
V_12 = F_31 ( V_2 , V_15 , V_27 ) ;
V_42:
F_14 ( & V_2 -> V_4 , V_24 ) ;
return V_12 ;
}
void
F_34 ( struct V_1 * V_43 , struct V_1 * V_44 )
{
unsigned long V_24 ;
struct V_9 * V_14 ;
F_13 ( & V_43 -> V_4 , V_24 ) ;
for ( V_14 = F_28 ( & V_43 -> V_5 ) ; V_14 ; V_14 = F_9 ( V_14 ) ) {
struct V_12 * V_12 = F_6 ( V_14 , struct V_12 , V_14 ) ;
struct V_12 * V_38 ;
V_38 = F_33 ( V_44 , V_12 -> V_15 , V_12 -> V_27 ) ;
if ( ! V_38 )
F_35 ( V_45 L_1 ,
V_12 -> V_15 , V_12 -> V_15 ) ;
}
F_14 ( & V_43 -> V_4 , V_24 ) ;
}
struct V_12 *
F_36 ( struct V_1 * V_2 , struct V_12 * V_12 ,
unsigned long V_15 , unsigned long V_27 )
{
unsigned long V_24 ;
struct V_12 * V_23 = NULL , * V_46 = NULL ;
F_13 ( & V_2 -> V_4 , V_24 ) ;
if ( V_12 -> V_15 < V_15 ) {
V_23 = F_30 ( V_12 -> V_15 , V_15 - 1 ) ;
if ( V_23 == NULL )
goto error;
}
if ( V_12 -> V_27 > V_27 ) {
V_46 = F_30 ( V_27 + 1 , V_12 -> V_27 ) ;
if ( V_46 == NULL )
goto error;
}
F_8 ( V_2 , V_12 ) ;
F_25 ( & V_12 -> V_14 , & V_2 -> V_5 ) ;
if ( V_23 ) {
F_18 ( & V_2 -> V_5 , V_23 ) ;
V_12 -> V_15 = V_15 ;
}
if ( V_46 ) {
F_18 ( & V_2 -> V_5 , V_46 ) ;
V_12 -> V_27 = V_27 ;
}
F_14 ( & V_2 -> V_4 , V_24 ) ;
return V_12 ;
error:
F_14 ( & V_2 -> V_4 , V_24 ) ;
if ( V_23 )
F_22 ( V_23 ) ;
return NULL ;
}
