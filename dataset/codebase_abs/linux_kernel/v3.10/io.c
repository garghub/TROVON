static void F_1 ( struct V_1 * V_1 , int error )
{
struct V_1 * V_2 = V_1 -> V_3 ;
F_2 ( V_2 , error ) ;
F_3 ( V_1 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
if ( V_1 -> V_4 ) {
struct V_1 * V_5 = F_5 ( V_6 , F_6 ( V_1 ) ) ;
memcpy ( V_5 -> V_7 ,
F_7 ( V_1 ) ,
F_6 ( V_1 ) * sizeof( struct V_8 ) ) ;
V_5 -> V_9 = V_1 -> V_9 ;
V_5 -> V_10 = V_1 -> V_10 ;
V_5 -> V_11 = V_1 -> V_11 ;
V_5 -> V_12 = F_6 ( V_1 ) ;
V_5 -> V_13 = V_1 -> V_13 ;
V_5 -> V_3 = V_1 ;
V_5 -> V_14 = F_1 ;
V_1 = V_5 ;
}
V_1 -> V_15 = V_1 -> V_12 ;
F_8 ( V_1 ) ;
}
struct V_1 * F_9 ( struct V_1 * V_1 , int V_16 ,
T_1 V_17 , struct V_18 * V_19 )
{
unsigned V_20 = V_1 -> V_4 , V_21 = 0 , V_22 = V_16 << 9 ;
struct V_8 * V_23 ;
struct V_1 * V_24 = NULL ;
F_10 ( V_16 <= 0 ) ;
if ( V_25 -> V_26 )
V_17 &= ~ V_27 ;
if ( V_16 >= F_11 ( V_1 ) )
return V_1 ;
if ( V_1 -> V_11 & V_28 ) {
V_24 = F_12 ( V_17 , 1 , V_19 ) ;
V_20 = 0 ;
goto V_29;
}
F_13 (bv, bio, idx) {
V_21 = V_20 - V_1 -> V_4 ;
if ( ! V_22 ) {
V_24 = F_12 ( V_17 , V_21 , V_19 ) ;
if ( ! V_24 )
return NULL ;
memcpy ( V_24 -> V_7 , F_7 ( V_1 ) ,
sizeof( struct V_8 ) * V_21 ) ;
break;
} else if ( V_22 < V_23 -> V_30 ) {
V_24 = F_12 ( V_17 , ++ V_21 , V_19 ) ;
if ( ! V_24 )
return NULL ;
memcpy ( V_24 -> V_7 , F_7 ( V_1 ) ,
sizeof( struct V_8 ) * V_21 ) ;
V_24 -> V_7 [ V_21 - 1 ] . V_30 = V_22 ;
V_23 -> V_31 += V_22 ;
V_23 -> V_30 -= V_22 ;
break;
}
V_22 -= V_23 -> V_30 ;
}
V_29:
V_24 -> V_10 = V_1 -> V_10 ;
V_24 -> V_9 = V_1 -> V_9 ;
V_24 -> V_13 = V_16 << 9 ;
V_24 -> V_11 = V_1 -> V_11 ;
V_24 -> V_12 = V_21 ;
V_24 -> V_15 = V_21 ;
V_1 -> V_9 += V_16 ;
V_1 -> V_13 -= V_16 << 9 ;
V_1 -> V_4 = V_20 ;
if ( F_14 ( V_1 ) ) {
if ( F_15 ( V_24 , V_1 , V_17 ) ) {
F_3 ( V_24 ) ;
return NULL ;
}
F_16 ( V_24 , 0 , F_11 ( V_24 ) ) ;
F_16 ( V_1 , F_11 ( V_24 ) , F_11 ( V_1 ) ) ;
}
return V_24 ;
}
static unsigned F_17 ( struct V_1 * V_1 )
{
unsigned V_24 = F_11 ( V_1 ) ;
struct V_32 * V_33 = F_18 ( V_1 -> V_10 ) ;
unsigned V_34 = F_19 ( unsigned , V_35 ,
F_20 ( V_33 ) ) ;
struct V_8 * V_23 , * V_36 = F_7 ( V_1 ) +
F_19 ( int , F_6 ( V_1 ) , V_34 ) ;
if ( V_1 -> V_11 & V_28 )
return F_21 ( V_24 , V_33 -> V_37 . V_38 ) ;
if ( F_6 ( V_1 ) > V_34 ||
V_33 -> V_39 ) {
V_24 = 0 ;
for ( V_23 = F_7 ( V_1 ) ; V_23 < V_36 ; V_23 ++ ) {
struct V_40 V_41 = {
. V_10 = V_1 -> V_10 ,
. V_9 = V_1 -> V_9 ,
. V_13 = V_24 << 9 ,
. V_11 = V_1 -> V_11 ,
} ;
if ( V_33 -> V_39 &&
V_33 -> V_39 ( V_33 , & V_41 , V_23 ) < ( int ) V_23 -> V_30 )
break;
V_24 += V_23 -> V_30 >> 9 ;
}
}
V_24 = F_21 ( V_24 , F_22 ( V_33 ) ) ;
F_23 ( ! V_24 ) ;
V_24 = F_24 ( int , V_24 , F_7 ( V_1 ) -> V_30 >> 9 ) ;
return V_24 ;
}
static void F_25 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_26 ( V_43 , struct V_44 , V_43 ) ;
V_45 -> V_1 -> V_14 = V_45 -> V_14 ;
V_45 -> V_1 -> V_3 = V_45 -> V_3 ;
F_2 ( V_45 -> V_1 , 0 ) ;
F_27 ( & V_45 -> V_43 ) ;
F_28 ( V_45 , V_45 -> V_2 -> V_44 ) ;
}
static void F_29 ( struct V_1 * V_1 , int error )
{
struct V_42 * V_43 = V_1 -> V_3 ;
struct V_44 * V_45 = F_26 ( V_43 , struct V_44 , V_43 ) ;
if ( error )
F_30 ( V_46 , & V_45 -> V_1 -> V_47 ) ;
F_3 ( V_1 ) ;
F_31 ( V_43 ) ;
}
static void F_32 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = F_26 ( V_43 , struct V_44 , V_43 ) ;
struct V_1 * V_1 = V_45 -> V_1 , * V_48 ;
do {
V_48 = F_9 ( V_1 , F_17 ( V_1 ) ,
V_6 , V_45 -> V_2 -> V_49 ) ;
if ( ! V_48 )
F_33 ( V_43 , F_32 , V_50 ) ;
V_48 -> V_14 = F_29 ;
V_48 -> V_3 = V_43 ;
F_34 ( V_43 ) ;
F_4 ( V_48 ) ;
} while ( V_48 != V_1 );
F_33 ( V_43 , F_25 , NULL ) ;
}
void F_35 ( struct V_1 * V_1 , struct V_51 * V_2 )
{
struct V_44 * V_45 ;
if ( ! F_36 ( V_1 ) && ! ( V_1 -> V_11 & V_28 ) )
goto V_52;
if ( F_11 ( V_1 ) <= F_17 ( V_1 ) )
goto V_52;
V_45 = F_37 ( V_2 -> V_44 , V_6 ) ;
V_45 -> V_1 = V_1 ;
V_45 -> V_2 = V_2 ;
V_45 -> V_14 = V_1 -> V_14 ;
V_45 -> V_3 = V_1 -> V_3 ;
F_38 ( V_1 ) ;
F_39 ( & V_45 -> V_43 , F_32 , NULL , NULL ) ;
return;
V_52:
F_4 ( V_1 ) ;
}
void F_40 ( struct V_1 * V_1 , struct V_53 * V_54 )
{
struct V_55 * V_56 = F_26 ( V_1 , struct V_55 , V_1 ) ;
F_28 ( V_56 , V_54 -> V_57 ) ;
}
struct V_1 * F_41 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_37 ( V_54 -> V_57 , V_6 ) ;
struct V_1 * V_1 = & V_56 -> V_1 ;
F_42 ( V_1 ) ;
V_1 -> V_47 |= V_58 << V_59 ;
V_1 -> V_15 = F_43 ( V_54 ) ;
V_1 -> V_7 = V_1 -> V_60 ;
return V_1 ;
}
void F_44 ( struct V_1 * V_1 , struct V_53 * V_54 )
{
struct V_55 * V_56 = F_26 ( V_1 , struct V_55 , V_1 ) ;
V_1 -> V_9 = F_45 ( & V_56 -> V_61 , 0 ) ;
V_1 -> V_10 = F_46 ( V_54 , & V_56 -> V_61 , 0 ) -> V_62 ;
V_56 -> V_63 = F_47 () ;
F_48 ( V_1 , V_1 -> V_3 , F_46 ( V_54 , & V_56 -> V_61 , 0 ) ) ;
}
void F_49 ( struct V_1 * V_1 , struct V_53 * V_54 ,
struct V_64 * V_65 , unsigned V_66 )
{
struct V_55 * V_56 = F_26 ( V_1 , struct V_55 , V_1 ) ;
F_50 ( & V_56 -> V_61 , V_65 , V_66 ) ;
F_44 ( V_1 , V_54 ) ;
}
void F_51 ( struct V_67 * V_68 , int error , const char * V_69 )
{
if ( V_68 -> V_70 -> V_71 ) {
unsigned V_72 = F_52 ( & V_68 -> V_73 ) ;
while ( V_72 > V_68 -> V_70 -> V_71 ) {
unsigned V_74 ;
unsigned V_75 = V_72 ;
unsigned V_76 = V_72 - V_68 -> V_70 -> V_71 ;
V_72 = F_53 ( & V_68 -> V_73 , V_75 , V_76 ) ;
if ( V_72 == V_75 ) {
V_72 = V_76 ;
V_74 = F_54 ( & V_68 -> V_77 ) ;
do {
V_75 = V_74 ;
V_76 = ( ( V_78 ) V_74 * 127 ) / 128 ;
V_74 = F_53 ( & V_68 -> V_77 ,
V_75 , V_76 ) ;
} while ( V_75 != V_74 );
}
}
}
if ( error ) {
char V_79 [ V_80 ] ;
unsigned V_74 = F_55 ( 1 << V_81 ,
& V_68 -> V_77 ) ;
V_74 >>= V_81 ;
if ( V_74 < V_68 -> V_70 -> V_82 )
F_56 ( L_1 ,
F_57 ( V_68 -> V_62 , V_79 ) , V_69 ) ;
else
F_58 ( V_68 -> V_70 ,
L_2 ,
F_57 ( V_68 -> V_62 , V_79 ) , V_69 ) ;
}
}
void F_59 ( struct V_53 * V_54 , struct V_1 * V_1 ,
int error , const char * V_69 )
{
struct V_55 * V_56 = F_26 ( V_1 , struct V_55 , V_1 ) ;
struct V_67 * V_68 = F_46 ( V_54 , & V_56 -> V_61 , 0 ) ;
unsigned V_83 = V_1 -> V_11 & V_84
? V_54 -> V_85
: V_54 -> V_86 ;
if ( V_83 ) {
unsigned V_87 = F_47 () ;
int V_88 = V_87 - V_56 -> V_63 ;
int V_89 = F_54 ( & V_54 -> V_89 ) ;
if ( V_88 > ( int ) V_83 ) {
int V_90 = V_88 / 1024 ;
V_54 -> V_91 = V_87 ;
V_90 = F_21 ( V_90 , V_92 + V_89 ) ;
F_60 ( V_90 , & V_54 -> V_89 ) ;
} else if ( V_89 < 0 )
F_61 ( & V_54 -> V_89 ) ;
}
F_51 ( V_68 , error , V_69 ) ;
}
void F_62 ( struct V_53 * V_54 , struct V_1 * V_1 ,
int error , const char * V_69 )
{
struct V_42 * V_43 = V_1 -> V_3 ;
F_59 ( V_54 , V_1 , error , V_69 ) ;
F_3 ( V_1 ) ;
F_31 ( V_43 ) ;
}
