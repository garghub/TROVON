T_1 * F_1 ( const T_2 * V_1 , int V_2 )
{
return F_2 ( V_1 -> V_3 , V_2 ) ;
}
const T_1 * F_3 ( const T_2 * V_1 ,
int V_2 )
{
return F_2 ( V_1 -> V_3 , V_2 ) ;
}
T_1 * F_4 ( T_3 * V_4 , int V_2 )
{
return F_2 ( F_5 ( V_4 ) , V_2 ) ;
}
const T_3 * F_6 ( const T_2 * V_1 )
{
if ( F_7 ( V_1 ) != V_5 )
return NULL ;
return V_1 -> V_6 . V_7 ;
}
const T_4 * F_8 ( const T_2 * V_1 )
{
if ( F_9 ( V_1 -> type ) != V_8 )
return NULL ;
return V_1 -> V_6 . V_9 ;
}
T_5 * F_10 ( const T_2 * V_1 )
{
return V_1 -> type ;
}
int F_7 ( const T_2 * V_1 )
{
return F_9 ( V_1 -> type ) ;
}
int F_11 ( const T_2 * V_1 )
{
int V_10 = F_7 ( V_1 ) ;
if ( V_10 != V_11 && V_10 != V_12 && V_10 != V_13 )
return - 1 ;
return F_9 ( V_1 -> V_6 . V_1 -> type ) ;
}
T_6 * F_12 ( const T_2 * V_1 )
{
if ( F_7 ( V_1 ) != V_11 )
return NULL ;
if ( F_9 ( V_1 -> V_6 . V_1 -> type ) != V_14 )
return NULL ;
return F_13 ( V_1 -> V_6 . V_1 -> V_6 . V_15 ,
F_14 ( T_6 ) ) ;
}
T_7 * F_15 ( const T_2 * V_1 )
{
if ( F_7 ( V_1 ) != V_12 )
return NULL ;
if ( F_9 ( V_1 -> V_6 . V_1 -> type ) != V_16 )
return NULL ;
return F_13 ( V_1 -> V_6 . V_1 -> V_6 . V_15 ,
F_14 ( T_7 ) ) ;
}
T_2 * F_16 ( T_6 * V_17 )
{
return F_17 ( V_17 , F_14 ( T_6 ) ,
V_14 , V_11 ) ;
}
T_2 * F_18 ( T_7 * V_18 )
{
return F_17 ( V_18 , F_14 ( T_7 ) ,
V_16 , V_12 ) ;
}
T_2 * F_19 ( T_3 * V_4 )
{
T_2 * V_1 = F_20 () ;
if ( V_1 == NULL ) {
F_21 ( V_19 , V_20 ) ;
return NULL ;
}
V_1 -> type = F_22 ( V_5 ) ;
V_1 -> V_6 . V_7 = V_4 ;
return V_1 ;
}
T_2 * F_23 ( T_4 * V_4 )
{
T_2 * V_1 = F_20 () ;
if ( V_1 == NULL ) {
F_21 ( V_21 , V_20 ) ;
return NULL ;
}
V_1 -> type = F_22 ( V_8 ) ;
V_1 -> V_6 . V_9 = V_4 ;
return V_1 ;
}
T_2 * F_24 ( int V_22 ,
const char * V_23 ,
int V_24 ,
unsigned char * V_25 ,
int V_26 , int V_27 ,
T_3 * V_28 )
{
T_2 * V_1 ;
const T_8 * V_29 ;
T_4 * V_4 ;
V_29 = F_25 ( V_22 ) ;
if ( V_29 )
V_22 = - 1 ;
V_4 = F_26 ( V_22 , V_29 , V_23 , V_24 , V_25 , V_26 , V_27 ,
V_28 ) ;
if ( V_4 == NULL ) {
F_21 ( V_30 , V_20 ) ;
return NULL ;
}
V_1 = F_23 ( V_4 ) ;
if ( V_1 == NULL ) {
F_21 ( V_30 , V_20 ) ;
F_27 ( V_4 ) ;
return NULL ;
}
return V_1 ;
}
