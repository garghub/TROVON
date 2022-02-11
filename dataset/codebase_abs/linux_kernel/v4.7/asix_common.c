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
int F_7 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_18 = 0 ;
T_2 V_6 ;
if ( V_17 -> V_19 && ( V_17 -> V_19 + sizeof( V_20 ) <= V_15 -> V_21 ) ) {
V_18 = ( ( V_17 -> V_19 + 1 ) & 0xfffe ) ;
V_17 -> V_22 = F_8 ( V_15 -> V_7 + V_18 ) ;
V_18 = 0 ;
V_6 = ( T_2 ) ( V_17 -> V_22 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_17 -> V_22 >> 16 ) & 0x7ff ) ) {
F_9 ( V_2 -> V_23 , L_1 ,
V_17 -> V_19 ) ;
if ( V_17 -> V_24 ) {
F_10 ( V_17 -> V_24 ) ;
V_17 -> V_24 = NULL ;
}
V_17 -> V_19 = 0 ;
}
}
while ( V_18 + sizeof( T_2 ) <= V_15 -> V_21 ) {
T_2 V_25 ;
unsigned char * V_7 ;
if ( ! V_17 -> V_19 ) {
if ( V_15 -> V_21 - V_18 == sizeof( T_2 ) ) {
V_17 -> V_22 = F_11 (
V_15 -> V_7 + V_18 ) ;
V_17 -> V_26 = true ;
V_18 += sizeof( T_2 ) ;
break;
}
if ( V_17 -> V_26 == true ) {
V_17 -> V_22 |= ( F_11 (
V_15 -> V_7 + V_18 ) << 16 ) ;
V_17 -> V_26 = false ;
V_18 += sizeof( T_2 ) ;
} else {
V_17 -> V_22 = F_8 ( V_15 -> V_7 +
V_18 ) ;
V_18 += sizeof( V_20 ) ;
}
V_6 = ( T_2 ) ( V_17 -> V_22 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_17 -> V_22 >> 16 ) & 0x7ff ) ) {
F_9 ( V_2 -> V_23 , L_2 ,
V_17 -> V_22 , V_18 ) ;
return 0 ;
}
if ( V_6 > V_2 -> V_23 -> V_27 + V_28 + V_29 ) {
F_12 ( V_2 -> V_23 , L_3 ,
V_6 ) ;
return 0 ;
}
V_17 -> V_24 = F_13 ( V_2 -> V_23 , V_6 ) ;
V_17 -> V_19 = V_6 ;
}
if ( V_17 -> V_19 > V_15 -> V_21 - V_18 ) {
V_25 = V_15 -> V_21 - V_18 ;
V_17 -> V_19 -= V_25 ;
} else {
V_25 = V_17 -> V_19 ;
V_17 -> V_19 = 0 ;
}
if ( V_17 -> V_24 ) {
V_7 = F_14 ( V_17 -> V_24 , V_25 ) ;
memcpy ( V_7 , V_15 -> V_7 + V_18 , V_25 ) ;
if ( ! V_17 -> V_19 )
F_15 ( V_2 , V_17 -> V_24 ) ;
}
V_18 += ( V_25 + 1 ) & 0xfffe ;
}
if ( V_15 -> V_21 != V_18 ) {
F_9 ( V_2 -> V_23 , L_4 ,
V_15 -> V_21 , V_18 ) ;
return 0 ;
}
return 1 ;
}
int F_16 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_30 * V_31 = V_2 -> V_32 ;
struct V_16 * V_17 = & V_31 -> V_33 ;
return F_7 ( V_2 , V_15 , V_17 ) ;
}
struct V_14 * F_17 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_3 V_34 )
{
int V_35 ;
int V_36 = F_18 ( V_15 ) ;
int V_37 = F_19 ( V_15 ) ;
V_20 V_38 ;
V_20 V_39 = 0xffff0000 ;
V_35 = ( ( V_15 -> V_21 + 4 ) & ( V_2 -> V_40 - 1 ) ) ? 0 : 4 ;
if ( ! F_20 ( V_15 ) &&
! ( V_35 && F_21 ( V_15 ) ) &&
V_36 + V_37 >= 4 + V_35 ) {
if ( V_36 < 4 ||
V_37 < V_35 ) {
V_15 -> V_7 = memmove ( V_15 -> V_41 + 4 , V_15 -> V_7 , V_15 -> V_21 ) ;
F_22 ( V_15 , V_15 -> V_21 ) ;
}
} else {
struct V_14 * V_42 ;
V_42 = F_23 ( V_15 , 4 , V_35 , V_34 ) ;
F_24 ( V_15 ) ;
V_15 = V_42 ;
if ( ! V_15 )
return NULL ;
}
V_38 = ( ( V_15 -> V_21 ^ 0x0000ffff ) << 16 ) + V_15 -> V_21 ;
F_25 ( V_15 , 4 ) ;
F_26 ( & V_38 ) ;
F_27 ( V_15 , & V_38 , sizeof( V_38 ) ) ;
if ( V_35 ) {
F_26 ( & V_39 ) ;
memcpy ( F_28 ( V_15 ) , & V_39 , sizeof( V_39 ) ) ;
F_14 ( V_15 , sizeof( V_39 ) ) ;
}
F_29 ( V_15 , 1 , 0 ) ;
return V_15 ;
}
int F_30 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_43 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_23 , L_5 ) ;
return V_8 ;
}
int F_31 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_44 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_23 , L_6 ) ;
return V_8 ;
}
int F_32 ( struct V_1 * V_2 , int V_45 )
{
int V_18 = ( V_45 ? 1 : 0 ) ;
T_1 V_46 [ 2 ] ;
int V_8 = F_1 ( V_2 , V_47 , 0 , 0 , 2 , V_46 ) ;
F_12 ( V_2 -> V_23 , L_7 ) ;
if ( V_8 < 0 ) {
F_9 ( V_2 -> V_23 , L_8 , V_8 ) ;
goto V_48;
}
F_12 ( V_2 -> V_23 , L_9 ,
* ( ( V_49 * ) V_46 ) ) ;
V_8 = V_46 [ V_18 ] ;
V_48:
return V_8 ;
}
int F_33 ( struct V_1 * V_2 )
{
return F_32 ( V_2 , 1 ) ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_34 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_50 , V_34 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_23 , L_10 , V_8 ) ;
return V_8 ;
}
T_2 F_35 ( struct V_1 * V_2 )
{
V_49 V_51 ;
int V_8 = F_1 ( V_2 , V_52 , 0 , 0 , 2 , & V_51 ) ;
if ( V_8 < 0 ) {
F_9 ( V_2 -> V_23 , L_11 , V_8 ) ;
goto V_48;
}
V_8 = F_36 ( V_51 ) ;
V_48:
return V_8 ;
}
int F_37 ( struct V_1 * V_2 , T_2 V_53 )
{
int V_8 ;
F_12 ( V_2 -> V_23 , L_12 , V_53 ) ;
V_8 = F_3 ( V_2 , V_54 , V_53 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_23 , L_13 ,
V_53 , V_8 ) ;
return V_8 ;
}
T_2 F_38 ( struct V_1 * V_2 )
{
V_49 V_51 ;
int V_8 = F_1 ( V_2 , V_55 , 0 , 0 , 2 , & V_51 ) ;
if ( V_8 < 0 ) {
F_9 ( V_2 -> V_23 , L_14 ,
V_8 ) ;
return V_8 ;
}
return F_36 ( V_51 ) ;
}
int F_39 ( struct V_1 * V_2 , T_2 V_53 )
{
int V_8 ;
F_12 ( V_2 -> V_23 , L_15 , V_53 ) ;
V_8 = F_3 ( V_2 , V_56 , V_53 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_23 , L_16 ,
V_53 , V_8 ) ;
return V_8 ;
}
int F_40 ( struct V_1 * V_2 , T_2 V_4 , int V_57 )
{
int V_8 ;
F_12 ( V_2 -> V_23 , L_17 , V_4 ) ;
V_8 = F_3 ( V_2 , V_58 , V_4 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_9 ( V_2 -> V_23 , L_18 ,
V_4 , V_8 ) ;
if ( V_57 )
F_41 ( V_57 ) ;
return V_8 ;
}
void F_42 ( struct V_59 * V_23 )
{
struct V_1 * V_2 = F_43 ( V_23 ) ;
struct V_60 * V_7 = (struct V_60 * ) & V_2 -> V_7 ;
T_2 V_61 = V_62 ;
if ( V_23 -> V_34 & V_63 ) {
V_61 |= V_64 ;
} else if ( V_23 -> V_34 & V_65 ||
F_44 ( V_23 ) > V_66 ) {
V_61 |= V_67 ;
} else if ( F_45 ( V_23 ) ) {
} else {
struct V_68 * V_69 ;
V_20 V_70 ;
memset ( V_7 -> V_71 , 0 , V_72 ) ;
F_46 (ha, net) {
V_70 = F_47 ( V_73 , V_69 -> V_74 ) >> 26 ;
V_7 -> V_71 [ V_70 >> 3 ] |=
1 << ( V_70 & 7 ) ;
}
F_5 ( V_2 , V_75 , 0 , 0 ,
V_72 , V_7 -> V_71 ) ;
V_61 |= V_76 ;
}
F_5 ( V_2 , V_54 , V_61 , 0 , 0 , NULL ) ;
}
int F_48 ( struct V_59 * V_77 , int V_78 , int V_79 )
{
struct V_1 * V_2 = F_43 ( V_77 ) ;
V_49 V_80 ;
F_49 ( & V_2 -> V_81 ) ;
F_30 ( V_2 ) ;
F_1 ( V_2 , V_82 , V_78 ,
( V_83 ) V_79 , 2 , & V_80 ) ;
F_31 ( V_2 ) ;
F_50 ( & V_2 -> V_81 ) ;
F_12 ( V_2 -> V_23 , L_19 ,
V_78 , V_79 , F_36 ( V_80 ) ) ;
return F_36 ( V_80 ) ;
}
void F_51 ( struct V_59 * V_77 , int V_78 , int V_79 , int V_84 )
{
struct V_1 * V_2 = F_43 ( V_77 ) ;
V_49 V_80 = F_52 ( V_84 ) ;
F_12 ( V_2 -> V_23 , L_20 ,
V_78 , V_79 , V_84 ) ;
F_49 ( & V_2 -> V_81 ) ;
F_30 ( V_2 ) ;
F_3 ( V_2 , V_85 , V_78 , ( V_83 ) V_79 , 2 , & V_80 ) ;
F_31 ( V_2 ) ;
F_50 ( & V_2 -> V_81 ) ;
}
void F_53 ( struct V_59 * V_23 , struct V_86 * V_87 )
{
struct V_1 * V_2 = F_43 ( V_23 ) ;
T_1 V_88 ;
if ( F_1 ( V_2 , V_89 , 0 , 0 , 1 , & V_88 ) < 0 ) {
V_87 -> V_90 = 0 ;
V_87 -> V_91 = 0 ;
return;
}
V_87 -> V_90 = V_92 | V_93 ;
V_87 -> V_91 = 0 ;
if ( V_88 & V_94 )
V_87 -> V_91 |= V_92 ;
if ( V_88 & V_95 )
V_87 -> V_91 |= V_93 ;
}
int F_54 ( struct V_59 * V_23 , struct V_86 * V_87 )
{
struct V_1 * V_2 = F_43 ( V_23 ) ;
T_1 V_88 = 0 ;
if ( V_87 -> V_91 & V_92 )
V_88 |= V_94 ;
if ( V_87 -> V_91 & V_93 )
V_88 |= V_95 ;
if ( F_3 ( V_2 , V_96 ,
V_88 , 0 , 0 , NULL ) < 0 )
return - V_12 ;
return 0 ;
}
int F_55 ( struct V_59 * V_23 )
{
return V_97 ;
}
int F_56 ( struct V_59 * V_23 , struct V_98 * V_99 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_43 ( V_23 ) ;
T_2 * V_100 ;
int V_101 , V_102 ;
int V_103 ;
if ( V_99 -> V_21 == 0 )
return - V_12 ;
V_99 -> V_104 = V_105 ;
V_101 = V_99 -> V_18 >> 1 ;
V_102 = ( V_99 -> V_18 + V_99 -> V_21 - 1 ) >> 1 ;
V_100 = F_57 ( sizeof( T_2 ) * ( V_102 - V_101 + 1 ) ,
V_106 ) ;
if ( ! V_100 )
return - V_107 ;
for ( V_103 = V_101 ; V_103 <= V_102 ; V_103 ++ ) {
if ( F_1 ( V_2 , V_108 , V_103 , 0 , 2 ,
& ( V_100 [ V_103 - V_101 ] ) ) < 0 ) {
F_58 ( V_100 ) ;
return - V_109 ;
}
}
memcpy ( V_7 , ( T_1 * ) V_100 + ( V_99 -> V_18 & 1 ) , V_99 -> V_21 ) ;
F_58 ( V_100 ) ;
return 0 ;
}
int F_59 ( struct V_59 * V_23 , struct V_98 * V_99 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_43 ( V_23 ) ;
T_2 * V_100 ;
int V_101 , V_102 ;
int V_103 ;
int V_8 ;
F_12 ( V_23 , L_21 ,
V_99 -> V_21 , V_99 -> V_18 , V_99 -> V_104 ) ;
if ( V_99 -> V_21 == 0 )
return - V_12 ;
if ( V_99 -> V_104 != V_105 )
return - V_12 ;
V_101 = V_99 -> V_18 >> 1 ;
V_102 = ( V_99 -> V_18 + V_99 -> V_21 - 1 ) >> 1 ;
V_100 = F_57 ( sizeof( T_2 ) * ( V_102 - V_101 + 1 ) ,
V_106 ) ;
if ( ! V_100 )
return - V_107 ;
if ( V_99 -> V_18 & 1 ) {
V_8 = F_1 ( V_2 , V_108 , V_101 , 0 , 2 ,
& ( V_100 [ 0 ] ) ) ;
if ( V_8 < 0 ) {
F_9 ( V_23 , L_22 , V_101 ) ;
goto free;
}
}
if ( ( V_99 -> V_18 + V_99 -> V_21 ) & 1 ) {
V_8 = F_1 ( V_2 , V_108 , V_102 , 0 , 2 ,
& ( V_100 [ V_102 - V_101 ] ) ) ;
if ( V_8 < 0 ) {
F_9 ( V_23 , L_22 , V_102 ) ;
goto free;
}
}
memcpy ( ( T_1 * ) V_100 + ( V_99 -> V_18 & 1 ) , V_7 , V_99 -> V_21 ) ;
V_8 = F_3 ( V_2 , V_110 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_9 ( V_23 , L_23 ) ;
goto free;
}
F_41 ( 20 ) ;
for ( V_103 = V_101 ; V_103 <= V_102 ; V_103 ++ ) {
F_12 ( V_23 , L_24 ,
V_103 , V_100 [ V_103 - V_101 ] ) ;
V_8 = F_3 ( V_2 , V_111 , V_103 ,
V_100 [ V_103 - V_101 ] , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_9 ( V_23 , L_25 ,
V_103 ) ;
goto free;
}
F_41 ( 20 ) ;
}
V_8 = F_3 ( V_2 , V_112 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_9 ( V_23 , L_26 ) ;
goto free;
}
V_8 = 0 ;
free:
F_58 ( V_100 ) ;
return V_8 ;
}
void F_60 ( struct V_59 * V_23 , struct V_113 * V_114 )
{
F_61 ( V_23 , V_114 ) ;
F_62 ( V_114 -> V_115 , V_116 , sizeof( V_114 -> V_115 ) ) ;
F_62 ( V_114 -> V_117 , V_118 , sizeof( V_114 -> V_117 ) ) ;
}
int F_63 ( struct V_59 * V_23 , void * V_119 )
{
struct V_1 * V_2 = F_43 ( V_23 ) ;
struct V_60 * V_7 = (struct V_60 * ) & V_2 -> V_7 ;
struct V_120 * V_74 = V_119 ;
if ( F_64 ( V_23 ) )
return - V_121 ;
if ( ! F_65 ( V_74 -> V_122 ) )
return - V_123 ;
memcpy ( V_23 -> V_124 , V_74 -> V_122 , V_73 ) ;
memcpy ( V_7 -> V_125 , V_74 -> V_122 , V_73 ) ;
F_5 ( V_2 , V_126 , 0 , 0 , V_73 ,
V_7 -> V_125 ) ;
return 0 ;
}
