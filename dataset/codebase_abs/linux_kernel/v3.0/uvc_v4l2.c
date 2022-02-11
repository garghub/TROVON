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
int V_51 ;
V_50 = F_12 ( sizeof( * V_50 ) , V_20 ) ;
if ( V_50 == NULL )
return - V_52 ;
V_51 = F_13 ( & V_50 -> V_53 , V_48 ) ;
if ( V_51 < 0 )
goto error;
V_51 = F_14 ( & V_50 -> V_53 ) ;
if ( V_51 < 0 )
goto error;
V_51 = F_15 ( & V_50 -> V_53 , 8 ) ;
if ( V_51 < 0 )
goto error;
F_16 ( & V_50 -> V_53 ) ;
V_50 -> V_54 = & V_2 -> V_22 ;
V_46 -> V_55 = & V_50 -> V_53 ;
F_17 ( V_2 ) ;
return 0 ;
error:
F_18 ( & V_50 -> V_53 ) ;
return V_51 ;
}
static int
F_19 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
struct V_49 * V_50 = F_20 ( V_46 -> V_55 ) ;
struct V_21 * V_22 = V_50 -> V_54 ;
F_21 ( V_2 ) ;
F_22 ( V_22 , 0 ) ;
F_23 ( & V_22 -> V_56 . V_57 ) ;
if ( F_24 ( & V_22 -> V_56 ) < 0 )
F_8 ( V_58 L_2
L_3 ) ;
F_25 ( & V_22 -> V_56 . V_57 ) ;
V_46 -> V_55 = NULL ;
F_26 ( & V_50 -> V_53 ) ;
F_18 ( & V_50 -> V_53 ) ;
F_27 ( V_50 ) ;
return 0 ;
}
static long
F_28 ( struct V_46 * V_46 , unsigned int V_59 , void * V_60 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
struct V_49 * V_50 = F_20 ( V_46 -> V_55 ) ;
struct V_5 * V_6 = V_2 -> V_7 . V_8 -> V_6 ;
struct V_21 * V_22 = & V_2 -> V_22 ;
int V_51 = 0 ;
switch ( V_59 ) {
case V_61 :
{
struct V_62 * V_63 = V_60 ;
memset ( V_63 , 0 , sizeof *V_63 ) ;
strncpy ( V_63 -> V_64 , L_4 , sizeof( V_63 -> V_64 ) ) ;
strncpy ( V_63 -> V_65 , V_6 -> V_13 -> V_66 , sizeof( V_63 -> V_65 ) ) ;
strncpy ( V_63 -> V_67 , F_29 ( & V_6 -> V_13 -> V_68 ) ,
sizeof V_63 -> V_67 ) ;
V_63 -> V_69 = V_70 ;
V_63 -> V_71 = V_72 | V_73 ;
break;
}
case V_74 :
{
struct V_23 * V_24 = V_60 ;
if ( V_24 -> type != V_22 -> V_56 . type )
return - V_45 ;
return F_5 ( V_22 , V_24 ) ;
}
case V_75 :
{
struct V_23 * V_24 = V_60 ;
if ( V_24 -> type != V_22 -> V_56 . type )
return - V_45 ;
return F_6 ( V_22 , V_24 ) ;
}
case V_76 :
{
struct V_77 * V_78 = V_60 ;
if ( V_78 -> type != V_22 -> V_56 . type ||
V_78 -> V_79 != V_80 )
return - V_45 ;
V_51 = F_30 ( & V_22 -> V_56 , V_78 -> V_81 ,
V_22 -> V_35 ) ;
if ( V_51 < 0 )
return V_51 ;
V_78 -> V_81 = V_51 ;
V_51 = 0 ;
break;
}
case V_82 :
{
struct V_83 * V_19 = V_60 ;
if ( V_19 -> type != V_22 -> V_56 . type )
return - V_45 ;
return F_31 ( & V_22 -> V_56 , V_19 ) ;
}
case V_84 :
if ( ( V_51 = F_32 ( & V_22 -> V_56 , V_60 ) ) < 0 )
return V_51 ;
return F_33 ( V_22 ) ;
case V_85 :
return F_34 ( & V_22 -> V_56 , V_60 ,
V_46 -> V_86 & V_87 ) ;
case V_88 :
{
int * type = V_60 ;
if ( * type != V_22 -> V_56 . type )
return - V_45 ;
return F_22 ( V_22 , 1 ) ;
}
case V_89 :
{
int * type = V_60 ;
if ( * type != V_22 -> V_56 . type )
return - V_45 ;
return F_22 ( V_22 , 0 ) ;
}
case V_90 :
{
struct V_91 * V_92 = V_60 ;
V_51 = F_35 ( & V_50 -> V_53 , V_92 ,
V_46 -> V_86 & V_87 ) ;
if ( V_51 == 0 && V_92 -> type == V_93 ) {
struct V_94 * V_94 = ( void * ) & V_92 -> V_95 . V_4 ;
V_2 -> V_96 =
! ( V_94 -> V_10 . V_97 & V_98 ) ;
V_2 -> V_15 = V_94 -> V_10 . V_99 ;
}
return V_51 ;
}
case V_100 :
{
struct V_101 * V_102 = V_60 ;
if ( V_102 -> type < V_103 || V_102 -> type > V_104 )
return - V_45 ;
return F_36 ( & V_50 -> V_53 , V_60 ) ;
}
case V_105 :
return F_37 ( & V_50 -> V_53 , V_60 ) ;
case V_106 :
V_51 = F_1 ( V_2 , V_60 ) ;
break;
default:
return - V_107 ;
}
return V_51 ;
}
static long
F_38 ( struct V_46 * V_46 , unsigned int V_59 , unsigned long V_60 )
{
return F_39 ( V_46 , V_59 , V_60 , F_28 ) ;
}
static int
F_40 ( struct V_46 * V_46 , struct V_108 * V_109 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
return F_41 ( & V_2 -> V_22 . V_56 , V_109 ) ;
}
static unsigned int
F_42 ( struct V_46 * V_46 , T_1 * V_110 )
{
struct V_47 * V_48 = F_10 ( V_46 ) ;
struct V_1 * V_2 = F_11 ( V_48 ) ;
struct V_49 * V_50 = F_20 ( V_46 -> V_55 ) ;
unsigned int V_111 = 0 ;
F_43 ( V_46 , & V_50 -> V_53 . V_112 -> V_110 , V_110 ) ;
if ( F_44 ( & V_50 -> V_53 ) )
V_111 |= V_113 ;
V_111 |= F_45 ( & V_2 -> V_22 . V_56 , V_46 , V_110 ) ;
return V_111 ;
}
