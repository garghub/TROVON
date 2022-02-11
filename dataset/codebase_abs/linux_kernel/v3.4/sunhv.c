static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
while ( ! F_2 ( V_4 ) ) {
long V_5 = F_3 ( V_4 -> V_6 [ V_4 -> V_7 ] ) ;
if ( V_5 != V_8 )
break;
V_4 -> V_7 = ( V_4 -> V_7 + 1 ) & ( V_9 - 1 ) ;
V_2 -> V_10 . V_11 ++ ;
}
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
while ( ! F_2 ( V_4 ) ) {
unsigned long V_12 = F_5 ( V_4 -> V_6 + V_4 -> V_7 ) ;
unsigned long V_13 , V_5 , V_14 ;
V_13 = F_6 ( V_4 -> V_15 , V_4 -> V_7 ,
V_9 ) ;
V_5 = F_7 ( V_12 , V_13 , & V_14 ) ;
if ( V_5 != V_8 )
break;
V_4 -> V_7 = ( V_4 -> V_7 + V_14 ) & ( V_9 - 1 ) ;
V_2 -> V_10 . V_11 += V_14 ;
}
}
static int F_8 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 = 0 ;
int V_19 = 10000 ;
while ( V_19 -- > 0 ) {
long V_5 ;
long V_20 = F_9 ( & V_5 ) ;
if ( V_5 == V_21 )
break;
if ( V_20 == V_22 ) {
if ( F_10 ( V_2 ) )
continue;
V_18 = 1 ;
V_20 = 0 ;
}
if ( V_20 == V_23 ) {
V_24 = 1 ;
F_11 ( V_2 , 0 ) ;
} else if ( V_24 ) {
V_24 = 0 ;
F_11 ( V_2 , 1 ) ;
}
if ( V_17 == NULL ) {
F_12 ( V_2 , V_20 ) ;
continue;
}
V_2 -> V_10 . V_25 ++ ;
if ( F_12 ( V_2 , V_20 ) )
continue;
F_13 ( V_17 , V_20 , V_26 ) ;
}
return V_18 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 = 0 ;
int V_19 = 10000 ;
while ( V_19 -- > 0 ) {
unsigned long V_12 = F_5 ( V_27 ) ;
unsigned long V_28 , V_29 ;
long V_30 = F_15 ( V_12 , V_31 , & V_28 ) ;
if ( V_30 != V_8 ) {
V_28 = 0 ;
if ( V_30 == V_22 ) {
if ( F_10 ( V_2 ) )
continue;
V_18 = 1 ;
* V_27 = 0 ;
V_28 = 1 ;
} else if ( V_30 == V_23 ) {
V_24 = 1 ;
F_11 ( V_2 , 0 ) ;
continue;
} else {
break;
}
}
if ( V_24 ) {
V_24 = 0 ;
F_11 ( V_2 , 1 ) ;
}
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
F_12 ( V_2 , V_27 [ V_29 ] ) ;
if ( V_17 == NULL )
continue;
V_2 -> V_10 . V_25 += V_28 ;
F_16 ( V_17 , V_27 , V_28 ) ;
}
return V_18 ;
}
static struct V_16 * F_17 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = NULL ;
if ( V_2 -> V_32 != NULL )
V_17 = V_2 -> V_32 -> V_2 . V_17 ;
if ( V_33 -> F_17 ( V_2 , V_17 ) )
F_18 () ;
return V_17 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_32 )
return;
V_4 = & V_2 -> V_32 -> V_4 ;
if ( F_2 ( V_4 ) || F_20 ( V_2 ) )
return;
V_33 -> F_19 ( V_2 , V_4 ) ;
if ( F_21 ( V_4 ) < V_34 )
F_22 ( V_2 ) ;
}
static T_1 F_23 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
struct V_16 * V_17 ;
unsigned long V_37 ;
F_24 ( & V_2 -> V_38 , V_37 ) ;
V_17 = F_17 ( V_2 ) ;
F_19 ( V_2 ) ;
F_25 ( & V_2 -> V_38 , V_37 ) ;
if ( V_17 )
F_26 ( V_17 ) ;
return V_39 ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
return V_40 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_41 )
{
return;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
return V_42 | V_43 | V_44 ;
}
static void F_30 ( struct V_1 * V_2 )
{
return;
}
static void F_31 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 , char V_45 )
{
unsigned long V_37 ;
int V_19 = 10000 ;
F_24 ( & V_2 -> V_38 , V_37 ) ;
while ( V_19 -- > 0 ) {
long V_5 = F_3 ( V_45 ) ;
if ( V_5 == V_8 )
break;
F_33 ( 1 ) ;
}
F_25 ( & V_2 -> V_38 , V_37 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static void F_35 ( struct V_1 * V_2 )
{
}
static void F_36 ( struct V_1 * V_2 , int V_46 )
{
if ( V_46 ) {
unsigned long V_37 ;
int V_19 = 10000 ;
F_24 ( & V_2 -> V_38 , V_37 ) ;
while ( V_19 -- > 0 ) {
long V_5 = F_3 ( V_22 ) ;
if ( V_5 == V_8 )
break;
F_33 ( 1 ) ;
}
F_25 ( & V_2 -> V_38 , V_37 ) ;
}
}
static int F_37 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
}
static void F_39 ( struct V_1 * V_2 , struct V_47 * V_48 ,
struct V_47 * V_49 )
{
unsigned int V_50 = F_40 ( V_2 , V_48 , V_49 , 0 , 4000000 ) ;
unsigned int V_51 = F_41 ( V_2 , V_50 ) ;
unsigned int V_52 , V_53 ;
unsigned long V_37 ;
F_24 ( & V_2 -> V_38 , V_37 ) ;
V_52 = V_48 -> V_54 ;
V_53 = V_48 -> V_55 ;
V_2 -> V_56 = 0 ;
if ( V_52 & V_57 )
V_2 -> V_56 |= V_58 ;
if ( ( V_53 & V_59 ) == 0 )
V_2 -> V_56 |= V_60 ;
F_42 ( V_2 , V_53 ,
( V_2 -> V_61 / ( 16 * V_51 ) ) ) ;
F_25 ( & V_2 -> V_38 , V_37 ) ;
}
static const char * F_43 ( struct V_1 * V_2 )
{
return L_1 ;
}
static void F_44 ( struct V_1 * V_2 )
{
}
static int F_45 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_37 )
{
}
static int F_47 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
return - V_64 ;
}
static int F_48 ( const char * V_65 , unsigned int V_66 ,
unsigned long * V_67 )
{
const char * V_68 = V_65 ;
char * V_69 = V_70 ;
int V_71 = V_31 ;
while ( V_66 -- ) {
if ( * V_65 == '\n' ) {
if ( V_71 < 2 )
break;
* V_69 ++ = '\r' ;
V_71 -- ;
} else if ( V_71 < 1 )
break;
* V_69 ++ = * V_65 ++ ;
V_71 -- ;
}
* V_67 = V_69 - V_70 ;
return V_65 - V_68 ;
}
static void F_49 ( struct V_72 * V_73 , const char * V_65 , unsigned V_66 )
{
struct V_1 * V_2 = V_74 ;
unsigned long V_37 ;
int V_75 = 1 ;
F_50 ( V_37 ) ;
if ( V_2 -> V_76 ) {
V_75 = 0 ;
} else if ( V_77 ) {
V_75 = F_51 ( & V_2 -> V_38 ) ;
} else
F_52 ( & V_2 -> V_38 ) ;
while ( V_66 > 0 ) {
unsigned long V_12 = F_5 ( V_70 ) ;
unsigned long V_67 ;
unsigned int V_78 = F_48 ( V_65 , V_66 ,
& V_67 ) ;
V_66 -= V_78 ;
V_65 += V_78 ;
while ( V_67 > 0 ) {
unsigned long V_79 ;
int V_19 = 1000000 ;
while ( V_19 -- ) {
unsigned long V_30 ;
V_30 = F_7 ( V_12 , V_67 ,
& V_79 ) ;
if ( V_30 == V_8 )
break;
F_33 ( 1 ) ;
}
if ( V_19 < 0 )
break;
V_67 -= V_79 ;
V_12 += V_79 ;
}
}
if ( V_75 )
F_53 ( & V_2 -> V_38 ) ;
F_54 ( V_37 ) ;
}
static inline void F_55 ( struct V_1 * V_2 , char V_20 )
{
int V_19 = 1000000 ;
while ( V_19 -- > 0 ) {
long V_5 = F_3 ( V_20 ) ;
if ( V_5 == V_8 )
break;
F_33 ( 1 ) ;
}
}
static void F_56 ( struct V_72 * V_73 , const char * V_65 , unsigned V_66 )
{
struct V_1 * V_2 = V_74 ;
unsigned long V_37 ;
int V_29 , V_75 = 1 ;
F_50 ( V_37 ) ;
if ( V_2 -> V_76 ) {
V_75 = 0 ;
} else if ( V_77 ) {
V_75 = F_51 ( & V_2 -> V_38 ) ;
} else
F_52 ( & V_2 -> V_38 ) ;
for ( V_29 = 0 ; V_29 < V_66 ; V_29 ++ ) {
if ( * V_65 == '\n' )
F_55 ( V_2 , '\r' ) ;
F_55 ( V_2 , * V_65 ++ ) ;
}
if ( V_75 )
F_53 ( & V_2 -> V_38 ) ;
F_54 ( V_37 ) ;
}
static int T_2 F_57 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
unsigned long V_82 ;
int V_83 ;
if ( V_81 -> V_84 . V_85 [ 0 ] == 0xffffffff )
return - V_86 ;
V_2 = F_58 ( sizeof( struct V_1 ) , V_87 ) ;
if ( F_59 ( ! V_2 ) )
return - V_88 ;
V_82 = 1 ;
if ( F_60 ( V_89 , 1 , & V_82 ) == 0 &&
V_82 >= 1 ) {
V_83 = - V_88 ;
V_70 = F_58 ( V_31 , V_87 ) ;
if ( ! V_70 )
goto V_90;
V_27 = F_58 ( V_31 , V_87 ) ;
if ( ! V_27 )
goto V_91;
V_92 . V_93 = F_49 ;
V_33 = & V_94 ;
}
V_74 = V_2 ;
V_2 -> line = 0 ;
V_2 -> V_95 = & V_96 ;
V_2 -> type = V_97 ;
V_2 -> V_61 = ( 29491200 / 16 ) ;
V_2 -> V_98 = ( unsigned char V_99 * ) F_5 ( V_2 ) ;
V_2 -> V_35 = V_81 -> V_84 . V_85 [ 0 ] ;
V_2 -> V_100 = & V_81 -> V_100 ;
V_83 = F_61 ( & V_101 , 1 ) ;
if ( V_83 )
goto V_102;
F_62 ( & V_92 , V_81 -> V_100 . V_103 ,
& V_101 , V_2 -> line , false ) ;
V_83 = F_63 ( & V_101 , V_2 ) ;
if ( V_83 )
goto V_104;
V_83 = F_64 ( V_2 -> V_35 , F_23 , 0 , L_2 , V_2 ) ;
if ( V_83 )
goto V_105;
F_65 ( & V_81 -> V_100 , V_2 ) ;
return 0 ;
V_105:
F_66 ( & V_101 , V_2 ) ;
V_104:
F_67 ( & V_101 , 1 ) ;
V_102:
F_68 ( V_27 ) ;
V_91:
F_68 ( V_70 ) ;
V_90:
F_68 ( V_2 ) ;
V_74 = NULL ;
return V_83 ;
}
static int T_3 F_69 ( struct V_80 * V_100 )
{
struct V_1 * V_2 = F_70 ( & V_100 -> V_100 ) ;
F_71 ( V_2 -> V_35 , V_2 ) ;
F_66 ( & V_101 , V_2 ) ;
F_67 ( & V_101 , 1 ) ;
F_68 ( V_2 ) ;
V_74 = NULL ;
F_65 ( & V_100 -> V_100 , NULL ) ;
return 0 ;
}
static int T_4 F_72 ( void )
{
if ( V_106 != V_107 )
return - V_86 ;
return F_73 ( & V_108 ) ;
}
static void T_5 F_74 ( void )
{
F_75 ( & V_108 ) ;
}
