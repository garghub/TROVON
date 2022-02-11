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
struct V_39 * V_40 = (struct V_39 * ) V_38 . V_21 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ )
V_40 -> V_42 [ V_41 ] ^= V_37 -> V_33 . V_42 [ V_41 ] ;
return F_20 ( V_40 , V_19 ) ;
}
}
#endif
return false ;
}
static bool F_29 ( struct V_43 * V_44 ,
struct V_25 * V_45 ,
struct V_46 * V_47 ,
struct V_23 * V_24 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 = & F_30 ( V_44 ) -> V_52 ;
struct V_43 * V_53 ;
T_3 V_54 ;
V_24 -> V_55 = 0 ;
V_24 -> V_56 = 0 ;
V_24 -> V_44 = NULL ;
V_53 = F_30 ( V_44 ) -> V_57 -> V_58 ( V_44 , V_45 , V_24 , NULL ) ;
if ( ! V_53 )
return false ;
F_14 ( & V_51 -> V_59 -> V_60 ) ;
V_51 -> V_59 -> V_61 ++ ;
F_18 ( & V_51 -> V_59 -> V_60 ) ;
V_49 = F_31 ( V_53 ) ;
V_49 -> V_62 = V_24 ;
F_32 ( V_24 ) -> V_63 = true ;
V_49 -> V_64 = F_33 ( F_34 ( V_45 ) -> V_65 ) ;
F_35 ( V_53 , V_66 ,
V_67 , V_68 ) ;
F_36 ( & V_24 -> V_69 , 1 ) ;
F_37 ( V_44 , V_24 , V_53 ) ;
F_30 ( V_53 ) -> V_57 -> V_70 ( V_53 ) ;
F_38 ( V_53 ) ;
F_39 ( V_53 ) ;
F_40 ( V_53 ) ;
F_41 ( V_53 ) ;
V_54 = F_42 ( V_45 ) -> V_54 ;
if ( V_54 != F_42 ( V_45 ) -> V_71 + 1 ) {
struct V_25 * V_72 ;
if ( F_43 ( F_44 ( V_45 ) ) )
V_72 = F_45 ( V_45 , V_73 ) ;
else
V_72 = F_46 ( V_45 ) ;
if ( F_47 ( V_72 ) ) {
F_48 ( V_72 ) ;
F_49 ( V_72 , F_50 ( V_45 ) ) ;
F_51 ( V_72 , V_53 ) ;
F_52 ( & V_53 -> V_74 , V_72 ) ;
V_49 -> V_75 = 1 ;
V_49 -> V_76 = V_54 - F_42 ( V_45 ) -> V_71 - 1 ;
} else {
V_54 = F_42 ( V_45 ) -> V_71 + 1 ;
}
}
F_32 ( V_24 ) -> V_77 = V_49 -> V_77 = V_54 ;
V_44 -> V_78 ( V_44 ) ;
F_53 ( V_53 ) ;
F_54 ( V_53 ) ;
F_55 ( ! V_24 -> V_44 ) ;
return true ;
}
static bool F_56 ( struct V_43 * V_44 )
{
struct V_79 * V_59 ;
V_59 = F_30 ( V_44 ) -> V_52 . V_59 ;
if ( ! V_59 || V_59 -> V_80 == 0 )
return false ;
if ( V_59 -> V_61 >= V_59 -> V_80 ) {
struct V_23 * V_81 ;
F_14 ( & V_59 -> V_60 ) ;
V_81 = V_59 -> V_82 ;
if ( ! V_81 || F_57 ( V_81 -> V_83 . V_84 , V_85 ) ) {
F_18 ( & V_59 -> V_60 ) ;
F_58 ( F_59 ( V_44 ) ,
V_86 ) ;
return false ;
}
V_59 -> V_82 = V_81 -> V_87 ;
V_59 -> V_61 -- ;
F_18 ( & V_59 -> V_60 ) ;
F_60 ( V_81 ) ;
}
return true ;
}
bool F_61 ( struct V_43 * V_44 , struct V_25 * V_45 ,
struct V_23 * V_24 ,
struct V_18 * V_19 ,
struct V_46 * V_47 )
{
struct V_18 V_88 = { . V_10 = - 1 } ;
bool V_89 = F_42 ( V_45 ) -> V_54 != F_42 ( V_45 ) -> V_71 + 1 ;
if ( V_19 -> V_10 == 0 )
F_58 ( F_59 ( V_44 ) , V_90 ) ;
if ( ! ( ( V_91 & V_92 ) &&
( V_89 || V_19 -> V_10 >= 0 ) &&
F_56 ( V_44 ) ) ) {
V_19 -> V_10 = - 1 ;
return false ;
}
if ( V_89 && ( V_91 & V_93 ) )
goto V_94;
if ( V_19 -> V_10 >= 0 &&
F_25 ( V_24 , V_45 , & V_88 ) &&
V_19 -> V_10 == V_22 &&
V_19 -> V_10 == V_88 . V_10 &&
! memcmp ( V_19 -> V_21 , V_88 . V_21 , V_19 -> V_10 ) ) {
V_94:
if ( F_29 ( V_44 , V_45 , V_47 , V_24 ) ) {
V_19 -> V_10 = - 1 ;
F_58 ( F_59 ( V_44 ) ,
V_95 ) ;
return true ;
}
F_58 ( F_59 ( V_44 ) , V_96 ) ;
} else if ( V_19 -> V_10 > 0 )
F_58 ( F_59 ( V_44 ) , V_96 ) ;
V_88 . exp = V_19 -> exp ;
* V_19 = V_88 ;
return false ;
}
