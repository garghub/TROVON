void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 ) ;
}
void F_3 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) ;
}
void F_5 ( struct V_1 * V_1 )
{
struct V_4 * V_5 ;
int V_6 ;
if ( ! F_6 ( V_1 -> V_7 ) )
return;
V_6 = F_7 ( V_1 ) ;
F_8 ( & V_1 -> V_8 ) ;
F_9 (alias, &inode->i_dentry, d_alias) {
struct V_4 * V_9 ;
F_8 ( & V_5 -> V_10 ) ;
F_9 (child, &alias->d_subdirs, d_u.d_child) {
if ( ! V_9 -> V_11 )
continue;
F_10 ( & V_9 -> V_10 , V_12 ) ;
if ( V_6 )
V_9 -> V_13 |= V_14 ;
else
V_9 -> V_13 &= ~ V_14 ;
F_11 ( & V_9 -> V_10 ) ;
}
F_11 ( & V_5 -> V_10 ) ;
}
F_11 ( & V_1 -> V_8 ) ;
}
int F_12 ( struct V_15 * V_15 , struct V_4 * V_4 , T_1 V_16 )
{
struct V_4 * V_17 ;
struct V_1 * V_18 ;
int V_19 = 0 ;
if ( ! V_4 )
V_4 = V_15 -> V_4 ;
if ( ! ( V_4 -> V_13 & V_14 ) )
return 0 ;
V_17 = F_13 ( V_4 ) ;
V_18 = V_17 -> V_11 ;
if ( F_14 ( ! F_7 ( V_18 ) ) )
F_5 ( V_18 ) ;
else if ( V_18 -> V_20 & V_16 ) {
V_16 |= V_21 ;
if ( V_15 )
V_19 = F_15 ( V_18 , V_16 , V_15 , V_22 ,
V_4 -> V_23 . V_24 , 0 ) ;
else
V_19 = F_15 ( V_18 , V_16 , V_4 -> V_11 , V_25 ,
V_4 -> V_23 . V_24 , 0 ) ;
}
F_16 ( V_17 ) ;
return V_19 ;
}
static int F_17 ( struct V_1 * V_26 ,
struct V_27 * V_28 ,
struct V_27 * V_29 ,
T_1 V_16 , void * V_30 ,
int V_31 , T_2 V_32 ,
const unsigned char * V_33 ,
struct V_34 * * V_35 )
{
struct V_36 * V_37 = NULL ;
T_1 V_38 = 0 ;
T_1 V_39 = 0 ;
if ( F_14 ( ! V_28 && ! V_29 ) ) {
F_18 () ;
return 0 ;
}
if ( V_16 & V_40 ) {
if ( V_28 &&
! ( V_28 -> V_41 & V_42 ) )
V_28 -> V_43 = 0 ;
if ( V_29 &&
! ( V_29 -> V_41 & V_42 ) )
V_29 -> V_43 = 0 ;
}
if ( V_28 ) {
V_37 = V_28 -> V_37 ;
V_38 = ( V_16 & ~ V_21 ) ;
V_38 &= V_28 -> V_16 ;
V_38 &= ~ V_28 -> V_43 ;
}
if ( V_29 ) {
V_39 = ( V_16 & ~ V_21 ) ;
V_37 = V_29 -> V_37 ;
V_39 &= V_29 -> V_16 ;
V_39 &= ~ V_29 -> V_43 ;
if ( V_28 )
V_39 &= ~ V_28 -> V_43 ;
}
F_19 ( L_1
L_2
L_3 ,
V_44 , V_37 , V_26 , V_16 , V_28 ,
V_38 , V_29 , V_39 , V_30 ,
V_31 , V_32 , * V_35 ) ;
if ( ! V_38 && ! V_39 )
return 0 ;
if ( V_37 -> V_45 -> V_46 ( V_37 , V_26 , V_28 ,
V_29 , V_16 , V_30 ,
V_31 ) == false )
return 0 ;
if ( ! * V_35 ) {
* V_35 = F_20 ( V_26 , V_16 , V_30 ,
V_31 , V_33 ,
V_32 , V_47 ) ;
if ( ! * V_35 )
return - V_48 ;
}
return V_37 -> V_45 -> V_49 ( V_37 , V_28 , V_29 , * V_35 ) ;
}
int F_15 ( struct V_1 * V_26 , T_1 V_16 , void * V_30 , int V_31 ,
const unsigned char * V_33 , T_2 V_32 )
{
struct V_50 * V_51 = NULL , * V_52 = NULL ;
struct V_27 * V_28 = NULL , * V_29 = NULL ;
struct V_36 * V_53 , * V_54 ;
struct V_34 * V_35 = NULL ;
struct V_55 * V_3 ;
int V_56 , V_19 = 0 ;
T_1 V_57 = ( V_16 & ~ V_21 ) ;
if ( V_31 == V_22 )
V_3 = F_21 ( ( (struct V_15 * ) V_30 ) -> V_3 ) ;
else
V_3 = NULL ;
if ( ! ( V_16 & V_40 ) &&
! ( V_57 & V_26 -> V_20 ) &&
! ( V_3 && V_57 & V_3 -> V_58 ) )
return 0 ;
V_56 = F_22 ( & V_59 ) ;
if ( ( V_16 & V_40 ) ||
( V_57 & V_26 -> V_20 ) )
V_51 = F_23 ( V_26 -> V_60 . V_61 ,
& V_59 ) ;
if ( V_3 && ( ( V_16 & V_40 ) ||
( V_57 & V_3 -> V_58 ) ) ) {
V_52 = F_23 ( V_3 -> V_62 . V_61 ,
& V_59 ) ;
V_51 = F_23 ( V_26 -> V_60 . V_61 ,
& V_59 ) ;
}
while ( V_51 || V_52 ) {
V_53 = V_54 = NULL ;
if ( V_51 ) {
V_28 = F_24 ( F_23 ( V_51 , & V_59 ) ,
struct V_27 , V_63 . V_64 ) ;
V_53 = V_28 -> V_37 ;
}
if ( V_52 ) {
V_29 = F_24 ( F_23 ( V_52 , & V_59 ) ,
struct V_27 , V_65 . V_66 ) ;
V_54 = V_29 -> V_37 ;
}
if ( V_53 > V_54 ) {
V_19 = F_17 ( V_26 , V_28 , NULL , V_16 , V_30 ,
V_31 , V_32 , V_33 , & V_35 ) ;
V_54 = NULL ;
} else if ( V_54 > V_53 ) {
V_19 = F_17 ( V_26 , NULL , V_29 , V_16 , V_30 ,
V_31 , V_32 , V_33 , & V_35 ) ;
V_53 = NULL ;
} else {
V_19 = F_17 ( V_26 , V_28 , V_29 ,
V_16 , V_30 , V_31 , V_32 , V_33 ,
& V_35 ) ;
}
if ( V_19 && ( V_16 & V_67 ) )
goto V_68;
if ( V_53 )
V_51 = F_23 ( V_51 -> V_69 ,
& V_59 ) ;
if ( V_54 )
V_52 = F_23 ( V_52 -> V_69 ,
& V_59 ) ;
}
V_19 = 0 ;
V_68:
F_25 ( & V_59 , V_56 ) ;
if ( V_35 )
F_26 ( V_35 ) ;
return V_19 ;
}
static T_3 int F_27 ( void )
{
int V_19 ;
F_28 ( F_29 ( V_70 ) != 23 ) ;
V_19 = F_30 ( & V_59 ) ;
if ( V_19 )
F_31 ( L_4 ) ;
return 0 ;
}
