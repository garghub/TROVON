int F_1 ( const char * type , const char * V_1 , T_1 V_2 ,
const char * V_3 , char * * V_4 , T_2 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
T_1 V_12 , V_13 ;
char * V_14 , * V_15 ;
int V_16 , V_17 ;
F_2 ( L_1 ,
type , ( int ) V_2 , ( int ) V_2 , V_1 , V_2 , V_3 ) ;
if ( ! V_1 || V_2 == 0 || ! V_4 )
return - V_18 ;
V_12 = 0 ;
V_13 = 0 ;
if ( type ) {
V_12 = strlen ( type ) ;
if ( V_12 < 1 )
return - V_18 ;
V_13 += V_12 + 1 ;
}
if ( ! V_2 )
V_2 = F_3 ( V_1 , 256 ) ;
if ( V_2 < 3 || V_2 > 255 )
return - V_18 ;
V_13 += V_2 + 1 ;
V_14 = F_4 ( V_13 , V_19 ) ;
if ( ! V_14 )
return - V_20 ;
V_15 = V_14 ;
if ( type ) {
memcpy ( V_15 , type , V_12 ) ;
V_15 += V_12 ;
* V_15 ++ = ':' ;
}
memcpy ( V_15 , V_1 , V_2 ) ;
V_15 += V_2 ;
* V_15 = '\0' ;
if ( ! V_3 )
V_3 = L_2 ;
F_5 ( L_3 , V_14 , V_3 ) ;
V_11 = F_6 ( V_21 ) ;
V_7 = F_7 ( & V_22 , V_14 , V_3 ) ;
F_8 ( V_11 ) ;
F_9 ( V_14 ) ;
if ( F_10 ( V_7 ) ) {
V_16 = F_11 ( V_7 ) ;
goto V_23;
}
F_12 ( & V_7 -> V_24 ) ;
V_7 -> V_25 |= V_26 ;
V_16 = F_13 ( V_7 ) ;
if ( V_16 < 0 )
goto V_27;
V_16 = V_7 -> V_28 . V_29 [ 0 ] ;
if ( V_16 )
goto V_27;
V_9 = F_14 ( V_7 -> V_30 . V_31 ,
F_15 ( & V_7 -> V_24 ) ) ;
V_17 = V_9 -> V_32 ;
V_16 = - V_20 ;
* V_4 = F_4 ( V_17 + 1 , V_19 ) ;
if ( ! * V_4 )
goto V_27;
memcpy ( * V_4 , V_9 -> V_31 , V_17 ) ;
( * V_4 ) [ V_17 ] = '\0' ;
if ( V_5 )
* V_5 = V_7 -> V_33 ;
V_16 = V_17 ;
V_27:
F_16 ( & V_7 -> V_24 ) ;
F_17 ( V_7 ) ;
V_23:
F_18 ( L_4 , V_16 ) ;
return V_16 ;
}
