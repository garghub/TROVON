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
static T_2 T_1 F_3 ( T_2 V_10 , T_2 V_11 )
{
unsigned long V_12 = F_4 ( V_10 ) ;
unsigned long V_13 = F_5 ( V_11 ) ;
if ( V_12 < V_13 )
return F_6 ( F_7 ( V_12 , V_13 ) ) ;
return 0 ;
}
static int T_1 F_8 ( struct V_4 * V_14 ,
struct V_4 * V_15 ,
int V_3 , int V_16 , T_2 V_17 )
{
struct V_18 * V_19 = & V_14 -> V_8 [ V_14 -> V_7 ] ;
struct V_18 * V_20 = & V_15 -> V_8 [ V_16 ] ;
if ( V_14 -> V_7 >= V_21 ) {
F_9 ( L_1 ) ;
return - V_22 ;
}
V_14 -> V_7 ++ ;
V_19 -> V_10 = V_20 -> V_10 ;
V_19 -> V_11 = V_20 -> V_10 + V_17 ;
V_19 -> V_3 = V_3 ;
if ( V_23 [ V_3 ] == V_24 )
V_23 [ V_3 ] = V_3 ;
V_20 -> V_10 += V_17 ;
if ( V_20 -> V_10 >= V_20 -> V_11 ) {
F_10 ( V_20 -> V_10 > V_20 -> V_11 ) ;
F_11 ( V_16 , V_15 ) ;
}
F_12 ( V_25 L_2 ,
V_3 , V_19 -> V_10 , V_19 -> V_11 - 1 , ( V_19 -> V_11 - V_19 -> V_10 ) >> 20 ) ;
return 0 ;
}
static int T_1 F_13 ( struct V_4 * V_14 ,
struct V_4 * V_15 ,
T_2 V_26 , T_2 V_27 , int V_28 )
{
T_3 V_29 = V_30 ;
T_2 V_17 ;
int V_31 ;
int V_3 = 0 ;
int V_6 , V_32 ;
if ( V_28 <= 0 )
return - 1 ;
if ( V_28 > V_33 ) {
F_14 ( L_3 ,
V_28 , V_33 ) ;
V_28 = V_33 ;
}
V_17 = V_27 - V_26 - F_3 ( V_26 , V_27 ) ;
V_17 = F_6 ( ( unsigned long ) ( V_17 >> V_34 ) / V_28 ) ;
V_31 = ( ( V_17 & ~ V_35 ) * V_28 ) /
V_36 ;
V_17 &= V_35 ;
if ( ! V_17 ) {
F_9 ( L_4
L_5 ) ;
return - 1 ;
}
while ( F_15 ( V_29 ) ) {
F_16 (i, physnode_mask) {
T_2 V_37 = F_6 ( V_38 ) ;
T_2 V_10 , V_39 , V_11 ;
int V_16 ;
V_16 = F_2 ( V_6 , V_15 ) ;
if ( V_16 < 0 ) {
F_17 ( V_6 , V_29 ) ;
continue;
}
V_10 = V_15 -> V_8 [ V_16 ] . V_10 ;
V_39 = V_15 -> V_8 [ V_16 ] . V_11 ;
V_11 = V_10 + V_17 ;
if ( V_3 < V_31 )
V_11 += V_36 ;
while ( V_11 - V_10 - F_3 ( V_10 , V_11 ) < V_17 ) {
V_11 += V_36 ;
if ( V_11 > V_39 ) {
V_11 = V_39 ;
break;
}
}
if ( V_11 < V_37 && V_37 - V_11 -
F_3 ( V_11 , V_37 ) < V_36 )
V_11 = V_37 ;
if ( V_39 - V_11 - F_3 ( V_11 , V_39 ) < V_17 )
V_11 = V_39 ;
V_32 = F_8 ( V_14 , V_15 , V_3 ++ % V_28 ,
V_16 ,
F_18 ( V_11 , V_39 ) - V_10 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
return 0 ;
}
static T_2 T_1 F_19 ( T_2 V_10 , T_2 V_27 , T_2 V_17 )
{
T_2 V_11 = V_10 + V_17 ;
while ( V_11 - V_10 - F_3 ( V_10 , V_11 ) < V_17 ) {
V_11 += V_36 ;
if ( V_11 > V_27 ) {
V_11 = V_27 ;
break;
}
}
return V_11 ;
}
static int T_1 F_20 ( struct V_4 * V_14 ,
struct V_4 * V_15 ,
T_2 V_26 , T_2 V_27 , T_2 V_17 )
{
T_3 V_29 = V_30 ;
T_2 V_40 ;
int V_3 = 0 ;
int V_6 , V_32 ;
if ( ! V_17 )
return - 1 ;
V_40 = ( V_27 - V_26 - F_3 ( V_26 , V_27 ) ) / V_33 ;
V_40 = F_21 ( V_40 , V_36 ) ;
if ( ( V_40 & V_35 ) < V_40 )
V_40 = ( V_40 + V_36 ) &
V_35 ;
if ( V_17 < V_40 ) {
F_9 ( L_6 ,
V_17 >> 20 , V_40 >> 20 ) ;
V_17 = V_40 ;
}
V_17 &= V_35 ;
while ( F_15 ( V_29 ) ) {
F_16 (i, physnode_mask) {
T_2 V_37 = F_6 ( V_38 ) ;
T_2 V_10 , V_39 , V_11 ;
int V_16 ;
V_16 = F_2 ( V_6 , V_15 ) ;
if ( V_16 < 0 ) {
F_17 ( V_6 , V_29 ) ;
continue;
}
V_10 = V_15 -> V_8 [ V_16 ] . V_10 ;
V_39 = V_15 -> V_8 [ V_16 ] . V_11 ;
V_11 = F_19 ( V_10 , V_39 , V_17 ) ;
if ( V_11 < V_37 && V_37 - V_11 -
F_3 ( V_11 , V_37 ) < V_36 )
V_11 = V_37 ;
if ( V_39 - V_11 - F_3 ( V_11 , V_39 ) < V_17 )
V_11 = V_39 ;
V_32 = F_8 ( V_14 , V_15 , V_3 ++ % V_33 ,
V_16 ,
F_18 ( V_11 , V_39 ) - V_10 ) ;
if ( V_32 < 0 )
return V_32 ;
}
}
return 0 ;
}
int T_1 F_22 ( int * V_41 )
{
int V_6 , V_42 = 0 ;
* V_41 = V_24 ;
for ( V_6 = 0 ; V_6 < F_23 ( V_23 ) ; V_6 ++ ) {
if ( V_23 [ V_6 ] != V_24 ) {
V_42 = V_6 ;
if ( * V_41 == V_24 )
* V_41 = V_23 [ V_6 ] ;
}
}
return V_42 ;
}
void T_1 F_24 ( struct V_4 * V_4 , int V_43 )
{
static struct V_4 V_14 V_44 ;
static struct V_4 V_15 V_44 ;
const T_2 V_27 = F_6 ( V_45 ) ;
T_4 * V_46 = NULL ;
T_5 V_47 = V_43 * V_43 * sizeof( V_46 [ 0 ] ) ;
int V_42 , V_41 ;
int V_6 , V_48 , V_32 ;
if ( ! V_2 )
goto V_49;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_15 = * V_4 ;
for ( V_6 = 0 ; V_6 < V_33 ; V_6 ++ )
V_23 [ V_6 ] = V_24 ;
if ( strchr ( V_2 , 'M' ) || strchr ( V_2 , 'G' ) ) {
T_2 V_17 ;
V_17 = F_25 ( V_2 , & V_2 ) ;
V_32 = F_20 ( & V_14 , & V_15 , 0 , V_27 , V_17 ) ;
} else {
unsigned long V_50 ;
V_50 = F_26 ( V_2 , & V_2 , 0 ) ;
V_32 = F_13 ( & V_14 , & V_15 , 0 , V_27 , V_50 ) ;
}
if ( * V_2 == ':' )
V_2 ++ ;
if ( V_32 < 0 )
goto V_49;
if ( F_27 ( & V_14 ) < 0 ) {
F_28 ( L_7 ) ;
goto V_49;
}
if ( V_43 ) {
T_2 V_51 ;
V_51 = F_29 ( 0 , F_6 ( V_52 ) ,
V_47 , V_53 ) ;
if ( ! V_51 ) {
F_28 ( L_8 ) ;
goto V_49;
}
F_30 ( V_51 , V_47 ) ;
V_46 = F_31 ( V_51 ) ;
for ( V_6 = 0 ; V_6 < V_43 ; V_6 ++ )
for ( V_48 = 0 ; V_48 < V_43 ; V_48 ++ )
V_46 [ V_6 * V_43 + V_48 ] =
F_32 ( V_6 , V_48 ) ;
}
V_42 = F_22 ( & V_41 ) ;
* V_4 = V_14 ;
F_33 ( V_30 ) ;
for ( V_6 = 0 ; V_6 < F_23 ( V_14 . V_8 ) ; V_6 ++ )
if ( V_14 . V_8 [ V_6 ] . V_10 != V_14 . V_8 [ V_6 ] . V_11 &&
V_14 . V_8 [ V_6 ] . V_3 != V_24 )
F_34 ( V_14 . V_8 [ V_6 ] . V_3 , V_30 ) ;
for ( V_6 = 0 ; V_6 < F_23 ( V_54 ) ; V_6 ++ ) {
if ( V_54 [ V_6 ] == V_24 )
continue;
for ( V_48 = 0 ; V_48 < F_23 ( V_23 ) ; V_48 ++ )
if ( V_54 [ V_6 ] == V_23 [ V_48 ] )
break;
V_54 [ V_6 ] = V_48 < F_23 ( V_23 ) ? V_48 : 0 ;
}
for ( V_6 = 0 ; V_6 < F_23 ( V_23 ) ; V_6 ++ )
if ( V_23 [ V_6 ] == V_24 )
V_23 [ V_6 ] = V_41 ;
F_35 () ;
for ( V_6 = 0 ; V_6 < V_42 + 1 ; V_6 ++ ) {
for ( V_48 = 0 ; V_48 < V_42 + 1 ; V_48 ++ ) {
int V_55 = V_23 [ V_6 ] ;
int V_56 = V_23 [ V_48 ] ;
int V_57 ;
if ( F_36 ( & V_2 , & V_57 ) == 2 )
;
else if ( V_55 >= V_43 || V_56 >= V_43 )
V_57 = V_55 == V_56 ?
V_58 : V_59 ;
else
V_57 = V_46 [ V_55 * V_43 + V_56 ] ;
F_37 ( V_6 , V_48 , V_57 ) ;
}
}
if ( V_46 )
F_38 ( F_39 ( V_46 ) , V_47 ) ;
return;
V_49:
for ( V_6 = 0 ; V_6 < F_23 ( V_23 ) ; V_6 ++ )
V_23 [ V_6 ] = V_6 ;
}
void F_40 ( int V_60 )
{
int V_61 , V_3 ;
V_3 = F_41 ( V_60 ) ;
F_42 ( V_3 == V_24 || ! F_43 ( V_3 ) ) ;
V_61 = V_23 [ V_3 ] ;
F_44 (nid)
if ( V_23 [ V_3 ] == V_61 )
F_45 ( V_60 , V_62 [ V_3 ] ) ;
}
void F_46 ( int V_60 )
{
int V_6 ;
F_44 (i)
F_47 ( V_60 , V_62 [ V_6 ] ) ;
}
static void F_48 ( int V_60 , bool V_63 )
{
int V_3 , V_61 ;
V_3 = F_41 ( V_60 ) ;
if ( V_3 == V_24 ) {
return;
}
V_61 = V_23 [ V_3 ] ;
F_44 (nid) {
if ( V_23 [ V_3 ] != V_61 )
continue;
F_49 ( V_60 , V_3 , V_63 ) ;
}
}
void F_40 ( int V_60 )
{
F_48 ( V_60 , true ) ;
}
void F_46 ( int V_60 )
{
F_48 ( V_60 , false ) ;
}
