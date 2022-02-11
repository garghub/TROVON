int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_1 ) ;
F_4 ( V_5 , & V_4 -> V_6 ) ;
if ( F_5 ( V_2 ) )
return 0 ;
if ( F_6 ( V_2 ) )
goto V_7;
if ( F_7 ( V_2 ) )
goto V_8;
if ( ! F_8 ( V_9 , & V_4 -> V_6 ) ) {
struct V_3 * V_10 ;
F_9 ( & V_4 -> V_11 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_10 -> V_2 -> V_6 ;
if ( V_6 & V_12 )
continue;
F_11 ( V_10 -> V_2 , V_6 | V_12 ) ;
}
F_12 ( & V_4 -> V_11 ) ;
}
F_13 ( V_2 ) ;
return 0 ;
V_8:
F_14 ( V_2 , 1 ) ;
V_7:
F_15 ( V_5 , & V_4 -> V_6 ) ;
return - V_13 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_2 ) ;
F_15 ( V_5 , & V_4 -> V_6 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 , 1 ) ;
F_14 ( V_2 , 0 ) ;
if ( ! F_8 ( V_9 , & V_4 -> V_6 ) ) {
struct V_3 * V_10 ;
F_9 ( & V_4 -> V_11 ) ;
F_10 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_10 -> V_2 -> V_6 ;
if ( ! ( V_6 & V_12 ) )
continue;
F_11 ( V_10 -> V_2 , V_6 & ~ V_12 ) ;
}
F_12 ( & V_4 -> V_11 ) ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_8 ( V_15 , & V_4 -> V_6 ) )
V_14 &= ~ ( V_16 | V_17 | V_18 ) ;
return V_14 ;
}
static int F_22 ( struct V_1 * V_2 , int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
if ( V_19 > F_24 ( V_2 ) )
return - V_13 ;
if ( V_19 > V_4 -> V_20 )
F_25 ( V_4 , L_3 ,
V_4 -> V_20 ) ;
V_2 -> V_21 = V_19 ;
return 0 ;
}
if ( V_19 > F_26 ( V_4 -> V_22 ) )
return - V_13 ;
V_4 -> V_23 = V_19 ;
V_2 -> V_21 = F_27 ( V_4 -> V_20 , V_4 -> V_23 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , const char * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_29 ( V_2 -> V_25 ) && ! strcmp ( V_24 , L_4 ) ) {
F_4 ( V_15 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_5
L_6 ) ;
F_30 ( V_2 ) ;
F_31 () ;
V_4 -> V_26 . V_27 &= ~ V_28 ;
F_32 ( V_2 ) ;
F_33 () ;
return 0 ;
}
if ( ! strcmp ( V_24 , L_7 ) ) {
F_15 ( V_15 , & V_4 -> V_6 ) ;
F_30 ( V_2 ) ;
F_34 ( V_2 , F_27 ( V_4 -> V_20 , V_2 -> V_21 ) ) ;
F_31 () ;
F_32 ( V_2 ) ;
F_33 () ;
return 0 ;
}
return - V_13 ;
}
static struct V_29 * F_35 ( struct V_1 * V_2 , void * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_32 = V_4 -> V_33 . V_31 ;
struct V_29 * V_34 ;
int V_35 ;
while ( V_32 ) {
V_34 = F_36 ( V_32 , struct V_29 , V_31 ) ;
V_35 = memcmp ( V_30 , V_34 -> V_36 . V_37 . V_38 ,
sizeof ( union V_39 ) ) ;
if ( V_35 < 0 )
V_32 = V_32 -> V_40 ;
else if ( V_35 > 0 )
V_32 = V_32 -> V_41 ;
else
return V_34 ;
}
return NULL ;
}
static int F_37 ( struct V_1 * V_2 , struct V_29 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * * V_32 = & V_4 -> V_33 . V_31 ;
struct V_31 * V_42 = NULL ;
struct V_29 * V_43 ;
int V_35 ;
while ( * V_32 ) {
V_42 = * V_32 ;
V_43 = F_36 ( V_42 , struct V_29 , V_31 ) ;
V_35 = memcmp ( V_34 -> V_36 . V_37 . V_38 , V_43 -> V_36 . V_37 . V_38 ,
sizeof ( union V_39 ) ) ;
if ( V_35 < 0 )
V_32 = & V_42 -> V_40 ;
else if ( V_35 > 0 )
V_32 = & V_42 -> V_41 ;
else
return - V_44 ;
}
F_38 ( & V_34 -> V_31 , V_42 , V_32 ) ;
F_39 ( & V_34 -> V_31 , & V_4 -> V_33 ) ;
F_40 ( & V_34 -> V_45 , & V_4 -> V_46 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_29 * V_34 )
{
struct V_47 * V_48 ;
while ( ( V_48 = F_42 ( & V_34 -> V_49 ) ) )
F_43 ( V_48 ) ;
F_3 ( F_2 ( V_2 ) , L_8 ) ;
F_44 ( V_2 , V_34 -> V_36 . V_37 . V_38 ) ;
if ( V_34 -> V_50 )
F_45 ( V_34 -> V_50 ) ;
F_46 ( V_34 ) ;
}
struct V_51 * F_47 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
V_52 = F_48 ( sizeof *V_52 , V_53 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_2 = V_2 ;
memset ( V_52 -> V_34 . V_36 . V_37 . V_38 , 0 , 16 ) ;
if ( F_49 ( V_52 ) ) {
F_46 ( V_52 ) ;
return NULL ;
}
return V_52 ;
}
int F_49 ( struct V_51 * V_52 )
{
struct V_3 * V_4 = F_2 ( V_52 -> V_2 ) ;
struct V_31 * V_32 ;
struct V_29 * V_34 ;
int V_35 = 1 ;
F_50 ( & V_4 -> V_54 ) ;
V_32 = F_51 ( & V_4 -> V_33 ) ;
while ( V_32 ) {
V_34 = F_36 ( V_32 , struct V_29 , V_31 ) ;
if ( memcmp ( V_52 -> V_34 . V_36 . V_37 . V_38 , V_34 -> V_36 . V_37 . V_38 ,
sizeof ( union V_39 ) ) < 0 ) {
V_52 -> V_34 = * V_34 ;
V_35 = 0 ;
break;
}
V_32 = F_52 ( V_32 ) ;
}
F_53 ( & V_4 -> V_54 ) ;
return V_35 ;
}
void F_54 ( struct V_51 * V_52 ,
struct V_29 * V_34 )
{
* V_34 = V_52 -> V_34 ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 , * V_55 ;
F_50 ( & V_4 -> V_54 ) ;
F_56 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_9 ,
F_57 ( V_34 -> V_36 . V_56 ) ,
V_34 -> V_36 . V_37 . V_38 ) ;
V_34 -> V_57 = 0 ;
}
F_53 ( & V_4 -> V_54 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 , * V_55 ;
F_58 ( V_58 ) ;
unsigned long V_6 ;
F_59 ( V_2 ) ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
F_61 ( & V_4 -> V_46 , & V_58 ) ;
F_10 (path, &remove_list, list)
F_62 ( & V_34 -> V_31 , & V_4 -> V_33 ) ;
F_56 (path, tp, &remove_list, list) {
if ( V_34 -> V_59 )
F_63 ( V_34 -> V_60 , V_34 -> V_59 ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_65 ( V_2 ) ;
F_66 ( & V_34 -> V_61 ) ;
F_41 ( V_2 , V_34 ) ;
F_59 ( V_2 ) ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
}
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_65 ( V_2 ) ;
}
static void F_67 ( int V_62 ,
struct V_63 * V_36 ,
void * V_64 )
{
struct V_29 * V_34 = V_64 ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_65 * V_50 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_67 * V_68 , * V_69 ;
struct V_70 V_71 ;
struct V_47 * V_48 ;
unsigned long V_6 ;
if ( ! V_62 )
F_3 ( V_4 , L_10 ,
F_57 ( V_36 -> V_56 ) , V_36 -> V_37 . V_38 ) ;
else
F_3 ( V_4 , L_11 ,
V_62 , V_34 -> V_36 . V_37 . V_38 ) ;
F_68 ( & V_71 ) ;
if ( ! V_62 ) {
struct V_72 V_73 ;
if ( ! F_69 ( V_4 -> V_74 , V_4 -> V_75 , V_36 , & V_73 ) )
V_50 = F_70 ( V_2 , V_4 -> V_76 , & V_73 ) ;
}
F_60 ( & V_4 -> V_54 , V_6 ) ;
if ( ! F_71 ( V_50 ) ) {
V_34 -> V_36 = * V_36 ;
V_66 = V_34 -> V_50 ;
V_34 -> V_50 = V_50 ;
F_3 ( V_4 , L_12 ,
V_50 , F_57 ( V_36 -> V_56 ) , V_36 -> V_77 ) ;
while ( ( V_48 = F_42 ( & V_34 -> V_49 ) ) )
F_72 ( & V_71 , V_48 ) ;
F_56 (neigh, tn, &path->neigh_list, list) {
if ( V_68 -> V_50 ) {
F_73 ( V_68 -> V_50 != V_66 ) ;
F_45 ( V_68 -> V_50 ) ;
}
F_74 ( & V_34 -> V_50 -> V_78 ) ;
V_68 -> V_50 = V_34 -> V_50 ;
if ( F_75 ( V_2 , V_68 -> V_79 ) ) {
if ( ! F_76 ( V_68 ) )
F_77 ( V_68 , F_78 ( V_2 ,
V_34 ,
V_68 ) ) ;
if ( ! F_76 ( V_68 ) ) {
F_79 ( & V_68 -> V_45 ) ;
F_80 ( V_68 ) ;
continue;
}
}
while ( ( V_48 = F_42 ( & V_68 -> V_49 ) ) )
F_72 ( & V_71 , V_48 ) ;
}
V_34 -> V_57 = 1 ;
}
V_34 -> V_59 = NULL ;
F_81 ( & V_34 -> V_61 ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
if ( F_71 ( V_50 ) )
F_44 ( V_2 , V_34 -> V_36 . V_37 . V_38 ) ;
if ( V_66 )
F_45 ( V_66 ) ;
while ( ( V_48 = F_42 ( & V_71 ) ) ) {
V_48 -> V_2 = V_2 ;
if ( F_82 ( V_48 ) )
F_25 ( V_4 , L_13
L_14 ) ;
}
}
static struct V_29 * F_83 ( struct V_1 * V_2 , void * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 ;
if ( ! V_4 -> V_80 )
return NULL ;
V_34 = F_84 ( sizeof *V_34 , V_81 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_2 = V_2 ;
F_68 ( & V_34 -> V_49 ) ;
F_85 ( & V_34 -> V_82 ) ;
memcpy ( V_34 -> V_36 . V_37 . V_38 , V_30 , sizeof ( union V_39 ) ) ;
V_34 -> V_36 . V_83 = V_4 -> V_84 ;
V_34 -> V_36 . V_85 = F_86 ( V_4 -> V_85 ) ;
V_34 -> V_36 . V_86 = 1 ;
V_34 -> V_36 . V_87 = V_4 -> V_80 -> V_88 . V_87 ;
return V_34 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_29 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_15 ,
V_34 -> V_36 . V_37 . V_38 ) ;
F_88 ( & V_34 -> V_61 ) ;
V_34 -> V_60 =
F_89 ( & V_89 , V_4 -> V_74 , V_4 -> V_75 ,
& V_34 -> V_36 ,
V_90 |
V_91 |
V_92 |
V_93 |
V_94 ,
1000 , V_81 ,
F_67 ,
V_34 , & V_34 -> V_59 ) ;
if ( V_34 -> V_60 < 0 ) {
F_25 ( V_4 , L_16 , V_34 -> V_60 ) ;
V_34 -> V_59 = NULL ;
F_81 ( & V_34 -> V_61 ) ;
return V_34 -> V_60 ;
}
return 0 ;
}
static void F_90 ( struct V_47 * V_48 , T_2 * V_79 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 ;
struct V_67 * V_68 ;
unsigned long V_6 ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_68 = F_91 ( V_79 , V_2 ) ;
if ( ! V_68 ) {
F_64 ( & V_4 -> V_54 , V_6 ) ;
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
return;
}
V_34 = F_35 ( V_2 , V_79 + 4 ) ;
if ( ! V_34 ) {
V_34 = F_83 ( V_2 , V_79 + 4 ) ;
if ( ! V_34 )
goto V_97;
F_37 ( V_2 , V_34 ) ;
}
F_40 ( & V_68 -> V_45 , & V_34 -> V_82 ) ;
if ( V_34 -> V_50 ) {
F_74 ( & V_34 -> V_50 -> V_78 ) ;
V_68 -> V_50 = V_34 -> V_50 ;
if ( F_75 ( V_2 , V_68 -> V_79 ) ) {
if ( ! F_76 ( V_68 ) )
F_77 ( V_68 , F_78 ( V_2 , V_34 , V_68 ) ) ;
if ( ! F_76 ( V_68 ) ) {
F_79 ( & V_68 -> V_45 ) ;
F_80 ( V_68 ) ;
goto V_98;
}
if ( F_93 ( & V_68 -> V_49 ) < V_99 )
F_72 ( & V_68 -> V_49 , V_48 ) ;
else {
F_25 ( V_4 , L_17 ,
F_93 ( & V_68 -> V_49 ) ) ;
goto V_98;
}
} else {
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_94 ( V_2 , V_48 , V_34 -> V_50 , F_95 ( V_79 ) ) ;
F_96 ( V_68 ) ;
return;
}
} else {
V_68 -> V_50 = NULL ;
if ( ! V_34 -> V_59 && F_87 ( V_2 , V_34 ) )
goto V_100;
F_72 ( & V_68 -> V_49 , V_48 ) ;
}
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_96 ( V_68 ) ;
return;
V_100:
F_79 ( & V_68 -> V_45 ) ;
V_97:
F_80 ( V_68 ) ;
V_98:
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_96 ( V_68 ) ;
}
static void F_97 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 ;
unsigned long V_6 ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_34 = F_35 ( V_2 , V_102 -> V_103 + 4 ) ;
if ( ! V_34 || ! V_34 -> V_57 ) {
int V_104 = 0 ;
if ( ! V_34 ) {
V_34 = F_83 ( V_2 , V_102 -> V_103 + 4 ) ;
V_104 = 1 ;
}
if ( V_34 ) {
F_72 ( & V_34 -> V_49 , V_48 ) ;
if ( ! V_34 -> V_59 && F_87 ( V_2 , V_34 ) ) {
F_64 ( & V_4 -> V_54 , V_6 ) ;
if ( V_104 )
F_41 ( V_2 , V_34 ) ;
return;
} else
F_37 ( V_2 , V_34 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
}
F_64 ( & V_4 -> V_54 , V_6 ) ;
return;
}
if ( V_34 -> V_50 ) {
F_3 ( V_4 , L_18 ,
F_57 ( V_34 -> V_36 . V_56 ) ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_94 ( V_2 , V_48 , V_34 -> V_50 , F_95 ( V_102 -> V_103 ) ) ;
return;
} else if ( ( V_34 -> V_59 || ! F_87 ( V_2 , V_34 ) ) &&
F_93 ( & V_34 -> V_49 ) < V_99 ) {
F_72 ( & V_34 -> V_49 , V_48 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
}
F_64 ( & V_4 -> V_54 , V_6 ) ;
}
static int F_98 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_67 * V_68 ;
struct V_101 * V_102 = (struct V_101 * ) V_48 -> V_102 ;
struct V_105 * V_106 ;
unsigned long V_6 ;
V_106 = (struct V_105 * ) V_48 -> V_107 ;
if ( F_99 ( V_102 -> V_103 [ 4 ] == 0xff ) ) {
if ( ( V_106 -> V_108 != F_100 ( V_109 ) ) &&
( V_106 -> V_108 != F_100 ( V_110 ) ) &&
( V_106 -> V_108 != F_100 ( V_111 ) ) &&
( V_106 -> V_108 != F_100 ( V_112 ) ) ) {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
return V_113 ;
}
V_102 -> V_103 [ 8 ] = ( V_4 -> V_85 >> 8 ) & 0xff ;
V_102 -> V_103 [ 9 ] = V_4 -> V_85 & 0xff ;
V_68 = F_101 ( V_2 , V_102 -> V_103 ) ;
if ( F_102 ( V_68 ) )
goto V_114;
F_103 ( V_2 , V_102 -> V_103 , V_48 ) ;
return V_113 ;
}
switch ( V_106 -> V_108 ) {
case F_100 ( V_109 ) :
case F_100 ( V_110 ) :
V_68 = F_101 ( V_2 , V_102 -> V_103 ) ;
if ( F_99 ( ! V_68 ) ) {
F_90 ( V_48 , V_102 -> V_103 , V_2 ) ;
return V_113 ;
}
break;
case F_100 ( V_111 ) :
case F_100 ( V_112 ) :
F_97 ( V_48 , V_2 , V_102 ) ;
return V_113 ;
default:
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
return V_113 ;
}
V_114:
if ( F_76 ( V_68 ) ) {
if ( F_104 ( V_68 ) ) {
F_105 ( V_2 , V_48 , F_76 ( V_68 ) ) ;
goto V_115;
}
} else if ( V_68 -> V_50 ) {
F_94 ( V_2 , V_48 , V_68 -> V_50 , F_95 ( V_102 -> V_103 ) ) ;
goto V_115;
}
if ( F_93 ( & V_68 -> V_49 ) < V_99 ) {
F_60 ( & V_4 -> V_54 , V_6 ) ;
F_72 ( & V_68 -> V_49 , V_48 ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
}
V_115:
F_96 ( V_68 ) ;
return V_113 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 , L_19 ,
F_107 ( V_116 - V_2 -> V_117 ) ) ;
F_25 ( V_4 , L_20 ,
F_108 ( V_2 ) ,
V_4 -> V_118 , V_4 -> V_119 ) ;
}
static int F_109 ( struct V_47 * V_48 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_79 , const void * V_120 , unsigned V_121 )
{
struct V_105 * V_106 ;
struct V_101 * V_102 = (struct V_101 * ) V_48 -> V_102 ;
V_106 = (struct V_105 * ) F_110 ( V_48 , sizeof *V_106 ) ;
V_106 -> V_108 = F_100 ( type ) ;
V_106 -> V_122 = 0 ;
memcpy ( V_102 -> V_103 , V_79 , V_123 ) ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_8 ( V_124 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_21 ) ;
return;
}
F_112 ( V_125 , & V_4 -> V_126 ) ;
}
static T_3 F_113 ( struct V_127 * V_128 , T_2 * V_79 )
{
T_3 * V_129 = ( T_3 * ) V_79 ;
T_3 V_130 ;
V_130 = F_114 ( V_129 [ 3 ] , V_129 [ 4 ] , V_131 & V_129 [ 0 ] , 0 ) ;
return V_130 & V_128 -> V_132 ;
}
struct V_67 * F_101 ( struct V_1 * V_2 , T_2 * V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
struct V_67 * V_68 = NULL ;
T_3 V_135 ;
F_115 () ;
V_128 = F_116 ( V_134 -> V_128 ) ;
if ( ! V_128 )
goto V_136;
V_135 = F_113 ( V_128 , V_79 ) ;
for ( V_68 = F_116 ( V_128 -> V_137 [ V_135 ] ) ;
V_68 != NULL ;
V_68 = F_116 ( V_68 -> V_138 ) ) {
if ( memcmp ( V_79 , V_68 -> V_79 , V_123 ) == 0 ) {
if ( ! F_117 ( & V_68 -> V_139 ) ) {
V_68 = NULL ;
goto V_136;
}
V_68 -> V_140 = V_116 ;
goto V_136;
}
}
V_136:
F_118 () ;
return V_68 ;
}
static void F_119 ( struct V_3 * V_4 )
{
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
unsigned long V_141 ;
unsigned long V_142 ;
unsigned long V_6 ;
int V_143 ;
if ( F_8 ( V_144 , & V_4 -> V_6 ) )
return;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_128 = F_120 ( V_134 -> V_128 ,
F_121 ( & V_4 -> V_54 ) ) ;
if ( ! V_128 )
goto V_136;
V_142 = 2 * V_145 . V_146 ;
V_141 = V_116 - V_142 ;
if ( F_8 ( V_144 , & V_4 -> V_6 ) )
goto V_136;
for ( V_143 = 0 ; V_143 < V_128 -> V_147 ; V_143 ++ ) {
struct V_67 * V_68 ;
struct V_67 T_4 * * V_148 = & V_128 -> V_137 [ V_143 ] ;
while ( ( V_68 = F_120 ( * V_148 ,
F_121 ( & V_4 -> V_54 ) ) ) != NULL ) {
if ( F_122 ( V_141 , V_68 -> V_140 ) ) {
F_123 ( * V_148 ,
F_120 ( V_68 -> V_138 ,
F_121 ( & V_4 -> V_54 ) ) ) ;
F_79 ( & V_68 -> V_45 ) ;
F_124 ( & V_68 -> V_149 , V_150 ) ;
} else {
V_148 = & V_68 -> V_138 ;
}
}
}
V_136:
F_64 ( & V_4 -> V_54 , V_6 ) ;
}
static void F_125 ( struct V_151 * V_152 )
{
struct V_3 * V_4 =
F_126 ( V_152 , struct V_3 , V_153 . V_152 ) ;
F_119 ( V_4 ) ;
if ( ! F_8 ( V_144 , & V_4 -> V_6 ) )
F_127 ( V_125 , & V_4 -> V_153 ,
V_145 . V_146 ) ;
}
static struct V_67 * F_128 ( T_2 * V_79 ,
struct V_1 * V_2 )
{
struct V_67 * V_68 ;
V_68 = F_84 ( sizeof *V_68 , V_81 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_2 = V_2 ;
memcpy ( & V_68 -> V_79 , V_79 , sizeof( V_68 -> V_79 ) ) ;
F_68 ( & V_68 -> V_49 ) ;
F_85 ( & V_68 -> V_45 ) ;
F_77 ( V_68 , NULL ) ;
F_129 ( & V_68 -> V_139 , 1 ) ;
return V_68 ;
}
struct V_67 * F_91 ( T_2 * V_79 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
struct V_67 * V_68 ;
T_3 V_135 ;
V_128 = F_120 ( V_134 -> V_128 ,
F_121 ( & V_4 -> V_54 ) ) ;
if ( ! V_128 ) {
V_68 = NULL ;
goto V_136;
}
V_135 = F_113 ( V_128 , V_79 ) ;
for ( V_68 = F_120 ( V_128 -> V_137 [ V_135 ] ,
F_121 ( & V_4 -> V_54 ) ) ;
V_68 != NULL ;
V_68 = F_120 ( V_68 -> V_138 ,
F_121 ( & V_4 -> V_54 ) ) ) {
if ( memcmp ( V_79 , V_68 -> V_79 , V_123 ) == 0 ) {
if ( ! F_117 ( & V_68 -> V_139 ) ) {
V_68 = NULL ;
break;
}
V_68 -> V_140 = V_116 ;
goto V_136;
}
}
V_68 = F_128 ( V_79 , V_2 ) ;
if ( ! V_68 )
goto V_136;
F_130 ( & V_68 -> V_139 ) ;
V_68 -> V_140 = V_116 ;
F_123 ( V_68 -> V_138 ,
F_120 ( V_128 -> V_137 [ V_135 ] ,
F_121 ( & V_4 -> V_54 ) ) ) ;
F_123 ( V_128 -> V_137 [ V_135 ] , V_68 ) ;
F_130 ( & V_134 -> V_154 ) ;
V_136:
return V_68 ;
}
void F_131 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 ;
if ( V_68 -> V_50 )
F_45 ( V_68 -> V_50 ) ;
while ( ( V_48 = F_42 ( & V_68 -> V_49 ) ) ) {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
}
if ( F_76 ( V_68 ) )
F_132 ( F_76 ( V_68 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_22 ,
F_95 ( V_68 -> V_79 ) ,
V_68 -> V_79 + 4 ) ;
F_46 ( V_68 ) ;
if ( F_133 ( & V_4 -> V_134 . V_154 ) ) {
if ( F_8 ( V_155 , & V_4 -> V_6 ) )
F_81 ( & V_4 -> V_134 . V_156 ) ;
}
}
static void V_150 ( struct V_157 * V_158 )
{
struct V_67 * V_68 = F_126 ( V_158 , struct V_67 , V_149 ) ;
F_96 ( V_68 ) ;
}
void F_80 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
struct V_67 T_4 * * V_148 ;
struct V_67 * V_32 ;
T_3 V_135 ;
V_128 = F_120 ( V_134 -> V_128 ,
F_121 ( & V_4 -> V_54 ) ) ;
if ( ! V_128 )
return;
V_135 = F_113 ( V_128 , V_68 -> V_79 ) ;
V_148 = & V_128 -> V_137 [ V_135 ] ;
for ( V_32 = F_120 ( * V_148 ,
F_121 ( & V_4 -> V_54 ) ) ;
V_32 != NULL ;
V_32 = F_120 ( * V_148 ,
F_121 ( & V_4 -> V_54 ) ) ) {
if ( V_32 == V_68 ) {
F_123 ( * V_148 ,
F_120 ( V_68 -> V_138 ,
F_121 ( & V_4 -> V_54 ) ) ) ;
F_124 ( & V_68 -> V_149 , V_150 ) ;
return;
} else {
V_148 = & V_32 -> V_138 ;
}
}
}
static int F_134 ( struct V_3 * V_4 )
{
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
struct V_67 * * V_137 ;
T_3 V_147 ;
F_15 ( V_155 , & V_4 -> V_6 ) ;
V_134 -> V_128 = NULL ;
V_128 = F_84 ( sizeof( * V_128 ) , V_53 ) ;
if ( ! V_128 )
return - V_159 ;
F_4 ( V_144 , & V_4 -> V_6 ) ;
V_147 = F_135 ( V_145 . V_160 ) ;
V_137 = F_84 ( V_147 * sizeof( * V_137 ) , V_53 ) ;
if ( ! V_137 ) {
F_46 ( V_128 ) ;
return - V_159 ;
}
V_128 -> V_147 = V_147 ;
V_128 -> V_132 = ( V_147 - 1 ) ;
V_128 -> V_137 = V_137 ;
V_134 -> V_128 = V_128 ;
V_128 -> V_134 = V_134 ;
F_129 ( & V_134 -> V_154 , 0 ) ;
F_15 ( V_144 , & V_4 -> V_6 ) ;
F_127 ( V_125 , & V_4 -> V_153 ,
V_145 . V_146 ) ;
return 0 ;
}
static void F_136 ( struct V_157 * V_161 )
{
struct V_127 * V_128 = F_126 ( V_161 ,
struct V_127 ,
V_149 ) ;
struct V_67 T_4 * * V_137 = V_128 -> V_137 ;
struct V_133 * V_134 = V_128 -> V_134 ;
F_46 ( V_137 ) ;
F_46 ( V_128 ) ;
F_81 ( & V_134 -> V_162 ) ;
}
void F_44 ( struct V_1 * V_2 , T_2 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
unsigned long V_6 ;
int V_143 ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_128 = F_120 ( V_134 -> V_128 ,
F_121 ( & V_4 -> V_54 ) ) ;
if ( ! V_128 )
goto V_136;
for ( V_143 = 0 ; V_143 < V_128 -> V_147 ; V_143 ++ ) {
struct V_67 * V_68 ;
struct V_67 T_4 * * V_148 = & V_128 -> V_137 [ V_143 ] ;
while ( ( V_68 = F_120 ( * V_148 ,
F_121 ( & V_4 -> V_54 ) ) ) != NULL ) {
if ( ! memcmp ( V_30 , V_68 -> V_79 + 4 , sizeof ( union V_39 ) ) ) {
F_123 ( * V_148 ,
F_120 ( V_68 -> V_138 ,
F_121 ( & V_4 -> V_54 ) ) ) ;
F_79 ( & V_68 -> V_45 ) ;
F_124 ( & V_68 -> V_149 , V_150 ) ;
} else {
V_148 = & V_68 -> V_138 ;
}
}
}
V_136:
F_64 ( & V_4 -> V_54 , V_6 ) ;
}
static void F_137 ( struct V_3 * V_4 )
{
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
unsigned long V_6 ;
int V_143 , V_163 = 0 ;
F_88 ( & V_4 -> V_134 . V_156 ) ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_128 = F_120 ( V_134 -> V_128 ,
F_121 ( & V_4 -> V_54 ) ) ;
if ( ! V_128 )
goto V_136;
V_163 = F_138 ( & V_4 -> V_134 . V_154 ) ;
if ( ! V_163 )
goto V_164;
for ( V_143 = 0 ; V_143 < V_128 -> V_147 ; V_143 ++ ) {
struct V_67 * V_68 ;
struct V_67 T_4 * * V_148 = & V_128 -> V_137 [ V_143 ] ;
while ( ( V_68 = F_120 ( * V_148 ,
F_121 ( & V_4 -> V_54 ) ) ) != NULL ) {
F_123 ( * V_148 ,
F_120 ( V_68 -> V_138 ,
F_121 ( & V_4 -> V_54 ) ) ) ;
F_79 ( & V_68 -> V_45 ) ;
F_124 ( & V_68 -> V_149 , V_150 ) ;
}
}
V_164:
F_123 ( V_134 -> V_128 , NULL ) ;
F_124 ( & V_128 -> V_149 , F_136 ) ;
V_136:
F_64 ( & V_4 -> V_54 , V_6 ) ;
if ( V_163 )
F_66 ( & V_4 -> V_134 . V_156 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_165 ;
F_3 ( V_4 , L_23 ) ;
F_88 ( & V_4 -> V_134 . V_162 ) ;
F_4 ( V_155 , & V_4 -> V_6 ) ;
V_165 = F_140 ( V_144 , & V_4 -> V_6 ) ;
if ( ! V_165 )
F_141 ( & V_4 -> V_153 ) ;
F_137 ( V_4 ) ;
F_66 ( & V_4 -> V_134 . V_162 ) ;
}
int F_142 ( struct V_1 * V_2 , struct V_166 * V_74 , int V_75 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_134 ( V_4 ) < 0 )
goto V_167;
V_4 -> V_168 = F_84 ( V_169 * sizeof * V_4 -> V_168 ,
V_53 ) ;
if ( ! V_4 -> V_168 ) {
F_143 ( V_170 L_24 ,
V_74 -> V_171 , V_169 ) ;
goto V_172;
}
V_4 -> V_173 = F_144 ( V_174 * sizeof * V_4 -> V_173 ) ;
if ( ! V_4 -> V_173 ) {
F_143 ( V_170 L_25 ,
V_74 -> V_171 , V_174 ) ;
goto V_175;
}
if ( F_145 ( V_2 , V_74 , V_75 ) )
goto V_176;
return 0 ;
V_176:
F_146 ( V_4 -> V_173 ) ;
V_175:
F_46 ( V_4 -> V_168 ) ;
V_172:
F_139 ( V_2 ) ;
V_167:
return - V_159 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_10 , * V_177 ;
F_58 ( V_161 ) ;
F_147 () ;
F_148 ( V_2 ) ;
F_56 (cpriv, tcpriv, &priv->child_intfs, list) {
F_4 ( V_144 , & V_10 -> V_6 ) ;
F_141 ( & V_10 -> V_153 ) ;
F_149 ( V_10 -> V_2 , & V_161 ) ;
}
F_150 ( & V_161 ) ;
F_151 ( V_2 ) ;
F_46 ( V_4 -> V_168 ) ;
F_146 ( V_4 -> V_173 ) ;
V_4 -> V_168 = NULL ;
V_4 -> V_173 = NULL ;
F_139 ( V_2 ) ;
}
void F_152 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_178 = & V_179 ;
V_2 -> V_180 = & V_181 ;
F_153 ( V_2 ) ;
F_154 ( V_2 , & V_4 -> V_182 , V_183 , 100 ) ;
V_2 -> V_184 = V_185 ;
V_2 -> V_6 |= V_186 | V_187 ;
V_2 -> V_188 = V_189 ;
V_2 -> V_190 = V_123 ;
V_2 -> type = V_191 ;
V_2 -> V_192 = V_174 * 2 ;
V_2 -> V_14 = ( V_193 |
V_194 ) ;
V_2 -> V_195 &= ~ V_196 ;
memcpy ( V_2 -> V_80 , V_197 , V_123 ) ;
F_155 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
F_156 ( & V_4 -> V_54 ) ;
F_157 ( & V_4 -> V_11 ) ;
F_85 ( & V_4 -> V_46 ) ;
F_85 ( & V_4 -> V_198 ) ;
F_85 ( & V_4 -> V_199 ) ;
F_85 ( & V_4 -> V_200 ) ;
F_158 ( & V_4 -> V_201 , V_202 ) ;
F_158 ( & V_4 -> V_203 , V_204 ) ;
F_159 ( & V_4 -> V_205 , V_206 ) ;
F_159 ( & V_4 -> V_207 , V_208 ) ;
F_159 ( & V_4 -> V_209 , V_210 ) ;
F_159 ( & V_4 -> V_211 , V_212 ) ;
F_159 ( & V_4 -> V_126 , V_213 ) ;
F_158 ( & V_4 -> V_214 , V_215 ) ;
F_158 ( & V_4 -> V_153 , F_125 ) ;
}
struct V_3 * F_160 ( const char * V_171 )
{
struct V_1 * V_2 ;
V_2 = F_161 ( ( int ) sizeof ( struct V_3 ) , V_171 ,
F_152 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_5 F_162 ( struct V_216 * V_2 ,
struct V_217 * V_218 , char * V_24 )
{
struct V_3 * V_4 = F_2 ( F_163 ( V_2 ) ) ;
return sprintf ( V_24 , L_26 , V_4 -> V_85 ) ;
}
static T_5 F_164 ( struct V_216 * V_2 ,
struct V_217 * V_218 , char * V_24 )
{
struct V_3 * V_4 = F_2 ( F_163 ( V_2 ) ) ;
return sprintf ( V_24 , L_27 , F_8 ( V_219 , & V_4 -> V_6 ) ) ;
}
void F_165 ( struct V_1 * V_220 , int V_221 )
{
struct V_3 * V_4 = F_2 ( V_220 ) ;
if ( V_221 > 0 ) {
F_4 ( V_219 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_28
L_29 ) ;
} else
F_15 ( V_219 , & V_4 -> V_6 ) ;
}
static T_5 F_166 ( struct V_216 * V_2 ,
struct V_217 * V_218 ,
const char * V_24 , T_6 V_222 )
{
unsigned long V_221 = F_167 ( V_24 , NULL , 0 ) ;
F_165 ( F_163 ( V_2 ) , V_221 ) ;
return V_222 ;
}
int F_168 ( struct V_1 * V_2 )
{
return F_169 ( & V_2 -> V_2 , & V_223 ) ;
}
static T_5 F_170 ( struct V_216 * V_2 ,
struct V_217 * V_218 ,
const char * V_24 , T_6 V_222 )
{
int V_85 ;
int V_35 ;
if ( sscanf ( V_24 , L_30 , & V_85 ) != 1 )
return - V_13 ;
if ( V_85 < 0 || V_85 > 0xffff )
return - V_13 ;
V_85 |= 0x8000 ;
V_35 = F_171 ( F_163 ( V_2 ) , V_85 ) ;
return V_35 ? V_35 : V_222 ;
}
static T_5 F_172 ( struct V_216 * V_2 ,
struct V_217 * V_218 ,
const char * V_24 , T_6 V_222 )
{
int V_85 ;
int V_35 ;
if ( sscanf ( V_24 , L_30 , & V_85 ) != 1 )
return - V_13 ;
if ( V_85 < 0 || V_85 > 0xffff )
return - V_13 ;
V_35 = F_173 ( F_163 ( V_2 ) , V_85 ) ;
return V_35 ? V_35 : V_222 ;
}
int F_174 ( struct V_1 * V_2 )
{
return F_169 ( & V_2 -> V_2 , & V_224 ) ;
}
int F_175 ( struct V_3 * V_4 , struct V_166 * V_225 )
{
struct V_226 * V_227 ;
int V_228 = - V_159 ;
V_227 = F_48 ( sizeof *V_227 , V_53 ) ;
if ( ! V_227 ) {
F_143 ( V_170 L_31 ,
V_225 -> V_171 , sizeof *V_227 ) ;
return V_228 ;
}
V_228 = F_176 ( V_225 , V_227 ) ;
if ( V_228 ) {
F_143 ( V_170 L_32 ,
V_225 -> V_171 , V_228 ) ;
F_46 ( V_227 ) ;
return V_228 ;
}
V_4 -> V_229 = V_227 -> V_230 ;
F_46 ( V_227 ) ;
if ( V_4 -> V_229 & V_231 ) {
V_4 -> V_2 -> V_232 = V_16 |
V_17 | V_233 ;
if ( V_4 -> V_229 & V_234 )
V_4 -> V_2 -> V_232 |= V_18 ;
V_4 -> V_2 -> V_14 |= V_4 -> V_2 -> V_232 ;
}
return 0 ;
}
static struct V_1 * F_177 ( const char * V_235 ,
struct V_166 * V_225 , T_2 V_75 )
{
struct V_3 * V_4 ;
struct V_236 V_218 ;
int V_228 = - V_159 ;
V_4 = F_160 ( V_235 ) ;
if ( ! V_4 )
goto V_237;
F_178 ( V_4 -> V_2 , V_225 -> V_238 ) ;
V_4 -> V_2 -> V_239 = V_75 - 1 ;
if ( ! F_179 ( V_225 , V_75 , & V_218 ) )
V_4 -> V_22 = F_180 ( V_218 . V_240 ) ;
else {
F_143 ( V_170 L_33 ,
V_225 -> V_171 , V_75 ) ;
goto V_241;
}
V_4 -> V_2 -> V_21 = F_26 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_4 -> V_2 -> V_242 = sizeof( struct V_67 ) ;
V_228 = F_181 ( V_225 , V_75 , 0 , & V_4 -> V_85 ) ;
if ( V_228 ) {
F_143 ( V_170 L_34 ,
V_225 -> V_171 , V_75 , V_228 ) ;
goto V_241;
}
if ( F_175 ( V_4 , V_225 ) )
goto V_241;
V_4 -> V_85 |= 0x8000 ;
V_4 -> V_2 -> V_80 [ 8 ] = V_4 -> V_85 >> 8 ;
V_4 -> V_2 -> V_80 [ 9 ] = V_4 -> V_85 & 0xff ;
V_228 = F_182 ( V_225 , V_75 , 0 , & V_4 -> V_84 ) ;
if ( V_228 ) {
F_143 ( V_170 L_35 ,
V_225 -> V_171 , V_75 , V_228 ) ;
goto V_241;
} else
memcpy ( V_4 -> V_2 -> V_25 + 4 , V_4 -> V_84 . V_38 , sizeof ( union V_39 ) ) ;
V_228 = F_142 ( V_4 -> V_2 , V_225 , V_75 ) ;
if ( V_228 < 0 ) {
F_143 ( V_170 L_36 ,
V_225 -> V_171 , V_75 , V_228 ) ;
goto V_241;
}
F_183 ( & V_4 -> V_243 ,
V_4 -> V_74 , V_244 ) ;
V_228 = F_184 ( & V_4 -> V_243 ) ;
if ( V_228 < 0 ) {
F_143 ( V_170 L_37
L_38 ,
V_225 -> V_171 , V_75 , V_228 ) ;
goto V_245;
}
V_228 = F_185 ( V_4 -> V_2 ) ;
if ( V_228 ) {
F_143 ( V_170 L_39 ,
V_225 -> V_171 , V_75 , V_228 ) ;
goto V_246;
}
F_186 ( V_4 -> V_2 ) ;
if ( F_187 ( V_4 -> V_2 ) )
goto V_247;
if ( F_174 ( V_4 -> V_2 ) )
goto V_247;
if ( F_168 ( V_4 -> V_2 ) )
goto V_247;
if ( F_169 ( & V_4 -> V_2 -> V_2 , & V_248 ) )
goto V_247;
if ( F_169 ( & V_4 -> V_2 -> V_2 , & V_249 ) )
goto V_247;
return V_4 -> V_2 ;
V_247:
F_148 ( V_4 -> V_2 ) ;
F_188 ( V_4 -> V_2 ) ;
V_246:
F_189 ( & V_4 -> V_243 ) ;
F_4 ( V_144 , & V_4 -> V_6 ) ;
F_141 ( & V_4 -> V_153 ) ;
F_190 ( V_125 ) ;
V_245:
F_20 ( V_4 -> V_2 ) ;
V_241:
F_191 ( V_4 -> V_2 ) ;
V_237:
return F_192 ( V_228 ) ;
}
static void F_193 ( struct V_166 * V_216 )
{
struct V_250 * V_251 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_252 , V_253 , V_254 ;
if ( F_194 ( V_216 -> V_255 ) != V_256 )
return;
V_251 = F_48 ( sizeof *V_251 , V_53 ) ;
if ( ! V_251 )
return;
F_85 ( V_251 ) ;
if ( V_216 -> V_255 == V_257 ) {
V_252 = 0 ;
V_253 = 0 ;
} else {
V_252 = 1 ;
V_253 = V_216 -> V_258 ;
}
for ( V_254 = V_252 ; V_254 <= V_253 ; ++ V_254 ) {
if ( F_195 ( V_216 , V_254 ) != V_259 )
continue;
V_2 = F_177 ( L_40 , V_216 , V_254 ) ;
if ( ! F_196 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_40 ( & V_4 -> V_45 , V_251 ) ;
}
}
F_197 ( V_216 , & V_260 , V_251 ) ;
}
static void F_198 ( struct V_166 * V_216 )
{
struct V_3 * V_4 , * V_261 ;
struct V_250 * V_251 ;
if ( F_194 ( V_216 -> V_255 ) != V_256 )
return;
V_251 = F_199 ( V_216 , & V_260 ) ;
if ( ! V_251 )
return;
F_56 (priv, tmp, dev_list, list) {
F_189 ( & V_4 -> V_243 ) ;
F_33 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_12 ) ;
F_31 () ;
F_4 ( V_144 , & V_4 -> V_6 ) ;
F_141 ( & V_4 -> V_153 ) ;
F_190 ( V_125 ) ;
F_188 ( V_4 -> V_2 ) ;
F_191 ( V_4 -> V_2 ) ;
}
F_46 ( V_251 ) ;
}
static int T_7 F_200 ( void )
{
int V_35 ;
V_169 = F_135 ( V_169 ) ;
V_169 = F_27 ( V_169 , V_262 ) ;
V_169 = F_201 ( V_169 , V_263 ) ;
V_174 = F_135 ( V_174 ) ;
V_174 = F_27 ( V_174 , V_262 ) ;
V_174 = F_202 ( V_174 , 2 * V_264 , V_263 ) ;
#ifdef F_203
V_265 = F_27 ( V_265 , V_266 ) ;
#endif
F_204 ( V_267 > V_268 ) ;
V_35 = F_205 () ;
if ( V_35 )
return V_35 ;
V_125 = F_206 ( L_41 ) ;
if ( ! V_125 ) {
V_35 = - V_159 ;
goto V_269;
}
F_207 ( & V_89 ) ;
V_35 = F_208 ( & V_260 ) ;
if ( V_35 )
goto V_270;
V_35 = F_209 () ;
if ( V_35 )
goto V_271;
return 0 ;
V_271:
F_210 ( & V_260 ) ;
V_270:
F_211 ( & V_89 ) ;
F_212 ( V_125 ) ;
V_269:
F_213 () ;
return V_35 ;
}
static void T_8 F_214 ( void )
{
F_215 () ;
F_210 ( & V_260 ) ;
F_211 ( & V_89 ) ;
F_213 () ;
F_212 ( V_125 ) ;
}
