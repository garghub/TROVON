void F_1 ( const char * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
V_5 = (struct V_4 * ) V_3 -> V_7 ;
F_2 ( V_8 L_1 ,
V_1 , V_3 -> V_9 , V_10 ) ;
if ( V_3 -> V_9 < 2 )
return;
V_6 = F_3 ( V_5 -> V_11 ) ;
F_2 ( V_8 L_2 ,
V_6 , ( V_6 & V_12 ) >> 2 ,
( V_6 & V_13 ) >> 4 ,
V_6 & V_14 ? L_3 : L_4 ,
V_6 & V_15 ? L_5 : L_4 ) ;
if ( V_3 -> V_9 < V_16 ) {
F_2 ( L_6 ) ;
return;
}
F_2 ( L_7 , F_3 ( V_5 -> V_17 ) ,
F_3 ( V_5 -> V_18 ) ) ;
F_2 ( V_8 L_8 , V_5 -> V_19 ) ;
F_2 ( L_9 , V_5 -> V_20 ) ;
F_2 ( L_10 , V_5 -> V_21 ) ;
if ( V_3 -> V_9 >= 30 )
F_2 ( L_11 , V_5 -> V_22 ) ;
F_2 ( L_6 ) ;
}
T_2 F_4 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 ;
T_3 * V_27 ;
int V_28 , V_29 = 0 ;
struct V_4 V_5 ;
T_1 V_6 , V_30 = 0 ;
enum {
V_31 = 0 , V_32 , V_33
} V_34 = V_31 ;
T_4 * V_35 ;
int V_36 , V_37 , V_38 ;
int V_39 = 0 ;
struct V_40 * V_41 ;
V_26 = F_5 ( V_24 ) ;
V_27 = V_26 -> V_27 ;
if ( V_3 -> V_9 < V_42 ) {
F_2 ( V_8 L_12
L_13 , V_24 -> V_1 , V_3 -> V_9 ) ;
F_6 ( V_3 ) ;
return V_43 ;
}
if ( V_27 -> V_44 != V_24 ) {
V_34 = ( V_27 -> V_45 == V_46 &&
! ( V_27 -> V_47 & V_48 ) ) ?
V_32 : V_33 ;
if ( V_24 == V_27 -> V_49 ) {
V_39 = 1 ;
V_34 = V_31 ;
} else if ( V_24 == V_27 -> V_50 ) {
F_2 ( V_8 L_14
L_15 , V_24 -> V_1 ) ;
F_6 ( V_3 ) ;
return V_43 ;
}
} else {
if ( V_27 -> V_45 == V_51 ) {
F_2 ( V_8 L_14
L_16 , V_24 -> V_1 ) ;
F_6 ( V_3 ) ;
return V_43 ;
} else if ( V_27 -> V_45 == V_52 &&
( V_27 -> V_47 & V_53 ) &&
! F_7 ( V_3 -> V_7 + V_54 , V_24 -> V_55 ) ) {
V_34 = V_33 ;
}
}
V_30 = ( V_3 -> V_7 [ 12 ] << 8 ) | V_3 -> V_7 [ 13 ] ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_35 = NULL ;
V_37 = 0 ;
V_38 = V_42 ;
if ( V_30 == V_56 || V_30 == V_57 ) {
V_35 = V_58 ;
V_37 = sizeof( V_58 ) ;
V_38 -= 2 ;
} else if ( V_30 >= 0x600 ) {
V_35 = V_59 ;
V_37 = sizeof( V_59 ) ;
V_38 -= 2 ;
}
V_6 = V_60 | V_61 ;
V_36 = V_16 ;
if ( V_34 != V_31 ) {
if ( V_34 == V_33 ) {
V_6 |= V_15 | V_14 ;
F_8 ( V_3 , V_54 ,
& V_5 . V_22 , V_54 ) ;
V_36 += V_54 ;
} else {
V_6 |= V_14 ;
F_8 ( V_3 , V_54 ,
& V_5 . V_22 , V_54 ) ;
V_29 += V_54 ;
}
if ( ( V_27 -> V_47 & V_62 ) &&
F_9 ( V_3 -> V_7 ) )
F_10 ( V_5 . V_19 ) ;
else if ( V_26 -> type == V_63 )
memcpy ( & V_5 . V_19 , V_26 -> V_64 . V_65 . V_66 ,
V_54 ) ;
else
memcpy ( & V_5 . V_19 , V_27 -> V_67 , V_54 ) ;
memcpy ( & V_5 . V_20 , V_24 -> V_55 , V_54 ) ;
F_11 ( V_3 , & V_5 . V_21 , V_54 ) ;
} else if ( V_27 -> V_45 == V_46 && ! V_39 ) {
V_6 |= V_15 ;
F_11 ( V_3 , & V_5 . V_19 , V_54 ) ;
memcpy ( & V_5 . V_20 , V_24 -> V_55 , V_54 ) ;
F_8 ( V_3 , V_54 , & V_5 . V_21 ,
V_54 ) ;
} else if ( V_27 -> V_45 == V_52 || V_39 ) {
V_6 |= V_14 ;
memcpy ( & V_5 . V_19 , V_39 ?
V_27 -> V_68 : V_27 -> V_67 , V_54 ) ;
F_8 ( V_3 , V_54 , & V_5 . V_20 ,
V_54 ) ;
F_11 ( V_3 , & V_5 . V_21 , V_54 ) ;
} else if ( V_27 -> V_45 == V_69 ) {
F_11 ( V_3 , & V_5 . V_19 , V_54 ) ;
F_8 ( V_3 , V_54 , & V_5 . V_20 ,
V_54 ) ;
memcpy ( & V_5 . V_21 , V_27 -> V_67 , V_54 ) ;
}
V_5 . V_11 = F_12 ( V_6 ) ;
F_13 ( V_3 , V_38 ) ;
V_28 = V_27 -> V_70 -> V_71 + V_36 + V_37 ;
if ( F_14 ( V_3 ) < V_29 ) {
V_3 = F_15 ( V_3 , V_72 ) ;
if ( V_3 == NULL ) {
V_26 -> V_73 . V_74 ++ ;
return V_43 ;
}
if ( F_16 ( V_3 , V_28 , V_29 ,
V_72 ) ) {
F_6 ( V_3 ) ;
V_26 -> V_73 . V_74 ++ ;
return V_43 ;
}
} else if ( F_17 ( V_3 ) < V_28 ) {
struct V_2 * V_75 = V_3 ;
V_3 = F_18 ( V_3 , V_28 ) ;
F_6 ( V_75 ) ;
if ( V_3 == NULL ) {
V_26 -> V_73 . V_74 ++ ;
return V_43 ;
}
} else {
V_3 = F_15 ( V_3 , V_72 ) ;
if ( V_3 == NULL ) {
V_26 -> V_73 . V_74 ++ ;
return V_43 ;
}
}
if ( V_35 )
memcpy ( F_19 ( V_3 , V_37 ) , V_35 , V_37 ) ;
memcpy ( F_19 ( V_3 , V_36 ) , & V_5 , V_36 ) ;
if ( V_34 == V_32 ) {
F_20 ( V_3 , & V_5 . V_22 , V_54 ) ;
}
V_26 -> V_73 . V_76 ++ ;
V_26 -> V_73 . V_77 += V_3 -> V_9 ;
F_21 ( V_3 ) ;
V_41 = (struct V_40 * ) V_3 -> V_78 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_79 = V_80 ;
if ( V_34 )
V_41 -> V_81 |= V_82 ;
V_41 -> V_30 = V_30 ;
V_41 -> V_26 = V_26 ;
V_3 -> V_24 = V_27 -> V_24 ;
F_22 ( V_3 ) ;
return V_43 ;
}
T_2 F_23 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 ;
T_3 * V_27 ;
struct V_40 * V_41 ;
struct V_4 * V_5 ;
T_1 V_6 ;
V_26 = F_5 ( V_24 ) ;
V_27 = V_26 -> V_27 ;
if ( V_3 -> V_9 < 10 ) {
F_2 ( V_8 L_17
L_13 , V_24 -> V_1 , V_3 -> V_9 ) ;
F_6 ( V_3 ) ;
return V_43 ;
}
V_26 -> V_73 . V_76 ++ ;
V_26 -> V_73 . V_77 += V_3 -> V_9 ;
V_41 = (struct V_40 * ) V_3 -> V_78 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_79 = V_80 ;
V_41 -> V_26 = V_26 ;
if ( V_3 -> V_9 >= V_16 + sizeof( V_59 ) + 2 ) {
V_5 = (struct V_4 * ) V_3 -> V_7 ;
V_6 = F_3 ( V_5 -> V_11 ) ;
if ( F_24 ( V_5 -> V_11 ) &&
( V_6 & V_13 ) == V_61 ) {
T_4 * V_83 = & V_3 -> V_7 [ V_16 +
sizeof( V_59 ) ] ;
V_41 -> V_30 = ( V_83 [ 0 ] << 8 ) | V_83 [ 1 ] ;
}
}
V_3 -> V_24 = V_27 -> V_24 ;
F_22 ( V_3 ) ;
return V_43 ;
}
static struct V_2 * F_25 ( struct V_2 * V_3 ,
struct V_84 * V_85 )
{
struct V_25 * V_26 ;
T_3 * V_27 ;
struct V_4 * V_5 ;
int V_86 , V_87 , V_36 , V_88 ;
V_26 = F_5 ( V_3 -> V_24 ) ;
V_27 = V_26 -> V_27 ;
if ( V_3 -> V_9 < V_16 ) {
F_6 ( V_3 ) ;
return NULL ;
}
if ( V_27 -> V_89 &&
strcmp ( V_85 -> V_90 -> V_1 , L_18 ) == 0 ) {
V_5 = (struct V_4 * ) V_3 -> V_7 ;
if ( F_26 () ) {
F_2 ( V_8 L_19
L_20 ,
V_27 -> V_24 -> V_1 , V_5 -> V_19 ) ;
}
F_6 ( V_3 ) ;
return NULL ;
}
V_3 = F_15 ( V_3 , V_72 ) ;
if ( V_3 == NULL )
return NULL ;
V_86 = V_85 -> V_90 -> V_91 +
V_85 -> V_90 -> V_92 ;
V_87 = V_85 -> V_90 -> V_93 +
V_85 -> V_90 -> V_94 ;
if ( ( F_17 ( V_3 ) < V_86 ||
F_14 ( V_3 ) < V_87 ) &&
F_16 ( V_3 , V_86 , V_87 , V_72 ) ) {
F_6 ( V_3 ) ;
return NULL ;
}
V_5 = (struct V_4 * ) V_3 -> V_7 ;
V_36 = F_27 ( V_5 -> V_11 ) ;
F_28 ( & V_85 -> V_95 ) ;
V_88 = 0 ;
if ( V_85 -> V_90 -> V_96 )
V_88 = V_85 -> V_90 -> V_96 ( V_3 , V_36 , V_85 -> V_97 ) ;
if ( V_88 == 0 && V_85 -> V_90 -> V_98 )
V_88 = V_85 -> V_90 -> V_98 ( V_3 , V_36 , V_85 -> V_97 ) ;
F_29 ( & V_85 -> V_95 ) ;
if ( V_88 < 0 ) {
F_6 ( V_3 ) ;
return NULL ;
}
return V_3 ;
}
T_2 F_30 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 ;
T_3 * V_27 ;
T_2 V_99 = V_100 ;
T_1 V_6 ;
struct V_101 V_102 ;
T_5 V_103 ;
struct V_40 * V_41 ;
int V_104 = 0 ;
struct V_4 * V_5 ;
V_26 = F_5 ( V_24 ) ;
V_27 = V_26 -> V_27 ;
V_102 . V_3 = V_3 ;
V_102 . V_105 = NULL ;
V_41 = (struct V_40 * ) V_3 -> V_78 ;
if ( V_41 -> V_79 != V_80 ) {
F_2 ( V_8 L_21
L_22 ,
V_24 -> V_1 , V_41 -> V_79 , V_80 ) ;
V_99 = V_43 ;
V_26 -> V_73 . V_74 ++ ;
goto V_106;
}
if ( V_27 -> V_107 ) {
V_102 . V_85 = V_27 -> V_108 . V_85 [ V_27 -> V_108 . V_109 ] ;
V_102 . V_107 = 1 ;
} else {
V_102 . V_85 = NULL ;
V_102 . V_107 = 0 ;
}
if ( V_3 -> V_9 < 24 ) {
F_2 ( V_8 L_23
L_13 , V_24 -> V_1 , V_3 -> V_9 ) ;
V_99 = V_43 ;
V_26 -> V_73 . V_74 ++ ;
goto V_106;
}
V_103 = F_31 ( V_27 , & V_102 ) ;
V_3 = V_102 . V_3 ;
V_41 = (struct V_40 * ) V_3 -> V_78 ;
V_5 = (struct V_4 * ) V_3 -> V_7 ;
V_6 = F_3 ( V_5 -> V_11 ) ;
switch ( V_103 ) {
case V_110 :
break;
case V_111 :
if ( V_27 -> V_112 &&
F_24 ( V_5 -> V_11 ) &&
V_41 -> V_30 != V_113 &&
! ( V_41 -> V_81 & V_82 ) ) {
F_2 ( V_8 L_24
L_25 ,
V_24 -> V_1 , V_41 -> V_30 ) ;
F_1 ( V_24 -> V_1 , V_3 ) ;
V_99 = V_43 ;
V_26 -> V_73 . V_74 ++ ;
goto V_106;
}
break;
case V_114 :
V_99 = V_43 ;
V_26 -> V_73 . V_74 ++ ;
goto V_106;
case V_115 :
goto V_106;
case V_116 :
V_99 = V_43 ;
goto V_117;
}
if ( ( ( V_6 & V_118 ) == F_32 ( 1 ) ) &&
V_27 -> V_119 && V_27 -> V_119 -> V_120 && V_41 -> V_121 == 0 ) {
V_41 -> V_121 = V_27 -> V_119 -> V_120 ;
V_6 &= ~ V_118 ;
V_5 -> V_11 = F_12 ( V_6 ) ;
}
if ( ! F_24 ( V_5 -> V_11 ) ) {
V_104 = 1 ;
V_102 . V_85 = NULL ;
}
if ( V_27 -> V_112 && V_41 -> V_30 == V_113 && V_102 . V_85 &&
! ( V_6 & V_122 ) ) {
V_104 = 1 ;
F_33 ( V_123 , L_26
L_27 , V_24 -> V_1 ) ;
V_102 . V_85 = NULL ;
}
if ( V_102 . V_85 && ( ! V_102 . V_85 -> V_90 || ! V_102 . V_85 -> V_90 -> V_98 ) )
V_102 . V_85 = NULL ;
else if ( ( V_102 . V_85 ||
V_27 -> V_108 . V_85 [ V_27 -> V_108 . V_109 ] ) &&
! V_104 ) {
V_6 |= V_122 ;
V_5 -> V_11 = F_12 ( V_6 ) ;
} else if ( V_27 -> V_124 &&
F_24 ( V_5 -> V_11 ) &&
V_41 -> V_30 != V_113 ) {
if ( F_26 () ) {
F_2 ( V_8 L_28
L_29 , V_24 -> V_1 ) ;
}
V_26 -> V_73 . V_74 ++ ;
V_99 = V_43 ;
goto V_106;
}
if ( V_102 . V_85 ) {
V_3 = F_25 ( V_3 , V_102 . V_85 ) ;
if ( V_3 == NULL ) {
F_2 ( V_8 L_30 ,
V_24 -> V_1 ) ;
V_99 = V_43 ;
goto V_106;
}
V_41 = (struct V_40 * ) V_3 -> V_78 ;
if ( V_41 -> V_79 != V_80 ) {
F_2 ( V_8 L_21
L_31 ,
V_24 -> V_1 , V_41 -> V_79 ,
V_80 ) ;
V_99 = V_43 ;
V_26 -> V_73 . V_74 ++ ;
goto V_106;
}
}
if ( V_27 -> V_70 -> V_102 == NULL || V_27 -> V_70 -> V_102 ( V_3 , V_24 ) ) {
V_99 = V_43 ;
V_26 -> V_73 . V_74 ++ ;
} else {
V_99 = V_43 ;
V_26 -> V_73 . V_76 ++ ;
V_26 -> V_73 . V_77 += V_3 -> V_9 ;
}
V_106:
if ( V_99 == V_43 && V_3 )
F_34 ( V_3 ) ;
V_117:
if ( V_102 . V_105 )
F_35 ( V_102 . V_105 ) ;
return V_99 ;
}
