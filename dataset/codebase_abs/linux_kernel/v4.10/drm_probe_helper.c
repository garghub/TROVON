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
unsigned long V_26 = V_27 ;
F_8 ( ! F_9 ( & V_23 -> V_28 . V_29 ) ) ;
if ( ! V_23 -> V_28 . V_30 || ! V_31 )
return;
F_10 (connector, dev) {
if ( V_13 -> V_32 & ( V_33 |
V_34 ) )
V_25 = true ;
}
if ( V_23 -> V_28 . V_35 ) {
V_25 = true ;
V_26 = V_36 ;
}
if ( V_25 )
F_11 ( & V_23 -> V_28 . V_37 , V_26 ) ;
}
static enum V_38
F_12 ( struct V_12 * V_13 , bool V_39 )
{
return V_13 -> V_40 -> V_41 ?
V_13 -> V_40 -> V_41 ( V_13 , V_39 ) :
V_42 ;
}
int F_13 ( struct V_12 * V_13 ,
T_1 V_43 , T_1 V_44 )
{
struct V_24 * V_23 = V_13 -> V_23 ;
struct V_2 * V_3 ;
const struct V_45 * V_46 =
V_13 -> V_47 ;
int V_48 = 0 ;
int V_49 = 0 ;
bool V_50 = true ;
enum V_38 V_51 ;
F_8 ( ! F_9 ( & V_23 -> V_28 . V_29 ) ) ;
F_14 ( L_1 , V_13 -> V_52 . V_53 ,
V_13 -> V_54 ) ;
F_3 (mode, &connector->modes, head)
V_3 -> V_55 = V_56 ;
V_51 = V_13 -> V_55 ;
if ( V_13 -> V_39 ) {
if ( V_13 -> V_39 == V_57 ||
V_13 -> V_39 == V_58 )
V_13 -> V_55 = V_42 ;
else
V_13 -> V_55 = V_59 ;
if ( V_13 -> V_40 -> V_39 )
V_13 -> V_40 -> V_39 ( V_13 ) ;
} else {
V_13 -> V_55 = F_12 ( V_13 , true ) ;
}
if ( V_51 != V_13 -> V_55 ) {
F_14 ( L_2 ,
V_13 -> V_52 . V_53 ,
V_13 -> V_54 ,
F_15 ( V_51 ) ,
F_15 ( V_13 -> V_55 ) ) ;
V_23 -> V_28 . V_35 = true ;
if ( V_23 -> V_28 . V_30 )
F_11 ( & V_23 -> V_28 . V_37 ,
0 ) ;
}
if ( V_31 != V_23 -> V_28 . V_60 )
F_7 ( V_23 ) ;
V_23 -> V_28 . V_60 = V_31 ;
if ( V_13 -> V_55 == V_59 ) {
F_14 ( L_3 ,
V_13 -> V_52 . V_53 , V_13 -> V_54 ) ;
F_16 ( V_13 , NULL ) ;
V_50 = false ;
goto V_61;
}
if ( V_13 -> V_62 ) {
struct V_63 * V_63 = (struct V_63 * ) V_13 -> V_64 -> V_65 ;
V_48 = F_17 ( V_13 , V_63 ) ;
F_18 ( V_13 , V_63 ) ;
} else {
V_48 = F_19 ( V_13 ) ;
if ( V_48 == 0 )
V_48 = (* V_46 -> V_66 )( V_13 ) ;
}
if ( V_48 == 0 && V_13 -> V_55 == V_42 )
V_48 = F_20 ( V_13 , 1024 , 768 ) ;
V_48 += F_2 ( V_13 ) ;
if ( V_48 == 0 )
goto V_61;
F_21 ( V_13 ) ;
if ( V_13 -> V_67 )
V_49 |= V_5 ;
if ( V_13 -> V_68 )
V_49 |= V_7 ;
if ( V_13 -> V_69 )
V_49 |= V_9 ;
F_3 (mode, &connector->modes, head) {
if ( V_3 -> V_55 == V_11 )
V_3 -> V_55 = F_22 ( V_3 ) ;
if ( V_3 -> V_55 == V_11 )
V_3 -> V_55 = F_23 ( V_3 , V_43 , V_44 ) ;
if ( V_3 -> V_55 == V_11 )
V_3 -> V_55 = F_1 ( V_3 , V_49 ) ;
if ( V_3 -> V_55 == V_11 && V_46 -> V_70 )
V_3 -> V_55 = V_46 -> V_70 ( V_13 ,
V_3 ) ;
}
V_61:
F_24 ( V_23 , & V_13 -> V_71 , V_50 ) ;
if ( F_25 ( & V_13 -> V_71 ) )
return 0 ;
F_3 (mode, &connector->modes, head)
V_3 -> V_72 = F_4 ( V_3 ) ;
F_26 ( & V_13 -> V_71 ) ;
F_14 ( L_4 , V_13 -> V_52 . V_53 ,
V_13 -> V_54 ) ;
F_3 (mode, &connector->modes, head) {
F_27 ( V_3 , V_73 ) ;
F_28 ( V_3 ) ;
}
return V_48 ;
}
void F_29 ( struct V_24 * V_23 )
{
F_30 ( V_23 ) ;
if ( V_23 -> V_28 . V_40 -> V_74 )
V_23 -> V_28 . V_40 -> V_74 ( V_23 ) ;
}
static void F_31 ( struct V_75 * V_76 )
{
struct V_77 * V_77 = F_32 ( V_76 ) ;
struct V_24 * V_23 = F_33 ( V_77 , struct V_24 , V_28 . V_37 ) ;
struct V_12 * V_13 ;
enum V_38 V_51 ;
bool V_78 = false , V_79 ;
V_79 = V_23 -> V_28 . V_35 ;
V_23 -> V_28 . V_35 = false ;
if ( ! V_31 )
goto V_80;
if ( ! F_34 ( & V_23 -> V_28 . V_29 ) ) {
V_78 = true ;
goto V_80;
}
F_10 (connector, dev) {
if ( V_13 -> V_39 )
continue;
if ( ! V_13 -> V_32 || V_13 -> V_32 == V_81 )
continue;
V_51 = V_13 -> V_55 ;
if ( V_51 == V_42 &&
! ( V_13 -> V_32 & V_34 ) )
continue;
V_78 = true ;
V_13 -> V_55 = F_12 ( V_13 , false ) ;
if ( V_51 != V_13 -> V_55 ) {
const char * V_82 , * V_83 ;
if ( V_13 -> V_55 == V_84 ) {
V_13 -> V_55 = V_51 ;
continue;
}
V_82 = F_15 ( V_51 ) ;
V_83 = F_15 ( V_13 -> V_55 ) ;
F_14 ( L_5
L_6 ,
V_13 -> V_52 . V_53 ,
V_13 -> V_54 ,
V_82 , V_83 ) ;
V_79 = true ;
}
}
F_35 ( & V_23 -> V_28 . V_29 ) ;
V_80:
if ( V_79 )
F_29 ( V_23 ) ;
if ( V_78 )
F_11 ( V_77 , V_27 ) ;
}
void F_36 ( struct V_24 * V_23 )
{
if ( ! V_23 -> V_28 . V_30 )
return;
F_37 ( & V_23 -> V_28 . V_37 ) ;
}
void F_38 ( struct V_24 * V_23 )
{
F_39 ( & V_23 -> V_28 . V_29 ) ;
F_7 ( V_23 ) ;
F_35 ( & V_23 -> V_28 . V_29 ) ;
}
void F_40 ( struct V_24 * V_23 )
{
F_41 ( & V_23 -> V_28 . V_37 , F_31 ) ;
V_23 -> V_28 . V_30 = true ;
F_38 ( V_23 ) ;
}
void F_42 ( struct V_24 * V_23 )
{
F_36 ( V_23 ) ;
}
bool F_43 ( struct V_24 * V_23 )
{
struct V_12 * V_13 ;
enum V_38 V_51 ;
bool V_79 = false ;
if ( ! V_23 -> V_28 . V_30 )
return false ;
F_39 ( & V_23 -> V_28 . V_29 ) ;
F_10 (connector, dev) {
if ( ! ( V_13 -> V_32 & V_81 ) )
continue;
V_51 = V_13 -> V_55 ;
V_13 -> V_55 = F_12 ( V_13 , false ) ;
F_14 ( L_2 ,
V_13 -> V_52 . V_53 ,
V_13 -> V_54 ,
F_15 ( V_51 ) ,
F_15 ( V_13 -> V_55 ) ) ;
if ( V_51 != V_13 -> V_55 )
V_79 = true ;
}
F_35 ( & V_23 -> V_28 . V_29 ) ;
if ( V_79 )
F_29 ( V_23 ) ;
return V_79 ;
}
