static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
{
int V_8 = V_9 ;
struct V_10 * V_11 ;
if( type != V_12 && type != V_13 && type != V_14 )
V_8 = V_15 - 3 ;
V_11 = (struct V_10 * ) F_2 ( V_2 , V_8 ) ;
V_11 -> V_16 = V_17 ;
if( type == V_12 || type == V_13 || type == V_14 )
{
V_11 -> V_18 . V_19 . V_20 = V_21 ;
V_11 -> V_18 . V_19 . V_22 = V_21 ;
V_11 -> V_18 . V_19 . V_23 = V_24 ;
V_11 -> V_18 . V_19 . V_25 [ 0 ] = 0x00 ;
V_11 -> V_18 . V_19 . V_25 [ 1 ] = 0x00 ;
V_11 -> V_18 . V_19 . V_25 [ 2 ] = 0x00 ;
V_11 -> V_18 . V_19 . V_26 = F_3 ( type ) ;
}
if ( V_6 != NULL )
memcpy ( V_11 -> V_6 , V_6 , V_4 -> V_27 ) ;
else
memcpy ( V_11 -> V_6 , V_4 -> V_28 , V_4 -> V_27 ) ;
if ( V_5 != NULL )
{
memcpy ( V_11 -> V_5 , V_5 , V_4 -> V_27 ) ;
return V_8 ;
}
return - V_8 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_29 ;
#ifdef F_5
if ( V_11 -> V_18 . V_19 . V_26 == F_3 ( V_12 ) )
return F_6 ( V_11 -> V_5 , V_2 ) ;
else
#endif
{
F_7 ( L_1 ,
V_2 -> V_4 -> V_30 , F_8 ( V_11 -> V_18 . V_19 . V_26 ) ) ;
return 0 ;
}
}
T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_29 ;
T_1 type ;
V_2 -> V_4 = V_4 ;
F_10 ( V_2 ) ;
if( V_11 -> V_18 . V_31 . V_20 == 0xe0 )
{
F_11 ( V_2 , V_15 - 3 ) ;
type = F_3 ( V_32 ) ;
}
else
{
F_11 ( V_2 , V_9 ) ;
type = V_11 -> V_18 . V_19 . V_26 ;
}
if ( * V_11 -> V_5 & 0x01 )
{
if ( memcmp ( V_11 -> V_5 , V_4 -> V_33 , V_34 ) == 0 )
V_2 -> V_35 = V_36 ;
else
V_2 -> V_35 = V_37 ;
}
else if ( V_4 -> V_38 & V_39 )
{
if ( memcmp ( V_11 -> V_5 , V_4 -> V_28 , V_34 ) )
V_2 -> V_35 = V_40 ;
}
return type ;
}
int F_12 ( struct V_3 * V_4 , int V_41 )
{
if ( ( V_41 < V_9 ) || ( V_41 > V_42 ) )
return - V_43 ;
V_4 -> V_44 = V_41 ;
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
V_4 -> V_45 = & V_46 ;
V_4 -> type = V_47 ;
V_4 -> V_48 = V_9 + 3 ;
V_4 -> V_44 = V_42 ;
V_4 -> V_27 = V_34 ;
V_4 -> V_49 = 100 ;
V_4 -> V_38 = V_50 | V_51 ;
memset ( V_4 -> V_33 , 0xFF , V_34 ) ;
}
struct V_3 * F_14 ( int V_52 )
{
return F_15 ( V_52 , L_2 , F_13 ) ;
}
