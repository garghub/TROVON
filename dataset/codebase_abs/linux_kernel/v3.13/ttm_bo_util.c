void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_2 -> V_3 ) ;
}
int F_3 ( struct V_1 * V_2 ,
bool V_4 ,
bool V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 * V_10 = & V_2 -> V_3 ;
int V_11 ;
if ( V_10 -> V_12 != V_13 ) {
F_4 ( V_9 ) ;
F_1 ( V_2 ) ;
F_5 ( & V_10 -> V_14 , V_15 ,
V_16 ) ;
V_10 -> V_12 = V_13 ;
}
V_11 = F_6 ( V_9 , V_7 -> V_14 ) ;
if ( F_7 ( V_11 != 0 ) )
return V_11 ;
if ( V_7 -> V_12 != V_13 ) {
V_11 = F_8 ( V_9 , V_7 ) ;
if ( F_7 ( V_11 != 0 ) )
return V_11 ;
}
* V_10 = * V_7 ;
V_7 -> V_17 = NULL ;
return 0 ;
}
int F_9 ( struct V_18 * V_19 , bool V_20 )
{
if ( F_10 ( V_19 -> V_21 ) )
return 0 ;
if ( V_20 )
return F_11 ( & V_19 -> V_22 ) ;
F_12 ( & V_19 -> V_22 ) ;
return 0 ;
}
void F_13 ( struct V_18 * V_19 )
{
if ( F_10 ( V_19 -> V_21 ) )
return;
F_14 ( & V_19 -> V_22 ) ;
}
static int F_15 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
if ( ! V_19 -> V_23 || F_16 ( & V_19 -> V_24 ) )
return - V_25 ;
V_2 = F_17 ( & V_19 -> V_24 ,
struct V_1 ,
V_24 ) ;
F_18 ( & V_2 -> V_24 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_26 * V_27 ,
struct V_6 * V_3 )
{
struct V_18 * V_19 = & V_27 -> V_19 [ V_3 -> V_12 ] ;
int V_11 = 0 ;
if ( ! V_27 -> V_28 -> V_29 )
return 0 ;
if ( F_10 ( V_19 -> V_21 ) )
return V_27 -> V_28 -> V_29 ( V_27 , V_3 ) ;
if ( V_27 -> V_28 -> V_29 &&
V_3 -> V_30 . V_31 ++ == 0 ) {
V_32:
V_11 = V_27 -> V_28 -> V_29 ( V_27 , V_3 ) ;
if ( V_11 == - V_25 ) {
V_11 = F_15 ( V_19 ) ;
if ( V_11 == 0 )
goto V_32;
}
}
return V_11 ;
}
void F_21 ( struct V_26 * V_27 ,
struct V_6 * V_3 )
{
struct V_18 * V_19 = & V_27 -> V_19 [ V_3 -> V_12 ] ;
if ( F_10 ( V_19 -> V_21 ) )
return;
if ( V_27 -> V_28 -> V_29 &&
-- V_3 -> V_30 . V_31 == 0 &&
V_27 -> V_28 -> V_33 )
V_27 -> V_28 -> V_33 ( V_27 , V_3 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_3 = & V_2 -> V_3 ;
int V_11 ;
if ( ! V_3 -> V_30 . V_34 ) {
struct V_18 * V_19 =
& V_2 -> V_27 -> V_19 [ V_3 -> V_12 ] ;
V_11 = F_20 ( V_2 -> V_27 , V_3 ) ;
if ( F_7 ( V_11 != 0 ) )
return V_11 ;
V_3 -> V_30 . V_34 = true ;
if ( V_19 -> V_23 )
F_23 ( & V_2 -> V_24 ,
& V_19 -> V_24 ) ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_3 = & V_2 -> V_3 ;
if ( V_3 -> V_30 . V_34 ) {
V_3 -> V_30 . V_34 = false ;
F_18 ( & V_2 -> V_24 ) ;
F_21 ( V_2 -> V_27 , V_3 ) ;
}
}
int F_25 ( struct V_26 * V_27 , struct V_6 * V_3 ,
void * * V_35 )
{
struct V_18 * V_19 = & V_27 -> V_19 [ V_3 -> V_12 ] ;
int V_11 ;
void * V_36 ;
* V_35 = NULL ;
( void ) F_9 ( V_19 , false ) ;
V_11 = F_20 ( V_27 , V_3 ) ;
F_13 ( V_19 ) ;
if ( V_11 || ! V_3 -> V_30 . V_37 )
return V_11 ;
if ( V_3 -> V_30 . V_36 ) {
V_36 = V_3 -> V_30 . V_36 ;
} else {
if ( V_3 -> V_14 & V_38 )
V_36 = F_26 ( V_3 -> V_30 . V_39 + V_3 -> V_30 . V_40 , V_3 -> V_30 . V_41 ) ;
else
V_36 = F_27 ( V_3 -> V_30 . V_39 + V_3 -> V_30 . V_40 , V_3 -> V_30 . V_41 ) ;
if ( ! V_36 ) {
( void ) F_9 ( V_19 , false ) ;
F_21 ( V_27 , V_3 ) ;
F_13 ( V_19 ) ;
return - V_42 ;
}
}
* V_35 = V_36 ;
return 0 ;
}
void F_28 ( struct V_26 * V_27 , struct V_6 * V_3 ,
void * V_35 )
{
struct V_18 * V_19 ;
V_19 = & V_27 -> V_19 [ V_3 -> V_12 ] ;
if ( V_35 && V_3 -> V_30 . V_36 == NULL )
F_29 ( V_35 ) ;
( void ) F_9 ( V_19 , false ) ;
F_21 ( V_27 , V_3 ) ;
F_13 ( V_19 ) ;
}
static int F_30 ( void * V_43 , void * V_44 , unsigned long V_45 )
{
T_1 * V_46 =
( T_1 * ) ( ( unsigned long ) V_43 + ( V_45 << V_47 ) ) ;
T_1 * V_48 =
( T_1 * ) ( ( unsigned long ) V_44 + ( V_45 << V_47 ) ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_50 / sizeof( T_1 ) ; ++ V_49 )
F_31 ( F_32 ( V_48 ++ ) , V_46 ++ ) ;
return 0 ;
}
static int F_33 ( struct V_8 * V_9 , void * V_44 ,
unsigned long V_45 ,
T_2 V_51 )
{
struct V_45 * V_52 = V_9 -> V_53 [ V_45 ] ;
void * V_43 ;
if ( ! V_52 )
return - V_42 ;
V_44 = ( void * ) ( ( unsigned long ) V_44 + ( V_45 << V_47 ) ) ;
#ifdef F_34
V_43 = F_35 ( V_52 , V_51 ) ;
#else
if ( F_36 ( V_51 ) != F_36 ( V_54 ) )
V_43 = F_37 ( & V_52 , 1 , 0 , V_51 ) ;
else
V_43 = F_38 ( V_52 ) ;
#endif
if ( ! V_43 )
return - V_42 ;
F_39 ( V_43 , V_44 , V_50 ) ;
#ifdef F_34
F_40 ( V_43 ) ;
#else
if ( F_36 ( V_51 ) != F_36 ( V_54 ) )
F_41 ( V_43 ) ;
else
F_42 ( V_52 ) ;
#endif
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , void * V_43 ,
unsigned long V_45 ,
T_2 V_51 )
{
struct V_45 * V_55 = V_9 -> V_53 [ V_45 ] ;
void * V_44 ;
if ( ! V_55 )
return - V_42 ;
V_43 = ( void * ) ( ( unsigned long ) V_43 + ( V_45 << V_47 ) ) ;
#ifdef F_34
V_44 = F_35 ( V_55 , V_51 ) ;
#else
if ( F_36 ( V_51 ) != F_36 ( V_54 ) )
V_44 = F_37 ( & V_55 , 1 , 0 , V_51 ) ;
else
V_44 = F_38 ( V_55 ) ;
#endif
if ( ! V_44 )
return - V_42 ;
F_44 ( V_43 , V_44 , V_50 ) ;
#ifdef F_34
F_40 ( V_44 ) ;
#else
if ( F_36 ( V_51 ) != F_36 ( V_54 ) )
F_41 ( V_44 ) ;
else
F_42 ( V_55 ) ;
#endif
return 0 ;
}
int F_45 ( struct V_1 * V_2 ,
bool V_4 , bool V_5 ,
struct V_6 * V_7 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_18 * V_19 = & V_27 -> V_19 [ V_7 -> V_12 ] ;
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 * V_10 = & V_2 -> V_3 ;
struct V_6 V_56 = * V_10 ;
void * V_57 ;
void * V_58 ;
int V_11 ;
unsigned long V_49 ;
unsigned long V_45 ;
unsigned long V_59 = 0 ;
int V_60 ;
V_11 = F_25 ( V_27 , V_10 , & V_57 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_25 ( V_27 , V_7 , & V_58 ) ;
if ( V_11 )
goto V_61;
if ( V_57 == NULL && V_58 == NULL )
goto V_62;
if ( V_57 == NULL &&
( V_9 == NULL || ( V_9 -> V_63 == V_64 &&
! ( V_9 -> V_65 & V_66 ) ) ) ) {
F_46 ( V_58 , 0 , V_7 -> V_67 * V_50 ) ;
goto V_62;
}
if ( V_9 && V_9 -> V_63 == V_64 ) {
V_11 = V_9 -> V_27 -> V_28 -> V_68 ( V_9 ) ;
if ( V_11 )
goto V_69;
}
V_59 = 0 ;
V_60 = 1 ;
if ( ( V_10 -> V_12 == V_7 -> V_12 ) &&
( V_7 -> V_70 < V_10 -> V_70 + V_10 -> V_41 ) ) {
V_60 = - 1 ;
V_59 = V_7 -> V_67 - 1 ;
}
for ( V_49 = 0 ; V_49 < V_7 -> V_67 ; ++ V_49 ) {
V_45 = V_49 * V_60 + V_59 ;
if ( V_57 == NULL ) {
T_2 V_51 = F_47 ( V_10 -> V_14 ,
V_54 ) ;
V_11 = F_43 ( V_9 , V_58 , V_45 ,
V_51 ) ;
} else if ( V_58 == NULL ) {
T_2 V_51 = F_47 ( V_7 -> V_14 ,
V_54 ) ;
V_11 = F_33 ( V_9 , V_57 , V_45 ,
V_51 ) ;
} else
V_11 = F_30 ( V_58 , V_57 , V_45 ) ;
if ( V_11 )
goto V_69;
}
F_48 () ;
V_62:
V_56 = * V_10 ;
* V_10 = * V_7 ;
V_7 -> V_17 = NULL ;
if ( ( V_19 -> V_71 & V_72 ) && ( V_9 != NULL ) ) {
F_4 ( V_9 ) ;
F_49 ( V_9 ) ;
V_2 -> V_9 = NULL ;
}
V_69:
F_28 ( V_27 , V_10 , V_58 ) ;
V_61:
F_28 ( V_27 , & V_56 , V_57 ) ;
if ( ! V_11 )
F_2 ( V_2 , & V_56 ) ;
return V_11 ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_1 * * V_73 )
{
struct V_1 * V_74 ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_75 * V_28 = V_27 -> V_28 ;
int V_11 ;
V_74 = F_53 ( sizeof( * V_74 ) , V_76 ) ;
if ( ! V_74 )
return - V_42 ;
* V_74 = * V_2 ;
F_54 ( & V_74 -> V_77 ) ;
F_54 ( & V_74 -> V_78 ) ;
F_54 ( & V_74 -> V_79 ) ;
F_54 ( & V_74 -> V_24 ) ;
F_55 ( & V_74 -> V_80 ) ;
F_56 ( & V_74 -> V_81 , 0 ) ;
F_57 ( & V_27 -> V_82 ) ;
if ( V_2 -> V_83 )
V_74 -> V_83 = V_28 -> V_84 ( V_2 -> V_83 ) ;
else
V_74 -> V_83 = NULL ;
F_58 ( & V_27 -> V_82 ) ;
F_59 ( & V_74 -> V_85 ) ;
F_59 ( & V_74 -> V_86 ) ;
V_74 -> V_87 = & F_50 ;
V_74 -> V_88 = 0 ;
V_74 -> V_89 = & V_74 -> V_90 ;
F_60 ( V_74 -> V_89 ) ;
V_11 = F_61 ( & V_74 -> V_89 -> V_91 ) ;
F_62 ( ! V_11 ) ;
* V_73 = V_74 ;
return 0 ;
}
T_2 F_47 ( T_1 V_92 , T_2 V_93 )
{
#if F_63 ( V_94 ) || F_63 ( V_95 )
if ( V_92 & V_38 )
V_93 = F_64 ( V_93 ) ;
else if ( V_96 . V_97 > 3 )
V_93 = F_65 ( V_93 ) ;
#elif F_63 ( V_98 )
if ( ! ( V_92 & V_99 ) ) {
F_36 ( V_93 ) |= V_100 ;
if ( V_92 & V_101 )
F_36 ( V_93 ) |= V_102 ;
}
#endif
#if F_63 ( V_103 )
if ( V_92 & V_38 )
V_93 = F_64 ( V_93 ) ;
else
V_93 = F_65 ( V_93 ) ;
#endif
#if F_63 ( V_104 ) || F_63 ( V_105 )
if ( ! ( V_92 & V_99 ) )
V_93 = F_65 ( V_93 ) ;
#endif
return V_93 ;
}
static int F_66 ( struct V_1 * V_2 ,
unsigned long V_40 ,
unsigned long V_41 ,
struct V_106 * V_107 )
{
struct V_6 * V_3 = & V_2 -> V_3 ;
if ( V_2 -> V_3 . V_30 . V_36 ) {
V_107 -> V_108 = V_109 ;
V_107 -> V_35 = ( void * ) ( ( ( V_110 * ) V_2 -> V_3 . V_30 . V_36 ) + V_40 ) ;
} else {
V_107 -> V_108 = V_111 ;
if ( V_3 -> V_14 & V_38 )
V_107 -> V_35 = F_26 ( V_2 -> V_3 . V_30 . V_39 + V_2 -> V_3 . V_30 . V_40 + V_40 ,
V_41 ) ;
else
V_107 -> V_35 = F_27 ( V_2 -> V_3 . V_30 . V_39 + V_2 -> V_3 . V_30 . V_40 + V_40 ,
V_41 ) ;
}
return ( ! V_107 -> V_35 ) ? - V_42 : 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned long V_112 ,
unsigned long V_67 ,
struct V_106 * V_107 )
{
struct V_6 * V_3 = & V_2 -> V_3 ; T_2 V_51 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_11 ;
F_68 ( ! V_9 ) ;
if ( V_9 -> V_63 == V_64 ) {
V_11 = V_9 -> V_27 -> V_28 -> V_68 ( V_9 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_67 == 1 && ( V_3 -> V_14 & V_99 ) ) {
V_107 -> V_108 = V_113 ;
V_107 -> V_45 = V_9 -> V_53 [ V_112 ] ;
V_107 -> V_35 = F_38 ( V_107 -> V_45 ) ;
} else {
V_51 = ( V_3 -> V_14 & V_99 ) ?
V_54 :
F_47 ( V_3 -> V_14 , V_54 ) ;
V_107 -> V_108 = V_114 ;
V_107 -> V_35 = F_37 ( V_9 -> V_53 + V_112 , V_67 ,
0 , V_51 ) ;
}
return ( ! V_107 -> V_35 ) ? - V_42 : 0 ;
}
int F_69 ( struct V_1 * V_2 ,
unsigned long V_112 , unsigned long V_67 ,
struct V_106 * V_107 )
{
struct V_18 * V_19 =
& V_2 -> V_27 -> V_19 [ V_2 -> V_3 . V_12 ] ;
unsigned long V_40 , V_41 ;
int V_11 ;
F_68 ( ! F_16 ( & V_2 -> V_79 ) ) ;
V_107 -> V_35 = NULL ;
V_107 -> V_2 = V_2 ;
if ( V_67 > V_2 -> V_67 )
return - V_115 ;
if ( V_112 > V_2 -> V_67 )
return - V_115 ;
#if 0
if (num_pages > 1 && !DRM_SUSER(DRM_CURPROC))
return -EPERM;
#endif
( void ) F_9 ( V_19 , false ) ;
V_11 = F_20 ( V_2 -> V_27 , & V_2 -> V_3 ) ;
F_13 ( V_19 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_2 -> V_3 . V_30 . V_37 ) {
return F_67 ( V_2 , V_112 , V_67 , V_107 ) ;
} else {
V_40 = V_112 << V_47 ;
V_41 = V_67 << V_47 ;
return F_66 ( V_2 , V_40 , V_41 , V_107 ) ;
}
}
void F_70 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_18 * V_19 =
& V_2 -> V_27 -> V_19 [ V_2 -> V_3 . V_12 ] ;
if ( ! V_107 -> V_35 )
return;
switch ( V_107 -> V_108 ) {
case V_111 :
F_29 ( V_107 -> V_35 ) ;
break;
case V_114 :
F_41 ( V_107 -> V_35 ) ;
break;
case V_113 :
F_42 ( V_107 -> V_45 ) ;
break;
case V_109 :
break;
default:
F_71 () ;
}
( void ) F_9 ( V_19 , false ) ;
F_21 ( V_107 -> V_2 -> V_27 , & V_107 -> V_2 -> V_3 ) ;
F_13 ( V_19 ) ;
V_107 -> V_35 = NULL ;
V_107 -> V_45 = NULL ;
}
int F_72 ( struct V_1 * V_2 ,
void * V_83 ,
bool V_4 ,
bool V_5 ,
struct V_6 * V_7 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_75 * V_28 = V_27 -> V_28 ;
struct V_18 * V_19 = & V_27 -> V_19 [ V_7 -> V_12 ] ;
struct V_6 * V_10 = & V_2 -> V_3 ;
int V_11 ;
struct V_1 * V_116 ;
void * V_117 = NULL ;
F_57 ( & V_27 -> V_82 ) ;
if ( V_2 -> V_83 ) {
V_117 = V_2 -> V_83 ;
V_2 -> V_83 = NULL ;
}
V_2 -> V_83 = V_28 -> V_84 ( V_83 ) ;
if ( V_4 ) {
V_11 = F_73 ( V_2 , false , false , false ) ;
F_58 ( & V_27 -> V_82 ) ;
if ( V_117 )
V_28 -> V_118 ( & V_117 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_19 -> V_71 & V_72 ) &&
( V_2 -> V_9 != NULL ) ) {
F_4 ( V_2 -> V_9 ) ;
F_49 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_1 ( V_2 ) ;
} else {
F_74 ( V_119 , & V_2 -> V_120 ) ;
F_58 ( & V_27 -> V_82 ) ;
if ( V_117 )
V_28 -> V_118 ( & V_117 ) ;
V_11 = F_52 ( V_2 , & V_116 ) ;
if ( V_11 )
return V_11 ;
if ( ! ( V_19 -> V_71 & V_72 ) )
V_116 -> V_9 = NULL ;
else
V_2 -> V_9 = NULL ;
F_75 ( V_116 ) ;
F_76 ( & V_116 ) ;
}
* V_10 = * V_7 ;
V_7 -> V_17 = NULL ;
return 0 ;
}
