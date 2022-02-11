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
const struct V_41 * V_42 = V_13 -> V_43 ;
struct V_44 V_45 ;
int V_46 ;
F_13 ( & V_45 , 0 ) ;
V_47:
V_46 = F_14 ( & V_13 -> V_23 -> V_30 . V_48 , & V_45 ) ;
if ( ! V_46 ) {
if ( V_42 -> V_49 )
V_46 = V_42 -> V_49 ( V_13 , & V_45 , V_40 ) ;
else if ( V_13 -> V_42 -> V_50 )
V_46 = V_13 -> V_42 -> V_50 ( V_13 , V_40 ) ;
else
V_46 = V_51 ;
}
if ( V_46 == - V_52 ) {
F_15 ( & V_45 ) ;
goto V_47;
}
if ( F_16 ( V_46 < 0 ) )
V_46 = V_53 ;
F_17 ( & V_45 ) ;
F_18 ( & V_45 ) ;
return V_46 ;
}
int
F_19 ( struct V_12 * V_13 ,
struct V_44 * V_45 ,
bool V_40 )
{
const struct V_41 * V_42 = V_13 -> V_43 ;
struct V_24 * V_23 = V_13 -> V_23 ;
int V_46 ;
if ( ! V_45 )
return F_12 ( V_13 , V_40 ) ;
V_46 = F_14 ( & V_23 -> V_30 . V_48 , V_45 ) ;
if ( V_46 )
return V_46 ;
if ( V_42 -> V_49 )
return V_42 -> V_49 ( V_13 , V_45 , V_40 ) ;
else if ( V_13 -> V_42 -> V_50 )
return V_13 -> V_42 -> V_50 ( V_13 , V_40 ) ;
else
return V_51 ;
}
int F_20 ( struct V_12 * V_13 ,
T_1 V_54 , T_1 V_55 )
{
struct V_24 * V_23 = V_13 -> V_23 ;
struct V_2 * V_3 ;
const struct V_41 * V_56 =
V_13 -> V_43 ;
int V_57 = 0 , V_46 ;
int V_58 = 0 ;
bool V_59 = true ;
enum V_39 V_60 ;
struct V_44 V_45 ;
F_16 ( ! F_21 ( & V_23 -> V_30 . V_61 ) ) ;
F_13 ( & V_45 , 0 ) ;
F_22 ( L_1 , V_13 -> V_62 . V_63 ,
V_13 -> V_64 ) ;
V_47:
V_46 = F_14 ( & V_23 -> V_30 . V_48 , & V_45 ) ;
if ( V_46 == - V_52 ) {
F_15 ( & V_45 ) ;
goto V_47;
} else
F_16 ( V_46 < 0 ) ;
F_3 (mode, &connector->modes, head)
V_3 -> V_65 = V_66 ;
V_60 = V_13 -> V_65 ;
if ( V_13 -> V_40 ) {
if ( V_13 -> V_40 == V_67 ||
V_13 -> V_40 == V_68 )
V_13 -> V_65 = V_51 ;
else
V_13 -> V_65 = V_69 ;
if ( V_13 -> V_42 -> V_40 )
V_13 -> V_42 -> V_40 ( V_13 ) ;
} else {
V_46 = F_19 ( V_13 , & V_45 , true ) ;
if ( V_46 == - V_52 ) {
F_15 ( & V_45 ) ;
goto V_47;
} else if ( F_23 ( V_46 < 0 , L_2 , V_46 ) )
V_46 = V_53 ;
V_13 -> V_65 = V_46 ;
}
if ( V_60 != V_13 -> V_65 ) {
F_22 ( L_3 ,
V_13 -> V_62 . V_63 ,
V_13 -> V_64 ,
F_24 ( V_60 ) ,
F_24 ( V_13 -> V_65 ) ) ;
V_23 -> V_30 . V_36 = true ;
if ( V_23 -> V_30 . V_31 )
F_11 ( & V_23 -> V_30 . V_38 ,
0 ) ;
}
if ( V_32 != V_23 -> V_30 . V_70 )
F_7 ( V_23 ) ;
V_23 -> V_30 . V_70 = V_32 ;
if ( V_13 -> V_65 == V_69 ) {
F_22 ( L_4 ,
V_13 -> V_62 . V_63 , V_13 -> V_64 ) ;
F_25 ( V_13 , NULL ) ;
V_59 = false ;
goto V_71;
}
if ( V_13 -> V_72 ) {
struct V_73 * V_73 = (struct V_73 * ) V_13 -> V_74 -> V_75 ;
V_57 = F_26 ( V_13 , V_73 ) ;
F_27 ( V_13 , V_73 ) ;
} else {
struct V_73 * V_73 = F_28 ( V_13 ) ;
if ( ! F_29 ( V_73 ) ) {
F_25 ( V_13 , V_73 ) ;
V_57 = F_26 ( V_13 , V_73 ) ;
F_27 ( V_13 , V_73 ) ;
F_30 ( V_73 ) ;
}
if ( V_57 == 0 )
V_57 = (* V_56 -> V_76 )( V_13 ) ;
}
if ( V_57 == 0 && V_13 -> V_65 == V_51 )
V_57 = F_31 ( V_13 , 1024 , 768 ) ;
V_57 += F_2 ( V_13 ) ;
if ( V_57 == 0 )
goto V_71;
F_32 ( V_13 ) ;
if ( V_13 -> V_77 )
V_58 |= V_5 ;
if ( V_13 -> V_78 )
V_58 |= V_7 ;
if ( V_13 -> V_79 )
V_58 |= V_9 ;
F_3 (mode, &connector->modes, head) {
if ( V_3 -> V_65 == V_11 )
V_3 -> V_65 = F_33 ( V_3 ) ;
if ( V_3 -> V_65 == V_11 )
V_3 -> V_65 = F_34 ( V_3 , V_54 , V_55 ) ;
if ( V_3 -> V_65 == V_11 )
V_3 -> V_65 = F_1 ( V_3 , V_58 ) ;
if ( V_3 -> V_65 == V_11 && V_56 -> V_80 )
V_3 -> V_65 = V_56 -> V_80 ( V_13 ,
V_3 ) ;
}
V_71:
F_35 ( V_23 , & V_13 -> V_81 , V_59 ) ;
F_17 ( & V_45 ) ;
F_18 ( & V_45 ) ;
if ( F_36 ( & V_13 -> V_81 ) )
return 0 ;
F_3 (mode, &connector->modes, head)
V_3 -> V_82 = F_4 ( V_3 ) ;
F_37 ( & V_13 -> V_81 ) ;
F_22 ( L_5 , V_13 -> V_62 . V_63 ,
V_13 -> V_64 ) ;
F_3 (mode, &connector->modes, head) {
F_38 ( V_3 , V_83 ) ;
F_39 ( V_3 ) ;
}
return V_57 ;
}
void F_40 ( struct V_24 * V_23 )
{
F_41 ( V_23 ) ;
if ( V_23 -> V_30 . V_42 -> V_84 )
V_23 -> V_30 . V_42 -> V_84 ( V_23 ) ;
}
static void F_42 ( struct V_85 * V_86 )
{
struct V_87 * V_87 = F_43 ( V_86 ) ;
struct V_24 * V_23 = F_44 ( V_87 , struct V_24 , V_30 . V_38 ) ;
struct V_12 * V_13 ;
struct V_26 V_27 ;
enum V_39 V_60 ;
bool V_88 = false , V_89 ;
V_89 = V_23 -> V_30 . V_36 ;
V_23 -> V_30 . V_36 = false ;
if ( ! V_32 )
goto V_90;
if ( ! F_45 ( & V_23 -> V_30 . V_61 ) ) {
V_88 = true ;
goto V_90;
}
F_8 ( V_23 , & V_27 ) ;
F_9 (connector, &conn_iter) {
if ( V_13 -> V_40 )
continue;
if ( ! V_13 -> V_33 || V_13 -> V_33 == V_91 )
continue;
V_60 = V_13 -> V_65 ;
if ( V_60 == V_51 &&
! ( V_13 -> V_33 & V_35 ) )
continue;
V_88 = true ;
V_13 -> V_65 = F_19 ( V_13 , NULL , false ) ;
if ( V_60 != V_13 -> V_65 ) {
const char * V_92 , * V_93 ;
if ( V_13 -> V_65 == V_53 ) {
V_13 -> V_65 = V_60 ;
continue;
}
V_92 = F_24 ( V_60 ) ;
V_93 = F_24 ( V_13 -> V_65 ) ;
F_22 ( L_6
L_7 ,
V_13 -> V_62 . V_63 ,
V_13 -> V_64 ,
V_92 , V_93 ) ;
V_89 = true ;
}
}
F_10 ( & V_27 ) ;
F_46 ( & V_23 -> V_30 . V_61 ) ;
V_90:
if ( V_89 )
F_40 ( V_23 ) ;
if ( V_88 )
F_11 ( V_87 , V_29 ) ;
}
void F_47 ( struct V_24 * V_23 )
{
if ( ! V_23 -> V_30 . V_31 )
return;
F_48 ( & V_23 -> V_30 . V_38 ) ;
}
void F_49 ( struct V_24 * V_23 )
{
F_50 ( & V_23 -> V_30 . V_38 , F_42 ) ;
V_23 -> V_30 . V_31 = true ;
F_7 ( V_23 ) ;
}
void F_51 ( struct V_24 * V_23 )
{
F_47 ( V_23 ) ;
}
bool F_52 ( struct V_24 * V_23 )
{
struct V_12 * V_13 ;
struct V_26 V_27 ;
enum V_39 V_60 ;
bool V_89 = false ;
if ( ! V_23 -> V_30 . V_31 )
return false ;
F_53 ( & V_23 -> V_30 . V_61 ) ;
F_8 ( V_23 , & V_27 ) ;
F_9 (connector, &conn_iter) {
if ( ! ( V_13 -> V_33 & V_91 ) )
continue;
V_60 = V_13 -> V_65 ;
V_13 -> V_65 = F_19 ( V_13 , NULL , false ) ;
F_22 ( L_3 ,
V_13 -> V_62 . V_63 ,
V_13 -> V_64 ,
F_24 ( V_60 ) ,
F_24 ( V_13 -> V_65 ) ) ;
if ( V_60 != V_13 -> V_65 )
V_89 = true ;
}
F_10 ( & V_27 ) ;
F_46 ( & V_23 -> V_30 . V_61 ) ;
if ( V_89 )
F_40 ( V_23 ) ;
return V_89 ;
}
