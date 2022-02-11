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
unsigned char V_7 , V_8 , V_9 ;
if ( ! F_10 ( V_6 , V_10 , V_11 ) )
return - V_12 ;
V_7 = F_2 ( V_6 + V_13 ) ;
V_8 = 0 ;
do {
F_6 ( V_8 , V_6 + V_13 ) ;
V_9 = F_2 ( V_6 + V_14 ) ;
V_9 ^= 0x0FE ;
F_6 ( V_9 , V_6 + V_13 ) ;
V_9 = F_2 ( V_6 + V_14 ) ;
V_9 ^= 0x0FE ;
if( V_8 != V_9 ) {
F_11 ( V_6 , V_10 ) ;
return - V_12 ;
}
V_8 -= 2 ;
} while( V_8 != 0 );
F_6 ( V_7 , V_6 + V_13 ) ;
V_2 -> V_4 = V_6 ;
return 0 ;
}
static int T_1 F_12 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_17 * V_18 ;
static int V_19 ;
const unsigned * V_20 ;
int V_21 , V_22 = 0 ;
if ( ! V_2 )
return - V_23 ;
if ( V_2 -> V_4 )
V_22 = F_9 ( V_2 , V_2 -> V_4 ) ;
else {
for ( V_20 = V_24 ; * V_20 ; V_20 ++ ) {
V_22 = F_9 ( V_2 , * V_20 ) ;
if ( ! V_22 )
break;
}
}
if ( V_22 )
goto V_25;
if ( V_19 ++ == 0 )
F_13 ( V_26 L_1 , V_27 ) ;
V_22 = - V_28 ;
V_16 -> V_29 = & V_29 ;
if ( F_14 ( V_2 , V_16 ) )
goto V_30;
V_2 -> V_4 &= ~ 3 ;
F_15 ( V_2 ) ;
F_13 ( V_26 L_2 ,
V_2 -> V_31 ) ;
V_18 = F_16 ( V_2 ) ;
V_18 -> V_32 = V_33 ;
V_18 -> V_34 = F_1 ;
V_18 -> V_35 = F_3 ;
V_18 -> V_36 = F_5 ;
V_18 -> V_37 = F_7 ;
memcpy ( V_18 -> V_38 , V_11 , V_39 + 1 ) ;
V_18 -> V_40 = NULL ;
V_2 -> V_41 = & V_42 ;
if ( V_2 -> V_43 == 0 )
{
for( V_21 = 0 ; V_44 [ V_21 ] != 0 ; V_21 ++ )
{
V_2 -> V_43 = V_44 [ V_21 ] ;
if ( ! F_17 ( V_2 -> V_43 , V_45 , 0 ,
V_11 , V_2 ) )
break;
}
if( V_44 [ V_21 ] == 0 )
{
F_13 ( V_46 L_3 ) ;
goto V_47;
}
}
else
{
for( V_21 = 0 ; V_44 [ V_21 ] != 0 ; V_21 ++ )
if ( V_44 [ V_21 ] == V_2 -> V_43 )
break;
if ( V_44 [ V_21 ] == 0 )
{
F_13 ( V_46 L_4 ,
V_2 -> V_43 ) ;
goto V_47;
}
if ( F_17 ( V_2 -> V_43 , V_45 , 0 ,
V_11 , V_2 ) )
{
F_13 ( V_46 L_5 ,
V_2 -> V_43 ) ;
goto V_47;
}
}
if ( V_2 -> V_48 == 0 )
{
for( V_21 = 0 ; V_49 [ V_21 ] != 0 ; V_21 ++ )
{
V_2 -> V_48 = V_49 [ V_21 ] ;
if ( ! F_18 ( V_2 -> V_48 , V_11 ) )
break;
}
if( V_49 [ V_21 ] == 0 )
{
F_13 ( V_46 L_6 ) ;
goto V_50;
}
}
else
{
for( V_21 = 0 ; V_49 [ V_21 ] != 0 ; V_21 ++ )
if ( V_49 [ V_21 ] == V_2 -> V_48 )
break;
if ( V_49 [ V_21 ] == 0 )
{
F_13 ( V_46 L_7 ,
V_2 -> V_48 ) ;
goto V_50;
}
if ( F_18 ( V_2 -> V_48 , V_11 ) )
{
F_13 ( V_46 L_8 ,
V_2 -> V_48 ) ;
goto V_50;
}
}
V_22 = F_19 ( V_2 ) ;
if ( V_22 )
goto V_51;
F_13 ( V_26 L_9 ,
V_2 -> V_52 , V_2 -> V_4 , V_2 -> V_43 , V_2 -> V_48 ) ;
return 0 ;
V_51:
F_20 ( V_2 -> V_48 ) ;
V_50:
F_21 ( V_2 -> V_43 , V_2 ) ;
V_47:
F_22 ( V_2 ) ;
V_30:
F_11 ( V_2 -> V_4 , V_10 ) ;
V_25:
return V_22 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_53 ;
F_7 ( V_2 , 0 , V_54 ) ;
F_7 ( V_2 , 0 , V_13 ) ;
V_2 -> V_55 = 6 ;
for( V_53 = 0 ; V_53 < 6 ; V_53 ++ )
V_2 -> V_31 [ V_53 ] = F_3 ( V_2 , V_56 ) >> 8 ;
}
static unsigned short V_33 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_16 ( V_2 ) ;
unsigned short V_5 = 0 ;
unsigned short V_57 ;
int V_53 ;
V_5 = 0 ;
for( V_53 = 0 ; V_44 [ V_53 ] != 0 ; V_53 ++ )
{
if( V_44 [ V_53 ] == V_2 -> V_43 )
break;
}
V_5 |= V_58 << 2 ;
V_5 |= V_53 << 4 ;
V_53 = V_2 -> V_48 - 5 ;
V_5 |= V_53 ;
if( V_18 -> V_59 == V_60 )
V_5 |= V_61 ;
else
V_5 &= ~ V_61 ;
V_57 = F_1 ( V_2 , V_62 ) ;
V_57 |= 0xf3 ;
V_5 &= V_57 ;
F_5 ( V_2 , V_5 , V_62 ) ;
return F_24 ( V_2 ) ;
}
static int T_1 F_25 ( void )
{
struct V_1 * V_2 ;
struct V_63 * V_16 ;
int V_53 , V_64 = 0 , V_22 = 0 ;
V_42 = V_65 ;
V_42 . V_66 = F_23 ;
V_42 . V_67 = V_68 ;
V_22 = F_26 ( & V_69 ) ;
if ( V_22 )
return V_22 ;
for ( V_53 = 0 ; V_53 < V_70 ; V_53 ++ ) {
V_2 = F_27 ( sizeof( struct V_17 ) ) ;
if ( ! V_2 )
continue;
V_2 -> V_4 = V_71 [ V_53 ] ;
V_2 -> V_43 = V_43 [ V_53 ] ;
V_2 -> V_48 = V_48 [ V_53 ] ;
V_16 = F_28 ( L_10 ,
V_53 , NULL , 0 ) ;
if ( F_29 ( V_16 ) ) {
F_30 ( V_2 ) ;
continue;
}
V_22 = F_12 ( V_2 , & V_16 -> V_2 ) ;
if ( ! V_22 ) {
V_72 [ V_53 ] = V_16 ;
F_31 ( V_72 [ V_53 ] , V_2 ) ;
++ V_64 ;
} else {
F_32 ( V_16 ) ;
F_30 ( V_2 ) ;
}
}
F_13 ( V_73 L_11 , V_64 ) ;
if ( V_64 == 0 ) {
F_13 ( V_73 L_12 ) ;
F_33 ( & V_69 ) ;
return - V_12 ;
}
return 0 ;
}
static void T_2 F_34 ( void )
{
struct V_1 * V_2 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_70 ; V_53 ++ ) {
struct V_63 * V_16 = V_72 [ V_53 ] ;
if ( ! V_16 )
continue;
V_2 = F_35 ( V_16 ) ;
F_36 ( V_2 ) ;
F_11 ( V_2 -> V_4 , V_10 ) ;
F_21 ( V_2 -> V_43 , V_2 ) ;
F_20 ( V_2 -> V_48 ) ;
F_22 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_16 , NULL ) ;
F_32 ( V_16 ) ;
}
F_33 ( & V_69 ) ;
}
