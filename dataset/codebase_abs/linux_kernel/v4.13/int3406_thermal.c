static int F_1 ( int V_1 , struct V_2 * V_3 )
{
int V_4 = V_3 -> V_5 -> V_6 [ V_3 -> V_5 -> V_7 - 1 ] ;
int V_8 = V_3 -> V_9 -> V_10 . V_11 ;
return V_1 * V_8 / V_4 ;
}
static int F_2 ( int V_1 , struct V_2 * V_3 )
{
int V_8 = V_3 -> V_9 -> V_10 . V_11 ;
int V_4 = V_3 -> V_5 -> V_6 [ V_3 -> V_5 -> V_7 - 1 ] ;
return V_1 * V_4 / V_8 ;
}
static int
F_3 ( struct V_12 * V_13 ,
unsigned long * V_14 )
{
struct V_2 * V_3 = V_13 -> V_15 ;
int V_16 = V_3 -> V_17 ? V_3 -> V_17 : 2 ;
* V_14 = V_3 -> V_5 -> V_7 - 1 - V_16 ;
return 0 ;
}
static int
F_4 ( struct V_12 * V_13 ,
unsigned long V_14 )
{
struct V_2 * V_3 = V_13 -> V_15 ;
int V_1 , V_18 ;
if ( V_14 > V_3 -> V_5 -> V_7 - 3 )
return - V_19 ;
V_14 = V_3 -> V_5 -> V_7 - 1 - V_14 ;
V_1 = V_3 -> V_5 -> V_6 [ V_14 ] ;
if ( ( V_3 -> V_20 && V_1 > V_3 -> V_20 ) ||
( V_3 -> V_21 && V_1 < V_3 -> V_21 ) )
return - V_19 ;
V_18 = F_1 ( V_1 , V_3 ) ;
return F_5 ( V_3 -> V_9 , V_18 ) ;
}
static int
F_6 ( struct V_12 * V_13 ,
unsigned long * V_14 )
{
struct V_2 * V_3 = V_13 -> V_15 ;
int V_18 , V_1 , V_22 ;
int * V_6 = V_3 -> V_5 -> V_6 ;
V_18 = V_3 -> V_9 -> V_10 . V_23 ;
V_1 = F_2 ( V_18 , V_3 ) ;
for ( V_22 = 2 ; V_22 < V_3 -> V_5 -> V_7 ; V_22 ++ ) {
if ( V_1 < V_6 [ V_22 ] ) {
if ( V_22 == 2 )
break;
if ( ( V_1 - V_6 [ V_22 - 1 ] ) < ( V_6 [ V_22 ] - V_1 ) )
V_22 -- ;
break;
}
}
* V_14 = V_3 -> V_5 -> V_7 - 1 - V_22 ;
return 0 ;
}
static int F_7 ( int * V_24 , int V_25 , int V_26 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
if ( V_24 [ V_22 ] == V_26 )
break;
}
return V_22 == V_25 ? - V_27 : V_22 ;
}
static void F_8 ( struct V_2 * V_3 )
{
T_1 V_28 ;
unsigned long long V_21 , V_20 ;
int V_16 ;
V_28 = F_9 ( V_3 -> V_29 , L_1 , NULL , & V_21 ) ;
if ( F_10 ( V_28 ) ) {
V_16 = F_7 ( V_3 -> V_5 -> V_6 , V_3 -> V_5 -> V_7 ,
V_21 ) ;
if ( V_16 > 0 ) {
V_3 -> V_21 = ( int ) V_21 ;
V_3 -> V_17 = V_16 ;
}
}
V_28 = F_9 ( V_3 -> V_29 , L_2 , NULL , & V_20 ) ;
if ( F_10 ( V_28 ) ) {
V_16 = F_7 ( V_3 -> V_5 -> V_6 , V_3 -> V_5 -> V_7 ,
V_20 ) ;
if ( V_16 > 0 ) {
V_3 -> V_20 = ( int ) V_20 ;
V_3 -> V_30 = V_16 ;
}
}
}
static void F_11 ( T_2 V_29 , T_3 V_31 , void * V_32 )
{
if ( V_31 == V_33 )
F_8 ( V_32 ) ;
}
static int F_12 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_13 ( & V_35 -> V_38 ) ;
struct V_2 * V_3 ;
struct V_39 * V_40 ;
int V_41 ;
if ( ! F_14 ( & V_35 -> V_38 ) )
return - V_42 ;
V_3 = F_15 ( & V_35 -> V_38 , sizeof( * V_3 ) , V_43 ) ;
if ( ! V_3 )
return - V_44 ;
V_3 -> V_29 = F_14 ( & V_35 -> V_38 ) ;
V_40 = F_16 ( V_45 ) ;
if ( ! V_40 )
return - V_42 ;
V_3 -> V_9 = V_40 ;
V_41 = F_17 ( F_13 ( & V_35 -> V_38 ) , & V_3 -> V_5 , NULL ) ;
if ( V_41 )
return V_41 ;
F_8 ( V_3 ) ;
V_3 -> V_13 = F_18 ( F_19 ( V_37 ) ,
V_3 , & V_46 ) ;
if ( F_20 ( V_3 -> V_13 ) )
goto V_47;
V_41 = F_21 ( V_37 -> V_29 , V_48 ,
F_11 , V_3 ) ;
if ( V_41 )
goto V_49;
F_22 ( V_35 , V_3 ) ;
return 0 ;
V_49:
F_23 ( V_3 -> V_13 ) ;
V_47:
F_24 ( V_3 -> V_5 ) ;
return - V_42 ;
}
static int F_25 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = F_26 ( V_35 ) ;
F_23 ( V_3 -> V_13 ) ;
F_24 ( V_3 -> V_5 ) ;
return 0 ;
}
