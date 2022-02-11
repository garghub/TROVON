static void F_1 ( struct V_1 * V_2 , unsigned char V_3 ) {}
static unsigned char F_2 ( struct V_1 * V_2 ) { return 0 ; }
static unsigned char F_3 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 ) { return 0 ; }
static void F_4 ( struct V_1 * V_2 ) {}
static void F_5 ( struct V_5 * V_6 , struct V_7 * V_8 ) { }
static void F_6 ( struct V_1 * V_2 , struct V_7 * V_8 ) { }
static T_1 F_7 ( struct V_1 * V_2 , const void * V_3 , T_1 V_9 , int V_10 )
{ return 0 ; }
static T_1 F_8 ( struct V_1 * V_2 , void * V_3 , T_1 V_9 , int V_10 )
{ return 0 ; }
static void F_9 ( struct V_1 * V_11 )
{
struct V_12 * V_13 ;
F_10 (drv, &drivers, list)
V_13 -> V_14 ( V_11 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
struct V_12 * V_13 ;
F_10 (drv, &drivers, list)
V_13 -> V_15 ( V_11 ) ;
}
static void F_12 ( void )
{
F_13 ( L_1 ) ;
}
int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_11 ;
if ( F_15 ( & V_16 ) )
F_12 () ;
F_16 ( & V_17 ) ;
F_10 (port, &portlist, list)
V_13 -> V_14 ( V_11 ) ;
F_17 ( & V_13 -> V_18 , & V_19 ) ;
F_18 ( & V_17 ) ;
return 0 ;
}
void F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_11 ;
F_16 ( & V_17 ) ;
F_20 ( & V_13 -> V_18 ) ;
F_10 (port, &portlist, list)
V_13 -> V_15 ( V_11 ) ;
F_18 ( & V_17 ) ;
}
static void F_21 ( struct V_1 * V_11 )
{
int V_6 ;
F_22 ( & V_20 ) ;
F_23 ( & V_11 -> V_21 ) ;
F_24 ( & V_20 ) ;
for ( V_6 = 0 ; V_6 < 5 ; V_6 ++ ) {
F_25 ( V_11 -> V_22 [ V_6 ] . V_23 ) ;
F_25 ( V_11 -> V_22 [ V_6 ] . V_24 ) ;
F_25 ( V_11 -> V_22 [ V_6 ] . V_25 ) ;
F_25 ( V_11 -> V_22 [ V_6 ] . V_26 ) ;
F_25 ( V_11 -> V_22 [ V_6 ] . V_27 ) ;
}
F_25 ( V_11 -> V_28 ) ;
F_25 ( V_11 ) ;
}
struct V_1 * F_26 ( struct V_1 * V_11 )
{
F_27 ( & V_11 -> V_29 ) ;
return V_11 ;
}
void F_28 ( struct V_1 * V_11 )
{
if ( F_29 ( & V_11 -> V_29 ) )
F_21 ( V_11 ) ;
return;
}
struct V_1 * F_30 ( unsigned long V_30 , int V_31 , int V_32 ,
struct V_33 * V_34 )
{
struct V_35 * V_9 ;
struct V_1 * V_36 ;
int V_37 ;
int V_38 ;
char * V_28 ;
V_36 = F_31 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_36 ) {
F_32 ( V_40 L_2 ) ;
return NULL ;
}
V_36 -> V_30 = V_30 ;
V_36 -> V_31 = V_31 ;
V_36 -> V_32 = V_32 ;
V_36 -> V_41 = V_36 -> V_42 = V_36 -> V_43 = - 1 ;
V_36 -> V_44 = 0 ;
F_33 ( & V_36 -> V_18 ) ;
V_36 -> V_45 = V_36 -> V_46 = NULL ;
V_36 -> V_47 = 0 ;
V_36 -> V_34 = V_34 ;
V_36 -> V_48 = V_36 ;
memset ( V_36 -> V_22 , 0 , 5 * sizeof ( struct V_49 ) ) ;
F_34 ( & V_36 -> V_50 ) ;
F_35 ( & V_36 -> V_51 ) ;
F_35 ( & V_36 -> V_52 ) ;
V_36 -> V_53 . V_54 = V_55 ;
V_36 -> V_53 . V_56 = V_57 ;
F_36 ( & V_36 -> V_53 . V_31 , 0 ) ;
V_36 -> V_58 = V_59 ;
F_37 ( & V_36 -> V_29 , 1 ) ;
F_33 ( & V_36 -> V_21 ) ;
V_28 = F_38 ( 15 , V_39 ) ;
if ( ! V_28 ) {
F_32 ( V_60 L_2 ) ;
F_25 ( V_36 ) ;
return NULL ;
}
F_22 ( & V_20 ) ;
for ( V_9 = V_61 . V_62 , V_37 = 0 ; V_9 != & V_61 ; V_9 = V_9 -> V_62 , V_37 ++ ) {
struct V_1 * V_2 = F_39 ( V_9 , struct V_1 , V_21 ) ;
if ( V_2 -> V_63 != V_37 )
break;
}
V_36 -> V_64 = V_36 -> V_63 = V_37 ;
F_40 ( & V_36 -> V_21 , V_9 ) ;
F_24 ( & V_20 ) ;
sprintf ( V_28 , L_3 , V_36 -> V_64 = V_36 -> V_63 ) ;
V_36 -> V_28 = V_28 ;
for ( V_38 = 0 ; V_38 < 5 ; V_38 ++ )
V_36 -> V_22 [ V_38 ] . V_65 = V_66 ;
V_36 -> V_67 = V_36 -> V_68 = NULL ;
return V_36 ;
}
void F_41 ( struct V_1 * V_11 )
{
int V_69 ;
#ifdef F_42
F_43 ( V_11 ) ;
#endif
if ( ! V_11 -> V_70 )
F_32 ( V_40 L_4
L_5 ,
V_11 -> V_28 ) ;
F_44 ( V_11 ) ;
F_16 ( & V_17 ) ;
F_45 ( & V_71 ) ;
F_40 ( & V_11 -> V_18 , & V_16 ) ;
for ( V_69 = 1 ; V_69 < 3 ; V_69 ++ ) {
struct V_1 * V_72 = V_11 -> V_73 [ V_69 - 1 ] ;
if ( V_72 )
F_40 ( & V_72 -> V_18 , & V_16 ) ;
}
F_46 ( & V_71 ) ;
F_9 ( V_11 ) ;
for ( V_69 = 1 ; V_69 < 3 ; V_69 ++ ) {
struct V_1 * V_72 = V_11 -> V_73 [ V_69 - 1 ] ;
if ( V_72 )
F_9 ( V_72 ) ;
}
F_18 ( & V_17 ) ;
}
void F_47 ( struct V_1 * V_11 )
{
int V_69 ;
F_16 ( & V_17 ) ;
F_11 ( V_11 ) ;
#ifdef F_42
F_48 ( V_11 ) ;
for ( V_69 = 1 ; V_69 < 3 ; V_69 ++ ) {
struct V_1 * V_72 = V_11 -> V_73 [ V_69 - 1 ] ;
if ( ! V_72 )
continue;
F_11 ( V_72 ) ;
F_48 ( V_72 ) ;
}
#endif
V_11 -> V_34 = & V_74 ;
F_22 ( & V_71 ) ;
F_20 ( & V_11 -> V_18 ) ;
for ( V_69 = 1 ; V_69 < 3 ; V_69 ++ ) {
struct V_1 * V_72 = V_11 -> V_73 [ V_69 - 1 ] ;
if ( V_72 )
F_20 ( & V_72 -> V_18 ) ;
}
F_24 ( & V_71 ) ;
F_18 ( & V_17 ) ;
F_49 ( V_11 ) ;
for ( V_69 = 1 ; V_69 < 3 ; V_69 ++ ) {
struct V_1 * V_72 = V_11 -> V_73 [ V_69 - 1 ] ;
if ( V_72 )
F_28 ( V_72 ) ;
}
}
struct V_5 *
F_50 ( struct V_1 * V_11 , const char * V_28 ,
int (* F_51)( void * ) , void (* F_52)( void * ) ,
void (* F_53)( void * ) ,
int V_47 , void * V_75 )
{
struct V_5 * V_36 ;
if ( V_11 -> V_48 -> V_47 & V_76 ) {
F_32 ( V_77 L_6 ,
V_11 -> V_28 ) ;
return NULL ;
}
if ( V_47 & V_78 ) {
if ( ! F_51 || ! F_52 ) {
F_32 ( V_79 L_7 , V_11 -> V_28 , V_28 ) ;
return NULL ;
}
}
if ( ! F_54 ( V_11 -> V_34 -> V_80 ) ) {
return NULL ;
}
F_26 ( V_11 ) ;
V_36 = F_38 ( sizeof( struct V_5 ) , V_39 ) ;
if ( V_36 == NULL ) {
F_32 ( V_40 L_8 , V_11 -> V_28 , V_28 ) ;
goto V_81;
}
V_36 -> V_82 = F_38 ( sizeof( struct V_7 ) , V_39 ) ;
if ( V_36 -> V_82 == NULL ) {
F_32 ( V_40 L_8 , V_11 -> V_28 , V_28 ) ;
goto V_83;
}
V_36 -> V_28 = V_28 ;
V_36 -> V_11 = V_11 ;
V_36 -> V_42 = - 1 ;
V_36 -> V_84 = F_51 ;
V_36 -> V_85 = F_52 ;
V_36 -> V_86 = V_75 ;
V_36 -> V_47 = V_47 ;
V_36 -> F_53 = F_53 ;
V_36 -> V_87 = 0 ;
V_36 -> V_88 = 5 * V_89 ;
V_36 -> V_90 = NULL ;
F_22 ( & V_11 -> V_48 -> V_52 ) ;
if ( V_47 & V_91 ) {
if ( V_11 -> V_48 -> V_45 ) {
F_24 ( & V_11 -> V_48 -> V_52 ) ;
F_32 ( V_77
L_9
L_10 , V_11 -> V_28 , V_28 ) ;
goto V_92;
}
V_11 -> V_47 |= V_76 ;
}
V_36 -> V_62 = V_11 -> V_48 -> V_45 ;
F_55 () ;
if ( V_11 -> V_48 -> V_45 )
V_11 -> V_48 -> V_45 -> V_90 = V_36 ;
V_11 -> V_48 -> V_45 = V_36 ;
F_24 ( & V_11 -> V_48 -> V_52 ) ;
F_56 ( & V_36 -> V_93 ) ;
V_36 -> V_94 = V_95 ;
V_36 -> V_96 = V_36 -> V_97 = NULL ;
V_11 -> V_34 -> V_98 ( V_36 , V_36 -> V_82 ) ;
if ( ! F_57 ( V_99 , & V_11 -> V_100 ) ) {
V_11 -> V_101 = V_36 ;
F_58 ( V_36 ) ;
}
return V_36 ;
V_92:
F_25 ( V_36 -> V_82 ) ;
V_83:
F_25 ( V_36 ) ;
V_81:
F_28 ( V_11 ) ;
F_59 ( V_11 -> V_34 -> V_80 ) ;
return NULL ;
}
void F_60 ( struct V_5 * V_70 )
{
struct V_1 * V_11 ;
#ifdef F_61
if ( V_70 == NULL ) {
F_32 ( V_60 L_11 ) ;
return;
}
#endif
V_11 = V_70 -> V_11 -> V_48 ;
if ( V_11 -> V_101 == V_70 ) {
V_11 -> V_101 = NULL ;
F_62 ( V_99 , & V_11 -> V_100 ) ;
F_63 ( V_70 ) ;
}
if ( V_11 -> V_46 == V_70 ) {
F_32 ( V_77 L_12 ,
V_11 -> V_28 , V_70 -> V_28 ) ;
F_64 ( V_70 ) ;
}
F_22 ( & V_11 -> V_52 ) ;
if ( V_70 -> V_62 )
V_70 -> V_62 -> V_90 = V_70 -> V_90 ;
if ( V_70 -> V_90 )
V_70 -> V_90 -> V_62 = V_70 -> V_62 ;
else
V_11 -> V_45 = V_70 -> V_62 ;
if ( V_70 -> V_47 & V_91 )
V_11 -> V_47 &= ~ V_76 ;
F_24 ( & V_11 -> V_52 ) ;
F_45 ( & V_11 -> V_51 ) ;
if ( V_70 -> V_97 || V_70 -> V_96 || V_11 -> V_67 == V_70 ) {
if ( V_70 -> V_97 )
V_70 -> V_97 -> V_96 = V_70 -> V_96 ;
else
V_11 -> V_67 = V_70 -> V_96 ;
if ( V_70 -> V_96 )
V_70 -> V_96 -> V_97 = V_70 -> V_97 ;
else
V_11 -> V_68 = V_70 -> V_97 ;
}
F_46 ( & V_11 -> V_51 ) ;
F_25 ( V_70 -> V_82 ) ;
F_25 ( V_70 ) ;
F_59 ( V_11 -> V_34 -> V_80 ) ;
F_28 ( V_11 ) ;
}
struct V_1 * F_65 ( int V_63 )
{
struct V_1 * V_11 , * V_102 = NULL ;
if ( F_15 ( & V_16 ) )
F_12 () ;
F_22 ( & V_71 ) ;
F_10 (port, &portlist, list) {
if ( V_11 -> V_63 == V_63 ) {
V_102 = F_26 ( V_11 ) ;
break;
}
}
F_24 ( & V_71 ) ;
return V_102 ;
}
struct V_1 * F_66 ( unsigned long V_30 )
{
struct V_1 * V_11 , * V_102 = NULL ;
if ( F_15 ( & V_16 ) )
F_12 () ;
F_22 ( & V_71 ) ;
F_10 (port, &portlist, list) {
if ( V_11 -> V_30 == V_30 ) {
V_102 = F_26 ( V_11 ) ;
break;
}
}
F_24 ( & V_71 ) ;
return V_102 ;
}
int F_67 ( struct V_5 * V_70 )
{
struct V_5 * V_103 ;
struct V_1 * V_11 = V_70 -> V_11 -> V_48 ;
unsigned long V_47 ;
if ( V_11 -> V_46 == V_70 ) {
F_32 ( V_79 L_13 ,
V_70 -> V_11 -> V_28 , V_70 -> V_28 ) ;
return 0 ;
}
F_68 ( & V_11 -> V_50 , V_47 ) ;
if ( ( V_103 = V_11 -> V_46 ) != NULL ) {
if ( V_103 -> V_84 ) {
if ( V_103 -> V_84 ( V_103 -> V_86 ) )
goto V_104;
V_11 -> V_34 -> V_105 ( V_11 , V_70 -> V_82 ) ;
} else
goto V_104;
if ( V_11 -> V_46 != V_103 ) {
F_32 ( V_40
L_14 ,
V_11 -> V_28 , V_103 -> V_28 ) ;
if ( V_11 -> V_46 )
goto V_104;
}
}
if ( V_70 -> V_87 & 1 ) {
V_70 -> V_87 = 0 ;
F_45 ( & V_11 -> V_51 ) ;
if ( V_70 -> V_97 )
V_70 -> V_97 -> V_96 = V_70 -> V_96 ;
else
V_11 -> V_67 = V_70 -> V_96 ;
if ( V_70 -> V_96 )
V_70 -> V_96 -> V_97 = V_70 -> V_97 ;
else
V_11 -> V_68 = V_70 -> V_97 ;
F_46 ( & V_11 -> V_51 ) ;
V_70 -> V_97 = V_70 -> V_96 = NULL ;
}
V_11 -> V_46 = V_70 ;
#ifdef F_42
if ( V_70 -> V_11 -> V_41 >= 0 ) {
V_11 -> V_43 = V_70 -> V_11 -> V_41 ;
}
if ( V_70 -> V_42 >= 0 ) {
if ( ! F_69 ( V_11 , V_70 -> V_42 ,
V_55 ) )
V_11 -> V_42 = V_70 -> V_42 ;
}
#endif
V_11 -> V_34 -> V_106 ( V_11 , V_70 -> V_82 ) ;
F_70 ( & V_11 -> V_50 , V_47 ) ;
V_70 -> time = V_107 ;
return 0 ;
V_104:
if ( V_70 -> V_87 & 2 || V_70 -> V_85 ) {
F_22 ( & V_11 -> V_51 ) ;
if ( F_57 ( 0 , & V_70 -> V_87 ) == 0 ) {
V_70 -> V_96 = NULL ;
V_70 -> V_97 = V_11 -> V_68 ;
if ( V_11 -> V_68 ) {
V_11 -> V_68 -> V_96 = V_70 ;
V_11 -> V_68 = V_70 ;
} else
V_11 -> V_67 = V_11 -> V_68 = V_70 ;
}
F_24 ( & V_11 -> V_51 ) ;
}
F_70 ( & V_11 -> V_50 , V_47 ) ;
return - V_108 ;
}
int F_71 ( struct V_5 * V_70 )
{
int V_109 ;
V_70 -> V_87 = 2 ;
V_109 = F_67 ( V_70 ) ;
if ( V_109 == - V_108 ) {
#ifdef F_72
F_32 ( V_77 L_15 , V_70 -> V_28 ) ;
#endif
if ( V_70 -> V_87 ) {
F_73 ( V_70 -> V_93 ,
! V_70 -> V_87 ) ;
if ( F_74 ( V_110 ) ) {
return - V_111 ;
}
V_109 = 1 ;
} else {
V_109 = 0 ;
#ifdef F_72
F_32 ( V_77 L_16 ,
V_70 -> V_28 ) ;
#endif
}
#ifdef F_72
if ( V_70 -> V_11 -> V_48 -> V_46 != V_70 )
F_32 ( V_77 L_17
L_18 , V_70 -> V_28 ,
V_70 -> V_11 -> V_48 -> V_46 ?
V_70 -> V_11 -> V_48 -> V_46 -> V_28 : L_19 ) ;
#endif
}
V_70 -> V_87 = 0 ;
return V_109 ;
}
void F_64 ( struct V_5 * V_70 )
{
struct V_1 * V_11 = V_70 -> V_11 -> V_48 ;
struct V_5 * V_112 ;
unsigned long V_47 ;
F_68 ( & V_11 -> V_50 , V_47 ) ;
if ( V_11 -> V_46 != V_70 ) {
F_70 ( & V_11 -> V_50 , V_47 ) ;
F_32 ( V_40 L_20
L_21 , V_11 -> V_28 , V_70 -> V_28 ) ;
return;
}
#ifdef F_42
if ( V_70 -> V_11 -> V_41 >= 0 ) {
V_11 -> V_43 = - 1 ;
}
if ( V_70 -> V_42 >= 0 ) {
F_75 ( V_11 ) ;
V_11 -> V_42 = - 1 ;
}
#endif
V_11 -> V_46 = NULL ;
F_70 ( & V_11 -> V_50 , V_47 ) ;
V_11 -> V_34 -> V_105 ( V_11 , V_70 -> V_82 ) ;
for ( V_112 = V_11 -> V_67 ; V_112 ; V_112 = V_112 -> V_96 ) {
if ( V_112 -> V_87 & 2 ) {
F_67 ( V_112 ) ;
if ( F_76 ( & V_112 -> V_93 ) )
F_77 ( & V_112 -> V_93 ) ;
return;
} else if ( V_112 -> V_85 ) {
V_112 -> V_85 ( V_112 -> V_86 ) ;
if ( V_70 -> V_11 -> V_46 )
return;
} else {
F_32 ( V_60 L_22 , V_11 -> V_28 , V_112 -> V_28 ) ;
}
}
for ( V_112 = V_11 -> V_45 ; ( V_11 -> V_46 == NULL ) && V_112 ; V_112 = V_112 -> V_62 ) {
if ( V_112 -> V_85 && V_112 != V_70 )
V_112 -> V_85 ( V_112 -> V_86 ) ;
}
}
T_2 F_78 ( int V_31 , void * V_113 )
{
struct V_1 * V_11 = V_113 ;
F_79 ( V_11 ) ;
return V_114 ;
}
