int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_1 ) ;
F_4 ( V_2 ) ;
F_5 ( V_5 , & V_4 -> V_6 ) ;
if ( F_6 ( V_2 ) ) {
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
F_14 ( V_2 ) ;
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
F_18 ( V_2 ) ;
F_14 ( V_2 ) ;
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
V_15 &= ~ ( V_17 | V_18 ) ;
return V_15 ;
}
static int F_22 ( struct V_1 * V_2 , int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_23 ( V_2 ) ) {
if ( V_19 > F_24 ( V_2 ) )
return - V_14 ;
if ( V_19 > V_4 -> V_20 )
F_25 ( V_4 , L_3 ,
V_4 -> V_20 ) ;
V_2 -> V_21 = V_19 ;
return 0 ;
}
if ( V_19 > F_26 ( V_4 -> V_22 ) )
return - V_14 ;
V_4 -> V_23 = V_19 ;
V_2 -> V_21 = F_27 ( V_4 -> V_20 , V_4 -> V_23 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , const char * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_29 ( V_2 -> V_25 ) && ! strcmp ( V_24 , L_4 ) ) {
F_5 ( V_16 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_5
L_6 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 , F_24 ( V_2 ) ) ;
F_32 () ;
V_4 -> V_26 . V_27 &= ~ V_28 ;
F_33 ( V_2 ) ;
F_34 () ;
return 0 ;
}
if ( ! strcmp ( V_24 , L_7 ) ) {
F_15 ( V_16 , & V_4 -> V_6 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 , F_27 ( V_4 -> V_20 , V_2 -> V_21 ) ) ;
F_32 () ;
F_33 ( V_2 ) ;
F_34 () ;
return 0 ;
}
return - V_14 ;
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
void F_33 ( struct V_1 * V_2 )
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
F_79 ( V_68 ) ;
continue;
}
}
while ( ( V_48 = F_42 ( & V_68 -> V_49 ) ) )
F_72 ( & V_71 , V_48 ) ;
}
V_34 -> V_57 = 1 ;
}
V_34 -> V_59 = NULL ;
F_80 ( & V_34 -> V_61 ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
if ( F_71 ( V_50 ) )
F_44 ( V_2 , V_34 -> V_36 . V_37 . V_38 ) ;
if ( V_66 )
F_45 ( V_66 ) ;
while ( ( V_48 = F_42 ( & V_71 ) ) ) {
V_48 -> V_2 = V_2 ;
if ( F_81 ( V_48 ) )
F_25 ( V_4 , L_13
L_14 ) ;
}
}
static struct V_29 * F_82 ( struct V_1 * V_2 , void * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 ;
if ( ! V_4 -> V_80 )
return NULL ;
V_34 = F_83 ( sizeof *V_34 , V_81 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_2 = V_2 ;
F_68 ( & V_34 -> V_49 ) ;
F_84 ( & V_34 -> V_82 ) ;
memcpy ( V_34 -> V_36 . V_37 . V_38 , V_30 , sizeof ( union V_39 ) ) ;
V_34 -> V_36 . V_83 = V_4 -> V_84 ;
V_34 -> V_36 . V_85 = F_85 ( V_4 -> V_85 ) ;
V_34 -> V_36 . V_86 = 1 ;
V_34 -> V_36 . V_87 = V_4 -> V_80 -> V_88 . V_87 ;
return V_34 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_29 * V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_15 ,
V_34 -> V_36 . V_37 . V_38 ) ;
F_87 ( & V_34 -> V_61 ) ;
V_34 -> V_60 =
F_88 ( & V_89 , V_4 -> V_74 , V_4 -> V_75 ,
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
F_80 ( & V_34 -> V_61 ) ;
return V_34 -> V_60 ;
}
return 0 ;
}
static void F_89 ( struct V_47 * V_48 , T_2 * V_79 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 ;
struct V_67 * V_68 ;
unsigned long V_6 ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_68 = F_90 ( V_79 , V_2 ) ;
if ( ! V_68 ) {
F_64 ( & V_4 -> V_54 , V_6 ) ;
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
return;
}
V_34 = F_35 ( V_2 , V_79 + 4 ) ;
if ( ! V_34 ) {
V_34 = F_82 ( V_2 , V_79 + 4 ) ;
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
F_79 ( V_68 ) ;
goto V_98;
}
if ( F_92 ( & V_68 -> V_49 ) < V_99 )
F_72 ( & V_68 -> V_49 , V_48 ) ;
else {
F_25 ( V_4 , L_17 ,
F_92 ( & V_68 -> V_49 ) ) ;
goto V_98;
}
} else {
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_93 ( V_2 , V_48 , V_34 -> V_50 , F_94 ( V_79 ) ) ;
F_95 ( V_68 ) ;
return;
}
} else {
V_68 -> V_50 = NULL ;
if ( ! V_34 -> V_59 && F_86 ( V_2 , V_34 ) )
goto V_97;
if ( F_92 ( & V_68 -> V_49 ) < V_99 )
F_72 ( & V_68 -> V_49 , V_48 ) ;
else
goto V_98;
}
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_95 ( V_68 ) ;
return;
V_97:
F_79 ( V_68 ) ;
V_98:
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_95 ( V_68 ) ;
}
static void F_96 ( struct V_47 * V_48 , struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_29 * V_34 ;
unsigned long V_6 ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_34 = F_35 ( V_2 , V_101 -> V_102 + 4 ) ;
if ( ! V_34 || ! V_34 -> V_57 ) {
int V_103 = 0 ;
if ( ! V_34 ) {
V_34 = F_82 ( V_2 , V_101 -> V_102 + 4 ) ;
V_103 = 1 ;
}
if ( V_34 ) {
if ( F_92 ( & V_34 -> V_49 ) < V_99 ) {
F_72 ( & V_34 -> V_49 , V_48 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
}
if ( ! V_34 -> V_59 && F_86 ( V_2 , V_34 ) ) {
F_64 ( & V_4 -> V_54 , V_6 ) ;
if ( V_103 )
F_41 ( V_2 , V_34 ) ;
return;
} else
F_37 ( V_2 , V_34 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
}
F_64 ( & V_4 -> V_54 , V_6 ) ;
return;
}
if ( V_34 -> V_50 ) {
F_3 ( V_4 , L_18 ,
F_57 ( V_34 -> V_36 . V_56 ) ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
F_93 ( V_2 , V_48 , V_34 -> V_50 , F_94 ( V_101 -> V_102 ) ) ;
return;
} else if ( ( V_34 -> V_59 || ! F_86 ( V_2 , V_34 ) ) &&
F_92 ( & V_34 -> V_49 ) < V_99 ) {
F_72 ( & V_34 -> V_49 , V_48 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
}
F_64 ( & V_4 -> V_54 , V_6 ) ;
}
static int F_97 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_67 * V_68 ;
struct V_100 * V_101 = F_98 ( V_48 ) ;
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
F_91 ( V_48 ) ;
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
F_89 ( V_48 , V_101 -> V_102 , V_2 ) ;
return V_113 ;
}
break;
case F_100 ( V_110 ) :
case F_100 ( V_111 ) :
F_96 ( V_48 , V_2 , V_101 ) ;
return V_113 ;
default:
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
return V_113 ;
}
V_114:
if ( F_76 ( V_68 ) ) {
if ( F_104 ( V_68 ) ) {
F_105 ( V_2 , V_48 , F_76 ( V_68 ) ) ;
goto V_115;
}
} else if ( V_68 -> V_50 ) {
F_93 ( V_2 , V_48 , V_68 -> V_50 , F_94 ( V_101 -> V_102 ) ) ;
goto V_115;
}
if ( F_92 ( & V_68 -> V_49 ) < V_99 ) {
F_60 ( & V_4 -> V_54 , V_6 ) ;
F_72 ( & V_68 -> V_49 , V_48 ) ;
F_64 ( & V_4 -> V_54 , V_6 ) ;
} else {
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
}
V_115:
F_95 ( V_68 ) ;
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
struct V_104 * V_105 ;
struct V_100 * V_101 = F_98 ( V_48 ) ;
V_105 = (struct V_104 * ) F_110 ( V_48 , sizeof *V_105 ) ;
V_105 -> V_107 = F_100 ( type ) ;
V_105 -> V_122 = 0 ;
memcpy ( V_101 -> V_102 , V_79 , V_123 ) ;
return sizeof *V_105 ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_124 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_21 ) ;
return;
}
F_112 ( V_4 -> V_125 , & V_4 -> V_126 ) ;
}
static int F_113 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) )
return V_2 -> V_127 ;
return V_4 -> V_128 -> V_127 ;
}
static T_3 F_114 ( struct V_129 * V_130 , T_2 * V_79 )
{
T_3 * V_131 = ( T_3 * ) V_79 ;
T_3 V_132 ;
V_132 = F_115 ( V_131 [ 3 ] , V_131 [ 4 ] , V_133 & V_131 [ 0 ] , 0 ) ;
return V_132 & V_130 -> V_134 ;
}
struct V_67 * F_101 ( struct V_1 * V_2 , T_2 * V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_135 * V_136 = & V_4 -> V_136 ;
struct V_129 * V_130 ;
struct V_67 * V_68 = NULL ;
T_3 V_137 ;
F_116 () ;
V_130 = F_117 ( V_136 -> V_130 ) ;
if ( ! V_130 )
goto V_138;
V_137 = F_114 ( V_130 , V_79 ) ;
for ( V_68 = F_117 ( V_130 -> V_139 [ V_137 ] ) ;
V_68 != NULL ;
V_68 = F_117 ( V_68 -> V_140 ) ) {
if ( memcmp ( V_79 , V_68 -> V_79 , V_123 ) == 0 ) {
if ( ! F_118 ( & V_68 -> V_141 ) ) {
V_68 = NULL ;
goto V_138;
}
V_68 -> V_142 = V_116 ;
goto V_138;
}
}
V_138:
F_119 () ;
return V_68 ;
}
static void F_120 ( struct V_3 * V_4 )
{
struct V_135 * V_136 = & V_4 -> V_136 ;
struct V_129 * V_130 ;
unsigned long V_143 ;
unsigned long V_144 ;
unsigned long V_6 ;
int V_145 ;
if ( F_7 ( V_146 , & V_4 -> V_6 ) )
return;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_130 = F_121 ( V_136 -> V_130 ,
F_122 ( & V_4 -> V_54 ) ) ;
if ( ! V_130 )
goto V_138;
V_144 = 2 * V_147 . V_148 ;
V_143 = V_116 - V_144 ;
if ( F_7 ( V_146 , & V_4 -> V_6 ) )
goto V_138;
for ( V_145 = 0 ; V_145 < V_130 -> V_149 ; V_145 ++ ) {
struct V_67 * V_68 ;
struct V_67 T_4 * * V_150 = & V_130 -> V_139 [ V_145 ] ;
while ( ( V_68 = F_121 ( * V_150 ,
F_122 ( & V_4 -> V_54 ) ) ) != NULL ) {
if ( F_123 ( V_143 , V_68 -> V_142 ) ) {
F_124 ( * V_150 ,
F_121 ( V_68 -> V_140 ,
F_122 ( & V_4 -> V_54 ) ) ) ;
F_125 ( & V_68 -> V_45 ) ;
F_126 ( & V_68 -> V_151 , V_152 ) ;
} else {
V_150 = & V_68 -> V_140 ;
}
}
}
V_138:
F_64 ( & V_4 -> V_54 , V_6 ) ;
}
static void F_127 ( struct V_153 * V_154 )
{
struct V_3 * V_4 =
F_128 ( V_154 , struct V_3 , V_155 . V_154 ) ;
F_120 ( V_4 ) ;
if ( ! F_7 ( V_146 , & V_4 -> V_6 ) )
F_129 ( V_4 -> V_125 , & V_4 -> V_155 ,
V_147 . V_148 ) ;
}
static struct V_67 * F_130 ( T_2 * V_79 ,
struct V_1 * V_2 )
{
struct V_67 * V_68 ;
V_68 = F_83 ( sizeof *V_68 , V_81 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_2 = V_2 ;
memcpy ( & V_68 -> V_79 , V_79 , sizeof( V_68 -> V_79 ) ) ;
F_68 ( & V_68 -> V_49 ) ;
F_84 ( & V_68 -> V_45 ) ;
F_77 ( V_68 , NULL ) ;
F_131 ( & V_68 -> V_141 , 1 ) ;
return V_68 ;
}
struct V_67 * F_90 ( T_2 * V_79 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_135 * V_136 = & V_4 -> V_136 ;
struct V_129 * V_130 ;
struct V_67 * V_68 ;
T_3 V_137 ;
V_130 = F_121 ( V_136 -> V_130 ,
F_122 ( & V_4 -> V_54 ) ) ;
if ( ! V_130 ) {
V_68 = NULL ;
goto V_138;
}
V_137 = F_114 ( V_130 , V_79 ) ;
for ( V_68 = F_121 ( V_130 -> V_139 [ V_137 ] ,
F_122 ( & V_4 -> V_54 ) ) ;
V_68 != NULL ;
V_68 = F_121 ( V_68 -> V_140 ,
F_122 ( & V_4 -> V_54 ) ) ) {
if ( memcmp ( V_79 , V_68 -> V_79 , V_123 ) == 0 ) {
if ( ! F_118 ( & V_68 -> V_141 ) ) {
V_68 = NULL ;
break;
}
V_68 -> V_142 = V_116 ;
goto V_138;
}
}
V_68 = F_130 ( V_79 , V_2 ) ;
if ( ! V_68 )
goto V_138;
F_132 ( & V_68 -> V_141 ) ;
V_68 -> V_142 = V_116 ;
F_124 ( V_68 -> V_140 ,
F_121 ( V_130 -> V_139 [ V_137 ] ,
F_122 ( & V_4 -> V_54 ) ) ) ;
F_124 ( V_130 -> V_139 [ V_137 ] , V_68 ) ;
F_132 ( & V_136 -> V_156 ) ;
V_138:
return V_68 ;
}
void F_133 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_47 * V_48 ;
if ( V_68 -> V_50 )
F_45 ( V_68 -> V_50 ) ;
while ( ( V_48 = F_42 ( & V_68 -> V_49 ) ) ) {
++ V_2 -> V_95 . V_96 ;
F_91 ( V_48 ) ;
}
if ( F_76 ( V_68 ) )
F_134 ( F_76 ( V_68 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_22 ,
F_94 ( V_68 -> V_79 ) ,
V_68 -> V_79 + 4 ) ;
F_46 ( V_68 ) ;
if ( F_135 ( & V_4 -> V_136 . V_156 ) ) {
if ( F_7 ( V_157 , & V_4 -> V_6 ) )
F_80 ( & V_4 -> V_136 . V_158 ) ;
}
}
static void V_152 ( struct V_159 * V_160 )
{
struct V_67 * V_68 = F_128 ( V_160 , struct V_67 , V_151 ) ;
F_95 ( V_68 ) ;
}
void F_79 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_135 * V_136 = & V_4 -> V_136 ;
struct V_129 * V_130 ;
struct V_67 T_4 * * V_150 ;
struct V_67 * V_32 ;
T_3 V_137 ;
V_130 = F_121 ( V_136 -> V_130 ,
F_122 ( & V_4 -> V_54 ) ) ;
if ( ! V_130 )
return;
V_137 = F_114 ( V_130 , V_68 -> V_79 ) ;
V_150 = & V_130 -> V_139 [ V_137 ] ;
for ( V_32 = F_121 ( * V_150 ,
F_122 ( & V_4 -> V_54 ) ) ;
V_32 != NULL ;
V_32 = F_121 ( * V_150 ,
F_122 ( & V_4 -> V_54 ) ) ) {
if ( V_32 == V_68 ) {
F_124 ( * V_150 ,
F_121 ( V_68 -> V_140 ,
F_122 ( & V_4 -> V_54 ) ) ) ;
F_125 ( & V_68 -> V_45 ) ;
F_126 ( & V_68 -> V_151 , V_152 ) ;
return;
} else {
V_150 = & V_32 -> V_140 ;
}
}
}
static int F_136 ( struct V_3 * V_4 )
{
struct V_135 * V_136 = & V_4 -> V_136 ;
struct V_129 * V_130 ;
struct V_67 T_4 * * V_139 ;
T_3 V_149 ;
F_15 ( V_157 , & V_4 -> V_6 ) ;
V_136 -> V_130 = NULL ;
V_130 = F_83 ( sizeof( * V_130 ) , V_53 ) ;
if ( ! V_130 )
return - V_161 ;
F_5 ( V_146 , & V_4 -> V_6 ) ;
V_149 = F_137 ( V_147 . V_162 ) ;
V_139 = F_83 ( V_149 * sizeof( * V_139 ) , V_53 ) ;
if ( ! V_139 ) {
F_46 ( V_130 ) ;
return - V_161 ;
}
V_130 -> V_149 = V_149 ;
V_130 -> V_134 = ( V_149 - 1 ) ;
V_130 -> V_139 = V_139 ;
F_138 ( V_136 -> V_130 , V_130 ) ;
V_130 -> V_136 = V_136 ;
F_131 ( & V_136 -> V_156 , 0 ) ;
F_15 ( V_146 , & V_4 -> V_6 ) ;
F_129 ( V_4 -> V_125 , & V_4 -> V_155 ,
V_147 . V_148 ) ;
return 0 ;
}
static void F_139 ( struct V_159 * V_163 )
{
struct V_129 * V_130 = F_128 ( V_163 ,
struct V_129 ,
V_151 ) ;
struct V_67 T_4 * * V_139 = V_130 -> V_139 ;
struct V_135 * V_136 = V_130 -> V_136 ;
F_46 ( V_139 ) ;
F_46 ( V_130 ) ;
F_80 ( & V_136 -> V_164 ) ;
}
void F_44 ( struct V_1 * V_2 , T_2 * V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_135 * V_136 = & V_4 -> V_136 ;
struct V_129 * V_130 ;
unsigned long V_6 ;
int V_145 ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_130 = F_121 ( V_136 -> V_130 ,
F_122 ( & V_4 -> V_54 ) ) ;
if ( ! V_130 )
goto V_138;
for ( V_145 = 0 ; V_145 < V_130 -> V_149 ; V_145 ++ ) {
struct V_67 * V_68 ;
struct V_67 T_4 * * V_150 = & V_130 -> V_139 [ V_145 ] ;
while ( ( V_68 = F_121 ( * V_150 ,
F_122 ( & V_4 -> V_54 ) ) ) != NULL ) {
if ( ! memcmp ( V_30 , V_68 -> V_79 + 4 , sizeof ( union V_39 ) ) ) {
F_124 ( * V_150 ,
F_121 ( V_68 -> V_140 ,
F_122 ( & V_4 -> V_54 ) ) ) ;
F_125 ( & V_68 -> V_45 ) ;
F_126 ( & V_68 -> V_151 , V_152 ) ;
} else {
V_150 = & V_68 -> V_140 ;
}
}
}
V_138:
F_64 ( & V_4 -> V_54 , V_6 ) ;
}
static void F_140 ( struct V_3 * V_4 )
{
struct V_135 * V_136 = & V_4 -> V_136 ;
struct V_129 * V_130 ;
unsigned long V_6 ;
int V_145 , V_165 = 0 ;
F_87 ( & V_4 -> V_136 . V_158 ) ;
F_60 ( & V_4 -> V_54 , V_6 ) ;
V_130 = F_121 ( V_136 -> V_130 ,
F_122 ( & V_4 -> V_54 ) ) ;
if ( ! V_130 )
goto V_138;
V_165 = F_141 ( & V_4 -> V_136 . V_156 ) ;
if ( ! V_165 )
goto V_166;
for ( V_145 = 0 ; V_145 < V_130 -> V_149 ; V_145 ++ ) {
struct V_67 * V_68 ;
struct V_67 T_4 * * V_150 = & V_130 -> V_139 [ V_145 ] ;
while ( ( V_68 = F_121 ( * V_150 ,
F_122 ( & V_4 -> V_54 ) ) ) != NULL ) {
F_124 ( * V_150 ,
F_121 ( V_68 -> V_140 ,
F_122 ( & V_4 -> V_54 ) ) ) ;
F_125 ( & V_68 -> V_45 ) ;
F_126 ( & V_68 -> V_151 , V_152 ) ;
}
}
V_166:
F_124 ( V_136 -> V_130 , NULL ) ;
F_126 ( & V_130 -> V_151 , F_139 ) ;
V_138:
F_64 ( & V_4 -> V_54 , V_6 ) ;
if ( V_165 )
F_66 ( & V_4 -> V_136 . V_158 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_167 ;
F_3 ( V_4 , L_23 ) ;
F_87 ( & V_4 -> V_136 . V_164 ) ;
F_5 ( V_157 , & V_4 -> V_6 ) ;
V_167 = F_143 ( V_146 , & V_4 -> V_6 ) ;
if ( ! V_167 )
F_144 ( & V_4 -> V_155 ) ;
F_140 ( V_4 ) ;
F_66 ( & V_4 -> V_136 . V_164 ) ;
}
int F_145 ( struct V_1 * V_2 , struct V_168 * V_74 , int V_75 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_169 = F_83 ( V_170 * sizeof * V_4 -> V_169 ,
V_53 ) ;
if ( ! V_4 -> V_169 ) {
F_146 ( V_171 L_24 ,
V_74 -> V_172 , V_170 ) ;
goto V_173;
}
V_4 -> V_174 = F_147 ( V_175 * sizeof * V_4 -> V_174 ) ;
if ( ! V_4 -> V_174 ) {
F_146 ( V_171 L_25 ,
V_74 -> V_172 , V_175 ) ;
goto V_176;
}
if ( F_148 ( V_2 , V_74 , V_75 ) )
goto V_177;
if ( F_136 ( V_4 ) < 0 )
goto V_178;
return 0 ;
V_178:
F_149 ( V_2 ) ;
V_177:
F_150 ( V_4 -> V_174 ) ;
V_176:
F_46 ( V_4 -> V_169 ) ;
V_173:
return - V_161 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_11 , * V_179 ;
F_58 ( V_163 ) ;
F_151 () ;
F_152 ( V_2 ) ;
F_56 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_146 , & V_11 -> V_6 ) ;
F_144 ( & V_11 -> V_155 ) ;
F_153 ( V_11 -> V_2 , & V_163 ) ;
}
F_154 ( & V_163 ) ;
F_142 ( V_2 ) ;
F_149 ( V_2 ) ;
F_46 ( V_4 -> V_169 ) ;
F_150 ( V_4 -> V_174 ) ;
V_4 -> V_169 = NULL ;
V_4 -> V_174 = NULL ;
}
void F_155 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_180 = & V_181 ;
V_2 -> V_182 = & V_183 ;
F_156 ( V_2 ) ;
F_157 ( V_2 , & V_4 -> V_184 , V_185 , V_186 ) ;
V_2 -> V_187 = V_188 ;
V_2 -> V_6 |= V_189 | V_190 ;
V_2 -> V_191 = V_192 ;
V_2 -> V_193 = V_123 ;
V_2 -> type = V_194 ;
V_2 -> V_195 = V_175 * 2 ;
V_2 -> V_15 = ( V_196 |
V_197 ) ;
F_158 ( V_2 ) ;
memcpy ( V_2 -> V_80 , V_198 , V_123 ) ;
V_4 -> V_2 = V_2 ;
F_159 ( & V_4 -> V_54 ) ;
F_160 ( & V_4 -> V_12 ) ;
F_84 ( & V_4 -> V_46 ) ;
F_84 ( & V_4 -> V_199 ) ;
F_84 ( & V_4 -> V_200 ) ;
F_84 ( & V_4 -> V_201 ) ;
F_161 ( & V_4 -> V_202 , V_203 ) ;
F_162 ( & V_4 -> V_204 , V_205 ) ;
F_162 ( & V_4 -> V_206 , V_207 ) ;
F_162 ( & V_4 -> V_208 , V_209 ) ;
F_162 ( & V_4 -> V_210 , V_211 ) ;
F_162 ( & V_4 -> V_126 , V_212 ) ;
F_161 ( & V_4 -> V_213 , V_214 ) ;
F_161 ( & V_4 -> V_155 , F_127 ) ;
}
struct V_3 * F_163 ( const char * V_172 )
{
struct V_1 * V_2 ;
V_2 = F_164 ( ( int ) sizeof( struct V_3 ) , V_172 ,
V_215 , F_155 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_5 F_165 ( struct V_216 * V_2 ,
struct V_217 * V_218 , char * V_24 )
{
struct V_3 * V_4 = F_2 ( F_166 ( V_2 ) ) ;
return sprintf ( V_24 , L_26 , V_4 -> V_85 ) ;
}
static T_5 F_167 ( struct V_216 * V_2 ,
struct V_217 * V_218 , char * V_24 )
{
struct V_3 * V_4 = F_2 ( F_166 ( V_2 ) ) ;
return sprintf ( V_24 , L_27 , F_7 ( V_219 , & V_4 -> V_6 ) ) ;
}
void F_168 ( struct V_1 * V_220 , int V_221 )
{
struct V_3 * V_4 = F_2 ( V_220 ) ;
if ( V_221 > 0 ) {
F_5 ( V_219 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_28
L_29 ) ;
} else
F_15 ( V_219 , & V_4 -> V_6 ) ;
}
static T_5 F_169 ( struct V_216 * V_2 ,
struct V_217 * V_218 ,
const char * V_24 , T_6 V_222 )
{
unsigned long V_221 = F_170 ( V_24 , NULL , 0 ) ;
F_168 ( F_166 ( V_2 ) , V_221 ) ;
return V_222 ;
}
int F_171 ( struct V_1 * V_2 )
{
return F_172 ( & V_2 -> V_2 , & V_223 ) ;
}
static T_5 F_173 ( struct V_216 * V_2 ,
struct V_217 * V_218 ,
const char * V_24 , T_6 V_222 )
{
int V_85 ;
int V_35 ;
if ( sscanf ( V_24 , L_30 , & V_85 ) != 1 )
return - V_14 ;
if ( V_85 <= 0 || V_85 > 0xffff || V_85 == 0x8000 )
return - V_14 ;
V_85 |= 0x8000 ;
V_35 = F_174 ( F_166 ( V_2 ) , V_85 ) ;
return V_35 ? V_35 : V_222 ;
}
static T_5 F_175 ( struct V_216 * V_2 ,
struct V_217 * V_218 ,
const char * V_24 , T_6 V_222 )
{
int V_85 ;
int V_35 ;
if ( sscanf ( V_24 , L_30 , & V_85 ) != 1 )
return - V_14 ;
if ( V_85 < 0 || V_85 > 0xffff )
return - V_14 ;
V_35 = F_176 ( F_166 ( V_2 ) , V_85 ) ;
return V_35 ? V_35 : V_222 ;
}
int F_177 ( struct V_1 * V_2 )
{
return F_172 ( & V_2 -> V_2 , & V_224 ) ;
}
int F_178 ( struct V_3 * V_4 , struct V_168 * V_225 )
{
struct V_226 * V_227 ;
int V_228 = - V_161 ;
V_227 = F_48 ( sizeof *V_227 , V_53 ) ;
if ( ! V_227 ) {
F_146 ( V_171 L_31 ,
V_225 -> V_172 , sizeof *V_227 ) ;
return V_228 ;
}
V_228 = F_179 ( V_225 , V_227 ) ;
if ( V_228 ) {
F_146 ( V_171 L_32 ,
V_225 -> V_172 , V_228 ) ;
F_46 ( V_227 ) ;
return V_228 ;
}
V_4 -> V_229 = V_227 -> V_230 ;
F_46 ( V_227 ) ;
if ( V_4 -> V_229 & V_231 ) {
V_4 -> V_2 -> V_232 = V_233 |
V_17 | V_234 ;
if ( V_4 -> V_229 & V_235 )
V_4 -> V_2 -> V_232 |= V_18 ;
V_4 -> V_2 -> V_15 |= V_4 -> V_2 -> V_232 ;
}
return 0 ;
}
static struct V_1 * F_180 ( const char * V_236 ,
struct V_168 * V_225 , T_2 V_75 )
{
struct V_3 * V_4 ;
struct V_237 V_218 ;
int V_228 = - V_161 ;
V_4 = F_163 ( V_236 ) ;
if ( ! V_4 )
goto V_238;
F_181 ( V_4 -> V_2 , V_225 -> V_239 ) ;
V_4 -> V_2 -> V_240 = V_75 - 1 ;
V_228 = F_182 ( V_225 , V_75 , & V_218 ) ;
if ( ! V_228 )
V_4 -> V_22 = F_183 ( V_218 . V_241 ) ;
else {
F_146 ( V_171 L_33 ,
V_225 -> V_172 , V_75 ) ;
goto V_242;
}
V_4 -> V_2 -> V_21 = F_26 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_4 -> V_2 -> V_243 = sizeof( struct V_67 ) ;
V_228 = F_184 ( V_225 , V_75 , 0 , & V_4 -> V_85 ) ;
if ( V_228 ) {
F_146 ( V_171 L_34 ,
V_225 -> V_172 , V_75 , V_228 ) ;
goto V_242;
}
V_228 = F_178 ( V_4 , V_225 ) ;
if ( V_228 )
goto V_242;
V_4 -> V_85 |= 0x8000 ;
V_4 -> V_2 -> V_80 [ 8 ] = V_4 -> V_85 >> 8 ;
V_4 -> V_2 -> V_80 [ 9 ] = V_4 -> V_85 & 0xff ;
V_228 = F_185 ( V_225 , V_75 , 0 , & V_4 -> V_84 ) ;
if ( V_228 ) {
F_146 ( V_171 L_35 ,
V_225 -> V_172 , V_75 , V_228 ) ;
goto V_242;
} else
memcpy ( V_4 -> V_2 -> V_25 + 4 , V_4 -> V_84 . V_38 , sizeof ( union V_39 ) ) ;
V_228 = F_145 ( V_4 -> V_2 , V_225 , V_75 ) ;
if ( V_228 < 0 ) {
F_146 ( V_171 L_36 ,
V_225 -> V_172 , V_75 , V_228 ) ;
goto V_242;
}
F_186 ( & V_4 -> V_244 ,
V_4 -> V_74 , V_245 ) ;
V_228 = F_187 ( & V_4 -> V_244 ) ;
if ( V_228 < 0 ) {
F_146 ( V_171 L_37
L_38 ,
V_225 -> V_172 , V_75 , V_228 ) ;
goto V_246;
}
V_228 = F_188 ( V_4 -> V_2 ) ;
if ( V_228 ) {
F_146 ( V_171 L_39 ,
V_225 -> V_172 , V_75 , V_228 ) ;
goto V_247;
}
F_189 ( V_4 -> V_2 ) ;
if ( F_190 ( V_4 -> V_2 ) )
goto V_248;
if ( F_177 ( V_4 -> V_2 ) )
goto V_248;
if ( F_171 ( V_4 -> V_2 ) )
goto V_248;
if ( F_172 ( & V_4 -> V_2 -> V_2 , & V_249 ) )
goto V_248;
if ( F_172 ( & V_4 -> V_2 -> V_2 , & V_250 ) )
goto V_248;
return V_4 -> V_2 ;
V_248:
F_152 ( V_4 -> V_2 ) ;
F_191 ( V_4 -> V_2 ) ;
V_247:
F_192 ( & V_4 -> V_244 ) ;
F_193 ( V_251 ) ;
F_5 ( V_146 , & V_4 -> V_6 ) ;
F_144 ( & V_4 -> V_155 ) ;
F_193 ( V_4 -> V_125 ) ;
V_246:
F_20 ( V_4 -> V_2 ) ;
V_242:
F_194 ( V_4 -> V_2 ) ;
V_238:
return F_195 ( V_228 ) ;
}
static void F_196 ( struct V_168 * V_216 )
{
struct V_252 * V_253 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_254 ;
int V_222 = 0 ;
V_253 = F_48 ( sizeof *V_253 , V_53 ) ;
if ( ! V_253 )
return;
F_84 ( V_253 ) ;
for ( V_254 = F_197 ( V_216 ) ; V_254 <= F_198 ( V_216 ) ; ++ V_254 ) {
if ( ! F_199 ( V_216 , V_254 ) )
continue;
V_2 = F_180 ( L_40 , V_216 , V_254 ) ;
if ( ! F_200 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_40 ( & V_4 -> V_45 , V_253 ) ;
V_222 ++ ;
}
}
if ( ! V_222 ) {
F_46 ( V_253 ) ;
return;
}
F_201 ( V_216 , & V_255 , V_253 ) ;
}
static void F_202 ( struct V_168 * V_216 )
{
struct V_3 * V_4 , * V_256 ;
struct V_252 * V_253 ;
V_253 = F_203 ( V_216 , & V_255 ) ;
if ( ! V_253 )
return;
F_56 (priv, tmp, dev_list, list) {
F_192 ( & V_4 -> V_244 ) ;
F_193 ( V_251 ) ;
F_34 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_13 ) ;
F_32 () ;
F_5 ( V_146 , & V_4 -> V_6 ) ;
F_144 ( & V_4 -> V_155 ) ;
F_193 ( V_4 -> V_125 ) ;
F_191 ( V_4 -> V_2 ) ;
F_194 ( V_4 -> V_2 ) ;
}
F_46 ( V_253 ) ;
}
static int T_7 F_204 ( void )
{
int V_35 ;
V_170 = F_137 ( V_170 ) ;
V_170 = F_27 ( V_170 , V_257 ) ;
V_170 = F_205 ( V_170 , V_258 ) ;
V_175 = F_137 ( V_175 ) ;
V_175 = F_27 ( V_175 , V_257 ) ;
V_175 = F_206 ( V_175 , 2 * V_259 , V_258 ) ;
#ifdef F_207
V_260 = F_27 ( V_260 , V_261 ) ;
#endif
F_208 ( V_262 > V_263 ) ;
V_35 = F_209 () ;
if ( V_35 )
return V_35 ;
V_251 = F_210 ( L_41 ) ;
if ( ! V_251 ) {
V_35 = - V_161 ;
goto V_264;
}
F_211 ( & V_89 ) ;
V_35 = F_212 ( & V_255 ) ;
if ( V_35 )
goto V_265;
V_35 = F_213 () ;
if ( V_35 )
goto V_266;
return 0 ;
V_266:
F_214 ( & V_255 ) ;
V_265:
F_215 ( & V_89 ) ;
F_216 ( V_251 ) ;
V_264:
F_217 () ;
return V_35 ;
}
static void T_8 F_218 ( void )
{
F_219 () ;
F_214 ( & V_255 ) ;
F_215 ( & V_89 ) ;
F_217 () ;
F_216 ( V_251 ) ;
}
