int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 ;
F_2 ( & V_6 -> V_11 . V_12 ) ;
if ( F_3 ( V_13 , & V_6 -> V_14 ) ) {
V_9 . V_15 = V_3 ;
V_9 . V_4 = V_4 ;
V_10 = F_4 ( & V_6 -> V_16 , & V_9 ) ;
if ( V_10 != 0 )
F_5 ( & V_6 -> V_11 , V_17 ) ;
}
F_6 ( & V_6 -> V_11 . V_12 ) ;
return 0 ;
}
static unsigned int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_11 )
{
struct V_5 * V_6 = V_19 -> V_21 ;
unsigned int V_22 = 0 ;
F_8 ( V_19 , & V_6 -> V_11 , V_11 ) ;
F_2 ( & V_6 -> V_11 . V_12 ) ;
if ( ! F_9 ( & V_6 -> V_16 ) )
V_22 = V_17 | V_23 ;
F_6 ( & V_6 -> V_11 . V_12 ) ;
return V_22 ;
}
static T_3 F_10 ( struct V_18 * V_19 ,
char T_4 * V_24 ,
T_5 V_25 ,
T_6 * V_26 )
{
struct V_5 * V_6 = V_19 -> V_21 ;
unsigned int V_10 ;
int V_27 ;
if ( V_25 < sizeof( struct V_8 ) )
return - V_28 ;
F_2 ( & V_6 -> V_11 . V_12 ) ;
if ( F_9 ( & V_6 -> V_16 ) ) {
if ( V_19 -> V_29 & V_30 ) {
V_27 = - V_31 ;
goto V_32;
}
V_27 = F_11 ( V_6 -> V_11 ,
! F_9 ( & V_6 -> V_16 ) ) ;
if ( V_27 )
goto V_32;
}
V_27 = F_12 ( & V_6 -> V_16 , V_24 , V_25 , & V_10 ) ;
V_32:
F_6 ( & V_6 -> V_11 . V_12 ) ;
return V_27 ? V_27 : V_10 ;
}
static int F_13 ( struct V_33 * V_33 , struct V_18 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_21 ;
F_2 ( & V_6 -> V_11 . V_12 ) ;
F_14 ( V_13 , & V_6 -> V_14 ) ;
F_15 ( & V_6 -> V_16 ) ;
F_6 ( & V_6 -> V_11 . V_12 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_34 ;
if ( V_6 == NULL )
return - V_35 ;
F_2 ( & V_6 -> V_11 . V_12 ) ;
if ( F_17 ( V_13 , & V_6 -> V_14 ) ) {
F_6 ( & V_6 -> V_11 . V_12 ) ;
return - V_36 ;
}
F_6 ( & V_6 -> V_11 . V_12 ) ;
V_34 = F_18 ( L_1 ,
& V_37 , V_6 , V_38 ) ;
if ( V_34 < 0 ) {
F_2 ( & V_6 -> V_11 . V_12 ) ;
F_14 ( V_13 , & V_6 -> V_14 ) ;
F_6 ( & V_6 -> V_11 . V_12 ) ;
}
return V_34 ;
}
static T_3 F_19 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_24 ,
T_5 V_43 )
{
struct V_1 * V_2 = F_20 ( V_40 ) ;
struct V_44 * V_45 = F_21 ( V_42 ) ;
int V_27 ;
bool V_46 ;
V_27 = F_22 ( V_24 , & V_46 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = V_2 -> V_47 -> V_48 ( V_2 ,
V_45 -> V_49 ,
V_46 ) ;
return ( V_27 < 0 ) ? V_27 : V_43 ;
}
static T_3 F_23 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_24 )
{
struct V_1 * V_2 = F_20 ( V_40 ) ;
struct V_44 * V_45 = F_21 ( V_42 ) ;
int V_46 = V_2 -> V_47 -> V_50 ( V_2 ,
V_45 -> V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
else
return sprintf ( V_24 , L_2 , V_46 ) ;
}
static T_3 F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
char * V_24 )
{
struct V_1 * V_2 = F_20 ( V_40 ) ;
struct V_44 * V_45 = F_21 ( V_42 ) ;
int V_46 , V_27 ;
V_27 = V_2 -> V_47 -> V_51 ( V_2 ,
V_45 -> V_49 , & V_46 ) ;
if ( V_27 < 0 )
return V_27 ;
return sprintf ( V_24 , L_2 , V_46 ) ;
}
static T_3 F_25 ( struct V_39 * V_40 ,
struct V_41 * V_42 ,
const char * V_24 ,
T_5 V_43 )
{
struct V_1 * V_2 = F_20 ( V_40 ) ;
struct V_44 * V_45 = F_21 ( V_42 ) ;
int V_46 ;
int V_27 ;
if ( ! V_2 -> V_47 -> V_52 )
return - V_28 ;
V_27 = F_26 ( V_24 , 10 , & V_46 ) ;
if ( V_27 )
return V_27 ;
V_27 = V_2 -> V_47 -> V_52 ( V_2 , V_45 -> V_49 ,
V_46 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_43 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_53 const * V_54 )
{
int V_27 = 0 , V_55 , V_56 = 0 ;
T_1 V_57 = 0 ;
char * V_58 ;
if ( ! V_54 -> V_59 )
return 0 ;
F_28 (i, &chan->event_mask, sizeof(chan->event_mask)*8 ) {
V_58 = F_29 ( V_60 , L_3 ,
V_61 [ V_55 / V_62 ] ,
V_63 [ V_55 % V_62 ] ) ;
if ( V_58 == NULL ) {
V_27 = - V_64 ;
goto V_65;
}
if ( V_54 -> V_66 )
V_57 = F_30 ( V_54 -> type , 0 , V_54 -> V_67 ,
V_55 / V_62 ,
V_55 % V_62 ) ;
else if ( V_54 -> V_68 )
V_57 = F_31 ( V_54 -> type ,
0 , 0 ,
V_55 % V_62 ,
V_55 / V_62 ,
0 ,
V_54 -> V_67 ,
V_54 -> V_69 ) ;
else
V_57 = F_32 ( V_54 -> type ,
V_54 -> V_67 ,
V_55 / V_62 ,
V_55 % V_62 ) ;
V_27 = F_33 ( V_58 ,
V_54 ,
& F_23 ,
F_19 ,
V_57 ,
0 ,
& V_2 -> V_40 ,
& V_2 -> V_7 ->
V_70 ) ;
F_34 ( V_58 ) ;
if ( V_27 )
goto V_65;
V_56 ++ ;
V_58 = F_29 ( V_60 , L_4 ,
V_61 [ V_55 / V_62 ] ,
V_63 [ V_55 % V_62 ] ) ;
if ( V_58 == NULL ) {
V_27 = - V_64 ;
goto V_65;
}
V_27 = F_33 ( V_58 , V_54 ,
F_24 ,
F_25 ,
V_57 ,
0 ,
& V_2 -> V_40 ,
& V_2 -> V_7 ->
V_70 ) ;
F_34 ( V_58 ) ;
if ( V_27 )
goto V_65;
V_56 ++ ;
}
V_27 = V_56 ;
V_65:
return V_27 ;
}
static inline void F_35 ( struct V_1 * V_2 )
{
struct V_44 * V_71 , * V_72 ;
F_36 (p, n,
&indio_dev->event_interface->
dev_attr_list, l) {
F_34 ( V_71 -> V_73 . V_42 . V_74 ) ;
F_34 ( V_71 ) ;
}
}
static inline int F_37 ( struct V_1 * V_2 )
{
int V_75 , V_27 , V_56 = 0 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_76 ; V_75 ++ ) {
V_27 = F_27 ( V_2 ,
& V_2 -> V_77 [ V_75 ] ) ;
if ( V_27 < 0 )
return V_27 ;
V_56 += V_27 ;
}
return V_56 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_76 ; V_75 ++ )
if ( V_2 -> V_77 [ V_75 ] . V_59 != 0 )
return true ;
return false ;
}
static void F_39 ( struct V_5 * V_6 )
{
F_40 ( V_6 -> V_16 ) ;
F_41 ( & V_6 -> V_11 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_44 * V_71 ;
int V_27 = 0 , V_78 = 0 , V_56 , V_79 ;
struct V_80 * * V_42 ;
if ( ! ( V_2 -> V_47 -> V_81 ||
F_38 ( V_2 ) ) )
return 0 ;
V_2 -> V_7 =
F_43 ( sizeof( struct V_5 ) , V_60 ) ;
if ( V_2 -> V_7 == NULL ) {
V_27 = - V_64 ;
goto V_65;
}
F_44 ( & V_2 -> V_7 -> V_70 ) ;
F_39 ( V_2 -> V_7 ) ;
if ( V_2 -> V_47 -> V_81 != NULL ) {
V_42 = V_2 -> V_47 -> V_81 -> V_82 ;
while ( * V_42 ++ != NULL )
V_78 ++ ;
}
V_56 = V_78 ;
if ( V_2 -> V_77 ) {
V_27 = F_37 ( V_2 ) ;
if ( V_27 < 0 )
goto V_83;
V_56 += V_27 ;
}
V_2 -> V_7 -> V_84 . V_74 = V_85 ;
V_2 -> V_7 -> V_84 . V_82 = F_45 ( V_56 + 1 ,
sizeof( V_2 -> V_7 -> V_84 . V_82 [ 0 ] ) ,
V_60 ) ;
if ( V_2 -> V_7 -> V_84 . V_82 == NULL ) {
V_27 = - V_64 ;
goto V_83;
}
if ( V_2 -> V_47 -> V_81 )
memcpy ( V_2 -> V_7 -> V_84 . V_82 ,
V_2 -> V_47 -> V_81 -> V_82 ,
sizeof( V_2 -> V_7 -> V_84 . V_82 [ 0 ] )
* V_78 ) ;
V_79 = V_78 ;
F_46 (p,
&indio_dev->event_interface->dev_attr_list,
l)
V_2 -> V_7 -> V_84 . V_82 [ V_79 ++ ] =
& V_71 -> V_73 . V_42 ;
V_2 -> V_86 [ V_2 -> V_87 ++ ] =
& V_2 -> V_7 -> V_84 ;
return 0 ;
V_83:
F_35 ( V_2 ) ;
F_34 ( V_2 -> V_7 ) ;
V_65:
return V_27 ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_35 ( V_2 ) ;
F_34 ( V_2 -> V_7 -> V_84 . V_82 ) ;
F_34 ( V_2 -> V_7 ) ;
}
