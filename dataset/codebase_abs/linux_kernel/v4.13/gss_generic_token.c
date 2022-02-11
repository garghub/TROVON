static int
F_1 ( int V_1 )
{
if ( V_1 < ( 1 << 7 ) )
return 1 ;
else if ( V_1 < ( 1 << 8 ) )
return 2 ;
#if ( V_2 == 2 )
else
return 3 ;
#else
else if ( V_1 < ( 1 << 16 ) )
return 3 ;
else if ( V_1 < ( 1 << 24 ) )
return 4 ;
else
return 5 ;
#endif
}
static void
F_2 ( unsigned char * * V_3 , int V_1 )
{
if ( V_1 < ( 1 << 7 ) ) {
* ( * V_3 ) ++ = ( unsigned char ) V_1 ;
} else {
* ( * V_3 ) ++ = ( unsigned char ) ( F_1 ( V_1 ) + 127 ) ;
#if ( V_2 > 2 )
if ( V_1 >= ( 1 << 24 ) )
* ( * V_3 ) ++ = ( unsigned char ) ( V_1 >> 24 ) ;
if ( V_1 >= ( 1 << 16 ) )
* ( * V_3 ) ++ = ( unsigned char ) ( ( V_1 >> 16 ) & 0xff ) ;
#endif
if ( V_1 >= ( 1 << 8 ) )
* ( * V_3 ) ++ = ( unsigned char ) ( ( V_1 >> 8 ) & 0xff ) ;
* ( * V_3 ) ++ = ( unsigned char ) ( V_1 & 0xff ) ;
}
}
static int
F_3 ( unsigned char * * V_3 , int * V_4 )
{
unsigned char V_5 ;
int V_6 ;
if ( * V_4 < 1 )
return - 1 ;
V_5 = * ( * V_3 ) ++ ;
( * V_4 ) -- ;
if ( V_5 & 0x80 ) {
if ( ( V_5 &= 0x7f ) > ( ( * V_4 ) - 1 ) )
return - 1 ;
if ( V_5 > V_2 )
return - 1 ;
V_6 = 0 ;
for (; V_5 ; V_5 -- ) {
V_6 = ( V_6 << 8 ) + ( * ( * V_3 ) ++ ) ;
( * V_4 ) -- ;
}
} else {
V_6 = V_5 ;
}
return V_6 ;
}
int
F_4 ( struct V_7 * V_8 , unsigned int V_9 )
{
V_9 += 2 + ( int ) V_8 -> V_10 ;
return 1 + F_1 ( V_9 ) + V_9 ;
}
void
F_5 ( struct V_7 * V_8 , int V_9 , unsigned char * * V_3 )
{
* ( * V_3 ) ++ = 0x60 ;
F_2 ( V_3 , 2 + V_8 -> V_10 + V_9 ) ;
* ( * V_3 ) ++ = 0x06 ;
* ( * V_3 ) ++ = ( unsigned char ) V_8 -> V_10 ;
F_6 ( * V_3 , V_8 -> V_11 , ( ( int ) V_8 -> V_10 ) ) ;
}
T_1
F_7 ( struct V_7 * V_8 , int * V_9 ,
unsigned char * * V_12 , int V_13 )
{
unsigned char * V_3 = * V_12 ;
int V_14 ;
struct V_7 V_15 ;
int V_6 = 0 ;
if ( ( V_13 -= 1 ) < 0 )
return V_16 ;
if ( * V_3 ++ != 0x60 )
return V_16 ;
if ( ( V_14 = F_3 ( & V_3 , & V_13 ) ) < 0 )
return V_16 ;
if ( V_14 != V_13 )
return V_16 ;
if ( ( V_13 -= 1 ) < 0 )
return V_16 ;
if ( * V_3 ++ != 0x06 )
return V_16 ;
if ( ( V_13 -= 1 ) < 0 )
return V_16 ;
V_15 . V_10 = * V_3 ++ ;
if ( ( V_13 -= V_15 . V_10 ) < 0 )
return V_16 ;
V_15 . V_11 = V_3 ;
V_3 += V_15 . V_10 ;
if ( ! F_8 ( & V_15 , V_8 ) )
V_6 = V_17 ;
if ( ( V_13 -= 2 ) < 0 )
return V_16 ;
if ( V_6 )
return V_6 ;
if ( ! V_6 ) {
* V_12 = V_3 ;
* V_9 = V_13 ;
}
return V_6 ;
}
