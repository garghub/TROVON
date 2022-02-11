static void
F_1 ( struct V_1 * V_1 ,
const T_1 V_2 [ V_3 ] )
{
T_1 V_4 = 0 ;
T_1 V_5 = 0 ;
int V_6 ;
T_1 V_7 ;
T_1 V_8 ;
for ( V_6 = 0 ; V_6 < V_1 -> V_9 ; V_6 ++ ) {
T_1 V_10 = F_2 ( V_2 , V_6 ) ;
T_1 V_11 = F_3 ( V_2 , V_6 ) ;
if ( V_10 > V_4 )
V_4 = V_10 ;
if ( V_11 > V_5 )
V_5 = V_11 ;
}
V_7 = F_4 ( V_1 ) ;
if ( V_4 >= V_7 )
V_4 = V_7 | V_12 ;
V_8 = F_5 ( V_1 , V_4 ) ;
if ( V_5 >= V_8 )
V_5 = V_8 | V_13 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ )
V_1 -> V_14 [ V_6 ] = V_4 | V_5 ;
}
static bool
F_6 ( struct V_1 * V_1 ,
T_1 V_15 )
{
T_1 V_16 [ sizeof( V_1 -> V_14 ) + 1 ] ;
int V_17 , V_18 ;
F_7 ( V_1 , V_15 ) ;
V_16 [ 0 ] = V_15 ;
if ( ( V_15 & V_19 ) ==
V_20 ) {
V_18 = 1 ;
} else {
memcpy ( V_16 + 1 , V_1 -> V_14 , V_1 -> V_9 ) ;
V_18 = V_1 -> V_9 + 1 ;
}
V_17 = F_8 ( & V_1 -> V_21 , V_22 ,
V_16 , V_18 ) ;
return V_17 == V_18 ;
}
static bool
F_9 ( struct V_1 * V_1 ,
T_1 V_15 )
{
memset ( V_1 -> V_14 , 0 , sizeof( V_1 -> V_14 ) ) ;
F_10 ( V_1 ) ;
return F_6 ( V_1 , V_15 ) ;
}
static bool
F_11 ( struct V_1 * V_1 )
{
int V_17 ;
F_10 ( V_1 ) ;
V_17 = F_8 ( & V_1 -> V_21 , V_23 ,
V_1 -> V_14 , V_1 -> V_9 ) ;
return V_17 == V_1 -> V_9 ;
}
static void
F_12 ( struct V_1 * V_1 )
{
int V_24 ;
T_1 V_25 ;
int V_26 , V_27 ;
T_1 V_28 [ 2 ] ;
T_1 V_29 , V_30 ;
if ( V_1 -> V_31 )
V_1 -> V_31 ( V_1 ) ;
F_13 ( V_1 , V_1 -> V_32 ,
& V_29 , & V_30 ) ;
V_28 [ 0 ] = V_29 ;
V_28 [ 1 ] = V_1 -> V_9 ;
if ( F_14 ( V_1 -> V_33 ) )
V_28 [ 1 ] |= V_34 ;
F_8 ( & V_1 -> V_21 , V_35 , V_28 , 2 ) ;
if ( V_1 -> V_36 )
F_8 ( & V_1 -> V_21 , V_37 ,
& V_30 , 1 ) ;
V_28 [ 0 ] = 0 ;
V_28 [ 1 ] = V_38 ;
F_8 ( & V_1 -> V_21 , V_39 , V_28 , 2 ) ;
V_1 -> V_40 |= V_41 ;
if ( ! F_9 ( V_1 ,
V_42 |
V_43 ) ) {
F_15 ( L_1 ) ;
return;
}
V_25 = 0xff ;
V_26 = 0 ;
V_27 = 0 ;
for (; ; ) {
T_1 V_2 [ V_3 ] ;
F_16 ( V_1 -> V_33 ) ;
if ( ! F_17 ( V_1 , V_2 ) ) {
F_15 ( L_2 ) ;
break;
}
if ( F_18 ( V_2 , V_1 -> V_9 ) ) {
F_19 ( L_3 ) ;
break;
}
for ( V_24 = 0 ; V_24 < V_1 -> V_9 ; V_24 ++ )
if ( ( V_1 -> V_14 [ V_24 ] & V_12 ) == 0 )
break;
if ( V_24 == V_1 -> V_9 ) {
++ V_27 ;
if ( V_27 == 5 ) {
F_15 ( L_4 ) ;
break;
}
F_9 ( V_1 ,
V_42 |
V_43 ) ;
V_26 = 0 ;
continue;
}
if ( ( V_1 -> V_14 [ 0 ] & V_44 ) == V_25 ) {
++ V_26 ;
if ( V_26 == 5 ) {
F_15 ( L_5 ) ;
break;
}
} else
V_26 = 0 ;
V_25 = V_1 -> V_14 [ 0 ] & V_44 ;
F_1 ( V_1 , V_2 ) ;
if ( ! F_11 ( V_1 ) ) {
F_15 ( L_6 ) ;
break;
}
}
}
static T_2 F_20 ( struct V_1 * V_1 )
{
T_2 V_45 = V_46 ;
bool V_47 , V_48 ;
V_47 = F_21 ( V_1 ) ;
V_48 = F_22 ( V_1 -> V_33 ) ;
if ( V_47 && V_48 ) {
V_45 = V_49 ;
} else if ( V_1 -> V_32 == 540000 ) {
if ( ! V_47 )
F_19 ( L_7 ) ;
if ( ! V_48 )
F_19 ( L_8 ) ;
}
return V_45 ;
}
static void
F_23 ( struct V_1 * V_1 )
{
bool V_50 = false ;
int V_51 , V_52 ;
T_2 V_45 ;
V_45 = F_20 ( V_1 ) ;
if ( ! F_6 ( V_1 ,
V_45 |
V_43 ) ) {
F_15 ( L_9 ) ;
return;
}
V_51 = 0 ;
V_52 = 0 ;
V_50 = false ;
for (; ; ) {
T_1 V_2 [ V_3 ] ;
if ( V_52 > 5 ) {
F_15 ( L_10 ) ;
break;
}
F_24 ( V_1 -> V_33 ) ;
if ( ! F_17 ( V_1 , V_2 ) ) {
F_15 ( L_2 ) ;
break;
}
if ( ! F_18 ( V_2 ,
V_1 -> V_9 ) ) {
F_12 ( V_1 ) ;
F_6 ( V_1 ,
V_45 |
V_43 ) ;
V_52 ++ ;
continue;
}
if ( F_25 ( V_2 ,
V_1 -> V_9 ) ) {
V_50 = true ;
break;
}
if ( V_51 > 5 ) {
F_12 ( V_1 ) ;
F_6 ( V_1 ,
V_45 |
V_43 ) ;
V_51 = 0 ;
V_52 ++ ;
continue;
}
F_1 ( V_1 , V_2 ) ;
if ( ! F_11 ( V_1 ) ) {
F_15 ( L_6 ) ;
break;
}
++ V_51 ;
}
F_26 ( V_1 ) ;
if ( V_50 )
F_19 ( L_11 ) ;
}
void F_27 ( struct V_1 * V_1 )
{
F_6 ( V_1 ,
V_20 ) ;
}
void
F_28 ( struct V_1 * V_1 )
{
F_12 ( V_1 ) ;
F_23 ( V_1 ) ;
}
