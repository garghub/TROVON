void F_1 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_3 ( V_2 ) ;
F_4 ( V_6 ) ;
F_5 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
F_6 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_6 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const T_1 * V_3 , T_2 V_4 )
{
T_3 V_14 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
T_1 * V_17 = V_16 -> V_18 . V_19 . V_20 ;
int V_21 = F_9 ( struct V_15 , V_18 . V_19 . V_20 ) ;
F_10 ( V_2 , V_13 ) ;
F_4 ( V_6 ) ;
V_14 = F_11 ( V_16 -> V_18 . V_19 . V_14 ) ;
if ( V_14 != V_22 && V_6 -> V_23 &&
F_12 ( V_6 ) ) {
F_13 ( V_13 ) ;
goto V_24;
}
F_14 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_14 != V_22 && V_6 -> V_23 ) {
F_15 ( V_6 ) ;
F_13 ( V_13 ) ;
goto V_24;
}
if ( ! V_6 -> V_23 && V_6 -> V_25 == V_26 ) {
V_6 -> V_25 = V_27 ;
}
F_16 ( V_2 , V_16 -> V_28 , NULL , 0 , V_17 , V_4 - V_21 ,
V_14 ,
V_14 == V_22 , V_13 ) ;
V_24:
F_7 ( V_6 ) ;
}
void F_17 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
const T_1 * V_28 = V_16 -> V_28 ;
bool V_29 = false ;
F_18 ( V_2 ) ;
F_19 ( V_6 ) ;
if ( V_6 -> V_30 &&
F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_21 ( V_6 -> V_30 ) ;
F_13 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
V_29 = true ;
}
F_22 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 == V_32 && V_29 ) {
T_3 V_33 ;
bool V_34 ;
V_33 = F_11 ( V_16 -> V_18 . V_35 . V_33 ) ;
V_34 = ! F_20 ( V_16 -> V_36 , V_2 -> V_37 ) ;
F_23 ( V_2 , NULL , 0 , V_33 , V_34 ) ;
} else if ( V_6 -> V_25 == V_27 ) {
F_16 ( V_2 , V_16 -> V_28 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
}
}
void F_24 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 ) ;
F_17 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_6 ) ;
}
void F_25 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_15 * V_16 = (struct V_15 * ) V_3 ;
const T_1 * V_28 = V_16 -> V_28 ;
T_3 V_33 ;
bool V_34 ;
F_26 ( V_2 ) ;
F_19 ( V_6 ) ;
F_27 ( V_10 , V_2 , V_3 , V_4 , V_11 ) ;
if ( V_6 -> V_25 != V_32 )
return;
if ( V_6 -> V_30 &&
F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) {
F_28 ( V_2 , V_6 -> V_30 ) ;
F_21 ( V_6 -> V_30 ) ;
F_13 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
} else
F_29 ( 1 ) ;
V_33 = F_11 ( V_16 -> V_18 . V_39 . V_33 ) ;
V_34 = ! F_20 ( V_16 -> V_36 , V_2 -> V_37 ) ;
F_23 ( V_2 , NULL , 0 , V_33 , V_34 ) ;
}
void F_30 ( struct V_1 * V_2 , const T_1 * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 ) ;
F_25 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_6 ) ;
}
void F_31 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_32 ( V_2 ) ;
F_33 ( V_10 , V_2 , V_3 , V_4 , V_40 ) ;
}
void F_34 ( struct V_1 * V_2 , const T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_35 ( V_2 ) ;
F_36 ( V_10 , V_2 , V_3 , V_4 , V_40 ) ;
}
void F_37 ( struct V_1 * V_2 , const T_1 * V_41 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_38 ( V_2 , V_41 ) ;
F_4 ( V_6 ) ;
F_39 ( V_10 , V_2 , V_41 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_16 ( V_2 , V_41 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
F_7 ( V_6 ) ;
}
void F_40 ( struct V_1 * V_2 , const T_1 * V_41 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_41 ( V_2 , V_41 ) ;
F_4 ( V_6 ) ;
F_42 ( V_10 , V_2 , V_41 , V_11 ) ;
if ( V_6 -> V_25 == V_27 )
F_16 ( V_2 , V_41 , NULL , 0 , NULL , 0 ,
V_38 ,
false , NULL ) ;
F_7 ( V_6 ) ;
}
void F_43 ( struct V_1 * V_2 , const T_1 * V_41 ,
enum V_42 V_43 , int V_44 ,
const T_1 * V_45 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
#ifdef F_44
union V_47 V_48 ;
char * V_3 = F_45 ( 128 , V_46 ) ;
if ( V_3 ) {
sprintf ( V_3 , L_1
L_2 , V_44 ,
V_43 == V_49 ? L_3 : L_4 ,
V_41 ) ;
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
V_48 . V_50 . V_51 = strlen ( V_3 ) ;
F_46 ( V_2 , V_52 , & V_48 , V_3 ) ;
F_47 ( V_3 ) ;
}
#endif
F_48 ( V_2 , V_41 , V_43 , V_44 , V_45 ) ;
F_49 ( V_10 , V_2 , V_41 , V_43 , V_44 , V_45 , V_46 ) ;
}
int F_50 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_53 * V_54 ,
enum V_55 V_56 ,
const T_1 * V_28 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 ,
const T_1 * V_60 , int V_61 , int V_62 ,
const T_1 * V_63 , int V_64 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_65 V_66 ;
int V_67 ;
F_19 ( V_6 ) ;
if ( V_56 == V_68 )
if ( ! V_60 || ! V_61 || V_62 < 0 || V_62 > 4 )
return - V_69 ;
if ( V_6 -> V_30 &&
F_20 ( V_28 , V_6 -> V_30 -> V_31 . V_28 ) )
return - V_70 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_17 = V_17 ;
V_66 . V_59 = V_59 ;
V_66 . V_63 = V_63 ;
V_66 . V_64 = V_64 ;
V_66 . V_56 = V_56 ;
V_66 . V_13 = F_51 ( & V_10 -> V_8 , V_54 , V_28 , V_57 , V_58 ,
V_71 , V_71 ) ;
V_66 . V_60 = V_60 ;
V_66 . V_61 = V_61 ;
V_66 . V_62 = V_62 ;
if ( ! V_66 . V_13 )
return - V_72 ;
V_67 = F_52 ( V_10 , V_6 , V_66 . V_13 -> V_73 ,
V_74 ) ;
if ( V_67 )
goto V_24;
V_67 = F_53 ( V_10 , V_2 , & V_66 ) ;
V_24:
F_13 ( V_66 . V_13 ) ;
return V_67 ;
}
int F_54 ( struct V_9 * V_10 ,
struct V_1 * V_2 , struct V_53 * V_54 ,
enum V_55 V_56 , const T_1 * V_28 ,
const T_1 * V_57 , int V_58 ,
const T_1 * V_17 , int V_59 ,
const T_1 * V_60 , int V_61 , int V_62 ,
const T_1 * V_63 , int V_64 )
{
int V_67 ;
F_55 ( & V_10 -> V_75 ) ;
F_4 ( V_2 -> V_7 ) ;
V_67 = F_50 ( V_10 , V_2 , V_54 , V_56 , V_28 ,
V_57 , V_58 , V_17 , V_59 ,
V_60 , V_61 , V_62 ,
V_63 , V_64 ) ;
F_7 ( V_2 -> V_7 ) ;
F_56 ( & V_10 -> V_75 ) ;
return V_67 ;
}
void F_57 ( struct V_76 * V_77 ,
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
int F_58 ( struct V_9 * V_10 ,
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
struct V_87 V_66 ;
int V_67 ;
bool V_88 = false ;
F_19 ( V_6 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
if ( V_6 -> V_30 && V_82 &&
F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_82 ) ) {
if ( V_6 -> V_25 == V_32 ) {
V_88 = true ;
V_6 -> V_25 = V_27 ;
}
} else if ( V_6 -> V_30 )
return - V_70 ;
V_66 . V_17 = V_17 ;
V_66 . V_59 = V_59 ;
memcpy ( & V_66 . V_89 , V_85 , sizeof( V_66 . V_89 ) ) ;
V_66 . V_83 = V_83 ;
V_66 . V_82 = V_82 ;
V_66 . V_90 = V_86 ;
if ( V_77 )
memcpy ( & V_66 . V_77 , V_77 , sizeof( V_66 . V_77 ) ) ;
if ( V_78 )
memcpy ( & V_66 . V_78 , V_78 ,
sizeof( V_66 . V_78 ) ) ;
F_57 ( & V_66 . V_78 ,
V_10 -> V_8 . V_91 ) ;
V_66 . V_13 = F_51 ( & V_10 -> V_8 , V_54 , V_28 , V_57 , V_58 ,
V_71 , V_71 ) ;
if ( ! V_66 . V_13 ) {
if ( V_88 )
V_6 -> V_25 = V_32 ;
return - V_72 ;
}
V_67 = F_52 ( V_10 , V_6 , V_66 . V_13 -> V_73 ,
V_74 ) ;
if ( V_67 )
goto V_24;
V_67 = F_59 ( V_10 , V_2 , & V_66 ) ;
V_24:
if ( V_67 ) {
if ( V_88 )
V_6 -> V_25 = V_32 ;
F_13 ( V_66 . V_13 ) ;
}
return V_67 ;
}
int F_60 ( struct V_9 * V_10 ,
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
int V_67 ;
F_55 ( & V_10 -> V_75 ) ;
F_4 ( V_6 ) ;
V_67 = F_58 ( V_10 , V_2 , V_54 , V_28 , V_82 ,
V_57 , V_58 , V_17 , V_59 , V_83 , V_85 ,
V_86 , V_77 , V_78 ) ;
F_7 ( V_6 ) ;
F_56 ( & V_10 -> V_75 ) ;
return V_67 ;
}
int F_61 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_92 ,
bool V_93 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_94 V_66 = {
. V_28 = V_28 ,
. V_33 = V_92 ,
. V_17 = V_17 ,
. V_59 = V_59 ,
. V_93 = V_93 ,
} ;
F_19 ( V_6 ) ;
if ( V_93 && ( ! V_6 -> V_30 ||
! F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) ) )
return 0 ;
return F_62 ( V_10 , V_2 , & V_66 ) ;
}
int F_63 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_92 ,
bool V_93 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_67 ;
F_4 ( V_6 ) ;
V_67 = F_61 ( V_10 , V_2 , V_28 , V_17 , V_59 , V_92 ,
V_93 ) ;
F_7 ( V_6 ) ;
return V_67 ;
}
static int F_64 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_92 ,
bool V_93 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_95 V_66 ;
F_19 ( V_6 ) ;
if ( V_6 -> V_25 != V_32 )
return - V_96 ;
if ( F_29 ( ! V_6 -> V_30 ) )
return - V_96 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_33 = V_92 ;
V_66 . V_93 = V_93 ;
V_66 . V_17 = V_17 ;
V_66 . V_59 = V_59 ;
if ( F_20 ( V_6 -> V_30 -> V_31 . V_28 , V_28 ) )
V_66 . V_13 = & V_6 -> V_30 -> V_31 ;
else
return - V_96 ;
return F_65 ( V_10 , V_2 , & V_66 ) ;
}
int F_66 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_17 , int V_59 , T_3 V_92 ,
bool V_93 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_67 ;
F_4 ( V_6 ) ;
V_67 = F_64 ( V_10 , V_2 , V_28 , V_17 , V_59 , V_92 ,
V_93 ) ;
F_7 ( V_6 ) ;
return V_67 ;
}
void F_67 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_94 V_66 ;
T_1 V_28 [ V_97 ] ;
F_19 ( V_6 ) ;
if ( ! V_10 -> V_98 -> V_35 )
return;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_33 = V_99 ;
V_66 . V_17 = NULL ;
V_66 . V_59 = 0 ;
if ( ! V_6 -> V_30 )
return;
memcpy ( V_28 , V_6 -> V_30 -> V_31 . V_28 , V_97 ) ;
V_66 . V_28 = V_28 ;
F_62 ( V_10 , V_2 , & V_66 ) ;
if ( V_6 -> V_30 ) {
F_21 ( V_6 -> V_30 ) ;
F_13 ( & V_6 -> V_30 -> V_31 ) ;
V_6 -> V_30 = NULL ;
}
}
void F_68 ( struct V_5 * V_6 , T_6 V_100 ,
struct V_53 * V_54 ,
unsigned int V_101 , T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_69 ( V_6 , V_100 , V_54 , V_101 ) ;
F_70 ( V_10 , V_6 , V_100 , V_54 , V_101 , V_46 ) ;
}
void F_71 ( struct V_5 * V_6 , T_6 V_100 ,
struct V_53 * V_54 ,
T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_72 ( V_6 , V_100 , V_54 ) ;
F_73 ( V_10 , V_6 , V_100 , V_54 , V_46 ) ;
}
void F_74 ( struct V_1 * V_2 , const T_1 * V_102 ,
struct V_103 * V_104 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_75 ( V_2 , V_102 , V_104 ) ;
F_76 ( V_10 , V_2 , V_102 , V_104 , V_46 ) ;
}
void F_77 ( struct V_1 * V_2 , const T_1 * V_102 , T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_78 ( V_2 , V_102 ) ;
F_79 ( V_10 , V_2 , V_102 , V_46 ) ;
}
void F_80 ( struct V_1 * V_2 , const T_1 * V_102 ,
enum V_105 V_92 ,
T_4 V_46 )
{
struct V_8 * V_8 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_81 ( V_10 , V_2 , V_102 , V_92 , V_46 ) ;
}
int F_82 ( struct V_5 * V_6 , T_5 V_106 ,
T_3 V_107 , const T_1 * V_108 ,
int V_109 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_110 * V_111 , * V_112 ;
int V_67 = 0 ;
T_3 V_113 ;
if ( ! V_6 -> V_8 -> V_114 )
return - V_115 ;
if ( ( V_107 & V_116 ) != V_117 )
return - V_69 ;
if ( V_107 & ~ ( V_116 | V_118 ) )
return - V_69 ;
V_113 = ( V_107 & V_118 ) >> 4 ;
if ( ! ( V_6 -> V_8 -> V_114 [ V_6 -> V_119 ] . V_120 & F_83 ( V_113 ) ) )
return - V_69 ;
V_112 = F_84 ( sizeof( * V_111 ) + V_109 , V_11 ) ;
if ( ! V_112 )
return - V_121 ;
F_85 ( & V_6 -> V_122 ) ;
F_86 (reg, &wdev->mgmt_registrations, list) {
int V_123 = F_87 ( V_109 , V_111 -> V_109 ) ;
if ( V_107 != F_11 ( V_111 -> V_107 ) )
continue;
if ( memcmp ( V_111 -> V_124 , V_108 , V_123 ) == 0 ) {
V_67 = - V_70 ;
break;
}
}
if ( V_67 ) {
F_47 ( V_112 ) ;
goto V_24;
}
memcpy ( V_112 -> V_124 , V_108 , V_109 ) ;
V_112 -> V_109 = V_109 ;
V_112 -> V_125 = V_106 ;
V_112 -> V_107 = F_88 ( V_107 ) ;
F_89 ( & V_112 -> V_126 , & V_6 -> V_127 ) ;
if ( V_10 -> V_98 -> V_128 )
F_90 ( V_10 , V_6 , V_107 , true ) ;
V_24:
F_91 ( & V_6 -> V_122 ) ;
return V_67 ;
}
void F_92 ( struct V_5 * V_6 , T_5 V_125 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_110 * V_111 , * V_129 ;
F_85 ( & V_6 -> V_122 ) ;
F_93 (reg, tmp, &wdev->mgmt_registrations, list) {
if ( V_111 -> V_125 != V_125 )
continue;
if ( V_10 -> V_98 -> V_128 ) {
T_3 V_107 = F_11 ( V_111 -> V_107 ) ;
F_90 ( V_10 , V_6 ,
V_107 , false ) ;
}
F_94 ( & V_111 -> V_126 ) ;
F_47 ( V_111 ) ;
}
F_91 ( & V_6 -> V_122 ) ;
if ( V_125 == V_6 -> V_130 )
V_6 -> V_130 = 0 ;
}
void F_95 ( struct V_5 * V_6 )
{
struct V_110 * V_111 , * V_129 ;
F_85 ( & V_6 -> V_122 ) ;
F_93 (reg, tmp, &wdev->mgmt_registrations, list) {
F_94 ( & V_111 -> V_126 ) ;
F_47 ( V_111 ) ;
}
F_91 ( & V_6 -> V_122 ) ;
}
int F_96 ( struct V_9 * V_10 ,
struct V_5 * V_6 ,
struct V_53 * V_54 , bool V_131 ,
unsigned int V_132 , const T_1 * V_3 , T_2 V_4 ,
bool V_133 , bool V_134 , T_6 * V_100 )
{
const struct V_15 * V_16 ;
T_3 V_135 ;
if ( ! V_6 -> V_8 -> V_114 )
return - V_115 ;
if ( ! V_10 -> V_98 -> V_136 )
return - V_115 ;
if ( V_4 < 24 + 1 )
return - V_69 ;
V_16 = ( const struct V_15 * ) V_3 ;
if ( ! F_97 ( V_16 -> V_137 ) )
return - V_69 ;
V_135 = F_11 ( V_16 -> V_137 ) & V_118 ;
if ( ! ( V_6 -> V_8 -> V_114 [ V_6 -> V_119 ] . V_138 & F_83 ( V_135 >> 4 ) ) )
return - V_69 ;
if ( F_98 ( V_16 -> V_137 ) &&
V_16 -> V_18 . V_139 . V_140 != V_141 ) {
int V_67 = 0 ;
F_4 ( V_6 ) ;
switch ( V_6 -> V_119 ) {
case V_142 :
case V_143 :
case V_144 :
if ( ! V_6 -> V_30 ) {
V_67 = - V_96 ;
break;
}
if ( ! F_20 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_28 ) ) {
V_67 = - V_96 ;
break;
}
if ( V_6 -> V_119 == V_142 )
break;
if ( ! F_20 ( V_6 -> V_30 -> V_31 . V_28 ,
V_16 -> V_145 ) ) {
V_67 = - V_96 ;
break;
}
break;
case V_146 :
case V_147 :
case V_148 :
if ( ! F_20 ( V_16 -> V_28 , F_99 ( V_6 ) ) )
V_67 = - V_69 ;
break;
case V_149 :
if ( ! F_20 ( V_16 -> V_36 , V_16 -> V_28 ) ) {
V_67 = - V_69 ;
break;
}
break;
case V_150 :
default:
V_67 = - V_115 ;
break;
}
F_7 ( V_6 ) ;
if ( V_67 )
return V_67 ;
}
if ( ! F_20 ( V_16 -> V_36 , F_99 ( V_6 ) ) )
return - V_69 ;
return F_100 ( V_10 , V_6 , V_54 , V_131 ,
V_132 , V_3 , V_4 , V_133 , V_134 ,
V_100 ) ;
}
bool F_101 ( struct V_5 * V_6 , int V_151 , int V_152 ,
const T_1 * V_3 , T_2 V_4 , T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
struct V_110 * V_111 ;
const struct V_153 * V_154 =
& V_8 -> V_114 [ V_6 -> V_119 ] ;
struct V_15 * V_16 = ( void * ) V_3 ;
const T_1 * V_50 ;
int V_155 ;
bool V_156 = false ;
T_7 V_157 = V_16 -> V_137 &
F_88 ( V_116 | V_118 ) ;
T_3 V_135 ;
F_102 ( V_6 , V_151 , V_152 ) ;
V_135 = ( F_11 ( V_16 -> V_137 ) & V_118 ) >> 4 ;
if ( ! ( V_154 -> V_120 & F_83 ( V_135 ) ) ) {
F_103 ( false ) ;
return false ;
}
V_50 = V_3 + F_104 ( V_16 -> V_137 ) ;
V_155 = V_4 - F_104 ( V_16 -> V_137 ) ;
F_85 ( & V_6 -> V_122 ) ;
F_86 (reg, &wdev->mgmt_registrations, list) {
if ( V_111 -> V_107 != V_157 )
continue;
if ( V_111 -> V_109 > V_155 )
continue;
if ( memcmp ( V_111 -> V_124 , V_50 , V_111 -> V_109 ) )
continue;
if ( F_105 ( V_10 , V_6 , V_111 -> V_125 ,
V_151 , V_152 ,
V_3 , V_4 , V_46 ) )
continue;
V_156 = true ;
break;
}
F_91 ( & V_6 -> V_122 ) ;
F_103 ( V_156 ) ;
return V_156 ;
}
void F_106 ( struct V_5 * V_6 , T_6 V_100 ,
const T_1 * V_3 , T_2 V_4 , bool V_158 , T_4 V_46 )
{
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_107 ( V_6 , V_100 , V_158 ) ;
F_108 ( V_10 , V_6 , V_100 , V_3 , V_4 , V_158 , V_46 ) ;
}
void F_109 ( struct V_1 * V_2 ,
enum V_159 V_160 ,
T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_110 ( V_2 , V_160 ) ;
F_111 ( V_10 , V_2 , V_160 , V_46 ) ;
}
void F_112 ( struct V_1 * V_2 ,
const T_1 * V_161 , T_5 V_162 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_113 ( V_2 , V_161 , V_162 ) ;
F_114 ( V_10 , V_2 , V_161 , V_162 , V_46 ) ;
}
void F_115 ( struct V_1 * V_2 ,
const T_1 * V_161 , T_5 V_162 ,
T_5 V_163 , T_5 V_164 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_116 ( V_10 , V_2 , V_161 , V_162 ,
V_163 , V_164 , V_46 ) ;
}
void F_117 ( struct V_1 * V_2 , const T_1 * V_28 ,
const T_1 * V_165 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_118 ( V_2 , V_28 ) ;
F_119 ( V_10 , V_2 , V_28 , V_165 , V_46 ) ;
}
void F_120 ( struct V_1 * V_2 , int V_166 ,
const T_1 * V_28 , bool V_167 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_121 ( V_2 , V_166 , V_28 , V_167 ) ;
F_122 ( V_10 , V_2 , V_166 , V_28 , V_167 , V_46 ) ;
}
void F_123 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
F_124 ( V_2 , V_169 ) ;
F_4 ( V_6 ) ;
if ( F_29 ( V_6 -> V_119 != V_146 &&
V_6 -> V_119 != V_147 ) )
goto V_24;
V_6 -> V_73 = V_169 -> V_54 ;
F_125 ( V_10 , V_2 , V_169 , V_11 ) ;
V_24:
F_7 ( V_6 ) ;
return;
}
bool F_126 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
bool V_170 ;
F_127 ( V_2 , V_41 ) ;
if ( F_29 ( V_6 -> V_119 != V_146 &&
V_6 -> V_119 != V_147 ) ) {
F_103 ( false ) ;
return false ;
}
V_170 = F_128 ( V_2 , V_41 , V_46 ) ;
F_103 ( V_170 ) ;
return V_170 ;
}
bool F_129 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_4 V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
bool V_170 ;
F_130 ( V_2 , V_41 ) ;
if ( F_29 ( V_6 -> V_119 != V_146 &&
V_6 -> V_119 != V_147 &&
V_6 -> V_119 != V_148 ) ) {
F_103 ( false ) ;
return false ;
}
V_170 = F_131 ( V_2 , V_41 , V_46 ) ;
F_103 ( V_170 ) ;
return V_170 ;
}
