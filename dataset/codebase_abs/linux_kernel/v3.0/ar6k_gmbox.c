static void F_1 ( void * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 ;
F_2 ( V_6 , ( L_1 , ( unsigned long ) V_5 ) ) ;
if ( V_3 -> V_7 ) {
F_2 ( V_8 ,
( L_2 , V_3 -> V_9 . V_10 . V_11 , V_3 -> V_7 ) ) ;
}
F_3 ( V_5 , V_3 ) ;
F_2 ( V_6 , ( L_3 ) ) ;
}
static int F_4 ( struct V_4 * V_5 , T_1 V_12 , bool V_13 )
{
int V_14 = 0 ;
struct V_15 V_16 ;
struct V_2 * V_17 = NULL ;
F_5 ( V_5 ) ;
if ( V_18 == V_12 ) {
V_5 -> V_19 . V_20 = true ;
V_5 -> V_21 . V_22 |=
F_6 ( 1 << V_23 ) ;
V_5 -> V_21 . V_24 |= F_7 ( 0x01 ) ;
} else {
V_5 -> V_19 . V_20 = false ;
V_5 -> V_21 . V_22 &=
~ ( F_6 ( 1 << V_23 ) ) ;
}
memcpy ( & V_16 , & V_5 -> V_21 , V_25 ) ;
F_8 ( V_5 ) ;
do {
if ( V_13 ) {
V_17 = F_9 ( V_5 ) ;
if ( NULL == V_17 ) {
V_14 = V_26 ;
F_10 ( false ) ;
break;
}
memcpy ( V_17 -> V_27 , & V_5 -> V_21 , V_25 ) ;
V_17 -> V_28 = F_1 ;
V_17 -> V_29 = V_5 ;
V_17 -> V_9 . V_10 . V_11 = V_12 ;
F_11 ( V_5 -> V_30 ,
V_31 ,
V_17 -> V_27 ,
V_25 ,
V_32 ,
V_17 ) ;
V_17 = NULL ;
break;
}
V_14 = F_11 ( V_5 -> V_30 ,
V_31 ,
& V_16 . V_24 ,
V_25 ,
V_33 ,
NULL ) ;
} while ( false );
if ( V_14 ) {
F_2 ( V_8 ,
( L_4 , V_12 , V_14 ) ) ;
} else {
if ( ! V_13 ) {
F_2 ( V_6 ,
( L_5 , V_12 ) ) ;
}
}
if ( V_17 != NULL ) {
F_3 ( V_5 , V_17 ) ;
}
return V_14 ;
}
int F_12 ( struct V_4 * V_5 , T_1 V_12 , bool V_13 )
{
int V_14 = 0 ;
struct V_2 * V_17 = NULL ;
T_2 V_34 [ 4 ] ;
if ( V_18 == V_12 ) {
return F_4 ( V_5 , V_18 , V_13 ) ;
} else if( V_35 == V_12 ) {
return F_4 ( V_5 , V_35 , V_13 ) ;
}
if ( V_36 == V_12 ) {
F_4 ( V_5 , V_35 , V_13 ) ;
}
F_5 ( V_5 ) ;
switch ( V_12 ) {
case V_36 :
V_5 -> V_37 . V_24 = 0 ;
break;
case V_38 :
V_5 -> V_37 . V_24 |= V_39 |
V_40 ;
break;
case V_41 :
V_5 -> V_37 . V_24 |= V_42 ;
break;
case V_43 :
V_5 -> V_37 . V_24 &= ~ V_42 ;
break;
case V_44 :
default:
F_10 ( false ) ;
break;
}
V_34 [ 0 ] = V_5 -> V_37 . V_24 ;
V_34 [ 1 ] = V_34 [ 0 ] ;
V_34 [ 2 ] = V_34 [ 0 ] ;
V_34 [ 3 ] = V_34 [ 0 ] ;
F_8 ( V_5 ) ;
do {
if ( V_13 ) {
V_17 = F_9 ( V_5 ) ;
if ( NULL == V_17 ) {
V_14 = V_26 ;
F_10 ( false ) ;
break;
}
memcpy ( V_17 -> V_27 , V_34 , sizeof( V_34 ) ) ;
V_17 -> V_28 = F_1 ;
V_17 -> V_29 = V_5 ;
V_17 -> V_9 . V_10 . V_11 = V_12 ;
F_11 ( V_5 -> V_30 ,
V_45 ,
V_17 -> V_27 ,
sizeof( V_34 ) ,
V_46 ,
V_17 ) ;
V_17 = NULL ;
break;
}
V_14 = F_11 ( V_5 -> V_30 ,
V_45 ,
V_34 ,
sizeof( V_34 ) ,
V_47 ,
NULL ) ;
} while ( false );
if ( V_14 ) {
F_2 ( V_8 ,
( L_4 , V_12 , V_14 ) ) ;
} else {
if ( ! V_13 ) {
F_2 ( V_6 ,
( L_5 , V_12 ) ) ;
}
}
if ( V_17 != NULL ) {
F_3 ( V_5 , V_17 ) ;
}
return V_14 ;
}
void F_13 ( struct V_4 * V_5 )
{
if ( V_5 -> V_48 ) {
V_5 -> V_48 = false ;
F_14 ( V_5 ) ;
}
}
int F_15 ( struct V_4 * V_5 )
{
int V_14 = 0 ;
T_2 V_49 [ 4 ] ;
do {
if ( 0 == V_5 -> V_50 . V_51 ) {
break;
}
F_2 ( V_52 , ( L_6 ,
V_5 -> V_50 . V_51 , V_5 -> V_50 . V_53 ) ) ;
V_14 = F_12 ( V_5 , V_36 , V_54 ) ;
if ( V_14 ) {
break;
}
V_49 [ 0 ] = V_55 ;
V_49 [ 1 ] = V_55 ;
V_49 [ 2 ] = V_55 ;
V_49 [ 3 ] = V_55 ;
V_14 = F_11 ( V_5 -> V_30 ,
V_56 ,
V_49 ,
sizeof( V_49 ) ,
V_47 ,
NULL ) ;
if ( V_14 ) {
break;
}
V_14 = F_16 ( V_5 ) ;
if ( V_14 ) {
break;
}
V_5 -> V_48 = true ;
} while ( false );
return V_14 ;
}
int F_17 ( struct V_4 * V_5 )
{
int V_14 = 0 ;
T_2 V_57 ;
int V_58 ;
T_2 V_59 ;
F_2 ( V_6 , ( L_7 ) ) ;
do {
V_59 = V_5 -> V_60 . V_59 &
V_5 -> V_37 . V_24 ;
if ( V_59 & V_39 ) {
F_2 ( V_8 , ( L_8 ) ) ;
V_14 = V_61 ;
}
if ( V_59 & V_40 ) {
F_2 ( V_8 , ( L_9 ) ) ;
V_14 = V_61 ;
}
if ( V_14 ) {
if ( V_5 -> V_19 . V_62 != NULL ) {
V_5 -> V_19 . V_62 ( V_5 -> V_19 . V_63 , V_14 ) ;
}
break;
}
if ( V_59 & V_42 ) {
if ( V_5 -> V_60 . V_64 > 0 ) {
F_10 ( V_5 -> V_19 . V_65 != NULL ) ;
V_14 = V_5 -> V_19 . V_65 (
V_5 -> V_19 . V_63 ,
( T_2 * ) & V_5 -> V_60 . V_66 [ 0 ] ,
V_5 -> V_60 . V_64 ) ;
}
}
if ( V_14 ) {
break;
}
V_57 = V_5 -> V_60 . V_57 &
V_5 -> V_21 . V_22 ;
if ( V_57 & ( F_6 ( 1 << V_23 ) ) ) {
V_14 = F_18 ( V_5 , V_54 , & V_58 ) ;
if ( V_14 ) {
break;
}
F_10 ( V_5 -> V_19 . V_67 != NULL ) ;
V_14 = V_5 -> V_19 . V_67 ( V_5 -> V_19 . V_63 ,
V_58 ,
V_5 -> V_19 . V_20 ) ;
}
} while ( false );
F_2 ( V_6 , ( L_10 , V_14 ) ) ;
return V_14 ;
}
int F_19 ( struct V_4 * V_5 , struct V_2 * V_3 , T_3 V_68 )
{
T_3 V_69 ;
bool V_70 = ( V_3 -> V_28 == NULL ) ? true : false ;
int V_14 ;
T_3 V_71 ;
V_69 = F_20 ( V_5 , V_68 ) ;
F_2 ( V_72 ,
( L_11 ,
V_68 ,
V_5 -> V_50 . V_51 ,
V_70 ? L_12 : L_13 ) ) ;
V_71 = V_5 -> V_50 . V_51 + V_5 -> V_50 . V_53 - V_69 ;
V_14 = F_11 ( V_5 -> V_30 ,
V_71 ,
V_3 -> V_27 ,
V_69 ,
V_70 ? V_73 : V_74 ,
V_70 ? NULL : V_3 ) ;
if ( V_70 ) {
V_3 -> V_7 = V_14 ;
} else {
if ( V_14 == V_75 ) {
V_14 = 0 ;
}
}
return V_14 ;
}
int F_21 ( struct V_4 * V_5 , struct V_2 * V_3 , T_3 V_76 )
{
T_3 V_69 ;
int V_14 ;
bool V_70 = ( V_3 -> V_28 == NULL ) ? true : false ;
V_69 = F_22 ( V_5 , V_76 ) ;
if ( V_69 > V_3 -> V_77 ) {
F_10 ( false ) ;
F_2 ( V_8 ,
( L_14 ,
V_69 , V_76 , V_3 -> V_77 ) ) ;
if ( V_3 -> V_28 != NULL ) {
F_23 ( V_3 , V_78 ) ;
return 0 ;
}
return V_78 ;
}
F_2 ( V_79 ,
( L_15 ,
( unsigned long ) V_3 , V_3 -> V_9 . V_10 . V_80 ,
V_69 ,
V_5 -> V_50 . V_51 ,
V_70 ? L_12 : L_13 ) ) ;
V_14 = F_11 ( V_5 -> V_30 ,
V_5 -> V_50 . V_51 ,
V_3 -> V_27 ,
V_69 ,
V_70 ? V_81 : V_82 ,
V_70 ? NULL : V_3 ) ;
if ( V_70 ) {
V_3 -> V_7 = V_14 ;
}
return V_14 ;
}
static int F_24 ( T_2 * V_27 , int V_83 )
{
int V_58 = 0 ;
if ( F_25 ( V_79 ) ) {
F_26 ( V_27 , V_83 , L_16 ) ;
}
while ( V_83 ) {
if ( * V_27 != 0 ) {
V_58 ++ ;
}
V_83 -- ;
V_27 ++ ;
}
return V_58 ;
}
static void F_27 ( void * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_1 ;
F_2 ( V_6 , ( L_17 , ( unsigned long ) V_5 ) ) ;
if ( V_3 -> V_7 ) {
F_2 ( V_8 ,
( L_18 , V_3 -> V_7 ) ) ;
} else {
int V_58 = 0 ;
V_58 = F_24 ( V_3 -> V_27 , V_84 ) ;
V_5 -> V_19 . V_67 ( V_5 -> V_19 . V_63 ,
V_58 ,
V_5 -> V_19 . V_20 ) ;
}
F_3 ( V_5 , V_3 ) ;
F_2 ( V_6 , ( L_19 ) ) ;
}
int F_18 ( struct V_4 * V_5 , bool V_13 , int * V_85 )
{
int V_14 = 0 ;
struct V_2 * V_17 = NULL ;
F_2 ( V_72 , ( L_20 , V_13 ? L_13 : L_12 ) ) ;
do {
V_17 = F_9 ( V_5 ) ;
if ( NULL == V_17 ) {
V_14 = V_26 ;
F_10 ( false ) ;
break;
}
F_28 ( V_17 -> V_27 , V_84 ) ;
if ( V_13 ) {
V_17 -> V_28 = F_27 ;
V_17 -> V_29 = V_5 ;
F_11 ( V_5 -> V_30 ,
V_86 ,
V_17 -> V_27 ,
V_84 ,
V_87 ,
V_17 ) ;
V_17 = NULL ;
break;
}
V_17 -> V_28 = NULL ;
V_14 = F_11 ( V_5 -> V_30 ,
V_86 ,
V_17 -> V_27 ,
V_84 ,
V_88 ,
NULL ) ;
} while ( false );
if ( V_14 ) {
F_2 ( V_8 ,
( L_21 , V_14 ) ) ;
}
if ( V_17 != NULL ) {
if ( ! V_14 ) {
* V_85 = F_24 ( V_17 -> V_27 , V_84 ) ;
}
F_3 ( V_5 , V_17 ) ;
}
F_2 ( V_72 , ( L_22 ,
V_13 ? L_13 : L_12 , V_14 ) ) ;
return V_14 ;
}
int F_29 ( struct V_4 * V_5 , int * V_89 )
{
int V_14 ;
T_2 V_90 [ 4 ] ;
V_14 = F_11 ( V_5 -> V_30 ,
V_91 ,
V_90 ,
sizeof( V_90 ) ,
V_88 ,
NULL ) ;
if ( ! V_14 ) {
if ( V_90 [ 0 ] == 0 ) {
* V_89 = 256 ;
} else {
* V_89 = V_90 [ 0 ] ;
}
}
return V_14 ;
}
void F_30 ( struct V_4 * V_5 )
{
if ( V_5 -> V_19 . V_62 != NULL ) {
V_5 -> V_19 . V_62 ( V_5 -> V_19 . V_63 , V_92 ) ;
}
}
int F_31 ( struct V_4 * V_5 , T_2 * V_93 , int * V_94 )
{
int V_14 = 0 ;
struct V_95 V_96 ;
int V_97 ;
do {
if ( * V_94 > sizeof( V_96 . V_66 ) ) {
F_10 ( false ) ;
V_14 = V_78 ;
break;
}
V_97 = * V_94 ;
* V_94 = 0 ;
V_14 = F_11 ( V_5 -> V_30 ,
V_98 ,
( T_2 * ) & V_96 ,
V_99 ,
V_100 ,
NULL ) ;
if ( V_14 ) {
F_2 ( V_8 ,
( L_23 , V_14 ) ) ;
break;
}
if ( V_96 . V_64 > 0 ) {
int V_101 = V_96 . V_64 > V_97 ? V_97 : V_96 . V_64 ;
memcpy ( V_93 , & V_96 . V_66 [ 0 ] , V_101 ) ;
* V_94 = V_101 ;
}
} while ( false );
return V_14 ;
}
int F_32 ( struct V_4 * V_5 , int Signal , int V_102 )
{
int V_14 = 0 ;
int V_103 ;
T_2 V_90 [ 4 ] ;
F_28 ( V_90 , sizeof( V_90 ) ) ;
do {
if ( Signal >= V_104 ) {
V_14 = V_78 ;
break;
}
V_90 [ 3 ] = ( 1 << Signal ) ;
V_14 = F_11 ( V_5 -> V_30 ,
V_105 ,
V_90 ,
sizeof( V_90 ) ,
V_47 ,
NULL ) ;
if ( V_14 ) {
break;
}
} while ( false );
if ( ! V_14 ) {
while ( V_102 ) {
V_14 = F_11 ( V_5 -> V_30 ,
V_105 ,
V_90 ,
sizeof( V_90 ) ,
V_88 ,
NULL ) ;
if ( V_14 ) {
break;
}
for ( V_103 = 0 ; V_103 < sizeof( V_90 ) ; V_103 ++ ) {
if ( V_90 [ V_103 ] & ( 1 << Signal ) ) {
break;
}
}
if ( V_103 >= sizeof( V_90 ) ) {
break;
}
V_102 -- ;
F_33 ( 1 ) ;
}
if ( 0 == V_102 ) {
F_2 ( V_8 ,
( L_24 , Signal ) ) ;
V_14 = V_106 ;
}
}
return V_14 ;
}
