int F_1 ( T_1 * V_1 )
{
if( ! V_2 && ! ( V_2 = F_2 ( V_3 ) ) ) {
F_3 ( V_4 , V_5 ) ;
return 0 ;
}
if( ! F_4 ( V_2 , ( char * ) V_1 ) ) {
F_3 ( V_4 , V_5 ) ;
return 0 ;
}
return 1 ;
}
static int V_3 ( T_1 * * V_6 , T_1 * * V_7 )
{
return ( ( * V_6 ) -> V_8 - ( * V_7 ) -> V_8 ) ;
}
T_1 * F_5 ( int V_9 )
{
T_1 V_10 ;
int V_11 ;
V_10 . V_8 = V_9 ;
if( ! V_2 || ( V_10 . V_8 < 0 ) ) return NULL ;
V_11 = F_6 ( V_2 , ( char * ) & V_10 ) ;
if( V_11 == - 1 ) return NULL ;
return ( T_1 * ) F_7 ( V_2 , V_11 ) ;
}
T_1 * F_8 ( T_2 * V_1 )
{
int V_9 ;
if( ( V_9 = F_9 ( V_1 -> V_12 ) ) == V_13 ) return NULL ;
return F_5 ( V_9 ) ;
}
int F_10 ( T_1 * V_14 )
{
for(; V_14 -> V_8 != - 1 ; V_14 ++ )
if( ! F_1 ( V_14 ) ) return 0 ;
return 1 ;
}
int F_11 ( int V_15 , int V_16 )
{
T_1 * V_1 , * V_17 ;
if( ! ( V_1 = F_5 ( V_16 ) ) ) {
F_3 ( V_18 , V_19 ) ;
return 0 ;
}
if( ! ( V_17 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ) ) {
F_3 ( V_18 , V_5 ) ;
return 0 ;
}
* V_17 = * V_1 ;
V_17 -> V_8 = V_15 ;
V_17 -> V_20 |= V_21 ;
return 1 ;
}
void F_12 ( void )
{
F_13 ( V_2 , V_22 ) ;
V_2 = NULL ;
}
static void V_22 ( T_1 * V_1 )
{
if( V_1 -> V_20 & V_21 ) Free ( V_1 ) ;
}
int F_14 ( void )
{
F_10 ( V_23 ) ;
F_10 ( V_24 ) ;
F_1 ( & V_25 ) ;
F_1 ( & V_26 ) ;
F_1 ( & V_27 ) ;
F_1 ( & V_28 ) ;
F_1 ( & V_29 ) ;
F_1 ( & V_30 ) ;
F_1 ( & V_31 ) ;
F_1 ( & V_32 ) ;
F_1 ( & V_33 ) ;
F_1 ( & V_34 ) ;
F_1 ( & V_35 ) ;
F_1 ( & V_36 ) ;
return 1 ;
}
void * F_15 ( T_2 * V_1 )
{
T_1 * V_37 ;
unsigned char * V_38 ;
if( ! ( V_37 = F_8 ( V_1 ) ) || ! V_37 -> V_39 ) return NULL ;
V_38 = V_1 -> V_40 -> V_41 ;
return V_37 -> V_39 ( NULL , & V_38 , V_1 -> V_40 -> V_42 ) ;
}
