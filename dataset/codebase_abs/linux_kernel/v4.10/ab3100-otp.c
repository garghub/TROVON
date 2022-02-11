static int T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 [ 8 ] ;
T_2 V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , 0 ,
V_7 , & V_4 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_6 , L_1 ) ;
return V_5 ;
}
V_5 = F_4 ( V_2 -> V_6 , 0 ,
V_8 , V_3 , 8 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_6 , L_2 ) ;
return V_5 ;
}
V_2 -> V_9 = ( V_4 & 0x80 ) ;
V_2 -> V_10 = ( V_4 & 0x40 ) ? 32768 : 34100 ;
V_2 -> V_11 = ( V_3 [ 1 ] & 0x80 ) ;
V_2 -> V_12 = ( V_3 [ 1 ] & 0x40 ) ;
V_2 -> V_13 = ( ( V_3 [ 1 ] << 8 ) | V_3 [ 0 ] ) & 0x3fff ;
V_2 -> V_14 = ( ( V_3 [ 4 ] & 0x0f ) << 16 ) | ( V_3 [ 3 ] << 8 ) | V_3 [ 2 ] ;
V_2 -> V_15 = ( ( V_3 [ 5 ] & 0x0f ) << 4 ) | ( V_3 [ 4 ] >> 4 ) ;
V_2 -> V_16 = ( V_3 [ 7 ] << 12 ) | ( V_3 [ 6 ] << 4 ) | ( V_3 [ 5 ] >> 4 ) ;
return 0 ;
}
static int F_5 ( struct V_17 * V_18 , void * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
F_6 ( V_18 , L_3 , V_2 -> V_9 ? L_4 : L_5 ) ;
F_6 ( V_18 , L_6 , V_2 -> V_10 ) ;
F_6 ( V_18 , L_7 , V_2 -> V_11 ? L_8 : L_9 ) ;
F_6 ( V_18 , L_10 , V_2 -> V_12 ?
L_11 : L_12 ) ;
F_6 ( V_18 , L_13 , V_2 -> V_13 , V_2 -> V_13 ) ;
F_6 ( V_18 , L_14 , V_2 -> V_14 , V_2 -> V_15 , V_2 -> V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_8 ( V_22 , F_5 , V_21 -> V_23 ) ;
}
static int T_1 F_9 ( struct V_24 * V_6 ,
struct V_1 * V_2 )
{
V_2 -> V_25 = F_10 ( L_15 , V_26 | V_27 ,
NULL , V_2 ,
& V_28 ) ;
if ( ! V_2 -> V_25 ) {
F_3 ( V_6 , L_16 ) ;
return - V_29 ;
}
return 0 ;
}
static void T_3 F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_25 ) ;
}
static inline int T_1 F_9 ( struct V_24 * V_6 ,
struct V_1 * V_2 )
{
return 0 ;
}
static inline void T_3 F_11 ( struct V_1 * V_2 )
{
}
static int T_1 F_13 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
int V_5 = 0 ;
int V_32 ;
V_2 = F_14 ( & V_31 -> V_6 , sizeof( struct V_1 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_6 = & V_31 -> V_6 ;
F_15 ( V_31 , V_2 ) ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_16 ( & V_31 -> V_6 , L_17 ) ;
for ( V_32 = 0 ; V_32 < F_17 ( V_35 ) ; V_32 ++ ) {
V_5 = F_18 ( & V_31 -> V_6 ,
& V_35 [ V_32 ] ) ;
if ( V_5 )
goto V_5;
}
V_5 = F_9 ( & V_31 -> V_6 , V_2 ) ;
if ( V_5 )
goto V_5;
return 0 ;
V_5:
while ( -- V_32 >= 0 )
F_19 ( & V_31 -> V_6 , & V_35 [ V_32 ] ) ;
return V_5 ;
}
static int T_3 F_20 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_21 ( V_31 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_17 ( V_35 ) ; V_32 ++ )
F_19 ( & V_31 -> V_6 ,
& V_35 [ V_32 ] ) ;
F_11 ( V_2 ) ;
return 0 ;
}
