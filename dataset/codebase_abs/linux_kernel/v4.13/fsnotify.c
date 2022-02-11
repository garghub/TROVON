void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 ) ;
}
void F_3 ( struct V_2 * V_3 )
{
F_4 ( V_3 ) ;
}
void F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_1 , * V_6 = NULL ;
F_6 ( & V_5 -> V_7 ) ;
F_7 (inode, &sb->s_inodes, i_sb_list) {
F_6 ( & V_1 -> V_8 ) ;
if ( V_1 -> V_9 & ( V_10 | V_11 | V_12 ) ) {
F_8 ( & V_1 -> V_8 ) ;
continue;
}
if ( ! F_9 ( & V_1 -> V_13 ) ) {
F_8 ( & V_1 -> V_8 ) ;
continue;
}
F_10 ( V_1 ) ;
F_8 ( & V_1 -> V_8 ) ;
F_8 ( & V_5 -> V_7 ) ;
if ( V_6 )
F_11 ( V_6 ) ;
F_12 ( V_1 , V_14 , V_1 , V_15 , NULL , 0 ) ;
F_13 ( V_1 ) ;
V_6 = V_1 ;
F_6 ( & V_5 -> V_7 ) ;
}
F_8 ( & V_5 -> V_7 ) ;
if ( V_6 )
F_11 ( V_6 ) ;
}
void F_14 ( struct V_1 * V_1 )
{
struct V_16 * V_17 ;
int V_18 ;
if ( ! F_15 ( V_1 -> V_19 ) )
return;
V_18 = F_16 ( V_1 ) ;
F_6 ( & V_1 -> V_8 ) ;
F_17 (alias, &inode->i_dentry, d_u.d_alias) {
struct V_16 * V_20 ;
F_6 ( & V_17 -> V_21 ) ;
F_7 (child, &alias->d_subdirs, d_child) {
if ( ! V_20 -> V_22 )
continue;
F_18 ( & V_20 -> V_21 , V_23 ) ;
if ( V_18 )
V_20 -> V_24 |= V_25 ;
else
V_20 -> V_24 &= ~ V_25 ;
F_8 ( & V_20 -> V_21 ) ;
}
F_8 ( & V_17 -> V_21 ) ;
}
F_8 ( & V_1 -> V_8 ) ;
}
int F_19 ( const struct V_26 * V_26 , struct V_16 * V_16 , T_1 V_27 )
{
struct V_16 * V_28 ;
struct V_1 * V_29 ;
int V_30 = 0 ;
if ( ! V_16 )
V_16 = V_26 -> V_16 ;
if ( ! ( V_16 -> V_24 & V_25 ) )
return 0 ;
V_28 = F_20 ( V_16 ) ;
V_29 = V_28 -> V_22 ;
if ( F_21 ( ! F_16 ( V_29 ) ) )
F_14 ( V_29 ) ;
else if ( V_29 -> V_31 & V_27 ) {
struct V_32 V_33 ;
V_27 |= V_34 ;
F_22 ( & V_33 , V_16 ) ;
if ( V_26 )
V_30 = F_12 ( V_29 , V_27 , V_26 , V_35 ,
V_33 . V_33 , 0 ) ;
else
V_30 = F_12 ( V_29 , V_27 , V_16 -> V_22 , V_15 ,
V_33 . V_33 , 0 ) ;
F_23 ( & V_33 ) ;
}
F_24 ( V_28 ) ;
return V_30 ;
}
static int F_25 ( struct V_1 * V_36 ,
struct V_37 * V_38 ,
struct V_37 * V_39 ,
T_1 V_27 , const void * V_40 ,
int V_41 , T_2 V_42 ,
const unsigned char * V_43 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 = NULL ;
T_1 V_48 = 0 ;
T_1 V_49 = 0 ;
if ( F_21 ( ! V_38 && ! V_39 ) ) {
F_26 () ;
return 0 ;
}
if ( V_27 & V_50 ) {
if ( V_38 &&
! ( V_38 -> V_51 & V_52 ) )
V_38 -> V_53 = 0 ;
if ( V_39 &&
! ( V_39 -> V_51 & V_52 ) )
V_39 -> V_53 = 0 ;
}
if ( V_38 ) {
V_47 = V_38 -> V_47 ;
V_48 = ( V_27 & ~ V_34 ) ;
V_48 &= V_38 -> V_27 ;
V_48 &= ~ V_38 -> V_53 ;
}
if ( V_39 ) {
V_49 = ( V_27 & ~ V_34 ) ;
V_47 = V_39 -> V_47 ;
V_49 &= V_39 -> V_27 ;
V_49 &= ~ V_39 -> V_53 ;
if ( V_38 )
V_49 &= ~ V_38 -> V_53 ;
}
F_27 ( L_1
L_2
L_3 ,
V_54 , V_47 , V_36 , V_27 , V_38 ,
V_48 , V_39 , V_49 , V_40 ,
V_41 , V_42 ) ;
if ( ! V_48 && ! V_49 )
return 0 ;
return V_47 -> V_55 -> V_56 ( V_47 , V_36 , V_38 ,
V_39 , V_27 , V_40 , V_41 ,
V_43 , V_42 , V_45 ) ;
}
int F_12 ( struct V_1 * V_36 , T_1 V_27 , const void * V_40 , int V_41 ,
const unsigned char * V_43 , T_2 V_42 )
{
struct V_57 * V_58 = NULL , * V_59 = NULL ;
struct V_37 * V_38 = NULL , * V_39 = NULL ;
struct V_46 * V_60 , * V_61 ;
struct V_62 * V_63 , * V_64 ;
struct V_44 V_45 ;
struct V_65 * V_3 ;
int V_30 = 0 ;
T_1 V_66 = ( V_27 & ~ V_34 ) ;
if ( V_41 == V_35 )
V_3 = F_28 ( ( ( const struct V_26 * ) V_40 ) -> V_3 ) ;
else
V_3 = NULL ;
if ( ! V_36 -> V_67 &&
( ! V_3 || ! V_3 -> V_68 ) )
return 0 ;
if ( ! ( V_27 & V_50 ) &&
! ( V_66 & V_36 -> V_31 ) &&
! ( V_3 && V_66 & V_3 -> V_69 ) )
return 0 ;
V_45 . V_70 = F_29 ( & V_71 ) ;
if ( ( V_27 & V_50 ) ||
( V_66 & V_36 -> V_31 ) ) {
V_63 = F_30 ( V_36 -> V_67 ,
& V_71 ) ;
if ( V_63 )
V_58 = F_30 ( V_63 -> V_72 . V_73 ,
& V_71 ) ;
}
if ( V_3 && ( ( V_27 & V_50 ) ||
( V_66 & V_3 -> V_69 ) ) ) {
V_63 = F_30 ( V_36 -> V_67 ,
& V_71 ) ;
if ( V_63 )
V_58 = F_30 ( V_63 -> V_72 . V_73 ,
& V_71 ) ;
V_64 = F_30 ( V_3 -> V_68 ,
& V_71 ) ;
if ( V_64 )
V_59 = F_30 (
V_64 -> V_72 . V_73 ,
& V_71 ) ;
}
while ( V_58 || V_59 ) {
V_60 = NULL ;
V_38 = NULL ;
V_61 = NULL ;
V_39 = NULL ;
if ( V_58 ) {
V_38 = F_31 ( F_30 ( V_58 , & V_71 ) ,
struct V_37 , V_74 ) ;
V_60 = V_38 -> V_47 ;
}
if ( V_59 ) {
V_39 = F_31 ( F_30 ( V_59 , & V_71 ) ,
struct V_37 , V_74 ) ;
V_61 = V_39 -> V_47 ;
}
if ( V_60 && V_61 ) {
int V_75 = F_32 ( V_60 ,
V_61 ) ;
if ( V_75 > 0 ) {
V_60 = NULL ;
V_38 = NULL ;
} else if ( V_75 < 0 ) {
V_61 = NULL ;
V_39 = NULL ;
}
}
V_45 . V_38 = V_38 ;
V_45 . V_39 = V_39 ;
V_30 = F_25 ( V_36 , V_38 , V_39 , V_27 ,
V_40 , V_41 , V_42 , V_43 ,
& V_45 ) ;
if ( V_30 && ( V_27 & V_76 ) )
goto V_77;
if ( V_60 )
V_58 = F_30 ( V_58 -> V_78 ,
& V_71 ) ;
if ( V_61 )
V_59 = F_30 ( V_59 -> V_78 ,
& V_71 ) ;
}
V_30 = 0 ;
V_77:
F_33 ( & V_71 , V_45 . V_70 ) ;
return V_30 ;
}
static T_3 int F_34 ( void )
{
int V_30 ;
F_35 ( F_36 ( V_79 ) != 23 ) ;
V_30 = F_37 ( & V_71 ) ;
if ( V_30 )
F_38 ( L_4 ) ;
V_80 = F_39 ( V_62 ,
V_81 ) ;
return 0 ;
}
