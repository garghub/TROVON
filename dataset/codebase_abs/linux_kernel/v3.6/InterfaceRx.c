static int F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
int V_4 = 0 ;
for( V_4 = ( V_5 - 1 ) ; V_4 >= 0 ; V_4 -- )
if( V_2 -> V_6 [ V_4 ] . V_7 == V_3 )
return V_4 ;
return V_5 + 1 ;
}
static T_1
F_2 ( T_2 V_8 )
{
T_1 V_9 = NULL ;
T_3 V_10 = 0 ;
if( ( F_3 ( & V_8 -> V_11 ) < V_12 ) &&
( V_8 -> V_13 -> V_14 == FALSE ) )
{
V_10 = F_3 ( & V_8 -> V_15 ) ;
V_9 = & V_8 -> V_16 [ V_10 ] ;
V_9 -> V_17 = TRUE ;
V_9 -> V_8 = V_8 ;
F_4 ( V_8 -> V_13 , V_18 , V_19 , V_20 , L_1 ,
V_10 , F_3 ( & V_8 -> V_11 ) ) ;
V_10 = ( V_10 + 1 ) % V_12 ;
F_5 ( & V_8 -> V_15 , V_10 ) ;
F_6 ( & V_8 -> V_11 ) ;
}
return V_9 ;
}
static void F_7 ( struct V_21 * V_21 )
{
struct V_22 * V_23 = NULL ;
BOOLEAN V_24 = FALSE ;
int V_25 = V_5 + 1 ;
T_3 V_26 = 0 ;
int V_27 = 1 ;
T_1 V_9 = ( T_1 ) V_21 -> V_28 ;
T_2 V_8 = V_9 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_13 ;
struct V_29 * V_30 = V_21 -> V_31 ;
if ( F_8 ( F_9 ( V_2 ) ) )
F_10 ( V_32 L_2 ,
V_2 -> V_33 -> V_34 , V_21 -> V_35 , V_21 -> V_36 ) ;
if( ( V_2 -> V_37 == TRUE ) ||
( TRUE == V_2 -> V_38 ) ||
( 0 == V_21 -> V_36 )
)
{
V_9 -> V_17 = FALSE ;
F_11 ( & V_8 -> V_11 ) ;
return;
}
if( V_21 -> V_35 != V_39 )
{
if( V_21 -> V_35 == - V_40 )
{
V_2 -> V_38 = TRUE ;
F_12 ( & V_2 -> V_41 ) ;
}
else
{
F_4 ( V_2 , V_18 , V_19 , V_20 , L_3 , V_21 -> V_35 ) ;
}
V_9 -> V_17 = FALSE ;
F_11 ( & V_8 -> V_11 ) ;
V_21 -> V_35 = V_39 ;
return ;
}
if( V_2 -> V_42 && ( V_2 -> V_43 ) )
{
F_4 ( V_2 , V_18 , V_19 , V_20 , L_4 ) ;
return ;
}
F_4 ( V_2 , V_18 , V_19 , V_20 , L_5 , V_30 -> V_44 ) ;
if( ! V_30 -> V_44 )
{
F_4 ( V_2 , V_18 , V_19 , V_20 , L_6 ) ;
F_11 ( & V_8 -> V_11 ) ;
return;
}
F_4 ( V_2 , V_18 , V_19 , V_20 , L_7 , V_30 -> V_45 , V_30 -> V_44 , V_30 -> V_46 ) ;
if( V_47 < V_30 -> V_44 )
{
if ( F_13 ( V_2 ) )
F_10 ( V_32 L_8 ,
V_2 -> V_33 -> V_34 , V_30 -> V_44 ) ;
++ V_2 -> V_33 -> V_48 . V_49 ;
F_11 ( & V_8 -> V_11 ) ;
return;
}
V_25 = F_1 ( V_2 , V_30 -> V_46 ) ;
if( V_25 < V_5 )
{
V_24 =
V_2 -> V_6 [ V_25 ] . V_50 ;
V_24 =
V_24 & V_2 -> V_51 ;
}
V_23 = F_14 ( V_30 -> V_44 + V_52 + V_53 ) ;
if( ! V_23 )
{
F_4 ( V_2 , V_54 , 0 , 0 , L_9 ) ;
F_11 ( & V_8 -> V_11 ) ;
return;
}
if( ( F_15 ( V_30 -> V_46 ) == V_55 ) ||
( ! ( V_30 -> V_45 >= 0x20 && V_30 -> V_45 <= 0x3F ) ) )
{
F_4 ( V_8 -> V_13 , V_18 , V_56 , V_20 , L_10 ) ;
* ( V_57 ) V_23 -> V_58 = V_30 -> V_45 ;
memcpy ( V_23 -> V_58 + sizeof( V_59 ) , V_21 -> V_31 +
( sizeof( struct V_29 ) ) , V_30 -> V_44 ) ;
V_23 -> V_60 = V_30 -> V_44 + sizeof( V_59 ) ;
F_16 ( & V_2 -> V_61 ) ;
F_17 ( V_2 -> V_62 , V_2 -> V_63 , V_23 ) ;
F_18 ( & V_2 -> V_61 ) ;
F_6 ( & V_2 -> V_64 ) ;
F_12 ( & V_2 -> V_65 ) ;
}
else
{
F_4 ( V_8 -> V_13 , V_18 , V_66 , V_20 , L_11 ) ;
F_19 ( V_23 , 2 + V_52 ) ;
memcpy ( V_23 -> V_58 + V_67 , ( V_68 ) V_21 -> V_31 + sizeof( struct V_29 ) , V_30 -> V_44 ) ;
V_23 -> V_33 = V_2 -> V_33 ;
F_20 ( V_23 , V_30 -> V_44 + V_67 ) ;
V_2 -> V_6 [ V_25 ] . V_69 += V_30 -> V_44 ;
V_2 -> V_6 [ V_25 ] . V_70 += V_30 -> V_44 ;
F_4 ( V_8 -> V_13 , V_18 , V_66 , V_20 , L_12 , V_30 -> V_44 ) ;
if( F_21 ( V_2 -> V_33 ) )
{
F_22 ( V_23 , V_67 ) ;
F_23 ( V_2 , V_30 -> V_46 , V_23 , & V_23 -> V_60 ,
NULL , V_24 ) ;
if( ! V_2 -> V_6 [ V_25 ] . V_71 )
{
F_24 ( V_23 , V_67 ) ;
memcpy ( V_23 -> V_58 , V_23 -> V_33 -> V_72 , 6 ) ;
memcpy ( V_23 -> V_58 + 6 , V_23 -> V_33 -> V_72 , 6 ) ;
( * ( V_23 -> V_58 + 11 ) ) ++ ;
* ( V_23 -> V_58 + 12 ) = 0x08 ;
* ( V_23 -> V_58 + 13 ) = 0x00 ;
V_30 -> V_44 += V_67 ;
}
V_23 -> V_73 = F_25 ( V_23 , V_2 -> V_33 ) ;
V_27 = F_26 ( V_23 ) ;
}
else
{
F_4 ( V_8 -> V_13 , V_18 , V_66 , V_20 , L_13 ) ;
F_27 ( V_23 ) ;
}
++ V_2 -> V_33 -> V_48 . V_74 ;
V_2 -> V_33 -> V_48 . V_75 += V_30 -> V_44 ;
for( V_26 = 0 ; V_26 < V_76 ; V_26 ++ )
{
if( ( V_30 -> V_44 <= V_77 * ( V_26 + 1 ) )
&& ( V_30 -> V_44 > V_77 * ( V_26 ) ) )
V_2 -> V_78 [ V_26 ] ++ ;
}
}
V_2 -> V_79 ++ ;
V_9 -> V_17 = FALSE ;
F_11 ( & V_8 -> V_11 ) ;
}
static int F_28 ( T_2 V_8 , T_1 V_9 )
{
struct V_21 * V_21 = V_9 -> V_21 ;
int V_80 = 0 ;
F_29 ( V_21 , V_8 -> V_81 , F_30 (
V_8 -> V_81 , V_8 -> V_82 . V_83 ) ,
V_21 -> V_31 , V_84 , F_7 ,
V_9 ) ;
if( FALSE == V_8 -> V_13 -> V_37 &&
FALSE == V_8 -> V_13 -> V_38 &&
FALSE == V_8 -> V_85 &&
FALSE == V_8 -> V_86 )
{
V_80 = F_31 ( V_21 , V_87 ) ;
if ( V_80 )
{
F_4 ( V_8 -> V_13 , V_18 , V_19 , V_20 , L_14 , V_80 ) ;
if( V_80 == - V_40 )
{
V_8 -> V_13 -> V_38 = TRUE ;
F_12 ( & V_8 -> V_13 -> V_41 ) ;
}
}
}
return V_80 ;
}
BOOLEAN F_32 ( T_2 V_8 )
{
V_59 V_88 = V_89 - F_3 ( & V_8 -> V_11 ) ;
T_1 V_9 = NULL ;
while( V_88 )
{
V_9 = F_2 ( V_8 ) ;
if( V_9 == NULL )
{
F_4 ( V_8 -> V_13 , V_54 , 0 , 0 , L_15 ) ;
return FALSE ;
}
F_28 ( V_8 , V_9 ) ;
V_88 -- ;
}
return TRUE ;
}
