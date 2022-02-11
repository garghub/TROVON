T_1 F_1 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_3 ( V_1 , V_2 -> V_3 -> V_4 ) ;
return 1 ;
}
T_1 F_4 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_3 ( V_1 , V_2 -> V_3 -> V_5 ) ;
return 1 ;
}
T_1 F_5 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
switch( V_2 -> V_3 -> V_6 -> type ) {
case V_7 :
F_6 ( V_1 , ( int ) F_7 ( & ( V_2 -> V_3 -> V_8 ) ) ) ;
return 1 ;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
F_3 ( V_1 , ( V_14 ) ( F_7 ( & ( V_2 -> V_3 -> V_8 ) ) ) ) ;
return 1 ;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
F_3 ( V_1 , ( V_14 ) ( F_8 ( & ( V_2 -> V_3 -> V_8 ) ) ) ) ;
return 1 ;
case V_19 :
case V_20 :
F_3 ( V_1 , ( V_14 ) ( F_9 ( & ( V_2 -> V_3 -> V_8 ) ) ) ) ;
return 1 ;
case V_21 : {
F_10 ( V_1 , ( V_22 ) ( F_11 ( & ( V_2 -> V_3 -> V_8 ) ) ) ) ;
return 1 ;
}
case V_23 : {
F_12 ( V_1 , F_11 ( & ( V_2 -> V_3 -> V_8 ) ) ) ;
return 1 ;
}
case V_24 : {
T_4 V_25 = ( T_4 ) F_13 ( sizeof( V_26 ) ) ;
V_25 -> type = V_27 ;
V_25 -> V_28 = V_2 -> V_3 -> V_4 ;
V_25 -> V_29 = F_14 ( NULL , V_2 -> V_3 -> V_30 , V_2 -> V_3 -> V_5 , V_2 -> V_3 -> V_4 ) ;
F_15 ( V_1 , V_25 ) ;
return 1 ;
}
case V_31 : {
T_4 V_32 = ( T_4 ) F_13 ( sizeof( V_26 ) ) ;
V_32 -> type = V_33 ;
V_32 -> V_28 = V_2 -> V_3 -> V_4 ;
V_32 -> V_29 = F_14 ( NULL , V_2 -> V_3 -> V_30 , V_2 -> V_3 -> V_5 , V_2 -> V_3 -> V_4 ) ;
F_15 ( V_1 , V_32 ) ;
return 1 ;
}
case V_34 : {
T_4 V_35 = ( T_4 ) F_13 ( sizeof( V_26 ) ) ;
V_35 -> type = V_36 ;
V_35 -> V_28 = V_2 -> V_3 -> V_4 ;
V_35 -> V_29 = F_14 ( NULL , V_2 -> V_3 -> V_30 , V_2 -> V_3 -> V_5 , V_2 -> V_3 -> V_4 ) ;
F_15 ( V_1 , V_35 ) ;
return 1 ;
}
case V_37 : {
T_4 V_38 = ( T_4 ) F_13 ( sizeof( V_26 ) ) ;
V_38 -> type = V_39 ;
V_38 -> V_28 = V_2 -> V_3 -> V_4 ;
V_38 -> V_29 = F_14 ( NULL , V_2 -> V_3 -> V_30 , V_2 -> V_3 -> V_5 , V_2 -> V_3 -> V_4 ) ;
F_15 ( V_1 , V_38 ) ;
return 1 ;
}
case V_40 :
case V_41 : {
T_5 V_42 = ( T_5 ) F_13 ( sizeof( V_43 ) ) ;
* V_42 = * ( T_5 ) F_16 ( & ( V_2 -> V_3 -> V_8 ) ) ;
F_17 ( V_1 , V_42 ) ;
return 1 ;
}
case V_44 :
case V_45 : {
T_6 * V_46 = F_18 ( & V_2 -> V_3 -> V_8 , V_47 , NULL ) ;
if ( V_46 )
F_19 ( V_1 , V_46 ) ;
else
F_20 ( V_1 , L_1 ) ;
return 1 ;
}
case V_48 :
if ( V_2 -> V_3 -> V_4 == 0 ) {
F_21 ( V_1 ) ;
return 1 ;
}
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
{
T_7 V_55 = F_22 () ;
F_23 ( V_55 , ( const V_56 * ) F_16 ( & V_2 -> V_3 -> V_8 ) ,
F_24 ( & V_2 -> V_3 -> V_8 ) ) ;
F_25 ( V_1 , V_55 ) ;
return 1 ;
}
case V_57 :
default:
F_20 ( V_1 , L_2 ) ;
return 1 ;
}
}
T_1 F_26 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
if ( V_2 -> V_3 -> V_8 . V_58 -> V_59 ) {
T_6 * V_46 = F_18 ( & V_2 -> V_3 -> V_8 , V_47 , NULL ) ;
if ( V_46 ) {
F_19 ( V_1 , V_46 ) ;
}
else {
F_19 ( V_1 , L_3 ) ;
}
}
else if ( V_2 -> V_3 -> V_6 -> type == V_48 ) {
F_19 ( V_1 , L_4 ) ;
}
else {
F_19 ( V_1 , L_5 ) ;
}
return 1 ;
}
static int F_27 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
T_6 V_60 [ V_61 + 1 ] ;
T_6 * V_62 ;
T_6 * V_63 ;
if ( ! V_2 -> V_3 -> V_64 ) {
V_62 = V_60 ;
F_28 ( V_2 -> V_3 , V_60 ) ;
} else
V_62 = V_2 -> V_3 -> V_64 -> V_65 ;
if ( ! V_62 ) return 0 ;
V_63 = strstr ( V_62 , L_6 ) ;
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
if ( F_30 ( V_1 , V_2 -> V_3 -> V_30 , V_2 -> V_3 -> V_5 , V_2 -> V_3 -> V_4 ) ) {
return 1 ;
}
return 0 ;
}
static int F_31 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_6 ( V_1 , F_32 ( V_2 -> V_3 , V_66 ) ) ;
return 1 ;
}
static int F_33 ( T_2 * V_1 ) {
T_3 V_2 = F_2 ( V_1 , 1 ) ;
F_19 ( V_1 , V_2 -> V_3 -> V_6 -> V_67 ) ;
return 1 ;
}
T_1 F_34 ( T_2 * V_1 ) {
T_3 V_68 = F_2 ( V_1 , 1 ) ;
T_3 V_69 = F_2 ( V_1 , 2 ) ;
if ( V_68 -> V_3 -> V_30 != V_69 -> V_3 -> V_30 ) {
F_35 ( F_34 , L_7 ) ;
return 0 ;
}
if ( V_68 -> V_3 -> V_5 <= V_69 -> V_3 -> V_5 && V_69 -> V_3 -> V_5 + V_69 -> V_3 -> V_4 <= V_68 -> V_3 -> V_5 + V_69 -> V_3 -> V_4 ) {
F_6 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_36 ( T_2 * V_1 ) {
T_3 V_68 = F_2 ( V_1 , 1 ) ;
T_3 V_69 = F_2 ( V_1 , 2 ) ;
if ( V_68 -> V_3 -> V_30 != V_69 -> V_3 -> V_30 )
F_35 ( F_36 , L_7 ) ;
if ( V_69 -> V_3 -> V_5 + V_69 -> V_3 -> V_4 <= V_68 -> V_3 -> V_5 + V_69 -> V_3 -> V_4 ) {
F_6 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
T_1 F_37 ( T_2 * V_1 ) {
T_3 V_68 = F_2 ( V_1 , 1 ) ;
T_3 V_69 = F_2 ( V_1 , 2 ) ;
if ( V_68 -> V_3 -> V_30 != V_69 -> V_3 -> V_30 ) {
F_35 ( F_37 , L_7 ) ;
return 0 ;
}
if ( V_69 -> V_3 -> V_5 + V_69 -> V_3 -> V_4 < V_68 -> V_3 -> V_5 ) {
F_6 ( V_1 , 1 ) ;
return 1 ;
} else {
return 0 ;
}
}
static int F_38 ( T_2 * V_1 V_70 ) {
T_3 V_2 = F_39 ( V_1 , 1 ) ;
if ( ! V_2 ) return 0 ;
if ( ! V_2 -> V_71 )
V_2 -> V_71 = TRUE ;
else
F_40 ( V_2 ) ;
return 0 ;
}
int F_41 ( T_2 * V_1 ) {
F_42 ( T_3 ) ;
F_43 ( T_3 ) ;
return 0 ;
}
T_8 F_44 ( T_2 * V_1 ) {
T_9 * V_72 ;
int V_73 = 0 ;
T_10 V_74 ;
if ( ! V_75 || ! V_75 -> V_76 ) {
F_35 ( F_44 , L_8 ) ;
return 0 ;
}
V_72 = F_45 ( V_75 -> V_76 ) ;
if ( V_72 ) {
for ( V_74 = 0 ; V_74 < V_72 -> V_28 ; V_74 ++ ) {
T_3 V_2 = ( T_3 ) F_13 ( sizeof( struct V_77 ) ) ;
V_2 -> V_3 = ( V_78 * ) F_46 ( V_72 , V_74 ) ;
V_2 -> V_71 = FALSE ;
F_47 ( V_1 , V_2 ) ;
V_73 ++ ;
}
F_48 ( V_72 , TRUE ) ;
}
return V_73 ;
}
void F_49 ( T_11 * V_79 ) {
if ( V_80 && V_79 && V_79 -> V_76 ) {
F_50 ( V_80 , V_79 -> V_76 ) ;
}
}
void F_51 ( T_12 * V_76 V_70 ) {
T_13 * V_81 = F_52 ( L_9 ) ;
T_10 V_74 ;
static T_14 V_82 = FALSE ;
for( V_74 = 0 ; V_74 < V_83 -> V_28 ; V_74 ++ ) {
T_15 V_84 = ( T_15 ) F_46 ( V_83 , V_74 ) ;
T_6 * V_85 = * ( ( T_6 * * ) V_84 ) ;
* V_84 = F_53 ( V_85 ) ;
if ( ! * V_84 ) {
F_54 ( L_10 , V_85 ) ;
* V_84 = NULL ;
F_40 ( V_85 ) ;
continue;
}
F_40 ( V_85 ) ;
F_55 ( V_81 , L_11 , ( * V_84 ) -> V_67 ) ;
V_82 = TRUE ;
}
F_48 ( V_83 , TRUE ) ;
V_83 = NULL ;
if ( V_82 ) {
T_13 * error = F_56 ( L_9 ,
& V_82 ,
V_81 -> V_86 ,
0 ,
NULL , NULL , NULL ) ;
if ( error ) {
F_54 ( L_12 , error -> V_86 ) ;
F_57 ( error , TRUE ) ;
}
else if ( ! F_58 ( V_81 -> V_86 , & V_80 ) ) {
F_54 ( L_13 , V_81 -> V_86 ) ;
}
}
}
T_16 F_59 ( T_2 * V_1 ) {
#define F_60 1
const T_6 * V_85 = F_61 ( V_1 , F_60 ) ;
T_15 V_84 ;
if ( ! V_85 ) return 0 ;
if ( ! F_53 ( V_85 ) && ! F_62 ( V_1 , V_85 ) ) {
F_63 ( F_59 , V_87 , L_14 ) ;
return 0 ;
}
if ( ! V_83 ) {
F_35 ( F_59 , L_15 ) ;
return 0 ;
}
V_84 = ( T_15 ) F_13 ( sizeof( void * ) ) ;
* V_84 = ( V_88 * ) ( void * ) F_64 ( V_85 ) ;
F_65 ( V_83 , V_84 ) ;
F_66 ( V_1 , V_84 ) ;
F_67 ( 1 ) ;
}
T_16 F_68 ( T_2 * V_1 ) {
void * V_89 , * V_90 ;
int V_74 = - 1 ;
int V_91 = 0 ;
V_88 * V_6 = NULL ;
F_69 ( V_1 ) ;
for ( V_74 = F_70 ( & V_89 ) ; V_74 != - 1 ;
V_74 = F_71 ( & V_89 ) ) {
for ( V_6 = F_72 ( V_74 , & V_90 ) ; V_6 != NULL ;
V_6 = F_73 ( V_74 , & V_90 ) ) {
if ( V_6 -> V_92 != - 1 )
continue;
V_91 ++ ;
F_19 ( V_1 , V_6 -> V_67 ) ;
F_74 ( V_1 , 1 , V_91 ) ;
}
}
F_67 ( 1 ) ;
}
T_1 F_75 ( T_2 * V_1 ) {
T_15 V_84 = F_76 ( V_1 , 1 ) ;
V_88 * V_93 = * V_84 ;
int V_73 = 0 ;
if ( ! V_93 ) {
F_20 ( V_1 , L_16 ) ;
return 0 ;
}
if ( ! V_94 ) {
F_35 ( F_75 , L_17 ) ;
return 0 ;
}
while ( V_93 ) {
T_9 * V_72 = F_77 ( V_75 -> V_76 , V_93 -> V_95 ) ;
T_10 V_74 ;
if ( V_72 ) {
for ( V_74 = 0 ; V_74 < V_72 -> V_28 ; V_74 ++ ) {
T_3 V_2 = ( T_3 ) F_13 ( sizeof( struct V_77 ) ) ;
V_2 -> V_3 = ( V_78 * ) F_46 ( V_72 , V_74 ) ;
V_2 -> V_71 = FALSE ;
F_47 ( V_1 , V_2 ) ;
V_73 ++ ;
}
}
V_93 = ( V_93 -> V_92 != - 1 ) ? F_78 ( V_93 -> V_92 ) : NULL ;
}
F_67 ( V_73 ) ;
}
T_1 F_79 ( T_2 * V_1 ) {
T_15 V_84 = F_76 ( V_1 , 1 ) ;
if ( V_83 ) {
F_19 ( V_1 , * ( ( T_6 * * ) V_84 ) ) ;
} else {
F_19 ( V_1 , ( * V_84 ) -> V_67 ) ;
}
return 1 ;
}
static int F_80 ( T_2 * V_1 V_70 ) {
return 0 ;
}
int F_81 ( T_2 * V_1 ) {
V_83 = F_82 () ;
F_83 ( T_15 ) ;
V_96 = F_82 () ;
return 0 ;
}
