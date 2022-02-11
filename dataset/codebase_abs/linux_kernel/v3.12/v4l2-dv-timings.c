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
( V_10 -> V_23 && ! ( V_8 -> V_23 & V_10 -> V_23 ) ) ||
( V_8 -> V_24 && ! ( V_11 & V_25 ) ) ||
( ! V_8 -> V_24 && ! ( V_11 & V_26 ) ) )
return false ;
return V_5 == NULL || V_5 ( V_2 , V_6 ) ;
}
int F_2 ( struct V_27 * V_2 ,
const struct V_3 * V_10 ,
T_1 V_5 ,
void * V_6 )
{
T_2 V_28 , V_29 ;
memset ( V_2 -> V_30 , 0 , sizeof( V_2 -> V_30 ) ) ;
for ( V_28 = V_29 = 0 ; V_31 [ V_28 ] . V_8 . V_17 ; V_28 ++ ) {
if ( F_1 ( V_31 + V_28 , V_10 ,
V_5 , V_6 ) &&
V_29 ++ == V_2 -> V_32 ) {
V_2 -> V_33 = V_31 [ V_28 ] ;
return 0 ;
}
}
return - V_34 ;
}
bool F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_10 ,
unsigned V_35 ,
T_1 V_5 ,
void * V_6 )
{
int V_28 ;
if ( ! F_1 ( V_2 , V_10 , V_5 , V_6 ) )
return false ;
for ( V_28 = 0 ; V_28 < V_31 [ V_28 ] . V_8 . V_17 ; V_28 ++ ) {
if ( F_1 ( V_31 + V_28 , V_10 ,
V_5 , V_6 ) &&
F_4 ( V_2 , V_31 + V_28 ,
V_35 ) ) {
* V_2 = V_31 [ V_28 ] ;
return true ;
}
}
return false ;
}
bool F_4 ( const struct V_1 * V_36 ,
const struct V_1 * V_37 ,
unsigned V_35 )
{
if ( V_36 -> type != V_37 -> type || V_36 -> type != V_13 )
return false ;
if ( V_36 -> V_8 . V_17 == V_37 -> V_8 . V_17 &&
V_36 -> V_8 . V_14 == V_37 -> V_8 . V_14 &&
V_36 -> V_8 . V_24 == V_37 -> V_8 . V_24 &&
V_36 -> V_8 . V_38 == V_37 -> V_8 . V_38 &&
V_36 -> V_8 . V_20 >= V_37 -> V_8 . V_20 - V_35 &&
V_36 -> V_8 . V_20 <= V_37 -> V_8 . V_20 + V_35 &&
V_36 -> V_8 . V_39 == V_37 -> V_8 . V_39 &&
V_36 -> V_8 . V_40 == V_37 -> V_8 . V_40 &&
V_36 -> V_8 . V_41 == V_37 -> V_8 . V_41 &&
V_36 -> V_8 . V_42 == V_37 -> V_8 . V_42 &&
( ! V_36 -> V_8 . V_24 ||
( V_36 -> V_8 . V_43 == V_37 -> V_8 . V_43 &&
V_36 -> V_8 . V_44 == V_37 -> V_8 . V_44 &&
V_36 -> V_8 . V_45 == V_37 -> V_8 . V_45 ) ) )
return true ;
return false ;
}
void F_5 ( const char * V_46 , const char * V_47 ,
const struct V_1 * V_2 , bool V_48 )
{
const struct V_7 * V_8 = & V_2 -> V_8 ;
T_2 V_49 , V_50 ;
if ( V_2 -> type != V_13 )
return;
V_49 = F_6 ( V_8 ) ;
V_50 = F_7 ( V_8 ) ;
if ( V_47 == NULL )
V_47 = L_1 ;
F_8 ( L_2 , V_46 , V_47 ,
V_8 -> V_17 , V_8 -> V_14 , V_8 -> V_24 ? L_3 : L_4 ,
( V_49 * V_50 ) > 0 ? ( ( T_2 ) V_8 -> V_20 / ( V_49 * V_50 ) ) : 0 ,
V_49 , V_50 ) ;
if ( ! V_48 )
return;
F_8 ( L_5 ,
V_46 , V_8 -> V_39 ,
( V_8 -> V_38 & V_51 ) ? L_6 : L_7 ,
V_8 -> V_52 , V_8 -> V_53 ) ;
F_8 ( L_8 ,
V_46 , V_8 -> V_40 ,
( V_8 -> V_38 & V_54 ) ? L_6 : L_7 ,
V_8 -> V_41 , V_8 -> V_42 ) ;
F_8 ( L_9 , V_46 , V_8 -> V_20 ) ;
F_8 ( L_10 , V_46 , V_8 -> V_55 ,
( V_8 -> V_55 & V_56 ) ?
L_11 : L_1 ,
( V_8 -> V_55 & V_57 ) ?
L_12 : L_1 ,
( V_8 -> V_55 & V_58 ) ?
L_13 : L_1 ,
( V_8 -> V_55 & V_59 ) ?
L_14 : L_1 ) ;
F_8 ( L_15 , V_46 , V_8 -> V_23 ,
( V_8 -> V_23 & V_60 ) ? L_16 : L_1 ,
( V_8 -> V_23 & V_61 ) ? L_17 : L_1 ,
( V_8 -> V_23 & V_62 ) ? L_18 : L_1 ,
( V_8 -> V_23 & V_63 ) ? L_19 : L_1 ) ;
}
bool F_9 ( unsigned V_64 , unsigned V_65 , unsigned V_41 ,
T_2 V_38 , struct V_1 * V_66 )
{
int V_67 , V_68 , V_69 , V_70 , V_52 ;
int V_71 , V_72 , V_73 ;
bool V_74 ;
unsigned V_75 ;
if ( V_41 < 4 || V_41 > 7 )
return false ;
if ( V_38 == V_54 )
V_74 = false ;
else if ( V_38 == V_51 )
V_74 = true ;
else
return false ;
if ( V_74 ) {
V_67 = V_76 ;
V_68 = ( V_77 * V_65 + 1999999 ) / 1000000 ;
V_68 -= V_41 + V_67 ;
if ( V_68 < V_78 )
V_68 = V_78 ;
} else {
V_67 = V_79 ;
V_68 = ( V_80 * V_65 + 1999999 ) / 1000000 - V_41 ;
if ( V_68 < V_81 )
V_68 = V_81 ;
}
V_72 = ( V_64 - V_67 - V_41 - V_68 + 1 ) & ~ 0x1 ;
switch ( V_41 ) {
case 4 :
V_73 = ( V_72 * 4 ) / 3 ;
break;
case 5 :
V_73 = ( V_72 * 16 ) / 9 ;
break;
case 6 :
V_73 = ( V_72 * 16 ) / 10 ;
break;
case 7 :
if ( V_72 == 1024 )
V_73 = ( V_72 * 5 ) / 4 ;
else if ( V_72 == 768 )
V_73 = ( V_72 * 15 ) / 9 ;
else
return false ;
break;
default:
return false ;
}
V_73 = V_73 & ~ 7 ;
if ( V_74 ) {
V_75 = ( V_73 + V_82 ) * V_65 ;
V_75 = ( V_75 / V_83 ) * V_83 ;
V_70 = V_84 ;
V_52 = V_85 ;
V_69 = V_82 - V_70 - V_52 ;
V_71 = V_73 + V_82 ;
} else {
unsigned V_86 =
100 * V_87 - ( V_88 * 100000 ) / V_65 ;
int V_89 ;
if ( V_86 < 2000 )
V_86 = 2000 ;
V_89 = V_73 * V_86 /
( 10000 - V_86 ) ;
V_89 = ( V_89 / ( 2 * V_90 ) ) * 2 * V_90 ;
V_75 = ( V_73 + V_89 ) * V_65 ;
V_75 = ( V_75 / V_83 ) * V_83 ;
V_70 = V_89 / 2 ;
V_71 = V_73 + V_89 ;
V_52 = ( V_71 * 8 + 50 ) / 100 ;
V_52 = V_52 - V_52 % V_90 ;
V_69 = V_89 - V_52 - V_70 ;
}
V_66 -> type = V_13 ;
V_66 -> V_8 . V_38 = V_38 ;
V_66 -> V_8 . V_17 = V_73 ;
V_66 -> V_8 . V_14 = V_72 ;
V_66 -> V_8 . V_39 = V_69 ;
V_66 -> V_8 . V_40 = V_67 ;
V_66 -> V_8 . V_52 = V_52 ;
V_66 -> V_8 . V_41 = V_41 ;
V_66 -> V_8 . V_53 = V_71 - V_73 - V_69 - V_52 ;
V_66 -> V_8 . V_42 = V_64 - V_72 - V_67 - V_41 ;
V_66 -> V_8 . V_20 = V_75 ;
V_66 -> V_8 . V_23 = V_62 ;
if ( V_74 )
V_66 -> V_8 . V_55 |= V_56 ;
return true ;
}
bool F_10 ( unsigned V_64 ,
unsigned V_65 ,
unsigned V_41 ,
T_2 V_38 ,
struct V_91 V_92 ,
struct V_1 * V_66 )
{
int V_75 ;
int V_67 , V_68 , V_69 , V_52 ;
int V_71 , V_72 , V_73 ;
bool V_93 ;
int V_89 ;
if ( V_41 != 3 )
return false ;
if ( V_38 == V_54 )
V_93 = true ;
else if ( V_38 == V_51 )
V_93 = false ;
else
return false ;
V_67 = V_94 ;
V_68 = ( V_95 * V_65 + 999999 ) / 1000000 - V_41 ;
V_72 = ( V_64 - V_67 - V_41 - V_68 + 1 ) & ~ 0x1 ;
if ( V_92 . V_96 == 0 || V_92 . V_97 == 0 ) {
V_92 . V_96 = 16 ;
V_92 . V_97 = 9 ;
}
V_73 = ( ( V_72 * V_92 . V_96 ) / V_92 . V_97 ) ;
if ( V_93 )
V_89 = ( ( V_73 * V_98 * V_65 ) -
( V_73 * V_99 * 1000 ) +
( V_65 * ( 100 - V_98 ) + V_99 * 1000 ) / 2 ) /
( V_65 * ( 100 - V_98 ) + V_99 * 1000 ) ;
else
V_89 = ( ( V_73 * V_100 * V_65 ) -
( V_73 * V_101 * 1000 ) +
( V_65 * ( 100 - V_100 ) + V_101 * 1000 ) / 2 ) /
( V_65 * ( 100 - V_100 ) + V_101 * 1000 ) ;
V_89 = V_89 - V_89 % ( 2 * V_102 ) ;
V_71 = V_73 + V_89 ;
V_75 = ( V_73 + V_89 ) * V_65 ;
V_75 = V_75 / V_103 * V_103 ;
V_52 = ( V_71 * 8 + 50 ) / 100 ;
V_52 = V_52 - V_52 % V_102 ;
V_69 = V_89 / 2 - V_52 ;
V_66 -> type = V_13 ;
V_66 -> V_8 . V_38 = V_38 ;
V_66 -> V_8 . V_17 = V_73 ;
V_66 -> V_8 . V_14 = V_72 ;
V_66 -> V_8 . V_39 = V_69 ;
V_66 -> V_8 . V_40 = V_67 ;
V_66 -> V_8 . V_52 = V_52 ;
V_66 -> V_8 . V_41 = V_41 ;
V_66 -> V_8 . V_53 = V_71 - V_73 - V_69 - V_52 ;
V_66 -> V_8 . V_42 = V_64 - V_72 - V_67 - V_41 ;
V_66 -> V_8 . V_20 = V_75 ;
V_66 -> V_8 . V_23 = V_63 ;
if ( ! V_93 )
V_66 -> V_8 . V_55 |= V_56 ;
return true ;
}
struct V_91 F_11 ( T_3 V_104 , T_3 V_105 )
{
struct V_91 V_92 = { 16 , 9 } ;
T_2 V_106 ;
T_3 V_107 ;
if ( ! V_104 && ! V_105 )
return V_92 ;
if ( V_104 && V_105 ) {
V_92 . V_96 = V_104 ;
V_92 . V_97 = V_105 ;
return V_92 ;
}
V_107 = V_104 | V_105 ;
if ( V_107 == 79 ) {
V_92 . V_96 = 16 ;
V_92 . V_97 = 9 ;
} else if ( V_107 == 34 ) {
V_92 . V_96 = 4 ;
V_92 . V_96 = 3 ;
} else if ( V_107 == 68 ) {
V_92 . V_96 = 15 ;
V_92 . V_96 = 9 ;
} else {
V_92 . V_96 = V_104 + 99 ;
V_92 . V_97 = 100 ;
}
if ( V_104 )
return V_92 ;
V_106 = V_92 . V_97 ;
V_92 . V_97 = V_92 . V_96 ;
V_92 . V_96 = V_106 ;
return V_92 ;
}
