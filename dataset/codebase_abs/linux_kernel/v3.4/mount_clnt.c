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
if ( V_2 -> V_32 )
args . V_33 |= V_34 ;
V_30 = F_3 ( & args ) ;
if ( F_4 ( V_30 ) )
goto V_35;
if ( V_2 -> V_26 == V_36 )
V_11 . V_37 = & V_30 -> V_38 [ V_39 ] ;
else
V_11 . V_37 = & V_30 -> V_38 [ V_40 ] ;
V_31 = F_5 ( V_30 , & V_11 , 0 ) ;
F_6 ( V_30 ) ;
if ( V_31 < 0 )
goto V_41;
if ( V_4 . V_42 != 0 )
goto V_43;
F_2 ( L_3 ) ;
V_31 = 0 ;
V_44:
return V_31 ;
V_35:
V_31 = F_7 ( V_30 ) ;
F_2 ( L_4 , V_31 ) ;
goto V_44;
V_41:
F_2 ( L_5 , V_31 ) ;
goto V_44;
V_43:
F_2 ( L_6 , V_4 . V_42 ) ;
V_31 = V_4 . V_42 ;
goto V_44;
}
void F_8 ( const struct V_1 * V_2 )
{
static const struct V_45 V_46 = {
. V_47 = 1 * V_48 ,
. V_49 = 3 * V_48 ,
. V_50 = 2 ,
} ;
struct V_15 args = {
. V_16 = V_2 -> V_16 ,
. V_17 = V_51 ,
. V_18 = V_2 -> V_19 ,
. V_20 = V_2 -> V_21 ,
. V_52 = & V_46 ,
. V_22 = V_2 -> V_23 ,
. V_24 = & V_25 ,
. V_26 = V_2 -> V_26 ,
. V_27 = V_28 ,
. V_33 = V_53 ,
} ;
struct V_10 V_11 = {
. V_12 = V_2 -> V_13 ,
} ;
struct V_29 * V_54 ;
int V_31 ;
if ( V_2 -> V_32 )
args . V_33 |= V_34 ;
V_54 = F_3 ( & args ) ;
if ( F_4 ( V_54 ) )
goto V_35;
F_2 ( L_7 ,
( V_2 -> V_23 ? V_2 -> V_23 : L_2 ) , V_2 -> V_13 ) ;
if ( V_2 -> V_26 == V_36 )
V_11 . V_37 = & V_54 -> V_38 [ V_55 ] ;
else
V_11 . V_37 = & V_54 -> V_38 [ V_56 ] ;
V_31 = F_5 ( V_54 , & V_11 , 0 ) ;
F_6 ( V_54 ) ;
if ( F_9 ( V_31 < 0 ) )
goto V_41;
return;
V_35:
F_2 ( L_8 ,
F_7 ( V_54 ) ) ;
return;
V_41:
F_2 ( L_9 , V_31 ) ;
}
static void F_10 ( struct V_57 * V_58 , const char * V_59 )
{
const T_1 V_60 = strlen ( V_59 ) ;
T_2 * V_61 ;
F_11 ( V_60 > V_62 ) ;
V_61 = F_12 ( V_58 , 4 + V_60 ) ;
F_13 ( V_61 , V_59 , V_60 ) ;
}
static void F_14 ( struct V_63 * V_64 , struct V_57 * V_58 ,
const char * V_13 )
{
F_10 ( V_58 , V_13 ) ;
}
static int F_15 ( struct V_57 * V_58 , struct V_3 * V_65 )
{
unsigned int V_66 ;
T_1 V_31 ;
T_2 * V_61 ;
V_61 = F_16 ( V_58 , 4 ) ;
if ( F_9 ( V_61 == NULL ) )
return - V_67 ;
V_31 = F_17 ( V_61 ) ;
for ( V_66 = 0 ; V_66 < F_18 ( V_68 ) ; V_66 ++ ) {
if ( V_68 [ V_66 ] . V_31 == V_31 ) {
V_65 -> V_42 = V_68 [ V_66 ] . V_42 ;
return 0 ;
}
}
F_2 ( L_10 , V_31 ) ;
V_65 -> V_42 = - V_69 ;
return 0 ;
}
static int F_19 ( struct V_57 * V_58 , struct V_3 * V_65 )
{
struct V_70 * V_5 = V_65 -> V_5 ;
T_2 * V_61 ;
V_61 = F_16 ( V_58 , V_71 ) ;
if ( F_9 ( V_61 == NULL ) )
return - V_67 ;
V_5 -> V_72 = V_71 ;
memcpy ( V_5 -> V_73 , V_61 , V_71 ) ;
return 0 ;
}
static int F_20 ( struct V_63 * V_64 ,
struct V_57 * V_58 ,
struct V_3 * V_65 )
{
int V_31 ;
V_31 = F_15 ( V_58 , V_65 ) ;
if ( F_9 ( V_31 != 0 || V_65 -> V_42 != 0 ) )
return V_31 ;
return F_19 ( V_58 , V_65 ) ;
}
static int F_21 ( struct V_57 * V_58 , struct V_3 * V_65 )
{
unsigned int V_66 ;
T_1 V_31 ;
T_2 * V_61 ;
V_61 = F_16 ( V_58 , 4 ) ;
if ( F_9 ( V_61 == NULL ) )
return - V_67 ;
V_31 = F_17 ( V_61 ) ;
for ( V_66 = 0 ; V_66 < F_18 ( V_74 ) ; V_66 ++ ) {
if ( V_74 [ V_66 ] . V_31 == V_31 ) {
V_65 -> V_42 = V_74 [ V_66 ] . V_42 ;
return 0 ;
}
}
F_2 ( L_11 , V_31 ) ;
V_65 -> V_42 = - V_69 ;
return 0 ;
}
static int F_22 ( struct V_57 * V_58 , struct V_3 * V_65 )
{
struct V_70 * V_5 = V_65 -> V_5 ;
T_1 V_72 ;
T_2 * V_61 ;
V_61 = F_16 ( V_58 , 4 ) ;
if ( F_9 ( V_61 == NULL ) )
return - V_67 ;
V_72 = F_17 ( V_61 ) ;
if ( V_72 > V_75 || V_72 == 0 )
return - V_67 ;
V_61 = F_16 ( V_58 , V_72 ) ;
if ( F_9 ( V_61 == NULL ) )
return - V_67 ;
V_5 -> V_72 = V_72 ;
memcpy ( V_5 -> V_73 , V_61 , V_72 ) ;
return 0 ;
}
static int F_23 ( struct V_57 * V_58 , struct V_3 * V_65 )
{
T_3 * V_76 = V_65 -> V_8 ;
unsigned int * V_77 = V_65 -> V_6 ;
T_1 V_78 , V_66 ;
T_2 * V_61 ;
if ( * V_77 == 0 )
return 0 ;
V_61 = F_16 ( V_58 , 4 ) ;
if ( F_9 ( V_61 == NULL ) )
return - V_67 ;
V_78 = F_17 ( V_61 ) ;
F_2 ( L_12 , V_78 ) ;
if ( V_78 > V_79 )
V_78 = V_79 ;
V_61 = F_16 ( V_58 , 4 * V_78 ) ;
if ( F_9 ( V_61 == NULL ) )
return - V_67 ;
if ( V_78 > * V_77 )
V_78 = * V_77 ;
for ( V_66 = 0 ; V_66 < V_78 ; V_66 ++ ) {
V_76 [ V_66 ] = F_17 ( V_61 ++ ) ;
F_2 ( L_13 , V_66 , V_76 [ V_66 ] ) ;
}
* V_77 = V_66 ;
return 0 ;
}
static int F_24 ( struct V_63 * V_64 ,
struct V_57 * V_58 ,
struct V_3 * V_65 )
{
int V_31 ;
V_31 = F_21 ( V_58 , V_65 ) ;
if ( F_9 ( V_31 != 0 || V_65 -> V_42 != 0 ) )
return V_31 ;
V_31 = F_22 ( V_58 , V_65 ) ;
if ( F_9 ( V_31 != 0 ) ) {
V_65 -> V_42 = - V_80 ;
return 0 ;
}
return F_23 ( V_58 , V_65 ) ;
}
