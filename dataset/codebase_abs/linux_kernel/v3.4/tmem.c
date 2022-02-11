void F_1 ( struct V_1 * V_2 )
{
F_2 () ;
V_1 = * V_2 ;
}
void F_3 ( struct V_3 * V_2 )
{
V_3 = * V_2 ;
}
static struct V_4 * F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_4 * V_11 ;
V_10 = V_6 -> V_12 . V_9 ;
while ( V_10 ) {
F_5 ( F_6 ( V_10 ) ) ;
V_11 = F_7 ( V_10 , struct V_4 , V_13 ) ;
switch ( F_8 ( V_8 , & V_11 -> V_14 ) ) {
case 0 :
goto V_15;
case - 1 :
V_10 = V_10 -> V_16 ;
break;
case 1 :
V_10 = V_10 -> V_17 ;
break;
}
}
V_11 = NULL ;
V_15:
return V_11 ;
}
static void F_9 ( struct V_4 * V_11 , struct V_5 * V_6 )
{
struct V_18 * V_19 ;
F_5 ( V_11 == NULL ) ;
F_10 ( V_11 , V_20 ) ;
F_5 ( V_11 -> V_21 > 0 ) ;
V_19 = V_11 -> V_19 ;
F_5 ( V_19 == NULL ) ;
if ( V_11 -> V_22 != NULL )
F_11 ( V_11 ) ;
F_5 ( V_11 -> V_22 != NULL ) ;
F_5 ( ( long ) V_11 -> V_23 != 0 ) ;
F_12 ( & V_19 -> V_24 ) ;
F_5 ( F_13 ( & V_19 -> V_24 ) < 0 ) ;
F_14 ( V_11 , V_20 ) ;
V_11 -> V_19 = NULL ;
F_15 ( & V_11 -> V_14 ) ;
F_16 ( & V_11 -> V_13 , & V_6 -> V_12 ) ;
}
static void F_17 ( struct V_4 * V_11 , struct V_5 * V_6 ,
struct V_18 * V_19 ,
struct V_7 * V_8 )
{
struct V_25 * V_26 = & V_6 -> V_12 ;
struct V_9 * * V_27 = & ( V_26 -> V_9 ) , * V_28 = NULL ;
struct V_4 * V_29 ;
F_5 ( V_19 == NULL ) ;
F_18 ( & V_19 -> V_24 ) ;
V_11 -> V_30 = 0 ;
V_11 -> V_22 = NULL ;
V_11 -> V_19 = V_19 ;
V_11 -> V_14 = * V_8 ;
V_11 -> V_23 = 0 ;
V_11 -> V_21 = 0 ;
(* V_3 . V_31 )( V_11 ) ;
F_19 ( V_11 , V_20 ) ;
while ( * V_27 ) {
F_5 ( F_6 ( * V_27 ) ) ;
V_29 = F_7 ( * V_27 , struct V_4 , V_13 ) ;
V_28 = * V_27 ;
switch ( F_8 ( V_8 , & V_29 -> V_14 ) ) {
case 0 :
F_20 () ;
break;
case - 1 :
V_27 = & ( * V_27 ) -> V_16 ;
break;
case 1 :
V_27 = & ( * V_27 ) -> V_17 ;
break;
}
}
F_21 ( & V_11 -> V_13 , V_28 , V_27 ) ;
F_22 ( & V_11 -> V_13 , V_26 ) ;
}
static void F_23 ( struct V_18 * V_19 , bool V_32 )
{
struct V_9 * V_10 ;
struct V_4 * V_11 ;
struct V_5 * V_6 = & V_19 -> V_33 [ 0 ] ;
int V_34 ;
F_5 ( V_19 == NULL ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ , V_6 ++ ) {
F_24 ( & V_6 -> V_36 ) ;
V_10 = F_25 ( & V_6 -> V_12 ) ;
while ( V_10 != NULL ) {
V_11 = F_7 ( V_10 , struct V_4 , V_13 ) ;
V_10 = F_26 ( V_10 ) ;
F_11 ( V_11 ) ;
F_9 ( V_11 , V_6 ) ;
(* V_1 . V_37 )( V_11 , V_19 ) ;
}
F_27 ( & V_6 -> V_36 ) ;
}
if ( V_32 )
F_28 ( & V_19 -> V_38 ) ;
}
static void F_2 ( void )
{
unsigned int V_39 , V_40 ;
for ( V_39 = 0 ; V_39 < F_29 ( V_41 ) ; V_39 ++ ) {
V_40 = V_39 * V_42 ;
if ( V_40 >= V_43 )
V_41 [ V_39 ] = ~ 0UL ;
else
V_41 [ V_39 ] =
( ~ 0UL >> ( V_43 - V_40 - 1 ) ) >> 1 ;
}
}
static struct V_44 * F_30 ( struct V_4 * V_11 )
{
struct V_44 * V_45 ;
F_10 ( V_11 , V_20 ) ;
F_5 ( V_11 -> V_19 == NULL ) ;
F_10 ( V_11 -> V_19 , V_46 ) ;
V_45 = (* V_1 . V_47 )( V_11 -> V_19 ) ;
if ( F_31 ( V_45 == NULL ) )
goto V_15;
V_45 -> V_11 = V_11 ;
F_19 ( V_45 , V_48 ) ;
memset ( & V_45 -> V_49 , 0 , sizeof( V_45 -> V_49 ) ) ;
V_45 -> V_50 = 0 ;
V_11 -> V_23 ++ ;
V_15:
return V_45 ;
}
static void F_32 ( struct V_44 * V_45 )
{
struct V_18 * V_19 ;
int V_34 ;
F_5 ( V_45 == NULL ) ;
for ( V_34 = 0 ; V_34 < V_51 ; V_34 ++ )
F_5 ( V_45 -> V_49 [ V_34 ] != NULL ) ;
F_10 ( V_45 , V_48 ) ;
F_14 ( V_45 , V_48 ) ;
F_5 ( V_45 -> V_11 == NULL ) ;
F_10 ( V_45 -> V_11 , V_20 ) ;
V_19 = V_45 -> V_11 -> V_19 ;
F_5 ( V_19 == NULL ) ;
F_10 ( V_19 , V_46 ) ;
V_45 -> V_11 -> V_23 -- ;
V_45 -> V_11 = NULL ;
(* V_1 . V_52 )( V_45 , V_19 ) ;
}
static void * * F_33 ( struct V_4 * V_11 , T_1 V_53 )
{
unsigned int V_54 , V_55 ;
struct V_44 * * V_56 = NULL ;
F_5 ( V_11 == NULL ) ;
F_10 ( V_11 , V_20 ) ;
F_5 ( V_11 -> V_19 == NULL ) ;
F_10 ( V_11 -> V_19 , V_46 ) ;
V_54 = V_11 -> V_30 ;
if ( V_53 > V_41 [ V_11 -> V_30 ] )
goto V_15;
if ( V_54 == 0 && V_11 -> V_22 ) {
V_56 = & V_11 -> V_22 ;
goto V_15;
}
V_55 = ( V_54 - 1 ) * V_42 ;
V_56 = & V_11 -> V_22 ;
while ( V_54 > 0 ) {
if ( * V_56 == NULL )
goto V_15;
V_56 = (struct V_44 * * )
( ( * V_56 ) -> V_49 +
( ( V_53 >> V_55 ) & V_57 ) ) ;
V_55 -= V_42 ;
V_54 -- ;
}
V_15:
return V_56 != NULL ? ( void * * ) V_56 : NULL ;
}
static void * F_34 ( struct V_4 * V_11 , T_1 V_53 )
{
struct V_44 * * V_56 ;
V_56 = (struct V_44 * * ) F_33 ( V_11 , V_53 ) ;
return V_56 != NULL ? * V_56 : NULL ;
}
static void * F_35 ( struct V_4 * V_11 , T_1 V_53 ,
void * V_58 , bool V_59 )
{
struct V_44 * * V_56 ;
void * V_60 = NULL ;
V_56 = (struct V_44 * * ) F_33 ( V_11 , V_53 ) ;
if ( ( V_56 != NULL ) && ( * V_56 != NULL ) ) {
void * V_61 = * ( void * * ) V_56 ;
* ( void * * ) V_56 = V_58 ;
if ( ! V_59 )
(* V_3 . free )( V_61 , V_11 -> V_19 ,
NULL , 0 , false ) ;
V_60 = V_58 ;
}
return V_60 ;
}
static int F_36 ( struct V_4 * V_11 , T_1 V_53 ,
void * V_62 )
{
int V_60 = 0 ;
struct V_44 * V_45 = NULL , * V_63 , * V_56 ;
unsigned int V_54 , V_55 ;
int V_64 = 0 ;
if ( V_53 > V_41 [ V_11 -> V_30 ] ) {
V_54 = V_11 -> V_30 + 1 ;
if ( V_53 > V_41 [ V_54 ] )
while ( V_53 > V_41 [ V_54 ] )
V_54 ++ ;
if ( V_11 -> V_22 == NULL ) {
V_11 -> V_30 = V_54 ;
goto V_65;
}
do {
V_63 = F_30 ( V_11 ) ;
if ( ! V_63 ) {
V_60 = - V_66 ;
goto V_15;
}
V_63 -> V_49 [ 0 ] = V_11 -> V_22 ;
V_63 -> V_50 = 1 ;
V_11 -> V_22 = V_63 ;
V_11 -> V_30 ++ ;
} while ( V_54 > V_11 -> V_30 );
}
V_65:
V_56 = V_11 -> V_22 ;
V_54 = V_11 -> V_30 ;
V_55 = ( V_54 - 1 ) * V_42 ;
while ( V_54 > 0 ) {
if ( V_56 == NULL ) {
V_56 = F_30 ( V_11 ) ;
if ( ! V_56 ) {
V_60 = - V_66 ;
goto V_15;
}
if ( V_45 ) {
V_45 -> V_49 [ V_64 ] = V_56 ;
V_45 -> V_50 ++ ;
} else
V_11 -> V_22 = V_56 ;
}
V_64 = ( V_53 >> V_55 ) & V_57 ;
V_45 = V_56 ;
V_56 = V_45 -> V_49 [ V_64 ] ;
V_55 -= V_42 ;
V_54 -- ;
}
F_5 ( V_56 != NULL ) ;
if ( V_45 ) {
V_45 -> V_50 ++ ;
V_45 -> V_49 [ V_64 ] = V_62 ;
} else
V_11 -> V_22 = V_62 ;
V_11 -> V_21 ++ ;
V_15:
return V_60 ;
}
static void * F_37 ( struct V_4 * V_11 , T_1 V_53 )
{
struct V_67 V_68 [ V_69 + 1 ] ;
struct V_67 * V_70 = V_68 ;
struct V_44 * V_56 = NULL ;
unsigned int V_54 , V_55 ;
int V_64 ;
F_5 ( V_11 == NULL ) ;
F_10 ( V_11 , V_20 ) ;
F_5 ( V_11 -> V_19 == NULL ) ;
F_10 ( V_11 -> V_19 , V_46 ) ;
V_54 = V_11 -> V_30 ;
if ( V_53 > V_41 [ V_54 ] )
goto V_15;
V_56 = V_11 -> V_22 ;
if ( V_54 == 0 && V_11 -> V_22 ) {
V_11 -> V_22 = NULL ;
goto V_15;
}
V_55 = ( V_54 - 1 ) * V_42 ;
V_70 -> V_45 = NULL ;
do {
if ( V_56 == NULL )
goto V_15;
V_70 ++ ;
V_64 = ( V_53 >> V_55 ) & V_57 ;
V_70 -> V_64 = V_64 ;
V_70 -> V_45 = V_56 ;
V_56 = V_56 -> V_49 [ V_64 ] ;
V_55 -= V_42 ;
V_54 -- ;
} while ( V_54 > 0 );
if ( V_56 == NULL )
goto V_15;
while ( V_70 -> V_45 ) {
V_70 -> V_45 -> V_49 [ V_70 -> V_64 ] = NULL ;
V_70 -> V_45 -> V_50 -- ;
if ( V_70 -> V_45 -> V_50 ) {
if ( V_70 -> V_45 == V_11 -> V_22 ) {
while ( V_11 -> V_30 > 0 &&
V_11 -> V_22 -> V_50 == 1 &&
V_11 -> V_22 -> V_49 [ 0 ] ) {
struct V_44 * V_71 =
V_11 -> V_22 ;
V_11 -> V_22 =
V_71 -> V_49 [ 0 ] ;
V_11 -> V_30 -- ;
V_71 -> V_49 [ 0 ] = NULL ;
V_71 -> V_50 = 0 ;
F_32 ( V_71 ) ;
}
}
goto V_15;
}
F_32 ( V_70 -> V_45 ) ;
V_70 -- ;
}
V_11 -> V_30 = 0 ;
V_11 -> V_22 = NULL ;
V_15:
if ( V_56 != NULL )
V_11 -> V_21 -- ;
F_5 ( V_11 -> V_21 < 0 ) ;
return V_56 ;
}
static void F_38 ( struct V_4 * V_11 ,
struct V_44 * V_45 ,
unsigned int V_39 )
{
int V_34 ;
if ( V_39 == 0 )
return;
for ( V_34 = 0 ; V_34 < V_51 ; V_34 ++ ) {
if ( V_45 -> V_49 [ V_34 ] ) {
if ( V_39 == 1 ) {
V_11 -> V_21 -- ;
(* V_3 . free )( V_45 -> V_49 [ V_34 ] ,
V_11 -> V_19 , NULL , 0 , true ) ;
V_45 -> V_49 [ V_34 ] = NULL ;
continue;
}
F_38 ( V_11 , V_45 -> V_49 [ V_34 ] , V_39 - 1 ) ;
F_32 ( V_45 -> V_49 [ V_34 ] ) ;
V_45 -> V_49 [ V_34 ] = NULL ;
}
}
}
static void F_11 ( struct V_4 * V_11 )
{
if ( V_11 -> V_22 == NULL )
return;
if ( V_11 -> V_30 == 0 ) {
V_11 -> V_21 -- ;
(* V_3 . free )( V_11 -> V_22 ,
V_11 -> V_19 , NULL , 0 , true ) ;
} else {
F_38 ( V_11 , V_11 -> V_22 ,
V_11 -> V_30 ) ;
F_32 ( V_11 -> V_22 ) ;
V_11 -> V_30 = 0 ;
}
V_11 -> V_22 = NULL ;
(* V_3 . V_72 )( V_11 -> V_19 , V_11 ) ;
}
int F_39 ( struct V_18 * V_19 , struct V_7 * V_8 , T_1 V_53 ,
char * V_73 , T_2 V_74 , bool V_75 , int V_76 )
{
struct V_4 * V_11 = NULL , * V_77 = NULL , * V_78 = NULL ;
void * V_62 = NULL , * V_79 = NULL ;
int V_60 = - V_66 ;
struct V_5 * V_6 ;
V_6 = & V_19 -> V_33 [ F_40 ( V_8 ) ] ;
F_24 ( & V_6 -> V_36 ) ;
V_11 = V_77 = F_4 ( V_6 , V_8 ) ;
if ( V_11 != NULL ) {
V_62 = F_34 ( V_77 , V_53 ) ;
if ( V_62 != NULL ) {
V_79 = F_37 ( V_11 , V_53 ) ;
F_5 ( V_79 != V_62 ) ;
(* V_3 . free )( V_62 , V_19 , V_8 , V_53 , true ) ;
if ( V_11 -> V_21 == 0 ) {
V_78 = V_11 ;
V_77 = NULL ;
}
V_62 = NULL ;
}
} else {
V_11 = V_78 = (* V_1 . V_80 )( V_19 ) ;
if ( F_31 ( V_11 == NULL ) ) {
V_60 = - V_66 ;
goto V_15;
}
F_17 ( V_11 , V_6 , V_19 , V_8 ) ;
}
F_5 ( V_11 == NULL ) ;
F_5 ( ( ( V_78 != V_11 ) && ( V_77 != V_11 ) ) || ( V_78 == V_77 ) ) ;
V_62 = (* V_3 . V_81 )( V_73 , V_74 , V_75 , V_76 ,
V_11 -> V_19 , & V_11 -> V_14 , V_53 ) ;
if ( F_31 ( V_62 == NULL ) )
goto free;
V_60 = F_36 ( V_11 , V_53 , V_62 ) ;
if ( F_31 ( V_60 == - V_66 ) )
goto V_82;
goto V_15;
V_82:
( void ) F_37 ( V_11 , V_53 ) ;
free:
if ( V_62 )
(* V_3 . free )( V_62 , V_19 , NULL , 0 , true ) ;
if ( V_78 ) {
F_9 ( V_78 , V_6 ) ;
(* V_1 . V_37 )( V_78 , V_19 ) ;
}
V_15:
F_27 ( & V_6 -> V_36 ) ;
return V_60 ;
}
void * F_41 ( struct V_18 * V_19 , struct V_7 * V_8 ,
T_1 V_53 , struct V_4 * * V_83 ,
void * * V_84 )
{
struct V_5 * V_6 ;
struct V_4 * V_11 = NULL ;
void * V_62 = NULL ;
V_6 = & V_19 -> V_33 [ F_40 ( V_8 ) ] ;
F_24 ( & V_6 -> V_36 ) ;
V_11 = F_4 ( V_6 , V_8 ) ;
if ( F_42 ( V_11 != NULL ) )
V_62 = F_34 ( V_11 , V_53 ) ;
* V_83 = V_11 ;
* V_84 = ( void * ) V_6 ;
return V_62 ;
}
void F_43 ( struct V_4 * V_11 , T_1 V_53 ,
void * V_62 , void * V_84 , bool V_85 )
{
struct V_5 * V_6 = (struct V_5 * ) V_84 ;
F_5 ( ! F_44 ( & V_6 -> V_36 ) ) ;
if ( V_62 != NULL ) {
F_5 ( V_11 == NULL ) ;
( void ) F_35 ( V_11 , V_53 , V_62 , 1 ) ;
} else if ( V_85 ) {
F_5 ( V_11 == NULL ) ;
( void ) F_37 ( V_11 , V_53 ) ;
}
F_27 ( & V_6 -> V_36 ) ;
}
static int F_45 ( void * * V_86 , struct V_5 * V_6 ,
struct V_18 * V_19 , struct V_7 * V_8 ,
T_1 V_53 , bool free , char * V_73 )
{
void * V_61 = * V_86 , * V_58 = NULL ;
bool V_87 = false ;
int V_60 = 0 ;
if ( ! F_46 ( V_19 ) )
V_58 = (* V_3 . V_88 )(
V_61 , V_19 , V_8 , V_53 , & V_87 ) ;
if ( V_87 )
V_60 = - V_89 ;
else if ( V_58 != NULL )
* V_86 = V_58 ;
F_27 ( & V_6 -> V_36 ) ;
if ( ! V_87 )
V_60 = (* V_3 . V_90 )( V_61 , V_58 , V_19 ,
V_8 , V_53 , free , V_73 ) ;
return V_60 ;
}
int F_47 ( struct V_18 * V_19 , struct V_7 * V_8 , T_1 V_53 ,
char * V_73 , T_2 * V_74 , bool V_75 , int V_91 )
{
struct V_4 * V_11 ;
void * V_62 ;
bool V_76 = F_46 ( V_19 ) ;
int V_60 = - 1 ;
struct V_5 * V_6 ;
bool free = ( V_91 == 1 ) || ( ( V_91 == 0 ) && V_76 ) ;
bool V_92 = 0 ;
void * * V_86 ;
V_93:
V_6 = & V_19 -> V_33 [ F_40 ( V_8 ) ] ;
F_24 ( & V_6 -> V_36 ) ;
V_92 = 1 ;
V_11 = F_4 ( V_6 , V_8 ) ;
if ( V_11 == NULL )
goto V_15;
V_86 = F_33 ( V_11 , V_53 ) ;
if ( V_86 == NULL )
goto V_15;
if ( V_3 . V_94 ( * V_86 ) ) {
V_60 = F_45 ( V_86 , V_6 , V_19 , V_8 ,
V_53 , free , V_73 ) ;
V_92 = 0 ;
if ( V_60 == - V_89 ) {
F_48 ( 10 , 1000 ) ;
goto V_93;
} else if ( V_60 != 0 ) {
if ( V_60 != - V_95 )
F_49 ( L_1 ,
V_60 ) ;
V_60 = - 1 ;
goto V_15;
}
goto V_15;
}
if ( free )
V_62 = F_37 ( V_11 , V_53 ) ;
else
V_62 = F_34 ( V_11 , V_53 ) ;
if ( V_62 == NULL )
goto V_15;
if ( free ) {
if ( V_11 -> V_21 == 0 ) {
F_9 ( V_11 , V_6 ) ;
(* V_1 . V_37 )( V_11 , V_19 ) ;
V_11 = NULL ;
}
}
if ( free )
V_60 = (* V_3 . V_96 )(
V_73 , V_74 , V_75 , V_62 , V_19 , V_8 , V_53 ) ;
else
V_60 = (* V_3 . V_97 )(
V_73 , V_74 , V_75 , V_62 , V_19 , V_8 , V_53 ) ;
if ( V_60 < 0 )
goto V_15;
V_60 = 0 ;
V_15:
if ( V_92 )
F_27 ( & V_6 -> V_36 ) ;
return V_60 ;
}
int F_50 ( struct V_18 * V_19 ,
struct V_7 * V_8 , T_1 V_53 )
{
struct V_4 * V_11 ;
void * V_62 ;
int V_60 = - 1 ;
struct V_5 * V_6 ;
V_6 = & V_19 -> V_33 [ F_40 ( V_8 ) ] ;
F_24 ( & V_6 -> V_36 ) ;
V_11 = F_4 ( V_6 , V_8 ) ;
if ( V_11 == NULL )
goto V_15;
V_62 = F_37 ( V_11 , V_53 ) ;
if ( V_62 == NULL )
goto V_15;
(* V_3 . free )( V_62 , V_19 , V_8 , V_53 , true ) ;
if ( V_11 -> V_21 == 0 ) {
F_9 ( V_11 , V_6 ) ;
(* V_1 . V_37 )( V_11 , V_19 ) ;
}
V_60 = 0 ;
V_15:
F_27 ( & V_6 -> V_36 ) ;
return V_60 ;
}
int F_51 ( struct V_18 * V_19 , struct V_7 * V_8 ,
T_1 V_53 , void * V_58 )
{
struct V_4 * V_11 ;
int V_60 = - 1 ;
struct V_5 * V_6 ;
V_6 = & V_19 -> V_33 [ F_40 ( V_8 ) ] ;
F_24 ( & V_6 -> V_36 ) ;
V_11 = F_4 ( V_6 , V_8 ) ;
if ( V_11 == NULL )
goto V_15;
V_58 = F_35 ( V_11 , V_53 , V_58 , 0 ) ;
V_60 = (* V_3 . V_98 )( V_58 , V_11 ) ;
V_15:
F_27 ( & V_6 -> V_36 ) ;
return V_60 ;
}
int F_52 ( struct V_18 * V_19 , struct V_7 * V_8 )
{
struct V_4 * V_11 ;
struct V_5 * V_6 ;
int V_60 = - 1 ;
V_6 = & V_19 -> V_33 [ F_40 ( V_8 ) ] ;
F_24 ( & V_6 -> V_36 ) ;
V_11 = F_4 ( V_6 , V_8 ) ;
if ( V_11 == NULL )
goto V_15;
F_11 ( V_11 ) ;
F_9 ( V_11 , V_6 ) ;
(* V_1 . V_37 )( V_11 , V_19 ) ;
V_60 = 0 ;
V_15:
F_27 ( & V_6 -> V_36 ) ;
return V_60 ;
}
int F_53 ( struct V_18 * V_19 )
{
int V_60 = - 1 ;
if ( V_19 == NULL )
goto V_15;
F_23 ( V_19 , 1 ) ;
V_60 = 0 ;
V_15:
return V_60 ;
}
void F_54 ( struct V_18 * V_19 , T_1 V_99 )
{
int V_100 = V_99 & V_101 ;
int V_102 = V_99 & V_103 ;
struct V_5 * V_6 = & V_19 -> V_33 [ 0 ] ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ , V_6 ++ ) {
V_6 -> V_12 = V_104 ;
F_55 ( & V_6 -> V_36 ) ;
}
F_56 ( & V_19 -> V_38 ) ;
F_57 ( & V_19 -> V_24 , 0 ) ;
F_19 ( V_19 , V_46 ) ;
F_58 ( & V_19 -> V_38 , & V_105 ) ;
V_19 -> V_100 = V_100 ;
V_19 -> V_102 = V_102 ;
}
