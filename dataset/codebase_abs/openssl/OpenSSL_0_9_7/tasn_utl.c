int F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
int * V_3 = F_2 ( * V_1 , V_2 -> V_4 ) ;
return * V_3 ;
}
int F_3 ( T_1 * * V_1 , int V_5 , const T_2 * V_2 )
{
int * V_3 , V_6 ;
V_3 = F_2 ( * V_1 , V_2 -> V_4 ) ;
V_6 = * V_3 ;
* V_3 = V_5 ;
return V_6 ;
}
int F_4 ( T_1 * * V_1 , int V_7 , const T_2 * V_2 )
{
const T_3 * V_8 ;
int * V_9 , V_6 ;
if( V_2 -> V_10 != V_11 ) return 0 ;
V_8 = V_2 -> V_12 ;
if( ! V_8 || ! ( V_8 -> V_13 & V_14 ) ) return 0 ;
V_9 = F_2 ( * V_1 , V_8 -> V_15 ) ;
if( V_7 == 0 ) {
* V_9 = 1 ;
return 1 ;
}
V_6 = F_5 ( V_9 , V_7 , V_8 -> V_16 ) ;
#ifdef F_6
fprintf ( V_17 , L_1 , V_2 -> V_18 , * V_9 ) ;
#endif
#ifdef F_7
if( V_6 < 0 )
fprintf ( V_17 , L_2 , V_2 -> V_18 ) ;
#endif
return V_6 ;
}
static T_4 * F_8 ( T_1 * * V_1 , const T_2 * V_2 )
{
const T_3 * V_8 ;
if( ! V_1 || ! * V_1 ) return NULL ;
V_8 = V_2 -> V_12 ;
if( ! V_8 || ! ( V_8 -> V_13 & V_19 ) ) return NULL ;
return F_2 ( * V_1 , V_8 -> V_20 ) ;
}
void F_9 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_4 * V_21 ;
V_21 = F_8 ( V_1 , V_2 ) ;
if( V_21 ) {
V_21 -> V_21 = NULL ;
V_21 -> V_22 = 0 ;
V_21 -> V_23 = 1 ;
}
}
void F_10 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_4 * V_21 ;
V_21 = F_8 ( V_1 , V_2 ) ;
if( V_21 ) {
if( V_21 -> V_21 ) F_11 ( V_21 -> V_21 ) ;
V_21 -> V_21 = NULL ;
V_21 -> V_22 = 0 ;
V_21 -> V_23 = 1 ;
}
}
int F_12 ( T_1 * * V_1 , unsigned char * V_24 , int V_25 , const T_2 * V_2 )
{
T_4 * V_21 ;
V_21 = F_8 ( V_1 , V_2 ) ;
if( ! V_21 ) return 1 ;
if( V_21 -> V_21 ) F_11 ( V_21 -> V_21 ) ;
V_21 -> V_21 = F_13 ( V_25 ) ;
if( ! V_21 -> V_21 ) return 0 ;
memcpy ( V_21 -> V_21 , V_24 , V_25 ) ;
V_21 -> V_22 = V_25 ;
V_21 -> V_23 = 0 ;
return 1 ;
}
int F_14 ( int * V_22 , unsigned char * * V_26 , T_1 * * V_1 , const T_2 * V_2 )
{
T_4 * V_21 ;
V_21 = F_8 ( V_1 , V_2 ) ;
if( ! V_21 || V_21 -> V_23 ) return 0 ;
if( V_26 ) {
memcpy ( * V_26 , V_21 -> V_21 , V_21 -> V_22 ) ;
* V_26 += V_21 -> V_22 ;
}
if( V_22 ) * V_22 = V_21 -> V_22 ;
return 1 ;
}
T_1 * * F_15 ( T_1 * * V_1 , const T_5 * V_27 )
{
T_1 * * V_28 ;
if( V_27 -> V_13 & V_29 ) return V_1 ;
V_28 = F_2 ( * V_1 , V_27 -> V_30 ) ;
return V_28 ;
}
const T_5 * F_16 ( T_1 * * V_1 , const T_5 * V_27 , int V_31 )
{
const T_6 * V_32 ;
const T_7 * V_33 ;
long V_34 ;
T_1 * * V_35 ;
int V_36 ;
if( ! ( V_27 -> V_13 & V_37 ) ) return V_27 ;
V_32 = F_17 ( V_27 -> V_38 ) ;
V_35 = F_2 ( * V_1 , V_32 -> V_30 ) ;
if( ! V_35 ) {
if( ! V_32 -> V_39 ) goto V_40;
return V_32 -> V_39 ;
}
if( V_27 -> V_13 & V_41 )
V_34 = F_18 ( ( V_42 * ) * V_35 ) ;
else
V_34 = F_19 ( ( V_43 * ) * V_35 ) ;
for( V_33 = V_32 -> V_44 , V_36 = 0 ; V_36 < V_32 -> V_45 ; V_36 ++ , V_33 ++ )
if( V_33 -> V_5 == V_34 ) return & V_33 -> V_27 ;
if( ! V_32 -> V_46 ) goto V_40;
return V_32 -> V_46 ;
V_40:
if( V_31 ) F_20 ( V_47 , V_48 ) ;
return NULL ;
}
