static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , NULL , V_3 , V_7 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_6 = F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
return V_6 ;
}
static struct V_8 *
F_7 ( struct V_8 * V_9 ,
const struct V_10 * V_11 ,
bool V_12 )
{
const struct V_10 * V_13 ;
struct V_8 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 = 0 ;
int V_6 ;
int error ;
for ( V_13 = V_11 ; V_13 -> V_20 ; V_13 ++ )
if ( V_13 -> V_12 == V_12 )
V_19 ++ ;
V_18 = F_8 ( & V_9 -> V_2 ,
sizeof( * V_18 ) +
sizeof( * V_16 ) * V_19 ,
V_21 ) ;
if ( ! V_18 )
return F_9 ( - V_22 ) ;
V_16 = ( void * ) ( V_18 + 1 ) ;
V_19 = 0 ;
for ( V_13 = V_11 ; V_13 -> V_20 ; V_13 ++ ) {
if ( V_13 -> V_12 != V_12 )
continue;
V_6 = F_1 ( & V_9 -> V_2 , V_13 -> V_3 ) ;
if ( ! F_10 ( V_6 ) )
continue;
V_16 [ V_19 ] . type = V_13 -> V_23 ;
V_16 [ V_19 ] . V_24 = V_13 -> V_25 ;
V_16 [ V_19 ] . V_6 = V_6 ;
V_16 [ V_19 ] . V_26 = 1 ;
V_16 [ V_19 ] . V_5 = V_13 -> V_20 ;
V_16 [ V_19 ] . V_27 = V_13 -> V_27 ;
V_16 [ V_19 ] . V_28 = 50 ;
V_19 ++ ;
}
if ( V_19 == 0 ) {
error = - V_29 ;
goto V_30;
}
V_18 -> V_31 = V_16 ;
V_18 -> V_32 = V_19 ;
V_18 -> V_33 = V_12 ;
V_14 = F_11 ( L_1 , V_34 ) ;
if ( ! V_14 ) {
error = - V_22 ;
goto V_30;
}
error = F_12 ( V_14 , V_18 ,
sizeof( * V_18 ) ) ;
if ( error )
goto V_35;
error = F_13 ( V_14 ) ;
if ( error )
goto V_35;
return V_14 ;
V_35:
F_14 ( V_14 ) ;
V_30:
F_15 ( & V_9 -> V_2 , V_18 ) ;
return F_9 ( error ) ;
}
static int F_16 ( const union V_36 * V_37 )
{
if ( V_37 -> type != V_38 )
return - 1 ;
return V_37 -> integer . V_39 ;
}
static int F_17 ( struct V_1 * V_2 ,
const union V_36 * V_5 ,
int V_40 ,
struct V_10 * V_13 )
{
int V_41 , V_42 ;
if ( V_5 -> type != V_43 ||
V_5 -> V_44 . V_45 != 5 ||
F_16 ( & V_5 -> V_44 . V_46 [ 0 ] ) != 1 ||
F_16 ( & V_5 -> V_44 . V_46 [ 2 ] ) !=
V_40 ) {
F_18 ( V_2 , L_2 ) ;
return - V_29 ;
}
V_13 -> V_23 = V_47 ;
V_13 -> V_3 =
F_16 ( & V_5 -> V_44 . V_46 [ 1 ] ) ;
V_41 = F_16 ( & V_5 -> V_44 . V_46 [ 3 ] ) ;
V_42 = F_16 ( & V_5 -> V_44 . V_46 [ 4 ] ) ;
if ( V_41 == 0x01 && V_42 == 0x81 ) {
V_13 -> V_20 = L_3 ;
V_13 -> V_25 = V_48 ;
V_13 -> V_27 = true ;
} else if ( V_41 == 0x07 && V_42 == 0xe3 ) {
V_13 -> V_20 = L_4 ;
V_13 -> V_25 = V_49 ;
V_13 -> V_27 = true ;
} else if ( V_41 == 0x0c && V_42 == 0xe9 ) {
V_13 -> V_20 = L_5 ;
V_13 -> V_25 = V_50 ;
V_13 -> V_12 = true ;
} else if ( V_41 == 0x0c && V_42 == 0xea ) {
V_13 -> V_20 = L_6 ;
V_13 -> V_25 = V_51 ;
V_13 -> V_12 = true ;
} else {
F_19 ( V_2 , L_7 ,
V_13 -> V_3 , V_41 , V_42 ) ;
V_13 -> V_20 = L_8 ;
V_13 -> V_25 = V_52 ;
}
return 0 ;
}
static struct V_10 * F_20 ( struct V_1 * V_2 )
{
struct V_53 V_54 = { V_55 } ;
const union V_36 * V_5 , * V_56 , * V_57 , * V_58 = NULL ;
struct V_10 * V_11 ;
T_1 V_59 ;
int V_60 , V_61 , V_40 = - 1 ;
V_59 = F_21 ( F_22 ( V_2 ) , L_9 , NULL ,
& V_54 , V_43 ) ;
if ( F_23 ( V_59 ) ) {
F_18 ( V_2 , L_10 ) ;
return F_9 ( - V_29 ) ;
}
V_5 = V_54 . V_62 ;
for ( V_60 = 0 ; ( V_60 + 1 ) < V_5 -> V_44 . V_45 ; V_60 += 2 ) {
V_57 = & V_5 -> V_44 . V_46 [ V_60 ] ;
if ( V_57 -> type != V_63 ||
V_57 -> V_64 . V_65 != 16 ||
V_5 -> V_44 . V_46 [ V_60 + 1 ] . type != V_43 ) {
break;
}
if ( memcmp ( V_57 -> V_64 . V_62 , V_66 , 16 ) == 0 ) {
V_58 = & V_5 -> V_44 . V_46 [ V_60 + 1 ] ;
break;
}
}
if ( ! V_58 ) {
F_18 ( V_2 , L_11 ) ;
V_11 = F_9 ( - V_29 ) ;
goto V_67;
}
V_56 = & V_58 -> V_44 . V_46 [ 0 ] ;
if ( V_56 -> type == V_43 &&
V_56 -> V_44 . V_45 == 5 &&
F_16 ( & V_56 -> V_44 . V_46 [ 0 ] ) == 0 &&
F_16 ( & V_56 -> V_44 . V_46 [ 2 ] ) == 0 ) {
V_40 = F_16 (
& V_56 -> V_44 . V_46 [ 1 ] ) ;
}
if ( V_40 == - 1 ) {
F_18 ( V_2 , L_12 ) ;
V_11 = F_9 ( - V_29 ) ;
goto V_67;
}
V_11 = F_24 ( V_2 , V_58 -> V_44 . V_45 ,
sizeof( * V_11 ) , V_21 ) ;
if ( ! V_11 ) {
V_11 = F_9 ( - V_22 ) ;
goto V_67;
}
for ( V_60 = 1 , V_61 = 0 ; V_60 < V_58 -> V_44 . V_45 ; V_60 ++ , V_61 ++ ) {
if ( F_17 ( V_2 ,
& V_58 -> V_44 . V_46 [ V_60 ] ,
V_40 ,
& V_11 [ V_61 ] ) ) {
V_11 = F_9 ( - V_29 ) ;
goto V_67;
}
}
V_67:
F_25 ( V_54 . V_62 ) ;
return V_11 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_68 * V_69 = F_27 ( V_9 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_70 ; V_60 ++ )
if ( V_69 -> V_71 [ V_60 ] )
F_28 ( V_69 -> V_71 [ V_60 ] ) ;
return 0 ;
}
static int F_29 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
const struct V_72 * V_73 ;
struct V_10 * V_11 ;
struct V_68 * V_69 ;
struct V_8 * V_14 ;
int V_60 ;
int error ;
V_73 = F_30 ( V_2 -> V_74 -> V_75 , V_2 ) ;
if ( ! V_73 )
return - V_29 ;
if ( ! V_73 -> V_76 ) {
V_11 = F_20 ( V_2 ) ;
if ( F_3 ( V_11 ) )
return F_4 ( V_11 ) ;
} else {
V_11 = (struct V_10 * ) V_73 -> V_76 ;
}
error = F_31 ( V_2 , NULL ) ;
if ( error < 0 ) {
F_32 ( V_2 , L_13 ) ;
return - V_29 ;
}
V_69 = F_8 ( V_2 , sizeof( * V_69 ) , V_21 ) ;
if ( ! V_69 )
return - V_22 ;
F_33 ( V_9 , V_69 ) ;
for ( V_60 = 0 ; V_60 < V_70 ; V_60 ++ ) {
V_14 = F_7 ( V_9 , V_11 , V_60 == 0 ) ;
if ( F_3 ( V_14 ) ) {
error = F_4 ( V_14 ) ;
if ( error != - V_29 ) {
F_26 ( V_9 ) ;
return error ;
}
continue;
}
V_69 -> V_71 [ V_60 ] = V_14 ;
}
if ( ! V_69 -> V_71 [ 0 ] && ! V_69 -> V_71 [ 1 ] )
return - V_29 ;
if ( ! V_73 -> V_76 )
F_15 ( V_2 , V_11 ) ;
return 0 ;
}
