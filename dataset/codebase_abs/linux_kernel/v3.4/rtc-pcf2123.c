static inline void F_1 ( void )
{
F_2 ( 30 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_8 * V_9 ;
T_2 V_10 [ 1 ] , V_11 [ 1 ] ;
unsigned long V_12 ;
int V_13 ;
V_9 = F_5 ( V_4 , struct V_8 , V_4 ) ;
if ( F_6 ( V_9 -> V_14 , 16 , & V_12 ) )
return - V_15 ;
V_10 [ 0 ] = V_16 | V_12 ;
V_13 = F_7 ( V_7 , V_10 , 1 , V_11 , 1 ) ;
if ( V_13 < 0 )
return - V_17 ;
F_1 () ;
return sprintf ( V_5 , L_1 , V_11 [ 0 ] ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_18 ) {
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_8 * V_9 ;
T_2 V_10 [ 2 ] ;
unsigned long V_12 ;
unsigned long V_19 ;
int V_13 ;
V_9 = F_5 ( V_4 , struct V_8 , V_4 ) ;
if ( F_6 ( V_9 -> V_14 , 16 , & V_12 )
|| F_6 ( V_5 , 10 , & V_19 ) )
return - V_15 ;
V_10 [ 0 ] = V_20 | V_12 ;
V_10 [ 1 ] = V_19 ;
V_13 = F_9 ( V_7 , V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 )
return - V_17 ;
F_1 () ;
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_2 V_10 [ 1 ] , V_11 [ 7 ] ;
int V_13 ;
V_10 [ 0 ] = V_16 | V_23 ;
V_13 = F_7 ( V_7 , V_10 , sizeof( V_10 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
V_22 -> V_24 = F_11 ( V_11 [ 0 ] & 0x7F ) ;
V_22 -> V_25 = F_11 ( V_11 [ 1 ] & 0x7F ) ;
V_22 -> V_26 = F_11 ( V_11 [ 2 ] & 0x3F ) ;
V_22 -> V_27 = F_11 ( V_11 [ 3 ] & 0x3F ) ;
V_22 -> V_28 = V_11 [ 4 ] & 0x07 ;
V_22 -> V_29 = F_11 ( V_11 [ 5 ] & 0x1F ) - 1 ;
V_22 -> V_30 = F_11 ( V_11 [ 6 ] ) ;
if ( V_22 -> V_30 < 70 )
V_22 -> V_30 += 100 ;
F_12 ( V_2 , L_2
L_3 ,
V_31 ,
V_22 -> V_24 , V_22 -> V_25 , V_22 -> V_26 ,
V_22 -> V_27 , V_22 -> V_29 , V_22 -> V_30 , V_22 -> V_28 ) ;
if ( F_13 ( V_22 ) < 0 )
F_14 ( V_2 , L_4 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_2 V_10 [ 8 ] ;
int V_13 ;
F_12 ( V_2 , L_2
L_3 ,
V_31 ,
V_22 -> V_24 , V_22 -> V_25 , V_22 -> V_26 ,
V_22 -> V_27 , V_22 -> V_29 , V_22 -> V_30 , V_22 -> V_28 ) ;
V_10 [ 0 ] = V_20 | V_32 ;
V_10 [ 1 ] = 0x20 ;
V_13 = F_9 ( V_7 , V_10 , 2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
V_10 [ 0 ] = V_20 | V_23 ;
V_10 [ 1 ] = F_16 ( V_22 -> V_24 & 0x7F ) ;
V_10 [ 2 ] = F_16 ( V_22 -> V_25 & 0x7F ) ;
V_10 [ 3 ] = F_16 ( V_22 -> V_26 & 0x3F ) ;
V_10 [ 4 ] = F_16 ( V_22 -> V_27 & 0x3F ) ;
V_10 [ 5 ] = V_22 -> V_28 & 0x07 ;
V_10 [ 6 ] = F_16 ( ( V_22 -> V_29 + 1 ) & 0x1F ) ;
V_10 [ 7 ] = F_16 ( V_22 -> V_30 < 100 ? V_22 -> V_30 : V_22 -> V_30 - 100 ) ;
V_13 = F_9 ( V_7 , V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
V_10 [ 0 ] = V_20 | V_32 ;
V_10 [ 1 ] = 0x00 ;
V_13 = F_9 ( V_7 , V_10 , 2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
return 0 ;
}
static int T_4 F_17 ( struct V_6 * V_7 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
T_2 V_10 [ 2 ] , V_11 [ 2 ] ;
int V_13 , V_37 ;
V_36 = F_18 ( sizeof( struct V_35 ) , V_38 ) ;
if ( ! V_36 )
return - V_39 ;
V_7 -> V_2 . V_40 = V_36 ;
V_10 [ 0 ] = V_20 | V_32 ;
V_10 [ 1 ] = 0x58 ;
F_12 ( & V_7 -> V_2 , L_5 ,
V_10 [ 0 ] , V_10 [ 1 ] ) ;
V_13 = F_9 ( V_7 , V_10 , 2 * sizeof( T_2 ) ) ;
if ( V_13 < 0 )
goto V_41;
F_1 () ;
V_10 [ 0 ] = V_20 | V_32 ;
V_10 [ 1 ] = 0x20 ;
F_12 ( & V_7 -> V_2 , L_6 ,
V_10 [ 0 ] , V_10 [ 1 ] ) ;
V_13 = F_9 ( V_7 , V_10 , 2 * sizeof( T_2 ) ) ;
if ( V_13 < 0 )
goto V_41;
F_1 () ;
V_10 [ 0 ] = V_16 | V_32 ;
F_12 ( & V_7 -> V_2 , L_7 ,
V_10 [ 0 ] ) ;
V_13 = F_7 ( V_7 , V_10 , 1 * sizeof( T_2 ) ,
V_11 , 2 * sizeof( T_2 ) ) ;
F_12 ( & V_7 -> V_2 , L_8 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
if ( V_13 < 0 )
goto V_41;
F_1 () ;
if ( ! ( V_11 [ 0 ] & 0x20 ) ) {
F_14 ( & V_7 -> V_2 , L_9 ) ;
goto V_41;
}
F_19 ( & V_7 -> V_2 , L_10 V_42 L_11 ) ;
F_19 ( & V_7 -> V_2 , L_12 ,
( V_7 -> V_43 + 500 ) / 1000 ) ;
V_10 [ 0 ] = V_20 | V_32 ;
V_10 [ 1 ] = 0x00 ;
V_13 = F_9 ( V_7 , V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 )
goto V_41;
F_1 () ;
V_34 = F_20 ( V_44 . V_45 . V_14 , & V_7 -> V_2 ,
& V_46 , V_47 ) ;
if ( F_21 ( V_34 ) ) {
F_14 ( & V_7 -> V_2 , L_13 ) ;
V_13 = F_22 ( V_34 ) ;
goto V_41;
}
V_36 -> V_34 = V_34 ;
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ ) {
sprintf ( V_36 -> V_48 [ V_37 ] . V_14 , L_14 , V_37 ) ;
V_36 -> V_48 [ V_37 ] . V_4 . V_4 . V_49 = V_50 | V_51 ;
V_36 -> V_48 [ V_37 ] . V_4 . V_4 . V_14 = V_36 -> V_48 [ V_37 ] . V_14 ;
V_36 -> V_48 [ V_37 ] . V_4 . V_52 = F_3 ;
V_36 -> V_48 [ V_37 ] . V_4 . V_53 = F_8 ;
V_13 = F_23 ( & V_7 -> V_2 , & V_36 -> V_48 [ V_37 ] . V_4 ) ;
if ( V_13 ) {
F_14 ( & V_7 -> V_2 , L_15 ,
V_36 -> V_48 [ V_37 ] . V_14 ) ;
goto V_54;
}
}
return 0 ;
V_54:
for ( V_37 -- ; V_37 >= 0 ; V_37 -- )
F_24 ( & V_7 -> V_2 , & V_36 -> V_48 [ V_37 ] . V_4 ) ;
V_41:
F_25 ( V_36 ) ;
V_7 -> V_2 . V_40 = NULL ;
return V_13 ;
}
static int T_5 F_26 ( struct V_6 * V_7 )
{
struct V_35 * V_36 = V_7 -> V_2 . V_40 ;
int V_37 ;
if ( V_36 ) {
struct V_33 * V_34 = V_36 -> V_34 ;
if ( V_34 )
F_27 ( V_34 ) ;
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ )
if ( V_36 -> V_48 [ V_37 ] . V_14 [ 0 ] )
F_24 ( & V_7 -> V_2 ,
& V_36 -> V_48 [ V_37 ] . V_4 ) ;
F_25 ( V_36 ) ;
}
return 0 ;
}
