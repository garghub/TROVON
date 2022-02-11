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
static int F_5 ( struct V_12 * V_13 ,
T_1 V_17 , T_1 V_18 , bool V_19 )
{
struct V_20 * V_16 = V_13 -> V_16 ;
struct V_2 * V_3 ;
const struct V_21 * V_22 =
V_13 -> V_23 ;
int V_24 = 0 ;
int V_25 = 0 ;
bool V_26 = true ;
enum V_27 V_28 ;
F_6 ( ! F_7 ( & V_16 -> V_29 . V_30 ) ) ;
F_8 ( L_1 , V_13 -> V_31 . V_32 ,
V_13 -> V_33 ) ;
F_9 (mode, &connector->modes, head)
V_3 -> V_34 = V_35 ;
if ( V_13 -> V_36 ) {
if ( V_13 -> V_36 == V_37 ||
V_13 -> V_36 == V_38 )
V_13 -> V_34 = V_39 ;
else
V_13 -> V_34 = V_40 ;
if ( V_13 -> V_41 -> V_36 )
V_13 -> V_41 -> V_36 ( V_13 ) ;
} else {
V_28 = V_13 -> V_34 ;
V_13 -> V_34 = V_13 -> V_41 -> V_42 ( V_13 , true ) ;
if ( V_28 != V_13 -> V_34 ) {
F_8 ( L_2 ,
V_13 -> V_31 . V_32 ,
V_13 -> V_33 ,
V_28 , V_13 -> V_34 ) ;
V_16 -> V_29 . V_43 = true ;
if ( V_16 -> V_29 . V_44 )
F_10 ( & V_16 -> V_29 . V_45 ,
0 ) ;
}
}
if ( V_46 != V_16 -> V_29 . V_47 )
F_11 ( V_16 ) ;
V_16 -> V_29 . V_47 = V_46 ;
if ( V_13 -> V_34 == V_40 ) {
F_8 ( L_3 ,
V_13 -> V_31 . V_32 , V_13 -> V_33 ) ;
F_12 ( V_13 , NULL ) ;
V_26 = false ;
goto V_48;
}
#ifdef F_13
V_24 = F_14 ( V_13 ) ;
if ( V_24 == 0 )
#endif
{
if ( V_13 -> V_49 ) {
struct V_50 * V_50 = (struct V_50 * ) V_13 -> V_51 -> V_52 ;
V_24 = F_15 ( V_13 , V_50 ) ;
F_16 ( V_13 , V_50 ) ;
} else
V_24 = (* V_22 -> V_53 )( V_13 ) ;
}
if ( V_24 == 0 && V_13 -> V_34 == V_39 )
V_24 = F_17 ( V_13 , 1024 , 768 ) ;
V_24 += F_2 ( V_13 ) ;
if ( V_24 == 0 )
goto V_48;
F_18 ( V_13 , V_19 ) ;
if ( V_13 -> V_54 )
V_25 |= V_5 ;
if ( V_13 -> V_55 )
V_25 |= V_7 ;
if ( V_13 -> V_56 )
V_25 |= V_9 ;
F_9 (mode, &connector->modes, head) {
V_3 -> V_34 = F_19 ( V_3 ) ;
if ( V_3 -> V_34 == V_11 )
V_3 -> V_34 = F_20 ( V_3 , V_17 , V_18 ) ;
if ( V_3 -> V_34 == V_11 )
V_3 -> V_34 = F_1 ( V_3 , V_25 ) ;
if ( V_3 -> V_34 == V_11 && V_22 -> V_57 )
V_3 -> V_34 = V_22 -> V_57 ( V_13 ,
V_3 ) ;
}
V_48:
F_21 ( V_16 , & V_13 -> V_58 , V_26 ) ;
if ( F_22 ( & V_13 -> V_58 ) )
return 0 ;
F_9 (mode, &connector->modes, head)
V_3 -> V_59 = F_23 ( V_3 ) ;
F_24 ( & V_13 -> V_58 ) ;
F_8 ( L_4 , V_13 -> V_31 . V_32 ,
V_13 -> V_33 ) ;
F_9 (mode, &connector->modes, head) {
F_25 ( V_3 , V_60 ) ;
F_26 ( V_3 ) ;
}
return V_24 ;
}
int F_27 ( struct V_12 * V_13 ,
T_1 V_17 , T_1 V_18 )
{
return F_5 ( V_13 , V_17 , V_18 , true ) ;
}
int F_28 ( struct V_12 * V_13 ,
T_1 V_17 , T_1 V_18 )
{
return F_5 ( V_13 , V_17 , V_18 , false ) ;
}
void F_29 ( struct V_20 * V_16 )
{
F_30 ( V_16 ) ;
if ( V_16 -> V_29 . V_41 -> V_61 )
V_16 -> V_29 . V_41 -> V_61 ( V_16 ) ;
}
static void F_31 ( struct V_62 * V_63 )
{
struct V_64 * V_64 = F_32 ( V_63 ) ;
struct V_20 * V_16 = F_33 ( V_64 , struct V_20 , V_29 . V_45 ) ;
struct V_12 * V_13 ;
enum V_27 V_28 ;
bool V_65 = false , V_66 ;
V_66 = V_16 -> V_29 . V_43 ;
V_16 -> V_29 . V_43 = false ;
if ( ! V_46 )
goto V_67;
F_34 ( & V_16 -> V_29 . V_30 ) ;
F_9 (connector, &dev->mode_config.connector_list, head) {
if ( V_13 -> V_36 )
continue;
if ( ! V_13 -> V_68 || V_13 -> V_68 == V_69 )
continue;
V_65 = true ;
V_28 = V_13 -> V_34 ;
if ( V_28 == V_39 &&
! ( V_13 -> V_68 & V_70 ) )
continue;
V_13 -> V_34 = V_13 -> V_41 -> V_42 ( V_13 , false ) ;
if ( V_28 != V_13 -> V_34 ) {
const char * V_71 , * V_72 ;
if ( V_13 -> V_34 == V_73 ) {
V_13 -> V_34 = V_28 ;
continue;
}
V_71 = F_35 ( V_28 ) ;
V_72 = F_35 ( V_13 -> V_34 ) ;
F_8 ( L_5
L_6 ,
V_13 -> V_31 . V_32 ,
V_13 -> V_33 ,
V_71 , V_72 ) ;
V_66 = true ;
}
}
F_36 ( & V_16 -> V_29 . V_30 ) ;
V_67:
if ( V_66 )
F_29 ( V_16 ) ;
if ( V_65 )
F_10 ( V_64 , V_74 ) ;
}
void F_37 ( struct V_20 * V_16 )
{
if ( ! V_16 -> V_29 . V_44 )
return;
F_38 ( & V_16 -> V_29 . V_45 ) ;
}
void F_11 ( struct V_20 * V_16 )
{
bool V_75 = false ;
struct V_12 * V_13 ;
if ( ! V_16 -> V_29 . V_44 || ! V_46 )
return;
F_9 (connector, &dev->mode_config.connector_list, head) {
if ( V_13 -> V_68 & ( V_76 |
V_70 ) )
V_75 = true ;
}
if ( V_75 )
F_10 ( & V_16 -> V_29 . V_45 , V_74 ) ;
}
void F_39 ( struct V_20 * V_16 )
{
F_40 ( & V_16 -> V_29 . V_45 , F_31 ) ;
V_16 -> V_29 . V_44 = true ;
F_11 ( V_16 ) ;
}
void F_41 ( struct V_20 * V_16 )
{
F_37 ( V_16 ) ;
}
bool F_42 ( struct V_20 * V_16 )
{
struct V_12 * V_13 ;
enum V_27 V_28 ;
bool V_66 = false ;
if ( ! V_16 -> V_29 . V_44 )
return false ;
F_34 ( & V_16 -> V_29 . V_30 ) ;
F_9 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_13 -> V_68 & V_69 ) )
continue;
V_28 = V_13 -> V_34 ;
V_13 -> V_34 = V_13 -> V_41 -> V_42 ( V_13 , false ) ;
F_8 ( L_7 ,
V_13 -> V_31 . V_32 ,
V_13 -> V_33 ,
F_35 ( V_28 ) ,
F_35 ( V_13 -> V_34 ) ) ;
if ( V_28 != V_13 -> V_34 )
V_66 = true ;
}
F_36 ( & V_16 -> V_29 . V_30 ) ;
if ( V_66 )
F_29 ( V_16 ) ;
return V_66 ;
}
