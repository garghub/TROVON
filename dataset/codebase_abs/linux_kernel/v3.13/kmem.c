void *
F_1 ( T_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
void * V_4 ;
T_1 V_5 = V_3 ;
while ( ! ( V_4 = F_2 ( V_5 ) ) ) {
if ( ( V_5 >>= 1 ) <= V_2 )
V_5 = V_2 ;
}
if ( V_4 )
* V_1 = V_5 ;
return V_4 ;
}
void *
F_3 ( T_1 V_1 , T_2 V_6 )
{
int V_7 = 0 ;
T_3 V_8 = F_4 ( V_6 ) ;
void * V_4 ;
do {
V_4 = F_5 ( V_1 , V_8 ) ;
if ( V_4 || ( V_6 & ( V_9 | V_10 ) ) )
return V_4 ;
if ( ! ( ++ V_7 % 100 ) )
F_6 ( NULL ,
L_1 ,
V_11 , V_8 ) ;
F_7 ( V_12 , V_13 / 50 ) ;
} while ( 1 );
}
void *
F_8 ( T_1 V_1 , T_2 V_6 )
{
void * V_4 ;
V_4 = F_9 ( V_1 , V_6 | V_9 ) ;
if ( V_4 )
return V_4 ;
return F_2 ( V_1 ) ;
}
void
F_10 ( const void * V_4 )
{
if ( ! F_11 ( V_4 ) ) {
F_12 ( V_4 ) ;
} else {
F_13 ( V_4 ) ;
}
}
void *
F_14 ( const void * V_4 , T_1 V_14 , T_1 V_15 ,
T_2 V_6 )
{
void * V_16 ;
V_16 = F_3 ( V_14 , V_6 ) ;
if ( V_4 ) {
if ( V_16 )
memcpy ( V_16 , V_4 ,
( ( V_15 < V_14 ) ? V_15 : V_14 ) ) ;
F_10 ( V_4 ) ;
}
return V_16 ;
}
void *
F_15 ( T_4 * V_17 , T_2 V_6 )
{
int V_7 = 0 ;
T_3 V_8 = F_4 ( V_6 ) ;
void * V_4 ;
do {
V_4 = F_16 ( V_17 , V_8 ) ;
if ( V_4 || ( V_6 & ( V_9 | V_10 ) ) )
return V_4 ;
if ( ! ( ++ V_7 % 100 ) )
F_6 ( NULL ,
L_1 ,
V_11 , V_8 ) ;
F_7 ( V_12 , V_13 / 50 ) ;
} while ( 1 );
}
