char * F_1 ( int V_1 )
{
if ( V_1 == V_2 ) {
if ( ! V_3 ) {
V_3 = true ;
F_2 ( V_4 , sizeof( V_4 ) ,
V_5 [ V_1 ] . V_6 ,
V_7 ) ;
}
return V_4 ;
}
return ( char * ) V_5 [ V_1 ] . V_6 ;
}
int F_3 ( const char * V_8 )
{
char * V_9 , * V_10 = NULL ;
bool V_11 = false ;
char * V_12 ;
int V_13 ;
V_12 = malloc ( strlen ( V_8 ) + 1 ) ;
if ( ! V_12 )
return - V_14 ;
strcpy ( V_12 , V_8 ) ;
V_9 = strtok_r ( ( char * ) V_12 , L_1 , & V_10 ) ;
while ( V_9 ) {
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
struct V_16 * V_17 = & V_5 [ V_13 ] ;
if ( strstr ( V_17 -> V_18 , V_9 ) )
V_17 -> V_19 = V_11 = true ;
}
V_9 = strtok_r ( NULL , L_1 , & V_10 ) ;
}
free ( V_12 ) ;
if ( V_11 )
return 0 ;
F_4 ( L_2 , V_8 ) ;
return - 1 ;
}
int F_5 ( void )
{
const char * V_20 = F_6 () ;
bool V_11 = false ;
int V_13 ;
if ( ! V_20 )
return - V_21 ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
char V_22 [ V_23 ] ;
struct V_16 * V_17 = & V_5 [ V_13 ] ;
struct V_24 V_25 ;
F_2 ( V_22 , V_23 , L_3 ,
V_20 , V_17 -> V_26 ) ;
if ( ! V_24 ( V_22 , & V_25 ) )
V_17 -> V_27 = V_11 = true ;
}
return V_11 ? 0 : - V_21 ;
}
int F_7 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_1 V_31 = 0 , V_1 ;
T_2 V_32 = V_33 ;
T_2 V_34 , V_35 ;
V_29 -= 1 ;
V_28 [ 0 ] = '\0' ;
if ( V_30 )
V_32 = V_30 -> V_36 . V_37 ;
V_34 = V_32 & V_38 ;
V_35 = V_32 & V_39 ;
V_32 &= ~ ( V_38 | V_39 ) ;
for ( V_1 = 0 ; V_32 && V_1 < F_8 ( V_40 ) ; V_1 ++ , V_32 >>= 1 ) {
if ( ! ( V_32 & 0x1 ) )
continue;
if ( V_31 ) {
strcat ( V_28 , L_4 ) ;
V_31 += 4 ;
}
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , V_40 [ V_1 ] ) ;
}
if ( * V_28 == '\0' )
V_31 += F_2 ( V_28 , V_29 - V_31 , L_5 ) ;
if ( V_34 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_6 ) ;
if ( V_35 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_7 ) ;
return V_31 ;
}
int F_9 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_1 V_1 , V_31 = 0 ;
T_2 V_32 = V_41 ;
T_2 V_34 , V_35 ;
if ( V_30 )
V_32 = V_30 -> V_36 . V_42 ;
V_29 -= 1 ;
V_28 [ 0 ] = '\0' ;
V_34 = V_32 & V_43 ;
V_35 = V_32 & V_44 ;
V_32 &= ~ ( V_43 | V_44 ) ;
for ( V_1 = 0 ; V_32 && V_1 < F_8 ( V_42 ) ; V_1 ++ , V_32 >>= 1 ) {
if ( ! ( V_32 & 0x1 ) )
continue;
if ( V_31 ) {
strcat ( V_28 , L_4 ) ;
V_31 += 4 ;
}
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , V_42 [ V_1 ] ) ;
}
if ( * V_28 == '\0' )
V_31 += F_2 ( V_28 , V_29 - V_31 , L_5 ) ;
if ( V_34 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_6 ) ;
if ( V_35 )
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , L_7 ) ;
return V_31 ;
}
int F_10 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_1 V_1 , V_31 = 0 ;
T_2 V_32 = V_45 ;
V_29 -= 1 ;
V_28 [ 0 ] = '\0' ;
if ( V_30 )
V_32 = V_30 -> V_36 . V_46 ;
for ( V_1 = 0 ; V_32 && V_1 < F_8 ( V_47 ) ; V_1 ++ , V_32 >>= 1 ) {
if ( ! ( V_32 & 0x1 ) )
continue;
if ( V_31 ) {
strcat ( V_28 , L_4 ) ;
V_31 += 4 ;
}
V_31 += F_2 ( V_28 + V_31 , V_29 - V_31 , V_47 [ V_1 ] ) ;
}
if ( * V_28 == '\0' )
V_31 += F_2 ( V_28 , V_29 - V_31 , L_5 ) ;
return V_31 ;
}
int F_11 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
T_2 V_48 = V_49 ;
int V_31 ;
if ( V_30 )
V_48 = V_30 -> V_36 . V_50 ;
if ( V_48 & V_49 )
V_31 = F_2 ( V_28 , V_29 , L_5 ) ;
else if ( V_48 & V_51 )
V_31 = F_2 ( V_28 , V_29 , L_8 ) ;
else
V_31 = F_2 ( V_28 , V_29 , L_9 ) ;
return V_31 ;
}
int F_12 ( char * V_28 , T_1 V_29 , struct V_30 * V_30 )
{
int V_1 = 0 ;
V_1 += F_9 ( V_28 , V_29 , V_30 ) ;
V_1 += F_2 ( V_28 + V_1 , V_29 - V_1 , L_10 ) ;
V_1 += F_10 ( V_28 + V_1 , V_29 - V_1 , V_30 ) ;
V_1 += F_2 ( V_28 + V_1 , V_29 - V_1 , L_11 ) ;
V_1 += F_7 ( V_28 + V_1 , V_29 - V_1 , V_30 ) ;
V_1 += F_2 ( V_28 + V_1 , V_29 - V_1 , L_12 ) ;
V_1 += F_11 ( V_28 + V_1 , V_29 - V_1 , V_30 ) ;
return V_1 ;
}
int F_13 ( struct V_52 * V_53 , struct V_30 * V_54 )
{
union V_55 * V_36 = & V_54 -> V_36 ;
T_2 V_56 = V_54 -> V_56 . V_57 ;
T_2 V_58 = V_36 -> V_59 ;
T_2 V_60 = V_36 -> V_42 ;
T_2 V_61 = V_36 -> V_46 ;
T_2 V_62 = V_36 -> V_50 ;
int V_63 = 0 ;
#define F_14 ( T_3 ) \
do { \
stats->__f++; \
stats->tot_hitm++; \
} while (0)
#define F_15 ( T_4 , T_5 ) PERF_MEM_##a##_##b
V_53 -> V_64 ++ ;
if ( V_62 & F_15 ( V_65 , V_66 ) ) V_53 -> V_67 ++ ;
if ( V_58 & F_15 ( V_68 , V_69 ) ) {
V_53 -> V_70 ++ ;
if ( ! V_56 ) {
V_53 -> V_71 ++ ;
return - 1 ;
}
if ( V_60 & F_15 ( V_72 , V_73 ) ) {
if ( V_60 & F_15 ( V_72 , V_74 ) ) V_53 -> V_75 ++ ;
if ( V_60 & F_15 ( V_72 , V_76 ) ) V_53 -> V_77 ++ ;
if ( V_60 & F_15 ( V_72 , V_78 ) ) V_53 -> V_79 ++ ;
if ( V_60 & F_15 ( V_72 , V_80 ) ) V_53 -> V_81 ++ ;
if ( V_60 & F_15 ( V_72 , V_82 ) ) V_53 -> V_83 ++ ;
if ( V_60 & F_15 ( V_72 , V_84 ) ) {
if ( V_61 & F_15 ( V_85 , V_86 ) )
F_14 ( V_87 ) ;
else
V_53 -> V_88 ++ ;
}
if ( V_60 & F_15 ( V_72 , V_89 ) ) {
V_53 -> V_90 ++ ;
if ( V_61 & F_15 ( V_85 , V_73 ) )
V_53 -> V_91 ++ ;
else
V_53 -> V_92 ++ ;
}
if ( ( V_60 & F_15 ( V_72 , V_93 ) ) ||
( V_60 & F_15 ( V_72 , V_94 ) ) ) {
V_53 -> V_95 ++ ;
if ( V_61 & F_15 ( V_85 , V_73 ) )
V_53 -> V_91 ++ ;
else
V_53 -> V_92 ++ ;
}
}
if ( ( V_60 & F_15 ( V_72 , V_96 ) ) ||
( V_60 & F_15 ( V_72 , V_97 ) ) ) {
if ( V_61 & F_15 ( V_85 , V_73 ) )
V_53 -> V_98 ++ ;
else if ( V_61 & F_15 ( V_85 , V_86 ) )
F_14 ( V_99 ) ;
}
if ( ( V_60 & F_15 ( V_72 , V_100 ) ) )
V_53 -> V_101 ++ ;
} else if ( V_58 & F_15 ( V_68 , V_102 ) ) {
V_53 -> V_103 ++ ;
if ( ! V_56 ) {
V_53 -> V_104 ++ ;
return - 1 ;
}
if ( V_60 & F_15 ( V_72 , V_73 ) ) {
if ( V_60 & F_15 ( V_72 , V_74 ) ) V_53 -> V_105 ++ ;
if ( V_60 & F_15 ( V_72 , V_80 ) ) V_53 -> V_106 ++ ;
}
if ( V_60 & F_15 ( V_72 , V_100 ) )
if ( V_60 & F_15 ( V_72 , V_80 ) ) V_53 -> V_107 ++ ;
} else {
V_53 -> V_108 ++ ;
return - 1 ;
}
if ( ! V_54 -> V_56 . V_109 || ! V_54 -> V_110 . V_109 ) {
V_53 -> V_111 ++ ;
return - 1 ;
}
#undef F_15
#undef F_14
return V_63 ;
}
void F_16 ( struct V_52 * V_53 , struct V_52 * V_112 )
{
V_53 -> V_64 += V_112 -> V_64 ;
V_53 -> V_67 += V_112 -> V_67 ;
V_53 -> V_103 += V_112 -> V_103 ;
V_53 -> V_105 += V_112 -> V_105 ;
V_53 -> V_104 += V_112 -> V_104 ;
V_53 -> V_106 += V_112 -> V_106 ;
V_53 -> V_107 += V_112 -> V_107 ;
V_53 -> V_70 += V_112 -> V_70 ;
V_53 -> V_92 += V_112 -> V_92 ;
V_53 -> V_91 += V_112 -> V_91 ;
V_53 -> V_75 += V_112 -> V_75 ;
V_53 -> V_77 += V_112 -> V_77 ;
V_53 -> V_101 += V_112 -> V_101 ;
V_53 -> V_71 += V_112 -> V_71 ;
V_53 -> V_79 += V_112 -> V_79 ;
V_53 -> V_81 += V_112 -> V_81 ;
V_53 -> V_83 += V_112 -> V_83 ;
V_53 -> V_88 += V_112 -> V_88 ;
V_53 -> V_87 += V_112 -> V_87 ;
V_53 -> V_99 += V_112 -> V_99 ;
V_53 -> V_113 += V_112 -> V_113 ;
V_53 -> V_98 += V_112 -> V_98 ;
V_53 -> V_90 += V_112 -> V_90 ;
V_53 -> V_95 += V_112 -> V_95 ;
V_53 -> V_111 += V_112 -> V_111 ;
V_53 -> V_108 += V_112 -> V_108 ;
}
