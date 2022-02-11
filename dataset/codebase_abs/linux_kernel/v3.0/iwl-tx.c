void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
int V_6 = V_4 -> V_7 . V_8 ;
if ( V_4 -> V_9 == 0 )
return;
if ( V_2 -> V_10 -> V_11 -> V_12 ) {
F_2 ( V_2 , V_13 ,
V_4 -> V_7 . V_14 | ( V_6 << 8 ) ) ;
} else {
if ( F_3 ( V_15 , & V_2 -> V_16 ) ) {
V_5 = F_4 ( V_2 , V_17 ) ;
if ( V_5 & V_18 ) {
F_5 ( V_2 ,
L_1
L_2 , V_6 , V_5 ) ;
F_6 ( V_2 , V_19 ,
V_20 ) ;
return;
}
F_7 ( V_2 , V_13 ,
V_4 -> V_7 . V_14 | ( V_6 << 8 ) ) ;
} else
F_2 ( V_2 , V_13 ,
V_4 -> V_7 . V_14 | ( V_6 << 8 ) ) ;
}
V_4 -> V_9 = 0 ;
}
static inline T_2 F_8 ( struct V_21 * V_22 , T_3 V_23 )
{
struct V_24 * V_25 = & V_22 -> V_26 [ V_23 ] ;
T_2 V_27 = F_9 ( & V_25 -> V_28 ) ;
if ( sizeof( T_2 ) > sizeof( T_1 ) )
V_27 |=
( ( T_2 ) ( F_10 ( V_25 -> V_29 ) & 0xF ) << 16 ) << 16 ;
return V_27 ;
}
static inline T_4 F_11 ( struct V_21 * V_22 , T_3 V_23 )
{
struct V_24 * V_25 = & V_22 -> V_26 [ V_23 ] ;
return F_10 ( V_25 -> V_29 ) >> 4 ;
}
static inline void F_12 ( struct V_21 * V_22 , T_3 V_23 ,
T_2 V_27 , T_4 V_30 )
{
struct V_24 * V_25 = & V_22 -> V_26 [ V_23 ] ;
T_4 V_29 = V_30 << 4 ;
F_13 ( V_27 , & V_25 -> V_28 ) ;
if ( sizeof( T_2 ) > sizeof( T_1 ) )
V_29 |= ( ( V_27 >> 16 ) >> 16 ) & 0xF ;
V_25 -> V_29 = F_14 ( V_29 ) ;
V_22 -> V_31 = V_23 + 1 ;
}
static inline T_3 F_15 ( struct V_21 * V_22 )
{
return V_22 -> V_31 & 0x1f ;
}
static void F_16 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_21 * V_22 , int V_34 )
{
struct V_35 * V_36 = V_2 -> V_35 ;
int V_37 ;
int V_31 ;
V_31 = F_15 ( V_22 ) ;
if ( V_31 >= V_38 ) {
F_17 ( V_2 , L_3 , V_31 ) ;
return;
}
if ( V_31 )
F_18 ( V_36 ,
F_19 ( V_33 , V_39 ) ,
F_20 ( V_33 , V_30 ) ,
V_40 ) ;
for ( V_37 = 1 ; V_37 < V_31 ; V_37 ++ )
F_18 ( V_36 , F_8 ( V_22 , V_37 ) ,
F_11 ( V_22 , V_37 ) , V_34 ) ;
}
void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_21 * V_41 = V_4 -> V_42 ;
int V_43 = V_4 -> V_7 . V_44 ;
F_16 ( V_2 , & V_4 -> V_33 [ V_43 ] , & V_41 [ V_43 ] ,
V_45 ) ;
if ( V_4 -> V_46 ) {
struct V_47 * V_48 ;
V_48 = V_4 -> V_46 [ V_4 -> V_7 . V_44 ] . V_48 ;
if ( V_48 ) {
F_22 ( V_48 ) ;
V_4 -> V_46 [ V_4 -> V_7 . V_44 ] . V_48 = NULL ;
}
}
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_27 , T_4 V_30 ,
T_3 V_49 )
{
struct V_50 * V_7 ;
struct V_21 * V_22 , * V_41 ;
T_1 V_31 ;
V_7 = & V_4 -> V_7 ;
V_41 = V_4 -> V_42 ;
V_22 = & V_41 [ V_7 -> V_14 ] ;
if ( V_49 )
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_31 = F_15 ( V_22 ) ;
if ( V_31 >= V_38 ) {
F_17 ( V_2 , L_4 ,
V_38 ) ;
return - V_51 ;
}
if ( F_24 ( V_27 & ~ F_25 ( 36 ) ) )
return - V_51 ;
if ( F_26 ( V_27 & ~ V_52 ) )
F_17 ( V_2 , L_5 ,
( unsigned long long ) V_27 ) ;
F_12 ( V_22 , V_31 , V_27 , V_30 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 = V_4 -> V_7 . V_8 ;
F_7 ( V_2 , F_28 ( V_6 ) ,
V_4 -> V_7 . V_53 >> 8 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_6 ] ;
struct V_50 * V_7 = & V_4 -> V_7 ;
if ( V_7 -> V_54 == 0 )
return;
while ( V_7 -> V_14 != V_7 -> V_44 ) {
F_21 ( V_2 , V_4 ) ;
V_7 -> V_44 = F_30 ( V_7 -> V_44 , V_7 -> V_54 ) ;
}
}
void F_31 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_6 ] ;
struct V_55 * V_36 = & V_2 -> V_35 -> V_36 ;
int V_37 ;
F_29 ( V_2 , V_6 ) ;
for ( V_37 = 0 ; V_37 < V_56 ; V_37 ++ )
F_32 ( V_4 -> V_57 [ V_37 ] ) ;
if ( V_4 -> V_7 . V_54 )
F_33 ( V_36 , V_2 -> V_58 . V_59 *
V_4 -> V_7 . V_54 , V_4 -> V_42 , V_4 -> V_7 . V_53 ) ;
F_32 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
F_32 ( V_4 -> V_57 ) ;
F_32 ( V_4 -> V_33 ) ;
V_4 -> V_57 = NULL ;
V_4 -> V_33 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_2 -> V_60 ] ;
struct V_50 * V_7 = & V_4 -> V_7 ;
int V_37 ;
if ( V_7 -> V_54 == 0 )
return;
while ( V_7 -> V_44 != V_7 -> V_14 ) {
V_37 = F_35 ( V_7 , V_7 -> V_44 ) ;
if ( V_4 -> V_33 [ V_37 ] . V_61 & V_62 ) {
F_16 ( V_2 , & V_4 -> V_33 [ V_37 ] , & V_4 -> V_42 [ V_37 ] ,
V_40 ) ;
V_4 -> V_33 [ V_37 ] . V_61 = 0 ;
}
V_7 -> V_44 = F_30 ( V_7 -> V_44 , V_7 -> V_54 ) ;
}
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_2 -> V_60 ] ;
struct V_55 * V_36 = & V_2 -> V_35 -> V_36 ;
int V_37 ;
F_34 ( V_2 ) ;
for ( V_37 = 0 ; V_37 < V_63 ; V_37 ++ )
F_32 ( V_4 -> V_57 [ V_37 ] ) ;
if ( V_4 -> V_7 . V_54 )
F_33 ( V_36 , V_2 -> V_58 . V_59 * V_4 -> V_7 . V_54 ,
V_4 -> V_42 , V_4 -> V_7 . V_53 ) ;
F_32 ( V_4 -> V_57 ) ;
F_32 ( V_4 -> V_33 ) ;
V_4 -> V_57 = NULL ;
V_4 -> V_33 = NULL ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
int F_37 ( const struct V_50 * V_7 )
{
int V_64 = V_7 -> V_44 - V_7 -> V_14 ;
if ( V_7 -> V_44 > V_7 -> V_14 )
V_64 -= V_7 -> V_54 ;
if ( V_64 <= 0 )
V_64 += V_7 -> V_65 ;
V_64 -= 2 ;
if ( V_64 < 0 )
V_64 = 0 ;
return V_64 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_50 * V_7 ,
int V_66 , int V_67 , T_1 V_8 )
{
V_7 -> V_54 = V_66 ;
V_7 -> V_65 = V_67 ;
V_7 -> V_8 = V_8 ;
if ( F_24 ( ! F_39 ( V_66 ) ) )
return - V_51 ;
if ( F_24 ( ! F_39 ( V_67 ) ) )
return - V_51 ;
V_7 -> V_68 = V_7 -> V_65 / 4 ;
if ( V_7 -> V_68 < 4 )
V_7 -> V_68 = 4 ;
V_7 -> V_69 = V_7 -> V_65 / 8 ;
if ( V_7 -> V_69 < 2 )
V_7 -> V_69 = 2 ;
V_7 -> V_14 = V_7 -> V_44 = 0 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_8 )
{
struct V_55 * V_36 = & V_2 -> V_35 -> V_36 ;
T_5 V_70 = V_2 -> V_58 . V_59 * V_71 ;
if ( V_8 != V_2 -> V_60 ) {
V_4 -> V_46 = F_41 ( sizeof( V_4 -> V_46 [ 0 ] ) *
V_71 , V_72 ) ;
if ( ! V_4 -> V_46 ) {
F_17 ( V_2 , L_6
L_7 ) ;
goto error;
}
} else {
V_4 -> V_46 = NULL ;
}
V_4 -> V_42 = F_42 ( V_36 , V_70 , & V_4 -> V_7 . V_53 ,
V_72 ) ;
if ( ! V_4 -> V_42 ) {
F_17 ( V_2 , L_8 , V_70 ) ;
goto error;
}
V_4 -> V_7 . V_8 = V_8 ;
return 0 ;
error:
F_32 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
return - V_73 ;
}
int F_43 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_67 , T_1 V_6 )
{
int V_37 , V_30 ;
int V_74 ;
V_4 -> V_33 = F_41 ( sizeof( struct V_32 ) * V_67 ,
V_72 ) ;
V_4 -> V_57 = F_41 ( sizeof( struct V_75 * ) * V_67 ,
V_72 ) ;
if ( ! V_4 -> V_33 || ! V_4 -> V_57 )
goto V_76;
V_30 = sizeof( struct V_75 ) ;
for ( V_37 = 0 ; V_37 < V_67 ; V_37 ++ ) {
V_4 -> V_57 [ V_37 ] = F_44 ( V_30 , V_72 ) ;
if ( ! V_4 -> V_57 [ V_37 ] )
goto V_77;
}
V_74 = F_40 ( V_2 , V_4 , V_6 ) ;
if ( V_74 )
goto V_77;
V_4 -> V_9 = 0 ;
if ( V_6 < 4 )
F_45 ( V_4 , V_6 , V_6 ) ;
F_46 ( V_71 & ( V_71 - 1 ) ) ;
V_74 = F_38 ( V_2 , & V_4 -> V_7 , V_71 , V_67 , V_6 ) ;
if ( V_74 )
return V_74 ;
F_27 ( V_2 , V_4 ) ;
return 0 ;
V_77:
for ( V_37 = 0 ; V_37 < V_67 ; V_37 ++ )
F_32 ( V_4 -> V_57 [ V_37 ] ) ;
V_76:
F_32 ( V_4 -> V_33 ) ;
F_32 ( V_4 -> V_57 ) ;
return - V_73 ;
}
void F_47 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_67 , T_1 V_6 )
{
memset ( V_4 -> V_33 , 0 , sizeof( struct V_32 ) * V_67 ) ;
V_4 -> V_9 = 0 ;
F_38 ( V_2 , & V_4 -> V_7 , V_71 , V_67 , V_6 ) ;
F_27 ( V_2 , V_4 ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_78 * V_57 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_2 -> V_60 ] ;
struct V_50 * V_7 = & V_4 -> V_7 ;
struct V_75 * V_79 ;
struct V_32 * V_80 ;
T_2 V_81 ;
unsigned long V_61 ;
T_1 V_23 ;
T_4 V_82 , V_83 ;
bool V_84 = false ;
bool V_85 = false ;
int V_37 ;
T_3 * V_86 ;
#ifdef F_49
const void * V_87 [ V_88 + 1 ] = {} ;
int V_89 [ V_88 + 1 ] = {} ;
int V_90 ;
#endif
if ( F_3 ( V_91 , & V_2 -> V_16 ) ) {
F_50 ( V_2 , L_9 ) ;
return - V_92 ;
}
V_82 = sizeof( V_79 -> V_93 ) ;
V_83 = sizeof( V_79 -> V_93 ) ;
F_46 ( V_88 > V_38 - 1 ) ;
for ( V_37 = 0 ; V_37 < V_88 ; V_37 ++ ) {
if ( ! V_57 -> V_30 [ V_37 ] )
continue;
if ( V_57 -> V_94 [ V_37 ] & V_95 ) {
V_85 = true ;
} else {
if ( F_24 ( V_85 ) )
return - V_51 ;
V_82 += V_57 -> V_30 [ V_37 ] ;
}
V_83 += V_57 -> V_30 [ V_37 ] ;
}
if ( F_24 ( V_82 > V_96 ) )
return - V_51 ;
if ( F_51 ( V_2 ) || F_52 ( V_2 ) ) {
F_50 ( V_2 , L_10 ,
F_51 ( V_2 ) ? L_11 : L_12 ) ;
return - V_92 ;
}
F_53 ( & V_2 -> V_97 , V_61 ) ;
if ( F_37 ( V_7 ) < ( ( V_57 -> V_61 & V_98 ) ? 2 : 1 ) ) {
F_54 ( & V_2 -> V_97 , V_61 ) ;
F_17 ( V_2 , L_13 ) ;
V_84 = F_55 ( V_2 ) ;
if ( ! V_84 ) {
F_17 ( V_2 , L_14 ) ;
F_56 ( V_2 , false ) ;
}
return - V_99 ;
}
V_23 = F_35 ( V_7 , V_7 -> V_14 ) ;
V_79 = V_4 -> V_57 [ V_23 ] ;
V_80 = & V_4 -> V_33 [ V_23 ] ;
if ( F_24 ( V_80 -> V_61 & V_62 ) ) {
F_54 ( & V_2 -> V_97 , V_61 ) ;
return - V_99 ;
}
memset ( V_80 , 0 , sizeof( * V_80 ) ) ;
if ( V_57 -> V_61 & V_100 )
V_80 -> V_101 = V_57 ;
if ( V_57 -> V_61 & V_98 )
V_80 -> V_102 = V_57 -> V_102 ;
V_79 -> V_93 . V_57 = V_57 -> V_8 ;
V_79 -> V_93 . V_61 = 0 ;
V_79 -> V_93 . V_103 = F_14 ( F_57 ( V_2 -> V_60 ) |
F_58 ( V_7 -> V_14 ) ) ;
V_86 = & V_79 -> V_57 . V_104 [ 0 ] ;
for ( V_37 = 0 ; V_37 < V_88 ; V_37 ++ ) {
if ( ! V_57 -> V_30 [ V_37 ] )
continue;
if ( V_57 -> V_94 [ V_37 ] & V_95 )
break;
memcpy ( V_86 , V_57 -> V_105 [ V_37 ] , V_57 -> V_30 [ V_37 ] ) ;
V_86 += V_57 -> V_30 [ V_37 ] ;
}
F_59 ( V_2 , L_15
L_16 ,
F_60 ( V_79 -> V_93 . V_57 ) ,
V_79 -> V_93 . V_57 ,
F_10 ( V_79 -> V_93 . V_103 ) , V_83 ,
V_7 -> V_14 , V_23 , V_2 -> V_60 ) ;
V_81 = F_61 ( V_2 -> V_35 , & V_79 -> V_93 ,
V_82 , V_40 ) ;
if ( F_26 ( F_62 ( V_2 -> V_35 , V_81 ) ) ) {
V_23 = - V_73 ;
goto V_106;
}
F_63 ( V_80 , V_39 , V_81 ) ;
F_64 ( V_80 , V_30 , V_82 ) ;
F_23 ( V_2 , V_4 , V_81 , V_82 , 1 ) ;
#ifdef F_49
V_87 [ 0 ] = & V_79 -> V_93 ;
V_89 [ 0 ] = V_82 ;
V_90 = 1 ;
#endif
for ( V_37 = 0 ; V_37 < V_88 ; V_37 ++ ) {
if ( ! V_57 -> V_30 [ V_37 ] )
continue;
if ( ! ( V_57 -> V_94 [ V_37 ] & V_95 ) )
continue;
V_81 = F_61 ( V_2 -> V_35 , ( void * ) V_57 -> V_105 [ V_37 ] ,
V_57 -> V_30 [ V_37 ] , V_40 ) ;
if ( F_62 ( V_2 -> V_35 , V_81 ) ) {
F_16 ( V_2 , V_80 ,
& V_4 -> V_42 [ V_7 -> V_14 ] ,
V_40 ) ;
V_23 = - V_73 ;
goto V_106;
}
F_23 ( V_2 , V_4 , V_81 ,
V_57 -> V_30 [ V_37 ] , 0 ) ;
#ifdef F_49
V_87 [ V_90 ] = V_57 -> V_105 [ V_37 ] ;
V_89 [ V_90 ] = V_57 -> V_30 [ V_37 ] ;
V_90 ++ ;
#endif
}
V_80 -> V_61 = V_57 -> V_61 | V_62 ;
V_4 -> V_9 = 1 ;
F_46 ( V_88 + 1 != 3 ) ;
#ifdef F_49
F_65 ( V_2 , V_57 -> V_61 ,
V_87 [ 0 ] , V_89 [ 0 ] ,
V_87 [ 1 ] , V_89 [ 1 ] ,
V_87 [ 2 ] , V_89 [ 2 ] ) ;
#endif
V_7 -> V_14 = F_30 ( V_7 -> V_14 , V_7 -> V_54 ) ;
F_1 ( V_2 , V_4 ) ;
V_106:
F_54 ( & V_2 -> V_97 , V_61 ) ;
return V_23 ;
}
static void F_66 ( struct V_1 * V_2 , int V_6 , int V_23 )
{
struct V_3 * V_4 = & V_2 -> V_4 [ V_6 ] ;
struct V_50 * V_7 = & V_4 -> V_7 ;
int V_107 = 0 ;
if ( ( V_23 >= V_7 -> V_54 ) || ( F_67 ( V_7 , V_23 ) == 0 ) ) {
F_17 ( V_2 , L_17
L_18 , V_6 ,
V_23 , V_7 -> V_54 , V_7 -> V_14 , V_7 -> V_44 ) ;
return;
}
for ( V_23 = F_30 ( V_23 , V_7 -> V_54 ) ; V_7 -> V_44 != V_23 ;
V_7 -> V_44 = F_30 ( V_7 -> V_44 , V_7 -> V_54 ) ) {
if ( V_107 ++ > 0 ) {
F_17 ( V_2 , L_19 , V_23 ,
V_7 -> V_14 , V_7 -> V_44 ) ;
F_56 ( V_2 , false ) ;
}
}
}
void F_68 ( struct V_1 * V_2 , struct V_108 * V_109 )
{
struct V_110 * V_111 = F_69 ( V_109 ) ;
T_4 V_103 = F_10 ( V_111 -> V_93 . V_103 ) ;
int V_6 = F_70 ( V_103 ) ;
int V_43 = F_71 ( V_103 ) ;
int V_112 ;
struct V_75 * V_57 ;
struct V_32 * V_33 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_2 -> V_60 ] ;
unsigned long V_61 ;
if ( F_72 ( V_6 != V_2 -> V_60 ,
L_20 ,
V_6 , V_2 -> V_60 , V_103 ,
V_2 -> V_4 [ V_2 -> V_60 ] . V_7 . V_44 ,
V_2 -> V_4 [ V_2 -> V_60 ] . V_7 . V_14 ) ) {
F_73 ( V_2 , V_111 , 32 ) ;
return;
}
V_112 = F_35 ( & V_4 -> V_7 , V_43 ) ;
V_57 = V_4 -> V_57 [ V_112 ] ;
V_33 = & V_4 -> V_33 [ V_112 ] ;
F_16 ( V_2 , V_33 , & V_4 -> V_42 [ V_43 ] , V_40 ) ;
if ( V_33 -> V_61 & V_100 ) {
V_33 -> V_101 -> V_113 = ( unsigned long ) F_69 ( V_109 ) ;
V_109 -> V_114 = NULL ;
} else if ( V_33 -> V_102 )
V_33 -> V_102 ( V_2 , V_57 , V_111 ) ;
F_53 ( & V_2 -> V_97 , V_61 ) ;
F_66 ( V_2 , V_6 , V_43 ) ;
if ( ! ( V_33 -> V_61 & V_98 ) ) {
F_74 ( V_115 , & V_2 -> V_16 ) ;
F_5 ( V_2 , L_21 ,
F_60 ( V_57 -> V_93 . V_57 ) ) ;
F_75 ( & V_2 -> V_116 ) ;
}
V_33 -> V_61 = 0 ;
F_54 ( & V_2 -> V_97 , V_61 ) ;
}
