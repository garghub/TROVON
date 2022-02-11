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
const struct V_16 * V_17 ;
struct V_16 V_18 ;
int V_19 = V_13 -> V_19 ;
const struct V_1 * V_2 = V_13 -> V_2 ;
int V_3 = V_13 -> V_3 ;
#ifdef F_3
int V_6 = 0 ;
#endif
if ( V_19 == V_20 )
F_4 ( V_15 , V_13 -> V_21 ) ;
do {
V_17 = F_5 ( V_10 , V_11 , sizeof( V_18 ) , & V_18 ) ;
if ( V_17 == NULL || V_17 -> V_22 == 0 ) {
F_6 ( L_1 ) ;
* V_14 = true ;
return false ;
}
#ifdef F_3
F_6 ( L_2
L_3 ,
++ V_6 , V_11 , V_17 -> type , F_7 ( V_17 -> V_22 ) ,
V_17 -> V_23 ) ;
#endif
V_11 += F_8 ( F_9 ( V_17 -> V_22 ) ) ;
F_6 ( L_4 , V_10 -> V_24 , V_11 ) ;
if ( F_10 ( V_13 -> V_21 , V_17 -> type ) ) {
switch ( V_19 ) {
case V_25 :
if ( F_1 ( V_2 , V_3 ,
V_17 -> type , V_17 -> V_23 ) ) {
return true ;
}
break;
case V_20 :
if ( F_1 ( V_2 , V_3 ,
V_17 -> type , V_17 -> V_23 ) )
F_11 ( V_15 , V_17 -> type ) ;
break;
case V_26 :
if ( ! F_1 ( V_2 , V_3 ,
V_17 -> type , V_17 -> V_23 ) )
return false ;
break;
}
} else {
switch ( V_19 ) {
case V_26 :
return false ;
}
}
} while ( V_11 < V_10 -> V_24 );
switch ( V_19 ) {
case V_20 :
return F_12 ( V_15 ) ;
case V_25 :
return false ;
case V_26 :
return true ;
}
return false ;
}
static bool
F_13 ( const struct V_9 * V_10 , struct V_27 * V_28 )
{
const struct V_12 * V_13 = V_28 -> V_29 ;
const struct V_30 * V_31 ;
struct V_30 V_32 ;
if ( V_28 -> V_33 != 0 ) {
F_6 ( L_5 ) ;
return false ;
}
V_31 = F_5 ( V_10 , V_28 -> V_34 , sizeof( V_32 ) , & V_32 ) ;
if ( V_31 == NULL ) {
F_6 ( L_6 ) ;
V_28 -> V_14 = true ;
return false ;
}
F_6 ( L_7 , F_9 ( V_31 -> V_35 ) , F_9 ( V_31 -> V_36 ) ) ;
return F_14 ( F_9 ( V_31 -> V_35 ) >= V_13 -> V_37 [ 0 ]
&& F_9 ( V_31 -> V_35 ) <= V_13 -> V_37 [ 1 ] ,
V_38 , V_13 -> V_23 , V_13 -> V_39 ) &&
F_14 ( F_9 ( V_31 -> V_36 ) >= V_13 -> V_40 [ 0 ]
&& F_9 ( V_31 -> V_36 ) <= V_13 -> V_40 [ 1 ] ,
V_41 , V_13 -> V_23 , V_13 -> V_39 ) &&
F_14 ( F_2 ( V_10 , V_28 -> V_34 + sizeof( V_32 ) ,
V_13 , & V_28 -> V_14 ) ,
V_42 , V_13 -> V_23 , V_13 -> V_39 ) ;
}
static int F_15 ( const struct V_43 * V_28 )
{
const struct V_12 * V_13 = V_28 -> V_29 ;
if ( V_13 -> V_23 & ~ V_44 )
return - V_45 ;
if ( V_13 -> V_39 & ~ V_44 )
return - V_45 ;
if ( V_13 -> V_39 & ~ V_13 -> V_23 )
return - V_45 ;
if ( ! ( V_13 -> V_23 & V_42 ) )
return 0 ;
if ( V_13 -> V_19 & ( V_20 |
V_25 | V_26 ) )
return 0 ;
return - V_45 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( V_46 , F_18 ( V_46 ) ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( V_46 , F_18 ( V_46 ) ) ;
}
