static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_8 -> V_6 ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_4 -> V_12 < 0 )
return F_2 ( V_6 -> V_13 -> V_14 ) ;
V_10 -> V_12 = F_3 ( V_2 -> V_15 , V_4 -> V_12 ) ;
V_10 -> V_16 = V_4 -> V_12 < V_2 -> V_15 ;
V_10 -> V_17 = V_18 ;
memcpy ( V_10 -> V_19 , V_4 -> V_4 , V_4 -> V_12 ) ;
return F_4 ( V_6 -> V_13 -> V_14 , V_10 , V_20 ) ;
}
static int
F_5 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
V_24 -> V_24 . V_25 . V_26 = V_22 -> V_27 ;
V_24 -> V_24 . V_25 . V_28 = V_22 -> V_28 ;
V_24 -> V_24 . V_25 . V_29 = V_22 -> V_29 ;
V_24 -> V_24 . V_25 . V_30 = V_31 ;
V_24 -> V_24 . V_25 . V_32 = V_22 -> V_33 * V_22 -> V_28 / 8 ;
V_24 -> V_24 . V_25 . V_34 = V_22 -> V_35 ;
V_24 -> V_24 . V_25 . V_36 = V_37 ;
V_24 -> V_24 . V_25 . V_38 = 0 ;
return 0 ;
}
static int
F_6 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_39 * V_40 ;
unsigned int V_35 ;
unsigned int V_41 ;
unsigned int V_42 ;
for ( V_42 = 0 ; V_42 < F_7 ( V_43 ) ; ++ V_42 ) {
V_40 = & V_43 [ V_42 ] ;
if ( V_40 -> V_27 == V_24 -> V_24 . V_25 . V_26 )
break;
}
if ( V_42 == F_7 ( V_43 ) ) {
F_8 ( V_44 L_1 ,
V_24 -> V_24 . V_25 . V_26 ) ;
return - V_45 ;
}
V_41 = V_40 -> V_33 * V_24 -> V_24 . V_25 . V_28 / 8 ;
V_35 = V_41 ? V_41 * V_24 -> V_24 . V_25 . V_29 : V_24 -> V_24 . V_25 . V_34 ;
V_22 -> V_27 = V_40 -> V_27 ;
V_22 -> V_33 = V_40 -> V_33 ;
V_22 -> V_28 = V_24 -> V_24 . V_25 . V_28 ;
V_22 -> V_29 = V_24 -> V_24 . V_25 . V_29 ;
V_22 -> V_35 = V_35 ;
V_24 -> V_24 . V_25 . V_30 = V_31 ;
V_24 -> V_24 . V_25 . V_32 = V_41 ;
V_24 -> V_24 . V_25 . V_34 = V_35 ;
V_24 -> V_24 . V_25 . V_36 = V_37 ;
V_24 -> V_24 . V_25 . V_38 = 0 ;
return 0 ;
}
static int
F_9 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
struct V_49 * V_50 ;
V_50 = F_12 ( sizeof( * V_50 ) , V_20 ) ;
if ( V_50 == NULL )
return - V_51 ;
F_13 ( & V_50 -> V_52 , V_48 ) ;
F_14 ( & V_50 -> V_52 ) ;
V_50 -> V_53 = & V_2 -> V_22 ;
V_46 -> V_54 = & V_50 -> V_52 ;
F_15 ( V_2 ) ;
return 0 ;
}
static int
F_16 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
struct V_49 * V_50 = F_17 ( V_46 -> V_54 ) ;
struct V_21 * V_22 = V_50 -> V_53 ;
F_18 ( V_2 ) ;
F_19 ( V_22 , 0 ) ;
F_20 ( & V_22 -> V_55 . V_56 ) ;
if ( F_21 ( & V_22 -> V_55 ) < 0 )
F_8 ( V_57 L_2
L_3 ) ;
F_22 ( & V_22 -> V_55 . V_56 ) ;
V_46 -> V_54 = NULL ;
F_23 ( & V_50 -> V_52 ) ;
F_24 ( & V_50 -> V_52 ) ;
F_25 ( V_50 ) ;
return 0 ;
}
static long
F_26 ( struct V_46 * V_46 , unsigned int V_58 , void * V_59 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
struct V_49 * V_50 = F_17 ( V_46 -> V_54 ) ;
struct V_5 * V_6 = V_2 -> V_7 . V_8 -> V_6 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
int V_60 = 0 ;
switch ( V_58 ) {
case V_61 :
{
struct V_62 * V_63 = V_59 ;
memset ( V_63 , 0 , sizeof *V_63 ) ;
strncpy ( V_63 -> V_64 , L_4 , sizeof( V_63 -> V_64 ) ) ;
strncpy ( V_63 -> V_65 , V_6 -> V_13 -> V_66 , sizeof( V_63 -> V_65 ) ) ;
strncpy ( V_63 -> V_67 , F_27 ( & V_6 -> V_13 -> V_68 ) ,
sizeof V_63 -> V_67 ) ;
V_63 -> V_69 = V_70 ;
V_63 -> V_71 = V_72 | V_73 ;
break;
}
case V_74 :
{
struct V_23 * V_24 = V_59 ;
if ( V_24 -> type != V_22 -> V_55 . type )
return - V_45 ;
return F_5 ( V_22 , V_24 ) ;
}
case V_75 :
{
struct V_23 * V_24 = V_59 ;
if ( V_24 -> type != V_22 -> V_55 . type )
return - V_45 ;
return F_6 ( V_22 , V_24 ) ;
}
case V_76 :
{
struct V_77 * V_78 = V_59 ;
if ( V_78 -> type != V_22 -> V_55 . type ||
V_78 -> V_79 != V_80 )
return - V_45 ;
V_60 = F_28 ( & V_22 -> V_55 , V_78 -> V_81 ,
V_22 -> V_35 ) ;
if ( V_60 < 0 )
return V_60 ;
V_78 -> V_81 = V_60 ;
V_60 = 0 ;
break;
}
case V_82 :
{
struct V_83 * V_19 = V_59 ;
if ( V_19 -> type != V_22 -> V_55 . type )
return - V_45 ;
return F_29 ( & V_22 -> V_55 , V_19 ) ;
}
case V_84 :
if ( ( V_60 = F_30 ( & V_22 -> V_55 , V_59 ) ) < 0 )
return V_60 ;
return F_31 ( V_22 ) ;
case V_85 :
return F_32 ( & V_22 -> V_55 , V_59 ,
V_46 -> V_86 & V_87 ) ;
case V_88 :
{
int * type = V_59 ;
if ( * type != V_22 -> V_55 . type )
return - V_45 ;
return F_19 ( V_22 , 1 ) ;
}
case V_89 :
{
int * type = V_59 ;
if ( * type != V_22 -> V_55 . type )
return - V_45 ;
return F_19 ( V_22 , 0 ) ;
}
case V_90 :
{
struct V_91 * V_92 = V_59 ;
V_60 = F_33 ( & V_50 -> V_52 , V_92 ,
V_46 -> V_86 & V_87 ) ;
if ( V_60 == 0 && V_92 -> type == V_93 ) {
struct V_94 * V_94 = ( void * ) & V_92 -> V_95 . V_4 ;
V_2 -> V_96 =
! ( V_94 -> V_10 . V_97 & V_98 ) ;
V_2 -> V_15 = V_94 -> V_10 . V_99 ;
}
return V_60 ;
}
case V_100 :
{
struct V_101 * V_102 = V_59 ;
if ( V_102 -> type < V_103 || V_102 -> type > V_104 )
return - V_45 ;
return F_34 ( & V_50 -> V_52 , V_59 , 2 ) ;
}
case V_105 :
return F_35 ( & V_50 -> V_52 , V_59 ) ;
case V_106 :
V_60 = F_1 ( V_2 , V_59 ) ;
break;
default:
return - V_107 ;
}
return V_60 ;
}
static long
F_36 ( struct V_46 * V_46 , unsigned int V_58 , unsigned long V_59 )
{
return F_37 ( V_46 , V_58 , V_59 , F_26 ) ;
}
static int
F_38 ( struct V_46 * V_46 , struct V_108 * V_109 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
return F_39 ( & V_2 -> V_22 . V_55 , V_109 ) ;
}
static unsigned int
F_40 ( struct V_46 * V_46 , T_1 * V_110 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
struct V_49 * V_50 = F_17 ( V_46 -> V_54 ) ;
unsigned int V_111 = 0 ;
F_41 ( V_46 , & V_50 -> V_52 . V_110 , V_110 ) ;
if ( F_42 ( & V_50 -> V_52 ) )
V_111 |= V_112 ;
V_111 |= F_43 ( & V_2 -> V_22 . V_55 , V_46 , V_110 ) ;
return V_111 ;
}
