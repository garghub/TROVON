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
V_12 = F_4 ( V_2 , V_5 , V_6 ) ;
if ( F_5 ( V_12 != 0 ) ) {
if ( V_12 != - V_15 )
F_6 ( L_1 ) ;
return V_12 ;
}
F_7 ( V_10 ) ;
F_1 ( V_2 ) ;
F_8 ( & V_11 -> V_16 , V_17 ,
V_18 ) ;
V_11 -> V_13 = V_14 ;
}
V_12 = F_9 ( V_10 , V_8 -> V_16 ) ;
if ( F_5 ( V_12 != 0 ) )
return V_12 ;
if ( V_8 -> V_13 != V_14 ) {
V_12 = F_10 ( V_10 , V_8 ) ;
if ( F_5 ( V_12 != 0 ) )
return V_12 ;
}
* V_11 = * V_8 ;
V_8 -> V_19 = NULL ;
return 0 ;
}
int F_11 ( struct V_20 * V_21 , bool V_5 )
{
if ( F_12 ( V_21 -> V_22 ) )
return 0 ;
if ( V_5 )
return F_13 ( & V_21 -> V_23 ) ;
F_14 ( & V_21 -> V_23 ) ;
return 0 ;
}
void F_15 ( struct V_20 * V_21 )
{
if ( F_12 ( V_21 -> V_22 ) )
return;
F_16 ( & V_21 -> V_23 ) ;
}
static int F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_2 ;
if ( ! V_21 -> V_24 || F_18 ( & V_21 -> V_25 ) )
return - V_26 ;
V_2 = F_19 ( & V_21 -> V_25 ,
struct V_1 ,
V_25 ) ;
F_20 ( & V_2 -> V_25 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
int F_22 ( struct V_27 * V_28 ,
struct V_7 * V_3 )
{
struct V_20 * V_21 = & V_28 -> V_21 [ V_3 -> V_13 ] ;
int V_12 = 0 ;
if ( ! V_28 -> V_29 -> V_30 )
return 0 ;
if ( F_12 ( V_21 -> V_22 ) )
return V_28 -> V_29 -> V_30 ( V_28 , V_3 ) ;
if ( V_28 -> V_29 -> V_30 &&
V_3 -> V_31 . V_32 ++ == 0 ) {
V_33:
V_12 = V_28 -> V_29 -> V_30 ( V_28 , V_3 ) ;
if ( V_12 == - V_26 ) {
V_12 = F_17 ( V_21 ) ;
if ( V_12 == 0 )
goto V_33;
}
}
return V_12 ;
}
void F_23 ( struct V_27 * V_28 ,
struct V_7 * V_3 )
{
struct V_20 * V_21 = & V_28 -> V_21 [ V_3 -> V_13 ] ;
if ( F_12 ( V_21 -> V_22 ) )
return;
if ( V_28 -> V_29 -> V_30 &&
-- V_3 -> V_31 . V_32 == 0 &&
V_28 -> V_29 -> V_34 )
V_28 -> V_29 -> V_34 ( V_28 , V_3 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_3 = & V_2 -> V_3 ;
int V_12 ;
if ( ! V_3 -> V_31 . V_35 ) {
struct V_20 * V_21 =
& V_2 -> V_28 -> V_21 [ V_3 -> V_13 ] ;
V_12 = F_22 ( V_2 -> V_28 , V_3 ) ;
if ( F_5 ( V_12 != 0 ) )
return V_12 ;
V_3 -> V_31 . V_35 = true ;
if ( V_21 -> V_24 )
F_25 ( & V_2 -> V_25 ,
& V_21 -> V_25 ) ;
}
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_3 = & V_2 -> V_3 ;
if ( V_3 -> V_31 . V_35 ) {
V_3 -> V_31 . V_35 = false ;
F_20 ( & V_2 -> V_25 ) ;
F_23 ( V_2 -> V_28 , V_3 ) ;
}
}
static int F_27 ( struct V_27 * V_28 , struct V_7 * V_3 ,
void * * V_36 )
{
struct V_20 * V_21 = & V_28 -> V_21 [ V_3 -> V_13 ] ;
int V_12 ;
void * V_37 ;
* V_36 = NULL ;
( void ) F_11 ( V_21 , false ) ;
V_12 = F_22 ( V_28 , V_3 ) ;
F_15 ( V_21 ) ;
if ( V_12 || ! V_3 -> V_31 . V_38 )
return V_12 ;
if ( V_3 -> V_31 . V_37 ) {
V_37 = V_3 -> V_31 . V_37 ;
} else {
if ( V_3 -> V_16 & V_39 )
V_37 = F_28 ( V_3 -> V_31 . V_40 + V_3 -> V_31 . V_41 , V_3 -> V_31 . V_42 ) ;
else
V_37 = F_29 ( V_3 -> V_31 . V_40 + V_3 -> V_31 . V_41 , V_3 -> V_31 . V_42 ) ;
if ( ! V_37 ) {
( void ) F_11 ( V_21 , false ) ;
F_23 ( V_28 , V_3 ) ;
F_15 ( V_21 ) ;
return - V_43 ;
}
}
* V_36 = V_37 ;
return 0 ;
}
static void F_30 ( struct V_27 * V_28 , struct V_7 * V_3 ,
void * V_36 )
{
struct V_20 * V_21 ;
V_21 = & V_28 -> V_21 [ V_3 -> V_13 ] ;
if ( V_36 && V_3 -> V_31 . V_37 == NULL )
F_31 ( V_36 ) ;
( void ) F_11 ( V_21 , false ) ;
F_23 ( V_28 , V_3 ) ;
F_15 ( V_21 ) ;
}
static int F_32 ( void * V_44 , void * V_45 , unsigned long V_46 )
{
T_1 * V_47 =
( T_1 * ) ( ( unsigned long ) V_44 + ( V_46 << V_48 ) ) ;
T_1 * V_49 =
( T_1 * ) ( ( unsigned long ) V_45 + ( V_46 << V_48 ) ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_51 / sizeof( T_1 ) ; ++ V_50 )
F_33 ( F_34 ( V_49 ++ ) , V_47 ++ ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 , void * V_45 ,
unsigned long V_46 ,
T_2 V_52 )
{
struct V_46 * V_53 = V_10 -> V_54 [ V_46 ] ;
void * V_44 ;
if ( ! V_53 )
return - V_43 ;
V_45 = ( void * ) ( ( unsigned long ) V_45 + ( V_46 << V_48 ) ) ;
#ifdef F_36
V_44 = F_37 ( V_53 , V_52 ) ;
#else
if ( F_38 ( V_52 ) != F_38 ( V_55 ) )
V_44 = F_39 ( & V_53 , 1 , 0 , V_52 ) ;
else
V_44 = F_40 ( V_53 ) ;
#endif
if ( ! V_44 )
return - V_43 ;
F_41 ( V_44 , V_45 , V_51 ) ;
#ifdef F_36
F_42 ( V_44 ) ;
#else
if ( F_38 ( V_52 ) != F_38 ( V_55 ) )
F_43 ( V_44 ) ;
else
F_44 ( V_53 ) ;
#endif
return 0 ;
}
static int F_45 ( struct V_9 * V_10 , void * V_44 ,
unsigned long V_46 ,
T_2 V_52 )
{
struct V_46 * V_56 = V_10 -> V_54 [ V_46 ] ;
void * V_45 ;
if ( ! V_56 )
return - V_43 ;
V_44 = ( void * ) ( ( unsigned long ) V_44 + ( V_46 << V_48 ) ) ;
#ifdef F_36
V_45 = F_37 ( V_56 , V_52 ) ;
#else
if ( F_38 ( V_52 ) != F_38 ( V_55 ) )
V_45 = F_39 ( & V_56 , 1 , 0 , V_52 ) ;
else
V_45 = F_40 ( V_56 ) ;
#endif
if ( ! V_45 )
return - V_43 ;
F_46 ( V_44 , V_45 , V_51 ) ;
#ifdef F_36
F_42 ( V_45 ) ;
#else
if ( F_38 ( V_52 ) != F_38 ( V_55 ) )
F_43 ( V_45 ) ;
else
F_44 ( V_56 ) ;
#endif
return 0 ;
}
int F_47 ( struct V_1 * V_2 ,
bool V_4 , bool V_5 ,
bool V_6 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_20 * V_21 = & V_28 -> V_21 [ V_8 -> V_13 ] ;
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
V_12 = F_4 ( V_2 , V_5 , V_6 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_27 ( V_28 , V_11 , & V_58 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_27 ( V_28 , V_8 , & V_59 ) ;
if ( V_12 )
goto V_62;
if ( V_58 == NULL && V_59 == NULL )
goto V_63;
if ( V_58 == NULL &&
( V_10 == NULL || ( V_10 -> V_64 == V_65 &&
! ( V_10 -> V_66 & V_67 ) ) ) ) {
F_48 ( V_59 , 0 , V_8 -> V_68 * V_51 ) ;
goto V_63;
}
if ( V_10 && V_10 -> V_64 == V_65 ) {
V_12 = V_10 -> V_28 -> V_29 -> V_69 ( V_10 ) ;
if ( V_12 )
goto V_70;
}
V_60 = 0 ;
V_61 = 1 ;
if ( ( V_11 -> V_13 == V_8 -> V_13 ) &&
( V_8 -> V_71 < V_11 -> V_71 + V_11 -> V_42 ) ) {
V_61 = - 1 ;
V_60 = V_8 -> V_68 - 1 ;
}
for ( V_50 = 0 ; V_50 < V_8 -> V_68 ; ++ V_50 ) {
V_46 = V_50 * V_61 + V_60 ;
if ( V_58 == NULL ) {
T_2 V_52 = F_49 ( V_11 -> V_16 ,
V_55 ) ;
V_12 = F_45 ( V_10 , V_59 , V_46 ,
V_52 ) ;
} else if ( V_59 == NULL ) {
T_2 V_52 = F_49 ( V_8 -> V_16 ,
V_55 ) ;
V_12 = F_35 ( V_10 , V_58 , V_46 ,
V_52 ) ;
} else
V_12 = F_32 ( V_59 , V_58 , V_46 ) ;
if ( V_12 )
goto V_70;
}
F_50 () ;
V_63:
V_57 = * V_11 ;
* V_11 = * V_8 ;
V_8 -> V_19 = NULL ;
if ( V_21 -> V_72 & V_73 ) {
F_51 ( V_10 ) ;
V_2 -> V_10 = NULL ;
}
V_70:
F_30 ( V_28 , V_11 , V_59 ) ;
V_62:
F_30 ( V_28 , & V_57 , V_58 ) ;
if ( ! V_12 )
F_2 ( V_2 , & V_57 ) ;
return V_12 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_1 * * V_74 )
{
struct V_1 * V_75 ;
int V_12 ;
V_75 = F_55 ( sizeof( * V_75 ) , V_76 ) ;
if ( ! V_75 )
return - V_43 ;
* V_75 = * V_2 ;
F_56 ( & V_75 -> V_77 ) ;
F_56 ( & V_75 -> V_78 ) ;
F_56 ( & V_75 -> V_79 ) ;
F_56 ( & V_75 -> V_25 ) ;
V_75 -> V_80 = NULL ;
F_57 ( & V_75 -> V_81 ) ;
F_58 ( & V_75 -> V_82 , 0 ) ;
F_59 ( & V_75 -> V_83 ) ;
F_59 ( & V_75 -> V_84 ) ;
V_75 -> V_85 = & F_52 ;
V_75 -> V_86 = 0 ;
V_75 -> V_87 = & V_75 -> V_88 ;
F_60 ( V_75 -> V_87 ) ;
V_12 = F_61 ( & V_75 -> V_87 -> V_89 ) ;
F_62 ( ! V_12 ) ;
* V_74 = V_75 ;
return 0 ;
}
T_2 F_49 ( T_1 V_90 , T_2 V_91 )
{
if ( V_90 & V_92 )
return V_91 ;
#if F_63 ( V_93 ) || F_63 ( V_94 )
if ( V_90 & V_39 )
V_91 = F_64 ( V_91 ) ;
else if ( V_95 . V_96 > 3 )
V_91 = F_65 ( V_91 ) ;
#endif
#if F_63 ( V_97 ) || F_63 ( V_98 ) || F_63 ( V_99 ) || \
F_63 ( V_100 )
if ( V_90 & V_39 )
V_91 = F_64 ( V_91 ) ;
else
V_91 = F_65 ( V_91 ) ;
#endif
#if F_63 ( V_101 ) || F_63 ( V_102 )
V_91 = F_65 ( V_91 ) ;
#endif
return V_91 ;
}
static int F_66 ( struct V_1 * V_2 ,
unsigned long V_41 ,
unsigned long V_42 ,
struct V_103 * V_104 )
{
struct V_7 * V_3 = & V_2 -> V_3 ;
if ( V_2 -> V_3 . V_31 . V_37 ) {
V_104 -> V_105 = V_106 ;
V_104 -> V_36 = ( void * ) ( ( ( V_107 * ) V_2 -> V_3 . V_31 . V_37 ) + V_41 ) ;
} else {
V_104 -> V_105 = V_108 ;
if ( V_3 -> V_16 & V_39 )
V_104 -> V_36 = F_28 ( V_2 -> V_3 . V_31 . V_40 + V_2 -> V_3 . V_31 . V_41 + V_41 ,
V_42 ) ;
else
V_104 -> V_36 = F_29 ( V_2 -> V_3 . V_31 . V_40 + V_2 -> V_3 . V_31 . V_41 + V_41 ,
V_42 ) ;
}
return ( ! V_104 -> V_36 ) ? - V_43 : 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned long V_109 ,
unsigned long V_68 ,
struct V_103 * V_104 )
{
struct V_7 * V_3 = & V_2 -> V_3 ; T_2 V_52 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_12 ;
F_68 ( ! V_10 ) ;
if ( V_10 -> V_64 == V_65 ) {
V_12 = V_10 -> V_28 -> V_29 -> V_69 ( V_10 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_68 == 1 && ( V_3 -> V_16 & V_92 ) ) {
V_104 -> V_105 = V_110 ;
V_104 -> V_46 = V_10 -> V_54 [ V_109 ] ;
V_104 -> V_36 = F_40 ( V_104 -> V_46 ) ;
} else {
V_52 = F_49 ( V_3 -> V_16 , V_55 ) ;
V_104 -> V_105 = V_111 ;
V_104 -> V_36 = F_39 ( V_10 -> V_54 + V_109 , V_68 ,
0 , V_52 ) ;
}
return ( ! V_104 -> V_36 ) ? - V_43 : 0 ;
}
int F_69 ( struct V_1 * V_2 ,
unsigned long V_109 , unsigned long V_68 ,
struct V_103 * V_104 )
{
struct V_20 * V_21 =
& V_2 -> V_28 -> V_21 [ V_2 -> V_3 . V_13 ] ;
unsigned long V_41 , V_42 ;
int V_12 ;
F_68 ( ! F_18 ( & V_2 -> V_79 ) ) ;
V_104 -> V_36 = NULL ;
V_104 -> V_2 = V_2 ;
if ( V_68 > V_2 -> V_68 )
return - V_112 ;
if ( V_109 > V_2 -> V_68 )
return - V_112 ;
#if 0
if (num_pages > 1 && !capable(CAP_SYS_ADMIN))
return -EPERM;
#endif
( void ) F_11 ( V_21 , false ) ;
V_12 = F_22 ( V_2 -> V_28 , & V_2 -> V_3 ) ;
F_15 ( V_21 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_2 -> V_3 . V_31 . V_38 ) {
return F_67 ( V_2 , V_109 , V_68 , V_104 ) ;
} else {
V_41 = V_109 << V_48 ;
V_42 = V_68 << V_48 ;
return F_66 ( V_2 , V_41 , V_42 , V_104 ) ;
}
}
void F_70 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_20 * V_21 =
& V_2 -> V_28 -> V_21 [ V_2 -> V_3 . V_13 ] ;
if ( ! V_104 -> V_36 )
return;
switch ( V_104 -> V_105 ) {
case V_108 :
F_31 ( V_104 -> V_36 ) ;
break;
case V_111 :
F_43 ( V_104 -> V_36 ) ;
break;
case V_110 :
F_44 ( V_104 -> V_46 ) ;
break;
case V_106 :
break;
default:
F_71 () ;
}
( void ) F_11 ( V_21 , false ) ;
F_23 ( V_104 -> V_2 -> V_28 , & V_104 -> V_2 -> V_3 ) ;
F_15 ( V_21 ) ;
V_104 -> V_36 = NULL ;
V_104 -> V_46 = NULL ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_113 * V_113 ,
bool V_4 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_20 * V_21 = & V_28 -> V_21 [ V_8 -> V_13 ] ;
struct V_7 * V_11 = & V_2 -> V_3 ;
int V_12 ;
struct V_1 * V_114 ;
F_73 ( V_2 -> V_87 , V_113 ) ;
if ( V_4 ) {
V_12 = F_4 ( V_2 , false , false ) ;
if ( V_12 )
return V_12 ;
if ( V_21 -> V_72 & V_73 ) {
F_51 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
F_1 ( V_2 ) ;
} else {
F_74 ( V_2 -> V_80 ) ;
V_2 -> V_80 = F_75 ( V_113 ) ;
V_12 = F_54 ( V_2 , & V_114 ) ;
if ( V_12 )
return V_12 ;
F_73 ( V_114 -> V_87 , V_113 ) ;
if ( ! ( V_21 -> V_72 & V_73 ) )
V_114 -> V_10 = NULL ;
else
V_2 -> V_10 = NULL ;
F_76 ( V_114 ) ;
F_77 ( & V_114 ) ;
}
* V_11 = * V_8 ;
V_8 -> V_19 = NULL ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_113 * V_113 , bool V_4 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_7 * V_11 = & V_2 -> V_3 ;
struct V_20 * V_115 = & V_28 -> V_21 [ V_11 -> V_13 ] ;
struct V_20 * V_116 = & V_28 -> V_21 [ V_8 -> V_13 ] ;
int V_12 ;
F_73 ( V_2 -> V_87 , V_113 ) ;
if ( ! V_4 ) {
struct V_1 * V_114 ;
F_74 ( V_2 -> V_80 ) ;
V_2 -> V_80 = F_75 ( V_113 ) ;
V_12 = F_54 ( V_2 , & V_114 ) ;
if ( V_12 )
return V_12 ;
F_73 ( V_114 -> V_87 , V_113 ) ;
if ( ! ( V_116 -> V_72 & V_73 ) )
V_114 -> V_10 = NULL ;
else
V_2 -> V_10 = NULL ;
F_76 ( V_114 ) ;
F_77 ( & V_114 ) ;
} else if ( V_115 -> V_72 & V_73 ) {
F_79 ( & V_115 -> V_117 ) ;
if ( ! V_115 -> V_118 || F_80 ( V_113 , V_115 -> V_118 ) ) {
F_74 ( V_115 -> V_118 ) ;
V_115 -> V_118 = F_75 ( V_113 ) ;
}
F_81 ( & V_115 -> V_117 ) ;
F_1 ( V_2 ) ;
F_74 ( V_2 -> V_80 ) ;
V_2 -> V_80 = F_75 ( V_113 ) ;
} else {
V_12 = F_4 ( V_2 , false , false ) ;
if ( V_12 )
return V_12 ;
if ( V_116 -> V_72 & V_73 ) {
F_51 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
F_1 ( V_2 ) ;
}
* V_11 = * V_8 ;
V_8 -> V_19 = NULL ;
return 0 ;
}
