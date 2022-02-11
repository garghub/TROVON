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
if ( & V_8 -> V_9 == & V_3 -> V_10 || V_8 -> V_5 != V_7 -> V_5 )
return NULL ;
return V_8 ;
}
static bool F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
F_6 (sec, &file->elf->sections, list)
F_6 (sym, &sec->symbol_list, list)
if ( ! strncmp ( V_12 -> V_13 , L_1 , 8 ) )
return true ;
return false ;
}
static bool F_7 ( struct V_2 * V_3 , struct V_11 * V_14 )
{
struct V_15 * V_15 ;
struct V_1 * V_7 ;
if ( V_3 -> V_16 && V_3 -> V_16 -> V_15 )
F_6 (rela, &file->whitelist->rela->rela_list, list) {
if ( V_15 -> V_12 -> type == V_17 &&
V_15 -> V_12 -> V_5 == V_14 -> V_5 &&
V_15 -> V_18 == V_14 -> V_6 )
return true ;
if ( V_15 -> V_12 -> type == V_19 && V_15 -> V_12 == V_14 )
return true ;
}
F_8 (file, func, insn)
if ( V_7 -> type == V_20 )
return true ;
return false ;
}
static int F_9 ( struct V_2 * V_3 , struct V_11 * V_14 ,
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
L_10
} ;
if ( V_14 -> V_25 == V_26 )
return 0 ;
if ( V_14 -> V_25 == V_27 )
for ( V_22 = 0 ; V_22 < F_10 ( V_24 ) ; V_22 ++ )
if ( ! strcmp ( V_14 -> V_13 , V_24 [ V_22 ] ) )
return 1 ;
if ( ! V_14 -> V_5 )
return 0 ;
F_8 (file, func, insn) {
V_23 = false ;
if ( V_7 -> type == V_28 )
return 0 ;
}
if ( V_23 )
return 0 ;
F_8 (file, func, insn) {
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
V_33 = F_11 ( V_31 -> V_5 ,
V_31 -> V_6 ) ;
if ( ! V_33 )
continue;
if ( V_21 == 5 ) {
F_12 ( L_11 ,
V_31 -> V_5 , V_31 -> V_6 ) ;
return - 1 ;
}
return F_9 ( V_3 , V_33 ,
V_21 + 1 ) ;
}
}
if ( V_7 -> type == V_34 && F_13 ( & V_7 -> V_35 ) )
return 0 ;
}
return 1 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_11 * V_14 )
{
return F_9 ( V_3 , V_14 , 0 ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
unsigned long V_6 ;
struct V_1 * V_7 ;
int V_36 ;
F_6 (sec, &file->elf->sections, list) {
if ( ! ( V_5 -> V_37 . V_38 & V_39 ) )
continue;
for ( V_6 = 0 ; V_6 < V_5 -> V_29 ; V_6 += V_7 -> V_29 ) {
V_7 = malloc ( sizeof( * V_7 ) ) ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_16 ( & V_7 -> V_35 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
V_36 = F_17 ( V_3 -> V_40 , V_5 , V_6 ,
V_5 -> V_29 - V_6 ,
& V_7 -> V_29 , & V_7 -> type ,
& V_7 -> V_41 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_7 -> type || V_7 -> type > V_42 ) {
F_12 ( L_12 ,
V_7 -> V_5 , V_7 -> V_6 , V_7 -> type ) ;
return - 1 ;
}
F_18 ( V_3 -> V_43 , & V_7 -> V_44 , V_7 -> V_6 ) ;
F_19 ( & V_7 -> V_9 , & V_3 -> V_10 ) ;
}
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
if ( ! F_1 ( V_3 , V_5 , V_14 -> V_6 ) ) {
F_20 ( L_13 ,
V_14 -> V_13 ) ;
return - 1 ;
}
F_8 (file, func, insn)
if ( ! V_7 -> V_14 )
V_7 -> V_14 = V_14 ;
}
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_15 * V_15 ;
struct V_1 * V_7 ;
bool V_45 ;
V_5 = F_22 ( V_3 -> V_40 , L_14 ) ;
if ( ! V_5 )
return 0 ;
F_6 (rela, &sec->rela_list, list) {
if ( V_15 -> V_12 -> type != V_17 ) {
F_20 ( L_15 , V_5 -> V_13 ) ;
return - 1 ;
}
V_7 = F_1 ( V_3 , V_15 -> V_12 -> V_5 , V_15 -> V_18 ) ;
if ( V_7 )
V_7 = F_23 ( V_7 , V_9 ) ;
else if ( V_15 -> V_18 == V_15 -> V_12 -> V_5 -> V_29 ) {
V_45 = false ;
F_24 (insn, &file->insn_list, list) {
if ( V_7 -> V_5 == V_15 -> V_12 -> V_5 ) {
V_45 = true ;
break;
}
}
if ( ! V_45 ) {
F_20 ( L_16 ,
V_15 -> V_12 -> V_5 -> V_13 , V_15 -> V_18 ) ;
return - 1 ;
}
} else {
F_20 ( L_16 ,
V_15 -> V_12 -> V_5 -> V_13 , V_15 -> V_18 ) ;
return - 1 ;
}
V_7 -> V_46 = true ;
}
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_14 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
if ( ! F_7 ( V_3 , V_14 ) )
continue;
F_8 (file, func, insn)
V_7 -> V_47 = true ;
}
}
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_15 * V_15 ;
struct V_4 * V_48 ;
unsigned long V_49 ;
F_27 (file, insn) {
if ( V_7 -> type != V_50 &&
V_7 -> type != V_30 )
continue;
if ( V_7 -> V_47 )
continue;
V_15 = F_28 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_15 ) {
V_48 = V_7 -> V_5 ;
V_49 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
} else if ( V_15 -> V_12 -> type == V_17 ) {
V_48 = V_15 -> V_12 -> V_5 ;
V_49 = V_15 -> V_18 + 4 ;
} else if ( V_15 -> V_12 -> V_5 -> V_51 ) {
V_48 = V_15 -> V_12 -> V_5 ;
V_49 = V_15 -> V_12 -> V_12 . V_52 + V_15 -> V_18 + 4 ;
} else {
V_7 -> V_32 = 0 ;
continue;
}
V_7 -> V_32 = F_1 ( V_3 , V_48 , V_49 ) ;
if ( ! V_7 -> V_32 ) {
if ( ! strcmp ( V_7 -> V_5 -> V_13 , L_17 ) )
continue;
F_12 ( L_18 ,
V_7 -> V_5 , V_7 -> V_6 , V_48 -> V_13 ,
V_49 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
unsigned long V_49 ;
struct V_15 * V_15 ;
F_27 (file, insn) {
if ( V_7 -> type != V_53 )
continue;
V_15 = F_28 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_15 ) {
V_49 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
V_7 -> V_54 = F_11 ( V_7 -> V_5 ,
V_49 ) ;
if ( ! V_7 -> V_54 ) {
F_12 ( L_19 ,
V_7 -> V_5 , V_7 -> V_6 , V_49 ) ;
return - 1 ;
}
} else if ( V_15 -> V_12 -> type == V_17 ) {
V_7 -> V_54 = F_11 ( V_15 -> V_12 -> V_5 ,
V_15 -> V_18 + 4 ) ;
if ( ! V_7 -> V_54 ||
V_7 -> V_54 -> type != V_19 ) {
F_12 ( L_20 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_15 -> V_12 -> V_5 -> V_13 ,
V_15 -> V_18 + 4 ) ;
return - 1 ;
}
} else
V_7 -> V_54 = V_15 -> V_12 ;
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_55 * V_55 ,
struct V_1 * V_56 ,
struct V_1 * * V_57 )
{
struct V_1 * V_58 , * V_59 , * V_7 , * V_60 ;
unsigned long V_49 ;
V_58 = NULL ;
V_7 = V_56 ;
F_31 (file, insn) {
if ( V_7 -> V_6 >= V_55 -> V_61 + V_55 -> V_62 )
break;
if ( V_55 -> V_63 )
V_7 -> type = V_64 ;
V_7 -> V_65 = true ;
V_58 = V_7 ;
}
if ( ! F_3 ( V_3 , V_58 ) ) {
F_20 ( L_21 ,
V_55 -> V_66 -> V_13 ) ;
return - 1 ;
}
V_60 = malloc ( sizeof( * V_60 ) ) ;
if ( ! V_60 ) {
F_20 ( L_22 ) ;
return - 1 ;
}
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
F_16 ( & V_60 -> V_35 ) ;
V_60 -> V_5 = V_55 -> V_67 ;
V_60 -> V_6 = - 1 ;
V_60 -> type = V_30 ;
V_60 -> V_32 = F_4 ( V_58 , V_9 ) ;
if ( ! V_55 -> V_68 ) {
* V_57 = V_60 ;
return 0 ;
}
V_59 = NULL ;
V_7 = * V_57 ;
F_31 (file, insn) {
if ( V_7 -> V_6 >= V_55 -> V_69 + V_55 -> V_68 )
break;
V_59 = V_7 ;
if ( V_7 -> type != V_50 &&
V_7 -> type != V_30 )
continue;
if ( ! V_7 -> V_41 )
continue;
V_49 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
if ( V_49 == V_55 -> V_69 + V_55 -> V_68 )
V_7 -> V_32 = V_60 ;
if ( ! V_7 -> V_32 ) {
F_12 ( L_23 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
}
if ( ! V_59 ) {
F_12 ( L_24 ,
V_55 -> V_67 , V_55 -> V_69 ) ;
return - 1 ;
}
F_32 ( & V_60 -> V_9 , & V_59 -> V_9 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_55 * V_55 ,
struct V_1 * V_56 ,
struct V_1 * * V_57 )
{
if ( V_56 -> type == V_64 )
return 0 ;
if ( V_56 -> type != V_30 ) {
F_12 ( L_25 ,
V_56 -> V_5 , V_56 -> V_6 ) ;
return - 1 ;
}
* V_57 = F_4 ( V_56 , V_9 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_70 V_71 ;
struct V_1 * V_56 , * V_57 ;
struct V_55 * V_55 , * V_72 ;
struct V_73 * V_74 ;
int V_36 ;
V_36 = F_35 ( V_3 -> V_40 , & V_71 ) ;
if ( V_36 )
return V_36 ;
F_36 (special_alt, tmp, &special_alts, list) {
V_74 = malloc ( sizeof( * V_74 ) ) ;
if ( ! V_74 ) {
F_20 ( L_22 ) ;
V_36 = - 1 ;
goto V_75;
}
V_56 = F_1 ( V_3 , V_55 -> V_66 ,
V_55 -> V_61 ) ;
if ( ! V_56 ) {
F_12 ( L_26 ,
V_55 -> V_66 , V_55 -> V_61 ) ;
V_36 = - 1 ;
goto V_75;
}
V_57 = NULL ;
if ( ! V_55 -> V_76 || V_55 -> V_68 ) {
V_57 = F_1 ( V_3 , V_55 -> V_67 ,
V_55 -> V_69 ) ;
if ( ! V_57 ) {
F_12 ( L_27 ,
V_55 -> V_67 ,
V_55 -> V_69 ) ;
V_36 = - 1 ;
goto V_75;
}
}
if ( V_55 -> V_76 ) {
V_36 = F_30 ( V_3 , V_55 , V_56 ,
& V_57 ) ;
if ( V_36 )
goto V_75;
} else if ( V_55 -> V_77 ) {
V_36 = F_33 ( V_3 , V_55 , V_56 ,
& V_57 ) ;
if ( V_36 )
goto V_75;
}
V_74 -> V_7 = V_57 ;
F_19 ( & V_74 -> V_9 , & V_56 -> V_35 ) ;
F_37 ( & V_55 -> V_9 ) ;
free ( V_55 ) ;
}
V_75:
return V_36 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_11 * V_14 ,
struct V_1 * V_7 , struct V_15 * V_78 ,
struct V_15 * V_79 )
{
struct V_15 * V_15 = V_78 ;
struct V_1 * V_80 ;
struct V_73 * V_74 ;
F_39 (rela, &file->rodata->rela->rela_list, list) {
if ( V_15 == V_79 )
break;
if ( V_15 -> V_12 -> V_5 != V_7 -> V_5 ||
V_15 -> V_18 <= V_14 -> V_6 ||
V_15 -> V_18 >= V_14 -> V_6 + V_14 -> V_29 )
break;
V_80 = F_1 ( V_3 , V_7 -> V_5 , V_15 -> V_18 ) ;
if ( ! V_80 ) {
F_20 ( L_28 ,
V_3 -> V_81 -> V_15 -> V_13 , V_7 -> V_5 -> V_13 ,
V_15 -> V_18 ) ;
return - 1 ;
}
V_74 = malloc ( sizeof( * V_74 ) ) ;
if ( ! V_74 ) {
F_20 ( L_22 ) ;
return - 1 ;
}
V_74 -> V_7 = V_80 ;
F_19 ( & V_74 -> V_9 , & V_7 -> V_35 ) ;
}
return 0 ;
}
static struct V_15 * F_40 ( struct V_2 * V_3 ,
struct V_11 * V_14 ,
struct V_1 * V_7 )
{
struct V_15 * V_82 , * V_83 ;
struct V_1 * V_56 = V_7 ;
V_82 = F_28 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_29 ) ;
if ( V_82 && V_82 -> V_12 == V_3 -> V_81 -> V_12 ) {
V_83 = F_41 ( V_3 -> V_81 ,
V_82 -> V_18 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_41 ( V_3 -> V_81 ,
V_82 -> V_18 + 4 ) ;
if ( ! V_83 )
return NULL ;
V_3 -> V_84 = true ;
return V_83 ;
}
F_42 (file, func, insn) {
if ( V_7 -> type == V_34 )
break;
if ( V_7 -> type == V_30 &&
V_7 -> V_32 &&
( V_7 -> V_32 -> V_6 <= V_7 -> V_6 ||
V_7 -> V_32 -> V_6 > V_56 -> V_6 ) )
break;
V_82 = F_28 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_82 || V_82 -> V_12 != V_3 -> V_81 -> V_12 )
continue;
if ( F_43 ( V_3 -> V_81 , V_82 -> V_18 ) )
continue;
return F_41 ( V_3 -> V_81 , V_82 -> V_18 ) ;
}
return NULL ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_11 * V_14 )
{
struct V_1 * V_7 , * V_85 = NULL ;
struct V_15 * V_15 , * V_86 = NULL ;
int V_36 ;
F_8 (file, func, insn) {
if ( V_7 -> type != V_34 )
continue;
V_15 = F_40 ( V_3 , V_14 , V_7 ) ;
if ( ! V_15 )
continue;
if ( V_85 ) {
V_36 = F_38 ( V_3 , V_14 , V_85 , V_86 ,
V_15 ) ;
if ( V_36 )
return V_36 ;
}
V_85 = V_7 ;
V_86 = V_15 ;
}
if ( V_85 ) {
V_36 = F_38 ( V_3 , V_14 , V_85 , V_86 , NULL ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
int V_36 ;
if ( ! V_3 -> V_81 || ! V_3 -> V_81 -> V_15 )
return 0 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
V_36 = F_44 ( V_3 , V_14 ) ;
if ( V_36 )
return V_36 ;
}
}
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
int V_36 ;
V_36 = F_15 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_21 ( V_3 ) ;
if ( V_36 )
return V_36 ;
F_25 ( V_3 ) ;
V_36 = F_26 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_29 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_34 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_45 ( V_3 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
static bool F_47 ( struct V_1 * V_7 )
{
if ( V_7 -> type == V_53 &&
V_7 -> V_54 -> type == V_87 &&
! strcmp ( V_7 -> V_54 -> V_13 , L_29 ) )
return true ;
return false ;
}
static bool F_48 ( struct V_1 * V_7 )
{
return ( V_7 -> V_88 & V_89 ) ||
( V_7 -> V_88 & V_90 ) ;
}
static bool F_49 ( struct V_1 * V_7 )
{
return ( V_7 -> V_88 & V_89 ) &&
( V_7 -> V_88 & V_90 ) ;
}
static unsigned int F_50 ( unsigned long V_88 )
{
return ( V_88 & ( V_89 | V_90 ) ) ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_1 * V_91 , unsigned char V_92 )
{
struct V_73 * V_74 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_14 = NULL ;
unsigned char V_88 ;
int V_36 ;
V_7 = V_91 ;
V_5 = V_7 -> V_5 ;
V_88 = V_92 ;
if ( V_7 -> V_65 && F_13 ( & V_7 -> V_35 ) ) {
F_12 ( L_30 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
while ( 1 ) {
if ( V_3 -> V_93 && V_7 -> V_14 ) {
if ( V_14 && V_14 != V_7 -> V_14 ) {
F_20 ( L_31 ,
V_14 -> V_13 , V_7 -> V_14 -> V_13 ) ;
return 1 ;
}
V_14 = V_7 -> V_14 ;
}
if ( V_7 -> V_47 ) {
if ( F_50 ( V_7 -> V_88 ) != F_50 ( V_88 ) ) {
F_12 ( L_32 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
}
V_7 -> V_47 = true ;
V_7 -> V_88 = V_88 ;
F_6 (alt, &insn->alts, list) {
V_36 = F_51 ( V_3 , V_74 -> V_7 , V_88 ) ;
if ( V_36 )
return 1 ;
}
switch ( V_7 -> type ) {
case V_94 :
if ( ! V_95 ) {
if ( V_88 & V_89 ) {
F_12 ( L_33 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
V_88 |= V_89 ;
}
break;
case V_96 :
if ( ! V_95 ) {
if ( V_88 & V_90 ) {
F_12 ( L_34 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
V_88 |= V_90 ;
}
break;
case V_97 :
if ( ! V_95 ) {
if ( F_49 ( V_7 ) )
V_88 &= ~ V_90 ;
V_88 &= ~ V_89 ;
}
break;
case V_28 :
if ( ! V_95 && F_48 ( V_7 ) ) {
F_12 ( L_35 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
case V_53 :
if ( F_47 ( V_7 ) ) {
V_88 |= V_98 ;
break;
}
V_36 = F_14 ( V_3 , V_7 -> V_54 ) ;
if ( V_36 == 1 )
return 0 ;
if ( V_36 == - 1 )
return 1 ;
case V_99 :
if ( ! V_95 && ! F_49 ( V_7 ) ) {
F_12 ( L_36 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
break;
case V_50 :
case V_30 :
if ( V_7 -> V_32 ) {
V_36 = F_51 ( V_3 , V_7 -> V_32 ,
V_88 ) ;
if ( V_36 )
return 1 ;
} else if ( F_48 ( V_7 ) ) {
F_12 ( L_37 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_7 -> type == V_30 )
return 0 ;
break;
case V_34 :
if ( F_13 ( & V_7 -> V_35 ) &&
F_48 ( V_7 ) ) {
F_12 ( L_37 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
default:
break;
}
if ( V_7 -> V_46 )
return 0 ;
V_7 = F_3 ( V_3 , V_7 ) ;
if ( ! V_7 ) {
F_20 ( L_38 , V_5 -> V_13 ) ;
return 1 ;
}
}
return 0 ;
}
static bool F_52 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_53 &&
! strcmp ( V_7 -> V_54 -> V_13 , L_39 ) ) ;
}
static bool F_53 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_53 &&
! strcmp ( V_7 -> V_54 -> V_13 ,
L_40 ) ) ;
}
static bool F_54 ( struct V_11 * V_14 ,
struct V_1 * V_7 )
{
int V_22 ;
if ( V_7 -> type == V_64 )
return true ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
if ( F_52 ( V_7 ) || F_53 ( V_7 ) )
return true ;
if ( V_7 -> type == V_30 && V_7 -> V_32 ) {
V_7 = V_7 -> V_32 ;
continue;
}
if ( V_7 -> V_6 + V_7 -> V_29 >= V_14 -> V_6 + V_14 -> V_29 )
break;
V_7 = F_4 ( V_7 , V_9 ) ;
}
return false ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
struct V_1 * V_7 ;
int V_36 , V_100 = 0 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
V_7 = F_1 ( V_3 , V_5 , V_14 -> V_6 ) ;
if ( ! V_7 )
continue;
V_36 = F_51 ( V_3 , V_7 , 0 ) ;
V_100 += V_36 ;
}
}
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
F_8 (file, func, insn) {
if ( V_7 -> V_47 )
continue;
V_7 -> V_47 = true ;
if ( V_3 -> V_84 || V_100 ||
F_54 ( V_14 , V_7 ) )
continue;
if ( ! V_3 -> V_84 &&
F_5 ( V_3 ) ) {
V_3 -> V_84 = true ;
continue;
}
F_12 ( L_41 , V_7 -> V_5 , V_7 -> V_6 ) ;
V_100 ++ ;
}
}
}
return V_100 ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
int V_100 = 0 ;
F_27 (file, insn) {
if ( ! V_7 -> V_47 && V_7 -> type == V_28 ) {
F_12 ( L_42 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
V_100 ++ ;
}
}
return V_100 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_7 , * V_101 ;
struct V_73 * V_74 , * V_102 ;
F_36 (insn, tmpinsn, &file->insn_list, list) {
F_36 (alt, tmpalt, &insn->alts, list) {
F_37 ( & V_74 -> V_9 ) ;
free ( V_74 ) ;
}
F_37 ( & V_7 -> V_9 ) ;
F_58 ( & V_7 -> V_44 ) ;
free ( V_7 ) ;
}
F_59 ( V_3 -> V_40 ) ;
}
int F_60 ( int V_103 , const char * * V_104 )
{
struct V_2 V_3 ;
int V_36 , V_100 = 0 ;
const struct V_105 V_106 [] = {
F_61 ( 'f' , L_43 , & V_95 , L_44 ) ,
F_62 () ,
} ;
V_103 = F_63 ( V_103 , V_104 , V_106 , V_107 , 0 ) ;
if ( V_103 != 1 )
F_64 ( V_107 , V_106 ) ;
V_108 = V_104 [ 0 ] ;
V_3 . V_40 = F_65 ( V_108 ) ;
if ( ! V_3 . V_40 ) {
fprintf ( V_109 , L_45 , V_108 ) ;
return 1 ;
}
F_16 ( & V_3 . V_10 ) ;
F_66 ( V_3 . V_43 ) ;
V_3 . V_16 = F_22 ( V_3 . V_40 , L_46 ) ;
V_3 . V_81 = F_22 ( V_3 . V_40 , L_47 ) ;
V_3 . V_84 = false ;
V_3 . V_93 = F_22 ( V_3 . V_40 , L_48 ) ;
V_36 = F_46 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_75;
V_100 += V_36 ;
V_36 = F_55 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_75;
V_100 += V_36 ;
V_36 = F_56 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_75;
V_100 += V_36 ;
V_75:
F_57 ( & V_3 ) ;
if ( V_36 || V_100 )
return 0 ;
return 0 ;
}
