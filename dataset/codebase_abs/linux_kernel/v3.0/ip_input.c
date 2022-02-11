int F_1 ( struct V_1 * V_2 )
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
if ( F_2 ( V_2 ) -> V_15 & F_8 ( V_16 | V_17 ) ) {
if ( F_9 ( V_2 , V_18 ) )
return 1 ;
}
if ( V_7 ) {
struct V_1 * V_19 = F_10 ( V_2 , V_20 ) ;
if ( V_19 )
F_11 ( V_7 , V_19 ) ;
}
V_7 = V_11 ;
}
}
if ( V_7 ) {
F_11 ( V_7 , V_2 ) ;
return 1 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_7 ( V_2 -> V_9 ) ;
F_13 ( V_2 , F_14 ( V_2 ) ) ;
F_15 ( V_2 ) ;
F_16 () ;
{
int V_5 = F_2 ( V_2 ) -> V_5 ;
int V_22 , V_23 ;
const struct V_24 * V_25 ;
V_26:
V_23 = F_17 ( V_2 , V_5 ) ;
V_22 = V_5 & ( V_27 - 1 ) ;
V_25 = F_3 ( V_28 [ V_22 ] ) ;
if ( V_25 != NULL ) {
int V_29 ;
if ( ! F_5 ( V_21 , & V_30 ) && ! V_25 -> V_31 ) {
if ( F_18 () )
F_19 ( L_1 ,
V_32 , V_5 ) ;
F_20 ( V_2 ) ;
goto V_33;
}
if ( ! V_25 -> V_34 ) {
if ( ! F_21 ( NULL , V_35 , V_2 ) ) {
F_20 ( V_2 ) ;
goto V_33;
}
F_22 ( V_2 ) ;
}
V_29 = V_25 -> V_36 ( V_2 ) ;
if ( V_29 < 0 ) {
V_5 = - V_29 ;
goto V_26;
}
F_23 ( V_21 , V_37 ) ;
} else {
if ( ! V_23 ) {
if ( F_21 ( NULL , V_35 , V_2 ) ) {
F_23 ( V_21 , V_38 ) ;
F_24 ( V_2 , V_39 ,
V_40 , 0 ) ;
}
} else
F_23 ( V_21 , V_37 ) ;
F_20 ( V_2 ) ;
}
}
V_33:
F_25 () ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_15 & F_8 ( V_16 | V_17 ) ) {
if ( F_9 ( V_2 , V_41 ) )
return 0 ;
}
return F_27 ( V_42 , V_43 , V_2 , V_2 -> V_9 , NULL ,
F_12 ) ;
}
static inline int F_28 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
const struct V_46 * V_47 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_29 ( V_2 , F_30 ( V_2 ) ) ) {
F_23 ( F_7 ( V_9 ) , V_48 ) ;
goto V_49;
}
V_47 = F_2 ( V_2 ) ;
V_45 = & ( F_31 ( V_2 ) -> V_45 ) ;
V_45 -> V_50 = V_47 -> V_51 * 4 - sizeof( struct V_46 ) ;
if ( F_32 ( F_7 ( V_9 ) , V_45 , V_2 ) ) {
F_23 ( F_7 ( V_9 ) , V_52 ) ;
goto V_49;
}
if ( F_33 ( V_45 -> V_53 ) ) {
struct V_54 * V_55 = F_34 ( V_9 ) ;
if ( V_55 ) {
if ( ! F_35 ( V_55 ) ) {
if ( F_36 ( V_55 ) &&
F_18 () )
F_19 ( V_56 L_2 ,
& V_47 -> V_57 , & V_47 -> V_58 ) ;
goto V_49;
}
}
if ( F_37 ( V_2 ) )
goto V_49;
}
return 0 ;
V_49:
return - 1 ;
}
static int F_38 ( struct V_1 * V_2 )
{
const struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_59 * V_60 ;
if ( F_39 ( V_2 ) == NULL ) {
int V_61 = F_40 ( V_2 , V_47 -> V_58 , V_47 -> V_57 ,
V_47 -> V_62 , V_2 -> V_9 ) ;
if ( F_33 ( V_61 ) ) {
if ( V_61 == - V_63 )
F_23 ( F_7 ( V_2 -> V_9 ) ,
V_64 ) ;
else if ( V_61 == - V_65 )
F_23 ( F_7 ( V_2 -> V_9 ) ,
V_66 ) ;
else if ( V_61 == - V_67 )
F_41 ( F_7 ( V_2 -> V_9 ) ,
V_68 ) ;
goto V_49;
}
}
#ifdef F_42
if ( F_33 ( F_39 ( V_2 ) -> V_69 ) ) {
struct V_70 * V_71 = F_43 ( V_70 ) ;
T_2 V_72 = F_39 ( V_2 ) -> V_69 ;
V_71 [ V_72 & 0xFF ] . V_73 ++ ;
V_71 [ V_72 & 0xFF ] . V_74 += V_2 -> V_75 ;
V_71 [ ( V_72 >> 16 ) & 0xFF ] . V_76 ++ ;
V_71 [ ( V_72 >> 16 ) & 0xFF ] . V_77 += V_2 -> V_75 ;
}
#endif
if ( V_47 -> V_51 > 5 && F_28 ( V_2 ) )
goto V_49;
V_60 = F_44 ( V_2 ) ;
if ( V_60 -> V_78 == V_79 ) {
F_45 ( F_7 ( V_60 -> V_80 . V_9 ) , V_81 ,
V_2 -> V_75 ) ;
} else if ( V_60 -> V_78 == V_82 )
F_45 ( F_7 ( V_60 -> V_80 . V_9 ) , V_83 ,
V_2 -> V_75 ) ;
return F_46 ( V_2 ) ;
V_49:
F_20 ( V_2 ) ;
return V_84 ;
}
int F_47 ( struct V_1 * V_2 , struct V_8 * V_9 , struct V_85 * V_86 , struct V_8 * V_87 )
{
const struct V_46 * V_47 ;
T_2 V_75 ;
if ( V_2 -> V_88 == V_89 )
goto V_49;
F_45 ( F_7 ( V_9 ) , V_90 , V_2 -> V_75 ) ;
if ( ( V_2 = F_48 ( V_2 , V_20 ) ) == NULL ) {
F_23 ( F_7 ( V_9 ) , V_48 ) ;
goto V_33;
}
if ( ! F_49 ( V_2 , sizeof( struct V_46 ) ) )
goto V_91;
V_47 = F_2 ( V_2 ) ;
if ( V_47 -> V_51 < 5 || V_47 -> V_92 != 4 )
goto V_91;
if ( ! F_49 ( V_2 , V_47 -> V_51 * 4 ) )
goto V_91;
V_47 = F_2 ( V_2 ) ;
if ( F_33 ( F_50 ( ( T_1 * ) V_47 , V_47 -> V_51 ) ) )
goto V_91;
V_75 = F_51 ( V_47 -> V_93 ) ;
if ( V_2 -> V_75 < V_75 ) {
F_23 ( F_7 ( V_9 ) , V_94 ) ;
goto V_49;
} else if ( V_75 < ( V_47 -> V_51 * 4 ) )
goto V_91;
if ( F_52 ( V_2 , V_75 ) ) {
F_23 ( F_7 ( V_9 ) , V_48 ) ;
goto V_49;
}
memset ( F_31 ( V_2 ) , 0 , sizeof( struct V_95 ) ) ;
F_53 ( V_2 ) ;
return F_27 ( V_42 , V_96 , V_2 , V_9 , NULL ,
F_38 ) ;
V_91:
F_23 ( F_7 ( V_9 ) , V_52 ) ;
V_49:
F_20 ( V_2 ) ;
V_33:
return V_84 ;
}
