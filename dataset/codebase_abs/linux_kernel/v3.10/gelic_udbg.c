static void F_1 ( int V_1 , int V_2 , void * V_3 , T_1 V_4 ,
T_2 * V_5 )
{
T_3 V_6 ;
T_2 V_7 = ( ( T_2 ) V_3 ) & 0x0fffffffffffffffUL ;
T_2 V_8 = V_7 + V_4 ;
T_2 V_9 = V_7 & ~ 0xfff ;
T_2 V_10 = ( V_8 + 0xfff ) & ~ 0xfff ;
T_2 V_11 = 0 ;
T_2 V_12 = 0xf800000000000000UL ;
V_6 = F_2 ( V_1 , V_2 ,
V_10 - V_9 , 12 , 0 ,
& V_11 ) ;
if ( V_6 )
F_3 ( 0 ) ;
V_6 = F_4 ( V_1 , V_2 , V_9 ,
V_11 , V_10 - V_9 ,
V_12 ) ;
if ( V_6 )
F_3 ( 0 ) ;
* V_5 = V_11 + V_7 - V_9 ;
}
static int F_5 ( int V_1 , int V_2 , T_2 V_11 , T_1 V_4 )
{
T_3 V_6 ;
T_2 V_5 ;
V_5 = V_11 & ~ 0xfff ;
V_4 += V_11 - V_5 ;
V_4 = ( V_4 + 0xfff ) & ~ 0xfff ;
V_6 = F_6 ( V_1 , V_2 , V_5 ,
V_4 ) ;
if ( V_6 )
return V_6 ;
return F_7 ( V_1 , V_2 , V_5 ) ;
}
static void F_8 ( void )
{
T_3 V_6 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
V_6 = F_9 ( V_16 , V_17 , 0 ) ;
if ( V_6 )
F_3 ( 0 ) ;
F_1 ( V_16 , V_17 , & V_18 , sizeof( V_18 ) ,
& V_11 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_19 . V_20 = V_11 + F_10 ( struct V_21 , V_22 ) ;
F_11 () ;
V_6 = F_12 ( V_16 , V_17 ,
V_23 , 0 , 0 , 0 ,
& V_14 , & V_13 ) ;
if ( V_6 )
F_3 ( 0 ) ;
V_14 <<= 16 ;
V_24 = (struct V_25 * ) V_18 . V_22 ;
memset ( & V_24 -> V_26 , 0xff , 6 ) ;
memcpy ( & V_24 -> V_27 , & V_14 , 6 ) ;
V_28 = sizeof( struct V_25 ) ;
V_6 = F_12 ( V_16 , V_17 ,
V_29 ,
V_30 , 0 , 0 ,
& V_15 , & V_13 ) ;
if ( ! V_6 ) {
V_24 -> type = 0x8100 ;
V_28 += sizeof( struct V_31 ) ;
V_32 = (struct V_31 * ) ( V_24 + 1 ) ;
V_32 -> V_33 = V_15 ;
V_32 -> V_34 = 0x0800 ;
V_35 = (struct V_36 * ) ( V_32 + 1 ) ;
} else {
V_24 -> type = 0x0800 ;
V_35 = (struct V_36 * ) ( V_24 + 1 ) ;
}
V_28 += sizeof( struct V_36 ) ;
V_35 -> V_37 = 0x45 ;
V_35 -> V_38 = 10 ;
V_35 -> V_39 = 0x11 ;
V_35 -> V_27 = 0x00000000 ;
V_35 -> V_26 = 0xffffffff ;
V_28 += sizeof( struct V_40 ) ;
V_41 = (struct V_40 * ) ( V_35 + 1 ) ;
V_41 -> V_27 = V_42 ;
V_41 -> V_26 = V_42 ;
V_43 = V_44 = ( char * ) ( V_41 + 1 ) ;
}
static void F_13 ( void )
{
if ( V_11 )
F_5 ( V_16 , V_17 ,
V_11 , sizeof( V_18 ) ) ;
F_14 ( V_16 , V_17 ) ;
}
static void F_15 ( int V_45 )
{
T_4 * V_46 ;
T_5 V_47 ;
int V_48 ;
V_18 . V_19 . V_49 = V_28 + V_45 ;
V_35 -> V_50 = V_45 + sizeof( struct V_40 ) +
sizeof( struct V_36 ) ;
V_41 -> V_4 = V_45 + sizeof( struct V_40 ) ;
V_35 -> V_51 = 0 ;
V_47 = 0 ;
V_46 = ( T_4 * ) V_35 ;
for ( V_48 = 0 ; V_48 < 5 ; V_48 ++ )
V_47 += * V_46 ++ ;
V_35 -> V_51 = ~ ( V_47 + ( V_47 >> 16 ) ) ;
V_18 . V_19 . V_52 = V_53 |
V_54 ;
V_18 . V_19 . V_55 = 0 ;
V_18 . V_19 . V_56 = 0 ;
F_11 () ;
F_16 ( V_16 , V_17 , V_11 , 0 ) ;
while ( ( V_18 . V_19 . V_52 & V_57 ) ==
V_58 )
F_17 () ;
}
static void F_18 ( char V_59 )
{
* V_43 ++ = V_59 ;
if ( V_59 == '\n' || ( V_43 - V_44 ) >= V_60 ) {
F_15 ( V_43 - V_44 ) ;
V_43 = V_44 ;
}
}
void T_6 F_19 ( void )
{
F_8 () ;
V_61 = F_18 ;
}
void F_20 ( void )
{
V_61 = NULL ;
F_13 () ;
}
