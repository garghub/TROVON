static T_1 F_1 ( T_2 V_1 , T_3 V_2 , void * V_3 ,
void * * V_4 )
{
T_1 V_5 ;
struct V_6 V_7 = { V_8 , NULL } ;
V_5 = F_2 ( V_1 , V_9 , & V_7 ) ;
if ( strstr ( V_7 . V_10 , V_3 ) != NULL ) {
* V_4 = V_1 ;
F_3 ( V_7 . V_10 ) ;
return V_11 ;
}
return V_12 ;
}
static inline void F_4 ( union V_13 V_14 [ 4 ] ,
T_4 V_15 )
{
V_14 [ 0 ] . type = V_16 ;
V_14 [ 0 ] . V_7 . V_17 = sizeof( V_18 ) ;
V_14 [ 0 ] . V_7 . V_10 = ( char * ) V_18 ;
V_14 [ 1 ] . type = V_19 ;
V_14 [ 1 ] . integer . V_20 = V_21 ;
V_14 [ 2 ] . type = V_19 ;
V_14 [ 2 ] . integer . V_20 = V_15 ;
V_14 [ 3 ] . type = V_22 ;
V_14 [ 3 ] . V_23 . V_24 = 0 ;
V_14 [ 3 ] . V_23 . V_25 = NULL ;
}
static T_5 F_5 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_30 )
{
T_2 V_1 ;
T_1 V_5 ;
struct V_31 V_32 ;
struct V_6 V_33 = { V_8 , NULL } ;
union V_13 V_14 [ 4 ] ;
union V_13 * V_34 ;
V_32 . V_24 = 4 ;
F_4 ( V_14 , V_35 ) ;
V_32 . V_10 = V_14 ;
V_5 = F_6 ( V_36 , V_37 ,
V_38 , F_1 , NULL ,
V_39 , & V_1 ) ;
if ( F_7 ( V_5 ) )
return - V_40 ;
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_41 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
V_34 = (union V_13 * ) V_33 . V_10 ;
V_5 = F_9 ( V_30 , V_43 , L_2 , V_34 -> string . V_10 ) ;
F_3 ( V_33 . V_10 ) ;
return V_5 ;
}
static T_5 F_10 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_30 )
{
T_2 V_1 ;
T_1 V_5 ;
struct V_31 V_32 ;
struct V_6 V_33 = { V_8 , NULL } ;
union V_13 V_14 [ 4 ] ;
union V_13 * V_44 ;
V_32 . V_24 = 4 ;
F_4 ( V_14 , V_45 ) ;
V_32 . V_10 = V_14 ;
V_5 = F_6 ( V_36 , V_37 ,
V_38 , F_1 , NULL ,
V_39 , & V_1 ) ;
if ( F_7 ( V_5 ) )
return - V_40 ;
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_22 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
V_44 = ( (union V_13 * ) V_33 . V_10 ) -> V_23 . V_25 ;
if ( V_44 -> type == V_19 ) {
if ( V_44 -> integer . V_20 ) {
V_5 = - V_46 ;
goto V_47;
}
V_44 ++ ;
if ( V_44 -> type == V_19 )
V_5 = F_9 ( V_30 , V_43 , L_3 ,
V_44 -> integer . V_20 ) ;
else
V_5 = - V_48 ;
} else {
V_5 = - V_48 ;
}
V_47:
F_3 ( V_33 . V_10 ) ;
return V_5 ;
}
static T_5 F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_30 , T_6 V_24 )
{
char V_49 [ V_50 + 1 ] ;
T_2 V_1 ;
T_1 V_5 ;
struct V_31 V_32 ;
struct V_6 V_33 = { V_8 , NULL } ;
union V_13 V_14 [ 4 ] ;
union V_13 V_34 ;
T_3 V_51 ;
T_4 V_52 ;
V_32 . V_24 = 4 ;
F_4 ( V_14 , V_35 ) ;
V_32 . V_10 = V_14 ;
V_5 = F_6 ( V_36 , V_37 ,
V_38 , F_1 , NULL ,
V_39 , & V_1 ) ;
if ( F_7 ( V_5 ) )
return - V_40 ;
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_41 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
F_12 ( V_49 ,
( (union V_13 * ) V_33 . V_10 ) -> string . V_10 ,
V_50 + 1 ) ;
F_3 ( V_33 . V_10 ) ;
V_33 . V_17 = V_8 ;
V_33 . V_10 = NULL ;
if ( strcmp ( V_49 , L_4 ) == - 1 )
V_14 [ 2 ] . integer . V_20 = V_53 ;
else
V_14 [ 2 ] . integer . V_20 = V_54 ;
if ( strcmp ( V_49 , L_5 ) == - 1 ) {
V_14 [ 3 ] . type = V_16 ;
V_14 [ 3 ] . V_7 . V_17 = sizeof( V_51 ) ;
sscanf ( V_30 , L_6 , & V_51 ) ;
V_14 [ 3 ] . V_7 . V_10 = ( char * ) & V_51 ;
} else {
V_14 [ 3 ] . V_23 . V_24 = 1 ;
V_34 . type = V_19 ;
sscanf ( V_30 , L_7 , & V_34 . integer . V_20 ) ;
V_14 [ 3 ] . V_23 . V_25 = & V_34 ;
}
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_19 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
V_52 = ( (union V_13 * ) V_33 . V_10 ) -> integer . V_20 ;
if ( V_52 == 0 )
V_5 = ( T_1 ) V_24 ;
else if ( V_52 == 1 )
V_5 = - V_55 ;
else
V_5 = - V_46 ;
F_3 ( V_33 . V_10 ) ;
return V_5 ;
}
static T_5 F_13 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
char V_49 [ V_50 + 1 ] ;
T_2 V_1 ;
T_1 V_5 ;
struct V_31 V_32 ;
struct V_6 V_33 = { V_8 , NULL } ;
union V_13 V_14 [ 4 ] ;
T_3 V_52 ;
char * V_56 [] = {
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
} ;
V_32 . V_24 = 4 ;
F_4 ( V_14 , V_35 ) ;
V_32 . V_10 = V_14 ;
V_5 = F_6 ( V_36 , V_37 ,
V_38 , F_1 , NULL ,
V_39 , & V_1 ) ;
if ( F_7 ( V_5 ) )
return - V_40 ;
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_41 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
F_12 ( V_49 ,
( (union V_13 * ) V_33 . V_10 ) -> string . V_10 ,
V_50 + 1 ) ;
if ( strcmp ( V_49 , L_5 ) == - 1 ) {
V_14 [ 3 ] . type = V_16 ;
V_14 [ 3 ] . V_7 . V_17 = 0 ;
V_14 [ 3 ] . V_7 . V_10 = NULL ;
}
V_14 [ 2 ] . integer . V_20 = V_57 ;
F_3 ( V_33 . V_10 ) ;
V_33 . V_17 = V_8 ;
V_33 . V_10 = NULL ;
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_19 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
V_52 = ( (union V_13 * ) V_33 . V_10 ) -> integer . V_20 ;
if ( V_52 < F_14 ( V_56 ) - 1 )
V_5 = F_9 ( V_30 , V_43 , L_13 , V_52 , V_56 [ V_52 ] ) ;
else
V_5 = F_9 ( V_30 , V_43 , L_13 , V_52 ,
V_56 [ F_14 ( V_56 ) - 1 ] ) ;
F_3 ( V_33 . V_10 ) ;
return V_5 ;
}
static T_5 F_15 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
T_2 V_1 ;
T_1 V_5 ;
struct V_31 V_32 ;
struct V_6 V_33 = { V_8 , NULL } ;
union V_13 V_14 [ 4 ] ;
union V_13 * V_44 ;
T_4 V_51 ;
V_32 . V_24 = 4 ;
F_4 ( V_14 , V_58 ) ;
V_32 . V_10 = V_14 ;
V_5 = F_6 ( V_36 , V_37 ,
V_38 , F_1 , NULL ,
V_39 , & V_1 ) ;
if ( F_7 ( V_5 ) )
return - V_40 ;
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_22 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
V_44 = ( (union V_13 * ) V_33 . V_10 ) -> V_23 . V_25 ;
if ( V_44 -> type != V_19 ) {
V_5 = - V_48 ;
goto V_47;
}
if ( V_44 -> integer . V_20 ) {
V_5 = - V_46 ;
goto V_47;
}
V_44 ++ ;
if ( V_44 -> type != V_19 ) {
V_5 = - V_48 ;
goto V_47;
}
if ( V_44 -> integer . V_20 ) {
V_51 = V_44 -> integer . V_20 ;
V_44 ++ ;
if ( V_44 -> type != V_19 ) {
V_5 = - V_48 ;
goto V_47;
}
if ( V_44 -> integer . V_20 == 0 )
V_5 = F_9 ( V_30 , V_43 , L_14 , V_51 ,
L_15 ) ;
else if ( V_44 -> integer . V_20 == 0xFFFFFFF0 )
V_5 = F_9 ( V_30 , V_43 , L_14 , V_51 ,
L_16 ) ;
else if ( V_44 -> integer . V_20 == 0xFFFFFFF1 )
V_5 = F_9 ( V_30 , V_43 , L_14 , V_51 ,
L_17 ) ;
else if ( V_44 -> integer . V_20 >= 1 &&
V_44 -> integer . V_20 <= 0x00000FFF )
V_5 = F_9 ( V_30 , V_43 , L_18 ,
V_51 , V_44 -> integer . V_20 ,
L_19 ) ;
else
V_5 = F_9 ( V_30 , V_43 , L_18 ,
V_51 , V_44 -> integer . V_20 ,
L_12 ) ;
} else {
V_5 = F_9 ( V_30 , V_43 , L_20 ,
V_44 -> integer . V_20 , L_21 ) ;
}
V_47:
F_3 ( V_33 . V_10 ) ;
return V_5 ;
}
static T_5 F_16 ( char * V_30 , T_3 V_59 , T_3 V_60 )
{
char * V_61 = V_30 ;
char V_49 [ V_50 + 1 ] ;
T_2 V_1 ;
T_1 V_5 ;
struct V_31 V_32 ;
struct V_6 V_33 = { V_8 , NULL } ;
union V_13 V_14 [ 4 ] ;
union V_13 V_34 ;
int V_62 ;
T_3 V_52 ;
char * V_56 [] = {
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
} ;
V_32 . V_24 = 4 ;
F_4 ( V_14 , V_35 ) ;
V_32 . V_10 = V_14 ;
V_5 = F_6 ( V_36 , V_37 ,
V_38 , F_1 , NULL ,
V_39 , & V_1 ) ;
if ( F_7 ( V_5 ) )
return - V_40 ;
V_5 = F_8 ( V_1 , L_1 , & V_32 , & V_33 ,
V_41 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
F_12 ( V_49 ,
( (union V_13 * ) V_33 . V_10 ) -> string . V_10 ,
V_50 + 1 ) ;
F_3 ( V_33 . V_10 ) ;
V_33 . V_17 = V_8 ;
V_33 . V_10 = NULL ;
if ( strcmp ( V_49 , L_5 ) == - 1 )
return - V_55 ;
V_14 [ 2 ] . integer . V_20 = V_63 ;
V_14 [ 3 ] . V_23 . V_24 = 1 ;
V_34 . type = V_19 ;
V_14 [ 3 ] . V_23 . V_25 = & V_34 ;
for ( V_62 = V_59 ; V_62 <= V_60 ; V_62 ++ ) {
V_34 . integer . V_20 = V_62 ;
V_5 = F_8 ( V_1 , L_1 ,
& V_32 , & V_33 , V_19 ) ;
if ( F_7 ( V_5 ) )
return - V_42 ;
V_52 = ( (union V_13 * ) V_33 . V_10 ) -> integer . V_20 ;
if ( V_52 > 0 && V_52 < F_14 ( V_56 ) )
V_61 += F_9 ( V_61 , V_43 , L_27 ,
V_62 , V_52 , V_56 [ V_52 ] ) ;
F_3 ( V_33 . V_10 ) ;
V_33 . V_17 = V_8 ;
V_33 . V_10 = NULL ;
}
return V_61 - V_30 ;
}
static T_5 F_17 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
return F_16 ( V_30 , 0 , V_64 ) ;
}
static T_5 F_18 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 )
{
return F_16 ( V_30 , V_65 , V_66 ) ;
}
int F_19 ( struct V_67 * V_68 )
{
return F_20 ( V_68 , & V_69 ) ;
}
void F_21 ( struct V_67 * V_68 )
{
F_22 ( V_68 , & V_69 ) ;
}
