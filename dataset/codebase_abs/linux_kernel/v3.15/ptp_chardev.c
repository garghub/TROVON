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
F_3 ( L_1 ) ;
return - V_19 ;
default:
return - V_19 ;
}
if ( V_26 -> V_4 == V_18 ) {
F_3 ( L_2 ) ;
return - V_19 ;
}
if ( V_23 -> V_32 ( V_23 , V_22 , V_4 , V_5 ) ) {
F_3 ( L_3 , V_4 , V_5 ) ;
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
struct V_24 V_44 ;
struct V_20 * V_21 = F_6 ( V_35 , struct V_20 , clock ) ;
struct V_1 * V_2 = V_21 -> V_23 ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
int V_14 , V_8 = 0 ;
unsigned int V_28 , V_49 ;
switch ( V_37 ) {
case V_50 :
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_51 = V_21 -> V_23 -> V_51 ;
V_40 . V_52 = V_21 -> V_23 -> V_52 ;
V_40 . V_30 = V_21 -> V_23 -> V_30 ;
V_40 . V_31 = V_21 -> V_23 -> V_31 ;
V_40 . V_53 = V_21 -> V_23 -> V_53 ;
V_40 . V_29 = V_21 -> V_23 -> V_29 ;
if ( F_7 ( ( void V_54 * ) V_38 , & V_40 , sizeof( V_40 ) ) )
V_8 = - V_55 ;
break;
case V_56 :
if ( F_8 ( & V_41 . V_12 , ( void V_54 * ) V_38 ,
sizeof( V_41 . V_12 ) ) ) {
V_8 = - V_55 ;
break;
}
if ( V_41 . V_12 . V_13 >= V_2 -> V_30 ) {
V_8 = - V_19 ;
break;
}
V_41 . type = V_11 ;
V_14 = V_41 . V_12 . V_57 & V_58 ? 1 : 0 ;
V_8 = V_2 -> V_14 ( V_2 , & V_41 , V_14 ) ;
break;
case V_59 :
if ( F_8 ( & V_41 . V_17 , ( void V_54 * ) V_38 ,
sizeof( V_41 . V_17 ) ) ) {
V_8 = - V_55 ;
break;
}
if ( V_41 . V_17 . V_13 >= V_2 -> V_31 ) {
V_8 = - V_19 ;
break;
}
V_41 . type = V_16 ;
V_14 = V_41 . V_17 . V_60 . V_61 || V_41 . V_17 . V_60 . V_62 ;
V_8 = V_2 -> V_14 ( V_2 , & V_41 , V_14 ) ;
break;
case V_63 :
if ( ! F_9 ( V_64 ) )
return - V_65 ;
V_41 . type = V_66 ;
V_14 = V_38 ? 1 : 0 ;
V_8 = V_2 -> V_14 ( V_2 , & V_41 , V_14 ) ;
break;
case V_67 :
V_43 = F_10 ( sizeof( * V_43 ) , V_68 ) ;
if ( ! V_43 ) {
V_8 = - V_69 ;
break;
}
if ( F_8 ( V_43 , ( void V_54 * ) V_38 ,
sizeof( * V_43 ) ) ) {
V_8 = - V_55 ;
break;
}
if ( V_43 -> V_70 > V_71 ) {
V_8 = - V_19 ;
break;
}
V_46 = & V_43 -> V_48 [ 0 ] ;
for ( V_28 = 0 ; V_28 < V_43 -> V_70 ; V_28 ++ ) {
F_11 ( & V_48 ) ;
V_46 -> V_61 = V_48 . V_72 ;
V_46 -> V_62 = V_48 . V_73 ;
V_46 ++ ;
V_21 -> V_23 -> V_74 ( V_21 -> V_23 , & V_48 ) ;
V_46 -> V_61 = V_48 . V_72 ;
V_46 -> V_62 = V_48 . V_73 ;
V_46 ++ ;
}
F_11 ( & V_48 ) ;
V_46 -> V_61 = V_48 . V_72 ;
V_46 -> V_62 = V_48 . V_73 ;
if ( F_7 ( ( void V_54 * ) V_38 , V_43 , sizeof( * V_43 ) ) )
V_8 = - V_55 ;
break;
case V_75 :
if ( F_8 ( & V_44 , ( void V_54 * ) V_38 , sizeof( V_44 ) ) ) {
V_8 = - V_55 ;
break;
}
V_49 = V_44 . V_13 ;
if ( V_49 >= V_2 -> V_29 ) {
V_8 = - V_19 ;
break;
}
if ( F_12 ( & V_21 -> V_76 ) )
return - V_77 ;
V_44 = V_2 -> V_27 [ V_49 ] ;
F_13 ( & V_21 -> V_76 ) ;
if ( ! V_8 && F_7 ( ( void V_54 * ) V_38 , & V_44 , sizeof( V_44 ) ) )
V_8 = - V_55 ;
break;
case V_78 :
if ( F_8 ( & V_44 , ( void V_54 * ) V_38 , sizeof( V_44 ) ) ) {
V_8 = - V_55 ;
break;
}
V_49 = V_44 . V_13 ;
if ( V_49 >= V_2 -> V_29 ) {
V_8 = - V_19 ;
break;
}
if ( F_12 ( & V_21 -> V_76 ) )
return - V_77 ;
V_8 = F_2 ( V_21 , V_49 , V_44 . V_4 , V_44 . V_5 ) ;
F_13 ( & V_21 -> V_76 ) ;
break;
default:
V_8 = - V_79 ;
break;
}
F_14 ( V_43 ) ;
return V_8 ;
}
unsigned int F_15 ( struct V_34 * V_35 , struct V_80 * V_81 , T_2 * V_82 )
{
struct V_20 * V_21 = F_6 ( V_35 , struct V_20 , clock ) ;
F_16 ( V_81 , & V_21 -> V_83 , V_82 ) ;
return F_17 ( & V_21 -> V_84 ) ? V_85 : 0 ;
}
T_3 F_18 ( struct V_34 * V_35 ,
T_4 V_86 , char V_54 * V_87 , T_5 V_88 )
{
struct V_20 * V_21 = F_6 ( V_35 , struct V_20 , clock ) ;
struct V_89 * V_90 = & V_21 -> V_84 ;
struct V_91 * V_92 ;
unsigned long V_57 ;
T_5 V_93 , V_28 ;
int V_94 ;
if ( V_88 % sizeof( struct V_91 ) != 0 )
return - V_19 ;
if ( V_88 > V_95 )
V_88 = V_95 ;
V_88 = V_88 / sizeof( struct V_91 ) ;
if ( F_12 ( & V_21 -> V_96 ) )
return - V_77 ;
if ( F_19 ( V_21 -> V_83 ,
V_21 -> V_97 || F_17 ( V_90 ) ) ) {
F_13 ( & V_21 -> V_96 ) ;
return - V_77 ;
}
if ( V_21 -> V_97 ) {
F_13 ( & V_21 -> V_96 ) ;
return - V_98 ;
}
V_92 = F_10 ( V_95 , V_68 ) ;
if ( ! V_92 ) {
F_13 ( & V_21 -> V_96 ) ;
return - V_69 ;
}
F_20 ( & V_90 -> V_99 , V_57 ) ;
V_93 = F_17 ( V_90 ) ;
if ( V_88 > V_93 )
V_88 = V_93 ;
for ( V_28 = 0 ; V_28 < V_88 ; V_28 ++ ) {
V_92 [ V_28 ] = V_90 -> V_87 [ V_90 -> V_100 ] ;
V_90 -> V_100 = ( V_90 -> V_100 + 1 ) % V_101 ;
}
F_21 ( & V_90 -> V_99 , V_57 ) ;
V_88 = V_88 * sizeof( struct V_91 ) ;
F_13 ( & V_21 -> V_96 ) ;
V_94 = V_88 ;
if ( F_7 ( V_87 , V_92 , V_88 ) )
V_94 = - V_55 ;
F_14 ( V_92 ) ;
return V_94 ;
}
