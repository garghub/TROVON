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
static int F_8 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
int V_17 = 10000 ;
while ( V_17 -- > 0 ) {
long V_5 ;
long V_18 = F_9 ( & V_5 ) ;
if ( V_5 == V_19 )
break;
if ( V_18 == V_20 ) {
if ( F_10 ( V_2 ) )
continue;
V_16 = 1 ;
V_18 = 0 ;
}
if ( V_18 == V_21 ) {
V_22 = 1 ;
F_11 ( V_2 , 0 ) ;
} else if ( V_22 ) {
V_22 = 0 ;
F_11 ( V_2 , 1 ) ;
}
if ( V_2 -> V_23 == NULL ) {
F_12 ( V_2 , V_18 ) ;
continue;
}
V_2 -> V_10 . V_24 ++ ;
if ( F_12 ( V_2 , V_18 ) )
continue;
F_13 ( & V_2 -> V_23 -> V_2 , V_18 , V_25 ) ;
}
return V_16 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
int V_17 = 10000 ;
while ( V_17 -- > 0 ) {
unsigned long V_12 = F_5 ( V_26 ) ;
unsigned long V_27 , V_28 ;
long V_29 = F_15 ( V_12 , V_30 , & V_27 ) ;
if ( V_29 != V_8 ) {
V_27 = 0 ;
if ( V_29 == V_20 ) {
if ( F_10 ( V_2 ) )
continue;
V_16 = 1 ;
* V_26 = 0 ;
V_27 = 1 ;
} else if ( V_29 == V_21 ) {
V_22 = 1 ;
F_11 ( V_2 , 0 ) ;
continue;
} else {
break;
}
}
if ( V_22 ) {
V_22 = 0 ;
F_11 ( V_2 , 1 ) ;
}
for ( V_28 = 0 ; V_28 < V_27 ; V_28 ++ )
F_12 ( V_2 , V_26 [ V_28 ] ) ;
if ( V_2 -> V_23 == NULL )
continue;
V_2 -> V_10 . V_24 += V_27 ;
F_16 ( & V_2 -> V_23 -> V_2 , V_26 ,
V_27 ) ;
}
return V_16 ;
}
static struct V_31 * F_17 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = NULL ;
if ( V_2 -> V_23 != NULL )
V_32 = & V_2 -> V_23 -> V_2 ;
if ( V_33 -> F_17 ( V_2 ) )
F_18 () ;
return V_32 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( ! V_2 -> V_23 )
return;
V_4 = & V_2 -> V_23 -> V_4 ;
if ( F_2 ( V_4 ) || F_20 ( V_2 ) )
return;
V_33 -> F_19 ( V_2 , V_4 ) ;
if ( F_21 ( V_4 ) < V_34 )
F_22 ( V_2 ) ;
}
static T_1 F_23 ( int V_35 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
struct V_31 * V_32 ;
unsigned long V_37 ;
F_24 ( & V_2 -> V_38 , V_37 ) ;
V_32 = F_17 ( V_2 ) ;
F_19 ( V_2 ) ;
F_25 ( & V_2 -> V_38 , V_37 ) ;
if ( V_32 )
F_26 ( V_32 ) ;
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
int V_17 = 10000 ;
if ( V_45 == V_46 )
return;
F_24 ( & V_2 -> V_38 , V_37 ) ;
while ( V_17 -- > 0 ) {
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
static void F_35 ( struct V_1 * V_2 , int V_47 )
{
if ( V_47 ) {
unsigned long V_37 ;
int V_17 = 10000 ;
F_24 ( & V_2 -> V_38 , V_37 ) ;
while ( V_17 -- > 0 ) {
long V_5 = F_3 ( V_20 ) ;
if ( V_5 == V_8 )
break;
F_33 ( 1 ) ;
}
F_25 ( & V_2 -> V_38 , V_37 ) ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
}
static void F_38 ( struct V_1 * V_2 , struct V_48 * V_49 ,
struct V_48 * V_50 )
{
unsigned int V_51 = F_39 ( V_2 , V_49 , V_50 , 0 , 4000000 ) ;
unsigned int V_52 = F_40 ( V_2 , V_51 ) ;
unsigned int V_53 , V_54 ;
unsigned long V_37 ;
F_24 ( & V_2 -> V_38 , V_37 ) ;
V_53 = V_49 -> V_55 ;
V_54 = V_49 -> V_56 ;
V_2 -> V_57 = 0 ;
if ( V_53 & V_58 )
V_2 -> V_57 |= V_59 ;
if ( ( V_54 & V_60 ) == 0 )
V_2 -> V_57 |= V_61 ;
F_41 ( V_2 , V_54 ,
( V_2 -> V_62 / ( 16 * V_52 ) ) ) ;
F_25 ( & V_2 -> V_38 , V_37 ) ;
}
static const char * F_42 ( struct V_1 * V_2 )
{
return L_1 ;
}
static void F_43 ( struct V_1 * V_2 )
{
}
static int F_44 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , int V_37 )
{
}
static int F_46 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
return - V_65 ;
}
static int F_47 ( const char * V_66 , unsigned int V_67 ,
unsigned long * V_68 )
{
const char * V_69 = V_66 ;
char * V_70 = V_71 ;
int V_72 = V_30 ;
while ( V_67 -- ) {
if ( * V_66 == '\n' ) {
if ( V_72 < 2 )
break;
* V_70 ++ = '\r' ;
V_72 -- ;
} else if ( V_72 < 1 )
break;
* V_70 ++ = * V_66 ++ ;
V_72 -- ;
}
* V_68 = V_70 - V_71 ;
return V_66 - V_69 ;
}
static void F_48 ( struct V_73 * V_74 , const char * V_66 , unsigned V_67 )
{
struct V_1 * V_2 = V_75 ;
unsigned long V_37 ;
int V_76 = 1 ;
if ( V_2 -> V_77 || V_78 )
V_76 = F_49 ( & V_2 -> V_38 , V_37 ) ;
else
F_24 ( & V_2 -> V_38 , V_37 ) ;
while ( V_67 > 0 ) {
unsigned long V_12 = F_5 ( V_71 ) ;
unsigned long V_68 ;
unsigned int V_79 = F_47 ( V_66 , V_67 ,
& V_68 ) ;
V_67 -= V_79 ;
V_66 += V_79 ;
while ( V_68 > 0 ) {
unsigned long V_80 ;
int V_17 = 1000000 ;
while ( V_17 -- ) {
unsigned long V_29 ;
V_29 = F_7 ( V_12 , V_68 ,
& V_80 ) ;
if ( V_29 == V_8 )
break;
F_33 ( 1 ) ;
}
if ( V_17 < 0 )
break;
V_68 -= V_80 ;
V_12 += V_80 ;
}
}
if ( V_76 )
F_25 ( & V_2 -> V_38 , V_37 ) ;
}
static inline void F_50 ( struct V_1 * V_2 , char V_18 )
{
int V_17 = 1000000 ;
while ( V_17 -- > 0 ) {
long V_5 = F_3 ( V_18 ) ;
if ( V_5 == V_8 )
break;
F_33 ( 1 ) ;
}
}
static void F_51 ( struct V_73 * V_74 , const char * V_66 , unsigned V_67 )
{
struct V_1 * V_2 = V_75 ;
unsigned long V_37 ;
int V_28 , V_76 = 1 ;
if ( V_2 -> V_77 || V_78 )
V_76 = F_49 ( & V_2 -> V_38 , V_37 ) ;
else
F_24 ( & V_2 -> V_38 , V_37 ) ;
if ( V_2 -> V_77 ) {
V_76 = 0 ;
} else if ( V_78 ) {
V_76 = F_52 ( & V_2 -> V_38 ) ;
} else
F_53 ( & V_2 -> V_38 ) ;
for ( V_28 = 0 ; V_28 < V_67 ; V_28 ++ ) {
if ( * V_66 == '\n' )
F_50 ( V_2 , '\r' ) ;
F_50 ( V_2 , * V_66 ++ ) ;
}
if ( V_76 )
F_25 ( & V_2 -> V_38 , V_37 ) ;
}
static int F_54 ( struct V_81 * V_82 )
{
struct V_1 * V_2 ;
unsigned long V_83 ;
int V_84 ;
if ( V_82 -> V_85 . V_86 [ 0 ] == 0xffffffff )
return - V_87 ;
V_2 = F_55 ( sizeof( struct V_1 ) , V_88 ) ;
if ( F_56 ( ! V_2 ) )
return - V_89 ;
V_83 = 1 ;
if ( F_57 ( V_90 , 1 , & V_83 ) == 0 &&
V_83 >= 1 ) {
V_84 = - V_89 ;
V_71 = F_55 ( V_30 , V_88 ) ;
if ( ! V_71 )
goto V_91;
V_26 = F_55 ( V_30 , V_88 ) ;
if ( ! V_26 )
goto V_92;
V_93 . V_94 = F_48 ;
V_33 = & V_95 ;
}
V_75 = V_2 ;
V_2 -> line = 0 ;
V_2 -> V_96 = & V_97 ;
V_2 -> type = V_98 ;
V_2 -> V_62 = ( 29491200 / 16 ) ;
V_2 -> V_99 = ( unsigned char V_100 * ) F_5 ( V_2 ) ;
V_2 -> V_35 = V_82 -> V_85 . V_86 [ 0 ] ;
V_2 -> V_101 = & V_82 -> V_101 ;
V_84 = F_58 ( & V_102 , 1 ) ;
if ( V_84 )
goto V_103;
F_59 ( & V_93 , V_82 -> V_101 . V_104 ,
& V_102 , V_2 -> line , false ) ;
V_84 = F_60 ( & V_102 , V_2 ) ;
if ( V_84 )
goto V_105;
V_84 = F_61 ( V_2 -> V_35 , F_23 , 0 , L_2 , V_2 ) ;
if ( V_84 )
goto V_106;
F_62 ( V_82 , V_2 ) ;
return 0 ;
V_106:
F_63 ( & V_102 , V_2 ) ;
V_105:
F_64 ( & V_102 , 1 ) ;
V_103:
F_65 ( V_26 ) ;
V_92:
F_65 ( V_71 ) ;
V_91:
F_65 ( V_2 ) ;
V_75 = NULL ;
return V_84 ;
}
static int F_66 ( struct V_81 * V_101 )
{
struct V_1 * V_2 = F_67 ( V_101 ) ;
F_68 ( V_2 -> V_35 , V_2 ) ;
F_63 ( & V_102 , V_2 ) ;
F_64 ( & V_102 , 1 ) ;
F_65 ( V_2 ) ;
V_75 = NULL ;
return 0 ;
}
static int T_2 F_69 ( void )
{
if ( V_107 != V_108 )
return - V_87 ;
return F_70 ( & V_109 ) ;
}
