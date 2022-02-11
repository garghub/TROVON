int F_1 ( void )
{
int V_1 ;
F_2 ( L_1 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
if ( V_3 [ V_1 ] != NULL ) {
F_2 ( L_2 , V_1 , V_3 [ V_1 ] ) ;
F_3 ( V_3 [ V_1 ] ) ;
V_3 [ V_1 ] = NULL ;
}
}
return V_4 ;
}
int F_4 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 , T_3 * V_9 )
{
T_2 V_10 , V_11 ;
if ( F_5 ( V_6 , V_7 ) )
return V_12 ;
while ( 1 ) {
V_10 = V_13 . V_14 - V_15 . V_16 ;
if ( V_8 > V_10 )
V_11 = V_10 ;
else
V_11 = V_8 ;
if ( F_6 ( V_6 , V_11 , V_9 ) ) {
V_12 = V_17 ;
return V_12 ;
}
V_15 . V_16 += V_11 ;
V_8 -= V_11 ;
if ( V_8 <= 0 )
break;
V_9 += V_11 * V_18 ;
if ( F_7 ( V_6 ) )
return V_12 ;
}
return V_4 ;
}
int F_8 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 , T_3 * V_9 )
{
T_2 V_10 , V_11 ;
if ( F_5 ( V_6 , V_7 ) )
return V_12 ;
while ( 1 ) {
if ( F_9 () )
return ERROR ;
V_10 = V_13 . V_14 - V_15 . V_16 ;
if ( V_8 > V_10 )
V_11 = V_10 ;
else
V_11 = V_8 ;
if ( F_10 ( V_6 , V_11 , V_9 , V_19 ) ) {
V_12 = V_20 ;
return V_12 ;
}
V_15 . V_16 = 0x1F ;
if ( F_11 ( V_6 ) ) {
if ( V_12 == V_21 ) {
V_12 = V_20 ;
return V_12 ;
}
}
V_8 -= V_11 ;
if ( V_8 <= 0 )
break;
V_9 += V_11 * V_18 ;
if ( F_7 ( V_6 ) )
return V_12 ;
}
return V_4 ;
}
static int F_11 ( struct V_5 * V_6 )
{
V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] = V_24 ;
V_15 . V_25 = V_26 ;
if ( V_15 . V_25 == V_27 ) {
V_15 . V_25 = V_24 ;
return V_28 ;
}
F_12 ( V_29 [ V_15 . V_22 ] , V_15 . V_25 ) ;
V_15 . V_25 = V_24 ;
return V_28 ;
}
int F_13 ( struct V_5 * V_6 )
{
F_2 ( L_3 ) ;
if ( ! V_30 )
return V_28 ;
V_30 = ERROR ;
V_31 = V_32 ;
if ( F_14 ( V_6 ) ) {
V_12 = V_33 ;
return ERROR ;
}
if ( F_15 ( V_6 ) ) {
V_12 = V_34 ;
return ERROR ;
}
V_30 = V_28 ;
return V_28 ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_35 )
{
T_1 V_36 ;
V_36 = V_35 / V_13 . V_14 ;
V_15 . V_22 = ( T_3 ) ( V_36 / V_13 . V_37 ) ;
if ( V_3 [ V_15 . V_22 ] == NULL ) {
if ( F_16 ( V_6 ) ) {
V_12 = V_34 ;
return ERROR ;
}
}
V_15 . V_16 = ( T_3 ) ( V_35 % V_13 . V_14 ) ;
V_15 . V_23 = ( T_2 ) ( V_36 % V_13 . V_37 ) ;
if ( V_15 . V_22 < V_13 . V_38 ) {
F_17 ( V_19 ) ;
F_18 ( V_19 ) ;
V_15 . V_25 = V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] ;
return V_28 ;
}
V_12 = V_39 ;
return ERROR ;
}
static int F_7 ( struct V_5 * V_6 )
{
T_2 V_23 = V_15 . V_23 ;
if ( ++ V_15 . V_16 < V_13 . V_14 )
return V_28 ;
if ( V_3 [ V_15 . V_22 ] == NULL ) {
if ( F_16 ( V_6 ) ) {
V_12 = V_34 ;
return ERROR ;
}
}
V_15 . V_16 = 0 ;
V_15 . V_23 = V_23 ;
if ( ++ V_15 . V_23 < V_13 . V_37 ) {
F_17 ( V_19 ) ;
F_18 ( V_19 ) ;
V_15 . V_25 = V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] ;
return V_28 ;
}
V_15 . V_23 = 0 ;
if ( ++ V_15 . V_22 < V_13 . V_38 ) {
if ( V_3 [ V_15 . V_22 ] == NULL ) {
if ( F_16 ( V_6 ) ) {
V_12 = V_34 ;
return ERROR ;
}
}
V_15 . V_23 = 0 ;
F_17 ( V_19 ) ;
F_18 ( V_19 ) ;
V_15 . V_25 = V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] ;
return V_28 ;
}
V_15 . V_22 = 0 ;
V_12 = V_39 ;
return ERROR ;
}
static int F_6 ( struct V_5 * V_6 , T_2 V_8 , T_3 * V_9 )
{
T_1 V_40 , V_41 ;
if ( ! F_19 ( V_6 , V_8 , V_9 ) )
return V_28 ;
if ( V_12 == V_21 )
return ERROR ;
if ( V_12 == V_42 )
return ERROR ;
#ifdef F_20
if ( V_13 . V_43 & V_44 ) {
if ( V_12 == V_45 )
return V_28 ;
return ERROR ;
}
V_40 = V_12 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
if ( F_21 ( V_6 ,
( V_40 == V_17 ) ? V_46 : V_47 ) ) {
if ( V_12 == V_21 )
return ERROR ;
continue;
}
V_12 = V_40 ;
if ( V_12 == V_45 )
return V_28 ;
return ERROR ;
}
V_30 = ERROR ;
#else
if ( V_12 == V_45 )
return V_28 ;
#endif
return ERROR ;
}
static int F_21 ( struct V_5 * V_6 , T_1 V_48 )
{
T_3 V_49 ;
V_49 = V_15 . V_16 ;
if ( F_9 () )
return ERROR ;
if ( V_48 == V_46 )
V_31 = V_46 ;
for ( V_15 . V_16 = 0 ; V_15 . V_16 < V_13 . V_14 ;
V_15 . V_16 ++ ) {
if ( F_22 ( V_6 ) ) {
if ( V_12 == V_21 )
return ERROR ;
if ( F_23 ( V_6 ) )
return ERROR ;
V_12 = V_20 ;
V_15 . V_25 = V_26 ;
V_15 . V_16 = V_49 ;
return ERROR ;
}
}
if ( F_24 ( V_6 ) )
return ERROR ;
V_15 . V_25 = V_24 ;
V_15 . V_16 = V_49 ;
return V_28 ;
}
static int F_9 ( void )
{
V_26 = V_15 . V_25 ;
for ( V_24 = V_50 [ V_15 . V_22 ] ;
V_24 < V_13 . V_51 ; V_24 ++ ) {
if ( ! F_25 ( V_29 [ V_15 . V_22 ] , V_24 ) ) {
F_26 ( V_29 [ V_15 . V_22 ] , V_24 ) ;
V_50 [ V_15 . V_22 ] = V_24 + 1 ;
V_15 . V_25 = V_24 ;
V_31 = V_47 ;
return V_28 ;
}
}
for ( V_24 = 0 ;
V_24 < V_50 [ V_15 . V_22 ] ; V_24 ++ ) {
if ( ! F_25 ( V_29 [ V_15 . V_22 ] , V_24 ) ) {
F_26 ( V_29 [ V_15 . V_22 ] , V_24 ) ;
V_50 [ V_15 . V_22 ] = V_24 + 1 ;
V_15 . V_25 = V_24 ;
V_31 = V_47 ;
return V_28 ;
}
}
V_24 = V_27 ;
V_12 = V_20 ;
return ERROR ;
}
static int F_24 ( struct V_5 * V_6 )
{
T_1 V_48 ;
V_48 = V_31 ;
V_31 = V_32 ;
if ( V_48 == V_32 )
return V_28 ;
V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] = V_24 ;
V_15 . V_25 = V_26 ;
if ( V_15 . V_25 == V_27 ) {
V_15 . V_25 = V_24 ;
return V_28 ;
}
if ( V_48 == V_47 ) {
if ( F_27 ( V_6 ) ) {
if ( V_12 == V_21 )
return ERROR ;
if ( F_28 ( V_6 ) )
return ERROR ;
} else
F_12 ( V_29 [ V_15 . V_22 ] , V_15 . V_25 ) ;
} else if ( F_28 ( V_6 ) )
return ERROR ;
V_15 . V_25 = V_24 ;
return V_28 ;
}
static int F_23 ( struct V_5 * V_6 )
{
V_31 = V_32 ;
V_15 . V_25 = V_24 ;
if ( F_28 ( V_6 ) )
return ERROR ;
V_15 . V_25 = V_26 ;
return V_28 ;
}
static int F_22 ( struct V_5 * V_6 )
{
int V_1 ;
T_1 V_40 , V_41 ;
if ( V_26 != V_27 ) {
V_15 . V_25 = V_26 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
if ( V_41 != 0 ) {
F_29 ( V_6 ) ;
if ( F_30 ( V_6 , V_52 ,
V_53 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
if ( F_31 ( V_52 , V_53 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
}
if ( F_32 ( V_6 , V_52 , V_53 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
if ( F_33 ( V_53 ) ) {
V_40 = ERROR ;
break;
}
if ( ! F_34 ( V_53 ) ) {
V_40 = V_28 ;
break;
}
if ( ! F_35 ( V_52 , V_53 ) ) {
V_40 = V_28 ;
break;
}
V_40 = ERROR ;
V_31 = V_46 ;
}
} else {
V_40 = V_28 ;
for ( V_1 = 0 ; V_1 < V_18 ; V_1 ++ )
V_52 [ V_1 ] = V_54 ;
F_17 ( V_53 ) ;
}
F_18 ( V_53 ) ;
if ( V_40 == ERROR ) {
F_36 ( V_53 ) ;
F_37 ( V_53 ) ;
}
V_15 . V_25 = V_24 ;
if ( F_38 ( V_6 , V_52 , V_53 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
if ( F_39 () ) {
V_12 = V_20 ;
return ERROR ;
}
V_15 . V_25 = V_26 ;
return V_28 ;
}
static int F_19 ( struct V_5 * V_6 , T_2 V_8 , T_3 * V_9 )
{
int V_1 ;
T_1 V_41 ;
if ( V_15 . V_25 == V_27 ) {
for ( V_1 = 0 ; V_1 < V_18 ; V_1 ++ )
* V_9 ++ = V_54 ;
return V_28 ;
}
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
if ( V_41 != 0 ) {
F_29 ( V_6 ) ;
if ( F_30 ( V_6 , V_52 , V_53 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
if ( F_31 ( V_52 , V_53 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
}
if ( F_40 ( V_6 , V_8 , V_9 , V_19 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
if ( F_33 ( V_19 ) ) {
V_12 = V_42 ;
return ERROR ;
}
if ( ! F_34 ( V_19 ) )
return V_28 ;
if ( ! F_35 ( V_9 , V_19 ) ) {
V_12 = V_45 ;
return ERROR ;
}
}
V_12 = V_17 ;
return ERROR ;
}
static int F_27 ( struct V_5 * V_6 )
{
if ( F_41 ( V_6 ) ) {
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
if ( F_39 () ) {
V_12 = V_20 ;
return ERROR ;
}
return V_28 ;
}
static int F_14 ( struct V_5 * V_6 )
{
if ( F_42 ( V_6 -> V_55 ) )
return ERROR ;
return V_28 ;
}
static int F_15 ( struct V_5 * V_6 )
{
V_15 . V_22 = 0 ;
V_15 . V_16 = 0 ;
for ( V_15 . V_25 = 0 ;
V_15 . V_25 < ( V_13 . V_51 - V_13 . V_37 - 1 ) ;
V_15 . V_25 ++ ) {
if ( F_43 ( V_6 , V_19 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
if ( ! F_44 ( V_19 ) )
break;
}
if ( V_15 . V_25 == ( V_13 . V_51 - V_13 . V_37 - 1 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
while ( V_15 . V_16 < V_56 ) {
if ( V_15 . V_16 ) {
if ( F_43 ( V_6 , V_19 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
}
if ( ! F_33 ( V_19 ) ) {
if ( F_32 ( V_6 , V_52 , V_19 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
if ( F_31 ( V_52 , V_19 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
V_57 . V_25 = V_15 . V_25 ;
V_57 . V_16 = V_15 . V_16 ;
F_29 ( V_6 ) ;
return V_28 ;
}
V_15 . V_16 ++ ;
}
F_29 ( V_6 ) ;
return ERROR ;
}
static int F_16 ( struct V_5 * V_6 )
{
T_2 V_58 , V_59 ;
if ( V_3 [ V_15 . V_22 ] == NULL ) {
V_3 [ V_15 . V_22 ] = F_45 ( V_60 * sizeof( T_2 ) ,
V_61 ) ;
if ( V_3 [ V_15 . V_22 ] == NULL )
return ERROR ;
}
V_15 . V_16 = 0 ;
for ( V_15 . V_23 = 0 ; V_15 . V_23 < V_13 . V_37 ;
V_15 . V_23 ++ )
V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] = V_27 ;
for ( V_15 . V_25 = 0 ; V_15 . V_25 < ( V_62 / 8 ) ;
V_15 . V_25 ++ )
V_29 [ V_15 . V_22 ] [ V_15 . V_25 ] = 0x00 ;
for ( V_15 . V_25 = 0 ; V_15 . V_25 < V_13 . V_51 ;
V_15 . V_25 ++ ) {
if ( ( ! V_15 . V_22 ) && ( V_15 . V_25 <= V_57 . V_25 ) ) {
F_26 ( V_29 [ V_15 . V_22 ] , V_15 . V_25 ) ;
continue;
}
if ( F_43 ( V_6 , V_19 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
if ( ! F_46 ( V_19 ) )
continue;
F_26 ( V_29 [ V_15 . V_22 ] , V_15 . V_25 ) ;
if ( F_44 ( V_19 ) )
continue;
if ( F_47 ( V_19 ) )
continue;
if ( V_15 . V_23 >= V_13 . V_37 )
continue;
if ( V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] == V_27 ) {
V_3 [ V_15 . V_22 ] [ V_15 . V_23 ] = V_15 . V_25 ;
continue;
}
V_58 = V_15 . V_25 ;
V_59 = V_15 . V_23 ;
V_15 . V_16 = ( T_3 ) ( V_13 . V_14 - 1 ) ;
if ( F_43 ( V_6 , V_19 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
if ( ! F_47 ( V_19 ) &&
( V_15 . V_23 == V_59 ) ) {
V_15 . V_25 = V_3 [ V_15 . V_22 ] [ V_59 ] ;
if ( F_43 ( V_6 , V_19 ) ) {
F_29 ( V_6 ) ;
return ERROR ;
}
V_15 . V_25 = V_58 ;
if ( ! F_47 ( V_19 ) ) {
if ( V_15 . V_23 != V_59 ) {
V_15 . V_25 =
V_3 [ V_15 . V_22 ] [ V_59 ] ;
V_3 [ V_15 . V_22 ] [ V_59 ] =
V_58 ;
}
} else {
V_15 . V_25 = V_3 [ V_15 . V_22 ] [ V_59 ] ;
V_3 [ V_15 . V_22 ] [ V_59 ] = V_58 ;
}
}
V_15 . V_16 = 0 ;
V_15 . V_25 = V_58 ;
V_50 [ V_15 . V_22 ] = 0 ;
}
F_29 ( V_6 ) ;
return V_28 ;
}
static int F_28 ( struct V_5 * V_6 )
{
T_3 V_49 ;
V_49 = V_15 . V_16 ;
F_48 ( V_53 ) ;
for ( V_15 . V_16 = 0 ; V_15 . V_16 < V_13 . V_14 ;
V_15 . V_16 ++ ) {
if ( F_49 ( V_6 , V_53 ) ) {
F_29 ( V_6 ) ;
V_15 . V_16 = V_49 ;
V_12 = V_21 ;
V_30 = ERROR ;
return ERROR ;
}
}
F_29 ( V_6 ) ;
V_15 . V_16 = V_49 ;
return V_28 ;
}
