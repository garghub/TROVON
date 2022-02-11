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
static void F_21 ( struct V_2 * V_3 )
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
V_7 -> V_45 = true ;
}
}
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_15 * V_15 ;
struct V_4 * V_46 ;
unsigned long V_47 ;
F_23 (file, insn) {
if ( V_7 -> type != V_48 &&
V_7 -> type != V_30 )
continue;
if ( V_7 -> V_45 )
continue;
V_15 = F_24 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_15 ) {
V_46 = V_7 -> V_5 ;
V_47 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
} else if ( V_15 -> V_12 -> type == V_17 ) {
V_46 = V_15 -> V_12 -> V_5 ;
V_47 = V_15 -> V_18 + 4 ;
} else if ( V_15 -> V_12 -> V_5 -> V_49 ) {
V_46 = V_15 -> V_12 -> V_5 ;
V_47 = V_15 -> V_12 -> V_12 . V_50 + V_15 -> V_18 + 4 ;
} else {
V_7 -> V_32 = 0 ;
continue;
}
V_7 -> V_32 = F_1 ( V_3 , V_46 , V_47 ) ;
if ( ! V_7 -> V_32 ) {
if ( ! strcmp ( V_7 -> V_5 -> V_13 , L_14 ) )
continue;
F_12 ( L_15 ,
V_7 -> V_5 , V_7 -> V_6 , V_46 -> V_13 ,
V_47 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
unsigned long V_47 ;
struct V_15 * V_15 ;
F_23 (file, insn) {
if ( V_7 -> type != V_51 )
continue;
V_15 = F_24 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_15 ) {
V_47 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
V_7 -> V_52 = F_11 ( V_7 -> V_5 ,
V_47 ) ;
if ( ! V_7 -> V_52 ) {
F_12 ( L_16 ,
V_7 -> V_5 , V_7 -> V_6 , V_47 ) ;
return - 1 ;
}
} else if ( V_15 -> V_12 -> type == V_17 ) {
V_7 -> V_52 = F_11 ( V_15 -> V_12 -> V_5 ,
V_15 -> V_18 + 4 ) ;
if ( ! V_7 -> V_52 ||
V_7 -> V_52 -> type != V_19 ) {
F_12 ( L_17 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_15 -> V_12 -> V_5 -> V_13 ,
V_15 -> V_18 + 4 ) ;
return - 1 ;
}
} else
V_7 -> V_52 = V_15 -> V_12 ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_53 * V_53 ,
struct V_1 * V_54 ,
struct V_1 * * V_55 )
{
struct V_1 * V_56 , * V_57 , * V_7 , * V_58 ;
unsigned long V_47 ;
V_56 = NULL ;
V_7 = V_54 ;
F_27 (file, insn) {
if ( V_7 -> V_6 >= V_53 -> V_59 + V_53 -> V_60 )
break;
if ( V_53 -> V_61 )
V_7 -> type = V_62 ;
V_7 -> V_63 = true ;
V_56 = V_7 ;
}
if ( ! F_3 ( V_3 , V_56 ) ) {
F_20 ( L_18 ,
V_53 -> V_64 -> V_13 ) ;
return - 1 ;
}
V_58 = malloc ( sizeof( * V_58 ) ) ;
if ( ! V_58 ) {
F_20 ( L_19 ) ;
return - 1 ;
}
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
F_16 ( & V_58 -> V_35 ) ;
V_58 -> V_5 = V_53 -> V_65 ;
V_58 -> V_6 = - 1 ;
V_58 -> type = V_30 ;
V_58 -> V_32 = F_4 ( V_56 , V_9 ) ;
if ( ! V_53 -> V_66 ) {
* V_55 = V_58 ;
return 0 ;
}
V_57 = NULL ;
V_7 = * V_55 ;
F_27 (file, insn) {
if ( V_7 -> V_6 >= V_53 -> V_67 + V_53 -> V_66 )
break;
V_57 = V_7 ;
if ( V_7 -> type != V_48 &&
V_7 -> type != V_30 )
continue;
if ( ! V_7 -> V_41 )
continue;
V_47 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
if ( V_47 == V_53 -> V_67 + V_53 -> V_66 )
V_7 -> V_32 = V_58 ;
if ( ! V_7 -> V_32 ) {
F_12 ( L_20 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
}
if ( ! V_57 ) {
F_12 ( L_21 ,
V_53 -> V_65 , V_53 -> V_67 ) ;
return - 1 ;
}
F_28 ( & V_58 -> V_9 , & V_57 -> V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_53 * V_53 ,
struct V_1 * V_54 ,
struct V_1 * * V_55 )
{
if ( V_54 -> type == V_62 )
return 0 ;
if ( V_54 -> type != V_30 ) {
F_12 ( L_22 ,
V_54 -> V_5 , V_54 -> V_6 ) ;
return - 1 ;
}
* V_55 = F_4 ( V_54 , V_9 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_68 V_69 ;
struct V_1 * V_54 , * V_55 ;
struct V_53 * V_53 , * V_70 ;
struct V_71 * V_72 ;
int V_36 ;
V_36 = F_31 ( V_3 -> V_40 , & V_69 ) ;
if ( V_36 )
return V_36 ;
F_32 (special_alt, tmp, &special_alts, list) {
V_72 = malloc ( sizeof( * V_72 ) ) ;
if ( ! V_72 ) {
F_20 ( L_19 ) ;
V_36 = - 1 ;
goto V_73;
}
V_54 = F_1 ( V_3 , V_53 -> V_64 ,
V_53 -> V_59 ) ;
if ( ! V_54 ) {
F_12 ( L_23 ,
V_53 -> V_64 , V_53 -> V_59 ) ;
V_36 = - 1 ;
goto V_73;
}
V_55 = NULL ;
if ( ! V_53 -> V_74 || V_53 -> V_66 ) {
V_55 = F_1 ( V_3 , V_53 -> V_65 ,
V_53 -> V_67 ) ;
if ( ! V_55 ) {
F_12 ( L_24 ,
V_53 -> V_65 ,
V_53 -> V_67 ) ;
V_36 = - 1 ;
goto V_73;
}
}
if ( V_53 -> V_74 ) {
V_36 = F_26 ( V_3 , V_53 , V_54 ,
& V_55 ) ;
if ( V_36 )
goto V_73;
} else if ( V_53 -> V_75 ) {
V_36 = F_29 ( V_3 , V_53 , V_54 ,
& V_55 ) ;
if ( V_36 )
goto V_73;
}
V_72 -> V_7 = V_55 ;
F_19 ( & V_72 -> V_9 , & V_54 -> V_35 ) ;
F_33 ( & V_53 -> V_9 ) ;
free ( V_53 ) ;
}
V_73:
return V_36 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_11 * V_14 ,
struct V_1 * V_7 , struct V_15 * V_76 ,
struct V_15 * V_77 )
{
struct V_15 * V_15 = V_76 ;
struct V_1 * V_78 ;
struct V_71 * V_72 ;
F_35 (rela, &file->rodata->rela->rela_list, list) {
if ( V_15 == V_77 )
break;
if ( V_15 -> V_12 -> V_5 != V_7 -> V_5 ||
V_15 -> V_18 <= V_14 -> V_6 ||
V_15 -> V_18 >= V_14 -> V_6 + V_14 -> V_29 )
break;
V_78 = F_1 ( V_3 , V_7 -> V_5 , V_15 -> V_18 ) ;
if ( ! V_78 ) {
F_20 ( L_25 ,
V_3 -> V_79 -> V_15 -> V_13 , V_7 -> V_5 -> V_13 ,
V_15 -> V_18 ) ;
return - 1 ;
}
V_72 = malloc ( sizeof( * V_72 ) ) ;
if ( ! V_72 ) {
F_20 ( L_19 ) ;
return - 1 ;
}
V_72 -> V_7 = V_78 ;
F_19 ( & V_72 -> V_9 , & V_7 -> V_35 ) ;
}
return 0 ;
}
static struct V_15 * F_36 ( struct V_2 * V_3 ,
struct V_11 * V_14 ,
struct V_1 * V_7 )
{
struct V_15 * V_80 , * V_81 ;
struct V_1 * V_54 = V_7 ;
V_80 = F_24 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_29 ) ;
if ( V_80 && V_80 -> V_12 == V_3 -> V_79 -> V_12 ) {
V_81 = F_37 ( V_3 -> V_79 ,
V_80 -> V_18 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_37 ( V_3 -> V_79 ,
V_80 -> V_18 + 4 ) ;
if ( ! V_81 )
return NULL ;
V_3 -> V_82 = true ;
return V_81 ;
}
F_38 (file, func, insn) {
if ( V_7 -> type == V_34 )
break;
if ( V_7 -> type == V_30 &&
V_7 -> V_32 &&
( V_7 -> V_32 -> V_6 <= V_7 -> V_6 ||
V_7 -> V_32 -> V_6 > V_54 -> V_6 ) )
break;
V_80 = F_24 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( V_80 && V_80 -> V_12 == V_3 -> V_79 -> V_12 )
return F_37 ( V_3 -> V_79 ,
V_80 -> V_18 ) ;
}
return NULL ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_11 * V_14 )
{
struct V_1 * V_7 , * V_83 = NULL ;
struct V_15 * V_15 , * V_84 = NULL ;
int V_36 ;
F_8 (file, func, insn) {
if ( V_7 -> type != V_34 )
continue;
V_15 = F_36 ( V_3 , V_14 , V_7 ) ;
if ( ! V_15 )
continue;
if ( V_83 ) {
V_36 = F_34 ( V_3 , V_14 , V_83 , V_84 ,
V_15 ) ;
if ( V_36 )
return V_36 ;
}
V_83 = V_7 ;
V_84 = V_15 ;
}
if ( V_83 ) {
V_36 = F_34 ( V_3 , V_14 , V_83 , V_84 , NULL ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
int V_36 ;
if ( ! V_3 -> V_79 || ! V_3 -> V_79 -> V_15 )
return 0 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
V_36 = F_39 ( V_3 , V_14 ) ;
if ( V_36 )
return V_36 ;
}
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
int V_36 ;
V_36 = F_15 ( V_3 ) ;
if ( V_36 )
return V_36 ;
F_21 ( V_3 ) ;
V_36 = F_22 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_25 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_30 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_40 ( V_3 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
static bool F_42 ( struct V_1 * V_7 )
{
if ( V_7 -> type == V_51 &&
V_7 -> V_52 -> type == V_85 &&
! strcmp ( V_7 -> V_52 -> V_13 , L_26 ) )
return true ;
return false ;
}
static bool F_43 ( struct V_1 * V_7 )
{
return ( V_7 -> V_86 & V_87 ) ||
( V_7 -> V_86 & V_88 ) ;
}
static bool F_44 ( struct V_1 * V_7 )
{
return ( V_7 -> V_86 & V_87 ) &&
( V_7 -> V_86 & V_88 ) ;
}
static unsigned int F_45 ( unsigned long V_86 )
{
return ( V_86 & ( V_87 | V_88 ) ) ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_1 * V_89 , unsigned char V_90 )
{
struct V_71 * V_72 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_14 = NULL ;
unsigned char V_86 ;
int V_36 ;
V_7 = V_89 ;
V_5 = V_7 -> V_5 ;
V_86 = V_90 ;
if ( V_7 -> V_63 && F_13 ( & V_7 -> V_35 ) ) {
F_12 ( L_27 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
while ( 1 ) {
if ( V_3 -> V_91 && V_7 -> V_14 ) {
if ( V_14 && V_14 != V_7 -> V_14 ) {
F_20 ( L_28 ,
V_14 -> V_13 , V_7 -> V_14 -> V_13 ) ;
return 1 ;
}
V_14 = V_7 -> V_14 ;
}
if ( V_7 -> V_45 ) {
if ( F_45 ( V_7 -> V_86 ) != F_45 ( V_86 ) ) {
F_12 ( L_29 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
}
V_7 -> V_45 = true ;
V_7 -> V_86 = V_86 ;
F_6 (alt, &insn->alts, list) {
V_36 = F_46 ( V_3 , V_72 -> V_7 , V_86 ) ;
if ( V_36 )
return 1 ;
}
switch ( V_7 -> type ) {
case V_92 :
if ( ! V_93 ) {
if ( V_86 & V_87 ) {
F_12 ( L_30 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
V_86 |= V_87 ;
}
break;
case V_94 :
if ( ! V_93 ) {
if ( V_86 & V_88 ) {
F_12 ( L_31 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
V_86 |= V_88 ;
}
break;
case V_95 :
if ( ! V_93 ) {
if ( F_44 ( V_7 ) )
V_86 &= ~ V_88 ;
V_86 &= ~ V_87 ;
}
break;
case V_28 :
if ( ! V_93 && F_43 ( V_7 ) ) {
F_12 ( L_32 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
case V_51 :
if ( F_42 ( V_7 ) ) {
V_86 |= V_96 ;
break;
}
V_36 = F_14 ( V_3 , V_7 -> V_52 ) ;
if ( V_36 == 1 )
return 0 ;
if ( V_36 == - 1 )
return 1 ;
case V_97 :
if ( ! V_93 && ! F_44 ( V_7 ) ) {
F_12 ( L_33 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
break;
case V_48 :
case V_30 :
if ( V_7 -> V_32 ) {
V_36 = F_46 ( V_3 , V_7 -> V_32 ,
V_86 ) ;
if ( V_36 )
return 1 ;
} else if ( F_43 ( V_7 ) ) {
F_12 ( L_34 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_7 -> type == V_30 )
return 0 ;
break;
case V_34 :
if ( F_13 ( & V_7 -> V_35 ) &&
F_43 ( V_7 ) ) {
F_12 ( L_34 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
case V_98 :
return 0 ;
default:
break;
}
V_7 = F_3 ( V_3 , V_7 ) ;
if ( ! V_7 ) {
F_20 ( L_35 , V_5 -> V_13 ) ;
return 1 ;
}
}
return 0 ;
}
static bool F_47 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_51 &&
! strcmp ( V_7 -> V_52 -> V_13 , L_36 ) ) ;
}
static bool F_48 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_51 &&
! strcmp ( V_7 -> V_52 -> V_13 ,
L_37 ) ) ;
}
static bool F_49 ( struct V_11 * V_14 ,
struct V_1 * V_7 )
{
int V_22 ;
if ( V_7 -> type == V_62 )
return true ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ ) {
if ( F_47 ( V_7 ) || F_48 ( V_7 ) )
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
static int F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_14 ;
struct V_1 * V_7 ;
int V_36 , V_99 = 0 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
V_7 = F_1 ( V_3 , V_5 , V_14 -> V_6 ) ;
if ( ! V_7 )
continue;
V_36 = F_46 ( V_3 , V_7 , 0 ) ;
V_99 += V_36 ;
}
}
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_14 -> type != V_19 )
continue;
F_8 (file, func, insn) {
if ( V_7 -> V_45 )
continue;
V_7 -> V_45 = true ;
if ( V_3 -> V_82 || V_99 ||
F_49 ( V_14 , V_7 ) )
continue;
if ( ! V_3 -> V_82 &&
F_5 ( V_3 ) ) {
V_3 -> V_82 = true ;
continue;
}
F_12 ( L_38 , V_7 -> V_5 , V_7 -> V_6 ) ;
V_99 ++ ;
}
}
}
return V_99 ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
int V_99 = 0 ;
F_23 (file, insn) {
if ( ! V_7 -> V_45 && V_7 -> type == V_28 ) {
F_12 ( L_39 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
V_99 ++ ;
}
}
return V_99 ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_7 , * V_100 ;
struct V_71 * V_72 , * V_101 ;
F_32 (insn, tmpinsn, &file->insn_list, list) {
F_32 (alt, tmpalt, &insn->alts, list) {
F_33 ( & V_72 -> V_9 ) ;
free ( V_72 ) ;
}
F_33 ( & V_7 -> V_9 ) ;
F_53 ( & V_7 -> V_44 ) ;
free ( V_7 ) ;
}
F_54 ( V_3 -> V_40 ) ;
}
int F_55 ( int V_102 , const char * * V_103 )
{
struct V_2 V_3 ;
int V_36 , V_99 = 0 ;
const struct V_104 V_105 [] = {
F_56 ( 'f' , L_40 , & V_93 , L_41 ) ,
F_57 () ,
} ;
V_102 = F_58 ( V_102 , V_103 , V_105 , V_106 , 0 ) ;
if ( V_102 != 1 )
F_59 ( V_106 , V_105 ) ;
V_107 = V_103 [ 0 ] ;
V_3 . V_40 = F_60 ( V_107 ) ;
if ( ! V_3 . V_40 ) {
fprintf ( V_108 , L_42 , V_107 ) ;
return 1 ;
}
F_16 ( & V_3 . V_10 ) ;
F_61 ( V_3 . V_43 ) ;
V_3 . V_16 = F_62 ( V_3 . V_40 , L_43 ) ;
V_3 . V_79 = F_62 ( V_3 . V_40 , L_44 ) ;
V_3 . V_82 = false ;
V_3 . V_91 = F_62 ( V_3 . V_40 , L_45 ) ;
V_36 = F_41 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_73;
V_99 += V_36 ;
V_36 = F_50 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_73;
V_99 += V_36 ;
V_36 = F_51 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_73;
V_99 += V_36 ;
V_73:
F_52 ( & V_3 ) ;
if ( V_36 || V_99 )
return 0 ;
return 0 ;
}
