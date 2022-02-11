static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 ;
if ( V_3 == ( V_6 | V_7 |
V_8 ) )
return;
F_2 (mode, &connector->modes, head) {
if ( ( V_5 -> V_3 & V_7 ) &&
! ( V_3 & V_7 ) )
V_5 -> V_9 = V_10 ;
if ( ( V_5 -> V_3 & V_6 ) &&
! ( V_3 & V_6 ) )
V_5 -> V_9 = V_11 ;
if ( ( V_5 -> V_3 & V_8 ) &&
! ( V_3 & V_8 ) )
V_5 -> V_9 = V_12 ;
}
return;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_2 -> V_13 . V_14 )
return 0 ;
V_5 = F_4 ( V_2 -> V_15 ,
& V_2 -> V_13 ) ;
if ( V_5 == NULL )
return 0 ;
F_5 ( V_2 , V_5 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 , bool V_18 )
{
struct V_19 * V_15 = V_2 -> V_15 ;
struct V_4 * V_5 ;
struct V_20 * V_21 =
V_2 -> V_22 ;
int V_23 = 0 ;
int V_24 = 0 ;
bool V_25 = true ;
F_7 ( ! F_8 ( & V_15 -> V_26 . V_27 ) ) ;
F_9 ( L_1 , V_2 -> V_28 . V_29 ,
V_2 -> V_30 ) ;
F_2 (mode, &connector->modes, head)
V_5 -> V_9 = V_31 ;
if ( V_2 -> V_32 ) {
if ( V_2 -> V_32 == V_33 )
V_2 -> V_9 = V_34 ;
else
V_2 -> V_9 = V_35 ;
if ( V_2 -> V_36 -> V_32 )
V_2 -> V_36 -> V_32 ( V_2 ) ;
} else {
V_2 -> V_9 = V_2 -> V_36 -> V_37 ( V_2 , true ) ;
}
if ( V_38 != V_15 -> V_26 . V_39 )
F_10 ( V_15 ) ;
V_15 -> V_26 . V_39 = V_38 ;
if ( V_2 -> V_9 == V_35 ) {
F_9 ( L_2 ,
V_2 -> V_28 . V_29 , V_2 -> V_30 ) ;
F_11 ( V_2 , NULL ) ;
V_25 = false ;
goto V_40;
}
#ifdef F_12
V_23 = F_13 ( V_2 ) ;
if ( V_23 == 0 )
#endif
{
if ( V_2 -> V_41 ) {
struct V_42 * V_42 = (struct V_42 * ) V_2 -> V_43 -> V_44 ;
V_23 = F_14 ( V_2 , V_42 ) ;
} else
V_23 = (* V_21 -> V_45 )( V_2 ) ;
}
if ( V_23 == 0 && V_2 -> V_9 == V_34 )
V_23 = F_15 ( V_2 , 1024 , 768 ) ;
V_23 += F_3 ( V_2 ) ;
if ( V_23 == 0 )
goto V_40;
F_16 ( V_2 , V_18 ) ;
if ( V_16 && V_17 )
F_17 ( V_15 , & V_2 -> V_46 , V_16 , V_17 ) ;
if ( V_2 -> V_47 )
V_24 |= V_7 ;
if ( V_2 -> V_48 )
V_24 |= V_6 ;
if ( V_2 -> V_49 )
V_24 |= V_8 ;
F_1 ( V_2 , V_24 ) ;
F_2 (mode, &connector->modes, head) {
if ( V_5 -> V_9 == V_50 && V_21 -> V_51 )
V_5 -> V_9 = V_21 -> V_51 ( V_2 ,
V_5 ) ;
}
V_40:
F_18 ( V_15 , & V_2 -> V_46 , V_25 ) ;
if ( F_19 ( & V_2 -> V_46 ) )
return 0 ;
F_2 (mode, &connector->modes, head)
V_5 -> V_52 = F_20 ( V_5 ) ;
F_21 ( & V_2 -> V_46 ) ;
F_9 ( L_3 , V_2 -> V_28 . V_29 ,
V_2 -> V_30 ) ;
F_2 (mode, &connector->modes, head) {
F_22 ( V_5 , V_53 ) ;
F_23 ( V_5 ) ;
}
return V_23 ;
}
int F_24 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 )
{
return F_6 ( V_2 , V_16 , V_17 , true ) ;
}
int F_25 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 )
{
return F_6 ( V_2 , V_16 , V_17 , false ) ;
}
void F_26 ( struct V_19 * V_15 )
{
F_27 ( V_15 ) ;
if ( V_15 -> V_26 . V_36 -> V_54 )
V_15 -> V_26 . V_36 -> V_54 ( V_15 ) ;
}
static void F_28 ( struct V_55 * V_56 )
{
struct V_57 * V_57 = F_29 ( V_56 ) ;
struct V_19 * V_15 = F_30 ( V_57 , struct V_19 , V_26 . V_58 ) ;
struct V_1 * V_2 ;
enum V_59 V_60 ;
bool V_61 = false , V_62 = false ;
if ( ! V_38 )
return;
F_31 ( & V_15 -> V_26 . V_27 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_32 )
continue;
if ( ! V_2 -> V_63 || V_2 -> V_63 == V_64 )
continue;
V_61 = true ;
V_60 = V_2 -> V_9 ;
if ( V_60 == V_34 &&
! ( V_2 -> V_63 & V_65 ) )
continue;
V_2 -> V_9 = V_2 -> V_36 -> V_37 ( V_2 , false ) ;
if ( V_60 != V_2 -> V_9 ) {
const char * V_66 , * V_67 ;
V_66 = F_32 ( V_60 ) ;
V_67 = F_32 ( V_2 -> V_9 ) ;
F_9 ( L_4
L_5 ,
V_2 -> V_28 . V_29 ,
V_2 -> V_30 ,
V_66 , V_67 ) ;
V_62 = true ;
}
}
F_33 ( & V_15 -> V_26 . V_27 ) ;
if ( V_62 )
F_26 ( V_15 ) ;
if ( V_61 )
F_34 ( V_57 , V_68 ) ;
}
void F_35 ( struct V_19 * V_15 )
{
if ( ! V_15 -> V_26 . V_69 )
return;
F_36 ( & V_15 -> V_26 . V_58 ) ;
}
void F_10 ( struct V_19 * V_15 )
{
bool V_70 = false ;
struct V_1 * V_2 ;
if ( ! V_15 -> V_26 . V_69 || ! V_38 )
return;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_63 & ( V_71 |
V_65 ) )
V_70 = true ;
}
if ( V_70 )
F_34 ( & V_15 -> V_26 . V_58 , V_68 ) ;
}
void F_37 ( struct V_19 * V_15 )
{
F_38 ( & V_15 -> V_26 . V_58 , F_28 ) ;
V_15 -> V_26 . V_69 = true ;
F_10 ( V_15 ) ;
}
void F_39 ( struct V_19 * V_15 )
{
F_35 ( V_15 ) ;
}
bool F_40 ( struct V_19 * V_15 )
{
struct V_1 * V_2 ;
enum V_59 V_60 ;
bool V_62 = false ;
if ( ! V_15 -> V_26 . V_69 )
return false ;
F_31 ( & V_15 -> V_26 . V_27 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_2 -> V_63 & V_64 ) )
continue;
V_60 = V_2 -> V_9 ;
V_2 -> V_9 = V_2 -> V_36 -> V_37 ( V_2 , false ) ;
F_9 ( L_6 ,
V_2 -> V_28 . V_29 ,
V_2 -> V_30 ,
F_32 ( V_60 ) ,
F_32 ( V_2 -> V_9 ) ) ;
if ( V_60 != V_2 -> V_9 )
V_62 = true ;
}
F_33 ( & V_15 -> V_26 . V_27 ) ;
if ( V_62 )
F_26 ( V_15 ) ;
return V_62 ;
}
