struct V_1 * F_1 ( T_1 V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_5 )
return NULL ;
for ( V_4 = V_3 ? V_3 + 1 : & V_6 [ 0 ] ;
V_4 < V_6 + V_5 ;
V_4 ++ )
if ( V_2 == V_7 || V_2 == V_4 -> V_2 )
return V_4 ;
return NULL ;
}
static void T_2 F_2 ( unsigned long V_8 , unsigned long V_9 ,
int V_10 )
{
if ( V_10 )
V_8 += V_11 ;
else
V_9 += V_11 ;
V_8 &= ~ V_11 ;
V_9 &= ~ V_11 ;
if ( V_9 <= V_12 || V_8 >= V_13 )
return;
V_8 = V_8 < V_12 ? 0x00000000 : V_8 - V_12 ;
V_9 = V_9 > V_13 ? V_14 : V_9 - V_12 ;
while ( V_8 < V_9 ) {
T_3 V_15 = V_8 >> V_16 ;
if ( V_10 )
F_3 ( V_15 , V_17 ) ;
else
F_4 ( V_15 , V_17 ) ;
V_8 += V_18 ;
}
}
static struct V_19 T_2 * F_5 (
struct V_20 * V_21 , struct V_1 * V_4 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
struct V_19 * V_24 = & V_21 -> V_19 [ V_22 ] ;
if ( F_6 ( V_4 ) >= V_24 -> V_8 &&
F_7 ( V_4 ) <= V_24 -> V_9 )
return V_24 ;
}
return & V_25 ;
}
static int T_2 F_8 ( struct V_20 * V_26 )
{
struct V_27 * V_28 ;
struct V_1 * V_4 ;
struct V_19 * V_24 ;
unsigned int V_22 ;
int error ;
V_28 = F_9 ( sizeof( * V_28 ) , V_29 ) ;
if ( ! V_28 )
return - V_30 ;
F_10 ( & V_28 -> V_31 ) ;
V_28 -> V_32 . V_33 = & V_26 -> V_32 ;
F_11 ( & V_28 -> V_32 , L_1 ) ;
error = F_12 ( & V_28 -> V_32 ) ;
if ( error ) {
F_13 ( L_2 ) ;
F_14 ( & V_28 -> V_32 ) ;
F_15 ( V_28 ) ;
return error ;
}
F_16 ( V_26 , V_28 ) ;
F_17 ( L_3 ,
V_5 , V_5 == 1 ? L_4 : L_5 ) ;
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_4 = & V_6 [ V_22 ] ;
V_4 -> V_2 = ( V_4 -> V_34 . V_35 << 16 ) | ( V_4 -> V_34 . V_36 << 8 ) ;
if ( V_4 -> V_2 == V_37 ) {
unsigned long V_38 = F_6 ( V_4 ) + 0x8000 ;
V_4 -> V_2 |= * ( V_39 * ) F_18 ( V_38 ) & V_40 ;
}
sprintf ( V_4 -> V_41 , L_6 , V_4 -> V_2 ) ;
F_19 ( V_4 ) ;
V_4 -> V_19 . V_41 = V_4 -> V_41 ;
V_24 = F_5 ( V_26 , V_4 ) ;
error = F_20 ( V_24 , & V_4 -> V_19 ) ;
if ( error )
F_21 ( & V_28 -> V_32 ,
L_7 ,
V_4 -> V_41 , & V_4 -> V_19 ) ;
F_11 ( & V_4 -> V_32 , L_8 , V_22 ) ;
V_4 -> V_32 . V_33 = & V_28 -> V_32 ;
V_4 -> V_32 . V_28 = & V_42 ;
}
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_4 = & V_6 [ V_22 ] ;
error = F_12 ( & V_4 -> V_32 ) ;
if ( error ) {
F_21 ( & V_28 -> V_32 , L_9 ,
V_4 -> V_41 ) ;
F_14 ( & V_4 -> V_32 ) ;
continue;
}
error = F_22 ( V_4 ) ;
if ( error )
F_21 ( & V_4 -> V_32 , L_10 ) ;
}
F_23 (z) {
if ( V_4 -> V_34 . V_43 & V_44 )
F_2 ( F_6 ( V_4 ) ,
F_7 ( V_4 ) + 1 , 1 ) ;
}
for ( V_22 = 0 ; V_22 < V_45 ; V_22 ++ )
if ( V_46 [ V_22 ] . V_47 < 16 * 1024 * 1024 )
F_2 ( V_46 [ V_22 ] . V_47 ,
V_46 [ V_22 ] . V_47 + V_46 [ V_22 ] . V_48 ,
0 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_49 , F_8 ) ;
}
