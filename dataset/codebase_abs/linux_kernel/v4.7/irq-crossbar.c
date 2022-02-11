static void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_3 -> V_4 + V_3 -> V_5 [ V_1 ] ) ;
}
static void F_3 ( int V_1 , int V_2 )
{
F_4 ( V_2 , V_3 -> V_4 + V_3 -> V_5 [ V_1 ] ) ;
}
static void F_5 ( int V_1 , int V_2 )
{
F_6 ( V_2 , V_3 -> V_4 + V_3 -> V_5 [ V_1 ] ) ;
}
static int F_7 ( struct V_6 * V_7 , unsigned V_8 ,
T_1 V_9 )
{
struct V_10 V_11 ;
int V_12 ;
int V_13 ;
if ( ! F_8 ( V_7 -> V_14 ) )
return - V_15 ;
F_9 ( & V_3 -> V_16 ) ;
for ( V_12 = V_3 -> V_17 - 1 ; V_12 >= 0 ; V_12 -- ) {
if ( V_3 -> V_18 [ V_12 ] == V_19 ) {
V_3 -> V_18 [ V_12 ] = V_9 ;
break;
}
}
F_10 ( & V_3 -> V_16 ) ;
if ( V_12 < 0 )
return - V_20 ;
V_11 . V_21 = V_7 -> V_14 -> V_21 ;
V_11 . V_22 = 3 ;
V_11 . V_23 [ 0 ] = 0 ;
V_11 . V_23 [ 1 ] = V_12 ;
V_11 . V_23 [ 2 ] = V_24 ;
V_13 = F_11 ( V_7 , V_8 , 1 , & V_11 ) ;
if ( V_13 )
V_3 -> V_18 [ V_12 ] = V_19 ;
else
V_3 -> V_25 ( V_12 , V_9 ) ;
return V_13 ;
}
static int F_12 ( struct V_6 * V_26 , unsigned int V_8 ,
unsigned int V_27 , void * V_28 )
{
struct V_10 * V_11 = V_28 ;
T_1 V_9 ;
int V_12 ;
if ( V_11 -> V_22 != 3 )
return - V_15 ;
if ( V_11 -> V_23 [ 0 ] != 0 )
return - V_15 ;
V_9 = V_11 -> V_23 [ 1 ] ;
if ( ( V_9 + V_27 ) > V_3 -> V_29 )
return - V_15 ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
int V_13 = F_7 ( V_26 , V_8 + V_12 , V_9 + V_12 ) ;
if ( V_13 )
return V_13 ;
F_13 ( V_26 , V_8 + V_12 , V_9 + V_12 ,
& V_30 , NULL ) ;
}
return 0 ;
}
static void F_14 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned int V_27 )
{
int V_12 ;
F_9 ( & V_3 -> V_16 ) ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
struct V_31 * V_26 = F_15 ( V_7 , V_8 + V_12 ) ;
F_16 ( V_26 ) ;
V_3 -> V_18 [ V_26 -> V_9 ] = V_19 ;
V_3 -> V_25 ( V_26 -> V_9 , V_3 -> V_32 ) ;
}
F_10 ( & V_3 -> V_16 ) ;
}
static int F_17 ( struct V_6 * V_26 ,
struct V_10 * V_11 ,
unsigned long * V_9 ,
unsigned int * type )
{
if ( F_18 ( V_11 -> V_21 ) ) {
if ( V_11 -> V_22 != 3 )
return - V_15 ;
if ( V_11 -> V_23 [ 0 ] != 0 )
return - V_15 ;
* V_9 = V_11 -> V_23 [ 1 ] ;
* type = V_11 -> V_23 [ 2 ] & V_33 ;
return 0 ;
}
return - V_15 ;
}
static int T_2 F_19 ( struct V_34 * V_35 )
{
int V_12 , V_36 , V_37 = 0 , V_38 = 0 , V_39 ;
const T_3 * V_40 ;
int V_41 = - V_42 ;
V_3 = F_20 ( sizeof( * V_3 ) , V_43 ) ;
if ( ! V_3 )
return V_41 ;
V_3 -> V_4 = F_21 ( V_35 , 0 ) ;
if ( ! V_3 -> V_4 )
goto V_44;
F_22 ( V_35 , L_1 ,
& V_3 -> V_29 ) ;
if ( ! V_3 -> V_29 ) {
F_23 ( L_2 ) ;
V_41 = - V_15 ;
goto V_45;
}
F_22 ( V_35 , L_3 , & V_37 ) ;
if ( ! V_37 ) {
F_23 ( L_4 ) ;
V_41 = - V_15 ;
goto V_45;
}
V_3 -> V_18 = F_24 ( V_37 , sizeof( int ) , V_43 ) ;
if ( ! V_3 -> V_18 )
goto V_45;
V_3 -> V_17 = V_37 ;
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ )
V_3 -> V_18 [ V_12 ] = V_19 ;
V_40 = F_25 ( V_35 , L_5 , & V_36 ) ;
if ( V_40 ) {
V_36 /= sizeof( T_3 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ ) {
F_26 ( V_35 ,
L_5 ,
V_12 , & V_39 ) ;
if ( V_39 >= V_37 ) {
F_23 ( L_6 ) ;
V_41 = - V_15 ;
goto V_46;
}
V_3 -> V_18 [ V_39 ] = V_47 ;
}
}
V_40 = F_25 ( V_35 , L_7 , & V_36 ) ;
if ( V_40 ) {
V_36 /= sizeof( T_3 ) ;
for ( V_12 = 0 ; V_12 < V_36 ; V_12 ++ ) {
F_26 ( V_35 ,
L_7 ,
V_12 , & V_39 ) ;
if ( V_39 >= V_37 ) {
F_23 ( L_8 ) ;
V_41 = - V_15 ;
goto V_46;
}
V_3 -> V_18 [ V_39 ] = V_48 ;
}
}
V_3 -> V_5 = F_24 ( V_37 , sizeof( int ) , V_43 ) ;
if ( ! V_3 -> V_5 )
goto V_46;
F_22 ( V_35 , L_9 , & V_36 ) ;
switch ( V_36 ) {
case 1 :
V_3 -> V_25 = F_5 ;
break;
case 2 :
V_3 -> V_25 = F_3 ;
break;
case 4 :
V_3 -> V_25 = F_1 ;
break;
default:
F_23 ( L_10 ) ;
V_41 = - V_15 ;
goto V_49;
break;
}
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ ) {
if ( V_3 -> V_18 [ V_12 ] == V_47 )
continue;
V_3 -> V_5 [ V_12 ] = V_38 ;
V_38 += V_36 ;
}
F_22 ( V_35 , L_11 , & V_3 -> V_32 ) ;
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ ) {
if ( V_3 -> V_18 [ V_12 ] == V_47 ||
V_3 -> V_18 [ V_12 ] == V_48 )
continue;
V_3 -> V_25 ( V_12 , V_3 -> V_32 ) ;
}
F_27 ( & V_3 -> V_16 ) ;
return 0 ;
V_49:
F_28 ( V_3 -> V_5 ) ;
V_46:
F_28 ( V_3 -> V_18 ) ;
V_45:
F_29 ( V_3 -> V_4 ) ;
V_44:
F_28 ( V_3 ) ;
V_3 = NULL ;
return V_41 ;
}
static int T_2 F_30 ( struct V_34 * V_35 ,
struct V_34 * V_14 )
{
struct V_6 * V_50 , * V_7 ;
int V_13 ;
if ( ! V_14 ) {
F_23 ( L_12 , V_35 -> V_51 ) ;
return - V_20 ;
}
V_50 = F_31 ( V_14 ) ;
if ( ! V_50 ) {
F_23 ( L_13 , V_35 -> V_51 ) ;
return - V_52 ;
}
V_13 = F_19 ( V_35 ) ;
if ( V_13 )
return V_13 ;
V_7 = F_32 ( V_50 , 0 ,
V_3 -> V_29 ,
V_35 , & V_53 ,
NULL ) ;
if ( ! V_7 ) {
F_23 ( L_14 , V_35 -> V_51 ) ;
return - V_42 ;
}
return 0 ;
}
