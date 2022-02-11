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
struct V_46 * V_53 = V_10 -> V_54 [ V_46 ] ;
void * V_44 ;
if ( ! V_53 )
return - V_43 ;
V_45 = ( void * ) ( ( unsigned long ) V_45 + ( V_46 << V_48 ) ) ;
#ifdef F_34
V_44 = F_35 ( V_53 , V_52 ) ;
#else
if ( F_36 ( V_52 ) != F_36 ( V_55 ) )
V_44 = F_37 ( & V_53 , 1 , 0 , V_52 ) ;
else
V_44 = F_38 ( V_53 ) ;
#endif
if ( ! V_44 )
return - V_43 ;
F_39 ( V_44 , V_45 , V_51 ) ;
#ifdef F_34
F_40 ( V_44 ) ;
#else
if ( F_36 ( V_52 ) != F_36 ( V_55 ) )
F_41 ( V_44 ) ;
else
F_42 ( V_53 ) ;
#endif
return 0 ;
}
static int F_43 ( struct V_9 * V_10 , void * V_44 ,
unsigned long V_46 ,
T_2 V_52 )
{
struct V_46 * V_56 = V_10 -> V_54 [ V_46 ] ;
void * V_45 ;
if ( ! V_56 )
return - V_43 ;
V_44 = ( void * ) ( ( unsigned long ) V_44 + ( V_46 << V_48 ) ) ;
#ifdef F_34
V_45 = F_35 ( V_56 , V_52 ) ;
#else
if ( F_36 ( V_52 ) != F_36 ( V_55 ) )
V_45 = F_37 ( & V_56 , 1 , 0 , V_52 ) ;
else
V_45 = F_38 ( V_56 ) ;
#endif
if ( ! V_45 )
return - V_43 ;
F_44 ( V_44 , V_45 , V_51 ) ;
#ifdef F_34
F_40 ( V_45 ) ;
#else
if ( F_36 ( V_52 ) != F_36 ( V_55 ) )
F_41 ( V_45 ) ;
else
F_42 ( V_56 ) ;
#endif
return 0 ;
}
int F_45 ( struct V_1 * V_2 ,
bool V_4 , bool V_5 , bool V_6 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_19 * V_20 = & V_28 -> V_20 [ V_8 -> V_13 ] ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_7 * V_11 = & V_2 -> V_3 ;
struct V_7 V_57 = * V_11 ;
void * V_58 ;
void * V_59 ;
int V_12 ;
unsigned long V_50 ;
unsigned long V_46 ;
unsigned long V_60 = 0 ;
int V_61 ;
V_12 = F_25 ( V_28 , V_11 , & V_58 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_25 ( V_28 , V_8 , & V_59 ) ;
if ( V_12 )
goto V_62;
if ( V_58 == NULL && V_59 == NULL )
goto V_63;
if ( V_58 == NULL && V_10 == NULL )
goto V_63;
if ( V_10 -> V_64 == V_65 ) {
V_12 = V_10 -> V_28 -> V_29 -> V_66 ( V_10 ) ;
if ( V_12 )
goto V_67;
}
V_60 = 0 ;
V_61 = 1 ;
if ( ( V_11 -> V_13 == V_8 -> V_13 ) &&
( V_8 -> V_68 < V_11 -> V_68 + V_11 -> V_42 ) ) {
V_61 = - 1 ;
V_60 = V_8 -> V_69 - 1 ;
}
for ( V_50 = 0 ; V_50 < V_8 -> V_69 ; ++ V_50 ) {
V_46 = V_50 * V_61 + V_60 ;
if ( V_58 == NULL ) {
T_2 V_52 = F_46 ( V_11 -> V_15 ,
V_55 ) ;
V_12 = F_43 ( V_10 , V_59 , V_46 ,
V_52 ) ;
} else if ( V_59 == NULL ) {
T_2 V_52 = F_46 ( V_8 -> V_15 ,
V_55 ) ;
V_12 = F_33 ( V_10 , V_58 , V_46 ,
V_52 ) ;
} else
V_12 = F_30 ( V_59 , V_58 , V_46 ) ;
if ( V_12 )
goto V_67;
}
F_47 () ;
V_63:
V_57 = * V_11 ;
* V_11 = * V_8 ;
V_8 -> V_18 = NULL ;
if ( ( V_20 -> V_70 & V_71 ) && ( V_10 != NULL ) ) {
F_4 ( V_10 ) ;
F_48 ( V_10 ) ;
V_2 -> V_10 = NULL ;
}
V_67:
F_28 ( V_28 , V_11 , V_59 ) ;
V_62:
F_28 ( V_28 , & V_57 , V_58 ) ;
F_2 ( V_2 , & V_57 ) ;
return V_12 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_1 * * V_72 )
{
struct V_1 * V_73 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_74 * V_29 = V_28 -> V_29 ;
V_73 = F_52 ( sizeof( * V_73 ) , V_75 ) ;
if ( ! V_73 )
return - V_43 ;
* V_73 = * V_2 ;
F_53 ( & V_73 -> V_76 ) ;
F_54 ( & V_73 -> V_77 ) ;
F_54 ( & V_73 -> V_78 ) ;
F_54 ( & V_73 -> V_79 ) ;
F_54 ( & V_73 -> V_25 ) ;
V_73 -> V_80 = NULL ;
F_55 ( & V_73 -> V_81 , 0 ) ;
V_73 -> V_82 = V_29 -> V_83 ( V_2 -> V_82 ) ;
F_56 ( & V_73 -> V_84 ) ;
F_56 ( & V_73 -> V_85 ) ;
V_73 -> V_86 = & F_49 ;
V_73 -> V_87 = 0 ;
* V_72 = V_73 ;
return 0 ;
}
T_2 F_46 ( T_1 V_88 , T_2 V_89 )
{
#if F_57 ( V_90 ) || F_57 ( V_91 )
if ( V_88 & V_39 )
V_89 = F_58 ( V_89 ) ;
else if ( V_92 . V_93 > 3 )
V_89 = F_59 ( V_89 ) ;
#elif F_57 ( V_94 )
if ( ! ( V_88 & V_95 ) ) {
F_36 ( V_89 ) |= V_96 ;
if ( V_88 & V_97 )
F_36 ( V_89 ) |= V_98 ;
}
#endif
#if F_57 ( V_99 )
if ( V_88 & V_39 )
V_89 = F_58 ( V_89 ) ;
else
V_89 = F_59 ( V_89 ) ;
#endif
#if F_57 ( V_100 )
if ( ! ( V_88 & V_95 ) )
V_89 = F_59 ( V_89 ) ;
#endif
return V_89 ;
}
static int F_60 ( struct V_1 * V_2 ,
unsigned long V_41 ,
unsigned long V_42 ,
struct V_101 * V_102 )
{
struct V_7 * V_3 = & V_2 -> V_3 ;
if ( V_2 -> V_3 . V_31 . V_37 ) {
V_102 -> V_103 = V_104 ;
V_102 -> V_36 = ( void * ) ( ( ( V_105 * ) V_2 -> V_3 . V_31 . V_37 ) + V_41 ) ;
} else {
V_102 -> V_103 = V_106 ;
if ( V_3 -> V_15 & V_39 )
V_102 -> V_36 = F_26 ( V_2 -> V_3 . V_31 . V_40 + V_2 -> V_3 . V_31 . V_41 + V_41 ,
V_42 ) ;
else
V_102 -> V_36 = F_27 ( V_2 -> V_3 . V_31 . V_40 + V_2 -> V_3 . V_31 . V_41 + V_41 ,
V_42 ) ;
}
return ( ! V_102 -> V_36 ) ? - V_43 : 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
unsigned long V_107 ,
unsigned long V_69 ,
struct V_101 * V_102 )
{
struct V_7 * V_3 = & V_2 -> V_3 ; T_2 V_52 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_12 ;
F_62 ( ! V_10 ) ;
if ( V_10 -> V_64 == V_65 ) {
V_12 = V_10 -> V_28 -> V_29 -> V_66 ( V_10 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_69 == 1 && ( V_3 -> V_15 & V_95 ) ) {
V_102 -> V_103 = V_108 ;
V_102 -> V_46 = V_10 -> V_54 [ V_107 ] ;
V_102 -> V_36 = F_38 ( V_102 -> V_46 ) ;
} else {
V_52 = ( V_3 -> V_15 & V_95 ) ?
V_55 :
F_46 ( V_3 -> V_15 , V_55 ) ;
V_102 -> V_103 = V_109 ;
V_102 -> V_36 = F_37 ( V_10 -> V_54 + V_107 , V_69 ,
0 , V_52 ) ;
}
return ( ! V_102 -> V_36 ) ? - V_43 : 0 ;
}
int F_63 ( struct V_1 * V_2 ,
unsigned long V_107 , unsigned long V_69 ,
struct V_101 * V_102 )
{
struct V_19 * V_20 =
& V_2 -> V_28 -> V_20 [ V_2 -> V_3 . V_13 ] ;
unsigned long V_41 , V_42 ;
int V_12 ;
F_62 ( ! F_16 ( & V_2 -> V_79 ) ) ;
V_102 -> V_36 = NULL ;
V_102 -> V_2 = V_2 ;
if ( V_69 > V_2 -> V_69 )
return - V_110 ;
if ( V_107 > V_2 -> V_69 )
return - V_110 ;
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
return F_61 ( V_2 , V_107 , V_69 , V_102 ) ;
} else {
V_41 = V_107 << V_48 ;
V_42 = V_69 << V_48 ;
return F_60 ( V_2 , V_41 , V_42 , V_102 ) ;
}
}
void F_64 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_19 * V_20 =
& V_2 -> V_28 -> V_20 [ V_2 -> V_3 . V_13 ] ;
if ( ! V_102 -> V_36 )
return;
switch ( V_102 -> V_103 ) {
case V_106 :
F_29 ( V_102 -> V_36 ) ;
break;
case V_109 :
F_41 ( V_102 -> V_36 ) ;
break;
case V_108 :
F_42 ( V_102 -> V_46 ) ;
break;
case V_104 :
break;
default:
F_65 () ;
}
( void ) F_9 ( V_20 , false ) ;
F_21 ( V_102 -> V_2 -> V_28 , & V_102 -> V_2 -> V_3 ) ;
F_13 ( V_20 ) ;
V_102 -> V_36 = NULL ;
V_102 -> V_46 = NULL ;
}
int F_66 ( struct V_1 * V_2 ,
void * V_82 ,
void * V_111 ,
bool V_4 , bool V_5 ,
bool V_6 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_74 * V_29 = V_28 -> V_29 ;
struct V_19 * V_20 = & V_28 -> V_20 [ V_8 -> V_13 ] ;
struct V_7 * V_11 = & V_2 -> V_3 ;
int V_12 ;
struct V_1 * V_112 ;
void * V_113 = NULL ;
F_67 ( & V_28 -> V_114 ) ;
if ( V_2 -> V_82 ) {
V_113 = V_2 -> V_82 ;
V_2 -> V_82 = NULL ;
}
V_2 -> V_82 = V_29 -> V_83 ( V_82 ) ;
V_2 -> V_111 = V_111 ;
if ( V_4 ) {
V_12 = F_68 ( V_2 , false , false , false ) ;
F_69 ( & V_28 -> V_114 ) ;
if ( V_113 )
V_29 -> V_115 ( & V_113 ) ;
if ( V_12 )
return V_12 ;
if ( ( V_20 -> V_70 & V_71 ) &&
( V_2 -> V_10 != NULL ) ) {
F_4 ( V_2 -> V_10 ) ;
F_48 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
F_1 ( V_2 ) ;
} else {
F_70 ( V_116 , & V_2 -> V_117 ) ;
F_69 ( & V_28 -> V_114 ) ;
if ( V_113 )
V_29 -> V_115 ( & V_113 ) ;
V_12 = F_51 ( V_2 , & V_112 ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_20 -> V_70 & V_71 ) )
V_112 -> V_10 = NULL ;
else
V_2 -> V_10 = NULL ;
F_71 ( V_112 ) ;
F_72 ( & V_112 ) ;
}
* V_11 = * V_8 ;
V_8 -> V_18 = NULL ;
return 0 ;
}
