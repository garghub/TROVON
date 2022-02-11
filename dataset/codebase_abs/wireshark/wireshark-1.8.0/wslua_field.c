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
T_4 V_22 = F_11 ( sizeof( V_23 ) ) ;
* V_22 = F_12 ( & ( V_2 -> V_8 ) ) ;
F_13 ( V_1 , V_22 ) ;
return 1 ;
}
case V_24 : {
T_5 V_22 = F_11 ( sizeof( V_25 ) ) ;
* V_22 = F_12 ( & ( V_2 -> V_8 ) ) ;
F_14 ( V_1 , V_22 ) ;
return 1 ;
}
case V_26 : {
T_6 V_27 = F_11 ( sizeof( V_28 ) ) ;
V_27 -> type = V_29 ;
V_27 -> V_30 = V_2 -> V_3 ;
V_27 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_27 ) ;
return 1 ;
}
case V_33 : {
T_6 V_34 = F_11 ( sizeof( V_28 ) ) ;
V_34 -> type = V_35 ;
V_34 -> V_30 = V_2 -> V_3 ;
V_34 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_34 ) ;
return 1 ;
}
case V_36 : {
T_6 V_37 = F_11 ( sizeof( V_28 ) ) ;
V_37 -> type = V_38 ;
V_37 -> V_30 = V_2 -> V_3 ;
V_37 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_37 ) ;
return 1 ;
}
case V_39 : {
T_6 V_40 = F_11 ( sizeof( V_28 ) ) ;
V_40 -> type = V_41 ;
V_40 -> V_30 = V_2 -> V_3 ;
V_40 -> V_31 = F_15 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) ;
F_16 ( V_1 , V_40 ) ;
return 1 ;
}
case V_42 :
case V_43 : {
T_7 V_44 = F_11 ( sizeof( V_45 ) ) ;
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
F_23 ( V_55 , F_24 ( V_2 -> V_32 , V_2 -> V_4 , V_2 -> V_3 ) , V_2 -> V_3 ) ;
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
if ( V_2 ) {
if ( V_2 -> V_8 . V_56 -> V_57 ) {
T_8 * V_48 = F_19 ( & V_2 -> V_8 , V_49 , NULL ) ;
if ( V_48 )
F_20 ( V_1 , V_48 ) ;
else
F_21 ( V_1 , L_1 ) ;
} else
F_21 ( V_1 , L_3 ) ;
}
return 1 ;
}
static int F_27 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
T_10 V_58 = F_28 ( sizeof( struct V_59 ) ) ;
V_58 -> V_60 = F_28 ( sizeof( struct V_61 ) ) ;
V_58 -> V_60 -> V_62 = V_2 -> V_32 ;
V_58 -> V_63 = V_2 -> V_4 ;
V_58 -> V_30 = V_2 -> V_3 ;
F_29 ( V_1 , V_58 ) ;
return 1 ;
}
static int F_30 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_7 ( V_1 , F_31 ( V_2 , V_64 ) ) ;
return 1 ;
}
static int F_32 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_20 ( V_1 , V_2 -> V_5 -> V_65 ) ;
return 1 ;
}
static int F_33 ( T_2 * V_1 ) {
const T_8 * V_66 = F_34 ( V_1 , 2 ) ;
const T_11 * V_58 ;
F_2 ( V_1 , 1 ) ;
for ( V_58 = V_67 ; V_58 -> V_68 ; V_58 ++ ) {
if ( F_35 ( V_58 -> V_68 , V_66 ) ) {
return V_58 -> V_69 ( V_1 ) ;
}
}
return 0 ;
}
T_1 F_36 ( T_2 * V_1 ) {
T_3 V_70 = F_2 ( V_1 , 1 ) ;
T_3 V_58 = F_2 ( V_1 , 2 ) ;
if ( V_70 -> V_32 != V_58 -> V_32 )
F_37 ( F_36 , L_4 ) ;
if ( V_70 -> V_4 <= V_58 -> V_4 && V_58 -> V_4 + V_58 -> V_3 <= V_70 -> V_4 + V_58 -> V_3 ) {
F_7 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_38 ( T_2 * V_1 ) {
T_3 V_70 = F_2 ( V_1 , 1 ) ;
T_3 V_58 = F_2 ( V_1 , 2 ) ;
if ( V_70 -> V_32 != V_58 -> V_32 )
return 0 ;
if ( V_58 -> V_4 + V_58 -> V_3 <= V_70 -> V_4 + V_58 -> V_3 ) {
F_7 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_39 ( T_2 * V_1 ) {
T_3 V_70 = F_2 ( V_1 , 1 ) ;
T_3 V_58 = F_2 ( V_1 , 2 ) ;
if ( V_70 -> V_32 != V_58 -> V_32 )
F_37 ( F_36 , L_4 ) ;
if ( V_58 -> V_4 + V_58 -> V_3 < V_70 -> V_4 ) {
F_7 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
int F_40 ( T_2 * V_1 ) {
F_41 ( T_3 ) ;
return 1 ;
}
T_12 F_42 ( T_2 * V_1 ) {
T_13 * V_71 ;
int V_72 = 0 ;
T_14 V_73 ;
if ( ! V_74 || ! V_74 -> V_75 ) {
F_37 ( F_42 , L_5 ) ;
}
V_71 = F_43 ( V_74 -> V_75 ) ;
if ( V_71 ) {
for ( V_73 = 0 ; V_73 < V_71 -> V_30 ; V_73 ++ ) {
F_44 ( V_1 , F_45 ( V_71 , V_73 ) ) ;
V_72 ++ ;
}
F_46 ( V_71 , TRUE ) ;
}
return V_72 ;
}
void F_47 ( T_15 * V_75 V_76 ) {
T_16 * V_77 = F_48 ( L_6 ) ;
T_14 V_73 ;
static T_17 V_78 = FALSE ;
for( V_73 = 0 ; V_73 < V_79 -> V_30 ; V_73 ++ ) {
T_18 V_80 = F_45 ( V_79 , V_73 ) ;
T_8 * V_68 = * ( ( T_8 * * ) V_80 ) ;
* V_80 = F_49 ( V_68 ) ;
if ( ! * V_80 ) {
F_50 ( L_7 , V_68 ) ;
* V_80 = NULL ;
F_51 ( V_68 ) ;
continue;
}
F_51 ( V_68 ) ;
F_52 ( V_77 , L_8 , ( * V_80 ) -> V_65 ) ;
V_78 = TRUE ;
}
F_46 ( V_79 , TRUE ) ;
V_79 = NULL ;
if ( V_78 ) {
T_16 * error = F_53 ( L_6 ,
& V_78 ,
V_77 -> V_81 ,
0 ,
NULL , NULL , NULL ) ;
if ( error ) {
F_50 ( L_9 , error -> V_81 ) ;
F_54 ( error , TRUE ) ;
}
}
}
T_19 F_55 ( T_2 * V_1 ) {
#define F_56 1
const T_8 * V_68 = F_34 ( V_1 , F_56 ) ;
T_18 V_80 ;
if ( ! V_68 ) return 0 ;
if ( ! F_49 ( V_68 ) )
F_57 ( F_55 , V_82 , L_10 ) ;
if ( ! V_79 )
F_37 ( V_83 , L_11 ) ;
V_80 = F_11 ( sizeof( void * ) ) ;
* V_80 = ( V_84 * ) F_58 ( V_68 ) ;
F_59 ( V_79 , V_80 ) ;
F_60 ( V_1 , V_80 ) ;
F_61 ( 1 ) ;
}
T_1 F_62 ( T_2 * V_1 ) {
T_18 V_80 = F_63 ( V_1 , 1 ) ;
V_84 * V_85 = * V_80 ;
int V_72 = 0 ;
if ( ! V_85 ) {
F_21 ( V_1 , L_12 ) ;
return 0 ;
}
if ( ! V_86 ) {
F_37 ( F_62 , L_13 ) ;
}
for (; V_85 ; V_85 = V_85 -> V_87 ) {
T_13 * V_71 = F_64 ( V_74 -> V_75 , V_85 -> V_88 ) ;
T_14 V_73 ;
if ( V_71 ) {
for ( V_73 = 0 ; V_73 < V_71 -> V_30 ; V_73 ++ ) {
F_44 ( V_1 , F_45 ( V_71 , V_73 ) ) ;
V_72 ++ ;
}
}
}
F_61 ( V_72 ) ;
}
T_1 F_65 ( T_2 * V_1 ) {
T_18 V_80 = F_63 ( V_1 , 1 ) ;
if ( ! ( V_80 && * V_80 ) ) {
F_21 ( V_1 , L_14 ) ;
return 0 ;
}
if ( V_79 ) {
F_20 ( V_1 , * ( ( T_8 * * ) V_80 ) ) ;
} else {
F_20 ( V_1 , ( * V_80 ) -> V_65 ) ;
}
return 1 ;
}
int F_66 ( T_2 * V_1 ) {
V_79 = F_67 () ;
F_68 ( T_18 ) ;
return 1 ;
}
