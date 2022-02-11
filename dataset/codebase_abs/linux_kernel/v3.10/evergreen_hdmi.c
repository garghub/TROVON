static void F_1 ( struct V_1 * V_2 , T_1 clock )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 = F_2 ( clock ) ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_12 -> V_15 -> V_14 ;
F_4 ( V_16 + V_14 , F_5 ( V_9 . V_17 ) ) ;
F_4 ( V_18 + V_14 , V_9 . V_19 ) ;
F_4 ( V_20 + V_14 , F_6 ( V_9 . V_21 ) ) ;
F_4 ( V_22 + V_14 , V_9 . V_23 ) ;
F_4 ( V_24 + V_14 , F_7 ( V_9 . V_25 ) ) ;
F_4 ( V_26 + V_14 , V_9 . V_27 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_4 -> V_7 ;
struct V_28 * V_29 ;
struct V_30 * V_30 = NULL ;
struct V_31 * V_32 ;
int V_33 , V_34 ;
static const T_2 V_35 [] [ 2 ] = {
{ V_36 , V_37 } ,
{ V_38 , V_39 } ,
{ V_40 , V_41 } ,
{ V_42 , V_43 } ,
{ V_44 , V_45 } ,
{ V_46 , V_47 } ,
{ V_48 , V_49 } ,
{ V_50 , V_51 } ,
{ V_52 , V_53 } ,
{ V_54 , V_55 } ,
{ V_56 , V_57 } ,
{ V_58 , V_59 } ,
} ;
F_9 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_29 -> V_2 == V_2 )
V_30 = F_10 ( V_29 ) ;
}
if ( ! V_30 ) {
F_11 ( L_1 ) ;
return;
}
V_34 = F_12 ( V_30 -> V_60 , & V_32 ) ;
if ( V_34 < 0 ) {
F_11 ( L_2 , V_34 ) ;
return;
}
F_13 ( ! V_32 ) ;
for ( V_33 = 0 ; V_33 < F_14 ( V_35 ) ; V_33 ++ ) {
T_3 V_61 = 0 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_34 ; V_62 ++ ) {
struct V_31 * V_63 = & V_32 [ V_62 ] ;
if ( V_63 -> V_64 == V_35 [ V_33 ] [ 1 ] ) {
V_61 = F_15 ( V_63 -> V_65 ) |
F_16 ( V_63 -> V_66 ) |
F_17 ( V_63 -> V_67 ) ;
if ( V_63 -> V_64 == V_37 )
V_61 |= F_18 ( V_63 -> V_67 ) ;
break;
}
}
F_4 ( V_35 [ V_33 ] [ 0 ] , V_61 ) ;
}
F_19 ( V_32 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
void * V_68 , T_4 V_69 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_12 -> V_15 -> V_14 ;
T_5 * V_70 = V_68 + 3 ;
V_70 [ 0x0 ] += 2 ;
F_4 ( V_71 + V_14 ,
V_70 [ 0x0 ] | ( V_70 [ 0x1 ] << 8 ) | ( V_70 [ 0x2 ] << 16 ) | ( V_70 [ 0x3 ] << 24 ) ) ;
F_4 ( V_72 + V_14 ,
V_70 [ 0x4 ] | ( V_70 [ 0x5 ] << 8 ) | ( V_70 [ 0x6 ] << 16 ) | ( V_70 [ 0x7 ] << 24 ) ) ;
F_4 ( V_73 + V_14 ,
V_70 [ 0x8 ] | ( V_70 [ 0x9 ] << 8 ) | ( V_70 [ 0xA ] << 16 ) | ( V_70 [ 0xB ] << 24 ) ) ;
F_4 ( V_74 + V_14 ,
V_70 [ 0xC ] | ( V_70 [ 0xD ] << 8 ) ) ;
}
static void F_21 ( struct V_1 * V_2 , T_3 clock )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_75 * V_75 = F_22 ( V_2 -> V_76 ) ;
T_3 V_77 = 24000 ;
if ( ! V_12 || ! V_12 -> V_15 )
return;
F_4 ( V_78 , V_77 * 100 ) ;
F_4 ( V_79 , clock * 100 ) ;
F_4 ( V_80 , F_23 ( V_75 -> V_81 ) ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_6 V_68 [ V_84 + V_85 ] ;
struct V_86 V_70 ;
T_1 V_14 ;
T_7 V_87 ;
if ( ! V_12 -> V_15 -> V_88 )
return;
V_14 = V_12 -> V_15 -> V_14 ;
F_21 ( V_2 , V_83 -> clock ) ;
F_4 ( V_89 + V_14 ,
V_90 ) ;
F_4 ( V_91 + V_14 , 0x1000 ) ;
F_4 ( V_89 + V_14 ,
V_90 |
V_92 |
V_93 ) ;
F_4 ( V_94 + V_14 ,
V_95 |
V_96 ) ;
F_4 ( V_97 + V_14 ,
V_98 ) ;
F_4 ( V_99 + V_14 ,
F_25 ( 2 ) ) ;
F_4 ( V_100 + V_14 , 0 ) ;
F_4 ( V_101 + V_14 ,
F_26 ( 1 ) |
F_27 ( 3 ) ) ;
F_4 ( V_102 + V_14 ,
V_103 ) ;
F_4 ( V_104 + V_14 ,
V_105 |
V_106 ) ;
F_1 ( V_2 , V_83 -> clock ) ;
F_4 ( V_107 + V_14 ,
F_28 ( 1 ) ) ;
F_4 ( V_108 + V_14 ,
F_29 ( 2 ) ) ;
F_4 ( V_109 + V_14 ,
F_30 ( 3 ) |
F_31 ( 4 ) |
F_32 ( 5 ) |
F_33 ( 6 ) |
F_34 ( 7 ) |
F_35 ( 8 ) ) ;
F_4 ( V_110 + V_14 ,
F_36 ( 0xff ) ) ;
F_8 ( V_2 ) ;
V_87 = F_37 ( & V_70 , V_83 ) ;
if ( V_87 < 0 ) {
F_11 ( L_3 , V_87 ) ;
return;
}
V_87 = F_38 ( & V_70 , V_68 , sizeof( V_68 ) ) ;
if ( V_87 < 0 ) {
F_11 ( L_4 , V_87 ) ;
return;
}
F_20 ( V_2 , V_68 , sizeof( V_68 ) ) ;
F_39 ( V_94 + V_14 ,
V_111 |
V_112 ) ;
F_40 ( V_99 + V_14 ,
F_41 ( 2 ) ,
~ V_113 ) ;
F_39 ( V_102 + V_14 ,
V_114 ) ;
F_4 ( V_115 + V_14 , 0x00FFFFFF ) ;
F_4 ( V_116 + V_14 , 0x007FFFFF ) ;
F_4 ( V_117 + V_14 , 0x00000001 ) ;
F_4 ( V_118 + V_14 , 0x00000001 ) ;
}
void F_42 ( struct V_1 * V_2 , bool V_119 )
{
struct V_10 * V_10 = F_3 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_119 && V_12 -> V_15 -> V_88 )
return;
if ( ! V_119 && ! V_12 -> V_15 -> V_88 )
return;
V_12 -> V_15 -> V_88 = V_119 ;
F_43 ( L_5 ,
V_119 ? L_6 : L_7 , V_12 -> V_15 -> V_14 , V_10 -> V_120 ) ;
}
