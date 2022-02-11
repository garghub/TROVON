T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 ;
T_3 * V_3 ;
V_2 = F_2 () ;
if ( ! V_2 )
return NULL ;
V_3 = F_3 ( T_3 ) ;
if ( ! V_3 )
goto V_4;
V_2 -> V_5 = F_4 ( V_6 ) ;
V_2 -> V_7 . V_8 = V_3 ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 -> V_11 = F_4 ( V_12 ) ;
F_5 ( V_3 -> V_13 , V_1 ) ;
return V_2 ;
V_4:
if ( V_2 )
F_6 ( V_2 ) ;
return NULL ;
}
T_4 * F_7 ( T_1 * V_2 )
{
T_3 * V_3 ;
V_3 = V_2 -> V_7 . V_8 ;
return F_8 ( V_3 -> V_13 ) ;
}
int F_9 ( T_1 * V_2 , T_4 * V_14 , int V_15 )
{
T_5 V_16 ;
unsigned char V_1 [ V_17 ] ;
unsigned int V_18 ;
int V_19 = 0 ;
T_3 * V_3 ;
F_10 ( & V_16 ) ;
V_3 = V_2 -> V_7 . V_8 ;
if ( ! F_11 ( & V_16 , V_14 , V_3 -> V_13 ) )
goto V_4;
if ( F_12 ( & V_16 , V_1 , & V_18 ) <= 0 )
goto V_4;
if ( V_15 ) {
if ( V_18 != ( unsigned int ) V_3 -> V_20 -> V_21 ) {
F_13 ( V_22 ,
V_23 ) ;
goto V_4;
}
if ( memcmp ( V_1 , V_3 -> V_20 -> V_24 , V_18 ) )
F_13 ( V_22 ,
V_25 ) ;
else
V_19 = 1 ;
} else {
if ( ! F_14 ( V_3 -> V_20 , V_1 , V_18 ) )
goto V_4;
V_19 = 1 ;
}
V_4:
F_15 ( & V_16 ) ;
return V_19 ;
}
