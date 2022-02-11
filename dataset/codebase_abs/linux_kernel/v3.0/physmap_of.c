static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 , V_8 , V_9 ;
const struct {
T_1 V_10 , V_11 ;
} * V_12 ;
const char * V_13 ;
V_12 = F_2 ( V_6 , L_1 , & V_8 ) ;
if ( ! V_12 )
return 0 ;
F_3 ( & V_2 -> V_2 , L_2 ) ;
V_9 = V_8 / sizeof( V_12 [ 0 ] ) ;
V_4 -> V_14 = F_4 ( V_9 * sizeof( * V_4 -> V_14 ) , V_15 ) ;
if ( ! V_4 -> V_14 )
return - V_16 ;
V_13 = F_2 ( V_6 , L_3 , & V_8 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_4 -> V_14 [ V_7 ] . V_10 = F_5 ( V_12 -> V_10 ) ;
V_4 -> V_14 [ V_7 ] . V_17 = F_5 ( V_12 -> V_11 ) & ~ 1 ;
if ( F_5 ( V_12 -> V_11 ) & 1 )
V_4 -> V_14 [ V_7 ] . V_18 = V_19 ;
if ( V_13 && ( V_8 > 0 ) ) {
int V_11 = strlen ( V_13 ) + 1 ;
V_4 -> V_14 [ V_7 ] . V_20 = ( char * ) V_13 ;
V_8 -= V_11 ;
V_13 += V_11 ;
} else {
V_4 -> V_14 [ V_7 ] . V_20 = L_4 ;
}
V_12 ++ ;
}
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
V_4 = F_7 ( & V_2 -> V_2 ) ;
if ( ! V_4 )
return 0 ;
F_8 ( & V_2 -> V_2 , NULL ) ;
if ( V_4 -> V_21 != V_4 -> V_22 [ 0 ] . V_23 ) {
F_9 ( V_4 -> V_21 ) ;
F_10 ( V_4 -> V_21 ) ;
}
if ( V_4 -> V_21 ) {
if ( F_11 ( V_4 ) )
F_12 ( F_11 ( V_4 ) ) ;
F_9 ( V_4 -> V_21 ) ;
}
for ( V_7 = 0 ; V_7 < V_4 -> V_24 ; V_7 ++ ) {
if ( V_4 -> V_22 [ V_7 ] . V_23 )
F_13 ( V_4 -> V_22 [ V_7 ] . V_23 ) ;
if ( V_4 -> V_22 [ V_7 ] . V_25 . V_26 )
F_14 ( V_4 -> V_22 [ V_7 ] . V_25 . V_26 ) ;
if ( V_4 -> V_22 [ V_7 ] . V_27 ) {
F_15 ( V_4 -> V_22 [ V_7 ] . V_27 ) ;
F_12 ( V_4 -> V_22 [ V_7 ] . V_27 ) ;
}
}
F_12 ( V_4 ) ;
return 0 ;
}
static struct V_28 * T_2 F_16 ( struct V_1 * V_2 ,
struct V_29 * V_25 )
{
struct V_5 * V_6 = V_2 -> V_2 . V_30 ;
const char * V_31 ;
struct V_28 * V_23 ;
static const char * V_32 []
= { L_5 , L_6 , L_7 } ;
int V_7 ;
F_3 ( & V_2 -> V_2 , L_8
L_9 ) ;
V_31 = F_2 ( V_6 , L_10 , NULL ) ;
if ( ! V_31 ) {
for ( V_7 = 0 ; V_7 < F_17 ( V_32 ) ; V_7 ++ ) {
V_23 = F_18 ( V_32 [ V_7 ] , V_25 ) ;
if ( V_23 )
return V_23 ;
}
return NULL ;
} else if ( strcmp ( V_31 , L_11 ) == 0 ) {
return F_18 ( L_5 , V_25 ) ;
} else if ( strcmp ( V_31 , L_12 ) == 0 ) {
return F_18 ( L_6 , V_25 ) ;
} else {
if ( strcmp ( V_31 , L_13 ) != 0 )
F_3 ( & V_2 -> V_2 , L_14
L_15 , V_31 ) ;
return F_18 ( L_16 , V_25 ) ;
}
}
static const char * * T_2 F_19 ( struct V_5 * V_6 )
{
const char * V_33 ;
int V_34 ;
unsigned int V_35 ;
unsigned int V_36 ;
const char * * V_27 ;
V_33 = F_2 ( V_6 , L_17 , & V_34 ) ;
if ( V_33 == NULL )
return V_37 ;
V_36 = 0 ;
for ( V_35 = 0 ; V_35 != V_34 ; V_35 ++ )
if ( V_33 [ V_35 ] == 0 )
V_36 ++ ;
V_27 = F_4 ( ( V_36 + 1 ) * sizeof( * V_27 ) , V_15 ) ;
V_36 = 0 ;
while ( V_34 > 0 ) {
V_27 [ V_36 ] = V_33 ;
V_35 = strlen ( V_33 ) + 1 ;
V_33 += V_35 ;
V_34 -= V_35 ;
V_36 ++ ;
}
return V_27 ;
}
static void T_2 F_20 ( const char * * V_38 )
{
if ( V_38 != V_37 )
F_12 ( V_38 ) ;
}
static int T_2 F_21 ( struct V_1 * V_2 )
{
const char * * V_39 ;
const struct V_40 * V_41 ;
struct V_5 * V_6 = V_2 -> V_2 . V_30 ;
struct V_42 V_27 ;
struct V_3 * V_4 ;
const char * V_43 ;
const T_1 * V_44 ;
int V_45 ;
int V_7 ;
int V_36 ;
const T_1 * V_46 ;
int V_47 ;
struct V_28 * * V_48 = NULL ;
T_3 V_49 ;
V_41 = F_22 ( V_50 , & V_2 -> V_2 ) ;
if ( ! V_41 )
return - V_51 ;
V_43 = V_41 -> V_52 ;
V_47 = ( F_23 ( V_6 ) + F_24 ( V_6 ) ) * sizeof( V_53 ) ;
V_46 = F_2 ( V_6 , L_18 , & V_36 ) ;
if ( V_36 % V_47 != 0 ) {
F_25 ( & V_2 -> V_2 , L_19 ,
V_2 -> V_2 . V_30 -> V_54 ) ;
V_45 = - V_51 ;
goto V_55;
}
V_36 /= V_47 ;
V_45 = - V_16 ;
V_4 = F_4 ( sizeof( struct V_3 ) +
sizeof( struct V_56 ) * V_36 , V_15 ) ;
if ( ! V_4 )
goto V_55;
F_8 ( & V_2 -> V_2 , V_4 ) ;
V_48 = F_4 ( sizeof( * V_48 ) * V_36 , V_15 ) ;
if ( ! V_48 )
goto V_55;
for ( V_7 = 0 ; V_7 < V_36 ; V_7 ++ ) {
V_45 = - V_57 ;
if ( F_26 ( V_6 , V_7 , & V_27 ) ) {
continue;
}
F_27 ( & V_2 -> V_2 , L_20 , & V_27 ) ;
V_45 = - V_58 ;
V_49 = F_28 ( & V_27 ) ;
V_4 -> V_22 [ V_7 ] . V_27 = F_29 ( V_27 . V_59 , V_49 ,
F_30 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 -> V_22 [ V_7 ] . V_27 )
goto V_60;
V_45 = - V_57 ;
V_44 = F_2 ( V_6 , L_21 , NULL ) ;
if ( ! V_44 ) {
F_25 ( & V_2 -> V_2 , L_22
L_23 ) ;
goto V_60;
}
V_4 -> V_22 [ V_7 ] . V_25 . V_20 = F_30 ( & V_2 -> V_2 ) ;
V_4 -> V_22 [ V_7 ] . V_25 . V_61 = V_27 . V_59 ;
V_4 -> V_22 [ V_7 ] . V_25 . V_17 = V_49 ;
V_4 -> V_22 [ V_7 ] . V_25 . V_62 = F_31 ( V_44 ) ;
V_45 = - V_16 ;
V_4 -> V_22 [ V_7 ] . V_25 . V_26 = F_32 ( V_4 -> V_22 [ V_7 ] . V_25 . V_61 ,
V_4 -> V_22 [ V_7 ] . V_25 . V_17 ) ;
if ( ! V_4 -> V_22 [ V_7 ] . V_25 . V_26 ) {
F_25 ( & V_2 -> V_2 , L_24
L_25 ) ;
goto V_60;
}
F_33 ( & V_4 -> V_22 [ V_7 ] . V_25 ) ;
if ( V_43 ) {
V_4 -> V_22 [ V_7 ] . V_23 = F_18 ( V_43 ,
& V_4 -> V_22 [ V_7 ] . V_25 ) ;
} else {
V_4 -> V_22 [ V_7 ] . V_23 = F_16 ( V_2 ,
& V_4 -> V_22 [ V_7 ] . V_25 ) ;
}
V_48 [ V_7 ] = V_4 -> V_22 [ V_7 ] . V_23 ;
V_45 = - V_57 ;
if ( ! V_4 -> V_22 [ V_7 ] . V_23 ) {
F_25 ( & V_2 -> V_2 , L_26 ) ;
goto V_60;
} else {
V_4 -> V_24 ++ ;
}
V_4 -> V_22 [ V_7 ] . V_23 -> V_63 = V_64 ;
V_4 -> V_22 [ V_7 ] . V_23 -> V_2 . V_65 = & V_2 -> V_2 ;
}
V_45 = 0 ;
if ( V_4 -> V_24 == 1 ) {
V_4 -> V_21 = V_4 -> V_22 [ 0 ] . V_23 ;
} else if ( V_4 -> V_24 > 1 ) {
V_4 -> V_21 = F_34 ( V_48 , V_4 -> V_24 ,
F_30 ( & V_2 -> V_2 ) ) ;
if ( V_4 -> V_21 == NULL )
V_45 = - V_57 ;
}
if ( V_45 )
goto V_60;
V_39 = F_19 ( V_6 ) ;
V_45 = F_35 ( V_4 -> V_21 , V_39 ,
& V_4 -> V_14 , 0 ) ;
if ( V_45 < 0 ) {
F_20 ( V_39 ) ;
goto V_60;
}
F_20 ( V_39 ) ;
if ( V_45 == 0 ) {
V_45 = F_36 ( & V_2 -> V_2 , V_6 , & V_4 -> V_14 ) ;
if ( V_45 < 0 )
goto V_60;
}
if ( V_45 == 0 ) {
V_45 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_45 < 0 )
goto V_60;
}
F_37 ( V_4 -> V_21 , V_4 -> V_14 , V_45 ) ;
F_12 ( V_48 ) ;
return 0 ;
V_60:
F_12 ( V_48 ) ;
V_55:
F_6 ( V_2 ) ;
return V_45 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_66 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_66 ) ;
}
