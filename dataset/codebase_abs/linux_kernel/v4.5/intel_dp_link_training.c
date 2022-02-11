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
if ( ! V_1 -> V_23 )
memset ( V_1 -> V_14 , 0 , sizeof( V_1 -> V_14 ) ) ;
F_10 ( V_1 ) ;
return F_6 ( V_1 , V_15 ) ;
}
static bool
F_11 ( struct V_1 * V_1 )
{
int V_17 ;
F_10 ( V_1 ) ;
V_17 = F_8 ( & V_1 -> V_21 , V_24 ,
V_1 -> V_14 , V_1 -> V_9 ) ;
return V_17 == V_1 -> V_9 ;
}
static void
F_12 ( struct V_1 * V_1 )
{
int V_25 ;
T_1 V_26 ;
int V_27 , V_28 ;
T_1 V_29 [ 2 ] ;
T_1 V_30 , V_31 ;
if ( V_1 -> V_32 )
V_1 -> V_32 ( V_1 ) ;
F_13 ( V_1 , V_1 -> V_33 ,
& V_30 , & V_31 ) ;
V_29 [ 0 ] = V_30 ;
V_29 [ 1 ] = V_1 -> V_9 ;
if ( F_14 ( V_1 -> V_34 ) )
V_29 [ 1 ] |= V_35 ;
F_8 ( & V_1 -> V_21 , V_36 , V_29 , 2 ) ;
if ( V_1 -> V_37 )
F_8 ( & V_1 -> V_21 , V_38 ,
& V_31 , 1 ) ;
V_29 [ 0 ] = 0 ;
V_29 [ 1 ] = V_39 ;
F_8 ( & V_1 -> V_21 , V_40 , V_29 , 2 ) ;
V_1 -> V_41 |= V_42 ;
if ( ! F_9 ( V_1 ,
V_43 |
V_44 ) ) {
F_15 ( L_1 ) ;
return;
}
V_26 = 0xff ;
V_27 = 0 ;
V_28 = 0 ;
for (; ; ) {
T_1 V_2 [ V_3 ] ;
F_16 ( V_1 -> V_34 ) ;
if ( ! F_17 ( V_1 , V_2 ) ) {
F_15 ( L_2 ) ;
break;
}
if ( F_18 ( V_2 , V_1 -> V_9 ) ) {
F_19 ( L_3 ) ;
break;
}
if ( V_1 -> V_23 ) {
F_19 ( L_4 ) ;
V_1 -> V_23 = false ;
if ( ! F_9 ( V_1 ,
V_43 |
V_44 ) ) {
F_15 ( L_1 ) ;
return;
}
continue;
}
for ( V_25 = 0 ; V_25 < V_1 -> V_9 ; V_25 ++ )
if ( ( V_1 -> V_14 [ V_25 ] & V_12 ) == 0 )
break;
if ( V_25 == V_1 -> V_9 ) {
++ V_28 ;
if ( V_28 == 5 ) {
F_15 ( L_5 ) ;
break;
}
F_9 ( V_1 ,
V_43 |
V_44 ) ;
V_27 = 0 ;
continue;
}
if ( ( V_1 -> V_14 [ 0 ] & V_45 ) == V_26 ) {
++ V_27 ;
if ( V_27 == 5 ) {
F_15 ( L_6 ) ;
break;
}
} else
V_27 = 0 ;
V_26 = V_1 -> V_14 [ 0 ] & V_45 ;
F_1 ( V_1 , V_2 ) ;
if ( ! F_11 ( V_1 ) ) {
F_15 ( L_7 ) ;
break;
}
}
}
static T_2 F_20 ( struct V_1 * V_1 )
{
T_2 V_46 = V_47 ;
bool V_48 , V_49 ;
V_48 = F_21 ( V_1 ) ;
V_49 = F_22 ( V_1 -> V_34 ) ;
if ( V_48 && V_49 ) {
V_46 = V_50 ;
} else if ( V_1 -> V_33 == 540000 ) {
if ( ! V_48 )
F_19 ( L_8 ) ;
if ( ! V_49 )
F_19 ( L_9 ) ;
}
return V_46 ;
}
static void
F_23 ( struct V_1 * V_1 )
{
bool V_51 = false ;
int V_52 , V_53 ;
T_2 V_46 ;
V_46 = F_20 ( V_1 ) ;
if ( ! F_6 ( V_1 ,
V_46 |
V_44 ) ) {
F_15 ( L_10 ) ;
return;
}
V_52 = 0 ;
V_53 = 0 ;
V_51 = false ;
for (; ; ) {
T_1 V_2 [ V_3 ] ;
if ( V_53 > 5 ) {
F_15 ( L_11 ) ;
break;
}
F_24 ( V_1 -> V_34 ) ;
if ( ! F_17 ( V_1 , V_2 ) ) {
F_15 ( L_2 ) ;
break;
}
if ( ! F_18 ( V_2 ,
V_1 -> V_9 ) ) {
V_1 -> V_23 = false ;
F_12 ( V_1 ) ;
F_6 ( V_1 ,
V_46 |
V_44 ) ;
V_53 ++ ;
continue;
}
if ( F_25 ( V_2 ,
V_1 -> V_9 ) ) {
V_51 = true ;
break;
}
if ( V_52 > 5 ) {
V_1 -> V_23 = false ;
F_12 ( V_1 ) ;
F_6 ( V_1 ,
V_46 |
V_44 ) ;
V_52 = 0 ;
V_53 ++ ;
continue;
}
F_1 ( V_1 , V_2 ) ;
if ( ! F_11 ( V_1 ) ) {
F_15 ( L_7 ) ;
break;
}
++ V_52 ;
}
F_26 ( V_1 ) ;
if ( V_51 ) {
V_1 -> V_23 = true ;
F_19 ( L_12 ) ;
}
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
