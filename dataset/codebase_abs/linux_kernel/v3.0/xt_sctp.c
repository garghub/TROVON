static bool
F_1 ( const struct V_1 * V_2 ,
const int V_3 ,
T_1 V_4 ,
T_1 V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
if ( V_2 [ V_6 ] . V_4 == V_4 )
return ( V_5 & V_2 [ V_6 ] . V_7 ) == V_2 [ V_6 ] . V_8 ;
return true ;
}
static inline bool
F_2 ( const struct V_9 * V_10 ,
unsigned int V_11 ,
const struct V_12 * V_13 ,
bool * V_14 )
{
T_2 V_15 [ 256 / sizeof ( T_2 ) ] ;
const T_3 * V_16 ;
T_3 V_17 ;
int V_18 = V_13 -> V_18 ;
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_3 = V_13 -> V_3 ;
#ifdef F_3
int V_6 = 0 ;
#endif
if ( V_18 == V_19 )
F_4 ( V_15 , V_13 -> V_20 ) ;
do {
V_16 = F_5 ( V_10 , V_11 , sizeof( V_17 ) , & V_17 ) ;
if ( V_16 == NULL || V_16 -> V_21 == 0 ) {
F_6 ( L_1 ) ;
* V_14 = true ;
return false ;
}
#ifdef F_3
F_6 ( L_2
L_3 ,
++ V_6 , V_11 , V_16 -> type , F_7 ( V_16 -> V_21 ) ,
V_16 -> V_22 ) ;
#endif
V_11 += F_8 ( F_9 ( V_16 -> V_21 ) ) ;
F_6 ( L_4 , V_10 -> V_23 , V_11 ) ;
if ( F_10 ( V_13 -> V_20 , V_16 -> type ) ) {
switch ( V_18 ) {
case V_24 :
if ( F_1 ( V_2 , V_3 ,
V_16 -> type , V_16 -> V_22 ) ) {
return true ;
}
break;
case V_19 :
if ( F_1 ( V_2 , V_3 ,
V_16 -> type , V_16 -> V_22 ) )
F_11 ( V_15 , V_16 -> type ) ;
break;
case V_25 :
if ( ! F_1 ( V_2 , V_3 ,
V_16 -> type , V_16 -> V_22 ) )
return false ;
break;
}
} else {
switch ( V_18 ) {
case V_25 :
return false ;
}
}
} while ( V_11 < V_10 -> V_23 );
switch ( V_18 ) {
case V_19 :
return F_12 ( V_15 ) ;
case V_24 :
return false ;
case V_25 :
return true ;
}
return false ;
}
static bool
F_13 ( const struct V_9 * V_10 , struct V_26 * V_27 )
{
const struct V_12 * V_13 = V_27 -> V_28 ;
const T_4 * V_29 ;
T_4 V_30 ;
if ( V_27 -> V_31 != 0 ) {
F_6 ( L_5 ) ;
return false ;
}
V_29 = F_5 ( V_10 , V_27 -> V_32 , sizeof( V_30 ) , & V_30 ) ;
if ( V_29 == NULL ) {
F_6 ( L_6 ) ;
V_27 -> V_14 = true ;
return false ;
}
F_6 ( L_7 , F_9 ( V_29 -> V_33 ) , F_9 ( V_29 -> V_34 ) ) ;
return F_14 ( F_9 ( V_29 -> V_33 ) >= V_13 -> V_35 [ 0 ]
&& F_9 ( V_29 -> V_33 ) <= V_13 -> V_35 [ 1 ] ,
V_36 , V_13 -> V_22 , V_13 -> V_37 )
&& F_14 ( F_9 ( V_29 -> V_34 ) >= V_13 -> V_38 [ 0 ]
&& F_9 ( V_29 -> V_34 ) <= V_13 -> V_38 [ 1 ] ,
V_39 , V_13 -> V_22 , V_13 -> V_37 )
&& F_14 ( F_2 ( V_10 , V_27 -> V_32 + sizeof( T_4 ) ,
V_13 , & V_27 -> V_14 ) ,
V_40 , V_13 -> V_22 , V_13 -> V_37 ) ;
}
static int F_15 ( const struct V_41 * V_27 )
{
const struct V_12 * V_13 = V_27 -> V_28 ;
if ( V_13 -> V_22 & ~ V_42 )
return - V_43 ;
if ( V_13 -> V_37 & ~ V_42 )
return - V_43 ;
if ( V_13 -> V_37 & ~ V_13 -> V_22 )
return - V_43 ;
if ( ! ( V_13 -> V_22 & V_40 ) )
return 0 ;
if ( V_13 -> V_18 & ( V_19 |
V_24 | V_25 ) )
return 0 ;
return - V_43 ;
}
static int T_5 F_16 ( void )
{
return F_17 ( V_44 , F_18 ( V_44 ) ) ;
}
static void T_6 F_19 ( void )
{
F_20 ( V_44 , F_18 ( V_44 ) ) ;
}
