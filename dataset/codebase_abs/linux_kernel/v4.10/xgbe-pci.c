static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 , V_5 ;
int V_6 ;
V_3 = V_7 ;
V_3 += F_2 ( V_2 -> V_8 ,
V_2 -> V_9 ) ;
V_3 = F_3 ( V_3 ) ;
V_6 = F_4 ( V_2 -> V_10 , V_3 ) ;
if ( V_6 < 0 ) {
F_5 ( V_2 -> V_11 , L_1 ,
V_3 ) ;
V_6 = F_6 ( V_2 -> V_10 ) ;
if ( V_6 < 0 ) {
F_5 ( V_2 -> V_11 , L_2 ) ;
return V_6 ;
}
V_3 = 1 ;
}
V_2 -> V_12 = V_3 ;
V_2 -> V_13 = V_2 -> V_10 -> V_14 ;
if ( V_3 > 1 ) {
V_2 -> V_15 = V_2 -> V_10 -> V_14 + 1 ;
V_2 -> V_16 = V_2 -> V_10 -> V_14 + 2 ;
V_2 -> V_17 = V_2 -> V_10 -> V_14 + 3 ;
for ( V_4 = V_7 , V_5 = 0 ;
( V_4 < V_3 ) && ( V_5 < V_18 ) ;
V_4 ++ , V_5 ++ )
V_2 -> V_19 [ V_5 ] = V_2 -> V_10 -> V_14 + V_4 ;
V_2 -> V_20 = V_5 ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = V_23 ;
} else {
V_2 -> V_15 = V_2 -> V_10 -> V_14 ;
V_2 -> V_16 = V_2 -> V_10 -> V_14 ;
V_2 -> V_17 = V_2 -> V_10 -> V_14 ;
}
if ( F_7 ( V_2 ) )
F_8 ( V_2 -> V_11 , L_3 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned int V_24 ;
unsigned int V_4 , V_5 ;
int V_6 ;
V_24 = V_7 ;
V_24 += F_2 ( V_2 -> V_8 ,
V_2 -> V_9 ) ;
V_2 -> V_25 = F_10 ( V_2 -> V_11 , V_24 ,
sizeof( struct V_26 ) ,
V_27 ) ;
if ( ! V_2 -> V_25 )
return - V_28 ;
for ( V_4 = 0 ; V_4 < V_24 ; V_4 ++ )
V_2 -> V_25 [ V_4 ] . V_29 = V_4 ;
V_6 = F_11 ( V_2 -> V_10 , V_2 -> V_25 ,
V_30 , V_24 ) ;
if ( V_6 < 0 ) {
F_5 ( V_2 -> V_11 , L_4 ) ;
F_12 ( V_2 -> V_11 , V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
return V_6 ;
}
V_2 -> V_12 = V_6 ;
V_2 -> V_13 = V_2 -> V_25 [ 0 ] . V_31 ;
V_2 -> V_15 = V_2 -> V_25 [ 1 ] . V_31 ;
V_2 -> V_16 = V_2 -> V_25 [ 2 ] . V_31 ;
V_2 -> V_17 = V_2 -> V_25 [ 3 ] . V_31 ;
for ( V_4 = V_7 , V_5 = 0 ; V_4 < V_6 ; V_4 ++ , V_5 ++ )
V_2 -> V_19 [ V_5 ] = V_2 -> V_25 [ V_4 ] . V_31 ;
V_2 -> V_20 = V_5 ;
V_2 -> V_21 = 1 ;
V_2 -> V_22 = V_23 ;
if ( F_7 ( V_2 ) )
F_8 ( V_2 -> V_11 , L_5 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_9 ( V_2 ) ;
if ( ! V_6 )
goto V_32;
V_6 = F_1 ( V_2 ) ;
if ( ! V_6 )
goto V_32;
V_2 -> V_12 = 1 ;
V_2 -> V_33 = 1 ;
V_2 -> V_13 = V_2 -> V_10 -> V_14 ;
V_2 -> V_15 = V_2 -> V_10 -> V_14 ;
V_2 -> V_16 = V_2 -> V_10 -> V_14 ;
V_2 -> V_17 = V_2 -> V_10 -> V_14 ;
V_32:
if ( F_7 ( V_2 ) ) {
unsigned int V_4 ;
F_8 ( V_2 -> V_11 , L_6 , V_2 -> V_13 ) ;
F_8 ( V_2 -> V_11 , L_7 , V_2 -> V_15 ) ;
F_8 ( V_2 -> V_11 , L_8 , V_2 -> V_16 ) ;
F_8 ( V_2 -> V_11 , L_9 , V_2 -> V_17 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_20 ; V_4 ++ )
F_8 ( V_2 -> V_11 , L_10 ,
V_4 , V_2 -> V_19 [ V_4 ] ) ;
}
return 0 ;
}
static int F_14 ( struct V_34 * V_35 , const struct V_36 * V_37 )
{
struct V_1 * V_2 ;
struct V_38 * V_11 = & V_35 -> V_11 ;
void T_1 * const * V_39 ;
struct V_34 * V_40 ;
unsigned int V_41 , V_42 ;
unsigned int V_43 ;
int V_44 ;
int V_6 ;
V_2 = F_15 ( V_11 ) ;
if ( F_16 ( V_2 ) ) {
V_6 = F_17 ( V_2 ) ;
goto V_45;
}
V_2 -> V_10 = V_35 ;
F_18 ( V_35 , V_2 ) ;
V_2 -> V_46 = (struct V_47 * ) V_37 -> V_48 ;
V_6 = F_19 ( V_35 ) ;
if ( V_6 ) {
F_20 ( V_11 , L_11 ) ;
goto V_49;
}
V_44 = F_21 ( V_35 , V_50 ) ;
V_6 = F_22 ( V_35 , V_44 , V_51 ) ;
if ( V_6 ) {
F_20 ( V_11 , L_12 ) ;
goto V_49;
}
V_39 = F_23 ( V_35 ) ;
if ( ! V_39 ) {
F_20 ( V_11 , L_13 ) ;
V_6 = - V_28 ;
goto V_49;
}
V_2 -> V_52 = V_39 [ V_53 ] ;
if ( ! V_2 -> V_52 ) {
F_20 ( V_11 , L_14 ) ;
V_6 = - V_28 ;
goto V_49;
}
V_2 -> V_54 = V_2 -> V_52 + V_55 ;
V_2 -> V_56 = V_2 -> V_52 + V_57 ;
if ( F_7 ( V_2 ) ) {
F_8 ( V_11 , L_15 , V_2 -> V_52 ) ;
F_8 ( V_11 , L_16 , V_2 -> V_54 ) ;
F_8 ( V_11 , L_17 , V_2 -> V_56 ) ;
}
V_2 -> V_58 = V_39 [ V_59 ] ;
if ( ! V_2 -> V_58 ) {
F_20 ( V_11 , L_18 ) ;
V_6 = - V_28 ;
goto V_49;
}
if ( F_7 ( V_2 ) )
F_8 ( V_11 , L_19 , V_2 -> V_58 ) ;
V_40 = F_24 ( 0 , 0 , F_25 ( 0 , 0 ) ) ;
if ( V_40 &&
( V_40 -> V_60 == V_61 ) && ( V_40 -> V_38 == 0x15d0 ) ) {
V_2 -> V_62 = V_63 ;
V_2 -> V_64 = V_65 ;
} else {
V_2 -> V_62 = V_66 ;
V_2 -> V_64 = V_67 ;
}
F_26 ( V_40 ) ;
V_43 = F_27 ( V_2 , V_2 -> V_62 ) ;
V_2 -> V_68 = F_28 ( V_43 , V_66 , V_69 ) ;
V_2 -> V_68 <<= 6 ;
V_2 -> V_70 = F_28 ( V_43 , V_66 , V_71 ) ;
V_2 -> V_70 = 1 << ( V_2 -> V_70 + 7 ) ;
V_2 -> V_72 = V_2 -> V_70 - 1 ;
if ( F_7 ( V_2 ) ) {
F_8 ( V_11 , L_20 ,
V_2 -> V_68 ) ;
F_8 ( V_11 , L_21 ,
V_2 -> V_70 ) ;
F_8 ( V_11 , L_22 ,
V_2 -> V_72 ) ;
}
F_29 ( V_35 ) ;
F_30 ( V_2 , V_73 , 0x1fffff ) ;
V_41 = F_31 ( V_2 , V_74 ) ;
V_42 = F_31 ( V_2 , V_75 ) ;
V_2 -> V_76 [ 0 ] = V_41 & 0xff ;
V_2 -> V_76 [ 1 ] = ( V_41 >> 8 ) & 0xff ;
V_2 -> V_76 [ 2 ] = ( V_41 >> 16 ) & 0xff ;
V_2 -> V_76 [ 3 ] = ( V_41 >> 24 ) & 0xff ;
V_2 -> V_76 [ 4 ] = V_42 & 0xff ;
V_2 -> V_76 [ 5 ] = ( V_42 >> 8 ) & 0xff ;
if ( ! F_32 ( V_42 , V_75 , V_77 ) ||
! F_33 ( V_2 -> V_76 ) ) {
F_20 ( V_11 , L_23 ) ;
V_6 = - V_78 ;
goto V_49;
}
V_2 -> V_79 = V_80 ;
V_2 -> V_81 = V_82 ;
V_2 -> V_83 = 1 ;
V_2 -> V_84 = V_85 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = V_89 ;
V_43 = F_31 ( V_2 , V_90 ) ;
V_2 -> V_91 = F_32 ( V_43 , V_90 , V_92 ) ;
V_2 -> V_93 = F_32 ( V_43 , V_90 , V_94 ) ;
V_2 -> V_95 = F_32 ( V_43 , V_90 , V_96 ) ;
V_2 -> V_97 = F_32 ( V_43 , V_90 , V_98 ) ;
if ( F_7 ( V_2 ) ) {
F_8 ( V_11 , L_24 ,
V_2 -> V_91 ,
V_2 -> V_91 ) ;
F_8 ( V_11 , L_25 ,
V_2 -> V_95 , V_2 -> V_97 ) ;
}
F_34 ( V_2 ) ;
V_43 = F_31 ( V_2 , V_99 ) ;
V_2 -> V_100 = F_32 ( V_43 , V_99 , V_101 ) ;
V_2 -> V_100 *= 16384 ;
V_2 -> V_100 = F_35 ( V_2 -> V_100 ,
V_2 -> V_46 -> V_100 ) ;
V_2 -> V_102 = F_32 ( V_43 , V_99 , V_103 ) ;
V_2 -> V_102 *= 16384 ;
V_2 -> V_102 = F_35 ( V_2 -> V_102 ,
V_2 -> V_46 -> V_102 ) ;
if ( F_7 ( V_2 ) )
F_8 ( V_11 , L_26 ,
V_2 -> V_100 , V_2 -> V_102 ) ;
V_6 = F_13 ( V_2 ) ;
if ( V_6 )
goto V_49;
V_6 = F_36 ( V_2 ) ;
if ( V_6 )
goto V_49;
F_37 ( V_2 -> V_104 , L_27 ) ;
return 0 ;
V_49:
F_38 ( V_2 ) ;
V_45:
F_39 ( V_11 , L_28 ) ;
return V_6 ;
}
static void F_40 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
F_42 ( V_2 ) ;
F_38 ( V_2 ) ;
}
static int F_43 ( struct V_34 * V_35 , T_2 V_105 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
struct V_106 * V_104 = V_2 -> V_104 ;
int V_6 = 0 ;
if ( F_44 ( V_104 ) )
V_6 = F_45 ( V_104 , V_107 ) ;
V_2 -> V_108 = F_46 ( V_2 , V_109 , V_110 ) ;
V_2 -> V_108 |= V_111 ;
F_47 ( V_2 , V_109 , V_110 , V_2 -> V_108 ) ;
return V_6 ;
}
static int F_48 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
struct V_106 * V_104 = V_2 -> V_104 ;
int V_6 = 0 ;
V_2 -> V_108 &= ~ V_111 ;
F_47 ( V_2 , V_109 , V_110 , V_2 -> V_108 ) ;
if ( F_44 ( V_104 ) ) {
V_6 = F_49 ( V_104 , V_107 ) ;
F_50 ( & V_2 -> V_112 ) ;
}
return V_6 ;
}
int F_51 ( void )
{
return F_52 ( & V_113 ) ;
}
void F_53 ( void )
{
F_54 ( & V_113 ) ;
}
