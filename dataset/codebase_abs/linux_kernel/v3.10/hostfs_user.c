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
char * F_14 ( void * V_47 , unsigned long long * V_48 ,
unsigned long long * V_49 , int * V_50 ,
unsigned int * V_51 )
{
T_1 * V_46 = V_47 ;
struct V_52 * V_53 ;
F_15 ( V_46 , * V_48 ) ;
V_53 = F_16 ( V_46 ) ;
if ( V_53 == NULL )
return NULL ;
* V_50 = strlen ( V_53 -> V_54 ) ;
* V_49 = V_53 -> V_55 ;
* V_51 = V_53 -> V_56 ;
* V_48 = F_17 ( V_46 ) ;
return V_53 -> V_54 ;
}
int F_18 ( int V_32 , unsigned long long * V_57 , char * V_2 , int V_58 )
{
int V_59 ;
V_59 = F_19 ( V_32 , V_2 , V_58 , * V_57 ) ;
if ( V_59 < 0 )
return - V_33 ;
* V_57 += V_59 ;
return V_59 ;
}
int F_20 ( int V_32 , unsigned long long * V_57 , const char * V_2 , int V_58 )
{
int V_59 ;
V_59 = F_21 ( V_32 , V_2 , V_58 , * V_57 ) ;
if ( V_59 < 0 )
return - V_33 ;
* V_57 += V_59 ;
return V_59 ;
}
int F_22 ( int V_32 , long long V_57 , int V_60 )
{
int V_61 ;
V_61 = F_23 ( V_32 , V_57 , V_60 ) ;
if ( V_61 < 0 )
return - V_33 ;
return 0 ;
}
int F_24 ( int V_32 , int V_62 )
{
int V_61 ;
if ( V_62 )
V_61 = F_25 ( V_32 ) ;
else
V_61 = F_26 ( V_32 ) ;
if ( V_61 < 0 )
return - V_33 ;
return 0 ;
}
int F_27 ( int V_63 , int V_32 )
{
return F_28 ( V_63 , V_32 ) ;
}
void F_29 ( void * V_47 )
{
F_30 ( * ( ( int * ) V_47 ) ) ;
}
void F_31 ( void * V_47 )
{
F_32 ( V_47 ) ;
}
int F_33 ( char * V_64 , int V_65 , int V_66 , int V_67 , int V_68 ,
int V_69 , int V_70 , int V_71 , int V_72 , int V_73 )
{
int V_7 , V_32 ;
V_7 = 0 ;
V_7 |= V_65 ? V_74 : 0 ;
V_7 |= V_66 ? V_75 : 0 ;
V_7 |= V_67 ? V_76 : 0 ;
V_7 |= V_68 ? V_77 : 0 ;
V_7 |= V_69 ? V_78 : 0 ;
V_7 |= V_70 ? V_79 : 0 ;
V_7 |= V_71 ? V_80 : 0 ;
V_7 |= V_72 ? V_81 : 0 ;
V_7 |= V_73 ? V_82 : 0 ;
V_32 = F_11 ( V_64 , V_83 | V_43 , V_7 ) ;
if ( V_32 < 0 )
return - V_33 ;
return V_32 ;
}
int F_34 ( const char * V_84 , struct V_85 * V_86 , int V_32 )
{
struct V_3 V_87 ;
struct V_88 V_89 [ 2 ] ;
int V_90 , V_91 ;
if ( V_86 -> V_92 & V_93 ) {
if ( V_32 >= 0 ) {
if ( F_35 ( V_32 , V_86 -> V_94 ) != 0 )
return - V_33 ;
} else if ( F_36 ( V_84 , V_86 -> V_94 ) != 0 ) {
return - V_33 ;
}
}
if ( V_86 -> V_92 & V_95 ) {
if ( V_32 >= 0 ) {
if ( F_37 ( V_32 , V_86 -> V_96 , - 1 ) )
return - V_33 ;
} else if ( F_38 ( V_84 , V_86 -> V_96 , - 1 ) ) {
return - V_33 ;
}
}
if ( V_86 -> V_92 & V_97 ) {
if ( V_32 >= 0 ) {
if ( F_37 ( V_32 , - 1 , V_86 -> V_98 ) )
return - V_33 ;
} else if ( F_38 ( V_84 , - 1 , V_86 -> V_98 ) ) {
return - V_33 ;
}
}
if ( V_86 -> V_92 & V_99 ) {
if ( V_32 >= 0 ) {
if ( F_39 ( V_32 , V_86 -> V_100 ) )
return - V_33 ;
} else if ( F_40 ( V_84 , V_86 -> V_100 ) ) {
return - V_33 ;
}
}
V_91 = ( V_101 | V_102 ) ;
if ( V_86 -> V_92 & V_91 ) {
V_90 = F_4 ( V_84 , & V_87 , V_32 ) ;
if ( V_90 != 0 )
return V_90 ;
V_89 [ 0 ] . V_18 = V_87 . V_17 . V_18 ;
V_89 [ 0 ] . V_103 = V_87 . V_17 . V_20 / 1000 ;
V_89 [ 1 ] . V_18 = V_87 . V_22 . V_18 ;
V_89 [ 1 ] . V_103 = V_87 . V_22 . V_20 / 1000 ;
if ( V_86 -> V_92 & V_101 ) {
V_89 [ 0 ] . V_18 = V_86 -> V_104 . V_18 ;
V_89 [ 0 ] . V_103 = V_86 -> V_104 . V_20 / 1000 ;
}
if ( V_86 -> V_92 & V_102 ) {
V_89 [ 1 ] . V_18 = V_86 -> V_105 . V_18 ;
V_89 [ 1 ] . V_103 = V_86 -> V_105 . V_20 / 1000 ;
}
if ( V_32 >= 0 ) {
if ( F_41 ( V_32 , V_89 ) != 0 )
return - V_33 ;
} else if ( F_42 ( V_84 , V_89 ) != 0 ) {
return - V_33 ;
}
}
if ( V_86 -> V_92 & ( V_106 | V_107 ) ) {
V_90 = F_4 ( V_84 , & V_87 , V_32 ) ;
V_86 -> V_104 = V_87 . V_17 ;
V_86 -> V_105 = V_87 . V_22 ;
if ( V_90 != 0 )
return V_90 ;
}
return 0 ;
}
int F_43 ( const char * V_108 , const char * V_109 )
{
int V_90 ;
V_90 = F_44 ( V_109 , V_108 ) ;
if ( V_90 )
return - V_33 ;
return 0 ;
}
int F_45 ( const char * V_84 )
{
int V_90 ;
V_90 = F_46 ( V_84 ) ;
if ( V_90 )
return - V_33 ;
return 0 ;
}
int F_47 ( const char * V_84 , int V_7 )
{
int V_90 ;
V_90 = F_48 ( V_84 , V_7 ) ;
if ( V_90 )
return - V_33 ;
return 0 ;
}
int F_49 ( const char * V_84 )
{
int V_90 ;
V_90 = F_50 ( V_84 ) ;
if ( V_90 )
return - V_33 ;
return 0 ;
}
int F_51 ( const char * V_84 , int V_7 , unsigned int V_110 , unsigned int V_111 )
{
int V_90 ;
V_90 = F_52 ( V_84 , V_7 , F_53 ( V_110 , V_111 ) ) ;
if ( V_90 )
return - V_33 ;
return 0 ;
}
int F_54 ( const char * V_109 , const char * V_108 )
{
int V_90 ;
V_90 = F_55 ( V_109 , V_108 ) ;
if ( V_90 )
return - V_33 ;
return 0 ;
}
int F_56 ( char * V_84 , char * V_2 , int V_15 )
{
int V_59 ;
V_59 = F_57 ( V_84 , V_2 , V_15 ) ;
if ( V_59 < 0 )
return - V_33 ;
if ( V_59 < V_15 )
V_2 [ V_59 ] = '\0' ;
return V_59 ;
}
int F_58 ( char * V_108 , char * V_109 )
{
int V_90 ;
V_90 = rename ( V_108 , V_109 ) ;
if ( V_90 < 0 )
return - V_33 ;
return 0 ;
}
int F_59 ( char * V_112 , long * V_113 , long long * V_114 ,
long long * V_115 , long long * V_116 ,
long long * V_117 , long long * V_118 ,
void * V_119 , int V_120 , long * V_121 )
{
struct V_122 V_2 ;
int V_90 ;
V_90 = V_122 ( V_112 , & V_2 ) ;
if ( V_90 < 0 )
return - V_33 ;
* V_113 = V_2 . V_123 ;
* V_114 = V_2 . V_124 ;
* V_115 = V_2 . V_125 ;
* V_116 = V_2 . V_126 ;
* V_117 = V_2 . V_127 ;
* V_118 = V_2 . V_128 ;
memcpy ( V_119 , & V_2 . V_129 ,
sizeof( V_2 . V_129 ) > V_120 ? V_120 :
sizeof( V_2 . V_129 ) ) ;
* V_121 = V_2 . V_130 ;
return 0 ;
}
