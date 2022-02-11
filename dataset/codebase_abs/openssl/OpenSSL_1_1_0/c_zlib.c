static void * F_1 ( void * V_1 , unsigned int V_2 , unsigned int V_3 )
{
void * V_4 ;
V_4 = F_2 ( V_2 * V_3 ) ;
return V_4 ;
}
static void F_3 ( void * V_1 , void * V_5 )
{
F_4 ( V_5 ) ;
}
static int F_5 ( T_1 * V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL )
goto V_7;
V_9 -> V_10 . V_11 = F_1 ;
V_9 -> V_10 . V_12 = F_3 ;
V_9 -> V_10 . V_1 = V_13 ;
V_9 -> V_10 . V_14 = V_13 ;
V_9 -> V_10 . V_15 = V_13 ;
V_7 = F_6 ( & V_9 -> V_10 , V_16 , sizeof( V_17 ) ) ;
if ( V_7 != V_18 )
goto V_7;
V_9 -> V_19 . V_11 = F_1 ;
V_9 -> V_19 . V_12 = F_3 ;
V_9 -> V_19 . V_1 = V_13 ;
V_9 -> V_19 . V_14 = V_13 ;
V_9 -> V_19 . V_15 = V_13 ;
V_7 = F_7 ( & V_9 -> V_19 , V_20 ,
V_16 , sizeof( V_17 ) ) ;
if ( V_7 != V_18 )
goto V_7;
V_6 -> V_21 = V_9 ;
return 1 ;
V_7:
F_4 ( V_9 ) ;
return 0 ;
}
static void F_8 ( T_1 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_21 ;
F_9 ( & V_9 -> V_10 ) ;
F_10 ( & V_9 -> V_19 ) ;
F_4 ( V_9 ) ;
}
static int F_11 ( T_1 * V_6 , unsigned char * V_22 ,
unsigned int V_23 , unsigned char * V_24 ,
unsigned int V_25 )
{
int V_7 = V_18 ;
struct V_8 * V_9 = V_6 -> V_21 ;
if ( V_9 == NULL )
return - 1 ;
V_9 -> V_19 . V_14 = V_24 ;
V_9 -> V_19 . V_26 = V_25 ;
V_9 -> V_19 . V_15 = V_22 ;
V_9 -> V_19 . V_27 = V_23 ;
if ( V_25 > 0 )
V_7 = F_12 ( & V_9 -> V_19 , V_28 ) ;
if ( V_7 != V_18 )
return - 1 ;
return V_23 - V_9 -> V_19 . V_27 ;
}
static int F_13 ( T_1 * V_6 , unsigned char * V_22 ,
unsigned int V_23 , unsigned char * V_24 ,
unsigned int V_25 )
{
int V_7 = V_18 ;
struct V_8 * V_9 = V_6 -> V_21 ;
if ( V_9 == NULL )
return 0 ;
V_9 -> V_10 . V_14 = V_24 ;
V_9 -> V_10 . V_26 = V_25 ;
V_9 -> V_10 . V_15 = V_22 ;
V_9 -> V_10 . V_27 = V_23 ;
if ( V_25 > 0 )
V_7 = F_14 ( & V_9 -> V_10 , V_28 ) ;
if ( V_7 != V_18 )
return - 1 ;
return V_23 - V_9 -> V_10 . V_27 ;
}
T_2 * F_15 ( void )
{
T_2 * V_29 = & V_30 ;
#ifdef F_16
# ifndef F_17
# if F_18 ( V_31 ) || F_18 ( V_32 )
# define F_17 "ZLIB1"
# elif F_18 ( V_33 )
# define F_17 "LIBZ"
# else
# define F_17 "z"
# endif
# endif
if ( ! V_34 ) {
V_35 = F_19 ( NULL , F_17 , NULL , 0 ) ;
if ( V_35 != NULL ) {
V_36 = ( V_37 ) F_20 ( V_35 , L_1 ) ;
V_38
= ( V_39 ) F_20 ( V_35 , L_2 ) ;
V_40 = ( V_41 ) F_20 ( V_35 , L_3 ) ;
V_42
= ( V_43 ) F_20 ( V_35 , L_4 ) ;
V_44
= ( V_45 ) F_20 ( V_35 , L_5 ) ;
V_46 = ( V_47 ) F_20 ( V_35 , L_6 ) ;
V_48
= ( V_49 ) F_20 ( V_35 , L_7 ) ;
V_50 = ( V_51 ) F_20 ( V_35 , L_8 ) ;
if ( V_36 && V_38 && V_40
&& V_42 && V_44
&& V_46 && V_48 && V_50 )
V_34 ++ ;
if ( ! F_21 ( V_52 , NULL ) ) {
F_22 () ;
return V_29 ;
}
if ( V_34 )
V_29 = & V_53 ;
}
}
#endif
#if F_18 ( V_54 )
V_29 = & V_53 ;
#endif
return ( V_29 ) ;
}
void F_22 ( void )
{
#ifdef F_16
if ( V_35 != NULL )
F_23 ( V_35 ) ;
V_35 = NULL ;
#endif
}
const T_3 * F_24 ( void )
{
return & V_55 ;
}
static int F_25 ( T_4 * V_56 )
{
T_5 * V_6 ;
# ifdef F_16
( void ) F_15 () ;
if ( ! V_34 ) {
F_26 ( V_57 , V_58 ) ;
return 0 ;
}
# endif
V_6 = F_2 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL ) {
F_26 ( V_57 , V_59 ) ;
return 0 ;
}
V_6 -> V_60 = V_61 ;
V_6 -> V_62 = V_61 ;
V_6 -> V_63 . V_11 = V_13 ;
V_6 -> V_63 . V_12 = V_13 ;
V_6 -> V_64 . V_11 = V_13 ;
V_6 -> V_64 . V_12 = V_13 ;
V_6 -> V_65 = V_20 ;
F_27 ( V_56 , 1 ) ;
F_28 ( V_56 , V_6 ) ;
return 1 ;
}
static int F_29 ( T_4 * V_56 )
{
T_5 * V_6 ;
if ( ! V_56 )
return 0 ;
V_6 = F_30 ( V_56 ) ;
if ( V_6 -> V_66 ) {
F_9 ( & V_6 -> V_63 ) ;
F_4 ( V_6 -> V_66 ) ;
}
if ( V_6 -> V_67 ) {
F_10 ( & V_6 -> V_64 ) ;
F_4 ( V_6 -> V_67 ) ;
}
F_4 ( V_6 ) ;
F_28 ( V_56 , NULL ) ;
F_27 ( V_56 , 0 ) ;
return 1 ;
}
static int F_31 ( T_4 * V_68 , char * V_22 , int V_69 )
{
T_5 * V_6 ;
int V_70 ;
V_17 * V_63 ;
T_4 * V_71 = F_32 ( V_68 ) ;
if ( ! V_22 || ! V_69 )
return 0 ;
V_6 = F_30 ( V_68 ) ;
V_63 = & V_6 -> V_63 ;
F_33 ( V_68 ) ;
if ( ! V_6 -> V_66 ) {
V_6 -> V_66 = F_34 ( V_6 -> V_60 ) ;
if ( V_6 -> V_66 == NULL ) {
F_26 ( V_72 , V_59 ) ;
return 0 ;
}
F_35 ( V_63 ) ;
V_63 -> V_14 = V_6 -> V_66 ;
V_63 -> V_26 = 0 ;
}
V_63 -> V_15 = ( unsigned char * ) V_22 ;
V_63 -> V_27 = ( unsigned int ) V_69 ;
for (; ; ) {
while ( V_63 -> V_26 ) {
V_70 = F_14 ( V_63 , 0 ) ;
if ( ( V_70 != V_18 ) && ( V_70 != V_73 ) ) {
F_26 ( V_72 , V_74 ) ;
F_36 ( 2 , L_9 , F_37 ( V_70 ) ) ;
return 0 ;
}
if ( ( V_70 == V_73 ) || ! V_63 -> V_27 )
return V_69 - V_63 -> V_27 ;
}
V_70 = F_38 ( V_71 , V_6 -> V_66 , V_6 -> V_60 ) ;
if ( V_70 <= 0 ) {
int V_75 = V_69 - V_63 -> V_27 ;
F_39 ( V_68 ) ;
if ( V_70 < 0 )
return ( V_75 > 0 ) ? V_75 : V_70 ;
return V_75 ;
}
V_63 -> V_26 = V_70 ;
V_63 -> V_14 = V_6 -> V_66 ;
}
}
static int F_40 ( T_4 * V_68 , const char * V_24 , int V_76 )
{
T_5 * V_6 ;
int V_70 ;
V_17 * V_64 ;
T_4 * V_71 = F_32 ( V_68 ) ;
if ( ! V_24 || ! V_76 )
return 0 ;
V_6 = F_30 ( V_68 ) ;
if ( V_6 -> V_77 )
return 0 ;
V_64 = & V_6 -> V_64 ;
F_33 ( V_68 ) ;
if ( ! V_6 -> V_67 ) {
V_6 -> V_67 = F_34 ( V_6 -> V_62 ) ;
if ( V_6 -> V_67 == NULL ) {
F_26 ( V_78 , V_59 ) ;
return 0 ;
}
V_6 -> V_79 = V_6 -> V_67 ;
V_6 -> V_80 = 0 ;
F_41 ( V_64 , V_6 -> V_65 ) ;
V_64 -> V_15 = V_6 -> V_67 ;
V_64 -> V_27 = V_6 -> V_62 ;
}
V_64 -> V_14 = ( void * ) V_24 ;
V_64 -> V_26 = V_76 ;
for (; ; ) {
while ( V_6 -> V_80 ) {
V_70 = F_42 ( V_71 , V_6 -> V_79 , V_6 -> V_80 ) ;
if ( V_70 <= 0 ) {
int V_75 = V_76 - V_64 -> V_26 ;
F_39 ( V_68 ) ;
if ( V_70 < 0 )
return ( V_75 > 0 ) ? V_75 : V_70 ;
return V_75 ;
}
V_6 -> V_79 += V_70 ;
V_6 -> V_80 -= V_70 ;
}
if ( ! V_64 -> V_26 )
return V_76 ;
V_6 -> V_79 = V_6 -> V_67 ;
V_64 -> V_15 = V_6 -> V_67 ;
V_64 -> V_27 = V_6 -> V_62 ;
V_70 = F_12 ( V_64 , 0 ) ;
if ( V_70 != V_18 ) {
F_26 ( V_78 , V_81 ) ;
F_36 ( 2 , L_9 , F_37 ( V_70 ) ) ;
return 0 ;
}
V_6 -> V_80 = V_6 -> V_62 - V_64 -> V_27 ;
}
}
static int F_43 ( T_4 * V_68 )
{
T_5 * V_6 ;
int V_70 ;
V_17 * V_64 ;
T_4 * V_71 = F_32 ( V_68 ) ;
V_6 = F_30 ( V_68 ) ;
if ( ! V_6 -> V_67 || ( V_6 -> V_77 && ! V_6 -> V_80 ) )
return 1 ;
V_64 = & V_6 -> V_64 ;
F_33 ( V_68 ) ;
V_64 -> V_14 = NULL ;
V_64 -> V_26 = 0 ;
for (; ; ) {
while ( V_6 -> V_80 ) {
V_70 = F_42 ( V_71 , V_6 -> V_79 , V_6 -> V_80 ) ;
if ( V_70 <= 0 ) {
F_39 ( V_68 ) ;
return V_70 ;
}
V_6 -> V_79 += V_70 ;
V_6 -> V_80 -= V_70 ;
}
if ( V_6 -> V_77 )
return 1 ;
V_6 -> V_79 = V_6 -> V_67 ;
V_64 -> V_15 = V_6 -> V_67 ;
V_64 -> V_27 = V_6 -> V_62 ;
V_70 = F_12 ( V_64 , V_82 ) ;
if ( V_70 == V_73 )
V_6 -> V_77 = 1 ;
else if ( V_70 != V_18 ) {
F_26 ( V_83 , V_81 ) ;
F_36 ( 2 , L_9 , F_37 ( V_70 ) ) ;
return 0 ;
}
V_6 -> V_80 = V_6 -> V_62 - V_64 -> V_27 ;
}
}
static long F_44 ( T_4 * V_68 , int V_84 , long V_85 , void * V_86 )
{
T_5 * V_6 ;
int V_70 , * V_87 ;
int V_88 , V_89 ;
T_4 * V_71 = F_32 ( V_68 ) ;
if ( V_71 == NULL )
return 0 ;
V_6 = F_30 ( V_68 ) ;
switch ( V_84 ) {
case V_90 :
V_6 -> V_80 = 0 ;
V_6 -> V_77 = 0 ;
V_70 = 1 ;
break;
case V_91 :
V_70 = F_43 ( V_68 ) ;
if ( V_70 > 0 )
V_70 = F_45 ( V_71 ) ;
break;
case V_92 :
V_88 = - 1 ;
V_89 = - 1 ;
if ( V_86 != NULL ) {
V_87 = V_86 ;
if ( * V_87 == 0 )
V_88 = ( int ) V_85 ;
else
V_89 = ( int ) V_85 ;
} else {
V_88 = ( int ) V_85 ;
V_89 = V_88 ;
}
if ( V_88 != - 1 ) {
F_4 ( V_6 -> V_66 ) ;
V_6 -> V_66 = NULL ;
V_6 -> V_60 = V_88 ;
}
if ( V_89 != - 1 ) {
F_4 ( V_6 -> V_67 ) ;
V_6 -> V_67 = NULL ;
V_6 -> V_62 = V_89 ;
}
V_70 = 1 ;
break;
case V_93 :
F_33 ( V_68 ) ;
V_70 = F_46 ( V_71 , V_84 , V_85 , V_86 ) ;
F_39 ( V_68 ) ;
break;
default:
V_70 = F_46 ( V_71 , V_84 , V_85 , V_86 ) ;
break;
}
return V_70 ;
}
static long F_47 ( T_4 * V_68 , int V_84 , T_6 * V_94 )
{
T_4 * V_71 = F_32 ( V_68 ) ;
if ( V_71 == NULL )
return 0 ;
return F_48 ( V_71 , V_84 , V_94 ) ;
}
