int F_1 ( T_1 * V_1 , const unsigned char * * V_2 , T_2 V_3 )
{
T_2 V_4 ;
T_2 V_5 = V_3 ;
const unsigned char * V_6 ;
if ( V_1 -> V_7 != V_8 ) {
F_2 ( V_9 , V_10 ) ;
return - 1 ;
}
if ( V_3 <= 4 ) {
F_2 ( V_9 , V_11 ) ;
return - 1 ;
}
V_6 = * V_2 ;
V_1 -> V_12 = * V_6 ++ ;
V_1 -> V_13 = * V_6 ++ ;
if ( F_3 ( V_1 ) == V_14 ) {
F_2 ( V_9 , V_11 ) ;
return - 1 ;
}
F_4 ( V_6 , V_4 ) ;
V_5 -= ( V_6 - * V_2 ) ;
if ( V_4 > V_5 ) {
F_2 ( V_9 , V_11 ) ;
return - 1 ;
}
if ( F_5 ( V_1 , V_6 , V_4 ) != 1 )
return - 1 ;
V_5 -= V_4 ;
* V_2 = V_6 + V_4 ;
return V_3 - V_5 ;
}
T_1 * F_6 ( T_1 * * V_15 , const unsigned char * * V_2 , T_2 V_3 )
{
T_1 * V_1 = NULL ;
const unsigned char * V_6 ;
if ( V_3 == 0 || V_3 > V_16 ) {
F_2 ( V_17 , V_18 ) ;
goto V_19;
}
if ( ( V_1 = F_7 () ) == NULL )
goto V_19;
V_6 = * V_2 ;
V_1 -> V_7 = * V_6 ;
if ( V_1 -> V_7 == V_8 ) {
int V_20 ;
T_2 V_21 ;
if ( V_3 < 43 ) {
F_2 ( V_17 , V_18 ) ;
goto V_19;
}
V_3 -= 43 ;
V_6 ++ ;
V_1 -> V_22 = F_8 ( V_6 , V_23 ) ;
if ( V_1 -> V_22 == NULL )
goto V_19;
V_1 -> V_24 = V_23 ;
V_6 += V_23 ;
F_9 ( V_6 , V_1 -> V_25 ) ;
F_4 ( V_6 , V_21 ) ;
if ( V_3 < V_21 ) {
F_2 ( V_17 , V_18 ) ;
goto V_19;
}
if ( V_21 > 0 ) {
V_1 -> V_26 = F_8 ( V_6 , V_21 ) ;
if ( V_1 -> V_26 == NULL )
goto V_19;
}
V_1 -> V_27 = V_21 ;
V_6 += V_21 ;
V_3 -= V_21 ;
V_20 = F_1 ( V_1 , & V_6 , V_3 ) ;
if ( V_20 <= 0 ) {
F_2 ( V_17 , V_18 ) ;
goto V_19;
}
V_3 -= V_20 ;
* V_2 = V_6 + V_3 ;
} else {
V_1 -> V_1 = F_8 ( V_6 , V_3 ) ;
if ( V_1 -> V_1 == NULL )
goto V_19;
V_1 -> V_28 = V_3 ;
* V_2 = V_6 + V_3 ;
}
if ( V_15 != NULL ) {
F_10 ( * V_15 ) ;
* V_15 = V_1 ;
}
return V_1 ;
V_19:
F_10 ( V_1 ) ;
return NULL ;
}
int F_11 ( const T_1 * V_1 , unsigned char * * V_29 )
{
T_2 V_3 ;
unsigned char * V_6 = NULL ;
if ( ! F_12 ( V_1 ) ) {
F_2 ( V_30 , V_11 ) ;
goto V_19;
}
if ( V_1 -> V_7 != V_8 ) {
F_2 ( V_30 , V_10 ) ;
goto V_19;
}
V_3 = 4 + V_1 -> V_20 ;
if ( V_29 != NULL ) {
if ( * V_29 != NULL ) {
V_6 = * V_29 ;
* V_29 += V_3 ;
} else {
V_6 = F_13 ( V_3 ) ;
if ( V_6 == NULL ) {
F_2 ( V_30 , V_31 ) ;
goto V_19;
}
* V_29 = V_6 ;
}
* V_6 ++ = V_1 -> V_12 ;
* V_6 ++ = V_1 -> V_13 ;
F_14 ( V_1 -> V_20 , V_6 ) ;
memcpy ( V_6 , V_1 -> V_32 , V_1 -> V_20 ) ;
}
return V_3 ;
V_19:
F_15 ( V_6 ) ;
return - 1 ;
}
int F_16 ( const T_1 * V_1 , unsigned char * * V_29 )
{
T_2 V_3 ;
unsigned char * V_6 = NULL ;
if ( ! F_17 ( V_1 ) ) {
F_2 ( V_33 , V_34 ) ;
goto V_19;
}
if ( V_1 -> V_7 == V_8 )
V_3 = 43 + V_1 -> V_27 + 4 + V_1 -> V_20 ;
else
V_3 = V_1 -> V_28 ;
if ( V_29 == NULL )
return V_3 ;
if ( * V_29 != NULL ) {
V_6 = * V_29 ;
* V_29 += V_3 ;
} else {
V_6 = F_13 ( V_3 ) ;
if ( V_6 == NULL ) {
F_2 ( V_33 , V_31 ) ;
goto V_19;
}
* V_29 = V_6 ;
}
if ( V_1 -> V_7 == V_8 ) {
* V_6 ++ = V_1 -> V_7 ;
memcpy ( V_6 , V_1 -> V_22 , V_23 ) ;
V_6 += V_23 ;
F_18 ( V_1 -> V_25 , V_6 ) ;
F_14 ( V_1 -> V_27 , V_6 ) ;
if ( V_1 -> V_27 > 0 ) {
memcpy ( V_6 , V_1 -> V_26 , V_1 -> V_27 ) ;
V_6 += V_1 -> V_27 ;
}
if ( F_11 ( V_1 , & V_6 ) <= 0 )
goto V_19;
} else {
memcpy ( V_6 , V_1 -> V_1 , V_3 ) ;
}
return V_3 ;
V_19:
F_15 ( V_6 ) ;
return - 1 ;
}
