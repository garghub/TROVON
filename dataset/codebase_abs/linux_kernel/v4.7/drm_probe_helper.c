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
int F_10 ( struct V_12 * V_13 ,
T_1 V_28 , T_1 V_29 )
{
struct V_17 * V_16 = V_13 -> V_16 ;
struct V_2 * V_3 ;
const struct V_30 * V_31 =
V_13 -> V_32 ;
int V_33 = 0 ;
int V_34 = 0 ;
bool V_35 = true ;
enum V_36 V_37 ;
F_6 ( ! F_7 ( & V_16 -> V_19 . V_20 ) ) ;
F_11 ( L_1 , V_13 -> V_38 . V_39 ,
V_13 -> V_40 ) ;
F_12 (mode, &connector->modes, head)
V_3 -> V_41 = V_42 ;
V_37 = V_13 -> V_41 ;
if ( V_13 -> V_43 ) {
if ( V_13 -> V_43 == V_44 ||
V_13 -> V_43 == V_45 )
V_13 -> V_41 = V_46 ;
else
V_13 -> V_41 = V_47 ;
if ( V_13 -> V_48 -> V_43 )
V_13 -> V_48 -> V_43 ( V_13 ) ;
} else {
V_13 -> V_41 = V_13 -> V_48 -> V_49 ( V_13 , true ) ;
}
if ( V_37 != V_13 -> V_41 ) {
F_11 ( L_2 ,
V_13 -> V_38 . V_39 ,
V_13 -> V_40 ,
F_13 ( V_37 ) ,
F_13 ( V_13 -> V_41 ) ) ;
V_16 -> V_19 . V_50 = true ;
if ( V_16 -> V_19 . V_21 )
F_9 ( & V_16 -> V_19 . V_26 ,
0 ) ;
}
if ( V_22 != V_16 -> V_19 . V_51 )
F_5 ( V_16 ) ;
V_16 -> V_19 . V_51 = V_22 ;
if ( V_13 -> V_41 == V_47 ) {
F_11 ( L_3 ,
V_13 -> V_38 . V_39 , V_13 -> V_40 ) ;
F_14 ( V_13 , NULL ) ;
V_35 = false ;
goto V_52;
}
if ( V_13 -> V_53 ) {
struct V_54 * V_54 = (struct V_54 * ) V_13 -> V_55 -> V_56 ;
V_33 = F_15 ( V_13 , V_54 ) ;
F_16 ( V_13 , V_54 ) ;
} else {
V_33 = F_17 ( V_13 ) ;
if ( V_33 == 0 )
V_33 = (* V_31 -> V_57 )( V_13 ) ;
}
if ( V_33 == 0 && V_13 -> V_41 == V_46 )
V_33 = F_18 ( V_13 , 1024 , 768 ) ;
V_33 += F_2 ( V_13 ) ;
if ( V_33 == 0 )
goto V_52;
F_19 ( V_13 ) ;
if ( V_13 -> V_58 )
V_34 |= V_5 ;
if ( V_13 -> V_59 )
V_34 |= V_7 ;
if ( V_13 -> V_60 )
V_34 |= V_9 ;
F_12 (mode, &connector->modes, head) {
if ( V_3 -> V_41 == V_11 )
V_3 -> V_41 = F_20 ( V_3 ) ;
if ( V_3 -> V_41 == V_11 )
V_3 -> V_41 = F_21 ( V_3 , V_28 , V_29 ) ;
if ( V_3 -> V_41 == V_11 )
V_3 -> V_41 = F_1 ( V_3 , V_34 ) ;
if ( V_3 -> V_41 == V_11 && V_31 -> V_61 )
V_3 -> V_41 = V_31 -> V_61 ( V_13 ,
V_3 ) ;
}
V_52:
F_22 ( V_16 , & V_13 -> V_62 , V_35 ) ;
if ( F_23 ( & V_13 -> V_62 ) )
return 0 ;
F_12 (mode, &connector->modes, head)
V_3 -> V_63 = F_24 ( V_3 ) ;
F_25 ( & V_13 -> V_62 ) ;
F_11 ( L_4 , V_13 -> V_38 . V_39 ,
V_13 -> V_40 ) ;
F_12 (mode, &connector->modes, head) {
F_26 ( V_3 , V_64 ) ;
F_27 ( V_3 ) ;
}
return V_33 ;
}
void F_28 ( struct V_17 * V_16 )
{
F_29 ( V_16 ) ;
if ( V_16 -> V_19 . V_48 -> V_65 )
V_16 -> V_19 . V_48 -> V_65 ( V_16 ) ;
}
static void F_30 ( struct V_66 * V_67 )
{
struct V_68 * V_68 = F_31 ( V_67 ) ;
struct V_17 * V_16 = F_32 ( V_68 , struct V_17 , V_19 . V_26 ) ;
struct V_12 * V_13 ;
enum V_36 V_37 ;
bool V_69 = false , V_70 ;
V_70 = V_16 -> V_19 . V_50 ;
V_16 -> V_19 . V_50 = false ;
if ( ! V_22 )
goto V_71;
F_33 ( & V_16 -> V_19 . V_20 ) ;
F_8 (connector, dev) {
if ( V_13 -> V_43 )
continue;
if ( ! V_13 -> V_23 || V_13 -> V_23 == V_72 )
continue;
V_37 = V_13 -> V_41 ;
if ( V_37 == V_46 &&
! ( V_13 -> V_23 & V_25 ) )
continue;
V_69 = true ;
V_13 -> V_41 = V_13 -> V_48 -> V_49 ( V_13 , false ) ;
if ( V_37 != V_13 -> V_41 ) {
const char * V_73 , * V_74 ;
if ( V_13 -> V_41 == V_75 ) {
V_13 -> V_41 = V_37 ;
continue;
}
V_73 = F_13 ( V_37 ) ;
V_74 = F_13 ( V_13 -> V_41 ) ;
F_11 ( L_5
L_6 ,
V_13 -> V_38 . V_39 ,
V_13 -> V_40 ,
V_73 , V_74 ) ;
V_70 = true ;
}
}
F_34 ( & V_16 -> V_19 . V_20 ) ;
V_71:
if ( V_70 )
F_28 ( V_16 ) ;
if ( V_69 )
F_9 ( V_68 , V_27 ) ;
}
void F_35 ( struct V_17 * V_16 )
{
if ( ! V_16 -> V_19 . V_21 )
return;
F_36 ( & V_16 -> V_19 . V_26 ) ;
}
void F_37 ( struct V_17 * V_16 )
{
F_33 ( & V_16 -> V_19 . V_20 ) ;
F_5 ( V_16 ) ;
F_34 ( & V_16 -> V_19 . V_20 ) ;
}
void F_38 ( struct V_17 * V_16 )
{
F_39 ( & V_16 -> V_19 . V_26 , F_30 ) ;
V_16 -> V_19 . V_21 = true ;
F_37 ( V_16 ) ;
}
void F_40 ( struct V_17 * V_16 )
{
F_35 ( V_16 ) ;
}
bool F_41 ( struct V_17 * V_16 )
{
struct V_12 * V_13 ;
enum V_36 V_37 ;
bool V_70 = false ;
if ( ! V_16 -> V_19 . V_21 )
return false ;
F_33 ( & V_16 -> V_19 . V_20 ) ;
F_8 (connector, dev) {
if ( ! ( V_13 -> V_23 & V_72 ) )
continue;
V_37 = V_13 -> V_41 ;
V_13 -> V_41 = V_13 -> V_48 -> V_49 ( V_13 , false ) ;
F_11 ( L_2 ,
V_13 -> V_38 . V_39 ,
V_13 -> V_40 ,
F_13 ( V_37 ) ,
F_13 ( V_13 -> V_41 ) ) ;
if ( V_37 != V_13 -> V_41 )
V_70 = true ;
}
F_34 ( & V_16 -> V_19 . V_20 ) ;
if ( V_70 )
F_28 ( V_16 ) ;
return V_70 ;
}
