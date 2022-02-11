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
struct V_6 * V_7 ;
int V_8 ;
if ( ! F_6 ( V_1 -> V_9 ) )
return;
V_8 = F_7 ( V_1 ) ;
F_8 ( & V_1 -> V_10 ) ;
F_9 (alias, p, &inode->i_dentry, d_alias) {
struct V_4 * V_11 ;
F_8 ( & V_5 -> V_12 ) ;
F_10 (child, &alias->d_subdirs, d_u.d_child) {
if ( ! V_11 -> V_13 )
continue;
F_11 ( & V_11 -> V_12 , V_14 ) ;
if ( V_8 )
V_11 -> V_15 |= V_16 ;
else
V_11 -> V_15 &= ~ V_16 ;
F_12 ( & V_11 -> V_12 ) ;
}
F_12 ( & V_5 -> V_12 ) ;
}
F_12 ( & V_1 -> V_10 ) ;
}
int F_13 ( struct V_17 * V_17 , struct V_4 * V_4 , T_1 V_18 )
{
struct V_4 * V_19 ;
struct V_1 * V_20 ;
int V_21 = 0 ;
if ( ! V_4 )
V_4 = V_17 -> V_4 ;
if ( ! ( V_4 -> V_15 & V_16 ) )
return 0 ;
V_19 = F_14 ( V_4 ) ;
V_20 = V_19 -> V_13 ;
if ( F_15 ( ! F_7 ( V_20 ) ) )
F_5 ( V_20 ) ;
else if ( V_20 -> V_22 & V_18 ) {
V_18 |= V_23 ;
if ( V_17 )
V_21 = F_16 ( V_20 , V_18 , V_17 , V_24 ,
V_4 -> V_25 . V_26 , 0 ) ;
else
V_21 = F_16 ( V_20 , V_18 , V_4 -> V_13 , V_27 ,
V_4 -> V_25 . V_26 , 0 ) ;
}
F_17 ( V_19 ) ;
return V_21 ;
}
static int F_18 ( struct V_1 * V_28 ,
struct V_29 * V_30 ,
struct V_29 * V_31 ,
T_1 V_18 , void * V_32 ,
int V_33 , T_2 V_34 ,
const unsigned char * V_35 ,
struct V_36 * * V_37 )
{
struct V_38 * V_39 = NULL ;
T_1 V_40 = 0 ;
T_1 V_41 = 0 ;
if ( F_15 ( ! V_30 && ! V_31 ) ) {
F_19 () ;
return 0 ;
}
if ( V_18 & V_42 ) {
if ( V_30 &&
! ( V_30 -> V_43 & V_44 ) )
V_30 -> V_45 = 0 ;
if ( V_31 &&
! ( V_31 -> V_43 & V_44 ) )
V_31 -> V_45 = 0 ;
}
if ( V_30 ) {
V_39 = V_30 -> V_39 ;
V_40 = ( V_18 & ~ V_23 ) ;
V_40 &= V_30 -> V_18 ;
V_40 &= ~ V_30 -> V_45 ;
}
if ( V_31 ) {
V_41 = ( V_18 & ~ V_23 ) ;
V_39 = V_31 -> V_39 ;
V_41 &= V_31 -> V_18 ;
V_41 &= ~ V_31 -> V_45 ;
if ( V_30 )
V_41 &= ~ V_30 -> V_45 ;
}
F_20 ( L_1
L_2
L_3 ,
V_46 , V_39 , V_28 , V_18 , V_30 ,
V_40 , V_31 , V_41 , V_32 ,
V_33 , V_34 , * V_37 ) ;
if ( ! V_40 && ! V_41 )
return 0 ;
if ( V_39 -> V_47 -> V_48 ( V_39 , V_28 , V_30 ,
V_31 , V_18 , V_32 ,
V_33 ) == false )
return 0 ;
if ( ! * V_37 ) {
* V_37 = F_21 ( V_28 , V_18 , V_32 ,
V_33 , V_35 ,
V_34 , V_49 ) ;
if ( ! * V_37 )
return - V_50 ;
}
return V_39 -> V_47 -> V_51 ( V_39 , V_30 , V_31 , * V_37 ) ;
}
int F_16 ( struct V_1 * V_28 , T_1 V_18 , void * V_32 , int V_33 ,
const unsigned char * V_35 , T_2 V_34 )
{
struct V_6 * V_52 = NULL , * V_53 = NULL ;
struct V_29 * V_30 = NULL , * V_31 = NULL ;
struct V_38 * V_54 , * V_55 ;
struct V_36 * V_37 = NULL ;
struct V_56 * V_3 ;
int V_57 , V_21 = 0 ;
T_1 V_58 = ( V_18 & ~ V_23 ) ;
if ( V_33 == V_24 )
V_3 = F_22 ( ( (struct V_17 * ) V_32 ) -> V_3 ) ;
else
V_3 = NULL ;
if ( ! ( V_18 & V_42 ) &&
! ( V_58 & V_28 -> V_22 ) &&
! ( V_3 && V_58 & V_3 -> V_59 ) )
return 0 ;
V_57 = F_23 ( & V_60 ) ;
if ( ( V_18 & V_42 ) ||
( V_58 & V_28 -> V_22 ) )
V_52 = F_24 ( V_28 -> V_61 . V_62 ,
& V_60 ) ;
if ( V_3 && ( ( V_18 & V_42 ) ||
( V_58 & V_3 -> V_59 ) ) ) {
V_53 = F_24 ( V_3 -> V_63 . V_62 ,
& V_60 ) ;
V_52 = F_24 ( V_28 -> V_61 . V_62 ,
& V_60 ) ;
}
while ( V_52 || V_53 ) {
V_54 = V_55 = NULL ;
if ( V_52 ) {
V_30 = F_25 ( F_24 ( V_52 , & V_60 ) ,
struct V_29 , V_64 . V_65 ) ;
V_54 = V_30 -> V_39 ;
}
if ( V_53 ) {
V_31 = F_25 ( F_24 ( V_53 , & V_60 ) ,
struct V_29 , V_66 . V_67 ) ;
V_55 = V_31 -> V_39 ;
}
if ( V_54 > V_55 ) {
V_21 = F_18 ( V_28 , V_30 , NULL , V_18 , V_32 ,
V_33 , V_34 , V_35 , & V_37 ) ;
V_55 = NULL ;
} else if ( V_55 > V_54 ) {
V_21 = F_18 ( V_28 , NULL , V_31 , V_18 , V_32 ,
V_33 , V_34 , V_35 , & V_37 ) ;
V_54 = NULL ;
} else {
V_21 = F_18 ( V_28 , V_30 , V_31 ,
V_18 , V_32 , V_33 , V_34 , V_35 ,
& V_37 ) ;
}
if ( V_21 && ( V_18 & V_68 ) )
goto V_69;
if ( V_54 )
V_52 = F_24 ( V_52 -> V_70 ,
& V_60 ) ;
if ( V_55 )
V_53 = F_24 ( V_53 -> V_70 ,
& V_60 ) ;
}
V_21 = 0 ;
V_69:
F_26 ( & V_60 , V_57 ) ;
if ( V_37 )
F_27 ( V_37 ) ;
return V_21 ;
}
static T_3 int F_28 ( void )
{
int V_21 ;
F_29 ( F_30 ( V_71 ) != 23 ) ;
V_21 = F_31 ( & V_60 ) ;
if ( V_21 )
F_32 ( L_4 ) ;
return 0 ;
}
