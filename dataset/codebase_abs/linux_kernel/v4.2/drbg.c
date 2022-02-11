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
if ( F_4 ( & V_7 -> V_10 . V_11 ) )
return true ;
if ( 0 == V_12 )
return true ;
if ( ! V_7 -> V_13 ) {
memcpy ( V_7 -> V_14 , V_8 , F_5 ( V_7 ) ) ;
V_7 -> V_13 = true ;
return false ;
}
V_9 = memcmp ( V_7 -> V_14 , V_8 , F_5 ( V_7 ) ) ;
if ( ! V_9 )
F_6 ( L_1 ) ;
memcpy ( V_7 -> V_14 , V_8 , F_5 ( V_7 ) ) ;
return V_9 != 0 ;
#else
return true ;
#endif
}
static inline void F_7 ( T_2 V_15 , unsigned char * V_8 )
{
struct V_16 {
T_3 V_17 ;
};
struct V_16 * V_18 = (struct V_16 * ) V_8 ;
V_18 -> V_17 = F_8 ( V_15 ) ;
}
static int F_9 ( struct V_6 * V_7 ,
unsigned char * V_19 , const unsigned char * V_20 ,
struct V_21 * V_22 )
{
int V_9 = 0 ;
struct V_23 * V_24 = NULL ;
struct V_23 V_25 ;
short V_26 = 0 ;
F_10 ( & V_25 , V_19 , F_5 ( V_7 ) ) ;
F_11 (curr, in, list) {
const unsigned char * V_27 = V_24 -> V_8 ;
T_4 V_28 = V_24 -> V_28 ;
while ( V_28 ) {
if ( F_5 ( V_7 ) == V_26 ) {
V_26 = 0 ;
V_9 = F_12 ( V_7 , V_20 , V_19 , & V_25 ) ;
if ( V_9 )
return V_9 ;
}
V_19 [ V_26 ] ^= * V_27 ;
V_27 ++ ;
V_26 ++ ;
V_28 -- ;
}
}
if ( V_26 )
V_9 = F_12 ( V_7 , V_20 , V_19 , & V_25 ) ;
return V_9 ;
}
static int F_13 ( struct V_6 * V_7 ,
unsigned char * V_29 , T_4 V_30 ,
struct V_21 * V_31 )
{
int V_9 = - V_32 ;
unsigned char V_33 [ 8 ] ;
struct V_23 V_34 , V_35 , V_36 , V_37 ;
F_14 ( V_38 ) ;
unsigned char * V_39 = V_29 + F_15 ( V_7 ) ;
unsigned char * V_40 = V_39 + F_5 ( V_7 ) ;
unsigned char * V_41 = V_40 + F_5 ( V_7 ) ;
T_4 V_42 = 0 ;
unsigned int V_43 = 0 ;
unsigned int V_44 = 0 ;
const unsigned char * V_45 = ( unsigned char * )
L_2
L_3
L_4
L_5 ;
unsigned char * V_46 ;
T_4 V_47 = 0 ;
T_4 V_48 = 0 ;
struct V_23 * V_49 = NULL ;
memset ( V_39 , 0 , F_5 ( V_7 ) ) ;
memset ( V_40 , 0 , F_5 ( V_7 ) ) ;
if ( ( 512 / 8 ) < V_30 )
return - V_50 ;
F_11 (seed, seedlist, list)
V_48 += V_49 -> V_28 ;
F_7 ( V_48 , & V_33 [ 0 ] ) ;
F_7 ( V_30 , & V_33 [ 4 ] ) ;
V_42 = ( V_48 + sizeof( V_33 ) + 1 ) % ( F_5 ( V_7 ) ) ;
if ( V_42 )
V_42 = F_5 ( V_7 ) - V_42 ;
V_42 ++ ;
V_39 [ 0 ] = 0x80 ;
F_10 ( & V_34 , V_40 , F_5 ( V_7 ) ) ;
F_16 ( & V_34 . V_11 , & V_38 ) ;
F_10 ( & V_35 , V_33 , sizeof( V_33 ) ) ;
F_16 ( & V_35 . V_11 , & V_38 ) ;
F_17 ( V_31 , & V_38 ) ;
F_10 ( & V_36 , V_39 , V_42 ) ;
F_16 ( & V_36 . V_11 , & V_38 ) ;
while ( V_43 < ( F_18 ( V_7 ) + ( F_5 ( V_7 ) ) ) ) {
F_7 ( V_44 , V_40 ) ;
V_9 = F_9 ( V_7 , V_41 + V_43 , V_45 , & V_38 ) ;
if ( V_9 )
goto V_19;
V_44 ++ ;
V_43 += F_5 ( V_7 ) ;
}
V_46 = V_41 + ( F_18 ( V_7 ) ) ;
F_10 ( & V_37 , V_46 , F_5 ( V_7 ) ) ;
while ( V_47 < V_30 ) {
short V_51 = 0 ;
V_9 = F_12 ( V_7 , V_41 , V_46 , & V_37 ) ;
if ( V_9 )
goto V_19;
V_51 = ( F_5 ( V_7 ) <
( V_30 - V_47 ) ) ?
F_5 ( V_7 ) :
( V_30 - V_47 ) ;
memcpy ( V_29 + V_47 , V_46 , V_51 ) ;
V_47 += V_51 ;
}
V_9 = 0 ;
V_19:
memset ( V_40 , 0 , F_5 ( V_7 ) ) ;
memset ( V_41 , 0 , F_15 ( V_7 ) + F_5 ( V_7 ) ) ;
memset ( V_39 , 0 , F_5 ( V_7 ) ) ;
return V_9 ;
}
static int F_19 ( struct V_6 * V_7 , struct V_21 * V_49 ,
int V_52 )
{
int V_9 = - V_32 ;
unsigned char * V_41 = V_7 -> V_53 ;
unsigned char * V_29 = V_7 -> V_53 + F_15 ( V_7 ) +
F_5 ( V_7 ) ;
unsigned char * V_54 , * V_55 ;
unsigned int V_28 = 0 ;
struct V_23 V_37 ;
if ( 3 > V_52 )
memset ( V_29 , 0 , F_15 ( V_7 ) ) ;
if ( V_49 ) {
V_9 = F_13 ( V_7 , V_29 , F_15 ( V_7 ) , V_49 ) ;
if ( V_9 )
goto V_19;
}
F_10 ( & V_37 , V_7 -> V_56 , F_5 ( V_7 ) ) ;
while ( V_28 < ( F_15 ( V_7 ) ) ) {
F_20 ( V_7 -> V_56 , F_5 ( V_7 ) ) ;
V_9 = F_12 ( V_7 , V_7 -> V_57 , V_41 + V_28 , & V_37 ) ;
if ( V_9 )
goto V_19;
V_28 += F_5 ( V_7 ) ;
}
V_54 = V_41 ;
V_55 = V_29 ;
for ( V_28 = 0 ; V_28 < F_15 ( V_7 ) ; V_28 ++ ) {
* V_54 ^= * V_55 ;
V_55 ++ ; V_54 ++ ;
}
memcpy ( V_7 -> V_57 , V_41 , F_18 ( V_7 ) ) ;
memcpy ( V_7 -> V_56 , V_41 + F_18 ( V_7 ) , F_5 ( V_7 ) ) ;
V_9 = 0 ;
V_19:
memset ( V_41 , 0 , F_15 ( V_7 ) + F_5 ( V_7 ) ) ;
if ( 2 != V_52 )
memset ( V_29 , 0 , F_15 ( V_7 ) ) ;
return V_9 ;
}
static int F_21 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_21 * V_59 )
{
int V_28 = 0 ;
int V_9 = 0 ;
struct V_23 V_25 ;
if ( V_59 && ! F_4 ( V_59 ) ) {
V_9 = F_19 ( V_7 , V_59 , 2 ) ;
if ( V_9 )
return 0 ;
}
F_20 ( V_7 -> V_56 , F_5 ( V_7 ) ) ;
F_10 ( & V_25 , V_7 -> V_56 , F_5 ( V_7 ) ) ;
while ( V_28 < V_58 ) {
int V_60 = 0 ;
V_9 = F_12 ( V_7 , V_7 -> V_57 , V_7 -> V_53 , & V_25 ) ;
if ( V_9 ) {
V_28 = V_9 ;
goto V_19;
}
V_60 = ( F_5 ( V_7 ) < ( V_58 - V_28 ) ) ?
F_5 ( V_7 ) : ( V_58 - V_28 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_53 ) ) {
F_20 ( V_7 -> V_56 , F_5 ( V_7 ) ) ;
continue;
}
memcpy ( V_8 + V_28 , V_7 -> V_53 , V_60 ) ;
V_28 += V_60 ;
if ( V_28 < V_58 )
F_20 ( V_7 -> V_56 , F_5 ( V_7 ) ) ;
}
V_9 = F_19 ( V_7 , NULL , 3 ) ;
if ( V_9 )
V_28 = V_9 ;
V_19:
memset ( V_7 -> V_53 , 0 , F_5 ( V_7 ) ) ;
return V_28 ;
}
static int F_22 ( struct V_6 * V_7 , struct V_21 * V_49 ,
int V_52 )
{
int V_9 = - V_32 ;
int V_44 = 0 ;
struct V_23 V_61 , V_62 , V_63 ;
F_14 ( V_31 ) ;
F_14 ( V_64 ) ;
if ( ! V_52 )
memset ( V_7 -> V_56 , 1 , F_15 ( V_7 ) ) ;
F_10 ( & V_61 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_16 ( & V_61 . V_11 , & V_31 ) ;
F_10 ( & V_62 , NULL , 1 ) ;
F_16 ( & V_62 . V_11 , & V_31 ) ;
if ( V_49 )
F_17 ( V_49 , & V_31 ) ;
F_10 ( & V_63 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_16 ( & V_63 . V_11 , & V_64 ) ;
for ( V_44 = 2 ; 0 < V_44 ; V_44 -- ) {
unsigned char V_65 = V_66 ;
if ( 1 == V_44 )
V_65 = V_67 ;
V_62 . V_8 = & V_65 ;
V_9 = F_23 ( V_7 , V_7 -> V_57 , V_7 -> V_57 , & V_31 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_23 ( V_7 , V_7 -> V_57 , V_7 -> V_56 , & V_64 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_49 )
return V_9 ;
}
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_58 ,
struct V_21 * V_59 )
{
int V_28 = 0 ;
int V_9 = 0 ;
struct V_23 V_25 ;
F_14 ( V_68 ) ;
if ( V_59 && ! F_4 ( V_59 ) ) {
V_9 = F_22 ( V_7 , V_59 , 1 ) ;
if ( V_9 )
return V_9 ;
}
F_10 ( & V_25 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_16 ( & V_25 . V_11 , & V_68 ) ;
while ( V_28 < V_58 ) {
unsigned int V_60 = 0 ;
V_9 = F_23 ( V_7 , V_7 -> V_57 , V_7 -> V_56 , & V_68 ) ;
if ( V_9 )
return V_9 ;
V_60 = ( F_5 ( V_7 ) < ( V_58 - V_28 ) ) ?
F_5 ( V_7 ) : ( V_58 - V_28 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_56 ) )
continue;
memcpy ( V_8 + V_28 , V_7 -> V_56 , V_60 ) ;
V_28 += V_60 ;
}
if ( V_59 && ! F_4 ( V_59 ) )
V_9 = F_22 ( V_7 , V_59 , 1 ) ;
else
V_9 = F_22 ( V_7 , NULL , 1 ) ;
if ( V_9 )
return V_9 ;
return V_28 ;
}
static inline void F_25 ( unsigned char * V_69 , T_4 V_70 ,
const unsigned char * V_71 , T_4 V_72 )
{
unsigned char * V_73 ;
const unsigned char * V_74 ;
unsigned int V_75 = 0 ;
T_4 V_28 = V_72 ;
V_73 = V_69 + ( V_70 - 1 ) ;
V_74 = V_71 + ( V_72 - 1 ) ;
while ( V_28 ) {
V_75 += * V_73 + * V_74 ;
* V_73 = V_75 & 0xff ;
V_75 >>= 8 ;
V_28 -- ; V_73 -- ; V_74 -- ;
}
V_28 = V_70 - V_72 ;
while ( V_28 && V_75 > 0 ) {
V_75 = * V_73 + 1 ;
* V_73 = V_75 & 0xff ;
V_75 >>= 8 ;
V_28 -- ; V_73 -- ;
}
}
static int F_26 ( struct V_6 * V_7 ,
unsigned char * V_76 , T_4 V_60 ,
struct V_21 * V_77 )
{
int V_9 = 0 ;
T_4 V_28 = 0 ;
unsigned char V_78 [ 5 ] ;
unsigned char * V_79 = V_7 -> V_53 + F_15 ( V_7 ) ;
struct V_23 V_25 ;
V_78 [ 0 ] = 1 ;
F_7 ( ( V_60 * 8 ) , & V_78 [ 1 ] ) ;
F_10 ( & V_25 , V_78 , 5 ) ;
F_27 ( & V_25 . V_11 , V_77 ) ;
while ( V_28 < V_60 ) {
short V_51 = 0 ;
V_9 = F_23 ( V_7 , NULL , V_79 , V_77 ) ;
if ( V_9 )
goto V_19;
V_78 [ 0 ] ++ ;
V_51 = ( F_5 ( V_7 ) < ( V_60 - V_28 ) ) ?
F_5 ( V_7 ) : ( V_60 - V_28 ) ;
memcpy ( V_76 + V_28 , V_79 , V_51 ) ;
V_28 += V_51 ;
}
V_19:
memset ( V_79 , 0 , F_5 ( V_7 ) ) ;
return V_9 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_21 * V_49 ,
int V_52 )
{
int V_9 = 0 ;
struct V_23 V_80 , V_81 ;
F_14 ( V_68 ) ;
F_14 ( V_82 ) ;
unsigned char * V_56 = V_7 -> V_53 ;
unsigned char V_65 = V_67 ;
if ( ! V_49 )
return - V_50 ;
if ( V_52 ) {
memcpy ( V_56 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_10 ( & V_80 , & V_65 , 1 ) ;
F_16 ( & V_80 . V_11 , & V_68 ) ;
F_10 ( & V_81 , V_56 , F_15 ( V_7 ) ) ;
F_16 ( & V_81 . V_11 , & V_68 ) ;
}
F_17 ( V_49 , & V_68 ) ;
V_9 = F_26 ( V_7 , V_7 -> V_56 , F_15 ( V_7 ) , & V_68 ) ;
if ( V_9 )
goto V_19;
V_65 = V_66 ;
F_10 ( & V_80 , & V_65 , 1 ) ;
F_16 ( & V_80 . V_11 , & V_82 ) ;
F_10 ( & V_81 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_16 ( & V_81 . V_11 , & V_82 ) ;
V_9 = F_26 ( V_7 , V_7 -> V_57 , F_15 ( V_7 ) , & V_82 ) ;
V_19:
memset ( V_7 -> V_53 , 0 , F_15 ( V_7 ) ) ;
return V_9 ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_21 * V_59 )
{
int V_9 = 0 ;
struct V_23 V_80 , V_81 ;
F_14 ( V_68 ) ;
unsigned char V_65 = V_83 ;
if ( ! V_59 || F_4 ( V_59 ) )
return 0 ;
F_10 ( & V_80 , & V_65 , 1 ) ;
F_10 ( & V_81 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_16 ( & V_80 . V_11 , & V_68 ) ;
F_16 ( & V_81 . V_11 , & V_68 ) ;
F_17 ( V_59 , & V_68 ) ;
V_9 = F_23 ( V_7 , NULL , V_7 -> V_53 , & V_68 ) ;
if ( V_9 )
goto V_19;
F_25 ( V_7 -> V_56 , F_15 ( V_7 ) ,
V_7 -> V_53 , F_5 ( V_7 ) ) ;
V_19:
memset ( V_7 -> V_53 , 0 , F_5 ( V_7 ) ) ;
return V_9 ;
}
static int F_30 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_58 )
{
int V_28 = 0 ;
int V_9 = 0 ;
unsigned char * V_84 = V_7 -> V_53 ;
unsigned char * V_69 = V_7 -> V_53 + F_15 ( V_7 ) ;
struct V_23 V_25 ;
F_14 ( V_68 ) ;
memcpy ( V_84 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_10 ( & V_25 , V_84 , F_15 ( V_7 ) ) ;
F_16 ( & V_25 . V_11 , & V_68 ) ;
while ( V_28 < V_58 ) {
unsigned int V_60 = 0 ;
V_9 = F_23 ( V_7 , NULL , V_69 , & V_68 ) ;
if ( V_9 ) {
V_28 = V_9 ;
goto V_19;
}
V_60 = ( F_5 ( V_7 ) < ( V_58 - V_28 ) ) ?
F_5 ( V_7 ) : ( V_58 - V_28 ) ;
if ( ! F_2 ( V_7 , V_69 ) ) {
F_20 ( V_84 , F_15 ( V_7 ) ) ;
continue;
}
memcpy ( V_8 + V_28 , V_69 , V_60 ) ;
V_28 += V_60 ;
if ( V_28 < V_58 )
F_20 ( V_84 , F_15 ( V_7 ) ) ;
}
V_19:
memset ( V_7 -> V_53 , 0 ,
( F_15 ( V_7 ) + F_5 ( V_7 ) ) ) ;
return V_28 ;
}
static int F_31 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_21 * V_59 )
{
int V_28 = 0 ;
int V_9 = 0 ;
union {
unsigned char V_85 [ 8 ] ;
T_5 V_86 ;
} V_87 ;
unsigned char V_65 = V_88 ;
struct V_23 V_80 , V_81 ;
F_14 ( V_68 ) ;
V_9 = F_29 ( V_7 , V_59 ) ;
if ( V_9 )
return V_9 ;
V_28 = F_30 ( V_7 , V_8 , V_58 ) ;
F_10 ( & V_80 , & V_65 , 1 ) ;
F_16 ( & V_80 . V_11 , & V_68 ) ;
F_10 ( & V_81 , V_7 -> V_56 , F_15 ( V_7 ) ) ;
F_16 ( & V_81 . V_11 , & V_68 ) ;
V_9 = F_23 ( V_7 , NULL , V_7 -> V_53 , & V_68 ) ;
if ( V_9 ) {
V_28 = V_9 ;
goto V_19;
}
F_25 ( V_7 -> V_56 , F_15 ( V_7 ) ,
V_7 -> V_53 , F_5 ( V_7 ) ) ;
F_25 ( V_7 -> V_56 , F_15 ( V_7 ) ,
V_7 -> V_57 , F_15 ( V_7 ) ) ;
V_87 . V_86 = F_32 ( V_7 -> V_89 ) ;
F_25 ( V_7 -> V_56 , F_15 ( V_7 ) , V_87 . V_85 , 8 ) ;
V_19:
memset ( V_7 -> V_53 , 0 , F_5 ( V_7 ) ) ;
return V_28 ;
}
static inline int F_33 ( struct V_6 * V_7 , struct V_21 * V_49 ,
int V_52 )
{
int V_9 = V_7 -> V_90 -> V_91 ( V_7 , V_49 , V_52 ) ;
if ( V_9 )
return V_9 ;
V_7 -> V_92 = true ;
V_7 -> V_89 = 1 ;
return V_9 ;
}
static void F_34 ( struct V_93 * V_94 )
{
struct V_23 V_25 ;
F_14 ( V_31 ) ;
struct V_6 * V_7 = F_35 ( V_94 , struct V_6 ,
V_95 ) ;
unsigned int V_96 = F_1 ( V_7 -> V_97 -> V_1 ) ;
unsigned char V_98 [ 32 ] ;
F_36 ( ! V_96 ) ;
F_36 ( V_96 > sizeof( V_98 ) ) ;
F_37 ( V_98 , V_96 ) ;
F_10 ( & V_25 , V_98 , V_96 ) ;
F_16 ( & V_25 . V_11 , & V_31 ) ;
F_38 ( & V_7 -> V_99 ) ;
F_39 ( V_7 -> V_100 ) ;
V_7 -> V_100 = NULL ;
V_7 -> V_92 = false ;
F_33 ( V_7 , & V_31 , true ) ;
if ( V_7 -> V_92 )
V_7 -> V_101 = F_40 ( V_7 ) ;
F_41 ( & V_7 -> V_99 ) ;
F_42 ( V_98 , V_96 ) ;
}
static int F_43 ( struct V_6 * V_7 , struct V_23 * V_102 ,
bool V_52 )
{
int V_9 ;
unsigned char V_98 [ ( ( 32 + 16 ) * 2 ) ] ;
unsigned int V_96 = F_1 ( V_7 -> V_97 -> V_1 ) ;
struct V_23 V_80 ;
F_14 ( V_31 ) ;
if ( V_102 && V_102 -> V_28 > ( F_44 ( V_7 ) ) ) {
F_45 ( L_6 ,
V_102 -> V_28 ) ;
return - V_50 ;
}
if ( F_4 ( & V_7 -> V_10 . V_11 ) ) {
F_10 ( & V_80 , V_7 -> V_10 . V_8 ,
V_7 -> V_10 . V_28 ) ;
F_45 ( L_7 ) ;
} else {
F_36 ( ! V_96 ) ;
if ( ! V_52 )
V_96 = ( ( V_96 + 1 ) / 2 ) * 3 ;
F_36 ( ( V_96 * 2 ) > sizeof( V_98 ) ) ;
F_37 ( V_98 , V_96 ) ;
if ( ! V_7 -> V_100 ) {
F_10 ( & V_80 , V_98 , V_96 ) ;
F_45 ( L_8 ,
V_96 ) ;
} else {
V_9 = F_46 ( V_7 -> V_100 ,
V_98 + V_96 ,
V_96 ) ;
if ( V_9 ) {
F_45 ( L_9 , V_9 ) ;
return V_9 ;
}
F_10 ( & V_80 , V_98 , V_96 * 2 ) ;
F_45 ( L_8 ,
V_96 * 2 ) ;
}
}
F_16 ( & V_80 . V_11 , & V_31 ) ;
if ( V_102 && V_102 -> V_8 && 0 < V_102 -> V_28 ) {
F_16 ( & V_102 -> V_11 , & V_31 ) ;
F_45 ( L_10 ) ;
}
if ( ! V_52 ) {
memset ( V_7 -> V_56 , 0 , F_15 ( V_7 ) ) ;
memset ( V_7 -> V_57 , 0 , F_15 ( V_7 ) ) ;
}
V_9 = F_33 ( V_7 , & V_31 , V_52 ) ;
F_42 ( V_98 , V_96 * 2 ) ;
return V_9 ;
}
static inline void F_47 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_48 ( V_7 -> V_56 ) ;
V_7 -> V_56 = NULL ;
F_48 ( V_7 -> V_57 ) ;
V_7 -> V_57 = NULL ;
F_48 ( V_7 -> V_53 ) ;
V_7 -> V_53 = NULL ;
V_7 -> V_89 = 0 ;
V_7 -> V_90 = NULL ;
V_7 -> V_97 = NULL ;
#ifdef F_3
F_48 ( V_7 -> V_14 ) ;
V_7 -> V_14 = NULL ;
V_7 -> V_13 = false ;
#endif
}
static inline int F_49 ( struct V_6 * V_7 )
{
int V_9 = - V_103 ;
unsigned int V_104 = 0 ;
switch ( V_7 -> V_97 -> V_1 & V_105 ) {
#ifdef F_50
case V_106 :
V_7 -> V_90 = & V_107 ;
break;
#endif
#ifdef F_51
case V_108 :
V_7 -> V_90 = & V_109 ;
break;
#endif
#ifdef F_52
case V_110 :
V_7 -> V_90 = & V_111 ;
break;
#endif
default:
V_9 = - V_112 ;
goto V_113;
}
V_7 -> V_56 = F_53 ( F_15 ( V_7 ) , V_114 ) ;
if ( ! V_7 -> V_56 )
goto V_113;
V_7 -> V_57 = F_53 ( F_15 ( V_7 ) , V_114 ) ;
if ( ! V_7 -> V_57 )
goto V_113;
#ifdef F_3
V_7 -> V_14 = F_53 ( F_5 ( V_7 ) , V_114 ) ;
if ( ! V_7 -> V_14 )
goto V_113;
V_7 -> V_13 = false ;
#endif
if ( V_7 -> V_97 -> V_1 & V_106 )
V_104 = 0 ;
else if ( V_7 -> V_97 -> V_1 & V_110 )
V_104 = F_15 ( V_7 ) + F_5 ( V_7 ) +
F_15 ( V_7 ) +
F_5 ( V_7 ) +
F_5 ( V_7 ) +
F_15 ( V_7 ) + F_5 ( V_7 ) ;
else
V_104 = F_15 ( V_7 ) + F_5 ( V_7 ) ;
if ( 0 < V_104 ) {
V_7 -> V_53 = F_54 ( V_104 , V_114 ) ;
if ( ! V_7 -> V_53 )
goto V_113;
}
return 0 ;
V_113:
F_47 ( V_7 ) ;
return V_9 ;
}
static int F_55 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_23 * V_59 )
{
int V_28 = 0 ;
F_14 ( V_115 ) ;
if ( ! V_7 -> V_97 ) {
F_45 ( L_11 ) ;
return - V_50 ;
}
if ( 0 == V_58 || ! V_8 ) {
F_45 ( L_12 ) ;
return - V_50 ;
}
if ( V_59 && NULL == V_59 -> V_8 && 0 < V_59 -> V_28 ) {
F_45 ( L_13 ) ;
return - V_50 ;
}
V_28 = - V_50 ;
if ( V_58 > ( F_56 ( V_7 ) ) ) {
F_45 ( L_14 ,
V_58 ) ;
goto V_113;
}
if ( V_59 && V_59 -> V_28 > ( F_44 ( V_7 ) ) ) {
F_45 ( L_15 ,
V_59 -> V_28 ) ;
goto V_113;
}
if ( V_7 -> V_101 < V_7 -> V_89 )
V_7 -> V_92 = false ;
if ( V_7 -> V_116 || ! V_7 -> V_92 ) {
F_45 ( L_16
L_17 ,
V_7 -> V_116 ? L_18 : L_19 ,
V_7 -> V_92 ? L_20 : L_21 ) ;
V_28 = F_43 ( V_7 , V_59 , true ) ;
if ( V_28 )
goto V_113;
V_59 = NULL ;
}
if ( V_59 && 0 < V_59 -> V_28 )
F_16 ( & V_59 -> V_11 , & V_115 ) ;
V_28 = V_7 -> V_90 -> V_117 ( V_7 , V_8 , V_58 , & V_115 ) ;
V_7 -> V_89 ++ ;
if ( 0 >= V_28 )
goto V_113;
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
V_28 = 0 ;
V_113:
return V_28 ;
}
static int F_57 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_23 * V_59 )
{
unsigned int V_28 = 0 ;
unsigned int V_118 = 0 ;
do {
int V_113 = 0 ;
unsigned int V_119 = 0 ;
V_118 = ( ( V_58 - V_28 ) / F_56 ( V_7 ) ) ;
V_119 = V_118 ? F_56 ( V_7 ) : ( V_58 - V_28 ) ;
F_38 ( & V_7 -> V_99 ) ;
V_113 = F_55 ( V_7 , V_8 + V_28 , V_119 , V_59 ) ;
F_41 ( & V_7 -> V_99 ) ;
if ( 0 > V_113 )
return V_113 ;
V_28 += V_119 ;
} while ( V_118 > 0 && ( V_28 < V_58 ) );
return 0 ;
}
static void F_58 ( struct V_120 * V_121 )
{
struct V_6 * V_7 = F_35 ( V_121 , struct V_6 ,
V_122 ) ;
F_59 ( & V_7 -> V_95 ) ;
}
static int F_60 ( struct V_6 * V_7 )
{
int V_113 ;
if ( F_4 ( & V_7 -> V_10 . V_11 ) )
return 0 ;
F_61 ( & V_7 -> V_95 , F_34 ) ;
V_7 -> V_122 . V_123 = V_124 ;
V_7 -> V_122 . V_125 = F_58 ;
V_113 = F_62 ( & V_7 -> V_122 ) ;
switch ( V_113 ) {
case 0 :
break;
case - V_126 :
V_113 = 0 ;
default:
V_7 -> V_122 . V_125 = NULL ;
return V_113 ;
}
V_7 -> V_100 = F_63 ( L_22 , 0 , 0 ) ;
V_7 -> V_101 = 50 ;
return V_113 ;
}
static int F_64 ( struct V_6 * V_7 , struct V_23 * V_102 ,
int V_127 , bool V_116 )
{
int V_9 ;
bool V_52 = true ;
F_45 ( L_23
L_24 , V_127 , V_116 ? L_25 : L_26 ) ;
F_38 ( & V_7 -> V_99 ) ;
if ( ! V_7 -> V_97 ) {
V_7 -> V_97 = & V_128 [ V_127 ] ;
V_7 -> V_116 = V_116 ;
V_7 -> V_92 = false ;
V_7 -> V_101 = F_40 ( V_7 ) ;
V_9 = F_49 ( V_7 ) ;
if ( V_9 )
goto V_129;
V_9 = - V_32 ;
if ( V_7 -> V_90 -> V_130 ( V_7 ) )
goto V_113;
V_9 = F_60 ( V_7 ) ;
if ( V_9 )
goto V_131;
if ( F_65 ( V_7 -> V_100 ) ) {
V_9 = F_66 ( V_7 -> V_100 ) ;
V_7 -> V_100 = NULL ;
if ( V_12 || V_9 != - V_132 )
goto V_131;
F_67 ( L_27 ) ;
}
V_52 = false ;
}
V_9 = F_43 ( V_7 , V_102 , V_52 ) ;
if ( V_9 && ! V_52 )
goto V_131;
F_41 ( & V_7 -> V_99 ) ;
return V_9 ;
V_113:
F_47 ( V_7 ) ;
V_129:
F_41 ( & V_7 -> V_99 ) ;
return V_9 ;
V_131:
F_41 ( & V_7 -> V_99 ) ;
F_68 ( V_7 ) ;
return V_9 ;
}
static int F_68 ( struct V_6 * V_7 )
{
if ( V_7 -> V_122 . V_125 ) {
F_69 ( & V_7 -> V_122 ) ;
F_70 ( & V_7 -> V_95 ) ;
F_39 ( V_7 -> V_100 ) ;
V_7 -> V_100 = NULL ;
}
if ( V_7 -> V_90 )
V_7 -> V_90 -> V_133 ( V_7 ) ;
F_47 ( V_7 ) ;
return 0 ;
}
static void F_71 ( struct V_134 * V_135 ,
const T_6 * V_25 , unsigned int V_28 )
{
struct V_6 * V_7 = F_72 ( V_135 ) ;
F_38 ( & V_7 -> V_99 ) ;
F_10 ( & V_7 -> V_10 , V_25 , V_28 ) ;
F_41 ( & V_7 -> V_99 ) ;
}
static int F_73 ( struct V_6 * V_7 )
{
struct V_136 * V_136 ;
struct V_137 * V_135 ;
V_135 = F_74 ( V_7 -> V_97 -> V_138 , 0 , 0 ) ;
if ( F_65 ( V_135 ) ) {
F_67 ( L_28 ,
V_7 -> V_97 -> V_138 ) ;
return F_66 ( V_135 ) ;
}
F_36 ( F_5 ( V_7 ) != F_75 ( V_135 ) ) ;
V_136 = F_54 ( sizeof( struct V_139 ) + F_76 ( V_135 ) ,
V_114 ) ;
if ( ! V_136 ) {
F_77 ( V_135 ) ;
return - V_103 ;
}
V_136 -> V_140 . V_135 = V_135 ;
V_136 -> V_140 . V_1 = 0 ;
V_7 -> V_141 = V_136 ;
return 0 ;
}
static int F_78 ( struct V_6 * V_7 )
{
struct V_136 * V_136 = (struct V_136 * ) V_7 -> V_141 ;
if ( V_136 ) {
F_77 ( V_136 -> V_140 . V_135 ) ;
F_48 ( V_136 ) ;
}
V_7 -> V_141 = NULL ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , const unsigned char * V_20 ,
unsigned char * V_76 , const struct V_21 * V_22 )
{
struct V_136 * V_136 = (struct V_136 * ) V_7 -> V_141 ;
struct V_23 * V_78 = NULL ;
if ( V_20 )
F_79 ( V_136 -> V_140 . V_135 , V_20 , F_15 ( V_7 ) ) ;
F_80 ( & V_136 -> V_140 ) ;
F_11 (input, in, list)
F_81 ( & V_136 -> V_140 , V_78 -> V_8 , V_78 -> V_28 ) ;
return F_82 ( & V_136 -> V_140 , V_76 ) ;
}
static int F_83 ( struct V_6 * V_7 )
{
int V_9 = 0 ;
struct V_142 * V_135 ;
V_135 = F_84 ( V_7 -> V_97 -> V_138 , 0 , 0 ) ;
if ( F_65 ( V_135 ) ) {
F_67 ( L_29 ,
V_7 -> V_97 -> V_138 ) ;
return F_66 ( V_135 ) ;
}
F_36 ( F_5 ( V_7 ) != F_85 ( V_135 ) ) ;
V_7 -> V_141 = V_135 ;
return V_9 ;
}
static int F_86 ( struct V_6 * V_7 )
{
struct V_142 * V_135 =
(struct V_142 * ) V_7 -> V_141 ;
if ( V_135 )
F_87 ( V_135 ) ;
V_7 -> V_141 = NULL ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , const unsigned char * V_20 ,
unsigned char * V_76 , const struct V_23 * V_22 )
{
struct V_142 * V_135 =
(struct V_142 * ) V_7 -> V_141 ;
F_88 ( V_135 , V_20 , ( F_18 ( V_7 ) ) ) ;
F_36 ( V_22 -> V_28 < F_5 ( V_7 ) ) ;
F_89 ( V_135 , V_76 , V_22 -> V_8 ) ;
return 0 ;
}
static inline void F_90 ( const char * V_143 ,
int * V_127 , bool * V_116 )
{
int V_44 = 0 ;
T_4 V_144 = 0 ;
int V_28 = 0 ;
* V_116 = true ;
if ( ! memcmp ( V_143 , L_30 , 10 ) ) {
V_144 = 10 ;
* V_116 = false ;
} else if ( ! memcmp ( V_143 , L_31 , 8 ) ) {
V_144 = 8 ;
} else {
return;
}
V_28 = strlen ( V_143 ) - V_144 ;
for ( V_44 = 0 ; F_91 ( V_128 ) > V_44 ; V_44 ++ ) {
if ( ! memcmp ( V_143 + V_144 , V_128 [ V_44 ] . V_145 ,
V_28 ) ) {
* V_127 = V_44 ;
return;
}
}
}
static int F_92 ( struct V_146 * V_135 )
{
struct V_6 * V_7 = F_93 ( V_135 ) ;
F_94 ( & V_7 -> V_99 ) ;
return 0 ;
}
static void F_95 ( struct V_146 * V_135 )
{
F_68 ( F_93 ( V_135 ) ) ;
}
static int F_96 ( struct V_134 * V_135 ,
const T_6 * V_84 , unsigned int V_147 ,
T_6 * V_69 , unsigned int V_148 )
{
struct V_6 * V_7 = F_72 ( V_135 ) ;
struct V_23 * V_59 = NULL ;
struct V_23 string ;
if ( V_147 ) {
F_10 ( & string , V_84 , V_147 ) ;
V_59 = & string ;
}
return F_57 ( V_7 , V_69 , V_148 , V_59 ) ;
}
static int F_97 ( struct V_134 * V_135 ,
const T_6 * V_49 , unsigned int V_147 )
{
struct V_6 * V_7 = F_72 ( V_135 ) ;
struct V_146 * V_149 = F_98 ( V_135 ) ;
bool V_116 = false ;
struct V_23 string ;
struct V_23 * V_150 = NULL ;
int V_127 = 0 ;
F_90 ( F_99 ( V_149 ) , & V_127 ,
& V_116 ) ;
if ( 0 < V_147 ) {
F_10 ( & string , V_49 , V_147 ) ;
V_150 = & string ;
}
return F_64 ( V_7 , V_150 , V_127 , V_116 ) ;
}
static inline int T_7 F_100 ( void )
{
int V_28 = 0 ;
#define F_101 16
unsigned char V_8 [ F_101 ] ;
struct V_6 * V_7 = NULL ;
int V_9 = - V_32 ;
int V_151 = - V_32 ;
bool V_116 = false ;
int V_127 = 0 ;
struct V_23 V_59 ;
T_4 V_152 , V_153 ;
if ( ! V_12 )
return 0 ;
#ifdef F_52
F_90 ( L_32 , & V_127 , & V_116 ) ;
#elif V_154 F_51
F_90 ( L_33 , & V_127 , & V_116 ) ;
#else
F_90 ( L_34 , & V_127 , & V_116 ) ;
#endif
V_7 = F_54 ( sizeof( struct V_6 ) , V_114 ) ;
if ( ! V_7 )
return - V_103 ;
F_94 ( & V_7 -> V_99 ) ;
V_9 = F_64 ( V_7 , NULL , V_127 , V_116 ) ;
if ( V_9 ) {
V_151 = V_9 ;
goto V_155;
}
V_152 = F_44 ( V_7 ) ;
V_153 = F_56 ( V_7 ) ;
F_10 ( & V_59 , V_8 , V_152 + 1 ) ;
V_28 = F_55 ( V_7 , V_8 , F_101 , & V_59 ) ;
F_36 ( 0 < V_28 ) ;
V_28 = F_55 ( V_7 , V_8 , ( V_153 + 1 ) , NULL ) ;
F_36 ( 0 < V_28 ) ;
F_68 ( V_7 ) ;
V_9 = F_64 ( V_7 , & V_59 , V_127 , V_116 ) ;
F_36 ( 0 == V_9 ) ;
V_151 = 0 ;
F_45 ( L_35
L_36 ) ;
F_68 ( V_7 ) ;
V_155:
F_48 ( V_7 ) ;
return V_151 ;
}
static inline void T_7 F_102 ( struct V_156 * V_157 ,
const struct V_158 * V_97 , int V_116 )
{
int V_27 = 0 ;
static int V_159 = 200 ;
memcpy ( V_157 -> V_160 . V_145 , L_37 , 6 ) ;
if ( V_116 ) {
memcpy ( V_157 -> V_160 . V_143 , L_31 , 8 ) ;
V_27 = 8 ;
} else {
memcpy ( V_157 -> V_160 . V_143 , L_30 , 10 ) ;
V_27 = 10 ;
}
memcpy ( V_157 -> V_160 . V_143 + V_27 , V_97 -> V_145 ,
strlen ( V_97 -> V_145 ) ) ;
V_157 -> V_160 . V_161 = V_159 ;
V_159 ++ ;
if ( V_12 )
V_157 -> V_160 . V_161 += 200 ;
V_157 -> V_160 . V_162 = sizeof( struct V_6 ) ;
V_157 -> V_160 . V_163 = V_124 ;
V_157 -> V_160 . V_164 = F_92 ;
V_157 -> V_160 . V_165 = F_95 ;
V_157 -> V_117 = F_96 ;
V_157 -> V_49 = F_97 ;
V_157 -> V_166 = F_71 ;
V_157 -> V_167 = 0 ;
}
static int T_7 F_103 ( void )
{
unsigned int V_44 = 0 ;
unsigned int V_168 = 0 ;
int V_9 = - V_32 ;
V_9 = F_100 () ;
if ( V_9 )
return V_9 ;
if ( F_91 ( V_128 ) * 2 > F_91 ( V_169 ) ) {
F_67 ( L_38
L_39 ,
F_91 ( V_128 ) * 2 , F_91 ( V_169 ) ) ;
return V_9 ;
}
for ( V_168 = 0 ; F_91 ( V_128 ) > V_168 ; V_168 ++ , V_44 ++ )
F_102 ( & V_169 [ V_44 ] , & V_128 [ V_168 ] , 1 ) ;
for ( V_168 = 0 ; F_91 ( V_128 ) > V_168 ; V_168 ++ , V_44 ++ )
F_102 ( & V_169 [ V_44 ] , & V_128 [ V_168 ] , 0 ) ;
return F_104 ( V_169 , ( F_91 ( V_128 ) * 2 ) ) ;
}
static void T_8 F_105 ( void )
{
F_106 ( V_169 , ( F_91 ( V_128 ) * 2 ) ) ;
}
