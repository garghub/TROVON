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
F_18 ( V_2 , 0 ) ;
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
static T_1 F_19 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_8 ( V_15 , & V_4 -> V_6 ) )
V_14 &= ~ ( V_16 | V_17 | V_18 ) ;
return V_14 ;
}
static int F_20 ( struct V_1 * V_2 , int V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_21 ( V_2 ) ) {
if ( V_19 > F_22 ( V_2 ) )
return - V_13 ;
if ( V_19 > V_4 -> V_20 )
F_23 ( V_4 , L_3 ,
V_4 -> V_20 ) ;
V_2 -> V_21 = V_19 ;
return 0 ;
}
if ( V_19 > F_24 ( V_4 -> V_22 ) )
return - V_13 ;
V_4 -> V_23 = V_19 ;
V_2 -> V_21 = F_25 ( V_4 -> V_20 , V_4 -> V_23 ) ;
return 0 ;
}
static struct V_24 * F_26 ( struct V_1 * V_2 , void * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 = V_4 -> V_28 . V_26 ;
struct V_24 * V_29 ;
int V_30 ;
while ( V_27 ) {
V_29 = F_27 ( V_27 , struct V_24 , V_26 ) ;
V_30 = memcmp ( V_25 , V_29 -> V_31 . V_32 . V_33 ,
sizeof ( union V_34 ) ) ;
if ( V_30 < 0 )
V_27 = V_27 -> V_35 ;
else if ( V_30 > 0 )
V_27 = V_27 -> V_36 ;
else
return V_29 ;
}
return NULL ;
}
static int F_28 ( struct V_1 * V_2 , struct V_24 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * * V_27 = & V_4 -> V_28 . V_26 ;
struct V_26 * V_37 = NULL ;
struct V_24 * V_38 ;
int V_30 ;
while ( * V_27 ) {
V_37 = * V_27 ;
V_38 = F_27 ( V_37 , struct V_24 , V_26 ) ;
V_30 = memcmp ( V_29 -> V_31 . V_32 . V_33 , V_38 -> V_31 . V_32 . V_33 ,
sizeof ( union V_34 ) ) ;
if ( V_30 < 0 )
V_27 = & V_37 -> V_35 ;
else if ( V_30 > 0 )
V_27 = & V_37 -> V_36 ;
else
return - V_39 ;
}
F_29 ( & V_29 -> V_26 , V_37 , V_27 ) ;
F_30 ( & V_29 -> V_26 , & V_4 -> V_28 ) ;
F_31 ( & V_29 -> V_40 , & V_4 -> V_41 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_24 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 , * V_44 ;
struct V_45 * V_46 ;
unsigned long V_6 ;
while ( ( V_46 = F_33 ( & V_29 -> V_47 ) ) )
F_34 ( V_46 ) ;
F_35 ( & V_4 -> V_48 , V_6 ) ;
F_36 (neigh, tn, &path->neigh_list, list) {
if ( V_43 -> V_49 )
F_37 ( V_43 -> V_49 ) ;
F_38 ( V_2 , V_43 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
if ( V_29 -> V_49 )
F_37 ( V_29 -> V_49 ) ;
F_40 ( V_29 ) ;
}
struct V_50 * F_41 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
V_51 = F_42 ( sizeof *V_51 , V_52 ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_2 = V_2 ;
memset ( V_51 -> V_29 . V_31 . V_32 . V_33 , 0 , 16 ) ;
if ( F_43 ( V_51 ) ) {
F_40 ( V_51 ) ;
return NULL ;
}
return V_51 ;
}
int F_43 ( struct V_50 * V_51 )
{
struct V_3 * V_4 = F_2 ( V_51 -> V_2 ) ;
struct V_26 * V_27 ;
struct V_24 * V_29 ;
int V_30 = 1 ;
F_44 ( & V_4 -> V_48 ) ;
V_27 = F_45 ( & V_4 -> V_28 ) ;
while ( V_27 ) {
V_29 = F_27 ( V_27 , struct V_24 , V_26 ) ;
if ( memcmp ( V_51 -> V_29 . V_31 . V_32 . V_33 , V_29 -> V_31 . V_32 . V_33 ,
sizeof ( union V_34 ) ) < 0 ) {
V_51 -> V_29 = * V_29 ;
V_30 = 0 ;
break;
}
V_27 = F_46 ( V_27 ) ;
}
F_47 ( & V_4 -> V_48 ) ;
return V_30 ;
}
void F_48 ( struct V_50 * V_51 ,
struct V_24 * V_29 )
{
* V_29 = V_51 -> V_29 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_29 , * V_53 ;
F_44 ( & V_4 -> V_48 ) ;
F_36 (path, tp, &priv->path_list, list) {
F_3 ( V_4 , L_4 ,
F_50 ( V_29 -> V_31 . V_54 ) ,
V_29 -> V_31 . V_32 . V_33 ) ;
V_29 -> V_55 = 0 ;
}
F_47 ( & V_4 -> V_48 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_29 , * V_53 ;
F_52 ( V_56 ) ;
unsigned long V_6 ;
F_53 ( V_2 ) ;
F_35 ( & V_4 -> V_48 , V_6 ) ;
F_54 ( & V_4 -> V_41 , & V_56 ) ;
F_10 (path, &remove_list, list)
F_55 ( & V_29 -> V_26 , & V_4 -> V_28 ) ;
F_36 (path, tp, &remove_list, list) {
if ( V_29 -> V_57 )
F_56 ( V_29 -> V_58 , V_29 -> V_57 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_57 ( V_2 ) ;
F_58 ( & V_29 -> V_59 ) ;
F_32 ( V_2 , V_29 ) ;
F_53 ( V_2 ) ;
F_35 ( & V_4 -> V_48 , V_6 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_57 ( V_2 ) ;
}
static void F_59 ( int V_60 ,
struct V_61 * V_31 ,
void * V_62 )
{
struct V_24 * V_29 = V_62 ;
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_63 * V_49 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_42 * V_43 , * V_44 ;
struct V_65 V_66 ;
struct V_45 * V_46 ;
unsigned long V_6 ;
if ( ! V_60 )
F_3 ( V_4 , L_5 ,
F_50 ( V_31 -> V_54 ) , V_31 -> V_32 . V_33 ) ;
else
F_3 ( V_4 , L_6 ,
V_60 , V_29 -> V_31 . V_32 . V_33 ) ;
F_60 ( & V_66 ) ;
if ( ! V_60 ) {
struct V_67 V_68 ;
if ( ! F_61 ( V_4 -> V_69 , V_4 -> V_70 , V_31 , & V_68 ) )
V_49 = F_62 ( V_2 , V_4 -> V_71 , & V_68 ) ;
}
F_35 ( & V_4 -> V_48 , V_6 ) ;
if ( ! F_63 ( V_49 ) ) {
V_29 -> V_31 = * V_31 ;
V_64 = V_29 -> V_49 ;
V_29 -> V_49 = V_49 ;
F_3 ( V_4 , L_7 ,
V_49 , F_50 ( V_31 -> V_54 ) , V_31 -> V_72 ) ;
while ( ( V_46 = F_33 ( & V_29 -> V_47 ) ) )
F_64 ( & V_66 , V_46 ) ;
F_36 (neigh, tn, &path->neigh_list, list) {
if ( V_43 -> V_49 ) {
F_65 ( V_43 -> V_49 != V_64 ) ;
F_37 ( V_43 -> V_49 ) ;
}
F_66 ( & V_29 -> V_49 -> V_73 ) ;
V_43 -> V_49 = V_29 -> V_49 ;
memcpy ( & V_43 -> V_32 . V_33 , & V_29 -> V_31 . V_32 . V_33 ,
sizeof( union V_34 ) ) ;
if ( F_67 ( V_2 , V_43 -> V_74 ) ) {
if ( ! F_68 ( V_43 ) )
F_69 ( V_43 , F_70 ( V_2 ,
V_29 ,
V_43 ) ) ;
if ( ! F_68 ( V_43 ) ) {
F_71 ( & V_43 -> V_40 ) ;
if ( V_43 -> V_49 )
F_37 ( V_43 -> V_49 ) ;
F_38 ( V_2 , V_43 ) ;
continue;
}
}
while ( ( V_46 = F_33 ( & V_43 -> V_47 ) ) )
F_64 ( & V_66 , V_46 ) ;
}
V_29 -> V_55 = 1 ;
}
V_29 -> V_57 = NULL ;
F_72 ( & V_29 -> V_59 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
if ( V_64 )
F_37 ( V_64 ) ;
while ( ( V_46 = F_33 ( & V_66 ) ) ) {
V_46 -> V_2 = V_2 ;
if ( F_73 ( V_46 ) )
F_23 ( V_4 , L_8
L_9 ) ;
}
}
static struct V_24 * F_74 ( struct V_1 * V_2 , void * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_29 ;
if ( ! V_4 -> V_75 )
return NULL ;
V_29 = F_75 ( sizeof *V_29 , V_76 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_2 = V_2 ;
F_60 ( & V_29 -> V_47 ) ;
F_76 ( & V_29 -> V_77 ) ;
memcpy ( V_29 -> V_31 . V_32 . V_33 , V_25 , sizeof ( union V_34 ) ) ;
V_29 -> V_31 . V_78 = V_4 -> V_79 ;
V_29 -> V_31 . V_80 = F_77 ( V_4 -> V_80 ) ;
V_29 -> V_31 . V_81 = 1 ;
V_29 -> V_31 . V_82 = V_4 -> V_75 -> V_83 . V_82 ;
return V_29 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_24 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_10 ,
V_29 -> V_31 . V_32 . V_33 ) ;
F_79 ( & V_29 -> V_59 ) ;
V_29 -> V_58 =
F_80 ( & V_84 , V_4 -> V_69 , V_4 -> V_70 ,
& V_29 -> V_31 ,
V_85 |
V_86 |
V_87 |
V_88 |
V_89 ,
1000 , V_76 ,
F_59 ,
V_29 , & V_29 -> V_57 ) ;
if ( V_29 -> V_58 < 0 ) {
F_23 ( V_4 , L_11 , V_29 -> V_58 ) ;
V_29 -> V_57 = NULL ;
F_72 ( & V_29 -> V_59 ) ;
return V_29 -> V_58 ;
}
return 0 ;
}
static void F_81 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_29 ;
struct V_42 * V_43 ;
struct V_74 * V_27 ;
unsigned long V_6 ;
V_27 = F_82 ( F_83 ( V_46 ) ) ;
V_43 = F_84 ( V_27 , V_46 -> V_2 ) ;
if ( ! V_43 ) {
++ V_2 -> V_90 . V_91 ;
F_85 ( V_46 ) ;
return;
}
F_35 ( & V_4 -> V_48 , V_6 ) ;
V_29 = F_26 ( V_2 , V_27 -> V_92 + 4 ) ;
if ( ! V_29 ) {
V_29 = F_74 ( V_2 , V_27 -> V_92 + 4 ) ;
if ( ! V_29 )
goto V_93;
F_28 ( V_2 , V_29 ) ;
}
F_31 ( & V_43 -> V_40 , & V_29 -> V_77 ) ;
if ( V_29 -> V_49 ) {
F_66 ( & V_29 -> V_49 -> V_73 ) ;
V_43 -> V_49 = V_29 -> V_49 ;
memcpy ( & V_43 -> V_32 . V_33 , & V_29 -> V_31 . V_32 . V_33 ,
sizeof( union V_34 ) ) ;
if ( F_67 ( V_2 , V_43 -> V_74 ) ) {
if ( ! F_68 ( V_43 ) )
F_69 ( V_43 , F_70 ( V_2 , V_29 , V_43 ) ) ;
if ( ! F_68 ( V_43 ) ) {
F_71 ( & V_43 -> V_40 ) ;
if ( V_43 -> V_49 )
F_37 ( V_43 -> V_49 ) ;
F_38 ( V_2 , V_43 ) ;
goto V_94;
}
if ( F_86 ( & V_43 -> V_47 ) < V_95 )
F_64 ( & V_43 -> V_47 , V_46 ) ;
else {
F_23 ( V_4 , L_12 ,
F_86 ( & V_43 -> V_47 ) ) ;
goto V_94;
}
} else {
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_87 ( V_2 , V_46 , V_29 -> V_49 , F_88 ( V_27 -> V_92 ) ) ;
return;
}
} else {
V_43 -> V_49 = NULL ;
if ( ! V_29 -> V_57 && F_78 ( V_2 , V_29 ) )
goto V_96;
F_64 ( & V_43 -> V_47 , V_46 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
return;
V_96:
F_71 ( & V_43 -> V_40 ) ;
V_93:
F_38 ( V_2 , V_43 ) ;
V_94:
++ V_2 -> V_90 . V_91 ;
F_85 ( V_46 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
}
static void F_89 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_46 -> V_2 ) ;
struct V_97 * V_98 = F_83 ( V_46 ) ;
struct V_74 * V_27 ;
V_27 = F_82 ( V_98 ) ;
if ( V_27 -> V_92 [ 4 ] != 0xff ) {
F_81 ( V_46 , V_2 ) ;
return;
}
V_27 -> V_92 [ 8 ] = ( V_4 -> V_80 >> 8 ) & 0xff ;
V_27 -> V_92 [ 9 ] = V_4 -> V_80 & 0xff ;
F_90 ( V_2 , V_27 -> V_92 + 4 , V_46 ) ;
}
static void F_91 ( struct V_45 * V_46 , struct V_1 * V_2 ,
struct V_99 * V_100 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_29 ;
unsigned long V_6 ;
F_35 ( & V_4 -> V_48 , V_6 ) ;
V_29 = F_26 ( V_2 , V_100 -> V_101 + 4 ) ;
if ( ! V_29 || ! V_29 -> V_55 ) {
int V_102 = 0 ;
if ( ! V_29 ) {
V_29 = F_74 ( V_2 , V_100 -> V_101 + 4 ) ;
V_102 = 1 ;
}
if ( V_29 ) {
F_92 ( V_46 , sizeof *V_100 ) ;
F_64 ( & V_29 -> V_47 , V_46 ) ;
if ( ! V_29 -> V_57 && F_78 ( V_2 , V_29 ) ) {
F_39 ( & V_4 -> V_48 , V_6 ) ;
if ( V_102 )
F_32 ( V_2 , V_29 ) ;
return;
} else
F_28 ( V_2 , V_29 ) ;
} else {
++ V_2 -> V_90 . V_91 ;
F_85 ( V_46 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
return;
}
if ( V_29 -> V_49 ) {
F_3 ( V_4 , L_13 ,
F_50 ( V_29 -> V_31 . V_54 ) ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_87 ( V_2 , V_46 , V_29 -> V_49 , F_88 ( V_100 -> V_101 ) ) ;
return;
} else if ( ( V_29 -> V_57 || ! F_78 ( V_2 , V_29 ) ) &&
F_86 ( & V_29 -> V_47 ) < V_95 ) {
F_92 ( V_46 , sizeof *V_100 ) ;
F_64 ( & V_29 -> V_47 , V_46 ) ;
} else {
++ V_2 -> V_90 . V_91 ;
F_85 ( V_46 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
}
static int F_93 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 ;
struct V_74 * V_27 = NULL ;
unsigned long V_6 ;
F_94 () ;
if ( F_95 ( F_83 ( V_46 ) ) )
V_27 = F_82 ( F_83 ( V_46 ) ) ;
if ( F_95 ( V_27 ) ) {
if ( F_96 ( ! * F_97 ( V_27 ) ) ) {
F_89 ( V_46 , V_2 ) ;
goto V_103;
}
V_43 = * F_97 ( V_27 ) ;
if ( F_96 ( ( memcmp ( & V_43 -> V_32 . V_33 ,
V_27 -> V_92 + 4 ,
sizeof( union V_34 ) ) ) ||
( V_43 -> V_2 != V_2 ) ) ) {
F_35 ( & V_4 -> V_48 , V_6 ) ;
if ( V_43 -> V_49 )
F_37 ( V_43 -> V_49 ) ;
F_71 ( & V_43 -> V_40 ) ;
F_38 ( V_2 , V_43 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_89 ( V_46 , V_2 ) ;
goto V_103;
}
if ( F_68 ( V_43 ) ) {
if ( F_98 ( V_43 ) ) {
F_99 ( V_2 , V_46 , F_68 ( V_43 ) ) ;
goto V_103;
}
} else if ( V_43 -> V_49 ) {
F_87 ( V_2 , V_46 , V_43 -> V_49 , F_88 ( V_27 -> V_92 ) ) ;
goto V_103;
}
if ( F_86 ( & V_43 -> V_47 ) < V_95 ) {
F_35 ( & V_4 -> V_48 , V_6 ) ;
F_64 ( & V_43 -> V_47 , V_46 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
} else {
++ V_2 -> V_90 . V_91 ;
F_85 ( V_46 ) ;
}
} else {
struct V_99 * V_100 =
(struct V_99 * ) V_46 -> V_104 ;
F_100 ( V_46 , sizeof *V_100 ) ;
if ( V_100 -> V_101 [ 4 ] == 0xff ) {
V_100 -> V_101 [ 8 ] = ( V_4 -> V_80 >> 8 ) & 0xff ;
V_100 -> V_101 [ 9 ] = V_4 -> V_80 & 0xff ;
F_90 ( V_2 , V_100 -> V_101 + 4 , V_46 ) ;
} else {
if ( ( F_101 ( ( V_105 * ) V_46 -> V_104 ) != V_106 ) &&
( F_101 ( ( V_105 * ) V_46 -> V_104 ) != V_107 ) ) {
F_23 ( V_4 , L_14 ,
F_83 ( V_46 ) ? L_15 : L_16 ,
F_101 ( ( V_105 * ) V_46 -> V_104 ) ,
F_88 ( V_100 -> V_101 ) ,
V_100 -> V_101 + 4 ) ;
F_85 ( V_46 ) ;
++ V_2 -> V_90 . V_91 ;
goto V_103;
}
F_91 ( V_46 , V_2 , V_100 ) ;
}
}
V_103:
F_102 () ;
return V_108 ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_23 ( V_4 , L_17 ,
F_104 ( V_109 - V_2 -> V_110 ) ) ;
F_23 ( V_4 , L_18 ,
F_105 ( V_2 ) ,
V_4 -> V_111 , V_4 -> V_112 ) ;
}
static int F_106 ( struct V_45 * V_46 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_113 , const void * V_114 , unsigned V_115 )
{
struct V_116 * V_117 ;
struct V_97 * V_98 ;
struct V_74 * V_27 ;
V_117 = (struct V_116 * ) F_92 ( V_46 , sizeof *V_117 ) ;
V_117 -> V_118 = F_107 ( type ) ;
V_117 -> V_119 = 0 ;
V_98 = F_83 ( V_46 ) ;
V_27 = NULL ;
if ( V_98 )
V_27 = F_108 ( V_98 ) ;
if ( ( ! V_98 || ! V_27 ) && V_113 ) {
struct V_99 * V_100 =
(struct V_99 * ) F_92 ( V_46 , sizeof *V_100 ) ;
memcpy ( V_100 -> V_101 , V_113 , V_120 ) ;
}
return 0 ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_8 ( V_121 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_19 ) ;
return;
}
F_110 ( V_122 , & V_4 -> V_123 ) ;
}
static void F_111 ( struct V_74 * V_27 )
{
struct V_42 * V_43 ;
struct V_3 * V_4 = F_2 ( V_27 -> V_2 ) ;
unsigned long V_6 ;
struct V_63 * V_49 = NULL ;
V_43 = * F_97 ( V_27 ) ;
if ( V_43 )
V_4 = F_2 ( V_43 -> V_2 ) ;
else
return;
F_3 ( V_4 ,
L_20 ,
F_88 ( V_27 -> V_92 ) ,
V_27 -> V_92 + 4 ) ;
F_35 ( & V_4 -> V_48 , V_6 ) ;
if ( V_43 -> V_49 )
V_49 = V_43 -> V_49 ;
F_71 ( & V_43 -> V_40 ) ;
F_38 ( V_27 -> V_2 , V_43 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
if ( V_49 )
F_37 ( V_49 ) ;
}
struct V_42 * F_84 ( struct V_74 * V_74 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 ;
V_43 = F_42 ( sizeof *V_43 , V_76 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_74 = V_74 ;
V_43 -> V_2 = V_2 ;
memset ( & V_43 -> V_32 . V_33 , 0 , sizeof ( union V_34 ) ) ;
* F_97 ( V_74 ) = V_43 ;
F_60 ( & V_43 -> V_47 ) ;
F_69 ( V_43 , NULL ) ;
return V_43 ;
}
void F_38 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_45 * V_46 ;
* F_97 ( V_43 -> V_74 ) = NULL ;
while ( ( V_46 = F_33 ( & V_43 -> V_47 ) ) ) {
++ V_2 -> V_90 . V_91 ;
F_85 ( V_46 ) ;
}
if ( F_68 ( V_43 ) )
F_112 ( F_68 ( V_43 ) ) ;
F_40 ( V_43 ) ;
}
static int F_113 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
V_125 -> V_126 = F_111 ;
return 0 ;
}
int F_114 ( struct V_1 * V_2 , struct V_127 * V_69 , int V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_128 = F_75 ( V_129 * sizeof * V_4 -> V_128 ,
V_52 ) ;
if ( ! V_4 -> V_128 ) {
F_115 ( V_130 L_21 ,
V_69 -> V_131 , V_129 ) ;
goto V_132;
}
V_4 -> V_133 = F_116 ( V_134 * sizeof * V_4 -> V_133 ) ;
if ( ! V_4 -> V_133 ) {
F_115 ( V_130 L_22 ,
V_69 -> V_131 , V_134 ) ;
goto V_135;
}
if ( F_117 ( V_2 , V_69 , V_70 ) )
goto V_136;
return 0 ;
V_136:
F_118 ( V_4 -> V_133 ) ;
V_135:
F_40 ( V_4 -> V_128 ) ;
V_132:
return - V_137 ;
}
void F_119 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_10 , * V_138 ;
F_120 ( V_2 ) ;
F_36 (cpriv, tcpriv, &priv->child_intfs, list) {
F_121 ( V_10 -> V_2 ) ;
F_119 ( V_10 -> V_2 ) ;
F_122 ( V_10 -> V_2 ) ;
}
F_123 ( V_2 ) ;
F_40 ( V_4 -> V_128 ) ;
F_118 ( V_4 -> V_133 ) ;
V_4 -> V_128 = NULL ;
V_4 -> V_133 = NULL ;
}
static void F_124 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_139 = & V_140 ;
V_2 -> V_141 = & V_142 ;
F_125 ( V_2 ) ;
F_126 ( V_2 , & V_4 -> V_143 , V_144 , 100 ) ;
V_2 -> V_145 = V_146 ;
V_2 -> V_6 |= V_147 | V_148 ;
V_2 -> V_149 = V_150 + V_120 ;
V_2 -> V_151 = V_120 ;
V_2 -> type = V_152 ;
V_2 -> V_153 = V_134 * 2 ;
V_2 -> V_14 = ( V_154 |
V_155 ) ;
V_2 -> V_156 &= ~ V_157 ;
memcpy ( V_2 -> V_75 , V_158 , V_120 ) ;
F_127 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
F_128 ( & V_4 -> V_48 ) ;
F_129 ( & V_4 -> V_11 ) ;
F_76 ( & V_4 -> V_41 ) ;
F_76 ( & V_4 -> V_159 ) ;
F_76 ( & V_4 -> V_160 ) ;
F_76 ( & V_4 -> V_161 ) ;
F_130 ( & V_4 -> V_162 , V_163 ) ;
F_130 ( & V_4 -> V_164 , V_165 ) ;
F_131 ( & V_4 -> V_166 , V_167 ) ;
F_131 ( & V_4 -> V_168 , V_169 ) ;
F_131 ( & V_4 -> V_170 , V_171 ) ;
F_131 ( & V_4 -> V_172 , V_173 ) ;
F_131 ( & V_4 -> V_123 , V_174 ) ;
F_130 ( & V_4 -> V_175 , V_176 ) ;
}
struct V_3 * F_132 ( const char * V_131 )
{
struct V_1 * V_2 ;
V_2 = F_133 ( ( int ) sizeof ( struct V_3 ) , V_131 ,
F_124 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_2 F_134 ( struct V_177 * V_2 ,
struct V_178 * V_179 , char * V_180 )
{
struct V_3 * V_4 = F_2 ( F_135 ( V_2 ) ) ;
return sprintf ( V_180 , L_23 , V_4 -> V_80 ) ;
}
static T_2 F_136 ( struct V_177 * V_2 ,
struct V_178 * V_179 , char * V_180 )
{
struct V_3 * V_4 = F_2 ( F_135 ( V_2 ) ) ;
return sprintf ( V_180 , L_24 , F_8 ( V_181 , & V_4 -> V_6 ) ) ;
}
static T_2 F_137 ( struct V_177 * V_2 ,
struct V_178 * V_179 ,
const char * V_180 , T_3 V_182 )
{
struct V_3 * V_4 = F_2 ( F_135 ( V_2 ) ) ;
unsigned long V_183 = F_138 ( V_180 , NULL , 0 ) ;
if ( V_183 > 0 ) {
F_4 ( V_181 , & V_4 -> V_6 ) ;
F_23 ( V_4 , L_25
L_26 ) ;
} else
F_15 ( V_181 , & V_4 -> V_6 ) ;
return V_182 ;
}
int F_139 ( struct V_1 * V_2 )
{
return F_140 ( & V_2 -> V_2 , & V_184 ) ;
}
static T_2 F_141 ( struct V_177 * V_2 ,
struct V_178 * V_179 ,
const char * V_180 , T_3 V_182 )
{
int V_80 ;
int V_30 ;
if ( sscanf ( V_180 , L_27 , & V_80 ) != 1 )
return - V_13 ;
if ( V_80 < 0 || V_80 > 0xffff )
return - V_13 ;
V_80 |= 0x8000 ;
V_30 = F_142 ( F_135 ( V_2 ) , V_80 ) ;
return V_30 ? V_30 : V_182 ;
}
static T_2 F_143 ( struct V_177 * V_2 ,
struct V_178 * V_179 ,
const char * V_180 , T_3 V_182 )
{
int V_80 ;
int V_30 ;
if ( sscanf ( V_180 , L_27 , & V_80 ) != 1 )
return - V_13 ;
if ( V_80 < 0 || V_80 > 0xffff )
return - V_13 ;
V_30 = F_144 ( F_135 ( V_2 ) , V_80 ) ;
return V_30 ? V_30 : V_182 ;
}
int F_145 ( struct V_1 * V_2 )
{
return F_140 ( & V_2 -> V_2 , & V_185 ) ;
}
int F_146 ( struct V_3 * V_4 , struct V_127 * V_186 )
{
struct V_187 * V_188 ;
int V_189 = - V_137 ;
V_188 = F_42 ( sizeof *V_188 , V_52 ) ;
if ( ! V_188 ) {
F_115 ( V_130 L_28 ,
V_186 -> V_131 , sizeof *V_188 ) ;
return V_189 ;
}
V_189 = F_147 ( V_186 , V_188 ) ;
if ( V_189 ) {
F_115 ( V_130 L_29 ,
V_186 -> V_131 , V_189 ) ;
F_40 ( V_188 ) ;
return V_189 ;
}
V_4 -> V_190 = V_188 -> V_191 ;
F_40 ( V_188 ) ;
if ( V_4 -> V_190 & V_192 ) {
V_4 -> V_2 -> V_193 = V_16 |
V_17 | V_194 ;
if ( V_4 -> V_190 & V_195 )
V_4 -> V_2 -> V_193 |= V_18 ;
V_4 -> V_2 -> V_14 |= V_4 -> V_2 -> V_193 ;
}
return 0 ;
}
static struct V_1 * F_148 ( const char * V_196 ,
struct V_127 * V_186 , T_4 V_70 )
{
struct V_3 * V_4 ;
struct V_197 V_179 ;
int V_189 = - V_137 ;
V_4 = F_132 ( V_196 ) ;
if ( ! V_4 )
goto V_198;
F_149 ( V_4 -> V_2 , V_186 -> V_199 ) ;
V_4 -> V_2 -> V_200 = V_70 - 1 ;
if ( ! F_150 ( V_186 , V_70 , & V_179 ) )
V_4 -> V_22 = F_151 ( V_179 . V_201 ) ;
else {
F_115 ( V_130 L_30 ,
V_186 -> V_131 , V_70 ) ;
goto V_202;
}
V_4 -> V_2 -> V_21 = F_24 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_189 = F_152 ( V_186 , V_70 , 0 , & V_4 -> V_80 ) ;
if ( V_189 ) {
F_115 ( V_130 L_31 ,
V_186 -> V_131 , V_70 , V_189 ) ;
goto V_202;
}
if ( F_146 ( V_4 , V_186 ) )
goto V_202;
V_4 -> V_80 |= 0x8000 ;
V_4 -> V_2 -> V_75 [ 8 ] = V_4 -> V_80 >> 8 ;
V_4 -> V_2 -> V_75 [ 9 ] = V_4 -> V_80 & 0xff ;
V_189 = F_153 ( V_186 , V_70 , 0 , & V_4 -> V_79 ) ;
if ( V_189 ) {
F_115 ( V_130 L_32 ,
V_186 -> V_131 , V_70 , V_189 ) ;
goto V_202;
} else
memcpy ( V_4 -> V_2 -> V_203 + 4 , V_4 -> V_79 . V_33 , sizeof ( union V_34 ) ) ;
V_189 = F_114 ( V_4 -> V_2 , V_186 , V_70 ) ;
if ( V_189 < 0 ) {
F_115 ( V_130 L_33 ,
V_186 -> V_131 , V_70 , V_189 ) ;
goto V_202;
}
F_154 ( & V_4 -> V_204 ,
V_4 -> V_69 , V_205 ) ;
V_189 = F_155 ( & V_4 -> V_204 ) ;
if ( V_189 < 0 ) {
F_115 ( V_130 L_34
L_35 ,
V_186 -> V_131 , V_70 , V_189 ) ;
goto V_206;
}
V_189 = F_156 ( V_4 -> V_2 ) ;
if ( V_189 ) {
F_115 ( V_130 L_36 ,
V_186 -> V_131 , V_70 , V_189 ) ;
goto V_207;
}
F_157 ( V_4 -> V_2 ) ;
if ( F_158 ( V_4 -> V_2 ) )
goto V_208;
if ( F_145 ( V_4 -> V_2 ) )
goto V_208;
if ( F_139 ( V_4 -> V_2 ) )
goto V_208;
if ( F_140 ( & V_4 -> V_2 -> V_2 , & V_209 ) )
goto V_208;
if ( F_140 ( & V_4 -> V_2 -> V_2 , & V_210 ) )
goto V_208;
return V_4 -> V_2 ;
V_208:
F_120 ( V_4 -> V_2 ) ;
F_121 ( V_4 -> V_2 ) ;
V_207:
F_159 ( & V_4 -> V_204 ) ;
F_160 ( V_122 ) ;
V_206:
F_119 ( V_4 -> V_2 ) ;
V_202:
F_122 ( V_4 -> V_2 ) ;
V_198:
return F_161 ( V_189 ) ;
}
static void F_162 ( struct V_127 * V_177 )
{
struct V_211 * V_212 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_213 , V_214 , V_215 ;
if ( F_163 ( V_177 -> V_216 ) != V_217 )
return;
V_212 = F_42 ( sizeof *V_212 , V_52 ) ;
if ( ! V_212 )
return;
F_76 ( V_212 ) ;
if ( V_177 -> V_216 == V_218 ) {
V_213 = 0 ;
V_214 = 0 ;
} else {
V_213 = 1 ;
V_214 = V_177 -> V_219 ;
}
for ( V_215 = V_213 ; V_215 <= V_214 ; ++ V_215 ) {
if ( F_164 ( V_177 , V_215 ) != V_220 )
continue;
V_2 = F_148 ( L_37 , V_177 , V_215 ) ;
if ( ! F_165 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_31 ( & V_4 -> V_40 , V_212 ) ;
}
}
F_166 ( V_177 , & V_221 , V_212 ) ;
}
static void F_167 ( struct V_127 * V_177 )
{
struct V_3 * V_4 , * V_222 ;
struct V_211 * V_212 ;
if ( F_163 ( V_177 -> V_216 ) != V_217 )
return;
V_212 = F_168 ( V_177 , & V_221 ) ;
F_36 (priv, tmp, dev_list, list) {
F_159 ( & V_4 -> V_204 ) ;
F_169 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_12 ) ;
F_170 () ;
F_160 ( V_122 ) ;
F_121 ( V_4 -> V_2 ) ;
F_119 ( V_4 -> V_2 ) ;
F_122 ( V_4 -> V_2 ) ;
}
F_40 ( V_212 ) ;
}
static int T_5 F_171 ( void )
{
int V_30 ;
V_129 = F_172 ( V_129 ) ;
V_129 = F_25 ( V_129 , V_223 ) ;
V_129 = F_173 ( V_129 , V_224 ) ;
V_134 = F_172 ( V_134 ) ;
V_134 = F_25 ( V_134 , V_223 ) ;
V_134 = F_174 ( V_134 , 2 * V_225 , V_224 ) ;
#ifdef F_175
V_226 = F_25 ( V_226 , V_227 ) ;
#endif
F_176 ( V_228 > V_229 ) ;
V_30 = F_177 () ;
if ( V_30 )
return V_30 ;
V_122 = F_178 ( L_38 ) ;
if ( ! V_122 ) {
V_30 = - V_137 ;
goto V_230;
}
F_179 ( & V_84 ) ;
V_30 = F_180 ( & V_221 ) ;
if ( V_30 )
goto V_231;
return 0 ;
V_231:
F_181 ( & V_84 ) ;
F_182 ( V_122 ) ;
V_230:
F_183 () ;
return V_30 ;
}
static void T_6 F_184 ( void )
{
F_185 ( & V_221 ) ;
F_181 ( & V_84 ) ;
F_183 () ;
F_182 ( V_122 ) ;
}
