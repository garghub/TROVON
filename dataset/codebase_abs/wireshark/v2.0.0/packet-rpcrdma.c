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
return F_13 ( V_60 , V_35 , V_34 , V_3 ) ;
}
break;
}
}
return V_2 ;
}
static int
F_18 ( T_2 * V_1 , T_7 * V_34 , T_3 * V_3 ,
void * T_8 V_61 )
{
return F_12 ( V_1 , V_34 , V_3 ) ;
}
static T_4
F_19 ( T_2 * V_1 , T_7 * V_34 , T_3 * V_3 ,
void * T_8 V_61 )
{
T_9 * V_62 ;
T_10 * V_63 = NULL ;
if ( V_64 ) {
if ( ( F_20 ( & V_34 -> V_65 , & V_66 [ 0 ] ) &&
F_20 ( & V_34 -> V_67 , & V_66 [ 1 ] ) &&
( V_34 -> V_68 == 0xffffffff || V_34 -> V_68 == V_69 [ 0 ] ) &&
( V_34 -> V_70 == 0xffffffff || V_34 -> V_70 == V_69 [ 1 ] ) ) ||
( F_20 ( & V_34 -> V_65 , & V_66 [ 1 ] ) &&
F_20 ( & V_34 -> V_67 , & V_66 [ 0 ] ) &&
( V_34 -> V_68 == 0xffffffff || V_34 -> V_68 == V_69 [ 1 ] ) &&
( V_34 -> V_70 == 0xffffffff || V_34 -> V_70 == V_69 [ 0 ] ) ) )
return ( F_12 ( V_1 , V_34 , V_3 ) != 0 ) ;
}
V_62 = F_21 ( V_34 -> V_71 -> V_72 , & V_34 -> V_65 , & V_34 -> V_67 ,
V_73 , V_34 -> V_68 , V_34 -> V_70 , 0 ) ;
if ( ! V_62 ) {
V_62 = F_21 ( V_34 -> V_71 -> V_72 , & V_34 -> V_67 , & V_34 -> V_67 ,
V_73 , V_34 -> V_70 , V_34 -> V_70 , V_74 | V_75 ) ;
if ( ! V_62 )
return FALSE ;
}
V_63 = ( T_10 * ) F_22 ( V_62 , V_76 ) ;
if ( ! V_63 )
return FALSE ;
if ( ( V_63 -> V_77 & V_78 ) != V_79 )
return FALSE ;
if ( ! ( F_23 ( V_80 , ( T_6 ) ( V_63 -> V_77 & V_81 ) ) ) )
return FALSE ;
V_62 = F_24 ( V_34 ) ;
F_25 ( V_62 , V_82 ) ;
return ( F_12 ( V_1 , V_34 , V_3 ) != 0 ) ;
}
void
F_26 ( void )
{
T_11 * V_83 ;
static T_12 V_84 [] = {
{ & V_44 ,
{ L_5 , L_8 ,
V_85 , V_86 ,
NULL , 0x0 , NULL , V_87 }
} ,
{ & V_47 ,
{ L_9 , L_10 ,
V_88 , V_89 ,
NULL , 0x0 , NULL , V_87 }
} ,
{ & V_48 ,
{ L_11 , L_12 ,
V_88 , V_89 ,
NULL , 0x0 , NULL , V_87 }
} ,
{ & V_49 ,
{ L_13 , L_14 ,
V_88 , V_89 ,
NULL , 0x0 , NULL , V_87 }
} ,
{ & V_50 ,
{ L_15 , L_16 ,
V_88 , V_89 ,
F_27 ( V_43 ) , 0x0 , NULL , V_87 }
} ,
{ & V_19 ,
{ L_17 , L_18 ,
V_88 , V_90 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_20 ,
{ L_19 , L_20 ,
V_88 , V_90 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_21 ,
{ L_21 , L_22 ,
V_88 , V_90 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_16 ,
{ L_23 , L_24 ,
V_88 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_17 ,
{ L_25 , L_26 ,
V_88 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_18 ,
{ L_27 , L_28 ,
V_91 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_14 ,
{ L_29 , L_30 ,
V_88 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_52 ,
{ L_31 , L_32 ,
V_88 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_53 ,
{ L_33 , L_34 ,
V_88 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_55 ,
{ L_35 , L_36 ,
V_88 , V_89 ,
F_27 ( V_92 ) , 0 , NULL , V_87 }
} ,
{ & V_57 ,
{ L_37 , L_38 ,
V_88 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
{ & V_58 ,
{ L_39 , L_40 ,
V_88 , V_89 ,
NULL , 0 , NULL , V_87 }
} ,
} ;
static T_13 * V_93 [] = {
& V_46 ,
& V_13 ,
} ;
V_94 = F_28 (
L_41 ,
L_5 ,
L_8
) ;
F_29 ( V_94 , V_84 , F_30 ( V_84 ) ) ;
F_31 ( V_93 , F_30 ( V_93 ) ) ;
V_83 = F_32 ( V_94 , V_95 ) ;
F_33 ( V_83 , L_42 , L_43 ,
L_44 ,
& V_64 ) ;
F_34 ( V_83 , L_45 , L_46 ,
L_47 ) ;
F_35 ( V_83 , L_48 , L_49 ,
L_50 , & V_96 [ 0 ] , V_97 , FALSE ) ;
F_36 ( V_83 , L_51 , L_52 ,
L_53 , & V_98 [ 0 ] ) ;
F_37 ( V_83 , L_54 , L_55 ,
L_56 , 10 , & V_69 [ 0 ] ) ;
F_34 ( V_83 , L_57 , L_58 ,
L_59 ) ;
F_35 ( V_83 , L_60 , L_49 ,
L_50 , & V_96 [ 1 ] , V_97 , FALSE ) ;
F_36 ( V_83 , L_61 , L_52 ,
L_62 , & V_98 [ 1 ] ) ;
F_37 ( V_83 , L_63 , L_55 ,
L_64 , 10 , & V_69 [ 1 ] ) ;
F_38 ( & V_80 , V_99 , V_100 ) ;
F_39 ( V_83 ,
L_65 ,
L_66 ,
L_67
L_68 V_99 L_69 ,
& V_80 , V_100 ) ;
}
void
V_95 ( void )
{
static T_4 V_101 = FALSE ;
if ( ! V_101 ) {
V_82 = F_40 ( F_18 , V_94 ) ;
F_41 ( L_70 , F_19 , L_71 , L_72 , V_94 , V_102 ) ;
F_41 ( L_73 , F_19 , L_74 , L_75 , V_94 , V_102 ) ;
V_103 [ 0 ] = F_42 ( F_43 () , V_104 ) ;
V_103 [ 1 ] = F_42 ( F_43 () , V_104 ) ;
V_60 = F_44 ( L_76 ) ;
V_39 = F_44 ( L_77 ) ;
V_105 = F_44 ( L_78 ) ;
V_76 = F_45 ( V_105 ) ;
V_101 = TRUE ;
}
if ( V_64 ) {
T_4 V_106 = FALSE ;
char * V_107 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
if ( V_96 [ V_10 ] == 0 ) {
V_108 = 0 ;
* ( ( V_109 * ) V_103 [ V_10 ] ) = ( V_109 ) strtoul ( V_98 [ V_10 ] , & V_107 , 0 ) ;
if ( V_108 || * V_107 != '\0' ) {
V_106 = TRUE ;
} else {
F_46 ( & V_66 [ V_10 ] , V_110 , sizeof( V_109 ) , V_103 [ V_10 ] ) ;
}
} else {
if ( ! F_47 ( V_98 [ V_10 ] , V_103 [ V_10 ] ) ) {
V_106 = TRUE ;
} else {
F_46 ( & V_66 [ V_10 ] , V_110 , V_104 , V_103 [ V_10 ] ) ;
}
}
if ( V_106 ) {
V_64 = FALSE ;
break;
}
}
}
}
