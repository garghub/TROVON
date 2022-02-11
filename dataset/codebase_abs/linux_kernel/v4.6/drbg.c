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
F_7 (curr, in, list) {
const unsigned char * V_22 = V_19 -> V_7 ;
T_4 V_23 = V_19 -> V_23 ;
while ( V_23 ) {
if ( F_6 ( V_12 ) == V_21 ) {
V_21 = 0 ;
V_17 = F_8 ( V_12 , V_14 , V_13 , & V_20 ) ;
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
V_17 = F_8 ( V_12 , V_14 , V_13 , & V_20 ) ;
return V_17 ;
}
static int F_9 ( struct V_11 * V_12 ,
unsigned char * V_24 , T_4 V_25 ,
struct V_15 * V_26 )
{
int V_17 = - V_27 ;
unsigned char V_28 [ 8 ] ;
struct V_18 V_29 , V_30 , V_31 , V_32 ;
F_10 ( V_33 ) ;
unsigned char * V_34 = V_24 + F_11 ( V_12 ) ;
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
F_7 (seed, seedlist, list)
V_43 += V_44 -> V_23 ;
F_2 ( V_43 , & V_28 [ 0 ] ) ;
F_2 ( V_25 , & V_28 [ 4 ] ) ;
V_37 = ( V_43 + sizeof( V_28 ) + 1 ) % ( F_6 ( V_12 ) ) ;
if ( V_37 )
V_37 = F_6 ( V_12 ) - V_37 ;
V_37 ++ ;
V_34 [ 0 ] = 0x80 ;
F_5 ( & V_29 , V_35 , F_6 ( V_12 ) ) ;
F_12 ( & V_29 . V_46 , & V_33 ) ;
F_5 ( & V_30 , V_28 , sizeof( V_28 ) ) ;
F_12 ( & V_30 . V_46 , & V_33 ) ;
F_13 ( V_26 , & V_33 ) ;
F_5 ( & V_31 , V_34 , V_37 ) ;
F_12 ( & V_31 . V_46 , & V_33 ) ;
while ( V_38 < ( F_14 ( V_12 ) + ( F_6 ( V_12 ) ) ) ) {
F_2 ( V_39 , V_35 ) ;
V_17 = F_4 ( V_12 , V_36 + V_38 , V_40 , & V_33 ) ;
if ( V_17 )
goto V_13;
V_39 ++ ;
V_38 += F_6 ( V_12 ) ;
}
V_41 = V_36 + ( F_14 ( V_12 ) ) ;
F_5 ( & V_32 , V_41 , F_6 ( V_12 ) ) ;
while ( V_42 < V_25 ) {
short V_47 = 0 ;
V_17 = F_8 ( V_12 , V_36 , V_41 , & V_32 ) ;
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
memset ( V_36 , 0 , F_11 ( V_12 ) + F_6 ( V_12 ) ) ;
memset ( V_34 , 0 , F_6 ( V_12 ) ) ;
return V_17 ;
}
static int F_15 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = - V_27 ;
unsigned char * V_36 = V_12 -> V_49 ;
unsigned char * V_24 = V_12 -> V_49 + F_11 ( V_12 ) +
F_6 ( V_12 ) ;
unsigned char * V_50 , * V_51 ;
unsigned int V_23 = 0 ;
struct V_18 V_32 ;
if ( 3 > V_48 )
memset ( V_24 , 0 , F_11 ( V_12 ) ) ;
if ( V_44 ) {
V_17 = F_9 ( V_12 , V_24 , F_11 ( V_12 ) , V_44 ) ;
if ( V_17 )
goto V_13;
}
F_5 ( & V_32 , V_12 -> V_52 , F_6 ( V_12 ) ) ;
while ( V_23 < ( F_11 ( V_12 ) ) ) {
F_16 ( V_12 -> V_52 , F_6 ( V_12 ) ) ;
V_17 = F_8 ( V_12 , V_12 -> V_53 , V_36 + V_23 , & V_32 ) ;
if ( V_17 )
goto V_13;
V_23 += F_6 ( V_12 ) ;
}
V_50 = V_36 ;
V_51 = V_24 ;
for ( V_23 = 0 ; V_23 < F_11 ( V_12 ) ; V_23 ++ ) {
* V_50 ^= * V_51 ;
V_51 ++ ; V_50 ++ ;
}
memcpy ( V_12 -> V_53 , V_36 , F_14 ( V_12 ) ) ;
memcpy ( V_12 -> V_52 , V_36 + F_14 ( V_12 ) , F_6 ( V_12 ) ) ;
V_17 = 0 ;
V_13:
memset ( V_36 , 0 , F_11 ( V_12 ) + F_6 ( V_12 ) ) ;
if ( 2 != V_48 )
memset ( V_24 , 0 , F_11 ( V_12 ) ) ;
return V_17 ;
}
static int F_17 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_54 ,
struct V_15 * V_55 )
{
int V_23 = 0 ;
int V_17 = 0 ;
struct V_18 V_20 ;
if ( V_55 && ! F_18 ( V_55 ) ) {
V_17 = F_15 ( V_12 , V_55 , 2 ) ;
if ( V_17 )
return 0 ;
}
F_16 ( V_12 -> V_52 , F_6 ( V_12 ) ) ;
F_5 ( & V_20 , V_12 -> V_52 , F_6 ( V_12 ) ) ;
while ( V_23 < V_54 ) {
int V_56 = 0 ;
V_17 = F_8 ( V_12 , V_12 -> V_53 , V_12 -> V_49 , & V_20 ) ;
if ( V_17 ) {
V_23 = V_17 ;
goto V_13;
}
V_56 = ( F_6 ( V_12 ) < ( V_54 - V_23 ) ) ?
F_6 ( V_12 ) : ( V_54 - V_23 ) ;
memcpy ( V_7 + V_23 , V_12 -> V_49 , V_56 ) ;
V_23 += V_56 ;
if ( V_23 < V_54 )
F_16 ( V_12 -> V_52 , F_6 ( V_12 ) ) ;
}
V_17 = F_15 ( V_12 , NULL , 3 ) ;
if ( V_17 )
V_23 = V_17 ;
V_13:
memset ( V_12 -> V_49 , 0 , F_6 ( V_12 ) ) ;
return V_23 ;
}
static int F_19 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = - V_27 ;
int V_39 = 0 ;
struct V_18 V_57 , V_58 , V_59 ;
F_10 ( V_26 ) ;
F_10 ( V_60 ) ;
if ( ! V_48 )
memset ( V_12 -> V_52 , 1 , F_11 ( V_12 ) ) ;
F_5 ( & V_57 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_12 ( & V_57 . V_46 , & V_26 ) ;
F_5 ( & V_58 , NULL , 1 ) ;
F_12 ( & V_58 . V_46 , & V_26 ) ;
if ( V_44 )
F_13 ( V_44 , & V_26 ) ;
F_5 ( & V_59 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_12 ( & V_59 . V_46 , & V_60 ) ;
for ( V_39 = 2 ; 0 < V_39 ; V_39 -- ) {
unsigned char V_61 = V_62 ;
if ( 1 == V_39 )
V_61 = V_63 ;
V_58 . V_7 = & V_61 ;
V_17 = F_20 ( V_12 , V_12 -> V_53 , V_12 -> V_53 , & V_26 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_20 ( V_12 , V_12 -> V_53 , V_12 -> V_52 , & V_60 ) ;
if ( V_17 )
return V_17 ;
if ( ! V_44 )
return V_17 ;
}
return 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
unsigned char * V_7 ,
unsigned int V_54 ,
struct V_15 * V_55 )
{
int V_23 = 0 ;
int V_17 = 0 ;
struct V_18 V_20 ;
F_10 ( V_64 ) ;
if ( V_55 && ! F_18 ( V_55 ) ) {
V_17 = F_19 ( V_12 , V_55 , 1 ) ;
if ( V_17 )
return V_17 ;
}
F_5 ( & V_20 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_12 ( & V_20 . V_46 , & V_64 ) ;
while ( V_23 < V_54 ) {
unsigned int V_56 = 0 ;
V_17 = F_20 ( V_12 , V_12 -> V_53 , V_12 -> V_52 , & V_64 ) ;
if ( V_17 )
return V_17 ;
V_56 = ( F_6 ( V_12 ) < ( V_54 - V_23 ) ) ?
F_6 ( V_12 ) : ( V_54 - V_23 ) ;
memcpy ( V_7 + V_23 , V_12 -> V_52 , V_56 ) ;
V_23 += V_56 ;
}
if ( V_55 && ! F_18 ( V_55 ) )
V_17 = F_19 ( V_12 , V_55 , 1 ) ;
else
V_17 = F_19 ( V_12 , NULL , 1 ) ;
if ( V_17 )
return V_17 ;
return V_23 ;
}
static inline void F_22 ( unsigned char * V_65 , T_4 V_66 ,
const unsigned char * V_67 , T_4 V_68 )
{
unsigned char * V_69 ;
const unsigned char * V_70 ;
unsigned int V_71 = 0 ;
T_4 V_23 = V_68 ;
V_69 = V_65 + ( V_66 - 1 ) ;
V_70 = V_67 + ( V_68 - 1 ) ;
while ( V_23 ) {
V_71 += * V_69 + * V_70 ;
* V_69 = V_71 & 0xff ;
V_71 >>= 8 ;
V_23 -- ; V_69 -- ; V_70 -- ;
}
V_23 = V_66 - V_68 ;
while ( V_23 && V_71 > 0 ) {
V_71 = * V_69 + 1 ;
* V_69 = V_71 & 0xff ;
V_71 >>= 8 ;
V_23 -- ; V_69 -- ;
}
}
static int F_23 ( struct V_11 * V_12 ,
unsigned char * V_72 , T_4 V_56 ,
struct V_15 * V_73 )
{
int V_17 = 0 ;
T_4 V_23 = 0 ;
unsigned char V_74 [ 5 ] ;
unsigned char * V_75 = V_12 -> V_49 + F_11 ( V_12 ) ;
struct V_18 V_20 ;
V_74 [ 0 ] = 1 ;
F_2 ( ( V_56 * 8 ) , & V_74 [ 1 ] ) ;
F_5 ( & V_20 , V_74 , 5 ) ;
F_24 ( & V_20 . V_46 , V_73 ) ;
while ( V_23 < V_56 ) {
short V_47 = 0 ;
V_17 = F_20 ( V_12 , NULL , V_75 , V_73 ) ;
if ( V_17 )
goto V_13;
V_74 [ 0 ] ++ ;
V_47 = ( F_6 ( V_12 ) < ( V_56 - V_23 ) ) ?
F_6 ( V_12 ) : ( V_56 - V_23 ) ;
memcpy ( V_72 + V_23 , V_75 , V_47 ) ;
V_23 += V_47 ;
}
V_13:
memset ( V_75 , 0 , F_6 ( V_12 ) ) ;
return V_17 ;
}
static int F_25 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = 0 ;
struct V_18 V_76 , V_77 ;
F_10 ( V_64 ) ;
F_10 ( V_78 ) ;
unsigned char * V_52 = V_12 -> V_49 ;
unsigned char V_61 = V_63 ;
if ( ! V_44 )
return - V_45 ;
if ( V_48 ) {
memcpy ( V_52 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_5 ( & V_76 , & V_61 , 1 ) ;
F_12 ( & V_76 . V_46 , & V_64 ) ;
F_5 ( & V_77 , V_52 , F_11 ( V_12 ) ) ;
F_12 ( & V_77 . V_46 , & V_64 ) ;
}
F_13 ( V_44 , & V_64 ) ;
V_17 = F_23 ( V_12 , V_12 -> V_52 , F_11 ( V_12 ) , & V_64 ) ;
if ( V_17 )
goto V_13;
V_61 = V_62 ;
F_5 ( & V_76 , & V_61 , 1 ) ;
F_12 ( & V_76 . V_46 , & V_78 ) ;
F_5 ( & V_77 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_12 ( & V_77 . V_46 , & V_78 ) ;
V_17 = F_23 ( V_12 , V_12 -> V_53 , F_11 ( V_12 ) , & V_78 ) ;
V_13:
memset ( V_12 -> V_49 , 0 , F_11 ( V_12 ) ) ;
return V_17 ;
}
static int F_26 ( struct V_11 * V_12 ,
struct V_15 * V_55 )
{
int V_17 = 0 ;
struct V_18 V_76 , V_77 ;
F_10 ( V_64 ) ;
unsigned char V_61 = V_79 ;
if ( ! V_55 || F_18 ( V_55 ) )
return 0 ;
F_5 ( & V_76 , & V_61 , 1 ) ;
F_5 ( & V_77 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_12 ( & V_76 . V_46 , & V_64 ) ;
F_12 ( & V_77 . V_46 , & V_64 ) ;
F_13 ( V_55 , & V_64 ) ;
V_17 = F_20 ( V_12 , NULL , V_12 -> V_49 , & V_64 ) ;
if ( V_17 )
goto V_13;
F_22 ( V_12 -> V_52 , F_11 ( V_12 ) ,
V_12 -> V_49 , F_6 ( V_12 ) ) ;
V_13:
memset ( V_12 -> V_49 , 0 , F_6 ( V_12 ) ) ;
return V_17 ;
}
static int F_27 ( struct V_11 * V_12 ,
unsigned char * V_7 ,
unsigned int V_54 )
{
int V_23 = 0 ;
int V_17 = 0 ;
unsigned char * V_80 = V_12 -> V_49 ;
unsigned char * V_65 = V_12 -> V_49 + F_11 ( V_12 ) ;
struct V_18 V_20 ;
F_10 ( V_64 ) ;
memcpy ( V_80 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_5 ( & V_20 , V_80 , F_11 ( V_12 ) ) ;
F_12 ( & V_20 . V_46 , & V_64 ) ;
while ( V_23 < V_54 ) {
unsigned int V_56 = 0 ;
V_17 = F_20 ( V_12 , NULL , V_65 , & V_64 ) ;
if ( V_17 ) {
V_23 = V_17 ;
goto V_13;
}
V_56 = ( F_6 ( V_12 ) < ( V_54 - V_23 ) ) ?
F_6 ( V_12 ) : ( V_54 - V_23 ) ;
memcpy ( V_7 + V_23 , V_65 , V_56 ) ;
V_23 += V_56 ;
if ( V_23 < V_54 )
F_16 ( V_80 , F_11 ( V_12 ) ) ;
}
V_13:
memset ( V_12 -> V_49 , 0 ,
( F_11 ( V_12 ) + F_6 ( V_12 ) ) ) ;
return V_23 ;
}
static int F_28 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_54 ,
struct V_15 * V_55 )
{
int V_23 = 0 ;
int V_17 = 0 ;
union {
unsigned char V_81 [ 8 ] ;
T_5 V_82 ;
} V_83 ;
unsigned char V_61 = V_84 ;
struct V_18 V_76 , V_77 ;
F_10 ( V_64 ) ;
V_17 = F_26 ( V_12 , V_55 ) ;
if ( V_17 )
return V_17 ;
V_23 = F_27 ( V_12 , V_7 , V_54 ) ;
F_5 ( & V_76 , & V_61 , 1 ) ;
F_12 ( & V_76 . V_46 , & V_64 ) ;
F_5 ( & V_77 , V_12 -> V_52 , F_11 ( V_12 ) ) ;
F_12 ( & V_77 . V_46 , & V_64 ) ;
V_17 = F_20 ( V_12 , NULL , V_12 -> V_49 , & V_64 ) ;
if ( V_17 ) {
V_23 = V_17 ;
goto V_13;
}
F_22 ( V_12 -> V_52 , F_11 ( V_12 ) ,
V_12 -> V_49 , F_6 ( V_12 ) ) ;
F_22 ( V_12 -> V_52 , F_11 ( V_12 ) ,
V_12 -> V_53 , F_11 ( V_12 ) ) ;
V_83 . V_82 = F_29 ( V_12 -> V_85 ) ;
F_22 ( V_12 -> V_52 , F_11 ( V_12 ) , V_83 . V_81 , 8 ) ;
V_13:
memset ( V_12 -> V_49 , 0 , F_6 ( V_12 ) ) ;
return V_23 ;
}
static inline int F_30 ( struct V_11 * V_12 , struct V_15 * V_44 ,
int V_48 )
{
int V_17 = V_12 -> V_86 -> V_87 ( V_12 , V_44 , V_48 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_88 = true ;
V_12 -> V_85 = 1 ;
return V_17 ;
}
static void F_31 ( struct V_89 * V_90 )
{
struct V_18 V_20 ;
F_10 ( V_26 ) ;
struct V_11 * V_12 = F_32 ( V_90 , struct V_11 ,
V_91 ) ;
unsigned int V_92 = F_1 ( V_12 -> V_93 -> V_1 ) ;
unsigned char V_94 [ 32 ] ;
F_33 ( ! V_92 ) ;
F_33 ( V_92 > sizeof( V_94 ) ) ;
F_34 ( V_94 , V_92 ) ;
F_5 ( & V_20 , V_94 , V_92 ) ;
F_12 ( & V_20 . V_46 , & V_26 ) ;
F_35 ( & V_12 -> V_95 ) ;
F_36 ( V_12 -> V_96 ) ;
V_12 -> V_96 = NULL ;
V_12 -> V_88 = false ;
F_30 ( V_12 , & V_26 , true ) ;
if ( V_12 -> V_88 )
V_12 -> V_97 = F_37 ( V_12 ) ;
F_38 ( & V_12 -> V_95 ) ;
F_39 ( V_94 , V_92 ) ;
}
static int F_40 ( struct V_11 * V_12 , struct V_18 * V_98 ,
bool V_48 )
{
int V_17 ;
unsigned char V_94 [ ( ( 32 + 16 ) * 2 ) ] ;
unsigned int V_92 = F_1 ( V_12 -> V_93 -> V_1 ) ;
struct V_18 V_76 ;
F_10 ( V_26 ) ;
if ( V_98 && V_98 -> V_23 > ( F_41 ( V_12 ) ) ) {
F_42 ( L_5 ,
V_98 -> V_23 ) ;
return - V_45 ;
}
if ( F_18 ( & V_12 -> V_99 . V_46 ) ) {
F_5 ( & V_76 , V_12 -> V_99 . V_7 ,
V_12 -> V_99 . V_23 ) ;
F_42 ( L_6 ) ;
} else {
F_33 ( ! V_92 ) ;
if ( ! V_48 )
V_92 = ( ( V_92 + 1 ) / 2 ) * 3 ;
F_33 ( ( V_92 * 2 ) > sizeof( V_94 ) ) ;
F_34 ( V_94 , V_92 ) ;
if ( ! V_12 -> V_96 ) {
F_5 ( & V_76 , V_94 , V_92 ) ;
F_42 ( L_7 ,
V_92 ) ;
} else {
V_17 = F_43 ( V_12 -> V_96 ,
V_94 + V_92 ,
V_92 ) ;
if ( V_17 ) {
F_42 ( L_8 , V_17 ) ;
return V_17 ;
}
F_5 ( & V_76 , V_94 , V_92 * 2 ) ;
F_42 ( L_7 ,
V_92 * 2 ) ;
}
}
F_12 ( & V_76 . V_46 , & V_26 ) ;
if ( V_98 && V_98 -> V_7 && 0 < V_98 -> V_23 ) {
F_12 ( & V_98 -> V_46 , & V_26 ) ;
F_42 ( L_9 ) ;
}
if ( ! V_48 ) {
memset ( V_12 -> V_52 , 0 , F_11 ( V_12 ) ) ;
memset ( V_12 -> V_53 , 0 , F_11 ( V_12 ) ) ;
}
V_17 = F_30 ( V_12 , & V_26 , V_48 ) ;
F_39 ( V_94 , V_92 * 2 ) ;
return V_17 ;
}
static inline void F_44 ( struct V_11 * V_12 )
{
if ( ! V_12 )
return;
F_45 ( V_12 -> V_52 ) ;
V_12 -> V_52 = NULL ;
F_45 ( V_12 -> V_53 ) ;
V_12 -> V_53 = NULL ;
F_45 ( V_12 -> V_49 ) ;
V_12 -> V_49 = NULL ;
V_12 -> V_85 = 0 ;
V_12 -> V_86 = NULL ;
V_12 -> V_93 = NULL ;
}
static inline int F_46 ( struct V_11 * V_12 )
{
int V_17 = - V_100 ;
unsigned int V_101 = 0 ;
switch ( V_12 -> V_93 -> V_1 & V_102 ) {
#ifdef F_47
case V_103 :
V_12 -> V_86 = & V_104 ;
break;
#endif
#ifdef F_48
case V_105 :
V_12 -> V_86 = & V_106 ;
break;
#endif
#ifdef F_49
case V_107 :
V_12 -> V_86 = & V_108 ;
break;
#endif
default:
V_17 = - V_109 ;
goto V_110;
}
V_12 -> V_52 = F_50 ( F_11 ( V_12 ) , V_111 ) ;
if ( ! V_12 -> V_52 )
goto V_110;
V_12 -> V_53 = F_50 ( F_11 ( V_12 ) , V_111 ) ;
if ( ! V_12 -> V_53 )
goto V_110;
if ( V_12 -> V_93 -> V_1 & V_103 )
V_101 = 0 ;
else if ( V_12 -> V_93 -> V_1 & V_107 )
V_101 = F_11 ( V_12 ) + F_6 ( V_12 ) +
F_11 ( V_12 ) +
F_6 ( V_12 ) +
F_6 ( V_12 ) +
F_11 ( V_12 ) + F_6 ( V_12 ) ;
else
V_101 = F_11 ( V_12 ) + F_6 ( V_12 ) ;
if ( 0 < V_101 ) {
V_12 -> V_49 = F_51 ( V_101 , V_111 ) ;
if ( ! V_12 -> V_49 )
goto V_110;
}
return 0 ;
V_110:
F_44 ( V_12 ) ;
return V_17 ;
}
static int F_52 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_54 ,
struct V_18 * V_55 )
{
int V_23 = 0 ;
F_10 ( V_112 ) ;
if ( ! V_12 -> V_93 ) {
F_42 ( L_10 ) ;
return - V_45 ;
}
if ( 0 == V_54 || ! V_7 ) {
F_42 ( L_11 ) ;
return - V_45 ;
}
if ( V_55 && NULL == V_55 -> V_7 && 0 < V_55 -> V_23 ) {
F_42 ( L_12 ) ;
return - V_45 ;
}
V_23 = - V_45 ;
if ( V_54 > ( F_53 ( V_12 ) ) ) {
F_42 ( L_13 ,
V_54 ) ;
goto V_110;
}
if ( V_55 && V_55 -> V_23 > ( F_41 ( V_12 ) ) ) {
F_42 ( L_14 ,
V_55 -> V_23 ) ;
goto V_110;
}
if ( V_12 -> V_97 < V_12 -> V_85 )
V_12 -> V_88 = false ;
if ( V_12 -> V_113 || ! V_12 -> V_88 ) {
F_42 ( L_15
L_16 ,
V_12 -> V_113 ? L_17 : L_18 ,
V_12 -> V_88 ? L_19 : L_20 ) ;
V_23 = F_40 ( V_12 , V_55 , true ) ;
if ( V_23 )
goto V_110;
V_55 = NULL ;
}
if ( V_55 && 0 < V_55 -> V_23 )
F_12 ( & V_55 -> V_46 , & V_112 ) ;
V_23 = V_12 -> V_86 -> V_114 ( V_12 , V_7 , V_54 , & V_112 ) ;
V_12 -> V_85 ++ ;
if ( 0 >= V_23 )
goto V_110;
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
V_110:
return V_23 ;
}
static int F_54 ( struct V_11 * V_12 ,
unsigned char * V_7 , unsigned int V_54 ,
struct V_18 * V_55 )
{
unsigned int V_23 = 0 ;
unsigned int V_115 = 0 ;
do {
int V_110 = 0 ;
unsigned int V_116 = 0 ;
V_115 = ( ( V_54 - V_23 ) / F_53 ( V_12 ) ) ;
V_116 = V_115 ? F_53 ( V_12 ) : ( V_54 - V_23 ) ;
F_35 ( & V_12 -> V_95 ) ;
V_110 = F_52 ( V_12 , V_7 + V_23 , V_116 , V_55 ) ;
F_38 ( & V_12 -> V_95 ) ;
if ( 0 > V_110 )
return V_110 ;
V_23 += V_116 ;
} while ( V_115 > 0 && ( V_23 < V_54 ) );
return 0 ;
}
static void F_55 ( struct V_117 * V_118 )
{
struct V_11 * V_12 = F_32 ( V_118 , struct V_11 ,
V_119 ) ;
F_56 ( & V_12 -> V_91 ) ;
}
static int F_57 ( struct V_11 * V_12 )
{
int V_110 ;
if ( F_18 ( & V_12 -> V_99 . V_46 ) )
return 0 ;
F_58 ( & V_12 -> V_91 , F_31 ) ;
V_12 -> V_119 . V_120 = V_121 ;
V_12 -> V_119 . V_122 = F_55 ;
V_110 = F_59 ( & V_12 -> V_119 ) ;
switch ( V_110 ) {
case 0 :
break;
case - V_123 :
V_110 = 0 ;
default:
V_12 -> V_119 . V_122 = NULL ;
return V_110 ;
}
V_12 -> V_96 = F_60 ( L_21 , 0 , 0 ) ;
V_12 -> V_97 = 50 ;
return V_110 ;
}
static int F_61 ( struct V_11 * V_12 , struct V_18 * V_98 ,
int V_124 , bool V_113 )
{
int V_17 ;
bool V_48 = true ;
F_42 ( L_22
L_23 , V_124 , V_113 ? L_24 : L_25 ) ;
F_35 ( & V_12 -> V_95 ) ;
if ( ! V_12 -> V_93 ) {
V_12 -> V_93 = & V_125 [ V_124 ] ;
V_12 -> V_113 = V_113 ;
V_12 -> V_88 = false ;
V_12 -> V_97 = F_37 ( V_12 ) ;
V_17 = F_46 ( V_12 ) ;
if ( V_17 )
goto V_126;
V_17 = - V_27 ;
if ( V_12 -> V_86 -> V_127 ( V_12 ) )
goto V_110;
V_17 = F_57 ( V_12 ) ;
if ( V_17 )
goto V_128;
if ( F_62 ( V_12 -> V_96 ) ) {
V_17 = F_63 ( V_12 -> V_96 ) ;
V_12 -> V_96 = NULL ;
if ( V_129 || V_17 != - V_130 )
goto V_128;
F_64 ( L_26 ) ;
}
V_48 = false ;
}
V_17 = F_40 ( V_12 , V_98 , V_48 ) ;
if ( V_17 && ! V_48 )
goto V_128;
F_38 ( & V_12 -> V_95 ) ;
return V_17 ;
V_110:
F_44 ( V_12 ) ;
V_126:
F_38 ( & V_12 -> V_95 ) ;
return V_17 ;
V_128:
F_38 ( & V_12 -> V_95 ) ;
F_65 ( V_12 ) ;
return V_17 ;
}
static int F_65 ( struct V_11 * V_12 )
{
if ( V_12 -> V_119 . V_122 ) {
F_66 ( & V_12 -> V_119 ) ;
F_67 ( & V_12 -> V_91 ) ;
F_36 ( V_12 -> V_96 ) ;
V_12 -> V_96 = NULL ;
}
if ( V_12 -> V_86 )
V_12 -> V_86 -> V_131 ( V_12 ) ;
F_44 ( V_12 ) ;
return 0 ;
}
static void F_68 ( struct V_132 * V_133 ,
const T_6 * V_20 , unsigned int V_23 )
{
struct V_11 * V_12 = F_69 ( V_133 ) ;
F_35 ( & V_12 -> V_95 ) ;
F_5 ( & V_12 -> V_99 , V_20 , V_23 ) ;
F_38 ( & V_12 -> V_95 ) ;
}
static int F_70 ( struct V_11 * V_12 )
{
struct V_134 * V_134 ;
struct V_135 * V_133 ;
V_133 = F_71 ( V_12 -> V_93 -> V_136 , 0 , 0 ) ;
if ( F_62 ( V_133 ) ) {
F_64 ( L_27 ,
V_12 -> V_93 -> V_136 ) ;
return F_63 ( V_133 ) ;
}
F_33 ( F_6 ( V_12 ) != F_72 ( V_133 ) ) ;
V_134 = F_51 ( sizeof( struct V_137 ) + F_73 ( V_133 ) ,
V_111 ) ;
if ( ! V_134 ) {
F_74 ( V_133 ) ;
return - V_100 ;
}
V_134 -> V_138 . V_133 = V_133 ;
V_134 -> V_138 . V_1 = 0 ;
V_12 -> V_139 = V_134 ;
return 0 ;
}
static int F_75 ( struct V_11 * V_12 )
{
struct V_134 * V_134 = (struct V_134 * ) V_12 -> V_139 ;
if ( V_134 ) {
F_74 ( V_134 -> V_138 . V_133 ) ;
F_45 ( V_134 ) ;
}
V_12 -> V_139 = NULL ;
return 0 ;
}
static int F_20 ( struct V_11 * V_12 , const unsigned char * V_14 ,
unsigned char * V_72 , const struct V_15 * V_16 )
{
struct V_134 * V_134 = (struct V_134 * ) V_12 -> V_139 ;
struct V_18 * V_74 = NULL ;
if ( V_14 )
F_76 ( V_134 -> V_138 . V_133 , V_14 , F_11 ( V_12 ) ) ;
F_77 ( & V_134 -> V_138 ) ;
F_7 (input, in, list)
F_78 ( & V_134 -> V_138 , V_74 -> V_7 , V_74 -> V_23 ) ;
return F_79 ( & V_134 -> V_138 , V_72 ) ;
}
static int F_80 ( struct V_11 * V_12 )
{
int V_17 = 0 ;
struct V_140 * V_133 ;
V_133 = F_81 ( V_12 -> V_93 -> V_136 , 0 , 0 ) ;
if ( F_62 ( V_133 ) ) {
F_64 ( L_28 ,
V_12 -> V_93 -> V_136 ) ;
return F_63 ( V_133 ) ;
}
F_33 ( F_6 ( V_12 ) != F_82 ( V_133 ) ) ;
V_12 -> V_139 = V_133 ;
return V_17 ;
}
static int F_83 ( struct V_11 * V_12 )
{
struct V_140 * V_133 =
(struct V_140 * ) V_12 -> V_139 ;
if ( V_133 )
F_84 ( V_133 ) ;
V_12 -> V_139 = NULL ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 , const unsigned char * V_14 ,
unsigned char * V_72 , const struct V_18 * V_16 )
{
struct V_140 * V_133 =
(struct V_140 * ) V_12 -> V_139 ;
F_85 ( V_133 , V_14 , ( F_14 ( V_12 ) ) ) ;
F_33 ( V_16 -> V_23 < F_6 ( V_12 ) ) ;
F_86 ( V_133 , V_72 , V_16 -> V_7 ) ;
return 0 ;
}
static inline void F_87 ( const char * V_141 ,
int * V_124 , bool * V_113 )
{
int V_39 = 0 ;
T_4 V_142 = 0 ;
int V_23 = 0 ;
* V_113 = true ;
if ( ! memcmp ( V_141 , L_29 , 10 ) ) {
V_142 = 10 ;
* V_113 = false ;
} else if ( ! memcmp ( V_141 , L_30 , 8 ) ) {
V_142 = 8 ;
} else {
return;
}
V_23 = strlen ( V_141 ) - V_142 ;
for ( V_39 = 0 ; F_88 ( V_125 ) > V_39 ; V_39 ++ ) {
if ( ! memcmp ( V_141 + V_142 , V_125 [ V_39 ] . V_143 ,
V_23 ) ) {
* V_124 = V_39 ;
return;
}
}
}
static int F_89 ( struct V_144 * V_133 )
{
struct V_11 * V_12 = F_90 ( V_133 ) ;
F_91 ( & V_12 -> V_95 ) ;
return 0 ;
}
static void F_92 ( struct V_144 * V_133 )
{
F_65 ( F_90 ( V_133 ) ) ;
}
static int F_93 ( struct V_132 * V_133 ,
const T_6 * V_80 , unsigned int V_145 ,
T_6 * V_65 , unsigned int V_146 )
{
struct V_11 * V_12 = F_69 ( V_133 ) ;
struct V_18 * V_55 = NULL ;
struct V_18 string ;
if ( V_145 ) {
F_5 ( & string , V_80 , V_145 ) ;
V_55 = & string ;
}
return F_54 ( V_12 , V_65 , V_146 , V_55 ) ;
}
static int F_94 ( struct V_132 * V_133 ,
const T_6 * V_44 , unsigned int V_145 )
{
struct V_11 * V_12 = F_69 ( V_133 ) ;
struct V_144 * V_147 = F_95 ( V_133 ) ;
bool V_113 = false ;
struct V_18 string ;
struct V_18 * V_148 = NULL ;
int V_124 = 0 ;
F_87 ( F_96 ( V_147 ) , & V_124 ,
& V_113 ) ;
if ( 0 < V_145 ) {
F_5 ( & string , V_44 , V_145 ) ;
V_148 = & string ;
}
return F_61 ( V_12 , V_148 , V_124 , V_113 ) ;
}
static inline int T_7 F_97 ( void )
{
int V_23 = 0 ;
#define F_98 16
unsigned char V_7 [ F_98 ] ;
struct V_11 * V_12 = NULL ;
int V_17 = - V_27 ;
int V_149 = - V_27 ;
bool V_113 = false ;
int V_124 = 0 ;
struct V_18 V_55 ;
T_4 V_150 , V_151 ;
if ( ! V_129 )
return 0 ;
#ifdef F_49
F_87 ( L_31 , & V_124 , & V_113 ) ;
#elif V_152 F_48
F_87 ( L_32 , & V_124 , & V_113 ) ;
#else
F_87 ( L_33 , & V_124 , & V_113 ) ;
#endif
V_12 = F_51 ( sizeof( struct V_11 ) , V_111 ) ;
if ( ! V_12 )
return - V_100 ;
F_91 ( & V_12 -> V_95 ) ;
V_17 = F_61 ( V_12 , NULL , V_124 , V_113 ) ;
if ( V_17 ) {
V_149 = V_17 ;
goto V_153;
}
V_150 = F_41 ( V_12 ) ;
V_151 = F_53 ( V_12 ) ;
F_5 ( & V_55 , V_7 , V_150 + 1 ) ;
V_23 = F_52 ( V_12 , V_7 , F_98 , & V_55 ) ;
F_33 ( 0 < V_23 ) ;
V_23 = F_52 ( V_12 , V_7 , ( V_151 + 1 ) , NULL ) ;
F_33 ( 0 < V_23 ) ;
F_65 ( V_12 ) ;
V_17 = F_61 ( V_12 , & V_55 , V_124 , V_113 ) ;
F_33 ( 0 == V_17 ) ;
V_149 = 0 ;
F_42 ( L_34
L_35 ) ;
F_65 ( V_12 ) ;
V_153:
F_45 ( V_12 ) ;
return V_149 ;
}
static inline void T_7 F_99 ( struct V_154 * V_155 ,
const struct V_156 * V_93 , int V_113 )
{
int V_22 = 0 ;
static int V_157 = 200 ;
memcpy ( V_155 -> V_158 . V_143 , L_36 , 6 ) ;
if ( V_113 ) {
memcpy ( V_155 -> V_158 . V_141 , L_30 , 8 ) ;
V_22 = 8 ;
} else {
memcpy ( V_155 -> V_158 . V_141 , L_29 , 10 ) ;
V_22 = 10 ;
}
memcpy ( V_155 -> V_158 . V_141 + V_22 , V_93 -> V_143 ,
strlen ( V_93 -> V_143 ) ) ;
V_155 -> V_158 . V_159 = V_157 ;
V_157 ++ ;
if ( V_129 )
V_155 -> V_158 . V_159 += 200 ;
V_155 -> V_158 . V_160 = sizeof( struct V_11 ) ;
V_155 -> V_158 . V_161 = V_121 ;
V_155 -> V_158 . V_162 = F_89 ;
V_155 -> V_158 . V_163 = F_92 ;
V_155 -> V_114 = F_93 ;
V_155 -> V_44 = F_94 ;
V_155 -> V_164 = F_68 ;
V_155 -> V_165 = 0 ;
}
static int T_7 F_100 ( void )
{
unsigned int V_39 = 0 ;
unsigned int V_166 = 0 ;
int V_17 = - V_27 ;
V_17 = F_97 () ;
if ( V_17 )
return V_17 ;
if ( F_88 ( V_125 ) * 2 > F_88 ( V_167 ) ) {
F_64 ( L_37
L_38 ,
F_88 ( V_125 ) * 2 , F_88 ( V_167 ) ) ;
return V_17 ;
}
for ( V_166 = 0 ; F_88 ( V_125 ) > V_166 ; V_166 ++ , V_39 ++ )
F_99 ( & V_167 [ V_39 ] , & V_125 [ V_166 ] , 1 ) ;
for ( V_166 = 0 ; F_88 ( V_125 ) > V_166 ; V_166 ++ , V_39 ++ )
F_99 ( & V_167 [ V_39 ] , & V_125 [ V_166 ] , 0 ) ;
return F_101 ( V_167 , ( F_88 ( V_125 ) * 2 ) ) ;
}
static void T_8 F_102 ( void )
{
F_103 ( V_167 , ( F_88 ( V_125 ) * 2 ) ) ;
}
