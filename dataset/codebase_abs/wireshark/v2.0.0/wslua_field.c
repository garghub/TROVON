T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 ) {
T_1 V_3 = ( T_1 ) F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_5 = V_2 ;
V_3 -> V_6 = FALSE ;
F_3 ( V_7 , V_3 ) ;
return F_4 ( V_1 , V_3 ) ;
}
T_4 F_5 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_7 ( V_1 , V_3 -> V_5 -> V_8 ) ;
return 1 ;
}
T_4 F_8 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_7 ( V_1 , V_3 -> V_5 -> V_9 ) ;
return 1 ;
}
T_4 F_9 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
switch( V_3 -> V_5 -> V_10 -> type ) {
case V_11 :
F_10 ( V_1 , ( int ) F_11 ( & ( V_3 -> V_5 -> V_12 ) ) ) ;
return 1 ;
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
F_7 ( V_1 , ( V_18 ) ( F_11 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_7 ( V_1 , ( V_18 ) ( F_12 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
case V_23 :
case V_24 :
F_7 ( V_1 , ( V_18 ) ( F_13 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
case V_25 : {
F_14 ( V_1 , ( V_26 ) ( F_15 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
}
case V_27 : {
F_16 ( V_1 , F_17 ( & ( V_3 -> V_5 -> V_12 ) ) ) ;
return 1 ;
}
case V_28 : {
T_5 V_29 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
V_29 -> type = V_31 ;
V_29 -> V_32 = V_3 -> V_5 -> V_8 ;
V_29 -> V_33 = F_18 ( NULL , V_3 -> V_5 -> V_34 , V_3 -> V_5 -> V_9 , V_3 -> V_5 -> V_8 ) ;
F_19 ( V_1 , V_29 ) ;
return 1 ;
}
case V_35 : {
T_5 V_36 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
V_36 -> type = V_37 ;
V_36 -> V_32 = V_3 -> V_5 -> V_8 ;
V_36 -> V_33 = F_18 ( NULL , V_3 -> V_5 -> V_34 , V_3 -> V_5 -> V_9 , V_3 -> V_5 -> V_8 ) ;
F_19 ( V_1 , V_36 ) ;
return 1 ;
}
case V_38 : {
T_5 V_39 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
V_39 -> type = V_40 ;
V_39 -> V_32 = V_3 -> V_5 -> V_8 ;
V_39 -> V_33 = F_18 ( NULL , V_3 -> V_5 -> V_34 , V_3 -> V_5 -> V_9 , V_3 -> V_5 -> V_8 ) ;
F_19 ( V_1 , V_39 ) ;
return 1 ;
}
case V_41 : {
T_5 V_42 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
V_42 -> type = V_43 ;
V_42 -> V_32 = V_3 -> V_5 -> V_8 ;
V_42 -> V_33 = F_18 ( NULL , V_3 -> V_5 -> V_34 , V_3 -> V_5 -> V_9 , V_3 -> V_5 -> V_8 ) ;
F_19 ( V_1 , V_42 ) ;
return 1 ;
}
case V_44 : {
T_5 V_45 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
V_45 -> type = V_46 ;
V_45 -> V_32 = V_3 -> V_5 -> V_8 ;
V_45 -> V_33 = F_18 ( NULL , V_3 -> V_5 -> V_34 , V_3 -> V_5 -> V_9 , V_3 -> V_5 -> V_8 ) ;
F_19 ( V_1 , V_45 ) ;
return 1 ;
}
case V_47 :
case V_48 : {
T_6 V_49 = ( T_6 ) F_2 ( sizeof( V_50 ) ) ;
* V_49 = * ( T_6 ) F_20 ( & ( V_3 -> V_5 -> V_12 ) ) ;
F_21 ( V_1 , V_49 ) ;
return 1 ;
}
case V_51 :
case V_52 : {
T_7 * V_53 = F_22 ( & V_3 -> V_5 -> V_12 , V_54 , V_55 , NULL ) ;
if ( V_53 )
F_23 ( V_1 , V_53 ) ;
else
F_24 ( V_1 , L_1 ) ;
return 1 ;
}
case V_56 :
if ( V_3 -> V_5 -> V_8 > 0 && V_3 -> V_5 -> V_57 ) {
F_23 ( V_1 , V_3 -> V_5 -> V_57 -> V_58 ) ;
return 1 ;
}
return 0 ;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
{
T_8 V_64 = F_25 () ;
F_26 ( V_64 , ( const V_65 * ) F_20 ( & V_3 -> V_5 -> V_12 ) ,
F_27 ( & V_3 -> V_5 -> V_12 ) ) ;
F_28 ( V_1 , V_64 ) ;
return 1 ;
}
case V_66 :
{
T_8 V_64 = F_25 () ;
T_9 * V_67 = ( T_9 * ) F_20 ( & V_3 -> V_5 -> V_12 ) ;
F_26 ( V_64 , ( const V_65 * ) F_18 ( F_29 () , V_67 , 0 ,
F_30 ( V_67 ) ) , F_30 ( V_67 ) ) ;
F_28 ( V_1 , V_64 ) ;
return 1 ;
}
case V_68 :
default:
F_24 ( V_1 , L_2 ) ;
return 1 ;
}
}
T_4 F_31 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( V_3 -> V_5 -> V_12 . V_69 -> V_70 ) {
T_7 * V_53 = NULL ;
if ( V_3 -> V_5 -> V_10 -> type == V_66 || V_3 -> V_5 -> V_10 -> type == V_71 ) {
V_53 = F_22 ( & V_3 -> V_5 -> V_12 , V_72 , V_55 , NULL ) ;
}
else {
V_53 = F_22 ( & V_3 -> V_5 -> V_12 , V_54 , V_3 -> V_5 -> V_10 -> V_73 , NULL ) ;
}
if ( V_53 ) {
F_23 ( V_1 , V_53 ) ;
F_32 ( V_53 ) ;
}
else {
F_23 ( V_1 , L_3 ) ;
}
}
else if ( V_3 -> V_5 -> V_10 -> type == V_56 ) {
F_23 ( V_1 , L_4 ) ;
}
else {
F_23 ( V_1 , L_5 ) ;
}
return 1 ;
}
static int F_33 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
T_7 V_74 [ V_75 + 1 ] ;
T_7 * V_76 ;
T_7 * V_77 ;
if ( ! V_3 -> V_5 -> V_57 ) {
V_76 = V_74 ;
F_34 ( V_3 -> V_5 , V_74 ) ;
} else
V_76 = V_3 -> V_5 -> V_57 -> V_58 ;
if ( ! V_76 ) return 0 ;
V_77 = strstr ( V_76 , L_6 ) ;
if ( ! V_77 ) {
F_23 ( V_1 , V_76 ) ;
} else {
V_77 += 2 ;
F_23 ( V_1 , V_77 ) ;
}
return 1 ;
}
static int F_35 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( V_3 -> V_5 -> V_10 ) {
F_7 ( V_1 , V_3 -> V_5 -> V_10 -> type ) ;
}
else {
F_36 ( V_1 ) ;
}
return 1 ;
}
static int F_37 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( V_3 -> V_5 -> V_34 ) {
F_38 ( V_1 , V_3 -> V_5 -> V_34 ) ;
}
else {
F_36 ( V_1 ) ;
}
return 1 ;
}
static int F_39 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( F_40 ( V_1 , V_3 -> V_5 -> V_34 , V_3 -> V_5 -> V_9 , V_3 -> V_5 -> V_8 ) ) {
return 1 ;
}
return 0 ;
}
static int F_41 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_42 ( V_3 -> V_5 , V_78 ) ) ;
return 1 ;
}
static int F_43 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_42 ( V_3 -> V_5 , V_79 ) ) ;
return 1 ;
}
static int F_44 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_42 ( V_3 -> V_5 , V_80 ) ) ;
return 1 ;
}
static int F_45 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_42 ( V_3 -> V_5 , V_81 ) ) ;
return 1 ;
}
static int F_46 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_42 ( V_3 -> V_5 , V_82 ) ) ;
return 1 ;
}
static int F_47 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_23 ( V_1 , V_3 -> V_5 -> V_10 -> V_83 ) ;
return 1 ;
}
T_4 F_48 ( T_2 * V_1 ) {
T_1 V_84 = F_6 ( V_1 , 1 ) ;
T_1 V_85 = F_6 ( V_1 , 2 ) ;
if ( V_84 -> V_5 -> V_34 == V_85 -> V_5 -> V_34 &&
V_84 -> V_5 -> V_9 == V_85 -> V_5 -> V_9 &&
V_85 -> V_5 -> V_8 == V_84 -> V_5 -> V_8 ) {
F_10 ( V_1 , 1 ) ;
} else {
F_10 ( V_1 , 0 ) ;
}
return 1 ;
}
T_4 F_49 ( T_2 * V_1 ) {
T_1 V_84 = F_6 ( V_1 , 1 ) ;
T_1 V_85 = F_6 ( V_1 , 2 ) ;
if ( V_84 -> V_5 -> V_34 != V_85 -> V_5 -> V_34 )
F_50 ( F_49 , L_7 ) ;
if ( V_85 -> V_5 -> V_9 + V_85 -> V_5 -> V_8 <= V_84 -> V_5 -> V_9 + V_84 -> V_5 -> V_8 ) {
F_10 ( V_1 , 1 ) ;
} else {
F_10 ( V_1 , 0 ) ;
}
return 1 ;
}
T_4 F_51 ( T_2 * V_1 ) {
T_1 V_84 = F_6 ( V_1 , 1 ) ;
T_1 V_85 = F_6 ( V_1 , 2 ) ;
if ( V_84 -> V_5 -> V_34 != V_85 -> V_5 -> V_34 ) {
F_50 ( F_51 , L_7 ) ;
return 0 ;
}
if ( V_85 -> V_5 -> V_9 + V_85 -> V_5 -> V_8 < V_84 -> V_5 -> V_9 ) {
F_10 ( V_1 , 1 ) ;
} else {
F_10 ( V_1 , 0 ) ;
}
return 1 ;
}
static int F_52 ( T_2 * V_1 V_86 ) {
T_1 V_3 = F_53 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_6 )
V_3 -> V_6 = TRUE ;
else
F_32 ( V_3 ) ;
return 0 ;
}
int F_54 ( T_2 * V_1 ) {
F_55 ( T_1 ) ;
F_56 ( T_1 ) ;
return 0 ;
}
T_10 F_57 ( T_2 * V_1 ) {
T_11 * V_87 ;
int V_88 = 0 ;
T_12 V_89 ;
if ( ! V_90 || ! V_90 -> V_91 ) {
F_50 ( F_57 , L_8 ) ;
return 0 ;
}
V_87 = F_58 ( V_90 -> V_91 ) ;
if ( V_87 ) {
for ( V_89 = 0 ; V_89 < V_87 -> V_32 ; V_89 ++ ) {
F_1 ( V_1 , ( T_3 * ) F_59 ( V_87 , V_89 ) ) ;
V_88 ++ ;
}
F_60 ( V_87 , TRUE ) ;
}
return V_88 ;
}
void F_61 ( T_13 * V_92 ) {
if ( V_93 && V_92 && V_92 -> V_91 ) {
F_62 ( V_93 , V_92 -> V_91 ) ;
}
}
void F_63 ( T_14 * V_91 V_86 ) {
T_15 * V_94 = F_64 ( L_9 ) ;
T_12 V_89 ;
static T_16 V_95 = FALSE ;
T_7 * V_96 ;
for( V_89 = 0 ; V_89 < V_97 -> V_32 ; V_89 ++ ) {
T_17 V_2 = ( T_17 ) F_59 ( V_97 , V_89 ) ;
T_7 * V_98 = * ( ( T_7 * * ) V_2 ) ;
* V_2 = F_65 ( V_98 ) ;
if ( ! * V_2 ) {
F_66 ( L_10 , V_98 ) ;
* V_2 = NULL ;
F_32 ( V_98 ) ;
continue;
}
F_32 ( V_98 ) ;
F_67 ( V_94 , L_11 , ( * V_2 ) -> V_83 ) ;
V_95 = TRUE ;
}
F_60 ( V_97 , TRUE ) ;
V_97 = NULL ;
if ( V_95 && V_94 -> V_32 > strlen ( L_9 ) ) {
T_15 * error = F_68 ( L_9 ,
& V_95 ,
V_94 -> V_99 ,
0 ,
NULL , NULL , NULL ) ;
if ( error ) {
F_66 ( L_12 , error -> V_99 ) ;
F_69 ( error , TRUE ) ;
} else {
if ( V_93 ) {
F_70 ( V_93 ) ;
V_93 = NULL ;
}
if ( ! F_71 ( V_94 -> V_99 , & V_93 , & V_96 ) ) {
F_66 ( L_13 , V_94 -> V_99 , V_96 ) ;
F_32 ( V_96 ) ;
}
}
} else if ( V_95 ) {
F_72 ( & V_95 ) ;
V_95 = FALSE ;
}
F_69 ( V_94 , TRUE ) ;
}
T_18 F_73 ( T_2 * V_1 ) {
#define F_74 1
const T_7 * V_98 = F_75 ( V_1 , F_74 ) ;
T_17 V_2 ;
if ( ! F_65 ( V_98 ) && ! F_76 ( V_1 , V_98 ) ) {
F_77 ( F_73 , V_100 , L_14 ) ;
return 0 ;
}
if ( ! V_97 ) {
F_50 ( F_73 , L_15 ) ;
return 0 ;
}
V_2 = ( T_17 ) F_2 ( sizeof( void * ) ) ;
* V_2 = ( V_101 * ) ( void * ) F_78 ( V_98 ) ;
F_3 ( V_97 , V_2 ) ;
F_79 ( V_1 , V_2 ) ;
F_80 ( 1 ) ;
}
T_18 F_81 ( T_2 * V_1 ) {
void * V_102 , * V_103 ;
int V_89 = - 1 ;
int V_104 = 0 ;
V_101 * V_10 = NULL ;
F_82 ( V_1 ) ;
for ( V_89 = F_83 ( & V_102 ) ; V_89 != - 1 ;
V_89 = F_84 ( & V_102 ) ) {
for ( V_10 = F_85 ( V_89 , & V_103 ) ; V_10 != NULL ;
V_10 = F_86 ( V_89 , & V_103 ) ) {
if ( V_10 -> V_105 != - 1 )
continue;
V_104 ++ ;
F_23 ( V_1 , V_10 -> V_83 ) ;
F_87 ( V_1 , 1 , V_104 ) ;
}
}
F_80 ( 1 ) ;
}
static int F_88 ( T_2 * V_1 ) {
T_17 V_3 = F_89 ( V_1 , 1 ) ;
V_101 * V_10 = NULL ;
F_90 ( F_23 , V_83 ) ;
return 1 ;
}
static int F_91 ( T_2 * V_1 ) {
T_17 V_3 = F_89 ( V_1 , 1 ) ;
V_101 * V_10 = NULL ;
F_90 ( F_23 , V_98 ) ;
return 1 ;
}
static int F_92 ( T_2 * V_1 ) {
T_17 V_3 = F_89 ( V_1 , 1 ) ;
V_101 * V_10 = NULL ;
F_90 ( F_7 , type ) ;
return 1 ;
}
T_4 F_93 ( T_2 * V_1 ) {
T_17 V_2 = F_89 ( V_1 , 1 ) ;
V_101 * V_106 = * V_2 ;
int V_88 = 0 ;
if ( ! V_106 ) {
F_24 ( V_1 , L_16 ) ;
return 0 ;
}
if ( ! V_107 ) {
F_50 ( F_93 , L_17 ) ;
return 0 ;
}
while ( V_106 ) {
T_11 * V_87 = F_94 ( V_90 -> V_91 , V_106 -> V_108 ) ;
T_12 V_89 ;
if ( V_87 ) {
for ( V_89 = 0 ; V_89 < V_87 -> V_32 ; V_89 ++ ) {
F_1 ( V_1 , ( T_3 * ) F_59 ( V_87 , V_89 ) ) ;
V_88 ++ ;
}
}
V_106 = ( V_106 -> V_105 != - 1 ) ? F_95 ( V_106 -> V_105 ) : NULL ;
}
F_80 ( V_88 ) ;
}
T_4 F_96 ( T_2 * V_1 ) {
T_17 V_2 = F_89 ( V_1 , 1 ) ;
if ( V_97 ) {
F_23 ( V_1 , * ( ( T_7 * * ) V_2 ) ) ;
} else {
F_23 ( V_1 , ( * V_2 ) -> V_83 ) ;
}
return 1 ;
}
static int F_97 ( T_2 * V_1 V_86 ) {
return 0 ;
}
int F_98 ( T_2 * V_1 ) {
V_97 = F_99 () ;
F_100 ( T_17 ) ;
F_56 ( T_17 ) ;
V_7 = F_99 () ;
return 0 ;
}
