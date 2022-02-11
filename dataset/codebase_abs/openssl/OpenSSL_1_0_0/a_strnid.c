void F_1 ( unsigned long V_1 )
{
V_2 = V_1 ;
}
unsigned long F_2 ( void )
{
return V_2 ;
}
int F_3 ( char * V_3 )
{
unsigned long V_1 ;
char * V_4 ;
if( ! strncmp ( V_3 , L_1 , 5 ) ) {
if( ! V_3 [ 5 ] ) return 0 ;
V_1 = strtoul ( V_3 + 5 , & V_4 , 0 ) ;
if( * V_4 ) return 0 ;
} else if( ! strcmp ( V_3 , L_2 ) )
V_1 = ~ ( ( unsigned long ) ( V_5 | V_6 ) ) ;
else if( ! strcmp ( V_3 , L_3 ) )
V_1 = ~ ( ( unsigned long ) V_7 ) ;
else if( ! strcmp ( V_3 , L_4 ) ) V_1 = V_6 ;
else if( ! strcmp ( V_3 , L_5 ) )
V_1 = 0xFFFFFFFFL ;
else return 0 ;
F_1 ( V_1 ) ;
return 1 ;
}
T_1 * F_4 ( T_1 * * V_8 , const unsigned char * V_9 ,
int V_10 , int V_11 , int V_12 )
{
T_2 * V_13 ;
T_1 * V_14 = NULL ;
unsigned long V_1 ;
int V_15 ;
if( ! V_8 ) V_8 = & V_14 ;
V_13 = F_5 ( V_12 ) ;
if( V_13 ) {
V_1 = V_13 -> V_1 ;
if( ! ( V_13 -> V_16 & V_17 ) ) V_1 &= V_2 ;
V_15 = F_6 ( V_8 , V_9 , V_10 , V_11 , V_1 ,
V_13 -> V_18 , V_13 -> V_19 ) ;
} else V_15 = F_7 ( V_8 , V_9 , V_10 , V_11 , V_20 & V_2 ) ;
if( V_15 <= 0 ) return NULL ;
return * V_8 ;
}
static int F_8 ( const T_2 * const * V_21 ,
const T_2 * const * V_22 )
{
return ( * V_21 ) -> V_12 - ( * V_22 ) -> V_12 ;
}
static int F_9 ( const T_2 * V_21 , const T_2 * V_22 )
{
return V_21 -> V_12 - V_22 -> V_12 ;
}
T_2 * F_5 ( int V_12 )
{
int V_23 ;
T_2 * V_24 ;
T_2 V_25 ;
V_25 . V_12 = V_12 ;
V_24 = F_10 ( & V_25 , V_26 ,
sizeof( V_26 ) / sizeof( T_2 ) ) ;
if( V_24 ) return V_24 ;
if( ! V_27 ) return NULL ;
V_23 = F_11 ( V_27 , & V_25 ) ;
if( V_23 < 0 ) return NULL ;
return F_12 ( V_27 , V_23 ) ;
}
int F_13 ( int V_12 ,
long V_18 , long V_19 , unsigned long V_1 ,
unsigned long V_16 )
{
T_2 * V_28 ;
char V_29 = 0 ;
V_16 &= ~ V_30 ;
if( ! V_27 ) V_27 = F_14 ( F_8 ) ;
if( ! V_27 ) {
F_15 ( V_31 , V_32 ) ;
return 0 ;
}
if( ! ( V_28 = F_5 ( V_12 ) ) ) {
V_28 = F_16 ( sizeof( T_2 ) ) ;
if( ! V_28 ) {
F_15 ( V_31 ,
V_32 ) ;
return 0 ;
}
V_28 -> V_16 = V_16 | V_30 ;
V_28 -> V_12 = V_12 ;
V_29 = 1 ;
} else V_28 -> V_16 = ( V_28 -> V_16 & V_30 ) | V_16 ;
if( V_18 != - 1 ) V_28 -> V_18 = V_18 ;
if( V_19 != - 1 ) V_28 -> V_19 = V_19 ;
V_28 -> V_1 = V_1 ;
if( V_29 ) F_17 ( V_27 , V_28 ) ;
return 1 ;
}
void F_18 ( void )
{
F_19 ( T_2 ) * V_28 ;
V_28 = V_27 ;
if( ! V_28 ) return;
V_27 = NULL ;
F_20 ( V_28 , V_33 ) ;
}
static void V_33 ( T_2 * V_13 )
{
if( V_13 -> V_16 & V_30 ) F_21 ( V_13 ) ;
}
