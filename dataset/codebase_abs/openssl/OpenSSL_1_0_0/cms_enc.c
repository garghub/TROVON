T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
T_3 * V_3 ;
const T_4 * V_4 ;
T_5 * V_5 = V_1 -> V_6 ;
unsigned char V_7 [ V_8 ] , * V_9 = NULL ;
int V_10 = 0 ;
int V_11 , V_12 = 0 ;
V_11 = V_1 -> V_13 ? 1 : 0 ;
V_2 = F_2 ( F_3 () ) ;
if ( ! V_2 )
{
F_4 ( V_14 ,
V_15 ) ;
return NULL ;
}
F_5 ( V_2 , & V_3 ) ;
if ( V_11 )
{
V_4 = V_1 -> V_13 ;
if ( V_1 -> V_16 )
V_1 -> V_13 = NULL ;
}
else
{
V_4 = F_6 ( V_5 -> V_17 ) ;
if ( ! V_4 )
{
F_4 ( V_14 ,
V_18 ) ;
goto V_19;
}
}
if ( F_7 ( V_3 , V_4 , NULL , NULL , NULL , V_11 ) <= 0 )
{
F_4 ( V_14 ,
V_20 ) ;
goto V_19;
}
if ( V_11 )
{
int V_21 ;
V_5 -> V_17 = F_8 ( F_9 ( V_3 ) ) ;
V_21 = F_10 ( V_3 ) ;
if ( V_21 > 0 )
{
if ( F_11 ( V_7 , V_21 ) <= 0 )
goto V_19;
V_9 = V_7 ;
}
}
else if ( F_12 ( V_3 , V_5 -> V_22 ) <= 0 )
{
F_4 ( V_14 ,
V_23 ) ;
goto V_19;
}
if ( V_11 && ! V_1 -> V_16 )
{
if ( ! V_1 -> V_24 )
V_1 -> V_24 = F_13 ( V_3 ) ;
V_1 -> V_16 = F_14 ( V_1 -> V_24 ) ;
if ( ! V_1 -> V_16 )
{
F_4 ( V_14 ,
V_15 ) ;
goto V_19;
}
if ( F_15 ( V_3 , V_1 -> V_16 ) <= 0 )
goto V_19;
V_12 = 1 ;
}
else if ( V_1 -> V_24 != ( unsigned int ) F_13 ( V_3 ) )
{
if ( F_16 ( V_3 , V_1 -> V_24 ) <= 0 )
{
F_4 ( V_14 ,
V_25 ) ;
goto V_19;
}
}
if ( F_7 ( V_3 , NULL , NULL , V_1 -> V_16 , V_9 , V_11 ) <= 0 )
{
F_4 ( V_14 ,
V_20 ) ;
goto V_19;
}
if ( V_9 )
{
V_5 -> V_22 = F_17 () ;
if ( ! V_5 -> V_22 )
{
F_4 ( V_14 ,
V_15 ) ;
goto V_19;
}
if ( F_18 ( V_3 , V_5 -> V_22 ) <= 0 )
{
F_4 ( V_14 ,
V_23 ) ;
goto V_19;
}
}
V_10 = 1 ;
V_19:
if ( V_1 -> V_16 && ! V_12 )
{
F_19 ( V_1 -> V_16 , V_1 -> V_24 ) ;
F_20 ( V_1 -> V_16 ) ;
V_1 -> V_16 = NULL ;
}
if ( V_10 )
return V_2 ;
F_21 ( V_2 ) ;
return NULL ;
}
int F_22 ( T_2 * V_1 ,
const T_4 * V_13 ,
const unsigned char * V_16 , T_6 V_24 )
{
V_1 -> V_13 = V_13 ;
if ( V_16 )
{
V_1 -> V_16 = F_14 ( V_24 ) ;
if ( ! V_1 -> V_16 )
return 0 ;
memcpy ( V_1 -> V_16 , V_16 , V_24 ) ;
}
V_1 -> V_24 = V_24 ;
if ( V_13 )
V_1 -> V_26 = F_8 ( V_27 ) ;
return 1 ;
}
int F_23 ( T_7 * V_28 , const T_4 * V_4 ,
const unsigned char * V_16 , T_6 V_24 )
{
T_2 * V_1 ;
if ( ! V_16 || ! V_24 )
{
F_4 ( V_29 , V_30 ) ;
return 0 ;
}
if ( V_4 )
{
V_28 -> V_31 . V_32 = F_24 ( V_33 ) ;
if ( ! V_28 -> V_31 . V_32 )
{
F_4 ( V_29 ,
V_15 ) ;
return 0 ;
}
V_28 -> V_26 = F_8 ( V_34 ) ;
V_28 -> V_31 . V_32 -> V_35 = 0 ;
}
else if ( F_25 ( V_28 -> V_26 ) != V_34 )
{
F_4 ( V_29 ,
V_36 ) ;
return 0 ;
}
V_1 = V_28 -> V_31 . V_32 -> V_37 ;
return F_22 ( V_1 , V_4 , V_16 , V_24 ) ;
}
T_1 * F_26 ( T_7 * V_28 )
{
V_33 * V_11 = V_28 -> V_31 . V_32 ;
if ( V_11 -> V_37 -> V_13 && V_11 -> V_38 )
V_11 -> V_35 = 2 ;
return F_1 ( V_11 -> V_37 ) ;
}
