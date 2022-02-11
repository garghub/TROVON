static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , unsigned int V_5 )
{
struct V_6 V_7 ;
int V_8 = 0 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
switch ( V_4 ) {
case V_9 :
break;
case V_10 :
V_7 . type = V_11 ;
V_7 . V_12 . V_13 = V_5 ;
V_8 = V_2 -> V_14 ( V_2 , & V_7 , 0 ) ;
break;
case V_15 :
V_7 . type = V_16 ;
V_7 . V_17 . V_13 = V_5 ;
V_8 = V_2 -> V_14 ( V_2 , & V_7 , 0 ) ;
break;
case V_18 :
break;
default:
return - V_19 ;
}
return V_8 ;
}
int F_2 ( struct V_20 * V_21 , unsigned int V_22 ,
enum V_3 V_4 , unsigned int V_5 )
{
struct V_1 * V_23 = V_21 -> V_23 ;
struct V_24 * V_25 = NULL , * V_26 = & V_23 -> V_27 [ V_22 ] ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_23 -> V_29 ; V_28 ++ ) {
if ( V_23 -> V_27 [ V_28 ] . V_4 == V_4 &&
V_23 -> V_27 [ V_28 ] . V_5 == V_5 ) {
V_25 = & V_23 -> V_27 [ V_28 ] ;
break;
}
}
if ( V_25 && V_28 == V_22 )
return 0 ;
switch ( V_4 ) {
case V_9 :
break;
case V_10 :
if ( V_5 >= V_23 -> V_30 )
return - V_19 ;
break;
case V_15 :
if ( V_5 >= V_23 -> V_31 )
return - V_19 ;
break;
case V_18 :
if ( V_5 != 0 )
return - V_19 ;
default:
return - V_19 ;
}
if ( V_23 -> V_32 ( V_23 , V_22 , V_4 , V_5 ) ) {
F_3 ( L_1 , V_4 , V_5 ) ;
return - V_33 ;
}
if ( V_25 ) {
F_1 ( V_23 , V_4 , V_5 ) ;
V_25 -> V_4 = V_9 ;
V_25 -> V_5 = 0 ;
}
F_1 ( V_23 , V_26 -> V_4 , V_26 -> V_5 ) ;
V_26 -> V_4 = V_4 ;
V_26 -> V_5 = V_5 ;
return 0 ;
}
int F_4 ( struct V_34 * V_35 , T_1 V_36 )
{
return 0 ;
}
long F_5 ( struct V_34 * V_35 , unsigned int V_37 , unsigned long V_38 )
{
struct V_39 V_40 ;
struct V_6 V_41 ;
struct V_42 * V_43 = NULL ;
struct V_44 V_45 ;
struct V_24 V_46 ;
struct V_20 * V_21 = F_6 ( V_35 , struct V_20 , clock ) ;
struct V_1 * V_2 = V_21 -> V_23 ;
struct V_47 * V_48 ;
struct V_49 V_50 ;
struct V_51 V_52 ;
int V_14 , V_8 = 0 ;
unsigned int V_28 , V_53 ;
switch ( V_37 ) {
case V_54 :
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_55 = V_21 -> V_23 -> V_55 ;
V_40 . V_56 = V_21 -> V_23 -> V_56 ;
V_40 . V_30 = V_21 -> V_23 -> V_30 ;
V_40 . V_31 = V_21 -> V_23 -> V_31 ;
V_40 . V_57 = V_21 -> V_23 -> V_57 ;
V_40 . V_29 = V_21 -> V_23 -> V_29 ;
V_40 . V_58 = V_21 -> V_23 -> V_59 != NULL ;
if ( F_7 ( ( void V_60 * ) V_38 , & V_40 , sizeof( V_40 ) ) )
V_8 = - V_61 ;
break;
case V_62 :
if ( F_8 ( & V_41 . V_12 , ( void V_60 * ) V_38 ,
sizeof( V_41 . V_12 ) ) ) {
V_8 = - V_61 ;
break;
}
if ( V_41 . V_12 . V_13 >= V_2 -> V_30 ) {
V_8 = - V_19 ;
break;
}
V_41 . type = V_11 ;
V_14 = V_41 . V_12 . V_63 & V_64 ? 1 : 0 ;
V_8 = V_2 -> V_14 ( V_2 , & V_41 , V_14 ) ;
break;
case V_65 :
if ( F_8 ( & V_41 . V_17 , ( void V_60 * ) V_38 ,
sizeof( V_41 . V_17 ) ) ) {
V_8 = - V_61 ;
break;
}
if ( V_41 . V_17 . V_13 >= V_2 -> V_31 ) {
V_8 = - V_19 ;
break;
}
V_41 . type = V_16 ;
V_14 = V_41 . V_17 . V_66 . V_67 || V_41 . V_17 . V_66 . V_68 ;
V_8 = V_2 -> V_14 ( V_2 , & V_41 , V_14 ) ;
break;
case V_69 :
if ( ! F_9 ( V_70 ) )
return - V_71 ;
V_41 . type = V_72 ;
V_14 = V_38 ? 1 : 0 ;
V_8 = V_2 -> V_14 ( V_2 , & V_41 , V_14 ) ;
break;
case V_73 :
if ( ! V_21 -> V_23 -> V_59 ) {
V_8 = - V_33 ;
break;
}
V_8 = V_21 -> V_23 -> V_59 ( V_21 -> V_23 , & V_52 ) ;
if ( V_8 )
break;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_50 = F_10 ( V_52 . V_74 ) ;
V_45 . V_74 . V_67 = V_50 . V_75 ;
V_45 . V_74 . V_68 = V_50 . V_76 ;
V_50 = F_10 ( V_52 . V_77 ) ;
V_45 . V_77 . V_67 = V_50 . V_75 ;
V_45 . V_77 . V_68 = V_50 . V_76 ;
V_50 = F_10 ( V_52 . V_78 ) ;
V_45 . V_78 . V_67 = V_50 . V_75 ;
V_45 . V_78 . V_68 = V_50 . V_76 ;
if ( F_7 ( ( void V_60 * ) V_38 , & V_45 ,
sizeof( V_45 ) ) )
V_8 = - V_61 ;
break;
case V_79 :
V_43 = F_11 ( ( void V_60 * ) V_38 , sizeof( * V_43 ) ) ;
if ( F_12 ( V_43 ) ) {
V_8 = F_13 ( V_43 ) ;
V_43 = NULL ;
break;
}
if ( V_43 -> V_80 > V_81 ) {
V_8 = - V_19 ;
break;
}
V_48 = & V_43 -> V_50 [ 0 ] ;
for ( V_28 = 0 ; V_28 < V_43 -> V_80 ; V_28 ++ ) {
F_14 ( & V_50 ) ;
V_48 -> V_67 = V_50 . V_75 ;
V_48 -> V_68 = V_50 . V_76 ;
V_48 ++ ;
V_21 -> V_23 -> V_82 ( V_21 -> V_23 , & V_50 ) ;
V_48 -> V_67 = V_50 . V_75 ;
V_48 -> V_68 = V_50 . V_76 ;
V_48 ++ ;
}
F_14 ( & V_50 ) ;
V_48 -> V_67 = V_50 . V_75 ;
V_48 -> V_68 = V_50 . V_76 ;
if ( F_7 ( ( void V_60 * ) V_38 , V_43 , sizeof( * V_43 ) ) )
V_8 = - V_61 ;
break;
case V_83 :
if ( F_8 ( & V_46 , ( void V_60 * ) V_38 , sizeof( V_46 ) ) ) {
V_8 = - V_61 ;
break;
}
V_53 = V_46 . V_13 ;
if ( V_53 >= V_2 -> V_29 ) {
V_8 = - V_19 ;
break;
}
if ( F_15 ( & V_21 -> V_84 ) )
return - V_85 ;
V_46 = V_2 -> V_27 [ V_53 ] ;
F_16 ( & V_21 -> V_84 ) ;
if ( ! V_8 && F_7 ( ( void V_60 * ) V_38 , & V_46 , sizeof( V_46 ) ) )
V_8 = - V_61 ;
break;
case V_86 :
if ( F_8 ( & V_46 , ( void V_60 * ) V_38 , sizeof( V_46 ) ) ) {
V_8 = - V_61 ;
break;
}
V_53 = V_46 . V_13 ;
if ( V_53 >= V_2 -> V_29 ) {
V_8 = - V_19 ;
break;
}
if ( F_15 ( & V_21 -> V_84 ) )
return - V_85 ;
V_8 = F_2 ( V_21 , V_53 , V_46 . V_4 , V_46 . V_5 ) ;
F_16 ( & V_21 -> V_84 ) ;
break;
default:
V_8 = - V_87 ;
break;
}
F_17 ( V_43 ) ;
return V_8 ;
}
unsigned int F_18 ( struct V_34 * V_35 , struct V_88 * V_89 , T_2 * V_90 )
{
struct V_20 * V_21 = F_6 ( V_35 , struct V_20 , clock ) ;
F_19 ( V_89 , & V_21 -> V_91 , V_90 ) ;
return F_20 ( & V_21 -> V_92 ) ? V_93 : 0 ;
}
T_3 F_21 ( struct V_34 * V_35 ,
T_4 V_94 , char V_60 * V_95 , T_5 V_96 )
{
struct V_20 * V_21 = F_6 ( V_35 , struct V_20 , clock ) ;
struct V_97 * V_98 = & V_21 -> V_92 ;
struct V_99 * V_100 ;
unsigned long V_63 ;
T_5 V_101 , V_28 ;
int V_102 ;
if ( V_96 % sizeof( struct V_99 ) != 0 )
return - V_19 ;
if ( V_96 > V_103 )
V_96 = V_103 ;
V_96 = V_96 / sizeof( struct V_99 ) ;
if ( F_15 ( & V_21 -> V_104 ) )
return - V_85 ;
if ( F_22 ( V_21 -> V_91 ,
V_21 -> V_105 || F_20 ( V_98 ) ) ) {
F_16 ( & V_21 -> V_104 ) ;
return - V_85 ;
}
if ( V_21 -> V_105 ) {
F_16 ( & V_21 -> V_104 ) ;
return - V_106 ;
}
V_100 = F_23 ( V_103 , V_107 ) ;
if ( ! V_100 ) {
F_16 ( & V_21 -> V_104 ) ;
return - V_108 ;
}
F_24 ( & V_98 -> V_109 , V_63 ) ;
V_101 = F_20 ( V_98 ) ;
if ( V_96 > V_101 )
V_96 = V_101 ;
for ( V_28 = 0 ; V_28 < V_96 ; V_28 ++ ) {
V_100 [ V_28 ] = V_98 -> V_95 [ V_98 -> V_110 ] ;
V_98 -> V_110 = ( V_98 -> V_110 + 1 ) % V_111 ;
}
F_25 ( & V_98 -> V_109 , V_63 ) ;
V_96 = V_96 * sizeof( struct V_99 ) ;
F_16 ( & V_21 -> V_104 ) ;
V_102 = V_96 ;
if ( F_7 ( V_95 , V_100 , V_96 ) )
V_102 = - V_61 ;
F_17 ( V_100 ) ;
return V_102 ;
}
