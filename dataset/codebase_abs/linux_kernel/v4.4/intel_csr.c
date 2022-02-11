static char F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) && ( V_2 -> V_3 -> V_4 <
F_3 ( V_5 ) ) )
return V_5 [ V_2 -> V_3 -> V_4 ] . V_6 ;
else if ( F_4 ( V_2 ) && ( V_2 -> V_3 -> V_4 <
F_3 ( V_7 ) ) )
return V_7 [ V_2 -> V_3 -> V_4 ] . V_6 ;
else
return - V_8 ;
}
static char F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) && ( V_2 -> V_3 -> V_4 <
F_3 ( V_5 ) ) )
return V_5 [ V_2 -> V_3 -> V_4 ] . V_9 ;
else if ( F_4 ( V_2 ) && ( V_2 -> V_3 -> V_4 <
F_3 ( V_7 ) ) )
return V_7 [ V_2 -> V_3 -> V_4 ] . V_9 ;
else
return - V_8 ;
}
enum V_10 F_6 ( struct V_11 * V_12 )
{
enum V_10 V_13 ;
F_7 ( & V_12 -> V_14 ) ;
V_13 = V_12 -> V_15 . V_13 ;
F_8 ( & V_12 -> V_14 ) ;
return V_13 ;
}
void F_9 ( struct V_11 * V_12 ,
enum V_10 V_13 )
{
F_7 ( & V_12 -> V_14 ) ;
V_12 -> V_15 . V_13 = V_13 ;
F_8 ( & V_12 -> V_14 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_16 ;
T_1 * V_17 = V_12 -> V_15 . V_18 ;
T_2 V_19 , V_20 ;
if ( ! F_11 ( V_2 ) ) {
F_12 ( L_1 ) ;
return;
}
if ( F_13 ( F_14 ( 0 ) ) )
return;
F_7 ( & V_12 -> V_14 ) ;
V_20 = V_12 -> V_15 . V_21 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
F_15 ( F_14 ( V_19 ) , V_17 [ V_19 ] ) ;
for ( V_19 = 0 ; V_19 < V_12 -> V_15 . V_22 ; V_19 ++ ) {
F_15 ( V_12 -> V_15 . V_23 [ V_19 ] ,
V_12 -> V_15 . V_24 [ V_19 ] ) ;
}
V_12 -> V_15 . V_13 = V_25 ;
F_8 ( & V_12 -> V_14 ) ;
}
static void F_16 ( const struct V_26 * V_27 , void * V_28 )
{
struct V_11 * V_12 = V_28 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_15 = & V_12 -> V_15 ;
char V_6 = F_1 ( V_2 ) ;
char V_9 = F_5 ( V_2 ) ;
T_2 V_36 = V_37 , V_38 = 0 , V_39 ;
T_2 V_19 ;
T_2 * V_18 ;
bool V_40 = false ;
if ( ! V_27 ) {
F_17 ( V_15 -> V_41 , 0 ) ;
goto V_42;
}
if ( ( V_6 == - V_8 ) || ( V_9 == - V_8 ) ) {
F_12 ( L_2 ) ;
goto V_42;
}
V_30 = (struct V_29 * ) V_27 -> V_43 ;
if ( sizeof( struct V_29 ) !=
( V_30 -> V_44 * 4 ) ) {
F_12 ( L_3 ,
( V_30 -> V_44 * 4 ) ) ;
goto V_42;
}
V_38 += sizeof( struct V_29 ) ;
V_32 = (struct V_31 * )
& V_27 -> V_43 [ V_38 ] ;
if ( sizeof( struct V_31 ) !=
( V_32 -> V_44 * 4 ) ) {
F_12 ( L_4 ,
( V_32 -> V_44 * 4 ) ) ;
goto V_42;
}
V_38 += sizeof( struct V_31 ) ;
for ( V_19 = 0 ; V_19 < V_32 -> V_45 ; V_19 ++ ) {
if ( V_32 -> V_46 [ V_19 ] . V_9 == '*' &&
V_6 == V_32 -> V_46 [ V_19 ] . V_6 ) {
V_36 = V_32 -> V_46 [ V_19 ] . V_47 ;
break;
} else if ( V_6 == V_32 -> V_46 [ V_19 ] . V_6 &&
V_9 == V_32 -> V_46 [ V_19 ] . V_9 ) {
V_36 = V_32 -> V_46 [ V_19 ] . V_47 ;
break;
} else if ( V_32 -> V_46 [ V_19 ] . V_6 == '*' &&
V_32 -> V_46 [ V_19 ] . V_9 == '*' )
V_36 = V_32 -> V_46 [ V_19 ] . V_47 ;
}
if ( V_36 == V_37 ) {
F_12 ( L_5 , V_6 ) ;
goto V_42;
}
V_38 += V_36 ;
V_34 = (struct V_33 * ) & V_27 -> V_43 [ V_38 ] ;
if ( sizeof( struct V_33 ) != ( V_34 -> V_44 ) ) {
F_12 ( L_6 ,
( V_34 -> V_44 ) ) ;
goto V_42;
}
V_38 += sizeof( struct V_33 ) ;
if ( V_34 -> V_22 > F_3 ( V_15 -> V_23 ) ) {
F_12 ( L_7 ,
V_34 -> V_22 ) ;
goto V_42;
}
V_15 -> V_22 = V_34 -> V_22 ;
for ( V_19 = 0 ; V_19 < V_34 -> V_22 ; V_19 ++ ) {
if ( V_34 -> V_23 [ V_19 ] < V_48 ||
V_34 -> V_23 [ V_19 ] > V_49 ) {
F_12 ( L_8 ,
V_34 -> V_23 [ V_19 ] ) ;
goto V_42;
}
V_15 -> V_23 [ V_19 ] = V_34 -> V_23 [ V_19 ] ;
V_15 -> V_24 [ V_19 ] = V_34 -> V_24 [ V_19 ] ;
}
V_39 = V_34 -> V_20 * 4 ;
if ( V_39 > V_50 ) {
F_12 ( L_9 , V_39 ) ;
goto V_42;
}
V_15 -> V_21 = V_34 -> V_20 ;
V_15 -> V_18 = F_18 ( V_39 , V_51 ) ;
if ( ! V_15 -> V_18 ) {
F_12 ( L_10 ) ;
goto V_42;
}
V_18 = V_15 -> V_18 ;
memcpy ( V_18 , & V_27 -> V_43 [ V_38 ] , V_39 ) ;
F_10 ( V_2 ) ;
V_40 = true ;
F_19 ( L_11 , V_12 -> V_15 . V_41 ) ;
V_42:
if ( V_40 )
F_20 ( V_12 ) ;
else
F_9 ( V_12 , V_52 ) ;
F_21 ( V_27 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_16 ;
struct V_35 * V_15 = & V_12 -> V_15 ;
int V_53 ;
if ( ! F_23 ( V_2 ) )
return;
if ( F_2 ( V_2 ) )
V_15 -> V_41 = V_54 ;
else if ( F_4 ( V_12 ) )
V_15 -> V_41 = V_55 ;
else {
F_12 ( L_12 ) ;
F_9 ( V_12 , V_52 ) ;
return;
}
F_19 ( L_13 , V_15 -> V_41 ) ;
F_24 ( V_12 ) ;
V_53 = F_25 ( V_56 , true , V_15 -> V_41 ,
& V_12 -> V_2 -> V_3 -> V_2 ,
V_51 , V_12 ,
F_16 ) ;
if ( V_53 ) {
F_17 ( V_15 -> V_41 , V_53 ) ;
F_9 ( V_12 , V_52 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_16 ;
if ( ! F_23 ( V_2 ) )
return;
F_9 ( V_12 , V_52 ) ;
F_27 ( V_12 -> V_15 . V_18 ) ;
}
void F_28 ( struct V_11 * V_12 )
{
F_29 ( F_6 ( V_12 ) != V_25 ,
L_14 ) ;
F_29 ( ! F_13 ( F_14 ( 0 ) ) ,
L_15 ) ;
F_29 ( ! F_13 ( V_57 ) , L_16 ) ;
F_29 ( ! F_13 ( V_58 ) , L_17 ) ;
}
