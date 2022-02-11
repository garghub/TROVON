static int F_1 ( T_1 * V_1 )
{
unsigned char V_2 ;
V_2 = F_2 ( V_1 -> V_3 . V_4 ) ;
if ( ! ( V_2 & 0x80 ) )
return 0 ;
return 1 ;
}
static void F_3 ( T_2 * V_5 )
{
F_4 ( 0 , V_5 -> V_1 -> V_3 . V_4 ) ;
}
static void T_3 F_5 ( struct V_6 * V_7 , unsigned long V_8 ,
unsigned long V_9 , unsigned long V_10 )
{
int V_11 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_3 . V_12 = V_8 ;
for ( V_11 = 1 ; V_11 < 8 ; V_11 ++ )
V_7 -> V_13 [ V_11 ] = V_8 + 2 + V_11 * 4 ;
V_7 -> V_3 . V_14 = V_9 ;
V_7 -> V_3 . V_4 = V_10 ;
V_7 -> V_15 = V_16 ;
}
static int T_3 F_6 ( void )
{
struct V_17 * V_18 = NULL ;
T_4 V_19 = 0 ;
T_5 type ;
int V_20 , V_11 ;
while ( ( V_18 = F_7 ( V_21 , V_18 ) ) ) {
unsigned long V_22 ;
struct V_6 V_7 [ V_23 ] , * V_24 [ V_23 ] ;
struct V_25 V_26 = V_27 ;
if ( V_18 -> V_28 == V_29 ) {
V_20 = V_30 ;
type = V_31 ;
} else if ( V_18 -> V_28 == V_32 ) {
V_20 = V_33 ;
type = V_34 ;
} else if ( V_18 -> V_28 == V_35 ) {
V_20 = V_36 ;
type = V_37 ;
V_26 . V_38 = & V_39 ;
} else
continue;
V_22 = V_18 -> V_40 . V_41 ;
if( type != V_37 ) {
if ( ! F_8 ( V_22 + V_42 , 0x800 , L_1 ) )
continue;
} else {
if ( ! F_8 ( V_22 + V_43 , 0x1000 , L_1 ) )
continue;
if ( ! F_8 ( V_22 + V_44 , 0x1000 , L_1 ) )
goto V_45;
if ( ! F_8 ( V_22 + V_46 , 0x8 , L_1 ) ) {
F_9 ( V_22 + V_44 , 0x1000 ) ;
V_45:
F_9 ( V_22 + V_43 , 0x1000 ) ;
continue;
}
}
V_19 = ( unsigned long ) F_10 ( V_22 ) ;
if ( type != V_37 )
F_4 ( 0 , V_19 + V_47 ) ;
F_11 ( V_48 L_2 ,
V_49 [ type ] ) ;
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ ) {
unsigned long V_8 , V_9 , V_10 ;
if ( type != V_37 ) {
V_8 = V_19 + V_50 [ V_11 ] ;
V_9 = V_8 + V_51 ;
V_10 = V_19 + V_52 [ V_11 ] ;
} else {
V_8 = V_19 + V_53 [ V_11 ] ;
V_9 = 0 ;
V_10 = V_19 + V_54 [ V_11 ] ;
}
F_5 ( & V_7 [ V_11 ] , V_8 , V_9 , V_10 ) ;
V_24 [ V_11 ] = & V_7 [ V_11 ] ;
}
F_12 ( & V_26 , V_24 , V_11 , NULL ) ;
}
return 0 ;
}
