static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
if ( V_1 == V_5 ) {
* V_2 = ( T_1 * ) F_2 () ;
if ( * V_2 )
return 2 ;
return 0 ;
} else if ( V_1 == V_6 ) {
F_3 ( ( V_7 * ) * V_2 ) ;
* V_2 = NULL ;
return 2 ;
}
return 1 ;
}
V_7 * F_4 ( V_7 * * V_8 , const unsigned char * * V_9 , long V_10 )
{
T_3 * V_11 = NULL ;
V_7 * V_12 = NULL ;
V_12 = F_2 () ;
if ( ! V_12 )
return NULL ;
V_11 = F_5 ( NULL , V_9 , V_10 ) ;
if ( ! V_11 ) {
F_3 ( V_12 ) ;
return NULL ;
}
if ( V_8 ) {
if ( * V_8 )
F_3 ( * V_8 ) ;
* V_8 = V_12 ;
}
V_12 -> V_13 = V_11 -> V_13 ;
V_12 -> V_14 = V_11 -> V_14 ;
V_12 -> V_15 = V_11 -> V_15 ;
V_12 -> V_16 = V_11 -> V_16 ;
if ( V_11 -> V_17 ) {
V_12 -> V_18 = V_11 -> V_17 -> V_18 -> V_19 ;
V_12 -> V_20 = V_11 -> V_17 -> V_18 -> V_10 ;
V_12 -> V_21 = V_11 -> V_17 -> V_21 ;
V_11 -> V_17 -> V_18 -> V_19 = NULL ;
F_6 ( V_11 -> V_17 -> V_18 ) ;
F_7 ( V_11 -> V_17 ) ;
V_11 -> V_17 = NULL ;
}
F_7 ( V_11 ) ;
return V_12 ;
}
int F_8 ( const V_7 * V_12 , unsigned char * * V_9 )
{
T_3 V_11 ;
T_4 V_22 ;
T_5 V_23 ;
V_11 . V_13 = V_12 -> V_13 ;
V_11 . V_15 = V_12 -> V_15 ;
V_11 . V_14 = V_12 -> V_14 ;
V_11 . V_16 = V_12 -> V_16 ;
if ( V_12 -> V_21 && V_12 -> V_18 && V_12 -> V_20 > 0 ) {
V_23 . V_24 = V_25 ;
V_23 . V_19 = V_12 -> V_18 ;
V_23 . V_10 = V_12 -> V_20 ;
V_22 . V_18 = & V_23 ;
V_22 . V_21 = V_12 -> V_21 ;
V_11 . V_17 = & V_22 ;
} else
V_11 . V_17 = NULL ;
return F_9 ( & V_11 , V_9 ) ;
}
