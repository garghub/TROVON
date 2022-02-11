int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_14 ) {
V_8 = - V_15 ;
goto V_16;
}
if ( V_10 -> V_17 == 1 ) {
if ( ( V_10 -> V_18 >= ( int ) 2.412e8 &&
V_10 -> V_18 <= ( int ) 2.487e8 ) ) {
int V_19 = V_10 -> V_18 / 100000 ;
int V_20 = 0 ;
while ( ( V_20 < 14 ) && ( V_19 != V_21 [ V_20 ] ) )
V_20 ++ ;
V_10 -> V_17 = 0 ;
V_10 -> V_18 = V_20 + 1 ;
}
}
if ( V_10 -> V_17 > 0 || V_10 -> V_18 > 14 || V_10 -> V_18 < 1 ) {
V_8 = - V_15 ;
goto V_16;
} else {
if ( ! ( F_3 ( V_2 ) -> V_22 ) [ V_10 -> V_18 ] ) {
V_8 = - V_23 ;
goto V_16;
}
V_2 -> V_24 . V_25 = V_10 -> V_18 ;
V_2 -> V_26 ( V_2 -> V_27 , V_2 -> V_24 . V_25 ) ;
if ( V_2 -> V_13 == V_28 || V_2 -> V_13 == V_29 )
if ( V_2 -> V_30 == V_31 ) {
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
}
V_8 = 0 ;
V_16:
F_6 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( V_2 -> V_24 . V_25 == 0 )
return - 1 ;
V_10 -> V_18 = V_21 [ V_2 -> V_24 . V_25 - 1 ] * 100000 ;
V_10 -> V_17 = 1 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
unsigned long V_34 ;
V_6 -> V_35 . V_36 = V_37 ;
if ( V_2 -> V_13 == V_38 )
return - 1 ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
if ( V_2 -> V_30 != V_31 &&
V_2 -> V_30 != V_40 &&
V_2 -> V_41 == 0 )
F_10 ( V_6 -> V_35 . V_42 ) ;
else
memcpy ( V_6 -> V_35 . V_42 ,
V_2 -> V_24 . V_43 , V_44 ) ;
F_11 ( & V_2 -> V_39 , V_34 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_45 ,
char * V_33 )
{
int V_8 = 0 ;
unsigned long V_34 ;
short V_46 = V_2 -> V_47 ;
struct V_48 * V_49 = (struct V_48 * ) V_45 ;
V_2 -> V_50 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_29 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_49 -> V_36 != V_37 ) {
V_8 = - V_23 ;
goto V_16;
}
if ( V_46 )
F_13 ( V_2 ) ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
memcpy ( V_2 -> V_24 . V_43 , V_49 -> V_42 , V_44 ) ;
V_2 -> V_41 = ! F_14 ( V_49 -> V_42 ) ;
F_11 ( & V_2 -> V_39 , V_34 ) ;
if ( V_46 )
F_15 ( V_2 ) ;
V_16:
F_6 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 , union V_5 * V_6 , char * V_7 )
{
int V_51 , V_8 = 0 ;
unsigned long V_34 ;
if ( V_2 -> V_13 == V_38 )
return - 1 ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
if ( V_2 -> V_24 . V_52 [ 0 ] == '\0' ||
V_2 -> V_24 . V_53 == 0 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_2 -> V_30 != V_31 &&
V_2 -> V_30 != V_40 &&
V_2 -> V_54 == 0 ) {
V_8 = - 1 ;
goto V_16;
}
V_51 = V_2 -> V_24 . V_53 ;
V_6 -> V_55 . V_56 = V_51 ;
strncpy ( V_7 , V_2 -> V_24 . V_52 , V_51 ) ;
V_6 -> V_55 . V_34 = 1 ;
V_16:
F_11 ( & V_2 -> V_39 , V_34 ) ;
return V_8 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_1 V_57 = V_6 -> V_58 . V_59 ;
V_2 -> V_60 = V_57 / 100000 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
T_1 V_61 ;
V_61 = F_19 ( V_2 , V_2 -> V_62 . V_63 ) ;
V_6 -> V_58 . V_59 = V_61 * 500000 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
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
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
V_6 -> V_64 . V_59 = V_2 -> V_64 ;
V_6 -> V_64 . V_66 = 0 ;
V_6 -> V_64 . V_65 = ( V_6 -> V_64 . V_59 == V_67 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
V_2 -> V_50 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_70 == V_2 -> V_13 )
goto V_16;
if ( V_6 -> V_70 == V_38 )
V_2 -> V_27 -> type = V_71 ;
else
V_2 -> V_27 -> type = V_37 ;
if ( ! V_2 -> V_47 ) {
V_2 -> V_13 = V_6 -> V_70 ;
} else {
F_13 ( V_2 ) ;
V_2 -> V_13 = V_6 -> V_70 ;
F_15 ( V_2 ) ;
}
V_16:
F_6 ( & V_2 -> V_12 ) ;
return 0 ;
}
void F_23 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_24 ( V_73 , struct V_1 , V_74 ) ;
short V_75 ;
T_2 V_76 = 0 ;
T_3 V_77 = 0 ;
int V_78 = 0 ;
V_75 = V_2 -> V_24 . V_25 ;
F_25 ( V_2 -> V_27 ) ;
if ( V_2 -> V_79 )
V_2 -> V_79 ( V_2 -> V_27 ) ;
F_4 ( V_2 ) ;
V_2 -> V_30 = V_40 ;
V_2 -> V_80 ( V_2 -> V_27 ) ;
V_2 -> V_81 ( V_2 -> V_27 , V_82 ) ;
if ( V_2 -> V_83 -> V_84 && V_2 -> V_83 -> V_85 && V_2 -> V_83 -> V_86 ) {
V_78 = 1 ;
V_76 = V_2 -> V_83 -> V_87 ;
V_77 = ( T_3 ) V_2 -> V_83 -> V_86 ;
F_26 ( L_1 , V_76 , V_77 ) ;
V_2 -> V_88 ( V_2 -> V_27 , V_89 , V_90 ) ;
}
F_27 ( V_2 ) ;
if ( V_78 ) {
F_26 ( L_2 ) ;
if ( V_76 == V_91 )
V_2 -> V_26 ( V_2 -> V_27 , V_75 + 2 ) ;
else if ( V_76 == V_92 )
V_2 -> V_26 ( V_2 -> V_27 , V_75 - 2 ) ;
else
V_2 -> V_26 ( V_2 -> V_27 , V_75 ) ;
V_2 -> V_88 ( V_2 -> V_27 , V_77 , V_76 ) ;
} else {
V_2 -> V_26 ( V_2 -> V_27 , V_75 ) ;
}
V_2 -> V_81 ( V_2 -> V_27 , V_93 ) ;
V_2 -> V_30 = V_31 ;
V_2 -> V_80 ( V_2 -> V_27 ) ;
if ( V_2 -> V_94 . V_95 == 0 || V_2 -> V_94 . V_96 == 0 ) {
V_2 -> V_94 . V_95 = 1 ;
V_2 -> V_94 . V_96 = 1 ;
}
if ( V_2 -> V_97 )
V_2 -> V_97 ( V_2 -> V_27 ) ;
if ( V_2 -> V_13 == V_28 || V_2 -> V_13 == V_29 )
F_5 ( V_2 ) ;
F_28 ( V_2 -> V_27 ) ;
F_6 ( & V_2 -> V_12 ) ;
}
int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 == V_38 || ! ( V_2 -> V_47 ) ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_2 -> V_30 == V_31 ) {
F_30 ( V_2 -> V_98 , & V_2 -> V_74 ) ;
return 0 ;
}
V_16:
F_6 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 , V_51 ;
short V_47 ;
unsigned long V_34 ;
V_2 -> V_50 = 1 ;
F_2 ( & V_2 -> V_12 ) ;
V_47 = V_2 -> V_47 ;
if ( V_6 -> V_55 . V_56 > V_99 ) {
V_8 = - V_100 ;
goto V_16;
}
if ( V_2 -> V_13 == V_38 ) {
V_8 = - 1 ;
goto V_16;
}
if ( V_47 )
F_13 ( V_2 ) ;
F_9 ( & V_2 -> V_39 , V_34 ) ;
if ( V_6 -> V_55 . V_34 && V_6 -> V_55 . V_56 ) {
V_51 = ( ( V_6 -> V_55 . V_56 - 1 ) < V_99 ) ? ( V_6 -> V_55 . V_56 - 1 ) : V_99 ;
strncpy ( V_2 -> V_24 . V_52 , V_33 , V_51 + 1 ) ;
V_2 -> V_24 . V_53 = V_51 + 1 ;
V_2 -> V_54 = 1 ;
} else {
V_2 -> V_54 = 0 ;
V_2 -> V_24 . V_52 [ 0 ] = '\0' ;
V_2 -> V_24 . V_53 = 0 ;
}
F_11 ( & V_2 -> V_39 , V_34 ) ;
if ( V_47 )
F_15 ( V_2 ) ;
V_16:
F_6 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
union V_5 * V_6 , char * V_7 )
{
V_6 -> V_70 = V_2 -> V_13 ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int * V_101 = ( int * ) V_33 ;
int V_102 = ( V_101 [ 0 ] > 0 ) ;
short V_103 = V_2 -> V_104 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_102 )
V_2 -> V_104 = 1 ;
else
V_2 -> V_104 = 0 ;
F_26 ( V_105 L_3 ,
V_2 -> V_104 ? L_4 : L_5 ) ;
if ( V_2 -> V_13 == V_38 ) {
if ( V_103 == 0 && V_2 -> V_104 ) {
if ( V_2 -> V_97 )
V_2 -> V_97 ( V_2 -> V_27 ) ;
F_28 ( V_2 -> V_27 ) ;
}
if ( V_103 && V_2 -> V_104 == 1 )
F_25 ( V_2 -> V_27 ) ;
}
F_6 ( & V_2 -> V_12 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
F_35 ( V_6 -> V_106 , L_6 , V_107 ) ;
if ( V_2 -> V_108 & V_109 ) {
F_36 ( V_6 -> V_106 , L_7 , V_107 ) ;
if ( V_2 -> V_108 & V_110 )
F_36 ( V_6 -> V_106 , L_8 , V_107 ) ;
} else if ( V_2 -> V_108 & V_110 ) {
F_36 ( V_6 -> V_106 , L_9 , V_107 ) ;
}
if ( V_2 -> V_70 & ( V_111 | V_112 ) )
F_36 ( V_6 -> V_106 , L_10 , V_107 ) ;
if ( ( V_2 -> V_30 == V_31 ) ||
( V_2 -> V_30 == V_40 ) )
F_36 ( V_6 -> V_106 , L_11 , V_107 ) ;
else if ( V_2 -> V_30 != V_113 )
F_36 ( V_6 -> V_106 , L_12 , V_107 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_12 ) ;
if ( V_6 -> V_114 . V_65 ) {
V_2 -> V_115 = V_116 ;
goto exit;
}
if ( V_6 -> V_114 . V_34 & V_117 ) {
V_2 -> V_118 = V_6 -> V_114 . V_59 / 1000 ;
}
if ( V_6 -> V_114 . V_34 & V_119 ) {
V_2 -> V_120 = V_6 -> V_114 . V_59 / 1000 ;
}
switch ( V_6 -> V_114 . V_34 & V_121 ) {
case V_122 :
V_2 -> V_115 = V_123 ;
break;
case V_124 :
V_2 -> V_115 = V_125 ;
break;
case V_126 :
V_2 -> V_115 = V_123 | V_125 ;
break;
case V_127 :
break;
default:
V_8 = - V_23 ;
goto exit;
}
exit:
F_6 ( & V_2 -> V_12 ) ;
return V_8 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_32 ,
union V_5 * V_6 , char * V_33 )
{
F_2 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_115 == V_116 ) {
V_6 -> V_114 . V_65 = 1 ;
goto exit;
}
V_6 -> V_114 . V_65 = 0 ;
if ( ( V_6 -> V_114 . V_34 & V_128 ) == V_117 ) {
V_6 -> V_114 . V_34 = V_117 ;
V_6 -> V_114 . V_59 = V_2 -> V_118 * 1000 ;
} else {
V_6 -> V_114 . V_34 = V_119 ;
V_6 -> V_114 . V_59 = V_2 -> V_120 * 1000 ;
}
if ( ( V_2 -> V_115 & ( V_125 | V_123 ) ) == ( V_125 | V_123 ) )
V_6 -> V_114 . V_34 |= V_126 ;
else if ( V_2 -> V_115 & V_125 )
V_6 -> V_114 . V_34 |= V_124 ;
else
V_6 -> V_114 . V_34 |= V_122 ;
exit:
F_6 ( & V_2 -> V_12 ) ;
return 0 ;
}
