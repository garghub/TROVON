int F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
int * V_3 = F_2 ( * V_1 , V_2 -> V_4 ) ;
return * V_3 ;
}
int F_3 ( T_1 * * V_1 , int V_5 ,
const T_2 * V_2 )
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
T_4 * * V_10 ;
if ( ( V_2 -> V_11 != V_12 )
&& ( V_2 -> V_11 != V_13 ) )
return 0 ;
V_8 = V_2 -> V_14 ;
if ( ! V_8 || ! ( V_8 -> V_15 & V_16 ) )
return 0 ;
V_9 = F_2 ( * V_1 , V_8 -> V_17 ) ;
V_10 = F_2 ( * V_1 , V_8 -> V_18 ) ;
if ( V_7 == 0 ) {
* V_9 = 1 ;
* V_10 = F_5 () ;
if ( * V_10 == NULL ) {
F_6 ( V_19 , V_20 ) ;
return - 1 ;
}
return 1 ;
}
if ( F_7 ( V_9 , V_7 , & V_6 , * V_10 ) < 0 )
return - 1 ;
#ifdef F_8
fprintf ( V_21 , L_1 , V_2 , * V_9 , V_2 -> V_22 ) ;
#endif
F_9 ( V_6 < 0 ) ;
if ( V_6 == 0 ) {
F_10 ( * V_10 ) ;
* V_10 = NULL ;
}
return V_6 ;
}
static T_5 * F_11 ( T_1 * * V_1 , const T_2 * V_2 )
{
const T_3 * V_8 ;
if ( ! V_1 || ! * V_1 )
return NULL ;
V_8 = V_2 -> V_14 ;
if ( ! V_8 || ! ( V_8 -> V_15 & V_23 ) )
return NULL ;
return F_2 ( * V_1 , V_8 -> V_24 ) ;
}
void F_12 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_5 * V_25 ;
V_25 = F_11 ( V_1 , V_2 ) ;
if ( V_25 ) {
V_25 -> V_25 = NULL ;
V_25 -> V_26 = 0 ;
V_25 -> V_27 = 1 ;
}
}
void F_13 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_5 * V_25 ;
V_25 = F_11 ( V_1 , V_2 ) ;
if ( V_25 ) {
F_14 ( V_25 -> V_25 ) ;
V_25 -> V_25 = NULL ;
V_25 -> V_26 = 0 ;
V_25 -> V_27 = 1 ;
}
}
int F_15 ( T_1 * * V_1 , const unsigned char * V_28 , int V_29 ,
const T_2 * V_2 )
{
T_5 * V_25 ;
V_25 = F_11 ( V_1 , V_2 ) ;
if ( ! V_25 )
return 1 ;
F_14 ( V_25 -> V_25 ) ;
V_25 -> V_25 = F_16 ( V_29 ) ;
if ( V_25 -> V_25 == NULL )
return 0 ;
memcpy ( V_25 -> V_25 , V_28 , V_29 ) ;
V_25 -> V_26 = V_29 ;
V_25 -> V_27 = 0 ;
return 1 ;
}
int F_17 ( int * V_26 , unsigned char * * V_30 , T_1 * * V_1 ,
const T_2 * V_2 )
{
T_5 * V_25 ;
V_25 = F_11 ( V_1 , V_2 ) ;
if ( ! V_25 || V_25 -> V_27 )
return 0 ;
if ( V_30 ) {
memcpy ( * V_30 , V_25 -> V_25 , V_25 -> V_26 ) ;
* V_30 += V_25 -> V_26 ;
}
if ( V_26 )
* V_26 = V_25 -> V_26 ;
return 1 ;
}
T_1 * * F_18 ( T_1 * * V_1 , const T_6 * V_31 )
{
T_1 * * V_32 ;
V_32 = F_2 ( * V_1 , V_31 -> V_33 ) ;
return V_32 ;
}
const T_6 * F_19 ( T_1 * * V_1 , const T_6 * V_31 ,
int V_34 )
{
const T_7 * V_35 ;
const T_8 * V_36 ;
long V_37 ;
T_1 * * V_38 ;
int V_39 ;
if ( ! ( V_31 -> V_15 & V_40 ) )
return V_31 ;
V_35 = F_20 ( V_31 -> V_41 ) ;
V_38 = F_2 ( * V_1 , V_35 -> V_33 ) ;
if ( * V_38 == NULL ) {
if ( ! V_35 -> V_42 )
goto V_43;
return V_35 -> V_42 ;
}
if ( V_31 -> V_15 & V_44 )
V_37 = F_21 ( ( V_45 * ) * V_38 ) ;
else
V_37 = F_22 ( ( V_46 * ) * V_38 ) ;
if ( V_35 -> V_47 != NULL && V_35 -> V_47 ( & V_37 ) == 0 ) {
F_6 ( V_48 , V_49 ) ;
return NULL ;
}
for ( V_36 = V_35 -> V_50 , V_39 = 0 ; V_39 < V_35 -> V_51 ; V_39 ++ , V_36 ++ )
if ( V_36 -> V_5 == V_37 )
return & V_36 -> V_31 ;
if ( ! V_35 -> V_52 )
goto V_43;
return V_35 -> V_52 ;
V_43:
if ( V_34 )
F_6 ( V_48 , V_49 ) ;
return NULL ;
}
