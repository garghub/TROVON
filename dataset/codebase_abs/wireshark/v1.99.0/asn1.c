void F_1 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_4 * V_4 ) {
memset ( V_1 , '\0' , sizeof( * V_1 ) ) ;
V_1 -> V_5 = V_6 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_4 = V_4 ;
}
T_3 F_2 ( T_1 * V_1 ) {
return V_1 && ( V_1 -> V_5 == V_6 ) ;
}
void F_3 ( T_1 * V_1 ) {
memset ( & V_1 -> V_7 , '\0' , sizeof( V_1 -> V_7 ) ) ;
V_1 -> V_7 . V_8 = - 1 ;
V_1 -> V_7 . V_2 = - 1 ;
}
void F_4 ( T_1 * V_1 ) {
memset ( & V_1 -> V_9 , '\0' , sizeof( V_1 -> V_9 ) ) ;
V_1 -> V_9 . V_8 = - 1 ;
V_1 -> V_9 . V_10 = - 1 ;
}
void F_5 ( T_1 * V_1 , const T_5 * V_11 ) {
T_6 * V_12 ;
V_12 = F_6 ( T_6 ) ;
V_12 -> V_11 = V_11 ;
V_12 -> V_13 = V_1 -> V_14 ;
V_1 -> V_14 = V_12 ;
}
void F_7 ( T_1 * V_1 , const T_5 * V_11 ) {
F_8 ( V_1 -> V_14 ) ;
F_8 ( ! strcmp ( V_1 -> V_14 -> V_11 , V_11 ) ) ;
V_1 -> V_14 = V_1 -> V_14 -> V_13 ;
}
void F_9 ( T_1 * V_1 , const T_5 * V_11 , const T_7 * V_15 ) {
const T_7 * V_16 = V_15 ;
T_8 * V_17 ;
F_8 ( V_1 -> V_14 ) ;
F_8 ( ! strcmp ( V_1 -> V_14 -> V_11 , V_11 ) ) ;
V_17 = V_1 -> V_14 -> V_17 ;
while ( V_16 -> V_11 ) {
F_8 ( V_17 ) ;
F_8 ( ( V_16 -> V_18 == V_19 ) || ( V_17 -> V_18 == V_16 -> V_18 ) ) ;
V_17 -> V_11 = V_16 -> V_11 ;
V_16 ++ ;
V_17 = V_17 -> V_13 ;
}
F_8 ( ! V_17 ) ;
}
static T_8 * F_10 ( T_1 * V_1 , const T_5 * V_11 ) {
T_8 * V_17 = NULL ;
F_8 ( V_1 -> V_14 ) ;
V_17 = V_1 -> V_14 -> V_17 ;
while ( V_17 ) {
if ( ! strcmp ( V_17 -> V_11 , V_11 ) )
return V_17 ;
V_17 = V_17 -> V_13 ;
}
return V_17 ;
}
static T_8 * F_11 ( T_1 * V_1 ) {
T_8 * V_17 , * * V_20 ;
F_8 ( V_1 -> V_14 ) ;
V_17 = F_6 ( T_8 ) ;
V_20 = & ( V_1 -> V_14 -> V_17 ) ;
while ( * V_20 )
V_20 = & ( ( * V_20 ) -> V_13 ) ;
* V_20 = V_17 ;
return V_17 ;
}
void F_12 ( T_1 * V_1 , T_3 V_21 ) {
T_8 * V_17 ;
V_17 = F_11 ( V_1 ) ;
V_17 -> V_18 = V_22 ;
V_17 -> V_21 . V_23 = V_21 ;
}
void F_13 ( T_1 * V_1 , T_9 V_21 ) {
T_8 * V_17 ;
V_17 = F_11 ( V_1 ) ;
V_17 -> V_18 = V_24 ;
V_17 -> V_21 . V_25 = V_21 ;
}
T_3 F_14 ( T_1 * V_1 , const T_5 * V_11 ) {
T_8 * V_17 = NULL ;
V_17 = F_10 ( V_1 , V_11 ) ;
F_8 ( V_17 ) ;
return V_17 -> V_21 . V_23 ;
}
T_9 F_15 ( T_1 * V_1 , const T_5 * V_11 ) {
T_8 * V_17 = NULL ;
V_17 = F_10 ( V_1 , V_11 ) ;
F_8 ( V_17 ) ;
return V_17 -> V_21 . V_25 ;
}
void F_16 ( T_10 * V_26 ) {
memset ( V_26 , '\0' , sizeof( * V_26 ) ) ;
V_26 -> V_5 = V_27 ;
}
T_3 F_17 ( T_10 * V_26 ) {
return V_26 && ( V_26 -> V_5 == V_27 ) ;
}
void F_18 ( T_10 * V_26 ) {
memset ( & V_26 -> V_28 , '\0' , sizeof( V_26 -> V_28 ) ) ;
V_26 -> V_28 . V_29 = - 1 ;
}
T_1 * F_19 ( void * V_30 ) {
T_1 * V_1 = ( T_1 * ) V_30 ;
if ( ! F_2 ( V_1 ) )
V_1 = NULL ;
return V_1 ;
}
T_10 * F_20 ( void * V_30 ) {
T_10 * V_26 = ( T_10 * ) V_30 ;
T_1 * V_1 = ( T_1 * ) V_30 ;
if ( ! F_2 ( V_1 ) )
V_1 = NULL ;
if ( V_1 )
V_26 = V_1 -> V_31 ;
if ( ! F_17 ( V_26 ) )
V_26 = NULL ;
return V_26 ;
}
double F_21 ( const T_11 * V_32 , T_12 V_33 ) {
T_11 V_34 ;
const T_11 * V_35 ;
T_11 * V_36 ;
double V_37 = 0 ;
if ( V_33 < 1 ) return V_37 ;
V_34 = V_32 [ 0 ] ;
V_35 = V_32 + 1 ;
V_33 -= 1 ;
if ( V_34 & 0x80 ) {
} else if ( V_34 & 0x40 ) {
switch ( V_34 & 0x3F ) {
case 0x00 : V_37 = V_38 ; break;
case 0x01 : V_37 = - V_38 ; break;
}
} else {
V_36 = F_22 ( V_35 , V_33 ) ;
V_37 = atof ( V_36 ) ;
}
return V_37 ;
}
