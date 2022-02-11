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
if ( V_49 ) {
V_29 -> V_31 = * V_31 ;
V_64 = V_29 -> V_49 ;
V_29 -> V_49 = V_49 ;
F_3 ( V_4 , L_7 ,
V_49 , F_50 ( V_31 -> V_54 ) , V_31 -> V_72 ) ;
while ( ( V_46 = F_33 ( & V_29 -> V_47 ) ) )
F_63 ( & V_66 , V_46 ) ;
F_36 (neigh, tn, &path->neigh_list, list) {
if ( V_43 -> V_49 ) {
F_64 ( V_43 -> V_49 != V_64 ) ;
F_37 ( V_43 -> V_49 ) ;
}
F_65 ( & V_29 -> V_49 -> V_73 ) ;
V_43 -> V_49 = V_29 -> V_49 ;
memcpy ( & V_43 -> V_32 . V_33 , & V_29 -> V_31 . V_32 . V_33 ,
sizeof( union V_34 ) ) ;
if ( F_66 ( V_2 , V_43 -> V_74 ) ) {
if ( ! F_67 ( V_43 ) )
F_68 ( V_43 , F_69 ( V_2 ,
V_29 ,
V_43 ) ) ;
if ( ! F_67 ( V_43 ) ) {
F_70 ( & V_43 -> V_40 ) ;
if ( V_43 -> V_49 )
F_37 ( V_43 -> V_49 ) ;
F_38 ( V_2 , V_43 ) ;
continue;
}
}
while ( ( V_46 = F_33 ( & V_43 -> V_47 ) ) )
F_63 ( & V_66 , V_46 ) ;
}
V_29 -> V_55 = 1 ;
}
V_29 -> V_57 = NULL ;
F_71 ( & V_29 -> V_59 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
if ( V_64 )
F_37 ( V_64 ) ;
while ( ( V_46 = F_33 ( & V_66 ) ) ) {
V_46 -> V_2 = V_2 ;
if ( F_72 ( V_46 ) )
F_23 ( V_4 , L_8
L_9 ) ;
}
}
static struct V_24 * F_73 ( struct V_1 * V_2 , void * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_29 ;
if ( ! V_4 -> V_75 )
return NULL ;
V_29 = F_74 ( sizeof *V_29 , V_76 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> V_2 = V_2 ;
F_60 ( & V_29 -> V_47 ) ;
F_75 ( & V_29 -> V_77 ) ;
memcpy ( V_29 -> V_31 . V_32 . V_33 , V_25 , sizeof ( union V_34 ) ) ;
V_29 -> V_31 . V_78 = V_4 -> V_79 ;
V_29 -> V_31 . V_80 = F_76 ( V_4 -> V_80 ) ;
V_29 -> V_31 . V_81 = 1 ;
V_29 -> V_31 . V_82 = V_4 -> V_75 -> V_83 . V_82 ;
return V_29 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_24 * V_29 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , L_10 ,
V_29 -> V_31 . V_32 . V_33 ) ;
F_78 ( & V_29 -> V_59 ) ;
V_29 -> V_58 =
F_79 ( & V_84 , V_4 -> V_69 , V_4 -> V_70 ,
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
F_71 ( & V_29 -> V_59 ) ;
return V_29 -> V_58 ;
}
return 0 ;
}
static void F_80 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_29 ;
struct V_42 * V_43 ;
struct V_74 * V_27 ;
unsigned long V_6 ;
V_27 = F_81 ( F_82 ( V_46 ) ) ;
V_43 = F_83 ( V_27 , V_46 -> V_2 ) ;
if ( ! V_43 ) {
++ V_2 -> V_90 . V_91 ;
F_84 ( V_46 ) ;
return;
}
F_35 ( & V_4 -> V_48 , V_6 ) ;
V_29 = F_26 ( V_2 , V_27 -> V_92 + 4 ) ;
if ( ! V_29 ) {
V_29 = F_73 ( V_2 , V_27 -> V_92 + 4 ) ;
if ( ! V_29 )
goto V_93;
F_28 ( V_2 , V_29 ) ;
}
F_31 ( & V_43 -> V_40 , & V_29 -> V_77 ) ;
if ( V_29 -> V_49 ) {
F_65 ( & V_29 -> V_49 -> V_73 ) ;
V_43 -> V_49 = V_29 -> V_49 ;
memcpy ( & V_43 -> V_32 . V_33 , & V_29 -> V_31 . V_32 . V_33 ,
sizeof( union V_34 ) ) ;
if ( F_66 ( V_2 , V_43 -> V_74 ) ) {
if ( ! F_67 ( V_43 ) )
F_68 ( V_43 , F_69 ( V_2 , V_29 , V_43 ) ) ;
if ( ! F_67 ( V_43 ) ) {
F_70 ( & V_43 -> V_40 ) ;
if ( V_43 -> V_49 )
F_37 ( V_43 -> V_49 ) ;
F_38 ( V_2 , V_43 ) ;
goto V_94;
}
if ( F_85 ( & V_43 -> V_47 ) < V_95 )
F_63 ( & V_43 -> V_47 , V_46 ) ;
else {
F_23 ( V_4 , L_12 ,
F_85 ( & V_43 -> V_47 ) ) ;
goto V_94;
}
} else {
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_86 ( V_2 , V_46 , V_29 -> V_49 , F_87 ( V_27 -> V_92 ) ) ;
return;
}
} else {
V_43 -> V_49 = NULL ;
if ( ! V_29 -> V_57 && F_77 ( V_2 , V_29 ) )
goto V_96;
F_63 ( & V_43 -> V_47 , V_46 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
return;
V_96:
F_70 ( & V_43 -> V_40 ) ;
V_93:
F_38 ( V_2 , V_43 ) ;
V_94:
++ V_2 -> V_90 . V_91 ;
F_84 ( V_46 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
}
static void F_88 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_46 -> V_2 ) ;
struct V_97 * V_98 = F_82 ( V_46 ) ;
struct V_74 * V_27 ;
V_27 = F_81 ( V_98 ) ;
if ( V_27 -> V_92 [ 4 ] != 0xff ) {
F_80 ( V_46 , V_2 ) ;
return;
}
V_27 -> V_92 [ 8 ] = ( V_4 -> V_80 >> 8 ) & 0xff ;
V_27 -> V_92 [ 9 ] = V_4 -> V_80 & 0xff ;
F_89 ( V_2 , V_27 -> V_92 + 4 , V_46 ) ;
}
static void F_90 ( struct V_45 * V_46 , struct V_1 * V_2 ,
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
V_29 = F_73 ( V_2 , V_100 -> V_101 + 4 ) ;
V_102 = 1 ;
}
if ( V_29 ) {
F_91 ( V_46 , sizeof *V_100 ) ;
F_63 ( & V_29 -> V_47 , V_46 ) ;
if ( ! V_29 -> V_57 && F_77 ( V_2 , V_29 ) ) {
F_39 ( & V_4 -> V_48 , V_6 ) ;
if ( V_102 )
F_32 ( V_2 , V_29 ) ;
return;
} else
F_28 ( V_2 , V_29 ) ;
} else {
++ V_2 -> V_90 . V_91 ;
F_84 ( V_46 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
return;
}
if ( V_29 -> V_49 ) {
F_3 ( V_4 , L_13 ,
F_50 ( V_29 -> V_31 . V_54 ) ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_86 ( V_2 , V_46 , V_29 -> V_49 , F_87 ( V_100 -> V_101 ) ) ;
return;
} else if ( ( V_29 -> V_57 || ! F_77 ( V_2 , V_29 ) ) &&
F_85 ( & V_29 -> V_47 ) < V_95 ) {
F_91 ( V_46 , sizeof *V_100 ) ;
F_63 ( & V_29 -> V_47 , V_46 ) ;
} else {
++ V_2 -> V_90 . V_91 ;
F_84 ( V_46 ) ;
}
F_39 ( & V_4 -> V_48 , V_6 ) ;
}
static int F_92 ( struct V_45 * V_46 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_42 * V_43 ;
struct V_74 * V_27 = NULL ;
unsigned long V_6 ;
if ( F_93 ( F_82 ( V_46 ) ) )
V_27 = F_81 ( F_82 ( V_46 ) ) ;
if ( F_93 ( V_27 ) ) {
if ( F_94 ( ! * F_95 ( V_27 ) ) ) {
F_88 ( V_46 , V_2 ) ;
return V_103 ;
}
V_43 = * F_95 ( V_27 ) ;
if ( F_94 ( ( memcmp ( & V_43 -> V_32 . V_33 ,
V_27 -> V_92 + 4 ,
sizeof( union V_34 ) ) ) ||
( V_43 -> V_2 != V_2 ) ) ) {
F_35 ( & V_4 -> V_48 , V_6 ) ;
if ( V_43 -> V_49 )
F_37 ( V_43 -> V_49 ) ;
F_70 ( & V_43 -> V_40 ) ;
F_38 ( V_2 , V_43 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
F_88 ( V_46 , V_2 ) ;
return V_103 ;
}
if ( F_67 ( V_43 ) ) {
if ( F_96 ( V_43 ) ) {
F_97 ( V_2 , V_46 , F_67 ( V_43 ) ) ;
return V_103 ;
}
} else if ( V_43 -> V_49 ) {
F_86 ( V_2 , V_46 , V_43 -> V_49 , F_87 ( V_27 -> V_92 ) ) ;
return V_103 ;
}
if ( F_85 ( & V_43 -> V_47 ) < V_95 ) {
F_35 ( & V_4 -> V_48 , V_6 ) ;
F_63 ( & V_43 -> V_47 , V_46 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
} else {
++ V_2 -> V_90 . V_91 ;
F_84 ( V_46 ) ;
}
} else {
struct V_99 * V_100 =
(struct V_99 * ) V_46 -> V_104 ;
F_98 ( V_46 , sizeof *V_100 ) ;
if ( V_100 -> V_101 [ 4 ] == 0xff ) {
V_100 -> V_101 [ 8 ] = ( V_4 -> V_80 >> 8 ) & 0xff ;
V_100 -> V_101 [ 9 ] = V_4 -> V_80 & 0xff ;
F_89 ( V_2 , V_100 -> V_101 + 4 , V_46 ) ;
} else {
if ( ( F_99 ( ( V_105 * ) V_46 -> V_104 ) != V_106 ) &&
( F_99 ( ( V_105 * ) V_46 -> V_104 ) != V_107 ) ) {
F_23 ( V_4 , L_14 ,
F_82 ( V_46 ) ? L_15 : L_16 ,
F_99 ( ( V_105 * ) V_46 -> V_104 ) ,
F_87 ( V_100 -> V_101 ) ,
V_100 -> V_101 + 4 ) ;
F_84 ( V_46 ) ;
++ V_2 -> V_90 . V_91 ;
return V_103 ;
}
F_90 ( V_46 , V_2 , V_100 ) ;
}
}
return V_103 ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_23 ( V_4 , L_17 ,
F_101 ( V_108 - V_2 -> V_109 ) ) ;
F_23 ( V_4 , L_18 ,
F_102 ( V_2 ) ,
V_4 -> V_110 , V_4 -> V_111 ) ;
}
static int F_103 ( struct V_45 * V_46 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_112 , const void * V_113 , unsigned V_114 )
{
struct V_115 * V_116 ;
struct V_97 * V_98 ;
struct V_74 * V_27 ;
V_116 = (struct V_115 * ) F_91 ( V_46 , sizeof *V_116 ) ;
V_116 -> V_117 = F_104 ( type ) ;
V_116 -> V_118 = 0 ;
V_98 = F_82 ( V_46 ) ;
V_27 = NULL ;
if ( V_98 )
V_27 = F_81 ( V_98 ) ;
if ( ( ! V_98 || ! V_27 ) && V_112 ) {
struct V_99 * V_100 =
(struct V_99 * ) F_91 ( V_46 , sizeof *V_100 ) ;
memcpy ( V_100 -> V_101 , V_112 , V_119 ) ;
}
return 0 ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_8 ( V_120 , & V_4 -> V_6 ) ) {
F_3 ( V_4 , L_19 ) ;
return;
}
F_106 ( V_121 , & V_4 -> V_122 ) ;
}
static void F_107 ( struct V_74 * V_27 )
{
struct V_42 * V_43 ;
struct V_3 * V_4 = F_2 ( V_27 -> V_2 ) ;
unsigned long V_6 ;
struct V_63 * V_49 = NULL ;
V_43 = * F_95 ( V_27 ) ;
if ( V_43 )
V_4 = F_2 ( V_43 -> V_2 ) ;
else
return;
F_3 ( V_4 ,
L_20 ,
F_87 ( V_27 -> V_92 ) ,
V_27 -> V_92 + 4 ) ;
F_35 ( & V_4 -> V_48 , V_6 ) ;
if ( V_43 -> V_49 )
V_49 = V_43 -> V_49 ;
F_70 ( & V_43 -> V_40 ) ;
F_38 ( V_27 -> V_2 , V_43 ) ;
F_39 ( & V_4 -> V_48 , V_6 ) ;
if ( V_49 )
F_37 ( V_49 ) ;
}
struct V_42 * F_83 ( struct V_74 * V_74 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 ;
V_43 = F_42 ( sizeof *V_43 , V_76 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_74 = V_74 ;
V_43 -> V_2 = V_2 ;
memset ( & V_43 -> V_32 . V_33 , 0 , sizeof ( union V_34 ) ) ;
* F_95 ( V_74 ) = V_43 ;
F_60 ( & V_43 -> V_47 ) ;
F_68 ( V_43 , NULL ) ;
return V_43 ;
}
void F_38 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_45 * V_46 ;
* F_95 ( V_43 -> V_74 ) = NULL ;
while ( ( V_46 = F_33 ( & V_43 -> V_47 ) ) ) {
++ V_2 -> V_90 . V_91 ;
F_84 ( V_46 ) ;
}
if ( F_67 ( V_43 ) )
F_108 ( F_67 ( V_43 ) ) ;
F_40 ( V_43 ) ;
}
static int F_109 ( struct V_1 * V_2 , struct V_123 * V_124 )
{
V_124 -> V_125 = F_107 ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 , struct V_126 * V_69 , int V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_127 = F_74 ( V_128 * sizeof * V_4 -> V_127 ,
V_52 ) ;
if ( ! V_4 -> V_127 ) {
F_111 ( V_129 L_21 ,
V_69 -> V_130 , V_128 ) ;
goto V_131;
}
V_4 -> V_132 = F_112 ( V_133 * sizeof * V_4 -> V_132 ) ;
if ( ! V_4 -> V_132 ) {
F_111 ( V_129 L_22 ,
V_69 -> V_130 , V_133 ) ;
goto V_134;
}
if ( F_113 ( V_2 , V_69 , V_70 ) )
goto V_135;
return 0 ;
V_135:
F_114 ( V_4 -> V_132 ) ;
V_134:
F_40 ( V_4 -> V_127 ) ;
V_131:
return - V_136 ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) , * V_10 , * V_137 ;
F_116 ( V_2 ) ;
F_36 (cpriv, tcpriv, &priv->child_intfs, list) {
F_117 ( V_10 -> V_2 ) ;
F_115 ( V_10 -> V_2 ) ;
F_118 ( V_10 -> V_2 ) ;
}
F_119 ( V_2 ) ;
F_40 ( V_4 -> V_127 ) ;
F_114 ( V_4 -> V_132 ) ;
V_4 -> V_127 = NULL ;
V_4 -> V_132 = NULL ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_2 -> V_138 = & V_139 ;
V_2 -> V_140 = & V_141 ;
F_121 ( V_2 ) ;
F_122 ( V_2 , & V_4 -> V_142 , V_143 , 100 ) ;
V_2 -> V_144 = V_145 ;
V_2 -> V_6 |= V_146 | V_147 ;
V_2 -> V_148 = V_149 + V_119 ;
V_2 -> V_150 = V_119 ;
V_2 -> type = V_151 ;
V_2 -> V_152 = V_133 * 2 ;
V_2 -> V_14 = ( V_153 |
V_154 ) ;
V_2 -> V_155 &= ~ V_156 ;
memcpy ( V_2 -> V_75 , V_157 , V_119 ) ;
F_123 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
F_124 ( & V_4 -> V_48 ) ;
F_125 ( & V_4 -> V_11 ) ;
F_75 ( & V_4 -> V_41 ) ;
F_75 ( & V_4 -> V_158 ) ;
F_75 ( & V_4 -> V_159 ) ;
F_75 ( & V_4 -> V_160 ) ;
F_126 ( & V_4 -> V_161 , V_162 ) ;
F_126 ( & V_4 -> V_163 , V_164 ) ;
F_127 ( & V_4 -> V_165 , V_166 ) ;
F_127 ( & V_4 -> V_167 , V_168 ) ;
F_127 ( & V_4 -> V_169 , V_170 ) ;
F_127 ( & V_4 -> V_171 , V_172 ) ;
F_127 ( & V_4 -> V_122 , V_173 ) ;
F_126 ( & V_4 -> V_174 , V_175 ) ;
}
struct V_3 * F_128 ( const char * V_130 )
{
struct V_1 * V_2 ;
V_2 = F_129 ( ( int ) sizeof ( struct V_3 ) , V_130 ,
F_120 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 ) ;
}
static T_2 F_130 ( struct V_176 * V_2 ,
struct V_177 * V_178 , char * V_179 )
{
struct V_3 * V_4 = F_2 ( F_131 ( V_2 ) ) ;
return sprintf ( V_179 , L_23 , V_4 -> V_80 ) ;
}
static T_2 F_132 ( struct V_176 * V_2 ,
struct V_177 * V_178 , char * V_179 )
{
struct V_3 * V_4 = F_2 ( F_131 ( V_2 ) ) ;
return sprintf ( V_179 , L_24 , F_8 ( V_180 , & V_4 -> V_6 ) ) ;
}
static T_2 F_133 ( struct V_176 * V_2 ,
struct V_177 * V_178 ,
const char * V_179 , T_3 V_181 )
{
struct V_3 * V_4 = F_2 ( F_131 ( V_2 ) ) ;
unsigned long V_182 = F_134 ( V_179 , NULL , 0 ) ;
if ( V_182 > 0 ) {
F_4 ( V_180 , & V_4 -> V_6 ) ;
F_23 ( V_4 , L_25
L_26 ) ;
} else
F_15 ( V_180 , & V_4 -> V_6 ) ;
return V_181 ;
}
int F_135 ( struct V_1 * V_2 )
{
return F_136 ( & V_2 -> V_2 , & V_183 ) ;
}
static T_2 F_137 ( struct V_176 * V_2 ,
struct V_177 * V_178 ,
const char * V_179 , T_3 V_181 )
{
int V_80 ;
int V_30 ;
if ( sscanf ( V_179 , L_27 , & V_80 ) != 1 )
return - V_13 ;
if ( V_80 < 0 || V_80 > 0xffff )
return - V_13 ;
V_80 |= 0x8000 ;
V_30 = F_138 ( F_131 ( V_2 ) , V_80 ) ;
return V_30 ? V_30 : V_181 ;
}
static T_2 F_139 ( struct V_176 * V_2 ,
struct V_177 * V_178 ,
const char * V_179 , T_3 V_181 )
{
int V_80 ;
int V_30 ;
if ( sscanf ( V_179 , L_27 , & V_80 ) != 1 )
return - V_13 ;
if ( V_80 < 0 || V_80 > 0xffff )
return - V_13 ;
V_30 = F_140 ( F_131 ( V_2 ) , V_80 ) ;
return V_30 ? V_30 : V_181 ;
}
int F_141 ( struct V_1 * V_2 )
{
return F_136 ( & V_2 -> V_2 , & V_184 ) ;
}
int F_142 ( struct V_3 * V_4 , struct V_126 * V_185 )
{
struct V_186 * V_187 ;
int V_188 = - V_136 ;
V_187 = F_42 ( sizeof *V_187 , V_52 ) ;
if ( ! V_187 ) {
F_111 ( V_129 L_28 ,
V_185 -> V_130 , sizeof *V_187 ) ;
return V_188 ;
}
V_188 = F_143 ( V_185 , V_187 ) ;
if ( V_188 ) {
F_111 ( V_129 L_29 ,
V_185 -> V_130 , V_188 ) ;
F_40 ( V_187 ) ;
return V_188 ;
}
V_4 -> V_189 = V_187 -> V_190 ;
F_40 ( V_187 ) ;
if ( V_4 -> V_189 & V_191 ) {
V_4 -> V_2 -> V_192 = V_16 |
V_17 | V_193 ;
if ( V_4 -> V_189 & V_194 )
V_4 -> V_2 -> V_192 |= V_18 ;
V_4 -> V_2 -> V_14 |= V_4 -> V_2 -> V_192 ;
}
return 0 ;
}
static struct V_1 * F_144 ( const char * V_195 ,
struct V_126 * V_185 , T_4 V_70 )
{
struct V_3 * V_4 ;
struct V_196 V_178 ;
int V_188 = - V_136 ;
V_4 = F_128 ( V_195 ) ;
if ( ! V_4 )
goto V_197;
F_145 ( V_4 -> V_2 , V_185 -> V_198 ) ;
V_4 -> V_2 -> V_199 = V_70 - 1 ;
if ( ! F_146 ( V_185 , V_70 , & V_178 ) )
V_4 -> V_22 = F_147 ( V_178 . V_200 ) ;
else {
F_111 ( V_129 L_30 ,
V_185 -> V_130 , V_70 ) ;
goto V_201;
}
V_4 -> V_2 -> V_21 = F_24 ( V_4 -> V_22 ) ;
V_4 -> V_20 = V_4 -> V_23 = V_4 -> V_2 -> V_21 ;
V_188 = F_148 ( V_185 , V_70 , 0 , & V_4 -> V_80 ) ;
if ( V_188 ) {
F_111 ( V_129 L_31 ,
V_185 -> V_130 , V_70 , V_188 ) ;
goto V_201;
}
if ( F_142 ( V_4 , V_185 ) )
goto V_201;
V_4 -> V_80 |= 0x8000 ;
V_4 -> V_2 -> V_75 [ 8 ] = V_4 -> V_80 >> 8 ;
V_4 -> V_2 -> V_75 [ 9 ] = V_4 -> V_80 & 0xff ;
V_188 = F_149 ( V_185 , V_70 , 0 , & V_4 -> V_79 ) ;
if ( V_188 ) {
F_111 ( V_129 L_32 ,
V_185 -> V_130 , V_70 , V_188 ) ;
goto V_201;
} else
memcpy ( V_4 -> V_2 -> V_202 + 4 , V_4 -> V_79 . V_33 , sizeof ( union V_34 ) ) ;
V_188 = F_110 ( V_4 -> V_2 , V_185 , V_70 ) ;
if ( V_188 < 0 ) {
F_111 ( V_129 L_33 ,
V_185 -> V_130 , V_70 , V_188 ) ;
goto V_201;
}
F_150 ( & V_4 -> V_203 ,
V_4 -> V_69 , V_204 ) ;
V_188 = F_151 ( & V_4 -> V_203 ) ;
if ( V_188 < 0 ) {
F_111 ( V_129 L_34
L_35 ,
V_185 -> V_130 , V_70 , V_188 ) ;
goto V_205;
}
V_188 = F_152 ( V_4 -> V_2 ) ;
if ( V_188 ) {
F_111 ( V_129 L_36 ,
V_185 -> V_130 , V_70 , V_188 ) ;
goto V_206;
}
F_153 ( V_4 -> V_2 ) ;
if ( F_154 ( V_4 -> V_2 ) )
goto V_207;
if ( F_141 ( V_4 -> V_2 ) )
goto V_207;
if ( F_135 ( V_4 -> V_2 ) )
goto V_207;
if ( F_136 ( & V_4 -> V_2 -> V_2 , & V_208 ) )
goto V_207;
if ( F_136 ( & V_4 -> V_2 -> V_2 , & V_209 ) )
goto V_207;
return V_4 -> V_2 ;
V_207:
F_116 ( V_4 -> V_2 ) ;
F_117 ( V_4 -> V_2 ) ;
V_206:
F_155 ( & V_4 -> V_203 ) ;
F_156 ( V_121 ) ;
V_205:
F_115 ( V_4 -> V_2 ) ;
V_201:
F_118 ( V_4 -> V_2 ) ;
V_197:
return F_157 ( V_188 ) ;
}
static void F_158 ( struct V_126 * V_176 )
{
struct V_210 * V_211 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_212 , V_213 , V_214 ;
if ( F_159 ( V_176 -> V_215 ) != V_216 )
return;
V_211 = F_42 ( sizeof *V_211 , V_52 ) ;
if ( ! V_211 )
return;
F_75 ( V_211 ) ;
if ( V_176 -> V_215 == V_217 ) {
V_212 = 0 ;
V_213 = 0 ;
} else {
V_212 = 1 ;
V_213 = V_176 -> V_218 ;
}
for ( V_214 = V_212 ; V_214 <= V_213 ; ++ V_214 ) {
if ( F_160 ( V_176 , V_214 ) != V_219 )
continue;
V_2 = F_144 ( L_37 , V_176 , V_214 ) ;
if ( ! F_161 ( V_2 ) ) {
V_4 = F_2 ( V_2 ) ;
F_31 ( & V_4 -> V_40 , V_211 ) ;
}
}
F_162 ( V_176 , & V_220 , V_211 ) ;
}
static void F_163 ( struct V_126 * V_176 )
{
struct V_3 * V_4 , * V_221 ;
struct V_210 * V_211 ;
if ( F_159 ( V_176 -> V_215 ) != V_216 )
return;
V_211 = F_164 ( V_176 , & V_220 ) ;
F_36 (priv, tmp, dev_list, list) {
F_155 ( & V_4 -> V_203 ) ;
F_165 () ;
F_11 ( V_4 -> V_2 , V_4 -> V_2 -> V_6 & ~ V_12 ) ;
F_166 () ;
F_156 ( V_121 ) ;
F_117 ( V_4 -> V_2 ) ;
F_115 ( V_4 -> V_2 ) ;
F_118 ( V_4 -> V_2 ) ;
}
F_40 ( V_211 ) ;
}
static int T_5 F_167 ( void )
{
int V_30 ;
V_128 = F_168 ( V_128 ) ;
V_128 = F_25 ( V_128 , V_222 ) ;
V_128 = F_169 ( V_128 , V_223 ) ;
V_133 = F_168 ( V_133 ) ;
V_133 = F_25 ( V_133 , V_222 ) ;
V_133 = F_170 ( V_133 , 2 * V_224 , V_223 ) ;
#ifdef F_171
V_225 = F_25 ( V_225 , V_226 ) ;
#endif
F_172 ( V_227 > V_228 ) ;
V_30 = F_173 () ;
if ( V_30 )
return V_30 ;
V_121 = F_174 ( L_38 ) ;
if ( ! V_121 ) {
V_30 = - V_136 ;
goto V_229;
}
F_175 ( & V_84 ) ;
V_30 = F_176 ( & V_220 ) ;
if ( V_30 )
goto V_230;
return 0 ;
V_230:
F_177 ( & V_84 ) ;
F_178 ( V_121 ) ;
V_229:
F_179 () ;
return V_30 ;
}
static void T_6 F_180 ( void )
{
F_181 ( & V_220 ) ;
F_177 ( & V_84 ) ;
F_179 () ;
F_178 ( V_121 ) ;
}
