static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_12 * V_13 ;
V_13 = F_2 ( & V_10 -> V_5 , V_3 , true ) ;
return ( ! F_3 ( V_13 ) ) ? F_4 ( V_13 ) / 1000 : 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_15 * V_15 = F_7 ( V_14 ) ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < F_8 ( V_17 ) ; V_16 ++ )
F_9 ( V_2 , V_17 [ V_16 ] . V_18 ,
V_17 [ V_16 ] . V_19 ) ;
F_9 ( V_2 , V_20 , 0x60007 ) ;
F_9 ( V_2 , V_21 , 0x01 ) ;
F_9 ( V_2 , V_22 , 0x01 ) ;
F_9 ( V_2 , V_23 , 0x80000000 | 0 ) ;
F_9 ( V_2 , V_24 , V_15 -> V_25 ) ;
F_9 ( V_2 , V_26 , 0x80000000 | 6000 ) ;
F_9 ( V_2 , V_27 , 0x10001FFF ) ;
F_9 ( V_2 , V_28 , 0x00201FF1 ) ;
F_9 ( V_2 , V_27 , 0x10001FFF ) ;
F_9 ( V_2 , V_28 , 0x201FF1 ) ;
F_9 ( V_2 , V_29 , 1 ) ;
F_9 ( V_2 , V_30 , V_31 ) ;
F_9 ( V_2 , F_10 ( 0 ) , 5448 ) ;
F_9 ( V_2 , F_10 ( 1 ) , 1 ) ;
F_9 ( V_2 , F_10 ( 2 ) , F_1 ( V_2 , V_2 -> V_32 ) ) ;
F_9 ( V_2 , F_10 ( 3 ) , V_2 -> V_32 / 1000000 ) ;
F_9 ( V_2 , V_33 , 4 * sizeof( T_1 ) ) ;
F_9 ( V_2 , V_34 , V_35 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_36 , 0x7F ) ;
F_9 ( V_2 , V_37 , 0 ) ;
F_9 ( V_2 , V_38 , 0xA0080 ) ;
F_9 ( V_2 , V_39 , 0x600040 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_15 * V_15 = F_7 ( V_14 ) ;
struct V_40 * V_41 = V_2 -> V_42 ;
if ( ! V_15 -> V_43 )
return 0 ;
F_13 ( V_41 , V_44 , 1 ) ;
F_14 ( V_41 , 0 ) ;
F_13 ( V_41 , V_45 , 3 ) ;
F_14 ( V_41 , F_15 ( V_15 -> V_46 ) ) ;
F_14 ( V_41 , F_16 ( V_15 -> V_46 ) ) ;
F_14 ( V_41 , V_15 -> V_43 ) ;
F_13 ( V_41 , V_44 , 1 ) ;
F_14 ( V_41 , 1 ) ;
V_2 -> V_47 -> V_48 ( V_2 ) ;
if ( ! F_17 ( V_2 ) ) {
F_18 ( L_1 ,
V_2 -> V_49 ) ;
return - V_50 ;
}
F_9 ( V_2 , V_51 , 0x4014 ) ;
F_9 ( V_2 , V_52 , 0x0 ) ;
if ( F_19 ( V_2 , 25 , V_53 , 0xFFFFFFFF ,
0xBABEFACE ) )
F_18 ( L_2 ,
V_2 -> V_49 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_54 , 0x0 ) ;
F_9 ( V_2 , V_55 , 0x0A ) ;
F_9 ( V_2 , V_56 , 0x01 ) ;
F_9 ( V_2 , V_57 , 0x50000 ) ;
F_9 ( V_2 , V_58 , 0x30000 ) ;
F_9 ( V_2 , V_59 , 0x011 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_60 ;
F_5 ( V_2 ) ;
F_11 ( V_2 ) ;
V_60 = F_12 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_20 ( V_2 ) ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_15 * V_15 = F_7 ( V_14 ) ;
struct V_4 * V_61 = V_2 -> V_5 ;
const struct V_62 * V_63 ;
T_1 V_64 = 0 , V_65 = 0 , V_66 ;
unsigned int * V_67 , * V_68 , * V_69 ;
unsigned int V_70 ;
if ( V_15 -> V_71 )
return;
if ( F_23 ( & V_63 , V_14 -> V_72 -> V_73 , V_61 -> V_5 ) ) {
F_18 ( L_3 ,
V_2 -> V_49 ) ;
return;
}
V_67 = ( unsigned int * ) V_63 -> V_67 ;
if ( V_63 -> V_74 < 8 || ( V_67 [ 0 ] < 2 ) || ( V_67 [ 0 ] >= ( V_63 -> V_74 >> 2 ) ) )
goto V_75;
if ( V_67 [ 1 ] != 2 )
goto V_75;
V_69 = V_67 + V_67 [ 2 ] + 3 ;
V_70 = V_67 [ 0 ] - V_67 [ 2 ] - 2 ;
V_66 = ( V_70 + ( V_70 / V_76 ) + 1 ) << 2 ;
V_15 -> V_71 = F_24 ( V_61 , V_66 , V_77 ) ;
if ( F_3 ( V_15 -> V_71 ) )
goto V_78;
if ( F_25 ( V_15 -> V_71 , V_2 -> V_79 ,
& V_15 -> V_46 ) )
goto V_78;
V_68 = F_26 ( V_15 -> V_71 ) ;
if ( ! V_68 )
goto V_78;
while ( V_70 > 0 ) {
int V_16 ;
T_1 V_80 = V_70 > V_76 ?
V_76 : V_70 ;
V_68 [ V_64 ++ ] = F_27 ( V_81 + V_65 ,
V_80 ) ;
for ( V_16 = 0 ; V_16 < V_80 ; V_16 ++ )
V_68 [ V_64 ++ ] = * V_69 ++ ;
V_65 += V_80 ;
V_70 -= V_80 ;
}
F_28 ( V_15 -> V_71 ) ;
V_15 -> V_43 = V_64 ;
goto V_75;
V_78:
if ( V_15 -> V_46 )
F_29 ( V_15 -> V_71 , V_2 -> V_79 ) ;
if ( V_15 -> V_71 )
F_30 ( V_15 -> V_71 ) ;
V_15 -> V_71 = NULL ;
V_15 -> V_46 = 0 ;
V_15 -> V_43 = 0 ;
V_75:
F_31 ( V_63 ) ;
}
