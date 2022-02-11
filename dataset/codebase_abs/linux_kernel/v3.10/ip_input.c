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
if ( ! V_20 -> V_25 ) {
if ( ! F_18 ( NULL , V_26 , V_2 ) ) {
F_19 ( V_2 ) ;
goto V_27;
}
F_20 ( V_2 ) ;
}
V_24 = V_20 -> V_28 ( V_2 ) ;
if ( V_24 < 0 ) {
V_5 = - V_24 ;
goto V_22;
}
F_21 ( V_18 , V_29 ) ;
} else {
if ( ! V_21 ) {
if ( F_18 ( NULL , V_26 , V_2 ) ) {
F_21 ( V_18 , V_30 ) ;
F_22 ( V_2 , V_31 ,
V_32 , 0 ) ;
}
F_19 ( V_2 ) ;
} else {
F_21 ( V_18 , V_29 ) ;
F_23 ( V_2 ) ;
}
}
}
V_27:
F_24 () ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
if ( F_8 ( F_2 ( V_2 ) ) ) {
if ( F_9 ( V_2 , V_33 ) )
return 0 ;
}
return F_26 ( V_34 , V_35 , V_2 , V_2 -> V_9 , NULL ,
F_12 ) ;
}
static inline bool F_27 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
const struct V_38 * V_39 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_28 ( V_2 , F_29 ( V_2 ) ) ) {
F_21 ( F_7 ( V_9 ) , V_40 ) ;
goto V_41;
}
V_39 = F_2 ( V_2 ) ;
V_37 = & ( F_30 ( V_2 ) -> V_37 ) ;
V_37 -> V_42 = V_39 -> V_43 * 4 - sizeof( struct V_38 ) ;
if ( F_31 ( F_7 ( V_9 ) , V_37 , V_2 ) ) {
F_21 ( F_7 ( V_9 ) , V_44 ) ;
goto V_41;
}
if ( F_32 ( V_37 -> V_45 ) ) {
struct V_46 * V_47 = F_33 ( V_9 ) ;
if ( V_47 ) {
if ( ! F_34 ( V_47 ) ) {
if ( F_35 ( V_47 ) )
F_36 ( L_1 ,
& V_39 -> V_48 ,
& V_39 -> V_49 ) ;
goto V_41;
}
}
if ( F_37 ( V_2 ) )
goto V_41;
}
return false ;
V_41:
return true ;
}
static int F_38 ( struct V_1 * V_2 )
{
const struct V_38 * V_39 = F_2 ( V_2 ) ;
struct V_50 * V_51 ;
if ( V_52 && ! F_39 ( V_2 ) ) {
const struct V_19 * V_20 ;
int V_5 = V_39 -> V_5 ;
V_20 = F_3 ( V_23 [ V_5 ] ) ;
if ( V_20 && V_20 -> V_53 ) {
V_20 -> V_53 ( V_2 ) ;
V_39 = F_2 ( V_2 ) ;
}
}
if ( ! F_39 ( V_2 ) ) {
int V_54 = F_40 ( V_2 , V_39 -> V_49 , V_39 -> V_48 ,
V_39 -> V_55 , V_2 -> V_9 ) ;
if ( F_32 ( V_54 ) ) {
if ( V_54 == - V_56 )
F_41 ( F_7 ( V_2 -> V_9 ) ,
V_57 ) ;
goto V_41;
}
}
#ifdef F_42
if ( F_32 ( F_39 ( V_2 ) -> V_58 ) ) {
struct V_59 * V_60 = F_43 ( V_59 ) ;
T_2 V_61 = F_39 ( V_2 ) -> V_58 ;
V_60 [ V_61 & 0xFF ] . V_62 ++ ;
V_60 [ V_61 & 0xFF ] . V_63 += V_2 -> V_64 ;
V_60 [ ( V_61 >> 16 ) & 0xFF ] . V_65 ++ ;
V_60 [ ( V_61 >> 16 ) & 0xFF ] . V_66 += V_2 -> V_64 ;
}
#endif
if ( V_39 -> V_43 > 5 && F_27 ( V_2 ) )
goto V_41;
V_51 = F_44 ( V_2 ) ;
if ( V_51 -> V_67 == V_68 ) {
F_45 ( F_7 ( V_51 -> V_69 . V_9 ) , V_70 ,
V_2 -> V_64 ) ;
} else if ( V_51 -> V_67 == V_71 )
F_45 ( F_7 ( V_51 -> V_69 . V_9 ) , V_72 ,
V_2 -> V_64 ) ;
return F_46 ( V_2 ) ;
V_41:
F_19 ( V_2 ) ;
return V_73 ;
}
int F_47 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_74 * V_75 , struct V_8 * V_76 )
{
const struct V_38 * V_39 ;
T_2 V_64 ;
if ( V_2 -> V_77 == V_78 )
goto V_41;
F_45 ( F_7 ( V_9 ) , V_79 , V_2 -> V_64 ) ;
if ( ( V_2 = F_48 ( V_2 , V_17 ) ) == NULL ) {
F_21 ( F_7 ( V_9 ) , V_40 ) ;
goto V_27;
}
if ( ! F_49 ( V_2 , sizeof( struct V_38 ) ) )
goto V_80;
V_39 = F_2 ( V_2 ) ;
if ( V_39 -> V_43 < 5 || V_39 -> V_81 != 4 )
goto V_80;
if ( ! F_49 ( V_2 , V_39 -> V_43 * 4 ) )
goto V_80;
V_39 = F_2 ( V_2 ) ;
if ( F_32 ( F_50 ( ( T_1 * ) V_39 , V_39 -> V_43 ) ) )
goto V_82;
V_64 = F_51 ( V_39 -> V_83 ) ;
if ( V_2 -> V_64 < V_64 ) {
F_21 ( F_7 ( V_9 ) , V_84 ) ;
goto V_41;
} else if ( V_64 < ( V_39 -> V_43 * 4 ) )
goto V_80;
if ( F_52 ( V_2 , V_64 ) ) {
F_21 ( F_7 ( V_9 ) , V_40 ) ;
goto V_41;
}
memset ( F_30 ( V_2 ) , 0 , sizeof( struct V_85 ) ) ;
F_53 ( V_2 ) ;
return F_26 ( V_34 , V_86 , V_2 , V_9 , NULL ,
F_38 ) ;
V_82:
F_21 ( F_7 ( V_9 ) , V_87 ) ;
V_80:
F_21 ( F_7 ( V_9 ) , V_44 ) ;
V_41:
F_19 ( V_2 ) ;
V_27:
return V_73 ;
}
