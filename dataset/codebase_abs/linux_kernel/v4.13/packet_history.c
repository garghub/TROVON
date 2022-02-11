int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 , V_3 , NULL ) ;
return V_1 == NULL ? - V_4 : 0 ;
}
void F_3 ( void )
{
if ( V_1 != NULL ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
}
}
int F_5 ( struct V_2 * * V_5 , T_2 V_6 )
{
struct V_2 * V_7 = F_6 ( V_1 , F_7 () ) ;
if ( V_7 == NULL )
return - V_4 ;
V_7 -> V_6 = V_6 ;
V_7 -> V_8 = F_8 () ;
V_7 -> V_9 = * V_5 ;
* V_5 = V_7 ;
return 0 ;
}
void F_9 ( struct V_2 * * V_5 )
{
struct V_2 * V_10 = * V_5 ;
while ( V_10 != NULL ) {
struct V_2 * V_9 = V_10 -> V_9 ;
F_10 ( V_1 , V_10 ) ;
V_10 = V_9 ;
}
* V_5 = NULL ;
}
int T_1 F_11 ( void )
{
V_11 = F_2 ( L_2 ,
sizeof( struct V_12 ) ,
0 , V_3 , NULL ) ;
return V_11 == NULL ? - V_4 : 0 ;
}
void F_12 ( void )
{
if ( V_11 != NULL ) {
F_4 ( V_11 ) ;
V_11 = NULL ;
}
}
static inline void F_13 ( struct V_12 * V_7 ,
const struct V_13 * V_14 ,
const T_2 V_15 )
{
const struct V_16 * V_17 = V_16 ( V_14 ) ;
V_7 -> V_18 = F_14 ( V_14 ) -> V_19 ;
V_7 -> V_20 = V_17 -> V_21 ;
V_7 -> V_22 = V_17 -> V_23 ;
V_7 -> V_24 = V_15 ;
V_7 -> V_25 = F_8 () ;
}
void F_15 ( struct V_26 * V_27 ,
const struct V_13 * V_14 ,
const T_2 V_15 )
{
struct V_12 * V_7 = F_16 ( V_27 ) ;
F_13 ( V_7 , V_14 , V_15 ) ;
}
int F_17 ( struct V_26 * V_27 , struct V_13 * V_14 )
{
const T_2 V_28 = F_14 ( V_14 ) -> V_19 ;
int V_29 ;
if ( F_18 ( F_19 ( V_27 ) -> V_18 , V_28 ) <= 0 )
return 1 ;
for ( V_29 = 1 ; V_29 <= V_27 -> V_30 ; V_29 ++ )
if ( V_12 ( V_27 , V_29 ) -> V_18 == V_28 )
return 1 ;
return 0 ;
}
static void F_20 ( struct V_26 * V_27 , const T_3 V_31 , const T_3 V_32 )
{
const T_3 V_33 = F_21 ( V_27 , V_31 ) ,
V_34 = F_21 ( V_27 , V_32 ) ;
struct V_12 * V_35 = V_27 -> V_36 [ V_33 ] ;
V_27 -> V_36 [ V_33 ] = V_27 -> V_36 [ V_34 ] ;
V_27 -> V_36 [ V_34 ] = V_35 ;
}
static void F_22 ( struct V_26 * V_27 , struct V_13 * V_14 , T_2 V_37 )
{
T_2 V_38 = F_19 ( V_27 ) -> V_18 ,
V_39 = F_14 ( V_14 ) -> V_19 ;
if ( ! F_23 ( V_38 , V_39 , V_37 ) ) {
V_27 -> V_30 = 1 ;
F_13 ( V_12 ( V_27 , 1 ) , V_14 , V_37 ) ;
}
}
static void F_24 ( struct V_26 * V_27 , struct V_13 * V_14 , T_4 V_40 )
{
T_2 V_38 = F_19 ( V_27 ) -> V_18 ,
V_39 = V_12 ( V_27 , 1 ) -> V_18 ,
V_41 = F_14 ( V_14 ) -> V_19 ;
if ( F_25 ( F_18 ( V_39 , V_41 ) > 0 ) ) {
V_27 -> V_30 = 2 ;
F_13 ( V_12 ( V_27 , 2 ) , V_14 , V_40 ) ;
return;
}
if ( F_23 ( V_38 , V_41 , V_40 ) ) {
T_2 V_37 = V_12 ( V_27 , 1 ) -> V_24 ;
if ( F_23 ( V_41 , V_39 , V_37 ) ) {
V_27 -> V_30 = 0 ;
V_27 -> V_42 = F_21 ( V_27 , 1 ) ;
} else
F_13 ( F_19 ( V_27 ) , V_14 , V_40 ) ;
} else {
F_20 ( V_27 , 0 , 3 ) ;
V_27 -> V_42 = F_21 ( V_27 , 3 ) ;
F_13 ( V_12 ( V_27 , 1 ) , V_14 , V_40 ) ;
V_27 -> V_30 = 2 ;
}
}
static int F_26 ( struct V_26 * V_27 , struct V_13 * V_14 , T_4 V_43 )
{
T_2 V_38 = F_19 ( V_27 ) -> V_18 ,
V_39 = V_12 ( V_27 , 1 ) -> V_18 ,
V_41 = V_12 ( V_27 , 2 ) -> V_18 ,
V_44 = F_14 ( V_14 ) -> V_19 ;
if ( F_25 ( F_18 ( V_41 , V_44 ) > 0 ) ) {
V_27 -> V_30 = 3 ;
F_13 ( V_12 ( V_27 , 3 ) , V_14 , V_43 ) ;
return 1 ;
}
if ( F_18 ( V_39 , V_44 ) > 0 ) {
F_20 ( V_27 , 2 , 3 ) ;
F_13 ( V_12 ( V_27 , 2 ) , V_14 , V_43 ) ;
V_27 -> V_30 = 3 ;
return 1 ;
}
if ( F_23 ( V_38 , V_44 , V_43 ) ) {
T_2 V_37 = V_12 ( V_27 , 1 ) -> V_24 ;
if ( F_23 ( V_44 , V_39 , V_37 ) ) {
T_2 V_40 = V_12 ( V_27 , 2 ) -> V_24 ;
if ( F_23 ( V_39 , V_41 , V_40 ) ) {
V_27 -> V_42 = F_21 ( V_27 , 2 ) ;
V_27 -> V_30 = 0 ;
} else {
V_27 -> V_42 = F_21 ( V_27 , 1 ) ;
V_27 -> V_30 = 1 ;
}
} else
F_13 ( F_19 ( V_27 ) , V_14 , V_43 ) ;
return 0 ;
}
F_20 ( V_27 , 0 , 3 ) ;
V_27 -> V_42 = F_21 ( V_27 , 3 ) ;
F_13 ( V_12 ( V_27 , 1 ) , V_14 , V_43 ) ;
V_27 -> V_30 = 3 ;
return 1 ;
}
static void F_27 ( struct V_26 * V_27 )
{
T_2 V_39 = V_12 ( V_27 , 1 ) -> V_18 ,
V_41 = V_12 ( V_27 , 2 ) -> V_18 ,
V_44 = V_12 ( V_27 , 3 ) -> V_18 ;
T_2 V_40 = V_12 ( V_27 , 2 ) -> V_24 ,
V_43 = V_12 ( V_27 , 3 ) -> V_24 ;
if ( F_23 ( V_39 , V_41 , V_40 ) ) {
if ( F_23 ( V_41 , V_44 , V_43 ) ) {
V_27 -> V_42 = F_21 ( V_27 , 3 ) ;
V_27 -> V_30 = 0 ;
} else {
V_27 -> V_42 = F_21 ( V_27 , 2 ) ;
V_27 -> V_30 = 1 ;
}
} else {
V_27 -> V_42 = F_21 ( V_27 , 1 ) ;
V_27 -> V_30 = 2 ;
}
}
int F_28 ( struct V_26 * V_27 ,
struct V_45 * V_46 ,
struct V_13 * V_14 , const T_2 V_15 ,
T_4 (* F_29)( struct V_47 * ) , struct V_47 * V_48 )
{
int V_49 = 0 ;
if ( V_27 -> V_30 == 0 ) {
F_22 ( V_27 , V_14 , V_15 ) ;
} else if ( V_27 -> V_30 == 1 ) {
F_24 ( V_27 , V_14 , V_15 ) ;
} else if ( V_27 -> V_30 != 2 ) {
F_30 ( L_3 , V_27 -> V_30 ) ;
} else if ( F_26 ( V_27 , V_14 , V_15 ) ) {
V_49 = F_31 ( V_46 , V_27 , F_29 , V_48 ) ;
F_27 ( V_27 ) ;
}
return V_49 ;
}
int F_32 ( struct V_26 * V_27 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 <= V_50 ; V_29 ++ ) {
V_27 -> V_36 [ V_29 ] = F_6 ( V_11 , V_51 ) ;
if ( V_27 -> V_36 [ V_29 ] == NULL )
goto V_52;
}
V_27 -> V_30 = V_27 -> V_42 = 0 ;
return 0 ;
V_52:
while ( V_29 -- != 0 ) {
F_10 ( V_11 , V_27 -> V_36 [ V_29 ] ) ;
V_27 -> V_36 [ V_29 ] = NULL ;
}
return - V_4 ;
}
void F_33 ( struct V_26 * V_27 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 <= V_50 ; ++ V_29 )
if ( V_27 -> V_36 [ V_29 ] != NULL ) {
F_10 ( V_11 , V_27 -> V_36 [ V_29 ] ) ;
V_27 -> V_36 [ V_29 ] = NULL ;
}
}
static inline struct V_12 *
F_34 ( const struct V_26 * V_27 )
{
return V_27 -> V_36 [ 0 ] ;
}
static inline struct V_12 *
F_35 ( const struct V_26 * V_27 )
{
return V_27 -> V_36 [ V_27 -> V_53 ] ;
}
T_4 F_36 ( struct V_26 * V_27 , const struct V_13 * V_14 )
{
T_4 V_54 = 0 ,
V_55 = F_37 ( V_16 ( V_14 ) -> V_21 ,
F_34 ( V_27 ) -> V_20 ) ;
if ( V_55 < 1 || V_55 > 4 ) {
if ( V_27 -> V_53 == 2 ) {
V_54 = F_37 ( F_35 ( V_27 ) -> V_20 ,
F_34 ( V_27 ) -> V_20 ) ;
if ( V_54 )
V_54 = 4 / V_54 *
F_38 ( F_35 ( V_27 ) -> V_25 ,
F_34 ( V_27 ) -> V_25 ) ;
else
F_30 ( L_4
L_5 ,
F_35 ( V_27 ) -> V_20 ,
F_34 ( V_27 ) -> V_20 ) ;
} else if ( V_55 < 1 ) {
V_27 -> V_53 = 1 ;
goto V_56;
}
} else if ( V_55 == 4 )
V_54 = F_39 ( F_40 ( F_34 ( V_27 ) -> V_25 ) ) ;
else {
V_27 -> V_53 = 2 ;
goto V_56;
}
if ( F_41 ( V_54 > V_57 ) ) {
F_42 ( L_6 , V_54 ) ;
V_54 = V_57 ;
}
V_27 -> V_53 = 0 ;
V_56:
return V_54 ;
}
