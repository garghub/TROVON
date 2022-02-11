static void
F_1 ( const T_1 V_1 [ V_2 ] )
{
F_2 ( L_1 ,
V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] ,
V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
}
static void
F_3 ( struct V_3 * V_3 ,
const T_1 V_1 [ V_2 ] )
{
T_1 V_4 = 0 ;
T_1 V_5 = 0 ;
int V_6 ;
T_1 V_7 ;
T_1 V_8 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_9 ; V_6 ++ ) {
T_1 V_10 = F_4 ( V_1 , V_6 ) ;
T_1 V_11 = F_5 ( V_1 , V_6 ) ;
if ( V_10 > V_4 )
V_4 = V_10 ;
if ( V_11 > V_5 )
V_5 = V_11 ;
}
V_7 = F_6 ( V_3 ) ;
if ( V_4 >= V_7 )
V_4 = V_7 | V_12 ;
V_8 = F_7 ( V_3 , V_4 ) ;
if ( V_5 >= V_8 )
V_5 = V_8 | V_13 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ )
V_3 -> V_14 [ V_6 ] = V_4 | V_5 ;
}
static bool
F_8 ( struct V_3 * V_3 ,
T_1 V_15 )
{
T_1 V_16 [ sizeof( V_3 -> V_14 ) + 1 ] ;
int V_17 , V_18 ;
F_9 ( V_3 , V_15 ) ;
V_16 [ 0 ] = V_15 ;
if ( ( V_15 & V_19 ) ==
V_20 ) {
V_18 = 1 ;
} else {
memcpy ( V_16 + 1 , V_3 -> V_14 , V_3 -> V_9 ) ;
V_18 = V_3 -> V_9 + 1 ;
}
V_17 = F_10 ( & V_3 -> V_21 , V_22 ,
V_16 , V_18 ) ;
return V_17 == V_18 ;
}
static bool
F_11 ( struct V_3 * V_3 ,
T_1 V_15 )
{
memset ( V_3 -> V_14 , 0 , sizeof( V_3 -> V_14 ) ) ;
F_12 ( V_3 ) ;
return F_8 ( V_3 , V_15 ) ;
}
static bool
F_13 ( struct V_3 * V_3 )
{
int V_17 ;
F_12 ( V_3 ) ;
V_17 = F_10 ( & V_3 -> V_21 , V_23 ,
V_3 -> V_14 , V_3 -> V_9 ) ;
return V_17 == V_3 -> V_9 ;
}
static bool F_14 ( struct V_3 * V_3 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_9 ; V_6 ++ )
if ( ( V_3 -> V_14 [ V_6 ] &
V_12 ) == 0 )
return false ;
return true ;
}
static bool
F_15 ( struct V_3 * V_3 )
{
T_1 V_24 ;
int V_25 , V_26 ;
T_1 V_27 [ 2 ] ;
T_1 V_28 , V_29 ;
if ( V_3 -> V_30 )
V_3 -> V_30 ( V_3 ) ;
F_16 ( V_3 , V_3 -> V_31 ,
& V_28 , & V_29 ) ;
V_27 [ 0 ] = V_28 ;
V_27 [ 1 ] = V_3 -> V_9 ;
if ( F_17 ( V_3 -> V_32 ) )
V_27 [ 1 ] |= V_33 ;
F_10 ( & V_3 -> V_21 , V_34 , V_27 , 2 ) ;
if ( V_3 -> V_35 )
F_10 ( & V_3 -> V_21 , V_36 ,
& V_29 , 1 ) ;
V_27 [ 0 ] = 0 ;
V_27 [ 1 ] = V_37 ;
F_10 ( & V_3 -> V_21 , V_38 , V_27 , 2 ) ;
V_3 -> V_39 |= V_40 ;
if ( ! F_11 ( V_3 ,
V_41 |
V_42 ) ) {
F_18 ( L_2 ) ;
return false ;
}
V_25 = 1 ;
V_26 = 0 ;
for (; ; ) {
T_1 V_1 [ V_2 ] ;
F_19 ( V_3 -> V_32 ) ;
if ( ! F_20 ( V_3 , V_1 ) ) {
F_18 ( L_3 ) ;
return false ;
}
if ( F_21 ( V_1 , V_3 -> V_9 ) ) {
F_2 ( L_4 ) ;
return true ;
}
if ( V_25 == 5 ) {
F_2 ( L_5 ) ;
return false ;
}
if ( V_26 == 1 ) {
F_2 ( L_6 ) ;
return false ;
}
V_24 = V_3 -> V_14 [ 0 ] & V_43 ;
F_3 ( V_3 , V_1 ) ;
if ( ! F_13 ( V_3 ) ) {
F_18 ( L_7 ) ;
return false ;
}
if ( ( V_3 -> V_14 [ 0 ] & V_43 ) ==
V_24 )
++ V_25 ;
else
V_25 = 1 ;
if ( F_14 ( V_3 ) )
++ V_26 ;
}
}
static T_2 F_22 ( struct V_3 * V_3 )
{
T_2 V_44 = V_45 ;
bool V_46 , V_47 ;
V_46 = F_23 ( V_3 ) ;
V_47 = F_24 ( V_3 -> V_32 ) ;
if ( V_46 && V_47 ) {
V_44 = V_48 ;
} else if ( V_3 -> V_31 == 540000 ) {
if ( ! V_46 )
F_2 ( L_8 ) ;
if ( ! V_47 )
F_2 ( L_9 ) ;
}
return V_44 ;
}
static bool
F_25 ( struct V_3 * V_3 )
{
int V_49 ;
T_2 V_44 ;
T_1 V_1 [ V_2 ] ;
V_44 = F_22 ( V_3 ) ;
if ( ! F_8 ( V_3 ,
V_44 |
V_42 ) ) {
F_18 ( L_10 ) ;
return false ;
}
V_3 -> V_50 = false ;
for ( V_49 = 0 ; V_49 < 5 ; V_49 ++ ) {
F_26 ( V_3 -> V_32 ) ;
if ( ! F_20 ( V_3 , V_1 ) ) {
F_18 ( L_3 ) ;
break;
}
if ( ! F_21 ( V_1 ,
V_3 -> V_9 ) ) {
F_1 ( V_1 ) ;
F_2 ( L_11
L_12 ) ;
break;
}
if ( F_27 ( V_1 ,
V_3 -> V_9 ) ) {
V_3 -> V_50 = true ;
F_2 ( L_13
L_14 ) ;
break;
}
F_3 ( V_3 , V_1 ) ;
if ( ! F_13 ( V_3 ) ) {
F_18 ( L_7 ) ;
break;
}
}
if ( V_49 == 5 ) {
F_1 ( V_1 ) ;
F_2 ( L_15 ) ;
}
F_28 ( V_3 ) ;
return V_3 -> V_50 ;
}
void F_29 ( struct V_3 * V_3 )
{
F_8 ( V_3 ,
V_20 ) ;
}
void
F_30 ( struct V_3 * V_3 )
{
F_15 ( V_3 ) ;
F_25 ( V_3 ) ;
}
