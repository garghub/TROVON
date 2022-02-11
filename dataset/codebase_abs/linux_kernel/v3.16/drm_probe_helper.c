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
V_21 = (* V_19 -> V_39 )( V_2 ) ;
if ( V_21 == 0 && V_2 -> V_9 == V_32 )
V_21 = F_11 ( V_2 , 1024 , 768 ) ;
if ( V_21 == 0 )
goto V_38;
F_12 ( V_2 , V_15 ) ;
if ( V_13 && V_14 )
F_13 ( V_17 , & V_2 -> V_40 , V_13 , V_14 ) ;
if ( V_2 -> V_41 )
V_22 |= V_7 ;
if ( V_2 -> V_42 )
V_22 |= V_6 ;
if ( V_2 -> V_43 )
V_22 |= V_8 ;
F_1 ( V_2 , V_22 ) ;
F_2 (mode, &connector->modes, head) {
if ( V_5 -> V_9 == V_44 && V_19 -> V_45 )
V_5 -> V_9 = V_19 -> V_45 ( V_2 ,
V_5 ) ;
}
V_38:
F_14 ( V_17 , & V_2 -> V_40 , V_23 ) ;
if ( F_15 ( & V_2 -> V_40 ) )
return 0 ;
F_2 (mode, &connector->modes, head)
V_5 -> V_46 = F_16 ( V_5 ) ;
F_17 ( & V_2 -> V_40 ) ;
F_6 ( L_3 , V_2 -> V_26 . V_27 ,
V_2 -> V_28 ) ;
F_2 (mode, &connector->modes, head) {
F_18 ( V_5 , V_47 ) ;
F_19 ( V_5 ) ;
}
return V_21 ;
}
int F_20 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_14 )
{
return F_3 ( V_2 , V_13 , V_14 , true ) ;
}
int F_21 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_14 )
{
return F_3 ( V_2 , V_13 , V_14 , false ) ;
}
void F_22 ( struct V_16 * V_17 )
{
F_23 ( V_17 ) ;
if ( V_17 -> V_24 . V_34 -> V_48 )
V_17 -> V_24 . V_34 -> V_48 ( V_17 ) ;
}
static void F_24 ( struct V_49 * V_50 )
{
struct V_51 * V_51 = F_25 ( V_50 ) ;
struct V_16 * V_17 = F_26 ( V_51 , struct V_16 , V_24 . V_52 ) ;
struct V_1 * V_2 ;
enum V_53 V_54 ;
bool V_55 = false , V_56 = false ;
if ( ! V_36 )
return;
F_27 ( & V_17 -> V_24 . V_25 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_30 )
continue;
if ( ! V_2 -> V_57 || V_2 -> V_57 == V_58 )
continue;
V_55 = true ;
V_54 = V_2 -> V_9 ;
if ( V_54 == V_32 &&
! ( V_2 -> V_57 & V_59 ) )
continue;
V_2 -> V_9 = V_2 -> V_34 -> V_35 ( V_2 , false ) ;
if ( V_54 != V_2 -> V_9 ) {
const char * V_60 , * V_61 ;
V_60 = F_28 ( V_54 ) ;
V_61 = F_28 ( V_2 -> V_9 ) ;
F_6 ( L_4
L_5 ,
V_2 -> V_26 . V_27 ,
V_2 -> V_28 ,
V_60 , V_61 ) ;
V_56 = true ;
}
}
F_29 ( & V_17 -> V_24 . V_25 ) ;
if ( V_56 )
F_22 ( V_17 ) ;
if ( V_55 )
F_30 ( V_51 , V_62 ) ;
}
void F_31 ( struct V_16 * V_17 )
{
if ( ! V_17 -> V_24 . V_63 )
return;
F_32 ( & V_17 -> V_24 . V_52 ) ;
}
void F_7 ( struct V_16 * V_17 )
{
bool V_64 = false ;
struct V_1 * V_2 ;
if ( ! V_17 -> V_24 . V_63 || ! V_36 )
return;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_57 & ( V_65 |
V_59 ) )
V_64 = true ;
}
if ( V_64 )
F_30 ( & V_17 -> V_24 . V_52 , V_62 ) ;
}
void F_33 ( struct V_16 * V_17 )
{
F_34 ( & V_17 -> V_24 . V_52 , F_24 ) ;
V_17 -> V_24 . V_63 = true ;
F_7 ( V_17 ) ;
}
void F_35 ( struct V_16 * V_17 )
{
F_31 ( V_17 ) ;
}
bool F_36 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
enum V_53 V_54 ;
bool V_56 = false ;
if ( ! V_17 -> V_24 . V_63 )
return false ;
F_27 ( & V_17 -> V_24 . V_25 ) ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( ! ( V_2 -> V_57 & V_58 ) )
continue;
V_54 = V_2 -> V_9 ;
V_2 -> V_9 = V_2 -> V_34 -> V_35 ( V_2 , false ) ;
F_6 ( L_6 ,
V_2 -> V_26 . V_27 ,
V_2 -> V_28 ,
F_28 ( V_54 ) ,
F_28 ( V_2 -> V_9 ) ) ;
if ( V_54 != V_2 -> V_9 )
V_56 = true ;
}
F_29 ( & V_17 -> V_24 . V_25 ) ;
if ( V_56 )
F_22 ( V_17 ) ;
return V_56 ;
}
