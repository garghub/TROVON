static int F_1 ( T_1 * V_1 , T_2 * * V_2 ,
const T_3 * type , T_4 * V_3 , T_5 * V_4 ,
int V_5 )
{
if ( V_1 -> V_2 == NULL )
V_1 -> V_2 = F_2 ( V_4 , V_3 ) ;
if ( V_1 -> V_2 == NULL )
return 0 ;
if ( type == NULL )
{
int V_6 ;
if ( F_3 ( V_4 , & V_6 ) > 0 )
type = F_4 ( V_6 ) ;
}
if ( type == NULL )
{
F_5 ( V_7 , V_8 ) ;
return 0 ;
}
if ( V_5 )
{
if ( V_1 -> V_2 -> V_9 -> V_10 )
{
if ( V_1 -> V_2 -> V_9 -> V_10 ( V_1 -> V_2 , V_1 ) <= 0 )
return 0 ;
V_1 -> V_2 -> V_11 = V_12 ;
}
else if ( F_6 ( V_1 -> V_2 ) <= 0 )
return 0 ;
}
else
{
if ( V_1 -> V_2 -> V_9 -> V_13 )
{
if ( V_1 -> V_2 -> V_9 -> V_13 ( V_1 -> V_2 , V_1 ) <= 0 )
return 0 ;
V_1 -> V_2 -> V_11 = V_14 ;
}
else if ( F_7 ( V_1 -> V_2 ) <= 0 )
return 0 ;
}
if ( F_8 ( V_1 -> V_2 , type ) <= 0 )
return 0 ;
if ( V_2 )
* V_2 = V_1 -> V_2 ;
if ( ! F_9 ( V_1 , type , V_3 ) )
return 0 ;
return 1 ;
}
int F_10 ( T_1 * V_1 , T_2 * * V_2 ,
const T_3 * type , T_4 * V_3 , T_5 * V_4 )
{
return F_1 ( V_1 , V_2 , type , V_3 , V_4 , 0 ) ;
}
int F_11 ( T_1 * V_1 , T_2 * * V_2 ,
const T_3 * type , T_4 * V_3 , T_5 * V_4 )
{
return F_1 ( V_1 , V_2 , type , V_3 , V_4 , 1 ) ;
}
int F_12 ( T_1 * V_1 , unsigned char * V_15 , T_6 * V_16 )
{
int V_17 , V_18 = 0 ;
if ( V_1 -> V_2 -> V_9 -> V_19 )
V_17 = 1 ;
else
V_17 = 0 ;
if ( V_15 )
{
T_1 V_20 ;
unsigned char V_21 [ V_22 ] ;
unsigned int V_23 ;
F_13 ( & V_20 ) ;
if ( ! F_14 ( & V_20 , V_1 ) )
return 0 ;
if ( V_17 )
V_18 = V_20 . V_2 -> V_9 -> V_19 ( V_20 . V_2 ,
V_15 , V_16 , & V_20 ) ;
else
V_18 = F_15 ( & V_20 , V_21 , & V_23 ) ;
F_16 ( & V_20 ) ;
if ( V_17 || ! V_18 )
return V_18 ;
if ( F_17 ( V_1 -> V_2 , V_15 , V_16 , V_21 , V_23 ) <= 0 )
return 0 ;
}
else
{
if ( V_17 )
{
if ( V_1 -> V_2 -> V_9 -> V_19 ( V_1 -> V_2 , V_15 , V_16 , V_1 ) <= 0 )
return 0 ;
}
else
{
int V_24 = F_18 ( V_1 -> V_25 ) ;
if ( V_24 < 0 || F_17 ( V_1 -> V_2 , V_15 , V_16 , NULL , V_24 ) <= 0 )
return 0 ;
}
}
return 1 ;
}
int F_19 ( T_1 * V_1 , unsigned char * V_26 , T_6 V_16 )
{
T_1 V_20 ;
unsigned char V_21 [ V_22 ] ;
int V_18 ;
unsigned int V_23 ;
int V_27 ;
if ( V_1 -> V_2 -> V_9 -> V_28 )
V_27 = 1 ;
else
V_27 = 0 ;
F_13 ( & V_20 ) ;
if ( ! F_14 ( & V_20 , V_1 ) )
return - 1 ;
if ( V_27 )
{
V_18 = V_20 . V_2 -> V_9 -> V_28 ( V_20 . V_2 ,
V_26 , V_16 , & V_20 ) ;
}
else
V_18 = F_15 ( & V_20 , V_21 , & V_23 ) ;
F_16 ( & V_20 ) ;
if ( V_27 || ! V_18 )
return V_18 ;
return F_20 ( V_1 -> V_2 , V_26 , V_16 , V_21 , V_23 ) ;
}
