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
struct V_13 * F_7 ( T_2 V_4 )
{
T_3 V_14 , V_15 ;
struct V_13 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
F_8 ( V_4 <= V_20 ) ;
V_14 = sizeof( struct V_17 * ) * V_4 ;
V_15 = sizeof( * V_16 ) + V_14 ;
V_16 = F_9 ( V_15 , V_21 ) ;
if ( ! V_16 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_4 ; V_19 ++ ) {
V_18 = F_10 ( V_22 , V_21 ) ;
if ( ! V_18 )
goto V_23;
V_16 -> V_24 [ V_19 ] = V_18 ;
}
V_16 -> V_25 = V_4 ;
return V_16 ;
V_23:
while ( -- V_19 >= 0 )
F_11 ( V_22 , V_16 -> V_24 [ V_19 ] ) ;
F_12 ( V_16 ) ;
return NULL ;
}
void F_13 ( struct V_13 * V_16 )
{
T_1 V_4 = V_16 -> V_25 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_4 ; V_19 ++ )
F_11 ( V_22 , V_16 -> V_24 [ V_19 ] ) ;
F_12 ( V_16 ) ;
}
static T_4 F_14 ( struct V_26 * V_27 )
{
T_4 V_28 = V_29 ;
struct V_30 * V_31 ;
if ( ! V_27 -> V_32 )
return V_28 ;
V_31 = V_27 -> V_33 -> V_34 . V_35 . V_36 ;
if ( ! V_31 )
return V_28 ;
F_15 ( & V_31 -> V_37 ) ;
if ( V_31 -> V_38 == V_39 &&
( V_31 -> V_40 . V_41 & V_42 ) &&
V_31 -> V_40 . V_43 > 0 )
V_28 = V_31 -> V_40 . V_43 ;
F_16 ( & V_31 -> V_37 ) ;
return V_28 ;
}
static int F_17 ( struct V_44 * V_45 ,
struct V_13 * V_16 ,
struct V_1 * V_2 ,
struct V_46 * V_47 )
{
T_4 V_48 = 0 ;
unsigned int V_4 ;
struct V_17 * V_18 ;
T_4 V_49 ;
unsigned int V_19 ;
F_18 ( & V_16 -> V_50 , & V_2 -> V_8 ) ;
V_16 -> V_51 = F_6 ( V_2 -> V_11 ) ;
V_16 -> V_52 = F_6 ( V_2 -> V_9 ) ;
V_16 -> V_53 = F_19 ( V_2 -> V_54 ) ;
V_16 -> V_55 [ 0 ] = '\0' ;
V_4 = F_20 ( V_16 ) ? 0 : V_16 -> V_25 ;
for ( V_19 = 0 ; V_19 < V_4 ; V_19 ++ ) {
V_18 = V_16 -> V_24 [ V_19 ] ;
F_21 ( & V_47 [ V_19 ] . V_56 , & V_18 -> V_57 ) ;
V_18 -> V_58 = F_6 ( V_47 [ V_19 ] . V_59 ) ;
V_18 -> V_60 = F_6 ( V_47 [ V_19 ] . V_61 ) ;
if ( F_22 ( V_18 ) )
continue;
if ( V_18 -> V_58 >= V_45 -> V_62 . V_63 &&
! F_23 ( V_45 ) -> V_64 ) {
F_2 ( L_5 ,
( char * ) V_45 -> V_62 . V_65 . V_66 ,
V_18 -> V_58 , V_45 -> V_62 . V_63 ) ;
F_24 ( V_6 , V_2 ) ;
return - V_7 ;
}
if ( ! V_45 -> V_67 [ V_18 -> V_58 ] ) {
F_2 ( L_6 ,
( char * ) V_45 -> V_62 . V_65 . V_66 ,
V_18 -> V_58 ) ;
F_24 ( V_6 , V_2 ) ;
continue;
}
V_49 = F_14 ( V_45 -> V_67 [ V_18 -> V_58 ] ) ;
if ( V_48 == 0 || V_49 < V_48 )
V_48 = V_49 ;
}
if ( V_48 == 0 )
V_48 = V_29 ;
V_4 = V_16 -> V_25 ? : V_45 -> V_62 . V_63 ;
V_49 = V_48 * V_4 ;
if ( V_49 < V_48 )
V_16 -> V_68 = V_69 ;
else
V_16 -> V_68 = V_49 ;
return 0 ;
}
static void
F_25 ( struct V_13 * V_16 , int * V_70 ,
T_4 * V_71 , T_4 * V_72 )
{
if ( V_72 )
* V_72 = ( V_73 ) V_16 -> V_51 * V_16 -> V_25 ;
}
static void
F_26 ( struct V_13 * V_16 , int * V_70 ,
T_4 * V_71 , T_4 * V_72 )
{
if ( V_72 )
* V_72 = ( V_73 ) V_16 -> V_51 * V_16 -> V_25 ;
}
static int F_27 ( struct V_74 * V_2 , int V_3 ,
T_1 * V_4 )
{
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_7 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_19 ( V_2 -> V_75 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_76 )
* V_4 = 0 ;
if ( V_3 < F_28 ( * V_4 , V_77 ) ) {
F_2 ( L_8 ,
V_3 , F_28 ( * V_4 , V_77 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( V_2 , V_3 , * V_4 ) ;
}
static int F_29 ( struct V_44 * V_45 , struct V_13 * V_16 ,
struct V_74 * V_2 )
{
return F_17 ( V_45 , V_16 , V_2 , V_2 -> V_78 ) ;
}
static int F_30 ( struct V_1 * V_79 , int V_3 ,
T_1 * V_4 )
{
struct V_80 * V_2 ;
V_2 = (struct V_80 * ) V_79 ;
if ( V_3 < sizeof( * V_2 ) ) {
F_2 ( L_9 ,
V_3 , ( int ) sizeof( * V_2 ) ) ;
return - V_7 ;
}
* V_4 = F_19 ( V_2 -> V_75 ) ;
if ( F_6 ( V_2 -> V_9 ) & V_76 )
* V_4 = 0 ;
if ( V_3 < F_28 ( * V_4 , V_81 ) ) {
F_2 ( L_10 ,
V_3 , F_28 ( * V_4 , V_81 ) ) ;
F_3 ( V_6 , V_2 ) ;
return - V_7 ;
}
return F_1 ( (struct V_74 * ) V_2 , V_3 ,
* V_4 ) ;
}
static int F_31 ( struct V_44 * V_45 , struct V_13 * V_16 ,
struct V_1 * V_2 )
{
struct V_80 * V_82 = (struct V_80 * ) V_2 ;
T_3 V_83 = 0 ;
int V_84 ;
V_84 = F_17 ( V_45 , V_16 , V_2 , V_82 -> V_78 ) ;
if ( V_84 )
return V_84 ;
V_83 = F_32 ( V_16 -> V_55 , V_82 -> V_85 ,
sizeof( V_16 -> V_55 ) ) ;
if ( V_83 >= sizeof( V_16 -> V_55 ) )
return - V_86 ;
return 0 ;
}
void F_33 ( unsigned int V_87 , const struct V_13 * V_16 )
{
F_34 ( V_87 , L_11 V_88 L_12 V_89 L_13 ,
V_16 ,
F_35 ( & V_16 -> V_50 ) , V_16 -> V_68 , V_16 -> V_90 ,
V_16 -> V_51 , V_16 -> V_25 ,
F_36 ( & V_16 -> V_91 ) , V_16 -> V_53 ,
V_16 -> V_55 ) ;
}
