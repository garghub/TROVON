T_1 *
F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( T_1 , 1 ) ;
return V_1 ;
}
void
F_3 ( T_1 * V_1 )
{
F_4 ( V_1 ) ;
}
void
F_5 ( T_1 * V_1 , const T_2 V_2 )
{
V_1 -> V_3 = V_2 ;
}
void
F_6 ( T_1 * V_1 , const T_2 V_2 )
{
V_1 -> V_3 = F_7 ( V_2 ) ;
}
void
F_8 ( T_1 * V_1 , const T_3 V_4 )
{
static T_2 V_5 [ 33 ] = {
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
F_9 ( V_4 <= 32 ) ;
V_1 -> V_6 = V_5 [ V_4 ] ;
}
T_2
F_10 ( T_1 * V_1 )
{
return F_11 ( V_1 -> V_3 ) ;
}
T_2
F_12 ( T_1 * V_1 )
{
return V_1 -> V_3 ;
}
void
F_13 ( const T_1 * V_1 , T_4 * V_7 )
{
T_2 V_8 = F_11 ( V_1 -> V_3 ) ;
F_14 ( ( V_9 * ) & V_8 , V_7 , V_10 ) ;
}
T_5
F_15 ( const T_1 * V_11 , const T_1 * V_12 )
{
T_2 V_13 , V_14 , V_6 ;
V_6 = F_16 ( V_11 -> V_6 , V_12 -> V_6 ) ;
V_13 = V_11 -> V_3 & V_6 ;
V_14 = V_12 -> V_3 & V_6 ;
return ( V_13 == V_14 ) ;
}
T_5
F_17 ( const T_1 * V_11 , const T_1 * V_12 )
{
T_2 V_13 , V_14 , V_6 ;
V_6 = F_16 ( V_11 -> V_6 , V_12 -> V_6 ) ;
V_13 = V_11 -> V_3 & V_6 ;
V_14 = V_12 -> V_3 & V_6 ;
return ( V_13 > V_14 ) ;
}
T_5
F_18 ( const T_1 * V_11 , const T_1 * V_12 )
{
T_2 V_13 , V_14 , V_6 ;
V_6 = F_16 ( V_11 -> V_6 , V_12 -> V_6 ) ;
V_13 = V_11 -> V_3 & V_6 ;
V_14 = V_12 -> V_3 & V_6 ;
return ( V_13 >= V_14 ) ;
}
T_5
F_19 ( const T_1 * V_11 , const T_1 * V_12 )
{
T_2 V_13 , V_14 , V_6 ;
V_6 = F_16 ( V_11 -> V_6 , V_12 -> V_6 ) ;
V_13 = V_11 -> V_3 & V_6 ;
V_14 = V_12 -> V_3 & V_6 ;
return ( V_13 < V_14 ) ;
}
T_5
F_20 ( const T_1 * V_11 , const T_1 * V_12 )
{
T_2 V_13 , V_14 , V_6 ;
V_6 = F_16 ( V_11 -> V_6 , V_12 -> V_6 ) ;
V_13 = V_11 -> V_3 & V_6 ;
V_14 = V_12 -> V_3 & V_6 ;
return ( V_13 <= V_14 ) ;
}
