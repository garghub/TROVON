static T_1 * F_1 ( T_1 * * V_1 , T_1 * V_2 , BOOLEAN * V_3 , T_2 * V_4 )
{
T_1 * V_5 = NULL ;
T_1 * V_6 = NULL ;
T_2 V_7 = 0 ;
T_3 V_8 = F_2 ( V_9 ) ;
if( ( NULL == V_1 ) || ( * V_4 == 0 ) || ( * V_3 ) )
{
* V_3 = TRUE ;
return NULL ;
}
V_5 = * V_1 ;
V_6 = * V_1 ;
if( ! V_5 || ! V_6 )
{
* V_3 = TRUE ;
return NULL ;
}
* V_3 = FALSE ;
switch( * V_2 )
{
case V_10 :
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_1 ) ;
V_7 += sizeof( V_14 ) ;
}
break;
case V_15 :
{
T_4 * V_16 ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_2 ) ;
V_16 = ( T_4 * ) V_6 ;
V_7 += sizeof( T_4 ) ;
V_7 += V_16 -> V_17 * V_18 ;
}
break;
case V_19 :
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_3 ) ;
V_7 += sizeof( V_20 ) ;
}
break;
case V_21 :
{
T_5 * V_22 = ( T_5 * ) V_6 ;
int V_23 = V_22 -> V_24 ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_4 ) ;
V_7 += sizeof( T_5 ) ;
V_7 += V_23 * V_25 ;
}
break;
case V_26 :
{
T_6 * V_27 = ( T_6 * ) V_6 ;
int V_28 = V_27 -> V_29 ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_5 ) ;
V_7 += V_28 * 4 ;
}
break;
case V_30 :
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_6 ) ;
* V_3 = TRUE ;
}
break;
case V_31 :
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_7 ) ;
* V_3 = TRUE ;
}
break;
case V_32 :
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_8 ) ;
* V_3 = TRUE ;
}
break;
case V_33 :
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_9 ) ;
* V_3 = TRUE ;
}
break;
default :
{
* V_3 = TRUE ;
}
break;
}
if( * V_3 == FALSE )
{
if( * V_4 <= V_7 )
{
* V_3 = TRUE ;
}
else
{
* V_2 = * V_6 ;
V_6 += V_7 ;
( * V_4 ) -= V_7 ;
}
}
* V_1 = V_6 ;
return V_5 ;
}
static T_1 F_4 ( T_1 * V_34 , T_2 * V_35 , T_2 * V_36 , T_2 V_37 , T_1 V_38 )
{
T_1 * V_39 = V_34 ;
BOOLEAN V_40 = FALSE ;
T_1 V_41 = 0 ;
T_1 * V_2 = NULL ;
T_3 V_8 = F_2 ( V_9 ) ;
if( ! V_34 || ( V_37 == 0 ) )
{
return 0 ;
}
* V_35 = * V_36 = 0 ;
V_41 = V_38 ;
while( ! V_40 )
{
V_2 = F_1 ( & V_39 , & V_41 , & V_40 , & V_37 ) ;
if( V_40 )
{
if( ( V_41 == V_32 ) || ( V_41 == V_33 ) )
{
* V_35 = * ( ( V_42 ) ( V_2 ) ) ;
* V_36 = * ( ( V_42 ) ( V_2 + 2 ) ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_10 , F_5 ( * V_35 ) , F_5 ( * V_36 ) ) ;
}
break;
}
}
return V_41 ;
}
T_2 F_6 ( T_3 V_8 ,
T_7 V_43 ,
T_8 * V_44 )
{
T_2 V_45 = 0 ;
T_2 V_46 = 0 ;
T_1 V_47 = 0 ;
T_9 * V_48 = NULL ;
BOOLEAN V_49 = FALSE ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_11 ) ;
V_48 = ( T_9 * ) V_43 ;
F_7 ( V_48 ) ;
V_47 = F_4 ( ( T_1 * ) ( V_43 + sizeof( T_9 ) ) ,
& V_46 ,
& V_45 ,
V_48 -> V_37 ,
V_48 -> V_38 ) ;
do
{
if( 0 == V_44 -> V_50 )
{
break;
}
if( ! V_44 -> V_51 )
{
break;
}
V_49 = F_8 ( V_44 , V_48 ) ;
if( ! V_49 )
break;
V_49 = F_9 ( V_44 , V_48 ) ;
if( ! V_49 )
break;
V_49 = F_10 ( V_44 , V_47 ) ;
if( ! V_49 )
break;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_12 ) ;
if( ( V_47 == V_32 ) || ( V_47 == V_33 ) )
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_13 , F_5 ( V_46 ) ) ;
V_49 = F_11 ( V_44 , F_5 ( V_46 ) ) ;
if( ! V_49 )
break;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_14 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_15 , F_5 ( V_45 ) ) ;
V_49 = F_12 ( V_44 , F_5 ( V_45 ) ) ;
if( ! V_49 )
break;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_16 ) ;
}
}while( 0 );
if( TRUE == V_49 )
{
INT V_52 = 0 ;
V_52 = F_13 ( V_8 , V_44 -> V_53 ) ;
if( V_52 >= V_54 )
{
V_49 = FALSE ;
}
else
{
if( FALSE == V_8 -> V_55 [ V_52 ] . V_56 )
{
V_49 = FALSE ;
}
}
}
return V_49 ;
}
static BOOLEAN F_8 ( T_8 * V_44 , T_9 * V_48 )
{
T_10 V_57 = 0 ;
T_10 V_58 = 0 ;
T_10 V_59 = 4 ;
T_11 V_60 [ 4 ] ;
T_3 V_8 = F_2 ( V_9 ) ;
T_10 V_61 = ( T_10 ) V_44 -> V_62 ;
if( 0 == V_61 )
return TRUE ;
for( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
{
V_60 [ V_58 ] = F_14 ( V_48 -> V_63 [ V_58 ] ) ;
}
for( V_57 = 0 ; V_57 < V_61 ; V_57 += V_59 )
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_17 ) ;
F_15 ( V_60 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_18 ) ;
F_15 ( & V_44 -> V_64 . V_65 [ V_57 ] ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_19 ) ;
F_15 ( & V_44 -> V_64 . V_66 [ V_57 ] ) ;
for( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
{
if( ( V_44 -> V_64 . V_65 [ V_57 + V_58 ] & V_60 [ V_58 ] )
!= V_44 -> V_64 . V_66 [ V_57 + V_58 ] )
{
break;
}
if( V_58 == V_59 - 1 )
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_20 ) ;
return TRUE ;
}
}
}
return FALSE ;
}
static BOOLEAN F_9 ( T_8 * V_44 , T_9 * V_48 )
{
T_10 V_57 = 0 ;
T_10 V_58 = 0 ;
T_10 V_59 = 4 ;
T_11 V_67 [ 4 ] ;
T_3 V_8 = F_2 ( V_9 ) ;
T_10 V_68 = ( T_10 ) V_44 -> V_69 ;
if( 0 == V_68 )
return TRUE ;
for( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
{
V_67 [ V_58 ] = F_14 ( V_48 -> V_70 [ V_58 ] ) ;
}
for( V_57 = 0 ; V_57 < V_68 ; V_57 += V_59 )
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_21 ) ;
F_15 ( V_67 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_22 ) ;
F_15 ( & V_44 -> V_71 . V_65 [ V_57 ] ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_23 ) ;
F_15 ( & V_44 -> V_71 . V_66 [ V_57 ] ) ;
for( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
{
if( ( V_44 -> V_71 . V_65 [ V_57 + V_58 ] & V_67 [ V_58 ] )
!= V_44 -> V_71 . V_66 [ V_57 + V_58 ] )
{
break;
}
if( V_58 == V_59 - 1 )
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_24 ) ;
return TRUE ;
}
}
}
return FALSE ;
}
VOID F_15 ( T_11 * V_72 )
{
T_10 V_59 = 4 ;
T_10 V_58 = 0 ;
T_3 V_8 = F_2 ( V_9 ) ;
for( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
{
F_3 ( V_8 , V_11 , V_12 , V_13 , L_25 , V_72 [ V_58 ] ) ;
}
}
static VOID F_7 ( T_9 * V_48 )
{
T_1 V_73 ;
T_1 V_74 ;
T_3 V_8 = F_2 ( V_9 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_26 ) ;
V_73 = V_48 -> V_75 & 0xf0 ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_27 , V_73 ) ;
V_74 = V_48 -> V_75 & 0x0f ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_28 , V_74 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_29 , F_5 ( V_48 -> V_37 ) ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_30 , V_48 -> V_38 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_31 , V_48 -> V_76 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_32 ) ;
F_15 ( V_48 -> V_63 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_33 ) ;
F_15 ( V_48 -> V_70 ) ;
F_3 ( V_8 , V_11 , V_12 , V_13 , L_34 ) ;
}
