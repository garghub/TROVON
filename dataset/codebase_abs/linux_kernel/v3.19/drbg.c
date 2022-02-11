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
static int F_7 ( struct V_6 * V_7 ,
unsigned char * V_18 , const unsigned char * V_19 ,
struct V_20 * V_21 )
{
int V_9 = 0 ;
struct V_22 * V_23 = NULL ;
struct V_22 V_24 ;
short V_25 = 0 ;
F_8 ( & V_24 , V_18 , F_4 ( V_7 ) ) ;
memset ( V_18 , 0 , F_4 ( V_7 ) ) ;
F_9 (curr, in, list) {
const unsigned char * V_26 = V_23 -> V_8 ;
T_4 V_27 = V_23 -> V_27 ;
while ( V_27 ) {
if ( F_4 ( V_7 ) == V_25 ) {
V_25 = 0 ;
V_9 = F_10 ( V_7 , V_19 , V_18 , & V_24 ) ;
if ( V_9 )
return V_9 ;
}
V_18 [ V_25 ] ^= * V_26 ;
V_26 ++ ;
V_25 ++ ;
V_27 -- ;
}
}
if ( V_25 )
V_9 = F_10 ( V_7 , V_19 , V_18 , & V_24 ) ;
return V_9 ;
}
static int F_11 ( struct V_6 * V_7 ,
unsigned char * V_28 , T_4 V_29 ,
struct V_20 * V_30 )
{
int V_9 = - V_31 ;
unsigned char V_32 [ 8 ] ;
struct V_22 V_33 , V_34 , V_35 , V_36 ;
F_12 ( V_37 ) ;
unsigned char * V_38 = V_28 + F_13 ( V_7 ) ;
unsigned char * V_39 = V_38 + F_4 ( V_7 ) ;
unsigned char * V_40 = V_39 + F_4 ( V_7 ) ;
T_4 V_41 = 0 ;
unsigned int V_42 = 0 ;
unsigned int V_43 = 0 ;
const unsigned char * V_44 = ( unsigned char * )
L_1
L_2
L_3
L_4 ;
unsigned char * V_45 ;
T_4 V_46 = 0 ;
T_4 V_47 = 0 ;
struct V_22 * V_48 = NULL ;
memset ( V_38 , 0 , F_4 ( V_7 ) ) ;
memset ( V_39 , 0 , F_4 ( V_7 ) ) ;
memset ( V_40 , 0 , F_13 ( V_7 ) ) ;
if ( ( 512 / 8 ) < V_29 )
return - V_49 ;
F_9 (seed, seedlist, list)
V_47 += V_48 -> V_27 ;
F_5 ( V_47 , & V_32 [ 0 ] ) ;
F_5 ( V_29 , & V_32 [ 4 ] ) ;
V_41 = ( V_47 + sizeof( V_32 ) + 1 ) % ( F_4 ( V_7 ) ) ;
if ( V_41 )
V_41 = F_4 ( V_7 ) - V_41 ;
V_41 ++ ;
V_38 [ 0 ] = 0x80 ;
F_8 ( & V_33 , V_39 , F_4 ( V_7 ) ) ;
F_14 ( & V_33 . V_50 , & V_37 ) ;
F_8 ( & V_34 , V_32 , sizeof( V_32 ) ) ;
F_14 ( & V_34 . V_50 , & V_37 ) ;
F_15 ( V_30 , & V_37 ) ;
F_8 ( & V_35 , V_38 , V_41 ) ;
F_14 ( & V_35 . V_50 , & V_37 ) ;
while ( V_42 < ( F_16 ( V_7 ) + ( F_4 ( V_7 ) ) ) ) {
F_5 ( V_43 , V_39 ) ;
V_9 = F_7 ( V_7 , V_40 + V_42 , V_44 , & V_37 ) ;
if ( V_9 )
goto V_18;
V_43 ++ ;
V_42 += F_4 ( V_7 ) ;
}
V_45 = V_40 + ( F_16 ( V_7 ) ) ;
F_8 ( & V_36 , V_45 , F_4 ( V_7 ) ) ;
while ( V_46 < V_29 ) {
short V_51 = 0 ;
V_9 = F_10 ( V_7 , V_40 , V_45 , & V_36 ) ;
if ( V_9 )
goto V_18;
V_51 = ( F_4 ( V_7 ) <
( V_29 - V_46 ) ) ?
F_4 ( V_7 ) :
( V_29 - V_46 ) ;
memcpy ( V_28 + V_46 , V_45 , V_51 ) ;
V_46 += V_51 ;
}
V_9 = 0 ;
V_18:
F_17 ( V_39 , F_4 ( V_7 ) ) ;
F_17 ( V_40 , F_13 ( V_7 ) ) ;
F_17 ( V_38 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_18 ( struct V_6 * V_7 , struct V_20 * V_48 ,
int V_52 )
{
int V_9 = - V_31 ;
unsigned char * V_40 = V_7 -> V_53 ;
unsigned char * V_28 = V_7 -> V_53 + F_13 ( V_7 ) +
F_4 ( V_7 ) ;
unsigned char * V_54 , * V_55 ;
unsigned int V_27 = 0 ;
struct V_22 V_36 ;
memset ( V_40 , 0 , F_13 ( V_7 ) + F_4 ( V_7 ) ) ;
if ( 3 > V_52 )
memset ( V_28 , 0 , F_13 ( V_7 ) ) ;
if ( V_48 ) {
V_9 = F_11 ( V_7 , V_28 , F_13 ( V_7 ) , V_48 ) ;
if ( V_9 )
goto V_18;
}
F_8 ( & V_36 , V_7 -> V_56 , F_4 ( V_7 ) ) ;
while ( V_27 < ( F_13 ( V_7 ) ) ) {
F_19 ( V_7 -> V_56 , F_4 ( V_7 ) ) ;
V_9 = F_10 ( V_7 , V_7 -> V_57 , V_40 + V_27 , & V_36 ) ;
if ( V_9 )
goto V_18;
V_27 += F_4 ( V_7 ) ;
}
V_54 = V_40 ;
V_55 = V_28 ;
for ( V_27 = 0 ; V_27 < F_13 ( V_7 ) ; V_27 ++ ) {
* V_54 ^= * V_55 ;
V_55 ++ ; V_54 ++ ;
}
memcpy ( V_7 -> V_57 , V_40 , F_16 ( V_7 ) ) ;
memcpy ( V_7 -> V_56 , V_40 + F_16 ( V_7 ) , F_4 ( V_7 ) ) ;
V_9 = 0 ;
V_18:
F_17 ( V_40 , F_13 ( V_7 ) + F_4 ( V_7 ) ) ;
if ( 2 != V_52 )
F_17 ( V_28 , F_13 ( V_7 ) ) ;
return V_9 ;
}
static int F_20 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_20 * V_59 )
{
int V_27 = 0 ;
int V_9 = 0 ;
struct V_22 V_24 ;
memset ( V_7 -> V_53 , 0 , F_4 ( V_7 ) ) ;
if ( V_59 && ! F_21 ( V_59 ) ) {
V_9 = F_18 ( V_7 , V_59 , 2 ) ;
if ( V_9 )
return 0 ;
}
F_19 ( V_7 -> V_56 , F_4 ( V_7 ) ) ;
F_8 ( & V_24 , V_7 -> V_56 , F_4 ( V_7 ) ) ;
while ( V_27 < V_58 ) {
int V_60 = 0 ;
V_9 = F_10 ( V_7 , V_7 -> V_57 , V_7 -> V_53 , & V_24 ) ;
if ( V_9 ) {
V_27 = V_9 ;
goto V_18;
}
V_60 = ( F_4 ( V_7 ) < ( V_58 - V_27 ) ) ?
F_4 ( V_7 ) : ( V_58 - V_27 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_53 ) ) {
F_19 ( V_7 -> V_56 , F_4 ( V_7 ) ) ;
continue;
}
memcpy ( V_8 + V_27 , V_7 -> V_53 , V_60 ) ;
V_27 += V_60 ;
if ( V_27 < V_58 )
F_19 ( V_7 -> V_56 , F_4 ( V_7 ) ) ;
}
V_9 = F_18 ( V_7 , NULL , 3 ) ;
if ( V_9 )
V_27 = V_9 ;
V_18:
F_17 ( V_7 -> V_53 , F_4 ( V_7 ) ) ;
return V_27 ;
}
static int F_22 ( struct V_6 * V_7 , struct V_20 * V_48 ,
int V_52 )
{
int V_9 = - V_31 ;
int V_43 = 0 ;
struct V_22 V_61 , V_62 , V_63 ;
F_12 ( V_30 ) ;
F_12 ( V_64 ) ;
if ( ! V_52 )
memset ( V_7 -> V_56 , 1 , F_13 ( V_7 ) ) ;
F_8 ( & V_61 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_14 ( & V_61 . V_50 , & V_30 ) ;
F_8 ( & V_62 , NULL , 1 ) ;
F_14 ( & V_62 . V_50 , & V_30 ) ;
if ( V_48 )
F_15 ( V_48 , & V_30 ) ;
F_8 ( & V_63 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_14 ( & V_63 . V_50 , & V_64 ) ;
for ( V_43 = 2 ; 0 < V_43 ; V_43 -- ) {
unsigned char V_65 = V_66 ;
if ( 1 == V_43 )
V_65 = V_67 ;
V_62 . V_8 = & V_65 ;
V_9 = F_23 ( V_7 , V_7 -> V_57 , V_7 -> V_57 , & V_30 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_23 ( V_7 , V_7 -> V_57 , V_7 -> V_56 , & V_64 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_48 )
return V_9 ;
}
return 0 ;
}
static int F_24 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_58 ,
struct V_20 * V_59 )
{
int V_27 = 0 ;
int V_9 = 0 ;
struct V_22 V_24 ;
F_12 ( V_68 ) ;
if ( V_59 && ! F_21 ( V_59 ) ) {
V_9 = F_22 ( V_7 , V_59 , 1 ) ;
if ( V_9 )
return V_9 ;
}
F_8 ( & V_24 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_14 ( & V_24 . V_50 , & V_68 ) ;
while ( V_27 < V_58 ) {
unsigned int V_60 = 0 ;
V_9 = F_23 ( V_7 , V_7 -> V_57 , V_7 -> V_56 , & V_68 ) ;
if ( V_9 )
return V_9 ;
V_60 = ( F_4 ( V_7 ) < ( V_58 - V_27 ) ) ?
F_4 ( V_7 ) : ( V_58 - V_27 ) ;
if ( ! F_2 ( V_7 , V_7 -> V_56 ) )
continue;
memcpy ( V_8 + V_27 , V_7 -> V_56 , V_60 ) ;
V_27 += V_60 ;
}
if ( V_59 && ! F_21 ( V_59 ) )
V_9 = F_22 ( V_7 , V_59 , 1 ) ;
else
V_9 = F_22 ( V_7 , NULL , 1 ) ;
if ( V_9 )
return V_9 ;
return V_27 ;
}
static inline void F_25 ( unsigned char * V_69 , T_4 V_70 ,
const unsigned char * V_71 , T_4 V_72 )
{
unsigned char * V_73 ;
const unsigned char * V_74 ;
unsigned int V_75 = 0 ;
T_4 V_27 = V_72 ;
V_73 = V_69 + ( V_70 - 1 ) ;
V_74 = V_71 + ( V_72 - 1 ) ;
while ( V_27 ) {
V_75 += * V_73 + * V_74 ;
* V_73 = V_75 & 0xff ;
V_75 >>= 8 ;
V_27 -- ; V_73 -- ; V_74 -- ;
}
V_27 = V_70 - V_72 ;
while ( V_27 && V_75 > 0 ) {
V_75 = * V_73 + 1 ;
* V_73 = V_75 & 0xff ;
V_75 >>= 8 ;
V_27 -- ; V_73 -- ;
}
}
static int F_26 ( struct V_6 * V_7 ,
unsigned char * V_76 , T_4 V_60 ,
struct V_20 * V_77 )
{
int V_9 = 0 ;
T_4 V_27 = 0 ;
unsigned char V_78 [ 5 ] ;
unsigned char * V_79 = V_7 -> V_53 + F_13 ( V_7 ) ;
struct V_22 V_24 ;
memset ( V_79 , 0 , F_4 ( V_7 ) ) ;
V_78 [ 0 ] = 1 ;
F_5 ( ( V_60 * 8 ) , & V_78 [ 1 ] ) ;
F_8 ( & V_24 , V_78 , 5 ) ;
F_27 ( & V_24 . V_50 , V_77 ) ;
while ( V_27 < V_60 ) {
short V_51 = 0 ;
V_9 = F_23 ( V_7 , NULL , V_79 , V_77 ) ;
if ( V_9 )
goto V_18;
V_78 [ 0 ] ++ ;
V_51 = ( F_4 ( V_7 ) < ( V_60 - V_27 ) ) ?
F_4 ( V_7 ) : ( V_60 - V_27 ) ;
memcpy ( V_76 + V_27 , V_79 , V_51 ) ;
V_27 += V_51 ;
}
V_18:
F_17 ( V_79 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_28 ( struct V_6 * V_7 , struct V_20 * V_48 ,
int V_52 )
{
int V_9 = 0 ;
struct V_22 V_80 , V_81 ;
F_12 ( V_68 ) ;
F_12 ( V_82 ) ;
unsigned char * V_56 = V_7 -> V_53 ;
unsigned char V_65 = V_67 ;
memset ( V_7 -> V_53 , 0 , F_13 ( V_7 ) ) ;
if ( ! V_48 )
return - V_49 ;
if ( V_52 ) {
memcpy ( V_56 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_8 ( & V_80 , & V_65 , 1 ) ;
F_14 ( & V_80 . V_50 , & V_68 ) ;
F_8 ( & V_81 , V_56 , F_13 ( V_7 ) ) ;
F_14 ( & V_81 . V_50 , & V_68 ) ;
}
F_15 ( V_48 , & V_68 ) ;
V_9 = F_26 ( V_7 , V_7 -> V_56 , F_13 ( V_7 ) , & V_68 ) ;
if ( V_9 )
goto V_18;
V_65 = V_66 ;
F_8 ( & V_80 , & V_65 , 1 ) ;
F_14 ( & V_80 . V_50 , & V_82 ) ;
F_8 ( & V_81 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_14 ( & V_81 . V_50 , & V_82 ) ;
V_9 = F_26 ( V_7 , V_7 -> V_57 , F_13 ( V_7 ) , & V_82 ) ;
V_18:
F_17 ( V_7 -> V_53 , F_13 ( V_7 ) ) ;
return V_9 ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_20 * V_59 )
{
int V_9 = 0 ;
struct V_22 V_80 , V_81 ;
F_12 ( V_68 ) ;
unsigned char V_65 = V_83 ;
memset ( V_7 -> V_53 , 0 , F_4 ( V_7 ) ) ;
if ( ! V_59 || F_21 ( V_59 ) )
return 0 ;
F_8 ( & V_80 , & V_65 , 1 ) ;
F_8 ( & V_81 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_14 ( & V_80 . V_50 , & V_68 ) ;
F_14 ( & V_81 . V_50 , & V_68 ) ;
F_15 ( V_59 , & V_68 ) ;
V_9 = F_23 ( V_7 , NULL , V_7 -> V_53 , & V_68 ) ;
if ( V_9 )
goto V_18;
F_25 ( V_7 -> V_56 , F_13 ( V_7 ) ,
V_7 -> V_53 , F_4 ( V_7 ) ) ;
V_18:
F_17 ( V_7 -> V_53 , F_4 ( V_7 ) ) ;
return V_9 ;
}
static int F_30 ( struct V_6 * V_7 ,
unsigned char * V_8 ,
unsigned int V_58 )
{
int V_27 = 0 ;
int V_9 = 0 ;
unsigned char * V_84 = V_7 -> V_53 ;
unsigned char * V_69 = V_7 -> V_53 + F_13 ( V_7 ) ;
struct V_22 V_24 ;
F_12 ( V_68 ) ;
memset ( V_84 , 0 , F_13 ( V_7 ) ) ;
memset ( V_69 , 0 , F_4 ( V_7 ) ) ;
memcpy ( V_84 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_8 ( & V_24 , V_84 , F_13 ( V_7 ) ) ;
F_14 ( & V_24 . V_50 , & V_68 ) ;
while ( V_27 < V_58 ) {
unsigned int V_60 = 0 ;
V_9 = F_23 ( V_7 , NULL , V_69 , & V_68 ) ;
if ( V_9 ) {
V_27 = V_9 ;
goto V_18;
}
V_60 = ( F_4 ( V_7 ) < ( V_58 - V_27 ) ) ?
F_4 ( V_7 ) : ( V_58 - V_27 ) ;
if ( ! F_2 ( V_7 , V_69 ) ) {
F_19 ( V_84 , F_13 ( V_7 ) ) ;
continue;
}
memcpy ( V_8 + V_27 , V_69 , V_60 ) ;
V_27 += V_60 ;
if ( V_27 < V_58 )
F_19 ( V_84 , F_13 ( V_7 ) ) ;
}
V_18:
F_17 ( V_7 -> V_53 ,
( F_13 ( V_7 ) + F_4 ( V_7 ) ) ) ;
return V_27 ;
}
static int F_31 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_20 * V_59 )
{
int V_27 = 0 ;
int V_9 = 0 ;
union {
unsigned char V_85 [ 8 ] ;
T_5 V_86 ;
} V_87 ;
unsigned char V_65 = V_88 ;
struct V_22 V_80 , V_81 ;
F_12 ( V_68 ) ;
V_9 = F_29 ( V_7 , V_59 ) ;
if ( V_9 )
return V_9 ;
V_27 = F_30 ( V_7 , V_8 , V_58 ) ;
memset ( V_7 -> V_53 , 0 , F_4 ( V_7 ) ) ;
F_8 ( & V_80 , & V_65 , 1 ) ;
F_14 ( & V_80 . V_50 , & V_68 ) ;
F_8 ( & V_81 , V_7 -> V_56 , F_13 ( V_7 ) ) ;
F_14 ( & V_81 . V_50 , & V_68 ) ;
V_9 = F_23 ( V_7 , NULL , V_7 -> V_53 , & V_68 ) ;
if ( V_9 ) {
V_27 = V_9 ;
goto V_18;
}
F_25 ( V_7 -> V_56 , F_13 ( V_7 ) ,
V_7 -> V_53 , F_4 ( V_7 ) ) ;
F_25 ( V_7 -> V_56 , F_13 ( V_7 ) ,
V_7 -> V_57 , F_13 ( V_7 ) ) ;
V_87 . V_86 = F_32 ( V_7 -> V_89 ) ;
F_25 ( V_7 -> V_56 , F_13 ( V_7 ) , V_87 . V_85 , 8 ) ;
V_18:
F_17 ( V_7 -> V_53 , F_4 ( V_7 ) ) ;
return V_27 ;
}
static int F_33 ( struct V_6 * V_7 , struct V_22 * V_90 ,
bool V_52 )
{
int V_9 = 0 ;
unsigned char * V_91 = NULL ;
T_4 V_92 = 0 ;
struct V_22 V_80 ;
F_12 ( V_30 ) ;
if ( V_90 && V_90 -> V_27 > ( F_34 ( V_7 ) ) ) {
F_35 ( L_5 ,
V_90 -> V_27 ) ;
return - V_49 ;
}
if ( V_7 -> V_10 && V_7 -> V_10 -> V_93 ) {
F_8 ( & V_80 , V_7 -> V_10 -> V_93 -> V_8 ,
V_7 -> V_10 -> V_93 -> V_27 ) ;
F_35 ( L_6 ) ;
} else {
V_92 = F_1 ( V_7 -> V_94 -> V_1 ) ;
if ( ! V_92 )
return - V_31 ;
if ( ! V_52 )
V_92 = ( ( V_92 + 1 ) / 2 ) * 3 ;
F_35 ( L_7 ,
V_92 ) ;
V_91 = F_36 ( V_92 , V_95 ) ;
if ( ! V_91 )
return - V_96 ;
F_37 ( V_91 , V_92 ) ;
F_8 ( & V_80 , V_91 , V_92 ) ;
}
F_14 ( & V_80 . V_50 , & V_30 ) ;
if ( V_90 && V_90 -> V_8 && 0 < V_90 -> V_27 ) {
F_14 ( & V_90 -> V_50 , & V_30 ) ;
F_35 ( L_8 ) ;
}
if ( ! V_52 ) {
memset ( V_7 -> V_56 , 0 , F_13 ( V_7 ) ) ;
memset ( V_7 -> V_57 , 0 , F_13 ( V_7 ) ) ;
}
V_9 = V_7 -> V_97 -> V_98 ( V_7 , & V_30 , V_52 ) ;
if ( V_9 )
goto V_18;
V_7 -> V_99 = true ;
V_7 -> V_89 = 1 ;
V_18:
F_38 ( V_91 ) ;
return V_9 ;
}
static inline void F_39 ( struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_38 ( V_7 -> V_56 ) ;
V_7 -> V_56 = NULL ;
F_38 ( V_7 -> V_57 ) ;
V_7 -> V_57 = NULL ;
F_38 ( V_7 -> V_53 ) ;
V_7 -> V_53 = NULL ;
V_7 -> V_89 = 0 ;
#ifdef F_3
F_38 ( V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_7 -> V_12 = false ;
#endif
}
static inline int F_40 ( struct V_6 * V_7 )
{
int V_9 = - V_96 ;
unsigned int V_100 = 0 ;
V_7 -> V_56 = F_41 ( F_13 ( V_7 ) , V_95 ) ;
if ( ! V_7 -> V_56 )
goto V_101;
V_7 -> V_57 = F_41 ( F_13 ( V_7 ) , V_95 ) ;
if ( ! V_7 -> V_57 )
goto V_101;
#ifdef F_3
V_7 -> V_13 = F_41 ( F_4 ( V_7 ) , V_95 ) ;
if ( ! V_7 -> V_13 )
goto V_101;
V_7 -> V_12 = false ;
#endif
if ( V_7 -> V_94 -> V_1 & V_102 )
V_100 = 0 ;
else if ( V_7 -> V_94 -> V_1 & V_103 )
V_100 = F_13 ( V_7 ) + F_4 ( V_7 ) +
F_13 ( V_7 ) +
F_4 ( V_7 ) +
F_4 ( V_7 ) +
F_13 ( V_7 ) + F_4 ( V_7 ) ;
else
V_100 = F_13 ( V_7 ) + F_4 ( V_7 ) ;
if ( 0 < V_100 ) {
V_7 -> V_53 = F_36 ( V_100 , V_95 ) ;
if ( ! V_7 -> V_53 )
goto V_101;
}
F_42 ( & V_7 -> V_104 ) ;
return 0 ;
V_101:
F_39 ( V_7 ) ;
return V_9 ;
}
static inline void F_43 ( struct V_6 * V_84 ,
struct V_6 * V_69 )
{
if ( ! V_84 || ! V_69 )
return;
memcpy ( V_69 -> V_56 , V_84 -> V_56 , F_13 ( V_84 ) ) ;
memcpy ( V_69 -> V_57 , V_84 -> V_57 , F_13 ( V_84 ) ) ;
V_69 -> V_89 = V_84 -> V_89 ;
V_69 -> V_99 = V_84 -> V_99 ;
V_69 -> V_105 = V_84 -> V_105 ;
#ifdef F_3
V_69 -> V_12 = V_84 -> V_12 ;
memcpy ( V_69 -> V_13 , V_84 -> V_13 , F_4 ( V_84 ) ) ;
#endif
}
static int F_44 ( struct V_6 * V_7 , struct V_6 * * V_106 )
{
int V_9 = - V_96 ;
struct V_6 * V_79 = NULL ;
V_79 = F_36 ( sizeof( struct V_6 ) , V_95 ) ;
if ( ! V_79 )
return - V_96 ;
V_79 -> V_94 = V_7 -> V_94 ;
V_79 -> V_97 = V_7 -> V_97 ;
V_9 = F_40 ( V_79 ) ;
if ( V_9 )
goto V_101;
F_45 ( & V_7 -> V_104 ) ;
F_43 ( V_7 , V_79 ) ;
V_79 -> V_10 = V_7 -> V_10 ;
F_46 ( & V_7 -> V_104 ) ;
* V_106 = V_79 ;
return 0 ;
V_101:
F_38 ( V_79 ) ;
return V_9 ;
}
static void F_47 ( struct V_6 * V_7 ,
struct V_6 * * V_106 )
{
struct V_6 * V_79 = * V_106 ;
F_45 ( & V_7 -> V_104 ) ;
F_43 ( V_79 , V_7 ) ;
F_46 ( & V_7 -> V_104 ) ;
F_39 ( V_79 ) ;
F_38 ( V_79 ) ;
* V_106 = NULL ;
}
static int F_48 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_22 * V_59 )
{
int V_27 = 0 ;
struct V_6 * V_106 = NULL ;
F_12 ( V_107 ) ;
struct V_22 V_108 ;
union {
T_6 V_109 ;
unsigned char V_110 [ sizeof( T_6 ) ] ;
} V_111 ;
if ( 0 == V_58 || ! V_8 ) {
F_35 ( L_9 ) ;
return - V_49 ;
}
if ( V_59 && NULL == V_59 -> V_8 && 0 < V_59 -> V_27 ) {
F_35 ( L_10 ) ;
return - V_49 ;
}
V_27 = F_44 ( V_7 , & V_106 ) ;
if ( V_27 ) {
F_35 ( L_11 ) ;
return V_27 ;
}
V_27 = - V_49 ;
if ( V_58 > ( F_49 ( V_106 ) ) ) {
F_35 ( L_12 ,
V_58 ) ;
goto V_101;
}
if ( V_59 && V_59 -> V_27 > ( F_34 ( V_106 ) ) ) {
F_35 ( L_13 ,
V_59 -> V_27 ) ;
goto V_101;
}
if ( ( F_50 ( V_106 ) ) < V_106 -> V_89 )
V_106 -> V_99 = false ;
V_27 = V_106 -> V_97 -> V_112 ( V_106 ) ;
if ( V_27 )
goto V_101;
if ( V_106 -> V_105 || ! V_106 -> V_99 ) {
F_35 ( L_14
L_15 ,
V_7 -> V_105 ? L_16 : L_17 ,
V_7 -> V_99 ? L_18 : L_19 ) ;
V_27 = F_33 ( V_106 , V_59 , true ) ;
if ( V_27 )
goto V_101;
V_59 = NULL ;
}
if ( ! V_7 -> V_10 ) {
V_111 . V_109 = F_51 () ;
F_8 ( & V_108 , V_111 . V_110 , sizeof( T_6 ) ) ;
F_14 ( & V_108 . V_50 , & V_107 ) ;
}
if ( V_59 && 0 < V_59 -> V_27 )
F_14 ( & V_59 -> V_50 , & V_107 ) ;
V_27 = V_106 -> V_97 -> V_113 ( V_106 , V_8 , V_58 , & V_107 ) ;
V_106 -> V_89 ++ ;
if ( 0 >= V_27 )
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
F_47 ( V_7 , & V_106 ) ;
return V_27 ;
}
static int F_52 ( struct V_6 * V_7 ,
unsigned char * V_8 , unsigned int V_58 ,
struct V_22 * V_59 )
{
int V_27 = 0 ;
unsigned int V_115 = 0 ;
do {
int V_116 = 0 ;
unsigned int V_117 = 0 ;
V_115 = ( ( V_58 - V_27 ) / F_49 ( V_7 ) ) ;
V_117 = V_115 ? F_49 ( V_7 ) : ( V_58 - V_27 ) ;
V_116 = F_48 ( V_7 , V_8 + V_27 , V_117 , V_59 ) ;
if ( 0 >= V_116 )
return V_116 ;
V_27 += V_116 ;
} while ( V_115 > 0 && ( V_27 < V_58 ) );
return V_27 ;
}
static int F_53 ( struct V_6 * V_7 , struct V_22 * V_90 ,
int V_118 , bool V_105 )
{
int V_9 = - V_96 ;
F_35 ( L_20
L_21 , V_118 , V_105 ? L_22 : L_23 ) ;
V_7 -> V_94 = & V_119 [ V_118 ] ;
V_7 -> V_105 = V_105 ;
V_7 -> V_99 = false ;
switch ( V_7 -> V_94 -> V_1 & V_120 ) {
#ifdef F_54
case V_102 :
V_7 -> V_97 = & V_121 ;
break;
#endif
#ifdef F_55
case V_122 :
V_7 -> V_97 = & V_123 ;
break;
#endif
#ifdef F_56
case V_103 :
V_7 -> V_97 = & V_124 ;
break;
#endif
default:
return - V_125 ;
}
V_9 = F_40 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = - V_31 ;
if ( V_7 -> V_97 -> V_112 ( V_7 ) )
goto V_101;
V_9 = F_33 ( V_7 , V_90 , false ) ;
V_7 -> V_97 -> V_114 ( V_7 ) ;
if ( V_9 )
goto V_101;
return 0 ;
V_101:
F_39 ( V_7 ) ;
return V_9 ;
}
static int F_57 ( struct V_6 * V_7 )
{
F_45 ( & V_7 -> V_104 ) ;
F_39 ( V_7 ) ;
F_46 ( & V_7 -> V_104 ) ;
return 0 ;
}
static inline void F_58 ( struct V_6 * V_7 ,
struct V_126 * V_10 )
{
if ( ! V_10 || ! V_10 -> V_93 )
return;
F_45 ( & V_7 -> V_104 ) ;
V_7 -> V_10 = V_10 ;
F_46 ( & V_7 -> V_104 ) ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_127 * V_127 ;
struct V_128 * V_129 ;
V_129 = F_60 ( V_7 -> V_94 -> V_130 , 0 , 0 ) ;
if ( F_61 ( V_129 ) ) {
F_62 ( L_24 ) ;
return F_63 ( V_129 ) ;
}
F_64 ( F_4 ( V_7 ) != F_65 ( V_129 ) ) ;
V_127 = F_36 ( sizeof( struct V_131 ) + F_66 ( V_129 ) ,
V_95 ) ;
if ( ! V_127 ) {
F_67 ( V_129 ) ;
return - V_96 ;
}
V_127 -> V_132 . V_129 = V_129 ;
V_127 -> V_132 . V_1 = 0 ;
V_7 -> V_133 = V_127 ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 )
{
struct V_127 * V_127 = (struct V_127 * ) V_7 -> V_133 ;
if ( V_127 ) {
F_67 ( V_127 -> V_132 . V_129 ) ;
F_38 ( V_127 ) ;
}
V_7 -> V_133 = NULL ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , const unsigned char * V_19 ,
unsigned char * V_76 , const struct V_20 * V_21 )
{
struct V_127 * V_127 = (struct V_127 * ) V_7 -> V_133 ;
struct V_22 * V_78 = NULL ;
if ( V_19 )
F_69 ( V_127 -> V_132 . V_129 , V_19 , F_13 ( V_7 ) ) ;
F_70 ( & V_127 -> V_132 ) ;
F_9 (input, in, list)
F_71 ( & V_127 -> V_132 , V_78 -> V_8 , V_78 -> V_27 ) ;
return F_72 ( & V_127 -> V_132 , V_76 ) ;
}
static int F_73 ( struct V_6 * V_7 )
{
int V_9 = 0 ;
struct V_134 * V_129 ;
V_129 = F_74 ( V_7 -> V_94 -> V_130 , 0 , 0 ) ;
if ( F_61 ( V_129 ) ) {
F_62 ( L_25 ) ;
return F_63 ( V_129 ) ;
}
F_64 ( F_4 ( V_7 ) != F_75 ( V_129 ) ) ;
V_7 -> V_133 = V_129 ;
return V_9 ;
}
static int F_76 ( struct V_6 * V_7 )
{
struct V_134 * V_129 =
(struct V_134 * ) V_7 -> V_133 ;
if ( V_129 )
F_77 ( V_129 ) ;
V_7 -> V_133 = NULL ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , const unsigned char * V_19 ,
unsigned char * V_76 , const struct V_22 * V_21 )
{
int V_9 = 0 ;
struct V_135 V_136 , V_137 ;
struct V_138 V_139 ;
struct V_134 * V_129 =
(struct V_134 * ) V_7 -> V_133 ;
V_139 . V_129 = V_129 ;
V_139 . V_1 = 0 ;
F_78 ( V_129 , V_19 , ( F_16 ( V_7 ) ) ) ;
F_79 ( & V_136 , V_21 -> V_8 , V_21 -> V_27 ) ;
F_79 ( & V_137 , V_76 , F_4 ( V_7 ) ) ;
V_9 = F_80 ( & V_139 , & V_137 , & V_136 , V_21 -> V_27 ) ;
return V_9 ;
}
static inline void F_81 ( const char * V_140 ,
int * V_118 , bool * V_105 )
{
int V_43 = 0 ;
T_4 V_141 = 0 ;
int V_27 = 0 ;
* V_105 = true ;
if ( ! memcmp ( V_140 , L_26 , 10 ) ) {
V_141 = 10 ;
* V_105 = false ;
} else if ( ! memcmp ( V_140 , L_27 , 8 ) ) {
V_141 = 8 ;
} else {
return;
}
V_27 = strlen ( V_140 ) - V_141 ;
for ( V_43 = 0 ; F_82 ( V_119 ) > V_43 ; V_43 ++ ) {
if ( ! memcmp ( V_140 + V_141 , V_119 [ V_43 ] . V_142 ,
V_27 ) ) {
* V_118 = V_43 ;
return;
}
}
}
static int F_83 ( struct V_143 * V_129 )
{
struct V_6 * V_7 = F_84 ( V_129 ) ;
bool V_105 = false ;
int V_118 = 0 ;
F_81 ( F_85 ( V_129 ) , & V_118 , & V_105 ) ;
return F_53 ( V_7 , NULL , V_118 , V_105 ) ;
}
static void F_86 ( struct V_143 * V_129 )
{
F_57 ( F_84 ( V_129 ) ) ;
}
static int F_87 ( struct V_144 * V_129 , T_7 * V_145 ,
unsigned int V_146 )
{
struct V_6 * V_7 = F_88 ( V_129 ) ;
if ( 0 < V_146 ) {
return F_52 ( V_7 , V_145 , V_146 , NULL ) ;
} else {
struct V_147 * V_24 = (struct V_147 * ) V_145 ;
struct V_22 V_59 ;
if ( ! V_24 )
return 0 ;
F_58 ( V_7 , V_24 -> V_10 ) ;
F_8 ( & V_59 , V_24 -> V_59 -> V_8 , V_24 -> V_59 -> V_27 ) ;
return F_52 ( V_7 , V_24 -> V_148 , V_24 -> V_60 ,
& V_59 ) ;
}
}
static int F_89 ( struct V_144 * V_129 , T_7 * V_48 , unsigned int V_149 )
{
struct V_6 * V_7 = F_88 ( V_129 ) ;
struct V_143 * V_150 = F_90 ( V_129 ) ;
bool V_105 = false ;
struct V_22 V_151 ;
int V_118 = 0 ;
F_57 ( V_7 ) ;
F_81 ( F_85 ( V_150 ) , & V_118 ,
& V_105 ) ;
if ( 0 < V_149 ) {
F_8 ( & V_151 , V_48 , V_149 ) ;
return F_53 ( V_7 , & V_151 , V_118 , V_105 ) ;
} else {
struct V_147 * V_24 = (struct V_147 * ) V_48 ;
if ( ! V_24 )
return F_53 ( V_7 , NULL , V_118 , V_105 ) ;
F_58 ( V_7 , V_24 -> V_10 ) ;
F_8 ( & V_151 , V_24 -> V_59 -> V_8 ,
V_24 -> V_59 -> V_27 ) ;
return F_53 ( V_7 , & V_151 , V_118 , V_105 ) ;
}
}
static inline int T_8 F_91 ( void )
{
#ifdef F_3
int V_27 = 0 ;
#define F_92 16
unsigned char V_8 [ F_92 ] ;
struct V_6 * V_7 = NULL ;
int V_9 = - V_31 ;
int V_152 = - V_31 ;
bool V_105 = false ;
int V_118 = 0 ;
struct V_22 V_59 ;
T_4 V_153 , V_154 ;
if ( ! V_11 )
return 0 ;
#ifdef F_56
F_81 ( L_28 , & V_118 , & V_105 ) ;
#elif V_155 F_55
F_81 ( L_29 , & V_118 , & V_105 ) ;
#else
F_81 ( L_30 , & V_118 , & V_105 ) ;
#endif
V_7 = F_36 ( sizeof( struct V_6 ) , V_95 ) ;
if ( ! V_7 )
return - V_96 ;
V_9 = F_53 ( V_7 , NULL , V_118 , V_105 ) ;
if ( V_9 ) {
V_152 = V_9 ;
goto V_148;
}
V_153 = F_34 ( V_7 ) ;
V_154 = F_49 ( V_7 ) ;
F_8 ( & V_59 , V_8 , V_153 + 1 ) ;
V_27 = F_48 ( V_7 , V_8 , F_92 , & V_59 ) ;
F_64 ( 0 < V_27 ) ;
V_27 = F_48 ( V_7 , V_8 , ( V_154 + 1 ) , NULL ) ;
F_64 ( 0 < V_27 ) ;
F_57 ( V_7 ) ;
V_9 = F_53 ( V_7 , & V_59 , V_118 , V_105 ) ;
F_64 ( 0 == V_9 ) ;
V_152 = 0 ;
F_35 ( L_31
L_32 ) ;
F_57 ( V_7 ) ;
V_148:
F_38 ( V_7 ) ;
return V_152 ;
#else
return 0 ;
#endif
}
static inline void T_8 F_93 ( struct V_156 * V_157 ,
const struct V_158 * V_94 , int V_105 )
{
int V_26 = 0 ;
static int V_159 = 100 ;
memset ( V_157 , 0 , sizeof( struct V_156 ) ) ;
memcpy ( V_157 -> V_142 , L_33 , 6 ) ;
if ( V_105 ) {
memcpy ( V_157 -> V_140 , L_27 , 8 ) ;
V_26 = 8 ;
} else {
memcpy ( V_157 -> V_140 , L_26 , 10 ) ;
V_26 = 10 ;
}
memcpy ( V_157 -> V_140 + V_26 , V_94 -> V_142 ,
strlen ( V_94 -> V_142 ) ) ;
V_157 -> V_160 = V_159 ;
V_159 ++ ;
if ( V_11 )
V_157 -> V_160 += 200 ;
V_157 -> V_161 = V_162 ;
V_157 -> V_163 = sizeof( struct V_6 ) ;
V_157 -> V_164 = & V_165 ;
V_157 -> V_166 = V_167 ;
V_157 -> V_168 = F_83 ;
V_157 -> V_169 = F_86 ;
V_157 -> V_170 . V_171 . V_172 = F_87 ;
V_157 -> V_170 . V_171 . V_173 = F_89 ;
V_157 -> V_170 . V_171 . V_174 = 0 ;
}
static int T_8 F_94 ( void )
{
unsigned int V_43 = 0 ;
unsigned int V_175 = 0 ;
int V_9 = - V_31 ;
V_9 = F_91 () ;
if ( V_9 )
return V_9 ;
if ( F_82 ( V_119 ) * 2 > F_82 ( V_176 ) ) {
F_62 ( L_34
L_35 ,
F_82 ( V_119 ) * 2 , F_82 ( V_176 ) ) ;
return V_9 ;
}
for ( V_175 = 0 ; F_82 ( V_119 ) > V_175 ; V_175 ++ , V_43 ++ )
F_93 ( & V_176 [ V_43 ] , & V_119 [ V_175 ] , 1 ) ;
for ( V_175 = 0 ; F_82 ( V_119 ) > V_175 ; V_175 ++ , V_43 ++ )
F_93 ( & V_176 [ V_43 ] , & V_119 [ V_175 ] , 0 ) ;
return F_95 ( V_176 , ( F_82 ( V_119 ) * 2 ) ) ;
}
static void T_9 F_96 ( void )
{
F_97 ( V_176 , ( F_82 ( V_119 ) * 2 ) ) ;
}
