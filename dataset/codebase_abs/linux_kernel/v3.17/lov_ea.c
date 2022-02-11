static int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 )
{
if ( V_4 > V_5 ) {
F_2 ( L_1 , V_4 ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( F_4 ( & V_2 -> V_8 ) == 0 ) {
F_2 ( L_2 ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( F_5 ( F_6 ( V_2 -> V_9 ) ) != V_10 ) {
F_2 ( L_3 ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( V_2 -> V_11 == 0 ||
( F_6 ( V_2 -> V_11 ) & ( V_12 - 1 ) ) != 0 ) {
F_2 ( L_4 ,
F_6 ( V_2 -> V_11 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return 0 ;
}
struct V_13 * F_7 ( T_1 V_4 , int * V_14 )
{
struct V_13 * V_15 ;
struct V_16 * V_17 ;
int V_18 , V_19 ;
F_8 ( V_4 <= V_20 ) ;
V_19 = sizeof( struct V_16 * ) * V_4 ;
* V_14 = sizeof( struct V_13 ) + V_19 ;
F_9 ( V_15 , * V_14 ) ;
if ( ! V_15 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
F_10 ( V_17 , V_21 , V_22 ) ;
if ( V_17 == NULL )
goto V_23;
V_15 -> V_24 [ V_18 ] = V_17 ;
}
V_15 -> V_25 = V_4 ;
return V_15 ;
V_23:
while ( -- V_18 >= 0 )
F_11 ( V_15 -> V_24 [ V_18 ] , V_21 , sizeof( * V_17 ) ) ;
F_12 ( V_15 , * V_14 ) ;
return NULL ;
}
void F_13 ( struct V_13 * V_15 )
{
T_1 V_4 = V_15 -> V_25 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
F_11 ( V_15 -> V_24 [ V_18 ] , V_21 ,
sizeof( struct V_16 ) ) ;
F_12 ( V_15 , sizeof( struct V_13 ) +
V_4 * sizeof( struct V_16 * ) ) ;
}
static void F_14 ( struct V_13 * V_15 ,
struct V_1 * V_2 )
{
F_15 ( & V_15 -> V_26 , & V_2 -> V_8 ) ;
V_15 -> V_27 = F_6 ( V_2 -> V_11 ) ;
V_15 -> V_28 = F_6 ( V_2 -> V_9 ) ;
V_15 -> V_29 = F_16 ( V_2 -> V_30 ) ;
V_15 -> V_31 [ 0 ] = '\0' ;
}
static void
F_17 ( struct V_13 * V_15 , int * V_32 ,
T_2 * V_33 , T_2 * V_34 )
{
if ( V_34 )
* V_34 = ( T_2 ) V_15 -> V_27 * V_15 -> V_25 ;
}
static void
F_18 ( struct V_13 * V_15 , int * V_32 ,
T_2 * V_33 , T_2 * V_34 )
{
if ( V_34 )
* V_34 = ( T_2 ) V_15 -> V_27 * V_15 -> V_25 ;
}
static int F_19 ( struct V_13 * V_15 , struct V_35 * V_36 ,
struct V_37 * V_38 )
{
return 0 ;
}
static void F_20 ( struct V_39 * V_40 , T_3 * V_41 )
{
struct V_42 * V_43 = V_40 -> V_44 -> V_45 . V_46 . V_47 ;
if ( V_43 == NULL || ! V_40 -> V_48 ) {
* V_41 = V_49 ;
return;
}
F_21 ( & V_43 -> V_50 ) ;
if ( V_43 -> V_51 == V_52 &&
( V_43 -> V_53 . V_54 & V_55 ) &&
V_43 -> V_53 . V_56 > 0 ) {
if ( * V_41 > V_43 -> V_53 . V_56 )
* V_41 = V_43 -> V_53 . V_56 ;
} else {
* V_41 = V_49 ;
}
F_22 ( & V_43 -> V_50 ) ;
}
static int F_23 ( struct V_57 * V_2 , int V_3 ,
T_1 * V_4 )
{
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_5 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_16 ( V_2 -> V_58 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_59 )
* V_4 = 0 ;
if ( V_3 < F_24 ( * V_4 , V_60 ) ) {
F_2 ( L_6 ,
V_3 , F_24 ( * V_4 , V_60 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( V_2 , V_3 , * V_4 ) ;
}
int F_25 ( struct V_61 * V_62 , struct V_13 * V_15 ,
struct V_57 * V_2 )
{
struct V_16 * V_17 ;
int V_18 ;
int V_4 ;
T_3 V_41 = V_63 ;
F_14 ( V_15 , V_2 ) ;
V_4 = F_26 ( V_15 ) ? 0 : V_15 -> V_25 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_17 = V_15 -> V_24 [ V_18 ] ;
F_27 ( & V_2 -> V_64 [ V_18 ] . V_65 , & V_17 -> V_66 ) ;
V_17 -> V_67 = F_6 ( V_2 -> V_64 [ V_18 ] . V_68 ) ;
V_17 -> V_69 = F_6 ( V_2 -> V_64 [ V_18 ] . V_70 ) ;
if ( V_17 -> V_67 >= V_62 -> V_71 . V_72 ) {
F_2 ( L_7 ,
V_17 -> V_67 , V_62 -> V_71 . V_72 ) ;
F_28 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_62 -> V_73 [ V_17 -> V_67 ] ) {
F_2 ( L_8 , V_17 -> V_67 ) ;
F_28 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_20 ( V_62 -> V_73 [ V_17 -> V_67 ] ,
& V_41 ) ;
}
V_15 -> V_74 = V_41 * V_15 -> V_25 ;
if ( V_15 -> V_25 == 0 )
V_15 -> V_74 = V_41 * V_62 -> V_71 . V_72 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_75 , int V_3 ,
T_1 * V_4 )
{
struct V_76 * V_2 ;
V_2 = (struct V_76 * ) V_75 ;
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_9 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_16 ( V_2 -> V_58 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_59 )
* V_4 = 0 ;
if ( V_3 < F_24 ( * V_4 , V_77 ) ) {
F_2 ( L_10 ,
V_3 , F_24 ( * V_4 , V_77 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( (struct V_57 * ) V_2 , V_3 ,
* V_4 ) ;
}
int F_30 ( struct V_61 * V_62 , struct V_13 * V_15 ,
struct V_1 * V_75 )
{
struct V_76 * V_2 ;
struct V_16 * V_17 ;
int V_18 ;
int V_4 ;
T_3 V_41 = V_63 ;
int V_78 = 0 ;
V_2 = (struct V_76 * ) V_75 ;
F_14 ( V_15 , (struct V_57 * ) V_2 ) ;
V_4 = F_26 ( V_15 ) ? 0 : V_15 -> V_25 ;
V_78 = F_31 ( V_15 -> V_31 , V_2 -> V_79 ,
sizeof( V_15 -> V_31 ) ) ;
if ( V_78 >= sizeof( V_15 -> V_31 ) )
return - V_80 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_17 = V_15 -> V_24 [ V_18 ] ;
F_27 ( & V_2 -> V_64 [ V_18 ] . V_65 , & V_17 -> V_66 ) ;
V_17 -> V_67 = F_6 ( V_2 -> V_64 [ V_18 ] . V_68 ) ;
V_17 -> V_69 = F_6 ( V_2 -> V_64 [ V_18 ] . V_70 ) ;
if ( V_17 -> V_67 >= V_62 -> V_71 . V_72 ) {
F_2 ( L_7 ,
V_17 -> V_67 , V_62 -> V_71 . V_72 ) ;
F_32 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_62 -> V_73 [ V_17 -> V_67 ] ) {
F_2 ( L_8 , V_17 -> V_67 ) ;
F_32 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_20 ( V_62 -> V_73 [ V_17 -> V_67 ] ,
& V_41 ) ;
}
V_15 -> V_74 = V_41 * V_15 -> V_25 ;
if ( V_15 -> V_25 == 0 )
V_15 -> V_74 = V_41 * V_62 -> V_71 . V_72 ;
return 0 ;
}
void F_33 ( unsigned int V_81 , const struct V_13 * V_15 )
{
F_34 ( V_81 , L_11 V_82 L_12
L_13
L_14 V_83 L_15 , V_15 ,
F_35 ( & V_15 -> V_26 ) , V_15 -> V_74 , V_15 -> V_84 ,
V_15 -> V_27 , V_15 -> V_25 ,
F_36 ( & V_15 -> V_85 ) , V_15 -> V_29 ,
V_15 -> V_31 ) ;
}
