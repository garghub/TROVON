static T_1 F_1 ( T_2 V_1 , T_3 V_2 , void * V_3 ,
void * * V_4 )
{
union V_5 * V_6 ;
if ( ! F_2 ( V_1 , V_7 , V_8 ,
1 << V_9 ) )
return V_10 ;
V_6 = F_3 ( V_1 , V_7 ,
V_8 , V_9 ,
NULL , V_11 ) ;
if ( V_6 ) {
F_4 ( V_12 , V_6 -> string . V_13 ,
V_14 + 1 ) ;
F_5 ( V_6 ) ;
}
* V_4 = V_1 ;
return V_15 ;
}
static inline union V_5 *
F_6 ( int V_16 , T_4 type , union V_5 * V_17 )
{
F_7 ( ! V_18 ) ;
return F_3 ( V_18 , V_7 ,
V_8 , V_16 , V_17 , type ) ;
}
static T_5 F_8 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
return F_9 ( V_23 , V_24 , L_1 , V_12 ) ;
}
static T_5 F_10 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
T_5 V_25 = - V_26 ;
union V_5 * V_6 ;
V_6 = F_6 ( V_27 , V_28 , NULL ) ;
if ( ! V_6 )
return - V_29 ;
if ( V_6 -> V_30 . V_31 == 2 &&
V_6 -> V_30 . V_32 [ 0 ] . type == V_33 &&
V_6 -> V_30 . V_32 [ 1 ] . type == V_33 ) {
if ( V_6 -> V_30 . V_32 [ 0 ] . integer . V_34 )
V_25 = - V_35 ;
else
V_25 = F_9 ( V_23 , V_24 , L_2 ,
V_6 -> V_30 . V_32 [ 1 ] . integer . V_34 ) ;
}
F_5 ( V_6 ) ;
return V_25 ;
}
static T_5 F_11 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_6 V_31 )
{
T_3 V_36 ;
T_7 V_37 ;
int V_16 = V_38 ;
union V_5 * V_6 , V_39 ;
union V_5 V_17 = F_12 ( 1 , & V_39 ) ;
if ( F_2 ( V_18 , V_7 , V_8 ,
1 << V_40 ) )
V_16 = V_40 ;
if ( strcmp ( V_12 , L_3 ) < 0 ) {
if ( sscanf ( V_23 , L_4 , & V_36 ) != 1 )
return - V_26 ;
V_17 . type = V_41 ;
V_17 . V_42 . V_43 = sizeof( V_36 ) ;
V_17 . V_42 . V_13 = ( V_44 * ) & V_36 ;
} else {
V_39 . type = V_33 ;
if ( sscanf ( V_23 , L_5 , & V_39 . integer . V_34 ) != 1 )
return - V_26 ;
}
V_6 = F_6 ( V_16 , V_33 , & V_17 ) ;
if ( ! V_6 ) {
return - V_29 ;
} else {
V_37 = V_6 -> integer . V_34 ;
F_5 ( V_6 ) ;
}
if ( V_37 == 0 )
return ( T_1 ) V_31 ;
return ( V_37 == 1 ) ? - V_45 : - V_35 ;
}
static T_5 F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 )
{
T_3 V_37 ;
T_1 V_46 ;
union V_5 * V_6 = NULL ;
union V_5 V_39 = {
. V_42 . type = V_41 ,
. V_42 . V_43 = 0 ,
. V_42 . V_13 = NULL
} ;
static char * V_47 [] = {
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
} ;
if ( strcmp ( V_12 , L_3 ) < 0 )
V_6 = & V_39 ;
V_6 = F_6 ( V_48 , V_33 , V_6 ) ;
if ( ! V_6 ) {
return - V_29 ;
} else {
V_37 = V_6 -> integer . V_34 ;
F_5 ( V_6 ) ;
}
if ( V_37 < F_14 ( V_47 ) - 1 )
V_46 = F_9 ( V_23 , V_24 , L_11 , V_37 , V_47 [ V_37 ] ) ;
else
V_46 = F_9 ( V_23 , V_24 , L_11 , V_37 ,
V_47 [ F_14 ( V_47 ) - 1 ] ) ;
return V_46 ;
}
static T_5 F_15 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 )
{
T_1 V_46 = - V_26 ;
union V_5 * V_6 , * V_49 ;
T_7 V_36 , V_50 ;
V_6 = F_6 ( V_51 , V_28 , NULL ) ;
if ( ! V_6 )
return - V_29 ;
V_49 = V_6 -> V_30 . V_32 ;
if ( V_6 -> V_30 . V_31 < 3 ||
V_49 [ 0 ] . type != V_33 ||
V_49 [ 1 ] . type != V_33 ||
V_49 [ 2 ] . type != V_33 )
goto V_52;
if ( V_49 [ 0 ] . integer . V_34 ) {
V_46 = - V_35 ;
goto V_52;
}
V_36 = V_49 [ 1 ] . integer . V_34 ;
V_50 = V_49 [ 2 ] . integer . V_34 ;
if ( V_36 ) {
if ( V_50 == 0 )
V_46 = F_9 ( V_23 , V_24 , L_12 , V_36 ,
L_13 ) ;
else if ( V_50 == 0xFFFFFFF0 )
V_46 = F_9 ( V_23 , V_24 , L_12 , V_36 ,
L_14 ) ;
else if ( V_50 == 0xFFFFFFF1 )
V_46 = F_9 ( V_23 , V_24 , L_12 , V_36 ,
L_15 ) ;
else if ( V_50 >= 1 && V_50 <= 0x00000FFF )
V_46 = F_9 ( V_23 , V_24 , L_16 ,
V_36 , V_50 , L_17 ) ;
else
V_46 = F_9 ( V_23 , V_24 , L_16 ,
V_36 , V_50 , L_10 ) ;
} else {
V_46 = F_9 ( V_23 , V_24 , L_18 ,
V_36 , L_19 ) ;
}
V_52:
F_5 ( V_6 ) ;
return V_46 ;
}
static T_5 F_16 ( char * V_23 , T_3 V_53 , T_3 V_54 )
{
int V_55 ;
T_3 V_37 ;
char * V_56 = V_23 ;
union V_5 * V_6 , V_39 ;
union V_5 V_57 = F_12 ( 1 , & V_39 ) ;
static char * V_47 [] = {
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
} ;
if ( ! F_2 ( V_18 , V_7 , V_8 ,
1 << V_58 ) )
return - V_45 ;
V_39 . integer . type = V_33 ;
for ( V_55 = V_53 ; V_55 <= V_54 ; V_55 ++ ) {
V_39 . integer . V_34 = V_55 ;
V_6 = F_6 ( V_58 , V_33 , & V_57 ) ;
if ( ! V_6 ) {
return - V_59 ;
} else {
V_37 = V_6 -> integer . V_34 ;
F_5 ( V_6 ) ;
}
if ( V_37 > 0 && V_37 < F_14 ( V_47 ) )
V_56 += F_9 ( V_56 , V_24 , L_25 ,
V_55 , V_37 , V_47 [ V_37 ] ) ;
}
return V_56 - V_23 ;
}
static T_5 F_17 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 )
{
return F_16 ( V_23 , 0 , V_60 ) ;
}
static T_5 F_18 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
char * V_23 )
{
return F_16 ( V_23 , V_61 , V_62 ) ;
}
int F_19 ( struct V_63 * V_64 )
{
F_20 ( V_65 , V_66 , V_67 ,
F_1 , NULL , NULL , & V_18 ) ;
return V_18 ? F_21 ( V_64 , & V_68 ) : 0 ;
}
void F_22 ( struct V_63 * V_64 )
{
if ( V_18 )
F_23 ( V_64 , & V_68 ) ;
}
