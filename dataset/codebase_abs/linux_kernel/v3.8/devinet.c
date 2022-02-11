static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
T_1 V_3 = ( V_4 T_1 ) V_2 ^ F_2 ( V_1 ) ;
return F_3 ( V_3 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
T_1 V_8 = F_1 ( V_1 , V_7 -> V_9 ) ;
F_5 ( & V_10 ) ;
F_6 ( & V_7 -> V_8 , & V_11 [ V_8 ] ) ;
F_7 ( & V_10 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_5 ( & V_10 ) ;
F_9 ( & V_7 -> V_8 ) ;
F_7 ( & V_10 ) ;
}
struct V_12 * F_10 ( struct V_1 * V_1 , T_2 V_2 , bool V_13 )
{
T_1 V_8 = F_1 ( V_1 , V_2 ) ;
struct V_12 * V_14 = NULL ;
struct V_6 * V_7 ;
struct V_15 * V_16 ;
F_11 () ;
F_12 (ifa, node, &inet_addr_lst[hash], hash) {
if ( V_7 -> V_9 == V_2 ) {
struct V_12 * V_17 = V_7 -> V_18 -> V_17 ;
if ( ! F_13 ( F_14 ( V_17 ) , V_1 ) )
continue;
V_14 = V_17 ;
break;
}
}
if ( ! V_14 ) {
struct V_19 V_20 = { . V_21 = V_2 } ;
struct V_22 V_23 = { 0 } ;
struct V_24 * V_25 ;
V_25 = F_15 ( V_1 , V_26 ) ;
if ( V_25 &&
! F_16 ( V_25 , & V_20 , & V_23 , V_27 ) &&
V_23 . type == V_28 )
V_14 = F_17 ( V_23 ) ;
}
if ( V_14 && V_13 )
F_18 ( V_14 ) ;
F_19 () ;
return V_14 ;
}
static void F_20 ( struct V_29 * V_30 )
{
}
static void F_21 ( struct V_29 * V_30 )
{
}
static struct V_6 * F_22 ( void )
{
return F_23 ( sizeof( struct V_6 ) , V_31 ) ;
}
static void F_24 ( struct V_32 * V_33 )
{
struct V_6 * V_7 = F_25 ( V_33 , struct V_6 , V_32 ) ;
if ( V_7 -> V_18 )
F_26 ( V_7 -> V_18 ) ;
F_27 ( V_7 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
F_29 ( & V_7 -> V_32 , F_24 ) ;
}
void F_30 ( struct V_29 * V_30 )
{
struct V_12 * V_17 = V_30 -> V_17 ;
F_31 ( V_30 -> V_34 ) ;
F_31 ( V_30 -> V_35 ) ;
#ifdef F_32
F_33 ( L_1 , V_36 , V_30 , V_17 ? V_17 -> V_37 : L_2 ) ;
#endif
F_34 ( V_17 ) ;
if ( ! V_30 -> V_38 )
F_35 ( L_3 , V_30 ) ;
else
F_27 ( V_30 ) ;
}
static struct V_29 * F_36 ( struct V_12 * V_17 )
{
struct V_29 * V_39 ;
F_37 () ;
V_39 = F_23 ( sizeof( * V_39 ) , V_31 ) ;
if ( ! V_39 )
goto V_40;
memcpy ( & V_39 -> V_41 , F_14 ( V_17 ) -> V_42 . V_43 ,
sizeof( V_39 -> V_41 ) ) ;
V_39 -> V_41 . V_44 = NULL ;
V_39 -> V_17 = V_17 ;
V_39 -> V_45 = F_38 ( V_17 , & V_46 ) ;
if ( ! V_39 -> V_45 )
goto V_47;
if ( F_39 ( V_39 -> V_41 , V_48 ) )
F_40 ( V_17 ) ;
F_18 ( V_17 ) ;
F_41 ( V_39 ) ;
F_20 ( V_39 ) ;
F_42 ( V_39 ) ;
if ( V_17 -> V_49 & V_50 )
F_43 ( V_39 ) ;
F_44 ( V_17 -> V_51 , V_39 ) ;
V_40:
return V_39 ;
V_47:
F_27 ( V_39 ) ;
V_39 = NULL ;
goto V_40;
}
static void F_45 ( struct V_32 * V_33 )
{
struct V_29 * V_30 = F_25 ( V_33 , struct V_29 , V_32 ) ;
F_26 ( V_30 ) ;
}
static void F_46 ( struct V_29 * V_39 )
{
struct V_6 * V_7 ;
struct V_12 * V_17 ;
F_37 () ;
V_17 = V_39 -> V_17 ;
V_39 -> V_38 = 1 ;
F_47 ( V_39 ) ;
while ( ( V_7 = V_39 -> V_34 ) != NULL ) {
F_48 ( V_39 , & V_39 -> V_34 , 0 ) ;
F_28 ( V_7 ) ;
}
F_49 ( V_17 -> V_51 , NULL ) ;
F_21 ( V_39 ) ;
F_50 ( & V_46 , V_39 -> V_45 ) ;
F_51 ( V_17 ) ;
F_29 ( & V_39 -> V_32 , F_45 ) ;
}
int F_52 ( struct V_29 * V_39 , T_2 V_52 , T_2 V_53 )
{
F_11 () ;
F_53 (in_dev) {
if ( F_54 ( V_52 , V_7 ) ) {
if ( ! V_53 || F_54 ( V_53 , V_7 ) ) {
F_19 () ;
return 1 ;
}
}
} F_55 ( V_39 ) ;
F_19 () ;
return 0 ;
}
static void F_56 ( struct V_29 * V_39 , struct V_6 * * V_54 ,
int V_55 , struct V_56 * V_57 , T_1 V_58 )
{
struct V_6 * V_59 = NULL ;
struct V_6 * V_7 , * V_60 = * V_54 ;
struct V_6 * V_61 = V_39 -> V_34 ;
struct V_6 * V_62 = NULL ;
int V_63 = F_57 ( V_39 ) ;
F_37 () ;
if ( ! ( V_60 -> V_64 & V_65 ) ) {
struct V_6 * * V_66 = & V_60 -> V_67 ;
while ( ( V_7 = * V_66 ) != NULL ) {
if ( ! ( V_7 -> V_64 & V_65 ) &&
V_60 -> V_68 <= V_7 -> V_68 )
V_61 = V_7 ;
if ( ! ( V_7 -> V_64 & V_65 ) ||
V_60 -> V_69 != V_7 -> V_69 ||
! F_54 ( V_60 -> V_70 , V_7 ) ) {
V_66 = & V_7 -> V_67 ;
V_62 = V_7 ;
continue;
}
if ( ! V_63 ) {
F_8 ( V_7 ) ;
* V_66 = V_7 -> V_67 ;
F_58 ( V_71 , V_7 , V_57 , V_58 ) ;
F_59 ( & V_72 ,
V_73 , V_7 ) ;
F_28 ( V_7 ) ;
} else {
V_59 = V_7 ;
break;
}
}
}
for ( V_7 = V_59 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( V_60 -> V_69 == V_7 -> V_69 &&
F_54 ( V_60 -> V_70 , V_7 ) )
F_60 ( V_7 , V_60 ) ;
}
* V_54 = V_60 -> V_67 ;
F_8 ( V_60 ) ;
F_58 ( V_71 , V_60 , V_57 , V_58 ) ;
F_59 ( & V_72 , V_73 , V_60 ) ;
if ( V_59 ) {
struct V_6 * V_74 = V_59 -> V_67 ;
if ( V_62 ) {
V_62 -> V_67 = V_59 -> V_67 ;
V_59 -> V_67 = V_61 -> V_67 ;
V_61 -> V_67 = V_59 ;
}
V_59 -> V_64 &= ~ V_65 ;
F_58 ( V_75 , V_59 , V_57 , V_58 ) ;
F_59 ( & V_72 ,
V_76 , V_59 ) ;
for ( V_7 = V_74 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( V_60 -> V_69 != V_7 -> V_69 ||
! F_54 ( V_60 -> V_70 , V_7 ) )
continue;
F_61 ( V_7 ) ;
}
}
if ( V_55 )
F_28 ( V_60 ) ;
}
static void F_48 ( struct V_29 * V_39 , struct V_6 * * V_54 ,
int V_55 )
{
F_56 ( V_39 , V_54 , V_55 , NULL , 0 ) ;
}
static int F_62 ( struct V_6 * V_7 , struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_29 * V_39 = V_7 -> V_18 ;
struct V_6 * V_60 , * * V_54 , * * V_77 ;
F_37 () ;
if ( ! V_7 -> V_9 ) {
F_28 ( V_7 ) ;
return 0 ;
}
V_7 -> V_64 &= ~ V_65 ;
V_77 = & V_39 -> V_34 ;
for ( V_54 = & V_39 -> V_34 ; ( V_60 = * V_54 ) != NULL ;
V_54 = & V_60 -> V_67 ) {
if ( ! ( V_60 -> V_64 & V_65 ) &&
V_7 -> V_68 <= V_60 -> V_68 )
V_77 = & V_60 -> V_67 ;
if ( V_60 -> V_69 == V_7 -> V_69 &&
F_54 ( V_60 -> V_70 , V_7 ) ) {
if ( V_60 -> V_9 == V_7 -> V_9 ) {
F_28 ( V_7 ) ;
return - V_78 ;
}
if ( V_60 -> V_68 != V_7 -> V_68 ) {
F_28 ( V_7 ) ;
return - V_79 ;
}
V_7 -> V_64 |= V_65 ;
}
}
if ( ! ( V_7 -> V_64 & V_65 ) ) {
F_63 ( V_7 -> V_9 ) ;
V_54 = V_77 ;
}
V_7 -> V_67 = * V_54 ;
* V_54 = V_7 ;
F_4 ( F_14 ( V_39 -> V_17 ) , V_7 ) ;
F_58 ( V_75 , V_7 , V_57 , V_58 ) ;
F_59 ( & V_72 , V_76 , V_7 ) ;
return 0 ;
}
static int F_64 ( struct V_6 * V_7 )
{
return F_62 ( V_7 , NULL , 0 ) ;
}
static int F_65 ( struct V_12 * V_17 , struct V_6 * V_7 )
{
struct V_29 * V_39 = F_66 ( V_17 ) ;
F_37 () ;
if ( ! V_39 ) {
F_28 ( V_7 ) ;
return - V_80 ;
}
F_67 ( V_39 ) ;
if ( V_7 -> V_18 != V_39 ) {
F_31 ( V_7 -> V_18 ) ;
F_41 ( V_39 ) ;
V_7 -> V_18 = V_39 ;
}
if ( F_68 ( V_7 -> V_9 ) )
V_7 -> V_68 = V_81 ;
return F_64 ( V_7 ) ;
}
struct V_29 * F_69 ( struct V_1 * V_1 , int V_82 )
{
struct V_12 * V_17 ;
struct V_29 * V_39 = NULL ;
F_11 () ;
V_17 = F_70 ( V_1 , V_82 ) ;
if ( V_17 )
V_39 = F_71 ( V_17 -> V_51 ) ;
F_19 () ;
return V_39 ;
}
struct V_6 * F_72 ( struct V_29 * V_39 , T_2 V_83 ,
T_2 V_84 )
{
F_37 () ;
F_53 (in_dev) {
if ( V_7 -> V_69 == V_84 && F_54 ( V_83 , V_7 ) )
return V_7 ;
} F_55 ( V_39 ) ;
return NULL ;
}
static int F_73 ( struct V_85 * V_86 , struct V_56 * V_57 , void * V_87 )
{
struct V_1 * V_1 = F_74 ( V_86 -> V_88 ) ;
struct V_89 * V_90 [ V_91 + 1 ] ;
struct V_29 * V_39 ;
struct V_92 * V_93 ;
struct V_6 * V_7 , * * V_54 ;
int V_94 = - V_79 ;
F_37 () ;
V_94 = F_75 ( V_57 , sizeof( * V_93 ) , V_90 , V_91 , V_95 ) ;
if ( V_94 < 0 )
goto V_96;
V_93 = F_76 ( V_57 ) ;
V_39 = F_69 ( V_1 , V_93 -> V_97 ) ;
if ( V_39 == NULL ) {
V_94 = - V_98 ;
goto V_96;
}
for ( V_54 = & V_39 -> V_34 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( V_90 [ V_99 ] &&
V_7 -> V_9 != F_77 ( V_90 [ V_99 ] ) )
continue;
if ( V_90 [ V_100 ] && F_78 ( V_90 [ V_100 ] , V_7 -> V_101 ) )
continue;
if ( V_90 [ V_102 ] &&
( V_93 -> V_103 != V_7 -> V_103 ||
! F_54 ( F_77 ( V_90 [ V_102 ] ) , V_7 ) ) )
continue;
F_56 ( V_39 , V_54 , 1 , V_57 , F_79 ( V_86 ) . V_58 ) ;
return 0 ;
}
V_94 = - V_104 ;
V_96:
return V_94 ;
}
static struct V_6 * F_80 ( struct V_1 * V_1 , struct V_56 * V_57 )
{
struct V_89 * V_90 [ V_91 + 1 ] ;
struct V_6 * V_7 ;
struct V_92 * V_93 ;
struct V_12 * V_17 ;
struct V_29 * V_39 ;
int V_94 ;
V_94 = F_75 ( V_57 , sizeof( * V_93 ) , V_90 , V_91 , V_95 ) ;
if ( V_94 < 0 )
goto V_96;
V_93 = F_76 ( V_57 ) ;
V_94 = - V_79 ;
if ( V_93 -> V_103 > 32 || V_90 [ V_99 ] == NULL )
goto V_96;
V_17 = F_81 ( V_1 , V_93 -> V_97 ) ;
V_94 = - V_98 ;
if ( V_17 == NULL )
goto V_96;
V_39 = F_66 ( V_17 ) ;
V_94 = - V_80 ;
if ( V_39 == NULL )
goto V_96;
V_7 = F_22 () ;
if ( V_7 == NULL )
goto V_96;
F_67 ( V_39 ) ;
F_41 ( V_39 ) ;
if ( V_90 [ V_102 ] == NULL )
V_90 [ V_102 ] = V_90 [ V_99 ] ;
F_82 ( & V_7 -> V_8 ) ;
V_7 -> V_103 = V_93 -> V_103 ;
V_7 -> V_69 = F_83 ( V_93 -> V_103 ) ;
V_7 -> V_64 = V_93 -> V_64 ;
V_7 -> V_68 = V_93 -> V_68 ;
V_7 -> V_18 = V_39 ;
V_7 -> V_9 = F_77 ( V_90 [ V_99 ] ) ;
V_7 -> V_70 = F_77 ( V_90 [ V_102 ] ) ;
if ( V_90 [ V_105 ] )
V_7 -> V_106 = F_77 ( V_90 [ V_105 ] ) ;
if ( V_90 [ V_100 ] )
F_84 ( V_7 -> V_101 , V_90 [ V_100 ] , V_107 ) ;
else
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
return V_7 ;
V_96:
return F_85 ( V_94 ) ;
}
static int F_86 ( struct V_85 * V_86 , struct V_56 * V_57 , void * V_87 )
{
struct V_1 * V_1 = F_74 ( V_86 -> V_88 ) ;
struct V_6 * V_7 ;
F_37 () ;
V_7 = F_80 ( V_1 , V_57 ) ;
if ( F_87 ( V_7 ) )
return F_88 ( V_7 ) ;
return F_62 ( V_7 , V_57 , F_79 ( V_86 ) . V_58 ) ;
}
static int F_89 ( T_2 V_2 )
{
int V_108 = - 1 ;
if ( F_90 ( V_2 ) )
V_108 = 0 ;
else {
T_3 V_109 = F_91 ( V_2 ) ;
if ( F_92 ( V_109 ) )
V_108 = 8 ;
else if ( F_93 ( V_109 ) )
V_108 = 16 ;
else if ( F_94 ( V_109 ) )
V_108 = 24 ;
}
return V_108 ;
}
int F_95 ( struct V_1 * V_1 , unsigned int V_110 , void T_4 * V_87 )
{
struct V_111 V_112 ;
struct V_113 V_114 ;
struct V_113 * sin = (struct V_113 * ) & V_112 . V_115 ;
struct V_29 * V_39 ;
struct V_6 * * V_54 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_12 * V_17 ;
char * V_116 ;
int V_117 = - V_118 ;
int V_119 = 0 ;
if ( F_96 ( & V_112 , V_87 , sizeof( struct V_111 ) ) )
goto V_40;
V_112 . V_120 [ V_107 - 1 ] = 0 ;
memcpy ( & V_114 , sin , sizeof( * sin ) ) ;
V_116 = strchr ( V_112 . V_120 , ':' ) ;
if ( V_116 )
* V_116 = 0 ;
F_97 ( V_1 , V_112 . V_120 ) ;
switch ( V_110 ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_119 = ( V_114 . V_125 == V_126 ) ;
memset ( sin , 0 , sizeof( * sin ) ) ;
sin -> V_125 = V_126 ;
break;
case V_127 :
V_117 = - V_128 ;
if ( ! F_98 ( V_1 -> V_129 , V_130 ) )
goto V_40;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
V_117 = - V_128 ;
if ( ! F_98 ( V_1 -> V_129 , V_130 ) )
goto V_40;
V_117 = - V_79 ;
if ( sin -> V_125 != V_126 )
goto V_40;
break;
default:
V_117 = - V_79 ;
goto V_40;
}
F_99 () ;
V_117 = - V_98 ;
V_17 = F_100 ( V_1 , V_112 . V_120 ) ;
if ( ! V_17 )
goto V_135;
if ( V_116 )
* V_116 = ':' ;
V_39 = F_66 ( V_17 ) ;
if ( V_39 ) {
if ( V_119 ) {
for ( V_54 = & V_39 -> V_34 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( ! strcmp ( V_112 . V_120 , V_7 -> V_101 ) &&
V_114 . V_136 . V_137 ==
V_7 -> V_9 ) {
break;
}
}
}
if ( ! V_7 ) {
for ( V_54 = & V_39 -> V_34 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 )
if ( ! strcmp ( V_112 . V_120 , V_7 -> V_101 ) )
break;
}
}
V_117 = - V_104 ;
if ( ! V_7 && V_110 != V_131 && V_110 != V_127 )
goto V_135;
switch ( V_110 ) {
case V_121 :
sin -> V_136 . V_137 = V_7 -> V_9 ;
goto V_138;
case V_122 :
sin -> V_136 . V_137 = V_7 -> V_106 ;
goto V_138;
case V_123 :
sin -> V_136 . V_137 = V_7 -> V_70 ;
goto V_138;
case V_124 :
sin -> V_136 . V_137 = V_7 -> V_69 ;
goto V_138;
case V_127 :
if ( V_116 ) {
V_117 = - V_104 ;
if ( ! V_7 )
break;
V_117 = 0 ;
if ( ! ( V_112 . V_139 & V_50 ) )
F_48 ( V_39 , V_54 , 1 ) ;
break;
}
V_117 = F_101 ( V_17 , V_112 . V_139 ) ;
break;
case V_131 :
V_117 = - V_79 ;
if ( F_89 ( sin -> V_136 . V_137 ) < 0 )
break;
if ( ! V_7 ) {
V_117 = - V_80 ;
V_7 = F_22 () ;
if ( ! V_7 )
break;
F_82 ( & V_7 -> V_8 ) ;
if ( V_116 )
memcpy ( V_7 -> V_101 , V_112 . V_120 , V_107 ) ;
else
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
} else {
V_117 = 0 ;
if ( V_7 -> V_9 == sin -> V_136 . V_137 )
break;
F_48 ( V_39 , V_54 , 0 ) ;
V_7 -> V_106 = 0 ;
V_7 -> V_68 = 0 ;
}
V_7 -> V_70 = V_7 -> V_9 = sin -> V_136 . V_137 ;
if ( ! ( V_17 -> V_49 & V_140 ) ) {
V_7 -> V_103 = F_89 ( V_7 -> V_70 ) ;
V_7 -> V_69 = F_83 ( V_7 -> V_103 ) ;
if ( ( V_17 -> V_49 & V_141 ) &&
V_7 -> V_103 < 31 )
V_7 -> V_106 = V_7 -> V_70 |
~ V_7 -> V_69 ;
} else {
V_7 -> V_103 = 32 ;
V_7 -> V_69 = F_83 ( 32 ) ;
}
V_117 = F_65 ( V_17 , V_7 ) ;
break;
case V_132 :
V_117 = 0 ;
if ( V_7 -> V_106 != sin -> V_136 . V_137 ) {
F_48 ( V_39 , V_54 , 0 ) ;
V_7 -> V_106 = sin -> V_136 . V_137 ;
F_64 ( V_7 ) ;
}
break;
case V_133 :
V_117 = 0 ;
if ( V_7 -> V_70 == sin -> V_136 . V_137 )
break;
V_117 = - V_79 ;
if ( F_89 ( sin -> V_136 . V_137 ) < 0 )
break;
V_117 = 0 ;
F_48 ( V_39 , V_54 , 0 ) ;
V_7 -> V_70 = sin -> V_136 . V_137 ;
F_64 ( V_7 ) ;
break;
case V_134 :
V_117 = - V_79 ;
if ( F_102 ( sin -> V_136 . V_137 , 0 ) )
break;
V_117 = 0 ;
if ( V_7 -> V_69 != sin -> V_136 . V_137 ) {
T_2 V_142 = V_7 -> V_69 ;
F_48 ( V_39 , V_54 , 0 ) ;
V_7 -> V_69 = sin -> V_136 . V_137 ;
V_7 -> V_103 = F_103 ( V_7 -> V_69 ) ;
if ( ( V_17 -> V_49 & V_141 ) &&
( V_7 -> V_103 < 31 ) &&
( V_7 -> V_106 ==
( V_7 -> V_9 | ~ V_142 ) ) ) {
V_7 -> V_106 = ( V_7 -> V_9 |
~ sin -> V_136 . V_137 ) ;
}
F_64 ( V_7 ) ;
}
break;
}
V_135:
F_104 () ;
V_40:
return V_117 ;
V_138:
F_104 () ;
V_117 = F_105 ( V_87 , & V_112 , sizeof( struct V_111 ) ) ? - V_118 : 0 ;
goto V_40;
}
static int F_106 ( struct V_12 * V_17 , char T_4 * V_143 , int V_144 )
{
struct V_29 * V_39 = F_66 ( V_17 ) ;
struct V_6 * V_7 ;
struct V_111 V_112 ;
int V_135 = 0 ;
if ( ! V_39 )
goto V_40;
for ( V_7 = V_39 -> V_34 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( ! V_143 ) {
V_135 += sizeof( V_112 ) ;
continue;
}
if ( V_144 < ( int ) sizeof( V_112 ) )
break;
memset ( & V_112 , 0 , sizeof( struct V_111 ) ) ;
if ( V_7 -> V_101 )
strcpy ( V_112 . V_120 , V_7 -> V_101 ) ;
else
strcpy ( V_112 . V_120 , V_17 -> V_37 ) ;
( * (struct V_113 * ) & V_112 . V_115 ) . V_125 = V_126 ;
( * (struct V_113 * ) & V_112 . V_115 ) . V_136 . V_137 =
V_7 -> V_9 ;
if ( F_105 ( V_143 , & V_112 , sizeof( struct V_111 ) ) ) {
V_135 = - V_118 ;
break;
}
V_143 += sizeof( struct V_111 ) ;
V_144 -= sizeof( struct V_111 ) ;
V_135 += sizeof( struct V_111 ) ;
}
V_40:
return V_135 ;
}
T_2 F_107 ( const struct V_12 * V_17 , T_2 V_145 , int V_146 )
{
T_2 V_2 = 0 ;
struct V_29 * V_39 ;
struct V_1 * V_1 = F_14 ( V_17 ) ;
F_11 () ;
V_39 = F_108 ( V_17 ) ;
if ( ! V_39 )
goto V_147;
F_53 (in_dev) {
if ( V_7 -> V_68 > V_146 )
continue;
if ( ! V_145 || F_54 ( V_145 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_55 ( V_39 ) ;
if ( V_2 )
goto V_148;
V_147:
F_109 (net, dev) {
V_39 = F_108 ( V_17 ) ;
if ( ! V_39 )
continue;
F_53 (in_dev) {
if ( V_7 -> V_68 != V_149 &&
V_7 -> V_68 <= V_146 ) {
V_2 = V_7 -> V_9 ;
goto V_148;
}
} F_55 ( V_39 ) ;
}
V_148:
F_19 () ;
return V_2 ;
}
static T_2 F_110 ( struct V_29 * V_39 , T_2 V_145 ,
T_2 V_25 , int V_146 )
{
int V_150 = 0 ;
T_2 V_2 = 0 ;
F_111 (in_dev) {
if ( ! V_2 &&
( V_25 == V_7 -> V_9 || ! V_25 ) &&
V_7 -> V_68 <= V_146 ) {
V_2 = V_7 -> V_9 ;
if ( V_150 )
break;
}
if ( ! V_150 ) {
V_150 = ( ! V_25 || F_54 ( V_25 , V_7 ) ) &&
( ! V_145 || F_54 ( V_145 , V_7 ) ) ;
if ( V_150 && V_2 ) {
if ( V_25 || ! V_145 )
break;
if ( F_54 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_68 <= V_146 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_150 = 0 ;
}
}
} F_55 ( V_39 ) ;
return V_150 ? V_2 : 0 ;
}
T_2 F_112 ( struct V_29 * V_39 ,
T_2 V_145 , T_2 V_25 , int V_146 )
{
T_2 V_2 = 0 ;
struct V_12 * V_17 ;
struct V_1 * V_1 ;
if ( V_146 != V_149 )
return F_110 ( V_39 , V_145 , V_25 , V_146 ) ;
V_1 = F_14 ( V_39 -> V_17 ) ;
F_11 () ;
F_109 (net, dev) {
V_39 = F_108 ( V_17 ) ;
if ( V_39 ) {
V_2 = F_110 ( V_39 , V_145 , V_25 , V_146 ) ;
if ( V_2 )
break;
}
}
F_19 () ;
return V_2 ;
}
int F_113 ( struct V_151 * V_152 )
{
return F_114 ( & V_72 , V_152 ) ;
}
int F_115 ( struct V_151 * V_152 )
{
return F_116 ( & V_72 , V_152 ) ;
}
static void F_117 ( struct V_12 * V_17 , struct V_29 * V_39 )
{
struct V_6 * V_7 ;
int V_153 = 0 ;
for ( V_7 = V_39 -> V_34 ; V_7 ; V_7 = V_7 -> V_67 ) {
char V_154 [ V_107 ] , * V_155 ;
memcpy ( V_154 , V_7 -> V_101 , V_107 ) ;
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
if ( V_153 ++ == 0 )
goto V_156;
V_155 = strchr ( V_154 , ':' ) ;
if ( V_155 == NULL ) {
sprintf ( V_154 , L_4 , V_153 ) ;
V_155 = V_154 ;
}
if ( strlen ( V_155 ) + strlen ( V_17 -> V_37 ) < V_107 )
strcat ( V_7 -> V_101 , V_155 ) ;
else
strcpy ( V_7 -> V_101 + ( V_107 - strlen ( V_155 ) - 1 ) , V_155 ) ;
V_156:
F_58 ( V_75 , V_7 , NULL , 0 ) ;
}
}
static bool F_118 ( unsigned int V_157 )
{
return V_157 >= 68 ;
}
static void F_119 ( struct V_12 * V_17 ,
struct V_29 * V_39 )
{
struct V_6 * V_7 ;
for ( V_7 = V_39 -> V_34 ; V_7 ;
V_7 = V_7 -> V_67 ) {
F_120 ( V_158 , V_159 ,
V_7 -> V_9 , V_17 ,
V_7 -> V_9 , NULL ,
V_17 -> V_160 , NULL ) ;
}
}
static int F_121 ( struct V_151 * V_161 , unsigned long V_162 ,
void * V_163 )
{
struct V_12 * V_17 = V_163 ;
struct V_29 * V_39 = F_66 ( V_17 ) ;
F_37 () ;
if ( ! V_39 ) {
if ( V_162 == V_164 ) {
V_39 = F_36 ( V_17 ) ;
if ( ! V_39 )
return F_122 ( - V_165 ) ;
if ( V_17 -> V_49 & V_166 ) {
F_123 ( V_39 , V_167 , 1 ) ;
F_123 ( V_39 , V_168 , 1 ) ;
}
} else if ( V_162 == V_169 ) {
if ( F_118 ( V_17 -> V_157 ) )
V_39 = F_36 ( V_17 ) ;
}
goto V_40;
}
switch ( V_162 ) {
case V_164 :
F_33 ( L_5 , V_36 ) ;
F_49 ( V_17 -> V_51 , NULL ) ;
break;
case V_76 :
if ( ! F_118 ( V_17 -> V_157 ) )
break;
if ( V_17 -> V_49 & V_166 ) {
struct V_6 * V_7 = F_22 () ;
if ( V_7 ) {
F_82 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_70 = F_124 ( V_170 ) ;
V_7 -> V_103 = 8 ;
V_7 -> V_69 = F_83 ( 8 ) ;
F_41 ( V_39 ) ;
V_7 -> V_18 = V_39 ;
V_7 -> V_68 = V_81 ;
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
F_64 ( V_7 ) ;
}
}
F_43 ( V_39 ) ;
case V_171 :
if ( ! F_125 ( V_39 ) )
break;
case V_172 :
F_119 ( V_17 , V_39 ) ;
break;
case V_73 :
F_126 ( V_39 ) ;
break;
case V_173 :
F_127 ( V_39 ) ;
break;
case V_174 :
F_128 ( V_39 ) ;
break;
case V_169 :
if ( F_118 ( V_17 -> V_157 ) )
break;
case V_175 :
F_46 ( V_39 ) ;
break;
case V_176 :
F_117 ( V_17 , V_39 ) ;
F_21 ( V_39 ) ;
F_20 ( V_39 ) ;
break;
}
V_40:
return V_177 ;
}
static T_5 F_129 ( void )
{
return F_130 ( sizeof( struct V_92 ) )
+ F_131 ( 4 )
+ F_131 ( 4 )
+ F_131 ( 4 )
+ F_131 ( V_107 ) ;
}
static int F_132 ( struct V_85 * V_86 , struct V_6 * V_7 ,
T_1 V_58 , T_1 V_178 , int V_162 , unsigned int V_49 )
{
struct V_92 * V_93 ;
struct V_56 * V_57 ;
V_57 = F_133 ( V_86 , V_58 , V_178 , V_162 , sizeof( * V_93 ) , V_49 ) ;
if ( V_57 == NULL )
return - V_179 ;
V_93 = F_76 ( V_57 ) ;
V_93 -> V_180 = V_126 ;
V_93 -> V_103 = V_7 -> V_103 ;
V_93 -> V_64 = V_7 -> V_64 | V_181 ;
V_93 -> V_68 = V_7 -> V_68 ;
V_93 -> V_97 = V_7 -> V_18 -> V_17 -> V_82 ;
if ( ( V_7 -> V_70 &&
F_134 ( V_86 , V_102 , V_7 -> V_70 ) ) ||
( V_7 -> V_9 &&
F_134 ( V_86 , V_99 , V_7 -> V_9 ) ) ||
( V_7 -> V_106 &&
F_134 ( V_86 , V_105 , V_7 -> V_106 ) ) ||
( V_7 -> V_101 [ 0 ] &&
F_135 ( V_86 , V_100 , V_7 -> V_101 ) ) )
goto V_182;
return F_136 ( V_86 , V_57 ) ;
V_182:
F_137 ( V_86 , V_57 ) ;
return - V_179 ;
}
static int F_138 ( struct V_85 * V_86 , struct V_183 * V_184 )
{
struct V_1 * V_1 = F_74 ( V_86 -> V_88 ) ;
int V_185 , V_186 ;
int V_187 , V_188 ;
int V_189 , V_190 ;
struct V_12 * V_17 ;
struct V_29 * V_39 ;
struct V_6 * V_7 ;
struct V_191 * V_33 ;
struct V_15 * V_16 ;
V_186 = V_184 -> args [ 0 ] ;
V_188 = V_187 = V_184 -> args [ 1 ] ;
V_190 = V_189 = V_184 -> args [ 2 ] ;
for ( V_185 = V_186 ; V_185 < V_192 ; V_185 ++ , V_188 = 0 ) {
V_187 = 0 ;
V_33 = & V_1 -> V_193 [ V_185 ] ;
F_11 () ;
F_12 (dev, node, head, index_hlist) {
if ( V_187 < V_188 )
goto V_194;
if ( V_185 > V_186 || V_187 > V_188 )
V_190 = 0 ;
V_39 = F_108 ( V_17 ) ;
if ( ! V_39 )
goto V_194;
for ( V_7 = V_39 -> V_34 , V_189 = 0 ; V_7 ;
V_7 = V_7 -> V_67 , V_189 ++ ) {
if ( V_189 < V_190 )
continue;
if ( F_132 ( V_86 , V_7 ,
F_79 ( V_184 -> V_86 ) . V_58 ,
V_184 -> V_57 -> V_195 ,
V_75 , V_196 ) <= 0 ) {
F_19 () ;
goto V_135;
}
}
V_194:
V_187 ++ ;
}
F_19 () ;
}
V_135:
V_184 -> args [ 0 ] = V_185 ;
V_184 -> args [ 1 ] = V_187 ;
V_184 -> args [ 2 ] = V_189 ;
return V_86 -> V_144 ;
}
static void F_58 ( int V_162 , struct V_6 * V_7 , struct V_56 * V_57 ,
T_1 V_58 )
{
struct V_85 * V_86 ;
T_1 V_178 = V_57 ? V_57 -> V_195 : 0 ;
int V_94 = - V_80 ;
struct V_1 * V_1 ;
V_1 = F_14 ( V_7 -> V_18 -> V_17 ) ;
V_86 = F_139 ( F_129 () , V_31 ) ;
if ( V_86 == NULL )
goto V_96;
V_94 = F_132 ( V_86 , V_7 , V_58 , V_178 , V_162 , 0 ) ;
if ( V_94 < 0 ) {
F_31 ( V_94 == - V_179 ) ;
F_140 ( V_86 ) ;
goto V_96;
}
F_141 ( V_86 , V_1 , V_58 , V_197 , V_57 , V_31 ) ;
return;
V_96:
if ( V_94 < 0 )
F_142 ( V_1 , V_197 , V_94 ) ;
}
static T_5 F_143 ( const struct V_12 * V_17 )
{
struct V_29 * V_39 = F_71 ( V_17 -> V_51 ) ;
if ( ! V_39 )
return 0 ;
return F_131 ( V_198 * 4 ) ;
}
static int F_144 ( struct V_85 * V_86 , const struct V_12 * V_17 )
{
struct V_29 * V_39 = F_71 ( V_17 -> V_51 ) ;
struct V_89 * V_199 ;
int V_200 ;
if ( ! V_39 )
return - V_201 ;
V_199 = F_145 ( V_86 , V_202 , V_198 * 4 ) ;
if ( V_199 == NULL )
return - V_179 ;
for ( V_200 = 0 ; V_200 < V_198 ; V_200 ++ )
( ( T_1 * ) F_146 ( V_199 ) ) [ V_200 ] = V_39 -> V_41 . V_203 [ V_200 ] ;
return 0 ;
}
static int F_147 ( const struct V_12 * V_17 ,
const struct V_89 * V_199 )
{
struct V_89 * V_52 , * V_90 [ V_204 + 1 ] ;
int V_94 , V_205 ;
if ( V_17 && ! F_66 ( V_17 ) )
return - V_206 ;
V_94 = F_148 ( V_90 , V_204 , V_199 , V_207 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( V_90 [ V_202 ] ) {
F_149 (a, tb[IFLA_INET_CONF], rem) {
int V_208 = F_150 ( V_52 ) ;
if ( F_151 ( V_52 ) < 4 )
return - V_79 ;
if ( V_208 <= 0 || V_208 > V_198 )
return - V_79 ;
}
}
return 0 ;
}
static int F_152 ( struct V_12 * V_17 , const struct V_89 * V_199 )
{
struct V_29 * V_39 = F_66 ( V_17 ) ;
struct V_89 * V_52 , * V_90 [ V_204 + 1 ] ;
int V_205 ;
if ( ! V_39 )
return - V_206 ;
if ( F_148 ( V_90 , V_204 , V_199 , NULL ) < 0 )
F_153 () ;
if ( V_90 [ V_202 ] ) {
F_149 (a, tb[IFLA_INET_CONF], rem)
F_154 ( V_39 , F_150 ( V_52 ) , F_155 ( V_52 ) ) ;
}
return 0 ;
}
static int F_156 ( int type )
{
int V_209 = F_130 ( sizeof( struct V_210 ) )
+ F_131 ( 4 ) ;
if ( type == - 1 || type == V_211 )
V_209 += F_131 ( 4 ) ;
if ( type == - 1 || type == V_212 )
V_209 += F_131 ( 4 ) ;
if ( type == - 1 || type == V_213 )
V_209 += F_131 ( 4 ) ;
return V_209 ;
}
static int F_157 ( struct V_85 * V_86 , int V_82 ,
struct V_214 * V_215 , T_1 V_58 ,
T_1 V_178 , int V_162 , unsigned int V_49 ,
int type )
{
struct V_56 * V_57 ;
struct V_210 * V_216 ;
V_57 = F_133 ( V_86 , V_58 , V_178 , V_162 , sizeof( struct V_210 ) ,
V_49 ) ;
if ( V_57 == NULL )
return - V_179 ;
V_216 = F_76 ( V_57 ) ;
V_216 -> V_217 = V_126 ;
if ( F_158 ( V_86 , V_218 , V_82 ) < 0 )
goto V_182;
if ( ( type == - 1 || type == V_211 ) &&
F_158 ( V_86 , V_211 ,
F_39 ( * V_215 , V_48 ) ) < 0 )
goto V_182;
if ( ( type == - 1 || type == V_212 ) &&
F_158 ( V_86 , V_212 ,
F_39 ( * V_215 , V_219 ) ) < 0 )
goto V_182;
if ( ( type == - 1 || type == V_213 ) &&
F_158 ( V_86 , V_213 ,
F_39 ( * V_215 , V_220 ) ) < 0 )
goto V_182;
return F_136 ( V_86 , V_57 ) ;
V_182:
F_137 ( V_86 , V_57 ) ;
return - V_179 ;
}
void F_159 ( struct V_1 * V_1 , int type , int V_82 ,
struct V_214 * V_215 )
{
struct V_85 * V_86 ;
int V_94 = - V_80 ;
V_86 = F_139 ( F_156 ( type ) , V_221 ) ;
if ( V_86 == NULL )
goto V_96;
V_94 = F_157 ( V_86 , V_82 , V_215 , 0 , 0 ,
V_222 , 0 , type ) ;
if ( V_94 < 0 ) {
F_31 ( V_94 == - V_179 ) ;
F_140 ( V_86 ) ;
goto V_96;
}
F_141 ( V_86 , V_1 , 0 , V_223 , NULL , V_221 ) ;
return;
V_96:
if ( V_94 < 0 )
F_142 ( V_1 , V_223 , V_94 ) ;
}
static int F_160 ( struct V_85 * V_224 ,
struct V_56 * V_57 ,
void * V_87 )
{
struct V_1 * V_1 = F_74 ( V_224 -> V_88 ) ;
struct V_89 * V_90 [ V_225 + 1 ] ;
struct V_210 * V_216 ;
struct V_85 * V_86 ;
struct V_214 * V_215 ;
struct V_29 * V_39 ;
struct V_12 * V_17 ;
int V_82 ;
int V_94 ;
V_94 = F_75 ( V_57 , sizeof( * V_216 ) , V_90 , V_225 ,
V_226 ) ;
if ( V_94 < 0 )
goto V_96;
V_94 = V_79 ;
if ( ! V_90 [ V_218 ] )
goto V_96;
V_82 = F_161 ( V_90 [ V_218 ] ) ;
switch ( V_82 ) {
case V_227 :
V_215 = V_1 -> V_42 . V_228 ;
break;
case V_229 :
V_215 = V_1 -> V_42 . V_43 ;
break;
default:
V_17 = F_81 ( V_1 , V_82 ) ;
if ( V_17 == NULL )
goto V_96;
V_39 = F_66 ( V_17 ) ;
if ( V_39 == NULL )
goto V_96;
V_215 = & V_39 -> V_41 ;
break;
}
V_94 = - V_80 ;
V_86 = F_139 ( F_156 ( - 1 ) , V_221 ) ;
if ( V_86 == NULL )
goto V_96;
V_94 = F_157 ( V_86 , V_82 , V_215 ,
F_79 ( V_224 ) . V_58 ,
V_57 -> V_195 , V_222 , 0 ,
- 1 ) ;
if ( V_94 < 0 ) {
F_31 ( V_94 == - V_179 ) ;
F_140 ( V_86 ) ;
goto V_96;
}
V_94 = F_162 ( V_86 , V_1 , F_79 ( V_224 ) . V_58 ) ;
V_96:
return V_94 ;
}
static void F_163 ( struct V_1 * V_1 , int V_200 )
{
struct V_12 * V_17 ;
F_11 () ;
F_109 (net, dev) {
struct V_29 * V_39 ;
V_39 = F_108 ( V_17 ) ;
if ( V_39 && ! F_164 ( V_200 , V_39 -> V_41 . V_230 ) )
V_39 -> V_41 . V_203 [ V_200 ] = V_1 -> V_42 . V_43 -> V_203 [ V_200 ] ;
}
F_19 () ;
}
static void F_165 ( struct V_1 * V_1 )
{
struct V_12 * V_17 ;
int V_231 = F_166 ( V_1 , V_48 ) ;
F_166 ( V_1 , V_232 ) = ! V_231 ;
F_167 ( V_1 , V_48 ) = V_231 ;
F_159 ( V_1 , V_211 ,
V_227 ,
V_1 -> V_42 . V_228 ) ;
F_159 ( V_1 , V_211 ,
V_229 ,
V_1 -> V_42 . V_43 ) ;
F_168 (net, dev) {
struct V_29 * V_39 ;
if ( V_231 )
F_40 ( V_17 ) ;
F_11 () ;
V_39 = F_108 ( V_17 ) ;
if ( V_39 ) {
F_123 ( V_39 , V_48 , V_231 ) ;
F_159 ( V_1 , V_211 ,
V_17 -> V_82 , & V_39 -> V_41 ) ;
}
F_19 () ;
}
}
static int F_169 ( T_6 * V_233 , int V_234 ,
void T_4 * V_235 ,
T_5 * V_236 , T_7 * V_237 )
{
int V_238 = * ( int * ) V_233 -> V_203 ;
int V_117 = F_170 ( V_233 , V_234 , V_235 , V_236 , V_237 ) ;
int V_239 = * ( int * ) V_233 -> V_203 ;
if ( V_234 ) {
struct V_214 * V_41 = V_233 -> V_240 ;
struct V_1 * V_1 = V_233 -> V_241 ;
int V_200 = ( int * ) V_233 -> V_203 - V_41 -> V_203 ;
F_171 ( V_200 , V_41 -> V_230 ) ;
if ( V_41 == V_1 -> V_42 . V_43 )
F_163 ( V_1 , V_200 ) ;
if ( V_200 == V_242 - 1 ||
V_200 == V_243 - 1 )
if ( ( V_239 == 0 ) && ( V_238 != 0 ) )
F_172 ( V_1 ) ;
if ( V_200 == V_244 - 1 &&
V_239 != V_238 ) {
int V_82 ;
if ( V_41 == V_1 -> V_42 . V_43 )
V_82 = V_229 ;
else if ( V_41 == V_1 -> V_42 . V_228 )
V_82 = V_227 ;
else {
struct V_29 * V_30 =
F_25 ( V_41 , struct V_29 ,
V_41 ) ;
V_82 = V_30 -> V_17 -> V_82 ;
}
F_159 ( V_1 , V_212 ,
V_82 , V_41 ) ;
}
}
return V_117 ;
}
static int F_173 ( T_6 * V_233 , int V_234 ,
void T_4 * V_235 ,
T_5 * V_236 , T_7 * V_237 )
{
int * V_245 = V_233 -> V_203 ;
int V_3 = * V_245 ;
T_7 V_246 = * V_237 ;
int V_117 = F_170 ( V_233 , V_234 , V_235 , V_236 , V_237 ) ;
if ( V_234 && * V_245 != V_3 ) {
struct V_1 * V_1 = V_233 -> V_241 ;
if ( V_245 != & F_167 ( V_1 , V_48 ) ) {
if ( ! F_174 () ) {
* V_245 = V_3 ;
* V_237 = V_246 ;
return F_175 () ;
}
if ( V_245 == & F_166 ( V_1 , V_48 ) ) {
F_165 ( V_1 ) ;
} else {
struct V_214 * V_41 = V_233 -> V_240 ;
struct V_29 * V_30 =
F_25 ( V_41 , struct V_29 , V_41 ) ;
if ( * V_245 )
F_40 ( V_30 -> V_17 ) ;
F_159 ( V_1 ,
V_211 ,
V_30 -> V_17 -> V_82 ,
V_41 ) ;
}
F_104 () ;
F_172 ( V_1 ) ;
} else
F_159 ( V_1 , V_211 ,
V_229 ,
V_1 -> V_42 . V_43 ) ;
}
return V_117 ;
}
static int F_176 ( T_6 * V_233 , int V_234 ,
void T_4 * V_235 ,
T_5 * V_236 , T_7 * V_237 )
{
int * V_245 = V_233 -> V_203 ;
int V_3 = * V_245 ;
int V_117 = F_170 ( V_233 , V_234 , V_235 , V_236 , V_237 ) ;
struct V_1 * V_1 = V_233 -> V_241 ;
if ( V_234 && * V_245 != V_3 )
F_172 ( V_1 ) ;
return V_117 ;
}
static int F_177 ( struct V_1 * V_1 , char * V_247 ,
struct V_214 * V_248 )
{
int V_200 ;
struct V_249 * V_250 ;
char V_251 [ sizeof( L_6 ) + V_107 ] ;
V_250 = F_178 ( & V_252 , sizeof( * V_250 ) , V_31 ) ;
if ( ! V_250 )
goto V_40;
for ( V_200 = 0 ; V_200 < F_179 ( V_250 -> V_253 ) - 1 ; V_200 ++ ) {
V_250 -> V_253 [ V_200 ] . V_203 += ( char * ) V_248 - ( char * ) & V_214 ;
V_250 -> V_253 [ V_200 ] . V_240 = V_248 ;
V_250 -> V_253 [ V_200 ] . V_241 = V_1 ;
}
snprintf ( V_251 , sizeof( V_251 ) , L_7 , V_247 ) ;
V_250 -> V_254 = F_180 ( V_1 , V_251 , V_250 -> V_253 ) ;
if ( ! V_250 -> V_254 )
goto free;
V_248 -> V_44 = V_250 ;
return 0 ;
free:
F_27 ( V_250 ) ;
V_40:
return - V_80 ;
}
static void F_181 ( struct V_214 * V_41 )
{
struct V_249 * V_250 = V_41 -> V_44 ;
if ( V_250 == NULL )
return;
V_41 -> V_44 = NULL ;
F_182 ( V_250 -> V_254 ) ;
F_27 ( V_250 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
F_183 ( V_30 -> V_17 , V_30 -> V_45 , L_8 , NULL ) ;
F_177 ( F_14 ( V_30 -> V_17 ) , V_30 -> V_17 -> V_37 ,
& V_30 -> V_41 ) ;
}
static void F_21 ( struct V_29 * V_30 )
{
F_181 ( & V_30 -> V_41 ) ;
F_184 ( V_30 -> V_45 ) ;
}
static T_8 int F_185 ( struct V_1 * V_1 )
{
int V_94 ;
struct V_214 * V_255 , * V_256 ;
#ifdef F_186
struct T_6 * V_257 = V_258 ;
struct V_259 * V_260 ;
#endif
V_94 = - V_165 ;
V_255 = & V_214 ;
V_256 = & V_261 ;
if ( ! F_13 ( V_1 , & V_262 ) ) {
V_255 = F_178 ( V_255 , sizeof( V_214 ) , V_31 ) ;
if ( V_255 == NULL )
goto V_263;
V_256 = F_178 ( V_256 , sizeof( V_261 ) , V_31 ) ;
if ( V_256 == NULL )
goto V_264;
#ifdef F_186
V_257 = F_178 ( V_257 , sizeof( V_258 ) , V_31 ) ;
if ( V_257 == NULL )
goto V_265;
V_257 [ 0 ] . V_203 = & V_255 -> V_203 [ V_266 - 1 ] ;
V_257 [ 0 ] . V_240 = V_255 ;
V_257 [ 0 ] . V_241 = V_1 ;
#endif
}
#ifdef F_186
V_94 = F_177 ( V_1 , L_9 , V_255 ) ;
if ( V_94 < 0 )
goto V_267;
V_94 = F_177 ( V_1 , L_10 , V_256 ) ;
if ( V_94 < 0 )
goto V_268;
V_94 = - V_165 ;
V_260 = F_180 ( V_1 , L_11 , V_257 ) ;
if ( V_260 == NULL )
goto V_269;
V_1 -> V_42 . V_260 = V_260 ;
#endif
V_1 -> V_42 . V_228 = V_255 ;
V_1 -> V_42 . V_43 = V_256 ;
return 0 ;
#ifdef F_186
V_269:
F_181 ( V_256 ) ;
V_268:
F_181 ( V_255 ) ;
V_267:
if ( V_257 != V_258 )
F_27 ( V_257 ) ;
V_265:
#endif
if ( V_256 != & V_261 )
F_27 ( V_256 ) ;
V_264:
if ( V_255 != & V_214 )
F_27 ( V_255 ) ;
V_263:
return V_94 ;
}
static T_9 void F_187 ( struct V_1 * V_1 )
{
#ifdef F_186
struct T_6 * V_257 ;
V_257 = V_1 -> V_42 . V_260 -> V_270 ;
F_182 ( V_1 -> V_42 . V_260 ) ;
F_181 ( V_1 -> V_42 . V_43 ) ;
F_181 ( V_1 -> V_42 . V_228 ) ;
F_27 ( V_257 ) ;
#endif
F_27 ( V_1 -> V_42 . V_43 ) ;
F_27 ( V_1 -> V_42 . V_228 ) ;
}
void T_10 F_188 ( void )
{
int V_200 ;
for ( V_200 = 0 ; V_200 < V_271 ; V_200 ++ )
F_189 ( & V_11 [ V_200 ] ) ;
F_190 ( & V_272 ) ;
F_191 ( V_273 , F_106 ) ;
F_192 ( & V_274 ) ;
F_193 ( & V_275 ) ;
F_194 ( V_273 , V_75 , F_86 , NULL , NULL ) ;
F_194 ( V_273 , V_71 , F_73 , NULL , NULL ) ;
F_194 ( V_273 , V_276 , NULL , F_138 , NULL ) ;
F_194 ( V_273 , V_277 , F_160 ,
NULL , NULL ) ;
}
