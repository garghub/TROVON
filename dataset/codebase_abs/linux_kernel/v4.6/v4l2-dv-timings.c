bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 ,
void * V_6 )
{
const struct V_7 * V_8 = & V_2 -> V_8 ;
const struct V_9 * V_10 = & V_4 -> V_8 ;
T_2 V_11 = V_10 -> V_12 ;
if ( V_2 -> type != V_13 )
return false ;
if ( V_2 -> type != V_4 -> type ||
V_8 -> V_14 < V_10 -> V_15 ||
V_8 -> V_14 > V_10 -> V_16 ||
V_8 -> V_17 < V_10 -> V_18 ||
V_8 -> V_17 > V_10 -> V_19 ||
V_8 -> V_20 < V_10 -> V_21 ||
V_8 -> V_20 > V_10 -> V_22 ||
( ! ( V_11 & V_23 ) &&
V_10 -> V_24 && V_8 -> V_24 &&
! ( V_8 -> V_24 & V_10 -> V_24 ) ) ||
( V_8 -> V_25 && ! ( V_11 & V_26 ) ) ||
( ! V_8 -> V_25 && ! ( V_11 & V_27 ) ) )
return false ;
return V_5 == NULL || V_5 ( V_2 , V_6 ) ;
}
int F_2 ( struct V_28 * V_2 ,
const struct V_3 * V_10 ,
T_1 V_5 ,
void * V_6 )
{
T_2 V_29 , V_30 ;
memset ( V_2 -> V_31 , 0 , sizeof( V_2 -> V_31 ) ) ;
for ( V_29 = V_30 = 0 ; V_32 [ V_29 ] . V_8 . V_17 ; V_29 ++ ) {
if ( F_1 ( V_32 + V_29 , V_10 ,
V_5 , V_6 ) &&
V_30 ++ == V_2 -> V_33 ) {
V_2 -> V_34 = V_32 [ V_29 ] ;
return 0 ;
}
}
return - V_35 ;
}
bool F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_10 ,
unsigned V_36 ,
T_1 V_5 ,
void * V_6 )
{
int V_29 ;
if ( ! F_1 ( V_2 , V_10 , V_5 , V_6 ) )
return false ;
for ( V_29 = 0 ; V_29 < V_32 [ V_29 ] . V_8 . V_17 ; V_29 ++ ) {
if ( F_1 ( V_32 + V_29 , V_10 ,
V_5 , V_6 ) &&
F_4 ( V_2 , V_32 + V_29 ,
V_36 , false ) ) {
T_2 V_37 = V_2 -> V_8 . V_37 & V_38 ;
* V_2 = V_32 [ V_29 ] ;
if ( F_5 ( & V_2 -> V_8 ) )
V_2 -> V_8 . V_37 |= V_37 ;
return true ;
}
}
return false ;
}
bool F_4 ( const struct V_1 * V_39 ,
const struct V_1 * V_40 ,
unsigned V_36 , bool V_41 )
{
if ( V_39 -> type != V_40 -> type || V_39 -> type != V_13 )
return false ;
if ( V_39 -> V_8 . V_17 == V_40 -> V_8 . V_17 &&
V_39 -> V_8 . V_14 == V_40 -> V_8 . V_14 &&
V_39 -> V_8 . V_25 == V_40 -> V_8 . V_25 &&
V_39 -> V_8 . V_42 == V_40 -> V_8 . V_42 &&
V_39 -> V_8 . V_20 >= V_40 -> V_8 . V_20 - V_36 &&
V_39 -> V_8 . V_20 <= V_40 -> V_8 . V_20 + V_36 &&
V_39 -> V_8 . V_43 == V_40 -> V_8 . V_43 &&
V_39 -> V_8 . V_44 == V_40 -> V_8 . V_44 &&
V_39 -> V_8 . V_45 == V_40 -> V_8 . V_45 &&
V_39 -> V_8 . V_46 == V_40 -> V_8 . V_46 &&
V_39 -> V_8 . V_47 == V_40 -> V_8 . V_47 &&
V_39 -> V_8 . V_48 == V_40 -> V_8 . V_48 &&
( ! V_41 ||
( V_39 -> V_8 . V_37 & V_38 ) ==
( V_40 -> V_8 . V_37 & V_38 ) ) &&
( ! V_39 -> V_8 . V_25 ||
( V_39 -> V_8 . V_49 == V_40 -> V_8 . V_49 &&
V_39 -> V_8 . V_50 == V_40 -> V_8 . V_50 &&
V_39 -> V_8 . V_51 == V_40 -> V_8 . V_51 ) ) )
return true ;
return false ;
}
void F_6 ( const char * V_52 , const char * V_53 ,
const struct V_1 * V_2 , bool V_54 )
{
const struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_55 , V_56 ;
T_2 V_57 ;
if ( V_2 -> type != V_13 )
return;
V_55 = F_7 ( V_8 ) ;
V_56 = F_8 ( V_8 ) ;
if ( V_8 -> V_25 )
V_56 /= 2 ;
V_57 = ( V_55 * V_56 ) > 0 ? F_9 ( ( 100 * ( V_58 ) V_8 -> V_20 ) ,
( V_55 * V_56 ) ) : 0 ;
if ( V_53 == NULL )
V_53 = L_1 ;
F_10 ( L_2 , V_52 , V_53 ,
V_8 -> V_17 , V_8 -> V_14 , V_8 -> V_25 ? L_3 : L_4 ,
V_57 / 100 , V_57 % 100 , V_55 , V_56 ) ;
if ( ! V_54 )
return;
F_10 ( L_5 ,
V_52 , V_8 -> V_43 ,
( V_8 -> V_42 & V_59 ) ? L_6 : L_7 ,
V_8 -> V_44 , V_8 -> V_45 ) ;
F_10 ( L_8 ,
V_52 , V_8 -> V_46 ,
( V_8 -> V_42 & V_60 ) ? L_6 : L_7 ,
V_8 -> V_47 , V_8 -> V_48 ) ;
if ( V_8 -> V_25 )
F_10 ( L_9 ,
V_52 , V_8 -> V_49 ,
( V_8 -> V_42 & V_60 ) ? L_6 : L_7 ,
V_8 -> V_50 , V_8 -> V_51 ) ;
F_10 ( L_10 , V_52 , V_8 -> V_20 ) ;
F_10 ( L_11 , V_52 , V_8 -> V_37 ,
( V_8 -> V_37 & V_61 ) ?
L_12 : L_1 ,
( ( V_8 -> V_37 & V_61 ) &&
V_8 -> V_47 == 8 ) ? L_13 : L_1 ,
( V_8 -> V_37 & V_62 ) ?
L_14 : L_1 ,
( V_8 -> V_37 & V_38 ) ?
L_15 : L_1 ,
( V_8 -> V_37 & V_63 ) ?
L_16 : L_1 ,
( V_8 -> V_37 & V_64 ) ?
L_17 : L_1 ) ;
F_10 ( L_18 , V_52 , V_8 -> V_24 ,
( V_8 -> V_24 & V_65 ) ? L_19 : L_1 ,
( V_8 -> V_24 & V_66 ) ? L_20 : L_1 ,
( V_8 -> V_24 & V_67 ) ? L_21 : L_1 ,
( V_8 -> V_24 & V_68 ) ? L_22 : L_1 ) ;
}
bool F_11 ( unsigned V_69 ,
unsigned V_70 ,
unsigned V_47 ,
unsigned V_71 ,
T_2 V_42 ,
bool V_25 ,
struct V_1 * V_72 )
{
int V_73 , V_74 , V_75 , V_76 , V_44 ;
int V_77 , V_78 , V_79 ;
bool V_80 ;
bool V_81 = false ;
unsigned V_82 ;
if ( V_47 < 4 || V_47 > 8 )
return false ;
if ( V_42 == V_60 )
V_80 = false ;
else if ( V_42 == V_59 )
V_80 = true ;
else
return false ;
if ( V_80 && V_47 == 8 )
V_81 = true ;
if ( V_81 && V_71 == 0 )
return false ;
if ( ! V_81 && V_47 > 7 )
return false ;
if ( V_70 == 0 )
return false ;
if ( V_80 ) {
if ( V_81 ) {
V_74 = V_83 ;
V_73 = ( V_84 * V_70 ) / 1000000 + 1 ;
V_73 -= V_47 + V_74 ;
if ( V_73 < V_85 )
V_73 = V_85 ;
} else {
V_73 = V_86 ;
V_74 = ( V_84 * V_70 ) / 1000000 + 1 ;
V_74 -= V_47 + V_73 ;
if ( V_74 < V_87 )
V_74 = V_87 ;
}
} else {
V_73 = V_88 ;
V_74 = ( V_89 * V_70 ) / 1000000 + 1 - V_47 ;
if ( V_74 < V_90 )
V_74 = V_90 ;
}
if ( V_25 )
V_78 = ( V_69 - 2 * V_73 - 2 * V_47 - 2 * V_74 ) & ~ 0x1 ;
else
V_78 = ( V_69 - V_73 - V_47 - V_74 + 1 ) & ~ 0x1 ;
if ( V_78 < 0 )
return false ;
switch ( V_47 ) {
case 4 :
V_79 = ( V_78 * 4 ) / 3 ;
break;
case 5 :
V_79 = ( V_78 * 16 ) / 9 ;
break;
case 6 :
V_79 = ( V_78 * 16 ) / 10 ;
break;
case 7 :
if ( V_78 == 1024 )
V_79 = ( V_78 * 5 ) / 4 ;
else if ( V_78 == 768 )
V_79 = ( V_78 * 15 ) / 9 ;
else
return false ;
break;
case 8 :
V_79 = V_71 ;
break;
default:
return false ;
}
if ( ! V_81 )
V_79 = V_79 & ~ 7 ;
if ( V_80 ) {
int V_91 ;
int V_92 ;
V_91 = V_81 ? V_93 : V_94 ;
V_92 = V_81 ? V_95 : V_96 ;
V_82 = ( V_79 + V_91 ) * V_70 ;
V_82 = ( V_82 / V_92 ) * V_92 ;
V_76 = V_91 / 2 ;
V_44 = V_97 ;
V_75 = V_91 - V_76 - V_44 ;
V_77 = V_79 + V_91 ;
} else {
unsigned V_98 =
100 * V_99 - ( V_100 * 100000 ) / V_70 ;
int V_91 ;
if ( V_98 < 2000 )
V_98 = 2000 ;
V_91 = V_79 * V_98 /
( 10000 - V_98 ) ;
V_91 = ( V_91 / ( 2 * V_101 ) ) * 2 * V_101 ;
V_82 = ( V_79 + V_91 ) * V_70 ;
V_82 = ( V_82 / V_96 ) * V_96 ;
V_76 = V_91 / 2 ;
V_77 = V_79 + V_91 ;
V_44 = V_77 * V_102 / 100 ;
V_44 = ( V_44 / V_101 ) * V_101 ;
V_75 = V_91 - V_44 - V_76 ;
}
V_72 -> type = V_13 ;
V_72 -> V_8 . V_42 = V_42 ;
V_72 -> V_8 . V_17 = V_79 ;
V_72 -> V_8 . V_14 = V_78 ;
V_72 -> V_8 . V_43 = V_75 ;
V_72 -> V_8 . V_46 = V_73 ;
V_72 -> V_8 . V_44 = V_44 ;
V_72 -> V_8 . V_47 = V_47 ;
V_72 -> V_8 . V_45 = V_77 - V_79 - V_75 - V_44 ;
if ( ! V_25 ) {
V_72 -> V_8 . V_48 = V_69 - V_78 - V_73 - V_47 ;
V_72 -> V_8 . V_25 = V_103 ;
} else {
V_72 -> V_8 . V_48 = ( V_69 - V_78 - 2 * V_73 -
2 * V_47 ) / 2 ;
V_72 -> V_8 . V_51 = V_69 - V_78 - 2 * V_73 -
2 * V_47 - V_72 -> V_8 . V_48 ;
V_72 -> V_8 . V_49 = V_73 ;
V_72 -> V_8 . V_50 = V_47 ;
V_72 -> V_8 . V_37 |= V_63 ;
V_72 -> V_8 . V_25 = V_104 ;
}
V_72 -> V_8 . V_20 = V_82 ;
V_72 -> V_8 . V_24 = V_67 ;
if ( V_80 )
V_72 -> V_8 . V_37 |= V_61 ;
return true ;
}
bool F_12 ( unsigned V_69 ,
unsigned V_70 ,
unsigned V_47 ,
T_2 V_42 ,
bool V_25 ,
struct V_105 V_106 ,
struct V_1 * V_72 )
{
int V_82 ;
int V_73 , V_74 , V_75 , V_44 ;
int V_77 , V_78 , V_79 ;
bool V_107 ;
int V_91 ;
if ( V_47 != 3 )
return false ;
if ( V_42 == V_60 )
V_107 = true ;
else if ( V_42 == V_59 )
V_107 = false ;
else
return false ;
if ( V_70 == 0 )
return false ;
V_73 = V_108 ;
V_74 = ( V_109 * V_70 + 500000 ) / 1000000 - V_47 ;
if ( V_25 )
V_78 = ( V_69 - 2 * V_73 - 2 * V_47 - 2 * V_74 ) & ~ 0x1 ;
else
V_78 = ( V_69 - V_73 - V_47 - V_74 + 1 ) & ~ 0x1 ;
if ( V_78 < 0 )
return false ;
if ( V_106 . V_110 == 0 || V_106 . V_111 == 0 ) {
V_106 . V_110 = 16 ;
V_106 . V_111 = 9 ;
}
V_79 = ( ( V_78 * V_106 . V_110 ) / V_106 . V_111 ) ;
V_79 = ( V_79 + V_112 / 2 ) & ~ ( V_112 - 1 ) ;
if ( V_107 ) {
V_58 V_113 ;
T_2 V_114 ;
V_113 = ( ( V_79 * V_115 * ( V_58 ) V_70 ) -
( ( V_58 ) V_79 * V_116 * 1000 ) ) ;
V_114 = ( V_70 * ( 100 - V_115 ) + V_116 * 1000 ) *
( 2 * V_112 ) ;
V_91 = F_9 ( ( V_113 + ( V_114 >> 1 ) ) , V_114 ) ;
V_91 *= ( 2 * V_112 ) ;
} else {
V_58 V_113 ;
T_2 V_114 ;
V_113 = ( ( V_79 * V_117 * ( V_58 ) V_70 ) -
( ( V_58 ) V_79 * V_118 * 1000 ) ) ;
V_114 = ( V_70 * ( 100 - V_117 ) + V_118 * 1000 ) *
( 2 * V_112 ) ;
V_91 = F_9 ( ( V_113 + ( V_114 >> 1 ) ) , V_114 ) ;
V_91 *= ( 2 * V_112 ) ;
}
V_77 = V_79 + V_91 ;
V_82 = ( V_79 + V_91 ) * V_70 ;
V_82 = V_82 / V_119 * V_119 ;
V_44 = ( V_77 * 8 + 50 ) / 100 ;
V_44 = ( ( V_44 + V_112 / 2 ) / V_112 ) * V_112 ;
V_75 = V_91 / 2 - V_44 ;
V_72 -> type = V_13 ;
V_72 -> V_8 . V_42 = V_42 ;
V_72 -> V_8 . V_17 = V_79 ;
V_72 -> V_8 . V_14 = V_78 ;
V_72 -> V_8 . V_43 = V_75 ;
V_72 -> V_8 . V_46 = V_73 ;
V_72 -> V_8 . V_44 = V_44 ;
V_72 -> V_8 . V_47 = V_47 ;
V_72 -> V_8 . V_45 = V_77 - V_79 - V_75 - V_44 ;
if ( ! V_25 ) {
V_72 -> V_8 . V_48 = V_69 - V_78 - V_73 - V_47 ;
V_72 -> V_8 . V_25 = V_103 ;
} else {
V_72 -> V_8 . V_48 = ( V_69 - V_78 - 2 * V_73 -
2 * V_47 ) / 2 ;
V_72 -> V_8 . V_51 = V_69 - V_78 - 2 * V_73 -
2 * V_47 - V_72 -> V_8 . V_48 ;
V_72 -> V_8 . V_49 = V_73 ;
V_72 -> V_8 . V_50 = V_47 ;
V_72 -> V_8 . V_37 |= V_63 ;
V_72 -> V_8 . V_25 = V_104 ;
}
V_72 -> V_8 . V_20 = V_82 ;
V_72 -> V_8 . V_24 = V_68 ;
if ( ! V_107 )
V_72 -> V_8 . V_37 |= V_61 ;
return true ;
}
struct V_105 F_13 ( T_3 V_120 , T_3 V_121 )
{
struct V_105 V_106 = { 16 , 9 } ;
T_3 V_122 ;
if ( ! V_120 && ! V_121 )
return V_106 ;
if ( V_120 && V_121 ) {
V_106 . V_110 = V_120 ;
V_106 . V_111 = V_121 ;
return V_106 ;
}
V_122 = V_120 | V_121 ;
if ( V_122 == 79 ) {
V_106 . V_110 = 16 ;
V_106 . V_111 = 9 ;
} else if ( V_122 == 34 ) {
V_106 . V_110 = 4 ;
V_106 . V_111 = 3 ;
} else if ( V_122 == 68 ) {
V_106 . V_110 = 15 ;
V_106 . V_111 = 9 ;
} else {
V_106 . V_110 = V_120 + 99 ;
V_106 . V_111 = 100 ;
}
if ( V_120 )
return V_106 ;
F_14 ( V_106 . V_111 , V_106 . V_110 ) ;
return V_106 ;
}
