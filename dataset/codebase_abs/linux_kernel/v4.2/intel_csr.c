static char F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) && ( V_2 -> V_3 -> V_4 <
F_3 ( V_5 ) ) )
return V_5 [ V_2 -> V_3 -> V_4 ] . V_6 ;
else
return - V_7 ;
}
static char F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) && ( V_2 -> V_3 -> V_4 <
F_3 ( V_5 ) ) )
return V_5 [ V_2 -> V_3 -> V_4 ] . V_8 ;
else
return - V_7 ;
}
enum V_9 F_5 ( struct V_10 * V_11 )
{
enum V_9 V_12 ;
F_6 ( & V_11 -> V_13 ) ;
V_12 = V_11 -> V_14 . V_12 ;
F_7 ( & V_11 -> V_13 ) ;
return V_12 ;
}
void F_8 ( struct V_10 * V_11 ,
enum V_9 V_12 )
{
F_6 ( & V_11 -> V_13 ) ;
V_11 -> V_14 . V_12 = V_12 ;
F_7 ( & V_11 -> V_13 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
T_1 * V_16 = V_11 -> V_14 . V_17 ;
T_2 V_18 , V_19 ;
if ( ! F_10 ( V_2 ) ) {
F_11 ( L_1 ) ;
return;
}
F_6 ( & V_11 -> V_13 ) ;
V_19 = V_11 -> V_14 . V_20 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_12 ( V_21 + V_18 * 4 ,
( V_22 V_23 ) V_16 [ V_18 ] ) ;
for ( V_18 = 0 ; V_18 < V_11 -> V_14 . V_24 ; V_18 ++ ) {
F_12 ( V_11 -> V_14 . V_25 [ V_18 ] ,
V_11 -> V_14 . V_26 [ V_18 ] ) ;
}
V_11 -> V_14 . V_12 = V_27 ;
F_7 ( & V_11 -> V_13 ) ;
}
static void F_13 ( const struct V_28 * V_29 , void * V_30 )
{
struct V_10 * V_11 = V_30 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_14 = & V_11 -> V_14 ;
char V_6 = F_1 ( V_2 ) ;
char V_8 = F_4 ( V_2 ) ;
T_2 V_38 = V_39 , V_40 = 0 , V_41 ;
T_2 V_18 ;
T_1 * V_17 ;
bool V_42 = false ;
if ( ! V_29 ) {
F_14 ( V_14 -> V_43 , 0 ) ;
goto V_44;
}
if ( ( V_6 == - V_7 ) || ( V_8 == - V_7 ) ) {
F_11 ( L_2 ) ;
goto V_44;
}
V_32 = (struct V_31 * ) V_29 -> V_45 ;
if ( sizeof( struct V_31 ) !=
( V_32 -> V_46 * 4 ) ) {
F_11 ( L_3 ,
( V_32 -> V_46 * 4 ) ) ;
goto V_44;
}
V_40 += sizeof( struct V_31 ) ;
V_34 = (struct V_33 * )
& V_29 -> V_45 [ V_40 ] ;
if ( sizeof( struct V_33 ) !=
( V_34 -> V_46 * 4 ) ) {
F_11 ( L_4 ,
( V_34 -> V_46 * 4 ) ) ;
goto V_44;
}
V_40 += sizeof( struct V_33 ) ;
for ( V_18 = 0 ; V_18 < V_34 -> V_47 ; V_18 ++ ) {
if ( V_34 -> V_48 [ V_18 ] . V_8 == '*' &&
V_6 == V_34 -> V_48 [ V_18 ] . V_6 ) {
V_38 = V_34 -> V_48 [ V_18 ] . V_49 ;
break;
} else if ( V_6 == V_34 -> V_48 [ V_18 ] . V_6 &&
V_8 == V_34 -> V_48 [ V_18 ] . V_8 ) {
V_38 = V_34 -> V_48 [ V_18 ] . V_49 ;
break;
} else if ( V_34 -> V_48 [ V_18 ] . V_6 == '*' &&
V_34 -> V_48 [ V_18 ] . V_8 == '*' )
V_38 = V_34 -> V_48 [ V_18 ] . V_49 ;
}
if ( V_38 == V_39 ) {
F_11 ( L_5 , V_6 ) ;
goto V_44;
}
V_40 += V_38 ;
V_36 = (struct V_35 * ) & V_29 -> V_45 [ V_40 ] ;
if ( sizeof( struct V_35 ) != ( V_36 -> V_46 ) ) {
F_11 ( L_6 ,
( V_36 -> V_46 ) ) ;
goto V_44;
}
V_40 += sizeof( struct V_35 ) ;
if ( V_36 -> V_24 > F_3 ( V_14 -> V_25 ) ) {
F_11 ( L_7 ,
V_36 -> V_24 ) ;
goto V_44;
}
V_14 -> V_24 = V_36 -> V_24 ;
for ( V_18 = 0 ; V_18 < V_36 -> V_24 ; V_18 ++ ) {
if ( V_36 -> V_25 [ V_18 ] < V_50 &&
V_36 -> V_25 [ V_18 ] > V_51 ) {
F_11 ( L_8 ,
V_36 -> V_25 [ V_18 ] ) ;
goto V_44;
}
V_14 -> V_25 [ V_18 ] = V_36 -> V_25 [ V_18 ] ;
V_14 -> V_26 [ V_18 ] = V_36 -> V_26 [ V_18 ] ;
}
V_41 = V_36 -> V_19 * 4 ;
if ( V_41 > V_52 ) {
F_11 ( L_9 , V_41 ) ;
goto V_44;
}
V_14 -> V_20 = V_36 -> V_19 ;
V_14 -> V_17 = F_15 ( V_41 , V_53 ) ;
if ( ! V_14 -> V_17 ) {
F_11 ( L_10 ) ;
goto V_44;
}
V_17 = V_14 -> V_17 ;
for ( V_18 = 0 ; V_18 < V_36 -> V_19 ; V_18 ++ ) {
T_2 * V_54 = ( V_22 * ) & V_29 -> V_45 [ V_40 + V_18 * 4 ] ;
V_17 [ V_18 ] = F_16 ( * V_54 ) ;
}
F_9 ( V_2 ) ;
V_42 = true ;
V_44:
if ( V_42 )
F_17 ( V_11 ) ;
else
F_8 ( V_11 , V_55 ) ;
F_18 ( V_29 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_37 * V_14 = & V_11 -> V_14 ;
int V_56 ;
if ( ! F_20 ( V_2 ) )
return;
if ( F_2 ( V_2 ) )
V_14 -> V_43 = V_57 ;
else {
F_11 ( L_11 ) ;
F_8 ( V_11 , V_55 ) ;
return;
}
F_21 ( V_11 ) ;
V_56 = F_22 ( V_58 , true , V_14 -> V_43 ,
& V_11 -> V_2 -> V_3 -> V_2 ,
V_53 , V_11 ,
F_13 ) ;
if ( V_56 ) {
F_14 ( V_14 -> V_43 , V_56 ) ;
F_8 ( V_11 , V_55 ) ;
}
}
void F_23 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
if ( ! F_20 ( V_2 ) )
return;
F_8 ( V_11 , V_55 ) ;
F_24 ( V_11 -> V_14 . V_17 ) ;
}
void F_25 ( struct V_10 * V_11 )
{
F_26 ( ( F_5 ( V_11 ) != V_27 ) , L_12 ) ;
F_26 ( ! F_27 ( V_21 ) ,
L_13 ) ;
F_26 ( ! F_27 ( V_59 ) , L_14 ) ;
F_26 ( ! F_27 ( V_60 ) , L_15 ) ;
}
