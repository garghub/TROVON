int F_1 ( T_1 * V_1 , long V_2 )
{
return F_2 ( V_1 -> V_2 , V_2 ) ;
}
long F_3 ( const T_1 * V_1 )
{
return F_4 ( V_1 -> V_2 ) ;
}
int F_5 ( T_1 * V_1 , T_2 * V_3 )
{
T_2 * V_4 ;
if ( V_1 -> V_3 == V_3 )
return 1 ;
V_4 = F_6 ( V_3 ) ;
if ( V_4 == NULL ) {
F_7 ( V_5 , V_6 ) ;
return 0 ;
}
F_8 ( V_1 -> V_3 ) ;
V_1 -> V_3 = V_4 ;
return 1 ;
}
T_2 * F_9 ( T_1 * V_1 )
{
return V_1 -> V_3 ;
}
int F_10 ( T_2 * V_1 , T_3 * V_7 )
{
T_3 * V_8 ;
if ( V_1 -> V_9 == V_7 )
return 1 ;
V_8 = F_11 ( V_7 ) ;
if ( V_8 == NULL ) {
F_7 ( V_10 , V_6 ) ;
return 0 ;
}
F_12 ( V_1 -> V_9 ) ;
V_1 -> V_9 = V_8 ;
return 1 ;
}
T_3 * F_13 ( T_2 * V_1 )
{
return V_1 -> V_9 ;
}
int F_14 ( T_2 * V_1 , unsigned char * V_11 , int V_12 )
{
return F_15 ( V_1 -> V_13 , V_11 , V_12 ) ;
}
T_4 * F_16 ( T_2 * V_1 )
{
return V_1 -> V_13 ;
}
int F_17 ( T_1 * V_1 , const T_5 * V_14 )
{
T_5 * V_15 ;
if ( V_1 -> V_16 == V_14 )
return 1 ;
V_15 = F_18 ( V_14 ) ;
if ( V_15 == NULL ) {
F_7 ( V_17 , V_6 ) ;
return 0 ;
}
F_19 ( V_1 -> V_16 ) ;
V_1 -> V_16 = V_15 ;
return 1 ;
}
T_5 * F_20 ( T_1 * V_1 )
{
return V_1 -> V_16 ;
}
int F_21 ( T_1 * V_1 , const T_6 * V_18 )
{
T_6 * V_19 ;
if ( V_1 -> V_18 == V_18 )
return 1 ;
V_19 = F_22 ( V_18 ) ;
if ( V_19 == NULL ) {
F_7 ( V_20 , V_6 ) ;
return 0 ;
}
F_23 ( V_1 -> V_18 ) ;
V_1 -> V_18 = V_19 ;
return 1 ;
}
const T_6 * F_24 ( const T_1 * V_1 )
{
return V_1 -> V_18 ;
}
int F_25 ( T_1 * V_1 , int V_21 )
{
V_1 -> V_21 = V_21 ? 0xFF : 0x00 ;
return 1 ;
}
int F_26 ( const T_1 * V_1 )
{
return V_1 -> V_21 ? 1 : 0 ;
}
void F_27 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
F_28 ( V_1 -> V_22 , V_23 ) ;
V_1 -> V_22 = NULL ;
}
int F_29 ( T_1 * V_1 )
{
return F_30 ( V_1 -> V_22 ) ;
}
int F_31 ( T_1 * V_1 , int V_24 , int V_25 )
{
return F_32 ( V_1 -> V_22 , V_24 , V_25 ) ;
}
int F_33 ( T_1 * V_1 , const T_5 * V_26 , int V_25 )
{
return F_34 ( V_1 -> V_22 , V_26 , V_25 ) ;
}
int F_35 ( T_1 * V_1 , int V_27 , int V_25 )
{
return F_36 ( V_1 -> V_22 , V_27 , V_25 ) ;
}
T_7 * F_37 ( T_1 * V_1 , int V_28 )
{
return F_38 ( V_1 -> V_22 , V_28 ) ;
}
T_7 * F_39 ( T_1 * V_1 , int V_28 )
{
return F_40 ( V_1 -> V_22 , V_28 ) ;
}
int F_41 ( T_1 * V_1 , T_7 * V_29 , int V_28 )
{
return F_42 ( & V_1 -> V_22 , V_29 , V_28 ) != NULL ;
}
void * F_43 ( T_1 * V_1 , int V_24 , int * V_27 , int * V_30 )
{
return F_44 ( V_1 -> V_22 , V_24 , V_27 , V_30 ) ;
}
