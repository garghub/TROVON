static void F_1 ( T_1 * V_1 )
{
T_2 V_2 , V_3 ;
if ( V_4 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
struct V_6 * V_7 = V_4 + V_2 ;
F_2 ( V_7 -> V_8 ) ;
for ( V_3 = 0 ; V_3 < V_7 -> V_9 ; V_3 ++ ) {
F_2 ( V_7 -> V_10 [ V_3 ] . V_11 ) ;
F_2 ( V_7 -> V_10 [ V_3 ] . V_12 ) ;
}
F_2 ( V_7 -> V_10 ) ;
}
F_2 ( V_4 ) ;
V_4 = NULL ;
V_5 = 0 ;
}
static int F_3 ( T_1 * V_1 , const T_3 * V_13 )
{
T_2 V_2 , V_3 , V_14 ;
int V_15 = 0 ;
const char * V_16 ;
F_4 ( V_17 ) * V_18 ;
V_16 = F_5 ( V_1 ) ;
V_18 = F_6 ( V_13 , V_16 ) ;
if ( F_7 ( V_18 ) <= 0 ) {
if ( V_18 == NULL )
F_8 ( V_19 , V_20 ) ;
else
F_8 ( V_19 , V_21 ) ;
F_9 ( 2 , L_1 , V_16 ) ;
goto V_22;
}
V_14 = F_7 ( V_18 ) ;
V_4 = F_10 ( sizeof( * V_4 ) * V_14 ) ;
V_5 = V_14 ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
struct V_6 * V_23 = V_4 + V_2 ;
V_17 * V_24 = F_11 ( V_18 , V_2 ) ;
F_4 ( V_17 ) * V_10 = F_6 ( V_13 , V_24 -> V_25 ) ;
if ( F_7 ( V_10 ) <= 0 ) {
if ( V_10 == NULL )
F_8 ( V_19 ,
V_26 ) ;
else
F_8 ( V_19 , V_27 ) ;
F_9 ( 4 , L_2 , V_24 -> V_8 , L_3 , V_24 -> V_25 ) ;
goto V_22;
}
V_23 -> V_8 = F_12 ( V_24 -> V_8 ) ;
if ( V_23 -> V_8 == NULL )
goto V_22;
V_14 = F_7 ( V_10 ) ;
V_23 -> V_10 = F_10 ( V_14 * sizeof( struct V_28 ) ) ;
if ( V_23 -> V_10 == NULL )
goto V_22;
V_23 -> V_9 = V_14 ;
for ( V_3 = 0 ; V_3 < V_14 ; V_3 ++ ) {
const char * V_8 ;
V_17 * V_29 = F_11 ( V_10 , V_3 ) ;
struct V_28 * V_11 = V_23 -> V_10 + V_3 ;
V_8 = strchr ( V_29 -> V_8 , '.' ) ;
if ( V_8 != NULL )
V_8 ++ ;
else
V_8 = V_29 -> V_8 ;
V_11 -> V_11 = F_12 ( V_8 ) ;
V_11 -> V_12 = F_12 ( V_29 -> V_25 ) ;
if ( V_11 -> V_11 == NULL || V_11 -> V_12 == NULL )
goto V_22;
}
}
V_15 = 1 ;
V_22:
if ( V_15 == 0 )
F_1 ( V_1 ) ;
return V_15 ;
}
void F_13 ( void )
{
F_14 ( L_4 , F_3 , F_1 ) ;
}
static const struct V_6 * F_15 ( const char * V_8 )
{
T_2 V_2 ;
const struct V_6 * V_30 ;
if ( V_8 == NULL )
return NULL ;
for ( V_2 = 0 , V_30 = V_4 ; V_2 < V_5 ; V_2 ++ , V_30 ++ ) {
if ( strcmp ( V_30 -> V_8 , V_8 ) == 0 )
return V_30 ;
}
return NULL ;
}
static int F_16 ( T_4 * V_31 , T_5 * V_32 , const char * V_8 )
{
T_6 * V_33 = NULL ;
T_2 V_2 ;
int V_15 = 0 ;
unsigned int V_34 ;
const T_7 * V_35 ;
const struct V_6 * V_30 ;
struct V_28 * V_11 ;
if ( V_31 == NULL && V_32 == NULL ) {
F_8 ( V_36 , V_37 ) ;
goto V_22;
}
V_30 = F_15 ( V_8 ) ;
if ( V_30 == NULL ) {
F_8 ( V_36 , V_38 ) ;
F_9 ( 2 , L_2 , V_8 ) ;
goto V_22;
}
V_33 = F_17 () ;
if ( V_33 == NULL )
goto V_22;
V_34 = V_39 ;
V_34 |= V_40 | V_41 ;
if ( V_31 != NULL ) {
V_35 = V_31 -> V_42 ;
F_18 ( V_33 , V_31 ) ;
} else {
V_35 = V_32 -> V_42 ;
F_19 ( V_33 , V_32 ) ;
}
if ( V_35 -> V_43 != V_44 )
V_34 |= V_45 ;
if ( V_35 -> V_46 != V_44 )
V_34 |= V_47 ;
F_20 ( V_33 , V_34 ) ;
for ( V_2 = 0 , V_11 = V_30 -> V_10 ; V_2 < V_30 -> V_9 ; V_2 ++ , V_11 ++ ) {
V_15 = F_21 ( V_33 , V_11 -> V_11 , V_11 -> V_12 ) ;
if ( V_15 <= 0 ) {
if ( V_15 == - 2 )
F_8 ( V_36 , V_48 ) ;
else
F_8 ( V_36 , V_49 ) ;
F_9 ( 6 , L_1 , V_8 , L_5 , V_11 -> V_11 ,
L_6 , V_11 -> V_12 ) ;
goto V_22;
}
}
V_15 = F_22 ( V_33 ) ;
V_22:
F_23 ( V_33 ) ;
return V_15 <= 0 ? 0 : 1 ;
}
int F_24 ( T_4 * V_31 , const char * V_8 )
{
return F_16 ( V_31 , NULL , V_8 ) ;
}
int F_25 ( T_5 * V_32 , const char * V_8 )
{
return F_16 ( NULL , V_32 , V_8 ) ;
}
