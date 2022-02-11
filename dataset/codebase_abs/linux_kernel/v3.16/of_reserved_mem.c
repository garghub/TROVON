int T_1 __weak F_1 ( T_2 V_1 ,
T_2 V_2 , T_2 V_3 , T_2 V_4 , bool V_5 ,
T_2 * V_6 )
{
T_2 V_7 = F_2 ( V_1 , V_2 , V_4 ) ;
if ( ! V_7 )
return - V_8 ;
if ( V_7 < V_3 ) {
F_3 ( V_7 , V_1 ) ;
return - V_8 ;
}
* V_6 = V_7 ;
if ( V_5 )
return F_4 ( V_7 , V_1 ) ;
return 0 ;
}
int T_1 __weak F_1 ( T_2 V_1 ,
T_2 V_2 , T_2 V_3 , T_2 V_4 , bool V_5 ,
T_2 * V_6 )
{
F_5 ( L_1 ,
V_1 , V_5 ? L_2 : L_3 ) ;
return - V_9 ;
}
void T_1 F_6 ( unsigned long V_10 , const char * V_11 ,
T_2 V_7 , T_2 V_1 )
{
struct V_12 * V_13 = & V_12 [ V_14 ] ;
if ( V_14 == F_7 ( V_12 ) ) {
F_5 ( L_4 ) ;
return;
}
V_13 -> V_15 = V_10 ;
V_13 -> V_16 = V_11 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_1 = V_1 ;
V_14 ++ ;
return;
}
static int T_1 F_8 ( unsigned long V_10 ,
const char * V_11 , T_2 * V_6 , T_2 * V_17 )
{
int V_18 = ( V_19 + V_20 ) * sizeof( V_21 ) ;
T_2 V_3 = 0 , V_4 = 0 ;
T_2 V_7 = 0 , V_2 = 0 , V_1 ;
int V_22 ;
const V_21 * V_23 ;
int V_5 ;
int V_24 ;
V_23 = F_9 ( V_10 , L_5 , & V_22 ) ;
if ( ! V_23 )
return - V_25 ;
if ( V_22 != V_20 * sizeof( V_21 ) ) {
F_5 ( L_6 ,
V_11 ) ;
return - V_25 ;
}
V_1 = F_10 ( V_20 , & V_23 ) ;
V_5 = F_9 ( V_10 , L_7 , NULL ) != NULL ;
V_23 = F_9 ( V_10 , L_8 , & V_22 ) ;
if ( V_23 ) {
if ( V_22 != V_19 * sizeof( V_21 ) ) {
F_5 ( L_9 ,
V_11 ) ;
return - V_25 ;
}
V_2 = F_10 ( V_19 , & V_23 ) ;
}
V_23 = F_9 ( V_10 , L_10 , & V_22 ) ;
if ( V_23 ) {
if ( V_22 % V_18 != 0 ) {
F_5 ( L_11 ,
V_11 ) ;
return - V_25 ;
}
V_7 = 0 ;
while ( V_22 > 0 ) {
V_3 = F_10 ( V_19 , & V_23 ) ;
V_4 = V_3 + F_10 ( V_20 ,
& V_23 ) ;
V_24 = F_1 ( V_1 ,
V_2 , V_3 , V_4 , V_5 , & V_7 ) ;
if ( V_24 == 0 ) {
F_11 ( L_12 ,
V_11 , & V_7 ,
( unsigned long ) V_1 / V_26 ) ;
break;
}
V_22 -= V_18 ;
}
} else {
V_24 = F_1 ( V_1 , V_2 ,
0 , 0 , V_5 , & V_7 ) ;
if ( V_24 == 0 )
F_11 ( L_12 ,
V_11 , & V_7 , ( unsigned long ) V_1 / V_26 ) ;
}
if ( V_7 == 0 ) {
F_12 ( L_13 ,
V_11 ) ;
return - V_8 ;
}
* V_6 = V_7 ;
* V_17 = V_1 ;
return 0 ;
}
static int T_1 F_13 ( struct V_12 * V_13 )
{
extern const struct V_27 V_28 [] ;
const struct V_27 * V_29 ;
for ( V_29 = V_28 ; V_29 < & V_30 ; V_29 ++ ) {
T_3 V_31 = V_29 -> V_32 ;
const char * V_33 = V_29 -> V_34 ;
if ( ! F_14 ( V_13 -> V_15 , V_33 ) )
continue;
if ( V_31 ( V_13 ) == 0 ) {
F_12 ( L_14 ,
V_13 -> V_16 , V_33 ) ;
return 0 ;
}
}
return - V_35 ;
}
void T_1 F_15 ( void )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_14 ; V_29 ++ ) {
struct V_12 * V_13 = & V_12 [ V_29 ] ;
unsigned long V_10 = V_13 -> V_15 ;
int V_36 = 0 ;
if ( V_13 -> V_1 == 0 )
V_36 = F_8 ( V_10 , V_13 -> V_16 ,
& V_13 -> V_7 , & V_13 -> V_1 ) ;
if ( V_36 == 0 )
F_13 ( V_13 ) ;
}
}
