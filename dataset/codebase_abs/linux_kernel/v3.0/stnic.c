static inline void
F_1 ( void )
{
T_1 V_1 ;
V_1 = * ( T_1 * ) 0xa0000000 ;
V_1 = * ( T_1 * ) 0xa0000000 ;
V_1 = * ( T_1 * ) 0xa0000000 ;
}
static inline T_2
F_2 ( int V_2 )
{
T_2 V_3 ;
V_3 = ( * ( V_4 * ) ( V_5 + ( ( V_2 ) << 1 ) ) >> 8 ) & 0xff ;
F_1 () ;
return V_3 ;
}
static inline void
F_3 ( int V_2 , T_2 V_3 )
{
* ( V_4 * ) ( V_5 + ( ( V_2 ) << 1 ) ) = ( ( V_6 ) ( V_3 ) << 8 ) ;
F_1 () ;
}
static int T_3 F_4 ( void )
{
struct V_7 * V_8 ;
int V_9 , V_10 ;
if ( ! V_11 )
return - V_12 ;
V_8 = F_5 () ;
if ( ! V_8 )
return - V_13 ;
#ifdef F_6
F_7 ( V_14 ) ;
#endif
for ( V_9 = 0 ; V_9 < V_15 ; V_9 ++ )
V_8 -> V_16 [ V_9 ] = V_14 [ V_9 ] ;
V_8 -> V_17 = 0x1000 ;
V_8 -> V_18 = V_19 ;
V_8 -> V_20 = & V_21 ;
V_10 = F_8 ( V_8 -> V_18 , V_22 , 0 , V_23 , V_8 ) ;
if ( V_10 ) {
F_9 ( V_24 L_1 , V_8 -> V_18 ) ;
F_10 ( V_8 ) ;
return V_10 ;
}
V_25 . V_26 = V_8 -> V_26 ;
V_25 . V_27 = 1 ;
#ifdef F_11
V_25 . V_28 = 0 ;
#else
V_25 . V_28 = 1 ;
#endif
V_25 . V_29 = V_30 ;
V_25 . V_31 = V_30 + V_32 ;
V_25 . V_33 = V_34 ;
V_25 . V_35 = & V_36 ;
V_25 . V_37 = & V_38 ;
V_25 . V_39 = & V_40 ;
V_25 . V_41 = & V_42 ;
F_12 ( V_8 ) ;
V_10 = F_13 ( V_8 ) ;
if ( V_10 ) {
F_14 ( V_8 -> V_18 , V_8 ) ;
F_10 ( V_8 ) ;
return V_10 ;
}
V_43 = V_8 ;
F_9 ( V_44 L_2 ) ;
return 0 ;
}
static void
V_36 ( struct V_7 * V_8 )
{
* ( V_4 * ) V_45 = 0 ;
F_15 ( 5 ) ;
if ( V_46 > 1 )
F_9 ( V_47 L_3 , V_48 ) ;
* ( V_4 * ) V_45 = ~ 0 ;
F_15 ( 5 ) ;
}
static void
V_38 ( struct V_7 * V_8 , struct V_49 * V_50 ,
int V_51 )
{
V_6 V_52 [ 2 ] ;
F_3 ( V_53 , 0 ) ;
F_3 ( V_54 , V_51 ) ;
F_3 ( V_55 , 4 ) ;
F_3 ( V_56 , 0 ) ;
F_3 ( V_57 , V_58 | V_59 | V_60 ) ;
V_52 [ 0 ] = * ( V_4 * ) V_61 ;
F_1 () ;
V_52 [ 1 ] = * ( V_4 * ) V_61 ;
F_1 () ;
V_50 -> V_62 = V_52 [ 0 ] >> 8 ;
V_50 -> V_63 = V_52 [ 0 ] & 0xff ;
#ifdef F_11
V_50 -> V_64 = V_52 [ 1 ] ;
#else
V_50 -> V_64 = ( ( V_52 [ 1 ] >> 8 ) & 0xff ) | ( V_52 [ 1 ] << 8 ) ;
#endif
if ( V_46 > 1 )
F_9 ( V_65 L_4 ,
V_51 , V_50 -> V_63 , V_50 -> V_62 , V_50 -> V_64 ) ;
F_3 ( V_57 , V_66 | V_59 | V_60 ) ;
}
static void
V_40 ( struct V_7 * V_8 , int V_67 , struct V_68 * V_69 ,
int V_70 )
{
char * V_52 = V_69 -> V_71 ;
V_6 V_3 ;
F_3 ( V_53 , V_70 & 0xff ) ;
F_3 ( V_54 , V_70 >> 8 ) ;
F_3 ( V_55 , V_67 & 0xff ) ;
F_3 ( V_56 , V_67 >> 8 ) ;
F_3 ( V_57 , V_58 | V_59 | V_60 ) ;
if ( V_67 & 1 )
V_67 ++ ;
while ( V_67 > 0 )
{
V_3 = * ( V_4 * ) V_61 ;
#ifdef F_11
* V_52 ++ = V_3 & 0xff ;
* V_52 ++ = V_3 >> 8 ;
#else
* V_52 ++ = V_3 >> 8 ;
* V_52 ++ = V_3 & 0xff ;
#endif
F_1 () ;
V_67 -= sizeof ( V_6 ) ;
}
F_3 ( V_57 , V_66 | V_59 | V_60 ) ;
}
static void
V_42 ( struct V_7 * V_8 , int V_67 ,
const unsigned char * V_52 , int V_72 )
{
F_3 ( V_55 , 1 ) ;
F_3 ( V_57 , V_58 | V_59 | V_60 ) ;
F_1 () ;
F_3 ( V_55 , V_67 & 0xff ) ;
F_3 ( V_56 , V_67 >> 8 ) ;
F_3 ( V_53 , 0 ) ;
F_3 ( V_54 , V_72 ) ;
F_3 ( V_57 , V_73 | V_59 | V_60 ) ;
if ( V_67 & 1 )
V_67 ++ ;
while ( V_67 > 0 )
{
#ifdef F_11
* ( V_4 * ) V_61 = ( ( V_6 ) V_52 [ 1 ] << 8 ) | V_52 [ 0 ] ;
#else
* ( V_4 * ) V_61 = ( ( V_6 ) V_52 [ 0 ] << 8 ) | V_52 [ 1 ] ;
#endif
F_1 () ;
V_52 += sizeof ( V_6 ) ;
V_67 -= sizeof ( V_6 ) ;
}
F_3 ( V_57 , V_66 | V_59 | V_60 ) ;
}
static void
F_12 ( struct V_7 * V_8 )
{
V_36 ( V_8 ) ;
F_16 ( V_8 , 0 ) ;
}
static void T_4 F_17 ( void )
{
F_18 ( V_43 ) ;
F_14 ( V_43 -> V_18 , V_43 ) ;
F_10 ( V_43 ) ;
}
