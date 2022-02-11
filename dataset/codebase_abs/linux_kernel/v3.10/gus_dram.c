static int F_1 ( struct V_1 * V_2 , char T_1 * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
unsigned long V_6 ;
unsigned int V_7 , V_8 ;
char V_9 [ 256 ] , * V_10 ;
while ( V_5 > 0 ) {
V_7 = V_5 > sizeof( V_9 ) ? sizeof( V_9 ) : V_5 ;
if ( F_2 ( V_9 , V_3 , V_7 ) )
return - V_11 ;
if ( V_2 -> V_12 ) {
F_3 ( & V_2 -> V_13 , V_6 ) ;
F_4 ( V_2 , V_14 , 0x01 ) ;
F_5 ( V_2 , V_4 ) ;
F_6 ( F_7 ( V_2 , V_15 ) , V_9 , V_7 ) ;
F_8 ( & V_2 -> V_13 , V_6 ) ;
V_4 += V_7 ;
} else {
V_10 = V_9 ;
V_8 = V_7 ;
while ( V_8 -- )
F_9 ( V_2 , V_4 ++ , * V_10 ++ ) ;
}
V_5 -= V_7 ;
V_3 += V_7 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , char T_1 * V_9 ,
unsigned int V_4 , unsigned int V_5 )
{
return F_1 ( V_2 , V_9 , V_4 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 , char T_1 * V_3 ,
unsigned int V_4 , unsigned int V_5 ,
int V_16 )
{
unsigned long V_6 ;
unsigned int V_7 , V_8 ;
char V_9 [ 256 ] , * V_10 ;
while ( V_5 > 0 ) {
V_7 = V_5 > sizeof( V_9 ) ? sizeof( V_9 ) : V_5 ;
if ( V_2 -> V_12 ) {
F_3 ( & V_2 -> V_13 , V_6 ) ;
F_4 ( V_2 , V_14 , V_16 ? 0x03 : 0x01 ) ;
F_5 ( V_2 , V_4 ) ;
F_12 ( F_7 ( V_2 , V_15 ) , V_9 , V_7 ) ;
F_4 ( V_2 , V_14 , 0x01 ) ;
F_8 ( & V_2 -> V_13 , V_6 ) ;
V_4 += V_7 ;
} else {
V_10 = V_9 ;
V_8 = V_7 ;
while ( V_8 -- )
* V_10 ++ = F_13 ( V_2 , V_4 ++ ) ;
}
if ( F_14 ( V_3 , V_9 , V_7 ) )
return - V_11 ;
V_5 -= V_7 ;
V_3 += V_7 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , char T_1 * V_9 ,
unsigned int V_4 , unsigned int V_5 ,
int V_16 )
{
return F_11 ( V_2 , V_9 , V_4 , V_5 , V_16 ) ;
}
