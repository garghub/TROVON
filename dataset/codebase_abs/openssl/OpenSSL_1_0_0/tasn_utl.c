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
if ( ( V_2 -> V_10 != V_11 )
&& ( V_2 -> V_10 != V_12 ) )
return 0 ;
V_8 = V_2 -> V_13 ;
if ( ! V_8 || ! ( V_8 -> V_14 & V_15 ) )
return 0 ;
V_9 = F_2 ( * V_1 , V_8 -> V_16 ) ;
if ( V_7 == 0 )
{
* V_9 = 1 ;
return 1 ;
}
V_6 = F_5 ( V_9 , V_7 , V_8 -> V_17 ) ;
#ifdef F_6
fprintf ( V_18 , L_1 , V_2 -> V_19 , * V_9 ) ;
#endif
#ifdef F_7
if ( V_6 < 0 )
fprintf ( V_18 , L_2 , V_2 -> V_19 ) ;
#endif
return V_6 ;
}
static T_4 * F_8 ( T_1 * * V_1 , const T_2 * V_2 )
{
const T_3 * V_8 ;
if ( ! V_1 || ! * V_1 )
return NULL ;
V_8 = V_2 -> V_13 ;
if ( ! V_8 || ! ( V_8 -> V_14 & V_20 ) )
return NULL ;
return F_2 ( * V_1 , V_8 -> V_21 ) ;
}
void F_9 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_4 * V_22 ;
V_22 = F_8 ( V_1 , V_2 ) ;
if ( V_22 )
{
V_22 -> V_22 = NULL ;
V_22 -> V_23 = 0 ;
V_22 -> V_24 = 1 ;
}
}
void F_10 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_4 * V_22 ;
V_22 = F_8 ( V_1 , V_2 ) ;
if ( V_22 )
{
if ( V_22 -> V_22 )
F_11 ( V_22 -> V_22 ) ;
V_22 -> V_22 = NULL ;
V_22 -> V_23 = 0 ;
V_22 -> V_24 = 1 ;
}
}
int F_12 ( T_1 * * V_1 , const unsigned char * V_25 , int V_26 ,
const T_2 * V_2 )
{
T_4 * V_22 ;
V_22 = F_8 ( V_1 , V_2 ) ;
if ( ! V_22 )
return 1 ;
if ( V_22 -> V_22 )
F_11 ( V_22 -> V_22 ) ;
V_22 -> V_22 = F_13 ( V_26 ) ;
if ( ! V_22 -> V_22 )
return 0 ;
memcpy ( V_22 -> V_22 , V_25 , V_26 ) ;
V_22 -> V_23 = V_26 ;
V_22 -> V_24 = 0 ;
return 1 ;
}
int F_14 ( int * V_23 , unsigned char * * V_27 , T_1 * * V_1 ,
const T_2 * V_2 )
{
T_4 * V_22 ;
V_22 = F_8 ( V_1 , V_2 ) ;
if ( ! V_22 || V_22 -> V_24 )
return 0 ;
if ( V_27 )
{
memcpy ( * V_27 , V_22 -> V_22 , V_22 -> V_23 ) ;
* V_27 += V_22 -> V_23 ;
}
if ( V_23 )
* V_23 = V_22 -> V_23 ;
return 1 ;
}
T_1 * * F_15 ( T_1 * * V_1 , const T_5 * V_28 )
{
T_1 * * V_29 ;
if ( V_28 -> V_14 & V_30 )
return V_1 ;
V_29 = F_2 ( * V_1 , V_28 -> V_31 ) ;
return V_29 ;
}
const T_5 * F_16 ( T_1 * * V_1 , const T_5 * V_28 ,
int V_32 )
{
const T_6 * V_33 ;
const T_7 * V_34 ;
long V_35 ;
T_1 * * V_36 ;
int V_37 ;
if ( ! ( V_28 -> V_14 & V_38 ) )
return V_28 ;
V_33 = F_17 ( V_28 -> V_39 ) ;
V_36 = F_2 ( * V_1 , V_33 -> V_31 ) ;
if ( ! V_36 )
{
if ( ! V_33 -> V_40 )
goto V_41;
return V_33 -> V_40 ;
}
if ( V_28 -> V_14 & V_42 )
V_35 = F_18 ( ( V_43 * ) * V_36 ) ;
else
V_35 = F_19 ( ( V_44 * ) * V_36 ) ;
for ( V_34 = V_33 -> V_45 , V_37 = 0 ; V_37 < V_33 -> V_46 ; V_37 ++ , V_34 ++ )
if ( V_34 -> V_5 == V_35 )
return & V_34 -> V_28 ;
if ( ! V_33 -> V_47 )
goto V_41;
return V_33 -> V_47 ;
V_41:
if ( V_32 )
F_20 ( V_48 ,
V_49 ) ;
return NULL ;
}
