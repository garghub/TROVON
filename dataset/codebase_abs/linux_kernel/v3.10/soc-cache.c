static bool F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
switch ( V_4 ) {
case 1 : {
T_1 * V_5 = V_1 ;
if ( V_5 [ V_2 ] == V_3 )
return true ;
V_5 [ V_2 ] = V_3 ;
break;
}
case 2 : {
T_2 * V_5 = V_1 ;
if ( V_5 [ V_2 ] == V_3 )
return true ;
V_5 [ V_2 ] = V_3 ;
break;
}
default:
F_2 () ;
}
return false ;
}
static unsigned int F_3 ( const void * V_1 , unsigned int V_2 ,
unsigned int V_4 )
{
if ( ! V_1 )
return - 1 ;
switch ( V_4 ) {
case 1 : {
const T_1 * V_5 = V_1 ;
return V_5 [ V_2 ] ;
}
case 2 : {
const T_2 * V_5 = V_1 ;
return V_5 [ V_2 ] ;
}
default:
F_2 () ;
}
return - 1 ;
}
static int F_4 ( struct V_6 * V_7 )
{
int V_8 ;
int V_9 ;
const struct V_10 * V_11 ;
unsigned int V_3 ;
V_11 = V_7 -> V_12 ;
for ( V_8 = 0 ; V_8 < V_11 -> V_13 ; ++ V_8 ) {
V_9 = F_5 ( V_7 , V_8 , & V_3 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_14 )
if ( F_3 ( V_7 -> V_14 ,
V_8 , V_11 -> V_15 ) == V_3 )
continue;
F_6 ( ! F_7 ( V_7 , V_8 ) ) ;
V_9 = F_8 ( V_7 , V_8 , V_3 ) ;
if ( V_9 )
return V_9 ;
F_9 ( V_7 -> V_16 , L_1 ,
V_8 , V_3 ) ;
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_18 )
{
F_1 ( V_7 -> V_19 , V_17 , V_18 ,
V_7 -> V_12 -> V_15 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 ,
unsigned int V_17 , unsigned int * V_18 )
{
* V_18 = F_3 ( V_7 -> V_19 , V_17 ,
V_7 -> V_12 -> V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_19 )
return 0 ;
F_13 ( V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
if ( V_7 -> V_14 )
V_7 -> V_19 = F_15 ( V_7 -> V_14 ,
V_7 -> V_20 , V_21 ) ;
else
V_7 -> V_19 = F_16 ( V_7 -> V_20 , V_21 ) ;
if ( ! V_7 -> V_19 )
return - V_22 ;
return 0 ;
}
int F_17 ( struct V_6 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_18 ( V_23 ) ; ++ V_8 )
if ( V_23 [ V_8 ] . V_24 == V_7 -> V_25 )
break;
if ( V_8 == F_18 ( V_23 ) ) {
F_19 ( V_7 -> V_16 , L_2 ,
V_7 -> V_25 ) ;
V_8 = 0 ;
}
F_20 ( & V_7 -> V_26 ) ;
V_7 -> V_27 = & V_23 [ V_8 ] ;
if ( V_7 -> V_27 -> V_28 ) {
if ( V_7 -> V_27 -> V_29 )
F_9 ( V_7 -> V_16 , L_3 ,
V_7 -> V_27 -> V_29 , V_7 -> V_29 ) ;
return V_7 -> V_27 -> V_28 ( V_7 ) ;
}
return - V_30 ;
}
int F_21 ( struct V_6 * V_7 )
{
if ( V_7 -> V_27 && V_7 -> V_27 -> exit ) {
if ( V_7 -> V_27 -> V_29 )
F_9 ( V_7 -> V_16 , L_4 ,
V_7 -> V_27 -> V_29 , V_7 -> V_29 ) ;
return V_7 -> V_27 -> exit ( V_7 ) ;
}
return - V_30 ;
}
int F_5 ( struct V_6 * V_7 ,
unsigned int V_17 , unsigned int * V_18 )
{
int V_9 ;
F_22 ( & V_7 -> V_26 ) ;
if ( V_18 && V_7 -> V_27 && V_7 -> V_27 -> V_31 ) {
V_9 = V_7 -> V_27 -> V_31 ( V_7 , V_17 , V_18 ) ;
F_23 ( & V_7 -> V_26 ) ;
return V_9 ;
}
F_23 ( & V_7 -> V_26 ) ;
return - V_30 ;
}
int F_24 ( struct V_6 * V_7 ,
unsigned int V_17 , unsigned int V_18 )
{
int V_9 ;
F_22 ( & V_7 -> V_26 ) ;
if ( V_7 -> V_27 && V_7 -> V_27 -> V_32 ) {
V_9 = V_7 -> V_27 -> V_32 ( V_7 , V_17 , V_18 ) ;
F_23 ( & V_7 -> V_26 ) ;
return V_9 ;
}
F_23 ( & V_7 -> V_26 ) ;
return - V_30 ;
}
int F_25 ( struct V_6 * V_7 )
{
int V_9 ;
const char * V_29 ;
if ( ! V_7 -> V_33 ) {
return 0 ;
}
if ( ! V_7 -> V_27 || ! V_7 -> V_27 -> V_34 )
return - V_30 ;
if ( V_7 -> V_27 -> V_29 )
V_29 = V_7 -> V_27 -> V_29 ;
else
V_29 = L_5 ;
if ( V_7 -> V_27 -> V_29 )
F_9 ( V_7 -> V_16 , L_6 ,
V_7 -> V_27 -> V_29 , V_7 -> V_29 ) ;
F_26 ( V_7 , V_29 , L_7 ) ;
V_9 = V_7 -> V_27 -> V_34 ( V_7 ) ;
if ( ! V_9 )
V_7 -> V_33 = 0 ;
F_26 ( V_7 , V_29 , L_8 ) ;
return V_9 ;
}
static int F_27 ( struct V_6 * V_7 ,
unsigned int V_17 )
{
const struct V_10 * V_11 ;
unsigned int V_35 , V_36 , V_37 ;
V_11 = V_7 -> V_12 ;
V_35 = 0 ;
V_36 = V_11 -> V_38 - 1 ;
do {
V_37 = ( V_35 + V_36 ) / 2 ;
if ( V_11 -> V_39 [ V_37 ] . V_17 == V_17 )
return V_37 ;
if ( V_11 -> V_39 [ V_37 ] . V_17 < V_17 )
V_35 = V_37 + 1 ;
else
V_36 = V_37 ;
} while ( V_35 <= V_36 );
return - 1 ;
}
int F_28 ( struct V_6 * V_7 ,
unsigned int V_17 )
{
int V_37 ;
if ( V_17 >= V_7 -> V_12 -> V_13 )
return 1 ;
V_37 = F_27 ( V_7 , V_17 ) ;
if ( V_37 < 0 )
return 0 ;
return V_7 -> V_12 -> V_39 [ V_37 ] . V_40 ;
}
int F_29 ( struct V_6 * V_7 ,
unsigned int V_17 )
{
int V_37 ;
if ( V_17 >= V_7 -> V_12 -> V_13 )
return 1 ;
V_37 = F_27 ( V_7 , V_17 ) ;
if ( V_37 < 0 )
return 0 ;
return V_7 -> V_12 -> V_39 [ V_37 ] . V_31 ;
}
int F_30 ( struct V_6 * V_7 ,
unsigned int V_17 )
{
int V_37 ;
if ( V_17 >= V_7 -> V_12 -> V_13 )
return 1 ;
V_37 = F_27 ( V_7 , V_17 ) ;
if ( V_37 < 0 )
return 0 ;
return V_7 -> V_12 -> V_39 [ V_37 ] . V_32 ;
}
