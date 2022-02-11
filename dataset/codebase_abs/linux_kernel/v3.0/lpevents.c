static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_3 . V_4 ;
if ( F_2 ( V_2 ) ) {
F_3 () ;
V_3 . V_4 += ( ( V_2 -> V_5 +
V_6 ) / V_6 ) *
V_6 ;
if ( V_3 . V_4 >
V_3 . V_7 ) {
V_3 . V_4 =
V_3 . V_8 ;
}
} else {
V_2 = NULL ;
}
return V_2 ;
}
int F_4 ( void )
{
struct V_1 * V_9 ;
if ( F_5 () >= V_10 )
return 0 ;
V_9 = (struct V_1 * ) V_3 . V_4 ;
return F_2 ( V_9 ) ||
V_3 . V_11 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_1 * V_12 ;
unsigned V_13 = ( ( V_2 -> V_5 + V_6 ) /
V_6 ) - 1 ;
switch ( V_13 ) {
case 3 :
V_12 = (struct V_1 * ) ( ( char * ) V_2 + 3 * V_6 ) ;
F_7 ( V_12 ) ;
case 2 :
V_12 = (struct V_1 * ) ( ( char * ) V_2 + 2 * V_6 ) ;
F_7 ( V_12 ) ;
case 1 :
V_12 = (struct V_1 * ) ( ( char * ) V_2 + 1 * V_6 ) ;
F_7 ( V_12 ) ;
}
F_8 () ;
F_7 ( V_2 ) ;
}
void F_9 ( void )
{
struct V_1 * V_2 ;
V_14:
if ( ! F_10 ( & V_3 . V_15 ) )
return;
for (; ; ) {
V_2 = F_1 () ;
if ( V_2 ) {
if ( V_2 -> V_16 < V_17 )
F_11 ( V_18 ) [ V_2 -> V_16 ] ++ ;
if ( V_2 -> V_16 < V_17 &&
V_19 [ V_2 -> V_16 ] )
V_19 [ V_2 -> V_16 ] ( V_2 ) ;
else {
T_1 type = V_2 -> V_16 ;
F_6 ( V_2 ) ;
F_12 ( & V_3 . V_15 ) ;
F_13 ( V_20
L_1 , type ) ;
goto V_14;
}
F_6 ( V_2 ) ;
} else if ( V_3 . V_11 )
F_14 ( V_3 . V_21 ) ;
else
break;
}
F_12 ( & V_3 . V_15 ) ;
}
static int F_15 ( char * V_22 )
{
unsigned long V_23 = F_16 ( V_22 , NULL , 0 ) ;
if ( ( V_23 > 0 ) && ( V_23 <= V_24 ) ) {
V_10 = V_23 ;
F_13 ( L_2 , V_23 ) ;
} else {
F_13 ( L_3 , V_23 ) ;
}
return 1 ;
}
void T_2 F_17 ( void )
{
void * V_25 ;
F_18 ( & V_3 . V_15 ) ;
V_25 = F_19 ( V_26 ) ;
memset ( V_25 , 0 , V_26 ) ;
F_20 ( 0 , V_25 , V_26 ) ;
V_3 . V_8 = V_25 ;
V_3 . V_4 = V_25 ;
V_3 . V_7 = ( char * ) V_25 +
( V_26 - V_27 ) ;
V_3 . V_21 = 0 ;
}
int F_21 ( T_3 V_28 , T_4 V_29 )
{
if ( V_28 < V_17 ) {
V_19 [ V_28 ] = V_29 ;
return 0 ;
}
return 1 ;
}
int F_22 ( T_3 V_28 )
{
F_23 () ;
if ( V_28 < V_17 ) {
if ( ! V_30 [ V_28 ] ) {
V_19 [ V_28 ] = NULL ;
F_24 () ;
return 0 ;
}
}
return 1 ;
}
int F_25 ( T_3 V_28 , T_5 V_31 )
{
if ( ( V_28 < V_17 ) &&
V_19 [ V_28 ] ) {
if ( V_31 == 0 )
V_31 = V_32 . V_33 ;
F_26 ( V_31 , V_28 ) ;
++ V_30 [ V_28 ] ;
return 0 ;
}
return 1 ;
}
int F_27 ( T_3 V_28 , T_5 V_31 )
{
if ( ( V_28 < V_17 ) &&
V_19 [ V_28 ] &&
V_30 [ V_28 ] ) {
if ( V_31 == 0 )
V_31 = V_32 . V_33 ;
F_28 ( V_31 , V_28 ) ;
-- V_30 [ V_28 ] ;
return 0 ;
}
return 1 ;
}
static int F_29 ( struct V_34 * V_35 , void * V_36 )
{
int V_37 , V_38 ;
unsigned long V_39 ;
static unsigned long V_40 [ V_24 ] ;
V_39 = 0 ;
F_30 (cpu) {
V_40 [ V_37 ] = 0 ;
for ( V_38 = 0 ; V_38 < V_17 ; V_38 ++ ) {
V_40 [ V_37 ] += F_31 ( V_18 , V_37 ) [ V_38 ] ;
}
V_39 += V_40 [ V_37 ] ;
}
F_32 ( V_35 , L_4 ) ;
F_32 ( V_35 , L_5 , V_39 ) ;
for ( V_38 = 0 ; V_38 < V_17 ; ++ V_38 ) {
V_39 = 0 ;
F_30 (cpu) {
V_39 += F_31 ( V_18 , V_37 ) [ V_38 ] ;
}
F_32 ( V_35 , L_6 , V_41 [ V_38 ] , V_39 ) ;
}
F_32 ( V_35 , L_7 ) ;
F_30 (cpu) {
F_32 ( V_35 , L_8 , V_37 , V_40 [ V_37 ] ) ;
}
return 0 ;
}
static int F_33 ( struct V_42 * V_42 , struct V_43 * V_43 )
{
return F_34 ( V_43 , F_29 , NULL ) ;
}
static int T_2 F_35 ( void )
{
if ( ! F_36 ( V_44 ) )
return 0 ;
F_37 ( L_9 , V_45 | V_46 , NULL ,
& V_47 ) ;
return 0 ;
}
