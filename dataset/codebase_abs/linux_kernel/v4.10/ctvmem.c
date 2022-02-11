static struct V_1 *
F_1 ( struct V_2 * V_3 , unsigned int V_4 , struct V_5 * V_6 )
{
struct V_1 * V_7 = NULL , * V_8 ;
struct V_9 * V_10 ;
V_4 = F_2 ( V_4 ) ;
if ( V_4 > V_3 -> V_4 ) {
F_3 ( V_6 -> V_11 -> V_12 ,
L_1 ) ;
return NULL ;
}
F_4 ( & V_3 -> V_13 ) ;
F_5 (pos, &vm->unused) {
V_8 = F_6 ( V_10 , struct V_1 , V_14 ) ;
if ( V_8 -> V_4 >= V_4 )
break;
}
if ( V_10 == & V_3 -> V_15 )
goto V_16;
if ( V_8 -> V_4 == V_4 ) {
F_7 ( & V_8 -> V_14 , & V_3 -> V_17 ) ;
V_3 -> V_4 -= V_4 ;
V_7 = V_8 ;
goto V_16;
}
V_7 = F_8 ( sizeof( * V_7 ) , V_18 ) ;
if ( ! V_7 )
goto V_16;
V_7 -> V_19 = V_8 -> V_19 ;
V_7 -> V_4 = V_4 ;
F_9 ( & V_7 -> V_14 , & V_3 -> V_17 ) ;
V_8 -> V_19 += V_4 ;
V_8 -> V_4 -= V_4 ;
V_3 -> V_4 -= V_4 ;
V_16:
F_10 ( & V_3 -> V_13 ) ;
return V_7 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_1 * V_8 , * V_20 ;
struct V_9 * V_10 , * V_21 ;
V_7 -> V_4 = F_2 ( V_7 -> V_4 ) ;
F_4 ( & V_3 -> V_13 ) ;
F_12 ( & V_7 -> V_14 ) ;
V_3 -> V_4 += V_7 -> V_4 ;
F_5 (pos, &vm->unused) {
V_8 = F_6 ( V_10 , struct V_1 , V_14 ) ;
if ( V_8 -> V_19 >= ( V_7 -> V_19 + V_7 -> V_4 ) )
break;
}
if ( V_10 == & V_3 -> V_15 ) {
F_13 ( & V_7 -> V_14 , & V_3 -> V_15 ) ;
V_8 = V_7 ;
} else {
if ( ( V_7 -> V_19 + V_7 -> V_4 ) == V_8 -> V_19 ) {
V_8 -> V_19 = V_7 -> V_19 ;
V_8 -> V_4 += V_7 -> V_4 ;
F_14 ( V_7 ) ;
} else {
F_15 ( & V_7 -> V_14 , V_10 -> V_22 , V_10 ) ;
V_8 = V_7 ;
}
}
V_10 = & V_8 -> V_14 ;
V_21 = V_10 -> V_22 ;
while ( V_21 != & V_3 -> V_15 ) {
V_8 = F_6 ( V_10 , struct V_1 , V_14 ) ;
V_20 = F_6 ( V_21 , struct V_1 , V_14 ) ;
if ( ( V_20 -> V_19 + V_20 -> V_4 ) > V_8 -> V_19 )
break;
V_20 -> V_4 += V_8 -> V_4 ;
F_12 ( V_10 ) ;
F_14 ( V_8 ) ;
V_10 = V_21 ;
V_21 = V_10 -> V_22 ;
}
F_10 ( & V_3 -> V_13 ) ;
}
static struct V_1 *
F_16 ( struct V_2 * V_3 , struct V_23 * V_24 , int V_4 )
{
struct V_1 * V_7 ;
unsigned int V_25 ;
unsigned V_26 , V_27 ;
unsigned long * V_28 ;
struct V_5 * V_6 = F_17 ( V_24 ) ;
V_7 = F_1 ( V_3 , V_4 , V_6 ) ;
if ( V_7 == NULL ) {
F_3 ( V_6 -> V_11 -> V_12 ,
L_2 ) ;
return NULL ;
}
V_28 = ( unsigned long * ) V_3 -> V_28 [ 0 ] . V_29 ;
V_25 = ( V_7 -> V_19 >> V_30 ) ;
V_27 = V_7 -> V_4 >> V_30 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
unsigned long V_19 ;
V_19 = F_18 ( V_24 , V_26 << V_30 ) ;
V_28 [ V_25 + V_26 ] = V_19 ;
}
V_7 -> V_4 = V_4 ;
return V_7 ;
}
static void F_19 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
F_11 ( V_3 , V_7 ) ;
}
static T_1
F_20 ( struct V_2 * V_3 , int V_31 )
{
return ( V_31 >= V_32 ) ? ~ 0UL : V_3 -> V_28 [ V_31 ] . V_19 ;
}
int F_21 ( struct V_2 * * V_33 , struct V_34 * V_35 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
int V_26 , V_36 = 0 ;
* V_33 = NULL ;
V_3 = F_8 ( sizeof( * V_3 ) , V_18 ) ;
if ( ! V_3 )
return - V_37 ;
F_22 ( & V_3 -> V_13 ) ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ ) {
V_36 = F_23 ( V_38 ,
F_24 ( V_35 ) ,
V_39 , & V_3 -> V_28 [ V_26 ] ) ;
if ( V_36 < 0 )
break;
}
if ( V_36 < 0 ) {
F_25 ( V_3 ) ;
return - V_37 ;
}
V_3 -> V_4 = V_40 * V_26 ;
V_3 -> V_41 = F_16 ;
V_3 -> V_42 = F_19 ;
V_3 -> V_43 = F_20 ;
F_26 ( & V_3 -> V_15 ) ;
F_26 ( & V_3 -> V_17 ) ;
V_7 = F_8 ( sizeof( * V_7 ) , V_18 ) ;
if ( NULL != V_7 ) {
V_7 -> V_19 = 0 ;
V_7 -> V_4 = V_3 -> V_4 ;
F_9 ( & V_7 -> V_14 , & V_3 -> V_15 ) ;
}
* V_33 = V_3 ;
return 0 ;
}
void F_25 ( struct V_2 * V_3 )
{
int V_26 ;
struct V_9 * V_10 ;
struct V_1 * V_8 ;
while ( ! F_27 ( & V_3 -> V_17 ) ) {
V_10 = V_3 -> V_17 . V_44 ;
F_12 ( V_10 ) ;
V_8 = F_6 ( V_10 , struct V_1 , V_14 ) ;
F_14 ( V_8 ) ;
}
while ( ! F_27 ( & V_3 -> V_15 ) ) {
V_10 = V_3 -> V_15 . V_44 ;
F_12 ( V_10 ) ;
V_8 = F_6 ( V_10 , struct V_1 , V_14 ) ;
F_14 ( V_8 ) ;
}
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ )
F_28 ( & V_3 -> V_28 [ V_26 ] ) ;
V_3 -> V_4 = 0 ;
F_14 ( V_3 ) ;
}
