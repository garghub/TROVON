static void F_1 ( T_1 V_1 , T_2 V_2 )
{
char * V_3 = ( V_4 ) V_5 ;
int V_6 = 0 ;
while ( * V_1 != '\1' && * V_1 != '\0' && V_6 < V_2 )
{
if ( * V_1 < ' ' )
{
* V_3 = ' ' ;
}
else
{
* V_3 = * V_1 ;
}
V_3 ++ ;
V_1 ++ ;
V_6 ++ ;
}
* V_3 = '\0' ;
#if 0
appMsg = (I8_P)m_pCurQuery;
#endif
if ( F_2 ( ( V_4 ) V_5 , L_1 , 6 ) == 0 )
{
V_7 ++ ;
#if 0
pSummaryStat->m_numOfUpdate++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfUpdate++;
#endif
}
else if ( F_2 ( ( V_4 ) V_5 , L_2 , 6 ) == 0 )
{
V_8 ++ ;
#if 0
pSummaryStat->m_numOfSelect++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfSelect++;
#endif
}
else if ( F_2 ( ( V_4 ) V_5 , L_3 , 6 ) == 0 )
{
V_9 ++ ;
#if 0
pSummaryStat->m_numOfInsert++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfInsert++;
#endif
}
else if ( F_2 ( ( V_4 ) V_5 , L_4 , 6 ) == 0 )
{
V_10 ++ ;
#if 0
pSummaryStat->m_numOfDelete++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfDelete++;
#endif
}
else if ( F_2 ( ( V_4 ) V_5 , L_5 , 8 ) == 0 )
{
V_11 ++ ;
#if 0
pSummaryStat->m_numOfRollback++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfRollback++;
#endif
}
else if ( F_2 ( ( V_4 ) V_5 , L_6 , 3 ) == 0 )
{
V_12 ++ ;
#if 0
pSummaryStat->m_numOfSet++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfSet++;
#endif
}
else if ( F_2 ( ( V_4 ) V_5 , L_7 , 5 ) == 0 )
{
V_13 ++ ;
#if 0
pSummaryStat->m_numOfStart++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfStart++;
#endif
}
else if ( F_2 ( ( V_4 ) V_5 , L_8 , 6 ) == 0 )
{
V_14 ++ ;
#if 0
pSummaryStat->m_numOfCommit++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfCommit++;
#endif
}
else
{
V_15 ++ ;
#if 0
pSummaryStat->m_numOfOtherStatement++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfOtherStatement++;
#endif
}
V_16 ++ ;
#if 0
m_pSummaryStat->m_numOfTransaction++;
if (m_pServerNode != NULL)
m_pServerNode->m_numOfTransaction++;
#endif
}
static T_3 F_3 ( T_1 * V_17 , T_2 * V_18 , int V_19 )
{
T_1 V_20 = * V_17 ;
T_3 V_21 = isalpha ( V_20 [ 0 ] ) != 0 ;
T_3 V_22 = isalpha ( V_20 [ 1 ] ) != 0 ;
T_3 V_23 = isalpha ( V_20 [ 2 ] ) != 0 ;
T_3 V_24 = isalpha ( V_20 [ 3 ] ) != 0 ;
T_3 V_25 = FALSE ;
T_2 V_2 = * V_18 ;
while ( ( V_2 > 2 ) && ( V_19 > 0 ) && ( ( V_21 == FALSE ) || ( V_22 == FALSE ) || ( V_23 == FALSE ) || ( V_24 == FALSE ) ) )
{
if ( V_25 )
{
if ( * ( ( V_26 ) V_20 ) == 0x2F2A )
{
V_25 = FALSE ;
V_20 ++ ;
V_2 -- ;
}
V_20 ++ ;
V_2 -- ;
}
else
{
if ( * ( ( V_26 ) V_20 ) == 0x2A2F )
{
V_25 = TRUE ;
V_2 -= 2 ;
V_20 += 2 ;
V_22 = isalpha ( V_20 [ 1 ] ) != 0 ;
V_23 = isalpha ( V_20 [ 2 ] ) != 0 ;
V_24 = isalpha ( V_20 [ 3 ] ) != 0 ;
continue;
}
V_20 ++ ;
V_21 = V_22 ;
V_22 = isalpha ( V_20 [ 1 ] ) != 0 ;
V_23 = isalpha ( V_20 [ 2 ] ) != 0 ;
V_24 = isalpha ( V_20 [ 3 ] ) != 0 ;
V_2 -- ;
if ( * ( ( T_1 ) V_20 ) != 0x0 )
V_19 -- ;
}
}
if ( V_21 && V_22 && V_23 && V_24 )
{
* V_17 = V_20 ;
* V_18 = V_2 ;
return TRUE ;
}
else
return FALSE ;
}
static T_3 F_4 ( T_4 * V_27 , T_5 * V_28 , int V_29 , T_6 * V_30 , T_2 V_2 )
{
T_7 V_31 [ 1024 ] ;
T_2 V_32 = V_2 ;
int V_6 ;
T_1 V_33 ;
for ( V_6 = 0 ; V_6 < 1024 ; V_6 ++ )
{
V_31 [ V_6 ] = '\0' ;
}
F_5 ( V_28 , V_31 , V_29 , V_2 ) ;
V_33 = ( T_1 ) V_31 ;
if ( F_3 ( ( T_1 * ) & V_33 , & V_32 , 0x30 ) == TRUE )
{
F_1 ( V_33 , V_2 ) ;
if ( V_27 )
F_6 ( V_27 , V_28 , V_29 + V_2 - V_32 , V_32 ,
L_9 , V_5 ) ;
F_7 ( V_30 -> V_34 , V_35 ) ;
if ( F_8 ( V_30 -> V_34 , V_35 ) )
F_9 ( V_30 -> V_34 , V_35 , V_5 ) ;
return TRUE ;
}
return FALSE ;
}
static void
F_10 ( T_5 * V_28 , T_6 * V_30 , T_4 * V_27 )
{
T_8 * V_36 = NULL ;
T_4 * V_37 = NULL ;
int V_29 = 0 , V_2 , V_38 , V_39 , V_40 , V_41 , V_42 ;
T_9 V_43 , V_44 = 0 ;
V_5 [ 0 ] = '0' ;
V_30 -> V_45 = L_10 ;
F_11 ( V_30 -> V_34 , V_46 , L_11 ) ;
F_7 ( V_30 -> V_34 , V_35 ) ;
V_43 = F_12 ( V_28 , V_29 ) ;
V_2 = F_13 ( V_28 , V_29 ) ;
if ( V_43 != V_47 )
V_44 = F_12 ( V_28 , V_29 + 1 ) ;
if ( F_8 ( V_30 -> V_34 , V_35 ) )
{
F_14 ( V_30 -> V_34 , V_35 , L_12 , F_15 ( V_43 , V_48 , L_13 ) ) ;
}
if ( V_27 )
{
V_36 = F_16 ( V_27 , V_49 , V_28 , 0 , - 1 , V_50 ) ;
V_37 = F_17 ( V_36 , V_51 ) ;
F_18 ( V_37 , V_52 , V_28 , V_29 , 1 , V_43 ) ;
if ( V_44 && V_43 != V_53 )
F_18 ( V_37 , V_54 , V_28 , V_29 + 1 , 1 , V_44 ) ;
}
switch ( V_43 )
{
case V_55 :
if ( F_8 ( V_30 -> V_34 , V_35 ) )
{
F_19 ( V_30 -> V_34 , V_35 , L_14 , F_15 ( V_44 , V_56 , L_13 ) ) ;
}
switch ( V_44 )
{
case V_57 :
F_4 ( V_37 , V_28 , V_29 + 0x0B , V_30 , V_2 - 0x0B ) ;
break;
case V_58 :
case V_59 :
if ( V_2 > ( 0x19 + 8 ) )
{
if ( F_4 ( V_37 , V_28 , V_29 + 0x12 , V_30 , V_2 - 0x12 ) == TRUE )
break;
}
break;
case V_60 :
if ( V_2 > ( 0x2A + 8 ) )
{
if ( F_4 ( V_37 , V_28 , V_29 + 0x2A , V_30 , V_2 - 0x2A ) == TRUE )
break;
}
break;
case V_61 :
if ( V_2 > ( 0x2A + 8 ) )
{
if ( F_4 ( V_37 , V_28 , V_29 + 0x14 , V_30 , V_2 - 0x14 ) == TRUE )
{
if ( F_8 ( V_30 -> V_34 , V_35 ) )
F_9 ( V_30 -> V_34 , V_35 , V_5 ) ;
break;
}
else
if ( F_4 ( V_37 , V_28 , V_29 + 0x30 , V_30 , V_2 - 0x30 ) == TRUE )
break;
}
break;
}
break;
case V_53 :
V_40 = V_44 ;
F_18 ( V_37 , V_62 , V_28 , V_29 + 1 , 1 , V_40 ) ;
V_38 = F_12 ( V_28 , V_29 + 2 ) ;
V_41 = F_12 ( V_28 , V_29 + 3 ) ;
V_39 = F_20 ( V_28 , V_29 + 5 ) ;
V_42 = F_20 ( V_28 , V_29 + 7 ) ;
F_18 ( V_37 , V_63 , V_28 , V_29 + 2 , 1 , V_38 ) ;
F_18 ( V_37 , V_64 , V_28 , V_29 + 3 , 1 , V_41 ) ;
F_18 ( V_37 , V_65 , V_28 , V_29 + 5 , 2 , V_39 ) ;
F_18 ( V_37 , V_66 , V_28 , V_29 + 7 , 2 , V_42 ) ;
break;
default:
return;
break;
}
}
void
F_21 ( void )
{
static T_10 V_67 [] =
{
{ & V_52 ,
{ L_15 , L_16 , V_68 , V_69 , F_22 ( V_48 ) , 0x0 , NULL , V_70 }
} ,
{ & V_54 ,
{ L_17 , L_18 , V_68 , V_69 , F_22 ( V_56 ) , 0x0 , NULL , V_70 }
} ,
{ & V_62 ,
{ L_19 , L_20 , V_68 , V_69 , NULL , 0x0 , NULL , V_70 }
} ,
{ & V_63 ,
{ L_21 , L_22 , V_68 , V_69 , NULL , 0x0 , NULL , V_70 }
} ,
{ & V_64 ,
{ L_23 , L_24 , V_71 , V_69 , NULL , 0x0 , NULL , V_70 }
} ,
{ & V_65 ,
{ L_25 , L_26 , V_71 , V_69 , NULL , 0x0 , NULL , V_70 }
} ,
{ & V_66 ,
{ L_27 , L_28 , V_71 , V_69 , NULL , 0x0 , NULL , V_70 }
} ,
{ & V_72 ,
{ L_29 , L_30 , V_73 , V_74 , NULL , 0x0 , NULL , V_70 }
} ,
} ;
static T_11 * V_75 [] =
{
& V_51 ,
& V_76 ,
} ;
V_49 = F_23 ( L_31 , L_11 , L_32 ) ;
F_24 ( V_49 , V_67 , F_25 ( V_67 ) ) ;
F_26 ( V_75 , F_25 ( V_75 ) ) ;
F_27 ( L_32 , F_10 , V_49 ) ;
}
void
F_28 ( void )
{
T_12 V_77 ;
V_77 = F_29 ( L_32 ) ;
F_30 ( L_33 , V_78 , V_77 ) ;
}
