static inline unsigned int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
T_2 V_3 = ( V_4 T_2 ) V_2 ^ F_2 ( V_1 , 8 ) ;
return ( ( V_3 ^ ( V_3 >> 8 ) ^ ( V_3 >> 16 ) ^ ( V_3 >> 24 ) ) &
( V_5 - 1 ) ) ;
}
static void F_3 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
unsigned int V_8 = F_1 ( V_1 , V_7 -> V_9 ) ;
F_4 ( & V_10 ) ;
F_5 ( & V_7 -> V_8 , & V_11 [ V_8 ] ) ;
F_6 ( & V_10 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_4 ( & V_10 ) ;
F_8 ( & V_7 -> V_8 ) ;
F_6 ( & V_10 ) ;
}
struct V_12 * F_9 ( struct V_1 * V_1 , T_1 V_2 , bool V_13 )
{
unsigned int V_8 = F_1 ( V_1 , V_2 ) ;
struct V_12 * V_14 = NULL ;
struct V_6 * V_7 ;
struct V_15 * V_16 ;
F_10 () ;
F_11 (ifa, node, &inet_addr_lst[hash], hash) {
struct V_12 * V_17 = V_7 -> V_18 -> V_17 ;
if ( ! F_12 ( F_13 ( V_17 ) , V_1 ) )
continue;
if ( V_7 -> V_9 == V_2 ) {
V_14 = V_17 ;
break;
}
}
if ( ! V_14 ) {
struct V_19 V_20 = { . V_21 = V_2 } ;
struct V_22 V_23 = { 0 } ;
struct V_24 * V_25 ;
V_25 = F_14 ( V_1 , V_26 ) ;
if ( V_25 &&
! F_15 ( V_25 , & V_20 , & V_23 , V_27 ) &&
V_23 . type == V_28 )
V_14 = F_16 ( V_23 ) ;
}
if ( V_14 && V_13 )
F_17 ( V_14 ) ;
F_18 () ;
return V_14 ;
}
static inline void F_19 ( struct V_29 * V_30 )
{
}
static inline void F_20 ( struct V_29 * V_30 )
{
}
static struct V_6 * F_21 ( void )
{
return F_22 ( sizeof( struct V_6 ) , V_31 ) ;
}
static void F_23 ( struct V_32 * V_33 )
{
struct V_6 * V_7 = F_24 ( V_33 , struct V_6 , V_32 ) ;
if ( V_7 -> V_18 )
F_25 ( V_7 -> V_18 ) ;
F_26 ( V_7 ) ;
}
static inline void F_27 ( struct V_6 * V_7 )
{
F_28 ( & V_7 -> V_32 , F_23 ) ;
}
void F_29 ( struct V_29 * V_30 )
{
struct V_12 * V_17 = V_30 -> V_17 ;
F_30 ( V_30 -> V_34 ) ;
F_30 ( V_30 -> V_35 ) ;
#ifdef F_31
F_32 ( V_36 L_1 ,
V_30 , V_17 ? V_17 -> V_37 : L_2 ) ;
#endif
F_33 ( V_17 ) ;
if ( ! V_30 -> V_38 )
F_34 ( L_3 , V_30 ) ;
else
F_26 ( V_30 ) ;
}
static struct V_29 * F_35 ( struct V_12 * V_17 )
{
struct V_29 * V_39 ;
F_36 () ;
V_39 = F_22 ( sizeof( * V_39 ) , V_31 ) ;
if ( ! V_39 )
goto V_40;
memcpy ( & V_39 -> V_41 , F_13 ( V_17 ) -> V_42 . V_43 ,
sizeof( V_39 -> V_41 ) ) ;
V_39 -> V_41 . V_44 = NULL ;
V_39 -> V_17 = V_17 ;
V_39 -> V_45 = F_37 ( V_17 , & V_46 ) ;
if ( ! V_39 -> V_45 )
goto V_47;
if ( F_38 ( V_39 -> V_41 , V_48 ) )
F_39 ( V_17 ) ;
F_17 ( V_17 ) ;
F_40 ( V_39 ) ;
F_19 ( V_39 ) ;
F_41 ( V_39 ) ;
if ( V_17 -> V_49 & V_50 )
F_42 ( V_39 ) ;
F_43 ( V_17 -> V_51 , V_39 ) ;
V_40:
return V_39 ;
V_47:
F_26 ( V_39 ) ;
V_39 = NULL ;
goto V_40;
}
static void F_44 ( struct V_32 * V_33 )
{
struct V_29 * V_30 = F_24 ( V_33 , struct V_29 , V_32 ) ;
F_25 ( V_30 ) ;
}
static void F_45 ( struct V_29 * V_39 )
{
struct V_6 * V_7 ;
struct V_12 * V_17 ;
F_36 () ;
V_17 = V_39 -> V_17 ;
V_39 -> V_38 = 1 ;
F_46 ( V_39 ) ;
while ( ( V_7 = V_39 -> V_34 ) != NULL ) {
F_47 ( V_39 , & V_39 -> V_34 , 0 ) ;
F_27 ( V_7 ) ;
}
F_43 ( V_17 -> V_51 , NULL ) ;
F_20 ( V_39 ) ;
F_48 ( & V_46 , V_39 -> V_45 ) ;
F_49 ( V_17 ) ;
F_28 ( & V_39 -> V_32 , F_44 ) ;
}
int F_50 ( struct V_29 * V_39 , T_1 V_52 , T_1 V_53 )
{
F_10 () ;
F_51 (in_dev) {
if ( F_52 ( V_52 , V_7 ) ) {
if ( ! V_53 || F_52 ( V_53 , V_7 ) ) {
F_18 () ;
return 1 ;
}
}
} F_53 ( V_39 ) ;
F_18 () ;
return 0 ;
}
static void F_54 ( struct V_29 * V_39 , struct V_6 * * V_54 ,
int V_55 , struct V_56 * V_57 , T_2 V_58 )
{
struct V_6 * V_59 = NULL ;
struct V_6 * V_7 , * V_60 = * V_54 ;
struct V_6 * V_61 = V_39 -> V_34 ;
struct V_6 * V_62 = NULL ;
int V_63 = F_55 ( V_39 ) ;
F_36 () ;
if ( ! ( V_60 -> V_64 & V_65 ) ) {
struct V_6 * * V_66 = & V_60 -> V_67 ;
while ( ( V_7 = * V_66 ) != NULL ) {
if ( ! ( V_7 -> V_64 & V_65 ) &&
V_60 -> V_68 <= V_7 -> V_68 )
V_61 = V_7 ;
if ( ! ( V_7 -> V_64 & V_65 ) ||
V_60 -> V_69 != V_7 -> V_69 ||
! F_52 ( V_60 -> V_70 , V_7 ) ) {
V_66 = & V_7 -> V_67 ;
V_62 = V_7 ;
continue;
}
if ( ! V_63 ) {
F_7 ( V_7 ) ;
* V_66 = V_7 -> V_67 ;
F_56 ( V_71 , V_7 , V_57 , V_58 ) ;
F_57 ( & V_72 ,
V_73 , V_7 ) ;
F_27 ( V_7 ) ;
} else {
V_59 = V_7 ;
break;
}
}
}
for ( V_7 = V_59 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( V_60 -> V_69 == V_7 -> V_69 &&
F_52 ( V_60 -> V_70 , V_7 ) )
F_58 ( V_7 , V_60 ) ;
}
* V_54 = V_60 -> V_67 ;
F_7 ( V_60 ) ;
F_56 ( V_71 , V_60 , V_57 , V_58 ) ;
F_57 ( & V_72 , V_73 , V_60 ) ;
if ( V_59 ) {
struct V_6 * V_74 = V_59 -> V_67 ;
if ( V_62 ) {
V_62 -> V_67 = V_59 -> V_67 ;
V_59 -> V_67 = V_61 -> V_67 ;
V_61 -> V_67 = V_59 ;
}
V_59 -> V_64 &= ~ V_65 ;
F_56 ( V_75 , V_59 , V_57 , V_58 ) ;
F_57 ( & V_72 ,
V_76 , V_59 ) ;
for ( V_7 = V_74 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( V_60 -> V_69 != V_7 -> V_69 ||
! F_52 ( V_60 -> V_70 , V_7 ) )
continue;
F_59 ( V_7 ) ;
}
}
if ( V_55 )
F_27 ( V_60 ) ;
}
static void F_47 ( struct V_29 * V_39 , struct V_6 * * V_54 ,
int V_55 )
{
F_54 ( V_39 , V_54 , V_55 , NULL , 0 ) ;
}
static int F_60 ( struct V_6 * V_7 , struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_29 * V_39 = V_7 -> V_18 ;
struct V_6 * V_60 , * * V_54 , * * V_77 ;
F_36 () ;
if ( ! V_7 -> V_9 ) {
F_27 ( V_7 ) ;
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
F_52 ( V_60 -> V_70 , V_7 ) ) {
if ( V_60 -> V_9 == V_7 -> V_9 ) {
F_27 ( V_7 ) ;
return - V_78 ;
}
if ( V_60 -> V_68 != V_7 -> V_68 ) {
F_27 ( V_7 ) ;
return - V_79 ;
}
V_7 -> V_64 |= V_65 ;
}
}
if ( ! ( V_7 -> V_64 & V_65 ) ) {
F_61 ( V_7 -> V_9 ) ;
V_54 = V_77 ;
}
V_7 -> V_67 = * V_54 ;
* V_54 = V_7 ;
F_3 ( F_13 ( V_39 -> V_17 ) , V_7 ) ;
F_56 ( V_75 , V_7 , V_57 , V_58 ) ;
F_57 ( & V_72 , V_76 , V_7 ) ;
return 0 ;
}
static int F_62 ( struct V_6 * V_7 )
{
return F_60 ( V_7 , NULL , 0 ) ;
}
static int F_63 ( struct V_12 * V_17 , struct V_6 * V_7 )
{
struct V_29 * V_39 = F_64 ( V_17 ) ;
F_36 () ;
if ( ! V_39 ) {
F_27 ( V_7 ) ;
return - V_80 ;
}
F_65 ( V_39 ) ;
if ( V_7 -> V_18 != V_39 ) {
F_30 ( V_7 -> V_18 ) ;
F_40 ( V_39 ) ;
V_7 -> V_18 = V_39 ;
}
if ( F_66 ( V_7 -> V_9 ) )
V_7 -> V_68 = V_81 ;
return F_62 ( V_7 ) ;
}
struct V_29 * F_67 ( struct V_1 * V_1 , int V_82 )
{
struct V_12 * V_17 ;
struct V_29 * V_39 = NULL ;
F_10 () ;
V_17 = F_68 ( V_1 , V_82 ) ;
if ( V_17 )
V_39 = F_69 ( V_17 -> V_51 ) ;
F_18 () ;
return V_39 ;
}
struct V_6 * F_70 ( struct V_29 * V_39 , T_1 V_83 ,
T_1 V_84 )
{
F_36 () ;
F_51 (in_dev) {
if ( V_7 -> V_69 == V_84 && F_52 ( V_83 , V_7 ) )
return V_7 ;
} F_53 ( V_39 ) ;
return NULL ;
}
static int F_71 ( struct V_85 * V_86 , struct V_56 * V_57 , void * V_87 )
{
struct V_1 * V_1 = F_72 ( V_86 -> V_88 ) ;
struct V_89 * V_90 [ V_91 + 1 ] ;
struct V_29 * V_39 ;
struct V_92 * V_93 ;
struct V_6 * V_7 , * * V_54 ;
int V_94 = - V_79 ;
F_36 () ;
V_94 = F_73 ( V_57 , sizeof( * V_93 ) , V_90 , V_91 , V_95 ) ;
if ( V_94 < 0 )
goto V_96;
V_93 = F_74 ( V_57 ) ;
V_39 = F_67 ( V_1 , V_93 -> V_97 ) ;
if ( V_39 == NULL ) {
V_94 = - V_98 ;
goto V_96;
}
for ( V_54 = & V_39 -> V_34 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( V_90 [ V_99 ] &&
V_7 -> V_9 != F_75 ( V_90 [ V_99 ] ) )
continue;
if ( V_90 [ V_100 ] && F_76 ( V_90 [ V_100 ] , V_7 -> V_101 ) )
continue;
if ( V_90 [ V_102 ] &&
( V_93 -> V_103 != V_7 -> V_103 ||
! F_52 ( F_75 ( V_90 [ V_102 ] ) , V_7 ) ) )
continue;
F_54 ( V_39 , V_54 , 1 , V_57 , F_77 ( V_86 ) . V_58 ) ;
return 0 ;
}
V_94 = - V_104 ;
V_96:
return V_94 ;
}
static struct V_6 * F_78 ( struct V_1 * V_1 , struct V_56 * V_57 )
{
struct V_89 * V_90 [ V_91 + 1 ] ;
struct V_6 * V_7 ;
struct V_92 * V_93 ;
struct V_12 * V_17 ;
struct V_29 * V_39 ;
int V_94 ;
V_94 = F_73 ( V_57 , sizeof( * V_93 ) , V_90 , V_91 , V_95 ) ;
if ( V_94 < 0 )
goto V_96;
V_93 = F_74 ( V_57 ) ;
V_94 = - V_79 ;
if ( V_93 -> V_103 > 32 || V_90 [ V_99 ] == NULL )
goto V_96;
V_17 = F_79 ( V_1 , V_93 -> V_97 ) ;
V_94 = - V_98 ;
if ( V_17 == NULL )
goto V_96;
V_39 = F_64 ( V_17 ) ;
V_94 = - V_80 ;
if ( V_39 == NULL )
goto V_96;
V_7 = F_21 () ;
if ( V_7 == NULL )
goto V_96;
F_65 ( V_39 ) ;
F_40 ( V_39 ) ;
if ( V_90 [ V_102 ] == NULL )
V_90 [ V_102 ] = V_90 [ V_99 ] ;
F_80 ( & V_7 -> V_8 ) ;
V_7 -> V_103 = V_93 -> V_103 ;
V_7 -> V_69 = F_81 ( V_93 -> V_103 ) ;
V_7 -> V_64 = V_93 -> V_64 ;
V_7 -> V_68 = V_93 -> V_68 ;
V_7 -> V_18 = V_39 ;
V_7 -> V_9 = F_75 ( V_90 [ V_99 ] ) ;
V_7 -> V_70 = F_75 ( V_90 [ V_102 ] ) ;
if ( V_90 [ V_105 ] )
V_7 -> V_106 = F_75 ( V_90 [ V_105 ] ) ;
if ( V_90 [ V_100 ] )
F_82 ( V_7 -> V_101 , V_90 [ V_100 ] , V_107 ) ;
else
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
return V_7 ;
V_96:
return F_83 ( V_94 ) ;
}
static int F_84 ( struct V_85 * V_86 , struct V_56 * V_57 , void * V_87 )
{
struct V_1 * V_1 = F_72 ( V_86 -> V_88 ) ;
struct V_6 * V_7 ;
F_36 () ;
V_7 = F_78 ( V_1 , V_57 ) ;
if ( F_85 ( V_7 ) )
return F_86 ( V_7 ) ;
return F_60 ( V_7 , V_57 , F_77 ( V_86 ) . V_58 ) ;
}
static inline int F_87 ( T_1 V_2 )
{
int V_108 = - 1 ;
if ( F_88 ( V_2 ) )
V_108 = 0 ;
else {
T_3 V_109 = F_89 ( V_2 ) ;
if ( F_90 ( V_109 ) )
V_108 = 8 ;
else if ( F_91 ( V_109 ) )
V_108 = 16 ;
else if ( F_92 ( V_109 ) )
V_108 = 24 ;
}
return V_108 ;
}
int F_93 ( struct V_1 * V_1 , unsigned int V_110 , void T_4 * V_87 )
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
if ( F_94 ( & V_112 , V_87 , sizeof( struct V_111 ) ) )
goto V_40;
V_112 . V_120 [ V_107 - 1 ] = 0 ;
memcpy ( & V_114 , sin , sizeof( * sin ) ) ;
V_116 = strchr ( V_112 . V_120 , ':' ) ;
if ( V_116 )
* V_116 = 0 ;
F_95 ( V_1 , V_112 . V_120 ) ;
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
if ( ! F_96 ( V_129 ) )
goto V_40;
break;
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_117 = - V_128 ;
if ( ! F_96 ( V_129 ) )
goto V_40;
V_117 = - V_79 ;
if ( sin -> V_125 != V_126 )
goto V_40;
break;
default:
V_117 = - V_79 ;
goto V_40;
}
F_97 () ;
V_117 = - V_98 ;
V_17 = F_98 ( V_1 , V_112 . V_120 ) ;
if ( ! V_17 )
goto V_134;
if ( V_116 )
* V_116 = ':' ;
V_39 = F_64 ( V_17 ) ;
if ( V_39 ) {
if ( V_119 ) {
for ( V_54 = & V_39 -> V_34 ; ( V_7 = * V_54 ) != NULL ;
V_54 = & V_7 -> V_67 ) {
if ( ! strcmp ( V_112 . V_120 , V_7 -> V_101 ) &&
V_114 . V_135 . V_136 ==
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
if ( ! V_7 && V_110 != V_130 && V_110 != V_127 )
goto V_134;
switch ( V_110 ) {
case V_121 :
sin -> V_135 . V_136 = V_7 -> V_9 ;
goto V_137;
case V_122 :
sin -> V_135 . V_136 = V_7 -> V_106 ;
goto V_137;
case V_123 :
sin -> V_135 . V_136 = V_7 -> V_70 ;
goto V_137;
case V_124 :
sin -> V_135 . V_136 = V_7 -> V_69 ;
goto V_137;
case V_127 :
if ( V_116 ) {
V_117 = - V_104 ;
if ( ! V_7 )
break;
V_117 = 0 ;
if ( ! ( V_112 . V_138 & V_50 ) )
F_47 ( V_39 , V_54 , 1 ) ;
break;
}
V_117 = F_99 ( V_17 , V_112 . V_138 ) ;
break;
case V_130 :
V_117 = - V_79 ;
if ( F_87 ( sin -> V_135 . V_136 ) < 0 )
break;
if ( ! V_7 ) {
V_117 = - V_80 ;
V_7 = F_21 () ;
F_80 ( & V_7 -> V_8 ) ;
if ( ! V_7 )
break;
if ( V_116 )
memcpy ( V_7 -> V_101 , V_112 . V_120 , V_107 ) ;
else
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
} else {
V_117 = 0 ;
if ( V_7 -> V_9 == sin -> V_135 . V_136 )
break;
F_47 ( V_39 , V_54 , 0 ) ;
V_7 -> V_106 = 0 ;
V_7 -> V_68 = 0 ;
}
V_7 -> V_70 = V_7 -> V_9 = sin -> V_135 . V_136 ;
if ( ! ( V_17 -> V_49 & V_139 ) ) {
V_7 -> V_103 = F_87 ( V_7 -> V_70 ) ;
V_7 -> V_69 = F_81 ( V_7 -> V_103 ) ;
if ( ( V_17 -> V_49 & V_140 ) &&
V_7 -> V_103 < 31 )
V_7 -> V_106 = V_7 -> V_70 |
~ V_7 -> V_69 ;
} else {
V_7 -> V_103 = 32 ;
V_7 -> V_69 = F_81 ( 32 ) ;
}
V_117 = F_63 ( V_17 , V_7 ) ;
break;
case V_131 :
V_117 = 0 ;
if ( V_7 -> V_106 != sin -> V_135 . V_136 ) {
F_47 ( V_39 , V_54 , 0 ) ;
V_7 -> V_106 = sin -> V_135 . V_136 ;
F_62 ( V_7 ) ;
}
break;
case V_132 :
V_117 = 0 ;
if ( V_7 -> V_70 == sin -> V_135 . V_136 )
break;
V_117 = - V_79 ;
if ( F_87 ( sin -> V_135 . V_136 ) < 0 )
break;
V_117 = 0 ;
F_47 ( V_39 , V_54 , 0 ) ;
V_7 -> V_70 = sin -> V_135 . V_136 ;
F_62 ( V_7 ) ;
break;
case V_133 :
V_117 = - V_79 ;
if ( F_100 ( sin -> V_135 . V_136 , 0 ) )
break;
V_117 = 0 ;
if ( V_7 -> V_69 != sin -> V_135 . V_136 ) {
T_1 V_141 = V_7 -> V_69 ;
F_47 ( V_39 , V_54 , 0 ) ;
V_7 -> V_69 = sin -> V_135 . V_136 ;
V_7 -> V_103 = F_101 ( V_7 -> V_69 ) ;
if ( ( V_17 -> V_49 & V_140 ) &&
( V_7 -> V_103 < 31 ) &&
( V_7 -> V_106 ==
( V_7 -> V_9 | ~ V_141 ) ) ) {
V_7 -> V_106 = ( V_7 -> V_9 |
~ sin -> V_135 . V_136 ) ;
}
F_62 ( V_7 ) ;
}
break;
}
V_134:
F_102 () ;
V_40:
return V_117 ;
V_137:
F_102 () ;
V_117 = F_103 ( V_87 , & V_112 , sizeof( struct V_111 ) ) ? - V_118 : 0 ;
goto V_40;
}
static int F_104 ( struct V_12 * V_17 , char T_4 * V_142 , int V_143 )
{
struct V_29 * V_39 = F_64 ( V_17 ) ;
struct V_6 * V_7 ;
struct V_111 V_112 ;
int V_134 = 0 ;
if ( ! V_39 )
goto V_40;
for ( V_7 = V_39 -> V_34 ; V_7 ; V_7 = V_7 -> V_67 ) {
if ( ! V_142 ) {
V_134 += sizeof( V_112 ) ;
continue;
}
if ( V_143 < ( int ) sizeof( V_112 ) )
break;
memset ( & V_112 , 0 , sizeof( struct V_111 ) ) ;
if ( V_7 -> V_101 )
strcpy ( V_112 . V_120 , V_7 -> V_101 ) ;
else
strcpy ( V_112 . V_120 , V_17 -> V_37 ) ;
( * (struct V_113 * ) & V_112 . V_115 ) . V_125 = V_126 ;
( * (struct V_113 * ) & V_112 . V_115 ) . V_135 . V_136 =
V_7 -> V_9 ;
if ( F_103 ( V_142 , & V_112 , sizeof( struct V_111 ) ) ) {
V_134 = - V_118 ;
break;
}
V_142 += sizeof( struct V_111 ) ;
V_143 -= sizeof( struct V_111 ) ;
V_134 += sizeof( struct V_111 ) ;
}
V_40:
return V_134 ;
}
T_1 F_105 ( const struct V_12 * V_17 , T_1 V_144 , int V_145 )
{
T_1 V_2 = 0 ;
struct V_29 * V_39 ;
struct V_1 * V_1 = F_13 ( V_17 ) ;
F_10 () ;
V_39 = F_106 ( V_17 ) ;
if ( ! V_39 )
goto V_146;
F_51 (in_dev) {
if ( V_7 -> V_68 > V_145 )
continue;
if ( ! V_144 || F_52 ( V_144 , V_7 ) ) {
V_2 = V_7 -> V_9 ;
break;
}
if ( ! V_2 )
V_2 = V_7 -> V_9 ;
} F_53 ( V_39 ) ;
if ( V_2 )
goto V_147;
V_146:
F_107 (net, dev) {
V_39 = F_106 ( V_17 ) ;
if ( ! V_39 )
continue;
F_51 (in_dev) {
if ( V_7 -> V_68 != V_148 &&
V_7 -> V_68 <= V_145 ) {
V_2 = V_7 -> V_9 ;
goto V_147;
}
} F_53 ( V_39 ) ;
}
V_147:
F_18 () ;
return V_2 ;
}
static T_1 F_108 ( struct V_29 * V_39 , T_1 V_144 ,
T_1 V_25 , int V_145 )
{
int V_149 = 0 ;
T_1 V_2 = 0 ;
F_109 (in_dev) {
if ( ! V_2 &&
( V_25 == V_7 -> V_9 || ! V_25 ) &&
V_7 -> V_68 <= V_145 ) {
V_2 = V_7 -> V_9 ;
if ( V_149 )
break;
}
if ( ! V_149 ) {
V_149 = ( ! V_25 || F_52 ( V_25 , V_7 ) ) &&
( ! V_144 || F_52 ( V_144 , V_7 ) ) ;
if ( V_149 && V_2 ) {
if ( V_25 || ! V_144 )
break;
if ( F_52 ( V_2 , V_7 ) )
break;
if ( V_7 -> V_68 <= V_145 ) {
V_2 = V_7 -> V_9 ;
break;
}
V_149 = 0 ;
}
}
} F_53 ( V_39 ) ;
return V_149 ? V_2 : 0 ;
}
T_1 F_110 ( struct V_29 * V_39 ,
T_1 V_144 , T_1 V_25 , int V_145 )
{
T_1 V_2 = 0 ;
struct V_12 * V_17 ;
struct V_1 * V_1 ;
if ( V_145 != V_148 )
return F_108 ( V_39 , V_144 , V_25 , V_145 ) ;
V_1 = F_13 ( V_39 -> V_17 ) ;
F_10 () ;
F_107 (net, dev) {
V_39 = F_106 ( V_17 ) ;
if ( V_39 ) {
V_2 = F_108 ( V_39 , V_144 , V_25 , V_145 ) ;
if ( V_2 )
break;
}
}
F_18 () ;
return V_2 ;
}
int F_111 ( struct V_150 * V_151 )
{
return F_112 ( & V_72 , V_151 ) ;
}
int F_113 ( struct V_150 * V_151 )
{
return F_114 ( & V_72 , V_151 ) ;
}
static void F_115 ( struct V_12 * V_17 , struct V_29 * V_39 )
{
struct V_6 * V_7 ;
int V_152 = 0 ;
for ( V_7 = V_39 -> V_34 ; V_7 ; V_7 = V_7 -> V_67 ) {
char V_153 [ V_107 ] , * V_154 ;
memcpy ( V_153 , V_7 -> V_101 , V_107 ) ;
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
if ( V_152 ++ == 0 )
goto V_155;
V_154 = strchr ( V_153 , ':' ) ;
if ( V_154 == NULL ) {
sprintf ( V_153 , L_4 , V_152 ) ;
V_154 = V_153 ;
}
if ( strlen ( V_154 ) + strlen ( V_17 -> V_37 ) < V_107 )
strcat ( V_7 -> V_101 , V_154 ) ;
else
strcpy ( V_7 -> V_101 + ( V_107 - strlen ( V_154 ) - 1 ) , V_154 ) ;
V_155:
F_56 ( V_75 , V_7 , NULL , 0 ) ;
}
}
static inline bool F_116 ( unsigned V_156 )
{
return V_156 >= 68 ;
}
static void F_117 ( struct V_12 * V_17 ,
struct V_29 * V_39 )
{
struct V_6 * V_7 = V_39 -> V_34 ;
if ( ! V_7 )
return;
F_118 ( V_157 , V_158 ,
V_7 -> V_9 , V_17 ,
V_7 -> V_9 , NULL ,
V_17 -> V_159 , NULL ) ;
}
static int F_119 ( struct V_150 * V_160 , unsigned long V_161 ,
void * V_162 )
{
struct V_12 * V_17 = V_162 ;
struct V_29 * V_39 = F_64 ( V_17 ) ;
F_36 () ;
if ( ! V_39 ) {
if ( V_161 == V_163 ) {
V_39 = F_35 ( V_17 ) ;
if ( ! V_39 )
return F_120 ( - V_164 ) ;
if ( V_17 -> V_49 & V_165 ) {
F_121 ( V_39 , V_166 , 1 ) ;
F_121 ( V_39 , V_167 , 1 ) ;
}
} else if ( V_161 == V_168 ) {
if ( F_116 ( V_17 -> V_156 ) )
V_39 = F_35 ( V_17 ) ;
}
goto V_40;
}
switch ( V_161 ) {
case V_163 :
F_32 ( V_36 L_5 ) ;
F_43 ( V_17 -> V_51 , NULL ) ;
break;
case V_76 :
if ( ! F_116 ( V_17 -> V_156 ) )
break;
if ( V_17 -> V_49 & V_165 ) {
struct V_6 * V_7 = F_21 () ;
if ( V_7 ) {
F_80 ( & V_7 -> V_8 ) ;
V_7 -> V_9 =
V_7 -> V_70 = F_122 ( V_169 ) ;
V_7 -> V_103 = 8 ;
V_7 -> V_69 = F_81 ( 8 ) ;
F_40 ( V_39 ) ;
V_7 -> V_18 = V_39 ;
V_7 -> V_68 = V_81 ;
memcpy ( V_7 -> V_101 , V_17 -> V_37 , V_107 ) ;
F_62 ( V_7 ) ;
}
}
F_42 ( V_39 ) ;
case V_170 :
if ( ! F_123 ( V_39 ) )
break;
case V_171 :
F_117 ( V_17 , V_39 ) ;
break;
case V_73 :
F_124 ( V_39 ) ;
break;
case V_172 :
F_125 ( V_39 ) ;
break;
case V_173 :
F_126 ( V_39 ) ;
break;
case V_168 :
if ( F_116 ( V_17 -> V_156 ) )
break;
case V_174 :
F_45 ( V_39 ) ;
break;
case V_175 :
F_115 ( V_17 , V_39 ) ;
F_20 ( V_39 ) ;
F_19 ( V_39 ) ;
break;
}
V_40:
return V_176 ;
}
static inline T_5 F_127 ( void )
{
return F_128 ( sizeof( struct V_92 ) )
+ F_129 ( 4 )
+ F_129 ( 4 )
+ F_129 ( 4 )
+ F_129 ( V_107 ) ;
}
static int F_130 ( struct V_85 * V_86 , struct V_6 * V_7 ,
T_2 V_58 , T_2 V_177 , int V_161 , unsigned int V_49 )
{
struct V_92 * V_93 ;
struct V_56 * V_57 ;
V_57 = F_131 ( V_86 , V_58 , V_177 , V_161 , sizeof( * V_93 ) , V_49 ) ;
if ( V_57 == NULL )
return - V_178 ;
V_93 = F_74 ( V_57 ) ;
V_93 -> V_179 = V_126 ;
V_93 -> V_103 = V_7 -> V_103 ;
V_93 -> V_64 = V_7 -> V_64 | V_180 ;
V_93 -> V_68 = V_7 -> V_68 ;
V_93 -> V_97 = V_7 -> V_18 -> V_17 -> V_82 ;
if ( V_7 -> V_70 )
F_132 ( V_86 , V_102 , V_7 -> V_70 ) ;
if ( V_7 -> V_9 )
F_132 ( V_86 , V_99 , V_7 -> V_9 ) ;
if ( V_7 -> V_106 )
F_132 ( V_86 , V_105 , V_7 -> V_106 ) ;
if ( V_7 -> V_101 [ 0 ] )
F_133 ( V_86 , V_100 , V_7 -> V_101 ) ;
return F_134 ( V_86 , V_57 ) ;
V_181:
F_135 ( V_86 , V_57 ) ;
return - V_178 ;
}
static int F_136 ( struct V_85 * V_86 , struct V_182 * V_183 )
{
struct V_1 * V_1 = F_72 ( V_86 -> V_88 ) ;
int V_184 , V_185 ;
int V_186 , V_187 ;
int V_188 , V_189 ;
struct V_12 * V_17 ;
struct V_29 * V_39 ;
struct V_6 * V_7 ;
struct V_190 * V_33 ;
struct V_15 * V_16 ;
V_185 = V_183 -> args [ 0 ] ;
V_187 = V_186 = V_183 -> args [ 1 ] ;
V_189 = V_188 = V_183 -> args [ 2 ] ;
for ( V_184 = V_185 ; V_184 < V_191 ; V_184 ++ , V_187 = 0 ) {
V_186 = 0 ;
V_33 = & V_1 -> V_192 [ V_184 ] ;
F_10 () ;
F_11 (dev, node, head, index_hlist) {
if ( V_186 < V_187 )
goto V_193;
if ( V_184 > V_185 || V_186 > V_187 )
V_189 = 0 ;
V_39 = F_106 ( V_17 ) ;
if ( ! V_39 )
goto V_193;
for ( V_7 = V_39 -> V_34 , V_188 = 0 ; V_7 ;
V_7 = V_7 -> V_67 , V_188 ++ ) {
if ( V_188 < V_189 )
continue;
if ( F_130 ( V_86 , V_7 ,
F_77 ( V_183 -> V_86 ) . V_58 ,
V_183 -> V_57 -> V_194 ,
V_75 , V_195 ) <= 0 ) {
F_18 () ;
goto V_134;
}
}
V_193:
V_186 ++ ;
}
F_18 () ;
}
V_134:
V_183 -> args [ 0 ] = V_184 ;
V_183 -> args [ 1 ] = V_186 ;
V_183 -> args [ 2 ] = V_188 ;
return V_86 -> V_143 ;
}
static void F_56 ( int V_161 , struct V_6 * V_7 , struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_85 * V_86 ;
T_2 V_177 = V_57 ? V_57 -> V_194 : 0 ;
int V_94 = - V_80 ;
struct V_1 * V_1 ;
V_1 = F_13 ( V_7 -> V_18 -> V_17 ) ;
V_86 = F_137 ( F_127 () , V_31 ) ;
if ( V_86 == NULL )
goto V_96;
V_94 = F_130 ( V_86 , V_7 , V_58 , V_177 , V_161 , 0 ) ;
if ( V_94 < 0 ) {
F_30 ( V_94 == - V_178 ) ;
F_138 ( V_86 ) ;
goto V_96;
}
F_139 ( V_86 , V_1 , V_58 , V_196 , V_57 , V_31 ) ;
return;
V_96:
if ( V_94 < 0 )
F_140 ( V_1 , V_196 , V_94 ) ;
}
static T_5 F_141 ( const struct V_12 * V_17 )
{
struct V_29 * V_39 = F_69 ( V_17 -> V_51 ) ;
if ( ! V_39 )
return 0 ;
return F_129 ( V_197 * 4 ) ;
}
static int F_142 ( struct V_85 * V_86 , const struct V_12 * V_17 )
{
struct V_29 * V_39 = F_69 ( V_17 -> V_51 ) ;
struct V_89 * V_198 ;
int V_199 ;
if ( ! V_39 )
return - V_200 ;
V_198 = F_143 ( V_86 , V_201 , V_197 * 4 ) ;
if ( V_198 == NULL )
return - V_178 ;
for ( V_199 = 0 ; V_199 < V_197 ; V_199 ++ )
( ( T_2 * ) F_144 ( V_198 ) ) [ V_199 ] = V_39 -> V_41 . V_202 [ V_199 ] ;
return 0 ;
}
static int F_145 ( const struct V_12 * V_17 ,
const struct V_89 * V_198 )
{
struct V_89 * V_52 , * V_90 [ V_203 + 1 ] ;
int V_94 , V_204 ;
if ( V_17 && ! F_64 ( V_17 ) )
return - V_205 ;
V_94 = F_146 ( V_90 , V_203 , V_198 , V_206 ) ;
if ( V_94 < 0 )
return V_94 ;
if ( V_90 [ V_201 ] ) {
F_147 (a, tb[IFLA_INET_CONF], rem) {
int V_207 = F_148 ( V_52 ) ;
if ( F_149 ( V_52 ) < 4 )
return - V_79 ;
if ( V_207 <= 0 || V_207 > V_197 )
return - V_79 ;
}
}
return 0 ;
}
static int F_150 ( struct V_12 * V_17 , const struct V_89 * V_198 )
{
struct V_29 * V_39 = F_64 ( V_17 ) ;
struct V_89 * V_52 , * V_90 [ V_203 + 1 ] ;
int V_204 ;
if ( ! V_39 )
return - V_205 ;
if ( F_146 ( V_90 , V_203 , V_198 , NULL ) < 0 )
F_151 () ;
if ( V_90 [ V_201 ] ) {
F_147 (a, tb[IFLA_INET_CONF], rem)
F_152 ( V_39 , F_148 ( V_52 ) , F_153 ( V_52 ) ) ;
}
return 0 ;
}
static void F_154 ( struct V_1 * V_1 , int V_199 )
{
struct V_12 * V_17 ;
F_10 () ;
F_107 (net, dev) {
struct V_29 * V_39 ;
V_39 = F_106 ( V_17 ) ;
if ( V_39 && ! F_155 ( V_199 , V_39 -> V_41 . V_208 ) )
V_39 -> V_41 . V_202 [ V_199 ] = V_1 -> V_42 . V_43 -> V_202 [ V_199 ] ;
}
F_18 () ;
}
static void F_156 ( struct V_1 * V_1 )
{
struct V_12 * V_17 ;
int V_209 = F_157 ( V_1 , V_48 ) ;
F_157 ( V_1 , V_210 ) = ! V_209 ;
F_158 ( V_1 , V_48 ) = V_209 ;
F_159 (net, dev) {
struct V_29 * V_39 ;
if ( V_209 )
F_39 ( V_17 ) ;
F_10 () ;
V_39 = F_106 ( V_17 ) ;
if ( V_39 )
F_121 ( V_39 , V_48 , V_209 ) ;
F_18 () ;
}
}
static int F_160 ( T_6 * V_211 , int V_212 ,
void T_4 * V_213 ,
T_5 * V_214 , T_7 * V_215 )
{
int V_117 = F_161 ( V_211 , V_212 , V_213 , V_214 , V_215 ) ;
if ( V_212 ) {
struct V_216 * V_41 = V_211 -> V_217 ;
struct V_1 * V_1 = V_211 -> V_218 ;
int V_199 = ( int * ) V_211 -> V_202 - V_41 -> V_202 ;
F_162 ( V_199 , V_41 -> V_208 ) ;
if ( V_41 == V_1 -> V_42 . V_43 )
F_154 ( V_1 , V_199 ) ;
}
return V_117 ;
}
static int F_163 ( T_6 * V_211 , int V_212 ,
void T_4 * V_213 ,
T_5 * V_214 , T_7 * V_215 )
{
int * V_219 = V_211 -> V_202 ;
int V_3 = * V_219 ;
T_7 V_220 = * V_215 ;
int V_117 = F_161 ( V_211 , V_212 , V_213 , V_214 , V_215 ) ;
if ( V_212 && * V_219 != V_3 ) {
struct V_1 * V_1 = V_211 -> V_218 ;
if ( V_219 != & F_158 ( V_1 , V_48 ) ) {
if ( ! F_164 () ) {
* V_219 = V_3 ;
* V_215 = V_220 ;
return F_165 () ;
}
if ( V_219 == & F_157 ( V_1 , V_48 ) ) {
F_156 ( V_1 ) ;
} else if ( * V_219 ) {
struct V_216 * V_41 = V_211 -> V_217 ;
struct V_29 * V_30 =
F_24 ( V_41 , struct V_29 , V_41 ) ;
F_39 ( V_30 -> V_17 ) ;
}
F_102 () ;
F_166 ( V_1 , 0 ) ;
}
}
return V_117 ;
}
static int F_167 ( T_6 * V_211 , int V_212 ,
void T_4 * V_213 ,
T_5 * V_214 , T_7 * V_215 )
{
int * V_219 = V_211 -> V_202 ;
int V_3 = * V_219 ;
int V_117 = F_161 ( V_211 , V_212 , V_213 , V_214 , V_215 ) ;
struct V_1 * V_1 = V_211 -> V_218 ;
if ( V_212 && * V_219 != V_3 )
F_166 ( V_1 , 0 ) ;
return V_117 ;
}
static int F_168 ( struct V_1 * V_1 , char * V_221 ,
struct V_216 * V_222 )
{
int V_199 ;
struct V_223 * V_224 ;
#define F_169 3
struct V_225 V_226 [] = {
{ . V_227 = L_6 , } ,
{ . V_227 = L_7 , } ,
{ . V_227 = L_8 , } ,
{ } ,
{ } ,
} ;
V_224 = F_170 ( & V_228 , sizeof( * V_224 ) , V_31 ) ;
if ( ! V_224 )
goto V_40;
for ( V_199 = 0 ; V_199 < F_171 ( V_224 -> V_229 ) - 1 ; V_199 ++ ) {
V_224 -> V_229 [ V_199 ] . V_202 += ( char * ) V_222 - ( char * ) & V_216 ;
V_224 -> V_229 [ V_199 ] . V_217 = V_222 ;
V_224 -> V_229 [ V_199 ] . V_218 = V_1 ;
}
V_224 -> V_221 = F_172 ( V_221 , V_31 ) ;
if ( ! V_224 -> V_221 )
goto free;
V_226 [ F_169 ] . V_227 = V_224 -> V_221 ;
V_224 -> V_230 = F_173 ( V_1 , V_226 ,
V_224 -> V_229 ) ;
if ( ! V_224 -> V_230 )
goto V_231;
V_222 -> V_44 = V_224 ;
return 0 ;
V_231:
F_26 ( V_224 -> V_221 ) ;
free:
F_26 ( V_224 ) ;
V_40:
return - V_80 ;
}
static void F_174 ( struct V_216 * V_41 )
{
struct V_223 * V_224 = V_41 -> V_44 ;
if ( V_224 == NULL )
return;
V_41 -> V_44 = NULL ;
F_175 ( V_224 -> V_230 ) ;
F_26 ( V_224 -> V_221 ) ;
F_26 ( V_224 ) ;
}
static void F_19 ( struct V_29 * V_30 )
{
F_176 ( V_30 -> V_17 , V_30 -> V_45 , L_7 , NULL ) ;
F_168 ( F_13 ( V_30 -> V_17 ) , V_30 -> V_17 -> V_37 ,
& V_30 -> V_41 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
F_174 ( & V_30 -> V_41 ) ;
F_177 ( V_30 -> V_45 ) ;
}
static T_8 int F_178 ( struct V_1 * V_1 )
{
int V_94 ;
struct V_216 * V_232 , * V_233 ;
#ifdef F_179
struct T_6 * V_234 = V_235 ;
struct V_236 * V_237 ;
#endif
V_94 = - V_164 ;
V_232 = & V_216 ;
V_233 = & V_238 ;
if ( ! F_12 ( V_1 , & V_239 ) ) {
V_232 = F_170 ( V_232 , sizeof( V_216 ) , V_31 ) ;
if ( V_232 == NULL )
goto V_240;
V_233 = F_170 ( V_233 , sizeof( V_238 ) , V_31 ) ;
if ( V_233 == NULL )
goto V_241;
#ifdef F_179
V_234 = F_170 ( V_234 , sizeof( V_235 ) , V_31 ) ;
if ( V_234 == NULL )
goto V_242;
V_234 [ 0 ] . V_202 = & V_232 -> V_202 [ V_243 - 1 ] ;
V_234 [ 0 ] . V_217 = V_232 ;
V_234 [ 0 ] . V_218 = V_1 ;
#endif
}
#ifdef F_179
V_94 = F_168 ( V_1 , L_9 , V_232 ) ;
if ( V_94 < 0 )
goto V_244;
V_94 = F_168 ( V_1 , L_10 , V_233 ) ;
if ( V_94 < 0 )
goto V_245;
V_94 = - V_164 ;
V_237 = F_173 ( V_1 , V_246 , V_234 ) ;
if ( V_237 == NULL )
goto V_247;
V_1 -> V_42 . V_237 = V_237 ;
#endif
V_1 -> V_42 . V_248 = V_232 ;
V_1 -> V_42 . V_43 = V_233 ;
return 0 ;
#ifdef F_179
V_247:
F_174 ( V_233 ) ;
V_245:
F_174 ( V_232 ) ;
V_244:
if ( V_234 != V_235 )
F_26 ( V_234 ) ;
V_242:
#endif
if ( V_233 != & V_238 )
F_26 ( V_233 ) ;
V_241:
if ( V_232 != & V_216 )
F_26 ( V_232 ) ;
V_240:
return V_94 ;
}
static T_9 void F_180 ( struct V_1 * V_1 )
{
#ifdef F_179
struct T_6 * V_234 ;
V_234 = V_1 -> V_42 . V_237 -> V_249 ;
F_175 ( V_1 -> V_42 . V_237 ) ;
F_174 ( V_1 -> V_42 . V_43 ) ;
F_174 ( V_1 -> V_42 . V_248 ) ;
F_26 ( V_234 ) ;
#endif
F_26 ( V_1 -> V_42 . V_43 ) ;
F_26 ( V_1 -> V_42 . V_248 ) ;
}
void T_10 F_181 ( void )
{
int V_199 ;
for ( V_199 = 0 ; V_199 < V_5 ; V_199 ++ )
F_182 ( & V_11 [ V_199 ] ) ;
F_183 ( & V_250 ) ;
F_184 ( V_251 , F_104 ) ;
F_185 ( & V_252 ) ;
F_186 ( & V_253 ) ;
F_187 ( V_251 , V_75 , F_84 , NULL ) ;
F_187 ( V_251 , V_71 , F_71 , NULL ) ;
F_187 ( V_251 , V_254 , NULL , F_136 ) ;
}
