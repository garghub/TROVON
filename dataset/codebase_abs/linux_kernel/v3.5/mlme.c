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
V_65 = V_10 -> V_71 -> V_72 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
F_11 ( V_64 . V_13 ) ;
return V_65 ;
}
int F_43 ( struct V_9 * V_10 ,
struct V_1 * V_2 , struct V_53 * V_54 ,
enum V_55 V_56 , const T_1 * V_28 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 ,
const T_1 * V_60 , int V_61 , int V_62 )
{
int V_65 ;
F_3 ( V_2 -> V_7 ) ;
V_65 = F_41 ( V_10 , V_2 , V_54 , V_56 , V_28 ,
V_57 , V_58 , V_17 , V_59 ,
V_60 , V_61 , V_62 ) ;
F_6 ( V_2 -> V_7 ) ;
return V_65 ;
}
void F_44 ( struct V_73 * V_74 ,
const struct V_73 * V_75 )
{
int V_76 ;
T_1 * V_77 , * V_78 ;
if ( ! V_75 ) {
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
return;
}
V_77 = ( T_1 * ) ( V_74 ) ;
V_78 = ( T_1 * ) ( V_75 ) ;
for ( V_76 = 0 ; V_76 < sizeof( * V_74 ) ; V_76 ++ )
V_77 [ V_76 ] &= V_78 [ V_76 ] ;
}
int F_45 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_53 * V_54 ,
const T_1 * V_28 , const T_1 * V_79 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 , bool V_80 ,
struct V_81 * V_82 ,
T_5 V_83 , struct V_73 * V_74 ,
struct V_73 * V_75 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_84 V_64 ;
int V_65 ;
bool V_85 = false ;
F_16 ( V_6 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
if ( V_6 -> V_30 && V_79 &&
F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_79 ) ) {
if ( V_6 -> V_25 == V_32 ) {
V_85 = true ;
V_6 -> V_25 = V_27 ;
}
} else if ( V_6 -> V_30 )
return - V_68 ;
V_64 . V_17 = V_17 ;
V_64 . V_59 = V_59 ;
memcpy ( & V_64 . V_86 , V_82 , sizeof( V_64 . V_86 ) ) ;
V_64 . V_80 = V_80 ;
V_64 . V_79 = V_79 ;
V_64 . V_87 = V_83 ;
if ( V_74 )
memcpy ( & V_64 . V_74 , V_74 , sizeof( V_64 . V_74 ) ) ;
if ( V_75 )
memcpy ( & V_64 . V_75 , V_75 ,
sizeof( V_64 . V_75 ) ) ;
F_44 ( & V_64 . V_75 ,
V_10 -> V_8 . V_88 ) ;
V_64 . V_13 = F_42 ( & V_10 -> V_8 , V_54 , V_28 , V_57 , V_58 ,
V_69 , V_69 ) ;
if ( ! V_64 . V_13 ) {
if ( V_85 )
V_6 -> V_25 = V_32 ;
return - V_70 ;
}
V_65 = V_10 -> V_71 -> V_89 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
if ( V_65 ) {
if ( V_85 )
V_6 -> V_25 = V_32 ;
F_11 ( V_64 . V_13 ) ;
}
return V_65 ;
}
int F_46 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_53 * V_54 ,
const T_1 * V_28 , const T_1 * V_79 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 , bool V_80 ,
struct V_81 * V_82 ,
T_5 V_83 , struct V_73 * V_74 ,
struct V_73 * V_75 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_65 ;
F_3 ( V_6 ) ;
V_65 = F_45 ( V_10 , V_2 , V_54 , V_28 , V_79 ,
V_57 , V_58 , V_17 , V_59 , V_80 , V_82 ,
V_83 , V_74 , V_75 ) ;
F_6 ( V_6 ) ;
return V_65 ;
}
int F_47 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_90 ,
bool V_91 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_92 V_64 = {
. V_28 = V_28 ,
. V_33 = V_90 ,
. V_17 = V_17 ,
. V_59 = V_59 ,
} ;
F_16 ( V_6 ) ;
if ( V_91 ) {
if ( V_6 -> V_30 &&
F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_18 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
return 0 ;
}
return V_10 -> V_71 -> V_35 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
}
int F_48 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_90 ,
bool V_91 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_65 ;
F_3 ( V_6 ) ;
V_65 = F_47 ( V_10 , V_2 , V_28 , V_17 , V_59 , V_90 ,
V_91 ) ;
F_6 ( V_6 ) ;
return V_65 ;
}
static int F_49 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_90 ,
bool V_91 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_93 V_64 ;
F_16 ( V_6 ) ;
if ( V_6 -> V_25 != V_32 )
return - V_94 ;
if ( F_25 ( ! V_6 -> V_30 ) )
return - V_94 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_33 = V_90 ;
V_64 . V_91 = V_91 ;
V_64 . V_17 = V_17 ;
V_64 . V_59 = V_59 ;
if ( F_17 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) )
V_64 . V_13 = & V_6 -> V_30 -> V_31 ;
else
return - V_94 ;
return V_10 -> V_71 -> V_39 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
}
int F_50 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_90 ,
bool V_91 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_65 ;
F_3 ( V_6 ) ;
V_65 = F_49 ( V_10 , V_2 , V_28 , V_17 , V_59 , V_90 ,
V_91 ) ;
F_6 ( V_6 ) ;
return V_65 ;
}
void F_51 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_92 V_64 ;
T_1 V_28 [ V_95 ] ;
F_16 ( V_6 ) ;
if ( ! V_10 -> V_71 -> V_35 )
return;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . V_33 = V_96 ;
V_64 . V_17 = NULL ;
V_64 . V_59 = 0 ;
if ( ! V_6 -> V_30 )
return;
memcpy ( V_28 , V_6 -> V_30 -> V_31 . V_28 , V_95 ) ;
V_64 . V_28 = V_28 ;
V_10 -> V_71 -> V_35 ( & V_10 -> V_8 , V_2 , & V_64 ) ;
if ( V_6 -> V_30 ) {
F_18 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
}
void F_52 ( struct V_1 * V_2 , T_6 V_97 ,
struct V_53 * V_54 ,
enum V_98 V_99 ,
unsigned int V_100 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_53 ( V_10 , V_2 , V_97 , V_54 , V_99 ,
V_100 , V_46 ) ;
}
void F_54 ( struct V_1 * V_2 ,
T_6 V_97 ,
struct V_53 * V_54 ,
enum V_98 V_99 ,
T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_55 ( V_10 , V_2 , V_97 , V_54 ,
V_99 , V_46 ) ;
}
void F_56 ( struct V_1 * V_2 , const T_1 * V_101 ,
struct V_102 * V_103 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_57 ( V_10 , V_2 , V_101 , V_103 , V_46 ) ;
}
void F_58 ( struct V_1 * V_2 , const T_1 * V_101 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_59 ( V_10 , V_2 , V_101 , V_46 ) ;
}
int F_60 ( struct V_5 * V_6 , T_5 V_104 ,
T_3 V_105 , const T_1 * V_106 ,
int V_107 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_108 * V_109 , * V_110 ;
int V_65 = 0 ;
T_3 V_111 ;
if ( ! V_6 -> V_8 -> V_112 )
return - V_113 ;
if ( ( V_105 & V_114 ) != V_115 )
return - V_67 ;
if ( V_105 & ~ ( V_114 | V_116 ) )
return - V_67 ;
V_111 = ( V_105 & V_116 ) >> 4 ;
if ( ! ( V_6 -> V_8 -> V_112 [ V_6 -> V_117 ] . V_118 & F_61 ( V_111 ) ) )
return - V_67 ;
V_110 = F_62 ( sizeof( * V_109 ) + V_107 , V_11 ) ;
if ( ! V_110 )
return - V_119 ;
F_63 ( & V_6 -> V_120 ) ;
F_64 (reg, &wdev->mgmt_registrations, list) {
int V_121 = F_65 ( V_107 , V_109 -> V_107 ) ;
if ( V_105 != F_9 ( V_109 -> V_105 ) )
continue;
if ( memcmp ( V_109 -> V_122 , V_106 , V_121 ) == 0 ) {
V_65 = - V_68 ;
break;
}
}
if ( V_65 ) {
F_39 ( V_110 ) ;
goto V_24;
}
memcpy ( V_110 -> V_122 , V_106 , V_107 ) ;
V_110 -> V_107 = V_107 ;
V_110 -> V_123 = V_104 ;
V_110 -> V_105 = F_66 ( V_105 ) ;
F_67 ( & V_110 -> V_124 , & V_6 -> V_125 ) ;
if ( V_10 -> V_71 -> V_126 )
V_10 -> V_71 -> V_126 ( V_8 , V_6 -> V_127 ,
V_105 , true ) ;
V_24:
F_68 ( & V_6 -> V_120 ) ;
return V_65 ;
}
void F_69 ( struct V_5 * V_6 , T_5 V_123 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_108 * V_109 , * V_128 ;
F_63 ( & V_6 -> V_120 ) ;
F_70 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_109 -> V_123 != V_123 )
continue;
if ( V_10 -> V_71 -> V_126 ) {
T_3 V_105 = F_9 ( V_109 -> V_105 ) ;
V_10 -> V_71 -> V_126 ( V_8 , V_6 -> V_127 ,
V_105 , false ) ;
}
F_71 ( & V_109 -> V_124 ) ;
F_39 ( V_109 ) ;
}
F_68 ( & V_6 -> V_120 ) ;
if ( V_123 == V_6 -> V_129 )
V_6 -> V_129 = 0 ;
}
void F_72 ( struct V_5 * V_6 )
{
struct V_108 * V_109 , * V_128 ;
F_63 ( & V_6 -> V_120 ) ;
F_70 (reg, tmp, &wdev->mgmt_registrations, list) {
F_71 ( & V_109 -> V_124 ) ;
F_39 ( V_109 ) ;
}
F_68 ( & V_6 -> V_120 ) ;
}
int F_73 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_53 * V_54 , bool V_130 ,
enum V_98 V_99 ,
bool V_131 , unsigned int V_132 ,
const T_1 * V_3 , T_2 V_4 , bool V_133 ,
bool V_134 , T_6 * V_97 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const struct V_15 * V_16 ;
T_3 V_135 ;
if ( ! V_6 -> V_8 -> V_112 )
return - V_113 ;
if ( ! V_10 -> V_71 -> V_136 )
return - V_113 ;
if ( V_4 < 24 + 1 )
return - V_67 ;
V_16 = ( const struct V_15 * ) V_3 ;
if ( ! F_74 ( V_16 -> V_137 ) )
return - V_67 ;
V_135 = F_9 ( V_16 -> V_137 ) & V_116 ;
if ( ! ( V_6 -> V_8 -> V_112 [ V_6 -> V_117 ] . V_138 & F_61 ( V_135 >> 4 ) ) )
return - V_67 ;
if ( F_75 ( V_16 -> V_137 ) &&
V_16 -> V_18 . V_139 . V_140 != V_141 ) {
int V_65 = 0 ;
F_3 ( V_6 ) ;
switch ( V_6 -> V_117 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! V_6 -> V_30 ) {
V_65 = - V_94 ;
break;
}
if ( ! F_17 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_28 ) ) {
V_65 = - V_94 ;
break;
}
if ( V_6 -> V_117 == V_142 )
break;
if ( ! F_17 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_145 ) ) {
V_65 = - V_94 ;
break;
}
break;
case V_146 :
case V_147 :
case V_148 :
if ( ! F_17 ( V_16 -> V_28 , V_2 -> V_37 ) )
V_65 = - V_67 ;
break;
case V_149 :
if ( ! F_17 ( V_16 -> V_36 , V_16 -> V_28 ) ) {
V_65 = - V_67 ;
break;
}
break;
default:
V_65 = - V_113 ;
break;
}
F_6 ( V_6 ) ;
if ( V_65 )
return V_65 ;
}
if ( ! F_17 ( V_16 -> V_36 , V_2 -> V_37 ) )
return - V_67 ;
return V_10 -> V_71 -> V_136 ( & V_10 -> V_8 , V_2 , V_54 , V_130 ,
V_99 , V_131 ,
V_132 , V_3 , V_4 , V_133 , V_134 ,
V_97 ) ;
}
bool F_76 ( struct V_1 * V_2 , int V_150 , int V_151 ,
const T_1 * V_3 , T_2 V_4 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_108 * V_109 ;
const struct V_152 * V_153 =
& V_8 -> V_112 [ V_6 -> V_117 ] ;
struct V_15 * V_16 = ( void * ) V_3 ;
const T_1 * V_50 ;
int V_154 ;
bool V_155 = false ;
T_7 V_156 = V_16 -> V_137 &
F_66 ( V_114 | V_116 ) ;
T_3 V_135 ;
V_135 = ( F_9 ( V_16 -> V_137 ) & V_116 ) >> 4 ;
if ( ! ( V_153 -> V_118 & F_61 ( V_135 ) ) )
return false ;
V_50 = V_3 + F_77 ( V_16 -> V_137 ) ;
V_154 = V_4 - F_77 ( V_16 -> V_137 ) ;
F_63 ( & V_6 -> V_120 ) ;
F_64 (reg, &wdev->mgmt_registrations, list) {
if ( V_109 -> V_105 != V_156 )
continue;
if ( V_109 -> V_107 > V_154 )
continue;
if ( memcmp ( V_109 -> V_122 , V_50 , V_109 -> V_107 ) )
continue;
if ( F_78 ( V_10 , V_2 , V_109 -> V_123 ,
V_150 , V_151 ,
V_3 , V_4 , V_46 ) )
continue;
V_155 = true ;
break;
}
F_68 ( & V_6 -> V_120 ) ;
return V_155 ;
}
void F_79 ( struct V_1 * V_2 , T_6 V_97 ,
const T_1 * V_3 , T_2 V_4 , bool V_157 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_80 ( V_10 , V_2 , V_97 , V_3 , V_4 , V_157 , V_46 ) ;
}
void F_81 ( struct V_1 * V_2 ,
enum V_158 V_159 ,
T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_82 ( V_10 , V_2 , V_159 , V_46 ) ;
}
void F_83 ( struct V_1 * V_2 ,
const T_1 * V_160 , T_5 V_161 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_84 ( V_10 , V_2 , V_160 , V_161 , V_46 ) ;
}
void F_85 ( struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_162 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_86 ( V_10 , V_2 , V_28 , V_162 , V_46 ) ;
}
void F_87 ( struct V_1 * V_2 , int V_163 ,
const T_1 * V_28 , bool V_164 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_88 ( V_10 , V_2 , V_163 , V_28 , V_164 , V_46 ) ;
}
void F_89 ( struct V_1 * V_2 , int V_150 ,
enum V_98 type )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_53 * V_54 ;
F_3 ( V_6 ) ;
if ( F_25 ( V_6 -> V_117 != V_146 &&
V_6 -> V_117 != V_147 ) )
goto V_24;
V_54 = F_90 ( V_10 , V_150 , type ) ;
if ( F_25 ( ! V_54 ) )
goto V_24;
V_6 -> V_165 = V_54 ;
F_91 ( V_10 , V_2 , V_150 , type , V_11 ) ;
V_24:
F_6 ( V_6 ) ;
return;
}
bool F_92 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_25 ( V_6 -> V_117 != V_146 &&
V_6 -> V_117 != V_147 ) )
return false ;
return F_93 ( V_2 , V_41 , V_46 ) ;
}
bool F_94 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_25 ( V_6 -> V_117 != V_146 &&
V_6 -> V_117 != V_147 &&
V_6 -> V_117 != V_148 ) )
return false ;
return F_95 ( V_2 , V_41 , V_46 ) ;
}
