static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static int F_3 ( struct V_2 * V_3 ,
unsigned V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_8 , V_9 , V_10 = F_5 ( V_3 ) ;
T_1 V_11 ;
V_9 = V_5 << ( F_6 ( V_3 -> V_12 -> V_13 ) - 1 ) ;
V_11 = V_3 -> V_12 -> V_13 ;
V_8 = F_7 ( V_4 , V_3 -> V_12 -> V_14 , V_9 , V_11 ) ;
if ( V_8 )
return V_8 ;
switch ( V_10 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_8 = F_8 ( V_4 , V_7 -> V_19 , 1 << V_7 -> V_20 ) ;
break;
}
return V_8 ;
}
static inline int F_9 ( struct V_1 * V_4 ,
struct V_6 * V_7 )
{
T_1 V_21 , V_22 ;
int V_8 ;
if ( V_7 -> V_23 [ 0 ] == V_7 -> V_23 [ 1 ] &&
V_7 -> V_24 [ 0 ] == V_7 -> V_24 [ 1 ] )
return 0 ;
V_8 = F_10 ( V_4 , V_7 -> V_23 [ 0 ] , & V_21 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_10 ( V_4 , V_7 -> V_23 [ 1 ] , & V_22 ) ;
if ( V_8 )
return V_8 ;
if ( ! ( V_22 & ( 1 << V_7 -> V_24 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_21 & ( 1 << V_7 -> V_24 [ 0 ] ) ) ) {
V_8 = F_8 ( V_4 , V_7 -> V_23 [ 0 ] ,
1 << V_7 -> V_24 [ 0 ] ) ;
if ( V_8 )
return V_8 ;
}
return F_11 ( V_4 , V_7 -> V_23 [ 1 ] ,
1 << V_7 -> V_24 [ 1 ] ) ;
}
static int F_12 ( struct V_25 * V_26 ,
int V_27 , struct V_28 * V_29 )
{
struct V_1 * V_4 = V_26 -> V_30 . V_4 ;
struct V_31 * V_32 = V_29 -> V_33 ;
T_1 V_34 ;
if ( V_32 == NULL )
return 0 ;
if ( ! ( V_32 -> V_35 & V_36 ) )
return 0 ;
switch ( V_27 ) {
case V_17 :
V_34 = V_37 ;
break;
case V_18 :
V_34 = V_38 ;
break;
default:
F_13 ( & V_26 -> V_30 , L_1 ) ;
return - V_39 ;
}
return F_14 ( V_4 , V_34 ,
V_32 -> V_35 & V_40 ) ;
}
static inline struct V_6 * F_15 ( int V_27 )
{
struct V_6 * V_7 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_16 ( V_6 ) ; V_41 ++ ) {
V_7 = & V_6 [ V_41 ] ;
if ( V_7 -> V_12 . V_27 == V_27 )
return V_7 ;
}
return NULL ;
}
static struct V_42 * F_17 (
struct V_25 * V_26 ,
struct V_43 * * V_44 )
{
const unsigned int V_45 = F_16 ( V_46 ) ;
struct V_47 * V_48 = V_26 -> V_30 . V_4 -> V_49 ;
struct V_47 * V_50 ;
const char * V_51 = NULL ;
unsigned int V_41 ;
struct V_42 * V_52 ;
int V_53 ;
V_50 = F_18 ( V_48 , L_2 ) ;
if ( ! V_50 ) {
F_19 ( & V_26 -> V_30 , L_3 ) ;
return NULL ;
}
V_53 = V_43 ( & V_26 -> V_30 , V_50 , V_46 , V_45 ) ;
if ( V_53 < 0 ) {
F_19 ( & V_26 -> V_30 , L_4 , V_53 ) ;
F_20 ( V_50 ) ;
return NULL ;
}
F_20 ( V_50 ) ;
V_52 = F_21 ( & V_26 -> V_30 , sizeof( * V_52 ) , V_54 ) ;
if ( ! V_52 ) {
F_19 ( & V_26 -> V_30 , L_5 ) ;
return NULL ;
}
for ( V_41 = 0 ; V_41 < V_45 ; V_41 ++ ) {
int V_27 ;
if ( ! V_46 [ V_41 ] . V_55 )
continue;
V_52 -> V_56 [ V_41 ] = V_46 [ V_41 ] . V_55 ;
V_27 = ( int ) V_46 [ V_41 ] . V_33 ;
if ( V_27 == V_57 )
V_51 = V_52 -> V_56 [ V_41 ] -> V_58 . V_59 ;
if ( ( V_27 == V_60 ) || ( V_27 == V_61 ) )
V_52 -> V_56 [ V_41 ] -> V_62 = V_51 ;
}
* V_44 = V_46 ;
return V_52 ;
}
static struct V_42 * F_17 (
struct V_25 * V_26 ,
struct V_43 * * V_44 )
{
* V_44 = NULL ;
return NULL ;
}
static int F_22 ( struct V_25 * V_26 )
{
struct V_6 * V_7 = NULL ;
struct V_63 V_64 = { } ;
struct V_2 * * V_3 ;
struct V_28 * V_65 ;
struct V_42 * V_52 ;
struct V_43 * V_44 = NULL ;
int V_27 ;
int V_53 ;
F_23 ( & V_26 -> V_30 , L_6 ) ;
V_52 = F_24 ( V_26 -> V_30 . V_4 ) ;
if ( ( ! V_52 ) && ( V_26 -> V_30 . V_4 -> V_49 ) )
V_52 = F_17 ( V_26 ,
& V_44 ) ;
if ( ! V_52 ) {
F_19 ( & V_26 -> V_30 , L_7 ) ;
return - V_66 ;
}
V_3 = F_21 ( & V_26 -> V_30 , V_67 *
sizeof( * V_3 ) , V_54 ) ;
if ( ! V_3 ) {
F_19 ( & V_26 -> V_30 , L_8 ) ;
return - V_68 ;
}
for ( V_27 = 0 ; V_27 < V_67 ; ++ V_27 ) {
V_65 = V_52 -> V_56 [ V_27 ] ;
V_7 = F_15 ( V_27 ) ;
if ( ! V_7 ) {
F_19 ( & V_26 -> V_30 , L_9 ) ;
V_53 = - V_39 ;
goto V_69;
}
V_53 = F_9 ( V_26 -> V_30 . V_4 , V_7 ) ;
if ( V_53 ) {
F_19 ( & V_26 -> V_30 ,
L_10 , V_27 , V_53 ) ;
goto V_69;
}
V_64 . V_30 = V_26 -> V_30 . V_4 ;
V_64 . V_55 = V_65 ;
V_64 . V_33 = V_7 ;
if ( V_44 )
V_64 . V_49 = V_44 [ V_27 ] . V_49 ;
V_3 [ V_27 ] = F_25 ( & V_7 -> V_12 , & V_64 ) ;
if ( F_26 ( V_3 [ V_27 ] ) ) {
F_19 ( & V_26 -> V_30 , L_11 ,
V_7 -> V_12 . V_59 ) ;
V_53 = F_27 ( V_3 [ V_27 ] ) ;
goto V_69;
}
if ( V_65 ) {
V_53 = F_12 ( V_26 , V_27 ,
V_65 ) ;
if ( V_53 < 0 ) {
F_19 ( & V_26 -> V_30 ,
L_12 , V_53 ) ;
F_28 ( V_3 [ V_27 ] ) ;
goto V_69;
}
}
}
F_29 ( V_26 , V_3 ) ;
return 0 ;
V_69:
while ( -- V_27 >= 0 )
F_28 ( V_3 [ V_27 ] ) ;
return V_53 ;
}
static int F_30 ( struct V_25 * V_26 )
{
struct V_2 * * V_3 = F_31 ( V_26 ) ;
int V_27 = V_67 ;
while ( -- V_27 >= 0 )
F_28 ( V_3 [ V_27 ] ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_70 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_70 ) ;
}
