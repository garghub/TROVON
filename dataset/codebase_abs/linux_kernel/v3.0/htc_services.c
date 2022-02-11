void F_1 ( void * V_1 , struct V_2 * V_3 )
{
F_2 ( false ) ;
}
void F_3 ( void * V_1 , struct V_2 * V_3 )
{
F_2 ( V_3 -> V_4 == V_5 ) ;
if ( V_3 -> V_6 == V_7 ) {
F_4 ( (struct V_8 * ) V_1 , V_3 ) ;
return;
}
if ( V_3 -> V_9 > 0 ) {
F_5 ( V_10 ,
( L_1 ,
V_3 -> V_9 + ( V_11 ) V_12 ) ) ;
#ifdef F_6
F_7 ( V_3 -> V_13 - V_12 ,
V_3 -> V_9 + V_12 ,
L_2 ) ;
#endif
}
F_8 ( (struct V_8 * ) V_1 , V_3 , & ( (struct V_8 * ) V_1 ) -> V_14 [ 0 ] ) ;
}
int F_9 ( struct V_8 * V_15 )
{
struct V_2 * V_16 = NULL ;
int V_17 ;
do {
V_16 = F_10 ( V_15 ) ;
if ( NULL == V_16 ) {
V_17 = V_18 ;
break;
}
if ( V_15 -> V_19 >= V_20 ) {
T_1 * V_21 ;
V_11 V_22 = 0 ;
V_21 = ( T_1 * ) V_16 -> V_13 ;
F_11 ( V_21 , sizeof( T_1 ) ) ;
V_21 -> V_23 = V_24 ;
if ( V_15 -> V_25 > 0 ) {
V_22 |= V_26 ;
V_21 -> V_27 = V_15 -> V_25 ;
}
memcpy ( & V_21 -> V_28 , & V_22 , sizeof( V_21 -> V_28 ) ) ;
F_12 ( V_16 ,
NULL ,
( V_29 * ) V_21 ,
sizeof( T_1 ) ,
V_5 ,
V_30 ) ;
} else {
T_2 * V_31 ;
V_31 = ( T_2 * ) V_16 -> V_13 ;
F_11 ( V_31 , sizeof( T_2 ) ) ;
V_31 -> V_23 = V_32 ;
F_12 ( V_16 ,
NULL ,
( V_29 * ) V_31 ,
sizeof( T_2 ) ,
V_5 ,
V_30 ) ;
}
V_16 -> V_33 = NULL ;
F_13 ( V_16 , 0 , 0 , 0 ) ;
V_17 = F_14 ( V_15 , V_16 ) ;
} while ( false );
if ( V_16 != NULL ) {
F_15 ( V_15 , V_16 ) ;
}
return V_17 ;
}
int F_16 ( T_3 V_34 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_8 * V_15 = F_17 ( V_34 ) ;
int V_17 = 0 ;
struct V_2 * V_39 = NULL ;
struct V_2 * V_16 = NULL ;
T_4 * V_40 ;
T_5 * V_41 ;
T_6 V_42 = V_43 ;
struct V_44 * V_45 ;
unsigned int V_46 = 0 ;
F_5 ( V_47 , ( L_3 ,
( unsigned long ) V_15 , V_36 -> V_48 ) ) ;
do {
F_2 ( V_36 -> V_48 != 0 ) ;
if ( V_49 == V_36 -> V_48 ) {
V_42 = V_5 ;
V_46 = V_50 ;
} else {
V_16 = F_10 ( V_15 ) ;
if ( NULL == V_16 ) {
F_2 ( false ) ;
V_17 = V_18 ;
break;
}
V_41 = ( T_5 * ) V_16 -> V_13 ;
F_2 ( V_41 != NULL ) ;
F_11 ( V_41 , sizeof( T_5 ) ) ;
V_41 -> V_23 = V_51 ;
V_41 -> V_48 = V_36 -> V_48 ;
V_41 -> V_52 = V_36 -> V_52 ;
if ( ( V_36 -> V_53 != NULL ) &&
( V_36 -> V_54 <= V_55 ) ) {
memcpy ( ( V_29 * ) V_41 + sizeof( T_5 ) ,
V_36 -> V_53 ,
V_36 -> V_54 ) ;
V_41 -> V_56 = V_36 -> V_54 ;
}
F_12 ( V_16 ,
NULL ,
( V_29 * ) V_41 ,
sizeof( T_5 ) + V_41 -> V_56 ,
V_5 ,
V_30 ) ;
V_16 -> V_33 = NULL ;
F_13 ( V_16 , 0 , 0 , 0 ) ;
V_17 = F_14 ( V_15 , V_16 ) ;
if ( V_17 ) {
break;
}
V_17 = F_18 ( V_15 , & V_39 ) ;
if ( V_17 ) {
break;
}
V_40 = ( T_4 * ) V_39 -> V_13 ;
if ( ( V_40 -> V_23 != V_57 ) ||
( V_39 -> V_9 < sizeof( T_4 ) ) ) {
F_2 ( false ) ;
V_17 = V_58 ;
break;
}
V_38 -> V_59 = V_40 -> V_6 ;
if ( V_40 -> V_6 != V_60 ) {
F_5 ( V_10 ,
( L_4 ,
V_40 -> V_48 , V_40 -> V_6 ) ) ;
V_17 = V_58 ;
break;
}
V_42 = ( T_6 ) V_40 -> V_61 ;
V_46 = V_40 -> V_62 ;
if ( ( V_38 -> V_53 != NULL ) &&
( V_40 -> V_56 > 0 ) &&
( V_40 -> V_56 <= V_55 ) ) {
int V_63 = F_19 ( ( int ) V_38 -> V_64 , ( int ) V_40 -> V_56 ) ;
memcpy ( V_38 -> V_53 ,
( ( V_29 * ) V_40 ) + sizeof( T_4 ) ,
V_63 ) ;
V_38 -> V_9 = V_63 ;
}
}
V_17 = V_58 ;
if ( V_42 >= V_43 ) {
F_2 ( false ) ;
break;
}
if ( 0 == V_46 ) {
F_2 ( false ) ;
break;
}
V_45 = & V_15 -> V_14 [ V_42 ] ;
V_45 -> V_65 = V_42 ;
if ( V_45 -> V_48 != 0 ) {
F_2 ( false ) ;
break;
}
V_38 -> V_4 = V_42 ;
V_38 -> V_66 = V_46 ;
V_45 -> V_48 = V_36 -> V_48 ;
V_45 -> V_67 = V_36 -> V_68 ;
V_45 -> V_66 = V_46 ;
V_45 -> V_69 = V_36 -> V_70 ;
V_45 -> V_71 . V_48 = V_36 -> V_48 ;
V_45 -> V_71 . V_72 = V_45 ;
V_45 -> V_71 . V_4 = V_42 ;
V_45 -> V_71 . V_73 = V_15 -> V_74 ;
if ( V_36 -> V_75 != 0 ) {
if ( V_36 -> V_75 > V_46 ) {
F_2 ( false ) ;
break;
}
V_45 -> V_71 . V_76 = V_36 -> V_75 / V_15 -> V_74 ;
} else {
V_45 -> V_71 . V_76 = V_46 / V_15 -> V_74 ;
}
if ( 0 == V_45 -> V_71 . V_76 ) {
V_45 -> V_71 . V_76 = 1 ;
}
V_45 -> V_77 = V_36 -> V_77 ;
V_17 = 0 ;
} while ( false );
if ( V_16 != NULL ) {
F_15 ( V_15 , V_16 ) ;
}
if ( V_39 != NULL ) {
F_4 ( V_15 , V_39 ) ;
}
F_5 ( V_47 , ( L_5 ) ) ;
return V_17 ;
}
static void F_20 ( struct V_8 * V_15 , struct V_78 * V_79 )
{
struct V_78 * V_80 , * V_81 ;
if ( NULL == V_15 -> V_82 ) {
V_15 -> V_82 = V_79 ;
V_79 -> V_83 = NULL ;
V_79 -> V_84 = NULL ;
return;
}
V_80 = V_15 -> V_82 ;
while ( V_80 ) {
V_81 = V_80 ;
V_80 = V_80 -> V_83 ;
}
V_81 -> V_83 = V_79 ;
V_79 -> V_84 = V_81 ;
V_79 -> V_83 = NULL ;
}
static void F_21 ( void * V_1 ,
struct V_78 * V_85 ,
int V_86 )
{
struct V_78 * V_87 ;
int V_88 = 0 ;
int V_89 ;
V_87 = V_85 ;
while ( V_87 != NULL ) {
V_87 = V_87 -> V_83 ;
V_88 ++ ;
}
V_89 = V_86 / V_88 ;
V_87 = V_85 ;
while ( V_87 != NULL ) {
if ( V_89 < V_87 -> V_76 ) {
F_2 ( false ) ;
break;
}
V_87 -> V_90 = V_87 -> V_76 ;
V_87 -> V_91 = 0xFFFF ;
V_87 -> V_92 = V_89 ;
V_87 -> V_93 = V_89 ;
V_87 = V_87 -> V_83 ;
}
}
void F_22 ( void * V_1 ,
struct V_78 * V_94 ,
T_7 V_95 )
{
struct V_78 * V_87 ;
if ( V_95 == V_96 ) {
V_87 = V_94 ;
while ( V_87 != NULL ) {
if ( V_87 -> V_97 > 0 ) {
V_87 -> V_92 += V_87 -> V_97 ;
V_87 -> V_97 = 0 ;
}
V_87 = V_87 -> V_83 ;
}
}
}
void F_23 ( T_3 V_34 ,
void * V_98 ,
T_8 V_99 ,
T_9 V_100 ,
T_10 V_101 [] ,
int V_102 )
{
struct V_8 * V_15 = F_17 ( V_34 ) ;
int V_103 ;
int V_104 ;
if ( V_100 != NULL ) {
V_15 -> V_105 = V_100 ;
F_2 ( V_99 != NULL ) ;
V_15 -> V_106 = V_99 ;
V_15 -> V_107 = V_98 ;
} else {
F_2 ( V_99 == NULL ) ;
V_15 -> V_105 = F_21 ;
V_15 -> V_106 = F_22 ;
V_15 -> V_107 = V_15 ;
}
F_20 ( V_15 , & V_15 -> V_14 [ V_5 ] . V_71 ) ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
for ( V_104 = V_108 ; V_104 < V_43 ; V_104 ++ ) {
if ( V_15 -> V_14 [ V_104 ] . V_48 == V_101 [ V_103 ] ) {
F_20 ( V_15 , & V_15 -> V_14 [ V_104 ] . V_71 ) ;
break;
}
}
F_2 ( V_104 < V_43 ) ;
}
}
