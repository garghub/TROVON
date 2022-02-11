static inline T_1 F_1 ( const void * V_1 )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( T_1 * V_2 , T_2 * V_3 , const T_2 * V_4 ,
unsigned int V_5 )
{
T_2 V_6 [ V_7 ] ;
if ( V_3 != V_4 )
memcpy ( V_3 , V_4 , V_5 ) ;
while ( V_5 >= V_7 ) {
F_4 ( V_2 , V_6 ) ;
F_5 ( V_3 , V_6 , V_7 ) ;
V_5 -= V_7 ;
V_3 += V_7 ;
}
if ( V_5 ) {
F_4 ( V_2 , V_6 ) ;
F_5 ( V_3 , V_6 , V_5 ) ;
}
}
void F_6 ( T_1 * V_2 , struct V_8 * V_9 , T_2 * V_10 )
{
static const char V_11 [ 16 ] = L_1 ;
V_2 [ 0 ] = F_1 ( V_11 + 0 ) ;
V_2 [ 1 ] = F_1 ( V_11 + 4 ) ;
V_2 [ 2 ] = F_1 ( V_11 + 8 ) ;
V_2 [ 3 ] = F_1 ( V_11 + 12 ) ;
V_2 [ 4 ] = V_9 -> V_12 [ 0 ] ;
V_2 [ 5 ] = V_9 -> V_12 [ 1 ] ;
V_2 [ 6 ] = V_9 -> V_12 [ 2 ] ;
V_2 [ 7 ] = V_9 -> V_12 [ 3 ] ;
V_2 [ 8 ] = V_9 -> V_12 [ 4 ] ;
V_2 [ 9 ] = V_9 -> V_12 [ 5 ] ;
V_2 [ 10 ] = V_9 -> V_12 [ 6 ] ;
V_2 [ 11 ] = V_9 -> V_12 [ 7 ] ;
V_2 [ 12 ] = F_1 ( V_10 + 0 ) ;
V_2 [ 13 ] = F_1 ( V_10 + 4 ) ;
V_2 [ 14 ] = F_1 ( V_10 + 8 ) ;
V_2 [ 15 ] = F_1 ( V_10 + 12 ) ;
}
int F_7 ( struct V_13 * V_14 , const T_2 * V_12 ,
unsigned int V_15 )
{
struct V_8 * V_9 = F_8 ( V_14 ) ;
int V_16 ;
if ( V_15 != V_17 )
return - V_18 ;
for ( V_16 = 0 ; V_16 < F_9 ( V_9 -> V_12 ) ; V_16 ++ )
V_9 -> V_12 [ V_16 ] = F_1 ( V_12 + V_16 * sizeof( T_1 ) ) ;
return 0 ;
}
int F_10 ( struct V_19 * V_20 , struct V_21 * V_3 ,
struct V_21 * V_4 , unsigned int V_22 )
{
struct V_23 V_24 ;
T_1 V_2 [ 16 ] ;
int V_25 ;
F_11 ( & V_24 , V_3 , V_4 , V_22 ) ;
V_25 = F_12 ( V_20 , & V_24 , V_7 ) ;
F_6 ( V_2 , F_13 ( V_20 -> V_14 ) , V_24 . V_10 ) ;
while ( V_24 . V_22 >= V_7 ) {
F_3 ( V_2 , V_24 . V_3 . V_26 . V_27 , V_24 . V_4 . V_26 . V_27 ,
F_14 ( V_24 . V_22 , V_7 ) ) ;
V_25 = F_15 ( V_20 , & V_24 ,
V_24 . V_22 % V_7 ) ;
}
if ( V_24 . V_22 ) {
F_3 ( V_2 , V_24 . V_3 . V_26 . V_27 , V_24 . V_4 . V_26 . V_27 ,
V_24 . V_22 ) ;
V_25 = F_15 ( V_20 , & V_24 , 0 ) ;
}
return V_25 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_28 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_28 ) ;
}
