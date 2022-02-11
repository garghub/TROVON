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
memcmp ( V_6 -> V_30 -> V_31 . V_28 , V_28 , V_32 ) == 0 ) {
F_17 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
V_29 = true ;
}
F_18 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 == V_33 && V_29 ) {
T_3 V_34 ;
bool V_35 ;
V_34 = F_9 ( V_16 -> V_18 . V_36 . V_34 ) ;
V_35 = memcmp ( V_16 -> V_37 , V_2 -> V_38 , V_32 ) != 0 ;
F_19 ( V_2 , NULL , 0 , V_34 , V_35 ) ;
} else if ( V_6 -> V_25 == V_27 ) {
F_14 ( V_2 , V_16 -> V_28 , NULL , 0 , NULL , 0 ,
V_39 ,
false , NULL ) ;
}
}
void F_20 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_6 ) ;
F_15 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_6 ) ;
}
void F_21 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
const T_1 * V_28 = V_16 -> V_28 ;
T_3 V_34 ;
bool V_35 ;
F_16 ( V_6 ) ;
F_22 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 != V_33 )
return;
if ( V_6 -> V_30 &&
memcmp ( V_6 -> V_30 -> V_31 . V_28 , V_28 , V_32 ) == 0 ) {
F_23 ( V_2 , V_6 -> V_30 ) ;
F_17 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
} else
F_24 ( 1 ) ;
V_34 = F_9 ( V_16 -> V_18 . V_40 . V_34 ) ;
V_35 = memcmp ( V_16 -> V_37 , V_2 -> V_38 , V_32 ) != 0 ;
F_19 ( V_2 , NULL , 0 , V_34 , V_35 ) ;
}
void F_25 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_6 ) ;
F_21 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_6 ) ;
}
void F_26 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_27 ( V_10 , V_2 , V_3 , V_4 , V_41 ) ;
}
void F_28 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_29 ( V_10 , V_2 , V_3 , V_4 , V_41 ) ;
}
void F_30 ( struct V_1 * V_2 , const T_1 * V_42 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_3 ( V_6 ) ;
F_31 ( V_10 , V_2 , V_42 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_14 ( V_2 , V_42 , NULL , 0 , NULL , 0 ,
V_39 ,
false , NULL ) ;
F_6 ( V_6 ) ;
}
void F_32 ( struct V_1 * V_2 , const T_1 * V_42 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_3 ( V_6 ) ;
F_33 ( V_10 , V_2 , V_42 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_14 ( V_2 , V_42 , NULL , 0 , NULL , 0 ,
V_39 ,
false , NULL ) ;
F_6 ( V_6 ) ;
}
void F_34 ( struct V_1 * V_2 , const T_1 * V_42 ,
enum V_43 V_44 , int V_45 ,
const T_1 * V_46 , T_4 V_47 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
#ifdef F_35
union V_48 V_49 ;
char * V_3 = F_36 ( 128 , V_47 ) ;
if ( V_3 ) {
sprintf ( V_3 , L_1
L_2 , V_45 ,
V_44 == V_50 ? L_3 : L_4 ,
V_42 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_51 . V_52 = strlen ( V_3 ) ;
F_37 ( V_2 , V_53 , & V_49 , V_3 ) ;
F_38 ( V_3 ) ;
}
#endif
F_39 ( V_10 , V_2 , V_42 , V_44 , V_45 , V_46 , V_47 ) ;
}
int F_40 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_54 * V_55 ,
enum V_56 V_57 ,
const T_1 * V_28 ,
const T_1 * V_58 , int V_59 ,
const T_1 * V_17 , int V_60 ,
const T_1 * V_61 , int V_62 , int V_63 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_64 V_65 ;
int V_66 ;
F_16 ( V_6 ) ;
if ( V_57 == V_67 )
if ( ! V_61 || ! V_62 || V_63 < 0 || V_63 > 4 )
return - V_68 ;
if ( V_6 -> V_30 &&
memcmp ( V_28 , V_6 -> V_30 -> V_31 . V_28 , V_32 ) == 0 )
return - V_69 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_17 = V_17 ;
V_65 . V_60 = V_60 ;
V_65 . V_57 = V_57 ;
V_65 . V_13 = F_41 ( & V_10 -> V_8 , V_55 , V_28 , V_58 , V_59 ,
V_70 , V_70 ) ;
V_65 . V_61 = V_61 ;
V_65 . V_62 = V_62 ;
V_65 . V_63 = V_63 ;
if ( ! V_65 . V_13 )
return - V_71 ;
V_66 = V_10 -> V_72 -> V_73 ( & V_10 -> V_8 , V_2 , & V_65 ) ;
F_11 ( V_65 . V_13 ) ;
return V_66 ;
}
int F_42 ( struct V_9 * V_10 ,
struct V_1 * V_2 , struct V_54 * V_55 ,
enum V_56 V_57 , const T_1 * V_28 ,
const T_1 * V_58 , int V_59 ,
const T_1 * V_17 , int V_60 ,
const T_1 * V_61 , int V_62 , int V_63 )
{
int V_66 ;
F_3 ( V_2 -> V_7 ) ;
V_66 = F_40 ( V_10 , V_2 , V_55 , V_57 , V_28 ,
V_58 , V_59 , V_17 , V_60 ,
V_61 , V_62 , V_63 ) ;
F_6 ( V_2 -> V_7 ) ;
return V_66 ;
}
void F_43 ( struct V_74 * V_75 ,
const struct V_74 * V_76 )
{
int V_77 ;
T_1 * V_78 , * V_79 ;
if ( ! V_76 ) {
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
return;
}
V_78 = ( T_1 * ) ( V_75 ) ;
V_79 = ( T_1 * ) ( V_76 ) ;
for ( V_77 = 0 ; V_77 < sizeof( * V_75 ) ; V_77 ++ )
V_78 [ V_77 ] &= V_79 [ V_77 ] ;
}
int F_44 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_54 * V_55 ,
const T_1 * V_28 , const T_1 * V_80 ,
const T_1 * V_58 , int V_59 ,
const T_1 * V_17 , int V_60 , bool V_81 ,
struct V_82 * V_83 ,
T_5 V_84 , struct V_74 * V_75 ,
struct V_74 * V_76 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_85 V_65 ;
int V_66 ;
bool V_86 = false ;
F_16 ( V_6 ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
if ( V_6 -> V_30 && V_80 &&
memcmp ( V_6 -> V_30 -> V_31 . V_28 , V_80 , V_32 ) == 0 ) {
if ( V_6 -> V_25 == V_33 ) {
V_86 = true ;
V_6 -> V_25 = V_27 ;
}
} else if ( V_6 -> V_30 )
return - V_69 ;
V_65 . V_17 = V_17 ;
V_65 . V_60 = V_60 ;
memcpy ( & V_65 . V_87 , V_83 , sizeof( V_65 . V_87 ) ) ;
V_65 . V_81 = V_81 ;
V_65 . V_80 = V_80 ;
V_65 . V_88 = V_84 ;
if ( V_75 )
memcpy ( & V_65 . V_75 , V_75 , sizeof( V_65 . V_75 ) ) ;
if ( V_76 )
memcpy ( & V_65 . V_76 , V_76 ,
sizeof( V_65 . V_76 ) ) ;
F_43 ( & V_65 . V_76 ,
V_10 -> V_8 . V_89 ) ;
V_65 . V_13 = F_41 ( & V_10 -> V_8 , V_55 , V_28 , V_58 , V_59 ,
V_70 , V_70 ) ;
if ( ! V_65 . V_13 ) {
if ( V_86 )
V_6 -> V_25 = V_33 ;
return - V_71 ;
}
V_66 = V_10 -> V_72 -> V_90 ( & V_10 -> V_8 , V_2 , & V_65 ) ;
if ( V_66 ) {
if ( V_86 )
V_6 -> V_25 = V_33 ;
F_11 ( V_65 . V_13 ) ;
}
return V_66 ;
}
int F_45 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_54 * V_55 ,
const T_1 * V_28 , const T_1 * V_80 ,
const T_1 * V_58 , int V_59 ,
const T_1 * V_17 , int V_60 , bool V_81 ,
struct V_82 * V_83 ,
T_5 V_84 , struct V_74 * V_75 ,
struct V_74 * V_76 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_66 ;
F_3 ( V_6 ) ;
V_66 = F_44 ( V_10 , V_2 , V_55 , V_28 , V_80 ,
V_58 , V_59 , V_17 , V_60 , V_81 , V_83 ,
V_84 , V_75 , V_76 ) ;
F_6 ( V_6 ) ;
return V_66 ;
}
int F_46 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_60 , T_3 V_91 ,
bool V_92 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_93 V_65 = {
. V_28 = V_28 ,
. V_34 = V_91 ,
. V_17 = V_17 ,
. V_60 = V_60 ,
} ;
F_16 ( V_6 ) ;
if ( V_92 ) {
if ( V_6 -> V_30 &&
memcmp ( V_6 -> V_30 -> V_31 . V_28 , V_28 , V_32 ) == 0 ) {
F_17 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
return 0 ;
}
return V_10 -> V_72 -> V_36 ( & V_10 -> V_8 , V_2 , & V_65 ) ;
}
int F_47 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_60 , T_3 V_91 ,
bool V_92 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_66 ;
F_3 ( V_6 ) ;
V_66 = F_46 ( V_10 , V_2 , V_28 , V_17 , V_60 , V_91 ,
V_92 ) ;
F_6 ( V_6 ) ;
return V_66 ;
}
static int F_48 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_60 , T_3 V_91 ,
bool V_92 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_94 V_65 ;
F_16 ( V_6 ) ;
if ( V_6 -> V_25 != V_33 )
return - V_95 ;
if ( F_24 ( ! V_6 -> V_30 ) )
return - V_95 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_34 = V_91 ;
V_65 . V_92 = V_92 ;
V_65 . V_17 = V_17 ;
V_65 . V_60 = V_60 ;
if ( memcmp ( V_6 -> V_30 -> V_31 . V_28 , V_28 , V_32 ) == 0 )
V_65 . V_13 = & V_6 -> V_30 -> V_31 ;
else
return - V_95 ;
return V_10 -> V_72 -> V_40 ( & V_10 -> V_8 , V_2 , & V_65 ) ;
}
int F_49 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_60 , T_3 V_91 ,
bool V_92 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_66 ;
F_3 ( V_6 ) ;
V_66 = F_48 ( V_10 , V_2 , V_28 , V_17 , V_60 , V_91 ,
V_92 ) ;
F_6 ( V_6 ) ;
return V_66 ;
}
void F_50 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_93 V_65 ;
T_1 V_28 [ V_32 ] ;
F_16 ( V_6 ) ;
if ( ! V_10 -> V_72 -> V_36 )
return;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_34 = V_96 ;
V_65 . V_17 = NULL ;
V_65 . V_60 = 0 ;
if ( ! V_6 -> V_30 )
return;
memcpy ( V_28 , V_6 -> V_30 -> V_31 . V_28 , V_32 ) ;
V_65 . V_28 = V_28 ;
V_10 -> V_72 -> V_36 ( & V_10 -> V_8 , V_2 , & V_65 ) ;
if ( V_6 -> V_30 ) {
F_17 ( V_6 -> V_30 ) ;
F_11 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
}
void F_51 ( struct V_1 * V_2 , T_6 V_97 ,
struct V_54 * V_55 ,
enum V_98 V_99 ,
unsigned int V_100 , T_4 V_47 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_52 ( V_10 , V_2 , V_97 , V_55 , V_99 ,
V_100 , V_47 ) ;
}
void F_53 ( struct V_1 * V_2 ,
T_6 V_97 ,
struct V_54 * V_55 ,
enum V_98 V_99 ,
T_4 V_47 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_54 ( V_10 , V_2 , V_97 , V_55 ,
V_99 , V_47 ) ;
}
void F_55 ( struct V_1 * V_2 , const T_1 * V_101 ,
struct V_102 * V_103 , T_4 V_47 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_56 ( V_10 , V_2 , V_101 , V_103 , V_47 ) ;
}
void F_57 ( struct V_1 * V_2 , const T_1 * V_101 , T_4 V_47 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_58 ( V_10 , V_2 , V_101 , V_47 ) ;
}
int F_59 ( struct V_5 * V_6 , T_5 V_104 ,
T_3 V_105 , const T_1 * V_106 ,
int V_107 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_108 * V_109 , * V_110 ;
int V_66 = 0 ;
T_3 V_111 ;
if ( ! V_6 -> V_8 -> V_112 )
return - V_113 ;
if ( ( V_105 & V_114 ) != V_115 )
return - V_68 ;
if ( V_105 & ~ ( V_114 | V_116 ) )
return - V_68 ;
V_111 = ( V_105 & V_116 ) >> 4 ;
if ( ! ( V_6 -> V_8 -> V_112 [ V_6 -> V_117 ] . V_118 & F_60 ( V_111 ) ) )
return - V_68 ;
V_110 = F_61 ( sizeof( * V_109 ) + V_107 , V_11 ) ;
if ( ! V_110 )
return - V_119 ;
F_62 ( & V_6 -> V_120 ) ;
F_63 (reg, &wdev->mgmt_registrations, list) {
int V_121 = F_64 ( V_107 , V_109 -> V_107 ) ;
if ( V_105 != F_9 ( V_109 -> V_105 ) )
continue;
if ( memcmp ( V_109 -> V_122 , V_106 , V_121 ) == 0 ) {
V_66 = - V_69 ;
break;
}
}
if ( V_66 ) {
F_38 ( V_110 ) ;
goto V_24;
}
memcpy ( V_110 -> V_122 , V_106 , V_107 ) ;
V_110 -> V_107 = V_107 ;
V_110 -> V_123 = V_104 ;
V_110 -> V_105 = F_65 ( V_105 ) ;
F_66 ( & V_110 -> V_124 , & V_6 -> V_125 ) ;
if ( V_10 -> V_72 -> V_126 )
V_10 -> V_72 -> V_126 ( V_8 , V_6 -> V_127 ,
V_105 , true ) ;
V_24:
F_67 ( & V_6 -> V_120 ) ;
return V_66 ;
}
void F_68 ( struct V_5 * V_6 , T_5 V_123 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_108 * V_109 , * V_128 ;
F_62 ( & V_6 -> V_120 ) ;
F_69 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_109 -> V_123 != V_123 )
continue;
if ( V_10 -> V_72 -> V_126 ) {
T_3 V_105 = F_9 ( V_109 -> V_105 ) ;
V_10 -> V_72 -> V_126 ( V_8 , V_6 -> V_127 ,
V_105 , false ) ;
}
F_70 ( & V_109 -> V_124 ) ;
F_38 ( V_109 ) ;
}
F_67 ( & V_6 -> V_120 ) ;
if ( V_123 == V_6 -> V_129 )
V_6 -> V_129 = 0 ;
}
void F_71 ( struct V_5 * V_6 )
{
struct V_108 * V_109 , * V_128 ;
F_62 ( & V_6 -> V_120 ) ;
F_69 (reg, tmp, &wdev->mgmt_registrations, list) {
F_70 ( & V_109 -> V_124 ) ;
F_38 ( V_109 ) ;
}
F_67 ( & V_6 -> V_120 ) ;
}
int F_72 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_54 * V_55 , bool V_130 ,
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
if ( ! V_10 -> V_72 -> V_136 )
return - V_113 ;
if ( V_4 < 24 + 1 )
return - V_68 ;
V_16 = ( const struct V_15 * ) V_3 ;
if ( ! F_73 ( V_16 -> V_137 ) )
return - V_68 ;
V_135 = F_9 ( V_16 -> V_137 ) & V_116 ;
if ( ! ( V_6 -> V_8 -> V_112 [ V_6 -> V_117 ] . V_138 & F_60 ( V_135 >> 4 ) ) )
return - V_68 ;
if ( F_74 ( V_16 -> V_137 ) &&
V_16 -> V_18 . V_139 . V_140 != V_141 ) {
int V_66 = 0 ;
F_3 ( V_6 ) ;
switch ( V_6 -> V_117 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! V_6 -> V_30 ) {
V_66 = - V_95 ;
break;
}
if ( memcmp ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_28 , V_32 ) ) {
V_66 = - V_95 ;
break;
}
if ( V_6 -> V_117 == V_142 )
break;
if ( memcmp ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_145 , V_32 ) ) {
V_66 = - V_95 ;
break;
}
break;
case V_146 :
case V_147 :
case V_148 :
if ( memcmp ( V_16 -> V_28 , V_2 -> V_38 , V_32 ) )
V_66 = - V_68 ;
break;
case V_149 :
if ( memcmp ( V_16 -> V_37 , V_16 -> V_28 , V_32 ) ) {
V_66 = - V_68 ;
break;
}
break;
default:
V_66 = - V_113 ;
break;
}
F_6 ( V_6 ) ;
if ( V_66 )
return V_66 ;
}
if ( memcmp ( V_16 -> V_37 , V_2 -> V_38 , V_32 ) != 0 )
return - V_68 ;
return V_10 -> V_72 -> V_136 ( & V_10 -> V_8 , V_2 , V_55 , V_130 ,
V_99 , V_131 ,
V_132 , V_3 , V_4 , V_133 , V_134 ,
V_97 ) ;
}
bool F_75 ( struct V_1 * V_2 , int V_150 , int V_151 ,
const T_1 * V_3 , T_2 V_4 , T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_108 * V_109 ;
const struct V_152 * V_153 =
& V_8 -> V_112 [ V_6 -> V_117 ] ;
struct V_15 * V_16 = ( void * ) V_3 ;
const T_1 * V_51 ;
int V_154 ;
bool V_155 = false ;
T_7 V_156 = V_16 -> V_137 &
F_65 ( V_114 | V_116 ) ;
T_3 V_135 ;
V_135 = ( F_9 ( V_16 -> V_137 ) & V_116 ) >> 4 ;
if ( ! ( V_153 -> V_118 & F_60 ( V_135 ) ) )
return false ;
V_51 = V_3 + F_76 ( V_16 -> V_137 ) ;
V_154 = V_4 - F_76 ( V_16 -> V_137 ) ;
F_62 ( & V_6 -> V_120 ) ;
F_63 (reg, &wdev->mgmt_registrations, list) {
if ( V_109 -> V_105 != V_156 )
continue;
if ( V_109 -> V_107 > V_154 )
continue;
if ( memcmp ( V_109 -> V_122 , V_51 , V_109 -> V_107 ) )
continue;
if ( F_77 ( V_10 , V_2 , V_109 -> V_123 ,
V_150 , V_151 ,
V_3 , V_4 , V_47 ) )
continue;
V_155 = true ;
break;
}
F_67 ( & V_6 -> V_120 ) ;
return V_155 ;
}
void F_78 ( struct V_1 * V_2 , T_6 V_97 ,
const T_1 * V_3 , T_2 V_4 , bool V_157 , T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_79 ( V_10 , V_2 , V_97 , V_3 , V_4 , V_157 , V_47 ) ;
}
void F_80 ( struct V_1 * V_2 ,
enum V_158 V_159 ,
T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_81 ( V_10 , V_2 , V_159 , V_47 ) ;
}
void F_82 ( struct V_1 * V_2 ,
const T_1 * V_160 , T_5 V_161 , T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_83 ( V_10 , V_2 , V_160 , V_161 , V_47 ) ;
}
void F_84 ( struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_162 , T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_85 ( V_10 , V_2 , V_28 , V_162 , V_47 ) ;
}
void F_86 ( struct V_1 * V_2 , int V_163 ,
const T_1 * V_28 , bool V_164 , T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_87 ( V_10 , V_2 , V_163 , V_28 , V_164 , V_47 ) ;
}
bool F_88 ( struct V_1 * V_2 ,
const T_1 * V_42 , T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_24 ( V_6 -> V_117 != V_146 &&
V_6 -> V_117 != V_147 ) )
return false ;
return F_89 ( V_2 , V_42 , V_47 ) ;
}
bool F_90 ( struct V_1 * V_2 ,
const T_1 * V_42 , T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_24 ( V_6 -> V_117 != V_146 &&
V_6 -> V_117 != V_147 &&
V_6 -> V_117 != V_148 ) )
return false ;
return F_91 ( V_2 , V_42 , V_47 ) ;
}
