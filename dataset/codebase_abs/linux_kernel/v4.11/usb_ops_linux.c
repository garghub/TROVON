T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( 0 , V_4 ) ;
if ( ! V_2 -> V_3 )
return V_5 ;
F_3 ( & V_2 -> V_6 ) ;
return V_7 ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_5 ( V_2 -> V_3 ) ;
F_6 ( V_2 -> V_3 ) ;
}
}
static unsigned int F_7 ( struct V_8 * V_9 , T_2 V_10 )
{
unsigned int V_11 = 0 ;
struct V_12 * V_13 = V_9 -> V_14 ;
if ( V_9 -> V_15 == 11 ) {
switch ( V_10 ) {
case V_16 :
V_11 = F_8 ( V_13 , 0x07 ) ;
break;
case V_17 :
V_11 = F_8 ( V_13 , 0x06 ) ;
break;
case V_18 :
V_11 = F_8 ( V_13 , 0x05 ) ;
break;
case V_19 :
V_11 = F_8 ( V_13 , 0x04 ) ;
break;
case V_20 :
V_11 = F_8 ( V_13 , 0x0a ) ;
break;
case V_21 :
V_11 = F_8 ( V_13 , 0x0b ) ;
break;
case V_22 :
V_11 = F_8 ( V_13 , 0x0c ) ;
break;
case V_23 :
V_11 = F_9 ( V_13 , 0x03 ) ;
break;
case V_24 :
V_11 = F_9 ( V_13 , 0x09 ) ;
break;
case V_25 :
V_11 = F_8 ( V_13 , 0x0d ) ;
break;
}
} else if ( V_9 -> V_15 == 6 ) {
switch ( V_10 ) {
case V_16 :
V_11 = F_8 ( V_13 , 0x07 ) ;
break;
case V_17 :
V_11 = F_8 ( V_13 , 0x06 ) ;
break;
case V_18 :
V_11 = F_8 ( V_13 , 0x05 ) ;
break;
case V_19 :
V_11 = F_8 ( V_13 , 0x04 ) ;
break;
case V_23 :
case V_24 :
V_11 = F_9 ( V_13 , 0x03 ) ;
break;
case V_25 :
case V_20 :
case V_21 :
case V_22 :
V_11 = F_8 ( V_13 , 0x0d ) ;
break;
}
} else if ( V_9 -> V_15 == 4 ) {
switch ( V_10 ) {
case V_17 :
V_11 = F_8 ( V_13 , 0x06 ) ;
break;
case V_19 :
V_11 = F_8 ( V_13 , 0x04 ) ;
break;
case V_23 :
case V_24 :
V_11 = F_9 ( V_13 , 0x03 ) ;
break;
case V_25 :
case V_20 :
case V_21 :
case V_22 :
V_11 = F_8 ( V_13 , 0x0d ) ;
break;
}
} else {
V_11 = 0 ;
}
return V_11 ;
}
static void F_10 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_27 -> V_30 ;
struct V_31 * V_32 = & ( V_29 -> V_33 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_34 * V_35 = (struct V_34 * ) V_32 -> V_36 ;
if ( V_27 -> V_37 != 0 ) {
if ( V_27 -> V_37 == ( - V_38 ) )
V_35 -> V_39 = true ;
else
V_35 -> V_40 = true ;
}
F_11 ( & V_2 -> V_6 ) ;
}
void F_12 ( struct V_31 * V_41 , T_2 V_10 , T_2 V_42 , T_3 * V_43 )
{
unsigned int V_11 ;
struct V_34 * V_35 = (struct V_34 * ) V_41 -> V_36 ;
struct V_1 * V_2 = V_41 -> V_2 ;
struct V_28 * V_44 = V_35 -> V_44 ;
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_45 ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_26 * V_3 = V_2 -> V_3 ;
if ( ( V_35 -> V_39 ) || ( V_35 -> V_40 ) ||
( V_35 -> V_46 . V_47 ) )
return;
V_11 = F_7 ( V_9 , V_10 ) ;
if ( V_11 == 0 )
return;
F_13 ( V_3 , V_13 , V_11 ,
V_43 , V_42 , F_10 ,
V_44 ) ;
F_14 ( V_3 , V_4 ) ;
F_15 ( & V_2 -> V_6 ) ;
}
static void F_16 ( struct V_26 * V_27 )
{
T_1 V_48 ;
T_4 * V_49 ;
struct V_50 * V_51 = (struct V_50 * ) V_27 -> V_30 ;
struct V_34 * V_35 = (struct V_34 * ) V_51 -> V_36 ;
struct V_52 * V_53 = & V_35 -> V_54 ;
if ( V_35 -> V_40 || V_35 -> V_39 )
return;
if ( V_27 -> V_37 == 0 ) {
if ( ( V_27 -> V_55 > ( V_56 ) ) ||
( V_27 -> V_55 < V_57 ) ) {
F_17 ( V_35 , V_53 -> V_58 , 0 ,
( unsigned char * ) V_51 ) ;
} else {
T_5 * V_59 = V_51 -> V_59 ;
V_51 -> V_60 = V_27 -> V_55 ;
V_49 = ( T_4 * ) V_51 -> V_49 ;
V_48 = F_18 ( * ( V_49 + 1 ) ) & 0x1ff ;
if ( ( V_48 & 0x1ff ) == 0x1ff ) {
F_19 ( V_35 , V_49 ) ;
F_20 ( & V_53 -> V_61 , V_59 ) ;
F_17 ( V_35 , V_53 -> V_58 ,
0 , ( unsigned char * ) V_51 ) ;
} else {
F_21 ( V_59 , V_27 -> V_55 ) ;
F_20 ( & V_53 -> V_61 , V_59 ) ;
F_22 ( & V_53 -> V_62 ) ;
F_17 ( V_35 , V_53 -> V_58 ,
0 , ( unsigned char * ) V_51 ) ;
}
}
} else {
switch ( V_27 -> V_37 ) {
case - V_63 :
case - V_64 :
case - V_65 :
case - V_38 :
V_35 -> V_39 = true ;
break;
case - V_66 :
if ( ! V_35 -> V_67 ) {
V_35 -> V_39 = true ;
break;
}
case - V_68 :
F_17 ( V_35 , V_53 -> V_58 , 0 ,
( unsigned char * ) V_51 ) ;
break;
case - V_69 :
F_23 ( V_35 -> V_70 , L_1 ) ;
break;
default:
break;
}
}
}
T_2 F_24 ( struct V_31 * V_41 , T_2 V_10 , T_2 V_42 , T_3 * V_71 )
{
unsigned int V_11 ;
int V_72 ;
T_2 V_73 = 0 ;
int V_74 = 0 ;
T_2 V_75 = V_7 ;
struct V_26 * V_27 = NULL ;
struct V_50 * V_51 = (struct V_50 * ) V_71 ;
struct V_1 * V_2 = V_41 -> V_2 ;
struct V_8 * V_9 = (struct V_8 * ) V_2 -> V_45 ;
struct V_34 * V_36 = V_9 -> V_35 ;
struct V_52 * V_53 = & V_36 -> V_54 ;
struct V_12 * V_13 = V_9 -> V_14 ;
if ( V_36 -> V_39 || V_36 -> V_40 ||
V_36 -> V_46 . V_47 || ! V_51 )
return V_5 ;
F_25 ( V_36 , V_51 ) ;
V_51 -> V_59 = F_26 ( & V_53 -> V_76 ) ;
if ( ! V_51 -> V_59 ) {
V_51 -> V_59 = F_27 ( V_36 -> V_70 ,
V_56 + V_77 ) ;
if ( ! V_51 -> V_59 )
return V_5 ;
V_73 = ( V_78 ) V_51 -> V_59 -> V_79 ;
V_74 = V_73 & ( V_77 - 1 ) ;
F_28 ( V_51 -> V_59 ,
( V_77 - V_74 ) ) ;
V_51 -> V_80 = V_51 -> V_59 -> V_81 ;
V_51 -> V_82 = V_51 -> V_59 -> V_79 ;
V_51 -> V_83 = F_29 ( V_51 -> V_59 ) ;
V_51 -> V_84 = F_30 ( V_51 -> V_59 ) ;
V_51 -> V_49 = V_51 -> V_59 -> V_79 ;
} else {
V_51 -> V_80 = V_51 -> V_59 -> V_81 ;
V_51 -> V_82 = V_51 -> V_59 -> V_79 ;
V_51 -> V_83 = F_29 ( V_51 -> V_59 ) ;
V_51 -> V_84 = F_30 ( V_51 -> V_59 ) ;
V_51 -> V_49 = V_51 -> V_59 -> V_79 ;
}
V_27 = V_51 -> V_27 ;
V_11 = F_7 ( V_9 , V_10 ) ;
F_13 ( V_27 , V_13 , V_11 ,
V_51 -> V_49 , V_56 ,
F_16 ,
V_51 ) ;
V_72 = F_14 ( V_27 , V_4 ) ;
if ( ( V_72 ) && ( V_72 != ( - V_85 ) ) )
V_75 = V_5 ;
return V_75 ;
}
void F_31 ( struct V_34 * V_35 )
{
int V_86 ;
struct V_50 * V_51 ;
V_51 = (struct V_50 * ) V_35 -> V_54 . V_87 ;
for ( V_86 = 0 ; V_86 < V_88 ; V_86 ++ ) {
if ( V_51 -> V_27 )
F_5 ( V_51 -> V_27 ) ;
V_51 ++ ;
}
}
void F_32 ( void * V_89 )
{
int V_75 = false ;
struct V_34 * V_35 = V_89 ;
struct V_90 * V_91 = & V_35 -> V_92 ;
if ( V_35 -> V_39 ||
V_35 -> V_40 ) {
F_23 ( V_35 -> V_70 , L_2 ) ;
return;
}
V_75 = F_33 ( V_35 , V_91 , NULL ) ;
if ( ! V_75 )
return;
F_22 ( & V_91 -> V_93 ) ;
}
static void F_34 ( struct V_26 * V_27 )
{
int V_86 ;
struct V_94 * V_95 = (struct V_94 * ) V_27 -> V_30 ;
struct V_96 * V_97 = V_95 -> V_97 ;
struct V_34 * V_35 = V_95 -> V_35 ;
struct V_90 * V_91 = & V_35 -> V_92 ;
struct V_98 * V_99 = & V_95 -> V_100 ;
switch ( V_99 -> V_101 ) {
case 1 :
case 2 :
V_91 -> V_102 -- ;
break;
case 4 :
case 5 :
V_91 -> V_103 -- ;
break;
case 6 :
case 7 :
V_91 -> V_104 -- ;
break;
case 0 :
case 3 :
default:
V_91 -> V_105 -- ;
break;
}
V_91 -> V_106 -- ;
for ( V_86 = 0 ; V_86 < 8 ; V_86 ++ ) {
if ( V_27 == V_95 -> V_107 [ V_86 ] ) {
V_95 -> V_108 [ V_86 ] = false ;
break;
}
}
if ( V_35 -> V_40 )
return;
switch ( V_27 -> V_37 ) {
case 0 :
break;
default:
F_35 ( V_35 -> V_70 ,
L_3 , V_27 -> V_37 ) ;
break;
}
F_36 ( V_91 , V_95 ) ;
F_37 ( V_91 , V_97 ) ;
F_22 ( & V_91 -> V_93 ) ;
}
T_2 F_38 ( struct V_31 * V_41 , T_2 V_10 , T_2 V_42 , T_3 * V_43 )
{
unsigned long V_109 ;
int V_86 , V_37 ;
unsigned int V_11 ;
T_2 V_75 , V_110 ;
struct V_26 * V_27 = NULL ;
struct V_34 * V_35 = (struct V_34 * ) V_41 -> V_36 ;
struct V_8 * V_9 = & V_35 -> V_111 ;
struct V_90 * V_91 = & V_35 -> V_92 ;
struct V_94 * V_95 = (struct V_94 * ) V_43 ;
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_98 * V_99 = & V_95 -> V_100 ;
if ( ( V_35 -> V_39 ) || ( V_35 -> V_40 ) ||
( V_35 -> V_46 . V_47 ) )
return V_5 ;
for ( V_86 = 0 ; V_86 < 8 ; V_86 ++ ) {
if ( ! V_95 -> V_108 [ V_86 ] ) {
F_39 ( & V_91 -> V_112 , V_109 ) ;
V_91 -> V_106 ++ ;
V_95 -> V_108 [ V_86 ] = true ;
switch ( V_99 -> V_101 ) {
case 1 :
case 2 :
V_91 -> V_102 ++ ;
break;
case 4 :
case 5 :
V_91 -> V_103 ++ ;
break;
case 6 :
case 7 :
V_91 -> V_104 ++ ;
break;
case 0 :
case 3 :
default:
V_91 -> V_105 ++ ;
break;
}
F_40 ( & V_91 -> V_112 , V_109 ) ;
V_95 -> V_113 [ V_86 ] = ( V_114 ) V_42 ;
V_27 = V_95 -> V_107 [ V_86 ] ;
break;
}
}
V_110 = false ;
if ( V_9 -> V_115 ) {
if ( V_42 > 0 && V_42 % 512 == 0 )
V_110 = true ;
} else {
if ( V_42 > 0 && V_42 % 64 == 0 )
V_110 = true ;
}
V_11 = F_7 ( V_9 , V_10 ) ;
if ( V_91 -> V_116 % V_117 == 0 )
V_27 -> V_118 &= ( ~ V_119 ) ;
else
V_27 -> V_118 |= V_119 ;
if ( V_110 )
V_42 += 8 ;
F_13 ( V_27 , V_13 , V_11 ,
V_95 -> V_120 ,
V_42 , F_34 ,
V_95 ) ;
V_37 = F_14 ( V_27 , V_4 ) ;
if ( ! V_37 )
V_75 = V_7 ;
else
V_75 = V_5 ;
return V_75 ;
}
void F_41 ( struct V_34 * V_35 )
{
int V_86 , V_121 ;
struct V_96 * V_97 = (struct V_96 * )
V_35 -> V_92 . V_97 ;
for ( V_86 = 0 ; V_86 < V_117 ; V_86 ++ ) {
for ( V_121 = 0 ; V_121 < 8 ; V_121 ++ ) {
if ( V_97 -> V_107 [ V_121 ] )
F_5 ( V_97 -> V_107 [ V_121 ] ) ;
}
V_97 ++ ;
}
}
int F_42 ( struct V_1 * V_2 , T_3 V_122 , V_114 V_123 ,
V_114 V_124 , void * V_82 , V_114 V_125 , T_3 V_126 )
{
unsigned int V_11 ;
int V_37 ;
T_3 V_127 ;
struct V_8 * V_128 = (struct V_8 * )
V_2 -> V_45 ;
struct V_12 * V_129 = V_128 -> V_14 ;
T_3 * V_130 , * V_131 ;
V_130 = F_43 ( ( T_2 ) V_125 + 16 , V_4 ) ;
if ( ! V_130 )
return - V_132 ;
V_131 = V_130 + 16 - ( ( V_78 ) ( V_130 ) & 0x0f ) ;
if ( V_126 == 0x01 ) {
V_11 = F_44 ( V_129 , 0 ) ;
V_127 = V_133 ;
} else {
V_11 = F_45 ( V_129 , 0 ) ;
V_127 = V_134 ;
memcpy ( V_131 , V_82 , V_125 ) ;
}
V_37 = F_46 ( V_129 , V_11 , V_122 , V_127 , V_123 , V_124 ,
V_131 , V_125 , V_135 / 2 ) ;
if ( V_37 > 0 ) {
if ( V_126 == 0x01 ) {
memcpy ( V_82 , V_131 , V_37 ) ;
}
}
F_47 ( V_130 ) ;
return V_37 ;
}
