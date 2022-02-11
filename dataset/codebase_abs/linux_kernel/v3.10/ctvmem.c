static struct V_1 *
F_1 ( struct V_2 * V_3 , unsigned int V_4 )
{
struct V_1 * V_5 = NULL , * V_6 ;
struct V_7 * V_8 ;
V_4 = F_2 ( V_4 ) ;
if ( V_4 > V_3 -> V_4 ) {
F_3 ( V_9 L_1
L_2 ) ;
return NULL ;
}
F_4 ( & V_3 -> V_10 ) ;
F_5 (pos, &vm->unused) {
V_6 = F_6 ( V_8 , struct V_1 , V_11 ) ;
if ( V_6 -> V_4 >= V_4 )
break;
}
if ( V_8 == & V_3 -> V_12 )
goto V_13;
if ( V_6 -> V_4 == V_4 ) {
F_7 ( & V_6 -> V_11 , & V_3 -> V_14 ) ;
V_3 -> V_4 -= V_4 ;
V_5 = V_6 ;
goto V_13;
}
V_5 = F_8 ( sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 )
goto V_13;
V_5 -> V_16 = V_6 -> V_16 ;
V_5 -> V_4 = V_4 ;
F_9 ( & V_5 -> V_11 , & V_3 -> V_14 ) ;
V_6 -> V_16 += V_4 ;
V_6 -> V_4 -= V_4 ;
V_3 -> V_4 -= V_4 ;
V_13:
F_10 ( & V_3 -> V_10 ) ;
return V_5 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
struct V_1 * V_6 , * V_17 ;
struct V_7 * V_8 , * V_18 ;
V_5 -> V_4 = F_2 ( V_5 -> V_4 ) ;
F_4 ( & V_3 -> V_10 ) ;
F_12 ( & V_5 -> V_11 ) ;
V_3 -> V_4 += V_5 -> V_4 ;
F_5 (pos, &vm->unused) {
V_6 = F_6 ( V_8 , struct V_1 , V_11 ) ;
if ( V_6 -> V_16 >= ( V_5 -> V_16 + V_5 -> V_4 ) )
break;
}
if ( V_8 == & V_3 -> V_12 ) {
F_13 ( & V_5 -> V_11 , & V_3 -> V_12 ) ;
V_6 = V_5 ;
} else {
if ( ( V_5 -> V_16 + V_5 -> V_4 ) == V_6 -> V_16 ) {
V_6 -> V_16 = V_5 -> V_16 ;
V_6 -> V_4 += V_5 -> V_4 ;
F_14 ( V_5 ) ;
} else {
F_15 ( & V_5 -> V_11 , V_8 -> V_19 , V_8 ) ;
V_6 = V_5 ;
}
}
V_8 = & V_6 -> V_11 ;
V_18 = V_8 -> V_19 ;
while ( V_18 != & V_3 -> V_12 ) {
V_6 = F_6 ( V_8 , struct V_1 , V_11 ) ;
V_17 = F_6 ( V_18 , struct V_1 , V_11 ) ;
if ( ( V_17 -> V_16 + V_17 -> V_4 ) > V_6 -> V_16 )
break;
V_17 -> V_4 += V_6 -> V_4 ;
F_12 ( V_8 ) ;
F_14 ( V_6 ) ;
V_8 = V_18 ;
V_18 = V_8 -> V_19 ;
}
F_10 ( & V_3 -> V_10 ) ;
}
static struct V_1 *
F_16 ( struct V_2 * V_3 , struct V_20 * V_21 , int V_4 )
{
struct V_1 * V_5 ;
unsigned int V_22 ;
unsigned V_23 , V_24 ;
unsigned long * V_25 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL ) {
F_3 ( V_9 L_3
L_4 ) ;
return NULL ;
}
V_25 = ( unsigned long * ) V_3 -> V_25 [ 0 ] . V_26 ;
V_22 = ( V_5 -> V_16 >> V_27 ) ;
V_24 = V_5 -> V_4 >> V_27 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
unsigned long V_16 ;
V_16 = F_17 ( V_21 , V_23 << V_27 ) ;
V_25 [ V_22 + V_23 ] = V_16 ;
}
V_5 -> V_4 = V_4 ;
return V_5 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
F_11 ( V_3 , V_5 ) ;
}
static T_1
F_19 ( struct V_2 * V_3 , int V_28 )
{
T_1 V_16 ;
V_16 = ( V_28 >= V_29 ) ? ~ 0UL : V_3 -> V_25 [ V_28 ] . V_16 ;
return V_16 ;
}
int F_20 ( struct V_2 * * V_30 , struct V_31 * V_32 )
{
struct V_2 * V_3 ;
struct V_1 * V_5 ;
int V_23 , V_33 = 0 ;
* V_30 = NULL ;
V_3 = F_8 ( sizeof( * V_3 ) , V_15 ) ;
if ( ! V_3 )
return - V_34 ;
F_21 ( & V_3 -> V_10 ) ;
for ( V_23 = 0 ; V_23 < V_29 ; V_23 ++ ) {
V_33 = F_22 ( V_35 ,
F_23 ( V_32 ) ,
V_36 , & V_3 -> V_25 [ V_23 ] ) ;
if ( V_33 < 0 )
break;
}
if ( V_33 < 0 ) {
F_24 ( V_3 ) ;
return - V_34 ;
}
V_3 -> V_4 = V_37 * V_23 ;
V_3 -> V_38 = F_16 ;
V_3 -> V_39 = F_18 ;
V_3 -> V_40 = F_19 ;
F_25 ( & V_3 -> V_12 ) ;
F_25 ( & V_3 -> V_14 ) ;
V_5 = F_8 ( sizeof( * V_5 ) , V_15 ) ;
if ( NULL != V_5 ) {
V_5 -> V_16 = 0 ;
V_5 -> V_4 = V_3 -> V_4 ;
F_9 ( & V_5 -> V_11 , & V_3 -> V_12 ) ;
}
* V_30 = V_3 ;
return 0 ;
}
void F_24 ( struct V_2 * V_3 )
{
int V_23 ;
struct V_7 * V_8 ;
struct V_1 * V_6 ;
while ( ! F_26 ( & V_3 -> V_14 ) ) {
V_8 = V_3 -> V_14 . V_41 ;
F_12 ( V_8 ) ;
V_6 = F_6 ( V_8 , struct V_1 , V_11 ) ;
F_14 ( V_6 ) ;
}
while ( ! F_26 ( & V_3 -> V_12 ) ) {
V_8 = V_3 -> V_12 . V_41 ;
F_12 ( V_8 ) ;
V_6 = F_6 ( V_8 , struct V_1 , V_11 ) ;
F_14 ( V_6 ) ;
}
for ( V_23 = 0 ; V_23 < V_29 ; V_23 ++ )
F_27 ( & V_3 -> V_25 [ V_23 ] ) ;
V_3 -> V_4 = 0 ;
F_14 ( V_3 ) ;
}
