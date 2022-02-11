int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 ( V_5 , & V_4 -> V_6 ) ;
if ( F_6 ( V_2 ) )
return 0 ;
if ( F_7 ( V_2 ) )
goto V_7;
if ( F_8 ( V_2 ) )
goto V_8;
if ( ! F_9 ( V_9 , & V_4 -> V_6 ) ) {
struct V_3 * V_10 ;
F_10 ( & V_4 -> V_11 ) ;
F_11 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_10 -> V_2 -> V_6 ;
if ( V_6 & V_12 )
continue;
F_12 ( V_10 -> V_2 , V_6 | V_12 ) ;
}
F_13 ( & V_4 -> V_11 ) ;
}
F_14 ( V_2 ) ;
return 0 ;
V_8:
F_15 ( V_2 , 1 ) ;
V_7:
F_16 ( V_5 , & V_4 -> V_6 ) ;
return - V_13 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_2 ) ;
F_16 ( V_5 , & V_4 -> V_6 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , 1 ) ;
F_15 ( V_2 , 0 ) ;
if ( ! F_9 ( V_9 , & V_4 -> V_6 ) ) {
struct V_3 * V_10 ;
F_10 ( & V_4 -> V_11 ) ;
F_11 (cpriv, &priv->child_intfs, list) {
int V_6 ;
V_6 = V_10 -> V_2 -> V_6 ;
if ( ! ( V_6 & V_12 ) )
continue;
F_12 ( V_10 -> V_2 , V_6 & ~ V_12 ) ;
}
F_13 ( & V_4 -> V_11 ) ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_9 ( V_15 , & V_4 -> V_6 ) )
V_14 &= ~ ( V_16 | V_17 | V_18 ) ;
return V_14 ;
}
static int F_23 ( struct V_1 * V_2 , int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_24 ( V_2 ) ) {
if ( V_19 > F_25 ( V_2 ) )
return - V_13 ;
if ( V_19 > V_4 -> V_20 )
F_26 ( V_4 , L_3 ,
V_4 -> V_20 ) ;
V_2 -> V_21 = V_19 ;
return 0 ;
}
if ( V_19 > F_27 ( V_4 -> V_22 ) )
return - V_13 ;
V_4 -> V_23 = V_19 ;
V_2 -> V_21 = F_28 ( V_4 -> V_20 , V_4 -> V_23 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , const char * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_30 ( V_2 -> V_25 ) && ! strcmp ( V_24 , L_4 ) ) {
F_5 ( V_15 , & V_4 -> V_6 ) ;
F_26 ( V_4 , L_5
L_6 ) ;
F_31 ( V_2 ) ;
F_32 () ;
V_4 -> V_26 . V_27 &= ~ V_28 ;
F_33 ( V_2 ) ;
F_34 () ;
return 0 ;
}
if ( ! strcmp ( V_24 , L_7 ) ) {
F_16 ( V_15 , & V_4 -> V_6 ) ;
F_31 ( V_2 ) ;
F_35 ( V_2 , F_28 ( V_4 -> V_20 , V_2 -> V_21 ) ) ;
F_32 () ;
F_33 ( V_2 ) ;
F_34 () ;
return 0 ;
}
return - V_13 ;
}
static struct V_29 * F_36 ( struct V_1 * V_2 , void * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * V_32 = V_4 -> V_33 . V_31 ;
struct V_29 * V_34 ;
int V_35 ;
while ( V_32 ) {
V_34 = F_37 ( V_32 , struct V_29 , V_31 ) ;
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
static int F_38 ( struct V_1 * V_2 , struct V_29 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_31 * * V_32 = & V_4 -> V_33 . V_31 ;
struct V_31 * V_42 = NULL ;
struct V_29 * V_43 ;
int V_35 ;
while ( * V_32 ) {
V_42 = * V_32 ;
V_43 = F_37 ( V_42 , struct V_29 , V_31 ) ;
V_35 = memcmp ( V_34 -> V_36 . V_37 . V_38 , V_43 -> V_36 . V_37 . V_38 ,
sizeof ( union V_39 ) ) ;
if ( V_35 < 0 )
V_32 = & V_42 -> V_40 ;
else if ( V_35 > 0 )
V_32 = & V_42 -> V_41 ;
else
return - V_44 ;
}
F_39 ( & V_34 -> V_31 , V_42 , V_32 ) ;
F_40 ( & V_34 -> V_31 , & V_4 -> V_33 ) ;
F_41 ( & V_34 -> V_45 , & V_4 -> V_46 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_29 * V_34 )
{
struct V_47 * V_48 ;
while ( ( V_48 = F_43 ( & V_34 -> V_49 ) ) )
F_44 ( V_48 ) ;
F_3 ( F_2 ( V_2 ) , L_8 ) ;
F_45 ( V_2 , V_34 -> V_36 . V_37 . V_38 ) ;
if ( V_34 -> V_50 )
F_46 ( V_34 -> V_50 ) ;
F_47 ( V_34 ) ;
}
struct V_51 * F_48 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
V_52 = F_49 ( sizeof *V_52 , V_53 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_2 = V_2 ;
memset ( V_52 -> V_34 . V_36 . V_37 . V_38 , 0 , 16 ) ;
if ( F_50 ( V_52 ) ) {
F_47 ( V_52 ) ;
return NULL ;
}
return V_52 ;
}
int F_50 ( struct V_51 * V_52 )
{
struct V_3 * V_4 = F_2 ( V_52 -> V_2 ) ;
struct V_31 * V_32 ;
struct V_29 * V_34 ;
int V_35 = 1 ;
F_51 ( & V_4 -> V_54 ) ;
V_32 = F_52 ( & V_4 -> V_33 ) ;
while ( V_32 ) {
V_34 = F_37 ( V_32 , struct V_29 , V_31 ) ;
if ( memcmp ( V_52 -> V_34 . V_36 . V_37 . V_38 , V_34 -> V_36 . V_37 . V_38 ,
sizeof ( union V_39 ) ) < 0 ) {
V_52 -> V_34 = * V_34 ;
V_35 = 0 ;
break;
}
V_32 = F_53 ( V_32 ) ;
}
F_54 ( & V_4 -> V_54 ) ;
return V_35 ;
}
void F_55 ( struct V_51 * V_52 ,
struct V_29 * V_34 )
{
* V_34 = V_52 -> V_34 ;
}
void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 , * V_55 ;
F_51 ( & V_4 -> V_54 ) ;
F_57 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_9 ,
F_58 ( V_34 -> V_36 . V_56 ) ,
V_34 -> V_36 . V_37 . V_38 ) ;
V_34 -> V_57 = 0 ;
}
F_54 ( & V_4 -> V_54 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 , * V_55 ;
F_59 ( V_58 ) ;
unsigned long V_6 ;
F_60 ( V_2 ) ;
F_61 ( & V_4 -> V_54 , V_6 ) ;
F_62 ( & V_4 -> V_46 , & V_58 ) ;
F_11 (path, &remove_list, list)
F_63 ( & V_34 -> V_31 , & V_4 -> V_33 ) ;
F_57 (path, tp, &remove_list, list) {
if ( V_34 -> V_59 )
F_64 ( V_34 -> V_60 , V_34 -> V_59 ) ;
F_65 ( & V_4 -> V_54 , V_6 ) ;
F_66 ( V_2 ) ;
F_67 ( & V_34 -> V_61 ) ;
F_42 ( V_2 , V_34 ) ;
F_60 ( V_2 ) ;
F_61 ( & V_4 -> V_54 , V_6 ) ;
}
F_65 ( & V_4 -> V_54 , V_6 ) ;
F_66 ( V_2 ) ;
}
static void F_68 ( int V_62 ,
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
F_58 ( V_36 -> V_56 ) , V_36 -> V_37 . V_38 ) ;
else
F_3 ( V_4 , L_11 ,
V_62 , V_34 -> V_36 . V_37 . V_38 ) ;
F_69 ( & V_71 ) ;
if ( ! V_62 ) {
struct V_72 V_73 ;
if ( ! F_70 ( V_4 -> V_74 , V_4 -> V_75 , V_36 , & V_73 ) )
V_50 = F_71 ( V_2 , V_4 -> V_76 , & V_73 ) ;
}
F_61 ( & V_4 -> V_54 , V_6 ) ;
if ( ! F_72 ( V_50 ) ) {
V_34 -> V_36 = * V_36 ;
V_66 = V_34 -> V_50 ;
V_34 -> V_50 = V_50 ;
F_3 ( V_4 , L_12 ,
V_50 , F_58 ( V_36 -> V_56 ) , V_36 -> V_77 ) ;
while ( ( V_48 = F_43 ( & V_34 -> V_49 ) ) )
F_73 ( & V_71 , V_48 ) ;
F_57 (neigh, tn, &path->neigh_list, list) {
if ( V_68 -> V_50 ) {
F_74 ( V_68 -> V_50 != V_66 ) ;
F_46 ( V_68 -> V_50 ) ;
}
F_75 ( & V_34 -> V_50 -> V_78 ) ;
V_68 -> V_50 = V_34 -> V_50 ;
if ( F_76 ( V_2 , V_68 -> V_79 ) ) {
if ( ! F_77 ( V_68 ) )
F_78 ( V_68 , F_79 ( V_2 ,
V_34 ,
V_68 ) ) ;
if ( ! F_77 ( V_68 ) ) {
F_80 ( V_68 ) ;
continue;
}
}
while ( ( V_48 = F_43 ( & V_68 -> V_49 ) ) )
F_73 ( & V_71 , V_48 ) ;
}
V_34 -> V_57 = 1 ;
}
V_34 -> V_59 = NULL ;
F_81 ( & V_34 -> V_61 ) ;
F_65 ( & V_4 -> V_54 , V_6 ) ;
if ( F_72 ( V_50 ) )
F_45 ( V_2 , V_34 -> V_36 . V_37 . V_38 ) ;
if ( V_66 )
F_46 ( V_66 ) ;
while ( ( V_48 = F_43 ( & V_71 ) ) ) {
V_48 -> V_2 = V_2 ;
if ( F_82 ( V_48 ) )
F_26 ( V_4 , L_13
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
F_69 ( & V_34 -> V_49 ) ;
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
F_68 ,
V_34 , & V_34 -> V_59 ) ;
if ( V_34 -> V_60 < 0 ) {
F_26 ( V_4 , L_16 , V_34 -> V_60 ) ;
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
F_61 ( & V_4 -> V_54 , V_6 ) ;
V_68 = F_91 ( V_79 , V_2 ) ;
if ( ! V_68 ) {
F_65 ( & V_4 -> V_54 , V_6 ) ;
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
return;
}
V_34 = F_36 ( V_2 , V_79 + 4 ) ;
if ( ! V_34 ) {
V_34 = F_83 ( V_2 , V_79 + 4 ) ;
if ( ! V_34 )
goto V_97;
F_38 ( V_2 , V_34 ) ;
}
F_41 ( & V_68 -> V_45 , & V_34 -> V_82 ) ;
if ( V_34 -> V_50 ) {
F_75 ( & V_34 -> V_50 -> V_78 ) ;
V_68 -> V_50 = V_34 -> V_50 ;
if ( F_76 ( V_2 , V_68 -> V_79 ) ) {
if ( ! F_77 ( V_68 ) )
F_78 ( V_68 , F_79 ( V_2 , V_34 , V_68 ) ) ;
if ( ! F_77 ( V_68 ) ) {
F_80 ( V_68 ) ;
goto V_98;
}
if ( F_93 ( & V_68 -> V_49 ) < V_99 )
F_73 ( & V_68 -> V_49 , V_48 ) ;
else {
F_26 ( V_4 , L_17 ,
F_93 ( & V_68 -> V_49 ) ) ;
goto V_98;
}
} else {
F_65 ( & V_4 -> V_54 , V_6 ) ;
F_94 ( V_2 , V_48 , V_34 -> V_50 , F_95 ( V_79 ) ) ;
F_96 ( V_68 ) ;
return;
}
} else {
V_68 -> V_50 = NULL ;
if ( ! V_34 -> V_59 && F_87 ( V_2 , V_34 ) )
goto V_97;
F_73 ( & V_68 -> V_49 , V_48 ) ;
}
F_65 ( & V_4 -> V_54 , V_6 ) ;
F_96 ( V_68 ) ;
return;
V_97:
F_80 ( V_68 ) ;
V_98:
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
F_65 ( & V_4 -> V_54 , V_6 ) ;
F_96 ( V_68 ) ;
}
static void F_97 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 ;
unsigned long V_6 ;
F_61 ( & V_4 -> V_54 , V_6 ) ;
V_34 = F_36 ( V_2 , V_101 -> V_102 + 4 ) ;
if ( ! V_34 || ! V_34 -> V_57 ) {
int V_103 = 0 ;
if ( ! V_34 ) {
V_34 = F_83 ( V_2 , V_101 -> V_102 + 4 ) ;
V_103 = 1 ;
}
if ( V_34 ) {
F_73 ( & V_34 -> V_49 , V_48 ) ;
if ( ! V_34 -> V_59 && F_87 ( V_2 , V_34 ) ) {
F_65 ( & V_4 -> V_54 , V_6 ) ;
if ( V_103 )
F_42 ( V_2 , V_34 ) ;
return;
} else
F_38 ( V_2 , V_34 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
}
F_65 ( & V_4 -> V_54 , V_6 ) ;
return;
}
if ( V_34 -> V_50 ) {
F_3 ( V_4 , L_18 ,
F_58 ( V_34 -> V_36 . V_56 ) ) ;
F_65 ( & V_4 -> V_54 , V_6 ) ;
F_94 ( V_2 , V_48 , V_34 -> V_50 , F_95 ( V_101 -> V_102 ) ) ;
return;
} else if ( ( V_34 -> V_59 || ! F_87 ( V_2 , V_34 ) ) &&
F_93 ( & V_34 -> V_49 ) < V_99 ) {
F_73 ( & V_34 -> V_49 , V_48 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
}
F_65 ( & V_4 -> V_54 , V_6 ) ;
}
static int F_98 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_67 * V_68 ;
struct V_100 * V_101 = (struct V_100 * ) V_48 -> V_101 ;
struct V_104 * V_105 ;
unsigned long V_6 ;
V_105 = (struct V_104 * ) V_48 -> V_106 ;
if ( F_99 ( V_101 -> V_102 [ 4 ] == 0xff ) ) {
if ( ( V_105 -> V_107 != F_100 ( V_108 ) ) &&
( V_105 -> V_107 != F_100 ( V_109 ) ) &&
( V_105 -> V_107 != F_100 ( V_110 ) ) &&
( V_105 -> V_107 != F_100 ( V_111 ) ) &&
( V_105 -> V_107 != F_100 ( V_112 ) ) ) {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
return V_113 ;
}
V_101 -> V_102 [ 8 ] = ( V_4 -> V_85 >> 8 ) & 0xff ;
V_101 -> V_102 [ 9 ] = V_4 -> V_85 & 0xff ;
V_68 = F_101 ( V_2 , V_101 -> V_102 ) ;
if ( F_102 ( V_68 ) )
goto V_114;
F_103 ( V_2 , V_101 -> V_102 , V_48 ) ;
return V_113 ;
}
switch ( V_105 -> V_107 ) {
case F_100 ( V_108 ) :
case F_100 ( V_109 ) :
case F_100 ( V_112 ) :
V_68 = F_101 ( V_2 , V_101 -> V_102 ) ;
if ( F_99 ( ! V_68 ) ) {
F_90 ( V_48 , V_101 -> V_102 , V_2 ) ;
return V_113 ;
}
break;
case F_100 ( V_110 ) :
case F_100 ( V_111 ) :
F_97 ( V_48 , V_2 , V_101 ) ;
return V_113 ;
default:
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
return V_113 ;
}
V_114:
if ( F_77 ( V_68 ) ) {
if ( F_104 ( V_68 ) ) {
F_105 ( V_2 , V_48 , F_77 ( V_68 ) ) ;
goto V_115;
}
} else if ( V_68 -> V_50 ) {
F_94 ( V_2 , V_48 , V_68 -> V_50 , F_95 ( V_101 -> V_102 ) ) ;
goto V_115;
}
if ( F_93 ( & V_68 -> V_49 ) < V_99 ) {
F_61 ( & V_4 -> V_54 , V_6 ) ;
F_73 ( & V_68 -> V_49 , V_48 ) ;
F_65 ( & V_4 -> V_54 , V_6 ) ;
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
F_26 ( V_4 , L_19 ,
F_107 ( V_116 - V_2 -> V_117 ) ) ;
F_26 ( V_4 , L_20 ,
F_108 ( V_2 ) ,
V_4 -> V_118 , V_4 -> V_119 ) ;
}
static int F_109 ( struct V_47 * V_48 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_79 , const void * V_120 , unsigned V_121 )
{
struct V_104 * V_105 ;
struct V_100 * V_101 = (struct V_100 * ) V_48 -> V_101 ;
V_105 = (struct V_104 * ) F_110 ( V_48 , sizeof *V_105 ) ;
V_105 -> V_107 = F_100 ( type ) ;
V_105 -> V_122 = 0 ;
memcpy ( V_101 -> V_102 , V_79 , V_123 ) ;
return sizeof *V_105 ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_9 ( V_124 , & V_4 -> V_6 ) ) {
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
if ( F_9 ( V_144 , & V_4 -> V_6 ) )
return;
F_61 ( & V_4 -> V_54 , V_6 ) ;
V_128 = F_120 ( V_134 -> V_128 ,
F_121 ( & V_4 -> V_54 ) ) ;
if ( ! V_128 )
goto V_136;
V_142 = 2 * V_145 . V_146 ;
V_141 = V_116 - V_142 ;
if ( F_9 ( V_144 , & V_4 -> V_6 ) )
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
F_124 ( & V_68 -> V_45 ) ;
F_125 ( & V_68 -> V_149 , V_150 ) ;
} else {
V_148 = & V_68 -> V_138 ;
}
}
}
V_136:
F_65 ( & V_4 -> V_54 , V_6 ) ;
}
static void F_126 ( struct V_151 * V_152 )
{
struct V_3 * V_4 =
F_127 ( V_152 , struct V_3 , V_153 . V_152 ) ;
F_119 ( V_4 ) ;
if ( ! F_9 ( V_144 , & V_4 -> V_6 ) )
F_128 ( V_125 , & V_4 -> V_153 ,
V_145 . V_146 ) ;
}
static struct V_67 * F_129 ( T_2 * V_79 ,
struct V_1 * V_2 )
{
struct V_67 * V_68 ;
V_68 = F_84 ( sizeof *V_68 , V_81 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_2 = V_2 ;
memcpy ( & V_68 -> V_79 , V_79 , sizeof( V_68 -> V_79 ) ) ;
F_69 ( & V_68 -> V_49 ) ;
F_85 ( & V_68 -> V_45 ) ;
F_78 ( V_68 , NULL ) ;
F_130 ( & V_68 -> V_139 , 1 ) ;
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
V_68 = F_129 ( V_79 , V_2 ) ;
if ( ! V_68 )
goto V_136;
F_131 ( & V_68 -> V_139 ) ;
V_68 -> V_140 = V_116 ;
F_123 ( V_68 -> V_138 ,
F_120 ( V_128 -> V_137 [ V_135 ] ,
F_121 ( & V_4 -> V_54 ) ) ) ;
F_123 ( V_128 -> V_137 [ V_135 ] , V_68 ) ;
F_131 ( & V_134 -> V_154 ) ;
V_136:
return V_68 ;
}
void F_132 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 ;
if ( V_68 -> V_50 )
F_46 ( V_68 -> V_50 ) ;
while ( ( V_48 = F_43 ( & V_68 -> V_49 ) ) ) {
++ V_2 -> V_95 . V_96 ;
F_92 ( V_48 ) ;
}
if ( F_77 ( V_68 ) )
F_133 ( F_77 ( V_68 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_22 ,
F_95 ( V_68 -> V_79 ) ,
V_68 -> V_79 + 4 ) ;
F_47 ( V_68 ) ;
if ( F_134 ( & V_4 -> V_134 . V_154 ) ) {
if ( F_9 ( V_155 , & V_4 -> V_6 ) )
F_81 ( & V_4 -> V_134 . V_156 ) ;
}
}
static void V_150 ( struct V_157 * V_158 )
{
struct V_67 * V_68 = F_127 ( V_158 , struct V_67 , V_149 ) ;
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
F_124 ( & V_68 -> V_45 ) ;
F_125 ( & V_68 -> V_149 , V_150 ) ;
return;
} else {
V_148 = & V_32 -> V_138 ;
}
}
}
static int F_135 ( struct V_3 * V_4 )
{
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
struct V_67 * * V_137 ;
T_3 V_147 ;
F_16 ( V_155 , & V_4 -> V_6 ) ;
V_134 -> V_128 = NULL ;
V_128 = F_84 ( sizeof( * V_128 ) , V_53 ) ;
if ( ! V_128 )
return - V_159 ;
F_5 ( V_144 , & V_4 -> V_6 ) ;
V_147 = F_136 ( V_145 . V_160 ) ;
V_137 = F_84 ( V_147 * sizeof( * V_137 ) , V_53 ) ;
if ( ! V_137 ) {
F_47 ( V_128 ) ;
return - V_159 ;
}
V_128 -> V_147 = V_147 ;
V_128 -> V_132 = ( V_147 - 1 ) ;
V_128 -> V_137 = V_137 ;
V_134 -> V_128 = V_128 ;
V_128 -> V_134 = V_134 ;
F_130 ( & V_134 -> V_154 , 0 ) ;
F_16 ( V_144 , & V_4 -> V_6 ) ;
F_128 ( V_125 , & V_4 -> V_153 ,
V_145 . V_146 ) ;
return 0 ;
}
static void F_137 ( struct V_157 * V_161 )
{
struct V_127 * V_128 = F_127 ( V_161 ,
struct V_127 ,
V_149 ) ;
struct V_67 T_4 * * V_137 = V_128 -> V_137 ;
struct V_133 * V_134 = V_128 -> V_134 ;
F_47 ( V_137 ) ;
F_47 ( V_128 ) ;
F_81 ( & V_134 -> V_162 ) ;
}
void F_45 ( struct V_1 * V_2 , T_2 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
unsigned long V_6 ;
int V_143 ;
F_61 ( & V_4 -> V_54 , V_6 ) ;
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
F_124 ( & V_68 -> V_45 ) ;
F_125 ( & V_68 -> V_149 , V_150 ) ;
} else {
V_148 = & V_68 -> V_138 ;
}
}
}
V_136:
F_65 ( & V_4 -> V_54 , V_6 ) ;
}
static void F_138 ( struct V_3 * V_4 )
{
struct V_133 * V_134 = & V_4 -> V_134 ;
struct V_127 * V_128 ;
unsigned long V_6 ;
int V_143 , V_163 = 0 ;
F_88 ( & V_4 -> V_134 . V_156 ) ;
F_61 ( & V_4 -> V_54 , V_6 ) ;
V_128 = F_120 ( V_134 -> V_128 ,
F_121 ( & V_4 -> V_54 ) ) ;
if ( ! V_128 )
goto V_136;
V_163 = F_139 ( & V_4 -> V_134 . V_154 ) ;
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
F_124 ( & V_68 -> V_45 ) ;
F_125 ( & V_68 -> V_149 , V_150 ) ;
}
}
V_164:
F_123 ( V_134 -> V_128 , NULL ) ;
F_125 ( & V_128 -> V_149 , F_137 ) ;
V_136:
F_65 ( & V_4 -> V_54 , V_6 ) ;
if ( V_163 )
F_67 ( & V_4 -> V_134 . V_156 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_165 ;
F_3 ( V_4 , L_23 ) ;
F_88 ( & V_4 -> V_134 . V_162 ) ;
F_5 ( V_155 , & V_4 -> V_6 ) ;
V_165 = F_141 ( V_144 , & V_4 -> V_6 ) ;
if ( ! V_165 )
F_142 ( & V_4 -> V_153 ) ;
F_138 ( V_4 ) ;
F_67 ( & V_4 -> V_134 . V_162 ) ;
}
int F_143 ( struct V_1 * V_2 , struct V_166 * V_74 , int V_75 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_135 ( V_4 ) < 0 )
goto V_167;
V_4 -> V_168 = F_84 ( V_169 * sizeof * V_4 -> V_168 ,
V_53 ) ;
if ( ! V_4 -> V_168 ) {
F_144 ( V_170 L_24 ,
V_74 -> V_171 , V_169 ) ;
goto V_172;
}
V_4 -> V_173 = F_145 ( V_174 * sizeof * V_4 -> V_173 ) ;
if ( ! V_4 -> V_173 ) {
F_144 ( V_170 L_25 ,
V_74 -> V_171 , V_174 ) ;
goto V_175;
}
if ( F_146 ( V_2 , V_74 , V_75 ) )
goto V_176;
return 0 ;
V_176:
F_147 ( V_4 -> V_173 ) ;
V_175:
F_47 ( V_4 -> V_168 ) ;
V_172:
F_140 ( V_2 ) ;
V_167:
return - V_159 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_10 , * V_177 ;
F_59 ( V_161 ) ;
F_148 () ;
F_149 ( V_2 ) ;
F_57 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_144 , & V_10 -> V_6 ) ;
F_142 ( & V_10 -> V_153 ) ;
F_150 ( V_10 -> V_2 , & V_161 ) ;
}
F_151 ( & V_161 ) ;
F_152 ( V_2 ) ;
F_47 ( V_4 -> V_168 ) ;
F_147 ( V_4 -> V_173 ) ;
V_4 -> V_168 = NULL ;
V_4 -> V_173 = NULL ;
F_140 ( V_2 ) ;
}
void F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_178 = & V_179 ;
V_2 -> V_180 = & V_181 ;
F_154 ( V_2 ) ;
F_155 ( V_2 , & V_4 -> V_182 , V_183 , V_184 ) ;
V_2 -> V_185 = V_186 ;
V_2 -> V_6 |= V_187 | V_188 ;
V_2 -> V_189 = V_190 ;
V_2 -> V_191 = V_123 ;
V_2 -> type = V_192 ;
V_2 -> V_193 = V_174 * 2 ;
V_2 -> V_14 = ( V_194 |
V_195 ) ;
V_2 -> V_196 &= ~ V_197 ;
memcpy ( V_2 -> V_80 , V_198 , V_123 ) ;
V_4 -> V_2 = V_2 ;
F_156 ( & V_4 -> V_54 ) ;
F_157 ( & V_4 -> V_11 ) ;
F_85 ( & V_4 -> V_46 ) ;
F_85 ( & V_4 -> V_199 ) ;
F_85 ( & V_4 -> V_200 ) ;
F_85 ( & V_4 -> V_201 ) ;
F_158 ( & V_4 -> V_202 , V_203 ) ;
F_158 ( & V_4 -> V_204 , V_205 ) ;
F_159 ( & V_4 -> V_206 , V_207 ) ;
F_159 ( & V_4 -> V_208 , V_209 ) ;
F_159 ( & V_4 -> V_210 , V_211 ) ;
F_159 ( & V_4 -> V_212 , V_213 ) ;
F_159 ( & V_4 -> V_126 , V_214 ) ;
F_158 ( & V_4 -> V_215 , V_216 ) ;
F_158 ( & V_4 -> V_153 , F_126 ) ;
}
struct V_3 * F_160 ( const char * V_171 )
{
struct V_1 * V_2 ;
V_2 = F_161 ( ( int ) sizeof ( struct V_3 ) , V_171 ,
F_153 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_5 F_162 ( struct V_217 * V_2 ,
struct V_218 * V_219 , char * V_24 )
{
struct V_3 * V_4 = F_2 ( F_163 ( V_2 ) ) ;
return sprintf ( V_24 , L_26 , V_4 -> V_85 ) ;
}
static T_5 F_164 ( struct V_217 * V_2 ,
struct V_218 * V_219 , char * V_24 )
{
struct V_3 * V_4 = F_2 ( F_163 ( V_2 ) ) ;
return sprintf ( V_24 , L_27 , F_9 ( V_220 , & V_4 -> V_6 ) ) ;
}
void F_165 ( struct V_1 * V_221 , int V_222 )
{
struct V_3 * V_4 = F_2 ( V_221 ) ;
if ( V_222 > 0 ) {
F_5 ( V_220 , & V_4 -> V_6 ) ;
F_26 ( V_4 , L_28
L_29 ) ;
} else
F_16 ( V_220 , & V_4 -> V_6 ) ;
}
static T_5 F_166 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_24 , T_6 V_223 )
{
unsigned long V_222 = F_167 ( V_24 , NULL , 0 ) ;
F_165 ( F_163 ( V_2 ) , V_222 ) ;
return V_223 ;
}
int F_168 ( struct V_1 * V_2 )
{
return F_169 ( & V_2 -> V_2 , & V_224 ) ;
}
static T_5 F_170 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_24 , T_6 V_223 )
{
int V_85 ;
int V_35 ;
if ( sscanf ( V_24 , L_30 , & V_85 ) != 1 )
return - V_13 ;
if ( V_85 <= 0 || V_85 > 0xffff || V_85 == 0x8000 )
return - V_13 ;
V_85 |= 0x8000 ;
V_35 = F_171 ( F_163 ( V_2 ) , V_85 ) ;
return V_35 ? V_35 : V_223 ;
}
static T_5 F_172 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_24 , T_6 V_223 )
{
int V_85 ;
int V_35 ;
if ( sscanf ( V_24 , L_30 , & V_85 ) != 1 )
return - V_13 ;
if ( V_85 < 0 || V_85 > 0xffff )
return - V_13 ;
V_35 = F_173 ( F_163 ( V_2 ) , V_85 ) ;
return V_35 ? V_35 : V_223 ;
}
int F_174 ( struct V_1 * V_2 )
{
return F_169 ( & V_2 -> V_2 , & V_225 ) ;
}
int F_175 ( struct V_3 * V_4 , struct V_166 * V_226 )
{
struct V_227 * V_228 ;
int V_229 = - V_159 ;
V_228 = F_49 ( sizeof *V_228 , V_53 ) ;
if ( ! V_228 ) {
F_144 ( V_170 L_31 ,
V_226 -> V_171 , sizeof *V_228 ) ;
return V_229 ;
}
V_229 = F_176 ( V_226 , V_228 ) ;
if ( V_229 ) {
F_144 ( V_170 L_32 ,
V_226 -> V_171 , V_229 ) ;
F_47 ( V_228 ) ;
return V_229 ;
}
V_4 -> V_230 = V_228 -> V_231 ;
F_47 ( V_228 ) ;
if ( V_4 -> V_230 & V_232 ) {
V_4 -> V_2 -> V_233 = V_16 |
V_17 | V_234 ;
if ( V_4 -> V_230 & V_235 )
V_4 -> V_2 -> V_233 |= V_18 ;
V_4 -> V_2 -> V_14 |= V_4 -> V_2 -> V_233 ;
}
return 0 ;
}
static struct V_1 * F_177 ( const char * V_236 ,
struct V_166 * V_226 , T_2 V_75 )
{
struct V_3 * V_4 ;
struct V_237 V_219 ;
int V_229 = - V_159 ;
V_4 = F_160 ( V_236 ) ;
if ( ! V_4 )
goto V_238;
F_178 ( V_4 -> V_2 , V_226 -> V_239 ) ;
V_4 -> V_2 -> V_240 = V_75 - 1 ;
if ( ! F_179 ( V_226 , V_75 , & V_219 ) )
V_4 -> V_22 = F_180 ( V_219 . V_241 ) ;
else {
F_144 ( V_170 L_33 ,
V_226 -> V_171 , V_75 ) ;
goto V_242;
}
V_4 -> V_2 -> V_21 = F_27 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_4 -> V_2 -> V_243 = sizeof( struct V_67 ) ;
V_229 = F_181 ( V_226 , V_75 , 0 , & V_4 -> V_85 ) ;
if ( V_229 ) {
F_144 ( V_170 L_34 ,
V_226 -> V_171 , V_75 , V_229 ) ;
goto V_242;
}
if ( F_175 ( V_4 , V_226 ) )
goto V_242;
V_4 -> V_85 |= 0x8000 ;
V_4 -> V_2 -> V_80 [ 8 ] = V_4 -> V_85 >> 8 ;
V_4 -> V_2 -> V_80 [ 9 ] = V_4 -> V_85 & 0xff ;
V_229 = F_182 ( V_226 , V_75 , 0 , & V_4 -> V_84 ) ;
if ( V_229 ) {
F_144 ( V_170 L_35 ,
V_226 -> V_171 , V_75 , V_229 ) ;
goto V_242;
} else
memcpy ( V_4 -> V_2 -> V_25 + 4 , V_4 -> V_84 . V_38 , sizeof ( union V_39 ) ) ;
V_229 = F_143 ( V_4 -> V_2 , V_226 , V_75 ) ;
if ( V_229 < 0 ) {
F_144 ( V_170 L_36 ,
V_226 -> V_171 , V_75 , V_229 ) ;
goto V_242;
}
F_183 ( & V_4 -> V_244 ,
V_4 -> V_74 , V_245 ) ;
V_229 = F_184 ( & V_4 -> V_244 ) ;
if ( V_229 < 0 ) {
F_144 ( V_170 L_37
L_38 ,
V_226 -> V_171 , V_75 , V_229 ) ;
goto V_246;
}
V_229 = F_185 ( V_4 -> V_2 ) ;
if ( V_229 ) {
F_144 ( V_170 L_39 ,
V_226 -> V_171 , V_75 , V_229 ) ;
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
F_5 ( V_144 , & V_4 -> V_6 ) ;
F_142 ( & V_4 -> V_153 ) ;
F_190 ( V_125 ) ;
V_246:
F_21 ( V_4 -> V_2 ) ;
V_242:
F_191 ( V_4 -> V_2 ) ;
V_238:
return F_192 ( V_229 ) ;
}
static void F_193 ( struct V_166 * V_217 )
{
struct V_251 * V_252 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_253 , V_254 , V_255 ;
if ( F_194 ( V_217 -> V_256 ) != V_257 )
return;
V_252 = F_49 ( sizeof *V_252 , V_53 ) ;
if ( ! V_252 )
return;
F_85 ( V_252 ) ;
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
F_41 ( & V_4 -> V_45 , V_252 ) ;
}
}
F_197 ( V_217 , & V_261 , V_252 ) ;
}
static void F_198 ( struct V_166 * V_217 )
{
struct V_3 * V_4 , * V_262 ;
struct V_251 * V_252 ;
if ( F_194 ( V_217 -> V_256 ) != V_257 )
return;
V_252 = F_199 ( V_217 , & V_261 ) ;
if ( ! V_252 )
return;
F_57 (priv, tmp, dev_list, list) {
F_189 ( & V_4 -> V_244 ) ;
F_34 () ;
F_12 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_12 ) ;
F_32 () ;
F_5 ( V_144 , & V_4 -> V_6 ) ;
F_142 ( & V_4 -> V_153 ) ;
F_190 ( V_125 ) ;
F_188 ( V_4 -> V_2 ) ;
F_191 ( V_4 -> V_2 ) ;
}
F_47 ( V_252 ) ;
}
static int T_7 F_200 ( void )
{
int V_35 ;
V_169 = F_136 ( V_169 ) ;
V_169 = F_28 ( V_169 , V_263 ) ;
V_169 = F_201 ( V_169 , V_264 ) ;
V_174 = F_136 ( V_174 ) ;
V_174 = F_28 ( V_174 , V_263 ) ;
V_174 = F_202 ( V_174 , 2 * V_265 , V_264 ) ;
#ifdef F_203
V_266 = F_28 ( V_266 , V_267 ) ;
#endif
F_204 ( V_268 > V_269 ) ;
V_35 = F_205 () ;
if ( V_35 )
return V_35 ;
V_125 = F_206 ( L_41 ) ;
if ( ! V_125 ) {
V_35 = - V_159 ;
goto V_270;
}
F_207 ( & V_89 ) ;
V_35 = F_208 ( & V_261 ) ;
if ( V_35 )
goto V_271;
V_35 = F_209 () ;
if ( V_35 )
goto V_272;
return 0 ;
V_272:
F_210 ( & V_261 ) ;
V_271:
F_211 ( & V_89 ) ;
F_212 ( V_125 ) ;
V_270:
F_213 () ;
return V_35 ;
}
static void T_8 F_214 ( void )
{
F_215 () ;
F_210 ( & V_261 ) ;
F_211 ( & V_89 ) ;
F_213 () ;
F_212 ( V_125 ) ;
}
