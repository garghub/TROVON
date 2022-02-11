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
F_9 (alias, &inode->i_dentry, d_u.d_alias) {
struct V_4 * V_9 ;
F_8 ( & V_5 -> V_10 ) ;
F_10 (child, &alias->d_subdirs, d_child) {
if ( ! V_9 -> V_11 )
continue;
F_11 ( & V_9 -> V_10 , V_12 ) ;
if ( V_6 )
V_9 -> V_13 |= V_14 ;
else
V_9 -> V_13 &= ~ V_14 ;
F_12 ( & V_9 -> V_10 ) ;
}
F_12 ( & V_5 -> V_10 ) ;
}
F_12 ( & V_1 -> V_8 ) ;
}
int F_13 ( struct V_15 * V_15 , struct V_4 * V_4 , T_1 V_16 )
{
struct V_4 * V_17 ;
struct V_1 * V_18 ;
int V_19 = 0 ;
if ( ! V_4 )
V_4 = V_15 -> V_4 ;
if ( ! ( V_4 -> V_13 & V_14 ) )
return 0 ;
V_17 = F_14 ( V_4 ) ;
V_18 = V_17 -> V_11 ;
if ( F_15 ( ! F_7 ( V_18 ) ) )
F_5 ( V_18 ) ;
else if ( V_18 -> V_20 & V_16 ) {
V_16 |= V_21 ;
if ( V_15 )
V_19 = F_16 ( V_18 , V_16 , V_15 , V_22 ,
V_4 -> V_23 . V_24 , 0 ) ;
else
V_19 = F_16 ( V_18 , V_16 , V_4 -> V_11 , V_25 ,
V_4 -> V_23 . V_24 , 0 ) ;
}
F_17 ( V_17 ) ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_26 ,
struct V_27 * V_28 ,
struct V_27 * V_29 ,
T_1 V_16 , void * V_30 ,
int V_31 , T_2 V_32 ,
const unsigned char * V_33 )
{
struct V_34 * V_35 = NULL ;
T_1 V_36 = 0 ;
T_1 V_37 = 0 ;
if ( F_15 ( ! V_28 && ! V_29 ) ) {
F_19 () ;
return 0 ;
}
if ( V_16 & V_38 ) {
if ( V_28 &&
! ( V_28 -> V_39 & V_40 ) )
V_28 -> V_41 = 0 ;
if ( V_29 &&
! ( V_29 -> V_39 & V_40 ) )
V_29 -> V_41 = 0 ;
}
if ( V_28 ) {
V_35 = V_28 -> V_35 ;
V_36 = ( V_16 & ~ V_21 ) ;
V_36 &= V_28 -> V_16 ;
V_36 &= ~ V_28 -> V_41 ;
}
if ( V_29 ) {
V_37 = ( V_16 & ~ V_21 ) ;
V_35 = V_29 -> V_35 ;
V_37 &= V_29 -> V_16 ;
V_37 &= ~ V_29 -> V_41 ;
if ( V_28 )
V_37 &= ~ V_28 -> V_41 ;
}
F_20 ( L_1
L_2
L_3 ,
V_42 , V_35 , V_26 , V_16 , V_28 ,
V_36 , V_29 , V_37 , V_30 ,
V_31 , V_32 ) ;
if ( ! V_36 && ! V_37 )
return 0 ;
return V_35 -> V_43 -> V_44 ( V_35 , V_26 , V_28 ,
V_29 , V_16 , V_30 , V_31 ,
V_33 , V_32 ) ;
}
int F_16 ( struct V_1 * V_26 , T_1 V_16 , void * V_30 , int V_31 ,
const unsigned char * V_33 , T_2 V_32 )
{
struct V_45 * V_46 = NULL , * V_47 = NULL ;
struct V_27 * V_28 = NULL , * V_29 = NULL ;
struct V_34 * V_48 , * V_49 ;
struct V_50 * V_3 ;
int V_51 , V_19 = 0 ;
T_1 V_52 = ( V_16 & ~ V_21 ) ;
if ( V_31 == V_22 )
V_3 = F_21 ( ( (struct V_15 * ) V_30 ) -> V_3 ) ;
else
V_3 = NULL ;
if ( ! ( V_16 & V_38 ) &&
! ( V_52 & V_26 -> V_20 ) &&
! ( V_3 && V_52 & V_3 -> V_53 ) )
return 0 ;
V_51 = F_22 ( & V_54 ) ;
if ( ( V_16 & V_38 ) ||
( V_52 & V_26 -> V_20 ) )
V_46 = F_23 ( V_26 -> V_55 . V_56 ,
& V_54 ) ;
if ( V_3 && ( ( V_16 & V_38 ) ||
( V_52 & V_3 -> V_53 ) ) ) {
V_47 = F_23 ( V_3 -> V_57 . V_56 ,
& V_54 ) ;
V_46 = F_23 ( V_26 -> V_55 . V_56 ,
& V_54 ) ;
}
while ( V_46 || V_47 ) {
V_48 = NULL ;
V_28 = NULL ;
V_49 = NULL ;
V_29 = NULL ;
if ( V_46 ) {
V_28 = F_24 ( F_23 ( V_46 , & V_54 ) ,
struct V_27 , V_58 ) ;
V_48 = V_28 -> V_35 ;
}
if ( V_47 ) {
V_29 = F_24 ( F_23 ( V_47 , & V_54 ) ,
struct V_27 , V_58 ) ;
V_49 = V_29 -> V_35 ;
}
if ( V_48 && V_49 ) {
int V_59 = F_25 ( V_48 ,
V_49 ) ;
if ( V_59 > 0 ) {
V_48 = NULL ;
V_28 = NULL ;
} else if ( V_59 < 0 ) {
V_49 = NULL ;
V_29 = NULL ;
}
}
V_19 = F_18 ( V_26 , V_28 , V_29 , V_16 ,
V_30 , V_31 , V_32 , V_33 ) ;
if ( V_19 && ( V_16 & V_60 ) )
goto V_61;
if ( V_48 )
V_46 = F_23 ( V_46 -> V_62 ,
& V_54 ) ;
if ( V_49 )
V_47 = F_23 ( V_47 -> V_62 ,
& V_54 ) ;
}
V_19 = 0 ;
V_61:
F_26 ( & V_54 , V_51 ) ;
return V_19 ;
}
static T_3 int F_27 ( void )
{
int V_19 ;
F_28 ( F_29 ( V_63 ) != 23 ) ;
V_19 = F_30 ( & V_54 ) ;
if ( V_19 )
F_31 ( L_4 ) ;
return 0 ;
}
