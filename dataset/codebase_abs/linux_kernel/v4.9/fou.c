static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static int F_2 ( struct V_5 * V_6 , struct V_1 * V_1 , T_1 V_7 )
{
if ( V_1 -> V_8 == V_9 )
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
else
F_6 ( V_6 ) -> V_11 =
F_4 ( F_5 ( F_6 ( V_6 ) -> V_11 ) - V_7 ) ;
F_7 ( V_6 , V_7 ) ;
F_8 ( V_6 , F_9 ( V_6 ) , V_7 ) ;
F_10 ( V_6 ) ;
return F_11 ( V_6 ) ;
}
static int F_12 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_1 )
return 1 ;
if ( F_2 ( V_6 , V_1 , sizeof( struct V_12 ) ) )
goto V_13;
return - V_1 -> V_14 ;
V_13:
F_13 ( V_6 ) ;
return 0 ;
}
static struct V_15 * F_14 ( struct V_5 * V_6 , struct V_15 * V_15 ,
void * V_16 , T_1 V_17 , T_2 V_18 ,
bool V_19 )
{
T_3 * V_20 = V_16 ;
T_1 V_21 = F_5 ( V_20 [ 0 ] ) ;
T_1 V_22 = F_5 ( V_20 [ 1 ] ) ;
T_1 V_23 = sizeof( struct V_12 ) + V_17 +
F_15 ( T_1 , V_22 + sizeof( V_24 ) , V_21 ) ;
if ( V_6 -> V_25 )
return V_15 ;
if ( ! F_16 ( V_6 , V_23 ) )
return NULL ;
V_15 = (struct V_15 * ) & F_9 ( V_6 ) [ 1 ] ;
F_17 ( V_6 , ( void * ) V_15 + V_17 ,
V_21 , V_22 , V_19 ) ;
return V_15 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_15 * V_15 )
{
F_13 ( V_6 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_7 , V_26 , V_17 ;
struct V_15 * V_15 ;
void * V_16 ;
V_24 V_27 = 0 ;
if ( ! V_1 )
return 1 ;
V_7 = sizeof( struct V_12 ) + sizeof( struct V_15 ) ;
if ( ! F_16 ( V_6 , V_7 ) )
goto V_13;
V_15 = (struct V_15 * ) & F_9 ( V_6 ) [ 1 ] ;
switch ( V_15 -> V_28 ) {
case 0 :
break;
case 1 : {
int V_29 ;
switch ( ( (struct V_30 * ) V_15 ) -> V_28 ) {
case 4 :
V_29 = V_31 ;
break;
case 6 :
V_29 = V_32 ;
break;
default:
goto V_13;
}
if ( F_2 ( V_6 , V_1 , sizeof( struct V_12 ) ) )
goto V_13;
return - V_29 ;
}
default:
goto V_13;
}
V_26 = V_15 -> V_33 << 2 ;
V_7 += V_26 ;
if ( ! F_16 ( V_6 , V_7 ) )
goto V_13;
V_15 = (struct V_15 * ) & F_9 ( V_6 ) [ 1 ] ;
V_17 = sizeof( struct V_15 ) + V_26 ;
if ( V_15 -> V_28 != 0 || F_20 ( V_15 , V_26 ) )
goto V_13;
V_17 = sizeof( struct V_15 ) + V_26 ;
if ( V_1 -> V_8 == V_9 )
F_3 ( V_6 ) -> V_10 = F_4 ( F_5 ( F_3 ( V_6 ) -> V_10 ) - V_7 ) ;
else
F_6 ( V_6 ) -> V_11 =
F_4 ( F_5 ( F_6 ( V_6 ) -> V_11 ) - V_7 ) ;
F_8 ( V_6 , F_9 ( V_6 ) , V_7 ) ;
V_16 = & V_15 [ 1 ] ;
if ( V_15 -> V_34 & V_35 ) {
T_4 V_34 = * ( T_4 * ) ( V_16 + V_27 ) ;
V_27 += V_36 ;
if ( V_34 & V_37 ) {
V_15 = F_14 ( V_6 , V_15 , V_16 + V_27 ,
V_17 , V_15 -> V_38 ,
! ! ( V_1 -> V_34 &
V_39 ) ) ;
if ( ! V_15 )
goto V_13;
V_16 = & V_15 [ 1 ] ;
V_27 += V_40 ;
}
}
if ( F_21 ( V_15 -> V_41 ) )
return F_18 ( V_6 , V_15 ) ;
F_7 ( V_6 , sizeof( struct V_12 ) + V_17 ) ;
F_10 ( V_6 ) ;
if ( F_11 ( V_6 ) )
goto V_13;
return - V_15 -> V_38 ;
V_13:
F_13 ( V_6 ) ;
return 0 ;
}
static struct V_5 * * F_22 ( struct V_2 * V_3 ,
struct V_5 * * V_42 ,
struct V_5 * V_6 )
{
const struct V_43 * V_44 ;
struct V_5 * * V_45 = NULL ;
T_2 V_46 = F_1 ( V_3 ) -> V_14 ;
const struct V_43 * * V_47 ;
F_23 ( V_6 ) -> V_48 = 0 ;
F_23 ( V_6 ) -> V_49 = 1 ;
F_24 () ;
V_47 = F_23 ( V_6 ) -> V_50 ? V_51 : V_52 ;
V_44 = F_25 ( V_47 [ V_46 ] ) ;
if ( ! V_44 || ! V_44 -> V_53 . V_54 )
goto V_55;
V_45 = F_26 ( V_44 -> V_53 . V_54 , V_42 , V_6 ) ;
V_55:
F_27 () ;
return V_45 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_5 * V_6 ,
int V_56 )
{
const struct V_43 * V_44 ;
T_2 V_46 = F_1 ( V_3 ) -> V_14 ;
int V_57 = - V_58 ;
const struct V_43 * * V_47 ;
F_24 () ;
V_47 = F_23 ( V_6 ) -> V_50 ? V_51 : V_52 ;
V_44 = F_25 ( V_47 [ V_46 ] ) ;
if ( F_29 ( ! V_44 || ! V_44 -> V_53 . V_59 ) )
goto V_55;
V_57 = V_44 -> V_53 . V_59 ( V_6 , V_56 ) ;
F_30 ( V_6 , V_56 ) ;
V_55:
F_27 () ;
return V_57 ;
}
static struct V_15 * F_31 ( struct V_5 * V_6 , unsigned int V_60 ,
struct V_15 * V_15 , void * V_16 ,
T_1 V_17 , struct V_61 * V_62 ,
bool V_19 )
{
T_3 * V_20 = V_16 ;
T_1 V_21 = F_5 ( V_20 [ 0 ] ) ;
T_1 V_22 = F_5 ( V_20 [ 1 ] ) ;
if ( V_6 -> V_25 )
return V_15 ;
if ( ! F_23 ( V_6 ) -> V_63 )
return NULL ;
V_15 = F_32 ( V_6 , ( void * ) V_15 , V_60 , V_17 ,
V_21 , V_22 , V_62 , V_19 ) ;
V_6 -> V_25 = 1 ;
return V_15 ;
}
static struct V_5 * * F_33 ( struct V_2 * V_3 ,
struct V_5 * * V_42 ,
struct V_5 * V_6 )
{
const struct V_43 * * V_47 ;
const struct V_43 * V_44 ;
struct V_5 * * V_45 = NULL ;
struct V_5 * V_64 ;
struct V_15 * V_15 ;
T_1 V_7 , V_26 , V_17 , V_60 ;
void * V_16 ;
V_24 V_27 = 0 ;
int V_65 = 1 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_61 V_62 ;
T_2 V_46 ;
F_34 ( & V_62 ) ;
V_60 = F_35 ( V_6 ) ;
V_7 = V_60 + sizeof( * V_15 ) ;
V_15 = F_36 ( V_6 , V_60 ) ;
if ( F_37 ( V_6 , V_7 ) ) {
V_15 = F_38 ( V_6 , V_7 , V_60 ) ;
if ( F_21 ( ! V_15 ) )
goto V_66;
}
switch ( V_15 -> V_28 ) {
case 0 :
break;
case 1 :
switch ( ( (struct V_30 * ) V_15 ) -> V_28 ) {
case 4 :
V_46 = V_31 ;
break;
case 6 :
V_46 = V_32 ;
break;
default:
goto V_66;
}
goto V_67;
default:
goto V_66;
}
V_26 = V_15 -> V_33 << 2 ;
V_7 += V_26 ;
if ( F_37 ( V_6 , V_7 ) ) {
V_15 = F_38 ( V_6 , V_7 , V_60 ) ;
if ( F_21 ( ! V_15 ) )
goto V_66;
}
if ( F_21 ( V_15 -> V_41 ) || V_15 -> V_28 != 0 ||
F_20 ( V_15 , V_26 ) )
goto V_66;
V_17 = sizeof( * V_15 ) + V_26 ;
F_39 ( V_6 , V_15 , V_17 ) ;
V_16 = & V_15 [ 1 ] ;
if ( V_15 -> V_34 & V_35 ) {
T_4 V_34 = * ( T_4 * ) ( V_16 + V_27 ) ;
V_27 += V_36 ;
if ( V_34 & V_37 ) {
V_15 = F_31 ( V_6 , V_60 , V_15 ,
V_16 + V_27 , V_17 , & V_62 ,
! ! ( V_1 -> V_34 &
V_39 ) ) ;
if ( ! V_15 )
goto V_66;
V_16 = & V_15 [ 1 ] ;
V_27 += V_40 ;
}
}
F_40 ( V_6 , V_17 ) ;
for ( V_64 = * V_42 ; V_64 ; V_64 = V_64 -> V_68 ) {
const struct V_15 * V_69 ;
if ( ! F_23 ( V_64 ) -> V_70 )
continue;
V_69 = (struct V_15 * ) ( V_64 -> V_16 + V_60 ) ;
if ( V_15 -> V_71 != V_69 -> V_71 ) {
F_23 ( V_64 ) -> V_70 = 0 ;
continue;
}
if ( V_15 -> V_33 && memcmp ( & V_15 [ 1 ] , & V_69 [ 1 ] ,
V_15 -> V_33 << 2 ) ) {
F_23 ( V_64 ) -> V_70 = 0 ;
continue;
}
}
V_46 = V_15 -> V_38 ;
V_67:
F_23 ( V_6 ) -> V_48 = 0 ;
F_23 ( V_6 ) -> V_49 = 1 ;
F_24 () ;
V_47 = F_23 ( V_6 ) -> V_50 ? V_51 : V_52 ;
V_44 = F_25 ( V_47 [ V_46 ] ) ;
if ( F_41 ( ! V_44 || ! V_44 -> V_53 . V_54 ) )
goto V_55;
V_45 = F_26 ( V_44 -> V_53 . V_54 , V_42 , V_6 ) ;
V_65 = 0 ;
V_55:
F_27 () ;
V_66:
F_23 ( V_6 ) -> V_65 |= V_65 ;
F_42 ( V_6 , & V_62 ) ;
return V_45 ;
}
static int F_43 ( struct V_2 * V_3 , struct V_5 * V_6 , int V_56 )
{
const struct V_43 * * V_47 ;
struct V_15 * V_15 = (struct V_15 * ) ( V_6 -> V_16 + V_56 ) ;
const struct V_43 * V_44 ;
unsigned int V_72 = 0 ;
T_2 V_46 ;
int V_57 = - V_73 ;
switch ( V_15 -> V_28 ) {
case 0 :
V_46 = V_15 -> V_38 ;
V_72 = sizeof( * V_15 ) + ( V_15 -> V_33 << 2 ) ;
break;
case 1 :
switch ( ( (struct V_30 * ) V_15 ) -> V_28 ) {
case 4 :
V_46 = V_31 ;
break;
case 6 :
V_46 = V_32 ;
break;
default:
return V_57 ;
}
break;
default:
return V_57 ;
}
F_24 () ;
V_47 = F_23 ( V_6 ) -> V_50 ? V_51 : V_52 ;
V_44 = F_25 ( V_47 [ V_46 ] ) ;
if ( F_29 ( ! V_44 || ! V_44 -> V_53 . V_59 ) )
goto V_55;
V_57 = V_44 -> V_53 . V_59 ( V_6 , V_56 + V_72 ) ;
F_30 ( V_6 , V_56 + V_72 ) ;
V_55:
F_27 () ;
return V_57 ;
}
static int F_44 ( struct V_74 * V_74 , struct V_1 * V_1 )
{
struct V_75 * V_76 = F_45 ( V_74 , V_77 ) ;
struct V_1 * V_78 ;
F_46 ( & V_76 -> V_79 ) ;
F_47 (fout, &fn->fou_list, list) {
if ( V_1 -> V_80 == V_78 -> V_80 &&
V_1 -> V_8 == V_78 -> V_8 ) {
F_48 ( & V_76 -> V_79 ) ;
return - V_81 ;
}
}
F_49 ( & V_1 -> V_82 , & V_76 -> V_83 ) ;
F_48 ( & V_76 -> V_79 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_84 * V_2 = V_1 -> V_2 ;
F_51 ( & V_1 -> V_82 ) ;
F_52 ( V_2 ) ;
F_53 ( V_1 , V_85 ) ;
}
static int F_54 ( struct V_74 * V_74 , struct V_86 * V_87 ,
struct V_84 * * V_88 )
{
struct V_84 * V_2 = NULL ;
struct V_1 * V_1 = NULL ;
struct V_2 * V_3 ;
struct V_89 V_90 ;
int V_57 ;
V_57 = F_55 ( V_74 , & V_87 -> V_91 , & V_2 ) ;
if ( V_57 < 0 )
goto error;
V_1 = F_56 ( sizeof( * V_1 ) , V_92 ) ;
if ( ! V_1 ) {
V_57 = - V_93 ;
goto error;
}
V_3 = V_2 -> V_3 ;
V_1 -> V_80 = V_87 -> V_91 . V_94 ;
V_1 -> V_8 = V_87 -> V_91 . V_8 ;
V_1 -> V_34 = V_87 -> V_34 ;
V_1 -> type = V_87 -> type ;
V_1 -> V_2 = V_2 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_95 = 1 ;
V_90 . V_4 = V_1 ;
V_90 . V_96 = NULL ;
switch ( V_87 -> type ) {
case V_97 :
V_90 . V_98 = F_12 ;
V_90 . V_54 = F_22 ;
V_90 . V_59 = F_28 ;
V_1 -> V_14 = V_87 -> V_14 ;
break;
case V_99 :
V_90 . V_98 = F_19 ;
V_90 . V_54 = F_33 ;
V_90 . V_59 = F_43 ;
break;
default:
V_57 = - V_100 ;
goto error;
}
F_57 ( V_74 , V_2 , & V_90 ) ;
V_3 -> V_101 = V_102 ;
V_57 = F_44 ( V_74 , V_1 ) ;
if ( V_57 )
goto error;
if ( V_88 )
* V_88 = V_2 ;
return 0 ;
error:
F_58 ( V_1 ) ;
if ( V_2 )
F_52 ( V_2 ) ;
return V_57 ;
}
static int F_59 ( struct V_74 * V_74 , struct V_86 * V_87 )
{
struct V_75 * V_76 = F_45 ( V_74 , V_77 ) ;
T_3 V_80 = V_87 -> V_91 . V_94 ;
T_2 V_8 = V_87 -> V_91 . V_8 ;
int V_57 = - V_100 ;
struct V_1 * V_1 ;
F_46 ( & V_76 -> V_79 ) ;
F_47 (fou, &fn->fou_list, list) {
if ( V_1 -> V_80 == V_80 && V_1 -> V_8 == V_8 ) {
F_50 ( V_1 ) ;
V_57 = 0 ;
break;
}
}
F_48 ( & V_76 -> V_79 ) ;
return V_57 ;
}
static int F_60 ( struct V_103 * V_104 ,
struct V_86 * V_87 )
{
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> V_91 . V_8 = V_9 ;
if ( V_104 -> V_105 [ V_106 ] ) {
T_2 V_8 = F_61 ( V_104 -> V_105 [ V_106 ] ) ;
switch ( V_8 ) {
case V_9 :
break;
case V_107 :
V_87 -> V_91 . V_108 = 1 ;
break;
default:
return - V_109 ;
}
V_87 -> V_91 . V_8 = V_8 ;
}
if ( V_104 -> V_105 [ V_110 ] ) {
T_3 V_80 = F_62 ( V_104 -> V_105 [ V_110 ] ) ;
V_87 -> V_91 . V_94 = V_80 ;
}
if ( V_104 -> V_105 [ V_111 ] )
V_87 -> V_14 = F_61 ( V_104 -> V_105 [ V_111 ] ) ;
if ( V_104 -> V_105 [ V_112 ] )
V_87 -> type = F_61 ( V_104 -> V_105 [ V_112 ] ) ;
if ( V_104 -> V_105 [ V_113 ] )
V_87 -> V_34 |= V_39 ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_103 * V_104 )
{
struct V_74 * V_74 = F_64 ( V_104 ) ;
struct V_86 V_87 ;
int V_57 ;
V_57 = F_60 ( V_104 , & V_87 ) ;
if ( V_57 )
return V_57 ;
return F_54 ( V_74 , & V_87 , NULL ) ;
}
static int F_65 ( struct V_5 * V_6 , struct V_103 * V_104 )
{
struct V_74 * V_74 = F_64 ( V_104 ) ;
struct V_86 V_87 ;
int V_57 ;
V_57 = F_60 ( V_104 , & V_87 ) ;
if ( V_57 )
return V_57 ;
return F_59 ( V_74 , & V_87 ) ;
}
static int F_66 ( struct V_1 * V_1 , struct V_5 * V_114 )
{
if ( F_67 ( V_114 , V_106 , V_1 -> V_2 -> V_3 -> V_115 ) ||
F_68 ( V_114 , V_110 , V_1 -> V_80 ) ||
F_67 ( V_114 , V_111 , V_1 -> V_14 ) ||
F_67 ( V_114 , V_112 , V_1 -> type ) )
return - 1 ;
if ( V_1 -> V_34 & V_39 )
if ( F_69 ( V_114 , V_113 ) )
return - 1 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_1 , T_5 V_116 , T_5 V_117 ,
T_5 V_34 , struct V_5 * V_6 , T_2 V_118 )
{
void * V_119 ;
V_119 = F_71 ( V_6 , V_116 , V_117 , & V_120 , V_34 , V_118 ) ;
if ( ! V_119 )
return - V_93 ;
if ( F_66 ( V_1 , V_6 ) < 0 )
goto V_121;
F_72 ( V_6 , V_119 ) ;
return 0 ;
V_121:
F_73 ( V_6 , V_119 ) ;
return - V_122 ;
}
static int F_74 ( struct V_5 * V_6 , struct V_103 * V_104 )
{
struct V_74 * V_74 = F_64 ( V_104 ) ;
struct V_75 * V_76 = F_45 ( V_74 , V_77 ) ;
struct V_5 * V_114 ;
struct V_86 V_87 ;
struct V_1 * V_78 ;
T_3 V_80 ;
T_2 V_8 ;
int V_123 ;
V_123 = F_60 ( V_104 , & V_87 ) ;
if ( V_123 )
return V_123 ;
V_80 = V_87 . V_91 . V_94 ;
if ( V_80 == 0 )
return - V_100 ;
V_8 = V_87 . V_91 . V_8 ;
if ( V_8 != V_9 && V_8 != V_107 )
return - V_100 ;
V_114 = F_75 ( V_124 , V_92 ) ;
if ( ! V_114 )
return - V_93 ;
V_123 = - V_125 ;
F_46 ( & V_76 -> V_79 ) ;
F_47 (fout, &fn->fou_list, list) {
if ( V_80 == V_78 -> V_80 && V_8 == V_78 -> V_8 ) {
V_123 = F_70 ( V_78 , V_104 -> V_126 ,
V_104 -> V_127 , 0 , V_114 ,
V_104 -> V_128 -> V_118 ) ;
break;
}
}
F_48 ( & V_76 -> V_79 ) ;
if ( V_123 < 0 )
goto V_129;
return F_76 ( V_114 , V_104 ) ;
V_129:
F_77 ( V_114 ) ;
return V_123 ;
}
static int F_78 ( struct V_5 * V_6 , struct V_130 * V_131 )
{
struct V_74 * V_74 = F_79 ( V_6 -> V_3 ) ;
struct V_75 * V_76 = F_45 ( V_74 , V_77 ) ;
struct V_1 * V_78 ;
int V_132 = 0 , V_123 ;
F_46 ( & V_76 -> V_79 ) ;
F_47 (fout, &fn->fou_list, list) {
if ( V_132 ++ < V_131 -> args [ 0 ] )
continue;
V_123 = F_70 ( V_78 , F_80 ( V_131 -> V_6 ) . V_116 ,
V_131 -> V_133 -> V_134 , V_135 ,
V_6 , V_136 ) ;
if ( V_123 )
break;
}
F_48 ( & V_76 -> V_79 ) ;
V_131 -> args [ 0 ] = V_132 ;
return V_6 -> V_7 ;
}
T_1 F_81 ( struct V_137 * V_138 )
{
return sizeof( struct V_12 ) ;
}
T_1 F_82 ( struct V_137 * V_138 )
{
T_1 V_7 ;
bool V_139 = false ;
V_7 = sizeof( struct V_12 ) + sizeof( struct V_15 ) ;
if ( V_138 -> V_34 & V_140 ) {
V_7 += V_40 ;
V_139 = true ;
}
V_7 += V_139 ? V_36 : 0 ;
return V_7 ;
}
static void F_83 ( struct V_5 * V_6 , struct V_137 * V_138 ,
struct V_141 * V_142 , T_2 * V_14 , T_3 V_143 )
{
struct V_12 * V_144 ;
F_84 ( V_6 , sizeof( struct V_12 ) ) ;
F_10 ( V_6 ) ;
V_144 = F_9 ( V_6 ) ;
V_144 -> V_145 = V_138 -> V_146 ;
V_144 -> V_147 = V_143 ;
V_144 -> V_7 = F_4 ( V_6 -> V_7 ) ;
F_85 ( ! ( V_138 -> V_34 & V_148 ) , V_6 ,
V_142 -> V_149 , V_142 -> V_150 , V_6 -> V_7 ) ;
* V_14 = V_151 ;
}
int F_86 ( struct V_5 * V_6 , struct V_137 * V_138 ,
T_2 * V_14 , T_3 * V_143 , int type )
{
int V_57 ;
V_57 = F_87 ( V_6 , type ) ;
if ( V_57 )
return V_57 ;
* V_143 = V_138 -> V_143 ? : F_88 ( F_89 ( V_6 -> V_152 ) ,
V_6 , 0 , 0 , false ) ;
return 0 ;
}
int F_90 ( struct V_5 * V_6 , struct V_137 * V_138 ,
T_2 * V_14 , struct V_141 * V_142 )
{
int type = V_138 -> V_34 & V_148 ? V_153 :
V_154 ;
T_3 V_143 ;
int V_57 ;
V_57 = F_86 ( V_6 , V_138 , V_14 , & V_143 , type ) ;
if ( V_57 )
return V_57 ;
F_83 ( V_6 , V_138 , V_142 , V_14 , V_143 ) ;
return 0 ;
}
int F_91 ( struct V_5 * V_6 , struct V_137 * V_138 ,
T_2 * V_14 , T_3 * V_143 , int type )
{
struct V_15 * V_15 ;
T_1 V_17 , V_26 = 0 ;
void * V_16 ;
bool V_139 = false ;
int V_57 ;
if ( ( V_138 -> V_34 & V_140 ) &&
V_6 -> V_155 == V_156 ) {
V_26 += V_40 ;
type |= V_157 ;
V_139 = true ;
}
V_26 += V_139 ? V_36 : 0 ;
V_57 = F_87 ( V_6 , type ) ;
if ( V_57 )
return V_57 ;
* V_143 = V_138 -> V_143 ? : F_88 ( F_89 ( V_6 -> V_152 ) ,
V_6 , 0 , 0 , false ) ;
V_17 = sizeof( struct V_15 ) + V_26 ;
F_84 ( V_6 , V_17 ) ;
V_15 = (struct V_15 * ) V_6 -> V_16 ;
V_15 -> V_41 = 0 ;
V_15 -> V_28 = 0 ;
V_15 -> V_33 = V_26 >> 2 ;
V_15 -> V_34 = 0 ;
V_15 -> V_38 = * V_14 ;
V_16 = & V_15 [ 1 ] ;
if ( V_139 ) {
T_4 * V_34 = V_16 ;
V_15 -> V_34 |= V_35 ;
* V_34 = 0 ;
V_16 += V_36 ;
if ( type & V_157 ) {
V_24 V_158 = F_92 ( V_6 ) ;
T_3 * V_20 = V_16 ;
if ( V_158 < V_17 )
return - V_100 ;
V_158 -= V_17 ;
V_20 [ 0 ] = F_4 ( V_158 ) ;
V_20 [ 1 ] = F_4 ( V_158 + V_6 -> V_159 ) ;
if ( ! F_93 ( V_6 ) ) {
V_6 -> V_155 = V_160 ;
V_6 -> V_161 = 0 ;
}
* V_34 |= V_37 ;
V_16 += V_40 ;
}
}
return 0 ;
}
int F_94 ( struct V_5 * V_6 , struct V_137 * V_138 ,
T_2 * V_14 , struct V_141 * V_142 )
{
int type = V_138 -> V_34 & V_148 ? V_153 :
V_154 ;
T_3 V_143 ;
int V_57 ;
V_57 = F_91 ( V_6 , V_138 , V_14 , & V_143 , type ) ;
if ( V_57 )
return V_57 ;
F_83 ( V_6 , V_138 , V_142 , V_14 , V_143 ) ;
return 0 ;
}
static int F_95 ( void )
{
int V_123 ;
V_123 = F_96 ( & V_162 , V_163 ) ;
if ( V_123 < 0 ) {
F_97 ( L_1 ) ;
return V_123 ;
}
V_123 = F_96 ( & V_164 , V_165 ) ;
if ( V_123 < 0 ) {
F_97 ( L_2 ) ;
F_98 ( & V_162 , V_163 ) ;
return V_123 ;
}
return 0 ;
}
static void F_99 ( void )
{
F_98 ( & V_162 , V_163 ) ;
F_98 ( & V_164 , V_165 ) ;
}
static int F_95 ( void )
{
return 0 ;
}
static void F_99 ( void )
{
}
static T_6 int F_100 ( struct V_74 * V_74 )
{
struct V_75 * V_76 = F_45 ( V_74 , V_77 ) ;
F_101 ( & V_76 -> V_83 ) ;
F_102 ( & V_76 -> V_79 ) ;
return 0 ;
}
static T_7 void F_103 ( struct V_74 * V_74 )
{
struct V_75 * V_76 = F_45 ( V_74 , V_77 ) ;
struct V_1 * V_1 , * V_68 ;
F_46 ( & V_76 -> V_79 ) ;
F_104 (fou, next, &fn->fou_list, list)
F_50 ( V_1 ) ;
F_48 ( & V_76 -> V_79 ) ;
}
static int T_8 F_105 ( void )
{
int V_123 ;
V_123 = F_106 ( & V_166 ) ;
if ( V_123 )
goto exit;
V_123 = F_107 ( & V_120 ,
V_167 ) ;
if ( V_123 < 0 )
goto V_168;
V_123 = F_95 () ;
if ( V_123 == 0 )
return 0 ;
F_108 ( & V_120 ) ;
V_168:
F_109 ( & V_166 ) ;
exit:
return V_123 ;
}
static void T_9 F_110 ( void )
{
F_99 () ;
F_108 ( & V_120 ) ;
F_109 ( & V_166 ) ;
}
