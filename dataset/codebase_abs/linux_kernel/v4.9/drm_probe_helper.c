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
V_26 = 0 ;
}
if ( V_25 )
F_11 ( & V_23 -> V_28 . V_36 , V_26 ) ;
}
int F_12 ( struct V_12 * V_13 ,
T_1 V_37 , T_1 V_38 )
{
struct V_24 * V_23 = V_13 -> V_23 ;
struct V_2 * V_3 ;
const struct V_39 * V_40 =
V_13 -> V_41 ;
int V_42 = 0 ;
int V_43 = 0 ;
bool V_44 = true ;
enum V_45 V_46 ;
F_8 ( ! F_9 ( & V_23 -> V_28 . V_29 ) ) ;
F_13 ( L_1 , V_13 -> V_47 . V_48 ,
V_13 -> V_49 ) ;
F_3 (mode, &connector->modes, head)
V_3 -> V_50 = V_51 ;
V_46 = V_13 -> V_50 ;
if ( V_13 -> V_52 ) {
if ( V_13 -> V_52 == V_53 ||
V_13 -> V_52 == V_54 )
V_13 -> V_50 = V_55 ;
else
V_13 -> V_50 = V_56 ;
if ( V_13 -> V_57 -> V_52 )
V_13 -> V_57 -> V_52 ( V_13 ) ;
} else {
V_13 -> V_50 = V_13 -> V_57 -> V_58 ( V_13 , true ) ;
}
if ( V_46 != V_13 -> V_50 ) {
F_13 ( L_2 ,
V_13 -> V_47 . V_48 ,
V_13 -> V_49 ,
F_14 ( V_46 ) ,
F_14 ( V_13 -> V_50 ) ) ;
V_23 -> V_28 . V_35 = true ;
if ( V_23 -> V_28 . V_30 )
F_11 ( & V_23 -> V_28 . V_36 ,
0 ) ;
}
if ( V_31 != V_23 -> V_28 . V_59 )
F_7 ( V_23 ) ;
V_23 -> V_28 . V_59 = V_31 ;
if ( V_13 -> V_50 == V_56 ) {
F_13 ( L_3 ,
V_13 -> V_47 . V_48 , V_13 -> V_49 ) ;
F_15 ( V_13 , NULL ) ;
V_44 = false ;
goto V_60;
}
if ( V_13 -> V_61 ) {
struct V_62 * V_62 = (struct V_62 * ) V_13 -> V_63 -> V_64 ;
V_42 = F_16 ( V_13 , V_62 ) ;
F_17 ( V_13 , V_62 ) ;
} else {
V_42 = F_18 ( V_13 ) ;
if ( V_42 == 0 )
V_42 = (* V_40 -> V_65 )( V_13 ) ;
}
if ( V_42 == 0 && V_13 -> V_50 == V_55 )
V_42 = F_19 ( V_13 , 1024 , 768 ) ;
V_42 += F_2 ( V_13 ) ;
if ( V_42 == 0 )
goto V_60;
F_20 ( V_13 ) ;
if ( V_13 -> V_66 )
V_43 |= V_5 ;
if ( V_13 -> V_67 )
V_43 |= V_7 ;
if ( V_13 -> V_68 )
V_43 |= V_9 ;
F_3 (mode, &connector->modes, head) {
if ( V_3 -> V_50 == V_11 )
V_3 -> V_50 = F_21 ( V_3 ) ;
if ( V_3 -> V_50 == V_11 )
V_3 -> V_50 = F_22 ( V_3 , V_37 , V_38 ) ;
if ( V_3 -> V_50 == V_11 )
V_3 -> V_50 = F_1 ( V_3 , V_43 ) ;
if ( V_3 -> V_50 == V_11 && V_40 -> V_69 )
V_3 -> V_50 = V_40 -> V_69 ( V_13 ,
V_3 ) ;
}
V_60:
F_23 ( V_23 , & V_13 -> V_70 , V_44 ) ;
if ( F_24 ( & V_13 -> V_70 ) )
return 0 ;
F_3 (mode, &connector->modes, head)
V_3 -> V_71 = F_4 ( V_3 ) ;
F_25 ( & V_13 -> V_70 ) ;
F_13 ( L_4 , V_13 -> V_47 . V_48 ,
V_13 -> V_49 ) ;
F_3 (mode, &connector->modes, head) {
F_26 ( V_3 , V_72 ) ;
F_27 ( V_3 ) ;
}
return V_42 ;
}
void F_28 ( struct V_24 * V_23 )
{
F_29 ( V_23 ) ;
if ( V_23 -> V_28 . V_57 -> V_73 )
V_23 -> V_28 . V_57 -> V_73 ( V_23 ) ;
}
static void F_30 ( struct V_74 * V_75 )
{
struct V_76 * V_76 = F_31 ( V_75 ) ;
struct V_24 * V_23 = F_32 ( V_76 , struct V_24 , V_28 . V_36 ) ;
struct V_12 * V_13 ;
enum V_45 V_46 ;
bool V_77 = false , V_78 ;
V_78 = V_23 -> V_28 . V_35 ;
V_23 -> V_28 . V_35 = false ;
if ( ! V_31 )
goto V_79;
F_33 ( & V_23 -> V_28 . V_29 ) ;
F_10 (connector, dev) {
if ( V_13 -> V_52 )
continue;
if ( ! V_13 -> V_32 || V_13 -> V_32 == V_80 )
continue;
V_46 = V_13 -> V_50 ;
if ( V_46 == V_55 &&
! ( V_13 -> V_32 & V_34 ) )
continue;
V_77 = true ;
V_13 -> V_50 = V_13 -> V_57 -> V_58 ( V_13 , false ) ;
if ( V_46 != V_13 -> V_50 ) {
const char * V_81 , * V_82 ;
if ( V_13 -> V_50 == V_83 ) {
V_13 -> V_50 = V_46 ;
continue;
}
V_81 = F_14 ( V_46 ) ;
V_82 = F_14 ( V_13 -> V_50 ) ;
F_13 ( L_5
L_6 ,
V_13 -> V_47 . V_48 ,
V_13 -> V_49 ,
V_81 , V_82 ) ;
V_78 = true ;
}
}
F_34 ( & V_23 -> V_28 . V_29 ) ;
V_79:
if ( V_78 )
F_28 ( V_23 ) ;
if ( V_77 )
F_11 ( V_76 , V_27 ) ;
}
void F_35 ( struct V_24 * V_23 )
{
if ( ! V_23 -> V_28 . V_30 )
return;
F_36 ( & V_23 -> V_28 . V_36 ) ;
}
void F_37 ( struct V_24 * V_23 )
{
F_33 ( & V_23 -> V_28 . V_29 ) ;
F_7 ( V_23 ) ;
F_34 ( & V_23 -> V_28 . V_29 ) ;
}
void F_38 ( struct V_24 * V_23 )
{
F_39 ( & V_23 -> V_28 . V_36 , F_30 ) ;
V_23 -> V_28 . V_30 = true ;
F_37 ( V_23 ) ;
}
void F_40 ( struct V_24 * V_23 )
{
F_35 ( V_23 ) ;
}
bool F_41 ( struct V_24 * V_23 )
{
struct V_12 * V_13 ;
enum V_45 V_46 ;
bool V_78 = false ;
if ( ! V_23 -> V_28 . V_30 )
return false ;
F_33 ( & V_23 -> V_28 . V_29 ) ;
F_10 (connector, dev) {
if ( ! ( V_13 -> V_32 & V_80 ) )
continue;
V_46 = V_13 -> V_50 ;
V_13 -> V_50 = V_13 -> V_57 -> V_58 ( V_13 , false ) ;
F_13 ( L_2 ,
V_13 -> V_47 . V_48 ,
V_13 -> V_49 ,
F_14 ( V_46 ) ,
F_14 ( V_13 -> V_50 ) ) ;
if ( V_46 != V_13 -> V_50 )
V_78 = true ;
}
F_34 ( & V_23 -> V_28 . V_29 ) ;
if ( V_78 )
F_28 ( V_23 ) ;
return V_78 ;
}
