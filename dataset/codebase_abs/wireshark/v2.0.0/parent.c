static void F_1 ( int V_1 , const char * V_2 , ... ) {
T_1 V_3 ;
char V_4 [ 1024 ] ;
if ( V_1 > V_5 ) return;
va_start ( V_3 , V_2 ) ;
F_2 ( V_4 , 1024 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
fprintf ( V_6 , L_1 , V_1 , V_4 ) ;
fflush ( V_6 ) ;
}
extern void F_3 ( int V_7 ) {
( V_5 = V_7 ) ;
if ( V_7 > 6 ) {
F_4 ( V_7 , V_6 , L_2 ) ;
}
F_5 ( ( 0 , L_3 , V_7 ) ) ;
}
static void F_6 ( int V_8 , const char * V_2 , ... ) {
T_1 V_3 ;
char V_4 [ 1024 ] ;
va_start ( V_3 , V_2 ) ;
F_2 ( V_4 , 1024 , V_2 , V_3 ) ;
va_end ( V_3 ) ;
#ifdef F_7
F_5 ( ( 0 , L_4 , V_8 , V_4 ) ) ;
#else
fprintf ( V_6 , L_4 , V_8 , V_4 ) ;
#endif
F_8 ( V_9 . V_10 , V_11 ) ;
exit ( V_8 ) ;
}
static void F_9 ( void ) {
#if 0
int i;
#endif
F_5 ( ( 4 , L_5 ) ) ;
#if 0
for (i=0;i<ECHLD_MAX_CHILDREN;i++) {
if ( parent.children[i].handlers ) g_array_free(parent.children[i].handlers,TRUE);
if ( parent.children[i].reqs ) g_array_free(parent.children[i].reqs,TRUE);
};
g_free(parent.children);
g_byte_array_free(parent.snd,TRUE);
#endif
F_5 ( ( 3 , L_6 ) ) ;
}
static void F_10 ( T_2 * V_12 ) {
F_5 ( ( 2 , L_7 , V_12 -> V_13 ) ) ;
V_12 -> V_13 = - 1 ;
V_12 -> V_14 = NULL ;
V_12 -> V_15 = FREE ;
F_11 ( V_12 -> V_16 , 0 ) ;
F_11 ( V_12 -> V_17 , 0 ) ;
}
void F_12 ( int V_18 ) {
int V_19 ;
int V_20 ;
if ( V_18 == V_21 ) {
F_13 ( ( 3333 , L_8 ) ) ;
}
V_19 = F_14 ( - 1 , & V_20 , V_22 ) ;
F_5 ( ( 2 , L_9 , V_19 ) ) ;
if ( V_19 == V_9 . V_10 ) {
if ( ! V_9 . V_23 ) {
F_15 ( 120 ) ;
F_13 ( ( V_24 , L_10 ) ) ;
}
return;
} else {
return;
}
return;
}
static T_3 F_16 ( T_4 type , T_5 * V_25 , void * V_26 ) {
T_6 * V_27 = ( T_6 * ) V_26 ;
char * V_28 = NULL ;
int V_29 = 0 ;
if ( V_27 && V_27 -> V_30 ) {
switch( type ) {
case V_31 :
V_9 . V_32 -> error ( V_25 , & V_29 , & V_28 ) ;
break;
case V_33 :
V_28 = F_17 ( L_11 ) ;
break;
default:
V_28 = F_18 ( L_12 , F_19 ( type ) ) ;
break;
case V_34 :
break;
}
V_27 -> V_30 ( V_26 , V_28 ) ;
if ( V_28 ) F_20 ( V_28 ) ;
}
return TRUE ;
}
void F_21 ( T_6 * V_27 ) {
int V_35 [ 2 ] ;
int V_36 [ 2 ] ;
F_5 ( ( 1 , L_13 ) ) ;
if ( ! V_27 ) {
F_13 ( ( V_37 , L_14 ) ) ;
}
if ( V_27 -> V_38 != V_39 ) {
F_13 ( ( V_40 , L_15 ) ) ;
}
if ( F_22 ( V_36 ) ) {
F_13 ( ( V_41 , L_16 ) ) ;
} else if( F_22 ( V_35 ) ) {
F_13 ( ( V_41 , L_17 ) ) ;
} else {
int V_19 ;
int V_42 ;
F_5 ( ( 3 , L_18 , V_35 [ 0 ] , V_35 [ 1 ] , V_36 [ 0 ] , V_36 [ 1 ] ) ) ;
V_19 = F_23 () ;
if ( V_19 < 0 ) {
F_13 ( ( V_43 , L_19 , F_24 ( V_44 ) ) ) ;
} else if ( V_19 == 0 ) {
#ifdef F_25
V_45 = V_46 ;
#endif
F_9 () ;
if ( V_27 -> V_47 )
V_27 -> V_47 ( V_27 -> V_48 ) ;
F_26 ( V_36 , V_35 , V_27 -> V_49 , V_27 -> main ) ;
F_13 ( ( V_50 , L_20 ) ) ;
} else {
#ifdef F_25
V_45 = V_51 ;
#endif
F_5 ( ( 3 , L_21 ) ) ;
F_27 ( NULL , NULL , & V_9 . V_52 , & V_9 . V_32 ) ;
V_9 . V_53 = F_28 ( T_2 , V_54 ) ;
V_9 . V_55 = F_29 () ;
V_9 . V_56 = V_36 [ 1 ] ;
V_9 . V_10 = V_19 ;
F_30 ( & ( V_9 . V_57 ) , V_35 [ 0 ] , 4096 ) ;
for ( V_42 = 0 ; V_42 < V_54 ; V_42 ++ ) {
V_9 . V_53 [ V_42 ] . V_13 = - 1 ;
V_9 . V_53 [ V_42 ] . V_14 = NULL ;
V_9 . V_53 [ V_42 ] . V_15 = FREE ;
V_9 . V_53 [ V_42 ] . V_16 = F_31 ( TRUE , TRUE , sizeof( V_58 ) ) ;
V_9 . V_53 [ V_42 ] . V_17 = F_31 ( TRUE , TRUE , sizeof( V_59 ) ) ;
}
V_9 . V_53 [ 0 ] . V_13 = 0 ;
V_9 . V_53 [ 0 ] . V_15 = V_60 ;
signal ( V_21 , F_12 ) ;
#if 0
close(to_disp[0]);
close(from_disp[1]);
#endif
if ( V_27 -> V_30 ) F_32 ( 0 , V_34 , F_16 , V_27 ) ;
F_5 ( ( 3 , L_22 ) ) ;
}
}
}
extern T_7 F_33 ( void ) {
V_9 . V_23 = TRUE ;
F_34 ( NULL , 0 , V_61 , ++ V_62 ) ;
do { ; } while( F_15 ( 1 ) );
F_9 () ;
F_35 ( V_9 . V_56 ) ;
F_8 ( V_9 . V_10 , V_11 ) ;
return TRUE ;
}
static T_2 * F_36 ( int V_63 ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < V_54 ; V_42 ++ ) {
if ( V_9 . V_53 [ V_42 ] . V_13 == V_63 ) return & ( V_9 . V_53 [ V_42 ] ) ;
} ;
return NULL ;
}
int F_37 ( T_2 * V_12 , int V_64 ) {
int V_42 ;
int V_65 = V_12 -> V_17 -> V_66 ;
V_59 * V_67 = ( V_59 * ) V_12 -> V_17 -> V_14 ;
for( V_42 = 0 ; V_42 < V_65 ; V_42 ++ ) {
if ( V_67 [ V_42 ] . V_64 == V_64 )
return V_42 ;
}
return - 1 ;
}
static T_7 F_38 ( T_2 * V_12 , T_4 V_68 , T_8 * V_69 , T_9 V_70 , void * V_71 ) {
int V_72 ;
V_59 * V_73 ;
int V_64 = V_62 ++ ;
if ( ! V_12 ) {
F_5 ( ( 1 , L_23 ) ) ;
return 1 ;
}
V_72 = F_37 ( V_12 , - 1 ) ;
if ( V_72 < 0 ) {
V_59 V_74 ;
V_72 = V_12 -> V_17 -> V_66 ;
F_39 ( V_12 -> V_17 , V_74 ) ;
}
V_73 = & ( ( ( V_59 * ) V_12 -> V_17 -> V_14 ) [ V_72 ] ) ;
V_73 -> V_64 = V_64 ;
V_73 -> V_75 = V_70 ;
V_73 -> V_71 = V_71 ;
F_40 ( & ( V_73 -> V_76 ) , NULL ) ;
F_5 ( ( 4 , L_24 , V_72 ) ) ;
F_5 ( ( 3 , L_25 , F_19 ( V_68 ) , V_12 -> V_13 , V_64 ) ) ;
F_34 ( V_69 , V_12 -> V_13 , V_68 , V_64 ) ;
if ( V_69 ) F_41 ( V_69 , TRUE ) ;
return V_64 ;
}
extern T_10 F_42 (
T_11 V_77 ,
T_4 V_68 ,
int T_12 V_78 ,
T_5 * V_69 ,
T_9 V_70 ,
void * V_71 ) {
return F_38 ( F_36 ( V_77 ) , V_68 , V_69 , V_70 , V_71 ) ;
}
extern void * F_43 ( int V_77 , int V_64 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
int V_72 ;
if ( ! V_12 ) return NULL ;
V_72 = F_37 ( V_12 , V_64 ) ;
if ( V_72 >= 0 )
return F_44 ( V_12 -> V_17 , V_59 , V_72 ) . V_71 ;
else
return NULL ;
}
extern T_9 F_45 ( int V_77 , int V_64 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
int V_72 ;
if ( ! V_12 ) return NULL ;
V_72 = F_37 ( V_12 , V_64 ) ;
if ( V_72 >= 0 )
return F_44 ( V_12 -> V_17 , V_59 , V_72 ) . V_75 ;
else
return NULL ;
}
extern T_13 F_46 ( int V_77 , int V_64 , void * V_71 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
int V_72 ;
if ( ! V_12 ) return FALSE ;
V_72 = F_37 ( V_12 , V_64 ) ;
if ( V_72 < 0 ) return FALSE ;
F_44 ( V_12 -> V_17 , V_59 , V_72 ) . V_71 = V_71 ;
return TRUE ;
}
extern T_13 F_47 ( int V_77 , int V_64 , T_9 V_75 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
int V_72 ;
if ( ! V_12 ) return FALSE ;
V_72 = F_37 ( V_12 , V_64 ) ;
if ( V_72 < 0 ) return FALSE ;
F_44 ( V_12 -> V_17 , V_59 , V_72 ) . V_75 = V_75 ;
return TRUE ;
}
extern T_13 F_48 ( int V_77 , int V_64 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
int V_72 ;
if ( ! V_12 ) return FALSE ;
V_72 = F_37 ( V_12 , V_64 ) ;
if ( V_72 < 0 ) return FALSE ;
F_49 ( V_12 -> V_17 , V_72 ) ;
return TRUE ;
}
static T_3 F_50 ( T_4 type , T_5 * V_69 , void * V_14 ) {
T_2 * V_12 = ( T_2 * ) V_14 ;
char * V_79 ;
if ( type != V_80 ) {
F_5 ( ( 1 , L_26 ) ) ;
return 1 ;
}
if ( V_9 . V_32 -> V_81 ( V_69 , & V_79 ) ) {
F_5 ( ( 1 , L_27 , V_12 -> V_13 , V_79 ) ) ;
F_20 ( V_79 ) ;
}
F_10 ( V_12 ) ;
return 0 ;
}
static T_3 F_51 ( T_4 type , T_5 * V_69 , void * V_14 ) {
T_2 * V_12 = ( T_2 * ) V_14 ;
int V_82 ;
char * V_28 = NULL ;
switch ( type ) {
case V_34 :
F_5 ( ( 1 , L_28 , V_12 -> V_13 ) ) ;
V_12 -> V_15 = V_60 ;
break;
case V_31 :
V_9 . V_32 -> error ( V_69 , & V_82 , & V_28 ) ;
break;
case V_33 :
V_28 = F_17 ( L_11 ) ;
break;
default:
V_28 = F_18 ( L_12 , F_19 ( type ) ) ;
break;
}
if ( V_12 -> V_75 )
V_12 -> V_75 ( V_12 -> V_14 , V_28 ) ;
if ( V_28 ) F_20 ( V_28 ) ;
return TRUE ;
}
int F_52 ( const void * V_83 , const void * V_84 ) {
return ( ( T_2 * ) V_84 ) -> V_13 - ( ( T_2 * ) V_83 ) -> V_13 ;
}
extern int F_53 ( T_5 * V_85 , T_14 V_75 , void * V_86 ) {
T_2 * V_12 = F_36 ( - 1 ) ;
if ( ! V_12 ) return - 1 ;
V_12 -> V_13 = ( V_87 ++ ) ;
V_12 -> V_14 = V_86 ;
V_12 -> V_15 = V_88 ;
V_12 -> V_75 = V_75 ;
F_5 ( ( 1 , L_29 , V_12 -> V_13 ) ) ;
F_54 ( V_12 , V_80 , F_50 , V_12 ) ;
F_38 ( V_12 , V_89 , ( T_8 * ) V_85 , F_51 , V_12 ) ;
return V_12 -> V_13 ;
}
extern void * F_55 ( int V_77 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return V_12 ? V_12 -> V_14 : NULL ;
}
extern T_7 F_56 ( T_11 V_13 , void * V_14 ) {
T_2 * V_12 = F_36 ( V_13 ) ;
if ( V_12 ) {
V_12 -> V_14 = V_14 ;
return TRUE ;
}
return FALSE ;
}
static int F_57 ( T_2 * V_12 , int V_90 ) {
int V_42 = 0 ;
int V_65 = V_12 -> V_16 -> V_66 ;
for ( V_42 = 0 ; V_42 < V_65 ; V_42 ++ ) {
if ( ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_42 ] . V_63 == V_90 ) return V_42 ;
}
return - 1 ;
}
static int F_54 ( T_2 * V_12 , T_4 V_68 , T_9 V_70 , void * V_71 ) {
V_58 V_91 ;
static int V_90 = 1 ;
V_91 . V_63 = V_90 ++ ;
V_91 . type = V_68 ;
V_91 . V_75 = V_70 ;
V_91 . V_71 = V_71 ;
F_39 ( V_12 -> V_16 , V_91 ) ;
return 0 ;
}
extern int F_32 ( int V_77 , T_4 V_68 , T_9 V_70 , void * V_71 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
if ( V_12 ) return F_54 ( V_12 , V_68 , V_70 , V_71 ) ;
else return - 1 ;
}
static T_7 F_58 ( T_2 * V_12 , int V_90 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
if ( V_72 < 0 ) return - 1 ;
F_49 ( V_12 -> V_16 , V_72 ) ;
return 1 ;
}
extern T_7 F_59 ( int V_77 , int V_90 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return F_58 ( V_12 , V_90 ) ;
}
static void * F_60 ( T_2 * V_12 , int V_90 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
if ( V_72 < 0 ) return NULL ;
return ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] . V_71 ;
}
extern void * F_61 ( int V_77 , int V_90 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return F_60 ( V_12 , V_90 ) ;
}
static T_9 F_62 ( T_2 * V_12 , int V_90 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
if ( V_72 < 0 ) return NULL ;
return ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] . V_75 ;
}
extern T_9 F_63 ( int V_77 , int V_90 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return F_62 ( V_12 , V_90 ) ;
}
static T_4 F_64 ( T_2 * V_12 , int V_90 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
if ( V_72 < 0 ) return V_92 ;
return ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] . type ;
}
extern T_4 F_65 ( int V_77 , int V_90 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return V_12 ? F_64 ( V_12 , V_90 ) : V_92 ;
}
static T_7 F_66 ( T_2 * V_12 , int V_90 , T_4 * V_68 , T_9 * V_75 , void * * V_14 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
V_58 * V_91 ;
if ( V_72 < 0 ) return - 1 ;
V_91 = & ( ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] ) ;
if ( V_68 ) * V_68 = V_91 -> type ;
if ( V_75 ) * V_75 = V_91 -> V_75 ;
if ( V_14 ) * V_14 = V_91 -> V_71 ;
return 0 ;
}
extern T_13 F_67 ( int V_77 , int V_90 , T_4 * V_68 , T_9 * V_75 , void * * V_14 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return V_12 && F_66 ( V_12 , V_90 , V_68 , V_75 , V_14 ) ;
}
static T_7 F_68 ( T_2 * V_12 , int V_90 , T_4 V_68 , T_9 V_75 , void * V_14 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
V_58 * V_91 ;
if ( V_72 < 0 ) return - 1 ;
V_91 = & ( ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] ) ;
V_91 -> type = V_68 ;
V_91 -> V_75 = V_75 ;
V_91 -> V_71 = V_14 ;
return 0 ;
}
extern T_13 F_69 ( int V_77 , int V_90 , T_4 V_68 , T_9 V_75 , void * V_14 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return V_12 ? F_68 ( V_12 , V_90 , V_68 , V_75 , V_14 ) : FALSE ;
}
static T_13 F_70 ( T_2 * V_12 , int V_90 , void * V_14 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
if ( V_72 < 0 ) return FALSE ;
( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] . V_71 = V_14 ;
return TRUE ;
}
extern T_13 F_71 ( int V_77 , int V_90 , void * V_14 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return V_12 ? F_70 ( V_12 , V_90 , V_14 ) : FALSE ;
}
extern T_13 F_72 ( T_2 * V_12 , int V_90 , T_9 V_75 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
if ( V_72 < 0 ) return FALSE ;
( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] . V_75 = V_75 ;
return TRUE ;
}
extern T_13 F_73 ( int V_77 , int V_90 , T_9 V_75 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return V_12 ? F_72 ( V_12 , V_90 , V_75 ) : FALSE ;
}
static T_13 F_74 ( T_2 * V_12 , int V_90 , T_4 V_68 ) {
int V_72 = F_57 ( V_12 , V_90 ) ;
if ( V_72 < 0 ) return FALSE ;
( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ V_72 ] . type = V_68 ;
return TRUE ;
}
extern T_13 F_75 ( int V_77 , int V_90 , T_4 V_68 ) {
T_2 * V_12 = F_36 ( V_77 ) ;
return V_12 ? F_74 ( V_12 , V_90 , V_68 ) : FALSE ;
}
extern void F_76 ( T_15 V_75 , void * V_71 ) {
int V_42 ;
for( V_42 = 0 ; V_42 < V_54 ; V_42 ++ ) {
T_2 * V_12 = & ( V_9 . V_53 [ V_42 ] ) ;
V_75 ( V_12 -> V_13 , V_12 -> V_14 , V_71 ) ;
}
}
static V_59 * F_77 ( T_2 * V_12 , int V_64 ) {
int V_72 = F_37 ( V_12 , V_64 ) ;
if( V_72 < 0 ) return NULL ;
return ( ( V_59 * ) ( V_12 -> V_17 -> V_14 ) ) + V_72 ;
}
static V_58 * F_78 ( T_2 * V_12 , T_4 V_68 , int * V_93 ) {
int V_65 = V_12 -> V_16 -> V_66 ;
V_58 * V_73 = NULL ;
for (; ( * V_93 ) < V_65 ; ( * V_93 ) ++ ) {
if ( ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ * V_93 ] . type == V_68 ) {
V_73 = & ( ( ( V_58 * ) ( V_12 -> V_16 -> V_14 ) ) [ * V_93 ] ) ;
( * V_93 ) ++ ;
break;
}
}
return V_73 ;
}
static long F_79 ( T_16 * V_84 , T_17 V_66 , T_11 V_13 , T_4 V_68 , T_10 V_64 , void * V_14 V_78 ) {
T_2 * V_12 = F_36 ( V_13 ) ;
T_8 * V_69 = F_29 () ;
F_5 ( ( 1 , L_30 , V_13 , F_19 ( V_68 ) , V_64 ) ) ;
F_80 ( V_69 , V_84 , ( V_94 ) V_66 ) ;
if ( V_12 ) {
V_59 * V_73 = F_77 ( V_12 , V_64 ) ;
int V_42 ;
V_58 * V_91 ;
T_13 V_95 = TRUE ;
if ( V_73 ) {
if ( V_73 -> V_75 ) {
V_95 = V_73 -> V_75 ( V_68 , V_69 , V_73 -> V_71 ) ;
}
V_73 -> V_64 = - 1 ;
V_73 -> V_75 = NULL ;
V_73 -> V_71 = 0 ;
V_73 -> V_76 . V_96 = 0 ;
V_73 -> V_76 . V_97 = 0 ;
F_5 ( ( 2 , L_31 , V_64 , V_95 ? L_32 : L_33 ) ) ;
}
V_42 = 0 ;
while( V_95 && ( V_91 = F_78 ( V_12 , V_68 , & V_42 ) ) ) {
if ( V_91 -> V_75 )
V_95 = V_91 -> V_75 ( V_68 , V_69 , V_91 -> V_71 ) ;
F_5 ( ( 2 , L_34 , F_19 ( V_91 -> type ) , V_91 -> V_63 , V_95 ? L_32 : L_33 ) ) ;
}
} else {
F_5 ( ( 1 , L_35 ) ) ;
}
F_41 ( V_69 , TRUE ) ;
return 1 ;
}
extern int F_81 ( T_18 * V_98 , T_18 * V_99 ) {
F_82 ( V_9 . V_57 . V_100 , V_98 ) ;
F_82 ( V_9 . V_57 . V_100 , V_99 ) ;
F_82 ( V_9 . V_56 , V_99 ) ;
return 2 ;
}
extern int F_83 ( T_18 * V_98 , T_18 * V_99 ) {
int V_101 = 0 ;
if ( F_84 ( V_9 . V_57 . V_100 , V_99 ) || F_84 ( V_9 . V_56 , V_99 ) ) {
F_5 ( ( 1 , L_36 ) ) ;
return - 1 ;
}
if ( F_84 ( V_9 . V_57 . V_100 , V_98 ) ) {
F_5 ( ( 3 , L_37 ) ) ;
F_85 ( & ( V_9 . V_57 ) , F_79 , & ( V_9 ) ) ;
}
return V_101 ;
}
extern int F_86 ( int T_19 V_78 , T_18 * V_98 , T_18 * V_102 , T_18 * V_99 , struct V_103 * V_104 ) {
T_18 V_105 , V_106 , V_107 ;
int V_101 ;
if ( V_98 == NULL ) { V_98 = & V_105 ; F_87 ( V_98 ) ; }
if ( V_102 == NULL ) { V_102 = & V_106 ; F_87 ( V_102 ) ; }
if ( V_99 == NULL ) { V_99 = & V_107 ; F_87 ( V_99 ) ; }
F_81 ( V_98 , V_99 ) ;
F_5 ( ( 5 , L_38 ) ) ;
V_101 = F_88 ( V_108 , V_98 , V_102 , V_99 , V_104 ) ;
F_83 ( V_98 , V_99 ) ;
return V_101 ;
}
extern T_7 F_89 ( struct V_103 * V_104 ) {
if ( F_86 ( 0 , NULL , NULL , NULL , V_104 ) < 0 ) {
return - 1 ;
} else {
return V_109 ;
}
}
T_5 * F_90 ( void ) {
return ( T_5 * ) F_29 () ;
}
T_5 * F_91 ( T_5 * V_110 , T_5 * V_111 ) {
T_8 * V_69 = F_29 () ;
T_8 * V_112 = ( T_8 * ) V_110 ;
T_8 * V_113 = ( T_8 * ) V_111 ;
F_80 ( V_69 , V_112 -> V_14 , V_112 -> V_66 ) ;
F_80 ( V_69 , V_113 -> V_14 , V_113 -> V_66 ) ;
return ( T_5 * ) V_69 ;
}
char * F_92 ( T_5 * V_114 , const char * V_115 , const char * V_116 , int V_117 , const char * V_2 ) {
T_8 * V_69 = ( T_8 * ) V_114 ;
T_20 * V_4 = F_93 ( V_115 ) ;
char * V_118 = ( char * ) V_69 -> V_14 ;
int V_119 = V_69 -> V_66 ;
long V_120 = V_119 ;
V_118 [ V_120 - 1 ] = '\0' ;
while( V_120 > 2 ) {
char * V_121 = V_118 ;
long V_122 = strlen ( V_121 ) + 1 ;
char * V_123 = V_118 + V_122 ;
long V_124 ;
V_120 -= V_122 ;
if ( V_120 < 0 ) {
F_94 ( V_4 , TRUE ) ;
return NULL ;
}
V_124 = strlen ( V_123 ) + 1 ;
V_120 -= V_124 ;
V_118 = V_123 + V_124 ;
if ( V_120 < 0 ) {
F_94 ( V_4 , TRUE ) ;
return NULL ;
}
F_95 ( V_4 , V_2 , V_121 , V_123 ) ;
}
F_96 ( V_4 , V_4 -> V_66 - V_117 ) ;
F_97 ( V_4 , V_116 ) ;
return F_94 ( V_4 , FALSE ) ;
}
void F_98 ( T_5 * V_114 , ... ) {
T_8 * V_69 = ( T_8 * ) V_114 ;
T_1 V_3 ;
va_start ( V_3 , V_114 ) ;
do {
char * V_125 = va_arg ( V_3 , char * ) ;
if ( V_125 ) {
char * V_126 = va_arg ( V_3 , char * ) ;
F_80 ( V_69 , ( T_16 * ) V_125 , ( V_94 ) strlen ( V_125 ) + 1 ) ;
F_80 ( V_69 , ( T_16 * ) V_126 , ( V_94 ) strlen ( V_126 ) + 1 ) ;
continue;
}
break;
} while( 1 );
va_end ( V_3 ) ;
}
