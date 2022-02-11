static void * F_1 ( void * V_1 , unsigned int V_2 , unsigned int V_3 )
{
void * V_4 ;
V_4 = F_2 ( V_2 * V_3 ) ;
if ( V_4 )
memset ( V_4 , 0 , V_2 * V_3 ) ;
return V_4 ;
}
static void F_3 ( void * V_1 , void * V_5 )
{
F_4 ( V_5 ) ;
}
static int F_5 ( T_1 * V_6 )
{
int V_7 ;
struct V_8 * V_9 =
(struct V_8 * ) F_2 ( sizeof( struct V_8 ) ) ;
if ( V_9 == NULL )
goto V_7;
V_9 -> V_10 . V_11 = F_1 ;
V_9 -> V_10 . V_12 = F_3 ;
V_9 -> V_10 . V_1 = V_13 ;
V_9 -> V_10 . V_14 = V_13 ;
V_9 -> V_10 . V_15 = V_13 ;
V_9 -> V_10 . V_16 = 0 ;
V_9 -> V_10 . V_17 = 0 ;
V_7 = F_6 ( & V_9 -> V_10 , V_18 , sizeof( V_19 ) ) ;
if ( V_7 != V_20 )
goto V_7;
V_9 -> V_21 . V_11 = F_1 ;
V_9 -> V_21 . V_12 = F_3 ;
V_9 -> V_21 . V_1 = V_13 ;
V_9 -> V_21 . V_14 = V_13 ;
V_9 -> V_21 . V_15 = V_13 ;
V_9 -> V_21 . V_16 = 0 ;
V_9 -> V_21 . V_17 = 0 ;
V_7 = F_7 ( & V_9 -> V_21 , V_22 ,
V_18 , sizeof( V_19 ) ) ;
if ( V_7 != V_20 )
goto V_7;
F_8 ( V_23 , V_6 , & V_6 -> V_24 ) ;
F_9 ( & V_6 -> V_24 , V_25 , V_9 ) ;
return 1 ;
V_7:
if ( V_9 )
F_4 ( V_9 ) ;
return 0 ;
}
static void F_10 ( T_1 * V_6 )
{
struct V_8 * V_9 =
(struct V_8 * ) F_11 ( & V_6 -> V_24 ,
V_25 ) ;
F_12 ( & V_9 -> V_10 ) ;
F_13 ( & V_9 -> V_21 ) ;
F_4 ( V_9 ) ;
F_14 ( V_23 , V_6 , & V_6 -> V_24 ) ;
}
static int F_15 ( T_1 * V_6 , unsigned char * V_26 ,
unsigned int V_27 , unsigned char * V_28 ,
unsigned int V_29 )
{
int V_7 = V_20 ;
struct V_8 * V_9 =
(struct V_8 * ) F_11 ( & V_6 -> V_24 ,
V_25 ) ;
if ( V_9 == NULL )
return - 1 ;
V_9 -> V_21 . V_14 = V_28 ;
V_9 -> V_21 . V_16 = V_29 ;
V_9 -> V_21 . V_15 = V_26 ;
V_9 -> V_21 . V_17 = V_27 ;
if ( V_29 > 0 )
V_7 = F_16 ( & V_9 -> V_21 , V_30 ) ;
if ( V_7 != V_20 )
return - 1 ;
# ifdef F_17
fprintf ( V_31 , L_1 ,
V_29 , V_27 - V_9 -> V_21 . V_17 ,
( V_29 != V_27 - V_9 -> V_21 . V_17 ) ? L_2 : L_3 ) ;
# endif
return V_27 - V_9 -> V_21 . V_17 ;
}
static int F_18 ( T_1 * V_6 , unsigned char * V_26 ,
unsigned int V_27 , unsigned char * V_28 ,
unsigned int V_29 )
{
int V_7 = V_20 ;
struct V_8 * V_9 =
(struct V_8 * ) F_11 ( & V_6 -> V_24 ,
V_25 ) ;
if ( V_9 == NULL )
return 0 ;
V_9 -> V_10 . V_14 = V_28 ;
V_9 -> V_10 . V_16 = V_29 ;
V_9 -> V_10 . V_15 = V_26 ;
V_9 -> V_10 . V_17 = V_27 ;
if ( V_29 > 0 )
V_7 = F_19 ( & V_9 -> V_10 , V_30 ) ;
if ( V_7 != V_20 )
return - 1 ;
# ifdef F_17
fprintf ( V_31 , L_4 ,
V_29 , V_27 - V_9 -> V_10 . V_17 ,
( V_29 != V_27 - V_9 -> V_10 . V_17 ) ? L_2 : L_3 ) ;
# endif
return V_27 - V_9 -> V_10 . V_17 ;
}
T_2 * F_20 ( void )
{
T_2 * V_32 = & V_33 ;
#ifdef F_21
if ( ! V_34 ) {
# if F_22 ( V_35 ) || F_22 ( V_36 )
V_37 = F_23 ( NULL , L_5 , NULL , 0 ) ;
# else
V_37 = F_23 ( NULL , L_6 , NULL , 0 ) ;
# endif
if ( V_37 != NULL ) {
V_38 = ( V_39 ) F_24 ( V_37 , L_7 ) ;
V_40
= ( V_41 ) F_24 ( V_37 , L_8 ) ;
V_42 = ( V_43 ) F_24 ( V_37 , L_9 ) ;
V_44
= ( V_45 ) F_24 ( V_37 , L_10 ) ;
V_46
= ( V_47 ) F_24 ( V_37 , L_11 ) ;
V_48 = ( V_49 ) F_24 ( V_37 , L_12 ) ;
V_50
= ( V_51 ) F_24 ( V_37 , L_13 ) ;
V_52 = ( V_53 ) F_24 ( V_37 , L_14 ) ;
if ( V_38 && V_40 && V_42
&& V_44 && V_46
&& V_48 && V_50 && V_52 )
V_34 ++ ;
}
}
#endif
#ifdef F_21
if ( V_34 )
#endif
#if F_22 ( V_54 ) || F_22 ( F_21 )
{
if ( V_25 == - 1 ) {
F_25 ( V_55 ) ;
if ( V_25 == - 1 )
V_25 =
F_26 ( V_23 ,
0 , NULL , NULL , NULL , NULL ) ;
F_27 ( V_55 ) ;
if ( V_25 == - 1 )
goto V_7;
}
V_32 = & V_56 ;
}
V_7:
#endif
return ( V_32 ) ;
}
void F_28 ( void )
{
#ifdef F_21
if ( V_37 )
F_29 ( V_37 ) ;
#endif
}
T_3 * F_30 ( void )
{
return & V_57 ;
}
static int F_31 ( T_4 * V_58 )
{
T_5 * V_6 ;
# ifdef F_21
( void ) F_20 () ;
if ( ! V_34 ) {
F_32 ( V_59 , V_60 ) ;
return 0 ;
}
# endif
V_6 = F_2 ( sizeof( T_5 ) ) ;
if ( ! V_6 ) {
F_32 ( V_59 , V_61 ) ;
return 0 ;
}
V_6 -> V_62 = NULL ;
V_6 -> V_63 = NULL ;
V_6 -> V_64 = V_65 ;
V_6 -> V_66 = V_65 ;
V_6 -> V_67 . V_11 = V_13 ;
V_6 -> V_67 . V_12 = V_13 ;
V_6 -> V_67 . V_14 = NULL ;
V_6 -> V_67 . V_16 = 0 ;
V_6 -> V_67 . V_15 = NULL ;
V_6 -> V_67 . V_17 = 0 ;
V_6 -> V_68 . V_11 = V_13 ;
V_6 -> V_68 . V_12 = V_13 ;
V_6 -> V_68 . V_14 = NULL ;
V_6 -> V_68 . V_16 = 0 ;
V_6 -> V_68 . V_15 = NULL ;
V_6 -> V_68 . V_17 = 0 ;
V_6 -> V_69 = 0 ;
V_6 -> V_70 = V_22 ;
V_58 -> V_71 = 1 ;
V_58 -> V_72 = ( char * ) V_6 ;
V_58 -> V_73 = 0 ;
return 1 ;
}
static int F_33 ( T_4 * V_58 )
{
T_5 * V_6 ;
if ( ! V_58 )
return 0 ;
V_6 = ( T_5 * ) V_58 -> V_72 ;
if ( V_6 -> V_62 ) {
F_12 ( & V_6 -> V_67 ) ;
F_4 ( V_6 -> V_62 ) ;
}
if ( V_6 -> V_63 ) {
F_13 ( & V_6 -> V_68 ) ;
F_4 ( V_6 -> V_63 ) ;
}
F_4 ( V_6 ) ;
V_58 -> V_72 = NULL ;
V_58 -> V_71 = 0 ;
V_58 -> V_73 = 0 ;
return 1 ;
}
static int F_34 ( T_4 * V_74 , char * V_26 , int V_75 )
{
T_5 * V_6 ;
int V_76 ;
V_19 * V_67 ;
if ( ! V_26 || ! V_75 )
return 0 ;
V_6 = ( T_5 * ) V_74 -> V_72 ;
V_67 = & V_6 -> V_67 ;
F_35 ( V_74 ) ;
if ( ! V_6 -> V_62 ) {
V_6 -> V_62 = F_2 ( V_6 -> V_64 ) ;
if ( ! V_6 -> V_62 ) {
F_32 ( V_77 , V_61 ) ;
return 0 ;
}
F_36 ( V_67 ) ;
V_67 -> V_14 = V_6 -> V_62 ;
V_67 -> V_16 = 0 ;
}
V_67 -> V_15 = ( unsigned char * ) V_26 ;
V_67 -> V_17 = ( unsigned int ) V_75 ;
for (; ; ) {
while ( V_67 -> V_16 ) {
V_76 = F_19 ( V_67 , 0 ) ;
if ( ( V_76 != V_20 ) && ( V_76 != V_78 ) ) {
F_32 ( V_77 , V_79 ) ;
F_37 ( 2 , L_15 , F_38 ( V_76 ) ) ;
return 0 ;
}
if ( ( V_76 == V_78 ) || ! V_67 -> V_17 )
return V_75 - V_67 -> V_17 ;
}
V_76 = F_39 ( V_74 -> V_80 , V_6 -> V_62 , V_6 -> V_64 ) ;
if ( V_76 <= 0 ) {
int V_81 = V_75 - V_67 -> V_17 ;
F_40 ( V_74 ) ;
if ( V_76 < 0 )
return ( V_81 > 0 ) ? V_81 : V_76 ;
return V_81 ;
}
V_67 -> V_16 = V_76 ;
V_67 -> V_14 = V_6 -> V_62 ;
}
}
static int F_41 ( T_4 * V_74 , const char * V_28 , int V_82 )
{
T_5 * V_6 ;
int V_76 ;
V_19 * V_68 ;
if ( ! V_28 || ! V_82 )
return 0 ;
V_6 = ( T_5 * ) V_74 -> V_72 ;
if ( V_6 -> V_69 )
return 0 ;
V_68 = & V_6 -> V_68 ;
F_35 ( V_74 ) ;
if ( ! V_6 -> V_63 ) {
V_6 -> V_63 = F_2 ( V_6 -> V_66 ) ;
if ( ! V_6 -> V_63 ) {
F_32 ( V_83 , V_61 ) ;
return 0 ;
}
V_6 -> V_84 = V_6 -> V_63 ;
V_6 -> V_85 = 0 ;
F_42 ( V_68 , V_6 -> V_70 ) ;
V_68 -> V_15 = V_6 -> V_63 ;
V_68 -> V_17 = V_6 -> V_66 ;
}
V_68 -> V_14 = ( void * ) V_28 ;
V_68 -> V_16 = V_82 ;
for (; ; ) {
while ( V_6 -> V_85 ) {
V_76 = F_43 ( V_74 -> V_80 , V_6 -> V_84 , V_6 -> V_85 ) ;
if ( V_76 <= 0 ) {
int V_81 = V_82 - V_68 -> V_16 ;
F_40 ( V_74 ) ;
if ( V_76 < 0 )
return ( V_81 > 0 ) ? V_81 : V_76 ;
return V_81 ;
}
V_6 -> V_84 += V_76 ;
V_6 -> V_85 -= V_76 ;
}
if ( ! V_68 -> V_16 )
return V_82 ;
V_6 -> V_84 = V_6 -> V_63 ;
V_68 -> V_15 = V_6 -> V_63 ;
V_68 -> V_17 = V_6 -> V_66 ;
V_76 = F_16 ( V_68 , 0 ) ;
if ( V_76 != V_20 ) {
F_32 ( V_83 , V_86 ) ;
F_37 ( 2 , L_15 , F_38 ( V_76 ) ) ;
return 0 ;
}
V_6 -> V_85 = V_6 -> V_66 - V_68 -> V_17 ;
}
}
static int F_44 ( T_4 * V_74 )
{
T_5 * V_6 ;
int V_76 ;
V_19 * V_68 ;
V_6 = ( T_5 * ) V_74 -> V_72 ;
if ( ! V_6 -> V_63 || ( V_6 -> V_69 && ! V_6 -> V_85 ) )
return 1 ;
V_68 = & V_6 -> V_68 ;
F_35 ( V_74 ) ;
V_68 -> V_14 = NULL ;
V_68 -> V_16 = 0 ;
for (; ; ) {
while ( V_6 -> V_85 ) {
V_76 = F_43 ( V_74 -> V_80 , V_6 -> V_84 , V_6 -> V_85 ) ;
if ( V_76 <= 0 ) {
F_40 ( V_74 ) ;
return V_76 ;
}
V_6 -> V_84 += V_76 ;
V_6 -> V_85 -= V_76 ;
}
if ( V_6 -> V_69 )
return 1 ;
V_6 -> V_84 = V_6 -> V_63 ;
V_68 -> V_15 = V_6 -> V_63 ;
V_68 -> V_17 = V_6 -> V_66 ;
V_76 = F_16 ( V_68 , V_87 ) ;
if ( V_76 == V_78 )
V_6 -> V_69 = 1 ;
else if ( V_76 != V_20 ) {
F_32 ( V_88 , V_86 ) ;
F_37 ( 2 , L_15 , F_38 ( V_76 ) ) ;
return 0 ;
}
V_6 -> V_85 = V_6 -> V_66 - V_68 -> V_17 ;
}
}
static long F_45 ( T_4 * V_74 , int V_89 , long V_90 , void * V_72 )
{
T_5 * V_6 ;
int V_76 , * V_91 ;
int V_92 , V_93 ;
if ( ! V_74 -> V_80 )
return 0 ;
V_6 = ( T_5 * ) V_74 -> V_72 ;
switch ( V_89 ) {
case V_94 :
V_6 -> V_85 = 0 ;
V_6 -> V_69 = 0 ;
V_76 = 1 ;
break;
case V_95 :
V_76 = F_44 ( V_74 ) ;
if ( V_76 > 0 )
V_76 = F_46 ( V_74 -> V_80 ) ;
break;
case V_96 :
V_92 = - 1 ;
V_93 = - 1 ;
if ( V_72 != NULL ) {
V_91 = V_72 ;
if ( * V_91 == 0 )
V_92 = ( int ) V_90 ;
else
V_93 = ( int ) V_90 ;
} else {
V_92 = ( int ) V_90 ;
V_93 = V_92 ;
}
if ( V_92 != - 1 ) {
if ( V_6 -> V_62 ) {
F_4 ( V_6 -> V_62 ) ;
V_6 -> V_62 = NULL ;
}
V_6 -> V_64 = V_92 ;
}
if ( V_93 != - 1 ) {
if ( V_6 -> V_63 ) {
F_4 ( V_6 -> V_63 ) ;
V_6 -> V_63 = NULL ;
}
V_6 -> V_66 = V_93 ;
}
V_76 = 1 ;
break;
case V_97 :
F_35 ( V_74 ) ;
V_76 = F_47 ( V_74 -> V_80 , V_89 , V_90 , V_72 ) ;
F_40 ( V_74 ) ;
break;
default:
V_76 = F_47 ( V_74 -> V_80 , V_89 , V_90 , V_72 ) ;
break;
}
return V_76 ;
}
static long F_48 ( T_4 * V_74 , int V_89 , T_6 * V_98 )
{
if ( ! V_74 -> V_80 )
return 0 ;
return F_49 ( V_74 -> V_80 , V_89 , V_98 ) ;
}
