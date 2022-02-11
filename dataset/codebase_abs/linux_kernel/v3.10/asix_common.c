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
while ( V_18 + sizeof( T_2 ) <= V_15 -> V_19 ) {
T_2 V_20 = 0 ;
unsigned char * V_7 ;
if ( ! V_17 -> V_6 ) {
if ( ( V_15 -> V_19 - V_18 == sizeof( T_2 ) ) ||
V_17 -> V_21 ) {
if( ! V_17 -> V_21 ) {
V_17 -> V_22 = F_8 (
V_15 -> V_7 + V_18 ) ;
V_17 -> V_21 = true ;
V_18 += sizeof( T_2 ) ;
break;
} else {
V_17 -> V_22 |= ( F_8 (
V_15 -> V_7 + V_18 )
<< 16 ) ;
V_17 -> V_21 = false ;
V_18 += sizeof( T_2 ) ;
}
} else {
V_17 -> V_22 = F_9 ( V_15 -> V_7 +
V_18 ) ;
V_18 += sizeof( V_23 ) ;
}
V_17 -> V_6 = ( T_2 ) ( V_17 -> V_22 & 0x7ff ) ;
if ( V_17 -> V_6 != ( ( ~ V_17 -> V_22 >> 16 ) & 0x7ff ) ) {
F_10 ( V_2 -> V_24 , L_1 ,
V_17 -> V_22 , V_18 ) ;
V_17 -> V_6 = 0 ;
return 0 ;
}
V_17 -> V_25 = F_11 ( V_2 -> V_24 ,
V_17 -> V_6 ) ;
if ( ! V_17 -> V_25 )
return 0 ;
}
if ( V_17 -> V_6 > V_2 -> V_24 -> V_26 + V_27 + V_28 ) {
F_10 ( V_2 -> V_24 , L_2 ,
V_17 -> V_6 ) ;
F_12 ( V_17 -> V_25 ) ;
V_17 -> V_25 = NULL ;
V_17 -> V_6 = 0U ;
return 0 ;
}
if ( V_17 -> V_6 > V_15 -> V_19 - V_18 ) {
V_20 = V_17 -> V_6 - ( V_15 -> V_19 - V_18 ) ;
V_17 -> V_6 = V_15 -> V_19 - V_18 ;
}
V_7 = F_13 ( V_17 -> V_25 , V_17 -> V_6 ) ;
memcpy ( V_7 , V_15 -> V_7 + V_18 , V_17 -> V_6 ) ;
if ( ! V_20 )
F_14 ( V_2 , V_17 -> V_25 ) ;
V_18 += ( V_17 -> V_6 + 1 ) & 0xfffe ;
V_17 -> V_6 = V_20 ;
}
if ( V_15 -> V_19 != V_18 ) {
F_10 ( V_2 -> V_24 , L_3 ,
V_15 -> V_19 , V_18 ) ;
return 0 ;
}
return 1 ;
}
int F_15 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
struct V_16 * V_17 = & V_30 -> V_32 ;
return F_7 ( V_2 , V_15 , V_17 ) ;
}
struct V_14 * F_16 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_3 V_33 )
{
int V_34 ;
int V_35 = F_17 ( V_15 ) ;
int V_36 = F_18 ( V_15 ) ;
V_23 V_37 ;
V_23 V_38 = 0xffff0000 ;
V_34 = ( ( V_15 -> V_19 + 4 ) & ( V_2 -> V_39 - 1 ) ) ? 0 : 4 ;
if ( ! F_19 ( V_15 ) &&
! ( V_34 && F_20 ( V_15 ) ) &&
V_35 + V_36 >= 4 + V_34 ) {
if ( V_35 < 4 ||
V_36 < V_34 ) {
V_15 -> V_7 = memmove ( V_15 -> V_40 + 4 , V_15 -> V_7 , V_15 -> V_19 ) ;
F_21 ( V_15 , V_15 -> V_19 ) ;
}
} else {
struct V_14 * V_41 ;
V_41 = F_22 ( V_15 , 4 , V_34 , V_33 ) ;
F_23 ( V_15 ) ;
V_15 = V_41 ;
if ( ! V_15 )
return NULL ;
}
V_37 = ( ( V_15 -> V_19 ^ 0x0000ffff ) << 16 ) + V_15 -> V_19 ;
F_24 ( V_15 , 4 ) ;
F_25 ( & V_37 ) ;
F_26 ( V_15 , & V_37 , sizeof( V_37 ) ) ;
if ( V_34 ) {
F_25 ( & V_38 ) ;
memcpy ( F_27 ( V_15 ) , & V_38 , sizeof( V_38 ) ) ;
F_13 ( V_15 , sizeof( V_38 ) ) ;
}
return V_15 ;
}
int F_28 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_42 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_10 ( V_2 -> V_24 , L_4 ) ;
return V_8 ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_43 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_10 ( V_2 -> V_24 , L_5 ) ;
return V_8 ;
}
int F_30 ( struct V_1 * V_2 , int V_44 )
{
int V_18 = ( V_44 ? 1 : 0 ) ;
T_1 V_45 [ 2 ] ;
int V_8 = F_1 ( V_2 , V_46 , 0 , 0 , 2 , V_45 ) ;
F_31 ( V_2 -> V_24 , L_6 ) ;
if ( V_8 < 0 ) {
F_10 ( V_2 -> V_24 , L_7 , V_8 ) ;
goto V_47;
}
F_31 ( V_2 -> V_24 , L_8 ,
* ( ( V_48 * ) V_45 ) ) ;
V_8 = V_45 [ V_18 ] ;
V_47:
return V_8 ;
}
int F_32 ( struct V_1 * V_2 )
{
return F_30 ( V_2 , 1 ) ;
}
int F_33 ( struct V_1 * V_2 , T_1 V_33 )
{
int V_8 ;
V_8 = F_3 ( V_2 , V_49 , V_33 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_10 ( V_2 -> V_24 , L_9 , V_8 ) ;
return V_8 ;
}
T_2 F_34 ( struct V_1 * V_2 )
{
V_48 V_50 ;
int V_8 = F_1 ( V_2 , V_51 , 0 , 0 , 2 , & V_50 ) ;
if ( V_8 < 0 ) {
F_10 ( V_2 -> V_24 , L_10 , V_8 ) ;
goto V_47;
}
V_8 = F_35 ( V_50 ) ;
V_47:
return V_8 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_52 )
{
int V_8 ;
F_31 ( V_2 -> V_24 , L_11 , V_52 ) ;
V_8 = F_3 ( V_2 , V_53 , V_52 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_10 ( V_2 -> V_24 , L_12 ,
V_52 , V_8 ) ;
return V_8 ;
}
T_2 F_37 ( struct V_1 * V_2 )
{
V_48 V_50 ;
int V_8 = F_1 ( V_2 , V_54 , 0 , 0 , 2 , & V_50 ) ;
if ( V_8 < 0 ) {
F_10 ( V_2 -> V_24 , L_13 ,
V_8 ) ;
return V_8 ;
}
return F_35 ( V_50 ) ;
}
int F_38 ( struct V_1 * V_2 , T_2 V_52 )
{
int V_8 ;
F_31 ( V_2 -> V_24 , L_14 , V_52 ) ;
V_8 = F_3 ( V_2 , V_55 , V_52 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_10 ( V_2 -> V_24 , L_15 ,
V_52 , V_8 ) ;
return V_8 ;
}
int F_39 ( struct V_1 * V_2 , T_2 V_4 , int V_56 )
{
int V_8 ;
F_31 ( V_2 -> V_24 , L_16 , V_4 ) ;
V_8 = F_3 ( V_2 , V_57 , V_4 , 0 , 0 , NULL ) ;
if ( V_8 < 0 )
F_10 ( V_2 -> V_24 , L_17 ,
V_4 , V_8 ) ;
if ( V_56 )
F_40 ( V_56 ) ;
return V_8 ;
}
void F_41 ( struct V_58 * V_24 )
{
struct V_1 * V_2 = F_42 ( V_24 ) ;
struct V_59 * V_7 = (struct V_59 * ) & V_2 -> V_7 ;
T_2 V_60 = V_61 ;
if ( V_24 -> V_33 & V_62 ) {
V_60 |= V_63 ;
} else if ( V_24 -> V_33 & V_64 ||
F_43 ( V_24 ) > V_65 ) {
V_60 |= V_66 ;
} else if ( F_44 ( V_24 ) ) {
} else {
struct V_67 * V_68 ;
V_23 V_69 ;
memset ( V_7 -> V_70 , 0 , V_71 ) ;
F_45 (ha, net) {
V_69 = F_46 ( V_72 , V_68 -> V_73 ) >> 26 ;
V_7 -> V_70 [ V_69 >> 3 ] |=
1 << ( V_69 & 7 ) ;
}
F_5 ( V_2 , V_74 , 0 , 0 ,
V_71 , V_7 -> V_70 ) ;
V_60 |= V_75 ;
}
F_5 ( V_2 , V_53 , V_60 , 0 , 0 , NULL ) ;
}
int F_47 ( struct V_58 * V_76 , int V_77 , int V_78 )
{
struct V_1 * V_2 = F_42 ( V_76 ) ;
V_48 V_79 ;
F_48 ( & V_2 -> V_80 ) ;
F_28 ( V_2 ) ;
F_1 ( V_2 , V_81 , V_77 ,
( V_82 ) V_78 , 2 , & V_79 ) ;
F_29 ( V_2 ) ;
F_49 ( & V_2 -> V_80 ) ;
F_31 ( V_2 -> V_24 , L_18 ,
V_77 , V_78 , F_35 ( V_79 ) ) ;
return F_35 ( V_79 ) ;
}
void F_50 ( struct V_58 * V_76 , int V_77 , int V_78 , int V_83 )
{
struct V_1 * V_2 = F_42 ( V_76 ) ;
V_48 V_79 = F_51 ( V_83 ) ;
F_31 ( V_2 -> V_24 , L_19 ,
V_77 , V_78 , V_83 ) ;
F_48 ( & V_2 -> V_80 ) ;
F_28 ( V_2 ) ;
F_3 ( V_2 , V_84 , V_77 , ( V_82 ) V_78 , 2 , & V_79 ) ;
F_29 ( V_2 ) ;
F_49 ( & V_2 -> V_80 ) ;
}
void F_52 ( struct V_58 * V_24 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_42 ( V_24 ) ;
T_1 V_87 ;
if ( F_1 ( V_2 , V_88 , 0 , 0 , 1 , & V_87 ) < 0 ) {
V_86 -> V_89 = 0 ;
V_86 -> V_90 = 0 ;
return;
}
V_86 -> V_89 = V_91 | V_92 ;
V_86 -> V_90 = 0 ;
if ( V_87 & V_93 )
V_86 -> V_90 |= V_91 ;
if ( V_87 & V_94 )
V_86 -> V_90 |= V_92 ;
}
int F_53 ( struct V_58 * V_24 , struct V_85 * V_86 )
{
struct V_1 * V_2 = F_42 ( V_24 ) ;
T_1 V_87 = 0 ;
if ( V_86 -> V_90 & V_91 )
V_87 |= V_93 ;
if ( V_86 -> V_90 & V_92 )
V_87 |= V_94 ;
if ( F_3 ( V_2 , V_95 ,
V_87 , 0 , 0 , NULL ) < 0 )
return - V_12 ;
return 0 ;
}
int F_54 ( struct V_58 * V_24 )
{
return V_96 ;
}
int F_55 ( struct V_58 * V_24 , struct V_97 * V_98 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_24 ) ;
T_2 * V_99 ;
int V_100 , V_101 ;
int V_102 ;
if ( V_98 -> V_19 == 0 )
return - V_12 ;
V_98 -> V_103 = V_104 ;
V_100 = V_98 -> V_18 >> 1 ;
V_101 = ( V_98 -> V_18 + V_98 -> V_19 - 1 ) >> 1 ;
V_99 = F_56 ( sizeof( T_2 ) * ( V_101 - V_100 + 1 ) ,
V_105 ) ;
if ( ! V_99 )
return - V_106 ;
for ( V_102 = V_100 ; V_102 <= V_101 ; V_102 ++ ) {
if ( F_1 ( V_2 , V_107 , V_102 , 0 , 2 ,
& ( V_99 [ V_102 - V_100 ] ) ) < 0 ) {
F_57 ( V_99 ) ;
return - V_108 ;
}
}
memcpy ( V_7 , ( T_1 * ) V_99 + ( V_98 -> V_18 & 1 ) , V_98 -> V_19 ) ;
F_57 ( V_99 ) ;
return 0 ;
}
int F_58 ( struct V_58 * V_24 , struct V_97 * V_98 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_24 ) ;
T_2 * V_99 ;
int V_100 , V_101 ;
int V_102 ;
int V_8 ;
F_31 ( V_24 , L_20 ,
V_98 -> V_19 , V_98 -> V_18 , V_98 -> V_103 ) ;
if ( V_98 -> V_19 == 0 )
return - V_12 ;
if ( V_98 -> V_103 != V_104 )
return - V_12 ;
V_100 = V_98 -> V_18 >> 1 ;
V_101 = ( V_98 -> V_18 + V_98 -> V_19 - 1 ) >> 1 ;
V_99 = F_56 ( sizeof( T_2 ) * ( V_101 - V_100 + 1 ) ,
V_105 ) ;
if ( ! V_99 )
return - V_106 ;
if ( V_98 -> V_18 & 1 ) {
V_8 = F_1 ( V_2 , V_107 , V_100 , 0 , 2 ,
& ( V_99 [ 0 ] ) ) ;
if ( V_8 < 0 ) {
F_10 ( V_24 , L_21 , V_100 ) ;
goto free;
}
}
if ( ( V_98 -> V_18 + V_98 -> V_19 ) & 1 ) {
V_8 = F_1 ( V_2 , V_107 , V_101 , 0 , 2 ,
& ( V_99 [ V_101 - V_100 ] ) ) ;
if ( V_8 < 0 ) {
F_10 ( V_24 , L_21 , V_101 ) ;
goto free;
}
}
memcpy ( ( T_1 * ) V_99 + ( V_98 -> V_18 & 1 ) , V_7 , V_98 -> V_19 ) ;
V_8 = F_3 ( V_2 , V_109 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_10 ( V_24 , L_22 ) ;
goto free;
}
F_40 ( 20 ) ;
for ( V_102 = V_100 ; V_102 <= V_101 ; V_102 ++ ) {
F_31 ( V_24 , L_23 ,
V_102 , V_99 [ V_102 - V_100 ] ) ;
V_8 = F_3 ( V_2 , V_110 , V_102 ,
V_99 [ V_102 - V_100 ] , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_10 ( V_24 , L_24 ,
V_102 ) ;
goto free;
}
F_40 ( 20 ) ;
}
V_8 = F_3 ( V_2 , V_111 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_8 < 0 ) {
F_10 ( V_24 , L_25 ) ;
goto free;
}
V_8 = 0 ;
free:
F_57 ( V_99 ) ;
return V_8 ;
}
void F_59 ( struct V_58 * V_24 , struct V_112 * V_113 )
{
F_60 ( V_24 , V_113 ) ;
F_61 ( V_113 -> V_114 , V_115 , sizeof( V_113 -> V_114 ) ) ;
F_61 ( V_113 -> V_116 , V_117 , sizeof( V_113 -> V_116 ) ) ;
V_113 -> V_118 = V_96 ;
}
int F_62 ( struct V_58 * V_24 , void * V_119 )
{
struct V_1 * V_2 = F_42 ( V_24 ) ;
struct V_59 * V_7 = (struct V_59 * ) & V_2 -> V_7 ;
struct V_120 * V_73 = V_119 ;
if ( F_63 ( V_24 ) )
return - V_121 ;
if ( ! F_64 ( V_73 -> V_122 ) )
return - V_123 ;
memcpy ( V_24 -> V_124 , V_73 -> V_122 , V_72 ) ;
memcpy ( V_7 -> V_125 , V_73 -> V_122 , V_72 ) ;
F_5 ( V_2 , V_126 , 0 , 0 , V_72 ,
V_7 -> V_125 ) ;
return 0 ;
}
