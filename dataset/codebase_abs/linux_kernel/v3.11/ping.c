static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
return - V_6 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 )
{
return - V_6 ;
}
static int F_3 ( T_1 type , T_1 V_9 , int * V_10 )
{
return - V_6 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_7 * V_8 , int V_10 ,
T_2 V_11 , T_3 V_12 , T_1 * V_13 ) {}
static int F_5 ( struct V_14 * V_14 , const struct V_15 * V_16 ,
const struct V_17 * V_18 , int V_19 )
{
return 0 ;
}
int F_6 ( struct V_20 * V_21 , struct V_1 * V_2 , struct V_3 * V_4 ,
T_4 V_5 )
{
struct V_22 * V_23 = F_7 ( V_2 ) ;
struct V_24 * V_25 = F_8 ( V_2 ) ;
struct V_26 V_27 ;
int V_28 ;
struct V_15 * V_29 ;
int V_30 = 0 ;
struct V_31 V_32 ;
int V_10 ;
int V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_38 V_39 ;
F_9 ( L_1 , V_23 , V_23 -> V_40 ) ;
V_10 = F_10 ( V_41 , V_4 , V_5 , & V_27 ,
sizeof( V_27 ) ) ;
if ( V_10 )
return V_10 ;
if ( V_4 -> V_42 ) {
struct V_43 * V_44 = (struct V_43 * ) V_4 -> V_42 ;
if ( V_4 -> V_45 < sizeof( struct V_43 ) ||
V_44 -> V_46 != V_41 ) {
return - V_47 ;
}
if ( V_2 -> V_48 &&
V_2 -> V_48 != V_44 -> V_49 ) {
return - V_47 ;
}
V_29 = & ( V_44 -> V_50 ) ;
V_30 = V_44 -> V_49 ;
} else {
if ( V_2 -> V_51 != V_52 )
return - V_53 ;
V_29 = & V_25 -> V_29 ;
}
if ( ! V_30 )
V_30 = V_2 -> V_48 ;
V_28 = F_11 ( V_29 ) ;
if ( F_12 ( V_28 ) && ! V_30 )
return - V_47 ;
if ( V_28 & V_54 )
return - V_47 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_55 = V_56 ;
V_32 . V_57 = V_25 -> V_57 ;
V_32 . V_29 = * V_29 ;
V_32 . V_58 = V_27 . V_59 ;
V_32 . V_60 = V_27 . V_61 ;
F_13 ( V_2 , F_14 ( & V_32 ) ) ;
if ( ! V_32 . V_62 && F_15 ( & V_32 . V_29 ) )
V_32 . V_62 = V_25 -> V_63 ;
else if ( ! V_32 . V_62 )
V_32 . V_62 = V_25 -> V_64 ;
V_35 = F_16 ( V_2 , & V_32 , V_29 , 1 ) ;
if ( F_17 ( V_35 ) )
return F_18 ( V_35 ) ;
V_37 = (struct V_36 * ) V_35 ;
V_25 = F_8 ( V_2 ) ;
if ( ! V_25 )
return - V_65 ;
if ( ! V_32 . V_62 && F_15 ( & V_32 . V_29 ) )
V_32 . V_62 = V_25 -> V_63 ;
else if ( ! V_32 . V_62 )
V_32 . V_62 = V_25 -> V_64 ;
V_39 . V_66 . type = V_27 . V_59 ;
V_39 . V_66 . V_9 = V_27 . V_61 ;
V_39 . V_66 . V_67 = 0 ;
V_39 . V_66 . V_68 . V_69 . V_70 = V_23 -> V_71 ;
V_39 . V_66 . V_68 . V_69 . V_72 = V_27 . V_73 ;
V_39 . V_74 = V_4 -> V_75 ;
V_39 . V_76 = 0 ;
V_39 . V_77 = V_41 ;
if ( F_15 ( & V_32 . V_29 ) )
V_33 = V_25 -> V_78 ;
else
V_33 = V_25 -> V_79 ;
if ( V_33 < 0 )
V_33 = F_19 ( V_35 ) ;
F_20 ( V_2 ) ;
V_10 = F_21 ( V_2 , V_80 , & V_39 , V_5 ,
0 , V_33 ,
V_25 -> V_81 , NULL , & V_32 , V_37 ,
V_82 , V_25 -> V_83 ) ;
if ( V_10 ) {
F_22 ( F_23 ( V_2 ) , V_37 -> V_84 ,
V_85 ) ;
F_24 ( V_2 ) ;
} else {
V_10 = F_25 ( V_2 , & V_32 ,
(struct V_26 * ) & V_39 . V_66 ,
V_5 ) ;
}
F_26 ( V_2 ) ;
if ( V_10 )
return V_10 ;
return V_5 ;
}
static void * F_27 ( struct V_86 * V_87 , T_5 * V_88 )
{
return F_28 ( V_87 , V_88 , V_41 ) ;
}
static int F_29 ( struct V_86 * V_87 , void * V_89 )
{
if ( V_89 == V_90 ) {
F_30 ( V_87 , V_91 ) ;
} else {
int V_92 = ( (struct V_93 * ) V_87 -> V_94 ) -> V_92 ;
struct V_22 * V_23 = F_7 ( V_89 ) ;
T_6 V_95 = F_31 ( V_23 -> V_71 ) ;
T_6 V_96 = F_31 ( V_23 -> V_97 ) ;
F_32 ( V_87 , V_89 , V_95 , V_96 , V_92 ) ;
}
return 0 ;
}
static int T_7 F_33 ( struct V_14 * V_14 )
{
return F_34 ( V_14 , & V_98 ) ;
}
static void T_7 F_35 ( struct V_14 * V_14 )
{
return F_36 ( V_14 , & V_98 ) ;
}
int T_8 F_37 ( void )
{
#ifdef F_38
int V_99 = F_39 ( & V_100 ) ;
if ( V_99 )
return V_99 ;
#endif
V_101 . V_102 = V_102 ;
V_101 . V_103 = V_103 ;
V_101 . V_104 = V_104 ;
V_101 . V_105 = V_105 ;
V_101 . V_106 = V_106 ;
return F_40 ( & V_107 ) ;
}
void F_41 ( void )
{
V_101 . V_102 = F_1 ;
V_101 . V_103 = F_2 ;
V_101 . V_104 = F_3 ;
V_101 . V_105 = F_4 ;
V_101 . V_106 = F_5 ;
#ifdef F_38
F_42 ( & V_100 ) ;
#endif
F_43 ( & V_107 ) ;
}
