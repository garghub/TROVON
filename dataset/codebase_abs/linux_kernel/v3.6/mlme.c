void F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_3 ( V_6 ) ;
F_4 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
F_5 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_6 ) ;
}
void F_7 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const T_1 * V_3 , T_2 V_4 )
{
T_3 V_14 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
T_1 * V_17 = V_16 -> V_18 . V_19 . V_20 ;
int V_21 = F_8 ( struct V_15 , V_18 . V_19 . V_20 ) ;
F_3 ( V_6 ) ;
V_14 = F_9 ( V_16 -> V_18 . V_19 . V_14 ) ;
if ( V_14 != V_22 && V_6 -> V_23 &&
F_10 ( V_6 ) ) {
F_11 ( V_13 ) ;
goto V_24;
}
F_12 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_14 != V_22 && V_6 -> V_23 ) {
F_13 ( V_6 ) ;
F_11 ( V_13 ) ;
goto V_24;
}
if ( ! V_6 -> V_23 && V_6 -> V_25 == V_26 ) {
V_6 -> V_25 = V_27 ;
}
F_14 ( V_2 , V_16 -> V_28 , NULL , 0 , V_17 , V_4 - V_21 ,
V_14 ,
V_14 == V_22 , V_13 ) ;
V_24:
F_6 ( V_6 ) ;
}
void F_15 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
const T_1 * V_28 = V_16 -> V_28 ;
bool V_29 = false ;
F_16 ( V_6 ) ;
if ( V_6 -> V_30 &&
F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_18 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
V_29 = true ;
}
F_19 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 == V_32 && V_29 ) {
T_3 V_33 ;
bool V_34 ;
V_33 = F_9 ( V_16 -> V_18 . V_35 . V_33 ) ;
V_34 = ! F_17 ( V_16 -> V_36 , V_2 -> V_37 ) ;
F_20 ( V_2 , NULL , 0 , V_33 , V_34 ) ;
} else if ( V_6 -> V_25 == V_27 ) {
F_14 ( V_2 , V_16 -> V_28 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
}
}
void F_21 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_6 ) ;
F_15 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_6 ) ;
}
void F_22 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
const T_1 * V_28 = V_16 -> V_28 ;
T_3 V_33 ;
bool V_34 ;
F_16 ( V_6 ) ;
F_23 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 != V_32 )
return;
if ( V_6 -> V_30 &&
F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_24 ( V_2 , V_6 -> V_30 ) ;
F_18 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
} else
F_25 ( 1 ) ;
V_33 = F_9 ( V_16 -> V_18 . V_39 . V_33 ) ;
V_34 = ! F_17 ( V_16 -> V_36 , V_2 -> V_37 ) ;
F_20 ( V_2 , NULL , 0 , V_33 , V_34 ) ;
}
void F_26 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_6 ) ;
F_22 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_6 ) ;
}
void F_27 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_28 ( V_10 , V_2 , V_3 , V_4 , V_40 ) ;
}
void F_29 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_30 ( V_10 , V_2 , V_3 , V_4 , V_40 ) ;
}
void F_31 ( struct V_1 * V_2 , const T_1 * V_41 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_3 ( V_6 ) ;
F_32 ( V_10 , V_2 , V_41 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_14 ( V_2 , V_41 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
F_6 ( V_6 ) ;
}
void F_33 ( struct V_1 * V_2 , const T_1 * V_41 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_3 ( V_6 ) ;
F_34 ( V_10 , V_2 , V_41 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_14 ( V_2 , V_41 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
F_6 ( V_6 ) ;
}
void F_35 ( struct V_1 * V_2 , const T_1 * V_41 ,
enum V_42 V_43 , int V_44 ,
const T_1 * V_45 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
#ifdef F_36
union V_47 V_48 ;
char * V_3 = F_37 ( 128 , V_46 ) ;
if ( V_3 ) {
sprintf ( V_3 , L_1
L_2 , V_44 ,
V_43 == V_49 ? L_3 : L_4 ,
V_41 ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_50 . V_51 = strlen ( V_3 ) ;
F_38 ( V_2 , V_52 , & V_48 , V_3 ) ;
F_39 ( V_3 ) ;
}
#endif
F_40 ( V_10 , V_2 , V_41 , V_43 , V_44 , V_45 , V_46 ) ;
}
int F_41 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_53 * V_54 ,
enum V_55 V_56 ,
const T_1 * V_28 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 ,
const T_1 * V_60 , int V_61 , int V_62 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_63 V_64 ;
int V_65 ;
F_16 ( V_6 ) ;
if ( V_56 == V_66 )
if ( ! V_60 || ! V_61 || V_62 < 0 || V_62 > 4 )
return - V_67 ;
if ( V_6 -> V_30 &&
F_17 ( V_28 , V_6 -> V_30 -> V_31 . V_28 ) )
return - V_68 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_17 = V_17 ;
V_64 . V_59 = V_59 ;
V_64 . V_56 = V_56 ;
V_64 . V_13 = F_42 ( & V_10 -> V_8 , V_54 , V_28 , V_57 , V_58 ,
V_69 , V_69 ) ;
V_64 . V_60 = V_60 ;
V_64 . V_61 = V_61 ;
V_64 . V_62 = V_62 ;
if ( ! V_64 . V_13 )
return - V_70 ;
V_65 = F_43 ( V_10 , V_6 , V_64 . V_13 -> V_71 ,
V_72 ) ;
if ( V_65 )
goto V_24;
V_65 = V_10 -> V_73 -> V_74 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
V_24:
F_11 ( V_64 . V_13 ) ;
return V_65 ;
}
int F_44 ( struct V_9 * V_10 ,
struct V_1 * V_2 , struct V_53 * V_54 ,
enum V_55 V_56 , const T_1 * V_28 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 ,
const T_1 * V_60 , int V_61 , int V_62 )
{
int V_65 ;
F_45 ( & V_10 -> V_75 ) ;
F_3 ( V_2 -> V_7 ) ;
V_65 = F_41 ( V_10 , V_2 , V_54 , V_56 , V_28 ,
V_57 , V_58 , V_17 , V_59 ,
V_60 , V_61 , V_62 ) ;
F_6 ( V_2 -> V_7 ) ;
F_46 ( & V_10 -> V_75 ) ;
return V_65 ;
}
void F_47 ( struct V_76 * V_77 ,
const struct V_76 * V_78 )
{
int V_79 ;
T_1 * V_80 , * V_81 ;
if ( ! V_78 ) {
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
return;
}
V_80 = ( T_1 * ) ( V_77 ) ;
V_81 = ( T_1 * ) ( V_78 ) ;
for ( V_79 = 0 ; V_79 < sizeof( * V_77 ) ; V_79 ++ )
V_80 [ V_79 ] &= V_81 [ V_79 ] ;
}
int F_48 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_53 * V_54 ,
const T_1 * V_28 , const T_1 * V_82 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 , bool V_83 ,
struct V_84 * V_85 ,
T_5 V_86 , struct V_76 * V_77 ,
struct V_76 * V_78 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_87 V_64 ;
int V_65 ;
bool V_88 = false ;
F_16 ( V_6 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_6 -> V_30 && V_82 &&
F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_82 ) ) {
if ( V_6 -> V_25 == V_32 ) {
V_88 = true ;
V_6 -> V_25 = V_27 ;
}
} else if ( V_6 -> V_30 )
return - V_68 ;
V_64 . V_17 = V_17 ;
V_64 . V_59 = V_59 ;
memcpy ( & V_64 . V_89 , V_85 , sizeof( V_64 . V_89 ) ) ;
V_64 . V_83 = V_83 ;
V_64 . V_82 = V_82 ;
V_64 . V_90 = V_86 ;
if ( V_77 )
memcpy ( & V_64 . V_77 , V_77 , sizeof( V_64 . V_77 ) ) ;
if ( V_78 )
memcpy ( & V_64 . V_78 , V_78 ,
sizeof( V_64 . V_78 ) ) ;
F_47 ( & V_64 . V_78 ,
V_10 -> V_8 . V_91 ) ;
V_64 . V_13 = F_42 ( & V_10 -> V_8 , V_54 , V_28 , V_57 , V_58 ,
V_69 , V_69 ) ;
if ( ! V_64 . V_13 ) {
if ( V_88 )
V_6 -> V_25 = V_32 ;
return - V_70 ;
}
V_65 = F_43 ( V_10 , V_6 , V_64 . V_13 -> V_71 ,
V_72 ) ;
if ( V_65 )
goto V_24;
V_65 = V_10 -> V_73 -> V_92 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
V_24:
if ( V_65 ) {
if ( V_88 )
V_6 -> V_25 = V_32 ;
F_11 ( V_64 . V_13 ) ;
}
return V_65 ;
}
int F_49 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_53 * V_54 ,
const T_1 * V_28 , const T_1 * V_82 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 , bool V_83 ,
struct V_84 * V_85 ,
T_5 V_86 , struct V_76 * V_77 ,
struct V_76 * V_78 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_65 ;
F_45 ( & V_10 -> V_75 ) ;
F_3 ( V_6 ) ;
V_65 = F_48 ( V_10 , V_2 , V_54 , V_28 , V_82 ,
V_57 , V_58 , V_17 , V_59 , V_83 , V_85 ,
V_86 , V_77 , V_78 ) ;
F_6 ( V_6 ) ;
F_46 ( & V_10 -> V_75 ) ;
return V_65 ;
}
int F_50 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_93 ,
bool V_94 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_95 V_64 = {
. V_28 = V_28 ,
. V_33 = V_93 ,
. V_17 = V_17 ,
. V_59 = V_59 ,
} ;
F_16 ( V_6 ) ;
if ( V_94 ) {
if ( V_6 -> V_30 &&
F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_18 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
return 0 ;
}
return V_10 -> V_73 -> V_35 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
}
int F_51 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_93 ,
bool V_94 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_65 ;
F_3 ( V_6 ) ;
V_65 = F_50 ( V_10 , V_2 , V_28 , V_17 , V_59 , V_93 ,
V_94 ) ;
F_6 ( V_6 ) ;
return V_65 ;
}
static int F_52 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_93 ,
bool V_94 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_96 V_64 ;
F_16 ( V_6 ) ;
if ( V_6 -> V_25 != V_32 )
return - V_97 ;
if ( F_25 ( ! V_6 -> V_30 ) )
return - V_97 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_33 = V_93 ;
V_64 . V_94 = V_94 ;
V_64 . V_17 = V_17 ;
V_64 . V_59 = V_59 ;
if ( F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) )
V_64 . V_13 = & V_6 -> V_30 -> V_31 ;
else
return - V_97 ;
return V_10 -> V_73 -> V_39 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
}
int F_53 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_93 ,
bool V_94 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_65 ;
F_3 ( V_6 ) ;
V_65 = F_52 ( V_10 , V_2 , V_28 , V_17 , V_59 , V_93 ,
V_94 ) ;
F_6 ( V_6 ) ;
return V_65 ;
}
void F_54 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_95 V_64 ;
T_1 V_28 [ V_98 ] ;
F_16 ( V_6 ) ;
if ( ! V_10 -> V_73 -> V_35 )
return;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_33 = V_99 ;
V_64 . V_17 = NULL ;
V_64 . V_59 = 0 ;
if ( ! V_6 -> V_30 )
return;
memcpy ( V_28 , V_6 -> V_30 -> V_31 . V_28 , V_98 ) ;
V_64 . V_28 = V_28 ;
V_10 -> V_73 -> V_35 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
if ( V_6 -> V_30 ) {
F_18 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
}
void F_55 ( struct V_5 * V_6 , T_6 V_100 ,
struct V_53 * V_54 ,
enum V_101 V_102 ,
unsigned int V_103 , T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_56 ( V_10 , V_6 , V_100 , V_54 , V_102 ,
V_103 , V_46 ) ;
}
void F_57 ( struct V_5 * V_6 , T_6 V_100 ,
struct V_53 * V_54 ,
enum V_101 V_102 ,
T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_58 ( V_10 , V_6 , V_100 , V_54 ,
V_102 , V_46 ) ;
}
void F_59 ( struct V_1 * V_2 , const T_1 * V_104 ,
struct V_105 * V_106 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_60 ( V_10 , V_2 , V_104 , V_106 , V_46 ) ;
}
void F_61 ( struct V_1 * V_2 , const T_1 * V_104 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_62 ( V_10 , V_2 , V_104 , V_46 ) ;
}
int F_63 ( struct V_5 * V_6 , T_5 V_107 ,
T_3 V_108 , const T_1 * V_109 ,
int V_110 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_111 * V_112 , * V_113 ;
int V_65 = 0 ;
T_3 V_114 ;
if ( ! V_6 -> V_8 -> V_115 )
return - V_116 ;
if ( ( V_108 & V_117 ) != V_118 )
return - V_67 ;
if ( V_108 & ~ ( V_117 | V_119 ) )
return - V_67 ;
V_114 = ( V_108 & V_119 ) >> 4 ;
if ( ! ( V_6 -> V_8 -> V_115 [ V_6 -> V_120 ] . V_121 & F_64 ( V_114 ) ) )
return - V_67 ;
V_113 = F_65 ( sizeof( * V_112 ) + V_110 , V_11 ) ;
if ( ! V_113 )
return - V_122 ;
F_66 ( & V_6 -> V_123 ) ;
F_67 (reg, &wdev->mgmt_registrations, list) {
int V_124 = F_68 ( V_110 , V_112 -> V_110 ) ;
if ( V_108 != F_9 ( V_112 -> V_108 ) )
continue;
if ( memcmp ( V_112 -> V_125 , V_109 , V_124 ) == 0 ) {
V_65 = - V_68 ;
break;
}
}
if ( V_65 ) {
F_39 ( V_113 ) ;
goto V_24;
}
memcpy ( V_113 -> V_125 , V_109 , V_110 ) ;
V_113 -> V_110 = V_110 ;
V_113 -> V_126 = V_107 ;
V_113 -> V_108 = F_69 ( V_108 ) ;
F_70 ( & V_113 -> V_127 , & V_6 -> V_128 ) ;
if ( V_10 -> V_73 -> V_129 )
V_10 -> V_73 -> V_129 ( V_8 , V_6 , V_108 , true ) ;
V_24:
F_71 ( & V_6 -> V_123 ) ;
return V_65 ;
}
void F_72 ( struct V_5 * V_6 , T_5 V_126 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_111 * V_112 , * V_130 ;
F_66 ( & V_6 -> V_123 ) ;
F_73 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_112 -> V_126 != V_126 )
continue;
if ( V_10 -> V_73 -> V_129 ) {
T_3 V_108 = F_9 ( V_112 -> V_108 ) ;
V_10 -> V_73 -> V_129 ( V_8 , V_6 ,
V_108 , false ) ;
}
F_74 ( & V_112 -> V_127 ) ;
F_39 ( V_112 ) ;
}
F_71 ( & V_6 -> V_123 ) ;
if ( V_126 == V_6 -> V_131 )
V_6 -> V_131 = 0 ;
}
void F_75 ( struct V_5 * V_6 )
{
struct V_111 * V_112 , * V_130 ;
F_66 ( & V_6 -> V_123 ) ;
F_73 (reg, tmp, &wdev->mgmt_registrations, list) {
F_74 ( & V_112 -> V_127 ) ;
F_39 ( V_112 ) ;
}
F_71 ( & V_6 -> V_123 ) ;
}
int F_76 ( struct V_9 * V_10 ,
struct V_5 * V_6 ,
struct V_53 * V_54 , bool V_132 ,
enum V_101 V_102 ,
bool V_133 , unsigned int V_134 ,
const T_1 * V_3 , T_2 V_4 , bool V_135 ,
bool V_136 , T_6 * V_100 )
{
struct V_1 * V_2 = V_6 -> V_137 ;
const struct V_15 * V_16 ;
T_3 V_138 ;
if ( ! V_6 -> V_8 -> V_115 )
return - V_116 ;
if ( ! V_10 -> V_73 -> V_139 )
return - V_116 ;
if ( V_4 < 24 + 1 )
return - V_67 ;
V_16 = ( const struct V_15 * ) V_3 ;
if ( ! F_77 ( V_16 -> V_140 ) )
return - V_67 ;
V_138 = F_9 ( V_16 -> V_140 ) & V_119 ;
if ( ! ( V_6 -> V_8 -> V_115 [ V_6 -> V_120 ] . V_141 & F_64 ( V_138 >> 4 ) ) )
return - V_67 ;
if ( F_78 ( V_16 -> V_140 ) &&
V_16 -> V_18 . V_142 . V_143 != V_144 ) {
int V_65 = 0 ;
F_3 ( V_6 ) ;
switch ( V_6 -> V_120 ) {
case V_145 :
case V_146 :
case V_147 :
if ( ! V_6 -> V_30 ) {
V_65 = - V_97 ;
break;
}
if ( ! F_17 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_28 ) ) {
V_65 = - V_97 ;
break;
}
if ( V_6 -> V_120 == V_145 )
break;
if ( ! F_17 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_148 ) ) {
V_65 = - V_97 ;
break;
}
break;
case V_149 :
case V_150 :
case V_151 :
if ( ! F_17 ( V_16 -> V_28 , V_2 -> V_37 ) )
V_65 = - V_67 ;
break;
case V_152 :
if ( ! F_17 ( V_16 -> V_36 , V_16 -> V_28 ) ) {
V_65 = - V_67 ;
break;
}
break;
default:
V_65 = - V_116 ;
break;
}
F_6 ( V_6 ) ;
if ( V_65 )
return V_65 ;
}
if ( ! F_17 ( V_16 -> V_36 , V_2 -> V_37 ) )
return - V_67 ;
return V_10 -> V_73 -> V_139 ( & V_10 -> V_8 , V_6 , V_54 , V_132 ,
V_102 , V_133 ,
V_134 , V_3 , V_4 , V_135 , V_136 ,
V_100 ) ;
}
bool F_79 ( struct V_5 * V_6 , int V_153 , int V_154 ,
const T_1 * V_3 , T_2 V_4 , T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_111 * V_112 ;
const struct V_155 * V_156 =
& V_8 -> V_115 [ V_6 -> V_120 ] ;
struct V_15 * V_16 = ( void * ) V_3 ;
const T_1 * V_50 ;
int V_157 ;
bool V_158 = false ;
T_7 V_159 = V_16 -> V_140 &
F_69 ( V_117 | V_119 ) ;
T_3 V_138 ;
V_138 = ( F_9 ( V_16 -> V_140 ) & V_119 ) >> 4 ;
if ( ! ( V_156 -> V_121 & F_64 ( V_138 ) ) )
return false ;
V_50 = V_3 + F_80 ( V_16 -> V_140 ) ;
V_157 = V_4 - F_80 ( V_16 -> V_140 ) ;
F_66 ( & V_6 -> V_123 ) ;
F_67 (reg, &wdev->mgmt_registrations, list) {
if ( V_112 -> V_108 != V_159 )
continue;
if ( V_112 -> V_110 > V_157 )
continue;
if ( memcmp ( V_112 -> V_125 , V_50 , V_112 -> V_110 ) )
continue;
if ( F_81 ( V_10 , V_6 , V_112 -> V_126 ,
V_153 , V_154 ,
V_3 , V_4 , V_46 ) )
continue;
V_158 = true ;
break;
}
F_71 ( & V_6 -> V_123 ) ;
return V_158 ;
}
void F_82 ( struct V_5 * V_6 , T_6 V_100 ,
const T_1 * V_3 , T_2 V_4 , bool V_160 , T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_83 ( V_10 , V_6 , V_100 , V_3 , V_4 , V_160 , V_46 ) ;
}
void F_84 ( struct V_1 * V_2 ,
enum V_161 V_162 ,
T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_85 ( V_10 , V_2 , V_162 , V_46 ) ;
}
void F_86 ( struct V_1 * V_2 ,
const T_1 * V_163 , T_5 V_164 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_87 ( V_10 , V_2 , V_163 , V_164 , V_46 ) ;
}
void F_88 ( struct V_1 * V_2 ,
const T_1 * V_163 , T_5 V_164 ,
T_5 V_165 , T_5 V_166 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_89 ( V_10 , V_2 , V_163 , V_164 ,
V_165 , V_166 , V_46 ) ;
}
void F_90 ( struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_167 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_91 ( V_10 , V_2 , V_28 , V_167 , V_46 ) ;
}
void F_92 ( struct V_1 * V_2 , int V_168 ,
const T_1 * V_28 , bool V_169 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_93 ( V_10 , V_2 , V_168 , V_28 , V_169 , V_46 ) ;
}
void F_94 ( struct V_1 * V_2 , int V_153 ,
enum V_101 type )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_53 * V_54 ;
F_3 ( V_6 ) ;
if ( F_25 ( V_6 -> V_120 != V_149 &&
V_6 -> V_120 != V_150 ) )
goto V_24;
V_54 = F_95 ( V_10 , V_153 , type ) ;
if ( F_25 ( ! V_54 ) )
goto V_24;
V_6 -> V_71 = V_54 ;
F_96 ( V_10 , V_2 , V_153 , type , V_11 ) ;
V_24:
F_6 ( V_6 ) ;
return;
}
bool F_97 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_25 ( V_6 -> V_120 != V_149 &&
V_6 -> V_120 != V_150 ) )
return false ;
return F_98 ( V_2 , V_41 , V_46 ) ;
}
bool F_99 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_25 ( V_6 -> V_120 != V_149 &&
V_6 -> V_120 != V_150 &&
V_6 -> V_120 != V_151 ) )
return false ;
return F_100 ( V_2 , V_41 , V_46 ) ;
}
