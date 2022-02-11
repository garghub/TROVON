static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ,
struct V_2 , V_1 ) ;
F_3 ( ! F_4 ( & V_3 -> V_4 ) ) ;
F_5 ( V_3 -> V_5 ) ;
F_5 ( V_3 ) ;
}
static inline void F_6 ( struct V_2 * V_3 )
{
if ( F_3 ( ! V_3 ) )
return;
F_7 ( & V_3 -> V_1 , F_1 ) ;
}
static struct V_2 * F_8 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_2 * V_8 , * V_9 ;
if ( V_3 -> V_7 == V_7 ) {
F_9 ( & V_3 -> V_1 ) ;
return V_3 ;
}
F_10 (tmp, &php_slot->children, link) {
V_8 = F_8 ( V_7 , V_9 ) ;
if ( V_8 )
return V_8 ;
}
return NULL ;
}
struct V_2 * F_11 ( struct V_6 * V_7 )
{
struct V_2 * V_3 , * V_9 ;
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_10 (tmp, &pnv_php_slot_list, link) {
V_3 = F_8 ( V_7 , V_9 ) ;
if ( V_3 ) {
F_13 ( & V_11 , V_10 ) ;
return V_3 ;
}
}
F_13 ( & V_11 , V_10 ) ;
return NULL ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_6 * V_12 ;
F_15 (dn, child) {
F_14 ( V_12 ) ;
F_16 ( V_12 ) ;
}
}
static void F_17 ( struct V_6 * V_13 )
{
struct V_6 * V_7 ;
int V_14 ;
F_15 (parent, dn) {
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
V_14 = F_19 ( & V_7 -> V_15 . V_1 . V_14 ) ;
if ( F_20 ( V_14 != 1 ) )
F_21 ( L_1 ,
V_14 , F_22 ( V_7 ) ) ;
F_23 ( V_7 ) ;
}
}
static void F_24 ( struct V_2 * V_3 )
{
F_14 ( V_3 -> V_7 ) ;
if ( V_3 -> V_16 )
F_25 ( & V_3 -> V_17 ) ;
F_17 ( V_3 -> V_7 ) ;
if ( V_3 -> V_16 ) {
F_5 ( V_3 -> V_18 ) ;
F_5 ( V_3 -> V_16 ) ;
V_3 -> V_18 = NULL ;
V_3 -> V_7 -> V_12 = NULL ;
V_3 -> V_16 = NULL ;
}
}
static void F_26 ( struct V_6 * V_13 )
{
struct V_6 * V_12 , * V_19 ;
F_15 (parent, child)
F_26 ( V_12 ) ;
V_12 = V_13 -> V_12 ;
V_13 -> V_12 = NULL ;
while ( V_12 ) {
V_19 = V_12 -> V_20 ;
V_12 -> V_20 = V_13 -> V_12 ;
V_13 -> V_12 = V_12 ;
V_12 = V_19 ;
}
}
static int F_27 ( struct V_21 * V_17 ,
struct V_6 * V_7 )
{
struct V_6 * V_12 ;
int V_22 = 0 ;
F_15 (dn, child) {
V_22 = F_28 ( V_17 , V_12 ) ;
if ( F_20 ( V_22 ) )
break;
V_22 = F_27 ( V_17 , V_12 ) ;
if ( F_20 ( V_22 ) )
break;
}
return V_22 ;
}
static void * F_29 ( struct V_6 * V_7 , void * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
struct V_26 * V_27 ;
V_27 = F_30 ( V_25 , V_7 ) ;
if ( F_20 ( ! V_27 ) )
return F_31 ( - V_28 ) ;
return NULL ;
}
static void F_32 ( struct V_2 * V_29 )
{
struct V_24 * V_25 = F_33 ( V_29 -> V_30 ) ;
F_34 ( V_29 -> V_7 , F_29 , V_25 ) ;
}
static int F_35 ( struct V_2 * V_3 )
{
void * V_16 , * V_31 , * V_18 ;
int V_22 ;
V_31 = F_36 ( 0x10000 , V_32 ) ;
if ( F_20 ( ! V_31 ) ) {
V_22 = - V_28 ;
F_37 ( & V_3 -> V_33 -> V_34 , L_2 ) ;
goto V_35;
}
V_22 = F_38 ( V_3 -> V_7 -> V_36 , V_31 , 0x10000 ) ;
if ( F_20 ( V_22 ) ) {
F_37 ( & V_3 -> V_33 -> V_34 , L_3 ,
V_22 ) ;
goto V_37;
}
V_16 = F_36 ( F_39 ( V_31 ) , V_32 ) ;
if ( F_20 ( ! V_16 ) ) {
V_22 = - V_28 ;
F_37 ( & V_3 -> V_33 -> V_34 , L_4 ,
F_39 ( V_31 ) ) ;
goto V_37;
}
memcpy ( V_16 , V_31 , F_39 ( V_31 ) ) ;
V_18 = F_40 ( V_16 , V_3 -> V_7 , NULL ) ;
if ( F_20 ( ! V_18 ) ) {
V_22 = - V_38 ;
F_37 ( & V_3 -> V_33 -> V_34 , L_5 ) ;
goto V_39;
}
F_41 ( & V_3 -> V_17 ) ;
F_26 ( V_3 -> V_7 ) ;
V_22 = F_27 ( & V_3 -> V_17 , V_3 -> V_7 ) ;
if ( F_20 ( V_22 ) ) {
F_26 ( V_3 -> V_7 ) ;
F_37 ( & V_3 -> V_33 -> V_34 , L_6 ,
V_22 ) ;
goto V_40;
}
V_3 -> V_7 -> V_12 = NULL ;
V_22 = F_42 ( & V_3 -> V_17 ) ;
if ( F_20 ( V_22 ) ) {
F_37 ( & V_3 -> V_33 -> V_34 , L_7 ,
V_22 ) ;
goto V_41;
}
F_32 ( V_3 ) ;
V_3 -> V_16 = V_16 ;
V_3 -> V_18 = V_18 ;
F_5 ( V_31 ) ;
goto V_35;
V_41:
F_25 ( & V_3 -> V_17 ) ;
V_40:
F_5 ( V_18 ) ;
V_3 -> V_7 -> V_12 = NULL ;
V_39:
F_5 ( V_16 ) ;
V_37:
F_5 ( V_31 ) ;
V_35:
return V_22 ;
}
int F_43 ( struct V_42 * V_29 ,
T_1 V_43 )
{
struct V_2 * V_3 = V_29 -> V_44 ;
struct V_45 V_46 ;
int V_22 ;
V_22 = F_44 ( V_3 -> V_47 , V_43 , & V_46 ) ;
if ( F_45 ( V_22 > 0 ) ) {
if ( F_46 ( V_46 . V_48 [ 1 ] ) != V_3 -> V_7 -> V_36 ||
F_46 ( V_46 . V_48 [ 2 ] ) != V_43 ||
F_46 ( V_46 . V_48 [ 3 ] ) != V_49 ) {
F_37 ( & V_3 -> V_33 -> V_34 , L_8 ,
F_46 ( V_46 . V_48 [ 1 ] ) ,
F_46 ( V_46 . V_48 [ 2 ] ) ,
F_46 ( V_46 . V_48 [ 3 ] ) ) ;
return - V_50 ;
}
} else if ( F_20 ( V_22 < 0 ) ) {
F_37 ( & V_3 -> V_33 -> V_34 , L_9 ,
V_22 , ( V_43 == V_51 ) ? L_10 : L_11 ) ;
return V_22 ;
}
if ( V_43 == V_52 || V_43 == V_53 )
F_24 ( V_3 ) ;
else
V_22 = F_35 ( V_3 ) ;
return V_22 ;
}
static int F_47 ( struct V_42 * V_29 , T_2 * V_43 )
{
struct V_2 * V_3 = V_29 -> V_44 ;
T_1 V_54 = V_51 ;
int V_22 ;
V_22 = F_48 ( V_3 -> V_47 , & V_54 ) ;
if ( F_20 ( V_22 ) ) {
F_37 ( & V_3 -> V_33 -> V_34 , L_12 ,
V_22 ) ;
} else {
* V_43 = V_54 ;
V_29 -> V_55 -> V_56 = V_54 ;
}
return 0 ;
}
static int F_49 ( struct V_42 * V_29 , T_2 * V_43 )
{
struct V_2 * V_3 = V_29 -> V_44 ;
T_1 V_57 = V_58 ;
int V_22 ;
V_22 = F_50 ( V_3 -> V_47 , & V_57 ) ;
if ( F_45 ( V_22 >= 0 ) ) {
* V_43 = V_57 ;
V_29 -> V_55 -> V_59 = V_57 ;
V_22 = 0 ;
} else {
F_37 ( & V_3 -> V_33 -> V_34 , L_13 ,
V_22 ) ;
}
return V_22 ;
}
static int F_51 ( struct V_42 * V_29 , T_2 V_43 )
{
V_29 -> V_55 -> V_60 = V_43 ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , bool V_61 )
{
struct V_42 * V_29 = & V_3 -> V_29 ;
T_1 V_57 = V_58 ;
T_1 V_56 = V_51 ;
int V_22 ;
if ( V_3 -> V_43 != V_62 )
return 0 ;
V_22 = F_49 ( V_29 , & V_57 ) ;
if ( F_20 ( V_22 ) )
return V_22 ;
if ( V_57 == V_58 )
goto V_63;
if ( ! V_3 -> V_64 ) {
V_3 -> V_64 = true ;
V_22 = F_47 ( V_29 , & V_56 ) ;
if ( F_20 ( V_22 ) )
return V_22 ;
if ( V_56 != V_51 )
return 0 ;
}
V_22 = F_47 ( V_29 , & V_56 ) ;
if ( F_20 ( V_22 ) )
return V_22 ;
if ( V_56 == V_51 )
goto V_63;
V_22 = F_43 ( V_29 , V_51 ) ;
if ( F_20 ( V_22 ) )
return V_22 ;
V_63:
if ( V_57 == V_65 ) {
if ( V_61 ) {
F_53 () ;
F_54 ( V_3 -> V_30 ) ;
F_55 () ;
}
V_3 -> V_43 = V_66 ;
if ( V_61 )
F_56 ( V_3 -> V_7 ) ;
} else {
V_3 -> V_43 = V_66 ;
}
return 0 ;
}
static int F_57 ( struct V_42 * V_29 )
{
struct V_2 * V_3 = F_2 ( V_29 ,
struct V_2 , V_29 ) ;
return F_52 ( V_3 , true ) ;
}
static int F_58 ( struct V_42 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_44 ;
int V_22 ;
if ( V_3 -> V_43 != V_66 )
return 0 ;
F_53 () ;
F_59 ( V_3 -> V_30 ) ;
F_55 () ;
F_60 ( V_3 -> V_7 ) ;
V_22 = F_43 ( V_29 , V_52 ) ;
V_3 -> V_43 = V_62 ;
return V_22 ;
}
static void F_61 ( struct V_42 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_44 ;
unsigned long V_10 ;
F_12 ( & V_11 , V_10 ) ;
F_62 ( & V_3 -> V_67 ) ;
F_13 ( & V_11 , V_10 ) ;
F_6 ( V_3 ) ;
F_6 ( V_3 -> V_13 ) ;
}
static struct V_2 * F_63 ( struct V_6 * V_7 )
{
struct V_2 * V_3 ;
struct V_68 * V_30 ;
const char * V_69 ;
T_3 V_47 ;
V_69 = F_64 ( V_7 , L_14 , NULL ) ;
if ( F_20 ( ! V_69 ) )
return NULL ;
if ( F_65 ( V_7 , & V_47 ) )
return NULL ;
V_30 = F_66 ( V_7 ) ;
if ( F_20 ( ! V_30 ) )
return NULL ;
V_3 = F_36 ( sizeof( * V_3 ) , V_32 ) ;
if ( F_20 ( ! V_3 ) )
return NULL ;
V_3 -> V_5 = F_67 ( V_69 , V_32 ) ;
if ( F_20 ( ! V_3 -> V_5 ) ) {
F_5 ( V_3 ) ;
return NULL ;
}
if ( F_45 ( V_7 -> V_12 && F_68 ( V_7 -> V_12 ) ) )
V_3 -> V_70 = F_69 ( F_68 ( V_7 -> V_12 ) -> V_71 ) ;
else
V_3 -> V_70 = - 1 ;
F_70 ( & V_3 -> V_1 ) ;
V_3 -> V_43 = V_72 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_33 = V_30 -> V_73 ;
V_3 -> V_30 = V_30 ;
V_3 -> V_47 = V_47 ;
V_3 -> V_64 = false ;
V_3 -> V_29 . V_74 = & V_75 ;
V_3 -> V_29 . V_55 = & V_3 -> V_76 ;
V_3 -> V_29 . V_77 = F_61 ;
V_3 -> V_29 . V_44 = V_3 ;
F_71 ( & V_3 -> V_4 ) ;
F_71 ( & V_3 -> V_67 ) ;
return V_3 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_2 * V_13 ;
struct V_6 * V_7 = V_3 -> V_7 ;
unsigned long V_10 ;
int V_22 ;
V_13 = F_11 ( V_3 -> V_7 ) ;
if ( F_20 ( V_13 ) ) {
F_6 ( V_13 ) ;
return - V_78 ;
}
V_22 = F_73 ( & V_3 -> V_29 , V_3 -> V_30 ,
V_3 -> V_70 , V_3 -> V_5 ) ;
if ( F_20 ( V_22 ) ) {
F_37 ( & V_3 -> V_33 -> V_34 , L_15 ,
V_22 ) ;
return V_22 ;
}
while ( ( V_7 = F_74 ( V_7 ) ) ) {
if ( ! F_68 ( V_7 ) ) {
F_18 ( V_7 ) ;
break;
}
V_13 = F_11 ( V_7 ) ;
if ( V_13 ) {
F_18 ( V_7 ) ;
break;
}
F_18 ( V_7 ) ;
}
F_12 ( & V_11 , V_10 ) ;
V_3 -> V_13 = V_13 ;
if ( V_13 )
F_75 ( & V_3 -> V_67 , & V_13 -> V_4 ) ;
else
F_75 ( & V_3 -> V_67 , & V_79 ) ;
F_13 ( & V_11 , V_10 ) ;
V_3 -> V_43 = V_62 ;
return 0 ;
}
static int F_76 ( struct V_6 * V_7 )
{
struct V_2 * V_3 ;
const T_4 * V_80 ;
int V_22 ;
V_80 = F_64 ( V_7 , L_16 , NULL ) ;
if ( ! V_80 || ! F_77 ( V_80 , 1 ) )
return - V_81 ;
V_80 = F_64 ( V_7 , L_17 , NULL ) ;
if ( ! V_80 || ! F_77 ( V_80 , 1 ) )
return - V_81 ;
V_3 = F_63 ( V_7 ) ;
if ( F_20 ( ! V_3 ) )
return - V_82 ;
V_22 = F_72 ( V_3 ) ;
if ( F_20 ( V_22 ) )
goto V_83;
V_22 = F_52 ( V_3 , false ) ;
if ( F_20 ( V_22 ) )
goto V_84;
return 0 ;
V_84:
F_78 ( V_3 -> V_7 ) ;
V_83:
F_6 ( V_3 ) ;
return V_22 ;
}
static void F_56 ( struct V_6 * V_7 )
{
struct V_6 * V_12 ;
F_15 (dn, child) {
F_76 ( V_12 ) ;
F_56 ( V_12 ) ;
}
}
static void F_78 ( struct V_6 * V_7 )
{
struct V_2 * V_3 ;
V_3 = F_11 ( V_7 ) ;
if ( ! V_3 )
return;
V_3 -> V_43 = V_85 ;
F_6 ( V_3 ) ;
F_79 ( & V_3 -> V_29 ) ;
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_6 * V_12 ;
F_15 (dn, child) {
F_60 ( V_12 ) ;
F_78 ( V_12 ) ;
}
}
static int T_5 F_80 ( void )
{
struct V_6 * V_7 ;
F_81 ( V_86 L_18 V_87 L_19 ) ;
F_82 (dn, NULL, L_20 )
F_56 ( V_7 ) ;
return 0 ;
}
static void T_6 F_83 ( void )
{
struct V_6 * V_7 ;
F_82 (dn, NULL, L_20 )
F_60 ( V_7 ) ;
}
