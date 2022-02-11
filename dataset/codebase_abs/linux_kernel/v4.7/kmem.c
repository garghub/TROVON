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
V_11 -> V_12 , V_11 -> V_13 ,
( unsigned int ) V_1 , V_14 , V_8 ) ;
F_7 ( V_15 , V_16 / 50 ) ;
} while ( 1 );
}
void *
F_8 ( T_1 V_1 , T_2 V_6 )
{
unsigned V_17 = 0 ;
void * V_4 ;
T_3 V_8 ;
V_4 = F_9 ( V_1 , V_6 | V_9 ) ;
if ( V_4 )
return V_4 ;
if ( ( V_11 -> V_6 & V_18 ) || ( V_6 & V_19 ) )
V_17 = F_10 () ;
V_8 = F_4 ( V_6 ) ;
V_4 = F_11 ( V_1 , V_8 | V_20 | V_21 , V_22 ) ;
if ( ( V_11 -> V_6 & V_18 ) || ( V_6 & V_19 ) )
F_12 ( V_17 ) ;
return V_4 ;
}
void *
F_13 ( const void * V_23 , T_1 V_24 , T_2 V_6 )
{
int V_7 = 0 ;
T_3 V_8 = F_4 ( V_6 ) ;
void * V_4 ;
do {
V_4 = F_14 ( V_23 , V_24 , V_8 ) ;
if ( V_4 || ( V_6 & ( V_9 | V_10 ) ) )
return V_4 ;
if ( ! ( ++ V_7 % 100 ) )
F_6 ( NULL ,
L_2 ,
V_11 -> V_12 , V_11 -> V_13 ,
V_24 , V_14 , V_8 ) ;
F_7 ( V_15 , V_16 / 50 ) ;
} while ( 1 );
}
void *
F_15 ( T_4 * V_25 , T_2 V_6 )
{
int V_7 = 0 ;
T_3 V_8 = F_4 ( V_6 ) ;
void * V_4 ;
do {
V_4 = F_16 ( V_25 , V_8 ) ;
if ( V_4 || ( V_6 & ( V_9 | V_10 ) ) )
return V_4 ;
if ( ! ( ++ V_7 % 100 ) )
F_6 ( NULL ,
L_3 ,
V_11 -> V_12 , V_11 -> V_13 ,
V_14 , V_8 ) ;
F_7 ( V_15 , V_16 / 50 ) ;
} while ( 1 );
}
