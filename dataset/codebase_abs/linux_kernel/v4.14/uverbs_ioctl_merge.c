static T_1 F_1 ( const void * * V_1 ,
unsigned int V_2 ,
const void * * V_3 ,
T_1 V_4 ,
T_1 V_5 ,
T_1 V_6 ,
T_2 V_7 ,
short * V_8 )
{
T_1 V_9 = 0 ;
short V_10 = V_11 ;
const void * V_12 ;
int V_13 , V_14 , V_15 = - 1 ;
F_2 (elem, i, j, elements, num_elements, num_offset,
data_offset) {
T_2 V_16 = * ( T_2 * ) ( V_12 + V_6 ) ;
if ( F_3 ( V_16 ) != V_7 )
continue;
if ( F_4 ( V_16 ) < * V_8 ||
( V_10 != V_11 && F_4 ( V_16 ) > V_10 ) )
continue;
V_1 [ V_15 == V_13 ? V_9 - 1 : V_9 ++ ] = V_12 ;
V_15 = V_13 ;
V_10 = F_4 ( V_16 ) ;
}
for ( V_13 = V_9 - 1 ; V_13 >= 0 &&
F_4 ( * ( T_2 * ) ( V_1 [ V_13 ] + V_6 ) ) == V_10 ; V_13 -- )
;
V_9 -= V_13 + 1 ;
memmove ( V_1 , V_1 + V_13 + 1 , sizeof( * V_1 ) * V_9 ) ;
* V_8 = V_10 ;
return V_9 ;
}
static short F_5 ( unsigned int V_2 ,
const void * * V_3 ,
T_1 V_4 ,
T_1 V_5 ,
T_1 V_6 )
{
short V_17 = V_18 ;
const void * V_12 ;
int V_13 , V_14 ;
F_2 (elem, i, j, elements, num_elements, num_offset,
data_offset) {
T_2 V_16 = * ( T_2 * ) ( V_12 + V_6 ) ;
if ( F_3 ( V_16 ) > V_17 )
V_17 = F_3 ( V_16 ) ;
}
return V_17 ;
}
static short F_6 ( unsigned int V_2 ,
const void * * V_3 ,
T_1 V_4 ,
T_1 V_5 ,
T_1 V_6 ,
T_2 V_7 )
{
short V_19 = V_18 ;
const void * V_12 ;
int V_13 , V_14 ;
F_2 (elem, i, j, elements, num_elements, num_offset,
data_offset) {
T_2 V_16 = * ( T_2 * ) ( V_12 + V_6 ) ;
if ( F_3 ( V_16 ) == V_7 &&
F_4 ( V_16 ) > V_19 )
V_19 = F_4 ( V_16 ) ;
}
return V_19 ;
}
static void F_7 ( struct V_20 * V_21 )
{
unsigned int V_13 ;
if ( ! V_21 )
return;
for ( V_13 = 0 ; V_13 < V_21 -> V_22 ; V_13 ++ )
F_8 ( V_21 -> V_23 [ V_13 ] ) ;
F_8 ( V_21 ) ;
}
static struct V_20 * F_9 ( const struct V_24 * * V_25 ,
T_1 V_26 )
{
int V_27 ;
int V_28 = 0 ;
T_1 V_29 = 0 ;
int V_30 = 0 ;
struct V_20 * V_21 = NULL ;
const struct V_31 * * V_32 ;
unsigned int V_33 = 0 ;
V_28 = F_10 ( V_26 , V_25 ) ;
if ( V_28 >= 0 )
V_29 = V_28 + 1 ;
V_21 = F_11 ( sizeof( * V_21 ) +
V_29 * sizeof( * V_21 -> V_23 ) ,
V_34 ) ;
if ( ! V_21 )
return F_12 ( - V_35 ) ;
V_21 -> V_22 = V_29 ;
V_32 = F_13 ( V_26 , sizeof( * V_32 ) , V_34 ) ;
if ( ! V_32 ) {
V_30 = - V_35 ;
goto F_7;
}
for ( V_27 = 0 ; V_27 < V_21 -> V_22 ; V_27 ++ ) {
short V_8 = V_18 ;
int V_36 = 0 ;
struct V_37 * V_38 = NULL ;
V_36 = F_14 ( V_26 , V_25 ,
V_27 ) ;
if ( V_36 < 0 )
continue;
V_38 = F_11 ( sizeof( * V_38 ) +
F_15 ( sizeof( * V_38 -> V_39 ) * ( V_36 + 1 ) ,
sizeof( long ) ) +
F_16 ( V_36 ) * sizeof( long ) ,
V_34 ) ;
if ( ! V_38 ) {
V_30 = - V_35 ;
goto free;
}
V_38 -> V_40 = V_36 + 1 ;
V_21 -> V_41 += V_38 -> V_40 ;
V_38 -> V_42 = ( void * ) ( V_38 + 1 ) +
F_15 ( sizeof( * V_38 -> V_39 ) *
( V_36 + 1 ) ,
sizeof( long ) ) ;
V_21 -> V_23 [ V_27 ] = V_38 ;
do {
T_1 V_43 ;
struct V_44 * V_45 ;
bool V_46 ;
V_43 =
F_17 ( V_32 ,
V_26 ,
V_25 ,
V_27 ,
& V_8 ) ;
if ( ! V_43 )
break;
if ( V_43 > 1 ) {
V_30 = - V_47 ;
goto free;
}
V_45 = & V_38 -> V_39 [ V_8 ] ;
memcpy ( V_45 , & V_32 [ 0 ] -> V_45 , sizeof( * V_45 ) ) ;
V_46 = F_18 ( V_45 ) &&
( V_45 -> V_48 . V_49 == V_50 ||
V_45 -> V_48 . V_49 == V_51 ) ;
V_33 += ! ! V_46 ;
if ( F_19 ( V_33 > 1 ,
L_1 ,
V_8 ) ||
F_19 ( V_46 &&
! ( V_45 -> V_52 & V_53 ) ,
L_2 ,
V_8 ) ||
F_19 ( F_18 ( V_45 ) &&
V_45 -> V_52 & V_54 ,
L_3 ,
V_8 ) ) {
V_30 = - V_55 ;
goto free;
}
if ( V_45 -> V_52 & V_53 )
F_20 ( V_8 , V_38 -> V_42 ) ;
V_8 ++ ;
} while ( 1 );
}
F_8 ( V_32 ) ;
return V_21 ;
free:
F_8 ( V_32 ) ;
F_7:
F_7 ( V_21 ) ;
return F_12 ( V_30 ) ;
}
static void F_21 ( struct V_56 * V_57 )
{
unsigned int V_13 , V_14 ;
if ( ! V_57 )
return;
for ( V_13 = 0 ; V_13 < V_57 -> V_22 ; V_13 ++ ) {
struct V_58 * V_59 =
V_57 -> V_59 [ V_13 ] ;
if ( ! V_59 )
continue;
for ( V_14 = 0 ; V_14 < V_59 -> V_60 ; V_14 ++ )
F_7 ( V_59 -> V_61 [ V_14 ] ) ;
F_8 ( V_59 ) ;
}
F_8 ( V_57 ) ;
}
static struct V_56 * F_22 ( const struct V_62 * * V_63 ,
T_1 V_64 )
{
T_2 V_27 ;
int V_65 = 0 ;
T_2 V_66 = 0 ;
int V_30 = 0 ;
struct V_56 * V_57 = NULL ;
const struct V_24 * * V_25 ;
V_65 = F_23 ( V_64 , V_63 ) ;
if ( V_65 >= 0 )
V_66 = V_65 + 1 ;
V_57 = F_11 ( sizeof( * V_57 ) +
V_66 *
sizeof( * V_57 -> V_59 ) , V_34 ) ;
if ( ! V_57 )
return F_12 ( - V_35 ) ;
V_57 -> V_22 = V_66 ;
V_25 = F_13 ( V_64 , sizeof( * V_25 ) , V_34 ) ;
if ( ! V_25 ) {
V_30 = - V_35 ;
goto F_21;
}
for ( V_27 = 0 ; V_27 < V_57 -> V_22 ; V_27 ++ ) {
short V_8 = V_18 ;
int V_67 = 0 ;
struct V_58 * V_38 = NULL ;
V_67 = F_24 ( V_64 , V_63 ,
V_27 ) ;
if ( V_67 < 0 )
continue;
V_38 = F_11 ( sizeof( * V_38 ) +
sizeof( * V_38 -> V_61 ) * ( V_67 + 1 ) ,
V_34 ) ;
if ( ! V_38 ) {
V_30 = - V_35 ;
goto free;
}
V_38 -> V_60 = V_67 + 1 ;
V_57 -> V_59 [ V_27 ] = V_38 ;
do {
T_1 V_26 ;
struct V_20 * V_21 ;
int V_13 ;
V_26 =
F_25 ( V_25 ,
V_64 ,
V_63 ,
V_27 ,
& V_8 ) ;
if ( ! V_26 )
break;
V_21 = F_9 ( V_25 ,
V_26 ) ;
if ( F_26 ( V_21 ) ) {
V_30 = F_27 ( V_21 ) ;
goto free;
}
for ( V_13 = V_64 - 1 ;
V_13 >= 0 && ! V_25 [ V_13 ] -> V_68 ; V_13 -- )
;
V_38 -> V_61 [ V_8 ++ ] = V_21 ;
if ( F_19 ( V_13 < 0 ,
L_4 ,
V_8 ) ) {
V_30 = - V_55 ;
goto free;
}
V_21 -> V_68 = V_25 [ V_13 ] -> V_68 ;
V_21 -> V_52 = V_25 [ V_13 ] -> V_52 ;
} while ( 1 );
}
F_8 ( V_25 ) ;
return V_57 ;
free:
F_8 ( V_25 ) ;
F_21:
F_21 ( V_57 ) ;
return F_12 ( V_30 ) ;
}
void F_28 ( struct V_69 * V_70 )
{
unsigned int V_13 , V_14 ;
if ( ! V_70 )
return;
for ( V_13 = 0 ; V_13 < V_70 -> V_22 ; V_13 ++ ) {
struct V_71 * V_72 =
V_70 -> V_73 [ V_13 ] ;
if ( ! V_72 )
continue;
for ( V_14 = 0 ; V_14 < V_72 -> V_74 ; V_14 ++ )
F_21 ( V_72 -> V_75 [ V_14 ] ) ;
F_8 ( V_72 ) ;
}
F_8 ( V_70 ) ;
}
struct V_69 * F_29 ( unsigned int V_76 ,
const struct V_77 * * V_78 )
{
T_2 V_27 ;
short V_79 = 0 ;
T_1 V_80 = 0 ;
struct V_69 * V_81 = NULL ;
const struct V_62 * * V_63 ;
int V_13 ;
int V_30 = 0 ;
V_79 = F_30 ( V_76 , V_78 ) ;
if ( V_79 >= 0 )
V_80 = V_79 + 1 ;
V_81 = F_11 ( sizeof( * V_81 ) +
V_80 * sizeof( * V_81 -> V_73 ) ,
V_34 ) ;
if ( ! V_81 )
return F_12 ( - V_35 ) ;
V_81 -> V_22 = V_80 ;
V_63 = F_13 ( V_76 , sizeof( * V_63 ) ,
V_34 ) ;
if ( ! V_63 ) {
V_30 = - V_35 ;
goto V_82;
}
for ( V_27 = 0 ; V_27 < V_81 -> V_22 ; V_27 ++ ) {
short V_8 = V_18 ;
short V_83 ;
struct V_71 * V_38 = NULL ;
V_83 = F_31 ( V_76 , V_78 ,
V_27 ) ;
if ( V_83 < 0 )
continue;
V_38 = F_11 ( sizeof( * V_38 ) +
sizeof( * V_38 -> V_75 ) * ( V_83 + 1 ) ,
V_34 ) ;
if ( ! V_38 ) {
V_30 = - V_35 ;
goto free;
}
V_38 -> V_74 = V_83 + 1 ;
V_81 -> V_73 [ V_27 ] = V_38 ;
do {
T_1 V_64 ;
struct V_56 * V_57 ;
V_64 = F_32 ( V_63 ,
V_76 ,
V_78 ,
V_27 ,
& V_8 ) ;
if ( ! V_64 )
break;
V_57 = F_22 ( V_63 ,
V_64 ) ;
if ( F_26 ( V_57 ) ) {
V_30 = F_27 ( V_57 ) ;
goto free;
}
for ( V_13 = V_64 - 1 ;
V_13 >= 0 && ! V_63 [ V_13 ] -> V_84 ; V_13 -- )
;
V_57 -> V_84 = V_13 < 0 ? NULL :
V_63 [ V_13 ] -> V_84 ;
V_38 -> V_75 [ V_8 ++ ] = V_57 ;
} while ( 1 );
}
F_8 ( V_63 ) ;
return V_81 ;
free:
F_8 ( V_63 ) ;
V_82:
F_28 ( V_81 ) ;
return F_12 ( V_30 ) ;
}
