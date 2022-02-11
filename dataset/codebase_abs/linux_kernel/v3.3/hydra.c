static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
if ( ! F_2 ( V_2 -> V_6 . V_7 , 0x10000 , L_1 ) )
return - V_8 ;
if ( ( V_5 = F_3 ( V_2 ) ) ) {
F_4 ( V_2 -> V_6 . V_7 , 0x10000 ) ;
return - V_8 ;
}
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
unsigned long V_11 = F_5 ( V_2 -> V_6 . V_7 ) ;
unsigned long V_12 = V_11 + V_13 ;
const char V_14 [] = L_2 ;
int V_15 , V_16 ;
int V_17 ;
int V_5 ;
static T_2 V_18 [ 16 ] = {
0x00 , 0x02 , 0x04 , 0x06 , 0x08 , 0x0a , 0x0c , 0x0e ,
0x10 , 0x12 , 0x14 , 0x16 , 0x18 , 0x1a , 0x1c , 0x1e ,
} ;
V_10 = F_6 ( 0 ) ;
if ( ! V_10 )
return - V_19 ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ )
V_10 -> V_21 [ V_17 ] = * ( ( V_22 * ) ( V_11 + V_23 + 2 * V_17 ) ) ;
F_7 ( 0x4b , V_12 + V_24 ) ;
V_15 = V_25 ;
V_16 = V_26 ;
V_10 -> V_27 = V_12 ;
V_10 -> V_28 = V_29 ;
if ( F_8 ( V_29 , V_30 , V_31 , L_3 ,
V_10 ) ) {
F_9 ( V_10 ) ;
return - V_32 ;
}
V_33 . V_14 = V_14 ;
V_33 . V_34 = V_15 ;
V_33 . V_16 = V_16 ;
V_33 . V_35 = 1 ;
V_33 . V_36 = 1 ;
V_33 . V_37 = V_15 + V_38 ;
V_33 . V_39 = V_40 ;
V_33 . V_41 = V_42 ;
V_33 . V_43 = V_44 ;
V_33 . V_45 = V_46 ;
V_33 . V_47 = V_18 ;
V_10 -> V_48 = & V_49 ;
F_10 ( V_10 , 0 ) ;
V_5 = F_11 ( V_10 ) ;
if ( V_5 ) {
F_12 ( V_29 , V_10 ) ;
F_9 ( V_10 ) ;
return V_5 ;
}
F_13 ( V_2 , V_10 ) ;
F_14 ( L_4 V_50 L_5 ,
V_10 -> V_14 , & V_2 -> V_6 , V_10 -> V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 )
{
F_16 ( V_10 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 )
{
if ( V_51 > 1 )
F_18 ( V_52 L_6 , V_10 -> V_14 ) ;
F_19 ( V_10 ) ;
return 0 ;
}
static void V_40 ( struct V_9 * V_10 )
{
F_18 ( V_53 L_7 ) ;
}
static void V_46 ( struct V_9 * V_10 ,
struct V_54 * V_55 , int V_56 )
{
int V_57 = V_10 -> V_27 ;
short * V_58 ;
unsigned long V_59 = ( V_57 - V_13 ) +
( ( V_56 - V_25 ) << 8 ) ;
V_58 = ( short * ) V_55 ;
* ( V_58 ++ ) = F_20 ( V_59 ) ;
* ( ( short * ) V_55 ) = F_21 ( * ( ( short * ) V_55 ) ) ;
V_59 += 2 ;
* ( V_58 ++ ) = F_20 ( V_59 ) ;
* ( ( short * ) V_55 + 1 ) = F_21 ( * ( ( short * ) V_55 + 1 ) ) ;
}
static void V_42 ( struct V_9 * V_10 , int V_60 ,
struct V_61 * V_62 , int V_63 )
{
unsigned long V_57 = V_10 -> V_27 ;
unsigned long V_64 = V_57 - V_13 ;
unsigned long V_65 = V_64 + V_63 - ( V_25 << 8 ) ;
if ( V_60 & 1 )
V_60 ++ ;
if ( V_65 + V_60 > V_64 + ( V_26 << 8 ) ) {
int V_66 = ( V_64 + ( V_26 << 8 ) ) - V_65 ;
F_22 ( V_62 -> V_67 , V_65 , V_66 ) ;
V_60 -= V_66 ;
F_22 ( V_62 -> V_67 + V_66 , V_64 , V_60 ) ;
} else
F_22 ( V_62 -> V_67 , V_65 , V_60 ) ;
}
static void V_44 ( struct V_9 * V_10 , int V_60 ,
const unsigned char * V_68 , int V_15 )
{
unsigned long V_57 = V_10 -> V_27 ;
unsigned long V_64 = V_57 - V_13 ;
if ( V_60 & 1 )
V_60 ++ ;
F_23 ( V_64 + ( ( V_15 - V_25 ) << 8 ) , V_68 , V_60 ) ;
}
static void T_3 F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_25 ( V_2 ) ;
F_26 ( V_10 ) ;
F_12 ( V_29 , V_10 ) ;
F_4 ( F_27 ( V_10 -> V_27 ) - V_13 , 0x10000 ) ;
F_9 ( V_10 ) ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_69 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_69 ) ;
}
