static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_5 ;
struct V_4 * V_7 = & V_2 -> V_6 . V_7 ;
return V_5 -> V_8 +
F_2 ( ( V_9 ) ( V_3 - V_7 -> V_8 ) *
( V_5 -> V_10 - V_5 -> V_8 ) ,
V_7 -> V_10 - V_7 -> V_8 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_11 )
{
struct V_4 * V_5 = & V_2 -> V_6 . V_5 ;
struct V_4 * V_7 = & V_2 -> V_6 . V_7 ;
if ( V_11 < 0 ) {
F_4 ( L_1 ) ;
return V_11 ;
}
if ( V_11 < V_5 -> V_8 )
return V_7 -> V_8 ;
if ( V_11 > V_5 -> V_10 )
return V_7 -> V_10 ;
return V_7 -> V_8 +
F_2 ( ( V_9 ) ( V_11 - V_5 -> V_8 ) *
( V_7 -> V_10 - V_7 -> V_8 ) ,
V_5 -> V_10 - V_5 -> V_8 ) ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_11 = F_7 ( V_2 -> V_14 ) ;
return F_3 ( V_2 , V_11 ) ;
}
static int F_8 ( struct V_12 * V_13 ,
int V_15 , int V_16 ,
unsigned int * V_17 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
struct V_18 * V_14 = V_2 -> V_14 ;
int V_19 = F_7 ( V_14 ) ;
int V_20 = F_3 ( V_2 , V_19 ) ;
int V_21 ;
if ( V_15 >= V_20 || ! V_2 -> V_22 )
return F_9 (
V_14 ,
F_1 ( V_2 , V_15 ) ,
F_1 ( V_2 , V_16 ) ) ;
while ( V_20 > V_15 ) {
int V_23 = ( V_20 * V_2 -> V_22 ) / 100 ;
int V_24 ;
int V_25 ;
int V_26 ;
if ( V_23 == 0 )
V_23 = 1 ;
V_24 = F_10 ( int , V_15 , V_20 - V_23 ) ;
V_25 = F_1 ( V_2 , V_24 ) ;
V_21 = F_9 ( V_14 ,
V_25 ,
V_25 ) ;
if ( V_21 )
goto V_27;
V_26 = F_11 ( V_20 - V_24 , V_2 -> V_28 ) ;
F_12 ( V_26 , V_26 + F_11 ( V_26 , 10 ) ) ;
V_20 = V_24 ;
}
return 0 ;
V_27:
F_9 ( V_14 , V_19 , V_19 ) ;
return V_21 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
return V_2 -> V_29 ;
}
static int F_14 ( struct V_12 * V_13 ,
unsigned int V_17 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
struct V_18 * V_14 = V_2 -> V_14 ;
unsigned int V_30 = V_2 -> V_29 ;
int V_21 ;
if ( V_17 >= V_13 -> V_31 -> V_32 )
return - V_33 ;
if ( V_17 >= V_2 -> V_29 || ! V_2 -> V_22 ) {
V_21 = F_9 ( V_14 ,
V_2 -> V_34 [ V_17 ] . V_5 ,
V_2 -> V_34 [ V_17 ] . V_5 ) ;
if ( ! V_21 )
V_2 -> V_29 = V_17 ;
return V_21 ;
}
while ( V_2 -> V_29 != V_17 ) {
unsigned int V_35 ;
int V_26 ;
if ( V_17 >= V_2 -> V_34 [ V_2 -> V_29 ] . V_36 )
V_35 = V_17 ;
else
V_35 = V_2 -> V_34 [ V_2 -> V_29 ] . V_36 ;
V_21 = F_9 ( V_14 ,
V_2 -> V_34 [ V_35 ] . V_5 ,
V_2 -> V_34 [ V_35 ] . V_5 ) ;
if ( V_21 ) {
F_15 ( & V_13 -> V_37 ,
L_2 ,
V_2 -> V_34 [ V_35 ] . V_5 ) ;
goto V_27;
}
V_2 -> V_29 = V_35 ;
V_26 = F_11 ( V_2 -> V_34 [ V_2 -> V_29 ] . V_7 -
V_2 -> V_34 [ V_35 ] . V_7 ,
V_2 -> V_28 ) ;
F_12 ( V_26 , V_26 + F_11 ( V_26 , 10 ) ) ;
}
return 0 ;
V_27:
if ( V_2 -> V_29 != V_30 ) {
if ( ! F_9 ( V_14 ,
V_2 -> V_34 [ V_30 ] . V_5 ,
V_2 -> V_34 [ V_30 ] . V_5 ) )
V_2 -> V_29 = V_30 ;
else
F_16 ( & V_13 -> V_37 ,
L_3 ) ;
}
return V_21 ;
}
static int F_17 ( struct V_12 * V_13 ,
unsigned int V_17 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
if ( V_17 >= V_13 -> V_31 -> V_32 )
return - V_33 ;
return V_2 -> V_34 [ V_17 ] . V_7 ;
}
static int F_18 ( struct V_38 * V_39 ,
struct V_1 * V_2 )
{
int V_21 ;
struct V_40 * V_41 = V_39 -> V_37 . V_42 ;
T_1 V_43 ;
T_1 V_44 [ 2 ] ;
V_2 -> V_14 = F_19 ( & V_39 -> V_37 , L_4 ) ;
if ( F_20 ( V_2 -> V_14 ) )
return F_21 ( V_2 -> V_14 ) ;
V_21 = F_22 ( V_41 , L_5 , & V_43 ) ;
if ( ! V_21 ) {
V_2 -> V_22 = V_43 ;
if ( V_2 -> V_22 > 100 ) {
F_15 ( & V_39 -> V_37 ,
L_6 ,
V_2 -> V_22 ) ;
return - V_33 ;
}
}
V_21 = F_22 ( V_41 , L_7 , & V_43 ) ;
if ( ! V_21 ) {
V_2 -> V_28 = V_43 ;
if ( V_2 -> V_28 == 0 ) {
F_15 ( & V_39 -> V_37 ,
L_8 ) ;
return - V_33 ;
} else if ( V_2 -> V_28 > V_45 ) {
F_15 ( & V_39 -> V_37 , L_9 ,
V_2 -> V_28 ) ;
return - V_33 ;
}
}
if ( V_2 -> V_22 && ! V_2 -> V_28 ) {
F_15 ( & V_39 -> V_37 ,
L_10 ) ;
return - V_33 ;
}
V_21 = F_22 ( V_41 , L_11 , & V_43 ) ;
if ( V_21 ) {
F_15 ( & V_39 -> V_37 ,
L_12 , V_21 ) ;
return V_21 ;
}
V_2 -> V_6 . V_7 . V_8 = V_43 ;
V_21 = F_22 ( V_41 , L_13 , & V_43 ) ;
if ( V_21 ) {
F_15 ( & V_39 -> V_37 ,
L_14 , V_21 ) ;
return V_21 ;
}
V_2 -> V_6 . V_7 . V_10 = V_43 ;
V_21 = F_23 ( V_41 , L_15 , V_44 ,
2 ) ;
if ( V_21 ) {
F_15 ( & V_39 -> V_37 , L_16 ,
V_21 ) ;
return V_21 ;
}
if ( V_44 [ 0 ] >= V_44 [ 1 ] ) {
F_15 ( & V_39 -> V_37 , L_17 ,
V_44 [ 0 ] , V_44 [ 1 ] ) ;
return - V_33 ;
}
V_2 -> V_6 . V_5 . V_8 = V_44 [ 0 ] ;
V_2 -> V_6 . V_5 . V_10 = V_44 [ 1 ] ;
return 0 ;
}
static int F_24 ( const void * V_46 , const void * V_47 )
{
const struct V_48 * V_49 = V_46 ;
const struct V_48 * V_50 = V_47 ;
return V_49 -> V_5 - V_50 -> V_5 ;
}
static int F_25 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_26 ( V_39 ) ;
struct V_51 * V_52 = & V_2 -> V_31 ;
struct V_18 * V_14 = V_2 -> V_14 ;
struct V_4 * V_44 = & V_2 -> V_6 . V_5 ;
int V_32 ;
int V_11 ;
int V_53 , V_54 ;
V_32 = F_27 ( V_14 ) ;
V_52 -> V_32 = V_32 ;
for ( V_53 = 0 ; V_53 < V_32 ; V_53 ++ ) {
V_11 = F_28 ( V_14 , V_53 ) ;
if ( V_11 < V_44 -> V_8 ||
V_11 > V_44 -> V_10 ) {
V_52 -> V_32 -- ;
continue;
}
}
if ( V_52 -> V_32 == 0 ) {
F_15 ( & V_39 -> V_37 , L_18 ) ;
return - V_33 ;
}
V_2 -> V_34 = F_29 ( & V_39 -> V_37 , V_52 -> V_32 ,
sizeof( struct V_48 ) ,
V_55 ) ;
if ( ! V_2 -> V_34 )
return - V_56 ;
for ( V_53 = 0 , V_54 = 0 ; V_53 < V_32 ; V_53 ++ ) {
V_11 = F_28 ( V_14 , V_53 ) ;
if ( V_11 < V_44 -> V_8 ||
V_11 > V_44 -> V_10 )
continue;
V_2 -> V_34 [ V_54 ] . V_5 = V_11 ;
V_2 -> V_34 [ V_54 ] . V_7 =
F_3 ( V_2 , V_11 ) ;
V_54 ++ ;
}
F_30 ( V_2 -> V_34 , V_52 -> V_32 ,
sizeof( struct V_48 ) , F_24 ,
NULL ) ;
for ( V_53 = V_52 -> V_32 - 1 ; V_53 > 0 ; V_53 -- ) {
int V_57 ;
int V_58 = ( V_2 -> V_34 [ V_53 ] . V_7 *
( 100 - V_2 -> V_22 ) ) / 100 ;
for ( V_57 = 0 ; V_57 < V_53 ; V_57 ++ ) {
if ( V_2 -> V_34 [ V_57 ] . V_7 >= V_58 ) {
V_2 -> V_34 [ V_53 ] . V_36 = V_57 ;
break;
}
}
if ( V_57 == V_53 ) {
F_16 ( & V_39 -> V_37 , L_19 ,
V_2 -> V_34 [ V_53 ] . V_7 ) ;
V_2 -> V_34 [ V_53 ] . V_36 = V_53 - 1 ;
}
}
return 0 ;
}
static int F_31 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_21 = F_32 ( V_2 -> V_14 ) ;
if ( ! V_21 )
V_2 -> V_59 = true ;
return V_21 ;
}
static int F_33 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_21 = F_34 ( V_2 -> V_14 ) ;
if ( ! V_21 )
V_2 -> V_59 = false ;
return V_21 ;
}
static int F_35 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
return V_2 -> V_59 ;
}
static int F_36 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_37 . V_42 ;
struct V_1 * V_2 ;
const struct V_60 * V_61 ;
struct V_51 * V_52 ;
struct V_62 V_63 = { } ;
struct V_4 * V_44 ;
int V_11 ;
int V_21 ;
V_2 = F_37 ( & V_39 -> V_37 , sizeof( struct V_1 ) ,
V_55 ) ;
if ( ! V_2 )
return - V_56 ;
F_38 ( V_39 , V_2 ) ;
V_21 = F_18 ( V_39 , V_2 ) ;
if ( V_21 )
return V_21 ;
V_44 = & V_2 -> V_6 . V_5 ;
V_52 = & V_2 -> V_31 ;
V_52 -> V_64 = L_20 ;
V_52 -> type = V_65 ;
V_52 -> V_66 = V_67 ;
if ( ( F_39 ( V_2 -> V_14 ) == 1 ) ||
( F_27 ( V_2 -> V_14 ) == - V_33 ) ) {
V_52 -> V_68 = true ;
V_52 -> V_69 = & V_70 ;
} else {
V_52 -> V_69 = & V_71 ;
}
V_61 = F_40 ( & V_39 -> V_37 , V_41 , V_52 ) ;
if ( ! V_61 )
return - V_56 ;
V_63 . V_42 = V_41 ;
V_63 . V_37 = & V_39 -> V_37 ;
V_63 . V_72 = V_2 ;
V_63 . V_61 = V_61 ;
if ( ! V_52 -> V_68 ) {
V_21 = F_25 ( V_39 ) ;
if ( V_21 )
return V_21 ;
V_11 = F_7 ( V_2 -> V_14 ) ;
if ( V_11 < 0 ) {
F_15 ( & V_39 -> V_37 , L_21 ) ;
return V_11 ;
}
if ( V_11 < V_44 -> V_8 ) {
V_2 -> V_29 = 0 ;
} else if ( V_11 > V_44 -> V_10 ) {
V_2 -> V_29 = V_52 -> V_32 - 1 ;
} else {
int V_53 ;
for ( V_53 = 0 ; V_53 < V_52 -> V_32 ; V_53 ++ ) {
if ( V_11 == V_2 -> V_34 [ V_53 ] . V_5 ) {
V_2 -> V_29 = V_53 ;
break;
}
}
}
}
V_2 -> V_13 = F_41 ( & V_39 -> V_37 , V_52 , & V_63 ) ;
if ( F_20 ( V_2 -> V_13 ) ) {
V_21 = F_21 ( V_2 -> V_13 ) ;
F_15 ( & V_39 -> V_37 , L_22 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
