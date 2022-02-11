static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_9 = NULL ;
T_1 V_10 ;
T_2 * V_11 ;
int V_12 ;
F_2 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_8 -> V_2 == V_2 ) {
V_9 = F_3 ( V_8 ) ;
break;
}
}
if ( ! V_9 ) {
F_4 ( L_1 ) ;
return;
}
V_12 = F_5 ( V_9 -> V_13 , & V_11 ) ;
if ( V_12 < 0 ) {
F_4 ( L_2 , V_12 ) ;
return;
}
V_10 = F_6 ( V_14 ) ;
V_10 &= ~ ( V_15 | V_16 ) ;
V_10 |= V_17 ;
if ( V_12 )
V_10 |= F_7 ( V_11 [ 0 ] ) ;
else
V_10 |= F_7 ( 5 ) ;
F_8 ( V_14 , V_10 ) ;
F_9 ( V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_9 = NULL ;
struct V_18 * V_19 ;
int V_20 , V_12 ;
static const T_3 V_21 [] [ 2 ] = {
{ V_22 , V_23 } ,
{ V_24 , V_25 } ,
{ V_26 , V_27 } ,
{ V_28 , V_29 } ,
{ V_30 , V_31 } ,
{ V_32 , V_33 } ,
{ V_34 , V_35 } ,
{ V_36 , V_37 } ,
{ V_38 , V_39 } ,
{ V_40 , V_41 } ,
{ V_42 , V_43 } ,
{ V_44 , V_45 } ,
} ;
F_2 (connector, &encoder->dev->mode_config.connector_list, head) {
if ( V_8 -> V_2 == V_2 ) {
V_9 = F_3 ( V_8 ) ;
break;
}
}
if ( ! V_9 ) {
F_4 ( L_1 ) ;
return;
}
V_12 = F_11 ( V_9 -> V_13 , & V_19 ) ;
if ( V_12 < 0 ) {
F_4 ( L_3 , V_12 ) ;
return;
}
F_12 ( ! V_19 ) ;
for ( V_20 = 0 ; V_20 < F_13 ( V_21 ) ; V_20 ++ ) {
T_1 V_46 = 0 ;
T_2 V_47 = 0 ;
int V_48 = - 1 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_12 ; V_49 ++ ) {
struct V_18 * V_50 = & V_19 [ V_49 ] ;
if ( V_50 -> V_51 == V_21 [ V_20 ] [ 1 ] ) {
if ( V_50 -> V_52 > V_48 ) {
V_46 = F_14 ( V_50 -> V_52 ) |
F_15 ( V_50 -> V_53 ) |
F_16 ( V_50 -> V_54 ) ;
V_48 = V_50 -> V_52 ;
}
if ( V_50 -> V_51 == V_23 )
V_47 |= V_50 -> V_54 ;
else
break;
}
}
V_46 |= F_17 ( V_47 ) ;
F_8 ( V_21 [ V_20 ] [ 0 ] , V_46 ) ;
}
F_9 ( V_19 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_57 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_5 -> V_6 ;
struct V_58 * V_58 = F_19 ( V_2 ) ;
struct V_59 * V_60 = V_58 -> V_61 ;
T_2 V_62 [ V_63 + V_64 ] ;
struct V_65 V_66 ;
T_4 V_67 ;
T_5 V_68 ;
if ( ! V_60 || ! V_60 -> V_69 )
return;
if ( ! V_60 -> V_69 -> V_70 )
return;
V_67 = V_60 -> V_69 -> V_67 ;
V_60 -> V_69 -> V_71 = F_20 ( V_4 ) ;
F_21 ( V_4 , V_60 -> V_69 -> V_71 , false ) ;
F_22 ( V_2 , V_56 -> clock ) ;
F_8 ( V_72 + V_67 ,
V_73 ) ;
F_8 ( V_74 + V_67 , 0x1000 ) ;
if ( F_23 ( V_4 ) ) {
F_8 ( V_75 + V_67 ,
F_24 ( 1 ) |
F_25 ( 3 ) ) ;
F_8 ( V_76 + V_67 ,
V_77 |
V_78 ) ;
} else {
F_8 ( V_75 + V_67 ,
V_79 |
F_24 ( 1 ) |
F_25 ( 3 ) |
V_80 ) ;
}
if ( F_23 ( V_4 ) ) {
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
}
F_8 ( V_81 + V_67 ,
V_82 |
V_83 ) ;
F_8 ( V_72 + V_67 ,
V_73 |
V_84 |
V_85 ) ;
F_8 ( V_86 + V_67 ,
V_87 |
V_88 |
V_89 |
V_90 ) ;
F_8 ( V_91 + V_67 ,
F_26 ( 2 ) |
F_27 ( 2 ) ) ;
F_8 ( V_92 + V_67 , 0 ) ;
V_68 = F_28 ( & V_66 , V_56 ) ;
if ( V_68 < 0 ) {
F_4 ( L_4 , V_68 ) ;
return;
}
V_68 = F_29 ( & V_66 , V_62 , sizeof( V_62 ) ) ;
if ( V_68 < 0 ) {
F_4 ( L_5 , V_68 ) ;
return;
}
F_30 ( V_2 , V_62 , sizeof( V_62 ) ) ;
F_31 ( V_2 , V_56 -> clock ) ;
F_8 ( V_93 + V_67 , 0x00FFFFFF ) ;
F_8 ( V_94 + V_67 , 0x007FFFFF ) ;
F_8 ( V_95 + V_67 , 0x00000001 ) ;
F_8 ( V_96 + V_67 , 0x00000001 ) ;
F_32 ( V_2 ) ;
F_21 ( V_4 , V_60 -> V_69 -> V_71 , true ) ;
}
