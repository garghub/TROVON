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
if ( V_57 == NULL && V_9 == NULL )
goto V_62;
if ( V_9 -> V_63 == V_64 ) {
V_11 = V_9 -> V_27 -> V_28 -> V_65 ( V_9 ) ;
if ( V_11 ) {
V_56 . V_17 = NULL ;
goto V_66;
}
}
V_59 = 0 ;
V_60 = 1 ;
if ( ( V_10 -> V_12 == V_7 -> V_12 ) &&
( V_7 -> V_67 < V_10 -> V_67 + V_10 -> V_41 ) ) {
V_60 = - 1 ;
V_59 = V_7 -> V_68 - 1 ;
}
for ( V_49 = 0 ; V_49 < V_7 -> V_68 ; ++ V_49 ) {
V_45 = V_49 * V_60 + V_59 ;
if ( V_57 == NULL ) {
T_2 V_51 = F_46 ( V_10 -> V_14 ,
V_54 ) ;
V_11 = F_43 ( V_9 , V_58 , V_45 ,
V_51 ) ;
} else if ( V_58 == NULL ) {
T_2 V_51 = F_46 ( V_7 -> V_14 ,
V_54 ) ;
V_11 = F_33 ( V_9 , V_57 , V_45 ,
V_51 ) ;
} else
V_11 = F_30 ( V_58 , V_57 , V_45 ) ;
if ( V_11 ) {
V_56 . V_17 = NULL ;
goto V_66;
}
}
F_47 () ;
V_62:
V_56 = * V_10 ;
* V_10 = * V_7 ;
V_7 -> V_17 = NULL ;
if ( ( V_19 -> V_69 & V_70 ) && ( V_9 != NULL ) ) {
F_4 ( V_9 ) ;
F_48 ( V_9 ) ;
V_2 -> V_9 = NULL ;
}
V_66:
F_28 ( V_27 , V_10 , V_58 ) ;
V_61:
F_28 ( V_27 , & V_56 , V_57 ) ;
F_2 ( V_2 , & V_56 ) ;
return V_11 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_1 * * V_71 )
{
struct V_1 * V_72 ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_73 * V_28 = V_27 -> V_28 ;
int V_11 ;
V_72 = F_52 ( sizeof( * V_72 ) , V_74 ) ;
if ( ! V_72 )
return - V_42 ;
* V_72 = * V_2 ;
F_53 ( & V_72 -> V_75 ) ;
F_53 ( & V_72 -> V_76 ) ;
F_53 ( & V_72 -> V_77 ) ;
F_53 ( & V_72 -> V_24 ) ;
V_72 -> V_78 = NULL ;
F_54 ( & V_72 -> V_79 , 0 ) ;
F_55 ( & V_27 -> V_80 ) ;
if ( V_2 -> V_81 )
V_72 -> V_81 = V_28 -> V_82 ( V_2 -> V_81 ) ;
else
V_72 -> V_81 = NULL ;
F_56 ( & V_27 -> V_80 ) ;
F_57 ( & V_72 -> V_83 ) ;
F_57 ( & V_72 -> V_84 ) ;
V_72 -> V_85 = & F_49 ;
V_72 -> V_86 = 0 ;
V_72 -> V_87 = & V_72 -> V_88 ;
F_58 ( V_72 -> V_87 ) ;
V_11 = F_59 ( & V_72 -> V_87 -> V_89 ) ;
F_60 ( ! V_11 ) ;
* V_71 = V_72 ;
return 0 ;
}
T_2 F_46 ( T_1 V_90 , T_2 V_91 )
{
#if F_61 ( V_92 ) || F_61 ( V_93 )
if ( V_90 & V_38 )
V_91 = F_62 ( V_91 ) ;
else if ( V_94 . V_95 > 3 )
V_91 = F_63 ( V_91 ) ;
#elif F_61 ( V_96 )
if ( ! ( V_90 & V_97 ) ) {
F_36 ( V_91 ) |= V_98 ;
if ( V_90 & V_99 )
F_36 ( V_91 ) |= V_100 ;
}
#endif
#if F_61 ( V_101 )
if ( V_90 & V_38 )
V_91 = F_62 ( V_91 ) ;
else
V_91 = F_63 ( V_91 ) ;
#endif
#if F_61 ( V_102 ) || F_61 ( V_103 )
if ( ! ( V_90 & V_97 ) )
V_91 = F_63 ( V_91 ) ;
#endif
return V_91 ;
}
static int F_64 ( struct V_1 * V_2 ,
unsigned long V_40 ,
unsigned long V_41 ,
struct V_104 * V_105 )
{
struct V_6 * V_3 = & V_2 -> V_3 ;
if ( V_2 -> V_3 . V_30 . V_36 ) {
V_105 -> V_106 = V_107 ;
V_105 -> V_35 = ( void * ) ( ( ( V_108 * ) V_2 -> V_3 . V_30 . V_36 ) + V_40 ) ;
} else {
V_105 -> V_106 = V_109 ;
if ( V_3 -> V_14 & V_38 )
V_105 -> V_35 = F_26 ( V_2 -> V_3 . V_30 . V_39 + V_2 -> V_3 . V_30 . V_40 + V_40 ,
V_41 ) ;
else
V_105 -> V_35 = F_27 ( V_2 -> V_3 . V_30 . V_39 + V_2 -> V_3 . V_30 . V_40 + V_40 ,
V_41 ) ;
}
return ( ! V_105 -> V_35 ) ? - V_42 : 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
unsigned long V_110 ,
unsigned long V_68 ,
struct V_104 * V_105 )
{
struct V_6 * V_3 = & V_2 -> V_3 ; T_2 V_51 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_11 ;
F_66 ( ! V_9 ) ;
if ( V_9 -> V_63 == V_64 ) {
V_11 = V_9 -> V_27 -> V_28 -> V_65 ( V_9 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_68 == 1 && ( V_3 -> V_14 & V_97 ) ) {
V_105 -> V_106 = V_111 ;
V_105 -> V_45 = V_9 -> V_53 [ V_110 ] ;
V_105 -> V_35 = F_38 ( V_105 -> V_45 ) ;
} else {
V_51 = ( V_3 -> V_14 & V_97 ) ?
V_54 :
F_46 ( V_3 -> V_14 , V_54 ) ;
V_105 -> V_106 = V_112 ;
V_105 -> V_35 = F_37 ( V_9 -> V_53 + V_110 , V_68 ,
0 , V_51 ) ;
}
return ( ! V_105 -> V_35 ) ? - V_42 : 0 ;
}
int F_67 ( struct V_1 * V_2 ,
unsigned long V_110 , unsigned long V_68 ,
struct V_104 * V_105 )
{
struct V_18 * V_19 =
& V_2 -> V_27 -> V_19 [ V_2 -> V_3 . V_12 ] ;
unsigned long V_40 , V_41 ;
int V_11 ;
F_66 ( ! F_16 ( & V_2 -> V_77 ) ) ;
V_105 -> V_35 = NULL ;
V_105 -> V_2 = V_2 ;
if ( V_68 > V_2 -> V_68 )
return - V_113 ;
if ( V_110 > V_2 -> V_68 )
return - V_113 ;
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
return F_65 ( V_2 , V_110 , V_68 , V_105 ) ;
} else {
V_40 = V_110 << V_47 ;
V_41 = V_68 << V_47 ;
return F_64 ( V_2 , V_40 , V_41 , V_105 ) ;
}
}
void F_68 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_18 * V_19 =
& V_2 -> V_27 -> V_19 [ V_2 -> V_3 . V_12 ] ;
if ( ! V_105 -> V_35 )
return;
switch ( V_105 -> V_106 ) {
case V_109 :
F_29 ( V_105 -> V_35 ) ;
break;
case V_112 :
F_41 ( V_105 -> V_35 ) ;
break;
case V_111 :
F_42 ( V_105 -> V_45 ) ;
break;
case V_107 :
break;
default:
F_69 () ;
}
( void ) F_9 ( V_19 , false ) ;
F_21 ( V_105 -> V_2 -> V_27 , & V_105 -> V_2 -> V_3 ) ;
F_13 ( V_19 ) ;
V_105 -> V_35 = NULL ;
V_105 -> V_45 = NULL ;
}
int F_70 ( struct V_1 * V_2 ,
void * V_81 ,
bool V_4 ,
bool V_5 ,
struct V_6 * V_7 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_73 * V_28 = V_27 -> V_28 ;
struct V_18 * V_19 = & V_27 -> V_19 [ V_7 -> V_12 ] ;
struct V_6 * V_10 = & V_2 -> V_3 ;
int V_11 ;
struct V_1 * V_114 ;
void * V_115 = NULL ;
F_55 ( & V_27 -> V_80 ) ;
if ( V_2 -> V_81 ) {
V_115 = V_2 -> V_81 ;
V_2 -> V_81 = NULL ;
}
V_2 -> V_81 = V_28 -> V_82 ( V_81 ) ;
if ( V_4 ) {
V_11 = F_71 ( V_2 , false , false , false ) ;
F_56 ( & V_27 -> V_80 ) ;
if ( V_115 )
V_28 -> V_116 ( & V_115 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_19 -> V_69 & V_70 ) &&
( V_2 -> V_9 != NULL ) ) {
F_4 ( V_2 -> V_9 ) ;
F_48 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_1 ( V_2 ) ;
} else {
F_72 ( V_117 , & V_2 -> V_118 ) ;
F_56 ( & V_27 -> V_80 ) ;
if ( V_115 )
V_28 -> V_116 ( & V_115 ) ;
V_11 = F_51 ( V_2 , & V_114 ) ;
if ( V_11 )
return V_11 ;
if ( ! ( V_19 -> V_69 & V_70 ) )
V_114 -> V_9 = NULL ;
else
V_2 -> V_9 = NULL ;
F_73 ( V_114 ) ;
F_74 ( & V_114 ) ;
}
* V_10 = * V_7 ;
V_7 -> V_17 = NULL ;
return 0 ;
}
