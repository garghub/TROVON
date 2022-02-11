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
. V_16 = & V_17 ,
. V_18 = V_2 -> V_18 ,
. V_19 = V_2 -> V_20 ,
. V_21 = V_2 -> V_22 ,
. V_23 = V_2 -> V_24 ,
. V_25 = & V_26 ,
. V_27 = V_2 -> V_27 ,
. V_28 = V_29 ,
} ;
struct V_30 * V_31 ;
int V_32 ;
F_2 ( L_1 ,
( V_2 -> V_24 ? V_2 -> V_24 : L_2 ) ,
V_2 -> V_13 ) ;
if ( V_2 -> V_33 )
args . V_34 |= V_35 ;
V_31 = F_3 ( & args ) ;
if ( F_4 ( V_31 ) )
goto V_36;
if ( V_2 -> V_27 == V_37 )
V_11 . V_38 = & V_31 -> V_39 [ V_40 ] ;
else
V_11 . V_38 = & V_31 -> V_39 [ V_41 ] ;
V_32 = F_5 ( V_31 , & V_11 , 0 ) ;
F_6 ( V_31 ) ;
if ( V_32 < 0 )
goto V_42;
if ( V_4 . V_43 != 0 )
goto V_44;
F_2 ( L_3 ) ;
V_32 = 0 ;
V_45:
return V_32 ;
V_36:
V_32 = F_7 ( V_31 ) ;
F_2 ( L_4 , V_32 ) ;
goto V_45;
V_42:
F_2 ( L_5 , V_32 ) ;
goto V_45;
V_44:
F_2 ( L_6 , V_4 . V_43 ) ;
V_32 = V_4 . V_43 ;
goto V_45;
}
void F_8 ( const struct V_1 * V_2 )
{
static const struct V_46 V_47 = {
. V_48 = 1 * V_49 ,
. V_50 = 3 * V_49 ,
. V_51 = 2 ,
} ;
struct V_15 args = {
. V_16 = & V_17 ,
. V_18 = V_52 ,
. V_19 = V_2 -> V_20 ,
. V_21 = V_2 -> V_22 ,
. V_53 = & V_47 ,
. V_23 = V_2 -> V_24 ,
. V_25 = & V_26 ,
. V_27 = V_2 -> V_27 ,
. V_28 = V_29 ,
. V_34 = V_54 ,
} ;
struct V_10 V_11 = {
. V_12 = V_2 -> V_13 ,
} ;
struct V_30 * V_55 ;
int V_32 ;
if ( V_2 -> V_33 )
args . V_34 |= V_35 ;
V_55 = F_3 ( & args ) ;
if ( F_4 ( V_55 ) )
goto V_36;
F_2 ( L_7 ,
( V_2 -> V_24 ? V_2 -> V_24 : L_2 ) , V_2 -> V_13 ) ;
if ( V_2 -> V_27 == V_37 )
V_11 . V_38 = & V_55 -> V_39 [ V_56 ] ;
else
V_11 . V_38 = & V_55 -> V_39 [ V_57 ] ;
V_32 = F_5 ( V_55 , & V_11 , 0 ) ;
F_6 ( V_55 ) ;
if ( F_9 ( V_32 < 0 ) )
goto V_42;
return;
V_36:
F_2 ( L_8 ,
F_7 ( V_55 ) ) ;
return;
V_42:
F_2 ( L_9 , V_32 ) ;
}
static void F_10 ( struct V_58 * V_59 , const char * V_60 )
{
const T_1 V_61 = strlen ( V_60 ) ;
T_2 * V_62 ;
F_11 ( V_61 > V_63 ) ;
V_62 = F_12 ( V_59 , 4 + V_61 ) ;
F_13 ( V_62 , V_60 , V_61 ) ;
}
static void F_14 ( struct V_64 * V_65 , struct V_58 * V_59 ,
const char * V_13 )
{
F_10 ( V_59 , V_13 ) ;
}
static int F_15 ( struct V_58 * V_59 , struct V_3 * V_66 )
{
unsigned int V_67 ;
T_1 V_32 ;
T_2 * V_62 ;
V_62 = F_16 ( V_59 , 4 ) ;
if ( F_9 ( V_62 == NULL ) )
return - V_68 ;
V_32 = F_17 ( V_62 ) ;
for ( V_67 = 0 ; V_67 < F_18 ( V_69 ) ; V_67 ++ ) {
if ( V_69 [ V_67 ] . V_32 == V_32 ) {
V_66 -> V_43 = V_69 [ V_67 ] . V_43 ;
return 0 ;
}
}
F_2 ( L_10 , V_32 ) ;
V_66 -> V_43 = - V_70 ;
return 0 ;
}
static int F_19 ( struct V_58 * V_59 , struct V_3 * V_66 )
{
struct V_71 * V_5 = V_66 -> V_5 ;
T_2 * V_62 ;
V_62 = F_16 ( V_59 , V_72 ) ;
if ( F_9 ( V_62 == NULL ) )
return - V_68 ;
V_5 -> V_73 = V_72 ;
memcpy ( V_5 -> V_74 , V_62 , V_72 ) ;
return 0 ;
}
static int F_20 ( struct V_64 * V_65 ,
struct V_58 * V_59 ,
struct V_3 * V_66 )
{
int V_32 ;
V_32 = F_15 ( V_59 , V_66 ) ;
if ( F_9 ( V_32 != 0 || V_66 -> V_43 != 0 ) )
return V_32 ;
return F_19 ( V_59 , V_66 ) ;
}
static int F_21 ( struct V_58 * V_59 , struct V_3 * V_66 )
{
unsigned int V_67 ;
T_1 V_32 ;
T_2 * V_62 ;
V_62 = F_16 ( V_59 , 4 ) ;
if ( F_9 ( V_62 == NULL ) )
return - V_68 ;
V_32 = F_17 ( V_62 ) ;
for ( V_67 = 0 ; V_67 < F_18 ( V_75 ) ; V_67 ++ ) {
if ( V_75 [ V_67 ] . V_32 == V_32 ) {
V_66 -> V_43 = V_75 [ V_67 ] . V_43 ;
return 0 ;
}
}
F_2 ( L_11 , V_32 ) ;
V_66 -> V_43 = - V_70 ;
return 0 ;
}
static int F_22 ( struct V_58 * V_59 , struct V_3 * V_66 )
{
struct V_71 * V_5 = V_66 -> V_5 ;
T_1 V_73 ;
T_2 * V_62 ;
V_62 = F_16 ( V_59 , 4 ) ;
if ( F_9 ( V_62 == NULL ) )
return - V_68 ;
V_73 = F_17 ( V_62 ) ;
if ( V_73 > V_76 || V_73 == 0 )
return - V_68 ;
V_62 = F_16 ( V_59 , V_73 ) ;
if ( F_9 ( V_62 == NULL ) )
return - V_68 ;
V_5 -> V_73 = V_73 ;
memcpy ( V_5 -> V_74 , V_62 , V_73 ) ;
return 0 ;
}
static int F_23 ( struct V_58 * V_59 , struct V_3 * V_66 )
{
T_3 * V_77 = V_66 -> V_8 ;
unsigned int * V_78 = V_66 -> V_6 ;
T_1 V_79 , V_67 ;
T_2 * V_62 ;
if ( * V_78 == 0 )
return 0 ;
V_62 = F_16 ( V_59 , 4 ) ;
if ( F_9 ( V_62 == NULL ) )
return - V_68 ;
V_79 = F_17 ( V_62 ) ;
F_2 ( L_12 , V_79 ) ;
if ( V_79 > V_80 )
V_79 = V_80 ;
V_62 = F_16 ( V_59 , 4 * V_79 ) ;
if ( F_9 ( V_62 == NULL ) )
return - V_68 ;
if ( V_79 > * V_78 )
V_79 = * V_78 ;
for ( V_67 = 0 ; V_67 < V_79 ; V_67 ++ ) {
V_77 [ V_67 ] = F_17 ( V_62 ++ ) ;
F_2 ( L_13 , V_67 , V_77 [ V_67 ] ) ;
}
* V_78 = V_67 ;
return 0 ;
}
static int F_24 ( struct V_64 * V_65 ,
struct V_58 * V_59 ,
struct V_3 * V_66 )
{
int V_32 ;
V_32 = F_21 ( V_59 , V_66 ) ;
if ( F_9 ( V_32 != 0 || V_66 -> V_43 != 0 ) )
return V_32 ;
V_32 = F_22 ( V_59 , V_66 ) ;
if ( F_9 ( V_32 != 0 ) ) {
V_66 -> V_43 = - V_81 ;
return 0 ;
}
return F_23 ( V_59 , V_66 ) ;
}
