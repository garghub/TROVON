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
F_8 ( ! F_9 ( & V_23 -> V_26 . V_27 ) ) ;
if ( ! V_23 -> V_26 . V_28 || ! V_29 )
return;
F_10 (connector, dev) {
if ( V_13 -> V_30 & ( V_31 |
V_32 ) )
V_25 = true ;
}
if ( V_25 )
F_11 ( & V_23 -> V_26 . V_33 , V_34 ) ;
}
int F_12 ( struct V_12 * V_13 ,
T_1 V_35 , T_1 V_36 )
{
struct V_24 * V_23 = V_13 -> V_23 ;
struct V_2 * V_3 ;
const struct V_37 * V_38 =
V_13 -> V_39 ;
int V_40 = 0 ;
int V_41 = 0 ;
bool V_42 = true ;
enum V_43 V_44 ;
F_8 ( ! F_9 ( & V_23 -> V_26 . V_27 ) ) ;
F_13 ( L_1 , V_13 -> V_45 . V_46 ,
V_13 -> V_47 ) ;
F_3 (mode, &connector->modes, head)
V_3 -> V_48 = V_49 ;
V_44 = V_13 -> V_48 ;
if ( V_13 -> V_50 ) {
if ( V_13 -> V_50 == V_51 ||
V_13 -> V_50 == V_52 )
V_13 -> V_48 = V_53 ;
else
V_13 -> V_48 = V_54 ;
if ( V_13 -> V_55 -> V_50 )
V_13 -> V_55 -> V_50 ( V_13 ) ;
} else {
V_13 -> V_48 = V_13 -> V_55 -> V_56 ( V_13 , true ) ;
}
if ( V_44 != V_13 -> V_48 ) {
F_13 ( L_2 ,
V_13 -> V_45 . V_46 ,
V_13 -> V_47 ,
F_14 ( V_44 ) ,
F_14 ( V_13 -> V_48 ) ) ;
V_23 -> V_26 . V_57 = true ;
if ( V_23 -> V_26 . V_28 )
F_11 ( & V_23 -> V_26 . V_33 ,
0 ) ;
}
if ( V_29 != V_23 -> V_26 . V_58 )
F_7 ( V_23 ) ;
V_23 -> V_26 . V_58 = V_29 ;
if ( V_13 -> V_48 == V_54 ) {
F_13 ( L_3 ,
V_13 -> V_45 . V_46 , V_13 -> V_47 ) ;
F_15 ( V_13 , NULL ) ;
V_42 = false ;
goto V_59;
}
if ( V_13 -> V_60 ) {
struct V_61 * V_61 = (struct V_61 * ) V_13 -> V_62 -> V_63 ;
V_40 = F_16 ( V_13 , V_61 ) ;
F_17 ( V_13 , V_61 ) ;
} else {
V_40 = F_18 ( V_13 ) ;
if ( V_40 == 0 )
V_40 = (* V_38 -> V_64 )( V_13 ) ;
}
if ( V_40 == 0 && V_13 -> V_48 == V_53 )
V_40 = F_19 ( V_13 , 1024 , 768 ) ;
V_40 += F_2 ( V_13 ) ;
if ( V_40 == 0 )
goto V_59;
F_20 ( V_13 ) ;
if ( V_13 -> V_65 )
V_41 |= V_5 ;
if ( V_13 -> V_66 )
V_41 |= V_7 ;
if ( V_13 -> V_67 )
V_41 |= V_9 ;
F_3 (mode, &connector->modes, head) {
if ( V_3 -> V_48 == V_11 )
V_3 -> V_48 = F_21 ( V_3 ) ;
if ( V_3 -> V_48 == V_11 )
V_3 -> V_48 = F_22 ( V_3 , V_35 , V_36 ) ;
if ( V_3 -> V_48 == V_11 )
V_3 -> V_48 = F_1 ( V_3 , V_41 ) ;
if ( V_3 -> V_48 == V_11 && V_38 -> V_68 )
V_3 -> V_48 = V_38 -> V_68 ( V_13 ,
V_3 ) ;
}
V_59:
F_23 ( V_23 , & V_13 -> V_69 , V_42 ) ;
if ( F_24 ( & V_13 -> V_69 ) )
return 0 ;
F_3 (mode, &connector->modes, head)
V_3 -> V_70 = F_4 ( V_3 ) ;
F_25 ( & V_13 -> V_69 ) ;
F_13 ( L_4 , V_13 -> V_45 . V_46 ,
V_13 -> V_47 ) ;
F_3 (mode, &connector->modes, head) {
F_26 ( V_3 , V_71 ) ;
F_27 ( V_3 ) ;
}
return V_40 ;
}
void F_28 ( struct V_24 * V_23 )
{
F_29 ( V_23 ) ;
if ( V_23 -> V_26 . V_55 -> V_72 )
V_23 -> V_26 . V_55 -> V_72 ( V_23 ) ;
}
static void F_30 ( struct V_73 * V_74 )
{
struct V_75 * V_75 = F_31 ( V_74 ) ;
struct V_24 * V_23 = F_32 ( V_75 , struct V_24 , V_26 . V_33 ) ;
struct V_12 * V_13 ;
enum V_43 V_44 ;
bool V_76 = false , V_77 ;
V_77 = V_23 -> V_26 . V_57 ;
V_23 -> V_26 . V_57 = false ;
if ( ! V_29 )
goto V_78;
F_33 ( & V_23 -> V_26 . V_27 ) ;
F_10 (connector, dev) {
if ( V_13 -> V_50 )
continue;
if ( ! V_13 -> V_30 || V_13 -> V_30 == V_79 )
continue;
V_44 = V_13 -> V_48 ;
if ( V_44 == V_53 &&
! ( V_13 -> V_30 & V_32 ) )
continue;
V_76 = true ;
V_13 -> V_48 = V_13 -> V_55 -> V_56 ( V_13 , false ) ;
if ( V_44 != V_13 -> V_48 ) {
const char * V_80 , * V_81 ;
if ( V_13 -> V_48 == V_82 ) {
V_13 -> V_48 = V_44 ;
continue;
}
V_80 = F_14 ( V_44 ) ;
V_81 = F_14 ( V_13 -> V_48 ) ;
F_13 ( L_5
L_6 ,
V_13 -> V_45 . V_46 ,
V_13 -> V_47 ,
V_80 , V_81 ) ;
V_77 = true ;
}
}
F_34 ( & V_23 -> V_26 . V_27 ) ;
V_78:
if ( V_77 )
F_28 ( V_23 ) ;
if ( V_76 )
F_11 ( V_75 , V_34 ) ;
}
void F_35 ( struct V_24 * V_23 )
{
if ( ! V_23 -> V_26 . V_28 )
return;
F_36 ( & V_23 -> V_26 . V_33 ) ;
}
void F_37 ( struct V_24 * V_23 )
{
F_33 ( & V_23 -> V_26 . V_27 ) ;
F_7 ( V_23 ) ;
F_34 ( & V_23 -> V_26 . V_27 ) ;
}
void F_38 ( struct V_24 * V_23 )
{
F_39 ( & V_23 -> V_26 . V_33 , F_30 ) ;
V_23 -> V_26 . V_28 = true ;
F_37 ( V_23 ) ;
}
void F_40 ( struct V_24 * V_23 )
{
F_35 ( V_23 ) ;
}
bool F_41 ( struct V_24 * V_23 )
{
struct V_12 * V_13 ;
enum V_43 V_44 ;
bool V_77 = false ;
if ( ! V_23 -> V_26 . V_28 )
return false ;
F_33 ( & V_23 -> V_26 . V_27 ) ;
F_10 (connector, dev) {
if ( ! ( V_13 -> V_30 & V_79 ) )
continue;
V_44 = V_13 -> V_48 ;
V_13 -> V_48 = V_13 -> V_55 -> V_56 ( V_13 , false ) ;
F_13 ( L_2 ,
V_13 -> V_45 . V_46 ,
V_13 -> V_47 ,
F_14 ( V_44 ) ,
F_14 ( V_13 -> V_48 ) ) ;
if ( V_44 != V_13 -> V_48 )
V_77 = true ;
}
F_34 ( & V_23 -> V_26 . V_27 ) ;
if ( V_77 )
F_28 ( V_23 ) ;
return V_77 ;
}
