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
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( V_3 -> V_8 [ V_6 ] == V_9 ) {
V_3 -> V_8 [ V_6 ] = V_2 ;
return V_6 ;
}
}
return - V_10 ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_13 ,
T_1 V_14 )
{
V_3 -> V_15 ( V_14 - V_16 , V_3 -> V_8 [ V_14 - V_16 ] ) ;
return 0 ;
}
static void F_9 ( struct V_11 * V_12 , unsigned int V_13 )
{
T_1 V_14 = F_10 ( V_13 ) -> V_17 ;
if ( V_14 > V_16 )
V_3 -> V_8 [ V_14 - V_16 ] = V_9 ;
}
static int F_11 ( struct V_11 * V_12 ,
struct V_18 * V_19 ,
const T_2 * V_20 , unsigned int V_21 ,
unsigned long * V_22 ,
unsigned int * V_23 )
{
unsigned long V_24 ;
V_24 = F_7 ( V_20 [ 1 ] ) ;
if ( F_12 ( V_24 ) )
return V_24 ;
* V_22 = V_24 + V_16 ;
return 0 ;
}
static int T_3 F_13 ( struct V_18 * V_25 )
{
int V_6 , V_26 , V_27 , V_28 = 0 , V_29 ;
const T_4 * V_30 ;
V_3 = F_14 ( sizeof( * V_3 ) , V_31 ) ;
if ( ! V_3 )
return - V_32 ;
V_3 -> V_4 = F_15 ( V_25 , 0 ) ;
if ( ! V_3 -> V_4 )
goto V_33;
F_16 ( V_25 , L_1 , & V_27 ) ;
V_3 -> V_8 = F_14 ( V_27 * sizeof( int ) , V_31 ) ;
if ( ! V_3 -> V_8 )
goto V_34;
V_3 -> V_7 = V_27 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ )
V_3 -> V_8 [ V_6 ] = V_9 ;
V_30 = F_17 ( V_25 , L_2 , & V_26 ) ;
if ( V_30 ) {
V_26 /= sizeof( T_4 ) ;
for ( V_6 = 0 ; V_6 < V_26 ; V_6 ++ ) {
F_18 ( V_25 ,
L_2 ,
V_6 , & V_29 ) ;
if ( V_29 > V_27 ) {
F_19 ( L_3 ) ;
goto V_35;
}
V_3 -> V_8 [ V_29 ] = 0 ;
}
}
V_3 -> V_5 = F_14 ( V_27 * sizeof( int ) , V_31 ) ;
if ( ! V_3 -> V_5 )
goto V_35;
F_16 ( V_25 , L_4 , & V_26 ) ;
switch ( V_26 ) {
case 1 :
V_3 -> V_15 = F_5 ;
break;
case 2 :
V_3 -> V_15 = F_3 ;
break;
case 4 :
V_3 -> V_15 = F_1 ;
break;
default:
F_19 ( L_5 ) ;
goto V_36;
break;
}
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
if ( ! V_3 -> V_8 [ V_6 ] )
continue;
V_3 -> V_5 [ V_6 ] = V_28 ;
V_28 += V_26 ;
}
F_20 ( & V_37 ) ;
return 0 ;
V_36:
F_21 ( V_3 -> V_5 ) ;
V_35:
F_21 ( V_3 -> V_8 ) ;
V_34:
F_22 ( V_3 -> V_4 ) ;
V_33:
F_21 ( V_3 ) ;
return - V_32 ;
}
int T_3 F_23 ( void )
{
struct V_18 * V_38 ;
V_38 = F_24 ( NULL , V_39 ) ;
if ( ! V_38 )
return - V_10 ;
F_13 ( V_38 ) ;
return 0 ;
}
