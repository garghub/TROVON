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
int F_3 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_4 * V_5 ;
struct V_17 * V_18 =
V_2 -> V_19 ;
int V_20 = 0 ;
int V_21 = 0 ;
bool V_22 = true ;
F_4 ( ! F_5 ( & V_16 -> V_23 . V_24 ) ) ;
F_6 ( L_1 , V_2 -> V_25 . V_26 ,
F_7 ( V_2 ) ) ;
F_2 (mode, &connector->modes, head)
V_5 -> V_9 = V_27 ;
if ( V_2 -> V_28 ) {
if ( V_2 -> V_28 == V_29 )
V_2 -> V_9 = V_30 ;
else
V_2 -> V_9 = V_31 ;
if ( V_2 -> V_32 -> V_28 )
V_2 -> V_32 -> V_28 ( V_2 ) ;
} else {
V_2 -> V_9 = V_2 -> V_32 -> V_33 ( V_2 , true ) ;
}
if ( V_34 != V_16 -> V_23 . V_35 )
F_8 ( V_16 ) ;
V_16 -> V_23 . V_35 = V_34 ;
if ( V_2 -> V_9 == V_31 ) {
F_6 ( L_2 ,
V_2 -> V_25 . V_26 , F_7 ( V_2 ) ) ;
F_9 ( V_2 , NULL ) ;
V_22 = false ;
goto V_36;
}
#ifdef F_10
V_20 = F_11 ( V_2 ) ;
if ( V_20 == 0 )
#endif
V_20 = (* V_18 -> V_37 )( V_2 ) ;
if ( V_20 == 0 && V_2 -> V_9 == V_30 )
V_20 = F_12 ( V_2 , 1024 , 768 ) ;
if ( V_20 == 0 )
goto V_36;
F_13 ( V_2 ) ;
if ( V_13 && V_14 )
F_14 ( V_16 , & V_2 -> V_38 , V_13 , V_14 ) ;
if ( V_2 -> V_39 )
V_21 |= V_7 ;
if ( V_2 -> V_40 )
V_21 |= V_6 ;
if ( V_2 -> V_41 )
V_21 |= V_8 ;
F_1 ( V_2 , V_21 ) ;
F_2 (mode, &connector->modes, head) {
if ( V_5 -> V_9 == V_42 )
V_5 -> V_9 = V_18 -> V_43 ( V_2 ,
V_5 ) ;
}
V_36:
F_15 ( V_16 , & V_2 -> V_38 , V_22 ) ;
if ( F_16 ( & V_2 -> V_38 ) )
return 0 ;
F_2 (mode, &connector->modes, head)
V_5 -> V_44 = F_17 ( V_5 ) ;
F_18 ( & V_2 -> V_38 ) ;
F_6 ( L_3 , V_2 -> V_25 . V_26 ,
F_7 ( V_2 ) ) ;
F_2 (mode, &connector->modes, head) {
F_19 ( V_5 , V_45 ) ;
F_20 ( V_5 ) ;
}
return V_20 ;
}
void F_21 ( struct V_15 * V_16 )
{
F_22 ( V_16 ) ;
if ( V_16 -> V_23 . V_32 -> V_46 )
V_16 -> V_23 . V_32 -> V_46 ( V_16 ) ;
}
static void F_23 ( struct V_47 * V_48 )
{
struct V_49 * V_49 = F_24 ( V_48 ) ;
struct V_15 * V_16 = F_25 ( V_49 , struct V_15 , V_23 . V_50 ) ;
struct V_1 * V_2 ;
enum V_51 V_52 ;
bool V_53 = false , V_54 = false ;
if ( ! V_34 )
return;
F_26 ( & V_16 -> V_23 . V_24 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_28 )
continue;
if ( ! V_2 -> V_55 || V_2 -> V_55 == V_56 )
continue;
V_53 = true ;
V_52 = V_2 -> V_9 ;
if ( V_52 == V_30 &&
! ( V_2 -> V_55 & V_57 ) )
continue;
V_2 -> V_9 = V_2 -> V_32 -> V_33 ( V_2 , false ) ;
if ( V_52 != V_2 -> V_9 ) {
const char * V_58 , * V_59 ;
V_58 = F_27 ( V_52 ) ;
V_59 = F_27 ( V_2 -> V_9 ) ;
F_6 ( L_4
L_5 ,
V_2 -> V_25 . V_26 ,
F_7 ( V_2 ) ,
V_58 , V_59 ) ;
V_54 = true ;
}
}
F_28 ( & V_16 -> V_23 . V_24 ) ;
if ( V_54 )
F_21 ( V_16 ) ;
if ( V_53 )
F_29 ( V_49 , V_60 ) ;
}
void F_30 ( struct V_15 * V_16 )
{
if ( ! V_16 -> V_23 . V_61 )
return;
F_31 ( & V_16 -> V_23 . V_50 ) ;
}
void F_8 ( struct V_15 * V_16 )
{
bool V_62 = false ;
struct V_1 * V_2 ;
if ( ! V_16 -> V_23 . V_61 || ! V_34 )
return;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_55 & ( V_63 |
V_57 ) )
V_62 = true ;
}
if ( V_62 )
F_29 ( & V_16 -> V_23 . V_50 , V_60 ) ;
}
void F_32 ( struct V_15 * V_16 )
{
F_33 ( & V_16 -> V_23 . V_50 , F_23 ) ;
V_16 -> V_23 . V_61 = true ;
F_8 ( V_16 ) ;
}
void F_34 ( struct V_15 * V_16 )
{
F_30 ( V_16 ) ;
}
bool F_35 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
enum V_51 V_52 ;
bool V_54 = false ;
if ( ! V_16 -> V_23 . V_61 )
return false ;
F_26 ( & V_16 -> V_23 . V_24 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_2 -> V_55 & V_56 ) )
continue;
V_52 = V_2 -> V_9 ;
V_2 -> V_9 = V_2 -> V_32 -> V_33 ( V_2 , false ) ;
F_6 ( L_6 ,
V_2 -> V_25 . V_26 ,
F_7 ( V_2 ) ,
F_27 ( V_52 ) ,
F_27 ( V_2 -> V_9 ) ) ;
if ( V_52 != V_2 -> V_9 )
V_54 = true ;
}
F_28 ( & V_16 -> V_23 . V_24 ) ;
if ( V_54 )
F_21 ( V_16 ) ;
return V_54 ;
}
