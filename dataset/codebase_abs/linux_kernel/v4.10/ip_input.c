bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_10 = F_3 ( V_9 ) ;
for ( V_4 = F_4 ( V_3 ) ; V_4 ; V_4 = F_4 ( V_4 -> V_11 ) ) {
struct V_6 * V_12 = V_4 -> V_12 ;
if ( V_12 && F_5 ( V_12 ) -> V_13 == V_5 &&
( ! V_12 -> V_14 ||
V_12 -> V_14 == V_9 -> V_15 ) &&
F_6 ( F_7 ( V_12 ) , V_10 ) ) {
if ( F_8 ( F_2 ( V_2 ) ) ) {
if ( F_9 ( V_10 , V_2 , V_16 ) )
return true ;
}
if ( V_7 ) {
struct V_1 * V_17 = F_10 ( V_2 , V_18 ) ;
if ( V_17 )
F_11 ( V_7 , V_17 ) ;
}
V_7 = V_12 ;
}
}
if ( V_7 ) {
F_11 ( V_7 , V_2 ) ;
return true ;
}
return false ;
}
static int F_12 ( struct V_10 * V_10 , struct V_6 * V_12 , struct V_1 * V_2 )
{
F_13 ( V_2 , F_14 ( V_2 ) ) ;
F_15 () ;
{
int V_5 = F_2 ( V_2 ) -> V_5 ;
const struct V_19 * V_20 ;
int V_21 ;
V_22:
V_21 = F_16 ( V_2 , V_5 ) ;
V_20 = F_4 ( V_23 [ V_5 ] ) ;
if ( V_20 ) {
int V_24 ;
if ( ! V_20 -> V_25 ) {
if ( ! F_17 ( NULL , V_26 , V_2 ) ) {
F_18 ( V_2 ) ;
goto V_27;
}
F_19 ( V_2 ) ;
}
V_24 = V_20 -> V_28 ( V_2 ) ;
if ( V_24 < 0 ) {
V_5 = - V_24 ;
goto V_22;
}
F_20 ( V_10 , V_29 ) ;
} else {
if ( ! V_21 ) {
if ( F_17 ( NULL , V_26 , V_2 ) ) {
F_20 ( V_10 , V_30 ) ;
F_21 ( V_2 , V_31 ,
V_32 , 0 ) ;
}
F_18 ( V_2 ) ;
} else {
F_20 ( V_10 , V_29 ) ;
F_22 ( V_2 ) ;
}
}
}
V_27:
F_23 () ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = F_3 ( V_2 -> V_9 ) ;
if ( F_8 ( F_2 ( V_2 ) ) ) {
if ( F_9 ( V_10 , V_2 , V_33 ) )
return 0 ;
}
return F_25 ( V_34 , V_35 ,
V_10 , NULL , V_2 , V_2 -> V_9 , NULL ,
F_12 ) ;
}
static inline bool F_26 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
const struct V_38 * V_39 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_27 ( V_2 , F_28 ( V_2 ) ) ) {
F_20 ( F_3 ( V_9 ) , V_40 ) ;
goto V_41;
}
V_39 = F_2 ( V_2 ) ;
V_37 = & ( F_29 ( V_2 ) -> V_37 ) ;
V_37 -> V_42 = V_39 -> V_43 * 4 - sizeof( struct V_38 ) ;
if ( F_30 ( F_3 ( V_9 ) , V_37 , V_2 ) ) {
F_20 ( F_3 ( V_9 ) , V_44 ) ;
goto V_41;
}
if ( F_31 ( V_37 -> V_45 ) ) {
struct V_46 * V_47 = F_32 ( V_9 ) ;
if ( V_47 ) {
if ( ! F_33 ( V_47 ) ) {
if ( F_34 ( V_47 ) )
F_35 ( L_1 ,
& V_39 -> V_48 ,
& V_39 -> V_49 ) ;
goto V_41;
}
}
if ( F_36 ( V_2 ) )
goto V_41;
}
return false ;
V_41:
return true ;
}
static int F_37 ( struct V_10 * V_10 , struct V_6 * V_12 , struct V_1 * V_2 )
{
const struct V_38 * V_39 = F_2 ( V_2 ) ;
struct V_50 * V_51 ;
struct V_8 * V_9 = V_2 -> V_9 ;
V_2 = F_38 ( V_2 ) ;
if ( ! V_2 )
return V_52 ;
if ( V_10 -> V_53 . V_54 &&
! F_39 ( V_2 ) &&
! V_2 -> V_12 &&
! F_8 ( V_39 ) ) {
const struct V_19 * V_20 ;
int V_5 = V_39 -> V_5 ;
V_20 = F_4 ( V_23 [ V_5 ] ) ;
if ( V_20 && V_20 -> V_55 ) {
V_20 -> V_55 ( V_2 ) ;
V_39 = F_2 ( V_2 ) ;
}
}
if ( ! F_40 ( V_2 ) ) {
int V_56 = F_41 ( V_2 , V_39 -> V_49 , V_39 -> V_48 ,
V_39 -> V_57 , V_9 ) ;
if ( F_31 ( V_56 ) ) {
if ( V_56 == - V_58 )
F_42 ( V_10 , V_59 ) ;
goto V_41;
}
}
#ifdef F_43
if ( F_31 ( F_39 ( V_2 ) -> V_60 ) ) {
struct V_61 * V_62 = F_44 ( V_61 ) ;
T_2 V_63 = F_39 ( V_2 ) -> V_60 ;
V_62 [ V_63 & 0xFF ] . V_64 ++ ;
V_62 [ V_63 & 0xFF ] . V_65 += V_2 -> V_66 ;
V_62 [ ( V_63 >> 16 ) & 0xFF ] . V_67 ++ ;
V_62 [ ( V_63 >> 16 ) & 0xFF ] . V_68 += V_2 -> V_66 ;
}
#endif
if ( V_39 -> V_43 > 5 && F_26 ( V_2 ) )
goto V_41;
V_51 = F_45 ( V_2 ) ;
if ( V_51 -> V_69 == V_70 ) {
F_46 ( V_10 , V_71 , V_2 -> V_66 ) ;
} else if ( V_51 -> V_69 == V_72 ) {
F_46 ( V_10 , V_73 , V_2 -> V_66 ) ;
} else if ( V_2 -> V_74 == V_75 ||
V_2 -> V_74 == V_76 ) {
struct V_46 * V_47 = F_32 ( V_9 ) ;
if ( V_47 &&
F_47 ( V_47 , V_77 ) )
goto V_41;
}
return F_48 ( V_2 ) ;
V_41:
F_18 ( V_2 ) ;
return V_78 ;
}
int F_49 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_79 * V_80 , struct V_8 * V_81 )
{
const struct V_38 * V_39 ;
struct V_10 * V_10 ;
T_2 V_66 ;
if ( V_2 -> V_74 == V_82 )
goto V_41;
V_10 = F_3 ( V_9 ) ;
F_46 ( V_10 , V_83 , V_2 -> V_66 ) ;
V_2 = F_50 ( V_2 , V_18 ) ;
if ( ! V_2 ) {
F_20 ( V_10 , V_40 ) ;
goto V_27;
}
if ( ! F_51 ( V_2 , sizeof( struct V_38 ) ) )
goto V_84;
V_39 = F_2 ( V_2 ) ;
if ( V_39 -> V_43 < 5 || V_39 -> V_85 != 4 )
goto V_84;
F_52 ( V_86 != V_87 + V_88 ) ;
F_52 ( V_89 != V_87 + V_90 ) ;
F_52 ( V_91 != V_87 + V_92 ) ;
F_53 ( V_10 ,
V_87 + ( V_39 -> V_57 & V_93 ) ,
F_54 (unsigned short, 1 , skb_shinfo(skb)->gso_segs) ) ;
if ( ! F_51 ( V_2 , V_39 -> V_43 * 4 ) )
goto V_84;
V_39 = F_2 ( V_2 ) ;
if ( F_31 ( F_55 ( ( T_1 * ) V_39 , V_39 -> V_43 ) ) )
goto V_94;
V_66 = F_56 ( V_39 -> V_95 ) ;
if ( V_2 -> V_66 < V_66 ) {
F_20 ( V_10 , V_96 ) ;
goto V_41;
} else if ( V_66 < ( V_39 -> V_43 * 4 ) )
goto V_84;
if ( F_57 ( V_2 , V_66 ) ) {
F_20 ( V_10 , V_40 ) ;
goto V_41;
}
V_2 -> V_97 = V_2 -> V_98 + V_39 -> V_43 * 4 ;
memset ( F_29 ( V_2 ) , 0 , sizeof( struct V_99 ) ) ;
F_29 ( V_2 ) -> V_100 = V_2 -> V_101 ;
F_58 ( V_2 ) ;
return F_25 ( V_34 , V_102 ,
V_10 , NULL , V_2 , V_9 , NULL ,
F_37 ) ;
V_94:
F_20 ( V_10 , V_103 ) ;
V_84:
F_20 ( V_10 , V_44 ) ;
V_41:
F_18 ( V_2 ) ;
V_27:
return V_78 ;
}
