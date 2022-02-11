void F_1 ( bool V_1 )
{
static T_1 V_2 [ V_3 ] ;
if ( F_2 ( V_2 , sizeof( V_2 ) ) && V_1 )
F_3 ( V_2 , sizeof( V_2 ) ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
F_5 ( V_5 , struct V_6 , V_8 ) ;
F_6 ( V_7 -> V_9 ) ;
F_7 ( V_7 ) ;
}
int F_3 ( void * V_2 , unsigned int V_10 )
{
int V_11 ;
struct V_6 * V_7 , * V_12 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 )
return - V_14 ;
V_7 -> V_9 = F_9 ( L_1 , 0 , 0 ) ;
if ( F_10 ( V_7 -> V_9 ) ) {
V_11 = F_11 ( V_7 -> V_9 ) ;
error: F_7 ( V_7 ) ;
F_12 ( L_2 , V_11 ) ;
return V_11 ;
}
V_11 = F_13 ( V_7 -> V_9 , V_2 , V_10 ) ;
if ( V_11 ) {
F_12 ( L_3 , V_11 ) ;
F_6 ( V_7 -> V_9 ) ;
goto error;
}
memcpy ( V_7 -> V_2 , V_2 , V_10 ) ;
F_14 ( & V_15 ) ;
V_12 = F_15 ( V_16 ,
F_16 ( & V_15 ) ) ;
F_17 ( V_16 , V_7 ) ;
F_18 ( & V_15 ) ;
if ( V_12 )
F_19 ( & V_12 -> V_8 , F_4 ) ;
return V_11 ;
}
static bool F_20 ( const void * V_17 ,
struct V_18 * V_19 )
{
struct V_6 * V_7 ;
bool V_20 = false ;
F_21 () ;
V_7 = F_22 ( V_16 ) ;
if ( V_7 ) {
F_23 ( V_7 -> V_9 , V_19 -> V_21 , V_17 ) ;
V_19 -> V_10 = V_22 ;
V_20 = true ;
}
F_24 () ;
return V_20 ;
}
static bool F_25 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_18 * V_19 )
{
if ( V_24 -> V_27 -> V_28 == V_29 ) {
const struct V_30 * V_31 = F_26 ( V_26 ) ;
T_2 V_17 [ 4 ] = { V_31 -> V_32 , V_31 -> V_33 , 0 , 0 } ;
return F_20 ( V_17 , V_19 ) ;
}
#if F_27 ( V_34 )
if ( V_24 -> V_27 -> V_28 == V_35 ) {
const struct V_36 * V_37 = F_28 ( V_26 ) ;
struct V_18 V_38 ;
if ( F_20 ( & V_37 -> V_32 , & V_38 ) ) {
struct V_39 * V_40 = & V_38 . V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ )
V_40 -> V_43 [ V_42 ] ^= V_37 -> V_33 . V_43 [ V_42 ] ;
return F_20 ( V_40 , V_19 ) ;
}
}
#endif
return false ;
}
void F_29 ( struct V_44 * V_45 , struct V_25 * V_46 )
{
struct V_47 * V_48 = F_30 ( V_45 ) ;
if ( F_31 ( V_46 ) -> V_49 == V_48 -> V_50 )
return;
V_46 = F_32 ( V_46 , V_51 ) ;
if ( ! V_46 )
return;
F_33 ( V_46 ) ;
V_48 -> V_52 = 0 ;
F_34 ( V_48 , V_46 ) ;
F_35 ( V_46 , F_36 ( V_46 ) ) ;
F_37 ( V_45 , V_46 -> V_53 ) ;
F_38 ( V_46 , V_45 ) ;
F_31 ( V_46 ) -> V_54 ++ ;
F_31 ( V_46 ) -> V_55 &= ~ V_56 ;
V_48 -> V_50 = F_31 ( V_46 ) -> V_49 ;
F_39 ( & V_45 -> V_57 , V_46 ) ;
V_48 -> V_58 = 1 ;
V_48 -> V_59 = V_46 -> V_10 ;
if ( F_31 ( V_46 ) -> V_55 & V_60 )
F_40 ( V_45 ) ;
}
static struct V_44 * F_41 ( struct V_44 * V_45 ,
struct V_25 * V_46 ,
struct V_61 * V_62 ,
struct V_23 * V_24 )
{
struct V_47 * V_48 ;
struct V_63 * V_64 = & F_42 ( V_45 ) -> V_65 ;
struct V_44 * V_66 ;
bool V_67 ;
V_24 -> V_68 = 0 ;
V_24 -> V_69 = 0 ;
V_24 -> V_45 = NULL ;
V_66 = F_42 ( V_45 ) -> V_70 -> V_71 ( V_45 , V_46 , V_24 , NULL ,
NULL , & V_67 ) ;
if ( ! V_66 )
return NULL ;
F_14 ( & V_64 -> V_72 . V_73 ) ;
V_64 -> V_72 . V_74 ++ ;
F_18 ( & V_64 -> V_72 . V_73 ) ;
V_48 = F_30 ( V_66 ) ;
V_48 -> V_75 = V_24 ;
F_43 ( V_24 ) -> V_76 = true ;
V_48 -> V_77 = F_44 ( F_45 ( V_46 ) -> V_78 ) ;
V_48 -> V_79 = V_48 -> V_77 ;
F_46 ( V_66 , V_80 ,
V_81 , V_82 ) ;
F_47 ( & V_24 -> V_83 , 2 ) ;
F_42 ( V_66 ) -> V_70 -> V_84 ( V_66 ) ;
F_48 ( V_66 ) ;
F_49 ( V_66 ) ;
F_50 ( V_66 ) ;
F_51 ( V_66 ) ;
V_48 -> V_50 = F_31 ( V_46 ) -> V_54 + 1 ;
F_29 ( V_66 , V_46 ) ;
F_43 ( V_24 ) -> V_50 = V_48 -> V_50 ;
V_48 -> V_85 = V_48 -> V_50 ;
return V_66 ;
}
static bool F_52 ( struct V_44 * V_45 )
{
struct V_86 * V_72 ;
V_72 = & F_42 ( V_45 ) -> V_65 . V_72 ;
if ( V_72 -> V_87 == 0 )
return false ;
if ( V_72 -> V_74 >= V_72 -> V_87 ) {
struct V_23 * V_88 ;
F_14 ( & V_72 -> V_73 ) ;
V_88 = V_72 -> V_89 ;
if ( ! V_88 || F_53 ( V_88 -> V_90 . V_91 , V_92 ) ) {
F_54 ( F_55 ( V_45 ) ,
V_93 ) ;
F_18 ( & V_72 -> V_73 ) ;
return false ;
}
V_72 -> V_89 = V_88 -> V_94 ;
V_72 -> V_74 -- ;
F_18 ( & V_72 -> V_73 ) ;
F_56 ( V_88 ) ;
}
return true ;
}
struct V_44 * F_57 ( struct V_44 * V_45 , struct V_25 * V_46 ,
struct V_23 * V_24 ,
struct V_18 * V_19 ,
struct V_61 * V_62 )
{
struct V_18 V_95 = { . V_10 = - 1 } ;
bool V_96 = F_31 ( V_46 ) -> V_49 != F_31 ( V_46 ) -> V_54 + 1 ;
struct V_44 * V_66 ;
if ( V_19 -> V_10 == 0 )
F_58 ( F_55 ( V_45 ) , V_97 ) ;
if ( ! ( ( V_98 & V_99 ) &&
( V_96 || V_19 -> V_10 >= 0 ) &&
F_52 ( V_45 ) ) ) {
V_19 -> V_10 = - 1 ;
return NULL ;
}
if ( V_96 && ( V_98 & V_100 ) )
goto V_101;
if ( V_19 -> V_10 >= 0 &&
F_25 ( V_24 , V_46 , & V_95 ) &&
V_19 -> V_10 == V_22 &&
V_19 -> V_10 == V_95 . V_10 &&
! memcmp ( V_19 -> V_21 , V_95 . V_21 , V_19 -> V_10 ) ) {
V_101:
V_66 = F_41 ( V_45 , V_46 , V_62 , V_24 ) ;
if ( V_66 ) {
V_19 -> V_10 = - 1 ;
F_58 ( F_55 ( V_45 ) ,
V_102 ) ;
return V_66 ;
}
F_58 ( F_55 ( V_45 ) , V_103 ) ;
} else if ( V_19 -> V_10 > 0 )
F_58 ( F_55 ( V_45 ) , V_103 ) ;
V_95 . exp = V_19 -> exp ;
* V_19 = V_95 ;
return NULL ;
}
