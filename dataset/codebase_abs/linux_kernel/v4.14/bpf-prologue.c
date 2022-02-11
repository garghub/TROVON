static inline int
F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_2 - V_2 -> V_3 ;
}
static int
F_2 ( struct V_4 V_5 , struct V_1 * V_2 )
{
if ( ! V_2 -> V_2 )
return - V_6 ;
if ( V_2 -> V_2 + 1 >= V_2 -> V_7 ) {
F_3 ( L_1 ) ;
V_2 -> V_2 = NULL ;
return - V_6 ;
}
* ( V_2 -> V_2 ) ++ = V_5 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_2 || V_2 -> V_2 >= V_2 -> V_7 )
return - V_6 ;
return 0 ;
}
static int
F_5 ( const char * type )
{
int V_8 = type ? atoi ( & type [ 1 ] ) : 64 ;
switch ( V_8 ) {
case 8 :
return V_9 ;
case 16 :
return V_10 ;
case 32 :
return V_11 ;
case 64 :
default:
return V_12 ;
}
}
static const char *
F_6 ( int V_13 )
{
switch ( V_13 ) {
case V_9 :
return L_2 ;
case V_10 :
return L_3 ;
case V_11 :
return L_4 ;
case V_12 :
return L_5 ;
default:
return L_6 ;
}
}
static int
F_7 ( struct V_1 * V_2 , int V_14 ,
const char * V_15 , int V_16 )
{
int V_17 = F_8 ( V_15 ) ;
if ( V_17 < 0 ) {
F_3 ( L_7 ,
V_15 ) ;
return V_17 ;
}
F_9 ( F_10 ( V_12 , V_16 , V_14 , V_17 ) , V_2 ) ;
return F_4 ( V_2 ) ;
}
static int
F_11 ( struct V_1 * V_2 ,
int V_18 ,
int V_19 ,
long V_17 )
{
if ( V_18 != V_20 )
F_9 ( F_12 ( V_20 , V_18 ) , V_2 ) ;
if ( V_17 )
F_9 ( F_13 ( V_21 , V_20 , V_17 ) , V_2 ) ;
F_9 ( F_13 ( V_22 , V_23 , V_24 ) , V_2 ) ;
if ( V_19 != V_25 )
F_9 ( F_12 ( V_25 , V_19 ) , V_2 ) ;
F_9 ( F_14 ( V_26 ) , V_2 ) ;
F_9 ( F_15 ( V_27 , V_28 , 0 , V_29 ) ,
V_2 ) ;
return F_4 ( V_2 ) ;
}
static int
F_16 ( struct V_1 * V_2 ,
struct V_30 * args , int V_31 )
{
int V_32 , V_33 = 0 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_33 = F_7 ( V_2 , V_34 , args [ V_32 ] . V_35 ,
V_36 + V_32 ) ;
if ( V_33 )
goto V_37;
}
return F_4 ( V_2 ) ;
V_37:
return V_33 ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_30 * args , int V_31 )
{
int V_33 , V_32 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
struct V_30 * V_38 = & args [ V_32 ] ;
const char * V_15 = V_38 -> V_35 ;
struct V_39 * V_40 = NULL ;
int V_41 = ( V_32 + 1 ) * - 8 ;
F_18 ( L_8 ,
V_32 , V_15 ) ;
V_33 = F_7 ( V_2 , V_42 , V_15 ,
V_20 ) ;
if ( V_33 ) {
F_3 ( L_9 ,
V_15 ) ;
goto V_37;
}
F_9 ( F_12 ( V_43 , V_44 ) , V_2 ) ;
F_9 ( F_13 ( V_21 , V_43 , V_41 ) , V_2 ) ;
F_9 ( F_19 ( V_12 , V_44 , V_20 ,
V_41 ) , V_2 ) ;
V_40 = V_38 -> V_40 ;
while ( V_40 ) {
F_18 ( L_10 ,
V_32 , V_40 -> V_17 ) ;
V_33 = F_11 ( V_2 , V_45 , V_43 ,
V_40 -> V_17 ) ;
if ( V_33 ) {
F_3 ( L_11 ) ;
goto V_37;
}
V_40 = V_40 -> V_46 ;
if ( V_40 )
F_9 ( F_10 ( V_12 , V_20 ,
V_44 , V_41 ) , V_2 ) ;
}
}
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
int V_13 = ( args [ V_32 ] . V_40 ) ? F_5 ( args [ V_32 ] . type ) : V_12 ;
F_18 ( L_12 ,
V_32 , F_6 ( V_13 ) ) ;
F_9 ( F_10 ( V_13 , V_36 + V_32 ,
V_44 , - V_24 * ( V_32 + 1 ) ) , V_2 ) ;
}
F_9 ( F_15 ( V_47 , V_28 , 0 , V_48 ) , V_2 ) ;
return F_4 ( V_2 ) ;
V_37:
return V_33 ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_4 * V_49 ,
struct V_4 * V_50 , struct V_4 * V_51 )
{
struct V_4 * V_52 ;
if ( F_4 ( V_2 ) )
return - V_6 ;
for ( V_52 = V_2 -> V_3 ; V_52 < V_2 -> V_2 ; V_52 ++ ) {
struct V_4 * V_53 ;
T_1 V_54 = F_21 ( V_52 -> V_55 ) ;
T_1 V_56 ;
if ( V_54 != V_57 )
continue;
V_56 = F_22 ( V_52 -> V_55 ) ;
if ( V_56 == V_58 )
continue;
switch ( V_52 -> V_59 ) {
case V_29 :
V_53 = V_49 ;
break;
case V_48 :
V_53 = V_50 ;
break;
case V_60 :
V_53 = V_51 ;
break;
default:
F_3 ( L_13 ) ;
return - V_61 ;
}
V_52 -> V_59 = V_53 - ( V_52 + 1 ) ;
}
return 0 ;
}
int F_23 ( struct V_30 * args , int V_31 ,
struct V_4 * V_62 , T_2 * V_63 ,
T_2 V_64 )
{
struct V_4 * V_50 = NULL ;
struct V_4 * V_49 = NULL ;
struct V_4 * V_51 = NULL ;
struct V_1 V_2 ;
bool V_65 = true ;
int V_33 = 0 , V_32 ;
if ( ! V_62 || ! V_63 )
return - V_66 ;
if ( V_64 > V_67 )
V_64 = V_67 ;
V_2 . V_3 = V_62 ;
V_2 . V_7 = V_62 + V_64 ;
V_2 . V_2 = V_62 ;
if ( ! V_31 ) {
F_9 ( F_13 ( V_22 , V_68 , 0 ) ,
& V_2 ) ;
if ( F_4 ( & V_2 ) )
goto V_37;
* V_63 = F_1 ( & V_2 ) ;
return 0 ;
}
if ( V_31 > V_69 ) {
F_24 ( L_14 ,
V_31 - V_69 ) ;
V_31 = V_69 ;
}
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
struct V_39 * V_40 = args [ V_32 ] . V_40 ;
if ( args [ V_32 ] . V_35 [ 0 ] == '@' ) {
F_3 ( L_15 ,
args [ V_32 ] . V_35 , V_40 ? V_40 -> V_17 : 0 ) ;
return - V_70 ;
}
while ( V_40 ) {
V_65 = false ;
#ifdef F_25
#define F_26 ((1LL << 31) - 1)
#define F_27 ((1LL << 31) * -1)
if ( V_40 -> V_17 > F_26 ||
V_40 -> V_17 < F_27 ) {
F_3 ( L_16 ,
V_40 -> V_17 ) ;
return - V_71 ;
}
#endif
V_40 = V_40 -> V_46 ;
}
}
F_18 ( L_17 ) ;
if ( V_65 ) {
F_18 ( L_18 ) ;
V_33 = F_16 ( & V_2 , args , V_31 ) ;
if ( V_33 )
goto V_37;
} else {
F_18 ( L_19 ) ;
F_9 ( F_12 ( V_42 , V_25 ) , & V_2 ) ;
V_33 = F_17 ( & V_2 , args , V_31 ) ;
if ( V_33 )
goto V_37;
V_49 = V_2 . V_2 ;
F_9 ( F_13 ( V_22 , V_68 , 1 ) ,
& V_2 ) ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ )
F_9 ( F_13 ( V_22 ,
V_36 + V_32 ,
0 ) ,
& V_2 ) ;
F_9 ( F_15 ( V_47 , V_28 , 0 , V_60 ) ,
& V_2 ) ;
}
V_50 = V_2 . V_2 ;
F_9 ( F_13 ( V_22 , V_68 , 0 ) , & V_2 ) ;
V_51 = V_2 . V_2 ;
if ( ! V_65 ) {
F_9 ( F_12 ( V_25 , V_42 ) , & V_2 ) ;
V_33 = F_20 ( & V_2 , V_49 , V_50 ,
V_51 ) ;
if ( V_33 )
goto V_37;
}
V_33 = F_4 ( & V_2 ) ;
if ( V_33 )
goto V_37;
* V_63 = F_1 ( & V_2 ) ;
return 0 ;
V_37:
return V_33 ;
}
