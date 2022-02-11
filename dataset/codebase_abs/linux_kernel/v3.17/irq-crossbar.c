static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_3 -> V_4 + V_3 -> V_5 [ V_1 ] ) ;
}
static inline void F_3 ( int V_1 , int V_2 )
{
F_4 ( V_2 , V_3 -> V_4 + V_3 -> V_5 [ V_1 ] ) ;
}
static inline void F_5 ( int V_1 , int V_2 )
{
F_6 ( V_2 , V_3 -> V_4 + V_3 -> V_5 [ V_1 ] ) ;
}
static inline int F_7 ( int V_2 )
{
int V_6 ;
for ( V_6 = V_3 -> V_7 - 1 ; V_6 >= 0 ; V_6 -- )
if ( V_3 -> V_8 [ V_6 ] == V_2 )
return V_6 ;
return - V_9 ;
}
static inline int F_8 ( int V_2 )
{
int V_6 ;
for ( V_6 = V_3 -> V_7 - 1 ; V_6 >= 0 ; V_6 -- ) {
if ( V_3 -> V_8 [ V_6 ] == V_10 ) {
V_3 -> V_8 [ V_6 ] = V_2 ;
return V_6 ;
}
}
return - V_9 ;
}
static inline bool F_9 ( T_1 V_11 )
{
int V_2 ;
if ( V_11 > V_12 ) {
V_2 = V_3 -> V_8 [ V_11 - V_12 ] ;
if ( V_2 != V_13 && V_2 != V_14 )
return true ;
}
return false ;
}
static int F_10 ( struct V_15 * V_16 , unsigned int V_17 ,
T_1 V_11 )
{
if ( F_9 ( V_11 ) )
V_3 -> V_18 ( V_11 - V_12 , V_3 -> V_8 [ V_11 - V_12 ] ) ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 , unsigned int V_17 )
{
T_1 V_11 = F_12 ( V_17 ) -> V_19 ;
if ( F_9 ( V_11 ) ) {
V_3 -> V_8 [ V_11 - V_12 ] = V_10 ;
V_3 -> V_18 ( V_11 - V_12 , V_3 -> V_20 ) ;
}
}
static int F_13 ( struct V_15 * V_16 ,
struct V_21 * V_22 ,
const T_2 * V_23 , unsigned int V_24 ,
unsigned long * V_25 ,
unsigned int * V_26 )
{
int V_27 ;
int V_28 = V_23 [ 1 ] ;
int V_29 ;
if ( V_28 >= V_3 -> V_30 ) {
V_29 = V_28 - V_3 -> V_30 ;
if ( V_29 < V_3 -> V_7 ) {
V_27 = V_3 -> V_8 [ V_29 ] ;
if ( V_27 == V_13 || V_27 == V_14 ) {
V_27 = V_29 ;
goto V_31;
}
}
F_14 ( L_1 ,
V_32 , V_28 , V_3 -> V_30 ) ;
return - V_33 ;
}
V_27 = F_7 ( V_28 ) ;
if ( V_27 >= 0 )
goto V_31;
V_27 = F_8 ( V_28 ) ;
if ( V_27 < 0 )
return V_27 ;
V_31:
* V_25 = V_27 + V_12 ;
return 0 ;
}
static int T_3 F_15 ( struct V_21 * V_34 )
{
int V_6 , V_35 , V_36 = 0 , V_37 = 0 , V_38 ;
const T_4 * V_39 ;
int V_27 = - V_40 ;
V_3 = F_16 ( sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 )
return V_27 ;
V_3 -> V_4 = F_17 ( V_34 , 0 ) ;
if ( ! V_3 -> V_4 )
goto V_42;
F_18 ( V_34 , L_2 ,
& V_3 -> V_30 ) ;
if ( ! V_3 -> V_30 ) {
F_14 ( L_3 ) ;
V_27 = - V_33 ;
goto V_43;
}
F_18 ( V_34 , L_4 , & V_36 ) ;
if ( ! V_36 ) {
F_14 ( L_5 ) ;
V_27 = - V_33 ;
goto V_43;
}
V_3 -> V_8 = F_19 ( V_36 , sizeof( int ) , V_41 ) ;
if ( ! V_3 -> V_8 )
goto V_43;
V_3 -> V_7 = V_36 ;
for ( V_6 = 0 ; V_6 < V_36 ; V_6 ++ )
V_3 -> V_8 [ V_6 ] = V_10 ;
V_39 = F_20 ( V_34 , L_6 , & V_35 ) ;
if ( V_39 ) {
V_35 /= sizeof( T_4 ) ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ ) {
F_21 ( V_34 ,
L_6 ,
V_6 , & V_38 ) ;
if ( V_38 >= V_36 ) {
F_14 ( L_7 ) ;
V_27 = - V_33 ;
goto V_44;
}
V_3 -> V_8 [ V_38 ] = V_13 ;
}
}
V_39 = F_20 ( V_34 , L_8 , & V_35 ) ;
if ( V_39 ) {
V_35 /= sizeof( T_4 ) ;
for ( V_6 = 0 ; V_6 < V_35 ; V_6 ++ ) {
F_21 ( V_34 ,
L_8 ,
V_6 , & V_38 ) ;
if ( V_38 >= V_36 ) {
F_14 ( L_9 ) ;
V_27 = - V_33 ;
goto V_44;
}
V_3 -> V_8 [ V_38 ] = V_14 ;
}
}
V_3 -> V_5 = F_19 ( V_36 , sizeof( int ) , V_41 ) ;
if ( ! V_3 -> V_5 )
goto V_44;
F_18 ( V_34 , L_10 , & V_35 ) ;
switch ( V_35 ) {
case 1 :
V_3 -> V_18 = F_5 ;
break;
case 2 :
V_3 -> V_18 = F_3 ;
break;
case 4 :
V_3 -> V_18 = F_1 ;
break;
default:
F_14 ( L_11 ) ;
V_27 = - V_33 ;
goto V_45;
break;
}
for ( V_6 = 0 ; V_6 < V_36 ; V_6 ++ ) {
if ( V_3 -> V_8 [ V_6 ] == V_13 )
continue;
V_3 -> V_5 [ V_6 ] = V_37 ;
V_37 += V_35 ;
}
F_18 ( V_34 , L_12 , & V_3 -> V_20 ) ;
for ( V_6 = 0 ; V_6 < V_36 ; V_6 ++ ) {
if ( V_3 -> V_8 [ V_6 ] == V_13 ||
V_3 -> V_8 [ V_6 ] == V_14 )
continue;
V_3 -> V_18 ( V_6 , V_3 -> V_20 ) ;
}
F_22 ( & V_46 ) ;
return 0 ;
V_45:
F_23 ( V_3 -> V_5 ) ;
V_44:
F_23 ( V_3 -> V_8 ) ;
V_43:
F_24 ( V_3 -> V_4 ) ;
V_42:
F_23 ( V_3 ) ;
V_3 = NULL ;
return V_27 ;
}
int T_3 F_25 ( void )
{
struct V_21 * V_47 ;
V_47 = F_26 ( NULL , V_48 ) ;
if ( ! V_47 )
return - V_9 ;
F_15 ( V_47 ) ;
return 0 ;
}
