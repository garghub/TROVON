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
static bool F_2 ( struct V_6 * V_7 ,
const unsigned char * V_8 )
{
#ifdef F_3
int V_9 = 0 ;
if ( V_7 -> V_10 )
return true ;
if ( 0 == V_11 )
return true ;
if ( ! V_7 -> V_12 ) {
memcpy ( V_7 -> V_13 , V_8 , F_4 ( V_7 ) ) ;
V_7 -> V_12 = true ;
return false ;
}
V_9 = memcmp ( V_7 -> V_13 , V_8 , F_4 ( V_7 ) ) ;
memcpy ( V_7 -> V_13 , V_8 , F_4 ( V_7 ) ) ;
return V_9 != 0 ;
#else
return true ;
#endif
}
static inline void F_5 ( unsigned char * V_8 , T_2 V_14 ,
T_3 V_15 )
{
unsigned char * V_16 ;
T_2 V_17 ;
V_16 = V_8 + ( V_15 - 1 ) ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ )
* ( V_16 -- ) = V_14 >> ( V_17 * 8 ) & 0xff ;
}
static inline void F_6 ( unsigned char * V_18 , T_3 V_19 ,
const unsigned char * V_20 , T_3 V_21 )
{
unsigned char * V_22 ;
const unsigned char * V_23 ;
unsigned int V_24 = 0 ;
T_3 V_25 = V_21 ;
V_22 = V_18 + ( V_19 - 1 ) ;
V_23 = V_20 + ( V_21 - 1 ) ;
while ( V_25 ) {
V_24 += * V_22 + * V_23 ;
* V_22 = V_24 & 0xff ;
V_24 >>= 8 ;
V_25 -- ; V_22 -- ; V_23 -- ;
}
V_25 = V_19 - V_21 ;
while ( V_25 && V_24 > 0 ) {
V_24 = * V_22 + 1 ;
* V_22 = V_24 & 0xff ;
V_24 >>= 8 ;
V_25 -- ; V_22 -- ;
}
}
static int F_7 ( struct V_6 * V_7 ,
unsigned char * V_26 , const unsigned char * V_27 ,
struct V_28 * V_29 )
{
int V_9 = 0 ;
struct V_30 * V_31 = NULL ;
struct V_30 V_32 ;
short V_33 = 0 ;
F_8 ( & V_32 , V_26 , F_4 ( V_7 ) ) ;
memset ( V_26 , 0 , F_4 ( V_7 ) ) ;
F_9 (curr, in, list) {
const unsigned char * V_34 = V_31 -> V_8 ;
T_3 V_25 = V_31 -> V_25 ;
while ( V_25 ) {
if ( F_4 ( V_7 ) == V_33 ) {
V_33 = 0 ;
V_9 = F_10 ( V_7 , V_27 , V_26 , & V_32 ) ;
if ( V_9 )
return V_9 ;
}
V_26 [ V_33 ] ^= * V_34 ;
V_34 ++ ;
V_33 ++ ;
V_25 -- ;
}
}
if ( V_33 )
V_9 = F_10 ( V_7 , V_27 , V_26 , & V_32 ) ;
return V_9 ;
}
static int F_11 ( struct V_6 * V_7 ,
unsigned char * V_35 , T_3 V_36 ,
struct V_28 * V_37 )
{
int V_9 = - V_38 ;
unsigned char V_39 [ 8 ] ;
struct V_30 V_40 , V_41 , V_42 , V_43 ;
F_12 ( V_44 ) ;
unsigned char * V_45 = V_35 + F_13 ( V_7 ) ;
unsigned char * V_46 = V_45 + F_4 ( V_7 ) ;
unsigned char * V_47 = V_46 + F_4 ( V_7 ) ;
T_3 V_48 = 0 ;
unsigned int V_49 = 0 ;
unsigned int V_17 = 0 ;
const unsigned char * V_50 = ( unsigned char * )
L_1
L_2
L_3
L_4 ;
unsigned char * V_51 ;
T_3 V_52 = 0 ;
T_3 V_53 = 0 ;
struct V_30 * V_54 = NULL ;
memset ( V_45 , 0 , F_4 ( V_7 ) ) ;
memset ( V_46 , 0 , F_4 ( V_7 ) ) ;
memset ( V_47 , 0 , F_13 ( V_7 ) ) ;
if ( ( 512 / 8 ) < V_36 )
return - V_55 ;
F_9 (seed, seedlist, list)
V_53 += V_54 -> V_25 ;
F_5 ( & V_39 [ 0 ] , V_53 , 4 ) ;
F_5 ( & V_39 [ 4 ] , V_36 , 4 ) ;
V_48 = ( V_53 + sizeof( V_39 ) + 1 ) % ( F_4 ( V_7 ) ) ;
if ( V_48 )
V_48 = F_4 ( V_7 ) - V_48 ;
V_48 ++ ;
V_45 [ 0 ] = 0x80 ;
F_8 ( & V_40 , V_46 , F_4 ( V_7 ) ) ;
F_14 ( & V_40 . V_56 , & V_44 ) ;
F_8 ( & V_41 , V_39 , sizeof( V_39 ) ) ;
F_14 ( & V_41 . V_56 , & V_44 ) ;
F_15 ( V_37 , & V_44 ) ;
F_8 ( & V_42 , V_45 , V_48 ) ;
F_14 ( & V_42 . V_56 , & V_44 ) ;
while ( V_49 < ( F_16 ( V_7 ) + ( F_4 ( V_7 ) ) ) ) {
F_5 ( V_46 , V_17 , 4 ) ;
V_9 = F_7 ( V_7 , V_47 + V_49 , V_50 , & V_44 ) ;
if ( V_9 )
goto V_26;
V_17 ++ ;
V_49 += F_4 ( V_7 ) ;
}
V_51 = V_47 + ( F_16 ( V_7 ) ) ;
F_8 ( & V_43 , V_51 , F_4 ( V_7 ) ) ;
while ( V_52 < V_36 ) {
short V_57 = 0 ;
V_9 = F_10 ( V_7 , V_47 , V_51 , & V_43 ) ;
if ( V_9 )
goto V_26;
V_57 = ( F_4 ( V_7 ) <
( V_36 - V_52 ) ) ?
F_4 ( V_7 ) :
( V_36 - V_52 ) ;
memcpy ( V_35 + V_52 , V_51 , V_57 ) ;
V_52 += V_57 ;
}
V_9 = 0 ;
V_26:
memset ( V_46 , 0 , F_4 ( V_7 ) ) ;
memset ( V_47 , 0 , F_13 ( V_7 ) ) ;
memset ( V_45 , 0 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_17 ( struct V_6 * V_7 , struct V_28 * V_54 ,
int V_58 )
{
int V_9 = - V_38 ;
unsigned char * V_47 = V_7 -> V_59 ;
unsigned char * V_35 = V_7 -> V_59 + F_13 ( V_7 ) +
F_4 ( V_7 ) ;
unsigned char * V_60 , * V_61 ;
unsigned int V_25 = 0 ;
struct V_30 V_43 ;
unsigned char V_62 = V_63 ;
memset ( V_47 , 0 , F_13 ( V_7 ) + F_4 ( V_7 ) ) ;
if ( 3 > V_58 )
memset ( V_35 , 0 , F_13 ( V_7 ) ) ;
if ( V_54 ) {
V_9 = F_11 ( V_7 , V_35 , F_13 ( V_7 ) , V_54 ) ;
if ( V_9 )
goto V_26;
}
F_8 ( & V_43 , V_7 -> V_64 , F_4 ( V_7 ) ) ;
while ( V_25 < ( F_13 ( V_7 ) ) ) {
F_6 ( V_7 -> V_64 , F_4 ( V_7 ) , & V_62 , 1 ) ;
V_9 = F_10 ( V_7 , V_7 -> V_65 , V_47 + V_25 , & V_43 ) ;
if ( V_9 )
goto V_26;
V_25 += F_4 ( V_7 ) ;
}
V_60 = V_47 ;
V_61 = V_35 ;
for ( V_25 = 0 ; V_25 < F_13 ( V_7 ) ; V_25 ++ ) {
* V_60 ^= * V_61 ;
V_61 ++ ; V_60 ++ ;
}
memcpy ( V_7 -> V_65 , V_47 , F_16 ( V_7 ) ) ;
memcpy ( V_7 -> V_64 , V_47 + F_16 ( V_7 ) , F_4 ( V_7 ) ) ;
V_9 = 0 ;
V_26:
memset ( V_47 , 0 , F_13 ( V_7 ) + F_4 ( V_7 ) ) ;
if ( 2 != V_58 )
memset ( V_35 , 0 , F_13 ( V_7 ) ) ;
return V_9 ;
}
static int F_18 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_15 ,
struct V_28 * V_66 )
{
int V_25 = 0 ;
int V_9 = 0 ;
struct V_30 V_32 ;
unsigned char V_62 = V_63 ;
memset ( V_7 -> V_59 , 0 , F_4 ( V_7 ) ) ;
if ( V_66 && ! F_19 ( V_66 ) ) {
V_9 = F_17 ( V_7 , V_66 , 2 ) ;
if ( V_9 )
return 0 ;
}
F_6 ( V_7 -> V_64 , F_4 ( V_7 ) , & V_62 , 1 ) ;
F_8 ( & V_32 , V_7 -> V_64 , F_4 ( V_7 ) ) ;
while ( V_25 < V_15 ) {
int V_67 = 0 ;
V_9 = F_10 ( V_7 , V_7 -> V_65 , V_7 -> V_59 , & V_32 ) ;
if ( V_9 ) {
V_25 = V_9 ;
goto V_26;
}
V_67 = ( F_4 ( V_7 ) < ( V_15 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_15 - V_25 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_59 ) ) {
F_6 ( V_7 -> V_64 , F_4 ( V_7 ) , & V_62 , 1 ) ;
continue;
}
memcpy ( V_8 + V_25 , V_7 -> V_59 , V_67 ) ;
V_25 += V_67 ;
if ( V_25 < V_15 )
F_6 ( V_7 -> V_64 , F_4 ( V_7 ) , & V_62 , 1 ) ;
}
V_9 = F_17 ( V_7 , NULL , 3 ) ;
if ( V_9 )
V_25 = V_9 ;
V_26:
memset ( V_7 -> V_59 , 0 , F_4 ( V_7 ) ) ;
return V_25 ;
}
static int F_20 ( struct V_6 * V_7 , struct V_28 * V_54 ,
int V_58 )
{
int V_9 = - V_38 ;
int V_17 = 0 ;
struct V_30 V_68 , V_69 , V_70 ;
F_12 ( V_37 ) ;
F_12 ( V_71 ) ;
if ( ! V_58 ) {
memset ( V_7 -> V_65 , 0 , F_13 ( V_7 ) ) ;
memset ( V_7 -> V_64 , 1 , F_13 ( V_7 ) ) ;
}
F_8 ( & V_68 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_14 ( & V_68 . V_56 , & V_37 ) ;
F_8 ( & V_69 , NULL , 1 ) ;
F_14 ( & V_69 . V_56 , & V_37 ) ;
if ( V_54 )
F_15 ( V_54 , & V_37 ) ;
F_8 ( & V_70 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_14 ( & V_70 . V_56 , & V_71 ) ;
for ( V_17 = 2 ; 0 < V_17 ; V_17 -- ) {
unsigned char V_62 = V_72 ;
if ( 1 == V_17 )
V_62 = V_63 ;
V_69 . V_8 = & V_62 ;
V_9 = F_21 ( V_7 , V_7 -> V_65 , V_7 -> V_65 , & V_37 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_21 ( V_7 , V_7 -> V_65 , V_7 -> V_64 , & V_71 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_54 )
return V_9 ;
}
return 0 ;
}
static int F_22 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_15 ,
struct V_28 * V_66 )
{
int V_25 = 0 ;
int V_9 = 0 ;
struct V_30 V_32 ;
F_12 ( V_73 ) ;
if ( V_66 && ! F_19 ( V_66 ) ) {
V_9 = F_20 ( V_7 , V_66 , 1 ) ;
if ( V_9 )
return V_9 ;
}
F_8 ( & V_32 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_14 ( & V_32 . V_56 , & V_73 ) ;
while ( V_25 < V_15 ) {
unsigned int V_67 = 0 ;
V_9 = F_21 ( V_7 , V_7 -> V_65 , V_7 -> V_64 , & V_73 ) ;
if ( V_9 )
return V_9 ;
V_67 = ( F_4 ( V_7 ) < ( V_15 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_15 - V_25 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_64 ) )
continue;
memcpy ( V_8 + V_25 , V_7 -> V_64 , V_67 ) ;
V_25 += V_67 ;
}
if ( V_66 && ! F_19 ( V_66 ) )
V_9 = F_20 ( V_7 , V_66 , 1 ) ;
else
V_9 = F_20 ( V_7 , NULL , 1 ) ;
if ( V_9 )
return V_9 ;
return V_25 ;
}
static int F_23 ( struct V_6 * V_7 ,
unsigned char * V_74 , T_3 V_67 ,
struct V_28 * V_75 )
{
int V_9 = 0 ;
T_3 V_25 = 0 ;
unsigned char V_76 [ 5 ] ;
unsigned char * V_77 = V_7 -> V_59 + F_13 ( V_7 ) ;
struct V_30 V_32 ;
memset ( V_77 , 0 , F_4 ( V_7 ) ) ;
V_76 [ 0 ] = 1 ;
F_5 ( & V_76 [ 1 ] , ( V_67 * 8 ) , 4 ) ;
F_8 ( & V_32 , V_76 , 5 ) ;
F_24 ( & V_32 . V_56 , V_75 ) ;
while ( V_25 < V_67 ) {
short V_57 = 0 ;
V_9 = F_21 ( V_7 , NULL , V_77 , V_75 ) ;
if ( V_9 )
goto V_26;
V_76 [ 0 ] ++ ;
V_57 = ( F_4 ( V_7 ) < ( V_67 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_67 - V_25 ) ;
memcpy ( V_74 + V_25 , V_77 , V_57 ) ;
V_25 += V_57 ;
}
V_26:
memset ( V_77 , 0 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_25 ( struct V_6 * V_7 , struct V_28 * V_54 ,
int V_58 )
{
int V_9 = 0 ;
struct V_30 V_78 , V_79 ;
F_12 ( V_73 ) ;
F_12 ( V_80 ) ;
unsigned char * V_64 = V_7 -> V_59 ;
unsigned char V_62 = V_63 ;
memset ( V_7 -> V_59 , 0 , F_13 ( V_7 ) ) ;
if ( ! V_54 )
return - V_55 ;
if ( V_58 ) {
memcpy ( V_64 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_8 ( & V_78 , & V_62 , 1 ) ;
F_14 ( & V_78 . V_56 , & V_73 ) ;
F_8 ( & V_79 , V_64 , F_13 ( V_7 ) ) ;
F_14 ( & V_79 . V_56 , & V_73 ) ;
}
F_15 ( V_54 , & V_73 ) ;
V_9 = F_23 ( V_7 , V_7 -> V_64 , F_13 ( V_7 ) , & V_73 ) ;
if ( V_9 )
goto V_26;
V_62 = V_72 ;
F_8 ( & V_78 , & V_62 , 1 ) ;
F_14 ( & V_78 . V_56 , & V_80 ) ;
F_8 ( & V_79 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_14 ( & V_79 . V_56 , & V_80 ) ;
V_9 = F_23 ( V_7 , V_7 -> V_65 , F_13 ( V_7 ) , & V_80 ) ;
V_26:
memset ( V_7 -> V_59 , 0 , F_13 ( V_7 ) ) ;
return V_9 ;
}
static int F_26 ( struct V_6 * V_7 ,
struct V_28 * V_66 )
{
int V_9 = 0 ;
struct V_30 V_78 , V_79 ;
F_12 ( V_73 ) ;
unsigned char V_62 = V_81 ;
memset ( V_7 -> V_59 , 0 , F_4 ( V_7 ) ) ;
if ( ! V_66 || F_19 ( V_66 ) )
return 0 ;
F_8 ( & V_78 , & V_62 , 1 ) ;
F_8 ( & V_79 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_14 ( & V_78 . V_56 , & V_73 ) ;
F_14 ( & V_79 . V_56 , & V_73 ) ;
F_15 ( V_66 , & V_73 ) ;
V_9 = F_21 ( V_7 , NULL , V_7 -> V_59 , & V_73 ) ;
if ( V_9 )
goto V_26;
F_6 ( V_7 -> V_64 , F_13 ( V_7 ) ,
V_7 -> V_59 , F_4 ( V_7 ) ) ;
V_26:
memset ( V_7 -> V_59 , 0 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_27 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_15 )
{
int V_25 = 0 ;
int V_9 = 0 ;
unsigned char * V_82 = V_7 -> V_59 ;
unsigned char * V_18 = V_7 -> V_59 + F_13 ( V_7 ) ;
struct V_30 V_32 ;
F_12 ( V_73 ) ;
unsigned char V_62 = V_63 ;
memset ( V_82 , 0 , F_13 ( V_7 ) ) ;
memset ( V_18 , 0 , F_4 ( V_7 ) ) ;
memcpy ( V_82 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_8 ( & V_32 , V_82 , F_13 ( V_7 ) ) ;
F_14 ( & V_32 . V_56 , & V_73 ) ;
while ( V_25 < V_15 ) {
unsigned int V_67 = 0 ;
V_9 = F_21 ( V_7 , NULL , V_18 , & V_73 ) ;
if ( V_9 ) {
V_25 = V_9 ;
goto V_26;
}
V_67 = ( F_4 ( V_7 ) < ( V_15 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_15 - V_25 ) ;
if ( ! F_2 ( V_7 , V_18 ) ) {
F_6 ( V_82 , F_13 ( V_7 ) , & V_62 , 1 ) ;
continue;
}
memcpy ( V_8 + V_25 , V_18 , V_67 ) ;
V_25 += V_67 ;
if ( V_25 < V_15 )
F_6 ( V_82 , F_13 ( V_7 ) , & V_62 , 1 ) ;
}
V_26:
memset ( V_7 -> V_59 , 0 ,
( F_13 ( V_7 ) + F_4 ( V_7 ) ) ) ;
return V_25 ;
}
static int F_28 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_15 ,
struct V_28 * V_66 )
{
int V_25 = 0 ;
int V_9 = 0 ;
unsigned char V_83 [ 8 ] ;
unsigned char V_62 = V_84 ;
struct V_30 V_78 , V_79 ;
F_12 ( V_73 ) ;
V_9 = F_26 ( V_7 , V_66 ) ;
if ( V_9 )
return V_9 ;
V_25 = F_27 ( V_7 , V_8 , V_15 ) ;
memset ( V_7 -> V_59 , 0 , F_4 ( V_7 ) ) ;
F_8 ( & V_78 , & V_62 , 1 ) ;
F_14 ( & V_78 . V_56 , & V_73 ) ;
F_8 ( & V_79 , V_7 -> V_64 , F_13 ( V_7 ) ) ;
F_14 ( & V_79 . V_56 , & V_73 ) ;
V_9 = F_21 ( V_7 , NULL , V_7 -> V_59 , & V_73 ) ;
if ( V_9 ) {
V_25 = V_9 ;
goto V_26;
}
F_6 ( V_7 -> V_64 , F_13 ( V_7 ) ,
V_7 -> V_59 , F_4 ( V_7 ) ) ;
F_6 ( V_7 -> V_64 , F_13 ( V_7 ) ,
V_7 -> V_65 , F_13 ( V_7 ) ) ;
F_5 ( V_83 , V_7 -> V_85 , sizeof( V_83 ) ) ;
F_6 ( V_7 -> V_64 , F_13 ( V_7 ) , V_83 , 8 ) ;
V_26:
memset ( V_7 -> V_59 , 0 , F_4 ( V_7 ) ) ;
return V_25 ;
}
static int F_29 ( struct V_6 * V_7 , struct V_30 * V_86 ,
bool V_58 )
{
int V_9 = 0 ;
unsigned char * V_87 = NULL ;
T_3 V_88 = 0 ;
struct V_30 V_78 ;
F_12 ( V_37 ) ;
if ( V_86 && V_86 -> V_25 > ( F_30 ( V_7 ) ) ) {
F_31 ( L_5 ,
V_86 -> V_25 ) ;
return - V_55 ;
}
if ( V_7 -> V_10 && V_7 -> V_10 -> V_89 ) {
F_8 ( & V_78 , V_7 -> V_10 -> V_89 -> V_8 ,
V_7 -> V_10 -> V_89 -> V_25 ) ;
F_31 ( L_6 ) ;
} else {
V_88 = F_1 ( V_7 -> V_90 -> V_1 ) ;
if ( ! V_88 )
return - V_38 ;
if ( ! V_58 )
V_88 = ( ( V_88 + 1 ) / 2 ) * 3 ;
F_31 ( L_7 ,
V_88 ) ;
V_87 = F_32 ( V_88 , V_91 ) ;
if ( ! V_87 )
return - V_92 ;
F_33 ( V_87 , V_88 ) ;
F_8 ( & V_78 , V_87 , V_88 ) ;
}
F_14 ( & V_78 . V_56 , & V_37 ) ;
if ( V_86 && V_86 -> V_8 && 0 < V_86 -> V_25 ) {
F_14 ( & V_86 -> V_56 , & V_37 ) ;
F_31 ( L_8 ) ;
}
V_9 = V_7 -> V_93 -> V_94 ( V_7 , & V_37 , V_58 ) ;
if ( V_9 )
goto V_26;
V_7 -> V_95 = true ;
V_7 -> V_85 = 1 ;
V_26:
if ( V_87 )
F_34 ( V_87 ) ;
return V_9 ;
}
static inline void F_35 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
if ( V_7 -> V_64 )
F_34 ( V_7 -> V_64 ) ;
V_7 -> V_64 = NULL ;
if ( V_7 -> V_65 )
F_34 ( V_7 -> V_65 ) ;
V_7 -> V_65 = NULL ;
if ( V_7 -> V_59 )
F_34 ( V_7 -> V_59 ) ;
V_7 -> V_59 = NULL ;
V_7 -> V_85 = 0 ;
#ifdef F_3
if ( V_7 -> V_13 )
F_34 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_12 = false ;
#endif
}
static inline int F_36 ( struct V_6 * V_7 )
{
int V_9 = - V_92 ;
unsigned int V_96 = 0 ;
if ( ! V_7 )
return - V_55 ;
V_7 -> V_64 = F_32 ( F_13 ( V_7 ) , V_91 ) ;
if ( ! V_7 -> V_64 )
goto V_97;
V_7 -> V_65 = F_32 ( F_13 ( V_7 ) , V_91 ) ;
if ( ! V_7 -> V_65 )
goto V_97;
#ifdef F_3
V_7 -> V_13 = F_32 ( F_4 ( V_7 ) , V_91 ) ;
if ( ! V_7 -> V_13 )
goto V_97;
V_7 -> V_12 = false ;
#endif
if ( V_7 -> V_90 -> V_1 & V_98 )
V_96 = 0 ;
else if ( V_7 -> V_90 -> V_1 & V_99 )
V_96 = F_13 ( V_7 ) + F_4 ( V_7 ) +
F_13 ( V_7 ) +
F_4 ( V_7 ) +
F_4 ( V_7 ) +
F_13 ( V_7 ) + F_4 ( V_7 ) ;
else
V_96 = F_13 ( V_7 ) + F_4 ( V_7 ) ;
if ( 0 < V_96 ) {
V_7 -> V_59 = F_32 ( V_96 , V_91 ) ;
if ( ! V_7 -> V_59 )
goto V_97;
}
F_37 ( & V_7 -> V_100 ) ;
return 0 ;
V_97:
F_35 ( V_7 ) ;
return V_9 ;
}
static inline void F_38 ( struct V_6 * V_82 ,
struct V_6 * V_18 )
{
if ( ! V_82 || ! V_18 )
return;
memcpy ( V_18 -> V_64 , V_82 -> V_64 , F_13 ( V_82 ) ) ;
memcpy ( V_18 -> V_65 , V_82 -> V_65 , F_13 ( V_82 ) ) ;
V_18 -> V_85 = V_82 -> V_85 ;
V_18 -> V_95 = V_82 -> V_95 ;
V_18 -> V_101 = V_82 -> V_101 ;
#ifdef F_3
V_18 -> V_12 = V_82 -> V_12 ;
memcpy ( V_18 -> V_13 , V_82 -> V_13 , F_4 ( V_82 ) ) ;
#endif
}
static int F_39 ( struct V_6 * V_7 , struct V_6 * * V_102 )
{
int V_9 = - V_92 ;
struct V_6 * V_77 = NULL ;
if ( ! V_7 || ! V_7 -> V_90 || ! V_7 -> V_64 || ! V_7 -> V_65 ) {
F_31 ( L_9
L_10 ) ;
return - V_55 ;
}
if ( ! ( V_7 -> V_90 -> V_1 & V_98 ) && NULL == V_7 -> V_59 )
return - V_55 ;
V_77 = F_32 ( sizeof( struct V_6 ) , V_91 ) ;
if ( ! V_77 )
return - V_92 ;
V_77 -> V_90 = V_7 -> V_90 ;
V_77 -> V_93 = V_7 -> V_93 ;
V_9 = F_36 ( V_77 ) ;
if ( V_9 )
goto V_97;
F_40 ( & V_7 -> V_100 ) ;
F_38 ( V_7 , V_77 ) ;
V_77 -> V_10 = V_7 -> V_10 ;
F_41 ( & V_7 -> V_100 ) ;
* V_102 = V_77 ;
return 0 ;
V_97:
if ( V_77 )
F_34 ( V_77 ) ;
return V_9 ;
}
static void F_42 ( struct V_6 * V_7 ,
struct V_6 * * V_102 )
{
struct V_6 * V_77 = * V_102 ;
F_40 ( & V_7 -> V_100 ) ;
F_38 ( V_77 , V_7 ) ;
F_41 ( & V_7 -> V_100 ) ;
F_35 ( V_77 ) ;
F_34 ( V_77 ) ;
* V_102 = NULL ;
}
static int F_43 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_15 ,
struct V_30 * V_66 )
{
int V_25 = 0 ;
struct V_6 * V_102 = NULL ;
F_12 ( V_103 ) ;
struct V_30 V_104 ;
union {
T_4 V_105 ;
unsigned char V_106 [ sizeof( T_4 ) ] ;
} V_107 ;
if ( 0 == V_15 || ! V_8 ) {
F_31 ( L_11 ) ;
return - V_55 ;
}
if ( V_66 && NULL == V_66 -> V_8 && 0 < V_66 -> V_25 ) {
F_31 ( L_12 ) ;
return - V_55 ;
}
V_25 = F_39 ( V_7 , & V_102 ) ;
if ( V_25 ) {
F_31 ( L_13 ) ;
return V_25 ;
}
V_25 = - V_55 ;
if ( V_15 > ( F_44 ( V_102 ) ) ) {
F_31 ( L_14 ,
V_15 ) ;
goto V_97;
}
if ( V_66 && V_66 -> V_25 > ( F_30 ( V_102 ) ) ) {
F_31 ( L_15 ,
V_66 -> V_25 ) ;
goto V_97;
}
if ( ( F_45 ( V_102 ) ) < V_102 -> V_85 )
V_102 -> V_95 = false ;
if ( V_102 -> V_93 -> V_108 ) {
V_25 = V_102 -> V_93 -> V_108 ( V_102 ) ;
if ( V_25 )
goto V_97;
}
if ( V_102 -> V_101 || ! V_102 -> V_95 ) {
F_31 ( L_16
L_17 ,
V_7 -> V_101 ? L_18 : L_19 ,
V_7 -> V_95 ? L_20 : L_21 ) ;
V_25 = F_29 ( V_102 , V_66 , true ) ;
if ( V_25 )
goto V_97;
V_66 = NULL ;
}
if ( ! V_7 -> V_10 ) {
V_107 . V_105 = F_46 () ;
F_8 ( & V_104 , V_107 . V_106 , sizeof( T_4 ) ) ;
F_14 ( & V_104 . V_56 , & V_103 ) ;
}
if ( V_66 && 0 < V_66 -> V_25 )
F_14 ( & V_66 -> V_56 , & V_103 ) ;
V_25 = V_102 -> V_93 -> V_109 ( V_102 , V_8 , V_15 , & V_103 ) ;
V_102 -> V_85 ++ ;
if ( 0 >= V_25 )
goto V_97;
#if 0
if (shadow->reseed_ctr && !(shadow->reseed_ctr % 4096)) {
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
drbg_dealloc_state(shadow);
kzfree(shadow);
return 0;
} else {
pr_devel("DRBG: self test successful\n");
}
}
#endif
V_97:
if ( V_102 -> V_93 -> V_110 )
V_102 -> V_93 -> V_110 ( V_102 ) ;
F_42 ( V_7 , & V_102 ) ;
return V_25 ;
}
static int F_47 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_15 ,
struct V_30 * V_66 )
{
int V_25 = 0 ;
unsigned int V_111 = 0 ;
do {
int V_112 = 0 ;
unsigned int V_113 = 0 ;
V_111 = ( ( V_15 - V_25 ) / F_44 ( V_7 ) ) ;
V_113 = V_111 ? F_44 ( V_7 ) : ( V_15 - V_25 ) ;
V_112 = F_43 ( V_7 , V_8 + V_25 , V_113 , V_66 ) ;
if ( 0 >= V_112 )
return V_112 ;
V_25 += V_112 ;
} while ( V_111 > 0 && ( V_25 < V_15 ) );
return V_25 ;
}
static int F_48 ( struct V_6 * V_7 , struct V_30 * V_86 ,
int V_114 , bool V_101 )
{
int V_9 = - V_92 ;
F_31 ( L_22
L_23 , V_114 , V_101 ? L_24 : L_25 ) ;
V_7 -> V_90 = & V_115 [ V_114 ] ;
V_7 -> V_101 = V_101 ;
V_7 -> V_95 = false ;
switch ( V_7 -> V_90 -> V_1 & V_116 ) {
#ifdef F_49
case V_98 :
V_7 -> V_93 = & V_117 ;
break;
#endif
#ifdef F_50
case V_118 :
V_7 -> V_93 = & V_119 ;
break;
#endif
#ifdef F_51
case V_99 :
V_7 -> V_93 = & V_120 ;
break;
#endif
default:
return - V_121 ;
}
V_9 = F_36 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = - V_38 ;
if ( V_7 -> V_93 -> V_108 && V_7 -> V_93 -> V_108 ( V_7 ) )
goto V_97;
V_9 = F_29 ( V_7 , V_86 , false ) ;
if ( V_7 -> V_93 -> V_110 )
V_7 -> V_93 -> V_110 ( V_7 ) ;
if ( V_9 )
goto V_97;
return 0 ;
V_97:
F_35 ( V_7 ) ;
return V_9 ;
}
static int F_52 ( struct V_6 * V_7 )
{
F_40 ( & V_7 -> V_100 ) ;
F_35 ( V_7 ) ;
F_41 ( & V_7 -> V_100 ) ;
return 0 ;
}
static inline void F_53 ( struct V_6 * V_7 ,
struct V_122 * V_10 )
{
if ( ! V_10 || ! V_10 -> V_89 )
return;
F_40 ( & V_7 -> V_100 ) ;
V_7 -> V_10 = V_10 ;
F_41 ( & V_7 -> V_100 ) ;
}
static int F_54 ( struct V_6 * V_7 )
{
struct V_123 * V_123 ;
struct V_124 * V_125 ;
V_125 = F_55 ( V_7 -> V_90 -> V_126 , 0 , 0 ) ;
if ( F_56 ( V_125 ) ) {
F_57 ( L_26 ) ;
return F_58 ( V_125 ) ;
}
F_59 ( F_4 ( V_7 ) != F_60 ( V_125 ) ) ;
V_123 = F_32 ( sizeof( struct V_127 ) + F_61 ( V_125 ) ,
V_91 ) ;
if ( ! V_123 ) {
F_62 ( V_125 ) ;
return - V_92 ;
}
V_123 -> V_128 . V_125 = V_125 ;
V_123 -> V_128 . V_1 = 0 ;
V_7 -> V_129 = V_123 ;
return 0 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_123 * V_123 = (struct V_123 * ) V_7 -> V_129 ;
if ( V_123 ) {
F_62 ( V_123 -> V_128 . V_125 ) ;
F_34 ( V_123 ) ;
}
V_7 -> V_129 = NULL ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 , const unsigned char * V_27 ,
unsigned char * V_74 , const struct V_28 * V_29 )
{
struct V_123 * V_123 = (struct V_123 * ) V_7 -> V_129 ;
struct V_30 * V_76 = NULL ;
if ( V_27 )
F_64 ( V_123 -> V_128 . V_125 , V_27 , F_13 ( V_7 ) ) ;
F_65 ( & V_123 -> V_128 ) ;
F_9 (input, in, list)
F_66 ( & V_123 -> V_128 , V_76 -> V_8 , V_76 -> V_25 ) ;
return F_67 ( & V_123 -> V_128 , V_74 ) ;
}
static int F_68 ( struct V_6 * V_7 )
{
int V_9 = 0 ;
struct V_130 * V_125 ;
V_125 = F_69 ( V_7 -> V_90 -> V_126 , 0 , 0 ) ;
if ( F_56 ( V_125 ) ) {
F_57 ( L_27 ) ;
return F_58 ( V_125 ) ;
}
F_59 ( F_4 ( V_7 ) != F_70 ( V_125 ) ) ;
V_7 -> V_129 = V_125 ;
return V_9 ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_130 * V_125 =
(struct V_130 * ) V_7 -> V_129 ;
if ( V_125 )
F_72 ( V_125 ) ;
V_7 -> V_129 = NULL ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , const unsigned char * V_27 ,
unsigned char * V_74 , const struct V_30 * V_29 )
{
int V_9 = 0 ;
struct V_131 V_132 , V_133 ;
struct V_134 V_135 ;
struct V_130 * V_125 =
(struct V_130 * ) V_7 -> V_129 ;
V_135 . V_125 = V_125 ;
V_135 . V_1 = 0 ;
F_73 ( V_125 , V_27 , ( F_16 ( V_7 ) ) ) ;
F_74 ( & V_132 , V_29 -> V_8 , V_29 -> V_25 ) ;
F_74 ( & V_133 , V_74 , F_4 ( V_7 ) ) ;
V_9 = F_75 ( & V_135 , & V_133 , & V_132 , V_29 -> V_25 ) ;
return V_9 ;
}
static inline void F_76 ( const char * V_136 ,
int * V_114 , bool * V_101 )
{
int V_17 = 0 ;
T_3 V_137 = 0 ;
int V_25 = 0 ;
* V_101 = true ;
if ( ! memcmp ( V_136 , L_28 , 10 ) ) {
V_137 = 10 ;
* V_101 = false ;
} else if ( ! memcmp ( V_136 , L_29 , 8 ) ) {
V_137 = 8 ;
} else {
return;
}
V_25 = strlen ( V_136 ) - V_137 ;
for ( V_17 = 0 ; F_77 ( V_115 ) > V_17 ; V_17 ++ ) {
if ( ! memcmp ( V_136 + V_137 , V_115 [ V_17 ] . V_138 ,
V_25 ) ) {
* V_114 = V_17 ;
return;
}
}
}
static int F_78 ( struct V_139 * V_125 )
{
struct V_6 * V_7 = F_79 ( V_125 ) ;
bool V_101 = false ;
int V_114 = 0 ;
F_76 ( F_80 ( V_125 ) , & V_114 , & V_101 ) ;
return F_48 ( V_7 , NULL , V_114 , V_101 ) ;
}
static void F_81 ( struct V_139 * V_125 )
{
F_52 ( F_79 ( V_125 ) ) ;
}
static int F_82 ( struct V_140 * V_125 , T_5 * V_141 ,
unsigned int V_142 )
{
struct V_6 * V_7 = F_83 ( V_125 ) ;
if ( 0 < V_142 ) {
return F_47 ( V_7 , V_141 , V_142 , NULL ) ;
} else {
struct V_143 * V_32 = (struct V_143 * ) V_141 ;
struct V_30 V_66 ;
if ( ! V_32 )
return 0 ;
F_53 ( V_7 , V_32 -> V_10 ) ;
F_8 ( & V_66 , V_32 -> V_66 -> V_8 , V_32 -> V_66 -> V_25 ) ;
return F_47 ( V_7 , V_32 -> V_144 , V_32 -> V_67 ,
& V_66 ) ;
}
}
static int F_84 ( struct V_140 * V_125 , T_5 * V_54 , unsigned int V_145 )
{
struct V_6 * V_7 = F_83 ( V_125 ) ;
struct V_139 * V_146 = F_85 ( V_125 ) ;
bool V_101 = false ;
struct V_30 V_147 ;
int V_114 = 0 ;
F_52 ( V_7 ) ;
F_76 ( F_80 ( V_146 ) , & V_114 ,
& V_101 ) ;
if ( 0 < V_145 ) {
F_8 ( & V_147 , V_54 , V_145 ) ;
return F_48 ( V_7 , & V_147 , V_114 , V_101 ) ;
} else {
struct V_143 * V_32 = (struct V_143 * ) V_54 ;
if ( ! V_32 )
return F_48 ( V_7 , NULL , V_114 , V_101 ) ;
F_53 ( V_7 , V_32 -> V_10 ) ;
F_8 ( & V_147 , V_32 -> V_66 -> V_8 ,
V_32 -> V_66 -> V_25 ) ;
return F_48 ( V_7 , & V_147 , V_114 , V_101 ) ;
}
}
static inline int T_6 F_86 ( void )
{
#ifdef F_3
int V_25 = 0 ;
#define F_87 16
unsigned char V_8 [ F_87 ] ;
struct V_6 * V_7 = NULL ;
int V_9 = - V_38 ;
int V_148 = - V_38 ;
bool V_101 = false ;
int V_114 = 0 ;
struct V_30 V_66 ;
T_3 V_149 , V_150 ;
if ( ! V_11 )
return 0 ;
#ifdef F_51
F_76 ( L_30 , & V_114 , & V_101 ) ;
#elif V_151 F_50
F_76 ( L_31 , & V_114 , & V_101 ) ;
#else
F_76 ( L_32 , & V_114 , & V_101 ) ;
#endif
V_7 = F_32 ( sizeof( struct V_6 ) , V_91 ) ;
if ( ! V_7 )
return - V_92 ;
V_9 = F_48 ( V_7 , NULL , V_114 , V_101 ) ;
if ( V_9 ) {
V_148 = V_9 ;
goto V_144;
}
V_149 = F_30 ( V_7 ) ;
V_150 = F_44 ( V_7 ) ;
F_8 ( & V_66 , V_8 , V_149 + 1 ) ;
V_25 = F_43 ( V_7 , V_8 , F_87 , & V_66 ) ;
F_59 ( 0 < V_25 ) ;
V_25 = F_43 ( V_7 , V_8 , ( V_150 + 1 ) , NULL ) ;
F_59 ( 0 < V_25 ) ;
F_52 ( V_7 ) ;
V_9 = F_48 ( V_7 , & V_66 , V_114 , V_101 ) ;
F_59 ( 0 == V_9 ) ;
V_148 = 0 ;
F_31 ( L_33
L_34 ) ;
F_52 ( V_7 ) ;
V_144:
F_34 ( V_7 ) ;
return V_148 ;
#else
return 0 ;
#endif
}
static inline void T_6 F_88 ( struct V_152 * V_153 ,
const struct V_154 * V_90 , int V_101 )
{
int V_34 = 0 ;
static int V_155 = 100 ;
memset ( V_153 , 0 , sizeof( struct V_152 ) ) ;
memcpy ( V_153 -> V_138 , L_35 , 6 ) ;
if ( V_101 ) {
memcpy ( V_153 -> V_136 , L_29 , 8 ) ;
V_34 = 8 ;
} else {
memcpy ( V_153 -> V_136 , L_28 , 10 ) ;
V_34 = 10 ;
}
memcpy ( V_153 -> V_136 + V_34 , V_90 -> V_138 ,
strlen ( V_90 -> V_138 ) ) ;
V_153 -> V_156 = V_155 ;
V_155 ++ ;
if ( V_11 )
V_153 -> V_156 += 200 ;
V_153 -> V_157 = V_158 ;
V_153 -> V_159 = sizeof( struct V_6 ) ;
V_153 -> V_160 = & V_161 ;
V_153 -> V_162 = V_163 ;
V_153 -> V_164 = F_78 ;
V_153 -> V_165 = F_81 ;
V_153 -> V_166 . V_167 . V_168 = F_82 ;
V_153 -> V_166 . V_167 . V_169 = F_84 ;
V_153 -> V_166 . V_167 . V_170 = 0 ;
}
static int T_6 F_89 ( void )
{
unsigned int V_17 = 0 ;
unsigned int V_171 = 0 ;
int V_9 = - V_38 ;
V_9 = F_86 () ;
if ( V_9 )
return V_9 ;
if ( F_77 ( V_115 ) * 2 > F_77 ( V_172 ) ) {
F_57 ( L_36
L_37 ,
F_77 ( V_115 ) * 2 , F_77 ( V_172 ) ) ;
return V_9 ;
}
for ( V_171 = 0 ; F_77 ( V_115 ) > V_171 ; V_171 ++ , V_17 ++ )
F_88 ( & V_172 [ V_17 ] , & V_115 [ V_171 ] , 1 ) ;
for ( V_171 = 0 ; F_77 ( V_115 ) > V_171 ; V_171 ++ , V_17 ++ )
F_88 ( & V_172 [ V_17 ] , & V_115 [ V_171 ] , 0 ) ;
return F_90 ( V_172 , ( F_77 ( V_115 ) * 2 ) ) ;
}
static void T_7 F_91 ( void )
{
F_92 ( V_172 , ( F_77 ( V_115 ) * 2 ) ) ;
}
