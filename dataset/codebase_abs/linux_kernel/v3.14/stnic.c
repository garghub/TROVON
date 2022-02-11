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
struct V_11 * V_12 ;
if ( ! V_13 )
return - V_14 ;
V_8 = F_5 () ;
if ( ! V_8 )
return - V_15 ;
#ifdef F_6
F_7 ( V_16 ) ;
#endif
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
V_8 -> V_18 [ V_9 ] = V_16 [ V_9 ] ;
V_8 -> V_19 = 0x1000 ;
V_8 -> V_20 = V_21 ;
V_8 -> V_22 = & V_23 ;
V_10 = F_8 ( V_8 -> V_20 , V_24 , 0 , V_25 , V_8 ) ;
if ( V_10 ) {
F_9 ( V_8 , L_1 , V_8 -> V_20 ) ;
F_10 ( V_8 ) ;
return V_10 ;
}
V_26 . V_27 = V_8 -> V_27 ;
V_26 . V_28 = 1 ;
#ifdef F_11
V_26 . V_29 = 0 ;
#else
V_26 . V_29 = 1 ;
#endif
V_26 . V_30 = V_31 ;
V_26 . V_32 = V_31 + V_33 ;
V_26 . V_34 = V_35 ;
V_26 . V_36 = & V_37 ;
V_26 . V_38 = & V_39 ;
V_26 . V_40 = & V_41 ;
V_26 . V_42 = & V_43 ;
F_12 ( V_8 ) ;
V_12 = F_13 ( V_8 ) ;
V_12 -> V_44 = V_45 ;
V_10 = F_14 ( V_8 ) ;
if ( V_10 ) {
F_15 ( V_8 -> V_20 , V_8 ) ;
F_10 ( V_8 ) ;
return V_10 ;
}
V_46 = V_8 ;
F_16 ( V_8 , L_2 ) ;
return 0 ;
}
static void
V_37 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_13 ( V_8 ) ;
* ( V_4 * ) V_47 = 0 ;
F_17 ( 5 ) ;
F_18 ( V_12 , V_48 , V_8 , L_3 , V_49 ) ;
* ( V_4 * ) V_47 = ~ 0 ;
F_17 ( 5 ) ;
}
static void
V_39 ( struct V_7 * V_8 , struct V_50 * V_51 ,
int V_52 )
{
struct V_11 * V_12 = F_13 ( V_8 ) ;
V_6 V_53 [ 2 ] ;
F_3 ( V_54 , 0 ) ;
F_3 ( V_55 , V_52 ) ;
F_3 ( V_56 , 4 ) ;
F_3 ( V_57 , 0 ) ;
F_3 ( V_58 , V_59 | V_60 | V_61 ) ;
V_53 [ 0 ] = * ( V_4 * ) V_62 ;
F_1 () ;
V_53 [ 1 ] = * ( V_4 * ) V_62 ;
F_1 () ;
V_51 -> V_63 = V_53 [ 0 ] >> 8 ;
V_51 -> V_64 = V_53 [ 0 ] & 0xff ;
#ifdef F_11
V_51 -> V_65 = V_53 [ 1 ] ;
#else
V_51 -> V_65 = ( ( V_53 [ 1 ] >> 8 ) & 0xff ) | ( V_53 [ 1 ] << 8 ) ;
#endif
F_19 ( V_12 , V_66 , V_8 , L_4 ,
V_52 , V_51 -> V_64 , V_51 -> V_63 , V_51 -> V_65 ) ;
F_3 ( V_58 , V_67 | V_60 | V_61 ) ;
}
static void
V_41 ( struct V_7 * V_8 , int V_68 , struct V_69 * V_70 ,
int V_71 )
{
char * V_53 = V_70 -> V_72 ;
V_6 V_3 ;
F_3 ( V_54 , V_71 & 0xff ) ;
F_3 ( V_55 , V_71 >> 8 ) ;
F_3 ( V_56 , V_68 & 0xff ) ;
F_3 ( V_57 , V_68 >> 8 ) ;
F_3 ( V_58 , V_59 | V_60 | V_61 ) ;
if ( V_68 & 1 )
V_68 ++ ;
while ( V_68 > 0 )
{
V_3 = * ( V_4 * ) V_62 ;
#ifdef F_11
* V_53 ++ = V_3 & 0xff ;
* V_53 ++ = V_3 >> 8 ;
#else
* V_53 ++ = V_3 >> 8 ;
* V_53 ++ = V_3 & 0xff ;
#endif
F_1 () ;
V_68 -= sizeof ( V_6 ) ;
}
F_3 ( V_58 , V_67 | V_60 | V_61 ) ;
}
static void
V_43 ( struct V_7 * V_8 , int V_68 ,
const unsigned char * V_53 , int V_73 )
{
F_3 ( V_56 , 1 ) ;
F_3 ( V_58 , V_59 | V_60 | V_61 ) ;
F_1 () ;
F_3 ( V_56 , V_68 & 0xff ) ;
F_3 ( V_57 , V_68 >> 8 ) ;
F_3 ( V_54 , 0 ) ;
F_3 ( V_55 , V_73 ) ;
F_3 ( V_58 , V_74 | V_60 | V_61 ) ;
if ( V_68 & 1 )
V_68 ++ ;
while ( V_68 > 0 )
{
#ifdef F_11
* ( V_4 * ) V_62 = ( ( V_6 ) V_53 [ 1 ] << 8 ) | V_53 [ 0 ] ;
#else
* ( V_4 * ) V_62 = ( ( V_6 ) V_53 [ 0 ] << 8 ) | V_53 [ 1 ] ;
#endif
F_1 () ;
V_53 += sizeof ( V_6 ) ;
V_68 -= sizeof ( V_6 ) ;
}
F_3 ( V_58 , V_67 | V_60 | V_61 ) ;
}
static void
F_12 ( struct V_7 * V_8 )
{
V_37 ( V_8 ) ;
F_20 ( V_8 , 0 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( V_46 ) ;
F_15 ( V_46 -> V_20 , V_46 ) ;
F_10 ( V_46 ) ;
}
