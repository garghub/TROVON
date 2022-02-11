static int
F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_3 = V_5 -> V_7 - V_5 -> V_8 ;
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 , V_10 ;
if ( V_3 > V_5 -> V_7 - V_5 -> V_8 )
return - V_11 ;
V_9 = V_5 -> V_12 -> V_13 [ V_5 -> V_7 - V_3 ] ;
V_10 = F_3 ( V_9 , V_5 ) ;
return F_4 ( V_5 -> V_14 , V_10 ) ;
}
static int
F_5 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_9 ;
int V_15 ;
V_9 = F_6 ( V_5 -> V_14 -> V_16 . V_17 , V_5 ) ;
for ( V_15 = V_5 -> V_8 ; V_15 < V_5 -> V_7 ; V_15 ++ ) {
if ( V_9 <= V_5 -> V_12 -> V_13 [ V_15 ] )
break;
}
* V_3 = V_5 -> V_7 - V_15 ;
return 0 ;
}
static int F_7 ( int * V_18 , int V_19 , int V_20 )
{
int V_21 ;
for ( V_21 = 2 ; V_21 < V_19 ; V_21 ++ ) {
if ( V_18 [ V_21 ] == V_20 )
break;
}
return V_21 == V_19 ? - V_22 : V_21 ;
}
static void F_8 ( struct V_4 * V_5 )
{
T_1 V_23 ;
unsigned long long V_8 , V_7 ;
V_23 = F_9 ( V_5 -> V_24 , L_1 , NULL , & V_8 ) ;
if ( F_10 ( V_23 ) )
V_5 -> V_8 = F_7 ( V_5 -> V_12 -> V_13 ,
V_5 -> V_12 -> V_25 , V_8 ) ;
V_23 = F_9 ( V_5 -> V_24 , L_2 , NULL , & V_7 ) ;
if ( F_10 ( V_23 ) )
V_5 -> V_7 = F_7 ( V_5 -> V_12 -> V_13 ,
V_5 -> V_12 -> V_25 , V_7 ) ;
V_5 -> V_8 = V_5 -> V_8 > 0 ? V_5 -> V_8 : 2 ;
V_5 -> V_7 = V_5 -> V_7 > 0 ? V_5 -> V_7 : V_5 -> V_12 -> V_25 - 1 ;
}
static void F_11 ( T_2 V_24 , T_3 V_26 , void * V_27 )
{
if ( V_26 == V_28 )
F_8 ( V_27 ) ;
}
static int F_12 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_13 ( & V_30 -> V_33 ) ;
struct V_4 * V_5 ;
struct V_34 * V_35 ;
int V_36 ;
if ( ! F_14 ( & V_30 -> V_33 ) )
return - V_37 ;
V_5 = F_15 ( & V_30 -> V_33 , sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return - V_39 ;
V_5 -> V_24 = F_14 ( & V_30 -> V_33 ) ;
V_35 = F_16 ( V_40 ) ;
if ( ! V_35 )
return - V_37 ;
V_5 -> V_14 = V_35 ;
V_36 = F_17 ( F_13 ( & V_30 -> V_33 ) , & V_5 -> V_12 , NULL ) ;
if ( V_36 )
return V_36 ;
F_8 ( V_5 ) ;
V_5 -> V_2 = F_18 ( F_19 ( V_32 ) ,
V_5 , & V_41 ) ;
if ( F_20 ( V_5 -> V_2 ) )
goto V_42;
V_36 = F_21 ( V_32 -> V_24 , V_43 ,
F_11 , V_5 ) ;
if ( V_36 )
goto V_44;
F_22 ( V_30 , V_5 ) ;
return 0 ;
V_44:
F_23 ( V_5 -> V_2 ) ;
V_42:
F_24 ( V_5 -> V_12 ) ;
return - V_37 ;
}
static int F_25 ( struct V_29 * V_30 )
{
struct V_4 * V_5 = F_26 ( V_30 ) ;
F_23 ( V_5 -> V_2 ) ;
F_24 ( V_5 -> V_12 ) ;
return 0 ;
}
