static inline int F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
memset ( ( void * ) V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
memset ( V_2 -> V_5 , 0xFF , sizeof( V_2 -> V_5 ) ) ;
#if V_6
V_2 -> V_7 = V_3 + 1 ;
#else
V_2 -> V_7 = V_3 ;
#endif
V_2 -> V_3 = V_3 ;
return 1 ;
}
static inline void F_2 ( struct V_1 * V_2 , const T_1 * V_8 )
{
T_2 * V_5 = V_2 -> V_5 ;
T_3 * V_4 = V_2 -> V_4 ;
#if V_6
const T_4 * const V_3 = V_2 -> V_3 ;
#else
const int V_3 = 0 ;
#endif
while ( V_2 -> V_7 < V_8 ) {
const T_1 * V_9 = V_2 -> V_7 ;
T_5 V_10 = V_9 - ( V_4 [ F_3 ( V_9 ) ] + V_3 ) ;
if ( V_10 > V_11 )
V_10 = V_11 ;
V_5 [ ( T_5 ) ( V_9 ) & V_12 ] = ( T_2 ) V_10 ;
V_4 [ F_3 ( V_9 ) ] = ( V_9 ) - V_3 ;
V_2 -> V_7 ++ ;
}
}
static inline T_5 F_4 ( const T_1 * V_13 , const T_1 * V_14 ,
const T_1 * const V_15 )
{
const T_1 * V_16 = V_13 ;
while ( V_16 < V_15 - ( V_17 - 1 ) ) {
#if V_6
T_6 V_18 = F_5 ( V_14 ) ^ F_5 ( V_16 ) ;
#else
T_7 V_18 = F_6 ( V_14 ) ^ F_6 ( V_16 ) ;
#endif
if ( ! V_18 ) {
V_16 += V_17 ;
V_14 += V_17 ;
continue;
}
V_16 += F_7 ( V_18 ) ;
return V_16 - V_13 ;
}
#if V_6
if ( ( V_16 < ( V_15 - 3 ) ) && ( F_6 ( V_14 ) == F_6 ( V_16 ) ) ) {
V_16 += 4 ;
V_14 += 4 ;
}
#endif
if ( ( V_16 < ( V_15 - 1 ) ) && ( F_8 ( V_14 ) == F_8 ( V_16 ) ) ) {
V_16 += 2 ;
V_14 += 2 ;
}
if ( ( V_16 < V_15 ) && ( * V_14 == * V_16 ) )
V_16 ++ ;
return V_16 - V_13 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
const T_1 * V_8 , const T_1 * const V_15 , const T_1 * * V_19 )
{
T_2 * const V_5 = V_2 -> V_5 ;
T_3 * const V_4 = V_2 -> V_4 ;
const T_1 * V_20 ;
#if V_6
const T_4 * const V_3 = V_2 -> V_3 ;
#else
const int V_3 = 0 ;
#endif
int V_21 = V_22 ;
T_5 V_23 = 0 , V_24 = 0 ;
T_2 V_10 ;
F_2 ( V_2 , V_8 ) ;
V_20 = V_4 [ F_3 ( V_8 ) ] + V_3 ;
if ( V_20 >= V_8 - 4 ) {
if ( F_6 ( V_20 ) == F_6 ( V_8 ) ) {
V_10 = ( T_2 ) ( V_8 - V_20 ) ;
V_23 = V_24 = F_4 ( V_8 + V_25 ,
V_20 + V_25 , V_15 ) + V_25 ;
* V_19 = V_20 ;
}
V_20 -= ( T_5 ) V_5 [ ( T_5 ) ( V_20 ) & V_12 ] ;
}
while ( ( V_20 >= V_8 - V_11 ) && V_21 ) {
V_21 -- ;
if ( * ( V_20 + V_24 ) == * ( V_8 + V_24 ) ) {
if ( F_6 ( V_20 ) == F_6 ( V_8 ) ) {
T_5 V_26 =
F_4 ( V_8 + V_25 ,
V_20 + V_25 , V_15 ) + V_25 ;
if ( V_26 > V_24 ) {
V_24 = V_26 ;
* V_19 = V_20 ;
}
}
}
V_20 -= ( T_5 ) V_5 [ ( T_5 ) ( V_20 ) & V_12 ] ;
}
if ( V_23 ) {
const T_4 * V_27 = V_8 ;
const T_4 * V_28 ;
V_28 = V_8 + V_23 - ( V_25 - 1 ) ;
while ( V_27 < V_28 - V_10 ) {
V_5 [ ( T_5 ) ( V_27 ) & V_12 ] = V_10 ;
V_27 ++ ;
}
do {
V_5 [ ( T_5 ) ( V_27 ) & V_12 ] = V_10 ;
V_4 [ F_3 ( V_27 ) ] = ( V_27 ) - V_3 ;
V_27 ++ ;
} while ( V_27 < V_28 );
V_2 -> V_7 = V_28 ;
}
return ( int ) V_24 ;
}
static inline int F_10 ( struct V_1 * V_2 ,
const T_1 * V_8 , const T_1 * V_29 , const T_1 * V_15 , int V_30 ,
const T_1 * * V_19 , const T_1 * * V_31 )
{
T_2 * const V_5 = V_2 -> V_5 ;
T_3 * const V_4 = V_2 -> V_4 ;
#if V_6
const T_4 * const V_3 = V_2 -> V_3 ;
#else
const int V_3 = 0 ;
#endif
const T_1 * V_20 ;
int V_21 = V_22 ;
int V_10 = ( int ) ( V_8 - V_29 ) ;
F_2 ( V_2 , V_8 ) ;
V_20 = V_4 [ F_3 ( V_8 ) ] + V_3 ;
while ( ( V_20 >= V_8 - V_11 ) && ( V_20 >= V_2 -> V_3 )
&& ( V_21 ) ) {
V_21 -- ;
if ( * ( V_29 + V_30 ) == * ( V_20 - V_10 + V_30 ) ) {
if ( F_6 ( V_20 ) == F_6 ( V_8 ) ) {
const T_1 * V_32 = V_20 + V_25 ;
const T_1 * V_33 = V_8 + V_25 ;
const T_1 * V_34 = V_8 ;
while ( V_33 < V_15 - ( V_17 - 1 ) ) {
#if V_6
T_6 V_18 = F_5 ( V_32 ) ^ F_5 ( V_33 ) ;
#else
T_7 V_18 = F_6 ( V_32 ) ^ F_6 ( V_33 ) ;
#endif
if ( ! V_18 ) {
V_33 += V_17 ;
V_32 += V_17 ;
continue;
}
V_33 += F_7 ( V_18 ) ;
goto V_35;
}
#if V_6
if ( ( V_33 < ( V_15 - 3 ) )
&& ( F_6 ( V_32 ) == F_6 ( V_33 ) ) ) {
V_33 += 4 ;
V_32 += 4 ;
}
V_33 += 2 ;
#endif
if ( ( V_33 < ( V_15 - 1 ) )
&& ( F_8 ( V_32 ) == F_8 ( V_33 ) ) ) {
V_32 += 2 ;
}
if ( ( V_33 < V_15 ) && ( * V_32 == * V_33 ) )
V_33 ++ ;
V_35:
V_32 = V_20 ;
while ( ( V_34 > V_29 )
&& ( V_32 > V_2 -> V_3 )
&& ( V_34 [ - 1 ] == V_32 [ - 1 ] ) ) {
V_34 -- ;
V_32 -- ;
}
if ( ( V_33 - V_34 ) > V_30 ) {
V_30 = ( int ) ( V_33 - V_34 ) ;
* V_19 = V_32 ;
* V_31 = V_34 ;
}
}
}
V_20 -= ( T_5 ) V_5 [ ( T_5 ) ( V_20 ) & V_12 ] ;
}
return V_30 ;
}
static inline int F_11 ( const T_1 * * V_8 , T_1 * * V_36 , const T_1 * * V_37 ,
int V_24 , const T_1 * V_20 )
{
int V_38 , V_39 ;
T_1 * V_40 ;
V_38 = ( int ) ( * V_8 - * V_37 ) ;
V_40 = ( * V_36 ) ++ ;
if ( V_38 >= ( int ) V_41 ) {
* V_40 = ( V_41 << V_42 ) ;
V_39 = V_38 - V_41 ;
for (; V_39 > 254 ; V_39 -= 255 )
* ( * V_36 ) ++ = 255 ;
* ( * V_36 ) ++ = ( T_1 ) V_39 ;
} else
* V_40 = ( V_38 << V_42 ) ;
F_12 ( * V_37 , * V_36 , V_38 ) ;
F_13 ( * V_36 , ( T_2 ) ( * V_8 - V_20 ) ) ;
V_39 = ( int ) ( V_24 - V_25 ) ;
if ( V_39 >= ( int ) V_43 ) {
* V_40 += V_43 ;
V_39 -= V_43 ;
for (; V_39 > 509 ; V_39 -= 510 ) {
* ( * V_36 ) ++ = 255 ;
* ( * V_36 ) ++ = 255 ;
}
if ( V_39 > 254 ) {
V_39 -= 255 ;
* ( * V_36 ) ++ = 255 ;
}
* ( * V_36 ) ++ = ( T_1 ) V_39 ;
} else
* V_40 += V_39 ;
* V_8 += V_24 ;
* V_37 = * V_8 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_44 ,
const char * V_45 ,
char * V_46 ,
int V_47 )
{
const T_1 * V_8 = ( const T_1 * ) V_45 ;
const T_1 * V_37 = V_8 ;
const T_1 * const V_48 = V_8 + V_47 ;
const T_1 * const V_49 = V_48 - V_50 ;
const T_1 * const V_15 = ( V_48 - V_51 ) ;
T_1 * V_36 = ( T_1 * ) V_46 ;
int V_24 , V_52 , V_53 , V_54 ;
const T_1 * V_20 = NULL ;
const T_1 * V_55 = NULL ;
const T_1 * V_56 = NULL ;
const T_1 * V_57 = NULL ;
const T_1 * V_58 = NULL ;
const T_1 * V_59 ;
const T_1 * V_60 ;
int V_61 ;
V_8 ++ ;
while ( V_8 < V_49 ) {
V_24 = F_9 ( V_44 , V_8 , V_15 , ( & V_20 ) ) ;
if ( ! V_24 ) {
V_8 ++ ;
continue;
}
V_59 = V_8 ;
V_60 = V_20 ;
V_54 = V_24 ;
V_62:
if ( V_8 + V_24 < V_49 )
V_52 = F_10 ( V_44 , V_8 + V_24 - 2 ,
V_8 + 1 , V_15 , V_24 , & V_56 , & V_55 ) ;
else
V_52 = V_24 ;
if ( V_52 == V_24 ) {
F_11 ( & V_8 , & V_36 , & V_37 , V_24 , V_20 ) ;
continue;
}
if ( V_59 < V_8 ) {
if ( V_55 < V_8 + V_54 ) {
V_8 = V_59 ;
V_20 = V_60 ;
V_24 = V_54 ;
}
}
if ( ( V_55 - V_8 ) < 3 ) {
V_24 = V_52 ;
V_8 = V_55 ;
V_20 = V_56 ;
goto V_62;
}
V_63:
if ( ( V_55 - V_8 ) < V_64 ) {
int V_65 ;
int V_66 = V_24 ;
if ( V_66 > V_64 )
V_66 = V_64 ;
if ( V_8 + V_66 > V_55 + V_52 - V_25 )
V_66 = ( int ) ( V_55 - V_8 ) + V_52 - V_25 ;
V_65 = V_66 - ( int ) ( V_55 - V_8 ) ;
if ( V_65 > 0 ) {
V_55 += V_65 ;
V_56 += V_65 ;
V_52 -= V_65 ;
}
}
if ( V_55 + V_52 < V_49 )
V_53 = F_10 ( V_44 ,
V_55 + V_52 - 3 , V_55 , V_15 ,
V_52 , & V_58 , & V_57 ) ;
else
V_53 = V_52 ;
if ( V_53 == V_52 ) {
if ( V_55 < V_8 + V_24 )
V_24 = ( int ) ( V_55 - V_8 ) ;
F_11 ( & V_8 , & V_36 , & V_37 , V_24 , V_20 ) ;
V_8 = V_55 ;
F_11 ( & V_8 , & V_36 , & V_37 , V_52 , V_56 ) ;
continue;
}
if ( V_57 < V_8 + V_24 + 3 ) {
if ( V_57 >= ( V_8 + V_24 ) ) {
if ( V_55 < V_8 + V_24 ) {
int V_65 =
( int ) ( V_8 + V_24 - V_55 ) ;
V_55 += V_65 ;
V_56 += V_65 ;
V_52 -= V_65 ;
if ( V_52 < V_25 ) {
V_55 = V_57 ;
V_56 = V_58 ;
V_52 = V_53 ;
}
}
F_11 ( & V_8 , & V_36 , & V_37 , V_24 , V_20 ) ;
V_8 = V_57 ;
V_20 = V_58 ;
V_24 = V_53 ;
V_59 = V_55 ;
V_60 = V_56 ;
V_54 = V_52 ;
goto V_62;
}
V_55 = V_57 ;
V_56 = V_58 ;
V_52 = V_53 ;
goto V_63;
}
if ( V_55 < V_8 + V_24 ) {
if ( ( V_55 - V_8 ) < ( int ) V_43 ) {
int V_65 ;
if ( V_24 > V_64 )
V_24 = V_64 ;
if ( V_8 + V_24 > V_55 + V_52 - V_25 )
V_24 = ( int ) ( V_55 - V_8 ) + V_52
- V_25 ;
V_65 = V_24 - ( int ) ( V_55 - V_8 ) ;
if ( V_65 > 0 ) {
V_55 += V_65 ;
V_56 += V_65 ;
V_52 -= V_65 ;
}
} else
V_24 = ( int ) ( V_55 - V_8 ) ;
}
F_11 ( & V_8 , & V_36 , & V_37 , V_24 , V_20 ) ;
V_8 = V_55 ;
V_20 = V_56 ;
V_24 = V_52 ;
V_55 = V_57 ;
V_56 = V_58 ;
V_52 = V_53 ;
goto V_63;
}
V_61 = ( int ) ( V_48 - V_37 ) ;
if ( V_61 >= ( int ) V_41 ) {
* V_36 ++ = ( V_41 << V_42 ) ;
V_61 -= V_41 ;
for (; V_61 > 254 ; V_61 -= 255 )
* V_36 ++ = 255 ;
* V_36 ++ = ( T_1 ) V_61 ;
} else
* V_36 ++ = ( V_61 << V_42 ) ;
memcpy ( V_36 , V_37 , V_48 - V_37 ) ;
V_36 += V_48 - V_37 ;
return ( int ) ( ( ( char * ) V_36 ) - V_46 ) ;
}
int F_15 ( const unsigned char * V_67 , T_5 V_68 ,
unsigned char * V_69 , T_5 * V_70 , void * V_71 )
{
int V_72 = - 1 ;
int V_73 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_71 ;
F_1 ( V_2 , ( const T_1 * ) V_67 ) ;
V_73 = F_14 ( (struct V_1 * ) V_2 , ( const T_1 * ) V_67 ,
( char * ) V_69 , ( int ) V_68 ) ;
if ( V_73 < 0 )
goto exit;
* V_70 = V_73 ;
return 0 ;
exit:
return V_72 ;
}
