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
V_13 = F_6 ( V_9 -> V_14 , 16 , & V_12 ) ;
if ( V_13 )
return V_13 ;
V_10 [ 0 ] = V_15 | V_12 ;
V_13 = F_7 ( V_7 , V_10 , 1 , V_11 , 1 ) ;
if ( V_13 < 0 )
return - V_16 ;
F_1 () ;
return sprintf ( V_5 , L_1 , V_11 [ 0 ] ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_17 ) {
struct V_6 * V_7 = F_4 ( V_2 ) ;
struct V_8 * V_9 ;
T_2 V_10 [ 2 ] ;
unsigned long V_12 ;
unsigned long V_18 ;
int V_13 ;
V_9 = F_5 ( V_4 , struct V_8 , V_4 ) ;
V_13 = F_6 ( V_9 -> V_14 , 16 , & V_12 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_6 ( V_5 , 10 , & V_18 ) ;
if ( V_13 )
return V_13 ;
V_10 [ 0 ] = V_19 | V_12 ;
V_10 [ 1 ] = V_18 ;
V_13 = F_9 ( V_7 , V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 )
return - V_16 ;
F_1 () ;
return V_17 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_2 V_10 [ 1 ] , V_11 [ 7 ] ;
int V_13 ;
V_10 [ 0 ] = V_15 | V_22 ;
V_13 = F_7 ( V_7 , V_10 , sizeof( V_10 ) ,
V_11 , sizeof( V_11 ) ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
V_21 -> V_23 = F_11 ( V_11 [ 0 ] & 0x7F ) ;
V_21 -> V_24 = F_11 ( V_11 [ 1 ] & 0x7F ) ;
V_21 -> V_25 = F_11 ( V_11 [ 2 ] & 0x3F ) ;
V_21 -> V_26 = F_11 ( V_11 [ 3 ] & 0x3F ) ;
V_21 -> V_27 = V_11 [ 4 ] & 0x07 ;
V_21 -> V_28 = F_11 ( V_11 [ 5 ] & 0x1F ) - 1 ;
V_21 -> V_29 = F_11 ( V_11 [ 6 ] ) ;
if ( V_21 -> V_29 < 70 )
V_21 -> V_29 += 100 ;
F_12 ( V_2 , L_2
L_3 ,
V_30 ,
V_21 -> V_23 , V_21 -> V_24 , V_21 -> V_25 ,
V_21 -> V_26 , V_21 -> V_28 , V_21 -> V_29 , V_21 -> V_27 ) ;
return F_13 ( V_21 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
T_2 V_10 [ 8 ] ;
int V_13 ;
F_12 ( V_2 , L_2
L_3 ,
V_30 ,
V_21 -> V_23 , V_21 -> V_24 , V_21 -> V_25 ,
V_21 -> V_26 , V_21 -> V_28 , V_21 -> V_29 , V_21 -> V_27 ) ;
V_10 [ 0 ] = V_19 | V_31 ;
V_10 [ 1 ] = 0x20 ;
V_13 = F_9 ( V_7 , V_10 , 2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
V_10 [ 0 ] = V_19 | V_22 ;
V_10 [ 1 ] = F_15 ( V_21 -> V_23 & 0x7F ) ;
V_10 [ 2 ] = F_15 ( V_21 -> V_24 & 0x7F ) ;
V_10 [ 3 ] = F_15 ( V_21 -> V_25 & 0x3F ) ;
V_10 [ 4 ] = F_15 ( V_21 -> V_26 & 0x3F ) ;
V_10 [ 5 ] = V_21 -> V_27 & 0x07 ;
V_10 [ 6 ] = F_15 ( ( V_21 -> V_28 + 1 ) & 0x1F ) ;
V_10 [ 7 ] = F_15 ( V_21 -> V_29 < 100 ? V_21 -> V_29 : V_21 -> V_29 - 100 ) ;
V_13 = F_9 ( V_7 , V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
V_10 [ 0 ] = V_19 | V_31 ;
V_10 [ 1 ] = 0x00 ;
V_13 = F_9 ( V_7 , V_10 , 2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_1 () ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
T_2 V_10 [ 2 ] , V_11 [ 2 ] ;
int V_13 , V_36 ;
V_35 = F_17 ( & V_7 -> V_2 , sizeof( struct V_34 ) ,
V_37 ) ;
if ( ! V_35 )
return - V_38 ;
V_7 -> V_2 . V_39 = V_35 ;
V_10 [ 0 ] = V_19 | V_31 ;
V_10 [ 1 ] = 0x58 ;
F_12 ( & V_7 -> V_2 , L_4 ,
V_10 [ 0 ] , V_10 [ 1 ] ) ;
V_13 = F_9 ( V_7 , V_10 , 2 * sizeof( T_2 ) ) ;
if ( V_13 < 0 )
goto V_40;
F_1 () ;
V_10 [ 0 ] = V_19 | V_31 ;
V_10 [ 1 ] = 0x20 ;
F_12 ( & V_7 -> V_2 , L_5 ,
V_10 [ 0 ] , V_10 [ 1 ] ) ;
V_13 = F_9 ( V_7 , V_10 , 2 * sizeof( T_2 ) ) ;
if ( V_13 < 0 )
goto V_40;
F_1 () ;
V_10 [ 0 ] = V_15 | V_31 ;
F_12 ( & V_7 -> V_2 , L_6 ,
V_10 [ 0 ] ) ;
V_13 = F_7 ( V_7 , V_10 , 1 * sizeof( T_2 ) ,
V_11 , 2 * sizeof( T_2 ) ) ;
F_12 ( & V_7 -> V_2 , L_7 ,
V_11 [ 0 ] , V_11 [ 1 ] ) ;
if ( V_13 < 0 )
goto V_40;
F_1 () ;
if ( ! ( V_11 [ 0 ] & 0x20 ) ) {
F_18 ( & V_7 -> V_2 , L_8 ) ;
V_13 = - V_41 ;
goto V_40;
}
F_19 ( & V_7 -> V_2 , L_9 V_42 L_10 ) ;
F_19 ( & V_7 -> V_2 , L_11 ,
( V_7 -> V_43 + 500 ) / 1000 ) ;
V_10 [ 0 ] = V_19 | V_31 ;
V_10 [ 1 ] = 0x00 ;
V_13 = F_9 ( V_7 , V_10 , sizeof( V_10 ) ) ;
if ( V_13 < 0 )
goto V_40;
F_1 () ;
V_33 = F_20 ( & V_7 -> V_2 , V_44 . V_45 . V_14 ,
& V_46 , V_47 ) ;
if ( F_21 ( V_33 ) ) {
F_18 ( & V_7 -> V_2 , L_12 ) ;
V_13 = F_22 ( V_33 ) ;
goto V_40;
}
V_35 -> V_33 = V_33 ;
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ ) {
F_23 ( & V_35 -> V_48 [ V_36 ] . V_4 . V_4 ) ;
sprintf ( V_35 -> V_48 [ V_36 ] . V_14 , L_13 , V_36 ) ;
V_35 -> V_48 [ V_36 ] . V_4 . V_4 . V_49 = V_50 | V_51 ;
V_35 -> V_48 [ V_36 ] . V_4 . V_4 . V_14 = V_35 -> V_48 [ V_36 ] . V_14 ;
V_35 -> V_48 [ V_36 ] . V_4 . V_52 = F_3 ;
V_35 -> V_48 [ V_36 ] . V_4 . V_53 = F_8 ;
V_13 = F_24 ( & V_7 -> V_2 , & V_35 -> V_48 [ V_36 ] . V_4 ) ;
if ( V_13 ) {
F_18 ( & V_7 -> V_2 , L_14 ,
V_35 -> V_48 [ V_36 ] . V_14 ) ;
goto V_54;
}
}
return 0 ;
V_54:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- )
F_25 ( & V_7 -> V_2 , & V_35 -> V_48 [ V_36 ] . V_4 ) ;
V_40:
V_7 -> V_2 . V_39 = NULL ;
return V_13 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_34 * V_35 = F_27 ( & V_7 -> V_2 ) ;
int V_36 ;
if ( V_35 ) {
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ )
if ( V_35 -> V_48 [ V_36 ] . V_14 [ 0 ] )
F_25 ( & V_7 -> V_2 ,
& V_35 -> V_48 [ V_36 ] . V_4 ) ;
}
return 0 ;
}
