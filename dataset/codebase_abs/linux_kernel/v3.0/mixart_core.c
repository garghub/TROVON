static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 , V_5 ;
V_5 = F_2 ( F_3 ( V_2 , V_6 ) ) ;
V_4 = F_2 ( F_3 ( V_2 , V_7 ) ) ;
if ( V_5 == V_4 )
return 0 ;
if ( V_5 < V_8 )
return 0 ;
if ( V_5 >= V_8 + V_9 )
return 0 ;
* V_3 = F_2 ( F_3 ( V_2 , V_5 ) ) ;
V_5 += 4 ;
if( V_5 >= ( V_8 + V_9 ) )
V_5 = V_8 ;
F_4 ( V_5 , F_3 ( V_2 , V_6 ) ) ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 V_12 )
{
unsigned long V_13 ;
T_1 V_4 ;
T_1 V_14 ;
int V_15 ;
#ifndef F_6
unsigned int V_16 ;
#endif
F_7 ( & V_2 -> V_17 , V_13 ) ;
V_15 = 0 ;
V_14 = F_2 ( F_3 ( V_2 , V_12 ) ) ;
V_11 -> V_18 = F_2 ( F_3 ( V_2 , V_12 + 4 ) ) ;
V_11 -> V_19 . V_20 = F_2 ( F_3 ( V_2 , V_12 + 8 ) ) ;
V_11 -> V_19 . V_21 = F_2 ( F_3 ( V_2 , V_12 + 12 ) ) ;
if( ( V_14 < V_22 ) || ( V_11 -> V_14 < ( V_14 - V_22 ) ) ) {
V_15 = - V_23 ;
F_8 ( V_24 L_1 , V_14 ) ;
goto V_25;
}
V_14 -= V_22 ;
F_9 ( V_11 -> V_26 , F_3 ( V_2 , V_12 + V_27 ) , V_14 ) ;
V_11 -> V_14 = V_14 ;
#ifndef F_6
V_14 /= 4 ;
for( V_16 = 0 ; V_16 < V_14 ; V_16 ++ ) {
( ( T_1 * ) V_11 -> V_26 ) [ V_16 ] = F_10 ( ( ( T_1 * ) V_11 -> V_26 ) [ V_16 ] ) ;
}
#endif
V_4 = F_2 ( F_3 ( V_2 , V_28 ) ) ;
if( ( V_4 < V_29 ) || ( V_4 >= ( V_29 + V_9 ) ) ) {
V_15 = - V_23 ;
goto V_25;
}
F_4 ( V_12 , F_3 ( V_2 , V_4 ) ) ;
V_4 += 4 ;
if( V_4 >= ( V_29 + V_9 ) )
V_4 = V_29 ;
F_4 ( V_4 , F_3 ( V_2 , V_28 ) ) ;
V_25:
F_11 ( & V_2 -> V_17 , V_13 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_10 * V_30 ,
int V_31 ,
int V_32 ,
T_1 * V_33 )
{
T_1 V_4 , V_5 ;
T_1 V_12 ;
int V_15 , V_16 ;
if ( F_13 ( V_30 -> V_14 % 4 ) )
return - V_23 ;
V_15 = 0 ;
V_5 = F_2 ( F_3 ( V_2 , V_34 ) ) ;
V_4 = F_2 ( F_3 ( V_2 , V_35 ) ) ;
if ( V_5 == V_4 ) {
F_8 ( V_24 L_2 ) ;
return - V_36 ;
}
if( ( V_5 < V_37 ) || ( V_5 >= ( V_37 + V_9 ) ) ) {
return - V_23 ;
}
V_12 = F_2 ( F_3 ( V_2 , V_5 ) ) ;
F_14 ( 0 , F_3 ( V_2 , V_5 ) ) ;
V_5 += 4 ;
if( V_5 >= ( V_37 + V_9 ) )
V_5 = V_37 ;
F_4 ( V_5 , F_3 ( V_2 , V_34 ) ) ;
F_4 ( V_30 -> V_14 + V_22 , F_3 ( V_2 , V_12 ) ) ;
F_4 ( V_30 -> V_18 , F_3 ( V_2 , V_12 + 4 ) ) ;
F_4 ( V_30 -> V_19 . V_20 , F_3 ( V_2 , V_12 + 8 ) ) ;
F_4 ( V_30 -> V_19 . V_21 , F_3 ( V_2 , V_12 + 12 ) ) ;
F_4 ( V_22 , F_3 ( V_2 , V_12 + 16 ) ) ;
F_4 ( V_22 , F_3 ( V_2 , V_12 + 20 ) ) ;
F_4 ( V_30 -> V_14 , F_3 ( V_2 , V_12 + 24 ) ) ;
F_4 ( V_22 , F_3 ( V_2 , V_12 + 28 ) ) ;
F_4 ( 0 , F_3 ( V_2 , V_12 + 32 ) ) ;
F_4 ( V_22 + V_31 , F_3 ( V_2 , V_12 + 36 ) ) ;
for( V_16 = 0 ; V_16 < V_30 -> V_14 ; V_16 += 4 ) {
F_4 ( * ( T_1 * ) ( V_30 -> V_26 + V_16 ) , F_3 ( V_2 , V_27 + V_12 + V_16 ) ) ;
}
if( V_32 ) {
if( * V_33 ) {
V_2 -> V_38 = * V_33 ;
}
else {
V_2 -> V_38 = V_12 ;
* V_33 = V_12 ;
}
}
V_12 |= V_39 ;
V_4 = F_2 ( F_3 ( V_2 , V_40 ) ) ;
if( ( V_4 < V_41 ) || ( V_4 >= ( V_41 + V_9 ) ) ) {
return - V_23 ;
}
F_4 ( V_12 , F_3 ( V_2 , V_4 ) ) ;
V_4 += 4 ;
if( V_4 >= ( V_41 + V_9 ) )
V_4 = V_41 ;
F_4 ( V_4 , F_3 ( V_2 , V_40 ) ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_10 * V_42 , int V_43 , void * V_44 )
{
struct V_10 V_11 ;
T_1 V_3 = 0 ;
int V_15 ;
T_2 V_45 ;
long V_46 ;
F_16 ( & V_2 -> V_47 ) ;
F_17 ( & V_45 , V_48 ) ;
F_18 ( & V_2 -> V_17 ) ;
V_15 = F_12 ( V_2 , V_42 , V_43 , 1 , & V_3 ) ;
if ( V_15 ) {
F_19 ( & V_2 -> V_17 ) ;
F_20 ( & V_2 -> V_47 ) ;
return V_15 ;
}
F_21 ( V_49 ) ;
F_22 ( & V_2 -> V_50 , & V_45 ) ;
F_19 ( & V_2 -> V_17 ) ;
V_46 = F_23 ( V_51 ) ;
F_24 ( & V_2 -> V_50 , & V_45 ) ;
if ( ! V_46 ) {
F_20 ( & V_2 -> V_47 ) ;
F_8 ( V_24 L_3 , V_3 ) ;
return - V_52 ;
}
V_11 . V_18 = 0 ;
V_11 . V_19 = (struct V_53 ) { 0 , 0 } ;
V_11 . V_26 = V_44 ;
V_11 . V_14 = V_43 ;
V_15 = F_5 ( V_2 , & V_11 , V_3 ) ;
if( V_42 -> V_18 != V_11 . V_18 )
F_8 ( V_24 L_4 ) ;
F_20 ( & V_2 -> V_47 ) ;
return V_15 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_10 * V_42 , T_1 V_54 )
{
int V_15 ;
T_2 V_45 ;
long V_46 ;
if ( F_13 ( ! V_54 ) )
return - V_23 ;
if ( F_13 ( ( V_54 & V_55 ) != V_56 ) )
return - V_23 ;
if ( F_13 ( V_54 & V_57 ) )
return - V_23 ;
F_16 ( & V_2 -> V_47 ) ;
F_17 ( & V_45 , V_48 ) ;
F_18 ( & V_2 -> V_17 ) ;
V_15 = F_12 ( V_2 , V_42 , V_58 , 1 , & V_54 ) ;
if( V_15 ) {
F_19 ( & V_2 -> V_17 ) ;
F_20 ( & V_2 -> V_47 ) ;
return V_15 ;
}
F_21 ( V_49 ) ;
F_22 ( & V_2 -> V_50 , & V_45 ) ;
F_19 ( & V_2 -> V_17 ) ;
V_46 = F_23 ( V_51 ) ;
F_24 ( & V_2 -> V_50 , & V_45 ) ;
if ( ! V_46 ) {
F_20 ( & V_2 -> V_47 ) ;
F_8 ( V_24 L_5 , V_54 ) ;
return - V_52 ;
}
F_20 ( & V_2 -> V_47 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , struct V_10 * V_42 )
{
T_1 V_59 ;
unsigned long V_13 ;
int V_15 ;
F_7 ( & V_2 -> V_17 , V_13 ) ;
V_15 = F_12 ( V_2 , V_42 , V_58 , 0 , & V_59 ) ;
F_11 ( & V_2 -> V_17 , V_13 ) ;
F_27 ( & V_2 -> V_60 ) ;
return V_15 ;
}
void F_28 ( unsigned long V_61 )
{
struct V_1 * V_2 = ( struct V_1 * ) ( V_61 ) ;
struct V_10 V_11 ;
T_1 V_30 , V_62 , type ;
int V_15 ;
F_29 ( & V_2 -> V_63 ) ;
while ( V_2 -> V_64 != V_2 -> V_65 ) {
V_30 = V_2 -> V_66 [ V_2 -> V_64 ] ;
V_2 -> V_64 ++ ;
V_2 -> V_64 %= V_67 ;
V_62 = V_30 & ~ V_55 ;
type = V_30 & V_55 ;
switch ( type ) {
case V_68 :
V_11 . V_18 = 0 ;
V_11 . V_26 = V_69 ;
V_11 . V_14 = sizeof( V_69 ) ;
V_15 = F_5 ( V_2 , & V_11 , V_62 ) ;
if( V_15 < 0 ) {
F_8 ( V_24 L_6 , V_15 , V_30 ) ;
break;
}
switch( V_11 . V_18 ) {
case V_70 :
case V_71 :
case V_72 :
case V_73 :
if( V_69 [ 0 ] )
F_8 ( V_24 L_7 , V_69 [ 0 ] ) ;
break;
default:
F_30 ( L_8 ,
V_30 , V_11 . V_18 , V_11 . V_19 . V_20 , V_11 . V_19 . V_21 , V_11 . V_14 ) ;
break;
}
break;
case V_56 :
case V_74 :
default:
F_8 ( V_24 L_9 , V_30 ) ;
}
F_31 ( & V_2 -> V_60 ) ;
}
F_32 ( & V_2 -> V_63 ) ;
}
T_3 F_33 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
int V_15 ;
struct V_10 V_11 ;
T_1 V_30 ;
T_1 V_77 ;
F_29 ( & V_2 -> V_63 ) ;
V_77 = F_34 ( F_35 ( V_2 , V_78 ) ) ;
if( ! ( V_77 & V_79 ) ) {
F_32 ( & V_2 -> V_63 ) ;
return V_80 ;
}
F_36 ( V_81 , F_35 ( V_2 , V_82 ) ) ;
V_77 = F_37 ( F_35 ( V_2 , V_83 ) ) ;
F_14 ( V_77 , F_35 ( V_2 , V_83 ) ) ;
F_36 ( V_79 , F_35 ( V_2 , V_78 ) ) ;
while ( F_1 ( V_2 , & V_30 ) ) {
switch ( V_30 & V_55 ) {
case V_74 :
V_11 . V_18 = 0 ;
V_11 . V_26 = V_69 ;
V_11 . V_14 = sizeof( V_69 ) ;
V_15 = F_5 ( V_2 , & V_11 , V_30 & ~ V_55 ) ;
if( V_15 < 0 ) {
F_8 ( V_24 L_10 , V_15 , V_30 ) ;
break;
}
if( V_11 . V_18 == V_84 ) {
int V_16 ;
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_69 ;
for( V_16 = 0 ; V_16 < V_86 -> V_87 ; V_16 ++ ) {
T_1 V_88 = V_86 -> V_89 [ V_16 ] . V_88 ;
unsigned int V_90 = ( V_88 & V_91 ) >> V_92 ;
unsigned int V_93 = ( V_88 & V_94 ) >> V_95 ;
unsigned int V_96 = V_88 & V_97 ;
unsigned int V_98 = ( ( V_88 & V_99 ) != 0 ) ;
struct V_100 * V_101 = V_2 -> V_101 [ V_90 ] ;
struct V_102 * V_103 ;
if ( ( V_90 >= V_2 -> V_104 ) || ( V_93 >= V_105 ) || ( V_96 >= V_106 ) ) {
F_8 ( V_24 L_11 ,
V_88 , V_86 -> V_89 [ V_16 ] . V_107 ) ;
break;
}
if ( V_98 )
V_103 = & V_101 -> V_108 [ V_93 ] ;
else
V_103 = & V_101 -> V_109 [ V_93 ] [ V_96 ] ;
if ( V_103 -> V_110 && ( V_103 -> V_111 == V_112 ) ) {
struct V_113 * V_114 = V_103 -> V_110 -> V_114 ;
int V_115 = 0 ;
T_4 V_116 = ( ( T_4 ) V_86 -> V_89 [ V_16 ] . V_117 ) << 32 ;
V_116 |= V_86 -> V_89 [ V_16 ] . V_107 ;
while ( 1 ) {
T_4 V_118 = V_103 -> V_119 + V_114 -> V_120 ;
if ( V_118 > V_116 ) {
break;
}
else {
V_115 = 1 ;
V_103 -> V_121 ++ ;
if ( V_103 -> V_121 >= V_114 -> V_122 )
V_103 -> V_121 = 0 ;
V_103 -> V_119 = V_118 ;
}
}
V_103 -> V_123 = ( T_1 ) ( V_116 - V_103 -> V_119 ) ;
if( V_115 ) {
F_32 ( & V_2 -> V_63 ) ;
F_38 ( V_103 -> V_110 ) ;
F_29 ( & V_2 -> V_63 ) ;
}
}
}
break;
}
if( V_11 . V_18 == V_124 ) {
if( V_11 . V_14 > 1 ) {
#ifndef F_6
int V_16 ;
for( V_16 = 0 ; V_16 < ( V_11 . V_14 / 4 ) ; V_16 ++ ) {
( V_69 ) [ V_16 ] = F_39 ( ( V_69 ) [ V_16 ] ) ;
}
#endif
( ( char * ) V_69 ) [ V_11 . V_14 - 1 ] = 0 ;
F_30 ( L_12 , ( char * ) V_69 ) ;
}
break;
}
F_30 ( L_13 , V_11 . V_18 ) ;
break;
case V_56 :
if( V_30 & V_57 ) {
V_30 &= ~ V_57 ;
F_8 ( V_24 L_14 , V_30 ) ;
}
case V_68 :
F_29 ( & V_2 -> V_17 ) ;
if( ( V_30 & ~ V_55 ) == V_2 -> V_38 ) {
F_40 ( & V_2 -> V_50 ) ;
V_2 -> V_38 = 0 ;
}
else {
V_2 -> V_66 [ V_2 -> V_65 ] = V_30 ;
V_2 -> V_65 ++ ;
V_2 -> V_65 %= V_67 ;
F_41 ( & V_2 -> V_125 ) ;
}
F_32 ( & V_2 -> V_17 ) ;
break;
case V_39 :
default:
F_30 ( L_15 , V_30 ) ;
break;
}
}
F_36 ( V_126 , F_35 ( V_2 , V_82 ) ) ;
F_32 ( & V_2 -> V_63 ) ;
return V_127 ;
}
void F_42 ( struct V_1 * V_2 )
{
F_14 ( 0 , F_3 ( V_2 , V_128 ) ) ;
F_14 ( 0 , F_3 ( V_2 , V_129 ) ) ;
if( V_2 -> V_75 >= 0 ) {
F_36 ( V_126 , F_35 ( V_2 , V_82 ) ) ;
}
return;
}
void F_43 ( struct V_1 * V_2 )
{
F_36 ( V_81 , F_35 ( V_2 , V_82 ) ) ;
return;
}
void F_44 ( struct V_1 * V_2 )
{
F_4 ( 1 , F_35 ( V_2 , V_130 ) ) ;
return;
}
