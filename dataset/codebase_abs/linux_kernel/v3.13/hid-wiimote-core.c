static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
T_1 * V_5 ;
int V_6 ;
if ( ! V_2 -> V_7 )
return - V_8 ;
V_5 = F_2 ( V_3 , V_4 , V_9 ) ;
if ( ! V_5 )
return - V_10 ;
V_6 = V_2 -> V_7 ( V_2 , V_5 , V_4 , V_11 ) ;
F_3 ( V_5 ) ;
return V_6 ;
}
static void F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_5 ( V_13 , struct V_14 ,
V_16 ) ;
struct V_17 * V_18 = F_5 ( V_15 , struct V_17 ,
V_15 ) ;
unsigned long V_19 ;
int V_6 ;
F_6 ( & V_18 -> V_15 . V_20 , V_19 ) ;
while ( V_18 -> V_15 . V_21 != V_18 -> V_15 . V_22 ) {
F_7 ( & V_18 -> V_15 . V_20 , V_19 ) ;
V_6 = F_1 ( V_18 -> V_2 ,
V_18 -> V_15 . V_23 [ V_18 -> V_15 . V_22 ] . V_24 ,
V_18 -> V_15 . V_23 [ V_18 -> V_15 . V_22 ] . V_25 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
F_8 ( V_18 ) ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
}
F_6 ( & V_18 -> V_15 . V_20 , V_19 ) ;
V_18 -> V_15 . V_22 = ( V_18 -> V_15 . V_22 + 1 ) % V_27 ;
}
F_7 ( & V_18 -> V_15 . V_20 , V_19 ) ;
}
static void V_14 ( struct V_17 * V_18 , const T_1 * V_3 ,
T_2 V_4 )
{
unsigned long V_19 ;
T_1 V_28 ;
if ( V_4 > V_29 ) {
F_9 ( V_18 -> V_2 , L_1 ) ;
F_6 ( & V_18 -> V_15 . V_20 , V_19 ) ;
goto V_30;
}
F_6 ( & V_18 -> V_15 . V_20 , V_19 ) ;
memcpy ( V_18 -> V_15 . V_23 [ V_18 -> V_15 . V_21 ] . V_24 , V_3 , V_4 ) ;
V_18 -> V_15 . V_23 [ V_18 -> V_15 . V_21 ] . V_25 = V_4 ;
V_28 = ( V_18 -> V_15 . V_21 + 1 ) % V_27 ;
if ( V_18 -> V_15 . V_21 == V_18 -> V_15 . V_22 ) {
V_18 -> V_15 . V_21 = V_28 ;
F_10 ( & V_18 -> V_15 . V_16 ) ;
} else if ( V_28 != V_18 -> V_15 . V_22 ) {
V_18 -> V_15 . V_21 = V_28 ;
} else {
F_9 ( V_18 -> V_2 , L_2 ) ;
goto V_30;
}
goto V_31;
V_30:
F_8 ( V_18 ) ;
V_31:
F_7 ( & V_18 -> V_15 . V_20 , V_19 ) ;
}
static inline void F_11 ( struct V_17 * V_18 , T_1 * V_32 )
{
if ( V_18 -> V_26 . V_19 & V_33 )
* V_32 |= 0x01 ;
}
void F_12 ( struct V_17 * V_18 , T_1 V_34 )
{
T_1 V_35 [ 2 ] ;
V_34 = ! ! V_34 ;
if ( V_34 == ! ! ( V_18 -> V_26 . V_19 & V_33 ) )
return;
if ( V_34 )
V_18 -> V_26 . V_19 |= V_33 ;
else
V_18 -> V_26 . V_19 &= ~ V_33 ;
V_35 [ 0 ] = V_36 ;
V_35 [ 1 ] = 0 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
void F_13 ( struct V_17 * V_18 , int V_37 )
{
T_1 V_35 [ 2 ] ;
V_37 &= V_38 ;
if ( ( V_18 -> V_26 . V_19 & V_38 ) == V_37 )
return;
V_18 -> V_26 . V_19 = ( V_18 -> V_26 . V_19 & ~ V_38 ) | V_37 ;
V_35 [ 0 ] = V_39 ;
V_35 [ 1 ] = 0 ;
if ( V_37 & V_40 )
V_35 [ 1 ] |= 0x10 ;
if ( V_37 & V_41 )
V_35 [ 1 ] |= 0x20 ;
if ( V_37 & V_42 )
V_35 [ 1 ] |= 0x40 ;
if ( V_37 & V_43 )
V_35 [ 1 ] |= 0x80 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
static T_1 F_14 ( struct V_17 * V_18 )
{
T_1 V_44 = V_18 -> V_26 . V_19 & V_45 ;
bool V_46 ;
V_46 = ( V_18 -> V_26 . V_19 & V_47 ) ||
( V_18 -> V_26 . V_19 & V_48 ) ;
if ( V_18 -> V_26 . V_49 == V_50 ) {
if ( V_46 )
return V_51 ;
else
return V_52 ;
}
if ( V_44 == V_53 ) {
if ( V_18 -> V_26 . V_19 & V_54 ) {
return V_55 ;
} else {
return V_56 ;
}
} else if ( V_44 == V_57 ) {
return V_58 ;
} else if ( V_44 == V_59 ) {
return V_60 ;
} else {
if ( V_18 -> V_26 . V_19 & V_54 ) {
if ( V_46 )
return V_61 ;
else
return V_62 ;
} else {
if ( V_46 )
return V_51 ;
else
return V_52 ;
}
}
}
void F_15 ( struct V_17 * V_18 , T_1 V_63 )
{
T_1 V_35 [ 3 ] ;
if ( V_18 -> V_26 . V_19 & V_64 )
V_63 = V_18 -> V_26 . V_63 ;
else if ( V_63 == V_65 )
V_63 = F_14 ( V_18 ) ;
V_35 [ 0 ] = V_66 ;
V_35 [ 1 ] = 0 ;
V_35 [ 2 ] = V_63 ;
V_18 -> V_26 . V_63 = V_63 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
void F_16 ( struct V_17 * V_18 )
{
T_1 V_35 [ 2 ] ;
V_35 [ 0 ] = V_67 ;
V_35 [ 1 ] = 0 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
void F_17 ( struct V_17 * V_18 , T_1 V_68 )
{
V_68 = ! ! V_68 ;
if ( V_68 == ! ! ( V_18 -> V_26 . V_19 & V_54 ) )
return;
if ( V_68 )
V_18 -> V_26 . V_19 |= V_54 ;
else
V_18 -> V_26 . V_19 &= ~ V_54 ;
F_15 ( V_18 , V_65 ) ;
}
void F_18 ( struct V_17 * V_18 , T_1 V_19 )
{
T_1 V_35 [ 2 ] ;
V_35 [ 0 ] = V_69 ;
V_35 [ 1 ] = V_19 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
void F_19 ( struct V_17 * V_18 , T_1 V_19 )
{
T_1 V_35 [ 2 ] ;
V_35 [ 0 ] = V_70 ;
V_35 [ 1 ] = V_19 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
static void F_20 ( struct V_17 * V_18 , bool V_71 ,
T_3 V_72 , const T_1 * V_5 , T_1 V_25 )
{
T_1 V_35 [ 22 ] ;
if ( V_25 > 16 || V_25 == 0 ) {
F_9 ( V_18 -> V_2 , L_3 , V_25 ) ;
return;
}
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
V_35 [ 0 ] = V_73 ;
V_35 [ 2 ] = ( V_72 >> 16 ) & 0xff ;
V_35 [ 3 ] = ( V_72 >> 8 ) & 0xff ;
V_35 [ 4 ] = V_72 & 0xff ;
V_35 [ 5 ] = V_25 ;
memcpy ( & V_35 [ 6 ] , V_5 , V_25 ) ;
if ( ! V_71 )
V_35 [ 1 ] |= 0x04 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
void F_21 ( struct V_17 * V_18 , bool V_71 , T_3 V_72 ,
T_4 V_25 )
{
T_1 V_35 [ 7 ] ;
if ( V_25 == 0 ) {
F_9 ( V_18 -> V_2 , L_4 , V_25 ) ;
return;
}
V_35 [ 0 ] = V_74 ;
V_35 [ 1 ] = 0 ;
V_35 [ 2 ] = ( V_72 >> 16 ) & 0xff ;
V_35 [ 3 ] = ( V_72 >> 8 ) & 0xff ;
V_35 [ 4 ] = V_72 & 0xff ;
V_35 [ 5 ] = ( V_25 >> 8 ) & 0xff ;
V_35 [ 6 ] = V_25 & 0xff ;
if ( ! V_71 )
V_35 [ 1 ] |= 0x04 ;
F_11 ( V_18 , & V_35 [ 1 ] ) ;
V_14 ( V_18 , V_35 , sizeof( V_35 ) ) ;
}
int F_22 ( struct V_17 * V_18 , T_3 V_72 ,
const T_1 * V_75 , T_1 V_25 )
{
unsigned long V_19 ;
int V_6 ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
F_23 ( V_18 , V_73 , 0 ) ;
F_24 ( V_18 , V_72 , V_75 , V_25 ) ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_6 = F_25 ( V_18 ) ;
if ( ! V_6 && V_18 -> V_26 . V_76 )
V_6 = - V_77 ;
return V_6 ;
}
T_5 F_26 ( struct V_17 * V_18 , T_3 V_72 , T_1 * V_78 ,
T_1 V_25 )
{
unsigned long V_19 ;
T_5 V_6 ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_79 = V_25 ;
V_18 -> V_26 . V_80 = V_78 ;
F_23 ( V_18 , V_74 , V_72 & 0xffff ) ;
F_27 ( V_18 , V_72 , V_25 ) ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_6 = F_25 ( V_18 ) ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_80 = NULL ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
if ( ! V_6 ) {
if ( V_18 -> V_26 . V_79 == 0 )
V_6 = - V_77 ;
else
V_6 = V_18 -> V_26 . V_79 ;
}
return V_6 ;
}
static int F_28 ( struct V_17 * V_18 )
{
T_1 V_75 ;
int V_6 ;
V_75 = 0x55 ;
V_6 = F_22 ( V_18 , 0xa400f0 , & V_75 , sizeof( V_75 ) ) ;
if ( V_6 )
return V_6 ;
V_75 = 0x0 ;
V_6 = F_22 ( V_18 , 0xa400fb , & V_75 , sizeof( V_75 ) ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static T_1 F_29 ( struct V_17 * V_18 , T_1 * V_78 )
{
int V_6 ;
V_6 = F_26 ( V_18 , 0xa400fa , V_78 , 6 ) ;
if ( V_6 != 6 )
return V_81 ;
F_30 ( V_18 -> V_2 , L_5 , V_78 ) ;
if ( V_78 [ 0 ] == 0xff && V_78 [ 1 ] == 0xff && V_78 [ 2 ] == 0xff &&
V_78 [ 3 ] == 0xff && V_78 [ 4 ] == 0xff && V_78 [ 5 ] == 0xff )
return V_81 ;
if ( V_78 [ 4 ] == 0x00 && V_78 [ 5 ] == 0x00 )
return V_82 ;
if ( V_78 [ 4 ] == 0x01 && V_78 [ 5 ] == 0x01 )
return V_83 ;
if ( V_78 [ 4 ] == 0x04 && V_78 [ 5 ] == 0x02 )
return V_84 ;
if ( V_78 [ 4 ] == 0x01 && V_78 [ 5 ] == 0x20 )
return V_85 ;
return V_86 ;
}
static int F_31 ( struct V_17 * V_18 )
{
T_1 V_75 ;
int V_6 ;
V_75 = 0x55 ;
V_6 = F_22 ( V_18 , 0xa600f0 , & V_75 , sizeof( V_75 ) ) ;
if ( V_6 )
return V_6 ;
V_75 = 0x0 ;
V_6 = F_22 ( V_18 , 0xa600fb , & V_75 , sizeof( V_75 ) ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
static bool F_32 ( struct V_17 * V_18 , T_1 V_87 )
{
T_1 V_75 ;
switch ( V_87 ) {
case V_83 :
V_75 = 0x07 ;
break;
case V_82 :
V_75 = 0x05 ;
break;
default:
V_75 = 0x04 ;
break;
}
return F_22 ( V_18 , 0xa600fe , & V_75 , sizeof( V_75 ) ) ;
}
static bool F_33 ( struct V_17 * V_18 , T_1 * V_78 )
{
int V_6 ;
V_6 = F_26 ( V_18 , 0xa600fa , V_78 , 6 ) ;
if ( V_6 != 6 )
return false ;
F_30 ( V_18 -> V_2 , L_6 , V_78 ) ;
if ( V_78 [ 5 ] == 0x05 )
return true ;
F_34 ( V_18 -> V_2 , L_7 , V_78 ) ;
return false ;
}
static T_1 F_35 ( struct V_17 * V_18 )
{
int V_6 ;
T_1 V_78 [ 6 ] ;
V_6 = F_26 ( V_18 , 0xa400fa , V_78 , 6 ) ;
if ( V_6 != 6 )
return V_88 ;
F_30 ( V_18 -> V_2 , L_8 , V_78 ) ;
if ( V_78 [ 0 ] == 0xff && V_78 [ 1 ] == 0xff && V_78 [ 2 ] == 0xff &&
V_78 [ 3 ] == 0xff && V_78 [ 4 ] == 0xff && V_78 [ 5 ] == 0xff )
return V_88 ;
if ( V_78 [ 4 ] == 0x04 && V_78 [ 5 ] == 0x05 )
return V_89 ;
else if ( V_78 [ 4 ] == 0x05 && V_78 [ 5 ] == 0x05 )
return V_90 ;
else if ( V_78 [ 4 ] == 0x07 && V_78 [ 5 ] == 0x05 )
return V_91 ;
return V_92 ;
}
static void F_36 ( struct V_17 * V_18 ,
unsigned int V_49 )
{
bool V_93 = false ;
const T_1 * V_94 , * V_95 ;
const struct V_96 * V_97 ;
int V_6 ;
V_94 = V_98 [ V_49 ] ;
for ( V_95 = V_94 ; * V_95 != V_99 ; ++ V_95 ) {
if ( V_100 [ * V_95 ] -> V_19 & V_101 ) {
V_93 = true ;
break;
}
}
if ( V_93 ) {
V_18 -> V_102 = F_37 () ;
if ( ! V_18 -> V_102 )
return;
F_38 ( V_18 -> V_102 , V_18 ) ;
V_18 -> V_102 -> V_103 . V_104 = & V_18 -> V_2 -> V_103 ;
V_18 -> V_102 -> V_105 . V_106 = V_18 -> V_2 -> V_107 ;
V_18 -> V_102 -> V_105 . V_108 = V_18 -> V_2 -> V_108 ;
V_18 -> V_102 -> V_105 . V_109 = V_18 -> V_2 -> V_109 ;
V_18 -> V_102 -> V_105 . V_110 = V_18 -> V_2 -> V_110 ;
V_18 -> V_102 -> V_111 = V_112 ;
}
for ( V_95 = V_94 ; * V_95 != V_99 ; ++ V_95 ) {
V_97 = V_100 [ * V_95 ] ;
if ( ! V_97 -> V_113 )
continue;
V_6 = V_97 -> V_113 ( V_97 , V_18 ) ;
if ( V_6 )
goto error;
}
if ( V_18 -> V_102 ) {
V_6 = F_39 ( V_18 -> V_102 ) ;
if ( V_6 )
goto error;
}
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_18 -> V_26 . V_49 = V_49 ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
return;
error:
for ( ; V_95 -- != V_94 ; ) {
V_97 = V_100 [ * V_95 ] ;
if ( V_97 -> remove )
V_97 -> remove ( V_97 , V_18 ) ;
}
if ( V_18 -> V_102 ) {
F_42 ( V_18 -> V_102 ) ;
V_18 -> V_102 = NULL ;
}
}
static void F_43 ( struct V_17 * V_18 )
{
const T_1 * V_94 , * V_95 ;
const struct V_96 * V_97 ;
unsigned long V_19 ;
V_94 = V_98 [ V_18 -> V_26 . V_49 ] ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_49 = V_114 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
for ( V_95 = V_94 ; * V_95 != V_99 ; ++ V_95 )
;
if ( V_18 -> V_102 ) {
F_44 ( V_18 -> V_102 ) ;
F_45 ( V_18 -> V_102 ) ;
}
for ( ; V_95 -- != V_94 ; ) {
V_97 = V_100 [ * V_95 ] ;
if ( V_97 -> remove )
V_97 -> remove ( V_97 , V_18 ) ;
}
if ( V_18 -> V_102 ) {
F_46 ( V_18 -> V_102 ) ;
V_18 -> V_102 = NULL ;
}
}
static void F_47 ( struct V_17 * V_18 , unsigned int V_46 )
{
unsigned long V_19 ;
const struct V_96 * V_97 ;
int V_6 ;
V_97 = V_115 [ V_46 ] ;
if ( V_97 -> V_113 ) {
V_6 = V_97 -> V_113 ( V_97 , V_18 ) ;
if ( V_6 )
V_46 = V_86 ;
}
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_87 = V_46 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
}
static void F_48 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
const struct V_96 * V_97 ;
V_97 = V_115 [ V_18 -> V_26 . V_87 ] ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_87 = V_86 ;
V_18 -> V_26 . V_19 &= ~ V_47 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
if ( V_97 -> remove )
V_97 -> remove ( V_97 , V_18 ) ;
}
static void F_49 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
const struct V_96 * V_97 ;
int V_6 ;
T_1 V_116 = 2 ;
V_97 = & V_117 ;
if ( V_97 -> V_113 ) {
V_6 = V_97 -> V_113 ( V_97 , V_18 ) ;
if ( V_6 )
V_116 = 1 ;
}
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_118 = V_116 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
}
static void F_50 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
const struct V_96 * V_97 ;
if ( V_18 -> V_26 . V_118 < 2 )
return;
V_97 = & V_117 ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_118 = 0 ;
V_18 -> V_26 . V_19 &= ~ V_48 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
if ( V_97 -> remove )
V_97 -> remove ( V_97 , V_18 ) ;
}
static void F_51 ( struct V_17 * V_18 ,
T_1 V_87 )
{
T_1 V_49 = V_119 ;
T_4 V_108 , V_109 ;
const char * V_111 ;
V_108 = V_18 -> V_2 -> V_108 ;
V_109 = V_18 -> V_2 -> V_109 ;
V_111 = V_18 -> V_2 -> V_111 ;
if ( V_87 == V_84 ) {
V_49 = V_50 ;
goto V_120;
} else if ( V_87 == V_85 ) {
V_49 = V_121 ;
goto V_120;
}
if ( ! strcmp ( V_111 , L_9 ) ) {
V_49 = V_122 ;
goto V_120;
} else if ( ! strcmp ( V_111 , L_10 ) ) {
V_49 = V_123 ;
goto V_120;
} else if ( ! strcmp ( V_111 , L_11 ) ) {
V_49 = V_50 ;
goto V_120;
} else if ( ! strcmp ( V_111 , L_12 ) ) {
V_49 = V_121 ;
goto V_120;
}
if ( V_108 == V_124 ) {
if ( V_109 == V_125 ) {
V_49 = V_122 ;
goto V_120;
} else if ( V_109 == V_126 ) {
V_49 = V_123 ;
goto V_120;
}
}
V_120:
if ( V_49 == V_119 )
F_34 ( V_18 -> V_2 , L_13 ,
V_111 , V_108 , V_109 , V_87 ) ;
else
F_34 ( V_18 -> V_2 , L_14 ,
V_127 [ V_49 ] ) ;
F_36 ( V_18 , V_49 ) ;
}
static void F_52 ( struct V_17 * V_18 )
{
T_1 V_87 = V_81 , V_128 [ 6 ] ;
bool V_46 ;
int V_6 ;
F_53 ( V_18 ) ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_18 -> V_26 . V_49 = V_114 ;
F_23 ( V_18 , V_67 , 0 ) ;
F_16 ( V_18 ) ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
V_6 = F_54 ( V_18 ) ;
if ( V_6 )
goto V_129;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_46 = V_18 -> V_26 . V_19 & V_130 ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
if ( ! V_46 )
goto V_129;
F_28 ( V_18 ) ;
V_87 = F_29 ( V_18 , V_128 ) ;
V_129:
F_55 ( V_18 ) ;
F_51 ( V_18 , V_87 ) ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
if ( ! ( V_18 -> V_26 . V_19 & V_131 ) &&
! ( V_18 -> V_26 . V_19 & V_132 ) )
F_56 ( & V_18 -> V_133 , V_134 + V_135 * 4 ) ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
}
static void F_57 ( struct V_17 * V_18 )
{
bool V_118 ;
T_1 V_136 [ 6 ] ;
F_53 ( V_18 ) ;
F_31 ( V_18 ) ;
V_118 = F_33 ( V_18 , V_136 ) ;
F_55 ( V_18 ) ;
if ( V_118 ) {
if ( ! V_18 -> V_26 . V_118 ) {
F_34 ( V_18 -> V_2 , L_15 ) ;
F_49 ( V_18 ) ;
}
} else if ( V_18 -> V_26 . V_118 ) {
F_50 ( V_18 ) ;
}
F_56 ( & V_18 -> V_133 , V_134 + V_135 * 4 ) ;
}
static bool F_58 ( struct V_17 * V_18 )
{
T_3 V_19 ;
T_1 type , V_24 [ 6 ] ;
bool V_6 , V_137 ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_19 = V_18 -> V_26 . V_19 ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
F_53 ( V_18 ) ;
if ( V_18 -> V_26 . V_87 == V_81 &&
V_18 -> V_26 . V_118 > 0 && ( V_19 & V_48 ) ) {
type = F_35 ( V_18 ) ;
V_6 = type == V_89 ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_6 = V_6 && ! ( V_18 -> V_26 . V_19 & V_138 ) ;
V_6 = V_6 && ! ( V_18 -> V_26 . V_19 & V_139 ) ;
V_6 = V_6 && ( V_18 -> V_26 . V_19 & V_140 ) ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
if ( ! V_6 )
F_30 ( V_18 -> V_2 , L_16 ) ;
V_137 = false ;
goto V_129;
}
if ( ! ( V_19 & V_48 ) &&
V_18 -> V_26 . V_87 != V_81 ) {
type = F_29 ( V_18 , V_24 ) ;
V_6 = type == V_18 -> V_26 . V_87 ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_6 = V_6 && ! ( V_18 -> V_26 . V_19 & V_140 ) ;
V_6 = V_6 && ( V_18 -> V_26 . V_19 & V_138 ) ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
if ( ! V_6 )
F_30 ( V_18 -> V_2 , L_17 ) ;
V_137 = true ;
goto V_129;
}
if ( ! ( V_19 & V_48 ) &&
V_18 -> V_26 . V_87 == V_81 ) {
type = F_29 ( V_18 , V_24 ) ;
V_6 = type == V_18 -> V_26 . V_87 ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_6 = V_6 && ! ( V_18 -> V_26 . V_19 & V_138 ) ;
V_6 = V_6 && ! ( V_18 -> V_26 . V_19 & V_140 ) ;
V_6 = V_6 && ! ( V_18 -> V_26 . V_19 & V_130 ) ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
if ( ! V_6 )
F_30 ( V_18 -> V_2 , L_18 ) ;
V_137 = true ;
goto V_129;
}
if ( V_18 -> V_26 . V_87 != V_81 &&
V_18 -> V_26 . V_118 > 0 && ( V_19 & V_48 ) ) {
type = F_35 ( V_18 ) ;
V_6 = type != V_88 ;
V_6 = V_6 && type != V_92 ;
V_6 = V_6 && type != V_89 ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_6 = V_6 && ( V_18 -> V_26 . V_19 & V_130 ) ;
V_6 = V_6 && ( V_18 -> V_26 . V_19 & V_138 ) ;
V_6 = V_6 && ( V_18 -> V_26 . V_19 & V_140 ) ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
if ( ! V_6 )
F_30 ( V_18 -> V_2 , L_19 ) ;
V_137 = false ;
goto V_129;
}
V_6 = false ;
V_129:
F_55 ( V_18 ) ;
if ( V_6 && V_137 && ! ( V_19 & V_131 ) &&
! ( V_19 & V_132 ) )
F_57 ( V_18 ) ;
return V_6 ;
}
static void F_59 ( struct V_17 * V_18 )
{
T_1 V_87 , V_128 [ 6 ] , V_136 [ 6 ] ;
T_3 V_19 ;
bool V_118 ;
F_30 ( V_18 -> V_2 , L_20 ) ;
F_53 ( V_18 ) ;
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_19 = V_18 -> V_26 . V_19 ;
V_18 -> V_26 . V_19 &= ~ V_138 ;
V_18 -> V_26 . V_19 &= ~ V_140 ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
F_28 ( V_18 ) ;
if ( V_19 & V_132 ) {
V_118 = false ;
} else {
F_31 ( V_18 ) ;
V_118 = F_33 ( V_18 , V_136 ) ;
}
V_87 = F_29 ( V_18 , V_128 ) ;
F_55 ( V_18 ) ;
if ( V_87 != V_18 -> V_26 . V_87 ) {
F_48 ( V_18 ) ;
if ( V_87 == V_86 ) {
F_34 ( V_18 -> V_2 , L_21 ,
V_128 ) ;
} else if ( V_87 == V_81 ) {
F_40 ( & V_18 -> V_26 . V_20 ) ;
V_18 -> V_26 . V_87 = V_81 ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
} else {
F_34 ( V_18 -> V_2 , L_22 ,
V_141 [ V_87 ] ) ;
F_47 ( V_18 , V_87 ) ;
}
}
if ( V_118 ) {
if ( ! V_18 -> V_26 . V_118 ) {
F_34 ( V_18 -> V_2 , L_15 ) ;
F_49 ( V_18 ) ;
}
} else if ( V_18 -> V_26 . V_118 ) {
F_50 ( V_18 ) ;
}
if ( ! ( V_19 & V_48 ) )
V_118 = false ;
if ( V_118 ) {
F_53 ( V_18 ) ;
F_32 ( V_18 , V_87 ) ;
F_55 ( V_18 ) ;
F_60 ( & V_18 -> V_133 ) ;
} else {
if ( ! ( V_19 & V_131 ) &&
! ( V_19 & V_132 ) )
F_56 ( & V_18 -> V_133 , V_134 + V_135 * 4 ) ;
}
F_40 ( & V_18 -> V_26 . V_20 ) ;
if ( V_118 ) {
V_18 -> V_26 . V_19 |= V_140 ;
if ( V_18 -> V_26 . V_87 == V_81 ) {
V_18 -> V_26 . V_19 &= ~ V_130 ;
V_18 -> V_26 . V_19 &= ~ V_139 ;
} else {
V_18 -> V_26 . V_19 &= ~ V_130 ;
V_18 -> V_26 . V_19 |= V_139 ;
V_18 -> V_26 . V_19 |= V_138 ;
}
} else if ( V_18 -> V_26 . V_87 != V_81 ) {
V_18 -> V_26 . V_19 |= V_138 ;
}
F_16 ( V_18 ) ;
F_41 ( & V_18 -> V_26 . V_20 ) ;
F_30 ( V_18 -> V_2 , L_23 ,
V_18 -> V_26 . V_118 , V_18 -> V_26 . V_87 ) ;
}
static void F_61 ( struct V_12 * V_13 )
{
struct V_17 * V_18 = F_5 ( V_13 , struct V_17 ,
V_142 ) ;
bool V_143 = false ;
if ( V_18 -> V_26 . V_49 == V_144 ) {
F_52 ( V_18 ) ;
V_143 = true ;
}
if ( V_143 || ! F_58 ( V_18 ) )
F_59 ( V_18 ) ;
if ( V_143 )
F_62 ( & V_18 -> V_2 -> V_103 . V_145 , V_146 ) ;
}
void F_63 ( struct V_17 * V_18 )
{
if ( ! ( V_18 -> V_26 . V_19 & V_147 ) )
F_10 ( & V_18 -> V_142 ) ;
}
static void F_64 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
F_63 ( V_18 ) ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
}
static void F_65 ( unsigned long V_148 )
{
struct V_17 * V_18 = ( void * ) V_148 ;
F_64 ( V_18 ) ;
}
static void F_66 ( struct V_17 * V_18 , const T_1 * V_149 )
{
const T_1 * V_95 , * V_94 ;
const struct V_96 * V_97 ;
V_97 = V_115 [ V_18 -> V_26 . V_87 ] ;
if ( V_97 -> V_150 ) {
V_97 -> V_150 ( V_18 , V_149 ) ;
return;
}
V_94 = V_98 [ V_18 -> V_26 . V_49 ] ;
for ( V_95 = V_94 ; * V_95 != V_99 ; ++ V_95 ) {
V_97 = V_100 [ * V_95 ] ;
if ( V_97 -> V_150 ) {
V_97 -> V_150 ( V_18 , V_149 ) ;
break;
}
}
}
static void F_67 ( struct V_17 * V_18 , const T_1 * V_149 )
{
const T_1 * V_95 , * V_94 ;
const struct V_96 * V_97 ;
V_97 = V_115 [ V_18 -> V_26 . V_87 ] ;
if ( V_97 -> V_151 ) {
V_97 -> V_151 ( V_18 , V_149 ) ;
return;
}
V_94 = V_98 [ V_18 -> V_26 . V_49 ] ;
for ( V_95 = V_94 ; * V_95 != V_99 ; ++ V_95 ) {
V_97 = V_100 [ * V_95 ] ;
if ( V_97 -> V_151 ) {
V_97 -> V_151 ( V_18 , V_149 ) ;
break;
}
}
}
static bool F_68 ( const struct V_96 * V_97 , T_2 V_152 )
{
if ( ! V_97 -> V_153 )
return false ;
if ( ( V_97 -> V_19 & V_154 ) && V_152 < 8 )
return false ;
if ( ( V_97 -> V_19 & V_155 ) && V_152 < 16 )
return false ;
return true ;
}
static void F_69 ( struct V_17 * V_18 , const T_1 * V_149 ,
T_2 V_152 )
{
static const T_1 V_156 [ 21 ] = { 0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0xff , 0xff ,
0xff } ;
const T_1 * V_95 , * V_94 ;
const struct V_96 * V_97 ;
bool V_157 ;
if ( V_152 > 21 )
V_152 = 21 ;
if ( V_152 < 6 || ! memcmp ( V_149 , V_156 , V_152 ) )
return;
if ( V_18 -> V_26 . V_19 & V_140 ) {
if ( V_149 [ 5 ] & 0x01 )
return;
if ( V_149 [ 4 ] & 0x01 ) {
if ( ! ( V_18 -> V_26 . V_19 & V_139 ) ) {
F_30 ( V_18 -> V_2 , L_24 ) ;
V_18 -> V_26 . V_19 |= V_139 ;
F_63 ( V_18 ) ;
}
} else {
if ( V_18 -> V_26 . V_19 & V_139 ) {
F_30 ( V_18 -> V_2 , L_25 ) ;
V_18 -> V_26 . V_19 &= ~ V_139 ;
V_18 -> V_26 . V_19 &= ~ V_138 ;
F_63 ( V_18 ) ;
}
}
V_157 = V_149 [ 5 ] & 0x02 ;
} else {
V_157 = false ;
}
if ( ! ( V_18 -> V_26 . V_19 & V_138 ) && ! V_157 )
return;
V_97 = V_115 [ V_18 -> V_26 . V_87 ] ;
if ( V_157 && V_97 -> V_158 ) {
V_97 -> V_158 ( V_18 , V_149 ) ;
return;
} else if ( ! V_157 && F_68 ( V_97 , V_152 ) ) {
V_97 -> V_153 ( V_18 , V_149 ) ;
return;
}
V_97 = & V_117 ;
if ( V_157 && V_97 -> V_158 ) {
V_97 -> V_158 ( V_18 , V_149 ) ;
return;
} else if ( ! V_157 && F_68 ( V_97 , V_152 ) ) {
V_97 -> V_153 ( V_18 , V_149 ) ;
return;
}
V_94 = V_98 [ V_18 -> V_26 . V_49 ] ;
for ( V_95 = V_94 ; * V_95 != V_99 ; ++ V_95 ) {
V_97 = V_100 [ * V_95 ] ;
if ( V_157 && V_97 -> V_158 ) {
V_97 -> V_158 ( V_18 , V_149 ) ;
return;
} else if ( ! V_157 && F_68 ( V_97 , V_152 ) ) {
V_97 -> V_153 ( V_18 , V_149 ) ;
return;
}
}
}
static void F_70 ( struct V_17 * V_18 , const T_1 * V_149 ,
bool V_159 , unsigned int V_105 )
{
const T_1 * V_95 , * V_94 ;
const struct V_96 * V_97 ;
V_97 = V_115 [ V_18 -> V_26 . V_87 ] ;
if ( V_97 -> V_160 ) {
V_97 -> V_160 ( V_18 , V_149 , V_159 , V_105 ) ;
return;
}
V_94 = V_98 [ V_18 -> V_26 . V_49 ] ;
for ( V_95 = V_94 ; * V_95 != V_99 ; ++ V_95 ) {
V_97 = V_100 [ * V_95 ] ;
if ( V_97 -> V_160 ) {
V_97 -> V_160 ( V_18 , V_149 , V_159 , V_105 ) ;
break;
}
}
}
static void F_71 ( struct V_17 * V_18 ,
const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_15 ( V_18 , V_65 ) ;
}
static void F_72 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_71 ( V_18 , V_149 ) ;
if ( V_149 [ 2 ] & 0x02 ) {
if ( ! ( V_18 -> V_26 . V_19 & V_130 ) ) {
F_30 ( V_18 -> V_2 , L_26 ) ;
V_18 -> V_26 . V_19 |= V_130 ;
F_63 ( V_18 ) ;
}
} else {
if ( V_18 -> V_26 . V_19 & V_130 ) {
F_30 ( V_18 -> V_2 , L_27 ) ;
V_18 -> V_26 . V_19 &= ~ V_130 ;
V_18 -> V_26 . V_19 &= ~ V_139 ;
V_18 -> V_26 . V_19 &= ~ V_138 ;
V_18 -> V_26 . V_19 &= ~ V_140 ;
F_63 ( V_18 ) ;
}
}
V_18 -> V_26 . V_161 = V_149 [ 5 ] ;
if ( F_73 ( V_18 , V_67 , 0 ) )
F_74 ( V_18 ) ;
}
static void F_75 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
}
static void F_76 ( struct V_17 * V_18 , const T_1 * V_149 )
{
T_4 V_72 = V_149 [ 3 ] << 8 | V_149 [ 4 ] ;
T_1 V_25 = ( V_149 [ 2 ] >> 4 ) + 1 ;
T_1 V_162 = V_149 [ 2 ] & 0x0f ;
F_66 ( V_18 , V_149 ) ;
if ( F_73 ( V_18 , V_74 , V_72 ) ) {
if ( V_162 )
V_25 = 0 ;
else if ( V_25 > V_18 -> V_26 . V_79 )
V_25 = V_18 -> V_26 . V_79 ;
V_18 -> V_26 . V_79 = V_25 ;
if ( V_18 -> V_26 . V_80 )
memcpy ( V_18 -> V_26 . V_80 , & V_149 [ 5 ] , V_25 ) ;
F_74 ( V_18 ) ;
}
}
static void F_77 ( struct V_17 * V_18 , const T_1 * V_149 )
{
T_1 V_162 = V_149 [ 3 ] ;
T_1 V_35 = V_149 [ 2 ] ;
F_66 ( V_18 , V_149 ) ;
if ( F_73 ( V_18 , V_35 , 0 ) ) {
V_18 -> V_26 . V_76 = V_162 ;
F_74 ( V_18 ) ;
} else if ( V_162 ) {
F_9 ( V_18 -> V_2 , L_28 , V_162 ,
V_35 ) ;
}
}
static void F_78 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_67 ( V_18 , V_149 ) ;
}
static void F_79 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_69 ( V_18 , & V_149 [ 2 ] , 8 ) ;
}
static void F_80 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_67 ( V_18 , V_149 ) ;
F_81 ( V_18 , & V_149 [ 5 ] , false ) ;
F_82 ( V_18 , & V_149 [ 8 ] , false ) ;
F_83 ( V_18 , & V_149 [ 11 ] , false ) ;
F_84 ( V_18 , & V_149 [ 14 ] , false ) ;
}
static void F_85 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_69 ( V_18 , & V_149 [ 2 ] , 19 ) ;
}
static void F_86 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_81 ( V_18 , & V_149 [ 2 ] , false ) ;
F_82 ( V_18 , & V_149 [ 4 ] , true ) ;
F_83 ( V_18 , & V_149 [ 7 ] , false ) ;
F_84 ( V_18 , & V_149 [ 9 ] , true ) ;
F_69 ( V_18 , & V_149 [ 12 ] , 9 ) ;
}
static void F_87 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_67 ( V_18 , V_149 ) ;
F_69 ( V_18 , & V_149 [ 5 ] , 16 ) ;
}
static void F_88 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
F_67 ( V_18 , V_149 ) ;
F_81 ( V_18 , & V_149 [ 5 ] , false ) ;
F_82 ( V_18 , & V_149 [ 7 ] , true ) ;
F_83 ( V_18 , & V_149 [ 10 ] , false ) ;
F_84 ( V_18 , & V_149 [ 12 ] , true ) ;
F_69 ( V_18 , & V_149 [ 15 ] , 6 ) ;
}
static void F_89 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_69 ( V_18 , V_149 , 21 ) ;
}
static void F_90 ( struct V_17 * V_18 , const T_1 * V_149 )
{
F_66 ( V_18 , V_149 ) ;
V_18 -> V_26 . V_163 [ 0 ] = V_149 [ 2 ] ;
V_18 -> V_26 . V_163 [ 1 ] = ( V_149 [ 0 ] >> 1 ) & ( 0x10 | 0x20 ) ;
V_18 -> V_26 . V_163 [ 1 ] |= ( V_149 [ 1 ] << 1 ) & ( 0x40 | 0x80 ) ;
F_81 ( V_18 , & V_149 [ 3 ] , false ) ;
F_82 ( V_18 , & V_149 [ 12 ] , false ) ;
}
static void F_91 ( struct V_17 * V_18 , const T_1 * V_149 )
{
T_1 V_5 [ 5 ] ;
F_66 ( V_18 , V_149 ) ;
V_18 -> V_26 . V_163 [ 1 ] |= ( V_149 [ 0 ] >> 5 ) & ( 0x01 | 0x02 ) ;
V_18 -> V_26 . V_163 [ 1 ] |= ( V_149 [ 1 ] >> 3 ) & ( 0x04 | 0x08 ) ;
V_5 [ 0 ] = 0 ;
V_5 [ 1 ] = 0 ;
V_5 [ 2 ] = V_18 -> V_26 . V_163 [ 0 ] ;
V_5 [ 3 ] = V_149 [ 2 ] ;
V_5 [ 4 ] = V_18 -> V_26 . V_163 [ 1 ] ;
F_67 ( V_18 , V_5 ) ;
F_83 ( V_18 , & V_149 [ 3 ] , false ) ;
F_84 ( V_18 , & V_149 [ 12 ] , false ) ;
}
static int F_92 ( struct V_1 * V_2 , struct V_164 * V_165 ,
T_6 * V_166 , int V_25 )
{
struct V_17 * V_18 = F_93 ( V_2 ) ;
struct V_167 * V_168 ;
int V_169 ;
unsigned long V_19 ;
if ( V_25 < 1 )
return - V_170 ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
for ( V_169 = 0 ; V_171 [ V_169 ] . V_105 ; ++ V_169 ) {
V_168 = & V_171 [ V_169 ] ;
if ( V_168 -> V_105 == V_166 [ 0 ] && V_168 -> V_25 < V_25 ) {
V_168 -> V_172 ( V_18 , & V_166 [ 1 ] ) ;
break;
}
}
if ( ! V_171 [ V_169 ] . V_105 )
F_9 ( V_2 , L_29 , V_166 [ 0 ] ,
V_25 ) ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
return 0 ;
}
static T_5 F_94 ( struct V_173 * V_103 ,
struct V_174 * V_175 ,
char * V_5 )
{
struct V_17 * V_18 = F_95 ( V_103 ) ;
T_1 type ;
unsigned long V_19 ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
type = V_18 -> V_26 . V_87 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
switch ( type ) {
case V_81 :
return sprintf ( V_5 , L_30 ) ;
case V_82 :
return sprintf ( V_5 , L_31 ) ;
case V_83 :
return sprintf ( V_5 , L_32 ) ;
case V_84 :
return sprintf ( V_5 , L_33 ) ;
case V_85 :
return sprintf ( V_5 , L_34 ) ;
case V_86 :
default:
return sprintf ( V_5 , L_35 ) ;
}
}
static T_5 F_96 ( struct V_173 * V_103 ,
struct V_174 * V_175 ,
const char * V_5 , T_2 V_4 )
{
struct V_17 * V_18 = F_95 ( V_103 ) ;
if ( ! strcmp ( V_5 , L_36 ) ) {
F_64 ( V_18 ) ;
} else {
return - V_170 ;
}
return F_97 ( V_5 , V_176 ) ;
}
static T_5 F_98 ( struct V_173 * V_103 ,
struct V_174 * V_175 ,
char * V_5 )
{
struct V_17 * V_18 = F_95 ( V_103 ) ;
T_1 type ;
unsigned long V_19 ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
type = V_18 -> V_26 . V_49 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
switch ( type ) {
case V_119 :
return sprintf ( V_5 , L_37 ) ;
case V_122 :
return sprintf ( V_5 , L_38 ) ;
case V_123 :
return sprintf ( V_5 , L_39 ) ;
case V_50 :
return sprintf ( V_5 , L_33 ) ;
case V_121 :
return sprintf ( V_5 , L_34 ) ;
case V_144 :
return sprintf ( V_5 , L_40 ) ;
case V_114 :
default:
return sprintf ( V_5 , L_35 ) ;
}
}
static struct V_17 * F_99 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
V_18 = F_100 ( sizeof( * V_18 ) , V_9 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_2 = V_2 ;
F_101 ( V_2 , V_18 ) ;
F_102 ( & V_18 -> V_15 . V_20 ) ;
F_103 ( & V_18 -> V_15 . V_16 , F_4 ) ;
F_102 ( & V_18 -> V_26 . V_20 ) ;
F_104 ( & V_18 -> V_26 . V_177 ) ;
F_105 ( & V_18 -> V_26 . V_178 ) ;
V_18 -> V_26 . V_63 = V_52 ;
V_18 -> V_26 . V_161 = 0xff ;
F_103 ( & V_18 -> V_142 , F_61 ) ;
F_106 ( & V_18 -> V_133 , F_65 , ( long ) V_18 ) ;
return V_18 ;
}
static void F_107 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
F_108 ( V_18 ) ;
F_6 ( & V_18 -> V_26 . V_20 , V_19 ) ;
V_18 -> V_26 . V_19 |= V_147 ;
F_7 ( & V_18 -> V_26 . V_20 , V_19 ) ;
F_109 ( & V_18 -> V_142 ) ;
F_60 ( & V_18 -> V_133 ) ;
F_110 ( & V_18 -> V_2 -> V_103 , & V_179 ) ;
F_110 ( & V_18 -> V_2 -> V_103 , & V_180 ) ;
F_50 ( V_18 ) ;
F_48 ( V_18 ) ;
F_43 ( V_18 ) ;
F_109 ( & V_18 -> V_15 . V_16 ) ;
F_111 ( V_18 -> V_2 ) ;
F_112 ( V_18 -> V_2 ) ;
F_3 ( V_18 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
const struct V_181 * V_105 )
{
struct V_17 * V_18 ;
int V_6 ;
V_2 -> V_182 |= V_183 ;
V_18 = F_99 ( V_2 ) ;
if ( ! V_18 ) {
F_114 ( V_2 , L_41 ) ;
return - V_10 ;
}
V_6 = F_115 ( V_2 ) ;
if ( V_6 ) {
F_114 ( V_2 , L_42 ) ;
goto V_162;
}
V_6 = F_116 ( V_2 , V_184 ) ;
if ( V_6 ) {
F_114 ( V_2 , L_43 ) ;
goto V_162;
}
V_6 = F_117 ( V_2 ) ;
if ( V_6 ) {
F_114 ( V_2 , L_44 ) ;
goto V_185;
}
V_6 = F_118 ( & V_2 -> V_103 , & V_180 ) ;
if ( V_6 ) {
F_114 ( V_2 , L_45 ) ;
goto V_186;
}
V_6 = F_118 ( & V_2 -> V_103 , & V_179 ) ;
if ( V_6 ) {
F_114 ( V_2 , L_45 ) ;
goto V_187;
}
V_6 = F_119 ( V_18 ) ;
if ( V_6 )
goto V_188;
F_34 ( V_2 , L_46 ) ;
F_64 ( V_18 ) ;
return 0 ;
V_188:
F_107 ( V_18 ) ;
return V_6 ;
V_187:
F_110 ( & V_18 -> V_2 -> V_103 , & V_180 ) ;
V_186:
F_111 ( V_2 ) ;
V_185:
F_112 ( V_2 ) ;
V_162:
F_42 ( V_18 -> V_44 ) ;
F_42 ( V_18 -> V_68 ) ;
F_3 ( V_18 ) ;
return V_6 ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_93 ( V_2 ) ;
F_34 ( V_2 , L_47 ) ;
F_107 ( V_18 ) ;
}
