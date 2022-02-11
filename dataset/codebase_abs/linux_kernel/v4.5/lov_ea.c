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
V_15 = F_9 ( * V_14 , V_21 ) ;
if ( ! V_15 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_17 = F_10 ( V_22 , V_21 | V_23 ) ;
if ( V_17 == NULL )
goto V_24;
V_15 -> V_25 [ V_18 ] = V_17 ;
}
V_15 -> V_26 = V_4 ;
return V_15 ;
V_24:
while ( -- V_18 >= 0 )
F_11 ( V_22 , V_15 -> V_25 [ V_18 ] ) ;
F_12 ( V_15 ) ;
return NULL ;
}
void F_13 ( struct V_13 * V_15 )
{
T_1 V_4 = V_15 -> V_26 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
F_11 ( V_22 , V_15 -> V_25 [ V_18 ] ) ;
F_12 ( V_15 ) ;
}
static void F_14 ( struct V_13 * V_15 ,
struct V_1 * V_2 )
{
F_15 ( & V_15 -> V_27 , & V_2 -> V_8 ) ;
V_15 -> V_28 = F_6 ( V_2 -> V_11 ) ;
V_15 -> V_29 = F_6 ( V_2 -> V_9 ) ;
V_15 -> V_30 = F_16 ( V_2 -> V_31 ) ;
V_15 -> V_32 [ 0 ] = '\0' ;
}
static void
F_17 ( struct V_13 * V_15 , int * V_33 ,
T_2 * V_34 , T_2 * V_35 )
{
if ( V_35 )
* V_35 = ( T_2 ) V_15 -> V_28 * V_15 -> V_26 ;
}
static void
F_18 ( struct V_13 * V_15 , int * V_33 ,
T_2 * V_34 , T_2 * V_35 )
{
if ( V_35 )
* V_35 = ( T_2 ) V_15 -> V_28 * V_15 -> V_26 ;
}
static int F_19 ( struct V_13 * V_15 , struct V_36 * V_37 ,
struct V_38 * V_39 )
{
return 0 ;
}
static void F_20 ( struct V_40 * V_41 , T_3 * V_42 )
{
struct V_43 * V_44 = V_41 -> V_45 -> V_46 . V_47 . V_48 ;
if ( V_44 == NULL || ! V_41 -> V_49 ) {
* V_42 = V_50 ;
return;
}
F_21 ( & V_44 -> V_51 ) ;
if ( V_44 -> V_52 == V_53 &&
( V_44 -> V_54 . V_55 & V_56 ) &&
V_44 -> V_54 . V_57 > 0 ) {
if ( * V_42 > V_44 -> V_54 . V_57 )
* V_42 = V_44 -> V_54 . V_57 ;
} else {
* V_42 = V_50 ;
}
F_22 ( & V_44 -> V_51 ) ;
}
static int F_23 ( struct V_58 * V_2 , int V_3 ,
T_1 * V_4 )
{
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_5 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_16 ( V_2 -> V_59 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_60 )
* V_4 = 0 ;
if ( V_3 < F_24 ( * V_4 , V_61 ) ) {
F_2 ( L_6 ,
V_3 , F_24 ( * V_4 , V_61 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( V_2 , V_3 , * V_4 ) ;
}
static int F_25 ( struct V_62 * V_63 , struct V_13 * V_15 ,
struct V_58 * V_2 )
{
struct V_16 * V_17 ;
int V_18 ;
int V_4 ;
T_3 V_42 = V_64 ;
F_14 ( V_15 , V_2 ) ;
V_4 = F_26 ( V_15 ) ? 0 : V_15 -> V_26 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_17 = V_15 -> V_25 [ V_18 ] ;
F_27 ( & V_2 -> V_65 [ V_18 ] . V_66 , & V_17 -> V_67 ) ;
V_17 -> V_68 = F_6 ( V_2 -> V_65 [ V_18 ] . V_69 ) ;
V_17 -> V_70 = F_6 ( V_2 -> V_65 [ V_18 ] . V_71 ) ;
if ( F_28 ( V_17 ) )
continue;
if ( V_17 -> V_68 >= V_63 -> V_72 . V_73 ) {
F_2 ( L_7 ,
V_17 -> V_68 , V_63 -> V_72 . V_73 ) ;
F_29 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_63 -> V_74 [ V_17 -> V_68 ] ) {
F_2 ( L_8 , V_17 -> V_68 ) ;
F_29 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_20 ( V_63 -> V_74 [ V_17 -> V_68 ] ,
& V_42 ) ;
}
V_15 -> V_75 = V_42 * V_15 -> V_26 ;
if ( V_15 -> V_26 == 0 )
V_15 -> V_75 = V_42 * V_63 -> V_72 . V_73 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_76 , int V_3 ,
T_1 * V_4 )
{
struct V_77 * V_2 ;
V_2 = (struct V_77 * ) V_76 ;
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_9 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_16 ( V_2 -> V_59 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_60 )
* V_4 = 0 ;
if ( V_3 < F_24 ( * V_4 , V_78 ) ) {
F_2 ( L_10 ,
V_3 , F_24 ( * V_4 , V_78 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( (struct V_58 * ) V_2 , V_3 ,
* V_4 ) ;
}
static int F_31 ( struct V_62 * V_63 , struct V_13 * V_15 ,
struct V_1 * V_76 )
{
struct V_77 * V_2 ;
struct V_16 * V_17 ;
int V_18 ;
int V_4 ;
T_3 V_42 = V_64 ;
int V_79 = 0 ;
V_2 = (struct V_77 * ) V_76 ;
F_14 ( V_15 , (struct V_58 * ) V_2 ) ;
V_4 = F_26 ( V_15 ) ? 0 : V_15 -> V_26 ;
V_79 = F_32 ( V_15 -> V_32 , V_2 -> V_80 ,
sizeof( V_15 -> V_32 ) ) ;
if ( V_79 >= sizeof( V_15 -> V_32 ) )
return - V_81 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_17 = V_15 -> V_25 [ V_18 ] ;
F_27 ( & V_2 -> V_65 [ V_18 ] . V_66 , & V_17 -> V_67 ) ;
V_17 -> V_68 = F_6 ( V_2 -> V_65 [ V_18 ] . V_69 ) ;
V_17 -> V_70 = F_6 ( V_2 -> V_65 [ V_18 ] . V_71 ) ;
if ( F_28 ( V_17 ) )
continue;
if ( V_17 -> V_68 >= V_63 -> V_72 . V_73 ) {
F_2 ( L_7 ,
V_17 -> V_68 , V_63 -> V_72 . V_73 ) ;
F_33 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_63 -> V_74 [ V_17 -> V_68 ] ) {
F_2 ( L_8 , V_17 -> V_68 ) ;
F_33 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_20 ( V_63 -> V_74 [ V_17 -> V_68 ] ,
& V_42 ) ;
}
V_15 -> V_75 = V_42 * V_15 -> V_26 ;
if ( V_15 -> V_26 == 0 )
V_15 -> V_75 = V_42 * V_63 -> V_72 . V_73 ;
return 0 ;
}
void F_34 ( unsigned int V_82 , const struct V_13 * V_15 )
{
F_35 ( V_82 , L_11 V_83 L_12 V_84 L_13 ,
V_15 ,
F_36 ( & V_15 -> V_27 ) , V_15 -> V_75 , V_15 -> V_85 ,
V_15 -> V_28 , V_15 -> V_26 ,
F_37 ( & V_15 -> V_86 ) , V_15 -> V_30 ,
V_15 -> V_32 ) ;
}
