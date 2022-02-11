int F_1 ( T_1 * V_1 , const char * V_2 )
{
int V_3 ;
F_2 ( V_1 , - 1 , V_2 ) ;
V_3 = ( int ) F_3 ( V_1 , - 1 ) ;
F_4 ( V_1 , 1 ) ;
return V_3 ;
}
void F_5 ( T_1 * V_1 , const char * V_2 , int V_3 )
{
F_6 ( V_1 , V_3 ) ;
F_7 ( V_1 , - 2 , V_2 ) ;
}
void * F_8 ( T_1 * V_1 , T_2 V_4 ) {
void * V_5 ;
T_3 V_6 = F_9 ( V_1 , & V_5 ) ;
return V_6 ( V_5 , NULL , 0 , V_4 ) ;
}
void * F_10 ( T_1 * V_1 , void * V_7 , T_2 V_8 , T_2 V_9 ) {
void * V_5 ;
T_3 V_6 = F_9 ( V_1 , & V_5 ) ;
return V_6 ( V_5 , V_7 , V_8 , V_9 ) ;
}
void F_11 ( T_1 * V_1 , void * V_7 , T_2 V_8 ) {
void * V_5 ;
T_3 V_6 = F_9 ( V_1 , & V_5 ) ;
V_6 ( V_5 , V_7 , V_8 , 0 ) ;
}
int F_12 ( T_1 * V_1 , const T_4 * * V_10 ) {
const T_4 * V_7 ;
const T_4 * * V_11 ;
int V_12 = F_13 ( V_1 ) ;
if( V_12 == 0 )
F_14 ( V_1 ) ;
else {
if( ! F_15 ( V_1 , 1 ) )
F_16 ( V_1 , 1 , L_1 ) ;
if( V_12 > 1 )
F_17 ( V_1 , 1 ) ;
}
for( V_11 = V_10 ; * V_11 ; ++ V_11 ) {
for( V_7 = * V_11 ; V_7 -> V_13 ; ++ V_7 ) {
F_18 ( V_1 , V_7 -> V_13 ) ;
F_6 ( V_1 , V_7 -> V_3 ) ;
F_19 ( V_1 , - 3 ) ;
}
}
return 1 ;
}
const char * F_20 ( const T_4 * V_14 , int V_3 ) {
for (; V_14 -> V_13 ; ++ V_14 ) {
if ( V_14 -> V_3 == V_3 )
return V_14 -> V_13 ;
}
return NULL ;
}
void F_21 ( T_5 * V_15 ) {
V_15 -> V_16 = 0 ;
}
void F_22 ( T_5 * V_15 , T_6 * V_17 ) {
V_15 -> V_18 [ V_15 -> V_16 ++ ] = V_17 ;
}
void F_23 ( T_5 * V_15 ) {
while ( V_15 -> V_16 > 0 )
F_24 ( V_15 -> V_18 [ -- V_15 -> V_16 ] ) ;
}
void F_25 ( T_6 * V_17 , T_2 V_19 , T_1 * V_1 , T_5 * V_15 ) {
V_17 -> V_20 = ( char * ) F_8 ( V_1 , V_19 ) ;
if ( ! V_17 -> V_20 ) {
F_23 ( V_15 ) ;
F_26 ( V_1 , L_2 ) ;
return;
}
V_17 -> V_4 = V_19 ;
V_17 -> V_16 = 0 ;
V_17 -> V_1 = V_1 ;
V_17 -> V_21 = V_15 ;
F_22 ( V_15 , V_17 ) ;
}
void F_24 ( T_6 * V_17 ) {
F_11 ( V_17 -> V_1 , V_17 -> V_20 , V_17 -> V_4 ) ;
}
void F_27 ( T_6 * V_17 ) {
V_17 -> V_16 = 0 ;
}
void F_28 ( T_6 * V_17 ) {
F_29 ( V_17 -> V_1 , V_17 -> V_20 , V_17 -> V_16 ) ;
}
void F_30 ( T_6 * V_22 , T_6 * V_23 ) {
F_31 ( V_22 , V_23 -> V_20 , V_23 -> V_16 ) ;
}
void F_31 ( T_6 * V_17 , const void * V_23 , T_2 V_19 ) {
T_2 V_24 = V_17 -> V_16 + V_19 ;
if ( V_24 > V_17 -> V_4 ) {
char * V_7 = ( char * ) F_10 ( V_17 -> V_1 , V_17 -> V_20 , V_17 -> V_4 , 2 * V_24 ) ;
if ( ! V_7 ) {
F_23 ( V_17 -> V_21 ) ;
F_26 ( V_17 -> V_1 , L_3 ) ;
return;
}
V_17 -> V_20 = V_7 ;
V_17 -> V_4 = 2 * V_24 ;
}
if ( V_23 )
memcpy ( V_17 -> V_20 + V_17 -> V_16 , V_23 , V_19 ) ;
V_17 -> V_16 = V_24 ;
}
void F_32 ( T_6 * V_17 , int V_25 ) {
T_2 V_26 ;
const char * V_7 = F_33 ( V_17 -> V_1 , V_25 , & V_26 ) ;
F_31 ( V_17 , V_7 , V_26 ) ;
}
void F_34 ( T_6 * V_17 , const void * V_23 , T_2 V_26 ) {
int V_27 ;
T_2 V_28 [ 2 ] = { V_29 } ;
V_28 [ 1 ] = V_26 ;
F_31 ( V_17 , V_28 , sizeof ( V_28 ) ) ;
F_31 ( V_17 , V_23 , V_26 ) ;
V_27 = ( int ) ( V_26 % V_30 ) ;
if ( V_27 ) F_31 ( V_17 , NULL , V_30 - V_27 ) ;
}
void F_35 ( T_6 * V_17 , T_2 V_31 ) {
T_2 V_28 [ 2 ] = { V_32 } ;
V_28 [ 1 ] = V_31 ;
F_31 ( V_17 , V_28 , sizeof ( V_28 ) ) ;
}
void F_36 ( T_6 * V_33 , int V_34 , int V_35 ) {
char V_36 [] = { 0 , 0 } ;
T_2 V_37 ;
const char * V_7 = F_33 ( V_33 -> V_1 , V_34 , & V_37 ) ;
const char * V_38 = V_7 + V_37 ;
V_33 -> V_16 = 0 ;
while ( V_7 < V_38 ) {
const char * V_39 ;
for ( V_39 = V_7 ; V_39 < V_38 && * V_39 != '%' ; ++ V_39 )
{}
if ( V_39 != V_7 )
F_34 ( V_33 , V_7 , V_39 - V_7 ) ;
if ( V_39 < V_38 ) {
if ( ++ V_39 < V_38 ) {
if ( isdigit ( * V_39 ) ) {
int V_31 ;
* V_36 = * V_39 ;
V_31 = ( int ) strtol ( V_36 , NULL , 10 ) ;
if ( V_31 == 1 && V_35 == 0 )
V_31 = 0 ;
else if ( V_31 > V_35 ) {
F_23 ( V_33 -> V_21 ) ;
F_26 ( V_33 -> V_1 , L_4 ) ;
return;
}
F_35 ( V_33 , V_31 ) ;
}
else F_34 ( V_33 , V_39 , 1 ) ;
}
V_7 = V_39 + 1 ;
}
else break;
}
}
int F_37 ( T_6 * V_17 , T_2 * V_40 , T_2 * V_31 , const char * * V_41 ) {
if ( * V_40 < V_17 -> V_16 ) {
T_2 * V_42 = ( T_2 * ) ( void * ) ( V_17 -> V_20 + * V_40 ) ;
* V_31 = V_42 [ 1 ] ;
* V_40 += 2 * sizeof ( T_2 ) ;
* V_41 = NULL ;
if ( * V_42 == V_29 ) {
int V_27 ;
* V_41 = V_17 -> V_20 + * V_40 ;
* V_40 += * V_31 ;
V_27 = ( int ) ( * V_40 % V_30 ) ;
if ( V_27 ) * V_40 += ( V_30 - V_27 ) ;
}
return 1 ;
}
return 0 ;
}
int F_38 ( T_1 * V_1 , int V_43 , const char * V_44 ) {
const char * V_45 = F_39 ( V_1 , L_5 ,
V_44 , F_40 ( V_1 , V_43 ) ) ;
return F_16 ( V_1 , V_43 , V_45 ) ;
}
