static const struct V_1 *
F_1 ( struct V_2 * V_3 )
{
const struct V_1 * V_4 ;
unsigned int V_5 ;
if ( F_2 ( V_3 ) ) {
V_5 = F_3 ( V_6 ) ;
V_4 = V_6 ;
} else if ( F_4 ( V_3 ) ) {
V_5 = F_3 ( V_7 ) ;
V_4 = V_7 ;
} else {
V_5 = 0 ;
}
if ( F_5 ( V_3 ) < V_5 )
return V_4 + F_5 ( V_3 ) ;
return & V_8 ;
}
static void F_6 ( struct V_2 * V_3 )
{
T_1 V_9 , V_10 ;
V_10 = V_11 ;
if ( F_4 ( V_3 ) )
V_10 |= V_12 ;
V_9 = F_7 ( V_13 ) ;
if ( ( V_9 & V_10 ) != V_10 ) {
V_9 |= V_10 ;
F_8 ( V_13 , V_9 ) ;
F_9 ( V_13 ) ;
}
}
void F_10 ( struct V_2 * V_3 )
{
T_2 * V_14 = V_3 -> V_15 . V_16 ;
T_1 V_17 , V_18 ;
if ( ! F_11 ( V_3 ) ) {
F_12 ( L_1 ) ;
return;
}
if ( ! V_3 -> V_15 . V_16 ) {
F_12 ( L_2 ) ;
return;
}
V_18 = V_3 -> V_15 . V_19 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_8 ( F_13 ( V_17 ) , V_14 [ V_17 ] ) ;
for ( V_17 = 0 ; V_17 < V_3 -> V_15 . V_20 ; V_17 ++ ) {
F_8 ( V_3 -> V_15 . V_21 [ V_17 ] ,
V_3 -> V_15 . V_22 [ V_17 ] ) ;
}
V_3 -> V_15 . V_23 = 0 ;
F_6 ( V_3 ) ;
}
static T_1 * F_14 ( struct V_2 * V_3 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_15 = & V_3 -> V_15 ;
const struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_33 = V_34 , V_35 = 0 , V_36 ;
T_1 V_17 ;
T_1 * V_16 ;
T_1 V_37 ;
if ( ! V_25 )
return NULL ;
V_27 = (struct V_26 * ) V_25 -> V_38 ;
if ( sizeof( struct V_26 ) !=
( V_27 -> V_39 * 4 ) ) {
F_12 ( L_3 ,
( V_27 -> V_39 * 4 ) ) ;
return NULL ;
}
V_15 -> V_40 = V_27 -> V_40 ;
if ( F_15 ( V_3 ) ) {
V_37 = V_41 ;
} else if ( F_16 ( V_3 ) ) {
V_37 = V_42 ;
} else if ( F_2 ( V_3 ) ) {
V_37 = V_43 ;
} else if ( F_4 ( V_3 ) ) {
V_37 = V_44 ;
} else {
F_17 ( F_5 ( V_3 ) ) ;
V_37 = 0 ;
}
if ( V_15 -> V_40 != V_37 ) {
F_18 ( L_4
L_5 V_45 L_6 ,
F_19 ( V_15 -> V_40 ) ,
F_20 ( V_15 -> V_40 ) ,
F_19 ( V_37 ) ,
F_20 ( V_37 ) ) ;
return NULL ;
}
V_35 += sizeof( struct V_26 ) ;
V_29 = (struct V_28 * )
& V_25 -> V_38 [ V_35 ] ;
if ( sizeof( struct V_28 ) !=
( V_29 -> V_39 * 4 ) ) {
F_12 ( L_7 ,
( V_29 -> V_39 * 4 ) ) ;
return NULL ;
}
V_35 += sizeof( struct V_28 ) ;
for ( V_17 = 0 ; V_17 < V_29 -> V_46 ; V_17 ++ ) {
if ( V_29 -> V_47 [ V_17 ] . V_48 == '*' &&
V_4 -> V_49 == V_29 -> V_47 [ V_17 ] . V_49 ) {
V_33 = V_29 -> V_47 [ V_17 ] . V_50 ;
break;
} else if ( V_4 -> V_49 == V_29 -> V_47 [ V_17 ] . V_49 &&
V_4 -> V_48 == V_29 -> V_47 [ V_17 ] . V_48 ) {
V_33 = V_29 -> V_47 [ V_17 ] . V_50 ;
break;
} else if ( V_29 -> V_47 [ V_17 ] . V_49 == '*' &&
V_29 -> V_47 [ V_17 ] . V_48 == '*' )
V_33 = V_29 -> V_47 [ V_17 ] . V_50 ;
}
if ( V_33 == V_34 ) {
F_12 ( L_8 ,
V_4 -> V_49 ) ;
return NULL ;
}
V_35 += V_33 ;
V_31 = (struct V_30 * ) & V_25 -> V_38 [ V_35 ] ;
if ( sizeof( struct V_30 ) != ( V_31 -> V_39 ) ) {
F_12 ( L_9 ,
( V_31 -> V_39 ) ) ;
return NULL ;
}
V_35 += sizeof( struct V_30 ) ;
if ( V_31 -> V_20 > F_3 ( V_15 -> V_21 ) ) {
F_12 ( L_10 ,
V_31 -> V_20 ) ;
return NULL ;
}
V_15 -> V_20 = V_31 -> V_20 ;
for ( V_17 = 0 ; V_17 < V_31 -> V_20 ; V_17 ++ ) {
if ( V_31 -> V_21 [ V_17 ] < V_51 ||
V_31 -> V_21 [ V_17 ] > V_52 ) {
F_12 ( L_11 ,
V_31 -> V_21 [ V_17 ] ) ;
return NULL ;
}
V_15 -> V_21 [ V_17 ] = F_21 ( V_31 -> V_21 [ V_17 ] ) ;
V_15 -> V_22 [ V_17 ] = V_31 -> V_22 [ V_17 ] ;
}
V_36 = V_31 -> V_18 * 4 ;
if ( V_36 > V_53 ) {
F_12 ( L_12 , V_36 ) ;
return NULL ;
}
V_15 -> V_19 = V_31 -> V_18 ;
V_16 = F_22 ( V_36 , V_54 ) ;
if ( ! V_16 ) {
F_12 ( L_13 ) ;
return NULL ;
}
return memcpy ( V_16 , & V_25 -> V_38 [ V_35 ] , V_36 ) ;
}
static void F_23 ( struct V_55 * V_56 )
{
struct V_2 * V_3 ;
struct V_32 * V_15 ;
const struct V_24 * V_25 = NULL ;
V_3 = F_24 ( V_56 , F_25 ( * V_3 ) , V_15 . V_56 ) ;
V_15 = & V_3 -> V_15 ;
F_26 ( & V_25 , V_3 -> V_15 . V_57 , & V_3 -> V_58 . V_59 -> V_60 ) ;
if ( V_25 )
V_3 -> V_15 . V_16 = F_14 ( V_3 , V_25 ) ;
if ( V_3 -> V_15 . V_16 ) {
F_10 ( V_3 ) ;
F_27 ( V_3 , V_61 ) ;
F_18 ( L_14 ,
V_3 -> V_15 . V_57 ,
F_19 ( V_15 -> V_40 ) ,
F_20 ( V_15 -> V_40 ) ) ;
} else {
F_28 ( V_3 -> V_58 . V_60 ,
L_15
L_16 V_45 L_17
L_18 ) ;
}
F_29 ( V_25 ) ;
}
void F_30 ( struct V_2 * V_3 )
{
struct V_32 * V_15 = & V_3 -> V_15 ;
F_31 ( & V_3 -> V_15 . V_56 , F_23 ) ;
if ( ! F_32 ( V_3 ) )
return;
if ( F_15 ( V_3 ) )
V_15 -> V_57 = V_62 ;
else if ( F_16 ( V_3 ) )
V_15 -> V_57 = V_63 ;
else if ( F_2 ( V_3 ) )
V_15 -> V_57 = V_64 ;
else if ( F_4 ( V_3 ) )
V_15 -> V_57 = V_65 ;
else {
F_12 ( L_19 ) ;
return;
}
F_33 ( L_20 , V_15 -> V_57 ) ;
F_34 ( V_3 , V_61 ) ;
F_35 ( & V_3 -> V_15 . V_56 ) ;
}
void F_36 ( struct V_2 * V_3 )
{
if ( ! F_32 ( V_3 ) )
return;
F_37 ( & V_3 -> V_15 . V_56 ) ;
if ( ! V_3 -> V_15 . V_16 )
F_27 ( V_3 , V_61 ) ;
}
void F_38 ( struct V_2 * V_3 )
{
if ( ! F_32 ( V_3 ) )
return;
if ( ! V_3 -> V_15 . V_16 )
F_34 ( V_3 , V_61 ) ;
}
void F_39 ( struct V_2 * V_3 )
{
if ( ! F_32 ( V_3 ) )
return;
F_36 ( V_3 ) ;
F_40 ( V_3 -> V_15 . V_16 ) ;
}
