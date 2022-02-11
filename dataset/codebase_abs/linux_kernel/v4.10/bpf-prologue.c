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
F_5 ( struct V_1 * V_2 , int V_8 ,
const char * V_9 , int V_10 )
{
int V_11 = F_6 ( V_9 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 ,
V_9 ) ;
return V_11 ;
}
F_7 ( F_8 ( V_12 , V_10 , V_8 , V_11 ) , V_2 ) ;
return F_4 ( V_2 ) ;
}
static int
F_9 ( struct V_1 * V_2 ,
int V_13 ,
int V_14 ,
long V_11 )
{
if ( V_13 != V_15 )
F_7 ( F_10 ( V_15 , V_13 ) , V_2 ) ;
if ( V_11 )
F_7 ( F_11 ( V_16 , V_15 , V_11 ) , V_2 ) ;
F_7 ( F_11 ( V_17 , V_18 , V_19 ) , V_2 ) ;
if ( V_14 != V_20 )
F_7 ( F_10 ( V_20 , V_14 ) , V_2 ) ;
F_7 ( F_12 ( V_21 ) , V_2 ) ;
F_7 ( F_13 ( V_22 , V_23 , 0 , V_24 ) ,
V_2 ) ;
return F_4 ( V_2 ) ;
}
static int
F_14 ( struct V_1 * V_2 ,
struct V_25 * args , int V_26 )
{
int V_27 , V_28 = 0 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
V_28 = F_5 ( V_2 , V_29 , args [ V_27 ] . V_30 ,
V_31 + V_27 ) ;
if ( V_28 )
goto V_32;
}
return F_4 ( V_2 ) ;
V_32:
return V_28 ;
}
static int
F_15 ( struct V_1 * V_2 ,
struct V_25 * args , int V_26 )
{
int V_28 , V_27 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
struct V_25 * V_33 = & args [ V_27 ] ;
const char * V_9 = V_33 -> V_30 ;
struct V_34 * V_35 = NULL ;
int V_36 = ( V_27 + 1 ) * - 8 ;
F_16 ( L_3 ,
V_27 , V_9 ) ;
V_28 = F_5 ( V_2 , V_37 , V_9 ,
V_15 ) ;
if ( V_28 ) {
F_3 ( L_4 ,
V_9 ) ;
goto V_32;
}
F_7 ( F_10 ( V_38 , V_39 ) , V_2 ) ;
F_7 ( F_11 ( V_16 , V_38 , V_36 ) , V_2 ) ;
F_7 ( F_17 ( V_12 , V_39 , V_15 ,
V_36 ) , V_2 ) ;
V_35 = V_33 -> V_35 ;
while ( V_35 ) {
F_16 ( L_5 ,
V_27 , V_35 -> V_11 ) ;
V_28 = F_9 ( V_2 , V_40 , V_38 ,
V_35 -> V_11 ) ;
if ( V_28 ) {
F_3 ( L_6 ) ;
goto V_32;
}
V_35 = V_35 -> V_41 ;
if ( V_35 )
F_7 ( F_8 ( V_12 , V_15 ,
V_39 , V_36 ) , V_2 ) ;
}
}
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
F_7 ( F_8 ( V_12 , V_31 + V_27 ,
V_39 , - V_19 * ( V_27 + 1 ) ) , V_2 ) ;
F_7 ( F_13 ( V_42 , V_23 , 0 , V_43 ) , V_2 ) ;
return F_4 ( V_2 ) ;
V_32:
return V_28 ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_4 * V_44 ,
struct V_4 * V_45 , struct V_4 * V_46 )
{
struct V_4 * V_47 ;
if ( F_4 ( V_2 ) )
return - V_6 ;
for ( V_47 = V_2 -> V_3 ; V_47 < V_2 -> V_2 ; V_47 ++ ) {
struct V_4 * V_48 ;
T_1 V_49 = F_19 ( V_47 -> V_50 ) ;
T_1 V_51 ;
if ( V_49 != V_52 )
continue;
V_51 = F_20 ( V_47 -> V_50 ) ;
if ( V_51 == V_53 )
continue;
switch ( V_47 -> V_54 ) {
case V_24 :
V_48 = V_44 ;
break;
case V_43 :
V_48 = V_45 ;
break;
case V_55 :
V_48 = V_46 ;
break;
default:
F_3 ( L_7 ) ;
return - V_56 ;
}
V_47 -> V_54 = V_48 - ( V_47 + 1 ) ;
}
return 0 ;
}
int F_21 ( struct V_25 * args , int V_26 ,
struct V_4 * V_57 , T_2 * V_58 ,
T_2 V_59 )
{
struct V_4 * V_45 = NULL ;
struct V_4 * V_44 = NULL ;
struct V_4 * V_46 = NULL ;
struct V_1 V_2 ;
bool V_60 = true ;
int V_28 = 0 , V_27 ;
if ( ! V_57 || ! V_58 )
return - V_61 ;
if ( V_59 > V_62 )
V_59 = V_62 ;
V_2 . V_3 = V_57 ;
V_2 . V_7 = V_57 + V_59 ;
V_2 . V_2 = V_57 ;
if ( ! V_26 ) {
F_7 ( F_11 ( V_17 , V_63 , 0 ) ,
& V_2 ) ;
if ( F_4 ( & V_2 ) )
goto V_32;
* V_58 = F_1 ( & V_2 ) ;
return 0 ;
}
if ( V_26 > V_64 ) {
F_22 ( L_8 ,
V_26 - V_64 ) ;
V_26 = V_64 ;
}
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
struct V_34 * V_35 = args [ V_27 ] . V_35 ;
if ( args [ V_27 ] . V_30 [ 0 ] == '@' ) {
F_3 ( L_9 ,
args [ V_27 ] . V_30 , V_35 ? V_35 -> V_11 : 0 ) ;
return - V_65 ;
}
while ( V_35 ) {
V_60 = false ;
#ifdef F_23
#define F_24 ((1LL << 31) - 1)
#define F_25 ((1LL << 31) * -1)
if ( V_35 -> V_11 > F_24 ||
V_35 -> V_11 < F_25 ) {
F_3 ( L_10 ,
V_35 -> V_11 ) ;
return - V_66 ;
}
#endif
V_35 = V_35 -> V_41 ;
}
}
F_16 ( L_11 ) ;
if ( V_60 ) {
F_16 ( L_12 ) ;
V_28 = F_14 ( & V_2 , args , V_26 ) ;
if ( V_28 )
goto V_32;
} else {
F_16 ( L_13 ) ;
F_7 ( F_10 ( V_37 , V_20 ) , & V_2 ) ;
V_28 = F_15 ( & V_2 , args , V_26 ) ;
if ( V_28 )
goto V_32;
V_44 = V_2 . V_2 ;
F_7 ( F_11 ( V_17 , V_63 , 1 ) ,
& V_2 ) ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
F_7 ( F_11 ( V_17 ,
V_31 + V_27 ,
0 ) ,
& V_2 ) ;
F_7 ( F_13 ( V_42 , V_23 , 0 , V_55 ) ,
& V_2 ) ;
}
V_45 = V_2 . V_2 ;
F_7 ( F_11 ( V_17 , V_63 , 0 ) , & V_2 ) ;
V_46 = V_2 . V_2 ;
if ( ! V_60 ) {
F_7 ( F_10 ( V_20 , V_37 ) , & V_2 ) ;
V_28 = F_18 ( & V_2 , V_44 , V_45 ,
V_46 ) ;
if ( V_28 )
goto V_32;
}
V_28 = F_4 ( & V_2 ) ;
if ( V_28 )
goto V_32;
* V_58 = F_1 ( & V_2 ) ;
return 0 ;
V_32:
return V_28 ;
}
