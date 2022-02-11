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
static bool F_5 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
struct V_13 * V_13 ;
struct V_1 * V_7 ;
if ( V_3 -> V_14 && V_3 -> V_14 -> V_13 )
F_6 (rela, &file->whitelist->rela->rela_list, list) {
if ( V_13 -> V_15 -> type == V_16 &&
V_13 -> V_15 -> V_5 == V_12 -> V_5 &&
V_13 -> V_17 == V_12 -> V_6 )
return true ;
if ( V_13 -> V_15 -> type == V_18 && V_13 -> V_15 == V_12 )
return true ;
}
F_7 (file, func, insn)
if ( V_7 -> type == V_19 )
return true ;
return false ;
}
static int F_8 ( struct V_2 * V_3 , struct V_11 * V_12 ,
int V_20 )
{
int V_21 ;
struct V_1 * V_7 ;
bool V_22 = true ;
static const char * const V_23 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8
} ;
if ( V_12 -> V_24 == V_25 )
return 0 ;
if ( V_12 -> V_24 == V_26 )
for ( V_21 = 0 ; V_21 < F_9 ( V_23 ) ; V_21 ++ )
if ( ! strcmp ( V_12 -> V_27 , V_23 [ V_21 ] ) )
return 1 ;
if ( ! V_12 -> V_5 )
return 0 ;
F_7 (file, func, insn) {
V_22 = false ;
if ( V_7 -> type == V_28 )
return 0 ;
}
if ( V_22 )
return 0 ;
F_7 (file, func, insn) {
if ( V_7 -> V_5 != V_12 -> V_5 ||
V_7 -> V_6 >= V_12 -> V_6 + V_12 -> V_29 )
break;
if ( V_7 -> type == V_30 ) {
struct V_1 * V_31 = V_7 -> V_32 ;
struct V_11 * V_33 ;
if ( ! V_31 )
return 0 ;
if ( V_31 -> V_5 != V_12 -> V_5 ||
V_31 -> V_6 < V_12 -> V_6 ||
V_31 -> V_6 >= V_12 -> V_6 + V_12 -> V_29 ) {
V_33 = F_10 ( V_31 -> V_5 ,
V_31 -> V_6 ) ;
if ( ! V_33 )
continue;
if ( V_20 == 5 ) {
F_11 ( L_9 ,
V_31 -> V_5 , V_31 -> V_6 ) ;
return - 1 ;
}
return F_8 ( V_3 , V_33 ,
V_20 + 1 ) ;
}
}
if ( V_7 -> type == V_34 && F_12 ( & V_7 -> V_35 ) )
return 0 ;
}
return 1 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
return F_8 ( V_3 , V_12 , 0 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
unsigned long V_6 ;
struct V_1 * V_7 ;
int V_36 ;
F_6 (sec, &file->elf->sections, list) {
if ( ! ( V_5 -> V_37 . V_38 & V_39 ) )
continue;
for ( V_6 = 0 ; V_6 < V_5 -> V_29 ; V_6 += V_7 -> V_29 ) {
V_7 = malloc ( sizeof( * V_7 ) ) ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
F_15 ( & V_7 -> V_35 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_6 = V_6 ;
V_36 = F_16 ( V_3 -> V_40 , V_5 , V_6 ,
V_5 -> V_29 - V_6 ,
& V_7 -> V_29 , & V_7 -> type ,
& V_7 -> V_41 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_7 -> type || V_7 -> type > V_42 ) {
F_11 ( L_10 ,
V_7 -> V_5 , V_7 -> V_6 , V_7 -> type ) ;
return - 1 ;
}
F_17 ( V_3 -> V_43 , & V_7 -> V_44 , V_7 -> V_6 ) ;
F_18 ( & V_7 -> V_9 , & V_3 -> V_10 ) ;
}
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
if ( ! F_1 ( V_3 , V_5 , V_12 -> V_6 ) ) {
F_19 ( L_11 ,
V_12 -> V_27 ) ;
return - 1 ;
}
F_7 (file, func, insn)
if ( ! V_7 -> V_12 )
V_7 -> V_12 = V_12 ;
}
}
return 0 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
if ( ! F_5 ( V_3 , V_12 ) )
continue;
F_7 (file, func, insn)
V_7 -> V_45 = true ;
}
}
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_13 * V_13 ;
struct V_4 * V_46 ;
unsigned long V_47 ;
F_22 (file, insn) {
if ( V_7 -> type != V_48 &&
V_7 -> type != V_30 )
continue;
if ( V_7 -> V_45 )
continue;
V_13 = F_23 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_13 ) {
V_46 = V_7 -> V_5 ;
V_47 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
} else if ( V_13 -> V_15 -> type == V_16 ) {
V_46 = V_13 -> V_15 -> V_5 ;
V_47 = V_13 -> V_17 + 4 ;
} else if ( V_13 -> V_15 -> V_5 -> V_49 ) {
V_46 = V_13 -> V_15 -> V_5 ;
V_47 = V_13 -> V_15 -> V_15 . V_50 + V_13 -> V_17 + 4 ;
} else {
V_7 -> V_32 = 0 ;
continue;
}
V_7 -> V_32 = F_1 ( V_3 , V_46 , V_47 ) ;
if ( ! V_7 -> V_32 ) {
if ( ! strcmp ( V_7 -> V_5 -> V_27 , L_12 ) )
continue;
F_11 ( L_13 ,
V_7 -> V_5 , V_7 -> V_6 , V_46 -> V_27 ,
V_47 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
unsigned long V_47 ;
struct V_13 * V_13 ;
F_22 (file, insn) {
if ( V_7 -> type != V_51 )
continue;
V_13 = F_23 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_13 ) {
V_47 = V_7 -> V_6 + V_7 -> V_29 + V_7 -> V_41 ;
V_7 -> V_52 = F_10 ( V_7 -> V_5 ,
V_47 ) ;
if ( ! V_7 -> V_52 ) {
F_11 ( L_14 ,
V_7 -> V_5 , V_7 -> V_6 , V_47 ) ;
return - 1 ;
}
} else if ( V_13 -> V_15 -> type == V_16 ) {
V_7 -> V_52 = F_10 ( V_13 -> V_15 -> V_5 ,
V_13 -> V_17 + 4 ) ;
if ( ! V_7 -> V_52 ||
V_7 -> V_52 -> type != V_18 ) {
F_11 ( L_15 ,
V_7 -> V_5 , V_7 -> V_6 ,
V_13 -> V_15 -> V_5 -> V_27 ,
V_13 -> V_17 + 4 ) ;
return - 1 ;
}
} else
V_7 -> V_52 = V_13 -> V_15 ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_53 * V_53 ,
struct V_1 * V_54 ,
struct V_1 * * V_55 )
{
struct V_1 * V_56 , * V_57 , * V_7 , * V_58 ;
unsigned long V_47 ;
V_56 = NULL ;
V_7 = V_54 ;
F_26 (file, insn) {
if ( V_7 -> V_6 >= V_53 -> V_59 + V_53 -> V_60 )
break;
if ( V_53 -> V_61 )
V_7 -> type = V_62 ;
V_7 -> V_63 = true ;
V_56 = V_7 ;
}
if ( ! F_3 ( V_3 , V_56 ) ) {
F_19 ( L_16 ,
V_53 -> V_64 -> V_27 ) ;
return - 1 ;
}
V_58 = malloc ( sizeof( * V_58 ) ) ;
if ( ! V_58 ) {
F_19 ( L_17 ) ;
return - 1 ;
}
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
F_15 ( & V_58 -> V_35 ) ;
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
F_26 (file, insn) {
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
F_11 ( L_18 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
return - 1 ;
}
}
if ( ! V_57 ) {
F_11 ( L_19 ,
V_53 -> V_65 , V_53 -> V_67 ) ;
return - 1 ;
}
F_27 ( & V_58 -> V_9 , & V_57 -> V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_53 * V_53 ,
struct V_1 * V_54 ,
struct V_1 * * V_55 )
{
if ( V_54 -> type == V_62 )
return 0 ;
if ( V_54 -> type != V_30 ) {
F_11 ( L_20 ,
V_54 -> V_5 , V_54 -> V_6 ) ;
return - 1 ;
}
* V_55 = F_4 ( V_54 , V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_68 V_69 ;
struct V_1 * V_54 , * V_55 ;
struct V_53 * V_53 , * V_70 ;
struct V_71 * V_72 ;
int V_36 ;
V_36 = F_30 ( V_3 -> V_40 , & V_69 ) ;
if ( V_36 )
return V_36 ;
F_31 (special_alt, tmp, &special_alts, list) {
V_72 = malloc ( sizeof( * V_72 ) ) ;
if ( ! V_72 ) {
F_19 ( L_17 ) ;
V_36 = - 1 ;
goto V_73;
}
V_54 = F_1 ( V_3 , V_53 -> V_64 ,
V_53 -> V_59 ) ;
if ( ! V_54 ) {
F_11 ( L_21 ,
V_53 -> V_64 , V_53 -> V_59 ) ;
V_36 = - 1 ;
goto V_73;
}
V_55 = NULL ;
if ( ! V_53 -> V_74 || V_53 -> V_66 ) {
V_55 = F_1 ( V_3 , V_53 -> V_65 ,
V_53 -> V_67 ) ;
if ( ! V_55 ) {
F_11 ( L_22 ,
V_53 -> V_65 ,
V_53 -> V_67 ) ;
V_36 = - 1 ;
goto V_73;
}
}
if ( V_53 -> V_74 ) {
V_36 = F_25 ( V_3 , V_53 , V_54 ,
& V_55 ) ;
if ( V_36 )
goto V_73;
} else if ( V_53 -> V_75 ) {
V_36 = F_28 ( V_3 , V_53 , V_54 ,
& V_55 ) ;
if ( V_36 )
goto V_73;
}
V_72 -> V_7 = V_55 ;
F_18 ( & V_72 -> V_9 , & V_54 -> V_35 ) ;
F_32 ( & V_53 -> V_9 ) ;
free ( V_53 ) ;
}
V_73:
return V_36 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_11 * V_12 ,
struct V_1 * V_7 , struct V_13 * V_76 ,
struct V_13 * V_77 )
{
struct V_13 * V_13 = V_76 ;
struct V_1 * V_78 ;
struct V_71 * V_72 ;
F_34 (rela, &file->rodata->rela->rela_list, list) {
if ( V_13 == V_77 )
break;
if ( V_13 -> V_15 -> V_5 != V_7 -> V_5 ||
V_13 -> V_17 <= V_12 -> V_6 ||
V_13 -> V_17 >= V_12 -> V_6 + V_12 -> V_29 )
break;
V_78 = F_1 ( V_3 , V_7 -> V_5 , V_13 -> V_17 ) ;
if ( ! V_78 ) {
F_19 ( L_23 ,
V_3 -> V_79 -> V_13 -> V_27 , V_7 -> V_5 -> V_27 ,
V_13 -> V_17 ) ;
return - 1 ;
}
V_72 = malloc ( sizeof( * V_72 ) ) ;
if ( ! V_72 ) {
F_19 ( L_17 ) ;
return - 1 ;
}
V_72 -> V_7 = V_78 ;
F_18 ( & V_72 -> V_9 , & V_7 -> V_35 ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_7 , * V_80 ;
struct V_13 * V_81 , * V_82 , * V_83 ;
int V_36 ;
V_80 = NULL ;
F_7 (file, func, insn) {
if ( V_7 -> type != V_34 )
continue;
V_81 = F_23 ( V_7 -> V_5 , V_7 -> V_6 ,
V_7 -> V_29 ) ;
if ( ! V_81 || V_81 -> V_15 != V_3 -> V_79 -> V_15 )
continue;
V_82 = F_36 ( V_3 -> V_79 ,
V_81 -> V_17 ) ;
if ( ! V_82 ) {
V_82 = F_36 ( V_3 -> V_79 ,
V_81 -> V_17 + 4 ) ;
if ( V_82 )
V_3 -> V_84 = true ;
}
if ( ! V_82 )
continue;
if ( V_80 ) {
V_36 = F_33 ( V_3 , V_12 , V_80 , V_83 ,
V_82 ) ;
if ( V_36 )
return V_36 ;
}
V_80 = V_7 ;
V_83 = V_82 ;
}
if ( V_80 ) {
V_36 = F_33 ( V_3 , V_12 , V_80 , V_83 , NULL ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
int V_36 ;
if ( ! V_3 -> V_79 || ! V_3 -> V_79 -> V_13 )
return 0 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
V_36 = F_35 ( V_3 , V_12 ) ;
if ( V_36 )
return V_36 ;
}
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
int V_36 ;
V_36 = F_14 ( V_3 ) ;
if ( V_36 )
return V_36 ;
F_20 ( V_3 ) ;
V_36 = F_21 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_24 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_29 ( V_3 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_37 ( V_3 ) ;
if ( V_36 )
return V_36 ;
return 0 ;
}
static bool F_39 ( struct V_1 * V_7 )
{
if ( V_7 -> type == V_51 &&
V_7 -> V_52 -> type == V_85 &&
! strcmp ( V_7 -> V_52 -> V_27 , L_24 ) )
return true ;
return false ;
}
static bool F_40 ( struct V_1 * V_7 )
{
return ( V_7 -> V_86 & V_87 ) ||
( V_7 -> V_86 & V_88 ) ;
}
static bool F_41 ( struct V_1 * V_7 )
{
return ( V_7 -> V_86 & V_87 ) &&
( V_7 -> V_86 & V_88 ) ;
}
static unsigned int F_42 ( unsigned long V_86 )
{
return ( V_86 & ( V_87 | V_88 ) ) ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_1 * V_89 , unsigned char V_90 )
{
struct V_71 * V_72 ;
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_11 * V_12 = NULL ;
unsigned char V_86 ;
int V_36 ;
V_7 = V_89 ;
V_5 = V_7 -> V_5 ;
V_86 = V_90 ;
if ( V_7 -> V_63 && F_12 ( & V_7 -> V_35 ) ) {
F_11 ( L_25 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
while ( 1 ) {
if ( V_3 -> V_91 && V_7 -> V_12 ) {
if ( V_12 && V_12 != V_7 -> V_12 ) {
F_19 ( L_26 ,
V_12 -> V_27 , V_7 -> V_12 -> V_27 ) ;
return 1 ;
}
V_12 = V_7 -> V_12 ;
}
if ( V_7 -> V_45 ) {
if ( F_42 ( V_7 -> V_86 ) != F_42 ( V_86 ) ) {
F_11 ( L_27 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
}
V_7 -> V_45 = true ;
V_7 -> V_86 = V_86 ;
F_6 (alt, &insn->alts, list) {
V_36 = F_43 ( V_3 , V_72 -> V_7 , V_86 ) ;
if ( V_36 )
return 1 ;
}
switch ( V_7 -> type ) {
case V_92 :
if ( ! V_93 ) {
if ( V_86 & V_87 ) {
F_11 ( L_28 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
V_86 |= V_87 ;
}
break;
case V_94 :
if ( ! V_93 ) {
if ( V_86 & V_88 ) {
F_11 ( L_29 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
V_86 |= V_88 ;
}
break;
case V_95 :
if ( ! V_93 ) {
if ( F_41 ( V_7 ) )
V_86 &= ~ V_88 ;
V_86 &= ~ V_87 ;
}
break;
case V_28 :
if ( ! V_93 && F_40 ( V_7 ) ) {
F_11 ( L_30 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
return 0 ;
case V_51 :
if ( F_39 ( V_7 ) ) {
V_86 |= V_96 ;
break;
}
V_36 = F_13 ( V_3 , V_7 -> V_52 ) ;
if ( V_36 == 1 )
return 0 ;
if ( V_36 == - 1 )
return 1 ;
case V_97 :
if ( ! V_93 && ! F_41 ( V_7 ) ) {
F_11 ( L_31 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
break;
case V_48 :
case V_30 :
if ( V_7 -> V_32 ) {
V_36 = F_43 ( V_3 , V_7 -> V_32 ,
V_86 ) ;
if ( V_36 )
return 1 ;
} else if ( F_40 ( V_7 ) ) {
F_11 ( L_32 ,
V_5 , V_7 -> V_6 ) ;
return 1 ;
}
if ( V_7 -> type == V_30 )
return 0 ;
break;
case V_34 :
if ( F_12 ( & V_7 -> V_35 ) &&
F_40 ( V_7 ) ) {
F_11 ( L_32 ,
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
F_19 ( L_33 , V_5 -> V_27 ) ;
return 1 ;
}
}
return 0 ;
}
static bool F_44 ( struct V_1 * V_7 )
{
struct V_13 * V_13 ;
struct V_4 * V_5 ;
struct V_11 * V_15 ;
unsigned long V_6 ;
V_13 = F_23 ( V_7 -> V_5 , V_7 -> V_6 , V_7 -> V_29 ) ;
if ( ! V_13 )
return false ;
if ( V_13 -> V_15 -> type != V_16 )
return false ;
V_5 = V_13 -> V_15 -> V_5 ;
V_6 = V_13 -> V_17 + V_7 -> V_6 + V_7 -> V_29 - V_13 -> V_6 ;
F_6 (sym, &sec->symbol_list, list) {
if ( V_15 -> type != V_99 )
continue;
if ( V_6 >= V_15 -> V_6 && V_6 < V_15 -> V_6 + V_15 -> V_29 )
return ( ! memcmp ( V_15 -> V_27 , L_34 , 8 ) ) ;
}
return false ;
}
static bool F_45 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_51 &&
! strcmp ( V_7 -> V_52 -> V_27 , L_35 ) ) ;
}
static bool F_46 ( struct V_1 * V_7 )
{
return ( V_7 -> type == V_51 &&
! strcmp ( V_7 -> V_52 -> V_27 ,
L_36 ) ) ;
}
static bool F_47 ( struct V_11 * V_12 ,
struct V_1 * V_7 )
{
int V_21 ;
if ( V_7 -> type == V_62 )
return true ;
if ( F_44 ( V_7 ) )
return true ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
if ( F_45 ( V_7 ) || F_46 ( V_7 ) )
return true ;
if ( V_7 -> type == V_30 && V_7 -> V_32 ) {
V_7 = V_7 -> V_32 ;
continue;
}
if ( V_7 -> V_6 + V_7 -> V_29 >= V_12 -> V_6 + V_12 -> V_29 )
break;
V_7 = F_4 ( V_7 , V_9 ) ;
}
return false ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_11 * V_12 ;
struct V_1 * V_7 ;
int V_36 , V_100 = 0 ;
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
V_7 = F_1 ( V_3 , V_5 , V_12 -> V_6 ) ;
if ( ! V_7 )
continue;
V_36 = F_43 ( V_3 , V_7 , 0 ) ;
V_100 += V_36 ;
}
}
F_6 (sec, &file->elf->sections, list) {
F_6 (func, &sec->symbol_list, list) {
if ( V_12 -> type != V_18 )
continue;
F_7 (file, func, insn) {
if ( V_7 -> V_45 )
continue;
V_7 -> V_45 = true ;
if ( V_3 -> V_84 || V_100 ||
F_47 ( V_12 , V_7 ) )
continue;
F_11 ( L_37 , V_7 -> V_5 , V_7 -> V_6 ) ;
V_100 ++ ;
}
}
}
return V_100 ;
}
static int F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
int V_100 = 0 ;
F_22 (file, insn) {
if ( ! V_7 -> V_45 && V_7 -> type == V_28 ) {
F_11 ( L_38 ,
V_7 -> V_5 , V_7 -> V_6 ) ;
V_100 ++ ;
}
}
return V_100 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_7 , * V_101 ;
struct V_71 * V_72 , * V_102 ;
F_31 (insn, tmpinsn, &file->insn_list, list) {
F_31 (alt, tmpalt, &insn->alts, list) {
F_32 ( & V_72 -> V_9 ) ;
free ( V_72 ) ;
}
F_32 ( & V_7 -> V_9 ) ;
F_51 ( & V_7 -> V_44 ) ;
free ( V_7 ) ;
}
F_52 ( V_3 -> V_40 ) ;
}
int F_53 ( int V_103 , const char * * V_104 )
{
struct V_2 V_3 ;
int V_36 , V_100 = 0 ;
const struct V_105 V_106 [] = {
F_54 ( 'f' , L_39 , & V_93 , L_40 ) ,
F_55 () ,
} ;
V_103 = F_56 ( V_103 , V_104 , V_106 , V_107 , 0 ) ;
if ( V_103 != 1 )
F_57 ( V_107 , V_106 ) ;
V_108 = V_104 [ 0 ] ;
V_3 . V_40 = F_58 ( V_108 ) ;
if ( ! V_3 . V_40 ) {
fprintf ( V_109 , L_41 , V_108 ) ;
return 1 ;
}
F_15 ( & V_3 . V_10 ) ;
F_59 ( V_3 . V_43 ) ;
V_3 . V_14 = F_60 ( V_3 . V_40 , L_42 ) ;
V_3 . V_79 = F_60 ( V_3 . V_40 , L_43 ) ;
V_3 . V_84 = false ;
V_3 . V_91 = F_60 ( V_3 . V_40 , L_44 ) ;
V_36 = F_38 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_73;
V_100 += V_36 ;
V_36 = F_48 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_73;
V_100 += V_36 ;
V_36 = F_49 ( & V_3 ) ;
if ( V_36 < 0 )
goto V_73;
V_100 += V_36 ;
V_73:
F_50 ( & V_3 ) ;
if ( V_36 || V_100 )
return 0 ;
return 0 ;
}
