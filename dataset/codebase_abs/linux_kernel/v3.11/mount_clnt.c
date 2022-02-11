int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {
. V_5 = V_2 -> V_5 ,
. V_6 = V_2 -> V_7 ,
. V_8 = V_2 -> V_9 ,
} ;
struct V_10 V_11 = {
. V_12 = V_2 -> V_13 ,
. V_14 = & V_4 ,
} ;
struct V_15 args = {
. V_16 = V_2 -> V_16 ,
. V_17 = V_2 -> V_17 ,
. V_18 = V_2 -> V_19 ,
. V_20 = V_2 -> V_21 ,
. V_22 = V_2 -> V_23 ,
. V_24 = & V_25 ,
. V_26 = V_2 -> V_26 ,
. V_27 = V_28 ,
} ;
struct V_29 * V_30 ;
int V_31 ;
F_2 ( L_1 ,
( V_2 -> V_23 ? V_2 -> V_23 : L_2 ) ,
V_2 -> V_13 ) ;
if ( strlen ( V_2 -> V_13 ) > V_32 )
return - V_33 ;
if ( V_2 -> V_34 )
args . V_35 |= V_36 ;
V_30 = F_3 ( & args ) ;
if ( F_4 ( V_30 ) )
goto V_37;
if ( V_2 -> V_26 == V_38 )
V_11 . V_39 = & V_30 -> V_40 [ V_41 ] ;
else
V_11 . V_39 = & V_30 -> V_40 [ V_42 ] ;
V_31 = F_5 ( V_30 , & V_11 , V_43 | V_44 ) ;
F_6 ( V_30 ) ;
if ( V_31 < 0 )
goto V_45;
if ( V_4 . V_46 != 0 )
goto V_47;
F_2 ( L_3 ) ;
V_31 = 0 ;
if ( V_2 -> V_26 != V_38 || * V_2 -> V_7 == 0 ) {
F_2 ( L_4 ) ;
V_2 -> V_9 [ 0 ] = V_48 ;
* V_2 -> V_7 = 1 ;
}
V_49:
return V_31 ;
V_37:
V_31 = F_7 ( V_30 ) ;
F_2 ( L_5 , V_31 ) ;
goto V_49;
V_45:
F_2 ( L_6 , V_31 ) ;
goto V_49;
V_47:
F_2 ( L_7 , V_4 . V_46 ) ;
V_31 = V_4 . V_46 ;
goto V_49;
}
void F_8 ( const struct V_1 * V_2 )
{
static const struct V_50 V_51 = {
. V_52 = 1 * V_53 ,
. V_54 = 3 * V_53 ,
. V_55 = 2 ,
} ;
struct V_15 args = {
. V_16 = V_2 -> V_16 ,
. V_17 = V_56 ,
. V_18 = V_2 -> V_19 ,
. V_20 = V_2 -> V_21 ,
. V_57 = & V_51 ,
. V_22 = V_2 -> V_23 ,
. V_24 = & V_25 ,
. V_26 = V_2 -> V_26 ,
. V_27 = V_28 ,
. V_35 = V_58 ,
} ;
struct V_10 V_11 = {
. V_12 = V_2 -> V_13 ,
} ;
struct V_29 * V_59 ;
int V_31 ;
if ( strlen ( V_2 -> V_13 ) > V_32 )
return;
if ( V_2 -> V_34 )
args . V_35 |= V_36 ;
V_59 = F_3 ( & args ) ;
if ( F_4 ( V_59 ) )
goto V_37;
F_2 ( L_8 ,
( V_2 -> V_23 ? V_2 -> V_23 : L_2 ) , V_2 -> V_13 ) ;
if ( V_2 -> V_26 == V_38 )
V_11 . V_39 = & V_59 -> V_40 [ V_60 ] ;
else
V_11 . V_39 = & V_59 -> V_40 [ V_61 ] ;
V_31 = F_5 ( V_59 , & V_11 , 0 ) ;
F_6 ( V_59 ) ;
if ( F_9 ( V_31 < 0 ) )
goto V_45;
return;
V_37:
F_2 ( L_9 ,
F_7 ( V_59 ) ) ;
return;
V_45:
F_2 ( L_10 , V_31 ) ;
}
static void F_10 ( struct V_62 * V_63 , const char * V_64 )
{
const T_1 V_65 = strlen ( V_64 ) ;
T_2 * V_66 ;
V_66 = F_11 ( V_63 , 4 + V_65 ) ;
F_12 ( V_66 , V_64 , V_65 ) ;
}
static void F_13 ( struct V_67 * V_68 , struct V_62 * V_63 ,
const char * V_13 )
{
F_10 ( V_63 , V_13 ) ;
}
static int F_14 ( struct V_62 * V_63 , struct V_3 * V_69 )
{
unsigned int V_70 ;
T_1 V_31 ;
T_2 * V_66 ;
V_66 = F_15 ( V_63 , 4 ) ;
if ( F_9 ( V_66 == NULL ) )
return - V_71 ;
V_31 = F_16 ( V_66 ) ;
for ( V_70 = 0 ; V_70 < F_17 ( V_72 ) ; V_70 ++ ) {
if ( V_72 [ V_70 ] . V_31 == V_31 ) {
V_69 -> V_46 = V_72 [ V_70 ] . V_46 ;
return 0 ;
}
}
F_2 ( L_11 , V_31 ) ;
V_69 -> V_46 = - V_73 ;
return 0 ;
}
static int F_18 ( struct V_62 * V_63 , struct V_3 * V_69 )
{
struct V_74 * V_5 = V_69 -> V_5 ;
T_2 * V_66 ;
V_66 = F_15 ( V_63 , V_75 ) ;
if ( F_9 ( V_66 == NULL ) )
return - V_71 ;
V_5 -> V_76 = V_75 ;
memcpy ( V_5 -> V_77 , V_66 , V_75 ) ;
return 0 ;
}
static int F_19 ( struct V_67 * V_68 ,
struct V_62 * V_63 ,
struct V_3 * V_69 )
{
int V_31 ;
V_31 = F_14 ( V_63 , V_69 ) ;
if ( F_9 ( V_31 != 0 || V_69 -> V_46 != 0 ) )
return V_31 ;
return F_18 ( V_63 , V_69 ) ;
}
static int F_20 ( struct V_62 * V_63 , struct V_3 * V_69 )
{
unsigned int V_70 ;
T_1 V_31 ;
T_2 * V_66 ;
V_66 = F_15 ( V_63 , 4 ) ;
if ( F_9 ( V_66 == NULL ) )
return - V_71 ;
V_31 = F_16 ( V_66 ) ;
for ( V_70 = 0 ; V_70 < F_17 ( V_78 ) ; V_70 ++ ) {
if ( V_78 [ V_70 ] . V_31 == V_31 ) {
V_69 -> V_46 = V_78 [ V_70 ] . V_46 ;
return 0 ;
}
}
F_2 ( L_12 , V_31 ) ;
V_69 -> V_46 = - V_73 ;
return 0 ;
}
static int F_21 ( struct V_62 * V_63 , struct V_3 * V_69 )
{
struct V_74 * V_5 = V_69 -> V_5 ;
T_1 V_76 ;
T_2 * V_66 ;
V_66 = F_15 ( V_63 , 4 ) ;
if ( F_9 ( V_66 == NULL ) )
return - V_71 ;
V_76 = F_16 ( V_66 ) ;
if ( V_76 > V_79 || V_76 == 0 )
return - V_71 ;
V_66 = F_15 ( V_63 , V_76 ) ;
if ( F_9 ( V_66 == NULL ) )
return - V_71 ;
V_5 -> V_76 = V_76 ;
memcpy ( V_5 -> V_77 , V_66 , V_76 ) ;
return 0 ;
}
static int F_22 ( struct V_62 * V_63 , struct V_3 * V_69 )
{
T_3 * V_80 = V_69 -> V_8 ;
unsigned int * V_81 = V_69 -> V_6 ;
T_1 V_82 , V_70 ;
T_2 * V_66 ;
if ( * V_81 == 0 )
return 0 ;
V_66 = F_15 ( V_63 , 4 ) ;
if ( F_9 ( V_66 == NULL ) )
return - V_71 ;
V_82 = F_16 ( V_66 ) ;
F_2 ( L_13 , V_82 ) ;
if ( V_82 > V_83 )
V_82 = V_83 ;
V_66 = F_15 ( V_63 , 4 * V_82 ) ;
if ( F_9 ( V_66 == NULL ) )
return - V_71 ;
if ( V_82 > * V_81 )
V_82 = * V_81 ;
for ( V_70 = 0 ; V_70 < V_82 ; V_70 ++ ) {
V_80 [ V_70 ] = F_16 ( V_66 ++ ) ;
F_2 ( L_14 , V_70 , V_80 [ V_70 ] ) ;
}
* V_81 = V_70 ;
return 0 ;
}
static int F_23 ( struct V_67 * V_68 ,
struct V_62 * V_63 ,
struct V_3 * V_69 )
{
int V_31 ;
V_31 = F_20 ( V_63 , V_69 ) ;
if ( F_9 ( V_31 != 0 || V_69 -> V_46 != 0 ) )
return V_31 ;
V_31 = F_21 ( V_63 , V_69 ) ;
if ( F_9 ( V_31 != 0 ) ) {
V_69 -> V_46 = - V_84 ;
return 0 ;
}
return F_22 ( V_63 , V_69 ) ;
}
