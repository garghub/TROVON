void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
if ( V_2 -> V_6 . V_7 == 0 ) {
return;
}
if ( V_2 -> V_6 . V_8 == V_9 ) {
V_2 -> V_6 . V_8 = F_2 ( V_4 -> V_10 , V_2 -> V_6 . V_11 ,
V_2 -> V_6 . V_7 , V_2 -> V_12
? V_13 : V_14 ) ;
V_2 -> V_15 = true ;
}
}
void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
if ( V_2 -> V_6 . V_7 == 0 ) {
V_2 -> V_6 . V_8 = V_9 ;
return;
}
if ( V_2 -> V_15 ) {
F_4 ( V_4 -> V_10 , V_2 -> V_6 . V_8 ,
V_2 -> V_6 . V_7 , V_2 -> V_12
? V_13 : V_14 ) ;
V_2 -> V_15 = 0 ;
V_2 -> V_6 . V_8 = V_9 ;
}
}
void F_5 ( struct V_16 * V_5 , struct V_1 * V_2 ,
int V_17 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
if ( V_2 -> V_18 ) {
V_5 -> V_19 ++ ;
if ( ( ( V_5 -> V_19 & V_20 ) == V_21 - 1 ) &&
F_6 ( V_5 -> V_22 ) )
V_5 -> V_19 ++ ;
}
F_7 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_6 . V_17 == - V_24 )
V_2 -> V_6 . V_17 = V_17 ;
F_3 ( V_2 ) ;
F_8 ( V_4 -> V_10 , L_1 ,
V_2 , V_5 -> V_25 , V_2 -> V_6 . V_26 ,
V_2 -> V_6 . V_7 , V_17 ) ;
F_9 ( & V_4 -> V_27 ) ;
V_2 -> V_6 . V_28 ( & V_2 -> V_5 -> V_29 , & V_2 -> V_6 ) ;
F_10 ( & V_4 -> V_27 ) ;
}
static const char * F_11 ( T_1 V_30 )
{
switch ( V_30 ) {
case V_31 :
return L_2 ;
case V_32 :
return L_3 ;
case V_33 :
return L_4 ;
case V_34 :
return L_5 ;
case V_35 :
return L_6 ;
case V_36 :
return L_7 ;
case V_37 :
return L_8 ;
case V_38 :
return L_9 ;
case V_39 :
return L_10 ;
default:
return L_11 ;
}
}
int F_12 ( struct V_3 * V_4 , unsigned V_40 ,
unsigned V_30 , struct V_41 * V_42 )
{
struct V_16 * V_5 = V_4 -> V_43 [ V_40 ] ;
T_2 V_44 = 500 ;
T_2 V_45 ;
F_13 ( V_4 -> V_10 , L_12 ,
V_5 -> V_25 ,
F_11 ( V_30 ) , V_42 -> V_46 ,
V_42 -> V_47 , V_42 -> V_48 ) ;
F_14 ( V_4 -> V_49 , F_15 ( V_40 ) , V_42 -> V_46 ) ;
F_14 ( V_4 -> V_49 , F_16 ( V_40 ) , V_42 -> V_47 ) ;
F_14 ( V_4 -> V_49 , F_17 ( V_40 ) , V_42 -> V_48 ) ;
F_14 ( V_4 -> V_49 , F_18 ( V_40 ) , V_30 | V_50 ) ;
do {
V_45 = F_19 ( V_4 -> V_49 , F_18 ( V_40 ) ) ;
if ( ! ( V_45 & V_50 ) ) {
F_13 ( V_4 -> V_10 , L_13 ,
F_20 ( V_45 ) ) ;
return 0 ;
}
V_44 -- ;
if ( ! V_44 )
return - V_51 ;
F_21 ( 1 ) ;
} while ( 1 );
}
static T_3 F_22 ( struct V_16 * V_5 ,
struct V_52 * V_53 )
{
T_2 V_54 = ( char * ) V_53 - ( char * ) V_5 -> V_55 ;
return V_5 -> V_56 + V_54 ;
}
static int F_23 ( struct V_16 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
if ( V_5 -> V_55 )
return 0 ;
if ( V_5 -> V_57 == 0 || V_5 -> V_57 == 1 )
return 0 ;
V_5 -> V_55 = F_24 ( V_4 -> V_10 ,
sizeof( struct V_58 ) * V_21 ,
& V_5 -> V_56 , V_59 ) ;
if ( ! V_5 -> V_55 ) {
F_25 ( V_5 -> V_4 -> V_10 , L_14 ,
V_5 -> V_25 ) ;
return - V_60 ;
}
return 0 ;
}
static void F_26 ( struct V_16 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
F_27 ( V_4 -> V_10 , sizeof( struct V_58 ) * V_21 ,
V_5 -> V_55 , V_5 -> V_56 ) ;
V_5 -> V_55 = NULL ;
V_5 -> V_56 = 0 ;
}
static int F_28 ( struct V_3 * V_4 , struct V_16 * V_5 )
{
struct V_41 V_42 ;
T_2 V_30 ;
memset ( & V_42 , 0x00 , sizeof( V_42 ) ) ;
if ( V_5 -> V_57 != 1 ) {
V_30 = V_31 ;
if ( V_5 -> V_57 > 1 ) {
if ( V_4 -> V_61 )
return 0 ;
V_4 -> V_61 = true ;
V_30 |= F_29 ( 2 ) ;
}
return F_12 ( V_4 , 0 , V_30 , & V_42 ) ;
}
return 0 ;
}
static int F_30 ( struct V_3 * V_4 , struct V_16 * V_5 ,
const struct V_62 * V_22 )
{
struct V_41 V_42 ;
memset ( & V_42 , 0x00 , sizeof( V_42 ) ) ;
V_42 . V_46 = F_31 ( F_32 ( V_22 ) )
| F_33 ( F_34 ( V_22 ) )
| F_35 ( V_5 -> V_29 . V_63 ) ;
V_42 . V_47 = V_64
| V_65 ;
if ( F_36 ( V_22 ) && V_5 -> V_29 . V_66 ) {
V_42 . V_47 |= V_67
| V_68 ;
V_5 -> V_69 = true ;
}
if ( F_6 ( V_22 ) )
V_42 . V_47 |= V_70 ;
V_42 . V_47 |= F_37 ( V_5 -> V_57 ) ;
if ( V_5 -> V_12 )
V_42 . V_46 |= F_38 ( V_5 -> V_57 >> 1 ) ;
if ( V_22 -> V_71 ) {
V_42 . V_47 |= F_39 ( V_22 -> V_71 - 1 ) ;
V_5 -> V_72 = 1 << ( V_22 -> V_71 - 1 ) ;
}
return F_12 ( V_4 , V_5 -> V_57 ,
V_39 , & V_42 ) ;
}
static int F_40 ( struct V_3 * V_4 , struct V_16 * V_5 )
{
struct V_41 V_42 ;
memset ( & V_42 , 0x00 , sizeof( V_42 ) ) ;
V_42 . V_46 = F_41 ( 1 ) ;
return F_12 ( V_4 , V_5 -> V_57 ,
V_38 , & V_42 ) ;
}
static int F_42 ( struct V_16 * V_5 ,
const struct V_62 * V_22 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
T_2 V_45 ;
int V_73 = - V_60 ;
if ( ! ( V_5 -> V_74 & V_75 ) ) {
V_73 = F_28 ( V_4 , V_5 ) ;
if ( V_73 )
return V_73 ;
}
V_73 = F_30 ( V_4 , V_5 , V_22 ) ;
if ( V_73 )
return V_73 ;
if ( ! ( V_5 -> V_74 & V_75 ) ) {
struct V_52 * V_76 ;
struct V_52 * V_77 ;
struct V_58 V_78 ;
V_73 = F_40 ( V_4 , V_5 ) ;
if ( V_73 )
return V_73 ;
V_5 -> V_22 = V_22 ;
V_5 -> type = F_32 ( V_22 ) ;
V_5 -> V_74 |= V_75 ;
V_45 = F_19 ( V_4 -> V_49 , V_79 ) ;
V_45 |= F_43 ( V_5 -> V_57 ) ;
F_14 ( V_4 -> V_49 , V_79 , V_45 ) ;
if ( ! F_6 ( V_22 ) )
return 0 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_76 = & V_5 -> V_55 [ 0 ] ;
V_78 . V_80 = F_22 ( V_5 , V_76 ) ;
V_78 . V_81 = V_82 ;
V_78 . V_83 = true ;
V_77 = & V_5 -> V_55 [ V_21 - 1 ] ;
F_44 ( & V_78 , V_77 ) ;
}
return 0 ;
}
static void F_45 ( struct V_3 * V_4 , struct V_16 * V_5 )
{
struct V_1 * V_2 ;
if ( ! F_46 ( & V_5 -> V_84 ) )
F_47 ( V_4 , V_5 -> V_57 ) ;
while ( ! F_46 ( & V_5 -> V_85 ) ) {
V_2 = F_48 ( & V_5 -> V_85 ) ;
F_5 ( V_5 , V_2 , - V_86 ) ;
}
}
static int F_49 ( struct V_16 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
T_2 V_45 ;
F_45 ( V_4 , V_5 ) ;
V_45 = F_19 ( V_4 -> V_49 , V_79 ) ;
V_45 &= ~ F_43 ( V_5 -> V_57 ) ;
F_14 ( V_4 -> V_49 , V_79 , V_45 ) ;
V_5 -> V_69 = false ;
V_5 -> V_22 = NULL ;
V_5 -> type = 0 ;
V_5 -> V_74 = 0 ;
return 0 ;
}
static int F_50 ( struct V_87 * V_40 ,
const struct V_62 * V_22 )
{
return - V_88 ;
}
static int F_51 ( struct V_87 * V_40 )
{
return - V_88 ;
}
static int F_52 ( struct V_87 * V_40 ,
const struct V_62 * V_22 )
{
struct V_16 * V_5 ;
struct V_3 * V_4 ;
unsigned long V_74 ;
int V_73 ;
if ( ! V_40 || ! V_22 || V_22 -> V_89 != V_90 ) {
F_53 ( L_15 ) ;
return - V_88 ;
}
if ( ! V_22 -> V_91 ) {
F_53 ( L_16 ) ;
return - V_88 ;
}
V_5 = F_54 ( V_40 ) ;
V_4 = V_5 -> V_4 ;
switch ( F_32 ( V_22 ) ) {
case V_92 :
strncat ( V_5 -> V_25 , L_17 , sizeof( V_5 -> V_25 ) ) ;
break;
case V_93 :
strncat ( V_5 -> V_25 , L_18 , sizeof( V_5 -> V_25 ) ) ;
break;
case V_94 :
strncat ( V_5 -> V_25 , L_19 , sizeof( V_5 -> V_25 ) ) ;
break;
case V_95 :
strncat ( V_5 -> V_25 , L_20 , sizeof( V_5 -> V_25 ) ) ;
break;
default:
F_25 ( V_4 -> V_10 , L_21 ) ;
}
if ( V_5 -> V_74 & V_75 ) {
F_55 ( V_4 -> V_10 , true , L_22 ,
V_5 -> V_25 ) ;
return 0 ;
}
F_13 ( V_4 -> V_10 , L_23 , V_5 -> V_25 ) ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
V_73 = F_42 ( V_5 , V_22 ) ;
F_57 ( & V_4 -> V_27 , V_74 ) ;
return V_73 ;
}
static int F_58 ( struct V_87 * V_40 )
{
struct V_16 * V_5 ;
struct V_3 * V_4 ;
unsigned long V_74 ;
int V_73 ;
if ( ! V_40 ) {
F_53 ( L_15 ) ;
return - V_88 ;
}
V_5 = F_54 ( V_40 ) ;
V_4 = V_5 -> V_4 ;
if ( ! ( V_5 -> V_74 & V_75 ) ) {
F_55 ( V_4 -> V_10 , true , L_24 ,
V_5 -> V_25 ) ;
return 0 ;
}
snprintf ( V_5 -> V_25 , sizeof( V_5 -> V_25 ) , L_25 ,
V_5 -> V_57 >> 1 ,
( V_5 -> V_57 & 1 ) ? L_26 : L_27 ) ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
V_73 = F_49 ( V_5 ) ;
F_57 ( & V_4 -> V_27 , V_74 ) ;
return V_73 ;
}
static struct V_96 * F_59 ( struct V_87 * V_40 ,
T_4 V_97 )
{
struct V_1 * V_2 ;
struct V_16 * V_5 = F_54 ( V_40 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
V_2 = F_60 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 ) {
F_25 ( V_4 -> V_10 , L_28 ) ;
return NULL ;
}
V_2 -> V_98 = V_5 -> V_57 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 . V_8 = V_9 ;
return & V_2 -> V_6 ;
}
static void F_61 ( struct V_87 * V_40 ,
struct V_96 * V_6 )
{
struct V_1 * V_2 = F_62 ( V_6 ) ;
F_63 ( V_2 ) ;
}
static struct V_1 * F_64 ( struct V_16 * V_5 ,
bool V_99 )
{
struct V_1 * V_2 , * V_100 , * V_73 = NULL ;
struct V_52 * V_101 ;
struct V_58 V_53 ;
T_2 V_102 ;
F_65 ( V_21 ) ;
V_102 = ( V_5 -> V_19 - V_5 -> V_103 ) & V_20 ;
if ( ! V_102 ) {
if ( ! V_99 )
return NULL ;
V_102 = V_21 ;
if ( F_6 ( V_5 -> V_22 ) ) {
V_5 -> V_19 = 1 ;
V_5 -> V_103 = 1 ;
} else {
V_5 -> V_19 = 0 ;
V_5 -> V_103 = 0 ;
}
}
if ( ( V_102 <= 1 ) && F_6 ( V_5 -> V_22 ) )
return NULL ;
F_66 (req, n, &dep->request_list, list) {
unsigned int V_104 = 0 ;
unsigned int V_105 ;
V_101 = & V_5 -> V_55 [ V_5 -> V_103 & V_20 ] ;
V_105 = V_5 -> V_103 ;
V_5 -> V_103 ++ ;
if ( ( ( V_105 & V_20 ) == V_21 - 1 ) &&
F_6 ( V_5 -> V_22 ) )
continue;
F_67 ( V_2 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_102 -- ;
if ( ! V_102 )
V_104 = 1 ;
if ( F_46 ( & V_5 -> V_85 ) )
V_104 = 1 ;
V_104 = 1 ;
V_2 -> V_53 = V_101 ;
if ( ! V_73 )
V_73 = V_2 ;
V_53 . V_80 = V_2 -> V_6 . V_8 ;
if ( F_6 ( V_5 -> V_22 ) ) {
V_53 . V_106 = true ;
V_53 . V_107 = true ;
} else {
V_53 . V_108 = V_104 ;
}
if ( F_36 ( V_5 -> V_22 ) && V_5 -> V_69 )
V_53 . V_109 = V_2 -> V_6 . V_110 ;
switch ( F_32 ( V_5 -> V_22 ) ) {
case V_92 :
V_53 . V_81 = V_111 ;
break;
case V_93 :
V_53 . V_81 = V_112 ;
if ( ! ( V_105 % ( V_21 / 4 ) ) )
V_53 . V_113 = V_104 ;
break;
case V_94 :
case V_95 :
V_53 . V_81 = V_114 ;
break;
default:
F_68 () ;
}
V_53 . V_7 = V_2 -> V_6 . V_7 ;
V_53 . V_83 = true ;
F_44 ( & V_53 , V_101 ) ;
V_2 -> V_115 = F_22 ( V_5 , V_101 ) ;
if ( V_104 )
break;
}
return V_73 ;
}
static int F_69 ( struct V_16 * V_5 , T_5 V_116 ,
int V_117 )
{
struct V_41 V_42 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = V_5 -> V_4 ;
int V_73 ;
T_2 V_30 ;
if ( V_117 && ( V_5 -> V_74 & V_118 ) ) {
F_13 ( V_4 -> V_10 , L_29 , V_5 -> V_25 ) ;
return - V_119 ;
}
V_5 -> V_74 &= ~ V_120 ;
if ( V_117 ) {
if ( F_46 ( & V_5 -> V_84 ) )
F_64 ( V_5 , V_117 ) ;
V_2 = F_48 ( & V_5 -> V_84 ) ;
} else {
V_2 = F_64 ( V_5 , V_117 ) ;
}
if ( ! V_2 ) {
V_5 -> V_74 |= V_120 ;
return 0 ;
}
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_46 = F_70 ( V_2 -> V_115 ) ;
V_42 . V_47 = F_71 ( V_2 -> V_115 ) ;
if ( V_117 )
V_30 = V_34 ;
else
V_30 = V_33 ;
V_30 |= F_29 ( V_116 ) ;
V_73 = F_12 ( V_4 , V_5 -> V_57 , V_30 , & V_42 ) ;
if ( V_73 < 0 ) {
F_8 ( V_4 -> V_10 , L_30 ) ;
F_3 ( V_2 ) ;
F_7 ( & V_2 -> V_23 ) ;
return V_73 ;
}
V_5 -> V_74 |= V_118 ;
V_5 -> V_121 = F_72 ( V_4 ,
V_5 -> V_57 ) ;
if ( ! V_5 -> V_121 )
F_73 ( V_122 L_31 , V_123 ) ;
return 0 ;
}
static int F_74 ( struct V_16 * V_5 , struct V_1 * V_2 )
{
V_2 -> V_6 . V_26 = 0 ;
V_2 -> V_6 . V_17 = - V_24 ;
V_2 -> V_12 = V_5 -> V_12 ;
V_2 -> V_98 = V_5 -> V_57 ;
F_1 ( V_2 ) ;
F_75 ( & V_2 -> V_23 , & V_5 -> V_85 ) ;
if ( V_5 -> V_74 & V_120 ) {
int V_73 ;
int V_124 ;
V_124 = 1 ;
if ( F_6 ( V_5 -> V_29 . V_22 ) &&
V_5 -> V_74 & V_118 )
V_124 = 0 ;
V_73 = F_69 ( V_5 , 0 , V_124 ) ;
if ( V_73 && V_73 != - V_119 ) {
struct V_3 * V_4 = V_5 -> V_4 ;
F_8 ( V_4 -> V_10 , L_32 ,
V_5 -> V_25 ) ;
}
} ;
return 0 ;
}
static int F_76 ( struct V_87 * V_40 , struct V_96 * V_6 ,
T_4 V_97 )
{
struct V_1 * V_2 = F_62 ( V_6 ) ;
struct V_16 * V_5 = F_54 ( V_40 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
unsigned long V_74 ;
int V_73 ;
if ( ! V_5 -> V_22 ) {
F_8 ( V_4 -> V_10 , L_33 ,
V_6 , V_40 -> V_25 ) ;
return - V_86 ;
}
F_13 ( V_4 -> V_10 , L_34 ,
V_6 , V_40 -> V_25 , V_6 -> V_7 ) ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
V_73 = F_74 ( V_5 , V_2 ) ;
F_57 ( & V_4 -> V_27 , V_74 ) ;
return V_73 ;
}
static int F_77 ( struct V_87 * V_40 ,
struct V_96 * V_6 )
{
struct V_1 * V_2 = F_62 ( V_6 ) ;
struct V_1 * V_125 = NULL ;
struct V_16 * V_5 = F_54 ( V_40 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
unsigned long V_74 ;
int V_73 = 0 ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
F_78 (r, &dep->request_list, list) {
if ( V_125 == V_2 )
break;
}
if ( V_125 != V_2 ) {
F_78 (r, &dep->req_queued, list) {
if ( V_125 == V_2 )
break;
}
if ( V_125 == V_2 ) {
F_47 ( V_4 , V_5 -> V_57 ) ;
goto V_126;
}
F_25 ( V_4 -> V_10 , L_35 ,
V_6 , V_40 -> V_25 ) ;
V_73 = - V_88 ;
goto V_126;
}
F_5 ( V_5 , V_2 , - V_127 ) ;
V_126:
F_57 ( & V_4 -> V_27 , V_74 ) ;
return V_73 ;
}
int F_79 ( struct V_16 * V_5 , int V_128 )
{
struct V_41 V_42 ;
struct V_3 * V_4 = V_5 -> V_4 ;
int V_73 ;
memset ( & V_42 , 0x00 , sizeof( V_42 ) ) ;
if ( V_128 ) {
if ( V_5 -> V_57 == 0 || V_5 -> V_57 == 1 ) {
V_4 -> V_129 = V_130 ;
}
V_73 = F_12 ( V_4 , V_5 -> V_57 ,
V_36 , & V_42 ) ;
if ( V_73 )
F_25 ( V_4 -> V_10 , L_36 ,
V_128 ? L_37 : L_38 ,
V_5 -> V_25 ) ;
else
V_5 -> V_74 |= V_131 ;
} else {
if ( V_5 -> V_74 & V_132 )
return 0 ;
V_73 = F_12 ( V_4 , V_5 -> V_57 ,
V_35 , & V_42 ) ;
if ( V_73 )
F_25 ( V_4 -> V_10 , L_36 ,
V_128 ? L_37 : L_38 ,
V_5 -> V_25 ) ;
else
V_5 -> V_74 &= ~ V_131 ;
}
return V_73 ;
}
static int F_80 ( struct V_87 * V_40 , int V_128 )
{
struct V_16 * V_5 = F_54 ( V_40 ) ;
struct V_3 * V_4 = V_5 -> V_4 ;
unsigned long V_74 ;
int V_73 ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
if ( F_6 ( V_5 -> V_22 ) ) {
F_25 ( V_4 -> V_10 , L_39 , V_5 -> V_25 ) ;
V_73 = - V_88 ;
goto V_133;
}
V_73 = F_79 ( V_5 , V_128 ) ;
V_133:
F_57 ( & V_4 -> V_27 , V_74 ) ;
return V_73 ;
}
static int F_81 ( struct V_87 * V_40 )
{
struct V_16 * V_5 = F_54 ( V_40 ) ;
V_5 -> V_74 |= V_132 ;
return F_80 ( V_40 , 1 ) ;
}
static int F_82 ( struct V_134 * V_135 )
{
struct V_3 * V_4 = F_83 ( V_135 ) ;
T_2 V_45 ;
V_45 = F_19 ( V_4 -> V_49 , V_136 ) ;
return F_84 ( V_45 ) ;
}
static int F_85 ( struct V_134 * V_135 )
{
struct V_3 * V_4 = F_83 ( V_135 ) ;
unsigned long V_44 ;
unsigned long V_74 ;
T_2 V_45 ;
int V_73 = 0 ;
T_1 V_137 ;
T_1 V_138 ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
V_45 = F_19 ( V_4 -> V_49 , V_136 ) ;
V_138 = V_45 & V_139 ;
if ( V_138 == V_140 ) {
F_8 ( V_4 -> V_10 , L_40 ) ;
V_73 = - V_88 ;
goto V_133;
}
V_137 = F_86 ( V_45 ) ;
switch ( V_137 ) {
case V_141 :
case V_142 :
break;
default:
F_8 ( V_4 -> V_10 , L_41 ,
V_137 ) ;
V_73 = - V_88 ;
goto V_133;
}
V_45 = F_19 ( V_4 -> V_49 , V_143 ) ;
V_45 |= V_144 ;
F_14 ( V_4 -> V_49 , V_143 , V_45 ) ;
F_87 ( 2000 , 2500 ) ;
V_45 &= ~ V_145 ;
F_14 ( V_4 -> V_49 , V_143 , V_45 ) ;
V_44 = V_146 + F_88 ( 100 ) ;
while ( ! ( F_89 ( V_146 , V_44 ) ) ) {
V_45 = F_19 ( V_4 -> V_49 , V_136 ) ;
if ( F_86 ( V_45 ) == V_147 )
break;
}
if ( F_86 ( V_45 ) != V_147 ) {
F_25 ( V_4 -> V_10 , L_42 ) ;
V_73 = - V_88 ;
}
V_133:
F_57 ( & V_4 -> V_27 , V_74 ) ;
return V_73 ;
}
static int F_90 ( struct V_134 * V_135 ,
int V_148 )
{
struct V_3 * V_4 = F_83 ( V_135 ) ;
V_4 -> V_148 = ! ! V_148 ;
return 0 ;
}
static void F_91 ( struct V_3 * V_4 , int V_149 )
{
T_2 V_45 ;
T_2 V_44 = 500 ;
V_45 = F_19 ( V_4 -> V_49 , V_143 ) ;
if ( V_149 )
V_45 |= V_150 ;
else
V_45 &= ~ V_150 ;
F_14 ( V_4 -> V_49 , V_143 , V_45 ) ;
do {
V_45 = F_19 ( V_4 -> V_49 , V_136 ) ;
if ( V_149 ) {
if ( ! ( V_45 & V_151 ) )
break;
} else {
if ( V_45 & V_151 )
break;
}
V_44 -- ;
if ( ! V_44 )
break;
F_21 ( 1 ) ;
} while ( 1 );
F_13 ( V_4 -> V_10 , L_43 ,
V_4 -> V_152
? V_4 -> V_152 -> V_153 : L_44 ,
V_149 ? L_45 : L_46 ) ;
}
static int F_92 ( struct V_134 * V_135 , int V_149 )
{
struct V_3 * V_4 = F_83 ( V_135 ) ;
unsigned long V_74 ;
V_149 = ! ! V_149 ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
F_91 ( V_4 , V_149 ) ;
F_57 ( & V_4 -> V_27 , V_74 ) ;
return 0 ;
}
static int F_93 ( struct V_134 * V_135 ,
struct V_154 * V_155 )
{
struct V_3 * V_4 = F_83 ( V_135 ) ;
struct V_16 * V_5 ;
unsigned long V_74 ;
int V_73 = 0 ;
T_2 V_45 ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
if ( V_4 -> V_152 ) {
F_25 ( V_4 -> V_10 , L_47 ,
V_4 -> V_156 . V_25 ,
V_4 -> V_152 -> V_155 . V_25 ) ;
V_73 = - V_119 ;
goto V_157;
}
V_4 -> V_152 = V_155 ;
V_4 -> V_156 . V_10 . V_155 = & V_155 -> V_155 ;
V_45 = F_19 ( V_4 -> V_49 , V_158 ) ;
V_45 &= ~ F_94 ( 3 ) ;
V_45 &= ~ F_95 ( V_159 ) ;
V_45 &= ~ V_160 ;
V_45 |= F_95 ( V_161 ) ;
switch ( F_96 ( V_4 -> V_162 . V_163 ) ) {
case V_164 :
V_45 &= ~ V_165 ;
break;
default:
F_8 ( V_4 -> V_10 , L_48 ) ;
}
if ( V_4 -> V_166 < V_167 )
V_45 |= V_168 ;
F_14 ( V_4 -> V_49 , V_158 , V_45 ) ;
V_45 = F_19 ( V_4 -> V_49 , V_169 ) ;
V_45 &= ~ ( V_170 ) ;
V_45 |= V_171 ;
F_14 ( V_4 -> V_49 , V_169 , V_45 ) ;
V_4 -> V_61 = false ;
V_172 . V_91 = F_97 ( 512 ) ;
V_5 = V_4 -> V_43 [ 0 ] ;
V_73 = F_42 ( V_5 , & V_172 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_49 , V_5 -> V_25 ) ;
goto V_157;
}
V_5 = V_4 -> V_43 [ 1 ] ;
V_73 = F_42 ( V_5 , & V_172 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_49 , V_5 -> V_25 ) ;
goto V_173;
}
V_4 -> V_129 = V_130 ;
F_98 ( V_4 ) ;
F_57 ( & V_4 -> V_27 , V_74 ) ;
return 0 ;
V_173:
F_49 ( V_4 -> V_43 [ 0 ] ) ;
V_157:
F_57 ( & V_4 -> V_27 , V_74 ) ;
return V_73 ;
}
static int F_99 ( struct V_134 * V_135 ,
struct V_154 * V_155 )
{
struct V_3 * V_4 = F_83 ( V_135 ) ;
unsigned long V_74 ;
F_56 ( & V_4 -> V_27 , V_74 ) ;
F_49 ( V_4 -> V_43 [ 0 ] ) ;
F_49 ( V_4 -> V_43 [ 1 ] ) ;
V_4 -> V_152 = NULL ;
V_4 -> V_156 . V_10 . V_155 = NULL ;
F_57 ( & V_4 -> V_27 , V_74 ) ;
return 0 ;
}
static int T_6 F_100 ( struct V_3 * V_4 )
{
struct V_16 * V_5 ;
T_1 V_98 ;
F_101 ( & V_4 -> V_156 . V_174 ) ;
for ( V_98 = 0 ; V_98 < V_175 ; V_98 ++ ) {
V_5 = F_60 ( sizeof( * V_5 ) , V_59 ) ;
if ( ! V_5 ) {
F_25 ( V_4 -> V_10 , L_50 ,
V_98 ) ;
return - V_60 ;
}
V_5 -> V_4 = V_4 ;
V_5 -> V_57 = V_98 ;
V_4 -> V_43 [ V_98 ] = V_5 ;
snprintf ( V_5 -> V_25 , sizeof( V_5 -> V_25 ) , L_25 , V_98 >> 1 ,
( V_98 & 1 ) ? L_26 : L_27 ) ;
V_5 -> V_29 . V_25 = V_5 -> V_25 ;
V_5 -> V_12 = ( V_98 & 1 ) ;
if ( V_98 == 0 || V_98 == 1 ) {
V_5 -> V_29 . V_176 = 512 ;
V_5 -> V_29 . V_177 = & V_178 ;
if ( ! V_98 )
V_4 -> V_156 . V_179 = & V_5 -> V_29 ;
} else {
int V_73 ;
V_5 -> V_29 . V_176 = 1024 ;
V_5 -> V_29 . V_66 = 15 ;
V_5 -> V_29 . V_177 = & V_180 ;
F_75 ( & V_5 -> V_29 . V_174 ,
& V_4 -> V_156 . V_174 ) ;
V_73 = F_23 ( V_5 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_51 , V_5 -> V_25 ) ;
return V_73 ;
}
}
F_101 ( & V_5 -> V_85 ) ;
F_101 ( & V_5 -> V_84 ) ;
}
return 0 ;
}
static void F_102 ( struct V_3 * V_4 )
{
struct V_16 * V_5 ;
T_1 V_98 ;
for ( V_98 = 0 ; V_98 < V_175 ; V_98 ++ ) {
V_5 = V_4 -> V_43 [ V_98 ] ;
F_26 ( V_5 ) ;
if ( V_98 != 0 && V_98 != 1 )
F_7 ( & V_5 -> V_29 . V_174 ) ;
F_63 ( V_5 ) ;
}
}
static void F_103 ( struct V_181 * V_10 )
{
F_8 ( V_10 , L_52 , V_123 ) ;
}
static int F_104 ( struct V_3 * V_4 , struct V_16 * V_5 ,
const struct V_182 * V_183 , int V_17 )
{
struct V_1 * V_2 ;
struct V_58 V_53 ;
unsigned int V_184 ;
unsigned int V_185 = 0 ;
do {
V_2 = F_48 ( & V_5 -> V_84 ) ;
if ( ! V_2 )
break;
F_105 ( V_2 -> V_53 , & V_53 ) ;
if ( V_53 . V_83 && V_17 != - V_86 )
F_25 ( V_4 -> V_10 , L_53 ,
V_5 -> V_25 , V_2 -> V_53 ) ;
V_184 = V_53 . V_7 ;
if ( V_5 -> V_12 ) {
if ( V_184 ) {
F_25 ( V_4 -> V_10 , L_54 ,
V_5 -> V_25 ) ;
V_17 = - V_127 ;
}
} else {
if ( V_184 && ( V_183 -> V_17 & V_186 ) )
V_185 = 1 ;
}
V_2 -> V_6 . V_26 += V_2 -> V_6 . V_7 - V_184 ;
F_5 ( V_5 , V_2 , V_17 ) ;
if ( V_185 )
break;
if ( ( V_183 -> V_17 & V_187 ) && V_53 . V_108 )
break;
if ( ( V_183 -> V_17 & V_188 ) && V_53 . V_113 )
break;
} while ( 1 );
if ( ( V_183 -> V_17 & V_188 ) && V_53 . V_113 )
return 0 ;
return 1 ;
}
static void F_106 ( struct V_3 * V_4 ,
struct V_16 * V_5 , const struct V_182 * V_183 ,
int V_117 )
{
unsigned V_17 = 0 ;
int V_189 ;
if ( V_183 -> V_17 & V_190 )
V_17 = - V_127 ;
V_189 = F_104 ( V_4 , V_5 , V_183 , V_17 ) ;
if ( V_189 ) {
V_5 -> V_74 &= ~ V_118 ;
V_5 -> V_121 = 0 ;
}
}
static void F_107 ( struct V_3 * V_4 ,
struct V_16 * V_5 , const struct V_182 * V_183 )
{
T_2 V_191 ;
if ( F_46 ( & V_5 -> V_85 ) ) {
F_13 ( V_4 -> V_10 , L_55 ,
V_5 -> V_25 ) ;
return;
}
if ( V_183 -> V_192 ) {
T_2 V_193 ;
V_193 = ~ ( V_5 -> V_72 - 1 ) ;
V_191 = V_183 -> V_192 & V_193 ;
V_191 += V_5 -> V_72 * 4 ;
} else {
V_191 = 0 ;
}
F_69 ( V_5 , V_191 , 1 ) ;
}
static void F_108 ( struct V_16 * V_5 ,
const struct V_182 * V_183 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
struct V_182 V_194 = * V_183 ;
V_194 . V_17 = V_187 ;
F_104 ( V_4 , V_5 , & V_194 , - V_86 ) ;
V_5 -> V_74 &= ~ V_118 ;
}
static void F_109 ( struct V_16 * V_5 ,
const struct V_182 * V_183 )
{
T_2 V_195 = V_183 -> V_192 ;
T_2 V_196 = ( V_195 >> 8 ) & ( ( 1 << 5 ) - 1 ) ;
switch ( V_196 ) {
case V_32 :
F_108 ( V_5 , V_183 ) ;
break;
case V_34 :
V_5 -> V_121 = V_195 & 0x7f ;
break;
default:
F_110 ( V_122 L_56 ,
V_123 , V_196 ) ;
break;
} ;
}
static void F_111 ( struct V_3 * V_4 ,
const struct V_182 * V_183 )
{
struct V_16 * V_5 ;
T_1 V_98 = V_183 -> V_197 ;
V_5 = V_4 -> V_43 [ V_98 ] ;
F_13 ( V_4 -> V_10 , L_57 , V_5 -> V_25 ,
F_112 ( V_183 -> V_198 ) ) ;
if ( V_98 == 0 || V_98 == 1 ) {
F_113 ( V_4 , V_183 ) ;
return;
}
switch ( V_183 -> V_198 ) {
case V_199 :
if ( F_6 ( V_5 -> V_22 ) ) {
F_8 ( V_4 -> V_10 , L_58 ,
V_5 -> V_25 ) ;
return;
}
F_106 ( V_4 , V_5 , V_183 , 1 ) ;
break;
case V_200 :
if ( ! F_6 ( V_5 -> V_22 ) ) {
F_8 ( V_4 -> V_10 , L_59 ,
V_5 -> V_25 ) ;
return;
}
F_106 ( V_4 , V_5 , V_183 , 0 ) ;
break;
case V_201 :
if ( F_6 ( V_5 -> V_22 ) ) {
F_107 ( V_4 , V_5 , V_183 ) ;
} else {
int V_73 ;
F_13 ( V_4 -> V_10 , L_60 ,
V_5 -> V_25 , V_183 -> V_17
? L_61
: L_62 ) ;
V_73 = F_69 ( V_5 , 0 , 1 ) ;
if ( ! V_73 || V_73 == - V_119 )
return;
F_8 ( V_4 -> V_10 , L_32 ,
V_5 -> V_25 ) ;
}
break;
case V_202 :
if ( ! F_36 ( V_5 -> V_22 ) ) {
F_25 ( V_4 -> V_10 , L_63 ,
V_5 -> V_25 ) ;
return;
}
switch ( V_183 -> V_17 ) {
case V_203 :
F_13 ( V_4 -> V_10 , L_64 ,
V_183 -> V_192 ) ;
break;
case V_204 :
default:
F_8 ( V_4 -> V_10 , L_65 ) ;
}
break;
case V_205 :
F_8 ( V_4 -> V_10 , L_66 , V_5 -> V_25 ) ;
break;
case V_206 :
F_109 ( V_5 , V_183 ) ;
break;
}
}
static void F_114 ( struct V_3 * V_4 )
{
if ( V_4 -> V_152 && V_4 -> V_152 -> V_207 ) {
F_9 ( & V_4 -> V_27 ) ;
V_4 -> V_152 -> V_207 ( & V_4 -> V_156 ) ;
F_10 ( & V_4 -> V_27 ) ;
}
}
static void F_47 ( struct V_3 * V_4 , T_2 V_98 )
{
struct V_16 * V_5 ;
struct V_41 V_42 ;
T_2 V_30 ;
int V_73 ;
V_5 = V_4 -> V_43 [ V_98 ] ;
F_115 ( ! V_5 -> V_121 ) ;
if ( V_5 -> V_121 ) {
V_30 = V_32 ;
V_30 |= V_208 | V_209 ;
V_30 |= F_29 ( V_5 -> V_121 ) ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_73 = F_12 ( V_4 , V_5 -> V_57 , V_30 , & V_42 ) ;
F_116 ( V_73 ) ;
V_5 -> V_121 = 0 ;
}
}
static void F_117 ( struct V_3 * V_4 )
{
T_2 V_98 ;
for ( V_98 = 2 ; V_98 < V_175 ; V_98 ++ ) {
struct V_16 * V_5 ;
V_5 = V_4 -> V_43 [ V_98 ] ;
if ( ! ( V_5 -> V_74 & V_75 ) )
continue;
F_45 ( V_4 , V_5 ) ;
}
}
static void F_118 ( struct V_3 * V_4 )
{
T_2 V_98 ;
for ( V_98 = 1 ; V_98 < V_175 ; V_98 ++ ) {
struct V_16 * V_5 ;
struct V_41 V_42 ;
int V_73 ;
V_5 = V_4 -> V_43 [ V_98 ] ;
if ( ! ( V_5 -> V_74 & V_131 ) )
continue;
V_5 -> V_74 &= ~ V_131 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_73 = F_12 ( V_4 , V_5 -> V_57 ,
V_35 , & V_42 ) ;
F_116 ( V_73 ) ;
}
}
static void F_119 ( struct V_3 * V_4 )
{
F_13 ( V_4 -> V_10 , L_52 , V_123 ) ;
#if 0
XXX
U1/U2 is powersave optimization. Skip it for now. Anyway we need to
enable it before we can disable it.
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= ~DWC3_DCTL_INITU1ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
reg &= ~DWC3_DCTL_INITU2ENA;
dwc3_writel(dwc->regs, DWC3_DCTL, reg);
#endif
F_117 ( V_4 ) ;
F_114 ( V_4 ) ;
V_4 -> V_61 = false ;
V_4 -> V_156 . V_138 = V_210 ;
}
static void F_120 ( struct V_3 * V_4 , int V_211 )
{
T_2 V_45 ;
V_45 = F_19 ( V_4 -> V_49 , F_121 ( 0 ) ) ;
if ( V_211 )
V_45 &= ~ V_212 ;
else
V_45 |= V_212 ;
F_14 ( V_4 -> V_49 , F_121 ( 0 ) , V_45 ) ;
}
static void F_122 ( struct V_3 * V_4 , int V_211 )
{
T_2 V_45 ;
V_45 = F_19 ( V_4 -> V_49 , F_123 ( 0 ) ) ;
if ( V_211 )
V_45 &= ~ V_213 ;
else
V_45 |= V_213 ;
F_14 ( V_4 -> V_49 , F_123 ( 0 ) , V_45 ) ;
}
static void F_124 ( struct V_3 * V_4 )
{
T_2 V_45 ;
F_13 ( V_4 -> V_10 , L_52 , V_123 ) ;
F_122 ( V_4 , true ) ;
F_120 ( V_4 , true ) ;
if ( V_4 -> V_156 . V_138 != V_210 )
F_114 ( V_4 ) ;
V_45 = F_19 ( V_4 -> V_49 , V_143 ) ;
V_45 &= ~ V_214 ;
F_14 ( V_4 -> V_49 , V_143 , V_45 ) ;
F_117 ( V_4 ) ;
F_118 ( V_4 ) ;
V_4 -> V_61 = false ;
V_45 = F_19 ( V_4 -> V_49 , V_169 ) ;
V_45 &= ~ ( V_215 ) ;
F_14 ( V_4 -> V_49 , V_169 , V_45 ) ;
}
static void F_125 ( struct V_3 * V_4 , T_2 V_138 )
{
T_2 V_45 ;
T_2 V_216 = V_217 ;
if ( V_138 != V_140 )
return;
if ( ! V_216 )
return;
V_45 = F_19 ( V_4 -> V_49 , V_158 ) ;
V_45 |= F_126 ( V_216 ) ;
F_14 ( V_4 -> V_49 , V_158 , V_45 ) ;
}
static void F_127 ( struct V_3 * V_4 , T_1 V_138 )
{
switch ( V_138 ) {
case V_218 :
F_122 ( V_4 , false ) ;
break;
case V_219 :
case V_220 :
case V_221 :
F_120 ( V_4 , false ) ;
break;
}
}
static void F_128 ( struct V_3 * V_4 )
{
struct V_41 V_42 ;
struct V_16 * V_5 ;
int V_73 ;
T_2 V_45 ;
T_1 V_138 ;
F_13 ( V_4 -> V_10 , L_52 , V_123 ) ;
memset ( & V_42 , 0x00 , sizeof( V_42 ) ) ;
V_45 = F_19 ( V_4 -> V_49 , V_136 ) ;
V_138 = V_45 & V_139 ;
V_4 -> V_138 = V_138 ;
F_125 ( V_4 , V_138 ) ;
switch ( V_138 ) {
case V_171 :
V_172 . V_91 = F_97 ( 512 ) ;
V_4 -> V_156 . V_179 -> V_176 = 512 ;
V_4 -> V_156 . V_138 = V_218 ;
break;
case V_222 :
V_172 . V_91 = F_97 ( 64 ) ;
V_4 -> V_156 . V_179 -> V_176 = 64 ;
V_4 -> V_156 . V_138 = V_219 ;
break;
case V_223 :
case V_224 :
V_172 . V_91 = F_97 ( 64 ) ;
V_4 -> V_156 . V_179 -> V_176 = 64 ;
V_4 -> V_156 . V_138 = V_220 ;
break;
case V_225 :
V_172 . V_91 = F_97 ( 8 ) ;
V_4 -> V_156 . V_179 -> V_176 = 8 ;
V_4 -> V_156 . V_138 = V_221 ;
break;
}
F_127 ( V_4 , V_4 -> V_156 . V_138 ) ;
V_5 = V_4 -> V_43 [ 0 ] ;
V_73 = F_42 ( V_5 , & V_172 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_49 , V_5 -> V_25 ) ;
return;
}
V_5 = V_4 -> V_43 [ 1 ] ;
V_73 = F_42 ( V_5 , & V_172 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_49 , V_5 -> V_25 ) ;
return;
}
}
static void F_129 ( struct V_3 * V_4 )
{
F_13 ( V_4 -> V_10 , L_52 , V_123 ) ;
V_4 -> V_152 -> V_226 ( & V_4 -> V_156 ) ;
}
static void F_130 ( struct V_3 * V_4 ,
unsigned int V_227 )
{
V_4 -> V_137 = V_227 & V_228 ;
F_13 ( V_4 -> V_10 , L_67 , V_123 , V_4 -> V_137 ) ;
}
static void F_131 ( struct V_3 * V_4 ,
const struct V_229 * V_183 )
{
switch ( V_183 -> type ) {
case V_230 :
F_119 ( V_4 ) ;
break;
case V_231 :
F_124 ( V_4 ) ;
break;
case V_232 :
F_128 ( V_4 ) ;
break;
case V_233 :
F_129 ( V_4 ) ;
break;
case V_234 :
F_130 ( V_4 , V_183 -> V_235 ) ;
break;
case V_236 :
F_13 ( V_4 -> V_10 , L_68 ) ;
break;
case V_237 :
F_13 ( V_4 -> V_10 , L_69 ) ;
break;
case V_238 :
F_13 ( V_4 -> V_10 , L_70 ) ;
break;
case V_239 :
F_13 ( V_4 -> V_10 , L_71 ) ;
break;
case V_240 :
F_13 ( V_4 -> V_10 , L_72 ) ;
break;
default:
F_8 ( V_4 -> V_10 , L_73 , V_183 -> type ) ;
}
}
static void F_132 ( struct V_3 * V_4 ,
const union V_241 * V_183 )
{
if ( V_183 -> type . V_242 == 0 ) {
return F_111 ( V_4 , & V_183 -> V_243 ) ;
}
switch ( V_183 -> type . type ) {
case V_244 :
F_131 ( V_4 , & V_183 -> V_245 ) ;
break;
default:
F_25 ( V_4 -> V_10 , L_74 , V_183 -> V_246 ) ;
}
}
static T_7 F_133 ( struct V_3 * V_4 , T_2 V_11 )
{
struct V_247 * V_248 ;
int V_249 ;
T_2 V_184 ;
V_184 = F_19 ( V_4 -> V_49 , F_134 ( V_11 ) ) ;
V_184 &= V_250 ;
if ( ! V_184 )
return V_251 ;
V_248 = V_4 -> V_252 [ V_11 ] ;
V_249 = V_184 ;
while ( V_249 > 0 ) {
union V_241 V_183 ;
memcpy ( & V_183 . V_246 , ( V_248 -> V_11 + V_248 -> V_253 ) , sizeof( V_183 . V_246 ) ) ;
F_132 ( V_4 , & V_183 ) ;
V_248 -> V_253 = ( V_248 -> V_253 + 4 ) % V_254 ;
V_249 -= 4 ;
F_14 ( V_4 -> V_49 , F_134 ( V_11 ) , 4 ) ;
}
return V_255 ;
}
static T_7 F_135 ( int V_256 , void * V_257 )
{
struct V_3 * V_4 = V_257 ;
int V_258 ;
T_7 V_73 = V_251 ;
F_10 ( & V_4 -> V_27 ) ;
for ( V_258 = 0 ; V_258 < V_259 ; V_258 ++ ) {
T_7 V_17 ;
V_17 = F_133 ( V_4 , V_258 ) ;
if ( V_17 == V_255 )
V_73 = V_17 ;
}
F_9 ( & V_4 -> V_27 ) ;
return V_73 ;
}
int T_6 F_136 ( struct V_3 * V_4 )
{
T_2 V_45 ;
int V_73 ;
int V_256 ;
V_4 -> V_260 = F_24 ( V_4 -> V_10 , sizeof( * V_4 -> V_260 ) ,
& V_4 -> V_261 , V_59 ) ;
if ( ! V_4 -> V_260 ) {
F_25 ( V_4 -> V_10 , L_75 ) ;
V_73 = - V_60 ;
goto V_157;
}
V_4 -> V_262 = F_24 ( V_4 -> V_10 , sizeof( * V_4 -> V_262 ) ,
& V_4 -> V_263 , V_59 ) ;
if ( ! V_4 -> V_262 ) {
F_25 ( V_4 -> V_10 , L_76 ) ;
V_73 = - V_60 ;
goto V_173;
}
V_4 -> V_264 = F_24 ( V_4 -> V_10 ,
sizeof( * V_4 -> V_264 ) * 2 ,
& V_4 -> V_265 , V_59 ) ;
if ( ! V_4 -> V_264 ) {
F_25 ( V_4 -> V_10 , L_77 ) ;
V_73 = - V_60 ;
goto V_266;
}
V_4 -> V_267 = F_24 ( V_4 -> V_10 ,
512 , & V_4 -> V_268 , V_59 ) ;
if ( ! V_4 -> V_267 ) {
F_25 ( V_4 -> V_10 , L_78 ) ;
V_73 = - V_60 ;
goto V_269;
}
F_137 ( & V_4 -> V_156 . V_10 , L_79 ) ;
V_4 -> V_156 . V_177 = & V_270 ;
V_4 -> V_156 . V_271 = true ;
V_4 -> V_156 . V_138 = V_210 ;
V_4 -> V_156 . V_10 . V_272 = V_4 -> V_10 ;
F_138 ( & V_4 -> V_156 . V_10 , V_4 -> V_10 -> V_273 ) ;
V_4 -> V_156 . V_10 . V_274 = V_4 -> V_10 -> V_274 ;
V_4 -> V_156 . V_10 . V_275 = V_4 -> V_10 -> V_275 ;
V_4 -> V_156 . V_10 . V_276 = F_103 ;
V_4 -> V_156 . V_25 = L_80 ;
V_73 = F_100 ( V_4 ) ;
if ( V_73 )
goto V_277;
V_256 = F_139 ( F_140 ( V_4 -> V_10 ) , 0 ) ;
V_73 = F_141 ( V_256 , F_135 , V_278 ,
L_81 , V_4 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_82 ,
V_256 , V_73 ) ;
goto V_279;
}
V_45 = ( V_280 |
V_281 |
V_282 |
V_283 |
V_284 |
V_285 |
V_286 |
V_287 |
V_288 ) ;
F_14 ( V_4 -> V_49 , V_289 , V_45 ) ;
V_73 = F_142 ( & V_4 -> V_156 . V_10 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_83 ) ;
F_143 ( & V_4 -> V_156 . V_10 ) ;
goto V_290;
}
V_73 = F_144 ( V_4 -> V_10 , & V_4 -> V_156 ) ;
if ( V_73 ) {
F_25 ( V_4 -> V_10 , L_84 ) ;
goto V_291;
}
return 0 ;
V_291:
F_145 ( & V_4 -> V_156 . V_10 ) ;
V_290:
F_14 ( V_4 -> V_49 , V_289 , 0x00 ) ;
F_146 ( V_256 , V_4 ) ;
V_279:
F_102 ( V_4 ) ;
V_277:
F_27 ( V_4 -> V_10 , 512 , V_4 -> V_267 ,
V_4 -> V_268 ) ;
V_269:
F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_264 ) * 2 ,
V_4 -> V_264 , V_4 -> V_265 ) ;
V_266:
F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_262 ) ,
V_4 -> V_262 , V_4 -> V_263 ) ;
V_173:
F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_260 ) ,
V_4 -> V_260 , V_4 -> V_261 ) ;
V_157:
return V_73 ;
}
void F_147 ( struct V_3 * V_4 )
{
int V_256 ;
int V_258 ;
F_148 ( & V_4 -> V_156 ) ;
V_256 = F_139 ( F_140 ( V_4 -> V_10 ) , 0 ) ;
F_14 ( V_4 -> V_49 , V_289 , 0x00 ) ;
F_146 ( V_256 , V_4 ) ;
for ( V_258 = 0 ; V_258 < F_149 ( V_4 -> V_43 ) ; V_258 ++ )
F_49 ( V_4 -> V_43 [ V_258 ] ) ;
F_102 ( V_4 ) ;
F_27 ( V_4 -> V_10 , 512 , V_4 -> V_267 ,
V_4 -> V_268 ) ;
F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_264 ) * 2 ,
V_4 -> V_264 , V_4 -> V_265 ) ;
F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_262 ) ,
V_4 -> V_262 , V_4 -> V_263 ) ;
F_27 ( V_4 -> V_10 , sizeof( * V_4 -> V_260 ) ,
V_4 -> V_260 , V_4 -> V_261 ) ;
F_145 ( & V_4 -> V_156 . V_10 ) ;
}
