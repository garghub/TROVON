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
static int F_2 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_2 * V_3 ;
V_15 = & V_13 -> V_15 ;
if ( ! V_15 -> V_16 )
return 0 ;
F_3 (mode, &connector->probed_modes, head) {
if ( V_3 -> V_17 != V_15 -> V_18 ||
V_3 -> V_19 != V_15 -> V_20 )
continue;
if ( V_15 -> V_21 ) {
if ( F_4 ( V_3 ) != V_15 -> V_22 )
continue;
}
return 0 ;
}
V_3 = F_5 ( V_13 -> V_23 ,
V_15 ) ;
if ( V_3 == NULL )
return 0 ;
F_6 ( V_13 , V_3 ) ;
return 1 ;
}
void F_7 ( struct V_24 * V_23 )
{
bool V_25 = false ;
struct V_12 * V_13 ;
struct V_26 V_27 ;
unsigned long V_28 = V_29 ;
if ( ! V_23 -> V_30 . V_31 || ! V_32 )
return;
F_8 ( V_23 , & V_27 ) ;
F_9 (connector, &conn_iter) {
if ( V_13 -> V_33 & ( V_34 |
V_35 ) )
V_25 = true ;
}
F_10 ( & V_27 ) ;
if ( V_23 -> V_30 . V_36 ) {
V_25 = true ;
V_28 = V_37 ;
}
if ( V_25 )
F_11 ( & V_23 -> V_30 . V_38 , V_28 ) ;
}
static enum V_39
F_12 ( struct V_12 * V_13 , bool V_40 )
{
return V_13 -> V_41 -> V_42 ?
V_13 -> V_41 -> V_42 ( V_13 , V_40 ) :
V_43 ;
}
int F_13 ( struct V_12 * V_13 ,
T_1 V_44 , T_1 V_45 )
{
struct V_24 * V_23 = V_13 -> V_23 ;
struct V_2 * V_3 ;
const struct V_46 * V_47 =
V_13 -> V_48 ;
int V_49 = 0 ;
int V_50 = 0 ;
bool V_51 = true ;
enum V_39 V_52 ;
F_14 ( ! F_15 ( & V_23 -> V_30 . V_53 ) ) ;
F_16 ( L_1 , V_13 -> V_54 . V_55 ,
V_13 -> V_56 ) ;
F_3 (mode, &connector->modes, head)
V_3 -> V_57 = V_58 ;
V_52 = V_13 -> V_57 ;
if ( V_13 -> V_40 ) {
if ( V_13 -> V_40 == V_59 ||
V_13 -> V_40 == V_60 )
V_13 -> V_57 = V_43 ;
else
V_13 -> V_57 = V_61 ;
if ( V_13 -> V_41 -> V_40 )
V_13 -> V_41 -> V_40 ( V_13 ) ;
} else {
V_13 -> V_57 = F_12 ( V_13 , true ) ;
}
if ( V_52 != V_13 -> V_57 ) {
F_16 ( L_2 ,
V_13 -> V_54 . V_55 ,
V_13 -> V_56 ,
F_17 ( V_52 ) ,
F_17 ( V_13 -> V_57 ) ) ;
V_23 -> V_30 . V_36 = true ;
if ( V_23 -> V_30 . V_31 )
F_11 ( & V_23 -> V_30 . V_38 ,
0 ) ;
}
if ( V_32 != V_23 -> V_30 . V_62 )
F_7 ( V_23 ) ;
V_23 -> V_30 . V_62 = V_32 ;
if ( V_13 -> V_57 == V_61 ) {
F_16 ( L_3 ,
V_13 -> V_54 . V_55 , V_13 -> V_56 ) ;
F_18 ( V_13 , NULL ) ;
V_51 = false ;
goto V_63;
}
if ( V_13 -> V_64 ) {
struct V_65 * V_65 = (struct V_65 * ) V_13 -> V_66 -> V_67 ;
V_49 = F_19 ( V_13 , V_65 ) ;
F_20 ( V_13 , V_65 ) ;
} else {
V_49 = F_21 ( V_13 ) ;
if ( V_49 == 0 )
V_49 = (* V_47 -> V_68 )( V_13 ) ;
}
if ( V_49 == 0 && V_13 -> V_57 == V_43 )
V_49 = F_22 ( V_13 , 1024 , 768 ) ;
V_49 += F_2 ( V_13 ) ;
if ( V_49 == 0 )
goto V_63;
F_23 ( V_13 ) ;
if ( V_13 -> V_69 )
V_50 |= V_5 ;
if ( V_13 -> V_70 )
V_50 |= V_7 ;
if ( V_13 -> V_71 )
V_50 |= V_9 ;
F_3 (mode, &connector->modes, head) {
if ( V_3 -> V_57 == V_11 )
V_3 -> V_57 = F_24 ( V_3 ) ;
if ( V_3 -> V_57 == V_11 )
V_3 -> V_57 = F_25 ( V_3 , V_44 , V_45 ) ;
if ( V_3 -> V_57 == V_11 )
V_3 -> V_57 = F_1 ( V_3 , V_50 ) ;
if ( V_3 -> V_57 == V_11 && V_47 -> V_72 )
V_3 -> V_57 = V_47 -> V_72 ( V_13 ,
V_3 ) ;
}
V_63:
F_26 ( V_23 , & V_13 -> V_73 , V_51 ) ;
if ( F_27 ( & V_13 -> V_73 ) )
return 0 ;
F_3 (mode, &connector->modes, head)
V_3 -> V_74 = F_4 ( V_3 ) ;
F_28 ( & V_13 -> V_73 ) ;
F_16 ( L_4 , V_13 -> V_54 . V_55 ,
V_13 -> V_56 ) ;
F_3 (mode, &connector->modes, head) {
F_29 ( V_3 , V_75 ) ;
F_30 ( V_3 ) ;
}
return V_49 ;
}
void F_31 ( struct V_24 * V_23 )
{
F_32 ( V_23 ) ;
if ( V_23 -> V_30 . V_41 -> V_76 )
V_23 -> V_30 . V_41 -> V_76 ( V_23 ) ;
}
static void F_33 ( struct V_77 * V_78 )
{
struct V_79 * V_79 = F_34 ( V_78 ) ;
struct V_24 * V_23 = F_35 ( V_79 , struct V_24 , V_30 . V_38 ) ;
struct V_12 * V_13 ;
struct V_26 V_27 ;
enum V_39 V_52 ;
bool V_80 = false , V_81 ;
V_81 = V_23 -> V_30 . V_36 ;
V_23 -> V_30 . V_36 = false ;
if ( ! V_32 )
goto V_82;
if ( ! F_36 ( & V_23 -> V_30 . V_53 ) ) {
V_80 = true ;
goto V_82;
}
F_8 ( V_23 , & V_27 ) ;
F_9 (connector, &conn_iter) {
if ( V_13 -> V_40 )
continue;
if ( ! V_13 -> V_33 || V_13 -> V_33 == V_83 )
continue;
V_52 = V_13 -> V_57 ;
if ( V_52 == V_43 &&
! ( V_13 -> V_33 & V_35 ) )
continue;
V_80 = true ;
V_13 -> V_57 = F_12 ( V_13 , false ) ;
if ( V_52 != V_13 -> V_57 ) {
const char * V_84 , * V_85 ;
if ( V_13 -> V_57 == V_86 ) {
V_13 -> V_57 = V_52 ;
continue;
}
V_84 = F_17 ( V_52 ) ;
V_85 = F_17 ( V_13 -> V_57 ) ;
F_16 ( L_5
L_6 ,
V_13 -> V_54 . V_55 ,
V_13 -> V_56 ,
V_84 , V_85 ) ;
V_81 = true ;
}
}
F_10 ( & V_27 ) ;
F_37 ( & V_23 -> V_30 . V_53 ) ;
V_82:
if ( V_81 )
F_31 ( V_23 ) ;
if ( V_80 )
F_11 ( V_79 , V_29 ) ;
}
void F_38 ( struct V_24 * V_23 )
{
if ( ! V_23 -> V_30 . V_31 )
return;
F_39 ( & V_23 -> V_30 . V_38 ) ;
}
void F_40 ( struct V_24 * V_23 )
{
F_41 ( & V_23 -> V_30 . V_38 , F_33 ) ;
V_23 -> V_30 . V_31 = true ;
F_7 ( V_23 ) ;
}
void F_42 ( struct V_24 * V_23 )
{
F_38 ( V_23 ) ;
}
bool F_43 ( struct V_24 * V_23 )
{
struct V_12 * V_13 ;
struct V_26 V_27 ;
enum V_39 V_52 ;
bool V_81 = false ;
if ( ! V_23 -> V_30 . V_31 )
return false ;
F_44 ( & V_23 -> V_30 . V_53 ) ;
F_8 ( V_23 , & V_27 ) ;
F_9 (connector, &conn_iter) {
if ( ! ( V_13 -> V_33 & V_83 ) )
continue;
V_52 = V_13 -> V_57 ;
V_13 -> V_57 = F_12 ( V_13 , false ) ;
F_16 ( L_2 ,
V_13 -> V_54 . V_55 ,
V_13 -> V_56 ,
F_17 ( V_52 ) ,
F_17 ( V_13 -> V_57 ) ) ;
if ( V_52 != V_13 -> V_57 )
V_81 = true ;
}
F_10 ( & V_27 ) ;
F_37 ( & V_23 -> V_30 . V_53 ) ;
if ( V_81 )
F_31 ( V_23 ) ;
return V_81 ;
}
