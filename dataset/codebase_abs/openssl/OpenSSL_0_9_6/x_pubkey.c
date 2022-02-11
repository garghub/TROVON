int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_6 () ;
}
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_7 )
{
F_8 ( V_1 , T_1 * , V_8 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_9 -> V_3 , V_10 ) ;
F_11 ( V_9 -> V_5 , V_11 ) ;
if ( V_9 -> V_12 != NULL )
{
F_12 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
}
F_13 ( V_1 , V_13 , V_14 ) ;
}
T_1 * V_8 ( void )
{
T_1 * V_9 = NULL ;
T_2 V_15 ;
F_14 ( V_9 , T_1 ) ;
F_15 ( V_9 -> V_3 , V_16 ) ;
F_15 ( V_9 -> V_5 , V_17 ) ;
V_9 -> V_12 = NULL ;
return ( V_9 ) ;
F_16 ( V_18 ) ;
}
void V_13 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_17 ( V_1 -> V_3 ) ;
F_18 ( V_1 -> V_5 ) ;
if ( V_1 -> V_12 != NULL ) F_12 ( V_1 -> V_12 ) ;
F_19 ( V_1 ) ;
}
int F_20 ( T_1 * * V_19 , T_3 * V_12 )
{
int V_20 = 0 ;
T_1 * V_21 ;
T_4 * V_1 ;
T_5 * V_22 ;
unsigned char * V_23 , * V_24 ;
int V_25 ;
if ( V_19 == NULL ) return ( 0 ) ;
if ( ( V_21 = V_8 () ) == NULL ) goto V_26;
V_1 = V_21 -> V_3 ;
if ( ( V_22 = F_21 ( V_12 -> type ) ) == NULL ) goto V_26;
F_22 ( V_1 -> V_27 ) ;
V_1 -> V_27 = V_22 ;
if ( ! V_12 -> V_28 || ( V_12 -> type == V_29 ) )
{
if ( ( V_1 -> V_30 == NULL ) ||
( V_1 -> V_30 -> type != V_31 ) )
{
F_23 ( V_1 -> V_30 ) ;
V_1 -> V_30 = F_24 () ;
V_1 -> V_30 -> type = V_31 ;
}
}
else
#ifndef F_25
if ( V_12 -> type == V_32 )
{
unsigned char * V_2 ;
T_6 * V_33 ;
V_33 = V_12 -> V_12 . V_33 ;
V_33 -> V_34 = 0 ;
F_23 ( V_1 -> V_30 ) ;
V_25 = F_26 ( V_33 , NULL ) ;
V_24 = ( unsigned char * ) F_27 ( V_25 ) ;
V_2 = V_24 ;
F_26 ( V_33 , & V_2 ) ;
V_1 -> V_30 = F_24 () ;
V_1 -> V_30 -> type = V_35 ;
V_1 -> V_30 -> V_36 . V_37 = F_28 () ;
F_29 ( V_1 -> V_30 -> V_36 . V_37 , V_24 , V_25 ) ;
F_19 ( V_24 ) ;
}
else
#endif
{
F_30 ( V_38 , V_39 ) ;
goto V_26;
}
if ( ( V_25 = F_31 ( V_12 , NULL ) ) <= 0 ) goto V_26;
if ( ( V_23 = ( unsigned char * ) F_27 ( V_25 + 1 ) ) == NULL ) goto V_26;
V_24 = V_23 ;
F_31 ( V_12 , & V_24 ) ;
if ( ! F_32 ( V_21 -> V_5 , V_23 , V_25 ) ) goto V_26;
V_21 -> V_5 -> V_40 &= ~ ( V_41 | 0x07 ) ;
V_21 -> V_5 -> V_40 |= V_41 ;
F_19 ( V_23 ) ;
#if 0
CRYPTO_add(&pkey->references,1,CRYPTO_LOCK_EVP_PKEY);
pk->pkey=pkey;
#endif
if ( * V_19 != NULL )
V_13 ( * V_19 ) ;
* V_19 = V_21 ;
V_21 = NULL ;
V_20 = 1 ;
V_26:
if ( V_21 != NULL ) V_13 ( V_21 ) ;
return ( V_20 ) ;
}
T_3 * F_33 ( T_1 * V_42 )
{
T_3 * V_9 = NULL ;
long V_43 ;
int type ;
unsigned char * V_24 ;
#ifndef F_25
T_4 * V_1 ;
#endif
if ( V_42 == NULL ) goto V_26;
if ( V_42 -> V_12 != NULL )
{
F_34 ( & V_42 -> V_12 -> V_44 , 1 , V_45 ) ;
return ( V_42 -> V_12 ) ;
}
if ( V_42 -> V_5 == NULL ) goto V_26;
type = F_35 ( V_42 -> V_3 -> V_27 ) ;
V_24 = V_42 -> V_5 -> V_46 ;
V_43 = V_42 -> V_5 -> V_7 ;
if ( ( V_9 = F_36 ( type , NULL , & V_24 , ( long ) V_43 ) ) == NULL )
{
F_30 ( V_47 , V_48 ) ;
goto V_26;
}
V_9 -> V_28 = 0 ;
#ifndef F_25
V_1 = V_42 -> V_3 ;
if ( V_9 -> type == V_32 )
{
if ( V_1 -> V_30 -> type == V_35 )
{
V_9 -> V_12 . V_33 -> V_34 = 0 ;
V_24 = V_1 -> V_30 -> V_36 . V_37 -> V_46 ;
V_43 = V_1 -> V_30 -> V_36 . V_37 -> V_7 ;
if ( ! F_37 ( & V_9 -> V_12 . V_33 , & V_24 , ( long ) V_43 ) )
goto V_26;
}
V_9 -> V_28 = 1 ;
}
#endif
V_42 -> V_12 = V_9 ;
F_34 ( & V_9 -> V_44 , 1 , V_45 ) ;
return ( V_9 ) ;
V_26:
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( NULL ) ;
}
T_3 * F_38 ( T_3 * * V_1 , unsigned char * * V_2 ,
long V_7 )
{
T_1 * V_49 ;
T_3 * V_50 ;
V_49 = F_7 ( NULL , V_2 , V_7 ) ;
if( ! V_49 ) return NULL ;
V_50 = F_33 ( V_49 ) ;
V_13 ( V_49 ) ;
if( ! V_50 ) return NULL ;
if( V_1 ) {
F_12 ( * V_1 ) ;
* V_1 = V_50 ;
}
return V_50 ;
}
int F_39 ( T_3 * V_1 , unsigned char * * V_2 )
{
T_1 * V_49 = NULL ;
int V_9 ;
if( ! V_1 ) return 0 ;
if( ! F_20 ( & V_49 , V_1 ) ) return 0 ;
V_9 = F_1 ( V_49 , V_2 ) ;
V_13 ( V_49 ) ;
return V_9 ;
}
T_7 * F_40 ( T_7 * * V_1 , unsigned char * * V_2 ,
long V_7 )
{
T_3 * V_12 ;
T_7 * V_42 ;
unsigned char * V_51 ;
V_51 = * V_2 ;
V_12 = F_38 ( NULL , & V_51 , V_7 ) ;
if( ! V_12 ) return NULL ;
V_42 = F_41 ( V_12 ) ;
F_12 ( V_12 ) ;
if( ! V_42 ) return NULL ;
* V_2 = V_51 ;
if( V_1 ) {
F_42 ( * V_1 ) ;
* V_1 = V_42 ;
}
return V_42 ;
}
int F_43 ( T_7 * V_1 , unsigned char * * V_2 )
{
T_3 * V_50 ;
int V_9 ;
if( ! V_1 ) return 0 ;
V_50 = F_44 () ;
if( ! V_50 ) {
F_45 ( V_52 , V_53 ) ;
return 0 ;
}
F_46 ( V_50 , V_1 ) ;
V_9 = F_39 ( V_50 , V_2 ) ;
F_12 ( V_50 ) ;
return V_9 ;
}
T_6 * F_47 ( T_6 * * V_1 , unsigned char * * V_2 ,
long V_7 )
{
T_3 * V_12 ;
T_6 * V_42 ;
unsigned char * V_51 ;
V_51 = * V_2 ;
V_12 = F_38 ( NULL , & V_51 , V_7 ) ;
if( ! V_12 ) return NULL ;
V_42 = F_48 ( V_12 ) ;
F_12 ( V_12 ) ;
if( ! V_42 ) return NULL ;
* V_2 = V_51 ;
if( V_1 ) {
F_49 ( * V_1 ) ;
* V_1 = V_42 ;
}
return V_42 ;
}
int F_50 ( T_6 * V_1 , unsigned char * * V_2 )
{
T_3 * V_50 ;
int V_9 ;
if( ! V_1 ) return 0 ;
V_50 = F_44 () ;
if( ! V_50 ) {
F_45 ( V_54 , V_53 ) ;
return 0 ;
}
F_51 ( V_50 , V_1 ) ;
V_9 = F_39 ( V_50 , V_2 ) ;
F_12 ( V_50 ) ;
return V_9 ;
}
