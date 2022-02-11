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
V_48:
return V_31 ;
V_37:
V_31 = F_7 ( V_30 ) ;
F_2 ( L_4 , V_31 ) ;
goto V_48;
V_45:
F_2 ( L_5 , V_31 ) ;
goto V_48;
V_47:
F_2 ( L_6 , V_4 . V_46 ) ;
V_31 = V_4 . V_46 ;
goto V_48;
}
void F_8 ( const struct V_1 * V_2 )
{
static const struct V_49 V_50 = {
. V_51 = 1 * V_52 ,
. V_53 = 3 * V_52 ,
. V_54 = 2 ,
} ;
struct V_15 args = {
. V_16 = V_2 -> V_16 ,
. V_17 = V_55 ,
. V_18 = V_2 -> V_19 ,
. V_20 = V_2 -> V_21 ,
. V_56 = & V_50 ,
. V_22 = V_2 -> V_23 ,
. V_24 = & V_25 ,
. V_26 = V_2 -> V_26 ,
. V_27 = V_28 ,
. V_35 = V_57 ,
} ;
struct V_10 V_11 = {
. V_12 = V_2 -> V_13 ,
} ;
struct V_29 * V_58 ;
int V_31 ;
if ( strlen ( V_2 -> V_13 ) > V_32 )
return;
if ( V_2 -> V_34 )
args . V_35 |= V_36 ;
V_58 = F_3 ( & args ) ;
if ( F_4 ( V_58 ) )
goto V_37;
F_2 ( L_7 ,
( V_2 -> V_23 ? V_2 -> V_23 : L_2 ) , V_2 -> V_13 ) ;
if ( V_2 -> V_26 == V_38 )
V_11 . V_39 = & V_58 -> V_40 [ V_59 ] ;
else
V_11 . V_39 = & V_58 -> V_40 [ V_60 ] ;
V_31 = F_5 ( V_58 , & V_11 , 0 ) ;
F_6 ( V_58 ) ;
if ( F_9 ( V_31 < 0 ) )
goto V_45;
return;
V_37:
F_2 ( L_8 ,
F_7 ( V_58 ) ) ;
return;
V_45:
F_2 ( L_9 , V_31 ) ;
}
static void F_10 ( struct V_61 * V_62 , const char * V_63 )
{
const T_1 V_64 = strlen ( V_63 ) ;
T_2 * V_65 ;
V_65 = F_11 ( V_62 , 4 + V_64 ) ;
F_12 ( V_65 , V_63 , V_64 ) ;
}
static void F_13 ( struct V_66 * V_67 , struct V_61 * V_62 ,
const char * V_13 )
{
F_10 ( V_62 , V_13 ) ;
}
static int F_14 ( struct V_61 * V_62 , struct V_3 * V_68 )
{
unsigned int V_69 ;
T_1 V_31 ;
T_2 * V_65 ;
V_65 = F_15 ( V_62 , 4 ) ;
if ( F_9 ( V_65 == NULL ) )
return - V_70 ;
V_31 = F_16 ( V_65 ) ;
for ( V_69 = 0 ; V_69 < F_17 ( V_71 ) ; V_69 ++ ) {
if ( V_71 [ V_69 ] . V_31 == V_31 ) {
V_68 -> V_46 = V_71 [ V_69 ] . V_46 ;
return 0 ;
}
}
F_2 ( L_10 , V_31 ) ;
V_68 -> V_46 = - V_72 ;
return 0 ;
}
static int F_18 ( struct V_61 * V_62 , struct V_3 * V_68 )
{
struct V_73 * V_5 = V_68 -> V_5 ;
T_2 * V_65 ;
V_65 = F_15 ( V_62 , V_74 ) ;
if ( F_9 ( V_65 == NULL ) )
return - V_70 ;
V_5 -> V_75 = V_74 ;
memcpy ( V_5 -> V_76 , V_65 , V_74 ) ;
return 0 ;
}
static int F_19 ( struct V_66 * V_67 ,
struct V_61 * V_62 ,
struct V_3 * V_68 )
{
int V_31 ;
V_31 = F_14 ( V_62 , V_68 ) ;
if ( F_9 ( V_31 != 0 || V_68 -> V_46 != 0 ) )
return V_31 ;
return F_18 ( V_62 , V_68 ) ;
}
static int F_20 ( struct V_61 * V_62 , struct V_3 * V_68 )
{
unsigned int V_69 ;
T_1 V_31 ;
T_2 * V_65 ;
V_65 = F_15 ( V_62 , 4 ) ;
if ( F_9 ( V_65 == NULL ) )
return - V_70 ;
V_31 = F_16 ( V_65 ) ;
for ( V_69 = 0 ; V_69 < F_17 ( V_77 ) ; V_69 ++ ) {
if ( V_77 [ V_69 ] . V_31 == V_31 ) {
V_68 -> V_46 = V_77 [ V_69 ] . V_46 ;
return 0 ;
}
}
F_2 ( L_11 , V_31 ) ;
V_68 -> V_46 = - V_72 ;
return 0 ;
}
static int F_21 ( struct V_61 * V_62 , struct V_3 * V_68 )
{
struct V_73 * V_5 = V_68 -> V_5 ;
T_1 V_75 ;
T_2 * V_65 ;
V_65 = F_15 ( V_62 , 4 ) ;
if ( F_9 ( V_65 == NULL ) )
return - V_70 ;
V_75 = F_16 ( V_65 ) ;
if ( V_75 > V_78 || V_75 == 0 )
return - V_70 ;
V_65 = F_15 ( V_62 , V_75 ) ;
if ( F_9 ( V_65 == NULL ) )
return - V_70 ;
V_5 -> V_75 = V_75 ;
memcpy ( V_5 -> V_76 , V_65 , V_75 ) ;
return 0 ;
}
static int F_22 ( struct V_61 * V_62 , struct V_3 * V_68 )
{
T_3 * V_79 = V_68 -> V_8 ;
unsigned int * V_80 = V_68 -> V_6 ;
T_1 V_81 , V_69 ;
T_2 * V_65 ;
if ( * V_80 == 0 )
return 0 ;
V_65 = F_15 ( V_62 , 4 ) ;
if ( F_9 ( V_65 == NULL ) )
return - V_70 ;
V_81 = F_16 ( V_65 ) ;
F_2 ( L_12 , V_81 ) ;
if ( V_81 > V_82 )
V_81 = V_82 ;
V_65 = F_15 ( V_62 , 4 * V_81 ) ;
if ( F_9 ( V_65 == NULL ) )
return - V_70 ;
if ( V_81 > * V_80 )
V_81 = * V_80 ;
for ( V_69 = 0 ; V_69 < V_81 ; V_69 ++ ) {
V_79 [ V_69 ] = F_16 ( V_65 ++ ) ;
F_2 ( L_13 , V_69 , V_79 [ V_69 ] ) ;
}
* V_80 = V_69 ;
return 0 ;
}
static int F_23 ( struct V_66 * V_67 ,
struct V_61 * V_62 ,
struct V_3 * V_68 )
{
int V_31 ;
V_31 = F_20 ( V_62 , V_68 ) ;
if ( F_9 ( V_31 != 0 || V_68 -> V_46 != 0 ) )
return V_31 ;
V_31 = F_21 ( V_62 , V_68 ) ;
if ( F_9 ( V_31 != 0 ) ) {
V_68 -> V_46 = - V_83 ;
return 0 ;
}
return F_22 ( V_62 , V_68 ) ;
}
