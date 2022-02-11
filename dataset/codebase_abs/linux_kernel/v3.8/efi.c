static int T_1
F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
static inline T_2
F_2 ( const void * V_3 , unsigned long V_4 )
{
return ( F_3 ( ~ 0L , V_3 , V_4 ) ^ ~ 0L ) ;
}
static T_3 F_4 ( struct V_5 * V_6 )
{
if ( ! V_6 || ! V_6 -> V_7 )
return 0 ;
return F_5 ( V_6 -> V_7 -> V_8 ,
F_6 ( V_6 ) ) - 1ULL ;
}
static inline int
F_7 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 == V_12 &&
F_8 ( V_10 -> V_13 ) == 1UL )
return 1 ;
return 0 ;
}
static int
F_9 ( T_4 * V_14 )
{
int V_15 ;
if ( ! V_14 || F_10 ( V_14 -> V_16 ) != V_17 )
return 0 ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ )
if ( F_7 ( & V_14 -> V_18 [ V_15 ] ) )
return 1 ;
return 0 ;
}
static T_5 F_11 ( struct V_19 * V_20 ,
T_3 V_21 , T_6 * V_22 , T_5 V_23 )
{
T_5 V_24 = 0 ;
struct V_5 * V_6 = V_20 -> V_6 ;
T_7 V_25 = V_21 * ( F_6 ( V_6 ) / 512 ) ;
if ( ! V_22 || V_21 > F_4 ( V_6 ) )
return 0 ;
while ( V_23 ) {
int V_26 = 512 ;
T_8 V_27 ;
unsigned char * V_28 = F_12 ( V_20 , V_25 ++ , & V_27 ) ;
if ( ! V_28 )
break;
if ( V_26 > V_23 )
V_26 = V_23 ;
memcpy ( V_22 , V_28 , V_26 ) ;
F_13 ( V_27 ) ;
V_22 += V_26 ;
V_24 += V_26 ;
V_23 -= V_26 ;
}
return V_24 ;
}
static T_9 * F_14 ( struct V_19 * V_20 ,
T_10 * V_29 )
{
T_5 V_23 ;
T_9 * V_30 ;
if ( ! V_29 )
return NULL ;
V_23 = F_8 ( V_29 -> V_31 ) *
F_8 ( V_29 -> V_32 ) ;
if ( ! V_23 )
return NULL ;
V_30 = F_15 ( V_23 , V_33 ) ;
if ( ! V_30 )
return NULL ;
if ( F_11 ( V_20 , F_16 ( V_29 -> V_34 ) ,
( T_6 * ) V_30 ,
V_23 ) < V_23 ) {
F_17 ( V_30 ) ;
V_30 = NULL ;
return NULL ;
}
return V_30 ;
}
static T_10 * F_18 ( struct V_19 * V_20 ,
T_3 V_21 )
{
T_10 * V_29 ;
unsigned V_35 = F_6 ( V_20 -> V_6 ) ;
V_29 = F_15 ( V_35 , V_33 ) ;
if ( ! V_29 )
return NULL ;
if ( F_11 ( V_20 , V_21 , ( T_6 * ) V_29 , V_35 ) < V_35 ) {
F_17 ( V_29 ) ;
V_29 = NULL ;
return NULL ;
}
return V_29 ;
}
static int F_19 ( struct V_19 * V_20 , T_3 V_21 ,
T_10 * * V_29 , T_9 * * V_36 )
{
T_2 V_37 , V_38 ;
T_3 V_39 ;
if ( ! V_36 )
return 0 ;
if ( ! ( * V_29 = F_18 ( V_20 , V_21 ) ) )
return 0 ;
if ( F_16 ( ( * V_29 ) -> V_16 ) != V_40 ) {
F_20 ( L_1
L_2 ,
( unsigned long long ) F_16 ( ( * V_29 ) -> V_16 ) ,
( unsigned long long ) V_40 ) ;
goto V_41;
}
if ( F_8 ( ( * V_29 ) -> V_42 ) >
F_6 ( V_20 -> V_6 ) ) {
F_20 ( L_3 ,
F_8 ( ( * V_29 ) -> V_42 ) ,
F_6 ( V_20 -> V_6 ) ) ;
goto V_41;
}
V_38 = F_8 ( ( * V_29 ) -> V_43 ) ;
( * V_29 ) -> V_43 = 0 ;
V_37 = F_2 ( ( const unsigned char * ) ( * V_29 ) , F_8 ( ( * V_29 ) -> V_42 ) ) ;
if ( V_37 != V_38 ) {
F_20 ( L_4 ,
V_37 , V_38 ) ;
goto V_41;
}
( * V_29 ) -> V_43 = F_21 ( V_38 ) ;
if ( F_16 ( ( * V_29 ) -> V_44 ) != V_21 ) {
F_20 ( L_5 ,
( unsigned long long ) F_16 ( ( * V_29 ) -> V_44 ) ,
( unsigned long long ) V_21 ) ;
goto V_41;
}
V_39 = F_4 ( V_20 -> V_6 ) ;
if ( F_16 ( ( * V_29 ) -> V_45 ) > V_39 ) {
F_20 ( L_6 ,
( unsigned long long ) F_16 ( ( * V_29 ) -> V_45 ) ,
( unsigned long long ) V_39 ) ;
goto V_41;
}
if ( F_16 ( ( * V_29 ) -> V_46 ) > V_39 ) {
F_20 ( L_7 ,
( unsigned long long ) F_16 ( ( * V_29 ) -> V_46 ) ,
( unsigned long long ) V_39 ) ;
goto V_41;
}
if ( F_8 ( ( * V_29 ) -> V_32 ) != sizeof( T_9 ) ) {
F_20 ( L_8 ) ;
goto V_41;
}
if ( ! ( * V_36 = F_14 ( V_20 , * V_29 ) ) )
goto V_41;
V_37 = F_2 ( ( const unsigned char * ) ( * V_36 ) ,
F_8 ( ( * V_29 ) -> V_31 ) *
F_8 ( ( * V_29 ) -> V_32 ) ) ;
if ( V_37 != F_8 ( ( * V_29 ) -> V_47 ) ) {
F_20 ( L_9 ) ;
goto V_48;
}
return 1 ;
V_48:
F_17 ( * V_36 ) ;
* V_36 = NULL ;
V_41:
F_17 ( * V_29 ) ;
* V_29 = NULL ;
return 0 ;
}
static inline int
F_22 ( const T_9 * V_30 , const T_3 V_39 )
{
if ( ( ! F_23 ( V_30 -> V_49 , V_50 ) ) ||
F_16 ( V_30 -> V_51 ) > V_39 ||
F_16 ( V_30 -> V_52 ) > V_39 )
return 0 ;
return 1 ;
}
static void
F_24 ( T_10 * V_53 , T_10 * V_54 , T_3 V_39 )
{
int V_55 = 0 ;
if ( ! V_53 || ! V_54 )
return;
if ( F_16 ( V_53 -> V_44 ) != F_16 ( V_54 -> V_56 ) ) {
F_25 ( V_57
L_10 ) ;
F_25 ( V_57 L_11 ,
( unsigned long long ) F_16 ( V_53 -> V_44 ) ,
( unsigned long long ) F_16 ( V_54 -> V_56 ) ) ;
V_55 ++ ;
}
if ( F_16 ( V_53 -> V_56 ) != F_16 ( V_54 -> V_44 ) ) {
F_25 ( V_57
L_12 ) ;
F_25 ( V_57 L_11 ,
( unsigned long long ) F_16 ( V_53 -> V_56 ) ,
( unsigned long long ) F_16 ( V_54 -> V_44 ) ) ;
V_55 ++ ;
}
if ( F_16 ( V_53 -> V_45 ) !=
F_16 ( V_54 -> V_45 ) ) {
F_25 ( V_57 L_13 ) ;
F_25 ( V_57 L_11 ,
( unsigned long long ) F_16 ( V_53 -> V_45 ) ,
( unsigned long long ) F_16 ( V_54 -> V_45 ) ) ;
V_55 ++ ;
}
if ( F_16 ( V_53 -> V_46 ) !=
F_16 ( V_54 -> V_46 ) ) {
F_25 ( V_57 L_14 ) ;
F_25 ( V_57 L_11 ,
( unsigned long long ) F_16 ( V_53 -> V_46 ) ,
( unsigned long long ) F_16 ( V_54 -> V_46 ) ) ;
V_55 ++ ;
}
if ( F_23 ( V_53 -> V_58 , V_54 -> V_58 ) ) {
F_25 ( V_57 L_15 ) ;
V_55 ++ ;
}
if ( F_8 ( V_53 -> V_31 ) !=
F_8 ( V_54 -> V_31 ) ) {
F_25 ( V_57 L_16
L_17 ,
F_8 ( V_53 -> V_31 ) ,
F_8 ( V_54 -> V_31 ) ) ;
V_55 ++ ;
}
if ( F_8 ( V_53 -> V_32 ) !=
F_8 ( V_54 -> V_32 ) ) {
F_25 ( V_57
L_18
L_17 ,
F_8 ( V_53 -> V_32 ) ,
F_8 ( V_54 -> V_32 ) ) ;
V_55 ++ ;
}
if ( F_8 ( V_53 -> V_47 ) !=
F_8 ( V_54 -> V_47 ) ) {
F_25 ( V_57
L_19
L_17 ,
F_8 ( V_53 -> V_47 ) ,
F_8 ( V_54 -> V_47 ) ) ;
V_55 ++ ;
}
if ( F_16 ( V_53 -> V_56 ) != V_39 ) {
F_25 ( V_57
L_20 ) ;
F_25 ( V_57 L_11 ,
( unsigned long long ) F_16 ( V_53 -> V_56 ) ,
( unsigned long long ) V_39 ) ;
V_55 ++ ;
}
if ( F_16 ( V_54 -> V_44 ) != V_39 ) {
F_25 ( V_57
L_21 ) ;
F_25 ( V_57 L_11 ,
( unsigned long long ) F_16 ( V_54 -> V_44 ) ,
( unsigned long long ) V_39 ) ;
V_55 ++ ;
}
if ( V_55 )
F_25 ( V_57
L_22 ) ;
return;
}
static int F_26 ( struct V_19 * V_20 , T_10 * * V_29 ,
T_9 * * V_36 )
{
int V_59 = 0 , V_60 = 0 , V_61 = 0 ;
T_10 * V_53 = NULL , * V_54 = NULL ;
T_9 * V_62 = NULL , * V_63 = NULL ;
T_4 * V_64 ;
T_3 V_39 ;
if ( ! V_36 )
return 0 ;
V_39 = F_4 ( V_20 -> V_6 ) ;
if ( ! V_2 ) {
V_64 = F_15 ( sizeof ( * V_64 ) , V_33 ) ;
if ( V_64 ) {
F_11 ( V_20 , 0 , ( T_6 * ) V_64 ,
sizeof ( * V_64 ) ) ;
V_61 = F_9 ( V_64 ) ;
F_17 ( V_64 ) ;
}
if ( ! V_61 )
goto V_41;
}
V_59 = F_19 ( V_20 , V_65 ,
& V_53 , & V_62 ) ;
if ( V_59 )
V_60 = F_19 ( V_20 ,
F_16 ( V_53 -> V_56 ) ,
& V_54 , & V_63 ) ;
if ( ! V_60 && V_2 )
V_60 = F_19 ( V_20 , V_39 , & V_54 , & V_63 ) ;
if ( ! V_59 && ! V_60 )
goto V_41;
F_24 ( V_53 , V_54 , V_39 ) ;
if ( V_59 ) {
* V_29 = V_53 ;
* V_36 = V_62 ;
F_17 ( V_54 ) ;
F_17 ( V_63 ) ;
if ( ! V_60 ) {
F_25 ( V_57
L_23
L_24 ) ;
}
return 1 ;
}
else if ( V_60 ) {
* V_29 = V_54 ;
* V_36 = V_63 ;
F_17 ( V_53 ) ;
F_17 ( V_62 ) ;
F_25 ( V_57
L_25 ) ;
return 1 ;
}
V_41:
F_17 ( V_53 ) ;
F_17 ( V_54 ) ;
F_17 ( V_62 ) ;
F_17 ( V_63 ) ;
* V_29 = NULL ;
* V_36 = NULL ;
return 0 ;
}
int F_27 ( struct V_19 * V_20 )
{
T_10 * V_29 = NULL ;
T_9 * V_36 = NULL ;
T_2 V_15 ;
unsigned V_35 = F_6 ( V_20 -> V_6 ) / 512 ;
if ( ! F_26 ( V_20 , & V_29 , & V_36 ) || ! V_29 || ! V_36 ) {
F_17 ( V_29 ) ;
F_17 ( V_36 ) ;
return 0 ;
}
F_20 ( L_26 ) ;
for ( V_15 = 0 ; V_15 < F_8 ( V_29 -> V_31 ) && V_15 < V_20 -> V_66 - 1 ; V_15 ++ ) {
struct V_67 * V_68 ;
unsigned V_69 = 0 ;
unsigned V_70 ;
T_3 V_71 = F_16 ( V_36 [ V_15 ] . V_51 ) ;
T_3 V_72 = F_16 ( V_36 [ V_15 ] . V_52 ) -
F_16 ( V_36 [ V_15 ] . V_51 ) + 1ULL ;
if ( ! F_22 ( & V_36 [ V_15 ] , F_4 ( V_20 -> V_6 ) ) )
continue;
F_28 ( V_20 , V_15 + 1 , V_71 * V_35 , V_72 * V_35 ) ;
if ( ! F_23 ( V_36 [ V_15 ] . V_49 ,
V_73 ) )
V_20 -> V_74 [ V_15 + 1 ] . V_75 = V_76 ;
V_68 = & V_20 -> V_74 [ V_15 + 1 ] . V_68 ;
F_29 ( & V_36 [ V_15 ] . V_77 , V_68 -> V_78 ) ;
V_70 = F_30 ( sizeof( V_68 -> V_79 ) - 1 ,
sizeof( V_36 [ V_15 ] . V_80 ) ) ;
V_68 -> V_79 [ V_70 ] = 0 ;
while ( V_69 < V_70 ) {
T_6 V_81 = V_36 [ V_15 ] . V_80 [ V_69 ] & 0xff ;
if ( V_81 && ! isprint ( V_81 ) )
V_81 = '!' ;
V_68 -> V_79 [ V_69 ] = V_81 ;
V_69 ++ ;
}
V_20 -> V_74 [ V_15 + 1 ] . V_82 = true ;
}
F_17 ( V_36 ) ;
F_17 ( V_29 ) ;
F_31 ( V_20 -> V_83 , L_27 , V_84 ) ;
return 1 ;
}
