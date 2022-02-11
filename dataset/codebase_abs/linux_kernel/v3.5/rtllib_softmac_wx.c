int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
V_8 = 0 ;
goto V_15;
}
if ( V_10 -> V_16 == 1 ) {
if ( ( V_10 -> V_17 >= ( int ) 2.412e8 &&
V_10 -> V_17 <= ( int ) 2.487e8 ) ) {
int V_18 = V_10 -> V_17 / 100000 ;
int V_19 = 0 ;
while ( ( V_19 < 14 ) && ( V_18 != V_20 [ V_19 ] ) )
V_19 ++ ;
V_10 -> V_16 = 0 ;
V_10 -> V_17 = V_19 + 1 ;
}
}
if ( V_10 -> V_16 > 0 || V_10 -> V_17 > 14 || V_10 -> V_17 < 1 ) {
V_8 = - V_21 ;
goto V_15;
} else {
if ( V_2 -> V_22 [ V_10 -> V_17 ] != 1 ) {
V_8 = - V_23 ;
goto V_15;
}
V_2 -> V_24 . V_25 = V_10 -> V_17 ;
V_2 -> V_26 ( V_2 -> V_27 , V_2 -> V_24 . V_25 ) ;
if ( V_2 -> V_13 == V_28 ||
V_2 -> V_13 == V_29 )
if ( V_2 -> V_30 == V_31 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
}
}
V_8 = 0 ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( V_2 -> V_24 . V_25 == 0 )
return - 1 ;
V_10 -> V_17 = V_20 [ V_2 -> V_24 . V_25 - 1 ] *
100000 ;
V_10 -> V_16 = 1 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
unsigned long V_34 ;
V_6 -> V_35 . V_36 = V_37 ;
if ( V_2 -> V_13 == V_38 )
return - 1 ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
if ( V_2 -> V_30 != V_31 &&
V_2 -> V_30 != V_40 &&
V_2 -> V_41 == 0 )
memset ( V_6 -> V_35 . V_42 , 0 , V_43 ) ;
else
memcpy ( V_6 -> V_35 . V_42 ,
V_2 -> V_24 . V_44 , V_43 ) ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_45 ,
char * V_33 )
{
int V_8 = 0 ;
T_1 V_46 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
unsigned long V_34 ;
short V_47 = V_2 -> V_48 ;
struct V_49 * V_50 = (struct V_49 * ) V_45 ;
F_11 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_29 ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_50 -> V_36 != V_37 ) {
V_8 = - V_23 ;
goto V_15;
}
if ( memcmp ( V_50 -> V_42 , V_46 , V_43 ) == 0 ) {
F_8 ( & V_2 -> V_39 , V_34 ) ;
memcpy ( V_2 -> V_24 . V_44 , V_50 -> V_42 , V_43 ) ;
V_2 -> V_41 = 0 ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
V_8 = - 1 ;
goto V_15;
}
if ( V_47 )
F_12 ( V_2 , true ) ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
V_2 -> V_51 = false ;
memcpy ( V_2 -> V_24 . V_44 , V_50 -> V_42 , V_43 ) ;
V_2 -> V_41 = ( memcmp ( V_50 -> V_42 , V_46 , V_43 ) != 0 ) ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
if ( V_47 )
F_13 ( V_2 ) ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_52 , V_8 = 0 ;
unsigned long V_34 ;
if ( V_2 -> V_13 == V_38 )
return - 1 ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
if ( V_2 -> V_24 . V_53 [ 0 ] == '\0' ||
V_2 -> V_24 . V_54 == 0 ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_2 -> V_30 != V_31 &&
V_2 -> V_30 != V_40 &&
V_2 -> V_55 == 0 ) {
V_8 = - 1 ;
goto V_15;
}
V_52 = V_2 -> V_24 . V_54 ;
V_6 -> V_56 . V_57 = V_52 ;
strncpy ( V_7 , V_2 -> V_24 . V_53 , V_52 ) ;
V_6 -> V_56 . V_34 = 1 ;
V_15:
F_9 ( & V_2 -> V_39 , V_34 ) ;
return V_8 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_2 V_58 = V_6 -> V_59 . V_60 ;
V_2 -> V_61 = V_58 / 100000 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_2 V_62 = 0 ;
V_62 = F_17 ( V_2 ,
V_2 -> V_63 . V_64 ) ;
V_6 -> V_59 . V_60 = V_62 * 500000 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
if ( V_6 -> V_65 . V_66 || ! V_6 -> V_65 . V_67 )
V_2 -> V_65 = V_68 ;
else {
if ( V_6 -> V_65 . V_60 < V_69 ||
V_6 -> V_65 . V_60 > V_70 )
return - V_23 ;
V_2 -> V_65 = V_6 -> V_65 . V_60 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
V_6 -> V_65 . V_60 = V_2 -> V_65 ;
V_6 -> V_65 . V_67 = 0 ;
V_6 -> V_65 . V_66 = ( V_6 -> V_65 . V_60 == V_68 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_71 = 0 ;
F_11 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
switch ( V_6 -> V_72 ) {
case V_38 :
case V_28 :
case V_14 :
break;
case V_73 :
V_6 -> V_72 = V_14 ;
break;
default:
V_71 = - V_23 ;
goto V_15;
}
if ( V_6 -> V_72 == V_2 -> V_13 )
goto V_15;
if ( V_6 -> V_72 == V_38 ) {
V_2 -> V_27 -> type = V_74 ;
F_21 ( V_2 -> V_27 , false ) ;
} else {
V_2 -> V_27 -> type = V_37 ;
if ( V_2 -> V_13 == V_38 )
F_22 ( V_2 -> V_27 , false ) ;
}
if ( ! V_2 -> V_48 ) {
V_2 -> V_13 = V_6 -> V_72 ;
} else {
F_12 ( V_2 , true ) ;
V_2 -> V_13 = V_6 -> V_72 ;
F_13 ( V_2 ) ;
}
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_71 ;
}
void F_23 ( void * V_75 )
{
struct V_1 * V_2 = F_24 ( V_75 ,
struct V_1 , V_76 ) ;
short V_77 ;
enum V_78 V_79 = 0 ;
enum V_80 V_81 = 0 ;
int V_82 = 0 ;
static int V_83 ;
if ( ! ( V_2 -> V_84 & V_85 ) ) {
F_25 ( V_2 , 0 ) ;
goto V_15;
}
V_77 = V_2 -> V_24 . V_25 ;
if ( V_2 -> V_86 )
V_2 -> V_86 ( V_2 -> V_27 ) ;
F_26 ( V_2 , 1 ) ;
F_26 ( V_2 , 1 ) ;
F_27 ( V_2 ) ;
if ( V_2 -> V_87 )
V_2 -> V_87 ( V_2 -> V_27 ) ;
F_3 ( V_2 ) ;
V_2 -> V_30 = V_40 ;
V_2 -> V_88 ( V_2 -> V_27 ) ;
F_28 ( 50 ) ;
if ( V_2 -> V_89 )
V_2 -> V_89 ( V_2 -> V_27 , V_90 ) ;
if ( V_2 -> V_91 -> V_92 && V_2 -> V_91 -> V_93 &&
V_2 -> V_91 -> V_94 ) {
V_82 = 1 ;
V_79 = V_2 -> V_91 -> V_95 ;
V_81 = (enum V_80 ) V_2 -> V_91 -> V_94 ;
F_29 ( V_96 , L_1 ,
V_79 , V_81 ) ;
V_2 -> V_97 ( V_2 -> V_27 , V_98 ,
V_99 ) ;
}
F_25 ( V_2 , 0 ) ;
if ( V_82 ) {
F_29 ( V_96 , L_2 ) ;
if ( V_79 == V_100 )
V_2 -> V_26 ( V_2 -> V_27 , V_77 + 2 ) ;
else if ( V_79 == V_101 )
V_2 -> V_26 ( V_2 -> V_27 , V_77 - 2 ) ;
else
V_2 -> V_26 ( V_2 -> V_27 , V_77 ) ;
V_2 -> V_97 ( V_2 -> V_27 , V_81 , V_79 ) ;
} else {
V_2 -> V_26 ( V_2 -> V_27 , V_77 ) ;
}
if ( V_2 -> V_89 )
V_2 -> V_89 ( V_2 -> V_27 , V_102 ) ;
V_2 -> V_30 = V_31 ;
V_2 -> V_88 ( V_2 -> V_27 ) ;
F_26 ( V_2 , 0 ) ;
if ( V_2 -> V_103 . V_104 == 0 ||
V_2 -> V_103 . V_105 == 0 ) {
V_2 -> V_103 . V_104 = 1 ;
V_2 -> V_103 . V_105 = 1 ;
}
if ( V_2 -> V_106 )
V_2 -> V_106 ( V_2 -> V_27 ) ;
if ( V_2 -> V_13 == V_28 || V_2 -> V_13 == V_29 )
F_4 ( V_2 ) ;
F_30 ( V_2 ) ;
V_83 = 0 ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_38 || ! ( V_2 -> V_48 ) ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_2 -> V_30 == V_31 ) {
F_32 ( V_2 -> V_107 , & V_2 -> V_76 ) ;
return 0 ;
}
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 , V_52 , V_108 ;
short V_48 ;
unsigned long V_34 ;
F_11 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
V_48 = V_2 -> V_48 ;
V_52 = ( V_6 -> V_56 . V_57 < V_109 ) ? V_6 -> V_56 . V_57 :
V_109 ;
if ( V_52 > V_109 ) {
V_8 = - V_110 ;
goto V_15;
}
if ( V_2 -> V_13 == V_38 ) {
V_8 = - 1 ;
goto V_15;
}
for ( V_108 = 0 ; V_108 < V_52 ; V_108 ++ ) {
if ( V_33 [ V_108 ] < 0 ) {
V_8 = - 1 ;
goto V_15;
}
}
if ( V_48 )
F_12 ( V_2 , true ) ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
if ( V_6 -> V_56 . V_34 && V_6 -> V_56 . V_57 ) {
strncpy ( V_2 -> V_24 . V_53 , V_33 , V_52 ) ;
V_2 -> V_24 . V_54 = V_52 ;
V_2 -> V_51 = false ;
V_2 -> V_55 = 1 ;
} else {
V_2 -> V_55 = 0 ;
V_2 -> V_24 . V_53 [ 0 ] = '\0' ;
V_2 -> V_24 . V_54 = 0 ;
}
F_9 ( & V_2 -> V_39 , V_34 ) ;
if ( V_48 )
F_13 ( V_2 ) ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
V_6 -> V_72 = V_2 -> V_13 ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int * V_111 = ( int * ) V_33 ;
int V_112 = ( V_111 [ 0 ] > 0 ) ;
short V_113 = V_2 -> V_114 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_112 )
V_2 -> V_114 = 1 ;
else
V_2 -> V_114 = 0 ;
F_36 ( V_115 L_3 ,
V_2 -> V_114 ? L_4 : L_5 ) ;
if ( V_2 -> V_13 == V_38 ) {
if ( V_113 == 0 && V_2 -> V_114 ) {
if ( V_2 -> V_106 )
V_2 -> V_106 ( V_2 -> V_27 ) ;
F_37 ( V_2 -> V_27 ) ;
}
if ( V_113 && V_2 -> V_114 == 1 )
F_38 ( V_2 -> V_27 ) ;
}
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
strcpy ( V_6 -> V_116 , L_6 ) ;
if ( V_2 -> V_117 & V_118 )
strcat ( V_6 -> V_116 , L_7 ) ;
if ( V_2 -> V_117 & V_119 )
strcat ( V_6 -> V_116 , L_8 ) ;
if ( V_2 -> V_72 & ( V_120 | V_121 ) )
strcat ( V_6 -> V_116 , L_9 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 ;
if ( ( ! V_2 -> V_122 ) ||
( ! V_2 -> V_123 ) ||
( ! V_2 -> V_124 ) ) {
F_41 ( V_125 , L_10
L_11 , V_126 ) ;
return - 1 ;
}
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_127 . V_66 ) {
F_29 ( V_96 , L_12 , V_126 ) ;
V_2 -> V_128 = V_129 ;
goto exit;
}
if ( V_6 -> V_127 . V_34 & V_130 ) {
V_2 -> V_131 = V_6 -> V_127 . V_60 / 1000 ;
F_29 ( V_96 , L_13 , V_126 ,
V_2 -> V_131 ) ;
}
if ( V_6 -> V_127 . V_34 & V_132 )
V_2 -> V_133 = V_6 -> V_127 . V_60 / 1000 ;
switch ( V_6 -> V_127 . V_34 & V_134 ) {
case V_135 :
V_2 -> V_128 = V_136 ;
break;
case V_137 :
V_2 -> V_128 = V_138 ;
break;
case V_139 :
V_2 -> V_128 = V_136 | V_138 ;
break;
case V_140 :
break;
default:
V_8 = - V_23 ;
goto exit;
}
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_128 == V_129 ) {
V_6 -> V_127 . V_66 = 1 ;
goto exit;
}
V_6 -> V_127 . V_66 = 0 ;
if ( ( V_6 -> V_127 . V_34 & V_141 ) == V_130 ) {
V_6 -> V_127 . V_34 = V_130 ;
V_6 -> V_127 . V_60 = V_2 -> V_131 * 1000 ;
} else {
V_6 -> V_127 . V_34 = V_132 ;
V_6 -> V_127 . V_60 = V_2 -> V_133 * 1000 ;
}
if ( ( V_2 -> V_128 & ( V_138 | V_136 ) ) ==
( V_138 | V_136 ) )
V_6 -> V_127 . V_34 |= V_139 ;
else if ( V_2 -> V_128 & V_138 )
V_6 -> V_127 . V_34 |= V_137 ;
else
V_6 -> V_127 . V_34 |= V_135 ;
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
