int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
F_2 ( ( unsigned long long ) V_4 -> V_8 , V_6 ) ;
F_3 ( V_4 -> V_8 < V_9 ) ;
F_3 ( F_4 ( V_4 ) ) ;
if ( F_5 ( V_2 ) ) {
V_7 = - V_10 ;
F_6 ( V_7 ) ;
goto V_11;
}
F_7 ( V_6 ) ;
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
V_4 -> V_12 = V_13 ;
F_12 ( V_14 , V_4 ) ;
F_13 ( V_4 ) ;
if ( F_14 ( V_4 ) ) {
F_15 ( V_6 , V_4 ) ;
} else {
V_7 = - V_15 ;
F_6 ( V_7 ) ;
}
F_16 ( V_6 ) ;
V_11:
return V_7 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_16 ,
unsigned int V_17 , struct V_3 * V_18 [] )
{
int V_19 = 0 ;
unsigned int V_20 ;
struct V_3 * V_4 ;
F_18 ( ( unsigned long long ) V_16 , V_17 ) ;
if ( ! V_17 )
goto V_21;
for ( V_20 = 0 ; V_20 < V_17 ; V_20 ++ ) {
if ( V_18 [ V_20 ] == NULL ) {
V_18 [ V_20 ] = F_19 ( V_2 -> V_22 , V_16 ++ ) ;
if ( V_18 [ V_20 ] == NULL ) {
V_19 = - V_23 ;
F_6 ( V_19 ) ;
goto V_21;
}
}
V_4 = V_18 [ V_20 ] ;
if ( F_4 ( V_4 ) ) {
F_20 (
( unsigned long long ) V_4 -> V_8 ) ;
continue;
}
if ( F_21 ( V_4 ) ) {
F_22 ( V_24 ,
L_1
L_2 ,
( unsigned long long ) V_4 -> V_8 ) ;
continue;
}
F_8 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
F_22 ( V_24 ,
L_3
L_4 ,
( unsigned long long ) V_4 -> V_8 ) ;
F_23 () ;
}
F_24 ( V_4 ) ;
F_11 ( V_4 ) ;
V_4 -> V_12 = V_25 ;
F_12 ( V_26 , V_4 ) ;
}
for ( V_20 = V_17 ; V_20 > 0 ; V_20 -- ) {
V_4 = V_18 [ V_20 - 1 ] ;
if ( ! F_4 ( V_4 ) )
F_13 ( V_4 ) ;
if ( ! F_14 ( V_4 ) ) {
V_19 = - V_15 ;
F_25 ( V_4 ) ;
V_18 [ V_20 - 1 ] = NULL ;
}
}
V_21:
return V_19 ;
}
int F_26 ( struct V_5 * V_6 , T_1 V_16 , int V_17 ,
struct V_3 * V_18 [] , int V_27 ,
int (* F_27)( struct V_28 * V_22 ,
struct V_3 * V_4 ) )
{
int V_19 = 0 ;
int V_20 , V_29 = 0 ;
struct V_3 * V_4 ;
struct V_28 * V_22 = F_28 ( V_6 ) ;
F_29 ( V_6 , ( unsigned long long ) V_16 , V_17 , V_27 ) ;
F_3 ( ! V_6 ) ;
F_3 ( ( V_27 & V_30 ) &&
( V_27 & V_31 ) ) ;
if ( V_18 == NULL ) {
V_19 = - V_32 ;
F_6 ( V_19 ) ;
goto V_21;
}
if ( V_17 < 0 ) {
F_22 ( V_24 , L_5 , V_17 ) ;
V_19 = - V_32 ;
F_6 ( V_19 ) ;
goto V_21;
}
if ( V_17 == 0 ) {
V_19 = 0 ;
goto V_21;
}
F_7 ( V_6 ) ;
for ( V_20 = 0 ; V_20 < V_17 ; V_20 ++ ) {
if ( V_18 [ V_20 ] == NULL ) {
V_18 [ V_20 ] = F_19 ( V_22 , V_16 ++ ) ;
if ( V_18 [ V_20 ] == NULL ) {
F_16 ( V_6 ) ;
V_19 = - V_23 ;
F_6 ( V_19 ) ;
goto V_21;
}
}
V_4 = V_18 [ V_20 ] ;
V_29 = ( V_27 & V_31 ) ;
if ( ! V_29 && ! F_30 ( V_6 , V_4 ) ) {
F_31 (
( unsigned long long ) V_4 -> V_8 ,
( unsigned long long ) F_32 ( V_6 ) ) ;
V_29 = 1 ;
}
F_33 ( ( unsigned long long ) V_4 -> V_8 ,
V_29 , F_4 ( V_4 ) , F_21 ( V_4 ) ) ;
if ( F_4 ( V_4 ) ) {
continue;
}
if ( V_29 ) {
if ( F_21 ( V_4 ) ) {
continue;
}
if ( ( V_27 & V_30 )
&& F_34 ( V_6 , V_4 ) )
continue;
F_8 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
#ifdef F_35
F_22 ( V_24 , L_3
L_4 ,
( unsigned long long ) V_4 -> V_8 ) ;
F_23 () ;
#else
F_36 ( V_4 ) ;
continue;
#endif
}
if ( ! ( V_27 & V_31 )
&& ! ( V_27 & V_30 )
&& F_30 ( V_6 , V_4 ) ) {
F_36 ( V_4 ) ;
continue;
}
F_24 ( V_4 ) ;
F_11 ( V_4 ) ;
if ( F_27 )
F_37 ( V_4 ) ;
V_4 -> V_12 = V_25 ;
F_12 ( V_26 , V_4 ) ;
continue;
}
}
V_19 = 0 ;
for ( V_20 = ( V_17 - 1 ) ; V_20 >= 0 ; V_20 -- ) {
V_4 = V_18 [ V_20 ] ;
if ( ! ( V_27 & V_30 ) ) {
if ( V_19 ) {
F_25 ( V_4 ) ;
V_18 [ V_20 ] = NULL ;
continue;
}
if ( ! F_4 ( V_4 ) )
F_13 ( V_4 ) ;
if ( ! F_14 ( V_4 ) ) {
V_19 = - V_15 ;
F_25 ( V_4 ) ;
V_18 [ V_20 ] = NULL ;
continue;
}
if ( F_38 ( V_4 ) ) {
F_3 ( F_4 ( V_4 ) ) ;
F_39 ( V_4 ) ;
V_19 = F_27 ( V_22 , V_4 ) ;
if ( V_19 ) {
F_25 ( V_4 ) ;
V_18 [ V_20 ] = NULL ;
continue;
}
}
}
F_15 ( V_6 , V_4 ) ;
}
F_16 ( V_6 ) ;
F_40 ( ( unsigned long long ) V_16 , V_17 ,
V_27 , V_29 ) ;
V_21:
return V_19 ;
}
static void F_41 ( struct V_28 * V_22 ,
T_2 V_33 )
{
int V_20 ;
T_1 V_34 ;
if ( V_33 == V_9 )
return;
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ ) {
V_34 = F_42 ( V_22 , V_20 ) ;
if ( V_34 == V_33 )
return;
}
F_23 () ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_7 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) V_4 -> V_38 ;
F_3 ( F_4 ( V_4 ) ) ;
F_41 ( V_2 -> V_22 , V_4 -> V_8 ) ;
if ( F_5 ( V_2 ) || F_44 ( V_2 ) ) {
V_7 = - V_10 ;
F_6 ( V_7 ) ;
goto V_11;
}
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
V_4 -> V_12 = V_13 ;
F_45 ( V_2 -> V_22 , V_4 -> V_38 , & V_37 -> V_39 ) ;
F_12 ( V_14 , V_4 ) ;
F_13 ( V_4 ) ;
if ( ! F_14 ( V_4 ) ) {
V_7 = - V_15 ;
F_6 ( V_7 ) ;
}
V_11:
return V_7 ;
}
