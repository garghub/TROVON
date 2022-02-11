static T_1 F_1 ( const void * V_1 )
{
return F_2 ( F_3 ( V_1 ) ) ;
}
static void F_4 ( T_2 * V_2 , const T_3 * V_3 )
{
memset ( ( void * ) V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
memset ( V_2 -> V_5 , 0xFF , sizeof( V_2 -> V_5 ) ) ;
V_2 -> V_6 = 64 * V_7 ;
V_2 -> V_8 = V_3 - 64 * V_7 ;
V_2 -> V_9 = V_3 ;
V_2 -> V_10 = V_3 - 64 * V_7 ;
V_2 -> V_11 = 64 * V_7 ;
V_2 -> V_12 = 64 * V_7 ;
}
static T_4 void F_5 ( T_2 * V_2 ,
const T_3 * V_13 )
{
T_5 * const V_5 = V_2 -> V_5 ;
T_1 * const V_4 = V_2 -> V_4 ;
const T_3 * const V_8 = V_2 -> V_8 ;
T_1 const V_14 = ( T_1 ) ( V_13 - V_8 ) ;
T_1 V_15 = V_2 -> V_6 ;
while ( V_15 < V_14 ) {
T_1 const V_16 = F_1 ( V_8 + V_15 ) ;
T_6 V_17 = V_15 - V_4 [ V_16 ] ;
if ( V_17 > V_18 )
V_17 = V_18 ;
F_6 ( V_15 ) = ( T_5 ) V_17 ;
V_4 [ V_16 ] = V_15 ;
V_15 ++ ;
}
V_2 -> V_6 = V_14 ;
}
static T_4 int F_7 (
T_2 * V_2 ,
const T_3 * V_13 ,
const T_3 * const V_19 ,
const T_3 * * V_20 ,
const int V_21 )
{
T_5 * const V_5 = V_2 -> V_5 ;
T_1 * const V_22 = V_2 -> V_4 ;
const T_3 * const V_8 = V_2 -> V_8 ;
const T_3 * const V_10 = V_2 -> V_10 ;
const T_1 V_11 = V_2 -> V_11 ;
const T_1 V_12 = ( V_2 -> V_12 + 64 * V_7 > ( T_1 ) ( V_13 - V_8 ) )
? V_2 -> V_12
: ( T_1 ) ( V_13 - V_8 ) - ( 64 * V_7 - 1 ) ;
T_1 V_23 ;
int V_24 = V_21 ;
T_6 V_25 = 0 ;
F_5 ( V_2 , V_13 ) ;
V_23 = V_22 [ F_1 ( V_13 ) ] ;
while ( ( V_23 >= V_12 )
&& ( V_24 ) ) {
V_24 -- ;
if ( V_23 >= V_11 ) {
const T_3 * const V_26 = V_8 + V_23 ;
if ( * ( V_26 + V_25 ) == * ( V_13 + V_25 )
&& ( F_3 ( V_26 ) == F_3 ( V_13 ) ) ) {
T_6 const V_27 = F_8 ( V_13 + V_28 ,
V_26 + V_28 , V_19 ) + V_28 ;
if ( V_27 > V_25 ) {
V_25 = V_27 ;
* V_20 = V_26 ;
}
}
} else {
const T_3 * const V_26 = V_10 + V_23 ;
if ( F_3 ( V_26 ) == F_3 ( V_13 ) ) {
T_6 V_27 ;
const T_3 * V_29 = V_13
+ ( V_11 - V_23 ) ;
if ( V_29 > V_19 )
V_29 = V_19 ;
V_27 = F_8 ( V_13 + V_28 ,
V_26 + V_28 , V_29 ) + V_28 ;
if ( ( V_13 + V_27 == V_29 )
&& ( V_29 < V_19 ) )
V_27 += F_8 ( V_13 + V_27 ,
V_8 + V_11 ,
V_19 ) ;
if ( V_27 > V_25 ) {
V_25 = V_27 ;
* V_20 = V_8 + V_23 ;
}
}
}
V_23 -= F_6 ( V_23 ) ;
}
return ( int ) V_25 ;
}
static T_4 int F_9 (
T_2 * V_2 ,
const T_3 * const V_13 ,
const T_3 * const V_30 ,
const T_3 * const V_31 ,
int V_32 ,
const T_3 * * V_20 ,
const T_3 * * V_33 ,
const int V_21 )
{
T_5 * const V_5 = V_2 -> V_5 ;
T_1 * const V_22 = V_2 -> V_4 ;
const T_3 * const V_8 = V_2 -> V_8 ;
const T_1 V_11 = V_2 -> V_11 ;
const T_3 * const V_34 = V_8 + V_11 ;
const T_1 V_12 = ( V_2 -> V_12 + 64 * V_7 > ( T_1 ) ( V_13 - V_8 ) )
? V_2 -> V_12
: ( T_1 ) ( V_13 - V_8 ) - ( 64 * V_7 - 1 ) ;
const T_3 * const V_10 = V_2 -> V_10 ;
T_1 V_23 ;
int V_24 = V_21 ;
int V_17 = ( int ) ( V_13 - V_30 ) ;
F_5 ( V_2 , V_13 ) ;
V_23 = V_22 [ F_1 ( V_13 ) ] ;
while ( ( V_23 >= V_12 )
&& ( V_24 ) ) {
V_24 -- ;
if ( V_23 >= V_11 ) {
const T_3 * V_35 = V_8 + V_23 ;
if ( * ( V_30 + V_32 )
== * ( V_35 - V_17 + V_32 ) ) {
if ( F_3 ( V_35 ) == F_3 ( V_13 ) ) {
int V_27 = V_28 + F_8 (
V_13 + V_28 ,
V_35 + V_28 ,
V_31 ) ;
int V_36 = 0 ;
while ( ( V_13 + V_36 > V_30 )
&& ( V_35 + V_36 > V_34 )
&& ( V_13 [ V_36 - 1 ] == V_35 [ V_36 - 1 ] ) )
V_36 -- ;
V_27 -= V_36 ;
if ( V_27 > V_32 ) {
V_32 = ( int ) V_27 ;
* V_20 = V_35 + V_36 ;
* V_33 = V_13 + V_36 ;
}
}
}
} else {
const T_3 * const V_35 = V_10 + V_23 ;
if ( F_3 ( V_35 ) == F_3 ( V_13 ) ) {
T_6 V_27 ;
int V_36 = 0 ;
const T_3 * V_29 = V_13 + ( V_11 - V_23 ) ;
if ( V_29 > V_31 )
V_29 = V_31 ;
V_27 = F_8 ( V_13 + V_28 ,
V_35 + V_28 , V_29 ) + V_28 ;
if ( ( V_13 + V_27 == V_29 ) && ( V_29 < V_31 ) )
V_27 += F_8 ( V_13 + V_27 , V_8 + V_11 ,
V_31 ) ;
while ( ( V_13 + V_36 > V_30 )
&& ( V_23 + V_36 > V_12 )
&& ( V_13 [ V_36 - 1 ] == V_35 [ V_36 - 1 ] ) )
V_36 -- ;
V_27 -= V_36 ;
if ( ( int ) V_27 > V_32 ) {
V_32 = ( int ) V_27 ;
* V_20 = V_8 + V_23 + V_36 ;
* V_33 = V_13 + V_36 ;
}
}
}
V_23 -= F_6 ( V_23 ) ;
}
return V_32 ;
}
static T_4 int F_10 (
const T_3 * * V_13 ,
T_3 * * V_37 ,
const T_3 * * V_38 ,
int V_39 ,
const T_3 * const V_26 ,
T_7 V_40 ,
T_3 * V_41 )
{
int V_42 ;
T_3 * V_43 ;
V_42 = ( int ) ( * V_13 - * V_38 ) ;
V_43 = ( * V_37 ) ++ ;
if ( ( V_40 )
&& ( ( * V_37 + ( V_42 >> 8 )
+ V_42 + ( 2 + 1 + V_44 ) ) > V_41 ) ) {
return 1 ;
}
if ( V_42 >= ( int ) V_45 ) {
int V_46 ;
* V_43 = ( V_45 << V_47 ) ;
V_46 = V_42 - V_45 ;
for (; V_46 > 254 ; V_46 -= 255 )
* ( * V_37 ) ++ = 255 ;
* ( * V_37 ) ++ = ( T_3 ) V_46 ;
} else
* V_43 = ( T_3 ) ( V_42 << V_47 ) ;
F_11 ( * V_37 , * V_38 , ( * V_37 ) + V_42 ) ;
* V_37 += V_42 ;
F_12 ( * V_37 , ( T_5 ) ( * V_13 - V_26 ) ) ;
* V_37 += 2 ;
V_42 = ( int ) ( V_39 - V_28 ) ;
if ( ( V_40 )
&& ( * V_37 + ( V_42 >> 8 )
+ ( 1 + V_44 ) > V_41 ) ) {
return 1 ;
}
if ( V_42 >= ( int ) V_48 ) {
* V_43 += V_48 ;
V_42 -= V_48 ;
for (; V_42 > 509 ; V_42 -= 510 ) {
* ( * V_37 ) ++ = 255 ;
* ( * V_37 ) ++ = 255 ;
}
if ( V_42 > 254 ) {
V_42 -= 255 ;
* ( * V_37 ) ++ = 255 ;
}
* ( * V_37 ) ++ = ( T_3 ) V_42 ;
} else
* V_43 += ( T_3 ) ( V_42 ) ;
* V_13 += V_39 ;
* V_38 = * V_13 ;
return 0 ;
}
static int F_13 (
T_2 * const V_49 ,
const char * const V_50 ,
char * const V_51 ,
int const V_52 ,
int const V_53 ,
int V_54 ,
T_7 V_55
)
{
const T_3 * V_13 = ( const T_3 * ) V_50 ;
const T_3 * V_38 = V_13 ;
const T_3 * const V_56 = V_13 + V_52 ;
const T_3 * const V_57 = V_56 - V_58 ;
const T_3 * const V_59 = ( V_56 - V_44 ) ;
T_3 * V_37 = ( T_3 * ) V_51 ;
T_3 * const V_41 = V_37 + V_53 ;
unsigned int V_21 ;
int V_25 , V_60 , V_61 , V_62 ;
const T_3 * V_63 = NULL ;
const T_3 * V_64 = NULL ;
const T_3 * V_65 = NULL ;
const T_3 * V_66 = NULL ;
const T_3 * V_67 = NULL ;
const T_3 * V_68 ;
const T_3 * V_69 ;
if ( V_54 > V_70 )
V_54 = V_70 ;
if ( V_54 < 1 )
V_54 = V_71 ;
V_21 = 1 << ( V_54 - 1 ) ;
V_49 -> V_9 += V_52 ;
V_13 ++ ;
while ( V_13 < V_57 ) {
V_25 = F_7 ( V_49 , V_13 ,
V_59 , ( & V_63 ) , V_21 ) ;
if ( ! V_25 ) {
V_13 ++ ;
continue;
}
V_68 = V_13 ;
V_69 = V_63 ;
V_62 = V_25 ;
V_72:
if ( V_13 + V_25 < V_57 )
V_60 = F_9 ( V_49 ,
V_13 + V_25 - 2 , V_13 + 0 ,
V_59 , V_25 , & V_65 ,
& V_64 , V_21 ) ;
else
V_60 = V_25 ;
if ( V_60 == V_25 ) {
if ( F_10 ( & V_13 , & V_37 ,
& V_38 , V_25 , V_63 , V_55 , V_41 ) )
return 0 ;
continue;
}
if ( V_68 < V_13 ) {
if ( V_64 < V_13 + V_62 ) {
V_13 = V_68 ;
V_63 = V_69 ;
V_25 = V_62 ;
}
}
if ( ( V_64 - V_13 ) < 3 ) {
V_25 = V_60 ;
V_13 = V_64 ;
V_63 = V_65 ;
goto V_72;
}
V_73:
if ( ( V_64 - V_13 ) < V_74 ) {
int V_75 ;
int V_76 = V_25 ;
if ( V_76 > V_74 )
V_76 = V_74 ;
if ( V_13 + V_76 > V_64 + V_60 - V_28 )
V_76 = ( int ) ( V_64 - V_13 ) + V_60 - V_28 ;
V_75 = V_76 - ( int ) ( V_64 - V_13 ) ;
if ( V_75 > 0 ) {
V_64 += V_75 ;
V_65 += V_75 ;
V_60 -= V_75 ;
}
}
if ( V_64 + V_60 < V_57 )
V_61 = F_9 ( V_49 ,
V_64 + V_60 - 3 , V_64 ,
V_59 , V_60 , & V_67 , & V_66 ,
V_21 ) ;
else
V_61 = V_60 ;
if ( V_61 == V_60 ) {
if ( V_64 < V_13 + V_25 )
V_25 = ( int ) ( V_64 - V_13 ) ;
if ( F_10 ( & V_13 , & V_37 , & V_38 ,
V_25 , V_63 , V_55 , V_41 ) )
return 0 ;
V_13 = V_64 ;
if ( F_10 ( & V_13 , & V_37 , & V_38 ,
V_60 , V_65 , V_55 , V_41 ) )
return 0 ;
continue;
}
if ( V_66 < V_13 + V_25 + 3 ) {
if ( V_66 >= ( V_13 + V_25 ) ) {
if ( V_64 < V_13 + V_25 ) {
int V_75 = ( int ) ( V_13 + V_25 - V_64 ) ;
V_64 += V_75 ;
V_65 += V_75 ;
V_60 -= V_75 ;
if ( V_60 < V_28 ) {
V_64 = V_66 ;
V_65 = V_67 ;
V_60 = V_61 ;
}
}
if ( F_10 ( & V_13 , & V_37 , & V_38 ,
V_25 , V_63 , V_55 , V_41 ) )
return 0 ;
V_13 = V_66 ;
V_63 = V_67 ;
V_25 = V_61 ;
V_68 = V_64 ;
V_69 = V_65 ;
V_62 = V_60 ;
goto V_72;
}
V_64 = V_66 ;
V_65 = V_67 ;
V_60 = V_61 ;
goto V_73;
}
if ( V_64 < V_13 + V_25 ) {
if ( ( V_64 - V_13 ) < ( int ) V_48 ) {
int V_75 ;
if ( V_25 > V_74 )
V_25 = V_74 ;
if ( V_13 + V_25 > V_64 + V_60 - V_28 )
V_25 = ( int ) ( V_64 - V_13 ) + V_60 - V_28 ;
V_75 = V_25 - ( int ) ( V_64 - V_13 ) ;
if ( V_75 > 0 ) {
V_64 += V_75 ;
V_65 += V_75 ;
V_60 -= V_75 ;
}
} else
V_25 = ( int ) ( V_64 - V_13 ) ;
}
if ( F_10 ( & V_13 , & V_37 , & V_38 , V_25 ,
V_63 , V_55 , V_41 ) )
return 0 ;
V_13 = V_64 ;
V_63 = V_65 ;
V_25 = V_60 ;
V_64 = V_66 ;
V_65 = V_67 ;
V_60 = V_61 ;
goto V_73;
}
{
int V_77 = ( int ) ( V_56 - V_38 ) ;
if ( ( V_55 )
&& ( ( ( char * ) V_37 - V_51 ) + V_77 + 1
+ ( ( V_77 + 255 - V_45 ) / 255 )
> ( T_1 ) V_53 ) ) {
return 0 ;
}
if ( V_77 >= ( int ) V_45 ) {
* V_37 ++ = ( V_45 << V_47 ) ;
V_77 -= V_45 ;
for (; V_77 > 254 ; V_77 -= 255 )
* V_37 ++ = 255 ;
* V_37 ++ = ( T_3 ) V_77 ;
} else
* V_37 ++ = ( T_3 ) ( V_77 << V_47 ) ;
memcpy ( V_37 , V_38 , V_56 - V_38 ) ;
V_37 += V_56 - V_38 ;
}
return ( int ) ( ( ( char * ) V_37 ) - V_51 ) ;
}
static int F_14 (
void * V_78 ,
const char * V_79 ,
char * V_80 ,
int V_81 ,
int V_82 ,
int V_54 )
{
T_2 * V_49 = & ( ( V_83 * ) V_78 ) -> V_84 ;
if ( ( ( T_6 ) ( V_78 ) & ( sizeof( void * ) - 1 ) ) != 0 ) {
return 0 ;
}
F_4 ( V_49 , ( const T_3 * ) V_79 ) ;
if ( V_82 < F_15 ( V_81 ) )
return F_13 ( V_49 , V_79 , V_80 ,
V_81 , V_82 , V_54 , V_85 ) ;
else
return F_13 ( V_49 , V_79 , V_80 ,
V_81 , V_82 , V_54 , V_86 ) ;
}
int F_16 ( const char * V_79 , char * V_80 , int V_81 ,
int V_82 , int V_54 , void * V_87 )
{
return F_14 ( V_87 , V_79 , V_80 ,
V_81 , V_82 , V_54 ) ;
}
void F_17 ( V_83 * V_88 , int V_54 )
{
V_88 -> V_84 . V_8 = NULL ;
V_88 -> V_84 . V_54 = ( unsigned int ) V_54 ;
}
int F_18 ( V_83 * V_88 ,
const char * V_89 ,
int V_90 )
{
T_2 * V_91 = & V_88 -> V_84 ;
if ( V_90 > 64 * V_7 ) {
V_89 += V_90 - 64 * V_7 ;
V_90 = 64 * V_7 ;
}
F_4 ( V_91 , ( const T_3 * ) V_89 ) ;
if ( V_90 >= 4 )
F_5 ( V_91 , ( const T_3 * ) V_89 + ( V_90 - 3 ) ) ;
V_91 -> V_9 = ( const T_3 * ) V_89 + V_90 ;
return V_90 ;
}
static void F_19 (
T_2 * V_91 ,
const T_3 * V_92 )
{
if ( V_91 -> V_9 >= V_91 -> V_8 + 4 ) {
F_5 ( V_91 , V_91 -> V_9 - 3 ) ;
}
V_91 -> V_12 = V_91 -> V_11 ;
V_91 -> V_11 = ( T_1 ) ( V_91 -> V_9 - V_91 -> V_8 ) ;
V_91 -> V_10 = V_91 -> V_8 ;
V_91 -> V_8 = V_92 - V_91 -> V_11 ;
V_91 -> V_9 = V_92 ;
V_91 -> V_6 = V_91 -> V_11 ;
}
static int F_20 (
V_83 * V_88 ,
const char * V_50 ,
char * V_51 ,
int V_52 ,
int V_53 ,
T_7 V_55 )
{
T_2 * V_91 = & V_88 -> V_84 ;
if ( V_91 -> V_8 == NULL )
F_4 ( V_91 , ( const T_3 * ) V_50 ) ;
if ( ( T_6 ) ( V_91 -> V_9 - V_91 -> V_8 ) > 2 * V_93 ) {
T_6 V_90 = ( T_6 ) ( V_91 -> V_9 - V_91 -> V_8 )
- V_91 -> V_11 ;
if ( V_90 > 64 * V_7 )
V_90 = 64 * V_7 ;
F_18 ( V_88 ,
( const char * ) ( V_91 -> V_9 ) - V_90 , ( int ) V_90 ) ;
}
if ( ( const T_3 * ) V_50 != V_91 -> V_9 )
F_19 ( V_91 , ( const T_3 * ) V_50 ) ;
{
const T_3 * V_94 = ( const T_3 * ) V_50 + V_52 ;
const T_3 * const V_95 = V_91 -> V_10 + V_91 -> V_12 ;
const T_3 * const V_96 = V_91 -> V_10 + V_91 -> V_11 ;
if ( ( V_94 > V_95 )
&& ( ( const T_3 * ) V_50 < V_96 ) ) {
if ( V_94 > V_96 )
V_94 = V_96 ;
V_91 -> V_12 = ( T_1 ) ( V_94 - V_91 -> V_10 ) ;
if ( V_91 -> V_11 - V_91 -> V_12 < 4 )
V_91 -> V_12 = V_91 -> V_11 ;
}
}
return F_13 ( V_91 , V_50 , V_51 ,
V_52 , V_53 , V_91 -> V_54 , V_55 ) ;
}
int F_21 (
V_83 * V_88 ,
const char * V_50 ,
char * V_51 ,
int V_52 ,
int V_53 )
{
if ( V_53 < F_15 ( V_52 ) )
return F_20 ( V_88 ,
V_50 , V_51 , V_52 , V_53 , V_85 ) ;
else
return F_20 ( V_88 ,
V_50 , V_51 , V_52 , V_53 , V_86 ) ;
}
int F_22 (
V_83 * V_88 ,
char * V_97 ,
int V_90 )
{
T_2 * const V_98 = & V_88 -> V_84 ;
int const V_99 = ( int ) ( V_98 -> V_9
- ( V_98 -> V_8 + V_98 -> V_11 ) ) ;
if ( V_90 > 64 * V_7 )
V_90 = 64 * V_7 ;
if ( V_90 < 4 )
V_90 = 0 ;
if ( V_90 > V_99 )
V_90 = V_99 ;
memmove ( V_97 , V_98 -> V_9 - V_90 , V_90 ) ;
{
T_1 const V_100 = ( T_1 ) ( V_98 -> V_9 - V_98 -> V_8 ) ;
V_98 -> V_9 = ( const T_3 * ) V_97 + V_90 ;
V_98 -> V_8 = V_98 -> V_9 - V_100 ;
V_98 -> V_11 = V_100 - V_90 ;
V_98 -> V_12 = V_100 - V_90 ;
if ( V_98 -> V_6 < V_98 -> V_11 )
V_98 -> V_6 = V_98 -> V_11 ;
}
return V_90 ;
}
