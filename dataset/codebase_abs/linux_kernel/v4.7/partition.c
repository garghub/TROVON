T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
if ( V_4 >= V_7 -> V_10 ) {
F_3 ( L_1 ,
V_3 , V_4 , V_5 ) ;
return 0xFFFFFFFF ;
}
V_9 = & V_7 -> V_11 [ V_4 ] ;
if ( V_9 -> V_12 )
return V_9 -> V_12 ( V_2 , V_3 , V_4 , V_5 ) ;
else
return V_9 -> V_13 + V_3 + V_5 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_1 V_5 )
{
struct V_14 * V_15 = NULL ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = F_5 ( V_7 -> V_23 ) ;
V_9 = & V_7 -> V_11 [ V_4 ] ;
V_20 = & V_9 -> V_24 . V_25 ;
if ( V_3 > V_20 -> V_26 ) {
F_3 ( L_2 ,
V_3 , V_20 -> V_26 ) ;
return 0xFFFFFFFF ;
}
if ( V_22 -> V_27 == V_28 ) {
V_18 = F_6 ( ( ( V_29 * ) ( V_22 -> V_30 . V_31 +
V_20 -> V_32 ) ) [ V_3 ] ) ;
goto V_33;
}
V_17 = ( V_2 -> V_34 - V_20 -> V_32 ) / sizeof( T_1 ) ;
if ( V_3 >= V_17 ) {
V_3 -= V_17 ;
V_16 = 1 + ( V_3 / ( V_2 -> V_34 / sizeof( T_1 ) ) ) ;
V_17 = V_3 % ( V_2 -> V_34 / sizeof( T_1 ) ) ;
} else {
V_16 = 0 ;
V_17 = V_20 -> V_32 / sizeof( T_1 ) + V_3 ;
}
V_18 = F_7 ( V_7 -> V_23 , V_16 ) ;
V_15 = F_8 ( V_2 , V_18 ) ;
if ( ! V_15 ) {
F_3 ( L_3 ,
V_2 , V_3 , V_4 , V_18 , V_17 ) ;
return 0xFFFFFFFF ;
}
V_18 = F_6 ( ( ( V_29 * ) V_15 -> V_35 ) [ V_17 ] ) ;
F_9 ( V_15 ) ;
V_33:
if ( V_22 -> V_36 . V_37 == V_4 ) {
F_3 ( L_4 ) ;
return 0xFFFFFFFF ;
}
return F_1 ( V_2 , V_18 ,
V_22 -> V_36 . V_37 ,
V_5 ) ;
}
inline T_1 F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_1 V_5 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
}
T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_1 V_5 )
{
int V_38 ;
struct V_39 * V_40 = NULL ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
T_1 V_41 ;
struct V_42 * V_43 ;
V_9 = & V_7 -> V_11 [ V_4 ] ;
V_43 = & V_9 -> V_24 . V_44 ;
V_41 = ( V_3 + V_5 ) & ~ ( V_43 -> V_45 - 1 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
if ( V_43 -> V_46 [ V_38 ] != NULL ) {
V_40 = (struct V_39 * )
V_43 -> V_46 [ V_38 ] -> V_35 ;
break;
}
}
if ( V_40 ) {
for ( V_38 = 0 ; V_38 < F_12 ( V_40 -> V_47 ) ; V_38 ++ ) {
struct V_48 * V_49 = & V_40 -> V_50 [ V_38 ] ;
T_3 V_51 = F_6 ( V_49 -> V_52 ) ;
if ( V_51 >= 0xFFFFFFF0 )
break;
else if ( V_51 == V_41 )
return F_6 ( V_49 -> V_53 ) +
( ( V_3 + V_5 ) &
( V_43 -> V_45 - 1 ) ) ;
else if ( V_51 > V_41 )
break;
}
}
return V_9 -> V_13 + V_3 + V_5 ;
}
int F_13 ( struct V_1 * V_2 , long V_54 , long * V_55 )
{
struct V_42 * V_43 ;
struct V_39 * V_40 = NULL ;
struct V_48 V_50 ;
T_1 V_41 ;
int V_38 , V_56 , V_57 , V_58 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_4 V_47 ;
struct V_14 * V_15 ;
int V_59 = 0 ;
F_14 ( & V_7 -> V_60 ) ;
for ( V_38 = 0 ; V_38 < V_7 -> V_10 ; V_38 ++ ) {
struct V_8 * V_9 = & V_7 -> V_11 [ V_38 ] ;
if ( V_54 > V_9 -> V_13 &&
V_54 < V_9 -> V_13 + V_9 -> V_61 ) {
V_43 = & V_9 -> V_24 . V_44 ;
V_41 = ( V_54 - V_9 -> V_13 ) &
~ ( V_43 -> V_45 - 1 ) ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ )
if ( V_43 -> V_46 [ V_56 ] != NULL ) {
V_40 = (struct V_39 * )
V_43 -> V_46 [ V_56 ] -> V_35 ;
break;
}
if ( ! V_40 ) {
V_59 = 1 ;
goto V_62;
}
V_47 =
F_12 ( V_40 -> V_47 ) ;
for ( V_57 = 0 ; V_57 < V_47 ; V_57 ++ ) {
struct V_48 * V_49 = & V_40 -> V_50 [ V_57 ] ;
T_3 V_51 = F_6 ( V_49 -> V_52 ) ;
if ( V_51 == 0xFFFFFFFF ) {
for (; V_56 < 4 ; V_56 ++ ) {
int V_63 ;
V_15 = V_43 -> V_46 [ V_56 ] ;
if ( ! V_15 )
continue;
V_40 = (struct V_39 * )
V_15 -> V_35 ;
V_49 -> V_52 =
F_15 ( V_41 ) ;
V_63 =
sizeof( struct V_39 ) +
V_47 *
sizeof( struct V_48 ) ;
F_16 ( ( char * ) V_40 , V_63 ) ;
F_17 ( V_15 ) ;
}
* V_55 = F_6 (
V_49 -> V_53 ) +
( ( V_54 -
V_9 -> V_13 ) &
( V_43 -> V_45 - 1 ) ) ;
V_59 = 0 ;
goto V_62;
} else if ( V_51 == V_41 ) {
* V_55 = F_6 (
V_49 -> V_53 ) +
( ( V_54 -
V_9 -> V_13 ) &
( V_43 -> V_45 - 1 ) ) ;
V_59 = 0 ;
goto V_62;
} else if ( V_51 > V_41 )
break;
}
for ( V_58 = V_57 ; V_58 < V_47 ; V_58 ++ ) {
struct V_48 * V_49 = & V_40 -> V_50 [ V_58 ] ;
T_3 V_51 = F_6 ( V_49 -> V_52 ) ;
if ( V_51 != 0xFFFFFFFF )
continue;
for (; V_56 < 4 ; V_56 ++ ) {
V_15 = V_43 -> V_46 [ V_56 ] ;
if ( ! V_15 )
continue;
V_40 = (struct V_39 * ) V_15 -> V_35 ;
V_50 = V_40 -> V_50 [ V_58 ] ;
V_50 . V_52 =
F_15 ( V_41 ) ;
memmove ( & V_40 -> V_50 [ V_57 + 1 ] ,
& V_40 -> V_50 [ V_57 ] ,
( V_58 - V_57 ) *
sizeof( struct V_48 ) ) ;
V_40 -> V_50 [ V_57 ] = V_50 ;
F_16 ( ( char * ) V_40 ,
sizeof( struct V_39 ) +
V_47 *
sizeof( struct V_48 ) ) ;
F_17 ( V_15 ) ;
}
* V_55 =
F_6 (
V_40 -> V_50 [ V_57 ] . V_53 ) +
( ( V_54 - V_9 -> V_13 ) &
( V_43 -> V_45 - 1 ) ) ;
V_59 = 0 ;
goto V_62;
}
V_59 = 1 ;
goto V_62;
}
}
if ( V_38 == V_7 -> V_10 ) {
V_59 = 1 ;
}
V_62:
F_18 ( & V_7 -> V_60 ) ;
return V_59 ;
}
static T_1 F_19 ( struct V_64 * V_64 , T_1 V_3 ,
T_2 V_4 , T_1 V_5 )
{
struct V_1 * V_2 = V_64 -> V_65 ;
struct V_8 * V_9 ;
struct V_66 V_67 ;
T_1 V_68 ;
T_5 V_69 ;
struct V_70 V_71 = {} ;
T_1 V_72 ;
if ( F_20 ( V_64 , V_3 , & V_71 , & V_67 , & V_68 , & V_69 ) !=
( V_73 >> 30 ) )
V_72 = 0xFFFFFFFF ;
else {
V_9 = & F_2 ( V_2 ) -> V_11 [ V_4 ] ;
V_72 = F_1 ( V_2 , V_67 . V_74 ,
V_9 -> V_24 . V_75 . V_76 ,
V_69 + V_5 ) ;
}
F_9 ( V_71 . V_15 ) ;
return V_72 ;
}
T_1 F_21 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_77 * V_78 ;
T_1 V_79 ;
struct V_64 * V_64 ;
F_3 ( L_5 ) ;
V_9 = & V_7 -> V_11 [ V_4 ] ;
V_78 = & V_9 -> V_24 . V_75 ;
V_64 = V_78 -> V_80 ? : V_78 -> V_81 ;
if ( ! V_64 )
return 0xFFFFFFFF ;
V_79 = F_19 ( V_64 , V_3 , V_4 , V_5 ) ;
if ( V_79 == 0xFFFFFFFF && V_78 -> V_80 ) {
F_22 ( V_2 , L_6 ) ;
if ( ! ( V_78 -> V_82 & V_83 ) ) {
V_78 -> V_81 = F_23 ( V_2 ,
V_78 -> V_84 ,
V_78 -> V_76 ) ;
if ( F_24 ( V_78 -> V_81 ) )
V_78 -> V_81 = NULL ;
V_78 -> V_82 |= V_83 ;
}
V_64 = V_78 -> V_81 ;
if ( ! V_64 )
return 0xFFFFFFFF ;
V_79 = F_19 ( V_64 , V_3 , V_4 , V_5 ) ;
}
return V_79 ;
}
