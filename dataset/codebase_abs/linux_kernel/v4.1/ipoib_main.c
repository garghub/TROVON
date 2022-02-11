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
if ( F_92 ( & V_69 -> V_50 ) < V_100 )
F_72 ( & V_69 -> V_50 , V_49 ) ;
else
goto V_99;
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
if ( F_92 ( & V_35 -> V_50 ) < V_100 ) {
F_72 ( & V_35 -> V_50 , V_49 ) ;
} else {
++ V_2 -> V_96 . V_97 ;
F_91 ( V_49 ) ;
}
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
F_112 ( V_4 -> V_126 , & V_4 -> V_127 ) ;
}
static int F_113 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_7 ( V_10 , & V_4 -> V_6 ) )
return V_2 -> V_128 ;
return V_4 -> V_129 -> V_128 ;
}
static T_3 F_114 ( struct V_130 * V_131 , T_2 * V_80 )
{
T_3 * V_132 = ( T_3 * ) V_80 ;
T_3 V_133 ;
V_133 = F_115 ( V_132 [ 3 ] , V_132 [ 4 ] , V_134 & V_132 [ 0 ] , 0 ) ;
return V_133 & V_131 -> V_135 ;
}
struct V_68 * F_101 ( struct V_1 * V_2 , T_2 * V_80 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_136 * V_137 = & V_4 -> V_137 ;
struct V_130 * V_131 ;
struct V_68 * V_69 = NULL ;
T_3 V_138 ;
F_116 () ;
V_131 = F_117 ( V_137 -> V_131 ) ;
if ( ! V_131 )
goto V_139;
V_138 = F_114 ( V_131 , V_80 ) ;
for ( V_69 = F_117 ( V_131 -> V_140 [ V_138 ] ) ;
V_69 != NULL ;
V_69 = F_117 ( V_69 -> V_141 ) ) {
if ( memcmp ( V_80 , V_69 -> V_80 , V_124 ) == 0 ) {
if ( ! F_118 ( & V_69 -> V_142 ) ) {
V_69 = NULL ;
goto V_139;
}
V_69 -> V_143 = V_117 ;
goto V_139;
}
}
V_139:
F_119 () ;
return V_69 ;
}
static void F_120 ( struct V_3 * V_4 )
{
struct V_136 * V_137 = & V_4 -> V_137 ;
struct V_130 * V_131 ;
unsigned long V_144 ;
unsigned long V_145 ;
unsigned long V_6 ;
int V_146 ;
if ( F_7 ( V_147 , & V_4 -> V_6 ) )
return;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_131 = F_121 ( V_137 -> V_131 ,
F_122 ( & V_4 -> V_55 ) ) ;
if ( ! V_131 )
goto V_139;
V_145 = 2 * V_148 . V_149 ;
V_144 = V_117 - V_145 ;
if ( F_7 ( V_147 , & V_4 -> V_6 ) )
goto V_139;
for ( V_146 = 0 ; V_146 < V_131 -> V_150 ; V_146 ++ ) {
struct V_68 * V_69 ;
struct V_68 T_4 * * V_151 = & V_131 -> V_140 [ V_146 ] ;
while ( ( V_69 = F_121 ( * V_151 ,
F_122 ( & V_4 -> V_55 ) ) ) != NULL ) {
if ( F_123 ( V_144 , V_69 -> V_143 ) ) {
F_124 ( * V_151 ,
F_121 ( V_69 -> V_141 ,
F_122 ( & V_4 -> V_55 ) ) ) ;
F_125 ( & V_69 -> V_46 ) ;
F_126 ( & V_69 -> V_152 , V_153 ) ;
} else {
V_151 = & V_69 -> V_141 ;
}
}
}
V_139:
F_64 ( & V_4 -> V_55 , V_6 ) ;
}
static void F_127 ( struct V_154 * V_155 )
{
struct V_3 * V_4 =
F_128 ( V_155 , struct V_3 , V_156 . V_155 ) ;
F_120 ( V_4 ) ;
if ( ! F_7 ( V_147 , & V_4 -> V_6 ) )
F_129 ( V_4 -> V_126 , & V_4 -> V_156 ,
V_148 . V_149 ) ;
}
static struct V_68 * F_130 ( T_2 * V_80 ,
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
F_131 ( & V_69 -> V_142 , 1 ) ;
return V_69 ;
}
struct V_68 * F_90 ( T_2 * V_80 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_136 * V_137 = & V_4 -> V_137 ;
struct V_130 * V_131 ;
struct V_68 * V_69 ;
T_3 V_138 ;
V_131 = F_121 ( V_137 -> V_131 ,
F_122 ( & V_4 -> V_55 ) ) ;
if ( ! V_131 ) {
V_69 = NULL ;
goto V_139;
}
V_138 = F_114 ( V_131 , V_80 ) ;
for ( V_69 = F_121 ( V_131 -> V_140 [ V_138 ] ,
F_122 ( & V_4 -> V_55 ) ) ;
V_69 != NULL ;
V_69 = F_121 ( V_69 -> V_141 ,
F_122 ( & V_4 -> V_55 ) ) ) {
if ( memcmp ( V_80 , V_69 -> V_80 , V_124 ) == 0 ) {
if ( ! F_118 ( & V_69 -> V_142 ) ) {
V_69 = NULL ;
break;
}
V_69 -> V_143 = V_117 ;
goto V_139;
}
}
V_69 = F_130 ( V_80 , V_2 ) ;
if ( ! V_69 )
goto V_139;
F_132 ( & V_69 -> V_142 ) ;
V_69 -> V_143 = V_117 ;
F_124 ( V_69 -> V_141 ,
F_121 ( V_131 -> V_140 [ V_138 ] ,
F_122 ( & V_4 -> V_55 ) ) ) ;
F_124 ( V_131 -> V_140 [ V_138 ] , V_69 ) ;
F_132 ( & V_137 -> V_157 ) ;
V_139:
return V_69 ;
}
void F_133 ( struct V_68 * V_69 )
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
F_134 ( F_76 ( V_69 ) ) ;
F_3 ( F_2 ( V_2 ) ,
L_22 ,
F_94 ( V_69 -> V_80 ) ,
V_69 -> V_80 + 4 ) ;
F_46 ( V_69 ) ;
if ( F_135 ( & V_4 -> V_137 . V_157 ) ) {
if ( F_7 ( V_158 , & V_4 -> V_6 ) )
F_80 ( & V_4 -> V_137 . V_159 ) ;
}
}
static void V_153 ( struct V_160 * V_161 )
{
struct V_68 * V_69 = F_128 ( V_161 , struct V_68 , V_152 ) ;
F_95 ( V_69 ) ;
}
void F_79 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_136 * V_137 = & V_4 -> V_137 ;
struct V_130 * V_131 ;
struct V_68 T_4 * * V_151 ;
struct V_68 * V_33 ;
T_3 V_138 ;
V_131 = F_121 ( V_137 -> V_131 ,
F_122 ( & V_4 -> V_55 ) ) ;
if ( ! V_131 )
return;
V_138 = F_114 ( V_131 , V_69 -> V_80 ) ;
V_151 = & V_131 -> V_140 [ V_138 ] ;
for ( V_33 = F_121 ( * V_151 ,
F_122 ( & V_4 -> V_55 ) ) ;
V_33 != NULL ;
V_33 = F_121 ( * V_151 ,
F_122 ( & V_4 -> V_55 ) ) ) {
if ( V_33 == V_69 ) {
F_124 ( * V_151 ,
F_121 ( V_69 -> V_141 ,
F_122 ( & V_4 -> V_55 ) ) ) ;
F_125 ( & V_69 -> V_46 ) ;
F_126 ( & V_69 -> V_152 , V_153 ) ;
return;
} else {
V_151 = & V_33 -> V_141 ;
}
}
}
static int F_136 ( struct V_3 * V_4 )
{
struct V_136 * V_137 = & V_4 -> V_137 ;
struct V_130 * V_131 ;
struct V_68 * * V_140 ;
T_3 V_150 ;
F_15 ( V_158 , & V_4 -> V_6 ) ;
V_137 -> V_131 = NULL ;
V_131 = F_83 ( sizeof( * V_131 ) , V_54 ) ;
if ( ! V_131 )
return - V_162 ;
F_5 ( V_147 , & V_4 -> V_6 ) ;
V_150 = F_137 ( V_148 . V_163 ) ;
V_140 = F_83 ( V_150 * sizeof( * V_140 ) , V_54 ) ;
if ( ! V_140 ) {
F_46 ( V_131 ) ;
return - V_162 ;
}
V_131 -> V_150 = V_150 ;
V_131 -> V_135 = ( V_150 - 1 ) ;
V_131 -> V_140 = V_140 ;
V_137 -> V_131 = V_131 ;
V_131 -> V_137 = V_137 ;
F_131 ( & V_137 -> V_157 , 0 ) ;
F_15 ( V_147 , & V_4 -> V_6 ) ;
F_129 ( V_4 -> V_126 , & V_4 -> V_156 ,
V_148 . V_149 ) ;
return 0 ;
}
static void F_138 ( struct V_160 * V_164 )
{
struct V_130 * V_131 = F_128 ( V_164 ,
struct V_130 ,
V_152 ) ;
struct V_68 T_4 * * V_140 = V_131 -> V_140 ;
struct V_136 * V_137 = V_131 -> V_137 ;
F_46 ( V_140 ) ;
F_46 ( V_131 ) ;
F_80 ( & V_137 -> V_165 ) ;
}
void F_44 ( struct V_1 * V_2 , T_2 * V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_136 * V_137 = & V_4 -> V_137 ;
struct V_130 * V_131 ;
unsigned long V_6 ;
int V_146 ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_131 = F_121 ( V_137 -> V_131 ,
F_122 ( & V_4 -> V_55 ) ) ;
if ( ! V_131 )
goto V_139;
for ( V_146 = 0 ; V_146 < V_131 -> V_150 ; V_146 ++ ) {
struct V_68 * V_69 ;
struct V_68 T_4 * * V_151 = & V_131 -> V_140 [ V_146 ] ;
while ( ( V_69 = F_121 ( * V_151 ,
F_122 ( & V_4 -> V_55 ) ) ) != NULL ) {
if ( ! memcmp ( V_31 , V_69 -> V_80 + 4 , sizeof ( union V_40 ) ) ) {
F_124 ( * V_151 ,
F_121 ( V_69 -> V_141 ,
F_122 ( & V_4 -> V_55 ) ) ) ;
F_125 ( & V_69 -> V_46 ) ;
F_126 ( & V_69 -> V_152 , V_153 ) ;
} else {
V_151 = & V_69 -> V_141 ;
}
}
}
V_139:
F_64 ( & V_4 -> V_55 , V_6 ) ;
}
static void F_139 ( struct V_3 * V_4 )
{
struct V_136 * V_137 = & V_4 -> V_137 ;
struct V_130 * V_131 ;
unsigned long V_6 ;
int V_146 , V_166 = 0 ;
F_87 ( & V_4 -> V_137 . V_159 ) ;
F_60 ( & V_4 -> V_55 , V_6 ) ;
V_131 = F_121 ( V_137 -> V_131 ,
F_122 ( & V_4 -> V_55 ) ) ;
if ( ! V_131 )
goto V_139;
V_166 = F_140 ( & V_4 -> V_137 . V_157 ) ;
if ( ! V_166 )
goto V_167;
for ( V_146 = 0 ; V_146 < V_131 -> V_150 ; V_146 ++ ) {
struct V_68 * V_69 ;
struct V_68 T_4 * * V_151 = & V_131 -> V_140 [ V_146 ] ;
while ( ( V_69 = F_121 ( * V_151 ,
F_122 ( & V_4 -> V_55 ) ) ) != NULL ) {
F_124 ( * V_151 ,
F_121 ( V_69 -> V_141 ,
F_122 ( & V_4 -> V_55 ) ) ) ;
F_125 ( & V_69 -> V_46 ) ;
F_126 ( & V_69 -> V_152 , V_153 ) ;
}
}
V_167:
F_124 ( V_137 -> V_131 , NULL ) ;
F_126 ( & V_131 -> V_152 , F_138 ) ;
V_139:
F_64 ( & V_4 -> V_55 , V_6 ) ;
if ( V_166 )
F_66 ( & V_4 -> V_137 . V_159 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_168 ;
F_3 ( V_4 , L_23 ) ;
F_87 ( & V_4 -> V_137 . V_165 ) ;
F_5 ( V_158 , & V_4 -> V_6 ) ;
V_168 = F_142 ( V_147 , & V_4 -> V_6 ) ;
if ( ! V_168 )
F_143 ( & V_4 -> V_156 ) ;
F_139 ( V_4 ) ;
F_66 ( & V_4 -> V_137 . V_165 ) ;
}
int F_144 ( struct V_1 * V_2 , struct V_169 * V_75 , int V_76 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_170 = F_83 ( V_171 * sizeof * V_4 -> V_170 ,
V_54 ) ;
if ( ! V_4 -> V_170 ) {
F_145 ( V_172 L_24 ,
V_75 -> V_173 , V_171 ) ;
goto V_174;
}
V_4 -> V_175 = F_146 ( V_176 * sizeof * V_4 -> V_175 ) ;
if ( ! V_4 -> V_175 ) {
F_145 ( V_172 L_25 ,
V_75 -> V_173 , V_176 ) ;
goto V_177;
}
if ( F_147 ( V_2 , V_75 , V_76 ) )
goto V_178;
if ( F_136 ( V_4 ) < 0 )
goto V_179;
return 0 ;
V_179:
F_148 ( V_2 ) ;
V_178:
F_149 ( V_4 -> V_175 ) ;
V_177:
F_46 ( V_4 -> V_170 ) ;
V_174:
return - V_162 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_11 , * V_180 ;
F_58 ( V_164 ) ;
F_150 () ;
F_151 ( V_2 ) ;
F_56 (cpriv, tcpriv, &priv->child_intfs, list) {
F_5 ( V_147 , & V_11 -> V_6 ) ;
F_143 ( & V_11 -> V_156 ) ;
F_152 ( V_11 -> V_2 , & V_164 ) ;
}
F_153 ( & V_164 ) ;
F_141 ( V_2 ) ;
F_148 ( V_2 ) ;
F_46 ( V_4 -> V_170 ) ;
F_149 ( V_4 -> V_175 ) ;
V_4 -> V_170 = NULL ;
V_4 -> V_175 = NULL ;
}
void F_154 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_181 = & V_182 ;
V_2 -> V_183 = & V_184 ;
F_155 ( V_2 ) ;
F_156 ( V_2 , & V_4 -> V_185 , V_186 , V_187 ) ;
V_2 -> V_188 = V_189 ;
V_2 -> V_6 |= V_190 | V_191 ;
V_2 -> V_192 = V_193 ;
V_2 -> V_194 = V_124 ;
V_2 -> type = V_195 ;
V_2 -> V_196 = V_176 * 2 ;
V_2 -> V_15 = ( V_197 |
V_198 ) ;
F_157 ( V_2 ) ;
memcpy ( V_2 -> V_81 , V_199 , V_124 ) ;
V_4 -> V_2 = V_2 ;
F_158 ( & V_4 -> V_55 ) ;
F_159 ( & V_4 -> V_12 ) ;
F_84 ( & V_4 -> V_47 ) ;
F_84 ( & V_4 -> V_200 ) ;
F_84 ( & V_4 -> V_201 ) ;
F_84 ( & V_4 -> V_202 ) ;
F_160 ( & V_4 -> V_203 , V_204 ) ;
F_161 ( & V_4 -> V_205 , V_206 ) ;
F_161 ( & V_4 -> V_207 , V_208 ) ;
F_161 ( & V_4 -> V_209 , V_210 ) ;
F_161 ( & V_4 -> V_211 , V_212 ) ;
F_161 ( & V_4 -> V_127 , V_213 ) ;
F_160 ( & V_4 -> V_214 , V_215 ) ;
F_160 ( & V_4 -> V_156 , F_127 ) ;
}
struct V_3 * F_162 ( const char * V_173 )
{
struct V_1 * V_2 ;
V_2 = F_163 ( ( int ) sizeof( struct V_3 ) , V_173 ,
V_216 , F_154 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_5 F_164 ( struct V_217 * V_2 ,
struct V_218 * V_219 , char * V_25 )
{
struct V_3 * V_4 = F_2 ( F_165 ( V_2 ) ) ;
return sprintf ( V_25 , L_26 , V_4 -> V_86 ) ;
}
static T_5 F_166 ( struct V_217 * V_2 ,
struct V_218 * V_219 , char * V_25 )
{
struct V_3 * V_4 = F_2 ( F_165 ( V_2 ) ) ;
return sprintf ( V_25 , L_27 , F_7 ( V_220 , & V_4 -> V_6 ) ) ;
}
void F_167 ( struct V_1 * V_221 , int V_222 )
{
struct V_3 * V_4 = F_2 ( V_221 ) ;
if ( V_222 > 0 ) {
F_5 ( V_220 , & V_4 -> V_6 ) ;
F_25 ( V_4 , L_28
L_29 ) ;
} else
F_15 ( V_220 , & V_4 -> V_6 ) ;
}
static T_5 F_168 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_25 , T_6 V_223 )
{
unsigned long V_222 = F_169 ( V_25 , NULL , 0 ) ;
F_167 ( F_165 ( V_2 ) , V_222 ) ;
return V_223 ;
}
int F_170 ( struct V_1 * V_2 )
{
return F_171 ( & V_2 -> V_2 , & V_224 ) ;
}
static T_5 F_172 ( struct V_217 * V_2 ,
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
V_36 = F_173 ( F_165 ( V_2 ) , V_86 ) ;
return V_36 ? V_36 : V_223 ;
}
static T_5 F_174 ( struct V_217 * V_2 ,
struct V_218 * V_219 ,
const char * V_25 , T_6 V_223 )
{
int V_86 ;
int V_36 ;
if ( sscanf ( V_25 , L_30 , & V_86 ) != 1 )
return - V_14 ;
if ( V_86 < 0 || V_86 > 0xffff )
return - V_14 ;
V_36 = F_175 ( F_165 ( V_2 ) , V_86 ) ;
return V_36 ? V_36 : V_223 ;
}
int F_176 ( struct V_1 * V_2 )
{
return F_171 ( & V_2 -> V_2 , & V_225 ) ;
}
int F_177 ( struct V_3 * V_4 , struct V_169 * V_226 )
{
struct V_227 * V_228 ;
int V_229 = - V_162 ;
V_228 = F_48 ( sizeof *V_228 , V_54 ) ;
if ( ! V_228 ) {
F_145 ( V_172 L_31 ,
V_226 -> V_173 , sizeof *V_228 ) ;
return V_229 ;
}
V_229 = F_178 ( V_226 , V_228 ) ;
if ( V_229 ) {
F_145 ( V_172 L_32 ,
V_226 -> V_173 , V_229 ) ;
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
static struct V_1 * F_179 ( const char * V_236 ,
struct V_169 * V_226 , T_2 V_76 )
{
struct V_3 * V_4 ;
struct V_237 V_219 ;
int V_229 = - V_162 ;
V_4 = F_162 ( V_236 ) ;
if ( ! V_4 )
goto V_238;
F_180 ( V_4 -> V_2 , V_226 -> V_239 ) ;
V_4 -> V_2 -> V_240 = V_76 - 1 ;
if ( ! F_181 ( V_226 , V_76 , & V_219 ) )
V_4 -> V_23 = F_182 ( V_219 . V_241 ) ;
else {
F_145 ( V_172 L_33 ,
V_226 -> V_173 , V_76 ) ;
goto V_242;
}
V_4 -> V_2 -> V_22 = F_26 ( V_4 -> V_23 ) ;
V_4 -> V_21 = V_4 -> V_24 = V_4 -> V_2 -> V_22 ;
V_4 -> V_2 -> V_243 = sizeof( struct V_68 ) ;
V_229 = F_183 ( V_226 , V_76 , 0 , & V_4 -> V_86 ) ;
if ( V_229 ) {
F_145 ( V_172 L_34 ,
V_226 -> V_173 , V_76 , V_229 ) ;
goto V_242;
}
if ( F_177 ( V_4 , V_226 ) )
goto V_242;
V_4 -> V_86 |= 0x8000 ;
V_4 -> V_2 -> V_81 [ 8 ] = V_4 -> V_86 >> 8 ;
V_4 -> V_2 -> V_81 [ 9 ] = V_4 -> V_86 & 0xff ;
V_229 = F_184 ( V_226 , V_76 , 0 , & V_4 -> V_85 ) ;
if ( V_229 ) {
F_145 ( V_172 L_35 ,
V_226 -> V_173 , V_76 , V_229 ) ;
goto V_242;
} else
memcpy ( V_4 -> V_2 -> V_26 + 4 , V_4 -> V_85 . V_39 , sizeof ( union V_40 ) ) ;
V_229 = F_144 ( V_4 -> V_2 , V_226 , V_76 ) ;
if ( V_229 < 0 ) {
F_145 ( V_172 L_36 ,
V_226 -> V_173 , V_76 , V_229 ) ;
goto V_242;
}
F_185 ( & V_4 -> V_244 ,
V_4 -> V_75 , V_245 ) ;
V_229 = F_186 ( & V_4 -> V_244 ) ;
if ( V_229 < 0 ) {
F_145 ( V_172 L_37
L_38 ,
V_226 -> V_173 , V_76 , V_229 ) ;
goto V_246;
}
V_229 = F_187 ( V_4 -> V_2 ) ;
if ( V_229 ) {
F_145 ( V_172 L_39 ,
V_226 -> V_173 , V_76 , V_229 ) ;
goto V_247;
}
F_188 ( V_4 -> V_2 ) ;
if ( F_189 ( V_4 -> V_2 ) )
goto V_248;
if ( F_176 ( V_4 -> V_2 ) )
goto V_248;
if ( F_170 ( V_4 -> V_2 ) )
goto V_248;
if ( F_171 ( & V_4 -> V_2 -> V_2 , & V_249 ) )
goto V_248;
if ( F_171 ( & V_4 -> V_2 -> V_2 , & V_250 ) )
goto V_248;
return V_4 -> V_2 ;
V_248:
F_151 ( V_4 -> V_2 ) ;
F_190 ( V_4 -> V_2 ) ;
V_247:
F_191 ( & V_4 -> V_244 ) ;
F_192 ( V_251 ) ;
F_5 ( V_147 , & V_4 -> V_6 ) ;
F_143 ( & V_4 -> V_156 ) ;
F_192 ( V_4 -> V_126 ) ;
V_246:
F_20 ( V_4 -> V_2 ) ;
V_242:
F_193 ( V_4 -> V_2 ) ;
V_238:
return F_194 ( V_229 ) ;
}
static void F_195 ( struct V_169 * V_217 )
{
struct V_252 * V_253 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_254 , V_255 , V_256 ;
if ( F_196 ( V_217 -> V_257 ) != V_258 )
return;
V_253 = F_48 ( sizeof *V_253 , V_54 ) ;
if ( ! V_253 )
return;
F_84 ( V_253 ) ;
if ( V_217 -> V_257 == V_259 ) {
V_254 = 0 ;
V_255 = 0 ;
} else {
V_254 = 1 ;
V_255 = V_217 -> V_260 ;
}
for ( V_256 = V_254 ; V_256 <= V_255 ; ++ V_256 ) {
if ( F_197 ( V_217 , V_256 ) != V_261 )
continue;
V_2 = F_179 ( L_40 , V_217 , V_256 ) ;
if ( ! F_198 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_40 ( & V_4 -> V_46 , V_253 ) ;
}
}
F_199 ( V_217 , & V_262 , V_253 ) ;
}
static void F_200 ( struct V_169 * V_217 )
{
struct V_3 * V_4 , * V_263 ;
struct V_252 * V_253 ;
if ( F_196 ( V_217 -> V_257 ) != V_258 )
return;
V_253 = F_201 ( V_217 , & V_262 ) ;
if ( ! V_253 )
return;
F_56 (priv, tmp, dev_list, list) {
F_191 ( & V_4 -> V_244 ) ;
F_192 ( V_251 ) ;
F_33 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_13 ) ;
F_31 () ;
F_5 ( V_147 , & V_4 -> V_6 ) ;
F_143 ( & V_4 -> V_156 ) ;
F_192 ( V_4 -> V_126 ) ;
F_190 ( V_4 -> V_2 ) ;
F_193 ( V_4 -> V_2 ) ;
}
F_46 ( V_253 ) ;
}
static int T_7 F_202 ( void )
{
int V_36 ;
V_171 = F_137 ( V_171 ) ;
V_171 = F_27 ( V_171 , V_264 ) ;
V_171 = F_203 ( V_171 , V_265 ) ;
V_176 = F_137 ( V_176 ) ;
V_176 = F_27 ( V_176 , V_264 ) ;
V_176 = F_204 ( V_176 , 2 * V_266 , V_265 ) ;
#ifdef F_205
V_267 = F_27 ( V_267 , V_268 ) ;
#endif
F_206 ( V_269 > V_270 ) ;
V_36 = F_207 () ;
if ( V_36 )
return V_36 ;
V_251 = F_208 ( L_41 ) ;
if ( ! V_251 ) {
V_36 = - V_162 ;
goto V_271;
}
F_209 ( & V_90 ) ;
V_36 = F_210 ( & V_262 ) ;
if ( V_36 )
goto V_272;
V_36 = F_211 () ;
if ( V_36 )
goto V_273;
return 0 ;
V_273:
F_212 ( & V_262 ) ;
V_272:
F_213 ( & V_90 ) ;
F_214 ( V_251 ) ;
V_271:
F_215 () ;
return V_36 ;
}
static void T_8 F_216 ( void )
{
F_217 () ;
F_212 ( & V_262 ) ;
F_213 ( & V_90 ) ;
F_215 () ;
F_214 ( V_251 ) ;
}
