bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 = V_2 -> V_9 ;
for ( V_4 = F_3 ( V_3 ) ; V_4 ; V_4 = F_3 ( V_4 -> V_10 ) ) {
struct V_6 * V_11 = V_4 -> V_11 ;
if ( V_11 && F_4 ( V_11 ) -> V_12 == V_5 &&
( ! V_11 -> V_13 ||
V_11 -> V_13 == V_9 -> V_14 ) &&
F_5 ( F_6 ( V_11 ) , F_7 ( V_9 ) ) ) {
if ( F_8 ( F_2 ( V_2 ) ) ) {
if ( F_9 ( V_2 , V_15 ) )
return true ;
}
if ( V_7 ) {
struct V_1 * V_16 = F_10 ( V_2 , V_17 ) ;
if ( V_16 )
F_11 ( V_7 , V_16 ) ;
}
V_7 = V_11 ;
}
}
if ( V_7 ) {
F_11 ( V_7 , V_2 ) ;
return true ;
}
return false ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_18 = F_7 ( V_2 -> V_9 ) ;
F_13 ( V_2 , F_14 ( V_2 ) ) ;
F_15 ( V_2 ) ;
F_16 () ;
{
int V_5 = F_2 ( V_2 ) -> V_5 ;
int V_19 , V_20 ;
const struct V_21 * V_22 ;
V_23:
V_20 = F_17 ( V_2 , V_5 ) ;
V_19 = V_5 & ( V_24 - 1 ) ;
V_22 = F_3 ( V_25 [ V_19 ] ) ;
if ( V_22 != NULL ) {
int V_26 ;
if ( ! F_5 ( V_18 , & V_27 ) && ! V_22 -> V_28 ) {
if ( F_18 () )
F_19 ( L_1 ,
V_29 , V_5 ) ;
F_20 ( V_2 ) ;
goto V_30;
}
if ( ! V_22 -> V_31 ) {
if ( ! F_21 ( NULL , V_32 , V_2 ) ) {
F_20 ( V_2 ) ;
goto V_30;
}
F_22 ( V_2 ) ;
}
V_26 = V_22 -> V_33 ( V_2 ) ;
if ( V_26 < 0 ) {
V_5 = - V_26 ;
goto V_23;
}
F_23 ( V_18 , V_34 ) ;
} else {
if ( ! V_20 ) {
if ( F_21 ( NULL , V_32 , V_2 ) ) {
F_23 ( V_18 , V_35 ) ;
F_24 ( V_2 , V_36 ,
V_37 , 0 ) ;
}
} else
F_23 ( V_18 , V_34 ) ;
F_20 ( V_2 ) ;
}
}
V_30:
F_25 () ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
if ( F_8 ( F_2 ( V_2 ) ) ) {
if ( F_9 ( V_2 , V_38 ) )
return 0 ;
}
return F_27 ( V_39 , V_40 , V_2 , V_2 -> V_9 , NULL ,
F_12 ) ;
}
static inline bool F_28 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_29 ( V_2 , F_30 ( V_2 ) ) ) {
F_23 ( F_7 ( V_9 ) , V_45 ) ;
goto V_46;
}
V_44 = F_2 ( V_2 ) ;
V_42 = & ( F_31 ( V_2 ) -> V_42 ) ;
V_42 -> V_47 = V_44 -> V_48 * 4 - sizeof( struct V_43 ) ;
if ( F_32 ( F_7 ( V_9 ) , V_42 , V_2 ) ) {
F_23 ( F_7 ( V_9 ) , V_49 ) ;
goto V_46;
}
if ( F_33 ( V_42 -> V_50 ) ) {
struct V_51 * V_52 = F_34 ( V_9 ) ;
if ( V_52 ) {
if ( ! F_35 ( V_52 ) ) {
if ( F_36 ( V_52 ) &&
F_18 () )
F_37 ( L_2 ,
& V_44 -> V_53 , & V_44 -> V_54 ) ;
goto V_46;
}
}
if ( F_38 ( V_2 ) )
goto V_46;
}
return false ;
V_46:
return true ;
}
static int F_39 ( struct V_1 * V_2 )
{
const struct V_43 * V_44 = F_2 ( V_2 ) ;
struct V_55 * V_56 ;
if ( F_40 ( V_2 ) == NULL ) {
int V_57 = F_41 ( V_2 , V_44 -> V_54 , V_44 -> V_53 ,
V_44 -> V_58 , V_2 -> V_9 ) ;
if ( F_33 ( V_57 ) ) {
if ( V_57 == - V_59 )
F_23 ( F_7 ( V_2 -> V_9 ) ,
V_60 ) ;
else if ( V_57 == - V_61 )
F_23 ( F_7 ( V_2 -> V_9 ) ,
V_62 ) ;
else if ( V_57 == - V_63 )
F_42 ( F_7 ( V_2 -> V_9 ) ,
V_64 ) ;
goto V_46;
}
}
#ifdef F_43
if ( F_33 ( F_40 ( V_2 ) -> V_65 ) ) {
struct V_66 * V_67 = F_44 ( V_66 ) ;
T_2 V_68 = F_40 ( V_2 ) -> V_65 ;
V_67 [ V_68 & 0xFF ] . V_69 ++ ;
V_67 [ V_68 & 0xFF ] . V_70 += V_2 -> V_71 ;
V_67 [ ( V_68 >> 16 ) & 0xFF ] . V_72 ++ ;
V_67 [ ( V_68 >> 16 ) & 0xFF ] . V_73 += V_2 -> V_71 ;
}
#endif
if ( V_44 -> V_48 > 5 && F_28 ( V_2 ) )
goto V_46;
V_56 = F_45 ( V_2 ) ;
if ( V_56 -> V_74 == V_75 ) {
F_46 ( F_7 ( V_56 -> V_76 . V_9 ) , V_77 ,
V_2 -> V_71 ) ;
} else if ( V_56 -> V_74 == V_78 )
F_46 ( F_7 ( V_56 -> V_76 . V_9 ) , V_79 ,
V_2 -> V_71 ) ;
return F_47 ( V_2 ) ;
V_46:
F_20 ( V_2 ) ;
return V_80 ;
}
int F_48 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_81 * V_82 , struct V_8 * V_83 )
{
const struct V_43 * V_44 ;
T_2 V_71 ;
if ( V_2 -> V_84 == V_85 )
goto V_46;
F_46 ( F_7 ( V_9 ) , V_86 , V_2 -> V_71 ) ;
if ( ( V_2 = F_49 ( V_2 , V_17 ) ) == NULL ) {
F_23 ( F_7 ( V_9 ) , V_45 ) ;
goto V_30;
}
if ( ! F_50 ( V_2 , sizeof( struct V_43 ) ) )
goto V_87;
V_44 = F_2 ( V_2 ) ;
if ( V_44 -> V_48 < 5 || V_44 -> V_88 != 4 )
goto V_87;
if ( ! F_50 ( V_2 , V_44 -> V_48 * 4 ) )
goto V_87;
V_44 = F_2 ( V_2 ) ;
if ( F_33 ( F_51 ( ( T_1 * ) V_44 , V_44 -> V_48 ) ) )
goto V_87;
V_71 = F_52 ( V_44 -> V_89 ) ;
if ( V_2 -> V_71 < V_71 ) {
F_23 ( F_7 ( V_9 ) , V_90 ) ;
goto V_46;
} else if ( V_71 < ( V_44 -> V_48 * 4 ) )
goto V_87;
if ( F_53 ( V_2 , V_71 ) ) {
F_23 ( F_7 ( V_9 ) , V_45 ) ;
goto V_46;
}
memset ( F_31 ( V_2 ) , 0 , sizeof( struct V_91 ) ) ;
F_54 ( V_2 ) ;
return F_27 ( V_39 , V_92 , V_2 , V_9 , NULL ,
F_39 ) ;
V_87:
F_23 ( F_7 ( V_9 ) , V_49 ) ;
V_46:
F_20 ( V_2 ) ;
V_30:
return V_80 ;
}
