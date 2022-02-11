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
F_6 ( V_1 ) ;
return 1 ;
case V_7 :
F_7 ( V_1 , ( int ) F_8 ( & ( V_2 -> V_8 ) ) ) ;
return 1 ;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
F_3 ( V_1 , ( V_14 ) F_8 ( & ( V_2 -> V_8 ) ) ) ;
return 1 ;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
F_3 ( V_1 , ( V_14 ) F_9 ( & ( V_2 -> V_8 ) ) ) ;
return 1 ;
case V_19 :
case V_20 :
F_3 ( V_1 , ( V_14 ) F_10 ( & ( V_2 -> V_8 ) ) ) ;
return 1 ;
case V_21 : {
T_4 V_22 = ( T_4 ) F_11 ( sizeof( V_23 ) ) ;
* V_22 = F_12 ( & ( V_2 -> V_8 ) ) ;
F_13 ( V_1 , V_22 ) ;
return 1 ;
}
case V_24 : {
T_5 V_22 = ( T_5 ) F_11 ( sizeof( V_25 ) ) ;
* V_22 = F_12 ( & ( V_2 -> V_8 ) ) ;
F_14 ( V_1 , V_22 ) ;
return 1 ;
}
case V_26 : {
T_6 V_27 = ( T_6 ) F_11 ( sizeof( V_28 ) ) ;
V_27 -> type = V_29 ;
V_27 -> V_30 = V_2 -> V_3 ;
V_27 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_27 ) ;
return 1 ;
}
case V_33 : {
T_6 V_34 = ( T_6 ) F_11 ( sizeof( V_28 ) ) ;
V_34 -> type = V_35 ;
V_34 -> V_30 = V_2 -> V_3 ;
V_34 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_34 ) ;
return 1 ;
}
case V_36 : {
T_6 V_37 = ( T_6 ) F_11 ( sizeof( V_28 ) ) ;
V_37 -> type = V_38 ;
V_37 -> V_30 = V_2 -> V_3 ;
V_37 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_37 ) ;
return 1 ;
}
case V_39 : {
T_6 V_40 = ( T_6 ) F_11 ( sizeof( V_28 ) ) ;
V_40 -> type = V_41 ;
V_40 -> V_30 = V_2 -> V_3 ;
V_40 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_40 ) ;
return 1 ;
}
case V_42 :
case V_43 : {
T_7 V_44 = ( T_7 ) F_11 ( sizeof( V_45 ) ) ;
* V_44 = * ( T_7 ) F_17 ( & ( V_2 -> V_8 ) ) ;
F_18 ( V_1 , V_44 ) ;
return 1 ;
}
case V_46 :
case V_47 : {
T_8 * V_48 = F_19 ( & V_2 -> V_8 , V_49 , NULL ) ;
if ( V_48 )
F_20 ( V_1 , V_48 ) ;
else
F_21 ( V_1 , L_1 ) ;
return 1 ;
}
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 : {
T_9 V_55 = F_22 () ;
F_23 ( V_55 , ( const V_56 * ) F_24 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) , V_2 -> V_3 ) ;
F_25 ( V_1 , V_55 ) ;
return 1 ;
}
default:
F_21 ( V_1 , L_2 ) ;
return 1 ;
}
}
T_1 F_26 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
if ( ! V_2 ) {
return F_21 ( V_1 , L_3 ) ;
}
if ( V_2 -> V_8 . V_57 -> V_58 ) {
T_8 * V_48 = F_19 ( & V_2 -> V_8 , V_49 , NULL ) ;
if ( V_48 ) {
F_20 ( V_1 , V_48 ) ;
}
else {
F_20 ( V_1 , L_4 ) ;
}
}
else if ( V_2 -> V_5 -> type == V_6 ) {
F_20 ( V_1 , L_5 ) ;
}
else {
F_20 ( V_1 , L_6 ) ;
}
return 1 ;
}
static int F_27 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
T_8 V_59 [ V_60 + 1 ] ;
T_8 * V_61 ;
T_8 * V_62 ;
if ( ! V_2 ) return 0 ;
if ( ! V_2 -> V_63 ) {
V_61 = V_59 ;
F_28 ( V_2 , V_59 ) ;
} else
V_61 = V_2 -> V_63 -> V_64 ;
if ( ! V_61 ) return 0 ;
V_62 = strstr ( V_61 , L_7 ) ;
if ( ! V_62 ) {
F_20 ( V_1 , V_61 ) ;
} else {
V_62 += 2 ;
F_20 ( V_1 , V_62 ) ;
}
return 1 ;
}
static int F_29 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
T_10 V_65 = F_30 ( struct V_66 ) ;
V_65 -> V_67 = F_30 ( struct V_68 ) ;
V_65 -> V_67 -> V_69 = V_2 -> V_32 ;
V_65 -> V_70 = V_2 -> V_4 ;
V_65 -> V_30 = V_2 -> V_3 ;
F_31 ( V_1 , V_65 ) ;
return 1 ;
}
static int F_32 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_7 ( V_1 , F_33 ( V_2 , V_71 ) ) ;
return 1 ;
}
static int F_34 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_20 ( V_1 , V_2 -> V_5 -> V_72 ) ;
return 1 ;
}
static int F_35 ( T_2 * V_1 ) {
const T_8 * V_73 = F_36 ( V_1 , 2 ) ;
const T_11 * V_65 ;
F_2 ( V_1 , 1 ) ;
for ( V_65 = V_74 ; V_65 -> V_75 ; V_65 ++ ) {
if ( F_37 ( V_65 -> V_75 , V_73 ) ) {
return V_65 -> V_76 ( V_1 ) ;
}
}
return 0 ;
}
T_1 F_38 ( T_2 * V_1 ) {
T_3 V_77 = F_2 ( V_1 , 1 ) ;
T_3 V_65 = F_2 ( V_1 , 2 ) ;
if ( V_77 -> V_32 != V_65 -> V_32 )
F_39 ( F_38 , L_8 ) ;
if ( V_77 -> V_4 <= V_65 -> V_4 && V_65 -> V_4 + V_65 -> V_3 <= V_77 -> V_4 + V_65 -> V_3 ) {
F_7 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_40 ( T_2 * V_1 ) {
T_3 V_77 = F_2 ( V_1 , 1 ) ;
T_3 V_65 = F_2 ( V_1 , 2 ) ;
if ( V_77 -> V_32 != V_65 -> V_32 )
return 0 ;
if ( V_65 -> V_4 + V_65 -> V_3 <= V_77 -> V_4 + V_65 -> V_3 ) {
F_7 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_41 ( T_2 * V_1 ) {
T_3 V_77 = F_2 ( V_1 , 1 ) ;
T_3 V_65 = F_2 ( V_1 , 2 ) ;
if ( V_77 -> V_32 != V_65 -> V_32 )
F_39 ( F_38 , L_8 ) ;
if ( V_65 -> V_4 + V_65 -> V_3 < V_77 -> V_4 ) {
F_7 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
static int F_42 ( T_2 * V_1 V_78 ) {
return 0 ;
}
int F_43 ( T_2 * V_1 ) {
F_44 ( T_3 ) ;
return 1 ;
}
T_12 F_45 ( T_2 * V_1 ) {
T_13 * V_79 ;
int V_80 = 0 ;
T_14 V_81 ;
if ( ! V_82 || ! V_82 -> V_83 ) {
F_39 ( F_45 , L_9 ) ;
}
V_79 = F_46 ( V_82 -> V_83 ) ;
if ( V_79 ) {
for ( V_81 = 0 ; V_81 < V_79 -> V_30 ; V_81 ++ ) {
F_47 ( V_1 , ( T_3 ) F_48 ( V_79 , V_81 ) ) ;
V_80 ++ ;
}
F_49 ( V_79 , TRUE ) ;
}
return V_80 ;
}
void F_50 ( T_15 * V_84 ) {
if ( V_85 && V_84 && V_84 -> V_83 ) {
F_51 ( V_85 , V_84 -> V_83 ) ;
}
}
void F_52 ( T_16 * V_83 V_78 ) {
T_17 * V_86 = F_53 ( L_10 ) ;
T_14 V_81 ;
static T_18 V_87 = FALSE ;
for( V_81 = 0 ; V_81 < V_88 -> V_30 ; V_81 ++ ) {
T_19 V_89 = ( T_19 ) F_48 ( V_88 , V_81 ) ;
T_8 * V_75 = * ( ( T_8 * * ) V_89 ) ;
* V_89 = F_54 ( V_75 ) ;
if ( ! * V_89 ) {
F_55 ( L_11 , V_75 ) ;
* V_89 = NULL ;
F_56 ( V_75 ) ;
continue;
}
F_56 ( V_75 ) ;
F_57 ( V_86 , L_12 , ( * V_89 ) -> V_72 ) ;
V_87 = TRUE ;
}
F_49 ( V_88 , TRUE ) ;
V_88 = NULL ;
if ( V_87 ) {
T_17 * error = F_58 ( L_10 ,
& V_87 ,
V_86 -> V_90 ,
0 ,
NULL , NULL , NULL ) ;
if ( error ) {
F_55 ( L_13 , error -> V_90 ) ;
F_59 ( error , TRUE ) ;
}
else if ( ! F_60 ( V_86 -> V_90 , & V_85 ) ) {
F_55 ( L_14 , V_86 -> V_90 ) ;
}
}
}
T_20 F_61 ( T_2 * V_1 ) {
#define F_62 1
const T_8 * V_75 = F_36 ( V_1 , F_62 ) ;
T_19 V_89 ;
if ( ! V_75 ) return 0 ;
if ( ! F_54 ( V_75 ) )
F_63 ( F_61 , V_91 , L_15 ) ;
if ( ! V_88 )
F_39 ( V_92 , L_16 ) ;
V_89 = ( T_19 ) F_11 ( sizeof( void * ) ) ;
* V_89 = ( V_93 * ) F_64 ( V_75 ) ;
F_65 ( V_88 , V_89 ) ;
F_66 ( V_1 , V_89 ) ;
F_67 ( 1 ) ;
}
T_1 F_68 ( T_2 * V_1 ) {
T_19 V_89 = F_69 ( V_1 , 1 ) ;
V_93 * V_94 = * V_89 ;
int V_80 = 0 ;
if ( ! V_94 ) {
F_21 ( V_1 , L_17 ) ;
return 0 ;
}
if ( ! V_95 ) {
F_39 ( F_68 , L_18 ) ;
}
for (; V_94 ; V_94 = V_94 -> V_96 ) {
T_13 * V_79 = F_70 ( V_82 -> V_83 , V_94 -> V_97 ) ;
T_14 V_81 ;
if ( V_79 ) {
for ( V_81 = 0 ; V_81 < V_79 -> V_30 ; V_81 ++ ) {
F_47 ( V_1 , ( T_3 ) F_48 ( V_79 , V_81 ) ) ;
V_80 ++ ;
}
}
}
F_67 ( V_80 ) ;
}
T_1 F_71 ( T_2 * V_1 ) {
T_19 V_89 = F_69 ( V_1 , 1 ) ;
if ( ! ( V_89 && * V_89 ) ) {
F_21 ( V_1 , L_19 ) ;
return 0 ;
}
if ( V_88 ) {
F_20 ( V_1 , * ( ( T_8 * * ) V_89 ) ) ;
} else {
F_20 ( V_1 , ( * V_89 ) -> V_72 ) ;
}
return 1 ;
}
static int F_72 ( T_2 * V_1 V_78 ) {
return 0 ;
}
int F_73 ( T_2 * V_1 ) {
V_88 = F_74 () ;
F_75 ( T_19 ) ;
return 1 ;
}
