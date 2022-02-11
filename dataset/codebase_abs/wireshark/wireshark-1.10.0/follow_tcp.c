static void
F_1 ( T_1 V_1 , T_1 T_2 V_2 )
{
F_2 ( ( V_3 * ) V_1 ) ;
}
void
F_3 ( void )
{
F_4 ( V_4 , F_1 , NULL ) ;
}
void
F_5 ( T_3 * T_4 V_2 , T_1 V_1 V_2 )
{
T_3 * V_5 ;
T_3 * V_6 ;
int V_7 ;
T_5 * V_8 ;
const T_5 * V_9 ;
int V_10 ;
const char * V_11 , * V_12 ;
char * V_13 , * V_14 ;
T_5 * V_15 = NULL ;
T_5 * V_16 = NULL ;
T_5 * V_17 = NULL ;
T_6 V_18 ;
V_3 * V_19 ;
T_7 V_20 ;
T_8 V_21 ;
T_5 * V_22 ;
if ( V_23 . V_24 -> V_25 . V_26 != V_27 ) {
F_6 ( V_28 , V_29 ,
L_1
L_2 ) ;
return;
}
V_19 = F_7 ( V_3 , 1 ) ;
V_19 -> V_30 = V_31 ;
F_8 () ;
V_8 = F_9 ( & V_23 . V_24 -> V_25 ) ;
if ( ! V_8 ) {
F_6 ( V_28 , V_29 ,
L_3
L_4 ) ;
F_10 ( V_19 ) ;
return;
}
V_7 = F_11 ( & V_22 , L_5 ) ;
V_19 -> V_22 = F_12 ( V_22 ) ;
if ( V_7 == - 1 ) {
F_6 ( V_28 , V_29 ,
L_6 ,
V_19 -> V_22 , F_13 ( V_32 ) ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 ) ;
F_10 ( V_8 ) ;
return;
}
V_33 = fdopen ( V_7 , L_7 ) ;
if ( V_33 == NULL ) {
F_6 ( V_28 , V_29 ,
L_6 ,
V_19 -> V_22 , F_13 ( V_32 ) ) ;
F_14 ( V_7 ) ;
F_15 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 ) ;
F_10 ( V_8 ) ;
return;
}
V_5 = ( T_3 * ) F_16 ( F_17 ( V_34 ) , V_35 ) ;
V_6 = F_18 ( F_19 ( V_5 ) ) ;
V_19 -> V_6 = V_6 ;
V_9 =
( const T_5 * ) F_20 ( F_21 ( V_6 ) ) ;
V_10 = ( int ) ( strlen ( V_8 ) + strlen ( V_9 ) + 16 ) ;
V_19 -> V_36 = ( T_5 * ) F_22 ( V_10 ) ;
if( strlen ( V_9 ) ) {
F_23 ( V_19 -> V_36 , V_10 ,
L_8 , V_9 , V_8 ) ;
} else {
F_23 ( V_19 -> V_36 , V_10 ,
L_9 , V_8 ) ;
}
F_24 ( F_21 ( V_6 ) , V_8 ) ;
F_25 ( & V_23 , V_8 , TRUE ) ;
F_10 ( V_8 ) ;
if ( V_37 ) {
F_6 ( V_28 , V_29 ,
L_10 ) ;
F_14 ( V_7 ) ;
F_15 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_36 ) ;
F_10 ( V_19 ) ;
return;
}
rewind ( V_33 ) ;
V_21 = fread ( & V_20 , 1 , sizeof( V_20 ) , V_33 ) ;
if ( V_21 != sizeof( V_20 ) ) {
if ( ferror ( V_33 ) ) {
F_6 ( V_28 , V_29 ,
L_11 ,
V_19 -> V_22 , F_13 ( V_32 ) ) ;
} else {
F_6 ( V_28 , V_29 ,
L_12 ,
V_19 -> V_22 ,
( unsigned long ) sizeof( V_20 ) ,
( unsigned long ) V_21 ) ;
}
F_14 ( V_7 ) ;
F_15 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_22 ) ;
F_10 ( V_19 -> V_36 ) ;
F_10 ( V_19 ) ;
return;
}
fclose ( V_33 ) ;
F_26 ( & V_18 ) ;
if ( V_18 . V_38 ) {
struct V_39 V_40 ;
memcpy ( & V_40 , V_18 . V_41 [ 0 ] , 16 ) ;
V_11 = F_27 ( & V_40 ) ;
memcpy ( & V_40 , V_18 . V_41 [ 1 ] , 16 ) ;
V_12 = F_27 ( & V_40 ) ;
} else {
T_9 V_40 ;
memcpy ( & V_40 , V_18 . V_41 [ 0 ] , 4 ) ;
V_11 = F_28 ( V_40 ) ;
memcpy ( & V_40 , V_18 . V_41 [ 1 ] , 4 ) ;
V_12 = F_28 ( V_40 ) ;
}
V_19 -> V_38 = V_18 . V_38 ;
V_13 = F_29 ( V_18 . V_42 [ 0 ] ) ;
V_14 = F_29 ( V_18 . V_42 [ 1 ] ) ;
if( V_20 . V_43 == V_18 . V_42 [ 0 ] ) {
V_15 =
F_30 ( L_13 V_44 L_14 ,
V_11 , V_13 ,
V_12 , V_14 ,
V_18 . V_45 [ 0 ] ) ;
} else {
V_15 =
F_30 ( L_13 V_44 L_14 ,
V_12 , V_14 ,
V_11 , V_13 ,
V_18 . V_45 [ 0 ] ) ;
}
if( V_20 . V_43 == V_18 . V_42 [ 1 ] ) {
V_16 =
F_30 ( L_13 V_44 L_14 ,
V_11 , V_13 ,
V_12 , V_14 ,
V_18 . V_45 [ 1 ] ) ;
} else {
V_16 =
F_30 ( L_13 V_44 L_14 ,
V_12 , V_14 ,
V_11 , V_13 ,
V_18 . V_45 [ 1 ] ) ;
}
V_17 = F_30 ( L_15 , V_18 . V_45 [ 0 ] + V_18 . V_45 [ 1 ] ) ;
F_31 ( L_16 , V_19 , V_17 ,
V_15 , V_16 ) ;
F_10 ( V_17 ) ;
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
V_33 = NULL ;
}
static char *
F_32 ( char * V_46 , int * V_47 )
{
char * V_48 ;
V_48 = strstr ( V_46 , L_17 ) ;
if ( ! V_48 ) {
* V_47 = ( int ) strlen ( V_46 ) ;
return NULL ;
}
* V_48 = '\0' ;
* V_47 = ( int ) ( V_48 - V_46 + 2 ) ;
return V_46 ;
}
static T_10
F_33 ( char * V_1 , T_8 V_49 , T_8 * V_50 )
{
char * V_51 , * V_52 , * line ;
T_8 V_53 = 0 ;
int V_54 ;
T_10 V_55 ;
V_51 = V_52 = F_34 ( V_1 , V_49 ) ;
if ( ! V_51 ) {
* V_50 = 0 ;
return FALSE ;
}
F_32 ( V_51 , & V_54 ) ;
V_51 += V_54 ;
V_53 += V_54 ;
V_55 = FALSE ;
* V_50 = - 1 ;
while ( ( line = F_32 ( V_51 , & V_54 ) ) ) {
char * V_56 , * V_57 , * V_58 ;
V_51 += V_54 ;
V_53 += V_54 ;
if ( strlen ( line ) == 0 ) {
break;
}
V_58 = strchr ( line , ':' ) ;
if ( ! V_58 ) break;
V_56 = line ;
* V_58 = '\0' ;
V_57 = V_58 + 2 ;
if ( ! strcmp ( V_56 , L_18 ) && strstr ( V_57 , L_19 ) ) {
V_55 = TRUE ;
}
}
* V_50 = V_53 ;
F_10 ( V_52 ) ;
return V_55 ;
}
T_11
F_35 ( V_3 * V_19 ,
T_10 (* F_36)( char * , T_8 , T_10 , void * ) ,
void * V_59 )
{
T_7 V_20 ;
T_8 V_60 ;
T_8 V_61 ;
int V_62 ;
T_12 V_63 [ V_64 ] ;
T_13 V_65 = 0 ;
T_10 V_66 ;
T_9 V_67 = 0 , V_68 = 0 ;
T_9 V_69 = 0 ;
T_9 V_70 = 0 ;
T_9 * V_71 ;
T_10 V_72 ;
char V_73 [ V_74 + 1 ] ;
T_8 V_21 ;
T_11 V_75 ;
#ifdef F_37
char V_76 [ V_74 + 1 ] ;
T_14 V_77 ;
T_10 V_78 = FALSE ;
int V_79 ;
#endif
V_62 = ( V_19 -> V_38 ) ? 16 : 4 ;
V_33 = F_38 ( V_19 -> V_22 , L_20 ) ;
if ( V_33 == NULL ) {
F_6 ( V_28 , V_29 ,
L_21 , V_19 -> V_22 ,
F_13 ( V_32 ) ) ;
return V_80 ;
}
while ( ( V_21 = fread ( & V_20 , 1 , sizeof( V_20 ) , V_33 ) ) ) {
if ( V_21 != sizeof( V_20 ) ) {
F_6 ( V_28 , V_29 ,
L_12 ,
V_19 -> V_22 ,
( unsigned long ) sizeof( V_20 ) ,
( unsigned long ) V_21 ) ;
fclose ( V_33 ) ;
V_33 = NULL ;
return V_81 ;
}
if ( V_65 == 0 ) {
memcpy ( V_63 , V_20 . V_82 , V_62 ) ;
V_65 = V_20 . V_43 ;
}
V_72 = FALSE ;
if ( memcmp ( V_63 , V_20 . V_82 , V_62 ) == 0 &&
V_65 == V_20 . V_43 ) {
V_66 = FALSE ;
V_71 = & V_67 ;
if ( V_19 -> V_83 == V_84 ) {
V_72 = TRUE ;
}
}
else {
V_66 = TRUE ;
V_71 = & V_68 ;
if ( V_19 -> V_83 == V_85 ) {
V_72 = TRUE ;
}
}
V_61 = 0 ;
while ( V_61 < V_20 . V_86 ) {
V_60 = ( ( V_20 . V_86 - V_61 ) < V_74 ) ? ( V_20 . V_86 - V_61 ) : V_74 ;
V_21 = fread ( V_73 , 1 , V_60 , V_33 ) ;
if ( V_21 == 0 )
break;
V_61 += V_21 ;
#ifdef F_37
if ( V_66 && V_61 == V_21 && ! memcmp ( V_73 , L_22 , 4 ) ) {
T_8 V_87 ;
V_78 = F_33 ( V_73 , V_21 , & V_87 ) ;
if ( V_78 ) {
V_75 = F_39 ( V_19 , F_36 , V_73 ,
V_87 , V_66 , V_59 , V_71 ,
& V_69 , & V_70 ) ;
if ( V_75 == V_88 ) {
fclose ( V_33 ) ;
V_33 = NULL ;
return V_75 ;
}
V_77 . V_89 = V_90 ;
V_77 . V_91 = 0 ;
V_77 . V_92 = V_90 ;
V_77 . V_93 = 0 ;
V_77 . V_94 = V_90 ;
V_77 . V_95 = V_90 ;
V_77 . V_96 = V_90 ;
V_79 = F_40 ( & V_77 , V_97 + 16 ) ;
if ( V_79 != V_98 ) {
fclose ( V_33 ) ;
V_33 = NULL ;
return V_81 ;
}
memmove ( V_73 , V_73 + V_87 , V_21 - V_87 ) ;
V_21 -= V_87 ;
}
}
if ( V_78 ) {
V_77 . V_89 = V_73 ;
V_77 . V_91 = ( int ) V_21 ;
do {
V_77 . V_92 = V_76 ;
V_77 . V_93 = V_74 ;
V_79 = F_41 ( & V_77 , V_99 ) ;
if ( V_79 < 0 || V_79 == V_100 ) {
F_42 ( & V_77 ) ;
fclose ( V_33 ) ;
V_33 = NULL ;
return V_81 ;
} else if ( V_79 == V_101 ) {
F_42 ( & V_77 ) ;
}
V_75 = F_39 ( V_19 , F_36 , V_76 ,
V_74 - V_77 . V_93 , V_66 ,
V_59 , V_71 ,
& V_69 ,
& V_70 ) ;
if( V_75 == V_88 ) {
F_42 ( & V_77 ) ;
fclose ( V_33 ) ;
V_33 = NULL ;
return V_75 ;
}
} while ( V_77 . V_93 == 0 );
V_72 = TRUE ;
}
#endif
if ( ! V_72 ) {
V_75 = F_39 ( V_19 , F_36 , V_73 ,
V_21 , V_66 , V_59 , V_71 ,
& V_69 ,
& V_70 ) ;
if( V_75 == V_88 ) {
fclose ( V_33 ) ;
V_33 = NULL ;
return V_75 ;
}
}
}
}
if ( ferror ( V_33 ) ) {
F_6 ( V_28 , V_29 ,
L_23 , V_19 -> V_22 ,
F_13 ( V_32 ) ) ;
fclose ( V_33 ) ;
V_33 = NULL ;
return V_81 ;
}
fclose ( V_33 ) ;
V_33 = NULL ;
return V_102 ;
}
