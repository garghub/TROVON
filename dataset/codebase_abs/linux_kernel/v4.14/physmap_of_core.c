static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( & V_2 -> V_2 ) ;
if ( ! V_4 )
return 0 ;
F_3 ( & V_2 -> V_2 , NULL ) ;
if ( V_4 -> V_6 ) {
F_4 ( V_4 -> V_6 ) ;
if ( V_4 -> V_6 != V_4 -> V_7 [ 0 ] . V_8 )
F_5 ( V_4 -> V_6 ) ;
}
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
int V_5 ;
F_11 ( & V_2 -> V_2 , L_1
L_2 ) ;
V_18 = F_12 ( V_16 , L_3 , NULL ) ;
if ( ! V_18 ) {
for ( V_5 = 0 ; V_5 < F_13 ( V_19 ) ; V_5 ++ ) {
V_8 = F_14 ( V_19 [ V_5 ] , V_10 ) ;
if ( V_8 )
return V_8 ;
}
return NULL ;
} else if ( strcmp ( V_18 , L_4 ) == 0 ) {
return F_14 ( L_5 , V_10 ) ;
} else if ( strcmp ( V_18 , L_6 ) == 0 ) {
return F_14 ( L_7 , V_10 ) ;
} else {
if ( strcmp ( V_18 , L_8 ) != 0 )
F_11 ( & V_2 -> V_2 , L_9
L_10 , V_18 ) ;
return F_14 ( L_11 , V_10 ) ;
}
}
static const char * const * F_15 ( struct V_15 * V_16 )
{
const char * * V_12 ;
int V_20 ;
V_20 = F_16 ( V_16 , L_12 ) ;
if ( V_20 < 0 )
return V_21 ;
V_12 = F_17 ( ( V_20 + 1 ) * sizeof( * V_12 ) , V_22 ) ;
if ( ! V_12 )
return NULL ;
V_20 = F_18 ( V_16 , L_12 , V_12 ,
V_20 ) ;
if ( V_20 < 0 )
return NULL ;
return V_12 ;
}
static void F_19 ( const char * const * V_23 )
{
if ( V_23 != V_21 )
F_9 ( V_23 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
const char * const * V_24 ;
const struct V_25 * V_26 ;
struct V_15 * V_16 = V_2 -> V_2 . V_17 ;
struct V_27 V_12 ;
struct V_3 * V_4 ;
const char * V_28 ;
const T_1 * V_29 ;
int V_30 ;
int V_5 ;
int V_20 ;
const T_1 * V_31 ;
int V_32 ;
struct V_13 * * V_33 = NULL ;
T_2 V_34 ;
bool V_35 ;
const char * V_36 = NULL ;
V_26 = F_21 ( V_37 , & V_2 -> V_2 ) ;
if ( ! V_26 )
return - V_38 ;
V_28 = V_26 -> V_39 ;
V_32 = ( F_22 ( V_16 ) + F_23 ( V_16 ) ) * sizeof( V_40 ) ;
F_24 ( V_16 , L_13 , & V_36 ) ;
V_31 = F_12 ( V_16 , L_14 , & V_20 ) ;
if ( ! V_31 || V_20 % V_32 != 0 ) {
F_25 ( & V_2 -> V_2 , L_15 ,
V_2 -> V_2 . V_17 ) ;
V_30 = - V_38 ;
goto V_41;
}
V_20 /= V_32 ;
V_35 = F_26 ( V_16 , L_16 ) ;
V_30 = - V_42 ;
V_4 = F_27 ( & V_2 -> V_2 ,
sizeof( struct V_3 ) +
sizeof( struct V_43 ) * V_20 , V_22 ) ;
if ( ! V_4 )
goto V_41;
F_3 ( & V_2 -> V_2 , V_4 ) ;
V_33 = F_17 ( sizeof( * V_33 ) * V_20 , V_22 ) ;
if ( ! V_33 )
goto V_41;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ ) {
V_30 = - V_44 ;
if ( F_28 ( V_16 , V_5 , & V_12 ) ) {
continue;
}
F_29 ( & V_2 -> V_2 , L_17 , & V_12 ) ;
V_30 = - V_45 ;
V_34 = F_30 ( & V_12 ) ;
V_4 -> V_7 [ V_5 ] . V_12 = F_31 ( V_12 . V_46 , V_34 ,
F_32 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 -> V_7 [ V_5 ] . V_12 )
goto V_47;
V_30 = - V_44 ;
V_29 = F_12 ( V_16 , L_18 , NULL ) ;
if ( ! V_29 ) {
F_25 ( & V_2 -> V_2 , L_19
L_20 ) ;
goto V_47;
}
V_4 -> V_7 [ V_5 ] . V_10 . V_48 = V_36 ? : F_32 ( & V_2 -> V_2 ) ;
V_4 -> V_7 [ V_5 ] . V_10 . V_49 = V_12 . V_46 ;
V_4 -> V_7 [ V_5 ] . V_10 . V_50 = V_34 ;
V_4 -> V_7 [ V_5 ] . V_10 . V_51 = F_33 ( V_29 ) ;
V_4 -> V_7 [ V_5 ] . V_10 . V_15 = V_16 ;
V_30 = F_34 ( V_2 , V_16 , & V_4 -> V_7 [ V_5 ] . V_10 ) ;
if ( V_30 )
goto V_47;
V_30 = F_35 ( V_2 , V_16 , & V_4 -> V_7 [ V_5 ] . V_10 ) ;
if ( V_30 )
goto V_47;
V_30 = - V_42 ;
V_4 -> V_7 [ V_5 ] . V_10 . V_11 = F_36 ( V_4 -> V_7 [ V_5 ] . V_10 . V_49 ,
V_4 -> V_7 [ V_5 ] . V_10 . V_50 ) ;
if ( ! V_4 -> V_7 [ V_5 ] . V_10 . V_11 ) {
F_25 ( & V_2 -> V_2 , L_21
L_22 ) ;
goto V_47;
}
F_37 ( & V_4 -> V_7 [ V_5 ] . V_10 ) ;
if ( V_35 )
V_4 -> V_7 [ V_5 ] . V_10 . V_49 = V_52 ;
if ( V_28 ) {
V_4 -> V_7 [ V_5 ] . V_8 = F_14 ( V_28 ,
& V_4 -> V_7 [ V_5 ] . V_10 ) ;
} else {
V_4 -> V_7 [ V_5 ] . V_8 = F_10 ( V_2 ,
& V_4 -> V_7 [ V_5 ] . V_10 ) ;
}
if ( ! V_4 -> V_7 [ V_5 ] . V_8 ) {
F_11 ( & V_2 -> V_2 ,
L_23 ,
V_28 ) ;
V_4 -> V_7 [ V_5 ] . V_8 = F_14 ( L_11 ,
& V_4 -> V_7 [ V_5 ] . V_10 ) ;
}
V_33 [ V_5 ] = V_4 -> V_7 [ V_5 ] . V_8 ;
V_30 = - V_44 ;
if ( ! V_4 -> V_7 [ V_5 ] . V_8 ) {
F_25 ( & V_2 -> V_2 , L_24 ) ;
goto V_47;
} else {
V_4 -> V_9 ++ ;
}
V_4 -> V_7 [ V_5 ] . V_8 -> V_2 . V_53 = & V_2 -> V_2 ;
}
V_30 = 0 ;
V_4 -> V_6 = NULL ;
if ( V_4 -> V_9 == 1 ) {
V_4 -> V_6 = V_4 -> V_7 [ 0 ] . V_8 ;
} else if ( V_4 -> V_9 > 1 ) {
V_4 -> V_6 = F_38 ( V_33 , V_4 -> V_9 ,
F_32 ( & V_2 -> V_2 ) ) ;
}
if ( V_4 -> V_6 == NULL )
V_30 = - V_44 ;
if ( V_30 )
goto V_47;
V_4 -> V_6 -> V_2 . V_53 = & V_2 -> V_2 ;
F_39 ( V_4 -> V_6 , V_16 ) ;
V_24 = F_15 ( V_16 ) ;
if ( ! V_24 ) {
V_30 = - V_42 ;
goto V_47;
}
F_40 ( V_4 -> V_6 , V_24 , NULL ,
NULL , 0 ) ;
F_19 ( V_24 ) ;
F_9 ( V_33 ) ;
return 0 ;
V_47:
F_9 ( V_33 ) ;
V_41:
F_1 ( V_2 ) ;
return V_30 ;
}
