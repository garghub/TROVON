static int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 )
{
if ( V_4 == 0 || V_4 > V_5 ) {
F_2 ( L_1 , V_4 ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( F_4 ( & V_2 -> V_8 ) == 0 ) {
F_2 ( L_2 ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( V_2 -> V_9 != F_5 ( V_10 ) ) {
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
return NULL ; ;
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
if ( V_3 < F_24 ( * V_4 , V_59 ) ) {
F_2 ( L_6 ,
V_3 , F_24 ( * V_4 , V_59 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( V_2 , V_3 , * V_4 ) ;
}
int F_25 ( struct V_60 * V_61 , struct V_13 * V_15 ,
struct V_57 * V_2 )
{
struct V_16 * V_17 ;
int V_18 ;
T_3 V_41 = V_62 ;
F_14 ( V_15 , V_2 ) ;
for ( V_18 = 0 ; V_18 < V_15 -> V_25 ; V_18 ++ ) {
V_17 = V_15 -> V_24 [ V_18 ] ;
F_26 ( & V_2 -> V_63 [ V_18 ] . V_64 , & V_17 -> V_65 ) ;
V_17 -> V_66 = F_6 ( V_2 -> V_63 [ V_18 ] . V_67 ) ;
V_17 -> V_68 = F_6 ( V_2 -> V_63 [ V_18 ] . V_69 ) ;
if ( V_17 -> V_66 >= V_61 -> V_70 . V_71 ) {
F_2 ( L_7 ,
V_17 -> V_66 , V_61 -> V_70 . V_71 ) ;
F_27 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_61 -> V_72 [ V_17 -> V_66 ] ) {
F_2 ( L_8 , V_17 -> V_66 ) ;
F_27 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_20 ( V_61 -> V_72 [ V_17 -> V_66 ] ,
& V_41 ) ;
}
V_15 -> V_73 = V_41 * V_15 -> V_25 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_74 , int V_3 ,
T_1 * V_4 )
{
struct V_75 * V_2 ;
V_2 = (struct V_75 * ) V_74 ;
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_9 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_16 ( V_2 -> V_58 ) ;
if ( V_3 < F_24 ( * V_4 , V_76 ) ) {
F_2 ( L_10 ,
V_3 , F_24 ( * V_4 , V_76 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( (struct V_57 * ) V_2 , V_3 ,
* V_4 ) ;
}
int F_29 ( struct V_60 * V_61 , struct V_13 * V_15 ,
struct V_1 * V_74 )
{
struct V_75 * V_2 ;
struct V_16 * V_17 ;
int V_18 ;
T_3 V_41 = V_62 ;
int V_77 = 0 ;
V_2 = (struct V_75 * ) V_74 ;
F_14 ( V_15 , (struct V_57 * ) V_2 ) ;
V_77 = F_30 ( V_15 -> V_31 , V_2 -> V_78 ,
sizeof( V_15 -> V_31 ) ) ;
if ( V_77 >= sizeof( V_15 -> V_31 ) )
return - V_79 ;
for ( V_18 = 0 ; V_18 < V_15 -> V_25 ; V_18 ++ ) {
V_17 = V_15 -> V_24 [ V_18 ] ;
F_26 ( & V_2 -> V_63 [ V_18 ] . V_64 , & V_17 -> V_65 ) ;
V_17 -> V_66 = F_6 ( V_2 -> V_63 [ V_18 ] . V_67 ) ;
V_17 -> V_68 = F_6 ( V_2 -> V_63 [ V_18 ] . V_69 ) ;
if ( V_17 -> V_66 >= V_61 -> V_70 . V_71 ) {
F_2 ( L_7 ,
V_17 -> V_66 , V_61 -> V_70 . V_71 ) ;
F_31 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_61 -> V_72 [ V_17 -> V_66 ] ) {
F_2 ( L_8 , V_17 -> V_66 ) ;
F_31 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_20 ( V_61 -> V_72 [ V_17 -> V_66 ] ,
& V_41 ) ;
}
V_15 -> V_73 = V_41 * V_15 -> V_25 ;
return 0 ;
}
