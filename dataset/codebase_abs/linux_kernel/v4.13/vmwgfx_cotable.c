static struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_2 ( struct V_2 * V_3 )
{
V_3 -> V_4 = - 1 ;
return 0 ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_3 -> V_10 -> V_11 ;
struct {
T_1 V_12 ;
T_2 V_13 ;
} * V_14 ;
F_4 ( V_9 -> V_15 . V_16 != V_17 ) ;
F_5 ( & V_9 -> V_18 -> V_19 . V_11 ) ;
V_14 = F_6 ( V_7 , sizeof( * V_14 ) , V_20 ) ;
if ( ! V_14 ) {
F_7 ( L_1
L_2 ) ;
return - V_21 ;
}
F_8 ( V_5 -> V_22 -> V_4 == V_20 ) ;
F_8 ( V_9 -> V_15 . V_16 != V_17 ) ;
V_14 -> V_12 . V_4 = V_23 ;
V_14 -> V_12 . V_24 = sizeof( V_14 -> V_13 ) ;
V_14 -> V_13 . V_25 = V_5 -> V_22 -> V_4 ;
V_14 -> V_13 . type = V_5 -> type ;
V_14 -> V_13 . V_26 = V_9 -> V_15 . V_27 ;
V_14 -> V_13 . V_28 = V_5 -> V_29 ;
F_9 ( V_7 , sizeof( * V_14 ) ) ;
V_5 -> V_30 = false ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
V_32 -> V_9 = & V_3 -> V_10 -> V_11 ;
return F_3 ( V_3 ) ;
}
int F_11 ( struct V_2 * V_3 , bool V_33 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
T_3 V_34 ;
struct {
T_1 V_12 ;
T_4 V_13 ;
} * V_35 ;
struct {
T_1 V_12 ;
T_2 V_13 ;
} * V_36 ;
if ( V_5 -> V_30 )
return 0 ;
if ( V_37 [ V_5 -> type ] . V_38 )
V_37 [ V_5 -> type ] . V_38 ( V_7 ,
& V_5 -> V_39 ,
V_33 ) ;
V_34 = sizeof( * V_36 ) ;
if ( V_33 )
V_34 += sizeof( * V_35 ) ;
V_36 = F_6 ( V_7 , V_34 , V_20 ) ;
if ( ! V_36 ) {
F_7 ( L_1
L_3 ) ;
return - V_21 ;
}
V_5 -> V_29 = 0 ;
if ( V_33 ) {
V_35 = ( void * ) V_36 ;
V_35 -> V_12 . V_4 = V_40 ;
V_35 -> V_12 . V_24 = sizeof( V_35 -> V_13 ) ;
V_35 -> V_13 . V_25 = V_5 -> V_22 -> V_4 ;
V_35 -> V_13 . type = V_5 -> type ;
V_36 = ( void * ) & V_35 [ 1 ] ;
V_5 -> V_29 = V_3 -> V_41 ;
}
V_36 -> V_12 . V_4 = V_23 ;
V_36 -> V_12 . V_24 = sizeof( V_36 -> V_13 ) ;
V_36 -> V_13 . V_25 = V_5 -> V_22 -> V_4 ;
V_36 -> V_13 . type = V_5 -> type ;
V_36 -> V_13 . V_26 = V_20 ;
V_36 -> V_13 . V_28 = 0 ;
F_9 ( V_7 , V_34 ) ;
V_5 -> V_30 = true ;
V_3 -> V_4 = - 1 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 ,
bool V_33 ,
struct V_31 * V_32 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_8 * V_9 = V_32 -> V_9 ;
struct V_42 * V_43 ;
if ( F_13 ( & V_3 -> V_44 ) )
return 0 ;
F_4 ( V_9 -> V_15 . V_16 != V_17 ) ;
F_5 ( & V_9 -> V_18 -> V_19 . V_11 ) ;
F_14 ( & V_7 -> V_45 ) ;
if ( ! V_5 -> V_30 )
F_15 ( V_5 -> V_22 , V_33 ) ;
F_16 ( & V_7 -> V_45 ) ;
( void ) F_17 ( NULL , V_7 , & V_43 , NULL ) ;
F_18 ( V_9 , V_43 ) ;
if ( F_19 ( V_43 != NULL ) )
F_20 ( & V_43 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
struct {
T_1 V_12 ;
T_4 V_13 ;
} * V_14 ;
struct V_42 * V_43 ;
if ( ! V_5 -> V_30 ) {
V_14 = F_6 ( V_7 , sizeof( * V_14 ) ,
V_20 ) ;
if ( ! V_14 ) {
F_7 ( L_1
L_4 ) ;
return - V_21 ;
}
V_14 -> V_12 . V_4 = V_40 ;
V_14 -> V_12 . V_24 = sizeof( V_14 -> V_13 ) ;
V_14 -> V_13 . V_25 = V_5 -> V_22 -> V_4 ;
V_14 -> V_13 . type = V_5 -> type ;
V_5 -> V_29 = V_3 -> V_41 ;
F_22 ( V_7 , sizeof( * V_14 ) ) ;
}
( void ) F_17 ( NULL , V_7 , & V_43 , NULL ) ;
F_18 ( & V_3 -> V_10 -> V_11 , V_43 ) ;
F_20 ( & V_43 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , T_3 V_46 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_1 * V_5 = V_1 ( V_3 ) ;
struct V_47 * V_48 , * V_49 = V_3 -> V_10 ;
struct V_8 * V_9 , * V_50 = & V_3 -> V_10 -> V_11 ;
T_3 V_51 = V_3 -> V_41 ;
T_3 V_52 = V_5 -> V_29 ;
T_3 V_53 ;
struct V_54 V_55 , V_56 ;
int V_57 ;
T_3 V_58 ;
V_57 = F_21 ( V_3 ) ;
if ( V_57 )
return V_57 ;
V_53 = V_5 -> V_29 ;
V_5 -> V_29 = V_52 ;
V_48 = F_24 ( sizeof( * V_48 ) , V_59 ) ;
if ( ! V_48 )
return - V_21 ;
V_57 = F_25 ( V_7 , V_48 , V_46 , & V_60 ,
true , V_61 ) ;
if ( V_57 ) {
F_7 ( L_5 ) ;
return V_57 ;
}
V_9 = & V_48 -> V_11 ;
F_4 ( F_26 ( V_9 , false , true , NULL ) ) ;
V_57 = F_27 ( V_50 , false , false ) ;
if ( F_28 ( V_57 != 0 ) ) {
F_7 ( L_6 ) ;
goto V_62;
}
for ( V_58 = 0 ; V_58 < V_50 -> V_63 ; ++ V_58 ) {
bool V_64 ;
V_57 = F_29 ( V_50 , V_58 , 1 , & V_55 ) ;
if ( F_28 ( V_57 != 0 ) ) {
F_7 ( L_7 ) ;
goto V_62;
}
V_57 = F_29 ( V_9 , V_58 , 1 , & V_56 ) ;
if ( F_28 ( V_57 != 0 ) ) {
F_7 ( L_8 ) ;
goto V_65;
}
memcpy ( F_30 ( & V_56 , & V_64 ) ,
F_30 ( & V_55 , & V_64 ) ,
V_66 ) ;
F_31 ( & V_56 ) ;
F_31 ( & V_55 ) ;
}
V_57 = F_32 ( V_9 , & V_67 , false , false ) ;
if ( F_28 ( V_57 != 0 ) ) {
F_7 ( L_9 ) ;
goto V_62;
}
V_3 -> V_10 = V_48 ;
V_3 -> V_41 = V_46 ;
V_5 -> V_29 = V_53 ;
V_57 = F_3 ( V_3 ) ;
if ( V_57 ) {
F_7 ( L_10 ) ;
V_3 -> V_10 = V_49 ;
V_3 -> V_41 = V_51 ;
V_5 -> V_29 = V_52 ;
goto V_62;
}
F_33 ( & V_3 -> V_44 ) ;
F_34 ( & V_3 -> V_44 , & V_48 -> V_68 ) ;
F_35 ( & V_49 ) ;
V_3 -> V_4 = V_5 -> type ;
return 0 ;
V_65:
F_31 ( & V_55 ) ;
V_62:
F_36 ( V_9 ) ;
F_35 ( & V_48 ) ;
return V_57 ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
T_3 V_46 = V_3 -> V_41 ;
T_3 V_69 ;
int V_57 ;
V_69 = ( V_5 -> V_70 + 1 ) * V_37 [ V_5 -> type ] . V_24 ;
while ( V_69 > V_46 )
V_46 *= 2 ;
if ( F_19 ( V_46 <= V_3 -> V_41 ) ) {
if ( V_5 -> V_30 && ! F_13 ( & V_3 -> V_44 ) ) {
V_57 = F_3 ( V_3 ) ;
if ( V_57 )
return V_57 ;
}
V_3 -> V_4 = V_5 -> type ;
return 0 ;
}
return F_23 ( V_3 , V_46 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
( void ) F_2 ( V_3 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
F_40 ( V_3 ) ;
F_41 ( F_42 ( V_7 ) , V_71 ) ;
}
struct V_2 * F_43 ( struct V_6 * V_7 ,
struct V_2 * V_22 ,
T_5 type )
{
struct V_1 * V_5 ;
int V_57 ;
T_5 V_72 ;
if ( F_28 ( V_71 == 0 ) )
V_71 = F_44 ( sizeof( struct V_1 ) ) ;
V_57 = F_45 ( F_42 ( V_7 ) ,
V_71 , false , true ) ;
if ( F_28 ( V_57 ) )
return F_46 ( V_57 ) ;
V_5 = F_24 ( sizeof( * V_5 ) , V_59 ) ;
if ( F_28 ( ! V_5 ) ) {
V_57 = - V_21 ;
goto V_73;
}
V_57 = F_47 ( V_7 , & V_5 -> V_3 , true ,
F_39 , & V_74 ) ;
if ( F_28 ( V_57 != 0 ) )
goto V_75;
F_48 ( & V_5 -> V_39 ) ;
V_5 -> V_3 . V_4 = type ;
V_5 -> V_3 . V_41 = V_66 ;
V_72 = V_66 / V_37 [ type ] . V_24 ;
if ( V_72 < V_37 [ type ] . V_76 ) {
V_5 -> V_3 . V_41 = V_37 [ type ] . V_76 *
V_37 [ type ] . V_24 ;
V_5 -> V_3 . V_41 =
( V_5 -> V_3 . V_41 + V_66 - 1 ) & V_77 ;
}
V_5 -> V_30 = true ;
V_5 -> V_70 = - 1 ;
V_5 -> type = type ;
V_5 -> V_22 = V_22 ;
F_49 ( & V_5 -> V_3 , F_38 ) ;
return & V_5 -> V_3 ;
V_75:
F_40 ( V_5 ) ;
V_73:
F_41 ( F_42 ( V_7 ) , V_71 ) ;
return F_46 ( V_57 ) ;
}
int F_50 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 = V_1 ( V_3 ) ;
if ( V_4 < 0 || V_4 >= V_78 ) {
F_7 ( L_11 ,
( unsigned ) V_5 -> type , V_4 ) ;
return - V_79 ;
}
if ( V_5 -> V_70 < V_4 ) {
V_3 -> V_4 = - 1 ;
V_5 -> V_70 = V_4 ;
}
return 0 ;
}
void F_51 ( struct V_2 * V_3 , struct V_80 * V_81 )
{
struct V_1 * V_5 =
F_1 ( V_3 , struct V_1 , V_3 ) ;
F_34 ( V_81 , & V_5 -> V_39 ) ;
}
