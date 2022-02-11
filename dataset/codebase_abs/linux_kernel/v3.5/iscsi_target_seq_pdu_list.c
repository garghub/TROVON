static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
F_2 ( L_1 ,
V_2 -> V_6 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_5 = & V_2 -> V_8 [ V_3 ] ;
F_2 ( L_2
L_3
L_4 , V_3 , V_5 -> V_9 , V_5 -> V_10 ,
V_5 -> V_11 , V_5 -> V_12 , V_5 -> V_13 ,
V_5 -> V_14 ) ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_15 * V_16 ;
F_2 ( L_5 ,
V_2 -> V_6 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ ) {
V_16 = & V_2 -> V_17 [ V_3 ] ;
F_2 ( L_6
L_7 , V_3 , V_16 -> V_11 ,
V_16 -> V_18 , V_16 -> V_19 , V_16 -> V_14 ) ;
}
}
static void F_1 ( struct V_1 * V_2 ) {}
static void F_3 ( struct V_1 * V_2 ) {}
static void F_4 (
struct V_1 * V_2 ,
T_1 type )
{
T_2 V_3 , V_7 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
if ( V_2 -> V_8 [ V_3 ] . type != V_20 )
continue;
V_2 -> V_8 [ V_3 ] . V_13 = V_7 ++ ;
}
}
static void F_5 (
struct V_1 * V_2 ,
T_1 type )
{
T_2 V_3 , V_19 = 0 , V_14 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ ) {
V_21:
if ( V_2 -> V_17 [ V_3 ] . V_14 == V_14 ) {
V_2 -> V_17 [ V_3 ] . V_19 = V_19 ++ ;
continue;
}
V_14 ++ ;
V_19 = 0 ;
goto V_21;
}
}
static void F_6 ( T_2 * V_22 , T_2 V_23 )
{
int V_3 , V_24 , V_25 ;
if ( V_23 == 1 ) {
V_22 [ 0 ] = 0 ;
return;
}
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ ) {
V_21:
F_7 ( & V_24 , sizeof( T_2 ) ) ;
V_24 = ( 1 + ( int ) ( 9999 + 1 ) - V_24 ) % V_23 ;
for ( V_25 = 0 ; V_25 < V_3 + 1 ; V_25 ++ ) {
V_24 |= 0x80000000 ;
if ( ( V_22 [ V_25 ] & 0x80000000 ) && ( V_22 [ V_25 ] == V_24 ) )
goto V_21;
}
V_22 [ V_3 ] = V_24 ;
}
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ )
V_22 [ V_3 ] &= ~ 0x80000000 ;
}
static int F_8 (
struct V_1 * V_2 ,
T_1 type )
{
int V_3 = 0 ;
T_2 * V_22 , V_10 , V_7 = 0 , V_14 = 0 , V_26 = 0 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_10 ; V_10 ++ ) {
V_21:
if ( V_2 -> V_17 [ V_10 ] . V_14 == V_14 ) {
V_7 ++ ;
continue;
}
V_22 = F_9 ( V_7 , sizeof( T_2 ) , V_27 ) ;
if ( ! V_22 ) {
F_10 ( L_8
L_9 ) ;
return - V_28 ;
}
F_6 ( V_22 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ )
V_2 -> V_17 [ V_26 + V_3 ] . V_19 = V_22 [ V_3 ] ;
F_11 ( V_22 ) ;
V_26 += V_7 ;
V_7 = 0 ;
V_14 ++ ;
goto V_21;
}
if ( V_7 ) {
V_22 = F_9 ( V_7 , sizeof( T_2 ) , V_27 ) ;
if ( ! V_22 ) {
F_10 ( L_10
L_11 ) ;
return - V_28 ;
}
F_6 ( V_22 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ )
V_2 -> V_17 [ V_26 + V_3 ] . V_19 = V_22 [ V_3 ] ;
F_11 ( V_22 ) ;
}
return 0 ;
}
static int F_12 (
struct V_1 * V_2 ,
T_1 type )
{
int V_3 , V_24 = 0 ;
T_2 * V_22 , V_7 = V_2 -> V_7 ;
if ( ( type == V_29 ) || ( type == V_30 ) )
V_7 -- ;
else if ( type == V_31 )
V_7 -= 2 ;
if ( ! V_7 )
return 0 ;
V_22 = F_9 ( V_7 , sizeof( T_2 ) , V_27 ) ;
if ( ! V_22 ) {
F_10 ( L_12 ) ;
return - V_28 ;
}
F_6 ( V_22 , V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
if ( V_2 -> V_8 [ V_3 ] . type != V_20 )
continue;
V_2 -> V_8 [ V_3 ] . V_13 = V_22 [ V_24 ++ ] ;
}
F_11 ( V_22 ) ;
return 0 ;
}
static void F_13 (
struct V_1 * V_2 ,
struct V_32 * V_33 ,
T_2 * V_7 ,
T_2 * V_10 )
{
int V_34 = 0 ;
T_2 V_35 = 0 , V_11 = 0 ;
T_2 V_36 = 0 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ( V_33 -> type == V_29 ) ||
( V_33 -> type == V_31 ) )
V_34 = 1 ;
if ( ( V_33 -> type == V_30 ) ||
( V_33 -> type == V_31 ) )
V_36 = F_14 ( V_2 -> V_39 . V_40 ,
V_38 -> V_41 -> V_42 -> V_43 ) ;
while ( V_11 < V_2 -> V_39 . V_40 ) {
* V_10 += 1 ;
if ( V_34 ) {
V_34 = 0 ;
V_11 += V_33 -> V_44 ;
* V_7 += 1 ;
if ( V_36 )
V_36 -=
V_33 -> V_44 ;
continue;
}
if ( V_36 > 0 ) {
if ( ( V_11 + V_38 -> V_45 -> V_46 )
>= V_2 -> V_39 . V_40 ) {
V_36 -=
( V_2 -> V_39 . V_40 - V_11 ) ;
V_11 += ( V_2 -> V_39 . V_40 - V_11 ) ;
continue;
}
if ( ( V_11 + V_38 -> V_45 -> V_46 )
>= V_38 -> V_41 -> V_42 -> V_43 ) {
V_36 -=
( V_38 -> V_41 -> V_42 -> V_43 -
V_11 ) ;
V_11 += ( V_38 -> V_41 -> V_42 -> V_43 -
V_11 ) ;
V_35 = 0 ;
* V_7 += 1 ;
continue;
}
V_11 += V_38 -> V_45 -> V_46 ;
V_36 -=
V_38 -> V_45 -> V_46 ;
continue;
}
if ( ( V_11 + V_38 -> V_45 -> V_46 ) >=
V_2 -> V_39 . V_40 ) {
V_11 += ( V_2 -> V_39 . V_40 - V_11 ) ;
continue;
}
if ( ( V_35 + V_38 -> V_45 -> V_46 ) >=
V_38 -> V_41 -> V_42 -> V_47 ) {
V_11 += ( V_38 -> V_41 -> V_42 -> V_47 -
V_35 ) ;
V_35 = 0 ;
* V_7 += 1 ;
continue;
}
V_35 += V_38 -> V_45 -> V_46 ;
V_11 += V_38 -> V_45 -> V_46 ;
}
}
static int F_15 (
struct V_1 * V_2 ,
struct V_32 * V_33 )
{
int V_34 = 0 , V_48 , V_49 ;
T_2 V_35 = 0 , V_11 = 0 , V_3 = 0 ;
T_2 V_10 = 0 , V_14 = 0 , V_36 = 0 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_4 * V_5 = V_2 -> V_8 ;
V_48 = V_38 -> V_41 -> V_42 -> V_50 ;
V_49 = V_38 -> V_41 -> V_42 -> V_51 ;
if ( ( V_33 -> type == V_29 ) ||
( V_33 -> type == V_31 ) )
V_34 = 1 ;
if ( ( V_33 -> type == V_30 ) ||
( V_33 -> type == V_31 ) )
V_36 = F_14 ( V_2 -> V_39 . V_40 ,
V_38 -> V_41 -> V_42 -> V_43 ) ;
while ( V_11 < V_2 -> V_39 . V_40 ) {
V_10 ++ ;
if ( ! V_48 ) {
V_16 [ V_3 ] . V_11 = V_11 ;
V_16 [ V_3 ] . V_14 = V_14 ;
}
if ( ! V_49 && ( V_10 == 1 ) ) {
V_5 [ V_14 ] . V_9 = V_3 ;
V_5 [ V_14 ] . V_14 = V_14 ;
V_5 [ V_14 ] . V_11 = V_11 ;
V_5 [ V_14 ] . V_52 = V_11 ;
}
if ( V_34 ) {
V_34 = 0 ;
if ( ! V_48 ) {
V_16 [ V_3 ] . type = V_53 ;
V_16 [ V_3 ++ ] . V_18 = V_33 -> V_44 ;
}
if ( ! V_49 ) {
V_5 [ V_14 ] . type = V_54 ;
V_5 [ V_14 ] . V_10 = 1 ;
V_5 [ V_14 ] . V_12 =
V_33 -> V_44 ;
}
V_11 += V_33 -> V_44 ;
V_10 = 0 ;
V_14 ++ ;
if ( V_36 )
V_36 -=
V_33 -> V_44 ;
continue;
}
if ( V_36 > 0 ) {
if ( ( V_11 +
V_38 -> V_45 -> V_46 ) >=
V_2 -> V_39 . V_40 ) {
if ( ! V_48 ) {
V_16 [ V_3 ] . type = V_55 ;
V_16 [ V_3 ] . V_18 =
( V_2 -> V_39 . V_40 - V_11 ) ;
}
if ( ! V_49 ) {
V_5 [ V_14 ] . type = V_56 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_35 +
( V_2 -> V_39 . V_40 - V_11 ) ) ;
}
V_36 -=
( V_2 -> V_39 . V_40 - V_11 ) ;
V_11 += ( V_2 -> V_39 . V_40 - V_11 ) ;
continue;
}
if ( ( V_11 +
V_38 -> V_45 -> V_46 ) >=
V_38 -> V_41 -> V_42 -> V_43 ) {
if ( ! V_48 ) {
V_16 [ V_3 ] . type = V_55 ;
V_16 [ V_3 ++ ] . V_18 =
( V_38 -> V_41 -> V_42 -> V_43 -
V_11 ) ;
}
if ( ! V_49 ) {
V_5 [ V_14 ] . type = V_56 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_35 +
( V_38 -> V_41 -> V_42 -> V_43 -
V_11 ) ) ;
}
V_36 -=
( V_38 -> V_41 -> V_42 -> V_43 -
V_11 ) ;
V_11 += ( V_38 -> V_41 -> V_42 -> V_43 -
V_11 ) ;
V_35 = 0 ;
V_10 = 0 ;
V_14 ++ ;
continue;
}
if ( ! V_48 ) {
V_16 [ V_3 ] . type = V_55 ;
V_16 [ V_3 ++ ] . V_18 =
V_38 -> V_45 -> V_46 ;
}
V_35 += V_38 -> V_45 -> V_46 ;
V_11 += V_38 -> V_45 -> V_46 ;
V_36 -=
V_38 -> V_45 -> V_46 ;
continue;
}
if ( ( V_11 + V_38 -> V_45 -> V_46 ) >=
V_2 -> V_39 . V_40 ) {
if ( ! V_48 ) {
V_16 [ V_3 ] . type = V_57 ;
V_16 [ V_3 ] . V_18 = ( V_2 -> V_39 . V_40 - V_11 ) ;
}
if ( ! V_49 ) {
V_5 [ V_14 ] . type = V_20 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_35 +
( V_2 -> V_39 . V_40 - V_11 ) ) ;
}
V_11 += ( V_2 -> V_39 . V_40 - V_11 ) ;
continue;
}
if ( ( V_35 + V_38 -> V_45 -> V_46 ) >=
V_38 -> V_41 -> V_42 -> V_47 ) {
if ( ! V_48 ) {
V_16 [ V_3 ] . type = V_57 ;
V_16 [ V_3 ++ ] . V_18 =
( V_38 -> V_41 -> V_42 -> V_47 -
V_35 ) ;
}
if ( ! V_49 ) {
V_5 [ V_14 ] . type = V_20 ;
V_5 [ V_14 ] . V_10 = V_10 ;
V_5 [ V_14 ] . V_12 = ( V_35 +
( V_38 -> V_41 -> V_42 -> V_47 -
V_35 ) ) ;
}
V_11 += ( V_38 -> V_41 -> V_42 -> V_47 -
V_35 ) ;
V_35 = 0 ;
V_10 = 0 ;
V_14 ++ ;
continue;
}
if ( ! V_48 ) {
V_16 [ V_3 ] . type = V_57 ;
V_16 [ V_3 ++ ] . V_18 =
V_38 -> V_45 -> V_46 ;
}
V_35 += V_38 -> V_45 -> V_46 ;
V_11 += V_38 -> V_45 -> V_46 ;
}
if ( ! V_49 ) {
if ( V_33 -> V_58 & V_59 ) {
if ( V_33 -> V_60 & V_61 ) {
if ( F_12 ( V_2 , V_33 -> type )
< 0 )
return - 1 ;
} else
F_4 ( V_2 , V_33 -> type ) ;
} else if ( V_33 -> V_58 & V_62 ) {
if ( V_33 -> V_60 & V_63 ) {
if ( F_12 ( V_2 , V_33 -> type )
< 0 )
return - 1 ;
} else
F_4 ( V_2 , V_33 -> type ) ;
}
F_1 ( V_2 ) ;
}
if ( ! V_48 ) {
if ( V_33 -> V_58 & V_59 ) {
if ( V_33 -> V_60 & V_64 ) {
if ( F_8 ( V_2 , V_33 -> type )
< 0 )
return - 1 ;
} else
F_5 ( V_2 , V_33 -> type ) ;
} else if ( V_33 -> V_58 & V_62 ) {
if ( V_33 -> V_60 & V_65 ) {
if ( F_8 ( V_2 , V_33 -> type )
< 0 )
return - 1 ;
} else
F_5 ( V_2 , V_33 -> type ) ;
}
F_3 ( V_2 ) ;
}
return 0 ;
}
int F_16 (
struct V_1 * V_2 ,
T_2 V_44 )
{
struct V_32 V_33 ;
T_2 V_10 = 0 , V_7 = 1 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_15 * V_16 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_66 * V_41 = V_38 -> V_41 ;
struct V_67 * V_68 ;
if ( V_41 -> V_42 -> V_51 &&
V_41 -> V_42 -> V_50 )
return 0 ;
if ( V_2 -> V_58 == V_69 )
return 0 ;
V_68 = F_17 ( V_41 ) ;
memset ( & V_33 , 0 , sizeof( struct V_32 ) ) ;
if ( V_2 -> V_58 == V_70 ) {
V_33 . V_58 = V_62 ;
V_33 . type = V_71 ;
if ( V_68 -> V_72 )
V_33 . V_60 |= V_65 ;
if ( V_68 -> V_73 )
V_33 . V_60 |= V_63 ;
} else {
V_33 . V_58 = V_59 ;
V_33 . V_44 = V_44 ;
if ( V_68 -> V_74 )
V_33 . V_60 |= V_61 ;
if ( ! V_2 -> V_75 && ! V_2 -> V_76 )
V_33 . type = V_71 ;
else if ( V_2 -> V_75 && ! V_2 -> V_76 )
V_33 . type = V_29 ;
else if ( ! V_2 -> V_75 && V_2 -> V_76 )
V_33 . type = V_30 ;
else if ( V_2 -> V_75 && V_2 -> V_76 )
V_33 . type = V_31 ;
}
F_13 ( V_2 , & V_33 , & V_7 , & V_10 ) ;
if ( ! V_38 -> V_41 -> V_42 -> V_51 ) {
V_5 = F_9 ( V_7 , sizeof( struct V_4 ) , V_77 ) ;
if ( ! V_5 ) {
F_10 ( L_13 ) ;
return - V_28 ;
}
V_2 -> V_8 = V_5 ;
V_2 -> V_7 = V_7 ;
}
if ( ! V_38 -> V_41 -> V_42 -> V_50 ) {
V_16 = F_9 ( V_10 , sizeof( struct V_15 ) , V_77 ) ;
if ( ! V_16 ) {
F_10 ( L_14 ) ;
F_11 ( V_5 ) ;
return - V_28 ;
}
V_2 -> V_17 = V_16 ;
V_2 -> V_10 = V_10 ;
}
return F_15 ( V_2 , & V_33 ) ;
}
struct V_15 * F_18 (
struct V_1 * V_2 ,
T_2 V_11 ,
T_2 V_18 )
{
T_2 V_3 ;
struct V_15 * V_16 = NULL ;
if ( ! V_2 -> V_17 ) {
F_10 ( L_15 ) ;
return NULL ;
}
V_16 = & V_2 -> V_17 [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_2 -> V_10 ; V_3 ++ )
if ( ( V_16 [ V_3 ] . V_11 == V_11 ) && ( V_16 [ V_3 ] . V_18 == V_18 ) )
return & V_16 [ V_3 ] ;
F_10 ( L_16
L_17 , V_2 -> V_6 , V_11 , V_18 ) ;
return NULL ;
}
struct V_15 * F_19 (
struct V_1 * V_2 ,
struct V_4 * V_5 )
{
T_2 V_3 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_15 * V_16 = NULL ;
if ( ! V_2 -> V_17 ) {
F_10 ( L_15 ) ;
return NULL ;
}
if ( V_38 -> V_41 -> V_42 -> V_51 ) {
V_21:
V_16 = & V_2 -> V_17 [ V_2 -> V_9 ] ;
for ( V_3 = 0 ; V_16 [ V_3 ] . V_14 != V_2 -> V_14 ; V_3 ++ ) {
F_2 ( L_18
L_19
L_20 , V_16 [ V_3 ] . V_14 ,
V_16 [ V_3 ] . V_19 , V_16 [ V_3 ] . V_11 ,
V_16 [ V_3 ] . V_18 ) ;
if ( V_16 [ V_3 ] . V_19 == V_2 -> V_19 ) {
V_2 -> V_19 ++ ;
return & V_16 [ V_3 ] ;
}
}
V_2 -> V_9 += V_2 -> V_19 ;
V_2 -> V_19 = 0 ;
V_2 -> V_14 ++ ;
if ( V_2 -> V_9 < V_2 -> V_10 )
goto V_21;
F_10 ( L_21
L_22 ,
V_2 -> V_6 , V_2 -> V_19 ) ;
return NULL ;
} else {
if ( ! V_5 ) {
F_10 ( L_23 ) ;
return NULL ;
}
F_2 ( L_24
L_25 , V_5 -> V_9 , V_5 -> V_10 ,
V_5 -> V_14 ) ;
V_16 = & V_2 -> V_17 [ V_5 -> V_9 ] ;
if ( V_5 -> V_19 == V_5 -> V_10 ) {
F_10 ( L_26
L_27 ,
V_2 -> V_6 , V_5 -> V_19 ,
V_5 -> V_10 ) ;
return NULL ;
}
for ( V_3 = 0 ; V_3 < V_5 -> V_10 ; V_3 ++ ) {
if ( V_16 [ V_3 ] . V_19 == V_5 -> V_19 ) {
V_5 -> V_19 ++ ;
return & V_16 [ V_3 ] ;
}
}
F_10 ( L_28
L_29 ,
V_2 -> V_6 , V_5 -> V_19 ) ;
return NULL ;
}
return NULL ;
}
struct V_4 * F_20 (
struct V_1 * V_2 ,
T_2 V_11 ,
T_2 V_18 )
{
T_2 V_3 ;
if ( ! V_2 -> V_8 ) {
F_10 ( L_30 ) ;
return NULL ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
F_2 ( L_31
L_32 ,
V_2 -> V_8 [ V_3 ] . V_52 , V_2 -> V_8 [ V_3 ] . V_12 ,
V_2 -> V_8 [ V_3 ] . V_14 ) ;
if ( ( V_2 -> V_8 [ V_3 ] . V_52 +
V_2 -> V_8 [ V_3 ] . V_12 ) >=
( V_11 + V_18 ) )
return & V_2 -> V_8 [ V_3 ] ;
}
F_10 ( L_33
L_34 , V_2 -> V_6 , V_11 ,
V_18 ) ;
return NULL ;
}
