extern void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 , T_4 * T_5 V_5 , void * V_6 ) {
T_6 V_7 ;
F_2 ( & V_7 , V_8 , TRUE , V_3 ) ;
F_3 ( V_6 ? * ( ( V_9 * ) V_6 ) : FALSE , & V_7 , V_1 , V_2 , 0 , V_4 , NULL ) ;
}
extern void F_4 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 , T_4 * T_5 V_5 , void * V_6 ) {
T_6 V_7 ;
F_2 ( & V_7 , V_8 , TRUE , V_3 ) ;
F_5 ( V_6 ? * ( ( V_9 * ) V_6 ) : FALSE , & V_7 , V_1 , V_2 , 0 , V_4 , NULL ) ;
}
extern void F_6 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 , T_4 * T_5 V_5 , void * V_6 ) {
T_6 V_7 ;
F_2 ( & V_7 , V_8 , TRUE , V_3 ) ;
F_7 ( V_6 ? * ( ( V_9 * ) V_6 ) : FALSE , & V_7 , V_1 , V_2 , 0 , V_4 , NULL ) ;
}
extern void F_8 ( T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 V_5 ,
int V_4 ,
T_4 * T_7 V_5 ,
void * V_10 ) {
int V_11 = V_10 ? * ( ( int * ) V_10 ) : - 1 ;
F_9 ( V_1 , V_4 , V_2 , 0 , V_11 , V_12 ) ;
}
extern void F_10 ( T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 V_5 ,
int V_4 ,
T_4 * T_7 V_5 ,
void * V_10 ) {
int V_11 = V_10 ? * ( ( int * ) V_10 ) : - 1 ;
F_9 ( V_1 , V_4 , V_2 , 0 , V_11 , V_13 ) ;
}
extern void F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 V_5 , T_4 * T_5 V_5 , void * V_14 ) {
F_12 ( ( V_15 ) V_14 , V_2 , V_3 , V_1 ) ;
}
extern void F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , int V_4 V_5 , T_4 * T_8 V_5 , void * T_9 V_5 ) {
T_2 * V_16 = NULL ;
T_1 * V_17 = NULL ;
T_10 V_18 , V_19 ;
const T_11 * V_20 = NULL ;
int V_21 = 0 ;
T_6 V_7 ;
F_2 ( & V_7 , V_8 , TRUE , V_3 ) ;
V_21 = F_5 ( FALSE , & V_7 , V_1 , V_2 , V_21 , V_4 , & V_16 ) ;
if ( V_16 ) {
V_18 = F_14 ( V_16 , 0 ) ;
V_19 = F_14 ( V_16 , 2 ) ;
V_20 = F_15 ( V_18 ) ;
F_16 ( V_7 . V_22 , L_1 ,
F_17 ( 0 , V_20 -> V_23 , L_2 ) ,
V_18 ) ;
if( V_1 ) {
T_12 * V_24 ;
const T_13 * V_25 ;
V_17 = F_18 ( V_7 . V_22 , V_26 ) ;
F_19 ( V_17 , V_27 , V_2 , V_21 - 4 , 2 , V_18 ,
L_3 , F_17 ( 0 , V_20 -> V_23 , L_2 ) , V_18 ) ;
V_24 = F_20 ( V_17 , V_28 , V_2 , V_21 - 2 , 2 , V_19 ) ;
if ( V_20 -> V_29 && ( V_25 = F_21 ( V_19 , V_20 -> V_29 ) ) ) {
V_25 = F_22 ( F_23 () , L_4 , V_25 , V_19 ) ;
} else {
V_25 = F_22 ( F_23 () , L_5 , V_19 ) ;
}
F_24 ( V_24 , L_6 , V_25 ) ;
}
}
}
static int F_25 ( V_9 V_30 , T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , int V_21 , T_14 * V_31 ) {
T_15 V_32 = 0 ;
T_16 V_33 ;
V_9 V_34 ;
T_17 V_35 ;
T_14 V_11 ;
T_14 V_36 ;
if( ! V_30 ) {
V_21 = F_26 ( V_3 , V_1 , V_2 , V_21 , & V_33 , & V_34 , & V_35 ) ;
V_21 = F_27 ( V_3 , V_1 , V_2 , V_21 , & V_11 , NULL ) ;
} else {
V_11 = F_28 ( V_2 , V_21 ) ;
}
if ( V_11 > 8 || V_11 < 1 ) {
F_29 ( V_37 ) ;
} else {
for( V_36 = 1 ; V_36 <= V_11 ; V_36 ++ ) {
V_32 = ( V_32 << 8 ) | F_30 ( V_2 , V_21 ) ;
V_21 ++ ;
}
if ( V_32 > 0xffffffff ) {
T_12 * V_24 = F_31 ( V_1 , V_38 , V_2 , V_21 - V_11 , V_11 , V_32 ) ;
F_32 ( V_3 , V_24 , & V_39 ) ;
* V_31 = 0 ;
} else {
F_20 ( V_1 , V_40 , V_2 , V_21 - V_11 , V_11 , ( T_14 ) V_32 ) ;
* V_31 = ( T_14 ) V_32 ;
}
}
return V_21 ;
}
static int F_33 ( V_9 V_30 , T_3 * V_3 , T_1 * V_1 , T_2 * V_2 , int V_21 , T_14 * V_41 ) {
T_16 V_33 ;
V_9 V_34 ;
T_17 V_35 ;
T_14 V_11 ;
T_15 V_42 = 0 ;
T_14 V_36 ;
if( ! V_30 ) {
V_21 = F_26 ( V_3 , V_1 , V_2 , V_21 , & V_33 , & V_34 , & V_35 ) ;
V_21 = F_27 ( V_3 , V_1 , V_2 , V_21 , & V_11 , NULL ) ;
} else {
V_11 = F_28 ( V_2 , V_21 ) ;
}
if ( V_11 > 8 || V_11 < 1 ) {
F_29 ( V_37 ) ;
} else {
for( V_36 = 1 ; V_36 <= V_11 ; V_36 ++ ) {
V_42 = ( V_42 << 8 ) | F_30 ( V_2 , V_21 ) ;
V_21 ++ ;
}
if ( V_42 > 0xffffffff ) {
T_12 * V_24 = F_31 ( V_1 , V_43 , V_2 , V_21 - V_11 , V_11 , V_42 ) ;
F_32 ( V_3 , V_24 , & V_44 ) ;
* V_41 = 0xfffffffd ;
} else {
T_12 * V_24 = F_20 ( V_1 , V_45 , V_2 , V_21 - V_11 , V_11 , ( T_14 ) V_42 ) ;
if ( V_42 == V_46 ) {
F_24 ( V_24 , L_7 ) ;
} else if ( V_42 == V_47 ) {
F_24 ( V_24 , L_8 ) ;
} else if ( V_42 == V_48 ) {
F_24 ( V_24 , L_9 ) ;
}
* V_41 = ( T_14 ) V_42 ;
}
}
return V_21 ;
}
T_18 * F_34 ( T_10 V_49 ) {
T_18 * V_50 = NULL ;
V_50 = ( T_18 * ) F_35 ( V_51 , F_36 ( ( T_14 ) ( V_49 ) ) ) ;
return V_50 ;
}
const T_11 * F_15 ( T_10 V_49 ) {
T_18 * V_50 = NULL ;
V_50 = F_34 ( V_49 ) ;
if ( ! V_50 ) return & V_52 ;
return V_50 -> V_20 ;
}
static T_17 F_37 ( T_19 V_53 , T_19 V_54 ) {
return F_38 ( V_54 ) - F_38 ( V_53 ) ;
}
V_9 F_39 ( T_10 V_49 ) {
T_18 * V_50 = NULL ;
V_50 = ( T_18 * ) F_35 ( V_51 , F_36 ( ( T_14 ) ( V_49 ) ) ) ;
if( ! V_50 ) return TRUE ;
return V_50 -> V_55 ;
}
void F_40 ( const T_11 * V_20 , T_20 V_56 ) {
T_11 * V_57 = NULL , * V_58 = NULL , * V_59 = NULL ;
T_18 * V_50 = NULL ;
T_21 * V_60 ;
V_9 V_61 = FALSE ;
T_22 V_62 = 0 , V_63 = 0 , V_36 = 0 , V_64 = 0 ;
if ( ! V_51 ) {
V_51 = F_41 ( F_37 ) ;
while ( V_65 [ V_36 ] . V_66 != NULL ) {
V_57 = F_42 ( F_43 () , T_11 ) ;
V_57 -> V_67 = V_65 [ V_36 ] . V_68 ;
V_60 = ( T_21 * ) F_44 ( F_43 () , sizeof( T_21 ) * 2 ) ;
V_60 [ 0 ] . V_66 = V_65 [ V_36 ] . V_66 ;
V_57 -> V_23 = V_60 ;
V_57 -> V_4 = & V_27 ;
V_57 -> V_69 = & V_26 ;
F_45 ( ( V_57 -> V_67 ) << 16 , V_70 , & V_62 ) ;
if ( V_62 != - 1 ) {
V_62 ++ ; V_63 = V_62 ;
while( ( V_70 [ V_62 ] . V_66 != NULL ) && ( ( ( V_70 [ V_62 ] . V_68 ) >> 16 ) == ( V_57 -> V_67 ) ) ) {
V_62 ++ ;
} ;
if ( V_63 < V_62 ) {
V_60 = ( T_21 * ) F_44 ( F_43 () , sizeof( T_21 ) * ( V_62 - V_63 + 1 ) ) ;
for ( V_64 = 0 ; V_63 < V_62 ; V_64 ++ ) {
V_60 [ V_64 ] . V_66 = V_70 [ V_63 ] . V_66 ;
V_60 [ V_64 ] . V_68 = ( V_70 [ V_63 ] . V_68 & 0xffff ) ;
V_63 ++ ;
} ;
V_57 -> V_71 = V_60 ;
}
}
if ( ! F_45 ( ( V_57 -> V_67 ) << 16 , V_72 , & V_62 ) ) {
V_62 ++ ; V_63 = V_62 ;
while( ( V_72 [ V_62 ] . V_66 != NULL ) && ( ( V_72 [ V_62 ] . V_68 >> 16 ) == ( V_57 -> V_67 ) ) ) {
} ;
if ( V_63 < V_62 ) {
V_60 = F_46 ( T_21 , V_62 - V_63 + 1 ) ;
for ( V_64 = 0 ; V_63 < V_36 ; V_64 ++ ) {
V_60 [ V_64 ] . V_66 = V_72 [ V_63 ] . V_66 ;
V_60 [ V_64 ] . V_68 = ( V_72 [ V_63 ] . V_68 & 0xffff ) ;
V_63 ++ ;
} ;
V_57 -> V_29 = V_60 ;
}
} ;
V_50 = F_42 ( F_43 () , T_18 ) ;
V_50 -> V_55 = TRUE ;
V_50 -> V_20 = V_57 ;
F_47 ( V_51 , F_48 ( V_57 -> V_67 ) , ( V_73 ) V_50 ) ;
V_36 ++ ;
} ;
V_57 = NULL ;
} ;
V_61 = F_39 ( V_20 -> V_67 ) ;
if ( ( ( V_56 == V_74 ) || ( V_56 == V_75 ) ) && V_61 ) {
V_50 = F_42 ( F_43 () , T_18 ) ;
V_50 -> V_55 = FALSE ;
V_50 -> V_20 = ( T_11 * ) V_20 ;
F_49 ( V_51 , F_48 ( V_20 -> V_67 ) , ( V_73 ) V_50 ) ;
return;
} ;
if( V_61 ) V_56 = V_76 ;
V_50 = F_34 ( V_20 -> V_67 ) ;
if ( V_50 == NULL ) {
V_50 = F_42 ( F_43 () , T_18 ) ;
V_50 -> V_55 = FALSE ;
V_50 -> V_20 = ( T_11 * ) V_20 ;
F_47 ( V_51 , F_48 ( V_20 -> V_67 ) , ( V_73 ) V_50 ) ;
return;
}
V_57 = V_50 -> V_20 ;
if ( V_56 == V_76 ) {
V_58 = ( T_11 * ) V_20 ;
V_59 = V_57 ;
} ;
if ( V_56 == V_77 ) {
V_58 = V_57 ;
V_59 = ( T_11 * ) V_20 ;
} ;
( V_58 -> V_4 ? ( V_57 -> V_4 = V_58 -> V_4 ) : ( V_57 -> V_4 = V_59 -> V_4 ) ) ;
( V_58 -> V_69 ? ( V_57 -> V_69 = V_58 -> V_69 ) : ( V_57 -> V_69 = V_59 -> V_69 ) ) ;
( V_58 -> V_23 ? ( V_57 -> V_23 = V_58 -> V_23 ) : ( V_57 -> V_23 = V_59 -> V_23 ) ) ;
( V_58 -> V_29 ? ( V_57 -> V_29 = V_58 -> V_29 ) : ( V_57 -> V_29 = V_59 -> V_29 ) ) ;
( V_58 -> V_71 ? ( V_57 -> V_71 = V_58 -> V_71 ) : ( V_57 -> V_71 = V_59 -> V_71 ) ) ;
( V_58 -> V_78 ? ( V_57 -> V_78 = V_58 -> V_78 ) : ( V_57 -> V_78 = V_59 -> V_78 ) ) ;
( V_58 -> V_79 ? ( V_57 -> V_79 = V_58 -> V_79 ) : ( V_57 -> V_79 = V_59 -> V_79 ) ) ;
( V_58 -> V_80 ? ( V_57 -> V_80 = V_58 -> V_80 ) : ( V_57 -> V_80 = V_59 -> V_80 ) ) ;
( V_58 -> V_81 ? ( V_57 -> V_81 = V_58 -> V_81 ) : ( V_57 -> V_81 = V_59 -> V_81 ) ) ;
( V_58 -> V_82 ? ( V_57 -> V_82 = V_58 -> V_82 ) : ( V_57 -> V_82 = V_59 -> V_82 ) ) ;
V_50 -> V_20 = V_57 ;
V_50 -> V_55 = FALSE ;
}
static int F_50 ( V_9 V_30 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 ) {
T_2 * V_16 = NULL ;
T_1 * V_17 = NULL ;
T_10 V_18 , V_19 ;
const T_11 * V_20 = NULL ;
V_21 = F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , & V_16 ) ;
if ( V_16 ) {
V_18 = F_14 ( V_16 , 0 ) ;
V_19 = F_14 ( V_16 , 2 ) ;
V_84 = ( V_18 << 16 ) | V_19 ;
V_20 = F_15 ( V_18 ) ;
F_16 ( T_23 -> V_22 , L_1 ,
F_17 ( 0 , V_20 -> V_23 , L_2 ) ,
V_18 ) ;
if( V_1 ) {
V_17 = F_18 ( T_23 -> V_22 , V_26 ) ;
F_19 ( V_17 , V_27 , V_2 , V_21 - 4 , 2 , V_18 ,
L_10 , F_17 ( 0 , V_20 -> V_23 , L_2 ) , V_18 ) ;
}
{
T_12 * V_24 = F_20 ( V_17 , V_28 , V_2 , V_21 - 2 , 2 , V_19 ) ;
const T_13 * V_25 ;
if ( V_20 -> V_23 && ( V_25 = F_21 ( V_19 , V_20 -> V_23 ) ) ) {
V_25 = F_22 ( F_23 () , L_4 , V_25 , V_19 ) ;
} else {
V_25 = F_22 ( F_23 () , L_5 , V_19 ) ;
}
F_24 ( V_24 , L_11 , V_25 ) ;
}
} else {
V_20 = & V_52 ;
}
V_85 . V_20 = V_20 ;
return V_21 ;
}
static int F_51 ( V_9 V_30 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 ) {
T_2 * V_16 ;
T_1 * V_17 = NULL ;
T_10 V_18 , V_19 ;
const T_11 * V_20 = NULL ;
const T_24 * V_86 = NULL ;
V_21 = F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , & V_16 ) ;
if ( V_16 ) {
V_18 = F_14 ( V_16 , 0 ) ;
V_19 = F_14 ( V_16 , 2 ) ;
V_84 = ( V_18 << 16 ) | V_19 ;
V_20 = F_15 ( V_18 ) ;
F_16 ( T_23 -> V_22 , L_1 ,
F_17 ( 0 , V_20 -> V_23 , L_2 ) ,
V_18 ) ;
if( V_1 ) {
V_17 = F_18 ( T_23 -> V_22 , V_26 ) ;
}
F_19 ( V_17 , V_27 , V_2 , V_21 - 4 , 2 , V_18 ,
L_3 , F_17 ( 0 , V_20 -> V_23 , L_2 ) , V_18 ) ;
V_85 . V_20 = V_20 ;
if ( V_20 -> V_81 ) {
for ( V_86 = V_20 -> V_81 ; V_86 -> V_4 ; V_86 ++ ) {
if ( V_19 == V_86 -> V_67 ) {
break;
}
}
if ( ! V_86 -> V_4 ) V_86 = & V_87 ;
} else {
V_86 = & V_87 ;
}
V_85 . V_86 = V_86 ;
{
T_12 * V_24 = F_20 ( V_17 , V_88 , V_2 , V_21 - 2 , 2 , V_19 ) ;
const T_13 * V_25 ;
if ( V_20 -> V_71 && ( V_25 = F_21 ( V_19 , V_20 -> V_71 ) ) ) {
V_25 = F_22 ( F_23 () , L_4 , V_25 , V_19 ) ;
} else {
V_25 = F_22 ( F_23 () , L_5 , V_19 ) ;
}
F_24 ( V_24 , L_12 , V_25 ) ;
}
} else {
V_85 . V_20 = & V_52 ;
V_85 . V_86 = & V_87 ;
}
return V_21 ;
}
static int F_52 ( V_9 V_30 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 ) {
T_2 * V_16 ;
T_1 * V_17 = NULL ;
T_10 V_18 , V_19 ;
const T_11 * V_20 = NULL ;
const T_25 * V_89 ;
V_21 = F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , & V_16 ) ;
if ( V_16 ) {
V_18 = F_14 ( V_16 , 0 ) ;
V_19 = F_14 ( V_16 , 2 ) ;
V_84 = ( V_18 << 16 ) | V_19 ;
V_20 = F_15 ( V_18 ) ;
F_16 ( T_23 -> V_22 , L_1 ,
F_17 ( 0 , V_20 -> V_23 , L_2 ) ,
V_18 ) ;
if( V_1 ) {
V_17 = F_18 ( T_23 -> V_22 , V_26 ) ;
}
F_19 ( V_17 , V_27 , V_2 , V_21 - 4 , 2 , V_18 ,
L_3 , F_17 ( 0 , V_20 -> V_23 , L_2 ) , V_18 ) ;
if ( V_20 -> V_80 ) {
for ( V_89 = V_20 -> V_80 ; V_89 -> V_4 ; V_89 ++ ) {
if ( V_19 == V_89 -> V_67 ) {
break;
}
}
if ( ! V_89 -> V_4 ) V_89 = & V_90 ;
V_85 . V_20 = V_20 ;
V_85 . V_89 = V_89 ;
} else {
V_85 . V_20 = & V_52 ;
V_85 . V_89 = & V_90 ;
}
{
T_12 * V_24 = F_20 ( V_17 , V_91 , V_2 , V_21 - 2 , 2 , V_19 ) ;
const T_13 * V_25 ;
if ( V_20 -> V_29 && ( V_25 = F_21 ( V_19 , V_20 -> V_29 ) ) ) {
V_25 = F_22 ( F_23 () , L_4 , V_25 , V_19 ) ;
} else {
V_25 = F_22 ( F_23 () , L_5 , V_19 ) ;
}
F_24 ( V_24 , L_6 , V_25 ) ;
}
} else {
V_85 . V_20 = & V_52 ;
V_85 . V_89 = & V_90 ;
}
return V_21 ;
}
static int F_53 ( V_9 V_30 V_5 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 V_5 ) {
T_16 V_33 ;
V_9 V_34 , V_92 ;
T_17 V_35 ;
T_14 V_11 ;
T_10 V_19 ;
int V_93 ;
const T_11 * V_20 ;
const T_26 * V_94 ;
T_2 * V_95 = NULL ;
V_21 = F_26 ( T_23 -> V_3 , V_1 , V_2 , V_21 , & V_33 , & V_34 , & V_35 ) ;
V_21 = F_27 ( T_23 -> V_3 , V_1 , V_2 , V_21 , & V_11 , & V_92 ) ;
V_93 = V_21 + V_11 ;
if( ( V_33 != V_96 )
|| ( V_35 != V_97 ) ) {
F_54 ( V_1 , V_2 , V_21 - 2 , 2 , L_13 , V_33 , V_34 , V_35 ) ;
return V_93 ;
}
V_95 = F_55 ( V_2 , V_21 , V_11 , V_11 ) ;
V_19 = V_84 & 0xffff ;
V_20 = ( V_85 . V_20 ) ? V_85 . V_20 : & V_52 ;
if ( V_20 -> V_79 ) {
for ( V_94 = V_20 -> V_79 ; V_94 && V_94 -> V_4 ; V_94 ++ ) {
if ( V_19 == V_94 -> V_67 ) {
break;
}
}
} else {
V_94 = & V_98 ;
}
if ( V_94 && V_94 -> V_4 ) {
if ( ! V_94 -> V_99 ) V_94 = & V_98 ;
V_94 -> V_99 ( V_1 , V_95 , T_23 -> V_3 , * ( V_94 -> V_4 ) , & V_85 , V_94 -> V_100 ) ;
}
return V_93 ;
}
static int F_56 ( V_9 V_30 V_5 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 V_5 ) {
T_2 * V_95 ;
T_14 V_101 = 0xffffffff ;
const T_26 * V_102 ;
const T_13 * V_25 ;
T_12 * V_24 ;
V_21 = F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , & V_95 ) ;
V_24 = T_23 -> V_22 ;
switch( F_57 ( V_95 ) ) {
case 4 : V_101 = F_58 ( V_95 , 0 ) ; break;
case 3 : V_101 = F_59 ( V_95 , 0 ) ; break;
case 2 : V_101 = F_14 ( V_95 , 0 ) ; break;
case 1 : V_101 = F_30 ( V_95 , 0 ) ; break;
default: break;
}
V_85 . V_103 = & V_98 ;
if ( V_85 . V_89 && V_85 . V_89 -> V_104 ) {
for( V_102 = V_85 . V_89 -> V_104 ; V_102 -> V_4 ; V_102 ++ ) {
if ( V_102 -> V_67 == V_101 ) {
V_85 . V_103 = V_102 ;
break;
}
}
}
if ( V_85 . V_89 && V_85 . V_89 -> V_23 && ( V_25 = F_21 ( V_101 , V_85 . V_89 -> V_23 ) ) ) {
V_25 = F_22 ( F_23 () , L_4 , V_25 , V_101 ) ;
} else {
V_25 = F_22 ( F_23 () , L_5 , V_101 ) ;
}
F_24 ( V_24 , L_11 , V_25 ) ;
return V_21 ;
}
static int F_60 ( V_9 V_30 V_5 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 V_5 ) {
int V_93 ;
T_16 V_33 ;
V_9 V_34 , V_92 ;
T_17 V_35 ;
T_14 V_11 ;
T_2 * V_95 = NULL ;
V_21 = F_26 ( T_23 -> V_3 , V_1 , V_2 , V_21 , & V_33 , & V_34 , & V_35 ) ;
V_21 = F_27 ( T_23 -> V_3 , V_1 , V_2 , V_21 , & V_11 , & V_92 ) ;
V_93 = V_21 + V_11 ;
if( ( V_33 != V_96 )
|| ( V_35 != V_97 ) ) {
F_54 ( V_1 , V_2 , V_21 - 2 , 2 , L_13 , V_33 , V_34 , V_35 ) ;
return V_93 ;
}
V_95 = F_55 ( V_2 , V_21 , V_11 , V_11 ) ;
if ( V_85 . V_103 && V_85 . V_103 -> V_99 ) {
V_85 . V_103 -> V_99 ( V_1 , V_95 , T_23 -> V_3 , * ( V_85 . V_103 -> V_4 ) , & V_85 , V_85 . V_103 -> V_100 ) ;
}
return V_93 ;
}
static int F_61 ( V_9 V_30 V_5 , T_2 * V_2 , int V_21 V_5 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 V_5 ) {
return F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , NULL ) ;
}
static int F_62 ( V_9 V_30 V_5 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 V_5 ) {
T_2 * V_95 ;
T_14 V_101 = 0xffffffff ;
const T_26 * V_105 ;
const T_13 * V_25 ;
T_12 * V_24 ;
V_21 = F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , & V_95 ) ;
V_24 = T_23 -> V_22 ;
if ( V_95 ) {
switch( F_57 ( V_95 ) ) {
case 4 : V_101 = F_58 ( V_95 , 0 ) ; break;
case 3 : V_101 = F_59 ( V_95 , 0 ) ; break;
case 2 : V_101 = F_14 ( V_95 , 0 ) ; break;
case 1 : V_101 = F_30 ( V_95 , 0 ) ; break;
default: break;
}
}
V_85 . V_103 = & V_98 ;
if ( V_85 . V_86 && V_85 . V_86 -> V_104 ) {
for( V_105 = V_85 . V_86 -> V_104 ; V_105 -> V_4 ; V_105 ++ ) {
if ( V_105 -> V_67 == V_101 ) {
V_85 . V_103 = V_105 ;
break;
}
}
} else {
V_85 . V_103 = & V_98 ;
}
if ( V_85 . V_86 && V_85 . V_86 -> V_23 && ( V_25 = F_21 ( V_101 , V_85 . V_86 -> V_23 ) ) ) {
V_25 = F_22 ( F_23 () , L_4 , V_25 , V_101 ) ;
} else {
V_25 = F_22 ( F_23 () , L_5 , V_101 ) ;
}
F_24 ( V_24 , L_11 , V_25 ) ;
return V_21 ;
}
static int F_63 ( V_9 V_30 V_5 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 V_5 ) {
T_2 * V_95 ;
int V_93 ;
T_16 V_33 ;
V_9 V_34 , V_92 ;
T_17 V_35 ;
T_14 V_11 ;
V_21 = F_26 ( T_23 -> V_3 , V_1 , V_2 , V_21 , & V_33 , & V_34 , & V_35 ) ;
V_21 = F_27 ( T_23 -> V_3 , V_1 , V_2 , V_21 , & V_11 , & V_92 ) ;
V_93 = V_21 + V_11 ;
if( ( V_33 != V_96 )
|| ( V_35 != V_97 ) ) {
F_54 ( V_1 , V_2 , V_21 - 2 , 2 , L_13 , V_33 , V_34 , V_35 ) ;
return V_93 ;
}
V_95 = F_55 ( V_2 , V_21 , V_11 , V_11 ) ;
if ( V_85 . V_103 && V_85 . V_103 -> V_99 ) {
V_85 . V_103 -> V_99 ( V_1 , V_95 , T_23 -> V_3 , * ( V_85 . V_103 -> V_4 ) , & V_85 , V_85 . V_103 -> V_100 ) ;
}
return V_93 ;
}
static int F_64 ( V_9 V_30 V_5 , T_2 * V_2 , int V_21 V_5 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 V_5 ) {
return F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , & V_2 ) ;
}
static int F_65 ( V_9 V_30 , T_2 * V_2 , int V_21 , T_6 * T_23 V_5 , T_1 * V_1 , int V_83 ) {
T_2 * V_16 ;
T_1 * V_106 = NULL ;
T_14 V_107 ;
int V_36 , V_11 , V_108 ;
V_108 = V_21 ;
V_21 = F_5 ( V_30 , T_23 , V_1 , V_2 , V_21 , V_83 , & V_16 ) ;
if ( V_16 ) {
V_107 = 0 ;
V_11 = F_57 ( V_16 ) ;
for( V_36 = 0 ; V_36 < V_11 ; V_36 ++ ) {
V_107 = ( V_107 << 8 ) | F_30 ( V_16 , V_36 ) ;
}
F_16 ( T_23 -> V_22 , L_14 , V_107 & 0x03 , V_107 >> 2 , V_107 & 0x03 , V_107 >> 2 ) ;
if( V_1 ) {
V_106 = F_18 ( T_23 -> V_22 , V_109 ) ;
}
F_20 ( V_106 , V_110 , V_2 , V_108 , V_21 - V_108 , V_107 & 0x03 ) ;
F_20 ( V_106 , V_111 , V_2 , V_108 , V_21 - V_108 , V_107 >> 2 ) ;
}
return V_21 ;
}
static void F_66 ( T_2 * V_2 , T_3 * V_3 , T_1 * V_1 ) {
F_67 ( V_2 , V_3 , V_1 , V_112 , V_113 ) ;
}
static void
F_68 ( T_2 * V_2 , T_3 * V_3 , T_1 * V_1 )
{
T_12 * V_114 ;
T_6 V_7 ;
V_115 = NULL ;
V_116 = NULL ;
F_2 ( & V_7 , V_8 , TRUE , V_3 ) ;
V_85 . V_117 = NULL ;
V_85 . V_118 = NULL ;
V_85 . V_119 = NULL ;
V_85 . V_120 = NULL ;
V_85 . V_121 = NULL ;
V_85 . V_20 = NULL ;
V_85 . V_86 = NULL ;
V_85 . V_89 = NULL ;
V_85 . V_122 = NULL ;
V_85 . V_103 = NULL ;
if( F_57 ( V_2 ) >= 6 ) {
if( ! F_69 ( V_2 , 0 , L_15 , 6 ) ) {
static V_15 V_123 = NULL ;
if( ! V_123 ) {
V_123 = F_70 ( L_16 ) ;
}
if( V_123 ) {
F_12 ( V_123 , V_2 , V_3 , V_1 ) ;
return;
}
}
{
T_12 * V_124 = NULL ;
T_14 V_125 = 0 , V_21 = 0 ;
V_125 = F_58 ( V_2 , V_21 ) ;
V_124 = F_20 ( V_1 , V_126 , V_2 , V_21 , 4 , V_125 ) ;
F_71 ( V_124 ) ;
if( F_72 ( V_127 , V_125 , V_2 , V_3 , V_1 ) ) {
return;
}
}
}
F_73 ( V_3 -> V_128 , V_129 , L_17 ) ;
if ( V_1 ) {
V_114 = F_9 ( V_1 , V_130 , V_2 , 0 , - 1 , V_12 ) ;
V_115 = F_18 ( V_114 , V_131 ) ;
}
F_74 ( FALSE , V_2 , 0 , & V_7 , V_115 , - 1 ) ;
}
void F_75 ( void ) {
static T_27 V_132 [] = {
{ & V_126 ,
{ L_18 , L_19 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_110 ,
{ L_20 , L_21 ,
V_133 , V_136 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_111 ,
{ L_22 , L_23 ,
V_133 , V_136 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_27 ,
{ L_24 , L_25 ,
V_137 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_28 ,
{ L_26 , L_27 ,
V_137 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_91 ,
{ L_28 , L_29 ,
V_137 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_88 ,
{ L_30 , L_31 ,
V_137 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_138 ,
{ L_32 , L_33 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_139 ,
{ L_34 , L_35 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_140 ,
{ L_36 , L_37 ,
V_133 , V_136 , F_76 ( V_141 ) , 0 ,
NULL , V_135 } } ,
{ & V_45 ,
{ L_38 , L_39 ,
V_133 , V_134 , NULL , 0 ,
L_40 , V_135 } } ,
{ & V_142 ,
{ L_41 , L_42 ,
V_143 , V_136 , F_76 ( V_144 ) , 0x80 ,
NULL , V_135 } } ,
{ & V_145 ,
{ L_43 , L_44 ,
V_143 , V_136 , F_76 ( V_146 ) , 0x40 ,
NULL , V_135 } } ,
{ & V_147 ,
{ L_45 , L_46 ,
V_143 , V_136 , NULL , 0x3F ,
NULL , V_135 } } ,
{ & V_148 ,
{ L_2 , L_47 ,
V_149 , V_150 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_151 ,
{ L_48 , L_49 ,
V_149 , V_150 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_152 ,
{ L_50 , L_51 ,
V_149 , V_150 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_153 ,
{ L_52 , L_53 ,
V_149 , V_150 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_154 ,
{ L_54 , L_55 ,
V_155 , V_150 , NULL , 0 ,
L_56 , V_135 } } ,
{ & V_43 ,
{ L_38 , L_39 ,
V_156 , V_134 , NULL , 0 ,
L_40 , V_135 } } ,
{ & V_38 ,
{ L_57 , L_58 ,
V_156 , V_136 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_157 ,
{ L_59 , L_60 ,
V_158 , V_150 , NULL , 0 ,
NULL , V_135 } } ,
#include "packet-h248-hfarr.c"
F_77 ( L_61 ,h248_arrel)
} ;
static T_22 * V_69 [] = {
& V_131 ,
& V_109 ,
& V_26 ,
& V_159 ,
& V_160 ,
& V_161 ,
& V_162 ,
& V_163 ,
F_78 ( V_164 ) ,
#include "packet-h248-ettarr.c"
} ;
static T_28 V_165 [] = {
{ & V_166 , { L_62 , V_167 , V_168 , L_63 , V_169 } } ,
{ & V_39 , { L_64 , V_170 , V_168 , L_65 , V_169 } } ,
{ & V_44 , { L_66 , V_170 , V_168 , L_67 , V_169 } } ,
} ;
T_29 * V_171 ;
T_30 * V_172 ;
V_130 = F_79 ( V_173 , V_174 , V_175 ) ;
F_80 ( L_61 , F_68 , V_130 ) ;
F_80 ( L_68 , F_66 , V_130 ) ;
F_81 ( V_130 , V_132 , F_82 ( V_132 ) ) ;
F_83 ( V_69 , F_82 ( V_69 ) ) ;
V_171 = F_84 ( V_130 ) ;
F_85 ( V_171 , V_165 , F_82 ( V_165 ) ) ;
V_127 = F_86 ( L_19 , L_69 , V_133 , V_134 ) ;
V_172 = F_87 ( V_130 , V_176 ) ;
F_88 ( V_172 , L_70 ,
L_71 ,
L_72 ,
& V_177 ) ;
F_89 ( V_172 , L_73 ,
L_74 ,
L_75 ,
10 ,
& V_178 ) ;
F_89 ( V_172 , L_76 ,
L_77 ,
L_75 ,
10 ,
& V_179 ) ;
F_88 ( V_172 , L_78 ,
L_79 ,
L_80 ,
& V_112 ) ;
V_180 = F_90 ( F_43 () , F_91 () ) ;
V_181 = F_90 ( F_43 () , F_91 () ) ;
V_182 = F_90 ( F_43 () , F_91 () ) ;
V_183 = F_90 ( F_43 () , F_91 () ) ;
V_184 = F_92 ( L_61 ) ;
F_93 () ;
}
void V_176 ( void ) {
static V_9 V_185 = FALSE ;
static T_14 V_186 ;
static T_14 V_187 ;
if ( ! V_185 ) {
V_113 = F_70 ( L_61 ) ;
V_188 = F_70 ( L_68 ) ;
F_94 ( L_81 , V_189 , V_113 ) ;
V_190 = F_70 ( L_82 ) ;
V_185 = TRUE ;
} else {
if ( V_186 != 0 )
F_95 ( L_83 , V_186 , V_113 ) ;
if ( V_187 != 0 )
F_95 ( L_84 , V_187 , V_188 ) ;
}
V_186 = V_178 ;
V_187 = V_179 ;
if ( V_186 != 0 ) {
F_94 ( L_83 , V_186 , V_113 ) ;
}
if ( V_187 != 0 ) {
F_94 ( L_84 , V_187 , V_188 ) ;
}
}
