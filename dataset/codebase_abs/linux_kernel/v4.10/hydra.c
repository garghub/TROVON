static int F_1 ( struct V_1 * V_2 ,
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
static int F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
unsigned long V_11 = ( unsigned long ) F_5 ( V_2 -> V_6 . V_7 ) ;
unsigned long V_12 = V_11 + V_13 ;
const char V_14 [] = L_2 ;
int V_15 , V_16 ;
int V_17 ;
int V_5 ;
struct V_18 * V_19 ;
static T_1 V_20 [ 16 ] = {
0x00 , 0x02 , 0x04 , 0x06 , 0x08 , 0x0a , 0x0c , 0x0e ,
0x10 , 0x12 , 0x14 , 0x16 , 0x18 , 0x1a , 0x1c , 0x1e ,
} ;
V_10 = F_6 ( 0 ) ;
if ( ! V_10 )
return - V_21 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ )
V_10 -> V_23 [ V_17 ] = * ( ( V_24 * ) ( V_11 + V_25 + 2 * V_17 ) ) ;
F_7 ( 0x4b , V_12 + V_26 ) ;
V_15 = V_27 ;
V_16 = V_28 ;
V_19 = F_8 ( V_10 ) ;
V_19 -> V_29 = V_30 ;
V_10 -> V_31 = V_12 ;
V_10 -> V_32 = V_33 ;
if ( F_9 ( V_33 , V_34 , V_35 , L_3 ,
V_10 ) ) {
F_10 ( V_10 ) ;
return - V_36 ;
}
V_37 . V_14 = V_14 ;
V_37 . V_38 = V_15 ;
V_37 . V_16 = V_16 ;
V_37 . V_39 = 1 ;
V_37 . V_40 = 1 ;
V_37 . V_41 = V_15 + V_42 ;
V_37 . V_43 = V_44 ;
V_37 . V_45 = V_46 ;
V_37 . V_47 = V_48 ;
V_37 . V_49 = V_50 ;
V_37 . V_51 = V_20 ;
V_10 -> V_52 = & V_53 ;
F_11 ( V_10 , 0 ) ;
V_5 = F_12 ( V_10 ) ;
if ( V_5 ) {
F_13 ( V_33 , V_10 ) ;
F_10 ( V_10 ) ;
return V_5 ;
}
F_14 ( V_2 , V_10 ) ;
F_15 ( L_4 V_54 L_5 ,
V_10 -> V_14 , & V_2 -> V_6 , V_10 -> V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 )
{
F_17 ( V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = F_8 ( V_10 ) ;
F_19 ( V_19 , V_55 , V_10 , L_6 ) ;
F_20 ( V_10 ) ;
return 0 ;
}
static void V_44 ( struct V_9 * V_10 )
{
F_21 ( V_10 , L_7 ) ;
}
static void V_50 ( struct V_9 * V_10 ,
struct V_56 * V_57 , int V_58 )
{
int V_59 = V_10 -> V_31 ;
short * V_60 ;
unsigned long V_61 = ( V_59 - V_13 ) +
( ( V_58 - V_27 ) << 8 ) ;
V_60 = ( short * ) V_57 ;
* ( V_60 ++ ) = F_22 ( V_61 ) ;
* ( ( short * ) V_57 ) = F_23 ( * ( ( short * ) V_57 ) ) ;
V_61 += 2 ;
* ( V_60 ++ ) = F_22 ( V_61 ) ;
* ( ( short * ) V_57 + 1 ) = F_23 ( * ( ( short * ) V_57 + 1 ) ) ;
}
static void V_46 ( struct V_9 * V_10 , int V_62 ,
struct V_63 * V_64 , int V_65 )
{
unsigned long V_59 = V_10 -> V_31 ;
unsigned long V_66 = V_59 - V_13 ;
unsigned long V_67 = V_66 + V_65 - ( V_27 << 8 ) ;
if ( V_62 & 1 )
V_62 ++ ;
if ( V_67 + V_62 > V_66 + ( V_28 << 8 ) ) {
int V_68 = ( V_66 + ( V_28 << 8 ) ) - V_67 ;
F_24 ( V_64 -> V_69 , V_67 , V_68 ) ;
V_62 -= V_68 ;
F_24 ( V_64 -> V_69 + V_68 , V_66 , V_62 ) ;
} else
F_24 ( V_64 -> V_69 , V_67 , V_62 ) ;
}
static void V_48 ( struct V_9 * V_10 , int V_62 ,
const unsigned char * V_70 , int V_15 )
{
unsigned long V_59 = V_10 -> V_31 ;
unsigned long V_66 = V_59 - V_13 ;
if ( V_62 & 1 )
V_62 ++ ;
F_25 ( V_66 + ( ( V_15 - V_27 ) << 8 ) , V_70 , V_62 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_27 ( V_2 ) ;
F_28 ( V_10 ) ;
F_13 ( V_33 , V_10 ) ;
F_4 ( F_29 ( V_10 -> V_31 ) - V_13 , 0x10000 ) ;
F_10 ( V_10 ) ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_71 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_71 ) ;
}
