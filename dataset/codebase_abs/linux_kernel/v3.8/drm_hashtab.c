int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = 1 << V_3 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = NULL ;
if ( V_4 <= V_6 / sizeof( * V_2 -> V_5 ) )
V_2 -> V_5 = F_2 ( V_4 , sizeof( * V_2 -> V_5 ) , V_7 ) ;
else
V_2 -> V_5 = F_3 ( V_4 * sizeof( * V_2 -> V_5 ) ) ;
if ( ! V_2 -> V_5 ) {
F_4 ( L_1 ) ;
return - V_8 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 , unsigned long V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned int V_16 ;
int V_17 = 0 ;
V_16 = F_6 ( V_9 , V_2 -> V_3 ) ;
F_7 ( L_2 , V_9 , V_16 ) ;
V_13 = & V_2 -> V_5 [ V_16 ] ;
F_8 (entry, list, h_list, head)
F_7 ( L_3 , V_17 ++ , V_11 -> V_9 ) ;
}
static struct V_14 * F_9 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned int V_16 ;
V_16 = F_6 ( V_9 , V_2 -> V_3 ) ;
V_13 = & V_2 -> V_5 [ V_16 ] ;
F_8 (entry, list, h_list, head) {
if ( V_11 -> V_9 == V_9 )
return V_15 ;
if ( V_11 -> V_9 > V_9 )
break;
}
return NULL ;
}
static struct V_14 * F_10 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
unsigned int V_16 ;
V_16 = F_6 ( V_9 , V_2 -> V_3 ) ;
V_13 = & V_2 -> V_5 [ V_16 ] ;
F_11 (entry, list, h_list, head) {
if ( V_11 -> V_9 == V_9 )
return V_15 ;
if ( V_11 -> V_9 > V_9 )
break;
}
return NULL ;
}
int F_12 ( struct V_1 * V_2 , struct V_10 * V_18 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 , * V_19 ;
unsigned int V_16 ;
unsigned long V_9 = V_18 -> V_9 ;
V_16 = F_6 ( V_9 , V_2 -> V_3 ) ;
V_13 = & V_2 -> V_5 [ V_16 ] ;
V_19 = NULL ;
F_8 (entry, list, h_list, head) {
if ( V_11 -> V_9 == V_9 )
return - V_20 ;
if ( V_11 -> V_9 > V_9 )
break;
V_19 = V_15 ;
}
if ( V_19 ) {
F_13 ( V_19 , & V_18 -> V_21 ) ;
} else {
F_14 ( & V_18 -> V_21 , V_13 ) ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_10 * V_18 ,
unsigned long V_22 , int V_23 , int V_24 ,
unsigned long V_25 )
{
int V_26 ;
unsigned long V_27 = ( 1 << V_23 ) - 1 ;
unsigned long V_28 , V_29 ;
V_29 = F_6 ( V_22 , V_23 ) ;
V_28 = V_29 ;
do {
V_18 -> V_9 = ( V_29 << V_24 ) + V_25 ;
V_26 = F_12 ( V_2 , V_18 ) ;
if ( V_26 )
V_29 = ( V_29 + 1 ) & V_27 ;
} while( V_26 && ( V_29 != V_28 ) );
if ( V_26 ) {
F_4 ( L_4 ) ;
return - V_20 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , unsigned long V_9 ,
struct V_10 * * V_18 )
{
struct V_14 * V_15 ;
V_15 = F_10 ( V_2 , V_9 ) ;
if ( ! V_15 )
return - V_20 ;
* V_18 = F_17 ( V_15 , struct V_10 , V_21 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , unsigned long V_9 )
{
struct V_14 * V_15 ;
V_15 = F_9 ( V_2 , V_9 ) ;
if ( V_15 ) {
F_19 ( V_15 ) ;
return 0 ;
}
return - V_20 ;
}
int F_20 ( struct V_1 * V_2 , struct V_10 * V_18 )
{
F_19 ( & V_18 -> V_21 ) ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 ) {
if ( ( V_6 / sizeof( * V_2 -> V_5 ) ) >> V_2 -> V_3 )
F_22 ( V_2 -> V_5 ) ;
else
F_23 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
}
