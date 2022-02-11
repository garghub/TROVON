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
static inline int F_7 ( T_4 * V_9 )
{
if ( V_9 -> V_10 != V_11 )
goto V_12;
if ( F_8 ( V_9 -> V_13 ) != V_14 )
goto V_12;
return V_15 ;
V_12:
return 0 ;
}
static int F_9 ( T_5 * V_16 , T_6 V_17 )
{
T_7 V_18 = 0 ;
int V_19 , V_9 = 0 , V_20 = 0 ;
if ( ! V_16 || F_10 ( V_16 -> V_21 ) != V_22 )
goto V_23;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
V_20 = F_7 ( & V_16 -> V_24 [ V_19 ] ) ;
if ( V_20 == V_15 ) {
V_9 = V_19 ;
goto V_25;
}
}
if ( V_20 != V_15 )
goto V_23;
V_25:
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ )
if ( ( V_16 -> V_24 [ V_19 ] . V_10 !=
V_11 ) &&
( V_16 -> V_24 [ V_19 ] . V_10 != 0x00 ) )
V_20 = V_26 ;
if ( V_20 == V_15 ) {
V_18 = F_8 ( V_16 -> V_24 [ V_9 ] . V_27 ) ;
if ( V_18 != ( T_7 ) V_17 - 1 && V_18 != 0xFFFFFFFF )
F_11 ( L_1 ,
V_18 , F_12 ( T_7 ,
V_17 - 1 , 0xFFFFFFFF ) ) ;
}
V_23:
return V_20 ;
}
static T_8 F_13 ( struct V_28 * V_29 ,
T_3 V_30 , T_9 * V_31 , T_8 V_32 )
{
T_8 V_33 = 0 ;
struct V_5 * V_6 = V_29 -> V_6 ;
T_6 V_34 = V_30 * ( F_6 ( V_6 ) / 512 ) ;
if ( ! V_31 || V_30 > F_4 ( V_6 ) )
return 0 ;
while ( V_32 ) {
int V_35 = 512 ;
T_10 V_36 ;
unsigned char * V_37 = F_14 ( V_29 , V_34 ++ , & V_36 ) ;
if ( ! V_37 )
break;
if ( V_35 > V_32 )
V_35 = V_32 ;
memcpy ( V_31 , V_37 , V_35 ) ;
F_15 ( V_36 ) ;
V_31 += V_35 ;
V_33 += V_35 ;
V_32 -= V_35 ;
}
return V_33 ;
}
static T_11 * F_16 ( struct V_28 * V_29 ,
T_12 * V_38 )
{
T_8 V_32 ;
T_11 * V_39 ;
if ( ! V_38 )
return NULL ;
V_32 = F_8 ( V_38 -> V_40 ) *
F_8 ( V_38 -> V_41 ) ;
if ( ! V_32 )
return NULL ;
V_39 = F_17 ( V_32 , V_42 ) ;
if ( ! V_39 )
return NULL ;
if ( F_13 ( V_29 , F_18 ( V_38 -> V_43 ) ,
( T_9 * ) V_39 , V_32 ) < V_32 ) {
F_19 ( V_39 ) ;
V_39 = NULL ;
return NULL ;
}
return V_39 ;
}
static T_12 * F_20 ( struct V_28 * V_29 ,
T_3 V_30 )
{
T_12 * V_38 ;
unsigned V_44 = F_6 ( V_29 -> V_6 ) ;
V_38 = F_17 ( V_44 , V_42 ) ;
if ( ! V_38 )
return NULL ;
if ( F_13 ( V_29 , V_30 , ( T_9 * ) V_38 , V_44 ) < V_44 ) {
F_19 ( V_38 ) ;
V_38 = NULL ;
return NULL ;
}
return V_38 ;
}
static int F_21 ( struct V_28 * V_29 , T_3 V_30 ,
T_12 * * V_38 , T_11 * * V_45 )
{
T_2 V_46 , V_47 ;
T_3 V_48 ;
if ( ! V_45 )
return 0 ;
if ( ! ( * V_38 = F_20 ( V_29 , V_30 ) ) )
return 0 ;
if ( F_18 ( ( * V_38 ) -> V_21 ) != V_49 ) {
F_11 ( L_2
L_3 ,
( unsigned long long ) F_18 ( ( * V_38 ) -> V_21 ) ,
( unsigned long long ) V_49 ) ;
goto V_50;
}
if ( F_8 ( ( * V_38 ) -> V_51 ) >
F_6 ( V_29 -> V_6 ) ) {
F_11 ( L_4 ,
F_8 ( ( * V_38 ) -> V_51 ) ,
F_6 ( V_29 -> V_6 ) ) ;
goto V_50;
}
if ( F_8 ( ( * V_38 ) -> V_51 ) < sizeof( T_12 ) ) {
F_11 ( L_5 ,
F_8 ( ( * V_38 ) -> V_51 ) ,
sizeof( T_12 ) ) ;
goto V_50;
}
V_47 = F_8 ( ( * V_38 ) -> V_52 ) ;
( * V_38 ) -> V_52 = 0 ;
V_46 = F_2 ( ( const unsigned char * ) ( * V_38 ) , F_8 ( ( * V_38 ) -> V_51 ) ) ;
if ( V_46 != V_47 ) {
F_11 ( L_6 ,
V_46 , V_47 ) ;
goto V_50;
}
( * V_38 ) -> V_52 = F_22 ( V_47 ) ;
if ( F_18 ( ( * V_38 ) -> V_53 ) != V_30 ) {
F_11 ( L_7 ,
( unsigned long long ) F_18 ( ( * V_38 ) -> V_53 ) ,
( unsigned long long ) V_30 ) ;
goto V_50;
}
V_48 = F_4 ( V_29 -> V_6 ) ;
if ( F_18 ( ( * V_38 ) -> V_54 ) > V_48 ) {
F_11 ( L_8 ,
( unsigned long long ) F_18 ( ( * V_38 ) -> V_54 ) ,
( unsigned long long ) V_48 ) ;
goto V_50;
}
if ( F_18 ( ( * V_38 ) -> V_55 ) > V_48 ) {
F_11 ( L_9 ,
( unsigned long long ) F_18 ( ( * V_38 ) -> V_55 ) ,
( unsigned long long ) V_48 ) ;
goto V_50;
}
if ( F_18 ( ( * V_38 ) -> V_55 ) < F_18 ( ( * V_38 ) -> V_54 ) ) {
F_11 ( L_9 ,
( unsigned long long ) F_18 ( ( * V_38 ) -> V_55 ) ,
( unsigned long long ) F_18 ( ( * V_38 ) -> V_54 ) ) ;
goto V_50;
}
if ( F_8 ( ( * V_38 ) -> V_41 ) != sizeof( T_11 ) ) {
F_11 ( L_10 ) ;
goto V_50;
}
if ( ! ( * V_45 = F_16 ( V_29 , * V_38 ) ) )
goto V_50;
V_46 = F_2 ( ( const unsigned char * ) ( * V_45 ) ,
F_8 ( ( * V_38 ) -> V_40 ) *
F_8 ( ( * V_38 ) -> V_41 ) ) ;
if ( V_46 != F_8 ( ( * V_38 ) -> V_56 ) ) {
F_11 ( L_11 ) ;
goto V_57;
}
return 1 ;
V_57:
F_19 ( * V_45 ) ;
* V_45 = NULL ;
V_50:
F_19 ( * V_38 ) ;
* V_38 = NULL ;
return 0 ;
}
static inline int
F_23 ( const T_11 * V_39 , const T_3 V_48 )
{
if ( ( ! F_24 ( V_39 -> V_58 , V_59 ) ) ||
F_18 ( V_39 -> V_13 ) > V_48 ||
F_18 ( V_39 -> V_60 ) > V_48 )
return 0 ;
return 1 ;
}
static void
F_25 ( T_12 * V_61 , T_12 * V_62 , T_3 V_48 )
{
int V_63 = 0 ;
if ( ! V_61 || ! V_62 )
return;
if ( F_18 ( V_61 -> V_53 ) != F_18 ( V_62 -> V_64 ) ) {
F_26 ( L_12 ) ;
F_26 ( L_13 ,
( unsigned long long ) F_18 ( V_61 -> V_53 ) ,
( unsigned long long ) F_18 ( V_62 -> V_64 ) ) ;
V_63 ++ ;
}
if ( F_18 ( V_61 -> V_64 ) != F_18 ( V_62 -> V_53 ) ) {
F_26 ( L_14 ) ;
F_26 ( L_13 ,
( unsigned long long ) F_18 ( V_61 -> V_64 ) ,
( unsigned long long ) F_18 ( V_62 -> V_53 ) ) ;
V_63 ++ ;
}
if ( F_18 ( V_61 -> V_54 ) !=
F_18 ( V_62 -> V_54 ) ) {
F_26 ( L_15 ) ;
F_26 ( L_13 ,
( unsigned long long ) F_18 ( V_61 -> V_54 ) ,
( unsigned long long ) F_18 ( V_62 -> V_54 ) ) ;
V_63 ++ ;
}
if ( F_18 ( V_61 -> V_55 ) !=
F_18 ( V_62 -> V_55 ) ) {
F_26 ( L_16 ) ;
F_26 ( L_13 ,
( unsigned long long ) F_18 ( V_61 -> V_55 ) ,
( unsigned long long ) F_18 ( V_62 -> V_55 ) ) ;
V_63 ++ ;
}
if ( F_24 ( V_61 -> V_65 , V_62 -> V_65 ) ) {
F_26 ( L_17 ) ;
V_63 ++ ;
}
if ( F_8 ( V_61 -> V_40 ) !=
F_8 ( V_62 -> V_40 ) ) {
F_26 ( L_18
L_19 ,
F_8 ( V_61 -> V_40 ) ,
F_8 ( V_62 -> V_40 ) ) ;
V_63 ++ ;
}
if ( F_8 ( V_61 -> V_41 ) !=
F_8 ( V_62 -> V_41 ) ) {
F_26 ( L_20
L_19 ,
F_8 ( V_61 -> V_41 ) ,
F_8 ( V_62 -> V_41 ) ) ;
V_63 ++ ;
}
if ( F_8 ( V_61 -> V_56 ) !=
F_8 ( V_62 -> V_56 ) ) {
F_26 ( L_21
L_19 ,
F_8 ( V_61 -> V_56 ) ,
F_8 ( V_62 -> V_56 ) ) ;
V_63 ++ ;
}
if ( F_18 ( V_61 -> V_64 ) != V_48 ) {
F_26 ( L_22 ) ;
F_26 ( L_13 ,
( unsigned long long ) F_18 ( V_61 -> V_64 ) ,
( unsigned long long ) V_48 ) ;
V_63 ++ ;
}
if ( F_18 ( V_62 -> V_53 ) != V_48 ) {
F_26 ( L_23 ) ;
F_26 ( L_13 ,
( unsigned long long ) F_18 ( V_62 -> V_53 ) ,
( unsigned long long ) V_48 ) ;
V_63 ++ ;
}
if ( V_63 )
F_26 ( L_24 ) ;
return;
}
static int F_27 ( struct V_28 * V_29 , T_12 * * V_38 ,
T_11 * * V_45 )
{
int V_66 = 0 , V_67 = 0 , V_68 = 0 ;
T_12 * V_61 = NULL , * V_62 = NULL ;
T_11 * V_69 = NULL , * V_70 = NULL ;
T_5 * V_71 ;
T_6 V_17 = F_28 ( V_29 -> V_6 -> V_7 ) >> 9 ;
T_3 V_48 ;
if ( ! V_45 )
return 0 ;
V_48 = F_4 ( V_29 -> V_6 ) ;
if ( ! V_2 ) {
V_71 = F_29 ( sizeof( * V_71 ) , V_42 ) ;
if ( ! V_71 )
goto V_50;
F_13 ( V_29 , 0 , ( T_9 * ) V_71 , sizeof( * V_71 ) ) ;
V_68 = F_9 ( V_71 , V_17 ) ;
F_19 ( V_71 ) ;
if ( ! V_68 )
goto V_50;
F_11 ( L_25 ,
V_68 == V_15 ?
L_26 : L_27 ) ;
}
V_66 = F_21 ( V_29 , V_14 ,
& V_61 , & V_69 ) ;
if ( V_66 )
V_67 = F_21 ( V_29 ,
F_18 ( V_61 -> V_64 ) ,
& V_62 , & V_70 ) ;
if ( ! V_67 && V_2 )
V_67 = F_21 ( V_29 , V_48 , & V_62 , & V_70 ) ;
if ( ! V_66 && ! V_67 )
goto V_50;
F_25 ( V_61 , V_62 , V_48 ) ;
if ( V_66 ) {
* V_38 = V_61 ;
* V_45 = V_69 ;
F_19 ( V_62 ) ;
F_19 ( V_70 ) ;
if ( ! V_67 )
F_26 ( L_28 ) ;
return 1 ;
}
else if ( V_67 ) {
* V_38 = V_62 ;
* V_45 = V_70 ;
F_19 ( V_61 ) ;
F_19 ( V_69 ) ;
F_26 ( L_29 ) ;
return 1 ;
}
V_50:
F_19 ( V_61 ) ;
F_19 ( V_62 ) ;
F_19 ( V_69 ) ;
F_19 ( V_70 ) ;
* V_38 = NULL ;
* V_45 = NULL ;
return 0 ;
}
int F_30 ( struct V_28 * V_29 )
{
T_12 * V_38 = NULL ;
T_11 * V_45 = NULL ;
T_2 V_19 ;
unsigned V_44 = F_6 ( V_29 -> V_6 ) / 512 ;
if ( ! F_27 ( V_29 , & V_38 , & V_45 ) || ! V_38 || ! V_45 ) {
F_19 ( V_38 ) ;
F_19 ( V_45 ) ;
return 0 ;
}
F_11 ( L_30 ) ;
for ( V_19 = 0 ; V_19 < F_8 ( V_38 -> V_40 ) && V_19 < V_29 -> V_72 - 1 ; V_19 ++ ) {
struct V_73 * V_74 ;
unsigned V_75 = 0 ;
unsigned V_76 ;
T_3 V_77 = F_18 ( V_45 [ V_19 ] . V_13 ) ;
T_3 V_78 = F_18 ( V_45 [ V_19 ] . V_60 ) -
F_18 ( V_45 [ V_19 ] . V_13 ) + 1ULL ;
if ( ! F_23 ( & V_45 [ V_19 ] , F_4 ( V_29 -> V_6 ) ) )
continue;
F_31 ( V_29 , V_19 + 1 , V_77 * V_44 , V_78 * V_44 ) ;
if ( ! F_24 ( V_45 [ V_19 ] . V_58 , V_79 ) )
V_29 -> V_80 [ V_19 + 1 ] . V_81 = V_82 ;
V_74 = & V_29 -> V_80 [ V_19 + 1 ] . V_74 ;
F_32 ( & V_45 [ V_19 ] . V_83 , V_74 -> V_84 ) ;
V_76 = F_33 ( sizeof( V_74 -> V_85 ) - 1 ,
sizeof( V_45 [ V_19 ] . V_86 ) ) ;
V_74 -> V_85 [ V_76 ] = 0 ;
while ( V_75 < V_76 ) {
T_9 V_87 = V_45 [ V_19 ] . V_86 [ V_75 ] & 0xff ;
if ( V_87 && ! isprint ( V_87 ) )
V_87 = '!' ;
V_74 -> V_85 [ V_75 ] = V_87 ;
V_75 ++ ;
}
V_29 -> V_80 [ V_19 + 1 ] . V_88 = true ;
}
F_19 ( V_45 ) ;
F_19 ( V_38 ) ;
F_34 ( V_29 -> V_89 , L_31 , V_90 ) ;
return 1 ;
}
