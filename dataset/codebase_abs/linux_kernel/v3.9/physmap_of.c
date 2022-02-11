static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( & V_2 -> V_2 ) ;
if ( ! V_4 )
return 0 ;
F_3 ( & V_2 -> V_2 , NULL ) ;
if ( V_4 -> V_6 != V_4 -> V_7 [ 0 ] . V_8 ) {
F_4 ( V_4 -> V_6 ) ;
F_5 ( V_4 -> V_6 ) ;
}
if ( V_4 -> V_6 )
F_4 ( V_4 -> V_6 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; V_5 ++ ) {
if ( V_4 -> V_7 [ V_5 ] . V_8 )
F_6 ( V_4 -> V_7 [ V_5 ] . V_8 ) ;
if ( V_4 -> V_7 [ V_5 ] . V_10 . V_11 )
F_7 ( V_4 -> V_7 [ V_5 ] . V_10 . V_11 ) ;
if ( V_4 -> V_7 [ V_5 ] . V_12 ) {
F_8 ( V_4 -> V_7 [ V_5 ] . V_12 ) ;
F_9 ( V_4 -> V_7 [ V_5 ] . V_12 ) ;
}
}
return 0 ;
}
static struct V_13 * F_10 ( struct V_1 * V_2 ,
struct V_14 * V_10 )
{
struct V_15 * V_16 = V_2 -> V_2 . V_17 ;
const char * V_18 ;
struct V_13 * V_8 ;
static const char * V_19 []
= { L_1 , L_2 , L_3 } ;
int V_5 ;
F_11 ( & V_2 -> V_2 , L_4
L_5 ) ;
V_18 = F_12 ( V_16 , L_6 , NULL ) ;
if ( ! V_18 ) {
for ( V_5 = 0 ; V_5 < F_13 ( V_19 ) ; V_5 ++ ) {
V_8 = F_14 ( V_19 [ V_5 ] , V_10 ) ;
if ( V_8 )
return V_8 ;
}
return NULL ;
} else if ( strcmp ( V_18 , L_7 ) == 0 ) {
return F_14 ( L_1 , V_10 ) ;
} else if ( strcmp ( V_18 , L_8 ) == 0 ) {
return F_14 ( L_2 , V_10 ) ;
} else {
if ( strcmp ( V_18 , L_9 ) != 0 )
F_11 ( & V_2 -> V_2 , L_10
L_11 , V_18 ) ;
return F_14 ( L_12 , V_10 ) ;
}
}
static const char * * F_15 ( struct V_15 * V_16 )
{
const char * V_20 ;
int V_21 ;
unsigned int V_22 ;
unsigned int V_23 ;
const char * * V_12 ;
V_20 = F_12 ( V_16 , L_13 , & V_21 ) ;
if ( V_20 == NULL )
return V_24 ;
V_23 = 0 ;
for ( V_22 = 0 ; V_22 != V_21 ; V_22 ++ )
if ( V_20 [ V_22 ] == 0 )
V_23 ++ ;
V_12 = F_16 ( ( V_23 + 1 ) * sizeof( * V_12 ) , V_25 ) ;
V_23 = 0 ;
while ( V_21 > 0 ) {
V_12 [ V_23 ] = V_20 ;
V_22 = strlen ( V_20 ) + 1 ;
V_20 += V_22 ;
V_21 -= V_22 ;
V_23 ++ ;
}
return V_12 ;
}
static void F_17 ( const char * * V_26 )
{
if ( V_26 != V_24 )
F_9 ( V_26 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
const char * * V_27 ;
const struct V_28 * V_29 ;
struct V_15 * V_16 = V_2 -> V_2 . V_17 ;
struct V_30 V_12 ;
struct V_3 * V_4 ;
const char * V_31 ;
const T_1 * V_32 ;
int V_33 ;
int V_5 ;
int V_23 ;
const T_1 * V_34 ;
int V_35 ;
struct V_13 * * V_36 = NULL ;
T_2 V_37 ;
struct V_38 V_39 ;
bool V_40 ;
const char * V_41 = NULL ;
V_29 = F_19 ( V_42 , & V_2 -> V_2 ) ;
if ( ! V_29 )
return - V_43 ;
V_31 = V_29 -> V_44 ;
V_35 = ( F_20 ( V_16 ) + F_21 ( V_16 ) ) * sizeof( V_45 ) ;
F_22 ( V_16 , L_14 , & V_41 ) ;
V_34 = F_12 ( V_16 , L_15 , & V_23 ) ;
if ( V_23 % V_35 != 0 ) {
F_23 ( & V_2 -> V_2 , L_16 ,
V_2 -> V_2 . V_17 -> V_46 ) ;
V_33 = - V_43 ;
goto V_47;
}
V_23 /= V_35 ;
V_40 = F_24 ( V_16 , L_17 ) ;
V_33 = - V_48 ;
V_4 = F_25 ( & V_2 -> V_2 ,
sizeof( struct V_3 ) +
sizeof( struct V_49 ) * V_23 , V_25 ) ;
if ( ! V_4 )
goto V_47;
F_3 ( & V_2 -> V_2 , V_4 ) ;
V_36 = F_16 ( sizeof( * V_36 ) * V_23 , V_25 ) ;
if ( ! V_36 )
goto V_47;
for ( V_5 = 0 ; V_5 < V_23 ; V_5 ++ ) {
V_33 = - V_50 ;
if ( F_26 ( V_16 , V_5 , & V_12 ) ) {
continue;
}
F_27 ( & V_2 -> V_2 , L_18 , & V_12 ) ;
V_33 = - V_51 ;
V_37 = F_28 ( & V_12 ) ;
V_4 -> V_7 [ V_5 ] . V_12 = F_29 ( V_12 . V_52 , V_37 ,
F_30 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 -> V_7 [ V_5 ] . V_12 )
goto V_53;
V_33 = - V_50 ;
V_32 = F_12 ( V_16 , L_19 , NULL ) ;
if ( ! V_32 ) {
F_23 ( & V_2 -> V_2 , L_20
L_21 ) ;
goto V_53;
}
V_4 -> V_7 [ V_5 ] . V_10 . V_54 = V_41 ? : F_30 ( & V_2 -> V_2 ) ;
V_4 -> V_7 [ V_5 ] . V_10 . V_55 = V_12 . V_52 ;
V_4 -> V_7 [ V_5 ] . V_10 . V_56 = V_37 ;
V_4 -> V_7 [ V_5 ] . V_10 . V_57 = F_31 ( V_32 ) ;
V_4 -> V_7 [ V_5 ] . V_10 . V_15 = V_16 ;
V_33 = - V_48 ;
V_4 -> V_7 [ V_5 ] . V_10 . V_11 = F_32 ( V_4 -> V_7 [ V_5 ] . V_10 . V_55 ,
V_4 -> V_7 [ V_5 ] . V_10 . V_56 ) ;
if ( ! V_4 -> V_7 [ V_5 ] . V_10 . V_11 ) {
F_23 ( & V_2 -> V_2 , L_22
L_23 ) ;
goto V_53;
}
F_33 ( & V_4 -> V_7 [ V_5 ] . V_10 ) ;
if ( V_40 )
V_4 -> V_7 [ V_5 ] . V_10 . V_55 = V_58 ;
if ( V_31 ) {
V_4 -> V_7 [ V_5 ] . V_8 = F_14 ( V_31 ,
& V_4 -> V_7 [ V_5 ] . V_10 ) ;
} else {
V_4 -> V_7 [ V_5 ] . V_8 = F_10 ( V_2 ,
& V_4 -> V_7 [ V_5 ] . V_10 ) ;
}
V_36 [ V_5 ] = V_4 -> V_7 [ V_5 ] . V_8 ;
V_33 = - V_50 ;
if ( ! V_4 -> V_7 [ V_5 ] . V_8 ) {
F_23 ( & V_2 -> V_2 , L_24 ) ;
goto V_53;
} else {
V_4 -> V_9 ++ ;
}
V_4 -> V_7 [ V_5 ] . V_8 -> V_59 = V_60 ;
V_4 -> V_7 [ V_5 ] . V_8 -> V_2 . V_61 = & V_2 -> V_2 ;
}
V_33 = 0 ;
V_4 -> V_6 = NULL ;
if ( V_4 -> V_9 == 1 ) {
V_4 -> V_6 = V_4 -> V_7 [ 0 ] . V_8 ;
} else if ( V_4 -> V_9 > 1 ) {
V_4 -> V_6 = F_34 ( V_36 , V_4 -> V_9 ,
F_30 ( & V_2 -> V_2 ) ) ;
}
if ( V_4 -> V_6 == NULL )
V_33 = - V_50 ;
if ( V_33 )
goto V_53;
V_39 . V_17 = V_16 ;
V_27 = F_15 ( V_16 ) ;
F_35 ( V_4 -> V_6 , V_27 , & V_39 ,
NULL , 0 ) ;
F_17 ( V_27 ) ;
F_9 ( V_36 ) ;
return 0 ;
V_53:
F_9 ( V_36 ) ;
V_47:
F_1 ( V_2 ) ;
return V_33 ;
}
