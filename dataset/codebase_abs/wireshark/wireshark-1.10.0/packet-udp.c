static struct V_1 *
F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( struct V_1 ) ;
return V_2 ;
}
static struct V_1 *
F_3 ( T_1 * V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_1 * V_2 = NULL ;
if( V_3 == NULL )
V_3 = F_4 ( V_4 ) ;
V_2 = (struct V_1 * ) F_5 ( V_3 , V_6 ) ;
if ( ! V_2 ) {
V_2 = F_1 () ;
F_6 ( V_3 , V_6 , V_2 ) ;
}
if ( ! V_2 ) {
return NULL ;
}
V_5 = F_7 ( & V_4 -> V_7 , & V_4 -> V_8 ) ;
if( V_5 == 0 ) {
V_5 = ( V_4 -> V_9 > V_4 -> V_10 ) ? 1 : - 1 ;
}
if( V_5 >= 0 ) {
V_2 -> V_11 = & ( V_2 -> V_12 ) ;
V_2 -> V_13 = & ( V_2 -> V_14 ) ;
} else {
V_2 -> V_11 = & ( V_2 -> V_14 ) ;
V_2 -> V_13 = & ( V_2 -> V_12 ) ;
}
return V_2 ;
}
void
F_8 ( T_3 V_15 , T_4 * V_16 , T_4 * V_17 , T_5 V_18 , T_5 V_19 , T_3 V_20 , T_3 V_21 , T_6 * V_22 , T_6 * V_23 ) {
T_1 * V_3 ;
struct V_1 * V_2 ;
T_7 * V_24 = NULL ;
if ( ! V_25 ) {
return;
}
V_3 = F_9 ( V_15 , V_16 , V_17 , V_26 , V_18 , V_19 , 0 ) ;
if ( ! V_3 ) {
return;
}
V_2 = (struct V_1 * ) F_5 ( V_3 , V_6 ) ;
if ( ! V_2 ) {
return;
}
if ( F_7 ( V_16 , & V_3 -> V_27 -> V_28 ) == 0 && V_18 == V_3 -> V_27 -> V_29 ) {
V_24 = & V_2 -> V_12 ;
} else if ( F_7 ( V_17 , & V_3 -> V_27 -> V_28 ) == 0 && V_19 == V_3 -> V_27 -> V_29 ) {
V_24 = & V_2 -> V_14 ;
}
if ( ! V_24 || V_24 -> V_23 ) {
return;
}
V_24 -> V_30 = V_20 ;
V_24 -> V_31 = V_21 ;
V_24 -> V_22 = F_10 ( V_22 ) ;
V_24 -> V_23 = F_10 ( V_23 ) ;
}
void
F_11 ( T_8 * V_32 , int V_33 , T_2 * V_4 ,
T_9 * V_34 , int V_35 , int V_36 , int V_37 )
{
T_8 * V_38 ;
int V_39 , V_40 ;
T_10 V_41 , V_42 ;
V_41 = F_12 ( V_32 , V_33 ) ;
V_42 = F_13 ( V_32 , V_33 ) ;
if ( V_37 != - 1 ) {
if ( V_37 - V_33 < V_42 )
V_42 = V_37 - V_33 ;
if ( V_41 > V_42 )
V_41 = V_42 ;
}
V_38 = F_14 ( V_32 , V_33 , V_41 , V_42 ) ;
if( F_15 ( V_43 ) )
F_16 ( V_43 , V_4 , V_38 ) ;
if ( F_17 ( & V_4 -> V_8 , & V_4 -> V_7 , V_26 ,
V_36 , V_35 , V_38 , V_4 , V_34 ) ) {
return;
}
if ( V_44 ) {
if ( F_18 ( V_45 , V_38 , V_4 , V_34 , NULL ) )
return;
}
if ( V_35 > V_36 ) {
V_39 = V_36 ;
V_40 = V_35 ;
} else {
V_39 = V_35 ;
V_40 = V_36 ;
}
if ( V_39 != 0 &&
F_19 ( V_46 , V_39 , V_38 , V_4 , V_34 ) )
return;
if ( V_40 != 0 &&
F_19 ( V_46 , V_40 , V_38 , V_4 , V_34 ) )
return;
if ( ! V_44 ) {
if ( F_18 ( V_45 , V_38 , V_4 , V_34 , NULL ) )
return;
}
F_20 ( V_47 , V_38 , V_4 , V_34 ) ;
}
static void
F_21 ( T_8 * V_32 , T_2 * V_4 , T_9 * V_34 , T_3 V_48 )
{
T_9 * V_49 = NULL ;
T_11 * V_50 , * V_51 , * V_52 ;
T_12 V_41 ;
T_12 V_42 ;
T_13 V_53 [ 4 ] ;
T_3 V_54 [ 2 ] ;
T_5 V_55 ;
int V_33 = 0 ;
T_14 * V_56 ;
T_9 * V_57 ;
T_11 * V_58 ;
T_1 * V_3 = NULL ;
struct V_1 * V_2 = NULL ;
T_9 * V_59 ;
V_56 = F_22 ( T_14 ) ;
F_23 ( & V_56 -> V_60 , V_4 -> V_7 . type , V_4 -> V_7 . V_41 , V_4 -> V_7 . V_61 ) ;
F_23 ( & V_56 -> V_62 , V_4 -> V_8 . type , V_4 -> V_8 . V_41 , V_4 -> V_8 . V_61 ) ;
F_24 ( V_4 -> V_63 , V_64 , ( V_48 == V_65 ) ? L_1 : L_2 ) ;
F_25 ( V_4 -> V_63 , V_66 ) ;
V_56 -> V_35 = F_26 ( V_32 , V_33 ) ;
V_56 -> V_36 = F_26 ( V_32 , V_33 + 2 ) ;
F_27 ( V_4 -> V_63 , V_66 , L_3 ,
F_28 ( V_56 -> V_35 ) , F_28 ( V_56 -> V_36 ) ) ;
if ( V_34 ) {
if ( V_67 ) {
if ( V_48 == V_65 ) {
V_50 = F_29 ( V_34 , V_6 , V_32 , V_33 , 8 ,
L_4 ,
F_28 ( V_56 -> V_35 ) , V_56 -> V_35 , F_28 ( V_56 -> V_36 ) , V_56 -> V_36 ) ;
} else {
V_50 = F_29 ( V_34 , V_68 , V_32 , V_33 , 8 ,
L_5 ,
F_28 ( V_56 -> V_35 ) , V_56 -> V_35 , F_28 ( V_56 -> V_36 ) , V_56 -> V_36 ) ;
}
} else {
V_50 = F_30 ( V_34 , ( V_48 == V_65 ) ? V_6 : V_68 , V_32 , V_33 , 8 , V_69 ) ;
}
V_49 = F_31 ( V_50 , V_70 ) ;
V_52 = F_32 ( V_49 , V_71 , V_32 , V_33 , 2 , V_56 -> V_35 ,
L_6 , F_28 ( V_56 -> V_35 ) , V_56 -> V_35 ) ;
if( V_56 -> V_35 > 32768 + 666 && V_56 -> V_35 <= 32768 + 666 + 30 )
F_33 ( V_4 , V_52 , V_72 , V_73 , L_7 ,
( ( V_56 -> V_35 - 32768 - 666 - 1 ) / 3 ) + 1 ,
( ( V_56 -> V_35 - 32768 - 666 - 1 ) % 3 ) + 1
) ;
V_52 = F_32 ( V_49 , V_74 , V_32 , V_33 + 2 , 2 , V_56 -> V_36 ,
L_8 , F_28 ( V_56 -> V_36 ) , V_56 -> V_36 ) ;
if( V_56 -> V_36 > 32768 + 666 && V_56 -> V_36 <= 32768 + 666 + 30 )
F_33 ( V_4 , V_52 , V_72 , V_73 , L_7 ,
( ( V_56 -> V_36 - 32768 - 666 - 1 ) / 3 ) + 1 ,
( ( V_56 -> V_36 - 32768 - 666 - 1 ) % 3 ) + 1
) ;
V_51 = F_34 ( V_49 , V_75 , V_32 , V_33 , 2 , V_56 -> V_35 ) ;
F_35 ( V_51 ) ;
V_51 = F_34 ( V_49 , V_75 , V_32 , V_33 + 2 , 2 , V_56 -> V_36 ) ;
F_35 ( V_51 ) ;
}
if ( V_48 == V_65 ) {
V_56 -> V_37 = V_56 -> V_76 = F_26 ( V_32 , V_33 + 4 ) ;
if ( V_56 -> V_37 < 8 ) {
V_58 = F_32 ( V_49 , V_77 , V_32 , V_33 + 4 , 2 ,
V_56 -> V_37 , L_9 , V_56 -> V_37 ) ;
F_33 ( V_4 , V_58 , V_78 , V_79 , L_10 , V_56 -> V_37 ) ;
F_36 ( V_4 -> V_63 , V_66 , L_11 , V_56 -> V_37 ) ;
return;
}
if ( ( V_56 -> V_37 > F_37 ( V_32 ) ) && ! V_4 -> V_80 && ! V_4 -> V_81 . V_82 ) {
V_58 = F_32 ( V_49 , V_77 , V_32 , V_33 + 4 , 2 ,
V_56 -> V_37 , L_12 , V_56 -> V_37 , F_37 ( V_32 ) ) ;
F_33 ( V_4 , V_58 , V_78 , V_79 , L_13 , V_56 -> V_37 ) ;
F_36 ( V_4 -> V_63 , V_66 , L_14 , V_56 -> V_37 ) ;
} else {
if ( V_34 ) {
F_34 ( V_49 , V_77 , V_32 , V_33 + 4 , 2 , V_56 -> V_37 ) ;
V_51 = F_34 ( V_49 , V_83 , V_32 , V_33 + 4 ,
0 , V_56 -> V_76 ) ;
F_35 ( V_51 ) ;
}
}
} else {
V_56 -> V_37 = V_4 -> V_84 - V_4 -> V_85 ;
V_56 -> V_76 = F_26 ( V_32 , V_33 + 4 ) ;
if ( ( ( V_56 -> V_76 > 0 ) && ( V_56 -> V_76 < 8 ) ) || ( V_56 -> V_76 > V_56 -> V_37 ) ) {
if ( V_34 ) {
V_51 = F_38 ( V_49 , V_86 , V_32 , V_33 + 4 , 2 , TRUE ) ;
F_35 ( V_51 ) ;
V_51 = F_34 ( V_49 , V_77 , V_32 , V_33 + 4 , 0 , V_56 -> V_37 ) ;
F_35 ( V_51 ) ;
}
V_58 = F_32 ( V_49 , V_83 , V_32 , V_33 + 4 , 2 ,
V_56 -> V_76 , L_15 ,
V_56 -> V_76 , V_56 -> V_37 ) ;
F_33 ( V_4 , V_58 , V_78 , V_79 , L_16 ,
V_56 -> V_76 , V_56 -> V_37 ) ;
F_36 ( V_4 -> V_63 , V_66 , L_17 ,
V_56 -> V_76 , V_56 -> V_37 ) ;
if ( ! V_87 )
return;
} else {
if ( V_34 ) {
V_51 = F_34 ( V_49 , V_77 , V_32 , V_33 + 4 , 0 , V_56 -> V_37 ) ;
F_35 ( V_51 ) ;
F_34 ( V_49 , V_83 , V_32 , V_33 + 4 , 2 , V_56 -> V_76 ) ;
}
}
}
V_56 -> V_76 = ( V_56 -> V_76 ) ? V_56 -> V_76 : V_56 -> V_37 ;
V_56 -> V_88 = F_26 ( V_32 , V_33 + 6 ) ;
V_42 = F_37 ( V_32 ) ;
V_41 = F_39 ( V_32 ) ;
if ( V_56 -> V_88 == 0 ) {
if ( ( V_48 == V_65 ) && ( V_4 -> V_7 . type == V_89 ) ) {
V_58 = F_32 ( V_49 , V_90 , V_32 , V_33 + 6 , 2 , 0 ,
L_18 , 0 ) ;
V_57 = F_31 ( V_58 , V_91 ) ;
V_58 = F_38 ( V_57 , V_92 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
V_58 = F_38 ( V_57 , V_93 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
} else {
V_58 = F_32 ( V_49 , V_90 , V_32 , V_33 + 6 , 2 , 0 ,
L_19 , 0 ) ;
F_33 ( V_4 , V_58 , V_94 , V_79 , L_20 ) ;
F_36 ( V_4 -> V_63 , V_66 , L_21 ) ;
V_57 = F_31 ( V_58 , V_91 ) ;
V_58 = F_38 ( V_57 , V_92 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
V_58 = F_38 ( V_57 , V_93 , V_32 ,
V_33 + 6 , 2 , TRUE ) ;
F_40 ( V_58 ) ;
}
} else if ( ! V_4 -> V_80 && V_41 >= V_42 &&
V_41 >= V_56 -> V_76 && V_42 >= V_56 -> V_76 &&
V_56 -> V_76 >= 8 ) {
if ( ( ( V_48 == V_65 ) && ( V_95 ) ) ||
( ( V_48 == V_96 ) && ( V_97 ) ) ) {
V_53 [ 0 ] . V_98 = ( const V_99 * ) V_4 -> V_7 . V_61 ;
V_53 [ 0 ] . V_41 = V_4 -> V_7 . V_41 ;
V_53 [ 1 ] . V_98 = ( const V_99 * ) V_4 -> V_8 . V_61 ;
V_53 [ 1 ] . V_41 = V_4 -> V_8 . V_41 ;
V_53 [ 2 ] . V_98 = ( const V_99 * ) & V_54 ;
switch ( V_4 -> V_7 . type ) {
case V_89 :
if ( V_48 == V_65 )
V_54 [ 0 ] = F_41 ( ( V_48 << 16 ) | V_56 -> V_37 ) ;
else
V_54 [ 0 ] = F_41 ( ( V_48 << 16 ) | V_42 ) ;
V_53 [ 2 ] . V_41 = 4 ;
break;
case V_100 :
if ( V_48 == V_65 )
V_54 [ 0 ] = F_41 ( V_56 -> V_37 ) ;
else
V_54 [ 0 ] = F_41 ( V_42 ) ;
V_54 [ 1 ] = F_41 ( V_48 ) ;
V_53 [ 2 ] . V_41 = 8 ;
break;
default:
F_42 () ;
break;
}
V_53 [ 3 ] . V_98 = F_43 ( V_32 , V_33 , V_56 -> V_76 ) ;
V_53 [ 3 ] . V_41 = V_56 -> V_76 ;
V_55 = F_44 ( & V_53 [ 0 ] , 4 ) ;
if ( V_55 == 0 ) {
V_58 = F_32 ( V_49 , V_90 , V_32 ,
V_33 + 6 , 2 , V_56 -> V_88 , L_22 , V_56 -> V_88 ) ;
V_57 = F_31 ( V_58 , V_91 ) ;
V_58 = F_38 ( V_57 , V_92 , V_32 ,
V_33 + 6 , 2 , TRUE ) ;
F_40 ( V_58 ) ;
V_58 = F_38 ( V_57 , V_93 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
} else {
V_58 = F_32 ( V_49 , V_90 , V_32 ,
V_33 + 6 , 2 , V_56 -> V_88 ,
L_23 , V_56 -> V_88 ,
F_45 ( V_56 -> V_88 , V_55 ) ) ;
V_57 = F_31 ( V_58 , V_91 ) ;
V_58 = F_38 ( V_57 , V_92 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
V_58 = F_38 ( V_57 , V_93 , V_32 ,
V_33 + 6 , 2 , TRUE ) ;
F_40 ( V_58 ) ;
F_33 ( V_4 , V_58 , V_94 , V_79 , L_24 ) ;
F_36 ( V_4 -> V_63 , V_66 , L_25 ) ;
}
} else {
V_58 = F_32 ( V_49 , V_90 , V_32 ,
V_33 + 6 , 2 , V_56 -> V_88 , L_26 , V_56 -> V_88 ) ;
V_57 = F_31 ( V_58 , V_91 ) ;
V_58 = F_38 ( V_57 , V_92 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
V_58 = F_38 ( V_57 , V_93 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
}
} else {
V_58 = F_32 ( V_49 , V_90 , V_32 ,
V_33 + 6 , 2 , V_56 -> V_88 , L_27 , V_56 -> V_88 ) ;
V_57 = F_31 ( V_58 , V_91 ) ;
V_58 = F_38 ( V_57 , V_92 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
V_58 = F_38 ( V_57 , V_93 , V_32 ,
V_33 + 6 , 2 , FALSE ) ;
F_40 ( V_58 ) ;
}
V_33 += 8 ;
V_4 -> V_101 = V_26 ;
V_4 -> V_9 = V_56 -> V_35 ;
V_4 -> V_10 = V_56 -> V_36 ;
F_16 ( V_102 , V_4 , V_56 ) ;
if ( V_25 ) {
V_3 = F_4 ( V_4 ) ;
V_2 = F_3 ( V_3 , V_4 ) ;
}
if ( V_2 && ( ( V_2 -> V_11 && V_2 -> V_11 -> V_23 ) || ( V_2 -> V_13 && V_2 -> V_13 -> V_23 ) ) ) {
V_50 = F_46 ( V_49 , V_32 , V_33 , 0 , L_28 ) ;
F_40 ( V_50 ) ;
V_59 = F_31 ( V_50 , V_103 ) ;
if ( V_2 -> V_11 && V_2 -> V_11 -> V_23 ) {
F_47 ( V_59 , V_104 , V_32 , 0 , 0 ,
V_2 -> V_11 -> V_30 , L_29 , V_2 -> V_11 -> V_30 ) ;
F_47 ( V_59 , V_105 , V_32 , 0 , 0 ,
V_2 -> V_11 -> V_31 , L_29 , V_2 -> V_11 -> V_31 ) ;
F_48 ( V_59 , V_106 , V_32 , 0 , 0 ,
V_2 -> V_11 -> V_22 , L_30 , V_2 -> V_11 -> V_22 ) ;
F_48 ( V_59 , V_107 , V_32 , 0 , 0 ,
V_2 -> V_11 -> V_23 , L_30 , V_2 -> V_11 -> V_23 ) ;
}
if ( V_2 -> V_13 -> V_23 ) {
F_47 ( V_59 , V_108 , V_32 , 0 , 0 ,
V_2 -> V_13 -> V_30 , L_29 , V_2 -> V_13 -> V_30 ) ;
F_47 ( V_59 , V_109 , V_32 , 0 , 0 ,
V_2 -> V_13 -> V_31 , L_29 , V_2 -> V_13 -> V_31 ) ;
F_48 ( V_59 , V_110 , V_32 , 0 , 0 ,
V_2 -> V_13 -> V_22 , L_30 , V_2 -> V_13 -> V_22 ) ;
F_48 ( V_59 , V_111 , V_32 , 0 , 0 ,
V_2 -> V_13 -> V_23 , L_30 , V_2 -> V_13 -> V_23 ) ;
}
}
if ( ! V_4 -> V_81 . V_82 || F_12 ( V_32 , V_33 ) > 0 )
F_11 ( V_32 , V_33 , V_4 , V_34 , V_56 -> V_35 , V_56 -> V_36 ,
V_56 -> V_37 ) ;
}
static void
F_49 ( T_8 * V_32 , T_2 * V_4 , T_9 * V_34 )
{
F_21 ( V_32 , V_4 , V_34 , V_65 ) ;
}
static void
F_50 ( T_8 * V_32 , T_2 * V_4 , T_9 * V_34 )
{
F_21 ( V_32 , V_4 , V_34 , V_96 ) ;
}
void
F_51 ( void )
{
T_15 * V_112 ;
T_15 * V_113 ;
static T_16 V_114 [] = {
{ & V_71 ,
{ L_31 , L_32 , V_115 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_74 ,
{ L_33 , L_34 , V_115 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_75 ,
{ L_35 , L_36 , V_115 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_77 ,
{ L_37 , L_38 , V_115 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_90 ,
{ L_39 , L_40 , V_115 , V_118 , NULL , 0x0 ,
L_41 , V_117 } } ,
{ & V_92 ,
{ L_42 , L_43 , V_119 , V_120 , NULL , 0x0 ,
L_44 , V_117 } } ,
{ & V_93 ,
{ L_45 , L_46 , V_119 , V_120 , NULL , 0x0 ,
L_47 , V_117 } } ,
{ & V_108 ,
{ L_48 , L_49 , V_121 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_109 ,
{ L_50 , L_51 , V_121 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_110 ,
{ L_52 , L_53 , V_122 , V_120 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_111 ,
{ L_54 , L_55 , V_122 , V_120 , NULL , 0x0 ,
L_56 , V_117 } } ,
{ & V_104 ,
{ L_57 , L_58 , V_121 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_105 ,
{ L_59 , L_60 , V_121 , V_116 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_106 ,
{ L_61 , L_62 , V_122 , V_120 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_107 ,
{ L_63 , L_64 , V_122 , V_120 , NULL , 0x0 ,
L_65 , V_117 } }
} ;
static T_16 V_123 [] = {
{ & V_86 ,
{ L_66 , L_67 , V_119 , V_120 , NULL , 0x0 ,
NULL , V_117 } } ,
{ & V_83 ,
{ L_68 , L_69 , V_115 , V_116 , NULL , 0x0 ,
NULL , V_117 } }
} ;
static T_10 * V_124 [] = {
& V_70 ,
& V_91 ,
& V_103
} ;
V_6 = F_52 ( L_70 ,
L_1 , L_71 ) ;
F_53 ( L_71 , F_49 , V_6 ) ;
V_68 = F_52 ( L_72 ,
L_2 , L_73 ) ;
F_54 ( V_6 , V_114 , F_55 ( V_114 ) ) ;
F_54 ( V_68 , V_123 , F_55 ( V_123 ) ) ;
F_56 ( V_124 , F_55 ( V_124 ) ) ;
V_46 = F_57 ( L_36 ,
L_74 , V_115 , V_116 ) ;
F_58 ( L_71 , & V_45 ) ;
F_58 ( L_73 , & V_45 ) ;
V_112 = F_59 ( V_6 , NULL ) ;
F_60 ( V_112 , L_75 ,
L_76 ,
L_77 ,
& V_67 ) ;
F_60 ( V_112 , L_78 ,
L_79 ,
L_80 ,
& V_44 ) ;
F_60 ( V_112 , L_81 ,
L_82 ,
L_83 ,
& V_95 ) ;
F_60 ( V_112 , L_84 ,
L_85 ,
L_86 ,
& V_25 ) ;
V_113 = F_59 ( V_68 , NULL ) ;
F_60 ( V_113 , L_87 ,
L_88 ,
L_89 ,
& V_87 ) ;
F_60 ( V_113 , L_81 ,
L_90 ,
L_91 ,
& V_97 ) ;
}
void
F_61 ( void )
{
T_17 V_125 ;
T_17 V_126 ;
V_125 = F_62 ( L_71 ) ;
F_63 ( L_92 , V_65 , V_125 ) ;
V_126 = F_64 ( F_50 , V_68 ) ;
F_63 ( L_92 , V_96 , V_126 ) ;
V_47 = F_62 ( L_93 ) ;
V_102 = F_65 ( L_71 ) ;
V_43 = F_65 ( L_94 ) ;
}
