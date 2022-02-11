void F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
char * V_5 = V_3 ;
int V_6 = 0 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( ( V_5 [ 0 ] == 0x1f ) && ( V_5 [ 1 ] == 0x8b ) ) {
int V_7 , V_8 ;
V_2 -> V_9 . V_10 = V_2 -> V_11 ;
if ( F_2 () > sizeof( V_2 -> V_11 ) )
F_3 ( L_1 ) ;
V_6 = 10 ;
V_8 = V_5 [ 3 ] ;
if ( V_5 [ 2 ] != V_12 || ( V_8 & V_13 ) != 0 )
F_3 ( L_2 ) ;
if ( ( V_8 & V_14 ) != 0 )
V_6 = 12 + V_5 [ 10 ] + ( V_5 [ 11 ] << 8 ) ;
if ( ( V_8 & V_15 ) != 0 )
while ( V_5 [ V_6 ++ ] != 0 )
;
if ( ( V_8 & V_16 ) != 0 )
while ( V_5 [ V_6 ++ ] != 0 )
;
if ( ( V_8 & V_17 ) != 0 )
V_6 += 2 ;
if ( V_6 >= V_4 )
F_3 ( L_3 ) ;
V_7 = F_4 ( & V_2 -> V_9 , - V_18 ) ;
if ( V_7 != V_19 )
F_3 ( L_4 , V_7 ) ;
}
V_2 -> V_9 . V_20 = V_6 ;
V_2 -> V_9 . V_21 = V_3 + V_6 ;
V_2 -> V_9 . V_22 = V_4 - V_6 ;
}
int F_5 ( struct V_1 * V_2 , void * V_23 , int V_24 )
{
int V_25 ;
if ( V_2 -> V_9 . V_10 ) {
int V_7 ;
V_2 -> V_9 . V_26 = V_23 ;
V_2 -> V_9 . V_27 = V_24 ;
V_7 = F_6 ( & V_2 -> V_9 , V_28 ) ;
if ( V_7 != V_19 && V_7 != V_29 )
F_3 ( L_5 , V_7 , V_2 -> V_9 . V_30 ) ;
V_25 = V_2 -> V_9 . V_26 - ( unsigned char * ) V_23 ;
} else {
V_25 = F_7 ( V_2 -> V_9 . V_22 , ( unsigned ) V_24 ) ;
memcpy ( V_23 , V_2 -> V_9 . V_21 , V_25 ) ;
V_2 -> V_9 . V_21 += V_25 ;
V_2 -> V_9 . V_22 -= V_25 ;
}
return V_25 ;
}
void F_8 ( struct V_1 * V_2 , void * V_23 , int V_24 )
{
int V_25 ;
V_25 = F_5 ( V_2 , V_23 , V_24 ) ;
if ( V_25 < V_24 )
F_3 ( L_6
L_7 , V_24 , V_25 ) ;
}
void F_9 ( struct V_1 * V_2 , int V_25 )
{
static char V_31 [ 128 ] ;
while ( V_25 > sizeof( V_31 ) ) {
F_8 ( V_2 , V_31 , sizeof( V_31 ) ) ;
V_25 -= sizeof( V_31 ) ;
}
if ( V_25 > 0 )
F_8 ( V_2 , V_31 , V_25 ) ;
}
int F_10 ( struct V_1 * V_2 , void * V_23 , int V_24 )
{
int V_25 ;
V_25 = F_5 ( V_2 , V_23 , V_24 ) ;
if ( V_2 -> V_9 . V_10 ) {
F_11 ( & V_2 -> V_9 ) ;
}
return V_25 ;
}
