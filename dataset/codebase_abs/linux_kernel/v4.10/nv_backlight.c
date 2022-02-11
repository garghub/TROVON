static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_7 ;
V_7 = V_8 + V_5 -> V_9 [ V_3 ] * V_10 ;
if ( V_7 < 0 )
V_7 = 0 ;
else if ( V_7 < V_8 )
V_7 = V_8 ;
else if ( V_7 > V_11 )
V_7 = V_11 ;
return V_7 ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
T_1 V_14 , V_15 , V_16 ;
int V_3 ;
if ( ! V_2 -> V_17 )
return 0 ;
if ( V_13 -> V_18 . V_19 != V_20 ||
V_13 -> V_18 . V_21 != V_20 )
V_3 = 0 ;
else
V_3 = V_13 -> V_18 . V_22 ;
V_15 = F_5 ( V_2 -> V_23 , 0x10F0 ) & 0x0000FFFF ;
V_14 = F_5 ( V_2 -> V_24 , 0x081C ) & 0xFFFFFFFC ;
V_16 = F_5 ( V_2 -> V_25 , 0x0848 ) & 0xCFFFFFCC ;
if ( V_3 > 0 ) {
V_14 |= 0x1 ;
V_15 |= ( 1 << 31 ) ;
V_15 |= F_1 ( V_2 , V_3 ) << 16 ;
V_16 |= V_2 -> V_26 ;
} else
V_16 |= 0x20000022 ;
F_6 ( V_2 -> V_24 , 0x081C , V_14 ) ;
F_6 ( V_2 -> V_23 , 0x10F0 , V_15 ) ;
F_6 ( V_2 -> V_25 , 0x848 , V_16 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_27 V_18 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_12 * V_13 ;
char V_28 [ 12 ] ;
if ( ! V_2 -> V_17 )
return;
#ifdef F_8
if ( ! F_9 ( V_29 ) ||
! F_10 ( L_1 ) )
return;
#endif
snprintf ( V_28 , sizeof( V_28 ) , L_2 , V_5 -> V_30 ) ;
memset ( & V_18 , 0 , sizeof( struct V_27 ) ) ;
V_18 . type = V_31 ;
V_18 . V_32 = V_33 - 1 ;
V_13 = F_11 ( V_28 , V_5 -> V_34 , V_2 , & V_35 ,
& V_18 ) ;
if ( F_12 ( V_13 ) ) {
V_5 -> V_36 = NULL ;
F_13 ( V_37 L_3 ) ;
goto error;
}
V_5 -> V_36 = V_13 ;
F_14 ( V_5 , 0 ,
0x158 * V_38 / V_11 ,
0x534 * V_38 / V_11 ) ;
V_13 -> V_18 . V_22 = V_13 -> V_18 . V_32 ;
V_13 -> V_18 . V_19 = V_20 ;
F_15 ( V_13 ) ;
F_13 ( L_4 , V_28 ) ;
return;
error:
return;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_12 * V_13 = V_5 -> V_36 ;
F_17 ( V_13 ) ;
F_13 ( L_5 ) ;
}
