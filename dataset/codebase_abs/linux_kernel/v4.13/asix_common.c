int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 , int V_8 )
{
int V_9 ;
int (* F_2)( struct V_1 * , T_1 , T_1 , T_2 , T_2 , void * , T_2 );
F_3 ( ! V_2 ) ;
if ( ! V_8 )
F_2 = V_10 ;
else
F_2 = V_11 ;
V_9 = F_2 ( V_2 , V_3 , V_12 | V_13 | V_14 ,
V_4 , V_5 , V_7 , V_6 ) ;
if ( F_4 ( V_9 < 0 ) )
F_5 ( V_2 -> V_15 , L_1 ,
V_5 , V_9 ) ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 , int V_8 )
{
int V_9 ;
int (* F_2)( struct V_1 * , T_1 , T_1 , T_2 , T_2 , const void * , T_2 );
F_3 ( ! V_2 ) ;
if ( ! V_8 )
F_2 = V_16 ;
else
F_2 = V_17 ;
V_9 = F_2 ( V_2 , V_3 , V_18 | V_13 | V_14 ,
V_4 , V_5 , V_7 , V_6 ) ;
if ( F_4 ( V_9 < 0 ) )
F_5 ( V_2 -> V_15 , L_2 ,
V_5 , V_9 ) ;
return V_9 ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
F_8 ( V_2 , V_3 ,
V_18 | V_13 | V_14 ,
V_4 , V_5 , V_7 , V_6 ) ;
}
static void F_9 ( struct V_19 * V_20 )
{
if ( V_20 -> V_21 ) {
F_10 ( V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
}
V_20 -> V_22 = 0 ;
V_20 -> V_23 = false ;
V_20 -> V_24 = 0 ;
}
int F_11 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_19 * V_20 )
{
int V_27 = 0 ;
T_2 V_6 ;
if ( V_20 -> V_22 && ( V_20 -> V_22 + sizeof( V_28 ) <= V_26 -> V_29 ) ) {
V_27 = ( ( V_20 -> V_22 + 1 ) & 0xfffe ) ;
V_20 -> V_24 = F_12 ( V_26 -> V_7 + V_27 ) ;
V_27 = 0 ;
V_6 = ( T_2 ) ( V_20 -> V_24 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_20 -> V_24 >> 16 ) & 0x7ff ) ) {
F_13 ( V_2 -> V_15 , L_3 ,
V_20 -> V_22 ) ;
F_9 ( V_20 ) ;
}
}
while ( V_27 + sizeof( T_2 ) <= V_26 -> V_29 ) {
T_2 V_30 ;
if ( ! V_20 -> V_22 ) {
if ( V_26 -> V_29 - V_27 == sizeof( T_2 ) ) {
V_20 -> V_24 = F_14 (
V_26 -> V_7 + V_27 ) ;
V_20 -> V_23 = true ;
V_27 += sizeof( T_2 ) ;
break;
}
if ( V_20 -> V_23 == true ) {
V_20 -> V_24 |= ( F_14 (
V_26 -> V_7 + V_27 ) << 16 ) ;
V_20 -> V_23 = false ;
V_27 += sizeof( T_2 ) ;
} else {
V_20 -> V_24 = F_12 ( V_26 -> V_7 +
V_27 ) ;
V_27 += sizeof( V_28 ) ;
}
V_6 = ( T_2 ) ( V_20 -> V_24 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_20 -> V_24 >> 16 ) & 0x7ff ) ) {
F_13 ( V_2 -> V_15 , L_4 ,
V_20 -> V_24 , V_27 ) ;
F_9 ( V_20 ) ;
return 0 ;
}
if ( V_6 > V_2 -> V_15 -> V_31 + V_32 + V_33 ) {
F_15 ( V_2 -> V_15 , L_5 ,
V_6 ) ;
F_9 ( V_20 ) ;
return 0 ;
}
V_20 -> V_21 = F_16 ( V_2 -> V_15 , V_6 ) ;
V_20 -> V_22 = V_6 ;
}
if ( V_20 -> V_22 > V_26 -> V_29 - V_27 ) {
V_30 = V_26 -> V_29 - V_27 ;
V_20 -> V_22 -= V_30 ;
} else {
V_30 = V_20 -> V_22 ;
V_20 -> V_22 = 0 ;
}
if ( V_20 -> V_21 ) {
F_17 ( V_20 -> V_21 , V_26 -> V_7 + V_27 ,
V_30 ) ;
if ( ! V_20 -> V_22 ) {
F_18 ( V_2 , V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
}
}
V_27 += ( V_30 + 1 ) & 0xfffe ;
}
if ( V_26 -> V_29 != V_27 ) {
F_13 ( V_2 -> V_15 , L_6 ,
V_26 -> V_29 , V_27 ) ;
F_9 ( V_20 ) ;
return 0 ;
}
return 1 ;
}
int F_19 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_19 * V_20 = & V_35 -> V_37 ;
return F_11 ( V_2 , V_26 , V_20 ) ;
}
void F_20 ( struct V_34 * V_35 )
{
struct V_19 * V_20 ;
if ( ! V_35 )
return;
V_20 = & V_35 -> V_37 ;
if ( V_20 -> V_21 ) {
F_10 ( V_20 -> V_21 ) ;
V_20 -> V_21 = NULL ;
}
}
struct V_25 * F_21 ( struct V_1 * V_2 , struct V_25 * V_26 ,
T_3 V_38 )
{
int V_39 ;
int V_40 = F_22 ( V_26 ) ;
int V_41 = F_23 ( V_26 ) ;
V_28 V_42 ;
V_28 V_43 = 0xffff0000 ;
V_39 = ( ( V_26 -> V_29 + 4 ) & ( V_2 -> V_44 - 1 ) ) ? 0 : 4 ;
if ( ! F_24 ( V_26 ) &&
! ( V_39 && F_25 ( V_26 ) ) &&
V_40 + V_41 >= 4 + V_39 ) {
if ( V_40 < 4 ||
V_41 < V_39 ) {
V_26 -> V_7 = memmove ( V_26 -> V_45 + 4 , V_26 -> V_7 , V_26 -> V_29 ) ;
F_26 ( V_26 , V_26 -> V_29 ) ;
}
} else {
struct V_25 * V_46 ;
V_46 = F_27 ( V_26 , 4 , V_39 , V_38 ) ;
F_28 ( V_26 ) ;
V_26 = V_46 ;
if ( ! V_26 )
return NULL ;
}
V_42 = ( ( V_26 -> V_29 ^ 0x0000ffff ) << 16 ) + V_26 -> V_29 ;
F_29 ( V_26 , 4 ) ;
F_30 ( & V_42 ) ;
F_31 ( V_26 , & V_42 , sizeof( V_42 ) ) ;
if ( V_39 ) {
F_30 ( & V_43 ) ;
memcpy ( F_32 ( V_26 ) , & V_43 , sizeof( V_43 ) ) ;
F_33 ( V_26 , sizeof( V_43 ) ) ;
}
F_34 ( V_26 , 1 , 0 ) ;
return V_26 ;
}
int F_35 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
V_9 = F_6 ( V_2 , V_47 , 0x0000 , 0 , 0 , NULL , V_8 ) ;
if ( V_9 < 0 )
F_13 ( V_2 -> V_15 , L_7 ) ;
return V_9 ;
}
int F_36 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
V_9 = F_6 ( V_2 , V_48 , 0x0000 , 0 , 0 , NULL , V_8 ) ;
if ( V_9 < 0 )
F_13 ( V_2 -> V_15 , L_8 ) ;
return V_9 ;
}
int F_37 ( struct V_1 * V_2 , int V_49 )
{
int V_27 = ( V_49 ? 1 : 0 ) ;
T_1 V_50 [ 2 ] ;
int V_9 = F_1 ( V_2 , V_51 , 0 , 0 , 2 , V_50 , 0 ) ;
F_15 ( V_2 -> V_15 , L_9 ) ;
if ( V_9 < 0 ) {
F_13 ( V_2 -> V_15 , L_10 , V_9 ) ;
goto V_52;
}
F_15 ( V_2 -> V_15 , L_11 ,
* ( ( V_53 * ) V_50 ) ) ;
V_9 = V_50 [ V_27 ] ;
V_52:
return V_9 ;
}
int F_38 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , 1 ) ;
}
int F_39 ( struct V_1 * V_2 , T_1 V_38 , int V_8 )
{
int V_9 ;
V_9 = F_6 ( V_2 , V_54 , V_38 , 0 , 0 , NULL , V_8 ) ;
if ( V_9 < 0 )
F_13 ( V_2 -> V_15 , L_12 , V_9 ) ;
return V_9 ;
}
T_2 F_40 ( struct V_1 * V_2 , int V_8 )
{
V_53 V_55 ;
int V_9 = F_1 ( V_2 , V_56 , 0 , 0 , 2 , & V_55 , V_8 ) ;
if ( V_9 < 0 ) {
F_13 ( V_2 -> V_15 , L_13 , V_9 ) ;
goto V_52;
}
V_9 = F_41 ( V_55 ) ;
V_52:
return V_9 ;
}
int F_42 ( struct V_1 * V_2 , T_2 V_57 , int V_8 )
{
int V_9 ;
F_15 ( V_2 -> V_15 , L_14 , V_57 ) ;
V_9 = F_6 ( V_2 , V_58 , V_57 , 0 , 0 , NULL , V_8 ) ;
if ( V_9 < 0 )
F_13 ( V_2 -> V_15 , L_15 ,
V_57 , V_9 ) ;
return V_9 ;
}
T_2 F_43 ( struct V_1 * V_2 , int V_8 )
{
V_53 V_55 ;
int V_9 = F_1 ( V_2 , V_59 ,
0 , 0 , 2 , & V_55 , V_8 ) ;
if ( V_9 < 0 ) {
F_13 ( V_2 -> V_15 , L_16 ,
V_9 ) ;
return V_9 ;
}
return F_41 ( V_55 ) ;
}
int F_44 ( struct V_1 * V_2 , T_2 V_57 , int V_8 )
{
int V_9 ;
F_15 ( V_2 -> V_15 , L_17 , V_57 ) ;
V_9 = F_6 ( V_2 , V_60 ,
V_57 , 0 , 0 , NULL , V_8 ) ;
if ( V_9 < 0 )
F_13 ( V_2 -> V_15 , L_18 ,
V_57 , V_9 ) ;
return V_9 ;
}
int F_45 ( struct V_1 * V_2 , T_2 V_4 , int V_61 , int V_8 )
{
int V_9 ;
F_15 ( V_2 -> V_15 , L_19 , V_4 ) ;
V_9 = F_6 ( V_2 , V_62 , V_4 , 0 , 0 , NULL , V_8 ) ;
if ( V_9 < 0 )
F_13 ( V_2 -> V_15 , L_20 ,
V_4 , V_9 ) ;
if ( V_61 )
F_46 ( V_61 ) ;
return V_9 ;
}
void F_47 ( struct V_63 * V_15 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
struct V_64 * V_7 = (struct V_64 * ) & V_2 -> V_7 ;
T_2 V_65 = V_66 ;
if ( V_15 -> V_38 & V_67 ) {
V_65 |= V_68 ;
} else if ( V_15 -> V_38 & V_69 ||
F_49 ( V_15 ) > V_70 ) {
V_65 |= V_71 ;
} else if ( F_50 ( V_15 ) ) {
} else {
struct V_72 * V_73 ;
V_28 V_74 ;
memset ( V_7 -> V_75 , 0 , V_76 ) ;
F_51 (ha, net) {
V_74 = F_52 ( V_77 , V_73 -> V_78 ) >> 26 ;
V_7 -> V_75 [ V_74 >> 3 ] |=
1 << ( V_74 & 7 ) ;
}
F_7 ( V_2 , V_79 , 0 , 0 ,
V_76 , V_7 -> V_75 ) ;
V_65 |= V_80 ;
}
F_7 ( V_2 , V_58 , V_65 , 0 , 0 , NULL ) ;
}
int F_53 ( struct V_63 * V_81 , int V_82 , int V_83 )
{
struct V_1 * V_2 = F_48 ( V_81 ) ;
V_53 V_84 ;
T_1 V_85 ;
int V_86 = 0 ;
int V_9 ;
F_54 ( & V_2 -> V_87 ) ;
do {
V_9 = F_35 ( V_2 , 0 ) ;
if ( V_9 == - V_88 || V_9 == - V_89 )
break;
F_55 ( 1000 , 1100 ) ;
V_9 = F_1 ( V_2 , V_90 ,
0 , 0 , 1 , & V_85 , 0 ) ;
} while ( ! ( V_85 & V_91 ) && ( V_86 ++ < 30 ) && ( V_9 != - V_88 ) );
if ( V_9 == - V_88 || V_9 == - V_89 ) {
F_56 ( & V_2 -> V_87 ) ;
return V_9 ;
}
F_1 ( V_2 , V_92 , V_82 ,
( V_93 ) V_83 , 2 , & V_84 , 0 ) ;
F_36 ( V_2 , 0 ) ;
F_56 ( & V_2 -> V_87 ) ;
F_15 ( V_2 -> V_15 , L_21 ,
V_82 , V_83 , F_41 ( V_84 ) ) ;
return F_41 ( V_84 ) ;
}
void F_57 ( struct V_63 * V_81 , int V_82 , int V_83 , int V_94 )
{
struct V_1 * V_2 = F_48 ( V_81 ) ;
V_53 V_84 = F_58 ( V_94 ) ;
T_1 V_85 ;
int V_86 = 0 ;
int V_9 ;
F_15 ( V_2 -> V_15 , L_22 ,
V_82 , V_83 , V_94 ) ;
F_54 ( & V_2 -> V_87 ) ;
do {
V_9 = F_35 ( V_2 , 0 ) ;
if ( V_9 == - V_88 )
break;
F_55 ( 1000 , 1100 ) ;
V_9 = F_1 ( V_2 , V_90 ,
0 , 0 , 1 , & V_85 , 0 ) ;
} while ( ! ( V_85 & V_91 ) && ( V_86 ++ < 30 ) && ( V_9 != - V_88 ) );
if ( V_9 == - V_88 ) {
F_56 ( & V_2 -> V_87 ) ;
return;
}
F_6 ( V_2 , V_95 , V_82 ,
( V_93 ) V_83 , 2 , & V_84 , 0 ) ;
F_36 ( V_2 , 0 ) ;
F_56 ( & V_2 -> V_87 ) ;
}
int F_59 ( struct V_63 * V_81 , int V_82 , int V_83 )
{
struct V_1 * V_2 = F_48 ( V_81 ) ;
V_53 V_84 ;
T_1 V_85 ;
int V_86 = 0 ;
int V_9 ;
F_54 ( & V_2 -> V_87 ) ;
do {
V_9 = F_35 ( V_2 , 1 ) ;
if ( V_9 == - V_88 || V_9 == - V_89 )
break;
F_55 ( 1000 , 1100 ) ;
V_9 = F_1 ( V_2 , V_90 ,
0 , 0 , 1 , & V_85 , 1 ) ;
} while ( ! ( V_85 & V_91 ) && ( V_86 ++ < 30 ) && ( V_9 != - V_88 ) );
if ( V_9 == - V_88 || V_9 == - V_89 ) {
F_56 ( & V_2 -> V_87 ) ;
return V_9 ;
}
F_1 ( V_2 , V_92 , V_82 ,
( V_93 ) V_83 , 2 , & V_84 , 1 ) ;
F_36 ( V_2 , 1 ) ;
F_56 ( & V_2 -> V_87 ) ;
F_15 ( V_2 -> V_15 , L_23 ,
V_82 , V_83 , F_41 ( V_84 ) ) ;
return F_41 ( V_84 ) ;
}
void
F_60 ( struct V_63 * V_81 , int V_82 , int V_83 , int V_94 )
{
struct V_1 * V_2 = F_48 ( V_81 ) ;
V_53 V_84 = F_58 ( V_94 ) ;
T_1 V_85 ;
int V_86 = 0 ;
int V_9 ;
F_15 ( V_2 -> V_15 , L_22 ,
V_82 , V_83 , V_94 ) ;
F_54 ( & V_2 -> V_87 ) ;
do {
V_9 = F_35 ( V_2 , 1 ) ;
if ( V_9 == - V_88 )
break;
F_55 ( 1000 , 1100 ) ;
V_9 = F_1 ( V_2 , V_90 ,
0 , 0 , 1 , & V_85 , 1 ) ;
} while ( ! ( V_85 & V_91 ) && ( V_86 ++ < 30 ) && ( V_9 != - V_88 ) );
if ( V_9 == - V_88 ) {
F_56 ( & V_2 -> V_87 ) ;
return;
}
F_6 ( V_2 , V_95 , V_82 ,
( V_93 ) V_83 , 2 , & V_84 , 1 ) ;
F_36 ( V_2 , 1 ) ;
F_56 ( & V_2 -> V_87 ) ;
}
void F_61 ( struct V_63 * V_15 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
T_1 V_98 ;
if ( F_1 ( V_2 , V_99 ,
0 , 0 , 1 , & V_98 , 0 ) < 0 ) {
V_97 -> V_100 = 0 ;
V_97 -> V_101 = 0 ;
return;
}
V_97 -> V_100 = V_102 | V_103 ;
V_97 -> V_101 = 0 ;
if ( V_98 & V_104 )
V_97 -> V_101 |= V_102 ;
if ( V_98 & V_105 )
V_97 -> V_101 |= V_103 ;
}
int F_62 ( struct V_63 * V_15 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
T_1 V_98 = 0 ;
if ( V_97 -> V_101 & V_102 )
V_98 |= V_104 ;
if ( V_97 -> V_101 & V_103 )
V_98 |= V_105 ;
if ( F_6 ( V_2 , V_106 ,
V_98 , 0 , 0 , NULL , 0 ) < 0 )
return - V_107 ;
return 0 ;
}
int F_63 ( struct V_63 * V_15 )
{
return V_108 ;
}
int F_64 ( struct V_63 * V_15 , struct V_109 * V_110 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
T_2 * V_111 ;
int V_112 , V_113 ;
int V_86 ;
if ( V_110 -> V_29 == 0 )
return - V_107 ;
V_110 -> V_114 = V_115 ;
V_112 = V_110 -> V_27 >> 1 ;
V_113 = ( V_110 -> V_27 + V_110 -> V_29 - 1 ) >> 1 ;
V_111 = F_65 ( sizeof( T_2 ) * ( V_113 - V_112 + 1 ) ,
V_116 ) ;
if ( ! V_111 )
return - V_117 ;
for ( V_86 = V_112 ; V_86 <= V_113 ; V_86 ++ ) {
if ( F_1 ( V_2 , V_118 , V_86 , 0 , 2 ,
& V_111 [ V_86 - V_112 ] , 0 ) < 0 ) {
F_66 ( V_111 ) ;
return - V_119 ;
}
}
memcpy ( V_7 , ( T_1 * ) V_111 + ( V_110 -> V_27 & 1 ) , V_110 -> V_29 ) ;
F_66 ( V_111 ) ;
return 0 ;
}
int F_67 ( struct V_63 * V_15 , struct V_109 * V_110 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
T_2 * V_111 ;
int V_112 , V_113 ;
int V_86 ;
int V_9 ;
F_15 ( V_15 , L_24 ,
V_110 -> V_29 , V_110 -> V_27 , V_110 -> V_114 ) ;
if ( V_110 -> V_29 == 0 )
return - V_107 ;
if ( V_110 -> V_114 != V_115 )
return - V_107 ;
V_112 = V_110 -> V_27 >> 1 ;
V_113 = ( V_110 -> V_27 + V_110 -> V_29 - 1 ) >> 1 ;
V_111 = F_65 ( sizeof( T_2 ) * ( V_113 - V_112 + 1 ) ,
V_116 ) ;
if ( ! V_111 )
return - V_117 ;
if ( V_110 -> V_27 & 1 ) {
V_9 = F_1 ( V_2 , V_118 , V_112 , 0 , 2 ,
& V_111 [ 0 ] , 0 ) ;
if ( V_9 < 0 ) {
F_13 ( V_15 , L_25 , V_112 ) ;
goto free;
}
}
if ( ( V_110 -> V_27 + V_110 -> V_29 ) & 1 ) {
V_9 = F_1 ( V_2 , V_118 , V_113 , 0 , 2 ,
& V_111 [ V_113 - V_112 ] , 0 ) ;
if ( V_9 < 0 ) {
F_13 ( V_15 , L_25 , V_113 ) ;
goto free;
}
}
memcpy ( ( T_1 * ) V_111 + ( V_110 -> V_27 & 1 ) , V_7 , V_110 -> V_29 ) ;
V_9 = F_6 ( V_2 , V_120 , 0x0000 , 0 , 0 , NULL , 0 ) ;
if ( V_9 < 0 ) {
F_13 ( V_15 , L_26 ) ;
goto free;
}
F_46 ( 20 ) ;
for ( V_86 = V_112 ; V_86 <= V_113 ; V_86 ++ ) {
F_15 ( V_15 , L_27 ,
V_86 , V_111 [ V_86 - V_112 ] ) ;
V_9 = F_6 ( V_2 , V_121 , V_86 ,
V_111 [ V_86 - V_112 ] , 0 , NULL , 0 ) ;
if ( V_9 < 0 ) {
F_13 ( V_15 , L_28 ,
V_86 ) ;
goto free;
}
F_46 ( 20 ) ;
}
V_9 = F_6 ( V_2 , V_122 , 0x0000 , 0 , 0 , NULL , 0 ) ;
if ( V_9 < 0 ) {
F_13 ( V_15 , L_29 ) ;
goto free;
}
V_9 = 0 ;
free:
F_66 ( V_111 ) ;
return V_9 ;
}
void F_68 ( struct V_63 * V_15 , struct V_123 * V_124 )
{
F_69 ( V_15 , V_124 ) ;
F_70 ( V_124 -> V_125 , V_126 , sizeof( V_124 -> V_125 ) ) ;
F_70 ( V_124 -> V_127 , V_128 , sizeof( V_124 -> V_127 ) ) ;
}
int F_71 ( struct V_63 * V_15 , void * V_129 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
struct V_64 * V_7 = (struct V_64 * ) & V_2 -> V_7 ;
struct V_130 * V_78 = V_129 ;
if ( F_72 ( V_15 ) )
return - V_131 ;
if ( ! F_73 ( V_78 -> V_132 ) )
return - V_133 ;
memcpy ( V_15 -> V_134 , V_78 -> V_132 , V_77 ) ;
memcpy ( V_7 -> V_135 , V_78 -> V_132 , V_77 ) ;
F_7 ( V_2 , V_136 , 0 , 0 , V_77 ,
V_7 -> V_135 ) ;
return 0 ;
}
