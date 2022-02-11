static struct V_1 * F_1 ( struct V_2 * V_3 ,
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
static bool F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
F_6 (file, sec)
F_7 (sym, &sec->symbol_list, list)
if ( ! strncmp ( V_12 -> V_13 , L_1 , 8 ) )
return true ;
return false ;
}
static bool F_8 ( struct V_2 * V_3 , struct V_11 * V_14 )
{
struct V_15 * V_15 ;
struct V_1 * V_7 ;
if ( V_3 -> V_16 && V_3 -> V_16 -> V_15 )
F_7 (rela, &file->whitelist->rela->rela_list, list) {
if ( V_15 -> V_12 -> type == V_17 &&
V_15 -> V_12 -> V_5 == V_14 -> V_5 &&
V_15 -> V_18 == V_14 -> V_6 )
return true ;
if ( V_15 -> V_12 -> type == V_19 && V_15 -> V_12 == V_14 )
return true ;
}
F_9 (file, func, insn)
if ( V_7 -> type == V_20 )
return true ;
return false ;
}
static int F_10 ( struct V_2 * V_3 , struct V_11 * V_14 ,
int V_21 )
{
int V_22 ;
struct V_1 * V_7 ;
bool V_23 = true ;
static const char * const V_24 [] = {
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
} ;
if ( V_14 -> V_25 == V_26 )
return 0 ;
if ( V_14 -> V_25 == V_27 )
for ( V_22 = 0 ; V_22 < F_11 ( V_24 ) ; V_22 ++ )
if ( ! strcmp ( V_14 -> V_13 , V_24 [ V_22 ] ) )
return 1 ;
if ( ! V_14 -> V_5 )
return 0 ;
F_9 (file, func, insn) {
V_23 = false ;
if ( V_7 -> type == V_28 )
return 0 ;
}
if ( V_23 )
return 0 ;
F_9 (file, func, insn) {
if ( V_7 -> V_5 != V_14 -> V_5 ||
V_7 -> V_6 >= V_14 -> V_6 + V_14 -> V_29 )
break;
if ( V_7 -> type == V_30 ) {
struct V_1 * V_31 = V_7 -> V_32 ;
struct V_11 * V_33 ;
if ( ! V_31 )
return 0 ;
if ( V_31 -> V_5 != V_14 -> V_5 ||
V_31 -> V_6 < V_14 -> V_6 ||
V_31 -> V_6 >= V_14 -> V_6 + V_14 -> V_29 ) {
V_33 = F_12 ( V_31 -> V_5 ,
V_31 -> V_6 ) ;
if ( ! V_33 )
continue;
if ( V_21 == 5 ) {
F_13 ( L_12 ,
V_31 -> V_5 , V_31 -> V_6 ) ;
return - 1 ;
}
return F_10 ( V_3 , V_33 ,
V_21 + 1 ) ;
}
}
if ( V_7 -> type == V_34 && F_14 ( & V_7 -> V_35 ) )
return 0 ;
}
return 1 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_11 * V_14 )
{
return F_10 ( V_3 , V_14 , 0 ) ;
}
static void F_16 ( struct V_36 * V_37 )
{
int V_22 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_38 . V_39 = V_40 ;
for ( V_22 = 0 ; V_22 < V_41 ; V_22 ++ )
V_37 -> V_42 [ V_22 ] . V_39 = V_40 ;
V_37 -> V_43 = V_40 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
unsigned long V_6 ;
struct V_1 * V_7 ;
int V_44 ;
F_6 (file, sec) {
if ( ! ( V_5 -> V_45 . V_46 & V_47 ) )
continue;
for ( V_6 = 0 ; V_6 < V_5 -> V_29 ; V_6 += V_7 -> V_29 ) {
V_7 = malloc ( sizeof( * V_7 ) ) ;
if ( ! V_7 ) {
F_18 ( L_13 ) ;
return - 1 ;
}
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_19 ( & V_7 -> V_35 ) ;
F_16 ( & V_7 -> V_37 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
V_44 = F_20 ( V_3 -> V_48 , V_5 , V_6 ,
V_5 -> V_29 - V_6 ,
& V_7 -> V_29 , & V_7 -> type ,
& V_7 -> V_49 ,
& V_7 -> V_50 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_7 -> type || V_7 -> type > V_51 ) {
F_13 ( L_14 ,
V_7 -> V_5 , V_7 -> V_6 , V_7 -> type ) ;
return - 1 ;
}
F_21 ( V_3 -> V_52 , & V_7 -> V_53 , V_7 -> V_6 ) ;
F_22 ( & V_7 -> V_9 , & V_3 -> V_10 ) ;
}
F_7 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
if ( ! F_1 ( V_3 , V_5 , V_14 -> V_6 ) ) {
F_18 ( L_15 ,
V_14 -> V_13 ) ;
return - 1 ;
}
F_9 (file, func, insn)
if ( ! V_7 -> V_14 )
V_7 -> V_14 = V_14 ;
}
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_15 * V_15 ;
struct V_1 * V_7 ;
bool V_54 ;
V_5 = F_24 ( V_3 -> V_48 , L_16 ) ;
if ( ! V_5 )
return 0 ;
F_7 (rela, &sec->rela_list, list) {
if ( V_15 -> V_12 -> type != V_17 ) {
F_18 ( L_17 , V_5 -> V_13 ) ;
return - 1 ;
}
V_7 = F_1 ( V_3 , V_15 -> V_12 -> V_5 , V_15 -> V_18 ) ;
if ( V_7 )
V_7 = F_25 ( V_7 , V_9 ) ;
else if ( V_15 -> V_18 == V_15 -> V_12 -> V_5 -> V_29 ) {
V_54 = false ;
F_26 (insn, &file->insn_list, list) {
if ( V_7 -> V_5 == V_15 -> V_12 -> V_5 ) {
V_54 = true ;
break;
}
}
if ( ! V_54 ) {
F_18 ( L_18 ,
V_15 -> V_12 -> V_5 -> V_13 , V_15 -> V_18 ) ;
return - 1 ;
}
} else {
F_18 ( L_18 ,
V_15 -> V_12 -> V_5 -> V_13 , V_15 -> V_18 ) ;
return - 1 ;
}
V_7 -> V_55 = true ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_14 ;
F_6 (file, sec) {
F_7 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
if ( ! F_8 ( V_3 , V_14 ) )
continue;
F_9 (file, func, insn)
V_7 -> V_56 = true ;
}
}
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_15 * V_15 ;
struct V_4 * V_57 ;
unsigned long V_58 ;
F_29 (file, insn) {
if ( V_7 -> type != V_59 &&
V_7 -> type != V_30 )
continue;
if ( V_7 -> V_56 )
continue;
V_15 = F_30 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_15 ) {
V_57 = V_7 -> V_5 ;
V_58 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_49 ;
} else if ( V_15 -> V_12 -> type == V_17 ) {
V_57 = V_15 -> V_12 -> V_5 ;
V_58 = V_15 -> V_18 + 4 ;
} else if ( V_15 -> V_12 -> V_5 -> V_60 ) {
V_57 = V_15 -> V_12 -> V_5 ;
V_58 = V_15 -> V_12 -> V_12 . V_61 + V_15 -> V_18 + 4 ;
} else {
V_7 -> V_32 = 0 ;
continue;
}
V_7 -> V_32 = F_1 ( V_3 , V_57 , V_58 ) ;
if ( ! V_7 -> V_32 ) {
if ( ! strcmp ( V_7 -> V_5 -> V_13 , L_19 ) )
continue;
F_13 ( L_20 ,
V_7 -> V_5 , V_7 -> V_6 , V_57 -> V_13 ,
V_58 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
unsigned long V_58 ;
struct V_15 * V_15 ;
F_29 (file, insn) {
if ( V_7 -> type != V_62 )
continue;
V_15 = F_30 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_15 ) {
V_58 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_49 ;
V_7 -> V_63 = F_12 ( V_7 -> V_5 ,
V_58 ) ;
if ( ! V_7 -> V_63 ) {
F_13 ( L_21 ,
V_7 -> V_5 , V_7 -> V_6 , V_58 ) ;
return - 1 ;
}
} else if ( V_15 -> V_12 -> type == V_17 ) {
V_7 -> V_63 = F_12 ( V_15 -> V_12 -> V_5 ,
V_15 -> V_18 + 4 ) ;
if ( ! V_7 -> V_63 ||
V_7 -> V_63 -> type != V_19 ) {
F_13 ( L_22 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_15 -> V_12 -> V_5 -> V_13 ,
V_15 -> V_18 + 4 ) ;
return - 1 ;
}
} else
V_7 -> V_63 = V_15 -> V_12 ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_64 * V_64 ,
struct V_1 * V_65 ,
struct V_1 * * V_66 )
{
struct V_1 * V_67 , * V_68 , * V_7 , * V_69 ;
unsigned long V_58 ;
V_67 = NULL ;
V_7 = V_65 ;
F_33 (file, insn) {
if ( V_7 -> V_6 >= V_64 -> V_70 + V_64 -> V_71 )
break;
if ( V_64 -> V_72 )
V_7 -> type = V_73 ;
V_7 -> V_74 = true ;
V_67 = V_7 ;
}
if ( ! F_3 ( V_3 , V_67 ) ) {
F_18 ( L_23 ,
V_64 -> V_75 -> V_13 ) ;
return - 1 ;
}
V_69 = malloc ( sizeof( * V_69 ) ) ;
if ( ! V_69 ) {
F_18 ( L_13 ) ;
return - 1 ;
}
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
F_19 ( & V_69 -> V_35 ) ;
F_16 ( & V_69 -> V_37 ) ;
V_69 -> V_5 = V_64 -> V_76 ;
V_69 -> V_6 = - 1 ;
V_69 -> type = V_30 ;
V_69 -> V_32 = F_4 ( V_67 , V_9 ) ;
V_69 -> V_56 = true ;
if ( ! V_64 -> V_77 ) {
* V_66 = V_69 ;
return 0 ;
}
V_68 = NULL ;
V_7 = * V_66 ;
F_33 (file, insn) {
if ( V_7 -> V_6 >= V_64 -> V_78 + V_64 -> V_77 )
break;
V_68 = V_7 ;
if ( V_7 -> type != V_59 &&
V_7 -> type != V_30 )
continue;
if ( ! V_7 -> V_49 )
continue;
V_58 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_49 ;
if ( V_58 == V_64 -> V_78 + V_64 -> V_77 )
V_7 -> V_32 = V_69 ;
if ( ! V_7 -> V_32 ) {
F_13 ( L_24 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
}
if ( ! V_68 ) {
F_13 ( L_25 ,
V_64 -> V_76 , V_64 -> V_78 ) ;
return - 1 ;
}
F_34 ( & V_69 -> V_9 , & V_68 -> V_9 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_64 * V_64 ,
struct V_1 * V_65 ,
struct V_1 * * V_66 )
{
if ( V_65 -> type == V_73 )
return 0 ;
if ( V_65 -> type != V_30 ) {
F_13 ( L_26 ,
V_65 -> V_5 , V_65 -> V_6 ) ;
return - 1 ;
}
* V_66 = F_4 ( V_65 , V_9 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_79 V_80 ;
struct V_1 * V_65 , * V_66 ;
struct V_64 * V_64 , * V_81 ;
struct V_82 * V_83 ;
int V_44 ;
V_44 = F_37 ( V_3 -> V_48 , & V_80 ) ;
if ( V_44 )
return V_44 ;
F_38 (special_alt, tmp, &special_alts, list) {
V_83 = malloc ( sizeof( * V_83 ) ) ;
if ( ! V_83 ) {
F_18 ( L_13 ) ;
V_44 = - 1 ;
goto V_84;
}
V_65 = F_1 ( V_3 , V_64 -> V_75 ,
V_64 -> V_70 ) ;
if ( ! V_65 ) {
F_13 ( L_27 ,
V_64 -> V_75 , V_64 -> V_70 ) ;
V_44 = - 1 ;
goto V_84;
}
V_66 = NULL ;
if ( ! V_64 -> V_85 || V_64 -> V_77 ) {
V_66 = F_1 ( V_3 , V_64 -> V_76 ,
V_64 -> V_78 ) ;
if ( ! V_66 ) {
F_13 ( L_28 ,
V_64 -> V_76 ,
V_64 -> V_78 ) ;
V_44 = - 1 ;
goto V_84;
}
}
if ( V_64 -> V_85 ) {
V_44 = F_32 ( V_3 , V_64 , V_65 ,
& V_66 ) ;
if ( V_44 )
goto V_84;
} else if ( V_64 -> V_86 ) {
V_44 = F_35 ( V_3 , V_64 , V_65 ,
& V_66 ) ;
if ( V_44 )
goto V_84;
}
V_83 -> V_7 = V_66 ;
F_22 ( & V_83 -> V_9 , & V_65 -> V_35 ) ;
F_39 ( & V_64 -> V_9 ) ;
free ( V_64 ) ;
}
V_84:
return V_44 ;
}
static int F_40 ( struct V_2 * V_3 , struct V_11 * V_14 ,
struct V_1 * V_7 , struct V_15 * V_87 ,
struct V_15 * V_88 )
{
struct V_15 * V_15 = V_87 ;
struct V_1 * V_89 ;
struct V_82 * V_83 ;
F_41 (rela, &file->rodata->rela->rela_list, list) {
if ( V_15 == V_88 )
break;
if ( V_15 -> V_12 -> V_5 != V_7 -> V_5 ||
V_15 -> V_18 <= V_14 -> V_6 ||
V_15 -> V_18 >= V_14 -> V_6 + V_14 -> V_29 )
break;
V_89 = F_1 ( V_3 , V_7 -> V_5 , V_15 -> V_18 ) ;
if ( ! V_89 ) {
F_18 ( L_29 ,
V_3 -> V_90 -> V_15 -> V_13 , V_7 -> V_5 -> V_13 ,
V_15 -> V_18 ) ;
return - 1 ;
}
V_83 = malloc ( sizeof( * V_83 ) ) ;
if ( ! V_83 ) {
F_18 ( L_13 ) ;
return - 1 ;
}
V_83 -> V_7 = V_89 ;
F_22 ( & V_83 -> V_9 , & V_7 -> V_35 ) ;
}
return 0 ;
}
static struct V_15 * F_42 ( struct V_2 * V_3 ,
struct V_11 * V_14 ,
struct V_1 * V_7 )
{
struct V_15 * V_91 , * V_92 ;
struct V_1 * V_65 = V_7 ;
V_91 = F_30 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_29 ) ;
if ( V_91 && V_91 -> V_12 == V_3 -> V_90 -> V_12 ) {
V_92 = F_43 ( V_3 -> V_90 ,
V_91 -> V_18 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_43 ( V_3 -> V_90 ,
V_91 -> V_18 + 4 ) ;
if ( ! V_92 )
return NULL ;
V_3 -> V_93 = true ;
return V_92 ;
}
F_44 (file, func, insn) {
if ( V_7 -> type == V_34 )
break;
if ( V_7 -> type == V_30 &&
V_7 -> V_32 &&
( V_7 -> V_32 -> V_6 <= V_7 -> V_6 ||
V_7 -> V_32 -> V_6 > V_65 -> V_6 ) )
break;
V_91 = F_30 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_91 || V_91 -> V_12 != V_3 -> V_90 -> V_12 )
continue;
if ( F_45 ( V_3 -> V_90 , V_91 -> V_18 ) )
continue;
return F_43 ( V_3 -> V_90 , V_91 -> V_18 ) ;
}
return NULL ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_11 * V_14 )
{
struct V_1 * V_7 , * V_94 = NULL ;
struct V_15 * V_15 , * V_95 = NULL ;
int V_44 ;
F_9 (file, func, insn) {
if ( V_7 -> type != V_34 )
continue;
V_15 = F_42 ( V_3 , V_14 , V_7 ) ;
if ( ! V_15 )
continue;
if ( V_94 ) {
V_44 = F_40 ( V_3 , V_14 , V_94 , V_95 ,
V_15 ) ;
if ( V_44 )
return V_44 ;
}
V_94 = V_7 ;
V_95 = V_15 ;
}
if ( V_94 ) {
V_44 = F_40 ( V_3 , V_14 , V_94 , V_95 , NULL ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
int V_44 ;
if ( ! V_3 -> V_90 || ! V_3 -> V_90 -> V_15 )
return 0 ;
F_6 (file, sec) {
F_7 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
V_44 = F_46 ( V_3 , V_14 ) ;
if ( V_44 )
return V_44 ;
}
}
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
int V_44 ;
V_44 = F_17 ( V_3 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_23 ( V_3 ) ;
if ( V_44 )
return V_44 ;
F_27 ( V_3 ) ;
V_44 = F_28 ( V_3 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_31 ( V_3 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_36 ( V_3 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_47 ( V_3 ) ;
if ( V_44 )
return V_44 ;
return 0 ;
}
static bool F_49 ( struct V_1 * V_7 )
{
if ( V_7 -> type == V_62 &&
V_7 -> V_63 -> type == V_96 &&
! strcmp ( V_7 -> V_63 -> V_13 , L_30 ) )
return true ;
return false ;
}
static bool F_50 ( struct V_36 * V_37 )
{
int V_22 ;
if ( V_37 -> V_38 . V_39 != V_97 . V_38 . V_39 ||
V_37 -> V_38 . V_6 != V_97 . V_38 . V_6 ||
V_37 -> V_98 != V_97 . V_38 . V_6 ||
V_37 -> V_99 )
return true ;
for ( V_22 = 0 ; V_22 < V_41 ; V_22 ++ )
if ( V_37 -> V_42 [ V_22 ] . V_39 != V_97 . V_42 [ V_22 ] . V_39 ||
V_37 -> V_42 [ V_22 ] . V_6 != V_97 . V_42 [ V_22 ] . V_6 )
return true ;
return false ;
}
static bool F_51 ( struct V_36 * V_37 )
{
if ( V_37 -> V_38 . V_39 == V_100 && V_37 -> V_42 [ V_100 ] . V_39 == V_101 &&
V_37 -> V_42 [ V_100 ] . V_6 == - 16 )
return true ;
if ( V_37 -> V_99 && V_37 -> V_42 [ V_100 ] . V_39 == V_100 )
return true ;
return false ;
}
static void F_52 ( struct V_36 * V_37 , unsigned char V_102 , int V_39 ,
int V_6 )
{
if ( ( F_53 ( V_102 ) ||
( V_37 -> V_99 && V_102 == V_37 -> V_43 ) ) &&
V_37 -> V_42 [ V_102 ] . V_39 == V_40 ) {
V_37 -> V_42 [ V_102 ] . V_39 = V_39 ;
V_37 -> V_42 [ V_102 ] . V_6 = V_6 ;
}
}
static void F_54 ( struct V_36 * V_37 , unsigned char V_102 )
{
V_37 -> V_42 [ V_102 ] . V_39 = V_40 ;
V_37 -> V_42 [ V_102 ] . V_6 = 0 ;
}
static int F_55 ( struct V_1 * V_7 , struct V_36 * V_37 )
{
struct V_50 * V_103 = & V_7 -> V_50 ;
struct V_104 * V_38 = & V_37 -> V_38 ;
struct V_104 * V_42 = V_37 -> V_42 ;
if ( V_38 -> V_39 == V_40 ) {
if ( V_7 -> V_14 ) {
F_13 ( L_31 , V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
return 0 ;
}
switch ( V_103 -> V_31 . type ) {
case V_105 :
switch ( V_103 -> V_106 . type ) {
case V_107 :
if ( V_38 -> V_39 == V_103 -> V_106 . V_102 && V_38 -> V_39 == V_108 &&
V_103 -> V_31 . V_102 == V_100 && V_42 [ V_100 ] . V_39 == V_101 &&
V_42 [ V_100 ] . V_6 == - V_38 -> V_6 ) {
V_38 -> V_39 = V_103 -> V_31 . V_102 ;
V_37 -> V_109 = false ;
} else if ( V_37 -> V_99 ) {
V_42 [ V_100 ] . V_39 = V_100 ;
V_42 [ V_100 ] . V_6 = - V_37 -> V_98 ;
V_37 -> V_109 = false ;
} else if ( ! V_110 ) {
F_13 ( L_32 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
break;
case V_111 :
if ( V_103 -> V_31 . V_102 == V_108 && V_103 -> V_106 . V_102 == V_108 ) {
V_37 -> V_98 -= V_103 -> V_106 . V_6 ;
if ( V_38 -> V_39 == V_108 )
V_38 -> V_6 -= V_103 -> V_106 . V_6 ;
break;
}
if ( V_103 -> V_31 . V_102 == V_108 && V_103 -> V_106 . V_102 == V_100 ) {
V_37 -> V_98 = - ( V_103 -> V_106 . V_6 + V_42 [ V_100 ] . V_6 ) ;
break;
}
if ( V_103 -> V_31 . V_102 != V_100 && V_103 -> V_106 . V_102 == V_108 &&
V_38 -> V_39 == V_108 ) {
V_37 -> V_43 = V_103 -> V_31 . V_102 ;
break;
}
if ( V_37 -> V_99 && V_103 -> V_31 . V_102 == V_108 &&
V_103 -> V_106 . V_102 == V_37 -> V_43 ) {
V_38 -> V_39 = V_108 ;
V_38 -> V_6 = V_37 -> V_98 = - V_103 -> V_106 . V_6 ;
V_37 -> V_43 = V_40 ;
V_37 -> V_99 = false ;
break;
}
if ( V_103 -> V_31 . V_102 == V_37 -> V_38 . V_39 ) {
F_13 ( L_33 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
break;
case V_112 :
if ( V_103 -> V_31 . V_102 != V_108 ||
( V_37 -> V_43 != V_40 && V_38 -> V_39 != V_108 ) ||
( V_37 -> V_43 == V_40 && V_38 -> V_39 != V_100 ) ) {
F_13 ( L_34 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
if ( V_37 -> V_43 != V_40 ) {
V_38 -> V_39 = V_37 -> V_43 ;
V_38 -> V_6 = V_37 -> V_98 = 0 ;
V_37 -> V_99 = true ;
}
break;
case V_113 :
if ( ! V_37 -> V_99 && V_103 -> V_31 . type == V_105 &&
V_103 -> V_31 . V_102 == V_38 -> V_39 ) {
V_38 -> V_39 = V_108 ;
}
if ( V_42 [ V_103 -> V_31 . V_102 ] . V_6 == - V_37 -> V_98 ) {
if ( V_37 -> V_99 && V_38 -> V_39 == V_114 &&
V_103 -> V_31 . type == V_105 &&
V_103 -> V_31 . V_102 == V_37 -> V_43 ) {
V_38 -> V_39 = V_37 -> V_43 ;
V_38 -> V_6 = 0 ;
}
F_54 ( V_37 , V_103 -> V_31 . V_102 ) ;
}
V_37 -> V_98 -= 8 ;
if ( V_38 -> V_39 == V_108 )
V_38 -> V_6 -= 8 ;
break;
case V_115 :
if ( V_37 -> V_99 && V_103 -> V_106 . V_102 == V_100 &&
V_103 -> V_106 . V_6 == V_42 [ V_103 -> V_31 . V_102 ] . V_6 ) {
if ( V_103 -> V_31 . V_102 == V_37 -> V_43 ) {
V_38 -> V_39 = V_37 -> V_43 ;
V_38 -> V_6 = 0 ;
}
F_54 ( V_37 , V_103 -> V_31 . V_102 ) ;
} else if ( V_103 -> V_106 . V_102 == V_38 -> V_39 &&
V_103 -> V_106 . V_6 == V_42 [ V_103 -> V_31 . V_102 ] . V_6 + V_38 -> V_6 ) {
F_54 ( V_37 , V_103 -> V_31 . V_102 ) ;
}
break;
default:
F_13 ( L_35 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
break;
case V_116 :
V_37 -> V_98 += 8 ;
if ( V_38 -> V_39 == V_108 )
V_38 -> V_6 += 8 ;
if ( V_103 -> V_106 . type != V_107 )
break;
if ( V_37 -> V_99 ) {
if ( V_103 -> V_106 . V_102 == V_38 -> V_39 && V_103 -> V_106 . V_102 == V_37 -> V_43 ) {
V_38 -> V_39 = V_114 ;
V_38 -> V_6 = - V_37 -> V_98 ;
F_52 ( V_37 , V_103 -> V_106 . V_102 , V_101 , - V_37 -> V_98 ) ;
} else if ( V_103 -> V_106 . V_102 == V_100 && V_38 -> V_39 == V_37 -> V_43 ) {
V_37 -> V_98 = 0 ;
} else if ( V_42 [ V_103 -> V_106 . V_102 ] . V_39 == V_40 ) {
F_52 ( V_37 , V_103 -> V_106 . V_102 , V_100 , - V_37 -> V_98 ) ;
}
} else {
F_52 ( V_37 , V_103 -> V_106 . V_102 , V_101 , - V_37 -> V_98 ) ;
}
if ( ! V_110 && V_7 -> V_14 && V_103 -> V_106 . V_102 == V_100 &&
V_38 -> V_39 != V_100 )
V_37 -> V_109 = true ;
break;
case V_117 :
if ( V_37 -> V_99 ) {
if ( V_103 -> V_106 . V_102 == V_38 -> V_39 && V_103 -> V_106 . V_102 == V_37 -> V_43 ) {
V_38 -> V_39 = V_114 ;
V_38 -> V_6 = V_103 -> V_31 . V_6 ;
F_52 ( V_37 , V_103 -> V_106 . V_102 , V_101 , V_103 -> V_31 . V_6 ) ;
}
else if ( V_42 [ V_103 -> V_106 . V_102 ] . V_39 == V_40 ) {
F_52 ( V_37 , V_103 -> V_106 . V_102 , V_100 , V_103 -> V_31 . V_6 ) ;
}
} else if ( V_103 -> V_31 . V_102 == V_38 -> V_39 ) {
F_52 ( V_37 , V_103 -> V_106 . V_102 , V_101 ,
V_103 -> V_31 . V_6 - V_37 -> V_38 . V_6 ) ;
}
break;
case V_118 :
if ( ( ! V_37 -> V_99 && V_38 -> V_39 != V_100 ) ||
( V_37 -> V_99 && V_38 -> V_39 != V_37 -> V_43 ) ) {
F_13 ( L_36 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
V_37 -> V_98 = - V_37 -> V_42 [ V_100 ] . V_6 - 8 ;
F_54 ( V_37 , V_100 ) ;
if ( ! V_37 -> V_99 ) {
V_38 -> V_39 = V_108 ;
V_38 -> V_6 -= 8 ;
}
break;
case V_119 :
if ( V_103 -> V_106 . type != V_113 ) {
F_13 ( L_37 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
V_37 -> V_98 -= 8 ;
if ( V_38 -> V_39 == V_108 )
V_38 -> V_6 -= 8 ;
break;
default:
F_13 ( L_35 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
return 0 ;
}
static bool F_56 ( struct V_1 * V_7 , struct V_36 * V_37 )
{
struct V_36 * V_120 = & V_7 -> V_37 , * V_121 = V_37 ;
int V_22 ;
if ( memcmp ( & V_120 -> V_38 , & V_121 -> V_38 , sizeof( V_120 -> V_38 ) ) ) {
F_13 ( L_38 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_120 -> V_38 . V_39 , V_120 -> V_38 . V_6 ,
V_121 -> V_38 . V_39 , V_121 -> V_38 . V_6 ) ;
} else if ( memcmp ( & V_120 -> V_42 , & V_121 -> V_42 , sizeof( V_120 -> V_42 ) ) ) {
for ( V_22 = 0 ; V_22 < V_41 ; V_22 ++ ) {
if ( ! memcmp ( & V_120 -> V_42 [ V_22 ] , & V_121 -> V_42 [ V_22 ] ,
sizeof( struct V_104 ) ) )
continue;
F_13 ( L_39 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_22 , V_120 -> V_42 [ V_22 ] . V_39 , V_120 -> V_42 [ V_22 ] . V_6 ,
V_22 , V_121 -> V_42 [ V_22 ] . V_39 , V_121 -> V_42 [ V_22 ] . V_6 ) ;
break;
}
} else if ( V_120 -> V_99 != V_121 -> V_99 ||
( V_120 -> V_99 && V_120 -> V_43 != V_121 -> V_43 ) ) {
F_13 ( L_40 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_120 -> V_99 , V_120 -> V_43 ,
V_121 -> V_99 , V_121 -> V_43 ) ;
} else
return true ;
return false ;
}
static int F_57 ( struct V_2 * V_3 , struct V_1 * V_122 ,
struct V_36 V_37 )
{
struct V_82 * V_83 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_14 = NULL ;
int V_44 ;
V_7 = V_122 ;
V_5 = V_7 -> V_5 ;
if ( V_7 -> V_74 && F_14 ( & V_7 -> V_35 ) ) {
F_13 ( L_41 ,
V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
while ( 1 ) {
if ( V_3 -> V_123 && V_7 -> V_14 ) {
if ( V_14 && V_14 != V_7 -> V_14 ) {
F_18 ( L_42 ,
V_14 -> V_13 , V_7 -> V_14 -> V_13 ) ;
return 1 ;
}
}
V_14 = V_7 -> V_14 ;
if ( V_14 && V_7 -> V_56 ) {
F_13 ( L_43 ,
V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
if ( V_7 -> V_124 ) {
if ( ! ! F_56 ( V_7 , & V_37 ) )
return 1 ;
return 0 ;
}
V_7 -> V_37 = V_37 ;
V_7 -> V_124 = true ;
F_7 (alt, &insn->alts, list) {
V_44 = F_57 ( V_3 , V_83 -> V_7 , V_37 ) ;
if ( V_44 )
return 1 ;
}
switch ( V_7 -> type ) {
case V_28 :
if ( V_14 && F_50 ( & V_37 ) ) {
F_13 ( L_44 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_37 . V_109 ) {
F_18 ( L_45 ,
V_7 -> V_14 -> V_13 ) ;
return 1 ;
}
return 0 ;
case V_62 :
if ( F_49 ( V_7 ) )
break;
V_44 = F_15 ( V_3 , V_7 -> V_63 ) ;
if ( V_44 == 1 )
return 0 ;
if ( V_44 == - 1 )
return 1 ;
case V_125 :
if ( ! V_110 && V_14 && ! F_51 ( & V_37 ) ) {
F_13 ( L_46 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
break;
case V_59 :
case V_30 :
if ( V_7 -> V_32 &&
( ! V_14 || ! V_7 -> V_32 -> V_14 ||
V_14 == V_7 -> V_32 -> V_14 ) ) {
V_44 = F_57 ( V_3 , V_7 -> V_32 ,
V_37 ) ;
if ( V_44 )
return 1 ;
} else if ( V_14 && F_50 ( & V_37 ) ) {
F_13 ( L_47 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_7 -> type == V_30 )
return 0 ;
break;
case V_34 :
if ( V_14 && F_14 ( & V_7 -> V_35 ) &&
F_50 ( & V_37 ) ) {
F_13 ( L_47 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
case V_126 :
if ( F_55 ( V_7 , & V_37 ) )
return - 1 ;
break;
default:
break;
}
if ( V_7 -> V_55 )
return 0 ;
V_7 = F_3 ( V_3 , V_7 ) ;
if ( ! V_7 ) {
F_18 ( L_48 , V_5 -> V_13 ) ;
return 1 ;
}
}
return 0 ;
}
static bool F_58 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_62 &&
! strcmp ( V_7 -> V_63 -> V_13 , L_49 ) ) ;
}
static bool F_59 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_62 &&
! strcmp ( V_7 -> V_63 -> V_13 ,
L_50 ) ) ;
}
static bool F_60 ( struct V_1 * V_7 )
{
int V_22 ;
if ( V_7 -> V_56 || V_7 -> type == V_73 )
return true ;
if ( ! strcmp ( V_7 -> V_5 -> V_13 , L_51 ) )
return true ;
if ( ! V_7 -> V_14 )
return false ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
if ( F_58 ( V_7 ) || F_59 ( V_7 ) )
return true ;
if ( V_7 -> type == V_30 && V_7 -> V_32 ) {
V_7 = V_7 -> V_32 ;
continue;
}
if ( V_7 -> V_6 + V_7 -> V_29 >= V_7 -> V_14 -> V_6 + V_7 -> V_14 -> V_29 )
break;
V_7 = F_4 ( V_7 , V_9 ) ;
}
return false ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
struct V_1 * V_7 ;
struct V_36 V_37 ;
int V_44 , V_127 = 0 ;
F_16 ( & V_37 ) ;
V_37 . V_38 = V_97 . V_38 ;
memcpy ( & V_37 . V_42 , & V_97 . V_42 ,
V_41 * sizeof( struct V_104 ) ) ;
V_37 . V_98 = V_97 . V_38 . V_6 ;
F_6 (file, sec) {
F_7 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
V_7 = F_1 ( V_3 , V_5 , V_14 -> V_6 ) ;
if ( ! V_7 || V_7 -> V_56 )
continue;
V_44 = F_57 ( V_3 , V_7 , V_37 ) ;
V_127 += V_44 ;
}
}
return V_127 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
if ( V_3 -> V_93 )
return 0 ;
F_29 (file, insn) {
if ( V_7 -> V_124 || F_60 ( V_7 ) )
continue;
if ( F_5 ( V_3 ) )
return 0 ;
F_13 ( L_52 , V_7 -> V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_7 , * V_128 ;
struct V_82 * V_83 , * V_129 ;
F_38 (insn, tmpinsn, &file->insn_list, list) {
F_38 (alt, tmpalt, &insn->alts, list) {
F_39 ( & V_83 -> V_9 ) ;
free ( V_83 ) ;
}
F_39 ( & V_7 -> V_9 ) ;
F_64 ( & V_7 -> V_53 ) ;
free ( V_7 ) ;
}
F_65 ( V_3 -> V_48 ) ;
}
int F_66 ( const char * V_130 , bool V_131 )
{
struct V_2 V_3 ;
int V_44 , V_127 = 0 ;
V_132 = V_130 ;
V_110 = V_131 ;
V_3 . V_48 = F_67 ( V_132 ) ;
if ( ! V_3 . V_48 )
return 1 ;
F_19 ( & V_3 . V_10 ) ;
F_68 ( V_3 . V_52 ) ;
V_3 . V_16 = F_24 ( V_3 . V_48 , L_53 ) ;
V_3 . V_90 = F_24 ( V_3 . V_48 , L_54 ) ;
V_3 . V_93 = false ;
V_3 . V_123 = F_24 ( V_3 . V_48 , L_55 ) ;
F_69 ( & V_97 ) ;
V_44 = F_48 ( & V_3 ) ;
if ( V_44 < 0 )
goto V_84;
V_127 += V_44 ;
if ( F_14 ( & V_3 . V_10 ) )
goto V_84;
V_44 = F_61 ( & V_3 ) ;
if ( V_44 < 0 )
goto V_84;
V_127 += V_44 ;
if ( ! V_127 ) {
V_44 = F_62 ( & V_3 ) ;
if ( V_44 < 0 )
goto V_84;
V_127 += V_44 ;
}
V_84:
F_63 ( & V_3 ) ;
if ( V_44 || V_127 )
return 0 ;
return 0 ;
}
