static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] ;
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_1 * V_2 , unsigned int V_3 )
{
static long V_9 [] = { 0x220 , 0x240 , 0x260 } ;
static int V_10 [] = { 5 , 9 , 10 , 7 , - 1 } ;
static int V_11 [] = { 1 , 3 , 0 , - 1 } ;
int V_12 , error ;
if ( V_13 [ V_3 ] == V_14 ) {
V_13 [ V_3 ] = F_3 ( V_10 ) ;
if ( V_13 [ V_3 ] < 0 ) {
F_4 ( V_2 , L_1 ) ;
return - V_15 ;
}
}
if ( V_16 [ V_3 ] == V_17 ) {
V_16 [ V_3 ] = F_5 ( V_11 ) ;
if ( V_16 [ V_3 ] < 0 ) {
F_4 ( V_2 , L_2 ) ;
return - V_15 ;
}
}
if ( V_18 [ V_3 ] != V_19 )
return F_6 ( V_6 , V_8 , V_18 [ V_3 ] , V_20 [ V_3 ] ,
V_13 [ V_3 ] , V_21 [ V_3 ] , V_16 [ V_3 ] , V_22 ) ;
V_12 = 0 ;
do {
V_18 [ V_3 ] = V_9 [ V_12 ] ;
error = F_6 ( V_6 , V_8 , V_18 [ V_3 ] , V_20 [ V_3 ] ,
V_13 [ V_3 ] , V_21 [ V_3 ] , V_16 [ V_3 ] , V_22 ) ;
} while ( error < 0 && ++ V_12 < F_7 ( V_9 ) );
return error ;
}
static int F_8 ( struct V_5 * V_6 ,
struct V_1 * V_2 , unsigned int V_3 ,
struct V_23 * * V_24 )
{
static int V_10 [] = { 11 , 12 , 15 , 9 , 5 , 7 , 3 , - 1 } ;
static int V_11 [] = { 5 , 6 , 7 , 3 , 1 , - 1 } ;
if ( V_25 [ V_3 ] == V_14 ) {
V_25 [ V_3 ] = F_3 ( V_10 ) ;
if ( V_25 [ V_3 ] < 0 ) {
F_4 ( V_2 , L_3 ) ;
return - V_15 ;
}
}
if ( V_26 [ V_3 ] == V_17 ) {
V_26 [ V_3 ] = F_5 ( V_11 ) ;
if ( V_26 [ V_3 ] < 0 ) {
F_4 ( V_2 , L_4 ) ;
return - V_15 ;
}
}
return F_9 ( V_6 , V_27 [ V_3 ] , V_25 [ V_3 ] , V_26 [ V_3 ] , - 1 ,
0 , V_28 [ V_3 ] , V_29 [ V_3 ] , 0 , V_24 ) ;
}
static int F_10 ( struct V_23 * V_30 ,
struct V_7 * V_31 )
{
unsigned long V_32 ;
unsigned char V_33 ;
F_11 ( & V_31 -> V_34 , V_32 ) ;
F_12 ( V_31 , 0x40 , 0x0b ) ;
F_13 ( & V_31 -> V_34 , V_32 ) ;
F_11 ( & V_31 -> V_35 , V_32 ) ;
F_14 ( V_30 -> V_36 . V_18 & 0x040 ? 2 : 0 , F_15 ( V_31 , V_37 ) ) ;
F_14 ( 0 , 0x201 ) ;
F_14 ( V_30 -> V_36 . V_18 & 0x020 ? 2 : 0 , F_15 ( V_31 , V_37 ) ) ;
F_14 ( 0 , 0x201 ) ;
F_14 ( V_30 -> V_36 . V_18 & 0x010 ? 3 : 1 , F_15 ( V_31 , V_37 ) ) ;
F_13 ( & V_31 -> V_35 , V_32 ) ;
F_16 ( 100 ) ;
F_17 ( V_30 , V_38 , 0 ) ;
if ( ( ( V_33 = F_18 ( V_30 , V_38 ) ) & 0x07 ) != 0 ) {
F_19 ( L_5 , V_30 -> V_36 . V_18 , V_33 ) ;
return - V_39 ;
}
F_16 ( 160 ) ;
F_17 ( V_30 , V_38 , 1 ) ;
F_16 ( 160 ) ;
if ( ( ( V_33 = F_18 ( V_30 , V_38 ) ) & 0x07 ) != 1 ) {
F_19 ( L_6 , V_30 -> V_36 . V_18 , V_33 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_40 V_41 , V_42 ;
int error ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_41 . V_43 = V_42 . V_43 = V_44 ;
strcpy ( V_41 . V_45 , L_7 ) ;
strcpy ( V_42 . V_45 , L_8 ) ;
error = F_21 ( V_6 , & V_41 , & V_42 ) ;
if ( error < 0 )
return error ;
strcpy ( V_41 . V_45 , L_9 ) ;
strcpy ( V_42 . V_45 , L_10 ) ;
error = F_21 ( V_6 , & V_41 , & V_42 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_5 * V_6 ;
struct V_23 * V_30 ;
struct V_7 * V_31 ;
struct V_46 * V_47 ;
int error ;
error = F_23 ( V_48 [ V_3 ] , V_49 [ V_3 ] , V_50 ,
sizeof( struct V_7 ) , & V_6 ) ;
if ( error < 0 )
return error ;
V_31 = V_6 -> V_51 ;
if ( V_20 [ V_3 ] == V_19 )
V_20 [ V_3 ] = 0 ;
if ( V_21 [ V_3 ] > 15 )
V_21 [ V_3 ] = - 1 ;
error = F_2 ( V_6 , V_31 , V_2 , V_3 ) ;
if ( error < 0 )
goto V_52;
if ( V_27 [ V_3 ] < 0 )
V_27 [ V_3 ] = V_31 -> V_18 + 0x20 ;
error = F_8 ( V_6 , V_2 , V_3 , & V_30 ) ;
if ( error < 0 )
goto V_52;
error = F_10 ( V_30 , V_31 ) ;
if ( error < 0 )
goto V_52;
V_30 -> V_53 = V_53 [ V_3 ] ;
error = F_24 ( V_30 ) ;
if ( error < 0 )
goto V_52;
error = - V_54 ;
if ( ! V_30 -> V_55 ) {
F_4 ( V_2 , L_11
L_12 , V_30 -> V_36 . V_18 ) ;
goto V_52;
}
V_30 -> V_56 = 1 ;
error = F_25 ( V_6 , V_31 , 0 , NULL ) ;
if ( error < 0 )
goto V_52;
error = F_26 ( V_6 , V_31 ) ;
if ( error < 0 )
goto V_52;
F_27 ( V_6 , L_13 ) ;
if ( V_29 [ V_3 ] > 0 ) {
error = F_28 ( V_30 , 1 , 1 , NULL ) ;
if ( error < 0 )
goto V_52;
}
error = F_29 ( V_30 ) ;
if ( error < 0 )
goto V_52;
error = F_20 ( V_6 ) ;
if ( error < 0 )
goto V_52;
if ( F_30 ( V_6 , V_31 -> V_18 , V_31 -> V_18 + 2 ,
V_57 , 0 , & V_47 ) < 0 )
F_31 ( V_2 , L_14 , V_31 -> V_18 ) ;
else {
error = F_32 ( V_47 , 0 , 2 , NULL ) ;
if ( error < 0 )
goto V_52;
}
if ( V_31 -> V_20 >= 0x300 ) {
error = F_33 ( V_6 , 0 , V_58 ,
V_31 -> V_20 , 0 , V_21 [ V_3 ] , NULL ) ;
if ( error < 0 )
goto V_52;
}
sprintf ( V_6 -> V_59 , L_15
L_16 , V_31 -> V_18 ,
V_30 -> V_36 . V_13 , V_31 -> V_13 , V_30 -> V_36 . V_26 , V_31 -> V_16 ) ;
F_34 ( V_6 , V_2 ) ;
error = F_35 ( V_6 ) ;
if ( error < 0 )
goto V_52;
F_36 ( V_2 , V_6 ) ;
return 0 ;
V_52: F_37 ( V_6 ) ;
return error ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_37 ( F_39 ( V_2 ) ) ;
F_36 ( V_2 , NULL ) ;
return 0 ;
}
static int T_1 F_40 ( void )
{
return F_41 ( & V_60 , V_61 ) ;
}
static void T_2 F_42 ( void )
{
F_43 ( & V_60 ) ;
}
