void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_2 -> V_3 ) ;
}
int F_3 ( struct V_1 * V_2 ,
bool V_4 , bool V_5 ,
bool V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_7 * V_11 = & V_2 -> V_3 ;
int V_12 ;
if ( V_11 -> V_13 != V_14 ) {
F_4 ( V_10 ) ;
F_1 ( V_2 ) ;
F_5 ( & V_11 -> V_15 , V_16 ,
V_17 ) ;
V_11 -> V_13 = V_14 ;
}
V_12 = F_6 ( V_10 , V_8 -> V_15 ) ;
if ( F_7 ( V_12 != 0 ) )
return V_12 ;
if ( V_8 -> V_13 != V_14 ) {
V_12 = F_8 ( V_10 , V_8 ) ;
if ( F_7 ( V_12 != 0 ) )
return V_12 ;
}
* V_11 = * V_8 ;
V_8 -> V_18 = NULL ;
return 0 ;
}
int F_9 ( struct V_19 * V_20 , bool V_21 )
{
if ( F_10 ( V_20 -> V_22 ) )
return 0 ;
if ( V_21 )
return F_11 ( & V_20 -> V_23 ) ;
F_12 ( & V_20 -> V_23 ) ;
return 0 ;
}
void F_13 ( struct V_19 * V_20 )
{
if ( F_10 ( V_20 -> V_22 ) )
return;
F_14 ( & V_20 -> V_23 ) ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
if ( ! V_20 -> V_24 || F_16 ( & V_20 -> V_25 ) )
return - V_26 ;
V_2 = F_17 ( & V_20 -> V_25 ,
struct V_1 ,
V_25 ) ;
F_18 ( & V_2 -> V_25 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_7 * V_3 )
{
struct V_19 * V_20 = & V_28 -> V_20 [ V_3 -> V_13 ] ;
int V_12 = 0 ;
if ( ! V_28 -> V_29 -> V_30 )
return 0 ;
if ( F_10 ( V_20 -> V_22 ) )
return V_28 -> V_29 -> V_30 ( V_28 , V_3 ) ;
if ( V_28 -> V_29 -> V_30 &&
V_3 -> V_31 . V_32 ++ == 0 ) {
V_33:
V_12 = V_28 -> V_29 -> V_30 ( V_28 , V_3 ) ;
if ( V_12 == - V_26 ) {
V_12 = F_15 ( V_20 ) ;
if ( V_12 == 0 )
goto V_33;
}
}
return V_12 ;
}
static void F_21 ( struct V_27 * V_28 ,
struct V_7 * V_3 )
{
struct V_19 * V_20 = & V_28 -> V_20 [ V_3 -> V_13 ] ;
if ( F_10 ( V_20 -> V_22 ) )
return;
if ( V_28 -> V_29 -> V_30 &&
-- V_3 -> V_31 . V_32 == 0 &&
V_28 -> V_29 -> V_34 )
V_28 -> V_29 -> V_34 ( V_28 , V_3 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_7 * V_3 = & V_2 -> V_3 ;
int V_12 ;
if ( ! V_3 -> V_31 . V_35 ) {
struct V_19 * V_20 =
& V_2 -> V_28 -> V_20 [ V_3 -> V_13 ] ;
V_12 = F_20 ( V_2 -> V_28 , V_3 ) ;
if ( F_7 ( V_12 != 0 ) )
return V_12 ;
V_3 -> V_31 . V_35 = true ;
if ( V_20 -> V_24 )
F_23 ( & V_2 -> V_25 ,
& V_20 -> V_25 ) ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_3 = & V_2 -> V_3 ;
if ( V_3 -> V_31 . V_35 ) {
V_3 -> V_31 . V_35 = false ;
F_18 ( & V_2 -> V_25 ) ;
F_21 ( V_2 -> V_28 , V_3 ) ;
}
}
int F_25 ( struct V_27 * V_28 , struct V_7 * V_3 ,
void * * V_36 )
{
struct V_19 * V_20 = & V_28 -> V_20 [ V_3 -> V_13 ] ;
int V_12 ;
void * V_37 ;
* V_36 = NULL ;
( void ) F_9 ( V_20 , false ) ;
V_12 = F_20 ( V_28 , V_3 ) ;
F_13 ( V_20 ) ;
if ( V_12 || ! V_3 -> V_31 . V_38 )
return V_12 ;
if ( V_3 -> V_31 . V_37 ) {
V_37 = V_3 -> V_31 . V_37 ;
} else {
if ( V_3 -> V_15 & V_39 )
V_37 = F_26 ( V_3 -> V_31 . V_40 + V_3 -> V_31 . V_41 , V_3 -> V_31 . V_42 ) ;
else
V_37 = F_27 ( V_3 -> V_31 . V_40 + V_3 -> V_31 . V_41 , V_3 -> V_31 . V_42 ) ;
if ( ! V_37 ) {
( void ) F_9 ( V_20 , false ) ;
F_21 ( V_28 , V_3 ) ;
F_13 ( V_20 ) ;
return - V_43 ;
}
}
* V_36 = V_37 ;
return 0 ;
}
void F_28 ( struct V_27 * V_28 , struct V_7 * V_3 ,
void * V_36 )
{
struct V_19 * V_20 ;
V_20 = & V_28 -> V_20 [ V_3 -> V_13 ] ;
if ( V_36 && V_3 -> V_31 . V_37 == NULL )
F_29 ( V_36 ) ;
( void ) F_9 ( V_20 , false ) ;
F_21 ( V_28 , V_3 ) ;
F_13 ( V_20 ) ;
}
static int F_30 ( void * V_44 , void * V_45 , unsigned long V_46 )
{
T_1 * V_47 =
( T_1 * ) ( ( unsigned long ) V_44 + ( V_46 << V_48 ) ) ;
T_1 * V_49 =
( T_1 * ) ( ( unsigned long ) V_45 + ( V_46 << V_48 ) ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_51 / sizeof( T_1 ) ; ++ V_50 )
F_31 ( F_32 ( V_49 ++ ) , V_47 ++ ) ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 , void * V_45 ,
unsigned long V_46 ,
T_2 V_52 )
{
struct V_46 * V_53 = F_34 ( V_10 , V_46 ) ;
void * V_44 ;
if ( ! V_53 )
return - V_43 ;
V_45 = ( void * ) ( ( unsigned long ) V_45 + ( V_46 << V_48 ) ) ;
#ifdef F_35
V_44 = F_36 ( V_53 , V_52 ) ;
#else
if ( F_37 ( V_52 ) != F_37 ( V_54 ) )
V_44 = F_38 ( & V_53 , 1 , 0 , V_52 ) ;
else
V_44 = F_39 ( V_53 ) ;
#endif
if ( ! V_44 )
return - V_43 ;
F_40 ( V_44 , V_45 , V_51 ) ;
#ifdef F_35
F_41 ( V_44 ) ;
#else
if ( F_37 ( V_52 ) != F_37 ( V_54 ) )
F_42 ( V_44 ) ;
else
F_43 ( V_53 ) ;
#endif
return 0 ;
}
static int F_44 ( struct V_9 * V_10 , void * V_44 ,
unsigned long V_46 ,
T_2 V_52 )
{
struct V_46 * V_55 = F_34 ( V_10 , V_46 ) ;
void * V_45 ;
if ( ! V_55 )
return - V_43 ;
V_44 = ( void * ) ( ( unsigned long ) V_44 + ( V_46 << V_48 ) ) ;
#ifdef F_35
V_45 = F_36 ( V_55 , V_52 ) ;
#else
if ( F_37 ( V_52 ) != F_37 ( V_54 ) )
V_45 = F_38 ( & V_55 , 1 , 0 , V_52 ) ;
else
V_45 = F_39 ( V_55 ) ;
#endif
if ( ! V_45 )
return - V_43 ;
F_45 ( V_44 , V_45 , V_51 ) ;
#ifdef F_35
F_41 ( V_45 ) ;
#else
if ( F_37 ( V_52 ) != F_37 ( V_54 ) )
F_42 ( V_45 ) ;
else
F_43 ( V_55 ) ;
#endif
return 0 ;
}
int F_46 ( struct V_1 * V_2 ,
bool V_4 , bool V_5 , bool V_6 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_19 * V_20 = & V_28 -> V_20 [ V_8 -> V_13 ] ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_7 * V_11 = & V_2 -> V_3 ;
struct V_7 V_56 ;
void * V_57 ;
void * V_58 ;
int V_12 ;
unsigned long V_50 ;
unsigned long V_46 ;
unsigned long V_59 = 0 ;
int V_60 ;
V_12 = F_25 ( V_28 , V_11 , & V_57 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_25 ( V_28 , V_8 , & V_58 ) ;
if ( V_12 )
goto V_61;
if ( V_57 == NULL && V_58 == NULL )
goto V_62;
if ( V_57 == NULL && V_10 == NULL )
goto V_62;
V_59 = 0 ;
V_60 = 1 ;
if ( ( V_11 -> V_13 == V_8 -> V_13 ) &&
( V_8 -> V_63 < V_11 -> V_63 + V_11 -> V_42 ) ) {
V_60 = - 1 ;
V_59 = V_8 -> V_64 - 1 ;
}
for ( V_50 = 0 ; V_50 < V_8 -> V_64 ; ++ V_50 ) {
V_46 = V_50 * V_60 + V_59 ;
if ( V_57 == NULL ) {
T_2 V_52 = F_47 ( V_11 -> V_15 ,
V_54 ) ;
V_12 = F_44 ( V_10 , V_58 , V_46 ,
V_52 ) ;
} else if ( V_58 == NULL ) {
T_2 V_52 = F_47 ( V_8 -> V_15 ,
V_54 ) ;
V_12 = F_33 ( V_10 , V_57 , V_46 ,
V_52 ) ;
} else
V_12 = F_30 ( V_58 , V_57 , V_46 ) ;
if ( V_12 )
goto V_65;
}
F_48 () ;
V_62:
V_56 = * V_11 ;
* V_11 = * V_8 ;
V_8 -> V_18 = NULL ;
if ( ( V_20 -> V_66 & V_67 ) && ( V_10 != NULL ) ) {
F_4 ( V_10 ) ;
F_49 ( V_10 ) ;
V_2 -> V_10 = NULL ;
}
V_65:
F_28 ( V_28 , V_11 , V_58 ) ;
V_61:
F_28 ( V_28 , & V_56 , V_57 ) ;
F_2 ( V_2 , & V_56 ) ;
return V_12 ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_1 * * V_68 )
{
struct V_1 * V_69 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_70 * V_29 = V_28 -> V_29 ;
V_69 = F_53 ( sizeof( * V_69 ) , V_71 ) ;
if ( ! V_69 )
return - V_43 ;
* V_69 = * V_2 ;
F_54 ( & V_69 -> V_72 ) ;
F_55 ( & V_69 -> V_73 ) ;
F_55 ( & V_69 -> V_74 ) ;
F_55 ( & V_69 -> V_75 ) ;
F_55 ( & V_69 -> V_25 ) ;
V_69 -> V_76 = NULL ;
F_56 ( & V_69 -> V_77 , 0 ) ;
V_69 -> V_78 = V_29 -> V_79 ( V_2 -> V_78 ) ;
F_57 ( & V_69 -> V_80 ) ;
F_57 ( & V_69 -> V_81 ) ;
V_69 -> V_82 = & F_50 ;
* V_68 = V_69 ;
return 0 ;
}
T_2 F_47 ( T_1 V_83 , T_2 V_84 )
{
#if F_58 ( V_85 ) || F_58 ( V_86 )
if ( V_83 & V_39 )
V_84 = F_59 ( V_84 ) ;
else if ( V_87 . V_88 > 3 )
V_84 = F_60 ( V_84 ) ;
#elif F_58 ( V_89 )
if ( ! ( V_83 & V_90 ) ) {
F_37 ( V_84 ) |= V_91 ;
if ( V_83 & V_92 )
F_37 ( V_84 ) |= V_93 ;
}
#endif
#if F_58 ( V_94 )
if ( V_83 & V_39 )
V_84 = F_59 ( V_84 ) ;
else
V_84 = F_60 ( V_84 ) ;
#endif
#if F_58 ( V_95 )
if ( ! ( V_83 & V_90 ) )
V_84 = F_60 ( V_84 ) ;
#endif
return V_84 ;
}
static int F_61 ( struct V_1 * V_2 ,
unsigned long V_41 ,
unsigned long V_42 ,
struct V_96 * V_97 )
{
struct V_7 * V_3 = & V_2 -> V_3 ;
if ( V_2 -> V_3 . V_31 . V_37 ) {
V_97 -> V_98 = V_99 ;
V_97 -> V_36 = ( void * ) ( ( ( V_100 * ) V_2 -> V_3 . V_31 . V_37 ) + V_41 ) ;
} else {
V_97 -> V_98 = V_101 ;
if ( V_3 -> V_15 & V_39 )
V_97 -> V_36 = F_26 ( V_2 -> V_3 . V_31 . V_40 + V_2 -> V_3 . V_31 . V_41 + V_41 ,
V_42 ) ;
else
V_97 -> V_36 = F_27 ( V_2 -> V_3 . V_31 . V_40 + V_2 -> V_3 . V_31 . V_41 + V_41 ,
V_42 ) ;
}
return ( ! V_97 -> V_36 ) ? - V_43 : 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
unsigned long V_102 ,
unsigned long V_64 ,
struct V_96 * V_97 )
{
struct V_7 * V_3 = & V_2 -> V_3 ; T_2 V_52 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_46 * V_53 ;
int V_50 ;
F_63 ( ! V_10 ) ;
if ( V_64 == 1 && ( V_3 -> V_15 & V_90 ) ) {
V_97 -> V_98 = V_103 ;
V_97 -> V_46 = F_34 ( V_10 , V_102 ) ;
V_97 -> V_36 = F_39 ( V_97 -> V_46 ) ;
} else {
for ( V_50 = V_102 ; V_50 < V_102 + V_64 ; ++ V_50 ) {
V_53 = F_34 ( V_10 , V_50 ) ;
if ( ! V_53 )
return - V_43 ;
}
V_52 = ( V_3 -> V_15 & V_90 ) ?
V_54 :
F_47 ( V_3 -> V_15 , V_54 ) ;
V_97 -> V_98 = V_104 ;
V_97 -> V_36 = F_38 ( V_10 -> V_105 + V_102 , V_64 ,
0 , V_52 ) ;
}
return ( ! V_97 -> V_36 ) ? - V_43 : 0 ;
}
int F_64 ( struct V_1 * V_2 ,
unsigned long V_102 , unsigned long V_64 ,
struct V_96 * V_97 )
{
struct V_19 * V_20 =
& V_2 -> V_28 -> V_20 [ V_2 -> V_3 . V_13 ] ;
unsigned long V_41 , V_42 ;
int V_12 ;
F_63 ( ! F_16 ( & V_2 -> V_75 ) ) ;
V_97 -> V_36 = NULL ;
V_97 -> V_2 = V_2 ;
if ( V_64 > V_2 -> V_64 )
return - V_106 ;
if ( V_102 > V_2 -> V_64 )
return - V_106 ;
#if 0
if (num_pages > 1 && !DRM_SUSER(DRM_CURPROC))
return -EPERM;
#endif
( void ) F_9 ( V_20 , false ) ;
V_12 = F_20 ( V_2 -> V_28 , & V_2 -> V_3 ) ;
F_13 ( V_20 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_2 -> V_3 . V_31 . V_38 ) {
return F_62 ( V_2 , V_102 , V_64 , V_97 ) ;
} else {
V_41 = V_102 << V_48 ;
V_42 = V_64 << V_48 ;
return F_61 ( V_2 , V_41 , V_42 , V_97 ) ;
}
}
void F_65 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_2 ;
struct V_19 * V_20 =
& V_2 -> V_28 -> V_20 [ V_2 -> V_3 . V_13 ] ;
if ( ! V_97 -> V_36 )
return;
switch ( V_97 -> V_98 ) {
case V_101 :
F_29 ( V_97 -> V_36 ) ;
break;
case V_104 :
F_42 ( V_97 -> V_36 ) ;
break;
case V_103 :
F_43 ( V_97 -> V_46 ) ;
break;
case V_99 :
break;
default:
F_66 () ;
}
( void ) F_9 ( V_20 , false ) ;
F_21 ( V_97 -> V_2 -> V_28 , & V_97 -> V_2 -> V_3 ) ;
F_13 ( V_20 ) ;
V_97 -> V_36 = NULL ;
V_97 -> V_46 = NULL ;
}
int F_67 ( struct V_1 * V_2 ,
void * V_78 ,
void * V_107 ,
bool V_4 , bool V_5 ,
bool V_6 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_70 * V_29 = V_28 -> V_29 ;
struct V_19 * V_20 = & V_28 -> V_20 [ V_8 -> V_13 ] ;
struct V_7 * V_11 = & V_2 -> V_3 ;
int V_12 ;
struct V_1 * V_108 ;
void * V_109 = NULL ;
F_68 ( & V_28 -> V_110 ) ;
if ( V_2 -> V_78 ) {
V_109 = V_2 -> V_78 ;
V_2 -> V_78 = NULL ;
}
V_2 -> V_78 = V_29 -> V_79 ( V_78 ) ;
V_2 -> V_107 = V_107 ;
if ( V_4 ) {
V_12 = F_69 ( V_2 , false , false , false ) ;
F_70 ( & V_28 -> V_110 ) ;
if ( V_109 )
V_29 -> V_111 ( & V_109 ) ;
if ( V_12 )
return V_12 ;
F_1 ( V_2 ) ;
if ( ( V_20 -> V_66 & V_67 ) &&
( V_2 -> V_10 != NULL ) ) {
F_4 ( V_2 -> V_10 ) ;
F_49 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
} else {
F_71 ( V_112 , & V_2 -> V_113 ) ;
F_70 ( & V_28 -> V_110 ) ;
if ( V_109 )
V_29 -> V_111 ( & V_109 ) ;
V_12 = F_52 ( V_2 , & V_108 ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_20 -> V_66 & V_67 ) )
V_108 -> V_10 = NULL ;
else
V_2 -> V_10 = NULL ;
F_72 ( V_108 ) ;
F_73 ( & V_108 ) ;
}
* V_11 = * V_8 ;
V_8 -> V_18 = NULL ;
return 0 ;
}
