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
V_8 = 0x3 ;
V_9 = V_11 |
V_12 |
V_13 |
V_14 |
V_15 ;
F_1 ( V_2 , V_16 ,
( F_3 ( V_2 , V_16 ) & ~ V_9 ) | V_8 ) ;
F_1 ( V_2 , V_17 , 0 ) ;
F_1 ( V_2 , V_18 , 0 ) ;
F_1 ( V_2 , V_19 , 0 ) ;
F_1 ( V_2 , V_20 , 0 ) ;
V_9 = V_21 | V_22 |
V_23 ;
F_1 ( V_2 , V_24 , F_3 ( V_2 , V_24 ) & ~ V_9 ) ;
}
void F_7 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_8 ;
V_8 = F_3 ( V_2 , V_16 ) ;
V_8 &= ~ V_26 ;
V_8 |= ( ( V_25 << V_27 ) &
V_26 ) ;
F_1 ( V_2 , V_16 , V_8 ) ;
}
int F_8 ( struct V_1 * V_2 ,
T_1 V_28 , T_1 V_29 , T_1 V_30 ,
T_1 V_31 , T_1 V_32 , T_1 V_33 , T_1 V_34 ,
T_1 V_35 , T_1 V_36 )
{
T_1 V_37 ;
if ( V_2 -> V_38 () != 0 ) {
F_9 ( L_1 ) ;
return - 1 ;
}
F_1 ( V_2 , V_39 , V_28 ) ;
F_1 ( V_2 , V_40 ,
( ( V_29 / V_30 << V_41 ) &
V_42 ) |
( V_29 / V_30 & V_43 ) ) ;
F_1 ( V_2 , V_44 ,
( ( V_29 / V_30 << V_45 ) &
V_46 ) |
( V_29 / V_30 & V_47 ) ) ;
F_1 ( V_2 , V_48 , V_35 ) ;
F_1 ( V_2 , V_49 ,
( ( V_31 << V_50 ) & V_51 ) |
( V_32 & V_52 ) ) ;
F_1 ( V_2 , V_53 ,
( ( V_33 << V_54 ) & V_55 ) |
( V_34 & V_56 ) ) ;
V_37 = V_57 | V_58 |
V_59 | V_60 |
( V_36 & V_61 ) ;
F_1 ( V_2 , V_24 , V_37 ) ;
return 0 ;
}
int F_10 (
struct V_1 * V_2 ,
unsigned int V_62 ,
unsigned int V_63 ,
unsigned int V_64 ,
unsigned int V_65 ,
unsigned int V_66 ,
unsigned int V_67 ,
unsigned int V_30 ,
unsigned int V_68 ,
unsigned int V_69 ,
unsigned int V_33 ,
unsigned int V_34 ,
unsigned int V_70 )
{
unsigned int V_71 , V_72 ;
V_71 = V_73 ;
V_72 = 0 ;
if ( V_62 == V_66 && V_63 == V_67 ) {
if ( V_65 < V_69 ) {
V_71 = V_74 ;
} else if ( V_65 > V_69 ) {
V_71 = V_75 ;
} else {
if ( V_64 <= V_68 ) {
V_71 = V_76 ;
} else {
V_71 = V_73 ;
}
}
}
if ( ( V_71 == V_74 ) || ( V_71 == V_76 ) ) {
V_64 += V_33 - 1 ;
V_65 += V_34 - 1 ;
V_68 += V_33 - 1 ;
V_69 += V_34 - 1 ;
}
F_1 ( V_2 , V_77 , V_62 ) ;
F_1 ( V_2 , V_39 , V_66 ) ;
F_1 ( V_2 , V_40 ,
( ( V_67 / V_30 << V_41 ) &
V_42 ) |
( V_63 / V_30 & V_43 ) ) ;
F_1 ( V_2 , V_44 ,
( ( V_67 / V_30 << V_45 ) &
V_46 ) |
( V_63 / V_30 & V_47 ) ) ;
if ( V_2 -> V_38 () != 0 )
return - 1 ;
F_1 ( V_2 , V_78 ,
( ( V_64 << V_79 ) & V_80 ) |
( V_65 & V_81 ) ) ;
F_1 ( V_2 , V_49 ,
( ( V_68 << V_50 ) & V_51 ) |
( V_69 & V_52 ) ) ;
F_1 ( V_2 , V_53 ,
( ( V_33 << V_54 ) & V_55 ) |
( V_34 & V_56 ) ) ;
V_72 = ( V_70 & V_61 ) | V_60 |
( ( V_71 == V_76 ) ? V_82 : 0 ) |
V_83 | V_57 ;
F_1 ( V_2 , V_24 , V_72 ) ;
return 0 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
unsigned int V_72 ;
V_72 = F_3 ( V_2 , V_24 ) ;
V_72 &= ( V_22 |
V_23 | V_21 ) ;
return V_72 ;
}
int F_12 ( struct V_1 * V_2 ,
const char * V_84 ,
T_1 V_85 ,
T_1 V_86 ,
T_1 V_66 ,
T_1 V_67 ,
T_1 V_87 ,
T_1 V_68 ,
T_1 V_69 ,
T_1 V_33 ,
T_1 V_34 ,
T_1 V_88 ,
T_1 V_89 ,
T_1 V_70 )
{
unsigned int V_90 ;
unsigned int V_91 ;
unsigned int V_92 ;
unsigned int V_72 = 0 ;
unsigned char V_93 [ 4 ] ;
int V_94 , V_95 ;
V_86 &= 7 ;
V_90 = ( V_33 + V_86 + 7 ) / 8 ;
V_91 = V_90 & ~ 3 ;
V_92 = V_90 & 3 ;
if ( V_2 -> V_38 () != 0 )
return - 1 ;
F_1 ( V_2 , V_77 , 0 ) ;
F_1 ( V_2 , V_39 , V_66 ) ;
F_1 ( V_2 , V_40 ,
( ( V_67 / V_87 << V_41 ) &
V_42 ) |
( V_67 / V_87 & V_43 ) ) ;
F_1 ( V_2 , V_44 ,
( ( V_67 / V_87 << V_45 ) &
V_46 ) |
( V_67 / V_87 & V_47 ) ) ;
F_1 ( V_2 , V_78 ,
( V_86 << V_79 ) &
V_96 ) ;
F_1 ( V_2 , V_49 ,
( ( V_68 << V_50 ) & V_51 ) |
( V_69 & V_52 ) ) ;
F_1 ( V_2 , V_53 ,
( ( V_33 << V_54 ) & V_55 ) |
( V_34 & V_56 ) ) ;
F_1 ( V_2 , V_48 , V_88 ) ;
F_1 ( V_2 , V_97 , V_89 ) ;
V_72 = ( V_70 & V_61 ) |
V_60 | V_98 |
V_99 | V_57 ;
F_1 ( V_2 , V_24 , V_72 | F_11 ( V_2 ) ) ;
for ( V_94 = 0 ; V_94 < V_34 ; V_94 ++ ) {
for ( V_95 = 0 ; V_95 < ( V_91 / 4 ) ; V_95 ++ )
F_5 ( V_2 , * ( unsigned int * ) ( V_84 + ( V_95 * 4 ) ) ) ;
if ( V_92 ) {
memcpy ( V_93 , V_84 + V_91 , V_92 ) ;
F_5 ( V_2 , * ( unsigned int * ) V_93 ) ;
}
V_84 += V_85 ;
}
return 0 ;
}
