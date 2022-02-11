struct V_1 * F_1 ( struct V_2 * V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
F_2 (sec, &elf->sections, list)
if ( ! strcmp ( V_4 -> V_3 , V_3 ) )
return V_4 ;
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_2 ,
unsigned int V_5 )
{
struct V_1 * V_4 ;
F_2 (sec, &elf->sections, list)
if ( V_4 -> V_5 == V_5 )
return V_4 ;
return NULL ;
}
static struct V_6 * F_4 ( struct V_2 * V_2 , unsigned int V_5 )
{
struct V_1 * V_4 ;
struct V_6 * V_7 ;
F_2 (sec, &elf->sections, list)
F_5 (sec->symbol_hash, sym, hash, idx)
if ( V_7 -> V_5 == V_5 )
return V_7 ;
return NULL ;
}
struct V_6 * F_6 ( struct V_1 * V_4 , unsigned long V_8 )
{
struct V_6 * V_7 ;
F_2 (sym, &sec->symbol_list, list)
if ( V_7 -> type != V_9 &&
V_7 -> V_8 == V_8 )
return V_7 ;
return NULL ;
}
struct V_10 * F_7 ( struct V_1 * V_4 , unsigned long V_8 ,
unsigned int V_11 )
{
struct V_10 * V_10 ;
unsigned long V_12 ;
if ( ! V_4 -> V_10 )
return NULL ;
for ( V_12 = V_8 ; V_12 < V_8 + V_11 ; V_12 ++ )
F_5 (sec->rela->rela_hash, rela, hash, o)
if ( V_10 -> V_8 == V_12 )
return V_10 ;
return NULL ;
}
struct V_10 * F_8 ( struct V_1 * V_4 , unsigned long V_8 )
{
return F_7 ( V_4 , V_8 , 1 ) ;
}
struct V_6 * F_9 ( struct V_1 * V_4 , unsigned long V_8 )
{
struct V_6 * V_13 ;
F_2 (func, &sec->symbol_list, list)
if ( V_13 -> type == V_14 && V_8 >= V_13 -> V_8 &&
V_8 < V_13 -> V_8 + V_13 -> V_11 )
return V_13 ;
return NULL ;
}
static int F_10 ( struct V_2 * V_2 )
{
T_1 * V_15 = NULL ;
struct V_1 * V_4 ;
T_2 V_16 , V_17 ;
int V_18 ;
if ( F_11 ( V_2 -> V_2 , & V_17 ) ) {
perror ( L_1 ) ;
return - 1 ;
}
if ( F_12 ( V_2 -> V_2 , & V_16 ) ) {
perror ( L_2 ) ;
return - 1 ;
}
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
V_4 = malloc ( sizeof( * V_4 ) ) ;
if ( ! V_4 ) {
perror ( L_3 ) ;
return - 1 ;
}
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_13 ( & V_4 -> V_19 ) ;
F_13 ( & V_4 -> V_20 ) ;
F_14 ( V_4 -> V_21 ) ;
F_14 ( V_4 -> V_22 ) ;
F_15 ( & V_4 -> V_23 , & V_2 -> V_24 ) ;
V_15 = F_16 ( V_2 -> V_2 , V_18 ) ;
if ( ! V_15 ) {
perror ( L_4 ) ;
return - 1 ;
}
V_4 -> V_5 = F_17 ( V_15 ) ;
if ( ! F_18 ( V_15 , & V_4 -> V_25 ) ) {
perror ( L_5 ) ;
return - 1 ;
}
V_4 -> V_3 = F_19 ( V_2 -> V_2 , V_16 , V_4 -> V_25 . V_26 ) ;
if ( ! V_4 -> V_3 ) {
perror ( L_6 ) ;
return - 1 ;
}
V_4 -> V_27 = F_20 ( V_15 , NULL ) ;
if ( ! V_4 -> V_27 ) {
perror ( L_7 ) ;
return - 1 ;
}
if ( V_4 -> V_27 -> V_28 != 0 ||
V_4 -> V_27 -> V_29 != V_4 -> V_25 . V_30 ) {
F_21 ( L_8 , V_4 -> V_3 ) ;
return - 1 ;
}
V_4 -> V_31 = ( unsigned long ) V_4 -> V_27 -> V_32 ;
V_4 -> V_11 = V_4 -> V_27 -> V_29 ;
}
if ( F_22 ( V_2 -> V_2 , V_15 ) ) {
F_21 ( L_9 ) ;
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_2 )
{
struct V_1 * V_33 ;
struct V_6 * V_7 ;
struct V_34 * V_35 , * V_36 ;
int V_37 , V_18 ;
V_33 = F_1 ( V_2 , L_10 ) ;
if ( ! V_33 ) {
F_21 ( L_11 ) ;
return - 1 ;
}
V_37 = V_33 -> V_25 . V_30 / V_33 -> V_25 . V_38 ;
for ( V_18 = 0 ; V_18 < V_37 ; V_18 ++ ) {
V_7 = malloc ( sizeof( * V_7 ) ) ;
if ( ! V_7 ) {
perror ( L_3 ) ;
return - 1 ;
}
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_5 = V_18 ;
if ( ! F_24 ( V_33 -> V_27 , V_18 , & V_7 -> V_7 ) ) {
perror ( L_12 ) ;
goto V_39;
}
V_7 -> V_3 = F_19 ( V_2 -> V_2 , V_33 -> V_25 . V_40 ,
V_7 -> V_7 . V_41 ) ;
if ( ! V_7 -> V_3 ) {
perror ( L_6 ) ;
goto V_39;
}
V_7 -> type = F_25 ( V_7 -> V_7 . V_42 ) ;
V_7 -> V_43 = F_26 ( V_7 -> V_7 . V_42 ) ;
if ( V_7 -> V_7 . V_44 > V_45 &&
V_7 -> V_7 . V_44 < V_46 ) {
V_7 -> V_4 = F_3 ( V_2 ,
V_7 -> V_7 . V_44 ) ;
if ( ! V_7 -> V_4 ) {
F_21 ( L_13 ,
V_7 -> V_3 ) ;
goto V_39;
}
if ( V_7 -> type == V_9 ) {
V_7 -> V_3 = V_7 -> V_4 -> V_3 ;
V_7 -> V_4 -> V_7 = V_7 ;
}
} else
V_7 -> V_4 = F_3 ( V_2 , 0 ) ;
V_7 -> V_8 = V_7 -> V_7 . V_47 ;
V_7 -> V_11 = V_7 -> V_7 . V_48 ;
V_35 = & V_7 -> V_4 -> V_19 ;
F_27 (tmp, &sym->sec->symbol_list) {
struct V_6 * V_15 ;
V_15 = F_28 ( V_36 , struct V_6 , V_23 ) ;
if ( V_7 -> V_8 > V_15 -> V_8 ) {
V_35 = V_36 ;
break;
}
if ( V_7 -> V_8 == V_15 -> V_8 && V_7 -> V_11 >= V_15 -> V_11 ) {
V_35 = V_36 ;
break;
}
}
F_29 ( & V_7 -> V_23 , V_35 ) ;
F_30 ( V_7 -> V_4 -> V_22 , & V_7 -> V_49 , V_7 -> V_5 ) ;
}
return 0 ;
V_39:
free ( V_7 ) ;
return - 1 ;
}
static int F_31 ( struct V_2 * V_2 )
{
struct V_1 * V_4 ;
struct V_10 * V_10 ;
int V_18 ;
unsigned int V_50 ;
F_2 (sec, &elf->sections, list) {
if ( V_4 -> V_25 . V_51 != V_52 )
continue;
V_4 -> V_53 = F_1 ( V_2 , V_4 -> V_3 + 5 ) ;
if ( ! V_4 -> V_53 ) {
F_21 ( L_14 ,
V_4 -> V_3 ) ;
return - 1 ;
}
V_4 -> V_53 -> V_10 = V_4 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_25 . V_30 / V_4 -> V_25 . V_38 ; V_18 ++ ) {
V_10 = malloc ( sizeof( * V_10 ) ) ;
if ( ! V_10 ) {
perror ( L_3 ) ;
return - 1 ;
}
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( ! F_32 ( V_4 -> V_27 , V_18 , & V_10 -> V_10 ) ) {
perror ( L_15 ) ;
return - 1 ;
}
V_10 -> type = F_33 ( V_10 -> V_10 . V_54 ) ;
V_10 -> V_55 = V_10 -> V_10 . V_56 ;
V_10 -> V_8 = V_10 -> V_10 . V_57 ;
V_50 = F_34 ( V_10 -> V_10 . V_54 ) ;
V_10 -> V_7 = F_4 ( V_2 , V_50 ) ;
if ( ! V_10 -> V_7 ) {
F_21 ( L_16 ,
V_50 , V_4 -> V_3 ) ;
return - 1 ;
}
F_15 ( & V_10 -> V_23 , & V_4 -> V_20 ) ;
F_30 ( V_4 -> V_21 , & V_10 -> V_49 , V_10 -> V_8 ) ;
}
}
return 0 ;
}
struct V_2 * F_35 ( const char * V_3 )
{
struct V_2 * V_2 ;
F_36 ( V_58 ) ;
V_2 = malloc ( sizeof( * V_2 ) ) ;
if ( ! V_2 ) {
perror ( L_3 ) ;
return NULL ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_13 ( & V_2 -> V_24 ) ;
V_2 -> V_3 = F_37 ( V_3 ) ;
if ( ! V_2 -> V_3 ) {
perror ( L_17 ) ;
goto V_39;
}
V_2 -> V_59 = F_38 ( V_3 , V_60 ) ;
if ( V_2 -> V_59 == - 1 ) {
perror ( L_18 ) ;
goto V_39;
}
V_2 -> V_2 = F_39 ( V_2 -> V_59 , V_61 , NULL ) ;
if ( ! V_2 -> V_2 ) {
perror ( L_19 ) ;
goto V_39;
}
if ( ! F_40 ( V_2 -> V_2 , & V_2 -> V_62 ) ) {
perror ( L_20 ) ;
goto V_39;
}
if ( F_10 ( V_2 ) )
goto V_39;
if ( F_23 ( V_2 ) )
goto V_39;
if ( F_31 ( V_2 ) )
goto V_39;
return V_2 ;
V_39:
F_41 ( V_2 ) ;
return NULL ;
}
void F_41 ( struct V_2 * V_2 )
{
struct V_1 * V_4 , * V_63 ;
struct V_6 * V_7 , * V_64 ;
struct V_10 * V_10 , * V_65 ;
F_42 (sec, tmpsec, &elf->sections, list) {
F_42 (sym, tmpsym, &sec->symbol_list, list) {
F_43 ( & V_7 -> V_23 ) ;
F_44 ( & V_7 -> V_49 ) ;
free ( V_7 ) ;
}
F_42 (rela, tmprela, &sec->rela_list, list) {
F_43 ( & V_10 -> V_23 ) ;
F_44 ( & V_10 -> V_49 ) ;
free ( V_10 ) ;
}
F_43 ( & V_4 -> V_23 ) ;
free ( V_4 ) ;
}
if ( V_2 -> V_3 )
free ( V_2 -> V_3 ) ;
if ( V_2 -> V_59 > 0 )
F_45 ( V_2 -> V_59 ) ;
if ( V_2 -> V_2 )
F_46 ( V_2 -> V_2 ) ;
free ( V_2 ) ;
}
