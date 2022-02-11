void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( 0 , V_4 , V_5 , V_2 -> V_6 ) |
F_3 ( 0 , V_4 , V_7 , V_8 ) |
F_3 ( 0 , V_4 , V_9 , V_9 ) ;
F_4 ( V_4 , V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_4 ( V_4 , 0 ) ;
}
void F_6 ( struct V_1 * V_2 ,
int V_10 , int V_11 )
{
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
}
void F_7 ( struct V_1 * V_2 ,
int V_12 , int V_13 )
{
T_1 V_3 ;
V_3 = F_2 ( 0 , V_14 , V_15 , V_13 ) |
F_2 ( 0 , V_14 , V_16 , V_12 ) ;
F_4 ( V_14 , V_3 ) ;
}
void F_8 ( struct V_1 * V_2 ,
T_1 V_17 , T_1 V_18 )
{
F_4 ( V_19 , ( V_17 << 16 ) | ( V_18 & 0xffff ) ) ;
F_4 ( V_20 , 0xffe0 ) ;
}
void F_9 ( struct V_1 * V_2 ,
T_2 V_21 , const T_3 * V_22 , const T_3 * V_23 )
{
int V_24 , V_25 , V_26 , V_27 , V_6 ;
T_3 V_28 , V_29 , V_30 ;
T_2 V_31 ;
void T_4 * V_32 , * V_33 ;
V_27 = V_2 -> V_10 >> 3 ;
V_26 = V_27 * V_2 -> V_11 ;
V_6 = V_2 -> V_34 * 2 / 8 ;
V_31 = 0 ;
V_33 = V_2 -> V_35 ;
V_32 = V_33 ;
for( V_24 = 0 ; V_24 < V_26 ; V_24 ++ )
{
V_28 = * V_22 ++ ;
V_29 = * V_23 ++ ;
V_31 = 0 ;
#if 0
if(rop == ROP_XOR)
opr = mask ^ color;
else
opr = mask & color;
for(j=0;j<8;j++)
{
if(opr & (0x80 >> j))
{
data |= 2 << (j*2);
}else{
data |= 1 << (j*2);
}
}
#else
for( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
if( V_29 & ( 0x80 >> V_25 ) ) {
if( V_21 == V_36 )
V_30 = V_29 ^ V_28 ;
else
V_30 = V_29 & V_28 ;
V_31 |= ( ( V_30 & ( 0x80 >> V_25 ) ) ? 2 : 1 ) << ( V_25 * 2 ) ;
}
}
#endif
F_10 ( V_31 , V_32 ) ;
#if 0
if(!((i+1)&(pitch-1)))
#else
if( ( V_24 + 1 ) % V_27 == 0 )
#endif
{
V_33 += V_6 ;
V_32 = V_33 ;
} else{
V_32 += sizeof( T_2 ) ;
}
}
}
void F_11 ( struct V_1 * V_2 ,
T_2 V_21 , const T_3 * V_22 , const T_3 * V_23 )
{
int V_24 , V_25 , V_26 , V_27 , V_6 ;
T_3 V_28 , V_29 ;
T_2 V_31 ;
void T_4 * V_32 , * V_33 ;
V_27 = V_2 -> V_10 >> 3 ;
V_26 = V_27 * V_2 -> V_11 ;
V_6 = V_2 -> V_34 * 2 / 8 ;
V_31 = 0 ;
V_33 = V_2 -> V_35 ;
V_32 = V_33 ;
for( V_24 = 0 ; V_24 < V_26 ; V_24 ++ )
{
V_28 = * V_22 ++ ;
V_29 = * V_23 ++ ;
V_31 = 0 ;
#if 0
if(rop == ROP_XOR)
opr = mask ^ color;
else
opr = mask & color;
for(j=0;j<8;j++)
{
if(opr & (0x80 >> j))
{
data |= 2 << (j*2);
}else{
data |= 1 << (j*2);
}
}
#else
for( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
if( V_29 & ( 1 << V_25 ) )
V_31 |= ( ( V_28 & ( 1 << V_25 ) ) ? 1 : 2 ) << ( V_25 * 2 ) ;
}
#endif
F_10 ( V_31 , V_32 ) ;
if( ! ( V_24 & ( V_27 - 1 ) ) )
{
V_33 += V_6 ;
V_32 = V_33 ;
} else{
V_32 += sizeof( T_2 ) ;
}
}
}
