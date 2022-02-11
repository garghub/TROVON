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
unsigned long V_34 ;
short V_46 = V_2 -> V_47 ;
struct V_48 * V_49 = (struct V_48 * ) V_45 ;
F_11 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_29 ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_49 -> V_36 != V_37 ) {
V_8 = - V_23 ;
goto V_15;
}
if ( F_12 ( V_49 -> V_42 ) ) {
F_8 ( & V_2 -> V_39 , V_34 ) ;
memcpy ( V_2 -> V_24 . V_44 , V_49 -> V_42 , V_43 ) ;
V_2 -> V_41 = 0 ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
V_8 = - 1 ;
goto V_15;
}
if ( V_46 )
F_13 ( V_2 , true ) ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
V_2 -> V_50 = false ;
memcpy ( V_2 -> V_24 . V_44 , V_49 -> V_42 , V_43 ) ;
V_2 -> V_41 = ! F_12 ( V_49 -> V_42 ) ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
if ( V_46 )
F_14 ( V_2 ) ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_51 , V_8 = 0 ;
unsigned long V_34 ;
if ( V_2 -> V_13 == V_38 )
return - 1 ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
if ( V_2 -> V_24 . V_52 [ 0 ] == '\0' ||
V_2 -> V_24 . V_53 == 0 ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_2 -> V_30 != V_31 &&
V_2 -> V_30 != V_40 &&
V_2 -> V_54 == 0 ) {
V_8 = - 1 ;
goto V_15;
}
V_51 = V_2 -> V_24 . V_53 ;
V_6 -> V_55 . V_56 = V_51 ;
strncpy ( V_7 , V_2 -> V_24 . V_52 , V_51 ) ;
V_6 -> V_55 . V_34 = 1 ;
V_15:
F_9 ( & V_2 -> V_39 , V_34 ) ;
return V_8 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_1 V_57 = V_6 -> V_58 . V_59 ;
V_2 -> V_60 = V_57 / 100000 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_1 V_61 = 0 ;
V_61 = F_18 ( V_2 ,
V_2 -> V_62 . V_63 ) ;
V_6 -> V_58 . V_59 = V_61 * 500000 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
if ( V_6 -> V_64 . V_65 || ! V_6 -> V_64 . V_66 )
V_2 -> V_64 = V_67 ;
else {
if ( V_6 -> V_64 . V_59 < V_68 ||
V_6 -> V_64 . V_59 > V_69 )
return - V_23 ;
V_2 -> V_64 = V_6 -> V_64 . V_59 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
V_6 -> V_64 . V_59 = V_2 -> V_64 ;
V_6 -> V_64 . V_66 = 0 ;
V_6 -> V_64 . V_65 = ( V_6 -> V_64 . V_59 == V_67 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_70 = 0 ;
F_11 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
switch ( V_6 -> V_71 ) {
case V_38 :
case V_28 :
case V_14 :
break;
case V_72 :
V_6 -> V_71 = V_14 ;
break;
default:
V_70 = - V_23 ;
goto V_15;
}
if ( V_6 -> V_71 == V_2 -> V_13 )
goto V_15;
if ( V_6 -> V_71 == V_38 ) {
V_2 -> V_27 -> type = V_73 ;
F_22 ( V_2 -> V_27 , false ) ;
} else {
V_2 -> V_27 -> type = V_37 ;
if ( V_2 -> V_13 == V_38 )
F_23 ( V_2 -> V_27 , false ) ;
}
if ( ! V_2 -> V_47 ) {
V_2 -> V_13 = V_6 -> V_71 ;
} else {
F_13 ( V_2 , true ) ;
V_2 -> V_13 = V_6 -> V_71 ;
F_14 ( V_2 ) ;
}
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_70 ;
}
void F_24 ( void * V_74 )
{
struct V_1 * V_2 = F_25 ( V_74 ,
struct V_1 , V_75 ) ;
short V_76 ;
enum V_77 V_78 = 0 ;
enum V_79 V_80 = 0 ;
int V_81 = 0 ;
static int V_82 ;
if ( ! ( V_2 -> V_83 & V_84 ) ) {
F_26 ( V_2 , 0 ) ;
goto V_15;
}
V_76 = V_2 -> V_24 . V_25 ;
if ( V_2 -> V_85 )
V_2 -> V_85 ( V_2 -> V_27 ) ;
F_27 ( V_2 , 1 ) ;
F_27 ( V_2 , 1 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_86 )
V_2 -> V_86 ( V_2 -> V_27 ) ;
F_3 ( V_2 ) ;
V_2 -> V_30 = V_40 ;
V_2 -> V_87 ( V_2 -> V_27 ) ;
F_29 ( 50 ) ;
if ( V_2 -> V_88 )
V_2 -> V_88 ( V_2 -> V_27 , V_89 ) ;
if ( V_2 -> V_90 -> V_91 && V_2 -> V_90 -> V_92 &&
V_2 -> V_90 -> V_93 ) {
V_81 = 1 ;
V_78 = V_2 -> V_90 -> V_94 ;
V_80 = (enum V_79 ) V_2 -> V_90 -> V_93 ;
F_30 ( V_95 , L_1 ,
V_78 , V_80 ) ;
V_2 -> V_96 ( V_2 -> V_27 , V_97 ,
V_98 ) ;
}
F_26 ( V_2 , 0 ) ;
if ( V_81 ) {
F_30 ( V_95 , L_2 ) ;
if ( V_78 == V_99 )
V_2 -> V_26 ( V_2 -> V_27 , V_76 + 2 ) ;
else if ( V_78 == V_100 )
V_2 -> V_26 ( V_2 -> V_27 , V_76 - 2 ) ;
else
V_2 -> V_26 ( V_2 -> V_27 , V_76 ) ;
V_2 -> V_96 ( V_2 -> V_27 , V_80 , V_78 ) ;
} else {
V_2 -> V_26 ( V_2 -> V_27 , V_76 ) ;
}
if ( V_2 -> V_88 )
V_2 -> V_88 ( V_2 -> V_27 , V_101 ) ;
V_2 -> V_30 = V_31 ;
V_2 -> V_87 ( V_2 -> V_27 ) ;
F_27 ( V_2 , 0 ) ;
if ( V_2 -> V_102 . V_103 == 0 ||
V_2 -> V_102 . V_104 == 0 ) {
V_2 -> V_102 . V_103 = 1 ;
V_2 -> V_102 . V_104 = 1 ;
}
if ( V_2 -> V_105 )
V_2 -> V_105 ( V_2 -> V_27 ) ;
if ( V_2 -> V_13 == V_28 || V_2 -> V_13 == V_29 )
F_4 ( V_2 ) ;
F_31 ( V_2 ) ;
V_82 = 0 ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_38 || ! ( V_2 -> V_47 ) ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_2 -> V_30 == V_31 ) {
F_33 ( V_2 -> V_106 , & V_2 -> V_75 ) ;
return 0 ;
}
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 , V_51 , V_107 ;
short V_47 ;
unsigned long V_34 ;
F_11 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
V_47 = V_2 -> V_47 ;
V_51 = ( V_6 -> V_55 . V_56 < V_108 ) ? V_6 -> V_55 . V_56 :
V_108 ;
if ( V_51 > V_108 ) {
V_8 = - V_109 ;
goto V_15;
}
if ( V_2 -> V_13 == V_38 ) {
V_8 = - 1 ;
goto V_15;
}
for ( V_107 = 0 ; V_107 < V_51 ; V_107 ++ ) {
if ( V_33 [ V_107 ] < 0 ) {
V_8 = - 1 ;
goto V_15;
}
}
if ( V_47 )
F_13 ( V_2 , true ) ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
if ( V_6 -> V_55 . V_34 && V_6 -> V_55 . V_56 ) {
strncpy ( V_2 -> V_24 . V_52 , V_33 , V_51 ) ;
V_2 -> V_24 . V_53 = V_51 ;
V_2 -> V_50 = false ;
V_2 -> V_54 = 1 ;
} else {
V_2 -> V_54 = 0 ;
V_2 -> V_24 . V_52 [ 0 ] = '\0' ;
V_2 -> V_24 . V_53 = 0 ;
}
F_9 ( & V_2 -> V_39 , V_34 ) ;
if ( V_47 )
F_14 ( V_2 ) ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
V_6 -> V_71 = V_2 -> V_13 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int * V_110 = ( int * ) V_33 ;
int V_111 = ( V_110 [ 0 ] > 0 ) ;
short V_112 = V_2 -> V_113 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_111 )
V_2 -> V_113 = 1 ;
else
V_2 -> V_113 = 0 ;
F_37 ( V_114 L_3 ,
V_2 -> V_113 ? L_4 : L_5 ) ;
if ( V_2 -> V_13 == V_38 ) {
if ( V_112 == 0 && V_2 -> V_113 ) {
if ( V_2 -> V_105 )
V_2 -> V_105 ( V_2 -> V_27 ) ;
F_38 ( V_2 -> V_27 ) ;
}
if ( V_112 && V_2 -> V_113 == 1 )
F_39 ( V_2 -> V_27 ) ;
}
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
strcpy ( V_6 -> V_115 , L_6 ) ;
if ( V_2 -> V_116 & V_117 )
strcat ( V_6 -> V_115 , L_7 ) ;
if ( V_2 -> V_116 & V_118 )
strcat ( V_6 -> V_115 , L_8 ) ;
if ( V_2 -> V_71 & ( V_119 | V_120 ) )
strcat ( V_6 -> V_115 , L_9 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 ;
if ( ( ! V_2 -> V_121 ) ||
( ! V_2 -> V_122 ) ||
( ! V_2 -> V_123 ) ) {
F_42 ( V_124 , L_10
L_11 , V_125 ) ;
return - 1 ;
}
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_126 . V_65 ) {
F_30 ( V_95 , L_12 , V_125 ) ;
V_2 -> V_127 = V_128 ;
goto exit;
}
if ( V_6 -> V_126 . V_34 & V_129 ) {
V_2 -> V_130 = V_6 -> V_126 . V_59 / 1000 ;
F_30 ( V_95 , L_13 , V_125 ,
V_2 -> V_130 ) ;
}
if ( V_6 -> V_126 . V_34 & V_131 )
V_2 -> V_132 = V_6 -> V_126 . V_59 / 1000 ;
switch ( V_6 -> V_126 . V_34 & V_133 ) {
case V_134 :
V_2 -> V_127 = V_135 ;
break;
case V_136 :
V_2 -> V_127 = V_137 ;
break;
case V_138 :
V_2 -> V_127 = V_135 | V_137 ;
break;
case V_139 :
break;
default:
V_8 = - V_23 ;
goto exit;
}
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_127 == V_128 ) {
V_6 -> V_126 . V_65 = 1 ;
goto exit;
}
V_6 -> V_126 . V_65 = 0 ;
if ( ( V_6 -> V_126 . V_34 & V_140 ) == V_129 ) {
V_6 -> V_126 . V_34 = V_129 ;
V_6 -> V_126 . V_59 = V_2 -> V_130 * 1000 ;
} else {
V_6 -> V_126 . V_34 = V_131 ;
V_6 -> V_126 . V_59 = V_2 -> V_132 * 1000 ;
}
if ( ( V_2 -> V_127 & ( V_137 | V_135 ) ) ==
( V_137 | V_135 ) )
V_6 -> V_126 . V_34 |= V_138 ;
else if ( V_2 -> V_127 & V_137 )
V_6 -> V_126 . V_34 |= V_136 ;
else
V_6 -> V_126 . V_34 |= V_134 ;
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
