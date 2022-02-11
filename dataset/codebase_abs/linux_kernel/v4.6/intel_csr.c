static const struct V_1 * F_1 ( struct V_2 * V_3 )
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
return NULL ;
}
if ( F_6 ( V_3 ) < V_5 )
return V_4 + F_6 ( V_3 ) ;
return NULL ;
}
bool F_7 ( struct V_9 * V_10 )
{
T_1 * V_11 = V_10 -> V_12 . V_13 ;
T_2 V_14 , V_15 ;
if ( ! F_8 ( V_10 ) ) {
F_9 ( L_1 ) ;
return false ;
}
if ( ! V_10 -> V_12 . V_13 ) {
F_9 ( L_2 ) ;
return false ;
}
V_15 = V_10 -> V_12 . V_16 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_10 ( F_11 ( V_14 ) , V_11 [ V_14 ] ) ;
for ( V_14 = 0 ; V_14 < V_10 -> V_12 . V_17 ; V_14 ++ ) {
F_10 ( V_10 -> V_12 . V_18 [ V_14 ] ,
V_10 -> V_12 . V_19 [ V_14 ] ) ;
}
V_10 -> V_12 . V_20 = 0 ;
return true ;
}
static T_2 * F_12 ( struct V_9 * V_10 ,
const struct V_21 * V_22 )
{
struct V_2 * V_3 = V_10 -> V_3 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_12 = & V_10 -> V_12 ;
const struct V_1 * V_1 = F_1 ( V_3 ) ;
char V_30 , V_31 ;
T_2 V_32 = V_33 , V_34 = 0 , V_35 ;
T_2 V_14 ;
T_2 * V_13 ;
if ( ! V_22 )
return NULL ;
if ( ! V_1 ) {
F_9 ( L_3 ) ;
return NULL ;
}
V_30 = V_1 -> V_30 ;
V_31 = V_1 -> V_31 ;
V_24 = (struct V_23 * ) V_22 -> V_36 ;
if ( sizeof( struct V_23 ) !=
( V_24 -> V_37 * 4 ) ) {
F_9 ( L_4 ,
( V_24 -> V_37 * 4 ) ) ;
return NULL ;
}
V_12 -> V_38 = V_24 -> V_38 ;
if ( ( F_4 ( V_3 ) || F_2 ( V_3 ) ) &&
V_12 -> V_38 < V_39 ) {
F_13 ( L_5
L_6
L_7 V_40 L_8 ,
F_14 ( V_12 -> V_38 ) ,
F_15 ( V_12 -> V_38 ) ,
F_14 ( V_39 ) ,
F_15 ( V_39 ) ) ;
return NULL ;
}
V_34 += sizeof( struct V_23 ) ;
V_26 = (struct V_25 * )
& V_22 -> V_36 [ V_34 ] ;
if ( sizeof( struct V_25 ) !=
( V_26 -> V_37 * 4 ) ) {
F_9 ( L_9 ,
( V_26 -> V_37 * 4 ) ) ;
return NULL ;
}
V_34 += sizeof( struct V_25 ) ;
for ( V_14 = 0 ; V_14 < V_26 -> V_41 ; V_14 ++ ) {
if ( V_26 -> V_42 [ V_14 ] . V_31 == '*' &&
V_30 == V_26 -> V_42 [ V_14 ] . V_30 ) {
V_32 = V_26 -> V_42 [ V_14 ] . V_43 ;
break;
} else if ( V_30 == V_26 -> V_42 [ V_14 ] . V_30 &&
V_31 == V_26 -> V_42 [ V_14 ] . V_31 ) {
V_32 = V_26 -> V_42 [ V_14 ] . V_43 ;
break;
} else if ( V_26 -> V_42 [ V_14 ] . V_30 == '*' &&
V_26 -> V_42 [ V_14 ] . V_31 == '*' )
V_32 = V_26 -> V_42 [ V_14 ] . V_43 ;
}
if ( V_32 == V_33 ) {
F_9 ( L_10 , V_30 ) ;
return NULL ;
}
V_34 += V_32 ;
V_28 = (struct V_27 * ) & V_22 -> V_36 [ V_34 ] ;
if ( sizeof( struct V_27 ) != ( V_28 -> V_37 ) ) {
F_9 ( L_11 ,
( V_28 -> V_37 ) ) ;
return NULL ;
}
V_34 += sizeof( struct V_27 ) ;
if ( V_28 -> V_17 > F_3 ( V_12 -> V_18 ) ) {
F_9 ( L_12 ,
V_28 -> V_17 ) ;
return NULL ;
}
V_12 -> V_17 = V_28 -> V_17 ;
for ( V_14 = 0 ; V_14 < V_28 -> V_17 ; V_14 ++ ) {
if ( V_28 -> V_18 [ V_14 ] < V_44 ||
V_28 -> V_18 [ V_14 ] > V_45 ) {
F_9 ( L_13 ,
V_28 -> V_18 [ V_14 ] ) ;
return NULL ;
}
V_12 -> V_18 [ V_14 ] = F_16 ( V_28 -> V_18 [ V_14 ] ) ;
V_12 -> V_19 [ V_14 ] = V_28 -> V_19 [ V_14 ] ;
}
V_35 = V_28 -> V_15 * 4 ;
if ( V_35 > V_46 ) {
F_9 ( L_14 , V_35 ) ;
return NULL ;
}
V_12 -> V_16 = V_28 -> V_15 ;
V_13 = F_17 ( V_35 , V_47 ) ;
if ( ! V_13 ) {
F_9 ( L_15 ) ;
return NULL ;
}
memcpy ( V_13 , & V_22 -> V_36 [ V_34 ] , V_35 ) ;
return V_13 ;
}
static void F_18 ( struct V_48 * V_49 )
{
struct V_9 * V_10 ;
struct V_29 * V_12 ;
const struct V_21 * V_22 ;
int V_50 ;
V_10 = F_19 ( V_49 , F_20 ( * V_10 ) , V_12 . V_49 ) ;
V_12 = & V_10 -> V_12 ;
V_50 = F_21 ( & V_22 , V_10 -> V_12 . V_51 ,
& V_10 -> V_3 -> V_52 -> V_3 ) ;
if ( ! V_22 )
goto V_53;
V_10 -> V_12 . V_13 = F_12 ( V_10 , V_22 ) ;
if ( ! V_10 -> V_12 . V_13 )
goto V_53;
F_7 ( V_10 ) ;
V_53:
if ( V_10 -> V_12 . V_13 ) {
F_22 ( V_10 , V_54 ) ;
F_13 ( L_16 ,
V_10 -> V_12 . V_51 ,
F_14 ( V_12 -> V_38 ) ,
F_15 ( V_12 -> V_38 ) ) ;
} else {
F_23 ( V_10 -> V_3 -> V_3 ,
L_17
L_7 V_40 L_18
L_19 ) ;
}
F_24 ( V_22 ) ;
}
void F_25 ( struct V_9 * V_10 )
{
struct V_29 * V_12 = & V_10 -> V_12 ;
F_26 ( & V_10 -> V_12 . V_49 , F_18 ) ;
if ( ! F_27 ( V_10 ) )
return;
if ( F_4 ( V_10 ) || F_2 ( V_10 ) )
V_12 -> V_51 = V_55 ;
else if ( F_5 ( V_10 ) )
V_12 -> V_51 = V_56 ;
else {
F_9 ( L_20 ) ;
return;
}
F_28 ( L_21 , V_12 -> V_51 ) ;
F_29 ( V_10 , V_54 ) ;
F_30 ( & V_10 -> V_12 . V_49 ) ;
}
void F_31 ( struct V_9 * V_10 )
{
if ( ! F_27 ( V_10 ) )
return;
F_32 ( & V_10 -> V_12 . V_49 ) ;
F_33 ( V_10 -> V_12 . V_13 ) ;
}
