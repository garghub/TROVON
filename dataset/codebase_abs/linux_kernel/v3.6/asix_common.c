int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
void * V_8 ;
int V_9 = - V_10 ;
F_2 ( V_2 -> V_11 , L_1 ,
V_3 , V_4 , V_5 , V_6 ) ;
V_8 = F_3 ( V_6 , V_12 ) ;
if ( ! V_8 )
goto V_13;
V_9 = F_4 (
V_2 -> V_14 ,
F_5 ( V_2 -> V_14 , 0 ) ,
V_3 ,
V_15 | V_16 | V_17 ,
V_4 ,
V_5 ,
V_8 ,
V_6 ,
V_18 ) ;
if ( V_9 == V_6 )
memcpy ( V_7 , V_8 , V_6 ) ;
else if ( V_9 >= 0 )
V_9 = - V_19 ;
F_6 ( V_8 ) ;
V_13:
return V_9 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
void * V_8 = NULL ;
int V_9 = - V_10 ;
F_2 ( V_2 -> V_11 , L_2 ,
V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 ) {
V_8 = F_8 ( V_7 , V_6 , V_12 ) ;
if ( ! V_8 )
goto V_13;
}
V_9 = F_4 (
V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
V_3 ,
V_20 | V_16 | V_17 ,
V_4 ,
V_5 ,
V_8 ,
V_6 ,
V_21 ) ;
F_6 ( V_8 ) ;
V_13:
return V_9 ;
}
static void F_10 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = (struct V_23 * ) V_22 -> V_25 ;
int V_26 = V_22 -> V_26 ;
if ( V_26 < 0 )
F_11 ( V_27 L_3 ,
V_26 ) ;
F_6 ( V_24 ) ;
F_12 ( V_22 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
struct V_23 * V_24 ;
int V_26 ;
struct V_22 * V_22 ;
F_2 ( V_2 -> V_11 , L_4 ,
V_3 , V_4 , V_5 , V_6 ) ;
V_22 = F_14 ( 0 , V_28 ) ;
if ( ! V_22 ) {
F_15 ( V_2 -> V_11 , L_5 ) ;
return;
}
V_24 = F_3 ( sizeof( struct V_23 ) , V_28 ) ;
if ( ! V_24 ) {
F_15 ( V_2 -> V_11 , L_6 ) ;
F_12 ( V_22 ) ;
return;
}
V_24 -> V_29 = V_20 | V_16 | V_17 ;
V_24 -> V_30 = V_3 ;
V_24 -> V_31 = F_16 ( V_4 ) ;
V_24 -> V_32 = F_16 ( V_5 ) ;
V_24 -> V_33 = F_16 ( V_6 ) ;
F_17 ( V_22 , V_2 -> V_14 ,
F_9 ( V_2 -> V_14 , 0 ) ,
( void * ) V_24 , V_7 , V_6 ,
F_10 , V_24 ) ;
V_26 = F_18 ( V_22 , V_28 ) ;
if ( V_26 < 0 ) {
F_15 ( V_2 -> V_11 , L_7 ,
V_26 ) ;
F_6 ( V_24 ) ;
F_12 ( V_22 ) ;
}
}
int F_19 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_36 = 0 ;
while ( V_36 + sizeof( V_37 ) < V_35 -> V_38 ) {
struct V_34 * V_39 ;
T_2 V_6 ;
V_37 V_40 = F_20 ( V_35 -> V_7 + V_36 ) ;
V_36 += sizeof( V_37 ) ;
V_6 = ( T_2 ) ( V_40 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_40 >> 16 ) & 0x07ff ) ) {
F_15 ( V_2 -> V_11 , L_8 ) ;
return 0 ;
}
if ( ( V_6 > V_2 -> V_11 -> V_41 + V_42 + V_43 ) ||
( V_6 + V_36 > V_35 -> V_38 ) ) {
F_15 ( V_2 -> V_11 , L_9 ,
V_6 ) ;
return 0 ;
}
V_39 = F_21 ( V_2 -> V_11 , V_6 ) ;
if ( ! V_39 )
return 0 ;
F_22 ( V_39 , V_6 ) ;
memcpy ( V_39 -> V_7 , V_35 -> V_7 + V_36 , V_6 ) ;
F_23 ( V_2 , V_39 ) ;
V_36 += ( V_6 + 1 ) & 0xfffe ;
}
if ( V_35 -> V_38 != V_36 ) {
F_15 ( V_2 -> V_11 , L_10 ,
V_35 -> V_38 ) ;
return 0 ;
}
return 1 ;
}
struct V_34 * F_24 ( struct V_1 * V_2 , struct V_34 * V_35 ,
T_3 V_44 )
{
int V_45 ;
int V_46 = F_25 ( V_35 ) ;
int V_47 = F_26 ( V_35 ) ;
V_37 V_48 ;
V_37 V_49 = 0xffff0000 ;
V_45 = ( ( V_35 -> V_38 + 4 ) & ( V_2 -> V_50 - 1 ) ) ? 0 : 4 ;
if ( ! F_27 ( V_35 ) &&
! ( V_45 && F_28 ( V_35 ) ) &&
V_46 + V_47 >= 4 + V_45 ) {
if ( V_46 < 4 ||
V_47 < V_45 ) {
V_35 -> V_7 = memmove ( V_35 -> V_51 + 4 , V_35 -> V_7 , V_35 -> V_38 ) ;
F_29 ( V_35 , V_35 -> V_38 ) ;
}
} else {
struct V_34 * V_52 ;
V_52 = F_30 ( V_35 , 4 , V_45 , V_44 ) ;
F_31 ( V_35 ) ;
V_35 = V_52 ;
if ( ! V_35 )
return NULL ;
}
V_48 = ( ( V_35 -> V_38 ^ 0x0000ffff ) << 16 ) + V_35 -> V_38 ;
F_32 ( V_35 , 4 ) ;
F_33 ( & V_48 ) ;
F_34 ( V_35 , & V_48 , sizeof( V_48 ) ) ;
if ( V_45 ) {
F_33 ( & V_49 ) ;
memcpy ( F_35 ( V_35 ) , & V_49 , sizeof( V_49 ) ) ;
F_22 ( V_35 , sizeof( V_49 ) ) ;
}
return V_35 ;
}
int F_36 ( struct V_1 * V_2 )
{
int V_53 ;
V_53 = F_7 ( V_2 , V_54 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_53 < 0 )
F_15 ( V_2 -> V_11 , L_11 ) ;
return V_53 ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_53 ;
V_53 = F_7 ( V_2 , V_55 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_53 < 0 )
F_15 ( V_2 -> V_11 , L_12 ) ;
return V_53 ;
}
int F_38 ( struct V_1 * V_2 , int V_56 )
{
int V_36 = ( V_56 ? 1 : 0 ) ;
T_1 V_8 [ 2 ] ;
int V_53 = F_1 ( V_2 , V_57 , 0 , 0 , 2 , V_8 ) ;
F_2 ( V_2 -> V_11 , L_13 ) ;
if ( V_53 < 0 ) {
F_15 ( V_2 -> V_11 , L_14 , V_53 ) ;
goto V_13;
}
F_2 ( V_2 -> V_11 , L_15 ,
* ( ( V_58 * ) V_8 ) ) ;
V_53 = V_8 [ V_36 ] ;
V_13:
return V_53 ;
}
int F_39 ( struct V_1 * V_2 )
{
return F_38 ( V_2 , 1 ) ;
}
int F_40 ( struct V_1 * V_2 , T_1 V_44 )
{
int V_53 ;
V_53 = F_7 ( V_2 , V_59 , V_44 , 0 , 0 , NULL ) ;
if ( V_53 < 0 )
F_15 ( V_2 -> V_11 , L_16 , V_53 ) ;
return V_53 ;
}
T_2 F_41 ( struct V_1 * V_2 )
{
V_58 V_60 ;
int V_53 = F_1 ( V_2 , V_61 , 0 , 0 , 2 , & V_60 ) ;
if ( V_53 < 0 ) {
F_15 ( V_2 -> V_11 , L_17 , V_53 ) ;
goto V_13;
}
V_53 = F_42 ( V_60 ) ;
V_13:
return V_53 ;
}
int F_43 ( struct V_1 * V_2 , T_2 V_62 )
{
int V_53 ;
F_2 ( V_2 -> V_11 , L_18 , V_62 ) ;
V_53 = F_7 ( V_2 , V_63 , V_62 , 0 , 0 , NULL ) ;
if ( V_53 < 0 )
F_15 ( V_2 -> V_11 , L_19 ,
V_62 , V_53 ) ;
return V_53 ;
}
T_2 F_44 ( struct V_1 * V_2 )
{
V_58 V_60 ;
int V_53 = F_1 ( V_2 , V_64 , 0 , 0 , 2 , & V_60 ) ;
if ( V_53 < 0 ) {
F_15 ( V_2 -> V_11 , L_20 ,
V_53 ) ;
return V_53 ;
}
return F_42 ( V_60 ) ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_62 )
{
int V_53 ;
F_2 ( V_2 -> V_11 , L_21 , V_62 ) ;
V_53 = F_7 ( V_2 , V_65 , V_62 , 0 , 0 , NULL ) ;
if ( V_53 < 0 )
F_15 ( V_2 -> V_11 , L_22 ,
V_62 , V_53 ) ;
return V_53 ;
}
int F_46 ( struct V_1 * V_2 , T_2 V_4 , int V_66 )
{
int V_53 ;
F_2 ( V_2 -> V_11 , L_23 , V_4 ) ;
V_53 = F_7 ( V_2 , V_67 , V_4 , 0 , 0 , NULL ) ;
if ( V_53 < 0 )
F_15 ( V_2 -> V_11 , L_24 ,
V_4 , V_53 ) ;
if ( V_66 )
F_47 ( V_66 ) ;
return V_53 ;
}
void F_48 ( struct V_68 * V_11 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
struct V_69 * V_7 = (struct V_69 * ) & V_2 -> V_7 ;
T_2 V_70 = V_71 ;
if ( V_11 -> V_44 & V_72 ) {
V_70 |= V_73 ;
} else if ( V_11 -> V_44 & V_74 ||
F_50 ( V_11 ) > V_75 ) {
V_70 |= V_76 ;
} else if ( F_51 ( V_11 ) ) {
} else {
struct V_77 * V_78 ;
V_37 V_79 ;
memset ( V_7 -> V_80 , 0 , V_81 ) ;
F_52 (ha, net) {
V_79 = F_53 ( V_82 , V_78 -> V_83 ) >> 26 ;
V_7 -> V_80 [ V_79 >> 3 ] |=
1 << ( V_79 & 7 ) ;
}
F_13 ( V_2 , V_84 , 0 , 0 ,
V_81 , V_7 -> V_80 ) ;
V_70 |= V_85 ;
}
F_13 ( V_2 , V_63 , V_70 , 0 , 0 , NULL ) ;
}
int F_54 ( struct V_68 * V_86 , int V_87 , int V_88 )
{
struct V_1 * V_2 = F_49 ( V_86 ) ;
V_58 V_89 ;
F_55 ( & V_2 -> V_90 ) ;
F_36 ( V_2 ) ;
F_1 ( V_2 , V_91 , V_87 ,
( V_92 ) V_88 , 2 , & V_89 ) ;
F_37 ( V_2 ) ;
F_56 ( & V_2 -> V_90 ) ;
F_2 ( V_2 -> V_11 , L_25 ,
V_87 , V_88 , F_42 ( V_89 ) ) ;
return F_42 ( V_89 ) ;
}
void F_57 ( struct V_68 * V_86 , int V_87 , int V_88 , int V_93 )
{
struct V_1 * V_2 = F_49 ( V_86 ) ;
V_58 V_89 = F_16 ( V_93 ) ;
F_2 ( V_2 -> V_11 , L_26 ,
V_87 , V_88 , V_93 ) ;
F_55 ( & V_2 -> V_90 ) ;
F_36 ( V_2 ) ;
F_7 ( V_2 , V_94 , V_87 , ( V_92 ) V_88 , 2 , & V_89 ) ;
F_37 ( V_2 ) ;
F_56 ( & V_2 -> V_90 ) ;
}
void F_58 ( struct V_68 * V_11 , struct V_95 * V_96 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
T_1 V_97 ;
if ( F_1 ( V_2 , V_98 , 0 , 0 , 1 , & V_97 ) < 0 ) {
V_96 -> V_99 = 0 ;
V_96 -> V_100 = 0 ;
return;
}
V_96 -> V_99 = V_101 | V_102 ;
V_96 -> V_100 = 0 ;
if ( V_97 & V_103 )
V_96 -> V_100 |= V_101 ;
if ( V_97 & V_104 )
V_96 -> V_100 |= V_102 ;
}
int F_59 ( struct V_68 * V_11 , struct V_95 * V_96 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
T_1 V_97 = 0 ;
if ( V_96 -> V_100 & V_101 )
V_97 |= V_103 ;
if ( V_96 -> V_100 & V_102 )
V_97 |= V_104 ;
if ( F_7 ( V_2 , V_105 ,
V_97 , 0 , 0 , NULL ) < 0 )
return - V_19 ;
return 0 ;
}
int F_60 ( struct V_68 * V_11 )
{
return V_106 ;
}
int F_61 ( struct V_68 * V_11 , struct V_107 * V_108 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
T_2 * V_109 ;
int V_110 , V_111 ;
int V_112 ;
if ( V_108 -> V_38 == 0 )
return - V_19 ;
V_108 -> V_113 = V_114 ;
V_110 = V_108 -> V_36 >> 1 ;
V_111 = ( V_108 -> V_36 + V_108 -> V_38 - 1 ) >> 1 ;
V_109 = F_3 ( sizeof( T_2 ) * ( V_111 - V_110 + 1 ) ,
V_12 ) ;
if ( ! V_109 )
return - V_10 ;
for ( V_112 = V_110 ; V_112 <= V_111 ; V_112 ++ ) {
if ( F_1 ( V_2 , V_115 , V_112 , 0 , 2 ,
& ( V_109 [ V_112 - V_110 ] ) ) < 0 ) {
F_6 ( V_109 ) ;
return - V_116 ;
}
}
memcpy ( V_7 , ( T_1 * ) V_109 + ( V_108 -> V_36 & 1 ) , V_108 -> V_38 ) ;
F_6 ( V_109 ) ;
return 0 ;
}
int F_62 ( struct V_68 * V_11 , struct V_107 * V_108 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
T_2 * V_109 ;
int V_110 , V_111 ;
int V_112 ;
int V_53 ;
F_2 ( V_11 , L_27 ,
V_108 -> V_38 , V_108 -> V_36 , V_108 -> V_113 ) ;
if ( V_108 -> V_38 == 0 )
return - V_19 ;
if ( V_108 -> V_113 != V_114 )
return - V_19 ;
V_110 = V_108 -> V_36 >> 1 ;
V_111 = ( V_108 -> V_36 + V_108 -> V_38 - 1 ) >> 1 ;
V_109 = F_3 ( sizeof( T_2 ) * ( V_111 - V_110 + 1 ) ,
V_12 ) ;
if ( ! V_109 )
return - V_10 ;
if ( V_108 -> V_36 & 1 ) {
V_53 = F_1 ( V_2 , V_115 , V_110 , 0 , 2 ,
& ( V_109 [ 0 ] ) ) ;
if ( V_53 < 0 ) {
F_15 ( V_11 , L_28 , V_110 ) ;
goto free;
}
}
if ( ( V_108 -> V_36 + V_108 -> V_38 ) & 1 ) {
V_53 = F_1 ( V_2 , V_115 , V_111 , 0 , 2 ,
& ( V_109 [ V_111 - V_110 ] ) ) ;
if ( V_53 < 0 ) {
F_15 ( V_11 , L_28 , V_111 ) ;
goto free;
}
}
memcpy ( ( T_1 * ) V_109 + ( V_108 -> V_36 & 1 ) , V_7 , V_108 -> V_38 ) ;
V_53 = F_7 ( V_2 , V_117 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_53 < 0 ) {
F_15 ( V_11 , L_29 ) ;
goto free;
}
F_47 ( 20 ) ;
for ( V_112 = V_110 ; V_112 <= V_111 ; V_112 ++ ) {
F_2 ( V_11 , L_30 ,
V_112 , V_109 [ V_112 - V_110 ] ) ;
V_53 = F_7 ( V_2 , V_118 , V_112 ,
V_109 [ V_112 - V_110 ] , 0 , NULL ) ;
if ( V_53 < 0 ) {
F_15 ( V_11 , L_31 ,
V_112 ) ;
goto free;
}
F_47 ( 20 ) ;
}
V_53 = F_7 ( V_2 , V_119 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_53 < 0 ) {
F_15 ( V_11 , L_32 ) ;
goto free;
}
V_53 = 0 ;
free:
F_6 ( V_109 ) ;
return V_53 ;
}
void F_63 ( struct V_68 * V_11 , struct V_120 * V_121 )
{
F_64 ( V_11 , V_121 ) ;
strncpy ( V_121 -> V_122 , V_123 , sizeof V_121 -> V_122 ) ;
strncpy ( V_121 -> V_124 , V_125 , sizeof V_121 -> V_124 ) ;
V_121 -> V_126 = V_106 ;
}
int F_65 ( struct V_68 * V_11 , void * V_127 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
struct V_69 * V_7 = (struct V_69 * ) & V_2 -> V_7 ;
struct V_128 * V_83 = V_127 ;
if ( F_66 ( V_11 ) )
return - V_129 ;
if ( ! F_67 ( V_83 -> V_130 ) )
return - V_131 ;
memcpy ( V_11 -> V_132 , V_83 -> V_130 , V_82 ) ;
memcpy ( V_7 -> V_133 , V_83 -> V_130 , V_82 ) ;
F_13 ( V_2 , V_134 , 0 , 0 , V_82 ,
V_7 -> V_133 ) ;
return 0 ;
}
