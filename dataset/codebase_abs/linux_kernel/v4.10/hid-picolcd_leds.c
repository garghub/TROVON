void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_5 ;
if ( ! V_2 -> V_6 [ 0 ] )
return;
V_4 = F_2 ( V_7 , V_2 -> V_8 ) ;
if ( ! V_4 || V_4 -> V_9 != 1 || V_4 -> V_10 [ 0 ] -> V_11 != 1 )
return;
F_3 ( & V_2 -> V_12 , V_5 ) ;
F_4 ( V_4 -> V_10 [ 0 ] , 0 , V_2 -> V_13 ) ;
if ( ! ( V_2 -> V_14 & V_15 ) )
F_5 ( V_2 -> V_8 , V_4 , V_16 ) ;
F_6 ( & V_2 -> V_12 , V_5 ) ;
}
static void F_7 ( struct V_17 * V_18 ,
enum V_19 V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_8 ;
struct V_1 * V_2 ;
int V_24 , V_25 = 0 ;
V_22 = V_18 -> V_22 -> V_26 ;
V_8 = F_8 ( V_22 ) ;
V_2 = F_9 ( V_8 ) ;
if ( ! V_2 )
return;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_18 != V_2 -> V_6 [ V_24 ] )
continue;
V_25 = ( V_2 -> V_13 >> V_24 ) & 1 ;
if ( V_20 == V_27 && V_25 ) {
V_2 -> V_13 &= ~ ( 1 << V_24 ) ;
F_1 ( V_2 ) ;
} else if ( V_20 != V_27 && ! V_25 ) {
V_2 -> V_13 |= 1 << V_24 ;
F_1 ( V_2 ) ;
}
break;
}
}
static enum V_19 F_10 ( struct V_17 * V_18 )
{
struct V_21 * V_22 ;
struct V_23 * V_8 ;
struct V_1 * V_2 ;
int V_24 , V_20 = 0 ;
V_22 = V_18 -> V_22 -> V_26 ;
V_8 = F_8 ( V_22 ) ;
V_2 = F_9 ( V_8 ) ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ )
if ( V_18 == V_2 -> V_6 [ V_24 ] ) {
V_20 = ( V_2 -> V_13 >> V_24 ) & 1 ;
break;
}
return V_20 ? V_28 : V_27 ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_21 * V_22 = & V_2 -> V_8 -> V_22 ;
struct V_17 * V_6 ;
T_1 V_29 = strlen ( F_12 ( V_22 ) ) + 8 ;
char * V_30 ;
int V_24 , V_31 = 0 ;
if ( ! V_4 )
return - V_32 ;
if ( V_4 -> V_9 != 1 || V_4 -> V_10 [ 0 ] -> V_11 != 1 ||
V_4 -> V_10 [ 0 ] -> V_33 != 8 ) {
F_13 ( V_22 , L_1 ) ;
return - V_34 ;
}
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
V_6 = F_14 ( sizeof( struct V_17 ) + V_29 , V_35 ) ;
if ( ! V_6 ) {
F_13 ( V_22 , L_2 , V_24 ) ;
V_31 = - V_36 ;
goto V_37;
}
V_30 = ( void * ) ( & V_6 [ 1 ] ) ;
snprintf ( V_30 , V_29 , L_3 , F_12 ( V_22 ) , V_24 ) ;
V_6 -> V_30 = V_30 ;
V_6 -> V_38 = 0 ;
V_6 -> V_39 = 1 ;
V_6 -> V_40 = F_10 ;
V_6 -> V_41 = F_7 ;
V_2 -> V_6 [ V_24 ] = V_6 ;
V_31 = F_15 ( V_22 , V_2 -> V_6 [ V_24 ] ) ;
if ( V_31 ) {
V_2 -> V_6 [ V_24 ] = NULL ;
F_16 ( V_6 ) ;
F_13 ( V_22 , L_4 , V_24 ) ;
goto V_37;
}
}
return 0 ;
V_37:
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ )
if ( V_2 -> V_6 [ V_24 ] ) {
V_6 = V_2 -> V_6 [ V_24 ] ;
V_2 -> V_6 [ V_24 ] = NULL ;
F_17 ( V_6 ) ;
F_16 ( V_6 ) ;
}
return V_31 ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_6 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
V_6 = V_2 -> V_6 [ V_24 ] ;
V_2 -> V_6 [ V_24 ] = NULL ;
if ( ! V_6 )
continue;
F_17 ( V_6 ) ;
F_16 ( V_6 ) ;
}
}
