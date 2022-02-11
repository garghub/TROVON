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
static inline void F_5 ( T_2 V_14 , unsigned char * V_8 )
{
struct V_15 {
T_3 V_16 ;
};
struct V_15 * V_17 = (struct V_15 * ) V_8 ;
V_17 -> V_16 = F_6 ( V_14 ) ;
}
static inline void F_7 ( unsigned char * V_18 , T_4 V_19 ,
const unsigned char * V_20 , T_4 V_21 )
{
unsigned char * V_22 ;
const unsigned char * V_23 ;
unsigned int V_24 = 0 ;
T_4 V_25 = V_21 ;
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
static int F_8 ( struct V_6 * V_7 ,
unsigned char * V_26 , const unsigned char * V_27 ,
struct V_28 * V_29 )
{
int V_9 = 0 ;
struct V_30 * V_31 = NULL ;
struct V_30 V_32 ;
short V_33 = 0 ;
F_9 ( & V_32 , V_26 , F_4 ( V_7 ) ) ;
memset ( V_26 , 0 , F_4 ( V_7 ) ) ;
F_10 (curr, in, list) {
const unsigned char * V_34 = V_31 -> V_8 ;
T_4 V_25 = V_31 -> V_25 ;
while ( V_25 ) {
if ( F_4 ( V_7 ) == V_33 ) {
V_33 = 0 ;
V_9 = F_11 ( V_7 , V_27 , V_26 , & V_32 ) ;
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
V_9 = F_11 ( V_7 , V_27 , V_26 , & V_32 ) ;
return V_9 ;
}
static int F_12 ( struct V_6 * V_7 ,
unsigned char * V_35 , T_4 V_36 ,
struct V_28 * V_37 )
{
int V_9 = - V_38 ;
unsigned char V_39 [ 8 ] ;
struct V_30 V_40 , V_41 , V_42 , V_43 ;
F_13 ( V_44 ) ;
unsigned char * V_45 = V_35 + F_14 ( V_7 ) ;
unsigned char * V_46 = V_45 + F_4 ( V_7 ) ;
unsigned char * V_47 = V_46 + F_4 ( V_7 ) ;
T_4 V_48 = 0 ;
unsigned int V_49 = 0 ;
unsigned int V_50 = 0 ;
const unsigned char * V_51 = ( unsigned char * )
L_1
L_2
L_3
L_4 ;
unsigned char * V_52 ;
T_4 V_53 = 0 ;
T_4 V_54 = 0 ;
struct V_30 * V_55 = NULL ;
memset ( V_45 , 0 , F_4 ( V_7 ) ) ;
memset ( V_46 , 0 , F_4 ( V_7 ) ) ;
memset ( V_47 , 0 , F_14 ( V_7 ) ) ;
if ( ( 512 / 8 ) < V_36 )
return - V_56 ;
F_10 (seed, seedlist, list)
V_54 += V_55 -> V_25 ;
F_5 ( V_54 , & V_39 [ 0 ] ) ;
F_5 ( V_36 , & V_39 [ 4 ] ) ;
V_48 = ( V_54 + sizeof( V_39 ) + 1 ) % ( F_4 ( V_7 ) ) ;
if ( V_48 )
V_48 = F_4 ( V_7 ) - V_48 ;
V_48 ++ ;
V_45 [ 0 ] = 0x80 ;
F_9 ( & V_40 , V_46 , F_4 ( V_7 ) ) ;
F_15 ( & V_40 . V_57 , & V_44 ) ;
F_9 ( & V_41 , V_39 , sizeof( V_39 ) ) ;
F_15 ( & V_41 . V_57 , & V_44 ) ;
F_16 ( V_37 , & V_44 ) ;
F_9 ( & V_42 , V_45 , V_48 ) ;
F_15 ( & V_42 . V_57 , & V_44 ) ;
while ( V_49 < ( F_17 ( V_7 ) + ( F_4 ( V_7 ) ) ) ) {
F_5 ( V_50 , V_46 ) ;
V_9 = F_8 ( V_7 , V_47 + V_49 , V_51 , & V_44 ) ;
if ( V_9 )
goto V_26;
V_50 ++ ;
V_49 += F_4 ( V_7 ) ;
}
V_52 = V_47 + ( F_17 ( V_7 ) ) ;
F_9 ( & V_43 , V_52 , F_4 ( V_7 ) ) ;
while ( V_53 < V_36 ) {
short V_58 = 0 ;
V_9 = F_11 ( V_7 , V_47 , V_52 , & V_43 ) ;
if ( V_9 )
goto V_26;
V_58 = ( F_4 ( V_7 ) <
( V_36 - V_53 ) ) ?
F_4 ( V_7 ) :
( V_36 - V_53 ) ;
memcpy ( V_35 + V_53 , V_52 , V_58 ) ;
V_53 += V_58 ;
}
V_9 = 0 ;
V_26:
memset ( V_46 , 0 , F_4 ( V_7 ) ) ;
memset ( V_47 , 0 , F_14 ( V_7 ) ) ;
memset ( V_45 , 0 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_18 ( struct V_6 * V_7 , struct V_28 * V_55 ,
int V_59 )
{
int V_9 = - V_38 ;
unsigned char * V_47 = V_7 -> V_60 ;
unsigned char * V_35 = V_7 -> V_60 + F_14 ( V_7 ) +
F_4 ( V_7 ) ;
unsigned char * V_61 , * V_62 ;
unsigned int V_25 = 0 ;
struct V_30 V_43 ;
unsigned char V_63 = V_64 ;
memset ( V_47 , 0 , F_14 ( V_7 ) + F_4 ( V_7 ) ) ;
if ( 3 > V_59 )
memset ( V_35 , 0 , F_14 ( V_7 ) ) ;
if ( V_55 ) {
V_9 = F_12 ( V_7 , V_35 , F_14 ( V_7 ) , V_55 ) ;
if ( V_9 )
goto V_26;
}
F_9 ( & V_43 , V_7 -> V_65 , F_4 ( V_7 ) ) ;
while ( V_25 < ( F_14 ( V_7 ) ) ) {
F_7 ( V_7 -> V_65 , F_4 ( V_7 ) , & V_63 , 1 ) ;
V_9 = F_11 ( V_7 , V_7 -> V_66 , V_47 + V_25 , & V_43 ) ;
if ( V_9 )
goto V_26;
V_25 += F_4 ( V_7 ) ;
}
V_61 = V_47 ;
V_62 = V_35 ;
for ( V_25 = 0 ; V_25 < F_14 ( V_7 ) ; V_25 ++ ) {
* V_61 ^= * V_62 ;
V_62 ++ ; V_61 ++ ;
}
memcpy ( V_7 -> V_66 , V_47 , F_17 ( V_7 ) ) ;
memcpy ( V_7 -> V_65 , V_47 + F_17 ( V_7 ) , F_4 ( V_7 ) ) ;
V_9 = 0 ;
V_26:
memset ( V_47 , 0 , F_14 ( V_7 ) + F_4 ( V_7 ) ) ;
if ( 2 != V_59 )
memset ( V_35 , 0 , F_14 ( V_7 ) ) ;
return V_9 ;
}
static int F_19 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_67 ,
struct V_28 * V_68 )
{
int V_25 = 0 ;
int V_9 = 0 ;
struct V_30 V_32 ;
unsigned char V_63 = V_64 ;
memset ( V_7 -> V_60 , 0 , F_4 ( V_7 ) ) ;
if ( V_68 && ! F_20 ( V_68 ) ) {
V_9 = F_18 ( V_7 , V_68 , 2 ) ;
if ( V_9 )
return 0 ;
}
F_7 ( V_7 -> V_65 , F_4 ( V_7 ) , & V_63 , 1 ) ;
F_9 ( & V_32 , V_7 -> V_65 , F_4 ( V_7 ) ) ;
while ( V_25 < V_67 ) {
int V_69 = 0 ;
V_9 = F_11 ( V_7 , V_7 -> V_66 , V_7 -> V_60 , & V_32 ) ;
if ( V_9 ) {
V_25 = V_9 ;
goto V_26;
}
V_69 = ( F_4 ( V_7 ) < ( V_67 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_67 - V_25 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_60 ) ) {
F_7 ( V_7 -> V_65 , F_4 ( V_7 ) , & V_63 , 1 ) ;
continue;
}
memcpy ( V_8 + V_25 , V_7 -> V_60 , V_69 ) ;
V_25 += V_69 ;
if ( V_25 < V_67 )
F_7 ( V_7 -> V_65 , F_4 ( V_7 ) , & V_63 , 1 ) ;
}
V_9 = F_18 ( V_7 , NULL , 3 ) ;
if ( V_9 )
V_25 = V_9 ;
V_26:
memset ( V_7 -> V_60 , 0 , F_4 ( V_7 ) ) ;
return V_25 ;
}
static int F_21 ( struct V_6 * V_7 , struct V_28 * V_55 ,
int V_59 )
{
int V_9 = - V_38 ;
int V_50 = 0 ;
struct V_30 V_70 , V_71 , V_72 ;
F_13 ( V_37 ) ;
F_13 ( V_73 ) ;
if ( ! V_59 )
memset ( V_7 -> V_65 , 1 , F_14 ( V_7 ) ) ;
F_9 ( & V_70 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_15 ( & V_70 . V_57 , & V_37 ) ;
F_9 ( & V_71 , NULL , 1 ) ;
F_15 ( & V_71 . V_57 , & V_37 ) ;
if ( V_55 )
F_16 ( V_55 , & V_37 ) ;
F_9 ( & V_72 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_15 ( & V_72 . V_57 , & V_73 ) ;
for ( V_50 = 2 ; 0 < V_50 ; V_50 -- ) {
unsigned char V_63 = V_74 ;
if ( 1 == V_50 )
V_63 = V_64 ;
V_71 . V_8 = & V_63 ;
V_9 = F_22 ( V_7 , V_7 -> V_66 , V_7 -> V_66 , & V_37 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_22 ( V_7 , V_7 -> V_66 , V_7 -> V_65 , & V_73 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_55 )
return V_9 ;
}
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_67 ,
struct V_28 * V_68 )
{
int V_25 = 0 ;
int V_9 = 0 ;
struct V_30 V_32 ;
F_13 ( V_75 ) ;
if ( V_68 && ! F_20 ( V_68 ) ) {
V_9 = F_21 ( V_7 , V_68 , 1 ) ;
if ( V_9 )
return V_9 ;
}
F_9 ( & V_32 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_15 ( & V_32 . V_57 , & V_75 ) ;
while ( V_25 < V_67 ) {
unsigned int V_69 = 0 ;
V_9 = F_22 ( V_7 , V_7 -> V_66 , V_7 -> V_65 , & V_75 ) ;
if ( V_9 )
return V_9 ;
V_69 = ( F_4 ( V_7 ) < ( V_67 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_67 - V_25 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_65 ) )
continue;
memcpy ( V_8 + V_25 , V_7 -> V_65 , V_69 ) ;
V_25 += V_69 ;
}
if ( V_68 && ! F_20 ( V_68 ) )
V_9 = F_21 ( V_7 , V_68 , 1 ) ;
else
V_9 = F_21 ( V_7 , NULL , 1 ) ;
if ( V_9 )
return V_9 ;
return V_25 ;
}
static int F_24 ( struct V_6 * V_7 ,
unsigned char * V_76 , T_4 V_69 ,
struct V_28 * V_77 )
{
int V_9 = 0 ;
T_4 V_25 = 0 ;
unsigned char V_78 [ 5 ] ;
unsigned char * V_79 = V_7 -> V_60 + F_14 ( V_7 ) ;
struct V_30 V_32 ;
memset ( V_79 , 0 , F_4 ( V_7 ) ) ;
V_78 [ 0 ] = 1 ;
F_5 ( ( V_69 * 8 ) , & V_78 [ 1 ] ) ;
F_9 ( & V_32 , V_78 , 5 ) ;
F_25 ( & V_32 . V_57 , V_77 ) ;
while ( V_25 < V_69 ) {
short V_58 = 0 ;
V_9 = F_22 ( V_7 , NULL , V_79 , V_77 ) ;
if ( V_9 )
goto V_26;
V_78 [ 0 ] ++ ;
V_58 = ( F_4 ( V_7 ) < ( V_69 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_69 - V_25 ) ;
memcpy ( V_76 + V_25 , V_79 , V_58 ) ;
V_25 += V_58 ;
}
V_26:
memset ( V_79 , 0 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_26 ( struct V_6 * V_7 , struct V_28 * V_55 ,
int V_59 )
{
int V_9 = 0 ;
struct V_30 V_80 , V_81 ;
F_13 ( V_75 ) ;
F_13 ( V_82 ) ;
unsigned char * V_65 = V_7 -> V_60 ;
unsigned char V_63 = V_64 ;
memset ( V_7 -> V_60 , 0 , F_14 ( V_7 ) ) ;
if ( ! V_55 )
return - V_56 ;
if ( V_59 ) {
memcpy ( V_65 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_9 ( & V_80 , & V_63 , 1 ) ;
F_15 ( & V_80 . V_57 , & V_75 ) ;
F_9 ( & V_81 , V_65 , F_14 ( V_7 ) ) ;
F_15 ( & V_81 . V_57 , & V_75 ) ;
}
F_16 ( V_55 , & V_75 ) ;
V_9 = F_24 ( V_7 , V_7 -> V_65 , F_14 ( V_7 ) , & V_75 ) ;
if ( V_9 )
goto V_26;
V_63 = V_74 ;
F_9 ( & V_80 , & V_63 , 1 ) ;
F_15 ( & V_80 . V_57 , & V_82 ) ;
F_9 ( & V_81 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_15 ( & V_81 . V_57 , & V_82 ) ;
V_9 = F_24 ( V_7 , V_7 -> V_66 , F_14 ( V_7 ) , & V_82 ) ;
V_26:
memset ( V_7 -> V_60 , 0 , F_14 ( V_7 ) ) ;
return V_9 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_28 * V_68 )
{
int V_9 = 0 ;
struct V_30 V_80 , V_81 ;
F_13 ( V_75 ) ;
unsigned char V_63 = V_83 ;
memset ( V_7 -> V_60 , 0 , F_4 ( V_7 ) ) ;
if ( ! V_68 || F_20 ( V_68 ) )
return 0 ;
F_9 ( & V_80 , & V_63 , 1 ) ;
F_9 ( & V_81 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_15 ( & V_80 . V_57 , & V_75 ) ;
F_15 ( & V_81 . V_57 , & V_75 ) ;
F_16 ( V_68 , & V_75 ) ;
V_9 = F_22 ( V_7 , NULL , V_7 -> V_60 , & V_75 ) ;
if ( V_9 )
goto V_26;
F_7 ( V_7 -> V_65 , F_14 ( V_7 ) ,
V_7 -> V_60 , F_4 ( V_7 ) ) ;
V_26:
memset ( V_7 -> V_60 , 0 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_28 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_67 )
{
int V_25 = 0 ;
int V_9 = 0 ;
unsigned char * V_84 = V_7 -> V_60 ;
unsigned char * V_18 = V_7 -> V_60 + F_14 ( V_7 ) ;
struct V_30 V_32 ;
F_13 ( V_75 ) ;
unsigned char V_63 = V_64 ;
memset ( V_84 , 0 , F_14 ( V_7 ) ) ;
memset ( V_18 , 0 , F_4 ( V_7 ) ) ;
memcpy ( V_84 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_9 ( & V_32 , V_84 , F_14 ( V_7 ) ) ;
F_15 ( & V_32 . V_57 , & V_75 ) ;
while ( V_25 < V_67 ) {
unsigned int V_69 = 0 ;
V_9 = F_22 ( V_7 , NULL , V_18 , & V_75 ) ;
if ( V_9 ) {
V_25 = V_9 ;
goto V_26;
}
V_69 = ( F_4 ( V_7 ) < ( V_67 - V_25 ) ) ?
F_4 ( V_7 ) : ( V_67 - V_25 ) ;
if ( ! F_2 ( V_7 , V_18 ) ) {
F_7 ( V_84 , F_14 ( V_7 ) , & V_63 , 1 ) ;
continue;
}
memcpy ( V_8 + V_25 , V_18 , V_69 ) ;
V_25 += V_69 ;
if ( V_25 < V_67 )
F_7 ( V_84 , F_14 ( V_7 ) , & V_63 , 1 ) ;
}
V_26:
memset ( V_7 -> V_60 , 0 ,
( F_14 ( V_7 ) + F_4 ( V_7 ) ) ) ;
return V_25 ;
}
static int F_29 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_67 ,
struct V_28 * V_68 )
{
int V_25 = 0 ;
int V_9 = 0 ;
union {
unsigned char V_85 [ 8 ] ;
T_5 V_86 ;
} V_87 ;
unsigned char V_63 = V_88 ;
struct V_30 V_80 , V_81 ;
F_13 ( V_75 ) ;
V_9 = F_27 ( V_7 , V_68 ) ;
if ( V_9 )
return V_9 ;
V_25 = F_28 ( V_7 , V_8 , V_67 ) ;
memset ( V_7 -> V_60 , 0 , F_4 ( V_7 ) ) ;
F_9 ( & V_80 , & V_63 , 1 ) ;
F_15 ( & V_80 . V_57 , & V_75 ) ;
F_9 ( & V_81 , V_7 -> V_65 , F_14 ( V_7 ) ) ;
F_15 ( & V_81 . V_57 , & V_75 ) ;
V_9 = F_22 ( V_7 , NULL , V_7 -> V_60 , & V_75 ) ;
if ( V_9 ) {
V_25 = V_9 ;
goto V_26;
}
F_7 ( V_7 -> V_65 , F_14 ( V_7 ) ,
V_7 -> V_60 , F_4 ( V_7 ) ) ;
F_7 ( V_7 -> V_65 , F_14 ( V_7 ) ,
V_7 -> V_66 , F_14 ( V_7 ) ) ;
V_87 . V_86 = F_30 ( V_7 -> V_89 ) ;
F_7 ( V_7 -> V_65 , F_14 ( V_7 ) , V_87 . V_85 , 8 ) ;
V_26:
memset ( V_7 -> V_60 , 0 , F_4 ( V_7 ) ) ;
return V_25 ;
}
static int F_31 ( struct V_6 * V_7 , struct V_30 * V_90 ,
bool V_59 )
{
int V_9 = 0 ;
unsigned char * V_91 = NULL ;
T_4 V_92 = 0 ;
struct V_30 V_80 ;
F_13 ( V_37 ) ;
if ( V_90 && V_90 -> V_25 > ( F_32 ( V_7 ) ) ) {
F_33 ( L_5 ,
V_90 -> V_25 ) ;
return - V_56 ;
}
if ( V_7 -> V_10 && V_7 -> V_10 -> V_93 ) {
F_9 ( & V_80 , V_7 -> V_10 -> V_93 -> V_8 ,
V_7 -> V_10 -> V_93 -> V_25 ) ;
F_33 ( L_6 ) ;
} else {
V_92 = F_1 ( V_7 -> V_94 -> V_1 ) ;
if ( ! V_92 )
return - V_38 ;
if ( ! V_59 )
V_92 = ( ( V_92 + 1 ) / 2 ) * 3 ;
F_33 ( L_7 ,
V_92 ) ;
V_91 = F_34 ( V_92 , V_95 ) ;
if ( ! V_91 )
return - V_96 ;
F_35 ( V_91 , V_92 ) ;
F_9 ( & V_80 , V_91 , V_92 ) ;
}
F_15 ( & V_80 . V_57 , & V_37 ) ;
if ( V_90 && V_90 -> V_8 && 0 < V_90 -> V_25 ) {
F_15 ( & V_90 -> V_57 , & V_37 ) ;
F_33 ( L_8 ) ;
}
if ( ! V_59 ) {
memset ( V_7 -> V_65 , 0 , F_14 ( V_7 ) ) ;
memset ( V_7 -> V_66 , 0 , F_14 ( V_7 ) ) ;
}
V_9 = V_7 -> V_97 -> V_98 ( V_7 , & V_37 , V_59 ) ;
if ( V_9 )
goto V_26;
V_7 -> V_99 = true ;
V_7 -> V_89 = 1 ;
V_26:
F_36 ( V_91 ) ;
return V_9 ;
}
static inline void F_37 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_36 ( V_7 -> V_65 ) ;
V_7 -> V_65 = NULL ;
F_36 ( V_7 -> V_66 ) ;
V_7 -> V_66 = NULL ;
F_36 ( V_7 -> V_60 ) ;
V_7 -> V_60 = NULL ;
V_7 -> V_89 = 0 ;
#ifdef F_3
F_36 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_12 = false ;
#endif
}
static inline int F_38 ( struct V_6 * V_7 )
{
int V_9 = - V_96 ;
unsigned int V_100 = 0 ;
V_7 -> V_65 = F_39 ( F_14 ( V_7 ) , V_95 ) ;
if ( ! V_7 -> V_65 )
goto V_101;
V_7 -> V_66 = F_39 ( F_14 ( V_7 ) , V_95 ) ;
if ( ! V_7 -> V_66 )
goto V_101;
#ifdef F_3
V_7 -> V_13 = F_39 ( F_4 ( V_7 ) , V_95 ) ;
if ( ! V_7 -> V_13 )
goto V_101;
V_7 -> V_12 = false ;
#endif
if ( V_7 -> V_94 -> V_1 & V_102 )
V_100 = 0 ;
else if ( V_7 -> V_94 -> V_1 & V_103 )
V_100 = F_14 ( V_7 ) + F_4 ( V_7 ) +
F_14 ( V_7 ) +
F_4 ( V_7 ) +
F_4 ( V_7 ) +
F_14 ( V_7 ) + F_4 ( V_7 ) ;
else
V_100 = F_14 ( V_7 ) + F_4 ( V_7 ) ;
if ( 0 < V_100 ) {
V_7 -> V_60 = F_34 ( V_100 , V_95 ) ;
if ( ! V_7 -> V_60 )
goto V_101;
}
F_40 ( & V_7 -> V_104 ) ;
return 0 ;
V_101:
F_37 ( V_7 ) ;
return V_9 ;
}
static inline void F_41 ( struct V_6 * V_84 ,
struct V_6 * V_18 )
{
if ( ! V_84 || ! V_18 )
return;
memcpy ( V_18 -> V_65 , V_84 -> V_65 , F_14 ( V_84 ) ) ;
memcpy ( V_18 -> V_66 , V_84 -> V_66 , F_14 ( V_84 ) ) ;
V_18 -> V_89 = V_84 -> V_89 ;
V_18 -> V_99 = V_84 -> V_99 ;
V_18 -> V_105 = V_84 -> V_105 ;
#ifdef F_3
V_18 -> V_12 = V_84 -> V_12 ;
memcpy ( V_18 -> V_13 , V_84 -> V_13 , F_4 ( V_84 ) ) ;
#endif
}
static int F_42 ( struct V_6 * V_7 , struct V_6 * * V_106 )
{
int V_9 = - V_96 ;
struct V_6 * V_79 = NULL ;
V_79 = F_34 ( sizeof( struct V_6 ) , V_95 ) ;
if ( ! V_79 )
return - V_96 ;
V_79 -> V_94 = V_7 -> V_94 ;
V_79 -> V_97 = V_7 -> V_97 ;
V_9 = F_38 ( V_79 ) ;
if ( V_9 )
goto V_101;
F_43 ( & V_7 -> V_104 ) ;
F_41 ( V_7 , V_79 ) ;
V_79 -> V_10 = V_7 -> V_10 ;
F_44 ( & V_7 -> V_104 ) ;
* V_106 = V_79 ;
return 0 ;
V_101:
F_36 ( V_79 ) ;
return V_9 ;
}
static void F_45 ( struct V_6 * V_7 ,
struct V_6 * * V_106 )
{
struct V_6 * V_79 = * V_106 ;
F_43 ( & V_7 -> V_104 ) ;
F_41 ( V_79 , V_7 ) ;
F_44 ( & V_7 -> V_104 ) ;
F_37 ( V_79 ) ;
F_36 ( V_79 ) ;
* V_106 = NULL ;
}
static int F_46 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_67 ,
struct V_30 * V_68 )
{
int V_25 = 0 ;
struct V_6 * V_106 = NULL ;
F_13 ( V_107 ) ;
struct V_30 V_108 ;
union {
T_6 V_109 ;
unsigned char V_110 [ sizeof( T_6 ) ] ;
} V_111 ;
if ( 0 == V_67 || ! V_8 ) {
F_33 ( L_9 ) ;
return - V_56 ;
}
if ( V_68 && NULL == V_68 -> V_8 && 0 < V_68 -> V_25 ) {
F_33 ( L_10 ) ;
return - V_56 ;
}
V_25 = F_42 ( V_7 , & V_106 ) ;
if ( V_25 ) {
F_33 ( L_11 ) ;
return V_25 ;
}
V_25 = - V_56 ;
if ( V_67 > ( F_47 ( V_106 ) ) ) {
F_33 ( L_12 ,
V_67 ) ;
goto V_101;
}
if ( V_68 && V_68 -> V_25 > ( F_32 ( V_106 ) ) ) {
F_33 ( L_13 ,
V_68 -> V_25 ) ;
goto V_101;
}
if ( ( F_48 ( V_106 ) ) < V_106 -> V_89 )
V_106 -> V_99 = false ;
V_25 = V_106 -> V_97 -> V_112 ( V_106 ) ;
if ( V_25 )
goto V_101;
if ( V_106 -> V_105 || ! V_106 -> V_99 ) {
F_33 ( L_14
L_15 ,
V_7 -> V_105 ? L_16 : L_17 ,
V_7 -> V_99 ? L_18 : L_19 ) ;
V_25 = F_31 ( V_106 , V_68 , true ) ;
if ( V_25 )
goto V_101;
V_68 = NULL ;
}
if ( ! V_7 -> V_10 ) {
V_111 . V_109 = F_49 () ;
F_9 ( & V_108 , V_111 . V_110 , sizeof( T_6 ) ) ;
F_15 ( & V_108 . V_57 , & V_107 ) ;
}
if ( V_68 && 0 < V_68 -> V_25 )
F_15 ( & V_68 -> V_57 , & V_107 ) ;
V_25 = V_106 -> V_97 -> V_113 ( V_106 , V_8 , V_67 , & V_107 ) ;
V_106 -> V_89 ++ ;
if ( 0 >= V_25 )
goto V_101;
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
V_101:
V_106 -> V_97 -> V_114 ( V_106 ) ;
F_45 ( V_7 , & V_106 ) ;
return V_25 ;
}
static int F_50 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_67 ,
struct V_30 * V_68 )
{
int V_25 = 0 ;
unsigned int V_115 = 0 ;
do {
int V_116 = 0 ;
unsigned int V_117 = 0 ;
V_115 = ( ( V_67 - V_25 ) / F_47 ( V_7 ) ) ;
V_117 = V_115 ? F_47 ( V_7 ) : ( V_67 - V_25 ) ;
V_116 = F_46 ( V_7 , V_8 + V_25 , V_117 , V_68 ) ;
if ( 0 >= V_116 )
return V_116 ;
V_25 += V_116 ;
} while ( V_115 > 0 && ( V_25 < V_67 ) );
return V_25 ;
}
static int F_51 ( struct V_6 * V_7 , struct V_30 * V_90 ,
int V_118 , bool V_105 )
{
int V_9 = - V_96 ;
F_33 ( L_20
L_21 , V_118 , V_105 ? L_22 : L_23 ) ;
V_7 -> V_94 = & V_119 [ V_118 ] ;
V_7 -> V_105 = V_105 ;
V_7 -> V_99 = false ;
switch ( V_7 -> V_94 -> V_1 & V_120 ) {
#ifdef F_52
case V_102 :
V_7 -> V_97 = & V_121 ;
break;
#endif
#ifdef F_53
case V_122 :
V_7 -> V_97 = & V_123 ;
break;
#endif
#ifdef F_54
case V_103 :
V_7 -> V_97 = & V_124 ;
break;
#endif
default:
return - V_125 ;
}
V_9 = F_38 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = - V_38 ;
if ( V_7 -> V_97 -> V_112 ( V_7 ) )
goto V_101;
V_9 = F_31 ( V_7 , V_90 , false ) ;
V_7 -> V_97 -> V_114 ( V_7 ) ;
if ( V_9 )
goto V_101;
return 0 ;
V_101:
F_37 ( V_7 ) ;
return V_9 ;
}
static int F_55 ( struct V_6 * V_7 )
{
F_43 ( & V_7 -> V_104 ) ;
F_37 ( V_7 ) ;
F_44 ( & V_7 -> V_104 ) ;
return 0 ;
}
static inline void F_56 ( struct V_6 * V_7 ,
struct V_126 * V_10 )
{
if ( ! V_10 || ! V_10 -> V_93 )
return;
F_43 ( & V_7 -> V_104 ) ;
V_7 -> V_10 = V_10 ;
F_44 ( & V_7 -> V_104 ) ;
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_127 * V_127 ;
struct V_128 * V_129 ;
V_129 = F_58 ( V_7 -> V_94 -> V_130 , 0 , 0 ) ;
if ( F_59 ( V_129 ) ) {
F_60 ( L_24 ) ;
return F_61 ( V_129 ) ;
}
F_62 ( F_4 ( V_7 ) != F_63 ( V_129 ) ) ;
V_127 = F_34 ( sizeof( struct V_131 ) + F_64 ( V_129 ) ,
V_95 ) ;
if ( ! V_127 ) {
F_65 ( V_129 ) ;
return - V_96 ;
}
V_127 -> V_132 . V_129 = V_129 ;
V_127 -> V_132 . V_1 = 0 ;
V_7 -> V_133 = V_127 ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_127 * V_127 = (struct V_127 * ) V_7 -> V_133 ;
if ( V_127 ) {
F_65 ( V_127 -> V_132 . V_129 ) ;
F_36 ( V_127 ) ;
}
V_7 -> V_133 = NULL ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 , const unsigned char * V_27 ,
unsigned char * V_76 , const struct V_28 * V_29 )
{
struct V_127 * V_127 = (struct V_127 * ) V_7 -> V_133 ;
struct V_30 * V_78 = NULL ;
if ( V_27 )
F_67 ( V_127 -> V_132 . V_129 , V_27 , F_14 ( V_7 ) ) ;
F_68 ( & V_127 -> V_132 ) ;
F_10 (input, in, list)
F_69 ( & V_127 -> V_132 , V_78 -> V_8 , V_78 -> V_25 ) ;
return F_70 ( & V_127 -> V_132 , V_76 ) ;
}
static int F_71 ( struct V_6 * V_7 )
{
int V_9 = 0 ;
struct V_134 * V_129 ;
V_129 = F_72 ( V_7 -> V_94 -> V_130 , 0 , 0 ) ;
if ( F_59 ( V_129 ) ) {
F_60 ( L_25 ) ;
return F_61 ( V_129 ) ;
}
F_62 ( F_4 ( V_7 ) != F_73 ( V_129 ) ) ;
V_7 -> V_133 = V_129 ;
return V_9 ;
}
static int F_74 ( struct V_6 * V_7 )
{
struct V_134 * V_129 =
(struct V_134 * ) V_7 -> V_133 ;
if ( V_129 )
F_75 ( V_129 ) ;
V_7 -> V_133 = NULL ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , const unsigned char * V_27 ,
unsigned char * V_76 , const struct V_30 * V_29 )
{
int V_9 = 0 ;
struct V_135 V_136 , V_137 ;
struct V_138 V_139 ;
struct V_134 * V_129 =
(struct V_134 * ) V_7 -> V_133 ;
V_139 . V_129 = V_129 ;
V_139 . V_1 = 0 ;
F_76 ( V_129 , V_27 , ( F_17 ( V_7 ) ) ) ;
F_77 ( & V_136 , V_29 -> V_8 , V_29 -> V_25 ) ;
F_77 ( & V_137 , V_76 , F_4 ( V_7 ) ) ;
V_9 = F_78 ( & V_139 , & V_137 , & V_136 , V_29 -> V_25 ) ;
return V_9 ;
}
static inline void F_79 ( const char * V_140 ,
int * V_118 , bool * V_105 )
{
int V_50 = 0 ;
T_4 V_141 = 0 ;
int V_25 = 0 ;
* V_105 = true ;
if ( ! memcmp ( V_140 , L_26 , 10 ) ) {
V_141 = 10 ;
* V_105 = false ;
} else if ( ! memcmp ( V_140 , L_27 , 8 ) ) {
V_141 = 8 ;
} else {
return;
}
V_25 = strlen ( V_140 ) - V_141 ;
for ( V_50 = 0 ; F_80 ( V_119 ) > V_50 ; V_50 ++ ) {
if ( ! memcmp ( V_140 + V_141 , V_119 [ V_50 ] . V_142 ,
V_25 ) ) {
* V_118 = V_50 ;
return;
}
}
}
static int F_81 ( struct V_143 * V_129 )
{
struct V_6 * V_7 = F_82 ( V_129 ) ;
bool V_105 = false ;
int V_118 = 0 ;
F_79 ( F_83 ( V_129 ) , & V_118 , & V_105 ) ;
return F_51 ( V_7 , NULL , V_118 , V_105 ) ;
}
static void F_84 ( struct V_143 * V_129 )
{
F_55 ( F_82 ( V_129 ) ) ;
}
static int F_85 ( struct V_144 * V_129 , T_7 * V_145 ,
unsigned int V_146 )
{
struct V_6 * V_7 = F_86 ( V_129 ) ;
if ( 0 < V_146 ) {
return F_50 ( V_7 , V_145 , V_146 , NULL ) ;
} else {
struct V_147 * V_32 = (struct V_147 * ) V_145 ;
struct V_30 V_68 ;
if ( ! V_32 )
return 0 ;
F_56 ( V_7 , V_32 -> V_10 ) ;
F_9 ( & V_68 , V_32 -> V_68 -> V_8 , V_32 -> V_68 -> V_25 ) ;
return F_50 ( V_7 , V_32 -> V_148 , V_32 -> V_69 ,
& V_68 ) ;
}
}
static int F_87 ( struct V_144 * V_129 , T_7 * V_55 , unsigned int V_149 )
{
struct V_6 * V_7 = F_86 ( V_129 ) ;
struct V_143 * V_150 = F_88 ( V_129 ) ;
bool V_105 = false ;
struct V_30 V_151 ;
int V_118 = 0 ;
F_55 ( V_7 ) ;
F_79 ( F_83 ( V_150 ) , & V_118 ,
& V_105 ) ;
if ( 0 < V_149 ) {
F_9 ( & V_151 , V_55 , V_149 ) ;
return F_51 ( V_7 , & V_151 , V_118 , V_105 ) ;
} else {
struct V_147 * V_32 = (struct V_147 * ) V_55 ;
if ( ! V_32 )
return F_51 ( V_7 , NULL , V_118 , V_105 ) ;
F_56 ( V_7 , V_32 -> V_10 ) ;
F_9 ( & V_151 , V_32 -> V_68 -> V_8 ,
V_32 -> V_68 -> V_25 ) ;
return F_51 ( V_7 , & V_151 , V_118 , V_105 ) ;
}
}
static inline int T_8 F_89 ( void )
{
#ifdef F_3
int V_25 = 0 ;
#define F_90 16
unsigned char V_8 [ F_90 ] ;
struct V_6 * V_7 = NULL ;
int V_9 = - V_38 ;
int V_152 = - V_38 ;
bool V_105 = false ;
int V_118 = 0 ;
struct V_30 V_68 ;
T_4 V_153 , V_154 ;
if ( ! V_11 )
return 0 ;
#ifdef F_54
F_79 ( L_28 , & V_118 , & V_105 ) ;
#elif V_155 F_53
F_79 ( L_29 , & V_118 , & V_105 ) ;
#else
F_79 ( L_30 , & V_118 , & V_105 ) ;
#endif
V_7 = F_34 ( sizeof( struct V_6 ) , V_95 ) ;
if ( ! V_7 )
return - V_96 ;
V_9 = F_51 ( V_7 , NULL , V_118 , V_105 ) ;
if ( V_9 ) {
V_152 = V_9 ;
goto V_148;
}
V_153 = F_32 ( V_7 ) ;
V_154 = F_47 ( V_7 ) ;
F_9 ( & V_68 , V_8 , V_153 + 1 ) ;
V_25 = F_46 ( V_7 , V_8 , F_90 , & V_68 ) ;
F_62 ( 0 < V_25 ) ;
V_25 = F_46 ( V_7 , V_8 , ( V_154 + 1 ) , NULL ) ;
F_62 ( 0 < V_25 ) ;
F_55 ( V_7 ) ;
V_9 = F_51 ( V_7 , & V_68 , V_118 , V_105 ) ;
F_62 ( 0 == V_9 ) ;
V_152 = 0 ;
F_33 ( L_31
L_32 ) ;
F_55 ( V_7 ) ;
V_148:
F_36 ( V_7 ) ;
return V_152 ;
#else
return 0 ;
#endif
}
static inline void T_8 F_91 ( struct V_156 * V_157 ,
const struct V_158 * V_94 , int V_105 )
{
int V_34 = 0 ;
static int V_159 = 100 ;
memset ( V_157 , 0 , sizeof( struct V_156 ) ) ;
memcpy ( V_157 -> V_142 , L_33 , 6 ) ;
if ( V_105 ) {
memcpy ( V_157 -> V_140 , L_27 , 8 ) ;
V_34 = 8 ;
} else {
memcpy ( V_157 -> V_140 , L_26 , 10 ) ;
V_34 = 10 ;
}
memcpy ( V_157 -> V_140 + V_34 , V_94 -> V_142 ,
strlen ( V_94 -> V_142 ) ) ;
V_157 -> V_160 = V_159 ;
V_159 ++ ;
if ( V_11 )
V_157 -> V_160 += 200 ;
V_157 -> V_161 = V_162 ;
V_157 -> V_163 = sizeof( struct V_6 ) ;
V_157 -> V_164 = & V_165 ;
V_157 -> V_166 = V_167 ;
V_157 -> V_168 = F_81 ;
V_157 -> V_169 = F_84 ;
V_157 -> V_170 . V_171 . V_172 = F_85 ;
V_157 -> V_170 . V_171 . V_173 = F_87 ;
V_157 -> V_170 . V_171 . V_174 = 0 ;
}
static int T_8 F_92 ( void )
{
unsigned int V_50 = 0 ;
unsigned int V_175 = 0 ;
int V_9 = - V_38 ;
V_9 = F_89 () ;
if ( V_9 )
return V_9 ;
if ( F_80 ( V_119 ) * 2 > F_80 ( V_176 ) ) {
F_60 ( L_34
L_35 ,
F_80 ( V_119 ) * 2 , F_80 ( V_176 ) ) ;
return V_9 ;
}
for ( V_175 = 0 ; F_80 ( V_119 ) > V_175 ; V_175 ++ , V_50 ++ )
F_91 ( & V_176 [ V_50 ] , & V_119 [ V_175 ] , 1 ) ;
for ( V_175 = 0 ; F_80 ( V_119 ) > V_175 ; V_175 ++ , V_50 ++ )
F_91 ( & V_176 [ V_50 ] , & V_119 [ V_175 ] , 0 ) ;
return F_93 ( V_176 , ( F_80 ( V_119 ) * 2 ) ) ;
}
static void T_9 F_94 ( void )
{
F_95 ( V_176 , ( F_80 ( V_119 ) * 2 ) ) ;
}
