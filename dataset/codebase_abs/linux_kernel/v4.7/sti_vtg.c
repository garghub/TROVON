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
if ( V_2 -> V_7 )
F_5 ( V_2 -> V_7 ) ;
F_6 ( 1 , V_2 -> V_8 + V_9 ) ;
}
static void F_7 ( void T_1 * V_8 ,
const struct V_10 * V_11 )
{
T_2 V_12 ;
T_2 V_13 ;
T_2 V_14 ;
T_2 V_15 ;
T_2 V_16 = F_8 ( * V_11 , 0 ) ;
T_2 V_17 = F_9 ( * V_11 , 0 ) ;
T_2 V_18 = F_8 ( * V_11 , V_11 -> V_19 - 1 ) ;
T_2 V_20 = F_9 ( * V_11 , V_11 -> V_21 - 1 ) ;
V_12 = ( V_17 << 16 ) | V_16 ;
V_13 = ( V_20 << 16 ) | V_18 ;
V_14 = V_12 ;
V_15 = V_13 ;
F_6 ( V_12 , V_8 + V_22 ) ;
F_6 ( V_13 , V_8 + V_23 ) ;
F_6 ( V_14 , V_8 + V_24 ) ;
F_6 ( V_15 , V_8 + V_25 ) ;
}
static void F_10 ( struct V_26 * V_27 ,
int V_28 ,
const struct V_10 * V_11 )
{
long V_29 , V_30 , V_31 ;
T_2 V_32 , V_33 ;
T_2 V_34 , V_35 ;
V_29 = V_11 -> V_36 ;
V_30 = 0 ;
V_31 = V_11 -> V_37 - V_11 -> V_38 ;
V_30 += V_28 ;
V_31 += V_28 ;
if ( V_30 < 0 )
V_30 += V_29 ;
else if ( V_30 >= V_29 )
V_30 -= V_29 ;
if ( V_31 < 0 )
V_31 += V_29 ;
else if ( V_31 >= V_29 )
V_31 -= V_29 ;
V_27 -> V_39 = ( V_31 << 16 ) | V_30 ;
if ( V_28 >= 0 ) {
V_32 = 1 ;
V_33 = V_32 ;
V_33 += V_11 -> V_40 - V_11 -> V_41 ;
V_35 = ( T_2 ) V_28 ;
V_34 = ( T_2 ) V_28 ;
} else {
V_32 = V_11 -> V_42 ;
V_33 = V_11 -> V_40 - V_11 -> V_41 ;
V_35 = V_29 + V_28 ;
V_34 = V_29 + V_28 ;
}
V_27 -> V_43 = ( V_33 << 16 ) | V_32 ;
V_27 -> V_44 = ( V_35 << 16 ) | V_34 ;
V_27 -> V_45 = V_27 -> V_43 ;
V_27 -> V_46 = V_27 -> V_44 ;
}
static void F_11 ( struct V_1 * V_2 ,
int type ,
struct V_26 * V_27 ,
const struct V_10 * V_11 )
{
unsigned int V_47 ;
if ( V_2 -> V_7 )
F_11 ( V_2 -> V_7 , V_48 ,
V_2 -> V_49 , V_11 ) ;
F_6 ( V_11 -> V_36 , V_2 -> V_8 + V_50 ) ;
F_6 ( V_11 -> V_42 * 2 , V_2 -> V_8 + V_51 ) ;
F_7 ( V_2 -> V_8 , V_11 ) ;
F_10 ( & V_27 [ V_52 - 1 ] , V_53 , V_11 ) ;
F_10 ( & V_27 [ V_54 - 1 ] , 0 , V_11 ) ;
F_10 ( & V_27 [ V_55 - 1 ] , V_56 , V_11 ) ;
F_10 ( & V_27 [ V_57 - 1 ] , V_58 , V_11 ) ;
for ( V_47 = 0 ; V_47 < V_59 ; V_47 ++ ) {
F_6 ( V_27 [ V_47 ] . V_39 ,
V_2 -> V_8 + V_60 [ V_47 ] . V_61 ) ;
F_6 ( V_27 [ V_47 ] . V_43 ,
V_2 -> V_8 + V_60 [ V_47 ] . V_62 ) ;
F_6 ( V_27 [ V_47 ] . V_45 ,
V_2 -> V_8 + V_60 [ V_47 ] . V_63 ) ;
F_6 ( V_27 [ V_47 ] . V_44 ,
V_2 -> V_8 + V_60 [ V_47 ] . V_64 ) ;
F_6 ( V_27 [ V_47 ] . V_46 ,
V_2 -> V_8 + V_60 [ V_47 ] . V_65 ) ;
}
F_6 ( type , V_2 -> V_8 + V_66 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_6 ( 0xFFFF , V_2 -> V_8 + V_67 ) ;
F_6 ( 0xFFFF , V_2 -> V_8 + V_68 ) ;
F_6 ( V_69 , V_2 -> V_8 + V_70 ) ;
}
void F_13 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
F_11 ( V_2 , V_71 , V_2 -> V_49 , V_11 ) ;
F_5 ( V_2 ) ;
if ( V_2 -> V_7 )
F_12 ( V_2 -> V_7 ) ;
else
F_12 ( V_2 ) ;
}
T_2 F_9 ( struct V_10 V_11 , int V_72 )
{
T_2 V_73 = V_11 . V_42 - V_11 . V_41 + 1 ;
if ( V_11 . V_74 & V_75 )
V_73 *= 2 ;
return V_73 + V_72 ;
}
T_2 F_8 ( struct V_10 V_11 , int V_76 )
{
return V_11 . V_36 - V_11 . V_38 + V_76 ;
}
int F_14 ( struct V_1 * V_2 , struct V_77 * V_78 ,
struct V_79 * V_80 )
{
if ( V_2 -> V_7 )
return F_14 ( V_2 -> V_7 , V_78 , V_80 ) ;
V_2 -> V_80 = V_80 ;
return F_15 ( & V_2 -> V_81 , V_78 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
if ( V_2 -> V_7 )
return F_16 ( V_2 -> V_7 , V_78 ) ;
return F_17 ( & V_2 -> V_81 , V_78 ) ;
}
static T_3 F_18 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
T_2 V_84 ;
V_84 = ( V_2 -> V_85 & V_86 ) ?
V_87 : V_88 ;
F_19 ( & V_2 -> V_81 , V_84 , V_2 -> V_80 ) ;
return V_89 ;
}
static T_3 F_20 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
V_2 -> V_85 = F_21 ( V_2 -> V_8 + V_90 ) ;
F_6 ( V_2 -> V_85 , V_2 -> V_8 + V_67 ) ;
F_21 ( V_2 -> V_8 + V_90 ) ;
return V_91 ;
}
static int F_22 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = & V_93 -> V_95 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
struct V_96 * V_97 ;
int V_98 ;
V_2 = F_23 ( V_95 , sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_95 = V_95 ;
V_2 -> V_6 = V_93 -> V_95 . V_101 ;
V_97 = F_24 ( V_93 , V_102 , 0 ) ;
if ( ! V_97 ) {
F_25 ( L_1 ) ;
return - V_100 ;
}
V_2 -> V_8 = F_26 ( V_95 , V_97 -> V_30 , F_27 ( V_97 ) ) ;
V_6 = F_28 ( V_93 -> V_95 . V_101 , L_2 , 0 ) ;
if ( V_6 ) {
V_2 -> V_7 = F_3 ( V_6 ) ;
if ( ! V_2 -> V_7 )
return - V_103 ;
} else {
V_2 -> V_82 = F_29 ( V_93 , 0 ) ;
if ( V_2 -> V_82 < 0 ) {
F_25 ( L_3 ) ;
return V_2 -> V_82 ;
}
F_30 ( & V_2 -> V_81 ) ;
V_98 = F_31 ( V_95 , V_2 -> V_82 , F_20 ,
F_18 , V_104 ,
F_32 ( V_95 ) , V_2 ) ;
if ( V_98 < 0 ) {
F_25 ( L_4 ) ;
return V_98 ;
}
}
F_1 ( V_2 ) ;
F_33 ( V_93 , V_2 ) ;
F_34 ( L_5 , V_105 , F_32 ( V_2 -> V_95 ) ) ;
return 0 ;
}
static int F_35 ( struct V_92 * V_93 )
{
return 0 ;
}
