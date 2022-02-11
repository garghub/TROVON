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
F_4 ( T_2 * V_7 , T_3 * V_8 ,
T_4 * V_9 , T_5 * V_10 )
{
T_6 V_11 ;
V_11 . V_12 = 0 ;
V_11 . V_10 = V_10 ;
V_11 . V_13 = TRUE ;
V_11 . V_14 = V_8 -> V_15 . V_16 ;
V_11 . V_17 = ( V_18 ) V_8 -> V_15 . V_19 -> V_20 . V_17 ;
V_11 . V_21 = V_7 -> V_21 ;
V_11 . V_22 = ! V_7 -> V_23 ;
V_11 . V_9 = V_9 ;
F_5 ( V_8 -> V_24 , V_25 , & V_11 ) ;
return V_11 . V_13 ;
}
static void
V_25 ( T_7 * V_26 , T_8 V_11 )
{
T_9 * V_27 = F_6 ( V_26 ) ;
T_6 * V_28 = ( T_6 * ) V_11 ;
const T_10 * V_29 ;
T_11 V_30 [ V_31 ] ;
T_11 * V_32 ;
F_7 ( V_27 ) ;
if ( F_8 ( V_26 ) )
return;
if ( ! V_28 -> V_13 )
return;
if ( V_27 -> V_33 ) {
V_32 = V_27 -> V_33 -> V_34 ;
}
else {
V_32 = V_30 ;
F_9 ( V_27 , V_30 ) ;
}
if ( F_10 ( V_26 ) )
V_32 = F_11 ( L_7 , V_32 , L_8 , NULL ) ;
V_28 -> V_13 = F_12 ( V_28 -> V_10 , V_28 -> V_12 , V_32 ) ;
if ( F_10 ( V_26 ) )
F_13 ( V_32 ) ;
if ( ! V_28 -> V_13 )
return;
if ( ( V_28 -> V_9 != NULL ) && ( V_28 -> V_12 == 0 )
&& ( F_14 ( V_28 -> V_9 , V_27 -> V_35 -> V_36 ) == NULL ) ) {
return;
}
if ( ( V_27 -> V_35 -> V_37 == V_1 ) && ( V_28 -> V_22 ) ) {
V_29 = F_15 ( V_28 -> V_14 , V_27 ) ;
if ( V_29 ) {
if ( ! F_12 ( V_28 -> V_10 , 0 , L_9 ) ) {
V_28 -> V_13 = FALSE ;
return;
}
if ( ! F_16 ( V_28 -> V_10 , V_29 ,
V_27 -> V_38 , V_28 -> V_17 ) ) {
V_28 -> V_13 = FALSE ;
return;
}
}
}
F_7 ( ( V_27 -> V_39 >= - 1 ) && ( V_27 -> V_39 < V_40 ) ) ;
if ( ( V_28 -> V_21 == V_41 ) ||
( ( V_28 -> V_21 == V_42 ) &&
( V_27 -> V_39 >= 0 ) && F_17 ( V_27 -> V_39 ) ) ) {
if ( V_26 -> V_43 != NULL ) {
V_28 -> V_12 ++ ;
F_5 ( V_26 ,
V_25 , V_28 ) ;
V_28 -> V_12 -- ;
if ( ! V_28 -> V_13 )
return;
}
}
}
void
F_18 ( T_12 * V_44 , const T_11 * V_45 )
{
T_13 V_46 = time ( NULL ) ;
char * V_47 = asctime ( localtime ( & V_46 ) ) ;
V_47 [ strlen ( V_47 ) - 1 ] = 0 ;
fputs ( L_10 , V_44 ) ;
fputs ( L_11 V_48 L_12 , V_44 ) ;
fprintf ( V_44 , L_13 V_48 L_14 V_48 L_15 , F_19 () ) ;
fputs ( L_16 V_49 L_17 , V_44 ) ;
fprintf ( V_44 , L_18 , V_50 , V_51 , V_47 , V_45 ? V_45 : L_9 ) ;
}
void
F_20 ( T_12 * V_44 )
{
fputs ( L_19 , V_44 ) ;
}
static T_1 F_21 ( T_11 * * V_52 , const char * V_53 )
{
T_1 V_54 = FALSE ;
T_11 * * V_55 ;
if ( V_53 == NULL || V_52 == NULL ) {
return FALSE ;
}
for ( V_55 = V_52 ; * V_55 ; V_55 ++ ) {
if ( strcmp ( * V_55 , V_53 ) == 0 ) {
V_54 = TRUE ;
break;
}
}
return V_54 ;
}
void
F_22 ( T_14 * V_56 , T_11 * * V_52 , T_3 * V_8 , T_12 * V_44 )
{
T_15 V_11 ;
F_7 ( V_8 ) ;
F_7 ( V_44 ) ;
fprintf ( V_44 , L_20 ) ;
F_23 ( V_8 -> V_24 , V_44 ) ;
if ( V_56 == NULL || V_56 -> V_56 == NULL ) {
V_11 . V_12 = 0 ;
V_11 . V_44 = V_44 ;
V_11 . V_14 = V_8 -> V_15 . V_16 ;
V_11 . V_57 = V_52 ;
F_5 ( V_8 -> V_24 , V_58 ,
& V_11 ) ;
} else {
F_24 ( V_59 , V_56 , V_8 , NULL , V_44 ) ;
}
fprintf ( V_44 , L_21 ) ;
}
void
F_25 ( T_14 * V_56 , T_2 * V_7 , T_11 * * V_52 , T_3 * V_8 , T_12 * V_44 )
{
T_16 V_11 ;
char V_47 [ 30 ] ;
T_13 V_46 = time ( NULL ) ;
struct V_60 * V_61 ;
static T_1 V_62 = TRUE ;
F_7 ( V_8 ) ;
F_7 ( V_44 ) ;
V_61 = localtime ( & V_46 ) ;
strftime ( V_47 , 30 , L_22 , V_61 ) ;
if ( ! V_62 )
fputs ( L_23 , V_44 ) ;
else
V_62 = FALSE ;
fputs ( L_24 , V_44 ) ;
fprintf ( V_44 , L_25 , V_47 ) ;
fputs ( L_26 , V_44 ) ;
fputs ( L_27 , V_44 ) ;
fputs ( L_28 , V_44 ) ;
fputs ( L_29 , V_44 ) ;
if ( V_56 == NULL || V_56 -> V_56 == NULL ) {
V_11 . V_12 = 1 ;
V_11 . V_44 = V_44 ;
V_11 . V_14 = V_8 -> V_15 . V_16 ;
V_11 . V_57 = V_52 ;
V_11 . V_23 = V_7 -> V_23 ;
F_5 ( V_8 -> V_24 , V_63 ,
& V_11 ) ;
} else {
F_24 ( V_64 , V_56 , V_8 , NULL , V_44 ) ;
}
fputs ( L_30 , V_44 ) ;
fputs ( L_31 , V_44 ) ;
fputs ( L_32 , V_44 ) ;
}
void
F_26 ( T_14 * V_56 , T_2 * V_7 , T_11 * * V_52 , T_3 * V_8 , T_12 * V_44 )
{
T_16 V_11 ;
char V_47 [ 30 ] ;
T_13 V_46 = time ( NULL ) ;
struct V_60 * V_61 ;
T_17 * V_65 ;
T_18 * V_66 ;
F_7 ( V_8 ) ;
F_7 ( V_44 ) ;
V_61 = localtime ( & V_46 ) ;
strftime ( V_47 , 30 , L_22 , V_61 ) ;
V_66 = F_27 ( V_8 -> V_24 , V_2 ) ;
if ( F_28 ( V_66 ) < 1 ) {
return;
}
V_66 = F_27 ( V_8 -> V_24 , V_3 ) ;
if ( F_28 ( V_66 ) < 1 ) {
return;
}
V_65 = ( T_17 * ) F_29 ( & ( ( T_9 * ) V_66 -> V_28 [ 0 ] ) -> V_67 ) ;
F_30 ( V_66 , TRUE ) ;
fprintf ( V_44 , L_33 , V_47 ) ;
fprintf ( V_44 , L_34 V_68 L_35 , ( V_69 ) V_65 -> V_70 , V_65 -> V_71 / 1000000 ) ;
if ( V_56 == NULL || V_56 -> V_56 == NULL ) {
V_11 . V_12 = 0 ;
V_11 . V_44 = V_44 ;
V_11 . V_14 = V_8 -> V_15 . V_16 ;
V_11 . V_57 = V_52 ;
V_11 . V_23 = V_7 -> V_23 ;
F_5 ( V_8 -> V_24 , V_72 ,
& V_11 ) ;
} else {
F_24 ( V_73 , V_56 , V_8 , NULL , V_44 ) ;
}
fputs ( L_36 , V_44 ) ;
}
void
F_31 ( T_14 * V_56 , T_3 * V_8 , T_19 * V_74 , T_12 * V_44 )
{
F_7 ( V_8 ) ;
F_7 ( V_44 ) ;
F_24 ( V_75 , V_56 , V_8 , V_74 , V_44 ) ;
}
static void
V_58 ( T_7 * V_26 , T_8 V_11 )
{
T_9 * V_27 = F_6 ( V_26 ) ;
T_15 * V_28 = ( T_15 * ) V_11 ;
const T_11 * V_32 ;
T_11 V_30 [ V_31 ] ;
char * V_76 ;
int V_77 ;
T_1 V_78 ;
F_7 ( V_27 ) ;
V_78 =
( ( ( V_27 -> V_35 -> type != V_79 ) ||
( V_27 -> V_35 -> V_37 == V_1 ) ) &&
( V_28 -> V_12 == 0 ) ) ;
for ( V_77 = - 1 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
if ( V_78 ) {
fputs ( L_38 , V_28 -> V_44 ) ;
V_28 -> V_12 ++ ;
for ( V_77 = - 1 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
}
if ( V_27 -> V_35 -> V_37 == V_80 ) {
if ( V_27 -> V_33 ) {
V_32 = V_27 -> V_33 -> V_34 ;
}
else {
V_32 = L_9 ;
}
fputs ( L_39 , V_28 -> V_44 ) ;
fputs ( L_40 , V_28 -> V_44 ) ;
F_32 ( V_28 -> V_44 , V_32 ) ;
fprintf ( V_28 -> V_44 , L_41 , V_27 -> V_38 ) ;
if ( V_26 -> V_81 && V_26 -> V_81 -> V_82 && ( V_27 -> V_83 < V_26 -> V_81 -> V_82 -> V_83 ) ) {
fprintf ( V_28 -> V_44 , L_42 , V_26 -> V_81 -> V_82 -> V_83 + V_27 -> V_83 ) ;
} else {
fprintf ( V_28 -> V_44 , L_42 , V_27 -> V_83 ) ;
}
if ( V_27 -> V_38 > 0 ) {
fputs ( L_43 , V_28 -> V_44 ) ;
F_33 ( V_28 , V_27 ) ;
}
if ( V_26 -> V_43 != NULL ) {
fputs ( L_44 , V_28 -> V_44 ) ;
}
else {
fputs ( L_45 , V_28 -> V_44 ) ;
}
}
else if ( V_27 -> V_35 -> V_37 == V_1 ) {
fputs ( L_46 , V_28 -> V_44 ) ;
F_33 ( V_28 , V_27 ) ;
fputs ( L_44 , V_28 -> V_44 ) ;
}
else {
if ( ( V_27 -> V_35 -> type == V_79 ) && ( V_27 -> V_35 -> V_37 != V_84 ) ) {
fputs ( L_47 , V_28 -> V_44 ) ;
}
else {
fputs ( L_39 , V_28 -> V_44 ) ;
}
F_32 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if ( V_27 -> V_33 ) {
fputs ( L_48 , V_28 -> V_44 ) ;
F_32 ( V_28 -> V_44 , V_27 -> V_33 -> V_34 ) ;
}
else {
V_32 = V_30 ;
F_9 ( V_27 , V_30 ) ;
fputs ( L_48 , V_28 -> V_44 ) ;
F_32 ( V_28 -> V_44 , V_32 ) ;
}
if ( F_8 ( V_26 ) )
fprintf ( V_28 -> V_44 , L_49 ) ;
fprintf ( V_28 -> V_44 , L_41 , V_27 -> V_38 ) ;
if ( V_26 -> V_81 && V_26 -> V_81 -> V_82 && ( V_27 -> V_83 < V_26 -> V_81 -> V_82 -> V_83 ) ) {
fprintf ( V_28 -> V_44 , L_42 , V_26 -> V_81 -> V_82 -> V_83 + V_27 -> V_83 ) ;
} else {
fprintf ( V_28 -> V_44 , L_42 , V_27 -> V_83 ) ;
}
switch ( V_27 -> V_35 -> type )
{
case V_79 :
break;
case V_85 :
fputs ( L_50 , V_28 -> V_44 ) ;
break;
default:
V_76 = F_34 ( NULL , & V_27 -> V_67 , V_86 , V_27 -> V_35 -> V_87 ) ;
if ( V_76 != NULL ) {
fputs ( L_40 , V_28 -> V_44 ) ;
F_32 ( V_28 -> V_44 , V_76 ) ;
}
F_35 ( NULL , V_76 ) ;
if ( V_27 -> V_38 > 0 ) {
fputs ( L_43 , V_28 -> V_44 ) ;
if ( V_27 -> V_35 -> V_88 != 0 ) {
switch ( V_27 -> V_67 . V_89 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
fprintf ( V_28 -> V_44 , L_51 , ( V_94 ) F_36 ( & V_27 -> V_67 ) ) ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
fprintf ( V_28 -> V_44 , L_51 , F_37 ( & V_27 -> V_67 ) ) ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
fprintf ( V_28 -> V_44 , L_52 V_103 L_53 , F_38 ( & V_27 -> V_67 ) ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
fprintf ( V_28 -> V_44 , L_52 V_103 L_53 , F_39 ( & V_27 -> V_67 ) ) ;
break;
default:
F_40 () ;
}
fputs ( L_54 , V_28 -> V_44 ) ;
F_33 ( V_28 , V_27 ) ;
}
else {
F_33 ( V_28 , V_27 ) ;
}
}
}
if ( V_26 -> V_43 != NULL ) {
fputs ( L_44 , V_28 -> V_44 ) ;
}
else if ( V_27 -> V_35 -> V_37 == V_1 ) {
fputs ( L_44 , V_28 -> V_44 ) ;
}
else {
fputs ( L_45 , V_28 -> V_44 ) ;
}
}
if ( V_26 -> V_43 != NULL ) {
if ( V_28 -> V_57 == NULL || F_21 ( V_28 -> V_57 , V_27 -> V_35 -> V_36 ) ) {
V_28 -> V_12 ++ ;
F_5 ( V_26 ,
V_58 , V_28 ) ;
V_28 -> V_12 -- ;
} else {
for ( V_77 = - 2 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
fputs ( L_55 , V_28 -> V_44 ) ;
F_32 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
fputs ( L_56 , V_28 -> V_44 ) ;
}
}
if ( V_78 ) {
V_28 -> V_12 -- ;
}
if ( V_26 -> V_43 != NULL ) {
for ( V_77 = - 1 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
if ( ( V_27 -> V_35 -> V_37 != V_1 ) && ( V_27 -> V_35 -> V_37 != V_84 ) ) {
if ( V_27 -> V_35 -> type == V_79 ) {
fputs ( L_57 , V_28 -> V_44 ) ;
}
else {
fputs ( L_58 , V_28 -> V_44 ) ;
}
} else {
fputs ( L_58 , V_28 -> V_44 ) ;
}
}
if ( V_78 ) {
fputs ( L_57 , V_28 -> V_44 ) ;
}
}
static void
V_63 ( T_7 * V_26 , T_8 V_11 )
{
T_9 * V_27 = F_6 ( V_26 ) ;
T_16 * V_28 = ( T_16 * ) V_11 ;
const T_11 * V_32 ;
T_11 V_30 [ V_31 ] ;
char * V_76 ;
int V_77 ;
F_7 ( V_27 ) ;
for ( V_77 = - 3 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
if ( V_27 -> V_35 -> V_37 == V_80 ) {
if ( V_27 -> V_33 ) {
V_32 = V_27 -> V_33 -> V_34 ;
}
else {
V_32 = L_9 ;
}
fputs ( L_59 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_32 ) ;
if ( V_26 -> V_43 != NULL ) {
fputs ( L_60 , V_28 -> V_44 ) ;
}
else {
if ( V_26 -> V_109 == NULL ) {
fputs ( L_61 , V_28 -> V_44 ) ;
} else {
fputs ( L_62 , V_28 -> V_44 ) ;
}
}
}
else {
if ( V_28 -> V_23 && V_27 -> V_38 > 0 ) {
fputs ( L_59 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
fputs ( L_63 , V_28 -> V_44 ) ;
fputs ( L_64 , V_28 -> V_44 ) ;
if ( V_27 -> V_35 -> V_88 != 0 ) {
switch ( V_27 -> V_67 . V_89 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
fprintf ( V_28 -> V_44 , L_51 , ( V_94 ) F_36 ( & V_27 -> V_67 ) ) ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
fprintf ( V_28 -> V_44 , L_51 , F_37 ( & V_27 -> V_67 ) ) ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
fprintf ( V_28 -> V_44 , L_52 V_103 L_53 , F_38 ( & V_27 -> V_67 ) ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
fprintf ( V_28 -> V_44 , L_52 V_103 L_53 , F_39 ( & V_27 -> V_67 ) ) ;
break;
default:
F_40 () ;
}
fputs ( L_65 , V_28 -> V_44 ) ;
}
else {
F_42 ( V_28 , V_27 ) ;
fputs ( L_65 , V_28 -> V_44 ) ;
}
for ( V_77 = - 3 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
}
fputs ( L_59 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
switch ( V_27 -> V_35 -> type )
{
case V_79 :
if ( V_26 -> V_43 != NULL ) {
fputs ( L_60 , V_28 -> V_44 ) ;
} else {
fputs ( L_64 , V_28 -> V_44 ) ;
if ( V_27 -> V_33 ) {
F_41 ( V_28 -> V_44 , V_27 -> V_33 -> V_34 ) ;
}
else {
V_32 = V_30 ;
F_9 ( V_27 , V_30 ) ;
F_41 ( V_28 -> V_44 , V_32 ) ;
}
if ( V_26 -> V_109 == NULL ) {
fputs ( L_66 , V_28 -> V_44 ) ;
} else {
fputs ( L_65 , V_28 -> V_44 ) ;
}
}
break;
case V_85 :
if ( V_26 -> V_43 != NULL ) {
fputs ( L_60 , V_28 -> V_44 ) ;
} else {
if ( V_26 -> V_109 == NULL ) {
fputs ( L_61 , V_28 -> V_44 ) ;
} else {
fputs ( L_62 , V_28 -> V_44 ) ;
}
}
break;
default:
V_76 = F_34 ( NULL , & V_27 -> V_67 , V_86 , V_27 -> V_35 -> V_87 ) ;
if ( V_76 != NULL ) {
if ( V_26 -> V_43 == NULL ) {
fputs ( L_64 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_76 ) ;
} else {
fputs ( L_60 , V_28 -> V_44 ) ;
}
}
F_35 ( NULL , V_76 ) ;
if ( V_26 -> V_43 == NULL ) {
if ( V_26 -> V_109 == NULL ) {
fputs ( L_66 , V_28 -> V_44 ) ;
} else {
fputs ( L_65 , V_28 -> V_44 ) ;
}
}
}
}
if ( V_26 -> V_43 != NULL ) {
if ( V_28 -> V_57 == NULL || F_21 ( V_28 -> V_57 , V_27 -> V_35 -> V_36 ) ) {
V_28 -> V_12 ++ ;
F_5 ( V_26 , V_63 , V_28 ) ;
V_28 -> V_12 -- ;
} else {
for ( V_77 = - 4 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
fputs ( L_67 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
fputs ( L_66 , V_28 -> V_44 ) ;
}
}
if ( V_26 -> V_43 != NULL ) {
for ( V_77 = - 3 ; V_77 < V_28 -> V_12 ; V_77 ++ ) {
fputs ( L_37 , V_28 -> V_44 ) ;
}
if ( V_26 -> V_109 == NULL ) {
fputs ( L_68 , V_28 -> V_44 ) ;
} else {
fputs ( L_69 , V_28 -> V_44 ) ;
}
}
}
static void
V_72 ( T_7 * V_26 , T_8 V_11 )
{
T_9 * V_27 = F_6 ( V_26 ) ;
T_9 * V_110 = F_6 ( V_26 -> V_81 ) ;
T_16 * V_28 = ( T_16 * ) V_11 ;
const T_11 * V_32 ;
T_11 V_30 [ V_31 ] ;
char * V_76 ;
int V_77 ;
T_11 * V_111 = NULL ;
F_7 ( V_27 ) ;
if ( V_27 -> V_35 -> V_37 == V_80 ) {
if ( V_27 -> V_33 ) {
V_32 = V_27 -> V_33 -> V_34 ;
}
else {
V_32 = L_9 ;
}
fputs ( L_59 , V_28 -> V_44 ) ;
if ( V_110 != NULL ) {
F_43 ( V_28 -> V_44 , V_110 -> V_35 -> V_36 ) ;
fputs ( L_70 , V_28 -> V_44 ) ;
}
F_43 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
if ( V_26 -> V_43 != NULL ) {
fputs ( L_64 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_32 ) ;
fputs ( L_71 , V_28 -> V_44 ) ;
}
else {
if ( V_26 -> V_109 == NULL ) {
fputs ( L_64 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_32 ) ;
fputs ( L_59 , V_28 -> V_44 ) ;
} else {
fputs ( L_64 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_32 ) ;
fputs ( L_71 , V_28 -> V_44 ) ;
}
}
}
else {
if ( V_28 -> V_23 && V_27 -> V_38 > 0 ) {
fputs ( L_59 , V_28 -> V_44 ) ;
if ( V_110 != NULL ) {
F_43 ( V_28 -> V_44 , V_110 -> V_35 -> V_36 ) ;
fputs ( L_70 , V_28 -> V_44 ) ;
}
F_43 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
fputs ( L_63 , V_28 -> V_44 ) ;
fputs ( L_64 , V_28 -> V_44 ) ;
if ( V_27 -> V_35 -> V_88 != 0 ) {
switch ( V_27 -> V_67 . V_89 -> V_89 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
fprintf ( V_28 -> V_44 , L_51 , ( V_94 ) F_36 ( & V_27 -> V_67 ) ) ;
break;
case V_95 :
case V_96 :
case V_97 :
case V_98 :
fprintf ( V_28 -> V_44 , L_51 , F_37 ( & V_27 -> V_67 ) ) ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
fprintf ( V_28 -> V_44 , L_52 V_103 L_53 , F_38 ( & V_27 -> V_67 ) ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
fprintf ( V_28 -> V_44 , L_52 V_103 L_53 , F_39 ( & V_27 -> V_67 ) ) ;
break;
default:
F_40 () ;
}
fputs ( L_71 , V_28 -> V_44 ) ;
}
else {
F_42 ( V_28 , V_27 ) ;
fputs ( L_71 , V_28 -> V_44 ) ;
}
}
fputs ( L_59 , V_28 -> V_44 ) ;
if ( V_110 != NULL ) {
F_43 ( V_28 -> V_44 , V_110 -> V_35 -> V_36 ) ;
fputs ( L_70 , V_28 -> V_44 ) ;
}
F_43 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
switch ( V_27 -> V_35 -> type )
{
case V_79 :
if ( V_26 -> V_43 != NULL ) {
fputs ( L_72 , V_28 -> V_44 ) ;
} else {
fputs ( L_64 , V_28 -> V_44 ) ;
if ( V_27 -> V_33 ) {
F_41 ( V_28 -> V_44 , V_27 -> V_33 -> V_34 ) ;
}
else {
V_32 = V_30 ;
F_9 ( V_27 , V_30 ) ;
F_41 ( V_28 -> V_44 , V_32 ) ;
}
if ( V_26 -> V_109 == NULL ) {
fputs ( L_59 , V_28 -> V_44 ) ;
} else {
fputs ( L_71 , V_28 -> V_44 ) ;
}
}
break;
case V_85 :
if ( V_26 -> V_43 != NULL ) {
fputs ( L_73 , V_28 -> V_44 ) ;
} else {
if ( V_26 -> V_109 == NULL ) {
fputs ( L_74 , V_28 -> V_44 ) ;
} else {
fputs ( L_73 , V_28 -> V_44 ) ;
}
}
break;
default:
V_76 = F_34 ( NULL , & V_27 -> V_67 , V_86 , V_27 -> V_35 -> V_87 ) ;
if ( V_76 != NULL ) {
if ( V_26 -> V_43 == NULL ) {
fputs ( L_64 , V_28 -> V_44 ) ;
F_41 ( V_28 -> V_44 , V_76 ) ;
} else {
fputs ( L_73 , V_28 -> V_44 ) ;
}
}
F_35 ( NULL , V_76 ) ;
if ( V_26 -> V_43 == NULL ) {
if ( V_26 -> V_109 == NULL ) {
fputs ( L_59 , V_28 -> V_44 ) ;
} else {
fputs ( L_71 , V_28 -> V_44 ) ;
}
}
}
}
if ( V_26 -> V_43 != NULL ) {
if ( V_28 -> V_57 != NULL ) {
if ( V_27 -> V_35 -> V_36 != NULL ) {
if ( strlen ( V_27 -> V_35 -> V_36 ) > 0 ) {
V_111 = F_44 ( V_27 -> V_35 -> V_36 ) ;
V_77 = 0 ;
while( V_111 [ V_77 ] != '\0' ) {
if( V_111 [ V_77 ] == '.' ) {
V_111 [ V_77 ] = '_' ;
}
V_77 ++ ;
}
}
}
if( F_21 ( V_28 -> V_57 , V_27 -> V_35 -> V_36 ) || F_21 ( V_28 -> V_57 , V_111 ) ) {
V_28 -> V_12 ++ ;
F_5 ( V_26 , V_72 , V_28 ) ;
V_28 -> V_12 -- ;
} else {
fputs ( L_67 , V_28 -> V_44 ) ;
F_43 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
fputs ( L_59 , V_28 -> V_44 ) ;
}
if ( V_111 != NULL ) {
F_13 ( V_111 ) ;
}
} else {
V_28 -> V_12 ++ ;
F_5 ( V_26 ,
V_72 , V_28 ) ;
V_28 -> V_12 -- ;
}
}
if ( V_26 -> V_43 != NULL ) {
if ( V_27 -> V_35 -> type == V_79 ) {
if ( V_26 -> V_109 == NULL ) {
fputs ( L_75 , V_28 -> V_44 ) ;
} else {
fputs ( L_76 , V_28 -> V_44 ) ;
}
} else {
if ( V_26 -> V_109 != NULL ) {
fputs ( L_77 , V_28 -> V_44 ) ;
}
}
}
}
static void
F_23 ( T_20 * V_24 , T_12 * V_44 )
{
T_21 V_112 , V_113 , V_114 ;
T_17 * V_65 ;
T_18 * V_66 ;
T_9 * V_115 ;
T_11 * V_116 ;
V_66 = F_27 ( V_24 , V_2 ) ;
if ( F_28 ( V_66 ) < 1 ) {
return;
}
V_115 = ( T_9 * ) V_66 -> V_28 [ 0 ] ;
F_30 ( V_66 , TRUE ) ;
V_66 = F_27 ( V_24 , V_4 ) ;
if ( F_28 ( V_66 ) < 1 ) {
return;
}
V_112 = F_37 ( & ( ( T_9 * ) V_66 -> V_28 [ 0 ] ) -> V_67 ) ;
F_30 ( V_66 , TRUE ) ;
V_66 = F_27 ( V_24 , V_5 ) ;
if ( F_28 ( V_66 ) < 1 ) {
return;
}
V_113 = F_37 ( & ( ( T_9 * ) V_66 -> V_28 [ 0 ] ) -> V_67 ) ;
F_30 ( V_66 , TRUE ) ;
V_66 = F_27 ( V_24 , V_6 ) ;
if ( F_28 ( V_66 ) < 1 ) {
return;
}
V_114 = F_37 ( & ( ( T_9 * ) V_66 -> V_28 [ 0 ] ) -> V_67 ) ;
F_30 ( V_66 , TRUE ) ;
V_66 = F_27 ( V_24 , V_3 ) ;
if ( F_28 ( V_66 ) < 1 ) {
return;
}
V_65 = ( T_17 * ) F_29 ( & ( ( T_9 * ) V_66 -> V_28 [ 0 ] ) -> V_67 ) ;
F_30 ( V_66 , TRUE ) ;
fprintf ( V_44 ,
L_78 ,
V_115 -> V_38 ) ;
fprintf ( V_44 ,
L_79 ,
V_112 , V_112 , V_115 -> V_38 ) ;
fprintf ( V_44 ,
L_80 ,
V_113 , V_113 , V_115 -> V_38 ) ;
fprintf ( V_44 ,
L_81 ,
V_114 , V_114 , V_115 -> V_38 ) ;
V_116 = F_45 ( NULL , V_65 , V_117 , TRUE ) ;
fprintf ( V_44 ,
L_82 ,
V_116 , ( int ) V_65 -> V_70 , V_65 -> V_71 , V_115 -> V_38 ) ;
F_35 ( NULL , V_116 ) ;
fprintf ( V_44 ,
L_83 ) ;
}
void
F_46 ( T_12 * V_44 )
{
fputs ( L_84 , V_44 ) ;
}
void
F_47 ( T_12 * V_44 )
{
fputs ( L_85 , V_44 ) ;
}
void
F_48 ( T_19 * V_74 , T_12 * V_44 )
{
T_22 V_77 ;
fputs ( L_10 , V_44 ) ;
fputs ( L_86 V_118 L_17 , V_44 ) ;
fprintf ( V_44 , L_87 , V_50 , V_51 ) ;
fprintf ( V_44 , L_88 ) ;
for ( V_77 = 0 ; V_77 < V_74 -> V_119 ; V_77 ++ ) {
fprintf ( V_44 , L_89 ) ;
F_32 ( V_44 , V_74 -> V_120 [ V_77 ] . V_121 ) ;
fprintf ( V_44 , L_90 ) ;
}
fprintf ( V_44 , L_91 ) ;
}
void
F_49 ( T_3 * V_8 , T_12 * V_44 )
{
T_22 V_77 ;
fprintf ( V_44 , L_20 ) ;
for ( V_77 = 0 ; V_77 < V_8 -> V_15 . V_74 -> V_119 ; V_77 ++ ) {
fprintf ( V_44 , L_89 ) ;
F_32 ( V_44 , V_8 -> V_15 . V_74 -> V_120 [ V_77 ] . V_122 ) ;
fprintf ( V_44 , L_90 ) ;
}
fprintf ( V_44 , L_21 ) ;
}
void
F_50 ( T_12 * V_44 )
{
fputs ( L_92 , V_44 ) ;
}
static T_11 * F_51 ( const T_11 * V_123 , const T_11 * V_124 )
{
T_11 * V_125 ;
T_11 * V_126 ;
V_125 = F_52 ( V_123 , V_124 ) ;
V_126 = V_125 ;
while ( ( V_126 = strstr ( V_126 , V_127 ) ) != NULL ) {
V_126 [ 0 ] = ' ' ;
V_126 [ 1 ] = '>' ;
V_126 [ 2 ] = ' ' ;
}
V_126 = V_125 ;
while ( ( V_126 = strstr ( V_126 , L_93 ) ) != NULL )
* V_126 = '\"' ;
return V_125 ;
}
static void F_53 ( const char * V_53 , char V_128 , T_12 * V_44 )
{
T_11 * V_125 ;
V_125 = F_51 ( V_53 , V_127 ) ;
fprintf ( V_44 , L_94 , V_125 , V_128 ) ;
F_13 ( V_125 ) ;
}
void
F_54 ( T_19 * V_74 , T_12 * V_44 )
{
T_22 V_77 ;
for ( V_77 = 0 ; V_77 < V_74 -> V_119 - 1 ; V_77 ++ )
F_53 ( V_74 -> V_120 [ V_77 ] . V_121 , ',' , V_44 ) ;
F_53 ( V_74 -> V_120 [ V_77 ] . V_121 , '\n' , V_44 ) ;
}
void
F_55 ( T_3 * V_8 , T_12 * V_44 )
{
T_22 V_77 ;
for ( V_77 = 0 ; V_77 < V_8 -> V_15 . V_74 -> V_119 - 1 ; V_77 ++ )
F_53 ( V_8 -> V_15 . V_74 -> V_120 [ V_77 ] . V_122 , ',' , V_44 ) ;
F_53 ( V_8 -> V_15 . V_74 -> V_120 [ V_77 ] . V_122 , '\n' , V_44 ) ;
}
void
F_56 ( T_21 V_112 , T_12 * V_44 , T_3 * V_8 )
{
T_21 V_77 = 0 , V_129 = 0 ;
T_23 * V_130 ;
T_24 * V_131 ;
char * V_132 ;
const T_25 * V_133 ;
V_94 V_38 ;
char V_134 [ 9 ] ;
struct V_135 * V_136 ;
for ( V_130 = V_8 -> V_15 . V_16 ; V_130 != NULL ; V_130 = V_130 -> V_109 ) {
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
V_136 = (struct V_135 * ) V_130 -> V_11 ;
V_131 = F_57 ( V_136 ) ;
V_38 = F_58 ( V_131 ) ;
if ( V_38 == 0 )
continue;
V_133 = F_59 ( V_131 , 0 , V_38 ) ;
V_132 = F_60 ( V_136 ) ;
if ( V_132 ) {
fprintf ( V_44 , L_95 , V_132 ) ;
F_35 ( NULL , V_132 ) ;
}
if ( V_129 ) {
fprintf ( V_44 , L_96 ,
V_112 , V_129 , V_38 ) ;
} else {
fprintf ( V_44 , L_97 ,
V_112 , V_38 ) ;
}
V_129 ++ ;
for ( V_77 = 0 ; V_77 < V_38 ; V_77 ++ ) {
fprintf ( V_44 , L_98 , * ( V_133 + V_77 ) ) ;
V_134 [ V_77 % 8 ] = F_61 ( * ( V_133 + V_77 ) ) ? * ( V_133 + V_77 ) : '.' ;
if ( V_77 == ( V_38 - 1 ) ) {
V_94 V_137 ;
V_137 = V_38 % 8 ;
if ( V_137 ) {
V_94 V_138 ;
for ( V_138 = 0 ; V_138 < 8 - V_137 ; V_138 ++ )
fprintf ( V_44 , L_99 ) ;
}
fprintf ( V_44 , L_100 , V_134 ) ;
break;
}
if ( ! ( ( V_77 + 1 ) % 8 ) ) {
fprintf ( V_44 , L_101 , V_134 ) ;
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
}
else {
fprintf ( V_44 , L_102 ) ;
}
}
}
}
static const T_10 *
F_15 ( T_23 * V_14 , T_9 * V_27 )
{
T_23 * V_130 ;
T_24 * V_139 ;
T_22 V_38 , V_140 ;
struct V_135 * V_136 ;
for ( V_130 = V_14 ; V_130 != NULL ; V_130 = V_130 -> V_109 ) {
V_136 = (struct V_135 * ) V_130 -> V_11 ;
V_139 = F_57 ( V_136 ) ;
if ( V_27 -> V_141 == V_139 ) {
V_140 = F_62 ( V_139 ,
V_27 -> V_83 ) ;
if ( V_140 < 0 ) {
return NULL ;
}
V_38 = V_27 -> V_38 ;
if ( V_38 > V_140 )
V_38 = V_140 ;
return F_59 ( V_139 , V_27 -> V_83 , V_38 ) ;
}
}
F_40 () ;
return NULL ;
}
static void
F_32 ( T_12 * V_44 , const char * V_142 )
{
const char * V_143 ;
char V_144 [ 8 ] ;
if ( V_44 == NULL || V_142 == NULL ) {
return;
}
for ( V_143 = V_142 ; * V_143 != '\0' ; V_143 ++ ) {
switch ( * V_143 ) {
case '&' :
fputs ( L_103 , V_44 ) ;
break;
case '<' :
fputs ( L_104 , V_44 ) ;
break;
case '>' :
fputs ( L_105 , V_44 ) ;
break;
case '"' :
fputs ( L_106 , V_44 ) ;
break;
case '\'' :
fputs ( L_107 , V_44 ) ;
break;
default:
if ( F_61 ( * V_143 ) )
fputc ( * V_143 , V_44 ) ;
else {
F_63 ( V_144 , sizeof( V_144 ) , L_108 , ( T_10 ) * V_143 ) ;
fputs ( V_144 , V_44 ) ;
}
}
}
}
static void
F_64 ( T_12 * V_44 , const char * V_142 , T_1 V_145 )
{
const char * V_143 ;
char V_144 [ 8 ] ;
if ( V_44 == NULL || V_142 == NULL ) {
return;
}
for ( V_143 = V_142 ; * V_143 != '\0' ; V_143 ++ ) {
switch ( * V_143 ) {
case '"' :
fputs ( L_93 , V_44 ) ;
break;
case '\\' :
fputs ( L_109 , V_44 ) ;
break;
case '/' :
fputs ( L_110 , V_44 ) ;
break;
case '\b' :
fputs ( L_111 , V_44 ) ;
break;
case '\f' :
fputs ( L_112 , V_44 ) ;
break;
case '\n' :
fputs ( L_113 , V_44 ) ;
break;
case '\r' :
fputs ( L_114 , V_44 ) ;
break;
case '\t' :
fputs ( L_115 , V_44 ) ;
break;
case '.' :
if ( V_145 )
fputs ( L_70 , V_44 ) ;
else
fputs ( L_116 , V_44 ) ;
break;
default:
if ( F_61 ( * V_143 ) )
fputc ( * V_143 , V_44 ) ;
else {
F_63 ( V_144 , sizeof( V_144 ) , L_117 , ( T_10 ) * V_143 ) ;
fputs ( V_144 , V_44 ) ;
}
}
}
}
static void
F_41 ( T_12 * V_44 , const char * V_142 )
{
F_64 ( V_44 , V_142 , FALSE ) ;
}
static void
F_43 ( T_12 * V_44 , const char * V_142 )
{
F_64 ( V_44 , V_142 , TRUE ) ;
}
static void
F_33 ( T_15 * V_28 , T_9 * V_27 )
{
int V_77 ;
const T_10 * V_29 ;
if ( ! V_27 -> V_141 )
return;
if ( V_27 -> V_38 > F_62 ( V_27 -> V_141 , V_27 -> V_83 ) ) {
fprintf ( V_28 -> V_44 , L_118 ) ;
return;
}
V_29 = F_15 ( V_28 -> V_14 , V_27 ) ;
if ( V_29 ) {
for ( V_77 = 0 ; V_77 < V_27 -> V_38 ; V_77 ++ ) {
fprintf ( V_28 -> V_44 , L_119 , V_29 [ V_77 ] ) ;
}
}
}
static void
F_42 ( T_16 * V_28 , T_9 * V_27 )
{
int V_77 ;
const T_10 * V_29 ;
if ( ! V_27 -> V_141 )
return;
if ( V_27 -> V_38 > F_62 ( V_27 -> V_141 , V_27 -> V_83 ) ) {
fprintf ( V_28 -> V_44 , L_118 ) ;
return;
}
V_29 = F_15 ( V_28 -> V_14 , V_27 ) ;
if ( V_29 ) {
for ( V_77 = 0 ; V_77 < V_27 -> V_38 ; V_77 ++ ) {
fprintf ( V_28 -> V_44 , L_119 , V_29 [ V_77 ] ) ;
}
}
}
T_1
F_65 ( T_5 * V_10 , T_3 * V_8 )
{
T_1 V_146 ;
T_23 * V_130 ;
T_24 * V_131 ;
char * line , * V_132 ;
const T_25 * V_133 ;
V_94 V_38 ;
struct V_135 * V_136 ;
V_146 = ( V_8 -> V_15 . V_16 -> V_109 != NULL ) ;
for ( V_130 = V_8 -> V_15 . V_16 ; V_130 != NULL ;
V_130 = V_130 -> V_109 ) {
V_136 = (struct V_135 * ) V_130 -> V_11 ;
V_131 = F_57 ( V_136 ) ;
if ( V_146 ) {
V_132 = F_60 ( V_136 ) ;
line = F_66 ( L_120 , V_132 ) ;
F_35 ( NULL , V_132 ) ;
F_12 ( V_10 , 0 , line ) ;
F_13 ( line ) ;
}
V_38 = F_58 ( V_131 ) ;
if ( V_38 == 0 )
return TRUE ;
V_133 = F_59 ( V_131 , 0 , V_38 ) ;
if ( ! F_16 ( V_10 , V_133 , V_38 ,
( V_18 ) V_8 -> V_15 . V_19 -> V_20 . V_17 ) )
return FALSE ;
}
return TRUE ;
}
static T_1
F_16 ( T_5 * V_10 , const T_25 * V_133 ,
V_94 V_38 , V_18 V_17 )
{
register unsigned int V_147 , V_77 , V_138 , V_148 , V_149 ;
T_25 V_150 ;
T_11 line [ V_151 + 1 ] ;
unsigned int V_152 ;
static T_11 V_153 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ( ( V_38 - 1 ) & 0xF0000000 ) != 0 )
V_152 = 8 ;
else if ( ( ( V_38 - 1 ) & 0x0F000000 ) != 0 )
V_152 = 7 ;
else if ( ( ( V_38 - 1 ) & 0x00F00000 ) != 0 )
V_152 = 6 ;
else if ( ( ( V_38 - 1 ) & 0x000F0000 ) != 0 )
V_152 = 5 ;
else
V_152 = 4 ;
V_147 = 0 ;
V_77 = 0 ;
V_138 = 0 ;
V_148 = 0 ;
while ( V_77 < V_38 ) {
if ( ( V_77 & 15 ) == 0 ) {
V_138 = 0 ;
V_149 = V_152 ;
do {
V_149 -- ;
V_150 = ( V_147 >> ( V_149 * 4 ) ) & 0xF ;
line [ V_138 ++ ] = V_153 [ V_150 ] ;
} while ( V_149 != 0 );
line [ V_138 ++ ] = ' ' ;
line [ V_138 ++ ] = ' ' ;
memset ( line + V_138 , ' ' , V_154 ) ;
V_148 = V_138 + V_155 + 2 ;
}
V_150 = * V_133 ++ ;
line [ V_138 ++ ] = V_153 [ V_150 >> 4 ] ;
line [ V_138 ++ ] = V_153 [ V_150 & 0xf ] ;
V_138 ++ ;
if ( V_17 == V_156 ) {
V_150 = F_67 ( V_150 ) ;
}
line [ V_148 ++ ] = ( ( V_150 >= ' ' ) && ( V_150 < 0x7f ) ) ? V_150 : '.' ;
V_77 ++ ;
if ( ( ( V_77 & 15 ) == 0 ) || ( V_77 == V_38 ) ) {
line [ V_148 ] = '\0' ;
if ( ! F_12 ( V_10 , 0 , line ) )
return FALSE ;
V_147 += 16 ;
}
}
return TRUE ;
}
T_26 F_68 ( T_14 * V_56 )
{
F_7 ( V_56 ) ;
if ( NULL == V_56 -> V_56 ) {
return 0 ;
} else {
return V_56 -> V_56 -> V_113 ;
}
}
void F_69 ( T_14 * V_56 )
{
F_7 ( V_56 ) ;
if ( NULL != V_56 -> V_56 ) {
T_26 V_77 ;
if ( NULL != V_56 -> V_157 ) {
F_70 ( V_56 -> V_157 ) ;
}
if ( NULL != V_56 -> V_158 ) {
F_13 ( V_56 -> V_158 ) ;
}
for( V_77 = 0 ; V_77 < V_56 -> V_56 -> V_113 ; ++ V_77 ) {
T_11 * V_159 = ( T_11 * ) F_71 ( V_56 -> V_56 , V_77 ) ;
F_13 ( V_159 ) ;
}
F_30 ( V_56 -> V_56 , TRUE ) ;
}
F_13 ( V_56 ) ;
}
void F_72 ( T_14 * V_56 , const T_11 * V_159 )
{
T_11 * V_160 ;
F_7 ( V_56 ) ;
F_7 ( V_159 ) ;
if ( NULL == V_56 -> V_56 ) {
V_56 -> V_56 = F_73 () ;
}
V_160 = F_44 ( V_159 ) ;
F_74 ( V_56 -> V_56 , V_160 ) ;
if ( ! strncmp ( V_159 , V_161 , strlen ( V_161 ) ) )
V_56 -> V_162 = TRUE ;
}
static void
F_75 ( void * V_11 , void * V_163 )
{
T_11 * V_159 = ( T_11 * ) V_11 ;
T_23 * * V_164 = ( T_23 * * ) V_163 ;
if ( ! strncmp ( V_159 , V_161 , strlen ( V_161 ) ) )
return;
if ( ! F_76 ( V_159 ) ) {
* V_164 = F_77 ( * V_164 , V_159 ) ;
}
}
T_23 *
F_78 ( T_14 * V_56 )
{
T_23 * V_164 = NULL ;
if ( V_56 -> V_56 == NULL ) {
return NULL ;
}
F_79 ( V_56 -> V_56 , F_75 , & V_164 ) ;
return V_164 ;
}
T_1 F_80 ( T_14 * V_165 , T_11 * V_166 )
{
const T_11 * V_167 ;
const T_11 * V_168 ;
F_7 ( V_165 ) ;
F_7 ( V_166 ) ;
if ( '\0' == * V_166 ) {
return FALSE ;
}
V_167 = strtok ( V_166 , L_121 ) ;
if ( ! V_167 ) {
return FALSE ;
}
V_168 = V_166 + strlen ( V_167 ) + 1 ;
if ( * V_168 == '\0' ) {
return FALSE ;
}
if ( 0 == strcmp ( V_167 , L_122 ) ) {
switch ( * V_168 ) {
case 'n' :
V_165 -> V_169 = FALSE ;
break;
case 'y' :
V_165 -> V_169 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_167 , L_123 ) ) {
switch ( * V_168 ) {
case '/' :
switch ( * ++ V_168 ) {
case 't' :
V_165 -> V_170 = '\t' ;
break;
case 's' :
V_165 -> V_170 = ' ' ;
break;
default:
V_165 -> V_170 = '\\' ;
}
break;
default:
V_165 -> V_170 = * V_168 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_167 , L_124 ) ) {
switch ( * V_168 ) {
case 'f' :
case 'l' :
case 'a' :
V_165 -> V_171 = * V_168 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_167 , L_125 ) ) {
switch ( * V_168 ) {
case '/' :
switch ( * ++ V_168 ) {
case 's' :
V_165 -> V_172 = ' ' ;
break;
default:
V_165 -> V_172 = '\\' ;
}
break;
default:
V_165 -> V_172 = * V_168 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_167 , L_126 ) ) {
switch ( * V_168 ) {
case 'd' :
V_165 -> V_173 = '"' ;
break;
case 's' :
V_165 -> V_173 = '\'' ;
break;
case 'n' :
V_165 -> V_173 = '\0' ;
break;
default:
V_165 -> V_173 = '\0' ;
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_167 , L_127 ) ) {
switch ( * V_168 ) {
case 'n' :
V_165 -> V_174 = FALSE ;
break;
case 'y' :
V_165 -> V_174 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
void F_81 ( T_12 * V_44 )
{
fprintf ( V_44 , L_128 ) ;
fputs ( L_129 , V_44 ) ;
fputs ( L_130 , V_44 ) ;
fputs ( L_131 , V_44 ) ;
fputs ( L_132 , V_44 ) ;
fputs ( L_133 , V_44 ) ;
fputs ( L_134 , V_44 ) ;
}
T_1 F_82 ( T_14 * V_56 )
{
F_7 ( V_56 ) ;
return V_56 -> V_162 ;
}
void F_83 ( T_14 * V_56 , T_12 * V_44 )
{
T_26 V_77 ;
F_7 ( V_56 ) ;
F_7 ( V_44 ) ;
F_7 ( V_56 -> V_56 ) ;
if ( V_56 -> V_174 ) {
fputs ( V_175 , V_44 ) ;
}
if ( ! V_56 -> V_169 ) {
return;
}
for( V_77 = 0 ; V_77 < V_56 -> V_56 -> V_113 ; ++ V_77 ) {
const T_11 * V_159 = ( const T_11 * ) F_71 ( V_56 -> V_56 , V_77 ) ;
if ( V_77 != 0 ) {
fputc ( V_56 -> V_170 , V_44 ) ;
}
fputs ( V_159 , V_44 ) ;
}
fputc ( '\n' , V_44 ) ;
}
static void F_84 ( T_14 * V_56 , T_8 V_176 , const T_11 * V_67 )
{
V_94 V_177 ;
T_18 * V_178 ;
if ( NULL == V_67 )
return;
V_177 = F_85 ( V_176 ) - 1 ;
if ( V_56 -> V_158 [ V_177 ] == NULL ) {
V_56 -> V_158 [ V_177 ] = F_73 () ;
}
V_178 = V_56 -> V_158 [ V_177 ] ;
switch ( V_56 -> V_171 ) {
case 'f' :
if ( F_28 ( V_178 ) != 0 )
return;
break;
case 'l' :
F_86 ( V_178 , 0 ) ;
break;
case 'a' :
if ( F_28 ( V_178 ) > 0 ) {
F_74 ( V_178 , ( T_8 ) F_66 ( L_135 , V_56 -> V_172 ) ) ;
}
break;
default:
F_40 () ;
break;
}
F_74 ( V_178 , ( T_8 ) V_67 ) ;
}
static void F_87 ( T_7 * V_26 , T_8 V_11 )
{
T_27 * V_179 ;
T_9 * V_27 ;
T_8 V_176 ;
V_179 = ( T_27 * ) V_11 ;
V_27 = F_6 ( V_26 ) ;
F_7 ( V_27 ) ;
V_176 = F_14 ( V_179 -> V_56 -> V_157 , V_27 -> V_35 -> V_36 ) ;
if ( NULL != V_176 ) {
F_84 ( V_179 -> V_56 , V_176 ,
F_88 ( V_27 , V_179 -> V_8 )
) ;
}
if ( V_26 -> V_43 != NULL ) {
F_5 ( V_26 , F_87 ,
V_179 ) ;
}
}
static void F_24 ( T_28 V_180 , T_14 * V_56 , T_3 * V_8 , T_19 * V_74 , T_12 * V_44 )
{
T_26 V_77 ;
T_1 V_181 = TRUE ;
T_22 V_182 ;
T_11 * V_183 ;
T_8 V_176 ;
T_27 V_11 ;
F_7 ( V_56 ) ;
F_7 ( V_56 -> V_56 ) ;
F_7 ( V_8 ) ;
F_7 ( V_44 ) ;
V_11 . V_56 = V_56 ;
V_11 . V_8 = V_8 ;
if ( NULL == V_56 -> V_157 ) {
V_56 -> V_157 = F_89 ( V_184 , V_185 ) ;
V_77 = 0 ;
while ( V_77 < V_56 -> V_56 -> V_113 ) {
T_11 * V_159 = ( T_11 * ) F_71 ( V_56 -> V_56 , V_77 ) ;
++ V_77 ;
F_90 ( V_56 -> V_157 , V_159 , F_91 ( V_77 ) ) ;
}
}
if ( NULL == V_56 -> V_158 )
V_56 -> V_158 = F_92 ( T_18 * , V_56 -> V_56 -> V_113 ) ;
F_5 ( V_8 -> V_24 , F_87 ,
& V_11 ) ;
switch ( V_180 ) {
case V_75 :
if ( V_56 -> V_162 ) {
for ( V_182 = 0 ; V_182 < V_74 -> V_119 ; V_182 ++ ) {
V_183 = F_66 ( L_136 , V_161 , V_74 -> V_120 [ V_182 ] . V_121 ) ;
V_176 = F_14 ( V_56 -> V_157 , V_183 ) ;
F_13 ( V_183 ) ;
if ( NULL != V_176 ) {
F_84 ( V_56 , V_176 , F_44 ( V_74 -> V_120 [ V_182 ] . V_122 ) ) ;
}
}
}
for( V_77 = 0 ; V_77 < V_56 -> V_56 -> V_113 ; ++ V_77 ) {
if ( 0 != V_77 ) {
fputc ( V_56 -> V_170 , V_44 ) ;
}
if ( NULL != V_56 -> V_158 [ V_77 ] ) {
T_18 * V_178 ;
T_11 * V_53 ;
T_26 V_138 ;
V_178 = V_56 -> V_158 [ V_77 ] ;
if ( V_56 -> V_173 != '\0' ) {
fputc ( V_56 -> V_173 , V_44 ) ;
}
for ( V_138 = 0 ; V_138 < F_28 ( V_178 ) ; V_138 ++ ) {
V_53 = ( T_11 * ) F_71 ( V_178 , V_138 ) ;
fputs ( V_53 , V_44 ) ;
F_13 ( V_53 ) ;
}
if ( V_56 -> V_173 != '\0' ) {
fputc ( V_56 -> V_173 , V_44 ) ;
}
F_30 ( V_178 , TRUE ) ;
V_56 -> V_158 [ V_77 ] = NULL ;
}
}
break;
case V_59 :
for( V_77 = 0 ; V_77 < V_56 -> V_56 -> V_113 ; ++ V_77 ) {
T_11 * V_159 = ( T_11 * ) F_71 ( V_56 -> V_56 , V_77 ) ;
if ( NULL != V_56 -> V_158 [ V_77 ] ) {
T_18 * V_178 ;
T_11 * V_53 ;
T_26 V_138 ;
V_178 = V_56 -> V_158 [ V_77 ] ;
for ( V_138 = 0 ; V_138 < ( F_28 ( V_178 ) ) ; V_138 += 2 ) {
V_53 = ( T_11 * ) F_71 ( V_178 , V_138 ) ;
fprintf ( V_44 , L_137 , V_159 ) ;
fputs ( L_59 , V_44 ) ;
F_32 ( V_44 , V_53 ) ;
fputs ( L_45 , V_44 ) ;
F_13 ( V_53 ) ;
}
F_30 ( V_178 , TRUE ) ;
V_56 -> V_158 [ V_77 ] = NULL ;
}
}
break;
case V_64 :
for( V_77 = 0 ; V_77 < V_56 -> V_56 -> V_113 ; ++ V_77 ) {
T_11 * V_159 = ( T_11 * ) F_71 ( V_56 -> V_56 , V_77 ) ;
if ( NULL != V_56 -> V_158 [ V_77 ] ) {
T_18 * V_178 ;
T_11 * V_53 ;
T_26 V_138 ;
V_178 = V_56 -> V_158 [ V_77 ] ;
for ( V_138 = 0 ; V_138 < ( F_28 ( V_178 ) ) ; V_138 += 2 ) {
V_53 = ( T_11 * ) F_71 ( V_178 , V_138 ) ;
if ( V_138 == 0 ) {
if ( ! V_181 ) {
fputs ( L_138 , V_44 ) ;
}
fprintf ( V_44 , L_139 , V_159 ) ;
}
fputs ( L_59 , V_44 ) ;
F_41 ( V_44 , V_53 ) ;
fputs ( L_59 , V_44 ) ;
F_13 ( V_53 ) ;
if ( V_138 + 2 < ( F_28 ( V_178 ) ) ) {
fputs ( L_77 , V_44 ) ;
}
else {
fputs ( L_8 , V_44 ) ;
}
}
V_181 = FALSE ;
F_30 ( V_178 , TRUE ) ;
V_56 -> V_158 [ V_77 ] = NULL ;
}
}
fputc ( '\n' , V_44 ) ;
break;
case V_73 :
for( V_77 = 0 ; V_77 < V_56 -> V_56 -> V_113 ; ++ V_77 ) {
T_11 * V_159 = ( T_11 * ) F_71 ( V_56 -> V_56 , V_77 ) ;
if ( NULL != V_56 -> V_158 [ V_77 ] ) {
T_18 * V_178 ;
T_11 * V_53 ;
T_26 V_138 ;
V_178 = V_56 -> V_158 [ V_77 ] ;
for ( V_138 = 0 ; V_138 < ( F_28 ( V_178 ) ) ; V_138 += 2 ) {
V_53 = ( T_11 * ) F_71 ( V_178 , V_138 ) ;
if ( V_138 == 0 ) {
if ( ! V_181 ) {
fputs ( L_77 , V_44 ) ;
}
fputs ( L_59 , V_44 ) ;
F_43 ( V_44 , V_159 ) ;
fputs ( L_140 , V_44 ) ;
}
fputs ( L_59 , V_44 ) ;
F_41 ( V_44 , V_53 ) ;
fputs ( L_59 , V_44 ) ;
F_13 ( V_53 ) ;
if ( V_138 + 2 < ( F_28 ( V_178 ) ) ) {
fputs ( L_77 , V_44 ) ;
}
else {
fputs ( L_8 , V_44 ) ;
}
}
V_181 = FALSE ;
F_30 ( V_178 , TRUE ) ;
V_56 -> V_158 [ V_77 ] = NULL ;
}
}
break;
default:
fprintf ( V_186 , L_141 , V_180 ) ;
F_40 () ;
break;
}
}
void F_93 ( T_14 * V_56 V_187 , T_12 * V_44 V_187 )
{
}
T_11 * F_88 ( T_9 * V_27 , T_3 * V_8 )
{
if ( V_27 -> V_35 -> V_37 == V_80 ) {
if ( V_27 -> V_33 ) {
return F_44 ( V_27 -> V_33 -> V_34 ) ;
}
else {
return F_94 ( V_8 -> V_15 . V_16 , V_27 ) ;
}
}
else if ( V_27 -> V_35 -> V_37 == V_1 ) {
return F_94 ( V_8 -> V_15 . V_16 , V_27 ) ;
}
else {
T_11 * V_76 ;
switch ( V_27 -> V_35 -> type )
{
case V_79 :
if ( V_27 -> V_33 ) {
return F_44 ( V_27 -> V_33 -> V_34 ) ;
} else {
return F_44 ( V_27 -> V_35 -> V_36 ) ;
}
case V_85 :
return F_44 ( L_142 ) ;
default:
V_76 = F_34 ( NULL , & V_27 -> V_67 , V_86 , V_27 -> V_35 -> V_87 ) ;
if ( V_76 != NULL ) {
T_11 * V_188 = F_44 ( V_76 ) ;
F_35 ( NULL , V_76 ) ;
return V_188 ;
} else {
return F_94 ( V_8 -> V_15 . V_16 , V_27 ) ;
}
}
}
}
static T_11 *
F_94 ( T_23 * V_14 , T_9 * V_27 )
{
const T_10 * V_29 ;
if ( ! V_27 -> V_141 )
return NULL ;
if ( V_27 -> V_38 > F_62 ( V_27 -> V_141 , V_27 -> V_83 ) ) {
return F_44 ( L_118 ) ;
}
V_29 = F_15 ( V_14 , V_27 ) ;
if ( V_29 ) {
int V_77 ;
T_11 * V_189 ;
T_11 * V_143 ;
int V_113 ;
const int V_190 = 2 ;
V_113 = V_190 * V_27 -> V_38 ;
V_189 = ( T_11 * ) F_95 ( sizeof( T_11 ) * ( V_113 + 1 ) ) ;
V_189 [ V_113 ] = '\0' ;
V_143 = V_189 ;
for ( V_77 = 0 ; V_77 < V_27 -> V_38 ; V_77 ++ ) {
F_63 ( V_143 , V_190 + 1 , L_119 , V_29 [ V_77 ] ) ;
V_143 += V_190 ;
}
return V_189 ;
} else {
return NULL ;
}
}
T_14 * F_96 ( void )
{
T_14 * V_56 = F_97 ( T_14 , 1 ) ;
V_56 -> V_174 = FALSE ;
V_56 -> V_169 = FALSE ;
V_56 -> V_170 = '\t' ;
V_56 -> V_171 = 'a' ;
V_56 -> V_172 = ',' ;
V_56 -> V_56 = NULL ;
V_56 -> V_157 = NULL ;
V_56 -> V_158 = NULL ;
V_56 -> V_173 = '\0' ;
V_56 -> V_162 = FALSE ;
return V_56 ;
}
