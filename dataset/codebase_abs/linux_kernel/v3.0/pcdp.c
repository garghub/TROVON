static int T_1
F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
int V_3 ;
static char V_4 [ 64 ] , * V_5 = V_4 ;
char V_6 ;
V_3 = ( V_2 -> V_7 . V_8 == V_9 ) ;
V_5 += sprintf ( V_5 , L_1 ,
V_3 ? L_2 : L_3 , V_2 -> V_7 . V_10 ) ;
if ( V_2 -> V_11 ) {
V_5 += sprintf ( V_5 , L_4 , V_2 -> V_11 ) ;
if ( V_2 -> V_12 ) {
switch ( V_2 -> V_6 ) {
case 0x2 : V_6 = 'e' ; break;
case 0x3 : V_6 = 'o' ; break;
default: V_6 = 'n' ;
}
V_5 += sprintf ( V_5 , L_5 , V_6 , V_2 -> V_12 ) ;
}
}
F_3 ( L_6 , 8250 , & V_4 [ 9 ] ) ;
return F_4 ( V_4 ) ;
#else
return - V_13 ;
#endif
}
static int T_1
F_5 ( struct V_14 * V_15 )
{
#if F_6 ( V_16 ) && F_6 ( V_17 )
T_2 * V_18 ;
V_18 = ( ( T_2 * ) V_15 + sizeof( struct V_14 ) ) ;
if ( V_18 [ 0 ] == V_19 ) {
struct V_20 V_21 ;
memcpy ( & V_21 , V_18 , sizeof( V_21 ) ) ;
if ( V_21 . V_22 & V_23 )
V_24 = V_21 . V_25 ;
if ( V_21 . V_22 & V_26 )
V_27 = V_21 . V_28 ;
}
if ( F_7 ( V_27 + 0xA0000 ) == V_29 ) {
F_8 ( V_30 L_7 ) ;
return - V_13 ;
}
V_31 = & V_32 ;
F_8 ( V_33 L_8 ) ;
return 0 ;
#else
return - V_13 ;
#endif
}
int T_1
F_9 ( char * V_34 )
{
struct V_35 * V_35 ;
struct V_1 * V_2 ;
struct V_14 * V_15 , * V_36 ;
int V_37 , V_38 = 0 ;
int V_39 = - V_13 ;
if ( V_40 . V_41 == V_42 )
return - V_13 ;
V_35 = F_10 ( V_40 . V_41 , 4096 ) ;
F_8 ( V_33 L_9 , V_35 -> V_43 , V_40 . V_41 ) ;
if ( strstr ( V_34 , L_10 ) ) {
if ( V_35 -> V_43 < 3 )
V_38 = 1 ;
} else if ( strstr ( V_34 , L_11 ) ) {
F_8 ( V_33 L_12 ) ;
goto V_44;
}
if ( V_35 -> V_43 < 3 && F_11 () )
V_38 = 1 ;
for ( V_37 = 0 , V_2 = V_35 -> V_2 ; V_37 < V_35 -> V_45 ; V_37 ++ , V_2 ++ ) {
if ( V_2 -> V_46 & V_47 || V_38 ) {
if ( V_2 -> type == V_48 ) {
V_39 = F_1 ( V_2 ) ;
goto V_44;
}
}
}
V_36 = (struct V_14 * ) ( ( T_2 * ) V_35 + V_35 -> V_49 ) ;
for ( V_15 = (struct V_14 * ) ( V_35 -> V_2 + V_35 -> V_45 ) ;
V_15 < V_36 ;
V_15 = (struct V_14 * ) ( ( T_2 * ) V_15 + V_15 -> V_49 ) ) {
if ( V_15 -> V_46 & V_50 ) {
if ( V_15 -> type == V_51 ) {
V_39 = F_5 ( V_15 ) ;
goto V_44;
}
}
}
V_44:
F_12 ( V_35 ) ;
return V_39 ;
}
