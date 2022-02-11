int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 ( V_5 , & V_4 -> V_6 ) ;
if ( F_6 ( V_2 , 1 ) ) {
if ( ! F_7 ( V_7 , & V_4 -> V_6 ) )
return 0 ;
goto V_8;
}
if ( F_8 ( V_2 ) )
goto V_9;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) ) {
struct V_3 * V_11 ;
F_9 ( & V_4 -> V_12 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_11 -> V_2 -> V_6 ;
if ( V_6 & V_13 )
continue;
F_11 ( V_11 -> V_2 , V_6 | V_13 ) ;
}
F_12 ( & V_4 -> V_12 ) ;
}
F_13 ( V_2 ) ;
return 0 ;
V_9:
F_14 ( V_2 , 1 ) ;
V_8:
F_15 ( V_5 , & V_4 -> V_6 ) ;
return - V_14 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_2 ) ;
F_15 ( V_5 , & V_4 -> V_6 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) ) {
struct V_3 * V_11 ;
F_9 ( & V_4 -> V_12 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_11 -> V_2 -> V_6 ;
if ( ! ( V_6 & V_13 ) )
continue;
F_11 ( V_11 -> V_2 , V_6 & ~ V_13 ) ;
}
F_12 ( & V_4 -> V_12 ) ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_7 ( V_16 , & V_4 -> V_6 ) )
V_15 &= ~ ( V_17 | V_18 | V_19 ) ;
return V_15 ;
}
static int F_22 ( struct V_1 * V_2 , int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
if ( V_20 > F_24 ( V_2 ) )
return - V_14 ;
if ( V_20 > V_4 -> V_21 )
F_25 ( V_4 , L_3 ,
V_4 -> V_21 ) ;
V_2 -> V_22 = V_20 ;
return 0 ;
}
if ( V_20 > F_26 ( V_4 -> V_23 ) )
return - V_14 ;
V_4 -> V_24 = V_20 ;
V_2 -> V_22 = F_27 ( V_4 -> V_21 , V_4 -> V_24 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , const char * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_29 ( V_2 -> V_26 ) && ! strcmp ( V_25 , L_4 ) ) {
F_5 ( V_16 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_5
L_6 ) ;
F_30 ( V_2 ) ;
F_31 () ;
V_4 -> V_27 . V_28 &= ~ V_29 ;
F_32 ( V_2 ) ;
F_33 () ;
return 0 ;
}
if ( ! strcmp ( V_25 , L_7 ) ) {
F_15 ( V_16 , & V_4 -> V_6 ) ;
F_30 ( V_2 ) ;
F_34 ( V_2 , F_27 ( V_4 -> V_21 , V_2 -> V_22 ) ) ;
F_31 () ;
F_32 ( V_2 ) ;
F_33 () ;
return 0 ;
}
return - V_14 ;
}
static struct V_30 * F_35 ( struct V_1 * V_2 , void * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 * V_33 = V_4 -> V_34 . V_32 ;
struct V_30 * V_35 ;
int V_36 ;
while ( V_33 ) {
V_35 = F_36 ( V_33 , struct V_30 , V_32 ) ;
V_36 = memcmp ( V_31 , V_35 -> V_37 . V_38 . V_39 ,
sizeof ( union V_40 ) ) ;
if ( V_36 < 0 )
V_33 = V_33 -> V_41 ;
else if ( V_36 > 0 )
V_33 = V_33 -> V_42 ;
else
return V_35 ;
}
return NULL ;
}
static int F_37 ( struct V_1 * V_2 , struct V_30 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_32 * * V_33 = & V_4 -> V_34 . V_32 ;
struct V_32 * V_43 = NULL ;
struct V_30 * V_44 ;
int V_36 ;
while ( * V_33 ) {
V_43 = * V_33 ;
V_44 = F_36 ( V_43 , struct V_30 , V_32 ) ;
V_36 = memcmp ( V_35 -> V_37 . V_38 . V_39 , V_44 -> V_37 . V_38 . V_39 ,
sizeof ( union V_40 ) ) ;
if ( V_36 < 0 )
V_33 = & V_43 -> V_41 ;
else if ( V_36 > 0 )
V_33 = & V_43 -> V_42 ;
else
return - V_45 ;
}
F_38 ( & V_35 -> V_32 , V_43 , V_33 ) ;
F_39 ( & V_35 -> V_32 , & V_4 -> V_34 ) ;
F_40 ( & V_35 -> V_46 , & V_4 -> V_47 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_30 * V_35 )
{
struct V_48 * V_49 ;
while ( ( V_49 = F_42 ( & V_35 -> V_50 ) ) )
F_43 ( V_49 ) ;
F_3 ( F_2 ( V_2 ) , L_8 ) ;
F_44 ( V_2 , V_35 -> V_37 . V_38 . V_39 ) ;
if ( V_35 -> V_51 )
F_45 ( V_35 -> V_51 ) ;
F_46 ( V_35 ) ;
}
struct V_52 * F_47 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
V_53 = F_48 ( sizeof *V_53 , V_54 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_2 = V_2 ;
memset ( V_53 -> V_35 . V_37 . V_38 . V_39 , 0 , 16 ) ;
if ( F_49 ( V_53 ) ) {
F_46 ( V_53 ) ;
return NULL ;
}
return V_53 ;
}
int F_49 ( struct V_52 * V_53 )
{
struct V_3 * V_4 = F_2 ( V_53 -> V_2 ) ;
struct V_32 * V_33 ;
struct V_30 * V_35 ;
int V_36 = 1 ;
F_50 ( & V_4 -> V_55 ) ;
V_33 = F_51 ( & V_4 -> V_34 ) ;
while ( V_33 ) {
V_35 = F_36 ( V_33 , struct V_30 , V_32 ) ;
if ( memcmp ( V_53 -> V_35 . V_37 . V_38 . V_39 , V_35 -> V_37 . V_38 . V_39 ,
sizeof ( union V_40 ) ) < 0 ) {
V_53 -> V_35 = * V_35 ;
V_36 = 0 ;
break;
}
V_33 = F_52 ( V_33 ) ;
}
F_53 ( & V_4 -> V_55 ) ;
return V_36 ;
}
void F_54 ( struct V_52 * V_53 ,
struct V_30 * V_35 )
{
* V_35 = V_53 -> V_35 ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_35 , * V_56 ;
F_50 ( & V_4 -> V_55 ) ;
F_56 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_9 ,
F_57 ( V_35 -> V_37 . V_57 ) ,
V_35 -> V_37 . V_38 . V_39 ) ;
V_35 -> V_58 = 0 ;
}
F_53 ( & V_4 -> V_55 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_35 , * V_56 ;
F_58 ( V_59 ) ;
unsigned long V_6 ;
F_59 ( V_2 ) ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
F_61 ( & V_4 -> V_47 , & V_59 ) ;
F_10 (path, &remove_list, list)
F_62 ( & V_35 -> V_32 , & V_4 -> V_34 ) ;
F_56 (path, tp, &remove_list, list) {
if ( V_35 -> V_60 )
F_63 ( V_35 -> V_61 , V_35 -> V_60 ) ;
F_64 ( & V_4 -> V_55 , V_6 ) ;
F_65 ( V_2 ) ;
F_66 ( & V_35 -> V_62 ) ;
F_41 ( V_2 , V_35 ) ;
F_59 ( V_2 ) ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
}
F_64 ( & V_4 -> V_55 , V_6 ) ;
F_65 ( V_2 ) ;
}
static void F_67 ( int V_63 ,
struct V_64 * V_37 ,
void * V_65 )
{
struct V_30 * V_35 = V_65 ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_66 * V_51 = NULL ;
struct V_66 * V_67 = NULL ;
struct V_68 * V_69 , * V_70 ;
struct V_71 V_72 ;
struct V_48 * V_49 ;
unsigned long V_6 ;
if ( ! V_63 )
F_3 ( V_4 , L_10 ,
F_57 ( V_37 -> V_57 ) , V_37 -> V_38 . V_39 ) ;
else
F_3 ( V_4 , L_11 ,
V_63 , V_35 -> V_37 . V_38 . V_39 ) ;
F_68 ( & V_72 ) ;
if ( ! V_63 ) {
struct V_73 V_74 ;
if ( ! F_69 ( V_4 -> V_75 , V_4 -> V_76 , V_37 , & V_74 ) )
V_51 = F_70 ( V_2 , V_4 -> V_77 , & V_74 ) ;
}
F_60 ( & V_4 -> V_55 , V_6 ) ;
if ( ! F_71 ( V_51 ) ) {
V_35 -> V_37 = * V_37 ;
V_67 = V_35 -> V_51 ;
V_35 -> V_51 = V_51 ;
F_3 ( V_4 , L_12 ,
V_51 , F_57 ( V_37 -> V_57 ) , V_37 -> V_78 ) ;
while ( ( V_49 = F_42 ( & V_35 -> V_50 ) ) )
F_72 ( & V_72 , V_49 ) ;
F_56 (neigh, tn, &path->neigh_list, list) {
if ( V_69 -> V_51 ) {
F_73 ( V_69 -> V_51 != V_67 ) ;
F_45 ( V_69 -> V_51 ) ;
}
F_74 ( & V_35 -> V_51 -> V_79 ) ;
V_69 -> V_51 = V_35 -> V_51 ;
if ( F_75 ( V_2 , V_69 -> V_80 ) ) {
if ( ! F_76 ( V_69 ) )
F_77 ( V_69 , F_78 ( V_2 ,
V_35 ,
V_69 ) ) ;
if ( ! F_76 ( V_69 ) ) {
F_79 ( V_69 ) ;
continue;
}
}
while ( ( V_49 = F_42 ( & V_69 -> V_50 ) ) )
F_72 ( & V_72 , V_49 ) ;
}
V_35 -> V_58 = 1 ;
}
V_35 -> V_60 = NULL ;
F_80 ( & V_35 -> V_62 ) ;
F_64 ( & V_4 -> V_55 , V_6 ) ;
if ( F_71 ( V_51 ) )
F_44 ( V_2 , V_35 -> V_37 . V_38 . V_39 ) ;
if ( V_67 )
F_45 ( V_67 ) ;
while ( ( V_49 = F_42 ( & V_72 ) ) ) {
V_49 -> V_2 = V_2 ;
if ( F_81 ( V_49 ) )
F_25 ( V_4 , L_13
L_14 ) ;
}
}
static struct V_30 * F_82 ( struct V_1 * V_2 , void * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_35 ;
if ( ! V_4 -> V_81 )
return NULL ;
V_35 = F_83 ( sizeof *V_35 , V_82 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_2 = V_2 ;
F_68 ( & V_35 -> V_50 ) ;
F_84 ( & V_35 -> V_83 ) ;
memcpy ( V_35 -> V_37 . V_38 . V_39 , V_31 , sizeof ( union V_40 ) ) ;
V_35 -> V_37 . V_84 = V_4 -> V_85 ;
V_35 -> V_37 . V_86 = F_85 ( V_4 -> V_86 ) ;
V_35 -> V_37 . V_87 = 1 ;
V_35 -> V_37 . V_88 = V_4 -> V_81 -> V_89 . V_88 ;
return V_35 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_30 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_15 ,
V_35 -> V_37 . V_38 . V_39 ) ;
F_87 ( & V_35 -> V_62 ) ;
V_35 -> V_61 =
F_88 ( & V_90 , V_4 -> V_75 , V_4 -> V_76 ,
& V_35 -> V_37 ,
V_91 |
V_92 |
V_93 |
V_94 |
V_95 ,
1000 , V_82 ,
F_67 ,
V_35 , & V_35 -> V_60 ) ;
if ( V_35 -> V_61 < 0 ) {
F_25 ( V_4 , L_16 , V_35 -> V_61 ) ;
V_35 -> V_60 = NULL ;
F_80 ( & V_35 -> V_62 ) ;
return V_35 -> V_61 ;
}
return 0 ;
}
static void F_89 ( struct V_48 * V_49 , T_2 * V_80 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_35 ;
struct V_68 * V_69 ;
unsigned long V_6 ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_69 = F_90 ( V_80 , V_2 ) ;
if ( ! V_69 ) {
F_64 ( & V_4 -> V_55 , V_6 ) ;
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
return;
}
V_35 = F_35 ( V_2 , V_80 + 4 ) ;
if ( ! V_35 ) {
V_35 = F_82 ( V_2 , V_80 + 4 ) ;
if ( ! V_35 )
goto V_98;
F_37 ( V_2 , V_35 ) ;
}
F_40 ( & V_69 -> V_46 , & V_35 -> V_83 ) ;
if ( V_35 -> V_51 ) {
F_74 ( & V_35 -> V_51 -> V_79 ) ;
V_69 -> V_51 = V_35 -> V_51 ;
if ( F_75 ( V_2 , V_69 -> V_80 ) ) {
if ( ! F_76 ( V_69 ) )
F_77 ( V_69 , F_78 ( V_2 , V_35 , V_69 ) ) ;
if ( ! F_76 ( V_69 ) ) {
F_79 ( V_69 ) ;
goto V_99;
}
if ( F_92 ( & V_69 -> V_50 ) < V_100 )
F_72 ( & V_69 -> V_50 , V_49 ) ;
else {
F_25 ( V_4 , L_17 ,
F_92 ( & V_69 -> V_50 ) ) ;
goto V_99;
}
} else {
F_64 ( & V_4 -> V_55 , V_6 ) ;
F_93 ( V_2 , V_49 , V_35 -> V_51 , F_94 ( V_80 ) ) ;
F_95 ( V_69 ) ;
return;
}
} else {
V_69 -> V_51 = NULL ;
if ( ! V_35 -> V_60 && F_86 ( V_2 , V_35 ) )
goto V_98;
F_72 ( & V_69 -> V_50 , V_49 ) ;
}
F_64 ( & V_4 -> V_55 , V_6 ) ;
F_95 ( V_69 ) ;
return;
V_98:
F_79 ( V_69 ) ;
V_99:
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
F_64 ( & V_4 -> V_55 , V_6 ) ;
F_95 ( V_69 ) ;
}
static void F_96 ( struct V_48 * V_49 , struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_35 ;
unsigned long V_6 ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_35 = F_35 ( V_2 , V_102 -> V_103 + 4 ) ;
if ( ! V_35 || ! V_35 -> V_58 ) {
int V_104 = 0 ;
if ( ! V_35 ) {
V_35 = F_82 ( V_2 , V_102 -> V_103 + 4 ) ;
V_104 = 1 ;
}
if ( V_35 ) {
F_72 ( & V_35 -> V_50 , V_49 ) ;
if ( ! V_35 -> V_60 && F_86 ( V_2 , V_35 ) ) {
F_64 ( & V_4 -> V_55 , V_6 ) ;
if ( V_104 )
F_41 ( V_2 , V_35 ) ;
return;
} else
F_37 ( V_2 , V_35 ) ;
} else {
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
}
F_64 ( & V_4 -> V_55 , V_6 ) ;
return;
}
if ( V_35 -> V_51 ) {
F_3 ( V_4 , L_18 ,
F_57 ( V_35 -> V_37 . V_57 ) ) ;
F_64 ( & V_4 -> V_55 , V_6 ) ;
F_93 ( V_2 , V_49 , V_35 -> V_51 , F_94 ( V_102 -> V_103 ) ) ;
return;
} else if ( ( V_35 -> V_60 || ! F_86 ( V_2 , V_35 ) ) &&
F_92 ( & V_35 -> V_50 ) < V_100 ) {
F_72 ( & V_35 -> V_50 , V_49 ) ;
} else {
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
}
F_64 ( & V_4 -> V_55 , V_6 ) ;
}
static int F_97 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_68 * V_69 ;
struct V_101 * V_102 = F_98 ( V_49 ) ;
struct V_105 * V_106 ;
unsigned long V_6 ;
V_106 = (struct V_105 * ) V_49 -> V_107 ;
if ( F_99 ( V_102 -> V_103 [ 4 ] == 0xff ) ) {
if ( ( V_106 -> V_108 != F_100 ( V_109 ) ) &&
( V_106 -> V_108 != F_100 ( V_110 ) ) &&
( V_106 -> V_108 != F_100 ( V_111 ) ) &&
( V_106 -> V_108 != F_100 ( V_112 ) ) &&
( V_106 -> V_108 != F_100 ( V_113 ) ) ) {
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
return V_114 ;
}
V_102 -> V_103 [ 8 ] = ( V_4 -> V_86 >> 8 ) & 0xff ;
V_102 -> V_103 [ 9 ] = V_4 -> V_86 & 0xff ;
V_69 = F_101 ( V_2 , V_102 -> V_103 ) ;
if ( F_102 ( V_69 ) )
goto V_115;
F_103 ( V_2 , V_102 -> V_103 , V_49 ) ;
return V_114 ;
}
switch ( V_106 -> V_108 ) {
case F_100 ( V_109 ) :
case F_100 ( V_110 ) :
case F_100 ( V_113 ) :
V_69 = F_101 ( V_2 , V_102 -> V_103 ) ;
if ( F_99 ( ! V_69 ) ) {
F_89 ( V_49 , V_102 -> V_103 , V_2 ) ;
return V_114 ;
}
break;
case F_100 ( V_111 ) :
case F_100 ( V_112 ) :
F_96 ( V_49 , V_2 , V_102 ) ;
return V_114 ;
default:
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
return V_114 ;
}
V_115:
if ( F_76 ( V_69 ) ) {
if ( F_104 ( V_69 ) ) {
F_105 ( V_2 , V_49 , F_76 ( V_69 ) ) ;
goto V_116;
}
} else if ( V_69 -> V_51 ) {
F_93 ( V_2 , V_49 , V_69 -> V_51 , F_94 ( V_102 -> V_103 ) ) ;
goto V_116;
}
if ( F_92 ( & V_69 -> V_50 ) < V_100 ) {
F_60 ( & V_4 -> V_55 , V_6 ) ;
F_72 ( & V_69 -> V_50 , V_49 ) ;
F_64 ( & V_4 -> V_55 , V_6 ) ;
} else {
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
}
V_116:
F_95 ( V_69 ) ;
return V_114 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 , L_19 ,
F_107 ( V_117 - V_2 -> V_118 ) ) ;
F_25 ( V_4 , L_20 ,
F_108 ( V_2 ) ,
V_4 -> V_119 , V_4 -> V_120 ) ;
}
static int F_109 ( struct V_48 * V_49 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_80 , const void * V_121 , unsigned V_122 )
{
struct V_105 * V_106 ;
struct V_101 * V_102 = F_98 ( V_49 ) ;
V_106 = (struct V_105 * ) F_110 ( V_49 , sizeof *V_106 ) ;
V_106 -> V_108 = F_100 ( type ) ;
V_106 -> V_123 = 0 ;
memcpy ( V_102 -> V_103 , V_80 , V_124 ) ;
return sizeof *V_106 ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_125 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_21 ) ;
return;
}
F_112 ( V_126 , & V_4 -> V_127 ) ;
}
static T_3 F_113 ( struct V_128 * V_129 , T_2 * V_80 )
{
T_3 * V_130 = ( T_3 * ) V_80 ;
T_3 V_131 ;
V_131 = F_114 ( V_130 [ 3 ] , V_130 [ 4 ] , V_132 & V_130 [ 0 ] , 0 ) ;
return V_131 & V_129 -> V_133 ;
}
struct V_68 * F_101 ( struct V_1 * V_2 , T_2 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_134 * V_135 = & V_4 -> V_135 ;
struct V_128 * V_129 ;
struct V_68 * V_69 = NULL ;
T_3 V_136 ;
F_115 () ;
V_129 = F_116 ( V_135 -> V_129 ) ;
if ( ! V_129 )
goto V_137;
V_136 = F_113 ( V_129 , V_80 ) ;
for ( V_69 = F_116 ( V_129 -> V_138 [ V_136 ] ) ;
V_69 != NULL ;
V_69 = F_116 ( V_69 -> V_139 ) ) {
if ( memcmp ( V_80 , V_69 -> V_80 , V_124 ) == 0 ) {
if ( ! F_117 ( & V_69 -> V_140 ) ) {
V_69 = NULL ;
goto V_137;
}
V_69 -> V_141 = V_117 ;
goto V_137;
}
}
V_137:
F_118 () ;
return V_69 ;
}
static void F_119 ( struct V_3 * V_4 )
{
struct V_134 * V_135 = & V_4 -> V_135 ;
struct V_128 * V_129 ;
unsigned long V_142 ;
unsigned long V_143 ;
unsigned long V_6 ;
int V_144 ;
if ( F_7 ( V_145 , & V_4 -> V_6 ) )
return;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_129 = F_120 ( V_135 -> V_129 ,
F_121 ( & V_4 -> V_55 ) ) ;
if ( ! V_129 )
goto V_137;
V_143 = 2 * V_146 . V_147 ;
V_142 = V_117 - V_143 ;
if ( F_7 ( V_145 , & V_4 -> V_6 ) )
goto V_137;
for ( V_144 = 0 ; V_144 < V_129 -> V_148 ; V_144 ++ ) {
struct V_68 * V_69 ;
struct V_68 T_4 * * V_149 = & V_129 -> V_138 [ V_144 ] ;
while ( ( V_69 = F_120 ( * V_149 ,
F_121 ( & V_4 -> V_55 ) ) ) != NULL ) {
if ( F_122 ( V_142 , V_69 -> V_141 ) ) {
F_123 ( * V_149 ,
F_120 ( V_69 -> V_139 ,
F_121 ( & V_4 -> V_55 ) ) ) ;
F_124 ( & V_69 -> V_46 ) ;
F_125 ( & V_69 -> V_150 , V_151 ) ;
} else {
V_149 = & V_69 -> V_139 ;
}
}
}
V_137:
F_64 ( & V_4 -> V_55 , V_6 ) ;
}
static void F_126 ( struct V_152 * V_153 )
{
struct V_3 * V_4 =
F_127 ( V_153 , struct V_3 , V_154 . V_153 ) ;
F_119 ( V_4 ) ;
if ( ! F_7 ( V_145 , & V_4 -> V_6 ) )
F_128 ( V_126 , & V_4 -> V_154 ,
V_146 . V_147 ) ;
}
static struct V_68 * F_129 ( T_2 * V_80 ,
struct V_1 * V_2 )
{
struct V_68 * V_69 ;
V_69 = F_83 ( sizeof *V_69 , V_82 ) ;
if ( ! V_69 )
return NULL ;
V_69 -> V_2 = V_2 ;
memcpy ( & V_69 -> V_80 , V_80 , sizeof( V_69 -> V_80 ) ) ;
F_68 ( & V_69 -> V_50 ) ;
F_84 ( & V_69 -> V_46 ) ;
F_77 ( V_69 , NULL ) ;
F_130 ( & V_69 -> V_140 , 1 ) ;
return V_69 ;
}
struct V_68 * F_90 ( T_2 * V_80 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_134 * V_135 = & V_4 -> V_135 ;
struct V_128 * V_129 ;
struct V_68 * V_69 ;
T_3 V_136 ;
V_129 = F_120 ( V_135 -> V_129 ,
F_121 ( & V_4 -> V_55 ) ) ;
if ( ! V_129 ) {
V_69 = NULL ;
goto V_137;
}
V_136 = F_113 ( V_129 , V_80 ) ;
for ( V_69 = F_120 ( V_129 -> V_138 [ V_136 ] ,
F_121 ( & V_4 -> V_55 ) ) ;
V_69 != NULL ;
V_69 = F_120 ( V_69 -> V_139 ,
F_121 ( & V_4 -> V_55 ) ) ) {
if ( memcmp ( V_80 , V_69 -> V_80 , V_124 ) == 0 ) {
if ( ! F_117 ( & V_69 -> V_140 ) ) {
V_69 = NULL ;
break;
}
V_69 -> V_141 = V_117 ;
goto V_137;
}
}
V_69 = F_129 ( V_80 , V_2 ) ;
if ( ! V_69 )
goto V_137;
F_131 ( & V_69 -> V_140 ) ;
V_69 -> V_141 = V_117 ;
F_123 ( V_69 -> V_139 ,
F_120 ( V_129 -> V_138 [ V_136 ] ,
F_121 ( & V_4 -> V_55 ) ) ) ;
F_123 ( V_129 -> V_138 [ V_136 ] , V_69 ) ;
F_131 ( & V_135 -> V_155 ) ;
V_137:
return V_69 ;
}
void F_132 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
if ( V_69 -> V_51 )
F_45 ( V_69 -> V_51 ) ;
while ( ( V_49 = F_42 ( & V_69 -> V_50 ) ) ) {
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
}
if ( F_76 ( V_69 ) )
F_133 ( F_76 ( V_69 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_22 ,
F_94 ( V_69 -> V_80 ) ,
V_69 -> V_80 + 4 ) ;
F_46 ( V_69 ) ;
if ( F_134 ( & V_4 -> V_135 . V_155 ) ) {
if ( F_7 ( V_156 , & V_4 -> V_6 ) )
F_80 ( & V_4 -> V_135 . V_157 ) ;
}
}
static void V_151 ( struct V_158 * V_159 )
{
struct V_68 * V_69 = F_127 ( V_159 , struct V_68 , V_150 ) ;
F_95 ( V_69 ) ;
}
void F_79 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_134 * V_135 = & V_4 -> V_135 ;
struct V_128 * V_129 ;
struct V_68 T_4 * * V_149 ;
struct V_68 * V_33 ;
T_3 V_136 ;
V_129 = F_120 ( V_135 -> V_129 ,
F_121 ( & V_4 -> V_55 ) ) ;
if ( ! V_129 )
return;
V_136 = F_113 ( V_129 , V_69 -> V_80 ) ;
V_149 = & V_129 -> V_138 [ V_136 ] ;
for ( V_33 = F_120 ( * V_149 ,
F_121 ( & V_4 -> V_55 ) ) ;
V_33 != NULL ;
V_33 = F_120 ( * V_149 ,
F_121 ( & V_4 -> V_55 ) ) ) {
if ( V_33 == V_69 ) {
F_123 ( * V_149 ,
F_120 ( V_69 -> V_139 ,
F_121 ( & V_4 -> V_55 ) ) ) ;
F_124 ( & V_69 -> V_46 ) ;
F_125 ( & V_69 -> V_150 , V_151 ) ;
return;
} else {
V_149 = & V_33 -> V_139 ;
}
}
}
static int F_135 ( struct V_3 * V_4 )
{
struct V_134 * V_135 = & V_4 -> V_135 ;
struct V_128 * V_129 ;
struct V_68 * * V_138 ;
T_3 V_148 ;
F_15 ( V_156 , & V_4 -> V_6 ) ;
V_135 -> V_129 = NULL ;
V_129 = F_83 ( sizeof( * V_129 ) , V_54 ) ;
if ( ! V_129 )
return - V_160 ;
F_5 ( V_145 , & V_4 -> V_6 ) ;
V_148 = F_136 ( V_146 . V_161 ) ;
V_138 = F_83 ( V_148 * sizeof( * V_138 ) , V_54 ) ;
if ( ! V_138 ) {
F_46 ( V_129 ) ;
return - V_160 ;
}
V_129 -> V_148 = V_148 ;
V_129 -> V_133 = ( V_148 - 1 ) ;
V_129 -> V_138 = V_138 ;
V_135 -> V_129 = V_129 ;
V_129 -> V_135 = V_135 ;
F_130 ( & V_135 -> V_155 , 0 ) ;
F_15 ( V_145 , & V_4 -> V_6 ) ;
F_128 ( V_126 , & V_4 -> V_154 ,
V_146 . V_147 ) ;
return 0 ;
}
static void F_137 ( struct V_158 * V_162 )
{
struct V_128 * V_129 = F_127 ( V_162 ,
struct V_128 ,
V_150 ) ;
struct V_68 T_4 * * V_138 = V_129 -> V_138 ;
struct V_134 * V_135 = V_129 -> V_135 ;
F_46 ( V_138 ) ;
F_46 ( V_129 ) ;
F_80 ( & V_135 -> V_163 ) ;
}
void F_44 ( struct V_1 * V_2 , T_2 * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_134 * V_135 = & V_4 -> V_135 ;
struct V_128 * V_129 ;
unsigned long V_6 ;
int V_144 ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_129 = F_120 ( V_135 -> V_129 ,
F_121 ( & V_4 -> V_55 ) ) ;
if ( ! V_129 )
goto V_137;
for ( V_144 = 0 ; V_144 < V_129 -> V_148 ; V_144 ++ ) {
struct V_68 * V_69 ;
struct V_68 T_4 * * V_149 = & V_129 -> V_138 [ V_144 ] ;
while ( ( V_69 = F_120 ( * V_149 ,
F_121 ( & V_4 -> V_55 ) ) ) != NULL ) {
if ( ! memcmp ( V_31 , V_69 -> V_80 + 4 , sizeof ( union V_40 ) ) ) {
F_123 ( * V_149 ,
F_120 ( V_69 -> V_139 ,
F_121 ( & V_4 -> V_55 ) ) ) ;
F_124 ( & V_69 -> V_46 ) ;
F_125 ( & V_69 -> V_150 , V_151 ) ;
} else {
V_149 = & V_69 -> V_139 ;
}
}
}
V_137:
F_64 ( & V_4 -> V_55 , V_6 ) ;
}
static void F_138 ( struct V_3 * V_4 )
{
struct V_134 * V_135 = & V_4 -> V_135 ;
struct V_128 * V_129 ;
unsigned long V_6 ;
int V_144 , V_164 = 0 ;
F_87 ( & V_4 -> V_135 . V_157 ) ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_129 = F_120 ( V_135 -> V_129 ,
F_121 ( & V_4 -> V_55 ) ) ;
if ( ! V_129 )
goto V_137;
V_164 = F_139 ( & V_4 -> V_135 . V_155 ) ;
if ( ! V_164 )
goto V_165;
for ( V_144 = 0 ; V_144 < V_129 -> V_148 ; V_144 ++ ) {
struct V_68 * V_69 ;
struct V_68 T_4 * * V_149 = & V_129 -> V_138 [ V_144 ] ;
while ( ( V_69 = F_120 ( * V_149 ,
F_121 ( & V_4 -> V_55 ) ) ) != NULL ) {
F_123 ( * V_149 ,
F_120 ( V_69 -> V_139 ,
F_121 ( & V_4 -> V_55 ) ) ) ;
F_124 ( & V_69 -> V_46 ) ;
F_125 ( & V_69 -> V_150 , V_151 ) ;
}
}
V_165:
F_123 ( V_135 -> V_129 , NULL ) ;
F_125 ( & V_129 -> V_150 , F_137 ) ;
V_137:
F_64 ( & V_4 -> V_55 , V_6 ) ;
if ( V_164 )
F_66 ( & V_4 -> V_135 . V_157 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_166 ;
F_3 ( V_4 , L_23 ) ;
F_87 ( & V_4 -> V_135 . V_163 ) ;
F_5 ( V_156 , & V_4 -> V_6 ) ;
V_166 = F_141 ( V_145 , & V_4 -> V_6 ) ;
if ( ! V_166 )
F_142 ( & V_4 -> V_154 ) ;
F_138 ( V_4 ) ;
F_66 ( & V_4 -> V_135 . V_163 ) ;
}
int F_143 ( struct V_1 * V_2 , struct V_167 * V_75 , int V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_135 ( V_4 ) < 0 )
goto V_168;
V_4 -> V_169 = F_83 ( V_170 * sizeof * V_4 -> V_169 ,
V_54 ) ;
if ( ! V_4 -> V_169 ) {
F_144 ( V_171 L_24 ,
V_75 -> V_172 , V_170 ) ;
goto V_173;
}
V_4 -> V_174 = F_145 ( V_175 * sizeof * V_4 -> V_174 ) ;
if ( ! V_4 -> V_174 ) {
F_144 ( V_171 L_25 ,
V_75 -> V_172 , V_175 ) ;
goto V_176;
}
if ( F_146 ( V_2 , V_75 , V_76 ) )
goto V_177;
return 0 ;
V_177:
F_147 ( V_4 -> V_174 ) ;
V_176:
F_46 ( V_4 -> V_169 ) ;
V_173:
F_140 ( V_2 ) ;
V_168:
return - V_160 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_11 , * V_178 ;
F_58 ( V_162 ) ;
F_148 () ;
F_149 ( V_2 ) ;
F_56 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_145 , & V_11 -> V_6 ) ;
F_142 ( & V_11 -> V_154 ) ;
F_150 ( V_11 -> V_2 , & V_162 ) ;
}
F_151 ( & V_162 ) ;
F_152 ( V_2 ) ;
F_46 ( V_4 -> V_169 ) ;
F_147 ( V_4 -> V_174 ) ;
V_4 -> V_169 = NULL ;
V_4 -> V_174 = NULL ;
F_140 ( V_2 ) ;
}
void F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_179 = & V_180 ;
V_2 -> V_181 = & V_182 ;
F_154 ( V_2 ) ;
F_155 ( V_2 , & V_4 -> V_183 , V_184 , V_185 ) ;
V_2 -> V_186 = V_187 ;
V_2 -> V_6 |= V_188 | V_189 ;
V_2 -> V_190 = V_191 ;
V_2 -> V_192 = V_124 ;
V_2 -> type = V_193 ;
V_2 -> V_194 = V_175 * 2 ;
V_2 -> V_15 = ( V_195 |
V_196 ) ;
V_2 -> V_197 &= ~ V_198 ;
memcpy ( V_2 -> V_81 , V_199 , V_124 ) ;
V_4 -> V_2 = V_2 ;
F_156 ( & V_4 -> V_55 ) ;
F_157 ( & V_4 -> V_12 ) ;
F_84 ( & V_4 -> V_47 ) ;
F_84 ( & V_4 -> V_200 ) ;
F_84 ( & V_4 -> V_201 ) ;
F_84 ( & V_4 -> V_202 ) ;
F_158 ( & V_4 -> V_203 , V_204 ) ;
F_159 ( & V_4 -> V_205 , V_206 ) ;
F_159 ( & V_4 -> V_207 , V_208 ) ;
F_159 ( & V_4 -> V_209 , V_210 ) ;
F_159 ( & V_4 -> V_211 , V_212 ) ;
F_159 ( & V_4 -> V_127 , V_213 ) ;
F_158 ( & V_4 -> V_214 , V_215 ) ;
F_158 ( & V_4 -> V_154 , F_126 ) ;
}
struct V_3 * F_160 ( const char * V_172 )
{
struct V_1 * V_2 ;
V_2 = F_161 ( ( int ) sizeof( struct V_3 ) , V_172 ,
V_216 , F_153 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_5 F_162 ( struct V_217 * V_2 ,
struct V_218 * V_219 , char * V_25 )
{
struct V_3 * V_4 = F_2 ( F_163 ( V_2 ) ) ;
return sprintf ( V_25 , L_26 , V_4 -> V_86 ) ;
}
static T_5 F_164 ( struct V_217 * V_2 ,
struct V_218 * V_219 , char * V_25 )
{
struct V_3 * V_4 = F_2 ( F_163 ( V_2 ) ) ;
return sprintf ( V_25 , L_27 , F_7 ( V_220 , & V_4 -> V_6 ) ) ;
}
void F_165 ( struct V_1 * V_221 , int V_222 )
{
struct V_3 * V_4 = F_2 ( V_221 ) ;
if ( V_222 > 0 ) {
F_5 ( V_220 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_28
L_29 ) ;
} else
F_15 ( V_220 , & V_4 -> V_6 ) ;
}
static T_5 F_166 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_25 , T_6 V_223 )
{
unsigned long V_222 = F_167 ( V_25 , NULL , 0 ) ;
F_165 ( F_163 ( V_2 ) , V_222 ) ;
return V_223 ;
}
int F_168 ( struct V_1 * V_2 )
{
return F_169 ( & V_2 -> V_2 , & V_224 ) ;
}
static T_5 F_170 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_25 , T_6 V_223 )
{
int V_86 ;
int V_36 ;
if ( sscanf ( V_25 , L_30 , & V_86 ) != 1 )
return - V_14 ;
if ( V_86 <= 0 || V_86 > 0xffff || V_86 == 0x8000 )
return - V_14 ;
V_86 |= 0x8000 ;
V_36 = F_171 ( F_163 ( V_2 ) , V_86 ) ;
return V_36 ? V_36 : V_223 ;
}
static T_5 F_172 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_25 , T_6 V_223 )
{
int V_86 ;
int V_36 ;
if ( sscanf ( V_25 , L_30 , & V_86 ) != 1 )
return - V_14 ;
if ( V_86 < 0 || V_86 > 0xffff )
return - V_14 ;
V_36 = F_173 ( F_163 ( V_2 ) , V_86 ) ;
return V_36 ? V_36 : V_223 ;
}
int F_174 ( struct V_1 * V_2 )
{
return F_169 ( & V_2 -> V_2 , & V_225 ) ;
}
int F_175 ( struct V_3 * V_4 , struct V_167 * V_226 )
{
struct V_227 * V_228 ;
int V_229 = - V_160 ;
V_228 = F_48 ( sizeof *V_228 , V_54 ) ;
if ( ! V_228 ) {
F_144 ( V_171 L_31 ,
V_226 -> V_172 , sizeof *V_228 ) ;
return V_229 ;
}
V_229 = F_176 ( V_226 , V_228 ) ;
if ( V_229 ) {
F_144 ( V_171 L_32 ,
V_226 -> V_172 , V_229 ) ;
F_46 ( V_228 ) ;
return V_229 ;
}
V_4 -> V_230 = V_228 -> V_231 ;
F_46 ( V_228 ) ;
if ( V_4 -> V_230 & V_232 ) {
V_4 -> V_2 -> V_233 = V_17 |
V_18 | V_234 ;
if ( V_4 -> V_230 & V_235 )
V_4 -> V_2 -> V_233 |= V_19 ;
V_4 -> V_2 -> V_15 |= V_4 -> V_2 -> V_233 ;
}
return 0 ;
}
static struct V_1 * F_177 ( const char * V_236 ,
struct V_167 * V_226 , T_2 V_76 )
{
struct V_3 * V_4 ;
struct V_237 V_219 ;
int V_229 = - V_160 ;
V_4 = F_160 ( V_236 ) ;
if ( ! V_4 )
goto V_238;
F_178 ( V_4 -> V_2 , V_226 -> V_239 ) ;
V_4 -> V_2 -> V_240 = V_76 - 1 ;
if ( ! F_179 ( V_226 , V_76 , & V_219 ) )
V_4 -> V_23 = F_180 ( V_219 . V_241 ) ;
else {
F_144 ( V_171 L_33 ,
V_226 -> V_172 , V_76 ) ;
goto V_242;
}
V_4 -> V_2 -> V_22 = F_26 ( V_4 -> V_23 ) ;
V_4 -> V_21 = V_4 -> V_24 = V_4 -> V_2 -> V_22 ;
V_4 -> V_2 -> V_243 = sizeof( struct V_68 ) ;
V_229 = F_181 ( V_226 , V_76 , 0 , & V_4 -> V_86 ) ;
if ( V_229 ) {
F_144 ( V_171 L_34 ,
V_226 -> V_172 , V_76 , V_229 ) ;
goto V_242;
}
if ( F_175 ( V_4 , V_226 ) )
goto V_242;
V_4 -> V_86 |= 0x8000 ;
V_4 -> V_2 -> V_81 [ 8 ] = V_4 -> V_86 >> 8 ;
V_4 -> V_2 -> V_81 [ 9 ] = V_4 -> V_86 & 0xff ;
V_229 = F_182 ( V_226 , V_76 , 0 , & V_4 -> V_85 ) ;
if ( V_229 ) {
F_144 ( V_171 L_35 ,
V_226 -> V_172 , V_76 , V_229 ) ;
goto V_242;
} else
memcpy ( V_4 -> V_2 -> V_26 + 4 , V_4 -> V_85 . V_39 , sizeof ( union V_40 ) ) ;
V_229 = F_143 ( V_4 -> V_2 , V_226 , V_76 ) ;
if ( V_229 < 0 ) {
F_144 ( V_171 L_36 ,
V_226 -> V_172 , V_76 , V_229 ) ;
goto V_242;
}
F_183 ( & V_4 -> V_244 ,
V_4 -> V_75 , V_245 ) ;
V_229 = F_184 ( & V_4 -> V_244 ) ;
if ( V_229 < 0 ) {
F_144 ( V_171 L_37
L_38 ,
V_226 -> V_172 , V_76 , V_229 ) ;
goto V_246;
}
V_229 = F_185 ( V_4 -> V_2 ) ;
if ( V_229 ) {
F_144 ( V_171 L_39 ,
V_226 -> V_172 , V_76 , V_229 ) ;
goto V_247;
}
F_186 ( V_4 -> V_2 ) ;
if ( F_187 ( V_4 -> V_2 ) )
goto V_248;
if ( F_174 ( V_4 -> V_2 ) )
goto V_248;
if ( F_168 ( V_4 -> V_2 ) )
goto V_248;
if ( F_169 ( & V_4 -> V_2 -> V_2 , & V_249 ) )
goto V_248;
if ( F_169 ( & V_4 -> V_2 -> V_2 , & V_250 ) )
goto V_248;
return V_4 -> V_2 ;
V_248:
F_149 ( V_4 -> V_2 ) ;
F_188 ( V_4 -> V_2 ) ;
V_247:
F_189 ( & V_4 -> V_244 ) ;
F_5 ( V_145 , & V_4 -> V_6 ) ;
F_142 ( & V_4 -> V_154 ) ;
F_190 ( V_126 ) ;
V_246:
F_20 ( V_4 -> V_2 ) ;
V_242:
F_191 ( V_4 -> V_2 ) ;
V_238:
return F_192 ( V_229 ) ;
}
static void F_193 ( struct V_167 * V_217 )
{
struct V_251 * V_252 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_253 , V_254 , V_255 ;
if ( F_194 ( V_217 -> V_256 ) != V_257 )
return;
V_252 = F_48 ( sizeof *V_252 , V_54 ) ;
if ( ! V_252 )
return;
F_84 ( V_252 ) ;
if ( V_217 -> V_256 == V_258 ) {
V_253 = 0 ;
V_254 = 0 ;
} else {
V_253 = 1 ;
V_254 = V_217 -> V_259 ;
}
for ( V_255 = V_253 ; V_255 <= V_254 ; ++ V_255 ) {
if ( F_195 ( V_217 , V_255 ) != V_260 )
continue;
V_2 = F_177 ( L_40 , V_217 , V_255 ) ;
if ( ! F_196 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_40 ( & V_4 -> V_46 , V_252 ) ;
}
}
F_197 ( V_217 , & V_261 , V_252 ) ;
}
static void F_198 ( struct V_167 * V_217 )
{
struct V_3 * V_4 , * V_262 ;
struct V_251 * V_252 ;
if ( F_194 ( V_217 -> V_256 ) != V_257 )
return;
V_252 = F_199 ( V_217 , & V_261 ) ;
if ( ! V_252 )
return;
F_56 (priv, tmp, dev_list, list) {
F_189 ( & V_4 -> V_244 ) ;
F_33 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_13 ) ;
F_31 () ;
F_5 ( V_145 , & V_4 -> V_6 ) ;
F_142 ( & V_4 -> V_154 ) ;
F_190 ( V_126 ) ;
F_188 ( V_4 -> V_2 ) ;
F_191 ( V_4 -> V_2 ) ;
}
F_46 ( V_252 ) ;
}
static int T_7 F_200 ( void )
{
int V_36 ;
V_170 = F_136 ( V_170 ) ;
V_170 = F_27 ( V_170 , V_263 ) ;
V_170 = F_201 ( V_170 , V_264 ) ;
V_175 = F_136 ( V_175 ) ;
V_175 = F_27 ( V_175 , V_263 ) ;
V_175 = F_202 ( V_175 , 2 * V_265 , V_264 ) ;
#ifdef F_203
V_266 = F_27 ( V_266 , V_267 ) ;
#endif
F_204 ( V_268 > V_269 ) ;
V_36 = F_205 () ;
if ( V_36 )
return V_36 ;
V_126 = F_206 ( L_41 ) ;
if ( ! V_126 ) {
V_36 = - V_160 ;
goto V_270;
}
F_207 ( & V_90 ) ;
V_36 = F_208 ( & V_261 ) ;
if ( V_36 )
goto V_271;
V_36 = F_209 () ;
if ( V_36 )
goto V_272;
return 0 ;
V_272:
F_210 ( & V_261 ) ;
V_271:
F_211 ( & V_90 ) ;
F_212 ( V_126 ) ;
V_270:
F_213 () ;
return V_36 ;
}
static void T_8 F_214 ( void )
{
F_215 () ;
F_210 ( & V_261 ) ;
F_211 ( & V_90 ) ;
F_213 () ;
F_212 ( V_126 ) ;
}
