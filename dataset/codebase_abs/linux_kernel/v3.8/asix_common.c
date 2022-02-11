int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 , V_3 ,
V_9 | V_10 | V_11 ,
V_4 , V_5 , V_7 , V_6 ) ;
if ( V_8 != V_6 && V_8 >= 0 )
return - V_12 ;
return V_8 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
return F_4 ( V_2 , V_3 ,
V_13 | V_10 | V_11 ,
V_4 , V_5 , V_7 , V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
F_6 ( V_2 , V_3 ,
V_13 | V_10 | V_11 ,
V_4 , V_5 , V_7 , V_6 ) ;
}
int F_7 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int V_16 = 0 ;
while ( V_16 + sizeof( V_17 ) < V_15 -> V_18 ) {
struct V_14 * V_19 ;
T_2 V_6 ;
V_17 V_20 = F_8 ( V_15 -> V_7 + V_16 ) ;
V_16 += sizeof( V_17 ) ;
V_6 = ( T_2 ) ( V_20 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_20 >> 16 ) & 0x07ff ) ) {
F_9 ( V_2 -> V_21 , L_1 ) ;
return 0 ;
}
if ( ( V_6 > V_2 -> V_21 -> V_22 + V_23 + V_24 ) ||
( V_6 + V_16 > V_15 -> V_18 ) ) {
F_9 ( V_2 -> V_21 , L_2 ,
V_6 ) ;
return 0 ;
}
V_19 = F_10 ( V_2 -> V_21 , V_6 ) ;
if ( ! V_19 )
return 0 ;
F_11 ( V_19 , V_6 ) ;
memcpy ( V_19 -> V_7 , V_15 -> V_7 + V_16 , V_6 ) ;
F_12 ( V_2 , V_19 ) ;
V_16 += ( V_6 + 1 ) & 0xfffe ;
}
if ( V_15 -> V_18 != V_16 ) {
F_9 ( V_2 -> V_21 , L_3 ,
V_15 -> V_18 ) ;
return 0 ;
}
return 1 ;
}
struct V_14 * F_13 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_3 V_25 )
{
int V_26 ;
int V_27 = F_14 ( V_15 ) ;
int V_28 = F_15 ( V_15 ) ;
V_17 V_29 ;
V_17 V_30 = 0xffff0000 ;
V_26 = ( ( V_15 -> V_18 + 4 ) & ( V_2 -> V_31 - 1 ) ) ? 0 : 4 ;
if ( ! F_16 ( V_15 ) &&
! ( V_26 && F_17 ( V_15 ) ) &&
V_27 + V_28 >= 4 + V_26 ) {
if ( V_27 < 4 ||
V_28 < V_26 ) {
V_15 -> V_7 = memmove ( V_15 -> V_32 + 4 , V_15 -> V_7 , V_15 -> V_18 ) ;
F_18 ( V_15 , V_15 -> V_18 ) ;
}
} else {
struct V_14 * V_33 ;
V_33 = F_19 ( V_15 , 4 , V_26 , V_25 ) ;
F_20 ( V_15 ) ;
V_15 = V_33 ;
if ( ! V_15 )
return NULL ;
}
V_29 = ( ( V_15 -> V_18 ^ 0x0000ffff ) << 16 ) + V_15 -> V_18 ;
F_21 ( V_15 , 4 ) ;
F_22 ( & V_29 ) ;
F_23 ( V_15 , & V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_22 ( & V_30 ) ;
memcpy ( F_24 ( V_15 ) , & V_30 , sizeof( V_30 ) ) ;
F_11 ( V_15 , sizeof( V_30 ) ) ;
}
return V_15 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_34 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_21 , L_4 ) ;
return V_8 ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_35 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_21 , L_5 ) ;
return V_8 ;
}
int F_27 ( struct V_1 * V_2 , int V_36 )
{
int V_16 = ( V_36 ? 1 : 0 ) ;
T_1 V_37 [ 2 ] ;
int V_8 = F_1 ( V_2 , V_38 , 0 , 0 , 2 , V_37 ) ;
F_28 ( V_2 -> V_21 , L_6 ) ;
if ( V_8 < 0 ) {
F_9 ( V_2 -> V_21 , L_7 , V_8 ) ;
goto V_39;
}
F_28 ( V_2 -> V_21 , L_8 ,
* ( ( V_40 * ) V_37 ) ) ;
V_8 = V_37 [ V_16 ] ;
V_39:
return V_8 ;
}
int F_29 ( struct V_1 * V_2 )
{
return F_27 ( V_2 , 1 ) ;
}
int F_30 ( struct V_1 * V_2 , T_1 V_25 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_41 , V_25 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_21 , L_9 , V_8 ) ;
return V_8 ;
}
T_2 F_31 ( struct V_1 * V_2 )
{
V_40 V_42 ;
int V_8 = F_1 ( V_2 , V_43 , 0 , 0 , 2 , & V_42 ) ;
if ( V_8 < 0 ) {
F_9 ( V_2 -> V_21 , L_10 , V_8 ) ;
goto V_39;
}
V_8 = F_32 ( V_42 ) ;
V_39:
return V_8 ;
}
int F_33 ( struct V_1 * V_2 , T_2 V_44 )
{
int V_8 ;
F_28 ( V_2 -> V_21 , L_11 , V_44 ) ;
V_8 = F_3 ( V_2 , V_45 , V_44 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_21 , L_12 ,
V_44 , V_8 ) ;
return V_8 ;
}
T_2 F_34 ( struct V_1 * V_2 )
{
V_40 V_42 ;
int V_8 = F_1 ( V_2 , V_46 , 0 , 0 , 2 , & V_42 ) ;
if ( V_8 < 0 ) {
F_9 ( V_2 -> V_21 , L_13 ,
V_8 ) ;
return V_8 ;
}
return F_32 ( V_42 ) ;
}
int F_35 ( struct V_1 * V_2 , T_2 V_44 )
{
int V_8 ;
F_28 ( V_2 -> V_21 , L_14 , V_44 ) ;
V_8 = F_3 ( V_2 , V_47 , V_44 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_21 , L_15 ,
V_44 , V_8 ) ;
return V_8 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_4 , int V_48 )
{
int V_8 ;
F_28 ( V_2 -> V_21 , L_16 , V_4 ) ;
V_8 = F_3 ( V_2 , V_49 , V_4 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_21 , L_17 ,
V_4 , V_8 ) ;
if ( V_48 )
F_37 ( V_48 ) ;
return V_8 ;
}
void F_38 ( struct V_50 * V_21 )
{
struct V_1 * V_2 = F_39 ( V_21 ) ;
struct V_51 * V_7 = (struct V_51 * ) & V_2 -> V_7 ;
T_2 V_52 = V_53 ;
if ( V_21 -> V_25 & V_54 ) {
V_52 |= V_55 ;
} else if ( V_21 -> V_25 & V_56 ||
F_40 ( V_21 ) > V_57 ) {
V_52 |= V_58 ;
} else if ( F_41 ( V_21 ) ) {
} else {
struct V_59 * V_60 ;
V_17 V_61 ;
memset ( V_7 -> V_62 , 0 , V_63 ) ;
F_42 (ha, net) {
V_61 = F_43 ( V_64 , V_60 -> V_65 ) >> 26 ;
V_7 -> V_62 [ V_61 >> 3 ] |=
1 << ( V_61 & 7 ) ;
}
F_5 ( V_2 , V_66 , 0 , 0 ,
V_63 , V_7 -> V_62 ) ;
V_52 |= V_67 ;
}
F_5 ( V_2 , V_45 , V_52 , 0 , 0 , NULL ) ;
}
int F_44 ( struct V_50 * V_68 , int V_69 , int V_70 )
{
struct V_1 * V_2 = F_39 ( V_68 ) ;
V_40 V_71 ;
F_45 ( & V_2 -> V_72 ) ;
F_25 ( V_2 ) ;
F_1 ( V_2 , V_73 , V_69 ,
( V_74 ) V_70 , 2 , & V_71 ) ;
F_26 ( V_2 ) ;
F_46 ( & V_2 -> V_72 ) ;
F_28 ( V_2 -> V_21 , L_18 ,
V_69 , V_70 , F_32 ( V_71 ) ) ;
return F_32 ( V_71 ) ;
}
void F_47 ( struct V_50 * V_68 , int V_69 , int V_70 , int V_75 )
{
struct V_1 * V_2 = F_39 ( V_68 ) ;
V_40 V_71 = F_48 ( V_75 ) ;
F_28 ( V_2 -> V_21 , L_19 ,
V_69 , V_70 , V_75 ) ;
F_45 ( & V_2 -> V_72 ) ;
F_25 ( V_2 ) ;
F_3 ( V_2 , V_76 , V_69 , ( V_74 ) V_70 , 2 , & V_71 ) ;
F_26 ( V_2 ) ;
F_46 ( & V_2 -> V_72 ) ;
}
void F_49 ( struct V_50 * V_21 , struct V_77 * V_78 )
{
struct V_1 * V_2 = F_39 ( V_21 ) ;
T_1 V_79 ;
if ( F_1 ( V_2 , V_80 , 0 , 0 , 1 , & V_79 ) < 0 ) {
V_78 -> V_81 = 0 ;
V_78 -> V_82 = 0 ;
return;
}
V_78 -> V_81 = V_83 | V_84 ;
V_78 -> V_82 = 0 ;
if ( V_79 & V_85 )
V_78 -> V_82 |= V_83 ;
if ( V_79 & V_86 )
V_78 -> V_82 |= V_84 ;
}
int F_50 ( struct V_50 * V_21 , struct V_77 * V_78 )
{
struct V_1 * V_2 = F_39 ( V_21 ) ;
T_1 V_79 = 0 ;
if ( V_78 -> V_82 & V_83 )
V_79 |= V_85 ;
if ( V_78 -> V_82 & V_84 )
V_79 |= V_86 ;
if ( F_3 ( V_2 , V_87 ,
V_79 , 0 , 0 , NULL ) < 0 )
return - V_12 ;
return 0 ;
}
int F_51 ( struct V_50 * V_21 )
{
return V_88 ;
}
int F_52 ( struct V_50 * V_21 , struct V_89 * V_90 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_39 ( V_21 ) ;
T_2 * V_91 ;
int V_92 , V_93 ;
int V_94 ;
if ( V_90 -> V_18 == 0 )
return - V_12 ;
V_90 -> V_95 = V_96 ;
V_92 = V_90 -> V_16 >> 1 ;
V_93 = ( V_90 -> V_16 + V_90 -> V_18 - 1 ) >> 1 ;
V_91 = F_53 ( sizeof( T_2 ) * ( V_93 - V_92 + 1 ) ,
V_97 ) ;
if ( ! V_91 )
return - V_98 ;
for ( V_94 = V_92 ; V_94 <= V_93 ; V_94 ++ ) {
if ( F_1 ( V_2 , V_99 , V_94 , 0 , 2 ,
& ( V_91 [ V_94 - V_92 ] ) ) < 0 ) {
F_54 ( V_91 ) ;
return - V_100 ;
}
}
memcpy ( V_7 , ( T_1 * ) V_91 + ( V_90 -> V_16 & 1 ) , V_90 -> V_18 ) ;
F_54 ( V_91 ) ;
return 0 ;
}
int F_55 ( struct V_50 * V_21 , struct V_89 * V_90 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_39 ( V_21 ) ;
T_2 * V_91 ;
int V_92 , V_93 ;
int V_94 ;
int V_8 ;
F_28 ( V_21 , L_20 ,
V_90 -> V_18 , V_90 -> V_16 , V_90 -> V_95 ) ;
if ( V_90 -> V_18 == 0 )
return - V_12 ;
if ( V_90 -> V_95 != V_96 )
return - V_12 ;
V_92 = V_90 -> V_16 >> 1 ;
V_93 = ( V_90 -> V_16 + V_90 -> V_18 - 1 ) >> 1 ;
V_91 = F_53 ( sizeof( T_2 ) * ( V_93 - V_92 + 1 ) ,
V_97 ) ;
if ( ! V_91 )
return - V_98 ;
if ( V_90 -> V_16 & 1 ) {
V_8 = F_1 ( V_2 , V_99 , V_92 , 0 , 2 ,
& ( V_91 [ 0 ] ) ) ;
if ( V_8 < 0 ) {
F_9 ( V_21 , L_21 , V_92 ) ;
goto free;
}
}
if ( ( V_90 -> V_16 + V_90 -> V_18 ) & 1 ) {
V_8 = F_1 ( V_2 , V_99 , V_93 , 0 , 2 ,
& ( V_91 [ V_93 - V_92 ] ) ) ;
if ( V_8 < 0 ) {
F_9 ( V_21 , L_21 , V_93 ) ;
goto free;
}
}
memcpy ( ( T_1 * ) V_91 + ( V_90 -> V_16 & 1 ) , V_7 , V_90 -> V_18 ) ;
V_8 = F_3 ( V_2 , V_101 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_9 ( V_21 , L_22 ) ;
goto free;
}
F_37 ( 20 ) ;
for ( V_94 = V_92 ; V_94 <= V_93 ; V_94 ++ ) {
F_28 ( V_21 , L_23 ,
V_94 , V_91 [ V_94 - V_92 ] ) ;
V_8 = F_3 ( V_2 , V_102 , V_94 ,
V_91 [ V_94 - V_92 ] , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_9 ( V_21 , L_24 ,
V_94 ) ;
goto free;
}
F_37 ( 20 ) ;
}
V_8 = F_3 ( V_2 , V_103 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_9 ( V_21 , L_25 ) ;
goto free;
}
V_8 = 0 ;
free:
F_54 ( V_91 ) ;
return V_8 ;
}
void F_56 ( struct V_50 * V_21 , struct V_104 * V_105 )
{
F_57 ( V_21 , V_105 ) ;
strncpy ( V_105 -> V_106 , V_107 , sizeof V_105 -> V_106 ) ;
strncpy ( V_105 -> V_108 , V_109 , sizeof V_105 -> V_108 ) ;
V_105 -> V_110 = V_88 ;
}
int F_58 ( struct V_50 * V_21 , void * V_111 )
{
struct V_1 * V_2 = F_39 ( V_21 ) ;
struct V_51 * V_7 = (struct V_51 * ) & V_2 -> V_7 ;
struct V_112 * V_65 = V_111 ;
if ( F_59 ( V_21 ) )
return - V_113 ;
if ( ! F_60 ( V_65 -> V_114 ) )
return - V_115 ;
memcpy ( V_21 -> V_116 , V_65 -> V_114 , V_64 ) ;
memcpy ( V_7 -> V_117 , V_65 -> V_114 , V_64 ) ;
F_5 ( V_2 , V_118 , 0 , 0 , V_64 ,
V_7 -> V_117 ) ;
return 0 ;
}
