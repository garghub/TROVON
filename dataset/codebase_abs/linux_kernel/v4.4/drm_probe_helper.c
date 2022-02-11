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
struct V_2 * V_3 ;
if ( ! V_13 -> V_14 . V_15 )
return 0 ;
V_3 = F_3 ( V_13 -> V_16 ,
& V_13 -> V_14 ) ;
if ( V_3 == NULL )
return 0 ;
F_4 ( V_13 , V_3 ) ;
return 1 ;
}
void F_5 ( struct V_17 * V_16 )
{
bool V_18 = false ;
struct V_12 * V_13 ;
F_6 ( ! F_7 ( & V_16 -> V_19 . V_20 ) ) ;
if ( ! V_16 -> V_19 . V_21 || ! V_22 )
return;
F_8 (connector, dev) {
if ( V_13 -> V_23 & ( V_24 |
V_25 ) )
V_18 = true ;
}
if ( V_18 )
F_9 ( & V_16 -> V_19 . V_26 , V_27 ) ;
}
static int F_10 ( struct V_12 * V_13 ,
T_1 V_28 , T_1 V_29 , bool V_30 )
{
struct V_17 * V_16 = V_13 -> V_16 ;
struct V_2 * V_3 ;
const struct V_31 * V_32 =
V_13 -> V_33 ;
int V_34 = 0 ;
int V_35 = 0 ;
bool V_36 = true ;
enum V_37 V_38 ;
F_6 ( ! F_7 ( & V_16 -> V_19 . V_20 ) ) ;
F_11 ( L_1 , V_13 -> V_39 . V_40 ,
V_13 -> V_41 ) ;
F_12 (mode, &connector->modes, head)
V_3 -> V_42 = V_43 ;
if ( V_13 -> V_44 ) {
if ( V_13 -> V_44 == V_45 ||
V_13 -> V_44 == V_46 )
V_13 -> V_42 = V_47 ;
else
V_13 -> V_42 = V_48 ;
if ( V_13 -> V_49 -> V_44 )
V_13 -> V_49 -> V_44 ( V_13 ) ;
} else {
V_38 = V_13 -> V_42 ;
V_13 -> V_42 = V_13 -> V_49 -> V_50 ( V_13 , true ) ;
if ( V_38 != V_13 -> V_42 ) {
F_11 ( L_2 ,
V_13 -> V_39 . V_40 ,
V_13 -> V_41 ,
V_38 , V_13 -> V_42 ) ;
V_16 -> V_19 . V_51 = true ;
if ( V_16 -> V_19 . V_21 )
F_9 ( & V_16 -> V_19 . V_26 ,
0 ) ;
}
}
if ( V_22 != V_16 -> V_19 . V_52 )
F_5 ( V_16 ) ;
V_16 -> V_19 . V_52 = V_22 ;
if ( V_13 -> V_42 == V_48 ) {
F_11 ( L_3 ,
V_13 -> V_39 . V_40 , V_13 -> V_41 ) ;
F_13 ( V_13 , NULL ) ;
V_36 = false ;
goto V_53;
}
#ifdef F_14
V_34 = F_15 ( V_13 ) ;
if ( V_34 == 0 )
#endif
{
if ( V_13 -> V_54 ) {
struct V_55 * V_55 = (struct V_55 * ) V_13 -> V_56 -> V_57 ;
V_34 = F_16 ( V_13 , V_55 ) ;
F_17 ( V_13 , V_55 ) ;
} else
V_34 = (* V_32 -> V_58 )( V_13 ) ;
}
if ( V_34 == 0 && V_13 -> V_42 == V_47 )
V_34 = F_18 ( V_13 , 1024 , 768 ) ;
V_34 += F_2 ( V_13 ) ;
if ( V_34 == 0 )
goto V_53;
F_19 ( V_13 , V_30 ) ;
if ( V_13 -> V_59 )
V_35 |= V_5 ;
if ( V_13 -> V_60 )
V_35 |= V_7 ;
if ( V_13 -> V_61 )
V_35 |= V_9 ;
F_12 (mode, &connector->modes, head) {
if ( V_3 -> V_42 == V_11 )
V_3 -> V_42 = F_20 ( V_3 ) ;
if ( V_3 -> V_42 == V_11 )
V_3 -> V_42 = F_21 ( V_3 , V_28 , V_29 ) ;
if ( V_3 -> V_42 == V_11 )
V_3 -> V_42 = F_1 ( V_3 , V_35 ) ;
if ( V_3 -> V_42 == V_11 && V_32 -> V_62 )
V_3 -> V_42 = V_32 -> V_62 ( V_13 ,
V_3 ) ;
}
V_53:
F_22 ( V_16 , & V_13 -> V_63 , V_36 ) ;
if ( F_23 ( & V_13 -> V_63 ) )
return 0 ;
F_12 (mode, &connector->modes, head)
V_3 -> V_64 = F_24 ( V_3 ) ;
F_25 ( & V_13 -> V_63 ) ;
F_11 ( L_4 , V_13 -> V_39 . V_40 ,
V_13 -> V_41 ) ;
F_12 (mode, &connector->modes, head) {
F_26 ( V_3 , V_65 ) ;
F_27 ( V_3 ) ;
}
return V_34 ;
}
int F_28 ( struct V_12 * V_13 ,
T_1 V_28 , T_1 V_29 )
{
return F_10 ( V_13 , V_28 , V_29 , true ) ;
}
int F_29 ( struct V_12 * V_13 ,
T_1 V_28 , T_1 V_29 )
{
return F_10 ( V_13 , V_28 , V_29 , false ) ;
}
void F_30 ( struct V_17 * V_16 )
{
F_31 ( V_16 ) ;
if ( V_16 -> V_19 . V_49 -> V_66 )
V_16 -> V_19 . V_49 -> V_66 ( V_16 ) ;
}
static void F_32 ( struct V_67 * V_68 )
{
struct V_69 * V_69 = F_33 ( V_68 ) ;
struct V_17 * V_16 = F_34 ( V_69 , struct V_17 , V_19 . V_26 ) ;
struct V_12 * V_13 ;
enum V_37 V_38 ;
bool V_70 = false , V_71 ;
V_71 = V_16 -> V_19 . V_51 ;
V_16 -> V_19 . V_51 = false ;
if ( ! V_22 )
goto V_72;
F_35 ( & V_16 -> V_19 . V_20 ) ;
F_8 (connector, dev) {
if ( V_13 -> V_44 )
continue;
if ( ! V_13 -> V_23 || V_13 -> V_23 == V_73 )
continue;
V_38 = V_13 -> V_42 ;
if ( V_38 == V_47 &&
! ( V_13 -> V_23 & V_25 ) )
continue;
V_70 = true ;
V_13 -> V_42 = V_13 -> V_49 -> V_50 ( V_13 , false ) ;
if ( V_38 != V_13 -> V_42 ) {
const char * V_74 , * V_75 ;
if ( V_13 -> V_42 == V_76 ) {
V_13 -> V_42 = V_38 ;
continue;
}
V_74 = F_36 ( V_38 ) ;
V_75 = F_36 ( V_13 -> V_42 ) ;
F_11 ( L_5
L_6 ,
V_13 -> V_39 . V_40 ,
V_13 -> V_41 ,
V_74 , V_75 ) ;
V_71 = true ;
}
}
F_37 ( & V_16 -> V_19 . V_20 ) ;
V_72:
if ( V_71 )
F_30 ( V_16 ) ;
if ( V_70 )
F_9 ( V_69 , V_27 ) ;
}
void F_38 ( struct V_17 * V_16 )
{
if ( ! V_16 -> V_19 . V_21 )
return;
F_39 ( & V_16 -> V_19 . V_26 ) ;
}
void F_40 ( struct V_17 * V_16 )
{
F_35 ( & V_16 -> V_19 . V_20 ) ;
F_5 ( V_16 ) ;
F_37 ( & V_16 -> V_19 . V_20 ) ;
}
void F_41 ( struct V_17 * V_16 )
{
F_42 ( & V_16 -> V_19 . V_26 , F_32 ) ;
V_16 -> V_19 . V_21 = true ;
F_40 ( V_16 ) ;
}
void F_43 ( struct V_17 * V_16 )
{
F_38 ( V_16 ) ;
}
bool F_44 ( struct V_17 * V_16 )
{
struct V_12 * V_13 ;
enum V_37 V_38 ;
bool V_71 = false ;
if ( ! V_16 -> V_19 . V_21 )
return false ;
F_35 ( & V_16 -> V_19 . V_20 ) ;
F_8 (connector, dev) {
if ( ! ( V_13 -> V_23 & V_73 ) )
continue;
V_38 = V_13 -> V_42 ;
V_13 -> V_42 = V_13 -> V_49 -> V_50 ( V_13 , false ) ;
F_11 ( L_7 ,
V_13 -> V_39 . V_40 ,
V_13 -> V_41 ,
F_36 ( V_38 ) ,
F_36 ( V_13 -> V_42 ) ) ;
if ( V_38 != V_13 -> V_42 )
V_71 = true ;
}
F_37 ( & V_16 -> V_19 . V_20 ) ;
if ( V_71 )
F_30 ( V_16 ) ;
return V_71 ;
}
