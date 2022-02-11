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
( F_6 ( V_2 -> V_11 ) &
( V_12 - 1 ) ) != 0 ) {
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
V_17 = F_10 ( V_22 , V_21 ) ;
if ( ! V_17 )
goto V_23;
V_15 -> V_24 [ V_18 ] = V_17 ;
}
V_15 -> V_25 = V_4 ;
return V_15 ;
V_23:
while ( -- V_18 >= 0 )
F_11 ( V_22 , V_15 -> V_24 [ V_18 ] ) ;
F_12 ( V_15 ) ;
return NULL ;
}
void F_13 ( struct V_13 * V_15 )
{
T_1 V_4 = V_15 -> V_25 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
F_11 ( V_22 , V_15 -> V_24 [ V_18 ] ) ;
F_12 ( V_15 ) ;
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
static void F_19 ( struct V_35 * V_36 , T_3 * V_37 )
{
struct V_38 * V_39 = V_36 -> V_40 -> V_41 . V_42 . V_43 ;
if ( ! V_39 || ! V_36 -> V_44 ) {
* V_37 = V_45 ;
return;
}
F_20 ( & V_39 -> V_46 ) ;
if ( V_39 -> V_47 == V_48 &&
( V_39 -> V_49 . V_50 & V_51 ) &&
V_39 -> V_49 . V_52 > 0 ) {
if ( * V_37 > V_39 -> V_49 . V_52 )
* V_37 = V_39 -> V_49 . V_52 ;
} else {
* V_37 = V_45 ;
}
F_21 ( & V_39 -> V_46 ) ;
}
static int F_22 ( struct V_53 * V_2 , int V_3 ,
T_1 * V_4 )
{
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_5 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_16 ( V_2 -> V_54 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_55 )
* V_4 = 0 ;
if ( V_3 < F_23 ( * V_4 , V_56 ) ) {
F_2 ( L_6 ,
V_3 , F_23 ( * V_4 , V_56 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( V_2 , V_3 , * V_4 ) ;
}
static int F_24 ( struct V_57 * V_58 , struct V_13 * V_15 ,
struct V_53 * V_2 )
{
struct V_16 * V_17 ;
int V_18 ;
int V_4 ;
T_3 V_37 = V_59 ;
F_14 ( V_15 , V_2 ) ;
V_4 = F_25 ( V_15 ) ? 0 : V_15 -> V_25 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_17 = V_15 -> V_24 [ V_18 ] ;
F_26 ( & V_2 -> V_60 [ V_18 ] . V_61 , & V_17 -> V_62 ) ;
V_17 -> V_63 = F_6 ( V_2 -> V_60 [ V_18 ] . V_64 ) ;
V_17 -> V_65 = F_6 ( V_2 -> V_60 [ V_18 ] . V_66 ) ;
if ( F_27 ( V_17 ) )
continue;
if ( V_17 -> V_63 >= V_58 -> V_67 . V_68 ) {
F_2 ( L_7 ,
V_17 -> V_63 , V_58 -> V_67 . V_68 ) ;
F_28 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_58 -> V_69 [ V_17 -> V_63 ] ) {
F_2 ( L_8 , V_17 -> V_63 ) ;
F_28 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_19 ( V_58 -> V_69 [ V_17 -> V_63 ] ,
& V_37 ) ;
}
V_15 -> V_70 = V_37 * V_15 -> V_25 ;
if ( V_15 -> V_25 == 0 )
V_15 -> V_70 = V_37 * V_58 -> V_67 . V_68 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_71 , int V_3 ,
T_1 * V_4 )
{
struct V_72 * V_2 ;
V_2 = (struct V_72 * ) V_71 ;
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_9 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_16 ( V_2 -> V_54 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_55 )
* V_4 = 0 ;
if ( V_3 < F_23 ( * V_4 , V_73 ) ) {
F_2 ( L_10 ,
V_3 , F_23 ( * V_4 , V_73 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( (struct V_53 * ) V_2 , V_3 ,
* V_4 ) ;
}
static int F_30 ( struct V_57 * V_58 , struct V_13 * V_15 ,
struct V_1 * V_71 )
{
struct V_72 * V_2 ;
struct V_16 * V_17 ;
int V_18 ;
int V_4 ;
T_3 V_37 = V_59 ;
int V_74 = 0 ;
V_2 = (struct V_72 * ) V_71 ;
F_14 ( V_15 , (struct V_53 * ) V_2 ) ;
V_4 = F_25 ( V_15 ) ? 0 : V_15 -> V_25 ;
V_74 = F_31 ( V_15 -> V_31 , V_2 -> V_75 ,
sizeof( V_15 -> V_31 ) ) ;
if ( V_74 >= sizeof( V_15 -> V_31 ) )
return - V_76 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_17 = V_15 -> V_24 [ V_18 ] ;
F_26 ( & V_2 -> V_60 [ V_18 ] . V_61 , & V_17 -> V_62 ) ;
V_17 -> V_63 = F_6 ( V_2 -> V_60 [ V_18 ] . V_64 ) ;
V_17 -> V_65 = F_6 ( V_2 -> V_60 [ V_18 ] . V_66 ) ;
if ( F_27 ( V_17 ) )
continue;
if ( V_17 -> V_63 >= V_58 -> V_67 . V_68 ) {
F_2 ( L_7 ,
V_17 -> V_63 , V_58 -> V_67 . V_68 ) ;
F_32 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_58 -> V_69 [ V_17 -> V_63 ] ) {
F_2 ( L_8 , V_17 -> V_63 ) ;
F_32 ( V_6 , V_2 ) ;
return - V_7 ;
}
F_19 ( V_58 -> V_69 [ V_17 -> V_63 ] ,
& V_37 ) ;
}
V_15 -> V_70 = V_37 * V_15 -> V_25 ;
if ( V_15 -> V_25 == 0 )
V_15 -> V_70 = V_37 * V_58 -> V_67 . V_68 ;
return 0 ;
}
void F_33 ( unsigned int V_77 , const struct V_13 * V_15 )
{
F_34 ( V_77 , L_11 V_78 L_12 V_79 L_13 ,
V_15 ,
F_35 ( & V_15 -> V_26 ) , V_15 -> V_70 , V_15 -> V_80 ,
V_15 -> V_27 , V_15 -> V_25 ,
F_36 ( & V_15 -> V_81 ) , V_15 -> V_29 ,
V_15 -> V_31 ) ;
}
