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
T_3 V_9 = 0 ;
bool V_10 = false ;
F_5 ( & ( V_4 -> V_11 ) , V_8 ) ;
F_6 ( V_12 , L_1 , V_13 ) ;
if( V_2 -> V_14 != 0xffff )
{
while( ! F_7 ( & V_2 -> V_15 ) )
{
V_7 = ( T_2 ) F_8 ( V_2 -> V_15 . V_16 , V_17 , V_18 ) ;
if( V_9 == 0 )
V_2 -> V_19 = V_7 -> V_20 ;
if( F_9 ( V_7 -> V_20 , V_2 -> V_19 ) ||
F_10 ( V_7 -> V_20 , V_2 -> V_19 ) )
{
F_11 ( & V_7 -> V_18 ) ;
if( F_10 ( V_7 -> V_20 , V_2 -> V_19 ) )
V_2 -> V_19 = ( V_2 -> V_19 + 1 ) % 4096 ;
F_6 ( V_12 , L_2 , V_7 -> V_20 ) ;
V_4 -> V_21 [ V_9 ] = V_7 -> V_22 ;
V_9 ++ ;
F_12 ( & V_7 -> V_18 , & V_4 -> V_23 ) ;
}
else
{
V_10 = true ;
break;
}
}
}
if( V_9 > 0 )
{
V_2 -> V_14 = 0xffff ;
if( V_9 > V_24 ) {
F_6 ( V_25 , L_3 ) ;
F_13 ( & ( V_4 -> V_11 ) , V_8 ) ;
return;
}
F_14 ( V_4 , V_4 -> V_21 , V_9 ) ;
}
if( V_10 && ( V_2 -> V_14 == 0xffff ) )
{
V_2 -> V_14 = V_2 -> V_19 ;
F_15 ( & V_2 -> V_26 ,
V_27 + F_16 ( V_4 -> V_28 -> V_29 ) ) ;
}
F_13 ( & ( V_4 -> V_11 ) , V_8 ) ;
}
static void F_17 ( unsigned long V_1 )
{
T_4 V_30 = ( T_4 ) V_1 ;
T_3 V_6 = V_30 -> V_6 ;
struct V_3 * V_4 = F_4 ( V_30 , struct V_3 , V_31 [ V_6 ] ) ;
F_18 ( V_4 , V_30 , V_32 , false ) ;
F_6 ( V_33 , L_4 ) ;
}
static void F_19 ( T_5 V_34 )
{
F_20 ( V_34 -> V_35 ) ;
memset ( & V_34 -> V_36 , 0 , sizeof( V_37 ) ) ;
memset ( & V_34 -> V_38 , 0 , sizeof( V_39 ) * V_40 ) ;
V_34 -> V_41 = 0 ;
V_34 -> V_42 = 0 ;
}
static void F_21 ( T_4 V_43 )
{
F_19 ( & V_43 -> V_44 ) ;
V_43 -> V_45 = 0 ;
V_43 -> V_46 = false ;
V_43 -> V_47 = false ;
V_43 -> V_48 = false ;
F_22 ( & V_43 -> V_49 ) ;
F_22 ( & V_43 -> V_50 ) ;
}
static void F_23 ( T_1 V_43 )
{
F_19 ( & V_43 -> V_44 ) ;
V_43 -> V_19 = 0xffff ;
V_43 -> V_14 = 0xffff ;
F_22 ( & V_43 -> V_51 ) ;
}
void F_24 ( struct V_3 * V_4 )
{
T_4 V_52 = V_4 -> V_31 ;
T_1 V_53 = V_4 -> V_5 ;
T_2 V_54 = V_4 -> V_55 ;
T_3 V_56 = 0 ;
F_6 ( V_57 , L_5 , V_13 ) ;
F_25 ( & V_4 -> V_58 ) ;
F_25 ( & V_4 -> V_59 ) ;
F_25 ( & V_4 -> V_60 ) ;
for( V_56 = 0 ; V_56 < V_61 ; V_56 ++ )
{
V_52 -> V_6 = V_56 ;
F_26 ( & V_52 -> V_44 . V_62 , F_1 ,
( unsigned long ) V_52 ) ;
F_26 ( & V_52 -> V_44 . V_63 , F_2 ,
( unsigned long ) V_52 ) ;
F_26 ( & V_52 -> V_64 , F_17 ,
( unsigned long ) V_52 ) ;
F_26 ( & V_52 -> V_50 . V_65 , V_66 ,
( unsigned long ) V_52 ) ;
F_26 ( & V_52 -> V_49 . V_65 ,
V_67 , ( unsigned long ) V_52 ) ;
F_21 ( V_52 ) ;
F_12 ( & V_52 -> V_44 . V_18 , & V_4 -> V_60 ) ;
V_52 ++ ;
}
F_25 ( & V_4 -> V_68 ) ;
F_25 ( & V_4 -> V_69 ) ;
F_25 ( & V_4 -> V_70 ) ;
for( V_56 = 0 ; V_56 < V_61 ; V_56 ++ )
{
V_53 -> V_6 = V_56 ;
F_25 ( & V_53 -> V_15 ) ;
F_26 ( & V_53 -> V_44 . V_62 , F_1 ,
( unsigned long ) V_53 ) ;
F_26 ( & V_53 -> V_44 . V_63 , F_2 ,
( unsigned long ) V_53 ) ;
F_26 ( & V_53 -> V_51 . V_65 ,
V_71 , ( unsigned long ) V_53 ) ;
F_26 ( & V_53 -> V_26 , F_3 ,
( unsigned long ) V_53 ) ;
F_23 ( V_53 ) ;
F_12 ( & V_53 -> V_44 . V_18 , & V_4 -> V_70 ) ;
V_53 ++ ;
}
F_25 ( & V_4 -> V_23 ) ;
for( V_56 = 0 ; V_56 < V_72 ; V_56 ++ )
{
F_12 ( & V_54 -> V_18 , & V_4 -> V_23 ) ;
if( V_56 == ( V_72 - 1 ) )
break;
V_54 = & V_4 -> V_55 [ V_56 + 1 ] ;
}
}
static void F_27 ( struct V_3 * V_4 ,
T_5 V_34 , T_6 V_73 )
{
F_28 ( & V_34 -> V_62 ) ;
F_28 ( & V_34 -> V_63 ) ;
if( V_73 != 0 )
F_15 ( & V_34 -> V_63 ,
V_27 + F_16 ( V_73 ) ) ;
}
static T_5 F_29 ( struct V_3 * V_4 ,
T_3 * V_35 , T_3 V_74 ,
T_7 V_75 )
{
T_3 V_76 ;
bool V_77 [ 4 ] = { 0 } ;
struct V_78 * V_79 ;
T_5 V_80 = NULL ;
if( V_4 -> V_81 == V_82 )
{
if( V_75 == V_83 )
{
V_77 [ V_84 ] = true ;
V_77 [ V_85 ] = true ;
}
else
{
V_77 [ V_86 ] = true ;
V_77 [ V_85 ] = true ;
}
}
else if( V_4 -> V_81 == V_87 )
{
if( V_75 == V_83 )
V_77 [ V_86 ] = true ;
else
V_77 [ V_84 ] = true ;
}
else
{
if( V_75 == V_83 )
{
V_77 [ V_86 ] = true ;
V_77 [ V_85 ] = true ;
V_77 [ V_88 ] = true ;
}
else
{
V_77 [ V_84 ] = true ;
V_77 [ V_85 ] = true ;
V_77 [ V_88 ] = true ;
}
}
if( V_75 == V_83 )
V_79 = & V_4 -> V_58 ;
else
V_79 = & V_4 -> V_68 ;
for( V_76 = 0 ; V_76 <= V_85 ; V_76 ++ )
{
if ( ! V_77 [ V_76 ] )
continue;
F_30 (pRet, psearch_list, List) {
if ( memcmp ( V_80 -> V_35 , V_35 , 6 ) == 0 )
if ( V_80 -> V_36 . V_89 . V_90 . V_91 . V_92 == V_74 )
if( V_80 -> V_36 . V_89 . V_90 . V_91 . V_93 == V_76 )
{
break;
}
}
if( & V_80 -> V_18 != V_79 )
break;
}
if( & V_80 -> V_18 != V_79 ) {
return V_80 ;
}
else
return NULL ;
}
static void F_31 ( T_5 V_34 , T_3 * V_35 ,
T_8 V_94 , T_9 V_95 , T_3 V_96 ,
T_3 V_97 )
{
T_3 V_56 ;
if( V_34 == NULL )
return;
memcpy ( V_34 -> V_35 , V_35 , 6 ) ;
if( V_94 != NULL )
memcpy ( ( T_3 * ) ( & ( V_34 -> V_36 ) ) , ( T_3 * ) V_94 , sizeof( V_37 ) ) ;
for( V_56 = 0 ; V_56 < V_96 ; V_56 ++ )
memcpy ( ( T_3 * ) ( & ( V_34 -> V_38 [ V_56 ] ) ) , ( T_3 * ) V_95 , sizeof( V_39 ) ) ;
V_34 -> V_41 = V_97 ;
V_34 -> V_42 = V_96 ;
}
bool F_32 (
struct V_3 * V_4 ,
T_5 * V_98 ,
T_3 * V_35 ,
T_3 V_74 ,
T_7 V_75 ,
bool V_99
)
{
T_3 V_100 = 0 ;
if ( F_33 ( V_35 ) )
{
F_6 ( V_25 , L_6 ) ;
return false ;
}
if ( V_4 -> V_101 . V_102 . V_103 == 0 )
V_100 = 0 ;
else
{
if ( ! F_34 ( V_74 ) )
{
F_6 ( V_25 , L_7 , V_13 , V_74 ) ;
return false ;
}
switch ( V_74 )
{
case 0 :
case 3 :
V_100 = 0 ;
break;
case 1 :
case 2 :
V_100 = 2 ;
break;
case 4 :
case 5 :
V_100 = 5 ;
break;
case 6 :
case 7 :
V_100 = 7 ;
break;
}
}
* V_98 = F_29 (
V_4 ,
V_35 ,
V_100 ,
V_75 ) ;
if( * V_98 != NULL )
{
return true ;
}
else
{
if ( ! V_99 ) {
F_6 ( V_57 , L_8 , V_100 ) ;
return false ;
}
else
{
V_37 V_36 ;
T_10 V_104 = & V_36 . V_89 . V_90 ;
struct V_78 * V_105 =
( V_75 == V_83 ) ?
( & V_4 -> V_60 ) :
( & V_4 -> V_70 ) ;
struct V_78 * V_106 =
( V_75 == V_83 ) ?
( & V_4 -> V_58 ) :
( & V_4 -> V_68 ) ;
T_11 V_107 = ( V_4 -> V_81 == V_82 ) ?
( ( V_75 == V_83 ) ? V_84 : V_86 ) :
( ( V_75 == V_83 ) ? V_86 : V_84 ) ;
F_6 ( V_57 , L_9 ) ;
if( ! F_7 ( V_105 ) )
{
( * V_98 ) = F_8 ( V_105 -> V_108 , V_109 , V_18 ) ;
F_11 ( & ( * V_98 ) -> V_18 ) ;
if( V_75 == V_83 )
{
T_4 V_110 = F_4 ( * V_98 , V_111 , V_44 ) ;
F_21 ( V_110 ) ;
}
else{
T_1 V_110 = F_4 ( * V_98 , V_112 , V_44 ) ;
F_23 ( V_110 ) ;
}
F_6 ( V_57 , L_10 , V_100 , V_107 , V_35 ) ;
V_104 -> V_91 . V_113 = 0 ;
V_104 -> V_91 . V_92 = V_100 ;
V_104 -> V_91 . V_93 = V_107 ;
V_104 -> V_91 . V_114 = 1 ;
V_104 -> V_91 . V_115 = 0 ;
V_104 -> V_91 . V_116 = 0 ;
V_104 -> V_91 . V_117 = V_100 ;
V_104 -> V_91 . V_118 = 0 ;
V_104 -> V_91 . V_119 = 0 ;
F_31 ( * V_98 , V_35 , & V_36 , NULL , 0 , 0 ) ;
F_27 ( V_4 , * V_98 , 0 ) ;
F_12 ( & ( ( * V_98 ) -> V_18 ) , V_106 ) ;
return true ;
}
else
{
F_6 ( V_25 , L_11 , V_13 ) ;
return false ;
}
}
}
}
static void F_35 ( struct V_3 * V_4 , T_5 V_120 ,
T_7 V_75 )
{
unsigned long V_8 = 0 ;
F_28 ( & V_120 -> V_62 ) ;
F_28 ( & V_120 -> V_63 ) ;
F_36 ( V_4 , V_120 , V_75 ) ;
if( V_75 == V_121 )
{
T_2 V_54 ;
T_1 V_53 = ( T_1 ) V_120 ;
if( F_37 ( & V_53 -> V_26 ) )
F_28 ( & V_53 -> V_26 ) ;
while( ! F_7 ( & V_53 -> V_15 ) )
{
F_5 ( & ( V_4 -> V_11 ) , V_8 ) ;
V_54 = ( T_2 ) F_8 ( V_53 -> V_15 . V_16 , V_17 , V_18 ) ;
F_11 ( & V_54 -> V_18 ) ;
{
int V_122 = 0 ;
struct V_123 * V_22 = V_54 -> V_22 ;
if ( F_38 ( ! V_22 ) )
{
F_13 ( & ( V_4 -> V_11 ) , V_8 ) ;
return;
}
for( V_122 = 0 ; V_122 < V_22 -> V_124 ; V_122 ++ ) {
F_39 ( V_22 -> V_125 [ V_122 ] ) ;
}
F_40 ( V_22 ) ;
V_22 = NULL ;
}
F_12 ( & V_54 -> V_18 , & V_4 -> V_23 ) ;
F_13 ( & ( V_4 -> V_11 ) , V_8 ) ;
}
}
else
{
T_4 V_52 = ( T_4 ) V_120 ;
F_28 ( & V_52 -> V_64 ) ;
}
}
void F_41 ( struct V_3 * V_4 , T_3 * V_35 )
{
T_5 V_43 , V_126 ;
F_42 ( L_12 , V_35 ) ;
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Pending_List, List)
{
if ( memcmp ( V_43 -> V_35 , V_35 , 6 ) == 0 )
{
F_35 ( V_4 , V_43 , V_83 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_60 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Admit_List, List)
{
if ( memcmp ( V_43 -> V_35 , V_35 , 6 ) == 0 )
{
F_42 ( L_13 ) ;
F_35 ( V_4 , V_43 , V_83 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_60 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Pending_List, List)
{
if ( memcmp ( V_43 -> V_35 , V_35 , 6 ) == 0 )
{
F_35 ( V_4 , V_43 , V_121 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_70 ) ;
}
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Admit_List, List)
{
if ( memcmp ( V_43 -> V_35 , V_35 , 6 ) == 0 )
{
F_35 ( V_4 , V_43 , V_121 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_70 ) ;
}
}
}
void F_44 ( struct V_3 * V_4 )
{
T_5 V_43 , V_126 ;
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Pending_List, List)
{
F_35 ( V_4 , V_43 , V_83 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_60 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Tx_TS_Admit_List, List)
{
F_35 ( V_4 , V_43 , V_83 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_60 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Pending_List, List)
{
F_35 ( V_4 , V_43 , V_121 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_70 ) ;
}
F_43 (pTS, pTmpTS, &ieee->Rx_TS_Admit_List, List)
{
F_35 ( V_4 , V_43 , V_121 ) ;
F_11 ( & V_43 -> V_18 ) ;
F_12 ( & V_43 -> V_18 , & V_4 -> V_70 ) ;
}
}
void F_45 ( struct V_3 * V_4 , T_4 V_52 )
{
if( ! V_52 -> V_46 )
{
V_52 -> V_46 = true ;
if( V_52 -> V_47 )
{
F_6 ( V_33 , L_14 ) ;
F_15 ( & V_52 -> V_64 ,
V_27 + F_16 ( V_127 ) ) ;
}
else
{
F_6 ( V_33 , L_15 ) ;
F_15 ( & V_52 -> V_64 , V_27 + 10 ) ;
}
}
else
F_6 ( V_25 , L_16 , V_13 ) ;
}
