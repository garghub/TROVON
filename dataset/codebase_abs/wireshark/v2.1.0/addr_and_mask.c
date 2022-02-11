T_1
F_1 ( const T_1 V_1 )
{
static const T_1 V_2 [ 33 ] = {
0x00000000 ,
0x80000000 , 0xc0000000 , 0xe0000000 , 0xf0000000 ,
0xf8000000 , 0xfc000000 , 0xfe000000 , 0xff000000 ,
0xff800000 , 0xffc00000 , 0xffe00000 , 0xfff00000 ,
0xfff80000 , 0xfffc0000 , 0xfffe0000 , 0xffff0000 ,
0xffff8000 , 0xffffc000 , 0xffffe000 , 0xfffff000 ,
0xfffff800 , 0xfffffc00 , 0xfffffe00 , 0xffffff00 ,
0xffffff80 , 0xffffffc0 , 0xffffffe0 , 0xfffffff0 ,
0xfffffff8 , 0xfffffffc , 0xfffffffe , 0xffffffff ,
} ;
F_2 ( V_1 <= 32 ) ;
return V_2 [ V_1 ] ;
}
int
F_3 ( T_2 * V_3 , int V_4 , T_3 * V_5 ,
T_1 V_6 )
{
T_1 V_7 ;
if ( V_6 > 32 )
return - 1 ;
V_7 = ( V_6 + 7 ) / 8 ;
memset ( V_5 , 0 , 4 ) ;
F_4 ( V_3 , V_5 , V_4 , V_7 ) ;
if ( V_6 % 8 )
V_5 [ V_7 - 1 ] &= ( ( 0xff00 >> ( V_6 % 8 ) ) & 0xff ) ;
return V_7 ;
}
int
F_5 ( T_2 * V_3 , int V_4 , struct V_8 * V_5 ,
T_1 V_6 )
{
T_1 V_7 ;
if ( V_6 > 128 )
return - 1 ;
V_7 = ( V_6 + 7 ) / 8 ;
memset ( V_5 -> V_9 , 0 , 16 ) ;
F_4 ( V_3 , V_5 -> V_9 , V_4 , V_7 ) ;
if ( V_6 % 8 ) {
V_5 -> V_9 [ V_7 - 1 ] &=
( ( 0xff00 >> ( V_6 % 8 ) ) & 0xff ) ;
}
return V_7 ;
}
