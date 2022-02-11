static void F_1 ( T_1 * V_1 )
{
unsigned int V_2 = 0 , V_3 = 0 ;
T_2 * V_4 = V_1 -> V_5 . V_6 ;
T_3 * V_7 = & V_1 -> V_7 ;
fprintf ( V_8 , L_1 , ( unsigned int ) V_1 ) ;
while( V_2 < V_1 -> V_9 )
{
fprintf ( V_8 , L_2 , V_4 -> V_10 [ V_2 ++ % V_11 ] . V_12 ) ;
if( ! ( V_2 % V_11 ) )
V_4 = V_4 -> V_13 ;
}
fprintf ( V_8 , L_3 ) ;
V_2 = 0 ;
fprintf ( V_8 , L_4 ) ;
while( V_3 < V_7 -> V_14 )
{
while( V_2 ++ < V_7 -> V_15 [ V_3 ] )
fprintf ( V_8 , L_5 ) ;
fprintf ( V_8 , L_6 ) ;
V_2 ++ ;
V_3 ++ ;
}
fprintf ( V_8 , L_3 ) ;
}
void F_2 ( T_1 * V_1 )
{
F_3 ( & V_1 -> V_5 ) ;
F_4 ( & V_1 -> V_7 ) ;
V_1 -> V_9 = 0 ;
V_1 -> V_16 = 0 ;
V_1 -> V_17 = 0 ;
}
T_1 * F_5 ( void )
{
T_1 * V_18 = F_6 ( sizeof( T_1 ) ) ;
if( ! V_18 )
{
F_7 ( V_19 , V_20 ) ;
return NULL ;
}
F_8 ( & V_18 -> V_5 ) ;
F_9 ( & V_18 -> V_7 ) ;
V_18 -> V_9 = 0 ;
V_18 -> V_16 = 0 ;
V_18 -> V_17 = 0 ;
return V_18 ;
}
void F_10 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
#ifdef F_11
{
T_2 * V_5 = V_1 -> V_5 . V_6 ;
fprintf ( V_8 , L_7 ,
V_1 -> V_7 . V_21 , V_1 -> V_5 . V_21 ) ;
fprintf ( V_8 , L_8 ) ;
while( V_5 ) {
unsigned V_22 = 0 ;
while( V_22 < V_11 )
fprintf ( V_8 , L_2 , V_5 -> V_10 [ V_22 ++ ] . V_12 ) ;
V_5 = V_5 -> V_13 ;
}
fprintf ( V_8 , L_3 ) ;
}
#endif
F_12 ( & V_1 -> V_7 ) ;
F_13 ( & V_1 -> V_5 ) ;
F_14 ( V_1 ) ;
}
void F_15 ( T_1 * V_1 )
{
F_16 ( L_9 , V_1 ) ;
if( V_1 -> V_16 || V_1 -> V_17 )
V_1 -> V_16 ++ ;
else if( ! F_17 ( & V_1 -> V_7 , V_1 -> V_9 ) )
{
F_7 ( V_23 , V_24 ) ;
V_1 -> V_16 ++ ;
}
F_18 ( V_1 ) ;
}
void F_19 ( T_1 * V_1 )
{
F_16 ( L_10 , V_1 ) ;
if( V_1 -> V_16 )
V_1 -> V_16 -- ;
else
{
unsigned int V_25 = F_20 ( & V_1 -> V_7 ) ;
if( V_25 < V_1 -> V_9 )
F_21 ( & V_1 -> V_5 , V_1 -> V_9 - V_25 ) ;
V_1 -> V_9 = V_25 ;
V_1 -> V_17 = 0 ;
}
F_18 ( V_1 ) ;
}
T_4 * F_22 ( T_1 * V_1 )
{
T_4 * V_18 ;
F_16 ( L_11 , V_1 ) ;
if( V_1 -> V_16 || V_1 -> V_17 ) return NULL ;
if( ( V_18 = F_23 ( & V_1 -> V_5 ) ) == NULL )
{
V_1 -> V_17 = 1 ;
F_7 ( V_26 , V_24 ) ;
return NULL ;
}
F_24 ( V_18 ) ;
V_1 -> V_9 ++ ;
F_25 ( V_1 , V_18 ) ;
return V_18 ;
}
static void F_9 ( T_3 * V_27 )
{
V_27 -> V_15 = NULL ;
V_27 -> V_14 = V_27 -> V_21 = 0 ;
}
static void F_12 ( T_3 * V_27 )
{
if( V_27 -> V_21 ) F_14 ( V_27 -> V_15 ) ;
}
static void F_4 ( T_3 * V_27 )
{
V_27 -> V_14 = 0 ;
}
static int F_17 ( T_3 * V_27 , unsigned int V_28 )
{
if( V_27 -> V_14 == V_27 -> V_21 )
{
unsigned int V_29 = ( V_27 -> V_21 ?
( V_27 -> V_21 * 3 / 2 ) : V_30 ) ;
unsigned int * V_31 = F_6 ( V_29 *
sizeof( unsigned int ) ) ;
if( ! V_31 ) return 0 ;
if( V_27 -> V_14 )
memcpy ( V_31 , V_27 -> V_15 , V_27 -> V_14 *
sizeof( unsigned int ) ) ;
if( V_27 -> V_21 ) F_14 ( V_27 -> V_15 ) ;
V_27 -> V_15 = V_31 ;
V_27 -> V_21 = V_29 ;
}
V_27 -> V_15 [ ( V_27 -> V_14 ) ++ ] = V_28 ;
return 1 ;
}
static unsigned int F_20 ( T_3 * V_27 )
{
return V_27 -> V_15 [ -- ( V_27 -> V_14 ) ] ;
}
static void F_8 ( T_5 * V_32 )
{
V_32 -> V_6 = V_32 -> V_33 = V_32 -> V_34 = NULL ;
V_32 -> V_9 = V_32 -> V_21 = 0 ;
}
static void F_13 ( T_5 * V_32 )
{
while( V_32 -> V_6 )
{
unsigned int V_22 = 0 ;
T_4 * V_35 = V_32 -> V_6 -> V_10 ;
while( V_22 ++ < V_11 )
{
if( V_35 -> V_36 ) F_26 ( V_35 ) ;
V_35 ++ ;
}
V_32 -> V_33 = V_32 -> V_6 -> V_13 ;
F_14 ( V_32 -> V_6 ) ;
V_32 -> V_6 = V_32 -> V_33 ;
}
}
static void F_3 ( T_5 * V_32 )
{
T_2 * V_4 = V_32 -> V_6 ;
while( V_4 )
{
unsigned int V_22 = 0 ;
T_4 * V_35 = V_4 -> V_10 ;
while( V_22 ++ < V_11 )
{
if( V_35 -> V_36 ) F_27 ( V_35 ) ;
V_35 ++ ;
}
V_4 = V_4 -> V_13 ;
}
V_32 -> V_33 = V_32 -> V_6 ;
V_32 -> V_9 = 0 ;
}
static T_4 * F_23 ( T_5 * V_32 )
{
if( V_32 -> V_9 == V_32 -> V_21 )
{
T_4 * V_35 ;
unsigned int V_22 = 0 ;
T_2 * V_4 = F_6 ( sizeof( T_2 ) ) ;
if( ! V_4 ) return NULL ;
V_35 = V_4 -> V_10 ;
while( V_22 ++ < V_11 )
F_28 ( V_35 ++ ) ;
V_4 -> V_37 = V_32 -> V_34 ;
V_4 -> V_13 = NULL ;
if( ! V_32 -> V_6 )
V_32 -> V_6 = V_32 -> V_33 = V_32 -> V_34 = V_4 ;
else
{
V_32 -> V_34 -> V_13 = V_4 ;
V_32 -> V_34 = V_4 ;
V_32 -> V_33 = V_4 ;
}
V_32 -> V_21 += V_11 ;
V_32 -> V_9 ++ ;
return V_4 -> V_10 ;
}
if( ! V_32 -> V_9 )
V_32 -> V_33 = V_32 -> V_6 ;
else if( ( V_32 -> V_9 % V_11 ) == 0 )
V_32 -> V_33 = V_32 -> V_33 -> V_13 ;
return V_32 -> V_33 -> V_10 + ( ( V_32 -> V_9 ++ ) % V_11 ) ;
}
static void F_21 ( T_5 * V_32 , unsigned int V_38 )
{
unsigned int V_39 = ( V_32 -> V_9 - 1 ) % V_11 ;
V_32 -> V_9 -= V_38 ;
while( V_38 -- )
{
F_29 ( V_32 -> V_33 -> V_10 + V_39 ) ;
if( ! V_39 )
{
V_39 = V_11 - 1 ;
V_32 -> V_33 = V_32 -> V_33 -> V_37 ;
}
else
V_39 -- ;
}
}
