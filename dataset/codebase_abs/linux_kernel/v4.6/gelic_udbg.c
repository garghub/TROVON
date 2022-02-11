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
F_13 ( V_24 -> V_26 ) ;
memcpy ( & V_24 -> V_27 , & V_14 , V_28 ) ;
V_29 = sizeof( struct V_25 ) ;
V_6 = F_12 ( V_16 , V_17 ,
V_30 ,
V_31 , 0 , 0 ,
& V_15 , & V_13 ) ;
if ( ! V_6 ) {
V_24 -> V_32 = V_33 ;
V_29 += sizeof( struct V_34 ) ;
V_35 = (struct V_34 * ) ( V_24 + 1 ) ;
V_35 -> V_36 = V_15 ;
V_35 -> V_37 = V_38 ;
V_39 = (struct V_40 * ) ( V_35 + 1 ) ;
} else {
V_24 -> V_32 = 0x0800 ;
V_39 = (struct V_40 * ) ( V_24 + 1 ) ;
}
V_29 += sizeof( struct V_40 ) ;
V_39 -> V_41 = 4 ;
V_39 -> V_42 = 5 ;
V_39 -> V_43 = 10 ;
V_39 -> V_44 = 0x11 ;
V_39 -> V_45 = 0x00000000 ;
V_39 -> V_46 = 0xffffffff ;
V_29 += sizeof( struct V_47 ) ;
V_48 = (struct V_47 * ) ( V_39 + 1 ) ;
V_48 -> V_49 = V_50 ;
V_48 -> V_51 = V_50 ;
V_52 = V_53 = ( char * ) ( V_48 + 1 ) ;
}
static void F_14 ( void )
{
if ( V_11 )
F_5 ( V_16 , V_17 ,
V_11 , sizeof( V_18 ) ) ;
F_15 ( V_16 , V_17 ) ;
}
static void F_16 ( int V_54 )
{
T_4 * V_55 ;
T_5 V_56 ;
int V_57 ;
V_18 . V_19 . V_58 = V_29 + V_54 ;
V_39 -> V_59 = V_54 + sizeof( struct V_47 ) +
sizeof( struct V_40 ) ;
V_48 -> V_4 = V_54 + sizeof( struct V_47 ) ;
V_39 -> V_60 = 0 ;
V_56 = 0 ;
V_55 = ( T_4 * ) V_39 ;
for ( V_57 = 0 ; V_57 < 5 ; V_57 ++ )
V_56 += * V_55 ++ ;
V_39 -> V_60 = ~ ( V_56 + ( V_56 >> 16 ) ) ;
V_18 . V_19 . V_61 = V_62 |
V_63 ;
V_18 . V_19 . V_64 = 0 ;
V_18 . V_19 . V_65 = 0 ;
F_11 () ;
F_17 ( V_16 , V_17 , V_11 , 0 ) ;
while ( ( V_18 . V_19 . V_61 & V_66 ) ==
V_67 )
F_18 () ;
}
static void F_19 ( char V_68 )
{
* V_52 ++ = V_68 ;
if ( V_68 == '\n' || ( V_52 - V_53 ) >= V_69 ) {
F_16 ( V_52 - V_53 ) ;
V_52 = V_53 ;
}
}
void T_6 F_20 ( void )
{
F_8 () ;
V_70 = F_19 ;
}
void F_21 ( void )
{
V_70 = NULL ;
F_14 () ;
}
