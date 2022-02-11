static inline void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
F_2 ( V_6 , V_2 -> V_7 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_8 , V_9 ;
F_1 ( V_2 , V_10 , 0xFFFFFFFF ) ;
V_8 = F_7 ( 0 , V_11 , V_12 , V_13 ) |
F_8 ( 0 , V_11 , V_14 , 0 ) |
F_8 ( 0 , V_11 , V_15 , 0 ) |
F_7 ( 0 , V_11 , V_16 , V_17 ) |
F_8 ( 0 , V_11 , V_18 , 3 ) ;
V_9 = F_9 ( V_11 , V_12 ) &
F_9 ( V_11 , V_14 ) &
F_9 ( V_11 , V_15 ) &
F_9 ( V_11 , V_16 ) &
F_9 ( V_11 , V_18 ) ;
F_1 ( V_2 , V_11 , ( F_3 ( V_2 , V_11 ) & V_9 ) | V_8 ) ;
F_1 ( V_2 , V_19 , 0 ) ;
F_1 ( V_2 , V_20 , 0 ) ;
F_1 ( V_2 , V_21 , 0 ) ;
F_1 ( V_2 , V_22 , 0 ) ;
V_8 = F_7 ( 0 , V_23 , V_24 , V_25 ) |
F_7 ( 0 , V_23 , V_26 , V_27 ) |
F_7 ( 0 , V_23 , V_28 , V_29 ) ;
V_9 = F_9 ( V_23 , V_24 ) &
F_9 ( V_23 , V_26 ) &
F_9 ( V_23 , V_28 ) ;
F_1 ( V_2 , V_23 , ( F_3 ( V_2 , V_23 ) & V_9 ) | V_8 ) ;
}
void F_10 ( struct V_1 * V_2 , int V_30 )
{
T_1 V_8 ;
V_8 = F_3 ( V_2 , V_11 ) ;
V_8 = F_8 ( V_8 , V_11 , V_31 , V_30 ) ;
F_1 ( V_2 , V_11 , V_8 ) ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_32 , T_1 V_33 , T_1 V_34 ,
T_1 V_35 , T_1 V_36 , T_1 V_37 , T_1 V_38 ,
T_1 V_39 , T_1 V_40 )
{
T_1 V_41 ;
if( V_2 -> V_42 () != 0 )
{
F_12 ( L_1 , V_43 ) ;
return - 1 ;
}
F_1 ( V_2 , V_44 , V_32 ) ;
F_1 ( V_2 , V_45 ,
F_8 ( 0 , V_45 , V_46 , V_33 / V_34 ) |
F_8 ( 0 , V_45 , V_29 , V_33 / V_34 ) ) ;
F_1 ( V_2 , V_47 ,
F_8 ( 0 , V_47 , V_46 , V_33 / V_34 ) |
F_8 ( 0 , V_47 , V_29 , V_33 / V_34 ) ) ;
F_1 ( V_2 , V_48 , V_39 ) ;
F_1 ( V_2 , V_49 ,
F_7 ( 0 , V_49 , V_50 , V_25 ) |
F_8 ( 0 , V_49 , V_51 , V_35 ) |
F_8 ( 0 , V_49 , V_52 , V_36 ) ) ;
F_1 ( V_2 , V_53 ,
F_8 ( 0 , V_53 , V_51 , V_37 ) |
F_8 ( 0 , V_53 , V_54 , V_38 ) ) ;
V_41 =
F_7 ( 0 , V_23 , V_55 , V_56 ) |
F_7 ( 0 , V_23 , V_57 , V_58 ) |
F_7 ( 0 , V_23 , V_59 , V_60 ) |
F_7 ( 0 , V_23 , V_61 , V_62 ) |
F_7 ( 0 , V_23 , V_63 , V_64 ) |
F_8 ( 0 , V_23 , V_65 , V_40 ) ;
F_1 ( V_2 , V_23 , V_41 ) ;
return 0 ;
}
int F_13 (
struct V_1 * V_2 ,
unsigned int V_66 ,
unsigned int V_67 ,
unsigned int V_68 ,
unsigned int V_69 ,
unsigned int V_70 ,
unsigned int V_71 ,
unsigned int V_34 ,
unsigned int V_72 ,
unsigned int V_73 ,
unsigned int V_37 ,
unsigned int V_38 ,
unsigned int V_74 )
{
unsigned int V_75 , V_76 ;
int V_77 ;
V_75 = V_58 ;
V_77 = 1 ;
V_76 = 0 ;
if ( V_66 == V_70 && V_67 == V_71 )
{
if ( V_69 < V_73 )
{
V_75 = V_78 ;
}
else if ( V_69 > V_73 )
{
V_75 = V_79 ;
}
else
{
if ( V_68 <= V_72 )
{
V_75 = V_80 ;
}
else
{
V_75 = V_58 ;
}
}
}
if ( ( V_75 == V_78 ) || ( V_75 == V_80 ) )
{
V_68 += V_37 - 1 ;
V_69 += V_38 - 1 ;
V_72 += V_37 - 1 ;
V_73 += V_38 - 1 ;
V_77 = ( - 1 ) ;
}
F_1 ( V_2 , V_81 , V_66 ) ;
F_1 ( V_2 , V_44 , V_70 ) ;
#if 0
if(Bpp == 3){
sx *= 3;
dx *= 3;
width *= 3;
write_dpr(accel,DE_PITCH,
FIELD_VALUE(0, DE_PITCH, DESTINATION, dPitch) |
FIELD_VALUE(0, DE_PITCH, SOURCE, sPitch));
}
else
#endif
{
F_1 ( V_2 , V_45 ,
F_8 ( 0 , V_45 , V_46 , ( V_71 / V_34 ) ) |
F_8 ( 0 , V_45 , V_29 , ( V_67 / V_34 ) ) ) ;
}
F_1 ( V_2 , V_47 ,
F_8 ( 0 , V_47 , V_46 , ( V_71 / V_34 ) ) |
F_8 ( 0 , V_47 , V_29 , ( V_67 / V_34 ) ) ) ;
if ( V_2 -> V_42 () != 0 ) {
return - 1 ;
}
{
F_1 ( V_2 , V_82 ,
F_7 ( 0 , V_82 , V_50 , V_25 ) |
F_8 ( 0 , V_82 , V_83 , V_68 ) |
F_8 ( 0 , V_82 , V_84 , V_69 ) ) ;
F_1 ( V_2 , V_49 ,
F_7 ( 0 , V_49 , V_50 , V_25 ) |
F_8 ( 0 , V_49 , V_51 , V_72 ) |
F_8 ( 0 , V_49 , V_52 , V_73 ) ) ;
F_1 ( V_2 , V_53 ,
F_8 ( 0 , V_53 , V_51 , V_37 ) |
F_8 ( 0 , V_53 , V_54 , V_38 ) ) ;
V_76 =
F_8 ( 0 , V_23 , V_65 , V_74 ) |
F_7 ( 0 , V_23 , V_63 , V_64 ) |
F_7 ( 0 , V_23 , V_61 , V_85 ) |
( ( V_75 == V_80 ) ?
F_7 ( 0 , V_23 , V_57 , V_80 )
: F_7 ( 0 , V_23 , V_57 , V_58 ) ) |
F_7 ( 0 , V_23 , V_55 , V_56 ) ;
F_1 ( V_2 , V_23 , V_76 ) ;
}
return 0 ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
unsigned int V_76 ;
V_76 = F_3 ( V_2 , V_23 ) ;
V_76 &=
F_15 ( V_86 ) |
F_15 ( V_87 ) |
F_15 ( V_88 ) ;
return V_76 ;
}
int F_16 ( struct V_1 * V_2 ,
const char * V_89 ,
T_1 V_90 ,
T_1 V_91 ,
T_1 V_70 ,
T_1 V_71 ,
T_1 V_92 ,
T_1 V_72 ,
T_1 V_73 ,
T_1 V_37 ,
T_1 V_38 ,
T_1 V_93 ,
T_1 V_94 ,
T_1 V_74 )
{
unsigned int V_95 ;
unsigned int V_96 ;
unsigned int V_97 ;
unsigned int V_76 = 0 ;
unsigned char V_98 [ 4 ] ;
int V_99 , V_100 ;
V_91 &= 7 ;
V_95 = ( V_37 + V_91 + 7 ) / 8 ;
V_96 = V_95 & ~ 3 ;
V_97 = V_95 & 3 ;
if( V_2 -> V_42 () != 0 )
{
return - 1 ;
}
F_1 ( V_2 , V_81 , 0 ) ;
F_1 ( V_2 , V_44 , V_70 ) ;
#if 0
if(bytePerPixel == 3 ){
dx *= 3;
width *= 3;
startBit *= 3;
write_dpr(accel,DE_PITCH,
FIELD_VALUE(0, DE_PITCH, DESTINATION, dPitch) |
FIELD_VALUE(0, DE_PITCH, SOURCE, dPitch));
}
else
#endif
{
F_1 ( V_2 , V_45 ,
F_8 ( 0 , V_45 , V_46 , V_71 / V_92 ) |
F_8 ( 0 , V_45 , V_29 , V_71 / V_92 ) ) ;
}
F_1 ( V_2 , V_47 ,
F_8 ( 0 , V_47 , V_46 , ( V_71 / V_92 ) ) |
F_8 ( 0 , V_47 , V_29 , ( V_71 / V_92 ) ) ) ;
F_1 ( V_2 , V_82 ,
F_7 ( 0 , V_82 , V_50 , V_25 ) |
F_8 ( 0 , V_82 , V_101 , V_91 ) ) ;
F_1 ( V_2 , V_49 ,
F_7 ( 0 , V_49 , V_50 , V_25 ) |
F_8 ( 0 , V_49 , V_51 , V_72 ) |
F_8 ( 0 , V_49 , V_52 , V_73 ) ) ;
F_1 ( V_2 , V_53 ,
F_8 ( 0 , V_53 , V_51 , V_37 ) |
F_8 ( 0 , V_53 , V_54 , V_38 ) ) ;
F_1 ( V_2 , V_48 , V_93 ) ;
F_1 ( V_2 , V_102 , V_94 ) ;
V_76 = F_8 ( 0 , V_23 , V_65 , V_74 ) |
F_7 ( 0 , V_23 , V_63 , V_64 ) |
F_7 ( 0 , V_23 , V_61 , V_103 ) |
F_7 ( 0 , V_23 , V_104 , V_105 ) |
F_7 ( 0 , V_23 , V_55 , V_56 ) ;
F_1 ( V_2 , V_23 , V_76 | F_14 ( V_2 ) ) ;
for ( V_99 = 0 ; V_99 < V_38 ; V_99 ++ )
{
for ( V_100 = 0 ; V_100 < ( V_96 / 4 ) ; V_100 ++ )
{
F_5 ( V_2 , * ( unsigned int * ) ( V_89 + ( V_100 * 4 ) ) ) ;
}
if ( V_97 )
{
memcpy ( V_98 , V_89 + V_96 , V_97 ) ;
F_5 ( V_2 , * ( unsigned int * ) V_98 ) ;
}
V_89 += V_90 ;
}
return 0 ;
}
