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
F_9 ( V_6 -> V_35 . V_42 ) ;
else
memcpy ( V_6 -> V_35 . V_42 ,
V_2 -> V_24 . V_43 , V_44 ) ;
F_10 ( & V_2 -> V_39 , V_34 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_45 ,
char * V_33 )
{
int V_8 = 0 ;
unsigned long V_34 ;
short V_46 = V_2 -> V_47 ;
struct V_48 * V_49 = (struct V_48 * ) V_45 ;
F_12 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_29 ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_49 -> V_36 != V_37 ) {
V_8 = - V_23 ;
goto V_15;
}
if ( F_13 ( V_49 -> V_42 ) ) {
F_8 ( & V_2 -> V_39 , V_34 ) ;
F_14 ( V_2 -> V_24 . V_43 , V_49 -> V_42 ) ;
V_2 -> V_41 = 0 ;
F_10 ( & V_2 -> V_39 , V_34 ) ;
V_8 = - 1 ;
goto V_15;
}
if ( V_46 )
F_15 ( V_2 , true ) ;
F_8 ( & V_2 -> V_39 , V_34 ) ;
V_2 -> V_50 = false ;
F_14 ( V_2 -> V_24 . V_43 , V_49 -> V_42 ) ;
V_2 -> V_41 = ! F_13 ( V_49 -> V_42 ) ;
F_10 ( & V_2 -> V_39 , V_34 ) ;
if ( V_46 )
F_16 ( V_2 ) ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
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
F_10 ( & V_2 -> V_39 , V_34 ) ;
return V_8 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_1 V_57 = V_6 -> V_58 . V_59 ;
V_2 -> V_60 = V_57 / 100000 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_1 V_61 ;
V_61 = F_20 ( V_2 ,
V_2 -> V_62 . V_63 ) ;
V_6 -> V_58 . V_59 = V_61 * 500000 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
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
int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
V_6 -> V_64 . V_59 = V_2 -> V_64 ;
V_6 -> V_64 . V_66 = 0 ;
V_6 -> V_64 . V_65 = ( V_6 -> V_64 . V_59 == V_67 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_70 = 0 ;
F_12 ( V_2 ) ;
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
F_24 ( V_2 -> V_27 , false ) ;
} else {
V_2 -> V_27 -> type = V_37 ;
if ( V_2 -> V_13 == V_38 )
F_25 ( V_2 -> V_27 , false ) ;
}
if ( ! V_2 -> V_47 ) {
V_2 -> V_13 = V_6 -> V_71 ;
} else {
F_15 ( V_2 , true ) ;
V_2 -> V_13 = V_6 -> V_71 ;
F_16 ( V_2 ) ;
}
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_70 ;
}
void F_26 ( void * V_74 )
{
struct V_1 * V_2 = F_27 ( V_74 ,
struct V_1 , V_75 ) ;
short V_76 ;
enum V_77 V_78 = 0 ;
enum V_79 V_80 = 0 ;
int V_81 = 0 ;
if ( ! ( V_2 -> V_82 & V_83 ) ) {
F_28 ( V_2 , 0 ) ;
goto V_15;
}
V_76 = V_2 -> V_24 . V_25 ;
if ( V_2 -> V_84 )
V_2 -> V_84 ( V_2 -> V_27 ) ;
F_29 ( V_2 , 1 ) ;
F_29 ( V_2 , 1 ) ;
F_30 ( V_2 ) ;
if ( V_2 -> V_85 )
V_2 -> V_85 ( V_2 -> V_27 ) ;
F_3 ( V_2 ) ;
V_2 -> V_30 = V_40 ;
V_2 -> V_86 ( V_2 -> V_27 ) ;
F_31 ( 50 ) ;
if ( V_2 -> V_87 )
V_2 -> V_87 ( V_2 -> V_27 , V_88 ) ;
if ( V_2 -> V_89 -> V_90 && V_2 -> V_89 -> V_91 &&
V_2 -> V_89 -> V_92 ) {
V_81 = 1 ;
V_78 = V_2 -> V_89 -> V_93 ;
V_80 = (enum V_79 ) V_2 -> V_89 -> V_92 ;
F_32 ( V_94 , L_1 ,
V_78 , V_80 ) ;
V_2 -> V_95 ( V_2 -> V_27 , V_96 ,
V_97 ) ;
}
F_28 ( V_2 , 0 ) ;
if ( V_81 ) {
F_32 ( V_94 , L_2 ) ;
if ( V_78 == V_98 )
V_2 -> V_26 ( V_2 -> V_27 , V_76 + 2 ) ;
else if ( V_78 == V_99 )
V_2 -> V_26 ( V_2 -> V_27 , V_76 - 2 ) ;
else
V_2 -> V_26 ( V_2 -> V_27 , V_76 ) ;
V_2 -> V_95 ( V_2 -> V_27 , V_80 , V_78 ) ;
} else {
V_2 -> V_26 ( V_2 -> V_27 , V_76 ) ;
}
if ( V_2 -> V_87 )
V_2 -> V_87 ( V_2 -> V_27 , V_100 ) ;
V_2 -> V_30 = V_31 ;
V_2 -> V_86 ( V_2 -> V_27 ) ;
F_29 ( V_2 , 0 ) ;
if ( V_2 -> V_101 . V_102 == 0 ||
V_2 -> V_101 . V_103 == 0 ) {
V_2 -> V_101 . V_102 = 1 ;
V_2 -> V_101 . V_103 = 1 ;
}
if ( V_2 -> V_104 )
V_2 -> V_104 ( V_2 -> V_27 ) ;
if ( V_2 -> V_13 == V_28 || V_2 -> V_13 == V_29 )
F_4 ( V_2 ) ;
F_33 ( V_2 ) ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
}
int F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_38 || ! ( V_2 -> V_47 ) ) {
V_8 = - 1 ;
goto V_15;
}
if ( V_2 -> V_30 == V_31 ) {
F_35 ( & V_2 -> V_75 ) ;
return 0 ;
}
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 , V_51 , V_105 ;
short V_47 ;
unsigned long V_34 ;
F_12 ( V_2 ) ;
F_2 ( & V_2 -> V_12 ) ;
V_47 = V_2 -> V_47 ;
V_51 = F_37 ( V_106 , V_6 -> V_55 . V_56 , V_107 ) ;
if ( V_2 -> V_13 == V_38 ) {
V_8 = - 1 ;
goto V_15;
}
for ( V_105 = 0 ; V_105 < V_51 ; V_105 ++ ) {
if ( V_33 [ V_105 ] < 0 ) {
V_8 = - 1 ;
goto V_15;
}
}
if ( V_47 )
F_15 ( V_2 , true ) ;
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
F_10 ( & V_2 -> V_39 , V_34 ) ;
if ( V_47 )
F_16 ( V_2 ) ;
V_15:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
V_6 -> V_71 = V_2 -> V_13 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int * V_108 = ( int * ) V_33 ;
int V_109 = ( V_108 [ 0 ] > 0 ) ;
short V_110 = V_2 -> V_111 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_109 )
V_2 -> V_111 = 1 ;
else
V_2 -> V_111 = 0 ;
F_40 ( V_2 -> V_27 , L_3 ,
V_2 -> V_111 ? L_4 : L_5 ) ;
if ( V_2 -> V_13 == V_38 ) {
if ( V_110 == 0 && V_2 -> V_111 ) {
if ( V_2 -> V_104 )
V_2 -> V_104 ( V_2 -> V_27 ) ;
F_41 ( V_2 -> V_27 ) ;
}
if ( V_110 && V_2 -> V_111 == 1 )
F_42 ( V_2 -> V_27 ) ;
}
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
strcpy ( V_6 -> V_112 , L_6 ) ;
if ( V_2 -> V_113 & V_114 )
strcat ( V_6 -> V_112 , L_7 ) ;
if ( V_2 -> V_113 & V_115 )
strcat ( V_6 -> V_112 , L_8 ) ;
if ( V_2 -> V_71 & ( V_116 | V_117 ) )
strcat ( V_6 -> V_112 , L_9 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 ;
if ( ( ! V_2 -> V_118 ) ||
( ! V_2 -> V_119 ) ||
( ! V_2 -> V_120 ) ) {
F_45 ( V_2 -> V_27 ,
L_10 ,
V_121 ) ;
return - 1 ;
}
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_122 . V_65 ) {
F_32 ( V_94 , L_11 , V_121 ) ;
V_2 -> V_123 = V_124 ;
goto exit;
}
if ( V_6 -> V_122 . V_34 & V_125 ) {
V_2 -> V_126 = V_6 -> V_122 . V_59 / 1000 ;
F_32 ( V_94 , L_12 , V_121 ,
V_2 -> V_126 ) ;
}
if ( V_6 -> V_122 . V_34 & V_127 )
V_2 -> V_128 = V_6 -> V_122 . V_59 / 1000 ;
switch ( V_6 -> V_122 . V_34 & V_129 ) {
case V_130 :
V_2 -> V_123 = V_131 ;
break;
case V_132 :
V_2 -> V_123 = V_133 ;
break;
case V_134 :
V_2 -> V_123 = V_131 | V_133 ;
break;
case V_135 :
break;
default:
V_8 = - V_23 ;
goto exit;
}
exit:
F_5 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_123 == V_124 ) {
V_6 -> V_122 . V_65 = 1 ;
goto exit;
}
V_6 -> V_122 . V_65 = 0 ;
if ( ( V_6 -> V_122 . V_34 & V_136 ) == V_125 ) {
V_6 -> V_122 . V_34 = V_125 ;
V_6 -> V_122 . V_59 = V_2 -> V_126 * 1000 ;
} else {
V_6 -> V_122 . V_34 = V_127 ;
V_6 -> V_122 . V_59 = V_2 -> V_128 * 1000 ;
}
if ( ( V_2 -> V_123 & ( V_133 | V_131 ) ) ==
( V_133 | V_131 ) )
V_6 -> V_122 . V_34 |= V_134 ;
else if ( V_2 -> V_123 & V_133 )
V_6 -> V_122 . V_34 |= V_132 ;
else
V_6 -> V_122 . V_34 |= V_130 ;
exit:
F_5 ( & V_2 -> V_12 ) ;
return 0 ;
}
