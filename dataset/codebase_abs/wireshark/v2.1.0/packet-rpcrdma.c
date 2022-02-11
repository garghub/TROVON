static T_1 F_1 ( T_2 * V_1 , T_1 V_2 , T_3 * V_3 ,
int V_4 , const char * V_5 , T_4 V_6 )
{
T_5 * V_7 ;
T_3 * V_8 ;
T_6 V_9 , V_10 , V_11 , V_12 ;
V_9 = F_2 ( V_1 , V_2 ) ;
V_7 = F_3 ( V_3 , V_4 , V_1 , V_2 , 4 , V_9 ,
L_1 , V_5 , V_9 ) ;
V_2 += 4 ;
V_8 = F_4 ( V_7 , V_13 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; ++ V_10 ) {
V_11 = F_2 ( V_1 , V_2 ) ;
V_2 += 4 ;
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 ) {
if ( V_6 ) {
F_5 ( V_8 , V_14 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
}
F_5 ( V_8 , V_16 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
F_5 ( V_8 , V_17 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
F_5 ( V_8 , V_18 , V_1 ,
V_2 , 8 , V_15 ) ;
V_2 += 8 ;
}
}
return V_2 ;
}
static T_1 F_6 ( T_2 * V_1 , T_1 V_2 , T_3 * V_3 )
{
V_2 = F_1 ( V_1 , V_2 , V_3 , V_19 , L_2 , TRUE ) ;
V_2 = F_1 ( V_1 , V_2 , V_3 , V_20 , L_3 , FALSE ) ;
V_2 = F_1 ( V_1 , V_2 , V_3 , V_21 , L_4 , FALSE ) ;
return V_2 ;
}
static T_4
F_7 ( T_2 * V_1 , T_1 V_2 , T_1 V_22 , T_1 V_23 , T_1 * V_24 )
{
T_6 V_9 , V_10 , V_11 , V_25 ;
if ( V_2 + 4 > V_22 )
return FALSE ;
V_9 = F_2 ( V_1 , V_2 ) ;
V_2 += 4 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_2 + 4 > V_22 )
return FALSE ;
V_11 = F_2 ( V_1 , V_2 ) ;
V_2 += 4 ;
V_25 = V_2 + V_11 * ( 16 + V_23 ) ;
if ( ( V_25 > V_22 ) || ( V_25 < V_2 ) )
return FALSE ;
V_2 = V_25 ;
}
F_8 ( V_2 <= V_22 ) ;
* V_24 = V_2 ;
return TRUE ;
}
static T_4
F_9 ( T_2 * V_1 , T_1 V_2 , T_1 V_22 , T_1 * V_24 )
{
if ( ! F_7 ( V_1 , V_2 , V_22 , 4 , V_24 ) )
return FALSE ;
if ( ! F_7 ( V_1 , * V_24 , V_22 , 0 , V_24 ) )
return FALSE ;
return F_7 ( V_1 , * V_24 , V_22 , 0 , V_24 ) ;
}
static T_4
F_10 ( T_2 * V_1 )
{
T_1 V_22 = F_11 ( V_1 ) ;
T_6 V_26 ;
T_6 V_27 = F_2 ( V_1 , 0 ) ;
T_6 V_28 = F_2 ( V_1 , 12 ) ;
T_1 V_2 ;
switch ( V_28 ) {
case V_29 :
if ( V_22 < V_30 )
return FALSE ;
if ( ! F_9 ( V_1 , V_31 , V_22 , & V_2 ) )
return FALSE ;
if ( V_2 + 4 > V_22 )
return FALSE ;
V_26 = F_2 ( V_1 , V_2 ) ;
if ( V_27 != V_26 )
return FALSE ;
break;
case V_32 :
if ( V_22 < V_33 )
return FALSE ;
if ( ! F_9 ( V_1 , V_31 + 8 , V_22 , & V_2 ) )
return FALSE ;
if ( V_2 + 4 > V_22 )
return FALSE ;
V_26 = F_2 ( V_1 , V_2 ) ;
if ( V_27 != V_26 )
return FALSE ;
break;
default:
break;
}
return TRUE ;
}
static int
F_12 ( T_2 * V_1 , T_7 * V_34 , T_3 * V_3 )
{
T_2 * V_35 ;
T_5 * V_36 ;
T_3 * V_37 ;
T_1 V_2 = 0 ;
T_6 V_27 ;
T_6 V_28 ;
T_6 V_11 ;
if ( F_11 ( V_1 ) < V_31 )
return 0 ;
if ( F_2 ( V_1 , 4 ) != 1 )
return 0 ;
V_28 = F_2 ( V_1 , 12 ) ;
if ( V_28 > V_38 )
return 0 ;
if ( ! F_10 ( V_1 ) )
return F_13 ( V_39 , V_1 , V_34 , V_3 ) ;
V_27 = F_2 ( V_1 , 0 ) ;
F_14 ( V_34 -> V_40 , V_41 , L_5 ) ;
F_15 ( V_34 -> V_40 , V_42 , L_6 ,
F_16 ( V_28 , V_43 , L_7 ) , V_27 ) ;
if ( V_3 ) {
V_36 = F_5 ( V_3 , V_44 , V_1 , 0 , V_31 , V_45 ) ;
V_37 = F_4 ( V_36 , V_46 ) ;
F_5 ( V_37 , V_47 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
F_5 ( V_37 , V_48 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
F_5 ( V_37 , V_49 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
F_5 ( V_37 , V_50 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
switch ( V_28 ) {
case V_29 :
V_2 = F_6 ( V_1 , V_2 , V_37 ) ;
V_35 = F_17 ( V_1 , V_2 ) ;
return F_13 ( V_39 , V_35 , V_34 , V_3 ) ;
case V_51 :
V_2 = F_6 ( V_1 , V_2 , V_37 ) ;
break;
case V_32 :
F_5 ( V_37 , V_52 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
F_5 ( V_37 , V_53 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
V_2 = F_6 ( V_1 , V_2 , V_37 ) ;
V_35 = F_17 ( V_1 , V_2 ) ;
return F_13 ( V_39 , V_35 , V_34 , V_3 ) ;
case V_54 :
break;
case V_38 :
V_11 = F_2 ( V_1 , V_2 ) ;
F_5 ( V_37 , V_55 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
switch ( V_11 ) {
case V_56 :
F_5 ( V_37 , V_57 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
F_5 ( V_37 , V_58 , V_1 ,
V_2 , 4 , V_15 ) ;
V_2 += 4 ;
break;
case V_59 :
break;
default:
V_35 = F_17 ( V_1 , V_2 ) ;
return F_18 ( V_35 , V_34 , V_3 ) ;
}
break;
}
}
return V_2 ;
}
static int
F_19 ( T_2 * V_1 , T_7 * V_34 , T_3 * V_3 ,
void * T_8 V_60 )
{
return F_12 ( V_1 , V_34 , V_3 ) ;
}
static T_4
F_20 ( T_2 * V_1 , T_7 * V_34 , T_3 * V_3 ,
void * T_8 V_60 )
{
T_9 * V_61 ;
T_10 * V_62 = NULL ;
if ( V_63 ) {
if ( ( F_21 ( & V_34 -> V_64 , & V_65 [ 0 ] ) &&
F_21 ( & V_34 -> V_66 , & V_65 [ 1 ] ) &&
( V_34 -> V_67 == 0xffffffff || V_34 -> V_67 == V_68 [ 0 ] ) &&
( V_34 -> V_69 == 0xffffffff || V_34 -> V_69 == V_68 [ 1 ] ) ) ||
( F_21 ( & V_34 -> V_64 , & V_65 [ 1 ] ) &&
F_21 ( & V_34 -> V_66 , & V_65 [ 0 ] ) &&
( V_34 -> V_67 == 0xffffffff || V_34 -> V_67 == V_68 [ 1 ] ) &&
( V_34 -> V_69 == 0xffffffff || V_34 -> V_69 == V_68 [ 0 ] ) ) )
return ( F_12 ( V_1 , V_34 , V_3 ) != 0 ) ;
}
V_61 = F_22 ( V_34 -> V_70 , & V_34 -> V_64 , & V_34 -> V_66 ,
V_71 , V_34 -> V_67 , V_34 -> V_69 , 0 ) ;
if ( ! V_61 ) {
V_61 = F_22 ( V_34 -> V_70 , & V_34 -> V_66 , & V_34 -> V_66 ,
V_71 , V_34 -> V_69 , V_34 -> V_69 , V_72 | V_73 ) ;
if ( ! V_61 )
return FALSE ;
}
V_62 = ( T_10 * ) F_23 ( V_61 , V_74 ) ;
if ( ! V_62 )
return FALSE ;
if ( ( V_62 -> V_75 & V_76 ) != V_77 )
return FALSE ;
if ( ! ( F_24 ( V_78 , ( T_6 ) ( V_62 -> V_75 & V_79 ) ) ) )
return FALSE ;
V_61 = F_25 ( V_34 ) ;
F_26 ( V_61 , V_80 ) ;
return ( F_12 ( V_1 , V_34 , V_3 ) != 0 ) ;
}
void
F_27 ( void )
{
T_11 * V_81 ;
static T_12 V_82 [] = {
{ & V_47 ,
{ L_8 , L_9 ,
V_83 , V_84 ,
NULL , 0x0 , NULL , V_85 }
} ,
{ & V_48 ,
{ L_10 , L_11 ,
V_83 , V_84 ,
NULL , 0x0 , NULL , V_85 }
} ,
{ & V_49 ,
{ L_12 , L_13 ,
V_83 , V_84 ,
NULL , 0x0 , NULL , V_85 }
} ,
{ & V_50 ,
{ L_14 , L_15 ,
V_83 , V_84 ,
F_28 ( V_43 ) , 0x0 , NULL , V_85 }
} ,
{ & V_19 ,
{ L_16 , L_17 ,
V_83 , V_86 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_20 ,
{ L_18 , L_19 ,
V_83 , V_86 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_21 ,
{ L_20 , L_21 ,
V_83 , V_86 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_16 ,
{ L_22 , L_23 ,
V_83 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_17 ,
{ L_24 , L_25 ,
V_83 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_18 ,
{ L_26 , L_27 ,
V_87 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_14 ,
{ L_28 , L_29 ,
V_83 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_52 ,
{ L_30 , L_31 ,
V_83 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_53 ,
{ L_32 , L_33 ,
V_83 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_55 ,
{ L_34 , L_35 ,
V_83 , V_84 ,
F_28 ( V_88 ) , 0 , NULL , V_85 }
} ,
{ & V_57 ,
{ L_36 , L_37 ,
V_83 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
{ & V_58 ,
{ L_38 , L_39 ,
V_83 , V_84 ,
NULL , 0 , NULL , V_85 }
} ,
} ;
static T_13 * V_89 [] = {
& V_46 ,
& V_13 ,
} ;
V_44 = F_29 (
L_40 ,
L_5 ,
L_41
) ;
F_30 ( V_44 , V_82 , F_31 ( V_82 ) ) ;
F_32 ( V_89 , F_31 ( V_89 ) ) ;
V_81 = F_33 ( V_44 , V_90 ) ;
F_34 ( V_81 , L_42 , L_43 ,
L_44 ,
& V_63 ) ;
F_35 ( V_81 , L_45 , L_46 ,
L_47 ) ;
F_36 ( V_81 , L_48 , L_49 ,
L_50 , & V_91 [ 0 ] , V_92 , FALSE ) ;
F_37 ( V_81 , L_51 , L_52 ,
L_53 , & V_93 [ 0 ] ) ;
F_38 ( V_81 , L_54 , L_55 ,
L_56 , 10 , & V_68 [ 0 ] ) ;
F_35 ( V_81 , L_57 , L_58 ,
L_59 ) ;
F_36 ( V_81 , L_60 , L_49 ,
L_50 , & V_91 [ 1 ] , V_92 , FALSE ) ;
F_37 ( V_81 , L_61 , L_52 ,
L_62 , & V_93 [ 1 ] ) ;
F_38 ( V_81 , L_63 , L_55 ,
L_64 , 10 , & V_68 [ 1 ] ) ;
F_39 ( & V_78 , V_94 , V_95 ) ;
F_40 ( V_81 ,
L_65 ,
L_66 ,
L_67
L_68 V_94 L_69 ,
& V_78 , V_95 ) ;
}
void
V_90 ( void )
{
static T_4 V_96 = FALSE ;
if ( ! V_96 ) {
V_80 = F_41 ( F_19 , V_44 ) ;
F_42 ( L_70 , F_20 , L_71 , L_72 , V_44 , V_97 ) ;
F_42 ( L_73 , F_20 , L_74 , L_75 , V_44 , V_97 ) ;
V_98 [ 0 ] = F_43 ( F_44 () , V_99 ) ;
V_98 [ 1 ] = F_43 ( F_44 () , V_99 ) ;
V_39 = F_45 ( L_76 , V_44 ) ;
V_100 = F_45 ( L_77 , V_44 ) ;
V_74 = F_46 ( V_100 ) ;
V_96 = TRUE ;
}
if ( V_63 ) {
T_4 V_101 = FALSE ;
char * V_102 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( V_91 [ V_10 ] == 0 ) {
V_103 = 0 ;
* ( ( V_104 * ) V_98 [ V_10 ] ) = ( V_104 ) strtoul ( V_93 [ V_10 ] , & V_102 , 0 ) ;
if ( V_103 || * V_102 != '\0' ) {
V_101 = TRUE ;
} else {
F_47 ( & V_65 [ V_10 ] , V_105 , sizeof( V_104 ) , V_98 [ V_10 ] ) ;
}
} else {
if ( ! F_48 ( V_93 [ V_10 ] , V_98 [ V_10 ] ) ) {
V_101 = TRUE ;
} else {
F_47 ( & V_65 [ V_10 ] , V_105 , V_99 , V_98 [ V_10 ] ) ;
}
}
if ( V_101 ) {
V_63 = FALSE ;
break;
}
}
}
}
