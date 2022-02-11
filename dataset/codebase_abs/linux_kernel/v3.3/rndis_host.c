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
switch ( V_8 -> V_6 ) {
case V_18 :
F_4 ( V_14 , L_2 ) ;
break;
case V_19 :
F_4 ( V_14 , L_3 ) ;
break;
default:
F_4 ( V_14 , L_4 ,
F_5 ( V_8 -> V_6 ) ) ;
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
T_1 V_28 ;
T_2 V_29 = 0 , V_30 , V_31 ;
if ( F_7 ( V_21 -> V_32 != V_33 &&
V_21 -> V_32 != V_34 ) ) {
V_29 = V_2 -> V_29 ++ ;
if ( ! V_29 )
V_29 = V_2 -> V_29 ++ ;
V_21 -> V_31 = ( V_35 T_1 ) V_29 ;
}
V_24 = V_11 -> V_15 -> V_36 -> V_37 . V_38 ;
V_25 = F_8 ( V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
V_39 ,
V_40 | V_41 ,
0 , V_24 ,
V_21 , F_5 ( V_21 -> V_30 ) ,
V_42 ) ;
if ( F_10 ( V_25 < 0 || V_29 == 0 ) )
return V_25 ;
if ( V_2 -> V_16 -> V_12 & V_43 ) {
V_25 = F_11 (
V_2 -> V_14 ,
F_12 ( V_2 -> V_14 ,
V_2 -> V_6 -> V_37 . V_44 ) ,
& V_23 , sizeof( V_23 ) , & V_26 ,
V_42 ) ;
if ( F_10 ( V_25 < 0 ) )
return V_25 ;
}
V_28 = V_21 -> V_32 | V_45 ;
for ( V_27 = 0 ; V_27 < 10 ; V_27 ++ ) {
memset ( V_21 , 0 , V_46 ) ;
V_25 = F_8 ( V_2 -> V_14 ,
F_13 ( V_2 -> V_14 , 0 ) ,
V_47 ,
V_48 | V_40 | V_41 ,
0 , V_24 ,
V_21 , V_9 ,
V_42 ) ;
if ( F_7 ( V_25 >= 8 ) ) {
V_30 = F_5 ( V_21 -> V_30 ) ;
V_31 = ( V_35 T_2 ) V_21 -> V_31 ;
if ( F_7 ( V_21 -> V_32 == V_28 ) ) {
if ( F_7 ( V_31 == V_29 ) ) {
if ( F_10 ( V_28 == V_49 ) )
return 0 ;
if ( F_7 ( V_50
== V_21 -> V_6 ) )
return 0 ;
F_14 ( & V_11 -> V_15 -> V_2 ,
L_5 ,
F_5 ( V_21 -> V_6 ) ) ;
return - V_51 ;
}
F_14 ( & V_11 -> V_15 -> V_2 ,
L_6 ,
V_31 , V_29 ) ;
} else switch ( V_21 -> V_32 ) {
case V_52 :
F_3 ( V_2 , ( void * ) V_21 , V_9 ) ;
break;
case V_53 : {
struct V_54 * V_8 = ( void * ) V_21 ;
V_8 -> V_32 = V_55 ;
V_8 -> V_30 = F_15 ( sizeof *V_8 ) ;
V_8 -> V_6 = V_50 ;
V_25 = F_8 ( V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
V_39 ,
V_40 | V_41 ,
0 , V_24 ,
V_8 , sizeof *V_8 ,
V_42 ) ;
if ( F_10 ( V_25 < 0 ) )
F_14 ( & V_11 -> V_15 -> V_2 ,
L_7 ,
V_25 ) ;
}
break;
default:
F_14 ( & V_11 -> V_15 -> V_2 ,
L_8 ,
F_5 ( V_21 -> V_32 ) , V_30 ) ;
}
} else {
F_14 ( & V_11 -> V_15 -> V_2 ,
L_9 , V_25 ) ;
}
F_16 ( 20 ) ;
}
F_14 ( & V_11 -> V_15 -> V_2 , L_10 ) ;
return - V_56 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_57 * V_58 ,
void * V_21 , T_1 V_59 , T_2 V_60 ,
void * * V_61 , int * V_62 )
{
int V_25 ;
union {
void * V_21 ;
struct V_20 * V_63 ;
struct F_17 * V_64 ;
struct V_65 * V_66 ;
} V_67 ;
T_2 V_68 , V_69 ;
V_67 . V_21 = V_21 ;
memset ( V_67 . V_64 , 0 , sizeof * V_67 . V_64 + V_60 ) ;
V_67 . V_64 -> V_32 = V_70 ;
V_67 . V_64 -> V_30 = F_15 ( sizeof * V_67 . V_64 + V_60 ) ;
V_67 . V_64 -> V_59 = V_59 ;
V_67 . V_64 -> V_69 = F_15 ( V_60 ) ;
V_67 . V_64 -> V_71 = F_15 ( 20 ) ;
V_25 = F_6 ( V_2 , V_67 . V_63 , V_46 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_58 -> V_2 , L_11 ,
V_59 , V_25 ) ;
return V_25 ;
}
V_68 = F_5 ( V_67 . V_66 -> V_71 ) ;
V_69 = F_5 ( V_67 . V_66 -> V_69 ) ;
if ( F_10 ( ( 8 + V_68 + V_69 ) > V_46 ) )
goto V_72;
if ( * V_62 != - 1 && V_69 != * V_62 )
goto V_72;
* V_61 = ( unsigned char * ) & V_67 . V_66 -> V_31 + V_68 ;
* V_62 = V_69 ;
return V_25 ;
V_72:
F_18 ( & V_58 -> V_2 , L_12
L_13 ,
V_59 , V_68 , V_69 ) ;
return - V_73 ;
}
int
F_19 ( struct V_1 * V_2 , struct V_57 * V_58 , int V_74 )
{
int V_25 ;
struct V_75 * V_4 = V_2 -> V_4 ;
struct V_10 * V_11 = ( void * ) & V_2 -> V_12 ;
union {
void * V_21 ;
struct V_20 * V_63 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct F_17 * V_64 ;
struct V_65 * V_66 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
} V_67 ;
T_2 V_86 ;
T_1 V_87 , * V_88 ;
int V_62 ;
unsigned char * V_89 ;
V_67 . V_21 = F_20 ( V_46 , V_90 ) ;
if ( ! V_67 . V_21 )
return - V_91 ;
V_25 = F_21 ( V_2 , V_58 ) ;
if ( V_25 < 0 )
goto V_92;
V_67 . V_77 -> V_32 = V_93 ;
V_67 . V_77 -> V_30 = F_15 ( sizeof * V_67 . V_77 ) ;
V_67 . V_77 -> V_94 = F_15 ( 1 ) ;
V_67 . V_77 -> V_95 = F_15 ( 0 ) ;
V_4 -> V_96 += sizeof ( struct V_97 ) ;
V_2 -> V_98 = V_4 -> V_99 + V_4 -> V_96 ;
V_2 -> V_100 = F_22 ( V_2 -> V_14 , V_2 -> V_101 , 1 ) ;
if ( V_2 -> V_100 == 0 ) {
F_23 ( V_2 , V_102 , V_2 -> V_4 ,
L_14 ) ;
V_25 = - V_103 ;
goto V_104;
}
V_2 -> V_105 = V_2 -> V_98 + ( V_2 -> V_100 + 1 ) ;
V_2 -> V_105 &= ~ ( V_2 -> V_100 - 1 ) ;
V_67 . V_77 -> V_106 = F_15 ( V_2 -> V_105 ) ;
V_4 -> V_107 = & V_108 ;
V_25 = F_6 ( V_2 , V_67 . V_63 , V_46 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_58 -> V_2 , L_15 , V_25 ) ;
goto V_104;
}
V_86 = F_5 ( V_67 . V_79 -> V_106 ) ;
if ( V_86 < V_2 -> V_98 ) {
if ( V_86 <= V_4 -> V_96 ) {
F_18 ( & V_58 -> V_2 ,
L_16 ,
V_2 -> V_98 , V_86 ) ;
V_25 = - V_103 ;
goto V_109;
}
F_24 ( & V_58 -> V_2 ,
L_17
L_18 ,
V_2 -> V_98 , V_86 , V_86 - V_4 -> V_96 ) ;
V_2 -> V_98 = V_86 ;
V_4 -> V_99 = V_2 -> V_98 - V_4 -> V_96 ;
}
F_14 ( & V_58 -> V_2 ,
L_19 ,
V_2 -> V_98 , V_86 , V_2 -> V_105 ,
1 << F_5 ( V_67 . V_79 -> V_110 ) ) ;
if ( V_2 -> V_16 -> V_111 &&
V_2 -> V_16 -> V_111 ( V_2 ) != 0 )
goto V_109;
V_88 = NULL ;
V_62 = sizeof *V_88 ;
V_25 = F_17 ( V_2 , V_58 , V_67 . V_21 , V_112 ,
0 , ( void * * ) & V_88 , & V_62 ) ;
if ( V_25 != 0 || ! V_88 ) {
V_87 = V_113 ;
V_88 = & V_87 ;
}
if ( ( V_74 & V_114 ) &&
* V_88 != V_115 ) {
F_23 ( V_2 , V_102 , V_2 -> V_4 ,
L_20 ) ;
V_25 = - V_116 ;
goto V_109;
}
if ( ( V_74 & V_117 ) &&
* V_88 == V_115 ) {
F_23 ( V_2 , V_102 , V_2 -> V_4 ,
L_21 ) ;
V_25 = - V_116 ;
goto V_109;
}
V_62 = V_118 ;
V_25 = F_17 ( V_2 , V_58 , V_67 . V_21 , V_119 ,
48 , ( void * * ) & V_89 , & V_62 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_58 -> V_2 , L_22 , V_25 ) ;
goto V_109;
}
memcpy ( V_4 -> V_120 , V_89 , V_118 ) ;
memcpy ( V_4 -> V_121 , V_89 , V_118 ) ;
memset ( V_67 . V_81 , 0 , sizeof * V_67 . V_81 ) ;
V_67 . V_81 -> V_32 = V_122 ;
V_67 . V_81 -> V_30 = F_15 ( 4 + sizeof * V_67 . V_81 ) ;
V_67 . V_81 -> V_59 = V_123 ;
V_67 . V_81 -> V_69 = F_15 ( 4 ) ;
V_67 . V_81 -> V_71 = F_15 ( ( sizeof * V_67 . V_81 ) - 8 ) ;
* ( T_1 * ) ( V_67 . V_21 + sizeof * V_67 . V_81 ) = V_124 ;
V_25 = F_6 ( V_2 , V_67 . V_63 , V_46 ) ;
if ( F_10 ( V_25 < 0 ) ) {
F_18 ( & V_58 -> V_2 , L_23 , V_25 ) ;
goto V_109;
}
V_25 = 0 ;
F_25 ( V_67 . V_21 ) ;
return V_25 ;
V_109:
memset ( V_67 . V_85 , 0 , sizeof * V_67 . V_85 ) ;
V_67 . V_85 -> V_32 = V_33 ;
V_67 . V_85 -> V_30 = F_15 ( sizeof * V_67 . V_85 ) ;
( void ) F_6 ( V_2 , ( void * ) V_67 . V_85 , V_46 ) ;
V_104:
F_26 ( V_11 -> V_12 , NULL ) ;
F_27 ( F_28 ( V_58 ) , V_11 -> V_12 ) ;
V_11 -> V_12 = NULL ;
V_92:
F_25 ( V_67 . V_21 ) ;
return V_25 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
return F_19 ( V_2 , V_58 , V_117 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_84 * V_85 ;
V_85 = F_31 ( V_46 , V_90 ) ;
if ( V_85 ) {
V_85 -> V_32 = V_33 ;
V_85 -> V_30 = F_15 ( sizeof *V_85 ) ;
( void ) F_6 ( V_2 , ( void * ) V_85 , V_46 ) ;
F_25 ( V_85 ) ;
}
F_32 ( V_2 , V_58 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_125 * V_126 )
{
while ( F_7 ( V_126 -> V_69 ) ) {
struct V_97 * V_127 = ( void * ) V_126 -> V_12 ;
struct V_125 * V_128 ;
T_2 V_30 , V_129 , V_130 ;
V_30 = F_5 ( V_127 -> V_30 ) ;
V_129 = F_5 ( V_127 -> V_129 ) ;
V_130 = F_5 ( V_127 -> V_130 ) ;
if ( F_10 ( V_127 -> V_32 != V_131 ||
V_126 -> V_69 < V_30 ||
( V_129 + V_130 + 8 ) > V_30 ) ) {
V_2 -> V_4 -> V_132 . V_133 ++ ;
F_2 ( V_2 -> V_4 , L_24 ,
F_5 ( V_127 -> V_32 ) ,
V_30 , V_129 , V_130 , V_126 -> V_69 ) ;
return 0 ;
}
F_34 ( V_126 , 8 + V_129 ) ;
if ( F_7 ( ( V_130 - V_126 -> V_69 ) <= sizeof *V_127 ) ) {
F_35 ( V_126 , V_130 ) ;
break;
}
V_128 = F_36 ( V_126 , V_134 ) ;
if ( F_10 ( ! V_128 ) )
break;
F_34 ( V_126 , V_30 - sizeof *V_127 ) ;
F_35 ( V_128 , V_130 ) ;
F_37 ( V_2 , V_128 ) ;
}
return 1 ;
}
struct V_125 *
F_38 ( struct V_1 * V_2 , struct V_125 * V_126 , T_3 V_74 )
{
struct V_97 * V_127 ;
struct V_125 * V_128 ;
unsigned V_69 = V_126 -> V_69 ;
if ( F_7 ( ! F_39 ( V_126 ) ) ) {
int V_135 = F_40 ( V_126 ) ;
if ( F_10 ( ( sizeof *V_127 ) <= V_135 ) )
goto V_136;
V_135 += F_41 ( V_126 ) ;
if ( F_7 ( ( sizeof *V_127 ) <= V_135 ) ) {
V_126 -> V_12 = memmove ( V_126 -> V_137 + sizeof *V_127 ,
V_126 -> V_12 , V_69 ) ;
F_42 ( V_126 , V_69 ) ;
goto V_136;
}
}
V_128 = F_43 ( V_126 , sizeof *V_127 , 1 , V_74 ) ;
F_44 ( V_126 ) ;
if ( F_10 ( ! V_128 ) )
return V_128 ;
V_126 = V_128 ;
V_136:
V_127 = ( void * ) F_45 ( V_126 , sizeof *V_127 ) ;
memset ( V_127 , 0 , sizeof *V_127 ) ;
V_127 -> V_32 = V_131 ;
V_127 -> V_30 = F_15 ( V_126 -> V_69 ) ;
V_127 -> V_129 = F_15 ( sizeof( * V_127 ) - 8 ) ;
V_127 -> V_130 = F_15 ( V_69 ) ;
return V_126 ;
}
