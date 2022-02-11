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
int F_6 ( struct V_21 * V_22 , struct V_1 * V_2 , struct V_3 * V_4 ,
T_4 V_5 )
{
struct V_23 * V_24 = F_7 ( V_2 ) ;
struct V_25 * V_26 = F_8 ( V_2 ) ;
struct V_27 V_28 ;
int V_29 ;
struct V_16 * V_30 ;
int V_31 = 0 ;
struct V_32 V_33 ;
int V_11 ;
int V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_39 V_40 ;
F_9 ( L_1 , V_24 , V_24 -> V_41 ) ;
V_11 = F_10 ( V_42 , V_4 , V_5 , & V_28 ,
sizeof( V_28 ) ) ;
if ( V_11 )
return V_11 ;
if ( V_4 -> V_43 ) {
F_11 ( struct V_44 * , V_45 , V_4 -> V_43 ) ;
if ( V_4 -> V_46 < sizeof( * V_45 ) )
return - V_47 ;
if ( V_45 -> V_48 != V_42 ) {
return - V_7 ;
}
if ( V_2 -> V_49 &&
V_2 -> V_49 != V_45 -> V_50 ) {
return - V_47 ;
}
V_30 = & ( V_45 -> V_51 ) ;
V_31 = V_45 -> V_50 ;
} else {
if ( V_2 -> V_52 != V_53 )
return - V_54 ;
V_30 = & V_2 -> V_55 ;
}
if ( ! V_31 )
V_31 = V_2 -> V_49 ;
V_29 = F_12 ( V_30 ) ;
if ( F_13 ( V_29 ) && ! V_31 )
return - V_47 ;
if ( V_29 & V_56 )
return - V_47 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_57 = V_58 ;
V_33 . V_59 = V_26 -> V_59 ;
V_33 . V_30 = * V_30 ;
V_33 . V_60 = V_2 -> V_61 ;
V_33 . V_62 = V_28 . V_63 ;
V_33 . V_64 = V_28 . V_65 ;
F_14 ( V_2 , F_15 ( & V_33 ) ) ;
if ( ! V_33 . V_66 && F_16 ( & V_33 . V_30 ) )
V_33 . V_66 = V_26 -> V_67 ;
else if ( ! V_33 . V_66 )
V_33 . V_66 = V_26 -> V_68 ;
V_36 = F_17 ( V_2 , & V_33 , V_30 ) ;
if ( F_18 ( V_36 ) )
return F_19 ( V_36 ) ;
V_38 = (struct V_37 * ) V_36 ;
V_26 = F_8 ( V_2 ) ;
if ( ! V_26 )
return - V_69 ;
if ( ! V_33 . V_66 && F_16 ( & V_33 . V_30 ) )
V_33 . V_66 = V_26 -> V_67 ;
else if ( ! V_33 . V_66 )
V_33 . V_66 = V_26 -> V_68 ;
V_40 . V_70 . type = V_28 . V_63 ;
V_40 . V_70 . V_10 = V_28 . V_65 ;
V_40 . V_70 . V_71 = 0 ;
V_40 . V_70 . V_72 . V_73 . V_74 = V_24 -> V_75 ;
V_40 . V_70 . V_72 . V_73 . V_76 = V_28 . V_77 ;
V_40 . V_4 = V_4 ;
V_40 . V_78 = 0 ;
V_40 . V_79 = V_42 ;
V_34 = F_20 ( V_26 , & V_33 , V_36 ) ;
F_21 ( V_2 ) ;
V_11 = F_22 ( V_2 , V_80 , & V_40 , V_5 ,
0 , V_34 ,
V_26 -> V_81 , NULL , & V_33 , V_38 ,
V_82 , V_26 -> V_83 ) ;
if ( V_11 ) {
F_23 ( F_24 ( V_2 ) , V_38 -> V_84 ,
V_85 ) ;
F_25 ( V_2 ) ;
} else {
V_11 = F_26 ( V_2 , & V_33 ,
(struct V_27 * ) & V_40 . V_70 ,
V_5 ) ;
}
F_27 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return V_5 ;
}
static void * F_28 ( struct V_86 * V_87 , T_5 * V_88 )
{
return F_29 ( V_87 , V_88 , V_42 ) ;
}
static int F_30 ( struct V_86 * V_87 , void * V_89 )
{
if ( V_89 == V_90 ) {
F_31 ( V_87 , V_91 ) ;
} else {
int V_92 = ( (struct V_93 * ) V_87 -> V_94 ) -> V_92 ;
struct V_23 * V_24 = F_7 ( V_89 ) ;
T_6 V_95 = F_32 ( V_24 -> V_75 ) ;
T_6 V_96 = F_32 ( V_24 -> V_97 ) ;
F_33 ( V_87 , V_89 , V_95 , V_96 , V_92 ) ;
}
return 0 ;
}
static int T_7 F_34 ( struct V_15 * V_15 )
{
return F_35 ( V_15 , & V_98 ) ;
}
static void T_7 F_36 ( struct V_15 * V_15 )
{
return F_37 ( V_15 , & V_98 ) ;
}
int T_8 F_38 ( void )
{
#ifdef F_39
int V_99 = F_40 ( & V_100 ) ;
if ( V_99 )
return V_99 ;
#endif
V_101 . V_102 = V_102 ;
V_101 . V_103 = V_103 ;
V_101 . V_104 =
V_104 ;
V_101 . V_105 = V_105 ;
V_101 . V_106 = V_106 ;
V_101 . V_107 = V_107 ;
return F_41 ( & V_108 ) ;
}
void F_42 ( void )
{
V_101 . V_102 = F_1 ;
V_101 . V_103 = F_2 ;
V_101 . V_104 = F_2 ;
V_101 . V_105 = F_3 ;
V_101 . V_106 = F_4 ;
V_101 . V_107 = F_5 ;
#ifdef F_39
F_43 ( & V_100 ) ;
#endif
F_44 ( & V_108 ) ;
}
