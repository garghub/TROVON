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
} else if ( F_5 ( V_3 ) ) {
V_5 = F_3 ( V_8 ) ;
V_4 = V_8 ;
} else {
V_5 = 0 ;
}
if ( F_6 ( V_3 ) < V_5 )
return V_4 + F_6 ( V_3 ) ;
return & V_9 ;
}
static void F_7 ( struct V_2 * V_3 )
{
T_1 V_10 , V_11 ;
V_11 = V_12 ;
if ( F_5 ( V_3 ) )
V_11 |= V_13 ;
V_10 = F_8 ( V_14 ) ;
if ( ( V_10 & V_11 ) != V_11 ) {
V_10 |= V_11 ;
F_9 ( V_14 , V_10 ) ;
F_10 ( V_14 ) ;
}
}
void F_11 ( struct V_2 * V_3 )
{
T_2 * V_15 = V_3 -> V_16 . V_17 ;
T_1 V_18 , V_19 ;
if ( ! F_12 ( V_3 ) ) {
F_13 ( L_1 ) ;
return;
}
if ( ! V_3 -> V_16 . V_17 ) {
F_13 ( L_2 ) ;
return;
}
V_19 = V_3 -> V_16 . V_20 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_9 ( F_14 ( V_18 ) , V_15 [ V_18 ] ) ;
for ( V_18 = 0 ; V_18 < V_3 -> V_16 . V_21 ; V_18 ++ ) {
F_9 ( V_3 -> V_16 . V_22 [ V_18 ] ,
V_3 -> V_16 . V_23 [ V_18 ] ) ;
}
V_3 -> V_16 . V_24 = 0 ;
F_7 ( V_3 ) ;
}
static T_1 * F_15 ( struct V_2 * V_3 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_16 = & V_3 -> V_16 ;
const struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_34 = V_35 , V_36 = 0 , V_37 ;
T_1 V_18 ;
T_1 * V_17 ;
T_1 V_38 ;
if ( ! V_26 )
return NULL ;
V_28 = (struct V_27 * ) V_26 -> V_39 ;
if ( sizeof( struct V_27 ) !=
( V_28 -> V_40 * 4 ) ) {
F_13 ( L_3 ,
( V_28 -> V_40 * 4 ) ) ;
return NULL ;
}
V_16 -> V_41 = V_28 -> V_41 ;
if ( F_2 ( V_3 ) ) {
V_38 = V_42 ;
} else if ( F_4 ( V_3 ) ) {
V_38 = V_43 ;
} else if ( F_5 ( V_3 ) ) {
V_38 = V_44 ;
} else {
F_16 ( F_6 ( V_3 ) ) ;
V_38 = 0 ;
}
if ( V_16 -> V_41 != V_38 ) {
F_17 ( L_4
L_5 V_45 L_6 ,
F_18 ( V_16 -> V_41 ) ,
F_19 ( V_16 -> V_41 ) ,
F_18 ( V_38 ) ,
F_19 ( V_38 ) ) ;
return NULL ;
}
V_36 += sizeof( struct V_27 ) ;
V_30 = (struct V_29 * )
& V_26 -> V_39 [ V_36 ] ;
if ( sizeof( struct V_29 ) !=
( V_30 -> V_40 * 4 ) ) {
F_13 ( L_7 ,
( V_30 -> V_40 * 4 ) ) ;
return NULL ;
}
V_36 += sizeof( struct V_29 ) ;
for ( V_18 = 0 ; V_18 < V_30 -> V_46 ; V_18 ++ ) {
if ( V_30 -> V_47 [ V_18 ] . V_48 == '*' &&
V_4 -> V_49 == V_30 -> V_47 [ V_18 ] . V_49 ) {
V_34 = V_30 -> V_47 [ V_18 ] . V_50 ;
break;
} else if ( V_4 -> V_49 == V_30 -> V_47 [ V_18 ] . V_49 &&
V_4 -> V_48 == V_30 -> V_47 [ V_18 ] . V_48 ) {
V_34 = V_30 -> V_47 [ V_18 ] . V_50 ;
break;
} else if ( V_30 -> V_47 [ V_18 ] . V_49 == '*' &&
V_30 -> V_47 [ V_18 ] . V_48 == '*' )
V_34 = V_30 -> V_47 [ V_18 ] . V_50 ;
}
if ( V_34 == V_35 ) {
F_13 ( L_8 ,
V_4 -> V_49 ) ;
return NULL ;
}
V_36 += V_34 ;
V_32 = (struct V_31 * ) & V_26 -> V_39 [ V_36 ] ;
if ( sizeof( struct V_31 ) != ( V_32 -> V_40 ) ) {
F_13 ( L_9 ,
( V_32 -> V_40 ) ) ;
return NULL ;
}
V_36 += sizeof( struct V_31 ) ;
if ( V_32 -> V_21 > F_3 ( V_16 -> V_22 ) ) {
F_13 ( L_10 ,
V_32 -> V_21 ) ;
return NULL ;
}
V_16 -> V_21 = V_32 -> V_21 ;
for ( V_18 = 0 ; V_18 < V_32 -> V_21 ; V_18 ++ ) {
if ( V_32 -> V_22 [ V_18 ] < V_51 ||
V_32 -> V_22 [ V_18 ] > V_52 ) {
F_13 ( L_11 ,
V_32 -> V_22 [ V_18 ] ) ;
return NULL ;
}
V_16 -> V_22 [ V_18 ] = F_20 ( V_32 -> V_22 [ V_18 ] ) ;
V_16 -> V_23 [ V_18 ] = V_32 -> V_23 [ V_18 ] ;
}
V_37 = V_32 -> V_19 * 4 ;
if ( V_37 > V_53 ) {
F_13 ( L_12 , V_37 ) ;
return NULL ;
}
V_16 -> V_20 = V_32 -> V_19 ;
V_17 = F_21 ( V_37 , V_54 ) ;
if ( ! V_17 ) {
F_13 ( L_13 ) ;
return NULL ;
}
return memcpy ( V_17 , & V_26 -> V_39 [ V_36 ] , V_37 ) ;
}
static void F_22 ( struct V_55 * V_56 )
{
struct V_2 * V_3 ;
struct V_33 * V_16 ;
const struct V_25 * V_26 ;
int V_57 ;
V_3 = F_23 ( V_56 , F_24 ( * V_3 ) , V_16 . V_56 ) ;
V_16 = & V_3 -> V_16 ;
V_57 = F_25 ( & V_26 , V_3 -> V_16 . V_58 ,
& V_3 -> V_59 . V_60 -> V_61 ) ;
if ( V_26 )
V_3 -> V_16 . V_17 = F_15 ( V_3 , V_26 ) ;
if ( V_3 -> V_16 . V_17 ) {
F_11 ( V_3 ) ;
F_26 ( V_3 , V_62 ) ;
F_17 ( L_14 ,
V_3 -> V_16 . V_58 ,
F_18 ( V_16 -> V_41 ) ,
F_19 ( V_16 -> V_41 ) ) ;
} else {
F_27 ( V_3 -> V_59 . V_61 ,
L_15
L_16 V_45 L_17
L_18 ) ;
}
F_28 ( V_26 ) ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_33 * V_16 = & V_3 -> V_16 ;
F_30 ( & V_3 -> V_16 . V_56 , F_22 ) ;
if ( ! F_31 ( V_3 ) )
return;
if ( F_2 ( V_3 ) )
V_16 -> V_58 = V_63 ;
else if ( F_4 ( V_3 ) )
V_16 -> V_58 = V_64 ;
else if ( F_5 ( V_3 ) )
V_16 -> V_58 = V_65 ;
else {
F_13 ( L_19 ) ;
return;
}
F_32 ( L_20 , V_16 -> V_58 ) ;
F_33 ( V_3 , V_62 ) ;
F_34 ( & V_3 -> V_16 . V_56 ) ;
}
void F_35 ( struct V_2 * V_3 )
{
if ( ! F_31 ( V_3 ) )
return;
F_36 ( & V_3 -> V_16 . V_56 ) ;
if ( ! V_3 -> V_16 . V_17 )
F_26 ( V_3 , V_62 ) ;
}
void F_37 ( struct V_2 * V_3 )
{
if ( ! F_31 ( V_3 ) )
return;
if ( ! V_3 -> V_16 . V_17 )
F_33 ( V_3 , V_62 ) ;
}
void F_38 ( struct V_2 * V_3 )
{
if ( ! F_31 ( V_3 ) )
return;
F_35 ( V_3 ) ;
F_39 ( V_3 -> V_16 . V_17 ) ;
}
