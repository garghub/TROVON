static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 , V_5 + 1 ) ;
F_3 ( V_2 , V_5 + 1 , V_4 | 0x04 ) ;
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 | 0x01 ) ;
V_4 = F_2 ( V_2 , V_6 + 2 ) ;
F_3 ( V_2 , V_6 + 2 , V_4 & 0xf7 ) ;
} else {
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 & 0xfe ) ;
F_3 ( V_2 , V_6 + 1 , 0x00 ) ;
}
}
static int F_4 ( struct V_1 * V_2 , void * V_7 , T_2 V_8 )
{
int V_9 = V_10 ;
T_2 V_11 = 4 ;
T_2 V_12 = 8 ;
T_2 V_13 = 1 ;
T_2 V_14 = 0 , V_15 = 0 , V_16 = 0 ;
T_2 V_17 = 0 , V_18 = 0 ;
T_1 * V_19 = ( T_1 * ) V_7 ;
T_2 V_20 = 0 , V_21 = 0 ;
V_11 = 254 ;
V_14 = V_8 / V_11 ;
V_17 = V_8 % V_11 ;
if ( V_14 ) {
F_5 ( V_22 , V_23 ,
( L_1
L_2 ,
V_8 , V_11 , V_14 ,
V_17 ) ) ;
}
for ( V_20 = 0 ; V_20 < V_14 ; V_20 ++ ) {
V_9 = F_6 ( V_2 , ( V_24 +
V_20 * V_11 ) ,
V_11 ,
( V_19 + V_20 * V_11 ) ) ;
if ( V_9 == V_25 )
goto exit;
}
if ( V_17 ) {
V_21 = V_14 * V_11 ;
V_15 = V_17 / V_12 ;
V_18 = V_17 % V_12 ;
if ( V_15 ) {
F_5 ( V_22 , V_23 ,
( L_3
L_4
L_5 ,
( V_8 - V_21 ) , V_12 ,
V_15 , V_18 ) ) ;
}
for ( V_20 = 0 ; V_20 < V_15 ; V_20 ++ ) {
V_9 = F_6 ( V_2 ,
( V_24 +
V_21 + V_20 * V_12 ) ,
V_12 ,
( V_19 + V_21 +
V_20 * V_12 ) ) ;
if ( V_9 == V_25 )
goto exit;
}
}
if ( V_18 ) {
V_21 = ( V_14 * V_11 ) +
( V_15 * V_12 ) ;
V_16 = V_18 / V_13 ;
F_5 ( V_22 , V_23 ,
( L_6
L_7 ,
( V_8 - V_21 ) , V_13 , V_16 ) ) ;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 ++ ) {
V_9 = F_3 ( V_2 ,
( V_24 + V_21 + V_20 ) ,
* ( V_19 + V_21 + V_20 ) ) ;
if ( V_9 == V_25 )
goto exit;
}
}
exit:
return V_9 ;
}
static int
F_7 ( struct V_1 * V_2 , T_2 V_26 , void * V_7 , T_2 V_27 )
{
T_1 V_28 ;
T_1 V_29 = ( T_1 ) ( V_26 & 0x07 ) ;
V_28 = ( F_2 ( V_2 , V_6 + 2 ) & 0xF8 ) | V_29 ;
F_3 ( V_2 , V_6 + 2 , V_28 ) ;
return F_4 ( V_2 , V_7 , V_27 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_7 , T_2 V_27 )
{
int V_9 = V_10 ;
T_2 V_30 , V_31 ;
T_2 V_26 , V_21 ;
T_1 * V_19 = ( T_1 * ) V_7 ;
V_30 = V_27 / V_32 ;
V_31 = V_27 % V_32 ;
for ( V_26 = 0 ; V_26 < V_30 ; V_26 ++ ) {
V_21 = V_26 * V_32 ;
V_9 = F_7 ( V_2 , V_26 , V_19 + V_21 ,
V_32 ) ;
if ( V_9 == V_25 )
goto exit;
}
if ( V_31 ) {
V_21 = V_30 * V_32 ;
V_26 = V_30 ;
V_9 = F_7 ( V_2 , V_26 , V_19 + V_21 ,
V_31 ) ;
if ( V_9 == V_25 )
goto exit;
}
F_5 ( V_22 , V_33 ,
( L_8 ) ) ;
exit:
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_34 = 0 ;
T_2 V_35 ;
do {
V_35 = F_10 ( V_2 , V_6 ) ;
if ( V_35 & V_36 )
break;
} while ( V_34 ++ < V_37 );
if ( V_34 >= V_37 ) {
F_5 ( V_22 , V_38 ,
( L_9 ,
V_39 , V_35 ) ) ;
return V_25 ;
}
F_5 ( V_22 , V_33 ,
( L_10 , V_39 ,
V_35 ) ) ;
V_35 = F_10 ( V_2 , V_6 ) ;
V_35 |= V_40 ;
V_35 &= ~ V_41 ;
F_11 ( V_2 , V_6 , V_35 ) ;
V_34 = 0 ;
do {
V_35 = F_10 ( V_2 , V_6 ) ;
if ( V_35 & V_41 ) {
F_5 ( V_22 , V_33 ,
( L_11
L_12 ,
V_39 , V_35 ) ) ;
return V_10 ;
}
F_12 ( 5 ) ;
} while ( V_34 ++ < V_37 );
F_5 ( V_22 , V_38 ,
( L_13 ,
V_39 , V_35 ) ) ;
return V_25 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
T_1 V_44 ;
T_1 V_45 = 100 ;
if ( ! ( F_15 ( V_2 ) &&
( ( V_43 -> V_46 < 0x21 ) ||
( V_43 -> V_46 == 0x21 &&
V_43 -> V_47 < 0x01 ) ) ) ) {
F_3 ( V_2 , V_48 + 3 , 0x20 ) ;
V_44 = F_2 ( V_2 , V_5 + 1 ) ;
while ( V_44 & F_16 ( 2 ) ) {
V_45 -- ;
if ( V_45 == 0 )
break;
F_12 ( 50 ) ;
V_44 = F_2 ( V_2 , V_5 + 1 ) ;
}
F_5 ( V_22 , V_33 ,
( L_14 , V_39 ,
V_45 ) ) ;
if ( ( V_45 == 0 ) ) {
V_44 = F_2 ( V_2 , V_5 + 1 ) ;
F_3 ( V_2 , V_5 + 1 ,
V_44 & ~ F_16 ( 2 ) ) ;
}
}
}
int F_17 ( struct V_1 * V_2 )
{
int V_49 = V_10 ;
T_1 V_50 = 0 ;
unsigned long V_51 ;
struct V_42 * V_43 = F_14 ( V_2 ) ;
struct V_52 * V_53 = F_18 ( V_2 ) ;
struct V_54 * V_54 = F_19 ( V_53 ) ;
struct V_55 * V_56 = NULL ;
const struct V_57 * V_58 ;
char * V_59 ;
T_1 * V_60 = NULL ;
T_1 * V_61 ;
int V_62 ;
static int V_63 ;
F_5 ( V_22 , V_33 , ( L_15 , V_39 ) ) ;
if ( F_20 ( V_43 -> V_64 ) ) {
V_59 = L_16 ;
F_5 ( V_22 , V_33 ,
( L_17
L_18 ) ) ;
} else if ( F_21 ( V_43 -> V_64 ) ) {
if ( V_2 -> V_65 . V_66 == 1 ) {
V_59 = L_19 ;
F_22 ( L_20
L_21 ) ;
} else {
if ( F_23 ( V_2 ) ) {
V_59 = L_22 ;
F_22 ( L_23
L_24 ) ;
} else {
V_59 = L_19 ;
F_22 ( L_25
L_26 ) ;
}
}
} else {
F_5 ( V_22 , V_38 ,
( L_27 , V_39 ) ) ;
V_49 = V_25 ;
goto Exit;
}
F_24 ( L_28 , V_59 ) ;
if ( F_25 ( & V_58 , V_59 , V_54 ) ) {
F_26 ( L_29 ) ;
V_49 = V_25 ;
goto Exit;
}
if ( ! V_58 ) {
F_26 ( L_30 , V_59 ) ;
V_49 = V_25 ;
goto Exit;
}
V_60 = F_27 ( V_58 -> V_67 , V_58 -> V_27 , V_68 ) ;
if ( ! V_60 ) {
V_49 = V_25 ;
goto Exit;
}
V_61 = V_60 ;
V_62 = V_58 -> V_27 ;
F_28 ( V_58 ) ;
V_56 = (struct V_55 * ) V_60 ;
V_43 -> V_46 = F_29 ( V_56 -> V_69 ) ;
V_43 -> V_47 = V_56 -> V_70 ;
V_43 -> V_71 = F_29 ( V_56 -> V_72 ) ;
F_22 ( L_31 ,
V_39 , V_43 -> V_46 ,
V_43 -> V_47 , V_43 -> V_71 ) ;
if ( ! V_63 ++ )
F_24 ( L_32
L_33 , V_73 , V_43 -> V_46 ,
V_43 -> V_47 ,
V_43 -> V_71 ) ;
if ( F_30 ( V_56 ) ) {
V_61 = V_61 + 32 ;
V_62 = V_62 - 32 ;
}
if ( F_2 ( V_2 , V_6 ) & V_74 ) {
F_13 ( V_2 ) ;
F_3 ( V_2 , V_6 , 0x00 ) ;
}
F_1 ( V_2 , true ) ;
V_51 = V_75 ;
while ( 1 ) {
F_3 ( V_2 , V_6 ,
F_2 ( V_2 , V_6 ) |
V_36 ) ;
V_49 = F_8 ( V_2 , V_61 , V_62 ) ;
if ( V_49 == V_10 ||
( F_31 ( V_75 - V_51 ) > 500 &&
V_50 ++ >= 3 ) )
break;
F_22 ( L_34
L_35 , V_39 , V_50 ,
F_31 ( V_75 - V_51 ) ) ;
}
F_1 ( V_2 , false ) ;
if ( V_10 != V_49 ) {
F_22 ( L_36 ) ;
goto Exit;
}
V_49 = F_9 ( V_2 ) ;
if ( V_10 != V_49 ) {
F_5 ( V_22 , V_38 ,
( L_36 ) ) ;
goto Exit;
}
F_5 ( V_22 , V_33 ,
( L_37 ) ) ;
Exit:
F_32 ( V_60 ) ;
return V_49 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
V_2 -> V_76 . V_77 = false ;
V_43 -> V_78 = 0 ;
}
static T_1
F_34 ( struct V_1 * V_2 , T_1 V_79 )
{
T_1 V_80 = false ;
T_2 V_35 = 0 ;
F_22 ( L_38 , V_39 , V_79 ) ;
V_35 = F_10 ( V_2 , V_81 ) ;
V_80 = true ;
switch ( V_79 ) {
case 0 :
V_35 = ( V_35 & ~ V_82 ) |
F_35 ( V_83 ) ;
break;
case 1 :
V_35 = ( V_35 & ~ V_82 ) |
F_35 ( V_84 ) ;
break;
case 2 :
V_35 = ( V_35 & ~ V_82 ) |
F_35 ( V_85 ) ;
break;
case 3 :
V_35 = ( V_35 & ~ V_82 ) |
F_35 ( V_86 ) ;
break;
default:
V_35 = ( V_35 & ~ V_82 ) |
F_35 ( V_83 ) ;
V_80 = false ;
break;
}
F_11 ( V_2 , V_81 , V_35 ) ;
return V_80 ;
}
static void
F_36 ( struct V_1 * V_2 ,
T_3 V_87 , T_3 V_88 , T_1 * V_89 )
{
T_1 * V_90 = NULL ;
T_3 V_91 = 0 ;
T_1 V_21 , V_92 ;
T_1 V_93 , V_94 , V_95 ;
T_3 V_20 , V_96 , V_97 ;
struct V_42 * V_43 = F_14 ( V_2 ) ;
if ( ( V_87 + V_88 ) > V_98 ) {
F_22 ( L_39 ,
V_39 , V_87 , V_88 ) ;
return;
}
V_90 = F_37 ( V_98 , V_68 ) ;
if ( V_90 == NULL ) {
F_22 ( L_40 , V_39 ) ;
return;
}
memset ( V_90 , 0xFF , V_98 ) ;
F_34 ( V_2 , 0 ) ;
while ( F_38 ( V_91 ) ) {
F_39 ( V_2 , V_91 ++ , & V_93 ) ;
if ( V_93 == 0xFF ) {
F_22 ( L_41 , V_39 ,
V_91 ) ;
break;
}
if ( F_40 ( V_93 ) ) {
V_21 = F_41 ( V_93 ) ;
F_39 ( V_2 , V_91 ++ , & V_94 ) ;
if ( F_42 ( V_94 ) ) {
continue;
}
V_21 |= ( ( V_94 & 0xF0 ) >> 1 ) ;
V_92 = ( V_94 & 0x0F ) ;
} else {
V_21 = ( ( V_93 >> 4 ) & 0x0f ) ;
V_92 = ( V_93 & 0x0f ) ;
}
if ( V_21 < V_99 ) {
T_3 V_100 ;
V_100 = V_21 * V_101 ;
for ( V_20 = 0 ; V_20 < V_102 ; V_20 ++ ) {
if ( ! ( V_92 & ( 0x01 << V_20 ) ) ) {
F_39 ( V_2 , V_91 ++ ,
& V_95 ) ;
V_90 [ V_100 ] = V_95 ;
F_39 ( V_2 , V_91 ++ ,
& V_95 ) ;
V_90 [ V_100 + 1 ] = V_95 ;
}
V_100 += 2 ;
}
} else {
F_22 ( V_103 L_42 ,
V_39 , V_21 ) ;
V_91 += F_43 ( V_92 ) * 2 ;
}
}
for ( V_20 = 0 ; V_20 < V_88 ; V_20 ++ )
V_89 [ V_20 ] = V_90 [ V_87 + V_20 ] ;
F_44 ( V_2 , V_104 ,
V_105 , & V_96 ) ;
V_97 = V_91 - 1 ;
V_43 -> V_106 = V_97 ;
F_32 ( V_90 ) ;
}
static void
F_45 ( struct V_1 * V_2 ,
T_3 V_87 , T_3 V_88 , T_1 * V_89 )
{
T_1 * V_90 ;
T_1 V_79 ;
T_3 V_91 ;
T_1 V_93 , V_94 , V_95 ;
T_1 V_21 , V_92 ;
T_3 V_20 , V_96 , V_97 ;
struct V_42 * V_43 = F_14 ( V_2 ) ;
if ( ( V_87 + V_88 ) > V_107 ) {
F_22 ( L_39 ,
V_39 , V_87 , V_88 ) ;
return;
}
V_90 = F_37 ( V_107 , V_68 ) ;
if ( V_90 == NULL ) {
F_22 ( L_43 , V_39 ) ;
return;
}
memset ( V_90 , 0xFF , V_107 ) ;
F_44 ( V_2 , V_108 ,
V_109 , & V_96 ) ;
for ( V_79 = 1 ; V_79 < V_110 ; V_79 ++ ) {
if ( F_34 ( V_2 , V_79 ) == false ) {
F_22 ( L_44 ,
V_39 ) ;
goto exit;
}
V_91 = 0 ;
while ( F_38 ( V_91 ) ) {
F_39 ( V_2 , V_91 ++ , & V_93 ) ;
if ( V_93 == 0xFF )
break;
if ( F_40 ( V_93 ) ) {
V_21 = F_41 ( V_93 ) ;
F_39 ( V_2 , V_91 ++ ,
& V_94 ) ;
if ( F_42 ( V_94 ) ) {
continue;
}
V_21 |= ( ( V_94 & 0xF0 ) >> 1 ) ;
V_92 = ( V_94 & 0x0F ) ;
} else {
V_21 = ( ( V_93 >> 4 ) & 0x0f ) ;
V_92 = ( V_93 & 0x0f ) ;
}
if ( V_21 < V_111 ) {
T_3 V_100 ;
V_100 = V_21 * V_101 ;
for ( V_20 = 0 ; V_20 < V_102 ; V_20 ++ ) {
if ( ! ( V_92 & ( 0x01 << V_20 ) ) ) {
F_39 ( V_2 ,
V_91 ++ ,
& V_95 ) ;
V_90 [ V_100 ] = V_95 ;
F_39 ( V_2 ,
V_91 ++ ,
& V_95 ) ;
V_90 [ V_100 + 1 ] = V_95 ;
}
V_100 += 2 ;
}
} else {
F_22 ( V_103
L_42 ,
V_39 , V_21 ) ;
V_91 += F_43 ( V_92 ) * 2 ;
}
}
if ( ( V_91 - 1 ) < V_96 ) {
F_22 ( L_45 ,
V_39 , V_79 , V_91 - 1 ) ;
break;
}
}
F_34 ( V_2 , 0 ) ;
for ( V_20 = 0 ; V_20 < V_88 ; V_20 ++ )
V_89 [ V_20 ] = V_90 [ V_87 + V_20 ] ;
F_44 ( V_2 , V_108 ,
V_105 , & V_96 ) ;
V_97 = ( V_112 * ( V_79 - 1 ) ) + V_91 - 1 ;
V_43 -> V_113 = V_97 ;
exit:
F_32 ( V_90 ) ;
}
void
F_46 ( struct V_1 * V_2 ,
T_1 V_114 , T_3 V_87 , T_3 V_88 , T_1 * V_89 )
{
if ( V_114 == V_104 )
F_36 ( V_2 , V_87 , V_88 , V_89 ) ;
else
F_45 ( V_2 , V_87 , V_88 , V_89 ) ;
}
T_3 F_47 ( struct V_1 * V_2 )
{
T_3 V_115 = 0 ;
T_1 V_116 = 0 , V_117 = 0 ;
T_1 V_118 , V_119 = 0 ;
struct V_42 * V_43 = F_14 ( V_2 ) ;
V_115 = V_43 -> V_106 ;
F_22 ( L_46 , V_39 , V_115 ) ;
F_34 ( V_2 , 0 ) ;
while ( F_38 ( V_115 ) ) {
if ( F_48 ( V_2 , V_115 , & V_118 ) ==
V_25 ) {
F_22 ( V_103 L_47
L_48 , V_39 , V_115 ) ;
break;
}
if ( V_118 == 0xFF )
break;
if ( F_40 ( V_118 ) ) {
V_116 = F_41 ( V_118 ) ;
V_115 ++ ;
F_48 ( V_2 , V_115 , & V_118 ) ;
if ( F_42 ( V_118 ) ) {
continue;
}
V_116 |= ( ( V_118 & 0xF0 ) >> 1 ) ;
V_117 = V_118 & 0x0F ;
} else {
V_116 = ( V_118 >> 4 ) & 0x0F ;
V_117 = V_118 & 0x0F ;
}
V_119 = F_43 ( V_117 ) ;
V_115 += ( V_119 * 2 ) + 1 ;
}
V_43 -> V_106 = V_115 ;
F_22 ( L_49 , V_39 , V_115 ) ;
return V_115 ;
}
T_3 F_49 ( struct V_1 * V_2 )
{
T_3 V_120 ;
T_3 V_115 ;
T_1 V_79 , V_121 ;
T_1 V_116 = 0 , V_117 = 0 ;
T_1 V_118 , V_119 = 0 ;
T_3 V_122 = 0 ;
struct V_42 * V_43 = F_14 ( V_2 ) ;
V_120 = V_43 -> V_113 ;
V_115 = ( T_3 ) ( ( V_120 % V_112 ) ) ;
V_121 = ( T_1 ) ( 1 + ( V_120 / V_112 ) ) ;
F_22 ( L_50 , V_39 , V_121 ,
V_115 ) ;
F_44 ( V_2 , V_108 ,
V_109 , & V_122 ) ;
for ( V_79 = V_121 ; V_79 < V_110 ; V_79 ++ ) {
if ( F_34 ( V_2 , V_79 ) == false ) {
F_22 ( V_103 L_51 ,
V_39 , V_79 ) ;
V_79 = V_110 ;
break;
}
if ( V_79 != V_121 )
V_115 = 0 ;
while ( F_38 ( V_115 ) ) {
if ( F_48 ( V_2 , V_115 ,
& V_118 ) == V_25 ) {
F_22 ( V_103 L_52
L_53 ,
V_39 , V_115 ) ;
V_79 = V_110 ;
break;
}
if ( V_118 == 0xFF )
break;
if ( F_40 ( V_118 ) ) {
V_116 = F_41 ( V_118 ) ;
V_115 ++ ;
F_48 ( V_2 , V_115 ,
& V_118 ) ;
if ( F_42 ( V_118 ) ) {
V_115 ++ ;
continue;
}
V_116 |= ( ( V_118 & 0xF0 ) >> 1 ) ;
V_117 = V_118 & 0x0F ;
} else {
V_116 = ( V_118 >> 4 ) & 0x0F ;
V_117 = V_118 & 0x0F ;
}
V_119 = F_43 ( V_117 ) ;
V_115 += ( V_119 * 2 ) + 1 ;
}
if ( V_115 < V_122 ) {
break;
}
}
V_122 = ( ( V_79 - 1 ) * V_112 ) + V_115 ;
V_43 -> V_113 = V_122 ;
F_22 ( L_49 , V_39 , V_122 ) ;
return V_122 ;
}
bool
F_50 ( struct V_1 * V_2 , T_1 V_21 , T_1 * V_67 )
{
T_1 V_118 , V_119 = 0 ;
T_3 V_115 = 0 ;
T_1 V_116 = 0 , V_117 = 0 ;
T_1 V_20 ;
T_1 V_123 = 0 ;
T_4 V_9 ;
if ( V_67 == NULL )
return false ;
F_44 ( V_2 , V_104 , V_124 ,
& V_123 ) ;
if ( V_21 > V_123 ) {
F_22 ( L_54 ,
V_39 , V_21 , V_123 ) ;
return false ;
}
memset ( V_67 , 0xFF , V_101 ) ;
V_9 = true ;
while ( F_38 ( V_115 ) ) {
if ( F_48 ( V_2 , V_115 ++ , & V_118 ) ==
V_25 ) {
V_9 = false ;
break;
}
if ( V_118 == 0xFF )
break;
if ( F_40 ( V_118 ) ) {
V_116 = F_41 ( V_118 ) ;
F_48 ( V_2 , V_115 ++ , & V_118 ) ;
if ( F_42 ( V_118 ) ) {
F_22 ( L_55 ,
V_39 ) ;
continue;
}
V_116 |= ( ( V_118 & 0xF0 ) >> 1 ) ;
V_117 = V_118 & 0x0F ;
} else {
V_116 = ( V_118 >> 4 ) & 0x0F ;
V_117 = V_118 & 0x0F ;
}
if ( V_116 == V_21 ) {
for ( V_20 = 0 ; V_20 < V_102 ; V_20 ++ ) {
if ( ! ( V_117 & ( 0x01 << V_20 ) ) ) {
F_39 ( V_2 , V_115 ++ ,
& V_118 ) ;
V_67 [ V_20 * 2 ] = V_118 ;
F_39 ( V_2 , V_115 ++ ,
& V_118 ) ;
V_67 [ ( V_20 * 2 ) + 1 ] = V_118 ;
}
}
} else {
V_119 = F_43 ( V_117 ) ;
V_115 += V_119 * 2 ;
}
}
return V_9 ;
}
void F_51 ( struct V_1 * V_2 )
{
T_2 V_35 ;
struct V_125 V_126 ;
struct V_42 * V_43 ;
V_43 = F_14 ( V_2 ) ;
V_35 = F_10 ( V_2 , V_127 ) ;
V_126 . V_128 = V_129 ;
V_126 . V_130 = ( ( V_35 & V_131 ) ? V_132 : V_133 ) ;
V_126 . V_134 = V_135 ;
V_126 . V_136 =
( ( V_35 & V_137 ) ? V_138 : V_139 ) ;
V_126 . V_140 = ( V_35 & V_141 ) >> V_142 ;
V_43 -> V_143 = ( ( V_35 & V_144 ) ?
V_145 : V_146 ) ;
V_35 = F_10 ( V_2 , V_147 ) ;
V_126 . V_148 = ( ( V_35 & V_149 ) >> 20 ) ;
V_43 -> V_150 = V_151 ;
V_35 = F_10 ( V_2 , V_152 ) ;
V_43 -> V_150 |=
( ( V_35 & V_153 ) ? V_154 : 0 ) ;
V_43 -> V_150 |= ( ( V_35 & V_155 ) ? V_156 : 0 ) ;
V_43 -> V_150 |=
( ( V_35 & V_157 ) ? V_158 : 0 ) ;
V_43 -> V_159 =
( ( V_35 & V_160 ) ? V_161 :
V_162 ) ;
F_52 ( V_126 ) ;
V_43 -> V_64 = V_126 ;
if ( F_53 ( V_126 ) )
V_43 -> V_163 = V_164 ;
else if ( F_54 ( V_126 ) )
V_43 -> V_163 = V_165 ;
else
V_43 -> V_163 = V_166 ;
F_55 ( L_56 , V_43 -> V_163 ) ;
}
void F_56 ( struct V_1 * V_2 , T_1 V_167 , T_1 V_168 )
{
struct V_42 * V_43 ;
T_2 V_100 ;
T_1 * V_169 ;
V_43 = F_14 ( V_2 ) ;
V_169 = ( T_1 * ) & V_43 -> V_170 ;
V_100 = V_171 ;
* V_169 = F_2 ( V_2 , V_100 ) ;
* V_169 |= V_167 ;
* V_169 &= ~ V_168 ;
F_3 ( V_2 , V_100 , * V_169 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
F_58 ( V_2 , V_171 , 0x1010 ) ;
V_43 -> V_170 = 0x1010 ;
F_58 ( V_2 , V_172 , 0x6404 ) ;
if ( F_59 ( & V_2 -> V_173 , V_174 ) == false )
F_3 ( V_2 , V_175 ,
V_176 ) ;
F_3 ( V_2 , V_177 , V_178 ) ;
F_58 ( V_2 , V_179 , 0x660F ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
F_5 ( V_180 , V_33 , ( L_57 ) ) ;
V_43 -> V_181 |= F_16 ( 6 ) ;
F_3 ( V_2 , V_182 + 2 ,
V_43 -> V_181 ) ;
F_3 ( V_2 , V_172 + 1 , 0xff ) ;
V_43 -> V_183 |= F_16 ( 0 ) ;
F_3 ( V_2 , V_172 + 2 , V_43 -> V_183 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
F_5 ( V_180 , V_33 , ( L_58 ) ) ;
V_43 -> V_181 &= ~ F_16 ( 6 ) ;
F_3 ( V_2 , V_182 + 2 ,
V_43 -> V_181 ) ;
F_3 ( V_2 , V_172 + 1 , 0x64 ) ;
V_43 -> V_183 &= ~ F_16 ( 0 ) ;
F_3 ( V_2 , V_172 + 2 , V_43 -> V_183 ) ;
F_62 ( V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_1 V_184 ,
T_1 V_185 )
{
F_56 ( V_2 , V_186 | V_187 | V_188 ,
0 ) ;
F_3 ( V_2 , V_189 + 1 , 0x6F ) ;
}
void F_64 ( struct V_1 * V_2 )
{
T_2 V_35 ;
struct V_190 * V_191 = & V_2 -> V_192 ;
struct V_193 * V_194 = & V_191 -> V_195 ;
F_58 ( V_2 , V_196 , 2 ) ;
F_58 ( V_2 , V_197 , V_194 -> V_198 ) ;
F_57 ( V_2 ) ;
F_3 ( V_2 , V_199 , 0x09 ) ;
V_35 = F_10 ( V_2 , V_200 ) ;
V_35 &= ~ V_201 ;
F_11 ( V_2 , V_200 , V_35 ) ;
V_35 |= V_201 ;
F_11 ( V_2 , V_200 , V_35 ) ;
if ( F_59 ( & V_2 -> V_173 , V_202 |
V_203 | V_204 ) == true ) {
F_3 ( V_2 , V_205 , 0x50 ) ;
F_3 ( V_2 , V_206 , 0x50 ) ;
}
F_63 ( V_2 , true , true ) ;
F_60 ( V_2 ) ;
F_56 ( V_2 , V_188 , 0 ) ;
}
void F_65 ( struct V_1 * V_207 ,
enum V_208 V_209 ,
void * V_210 , bool V_211 )
{
struct V_42 * V_43 = F_14 ( V_207 ) ;
struct V_212 * V_213 = & V_43 -> V_214 ;
switch ( V_209 ) {
case V_215 :
{
struct V_216 * V_217 = (struct V_216 * ) V_210 ;
if ( V_211 ) {
F_22 ( L_59 , V_217 -> V_218 ) ;
F_66 ( V_213 ,
V_219 ,
V_217 -> V_218 , V_217 ) ;
} else {
F_22 ( L_60 , V_217 -> V_218 ) ;
F_66 ( V_213 ,
V_219 ,
V_217 -> V_218 , NULL ) ;
}
}
break;
case V_220 :
F_67 ( V_213 , V_221 , V_211 ) ;
break;
case V_222 :
F_67 ( V_213 , V_223 , V_211 ) ;
break;
default:
break;
}
}
void F_68 ( struct V_1 * V_224 , bool V_3 )
{
if ( V_3 ) {
F_22 ( L_61 ) ;
F_3 ( V_224 , V_225 + 1 ,
F_2 ( V_224 , V_225 + 1 ) |
F_16 ( 1 ) ) ;
} else {
F_22 ( L_62 ) ;
F_3 ( V_224 , V_225 + 1 ,
F_2 ( V_224 , V_225 + 1 ) &
~ F_16 ( 1 ) ) ;
}
}
bool F_69 ( T_1 V_226 )
{
bool V_9 = false ;
if ( V_226 == V_227 )
V_9 = true ;
return V_9 ;
}
int F_70 ( struct V_1 * V_2 , struct V_228 * V_229 )
{
int V_9 = V_10 ;
T_1 V_20 = 0 ;
if ( V_229 == NULL ) {
F_22 ( L_63 , V_39 ) ;
V_9 = V_25 ;
goto exit;
}
switch ( V_229 -> V_226 ) {
case V_230 :
F_5 ( V_22 , V_33 ,
( L_64 , V_229 -> V_231 ) ) ;
break;
case V_227 :
F_71 ( V_2 , V_229 -> V_231 ) ;
break;
case V_232 :
break;
case V_233 :
F_5 ( V_22 , V_33 ,
( L_65 ) ) ;
for ( V_20 = 0 ; V_20 < V_229 -> V_234 ; V_20 ++ ) {
F_5 ( V_22 , V_33 ,
( L_66 , V_20 ,
V_229 -> V_231 [ V_20 ] ) ) ;
}
break;
case V_235 :
F_5 ( V_22 , V_33 ,
( L_67 ) ) ;
F_5 ( V_22 , V_33 ,
( L_68
L_69 , V_229 -> V_231 [ 0 ] ,
V_229 -> V_231 [ 1 ] , V_229 -> V_231 [ 2 ] ,
V_229 -> V_231 [ 3 ] , V_229 -> V_231 [ 4 ] ) ) ;
break;
case V_236 :
F_22 ( L_70 , V_39 ) ;
F_72 ( V_2 ,
V_229 -> V_231 , V_229 -> V_234 ) ;
break;
default:
V_9 = V_25 ;
break;
}
exit:
return V_9 ;
}
void F_73 ( struct V_1 * V_2 )
{
T_1 V_237 ;
V_237 = F_2 ( V_2 , V_238 ) ;
V_237 |= F_16 ( 7 ) ;
F_3 ( V_2 , V_238 , V_237 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
T_1 V_237 ;
V_237 = F_2 ( V_2 , V_238 ) ;
if ( ! ( V_237 & F_16 ( 7 ) ) ) {
V_237 |= F_16 ( 7 ) ;
F_3 ( V_2 , V_238 , V_237 ) ;
}
}
void F_75 ( struct V_1 * V_2 )
{
T_1 V_237 ;
V_237 = F_2 ( V_2 , V_238 ) ;
V_237 &= ~ F_16 ( 7 ) ;
F_3 ( V_2 , V_238 , V_237 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_239 * V_240 ;
T_1 V_20 ;
V_43 = F_14 ( V_2 ) ;
V_240 = & V_43 -> V_241 ;
V_43 -> V_242 = false ;
V_43 -> V_243 = false ;
if ( ! V_2 -> V_76 . V_244 )
V_43 -> V_78 = 0 ;
V_43 -> V_243 = false ;
V_240 -> V_245 = 0 ;
V_240 -> V_246 = 0 ;
for ( V_20 = 0 ; V_20 < V_247 ; V_20 ++ )
V_240 -> V_248 [ V_20 ] = 0 ;
V_43 -> V_106 = 0 ;
V_43 -> V_113 = 0 ;
}
T_1 F_77 ( struct V_1 * V_2 )
{
T_1 V_27 = 0 ;
T_2 V_249 ;
V_249 = F_78 ( V_2 , V_250 ) ;
V_27 = ( V_249 & V_251 ) ? 6 : 4 ;
F_55 ( L_71 , V_27 == 4 ? L_72 : L_73 ) ;
return V_27 ;
}
static int F_79 ( struct V_1 * V_2 , T_2 V_252 , T_2 V_67 )
{
int V_253 = V_10 ;
T_4 V_254 = 0 ;
T_2 V_255 = F_80 ( V_252 ) | F_81 ( V_67 ) |
F_82 ( V_256 ) ;
T_3 V_257 = V_258 ;
F_11 ( V_2 , V_257 , V_255 ) ;
do {
V_255 = F_10 ( V_2 , V_257 ) ;
if ( V_259 == F_83 ( V_255 ) ) {
break;
}
if ( V_254 > V_260 ) {
F_5 ( V_22 , V_38 ,
( L_74
L_75 , V_252 ) ) ;
V_253 = V_25 ;
break;
}
} while ( V_254 ++ );
return V_253 ;
}
int F_84 ( struct V_1 * V_2 , T_2 V_261 )
{
int V_253 = V_10 ;
T_2 V_20 ;
T_2 V_262 = V_261 ;
T_2 V_263 = V_264 ;
for ( V_20 = 0 ; V_20 < ( V_262 - 1 ) ; V_20 ++ ) {
V_253 = F_79 ( V_2 , V_20 , V_20 + 1 ) ;
if ( V_253 != V_10 ) {
return V_253 ;
}
}
V_253 = F_79 ( V_2 , ( V_262 - 1 ) , 0xFF ) ;
if ( V_253 != V_10 ) {
return V_253 ;
}
for ( V_20 = V_262 ; V_20 < V_263 ; V_20 ++ ) {
V_253 = F_79 ( V_2 , V_20 , ( V_20 + 1 ) ) ;
if ( V_10 != V_253 ) {
return V_253 ;
}
}
V_253 = F_79 ( V_2 , V_263 , V_262 ) ;
if ( V_253 != V_10 ) {
return V_253 ;
}
return V_253 ;
}
static void F_85 ( struct V_1 * V_2 )
{
T_2 V_35 ;
T_2 V_265 ;
F_58 ( V_2 , V_266 + 2 , 0x0000 ) ;
V_35 = F_10 ( V_2 , V_266 ) & 0xFFFF00FF ;
V_265 = V_35 & 0x000000FF ;
V_35 |= ( ( V_265 << 8 ) | 0x00FF0000 ) ;
F_11 ( V_2 , V_266 , V_35 ) ;
F_58 ( V_2 , V_267 , 0x0000 ) ;
V_35 = F_10 ( V_2 , V_268 ) & 0xFFFF001F ;
V_265 = V_35 & 0x0000001F ;
V_35 |= ( ( V_265 << 8 ) | 0x001D0000 ) ;
F_11 ( V_2 , V_268 , V_35 ) ;
F_58 ( V_2 , V_269 , 0x8080 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
T_1 V_270 = 0 , V_28 = 0 ;
F_3 ( V_2 , V_271 , 0xFF ) ;
F_87 ( V_2 , (enum V_272 ) V_270 , 0x0 , V_273 , 0x0 ) ;
V_28 |= V_274 ;
F_3 ( V_2 , V_275 , V_28 ) ;
V_28 = 0 ;
V_28 |= ( V_276 | V_277 | V_278 ) ;
F_3 ( V_2 , V_5 , V_28 ) ;
V_28 &= ~ V_278 ;
F_3 ( V_2 , V_5 , V_28 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_86 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
bool V_279 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
if ( F_15 ( V_2 ) && ( V_43 -> V_46 <= 0x20 ) ) {
T_3 V_280 = 0 ;
F_3 ( V_2 , V_6 , 0 ) ;
V_280 = F_78 ( V_2 , V_5 ) ;
F_58 ( V_2 , V_5 ,
V_280 & ( ~ V_281 ) ) ;
V_280 = F_78 ( V_2 , V_5 ) & 0x0FFF ;
F_58 ( V_2 , V_5 ,
V_280 | ( V_282 | V_283 ) ) ;
V_280 = F_78 ( V_2 , V_5 ) ;
F_58 ( V_2 , V_5 ,
V_280 | V_281 ) ;
} else {
T_1 V_284 = 0 ;
if ( F_2 ( V_2 , V_6 ) & F_16 ( 1 ) ) {
if ( V_2 -> V_285 ) {
F_3 ( V_2 , V_286 , 0x20 ) ;
F_3 ( V_2 , V_287 , 0x00 ) ;
F_3 ( V_2 , V_288 , 0x00 ) ;
F_3 ( V_2 , V_48 + 3 ,
0x20 ) ;
while ( ( V_284 ++ < 100 ) &&
( V_281 &
F_78 ( V_2 ,
V_5 ) ) ) {
F_12 ( 50 ) ;
}
if ( V_284 >= 100 ) {
F_3 ( V_2 ,
V_5 + 1 ,
0x50 ) ;
F_90 ( 10 ) ;
}
}
}
F_3 ( V_2 , V_5 + 1 , 0x54 ) ;
F_3 ( V_2 , V_6 , 0 ) ;
}
if ( V_279 ) {
F_58 ( V_2 , V_289 , 0x70A3 ) ;
F_3 ( V_2 , V_290 , 0x80 ) ;
F_58 ( V_2 , V_291 , 0x880F ) ;
F_3 ( V_2 , V_292 , 0xF9 ) ;
} else {
F_3 ( V_2 , V_293 , 0x00 ) ;
}
}
static void F_91 ( struct V_1 * V_2 ,
bool V_279 )
{
F_89 ( V_2 , V_279 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_58 ( V_2 , V_289 , 0x70a3 ) ;
F_3 ( V_2 , V_292 + 1 , 0x82 ) ;
}
static void F_93 ( struct V_1 * V_2 , bool V_279 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
T_3 V_294 = 0 ;
T_1 V_28 = 0 ;
if ( V_279 ) {
F_3 ( V_2 , V_295 , 0x04 ) ;
V_28 = F_2 ( V_2 , V_296 ) ;
V_28 &= ( ~ V_297 ) ;
F_3 ( V_2 , V_296 , V_28 ) ;
}
V_28 = 0x23 ;
if ( F_94 ( V_43 -> V_64 ) )
V_28 |= F_16 ( 3 ) ;
F_3 ( V_2 , V_298 , V_28 ) ;
if ( V_279 ) {
V_294 |= ( V_299 | V_300 | V_301 ) ;
} else {
V_294 |= ( V_299 | V_300 | V_301 ) ;
}
F_58 ( V_2 , V_302 , V_294 ) ;
F_3 ( V_2 , V_303 , 0x0e ) ;
}
int F_95 ( struct V_1 * V_2 , T_1 V_304 )
{
int V_49 = V_10 ;
if ( V_2 -> V_305 ) {
return V_49 ;
}
F_88 ( V_2 ) ;
F_91 ( V_2 , false ) ;
F_85 ( V_2 ) ;
F_93 ( V_2 , false ) ;
F_5 ( V_180 , V_33 ,
( L_76 ) ) ;
return V_49 ;
}
int F_96 ( struct V_1 * V_2 )
{
int V_49 = V_10 ;
if ( V_2 -> V_305 ) {
return V_49 ;
}
F_88 ( V_2 ) ;
F_91 ( V_2 , true ) ;
F_85 ( V_2 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 , true ) ;
return V_49 ;
}
void F_97 ( struct V_1 * V_2 , T_1 * V_306 )
{
struct V_307 * V_308 = F_98 ( V_2 ) ;
if ( false == V_308 -> V_309 ) {
if ( ! V_308 -> V_310 ) {
F_99 ( V_2 , V_104 ) ;
memcpy ( ( void * ) V_306 ,
( void * ) V_308 -> V_311 ,
V_312 ) ;
}
} else {
F_5 ( V_180 , V_23 ,
( L_77 ) ) ;
if ( false == V_308 -> V_310 )
F_99 ( V_2 , V_104 ) ;
memcpy ( ( void * ) V_306 , ( void * ) V_308 -> V_311 ,
V_312 ) ;
}
}
void F_100 ( struct V_1 * V_2 , T_1 * V_313 )
{
struct V_307 * V_308 = F_98 ( V_2 ) ;
T_3 V_314 ;
V_314 = F_29 ( * ( ( T_3 * ) V_313 ) ) ;
if ( V_314 != V_315 ) {
F_22 ( L_78 , V_314 ) ;
V_308 -> V_309 = true ;
} else {
V_308 -> V_309 = false ;
}
F_5 ( V_22 , V_33 ,
( L_79 , V_314 ) ) ;
}
static void F_101 ( T_1 V_316 , void * V_317 , void * V_318 )
{
switch ( V_316 ) {
case V_319 :
{
T_1 * V_320 , * V_321 ;
V_320 = ( T_1 * ) V_317 ;
V_321 = ( T_1 * ) V_318 ;
if ( * V_320 <= 63 )
* V_321 = * V_320 ;
else {
F_5 ( V_180 , V_38 ,
( L_80
L_81 ,
* V_320 , V_322 ) ) ;
* V_321 = V_322 ;
}
}
break;
default:
break;
}
}
static void
F_102 ( struct V_323 * V_324 ,
T_1 * V_306 , bool V_325 )
{
T_2 V_326 , V_327 , V_328 , V_329 = 1 ;
memset ( V_324 , 0 , sizeof( * V_324 ) ) ;
if ( V_325 ) {
for ( V_328 = 0 ; V_328 < V_330 ; V_328 ++ ) {
for ( V_326 = 0 ; V_326 < V_329 ; V_326 ++ ) {
V_324 -> V_331 [ V_326 ] [ V_328 ] =
V_322 ;
V_324 -> V_332 [ V_326 ] [ V_328 ] =
V_322 ;
V_324 -> V_333 [ V_326 ] [ V_328 ] =
V_334 ;
V_324 -> V_335 [ V_326 ] [ V_328 ] =
V_336 ;
V_324 -> V_337 [ V_326 ] [ V_328 ] =
V_338 ;
V_324 -> V_339 [ V_326 ] [ V_328 ] =
V_340 ;
V_324 -> V_341 [ V_326 ] [ V_328 ] =
V_342 ;
}
}
V_324 -> V_343 [ 0 ] = V_344 ;
return;
}
for ( V_326 = 0 ; V_326 < V_329 ; V_326 ++ ) {
for ( V_328 = 0 ; V_328 < V_330 ; V_328 ++ ) {
V_327 =
V_345 + ( V_326 * 3 ) + V_328 ;
F_101 ( V_319 , & V_306 [ V_327 ] ,
& V_324 -> V_331 [ V_326 ] [ V_328 ] ) ;
V_327 = V_346 +
( V_326 * 3 ) + V_328 ;
F_101 ( V_319 , & V_306 [ V_327 ] ,
& V_324 -> V_332 [ V_326 ] [ V_328 ] ) ;
}
}
for ( V_328 = 0 ; V_328 < V_330 ; V_328 ++ ) {
for ( V_326 = 0 ; V_326 < V_329 ; V_326 ++ ) {
V_324 -> V_333 [ V_326 ] [ V_328 ] = 0 ;
V_324 -> V_335 [ V_326 ] [ V_328 ] =
( V_306
[ V_347 +
V_328 ] >> ( V_326 * 4 ) ) & 0xF ;
if ( V_324 -> V_335 [ V_326 ] [ V_328 ] & F_16 ( 3 ) )
V_324 -> V_335 [ V_326 ] [ V_328 ] |= 0xF0 ;
V_324 -> V_337 [ V_326 ] [ V_328 ] =
( V_306 [ V_348 +
V_328 ] >> ( V_326 * 4 ) ) & 0xF ;
V_324 -> V_339 [ V_326 ] [ V_328 ] =
( V_306 [ V_349 +
V_328 ] >> ( V_326 * 4 ) ) & 0xF ;
V_324 -> V_341 [ V_326 ] [ V_328 ] =
( V_306 [ V_350 +
V_328 ] >> ( V_326 * 4 ) ) & 0xF ;
}
}
V_324 -> V_343 [ 0 ] = V_306 [ V_351 ] ;
}
static T_1 F_103 ( T_1 V_352 )
{
T_1 V_328 = 0 ;
if ( V_352 < 3 )
V_328 = 0 ;
else if ( V_352 < 9 )
V_328 = 1 ;
else
V_328 = 2 ;
return V_328 ;
}
void
F_104 ( struct V_1 * V_2 ,
T_1 * V_306 , bool V_325 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
struct V_323 V_324 ;
T_1 V_326 , V_353 , V_328 , V_329 = 1 ;
T_1 V_354 , V_355 ;
F_102 ( & V_324 , V_306 , V_325 ) ;
for ( V_326 = 0 ; V_326 < V_329 ; V_326 ++ ) {
for ( V_353 = 0 ; V_353 < V_356 ; V_353 ++ ) {
V_328 = F_103 ( V_353 ) ;
V_43 -> V_357 [ V_326 ] [ V_353 ] =
V_324 . V_331 [ V_326 ] [ V_328 ] ;
V_43 -> V_358 [ V_326 ] [ V_353 ] =
V_324 . V_332 [ V_326 ] [ V_328 ] ;
V_43 -> V_359 [ V_326 ] [ V_353 ] =
V_324 . V_335 [ V_326 ] [ V_328 ] ;
V_43 -> V_360 [ V_326 ] [ V_353 ] =
V_324 . V_337 [ V_326 ] [ V_328 ] ;
V_43 -> V_361 [ V_326 ] [ V_353 ] =
V_324 . V_341 [ V_326 ] [ V_328 ] ;
V_43 -> V_362 [ V_326 ] [ V_353 ] =
V_324 . V_339 [ V_326 ] [ V_328 ] ;
V_354 = V_324 . V_332 [ V_326 ] [ V_328 ] ;
V_355 = V_324 . V_333 [ V_326 ] [ V_328 ] ;
V_43 -> V_363 [ V_326 ] [ V_353 ] =
( V_354 > V_355 ) ? ( V_354 - V_355 ) : 0 ;
}
}
for ( V_326 = 0 ; V_326 < V_364 ; V_326 ++ ) {
for ( V_353 = 0 ; V_353 < V_356 ; V_353 ++ ) {
F_5 ( V_180 , V_33 ,
( L_82
L_83 ,
V_326 , V_353 ,
V_43 -> V_357 [ V_326 ] [ V_353 ] ,
V_43 -> V_358 [ V_326 ] [ V_353 ] ,
V_43 -> V_363 [ V_326 ] [ V_353 ] ) ) ;
}
}
for ( V_353 = 0 ; V_353 < V_356 ; V_353 ++ ) {
F_5 ( V_180 , V_33 ,
( L_84 , V_353 ,
V_43 -> V_359 [ V_365 ] [ V_353 ] ,
V_43 -> V_359 [ V_365 ] [ V_353 ] ) ) ;
}
for ( V_353 = 0 ; V_353 < V_356 ; V_353 ++ )
F_5 ( V_180 , V_33 ,
( L_85 , V_353 ,
V_43 -> V_360 [ V_365 ] [ V_353 ] ) ) ;
for ( V_353 = 0 ; V_353 < V_356 ; V_353 ++ ) {
F_5 ( V_180 , V_33 ,
( L_86 , V_353 ,
V_43 -> V_359 [ V_366 ] [ V_353 ] ,
V_43 -> V_359 [ V_366 ] [ V_353 ] ) ) ;
}
for ( V_353 = 0 ; V_353 < V_356 ; V_353 ++ )
F_5 ( V_180 , V_33 ,
( L_87 , V_353 ,
V_43 -> V_360 [ V_366 ] [ V_353 ] ) ) ;
if ( ! V_325 ) {
struct V_367 * V_368 = & V_2 -> V_65 ;
if ( V_368 -> V_369 == 0xff ) {
if ( V_306 [ V_370 ] == 0xff )
V_43 -> V_371 = 0 ;
else
V_43 -> V_371 =
V_306 [ V_370 ] & 0x7 ;
} else {
V_43 -> V_371 =
V_368 -> V_369 ;
}
} else {
V_43 -> V_371 = 0 ;
}
F_5 ( V_180 , V_33 ,
( L_88 , V_43 -> V_371 ) ) ;
if ( ! V_325 )
V_43 -> V_372 = true ;
}
void
F_105 ( struct V_1 * V_2 ,
T_1 * V_313 , bool V_325 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
T_1 V_373 ;
T_2 V_374 ;
if ( ! V_325 ) {
V_374 = F_10 ( V_2 , V_152 ) ;
if ( V_374 & V_155 )
V_43 -> V_375 = 1 ;
else
V_43 -> V_375 = 0 ;
V_43 -> V_376 = V_377 ;
V_373 = V_313 [ V_378 ] ;
V_43 -> V_379 = ( V_373 & 0x1 ) ;
V_43 -> V_380 = ( ( V_373 & 0x10 ) >> 4 ) ;
V_43 -> V_381 = ( ( V_373 & 0x20 ) >> 5 ) ;
} else {
V_43 -> V_375 = 0 ;
V_43 -> V_376 = V_377 ;
V_43 -> V_379 = V_382 ;
V_43 -> V_380 = 0 ;
V_43 -> V_381 = V_383 ;
}
F_106 ( V_2 ) ;
}
void
F_107 ( struct V_1 * V_2 ,
T_1 * V_313 , bool V_325 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
if ( ! V_325 )
V_43 -> V_384 = V_313 [ V_385 ] ;
else
V_43 -> V_384 = 1 ;
F_5 ( V_180 , V_33 ,
( L_89 ,
V_43 -> V_384 ) ) ;
}
void
F_108 ( struct V_1 * V_2 ,
T_1 * V_313 , bool V_325 )
{
V_2 -> V_173 . V_386 =
F_109 ( V_2 , V_313 ?
V_313 [ V_387 ] : 0xFF ,
V_2 -> V_65 . V_388 ,
V_389 ,
V_325 ) ;
F_22 ( L_90 ,
V_2 -> V_173 . V_386 ) ;
}
void
F_110 ( struct V_1 * V_2 ,
T_1 * V_313 , bool V_325 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
if ( ! V_325 ) {
V_43 -> V_390 = V_313 [ V_391 ] ;
V_43 -> V_392 =
V_313 [ V_393 ] ;
} else {
V_43 -> V_390 = 0 ;
V_43 -> V_392 = 0 ;
}
F_5 ( V_180 , V_33 ,
( L_91 , V_43 -> V_390 ) ) ;
F_5 ( V_180 , V_33 ,
( L_92 ,
V_43 -> V_392 ) ) ;
}
void
F_111 ( struct V_1 * V_2 ,
T_1 * V_313 , bool V_325 )
{
}
void
F_112 ( struct V_1 * V_2 ,
T_1 * V_313 , bool V_325 )
{
}
void
F_113 ( struct V_1 * V_394 ,
T_1 * V_313 , T_1 V_325 )
{
struct V_42 * V_43 = F_14 ( V_394 ) ;
if ( ! V_325 ) {
V_43 -> V_395 = V_313 [ V_396 ] ;
if ( V_43 -> V_395 == 0xFF )
V_43 -> V_395 = V_397 ;
} else {
V_43 -> V_395 = V_397 ;
}
F_5 ( V_180 , V_33 ,
( L_93 , V_39 ,
V_43 -> V_395 ) ) ;
}
void
F_114 ( struct V_1 * V_2 ,
T_1 * V_306 , bool V_398 )
{
struct V_42 * V_43 = F_14 ( V_2 ) ;
if ( V_398 == false )
V_43 -> V_399 =
V_306 [ V_400 ] ;
else
V_43 -> V_399 = V_401 ;
if ( ( V_43 -> V_399 == 0xff ) || ( V_398 == true ) ) {
V_43 -> V_402 = true ;
V_43 -> V_399 = V_401 ;
}
F_22 ( L_94 , V_39 ,
V_43 -> V_399 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
}
static void F_116 ( struct V_403 * V_404 )
{
T_3 * V_405 = ( T_3 * ) V_404 ;
T_2 V_254 = 16 ;
T_2 V_406 ;
T_3 V_407 = 0 ;
V_404 -> V_408 &= F_117 ( 0xffff0000 ) ;
for ( V_406 = 0 ; V_406 < V_254 ; V_406 ++ ) {
V_407 ^= F_29 ( * ( V_405 + V_406 ) ) ;
}
V_404 -> V_408 |= F_117 ( V_407 & 0x0000ffff ) ;
}
static void F_118 ( struct V_409 * V_410 ,
struct V_411 * V_404 )
{
if ( ( V_410 -> V_412 > 0 ) && ! V_410 -> V_413 ) {
switch ( V_410 -> V_412 ) {
case V_414 :
case V_415 :
case V_416 :
V_404 -> V_417 = 1 ;
break;
case V_418 :
V_404 -> V_417 = 3 ;
break;
case 0 :
default:
break;
}
}
}
static void F_119 ( struct V_409 * V_410 ,
struct V_411 * V_404 )
{
switch ( V_410 -> V_419 ) {
case V_420 :
V_404 -> V_421 = 1 ;
break;
case V_422 :
V_404 -> V_423 = 1 ;
break;
case V_424 :
default:
break;
}
if ( V_410 -> V_419 ) {
V_404 -> V_425 = 1 ;
if ( V_410 -> V_426 ) {
if ( V_410 -> V_427 & V_428 )
V_404 -> V_429 = 1 ;
switch ( V_410 -> V_430 ) {
case V_431 :
V_404 -> V_432 = 0 ;
break;
case V_433 :
V_404 -> V_432 = 1 ;
break;
case V_434 :
V_404 -> V_432 = 2 ;
break;
default:
V_404 -> V_432 = 3 ;
break;
}
}
}
}
static void F_120 ( struct V_409 * V_410 ,
struct V_411 * V_404 )
{
if ( V_410 -> V_426 ) {
if ( V_410 -> V_427 & V_428 )
V_404 -> V_435 = 1 ;
switch ( V_410 -> V_430 ) {
case V_431 :
V_404 -> V_436 = 0 ;
break;
case V_433 :
V_404 -> V_436 = 1 ;
break;
case V_434 :
V_404 -> V_436 = 2 ;
break;
default:
V_404 -> V_436 = 3 ;
break;
}
}
}
static void F_121 ( struct V_437 * V_438 ,
T_1 * V_89 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_239 * V_240 ;
struct V_190 * V_191 ;
struct V_193 * V_194 ;
struct V_409 * V_410 ;
struct V_411 * V_404 ;
T_4 V_439 ;
V_2 = V_438 -> V_2 ;
V_43 = F_14 ( V_2 ) ;
V_240 = & V_43 -> V_241 ;
V_191 = & V_2 -> V_192 ;
V_194 = & V_191 -> V_195 ;
V_410 = & V_438 -> V_440 ;
V_439 = F_122 ( V_410 -> V_441 ) ;
V_404 = (struct V_411 * ) V_89 ;
if ( V_438 -> V_442 == V_443 ) {
V_404 -> V_444 = V_410 -> V_218 ;
if ( V_410 -> V_445 == true )
V_404 -> V_446 = 1 ;
else
V_404 -> V_447 = 1 ;
V_404 -> V_448 = V_410 -> V_448 ;
V_404 -> V_449 = V_410 -> V_450 ;
F_118 ( V_410 , V_404 ) ;
V_404 -> V_451 = V_410 -> V_452 ;
if ( ( V_410 -> V_453 != 0x888e ) &&
( V_410 -> V_453 != 0x0806 ) &&
( V_410 -> V_454 != 1 ) ) {
F_119 ( V_410 , V_404 ) ;
F_120 ( V_410 , V_404 ) ;
V_404 -> V_455 = 8 ;
V_404 -> V_456 = 0x1F ;
V_404 -> V_457 = 0xF ;
V_404 -> V_458 =
V_240 -> V_459 [ V_410 -> V_218 ] ;
} else {
V_404 -> V_447 = 1 ;
V_404 -> V_460 = 1 ;
if ( V_194 -> V_461 == V_462 )
V_404 -> V_463 = 1 ;
V_404 -> V_458 = F_123 ( V_191 -> V_464 ) ;
}
} else if ( V_438 -> V_442 == V_465 ) {
V_404 -> V_444 = V_410 -> V_218 ;
V_404 -> V_448 = V_410 -> V_448 ;
V_404 -> V_449 = V_410 -> V_450 ;
V_404 -> V_451 = V_410 -> V_452 ;
V_404 -> V_460 = 1 ;
V_404 -> V_466 = 1 ;
V_404 -> V_467 = 6 ;
if ( V_438 -> V_468 )
V_404 -> V_469 = 1 ;
V_404 -> V_458 = F_123 ( V_191 -> V_464 ) ;
} else if ( V_438 -> V_442 == V_470 ) {
F_5 ( V_471 , V_472 ,
( L_95 , V_39 ) ) ;
} else {
F_5 ( V_471 , V_472 ,
( L_96 , V_39 ,
V_438 -> V_442 ) ) ;
V_404 -> V_444 = 4 ;
V_404 -> V_449 = 6 ;
V_404 -> V_451 = V_410 -> V_452 ;
V_404 -> V_460 = 1 ;
V_404 -> V_458 = F_123 ( V_191 -> V_464 ) ;
}
V_404 -> V_473 = V_410 -> V_474 ;
V_404 -> V_21 = V_475 + V_476 ;
if ( V_439 )
V_404 -> V_477 = 1 ;
V_404 -> V_478 = 1 ;
V_404 -> V_479 = 1 ;
V_404 -> V_480 = 1 ;
if ( ! V_410 -> V_481 ) {
V_404 -> V_482 = 1 ;
V_404 -> V_483 = 0 ;
}
}
void F_124 ( struct V_437 * V_438 , T_1 * V_89 )
{
struct V_403 * V_484 ;
V_484 = (struct V_403 * ) V_89 ;
memset ( V_484 , 0 , sizeof( struct V_403 ) ) ;
F_121 ( V_438 , V_89 ) ;
V_484 -> V_485 = F_117 ( V_484 -> V_485 ) ;
V_484 -> V_486 = F_117 ( V_484 -> V_486 ) ;
V_484 -> V_487 = F_117 ( V_484 -> V_487 ) ;
V_484 -> V_488 = F_117 ( V_484 -> V_488 ) ;
V_484 -> V_489 = F_117 ( V_484 -> V_489 ) ;
V_484 -> V_490 = F_117 ( V_484 -> V_490 ) ;
V_484 -> V_491 = F_117 ( V_484 -> V_491 ) ;
V_484 -> V_408 = F_117 ( V_484 -> V_408 ) ;
F_116 ( V_484 ) ;
}
void F_125 ( struct V_1 * V_2 , T_1 * V_492 ,
T_2 V_493 , T_1 V_494 , T_1 V_495 )
{
struct V_403 * V_404 ;
V_404 = (struct V_403 * ) V_492 ;
memset ( V_492 , 0 , V_475 ) ;
V_404 -> V_485 |= F_117 ( V_496 | V_497 | V_498 ) ;
V_404 -> V_485 |= F_117 ( ( ( V_475 + V_476 ) <<
V_499 ) & 0x00ff0000 ) ;
V_404 -> V_485 |= F_117 ( V_493 & 0x0000ffff ) ;
V_404 -> V_486 |= F_117 ( ( V_500 << V_501 ) & 0x00001f00 ) ;
if ( V_494 ) {
V_404 -> V_486 |= F_117 ( V_502 ) ;
} else {
V_404 -> V_489 |= F_117 ( F_16 ( 7 ) ) ;
V_404 -> V_488 |= F_117 ( ( 8 << 28 ) ) ;
}
if ( true == V_495 ) {
V_404 -> V_487 |= F_117 ( F_16 ( 23 ) ) ;
}
V_404 -> V_489 |= F_117 ( F_16 ( 8 ) ) ;
F_116 ( V_404 ) ;
}
void F_126 ( struct V_1 * V_2 , T_1 V_503 )
{
T_1 V_504 ;
if ( ( V_503 == V_505 ) || ( V_503 == V_506 ) ) {
F_61 ( V_2 ) ;
V_504 = V_186 | V_187 | V_507 ;
F_56 ( V_2 , V_504 , ~ V_504 ) ;
} else if ( ( V_503 == V_508 ) ) {
F_60 ( V_2 ) ;
V_504 = V_186 | V_187 | V_188 ;
F_56 ( V_2 , V_504 , ~ V_504 ) ;
} else if ( V_503 == V_509 ) {
F_127 ( V_2 ) ;
F_60 ( V_2 ) ;
V_504 = V_186 | V_188 ;
F_56 ( V_2 , V_504 , ~ V_504 ) ;
F_11 ( V_2 , V_510 , 0x7000228e ) ;
F_58 ( V_2 , V_511 , 0xFFFF ) ;
F_58 ( V_2 , V_512 , 0x0400 ) ;
F_3 ( V_2 , V_177 , 0x02 ) ;
F_3 ( V_2 , V_175 , 0x05 ) ;
F_3 ( V_2 , V_196 , 0x0a ) ;
F_58 ( V_2 , V_179 , 0x00 ) ;
F_58 ( V_2 , V_172 , 0xff04 ) ;
F_58 ( V_2 , V_513 , 0x7fff ) ;
F_3 ( V_2 , V_514 , F_16 ( 0 ) ) ;
V_504 = V_186 | V_187 |
V_515 | V_188 ;
F_56 ( V_2 , V_504 , ~ V_504 ) ;
}
V_504 = F_2 ( V_2 , V_516 ) ;
V_504 = ( V_504 & 0xC ) | V_503 ;
F_3 ( V_2 , V_516 , V_504 ) ;
}
void F_128 ( struct V_1 * V_2 , T_1 * V_237 )
{
T_1 V_517 = 0 ;
T_2 V_518 ;
V_518 = V_519 ;
for ( V_517 = 0 ; V_517 < 6 ; V_517 ++ )
F_3 ( V_2 , ( V_518 + V_517 ) , V_237 [ V_517 ] ) ;
}
void F_129 ( struct V_1 * V_2 , T_1 * V_237 )
{
T_1 V_517 = 0 ;
T_2 V_520 ;
V_520 = V_521 ;
for ( V_517 = 0 ; V_517 < 6 ; V_517 ++ )
F_3 ( V_2 , ( V_520 + V_517 ) , V_237 [ V_517 ] ) ;
}
void F_130 ( struct V_1 * V_2 )
{
T_5 V_522 ;
T_2 V_523 ;
struct V_190 * V_191 = & V_2 -> V_192 ;
struct V_193 * V_194 = & V_191 -> V_195 ;
V_522 = V_191 -> V_524 -
F_131 ( V_191 -> V_524 ,
( V_194 -> V_198 * 1024 ) ) - 1024 ;
if ( ( ( V_194 -> V_525 & 0x03 ) == V_526 ) ||
( ( V_194 -> V_525 & 0x03 ) == V_527 ) ) {
F_61 ( V_2 ) ;
}
V_523 = V_528 ;
F_56 ( V_2 , 0 , V_187 ) ;
F_11 ( V_2 , V_523 , V_522 ) ;
F_11 ( V_2 , V_523 + 4 , V_522 >> 32 ) ;
F_56 ( V_2 , V_187 , 0 ) ;
if ( ( ( V_194 -> V_525 & 0x03 ) == V_526 ) ||
( ( V_194 -> V_525 & 0x03 ) == V_527 ) )
F_60 ( V_2 ) ;
}
void F_132 ( struct V_1 * V_2 )
{
F_58 ( V_2 , V_511 , 0 ) ;
F_3 ( V_2 , V_514 , F_16 ( 0 ) ) ;
F_56 ( V_2 , V_186 , 0 ) ;
}
void F_133 ( struct V_1 * V_2 , T_1 type )
{
T_1 V_529 = 0x30 ;
struct V_42 * V_43 = F_14 ( V_2 ) ;
struct V_530 * V_531 = & V_2 -> V_173 ;
if ( type == 0 ) {
T_2 V_532 ;
F_58 ( V_2 , V_511 , 0xFFFF ) ;
V_532 = F_10 ( V_2 , V_510 ) ;
V_532 |= V_533 | V_534 ;
F_11 ( V_2 , V_510 , V_532 ) ;
if ( F_59 ( V_531 , V_174 ) == true )
V_529 =
( V_43 -> V_535 == V_536 ) ? 7 : 48 ;
else
V_529 = 0x7 ;
} else if ( type == 1 ) {
F_58 ( V_2 , V_511 , 0 ) ;
} else if ( type == 2 ) {
F_56 ( V_2 , 0 , V_186 ) ;
if ( F_59 ( V_531 ,
V_202 | V_203 ) ) {
F_3 ( V_2 , 0x542 , 0x02 ) ;
V_529 = 0x7 ;
}
}
F_58 ( V_2 , V_537 ,
V_529 << V_538 | V_529 <<
V_539 ) ;
switch ( type ) {
case 0 :
F_134 ( V_2 , true ) ;
break;
case 1 :
F_134 ( V_2 , false ) ;
break;
case 2 :
break;
}
}
