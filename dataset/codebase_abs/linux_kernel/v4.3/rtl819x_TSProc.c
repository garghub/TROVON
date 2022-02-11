static void F_1 ( unsigned long V_1 )
{
}
static void F_2 ( unsigned long V_1 )
{
}
static void F_3 ( unsigned long V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
struct V_3 * V_4 = F_4 ( V_2 , struct V_3 , V_5 [ V_2 -> V_6 ] ) ;
T_2 V_7 = NULL ;
unsigned long V_8 = 0 ;
struct V_9 * V_10 [ V_11 ] ;
T_3 V_12 = 0 ;
bool V_13 = false ;
F_5 ( & ( V_4 -> V_14 ) , V_8 ) ;
F_6 ( V_15 , L_1 , V_16 ) ;
if( V_2 -> V_17 != 0xffff )
{
while( ! F_7 ( & V_2 -> V_18 ) )
{
V_7 = ( T_2 ) F_8 ( V_2 -> V_18 . V_19 , V_20 , V_21 ) ;
if( V_12 == 0 )
V_2 -> V_22 = V_7 -> V_23 ;
if( F_9 ( V_7 -> V_23 , V_2 -> V_22 ) ||
F_10 ( V_7 -> V_23 , V_2 -> V_22 ) )
{
F_11 ( & V_7 -> V_21 ) ;
if( F_10 ( V_7 -> V_23 , V_2 -> V_22 ) )
V_2 -> V_22 = ( V_2 -> V_22 + 1 ) % 4096 ;
F_6 ( V_15 , L_2 , V_7 -> V_23 ) ;
V_10 [ V_12 ] = V_7 -> V_24 ;
V_12 ++ ;
F_12 ( & V_7 -> V_21 , & V_4 -> V_25 ) ;
}
else
{
V_13 = true ;
break;
}
}
}
if( V_12 > 0 )
{
V_2 -> V_17 = 0xffff ;
if( V_12 > V_11 ) {
F_6 ( V_26 , L_3 ) ;
F_13 ( & ( V_4 -> V_14 ) , V_8 ) ;
return;
}
F_14 ( V_4 , V_10 , V_12 ) ;
}
if( V_13 && ( V_2 -> V_17 == 0xffff ) )
{
V_2 -> V_17 = V_2 -> V_22 ;
F_15 ( & V_2 -> V_27 , V_28 + F_16 ( V_4 -> V_29 -> V_30 ) ) ;
}
F_13 ( & ( V_4 -> V_14 ) , V_8 ) ;
}
static void F_17 ( unsigned long V_1 )
{
T_4 V_31 = ( T_4 ) V_1 ;
T_3 V_6 = V_31 -> V_6 ;
struct V_3 * V_4 = F_4 ( V_31 , struct V_3 , V_32 [ V_6 ] ) ;
F_18 ( V_4 , V_31 , V_33 , false ) ;
F_6 ( V_34 , L_4 ) ;
}
static void F_19 ( T_5 V_35 )
{
F_20 ( V_35 -> V_36 ) ;
memset ( & V_35 -> V_37 , 0 , sizeof( V_38 ) ) ;
memset ( & V_35 -> V_39 , 0 , sizeof( V_40 ) * V_41 ) ;
V_35 -> V_42 = 0 ;
V_35 -> V_43 = 0 ;
}
static void F_21 ( T_4 V_44 )
{
F_19 ( & V_44 -> V_45 ) ;
V_44 -> V_46 = 0 ;
V_44 -> V_47 = false ;
V_44 -> V_48 = false ;
V_44 -> V_49 = false ;
F_22 ( & V_44 -> V_50 ) ;
F_22 ( & V_44 -> V_51 ) ;
}
static void F_23 ( T_1 V_44 )
{
F_19 ( & V_44 -> V_45 ) ;
V_44 -> V_22 = 0xffff ;
V_44 -> V_17 = 0xffff ;
F_22 ( & V_44 -> V_52 ) ;
}
void F_24 ( struct V_3 * V_4 )
{
T_4 V_53 = V_4 -> V_32 ;
T_1 V_54 = V_4 -> V_5 ;
T_2 V_55 = V_4 -> V_56 ;
T_3 V_57 = 0 ;
F_6 ( V_58 , L_5 , V_16 ) ;
F_25 ( & V_4 -> V_59 ) ;
F_25 ( & V_4 -> V_60 ) ;
F_25 ( & V_4 -> V_61 ) ;
for( V_57 = 0 ; V_57 < V_62 ; V_57 ++ )
{
V_53 -> V_6 = V_57 ;
F_26 ( & V_53 -> V_45 . V_63 , F_1 ,
( unsigned long ) V_53 ) ;
F_26 ( & V_53 -> V_45 . V_64 , F_2 ,
( unsigned long ) V_53 ) ;
F_26 ( & V_53 -> V_65 , F_17 ,
( unsigned long ) V_53 ) ;
F_26 ( & V_53 -> V_51 . V_66 , V_67 ,
( unsigned long ) V_53 ) ;
F_26 ( & V_53 -> V_50 . V_66 ,
V_68 , ( unsigned long ) V_53 ) ;
F_21 ( V_53 ) ;
F_12 ( & V_53 -> V_45 . V_21 , & V_4 -> V_61 ) ;
V_53 ++ ;
}
F_25 ( & V_4 -> V_69 ) ;
F_25 ( & V_4 -> V_70 ) ;
F_25 ( & V_4 -> V_71 ) ;
for( V_57 = 0 ; V_57 < V_62 ; V_57 ++ )
{
V_54 -> V_6 = V_57 ;
F_25 ( & V_54 -> V_18 ) ;
F_26 ( & V_54 -> V_45 . V_63 , F_1 ,
( unsigned long ) V_54 ) ;
F_26 ( & V_54 -> V_45 . V_64 , F_2 ,
( unsigned long ) V_54 ) ;
F_26 ( & V_54 -> V_52 . V_66 ,
V_72 , ( unsigned long ) V_54 ) ;
F_26 ( & V_54 -> V_27 , F_3 ,
( unsigned long ) V_54 ) ;
F_23 ( V_54 ) ;
F_12 ( & V_54 -> V_45 . V_21 , & V_4 -> V_71 ) ;
V_54 ++ ;
}
F_25 ( & V_4 -> V_25 ) ;
for( V_57 = 0 ; V_57 < V_73 ; V_57 ++ )
{
F_12 ( & V_55 -> V_21 , & V_4 -> V_25 ) ;
if( V_57 == ( V_73 - 1 ) )
break;
V_55 = & V_4 -> V_56 [ V_57 + 1 ] ;
}
}
static void F_27 ( struct V_3 * V_4 ,
T_5 V_35 , T_6 V_74 )
{
F_28 ( & V_35 -> V_63 ) ;
F_28 ( & V_35 -> V_64 ) ;
if( V_74 != 0 )
F_15 ( & V_35 -> V_64 , V_28 + F_16 ( V_74 ) ) ;
}
static T_5 F_29 ( struct V_3 * V_4 ,
T_3 * V_36 , T_3 V_75 ,
T_7 V_76 )
{
T_3 V_77 ;
bool V_78 [ 4 ] = { 0 } ;
struct V_79 * V_80 ;
T_5 V_81 = NULL ;
if( V_4 -> V_82 == V_83 )
{
if( V_76 == V_84 )
{
V_78 [ V_85 ] = true ;
V_78 [ V_86 ] = true ;
}
else
{
V_78 [ V_87 ] = true ;
V_78 [ V_86 ] = true ;
}
}
else if( V_4 -> V_82 == V_88 )
{
if( V_76 == V_84 )
V_78 [ V_87 ] = true ;
else
V_78 [ V_85 ] = true ;
}
else
{
if( V_76 == V_84 )
{
V_78 [ V_87 ] = true ;
V_78 [ V_86 ] = true ;
V_78 [ V_89 ] = true ;
}
else
{
V_78 [ V_85 ] = true ;
V_78 [ V_86 ] = true ;
V_78 [ V_89 ] = true ;
}
}
if( V_76 == V_84 )
V_80 = & V_4 -> V_59 ;
else
V_80 = & V_4 -> V_69 ;
for( V_77 = 0 ; V_77 <= V_86 ; V_77 ++ )
{
if ( ! V_78 [ V_77 ] )
continue;
F_30 (pRet, psearch_list, List) {
if ( memcmp ( V_81 -> V_36 , V_36 , 6 ) == 0 )
if ( V_81 -> V_37 . V_90 . V_91 . V_92 . V_93 == V_75 )
if( V_81 -> V_37 . V_90 . V_91 . V_92 . V_94 == V_77 )
{
break;
}
}
if( & V_81 -> V_21 != V_80 )
break;
}
if( & V_81 -> V_21 != V_80 ) {
return V_81 ;
}
else
return NULL ;
}
static void F_31 ( T_5 V_35 , T_3 * V_36 ,
T_8 V_95 , T_9 V_96 , T_3 V_97 ,
T_3 V_98 )
{
T_3 V_57 ;
if( V_35 == NULL )
return;
memcpy ( V_35 -> V_36 , V_36 , 6 ) ;
if( V_95 != NULL )
memcpy ( ( T_3 * ) ( & ( V_35 -> V_37 ) ) , ( T_3 * ) V_95 , sizeof( V_38 ) ) ;
for( V_57 = 0 ; V_57 < V_97 ; V_57 ++ )
memcpy ( ( T_3 * ) ( & ( V_35 -> V_39 [ V_57 ] ) ) , ( T_3 * ) V_96 , sizeof( V_40 ) ) ;
V_35 -> V_42 = V_98 ;
V_35 -> V_43 = V_97 ;
}
bool F_32 (
struct V_3 * V_4 ,
T_5 * V_99 ,
T_3 * V_36 ,
T_3 V_75 ,
T_7 V_76 ,
bool V_100
)
{
T_3 V_101 = 0 ;
if ( F_33 ( V_36 ) )
{
F_6 ( V_26 , L_6 ) ;
return false ;
}
if ( V_4 -> V_102 . V_103 . V_104 == 0 )
V_101 = 0 ;
else
{
if ( ! F_34 ( V_75 ) )
{
F_6 ( V_26 , L_7 , V_16 , V_75 ) ;
return false ;
}
switch ( V_75 )
{
case 0 :
case 3 :
V_101 = 0 ;
break;
case 1 :
case 2 :
V_101 = 2 ;
break;
case 4 :
case 5 :
V_101 = 5 ;
break;
case 6 :
case 7 :
V_101 = 7 ;
break;
}
}
* V_99 = F_29 (
V_4 ,
V_36 ,
V_101 ,
V_76 ) ;
if( * V_99 != NULL )
{
return true ;
}
else
{
if ( ! V_100 ) {
F_6 ( V_58 , L_8 , V_101 ) ;
return false ;
}
else
{
V_38 V_37 ;
T_10 V_105 = & V_37 . V_90 . V_91 ;
struct V_79 * V_106 =
( V_76 == V_84 ) ?
( & V_4 -> V_61 ) :
( & V_4 -> V_71 ) ;
struct V_79 * V_107 =
( V_76 == V_84 ) ?
( & V_4 -> V_59 ) :
( & V_4 -> V_69 ) ;
T_11 V_108 = ( V_4 -> V_82 == V_83 ) ?
( ( V_76 == V_84 ) ? V_85 : V_87 ) :
( ( V_76 == V_84 ) ? V_87 : V_85 ) ;
F_6 ( V_58 , L_9 ) ;
if( ! F_7 ( V_106 ) )
{
( * V_99 ) = F_8 ( V_106 -> V_109 , V_110 , V_21 ) ;
F_11 ( & ( * V_99 ) -> V_21 ) ;
if( V_76 == V_84 )
{
T_4 V_111 = F_4 ( * V_99 , V_112 , V_45 ) ;
F_21 ( V_111 ) ;
}
else{
T_1 V_111 = F_4 ( * V_99 , V_113 , V_45 ) ;
F_23 ( V_111 ) ;
}
F_6 ( V_58 , L_10 , V_101 , V_108 , V_36 ) ;
V_105 -> V_92 . V_114 = 0 ;
V_105 -> V_92 . V_93 = V_101 ;
V_105 -> V_92 . V_94 = V_108 ;
V_105 -> V_92 . V_115 = 1 ;
V_105 -> V_92 . V_116 = 0 ;
V_105 -> V_92 . V_117 = 0 ;
V_105 -> V_92 . V_118 = V_101 ;
V_105 -> V_92 . V_119 = 0 ;
V_105 -> V_92 . V_120 = 0 ;
F_31 ( * V_99 , V_36 , & V_37 , NULL , 0 , 0 ) ;
F_27 ( V_4 , * V_99 , 0 ) ;
F_12 ( & ( ( * V_99 ) -> V_21 ) , V_107 ) ;
return true ;
}
else
{
F_6 ( V_26 , L_11 , V_16 ) ;
return false ;
}
}
}
}
static void F_35 ( struct V_3 * V_4 , T_5 V_121 ,
T_7 V_76 )
{
unsigned long V_8 = 0 ;
F_28 ( & V_121 -> V_63 ) ;
F_28 ( & V_121 -> V_64 ) ;
F_36 ( V_4 , V_121 , V_76 ) ;
if( V_76 == V_122 )
{
T_2 V_55 ;
T_1 V_54 = ( T_1 ) V_121 ;
if( F_37 ( & V_54 -> V_27 ) )
F_28 ( & V_54 -> V_27 ) ;
while( ! F_7 ( & V_54 -> V_18 ) )
{
F_5 ( & ( V_4 -> V_14 ) , V_8 ) ;
V_55 = ( T_2 ) F_8 ( V_54 -> V_18 . V_19 , V_20 , V_21 ) ;
F_11 ( & V_55 -> V_21 ) ;
{
int V_123 = 0 ;
struct V_9 * V_24 = V_55 -> V_24 ;
if ( F_38 ( ! V_24 ) )
{
F_13 ( & ( V_4 -> V_14 ) , V_8 ) ;
return;
}
for( V_123 = 0 ; V_123 < V_24 -> V_124 ; V_123 ++ ) {
F_39 ( V_24 -> V_125 [ V_123 ] ) ;
}
F_40 ( V_24 ) ;
V_24 = NULL ;
}
F_12 ( & V_55 -> V_21 , & V_4 -> V_25 ) ;
F_13 ( & ( V_4 -> V_14 ) , V_8 ) ;
}
}
else
{
T_4 V_53 = ( T_4 ) V_121 ;
F_28 ( & V_53 -> V_65 ) ;
}
}
void F_41 ( struct V_3 * V_4 , T_3 * V_36 )
{
T_5 V_44 , V_126 ;
F_42 ( L_12 , V_36 ) ;
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Pending_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_35 ( V_4 , V_44 , V_84 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Admit_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_42 ( L_13 ) ;
F_35 ( V_4 , V_44 , V_84 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Pending_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_35 ( V_4 , V_44 , V_122 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_71 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Admit_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_35 ( V_4 , V_44 , V_122 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_71 ) ;
}
}
}
void F_44 ( struct V_3 * V_4 )
{
T_5 V_44 , V_126 ;
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Pending_List, List)
{
F_35 ( V_4 , V_44 , V_84 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Admit_List, List)
{
F_35 ( V_4 , V_44 , V_84 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Pending_List, List)
{
F_35 ( V_4 , V_44 , V_122 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_71 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Admit_List, List)
{
F_35 ( V_4 , V_44 , V_122 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_71 ) ;
}
}
void F_45 ( struct V_3 * V_4 , T_4 V_53 )
{
if( ! V_53 -> V_47 )
{
V_53 -> V_47 = true ;
if( V_53 -> V_48 )
{
F_6 ( V_34 , L_14 ) ;
F_15 ( & V_53 -> V_65 , V_28 + F_16 ( V_127 ) ) ;
}
else
{
F_6 ( V_34 , L_15 ) ;
F_15 ( & V_53 -> V_65 , V_28 + 10 ) ;
}
}
else
F_6 ( V_26 , L_16 , V_16 ) ;
}
