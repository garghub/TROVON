inline int F_1 ( const struct V_1 * V_2 ,
int (* F_2)( const struct V_1 * V_2 ,
T_1 * V_3 , const T_2 * V_4 ) ,
T_1 * V_5 )
{
T_1 V_6 , V_7 , V_8 ;
int V_9 ;
V_9 = F_2 ( V_2 , & V_6 , & V_2 -> V_10 . V_11 -> V_12 ) ;
if ( V_9 ) {
F_3 ( L_1 ,
& V_2 -> V_10 . V_11 -> V_12 ) ;
return V_9 ;
}
if ( * V_5 == V_6 )
return V_2 -> V_10 . V_13 ;
F_4 ( V_2 -> V_14 ) ;
V_7 = * V_5 & ( V_2 -> V_10 . V_13 - 1 ) ;
V_9 = F_2 ( V_2 , & V_8 , & V_2 -> V_10 . V_11 -> V_15 [ V_7 ] ) ;
if ( V_9 ) {
F_3 ( L_2 ,
* V_5 , & V_2 -> V_10 . V_11 -> V_15 [ V_7 ] ) ;
return V_9 ;
}
if ( V_8 >= V_2 -> V_10 . V_13 ) {
F_3 ( L_3 ,
V_8 , V_2 -> V_10 . V_13 ) ;
return - V_16 ;
}
( * V_5 ) ++ ;
return V_8 ;
}
static inline T_3 F_5 ( struct V_17 * V_18 ,
void * V_19 , T_4 V_20 ,
int (* F_6)( void * V_21 , void * V_19 ,
T_4 V_20 ) )
{
int V_9 , V_22 = 0 ;
while ( V_20 && V_18 -> V_7 < V_18 -> V_23 ) {
T_4 V_24 ;
V_24 = F_7 ( V_18 -> V_18 [ V_18 -> V_7 ] . V_25 , V_20 ) ;
V_9 = F_6 ( V_18 -> V_18 [ V_18 -> V_7 ] . V_26 , V_19 , V_24 ) ;
if ( V_9 )
return V_9 ;
V_22 += V_24 ;
V_20 -= V_24 ;
V_19 += V_24 ;
V_18 -> V_27 += V_24 ;
V_18 -> V_18 [ V_18 -> V_7 ] . V_25 -= V_24 ;
V_18 -> V_18 [ V_18 -> V_7 ] . V_26 += V_24 ;
if ( ! V_18 -> V_18 [ V_18 -> V_7 ] . V_25 ) {
V_18 -> V_18 [ V_18 -> V_7 ] . V_25 = V_18 -> V_27 ;
V_18 -> V_18 [ V_18 -> V_7 ] . V_26 -= V_18 -> V_27 ;
V_18 -> V_27 = 0 ;
V_18 -> V_7 ++ ;
}
}
return V_22 ;
}
static inline bool F_8 ( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,
struct V_28 * V_29 ,
bool (* F_9)( struct V_1 * ,
T_5 , struct V_28 * ) )
{
if ( V_21 < V_29 -> V_30 || V_21 > V_29 -> V_31 ) {
if ( ! F_9 ( V_2 , V_21 , V_29 ) )
return false ;
}
F_10 ( V_21 < V_29 -> V_30 || V_21 > V_29 -> V_31 ) ;
if ( F_11 ( V_21 + * V_20 == 0 ) ) {
if ( V_29 -> V_31 == - 1ULL )
return true ;
goto V_32;
}
if ( V_21 + * V_20 < V_21 ) {
F_3 ( L_4 ,
* V_20 , ( unsigned long long ) V_21 ) ;
return false ;
}
if ( F_11 ( V_21 + * V_20 - 1 > V_29 -> V_31 ) )
goto V_32;
return true ;
V_32:
* V_20 = V_29 -> V_31 + 1 - V_21 ;
return true ;
}
static inline bool F_12 ( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,
struct V_28 * V_29 ,
bool (* F_9)( struct V_1 * ,
T_5 , struct V_28 * ) )
{
return true ;
}
static int F_13 ( const struct V_1 * V_2 ,
int * V_33 , T_1 * V_7 , void * V_21 ,
const struct V_34 * V_35 ,
struct V_34 * * V_36 , int * V_37 )
{
T_6 V_20 ;
if ( * V_33 != - 1 ) {
F_3 ( L_5 , * V_33 , * V_7 ) ;
return - V_16 ;
}
V_20 = F_14 ( V_2 , V_35 -> V_20 ) ;
if ( F_11 ( V_20 % sizeof( struct V_34 ) ) ) {
F_3 ( L_6 , V_35 -> V_20 ) ;
return - V_16 ;
}
if ( V_35 -> V_38 & F_15 ( V_2 , V_39 ) )
* V_33 = F_16 ( V_2 , V_35 -> V_40 ) ;
else
* V_33 = - 2 ;
* V_36 = V_21 ;
* V_37 = V_20 / sizeof( struct V_34 ) ;
* V_7 = 0 ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 , T_7 V_41 )
{
struct V_42 * V_43 ;
unsigned int V_44 , V_45 = ( V_18 -> V_46 & ~ V_47 ) * 2 ;
if ( V_45 < 8 )
V_45 = 8 ;
V_44 = ( V_18 -> V_46 & V_47 ) ;
if ( V_44 )
V_43 = F_18 ( V_18 -> V_18 , V_45 * sizeof( struct V_48 ) , V_41 ) ;
else {
V_43 = F_19 ( V_45 * sizeof( struct V_48 ) , V_41 ) ;
if ( V_43 ) {
memcpy ( V_43 , V_18 -> V_18 ,
V_18 -> V_46 * sizeof( struct V_48 ) ) ;
V_44 = V_47 ;
}
}
if ( ! V_43 )
return - V_49 ;
V_18 -> V_18 = V_43 ;
V_18 -> V_46 = ( V_45 | V_44 ) ;
return 0 ;
}
static T_1 T_8 F_20 ( const struct V_1 * V_2 , int * V_33 ,
struct V_34 * * V_36 , int * V_37 )
{
T_1 V_7 = * V_33 ;
* V_33 = - 1 ;
* V_36 = V_2 -> V_10 . V_35 ;
* V_37 = V_2 -> V_10 . V_13 ;
return V_7 ;
}
static int F_21 ( struct V_1 * V_2 , void * V_50 , const void * V_51 ,
bool (* F_22)( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,
struct V_28 * V_29 ,
bool (* F_9)( struct V_1 * V_2 ,
T_5 ,
struct V_28 * ) ) ,
bool (* F_9)( struct V_1 * V_2 ,
T_5 V_21 ,
struct V_28 * V_52 ) ,
struct V_28 * V_29 ,
int (* F_23)( void * V_50 , const void * V_51 , T_4 V_20 ) )
{
T_4 V_53 , V_20 = sizeof( struct V_34 ) ;
do {
T_5 V_21 ;
int V_9 ;
V_53 = V_20 ;
V_21 = ( T_5 ) ( unsigned long ) V_51 - V_29 -> V_54 ;
if ( ! F_22 ( V_2 , V_21 , & V_53 , V_29 , F_9 ) )
return - V_16 ;
V_9 = F_23 ( V_50 , V_51 , V_53 ) ;
if ( V_9 )
return V_9 ;
V_50 += V_53 ;
V_51 += V_53 ;
V_20 -= V_53 ;
} while ( V_20 );
return 0 ;
}
static inline int
F_24 ( struct V_1 * V_2 , T_1 V_7 ,
struct V_17 * V_55 ,
struct V_17 * V_56 ,
bool (* F_22)( struct V_1 * V_2 , T_5 V_21 , T_4 * V_20 ,
struct V_28 * V_29 ,
bool (* F_9)( struct V_1 * , T_5 ,
struct V_28 * ) ) ,
bool (* F_9)( struct V_1 * , T_5 , struct V_28 * ) ,
T_7 V_41 ,
int (* F_23)( void * V_50 , const void * V_51 , T_4 V_20 ) )
{
int V_9 , V_57 = 0 , V_33 , V_37 ;
struct V_34 V_35 , * V_36 ;
struct V_28 V_29 = { - 1ULL , 0 } , V_58 ;
bool V_59 = false ;
V_36 = V_2 -> V_10 . V_35 ;
V_37 = V_2 -> V_10 . V_13 ;
V_33 = - 1 ;
if ( V_55 )
V_55 -> V_7 = V_55 -> V_23 = 0 ;
else if ( V_56 )
V_56 -> V_7 = V_56 -> V_23 = 0 ;
else
F_25 () ;
for (; ; ) {
void * V_21 ;
struct V_17 * V_18 ;
T_4 V_20 ;
if ( F_11 ( V_59 ) )
V_9 = F_21 ( V_2 , & V_35 , & V_36 [ V_7 ] , F_22 , F_9 ,
& V_58 , F_23 ) ;
else
V_9 = F_23 ( & V_35 , & V_36 [ V_7 ] , sizeof( V_35 ) ) ;
if ( F_11 ( V_9 ) )
goto V_60;
if ( F_11 ( V_35 . V_38 &
F_15 ( V_2 , V_61 ) ) ) {
T_5 V_62 = F_26 ( V_2 , V_35 . V_21 ) ;
V_20 = F_14 ( V_2 , V_35 . V_20 ) ;
if ( ! F_22 ( V_2 , V_62 , & V_20 , & V_29 , F_9 ) ) {
V_9 = - V_16 ;
goto V_60;
}
if ( F_11 ( V_20 != F_14 ( V_2 , V_35 . V_20 ) ) ) {
V_59 = true ;
V_58 = V_29 ;
}
V_21 = ( void * ) ( long ) ( V_62 + V_29 . V_54 ) ;
V_9 = F_13 ( V_2 , & V_33 , & V_7 , V_21 , & V_35 ,
& V_36 , & V_37 ) ;
if ( V_9 )
goto V_60;
continue;
}
if ( V_57 ++ == V_2 -> V_10 . V_13 ) {
F_3 ( L_7 , V_36 ) ;
V_9 = - V_63 ;
goto V_60;
}
if ( V_35 . V_38 & F_15 ( V_2 , V_64 ) )
V_18 = V_56 ;
else {
V_18 = V_55 ;
if ( F_11 ( V_56 && V_56 -> V_7 ) ) {
F_3 ( L_8 ,
& V_36 [ V_7 ] ) ;
V_9 = - V_16 ;
goto V_60;
}
}
if ( ! V_18 ) {
F_3 ( L_9 ,
! V_56 ? L_10 : L_11 ) ;
V_9 = - V_65 ;
goto V_60;
}
V_66:
V_20 = F_14 ( V_2 , V_35 . V_20 ) ;
if ( ! F_22 ( V_2 , F_26 ( V_2 , V_35 . V_21 ) , & V_20 , & V_29 ,
F_9 ) ) {
V_9 = - V_16 ;
goto V_60;
}
V_21 = ( void * ) ( unsigned long ) ( F_26 ( V_2 , V_35 . V_21 ) +
V_29 . V_54 ) ;
if ( F_11 ( V_18 -> V_23 == ( V_18 -> V_46 & ~ V_47 ) ) ) {
V_9 = F_17 ( V_18 , V_41 ) ;
if ( V_9 )
goto V_60;
}
V_18 -> V_18 [ V_18 -> V_23 ] . V_26 = V_21 ;
V_18 -> V_18 [ V_18 -> V_23 ] . V_25 = V_20 ;
V_18 -> V_23 ++ ;
if ( F_11 ( V_20 != F_14 ( V_2 , V_35 . V_20 ) ) ) {
V_35 . V_20 = F_27 ( V_2 ,
F_14 ( V_2 , V_35 . V_20 ) - V_20 ) ;
V_35 . V_21 = F_28 ( V_2 ,
F_26 ( V_2 , V_35 . V_21 ) + V_20 ) ;
goto V_66;
}
if ( V_35 . V_38 & F_15 ( V_2 , V_39 ) ) {
V_7 = F_16 ( V_2 , V_35 . V_40 ) ;
} else {
if ( F_11 ( V_33 > 0 ) ) {
V_7 = F_20 ( V_2 , & V_33 ,
& V_36 , & V_37 ) ;
V_59 = false ;
} else
break;
}
if ( V_7 >= V_37 ) {
F_3 ( L_12 , V_7 , V_37 ) ;
V_9 = - V_16 ;
goto V_60;
}
}
return 0 ;
V_60:
return V_9 ;
}
static inline int F_29 ( struct V_1 * V_2 ,
const struct V_67 * V_23 ,
unsigned int V_68 ,
int (* F_30)( const struct V_1 * V_2 ,
T_2 * V_4 , T_1 V_3 ) ,
int (* F_31)( struct V_67 * V_50 ,
const struct V_67
* V_51 , unsigned V_13 ) )
{
struct V_69 * V_70 ;
int V_9 ;
T_1 V_71 , V_72 ;
V_70 = V_2 -> V_10 . V_23 ;
V_71 = V_2 -> V_73 + V_2 -> V_74 ;
V_72 = V_71 % V_2 -> V_10 . V_13 ;
if ( V_68 > 1 && F_11 ( V_72 + V_68 >= V_2 -> V_10 . V_13 ) ) {
T_1 V_53 = V_2 -> V_10 . V_13 - V_72 ;
V_9 = F_31 ( & V_70 -> V_15 [ V_72 ] , V_23 , V_53 ) ;
if ( ! V_9 )
V_9 = F_31 ( & V_70 -> V_15 [ 0 ] , V_23 + V_53 ,
V_68 - V_53 ) ;
} else
V_9 = F_31 ( & V_70 -> V_15 [ V_72 ] , V_23 , V_68 ) ;
if ( V_9 ) {
F_3 ( L_13 ,
V_68 , V_72 , & V_70 -> V_15 [ V_72 ] ) ;
return V_9 ;
}
F_32 ( V_2 -> V_14 ) ;
V_9 = F_30 ( V_2 , & V_2 -> V_10 . V_23 -> V_12 , V_71 + V_68 ) ;
if ( V_9 ) {
F_3 ( L_14 ,
& V_2 -> V_10 . V_23 -> V_12 ) ;
return V_9 ;
}
V_2 -> V_74 += V_68 ;
return 0 ;
}
static inline int F_33 ( struct V_1 * V_2 ,
int (* F_2)( const struct V_1 * V_2 ,
T_1 * V_3 ,
const T_2 * V_4 ) )
{
bool V_75 ;
T_1 V_76 ;
int V_9 ;
F_34 ( V_2 -> V_14 ) ;
if ( ! V_2 -> V_77 ) {
T_1 V_38 ;
V_9 = F_2 ( V_2 , & V_38 , & V_2 -> V_10 . V_11 -> V_38 ) ;
if ( V_9 ) {
F_3 ( L_15 ,
& V_2 -> V_10 . V_11 -> V_38 ) ;
return V_9 ;
}
return ( ! ( V_38 & V_78 ) ) ;
}
V_9 = F_2 ( V_2 , & V_76 , & F_35 ( & V_2 -> V_10 ) ) ;
if ( V_9 ) {
F_3 ( L_16 ,
& F_35 ( & V_2 -> V_10 ) ) ;
return V_9 ;
}
if ( F_11 ( V_2 -> V_74 > 0xffff ) )
V_75 = true ;
else
V_75 = F_36 ( V_76 ,
V_2 -> V_73 + V_2 -> V_74 ,
V_2 -> V_73 ) ;
V_2 -> V_73 += V_2 -> V_74 ;
V_2 -> V_74 = 0 ;
return V_75 ;
}
static inline bool F_37 ( struct V_1 * V_2 ,
int (* F_2)( const struct V_1 * V_2 ,
T_1 * V_3 , const T_2 * V_4 ) ,
int (* F_30)( const struct V_1 * V_2 ,
T_2 * V_4 , T_1 V_3 ) )
{
T_1 V_11 ;
if ( ! V_2 -> V_77 ) {
if ( F_30 ( V_2 , & V_2 -> V_10 . V_23 -> V_38 , 0 ) != 0 ) {
F_3 ( L_17 ,
& V_2 -> V_10 . V_23 -> V_38 ) ;
return true ;
}
} else {
if ( F_30 ( V_2 , & F_38 ( & V_2 -> V_10 ) ,
V_2 -> V_5 ) != 0 ) {
F_3 ( L_18 ,
& F_38 ( & V_2 -> V_10 ) ) ;
return true ;
}
}
F_34 ( V_2 -> V_14 ) ;
if ( F_2 ( V_2 , & V_11 , & V_2 -> V_10 . V_11 -> V_12 ) != 0 ) {
F_3 ( L_19 ,
& V_2 -> V_10 . V_11 -> V_12 ) ;
return true ;
}
return V_11 == V_2 -> V_5 ;
}
static inline void F_39 ( struct V_1 * V_2 ,
int (* F_30)( const struct V_1 * V_2 ,
T_2 * V_4 , T_1 V_3 ) )
{
if ( ! V_2 -> V_77 ) {
if ( F_30 ( V_2 , & V_2 -> V_10 . V_23 -> V_38 ,
V_79 ) ) {
F_3 ( L_20 ,
& V_2 -> V_10 . V_23 -> V_38 ) ;
}
}
}
static inline int F_40 ( const struct V_1 * V_2 , T_1 * V_3 , const T_2 * V_4 )
{
T_2 V_80 = 0 ;
int V_81 = F_41 ( V_80 , ( V_82 T_2 V_83 * ) V_4 ) ;
* V_3 = F_16 ( V_2 , V_80 ) ;
return V_81 ;
}
static inline int F_42 ( const struct V_1 * V_2 , T_2 * V_4 , T_1 V_3 )
{
T_2 V_80 = F_15 ( V_2 , V_3 ) ;
return F_43 ( V_80 , ( V_82 T_2 V_83 * ) V_4 ) ;
}
static inline int F_44 ( void * V_50 , const void * V_51 , T_4 V_20 )
{
return F_45 ( V_50 , ( V_82 void V_83 * ) V_51 , V_20 ) ?
- V_84 : 0 ;
}
static inline int F_46 ( struct V_67 * V_50 ,
const struct V_67 * V_51 ,
unsigned int V_13 )
{
return F_47 ( ( V_82 void V_83 * ) V_50 , V_51 ,
sizeof( * V_50 ) * V_13 ) ? - V_84 : 0 ;
}
static inline int F_48 ( void * V_51 , void * V_50 , T_4 V_20 )
{
return F_45 ( V_50 , ( V_82 void V_83 * ) V_51 , V_20 ) ?
- V_84 : 0 ;
}
static inline int F_49 ( void * V_50 , void * V_51 , T_4 V_20 )
{
return F_47 ( ( V_82 void V_83 * ) V_50 , V_51 , V_20 ) ?
- V_84 : 0 ;
}
int F_50 ( struct V_1 * V_2 , T_5 V_85 ,
unsigned int V_13 , bool V_14 ,
struct V_34 V_83 * V_35 ,
struct V_86 V_83 * V_11 ,
struct V_69 V_83 * V_23 )
{
if ( ! V_13 || V_13 > 0xffff || ( V_13 & ( V_13 - 1 ) ) ) {
F_3 ( L_21 , V_13 ) ;
return - V_16 ;
}
V_2 -> V_87 = ( V_85 & ( 1ULL << V_88 ) ) ;
V_2 -> V_77 = ( V_85 & ( 1 << V_89 ) ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_74 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_10 . V_13 = V_13 ;
V_2 -> V_10 . V_35 = ( V_82 struct V_34 * ) V_35 ;
V_2 -> V_10 . V_11 = ( V_82 struct V_86 * ) V_11 ;
V_2 -> V_10 . V_23 = ( V_82 struct V_69 * ) V_23 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_90 * V_55 ,
struct V_90 * V_56 ,
bool (* F_9)( struct V_1 * V_2 ,
T_5 V_21 , struct V_28 * V_52 ) ,
T_1 * V_8 )
{
int V_9 ;
* V_8 = V_2 -> V_10 . V_13 ;
V_9 = F_1 ( V_2 , F_40 , & V_2 -> V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == V_2 -> V_10 . V_13 )
return 0 ;
F_52 ( sizeof( struct V_17 ) != sizeof( struct V_90 ) ) ;
F_52 ( F_53 ( struct V_17 , V_18 ) !=
F_53 ( struct V_90 , V_18 ) ) ;
F_52 ( F_53 ( struct V_17 , V_7 ) !=
F_53 ( struct V_90 , V_7 ) ) ;
F_52 ( F_53 ( struct V_17 , V_23 ) !=
F_53 ( struct V_90 , V_23 ) ) ;
F_52 ( F_53 ( struct V_17 , V_46 ) !=
F_53 ( struct V_90 , V_46 ) ) ;
F_52 ( sizeof( struct V_48 ) != sizeof( struct V_42 ) ) ;
F_52 ( F_53 ( struct V_48 , V_26 ) !=
F_53 ( struct V_42 , V_26 ) ) ;
F_52 ( F_53 ( struct V_48 , V_25 ) !=
F_53 ( struct V_42 , V_25 ) ) ;
F_52 ( sizeof( ( (struct V_48 * ) NULL ) -> V_26 )
!= sizeof( ( (struct V_42 * ) NULL ) -> V_26 ) ) ;
F_52 ( sizeof( ( (struct V_48 * ) NULL ) -> V_25 )
!= sizeof( ( (struct V_42 * ) NULL ) -> V_25 ) ) ;
* V_8 = V_9 ;
V_9 = F_24 ( V_2 , * V_8 , (struct V_17 * ) V_55 ,
(struct V_17 * ) V_56 ,
F_8 , F_9 , V_91 , F_44 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
T_3 F_54 ( struct V_90 * V_55 , void * V_50 , T_4 V_20 )
{
return F_5 ( (struct V_17 * ) V_55 ,
V_50 , V_20 , F_48 ) ;
}
T_3 F_55 ( struct V_90 * V_56 ,
const void * V_51 , T_4 V_20 )
{
return F_5 ( (struct V_17 * ) V_56 ,
( void * ) V_51 , V_20 , F_49 ) ;
}
void F_56 ( struct V_1 * V_2 , unsigned int V_13 )
{
V_2 -> V_5 -= V_13 ;
}
int F_57 ( struct V_1 * V_2 , T_1 V_8 , T_6 V_20 )
{
struct V_67 V_23 ;
V_23 . V_92 = F_27 ( V_2 , V_8 ) ;
V_23 . V_20 = F_27 ( V_2 , V_20 ) ;
return F_29 ( V_2 , & V_23 , 1 , F_42 , F_46 ) ;
}
int F_58 ( struct V_1 * V_2 ,
const struct V_67 V_23 [] ,
unsigned V_68 )
{
return F_29 ( V_2 , V_23 , V_68 ,
F_42 , F_46 ) ;
}
bool F_59 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , F_40 , F_42 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_39 ( V_2 , F_42 ) ;
}
int F_61 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , F_40 ) ;
}
static inline int F_62 ( const struct V_1 * V_2 ,
T_1 * V_3 , const T_2 * V_4 )
{
* V_3 = F_16 ( V_2 , F_63 ( * V_4 ) ) ;
return 0 ;
}
static inline int F_64 ( const struct V_1 * V_2 , T_2 * V_4 , T_1 V_3 )
{
F_63 ( * V_4 ) = F_15 ( V_2 , V_3 ) ;
return 0 ;
}
static inline int F_65 ( void * V_50 , const void * V_51 , T_4 V_20 )
{
memcpy ( V_50 , V_51 , V_20 ) ;
return 0 ;
}
static inline int F_66 ( struct V_67 * V_50 ,
const struct V_67 * V_51 ,
unsigned int V_13 )
{
memcpy ( V_50 , V_51 , V_13 * sizeof( * V_50 ) ) ;
return 0 ;
}
static inline int F_67 ( void * V_51 , void * V_50 , T_4 V_20 )
{
memcpy ( V_50 , V_51 , V_20 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , T_5 V_85 ,
unsigned int V_13 , bool V_14 ,
struct V_34 * V_35 ,
struct V_86 * V_11 ,
struct V_69 * V_23 )
{
if ( ! V_13 || V_13 > 0xffff || ( V_13 & ( V_13 - 1 ) ) ) {
F_3 ( L_21 , V_13 ) ;
return - V_16 ;
}
V_2 -> V_87 = ( V_85 & ( 1ULL << V_88 ) ) ;
V_2 -> V_77 = ( V_85 & ( 1 << V_89 ) ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_74 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_10 . V_13 = V_13 ;
V_2 -> V_10 . V_35 = V_35 ;
V_2 -> V_10 . V_11 = V_11 ;
V_2 -> V_10 . V_23 = V_23 ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_17 * V_55 ,
struct V_17 * V_56 ,
T_1 * V_8 ,
T_7 V_41 )
{
int V_9 ;
V_9 = F_1 ( V_2 , F_62 , & V_2 -> V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 == V_2 -> V_10 . V_13 )
return 0 ;
* V_8 = V_9 ;
V_9 = F_24 ( V_2 , * V_8 , V_55 , V_56 , F_12 , NULL ,
V_41 , F_65 ) ;
if ( V_9 )
return V_9 ;
return 1 ;
}
T_3 F_70 ( struct V_17 * V_55 , void * V_50 , T_4 V_20 )
{
return F_5 ( V_55 , V_50 , V_20 , F_67 ) ;
}
T_3 F_71 ( struct V_17 * V_56 ,
const void * V_51 , T_4 V_20 )
{
return F_5 ( V_56 , ( void * ) V_51 , V_20 , F_67 ) ;
}
void F_72 ( struct V_1 * V_2 , unsigned int V_13 )
{
V_2 -> V_5 -= V_13 ;
}
int F_73 ( struct V_1 * V_2 , T_1 V_8 , T_6 V_20 )
{
struct V_67 V_23 ;
V_23 . V_92 = F_27 ( V_2 , V_8 ) ;
V_23 . V_20 = F_27 ( V_2 , V_20 ) ;
return F_29 ( V_2 , & V_23 , 1 , F_64 , F_66 ) ;
}
bool F_74 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , F_62 , F_64 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_39 ( V_2 , F_64 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , F_62 ) ;
}
