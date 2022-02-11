void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , & V_2 -> V_3 ) ;
}
int F_3 ( struct V_1 * V_2 ,
bool V_4 , bool V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_6 * V_10 = & V_2 -> V_3 ;
int V_11 ;
if ( V_10 -> V_12 != V_13 ) {
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
if ( F_5 ( V_11 != 0 ) ) {
if ( V_11 != - V_14 )
F_6 ( L_1 ) ;
return V_11 ;
}
F_7 ( V_9 ) ;
F_1 ( V_2 ) ;
F_8 ( & V_10 -> V_15 , V_16 ,
V_17 ) ;
V_10 -> V_12 = V_13 ;
}
V_11 = F_9 ( V_9 , V_7 -> V_15 ) ;
if ( F_5 ( V_11 != 0 ) )
return V_11 ;
if ( V_7 -> V_12 != V_13 ) {
V_11 = F_10 ( V_9 , V_7 ) ;
if ( F_5 ( V_11 != 0 ) )
return V_11 ;
}
* V_10 = * V_7 ;
V_7 -> V_18 = NULL ;
return 0 ;
}
int F_11 ( struct V_19 * V_20 , bool V_4 )
{
if ( F_12 ( V_20 -> V_21 ) )
return 0 ;
if ( V_4 )
return F_13 ( & V_20 -> V_22 ) ;
F_14 ( & V_20 -> V_22 ) ;
return 0 ;
}
void F_15 ( struct V_19 * V_20 )
{
if ( F_12 ( V_20 -> V_21 ) )
return;
F_16 ( & V_20 -> V_22 ) ;
}
static int F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
if ( ! V_20 -> V_23 || F_18 ( & V_20 -> V_24 ) )
return - V_25 ;
V_2 = F_19 ( & V_20 -> V_24 ,
struct V_1 ,
V_24 ) ;
F_20 ( & V_2 -> V_24 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
int F_22 ( struct V_26 * V_27 ,
struct V_6 * V_3 )
{
struct V_19 * V_20 = & V_27 -> V_20 [ V_3 -> V_12 ] ;
int V_11 = 0 ;
if ( ! V_27 -> V_28 -> V_29 )
return 0 ;
if ( F_12 ( V_20 -> V_21 ) )
return V_27 -> V_28 -> V_29 ( V_27 , V_3 ) ;
if ( V_27 -> V_28 -> V_29 &&
V_3 -> V_30 . V_31 ++ == 0 ) {
V_32:
V_11 = V_27 -> V_28 -> V_29 ( V_27 , V_3 ) ;
if ( V_11 == - V_25 ) {
V_11 = F_17 ( V_20 ) ;
if ( V_11 == 0 )
goto V_32;
}
}
return V_11 ;
}
void F_23 ( struct V_26 * V_27 ,
struct V_6 * V_3 )
{
struct V_19 * V_20 = & V_27 -> V_20 [ V_3 -> V_12 ] ;
if ( F_12 ( V_20 -> V_21 ) )
return;
if ( V_27 -> V_28 -> V_29 &&
-- V_3 -> V_30 . V_31 == 0 &&
V_27 -> V_28 -> V_33 )
V_27 -> V_28 -> V_33 ( V_27 , V_3 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_3 = & V_2 -> V_3 ;
int V_11 ;
if ( ! V_3 -> V_30 . V_34 ) {
struct V_19 * V_20 =
& V_2 -> V_27 -> V_20 [ V_3 -> V_12 ] ;
V_11 = F_22 ( V_2 -> V_27 , V_3 ) ;
if ( F_5 ( V_11 != 0 ) )
return V_11 ;
V_3 -> V_30 . V_34 = true ;
if ( V_20 -> V_23 )
F_25 ( & V_2 -> V_24 ,
& V_20 -> V_24 ) ;
}
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_3 = & V_2 -> V_3 ;
if ( V_3 -> V_30 . V_34 ) {
V_3 -> V_30 . V_34 = false ;
F_20 ( & V_2 -> V_24 ) ;
F_23 ( V_2 -> V_27 , V_3 ) ;
}
}
static int F_27 ( struct V_26 * V_27 , struct V_6 * V_3 ,
void * * V_35 )
{
struct V_19 * V_20 = & V_27 -> V_20 [ V_3 -> V_12 ] ;
int V_11 ;
void * V_36 ;
* V_35 = NULL ;
( void ) F_11 ( V_20 , false ) ;
V_11 = F_22 ( V_27 , V_3 ) ;
F_15 ( V_20 ) ;
if ( V_11 || ! V_3 -> V_30 . V_37 )
return V_11 ;
if ( V_3 -> V_30 . V_36 ) {
V_36 = V_3 -> V_30 . V_36 ;
} else {
if ( V_3 -> V_15 & V_38 )
V_36 = F_28 ( V_3 -> V_30 . V_39 + V_3 -> V_30 . V_40 , V_3 -> V_30 . V_41 ) ;
else
V_36 = F_29 ( V_3 -> V_30 . V_39 + V_3 -> V_30 . V_40 , V_3 -> V_30 . V_41 ) ;
if ( ! V_36 ) {
( void ) F_11 ( V_20 , false ) ;
F_23 ( V_27 , V_3 ) ;
F_15 ( V_20 ) ;
return - V_42 ;
}
}
* V_35 = V_36 ;
return 0 ;
}
static void F_30 ( struct V_26 * V_27 , struct V_6 * V_3 ,
void * V_35 )
{
struct V_19 * V_20 ;
V_20 = & V_27 -> V_20 [ V_3 -> V_12 ] ;
if ( V_35 && V_3 -> V_30 . V_36 == NULL )
F_31 ( V_35 ) ;
( void ) F_11 ( V_20 , false ) ;
F_23 ( V_27 , V_3 ) ;
F_15 ( V_20 ) ;
}
static int F_32 ( void * V_43 , void * V_44 , unsigned long V_45 )
{
T_1 * V_46 =
( T_1 * ) ( ( unsigned long ) V_43 + ( V_45 << V_47 ) ) ;
T_1 * V_48 =
( T_1 * ) ( ( unsigned long ) V_44 + ( V_45 << V_47 ) ) ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_50 / sizeof( T_1 ) ; ++ V_49 )
F_33 ( F_34 ( V_48 ++ ) , V_46 ++ ) ;
return 0 ;
}
static int F_35 ( struct V_8 * V_9 , void * V_44 ,
unsigned long V_45 ,
T_2 V_51 )
{
struct V_45 * V_52 = V_9 -> V_53 [ V_45 ] ;
void * V_43 ;
if ( ! V_52 )
return - V_42 ;
V_44 = ( void * ) ( ( unsigned long ) V_44 + ( V_45 << V_47 ) ) ;
#ifdef F_36
V_43 = F_37 ( V_52 , V_51 ) ;
#else
if ( F_38 ( V_51 ) != F_38 ( V_54 ) )
V_43 = F_39 ( & V_52 , 1 , 0 , V_51 ) ;
else
V_43 = F_40 ( V_52 ) ;
#endif
if ( ! V_43 )
return - V_42 ;
F_41 ( V_43 , V_44 , V_50 ) ;
#ifdef F_36
F_42 ( V_43 ) ;
#else
if ( F_38 ( V_51 ) != F_38 ( V_54 ) )
F_43 ( V_43 ) ;
else
F_44 ( V_52 ) ;
#endif
return 0 ;
}
static int F_45 ( struct V_8 * V_9 , void * V_43 ,
unsigned long V_45 ,
T_2 V_51 )
{
struct V_45 * V_55 = V_9 -> V_53 [ V_45 ] ;
void * V_44 ;
if ( ! V_55 )
return - V_42 ;
V_43 = ( void * ) ( ( unsigned long ) V_43 + ( V_45 << V_47 ) ) ;
#ifdef F_36
V_44 = F_37 ( V_55 , V_51 ) ;
#else
if ( F_38 ( V_51 ) != F_38 ( V_54 ) )
V_44 = F_39 ( & V_55 , 1 , 0 , V_51 ) ;
else
V_44 = F_40 ( V_55 ) ;
#endif
if ( ! V_44 )
return - V_42 ;
F_46 ( V_43 , V_44 , V_50 ) ;
#ifdef F_36
F_42 ( V_44 ) ;
#else
if ( F_38 ( V_51 ) != F_38 ( V_54 ) )
F_43 ( V_44 ) ;
else
F_44 ( V_55 ) ;
#endif
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
bool V_4 , bool V_5 ,
struct V_6 * V_7 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_19 * V_20 = & V_27 -> V_20 [ V_7 -> V_12 ] ;
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
V_11 = F_4 ( V_2 , V_4 , V_5 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_27 ( V_27 , V_10 , & V_57 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_27 ( V_27 , V_7 , & V_58 ) ;
if ( V_11 )
goto V_61;
if ( V_57 == NULL && V_58 == NULL )
goto V_62;
if ( V_57 == NULL &&
( V_9 == NULL || ( V_9 -> V_63 == V_64 &&
! ( V_9 -> V_65 & V_66 ) ) ) ) {
F_48 ( V_58 , 0 , V_7 -> V_67 * V_50 ) ;
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
T_2 V_51 = F_49 ( V_10 -> V_15 ,
V_54 ) ;
V_11 = F_45 ( V_9 , V_58 , V_45 ,
V_51 ) ;
} else if ( V_58 == NULL ) {
T_2 V_51 = F_49 ( V_7 -> V_15 ,
V_54 ) ;
V_11 = F_35 ( V_9 , V_57 , V_45 ,
V_51 ) ;
} else
V_11 = F_32 ( V_58 , V_57 , V_45 ) ;
if ( V_11 )
goto V_69;
}
F_50 () ;
V_62:
V_56 = * V_10 ;
* V_10 = * V_7 ;
V_7 -> V_18 = NULL ;
if ( V_20 -> V_71 & V_72 ) {
F_51 ( V_9 ) ;
V_2 -> V_9 = NULL ;
}
V_69:
F_30 ( V_27 , V_10 , V_58 ) ;
V_61:
F_30 ( V_27 , & V_56 , V_57 ) ;
if ( ! V_11 )
F_2 ( V_2 , & V_56 ) ;
return V_11 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_1 * * V_73 )
{
struct V_1 * V_74 ;
int V_11 ;
V_74 = F_55 ( sizeof( * V_74 ) , V_75 ) ;
if ( ! V_74 )
return - V_42 ;
* V_74 = * V_2 ;
F_56 ( & V_2 -> V_76 -> V_77 ) ;
F_57 ( & V_74 -> V_78 ) ;
F_57 ( & V_74 -> V_79 ) ;
F_57 ( & V_74 -> V_80 ) ;
F_57 ( & V_74 -> V_24 ) ;
V_74 -> V_81 = NULL ;
F_58 ( & V_74 -> V_82 ) ;
F_59 ( & V_74 -> V_83 , 0 ) ;
F_60 ( & V_74 -> V_84 ) ;
F_60 ( & V_74 -> V_85 ) ;
V_74 -> V_86 = & F_52 ;
V_74 -> V_87 = 0 ;
V_74 -> V_88 = & V_74 -> V_89 ;
F_61 ( V_74 -> V_88 ) ;
V_11 = F_62 ( & V_74 -> V_88 -> V_90 ) ;
F_63 ( ! V_11 ) ;
* V_73 = V_74 ;
return 0 ;
}
T_2 F_49 ( T_1 V_91 , T_2 V_92 )
{
if ( V_91 & V_93 )
return V_92 ;
#if F_64 ( V_94 ) || F_64 ( V_95 )
if ( V_91 & V_38 )
V_92 = F_65 ( V_92 ) ;
else if ( V_96 . V_97 > 3 )
V_92 = F_66 ( V_92 ) ;
#endif
#if F_64 ( V_98 ) || F_64 ( V_99 ) || F_64 ( V_100 ) || \
F_64 ( V_101 )
if ( V_91 & V_38 )
V_92 = F_65 ( V_92 ) ;
else
V_92 = F_66 ( V_92 ) ;
#endif
#if F_64 ( V_102 ) || F_64 ( V_103 )
V_92 = F_66 ( V_92 ) ;
#endif
return V_92 ;
}
static int F_67 ( struct V_1 * V_2 ,
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
if ( V_3 -> V_15 & V_38 )
V_105 -> V_35 = F_28 ( V_2 -> V_3 . V_30 . V_39 + V_2 -> V_3 . V_30 . V_40 + V_40 ,
V_41 ) ;
else
V_105 -> V_35 = F_29 ( V_2 -> V_3 . V_30 . V_39 + V_2 -> V_3 . V_30 . V_40 + V_40 ,
V_41 ) ;
}
return ( ! V_105 -> V_35 ) ? - V_42 : 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
unsigned long V_110 ,
unsigned long V_67 ,
struct V_104 * V_105 )
{
struct V_6 * V_3 = & V_2 -> V_3 ; T_2 V_51 ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_11 ;
F_69 ( ! V_9 ) ;
if ( V_9 -> V_63 == V_64 ) {
V_11 = V_9 -> V_27 -> V_28 -> V_68 ( V_9 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_67 == 1 && ( V_3 -> V_15 & V_93 ) ) {
V_105 -> V_106 = V_111 ;
V_105 -> V_45 = V_9 -> V_53 [ V_110 ] ;
V_105 -> V_35 = F_40 ( V_105 -> V_45 ) ;
} else {
V_51 = F_49 ( V_3 -> V_15 , V_54 ) ;
V_105 -> V_106 = V_112 ;
V_105 -> V_35 = F_39 ( V_9 -> V_53 + V_110 , V_67 ,
0 , V_51 ) ;
}
return ( ! V_105 -> V_35 ) ? - V_42 : 0 ;
}
int F_70 ( struct V_1 * V_2 ,
unsigned long V_110 , unsigned long V_67 ,
struct V_104 * V_105 )
{
struct V_19 * V_20 =
& V_2 -> V_27 -> V_20 [ V_2 -> V_3 . V_12 ] ;
unsigned long V_40 , V_41 ;
int V_11 ;
F_69 ( ! F_18 ( & V_2 -> V_80 ) ) ;
V_105 -> V_35 = NULL ;
V_105 -> V_2 = V_2 ;
if ( V_67 > V_2 -> V_67 )
return - V_113 ;
if ( V_110 > V_2 -> V_67 )
return - V_113 ;
#if 0
if (num_pages > 1 && !capable(CAP_SYS_ADMIN))
return -EPERM;
#endif
( void ) F_11 ( V_20 , false ) ;
V_11 = F_22 ( V_2 -> V_27 , & V_2 -> V_3 ) ;
F_15 ( V_20 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_2 -> V_3 . V_30 . V_37 ) {
return F_68 ( V_2 , V_110 , V_67 , V_105 ) ;
} else {
V_40 = V_110 << V_47 ;
V_41 = V_67 << V_47 ;
return F_67 ( V_2 , V_40 , V_41 , V_105 ) ;
}
}
void F_71 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_19 * V_20 =
& V_2 -> V_27 -> V_20 [ V_2 -> V_3 . V_12 ] ;
if ( ! V_105 -> V_35 )
return;
switch ( V_105 -> V_106 ) {
case V_109 :
F_31 ( V_105 -> V_35 ) ;
break;
case V_112 :
F_43 ( V_105 -> V_35 ) ;
break;
case V_111 :
F_44 ( V_105 -> V_45 ) ;
break;
case V_107 :
break;
default:
F_72 () ;
}
( void ) F_11 ( V_20 , false ) ;
F_23 ( V_105 -> V_2 -> V_27 , & V_105 -> V_2 -> V_3 ) ;
F_15 ( V_20 ) ;
V_105 -> V_35 = NULL ;
V_105 -> V_45 = NULL ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
bool V_116 ,
struct V_6 * V_7 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_19 * V_20 = & V_27 -> V_20 [ V_7 -> V_12 ] ;
struct V_6 * V_10 = & V_2 -> V_3 ;
int V_11 ;
struct V_1 * V_117 ;
F_74 ( V_2 -> V_88 , V_115 ) ;
if ( V_116 ) {
V_11 = F_4 ( V_2 , false , false ) ;
if ( V_11 )
return V_11 ;
if ( V_20 -> V_71 & V_72 ) {
F_51 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_1 ( V_2 ) ;
} else {
F_75 ( V_2 -> V_81 ) ;
V_2 -> V_81 = F_76 ( V_115 ) ;
V_11 = F_54 ( V_2 , & V_117 ) ;
if ( V_11 )
return V_11 ;
F_74 ( V_117 -> V_88 , V_115 ) ;
if ( ! ( V_20 -> V_71 & V_72 ) )
V_117 -> V_9 = NULL ;
else
V_2 -> V_9 = NULL ;
F_77 ( V_117 ) ;
F_78 ( & V_117 ) ;
}
* V_10 = * V_7 ;
V_7 -> V_18 = NULL ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_114 * V_115 , bool V_116 ,
struct V_6 * V_7 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_6 * V_10 = & V_2 -> V_3 ;
struct V_19 * V_118 = & V_27 -> V_20 [ V_10 -> V_12 ] ;
struct V_19 * V_119 = & V_27 -> V_20 [ V_7 -> V_12 ] ;
int V_11 ;
F_74 ( V_2 -> V_88 , V_115 ) ;
if ( ! V_116 ) {
struct V_1 * V_117 ;
F_75 ( V_2 -> V_81 ) ;
V_2 -> V_81 = F_76 ( V_115 ) ;
V_11 = F_54 ( V_2 , & V_117 ) ;
if ( V_11 )
return V_11 ;
F_74 ( V_117 -> V_88 , V_115 ) ;
if ( ! ( V_119 -> V_71 & V_72 ) )
V_117 -> V_9 = NULL ;
else
V_2 -> V_9 = NULL ;
F_77 ( V_117 ) ;
F_78 ( & V_117 ) ;
} else if ( V_118 -> V_71 & V_72 ) {
F_80 ( & V_118 -> V_120 ) ;
if ( ! V_118 -> V_121 || F_81 ( V_115 , V_118 -> V_121 ) ) {
F_75 ( V_118 -> V_121 ) ;
V_118 -> V_121 = F_76 ( V_115 ) ;
}
F_82 ( & V_118 -> V_120 ) ;
F_1 ( V_2 ) ;
F_75 ( V_2 -> V_81 ) ;
V_2 -> V_81 = F_76 ( V_115 ) ;
} else {
V_11 = F_4 ( V_2 , false , false ) ;
if ( V_11 )
return V_11 ;
if ( V_119 -> V_71 & V_72 ) {
F_51 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
F_1 ( V_2 ) ;
}
* V_10 = * V_7 ;
V_7 -> V_18 = NULL ;
return 0 ;
}
