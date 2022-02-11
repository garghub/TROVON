static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int * V_6 )
{
return - V_7 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_8 * V_9 )
{
}
static int F_3 ( T_1 type , T_1 V_10 , int * V_11 )
{
return - V_7 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_8 * V_9 , int V_11 ,
T_2 V_12 , T_3 V_13 , T_1 * V_14 ) {}
static int F_5 ( struct V_15 * V_15 , const struct V_16 * V_17 ,
const struct V_18 * V_19 , int V_20 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_5 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_25 V_26 ;
int V_27 ;
struct V_16 * V_28 ;
int V_29 = 0 ;
struct V_30 V_31 ;
int V_11 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_36 V_37 ;
struct V_38 V_39 = { 0 } ;
struct V_40 V_41 ;
F_9 ( L_1 , V_22 , V_22 -> V_42 ) ;
V_11 = F_10 ( V_43 , V_4 , V_5 , & V_26 ,
sizeof( V_26 ) ) ;
if ( V_11 )
return V_11 ;
if ( V_4 -> V_44 ) {
F_11 ( struct V_45 * , V_46 , V_4 -> V_44 ) ;
if ( V_4 -> V_47 < sizeof( * V_46 ) )
return - V_48 ;
if ( V_46 -> V_49 != V_43 ) {
return - V_7 ;
}
V_28 = & ( V_46 -> V_50 ) ;
if ( F_12 ( F_13 ( V_28 ) ) )
V_29 = V_46 -> V_51 ;
} else {
if ( V_2 -> V_52 != V_53 )
return - V_54 ;
V_28 = & V_2 -> V_55 ;
}
if ( ! V_29 )
V_29 = V_2 -> V_56 ;
if ( ! V_29 )
V_29 = V_24 -> V_57 . V_58 ;
if ( ! V_29 && F_14 ( V_28 ) )
V_29 = V_24 -> V_59 ;
else if ( ! V_29 )
V_29 = V_24 -> V_60 ;
V_27 = F_13 ( V_28 ) ;
if ( ( F_12 ( V_27 ) && ! V_29 ) ||
( V_27 & V_61 ) ||
( V_29 && V_2 -> V_56 && V_29 != V_2 -> V_56 ) )
return - V_48 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_62 = V_63 ;
V_31 . V_64 = V_24 -> V_64 ;
V_31 . V_28 = * V_28 ;
V_31 . V_65 = V_29 ;
V_31 . V_66 = V_2 -> V_67 ;
V_31 . V_68 = V_2 -> V_69 ;
V_31 . V_70 = V_26 . V_71 ;
V_31 . V_72 = V_26 . V_73 ;
F_15 ( V_2 , F_16 ( & V_31 ) ) ;
V_41 . V_74 = V_24 -> V_74 ;
V_31 . V_75 = F_17 ( V_41 . V_74 , V_31 . V_75 ) ;
V_33 = F_18 ( V_2 , & V_31 , V_28 ) ;
if ( F_19 ( V_33 ) )
return F_20 ( V_33 ) ;
V_35 = (struct V_34 * ) V_33 ;
if ( ! V_31 . V_65 && F_14 ( & V_31 . V_28 ) )
V_31 . V_65 = V_24 -> V_59 ;
else if ( ! V_31 . V_65 )
V_31 . V_65 = V_24 -> V_60 ;
V_37 . V_76 . type = V_26 . V_71 ;
V_37 . V_76 . V_10 = V_26 . V_73 ;
V_37 . V_76 . V_77 = 0 ;
V_37 . V_76 . V_78 . V_79 . V_80 = V_22 -> V_81 ;
V_37 . V_76 . V_78 . V_79 . V_82 = V_26 . V_83 ;
V_37 . V_4 = V_4 ;
V_37 . V_84 = 0 ;
V_37 . V_85 = V_43 ;
V_41 . V_86 = F_21 ( V_24 , & V_31 , V_33 ) ;
V_41 . V_87 = V_24 -> V_87 ;
V_41 . V_88 = NULL ;
F_22 ( V_2 ) ;
V_11 = F_23 ( V_2 , V_89 , & V_37 , V_5 ,
0 , & V_41 , & V_31 , V_35 ,
V_90 , & V_39 ) ;
if ( V_11 ) {
F_24 ( F_25 ( V_2 ) , V_35 -> V_91 ,
V_92 ) ;
F_26 ( V_2 ) ;
} else {
V_11 = F_27 ( V_2 , & V_31 ,
(struct V_25 * ) & V_37 . V_76 ,
V_5 ) ;
}
F_28 ( V_2 ) ;
F_29 ( V_33 ) ;
if ( V_11 )
return V_11 ;
return V_5 ;
}
static void * F_30 ( struct V_93 * V_94 , T_5 * V_95 )
{
return F_31 ( V_94 , V_95 , V_43 ) ;
}
static int F_32 ( struct V_93 * V_94 , void * V_96 )
{
if ( V_96 == V_97 ) {
F_33 ( V_94 , V_98 ) ;
} else {
int V_99 = ( (struct V_100 * ) V_94 -> V_101 ) -> V_99 ;
struct V_21 * V_22 = F_7 ( V_96 ) ;
T_6 V_102 = F_34 ( V_22 -> V_81 ) ;
T_6 V_103 = F_34 ( V_22 -> V_104 ) ;
F_35 ( V_94 , V_96 , V_102 , V_103 , V_99 ) ;
}
return 0 ;
}
static int T_7 F_36 ( struct V_15 * V_15 )
{
return F_37 ( V_15 , & V_105 ) ;
}
static void T_7 F_38 ( struct V_15 * V_15 )
{
return F_39 ( V_15 , & V_105 ) ;
}
int T_8 F_40 ( void )
{
#ifdef F_41
int V_106 = F_42 ( & V_107 ) ;
if ( V_106 )
return V_106 ;
#endif
V_108 . V_109 = V_109 ;
V_108 . V_110 = V_110 ;
V_108 . V_111 =
V_111 ;
V_108 . V_112 = V_112 ;
V_108 . V_113 = V_113 ;
V_108 . V_114 = V_114 ;
return F_43 ( & V_115 ) ;
}
void F_44 ( void )
{
V_108 . V_109 = F_1 ;
V_108 . V_110 = F_2 ;
V_108 . V_111 = F_2 ;
V_108 . V_112 = F_3 ;
V_108 . V_113 = F_4 ;
V_108 . V_114 = F_5 ;
#ifdef F_41
F_45 ( & V_107 ) ;
#endif
F_46 ( & V_115 ) ;
}
