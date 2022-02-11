void F_1 ( struct V_1 * V_2 ,
int (* F_2)( void * V_3 ) ,
int (* F_3)( void * V_3 ) ,
int (* F_4)( void * V_3 ) ,
int (* F_5)( void * V_3 ) ,
int (* F_6)( void * V_3 ) , void * V_3 )
{
V_2 -> F_2 = F_2 ;
V_2 -> F_3 = F_3 ;
V_2 -> F_4 = F_4 ;
V_2 -> F_5 = F_5 ;
V_2 -> F_6 = F_6 ;
V_2 -> V_4 = V_3 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_6 , void * V_7 )
{
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = V_7 ;
if ( ! V_2 -> V_8 ) {
F_8 ( & V_2 -> V_9 ) ;
V_2 -> V_8 = true ;
}
V_2 -> V_10 = 0 ;
if ( V_2 -> F_5 )
V_2 -> F_5 ( V_2 -> V_4 ) ;
V_2 -> V_11 = 0 ;
if ( V_2 -> F_6 )
V_2 -> F_6 ( V_2 -> V_4 ) ;
V_2 -> V_12 = 0 ;
}
void F_9 ( struct V_1 * V_2 )
__acquires( &commonring->lock
void F_10 ( struct V_1 * V_2 )
__releases( &commonring->lock
bool F_11 ( struct V_1 * V_2 )
{
T_1 V_13 ;
bool V_14 = true ;
V_15:
if ( V_2 -> V_10 <= V_2 -> V_11 )
V_13 = V_2 -> V_5 - V_2 -> V_11 +
V_2 -> V_10 ;
else
V_13 = V_2 -> V_10 - V_2 -> V_11 ;
if ( V_13 > 1 ) {
if ( ! V_2 -> V_16 )
return true ;
if ( V_13 > V_2 -> V_5 / 8 ) {
V_2 -> V_16 = false ;
return true ;
}
if ( V_14 ) {
if ( V_2 -> F_3 )
V_2 -> F_3 ( V_2 -> V_4 ) ;
V_14 = false ;
goto V_15;
}
return false ;
}
if ( V_14 ) {
if ( V_2 -> F_3 )
V_2 -> F_3 ( V_2 -> V_4 ) ;
V_14 = false ;
goto V_15;
}
V_2 -> V_16 = true ;
return false ;
}
void * F_12 ( struct V_1 * V_2 )
{
void * V_17 ;
T_1 V_13 ;
bool V_14 = true ;
V_15:
if ( V_2 -> V_10 <= V_2 -> V_11 )
V_13 = V_2 -> V_5 - V_2 -> V_11 +
V_2 -> V_10 ;
else
V_13 = V_2 -> V_10 - V_2 -> V_11 ;
if ( V_13 > 1 ) {
V_17 = V_2 -> V_7 +
( V_2 -> V_11 * V_2 -> V_6 ) ;
V_2 -> V_11 ++ ;
if ( V_2 -> V_11 == V_2 -> V_5 )
V_2 -> V_11 = 0 ;
return V_17 ;
}
if ( V_14 ) {
if ( V_2 -> F_3 )
V_2 -> F_3 ( V_2 -> V_4 ) ;
V_14 = false ;
goto V_15;
}
V_2 -> V_16 = true ;
return NULL ;
}
void *
F_13 ( struct V_1 * V_2 ,
T_1 V_18 , T_1 * V_19 )
{
void * V_17 ;
T_1 V_13 ;
bool V_14 = true ;
V_15:
if ( V_2 -> V_10 <= V_2 -> V_11 )
V_13 = V_2 -> V_5 - V_2 -> V_11 +
V_2 -> V_10 ;
else
V_13 = V_2 -> V_10 - V_2 -> V_11 ;
if ( V_13 > 1 ) {
V_17 = V_2 -> V_7 +
( V_2 -> V_11 * V_2 -> V_6 ) ;
* V_19 = F_14 ( T_1 , V_18 , V_13 - 1 ) ;
if ( * V_19 + V_2 -> V_11 > V_2 -> V_5 )
* V_19 = V_2 -> V_5 - V_2 -> V_11 ;
V_2 -> V_11 += * V_19 ;
if ( V_2 -> V_11 == V_2 -> V_5 )
V_2 -> V_11 = 0 ;
return V_17 ;
}
if ( V_14 ) {
if ( V_2 -> F_3 )
V_2 -> F_3 ( V_2 -> V_4 ) ;
V_14 = false ;
goto V_15;
}
V_2 -> V_16 = true ;
return NULL ;
}
int F_15 ( struct V_1 * V_2 )
{
void * V_20 ;
V_20 = V_2 -> V_7 ;
V_20 += ( V_2 -> V_12 * V_2 -> V_6 ) ;
if ( V_2 -> V_12 > V_2 -> V_11 ) {
V_20 = V_2 -> V_7 ;
V_2 -> V_12 = 0 ;
}
V_2 -> V_12 = V_2 -> V_11 ;
if ( V_2 -> F_6 )
V_2 -> F_6 ( V_2 -> V_4 ) ;
if ( V_2 -> F_2 )
return V_2 -> F_2 ( V_2 -> V_4 ) ;
return - V_21 ;
}
void F_16 ( struct V_1 * V_2 ,
T_1 V_18 )
{
if ( V_2 -> V_11 == 0 )
V_2 -> V_11 = V_2 -> V_5 - V_18 ;
else
V_2 -> V_11 -= V_18 ;
}
void * F_17 ( struct V_1 * V_2 ,
T_1 * V_18 )
{
if ( V_2 -> F_4 )
V_2 -> F_4 ( V_2 -> V_4 ) ;
* V_18 = ( V_2 -> V_11 >= V_2 -> V_10 ) ?
( V_2 -> V_11 - V_2 -> V_10 ) :
( V_2 -> V_5 - V_2 -> V_10 ) ;
if ( * V_18 == 0 )
return NULL ;
return V_2 -> V_7 +
( V_2 -> V_10 * V_2 -> V_6 ) ;
}
int F_18 ( struct V_1 * V_2 ,
T_1 V_18 )
{
V_2 -> V_10 += V_18 ;
if ( V_2 -> V_10 == V_2 -> V_5 )
V_2 -> V_10 = 0 ;
if ( V_2 -> F_5 )
return V_2 -> F_5 ( V_2 -> V_4 ) ;
return - V_21 ;
}
