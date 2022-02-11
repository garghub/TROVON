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
static int F_3 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_14 , bool V_15 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_4 * V_5 ;
struct V_18 * V_19 =
V_2 -> V_20 ;
int V_21 = 0 ;
int V_22 = 0 ;
bool V_23 = true ;
F_4 ( ! F_5 ( & V_17 -> V_24 . V_25 ) ) ;
F_6 ( L_1 , V_2 -> V_26 . V_27 ,
V_2 -> V_28 ) ;
F_2 (mode, &connector->modes, head)
V_5 -> V_9 = V_29 ;
if ( V_2 -> V_30 ) {
if ( V_2 -> V_30 == V_31 )
V_2 -> V_9 = V_32 ;
else
V_2 -> V_9 = V_33 ;
if ( V_2 -> V_34 -> V_30 )
V_2 -> V_34 -> V_30 ( V_2 ) ;
} else {
V_2 -> V_9 = V_2 -> V_34 -> V_35 ( V_2 , true ) ;
}
if ( V_36 != V_17 -> V_24 . V_37 )
F_7 ( V_17 ) ;
V_17 -> V_24 . V_37 = V_36 ;
if ( V_2 -> V_9 == V_33 ) {
F_6 ( L_2 ,
V_2 -> V_26 . V_27 , V_2 -> V_28 ) ;
F_8 ( V_2 , NULL ) ;
V_23 = false ;
goto V_38;
}
#ifdef F_9
V_21 = F_10 ( V_2 ) ;
if ( V_21 == 0 )
#endif
{
if ( V_2 -> V_39 ) {
struct V_40 * V_40 = (struct V_40 * ) V_2 -> V_41 -> V_42 ;
V_21 = F_11 ( V_2 , V_40 ) ;
} else
V_21 = (* V_19 -> V_43 )( V_2 ) ;
}
if ( V_21 == 0 && V_2 -> V_9 == V_32 )
V_21 = F_12 ( V_2 , 1024 , 768 ) ;
if ( V_21 == 0 )
goto V_38;
F_13 ( V_2 , V_15 ) ;
if ( V_13 && V_14 )
F_14 ( V_17 , & V_2 -> V_44 , V_13 , V_14 ) ;
if ( V_2 -> V_45 )
V_22 |= V_7 ;
if ( V_2 -> V_46 )
V_22 |= V_6 ;
if ( V_2 -> V_47 )
V_22 |= V_8 ;
F_1 ( V_2 , V_22 ) ;
F_2 (mode, &connector->modes, head) {
if ( V_5 -> V_9 == V_48 && V_19 -> V_49 )
V_5 -> V_9 = V_19 -> V_49 ( V_2 ,
V_5 ) ;
}
V_38:
F_15 ( V_17 , & V_2 -> V_44 , V_23 ) ;
if ( F_16 ( & V_2 -> V_44 ) )
return 0 ;
F_2 (mode, &connector->modes, head)
V_5 -> V_50 = F_17 ( V_5 ) ;
F_18 ( & V_2 -> V_44 ) ;
F_6 ( L_3 , V_2 -> V_26 . V_27 ,
V_2 -> V_28 ) ;
F_2 (mode, &connector->modes, head) {
F_19 ( V_5 , V_51 ) ;
F_20 ( V_5 ) ;
}
return V_21 ;
}
int F_21 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_14 )
{
return F_3 ( V_2 , V_13 , V_14 , true ) ;
}
int F_22 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_14 )
{
return F_3 ( V_2 , V_13 , V_14 , false ) ;
}
void F_23 ( struct V_16 * V_17 )
{
F_24 ( V_17 ) ;
if ( V_17 -> V_24 . V_34 -> V_52 )
V_17 -> V_24 . V_34 -> V_52 ( V_17 ) ;
}
static void F_25 ( struct V_53 * V_54 )
{
struct V_55 * V_55 = F_26 ( V_54 ) ;
struct V_16 * V_17 = F_27 ( V_55 , struct V_16 , V_24 . V_56 ) ;
struct V_1 * V_2 ;
enum V_57 V_58 ;
bool V_59 = false , V_60 = false ;
if ( ! V_36 )
return;
F_28 ( & V_17 -> V_24 . V_25 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_30 )
continue;
if ( ! V_2 -> V_61 || V_2 -> V_61 == V_62 )
continue;
V_59 = true ;
V_58 = V_2 -> V_9 ;
if ( V_58 == V_32 &&
! ( V_2 -> V_61 & V_63 ) )
continue;
V_2 -> V_9 = V_2 -> V_34 -> V_35 ( V_2 , false ) ;
if ( V_58 != V_2 -> V_9 ) {
const char * V_64 , * V_65 ;
V_64 = F_29 ( V_58 ) ;
V_65 = F_29 ( V_2 -> V_9 ) ;
F_6 ( L_4
L_5 ,
V_2 -> V_26 . V_27 ,
V_2 -> V_28 ,
V_64 , V_65 ) ;
V_60 = true ;
}
}
F_30 ( & V_17 -> V_24 . V_25 ) ;
if ( V_60 )
F_23 ( V_17 ) ;
if ( V_59 )
F_31 ( V_55 , V_66 ) ;
}
void F_32 ( struct V_16 * V_17 )
{
if ( ! V_17 -> V_24 . V_67 )
return;
F_33 ( & V_17 -> V_24 . V_56 ) ;
}
void F_7 ( struct V_16 * V_17 )
{
bool V_68 = false ;
struct V_1 * V_2 ;
if ( ! V_17 -> V_24 . V_67 || ! V_36 )
return;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_61 & ( V_69 |
V_63 ) )
V_68 = true ;
}
if ( V_68 )
F_31 ( & V_17 -> V_24 . V_56 , V_66 ) ;
}
void F_34 ( struct V_16 * V_17 )
{
F_35 ( & V_17 -> V_24 . V_56 , F_25 ) ;
V_17 -> V_24 . V_67 = true ;
F_7 ( V_17 ) ;
}
void F_36 ( struct V_16 * V_17 )
{
F_32 ( V_17 ) ;
}
bool F_37 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
enum V_57 V_58 ;
bool V_60 = false ;
if ( ! V_17 -> V_24 . V_67 )
return false ;
F_28 ( & V_17 -> V_24 . V_25 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_2 -> V_61 & V_62 ) )
continue;
V_58 = V_2 -> V_9 ;
V_2 -> V_9 = V_2 -> V_34 -> V_35 ( V_2 , false ) ;
F_6 ( L_6 ,
V_2 -> V_26 . V_27 ,
V_2 -> V_28 ,
F_29 ( V_58 ) ,
F_29 ( V_2 -> V_9 ) ) ;
if ( V_58 != V_2 -> V_9 )
V_60 = true ;
}
F_30 ( & V_17 -> V_24 . V_25 ) ;
if ( V_60 )
F_23 ( V_17 ) ;
return V_60 ;
}
