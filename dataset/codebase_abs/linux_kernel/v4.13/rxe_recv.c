static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( F_2 ( ! V_6 -> V_7 ) )
goto V_8;
switch ( F_3 ( V_6 ) ) {
case V_9 :
if ( F_2 ( ( V_4 -> V_10 & V_11 ) != 0 ) ) {
F_4 ( L_1 ) ;
goto V_8;
}
break;
case V_12 :
if ( F_2 ( ! ( V_4 -> V_10 & V_13 ) ) ) {
F_4 ( L_1 ) ;
goto V_8;
}
break;
case V_14 :
case V_15 :
case V_16 :
if ( F_2 ( ! ( V_4 -> V_10 & V_17 ) ) ) {
F_4 ( L_1 ) ;
goto V_8;
}
break;
default:
F_4 ( L_2 ) ;
goto V_8;
}
if ( V_4 -> V_18 & V_19 ) {
if ( F_2 ( V_6 -> V_20 . V_21 != V_22 ) )
goto V_8;
} else if ( F_2 ( V_6 -> V_23 . V_21 < V_22 ||
V_6 -> V_23 . V_21 > V_24 ) ) {
goto V_8;
}
return 0 ;
V_8:
return - V_25 ;
}
static void F_5 ( struct V_26 * V_27 )
{
F_6 ( & V_27 -> V_28 ) ;
V_27 -> V_29 . V_30 = F_7 ( ( V_31 ) 0xffff ,
V_27 -> V_29 . V_30 + 1 ) ;
F_8 ( & V_27 -> V_28 ) ;
}
static void F_9 ( struct V_26 * V_27 )
{
F_6 ( & V_27 -> V_28 ) ;
V_27 -> V_29 . V_32 = F_7 ( ( V_31 ) 0xffff ,
V_27 -> V_29 . V_32 + 1 ) ;
F_8 ( & V_27 -> V_28 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
V_31 V_33 , struct V_5 * V_6 )
{
int V_34 ;
int V_35 = 0 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
T_1 V_36 = F_11 ( V_4 ) ;
V_4 -> V_37 = 0 ;
if ( V_33 == 1 ) {
for ( V_34 = 0 ; V_34 < V_27 -> V_29 . V_38 ; V_34 ++ ) {
if ( F_12 ( V_36 , V_27 -> V_39 [ V_34 ] ) ) {
V_4 -> V_37 = V_34 ;
V_35 = 1 ;
break;
}
}
if ( ! V_35 ) {
F_4 ( L_3 , V_36 ) ;
F_5 ( V_27 ) ;
goto V_8;
}
} else if ( V_33 != 0 ) {
if ( F_2 ( ! F_12 ( V_36 ,
V_27 -> V_39 [ V_6 -> V_29 . V_37 ]
) ) ) {
F_4 ( L_4 , V_36 ) ;
F_5 ( V_27 ) ;
goto V_8;
}
V_4 -> V_37 = V_6 -> V_29 . V_37 ;
}
if ( ( F_3 ( V_6 ) == V_14 || F_3 ( V_6 ) == V_16 ) &&
V_33 != 0 && V_4 -> V_18 ) {
V_31 V_40 = ( V_33 == 1 ) ? V_41 : V_6 -> V_29 . V_40 ;
if ( F_2 ( F_13 ( V_4 ) != V_40 ) ) {
F_4 ( L_5 ,
F_13 ( V_4 ) , V_40 , V_33 ) ;
F_9 ( V_27 ) ;
goto V_8;
}
}
return 0 ;
V_8:
return - V_25 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_42 * V_43 = F_15 ( V_4 ) ;
if ( F_3 ( V_6 ) != V_9 && F_3 ( V_6 ) != V_12 )
goto V_44;
if ( F_2 ( V_4 -> V_45 != V_6 -> V_29 . V_45 ) ) {
F_4 ( L_6 ,
V_4 -> V_45 , V_6 -> V_29 . V_45 ) ;
goto V_8;
}
if ( V_43 -> V_46 == F_16 ( V_47 ) ) {
struct V_48 * V_49 =
& V_6 -> V_50 . V_51 . V_52 . V_53 ;
struct V_48 * V_54 =
& V_6 -> V_50 . V_55 . V_52 . V_53 ;
if ( F_17 ( V_43 ) -> V_54 != V_49 -> V_56 ) {
F_4 ( L_7 ,
& F_17 ( V_43 ) -> V_54 ,
& V_49 -> V_56 ) ;
goto V_8;
}
if ( F_17 ( V_43 ) -> V_49 != V_54 -> V_56 ) {
F_4 ( L_8 ,
& F_17 ( V_43 ) -> V_49 ,
& V_54 -> V_56 ) ;
goto V_8;
}
} else if ( V_43 -> V_46 == F_16 ( V_57 ) ) {
struct V_58 * V_49 =
& V_6 -> V_50 . V_51 . V_59 . V_60 ;
struct V_58 * V_54 =
& V_6 -> V_50 . V_55 . V_59 . V_60 ;
if ( memcmp ( & F_18 ( V_43 ) -> V_54 , V_49 , sizeof( * V_49 ) ) ) {
F_4 ( L_9 ,
& F_18 ( V_43 ) -> V_54 , V_49 ) ;
goto V_8;
}
if ( memcmp ( & F_18 ( V_43 ) -> V_49 , V_54 , sizeof( * V_54 ) ) ) {
F_4 ( L_10 ,
& F_18 ( V_43 ) -> V_49 , V_54 ) ;
goto V_8;
}
}
V_44:
return 0 ;
V_8:
return - V_25 ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_5 * V_6 = NULL ;
V_31 V_33 = F_20 ( V_4 ) ;
int V_61 ;
int V_62 ;
if ( F_2 ( F_21 ( V_4 ) != V_63 ) ) {
F_4 ( L_11 ) ;
goto V_8;
}
if ( V_33 != V_64 ) {
V_61 = ( V_33 == 0 ) ? V_27 -> V_65 :
( ( V_33 == 1 ) ? V_27 -> V_66 : V_33 ) ;
V_6 = F_22 ( & V_2 -> V_67 , V_61 ) ;
if ( F_2 ( ! V_6 ) ) {
F_4 ( L_12 , V_33 ) ;
goto V_8;
}
V_62 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( F_2 ( V_62 ) )
goto V_68;
V_62 = F_14 ( V_2 , V_4 , V_6 ) ;
if ( F_2 ( V_62 ) )
goto V_68;
V_62 = F_10 ( V_2 , V_4 , V_33 , V_6 ) ;
if ( F_2 ( V_62 ) )
goto V_68;
} else {
if ( F_2 ( ( V_4 -> V_18 & V_69 ) == 0 ) ) {
F_4 ( L_13 ) ;
goto V_8;
}
}
V_4 -> V_6 = V_6 ;
return 0 ;
V_68:
if ( V_6 )
F_23 ( V_6 ) ;
V_8:
return - V_25 ;
}
static inline void F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_42 * V_43 )
{
if ( V_4 -> V_18 & V_19 )
F_25 ( V_2 , V_4 -> V_6 , V_43 ) ;
else
F_26 ( V_2 , V_4 -> V_6 , V_43 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_3 * V_4 = F_28 ( V_43 ) ;
struct V_70 * V_71 ;
struct V_42 * V_72 ;
struct V_73 * V_74 ;
struct V_5 * V_6 ;
union V_75 V_76 ;
int V_62 ;
if ( V_43 -> V_46 == F_16 ( V_47 ) )
F_29 ( F_17 ( V_43 ) -> V_54 ,
(struct V_58 * ) & V_76 ) ;
else if ( V_43 -> V_46 == F_16 ( V_57 ) )
memcpy ( & V_76 , & F_18 ( V_43 ) -> V_54 , sizeof( V_76 ) ) ;
V_71 = F_30 ( & V_2 -> V_77 , & V_76 ) ;
if ( ! V_71 )
goto V_8;
F_6 ( & V_71 -> V_78 ) ;
F_31 (mce, &mcg->qp_list, qp_list) {
V_6 = V_74 -> V_6 ;
V_4 = F_28 ( V_43 ) ;
V_62 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_62 )
continue;
V_62 = F_10 ( V_2 , V_4 , F_20 ( V_4 ) , V_6 ) ;
if ( V_62 )
continue;
V_72 = ( V_74 -> V_79 . V_80 != & V_71 -> V_79 ) ?
F_32 ( V_43 , V_81 ) : NULL ;
V_4 -> V_6 = V_6 ;
F_33 ( V_6 ) ;
F_24 ( V_2 , V_4 , V_43 ) ;
V_43 = V_72 ;
if ( ! V_43 )
break;
}
F_8 ( & V_71 -> V_78 ) ;
F_23 ( V_71 ) ;
V_8:
if ( V_43 )
F_34 ( V_43 ) ;
}
static int F_35 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
union V_75 V_76 ;
union V_75 * V_82 ;
T_1 V_61 ;
if ( V_43 -> V_46 == F_16 ( V_47 ) ) {
F_29 ( F_17 ( V_43 ) -> V_54 ,
(struct V_58 * ) & V_76 ) ;
V_82 = & V_76 ;
} else {
V_82 = (union V_75 * ) & F_18 ( V_43 ) -> V_54 ;
}
return F_36 ( & V_2 -> V_83 , V_82 ,
V_84 ,
1 , V_2 -> V_85 , & V_61 ) ;
}
int F_37 ( struct V_42 * V_43 )
{
int V_62 ;
struct V_3 * V_4 = F_28 ( V_43 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_2 * V_86 ;
V_31 V_87 , V_88 ;
V_4 -> V_89 = 0 ;
if ( F_2 ( V_43 -> V_90 < V_4 -> V_89 + V_91 ) )
goto V_92;
if ( F_2 ( F_35 ( V_2 , V_43 ) < 0 ) ) {
F_4 ( L_14 ) ;
goto V_92;
}
V_4 -> V_10 = F_38 ( V_4 ) ;
V_4 -> V_93 = F_39 ( V_4 ) ;
V_4 -> V_6 = NULL ;
V_4 -> V_18 |= V_94 [ V_4 -> V_10 ] . V_18 ;
if ( F_2 ( V_43 -> V_90 < F_40 ( V_4 ) ) )
goto V_92;
V_62 = F_19 ( V_4 ) ;
if ( F_2 ( V_62 ) )
goto V_92;
V_86 = ( T_2 * ) ( V_4 -> V_95 + V_4 -> V_96 - V_97 ) ;
V_88 = F_41 ( * V_86 ) ;
V_87 = F_42 ( V_4 , V_43 ) ;
V_87 = F_43 ( V_2 , V_87 , ( V_98 * ) F_44 ( V_4 ) ,
F_45 ( V_4 ) ) ;
V_87 = ( V_99 V_31 ) F_46 ( ~ V_87 ) ;
if ( F_2 ( V_87 != V_88 ) ) {
if ( V_43 -> V_46 == F_16 ( V_57 ) )
F_4 ( L_15 ,
& F_18 ( V_43 ) -> V_49 ) ;
else if ( V_43 -> V_46 == F_16 ( V_47 ) )
F_4 ( L_16 ,
& F_17 ( V_43 ) -> V_49 ) ;
else
F_4 ( L_17 ) ;
goto V_92;
}
F_47 ( V_2 , V_100 ) ;
if ( F_2 ( F_20 ( V_4 ) == V_64 ) )
F_27 ( V_2 , V_43 ) ;
else
F_24 ( V_2 , V_4 , V_43 ) ;
return 0 ;
V_92:
if ( V_4 -> V_6 )
F_23 ( V_4 -> V_6 ) ;
F_34 ( V_43 ) ;
return 0 ;
}
