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
F_2 ( 1 , L_1 , V_4 ) ;
break;
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
F_2 ( 1 , L_1 , V_4 ) ;
break;
}
return - 1 ;
}
int F_4 ( struct V_6 * V_7 )
{
const struct V_8 * V_9 = V_7 -> V_10 ;
T_3 V_11 ;
V_11 = V_9 -> V_12 * V_9 -> V_13 ;
F_5 ( & V_7 -> V_14 ) ;
F_6 ( V_7 -> V_15 , L_2 ,
V_7 -> V_16 ) ;
if ( V_9 -> V_17 )
V_7 -> V_18 = F_7 ( V_9 -> V_17 ,
V_11 , V_19 ) ;
else
V_7 -> V_18 = F_8 ( V_11 , V_19 ) ;
if ( ! V_7 -> V_18 )
return - V_20 ;
return 0 ;
}
int F_9 ( struct V_6 * V_7 )
{
F_6 ( V_7 -> V_15 , L_3 ,
V_7 -> V_16 ) ;
F_10 ( V_7 -> V_18 ) ;
V_7 -> V_18 = NULL ;
return 0 ;
}
int F_11 ( struct V_6 * V_7 ,
unsigned int V_21 , unsigned int * V_22 )
{
if ( ! V_22 )
return - V_23 ;
F_12 ( & V_7 -> V_14 ) ;
if ( ! F_13 ( V_7 -> V_18 ) )
* V_22 = F_3 ( V_7 -> V_18 , V_21 ,
V_7 -> V_10 -> V_13 ) ;
F_14 ( & V_7 -> V_14 ) ;
return 0 ;
}
int F_15 ( struct V_6 * V_7 ,
unsigned int V_21 , unsigned int V_22 )
{
F_12 ( & V_7 -> V_14 ) ;
if ( ! F_13 ( V_7 -> V_18 ) )
F_1 ( V_7 -> V_18 , V_21 , V_22 ,
V_7 -> V_10 -> V_13 ) ;
F_14 ( & V_7 -> V_14 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
int V_24 ;
int V_25 ;
const struct V_8 * V_9 ;
unsigned int V_3 ;
V_9 = V_7 -> V_10 ;
for ( V_24 = 0 ; V_24 < V_9 -> V_12 ; ++ V_24 ) {
V_25 = F_11 ( V_7 , V_24 , & V_3 ) ;
if ( V_25 )
return V_25 ;
if ( V_9 -> V_17 )
if ( F_3 ( V_9 -> V_17 ,
V_24 , V_9 -> V_13 ) == V_3 )
continue;
F_17 ( ! F_18 ( V_7 , V_24 ) ) ;
V_25 = F_19 ( V_7 , V_24 , V_3 ) ;
if ( V_25 )
return V_25 ;
F_6 ( V_7 -> V_15 , L_4 ,
V_24 , V_3 ) ;
}
return 0 ;
}
int F_20 ( struct V_6 * V_7 )
{
const char * V_16 = L_5 ;
int V_25 ;
if ( ! V_7 -> V_26 )
return 0 ;
F_6 ( V_7 -> V_15 , L_6 ,
V_7 -> V_16 ) ;
F_21 ( V_7 , V_16 , L_7 ) ;
V_25 = F_16 ( V_7 ) ;
if ( ! V_25 )
V_7 -> V_26 = 0 ;
F_21 ( V_7 , V_16 , L_8 ) ;
return V_25 ;
}
