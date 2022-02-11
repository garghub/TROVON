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
} else if ( F_17 ( V_3 ) || F_18 ( V_3 ) ) {
V_37 = V_43 ;
} else if ( F_2 ( V_3 ) ) {
V_37 = V_44 ;
} else if ( F_4 ( V_3 ) ) {
V_37 = V_45 ;
} else {
F_19 ( F_5 ( V_3 ) ) ;
V_37 = 0 ;
}
if ( V_15 -> V_40 != V_37 ) {
F_20 ( L_4
L_5 V_46 L_6 ,
F_21 ( V_15 -> V_40 ) ,
F_22 ( V_15 -> V_40 ) ,
F_21 ( V_37 ) ,
F_22 ( V_37 ) ) ;
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
for ( V_17 = 0 ; V_17 < V_29 -> V_47 ; V_17 ++ ) {
if ( V_29 -> V_48 [ V_17 ] . V_49 == '*' &&
V_4 -> V_50 == V_29 -> V_48 [ V_17 ] . V_50 ) {
V_33 = V_29 -> V_48 [ V_17 ] . V_51 ;
break;
} else if ( V_4 -> V_50 == V_29 -> V_48 [ V_17 ] . V_50 &&
V_4 -> V_49 == V_29 -> V_48 [ V_17 ] . V_49 ) {
V_33 = V_29 -> V_48 [ V_17 ] . V_51 ;
break;
} else if ( V_29 -> V_48 [ V_17 ] . V_50 == '*' &&
V_29 -> V_48 [ V_17 ] . V_49 == '*' )
V_33 = V_29 -> V_48 [ V_17 ] . V_51 ;
}
if ( V_33 == V_34 ) {
F_12 ( L_8 ,
V_4 -> V_50 ) ;
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
if ( V_31 -> V_21 [ V_17 ] < V_52 ||
V_31 -> V_21 [ V_17 ] > V_53 ) {
F_12 ( L_11 ,
V_31 -> V_21 [ V_17 ] ) ;
return NULL ;
}
V_15 -> V_21 [ V_17 ] = F_23 ( V_31 -> V_21 [ V_17 ] ) ;
V_15 -> V_22 [ V_17 ] = V_31 -> V_22 [ V_17 ] ;
}
V_36 = V_31 -> V_18 * 4 ;
if ( V_36 > V_54 ) {
F_12 ( L_12 , V_36 ) ;
return NULL ;
}
V_15 -> V_19 = V_31 -> V_18 ;
V_16 = F_24 ( V_36 , V_55 ) ;
if ( ! V_16 ) {
F_12 ( L_13 ) ;
return NULL ;
}
return memcpy ( V_16 , & V_25 -> V_38 [ V_35 ] , V_36 ) ;
}
static void F_25 ( struct V_56 * V_57 )
{
struct V_2 * V_3 ;
struct V_32 * V_15 ;
const struct V_24 * V_25 = NULL ;
V_3 = F_26 ( V_57 , F_27 ( * V_3 ) , V_15 . V_57 ) ;
V_15 = & V_3 -> V_15 ;
F_28 ( & V_25 , V_3 -> V_15 . V_58 , & V_3 -> V_59 . V_60 -> V_61 ) ;
if ( V_25 )
V_3 -> V_15 . V_16 = F_14 ( V_3 , V_25 ) ;
if ( V_3 -> V_15 . V_16 ) {
F_10 ( V_3 ) ;
F_29 ( V_3 , V_62 ) ;
F_20 ( L_14 ,
V_3 -> V_15 . V_58 ,
F_21 ( V_15 -> V_40 ) ,
F_22 ( V_15 -> V_40 ) ) ;
} else {
F_30 ( V_3 -> V_59 . V_61 ,
L_15
L_16 V_46 L_17
L_18 ) ;
}
F_31 ( V_25 ) ;
}
void F_32 ( struct V_2 * V_3 )
{
struct V_32 * V_15 = & V_3 -> V_15 ;
F_33 ( & V_3 -> V_15 . V_57 , F_25 ) ;
if ( ! F_11 ( V_3 ) )
return;
if ( F_15 ( V_3 ) )
V_15 -> V_58 = V_63 ;
else if ( F_16 ( V_3 ) )
V_15 -> V_58 = V_64 ;
else if ( F_17 ( V_3 ) || F_18 ( V_3 ) )
V_15 -> V_58 = V_65 ;
else if ( F_2 ( V_3 ) )
V_15 -> V_58 = V_66 ;
else if ( F_4 ( V_3 ) )
V_15 -> V_58 = V_67 ;
else {
F_12 ( L_19 ) ;
return;
}
F_34 ( L_20 , V_15 -> V_58 ) ;
F_35 ( V_3 , V_62 ) ;
F_36 ( & V_3 -> V_15 . V_57 ) ;
}
void F_37 ( struct V_2 * V_3 )
{
if ( ! F_11 ( V_3 ) )
return;
F_38 ( & V_3 -> V_15 . V_57 ) ;
if ( ! V_3 -> V_15 . V_16 )
F_29 ( V_3 , V_62 ) ;
}
void F_39 ( struct V_2 * V_3 )
{
if ( ! F_11 ( V_3 ) )
return;
if ( ! V_3 -> V_15 . V_16 )
F_35 ( V_3 , V_62 ) ;
}
void F_40 ( struct V_2 * V_3 )
{
if ( ! F_11 ( V_3 ) )
return;
F_37 ( V_3 ) ;
F_41 ( V_3 -> V_15 . V_16 ) ;
}
