void T_1 F_1 ( char * V_1 )
{
V_2 = V_1 ;
}
static int T_1 F_2 ( int V_3 , const struct V_4 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_7 ; V_6 ++ )
if ( V_5 -> V_8 [ V_6 ] . V_3 == V_3 )
return V_6 ;
return - V_9 ;
}
static int T_1 F_3 ( struct V_4 * V_10 ,
struct V_4 * V_11 ,
int V_3 , int V_12 , T_2 V_13 )
{
struct V_14 * V_15 = & V_10 -> V_8 [ V_10 -> V_7 ] ;
struct V_14 * V_16 = & V_11 -> V_8 [ V_12 ] ;
if ( V_10 -> V_7 >= V_17 ) {
F_4 ( L_1 ) ;
return - V_18 ;
}
V_10 -> V_7 ++ ;
V_15 -> V_19 = V_16 -> V_19 ;
V_15 -> V_20 = V_16 -> V_19 + V_13 ;
V_15 -> V_3 = V_3 ;
if ( V_21 [ V_3 ] == V_22 )
V_21 [ V_3 ] = V_16 -> V_3 ;
V_16 -> V_19 += V_13 ;
if ( V_16 -> V_19 >= V_16 -> V_20 ) {
F_5 ( V_16 -> V_19 > V_16 -> V_20 ) ;
F_6 ( V_12 , V_11 ) ;
}
F_7 ( V_23 L_2 , V_3 ,
V_15 -> V_19 , V_15 -> V_20 , ( V_15 -> V_20 - V_15 -> V_19 ) >> 20 ) ;
return 0 ;
}
static int T_1 F_8 ( struct V_4 * V_10 ,
struct V_4 * V_11 ,
T_2 V_24 , T_2 V_25 , int V_26 )
{
T_3 V_27 = V_28 ;
T_2 V_13 ;
int V_29 ;
int V_3 = 0 ;
int V_6 , V_30 ;
if ( V_26 <= 0 )
return - 1 ;
if ( V_26 > V_31 ) {
F_9 ( L_3 ,
V_26 , V_31 ) ;
V_26 = V_31 ;
}
V_13 = V_25 - V_24 - F_10 ( V_24 , V_25 ) ;
V_13 = F_11 ( ( unsigned long ) ( V_13 >> V_32 ) / V_26 ) ;
V_29 = ( ( V_13 & ~ V_33 ) * V_26 ) /
V_34 ;
V_13 &= V_33 ;
if ( ! V_13 ) {
F_4 ( L_4
L_5 ) ;
return - 1 ;
}
for ( V_6 = 0 ; V_6 < V_11 -> V_7 ; V_6 ++ )
F_12 ( V_11 -> V_8 [ V_6 ] . V_3 , V_27 ) ;
while ( F_13 ( V_27 ) ) {
F_14 (i, physnode_mask) {
T_2 V_35 = F_11 ( V_36 ) ;
T_2 V_19 , V_37 , V_20 ;
int V_12 ;
V_12 = F_2 ( V_6 , V_11 ) ;
if ( V_12 < 0 ) {
F_15 ( V_6 , V_27 ) ;
continue;
}
V_19 = V_11 -> V_8 [ V_12 ] . V_19 ;
V_37 = V_11 -> V_8 [ V_12 ] . V_20 ;
V_20 = V_19 + V_13 ;
if ( V_3 < V_29 )
V_20 += V_34 ;
while ( V_20 - V_19 -
F_10 ( V_19 , V_20 ) < V_13 ) {
V_20 += V_34 ;
if ( V_20 > V_37 ) {
V_20 = V_37 ;
break;
}
}
if ( V_20 < V_35 && V_35 - V_20 -
F_10 ( V_20 , V_35 ) < V_34 )
V_20 = V_35 ;
if ( V_37 - V_20 -
F_10 ( V_20 , V_37 ) < V_13 )
V_20 = V_37 ;
V_30 = F_3 ( V_10 , V_11 , V_3 ++ % V_26 ,
V_12 ,
F_16 ( V_20 , V_37 ) - V_19 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return 0 ;
}
static T_2 T_1 F_17 ( T_2 V_19 , T_2 V_25 , T_2 V_13 )
{
T_2 V_20 = V_19 + V_13 ;
while ( V_20 - V_19 - F_10 ( V_19 , V_20 ) < V_13 ) {
V_20 += V_34 ;
if ( V_20 > V_25 ) {
V_20 = V_25 ;
break;
}
}
return V_20 ;
}
static int T_1 F_18 ( struct V_4 * V_10 ,
struct V_4 * V_11 ,
T_2 V_24 , T_2 V_25 , T_2 V_13 )
{
T_3 V_27 = V_28 ;
T_2 V_38 ;
int V_3 = 0 ;
int V_6 , V_30 ;
if ( ! V_13 )
return - 1 ;
V_38 = ( V_25 - V_24 - F_10 ( V_24 , V_25 ) ) /
V_31 ;
V_38 = F_19 ( V_38 , V_34 ) ;
if ( ( V_38 & V_33 ) < V_38 )
V_38 = ( V_38 + V_34 ) &
V_33 ;
if ( V_13 < V_38 ) {
F_4 ( L_6 ,
V_13 >> 20 , V_38 >> 20 ) ;
V_13 = V_38 ;
}
V_13 &= V_33 ;
for ( V_6 = 0 ; V_6 < V_11 -> V_7 ; V_6 ++ )
F_12 ( V_11 -> V_8 [ V_6 ] . V_3 , V_27 ) ;
while ( F_13 ( V_27 ) ) {
F_14 (i, physnode_mask) {
T_2 V_35 = F_11 ( V_36 ) ;
T_2 V_19 , V_37 , V_20 ;
int V_12 ;
V_12 = F_2 ( V_6 , V_11 ) ;
if ( V_12 < 0 ) {
F_15 ( V_6 , V_27 ) ;
continue;
}
V_19 = V_11 -> V_8 [ V_12 ] . V_19 ;
V_37 = V_11 -> V_8 [ V_12 ] . V_20 ;
V_20 = F_17 ( V_19 , V_37 , V_13 ) ;
if ( V_20 < V_35 && V_35 - V_20 -
F_10 ( V_20 , V_35 ) < V_34 )
V_20 = V_35 ;
if ( V_37 - V_20 -
F_10 ( V_20 , V_37 ) < V_13 )
V_20 = V_37 ;
V_30 = F_3 ( V_10 , V_11 , V_3 ++ % V_31 ,
V_12 ,
F_16 ( V_20 , V_37 ) - V_19 ) ;
if ( V_30 < 0 )
return V_30 ;
}
}
return 0 ;
}
void T_1 F_20 ( struct V_4 * V_4 , int V_39 )
{
static struct V_4 V_10 V_40 ;
static struct V_4 V_11 V_40 ;
const T_2 V_25 = F_11 ( V_41 ) ;
T_4 * V_42 = NULL ;
T_5 V_43 = V_39 * V_39 * sizeof( V_42 [ 0 ] ) ;
int V_44 , V_45 ;
int V_6 , V_46 , V_30 ;
if ( ! V_2 )
goto V_47;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = * V_4 ;
for ( V_6 = 0 ; V_6 < V_31 ; V_6 ++ )
V_21 [ V_6 ] = V_22 ;
if ( strchr ( V_2 , 'M' ) || strchr ( V_2 , 'G' ) ) {
T_2 V_13 ;
V_13 = F_21 ( V_2 , & V_2 ) ;
V_30 = F_18 ( & V_10 , & V_11 , 0 , V_25 , V_13 ) ;
} else {
unsigned long V_48 ;
V_48 = F_22 ( V_2 , NULL , 0 ) ;
V_30 = F_8 ( & V_10 , & V_11 , 0 , V_25 , V_48 ) ;
}
if ( V_30 < 0 )
goto V_47;
if ( F_23 ( & V_10 ) < 0 ) {
F_24 ( L_7 ) ;
goto V_47;
}
if ( V_39 ) {
T_2 V_49 ;
V_49 = F_25 ( 0 , F_11 ( V_50 ) ,
V_43 , V_51 ) ;
if ( V_49 == V_52 ) {
F_24 ( L_8 ) ;
goto V_47;
}
F_26 ( V_49 , V_49 + V_43 , L_9 ) ;
V_42 = F_27 ( V_49 ) ;
for ( V_6 = 0 ; V_6 < V_39 ; V_6 ++ )
for ( V_46 = 0 ; V_46 < V_39 ; V_46 ++ )
V_42 [ V_6 * V_39 + V_46 ] =
F_28 ( V_6 , V_46 ) ;
}
V_44 = 0 ;
V_45 = V_22 ;
for ( V_6 = 0 ; V_6 < F_29 ( V_21 ) ; V_6 ++ ) {
if ( V_21 [ V_6 ] != V_22 ) {
V_44 = V_6 ;
if ( V_45 == V_22 )
V_45 = V_21 [ V_6 ] ;
}
}
if ( V_45 == V_22 ) {
F_24 ( L_10 ) ;
goto V_47;
}
* V_4 = V_10 ;
for ( V_6 = 0 ; V_6 < F_29 ( V_53 ) ; V_6 ++ ) {
if ( V_53 [ V_6 ] == V_22 )
continue;
for ( V_46 = 0 ; V_46 < F_29 ( V_21 ) ; V_46 ++ )
if ( V_53 [ V_6 ] == V_21 [ V_46 ] )
break;
V_53 [ V_6 ] = V_46 < F_29 ( V_21 ) ? V_46 : 0 ;
}
for ( V_6 = 0 ; V_6 < F_29 ( V_21 ) ; V_6 ++ )
if ( V_21 [ V_6 ] == V_22 )
V_21 [ V_6 ] = V_45 ;
F_30 () ;
for ( V_6 = 0 ; V_6 < V_44 + 1 ; V_6 ++ ) {
for ( V_46 = 0 ; V_46 < V_44 + 1 ; V_46 ++ ) {
int V_54 = V_21 [ V_6 ] ;
int V_55 = V_21 [ V_46 ] ;
int V_56 ;
if ( V_54 >= V_39 || V_55 >= V_39 )
V_56 = V_54 == V_55 ?
V_57 : V_58 ;
else
V_56 = V_42 [ V_54 * V_39 + V_55 ] ;
F_31 ( V_6 , V_46 , V_56 ) ;
}
}
if ( V_42 )
F_32 ( F_33 ( V_42 ) , F_33 ( V_42 ) + V_43 ) ;
return;
V_47:
for ( V_6 = 0 ; V_6 < F_29 ( V_21 ) ; V_6 ++ )
V_21 [ V_6 ] = V_6 ;
}
void T_6 F_34 ( int V_59 )
{
int V_60 , V_3 ;
V_3 = F_35 ( V_59 ) ;
F_36 ( V_3 == V_22 || ! F_37 ( V_3 ) ) ;
V_60 = V_21 [ V_3 ] ;
F_38 (nid)
if ( V_21 [ V_3 ] == V_60 )
F_39 ( V_59 , V_61 [ V_3 ] ) ;
}
void T_6 F_40 ( int V_59 )
{
int V_6 ;
F_38 (i)
F_41 ( V_59 , V_61 [ V_6 ] ) ;
}
static void T_6 F_42 ( int V_59 , bool V_62 )
{
int V_3 , V_60 ;
V_3 = F_35 ( V_59 ) ;
if ( V_3 == V_22 ) {
return;
}
V_60 = V_21 [ V_3 ] ;
F_38 (nid) {
if ( V_21 [ V_3 ] != V_60 )
continue;
F_43 ( V_59 , V_3 , V_62 ) ;
}
}
void T_6 F_34 ( int V_59 )
{
F_42 ( V_59 , true ) ;
}
void T_6 F_40 ( int V_59 )
{
F_42 ( V_59 , false ) ;
}
