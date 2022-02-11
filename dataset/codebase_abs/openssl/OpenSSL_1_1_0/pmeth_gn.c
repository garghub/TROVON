int F_1 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_4 ) {
F_2 ( V_5 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_8 ;
if ( ! V_1 -> V_3 -> V_9 )
return 1 ;
V_2 = V_1 -> V_3 -> V_9 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_3 ( T_1 * V_1 , T_2 * * V_11 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_4 ) {
F_2 ( V_12 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_8 ) {
F_2 ( V_12 , V_13 ) ;
return - 1 ;
}
if ( V_11 == NULL )
return - 1 ;
if ( * V_11 == NULL )
* V_11 = F_4 () ;
if ( * V_11 == NULL ) {
F_2 ( V_12 , V_14 ) ;
return - 1 ;
}
V_2 = V_1 -> V_3 -> V_4 ( V_1 , * V_11 ) ;
if ( V_2 <= 0 ) {
F_5 ( * V_11 ) ;
* V_11 = NULL ;
}
return V_2 ;
}
int F_6 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_15 ) {
F_2 ( V_16 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_17 ;
if ( ! V_1 -> V_3 -> V_18 )
return 1 ;
V_2 = V_1 -> V_3 -> V_18 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_7 ( T_1 * V_1 , T_2 * * V_11 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_15 ) {
F_2 ( V_19 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_17 ) {
F_2 ( V_19 , V_13 ) ;
return - 1 ;
}
if ( V_11 == NULL )
return - 1 ;
if ( * V_11 == NULL )
* V_11 = F_4 () ;
if ( * V_11 == NULL )
return - 1 ;
V_2 = V_1 -> V_3 -> V_15 ( V_1 , * V_11 ) ;
if ( V_2 <= 0 ) {
F_5 ( * V_11 ) ;
* V_11 = NULL ;
}
return V_2 ;
}
void F_8 ( T_1 * V_1 , T_3 * V_20 )
{
V_1 -> V_21 = V_20 ;
}
T_3 * F_9 ( T_1 * V_1 )
{
return V_1 -> V_21 ;
}
static int F_10 ( int V_22 , int V_23 , T_4 * V_24 )
{
T_1 * V_1 = F_11 ( V_24 ) ;
V_1 -> V_25 [ 0 ] = V_22 ;
V_1 -> V_25 [ 1 ] = V_23 ;
return V_1 -> V_21 ( V_1 ) ;
}
void F_12 ( T_4 * V_20 , T_1 * V_1 )
{
F_13 ( V_20 , F_10 , V_1 ) ;
}
int F_14 ( T_1 * V_1 , int V_26 )
{
if ( V_26 == - 1 )
return V_1 -> V_27 ;
if ( V_26 < 0 || V_26 > V_1 -> V_27 )
return 0 ;
return V_1 -> V_25 [ V_26 ] ;
}
T_2 * F_15 ( int type , T_5 * V_28 ,
const unsigned char * V_29 , int V_30 )
{
T_1 * V_31 = NULL ;
T_2 * V_32 = NULL ;
V_31 = F_16 ( type , V_28 ) ;
if ( ! V_31 )
return NULL ;
if ( F_6 ( V_31 ) <= 0 )
goto V_33;
if ( F_17 ( V_31 , V_29 , V_30 ) <= 0 )
goto V_33;
if ( F_7 ( V_31 , & V_32 ) <= 0 )
goto V_33;
V_33:
F_18 ( V_31 ) ;
return V_32 ;
}
