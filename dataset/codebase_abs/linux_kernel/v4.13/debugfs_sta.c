static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
F_2 () ;
F_3 (peer, &stats->peers_extd, list) {
V_8 = F_4 ( V_2 -> V_11 , V_6 -> V_12 ,
NULL ) ;
if ( ! V_8 )
continue;
V_10 = (struct V_9 * ) V_8 -> V_13 ;
V_10 -> V_14 += ( V_15 ) V_6 -> V_14 ;
}
F_5 () ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_16 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
F_2 () ;
F_3 (peer, &stats->peers, list) {
V_8 = F_4 ( V_2 -> V_11 , V_6 -> V_12 ,
NULL ) ;
if ( ! V_8 )
continue;
V_10 = (struct V_9 * ) V_8 -> V_13 ;
V_10 -> V_14 += ( V_15 ) V_6 -> V_14 ;
}
F_5 () ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_17 )
F_1 ( V_2 , V_4 ) ;
else
F_6 ( V_2 , V_4 ) ;
}
void F_8 ( struct V_18 * V_11 , struct V_19 * V_20 ,
struct V_7 * V_8 ,
struct V_21 * V_22 )
{
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
if ( ! F_9 ( V_2 ) )
return;
V_22 -> V_14 = V_10 -> V_14 ;
V_22 -> V_24 |= 1ULL << V_25 ;
if ( ! V_10 -> V_26 . V_27 && ! V_10 -> V_26 . V_28 )
return;
if ( V_10 -> V_26 . V_27 ) {
V_22 -> V_26 . V_27 = V_10 -> V_26 . V_27 ;
} else {
V_22 -> V_26 . V_29 = V_10 -> V_26 . V_29 ;
V_22 -> V_26 . V_28 = V_10 -> V_26 . V_28 ;
V_22 -> V_26 . V_30 = V_10 -> V_26 . V_30 ;
}
V_22 -> V_26 . V_31 = V_10 -> V_26 . V_31 ;
V_22 -> V_24 |= 1ULL << V_32 ;
}
static T_1 F_10 ( struct V_33 * V_33 ,
char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_7 * V_8 = V_33 -> V_37 ;
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
char V_38 [ 32 ] ;
int V_39 = 0 ;
F_11 ( & V_2 -> V_40 ) ;
V_39 = F_12 ( V_38 , sizeof( V_38 ) - V_39 , L_1 ,
( V_10 -> V_41 == V_42 ) ?
L_2 : L_3 ) ;
F_13 ( & V_2 -> V_40 ) ;
return F_14 ( V_34 , V_35 , V_36 , V_38 , V_39 ) ;
}
static T_1 F_15 ( struct V_33 * V_33 ,
const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_7 * V_8 = V_33 -> V_37 ;
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
T_5 V_41 ;
int V_43 ;
if ( F_16 ( V_34 , V_35 , 0 , & V_41 ) )
return - V_44 ;
if ( V_41 >= V_45 )
return - V_44 ;
F_11 ( & V_2 -> V_40 ) ;
if ( ( V_2 -> V_46 != V_47 ) ||
( V_41 == V_10 -> V_41 ) ) {
V_43 = V_35 ;
goto V_48;
}
V_43 = F_17 ( V_2 , V_10 -> V_23 -> V_49 , V_8 -> V_50 ) ;
if ( V_43 ) {
F_18 ( V_2 , L_4 , V_43 ) ;
goto V_48;
}
V_10 -> V_41 = V_41 ;
V_48:
F_13 ( & V_2 -> V_40 ) ;
return V_43 ;
}
static T_1 F_19 ( struct V_33 * V_33 ,
const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_7 * V_8 = V_33 -> V_37 ;
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
T_5 V_51 , V_52 ;
int V_43 ;
char V_38 [ 64 ] ;
F_20 ( V_38 , sizeof( V_38 ) - 1 , V_36 , V_34 , V_35 ) ;
V_38 [ sizeof( V_38 ) - 1 ] = '\0' ;
V_43 = sscanf ( V_38 , L_5 , & V_51 , & V_52 ) ;
if ( V_43 != 2 )
return - V_44 ;
if ( V_51 > V_53 - 2 )
return - V_44 ;
F_11 ( & V_2 -> V_40 ) ;
if ( ( V_2 -> V_46 != V_47 ) ||
( V_10 -> V_41 != V_54 ) ) {
V_43 = V_35 ;
goto V_48;
}
V_43 = F_21 ( V_2 , V_10 -> V_23 -> V_49 , V_8 -> V_50 ,
V_51 , V_52 ) ;
if ( V_43 ) {
F_18 ( V_2 , L_6 ,
V_10 -> V_23 -> V_49 , V_8 -> V_50 , V_51 , V_52 ) ;
}
V_43 = V_35 ;
V_48:
F_13 ( & V_2 -> V_40 ) ;
return V_43 ;
}
static T_1 F_22 ( struct V_33 * V_33 ,
const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_7 * V_8 = V_33 -> V_37 ;
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
T_5 V_51 , V_55 ;
int V_43 ;
char V_38 [ 64 ] ;
F_20 ( V_38 , sizeof( V_38 ) - 1 , V_36 , V_34 , V_35 ) ;
V_38 [ sizeof( V_38 ) - 1 ] = '\0' ;
V_43 = sscanf ( V_38 , L_5 , & V_51 , & V_55 ) ;
if ( V_43 != 2 )
return - V_44 ;
if ( V_51 > V_53 - 2 )
return - V_44 ;
F_11 ( & V_2 -> V_40 ) ;
if ( ( V_2 -> V_46 != V_47 ) ||
( V_10 -> V_41 != V_54 ) ) {
V_43 = V_35 ;
goto V_48;
}
V_43 = F_23 ( V_2 , V_10 -> V_23 -> V_49 , V_8 -> V_50 ,
V_51 , V_55 ) ;
if ( V_43 ) {
F_18 ( V_2 , L_7 ,
V_10 -> V_23 -> V_49 , V_8 -> V_50 , V_51 , V_55 ) ;
}
V_43 = V_35 ;
V_48:
F_13 ( & V_2 -> V_40 ) ;
return V_43 ;
}
static T_1 F_24 ( struct V_33 * V_33 ,
const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_7 * V_8 = V_33 -> V_37 ;
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
T_5 V_51 , V_56 , V_57 ;
int V_43 ;
char V_38 [ 64 ] ;
F_20 ( V_38 , sizeof( V_38 ) - 1 , V_36 , V_34 , V_35 ) ;
V_38 [ sizeof( V_38 ) - 1 ] = '\0' ;
V_43 = sscanf ( V_38 , L_8 , & V_51 , & V_56 , & V_57 ) ;
if ( V_43 != 3 )
return - V_44 ;
if ( V_51 > V_53 - 2 )
return - V_44 ;
F_11 ( & V_2 -> V_40 ) ;
if ( ( V_2 -> V_46 != V_47 ) ||
( V_10 -> V_41 != V_54 ) ) {
V_43 = V_35 ;
goto V_48;
}
V_43 = F_25 ( V_2 , V_10 -> V_23 -> V_49 , V_8 -> V_50 ,
V_51 , V_56 , V_57 ) ;
if ( V_43 ) {
F_18 ( V_2 , L_9 ,
V_10 -> V_23 -> V_49 , V_8 -> V_50 , V_51 , V_56 ,
V_57 ) ;
}
V_43 = V_35 ;
V_48:
F_13 ( & V_2 -> V_40 ) ;
return V_43 ;
}
static T_1 F_26 ( struct V_33 * V_33 ,
char T_2 * V_34 ,
T_3 V_35 ,
T_4 * V_36 )
{
struct V_7 * V_8 = V_33 -> V_37 ;
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
char V_38 [ 8 ] ;
int V_39 = 0 ;
F_11 ( & V_2 -> V_40 ) ;
V_39 = F_12 ( V_38 , sizeof( V_38 ) - V_39 ,
L_10 ) ;
F_13 ( & V_2 -> V_40 ) ;
return F_14 ( V_34 , V_35 , V_36 , V_38 , V_39 ) ;
}
static T_1
F_27 ( struct V_33 * V_33 ,
const char T_2 * V_34 ,
T_3 V_35 , T_4 * V_36 )
{
struct V_7 * V_8 = V_33 -> V_37 ;
struct V_9 * V_10 = (struct V_9 * ) V_8 -> V_13 ;
struct V_1 * V_2 = V_10 -> V_23 -> V_2 ;
T_6 V_58 ;
int V_43 ;
if ( F_28 ( V_34 , V_35 , 0 , & V_58 ) )
return - V_44 ;
if ( V_58 != 1 )
return - V_44 ;
F_11 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_46 != V_47 ) {
V_43 = - V_59 ;
goto V_48;
}
V_43 = F_29 ( V_2 , V_10 -> V_23 -> V_49 , V_8 -> V_50 ,
V_60 , V_58 ) ;
if ( V_43 ) {
F_18 ( V_2 , L_11 ,
V_43 ) ;
goto V_48;
}
V_48:
F_13 ( & V_2 -> V_40 ) ;
return V_35 ;
}
void F_30 ( struct V_18 * V_11 , struct V_19 * V_20 ,
struct V_7 * V_8 , struct V_61 * V_62 )
{
F_31 ( L_12 , 0644 , V_62 , V_8 , & V_63 ) ;
F_31 ( L_13 , 0200 , V_62 , V_8 , & V_64 ) ;
F_31 ( L_14 , 0200 , V_62 , V_8 , & V_65 ) ;
F_31 ( L_15 , 0200 , V_62 , V_8 , & V_66 ) ;
F_31 ( L_16 , 0600 , V_62 , V_8 ,
& V_67 ) ;
}
