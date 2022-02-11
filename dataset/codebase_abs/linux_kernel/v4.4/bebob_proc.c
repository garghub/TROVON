static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( sizeof( struct V_8 ) , V_10 ) ;
if ( V_9 == NULL )
return;
if ( F_3 ( V_6 -> V_11 , 0 ,
V_9 , sizeof( struct V_8 ) ) < 0 )
goto V_12;
F_4 ( V_4 , L_1 ,
( char * ) & V_9 -> V_13 ) ;
F_4 ( V_4 , L_2 , V_9 -> V_14 ) ;
F_4 ( V_4 , L_3 , V_9 -> V_15 ) ;
F_4 ( V_4 , L_4 ,
V_9 -> V_16 [ 0 ] , V_9 -> V_16 [ 1 ] ) ;
F_4 ( V_4 , L_5 , V_9 -> V_17 ) ;
F_4 ( V_4 , L_6 , V_9 -> V_18 ) ;
F_4 ( V_4 , L_7 , ( char * ) & V_9 -> V_19 ) ;
F_4 ( V_4 , L_8 , ( char * ) & V_9 -> V_20 ) ;
F_4 ( V_4 , L_9 , V_9 -> V_21 ) ;
F_4 ( V_4 , L_10 , V_9 -> V_22 ) ;
F_4 ( V_4 , L_11 , V_9 -> V_23 ) ;
F_4 ( V_4 , L_12 , V_9 -> V_24 ) ;
F_4 ( V_4 , L_13 , ( char * ) & V_9 -> V_25 ) ;
F_4 ( V_4 , L_14 , ( char * ) & V_9 -> V_26 ) ;
V_12:
F_5 ( V_9 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const struct V_27 * V_28 = V_6 -> V_28 -> V_29 ;
T_1 * V_30 ;
unsigned int V_31 , V_32 , V_33 , V_34 ;
if ( V_28 == NULL )
return;
V_33 = V_28 -> V_35 * 2 ;
V_34 = V_33 * sizeof( T_1 ) ;
V_30 = F_7 ( V_34 , V_10 ) ;
if ( V_30 == NULL )
return;
if ( V_28 -> V_36 ( V_6 , V_30 , V_34 ) < 0 )
goto V_12;
for ( V_31 = 0 , V_32 = 1 ; V_31 < V_33 ; V_31 ++ ) {
F_4 ( V_4 , L_15 ,
V_28 -> V_37 [ V_31 / 2 ] , V_32 ++ , V_30 [ V_31 ] ) ;
if ( ( V_31 + 1 < V_33 - 1 ) &&
( strcmp ( V_28 -> V_37 [ V_31 / 2 ] ,
V_28 -> V_37 [ ( V_31 + 1 ) / 2 ] ) != 0 ) )
V_32 = 1 ;
}
V_12:
F_5 ( V_30 ) ;
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_38 * V_39 ;
unsigned int V_31 ;
F_4 ( V_4 , L_16 ) ;
F_4 ( V_4 , L_17 ) ;
V_39 = V_6 -> V_40 ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
F_4 ( V_4 ,
L_18 , V_42 [ V_31 ] ,
V_39 [ V_31 ] . V_43 , V_39 [ V_31 ] . V_44 ) ;
}
F_4 ( V_4 , L_19 ) ;
F_4 ( V_4 , L_17 ) ;
V_39 = V_6 -> V_45 ;
for ( V_31 = 0 ; V_31 < V_41 ; V_31 ++ ) {
F_4 ( V_4 ,
L_18 , V_42 [ V_31 ] ,
V_39 [ V_31 ] . V_43 , V_39 [ V_31 ] . V_44 ) ;
}
}
static void
F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_46 [] = {
L_20 ,
L_21 ,
L_22 ,
} ;
struct V_5 * V_6 = V_2 -> V_7 ;
const struct V_47 * V_48 = V_6 -> V_28 -> V_49 ;
const struct V_50 * V_51 = V_6 -> V_28 -> clock ;
enum V_52 V_53 ;
unsigned int V_49 ;
if ( V_48 -> V_36 ( V_6 , & V_49 ) >= 0 )
F_4 ( V_4 , L_23 , V_49 ) ;
if ( F_10 ( V_6 , & V_53 ) >= 0 ) {
if ( V_51 )
F_4 ( V_4 , L_24 ,
V_46 [ V_53 ] ) ;
else
F_4 ( V_4 , L_25 ,
V_46 [ V_53 ] , V_6 -> V_54 ) ;
}
}
static void
F_11 ( struct V_5 * V_6 , struct V_1 * V_55 , const char * V_56 ,
void (* F_12)( struct V_1 * V_57 , struct V_3 * V_58 ) )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_6 -> V_59 , V_56 , V_55 ) ;
if ( V_2 == NULL )
return;
F_14 ( V_2 , V_6 , F_12 ) ;
if ( F_15 ( V_2 ) < 0 )
F_16 ( V_2 ) ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_55 ;
V_55 = F_13 ( V_6 -> V_59 , L_26 ,
V_6 -> V_59 -> V_60 ) ;
if ( V_55 == NULL )
return;
V_55 -> V_61 = V_62 | V_63 | V_64 ;
if ( F_15 ( V_55 ) < 0 ) {
F_16 ( V_55 ) ;
return;
}
F_11 ( V_6 , V_55 , L_27 , F_9 ) ;
F_11 ( V_6 , V_55 , L_28 , F_1 ) ;
F_11 ( V_6 , V_55 , L_29 , F_8 ) ;
if ( V_6 -> V_28 -> V_29 != NULL )
F_11 ( V_6 , V_55 , L_30 , F_6 ) ;
}
