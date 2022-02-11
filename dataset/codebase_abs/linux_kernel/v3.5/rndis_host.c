void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_2 ( V_2 -> V_4 , L_1 ,
V_3 -> V_5 , V_3 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_7 * V_8 ,
int V_9 )
{
struct V_10 * V_11 = ( void * ) & V_2 -> V_12 ;
struct V_13 * V_14 = & V_11 -> V_15 -> V_2 ;
if ( V_2 -> V_16 -> V_17 ) {
V_2 -> V_16 -> V_17 ( V_2 , V_8 , V_9 ) ;
} else {
T_1 V_6 = F_4 ( V_8 -> V_6 ) ;
switch ( V_6 ) {
case V_18 :
F_5 ( V_14 , L_2 ) ;
break;
case V_19 :
F_5 ( V_14 , L_3 ) ;
break;
default:
F_5 ( V_14 , L_4 , V_6 ) ;
}
}
}
int F_6 ( struct V_1 * V_2 , struct V_20 * V_21 , int V_9 )
{
struct V_10 * V_11 = ( void * ) & V_2 -> V_12 ;
struct V_22 V_23 ;
int V_24 ;
int V_25 ;
int V_26 ;
unsigned V_27 ;
T_1 V_28 = 0 , V_29 , V_30 , V_31 , V_32 ,
V_6 ;
V_31 = F_4 ( V_21 -> V_31 ) ;
if ( F_7 ( V_31 != V_33 && V_31 != V_34 ) ) {
V_28 = V_2 -> V_28 ++ ;
if ( ! V_28 )
V_28 = V_2 -> V_28 ++ ;
V_21 -> V_30 = ( V_35 V_36 ) V_28 ;
}
V_24 = V_11 -> V_15 -> V_37 -> V_38 . V_39 ;
V_25 = F_8 ( V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
V_40 ,
V_41 | V_42 ,
0 , V_24 ,
V_21 , F_4 ( V_21 -> V_29 ) ,
V_43 ) ;
if ( F_10 ( V_25 < 0 || V_28 == 0 ) )
return V_25 ;
if ( V_2 -> V_16 -> V_12 & V_44 ) {
V_25 = F_11 (
V_2 -> V_14 ,
F_12 ( V_2 -> V_14 ,
V_2 -> V_6 -> V_38 . V_45 ) ,
& V_23 , sizeof( V_23 ) , & V_26 ,
V_43 ) ;
if ( F_10 ( V_25 < 0 ) )
return V_25 ;
}
V_32 = F_4 ( V_21 -> V_31 ) | V_46 ;
for ( V_27 = 0 ; V_27 < 10 ; V_27 ++ ) {
memset ( V_21 , 0 , V_47 ) ;
V_25 = F_8 ( V_2 -> V_14 ,
F_13 ( V_2 -> V_14 , 0 ) ,
V_48 ,
V_49 | V_41 | V_42 ,
0 , V_24 ,
V_21 , V_9 ,
V_43 ) ;
if ( F_7 ( V_25 >= 8 ) ) {
V_31 = F_4 ( V_21 -> V_31 ) ;
V_29 = F_4 ( V_21 -> V_29 ) ;
V_6 = F_4 ( V_21 -> V_6 ) ;
V_30 = ( V_35 T_1 ) V_21 -> V_30 ;
if ( F_7 ( V_31 == V_32 ) ) {
if ( F_7 ( V_30 == V_28 ) ) {
if ( F_10 ( V_32 == V_50 ) )
return 0 ;
if ( F_7 ( V_51 ==
V_6 ) )
return 0 ;
F_14 ( & V_11 -> V_15 -> V_2 ,
L_5 ,
V_6 ) ;
return - V_52 ;
}
F_14 ( & V_11 -> V_15 -> V_2 ,
L_6 ,
V_30 , V_28 ) ;
} else switch ( V_31 ) {
case V_53 :
F_3 ( V_2 , ( void * ) V_21 , V_9 ) ;
break;
case V_54 : {
struct V_55 * V_8 = ( void * ) V_21 ;
V_8 -> V_31 = F_15 ( V_56 ) ;
V_8 -> V_29 = F_15 ( sizeof *V_8 ) ;
V_8 -> V_6 = F_15 ( V_51 ) ;
V_25 = F_8 ( V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
V_40 ,
V_41 | V_42 ,
0 , V_24 ,
V_8 , sizeof *V_8 ,
V_43 ) ;
if ( F_10 ( V_25 < 0 ) )
F_14 ( & V_11 -> V_15 -> V_2 ,
L_7 ,
V_25 ) ;
}
break;
default:
F_14 ( & V_11 -> V_15 -> V_2 ,
L_8 ,
F_4 ( V_21 -> V_31 ) , V_29 ) ;
}
} else {
F_14 ( & V_11 -> V_15 -> V_2 ,
L_9 , V_25 ) ;
}
F_16 ( 20 ) ;
}
F_14 ( & V_11 -> V_15 -> V_2 , L_10 ) ;
return - V_57 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_58 * V_59 ,
void * V_21 , T_1 V_60 , T_1 V_61 ,
void * * V_62 , int * V_63 )
{
int V_25 ;
union {
void * V_21 ;
struct V_20 * V_64 ;
struct F_17 * V_65 ;
struct V_66 * V_67 ;
} V_68 ;
T_1 V_69 , V_70 ;
V_68 . V_21 = V_21 ;
memset ( V_68 . V_65 , 0 , sizeof * V_68 . V_65 + V_61 ) ;
V_68 . V_65 -> V_31 = F_15 ( V_71 ) ;
V_68 . V_65 -> V_29 = F_15 ( sizeof * V_68 . V_65 + V_61 ) ;
V_68 . V_65 -> V_60 = F_15 ( V_60 ) ;
V_68 . V_65 -> V_70 = F_15 ( V_61 ) ;
V_68 . V_65 -> V_72 = F_15 ( 20 ) ;
V_25 = F_6 ( V_2 , V_68 . V_64 , V_47 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_59 -> V_2 , L_11 ,
V_60 , V_25 ) ;
return V_25 ;
}
V_69 = F_4 ( V_68 . V_67 -> V_72 ) ;
V_70 = F_4 ( V_68 . V_67 -> V_70 ) ;
if ( F_10 ( ( 8 + V_69 + V_70 ) > V_47 ) )
goto V_73;
if ( * V_63 != - 1 && V_70 != * V_63 )
goto V_73;
* V_62 = ( unsigned char * ) & V_68 . V_67 -> V_30 + V_69 ;
* V_63 = V_70 ;
return V_25 ;
V_73:
F_18 ( & V_59 -> V_2 , L_12
L_13 ,
V_60 , V_69 , V_70 ) ;
return - V_74 ;
}
int
F_19 ( struct V_1 * V_2 , struct V_58 * V_59 , int V_75 )
{
int V_25 ;
struct V_76 * V_4 = V_2 -> V_4 ;
struct V_10 * V_11 = ( void * ) & V_2 -> V_12 ;
union {
void * V_21 ;
struct V_20 * V_64 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct F_17 * V_65 ;
struct V_66 * V_67 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
} V_68 ;
T_1 V_87 ;
V_36 V_88 , * V_89 ;
int V_63 ;
unsigned char * V_90 ;
V_68 . V_21 = F_20 ( V_47 , V_91 ) ;
if ( ! V_68 . V_21 )
return - V_92 ;
V_25 = F_21 ( V_2 , V_59 ) ;
if ( V_25 < 0 )
goto V_93;
V_68 . V_78 -> V_31 = F_15 ( V_94 ) ;
V_68 . V_78 -> V_29 = F_15 ( sizeof * V_68 . V_78 ) ;
V_68 . V_78 -> V_95 = F_15 ( 1 ) ;
V_68 . V_78 -> V_96 = F_15 ( 0 ) ;
V_4 -> V_97 += sizeof ( struct V_98 ) ;
V_2 -> V_99 = V_4 -> V_100 + V_4 -> V_97 ;
V_2 -> V_101 = F_22 ( V_2 -> V_14 , V_2 -> V_102 , 1 ) ;
if ( V_2 -> V_101 == 0 ) {
F_23 ( V_2 , V_103 , V_2 -> V_4 ,
L_14 ) ;
V_25 = - V_104 ;
goto V_105;
}
V_2 -> V_106 = V_2 -> V_99 + ( V_2 -> V_101 + 1 ) ;
V_2 -> V_106 &= ~ ( V_2 -> V_101 - 1 ) ;
V_68 . V_78 -> V_107 = F_15 ( V_2 -> V_106 ) ;
V_4 -> V_108 = & V_109 ;
V_25 = F_6 ( V_2 , V_68 . V_64 , V_47 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_59 -> V_2 , L_15 , V_25 ) ;
goto V_105;
}
V_87 = F_4 ( V_68 . V_80 -> V_107 ) ;
if ( V_87 < V_2 -> V_99 ) {
if ( V_87 <= V_4 -> V_97 ) {
F_18 ( & V_59 -> V_2 ,
L_16 ,
V_2 -> V_99 , V_87 ) ;
V_25 = - V_104 ;
goto V_110;
}
F_24 ( & V_59 -> V_2 ,
L_17
L_18 ,
V_2 -> V_99 , V_87 , V_87 - V_4 -> V_97 ) ;
V_2 -> V_99 = V_87 ;
V_4 -> V_100 = V_2 -> V_99 - V_4 -> V_97 ;
}
F_14 ( & V_59 -> V_2 ,
L_19 ,
V_2 -> V_99 , V_87 , V_2 -> V_106 ,
1 << F_4 ( V_68 . V_80 -> V_111 ) ) ;
if ( V_2 -> V_16 -> V_112 &&
V_2 -> V_16 -> V_112 ( V_2 ) != 0 )
goto V_110;
V_89 = NULL ;
V_63 = sizeof *V_89 ;
V_25 = F_17 ( V_2 , V_59 , V_68 . V_21 ,
V_113 ,
0 , ( void * * ) & V_89 , & V_63 ) ;
if ( V_25 != 0 || ! V_89 ) {
V_88 = F_15 ( V_114 ) ;
V_89 = & V_88 ;
}
if ( ( V_75 & V_115 ) &&
F_25 ( V_89 ) != V_116 ) {
F_23 ( V_2 , V_103 , V_2 -> V_4 ,
L_20 ) ;
V_25 = - V_117 ;
goto V_110;
}
if ( ( V_75 & V_118 ) &&
F_25 ( V_89 ) == V_116 ) {
F_23 ( V_2 , V_103 , V_2 -> V_4 ,
L_21 ) ;
V_25 = - V_117 ;
goto V_110;
}
V_63 = V_119 ;
V_25 = F_17 ( V_2 , V_59 , V_68 . V_21 ,
V_120 ,
48 , ( void * * ) & V_90 , & V_63 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_59 -> V_2 , L_22 , V_25 ) ;
goto V_110;
}
memcpy ( V_4 -> V_121 , V_90 , V_119 ) ;
memcpy ( V_4 -> V_122 , V_90 , V_119 ) ;
memset ( V_68 . V_82 , 0 , sizeof * V_68 . V_82 ) ;
V_68 . V_82 -> V_31 = F_15 ( V_123 ) ;
V_68 . V_82 -> V_29 = F_15 ( 4 + sizeof * V_68 . V_82 ) ;
V_68 . V_82 -> V_60 = F_15 ( V_124 ) ;
V_68 . V_82 -> V_70 = F_15 ( 4 ) ;
V_68 . V_82 -> V_72 = F_15 ( ( sizeof * V_68 . V_82 ) - 8 ) ;
* ( V_36 * ) ( V_68 . V_21 + sizeof * V_68 . V_82 ) = F_15 ( V_125 ) ;
V_25 = F_6 ( V_2 , V_68 . V_64 , V_47 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_59 -> V_2 , L_23 , V_25 ) ;
goto V_110;
}
V_25 = 0 ;
F_26 ( V_68 . V_21 ) ;
return V_25 ;
V_110:
memset ( V_68 . V_86 , 0 , sizeof * V_68 . V_86 ) ;
V_68 . V_86 -> V_31 = F_15 ( V_33 ) ;
V_68 . V_86 -> V_29 = F_15 ( sizeof * V_68 . V_86 ) ;
( void ) F_6 ( V_2 , ( void * ) V_68 . V_86 , V_47 ) ;
V_105:
F_27 ( V_11 -> V_12 , NULL ) ;
F_28 ( F_29 ( V_59 ) , V_11 -> V_12 ) ;
V_11 -> V_12 = NULL ;
V_93:
F_26 ( V_68 . V_21 ) ;
return V_25 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
return F_19 ( V_2 , V_59 , V_118 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_85 * V_86 ;
V_86 = F_32 ( V_47 , V_91 ) ;
if ( V_86 ) {
V_86 -> V_31 = F_15 ( V_33 ) ;
V_86 -> V_29 = F_15 ( sizeof *V_86 ) ;
( void ) F_6 ( V_2 , ( void * ) V_86 , V_47 ) ;
F_26 ( V_86 ) ;
}
F_33 ( V_2 , V_59 ) ;
}
int F_34 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
while ( F_7 ( V_127 -> V_70 ) ) {
struct V_98 * V_128 = ( void * ) V_127 -> V_12 ;
struct V_126 * V_129 ;
T_1 V_31 , V_29 , V_130 , V_131 ;
V_31 = F_4 ( V_128 -> V_31 ) ;
V_29 = F_4 ( V_128 -> V_29 ) ;
V_130 = F_4 ( V_128 -> V_130 ) ;
V_131 = F_4 ( V_128 -> V_131 ) ;
if ( F_10 ( V_31 != V_132 || V_127 -> V_70 < V_29
|| ( V_130 + V_131 + 8 ) > V_29 ) ) {
V_2 -> V_4 -> V_133 . V_134 ++ ;
F_2 ( V_2 -> V_4 , L_24 ,
F_4 ( V_128 -> V_31 ) ,
V_29 , V_130 , V_131 , V_127 -> V_70 ) ;
return 0 ;
}
F_35 ( V_127 , 8 + V_130 ) ;
if ( F_7 ( ( V_131 - V_127 -> V_70 ) <= sizeof *V_128 ) ) {
F_36 ( V_127 , V_131 ) ;
break;
}
V_129 = F_37 ( V_127 , V_135 ) ;
if ( F_10 ( ! V_129 ) )
break;
F_35 ( V_127 , V_29 - sizeof *V_128 ) ;
F_36 ( V_129 , V_131 ) ;
F_38 ( V_2 , V_129 ) ;
}
return 1 ;
}
struct V_126 *
F_39 ( struct V_1 * V_2 , struct V_126 * V_127 , T_2 V_75 )
{
struct V_98 * V_128 ;
struct V_126 * V_129 ;
unsigned V_70 = V_127 -> V_70 ;
if ( F_7 ( ! F_40 ( V_127 ) ) ) {
int V_136 = F_41 ( V_127 ) ;
if ( F_10 ( ( sizeof *V_128 ) <= V_136 ) )
goto V_137;
V_136 += F_42 ( V_127 ) ;
if ( F_7 ( ( sizeof *V_128 ) <= V_136 ) ) {
V_127 -> V_12 = memmove ( V_127 -> V_138 + sizeof *V_128 ,
V_127 -> V_12 , V_70 ) ;
F_43 ( V_127 , V_70 ) ;
goto V_137;
}
}
V_129 = F_44 ( V_127 , sizeof *V_128 , 1 , V_75 ) ;
F_45 ( V_127 ) ;
if ( F_10 ( ! V_129 ) )
return V_129 ;
V_127 = V_129 ;
V_137:
V_128 = ( void * ) F_46 ( V_127 , sizeof *V_128 ) ;
memset ( V_128 , 0 , sizeof *V_128 ) ;
V_128 -> V_31 = F_15 ( V_132 ) ;
V_128 -> V_29 = F_15 ( V_127 -> V_70 ) ;
V_128 -> V_130 = F_15 ( sizeof( * V_128 ) - 8 ) ;
V_128 -> V_131 = F_15 ( V_70 ) ;
return V_127 ;
}
