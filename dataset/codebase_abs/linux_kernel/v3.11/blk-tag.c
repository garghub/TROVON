struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
return F_2 ( V_3 -> V_5 , V_4 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_4 ( & V_7 -> V_9 ) ;
if ( V_8 ) {
F_5 ( F_6 ( V_7 -> V_10 , V_7 -> V_11 ) <
V_7 -> V_11 ) ;
F_7 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
F_7 ( V_7 -> V_10 ) ;
V_7 -> V_10 = NULL ;
F_7 ( V_7 ) ;
}
return V_8 ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
if ( ! V_7 )
return;
F_3 ( V_7 ) ;
V_3 -> V_5 = NULL ;
F_9 ( V_13 , V_3 ) ;
}
void F_10 ( struct V_6 * V_7 )
{
if ( F_11 ( ! F_3 ( V_7 ) ) )
F_12 () ;
}
void F_13 ( struct V_2 * V_3 )
{
F_9 ( V_13 , V_3 ) ;
}
static int
F_14 ( struct V_2 * V_3 , struct V_6 * V_14 , int V_15 )
{
struct V_1 * * V_12 ;
unsigned long * V_10 ;
int V_16 ;
if ( V_3 && V_15 > V_3 -> V_17 * 2 ) {
V_15 = V_3 -> V_17 * 2 ;
F_15 ( V_18 L_1 ,
V_19 , V_15 ) ;
}
V_12 = F_16 ( V_15 * sizeof( struct V_1 * ) , V_20 ) ;
if ( ! V_12 )
goto V_21;
V_16 = F_17 ( V_15 , V_22 ) / V_22 ;
V_10 = F_16 ( V_16 * sizeof( unsigned long ) , V_20 ) ;
if ( ! V_10 )
goto V_21;
V_14 -> V_23 = V_15 ;
V_14 -> V_11 = V_15 ;
V_14 -> V_12 = V_12 ;
V_14 -> V_10 = V_10 ;
return 0 ;
V_21:
F_7 ( V_12 ) ;
return - V_24 ;
}
static struct V_6 * F_18 ( struct V_2 * V_3 ,
int V_15 )
{
struct V_6 * V_14 ;
V_14 = F_19 ( sizeof( struct V_6 ) , V_20 ) ;
if ( ! V_14 )
goto V_21;
if ( F_14 ( V_3 , V_14 , V_15 ) )
goto V_21;
F_20 ( & V_14 -> V_9 , 1 ) ;
return V_14 ;
V_21:
F_7 ( V_14 ) ;
return NULL ;
}
struct V_6 * F_21 ( int V_15 )
{
return F_18 ( NULL , V_15 ) ;
}
int F_22 ( struct V_2 * V_3 , int V_15 ,
struct V_6 * V_14 )
{
int V_25 ;
F_5 ( V_14 && V_3 -> V_5 && V_14 != V_3 -> V_5 ) ;
if ( ! V_14 && ! V_3 -> V_5 ) {
V_14 = F_18 ( V_3 , V_15 ) ;
if ( ! V_14 )
return - V_24 ;
} else if ( V_3 -> V_5 ) {
V_25 = F_23 ( V_3 , V_15 ) ;
if ( V_25 )
return V_25 ;
F_24 ( V_13 , V_3 ) ;
return 0 ;
} else
F_25 ( & V_14 -> V_9 ) ;
V_3 -> V_5 = V_14 ;
F_26 ( V_13 , V_3 ) ;
F_27 ( & V_3 -> V_26 ) ;
return 0 ;
}
int F_23 ( struct V_2 * V_3 , int V_27 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
struct V_1 * * V_12 ;
unsigned long * V_10 ;
int V_11 , V_16 ;
if ( ! V_7 )
return - V_28 ;
if ( V_27 <= V_7 -> V_23 ) {
V_7 -> V_11 = V_27 ;
return 0 ;
}
if ( F_28 ( & V_7 -> V_9 ) != 1 )
return - V_29 ;
V_12 = V_7 -> V_12 ;
V_10 = V_7 -> V_10 ;
V_11 = V_7 -> V_23 ;
if ( F_14 ( V_3 , V_7 , V_27 ) )
return - V_24 ;
memcpy ( V_7 -> V_12 , V_12 , V_11 * sizeof( struct V_1 * ) ) ;
V_16 = F_17 ( V_11 , V_22 ) / V_22 ;
memcpy ( V_7 -> V_10 , V_10 , V_16 * sizeof( unsigned long ) ) ;
F_7 ( V_12 ) ;
F_7 ( V_10 ) ;
return 0 ;
}
void F_29 ( struct V_2 * V_3 , struct V_1 * V_30 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
unsigned V_4 = V_30 -> V_4 ;
F_5 ( V_4 >= V_7 -> V_23 ) ;
F_30 ( & V_30 -> V_31 ) ;
V_30 -> V_32 &= ~ V_33 ;
V_30 -> V_4 = - 1 ;
if ( F_11 ( V_7 -> V_12 [ V_4 ] == NULL ) )
F_15 ( V_18 L_2 ,
V_19 , V_4 ) ;
V_7 -> V_12 [ V_4 ] = NULL ;
if ( F_11 ( ! F_31 ( V_4 , V_7 -> V_10 ) ) ) {
F_15 ( V_18 L_3 ,
V_19 , V_4 ) ;
return;
}
F_32 ( V_4 , V_7 -> V_10 ) ;
}
int F_33 ( struct V_2 * V_3 , struct V_1 * V_30 )
{
struct V_6 * V_7 = V_3 -> V_5 ;
unsigned V_11 ;
int V_4 ;
if ( F_11 ( ( V_30 -> V_32 & V_33 ) ) ) {
F_15 ( V_18
L_4 ,
V_19 , V_30 ,
V_30 -> V_34 ? V_30 -> V_34 -> V_35 : L_5 , V_30 -> V_4 ) ;
F_12 () ;
}
V_11 = V_7 -> V_11 ;
if ( ! F_34 ( V_30 ) && V_11 > 1 ) {
switch ( V_11 ) {
case 2 :
V_11 = 1 ;
break;
case 3 :
V_11 = 2 ;
break;
default:
V_11 -= 2 ;
}
if ( V_3 -> V_36 [ V_37 ] > V_11 )
return 1 ;
}
do {
V_4 = F_35 ( V_7 -> V_10 , V_11 ) ;
if ( V_4 >= V_11 )
return 1 ;
} while ( F_36 ( V_4 , V_7 -> V_10 ) );
V_30 -> V_32 |= V_33 ;
V_30 -> V_4 = V_4 ;
V_7 -> V_12 [ V_4 ] = V_30 ;
F_37 ( V_30 ) ;
F_38 ( & V_30 -> V_31 , & V_3 -> V_26 ) ;
return 0 ;
}
void F_39 ( struct V_2 * V_3 )
{
struct V_38 * V_39 , * V_40 ;
F_40 (tmp, n, &q->tag_busy_list)
F_41 ( V_3 , F_42 ( V_39 ) ) ;
}
