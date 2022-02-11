void F_1 ( void )
{
V_1 = F_2 ( L_1 ) ;
V_2 = F_2 ( L_2 ) ;
V_3 = F_3 ( L_3 ) ;
V_4 = F_3 ( L_4 ) ;
V_5 = F_3 ( L_5 ) ;
V_6 = F_3 ( L_6 ) ;
}
T_1
F_4 ( T_2 V_7 , T_1 V_8 ,
T_3 * V_9 , T_4 * V_10 ,
T_5 * V_11 )
{
T_6 V_12 ;
V_12 . V_13 = 0 ;
V_12 . V_11 = V_11 ;
V_12 . V_14 = TRUE ;
V_12 . V_15 = V_9 -> V_16 . V_17 ;
V_12 . V_18 = ( V_19 ) V_9 -> V_16 . V_20 -> V_21 . V_18 ;
V_12 . V_7 = V_7 ;
V_12 . V_22 = ! V_8 ;
V_12 . V_10 = V_10 ;
F_5 ( V_9 -> V_23 , V_24 , & V_12 ) ;
return V_12 . V_14 ;
}
static void
V_24 ( T_7 * V_25 , T_8 V_12 )
{
T_9 * V_26 = F_6 ( V_25 ) ;
T_6 * V_27 = ( T_6 * ) V_12 ;
const T_10 * V_28 ;
T_11 V_29 [ V_30 ] ;
T_11 * V_31 ;
F_7 ( V_26 ) ;
if ( F_8 ( V_25 ) && ( V_32 . V_33 == FALSE ) )
return;
if ( ! V_27 -> V_14 )
return;
if ( V_26 -> V_34 ) {
V_31 = V_26 -> V_34 -> V_35 ;
}
else {
V_31 = V_29 ;
F_9 ( V_26 , V_29 ) ;
}
if ( F_10 ( V_25 ) )
V_31 = F_11 ( L_7 , V_31 , L_8 , NULL ) ;
V_27 -> V_14 = F_12 ( V_27 -> V_11 , V_27 -> V_13 , V_31 ) ;
if ( F_10 ( V_25 ) )
F_13 ( V_31 ) ;
if ( ! V_27 -> V_14 )
return;
if ( ( V_27 -> V_10 != NULL ) && ( V_27 -> V_13 == 0 )
&& ( F_14 ( V_27 -> V_10 , V_26 -> V_36 -> V_37 ) == NULL ) ) {
return;
}
if ( ( V_26 -> V_36 -> V_38 == V_1 ) && ( V_27 -> V_22 ) ) {
V_28 = F_15 ( V_27 -> V_15 , V_26 ) ;
if ( V_28 ) {
if ( ! F_12 ( V_27 -> V_11 , 0 , L_9 ) ) {
V_27 -> V_14 = FALSE ;
return;
}
if ( ! F_16 ( V_27 -> V_11 , V_28 ,
V_26 -> V_39 , V_27 -> V_18 ) ) {
V_27 -> V_14 = FALSE ;
return;
}
}
}
F_7 ( ( V_26 -> V_40 >= - 1 ) && ( V_26 -> V_40 < V_41 ) ) ;
if ( ( V_27 -> V_7 == V_42 ) ||
( ( V_27 -> V_7 == V_43 ) &&
( V_26 -> V_40 >= 0 ) && F_17 ( V_26 -> V_40 ) ) ) {
if ( V_25 -> V_44 != NULL ) {
V_27 -> V_13 ++ ;
F_5 ( V_25 ,
V_24 , V_27 ) ;
V_27 -> V_13 -- ;
if ( ! V_27 -> V_14 )
return;
}
}
}
void
F_18 ( T_12 * V_45 , const T_11 * V_46 )
{
T_13 V_47 = time ( NULL ) ;
struct V_48 * V_49 ;
char * V_50 ;
const char * V_51 ;
V_49 = localtime ( & V_47 ) ;
if ( V_49 != NULL ) {
V_50 = asctime ( V_49 ) ;
V_50 [ strlen ( V_50 ) - 1 ] = 0 ;
V_51 = V_50 ;
} else
V_51 = L_10 ;
fprintf ( V_45 , L_11 ) ;
fprintf ( V_45 , L_12 V_52 L_13 ) ;
fprintf ( V_45 , L_14 V_52 L_15 V_52 L_16 , F_19 () ) ;
fprintf ( V_45 , L_17 V_53 L_18 , V_54 , V_55 , V_51 ) ;
if ( V_46 ) {
F_20 ( V_45 , V_46 ) ;
}
fprintf ( V_45 , L_19 ) ;
}
void
F_21 ( T_12 * V_45 )
{
fputs ( L_20 , V_45 ) ;
V_56 = TRUE ;
}
static T_1 F_22 ( T_11 * * V_57 , const char * V_58 )
{
T_1 V_59 = FALSE ;
T_11 * * V_60 ;
if ( V_58 == NULL || V_57 == NULL ) {
return FALSE ;
}
for ( V_60 = V_57 ; * V_60 ; V_60 ++ ) {
if ( strcmp ( * V_60 , V_58 ) == 0 ) {
V_59 = TRUE ;
break;
}
}
return V_59 ;
}
void
F_23 ( T_14 * V_61 , T_11 * * V_57 , T_15 V_62 , T_3 * V_9 , T_12 * V_45 )
{
T_16 V_12 ;
F_7 ( V_9 ) ;
F_7 ( V_45 ) ;
fprintf ( V_45 , L_21 ) ;
F_24 ( V_9 , V_45 ) ;
if ( V_61 == NULL || V_61 -> V_61 == NULL ) {
V_12 . V_13 = 0 ;
V_12 . V_45 = V_45 ;
V_12 . V_15 = V_9 -> V_16 . V_17 ;
V_12 . V_63 = V_57 ;
V_12 . V_64 = V_62 ;
F_5 ( V_9 -> V_23 , V_65 ,
& V_12 ) ;
} else {
F_25 ( V_66 , V_61 , V_9 , NULL , V_45 ) ;
}
fprintf ( V_45 , L_22 ) ;
}
void
F_26 ( T_14 * V_61 ,
T_2 V_7 ,
T_1 V_8 , T_11 * * V_57 ,
T_15 V_62 , T_3 * V_9 ,
T_12 * V_45 )
{
T_17 V_12 ;
char V_51 [ 30 ] ;
T_13 V_47 = time ( NULL ) ;
struct V_48 * V_49 ;
F_7 ( V_9 ) ;
F_7 ( V_45 ) ;
V_49 = localtime ( & V_47 ) ;
if ( V_49 != NULL )
strftime ( V_51 , sizeof V_51 , L_23 , V_49 ) ;
else
F_27 ( V_51 , L_24 , sizeof V_51 ) ;
if ( ! V_56 )
fputs ( L_25 , V_45 ) ;
else
V_56 = FALSE ;
fputs ( L_26 , V_45 ) ;
fprintf ( V_45 , L_27 , V_51 ) ;
fputs ( L_28 , V_45 ) ;
fputs ( L_29 , V_45 ) ;
fputs ( L_30 , V_45 ) ;
fputs ( L_31 , V_45 ) ;
if ( V_61 == NULL || V_61 -> V_61 == NULL ) {
V_12 . V_13 = 1 ;
V_12 . V_45 = V_45 ;
V_12 . V_15 = V_9 -> V_16 . V_17 ;
V_12 . V_63 = V_57 ;
V_12 . V_64 = V_62 ;
V_12 . V_8 = V_8 ;
V_12 . V_67 = TRUE ;
if ( V_7 == V_68 ) {
V_12 . V_67 = FALSE ;
}
F_5 ( V_9 -> V_23 , V_69 ,
& V_12 ) ;
} else {
F_25 ( V_70 , V_61 , V_9 , NULL , V_45 ) ;
}
fputs ( L_32 , V_45 ) ;
fputs ( L_33 , V_45 ) ;
fputs ( L_34 , V_45 ) ;
}
void
F_28 ( T_14 * V_61 ,
T_1 V_8 , T_11 * * V_57 ,
T_15 V_62 , T_3 * V_9 ,
T_12 * V_45 )
{
T_17 V_12 ;
char V_51 [ 30 ] ;
T_13 V_47 = time ( NULL ) ;
struct V_48 * V_49 ;
F_7 ( V_9 ) ;
F_7 ( V_45 ) ;
V_49 = localtime ( & V_47 ) ;
if ( V_49 != NULL )
strftime ( V_51 , sizeof V_51 , L_23 , V_49 ) ;
else
F_27 ( V_51 , L_24 , sizeof V_51 ) ;
fprintf ( V_45 , L_35 , V_51 ) ;
fprintf ( V_45 , L_36 V_71 L_37 , ( V_72 ) V_9 -> V_16 . V_73 . V_74 , V_9 -> V_16 . V_73 . V_75 / 1000000 ) ;
if ( V_61 == NULL || V_61 -> V_61 == NULL ) {
V_12 . V_13 = 0 ;
V_12 . V_45 = V_45 ;
V_12 . V_15 = V_9 -> V_16 . V_17 ;
V_12 . V_63 = V_57 ;
V_12 . V_64 = V_62 ;
V_12 . V_8 = V_8 ;
F_5 ( V_9 -> V_23 , V_76 ,
& V_12 ) ;
} else {
F_25 ( V_77 , V_61 , V_9 , NULL , V_45 ) ;
}
fputs ( L_38 , V_45 ) ;
}
void
F_29 ( T_14 * V_61 , T_3 * V_9 , T_18 * V_78 , T_12 * V_45 )
{
F_7 ( V_9 ) ;
F_7 ( V_45 ) ;
F_25 ( V_79 , V_61 , V_9 , V_78 , V_45 ) ;
}
static void F_30 ( int V_13 , T_12 * V_45 )
{
int V_80 ;
if ( V_45 == NULL ) {
return;
}
for ( V_80 = 0 ; V_80 < V_13 ; V_80 ++ ) {
fputs ( L_39 , V_45 ) ;
}
}
static void
V_65 ( T_7 * V_25 , T_8 V_12 )
{
T_9 * V_26 = F_6 ( V_25 ) ;
T_16 * V_27 = ( T_16 * ) V_12 ;
const T_11 * V_31 ;
T_11 V_29 [ V_30 ] ;
char * V_81 ;
T_1 V_82 ;
F_7 ( V_26 ) ;
V_82 =
( ( ( V_26 -> V_36 -> type != V_83 ) ||
( V_26 -> V_36 -> V_38 == V_1 ) ) &&
( V_27 -> V_13 == 0 ) ) ;
F_30 ( V_27 -> V_13 + 1 , V_27 -> V_45 ) ;
if ( V_82 ) {
fputs ( L_40 , V_27 -> V_45 ) ;
F_30 ( V_27 -> V_13 + 1 , V_27 -> V_45 ) ;
}
if ( V_26 -> V_36 -> V_38 == V_84 ) {
if ( V_26 -> V_34 ) {
V_31 = V_26 -> V_34 -> V_35 ;
}
else {
V_31 = L_9 ;
}
fputs ( L_41 , V_27 -> V_45 ) ;
fputs ( L_42 , V_27 -> V_45 ) ;
F_20 ( V_27 -> V_45 , V_31 ) ;
fprintf ( V_27 -> V_45 , L_43 , V_26 -> V_39 ) ;
if ( V_25 -> V_85 && V_25 -> V_85 -> V_86 && ( V_26 -> V_87 < V_25 -> V_85 -> V_86 -> V_87 ) ) {
fprintf ( V_27 -> V_45 , L_44 , V_25 -> V_85 -> V_86 -> V_87 + V_26 -> V_87 ) ;
} else {
fprintf ( V_27 -> V_45 , L_44 , V_26 -> V_87 ) ;
}
if ( V_26 -> V_39 > 0 ) {
fputs ( L_45 , V_27 -> V_45 ) ;
F_31 ( V_27 , V_26 ) ;
}
if ( V_25 -> V_44 != NULL ) {
fputs ( L_19 , V_27 -> V_45 ) ;
}
else {
fputs ( L_46 , V_27 -> V_45 ) ;
}
}
else if ( V_26 -> V_36 -> V_38 == V_1 ) {
fputs ( L_47 , V_27 -> V_45 ) ;
F_31 ( V_27 , V_26 ) ;
fputs ( L_19 , V_27 -> V_45 ) ;
}
else {
if ( ( V_26 -> V_36 -> type == V_83 ) && ( V_26 -> V_36 -> V_38 != V_88 ) ) {
fputs ( L_48 , V_27 -> V_45 ) ;
}
else {
fputs ( L_41 , V_27 -> V_45 ) ;
}
F_20 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if ( V_26 -> V_34 ) {
fputs ( L_49 , V_27 -> V_45 ) ;
F_20 ( V_27 -> V_45 , V_26 -> V_34 -> V_35 ) ;
}
else {
V_31 = V_29 ;
F_9 ( V_26 , V_29 ) ;
fputs ( L_49 , V_27 -> V_45 ) ;
F_20 ( V_27 -> V_45 , V_31 ) ;
}
if ( F_8 ( V_25 ) && ( V_32 . V_33 == FALSE ) )
fprintf ( V_27 -> V_45 , L_50 ) ;
fprintf ( V_27 -> V_45 , L_43 , V_26 -> V_39 ) ;
if ( V_25 -> V_85 && V_25 -> V_85 -> V_86 && ( V_26 -> V_87 < V_25 -> V_85 -> V_86 -> V_87 ) ) {
fprintf ( V_27 -> V_45 , L_44 , V_25 -> V_85 -> V_86 -> V_87 + V_26 -> V_87 ) ;
} else {
fprintf ( V_27 -> V_45 , L_44 , V_26 -> V_87 ) ;
}
switch ( V_26 -> V_36 -> type )
{
case V_83 :
break;
case V_89 :
fputs ( L_51 , V_27 -> V_45 ) ;
break;
default:
V_81 = F_32 ( NULL , & V_26 -> V_90 , V_91 , V_26 -> V_36 -> V_92 ) ;
if ( V_81 != NULL ) {
fputs ( L_42 , V_27 -> V_45 ) ;
F_20 ( V_27 -> V_45 , V_81 ) ;
}
F_33 ( NULL , V_81 ) ;
if ( V_26 -> V_39 > 0 ) {
fputs ( L_45 , V_27 -> V_45 ) ;
if ( V_26 -> V_36 -> V_93 != 0 ) {
switch ( V_26 -> V_90 . V_94 -> V_94 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
fprintf ( V_27 -> V_45 , L_52 , ( V_99 ) F_34 ( & V_26 -> V_90 ) ) ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
fprintf ( V_27 -> V_45 , L_52 , F_35 ( & V_26 -> V_90 ) ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
fprintf ( V_27 -> V_45 , L_53 V_108 L_54 , F_36 ( & V_26 -> V_90 ) ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
fprintf ( V_27 -> V_45 , L_53 V_108 L_54 , F_37 ( & V_26 -> V_90 ) ) ;
break;
default:
F_38 () ;
}
fputs ( L_55 , V_27 -> V_45 ) ;
F_31 ( V_27 , V_26 ) ;
}
else {
F_31 ( V_27 , V_26 ) ;
}
}
}
if ( V_25 -> V_44 != NULL ) {
fputs ( L_19 , V_27 -> V_45 ) ;
}
else if ( V_26 -> V_36 -> V_38 == V_1 ) {
fputs ( L_19 , V_27 -> V_45 ) ;
}
else {
fputs ( L_46 , V_27 -> V_45 ) ;
}
}
if ( V_25 -> V_44 != NULL ) {
if ( V_27 -> V_63 == NULL || F_22 ( V_27 -> V_63 , V_26 -> V_36 -> V_37 ) ) {
T_11 * * V_114 = NULL ;
if ( ( V_27 -> V_64 & V_115 ) == V_115 ) {
V_114 = V_27 -> V_63 ;
V_27 -> V_63 = NULL ;
}
V_27 -> V_13 ++ ;
F_5 ( V_25 ,
V_65 , V_27 ) ;
V_27 -> V_13 -- ;
if ( ( V_27 -> V_64 & V_115 ) == V_115 ) {
V_27 -> V_63 = V_114 ;
}
} else {
F_30 ( V_27 -> V_13 + 2 , V_27 -> V_45 ) ;
fputs ( L_56 , V_27 -> V_45 ) ;
F_20 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_57 , V_27 -> V_45 ) ;
}
}
if ( V_82 ) {
V_27 -> V_13 -- ;
}
if ( V_25 -> V_44 != NULL ) {
F_30 ( V_27 -> V_13 + 1 , V_27 -> V_45 ) ;
if ( ( V_26 -> V_36 -> V_38 != V_1 ) && ( V_26 -> V_36 -> V_38 != V_88 ) ) {
if ( V_26 -> V_36 -> type == V_83 ) {
fputs ( L_58 , V_27 -> V_45 ) ;
}
else {
fputs ( L_59 , V_27 -> V_45 ) ;
}
} else {
fputs ( L_59 , V_27 -> V_45 ) ;
}
}
if ( V_82 ) {
fputs ( L_58 , V_27 -> V_45 ) ;
}
}
static void
V_69 ( T_7 * V_25 , T_8 V_12 )
{
T_9 * V_26 = F_6 ( V_25 ) ;
T_17 * V_27 = ( T_17 * ) V_12 ;
const T_11 * V_31 ;
T_11 V_29 [ V_30 ] ;
char * V_81 ;
F_7 ( V_26 ) ;
if ( V_26 -> V_36 -> V_38 == V_84 ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
if ( V_26 -> V_34 ) {
V_31 = V_26 -> V_34 -> V_35 ;
}
else {
V_31 = L_9 ;
}
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_31 ) ;
if ( V_25 -> V_44 != NULL ) {
fputs ( L_61 , V_27 -> V_45 ) ;
}
else {
if ( V_25 -> V_116 == NULL ) {
fputs ( L_62 , V_27 -> V_45 ) ;
} else {
fputs ( L_63 , V_27 -> V_45 ) ;
}
}
}
else {
if ( V_27 -> V_8 && ( ! V_27 -> V_67 || V_26 -> V_39 > 0 ) ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_64 , V_27 -> V_45 ) ;
fputs ( L_65 , V_27 -> V_45 ) ;
if ( V_26 -> V_36 -> V_93 != 0 ) {
switch ( V_26 -> V_90 . V_94 -> V_94 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
fprintf ( V_27 -> V_45 , L_52 , ( V_99 ) F_34 ( & V_26 -> V_90 ) ) ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
fprintf ( V_27 -> V_45 , L_52 , F_35 ( & V_26 -> V_90 ) ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
fprintf ( V_27 -> V_45 , L_53 V_108 L_54 , F_36 ( & V_26 -> V_90 ) ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
fprintf ( V_27 -> V_45 , L_53 V_108 L_54 , F_37 ( & V_26 -> V_90 ) ) ;
break;
default:
F_38 () ;
}
}
else {
F_40 ( V_27 , V_26 ) ;
}
fprintf ( V_27 -> V_45 , L_66 V_117 L_67 , V_26 -> V_87 ) ;
fprintf ( V_27 -> V_45 , L_68 V_117 L_67 , V_26 -> V_39 ) ;
fprintf ( V_27 -> V_45 , L_68 V_71 , V_26 -> V_36 -> V_93 ) ;
fprintf ( V_27 -> V_45 , L_68 V_117 L_67 , ( V_118 ) V_26 -> V_90 . V_94 -> V_94 ) ;
if ( V_27 -> V_67 ) {
fputs ( L_69 , V_27 -> V_45 ) ;
} else {
if ( V_25 -> V_116 == NULL && V_25 -> V_44 == NULL ) {
fputs ( L_70 , V_27 -> V_45 ) ;
} else {
fputs ( L_69 , V_27 -> V_45 ) ;
}
}
}
switch ( V_26 -> V_36 -> type )
{
case V_83 :
if ( V_25 -> V_44 != NULL ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_61 , V_27 -> V_45 ) ;
} else if ( V_27 -> V_67 ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_71 , V_27 -> V_45 ) ;
if ( V_26 -> V_34 ) {
F_39 ( V_27 -> V_45 , V_26 -> V_34 -> V_35 ) ;
}
else {
V_31 = V_29 ;
F_9 ( V_26 , V_29 ) ;
F_39 ( V_27 -> V_45 , V_31 ) ;
}
if ( V_25 -> V_116 == NULL ) {
fputs ( L_72 , V_27 -> V_45 ) ;
} else {
fputs ( L_73 , V_27 -> V_45 ) ;
}
}
break;
case V_89 :
if ( V_25 -> V_44 != NULL ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_61 , V_27 -> V_45 ) ;
} else if ( V_27 -> V_67 ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
if ( V_25 -> V_116 == NULL ) {
fputs ( L_62 , V_27 -> V_45 ) ;
} else {
fputs ( L_63 , V_27 -> V_45 ) ;
}
}
break;
default:
if ( V_27 -> V_67 ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
V_81 = F_32 ( NULL , & V_26 -> V_90 , V_91 , V_26 -> V_36 -> V_92 ) ;
if ( V_81 != NULL ) {
if ( V_27 -> V_67 ) {
fputs ( L_71 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_81 ) ;
if ( V_25 -> V_44 != NULL ) {
fputs ( L_73 , V_27 -> V_45 ) ;
}
}
}
F_33 ( NULL , V_81 ) ;
if ( V_25 -> V_44 == NULL ) {
if ( V_25 -> V_116 == NULL ) {
fputs ( L_72 , V_27 -> V_45 ) ;
} else {
fputs ( L_73 , V_27 -> V_45 ) ;
}
}
}
if ( V_25 -> V_44 != NULL ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_74 , V_27 -> V_45 ) ;
}
}
}
if ( V_25 -> V_44 != NULL ) {
if ( V_27 -> V_63 == NULL || F_22 ( V_27 -> V_63 , V_26 -> V_36 -> V_37 ) ) {
T_11 * * V_114 = NULL ;
if ( ( V_27 -> V_64 & V_115 ) == V_115 ) {
V_114 = V_27 -> V_63 ;
V_27 -> V_63 = NULL ;
}
V_27 -> V_13 ++ ;
F_5 ( V_25 , V_69 , V_27 ) ;
V_27 -> V_13 -- ;
if ( ( V_27 -> V_64 & V_115 ) == V_115 ) {
V_27 -> V_63 = V_114 ;
}
} else {
F_30 ( V_27 -> V_13 + 4 , V_27 -> V_45 ) ;
fputs ( L_75 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_72 , V_27 -> V_45 ) ;
}
}
if ( V_25 -> V_44 != NULL ) {
F_30 ( V_27 -> V_13 + 3 , V_27 -> V_45 ) ;
if ( V_25 -> V_116 == NULL ) {
fputs ( L_76 , V_27 -> V_45 ) ;
} else {
fputs ( L_77 , V_27 -> V_45 ) ;
}
}
}
static void
V_76 ( T_7 * V_25 , T_8 V_12 )
{
T_9 * V_26 = F_6 ( V_25 ) ;
T_9 * V_119 = F_6 ( V_25 -> V_85 ) ;
T_17 * V_27 = ( T_17 * ) V_12 ;
const T_11 * V_31 ;
T_11 V_29 [ V_30 ] ;
char * V_81 ;
int V_80 ;
T_11 * V_120 = NULL ;
F_7 ( V_26 ) ;
if ( V_26 -> V_36 -> V_38 == V_84 ) {
if ( V_26 -> V_34 ) {
V_31 = V_26 -> V_34 -> V_35 ;
}
else {
V_31 = L_9 ;
}
fputs ( L_60 , V_27 -> V_45 ) ;
if ( V_119 != NULL ) {
F_41 ( V_27 -> V_45 , V_119 -> V_36 -> V_37 ) ;
fputs ( L_78 , V_27 -> V_45 ) ;
}
F_41 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
if ( V_25 -> V_44 != NULL ) {
fputs ( L_71 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_31 ) ;
fputs ( L_79 , V_27 -> V_45 ) ;
}
else {
if ( V_25 -> V_116 == NULL ) {
fputs ( L_71 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_31 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
} else {
fputs ( L_71 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_31 ) ;
fputs ( L_79 , V_27 -> V_45 ) ;
}
}
}
else {
if ( V_27 -> V_8 && V_26 -> V_39 > 0 ) {
fputs ( L_60 , V_27 -> V_45 ) ;
if ( V_119 != NULL ) {
F_41 ( V_27 -> V_45 , V_119 -> V_36 -> V_37 ) ;
fputs ( L_78 , V_27 -> V_45 ) ;
}
F_41 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_64 , V_27 -> V_45 ) ;
fputs ( L_71 , V_27 -> V_45 ) ;
if ( V_26 -> V_36 -> V_93 != 0 ) {
switch ( V_26 -> V_90 . V_94 -> V_94 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
fprintf ( V_27 -> V_45 , L_52 , ( V_99 ) F_34 ( & V_26 -> V_90 ) ) ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
fprintf ( V_27 -> V_45 , L_52 , F_35 ( & V_26 -> V_90 ) ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
fprintf ( V_27 -> V_45 , L_53 V_108 L_54 , F_36 ( & V_26 -> V_90 ) ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
fprintf ( V_27 -> V_45 , L_53 V_108 L_54 , F_37 ( & V_26 -> V_90 ) ) ;
break;
default:
F_38 () ;
}
fputs ( L_79 , V_27 -> V_45 ) ;
}
else {
F_40 ( V_27 , V_26 ) ;
fputs ( L_79 , V_27 -> V_45 ) ;
}
}
fputs ( L_60 , V_27 -> V_45 ) ;
if ( V_119 != NULL ) {
F_41 ( V_27 -> V_45 , V_119 -> V_36 -> V_37 ) ;
fputs ( L_78 , V_27 -> V_45 ) ;
}
F_41 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
switch ( V_26 -> V_36 -> type )
{
case V_83 :
if ( V_25 -> V_44 != NULL ) {
fputs ( L_80 , V_27 -> V_45 ) ;
} else {
fputs ( L_71 , V_27 -> V_45 ) ;
if ( V_26 -> V_34 ) {
F_39 ( V_27 -> V_45 , V_26 -> V_34 -> V_35 ) ;
}
else {
V_31 = V_29 ;
F_9 ( V_26 , V_29 ) ;
F_39 ( V_27 -> V_45 , V_31 ) ;
}
if ( V_25 -> V_116 == NULL ) {
fputs ( L_60 , V_27 -> V_45 ) ;
} else {
fputs ( L_79 , V_27 -> V_45 ) ;
}
}
break;
case V_89 :
if ( V_25 -> V_44 != NULL ) {
fputs ( L_81 , V_27 -> V_45 ) ;
} else {
if ( V_25 -> V_116 == NULL ) {
fputs ( L_82 , V_27 -> V_45 ) ;
} else {
fputs ( L_81 , V_27 -> V_45 ) ;
}
}
break;
default:
V_81 = F_32 ( NULL , & V_26 -> V_90 , V_91 , V_26 -> V_36 -> V_92 ) ;
if ( V_81 != NULL ) {
fputs ( L_71 , V_27 -> V_45 ) ;
F_39 ( V_27 -> V_45 , V_81 ) ;
}
F_33 ( NULL , V_81 ) ;
if ( V_25 -> V_116 == NULL && V_25 -> V_44 == NULL ) {
fputs ( L_60 , V_27 -> V_45 ) ;
} else {
fputs ( L_79 , V_27 -> V_45 ) ;
}
}
}
if ( V_25 -> V_44 != NULL ) {
if ( V_27 -> V_63 != NULL ) {
if ( V_26 -> V_36 -> V_37 != NULL ) {
if ( strlen ( V_26 -> V_36 -> V_37 ) > 0 ) {
V_120 = F_42 ( V_26 -> V_36 -> V_37 ) ;
V_80 = 0 ;
while( V_120 [ V_80 ] != '\0' ) {
if( V_120 [ V_80 ] == '.' ) {
V_120 [ V_80 ] = '_' ;
}
V_80 ++ ;
}
}
}
if( F_22 ( V_27 -> V_63 , V_26 -> V_36 -> V_37 ) || F_22 ( V_27 -> V_63 , V_120 ) ) {
T_11 * * V_114 = NULL ;
if ( ( V_27 -> V_64 & V_115 ) == V_115 ) {
V_114 = V_27 -> V_63 ;
V_27 -> V_63 = NULL ;
}
V_27 -> V_13 ++ ;
F_5 ( V_25 , V_76 , V_27 ) ;
V_27 -> V_13 -- ;
if ( ( V_27 -> V_64 & V_115 ) == V_115 ) {
V_27 -> V_63 = V_114 ;
}
} else {
fputs ( L_75 , V_27 -> V_45 ) ;
F_41 ( V_27 -> V_45 , V_26 -> V_36 -> V_37 ) ;
fputs ( L_60 , V_27 -> V_45 ) ;
}
if ( V_120 != NULL ) {
F_13 ( V_120 ) ;
}
} else {
V_27 -> V_13 ++ ;
F_5 ( V_25 ,
V_76 , V_27 ) ;
V_27 -> V_13 -- ;
}
}
if ( V_25 -> V_44 != NULL ) {
if ( V_26 -> V_36 -> type == V_83 ) {
if ( V_25 -> V_116 == NULL ) {
fputs ( L_83 , V_27 -> V_45 ) ;
} else {
fputs ( L_84 , V_27 -> V_45 ) ;
}
} else {
if ( V_25 -> V_116 != NULL ) {
fputs ( L_85 , V_27 -> V_45 ) ;
}
}
}
}
static void
F_24 ( T_3 * V_9 , T_12 * V_45 )
{
T_19 V_121 , V_122 , V_123 ;
T_20 * V_124 ;
T_9 * V_125 ;
T_11 * V_126 ;
V_124 = F_43 ( V_9 -> V_23 , V_2 ) ;
if ( F_44 ( V_124 ) < 1 ) {
return;
}
V_125 = ( T_9 * ) V_124 -> V_27 [ 0 ] ;
F_45 ( V_124 , TRUE ) ;
V_121 = V_9 -> V_16 . V_121 ;
V_122 = V_9 -> V_16 . V_20 -> V_127 ;
V_123 = V_9 -> V_16 . V_20 -> V_128 ;
fprintf ( V_45 ,
L_86 ,
V_125 -> V_39 ) ;
fprintf ( V_45 ,
L_87 ,
V_121 , V_121 , V_125 -> V_39 ) ;
fprintf ( V_45 ,
L_88 ,
V_122 , V_122 , V_125 -> V_39 ) ;
fprintf ( V_45 ,
L_89 ,
V_123 , V_123 , V_125 -> V_39 ) ;
V_126 = F_46 ( NULL , & V_9 -> V_16 . V_73 , V_129 , TRUE ) ;
fprintf ( V_45 ,
L_90 ,
V_126 , ( int ) V_9 -> V_16 . V_73 . V_74 , V_9 -> V_16 . V_73 . V_75 , V_125 -> V_39 ) ;
F_33 ( NULL , V_126 ) ;
fprintf ( V_45 ,
L_91 ) ;
}
void
F_47 ( T_12 * V_45 )
{
fputs ( L_92 , V_45 ) ;
}
void
F_48 ( T_12 * V_45 )
{
fputs ( L_70 , V_45 ) ;
}
void
F_49 ( T_18 * V_78 , T_12 * V_45 )
{
T_21 V_80 ;
fprintf ( V_45 , L_11 ) ;
fprintf ( V_45 , L_93 V_130 L_94 , V_54 , V_55 ) ;
fprintf ( V_45 , L_95 ) ;
for ( V_80 = 0 ; V_80 < V_78 -> V_131 ; V_80 ++ ) {
fprintf ( V_45 , L_96 ) ;
F_20 ( V_45 , V_78 -> V_132 [ V_80 ] . V_133 ) ;
fprintf ( V_45 , L_97 ) ;
}
fprintf ( V_45 , L_98 ) ;
}
void
F_50 ( T_3 * V_9 , T_12 * V_45 )
{
T_21 V_80 ;
fprintf ( V_45 , L_21 ) ;
for ( V_80 = 0 ; V_80 < V_9 -> V_16 . V_78 -> V_131 ; V_80 ++ ) {
fprintf ( V_45 , L_96 ) ;
F_20 ( V_45 , V_9 -> V_16 . V_78 -> V_132 [ V_80 ] . V_134 ) ;
fprintf ( V_45 , L_97 ) ;
}
fprintf ( V_45 , L_22 ) ;
}
void
F_51 ( T_12 * V_45 )
{
fputs ( L_99 , V_45 ) ;
}
static T_11 * F_52 ( const T_11 * V_135 , const T_11 * V_136 )
{
T_11 * V_137 ;
T_11 * V_138 ;
V_137 = F_53 ( V_135 , V_136 ) ;
V_138 = V_137 ;
while ( ( V_138 = strstr ( V_138 , V_139 ) ) != NULL ) {
V_138 [ 0 ] = ' ' ;
V_138 [ 1 ] = '>' ;
V_138 [ 2 ] = ' ' ;
}
V_138 = V_137 ;
while ( ( V_138 = strstr ( V_138 , L_100 ) ) != NULL )
* V_138 = '\"' ;
return V_137 ;
}
static void F_54 ( const char * V_58 , char V_140 , T_12 * V_45 )
{
T_11 * V_137 ;
V_137 = F_52 ( V_58 , V_139 ) ;
fprintf ( V_45 , L_101 , V_137 , V_140 ) ;
F_13 ( V_137 ) ;
}
void
F_55 ( T_18 * V_78 , T_12 * V_45 )
{
T_21 V_80 ;
for ( V_80 = 0 ; V_80 < V_78 -> V_131 - 1 ; V_80 ++ )
F_54 ( V_78 -> V_132 [ V_80 ] . V_133 , ',' , V_45 ) ;
F_54 ( V_78 -> V_132 [ V_80 ] . V_133 , '\n' , V_45 ) ;
}
void
F_56 ( T_3 * V_9 , T_12 * V_45 )
{
T_21 V_80 ;
for ( V_80 = 0 ; V_80 < V_9 -> V_16 . V_78 -> V_131 - 1 ; V_80 ++ )
F_54 ( V_9 -> V_16 . V_78 -> V_132 [ V_80 ] . V_134 , ',' , V_45 ) ;
F_54 ( V_9 -> V_16 . V_78 -> V_132 [ V_80 ] . V_134 , '\n' , V_45 ) ;
}
void
F_57 ( T_19 V_121 , T_12 * V_45 , T_3 * V_9 )
{
T_19 V_80 = 0 , V_141 = 0 ;
T_22 * V_142 ;
T_23 * V_143 ;
char * V_144 ;
const T_24 * V_145 ;
V_99 V_39 ;
char V_146 [ 9 ] ;
struct V_147 * V_148 ;
for ( V_142 = V_9 -> V_16 . V_17 ; V_142 != NULL ; V_142 = V_142 -> V_116 ) {
memset ( V_146 , 0 , sizeof( V_146 ) ) ;
V_148 = (struct V_147 * ) V_142 -> V_12 ;
V_143 = F_58 ( V_148 ) ;
V_39 = F_59 ( V_143 ) ;
if ( V_39 == 0 )
continue;
V_145 = F_60 ( V_143 , 0 , V_39 ) ;
V_144 = F_61 ( V_148 ) ;
if ( V_144 ) {
fprintf ( V_45 , L_102 , V_144 ) ;
F_33 ( NULL , V_144 ) ;
}
if ( V_141 ) {
fprintf ( V_45 , L_103 ,
V_121 , V_141 , V_39 ) ;
} else {
fprintf ( V_45 , L_104 ,
V_121 , V_39 ) ;
}
V_141 ++ ;
for ( V_80 = 0 ; V_80 < V_39 ; V_80 ++ ) {
fprintf ( V_45 , L_105 , * ( V_145 + V_80 ) ) ;
V_146 [ V_80 % 8 ] = F_62 ( * ( V_145 + V_80 ) ) ? * ( V_145 + V_80 ) : '.' ;
if ( V_80 == ( V_39 - 1 ) ) {
V_99 V_149 ;
V_149 = V_39 % 8 ;
if ( V_149 ) {
V_99 V_150 ;
for ( V_150 = 0 ; V_150 < 8 - V_149 ; V_150 ++ )
fprintf ( V_45 , L_106 ) ;
}
fprintf ( V_45 , L_107 , V_146 ) ;
break;
}
if ( ! ( ( V_80 + 1 ) % 8 ) ) {
fprintf ( V_45 , L_108 , V_146 ) ;
memset ( V_146 , 0 , sizeof( V_146 ) ) ;
}
else {
fprintf ( V_45 , L_109 ) ;
}
}
}
}
static const T_10 *
F_15 ( T_22 * V_15 , T_9 * V_26 )
{
T_22 * V_142 ;
T_23 * V_151 ;
T_21 V_39 , V_152 ;
struct V_147 * V_148 ;
for ( V_142 = V_15 ; V_142 != NULL ; V_142 = V_142 -> V_116 ) {
V_148 = (struct V_147 * ) V_142 -> V_12 ;
V_151 = F_58 ( V_148 ) ;
if ( V_26 -> V_153 == V_151 ) {
V_152 = F_63 ( V_151 ,
V_26 -> V_87 ) ;
if ( V_152 < 0 ) {
return NULL ;
}
V_39 = V_26 -> V_39 ;
if ( V_39 > V_152 )
V_39 = V_152 ;
return F_60 ( V_151 , V_26 -> V_87 , V_39 ) ;
}
}
F_38 () ;
return NULL ;
}
static void
F_20 ( T_12 * V_45 , const char * V_154 )
{
const char * V_155 ;
char V_156 [ 8 ] ;
if ( V_45 == NULL || V_154 == NULL ) {
return;
}
for ( V_155 = V_154 ; * V_155 != '\0' ; V_155 ++ ) {
switch ( * V_155 ) {
case '&' :
fputs ( L_110 , V_45 ) ;
break;
case '<' :
fputs ( L_111 , V_45 ) ;
break;
case '>' :
fputs ( L_112 , V_45 ) ;
break;
case '"' :
fputs ( L_113 , V_45 ) ;
break;
case '\'' :
fputs ( L_114 , V_45 ) ;
break;
default:
if ( F_62 ( * V_155 ) )
fputc ( * V_155 , V_45 ) ;
else {
F_64 ( V_156 , sizeof( V_156 ) , L_115 , ( T_10 ) * V_155 ) ;
fputs ( V_156 , V_45 ) ;
}
}
}
}
static void
F_65 ( T_12 * V_45 , const char * V_154 , T_1 V_157 )
{
const char * V_155 ;
char V_156 [ 8 ] ;
if ( V_45 == NULL || V_154 == NULL ) {
return;
}
for ( V_155 = V_154 ; * V_155 != '\0' ; V_155 ++ ) {
switch ( * V_155 ) {
case '"' :
fputs ( L_100 , V_45 ) ;
break;
case '\\' :
fputs ( L_116 , V_45 ) ;
break;
case '/' :
fputs ( L_117 , V_45 ) ;
break;
case '\b' :
fputs ( L_118 , V_45 ) ;
break;
case '\f' :
fputs ( L_119 , V_45 ) ;
break;
case '\n' :
fputs ( L_120 , V_45 ) ;
break;
case '\r' :
fputs ( L_121 , V_45 ) ;
break;
case '\t' :
fputs ( L_122 , V_45 ) ;
break;
case '.' :
if ( V_157 )
fputs ( L_78 , V_45 ) ;
else
fputs ( L_123 , V_45 ) ;
break;
default:
if ( F_62 ( * V_155 ) )
fputc ( * V_155 , V_45 ) ;
else {
F_64 ( V_156 , sizeof( V_156 ) , L_124 , ( T_10 ) * V_155 ) ;
fputs ( V_156 , V_45 ) ;
}
}
}
}
static void
F_39 ( T_12 * V_45 , const char * V_154 )
{
F_65 ( V_45 , V_154 , FALSE ) ;
}
static void
F_41 ( T_12 * V_45 , const char * V_154 )
{
F_65 ( V_45 , V_154 , TRUE ) ;
}
static void
F_31 ( T_16 * V_27 , T_9 * V_26 )
{
int V_80 ;
const T_10 * V_28 ;
if ( ! V_26 -> V_153 )
return;
if ( V_26 -> V_39 > F_63 ( V_26 -> V_153 , V_26 -> V_87 ) ) {
fprintf ( V_27 -> V_45 , L_125 ) ;
return;
}
V_28 = F_15 ( V_27 -> V_15 , V_26 ) ;
if ( V_28 ) {
for ( V_80 = 0 ; V_80 < V_26 -> V_39 ; V_80 ++ ) {
fprintf ( V_27 -> V_45 , L_126 , V_28 [ V_80 ] ) ;
}
}
}
static void
F_40 ( T_17 * V_27 , T_9 * V_26 )
{
int V_80 ;
const T_10 * V_28 ;
if ( ! V_26 -> V_153 )
return;
if ( V_26 -> V_39 > F_63 ( V_26 -> V_153 , V_26 -> V_87 ) ) {
fprintf ( V_27 -> V_45 , L_125 ) ;
return;
}
V_28 = F_15 ( V_27 -> V_15 , V_26 ) ;
if ( V_28 ) {
for ( V_80 = 0 ; V_80 < V_26 -> V_39 ; V_80 ++ ) {
fprintf ( V_27 -> V_45 , L_126 , V_28 [ V_80 ] ) ;
}
}
}
T_1
F_66 ( T_5 * V_11 , T_3 * V_9 )
{
T_1 V_158 ;
T_22 * V_142 ;
T_23 * V_143 ;
char * line , * V_144 ;
const T_24 * V_145 ;
V_99 V_39 ;
struct V_147 * V_148 ;
V_158 = ( V_9 -> V_16 . V_17 -> V_116 != NULL ) ;
for ( V_142 = V_9 -> V_16 . V_17 ; V_142 != NULL ;
V_142 = V_142 -> V_116 ) {
V_148 = (struct V_147 * ) V_142 -> V_12 ;
V_143 = F_58 ( V_148 ) ;
if ( V_158 ) {
V_144 = F_61 ( V_148 ) ;
line = F_67 ( L_127 , V_144 ) ;
F_33 ( NULL , V_144 ) ;
F_12 ( V_11 , 0 , line ) ;
F_13 ( line ) ;
}
V_39 = F_59 ( V_143 ) ;
if ( V_39 == 0 )
return TRUE ;
V_145 = F_60 ( V_143 , 0 , V_39 ) ;
if ( ! F_16 ( V_11 , V_145 , V_39 ,
( V_19 ) V_9 -> V_16 . V_20 -> V_21 . V_18 ) )
return FALSE ;
}
return TRUE ;
}
static T_1
F_16 ( T_5 * V_11 , const T_24 * V_145 ,
V_99 V_39 , V_19 V_18 )
{
register unsigned int V_159 , V_80 , V_150 , V_160 , V_161 ;
T_24 V_162 ;
T_11 line [ V_163 + 1 ] ;
unsigned int V_164 ;
static T_11 V_165 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ( ( V_39 - 1 ) & 0xF0000000 ) != 0 )
V_164 = 8 ;
else if ( ( ( V_39 - 1 ) & 0x0F000000 ) != 0 )
V_164 = 7 ;
else if ( ( ( V_39 - 1 ) & 0x00F00000 ) != 0 )
V_164 = 6 ;
else if ( ( ( V_39 - 1 ) & 0x000F0000 ) != 0 )
V_164 = 5 ;
else
V_164 = 4 ;
V_159 = 0 ;
V_80 = 0 ;
V_150 = 0 ;
V_160 = 0 ;
while ( V_80 < V_39 ) {
if ( ( V_80 & 15 ) == 0 ) {
V_150 = 0 ;
V_161 = V_164 ;
do {
V_161 -- ;
V_162 = ( V_159 >> ( V_161 * 4 ) ) & 0xF ;
line [ V_150 ++ ] = V_165 [ V_162 ] ;
} while ( V_161 != 0 );
line [ V_150 ++ ] = ' ' ;
line [ V_150 ++ ] = ' ' ;
memset ( line + V_150 , ' ' , V_166 ) ;
V_160 = V_150 + V_167 + 2 ;
}
V_162 = * V_145 ++ ;
line [ V_150 ++ ] = V_165 [ V_162 >> 4 ] ;
line [ V_150 ++ ] = V_165 [ V_162 & 0xf ] ;
V_150 ++ ;
if ( V_18 == V_168 ) {
V_162 = F_68 ( V_162 ) ;
}
line [ V_160 ++ ] = ( ( V_162 >= ' ' ) && ( V_162 < 0x7f ) ) ? V_162 : '.' ;
V_80 ++ ;
if ( ( ( V_80 & 15 ) == 0 ) || ( V_80 == V_39 ) ) {
line [ V_160 ] = '\0' ;
if ( ! F_12 ( V_11 , 0 , line ) )
return FALSE ;
V_159 += 16 ;
}
}
return TRUE ;
}
T_25 F_69 ( T_14 * V_61 )
{
F_7 ( V_61 ) ;
if ( NULL == V_61 -> V_61 ) {
return 0 ;
} else {
return V_61 -> V_61 -> V_122 ;
}
}
void F_70 ( T_14 * V_61 )
{
F_7 ( V_61 ) ;
if ( NULL != V_61 -> V_61 ) {
T_25 V_80 ;
if ( NULL != V_61 -> V_169 ) {
F_71 ( V_61 -> V_169 ) ;
}
if ( NULL != V_61 -> V_170 ) {
F_13 ( V_61 -> V_170 ) ;
}
for( V_80 = 0 ; V_80 < V_61 -> V_61 -> V_122 ; ++ V_80 ) {
T_11 * V_171 = ( T_11 * ) F_72 ( V_61 -> V_61 , V_80 ) ;
F_13 ( V_171 ) ;
}
F_45 ( V_61 -> V_61 , TRUE ) ;
}
F_13 ( V_61 ) ;
}
void F_73 ( T_14 * V_61 , const T_11 * V_171 )
{
T_11 * V_172 ;
F_7 ( V_61 ) ;
F_7 ( V_171 ) ;
if ( NULL == V_61 -> V_61 ) {
V_61 -> V_61 = F_74 () ;
}
V_172 = F_42 ( V_171 ) ;
F_75 ( V_61 -> V_61 , V_172 ) ;
if ( ! strncmp ( V_171 , V_173 , strlen ( V_173 ) ) )
V_61 -> V_174 = TRUE ;
}
static void
F_76 ( void * V_12 , void * V_175 )
{
T_11 * V_171 = ( T_11 * ) V_12 ;
T_22 * * V_176 = ( T_22 * * ) V_175 ;
if ( ! strncmp ( V_171 , V_173 , strlen ( V_173 ) ) )
return;
if ( ! F_77 ( V_171 ) ) {
* V_176 = F_78 ( * V_176 , V_171 ) ;
}
}
T_22 *
F_79 ( T_14 * V_61 )
{
T_22 * V_176 = NULL ;
if ( V_61 -> V_61 == NULL ) {
return NULL ;
}
F_80 ( V_61 -> V_61 , F_76 , & V_176 ) ;
return V_176 ;
}
T_1 F_81 ( T_14 * V_177 , T_11 * V_178 )
{
const T_11 * V_179 ;
const T_11 * V_180 ;
F_7 ( V_177 ) ;
F_7 ( V_178 ) ;
if ( '\0' == * V_178 ) {
return FALSE ;
}
V_179 = strtok ( V_178 , L_128 ) ;
if ( ! V_179 ) {
return FALSE ;
}
V_180 = V_178 + strlen ( V_179 ) + 1 ;
if ( * V_180 == '\0' ) {
return FALSE ;
}
if ( 0 == strcmp ( V_179 , L_129 ) ) {
switch ( * V_180 ) {
case 'n' :
V_177 -> V_181 = FALSE ;
break;
case 'y' :
V_177 -> V_181 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_179 , L_130 ) ) {
switch ( * V_180 ) {
case '/' :
switch ( * ++ V_180 ) {
case 't' :
V_177 -> V_182 = '\t' ;
break;
case 's' :
V_177 -> V_182 = ' ' ;
break;
default:
V_177 -> V_182 = '\\' ;
}
break;
default:
V_177 -> V_182 = * V_180 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_179 , L_131 ) ) {
switch ( * V_180 ) {
case 'f' :
case 'l' :
case 'a' :
V_177 -> V_183 = * V_180 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_179 , L_132 ) ) {
switch ( * V_180 ) {
case '/' :
switch ( * ++ V_180 ) {
case 's' :
V_177 -> V_184 = ' ' ;
break;
default:
V_177 -> V_184 = '\\' ;
}
break;
default:
V_177 -> V_184 = * V_180 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_179 , L_133 ) ) {
switch ( * V_180 ) {
case 'd' :
V_177 -> V_185 = '"' ;
break;
case 's' :
V_177 -> V_185 = '\'' ;
break;
case 'n' :
V_177 -> V_185 = '\0' ;
break;
default:
V_177 -> V_185 = '\0' ;
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_179 , L_134 ) ) {
switch ( * V_180 ) {
case 'n' :
V_177 -> V_186 = FALSE ;
break;
case 'y' :
V_177 -> V_186 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
void F_82 ( T_12 * V_45 )
{
fprintf ( V_45 , L_135 ) ;
fputs ( L_136 , V_45 ) ;
fputs ( L_137 , V_45 ) ;
fputs ( L_138 , V_45 ) ;
fputs ( L_139 , V_45 ) ;
fputs ( L_140 , V_45 ) ;
fputs ( L_141 , V_45 ) ;
}
T_1 F_83 ( T_14 * V_61 )
{
F_7 ( V_61 ) ;
return V_61 -> V_174 ;
}
void F_84 ( T_14 * V_61 , T_12 * V_45 )
{
T_25 V_80 ;
F_7 ( V_61 ) ;
F_7 ( V_45 ) ;
F_7 ( V_61 -> V_61 ) ;
if ( V_61 -> V_186 ) {
fputs ( V_187 , V_45 ) ;
}
if ( ! V_61 -> V_181 ) {
return;
}
for( V_80 = 0 ; V_80 < V_61 -> V_61 -> V_122 ; ++ V_80 ) {
const T_11 * V_171 = ( const T_11 * ) F_72 ( V_61 -> V_61 , V_80 ) ;
if ( V_80 != 0 ) {
fputc ( V_61 -> V_182 , V_45 ) ;
}
fputs ( V_171 , V_45 ) ;
}
fputc ( '\n' , V_45 ) ;
}
static void F_85 ( T_14 * V_61 , T_8 V_188 , const T_11 * V_90 )
{
V_99 V_189 ;
T_20 * V_190 ;
if ( NULL == V_90 )
return;
V_189 = F_86 ( V_188 ) - 1 ;
if ( V_61 -> V_170 [ V_189 ] == NULL ) {
V_61 -> V_170 [ V_189 ] = F_74 () ;
}
V_190 = V_61 -> V_170 [ V_189 ] ;
switch ( V_61 -> V_183 ) {
case 'f' :
if ( F_44 ( V_190 ) != 0 )
return;
break;
case 'l' :
F_87 ( V_190 , 0 ) ;
break;
case 'a' :
if ( F_44 ( V_190 ) > 0 ) {
F_75 ( V_190 , ( T_8 ) F_67 ( L_142 , V_61 -> V_184 ) ) ;
}
break;
default:
F_38 () ;
break;
}
F_75 ( V_190 , ( T_8 ) V_90 ) ;
}
static void F_88 ( T_7 * V_25 , T_8 V_12 )
{
T_26 * V_191 ;
T_9 * V_26 ;
T_8 V_188 ;
V_191 = ( T_26 * ) V_12 ;
V_26 = F_6 ( V_25 ) ;
F_7 ( V_26 ) ;
V_188 = F_14 ( V_191 -> V_61 -> V_169 , V_26 -> V_36 -> V_37 ) ;
if ( NULL != V_188 ) {
F_85 ( V_191 -> V_61 , V_188 ,
F_89 ( V_26 , V_191 -> V_9 )
) ;
}
if ( V_25 -> V_44 != NULL ) {
F_5 ( V_25 , F_88 ,
V_191 ) ;
}
}
static void F_25 ( T_27 V_192 , T_14 * V_61 , T_3 * V_9 , T_18 * V_78 , T_12 * V_45 )
{
T_25 V_80 ;
T_1 V_193 = TRUE ;
T_21 V_194 ;
T_11 * V_195 ;
T_8 V_188 ;
T_26 V_12 ;
F_7 ( V_61 ) ;
F_7 ( V_61 -> V_61 ) ;
F_7 ( V_9 ) ;
F_7 ( V_45 ) ;
V_12 . V_61 = V_61 ;
V_12 . V_9 = V_9 ;
if ( NULL == V_61 -> V_169 ) {
V_61 -> V_169 = F_90 ( V_196 , V_197 ) ;
V_80 = 0 ;
while ( V_80 < V_61 -> V_61 -> V_122 ) {
T_11 * V_171 = ( T_11 * ) F_72 ( V_61 -> V_61 , V_80 ) ;
++ V_80 ;
F_91 ( V_61 -> V_169 , V_171 , F_92 ( V_80 ) ) ;
}
}
if ( NULL == V_61 -> V_170 )
V_61 -> V_170 = F_93 ( T_20 * , V_61 -> V_61 -> V_122 ) ;
F_5 ( V_9 -> V_23 , F_88 ,
& V_12 ) ;
switch ( V_192 ) {
case V_79 :
if ( V_61 -> V_174 ) {
for ( V_194 = 0 ; V_194 < V_78 -> V_131 ; V_194 ++ ) {
V_195 = F_67 ( L_143 , V_173 , V_78 -> V_132 [ V_194 ] . V_133 ) ;
V_188 = F_14 ( V_61 -> V_169 , V_195 ) ;
F_13 ( V_195 ) ;
if ( NULL != V_188 ) {
F_85 ( V_61 , V_188 , F_42 ( V_78 -> V_132 [ V_194 ] . V_134 ) ) ;
}
}
}
for( V_80 = 0 ; V_80 < V_61 -> V_61 -> V_122 ; ++ V_80 ) {
if ( 0 != V_80 ) {
fputc ( V_61 -> V_182 , V_45 ) ;
}
if ( NULL != V_61 -> V_170 [ V_80 ] ) {
T_20 * V_190 ;
T_11 * V_58 ;
T_25 V_150 ;
V_190 = V_61 -> V_170 [ V_80 ] ;
if ( V_61 -> V_185 != '\0' ) {
fputc ( V_61 -> V_185 , V_45 ) ;
}
for ( V_150 = 0 ; V_150 < F_44 ( V_190 ) ; V_150 ++ ) {
V_58 = ( T_11 * ) F_72 ( V_190 , V_150 ) ;
fputs ( V_58 , V_45 ) ;
F_13 ( V_58 ) ;
}
if ( V_61 -> V_185 != '\0' ) {
fputc ( V_61 -> V_185 , V_45 ) ;
}
F_45 ( V_190 , TRUE ) ;
V_61 -> V_170 [ V_80 ] = NULL ;
}
}
break;
case V_66 :
for( V_80 = 0 ; V_80 < V_61 -> V_61 -> V_122 ; ++ V_80 ) {
T_11 * V_171 = ( T_11 * ) F_72 ( V_61 -> V_61 , V_80 ) ;
if ( NULL != V_61 -> V_170 [ V_80 ] ) {
T_20 * V_190 ;
T_11 * V_58 ;
T_25 V_150 ;
V_190 = V_61 -> V_170 [ V_80 ] ;
for ( V_150 = 0 ; V_150 < ( F_44 ( V_190 ) ) ; V_150 += 2 ) {
V_58 = ( T_11 * ) F_72 ( V_190 , V_150 ) ;
fprintf ( V_45 , L_144 , V_171 ) ;
fputs ( L_60 , V_45 ) ;
F_20 ( V_45 , V_58 ) ;
fputs ( L_46 , V_45 ) ;
F_13 ( V_58 ) ;
}
F_45 ( V_190 , TRUE ) ;
V_61 -> V_170 [ V_80 ] = NULL ;
}
}
break;
case V_70 :
for( V_80 = 0 ; V_80 < V_61 -> V_61 -> V_122 ; ++ V_80 ) {
T_11 * V_171 = ( T_11 * ) F_72 ( V_61 -> V_61 , V_80 ) ;
if ( NULL != V_61 -> V_170 [ V_80 ] ) {
T_20 * V_190 ;
T_11 * V_58 ;
T_25 V_150 ;
V_190 = V_61 -> V_170 [ V_80 ] ;
for ( V_150 = 0 ; V_150 < ( F_44 ( V_190 ) ) ; V_150 += 2 ) {
V_58 = ( T_11 * ) F_72 ( V_190 , V_150 ) ;
if ( V_150 == 0 ) {
if ( ! V_193 ) {
fputs ( L_145 , V_45 ) ;
}
fprintf ( V_45 , L_146 , V_171 ) ;
}
fputs ( L_60 , V_45 ) ;
F_39 ( V_45 , V_58 ) ;
fputs ( L_60 , V_45 ) ;
F_13 ( V_58 ) ;
if ( V_150 + 2 < ( F_44 ( V_190 ) ) ) {
fputs ( L_85 , V_45 ) ;
}
else {
fputs ( L_8 , V_45 ) ;
}
}
V_193 = FALSE ;
F_45 ( V_190 , TRUE ) ;
V_61 -> V_170 [ V_80 ] = NULL ;
}
}
fputc ( '\n' , V_45 ) ;
break;
case V_77 :
for( V_80 = 0 ; V_80 < V_61 -> V_61 -> V_122 ; ++ V_80 ) {
T_11 * V_171 = ( T_11 * ) F_72 ( V_61 -> V_61 , V_80 ) ;
if ( NULL != V_61 -> V_170 [ V_80 ] ) {
T_20 * V_190 ;
T_11 * V_58 ;
T_25 V_150 ;
V_190 = V_61 -> V_170 [ V_80 ] ;
for ( V_150 = 0 ; V_150 < ( F_44 ( V_190 ) ) ; V_150 += 2 ) {
V_58 = ( T_11 * ) F_72 ( V_190 , V_150 ) ;
if ( V_150 == 0 ) {
if ( ! V_193 ) {
fputs ( L_85 , V_45 ) ;
}
fputs ( L_60 , V_45 ) ;
F_41 ( V_45 , V_171 ) ;
fputs ( L_147 , V_45 ) ;
}
fputs ( L_60 , V_45 ) ;
F_39 ( V_45 , V_58 ) ;
fputs ( L_60 , V_45 ) ;
F_13 ( V_58 ) ;
if ( V_150 + 2 < ( F_44 ( V_190 ) ) ) {
fputs ( L_85 , V_45 ) ;
}
else {
fputs ( L_8 , V_45 ) ;
}
}
V_193 = FALSE ;
F_45 ( V_190 , TRUE ) ;
V_61 -> V_170 [ V_80 ] = NULL ;
}
}
break;
default:
fprintf ( V_198 , L_148 , V_192 ) ;
F_38 () ;
break;
}
}
void F_94 ( T_14 * V_61 V_199 , T_12 * V_45 V_199 )
{
}
T_11 * F_89 ( T_9 * V_26 , T_3 * V_9 )
{
if ( V_26 -> V_36 -> V_38 == V_84 ) {
if ( V_26 -> V_34 ) {
return F_42 ( V_26 -> V_34 -> V_35 ) ;
}
else {
return F_95 ( V_9 -> V_16 . V_17 , V_26 ) ;
}
}
else if ( V_26 -> V_36 -> V_38 == V_1 ) {
return F_95 ( V_9 -> V_16 . V_17 , V_26 ) ;
}
else {
T_11 * V_81 ;
switch ( V_26 -> V_36 -> type )
{
case V_83 :
if ( V_26 -> V_34 ) {
return F_42 ( V_26 -> V_34 -> V_35 ) ;
} else {
return F_42 ( V_26 -> V_36 -> V_37 ) ;
}
case V_89 :
return F_42 ( L_149 ) ;
default:
V_81 = F_32 ( NULL , & V_26 -> V_90 , V_91 , V_26 -> V_36 -> V_92 ) ;
if ( V_81 != NULL ) {
T_11 * V_200 = F_42 ( V_81 ) ;
F_33 ( NULL , V_81 ) ;
return V_200 ;
} else {
return F_95 ( V_9 -> V_16 . V_17 , V_26 ) ;
}
}
}
}
static T_11 *
F_95 ( T_22 * V_15 , T_9 * V_26 )
{
const T_10 * V_28 ;
if ( ! V_26 -> V_153 )
return NULL ;
if ( V_26 -> V_39 > F_63 ( V_26 -> V_153 , V_26 -> V_87 ) ) {
return F_42 ( L_125 ) ;
}
V_28 = F_15 ( V_15 , V_26 ) ;
if ( V_28 ) {
int V_80 ;
T_11 * V_201 ;
T_11 * V_155 ;
int V_122 ;
const int V_202 = 2 ;
V_122 = V_202 * V_26 -> V_39 ;
V_201 = ( T_11 * ) F_96 ( sizeof( T_11 ) * ( V_122 + 1 ) ) ;
V_201 [ V_122 ] = '\0' ;
V_155 = V_201 ;
for ( V_80 = 0 ; V_80 < V_26 -> V_39 ; V_80 ++ ) {
F_64 ( V_155 , V_202 + 1 , L_126 , V_28 [ V_80 ] ) ;
V_155 += V_202 ;
}
return V_201 ;
} else {
return NULL ;
}
}
T_14 * F_97 ( void )
{
T_14 * V_61 = F_98 ( T_14 , 1 ) ;
V_61 -> V_186 = FALSE ;
V_61 -> V_181 = FALSE ;
V_61 -> V_182 = '\t' ;
V_61 -> V_183 = 'a' ;
V_61 -> V_184 = ',' ;
V_61 -> V_61 = NULL ;
V_61 -> V_169 = NULL ;
V_61 -> V_170 = NULL ;
V_61 -> V_185 = '\0' ;
V_61 -> V_174 = FALSE ;
return V_61 ;
}
