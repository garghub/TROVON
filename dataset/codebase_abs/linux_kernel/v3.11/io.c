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
if ( V_16 >= F_11 ( V_1 ) )
return V_1 ;
if ( V_1 -> V_11 & V_25 ) {
V_24 = F_12 ( V_17 , 1 , V_19 ) ;
if ( ! V_24 )
return NULL ;
V_20 = 0 ;
goto V_26;
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
} else if ( V_22 < V_23 -> V_27 ) {
V_24 = F_12 ( V_17 , ++ V_21 , V_19 ) ;
if ( ! V_24 )
return NULL ;
memcpy ( V_24 -> V_7 , F_7 ( V_1 ) ,
sizeof( struct V_8 ) * V_21 ) ;
V_24 -> V_7 [ V_21 - 1 ] . V_27 = V_22 ;
V_23 -> V_28 += V_22 ;
V_23 -> V_27 -= V_22 ;
break;
}
V_22 -= V_23 -> V_27 ;
}
V_26:
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
struct V_29 * V_30 = F_18 ( V_1 -> V_10 ) ;
unsigned V_31 = F_19 ( unsigned , V_32 ,
F_20 ( V_30 ) ) ;
if ( V_1 -> V_11 & V_25 )
return F_21 ( V_24 , V_30 -> V_33 . V_34 ) ;
if ( F_6 ( V_1 ) > V_31 ||
V_30 -> V_35 ) {
struct V_8 * V_23 ;
int V_36 , V_37 = 0 ;
V_24 = 0 ;
F_13 (bv, bio, i) {
struct V_38 V_39 = {
. V_10 = V_1 -> V_10 ,
. V_9 = V_1 -> V_9 ,
. V_13 = V_24 << 9 ,
. V_11 = V_1 -> V_11 ,
} ;
if ( V_37 == V_31 )
break;
if ( V_30 -> V_35 &&
V_30 -> V_35 ( V_30 , & V_39 , V_23 ) < ( int ) V_23 -> V_27 )
break;
V_37 ++ ;
V_24 += V_23 -> V_27 >> 9 ;
}
}
V_24 = F_21 ( V_24 , F_22 ( V_30 ) ) ;
F_23 ( ! V_24 ) ;
V_24 = F_24 ( int , V_24 , F_7 ( V_1 ) -> V_27 >> 9 ) ;
return V_24 ;
}
static void F_25 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_26 ( V_41 , struct V_42 , V_41 ) ;
V_43 -> V_1 -> V_14 = V_43 -> V_14 ;
V_43 -> V_1 -> V_3 = V_43 -> V_3 ;
F_2 ( V_43 -> V_1 , 0 ) ;
F_27 ( & V_43 -> V_41 ) ;
F_28 ( V_43 , V_43 -> V_2 -> V_42 ) ;
}
static void F_29 ( struct V_1 * V_1 , int error )
{
struct V_40 * V_41 = V_1 -> V_3 ;
struct V_42 * V_43 = F_26 ( V_41 , struct V_42 , V_41 ) ;
if ( error )
F_30 ( V_44 , & V_43 -> V_1 -> V_45 ) ;
F_3 ( V_1 ) ;
F_31 ( V_41 ) ;
}
void F_32 ( struct V_1 * V_1 , struct V_46 * V_2 )
{
struct V_42 * V_43 ;
struct V_1 * V_47 ;
if ( ! F_33 ( V_1 ) && ! ( V_1 -> V_11 & V_25 ) )
goto V_48;
if ( F_11 ( V_1 ) <= F_17 ( V_1 ) )
goto V_48;
V_43 = F_34 ( V_2 -> V_42 , V_6 ) ;
F_35 ( & V_43 -> V_41 , NULL ) ;
V_43 -> V_1 = V_1 ;
V_43 -> V_2 = V_2 ;
V_43 -> V_14 = V_1 -> V_14 ;
V_43 -> V_3 = V_1 -> V_3 ;
F_36 ( V_1 ) ;
do {
V_47 = F_9 ( V_1 , F_17 ( V_1 ) ,
V_6 , V_43 -> V_2 -> V_49 ) ;
V_47 -> V_14 = F_29 ;
V_47 -> V_3 = & V_43 -> V_41 ;
F_37 ( & V_43 -> V_41 ) ;
F_4 ( V_47 ) ;
} while ( V_47 != V_1 );
F_38 ( & V_43 -> V_41 , F_25 , NULL ) ;
V_48:
F_4 ( V_1 ) ;
}
void F_39 ( struct V_1 * V_1 , struct V_50 * V_51 )
{
struct V_52 * V_53 = F_26 ( V_1 , struct V_52 , V_1 ) ;
F_28 ( V_53 , V_51 -> V_54 ) ;
}
struct V_1 * F_40 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_34 ( V_51 -> V_54 , V_6 ) ;
struct V_1 * V_1 = & V_53 -> V_1 ;
F_41 ( V_1 ) ;
V_1 -> V_45 |= V_55 << V_56 ;
V_1 -> V_15 = F_42 ( V_51 ) ;
V_1 -> V_7 = V_1 -> V_57 ;
return V_1 ;
}
void F_43 ( struct V_1 * V_1 , struct V_50 * V_51 )
{
struct V_52 * V_53 = F_26 ( V_1 , struct V_52 , V_1 ) ;
V_1 -> V_9 = F_44 ( & V_53 -> V_58 , 0 ) ;
V_1 -> V_10 = F_45 ( V_51 , & V_53 -> V_58 , 0 ) -> V_59 ;
V_53 -> V_60 = F_46 () ;
F_47 ( V_1 , V_1 -> V_3 , F_45 ( V_51 , & V_53 -> V_58 , 0 ) ) ;
}
void F_48 ( struct V_1 * V_1 , struct V_50 * V_51 ,
struct V_61 * V_62 , unsigned V_63 )
{
struct V_52 * V_53 = F_26 ( V_1 , struct V_52 , V_1 ) ;
F_49 ( & V_53 -> V_58 , V_62 , V_63 ) ;
F_43 ( V_1 , V_51 ) ;
}
void F_50 ( struct V_64 * V_65 , int error , const char * V_66 )
{
if ( V_65 -> V_67 -> V_68 ) {
unsigned V_69 = F_51 ( & V_65 -> V_70 ) ;
while ( V_69 > V_65 -> V_67 -> V_68 ) {
unsigned V_71 ;
unsigned V_72 = V_69 ;
unsigned V_73 = V_69 - V_65 -> V_67 -> V_68 ;
V_69 = F_52 ( & V_65 -> V_70 , V_72 , V_73 ) ;
if ( V_69 == V_72 ) {
V_69 = V_73 ;
V_71 = F_53 ( & V_65 -> V_74 ) ;
do {
V_72 = V_71 ;
V_73 = ( ( V_75 ) V_71 * 127 ) / 128 ;
V_71 = F_52 ( & V_65 -> V_74 ,
V_72 , V_73 ) ;
} while ( V_72 != V_71 );
}
}
}
if ( error ) {
char V_76 [ V_77 ] ;
unsigned V_71 = F_54 ( 1 << V_78 ,
& V_65 -> V_74 ) ;
V_71 >>= V_78 ;
if ( V_71 < V_65 -> V_67 -> V_79 )
F_55 ( L_1 ,
F_56 ( V_65 -> V_59 , V_76 ) , V_66 ) ;
else
F_57 ( V_65 -> V_67 ,
L_2 ,
F_56 ( V_65 -> V_59 , V_76 ) , V_66 ) ;
}
}
void F_58 ( struct V_50 * V_51 , struct V_1 * V_1 ,
int error , const char * V_66 )
{
struct V_52 * V_53 = F_26 ( V_1 , struct V_52 , V_1 ) ;
struct V_64 * V_65 = F_45 ( V_51 , & V_53 -> V_58 , 0 ) ;
unsigned V_80 = V_1 -> V_11 & V_81
? V_51 -> V_82
: V_51 -> V_83 ;
if ( V_80 ) {
unsigned V_84 = F_46 () ;
int V_85 = V_84 - V_53 -> V_60 ;
int V_86 = F_53 ( & V_51 -> V_86 ) ;
if ( V_85 > ( int ) V_80 ) {
int V_87 = V_85 / 1024 ;
V_51 -> V_88 = V_84 ;
V_87 = F_21 ( V_87 , V_89 + V_86 ) ;
F_59 ( V_87 , & V_51 -> V_86 ) ;
} else if ( V_86 < 0 )
F_60 ( & V_51 -> V_86 ) ;
}
F_50 ( V_65 , error , V_66 ) ;
}
void F_61 ( struct V_50 * V_51 , struct V_1 * V_1 ,
int error , const char * V_66 )
{
struct V_40 * V_41 = V_1 -> V_3 ;
F_58 ( V_51 , V_1 , error , V_66 ) ;
F_3 ( V_1 ) ;
F_31 ( V_41 ) ;
}
