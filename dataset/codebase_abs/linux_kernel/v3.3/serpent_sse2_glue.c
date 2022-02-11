static inline bool F_1 ( bool V_1 , unsigned int V_2 )
{
if ( V_1 )
return true ;
if ( V_2 < V_3 * V_4 )
return false ;
F_2 () ;
return true ;
}
static inline void F_3 ( bool V_1 )
{
if ( V_1 )
F_4 () ;
}
static int F_5 ( struct V_5 * V_6 , struct V_7 * V_8 ,
bool V_9 )
{
bool V_1 = false ;
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 ;
int V_14 ;
V_14 = F_7 ( V_6 , V_8 ) ;
V_6 -> V_15 &= ~ V_16 ;
while ( ( V_2 = V_8 -> V_2 ) ) {
T_1 * V_17 = V_8 -> V_18 . V_19 . V_20 ;
T_1 * V_21 = V_8 -> V_22 . V_19 . V_20 ;
V_1 = F_1 ( V_1 , V_2 ) ;
if ( V_2 >= V_13 * V_4 ) {
do {
if ( V_9 )
F_8 ( V_11 , V_21 , V_17 ) ;
else
F_9 ( V_11 , V_21 , V_17 ) ;
V_17 += V_13 * V_4 ;
V_21 += V_13 * V_4 ;
V_2 -= V_13 * V_4 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_23;
}
do {
if ( V_9 )
F_10 ( V_11 , V_21 , V_17 ) ;
else
F_11 ( V_11 , V_21 , V_17 ) ;
V_17 += V_13 ;
V_21 += V_13 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
V_23:
V_14 = F_12 ( V_6 , V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
return V_14 ;
}
static int F_13 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
struct V_7 V_8 ;
F_14 ( & V_8 , V_22 , V_18 , V_2 ) ;
return F_5 ( V_6 , & V_8 , true ) ;
}
static int F_15 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
struct V_7 V_8 ;
F_14 ( & V_8 , V_22 , V_18 , V_2 ) ;
return F_5 ( V_6 , & V_8 , false ) ;
}
static unsigned int F_16 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_18 = ( T_2 * ) V_8 -> V_18 . V_19 . V_20 ;
T_2 * V_22 = ( T_2 * ) V_8 -> V_22 . V_19 . V_20 ;
T_2 * V_25 = ( T_2 * ) V_8 -> V_25 ;
do {
F_17 ( V_22 , V_18 , V_25 ) ;
F_10 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_22 ) ;
V_25 = V_22 ;
V_18 += 1 ;
V_22 += 1 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
F_17 ( ( T_2 * ) V_8 -> V_25 , ( T_2 * ) V_8 -> V_25 , V_25 ) ;
return V_2 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
struct V_7 V_8 ;
int V_14 ;
F_14 ( & V_8 , V_22 , V_18 , V_2 ) ;
V_14 = F_7 ( V_6 , & V_8 ) ;
while ( ( V_2 = V_8 . V_2 ) ) {
V_2 = F_16 ( V_6 , & V_8 ) ;
V_14 = F_12 ( V_6 , & V_8 , V_2 ) ;
}
return V_14 ;
}
static unsigned int F_19 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_18 = ( T_2 * ) V_8 -> V_18 . V_19 . V_20 ;
T_2 * V_22 = ( T_2 * ) V_8 -> V_22 . V_19 . V_20 ;
T_2 V_26 [ V_4 - 1 ] ;
T_2 V_27 ;
int V_28 ;
V_18 += V_2 / V_13 - 1 ;
V_22 += V_2 / V_13 - 1 ;
V_27 = * V_18 ;
if ( V_2 >= V_13 * V_4 ) {
do {
V_2 -= V_13 * ( V_4 - 1 ) ;
V_18 -= V_4 - 1 ;
V_22 -= V_4 - 1 ;
for ( V_28 = 0 ; V_28 < V_4 - 1 ; V_28 ++ )
V_26 [ V_28 ] = V_18 [ V_28 ] ;
F_9 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_18 ) ;
for ( V_28 = 0 ; V_28 < V_4 - 1 ; V_28 ++ )
F_17 ( V_22 + ( V_28 + 1 ) , V_22 + ( V_28 + 1 ) , V_26 + V_28 ) ;
V_2 -= V_13 ;
if ( V_2 < V_13 )
goto V_23;
F_17 ( V_22 , V_22 , V_18 - 1 ) ;
V_18 -= 1 ;
V_22 -= 1 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_23;
}
for (; ; ) {
F_11 ( V_11 , ( T_1 * ) V_22 , ( T_1 * ) V_18 ) ;
V_2 -= V_13 ;
if ( V_2 < V_13 )
break;
F_17 ( V_22 , V_22 , V_18 - 1 ) ;
V_18 -= 1 ;
V_22 -= 1 ;
}
V_23:
F_17 ( V_22 , V_22 , ( T_2 * ) V_8 -> V_25 ) ;
* ( T_2 * ) V_8 -> V_25 = V_27 ;
return V_2 ;
}
static int F_20 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
bool V_1 = false ;
struct V_7 V_8 ;
int V_14 ;
F_14 ( & V_8 , V_22 , V_18 , V_2 ) ;
V_14 = F_7 ( V_6 , & V_8 ) ;
V_6 -> V_15 &= ~ V_16 ;
while ( ( V_2 = V_8 . V_2 ) ) {
V_1 = F_1 ( V_1 , V_2 ) ;
V_2 = F_19 ( V_6 , & V_8 ) ;
V_14 = F_12 ( V_6 , & V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
return V_14 ;
}
static inline void F_21 ( T_3 * V_22 , const T_2 * V_18 )
{
V_22 -> V_29 = F_22 ( V_18 -> V_29 ) ;
V_22 -> V_30 = F_22 ( V_18 -> V_30 ) ;
}
static inline void F_23 ( T_2 * V_22 , const T_3 * V_18 )
{
V_22 -> V_29 = F_24 ( V_18 -> V_29 ) ;
V_22 -> V_30 = F_24 ( V_18 -> V_30 ) ;
}
static inline void F_25 ( T_2 * V_28 )
{
V_28 -> V_30 ++ ;
if ( ! V_28 -> V_30 )
V_28 -> V_29 ++ ;
}
static void F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
T_1 * V_31 = V_8 -> V_25 ;
T_1 V_32 [ V_3 ] ;
T_1 * V_18 = V_8 -> V_18 . V_19 . V_20 ;
T_1 * V_22 = V_8 -> V_22 . V_19 . V_20 ;
unsigned int V_2 = V_8 -> V_2 ;
F_10 ( V_11 , V_32 , V_31 ) ;
F_27 ( V_32 , V_18 , V_2 ) ;
memcpy ( V_22 , V_32 , V_2 ) ;
F_28 ( V_31 , V_3 ) ;
}
static unsigned int F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_6 ( V_6 -> V_12 ) ;
const unsigned int V_13 = V_3 ;
unsigned int V_2 = V_8 -> V_2 ;
T_2 * V_18 = ( T_2 * ) V_8 -> V_18 . V_19 . V_20 ;
T_2 * V_22 = ( T_2 * ) V_8 -> V_22 . V_19 . V_20 ;
T_2 V_31 ;
T_3 V_33 [ V_4 ] ;
int V_28 ;
F_23 ( & V_31 , ( T_3 * ) V_8 -> V_25 ) ;
if ( V_2 >= V_13 * V_4 ) {
do {
for ( V_28 = 0 ; V_28 < V_4 ; V_28 ++ ) {
if ( V_22 != V_18 )
V_22 [ V_28 ] = V_18 [ V_28 ] ;
F_21 ( & V_33 [ V_28 ] , & V_31 ) ;
F_25 ( & V_31 ) ;
}
F_30 ( V_11 , ( T_1 * ) V_22 ,
( T_1 * ) V_33 ) ;
V_18 += V_4 ;
V_22 += V_4 ;
V_2 -= V_13 * V_4 ;
} while ( V_2 >= V_13 * V_4 );
if ( V_2 < V_13 )
goto V_23;
}
do {
if ( V_22 != V_18 )
* V_22 = * V_18 ;
F_21 ( & V_33 [ 0 ] , & V_31 ) ;
F_25 ( & V_31 ) ;
F_10 ( V_11 , ( T_1 * ) V_33 , ( T_1 * ) V_33 ) ;
F_17 ( V_22 , V_22 , ( T_2 * ) V_33 ) ;
V_18 += 1 ;
V_22 += 1 ;
V_2 -= V_13 ;
} while ( V_2 >= V_13 );
V_23:
F_21 ( ( T_3 * ) V_8 -> V_25 , & V_31 ) ;
return V_2 ;
}
static int F_31 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
bool V_1 = false ;
struct V_7 V_8 ;
int V_14 ;
F_14 ( & V_8 , V_22 , V_18 , V_2 ) ;
V_14 = F_32 ( V_6 , & V_8 , V_3 ) ;
V_6 -> V_15 &= ~ V_16 ;
while ( ( V_2 = V_8 . V_2 ) >= V_3 ) {
V_1 = F_1 ( V_1 , V_2 ) ;
V_2 = F_29 ( V_6 , & V_8 ) ;
V_14 = F_12 ( V_6 , & V_8 , V_2 ) ;
}
F_3 ( V_1 ) ;
if ( V_8 . V_2 ) {
F_26 ( V_6 , & V_8 ) ;
V_14 = F_12 ( V_6 , & V_8 , 0 ) ;
}
return V_14 ;
}
static void F_33 ( void * V_34 , T_1 * V_35 , unsigned int V_2 )
{
const unsigned int V_13 = V_3 ;
struct V_36 * V_11 = V_34 ;
int V_28 ;
V_11 -> V_1 = F_1 ( V_11 -> V_1 , V_2 ) ;
if ( V_2 == V_13 * V_4 ) {
F_8 ( V_11 -> V_11 , V_35 , V_35 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_2 / V_13 ; V_28 ++ , V_35 += V_13 )
F_10 ( V_11 -> V_11 , V_35 , V_35 ) ;
}
static void F_34 ( void * V_34 , T_1 * V_35 , unsigned int V_2 )
{
const unsigned int V_13 = V_3 ;
struct V_36 * V_11 = V_34 ;
int V_28 ;
V_11 -> V_1 = F_1 ( V_11 -> V_1 , V_2 ) ;
if ( V_2 == V_13 * V_4 ) {
F_9 ( V_11 -> V_11 , V_35 , V_35 ) ;
return;
}
for ( V_28 = 0 ; V_28 < V_2 / V_13 ; V_28 ++ , V_35 += V_13 )
F_11 ( V_11 -> V_11 , V_35 , V_35 ) ;
}
static int F_35 ( struct V_37 * V_12 , const T_1 * V_38 ,
unsigned int V_39 )
{
struct V_40 * V_11 = F_36 ( V_12 ) ;
int V_14 ;
V_14 = F_37 ( & V_11 -> V_10 , V_38 , V_39 -
V_3 ) ;
if ( V_14 )
return V_14 ;
return F_38 ( & V_11 -> V_41 , V_38 + V_39 -
V_3 ) ;
}
static int F_39 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
struct V_40 * V_11 = F_6 ( V_6 -> V_12 ) ;
T_3 V_42 [ V_4 ] ;
struct V_36 V_43 = {
. V_11 = & V_11 -> V_10 ,
. V_1 = false ,
} ;
struct V_44 V_45 = {
. V_46 = V_42 ,
. V_47 = sizeof( V_42 ) ,
. V_48 = & V_11 -> V_41 ,
. V_43 = & V_43 ,
. V_49 = F_33 ,
} ;
int V_50 ;
V_6 -> V_15 &= ~ V_16 ;
V_50 = F_40 ( V_6 , V_22 , V_18 , V_2 , & V_45 ) ;
F_3 ( V_43 . V_1 ) ;
return V_50 ;
}
static int F_41 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
struct V_40 * V_11 = F_6 ( V_6 -> V_12 ) ;
T_3 V_42 [ V_4 ] ;
struct V_36 V_43 = {
. V_11 = & V_11 -> V_10 ,
. V_1 = false ,
} ;
struct V_44 V_45 = {
. V_46 = V_42 ,
. V_47 = sizeof( V_42 ) ,
. V_48 = & V_11 -> V_41 ,
. V_43 = & V_43 ,
. V_49 = F_34 ,
} ;
int V_50 ;
V_6 -> V_15 &= ~ V_16 ;
V_50 = F_40 ( V_6 , V_22 , V_18 , V_2 , & V_45 ) ;
F_3 ( V_43 . V_1 ) ;
return V_50 ;
}
static void F_42 ( struct V_37 * V_12 )
{
struct V_40 * V_11 = F_36 ( V_12 ) ;
F_43 ( & V_11 -> V_41 ) ;
}
static int F_44 ( struct V_37 * V_12 , const T_1 * V_38 ,
unsigned int V_39 )
{
struct V_51 * V_11 = F_36 ( V_12 ) ;
T_4 * V_15 = & V_12 -> V_52 ;
int V_14 ;
if ( V_39 % 2 ) {
* V_15 |= V_53 ;
return - V_54 ;
}
V_14 = F_37 ( & V_11 -> V_43 , V_38 , V_39 / 2 ) ;
if ( V_14 )
return V_14 ;
return F_37 ( & V_11 -> V_55 , V_38 + V_39 / 2 , V_39 / 2 ) ;
}
static int F_45 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
struct V_51 * V_11 = F_6 ( V_6 -> V_12 ) ;
T_3 V_42 [ V_4 ] ;
struct V_36 V_43 = {
. V_11 = & V_11 -> V_43 ,
. V_1 = false ,
} ;
struct V_56 V_45 = {
. V_46 = V_42 ,
. V_47 = sizeof( V_42 ) ,
. V_55 = & V_11 -> V_55 ,
. V_57 = F_46 ( F_10 ) ,
. V_43 = & V_43 ,
. V_49 = F_33 ,
} ;
int V_50 ;
V_6 -> V_15 &= ~ V_16 ;
V_50 = F_47 ( V_6 , V_22 , V_18 , V_2 , & V_45 ) ;
F_3 ( V_43 . V_1 ) ;
return V_50 ;
}
static int F_48 ( struct V_5 * V_6 , struct V_24 * V_22 ,
struct V_24 * V_18 , unsigned int V_2 )
{
struct V_51 * V_11 = F_6 ( V_6 -> V_12 ) ;
T_3 V_42 [ V_4 ] ;
struct V_36 V_43 = {
. V_11 = & V_11 -> V_43 ,
. V_1 = false ,
} ;
struct V_56 V_45 = {
. V_46 = V_42 ,
. V_47 = sizeof( V_42 ) ,
. V_55 = & V_11 -> V_55 ,
. V_57 = F_46 ( F_10 ) ,
. V_43 = & V_43 ,
. V_49 = F_34 ,
} ;
int V_50 ;
V_6 -> V_15 &= ~ V_16 ;
V_50 = F_47 ( V_6 , V_22 , V_18 , V_2 , & V_45 ) ;
F_3 ( V_43 . V_1 ) ;
return V_50 ;
}
static int F_49 ( struct V_58 * V_12 , const T_1 * V_38 ,
unsigned int V_59 )
{
struct V_60 * V_11 = F_50 ( V_12 ) ;
struct V_58 * V_61 = & V_11 -> V_62 -> V_63 ;
int V_14 ;
F_51 ( V_61 , V_64 ) ;
F_52 ( V_61 , F_53 ( V_12 )
& V_64 ) ;
V_14 = F_54 ( V_61 , V_38 , V_59 ) ;
F_52 ( V_12 , F_53 ( V_61 )
& V_65 ) ;
return V_14 ;
}
static int F_55 ( struct V_66 * V_45 )
{
struct V_58 * V_12 = F_56 ( V_45 ) ;
struct V_60 * V_11 = F_50 ( V_12 ) ;
struct V_5 V_6 ;
V_6 . V_12 = F_57 ( V_11 -> V_62 ) ;
V_6 . V_67 = V_45 -> V_67 ;
V_6 . V_15 = 0 ;
return F_58 ( V_6 . V_12 ) -> F_59 (
& V_6 , V_45 -> V_22 , V_45 -> V_18 , V_45 -> V_2 ) ;
}
static int F_60 ( struct V_66 * V_45 )
{
struct V_58 * V_12 = F_56 ( V_45 ) ;
struct V_60 * V_11 = F_50 ( V_12 ) ;
if ( ! F_61 () ) {
struct V_66 * V_68 =
F_62 ( V_45 ) ;
memcpy ( V_68 , V_45 , sizeof( * V_45 ) ) ;
F_63 ( V_68 , & V_11 -> V_62 -> V_63 ) ;
return F_64 ( V_68 ) ;
} else {
return F_55 ( V_45 ) ;
}
}
static int F_65 ( struct V_66 * V_45 )
{
struct V_58 * V_12 = F_56 ( V_45 ) ;
struct V_60 * V_11 = F_50 ( V_12 ) ;
if ( ! F_61 () ) {
struct V_66 * V_68 =
F_62 ( V_45 ) ;
memcpy ( V_68 , V_45 , sizeof( * V_45 ) ) ;
F_63 ( V_68 , & V_11 -> V_62 -> V_63 ) ;
return F_66 ( V_68 ) ;
} else {
struct V_5 V_6 ;
V_6 . V_12 = F_57 ( V_11 -> V_62 ) ;
V_6 . V_67 = V_45 -> V_67 ;
V_6 . V_15 = 0 ;
return F_58 ( V_6 . V_12 ) -> F_67 (
& V_6 , V_45 -> V_22 , V_45 -> V_18 , V_45 -> V_2 ) ;
}
}
static void F_68 ( struct V_37 * V_12 )
{
struct V_60 * V_11 = F_36 ( V_12 ) ;
F_69 ( V_11 -> V_62 ) ;
}
static void F_70 ( struct V_37 * V_12 ,
struct V_69 * V_62 )
{
struct V_60 * V_11 = F_36 ( V_12 ) ;
V_11 -> V_62 = V_62 ;
V_12 -> V_70 . V_71 = sizeof( struct V_66 ) +
F_71 ( & V_62 -> V_63 ) ;
}
static int F_72 ( struct V_37 * V_12 )
{
struct V_69 * V_62 ;
V_62 = F_73 ( L_1 , 0 , 0 ) ;
if ( F_74 ( V_62 ) )
return F_75 ( V_62 ) ;
F_70 ( V_12 , V_62 ) ;
return 0 ;
}
static int F_76 ( struct V_37 * V_12 )
{
struct V_69 * V_62 ;
V_62 = F_73 ( L_2 , 0 , 0 ) ;
if ( F_74 ( V_62 ) )
return F_75 ( V_62 ) ;
F_70 ( V_12 , V_62 ) ;
return 0 ;
}
static int F_77 ( struct V_37 * V_12 )
{
struct V_69 * V_62 ;
V_62 = F_73 ( L_3 , 0 , 0 ) ;
if ( F_74 ( V_62 ) )
return F_75 ( V_62 ) ;
F_70 ( V_12 , V_62 ) ;
return 0 ;
}
static int F_78 ( struct V_37 * V_12 )
{
struct V_69 * V_62 ;
V_62 = F_73 ( L_4 , 0 , 0 ) ;
if ( F_74 ( V_62 ) )
return F_75 ( V_62 ) ;
F_70 ( V_12 , V_62 ) ;
return 0 ;
}
static int F_79 ( struct V_37 * V_12 )
{
struct V_69 * V_62 ;
V_62 = F_73 ( L_5 , 0 , 0 ) ;
if ( F_74 ( V_62 ) )
return F_75 ( V_62 ) ;
F_70 ( V_12 , V_62 ) ;
return 0 ;
}
static int T_5 F_80 ( void )
{
int V_14 ;
if ( ! V_72 ) {
F_81 ( V_73 L_6 ) ;
return - V_74 ;
}
V_14 = F_82 ( & V_75 ) ;
if ( V_14 )
goto V_76;
V_14 = F_82 ( & V_77 ) ;
if ( V_14 )
goto V_78;
V_14 = F_82 ( & V_79 ) ;
if ( V_14 )
goto V_80;
V_14 = F_82 ( & V_81 ) ;
if ( V_14 )
goto V_82;
V_14 = F_82 ( & V_83 ) ;
if ( V_14 )
goto V_84;
V_14 = F_82 ( & V_85 ) ;
if ( V_14 )
goto V_86;
V_14 = F_82 ( & V_87 ) ;
if ( V_14 )
goto V_88;
V_14 = F_82 ( & V_89 ) ;
if ( V_14 )
goto V_90;
V_14 = F_82 ( & V_91 ) ;
if ( V_14 )
goto V_92;
V_14 = F_82 ( & V_93 ) ;
if ( V_14 )
goto V_94;
return V_14 ;
F_83 ( & V_93 ) ;
V_94:
F_83 ( & V_91 ) ;
V_92:
F_83 ( & V_89 ) ;
V_90:
F_83 ( & V_87 ) ;
V_88:
F_83 ( & V_85 ) ;
V_86:
F_83 ( & V_83 ) ;
V_84:
F_83 ( & V_81 ) ;
V_82:
F_83 ( & V_79 ) ;
V_80:
F_83 ( & V_77 ) ;
V_78:
F_83 ( & V_75 ) ;
V_76:
return V_14 ;
}
static void T_6 F_84 ( void )
{
F_83 ( & V_93 ) ;
F_83 ( & V_91 ) ;
F_83 ( & V_89 ) ;
F_83 ( & V_87 ) ;
F_83 ( & V_85 ) ;
F_83 ( & V_83 ) ;
F_83 ( & V_81 ) ;
F_83 ( & V_79 ) ;
F_83 ( & V_77 ) ;
F_83 ( & V_75 ) ;
}
