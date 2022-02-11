static inline union V_1 *
F_1 ( T_1 V_2 , int V_3 , T_2 type ,
union V_1 * V_4 )
{
F_2 ( ! V_2 ) ;
return F_3 ( V_2 , V_5 ,
V_6 ,
V_3 , V_4 , type ) ;
}
static T_3 F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_12 * V_13 = F_5 ( V_8 ) ;
return F_6 ( V_11 , V_14 , L_1 , V_13 -> V_15 ) ;
}
static T_3 F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
T_3 V_16 = - V_17 ;
union V_1 * V_18 ;
struct V_12 * V_13 = F_5 ( V_8 ) ;
V_18 = F_1 ( V_13 -> V_19 , V_20 ,
V_21 , NULL ) ;
if ( ! V_18 )
return - V_22 ;
if ( V_18 -> V_23 . V_24 == 2 &&
V_18 -> V_23 . V_25 [ 0 ] . type == V_26 &&
V_18 -> V_23 . V_25 [ 1 ] . type == V_26 ) {
if ( V_18 -> V_23 . V_25 [ 0 ] . integer . V_27 )
V_16 = - V_28 ;
else
V_16 = F_6 ( V_11 , V_14 , L_2 ,
V_18 -> V_23 . V_25 [ 1 ] . integer . V_27 ) ;
}
F_8 ( V_18 ) ;
return V_16 ;
}
static T_3 F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_4 V_24 )
{
T_5 V_29 ;
T_6 V_30 ;
int V_3 = V_31 ;
union V_1 * V_18 , V_32 ;
union V_1 V_4 = F_10 ( 1 , & V_32 ) ;
struct V_12 * V_13 = F_5 ( V_8 ) ;
if ( F_11 ( V_13 -> V_19 , V_5 ,
V_6 , 1 << V_33 ) )
V_3 = V_33 ;
if ( strcmp ( V_13 -> V_15 , L_3 ) < 0 ) {
if ( sscanf ( V_11 , L_4 , & V_29 ) != 1 )
return - V_17 ;
V_4 . type = V_34 ;
V_4 . V_35 . V_36 = sizeof( V_29 ) ;
V_4 . V_35 . V_37 = ( V_38 * ) & V_29 ;
} else {
V_32 . type = V_26 ;
if ( sscanf ( V_11 , L_5 , & V_32 . integer . V_27 ) != 1 )
return - V_17 ;
}
V_18 = F_1 ( V_13 -> V_19 , V_3 , V_26 ,
& V_4 ) ;
if ( ! V_18 ) {
return - V_22 ;
} else {
V_30 = V_18 -> integer . V_27 ;
F_8 ( V_18 ) ;
}
if ( V_30 == 0 )
return ( V_39 ) V_24 ;
return ( V_30 == 1 ) ? - V_40 : - V_28 ;
}
static T_3 F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
char * V_11 )
{
T_5 V_30 ;
V_39 V_41 ;
union V_1 * V_18 = NULL ;
union V_1 V_32 = {
. V_35 . type = V_34 ,
. V_35 . V_36 = 0 ,
. V_35 . V_37 = NULL
} ;
struct V_12 * V_13 = F_5 ( V_8 ) ;
static char * V_42 [] = {
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
} ;
if ( strcmp ( V_13 -> V_15 , L_3 ) < 0 )
V_18 = & V_32 ;
V_18 = F_1 ( V_13 -> V_19 , V_43 ,
V_26 , V_18 ) ;
if ( ! V_18 ) {
return - V_22 ;
} else {
V_30 = V_18 -> integer . V_27 ;
F_8 ( V_18 ) ;
}
if ( V_30 < F_13 ( V_42 ) - 1 )
V_41 = F_6 ( V_11 , V_14 , L_11 , V_30 , V_42 [ V_30 ] ) ;
else
V_41 = F_6 ( V_11 , V_14 , L_11 , V_30 ,
V_42 [ F_13 ( V_42 ) - 1 ] ) ;
return V_41 ;
}
static T_3 F_14 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
char * V_11 )
{
V_39 V_41 = - V_17 ;
union V_1 * V_18 , * V_44 ;
T_6 V_29 , V_45 ;
struct V_12 * V_13 = F_5 ( V_8 ) ;
V_18 = F_1 ( V_13 -> V_19 , V_46 ,
V_21 , NULL ) ;
if ( ! V_18 )
return - V_22 ;
V_44 = V_18 -> V_23 . V_25 ;
if ( V_18 -> V_23 . V_24 < 3 ||
V_44 [ 0 ] . type != V_26 ||
V_44 [ 1 ] . type != V_26 ||
V_44 [ 2 ] . type != V_26 )
goto V_47;
if ( V_44 [ 0 ] . integer . V_27 ) {
V_41 = - V_28 ;
goto V_47;
}
V_29 = V_44 [ 1 ] . integer . V_27 ;
V_45 = V_44 [ 2 ] . integer . V_27 ;
if ( V_29 ) {
if ( V_45 == 0 )
V_41 = F_6 ( V_11 , V_14 , L_12 , V_29 ,
L_13 ) ;
else if ( V_45 == 0xFFFFFFF0 )
V_41 = F_6 ( V_11 , V_14 , L_12 , V_29 ,
L_14 ) ;
else if ( V_45 == 0xFFFFFFF1 )
V_41 = F_6 ( V_11 , V_14 , L_12 , V_29 ,
L_15 ) ;
else if ( V_45 >= 1 && V_45 <= 0x00000FFF )
V_41 = F_6 ( V_11 , V_14 , L_16 ,
V_29 , V_45 , L_17 ) ;
else
V_41 = F_6 ( V_11 , V_14 , L_16 ,
V_29 , V_45 , L_10 ) ;
} else {
V_41 = F_6 ( V_11 , V_14 , L_18 ,
V_29 , L_19 ) ;
}
V_47:
F_8 ( V_18 ) ;
return V_41 ;
}
static T_3 F_15 ( T_1 V_48 , char * V_11 , T_5 V_49 ,
T_5 V_50 )
{
int V_51 ;
T_5 V_30 ;
char * V_52 = V_11 ;
union V_1 * V_18 , V_32 ;
union V_1 V_53 = F_10 ( 1 , & V_32 ) ;
static char * V_42 [] = {
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
} ;
if ( ! F_11 ( V_48 , V_5 , V_6 ,
1 << V_54 ) )
return - V_40 ;
V_32 . integer . type = V_26 ;
for ( V_51 = V_49 ; V_51 <= V_50 ; V_51 ++ ) {
V_32 . integer . V_27 = V_51 ;
V_18 = F_1 ( V_48 , V_54 ,
V_26 , & V_53 ) ;
if ( ! V_18 ) {
return - V_55 ;
} else {
V_30 = V_18 -> integer . V_27 ;
F_8 ( V_18 ) ;
}
if ( V_30 > 0 && V_30 < F_13 ( V_42 ) )
V_52 += F_6 ( V_52 , V_14 , L_25 ,
V_51 , V_30 , V_42 [ V_30 ] ) ;
}
return V_52 - V_11 ;
}
static T_3 F_16 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_5 ( V_8 ) ;
return F_15 ( V_13 -> V_19 , V_11 , 0 ,
V_56 ) ;
}
static T_3 F_17 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_5 ( V_8 ) ;
return F_15 ( V_13 -> V_19 , V_11 , V_57 ,
V_58 ) ;
}
int F_18 ( struct V_12 * V_13 )
{
union V_1 * V_18 ;
int V_59 ;
if ( ! V_13 -> V_19 )
return 0 ;
if ( ! F_11 ( V_13 -> V_19 , V_5 ,
V_6 , 1 << V_60 ) )
return 0 ;
V_18 = F_3 ( V_13 -> V_19 , V_5 ,
V_6 , V_60 ,
NULL , V_61 ) ;
if ( V_18 ) {
F_19 ( V_13 -> V_15 , V_18 -> string . V_37 ,
sizeof( V_13 -> V_15 ) ) ;
F_8 ( V_18 ) ;
}
V_59 = F_20 ( & V_13 -> V_62 -> V_63 , & V_64 ) ;
if ( ! V_59 )
V_13 -> V_65 |= V_66 ;
return V_59 ;
}
void F_21 ( struct V_12 * V_13 )
{
if ( V_13 -> V_65 & V_66 )
F_22 ( & V_13 -> V_62 -> V_63 , & V_64 ) ;
}
