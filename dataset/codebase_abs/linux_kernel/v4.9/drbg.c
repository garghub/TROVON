static inline unsigned short F_1 ( T_1 V_1 )
{
switch ( V_1 & V_2 ) {
case V_3 :
return 16 ;
case V_4 :
return 24 ;
case V_5 :
return 32 ;
default:
return 32 ;
}
}
static inline void F_2 ( T_2 V_6 , unsigned char * V_7 )
{
struct V_8 {
T_3 V_9 ;
};
struct V_8 * V_10 = (struct V_8 * ) V_7 ;
V_10 -> V_9 = F_3 ( V_6 ) ;
}
static int F_4 ( struct V_11 * V_12 ,
unsigned char * V_13 , const unsigned char * V_14 ,
struct V_15 * V_16 )
{
int V_17 = 0 ;
struct V_18 * V_19 = NULL ;
struct V_18 V_20 ;
short V_21 = 0 ;
F_5 ( & V_20 , V_13 , F_6 ( V_12 ) ) ;
F_7 ( V_12 , V_14 ) ;
F_8 (curr, in, list) {
const unsigned char * V_22 = V_19 -> V_7 ;
T_4 V_23 = V_19 -> V_23 ;
while ( V_23 ) {
if ( F_6 ( V_12 ) == V_21 ) {
V_21 = 0 ;
V_17 = F_9 ( V_12 , V_13 , & V_20 ) ;
if ( V_17 )
return V_17 ;
}
V_13 [ V_21 ] ^= * V_22 ;
V_22 ++ ;
V_21 ++ ;
V_23 -- ;
}
}
if ( V_21 )
V_17 = F_9 ( V_12 , V_13 , & V_20 ) ;
return V_17 ;
}
static int F_10 ( struct V_11 * V_12 ,
unsigned char * V_24 , T_4 V_25 ,
struct V_15 * V_26 )
{
int V_17 = - V_27 ;
unsigned char V_28 [ 8 ] ;
struct V_18 V_29 , V_30 , V_31 , V_32 ;
F_11 ( V_33 ) ;
unsigned char * V_34 = V_24 + F_12 ( V_12 ) ;
unsigned char * V_35 = V_34 + F_6 ( V_12 ) ;
unsigned char * V_36 = V_35 + F_6 ( V_12 ) ;
T_4 V_37 = 0 ;
unsigned int V_38 = 0 ;
unsigned int V_39 = 0 ;
const unsigned char * V_40 = ( unsigned char * )
L_1
L_2
L_3
L_4 ;
unsigned char * V_41 ;
T_4 V_42 = 0 ;
T_4 V_43 = 0 ;
struct V_18 * V_44 = NULL ;
memset ( V_34 , 0 , F_6 ( V_12 ) ) ;
memset ( V_35 , 0 , F_6 ( V_12 ) ) ;
if ( ( 512 / 8 ) < V_25 )
return - V_45 ;
F_8 (seed, seedlist, list)
V_43 += V_44 -> V_23 ;
F_2 ( V_43 , & V_28 [ 0 ] ) ;
F_2 ( V_25 , & V_28 [ 4 ] ) ;
V_37 = ( V_43 + sizeof( V_28 ) + 1 ) % ( F_6 ( V_12 ) ) ;
if ( V_37 )
V_37 = F_6 ( V_12 ) - V_37 ;
V_37 ++ ;
V_34 [ 0 ] = 0x80 ;
F_5 ( & V_29 , V_35 , F_6 ( V_12 ) ) ;
F_13 ( & V_29 . V_46 , & V_33 ) ;
F_5 ( & V_30 , V_28 , sizeof( V_28 ) ) ;
F_13 ( & V_30 . V_46 , & V_33 ) ;
F_14 ( V_26 , & V_33 ) ;
F_5 ( & V_31 , V_34 , V_37 ) ;
F_13 ( & V_31 . V_46 , & V_33 ) ;
while ( V_38 < ( F_15 ( V_12 ) + ( F_6 ( V_12 ) ) ) ) {
F_2 ( V_39 , V_35 ) ;
V_17 = F_4 ( V_12 , V_36 + V_38 , V_40 , & V_33 ) ;
if ( V_17 )
goto V_13;
V_39 ++ ;
V_38 += F_6 ( V_12 ) ;
}
V_41 = V_36 + ( F_15 ( V_12 ) ) ;
F_5 ( & V_32 , V_41 , F_6 ( V_12 ) ) ;
F_7 ( V_12 , V_36 ) ;
while ( V_42 < V_25 ) {
short V_47 = 0 ;
V_17 = F_9 ( V_12 , V_41 , & V_32 ) ;
if ( V_17 )
goto V_13;
V_47 = ( F_6 ( V_12 ) <
( V_25 - V_42 ) ) ?
F_6 ( V_12 ) :
( V_25 - V_42 ) ;
memcpy ( V_24 + V_42 , V_41 , V_47 ) ;
V_42 += V_47 ;
}
V_17 = 0 ;
V_13:
memset ( V_35 , 0 , F_6 ( V_12 ) ) ;
memset ( V_36 , 0 , F_12 ( V_12 ) + F_6 ( V_12 ) ) ;
memset ( V_34 , 0 , F_6 ( V_12 ) ) ;
return V_17 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = - V_27 ;
unsigned char * V_36 = V_12 -> V_49 ;
unsigned char * V_24 = V_12 -> V_49 + F_12 ( V_12 ) +
F_6 ( V_12 ) ;
if ( 3 > V_48 )
memset ( V_24 , 0 , F_12 ( V_12 ) ) ;
if ( ! V_48 ) {
F_17 ( V_12 -> V_50 , F_6 ( V_12 ) ) ;
V_17 = F_18 ( V_12 -> V_51 , V_12 -> V_52 ,
F_15 ( V_12 ) ) ;
if ( V_17 )
goto V_13;
}
if ( V_44 ) {
V_17 = F_10 ( V_12 , V_24 , F_12 ( V_12 ) , V_44 ) ;
if ( V_17 )
goto V_13;
}
V_17 = F_19 ( V_12 , V_24 , F_12 ( V_12 ) ,
V_36 , F_12 ( V_12 ) ) ;
if ( V_17 )
return V_17 ;
V_17 = F_18 ( V_12 -> V_51 , V_36 ,
F_15 ( V_12 ) ) ;
if ( V_17 )
goto V_13;
memcpy ( V_12 -> V_50 , V_36 + F_15 ( V_12 ) , F_6 ( V_12 ) ) ;
F_17 ( V_12 -> V_50 , F_6 ( V_12 ) ) ;
V_17 = 0 ;
V_13:
memset ( V_36 , 0 , F_12 ( V_12 ) + F_6 ( V_12 ) ) ;
if ( 2 != V_48 )
memset ( V_24 , 0 , F_12 ( V_12 ) ) ;
return V_17 ;
}
static int F_20 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_53 ,
struct V_15 * V_54 )
{
int V_17 ;
int V_23 = F_21 ( int , V_53 , V_55 ) ;
if ( V_54 && ! F_22 ( V_54 ) ) {
V_17 = F_16 ( V_12 , V_54 , 2 ) ;
if ( V_17 )
return 0 ;
}
V_17 = F_19 ( V_12 , V_12 -> V_56 , V_57 ,
V_7 , V_23 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_16 ( V_12 , NULL , 3 ) ;
if ( V_17 )
V_23 = V_17 ;
return V_23 ;
}
static int F_23 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = - V_27 ;
int V_39 = 0 ;
struct V_18 V_58 , V_59 , V_60 ;
F_11 ( V_26 ) ;
F_11 ( V_61 ) ;
if ( ! V_48 ) {
memset ( V_12 -> V_50 , 1 , F_12 ( V_12 ) ) ;
F_24 ( V_12 , V_12 -> V_52 ) ;
}
F_5 ( & V_58 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_13 ( & V_58 . V_46 , & V_26 ) ;
F_5 ( & V_59 , NULL , 1 ) ;
F_13 ( & V_59 . V_46 , & V_26 ) ;
if ( V_44 )
F_14 ( V_44 , & V_26 ) ;
F_5 ( & V_60 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_13 ( & V_60 . V_46 , & V_61 ) ;
for ( V_39 = 2 ; 0 < V_39 ; V_39 -- ) {
unsigned char V_62 = V_63 ;
if ( 1 == V_39 )
V_62 = V_64 ;
V_59 . V_7 = & V_62 ;
V_17 = F_25 ( V_12 , V_12 -> V_52 , & V_26 ) ;
if ( V_17 )
return V_17 ;
F_24 ( V_12 , V_12 -> V_52 ) ;
V_17 = F_25 ( V_12 , V_12 -> V_50 , & V_61 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_44 )
return V_17 ;
}
return 0 ;
}
static int F_26 ( struct V_11 * V_12 ,
unsigned char * V_7 ,
unsigned int V_53 ,
struct V_15 * V_54 )
{
int V_23 = 0 ;
int V_17 = 0 ;
struct V_18 V_20 ;
F_11 ( V_65 ) ;
if ( V_54 && ! F_22 ( V_54 ) ) {
V_17 = F_23 ( V_12 , V_54 , 1 ) ;
if ( V_17 )
return V_17 ;
}
F_5 ( & V_20 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_13 ( & V_20 . V_46 , & V_65 ) ;
while ( V_23 < V_53 ) {
unsigned int V_66 = 0 ;
V_17 = F_25 ( V_12 , V_12 -> V_50 , & V_65 ) ;
if ( V_17 )
return V_17 ;
V_66 = ( F_6 ( V_12 ) < ( V_53 - V_23 ) ) ?
F_6 ( V_12 ) : ( V_53 - V_23 ) ;
memcpy ( V_7 + V_23 , V_12 -> V_50 , V_66 ) ;
V_23 += V_66 ;
}
if ( V_54 && ! F_22 ( V_54 ) )
V_17 = F_23 ( V_12 , V_54 , 1 ) ;
else
V_17 = F_23 ( V_12 , NULL , 1 ) ;
if ( V_17 )
return V_17 ;
return V_23 ;
}
static inline void F_27 ( unsigned char * V_67 , T_4 V_68 ,
const unsigned char * V_69 , T_4 V_70 )
{
unsigned char * V_71 ;
const unsigned char * V_72 ;
unsigned int V_73 = 0 ;
T_4 V_23 = V_70 ;
V_71 = V_67 + ( V_68 - 1 ) ;
V_72 = V_69 + ( V_70 - 1 ) ;
while ( V_23 ) {
V_73 += * V_71 + * V_72 ;
* V_71 = V_73 & 0xff ;
V_73 >>= 8 ;
V_23 -- ; V_71 -- ; V_72 -- ;
}
V_23 = V_68 - V_70 ;
while ( V_23 && V_73 > 0 ) {
V_73 = * V_71 + 1 ;
* V_71 = V_73 & 0xff ;
V_73 >>= 8 ;
V_23 -- ; V_71 -- ;
}
}
static int F_28 ( struct V_11 * V_12 ,
unsigned char * V_74 , T_4 V_66 ,
struct V_15 * V_75 )
{
int V_17 = 0 ;
T_4 V_23 = 0 ;
unsigned char V_76 [ 5 ] ;
unsigned char * V_77 = V_12 -> V_49 + F_12 ( V_12 ) ;
struct V_18 V_20 ;
V_76 [ 0 ] = 1 ;
F_2 ( ( V_66 * 8 ) , & V_76 [ 1 ] ) ;
F_5 ( & V_20 , V_76 , 5 ) ;
F_29 ( & V_20 . V_46 , V_75 ) ;
while ( V_23 < V_66 ) {
short V_47 = 0 ;
V_17 = F_25 ( V_12 , V_77 , V_75 ) ;
if ( V_17 )
goto V_13;
V_76 [ 0 ] ++ ;
V_47 = ( F_6 ( V_12 ) < ( V_66 - V_23 ) ) ?
F_6 ( V_12 ) : ( V_66 - V_23 ) ;
memcpy ( V_74 + V_23 , V_77 , V_47 ) ;
V_23 += V_47 ;
}
V_13:
memset ( V_77 , 0 , F_6 ( V_12 ) ) ;
return V_17 ;
}
static int F_30 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = 0 ;
struct V_18 V_78 , V_79 ;
F_11 ( V_65 ) ;
F_11 ( V_80 ) ;
unsigned char * V_50 = V_12 -> V_49 ;
unsigned char V_62 = V_64 ;
if ( ! V_44 )
return - V_45 ;
if ( V_48 ) {
memcpy ( V_50 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_5 ( & V_78 , & V_62 , 1 ) ;
F_13 ( & V_78 . V_46 , & V_65 ) ;
F_5 ( & V_79 , V_50 , F_12 ( V_12 ) ) ;
F_13 ( & V_79 . V_46 , & V_65 ) ;
}
F_14 ( V_44 , & V_65 ) ;
V_17 = F_28 ( V_12 , V_12 -> V_50 , F_12 ( V_12 ) , & V_65 ) ;
if ( V_17 )
goto V_13;
V_62 = V_63 ;
F_5 ( & V_78 , & V_62 , 1 ) ;
F_13 ( & V_78 . V_46 , & V_80 ) ;
F_5 ( & V_79 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_13 ( & V_79 . V_46 , & V_80 ) ;
V_17 = F_28 ( V_12 , V_12 -> V_52 , F_12 ( V_12 ) , & V_80 ) ;
V_13:
memset ( V_12 -> V_49 , 0 , F_12 ( V_12 ) ) ;
return V_17 ;
}
static int F_31 ( struct V_11 * V_12 ,
struct V_15 * V_54 )
{
int V_17 = 0 ;
struct V_18 V_78 , V_79 ;
F_11 ( V_65 ) ;
unsigned char V_62 = V_81 ;
if ( ! V_54 || F_22 ( V_54 ) )
return 0 ;
F_5 ( & V_78 , & V_62 , 1 ) ;
F_5 ( & V_79 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_13 ( & V_78 . V_46 , & V_65 ) ;
F_13 ( & V_79 . V_46 , & V_65 ) ;
F_14 ( V_54 , & V_65 ) ;
V_17 = F_25 ( V_12 , V_12 -> V_49 , & V_65 ) ;
if ( V_17 )
goto V_13;
F_27 ( V_12 -> V_50 , F_12 ( V_12 ) ,
V_12 -> V_49 , F_6 ( V_12 ) ) ;
V_13:
memset ( V_12 -> V_49 , 0 , F_6 ( V_12 ) ) ;
return V_17 ;
}
static int F_32 ( struct V_11 * V_12 ,
unsigned char * V_7 ,
unsigned int V_53 )
{
int V_23 = 0 ;
int V_17 = 0 ;
unsigned char * V_82 = V_12 -> V_49 ;
unsigned char * V_67 = V_12 -> V_49 + F_12 ( V_12 ) ;
struct V_18 V_20 ;
F_11 ( V_65 ) ;
memcpy ( V_82 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_5 ( & V_20 , V_82 , F_12 ( V_12 ) ) ;
F_13 ( & V_20 . V_46 , & V_65 ) ;
while ( V_23 < V_53 ) {
unsigned int V_66 = 0 ;
V_17 = F_25 ( V_12 , V_67 , & V_65 ) ;
if ( V_17 ) {
V_23 = V_17 ;
goto V_13;
}
V_66 = ( F_6 ( V_12 ) < ( V_53 - V_23 ) ) ?
F_6 ( V_12 ) : ( V_53 - V_23 ) ;
memcpy ( V_7 + V_23 , V_67 , V_66 ) ;
V_23 += V_66 ;
if ( V_23 < V_53 )
F_17 ( V_82 , F_12 ( V_12 ) ) ;
}
V_13:
memset ( V_12 -> V_49 , 0 ,
( F_12 ( V_12 ) + F_6 ( V_12 ) ) ) ;
return V_23 ;
}
static int F_33 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_53 ,
struct V_15 * V_54 )
{
int V_23 = 0 ;
int V_17 = 0 ;
union {
unsigned char V_83 [ 8 ] ;
T_5 V_84 ;
} V_85 ;
unsigned char V_62 = V_86 ;
struct V_18 V_78 , V_79 ;
F_11 ( V_65 ) ;
V_17 = F_31 ( V_12 , V_54 ) ;
if ( V_17 )
return V_17 ;
V_23 = F_32 ( V_12 , V_7 , V_53 ) ;
F_5 ( & V_78 , & V_62 , 1 ) ;
F_13 ( & V_78 . V_46 , & V_65 ) ;
F_5 ( & V_79 , V_12 -> V_50 , F_12 ( V_12 ) ) ;
F_13 ( & V_79 . V_46 , & V_65 ) ;
V_17 = F_25 ( V_12 , V_12 -> V_49 , & V_65 ) ;
if ( V_17 ) {
V_23 = V_17 ;
goto V_13;
}
F_27 ( V_12 -> V_50 , F_12 ( V_12 ) ,
V_12 -> V_49 , F_6 ( V_12 ) ) ;
F_27 ( V_12 -> V_50 , F_12 ( V_12 ) ,
V_12 -> V_52 , F_12 ( V_12 ) ) ;
V_85 . V_84 = F_34 ( V_12 -> V_87 ) ;
F_27 ( V_12 -> V_50 , F_12 ( V_12 ) , V_85 . V_83 , 8 ) ;
V_13:
memset ( V_12 -> V_49 , 0 , F_6 ( V_12 ) ) ;
return V_23 ;
}
static inline int F_35 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = V_12 -> V_88 -> V_89 ( V_12 , V_44 , V_48 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_90 = true ;
V_12 -> V_87 = 1 ;
return V_17 ;
}
static void F_36 ( struct V_91 * V_92 )
{
struct V_18 V_20 ;
F_11 ( V_26 ) ;
struct V_11 * V_12 = F_37 ( V_92 , struct V_11 ,
V_93 ) ;
unsigned int V_94 = F_1 ( V_12 -> V_95 -> V_1 ) ;
unsigned char V_96 [ 32 ] ;
F_38 ( ! V_94 ) ;
F_38 ( V_94 > sizeof( V_96 ) ) ;
F_39 ( V_96 , V_94 ) ;
F_5 ( & V_20 , V_96 , V_94 ) ;
F_13 ( & V_20 . V_46 , & V_26 ) ;
F_40 ( & V_12 -> V_97 ) ;
F_41 ( V_12 -> V_98 ) ;
V_12 -> V_98 = NULL ;
V_12 -> V_90 = false ;
F_35 ( V_12 , & V_26 , true ) ;
if ( V_12 -> V_90 )
V_12 -> V_99 = F_42 ( V_12 ) ;
F_43 ( & V_12 -> V_97 ) ;
F_44 ( V_96 , V_94 ) ;
}
static int F_45 ( struct V_11 * V_12 , struct V_18 * V_100 ,
bool V_48 )
{
int V_17 ;
unsigned char V_96 [ ( ( 32 + 16 ) * 2 ) ] ;
unsigned int V_94 = F_1 ( V_12 -> V_95 -> V_1 ) ;
struct V_18 V_78 ;
F_11 ( V_26 ) ;
if ( V_100 && V_100 -> V_23 > ( F_46 ( V_12 ) ) ) {
F_47 ( L_5 ,
V_100 -> V_23 ) ;
return - V_45 ;
}
if ( F_22 ( & V_12 -> V_101 . V_46 ) ) {
F_5 ( & V_78 , V_12 -> V_101 . V_7 ,
V_12 -> V_101 . V_23 ) ;
F_47 ( L_6 ) ;
} else {
F_38 ( ! V_94 ) ;
if ( ! V_48 )
V_94 = ( ( V_94 + 1 ) / 2 ) * 3 ;
F_38 ( ( V_94 * 2 ) > sizeof( V_96 ) ) ;
F_39 ( V_96 , V_94 ) ;
if ( ! V_12 -> V_98 ) {
F_5 ( & V_78 , V_96 , V_94 ) ;
F_47 ( L_7 ,
V_94 ) ;
} else {
V_17 = F_48 ( V_12 -> V_98 ,
V_96 + V_94 ,
V_94 ) ;
if ( V_17 ) {
F_47 ( L_8 , V_17 ) ;
return V_17 ;
}
F_5 ( & V_78 , V_96 , V_94 * 2 ) ;
F_47 ( L_7 ,
V_94 * 2 ) ;
}
}
F_13 ( & V_78 . V_46 , & V_26 ) ;
if ( V_100 && V_100 -> V_7 && 0 < V_100 -> V_23 ) {
F_13 ( & V_100 -> V_46 , & V_26 ) ;
F_47 ( L_9 ) ;
}
if ( ! V_48 ) {
memset ( V_12 -> V_50 , 0 , F_12 ( V_12 ) ) ;
memset ( V_12 -> V_52 , 0 , F_12 ( V_12 ) ) ;
}
V_17 = F_35 ( V_12 , & V_26 , V_48 ) ;
F_44 ( V_96 , V_94 * 2 ) ;
return V_17 ;
}
static inline void F_49 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_50 ( V_12 -> V_50 ) ;
V_12 -> V_102 = NULL ;
F_50 ( V_12 -> V_52 ) ;
V_12 -> V_103 = NULL ;
F_50 ( V_12 -> V_104 ) ;
V_12 -> V_104 = NULL ;
V_12 -> V_87 = 0 ;
V_12 -> V_88 = NULL ;
V_12 -> V_95 = NULL ;
}
static inline int F_51 ( struct V_11 * V_12 )
{
int V_17 = - V_105 ;
unsigned int V_106 = 0 ;
switch ( V_12 -> V_95 -> V_1 & V_107 ) {
#ifdef F_52
case V_108 :
V_12 -> V_88 = & V_109 ;
break;
#endif
#ifdef F_53
case V_110 :
V_12 -> V_88 = & V_111 ;
break;
#endif
#ifdef F_54
case V_112 :
V_12 -> V_88 = & V_113 ;
break;
#endif
default:
V_17 = - V_114 ;
goto V_115;
}
V_17 = V_12 -> V_88 -> V_116 ( V_12 ) ;
if ( V_17 < 0 )
goto V_115;
V_12 -> V_102 = F_55 ( F_12 ( V_12 ) + V_17 , V_117 ) ;
if ( ! V_12 -> V_102 ) {
V_17 = - V_105 ;
goto V_118;
}
V_12 -> V_50 = F_56 ( V_12 -> V_102 , V_17 + 1 ) ;
V_12 -> V_103 = F_55 ( F_12 ( V_12 ) + V_17 , V_117 ) ;
if ( ! V_12 -> V_103 ) {
V_17 = - V_105 ;
goto V_118;
}
V_12 -> V_52 = F_56 ( V_12 -> V_103 , V_17 + 1 ) ;
if ( V_12 -> V_95 -> V_1 & V_108 )
V_106 = 0 ;
else if ( V_12 -> V_95 -> V_1 & V_112 )
V_106 = F_12 ( V_12 ) + F_6 ( V_12 ) +
F_12 ( V_12 ) +
F_6 ( V_12 ) +
F_6 ( V_12 ) +
F_12 ( V_12 ) + F_6 ( V_12 ) ;
else
V_106 = F_12 ( V_12 ) + F_6 ( V_12 ) ;
if ( 0 < V_106 ) {
V_12 -> V_104 = F_57 ( V_106 + V_17 , V_117 ) ;
if ( ! V_12 -> V_104 ) {
V_17 = - V_105 ;
goto V_118;
}
V_12 -> V_49 = F_56 ( V_12 -> V_104 , V_17 + 1 ) ;
}
return 0 ;
V_118:
V_12 -> V_88 -> V_119 ( V_12 ) ;
V_115:
F_49 ( V_12 ) ;
return V_17 ;
}
static int F_58 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_53 ,
struct V_18 * V_54 )
{
int V_23 = 0 ;
F_11 ( V_120 ) ;
if ( ! V_12 -> V_95 ) {
F_47 ( L_10 ) ;
return - V_45 ;
}
if ( 0 == V_53 || ! V_7 ) {
F_47 ( L_11 ) ;
return - V_45 ;
}
if ( V_54 && NULL == V_54 -> V_7 && 0 < V_54 -> V_23 ) {
F_47 ( L_12 ) ;
return - V_45 ;
}
V_23 = - V_45 ;
if ( V_53 > ( F_59 ( V_12 ) ) ) {
F_47 ( L_13 ,
V_53 ) ;
goto V_115;
}
if ( V_54 && V_54 -> V_23 > ( F_46 ( V_12 ) ) ) {
F_47 ( L_14 ,
V_54 -> V_23 ) ;
goto V_115;
}
if ( V_12 -> V_99 < V_12 -> V_87 )
V_12 -> V_90 = false ;
if ( V_12 -> V_121 || ! V_12 -> V_90 ) {
F_47 ( L_15
L_16 ,
V_12 -> V_121 ? L_17 : L_18 ,
V_12 -> V_90 ? L_19 : L_20 ) ;
V_23 = F_45 ( V_12 , V_54 , true ) ;
if ( V_23 )
goto V_115;
V_54 = NULL ;
}
if ( V_54 && 0 < V_54 -> V_23 )
F_13 ( & V_54 -> V_46 , & V_120 ) ;
V_23 = V_12 -> V_88 -> V_122 ( V_12 , V_7 , V_53 , & V_120 ) ;
V_12 -> V_87 ++ ;
if ( 0 >= V_23 )
goto V_115;
#if 0
if (drbg->reseed_ctr && !(drbg->reseed_ctr % 4096)) {
int err = 0;
pr_devel("DRBG: start to perform self test\n");
if (drbg->core->flags & DRBG_HMAC)
err = alg_test("drbg_pr_hmac_sha256",
"drbg_pr_hmac_sha256", 0, 0);
else if (drbg->core->flags & DRBG_CTR)
err = alg_test("drbg_pr_ctr_aes128",
"drbg_pr_ctr_aes128", 0, 0);
else
err = alg_test("drbg_pr_sha256",
"drbg_pr_sha256", 0, 0);
if (err) {
pr_err("DRBG: periodical self test failed\n");
drbg_uninstantiate(drbg);
return 0;
} else {
pr_devel("DRBG: self test successful\n");
}
}
#endif
V_23 = 0 ;
V_115:
return V_23 ;
}
static int F_60 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_53 ,
struct V_18 * V_54 )
{
unsigned int V_23 = 0 ;
unsigned int V_123 = 0 ;
do {
int V_115 = 0 ;
unsigned int V_124 = 0 ;
V_123 = ( ( V_53 - V_23 ) / F_59 ( V_12 ) ) ;
V_124 = V_123 ? F_59 ( V_12 ) : ( V_53 - V_23 ) ;
F_40 ( & V_12 -> V_97 ) ;
V_115 = F_58 ( V_12 , V_7 + V_23 , V_124 , V_54 ) ;
F_43 ( & V_12 -> V_97 ) ;
if ( 0 > V_115 )
return V_115 ;
V_23 += V_124 ;
} while ( V_123 > 0 && ( V_23 < V_53 ) );
return 0 ;
}
static void F_61 ( struct V_125 * V_126 )
{
struct V_11 * V_12 = F_37 ( V_126 , struct V_11 ,
V_127 ) ;
F_62 ( & V_12 -> V_93 ) ;
}
static int F_63 ( struct V_11 * V_12 )
{
int V_115 ;
if ( F_22 ( & V_12 -> V_101 . V_46 ) )
return 0 ;
F_64 ( & V_12 -> V_93 , F_36 ) ;
V_12 -> V_127 . V_128 = V_129 ;
V_12 -> V_127 . V_130 = F_61 ;
V_115 = F_65 ( & V_12 -> V_127 ) ;
switch ( V_115 ) {
case 0 :
break;
case - V_131 :
V_115 = 0 ;
default:
V_12 -> V_127 . V_130 = NULL ;
return V_115 ;
}
V_12 -> V_98 = F_66 ( L_21 , 0 , 0 ) ;
V_12 -> V_99 = 50 ;
return V_115 ;
}
static int F_67 ( struct V_11 * V_12 , struct V_18 * V_100 ,
int V_132 , bool V_121 )
{
int V_17 ;
bool V_48 = true ;
F_47 ( L_22
L_23 , V_132 , V_121 ? L_24 : L_25 ) ;
F_40 ( & V_12 -> V_97 ) ;
if ( ! V_12 -> V_95 ) {
V_12 -> V_95 = & V_133 [ V_132 ] ;
V_12 -> V_121 = V_121 ;
V_12 -> V_90 = false ;
V_12 -> V_99 = F_42 ( V_12 ) ;
V_17 = F_51 ( V_12 ) ;
if ( V_17 )
goto V_134;
V_17 = F_63 ( V_12 ) ;
if ( V_17 )
goto V_135;
if ( F_68 ( V_12 -> V_98 ) ) {
V_17 = F_69 ( V_12 -> V_98 ) ;
V_12 -> V_98 = NULL ;
if ( V_136 || V_17 != - V_137 )
goto V_135;
F_70 ( L_26 ) ;
}
V_48 = false ;
}
V_17 = F_45 ( V_12 , V_100 , V_48 ) ;
if ( V_17 && ! V_48 )
goto V_135;
F_43 ( & V_12 -> V_97 ) ;
return V_17 ;
V_134:
F_43 ( & V_12 -> V_97 ) ;
return V_17 ;
V_135:
F_43 ( & V_12 -> V_97 ) ;
F_71 ( V_12 ) ;
return V_17 ;
}
static int F_71 ( struct V_11 * V_12 )
{
if ( V_12 -> V_127 . V_130 ) {
F_72 ( & V_12 -> V_127 ) ;
F_73 ( & V_12 -> V_93 ) ;
F_41 ( V_12 -> V_98 ) ;
V_12 -> V_98 = NULL ;
}
if ( V_12 -> V_88 )
V_12 -> V_88 -> V_119 ( V_12 ) ;
F_49 ( V_12 ) ;
return 0 ;
}
static void F_74 ( struct V_138 * V_139 ,
const T_6 * V_20 , unsigned int V_23 )
{
struct V_11 * V_12 = F_75 ( V_139 ) ;
F_40 ( & V_12 -> V_97 ) ;
F_5 ( & V_12 -> V_101 , V_20 , V_23 ) ;
F_43 ( & V_12 -> V_97 ) ;
}
static int F_76 ( struct V_11 * V_12 )
{
struct V_140 * V_140 ;
struct V_141 * V_139 ;
V_139 = F_77 ( V_12 -> V_95 -> V_142 , 0 , 0 ) ;
if ( F_68 ( V_139 ) ) {
F_70 ( L_27 ,
V_12 -> V_95 -> V_142 ) ;
return F_69 ( V_139 ) ;
}
F_38 ( F_6 ( V_12 ) != F_78 ( V_139 ) ) ;
V_140 = F_57 ( sizeof( struct V_143 ) + F_79 ( V_139 ) ,
V_117 ) ;
if ( ! V_140 ) {
F_80 ( V_139 ) ;
return - V_105 ;
}
V_140 -> V_144 . V_139 = V_139 ;
V_140 -> V_144 . V_1 = 0 ;
V_12 -> V_145 = V_140 ;
return F_81 ( V_139 ) ;
}
static int F_82 ( struct V_11 * V_12 )
{
struct V_140 * V_140 = (struct V_140 * ) V_12 -> V_145 ;
if ( V_140 ) {
F_80 ( V_140 -> V_144 . V_139 ) ;
F_50 ( V_140 ) ;
}
V_12 -> V_145 = NULL ;
return 0 ;
}
static void F_24 ( struct V_11 * V_12 ,
const unsigned char * V_14 )
{
struct V_140 * V_140 = (struct V_140 * ) V_12 -> V_145 ;
F_83 ( V_140 -> V_144 . V_139 , V_14 , F_12 ( V_12 ) ) ;
}
static int F_25 ( struct V_11 * V_12 , unsigned char * V_74 ,
const struct V_15 * V_16 )
{
struct V_140 * V_140 = (struct V_140 * ) V_12 -> V_145 ;
struct V_18 * V_76 = NULL ;
F_84 ( & V_140 -> V_144 ) ;
F_8 (input, in, list)
F_85 ( & V_140 -> V_144 , V_76 -> V_7 , V_76 -> V_23 ) ;
return F_86 ( & V_140 -> V_144 , V_74 ) ;
}
static int F_87 ( struct V_11 * V_12 )
{
struct V_146 * V_139 =
(struct V_146 * ) V_12 -> V_145 ;
if ( V_139 )
F_88 ( V_139 ) ;
V_12 -> V_145 = NULL ;
if ( V_12 -> V_51 )
F_89 ( V_12 -> V_51 ) ;
V_12 -> V_51 = NULL ;
if ( V_12 -> V_147 )
F_90 ( V_12 -> V_147 ) ;
V_12 -> V_147 = NULL ;
F_91 ( V_12 -> V_148 ) ;
V_12 -> V_56 = NULL ;
F_91 ( V_12 -> V_149 ) ;
V_12 -> V_149 = NULL ;
return 0 ;
}
static void F_92 ( struct V_150 * V_83 , int error )
{
struct V_11 * V_12 = V_83 -> V_20 ;
if ( error == - V_151 )
return;
V_12 -> V_152 = error ;
F_93 ( & V_12 -> V_153 ) ;
}
static int F_94 ( struct V_11 * V_12 )
{
struct V_146 * V_139 ;
struct V_154 * V_155 ;
struct V_156 * V_83 ;
unsigned int V_157 ;
char V_158 [ V_159 ] ;
V_139 = F_95 ( V_12 -> V_95 -> V_142 , 0 , 0 ) ;
if ( F_68 ( V_139 ) ) {
F_70 ( L_28 ,
V_12 -> V_95 -> V_142 ) ;
return F_69 ( V_139 ) ;
}
F_38 ( F_6 ( V_12 ) != F_96 ( V_139 ) ) ;
V_12 -> V_145 = V_139 ;
if ( snprintf ( V_158 , V_159 , L_29 ,
V_12 -> V_95 -> V_142 ) >= V_159 ) {
F_87 ( V_12 ) ;
return - V_45 ;
}
V_155 = F_97 ( V_158 , 0 , 0 ) ;
if ( F_68 ( V_155 ) ) {
F_70 ( L_30 ,
V_158 ) ;
F_87 ( V_12 ) ;
return F_69 ( V_155 ) ;
}
V_12 -> V_51 = V_155 ;
V_83 = F_98 ( V_155 , V_117 ) ;
if ( ! V_83 ) {
F_70 ( L_31 ) ;
F_87 ( V_12 ) ;
return - V_105 ;
}
V_12 -> V_147 = V_83 ;
F_99 ( V_83 , V_160 ,
F_92 , V_12 ) ;
V_157 = F_100 ( V_155 ) ;
V_12 -> V_148 = F_57 ( V_57 + V_157 ,
V_117 ) ;
if ( ! V_12 -> V_148 ) {
F_87 ( V_12 ) ;
return - V_105 ;
}
V_12 -> V_56 = ( T_6 * ) F_56 ( V_12 -> V_148 ,
V_157 + 1 ) ;
V_12 -> V_149 = F_55 ( V_161 + V_157 ,
V_117 ) ;
if ( ! V_12 -> V_149 ) {
F_87 ( V_12 ) ;
return - V_105 ;
}
V_12 -> V_162 = ( T_6 * ) F_56 ( V_12 -> V_149 ,
V_157 + 1 ) ;
return V_157 ;
}
static void F_7 ( struct V_11 * V_12 ,
const unsigned char * V_14 )
{
struct V_146 * V_139 =
(struct V_146 * ) V_12 -> V_145 ;
F_101 ( V_139 , V_14 , ( F_15 ( V_12 ) ) ) ;
}
static int F_9 ( struct V_11 * V_12 , unsigned char * V_74 ,
const struct V_18 * V_16 )
{
struct V_146 * V_139 =
(struct V_146 * ) V_12 -> V_145 ;
F_38 ( V_16 -> V_23 < F_6 ( V_12 ) ) ;
F_102 ( V_139 , V_74 , V_16 -> V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_11 * V_12 ,
T_6 * V_163 , T_7 V_164 ,
T_6 * V_165 , T_7 V_66 )
{
struct V_166 V_167 ;
int V_17 ;
F_103 ( & V_167 , V_163 , V_164 ) ;
while ( V_66 ) {
T_7 V_168 = F_104 ( V_164 , V_66 , ( T_7 ) V_161 ) ;
struct V_166 V_169 ;
F_103 ( & V_169 , V_12 -> V_162 , V_168 ) ;
F_105 ( V_12 -> V_147 , & V_167 , & V_169 ,
V_168 , V_12 -> V_50 ) ;
V_17 = F_106 ( V_12 -> V_147 ) ;
switch ( V_17 ) {
case 0 :
break;
case - V_151 :
case - V_170 :
V_17 = F_107 (
& V_12 -> V_153 ) ;
if ( ! V_17 && ! V_12 -> V_152 ) {
F_108 ( & V_12 -> V_153 ) ;
break;
}
default:
goto V_13;
}
F_109 ( & V_12 -> V_153 ) ;
memcpy ( V_165 , V_12 -> V_162 , V_168 ) ;
V_66 -= V_168 ;
}
V_17 = 0 ;
V_13:
F_44 ( V_12 -> V_162 , V_161 ) ;
return V_17 ;
}
static inline void F_110 ( const char * V_171 ,
int * V_132 , bool * V_121 )
{
int V_39 = 0 ;
T_4 V_172 = 0 ;
int V_23 = 0 ;
* V_121 = true ;
if ( ! memcmp ( V_171 , L_32 , 10 ) ) {
V_172 = 10 ;
* V_121 = false ;
} else if ( ! memcmp ( V_171 , L_33 , 8 ) ) {
V_172 = 8 ;
} else {
return;
}
V_23 = strlen ( V_171 ) - V_172 ;
for ( V_39 = 0 ; F_111 ( V_133 ) > V_39 ; V_39 ++ ) {
if ( ! memcmp ( V_171 + V_172 , V_133 [ V_39 ] . V_173 ,
V_23 ) ) {
* V_132 = V_39 ;
return;
}
}
}
static int F_112 ( struct V_174 * V_139 )
{
struct V_11 * V_12 = F_113 ( V_139 ) ;
F_114 ( & V_12 -> V_97 ) ;
return 0 ;
}
static void F_115 ( struct V_174 * V_139 )
{
F_71 ( F_113 ( V_139 ) ) ;
}
static int F_116 ( struct V_138 * V_139 ,
const T_6 * V_82 , unsigned int V_175 ,
T_6 * V_67 , unsigned int V_176 )
{
struct V_11 * V_12 = F_75 ( V_139 ) ;
struct V_18 * V_54 = NULL ;
struct V_18 string ;
if ( V_175 ) {
F_5 ( & string , V_82 , V_175 ) ;
V_54 = & string ;
}
return F_60 ( V_12 , V_67 , V_176 , V_54 ) ;
}
static int F_117 ( struct V_138 * V_139 ,
const T_6 * V_44 , unsigned int V_175 )
{
struct V_11 * V_12 = F_75 ( V_139 ) ;
struct V_174 * V_177 = F_118 ( V_139 ) ;
bool V_121 = false ;
struct V_18 string ;
struct V_18 * V_178 = NULL ;
int V_132 = 0 ;
F_110 ( F_119 ( V_177 ) , & V_132 ,
& V_121 ) ;
if ( 0 < V_175 ) {
F_5 ( & string , V_44 , V_175 ) ;
V_178 = & string ;
}
return F_67 ( V_12 , V_178 , V_132 , V_121 ) ;
}
static inline int T_8 F_120 ( void )
{
int V_23 = 0 ;
#define F_121 16
unsigned char V_7 [ F_121 ] ;
struct V_11 * V_12 = NULL ;
int V_17 = - V_27 ;
int V_179 = - V_27 ;
bool V_121 = false ;
int V_132 = 0 ;
struct V_18 V_54 ;
T_4 V_180 , V_181 ;
if ( ! V_136 )
return 0 ;
#ifdef F_54
F_110 ( L_34 , & V_132 , & V_121 ) ;
#elif V_182 F_53
F_110 ( L_35 , & V_132 , & V_121 ) ;
#else
F_110 ( L_36 , & V_132 , & V_121 ) ;
#endif
V_12 = F_57 ( sizeof( struct V_11 ) , V_117 ) ;
if ( ! V_12 )
return - V_105 ;
F_114 ( & V_12 -> V_97 ) ;
V_12 -> V_95 = & V_133 [ V_132 ] ;
V_12 -> V_99 = F_42 ( V_12 ) ;
V_180 = F_46 ( V_12 ) ;
V_181 = F_59 ( V_12 ) ;
F_5 ( & V_54 , V_7 , V_180 + 1 ) ;
V_23 = F_58 ( V_12 , V_7 , F_121 , & V_54 ) ;
F_38 ( 0 < V_23 ) ;
V_23 = F_58 ( V_12 , V_7 , ( V_181 + 1 ) , NULL ) ;
F_38 ( 0 < V_23 ) ;
V_17 = F_45 ( V_12 , & V_54 , false ) ;
F_38 ( 0 == V_17 ) ;
V_179 = 0 ;
F_47 ( L_37
L_38 ) ;
F_91 ( V_12 ) ;
return V_179 ;
}
static inline void T_8 F_122 ( struct V_183 * V_184 ,
const struct V_185 * V_95 , int V_121 )
{
int V_22 = 0 ;
static int V_186 = 200 ;
memcpy ( V_184 -> V_187 . V_173 , L_39 , 6 ) ;
if ( V_121 ) {
memcpy ( V_184 -> V_187 . V_171 , L_33 , 8 ) ;
V_22 = 8 ;
} else {
memcpy ( V_184 -> V_187 . V_171 , L_32 , 10 ) ;
V_22 = 10 ;
}
memcpy ( V_184 -> V_187 . V_171 + V_22 , V_95 -> V_173 ,
strlen ( V_95 -> V_173 ) ) ;
V_184 -> V_187 . V_188 = V_186 ;
V_186 ++ ;
if ( V_136 )
V_184 -> V_187 . V_188 += 200 ;
V_184 -> V_187 . V_189 = sizeof( struct V_11 ) ;
V_184 -> V_187 . V_190 = V_129 ;
V_184 -> V_187 . V_191 = F_112 ;
V_184 -> V_187 . V_192 = F_115 ;
V_184 -> V_122 = F_116 ;
V_184 -> V_44 = F_117 ;
V_184 -> V_193 = F_74 ;
V_184 -> V_194 = 0 ;
}
static int T_8 F_123 ( void )
{
unsigned int V_39 = 0 ;
unsigned int V_195 = 0 ;
int V_17 ;
V_17 = F_120 () ;
if ( V_17 )
return V_17 ;
if ( F_111 ( V_133 ) * 2 > F_111 ( V_196 ) ) {
F_70 ( L_40
L_41 ,
F_111 ( V_133 ) * 2 , F_111 ( V_196 ) ) ;
return - V_27 ;
}
for ( V_195 = 0 ; F_111 ( V_133 ) > V_195 ; V_195 ++ , V_39 ++ )
F_122 ( & V_196 [ V_39 ] , & V_133 [ V_195 ] , 1 ) ;
for ( V_195 = 0 ; F_111 ( V_133 ) > V_195 ; V_195 ++ , V_39 ++ )
F_122 ( & V_196 [ V_39 ] , & V_133 [ V_195 ] , 0 ) ;
return F_124 ( V_196 , ( F_111 ( V_133 ) * 2 ) ) ;
}
static void T_9 F_125 ( void )
{
F_126 ( V_196 , ( F_111 ( V_133 ) * 2 ) ) ;
}
