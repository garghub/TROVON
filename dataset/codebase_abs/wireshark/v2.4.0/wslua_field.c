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
F_7 ( V_1 , ( V_18 ) ( F_12 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
F_7 ( V_1 , ( V_18 ) ( F_13 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
case V_23 :
case V_24 :
F_7 ( V_1 , ( V_18 ) ( F_14 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
case V_25 : {
F_15 ( V_1 , ( V_26 ) ( F_16 ( & ( V_3 -> V_5 -> V_12 ) ) ) ) ;
return 1 ;
}
case V_27 : {
F_17 ( V_1 , F_11 ( & ( V_3 -> V_5 -> V_12 ) ) ) ;
return 1 ;
}
case V_28 : {
T_5 V_29 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
F_18 ( NULL , V_29 , V_31 , V_3 -> V_5 -> V_8 , V_3 -> V_5 -> V_32 , V_3 -> V_5 -> V_9 ) ;
F_19 ( V_1 , V_29 ) ;
return 1 ;
}
case V_33 : {
T_5 V_34 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
F_18 ( NULL , V_34 , V_35 , V_3 -> V_5 -> V_8 , V_3 -> V_5 -> V_32 , V_3 -> V_5 -> V_9 ) ;
F_19 ( V_1 , V_34 ) ;
return 1 ;
}
case V_36 : {
T_5 V_37 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
F_18 ( NULL , V_37 , V_38 , V_3 -> V_5 -> V_8 , V_3 -> V_5 -> V_32 , V_3 -> V_5 -> V_9 ) ;
F_19 ( V_1 , V_37 ) ;
return 1 ;
}
case V_39 : {
T_5 V_40 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
F_18 ( NULL , V_40 , V_41 , V_3 -> V_5 -> V_8 , V_3 -> V_5 -> V_32 , V_3 -> V_5 -> V_9 ) ;
F_19 ( V_1 , V_40 ) ;
return 1 ;
}
case V_42 : {
T_5 V_43 = ( T_5 ) F_2 ( sizeof( V_30 ) ) ;
F_18 ( NULL , V_43 , V_44 , V_3 -> V_5 -> V_8 , V_3 -> V_5 -> V_32 , V_3 -> V_5 -> V_9 ) ;
F_19 ( V_1 , V_43 ) ;
return 1 ;
}
case V_45 :
case V_46 : {
T_6 V_47 = ( T_6 ) F_2 ( sizeof( V_48 ) ) ;
* V_47 = * ( T_6 ) F_20 ( & ( V_3 -> V_5 -> V_12 ) ) ;
F_21 ( V_1 , V_47 ) ;
return 1 ;
}
case V_49 :
case V_50 : {
T_7 * V_51 = F_22 ( NULL , & V_3 -> V_5 -> V_12 , V_52 , V_53 ) ;
if ( V_51 )
{
F_23 ( V_1 , V_51 ) ;
F_24 ( NULL , V_51 ) ;
}
else
{
F_25 ( V_1 , L_1 ) ;
}
return 1 ;
}
case V_54 :
if ( V_3 -> V_5 -> V_8 > 0 && V_3 -> V_5 -> V_55 ) {
F_23 ( V_1 , V_3 -> V_5 -> V_55 -> V_56 ) ;
return 1 ;
}
return 0 ;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
{
T_8 V_62 = F_26 () ;
F_27 ( V_62 , ( const V_63 * ) F_20 ( & V_3 -> V_5 -> V_12 ) ,
F_28 ( & V_3 -> V_5 -> V_12 ) ) ;
F_29 ( V_1 , V_62 ) ;
return 1 ;
}
case V_64 :
{
T_8 V_62 = F_26 () ;
T_9 * V_65 = ( T_9 * ) F_20 ( & V_3 -> V_5 -> V_12 ) ;
F_27 ( V_62 , ( const V_63 * ) F_30 ( F_31 () , V_65 , 0 ,
F_32 ( V_65 ) ) , F_32 ( V_65 ) ) ;
F_29 ( V_1 , V_62 ) ;
return 1 ;
}
case V_66 :
default:
F_25 ( V_1 , L_2 ) ;
return 1 ;
}
}
T_4 F_33 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( V_3 -> V_5 -> V_12 . V_67 -> V_68 ) {
T_7 * V_51 = NULL ;
if ( V_3 -> V_5 -> V_10 -> type == V_64 || V_3 -> V_5 -> V_10 -> type == V_69 ) {
V_51 = F_22 ( NULL , & V_3 -> V_5 -> V_12 , V_70 , V_53 ) ;
}
else {
V_51 = F_22 ( NULL , & V_3 -> V_5 -> V_12 , V_52 , V_3 -> V_5 -> V_10 -> V_71 ) ;
}
if ( V_51 ) {
F_23 ( V_1 , V_51 ) ;
F_24 ( NULL , V_51 ) ;
}
else {
F_23 ( V_1 , L_3 ) ;
}
}
else if ( V_3 -> V_5 -> V_10 -> type == V_54 ) {
F_23 ( V_1 , L_4 ) ;
}
else {
F_23 ( V_1 , L_5 ) ;
}
return 1 ;
}
static int F_34 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
T_7 V_72 [ V_73 + 1 ] ;
T_7 * V_74 ;
T_7 * V_75 ;
if ( ! V_3 -> V_5 -> V_55 ) {
V_74 = V_72 ;
F_35 ( V_3 -> V_5 , V_72 ) ;
} else
V_74 = V_3 -> V_5 -> V_55 -> V_56 ;
if ( ! V_74 ) return 0 ;
V_75 = strstr ( V_74 , L_6 ) ;
if ( ! V_75 ) {
F_23 ( V_1 , V_74 ) ;
} else {
V_75 += 2 ;
F_23 ( V_1 , V_75 ) ;
}
return 1 ;
}
static int F_36 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( V_3 -> V_5 -> V_10 ) {
F_7 ( V_1 , V_3 -> V_5 -> V_10 -> type ) ;
}
else {
F_37 ( V_1 ) ;
}
return 1 ;
}
static int F_38 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( V_3 -> V_5 -> V_32 ) {
F_39 ( V_1 , V_3 -> V_5 -> V_32 ) ;
}
else {
F_37 ( V_1 ) ;
}
return 1 ;
}
static int F_40 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
if ( F_41 ( V_1 , V_3 -> V_5 -> V_32 , V_3 -> V_5 -> V_9 , V_3 -> V_5 -> V_8 ) ) {
return 1 ;
}
return 0 ;
}
static int F_42 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_43 ( V_3 -> V_5 , V_76 ) ) ;
return 1 ;
}
static int F_44 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_43 ( V_3 -> V_5 , V_77 ) ) ;
return 1 ;
}
static int F_45 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_43 ( V_3 -> V_5 , V_78 ) ) ;
return 1 ;
}
static int F_46 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_43 ( V_3 -> V_5 , V_79 ) ) ;
return 1 ;
}
static int F_47 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_10 ( V_1 , F_43 ( V_3 -> V_5 , V_80 ) ) ;
return 1 ;
}
static int F_48 ( T_2 * V_1 ) {
T_1 V_3 = F_6 ( V_1 , 1 ) ;
F_23 ( V_1 , V_3 -> V_5 -> V_10 -> V_81 ) ;
return 1 ;
}
T_4 F_49 ( T_2 * V_1 ) {
T_1 V_82 = F_6 ( V_1 , 1 ) ;
T_1 V_83 = F_6 ( V_1 , 2 ) ;
if ( V_82 -> V_5 -> V_32 == V_83 -> V_5 -> V_32 &&
V_82 -> V_5 -> V_9 == V_83 -> V_5 -> V_9 &&
V_83 -> V_5 -> V_8 == V_82 -> V_5 -> V_8 ) {
F_10 ( V_1 , 1 ) ;
} else {
F_10 ( V_1 , 0 ) ;
}
return 1 ;
}
T_4 F_50 ( T_2 * V_1 ) {
T_1 V_82 = F_6 ( V_1 , 1 ) ;
T_1 V_83 = F_6 ( V_1 , 2 ) ;
if ( V_82 -> V_5 -> V_32 != V_83 -> V_5 -> V_32 )
F_51 ( F_50 , L_7 ) ;
if ( V_83 -> V_5 -> V_9 + V_83 -> V_5 -> V_8 <= V_82 -> V_5 -> V_9 + V_82 -> V_5 -> V_8 ) {
F_10 ( V_1 , 1 ) ;
} else {
F_10 ( V_1 , 0 ) ;
}
return 1 ;
}
T_4 F_52 ( T_2 * V_1 ) {
T_1 V_82 = F_6 ( V_1 , 1 ) ;
T_1 V_83 = F_6 ( V_1 , 2 ) ;
if ( V_82 -> V_5 -> V_32 != V_83 -> V_5 -> V_32 ) {
F_51 ( F_52 , L_7 ) ;
return 0 ;
}
if ( V_83 -> V_5 -> V_9 + V_83 -> V_5 -> V_8 < V_82 -> V_5 -> V_9 ) {
F_10 ( V_1 , 1 ) ;
} else {
F_10 ( V_1 , 0 ) ;
}
return 1 ;
}
static int F_53 ( T_2 * V_1 ) {
T_1 V_3 = F_54 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_6 )
V_3 -> V_6 = TRUE ;
else
F_55 ( V_3 ) ;
return 0 ;
}
int F_56 ( T_2 * V_1 ) {
F_57 ( T_1 ) ;
F_58 ( T_1 ) ;
return 0 ;
}
T_10 F_59 ( T_2 * V_1 ) {
T_11 * V_84 ;
int V_85 = 0 ;
T_12 V_86 ;
if ( ! V_87 || ! V_87 -> V_88 ) {
F_51 ( F_59 , L_8 ) ;
return 0 ;
}
V_84 = F_60 ( V_87 -> V_88 ) ;
if ( V_84 ) {
for ( V_86 = 0 ; V_86 < V_84 -> V_89 ; V_86 ++ ) {
F_1 ( V_1 , ( T_3 * ) F_61 ( V_84 , V_86 ) ) ;
V_85 ++ ;
}
F_62 ( V_84 , TRUE ) ;
}
return V_85 ;
}
void F_63 ( T_13 * V_90 ) {
if ( V_91 && V_90 && V_90 -> V_88 ) {
F_64 ( V_91 , V_90 -> V_88 ) ;
}
}
T_14 F_65 ( void ) {
return ( V_91 && F_66 ( V_91 ) ) ;
}
void F_67 ( T_15 * V_88 V_92 ) {
T_16 * V_93 = F_68 ( L_9 ) ;
T_12 V_86 ;
T_7 * V_94 ;
for( V_86 = 0 ; V_86 < V_95 -> V_89 ; V_86 ++ ) {
T_17 V_2 = ( T_17 ) F_61 ( V_95 , V_86 ) ;
T_7 * V_96 = * ( ( T_7 * * ) V_2 ) ;
* V_2 = F_69 ( V_96 ) ;
if ( ! * V_2 ) {
F_70 ( L_10 , V_96 ) ;
* V_2 = NULL ;
F_55 ( V_96 ) ;
continue;
}
F_55 ( V_96 ) ;
F_71 ( V_93 , L_11 , ( * V_2 ) -> V_81 ) ;
V_97 = TRUE ;
}
F_62 ( V_95 , TRUE ) ;
V_95 = NULL ;
if ( V_97 && V_93 -> V_89 > strlen ( L_9 ) ) {
T_16 * error = F_72 ( L_9 ,
& V_97 ,
V_93 -> V_98 ,
0 ,
NULL , NULL , NULL ) ;
if ( error ) {
F_70 ( L_12 , error -> V_98 ) ;
F_73 ( error , TRUE ) ;
} else if ( ! F_74 ( V_93 -> V_98 , & V_91 , & V_94 ) ) {
F_70 ( L_13 , V_93 -> V_98 , V_94 ) ;
F_55 ( V_94 ) ;
}
}
F_73 ( V_93 , TRUE ) ;
}
T_18 F_75 ( T_2 * V_1 ) {
#define F_76 1
const T_7 * V_96 = F_77 ( V_1 , F_76 ) ;
T_17 V_2 ;
if ( ! F_69 ( V_96 ) && ! F_78 ( V_1 , V_96 ) ) {
F_79 ( F_75 , V_99 , L_14 ) ;
return 0 ;
}
if ( ! V_95 ) {
F_51 ( F_75 , L_15 ) ;
return 0 ;
}
V_2 = ( T_17 ) F_2 ( sizeof( void * ) ) ;
* V_2 = ( V_100 * ) ( void * ) F_80 ( V_96 ) ;
F_3 ( V_95 , V_2 ) ;
F_81 ( V_1 , V_2 ) ;
F_82 ( 1 ) ;
}
T_18 F_83 ( T_2 * V_1 ) {
void * V_101 , * V_102 ;
int V_86 = - 1 ;
int V_103 = 0 ;
V_100 * V_10 = NULL ;
F_84 ( V_1 ) ;
for ( V_86 = F_85 ( & V_101 ) ; V_86 != - 1 ;
V_86 = F_86 ( & V_101 ) ) {
for ( V_10 = F_87 ( V_86 , & V_102 ) ; V_10 != NULL ;
V_10 = F_88 ( V_86 , & V_102 ) ) {
if ( V_10 -> V_104 != - 1 )
continue;
V_103 ++ ;
F_23 ( V_1 , V_10 -> V_81 ) ;
F_89 ( V_1 , 1 , V_103 ) ;
}
}
F_82 ( 1 ) ;
}
static int F_90 ( T_2 * V_1 ) {
T_17 V_3 = F_91 ( V_1 , 1 ) ;
V_100 * V_10 = NULL ;
F_92 ( F_23 , V_81 ) ;
return 1 ;
}
static int F_93 ( T_2 * V_1 ) {
T_17 V_3 = F_91 ( V_1 , 1 ) ;
V_100 * V_10 = NULL ;
F_92 ( F_23 , V_96 ) ;
return 1 ;
}
static int F_94 ( T_2 * V_1 ) {
T_17 V_3 = F_91 ( V_1 , 1 ) ;
V_100 * V_10 = NULL ;
F_92 ( F_7 , type ) ;
return 1 ;
}
T_4 F_95 ( T_2 * V_1 ) {
T_17 V_2 = F_91 ( V_1 , 1 ) ;
V_100 * V_105 = * V_2 ;
int V_85 = 0 ;
if ( ! V_105 ) {
F_25 ( V_1 , L_16 ) ;
return 0 ;
}
if ( ! V_106 ) {
F_51 ( F_95 , L_17 ) ;
return 0 ;
}
while ( V_105 ) {
T_11 * V_84 = F_96 ( V_87 -> V_88 , V_105 -> V_107 ) ;
T_12 V_86 ;
if ( V_84 ) {
for ( V_86 = 0 ; V_86 < V_84 -> V_89 ; V_86 ++ ) {
F_1 ( V_1 , ( T_3 * ) F_61 ( V_84 , V_86 ) ) ;
V_85 ++ ;
}
}
V_105 = ( V_105 -> V_104 != - 1 ) ? F_97 ( V_105 -> V_104 ) : NULL ;
}
F_82 ( V_85 ) ;
}
T_4 F_98 ( T_2 * V_1 ) {
T_17 V_2 = F_91 ( V_1 , 1 ) ;
if ( V_95 ) {
F_23 ( V_1 , * ( ( T_7 * * ) V_2 ) ) ;
} else {
F_23 ( V_1 , ( * V_2 ) -> V_81 ) ;
}
return 1 ;
}
static int F_99 ( T_2 * V_1 V_92 ) {
return 0 ;
}
int F_100 ( T_2 * V_1 ) {
V_95 = F_101 () ;
F_102 ( T_17 ) ;
F_58 ( T_17 ) ;
V_7 = F_101 () ;
return 0 ;
}
int F_103 ( T_2 * V_1 V_92 ) {
if ( V_91 ) {
F_104 ( V_91 ) ;
V_91 = NULL ;
}
if ( V_97 ) {
F_105 ( & V_97 ) ;
V_97 = FALSE ;
}
return 0 ;
}
