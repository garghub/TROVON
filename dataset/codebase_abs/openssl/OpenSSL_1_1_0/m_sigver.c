static int F_1 ( T_1 * V_1 , T_2 * * V_2 ,
const T_3 * type , T_4 * V_3 , T_5 * V_4 ,
int V_5 )
{
if ( V_1 -> V_2 == NULL )
V_1 -> V_2 = F_2 ( V_4 , V_3 ) ;
if ( V_1 -> V_2 == NULL )
return 0 ;
if ( ! ( V_1 -> V_2 -> V_6 -> V_7 & V_8 ) ) {
if ( type == NULL ) {
int V_9 ;
if ( F_3 ( V_4 , & V_9 ) > 0 )
type = F_4 ( V_9 ) ;
}
if ( type == NULL ) {
F_5 ( V_10 , V_11 ) ;
return 0 ;
}
}
if ( V_5 ) {
if ( V_1 -> V_2 -> V_6 -> V_12 ) {
if ( V_1 -> V_2 -> V_6 -> V_12 ( V_1 -> V_2 , V_1 ) <= 0 )
return 0 ;
V_1 -> V_2 -> V_13 = V_14 ;
} else if ( F_6 ( V_1 -> V_2 ) <= 0 )
return 0 ;
} else {
if ( V_1 -> V_2 -> V_6 -> V_15 ) {
if ( V_1 -> V_2 -> V_6 -> V_15 ( V_1 -> V_2 , V_1 ) <= 0 )
return 0 ;
V_1 -> V_2 -> V_13 = V_16 ;
} else if ( F_7 ( V_1 -> V_2 ) <= 0 )
return 0 ;
}
if ( F_8 ( V_1 -> V_2 , type ) <= 0 )
return 0 ;
if ( V_2 )
* V_2 = V_1 -> V_2 ;
if ( V_1 -> V_2 -> V_6 -> V_7 & V_8 )
return 1 ;
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
int F_12 ( T_1 * V_1 , unsigned char * V_17 ,
T_6 * V_18 )
{
int V_19 = 0 , V_20 = 0 ;
T_2 * V_2 = V_1 -> V_2 ;
if ( V_2 -> V_6 -> V_7 & V_8 ) {
if ( ! V_17 )
return V_2 -> V_6 -> V_21 ( V_2 , V_17 , V_18 , V_1 ) ;
if ( V_1 -> V_7 & V_22 )
V_20 = V_2 -> V_6 -> V_21 ( V_2 , V_17 , V_18 , V_1 ) ;
else {
T_2 * V_23 = F_13 ( V_1 -> V_2 ) ;
if ( ! V_23 )
return 0 ;
V_20 = V_23 -> V_6 -> V_21 ( V_23 , V_17 , V_18 , V_1 ) ;
F_14 ( V_23 ) ;
}
return V_20 ;
}
if ( V_2 -> V_6 -> V_21 )
V_19 = 1 ;
else
V_19 = 0 ;
if ( V_17 ) {
unsigned char V_24 [ V_25 ] ;
unsigned int V_26 = 0 ;
if ( V_1 -> V_7 & V_22 ) {
if ( V_19 )
V_20 = V_1 -> V_2 -> V_6 -> V_21 ( V_1 -> V_2 , V_17 , V_18 , V_1 ) ;
else
V_20 = F_15 ( V_1 , V_24 , & V_26 ) ;
} else {
T_1 * V_27 = F_16 () ;
if ( V_27 == NULL || ! F_17 ( V_27 , V_1 ) )
return 0 ;
if ( V_19 )
V_20 = V_27 -> V_2 -> V_6 -> V_21 ( V_27 -> V_2 ,
V_17 , V_18 , V_27 ) ;
else
V_20 = F_15 ( V_27 , V_24 , & V_26 ) ;
F_18 ( V_27 ) ;
}
if ( V_19 || ! V_20 )
return V_20 ;
if ( F_19 ( V_1 -> V_2 , V_17 , V_18 , V_24 , V_26 ) <= 0 )
return 0 ;
} else {
if ( V_19 ) {
if ( V_2 -> V_6 -> V_21 ( V_2 , V_17 , V_18 , V_1 ) <= 0 )
return 0 ;
} else {
int V_28 = F_20 ( V_1 -> V_29 ) ;
if ( V_28 < 0 || F_19 ( V_2 , V_17 , V_18 , NULL , V_28 ) <= 0 )
return 0 ;
}
}
return 1 ;
}
int F_21 ( T_1 * V_1 , const unsigned char * V_30 ,
T_6 V_18 )
{
unsigned char V_24 [ V_25 ] ;
int V_20 = 0 ;
unsigned int V_26 = 0 ;
int V_31 = 0 ;
if ( V_1 -> V_2 -> V_6 -> V_32 )
V_31 = 1 ;
else
V_31 = 0 ;
if ( V_1 -> V_7 & V_22 ) {
if ( V_31 ) {
V_20 = V_1 -> V_2 -> V_6 -> V_32 ( V_1 -> V_2 , V_30 , V_18 , V_1 ) ;
} else
V_20 = F_15 ( V_1 , V_24 , & V_26 ) ;
} else {
T_1 * V_27 = F_16 () ;
if ( V_27 == NULL || ! F_17 ( V_27 , V_1 ) )
return - 1 ;
if ( V_31 ) {
V_20 = V_27 -> V_2 -> V_6 -> V_32 ( V_27 -> V_2 ,
V_30 , V_18 , V_27 ) ;
} else
V_20 = F_15 ( V_27 , V_24 , & V_26 ) ;
F_18 ( V_27 ) ;
}
if ( V_31 || ! V_20 )
return V_20 ;
return F_22 ( V_1 -> V_2 , V_30 , V_18 , V_24 , V_26 ) ;
}
