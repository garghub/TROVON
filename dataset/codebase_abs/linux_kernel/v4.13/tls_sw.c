static inline void F_1 ( int V_1 ,
char * V_2 ,
T_1 V_3 ,
char * V_4 ,
int V_5 ,
unsigned char V_6 )
{
memcpy ( V_2 , V_4 , V_5 ) ;
V_2 [ 8 ] = V_6 ;
V_2 [ 9 ] = V_7 ;
V_2 [ 10 ] = V_8 ;
V_2 [ 11 ] = V_3 >> 8 ;
V_2 [ 12 ] = V_3 & 0xFF ;
}
static void F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int * V_13 , unsigned int * V_14 , int V_15 )
{
int V_16 = * V_13 - 1 ;
int V_17 = * V_14 - V_15 ;
if ( V_17 <= 0 ) {
F_3 ( V_17 < 0 ) ;
return;
}
* V_14 = V_15 ;
while ( V_17 >= V_12 [ V_16 ] . V_18 ) {
V_17 -= V_12 [ V_16 ] . V_18 ;
F_4 ( V_10 , V_12 [ V_16 ] . V_18 ) ;
F_5 ( F_6 ( & V_12 [ V_16 ] ) ) ;
V_16 -- ;
if ( V_16 < 0 )
goto V_19;
}
V_12 [ V_16 ] . V_18 -= V_17 ;
F_4 ( V_10 , V_17 ) ;
V_19:
* V_13 = V_16 + 1 ;
}
static void F_7 ( struct V_9 * V_10 , int V_15 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
F_2 ( V_10 , V_23 -> V_24 ,
& V_23 -> V_25 ,
& V_23 -> V_26 ,
V_15 ) ;
if ( V_15 > 0 )
V_15 += V_21 -> V_27 ;
F_2 ( V_10 , V_23 -> V_28 ,
& V_23 -> V_29 ,
& V_23 -> V_30 ,
V_15 ) ;
}
static int F_10 ( struct V_9 * V_10 , int V_31 , struct V_11 * V_12 ,
int * V_13 , unsigned int * V_14 ,
int V_32 )
{
struct V_33 * V_34 ;
unsigned int V_3 = * V_14 ;
int V_35 = * V_13 , V_36 = 0 , V_37 = 0 ;
struct V_11 * V_38 ;
unsigned int V_39 ;
V_31 -= V_3 ;
V_34 = F_11 ( V_10 ) ;
while ( V_31 > 0 ) {
if ( ! F_12 ( V_10 , V_34 ) ) {
V_37 = - V_40 ;
goto V_19;
}
V_36 = F_13 ( int , V_31 , V_34 -> V_3 - V_34 -> V_41 ) ;
if ( ! F_14 ( V_10 , V_36 ) ) {
V_37 = - V_40 ;
goto V_19;
}
F_15 ( V_10 , V_36 ) ;
V_3 += V_36 ;
V_39 = V_34 -> V_41 ;
V_34 -> V_41 += V_36 ;
V_38 = V_12 + V_35 - 1 ;
if ( V_35 > V_32 && F_6 ( V_12 ) == V_34 -> V_42 &&
V_12 -> V_41 + V_12 -> V_18 == V_39 ) {
V_12 -> V_18 += V_36 ;
} else {
V_38 ++ ;
F_16 ( V_38 ) ;
F_17 ( V_38 , V_34 -> V_42 , V_36 , V_39 ) ;
F_18 ( V_34 -> V_42 ) ;
++ V_35 ;
if ( V_35 == V_43 ) {
V_37 = - V_44 ;
break;
}
}
V_31 -= V_36 ;
}
goto V_19;
V_19:
* V_14 = V_3 ;
* V_13 = V_35 ;
return V_37 ;
}
static int F_19 ( struct V_9 * V_10 , int V_31 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
int V_37 = 0 ;
V_37 = F_10 ( V_10 , V_31 , V_23 -> V_28 ,
& V_23 -> V_29 , & V_23 -> V_30 , 0 ) ;
return V_37 ;
}
static int F_20 ( struct V_9 * V_10 , int V_31 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
int V_37 = 0 ;
V_37 = F_10 ( V_10 , V_31 , V_23 -> V_24 ,
& V_23 -> V_25 , & V_23 -> V_26 ,
V_21 -> V_45 ) ;
return V_37 ;
}
static void F_21 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int * V_13 , unsigned int * V_14 )
{
int V_16 , V_46 = * V_13 ;
for ( V_16 = 0 ; V_16 < V_46 ; ++ V_16 ) {
F_4 ( V_10 , V_12 [ V_16 ] . V_18 ) ;
F_5 ( F_6 ( & V_12 [ V_16 ] ) ) ;
}
* V_13 = 0 ;
* V_14 = 0 ;
}
static void F_22 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
F_21 ( V_10 , V_23 -> V_28 , & V_23 -> V_29 ,
& V_23 -> V_30 ) ;
F_21 ( V_10 , V_23 -> V_24 , & V_23 -> V_25 ,
& V_23 -> V_26 ) ;
}
static int F_23 ( struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_47 ,
T_2 V_48 )
{
unsigned int V_49 = sizeof( struct V_50 ) +
F_24 ( V_23 -> V_51 ) ;
struct V_50 * V_52 ;
int V_37 ;
V_52 = F_25 ( V_49 , V_48 ) ;
if ( ! V_52 )
return - V_40 ;
V_23 -> V_28 [ 0 ] . V_41 += V_21 -> V_53 ;
V_23 -> V_28 [ 0 ] . V_18 -= V_21 -> V_53 ;
F_26 ( V_52 , V_23 -> V_51 ) ;
F_27 ( V_52 , V_54 ) ;
F_28 ( V_52 , V_23 -> V_55 , V_23 -> V_56 ,
V_47 , V_21 -> V_57 ) ;
V_37 = F_29 ( V_52 ) ;
V_23 -> V_28 [ 0 ] . V_41 -= V_21 -> V_53 ;
V_23 -> V_28 [ 0 ] . V_18 += V_21 -> V_53 ;
F_30 ( V_52 ) ;
return V_37 ;
}
static int F_31 ( struct V_9 * V_10 , int V_48 ,
unsigned char V_6 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
int V_37 ;
F_32 ( V_23 -> V_24 + V_23 -> V_25 - 1 ) ;
F_32 ( V_23 -> V_28 + V_23 -> V_29 - 1 ) ;
F_1 ( 0 , V_23 -> V_58 , V_23 -> V_26 ,
V_21 -> V_59 , V_21 -> V_60 ,
V_6 ) ;
F_33 ( V_21 ,
F_34 ( F_6 ( & V_23 -> V_28 [ 0 ] ) ) +
V_23 -> V_28 [ 0 ] . V_41 ,
V_23 -> V_26 , V_6 ) ;
V_21 -> V_45 = 0 ;
F_35 ( V_61 , & V_21 -> V_48 ) ;
V_37 = F_23 ( V_21 , V_23 , V_23 -> V_26 ,
V_10 -> V_62 ) ;
if ( V_37 < 0 ) {
F_35 ( V_63 , & V_10 -> V_64 -> V_48 ) ;
return V_37 ;
}
F_21 ( V_10 , V_23 -> V_24 , & V_23 -> V_25 ,
& V_23 -> V_26 ) ;
V_23 -> V_29 = 0 ;
V_23 -> V_30 = 0 ;
V_37 = F_36 ( V_10 , V_21 , V_23 -> V_28 , 0 , V_48 ) ;
if ( V_37 < 0 && V_37 != - V_65 )
F_37 ( V_10 ) ;
F_38 ( V_10 , V_21 ) ;
return V_37 ;
}
static int F_39 ( struct V_9 * V_10 , int V_48 )
{
return F_31 ( V_10 , V_48 , V_66 ) ;
}
static int F_40 ( struct V_9 * V_10 , struct V_67 * V_68 ,
int V_18 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
struct V_42 * V_69 [ V_43 ] ;
T_1 V_41 ;
T_3 V_70 , V_36 ;
int V_16 = 0 ;
unsigned int V_3 = V_23 -> V_26 ;
int V_35 = V_23 -> V_25 ;
int V_37 = 0 ;
int V_71 ;
while ( V_18 > 0 ) {
V_16 = 0 ;
V_71 = F_41 ( V_23 -> V_24 ) - V_35 ;
if ( V_71 == 0 ) {
V_37 = - V_72 ;
goto V_19;
}
V_70 = F_42 ( V_68 , V_69 ,
V_18 ,
V_71 , & V_41 ) ;
if ( V_70 <= 0 ) {
V_37 = - V_72 ;
goto V_19;
}
F_43 ( V_68 , V_70 ) ;
V_18 -= V_70 ;
V_3 += V_70 ;
while ( V_70 ) {
V_36 = F_13 ( int , V_70 , V_73 - V_41 ) ;
F_17 ( & V_23 -> V_24 [ V_35 ] ,
V_69 [ V_16 ] , V_36 , V_41 ) ;
F_16 ( & V_23 -> V_24 [ V_35 ] ) ;
F_15 ( V_10 , V_36 ) ;
V_41 = 0 ;
V_70 -= V_36 ;
++ V_16 ;
++ V_35 ;
}
}
V_19:
V_23 -> V_26 = V_3 ;
V_23 -> V_25 = V_35 ;
return V_37 ;
}
static int F_44 ( struct V_9 * V_10 , struct V_67 * V_68 ,
int V_74 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
struct V_11 * V_12 = V_23 -> V_24 ;
int V_75 , V_16 , V_37 = 0 ;
for ( V_16 = V_21 -> V_45 ;
V_16 < V_23 -> V_25 ; ++ V_16 ) {
V_75 = V_12 [ V_16 ] . V_18 ;
if ( F_45 (
F_34 ( F_6 ( & V_12 [ V_16 ] ) ) + V_12 [ V_16 ] . V_41 ,
V_75 , V_68 ) != V_75 ) {
V_37 = - V_72 ;
goto V_19;
}
V_74 -= V_75 ;
++ V_21 -> V_45 ;
if ( ! V_74 )
break;
}
V_19:
return V_37 ;
}
int F_46 ( struct V_9 * V_10 , struct V_76 * V_77 , T_1 V_3 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
int V_78 = 0 ;
int V_79 ;
long V_80 = F_47 ( V_10 , V_77 -> V_81 & V_82 ) ;
bool V_83 = ! ( V_77 -> V_81 & V_84 ) ;
T_1 V_85 , V_70 = 0 ;
unsigned char V_6 = V_66 ;
int V_86 ;
bool V_87 ;
int V_88 ;
if ( V_77 -> V_81 & ~ ( V_84 | V_82 | V_89 ) )
return - V_90 ;
F_48 ( V_10 ) ;
if ( F_49 ( V_10 , V_21 , V_77 -> V_81 , & V_80 ) )
goto V_91;
if ( F_50 ( V_77 -> V_92 ) ) {
V_78 = F_51 ( V_10 , V_77 , & V_6 ) ;
if ( V_78 )
goto V_91;
}
while ( F_52 ( V_77 ) ) {
if ( V_10 -> V_93 ) {
V_78 = V_10 -> V_93 ;
goto V_91;
}
V_88 = V_23 -> V_26 ;
V_87 = false ;
V_85 = F_52 ( V_77 ) ;
V_86 = V_94 - V_23 -> V_26 ;
if ( V_85 >= V_86 ) {
V_85 = V_86 ;
V_87 = true ;
}
V_79 = V_23 -> V_26 + V_85 +
V_21 -> V_27 ;
if ( ! F_53 ( V_10 ) )
goto V_95;
V_96:
V_78 = F_19 ( V_10 , V_79 ) ;
if ( V_78 ) {
if ( V_78 != - V_44 )
goto V_97;
V_85 -= V_79 - V_23 -> V_30 ;
V_87 = true ;
}
if ( V_87 || V_83 ) {
V_78 = F_40 ( V_10 , & V_77 -> V_98 ,
V_85 ) ;
if ( V_78 )
goto V_99;
V_70 += V_85 ;
V_78 = F_31 ( V_10 , V_77 -> V_81 , V_6 ) ;
if ( ! V_78 )
continue;
if ( V_78 == - V_65 )
goto V_91;
V_70 -= V_85 ;
V_99:
F_54 ( & V_77 -> V_98 ,
V_23 -> V_26 - V_88 ) ;
F_2 ( V_10 , V_23 -> V_24 ,
& V_23 -> V_25 ,
& V_23 -> V_26 ,
V_88 ) ;
}
V_79 = V_23 -> V_26 + V_85 ;
V_100:
V_78 = F_20 ( V_10 , V_79 ) ;
if ( V_78 ) {
if ( V_78 != - V_44 )
goto V_97;
V_85 -= V_79 - V_23 -> V_26 ;
V_87 = true ;
F_2 ( V_10 , V_23 -> V_28 ,
& V_23 -> V_29 ,
& V_23 -> V_30 ,
V_23 -> V_26 +
V_21 -> V_27 ) ;
}
V_78 = F_44 ( V_10 , & V_77 -> V_98 , V_85 ) ;
if ( V_78 )
goto V_101;
V_70 += V_85 ;
if ( V_87 || V_83 ) {
V_102:
V_78 = F_31 ( V_10 , V_77 -> V_81 , V_6 ) ;
if ( V_78 ) {
if ( V_78 == - V_40 )
goto V_97;
goto V_91;
}
}
continue;
V_95:
F_35 ( V_63 , & V_10 -> V_64 -> V_48 ) ;
V_97:
V_78 = F_55 ( V_10 , & V_80 ) ;
if ( V_78 ) {
V_101:
F_7 ( V_10 , V_88 ) ;
goto V_91;
}
if ( F_56 ( V_21 ) )
goto V_102;
if ( V_23 -> V_30 < V_79 )
goto V_96;
goto V_100;
}
V_91:
V_78 = F_57 ( V_10 , V_77 -> V_81 , V_78 ) ;
F_58 ( V_10 ) ;
return V_70 ? V_70 : V_78 ;
}
int F_59 ( struct V_9 * V_10 , struct V_42 * V_42 ,
int V_41 , T_1 V_3 , int V_48 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
int V_78 = 0 ;
long V_80 = F_47 ( V_10 , V_48 & V_82 ) ;
bool V_83 ;
T_1 V_88 = V_3 ;
unsigned char V_6 = V_66 ;
struct V_11 * V_12 ;
bool V_87 ;
int V_86 ;
if ( V_48 & ~ ( V_84 | V_82 | V_89 |
V_103 ) )
return - V_90 ;
V_83 = ! ( V_48 & ( V_84 | V_103 ) ) ;
F_48 ( V_10 ) ;
F_60 ( V_104 , V_10 ) ;
if ( F_49 ( V_10 , V_21 , V_48 , & V_80 ) )
goto V_105;
while ( V_3 > 0 ) {
T_1 V_75 , V_79 ;
if ( V_10 -> V_93 ) {
V_78 = V_10 -> V_93 ;
goto V_105;
}
V_87 = false ;
V_86 = V_94 - V_23 -> V_26 ;
V_75 = V_3 ;
if ( V_75 >= V_86 ) {
V_75 = V_86 ;
V_87 = true ;
}
V_79 = V_23 -> V_26 + V_75 +
V_21 -> V_27 ;
if ( ! F_53 ( V_10 ) )
goto V_95;
V_106:
V_78 = F_19 ( V_10 , V_79 ) ;
if ( V_78 ) {
if ( V_78 != - V_44 )
goto V_97;
V_75 -= V_79 - V_23 -> V_26 ;
V_87 = true ;
}
F_18 ( V_42 ) ;
V_12 = V_23 -> V_24 + V_23 -> V_25 ;
F_17 ( V_12 , V_42 , V_75 , V_41 ) ;
V_23 -> V_25 ++ ;
F_15 ( V_10 , V_75 ) ;
V_41 += V_75 ;
V_3 -= V_75 ;
V_23 -> V_26 += V_75 ;
V_21 -> V_45 = V_23 -> V_25 ;
if ( V_87 || V_83 ||
V_23 -> V_25 ==
F_41 ( V_23 -> V_24 ) ) {
V_102:
V_78 = F_31 ( V_10 , V_48 , V_6 ) ;
if ( V_78 ) {
if ( V_78 == - V_40 )
goto V_97;
goto V_105;
}
}
continue;
V_95:
F_35 ( V_63 , & V_10 -> V_64 -> V_48 ) ;
V_97:
V_78 = F_55 ( V_10 , & V_80 ) ;
if ( V_78 ) {
F_7 ( V_10 , V_23 -> V_26 ) ;
goto V_105;
}
if ( F_56 ( V_21 ) )
goto V_102;
goto V_106;
}
V_105:
if ( V_88 > V_3 )
V_78 = V_88 - V_3 ;
else
V_78 = F_57 ( V_10 , V_48 , V_78 ) ;
F_58 ( V_10 ) ;
return V_78 ;
}
void F_61 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = F_8 ( V_10 ) ;
struct V_22 * V_23 = F_9 ( V_21 ) ;
if ( V_23 -> V_51 )
F_62 ( V_23 -> V_51 ) ;
F_22 ( V_10 ) ;
F_30 ( V_23 ) ;
}
int F_63 ( struct V_9 * V_10 , struct V_20 * V_23 )
{
char V_107 [ V_108 ] ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_22 * V_113 ;
T_4 V_114 , V_115 , V_116 , V_60 ;
char * V_57 , * V_59 ;
int V_37 = 0 ;
if ( ! V_23 ) {
V_37 = - V_117 ;
goto V_19;
}
if ( V_23 -> V_118 ) {
V_37 = - V_119 ;
goto V_19;
}
V_113 = F_64 ( sizeof( * V_113 ) , V_120 ) ;
if ( ! V_113 ) {
V_37 = - V_40 ;
goto V_19;
}
V_23 -> V_118 = (struct V_121 * ) V_113 ;
V_23 -> V_122 = F_61 ;
V_110 = & V_23 -> V_123 ;
switch ( V_110 -> V_124 ) {
case V_125 : {
V_114 = V_126 ;
V_115 = V_127 ;
V_116 = V_126 ;
V_57 = ( (struct V_111 * ) V_110 ) -> V_57 ;
V_60 = V_128 ;
V_59 =
( (struct V_111 * ) V_110 ) -> V_59 ;
V_112 =
(struct V_111 * ) V_110 ;
break;
}
default:
V_37 = - V_117 ;
goto V_19;
}
V_23 -> V_53 = V_129 + V_114 ;
V_23 -> V_115 = V_115 ;
V_23 -> V_27 = V_23 -> V_53 + V_23 -> V_115 ;
V_23 -> V_116 = V_116 ;
V_23 -> V_57 = F_25 ( V_116 + V_130 ,
V_120 ) ;
if ( ! V_23 -> V_57 ) {
V_37 = - V_40 ;
goto V_19;
}
memcpy ( V_23 -> V_57 , V_112 -> V_131 , V_130 ) ;
memcpy ( V_23 -> V_57 + V_130 , V_57 , V_116 ) ;
V_23 -> V_60 = V_60 ;
V_23 -> V_59 = F_25 ( V_60 , V_120 ) ;
if ( ! V_23 -> V_59 ) {
V_37 = - V_40 ;
goto V_132;
}
memcpy ( V_23 -> V_59 , V_59 , V_60 ) ;
F_65 ( V_113 -> V_28 ,
F_41 ( V_113 -> V_28 ) ) ;
F_65 ( V_113 -> V_24 ,
F_41 ( V_113 -> V_24 ) ) ;
F_65 ( V_113 -> V_55 , 2 ) ;
F_66 ( & V_113 -> V_55 [ 0 ] , V_113 -> V_58 ,
sizeof( V_113 -> V_58 ) ) ;
F_16 ( & V_113 -> V_55 [ 1 ] ) ;
F_67 ( V_113 -> V_55 , 2 , V_113 -> V_24 ) ;
F_65 ( V_113 -> V_56 , 2 ) ;
F_66 ( & V_113 -> V_56 [ 0 ] , V_113 -> V_58 ,
sizeof( V_113 -> V_58 ) ) ;
F_16 ( & V_113 -> V_56 [ 1 ] ) ;
F_67 ( V_113 -> V_56 , 2 , V_113 -> V_28 ) ;
if ( ! V_113 -> V_51 ) {
V_113 -> V_51 = F_68 ( L_1 , 0 , 0 ) ;
if ( F_69 ( V_113 -> V_51 ) ) {
V_37 = F_70 ( V_113 -> V_51 ) ;
V_113 -> V_51 = NULL ;
goto V_133;
}
}
V_23 -> V_134 = F_39 ;
memcpy ( V_107 , V_112 -> V_135 , V_108 ) ;
V_37 = F_71 ( V_113 -> V_51 , V_107 ,
V_108 ) ;
if ( V_37 )
goto V_136;
V_37 = F_72 ( V_113 -> V_51 , V_23 -> V_115 ) ;
if ( ! V_37 )
goto V_19;
V_136:
F_62 ( V_113 -> V_51 ) ;
V_113 -> V_51 = NULL ;
V_133:
F_30 ( V_23 -> V_59 ) ;
V_23 -> V_59 = NULL ;
V_132:
F_30 ( V_23 -> V_57 ) ;
V_23 -> V_57 = NULL ;
V_19:
return V_37 ;
}
