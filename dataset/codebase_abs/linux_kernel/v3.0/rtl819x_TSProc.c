void F_1 ( unsigned long V_1 )
{
}
void F_2 ( unsigned long V_1 )
{
}
void F_3 ( unsigned long V_1 )
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
void F_17 ( unsigned long V_1 )
{
T_4 V_31 = ( T_4 ) V_1 ;
T_3 V_6 = V_31 -> V_6 ;
struct V_3 * V_4 = F_4 ( V_31 , struct V_3 , V_32 [ V_6 ] ) ;
F_18 ( V_4 , V_31 , V_33 , false ) ;
F_6 ( V_34 , L_4 ) ;
}
void F_19 ( T_5 V_35 )
{
memset ( V_35 -> V_36 , 0 , 6 ) ;
memset ( & V_35 -> V_37 , 0 , sizeof( V_38 ) ) ;
memset ( & V_35 -> V_39 , 0 , sizeof( V_40 ) * V_41 ) ;
V_35 -> V_42 = 0 ;
V_35 -> V_43 = 0 ;
}
void F_20 ( T_4 V_44 )
{
F_19 ( & V_44 -> V_45 ) ;
V_44 -> V_46 = 0 ;
V_44 -> V_47 = false ;
V_44 -> V_48 = false ;
V_44 -> V_49 = false ;
F_21 ( & V_44 -> V_50 ) ;
F_21 ( & V_44 -> V_51 ) ;
}
void F_22 ( T_1 V_44 )
{
F_19 ( & V_44 -> V_45 ) ;
V_44 -> V_22 = 0xffff ;
V_44 -> V_17 = 0xffff ;
F_21 ( & V_44 -> V_52 ) ;
}
void F_23 ( struct V_3 * V_4 )
{
T_4 V_53 = V_4 -> V_32 ;
T_1 V_54 = V_4 -> V_5 ;
T_2 V_55 = V_4 -> V_56 ;
T_3 V_57 = 0 ;
F_6 ( V_58 , L_5 , V_16 ) ;
F_24 ( & V_4 -> V_59 ) ;
F_24 ( & V_4 -> V_60 ) ;
F_24 ( & V_4 -> V_61 ) ;
for( V_57 = 0 ; V_57 < V_62 ; V_57 ++ )
{
V_53 -> V_6 = V_57 ;
F_25 ( & V_53 -> V_45 . V_63 ) ;
V_53 -> V_45 . V_63 . V_1 = ( unsigned long ) V_53 ;
V_53 -> V_45 . V_63 . V_64 = F_1 ;
F_25 ( & V_53 -> V_45 . V_65 ) ;
V_53 -> V_45 . V_65 . V_1 = ( unsigned long ) V_53 ;
V_53 -> V_45 . V_65 . V_64 = F_2 ;
F_25 ( & V_53 -> V_66 ) ;
V_53 -> V_66 . V_1 = ( unsigned long ) V_53 ;
V_53 -> V_66 . V_64 = F_17 ;
F_25 ( & V_53 -> V_51 . V_67 ) ;
V_53 -> V_51 . V_67 . V_1 = ( unsigned long ) V_53 ;
V_53 -> V_51 . V_67 . V_64 = V_68 ;
F_25 ( & V_53 -> V_50 . V_67 ) ;
V_53 -> V_50 . V_67 . V_1 = ( unsigned long ) V_53 ;
V_53 -> V_50 . V_67 . V_64 = V_69 ;
F_20 ( V_53 ) ;
F_12 ( & V_53 -> V_45 . V_21 , & V_4 -> V_61 ) ;
V_53 ++ ;
}
F_24 ( & V_4 -> V_70 ) ;
F_24 ( & V_4 -> V_71 ) ;
F_24 ( & V_4 -> V_72 ) ;
for( V_57 = 0 ; V_57 < V_62 ; V_57 ++ )
{
V_54 -> V_6 = V_57 ;
F_24 ( & V_54 -> V_18 ) ;
F_25 ( & V_54 -> V_45 . V_63 ) ;
V_54 -> V_45 . V_63 . V_1 = ( unsigned long ) V_54 ;
V_54 -> V_45 . V_63 . V_64 = F_1 ;
F_25 ( & V_54 -> V_45 . V_65 ) ;
V_54 -> V_45 . V_65 . V_1 = ( unsigned long ) V_54 ;
V_54 -> V_45 . V_65 . V_64 = F_2 ;
F_25 ( & V_54 -> V_52 . V_67 ) ;
V_54 -> V_52 . V_67 . V_1 = ( unsigned long ) V_54 ;
V_54 -> V_52 . V_67 . V_64 = V_73 ;
F_25 ( & V_54 -> V_27 ) ;
V_54 -> V_27 . V_1 = ( unsigned long ) V_54 ;
V_54 -> V_27 . V_64 = F_3 ;
F_22 ( V_54 ) ;
F_12 ( & V_54 -> V_45 . V_21 , & V_4 -> V_72 ) ;
V_54 ++ ;
}
F_24 ( & V_4 -> V_25 ) ;
for( V_57 = 0 ; V_57 < V_74 ; V_57 ++ )
{
F_12 ( & V_55 -> V_21 , & V_4 -> V_25 ) ;
if( V_57 == ( V_74 - 1 ) )
break;
V_55 = & V_4 -> V_56 [ V_57 + 1 ] ;
}
}
void F_26 ( struct V_3 * V_4 , T_5 V_35 , T_6 V_75 )
{
F_27 ( & V_35 -> V_63 ) ;
F_27 ( & V_35 -> V_65 ) ;
if( V_75 != 0 )
F_15 ( & V_35 -> V_65 , V_28 + F_16 ( V_75 ) ) ;
}
T_5 F_28 ( struct V_3 * V_4 , T_3 * V_36 , T_3 V_76 , T_7 V_77 )
{
T_3 V_78 ;
bool V_79 [ 4 ] = { 0 , 0 , 0 , 0 } ;
struct V_80 * V_81 ;
T_5 V_82 = NULL ;
if( V_4 -> V_83 == V_84 )
{
if( V_77 == V_85 )
{
V_79 [ V_86 ] = true ;
V_79 [ V_87 ] = true ;
}
else
{
V_79 [ V_88 ] = true ;
V_79 [ V_87 ] = true ;
}
}
else if( V_4 -> V_83 == V_89 )
{
if( V_77 == V_85 )
V_79 [ V_88 ] = true ;
else
V_79 [ V_86 ] = true ;
}
else
{
if( V_77 == V_85 )
{
V_79 [ V_88 ] = true ;
V_79 [ V_87 ] = true ;
V_79 [ V_90 ] = true ;
}
else
{
V_79 [ V_86 ] = true ;
V_79 [ V_87 ] = true ;
V_79 [ V_90 ] = true ;
}
}
if( V_77 == V_85 )
V_81 = & V_4 -> V_59 ;
else
V_81 = & V_4 -> V_70 ;
for( V_78 = 0 ; V_78 <= V_87 ; V_78 ++ )
{
if( V_79 [ V_78 ] == false )
continue;
F_29 (pRet, psearch_list, List) {
if ( memcmp ( V_82 -> V_36 , V_36 , 6 ) == 0 )
if ( V_82 -> V_37 . V_91 . V_92 . V_93 . V_94 == V_76 )
if( V_82 -> V_37 . V_91 . V_92 . V_93 . V_95 == V_78 )
{
break;
}
}
if( & V_82 -> V_21 != V_81 )
break;
}
if( & V_82 -> V_21 != V_81 ) {
return V_82 ;
}
else
return NULL ;
}
void F_30 (
T_5 V_35 ,
T_3 * V_36 ,
T_8 V_96 ,
T_9 V_97 ,
T_3 V_98 ,
T_3 V_99
)
{
T_3 V_57 ;
if( V_35 == NULL )
return;
memcpy ( V_35 -> V_36 , V_36 , 6 ) ;
if( V_96 != NULL )
memcpy ( ( T_3 * ) ( & ( V_35 -> V_37 ) ) , ( T_3 * ) V_96 , sizeof( V_38 ) ) ;
for( V_57 = 0 ; V_57 < V_98 ; V_57 ++ )
memcpy ( ( T_3 * ) ( & ( V_35 -> V_39 [ V_57 ] ) ) , ( T_3 * ) V_97 , sizeof( V_40 ) ) ;
V_35 -> V_42 = V_99 ;
V_35 -> V_43 = V_98 ;
}
bool F_31 (
struct V_3 * V_4 ,
T_5 * V_100 ,
T_3 * V_36 ,
T_3 V_76 ,
T_7 V_77 ,
bool V_101
)
{
T_3 V_102 = 0 ;
if( F_32 ( V_36 ) || F_33 ( V_36 ) )
{
F_6 ( V_26 , L_6 ) ;
return false ;
}
if ( V_4 -> V_103 . V_104 . V_105 == 0 )
V_102 = 0 ;
else
{
if ( ! F_34 ( V_76 ) )
{
F_6 ( V_26 , L_7 , V_16 , V_76 ) ;
return false ;
}
switch( V_76 )
{
case 0 :
case 3 :
V_102 = 0 ;
break;
case 1 :
case 2 :
V_102 = 2 ;
break;
case 4 :
case 5 :
V_102 = 5 ;
break;
case 6 :
case 7 :
V_102 = 7 ;
break;
}
}
* V_100 = F_28 (
V_4 ,
V_36 ,
V_102 ,
V_77 ) ;
if( * V_100 != NULL )
{
return true ;
}
else
{
if( V_101 == false )
{
F_6 ( V_58 , L_8 , V_102 ) ;
return false ;
}
else
{
V_38 V_37 ;
T_10 V_106 = & V_37 . V_91 . V_92 ;
struct V_80 * V_107 =
( V_77 == V_85 ) ?
( & V_4 -> V_61 ) :
( & V_4 -> V_72 ) ;
struct V_80 * V_108 =
( V_77 == V_85 ) ?
( & V_4 -> V_59 ) :
( & V_4 -> V_70 ) ;
T_11 V_109 = ( V_4 -> V_83 == V_84 ) ?
( ( V_77 == V_85 ) ? V_86 : V_88 ) :
( ( V_77 == V_85 ) ? V_88 : V_86 ) ;
F_6 ( V_58 , L_9 ) ;
if( ! F_7 ( V_107 ) )
{
( * V_100 ) = F_8 ( V_107 -> V_110 , V_111 , V_21 ) ;
F_11 ( & ( * V_100 ) -> V_21 ) ;
if( V_77 == V_85 )
{
T_4 V_112 = F_4 ( * V_100 , V_113 , V_45 ) ;
F_20 ( V_112 ) ;
}
else{
T_1 V_112 = F_4 ( * V_100 , V_114 , V_45 ) ;
F_22 ( V_112 ) ;
}
F_6 ( V_58 , L_10 , V_102 , V_109 , V_36 ) ;
V_106 -> V_93 . V_115 = 0 ;
V_106 -> V_93 . V_94 = V_102 ;
V_106 -> V_93 . V_95 = V_109 ;
V_106 -> V_93 . V_116 = 1 ;
V_106 -> V_93 . V_117 = 0 ;
V_106 -> V_93 . V_118 = 0 ;
V_106 -> V_93 . V_119 = V_102 ;
V_106 -> V_93 . V_120 = 0 ;
V_106 -> V_93 . V_121 = 0 ;
F_30 ( * V_100 , V_36 , & V_37 , NULL , 0 , 0 ) ;
F_26 ( V_4 , * V_100 , 0 ) ;
F_12 ( & ( ( * V_100 ) -> V_21 ) , V_108 ) ;
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
void F_35 (
struct V_3 * V_4 ,
T_5 V_122 ,
T_7 V_77
)
{
unsigned long V_8 = 0 ;
F_27 ( & V_122 -> V_63 ) ;
F_27 ( & V_122 -> V_65 ) ;
F_36 ( V_4 , V_122 , V_77 ) ;
if( V_77 == V_123 )
{
T_2 V_55 ;
T_1 V_54 = ( T_1 ) V_122 ;
if( F_37 ( & V_54 -> V_27 ) )
F_27 ( & V_54 -> V_27 ) ;
while( ! F_7 ( & V_54 -> V_18 ) )
{
F_5 ( & ( V_4 -> V_14 ) , V_8 ) ;
V_55 = ( T_2 ) F_8 ( V_54 -> V_18 . V_19 , V_20 , V_21 ) ;
F_11 ( & V_55 -> V_21 ) ;
{
int V_124 = 0 ;
struct V_9 * V_24 = V_55 -> V_24 ;
if ( F_38 ( ! V_24 ) )
{
F_13 ( & ( V_4 -> V_14 ) , V_8 ) ;
return;
}
for( V_124 = 0 ; V_124 < V_24 -> V_125 ; V_124 ++ ) {
F_39 ( V_24 -> V_126 [ V_124 ] ) ;
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
T_4 V_53 = ( T_4 ) V_122 ;
F_27 ( & V_53 -> V_66 ) ;
}
}
void F_41 ( struct V_3 * V_4 , T_3 * V_36 )
{
T_5 V_44 , V_127 ;
F_42 ( L_12 , V_36 ) ;
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Pending_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_35 ( V_4 , V_44 , V_85 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Admit_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_42 ( L_13 ) ;
F_35 ( V_4 , V_44 , V_85 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Pending_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_35 ( V_4 , V_44 , V_123 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_72 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Admit_List, List)
{
if ( memcmp ( V_44 -> V_36 , V_36 , 6 ) == 0 )
{
F_35 ( V_4 , V_44 , V_123 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_72 ) ;
}
}
}
void F_44 ( struct V_3 * V_4 )
{
T_5 V_44 , V_127 ;
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Pending_List, List)
{
F_35 ( V_4 , V_44 , V_85 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Admit_List, List)
{
F_35 ( V_4 , V_44 , V_85 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_61 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Pending_List, List)
{
F_35 ( V_4 , V_44 , V_123 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_72 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Admit_List, List)
{
F_35 ( V_4 , V_44 , V_123 ) ;
F_11 ( & V_44 -> V_21 ) ;
F_12 ( & V_44 -> V_21 , & V_4 -> V_72 ) ;
}
}
void F_45 ( struct V_3 * V_4 , T_4 V_53 )
{
if( V_53 -> V_47 == false )
{
V_53 -> V_47 = true ;
if( V_53 -> V_48 )
{
F_6 ( V_34 , L_14 ) ;
F_15 ( & V_53 -> V_66 , V_28 + F_16 ( V_128 ) ) ;
}
else
{
F_6 ( V_34 , L_15 ) ;
F_15 ( & V_53 -> V_66 , V_28 + 10 ) ;
}
}
else
F_6 ( V_26 , L_16 , V_16 ) ;
}
