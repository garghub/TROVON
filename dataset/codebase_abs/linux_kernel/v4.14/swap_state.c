unsigned long F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 ;
unsigned long V_4 = 0 ;
struct V_5 * V_6 ;
F_2 () ;
for ( V_1 = 0 ; V_1 < V_7 ; V_1 ++ ) {
V_3 = V_8 [ V_1 ] ;
V_6 = F_3 ( V_9 [ V_1 ] ) ;
if ( ! V_3 || ! V_6 )
continue;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_4 += V_6 [ V_2 ] . V_10 ;
}
F_4 () ;
return V_4 ;
}
void F_5 ( void )
{
F_6 ( L_1 , F_1 () ) ;
F_6 ( L_2 ,
V_11 . V_12 , V_11 . V_13 ,
V_11 . V_14 , V_11 . V_15 ) ;
F_6 ( L_3 ,
F_7 () << ( V_16 - 10 ) ) ;
F_6 ( L_4 , V_17 << ( V_16 - 10 ) ) ;
}
int F_8 ( struct V_18 * V_18 , T_1 V_19 )
{
int error , V_1 , V_3 = F_9 ( V_18 ) ;
struct V_5 * V_5 ;
T_2 V_20 = F_10 ( V_19 ) ;
F_11 ( ! F_12 ( V_18 ) , V_18 ) ;
F_11 ( F_13 ( V_18 ) , V_18 ) ;
F_11 ( ! F_14 ( V_18 ) , V_18 ) ;
F_15 ( V_18 , V_3 ) ;
F_16 ( V_18 ) ;
V_5 = F_17 ( V_19 ) ;
F_18 ( & V_5 -> V_21 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
F_19 ( V_18 + V_1 , V_19 . V_22 + V_1 ) ;
error = F_20 ( & V_5 -> V_23 ,
V_20 + V_1 , V_18 + V_1 ) ;
if ( F_21 ( error ) )
break;
}
if ( F_22 ( ! error ) ) {
V_5 -> V_10 += V_3 ;
F_23 ( F_24 ( V_18 ) , V_24 , V_3 ) ;
F_25 ( V_12 , V_3 ) ;
} else {
F_26 ( error == - V_25 ) ;
F_19 ( V_18 + V_1 , 0UL ) ;
while ( V_1 -- ) {
F_27 ( & V_5 -> V_23 , V_20 + V_1 ) ;
F_19 ( V_18 + V_1 , 0UL ) ;
}
F_28 ( V_18 ) ;
F_29 ( V_18 , V_3 ) ;
}
F_30 ( & V_5 -> V_21 ) ;
return error ;
}
int F_31 ( struct V_18 * V_18 , T_1 V_19 , T_3 V_26 )
{
int error ;
error = F_32 ( V_26 , F_33 ( V_18 ) ) ;
if ( ! error ) {
error = F_8 ( V_18 , V_19 ) ;
F_34 () ;
}
return error ;
}
void F_35 ( struct V_18 * V_18 )
{
struct V_5 * V_5 ;
int V_1 , V_3 = F_9 ( V_18 ) ;
T_1 V_19 ;
T_2 V_20 ;
F_11 ( ! F_12 ( V_18 ) , V_18 ) ;
F_11 ( ! F_13 ( V_18 ) , V_18 ) ;
F_11 ( F_36 ( V_18 ) , V_18 ) ;
V_19 . V_22 = F_37 ( V_18 ) ;
V_5 = F_17 ( V_19 ) ;
V_20 = F_10 ( V_19 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
F_27 ( & V_5 -> V_23 , V_20 + V_1 ) ;
F_19 ( V_18 + V_1 , 0 ) ;
}
F_28 ( V_18 ) ;
V_5 -> V_10 -= V_3 ;
F_23 ( F_24 ( V_18 ) , V_24 , - V_3 ) ;
F_25 ( V_13 , V_3 ) ;
}
int F_38 ( struct V_18 * V_18 )
{
T_1 V_19 ;
int V_27 ;
F_11 ( ! F_12 ( V_18 ) , V_18 ) ;
F_11 ( ! F_39 ( V_18 ) , V_18 ) ;
V_19 = F_40 ( V_18 ) ;
if ( ! V_19 . V_22 )
return 0 ;
if ( F_41 ( V_18 , V_19 ) )
goto V_28;
V_27 = F_31 ( V_18 , V_19 ,
V_29 | V_30 | V_31 ) ;
if ( V_27 )
goto V_28;
F_42 ( V_18 ) ;
return 1 ;
V_28:
F_43 ( V_18 , V_19 ) ;
return 0 ;
}
void F_44 ( struct V_18 * V_18 )
{
T_1 V_19 ;
struct V_5 * V_5 ;
V_19 . V_22 = F_37 ( V_18 ) ;
V_5 = F_17 ( V_19 ) ;
F_18 ( & V_5 -> V_21 ) ;
F_35 ( V_18 ) ;
F_30 ( & V_5 -> V_21 ) ;
F_43 ( V_18 , V_19 ) ;
F_29 ( V_18 , F_9 ( V_18 ) ) ;
}
static inline void F_45 ( struct V_18 * V_18 )
{
if ( F_13 ( V_18 ) && ! F_46 ( V_18 ) && F_47 ( V_18 ) ) {
F_48 ( V_18 ) ;
F_49 ( V_18 ) ;
}
}
void F_50 ( struct V_18 * V_18 )
{
F_45 ( V_18 ) ;
if ( ! F_51 ( V_18 ) )
F_52 ( V_18 ) ;
}
void F_53 ( struct V_18 * * V_32 , int V_3 )
{
struct V_18 * * V_33 = V_32 ;
int V_1 ;
F_54 () ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
F_45 ( V_33 [ V_1 ] ) ;
F_55 ( V_33 , V_3 , false ) ;
}
struct V_18 * F_56 ( T_1 V_19 , struct V_34 * V_35 ,
unsigned long V_36 )
{
struct V_18 * V_18 ;
unsigned long V_37 ;
int V_38 , V_39 , V_40 ;
V_18 = F_57 ( F_17 ( V_19 ) , F_10 ( V_19 ) ) ;
F_58 ( V_15 ) ;
if ( V_18 ) {
F_58 ( V_14 ) ;
if ( F_21 ( F_59 ( V_18 ) ) )
return V_18 ;
V_40 = F_60 ( V_18 ) ;
if ( V_35 ) {
V_37 = F_61 ( V_35 ) ;
V_38 = F_62 ( V_37 ) ;
V_39 = F_63 ( V_37 ) ;
if ( V_40 )
V_39 = F_64 ( int , V_39 + 1 , V_41 ) ;
F_65 ( & V_35 -> V_42 ,
F_66 ( V_36 , V_38 , V_39 ) ) ;
}
if ( V_40 ) {
F_67 ( V_43 ) ;
if ( ! V_35 )
F_68 ( & V_44 ) ;
}
}
return V_18 ;
}
struct V_18 * F_69 ( T_1 V_19 , T_3 V_26 ,
struct V_34 * V_35 , unsigned long V_36 ,
bool * V_45 )
{
struct V_18 * V_46 , * V_47 = NULL ;
struct V_5 * V_48 = F_17 ( V_19 ) ;
int V_27 ;
* V_45 = false ;
do {
V_46 = F_57 ( V_48 , F_10 ( V_19 ) ) ;
if ( V_46 )
break;
if ( ! F_70 ( V_19 ) && V_49 )
break;
if ( ! V_47 ) {
V_47 = F_71 ( V_26 , V_35 , V_36 ) ;
if ( ! V_47 )
break;
}
V_27 = F_72 ( V_26 & V_50 ) ;
if ( V_27 )
break;
V_27 = F_73 ( V_19 ) ;
if ( V_27 == - V_25 ) {
F_34 () ;
F_74 () ;
continue;
}
if ( V_27 ) {
F_34 () ;
break;
}
F_75 ( V_47 ) ;
F_76 ( V_47 ) ;
V_27 = F_8 ( V_47 , V_19 ) ;
if ( F_22 ( ! V_27 ) ) {
F_34 () ;
F_77 ( V_47 ) ;
* V_45 = true ;
return V_47 ;
}
F_34 () ;
F_78 ( V_47 ) ;
F_43 ( V_47 , V_19 ) ;
} while ( V_27 != - V_51 );
if ( V_47 )
F_52 ( V_47 ) ;
return V_46 ;
}
struct V_18 * F_79 ( T_1 V_19 , T_3 V_26 ,
struct V_34 * V_35 , unsigned long V_36 , bool V_52 )
{
bool V_53 ;
struct V_18 * V_54 = F_69 ( V_19 , V_26 ,
V_35 , V_36 , & V_53 ) ;
if ( V_53 )
F_80 ( V_54 , V_52 ) ;
return V_54 ;
}
static unsigned int F_81 ( unsigned long V_55 ,
unsigned long V_56 ,
int V_39 ,
int V_57 ,
int V_58 )
{
unsigned int V_32 , V_59 ;
V_32 = V_39 + 2 ;
if ( V_32 == 2 ) {
if ( V_56 != V_55 + 1 && V_56 != V_55 - 1 )
V_32 = 1 ;
} else {
unsigned int V_60 = 4 ;
while ( V_60 < V_32 )
V_60 <<= 1 ;
V_32 = V_60 ;
}
if ( V_32 > V_57 )
V_32 = V_57 ;
V_59 = V_58 / 2 ;
if ( V_32 < V_59 )
V_32 = V_59 ;
return V_32 ;
}
static unsigned long F_82 ( unsigned long V_56 )
{
static unsigned long V_55 ;
unsigned int V_39 , V_32 , V_57 ;
static T_4 V_61 ;
V_57 = 1 << F_83 ( V_62 ) ;
if ( V_57 <= 1 )
return 1 ;
V_39 = F_84 ( & V_44 , 0 ) ;
V_32 = F_81 ( V_55 , V_56 , V_39 , V_57 ,
F_85 ( & V_61 ) ) ;
if ( ! V_39 )
V_55 = V_56 ;
F_86 ( & V_61 , V_32 ) ;
return V_32 ;
}
struct V_18 * F_87 ( T_1 V_19 , T_3 V_26 ,
struct V_34 * V_35 , unsigned long V_36 )
{
struct V_18 * V_18 ;
unsigned long V_63 = F_10 ( V_19 ) ;
unsigned long V_56 = V_63 ;
unsigned long V_64 , V_65 ;
unsigned long V_66 ;
struct V_67 V_68 ;
bool V_52 = true , V_69 ;
V_66 = F_82 ( V_56 ) - 1 ;
if ( ! V_66 )
goto V_70;
V_52 = false ;
V_64 = V_56 & ~ V_66 ;
V_65 = V_56 | V_66 ;
if ( ! V_64 )
V_64 ++ ;
F_88 ( & V_68 ) ;
for ( V_56 = V_64 ; V_56 <= V_65 ; V_56 ++ ) {
V_18 = F_69 (
F_89 ( F_90 ( V_19 ) , V_56 ) ,
V_26 , V_35 , V_36 , & V_69 ) ;
if ( ! V_18 )
continue;
if ( V_69 ) {
F_80 ( V_18 , false ) ;
if ( V_56 != V_63 &&
F_22 ( ! F_59 ( V_18 ) ) ) {
F_91 ( V_18 ) ;
F_67 ( V_71 ) ;
}
}
F_52 ( V_18 ) ;
}
F_92 ( & V_68 ) ;
F_54 () ;
V_70:
return F_79 ( V_19 , V_26 , V_35 , V_36 , V_52 ) ;
}
int F_93 ( unsigned int type , unsigned long V_72 )
{
struct V_5 * V_6 , * V_73 ;
unsigned int V_1 , V_3 ;
V_3 = F_94 ( V_72 , V_74 ) ;
V_6 = F_95 ( sizeof( struct V_5 ) * V_3 , V_50 ) ;
if ( ! V_6 )
return - V_51 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ ) {
V_73 = V_6 + V_1 ;
F_96 ( & V_73 -> V_23 , V_75 | V_31 ) ;
F_86 ( & V_73 -> V_76 , 0 ) ;
V_73 -> V_77 = & V_78 ;
F_97 ( V_73 ) ;
F_98 ( & V_73 -> V_21 ) ;
}
V_8 [ type ] = V_3 ;
F_99 ( V_9 [ type ] , V_6 ) ;
return 0 ;
}
void F_100 ( unsigned int type )
{
struct V_5 * V_6 ;
V_6 = V_9 [ type ] ;
V_8 [ type ] = 0 ;
F_99 ( V_9 [ type ] , NULL ) ;
F_101 () ;
F_102 ( V_6 ) ;
}
static inline void F_103 ( struct V_34 * V_35 ,
unsigned long V_79 ,
unsigned long V_80 ,
unsigned long V_81 ,
unsigned long * V_82 ,
unsigned long * V_83 )
{
* V_82 = F_104 ( V_80 , F_105 ( V_35 -> V_84 ) ,
F_105 ( V_79 & V_85 ) ) ;
* V_83 = F_106 ( V_81 , F_105 ( V_35 -> V_86 ) ,
F_105 ( ( V_79 & V_85 ) + V_87 ) ) ;
}
struct V_18 * F_107 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_34 * V_35 = V_89 -> V_35 ;
unsigned long V_92 ;
struct V_18 * V_18 ;
T_1 V_19 ;
unsigned long V_79 , V_93 , V_94 ;
unsigned long V_82 , V_83 ;
T_5 * V_95 ;
unsigned int V_96 , V_39 , V_58 , V_38 , V_97 ;
#ifndef F_108
T_5 * V_98 ;
#endif
V_96 = 1 << F_64 (unsigned int, READ_ONCE(page_cluster),
SWAP_RA_ORDER_CEILING) ;
if ( V_96 == 1 ) {
V_91 -> V_38 = 1 ;
return NULL ;
}
V_79 = V_89 -> V_99 ;
V_19 = F_109 ( V_89 -> V_100 ) ;
if ( ( F_21 ( F_110 ( V_19 ) ) ) )
return NULL ;
V_18 = F_56 ( V_19 , V_35 , V_79 ) ;
if ( V_18 )
return V_18 ;
V_94 = F_105 ( V_79 ) ;
V_92 = F_61 ( V_35 ) ;
V_93 = F_105 ( F_111 ( V_92 ) ) ;
V_58 = F_62 ( V_92 ) ;
V_39 = F_63 ( V_92 ) ;
V_91 -> V_38 = V_38 = F_81 ( V_93 , V_94 , V_39 ,
V_96 , V_58 ) ;
F_65 ( & V_35 -> V_42 ,
F_66 ( V_79 , V_38 , 0 ) ) ;
if ( V_38 == 1 )
return NULL ;
if ( V_94 == V_93 + 1 )
F_103 ( V_35 , V_79 , V_94 , V_94 + V_38 , & V_82 , & V_83 ) ;
else if ( V_93 == V_94 + 1 )
F_103 ( V_35 , V_79 , V_94 - V_38 + 1 , V_94 + 1 ,
& V_82 , & V_83 ) ;
else {
V_97 = ( V_38 - 1 ) / 2 ;
F_103 ( V_35 , V_79 , V_94 - V_97 , V_94 + V_38 - V_97 ,
& V_82 , & V_83 ) ;
}
V_91 -> V_101 = V_83 - V_82 ;
V_91 -> V_56 = V_94 - V_82 ;
V_95 = V_89 -> V_95 - V_91 -> V_56 ;
#ifdef F_108
V_91 -> V_102 = V_95 ;
#else
V_98 = V_91 -> V_102 ;
for ( V_93 = V_82 ; V_93 != V_83 ; V_93 ++ )
* V_98 ++ = * V_95 ++ ;
#endif
return NULL ;
}
struct V_18 * F_112 ( T_1 V_103 , T_3 V_26 ,
struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_67 V_68 ;
struct V_34 * V_35 = V_89 -> V_35 ;
struct V_18 * V_18 ;
T_5 * V_95 , V_104 ;
T_1 V_19 ;
unsigned int V_1 ;
bool V_69 ;
if ( V_91 -> V_38 == 1 )
goto V_70;
F_88 ( & V_68 ) ;
for ( V_1 = 0 , V_95 = V_91 -> V_102 ; V_1 < V_91 -> V_101 ;
V_1 ++ , V_95 ++ ) {
V_104 = * V_95 ;
if ( F_113 ( V_104 ) )
continue;
if ( F_114 ( V_104 ) )
continue;
V_19 = F_109 ( V_104 ) ;
if ( F_21 ( F_110 ( V_19 ) ) )
continue;
V_18 = F_69 ( V_19 , V_26 , V_35 ,
V_89 -> V_99 , & V_69 ) ;
if ( ! V_18 )
continue;
if ( V_69 ) {
F_80 ( V_18 , false ) ;
if ( V_1 != V_91 -> V_56 &&
F_22 ( ! F_59 ( V_18 ) ) ) {
F_91 ( V_18 ) ;
F_67 ( V_71 ) ;
}
}
F_52 ( V_18 ) ;
}
F_92 ( & V_68 ) ;
F_54 () ;
V_70:
return F_79 ( V_103 , V_26 , V_35 , V_89 -> V_99 ,
V_91 -> V_38 == 1 ) ;
}
static T_6 F_115 ( struct V_105 * V_106 ,
struct V_107 * V_108 , char * V_109 )
{
return sprintf ( V_109 , L_5 , V_110 ? L_6 : L_7 ) ;
}
static T_6 F_116 ( struct V_105 * V_106 ,
struct V_107 * V_108 ,
const char * V_109 , T_7 V_111 )
{
if ( ! strncmp ( V_109 , L_6 , 4 ) || ! strncmp ( V_109 , L_8 , 1 ) )
V_110 = true ;
else if ( ! strncmp ( V_109 , L_7 , 5 ) || ! strncmp ( V_109 , L_9 , 1 ) )
V_110 = false ;
else
return - V_112 ;
return V_111 ;
}
static int T_8 F_117 ( void )
{
int V_27 ;
struct V_105 * V_113 ;
V_113 = F_118 ( L_10 , V_114 ) ;
if ( ! V_113 ) {
F_119 ( L_11 ) ;
return - V_51 ;
}
V_27 = F_120 ( V_113 , & V_115 ) ;
if ( V_27 ) {
F_119 ( L_12 ) ;
goto V_116;
}
return 0 ;
V_116:
F_121 ( V_113 ) ;
return V_27 ;
}
