void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned V_5 )
{
( void ) V_5 ;
V_2 -> V_6 =
F_2 ( V_4 -> V_7 -> V_8 . V_9 ) ;
V_2 -> V_10 =
F_3 ( V_4 -> V_7 -> V_8 . V_11 ) ;
}
void
F_4 (
const struct V_12 * V_13 ,
const struct V_14 * V_7 )
{
struct V_3 V_15 = V_16 ;
V_15 . V_7 = V_7 ;
F_5 ( V_13 , & V_15 ) ;
}
static void
F_6 (
struct V_17 * V_18 ,
const struct V_19 * V_15 ,
unsigned int V_20 ,
unsigned int V_21 ,
unsigned int V_22 ,
unsigned int V_23 )
{
unsigned int V_24 , V_25 ;
#ifndef F_7
#endif
T_1 V_26 = { 0 } ;
unsigned int V_27 , V_28 , V_29 , V_30 ,
V_31 , V_32 , V_33 , V_34 ;
unsigned int V_35 , V_36 , V_37 , V_38 ;
unsigned int V_39 , V_40 , V_41 , V_42 ,
V_43 , V_44 ;
unsigned int V_45 = ( V_46 == V_47 ?
V_48 : V_49 ) ;
unsigned int V_50 = ( V_23 ? F_8 ( V_22 ) : F_3 ( V_22 ) ) ;
unsigned int V_51 = ( V_23 ? F_9 ( V_21 ) : F_2 ( V_21 ) ) ;
unsigned int V_52 = V_20 * V_53 ;
unsigned V_9 , V_11 ;
unsigned int * V_54 = NULL ;
unsigned int * V_55 = NULL ;
struct V_56 * V_57 ;
assert ( V_15 != NULL ) ;
assert ( V_18 != NULL ) ;
assert ( V_18 -> V_58 != NULL ) ;
V_57 = (struct V_56 * ) V_18 -> V_58 ;
V_57 += ( 2 * V_23 ) ;
if( V_23 == 0 )
{
V_54 = V_15 -> V_59 ;
V_55 = V_15 -> V_60 ;
V_9 = V_15 -> V_61 ;
V_11 = V_15 -> V_62 ;
}
else
{
V_54 = V_15 -> V_63 ;
V_55 = V_15 -> V_64 ;
V_9 = V_15 -> V_65 ;
V_11 = V_15 -> V_66 ;
}
F_10 ( L_1 ,
V_67 , V_68 >> V_23 ) ;
F_10 ( L_2 , V_51 , V_50 ) ;
F_10 ( L_3 , V_9 , V_11 ) ;
assert ( V_9 == V_51 + 1 ) ;
assert ( V_11 == V_50 + 1 ) ;
for ( V_25 = 0 ; V_25 < V_50 ; V_25 ++ ) {
for ( V_24 = 0 ; V_24 < V_51 ; V_24 ++ ) {
V_27 = V_54 [ V_25 * V_9 + V_24 ] ;
V_28 = V_54 [ V_25 * V_9 + ( V_24 + 1 ) ] ;
V_29 = V_54 [ ( V_25 + 1 ) * V_9 + V_24 ] ;
V_30 = V_54 [ ( V_25 + 1 ) * V_9 + ( V_24 + 1 ) ] ;
V_31 = V_55 [ V_25 * V_9 + V_24 ] ;
V_32 = V_55 [ V_25 * V_9 + ( V_24 + 1 ) ] ;
V_33 = V_55 [ ( V_25 + 1 ) * V_9 + V_24 ] ;
V_34 = V_55 [ ( V_25 + 1 ) * V_9 + ( V_24 + 1 ) ] ;
V_35 = F_11 ( V_27 , V_29 ) ;
V_37 = F_12 ( V_28 , V_30 ) ;
V_36 = F_11 ( V_31 , V_32 ) ;
V_38 = F_12 ( V_33 , V_34 ) ;
assert ( V_28 >= V_35 ) ;
assert ( V_30 >= V_35 ) ;
assert ( V_33 >= V_36 ) ;
assert ( V_34 >= V_36 ) ;
V_40 = V_36 >> V_69 ;
V_39 = ( ( V_35 >> V_69 )
>> V_70 )
<< ( V_70 ) ;
V_26 . V_71 = V_40 * V_52 + V_39 ;
V_42 = F_13 ( V_38 , 1 << V_69 ) ;
V_26 . V_72 = V_42 - V_40 + V_45 ;
V_41 = F_13 ( V_37 , 1 << V_69 ) ;
V_26 . V_73 = V_41 - V_39 + V_45 ;
V_43 = V_39 << ( V_69 ) ;
V_44 = V_40 << ( V_69 ) ;
V_26 . V_74 = V_27 - V_43 ;
V_26 . V_75 = V_28 - V_43 ;
V_26 . V_76 = V_29 - V_43 ;
V_26 . V_77 = V_30 - V_43 ;
V_26 . V_78 = V_31 - V_44 ;
V_26 . V_79 = V_32 - V_44 ;
V_26 . V_80 = V_33 - V_44 ;
V_26 . V_81 = V_34 - V_44 ;
assert ( V_26 . V_74 < ( V_26 . V_73 << V_69 ) ) ;
assert ( V_26 . V_75 < ( V_26 . V_73 << V_69 ) ) ;
assert ( V_26 . V_76 < ( V_26 . V_73 << V_69 ) ) ;
assert ( V_26 . V_77 < ( V_26 . V_73 << V_69 ) ) ;
assert ( V_26 . V_78 < ( V_26 . V_72 << V_69 ) ) ;
assert ( V_26 . V_79 < ( V_26 . V_72 << V_69 ) ) ;
assert ( V_26 . V_80 < ( V_26 . V_72 << V_69 ) ) ;
assert ( V_26 . V_81 < ( V_26 . V_72 << V_69 ) ) ;
assert ( V_26 . V_74 < V_26 . V_75 ) ;
assert ( V_26 . V_76 < V_26 . V_77 ) ;
assert ( V_26 . V_78 < V_26 . V_80 ) ;
assert ( V_26 . V_79 < V_26 . V_81 ) ;
#if 0
printf("j: %d\ti:%d\n", j, i);
printf("offset: %d\n", s.in_addr_offset);
printf("p0_x: %d\n", s.p0_x);
printf("p0_y: %d\n", s.p0_y);
printf("p1_x: %d\n", s.p1_x);
printf("p1_y: %d\n", s.p1_y);
printf("p2_x: %d\n", s.p2_x);
printf("p2_y: %d\n", s.p2_y);
printf("p3_x: %d\n", s.p3_x);
printf("p3_y: %d\n", s.p3_y);
printf("p0_x_nofrac[0]: %d\n", s.p0_x>>DVS_COORD_FRAC_BITS);
printf("p0_y_nofrac[1]: %d\n", s.p0_y>>DVS_COORD_FRAC_BITS);
printf("p1_x_nofrac[2]: %d\n", s.p1_x>>DVS_COORD_FRAC_BITS);
printf("p1_y_nofrac[3]: %d\n", s.p1_y>>DVS_COORD_FRAC_BITS);
printf("p2_x_nofrac[0]: %d\n", s.p2_x>>DVS_COORD_FRAC_BITS);
printf("p2_y_nofrac[1]: %d\n", s.p2_y>>DVS_COORD_FRAC_BITS);
printf("p3_x_nofrac[2]: %d\n", s.p3_x>>DVS_COORD_FRAC_BITS);
printf("p3_y_nofrac[3]: %d\n", s.p3_y>>DVS_COORD_FRAC_BITS);
printf("\n");
#endif
* V_57 = V_26 ;
if ( V_23 )
V_57 += 3 ;
else
V_57 += ( 1 + ( V_24 & 1 ) ) ;
}
}
}
struct V_17 *
F_14 (
const struct V_19 * V_82 ,
const struct V_12 * V_13 ,
const struct V_14 * V_83 )
{
unsigned int V_20 ;
unsigned int V_21 ;
unsigned int V_22 ;
struct V_17 * V_84 ;
struct V_56 * V_85 ;
assert ( V_13 != NULL ) ;
assert ( V_82 != NULL ) ;
assert ( V_83 != NULL ) ;
V_84 = F_15 ( ( V_86 ) ( ( F_16 ( V_13 ) / 2 ) * 3 ) ) ;
if ( ! V_84 )
return NULL ;
assert ( ( V_83 -> V_87 == V_88 )
|| ( V_83 -> V_87 == V_89 ) ) ;
V_85 = (struct V_56 * ) V_84 -> V_58 ;
V_20 = V_83 -> V_90 ;
V_21 = V_13 -> V_91 [ 0 ] . V_8 . V_9 ;
V_22 = V_13 -> V_91 [ 0 ] . V_8 . V_11 ;
F_6 ( V_84 , V_82 ,
V_20 , V_21 , V_22 , 0 ) ;
if ( V_83 -> V_87 == V_89 ) {
V_20 /= 2 ;
}
F_6 ( V_84 , V_82 ,
V_20 , V_21 / 2 , V_22 / 2 , 1 ) ;
return V_84 ;
}
enum V_92
F_17 (
const struct V_19 * V_82 ,
const struct V_12 * V_13 ,
const struct V_14 * V_83 ,
T_2 V_93 )
{
struct V_17 * V_84 ;
assert ( V_82 != NULL ) ;
assert ( V_93 != V_94 ) ;
assert ( V_83 != NULL ) ;
V_84 = F_14 ( V_82 ,
V_13 ,
V_83 ) ;
if ( ! V_84 ) {
F_18 ( V_95 ) ;
return V_95 ;
}
F_19 (
V_93 ,
V_84 ) ;
F_20 ( V_84 ) ;
return V_96 ;
}
