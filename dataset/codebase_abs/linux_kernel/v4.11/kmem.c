void *
F_1 ( T_1 V_1 , T_2 V_2 )
{
int V_3 = 0 ;
T_3 V_4 = F_2 ( V_2 ) ;
void * V_5 ;
do {
V_5 = F_3 ( V_1 , V_4 ) ;
if ( V_5 || ( V_2 & ( V_6 | V_7 ) ) )
return V_5 ;
if ( ! ( ++ V_3 % 100 ) )
F_4 ( NULL ,
L_1 ,
V_8 -> V_9 , V_8 -> V_10 ,
( unsigned int ) V_1 , V_11 , V_4 ) ;
F_5 ( V_12 , V_13 / 50 ) ;
} while ( 1 );
}
void *
F_6 ( T_1 V_1 , T_2 V_2 )
{
unsigned V_14 = 0 ;
void * V_5 ;
T_3 V_4 ;
V_5 = F_7 ( V_1 , V_2 | V_6 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_8 -> V_2 & V_15 ) || ( V_2 & V_16 ) )
V_14 = F_8 () ;
V_4 = F_2 ( V_2 ) ;
V_5 = F_9 ( V_1 , V_4 | V_17 | V_18 , V_19 ) ;
if ( ( V_8 -> V_2 & V_15 ) || ( V_2 & V_16 ) )
F_10 ( V_14 ) ;
return V_5 ;
}
void *
F_11 ( const void * V_20 , T_1 V_21 , T_2 V_2 )
{
int V_3 = 0 ;
T_3 V_4 = F_2 ( V_2 ) ;
void * V_5 ;
do {
V_5 = F_12 ( V_20 , V_21 , V_4 ) ;
if ( V_5 || ( V_2 & ( V_6 | V_7 ) ) )
return V_5 ;
if ( ! ( ++ V_3 % 100 ) )
F_4 ( NULL ,
L_2 ,
V_8 -> V_9 , V_8 -> V_10 ,
V_21 , V_11 , V_4 ) ;
F_5 ( V_12 , V_13 / 50 ) ;
} while ( 1 );
}
void *
F_13 ( T_4 * V_22 , T_2 V_2 )
{
int V_3 = 0 ;
T_3 V_4 = F_2 ( V_2 ) ;
void * V_5 ;
do {
V_5 = F_14 ( V_22 , V_4 ) ;
if ( V_5 || ( V_2 & ( V_6 | V_7 ) ) )
return V_5 ;
if ( ! ( ++ V_3 % 100 ) )
F_4 ( NULL ,
L_3 ,
V_8 -> V_9 , V_8 -> V_10 ,
V_11 , V_4 ) ;
F_5 ( V_12 , V_13 / 50 ) ;
} while ( 1 );
}
