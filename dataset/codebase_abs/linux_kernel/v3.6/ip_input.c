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
const struct V_19 * V_20 ;
int V_21 ;
V_22:
V_21 = F_17 ( V_2 , V_5 ) ;
V_20 = F_3 ( V_23 [ V_5 ] ) ;
if ( V_20 != NULL ) {
int V_24 ;
if ( ! F_5 ( V_18 , & V_25 ) && ! V_20 -> V_26 ) {
F_18 ( L_1 ,
V_27 , V_5 ) ;
F_19 ( V_2 ) ;
goto V_28;
}
if ( ! V_20 -> V_29 ) {
if ( ! F_20 ( NULL , V_30 , V_2 ) ) {
F_19 ( V_2 ) ;
goto V_28;
}
F_21 ( V_2 ) ;
}
V_24 = V_20 -> V_31 ( V_2 ) ;
if ( V_24 < 0 ) {
V_5 = - V_24 ;
goto V_22;
}
F_22 ( V_18 , V_32 ) ;
} else {
if ( ! V_21 ) {
if ( F_20 ( NULL , V_30 , V_2 ) ) {
F_22 ( V_18 , V_33 ) ;
F_23 ( V_2 , V_34 ,
V_35 , 0 ) ;
}
} else
F_22 ( V_18 , V_32 ) ;
F_19 ( V_2 ) ;
}
}
V_28:
F_24 () ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
if ( F_8 ( F_2 ( V_2 ) ) ) {
if ( F_9 ( V_2 , V_36 ) )
return 0 ;
}
return F_26 ( V_37 , V_38 , V_2 , V_2 -> V_9 , NULL ,
F_12 ) ;
}
static inline bool F_27 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
const struct V_41 * V_42 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_28 ( V_2 , F_29 ( V_2 ) ) ) {
F_22 ( F_7 ( V_9 ) , V_43 ) ;
goto V_44;
}
V_42 = F_2 ( V_2 ) ;
V_40 = & ( F_30 ( V_2 ) -> V_40 ) ;
V_40 -> V_45 = V_42 -> V_46 * 4 - sizeof( struct V_41 ) ;
if ( F_31 ( F_7 ( V_9 ) , V_40 , V_2 ) ) {
F_22 ( F_7 ( V_9 ) , V_47 ) ;
goto V_44;
}
if ( F_32 ( V_40 -> V_48 ) ) {
struct V_49 * V_50 = F_33 ( V_9 ) ;
if ( V_50 ) {
if ( ! F_34 ( V_50 ) ) {
if ( F_35 ( V_50 ) )
F_18 ( L_2 ,
& V_42 -> V_51 ,
& V_42 -> V_52 ) ;
goto V_44;
}
}
if ( F_36 ( V_2 ) )
goto V_44;
}
return false ;
V_44:
return true ;
}
static int F_37 ( struct V_1 * V_2 )
{
const struct V_41 * V_42 = F_2 ( V_2 ) ;
struct V_53 * V_54 ;
if ( V_55 && ! F_38 ( V_2 ) ) {
const struct V_19 * V_20 ;
int V_5 = V_42 -> V_5 ;
V_20 = F_3 ( V_23 [ V_5 ] ) ;
if ( V_20 && V_20 -> V_56 ) {
V_20 -> V_56 ( V_2 ) ;
V_42 = F_2 ( V_2 ) ;
}
}
if ( ! F_38 ( V_2 ) ) {
int V_57 = F_39 ( V_2 , V_42 -> V_52 , V_42 -> V_51 ,
V_42 -> V_58 , V_2 -> V_9 ) ;
if ( F_32 ( V_57 ) ) {
if ( V_57 == - V_59 )
F_40 ( F_7 ( V_2 -> V_9 ) ,
V_60 ) ;
goto V_44;
}
}
#ifdef F_41
if ( F_32 ( F_38 ( V_2 ) -> V_61 ) ) {
struct V_62 * V_63 = F_42 ( V_62 ) ;
T_2 V_64 = F_38 ( V_2 ) -> V_61 ;
V_63 [ V_64 & 0xFF ] . V_65 ++ ;
V_63 [ V_64 & 0xFF ] . V_66 += V_2 -> V_67 ;
V_63 [ ( V_64 >> 16 ) & 0xFF ] . V_68 ++ ;
V_63 [ ( V_64 >> 16 ) & 0xFF ] . V_69 += V_2 -> V_67 ;
}
#endif
if ( V_42 -> V_46 > 5 && F_27 ( V_2 ) )
goto V_44;
V_54 = F_43 ( V_2 ) ;
if ( V_54 -> V_70 == V_71 ) {
F_44 ( F_7 ( V_54 -> V_72 . V_9 ) , V_73 ,
V_2 -> V_67 ) ;
} else if ( V_54 -> V_70 == V_74 )
F_44 ( F_7 ( V_54 -> V_72 . V_9 ) , V_75 ,
V_2 -> V_67 ) ;
return F_45 ( V_2 ) ;
V_44:
F_19 ( V_2 ) ;
return V_76 ;
}
int F_46 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_77 * V_78 , struct V_8 * V_79 )
{
const struct V_41 * V_42 ;
T_2 V_67 ;
if ( V_2 -> V_80 == V_81 )
goto V_44;
F_44 ( F_7 ( V_9 ) , V_82 , V_2 -> V_67 ) ;
if ( ( V_2 = F_47 ( V_2 , V_17 ) ) == NULL ) {
F_22 ( F_7 ( V_9 ) , V_43 ) ;
goto V_28;
}
if ( ! F_48 ( V_2 , sizeof( struct V_41 ) ) )
goto V_83;
V_42 = F_2 ( V_2 ) ;
if ( V_42 -> V_46 < 5 || V_42 -> V_84 != 4 )
goto V_83;
if ( ! F_48 ( V_2 , V_42 -> V_46 * 4 ) )
goto V_83;
V_42 = F_2 ( V_2 ) ;
if ( F_32 ( F_49 ( ( T_1 * ) V_42 , V_42 -> V_46 ) ) )
goto V_83;
V_67 = F_50 ( V_42 -> V_85 ) ;
if ( V_2 -> V_67 < V_67 ) {
F_22 ( F_7 ( V_9 ) , V_86 ) ;
goto V_44;
} else if ( V_67 < ( V_42 -> V_46 * 4 ) )
goto V_83;
if ( F_51 ( V_2 , V_67 ) ) {
F_22 ( F_7 ( V_9 ) , V_43 ) ;
goto V_44;
}
memset ( F_30 ( V_2 ) , 0 , sizeof( struct V_87 ) ) ;
F_52 ( V_2 ) ;
return F_26 ( V_37 , V_88 , V_2 , V_9 , NULL ,
F_37 ) ;
V_83:
F_22 ( F_7 ( V_9 ) , V_47 ) ;
V_44:
F_19 ( V_2 ) ;
V_28:
return V_76 ;
}
