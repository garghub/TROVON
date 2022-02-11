static unsigned short F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static unsigned short F_3 ( struct V_1 * V_2 , unsigned short V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned short V_5 , unsigned short V_3 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int T_1 F_9 ( struct V_1 * V_2 , int V_6 )
{
unsigned char V_7 , V_8 ;
int V_9 ;
if ( ! F_10 ( V_6 , V_10 , V_11 ) )
return - V_12 ;
V_7 = F_2 ( V_6 + 0x1f ) ;
if ( V_7 != 0x1f )
goto V_13;
V_7 = F_2 ( V_6 + 0x1e ) & 0x07 ;
for ( V_9 = 0 ; V_9 < 16 ; V_9 ++ ) {
V_8 = F_2 ( V_6 + 0x1e ) & 0x07 ;
if ( ( ( V_7 + 1 ) & 0x07 ) != V_8 )
goto V_13;
V_7 = V_8 ;
}
V_2 -> V_4 = V_6 ;
return 0 ;
V_13:
F_11 ( V_6 , V_10 ) ;
return - V_12 ;
}
static int T_1 F_12 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_16 * V_17 ;
static int V_18 ;
const unsigned * V_19 ;
int V_20 , V_21 = 0 ;
if ( ! V_2 )
return - V_22 ;
if ( V_2 -> V_4 )
V_21 = F_9 ( V_2 , V_2 -> V_4 ) ;
else {
for ( V_19 = V_23 ; * V_19 ; V_19 ++ ) {
V_21 = F_9 ( V_2 , * V_19 ) ;
if ( ! V_21 )
break;
}
}
if ( V_21 )
goto V_24;
if ( V_18 ++ == 0 )
F_13 ( V_25 L_1 , V_26 ) ;
V_21 = - V_27 ;
V_15 -> V_28 = & V_28 ;
if ( F_14 ( V_2 , V_15 ) )
goto V_29;
V_2 -> V_4 &= ~ 3 ;
F_15 ( V_2 ) ;
F_13 ( V_25 L_2 ,
V_2 -> V_30 ) ;
V_17 = F_16 ( V_2 ) ;
V_17 -> V_31 = V_32 ;
V_17 -> V_33 = F_1 ;
V_17 -> V_34 = F_3 ;
V_17 -> V_35 = F_5 ;
V_17 -> V_36 = F_7 ;
memcpy ( V_17 -> V_37 , V_11 , V_38 + 1 ) ;
V_17 -> V_39 = NULL ;
V_2 -> V_40 = & V_41 ;
if ( V_2 -> V_42 == 0 )
{
for( V_20 = 0 ; V_43 [ V_20 ] != 0 ; V_20 ++ )
{
V_2 -> V_42 = V_43 [ V_20 ] ;
if ( ! F_17 ( V_2 -> V_42 , V_44 , 0 ,
V_11 , V_2 ) )
break;
}
if( V_43 [ V_20 ] == 0 )
{
F_13 ( V_45 L_3 ) ;
goto V_46;
}
}
else
{
for( V_20 = 0 ; V_43 [ V_20 ] != 0 ; V_20 ++ )
if ( V_43 [ V_20 ] == V_2 -> V_42 )
break;
if ( V_43 [ V_20 ] == 0 )
{
F_13 ( V_45 L_4 ,
V_2 -> V_42 ) ;
goto V_46;
}
if ( F_17 ( V_2 -> V_42 , V_44 , 0 ,
V_11 , V_2 ) )
{
F_13 ( V_45 L_5 ,
V_2 -> V_42 ) ;
goto V_46;
}
}
if ( V_2 -> V_47 == 0 )
{
for( V_20 = 0 ; V_48 [ V_20 ] != 0 ; V_20 ++ )
{
V_2 -> V_47 = V_48 [ V_20 ] ;
if ( ! F_18 ( V_2 -> V_47 , V_11 ) )
break;
}
if( V_48 [ V_20 ] == 0 )
{
F_13 ( V_45 L_6 ) ;
goto V_49;
}
}
else
{
for( V_20 = 0 ; V_48 [ V_20 ] != 0 ; V_20 ++ )
if ( V_48 [ V_20 ] == V_2 -> V_47 )
break;
if ( V_48 [ V_20 ] == 0 )
{
F_13 ( V_45 L_7 ,
V_2 -> V_47 ) ;
goto V_49;
}
if ( F_18 ( V_2 -> V_47 , V_11 ) )
{
F_13 ( V_45 L_8 ,
V_2 -> V_47 ) ;
goto V_49;
}
}
V_21 = F_19 ( V_2 ) ;
if ( V_21 )
goto V_50;
F_13 ( V_25 L_9 ,
V_2 -> V_51 , V_2 -> V_4 , V_2 -> V_42 , V_2 -> V_47 ) ;
return 0 ;
V_50:
F_20 ( V_2 -> V_47 ) ;
V_49:
F_21 ( V_2 -> V_42 , V_2 ) ;
V_46:
F_22 ( V_2 ) ;
V_29:
F_11 ( V_2 -> V_4 , V_10 ) ;
V_24:
return V_21 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_9 ;
F_7 ( V_2 , 0 , V_52 ) ;
F_7 ( V_2 , 0 , V_53 ) ;
V_2 -> V_54 = 6 ;
for( V_9 = 0 ; V_9 < 6 ; V_9 ++ )
V_2 -> V_30 [ V_9 ] = F_3 ( V_2 , V_55 ) >> 8 ;
}
static unsigned short V_32 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_16 ( V_2 ) ;
unsigned short V_5 = 0 ;
int V_9 ;
F_6 ( 0 , V_2 -> V_4 + 0x11 ) ;
F_24 ( 20 ) ;
F_6 ( 0x04 , V_2 -> V_4 + 0x11 ) ;
F_24 ( 20 ) ;
F_6 ( 0 , V_2 -> V_4 + 0x11 ) ;
F_24 ( 100 ) ;
V_5 = F_2 ( V_2 -> V_4 + 0x11 ) ;
V_5 |= 0x78 ;
V_5 &= 0xf9 ;
if( V_17 -> V_56 == V_57 )
V_5 |= 0x20 ;
else
V_5 &= ~ 0x20 ;
F_6 ( V_5 , V_2 -> V_4 + 0x11 ) ;
F_6 ( 0xff , V_2 -> V_4 + 0x12 ) ;
for( V_9 = 0 ; V_43 [ V_9 ] != 0 ; V_9 ++ )
{
if( V_43 [ V_9 ] == V_2 -> V_42 )
break;
}
V_5 = V_9 ;
V_9 = ( 7 - V_2 -> V_47 ) << 4 ;
V_5 |= V_9 ;
F_6 ( V_5 , V_2 -> V_4 + 0x13 ) ;
return F_25 ( V_2 ) ;
}
static int T_1 F_26 ( void )
{
struct V_1 * V_2 ;
struct V_58 * V_15 ;
int V_9 , V_59 = 0 , V_21 = 0 ;
V_41 = V_60 ;
V_41 . V_61 = F_23 ;
V_41 . V_62 = V_63 ;
V_21 = F_27 ( & V_64 ) ;
if ( V_21 )
return V_21 ;
for ( V_9 = 0 ; V_9 < V_65 ; V_9 ++ ) {
V_2 = F_28 ( sizeof( struct V_16 ) ) ;
if ( ! V_2 )
continue;
V_2 -> V_4 = V_66 [ V_9 ] ;
V_2 -> V_42 = V_42 [ V_9 ] ;
V_2 -> V_47 = V_47 [ V_9 ] ;
V_15 = F_29 ( L_10 ,
V_9 , NULL , 0 ) ;
if ( F_30 ( V_15 ) ) {
F_31 ( V_2 ) ;
continue;
}
V_21 = F_12 ( V_2 , & V_15 -> V_2 ) ;
if ( ! V_21 ) {
V_67 [ V_9 ] = V_15 ;
F_32 ( V_15 , V_2 ) ;
++ V_59 ;
} else {
F_33 ( V_15 ) ;
F_31 ( V_2 ) ;
}
}
F_13 ( V_68 L_11 , V_59 ) ;
if ( V_59 == 0 ) {
F_13 ( V_68 L_12 ) ;
F_34 ( & V_64 ) ;
return - V_12 ;
}
return 0 ;
}
static void T_2 F_35 ( void )
{
struct V_1 * V_2 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_65 ; V_9 ++ ) {
struct V_58 * V_15 = V_67 [ V_9 ] ;
if ( ! V_15 )
continue;
V_2 = F_36 ( V_15 ) ;
F_37 ( V_2 ) ;
F_11 ( V_2 -> V_4 , V_10 ) ;
F_21 ( V_2 -> V_42 , V_2 ) ;
F_20 ( V_2 -> V_47 ) ;
F_22 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_15 , NULL ) ;
F_33 ( V_15 ) ;
}
F_34 ( & V_64 ) ;
}
