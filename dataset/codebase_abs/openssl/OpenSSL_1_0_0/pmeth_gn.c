int F_1 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_4 )
{
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
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_4 )
{
F_2 ( V_12 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_8 )
{
F_2 ( V_12 , V_13 ) ;
return - 1 ;
}
if ( ! V_11 )
return - 1 ;
if ( ! * V_11 )
* V_11 = F_4 () ;
V_2 = V_1 -> V_3 -> V_4 ( V_1 , * V_11 ) ;
if ( V_2 <= 0 )
{
F_5 ( * V_11 ) ;
* V_11 = NULL ;
}
return V_2 ;
}
int F_6 ( T_1 * V_1 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_14 )
{
F_2 ( V_15 ,
V_6 ) ;
return - 2 ;
}
V_1 -> V_7 = V_16 ;
if ( ! V_1 -> V_3 -> V_17 )
return 1 ;
V_2 = V_1 -> V_3 -> V_17 ( V_1 ) ;
if ( V_2 <= 0 )
V_1 -> V_7 = V_10 ;
return V_2 ;
}
int F_7 ( T_1 * V_1 , T_2 * * V_11 )
{
int V_2 ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_3 -> V_14 )
{
F_2 ( V_18 ,
V_6 ) ;
return - 2 ;
}
if ( V_1 -> V_7 != V_16 )
{
F_2 ( V_18 , V_13 ) ;
return - 1 ;
}
if ( ! V_11 )
return - 1 ;
if ( ! * V_11 )
* V_11 = F_4 () ;
V_2 = V_1 -> V_3 -> V_14 ( V_1 , * V_11 ) ;
if ( V_2 <= 0 )
{
F_5 ( * V_11 ) ;
* V_11 = NULL ;
}
return V_2 ;
}
void F_8 ( T_1 * V_1 , T_3 * V_19 )
{
V_1 -> V_20 = V_19 ;
}
T_3 * F_9 ( T_1 * V_1 )
{
return V_1 -> V_20 ;
}
static int F_10 ( int V_21 , int V_22 , T_4 * V_23 )
{
T_1 * V_1 = V_23 -> V_24 ;
V_1 -> V_25 [ 0 ] = V_21 ;
V_1 -> V_25 [ 1 ] = V_22 ;
return V_1 -> V_20 ( V_1 ) ;
}
void F_11 ( T_4 * V_19 , T_1 * V_1 )
{
F_12 (cb, trans_cb, ctx)
}
int F_13 ( T_1 * V_1 , int V_26 )
{
if ( V_26 == - 1 )
return V_1 -> V_27 ;
if ( V_26 < 0 || V_26 > V_1 -> V_27 )
return 0 ;
return V_1 -> V_25 [ V_26 ] ;
}
T_2 * F_14 ( int type , T_5 * V_28 ,
unsigned char * V_29 , int V_30 )
{
T_1 * V_31 = NULL ;
T_2 * V_32 = NULL ;
V_31 = F_15 ( type , V_28 ) ;
if ( ! V_31 )
return NULL ;
if ( F_6 ( V_31 ) <= 0 )
goto V_33;
if ( F_16 ( V_31 , - 1 , V_16 ,
V_34 , V_30 , V_29 ) <= 0 )
goto V_33;
if ( F_7 ( V_31 , & V_32 ) <= 0 )
goto V_33;
V_33:
if ( V_31 )
F_17 ( V_31 ) ;
return V_32 ;
}
