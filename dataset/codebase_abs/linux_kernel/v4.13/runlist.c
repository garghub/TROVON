static inline void F_1 ( T_1 * V_1 , int V_2 , int V_3 ,
int V_4 )
{
if ( F_2 ( ( V_2 != V_3 ) && ( V_4 > 0 ) ) )
memmove ( V_1 + V_2 , V_1 + V_3 , V_4 * sizeof( * V_1 ) ) ;
}
static inline void F_3 ( T_1 * V_5 , int V_2 ,
T_1 * V_6 , int V_3 , int V_4 )
{
if ( F_2 ( V_4 > 0 ) )
memcpy ( V_5 + V_2 , V_6 + V_3 , V_4 * sizeof( * V_5 ) ) ;
}
static inline T_1 * F_4 ( T_1 * V_7 ,
int V_8 , int V_9 )
{
T_1 * V_10 ;
V_8 = F_5 ( V_8 * sizeof( * V_7 ) ) ;
V_9 = F_5 ( V_9 * sizeof( * V_7 ) ) ;
if ( V_8 == V_9 )
return V_7 ;
V_10 = F_6 ( V_9 ) ;
if ( F_7 ( ! V_10 ) )
return F_8 ( - V_11 ) ;
if ( F_2 ( V_7 != NULL ) ) {
if ( F_7 ( V_8 > V_9 ) )
V_8 = V_9 ;
memcpy ( V_10 , V_7 , V_8 ) ;
F_9 ( V_7 ) ;
}
return V_10 ;
}
static inline T_1 * F_10 ( T_1 * V_7 ,
int V_8 , int V_9 )
{
T_1 * V_10 ;
V_8 = F_5 ( V_8 * sizeof( * V_7 ) ) ;
V_9 = F_5 ( V_9 * sizeof( * V_7 ) ) ;
if ( V_8 == V_9 )
return V_7 ;
V_10 = F_11 ( V_9 ) ;
F_12 ( ! V_10 ) ;
if ( F_2 ( V_7 != NULL ) ) {
if ( F_7 ( V_8 > V_9 ) )
V_8 = V_9 ;
memcpy ( V_10 , V_7 , V_8 ) ;
F_9 ( V_7 ) ;
}
return V_10 ;
}
static inline bool F_13 ( T_1 * V_2 ,
T_1 * V_3 )
{
F_12 ( ! V_2 ) ;
F_12 ( ! V_3 ) ;
if ( ( V_2 -> V_12 == V_13 ) && ( V_3 -> V_12 == V_13 ) )
return true ;
if ( ( V_2 -> V_14 + V_2 -> V_15 ) != V_3 -> V_14 )
return false ;
if ( ( V_2 -> V_12 >= 0 ) && ( V_3 -> V_12 >= 0 ) &&
( ( V_2 -> V_12 + V_2 -> V_15 ) == V_3 -> V_12 ) )
return true ;
if ( ( V_2 -> V_12 == V_16 ) && ( V_3 -> V_12 == V_16 ) )
return true ;
return false ;
}
static inline void F_14 ( T_1 * V_2 , T_1 * V_3 )
{
V_2 -> V_15 += V_3 -> V_15 ;
}
static inline T_1 * F_15 ( T_1 * V_2 ,
int V_17 , T_1 * V_3 , int V_18 , int V_19 )
{
bool V_20 = false ;
int V_21 ;
F_12 ( ! V_2 ) ;
F_12 ( ! V_3 ) ;
if ( ( V_19 + 1 ) < V_17 )
V_20 = F_13 ( V_3 + V_18 - 1 , V_2 + V_19 + 1 ) ;
V_2 = F_4 ( V_2 , V_17 , V_17 + V_18 - V_20 ) ;
if ( F_16 ( V_2 ) )
return V_2 ;
if ( V_20 )
F_14 ( V_3 + V_18 - 1 , V_2 + V_19 + 1 ) ;
V_21 = V_19 + V_18 + 1 ;
F_1 ( V_2 , V_21 , V_19 + 1 + V_20 , V_17 - ( V_19 + 1 + V_20 ) ) ;
F_3 ( V_2 , V_19 + 1 , V_3 , 0 , V_18 ) ;
V_2 [ V_19 ] . V_15 = V_2 [ V_19 + 1 ] . V_14 - V_2 [ V_19 ] . V_14 ;
if ( V_2 [ V_21 ] . V_12 == V_22 )
V_2 [ V_21 ] . V_14 = V_2 [ V_21 - 1 ] . V_14 + V_2 [ V_21 - 1 ] . V_15 ;
return V_2 ;
}
static inline T_1 * F_17 ( T_1 * V_2 ,
int V_17 , T_1 * V_3 , int V_18 , int V_19 )
{
bool V_23 = false ;
bool V_24 = false ;
int V_21 ;
F_12 ( ! V_2 ) ;
F_12 ( ! V_3 ) ;
if ( V_19 == 0 )
V_24 = ( V_3 [ 0 ] . V_14 > 0 ) ;
else {
T_2 V_25 ;
V_23 = F_13 ( V_2 + V_19 - 1 , V_3 ) ;
V_25 = V_2 [ V_19 - 1 ] . V_15 ;
if ( V_23 )
V_25 += V_3 -> V_15 ;
V_24 = ( V_3 [ 0 ] . V_14 > V_2 [ V_19 - 1 ] . V_14 + V_25 ) ;
}
V_2 = F_4 ( V_2 , V_17 , V_17 + V_18 - V_23 + V_24 ) ;
if ( F_16 ( V_2 ) )
return V_2 ;
if ( V_23 )
F_14 ( V_2 + V_19 - 1 , V_3 ) ;
V_21 = V_19 + V_18 - V_23 + V_24 ;
F_1 ( V_2 , V_21 , V_19 , V_17 - V_19 ) ;
F_3 ( V_2 , V_19 + V_24 , V_3 , V_23 , V_18 - V_23 ) ;
V_2 [ V_21 ] . V_14 = V_2 [ V_21 - 1 ] . V_14 + V_2 [ V_21 - 1 ] . V_15 ;
if ( V_2 [ V_21 ] . V_12 == V_16 || V_2 [ V_21 ] . V_12 == V_13 )
V_2 [ V_21 ] . V_15 = V_2 [ V_21 + 1 ] . V_14 - V_2 [ V_21 ] . V_14 ;
if ( V_24 ) {
if ( V_19 > 0 ) {
V_2 [ V_19 ] . V_14 = V_2 [ V_19 - 1 ] . V_14 + V_2 [ V_19 - 1 ] . V_15 ;
V_2 [ V_19 ] . V_15 = V_2 [ V_19 + 1 ] . V_14 - V_2 [ V_19 ] . V_14 ;
} else {
V_2 [ V_19 ] . V_14 = 0 ;
V_2 [ V_19 ] . V_15 = V_2 [ V_19 + 1 ] . V_14 ;
}
V_2 [ V_19 ] . V_12 = V_13 ;
}
return V_2 ;
}
static inline T_1 * F_18 ( T_1 * V_2 ,
int V_17 , T_1 * V_3 , int V_18 , int V_19 )
{
signed V_26 ;
bool V_23 = false ;
bool V_20 = false ;
int V_27 ;
int V_21 ;
F_12 ( ! V_2 ) ;
F_12 ( ! V_3 ) ;
if ( ( V_19 + 1 ) < V_17 )
V_20 = F_13 ( V_3 + V_18 - 1 , V_2 + V_19 + 1 ) ;
if ( V_19 > 0 )
V_23 = F_13 ( V_2 + V_19 - 1 , V_3 ) ;
V_26 = V_18 - 1 - V_23 - V_20 ;
if ( V_26 > 0 ) {
V_2 = F_4 ( V_2 , V_17 , V_17 + V_26 ) ;
if ( F_16 ( V_2 ) )
return V_2 ;
}
if ( V_20 )
F_14 ( V_3 + V_18 - 1 , V_2 + V_19 + 1 ) ;
if ( V_23 )
F_14 ( V_2 + V_19 - 1 , V_3 ) ;
V_27 = V_19 + V_20 + 1 ;
V_21 = V_19 + V_18 - V_23 ;
F_1 ( V_2 , V_21 , V_27 , V_17 - V_27 ) ;
F_3 ( V_2 , V_19 , V_3 , V_23 , V_18 - V_23 ) ;
if ( V_17 - V_27 > 0 && V_2 [ V_21 ] . V_12 == V_22 )
V_2 [ V_21 ] . V_14 = V_2 [ V_21 - 1 ] . V_14 + V_2 [ V_21 - 1 ] . V_15 ;
return V_2 ;
}
static inline T_1 * F_19 ( T_1 * V_2 , int V_17 ,
T_1 * V_3 , int V_18 , int V_19 )
{
F_12 ( ! V_2 ) ;
F_12 ( ! V_3 ) ;
V_2 = F_4 ( V_2 , V_17 , V_17 + V_18 + 1 ) ;
if ( F_16 ( V_2 ) )
return V_2 ;
F_1 ( V_2 , V_19 + 1 + V_18 , V_19 , V_17 - V_19 ) ;
F_3 ( V_2 , V_19 + 1 , V_3 , 0 , V_18 ) ;
V_2 [ V_19 ] . V_15 = V_2 [ V_19 + 1 ] . V_14 - V_2 [ V_19 ] . V_14 ;
V_2 [ V_19 + V_18 + 1 ] . V_14 = V_2 [ V_19 + V_18 ] . V_14 + V_2 [ V_19 + V_18 ] . V_15 ;
V_2 [ V_19 + V_18 + 1 ] . V_15 = V_2 [ V_19 + V_18 + 2 ] . V_14 - V_2 [ V_19 + V_18 + 1 ] . V_14 ;
return V_2 ;
}
T_1 * F_20 ( T_1 * V_28 ,
T_1 * V_29 )
{
int V_30 , V_31 ;
int V_32 ;
int V_33 ;
int V_34 , V_35 ;
int V_36 , V_37 ;
int V_21 = 0 ;
T_3 V_38 = 0 ;
#ifdef F_21
F_22 ( L_1 ) ;
F_23 ( V_28 ) ;
F_22 ( L_2 ) ;
F_23 ( V_29 ) ;
#endif
if ( F_7 ( ! V_29 ) )
return V_28 ;
if ( F_16 ( V_29 ) || F_16 ( V_28 ) )
return F_8 ( - V_39 ) ;
if ( F_7 ( ! V_28 ) ) {
V_28 = V_29 ;
if ( F_7 ( V_28 [ 0 ] . V_14 ) ) {
for ( V_34 = 0 ; F_2 ( V_28 [ V_34 ] . V_15 ) ; V_34 ++ )
;
V_34 ++ ;
V_28 = F_4 ( V_28 , V_34 , V_34 + 1 ) ;
if ( F_16 ( V_28 ) )
return V_28 ;
F_1 ( V_28 , 1 , 0 , V_34 ) ;
V_28 [ 0 ] . V_14 = 0 ;
V_28 [ 0 ] . V_12 = V_13 ;
V_28 [ 0 ] . V_15 = V_28 [ 1 ] . V_14 ;
}
goto V_40;
}
V_31 = V_30 = 0 ;
while ( V_29 [ V_31 ] . V_15 && V_29 [ V_31 ] . V_12 < V_16 )
V_31 ++ ;
F_12 ( ! V_29 [ V_31 ] . V_15 ) ;
V_32 = V_31 ;
for (; V_28 [ V_30 ] . V_15 ; V_30 ++ ) {
if ( V_28 [ V_30 ] . V_14 + V_28 [ V_30 ] . V_15 > V_29 [ V_32 ] . V_14 )
break;
}
V_33 = V_30 ;
if ( ( V_28 [ V_30 ] . V_14 == V_29 [ V_31 ] . V_14 ) && ( V_28 [ V_30 ] . V_12 >= 0 ) &&
( V_29 [ V_31 ] . V_12 >= 0 ) ) {
F_24 ( NULL , L_3 ) ;
return F_8 ( - V_41 ) ;
}
for ( V_35 = V_31 ; V_29 [ V_35 ] . V_15 ; V_35 ++ )
;
for ( V_34 = V_30 ; V_28 [ V_34 ] . V_15 ; V_34 ++ )
;
if ( V_29 [ V_35 ] . V_12 == V_22 )
V_38 = V_29 [ V_21 = V_35 ] . V_14 ;
for ( V_37 = V_35 ; V_37 >= 0 && V_29 [ V_37 ] . V_12 < V_16 ; V_37 -- )
;
for ( V_36 = V_34 ; V_36 >= 0 && V_28 [ V_36 ] . V_12 < V_16 ; V_36 -- )
;
{
bool V_42 ;
bool V_43 ;
int V_44 = V_34 + 1 ;
int V_45 = V_37 - V_32 + 1 ;
V_42 = ( ( V_28 [ V_33 ] . V_12 < V_13 ) ||
( V_28 [ V_33 ] . V_14 == V_29 [ V_32 ] . V_14 ) ) ;
V_43 = ( ( V_28 [ V_33 ] . V_12 >= V_13 ) &&
( ( V_28 [ V_33 ] . V_14 + V_28 [ V_33 ] . V_15 ) <=
( V_29 [ V_35 - 1 ] . V_14 + V_29 [ V_35 - 1 ] . V_15 ) ) ) ;
if ( V_43 && ! V_28 [ V_33 ] . V_15 )
V_45 ++ ;
if ( V_21 && ( V_28 [ V_33 ] . V_14 + V_28 [ V_33 ] . V_15 > V_29 [ V_35 - 1 ] . V_14 ) )
V_43 = false ;
#if 0
ntfs_debug("dfinal = %i, dend = %i", dfinal, dend);
ntfs_debug("sstart = %i, sfinal = %i, send = %i", sstart, sfinal, send);
ntfs_debug("start = %i, finish = %i", start, finish);
ntfs_debug("ds = %i, ss = %i, dins = %i", ds, ss, dins);
#endif
if ( V_42 ) {
if ( V_43 )
V_28 = F_18 ( V_28 , V_44 , V_29 + V_32 , V_45 , V_33 ) ;
else
V_28 = F_17 ( V_28 , V_44 , V_29 + V_32 , V_45 , V_33 ) ;
} else {
if ( V_43 )
V_28 = F_15 ( V_28 , V_44 , V_29 + V_32 , V_45 , V_33 ) ;
else
V_28 = F_19 ( V_28 , V_44 , V_29 + V_32 , V_45 , V_33 ) ;
}
if ( F_16 ( V_28 ) ) {
F_24 ( NULL , L_4 ) ;
return V_28 ;
}
F_9 ( V_29 ) ;
if ( V_21 ) {
F_22 ( L_5 ) ;
for ( V_44 = V_34 ; V_28 [ V_44 ] . V_15 ; V_44 ++ )
;
if ( V_28 [ V_44 ] . V_14 <= V_38 ) {
int V_46 = 0 ;
if ( V_28 [ V_44 ] . V_14 == V_38 ) {
F_22 ( L_6
L_7 ,
( unsigned long long )
V_28 [ V_44 ] . V_12 ) ;
V_28 [ V_44 ] . V_12 = V_22 ;
goto V_40;
}
if ( V_28 [ V_44 ] . V_12 == V_22 ) {
V_44 -- ;
V_46 = 1 ;
}
if ( V_28 [ V_44 ] . V_12 != V_13 ) {
if ( ! V_46 ) {
V_28 = F_10 ( V_28 , V_44 ,
V_44 + 2 ) ;
V_46 = 2 ;
}
V_44 ++ ;
if ( V_46 != 1 )
V_28 [ V_44 ] . V_14 = V_28 [ V_44 - 1 ] . V_14 +
V_28 [ V_44 - 1 ] . V_15 ;
V_28 [ V_44 ] . V_12 = V_13 ;
V_46 -- ;
}
V_28 [ V_44 ] . V_15 = V_38 - V_28 [ V_44 ] . V_14 ;
V_44 ++ ;
if ( ! V_46 )
V_28 = F_10 ( V_28 , V_44 , V_44 + 1 ) ;
V_28 [ V_44 ] . V_14 = V_38 ;
V_28 [ V_44 ] . V_12 = V_22 ;
V_28 [ V_44 ] . V_15 = ( T_2 ) 0 ;
}
}
}
V_40:
F_22 ( L_8 ) ;
F_23 ( V_28 ) ;
return V_28 ;
}
T_1 * F_25 ( const T_4 * V_47 ,
const T_5 * V_48 , T_1 * V_49 )
{
T_3 V_14 ;
T_6 V_12 ;
T_2 V_50 ;
T_1 * V_7 ;
T_7 * V_51 ;
T_7 * V_52 ;
int V_53 ;
T_8 V_54 ;
T_7 V_55 ;
#ifdef F_21
if ( ! V_48 || ! V_48 -> V_56 || F_26 (
V_48 -> V_57 . V_56 . V_58 ) < ( T_3 ) 0 ) {
F_24 ( V_47 -> V_59 , L_9 ) ;
return F_8 ( - V_39 ) ;
}
#endif
V_14 = F_26 ( V_48 -> V_57 . V_56 . V_58 ) ;
V_12 = 0 ;
V_51 = ( T_7 * ) V_48 + F_27 (
V_48 -> V_57 . V_56 . V_60 ) ;
V_52 = ( T_7 * ) V_48 + F_28 ( V_48 -> V_15 ) ;
if ( F_7 ( V_51 < ( T_7 * ) V_48 || V_51 > V_52 ) ) {
F_24 ( V_47 -> V_59 , L_10 ) ;
return F_8 ( - V_61 ) ;
}
if ( ! V_14 && ! * V_51 )
return V_49 ;
V_54 = 0 ;
V_7 = F_6 ( V_53 = V_62 ) ;
if ( F_7 ( ! V_7 ) )
return F_8 ( - V_11 ) ;
if ( V_14 ) {
V_7 -> V_14 = 0 ;
V_7 -> V_12 = V_13 ;
V_7 -> V_15 = V_14 ;
V_54 ++ ;
}
while ( V_51 < V_52 && * V_51 ) {
if ( ( ( V_54 + 3 ) * sizeof( * V_49 ) ) > V_53 ) {
T_1 * V_63 ;
V_63 = F_6 ( V_53 + ( int ) V_62 ) ;
if ( F_7 ( ! V_63 ) ) {
F_9 ( V_7 ) ;
return F_8 ( - V_11 ) ;
}
memcpy ( V_63 , V_7 , V_53 ) ;
F_9 ( V_7 ) ;
V_7 = V_63 ;
V_53 += V_62 ;
}
V_7 [ V_54 ] . V_14 = V_14 ;
V_55 = * V_51 & 0xf ;
if ( V_55 ) {
if ( F_7 ( V_51 + V_55 > V_52 ) )
goto V_64;
for ( V_50 = ( V_65 ) V_51 [ V_55 -- ] ; V_55 ; V_55 -- )
V_50 = ( V_50 << 8 ) + V_51 [ V_55 ] ;
} else {
F_24 ( V_47 -> V_59 , L_11
L_12 ) ;
V_50 = ( T_2 ) - 1 ;
}
if ( F_7 ( V_50 < 0 ) ) {
F_24 ( V_47 -> V_59 , L_13
L_14 ) ;
goto V_66;
}
V_7 [ V_54 ] . V_15 = V_50 ;
V_14 += V_50 ;
if ( ! ( * V_51 & 0xf0 ) )
V_7 [ V_54 ] . V_12 = V_16 ;
else {
T_7 V_67 = * V_51 & 0xf ;
V_55 = V_67 + ( ( * V_51 >> 4 ) & 0xf ) ;
if ( V_51 + V_55 > V_52 )
goto V_64;
for ( V_50 = ( V_65 ) V_51 [ V_55 -- ] ; V_55 > V_67 ; V_55 -- )
V_50 = ( V_50 << 8 ) + V_51 [ V_55 ] ;
V_12 += V_50 ;
#ifdef F_21
if ( V_47 -> V_68 < 3 ) {
if ( F_7 ( V_50 == ( T_6 ) - 1 ) )
F_24 ( V_47 -> V_59 , L_15 ) ;
if ( F_7 ( V_12 == ( T_6 ) - 1 ) )
F_24 ( V_47 -> V_59 , L_16 ) ;
}
#endif
if ( F_7 ( V_12 < ( T_6 ) - 1 ) ) {
F_24 ( V_47 -> V_59 , L_17
L_18 ) ;
goto V_66;
}
V_7 [ V_54 ] . V_12 = V_12 ;
}
V_54 ++ ;
V_51 += ( * V_51 & 0xf ) + ( ( * V_51 >> 4 ) & 0xf ) + 1 ;
}
if ( F_7 ( V_51 >= V_52 ) )
goto V_64;
V_50 = F_26 ( V_48 -> V_57 . V_56 . V_69 ) ;
if ( F_7 ( V_50 && V_14 - 1 != V_50 ) ) {
V_70:
F_24 ( V_47 -> V_59 , L_19
L_20 ) ;
goto V_66;
}
if ( ! V_48 -> V_57 . V_56 . V_58 ) {
T_3 V_71 ;
V_71 = ( ( F_26 (
V_48 -> V_57 . V_56 . V_72 ) +
V_47 -> V_73 - 1 ) >>
V_47 -> V_74 ) - 1 ;
if ( V_50 ) {
if ( V_50 < V_71 ) {
F_22 ( L_21
L_22
L_23 ,
( unsigned long long ) V_50 ,
( unsigned long long )
V_71 ) ;
V_7 [ V_54 ] . V_14 = V_14 ;
V_14 += V_7 [ V_54 ] . V_15 = V_71 -
V_50 ;
V_7 [ V_54 ] . V_12 = V_13 ;
V_54 ++ ;
} else if ( F_7 ( V_50 > V_71 ) ) {
F_24 ( V_47 -> V_59 , L_24
L_25
L_26 ,
( unsigned long long ) V_50 ,
( unsigned long long )
V_71 ) ;
goto V_70;
}
}
V_7 [ V_54 ] . V_12 = V_22 ;
} else
V_7 [ V_54 ] . V_12 = V_13 ;
V_7 [ V_54 ] . V_14 = V_14 ;
V_7 [ V_54 ] . V_15 = ( T_2 ) 0 ;
if ( ! V_49 ) {
F_22 ( L_27 ) ;
F_23 ( V_7 ) ;
return V_7 ;
}
V_49 = F_20 ( V_49 , V_7 ) ;
if ( F_2 ( ! F_16 ( V_49 ) ) )
return V_49 ;
F_9 ( V_7 ) ;
F_24 ( V_47 -> V_59 , L_28 ) ;
return V_49 ;
V_64:
F_24 ( V_47 -> V_59 , L_10 ) ;
V_66:
F_9 ( V_7 ) ;
return F_8 ( - V_61 ) ;
}
T_6 F_29 ( const T_1 * V_7 , const T_3 V_14 )
{
int V_75 ;
F_12 ( V_14 < 0 ) ;
if ( F_7 ( ! V_7 ) )
return V_13 ;
if ( F_7 ( V_14 < V_7 [ 0 ] . V_14 ) )
return V_22 ;
for ( V_75 = 0 ; F_2 ( V_7 [ V_75 ] . V_15 ) ; V_75 ++ ) {
if ( F_7 ( V_14 < V_7 [ V_75 + 1 ] . V_14 ) ) {
if ( F_2 ( V_7 [ V_75 ] . V_12 >= ( T_6 ) 0 ) )
return V_7 [ V_75 ] . V_12 + ( V_14 - V_7 [ V_75 ] . V_14 ) ;
return V_7 [ V_75 ] . V_12 ;
}
}
if ( F_2 ( V_7 [ V_75 ] . V_12 < ( T_6 ) 0 ) )
return V_7 [ V_75 ] . V_12 ;
return V_22 ;
}
T_1 * F_30 ( T_1 * V_7 , const T_3 V_14 )
{
F_12 ( V_14 < 0 ) ;
if ( F_7 ( ! V_7 || V_14 < V_7 [ 0 ] . V_14 ) )
return NULL ;
while ( F_2 ( V_7 -> V_15 ) ) {
if ( F_7 ( V_14 < V_7 [ 1 ] . V_14 ) ) {
if ( F_2 ( V_7 -> V_12 >= V_16 ) )
return V_7 ;
return NULL ;
}
V_7 ++ ;
}
if ( F_2 ( V_7 -> V_12 == V_22 ) )
return V_7 ;
return NULL ;
}
static inline int F_31 ( const T_2 V_76 )
{
T_2 V_77 = V_76 ;
int V_75 ;
V_65 V_78 ;
V_75 = 0 ;
do {
V_77 >>= 8 ;
V_75 ++ ;
} while ( V_77 != 0 && V_77 != - 1 );
V_78 = ( V_76 >> 8 * ( V_75 - 1 ) ) & 0xff ;
if ( ( V_76 < 0 && V_78 >= 0 ) || ( V_76 > 0 && V_78 < 0 ) )
V_75 ++ ;
return V_75 ;
}
int F_32 ( const T_4 * V_47 ,
const T_1 * V_7 , const T_3 V_79 ,
const T_3 V_80 )
{
T_6 V_81 ;
int V_82 ;
bool V_83 = false ;
F_12 ( V_79 < 0 ) ;
F_12 ( V_80 < - 1 ) ;
F_12 ( V_80 >= 0 && V_79 > V_80 ) ;
if ( ! V_7 ) {
F_12 ( V_79 ) ;
F_12 ( V_80 > 0 ) ;
return 1 ;
}
while ( V_7 -> V_15 && V_79 >= V_7 [ 1 ] . V_14 )
V_7 ++ ;
if ( F_7 ( ( ! V_7 -> V_15 && V_79 > V_7 -> V_14 ) ||
V_79 < V_7 -> V_14 ) )
return - V_39 ;
V_81 = 0 ;
V_82 = 1 ;
if ( V_79 > V_7 -> V_14 ) {
T_2 V_26 , V_15 = V_7 -> V_15 ;
if ( F_7 ( V_15 < 0 || V_7 -> V_12 < V_16 ) )
goto V_66;
if ( F_7 ( V_80 >= 0 && V_7 [ 1 ] . V_14 > V_80 ) ) {
T_2 V_84 = V_80 + 1 ;
if ( F_7 ( V_7 [ 1 ] . V_14 > V_84 ) )
V_15 = V_84 - V_7 -> V_14 ;
V_83 = true ;
}
V_26 = V_79 - V_7 -> V_14 ;
V_82 += 1 + F_31 ( V_15 - V_26 ) ;
if ( F_2 ( V_7 -> V_12 >= 0 || V_47 -> V_68 < 3 ) ) {
V_81 = V_7 -> V_12 ;
if ( F_2 ( V_7 -> V_12 >= 0 ) )
V_81 += V_26 ;
V_82 += F_31 ( V_81 ) ;
}
V_7 ++ ;
}
for (; V_7 -> V_15 && ! V_83 ; V_7 ++ ) {
T_2 V_15 = V_7 -> V_15 ;
if ( F_7 ( V_15 < 0 || V_7 -> V_12 < V_16 ) )
goto V_66;
if ( F_7 ( V_80 >= 0 && V_7 [ 1 ] . V_14 > V_80 ) ) {
T_2 V_84 = V_80 + 1 ;
if ( F_7 ( V_7 [ 1 ] . V_14 > V_84 ) )
V_15 = V_84 - V_7 -> V_14 ;
V_83 = true ;
}
V_82 += 1 + F_31 ( V_15 ) ;
if ( F_2 ( V_7 -> V_12 >= 0 || V_47 -> V_68 < 3 ) ) {
V_82 += F_31 ( V_7 -> V_12 -
V_81 ) ;
V_81 = V_7 -> V_12 ;
}
}
return V_82 ;
V_66:
if ( V_7 -> V_12 == V_13 )
V_82 = - V_39 ;
else
V_82 = - V_61 ;
return V_82 ;
}
static inline int F_33 ( V_65 * V_2 , const V_65 * V_85 ,
const T_2 V_76 )
{
T_2 V_77 = V_76 ;
int V_75 ;
V_65 V_78 ;
V_75 = 0 ;
do {
if ( F_7 ( V_2 > V_85 ) )
goto V_66;
* V_2 ++ = V_77 & 0xffll ;
V_77 >>= 8 ;
V_75 ++ ;
} while ( V_77 != 0 && V_77 != - 1 );
V_78 = ( V_76 >> 8 * ( V_75 - 1 ) ) & 0xff ;
if ( V_76 < 0 && V_78 >= 0 ) {
if ( F_7 ( V_2 > V_85 ) )
goto V_66;
V_75 ++ ;
* V_2 = ( V_65 ) - 1 ;
} else if ( V_76 > 0 && V_78 < 0 ) {
if ( F_7 ( V_2 > V_85 ) )
goto V_66;
V_75 ++ ;
* V_2 = ( V_65 ) 0 ;
}
return V_75 ;
V_66:
return - V_86 ;
}
int F_34 ( const T_4 * V_47 , V_65 * V_2 ,
const int V_87 , const T_1 * V_7 ,
const T_3 V_79 , const T_3 V_80 , T_3 * const V_88 )
{
T_6 V_81 ;
V_65 * V_85 , * V_89 ;
int V_90 = - V_86 ;
bool V_83 = false ;
V_65 V_91 , V_92 ;
F_12 ( V_79 < 0 ) ;
F_12 ( V_80 < - 1 ) ;
F_12 ( V_80 >= 0 && V_79 > V_80 ) ;
F_12 ( V_87 < 1 ) ;
if ( ! V_7 ) {
F_12 ( V_79 ) ;
F_12 ( V_80 > 0 ) ;
if ( V_88 )
* V_88 = 0 ;
* V_2 = 0 ;
return 0 ;
}
while ( V_7 -> V_15 && V_79 >= V_7 [ 1 ] . V_14 )
V_7 ++ ;
if ( F_7 ( ( ! V_7 -> V_15 && V_79 > V_7 -> V_14 ) ||
V_79 < V_7 -> V_14 ) )
return - V_39 ;
V_85 = V_2 + V_87 - 1 ;
V_81 = 0 ;
if ( V_79 > V_7 -> V_14 ) {
T_2 V_26 , V_15 = V_7 -> V_15 ;
if ( F_7 ( V_15 < 0 || V_7 -> V_12 < V_16 ) )
goto V_66;
if ( F_7 ( V_80 >= 0 && V_7 [ 1 ] . V_14 > V_80 ) ) {
T_2 V_84 = V_80 + 1 ;
if ( F_7 ( V_7 [ 1 ] . V_14 > V_84 ) )
V_15 = V_84 - V_7 -> V_14 ;
V_83 = true ;
}
V_26 = V_79 - V_7 -> V_14 ;
V_91 = F_33 ( V_2 + 1 , V_85 ,
V_15 - V_26 ) ;
if ( F_7 ( V_91 < 0 ) )
goto V_93;
if ( F_2 ( V_7 -> V_12 >= 0 || V_47 -> V_68 < 3 ) ) {
V_81 = V_7 -> V_12 ;
if ( F_2 ( V_7 -> V_12 >= 0 ) )
V_81 += V_26 ;
V_92 = F_33 ( V_2 + 1 +
V_91 , V_85 , V_81 ) ;
if ( F_7 ( V_92 < 0 ) )
goto V_93;
} else
V_92 = 0 ;
V_89 = V_2 + V_91 + V_92 + 1 ;
if ( F_7 ( V_89 > V_85 ) )
goto V_93;
* V_2 = V_92 << 4 | V_91 ;
V_2 = V_89 ;
V_7 ++ ;
}
for (; V_7 -> V_15 && ! V_83 ; V_7 ++ ) {
T_2 V_15 = V_7 -> V_15 ;
if ( F_7 ( V_15 < 0 || V_7 -> V_12 < V_16 ) )
goto V_66;
if ( F_7 ( V_80 >= 0 && V_7 [ 1 ] . V_14 > V_80 ) ) {
T_2 V_84 = V_80 + 1 ;
if ( F_7 ( V_7 [ 1 ] . V_14 > V_84 ) )
V_15 = V_84 - V_7 -> V_14 ;
V_83 = true ;
}
V_91 = F_33 ( V_2 + 1 , V_85 ,
V_15 ) ;
if ( F_7 ( V_91 < 0 ) )
goto V_93;
if ( F_2 ( V_7 -> V_12 >= 0 || V_47 -> V_68 < 3 ) ) {
V_92 = F_33 ( V_2 + 1 +
V_91 , V_85 , V_7 -> V_12 - V_81 ) ;
if ( F_7 ( V_92 < 0 ) )
goto V_93;
V_81 = V_7 -> V_12 ;
} else
V_92 = 0 ;
V_89 = V_2 + V_91 + V_92 + 1 ;
if ( F_7 ( V_89 > V_85 ) )
goto V_93;
* V_2 = V_92 << 4 | V_91 ;
V_2 = V_89 ;
}
V_90 = 0 ;
V_93:
if ( V_88 )
* V_88 = V_7 -> V_14 ;
* V_2 = 0 ;
return V_90 ;
V_66:
if ( V_7 -> V_12 == V_13 )
V_90 = - V_39 ;
else
V_90 = - V_61 ;
return V_90 ;
}
int F_35 ( const T_4 * V_47 , T_9 * const T_9 ,
const T_2 V_94 )
{
T_1 * V_7 ;
int V_8 ;
F_22 ( L_29 , ( long long ) V_94 ) ;
F_12 ( ! T_9 ) ;
F_12 ( V_94 < 0 ) ;
V_7 = T_9 -> V_7 ;
if ( ! V_94 ) {
F_22 ( L_30 ) ;
T_9 -> V_7 = NULL ;
if ( V_7 )
F_9 ( V_7 ) ;
return 0 ;
}
if ( F_7 ( ! V_7 ) ) {
V_7 = F_6 ( V_62 ) ;
if ( F_7 ( ! V_7 ) ) {
F_24 ( V_47 -> V_59 , L_31
L_32 ) ;
return - V_11 ;
}
T_9 -> V_7 = V_7 ;
V_7 [ 1 ] . V_15 = V_7 -> V_14 = 0 ;
V_7 -> V_12 = V_16 ;
V_7 [ 1 ] . V_14 = V_7 -> V_15 = V_94 ;
V_7 [ 1 ] . V_12 = V_22 ;
return 0 ;
}
F_12 ( V_94 < V_7 -> V_14 ) ;
while ( F_2 ( V_7 -> V_15 && V_94 >= V_7 [ 1 ] . V_14 ) )
V_7 ++ ;
if ( V_7 -> V_15 ) {
T_1 * V_95 ;
bool V_96 ;
F_22 ( L_33 ) ;
V_95 = V_7 + 1 ;
while ( F_2 ( V_95 -> V_15 ) )
V_95 ++ ;
V_8 = V_95 - T_9 -> V_7 + 1 ;
V_7 -> V_15 = V_94 - V_7 -> V_14 ;
V_96 = false ;
if ( V_7 -> V_15 ) {
V_7 ++ ;
if ( ! V_7 -> V_15 )
V_96 = true ;
V_7 -> V_14 = V_94 ;
V_7 -> V_15 = 0 ;
}
V_7 -> V_12 = V_22 ;
if ( ! V_96 ) {
int V_9 = V_7 - T_9 -> V_7 + 1 ;
V_7 = F_4 ( T_9 -> V_7 , V_8 , V_9 ) ;
if ( F_16 ( V_7 ) )
F_36 ( V_47 -> V_59 , L_34
L_35
L_36
L_37
L_38 ) ;
else
T_9 -> V_7 = V_7 ;
}
} else if ( F_2 ( V_94 > V_7 -> V_14 ) ) {
F_22 ( L_39 ) ;
if ( ( V_7 > T_9 -> V_7 ) && ( ( V_7 - 1 ) -> V_12 == V_16 ) )
( V_7 - 1 ) -> V_15 = V_94 - ( V_7 - 1 ) -> V_14 ;
else {
V_8 = V_7 - T_9 -> V_7 + 1 ;
V_7 = F_4 ( T_9 -> V_7 , V_8 ,
V_8 + 1 ) ;
if ( F_16 ( V_7 ) ) {
F_24 ( V_47 -> V_59 , L_40
L_41 ) ;
return F_37 ( V_7 ) ;
}
T_9 -> V_7 = V_7 ;
V_7 += V_8 - 1 ;
V_7 -> V_12 = V_16 ;
V_7 -> V_15 = V_94 - V_7 -> V_14 ;
V_7 ++ ;
V_7 -> V_15 = 0 ;
}
V_7 -> V_14 = V_94 ;
V_7 -> V_12 = V_22 ;
} else {
V_7 -> V_12 = V_22 ;
}
F_22 ( L_42 ) ;
return 0 ;
}
int F_38 ( const T_4 * V_47 , T_9 * const T_9 ,
const T_3 V_42 , const T_2 V_15 )
{
const T_3 V_97 = V_42 + V_15 ;
T_2 V_26 ;
T_1 * V_7 , * V_98 , * V_99 , * V_95 ;
int V_8 ;
bool V_100 = false ;
F_22 ( L_43 ,
( long long ) V_42 , ( long long ) V_15 ) ;
F_12 ( ! T_9 ) ;
F_12 ( V_42 < 0 ) ;
F_12 ( V_15 < 0 ) ;
F_12 ( V_97 < 0 ) ;
V_7 = T_9 -> V_7 ;
if ( F_7 ( ! V_7 ) ) {
if ( F_2 ( ! V_42 && ! V_15 ) )
return 0 ;
return - V_101 ;
}
while ( F_2 ( V_7 -> V_15 && V_42 >= V_7 [ 1 ] . V_14 ) )
V_7 ++ ;
V_98 = V_7 ;
while ( F_2 ( V_98 -> V_15 && V_97 >= V_98 [ 1 ] . V_14 ) ) {
if ( F_7 ( V_98 -> V_12 < V_16 ) )
return - V_39 ;
V_98 ++ ;
}
if ( F_7 ( V_98 -> V_15 && V_98 -> V_12 < V_16 ) )
return - V_39 ;
if ( ! V_98 -> V_15 && V_97 > V_98 -> V_14 )
return - V_101 ;
if ( ! V_15 )
return 0 ;
if ( ! V_7 -> V_15 )
return - V_101 ;
V_99 = V_98 ;
while ( F_2 ( V_99 -> V_15 ) )
V_99 ++ ;
V_8 = V_99 - T_9 -> V_7 + 1 ;
if ( V_7 -> V_12 == V_16 ) {
if ( V_97 <= V_7 [ 1 ] . V_14 ) {
F_22 ( L_44 ) ;
return 0 ;
}
V_102:
V_7 -> V_15 = V_97 - V_7 -> V_14 ;
if ( V_98 -> V_12 == V_16 ) {
V_98 ++ ;
V_7 -> V_15 = V_98 -> V_14 - V_7 -> V_14 ;
}
V_7 ++ ;
if ( V_7 < V_98 )
memmove ( V_7 , V_98 , ( V_99 - V_98 + 1 ) *
sizeof( * V_7 ) ) ;
if ( V_97 > V_7 -> V_14 ) {
V_26 = V_97 - V_7 -> V_14 ;
V_7 -> V_14 = V_97 ;
V_7 -> V_15 -= V_26 ;
if ( V_7 -> V_12 >= 0 )
V_7 -> V_12 += V_26 ;
}
V_103:
if ( V_7 < V_98 ) {
V_7 = F_4 ( T_9 -> V_7 , V_8 ,
V_8 - ( V_98 - V_7 ) ) ;
if ( F_16 ( V_7 ) )
F_36 ( V_47 -> V_59 , L_34
L_35
L_36
L_37
L_38 ) ;
else
T_9 -> V_7 = V_7 ;
}
F_22 ( L_45 ) ;
return 0 ;
}
if ( V_42 == V_7 -> V_14 ) {
if ( V_7 > T_9 -> V_7 && ( V_7 - 1 ) -> V_12 == V_16 ) {
V_7 -- ;
goto V_102;
}
if ( V_97 >= V_7 [ 1 ] . V_14 ) {
V_7 -> V_12 = V_16 ;
goto V_102;
}
V_95 = F_4 ( T_9 -> V_7 , V_8 , V_8 + 1 ) ;
if ( F_16 ( V_95 ) )
goto V_104;
V_8 ++ ;
if ( T_9 -> V_7 != V_95 ) {
V_7 = V_95 + ( V_7 - T_9 -> V_7 ) ;
V_98 = V_95 + ( V_98 - T_9 -> V_7 ) ;
V_99 = V_95 + ( V_99 - T_9 -> V_7 ) ;
T_9 -> V_7 = V_95 ;
}
V_105:
memmove ( V_7 + 1 , V_7 , ( V_99 - V_7 + 1 ) * sizeof( * V_7 ) ) ;
V_7 -> V_12 = V_16 ;
V_7 -> V_15 = V_15 ;
V_7 ++ ;
V_7 -> V_14 += V_15 ;
if ( V_7 -> V_12 >= 0 || V_100 )
V_7 -> V_12 += V_15 ;
V_7 -> V_15 -= V_15 ;
F_22 ( L_46 ) ;
return 0 ;
}
if ( V_98 -> V_12 == V_16 ) {
V_7 -> V_15 = V_42 - V_7 -> V_14 ;
V_7 ++ ;
if ( V_7 < V_98 )
memmove ( V_7 , V_98 , ( V_99 - V_98 + 1 ) *
sizeof( * V_7 ) ) ;
V_7 -> V_14 = V_42 ;
V_7 -> V_15 = V_7 [ 1 ] . V_14 - V_42 ;
goto V_103;
}
if ( V_97 >= V_7 [ 1 ] . V_14 ) {
if ( V_7 [ 1 ] . V_15 && V_97 >= V_7 [ 2 ] . V_14 ) {
V_7 -> V_15 = V_42 - V_7 -> V_14 ;
V_7 ++ ;
V_7 -> V_14 = V_42 ;
V_7 -> V_12 = V_16 ;
goto V_102;
}
V_95 = F_4 ( T_9 -> V_7 , V_8 , V_8 + 1 ) ;
if ( F_16 ( V_95 ) )
goto V_104;
V_8 ++ ;
if ( T_9 -> V_7 != V_95 ) {
V_7 = V_95 + ( V_7 - T_9 -> V_7 ) ;
V_98 = V_95 + ( V_98 - T_9 -> V_7 ) ;
V_99 = V_95 + ( V_99 - T_9 -> V_7 ) ;
T_9 -> V_7 = V_95 ;
}
V_7 -> V_15 = V_42 - V_7 -> V_14 ;
V_7 ++ ;
V_26 = V_7 -> V_14 - V_42 ;
V_7 -> V_14 = V_42 ;
if ( V_7 -> V_12 >= 0 ) {
V_7 -> V_12 -= V_26 ;
V_100 = true ;
}
V_7 -> V_15 += V_26 ;
goto V_105;
}
V_95 = F_4 ( T_9 -> V_7 , V_8 , V_8 + 2 ) ;
if ( F_16 ( V_95 ) )
goto V_104;
V_8 += 2 ;
if ( T_9 -> V_7 != V_95 ) {
V_7 = V_95 + ( V_7 - T_9 -> V_7 ) ;
V_98 = V_95 + ( V_98 - T_9 -> V_7 ) ;
V_99 = V_95 + ( V_99 - T_9 -> V_7 ) ;
T_9 -> V_7 = V_95 ;
}
memmove ( V_7 + 2 , V_7 , ( V_99 - V_7 + 1 ) * sizeof( * V_7 ) ) ;
V_7 -> V_15 = V_42 - V_7 -> V_14 ;
V_7 ++ ;
V_7 -> V_14 = V_42 ;
V_7 -> V_12 = V_16 ;
V_7 -> V_15 = V_15 ;
V_7 ++ ;
V_26 = V_97 - V_7 -> V_14 ;
V_7 -> V_14 = V_97 ;
V_7 -> V_12 += V_26 ;
V_7 -> V_15 -= V_26 ;
F_22 ( L_47 ) ;
return 0 ;
V_104:
F_24 ( V_47 -> V_59 , L_48 ) ;
return - V_11 ;
}
