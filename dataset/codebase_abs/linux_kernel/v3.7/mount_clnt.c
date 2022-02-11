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
V_31 = F_5 ( V_30 , & V_11 , V_41 | V_42 ) ;
F_6 ( V_30 ) ;
if ( V_31 < 0 )
goto V_43;
if ( V_4 . V_44 != 0 )
goto V_45;
F_2 ( L_3 ) ;
V_31 = 0 ;
V_46:
return V_31 ;
V_35:
V_31 = F_7 ( V_30 ) ;
F_2 ( L_4 , V_31 ) ;
goto V_46;
V_43:
F_2 ( L_5 , V_31 ) ;
goto V_46;
V_45:
F_2 ( L_6 , V_4 . V_44 ) ;
V_31 = V_4 . V_44 ;
goto V_46;
}
void F_8 ( const struct V_1 * V_2 )
{
static const struct V_47 V_48 = {
. V_49 = 1 * V_50 ,
. V_51 = 3 * V_50 ,
. V_52 = 2 ,
} ;
struct V_15 args = {
. V_16 = V_2 -> V_16 ,
. V_17 = V_53 ,
. V_18 = V_2 -> V_19 ,
. V_20 = V_2 -> V_21 ,
. V_54 = & V_48 ,
. V_22 = V_2 -> V_23 ,
. V_24 = & V_25 ,
. V_26 = V_2 -> V_26 ,
. V_27 = V_28 ,
. V_33 = V_55 ,
} ;
struct V_10 V_11 = {
. V_12 = V_2 -> V_13 ,
} ;
struct V_29 * V_56 ;
int V_31 ;
if ( V_2 -> V_32 )
args . V_33 |= V_34 ;
V_56 = F_3 ( & args ) ;
if ( F_4 ( V_56 ) )
goto V_35;
F_2 ( L_7 ,
( V_2 -> V_23 ? V_2 -> V_23 : L_2 ) , V_2 -> V_13 ) ;
if ( V_2 -> V_26 == V_36 )
V_11 . V_37 = & V_56 -> V_38 [ V_57 ] ;
else
V_11 . V_37 = & V_56 -> V_38 [ V_58 ] ;
V_31 = F_5 ( V_56 , & V_11 , 0 ) ;
F_6 ( V_56 ) ;
if ( F_9 ( V_31 < 0 ) )
goto V_43;
return;
V_35:
F_2 ( L_8 ,
F_7 ( V_56 ) ) ;
return;
V_43:
F_2 ( L_9 , V_31 ) ;
}
static void F_10 ( struct V_59 * V_60 , const char * V_61 )
{
const T_1 V_62 = strlen ( V_61 ) ;
T_2 * V_63 ;
F_11 ( V_62 > V_64 ) ;
V_63 = F_12 ( V_60 , 4 + V_62 ) ;
F_13 ( V_63 , V_61 , V_62 ) ;
}
static void F_14 ( struct V_65 * V_66 , struct V_59 * V_60 ,
const char * V_13 )
{
F_10 ( V_60 , V_13 ) ;
}
static int F_15 ( struct V_59 * V_60 , struct V_3 * V_67 )
{
unsigned int V_68 ;
T_1 V_31 ;
T_2 * V_63 ;
V_63 = F_16 ( V_60 , 4 ) ;
if ( F_9 ( V_63 == NULL ) )
return - V_69 ;
V_31 = F_17 ( V_63 ) ;
for ( V_68 = 0 ; V_68 < F_18 ( V_70 ) ; V_68 ++ ) {
if ( V_70 [ V_68 ] . V_31 == V_31 ) {
V_67 -> V_44 = V_70 [ V_68 ] . V_44 ;
return 0 ;
}
}
F_2 ( L_10 , V_31 ) ;
V_67 -> V_44 = - V_71 ;
return 0 ;
}
static int F_19 ( struct V_59 * V_60 , struct V_3 * V_67 )
{
struct V_72 * V_5 = V_67 -> V_5 ;
T_2 * V_63 ;
V_63 = F_16 ( V_60 , V_73 ) ;
if ( F_9 ( V_63 == NULL ) )
return - V_69 ;
V_5 -> V_74 = V_73 ;
memcpy ( V_5 -> V_75 , V_63 , V_73 ) ;
return 0 ;
}
static int F_20 ( struct V_65 * V_66 ,
struct V_59 * V_60 ,
struct V_3 * V_67 )
{
int V_31 ;
V_31 = F_15 ( V_60 , V_67 ) ;
if ( F_9 ( V_31 != 0 || V_67 -> V_44 != 0 ) )
return V_31 ;
return F_19 ( V_60 , V_67 ) ;
}
static int F_21 ( struct V_59 * V_60 , struct V_3 * V_67 )
{
unsigned int V_68 ;
T_1 V_31 ;
T_2 * V_63 ;
V_63 = F_16 ( V_60 , 4 ) ;
if ( F_9 ( V_63 == NULL ) )
return - V_69 ;
V_31 = F_17 ( V_63 ) ;
for ( V_68 = 0 ; V_68 < F_18 ( V_76 ) ; V_68 ++ ) {
if ( V_76 [ V_68 ] . V_31 == V_31 ) {
V_67 -> V_44 = V_76 [ V_68 ] . V_44 ;
return 0 ;
}
}
F_2 ( L_11 , V_31 ) ;
V_67 -> V_44 = - V_71 ;
return 0 ;
}
static int F_22 ( struct V_59 * V_60 , struct V_3 * V_67 )
{
struct V_72 * V_5 = V_67 -> V_5 ;
T_1 V_74 ;
T_2 * V_63 ;
V_63 = F_16 ( V_60 , 4 ) ;
if ( F_9 ( V_63 == NULL ) )
return - V_69 ;
V_74 = F_17 ( V_63 ) ;
if ( V_74 > V_77 || V_74 == 0 )
return - V_69 ;
V_63 = F_16 ( V_60 , V_74 ) ;
if ( F_9 ( V_63 == NULL ) )
return - V_69 ;
V_5 -> V_74 = V_74 ;
memcpy ( V_5 -> V_75 , V_63 , V_74 ) ;
return 0 ;
}
static int F_23 ( struct V_59 * V_60 , struct V_3 * V_67 )
{
T_3 * V_78 = V_67 -> V_8 ;
unsigned int * V_79 = V_67 -> V_6 ;
T_1 V_80 , V_68 ;
T_2 * V_63 ;
if ( * V_79 == 0 )
return 0 ;
V_63 = F_16 ( V_60 , 4 ) ;
if ( F_9 ( V_63 == NULL ) )
return - V_69 ;
V_80 = F_17 ( V_63 ) ;
F_2 ( L_12 , V_80 ) ;
if ( V_80 > V_81 )
V_80 = V_81 ;
V_63 = F_16 ( V_60 , 4 * V_80 ) ;
if ( F_9 ( V_63 == NULL ) )
return - V_69 ;
if ( V_80 > * V_79 )
V_80 = * V_79 ;
for ( V_68 = 0 ; V_68 < V_80 ; V_68 ++ ) {
V_78 [ V_68 ] = F_17 ( V_63 ++ ) ;
F_2 ( L_13 , V_68 , V_78 [ V_68 ] ) ;
}
* V_79 = V_68 ;
return 0 ;
}
static int F_24 ( struct V_65 * V_66 ,
struct V_59 * V_60 ,
struct V_3 * V_67 )
{
int V_31 ;
V_31 = F_21 ( V_60 , V_67 ) ;
if ( F_9 ( V_31 != 0 || V_67 -> V_44 != 0 ) )
return V_31 ;
V_31 = F_22 ( V_60 , V_67 ) ;
if ( F_9 ( V_31 != 0 ) ) {
V_67 -> V_44 = - V_82 ;
return 0 ;
}
return F_23 ( V_60 , V_67 ) ;
}
