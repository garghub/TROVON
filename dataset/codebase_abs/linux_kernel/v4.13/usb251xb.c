static void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_2 -> V_4 ) )
return;
F_3 ( V_2 -> V_4 , V_3 ) ;
if ( V_3 )
F_4 ( 500 , 750 ) ;
else
F_4 ( 1 , 10 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 , V_8 ;
char V_9 [ V_10 ] ;
memset ( V_9 , 0 , V_10 ) ;
if ( V_2 -> V_11 ) {
F_6 ( V_6 , L_1 ) ;
V_9 [ 0 ] = 0x01 ;
V_9 [ 1 ] = V_12 ;
F_1 ( V_2 , 1 ) ;
V_7 = F_7 ( V_2 -> V_13 ,
V_14 , 2 , V_9 ) ;
if ( V_7 ) {
F_8 ( V_6 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
V_9 [ V_15 ] = ( V_2 -> V_16 >> 8 ) & 0xFF ;
V_9 [ V_17 ] = V_2 -> V_16 & 0xFF ;
V_9 [ V_18 ] = ( V_2 -> V_19 >> 8 ) & 0xFF ;
V_9 [ V_20 ] = V_2 -> V_19 & 0xFF ;
V_9 [ V_21 ] = ( V_2 -> V_22 >> 8 ) & 0xFF ;
V_9 [ V_23 ] = V_2 -> V_22 & 0xFF ;
V_9 [ V_24 ] = V_2 -> V_25 ;
V_9 [ V_26 ] = V_2 -> V_27 ;
V_9 [ V_28 ] = V_2 -> V_29 ;
V_9 [ V_30 ] = V_2 -> V_31 ;
V_9 [ V_32 ] = V_2 -> V_33 ;
V_9 [ V_34 ] = V_2 -> V_35 ;
V_9 [ V_36 ] = V_2 -> V_37 ;
V_9 [ V_38 ] = V_2 -> V_39 ;
V_9 [ V_40 ] = V_2 -> V_41 ;
V_9 [ V_42 ] = V_2 -> V_43 ;
V_9 [ V_44 ] = V_2 -> V_45 ;
V_9 [ V_46 ] = ( V_2 -> V_47 >> 8 ) & 0xFF ;
V_9 [ V_48 ] = V_2 -> V_47 & 0xFF ;
V_9 [ V_49 ] = V_2 -> V_50 ;
V_9 [ V_51 ] = V_2 -> V_52 ;
V_9 [ V_53 ] = V_2 -> V_54 ;
memcpy ( & V_9 [ V_55 ] , V_2 -> V_56 ,
V_57 ) ;
memcpy ( & V_9 [ V_58 ] , V_2 -> V_59 ,
V_57 ) ;
memcpy ( & V_9 [ V_60 ] , V_2 -> V_61 ,
V_57 ) ;
V_9 [ V_62 ] = V_2 -> V_63 ;
V_9 [ V_64 ] = V_2 -> V_65 ;
V_9 [ V_66 ] = V_2 -> V_67 ;
V_9 [ V_68 ] = V_2 -> V_69 ;
V_9 [ V_70 ] = V_2 -> V_71 ;
V_9 [ V_72 ] = V_2 -> V_73 ;
V_9 [ V_14 ] = V_12 ;
F_1 ( V_2 , 1 ) ;
for ( V_8 = 0 ; V_8 < ( V_10 / V_74 ) ; V_8 ++ ) {
int V_75 = V_8 * V_74 ;
char V_76 [ V_74 + 1 ] ;
V_76 [ 0 ] = V_74 ;
memcpy ( & V_76 [ 1 ] , & V_9 [ V_75 ] , V_74 ) ;
F_9 ( V_6 , L_3 ,
V_74 , V_8 , V_75 ) ;
V_7 = F_7 ( V_2 -> V_13 , V_75 ,
V_74 + 1 ,
V_76 ) ;
if ( V_7 )
goto V_77;
}
F_6 ( V_6 , L_4 ) ;
return 0 ;
V_77:
F_8 ( V_6 , L_5 , V_8 , V_7 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_80 * V_81 = V_6 -> V_82 ;
int V_83 , V_7 , V_8 ;
T_1 * V_84 = NULL ;
const T_1 * V_85 ;
const char * V_86 ;
char V_87 [ V_57 / 2 ] ;
if ( ! V_81 ) {
F_8 ( V_6 , L_6 ) ;
return - V_88 ;
}
if ( F_11 ( V_81 , L_7 , NULL ) )
V_2 -> V_11 = 1 ;
else
V_2 -> V_11 = 0 ;
V_2 -> V_4 = F_12 ( V_81 , L_8 , 0 ) ;
if ( V_2 -> V_4 == - V_89 )
return - V_89 ;
if ( F_2 ( V_2 -> V_4 ) ) {
V_7 = F_13 ( V_6 , V_2 -> V_4 ,
V_90 ,
L_9 ) ;
if ( V_7 ) {
F_8 ( V_6 ,
L_10 ,
V_2 -> V_4 , V_7 ) ;
return V_7 ;
}
}
if ( F_14 ( V_81 , L_11 , & V_2 -> V_16 , 1 ) )
V_2 -> V_16 = V_91 ;
if ( F_14 ( V_81 , L_12 ,
& V_2 -> V_19 , 1 ) )
V_2 -> V_19 = V_79 -> V_19 ;
if ( F_14 ( V_81 , L_13 , & V_2 -> V_22 , 1 ) )
V_2 -> V_22 = V_92 ;
V_2 -> V_25 = V_93 ;
if ( F_11 ( V_81 , L_14 , NULL ) ) {
V_2 -> V_25 |= F_15 ( 7 ) ;
V_2 -> V_25 &= ~ F_15 ( 2 ) ;
if ( F_11 ( V_81 , L_15 , NULL ) )
V_2 -> V_25 &= ~ F_15 ( 1 ) ;
else if ( F_11 ( V_81 , L_16 , NULL ) )
V_2 -> V_25 |= F_15 ( 1 ) ;
} else if ( F_11 ( V_81 , L_17 , NULL ) ) {
V_2 -> V_25 &= ~ F_15 ( 7 ) ;
V_2 -> V_25 |= F_15 ( 2 ) ;
}
if ( F_11 ( V_81 , L_18 , NULL ) )
V_2 -> V_25 |= F_15 ( 5 ) ;
if ( F_11 ( V_81 , L_19 , NULL ) )
V_2 -> V_25 |= F_15 ( 4 ) ;
else if ( F_11 ( V_81 , L_20 , NULL ) )
V_2 -> V_25 &= ~ F_15 ( 4 ) ;
if ( F_11 ( V_81 , L_21 , NULL ) )
V_2 -> V_25 |= F_15 ( 3 ) ;
if ( F_11 ( V_81 , L_22 , NULL ) )
V_2 -> V_25 |= F_15 ( 0 ) ;
else if ( F_11 ( V_81 , L_23 , NULL ) )
V_2 -> V_25 &= ~ F_15 ( 0 ) ;
V_2 -> V_27 = V_94 ;
if ( F_11 ( V_81 , L_24 , NULL ) )
V_2 -> V_27 |= F_15 ( 7 ) ;
if ( ! F_16 ( V_81 , L_25 , V_84 ) ) {
if ( * V_84 == 100 ) {
V_2 -> V_27 &= ~ F_15 ( 5 ) ;
V_2 -> V_27 &= ~ F_15 ( 4 ) ;
} else if ( * V_84 == 4000 ) {
V_2 -> V_27 &= ~ F_15 ( 5 ) ;
V_2 -> V_27 |= F_15 ( 4 ) ;
} else if ( * V_84 == 16000 ) {
V_2 -> V_27 |= F_15 ( 5 ) ;
V_2 -> V_27 |= F_15 ( 4 ) ;
} else {
V_2 -> V_27 |= F_15 ( 5 ) ;
V_2 -> V_27 &= ~ F_15 ( 4 ) ;
}
}
if ( F_11 ( V_81 , L_26 , NULL ) )
V_2 -> V_27 |= F_15 ( 3 ) ;
V_2 -> V_29 = V_95 ;
if ( F_11 ( V_81 , L_27 , NULL ) )
V_2 -> V_29 |= F_15 ( 3 ) ;
if ( F_11 ( V_81 , L_28 , NULL ) )
V_2 -> V_29 |= F_15 ( 0 ) ;
V_2 -> V_31 = V_96 ;
V_85 = F_11 ( V_81 , L_29 , & V_83 ) ;
if ( V_85 && ( V_83 / sizeof( T_1 ) ) > 0 ) {
for ( V_8 = 0 ; V_8 < V_83 / sizeof( T_1 ) ; V_8 ++ ) {
T_1 V_97 = F_17 ( V_85 [ V_8 ] ) ;
if ( ( V_97 >= 1 ) && ( V_97 <= 4 ) )
V_2 -> V_31 |= F_15 ( V_97 ) ;
}
}
V_2 -> V_33 = V_98 ;
V_85 = F_11 ( V_81 , L_30 , & V_83 ) ;
if ( V_85 && ( V_83 / sizeof( T_1 ) ) > 0 ) {
for ( V_8 = 0 ; V_8 < V_83 / sizeof( T_1 ) ; V_8 ++ ) {
T_1 V_97 = F_17 ( V_85 [ V_8 ] ) ;
if ( ( V_97 >= 1 ) && ( V_97 <= 4 ) )
V_2 -> V_33 |= F_15 ( V_97 ) ;
}
}
V_2 -> V_35 = V_99 ;
V_85 = F_11 ( V_81 , L_31 , & V_83 ) ;
if ( V_85 && ( V_83 / sizeof( T_1 ) ) > 0 ) {
for ( V_8 = 0 ; V_8 < V_83 / sizeof( T_1 ) ; V_8 ++ ) {
T_1 V_97 = F_17 ( V_85 [ V_8 ] ) ;
if ( ( V_97 >= 1 ) && ( V_97 <= 4 ) )
V_2 -> V_35 |= F_15 ( V_97 ) ;
}
}
V_2 -> V_45 = V_100 ;
if ( ! F_16 ( V_81 , L_32 , V_84 ) )
V_2 -> V_45 = F_18 ( V_101 , * V_84 / 2 , 255 ) ;
if ( F_14 ( V_81 , L_33 , & V_2 -> V_47 , 1 ) )
V_2 -> V_47 = V_102 ;
V_86 = F_11 ( V_81 , L_34 , NULL ) ;
F_19 ( V_87 , V_86 ? : V_103 ,
sizeof( V_87 ) ) ;
V_2 -> V_50 = strlen ( V_87 ) & 0xFF ;
memset ( V_2 -> V_56 , 0 , V_57 ) ;
V_83 = F_18 ( V_104 , V_57 / 2 , strlen ( V_87 ) ) ;
V_83 = F_20 ( V_87 , V_83 , V_105 ,
( V_106 * ) V_2 -> V_56 ,
V_57 ) ;
V_86 = F_11 ( V_81 , L_35 , NULL ) ;
F_19 ( V_87 , V_86 ? : V_79 -> V_107 , sizeof( V_87 ) ) ;
V_2 -> V_52 = strlen ( V_87 ) & 0xFF ;
memset ( V_2 -> V_61 , 0 , V_57 ) ;
V_83 = F_18 ( V_104 , V_57 / 2 , strlen ( V_87 ) ) ;
V_83 = F_20 ( V_87 , V_83 , V_105 ,
( V_106 * ) V_2 -> V_61 ,
V_57 ) ;
V_86 = F_11 ( V_81 , L_36 , NULL ) ;
F_19 ( V_87 , V_86 ? : V_108 ,
sizeof( V_87 ) ) ;
V_2 -> V_54 = strlen ( V_87 ) & 0xFF ;
memset ( V_2 -> V_59 , 0 , V_57 ) ;
V_83 = F_18 ( V_104 , V_57 / 2 , strlen ( V_87 ) ) ;
V_83 = F_20 ( V_87 , V_83 , V_105 ,
( V_106 * ) V_2 -> V_59 ,
V_57 ) ;
V_2 -> V_37 = V_109 ;
V_2 -> V_39 = V_110 ;
V_2 -> V_41 = V_111 ;
V_2 -> V_43 = V_112 ;
V_2 -> V_63 = V_113 ;
V_2 -> V_65 = V_114 ;
V_2 -> V_67 = V_115 ;
V_2 -> V_69 = V_116 ;
V_2 -> V_71 = V_117 ;
V_2 -> V_73 = V_118 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_80 * V_81 = V_6 -> V_82 ;
const struct V_119 * V_120 = F_22 ( V_121 ,
V_6 ) ;
int V_7 ;
if ( V_81 ) {
V_7 = F_10 ( V_2 ,
(struct V_78 * ) V_120 -> V_79 ) ;
if ( V_7 ) {
F_8 ( V_6 , L_37 , V_7 ) ;
return V_7 ;
}
}
V_7 = F_5 ( V_2 ) ;
if ( V_7 ) {
F_8 ( V_6 , L_38 , V_7 ) ;
return V_7 ;
}
F_6 ( V_6 , L_39 ) ;
return 0 ;
}
static int F_23 ( struct V_122 * V_13 ,
const struct V_123 * V_124 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( & V_13 -> V_6 , sizeof( struct V_1 ) , V_125 ) ;
if ( ! V_2 )
return - V_126 ;
F_25 ( V_13 , V_2 ) ;
V_2 -> V_6 = & V_13 -> V_6 ;
V_2 -> V_13 = V_13 ;
return F_21 ( V_2 ) ;
}
