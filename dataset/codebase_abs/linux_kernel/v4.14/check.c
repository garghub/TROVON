struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned long V_6 )
{
struct V_1 * V_7 ;
F_2 (file->insn_hash, insn, hash, offset)
if ( V_7 -> V_5 == V_5 && V_7 -> V_6 == V_6 )
return V_7 ;
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
struct V_1 * V_8 = F_4 ( V_7 , V_9 ) ;
if ( ! V_8 || & V_8 -> V_9 == & V_3 -> V_10 || V_8 -> V_5 != V_7 -> V_5 )
return NULL ;
return V_8 ;
}
static bool F_5 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
struct V_13 * V_13 ;
if ( V_3 -> V_14 && V_3 -> V_14 -> V_13 )
F_6 (rela, &file->whitelist->rela->rela_list, list) {
if ( V_13 -> V_15 -> type == V_16 &&
V_13 -> V_15 -> V_5 == V_12 -> V_5 &&
V_13 -> V_17 == V_12 -> V_6 )
return true ;
if ( V_13 -> V_15 -> type == V_18 && V_13 -> V_15 == V_12 )
return true ;
}
return false ;
}
static int F_7 ( struct V_2 * V_3 , struct V_11 * V_12 ,
int V_19 )
{
int V_20 ;
struct V_1 * V_7 ;
bool V_21 = true ;
static const char * const V_22 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
} ;
if ( V_12 -> V_23 == V_24 )
return 0 ;
if ( V_12 -> V_23 == V_25 )
for ( V_20 = 0 ; V_20 < F_8 ( V_22 ) ; V_20 ++ )
if ( ! strcmp ( V_12 -> V_26 , V_22 [ V_20 ] ) )
return 1 ;
if ( ! V_12 -> V_5 )
return 0 ;
F_9 (file, func, insn) {
V_21 = false ;
if ( V_7 -> type == V_27 )
return 0 ;
}
if ( V_21 )
return 0 ;
F_9 (file, func, insn) {
if ( V_7 -> V_5 != V_12 -> V_5 ||
V_7 -> V_6 >= V_12 -> V_6 + V_12 -> V_28 )
break;
if ( V_7 -> type == V_29 ) {
struct V_1 * V_30 = V_7 -> V_31 ;
struct V_11 * V_32 ;
if ( ! V_30 )
return 0 ;
if ( V_30 -> V_5 != V_12 -> V_5 ||
V_30 -> V_6 < V_12 -> V_6 ||
V_30 -> V_6 >= V_12 -> V_6 + V_12 -> V_28 ) {
V_32 = F_10 ( V_30 -> V_5 ,
V_30 -> V_6 ) ;
if ( ! V_32 )
continue;
if ( V_19 == 5 ) {
F_11 ( L_11 ,
V_30 -> V_5 , V_30 -> V_6 ) ;
return - 1 ;
}
return F_7 ( V_3 , V_32 ,
V_19 + 1 ) ;
}
}
if ( V_7 -> type == V_33 && F_12 ( & V_7 -> V_34 ) )
return 0 ;
}
return 1 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
return F_7 ( V_3 , V_12 , 0 ) ;
}
static void F_14 ( struct V_35 * V_36 )
{
int V_20 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_37 . V_38 = V_39 ;
for ( V_20 = 0 ; V_20 < V_40 ; V_20 ++ ) {
V_36 -> V_41 [ V_20 ] . V_38 = V_39 ;
V_36 -> V_42 [ V_20 ] . V_38 = V_39 ;
}
V_36 -> V_43 = V_39 ;
V_36 -> V_44 = - 1 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
unsigned long V_6 ;
struct V_1 * V_7 ;
int V_45 ;
F_16 (file, sec) {
if ( ! ( V_5 -> V_46 . V_47 & V_48 ) )
continue;
if ( strcmp ( V_5 -> V_26 , L_12 ) &&
strcmp ( V_5 -> V_26 , L_13 ) &&
strncmp ( V_5 -> V_26 , L_14 , 9 ) )
V_5 -> V_49 = true ;
for ( V_6 = 0 ; V_6 < V_5 -> V_28 ; V_6 += V_7 -> V_28 ) {
V_7 = malloc ( sizeof( * V_7 ) ) ;
if ( ! V_7 ) {
F_17 ( L_15 ) ;
return - 1 ;
}
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_18 ( & V_7 -> V_34 ) ;
F_14 ( & V_7 -> V_36 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
V_45 = F_19 ( V_3 -> V_50 , V_5 , V_6 ,
V_5 -> V_28 - V_6 ,
& V_7 -> V_28 , & V_7 -> type ,
& V_7 -> V_51 ,
& V_7 -> V_52 ) ;
if ( V_45 )
goto V_53;
if ( ! V_7 -> type || V_7 -> type > V_54 ) {
F_11 ( L_16 ,
V_7 -> V_5 , V_7 -> V_6 , V_7 -> type ) ;
V_45 = - 1 ;
goto V_53;
}
F_20 ( V_3 -> V_55 , & V_7 -> V_56 , V_7 -> V_6 ) ;
F_21 ( & V_7 -> V_9 , & V_3 -> V_10 ) ;
}
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
if ( ! F_1 ( V_3 , V_5 , V_12 -> V_6 ) ) {
F_17 ( L_17 ,
V_12 -> V_26 ) ;
return - 1 ;
}
F_9 (file, func, insn)
if ( ! V_7 -> V_12 )
V_7 -> V_12 = V_12 ;
}
}
return 0 ;
V_53:
free ( V_7 ) ;
return V_45 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_13 * V_13 ;
struct V_1 * V_7 ;
bool V_57 ;
F_23 (file, insn)
if ( V_7 -> type == V_58 )
V_7 -> V_59 = true ;
V_5 = F_24 ( V_3 -> V_50 , L_18 ) ;
if ( ! V_5 )
goto V_60;
F_6 (rela, &sec->rela_list, list) {
if ( V_13 -> V_15 -> type != V_16 ) {
F_17 ( L_19 , V_5 -> V_26 ) ;
return - 1 ;
}
V_7 = F_1 ( V_3 , V_13 -> V_15 -> V_5 , V_13 -> V_17 ) ;
if ( V_7 )
V_7 = F_25 ( V_7 , V_9 ) ;
else if ( V_13 -> V_17 == V_13 -> V_15 -> V_5 -> V_28 ) {
V_57 = false ;
F_26 (insn, &file->insn_list, list) {
if ( V_7 -> V_5 == V_13 -> V_15 -> V_5 ) {
V_57 = true ;
break;
}
}
if ( ! V_57 ) {
F_17 ( L_20 ,
V_13 -> V_15 -> V_5 -> V_26 , V_13 -> V_17 ) ;
return - 1 ;
}
} else {
F_17 ( L_20 ,
V_13 -> V_15 -> V_5 -> V_26 , V_13 -> V_17 ) ;
return - 1 ;
}
V_7 -> V_59 = true ;
}
V_60:
V_5 = F_24 ( V_3 -> V_50 , L_21 ) ;
if ( ! V_5 )
return 0 ;
F_6 (rela, &sec->rela_list, list) {
if ( V_13 -> V_15 -> type != V_16 ) {
F_17 ( L_19 , V_5 -> V_26 ) ;
return - 1 ;
}
V_7 = F_1 ( V_3 , V_13 -> V_15 -> V_5 , V_13 -> V_17 ) ;
if ( V_7 )
V_7 = F_25 ( V_7 , V_9 ) ;
else if ( V_13 -> V_17 == V_13 -> V_15 -> V_5 -> V_28 ) {
V_57 = false ;
F_26 (insn, &file->insn_list, list) {
if ( V_7 -> V_5 == V_13 -> V_15 -> V_5 ) {
V_57 = true ;
break;
}
}
if ( ! V_57 ) {
F_17 ( L_22 ,
V_13 -> V_15 -> V_5 -> V_26 , V_13 -> V_17 ) ;
return - 1 ;
}
} else {
F_17 ( L_22 ,
V_13 -> V_15 -> V_5 -> V_26 , V_13 -> V_17 ) ;
return - 1 ;
}
V_7 -> V_59 = false ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
F_16 (file, sec) {
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
if ( ! F_5 ( V_3 , V_12 ) )
continue;
F_9 (file, func, insn)
V_7 -> V_61 = true ;
}
}
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_13 * V_13 ;
struct V_4 * V_62 ;
unsigned long V_63 ;
F_23 (file, insn) {
if ( V_7 -> type != V_64 &&
V_7 -> type != V_29 )
continue;
if ( V_7 -> V_61 )
continue;
V_13 = F_29 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_28 ) ;
if ( ! V_13 ) {
V_62 = V_7 -> V_5 ;
V_63 = V_7 -> V_6 + V_7 -> V_28 + V_7 -> V_51 ;
} else if ( V_13 -> V_15 -> type == V_16 ) {
V_62 = V_13 -> V_15 -> V_5 ;
V_63 = V_13 -> V_17 + 4 ;
} else if ( V_13 -> V_15 -> V_5 -> V_65 ) {
V_62 = V_13 -> V_15 -> V_5 ;
V_63 = V_13 -> V_15 -> V_15 . V_66 + V_13 -> V_17 + 4 ;
} else {
V_7 -> V_31 = 0 ;
continue;
}
V_7 -> V_31 = F_1 ( V_3 , V_62 , V_63 ) ;
if ( ! V_7 -> V_31 ) {
if ( ! strcmp ( V_7 -> V_5 -> V_26 , L_12 ) )
continue;
F_11 ( L_23 ,
V_7 -> V_5 , V_7 -> V_6 , V_62 -> V_26 ,
V_63 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
unsigned long V_63 ;
struct V_13 * V_13 ;
F_23 (file, insn) {
if ( V_7 -> type != V_67 )
continue;
V_13 = F_29 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_28 ) ;
if ( ! V_13 ) {
V_63 = V_7 -> V_6 + V_7 -> V_28 + V_7 -> V_51 ;
V_7 -> V_68 = F_10 ( V_7 -> V_5 ,
V_63 ) ;
if ( ! V_7 -> V_68 ) {
F_11 ( L_24 ,
V_7 -> V_5 , V_7 -> V_6 , V_63 ) ;
return - 1 ;
}
} else if ( V_13 -> V_15 -> type == V_16 ) {
V_7 -> V_68 = F_10 ( V_13 -> V_15 -> V_5 ,
V_13 -> V_17 + 4 ) ;
if ( ! V_7 -> V_68 ||
V_7 -> V_68 -> type != V_18 ) {
F_11 ( L_25 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_13 -> V_15 -> V_5 -> V_26 ,
V_13 -> V_17 + 4 ) ;
return - 1 ;
}
} else
V_7 -> V_68 = V_13 -> V_15 ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_69 * V_69 ,
struct V_1 * V_70 ,
struct V_1 * * V_71 )
{
struct V_1 * V_72 , * V_73 , * V_7 , * V_74 ;
unsigned long V_63 ;
V_72 = NULL ;
V_7 = V_70 ;
F_32 (file, insn) {
if ( V_7 -> V_6 >= V_69 -> V_75 + V_69 -> V_76 )
break;
if ( V_69 -> V_77 )
V_7 -> type = V_78 ;
V_7 -> V_79 = true ;
V_72 = V_7 ;
}
if ( ! F_3 ( V_3 , V_72 ) ) {
F_17 ( L_26 ,
V_69 -> V_80 -> V_26 ) ;
return - 1 ;
}
V_74 = malloc ( sizeof( * V_74 ) ) ;
if ( ! V_74 ) {
F_17 ( L_15 ) ;
return - 1 ;
}
memset ( V_74 , 0 , sizeof( * V_74 ) ) ;
F_18 ( & V_74 -> V_34 ) ;
F_14 ( & V_74 -> V_36 ) ;
V_74 -> V_5 = V_69 -> V_81 ;
V_74 -> V_6 = - 1 ;
V_74 -> type = V_29 ;
V_74 -> V_31 = F_4 ( V_72 , V_9 ) ;
V_74 -> V_61 = true ;
if ( ! V_69 -> V_82 ) {
* V_71 = V_74 ;
return 0 ;
}
V_73 = NULL ;
V_7 = * V_71 ;
F_32 (file, insn) {
if ( V_7 -> V_6 >= V_69 -> V_83 + V_69 -> V_82 )
break;
V_73 = V_7 ;
if ( V_7 -> type != V_64 &&
V_7 -> type != V_29 )
continue;
if ( ! V_7 -> V_51 )
continue;
V_63 = V_7 -> V_6 + V_7 -> V_28 + V_7 -> V_51 ;
if ( V_63 == V_69 -> V_83 + V_69 -> V_82 )
V_7 -> V_31 = V_74 ;
if ( ! V_7 -> V_31 ) {
F_11 ( L_27 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
}
if ( ! V_73 ) {
F_11 ( L_28 ,
V_69 -> V_81 , V_69 -> V_83 ) ;
return - 1 ;
}
F_33 ( & V_74 -> V_9 , & V_73 -> V_9 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_69 * V_69 ,
struct V_1 * V_70 ,
struct V_1 * * V_71 )
{
if ( V_70 -> type == V_78 )
return 0 ;
if ( V_70 -> type != V_29 ) {
F_11 ( L_29 ,
V_70 -> V_5 , V_70 -> V_6 ) ;
return - 1 ;
}
* V_71 = F_4 ( V_70 , V_9 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_84 V_85 ;
struct V_1 * V_70 , * V_71 ;
struct V_69 * V_69 , * V_86 ;
struct V_87 * V_88 ;
int V_45 ;
V_45 = F_36 ( V_3 -> V_50 , & V_85 ) ;
if ( V_45 )
return V_45 ;
F_37 (special_alt, tmp, &special_alts, list) {
V_88 = malloc ( sizeof( * V_88 ) ) ;
if ( ! V_88 ) {
F_17 ( L_15 ) ;
V_45 = - 1 ;
goto V_89;
}
V_70 = F_1 ( V_3 , V_69 -> V_80 ,
V_69 -> V_75 ) ;
if ( ! V_70 ) {
F_11 ( L_30 ,
V_69 -> V_80 , V_69 -> V_75 ) ;
V_45 = - 1 ;
goto V_89;
}
V_71 = NULL ;
if ( ! V_69 -> V_90 || V_69 -> V_82 ) {
V_71 = F_1 ( V_3 , V_69 -> V_81 ,
V_69 -> V_83 ) ;
if ( ! V_71 ) {
F_11 ( L_31 ,
V_69 -> V_81 ,
V_69 -> V_83 ) ;
V_45 = - 1 ;
goto V_89;
}
}
if ( V_69 -> V_90 ) {
V_45 = F_31 ( V_3 , V_69 , V_70 ,
& V_71 ) ;
if ( V_45 )
goto V_89;
} else if ( V_69 -> V_91 ) {
V_45 = F_34 ( V_3 , V_69 , V_70 ,
& V_71 ) ;
if ( V_45 )
goto V_89;
}
V_88 -> V_7 = V_71 ;
F_21 ( & V_88 -> V_9 , & V_70 -> V_34 ) ;
F_38 ( & V_69 -> V_9 ) ;
free ( V_69 ) ;
}
V_89:
return V_45 ;
}
static int F_39 ( struct V_2 * V_3 , struct V_11 * V_12 ,
struct V_1 * V_7 , struct V_13 * V_92 ,
struct V_13 * V_93 )
{
struct V_13 * V_13 = V_92 ;
struct V_1 * V_94 ;
struct V_87 * V_88 ;
F_40 (rela, &file->rodata->rela->rela_list, list) {
if ( V_13 == V_93 )
break;
if ( V_13 -> V_15 -> V_5 != V_7 -> V_5 ||
V_13 -> V_17 <= V_12 -> V_6 ||
V_13 -> V_17 >= V_12 -> V_6 + V_12 -> V_28 )
break;
V_94 = F_1 ( V_3 , V_7 -> V_5 , V_13 -> V_17 ) ;
if ( ! V_94 ) {
F_17 ( L_32 ,
V_3 -> V_95 -> V_13 -> V_26 , V_7 -> V_5 -> V_26 ,
V_13 -> V_17 ) ;
return - 1 ;
}
V_88 = malloc ( sizeof( * V_88 ) ) ;
if ( ! V_88 ) {
F_17 ( L_15 ) ;
return - 1 ;
}
V_88 -> V_7 = V_94 ;
F_21 ( & V_88 -> V_9 , & V_7 -> V_34 ) ;
}
return 0 ;
}
static struct V_13 * F_41 ( struct V_2 * V_3 ,
struct V_11 * V_12 ,
struct V_1 * V_7 )
{
struct V_13 * V_96 , * V_97 ;
struct V_1 * V_70 = V_7 ;
V_96 = F_29 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_28 ) ;
if ( V_96 && V_96 -> V_15 == V_3 -> V_95 -> V_15 ) {
V_97 = F_42 ( V_3 -> V_95 ,
V_96 -> V_17 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_42 ( V_3 -> V_95 ,
V_96 -> V_17 + 4 ) ;
if ( ! V_97 )
return NULL ;
V_3 -> V_98 = true ;
return V_97 ;
}
F_43 (file, func, insn) {
if ( V_7 -> type == V_33 )
break;
if ( V_7 -> type == V_29 &&
V_7 -> V_31 &&
( V_7 -> V_31 -> V_6 <= V_7 -> V_6 ||
V_7 -> V_31 -> V_6 > V_70 -> V_6 ) )
break;
V_96 = F_29 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_28 ) ;
if ( ! V_96 || V_96 -> V_15 != V_3 -> V_95 -> V_15 )
continue;
if ( F_44 ( V_3 -> V_95 , V_96 -> V_17 ) )
continue;
return F_42 ( V_3 -> V_95 , V_96 -> V_17 ) ;
}
return NULL ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_7 , * V_99 = NULL ;
struct V_13 * V_13 , * V_100 = NULL ;
int V_45 ;
F_9 (file, func, insn) {
if ( V_7 -> type != V_33 )
continue;
V_13 = F_41 ( V_3 , V_12 , V_7 ) ;
if ( ! V_13 )
continue;
if ( V_99 ) {
V_45 = F_39 ( V_3 , V_12 , V_99 , V_100 ,
V_13 ) ;
if ( V_45 )
return V_45 ;
}
V_99 = V_7 ;
V_100 = V_13 ;
}
if ( V_99 ) {
V_45 = F_39 ( V_3 , V_12 , V_99 , V_100 , NULL ) ;
if ( V_45 )
return V_45 ;
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
int V_45 ;
if ( ! V_3 -> V_95 || ! V_3 -> V_95 -> V_13 )
return 0 ;
F_16 (file, sec) {
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
V_45 = F_45 ( V_3 , V_12 ) ;
if ( V_45 )
return V_45 ;
}
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_4 * V_5 , * V_101 ;
struct V_13 * V_13 ;
struct V_102 * V_103 ;
struct V_1 * V_7 ;
struct V_104 * V_37 ;
int V_20 ;
V_5 = F_24 ( V_3 -> V_50 , L_33 ) ;
if ( ! V_5 )
return 0 ;
V_101 = V_5 -> V_13 ;
if ( ! V_101 ) {
F_17 ( L_34 ) ;
return - 1 ;
}
if ( V_5 -> V_28 % sizeof( struct V_102 ) ) {
F_17 ( L_35 ) ;
return - 1 ;
}
V_3 -> V_105 = true ;
for ( V_20 = 0 ; V_20 < V_5 -> V_28 / sizeof( struct V_102 ) ; V_20 ++ ) {
V_103 = (struct V_102 * ) V_5 -> V_106 -> V_107 + V_20 ;
V_13 = F_42 ( V_5 , V_20 * sizeof( * V_103 ) ) ;
if ( ! V_13 ) {
F_17 ( L_36 , V_20 ) ;
return - 1 ;
}
V_7 = F_1 ( V_3 , V_13 -> V_15 -> V_5 , V_13 -> V_17 ) ;
if ( ! V_7 ) {
F_17 ( L_37 , V_20 ) ;
return - 1 ;
}
V_37 = & V_7 -> V_36 . V_37 ;
if ( V_103 -> type == V_108 ) {
V_7 -> V_109 = true ;
continue;
} else if ( V_103 -> type == V_110 ) {
V_7 -> V_111 = true ;
V_7 -> V_103 = true ;
continue;
}
V_7 -> V_103 = true ;
switch ( V_103 -> V_112 ) {
case V_113 :
V_37 -> V_38 = V_39 ;
break;
case V_114 :
V_37 -> V_38 = V_115 ;
break;
case V_116 :
V_37 -> V_38 = V_117 ;
break;
case V_118 :
V_37 -> V_38 = V_119 ;
break;
case V_120 :
V_37 -> V_38 = V_121 ;
break;
case V_122 :
V_37 -> V_38 = V_123 ;
break;
case V_124 :
V_37 -> V_38 = V_125 ;
break;
case V_126 :
V_37 -> V_38 = V_127 ;
break;
default:
F_11 ( L_38 ,
V_7 -> V_5 , V_7 -> V_6 , V_103 -> V_112 ) ;
return - 1 ;
}
V_37 -> V_6 = V_103 -> V_128 ;
V_7 -> V_36 . type = V_103 -> type ;
}
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
int V_45 ;
V_45 = F_15 ( V_3 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_22 ( V_3 ) ;
if ( V_45 )
return V_45 ;
F_27 ( V_3 ) ;
V_45 = F_28 ( V_3 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_30 ( V_3 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_35 ( V_3 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_46 ( V_3 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_47 ( V_3 ) ;
if ( V_45 )
return V_45 ;
return 0 ;
}
static bool F_49 ( struct V_1 * V_7 )
{
if ( V_7 -> type == V_67 &&
V_7 -> V_68 -> type == V_129 &&
! strcmp ( V_7 -> V_68 -> V_26 , L_39 ) )
return true ;
return false ;
}
static bool F_50 ( struct V_35 * V_36 )
{
int V_20 ;
if ( V_36 -> V_37 . V_38 != V_130 . V_37 . V_38 ||
V_36 -> V_37 . V_6 != V_130 . V_37 . V_6 ||
V_36 -> V_131 != V_130 . V_37 . V_6 ||
V_36 -> V_132 )
return true ;
for ( V_20 = 0 ; V_20 < V_40 ; V_20 ++ )
if ( V_36 -> V_41 [ V_20 ] . V_38 != V_130 . V_41 [ V_20 ] . V_38 ||
V_36 -> V_41 [ V_20 ] . V_6 != V_130 . V_41 [ V_20 ] . V_6 )
return true ;
return false ;
}
static bool F_51 ( struct V_35 * V_36 )
{
if ( V_36 -> V_37 . V_38 == V_117 && V_36 -> V_41 [ V_117 ] . V_38 == V_133 &&
V_36 -> V_41 [ V_117 ] . V_6 == - 16 )
return true ;
if ( V_36 -> V_132 && V_36 -> V_41 [ V_117 ] . V_38 == V_117 )
return true ;
return false ;
}
static int F_52 ( struct V_1 * V_7 , struct V_35 * V_36 )
{
struct V_104 * V_37 = & V_36 -> V_37 ;
struct V_52 * V_134 = & V_7 -> V_52 ;
if ( V_37 -> V_38 != V_115 )
return 0 ;
if ( V_134 -> V_30 . type == V_135 )
V_37 -> V_6 += 8 ;
if ( V_134 -> V_136 . type == V_137 )
V_37 -> V_6 -= 8 ;
if ( V_134 -> V_30 . type == V_138 && V_134 -> V_136 . type == V_139 &&
V_134 -> V_30 . V_140 == V_115 && V_134 -> V_136 . V_140 == V_115 )
V_37 -> V_6 -= V_134 -> V_136 . V_6 ;
return 0 ;
}
static void F_53 ( struct V_35 * V_36 , unsigned char V_140 , int V_38 ,
int V_6 )
{
if ( F_54 ( V_140 ) &&
V_36 -> V_41 [ V_140 ] . V_38 == V_39 ) {
V_36 -> V_41 [ V_140 ] . V_38 = V_38 ;
V_36 -> V_41 [ V_140 ] . V_6 = V_6 ;
}
}
static void F_55 ( struct V_35 * V_36 , unsigned char V_140 )
{
V_36 -> V_41 [ V_140 ] . V_38 = V_39 ;
V_36 -> V_41 [ V_140 ] . V_6 = 0 ;
}
static int F_56 ( struct V_1 * V_7 , struct V_35 * V_36 )
{
struct V_52 * V_134 = & V_7 -> V_52 ;
struct V_104 * V_37 = & V_36 -> V_37 ;
struct V_104 * V_41 = V_36 -> V_41 ;
if ( V_37 -> V_38 == V_39 ) {
if ( V_7 -> V_12 ) {
F_11 ( L_40 , V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
return 0 ;
}
if ( V_36 -> type == V_141 || V_36 -> type == V_142 )
return F_52 ( V_7 , V_36 ) ;
switch ( V_134 -> V_30 . type ) {
case V_138 :
switch ( V_134 -> V_136 . type ) {
case V_143 :
if ( V_134 -> V_136 . V_140 == V_115 && V_134 -> V_30 . V_140 == V_117 &&
V_37 -> V_38 == V_115 &&
V_41 [ V_117 ] . V_38 == V_133 &&
V_41 [ V_117 ] . V_6 == - V_37 -> V_6 ) {
V_37 -> V_38 = V_134 -> V_30 . V_140 ;
V_36 -> V_144 = false ;
}
else if ( V_134 -> V_136 . V_140 == V_115 &&
V_134 -> V_30 . V_140 == V_117 && V_36 -> V_132 ) {
V_41 [ V_117 ] . V_38 = V_117 ;
V_41 [ V_117 ] . V_6 = - V_36 -> V_131 ;
V_36 -> V_144 = false ;
}
else if ( V_134 -> V_136 . V_140 == V_115 && V_37 -> V_38 == V_115 ) {
V_36 -> V_42 [ V_134 -> V_30 . V_140 ] . V_38 = V_133 ;
V_36 -> V_42 [ V_134 -> V_30 . V_140 ] . V_6 = - V_36 -> V_131 ;
}
else if ( V_134 -> V_30 . V_140 == V_37 -> V_38 ) {
if ( V_37 -> V_38 == V_115 &&
V_36 -> V_42 [ V_134 -> V_136 . V_140 ] . V_38 == V_133 ) {
V_37 -> V_6 = - V_36 -> V_42 [ V_134 -> V_136 . V_140 ] . V_6 ;
V_36 -> V_131 = V_37 -> V_6 ;
} else {
V_37 -> V_38 = V_39 ;
V_37 -> V_6 = 0 ;
}
}
break;
case V_139 :
if ( V_134 -> V_30 . V_140 == V_115 && V_134 -> V_136 . V_140 == V_115 ) {
V_36 -> V_131 -= V_134 -> V_136 . V_6 ;
if ( V_37 -> V_38 == V_115 )
V_37 -> V_6 -= V_134 -> V_136 . V_6 ;
break;
}
if ( V_134 -> V_30 . V_140 == V_115 && V_134 -> V_136 . V_140 == V_117 ) {
V_36 -> V_131 = - ( V_134 -> V_136 . V_6 + V_41 [ V_117 ] . V_6 ) ;
break;
}
if ( V_134 -> V_136 . V_140 == V_115 && V_37 -> V_38 == V_115 ) {
V_36 -> V_43 = V_134 -> V_30 . V_140 ;
V_36 -> V_42 [ V_134 -> V_30 . V_140 ] . V_38 = V_133 ;
V_36 -> V_42 [ V_134 -> V_30 . V_140 ] . V_6 = \
- V_36 -> V_131 + V_134 -> V_136 . V_6 ;
break;
}
if ( V_36 -> V_132 && V_134 -> V_30 . V_140 == V_115 &&
V_134 -> V_136 . V_140 == V_36 -> V_43 ) {
V_37 -> V_38 = V_115 ;
V_37 -> V_6 = V_36 -> V_131 = - V_134 -> V_136 . V_6 ;
V_36 -> V_43 = V_39 ;
V_36 -> V_132 = false ;
break;
}
if ( V_134 -> V_30 . V_140 == V_36 -> V_37 . V_38 ) {
F_11 ( L_41 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
break;
case V_145 :
if ( V_134 -> V_30 . V_140 != V_115 ||
( V_36 -> V_43 != V_39 && V_37 -> V_38 != V_115 ) ||
( V_36 -> V_43 == V_39 && V_37 -> V_38 != V_117 ) ) {
F_11 ( L_42 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
if ( V_36 -> V_43 != V_39 ) {
V_37 -> V_38 = V_36 -> V_43 ;
V_37 -> V_6 = V_36 -> V_131 = 0 ;
V_36 -> V_132 = true ;
}
break;
case V_137 :
if ( ! V_36 -> V_132 && V_134 -> V_30 . type == V_138 &&
V_134 -> V_30 . V_140 == V_37 -> V_38 ) {
V_37 -> V_38 = V_115 ;
}
if ( V_36 -> V_132 && V_37 -> V_38 == V_146 &&
V_134 -> V_30 . type == V_138 &&
V_134 -> V_30 . V_140 == V_36 -> V_43 &&
V_36 -> V_44 == - V_36 -> V_131 ) {
V_37 -> V_38 = V_36 -> V_43 ;
V_37 -> V_6 = 0 ;
V_36 -> V_44 = - 1 ;
} else if ( V_41 [ V_134 -> V_30 . V_140 ] . V_6 == - V_36 -> V_131 ) {
F_55 ( V_36 , V_134 -> V_30 . V_140 ) ;
}
V_36 -> V_131 -= 8 ;
if ( V_37 -> V_38 == V_115 )
V_37 -> V_6 -= 8 ;
break;
case V_147 :
if ( V_36 -> V_132 && V_134 -> V_136 . V_140 == V_117 &&
V_134 -> V_136 . V_6 == V_36 -> V_44 ) {
V_37 -> V_38 = V_36 -> V_43 ;
V_37 -> V_6 = 0 ;
V_36 -> V_44 = - 1 ;
}
if ( V_36 -> V_132 && V_134 -> V_136 . V_140 == V_117 &&
V_134 -> V_136 . V_6 == V_41 [ V_134 -> V_30 . V_140 ] . V_6 ) {
F_55 ( V_36 , V_134 -> V_30 . V_140 ) ;
} else if ( V_134 -> V_136 . V_140 == V_37 -> V_38 &&
V_134 -> V_136 . V_6 == V_41 [ V_134 -> V_30 . V_140 ] . V_6 + V_37 -> V_6 ) {
F_55 ( V_36 , V_134 -> V_30 . V_140 ) ;
}
break;
default:
F_11 ( L_43 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
break;
case V_135 :
V_36 -> V_131 += 8 ;
if ( V_37 -> V_38 == V_115 )
V_37 -> V_6 += 8 ;
if ( V_134 -> V_136 . type != V_143 )
break;
if ( V_36 -> V_132 ) {
if ( V_134 -> V_136 . V_140 == V_37 -> V_38 && V_134 -> V_136 . V_140 == V_36 -> V_43 ) {
V_37 -> V_38 = V_146 ;
V_37 -> V_6 = - V_36 -> V_131 ;
V_36 -> V_44 = - V_36 -> V_131 ;
} else if ( V_134 -> V_136 . V_140 == V_117 && V_37 -> V_38 == V_36 -> V_43 ) {
V_36 -> V_131 = 0 ;
} else if ( V_41 [ V_134 -> V_136 . V_140 ] . V_38 == V_39 ) {
F_53 ( V_36 , V_134 -> V_136 . V_140 , V_117 , - V_36 -> V_131 ) ;
}
} else {
F_53 ( V_36 , V_134 -> V_136 . V_140 , V_133 , - V_36 -> V_131 ) ;
}
if ( ! V_148 && V_7 -> V_12 && V_134 -> V_136 . V_140 == V_117 &&
V_37 -> V_38 != V_117 )
V_36 -> V_144 = true ;
break;
case V_149 :
if ( V_36 -> V_132 ) {
if ( V_134 -> V_136 . V_140 == V_37 -> V_38 && V_134 -> V_136 . V_140 == V_36 -> V_43 ) {
V_37 -> V_38 = V_146 ;
V_37 -> V_6 = V_134 -> V_30 . V_6 ;
V_36 -> V_44 = V_134 -> V_30 . V_6 ;
}
else if ( V_41 [ V_134 -> V_136 . V_140 ] . V_38 == V_39 ) {
F_53 ( V_36 , V_134 -> V_136 . V_140 , V_117 , V_134 -> V_30 . V_6 ) ;
}
} else if ( V_134 -> V_30 . V_140 == V_37 -> V_38 ) {
F_53 ( V_36 , V_134 -> V_136 . V_140 , V_133 ,
V_134 -> V_30 . V_6 - V_36 -> V_37 . V_6 ) ;
}
break;
case V_150 :
if ( ( ! V_36 -> V_132 && V_37 -> V_38 != V_117 ) ||
( V_36 -> V_132 && V_37 -> V_38 != V_36 -> V_43 ) ) {
F_11 ( L_44 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
V_36 -> V_131 = - V_36 -> V_41 [ V_117 ] . V_6 - 8 ;
F_55 ( V_36 , V_117 ) ;
if ( ! V_36 -> V_132 ) {
V_37 -> V_38 = V_115 ;
V_37 -> V_6 -= 8 ;
}
break;
case V_151 :
if ( V_134 -> V_136 . type != V_137 ) {
F_11 ( L_45 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
V_36 -> V_131 -= 8 ;
if ( V_37 -> V_38 == V_115 )
V_37 -> V_6 -= 8 ;
break;
default:
F_11 ( L_43 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
return 0 ;
}
static bool F_57 ( struct V_1 * V_7 , struct V_35 * V_36 )
{
struct V_35 * V_152 = & V_7 -> V_36 , * V_153 = V_36 ;
int V_20 ;
if ( memcmp ( & V_152 -> V_37 , & V_153 -> V_37 , sizeof( V_152 -> V_37 ) ) ) {
F_11 ( L_46 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_152 -> V_37 . V_38 , V_152 -> V_37 . V_6 ,
V_153 -> V_37 . V_38 , V_153 -> V_37 . V_6 ) ;
} else if ( memcmp ( & V_152 -> V_41 , & V_153 -> V_41 , sizeof( V_152 -> V_41 ) ) ) {
for ( V_20 = 0 ; V_20 < V_40 ; V_20 ++ ) {
if ( ! memcmp ( & V_152 -> V_41 [ V_20 ] , & V_153 -> V_41 [ V_20 ] ,
sizeof( struct V_104 ) ) )
continue;
F_11 ( L_47 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_20 , V_152 -> V_41 [ V_20 ] . V_38 , V_152 -> V_41 [ V_20 ] . V_6 ,
V_20 , V_153 -> V_41 [ V_20 ] . V_38 , V_153 -> V_41 [ V_20 ] . V_6 ) ;
break;
}
} else if ( V_152 -> type != V_153 -> type ) {
F_11 ( L_48 ,
V_7 -> V_5 , V_7 -> V_6 , V_152 -> type , V_153 -> type ) ;
} else if ( V_152 -> V_132 != V_153 -> V_132 ||
( V_152 -> V_132 && V_152 -> V_43 != V_153 -> V_43 ) ||
( V_152 -> V_132 && V_152 -> V_44 != V_153 -> V_44 ) ) {
F_11 ( L_49 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_152 -> V_132 , V_152 -> V_43 , V_152 -> V_44 ,
V_153 -> V_132 , V_153 -> V_43 , V_153 -> V_44 ) ;
} else
return true ;
return false ;
}
static int F_58 ( struct V_2 * V_3 , struct V_1 * V_154 ,
struct V_35 V_36 )
{
struct V_87 * V_88 ;
struct V_1 * V_7 , * V_155 ;
struct V_4 * V_5 ;
struct V_11 * V_12 = NULL ;
int V_45 ;
V_7 = V_154 ;
V_5 = V_7 -> V_5 ;
if ( V_7 -> V_79 && F_12 ( & V_7 -> V_34 ) ) {
F_11 ( L_50 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
while ( 1 ) {
V_155 = F_3 ( V_3 , V_7 ) ;
if ( V_3 -> V_156 && V_12 && V_7 -> V_12 && V_12 != V_7 -> V_12 ) {
F_17 ( L_51 ,
V_12 -> V_26 , V_7 -> V_12 -> V_26 ) ;
return 1 ;
}
if ( V_7 -> V_12 )
V_12 = V_7 -> V_12 ;
if ( V_12 && V_7 -> V_61 ) {
F_11 ( L_52 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_7 -> V_157 ) {
if ( ! V_7 -> V_103 && ! F_57 ( V_7 , & V_36 ) )
return 1 ;
return 0 ;
}
if ( V_7 -> V_103 ) {
if ( V_7 -> V_111 ) {
struct V_1 * V_158 , * V_20 ;
V_20 = V_7 ;
V_158 = NULL ;
F_43 (file, func, i) {
if ( V_20 -> V_109 ) {
V_158 = V_20 ;
break;
}
}
if ( ! V_158 ) {
F_11 ( L_53 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( ! V_158 -> V_157 ) {
if ( V_7 == V_154 )
return 0 ;
F_11 ( L_54 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
V_7 -> V_36 = V_158 -> V_36 ;
}
V_36 = V_7 -> V_36 ;
} else
V_7 -> V_36 = V_36 ;
V_7 -> V_157 = true ;
F_6 (alt, &insn->alts, list) {
V_45 = F_58 ( V_3 , V_88 -> V_7 , V_36 ) ;
if ( V_45 )
return 1 ;
}
switch ( V_7 -> type ) {
case V_27 :
if ( V_12 && F_50 ( & V_36 ) ) {
F_11 ( L_55 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_36 . V_144 ) {
F_17 ( L_56 ,
V_7 -> V_12 -> V_26 ) ;
return 1 ;
}
return 0 ;
case V_67 :
if ( F_49 ( V_7 ) )
break;
V_45 = F_13 ( V_3 , V_7 -> V_68 ) ;
if ( V_45 == 1 )
return 0 ;
if ( V_45 == - 1 )
return 1 ;
case V_159 :
if ( ! V_148 && V_12 && ! F_51 ( & V_36 ) ) {
F_11 ( L_57 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
break;
case V_64 :
case V_29 :
if ( V_7 -> V_31 &&
( ! V_12 || ! V_7 -> V_31 -> V_12 ||
V_12 == V_7 -> V_31 -> V_12 ) ) {
V_45 = F_58 ( V_3 , V_7 -> V_31 ,
V_36 ) ;
if ( V_45 )
return 1 ;
} else if ( V_12 && F_50 ( & V_36 ) ) {
F_11 ( L_58 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_7 -> type == V_29 )
return 0 ;
break;
case V_33 :
if ( V_12 && F_12 ( & V_7 -> V_34 ) &&
F_50 ( & V_36 ) ) {
F_11 ( L_58 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
case V_160 :
if ( V_12 && ( ! V_155 || ! V_155 -> V_103 ) ) {
F_11 ( L_59 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
case V_161 :
if ( F_56 ( V_7 , & V_36 ) )
return 1 ;
break;
default:
break;
}
if ( V_7 -> V_59 )
return 0 ;
V_7 = V_155 ;
if ( ! V_7 ) {
F_17 ( L_60 , V_5 -> V_26 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
int V_45 , V_162 = 0 ;
struct V_35 V_36 ;
if ( ! V_3 -> V_105 )
return 0 ;
F_14 ( & V_36 ) ;
F_23 (file, insn) {
if ( V_7 -> V_103 && ! V_7 -> V_157 ) {
V_45 = F_58 ( V_3 , V_7 , V_36 ) ;
V_162 += V_45 ;
}
}
return V_162 ;
}
static bool F_60 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_67 &&
! strcmp ( V_7 -> V_68 -> V_26 , L_61 ) ) ;
}
static bool F_61 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_67 &&
! strcmp ( V_7 -> V_68 -> V_26 ,
L_62 ) ) ;
}
static bool F_62 ( struct V_1 * V_7 )
{
int V_20 ;
if ( V_7 -> V_61 || V_7 -> type == V_78 )
return true ;
if ( ! strcmp ( V_7 -> V_5 -> V_26 , L_63 ) ||
! strcmp ( V_7 -> V_5 -> V_26 , L_12 ) ||
! strcmp ( V_7 -> V_5 -> V_26 , L_13 ) )
return true ;
if ( ! V_7 -> V_12 )
return false ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
if ( F_60 ( V_7 ) || F_61 ( V_7 ) )
return true ;
if ( V_7 -> type == V_29 && V_7 -> V_31 ) {
V_7 = V_7 -> V_31 ;
continue;
}
if ( V_7 -> V_6 + V_7 -> V_28 >= V_7 -> V_12 -> V_6 + V_7 -> V_12 -> V_28 )
break;
V_7 = F_4 ( V_7 , V_9 ) ;
}
return false ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
struct V_1 * V_7 ;
struct V_35 V_36 ;
int V_45 , V_162 = 0 ;
F_14 ( & V_36 ) ;
V_36 . V_37 = V_130 . V_37 ;
memcpy ( & V_36 . V_41 , & V_130 . V_41 ,
V_40 * sizeof( struct V_104 ) ) ;
V_36 . V_131 = V_130 . V_37 . V_6 ;
F_16 (file, sec) {
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
V_7 = F_1 ( V_3 , V_5 , V_12 -> V_6 ) ;
if ( ! V_7 || V_7 -> V_61 )
continue;
V_45 = F_58 ( V_3 , V_7 , V_36 ) ;
V_162 += V_45 ;
}
}
return V_162 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( V_3 -> V_98 )
return 0 ;
F_23 (file, insn) {
if ( V_7 -> V_157 || F_62 ( V_7 ) )
continue;
F_11 ( L_64 , V_7 -> V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_7 , * V_163 ;
struct V_87 * V_88 , * V_164 ;
F_37 (insn, tmpinsn, &file->insn_list, list) {
F_37 (alt, tmpalt, &insn->alts, list) {
F_38 ( & V_88 -> V_9 ) ;
free ( V_88 ) ;
}
F_38 ( & V_7 -> V_9 ) ;
F_66 ( & V_7 -> V_56 ) ;
free ( V_7 ) ;
}
F_67 ( V_3 -> V_50 ) ;
}
int F_68 ( const char * V_165 , bool V_166 , bool V_167 , bool V_168 )
{
struct V_2 V_3 ;
int V_45 , V_162 = 0 ;
V_169 = V_165 ;
V_148 = V_166 ;
V_3 . V_50 = F_69 ( V_169 , V_168 ? V_170 : V_171 ) ;
if ( ! V_3 . V_50 )
return 1 ;
F_18 ( & V_3 . V_10 ) ;
F_70 ( V_3 . V_55 ) ;
V_3 . V_14 = F_24 ( V_3 . V_50 , L_65 ) ;
V_3 . V_95 = F_24 ( V_3 . V_50 , L_66 ) ;
V_3 . V_156 = F_24 ( V_3 . V_50 , L_67 ) ;
V_3 . V_98 = V_167 ;
V_3 . V_105 = false ;
F_71 ( & V_130 ) ;
V_45 = F_48 ( & V_3 ) ;
if ( V_45 < 0 )
goto V_89;
V_162 += V_45 ;
if ( F_12 ( & V_3 . V_10 ) )
goto V_89;
V_45 = F_63 ( & V_3 ) ;
if ( V_45 < 0 )
goto V_89;
V_162 += V_45 ;
V_45 = F_59 ( & V_3 ) ;
if ( V_45 < 0 )
goto V_89;
V_162 += V_45 ;
if ( ! V_162 ) {
V_45 = F_64 ( & V_3 ) ;
if ( V_45 < 0 )
goto V_89;
V_162 += V_45 ;
}
if ( V_168 ) {
V_45 = F_72 ( & V_3 ) ;
if ( V_45 < 0 )
goto V_89;
V_45 = F_73 ( & V_3 ) ;
if ( V_45 < 0 )
goto V_89;
V_45 = F_74 ( V_3 . V_50 ) ;
if ( V_45 < 0 )
goto V_89;
}
V_89:
F_65 ( & V_3 ) ;
if ( V_45 || V_162 )
return 0 ;
return 0 ;
}
