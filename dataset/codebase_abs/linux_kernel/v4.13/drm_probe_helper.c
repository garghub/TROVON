static enum V_1
F_1 ( const struct V_2 * V_3 ,
int V_4 )
{
if ( ( V_3 -> V_4 & V_5 ) &&
! ( V_4 & V_5 ) )
return V_6 ;
if ( ( V_3 -> V_4 & V_7 ) &&
! ( V_4 & V_7 ) )
return V_8 ;
if ( ( V_3 -> V_4 & V_9 ) &&
! ( V_4 & V_9 ) )
return V_10 ;
return V_11 ;
}
static enum V_1
F_2 ( struct V_2 * V_3 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
T_1 * V_16 = V_13 -> V_17 ;
enum V_1 V_18 = V_11 ;
unsigned int V_19 ;
V_18 = F_3 ( V_13 , V_3 ) ;
if ( V_18 != V_11 )
return V_18 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
struct V_21 * V_22 = F_4 ( V_15 , V_16 [ V_19 ] ) ;
struct V_23 * V_24 ;
if ( ! V_22 )
continue;
V_18 = F_5 ( V_22 , V_3 ) ;
if ( V_18 != V_11 ) {
continue;
}
V_18 = F_6 ( V_22 -> V_25 , V_3 ) ;
if ( V_18 != V_11 ) {
continue;
}
F_7 (crtc, dev) {
if ( ! F_8 ( V_22 , V_24 ) )
continue;
V_18 = F_9 ( V_24 , V_3 ) ;
if ( V_18 == V_11 ) {
return V_18 ;
}
}
}
return V_18 ;
}
static int F_10 ( struct V_12 * V_13 )
{
struct V_26 * V_27 ;
struct V_2 * V_3 ;
V_27 = & V_13 -> V_27 ;
if ( ! V_27 -> V_28 )
return 0 ;
F_11 (mode, &connector->probed_modes, head) {
if ( V_3 -> V_29 != V_27 -> V_30 ||
V_3 -> V_31 != V_27 -> V_32 )
continue;
if ( V_27 -> V_33 ) {
if ( F_12 ( V_3 ) != V_27 -> V_34 )
continue;
}
return 0 ;
}
V_3 = F_13 ( V_13 -> V_15 ,
V_27 ) ;
if ( V_3 == NULL )
return 0 ;
F_14 ( V_13 , V_3 ) ;
return 1 ;
}
enum V_1 F_9 ( struct V_23 * V_24 ,
const struct V_2 * V_3 )
{
const struct V_35 * V_36 = V_24 -> V_37 ;
if ( ! V_36 || ! V_36 -> V_38 )
return V_11 ;
return V_36 -> V_38 ( V_24 , V_3 ) ;
}
enum V_1 F_5 ( struct V_21 * V_22 ,
const struct V_2 * V_3 )
{
const struct V_39 * V_40 =
V_22 -> V_37 ;
if ( ! V_40 || ! V_40 -> V_38 )
return V_11 ;
return V_40 -> V_38 ( V_22 , V_3 ) ;
}
enum V_1 F_3 ( struct V_12 * V_13 ,
struct V_2 * V_3 )
{
const struct V_41 * V_42 =
V_13 -> V_37 ;
if ( ! V_42 || ! V_42 -> V_38 )
return V_11 ;
return V_42 -> V_38 ( V_13 , V_3 ) ;
}
void F_15 ( struct V_14 * V_15 )
{
bool V_43 = false ;
struct V_12 * V_13 ;
struct V_44 V_45 ;
unsigned long V_46 = V_47 ;
if ( ! V_15 -> V_48 . V_49 || ! V_50 )
return;
F_16 ( V_15 , & V_45 ) ;
F_17 (connector, &conn_iter) {
if ( V_13 -> V_51 & ( V_52 |
V_53 ) )
V_43 = true ;
}
F_18 ( & V_45 ) ;
if ( V_15 -> V_48 . V_54 ) {
V_43 = true ;
V_46 = V_55 ;
}
if ( V_43 )
F_19 ( & V_15 -> V_48 . V_56 , V_46 ) ;
}
static enum V_57
F_20 ( struct V_12 * V_13 , bool V_58 )
{
const struct V_41 * V_59 = V_13 -> V_37 ;
struct V_60 V_61 ;
int V_18 ;
F_21 ( & V_61 , 0 ) ;
V_62:
V_18 = F_22 ( & V_13 -> V_15 -> V_48 . V_63 , & V_61 ) ;
if ( ! V_18 ) {
if ( V_59 -> V_64 )
V_18 = V_59 -> V_64 ( V_13 , & V_61 , V_58 ) ;
else if ( V_13 -> V_59 -> V_65 )
V_18 = V_13 -> V_59 -> V_65 ( V_13 , V_58 ) ;
else
V_18 = V_66 ;
}
if ( V_18 == - V_67 ) {
F_23 ( & V_61 ) ;
goto V_62;
}
if ( F_24 ( V_18 < 0 ) )
V_18 = V_68 ;
F_25 ( & V_61 ) ;
F_26 ( & V_61 ) ;
return V_18 ;
}
int
F_27 ( struct V_12 * V_13 ,
struct V_60 * V_61 ,
bool V_58 )
{
const struct V_41 * V_59 = V_13 -> V_37 ;
struct V_14 * V_15 = V_13 -> V_15 ;
int V_18 ;
if ( ! V_61 )
return F_20 ( V_13 , V_58 ) ;
V_18 = F_22 ( & V_15 -> V_48 . V_63 , V_61 ) ;
if ( V_18 )
return V_18 ;
if ( V_59 -> V_64 )
return V_59 -> V_64 ( V_13 , V_61 , V_58 ) ;
else if ( V_13 -> V_59 -> V_65 )
return V_13 -> V_59 -> V_65 ( V_13 , V_58 ) ;
else
return V_66 ;
}
int F_28 ( struct V_12 * V_13 ,
T_1 V_69 , T_1 V_70 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_2 * V_3 ;
const struct V_41 * V_42 =
V_13 -> V_37 ;
int V_71 = 0 , V_18 ;
int V_72 = 0 ;
bool V_73 = true ;
enum V_57 V_74 ;
struct V_60 V_61 ;
F_24 ( ! F_29 ( & V_15 -> V_48 . V_75 ) ) ;
F_21 ( & V_61 , 0 ) ;
F_30 ( L_1 , V_13 -> V_76 . V_77 ,
V_13 -> V_78 ) ;
V_62:
V_18 = F_22 ( & V_15 -> V_48 . V_63 , & V_61 ) ;
if ( V_18 == - V_67 ) {
F_23 ( & V_61 ) ;
goto V_62;
} else
F_24 ( V_18 < 0 ) ;
F_11 (mode, &connector->modes, head)
V_3 -> V_79 = V_80 ;
V_74 = V_13 -> V_79 ;
if ( V_13 -> V_58 ) {
if ( V_13 -> V_58 == V_81 ||
V_13 -> V_58 == V_82 )
V_13 -> V_79 = V_66 ;
else
V_13 -> V_79 = V_83 ;
if ( V_13 -> V_59 -> V_58 )
V_13 -> V_59 -> V_58 ( V_13 ) ;
} else {
V_18 = F_27 ( V_13 , & V_61 , true ) ;
if ( V_18 == - V_67 ) {
F_23 ( & V_61 ) ;
goto V_62;
} else if ( F_31 ( V_18 < 0 , L_2 , V_18 ) )
V_18 = V_68 ;
V_13 -> V_79 = V_18 ;
}
if ( V_74 != V_13 -> V_79 ) {
F_30 ( L_3 ,
V_13 -> V_76 . V_77 ,
V_13 -> V_78 ,
F_32 ( V_74 ) ,
F_32 ( V_13 -> V_79 ) ) ;
V_15 -> V_48 . V_54 = true ;
if ( V_15 -> V_48 . V_49 )
F_19 ( & V_15 -> V_48 . V_56 ,
0 ) ;
}
if ( V_50 != V_15 -> V_48 . V_84 )
F_15 ( V_15 ) ;
V_15 -> V_48 . V_84 = V_50 ;
if ( V_13 -> V_79 == V_83 ) {
F_30 ( L_4 ,
V_13 -> V_76 . V_77 , V_13 -> V_78 ) ;
F_33 ( V_13 , NULL ) ;
V_73 = false ;
goto V_85;
}
if ( V_13 -> V_86 ) {
struct V_87 * V_87 = (struct V_87 * ) V_13 -> V_88 -> V_89 ;
V_71 = F_34 ( V_13 , V_87 ) ;
F_35 ( V_13 , V_87 ) ;
} else {
struct V_87 * V_87 = F_36 ( V_13 ) ;
if ( ! F_37 ( V_87 ) ) {
F_33 ( V_13 , V_87 ) ;
V_71 = F_34 ( V_13 , V_87 ) ;
F_35 ( V_13 , V_87 ) ;
F_38 ( V_87 ) ;
}
if ( V_71 == 0 )
V_71 = (* V_42 -> V_90 )( V_13 ) ;
}
if ( V_71 == 0 && V_13 -> V_79 == V_66 )
V_71 = F_39 ( V_13 , 1024 , 768 ) ;
V_71 += F_10 ( V_13 ) ;
if ( V_71 == 0 )
goto V_85;
F_40 ( V_13 ) ;
if ( V_13 -> V_91 )
V_72 |= V_5 ;
if ( V_13 -> V_92 )
V_72 |= V_7 ;
if ( V_13 -> V_93 )
V_72 |= V_9 ;
F_11 (mode, &connector->modes, head) {
if ( V_3 -> V_79 == V_11 )
V_3 -> V_79 = F_41 ( V_3 ) ;
if ( V_3 -> V_79 == V_11 )
V_3 -> V_79 = F_42 ( V_3 , V_69 , V_70 ) ;
if ( V_3 -> V_79 == V_11 )
V_3 -> V_79 = F_1 ( V_3 , V_72 ) ;
if ( V_3 -> V_79 == V_11 )
V_3 -> V_79 = F_2 ( V_3 ,
V_13 ) ;
}
V_85:
F_43 ( V_15 , & V_13 -> V_94 , V_73 ) ;
F_25 ( & V_61 ) ;
F_26 ( & V_61 ) ;
if ( F_44 ( & V_13 -> V_94 ) )
return 0 ;
F_11 (mode, &connector->modes, head)
V_3 -> V_95 = F_12 ( V_3 ) ;
F_45 ( & V_13 -> V_94 ) ;
F_30 ( L_5 , V_13 -> V_76 . V_77 ,
V_13 -> V_78 ) ;
F_11 (mode, &connector->modes, head) {
F_46 ( V_3 , V_96 ) ;
F_47 ( V_3 ) ;
}
return V_71 ;
}
void F_48 ( struct V_14 * V_15 )
{
F_49 ( V_15 ) ;
if ( V_15 -> V_48 . V_59 -> V_97 )
V_15 -> V_48 . V_59 -> V_97 ( V_15 ) ;
}
static void F_50 ( struct V_98 * V_99 )
{
struct V_100 * V_100 = F_51 ( V_99 ) ;
struct V_14 * V_15 = F_52 ( V_100 , struct V_14 , V_48 . V_56 ) ;
struct V_12 * V_13 ;
struct V_44 V_45 ;
enum V_57 V_74 ;
bool V_101 = false , V_102 ;
V_102 = V_15 -> V_48 . V_54 ;
V_15 -> V_48 . V_54 = false ;
if ( ! V_50 )
goto V_103;
if ( ! F_53 ( & V_15 -> V_48 . V_75 ) ) {
V_101 = true ;
goto V_103;
}
F_16 ( V_15 , & V_45 ) ;
F_17 (connector, &conn_iter) {
if ( V_13 -> V_58 )
continue;
if ( ! V_13 -> V_51 || V_13 -> V_51 == V_104 )
continue;
V_74 = V_13 -> V_79 ;
if ( V_74 == V_66 &&
! ( V_13 -> V_51 & V_53 ) )
continue;
V_101 = true ;
V_13 -> V_79 = F_27 ( V_13 , NULL , false ) ;
if ( V_74 != V_13 -> V_79 ) {
const char * V_105 , * V_106 ;
if ( V_13 -> V_79 == V_68 ) {
V_13 -> V_79 = V_74 ;
continue;
}
V_105 = F_32 ( V_74 ) ;
V_106 = F_32 ( V_13 -> V_79 ) ;
F_30 ( L_6
L_7 ,
V_13 -> V_76 . V_77 ,
V_13 -> V_78 ,
V_105 , V_106 ) ;
V_102 = true ;
}
}
F_18 ( & V_45 ) ;
F_54 ( & V_15 -> V_48 . V_75 ) ;
V_103:
if ( V_102 )
F_48 ( V_15 ) ;
if ( V_101 )
F_19 ( V_100 , V_47 ) ;
}
void F_55 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_48 . V_49 )
return;
F_56 ( & V_15 -> V_48 . V_56 ) ;
}
void F_57 ( struct V_14 * V_15 )
{
F_58 ( & V_15 -> V_48 . V_56 , F_50 ) ;
V_15 -> V_48 . V_49 = true ;
F_15 ( V_15 ) ;
}
void F_59 ( struct V_14 * V_15 )
{
F_55 ( V_15 ) ;
}
bool F_60 ( struct V_14 * V_15 )
{
struct V_12 * V_13 ;
struct V_44 V_45 ;
enum V_57 V_74 ;
bool V_102 = false ;
if ( ! V_15 -> V_48 . V_49 )
return false ;
F_61 ( & V_15 -> V_48 . V_75 ) ;
F_16 ( V_15 , & V_45 ) ;
F_17 (connector, &conn_iter) {
if ( ! ( V_13 -> V_51 & V_104 ) )
continue;
V_74 = V_13 -> V_79 ;
V_13 -> V_79 = F_27 ( V_13 , NULL , false ) ;
F_30 ( L_3 ,
V_13 -> V_76 . V_77 ,
V_13 -> V_78 ,
F_32 ( V_74 ) ,
F_32 ( V_13 -> V_79 ) ) ;
if ( V_74 != V_13 -> V_79 )
V_102 = true ;
}
F_18 ( & V_45 ) ;
F_54 ( & V_15 -> V_48 . V_75 ) ;
if ( V_102 )
F_48 ( V_15 ) ;
return V_102 ;
}
