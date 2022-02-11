static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , & V_4 ) ;
}
struct V_1 * F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_4 (vtg, &vtg_lookup, link) {
if ( V_2 -> V_6 == V_6 )
return V_2 ;
}
return NULL ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( 1 , V_2 -> V_7 + V_8 ) ;
}
static void F_7 ( void T_1 * V_7 ,
const struct V_9 * V_10 )
{
T_2 V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 = F_8 ( * V_10 , 0 ) ;
T_2 V_16 = F_9 ( * V_10 , 0 ) ;
T_2 V_17 = F_8 ( * V_10 , V_10 -> V_18 - 1 ) ;
T_2 V_19 = F_9 ( * V_10 , V_10 -> V_20 - 1 ) ;
V_11 = ( V_16 << 16 ) | V_15 ;
V_12 = ( V_19 << 16 ) | V_17 ;
V_13 = V_11 ;
V_14 = V_12 ;
F_6 ( V_11 , V_7 + V_21 ) ;
F_6 ( V_12 , V_7 + V_22 ) ;
F_6 ( V_13 , V_7 + V_23 ) ;
F_6 ( V_14 , V_7 + V_24 ) ;
}
static void F_10 ( struct V_25 * V_26 ,
int V_27 ,
const struct V_9 * V_10 )
{
long V_28 , V_29 , V_30 ;
T_2 V_31 , V_32 ;
T_2 V_33 , V_34 ;
V_28 = V_10 -> V_35 ;
V_29 = 0 ;
V_30 = V_10 -> V_36 - V_10 -> V_37 ;
V_29 += V_27 ;
V_30 += V_27 ;
if ( V_29 < 0 )
V_29 += V_28 ;
else if ( V_29 >= V_28 )
V_29 -= V_28 ;
if ( V_30 < 0 )
V_30 += V_28 ;
else if ( V_30 >= V_28 )
V_30 -= V_28 ;
V_26 -> V_38 = ( V_30 << 16 ) | V_29 ;
if ( V_27 >= 0 ) {
V_31 = 1 ;
V_32 = V_31 ;
V_32 += V_10 -> V_39 - V_10 -> V_40 ;
V_34 = ( T_2 ) V_27 ;
V_33 = ( T_2 ) V_27 ;
} else {
V_31 = V_10 -> V_41 ;
V_32 = V_10 -> V_39 - V_10 -> V_40 ;
V_34 = V_28 + V_27 ;
V_33 = V_28 + V_27 ;
}
V_26 -> V_42 = ( V_32 << 16 ) | V_31 ;
V_26 -> V_43 = ( V_34 << 16 ) | V_33 ;
V_26 -> V_44 = V_26 -> V_42 ;
V_26 -> V_45 = V_26 -> V_43 ;
}
static void F_11 ( struct V_1 * V_2 ,
int type ,
struct V_25 * V_26 ,
const struct V_9 * V_10 )
{
unsigned int V_46 ;
F_6 ( V_10 -> V_35 , V_2 -> V_7 + V_47 ) ;
F_6 ( V_10 -> V_41 * 2 , V_2 -> V_7 + V_48 ) ;
F_7 ( V_2 -> V_7 , V_10 ) ;
F_10 ( & V_26 [ V_49 - 1 ] , V_50 , V_10 ) ;
F_10 ( & V_26 [ V_51 - 1 ] , 0 , V_10 ) ;
F_10 ( & V_26 [ V_52 - 1 ] , V_53 , V_10 ) ;
F_10 ( & V_26 [ V_54 - 1 ] , V_55 , V_10 ) ;
for ( V_46 = 0 ; V_46 < V_56 ; V_46 ++ ) {
F_6 ( V_26 [ V_46 ] . V_38 ,
V_2 -> V_7 + V_57 [ V_46 ] . V_58 ) ;
F_6 ( V_26 [ V_46 ] . V_42 ,
V_2 -> V_7 + V_57 [ V_46 ] . V_59 ) ;
F_6 ( V_26 [ V_46 ] . V_44 ,
V_2 -> V_7 + V_57 [ V_46 ] . V_60 ) ;
F_6 ( V_26 [ V_46 ] . V_43 ,
V_2 -> V_7 + V_57 [ V_46 ] . V_61 ) ;
F_6 ( V_26 [ V_46 ] . V_45 ,
V_2 -> V_7 + V_57 [ V_46 ] . V_62 ) ;
}
F_6 ( type , V_2 -> V_7 + V_63 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_6 ( 0xFFFF , V_2 -> V_7 + V_64 ) ;
F_6 ( 0xFFFF , V_2 -> V_7 + V_65 ) ;
F_6 ( V_66 , V_2 -> V_7 + V_67 ) ;
}
void F_13 ( struct V_1 * V_2 ,
const struct V_9 * V_10 )
{
F_11 ( V_2 , V_68 , V_2 -> V_69 , V_10 ) ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
}
T_2 F_9 ( struct V_9 V_10 , int V_70 )
{
T_2 V_71 = V_10 . V_41 - V_10 . V_40 + 1 ;
if ( V_10 . V_72 & V_73 )
V_71 *= 2 ;
return V_71 + V_70 ;
}
T_2 F_8 ( struct V_9 V_10 , int V_74 )
{
return V_10 . V_35 - V_10 . V_37 + V_74 ;
}
int F_14 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_77 * V_78 )
{
V_2 -> V_78 = V_78 ;
return F_15 ( & V_2 -> V_79 , V_76 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
return F_17 ( & V_2 -> V_79 , V_76 ) ;
}
static T_3 F_18 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
T_2 V_82 ;
V_82 = ( V_2 -> V_83 & V_84 ) ?
V_85 : V_86 ;
F_19 ( & V_2 -> V_79 , V_82 , V_2 -> V_78 ) ;
return V_87 ;
}
static T_3 F_20 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
V_2 -> V_83 = F_21 ( V_2 -> V_7 + V_88 ) ;
F_6 ( V_2 -> V_83 , V_2 -> V_7 + V_64 ) ;
F_21 ( V_2 -> V_7 + V_88 ) ;
return V_89 ;
}
static int F_22 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = & V_91 -> V_93 ;
struct V_1 * V_2 ;
struct V_94 * V_95 ;
int V_96 ;
V_2 = F_23 ( V_93 , sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return - V_98 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_6 = V_91 -> V_93 . V_99 ;
V_95 = F_24 ( V_91 , V_100 , 0 ) ;
if ( ! V_95 ) {
F_25 ( L_1 ) ;
return - V_98 ;
}
V_2 -> V_7 = F_26 ( V_93 , V_95 -> V_29 , F_27 ( V_95 ) ) ;
if ( ! V_2 -> V_7 ) {
F_25 ( L_2 ) ;
return - V_98 ;
}
V_2 -> V_80 = F_28 ( V_91 , 0 ) ;
if ( V_2 -> V_80 < 0 ) {
F_25 ( L_3 ) ;
return V_2 -> V_80 ;
}
F_29 ( & V_2 -> V_79 ) ;
V_96 = F_30 ( V_93 , V_2 -> V_80 , F_20 ,
F_18 , V_101 ,
F_31 ( V_93 ) , V_2 ) ;
if ( V_96 < 0 ) {
F_25 ( L_4 ) ;
return V_96 ;
}
F_1 ( V_2 ) ;
F_32 ( V_91 , V_2 ) ;
F_33 ( L_5 , V_102 , F_31 ( V_2 -> V_93 ) ) ;
return 0 ;
}
static int F_34 ( struct V_90 * V_91 )
{
return 0 ;
}
