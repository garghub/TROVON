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
struct V_10 args ;
int V_11 ;
int V_12 ;
F_8 ( & V_3 -> V_13 ) ;
for ( V_11 = V_3 -> V_14 - 1 ; V_11 >= 0 ; V_11 -- ) {
if ( V_3 -> V_15 [ V_11 ] == V_16 ) {
V_3 -> V_15 [ V_11 ] = V_9 ;
break;
}
}
F_9 ( & V_3 -> V_13 ) ;
if ( V_11 < 0 )
return - V_17 ;
args . V_18 = V_7 -> V_19 -> V_20 ;
args . V_21 = 3 ;
args . args [ 0 ] = 0 ;
args . args [ 1 ] = V_11 ;
args . args [ 2 ] = V_22 ;
V_12 = F_10 ( V_7 , V_8 , 1 , & args ) ;
if ( V_12 )
V_3 -> V_15 [ V_11 ] = V_16 ;
else
V_3 -> V_23 ( V_11 , V_9 ) ;
return V_12 ;
}
static int F_11 ( struct V_6 * V_24 , unsigned int V_8 ,
unsigned int V_25 , void * V_26 )
{
struct V_10 * args = V_26 ;
T_1 V_9 ;
int V_11 ;
if ( args -> V_21 != 3 )
return - V_27 ;
if ( args -> args [ 0 ] != 0 )
return - V_27 ;
V_9 = args -> args [ 1 ] ;
if ( ( V_9 + V_25 ) > V_3 -> V_28 )
return - V_27 ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
int V_12 = F_7 ( V_24 , V_8 + V_11 , V_9 + V_11 ) ;
if ( V_12 )
return V_12 ;
F_12 ( V_24 , V_8 + V_11 , V_9 + V_11 ,
& V_29 , NULL ) ;
}
return 0 ;
}
static void F_13 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned int V_25 )
{
int V_11 ;
F_8 ( & V_3 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_25 ; V_11 ++ ) {
struct V_30 * V_24 = F_14 ( V_7 , V_8 + V_11 ) ;
F_15 ( V_24 ) ;
V_3 -> V_15 [ V_24 -> V_9 ] = V_16 ;
V_3 -> V_23 ( V_24 -> V_9 , V_3 -> V_31 ) ;
}
F_9 ( & V_3 -> V_13 ) ;
}
static int F_16 ( struct V_6 * V_24 ,
struct V_32 * V_33 ,
const T_2 * V_34 , unsigned int V_35 ,
unsigned long * V_36 ,
unsigned int * V_37 )
{
if ( V_24 -> V_20 != V_33 )
return - V_27 ;
if ( V_35 != 3 )
return - V_27 ;
if ( V_34 [ 0 ] != 0 )
return - V_27 ;
* V_36 = V_34 [ 1 ] ;
* V_37 = V_34 [ 2 ] ;
return 0 ;
}
static int T_3 F_17 ( struct V_32 * V_38 )
{
int V_11 , V_39 , V_40 = 0 , V_41 = 0 , V_42 ;
const T_4 * V_43 ;
int V_44 = - V_45 ;
V_3 = F_18 ( sizeof( * V_3 ) , V_46 ) ;
if ( ! V_3 )
return V_44 ;
V_3 -> V_4 = F_19 ( V_38 , 0 ) ;
if ( ! V_3 -> V_4 )
goto V_47;
F_20 ( V_38 , L_1 ,
& V_3 -> V_28 ) ;
if ( ! V_3 -> V_28 ) {
F_21 ( L_2 ) ;
V_44 = - V_27 ;
goto V_48;
}
F_20 ( V_38 , L_3 , & V_40 ) ;
if ( ! V_40 ) {
F_21 ( L_4 ) ;
V_44 = - V_27 ;
goto V_48;
}
V_3 -> V_15 = F_22 ( V_40 , sizeof( int ) , V_46 ) ;
if ( ! V_3 -> V_15 )
goto V_48;
V_3 -> V_14 = V_40 ;
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ )
V_3 -> V_15 [ V_11 ] = V_16 ;
V_43 = F_23 ( V_38 , L_5 , & V_39 ) ;
if ( V_43 ) {
V_39 /= sizeof( T_4 ) ;
for ( V_11 = 0 ; V_11 < V_39 ; V_11 ++ ) {
F_24 ( V_38 ,
L_5 ,
V_11 , & V_42 ) ;
if ( V_42 >= V_40 ) {
F_21 ( L_6 ) ;
V_44 = - V_27 ;
goto V_49;
}
V_3 -> V_15 [ V_42 ] = V_50 ;
}
}
V_43 = F_23 ( V_38 , L_7 , & V_39 ) ;
if ( V_43 ) {
V_39 /= sizeof( T_4 ) ;
for ( V_11 = 0 ; V_11 < V_39 ; V_11 ++ ) {
F_24 ( V_38 ,
L_7 ,
V_11 , & V_42 ) ;
if ( V_42 >= V_40 ) {
F_21 ( L_8 ) ;
V_44 = - V_27 ;
goto V_49;
}
V_3 -> V_15 [ V_42 ] = V_51 ;
}
}
V_3 -> V_5 = F_22 ( V_40 , sizeof( int ) , V_46 ) ;
if ( ! V_3 -> V_5 )
goto V_49;
F_20 ( V_38 , L_9 , & V_39 ) ;
switch ( V_39 ) {
case 1 :
V_3 -> V_23 = F_5 ;
break;
case 2 :
V_3 -> V_23 = F_3 ;
break;
case 4 :
V_3 -> V_23 = F_1 ;
break;
default:
F_21 ( L_10 ) ;
V_44 = - V_27 ;
goto V_52;
break;
}
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ ) {
if ( V_3 -> V_15 [ V_11 ] == V_50 )
continue;
V_3 -> V_5 [ V_11 ] = V_41 ;
V_41 += V_39 ;
}
F_20 ( V_38 , L_11 , & V_3 -> V_31 ) ;
for ( V_11 = 0 ; V_11 < V_40 ; V_11 ++ ) {
if ( V_3 -> V_15 [ V_11 ] == V_50 ||
V_3 -> V_15 [ V_11 ] == V_51 )
continue;
V_3 -> V_23 ( V_11 , V_3 -> V_31 ) ;
}
F_25 ( & V_3 -> V_13 ) ;
return 0 ;
V_52:
F_26 ( V_3 -> V_5 ) ;
V_49:
F_26 ( V_3 -> V_15 ) ;
V_48:
F_27 ( V_3 -> V_4 ) ;
V_47:
F_26 ( V_3 ) ;
V_3 = NULL ;
return V_44 ;
}
static int T_3 F_28 ( struct V_32 * V_38 ,
struct V_32 * V_19 )
{
struct V_6 * V_53 , * V_7 ;
int V_12 ;
if ( ! V_19 ) {
F_21 ( L_12 , V_38 -> V_54 ) ;
return - V_17 ;
}
V_53 = F_29 ( V_19 ) ;
if ( ! V_53 ) {
F_21 ( L_13 , V_38 -> V_54 ) ;
return - V_55 ;
}
V_12 = F_17 ( V_38 ) ;
if ( V_12 )
return V_12 ;
V_7 = F_30 ( V_53 , 0 ,
V_3 -> V_28 ,
V_38 , & V_56 ,
NULL ) ;
if ( ! V_7 ) {
F_21 ( L_14 , V_38 -> V_54 ) ;
return - V_45 ;
}
return 0 ;
}
