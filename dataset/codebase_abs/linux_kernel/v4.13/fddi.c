static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 , unsigned int V_7 )
{
int V_8 = V_9 ;
struct V_10 * V_11 ;
if( type != V_12 && type != V_13 && type != V_14 )
V_8 = V_15 - 3 ;
V_11 = F_2 ( V_2 , V_8 ) ;
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
T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_29 ;
T_1 type ;
V_2 -> V_4 = V_4 ;
F_5 ( V_2 ) ;
if( V_11 -> V_18 . V_30 . V_20 == 0xe0 )
{
F_6 ( V_2 , V_15 - 3 ) ;
type = F_3 ( V_31 ) ;
}
else
{
F_6 ( V_2 , V_9 ) ;
type = V_11 -> V_18 . V_19 . V_26 ;
}
if ( * V_11 -> V_5 & 0x01 )
{
if ( memcmp ( V_11 -> V_5 , V_4 -> V_32 , V_33 ) == 0 )
V_2 -> V_34 = V_35 ;
else
V_2 -> V_34 = V_36 ;
}
else if ( V_4 -> V_37 & V_38 )
{
if ( memcmp ( V_11 -> V_5 , V_4 -> V_28 , V_33 ) )
V_2 -> V_34 = V_39 ;
}
return type ;
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_40 = & V_41 ;
V_4 -> type = V_42 ;
V_4 -> V_43 = V_9 + 3 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = V_9 ;
V_4 -> V_47 = V_45 ;
V_4 -> V_27 = V_33 ;
V_4 -> V_48 = 100 ;
V_4 -> V_37 = V_49 | V_50 ;
memset ( V_4 -> V_32 , 0xFF , V_33 ) ;
}
struct V_3 * F_8 ( int V_51 )
{
return F_9 ( V_51 , L_1 , V_52 ,
F_7 ) ;
}
