static void F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 -> V_6 ;
V_4 -> V_7 = V_2 -> V_8 ;
V_4 -> V_9 = V_2 -> V_10 ;
V_4 -> V_11 = V_2 -> V_12 ;
V_4 -> V_13 = V_2 -> V_14 ;
V_4 -> V_15 = V_2 -> V_16 ;
V_4 -> V_17 . V_18 = V_2 -> V_19 ;
V_4 -> V_17 . V_20 = 0 ;
V_4 -> ctime . V_18 = V_2 -> V_21 ;
V_4 -> ctime . V_20 = 0 ;
V_4 -> V_22 . V_18 = V_2 -> V_23 ;
V_4 -> V_22 . V_20 = 0 ;
V_4 -> V_24 = V_2 -> V_25 ;
V_4 -> V_26 = V_2 -> V_27 ;
V_4 -> V_28 = F_2 ( V_2 -> V_29 ) ;
V_4 -> V_30 = F_3 ( V_2 -> V_29 ) ;
}
int F_4 ( const char * V_31 , struct V_3 * V_4 , int V_32 )
{
struct V_1 V_2 ;
if ( V_32 >= 0 ) {
if ( F_5 ( V_32 , & V_2 ) < 0 )
return - V_33 ;
} else if ( F_6 ( V_31 , & V_2 ) < 0 ) {
return - V_33 ;
}
F_1 ( & V_2 , V_4 ) ;
return 0 ;
}
int F_7 ( char * V_31 , int V_34 , int V_35 , int V_36 )
{
int V_7 = 0 ;
if ( V_34 )
V_7 = V_37 ;
if ( V_35 )
V_7 |= V_38 ;
if ( V_36 )
V_7 |= V_39 ;
if ( F_8 ( V_31 , V_7 ) != 0 )
return - V_33 ;
else return 0 ;
}
int F_9 ( char * V_31 , int V_34 , int V_35 , int V_40 )
{
int V_7 = 0 , V_32 ;
if ( V_34 && ! V_35 )
V_7 = V_41 ;
else if ( ! V_34 && V_35 )
V_7 = V_42 ;
else if ( V_34 && V_35 )
V_7 = V_43 ;
else F_10 ( L_1 ) ;
if ( V_40 )
V_7 |= V_44 ;
V_32 = F_11 ( V_31 , V_7 ) ;
if ( V_32 < 0 )
return - V_33 ;
else return V_32 ;
}
void * F_12 ( char * V_31 , int * V_45 )
{
T_1 * V_46 ;
V_46 = F_13 ( V_31 ) ;
* V_45 = V_33 ;
return V_46 ;
}
void F_14 ( void * V_47 , unsigned long long V_48 )
{
T_1 * V_46 = V_47 ;
F_15 ( V_46 , V_48 ) ;
}
char * F_16 ( void * V_47 , unsigned long long * V_49 ,
unsigned long long * V_50 , int * V_51 ,
unsigned int * V_52 )
{
T_1 * V_46 = V_47 ;
struct V_53 * V_54 ;
V_54 = F_17 ( V_46 ) ;
if ( V_54 == NULL )
return NULL ;
* V_51 = strlen ( V_54 -> V_55 ) ;
* V_50 = V_54 -> V_56 ;
* V_52 = V_54 -> V_57 ;
* V_49 = V_54 -> V_58 ;
return V_54 -> V_55 ;
}
int F_18 ( int V_32 , unsigned long long * V_59 , char * V_2 , int V_60 )
{
int V_61 ;
V_61 = F_19 ( V_32 , V_2 , V_60 , * V_59 ) ;
if ( V_61 < 0 )
return - V_33 ;
* V_59 += V_61 ;
return V_61 ;
}
int F_20 ( int V_32 , unsigned long long * V_59 , const char * V_2 , int V_60 )
{
int V_61 ;
V_61 = F_21 ( V_32 , V_2 , V_60 , * V_59 ) ;
if ( V_61 < 0 )
return - V_33 ;
* V_59 += V_61 ;
return V_61 ;
}
int F_22 ( int V_32 , long long V_59 , int V_62 )
{
int V_63 ;
V_63 = F_23 ( V_32 , V_59 , V_62 ) ;
if ( V_63 < 0 )
return - V_33 ;
return 0 ;
}
int F_24 ( int V_32 , int V_64 )
{
int V_63 ;
if ( V_64 )
V_63 = F_25 ( V_32 ) ;
else
V_63 = F_26 ( V_32 ) ;
if ( V_63 < 0 )
return - V_33 ;
return 0 ;
}
int F_27 ( int V_65 , int V_32 )
{
return F_28 ( V_65 , V_32 ) ;
}
void F_29 ( void * V_47 )
{
F_30 ( * ( ( int * ) V_47 ) ) ;
}
void F_31 ( void * V_47 )
{
F_32 ( V_47 ) ;
}
int F_33 ( char * V_66 , int V_7 )
{
int V_32 ;
V_32 = F_11 ( V_66 , V_67 | V_43 , V_7 ) ;
if ( V_32 < 0 )
return - V_33 ;
return V_32 ;
}
int F_34 ( const char * V_68 , struct V_69 * V_70 , int V_32 )
{
struct V_3 V_71 ;
struct V_72 V_73 [ 2 ] ;
int V_74 , V_75 ;
if ( V_70 -> V_76 & V_77 ) {
if ( V_32 >= 0 ) {
if ( F_35 ( V_32 , V_70 -> V_78 ) != 0 )
return - V_33 ;
} else if ( F_36 ( V_68 , V_70 -> V_78 ) != 0 ) {
return - V_33 ;
}
}
if ( V_70 -> V_76 & V_79 ) {
if ( V_32 >= 0 ) {
if ( F_37 ( V_32 , V_70 -> V_80 , - 1 ) )
return - V_33 ;
} else if ( F_38 ( V_68 , V_70 -> V_80 , - 1 ) ) {
return - V_33 ;
}
}
if ( V_70 -> V_76 & V_81 ) {
if ( V_32 >= 0 ) {
if ( F_37 ( V_32 , - 1 , V_70 -> V_82 ) )
return - V_33 ;
} else if ( F_38 ( V_68 , - 1 , V_70 -> V_82 ) ) {
return - V_33 ;
}
}
if ( V_70 -> V_76 & V_83 ) {
if ( V_32 >= 0 ) {
if ( F_39 ( V_32 , V_70 -> V_84 ) )
return - V_33 ;
} else if ( F_40 ( V_68 , V_70 -> V_84 ) ) {
return - V_33 ;
}
}
V_75 = ( V_85 | V_86 ) ;
if ( V_70 -> V_76 & V_75 ) {
V_74 = F_4 ( V_68 , & V_71 , V_32 ) ;
if ( V_74 != 0 )
return V_74 ;
V_73 [ 0 ] . V_18 = V_71 . V_17 . V_18 ;
V_73 [ 0 ] . V_87 = V_71 . V_17 . V_20 / 1000 ;
V_73 [ 1 ] . V_18 = V_71 . V_22 . V_18 ;
V_73 [ 1 ] . V_87 = V_71 . V_22 . V_20 / 1000 ;
if ( V_70 -> V_76 & V_85 ) {
V_73 [ 0 ] . V_18 = V_70 -> V_88 . V_18 ;
V_73 [ 0 ] . V_87 = V_70 -> V_88 . V_20 / 1000 ;
}
if ( V_70 -> V_76 & V_86 ) {
V_73 [ 1 ] . V_18 = V_70 -> V_89 . V_18 ;
V_73 [ 1 ] . V_87 = V_70 -> V_89 . V_20 / 1000 ;
}
if ( V_32 >= 0 ) {
if ( F_41 ( V_32 , V_73 ) != 0 )
return - V_33 ;
} else if ( F_42 ( V_68 , V_73 ) != 0 ) {
return - V_33 ;
}
}
if ( V_70 -> V_76 & ( V_90 | V_91 ) ) {
V_74 = F_4 ( V_68 , & V_71 , V_32 ) ;
V_70 -> V_88 = V_71 . V_17 ;
V_70 -> V_89 = V_71 . V_22 ;
if ( V_74 != 0 )
return V_74 ;
}
return 0 ;
}
int F_43 ( const char * V_92 , const char * V_93 )
{
int V_74 ;
V_74 = F_44 ( V_93 , V_92 ) ;
if ( V_74 )
return - V_33 ;
return 0 ;
}
int F_45 ( const char * V_68 )
{
int V_74 ;
V_74 = F_46 ( V_68 ) ;
if ( V_74 )
return - V_33 ;
return 0 ;
}
int F_47 ( const char * V_68 , int V_7 )
{
int V_74 ;
V_74 = F_48 ( V_68 , V_7 ) ;
if ( V_74 )
return - V_33 ;
return 0 ;
}
int F_49 ( const char * V_68 )
{
int V_74 ;
V_74 = F_50 ( V_68 ) ;
if ( V_74 )
return - V_33 ;
return 0 ;
}
int F_51 ( const char * V_68 , int V_7 , unsigned int V_94 , unsigned int V_95 )
{
int V_74 ;
V_74 = F_52 ( V_68 , V_7 , F_53 ( V_94 , V_95 ) ) ;
if ( V_74 )
return - V_33 ;
return 0 ;
}
int F_54 ( const char * V_93 , const char * V_92 )
{
int V_74 ;
V_74 = F_55 ( V_93 , V_92 ) ;
if ( V_74 )
return - V_33 ;
return 0 ;
}
int F_56 ( char * V_68 , char * V_2 , int V_15 )
{
int V_61 ;
V_61 = F_57 ( V_68 , V_2 , V_15 ) ;
if ( V_61 < 0 )
return - V_33 ;
if ( V_61 < V_15 )
V_2 [ V_61 ] = '\0' ;
return V_61 ;
}
int F_58 ( char * V_92 , char * V_93 )
{
int V_74 ;
V_74 = rename ( V_92 , V_93 ) ;
if ( V_74 < 0 )
return - V_33 ;
return 0 ;
}
int F_59 ( char * V_92 , char * V_93 , unsigned int V_96 )
{
int V_74 ;
#ifndef F_60
# ifdef F_61
# define F_60 316
# endif
# ifdef F_62
# define F_60 353
# endif
#endif
#ifdef F_60
V_74 = F_63 ( F_60 , V_97 , V_92 , V_97 , V_93 , V_96 ) ;
if ( V_74 < 0 ) {
if ( V_33 != V_98 )
return - V_33 ;
else
return - V_99 ;
}
return 0 ;
#else
return - V_99 ;
#endif
}
int F_64 ( char * V_100 , long * V_101 , long long * V_102 ,
long long * V_103 , long long * V_104 ,
long long * V_105 , long long * V_106 ,
void * V_107 , int V_108 , long * V_109 )
{
struct V_110 V_2 ;
int V_74 ;
V_74 = V_110 ( V_100 , & V_2 ) ;
if ( V_74 < 0 )
return - V_33 ;
* V_101 = V_2 . V_111 ;
* V_102 = V_2 . V_112 ;
* V_103 = V_2 . V_113 ;
* V_104 = V_2 . V_114 ;
* V_105 = V_2 . V_115 ;
* V_106 = V_2 . V_116 ;
memcpy ( V_107 , & V_2 . V_117 ,
sizeof( V_2 . V_117 ) > V_108 ? V_108 :
sizeof( V_2 . V_117 ) ) ;
* V_109 = V_2 . V_118 ;
return 0 ;
}
