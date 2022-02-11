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
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , T_4 V_5 )
{
struct V_21 * V_22 = F_7 ( V_2 ) ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_25 V_26 ;
int V_27 ;
struct V_16 * V_28 ;
int V_29 = 0 ;
struct V_30 V_31 ;
int V_11 ;
int V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 V_38 ;
F_9 ( L_1 , V_22 , V_22 -> V_39 ) ;
V_11 = F_10 ( V_40 , V_4 , V_5 , & V_26 ,
sizeof( V_26 ) ) ;
if ( V_11 )
return V_11 ;
if ( V_4 -> V_41 ) {
F_11 ( struct V_42 * , V_43 , V_4 -> V_41 ) ;
if ( V_4 -> V_44 < sizeof( * V_43 ) )
return - V_45 ;
if ( V_43 -> V_46 != V_40 ) {
return - V_7 ;
}
if ( V_2 -> V_47 &&
V_2 -> V_47 != V_43 -> V_48 ) {
return - V_45 ;
}
V_28 = & ( V_43 -> V_49 ) ;
V_29 = V_43 -> V_48 ;
} else {
if ( V_2 -> V_50 != V_51 )
return - V_52 ;
V_28 = & V_2 -> V_53 ;
}
if ( ! V_29 )
V_29 = V_2 -> V_47 ;
V_27 = F_12 ( V_28 ) ;
if ( F_13 ( V_27 ) && ! V_29 )
return - V_45 ;
if ( V_27 & V_54 )
return - V_45 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_55 = V_56 ;
V_31 . V_57 = V_24 -> V_57 ;
V_31 . V_28 = * V_28 ;
V_31 . V_58 = V_2 -> V_59 ;
V_31 . V_60 = V_26 . V_61 ;
V_31 . V_62 = V_26 . V_63 ;
F_14 ( V_2 , F_15 ( & V_31 ) ) ;
if ( ! V_31 . V_64 && F_16 ( & V_31 . V_28 ) )
V_31 . V_64 = V_24 -> V_65 ;
else if ( ! V_31 . V_64 )
V_31 . V_64 = V_24 -> V_66 ;
V_34 = F_17 ( V_2 , & V_31 , V_28 ) ;
if ( F_18 ( V_34 ) )
return F_19 ( V_34 ) ;
V_36 = (struct V_35 * ) V_34 ;
V_24 = F_8 ( V_2 ) ;
if ( ! V_24 )
return - V_67 ;
if ( ! V_31 . V_64 && F_16 ( & V_31 . V_28 ) )
V_31 . V_64 = V_24 -> V_65 ;
else if ( ! V_31 . V_64 )
V_31 . V_64 = V_24 -> V_66 ;
V_38 . V_68 . type = V_26 . V_61 ;
V_38 . V_68 . V_10 = V_26 . V_63 ;
V_38 . V_68 . V_69 = 0 ;
V_38 . V_68 . V_70 . V_71 . V_72 = V_22 -> V_73 ;
V_38 . V_68 . V_70 . V_71 . V_74 = V_26 . V_75 ;
V_38 . V_4 = V_4 ;
V_38 . V_76 = 0 ;
V_38 . V_77 = V_40 ;
V_32 = F_20 ( V_24 , & V_31 , V_34 ) ;
F_21 ( V_2 ) ;
V_11 = F_22 ( V_2 , V_78 , & V_38 , V_5 ,
0 , V_32 ,
V_24 -> V_79 , NULL , & V_31 , V_36 ,
V_80 , V_24 -> V_81 ) ;
if ( V_11 ) {
F_23 ( F_24 ( V_2 ) , V_36 -> V_82 ,
V_83 ) ;
F_25 ( V_2 ) ;
} else {
V_11 = F_26 ( V_2 , & V_31 ,
(struct V_25 * ) & V_38 . V_68 ,
V_5 ) ;
}
F_27 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return V_5 ;
}
static void * F_28 ( struct V_84 * V_85 , T_5 * V_86 )
{
return F_29 ( V_85 , V_86 , V_40 ) ;
}
static int F_30 ( struct V_84 * V_85 , void * V_87 )
{
if ( V_87 == V_88 ) {
F_31 ( V_85 , V_89 ) ;
} else {
int V_90 = ( (struct V_91 * ) V_85 -> V_92 ) -> V_90 ;
struct V_21 * V_22 = F_7 ( V_87 ) ;
T_6 V_93 = F_32 ( V_22 -> V_73 ) ;
T_6 V_94 = F_32 ( V_22 -> V_95 ) ;
F_33 ( V_85 , V_87 , V_93 , V_94 , V_90 ) ;
}
return 0 ;
}
static int T_7 F_34 ( struct V_15 * V_15 )
{
return F_35 ( V_15 , & V_96 ) ;
}
static void T_7 F_36 ( struct V_15 * V_15 )
{
return F_37 ( V_15 , & V_96 ) ;
}
int T_8 F_38 ( void )
{
#ifdef F_39
int V_97 = F_40 ( & V_98 ) ;
if ( V_97 )
return V_97 ;
#endif
V_99 . V_100 = V_100 ;
V_99 . V_101 = V_101 ;
V_99 . V_102 =
V_102 ;
V_99 . V_103 = V_103 ;
V_99 . V_104 = V_104 ;
V_99 . V_105 = V_105 ;
return F_41 ( & V_106 ) ;
}
void F_42 ( void )
{
V_99 . V_100 = F_1 ;
V_99 . V_101 = F_2 ;
V_99 . V_102 = F_2 ;
V_99 . V_103 = F_3 ;
V_99 . V_104 = F_4 ;
V_99 . V_105 = F_5 ;
#ifdef F_39
F_43 ( & V_98 ) ;
#endif
F_44 ( & V_106 ) ;
}
