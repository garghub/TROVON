T_1 F_1 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_3 ( V_1 , V_2 -> V_3 ) ;
return 1 ;
}
T_1 F_4 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_3 ( V_1 , V_2 -> V_4 ) ;
return 1 ;
}
T_1 F_5 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
switch( V_2 -> V_5 -> type ) {
case V_6 :
F_6 ( V_1 , ( int ) F_7 ( & ( V_2 -> V_7 ) ) ) ;
return 1 ;
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
F_3 ( V_1 , ( V_13 ) F_7 ( & ( V_2 -> V_7 ) ) ) ;
return 1 ;
case V_14 :
case V_15 :
case V_16 :
case V_17 :
F_3 ( V_1 , ( V_13 ) F_8 ( & ( V_2 -> V_7 ) ) ) ;
return 1 ;
case V_18 :
case V_19 :
F_3 ( V_1 , ( V_13 ) F_9 ( & ( V_2 -> V_7 ) ) ) ;
return 1 ;
case V_20 : {
T_4 V_21 = ( T_4 ) F_10 ( sizeof( V_22 ) ) ;
* V_21 = F_11 ( & ( V_2 -> V_7 ) ) ;
F_12 ( V_1 , V_21 ) ;
return 1 ;
}
case V_23 : {
T_5 V_21 = ( T_5 ) F_10 ( sizeof( V_24 ) ) ;
* V_21 = F_11 ( & ( V_2 -> V_7 ) ) ;
F_13 ( V_1 , V_21 ) ;
return 1 ;
}
case V_25 : {
T_6 V_26 = ( T_6 ) F_10 ( sizeof( V_27 ) ) ;
V_26 -> type = V_28 ;
V_26 -> V_29 = V_2 -> V_3 ;
V_26 -> V_30 = F_14 ( NULL , V_2 -> V_31 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_15 ( V_1 , V_26 ) ;
return 1 ;
}
case V_32 : {
T_6 V_33 = ( T_6 ) F_10 ( sizeof( V_27 ) ) ;
V_33 -> type = V_34 ;
V_33 -> V_29 = V_2 -> V_3 ;
V_33 -> V_30 = F_14 ( NULL , V_2 -> V_31 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_15 ( V_1 , V_33 ) ;
return 1 ;
}
case V_35 : {
T_6 V_36 = ( T_6 ) F_10 ( sizeof( V_27 ) ) ;
V_36 -> type = V_37 ;
V_36 -> V_29 = V_2 -> V_3 ;
V_36 -> V_30 = F_14 ( NULL , V_2 -> V_31 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_15 ( V_1 , V_36 ) ;
return 1 ;
}
case V_38 : {
T_6 V_39 = ( T_6 ) F_10 ( sizeof( V_27 ) ) ;
V_39 -> type = V_40 ;
V_39 -> V_29 = V_2 -> V_3 ;
V_39 -> V_30 = F_14 ( NULL , V_2 -> V_31 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_15 ( V_1 , V_39 ) ;
return 1 ;
}
case V_41 :
case V_42 : {
T_7 V_43 = ( T_7 ) F_10 ( sizeof( V_44 ) ) ;
* V_43 = * ( T_7 ) F_16 ( & ( V_2 -> V_7 ) ) ;
F_17 ( V_1 , V_43 ) ;
return 1 ;
}
case V_45 :
case V_46 : {
T_8 * V_47 = F_18 ( & V_2 -> V_7 , V_48 , NULL ) ;
if ( V_47 )
F_19 ( V_1 , V_47 ) ;
else
F_20 ( V_1 , L_1 ) ;
return 1 ;
}
case V_49 :
if ( V_2 -> V_3 == 0 ) {
F_21 ( V_1 ) ;
return 1 ;
}
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 : {
T_9 V_56 = F_22 () ;
F_23 ( V_56 , ( const V_57 * ) F_14 ( F_24 () , V_2 -> V_31 , V_2 -> V_4 , V_2 -> V_3 ) , V_2 -> V_3 ) ;
F_25 ( V_1 , V_56 ) ;
return 1 ;
}
default:
F_20 ( V_1 , L_2 ) ;
return 1 ;
}
}
T_1 F_26 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
if ( ! V_2 ) {
return F_20 ( V_1 , L_3 ) ;
}
if ( V_2 -> V_7 . V_58 -> V_59 ) {
T_8 * V_47 = F_18 ( & V_2 -> V_7 , V_48 , NULL ) ;
if ( V_47 ) {
F_19 ( V_1 , V_47 ) ;
}
else {
F_19 ( V_1 , L_4 ) ;
}
}
else if ( V_2 -> V_5 -> type == V_49 ) {
F_19 ( V_1 , L_5 ) ;
}
else {
F_19 ( V_1 , L_6 ) ;
}
return 1 ;
}
static int F_27 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
T_8 V_60 [ V_61 + 1 ] ;
T_8 * V_62 ;
T_8 * V_63 ;
if ( ! V_2 ) return 0 ;
if ( ! V_2 -> V_64 ) {
V_62 = V_60 ;
F_28 ( V_2 , V_60 ) ;
} else
V_62 = V_2 -> V_64 -> V_65 ;
if ( ! V_62 ) return 0 ;
V_63 = strstr ( V_62 , L_7 ) ;
if ( ! V_63 ) {
F_19 ( V_1 , V_62 ) ;
} else {
V_63 += 2 ;
F_19 ( V_1 , V_63 ) ;
}
return 1 ;
}
static int F_29 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
T_10 V_66 = F_30 ( struct V_67 ) ;
V_66 -> V_68 = F_30 ( struct V_69 ) ;
V_66 -> V_68 -> V_70 = V_2 -> V_31 ;
V_66 -> V_68 -> V_71 = FALSE ;
V_66 -> V_68 -> V_72 = FALSE ;
V_66 -> V_73 = V_2 -> V_4 ;
V_66 -> V_29 = V_2 -> V_3 ;
F_31 ( V_1 , V_66 ) ;
return 1 ;
}
static int F_32 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_6 ( V_1 , F_33 ( V_2 , V_74 ) ) ;
return 1 ;
}
static int F_34 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_19 ( V_1 , V_2 -> V_5 -> V_75 ) ;
return 1 ;
}
static int F_35 ( T_2 * V_1 ) {
const T_8 * V_76 = F_36 ( V_1 , 2 ) ;
const T_11 * V_66 ;
F_2 ( V_1 , 1 ) ;
for ( V_66 = V_77 ; V_66 -> V_78 ; V_66 ++ ) {
if ( F_37 ( V_66 -> V_78 , V_76 ) ) {
return V_66 -> V_79 ( V_1 ) ;
}
}
return 0 ;
}
T_1 F_38 ( T_2 * V_1 ) {
T_3 V_80 = F_2 ( V_1 , 1 ) ;
T_3 V_66 = F_2 ( V_1 , 2 ) ;
if ( V_80 -> V_31 != V_66 -> V_31 )
F_39 ( F_38 , L_8 ) ;
if ( V_80 -> V_4 <= V_66 -> V_4 && V_66 -> V_4 + V_66 -> V_3 <= V_80 -> V_4 + V_66 -> V_3 ) {
F_6 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_40 ( T_2 * V_1 ) {
T_3 V_80 = F_2 ( V_1 , 1 ) ;
T_3 V_66 = F_2 ( V_1 , 2 ) ;
if ( V_80 -> V_31 != V_66 -> V_31 )
F_39 ( F_40 , L_8 ) ;
if ( V_66 -> V_4 + V_66 -> V_3 <= V_80 -> V_4 + V_66 -> V_3 ) {
F_6 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_41 ( T_2 * V_1 ) {
T_3 V_80 = F_2 ( V_1 , 1 ) ;
T_3 V_66 = F_2 ( V_1 , 2 ) ;
if ( V_80 -> V_31 != V_66 -> V_31 )
F_39 ( F_41 , L_8 ) ;
if ( V_66 -> V_4 + V_66 -> V_3 < V_80 -> V_4 ) {
F_6 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
static int F_42 ( T_2 * V_1 V_81 ) {
return 0 ;
}
int F_43 ( T_2 * V_1 ) {
F_44 ( T_3 ) ;
return 1 ;
}
T_12 F_45 ( T_2 * V_1 ) {
T_13 * V_82 ;
int V_83 = 0 ;
T_14 V_84 ;
if ( ! V_85 || ! V_85 -> V_86 ) {
F_39 ( F_45 , L_9 ) ;
}
V_82 = F_46 ( V_85 -> V_86 ) ;
if ( V_82 ) {
for ( V_84 = 0 ; V_84 < V_82 -> V_29 ; V_84 ++ ) {
F_47 ( V_1 , ( T_3 ) F_48 ( V_82 , V_84 ) ) ;
V_83 ++ ;
}
F_49 ( V_82 , TRUE ) ;
}
return V_83 ;
}
void F_50 ( T_15 * V_87 ) {
if ( V_88 && V_87 && V_87 -> V_86 ) {
F_51 ( V_88 , V_87 -> V_86 ) ;
}
}
void F_52 ( T_16 * V_86 V_81 ) {
T_17 * V_89 = F_53 ( L_10 ) ;
T_14 V_84 ;
static T_18 V_90 = FALSE ;
for( V_84 = 0 ; V_84 < V_91 -> V_29 ; V_84 ++ ) {
T_19 V_92 = ( T_19 ) F_48 ( V_91 , V_84 ) ;
T_8 * V_78 = * ( ( T_8 * * ) V_92 ) ;
* V_92 = F_54 ( V_78 ) ;
if ( ! * V_92 ) {
F_55 ( L_11 , V_78 ) ;
* V_92 = NULL ;
F_56 ( V_78 ) ;
continue;
}
F_56 ( V_78 ) ;
F_57 ( V_89 , L_12 , ( * V_92 ) -> V_75 ) ;
V_90 = TRUE ;
}
F_49 ( V_91 , TRUE ) ;
V_91 = NULL ;
if ( V_90 ) {
T_17 * error = F_58 ( L_10 ,
& V_90 ,
V_89 -> V_93 ,
0 ,
NULL , NULL , NULL ) ;
if ( error ) {
F_55 ( L_13 , error -> V_93 ) ;
F_59 ( error , TRUE ) ;
}
else if ( ! F_60 ( V_89 -> V_93 , & V_88 ) ) {
F_55 ( L_14 , V_89 -> V_93 ) ;
}
}
}
T_20 F_61 ( T_2 * V_1 ) {
#define F_62 1
const T_8 * V_78 = F_36 ( V_1 , F_62 ) ;
T_19 V_92 ;
if ( ! V_78 ) return 0 ;
if ( ! F_54 ( V_78 ) )
F_63 ( F_61 , V_94 , L_15 ) ;
if ( ! V_91 )
F_39 ( F_61 , L_16 ) ;
V_92 = ( T_19 ) F_10 ( sizeof( void * ) ) ;
* V_92 = ( V_95 * ) F_64 ( V_78 ) ;
F_65 ( V_91 , V_92 ) ;
F_66 ( V_1 , V_92 ) ;
F_67 ( 1 ) ;
}
T_1 F_68 ( T_2 * V_1 ) {
T_19 V_92 = F_69 ( V_1 , 1 ) ;
V_95 * V_96 = * V_92 ;
int V_83 = 0 ;
if ( ! V_96 ) {
F_20 ( V_1 , L_17 ) ;
return 0 ;
}
if ( ! V_97 ) {
F_39 ( F_68 , L_18 ) ;
}
while ( V_96 ) {
T_13 * V_82 = F_70 ( V_85 -> V_86 , V_96 -> V_98 ) ;
T_14 V_84 ;
if ( V_82 ) {
for ( V_84 = 0 ; V_84 < V_82 -> V_29 ; V_84 ++ ) {
F_47 ( V_1 , ( T_3 ) F_48 ( V_82 , V_84 ) ) ;
V_83 ++ ;
}
}
V_96 = ( V_96 -> V_99 != - 1 ) ? F_71 ( V_96 -> V_99 ) : NULL ;
}
F_67 ( V_83 ) ;
}
T_1 F_72 ( T_2 * V_1 ) {
T_19 V_92 = F_69 ( V_1 , 1 ) ;
if ( ! ( V_92 && * V_92 ) ) {
F_20 ( V_1 , L_19 ) ;
return 0 ;
}
if ( V_91 ) {
F_19 ( V_1 , * ( ( T_8 * * ) V_92 ) ) ;
} else {
F_19 ( V_1 , ( * V_92 ) -> V_75 ) ;
}
return 1 ;
}
static int F_73 ( T_2 * V_1 V_81 ) {
return 0 ;
}
int F_74 ( T_2 * V_1 ) {
V_91 = F_75 () ;
F_76 ( T_19 ) ;
return 1 ;
}
