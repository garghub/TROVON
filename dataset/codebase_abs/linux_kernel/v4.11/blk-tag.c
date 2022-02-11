struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
return F_2 ( V_3 -> V_5 , V_4 ) ;
}
void F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( & V_7 -> V_8 ) ) {
F_5 ( F_6 ( V_7 -> V_9 , V_7 -> V_10 ) <
V_7 -> V_10 ) ;
F_7 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
F_7 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
F_7 ( V_7 ) ;
}
}
void F_8 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
if ( ! V_7 )
return;
F_3 ( V_7 ) ;
V_3 -> V_5 = NULL ;
F_9 ( V_12 , V_3 ) ;
}
void F_10 ( struct V_2 * V_3 )
{
F_9 ( V_12 , V_3 ) ;
}
static int
F_11 ( struct V_2 * V_3 , struct V_6 * V_13 , int V_14 )
{
struct V_1 * * V_11 ;
unsigned long * V_9 ;
int V_15 ;
if ( V_3 && V_14 > V_3 -> V_16 * 2 ) {
V_14 = V_3 -> V_16 * 2 ;
F_12 ( V_17 L_1 ,
V_18 , V_14 ) ;
}
V_11 = F_13 ( V_14 * sizeof( struct V_1 * ) , V_19 ) ;
if ( ! V_11 )
goto V_20;
V_15 = F_14 ( V_14 , V_21 ) / V_21 ;
V_9 = F_13 ( V_15 * sizeof( unsigned long ) , V_19 ) ;
if ( ! V_9 )
goto V_20;
V_13 -> V_22 = V_14 ;
V_13 -> V_10 = V_14 ;
V_13 -> V_11 = V_11 ;
V_13 -> V_9 = V_9 ;
return 0 ;
V_20:
F_7 ( V_11 ) ;
return - V_23 ;
}
static struct V_6 * F_15 ( struct V_2 * V_3 ,
int V_14 , int V_24 )
{
struct V_6 * V_13 ;
V_13 = F_16 ( sizeof( struct V_6 ) , V_19 ) ;
if ( ! V_13 )
goto V_20;
if ( F_11 ( V_3 , V_13 , V_14 ) )
goto V_20;
F_17 ( & V_13 -> V_8 , 1 ) ;
V_13 -> V_24 = V_24 ;
V_13 -> V_25 = 0 ;
return V_13 ;
V_20:
F_7 ( V_13 ) ;
return NULL ;
}
struct V_6 * F_18 ( int V_14 , int V_24 )
{
return F_15 ( NULL , V_14 , V_24 ) ;
}
int F_19 ( struct V_2 * V_3 , int V_14 ,
struct V_6 * V_13 , int V_24 )
{
int V_26 ;
F_5 ( V_13 && V_3 -> V_5 && V_13 != V_3 -> V_5 ) ;
if ( ! V_13 && ! V_3 -> V_5 ) {
V_13 = F_15 ( V_3 , V_14 , V_24 ) ;
if ( ! V_13 )
return - V_23 ;
} else if ( V_3 -> V_5 ) {
V_26 = F_20 ( V_3 , V_14 ) ;
if ( V_26 )
return V_26 ;
F_21 ( V_12 , V_3 ) ;
return 0 ;
} else
F_22 ( & V_13 -> V_8 ) ;
V_3 -> V_5 = V_13 ;
F_23 ( V_12 , V_3 ) ;
F_24 ( & V_3 -> V_27 ) ;
return 0 ;
}
int F_20 ( struct V_2 * V_3 , int V_28 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
struct V_1 * * V_11 ;
unsigned long * V_9 ;
int V_10 , V_15 ;
if ( ! V_7 )
return - V_29 ;
if ( V_28 <= V_7 -> V_22 ) {
V_7 -> V_10 = V_28 ;
return 0 ;
}
if ( F_25 ( & V_7 -> V_8 ) != 1 )
return - V_30 ;
V_11 = V_7 -> V_11 ;
V_9 = V_7 -> V_9 ;
V_10 = V_7 -> V_22 ;
if ( F_11 ( V_3 , V_7 , V_28 ) )
return - V_23 ;
memcpy ( V_7 -> V_11 , V_11 , V_10 * sizeof( struct V_1 * ) ) ;
V_15 = F_14 ( V_10 , V_21 ) / V_21 ;
memcpy ( V_7 -> V_9 , V_9 , V_15 * sizeof( unsigned long ) ) ;
F_7 ( V_11 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 , struct V_1 * V_31 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
unsigned V_4 = V_31 -> V_4 ;
F_5 ( V_4 >= V_7 -> V_22 ) ;
F_27 ( & V_31 -> V_32 ) ;
V_31 -> V_33 &= ~ V_34 ;
V_31 -> V_4 = - 1 ;
V_31 -> V_35 = - 1 ;
if ( F_28 ( V_7 -> V_11 [ V_4 ] == NULL ) )
F_12 ( V_17 L_2 ,
V_18 , V_4 ) ;
V_7 -> V_11 [ V_4 ] = NULL ;
if ( F_28 ( ! F_29 ( V_4 , V_7 -> V_9 ) ) ) {
F_12 ( V_17 L_3 ,
V_18 , V_4 ) ;
return;
}
F_30 ( V_4 , V_7 -> V_9 ) ;
}
int F_31 ( struct V_2 * V_3 , struct V_1 * V_31 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
unsigned V_10 ;
int V_4 ;
if ( F_28 ( ( V_31 -> V_33 & V_34 ) ) ) {
F_12 ( V_17
L_4 ,
V_18 , V_31 ,
V_31 -> V_36 ? V_31 -> V_36 -> V_37 : L_5 , V_31 -> V_4 ) ;
F_32 () ;
}
V_10 = V_7 -> V_10 ;
if ( ! F_33 ( V_31 ) && V_10 > 1 ) {
switch ( V_10 ) {
case 2 :
V_10 = 1 ;
break;
case 3 :
V_10 = 2 ;
break;
default:
V_10 -= 2 ;
}
if ( V_3 -> V_38 [ V_39 ] > V_10 )
return 1 ;
}
do {
if ( V_7 -> V_24 == V_40 ) {
V_4 = F_34 ( V_7 -> V_9 , V_10 ) ;
if ( V_4 >= V_10 )
return 1 ;
} else {
int V_41 = V_7 -> V_25 ;
int V_42 = F_35 ( int , V_7 -> V_10 , V_10 + V_41 ) ;
V_4 = F_36 ( V_7 -> V_9 , V_42 , V_41 ) ;
if ( V_4 >= V_42 && V_41 + V_42 > V_7 -> V_10 ) {
V_42 = V_41 + V_42 - V_7 -> V_10 ;
V_4 = F_34 ( V_7 -> V_9 , V_42 ) ;
}
if ( V_4 >= V_42 )
return 1 ;
}
} while ( F_37 ( V_4 , V_7 -> V_9 ) );
V_7 -> V_25 = ( V_4 + 1 ) % V_7 -> V_10 ;
V_31 -> V_33 |= V_34 ;
V_31 -> V_4 = V_4 ;
V_7 -> V_11 [ V_4 ] = V_31 ;
F_38 ( V_31 ) ;
F_39 ( & V_31 -> V_32 , & V_3 -> V_27 ) ;
return 0 ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_43 * V_44 , * V_45 ;
F_41 (tmp, n, &q->tag_busy_list)
F_42 ( V_3 , F_43 ( V_44 ) ) ;
}
