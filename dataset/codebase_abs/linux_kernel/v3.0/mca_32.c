static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_2 -> V_6 [ 0 ]
+ ( V_2 -> V_6 [ 1 ] << 8 ) ;
if ( ! V_2 -> V_5 && V_2 -> V_7 < V_8 ) {
V_2 -> V_3 = V_9 ;
return;
} else if ( V_2 -> V_5 != 0xffff ) {
V_2 -> V_3 = V_10 ;
}
if ( ( V_2 -> V_5 == 0xffff ||
V_2 -> V_5 == 0x0000 ) && V_2 -> V_7 >= V_8 ) {
int V_11 ;
for ( V_11 = 2 ; V_11 < 8 ; V_11 ++ ) {
if ( V_2 -> V_6 [ V_11 ] != 0xff ) {
V_2 -> V_3 = V_10 ;
break;
}
}
}
if ( ! ( V_2 -> V_6 [ 2 ] & V_12 ) ) {
V_2 -> V_3 = V_13 ;
}
}
static int F_2 ( unsigned char * V_6 )
{
int V_11 ;
int V_14 = 0 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_6 [ V_11 ] = F_3 ( F_4 ( V_11 ) ) ;
if ( V_6 [ V_11 ] != 0xff ) {
V_14 = 1 ;
}
}
return V_14 ;
}
static unsigned char F_5 ( struct V_1 * V_2 , int V_15 )
{
unsigned char V_16 ;
unsigned long V_17 ;
if ( V_15 < 0 || V_15 >= 8 )
return 0 ;
F_6 ( & V_18 , V_17 ) ;
if ( V_2 -> V_19 ) {
F_7 ( 0 , V_20 ) ;
F_7 ( V_2 -> V_19 , V_21 ) ;
V_16 = F_3 ( F_4 ( V_15 ) ) ;
F_7 ( 0xff , V_21 ) ;
} else {
F_7 ( 0xff , V_21 ) ;
F_7 ( 0x8 | ( V_2 -> V_7 & 0xf ) , V_20 ) ;
V_16 = F_3 ( F_4 ( V_15 ) ) ;
F_7 ( 0 , V_20 ) ;
}
F_8 ( & V_18 , V_17 ) ;
V_2 -> V_6 [ V_15 ] = V_16 ;
return V_16 ;
}
static void F_9 ( struct V_1 * V_2 , int V_15 ,
unsigned char V_16 )
{
unsigned long V_17 ;
if ( V_15 < 0 || V_15 >= 8 )
return;
F_6 ( & V_18 , V_17 ) ;
F_7 ( 0xff , V_21 ) ;
F_7 ( 0x8 | ( V_2 -> V_7 & 0xf ) , V_20 ) ;
F_7 ( V_16 , F_4 ( V_15 ) ) ;
F_7 ( 0 , V_20 ) ;
F_8 ( & V_18 , V_17 ) ;
V_2 -> V_6 [ V_15 ] = V_16 ;
}
static int F_10 ( struct V_1 * V_2 , int V_22 )
{
return V_22 ;
}
static int F_11 ( struct V_1 * V_2 , int V_23 )
{
return V_23 ;
}
static void * F_12 ( struct V_1 * V_2 , void * V_24 )
{
return V_24 ;
}
static int T_1 F_13 ( void )
{
unsigned int V_25 , V_11 ;
struct V_1 * V_2 ;
unsigned char V_6 [ 8 ] ;
short V_26 [] = { 0xf7 , 0xfd , 0x00 } ;
struct V_27 * V_28 ;
if ( F_14 () ) {
F_15 ( V_29 L_1 ) ;
return - V_30 ;
}
if ( ! V_31 )
return - V_30 ;
F_15 ( V_32 L_2 ) ;
V_28 = F_16 ( V_33 ) ;
if ( ! V_28 )
goto V_34;
V_28 -> V_35 = 0xffffffffLL ;
V_28 -> V_36 . V_37 = F_9 ;
V_28 -> V_36 . V_38 = F_5 ;
V_28 -> V_36 . V_39 = F_10 ;
V_28 -> V_36 . V_40 = F_11 ;
V_28 -> V_36 . V_41 = F_12 ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_42 ) ;
if ( F_18 ( ! V_2 ) )
goto V_34;
F_19 ( & V_18 ) ;
F_7 ( 0 , V_20 ) ;
V_2 -> V_19 = 0x7f ;
F_7 ( V_2 -> V_19 , V_21 ) ;
V_2 -> V_43 [ 0 ] = 0 ;
F_2 ( V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 = V_44 ;
V_2 -> V_7 = V_45 ;
F_20 ( V_33 , V_2 ) ;
V_2 = F_17 ( sizeof( struct V_1 ) , V_46 ) ;
if ( F_18 ( ! V_2 ) )
goto V_47;
V_2 -> V_19 = 0xdf ;
F_7 ( V_2 -> V_19 , V_21 ) ;
V_2 -> V_43 [ 0 ] = 0 ;
F_2 ( V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 = V_48 ;
V_2 -> V_7 = V_49 ;
F_20 ( V_33 , V_2 ) ;
for ( V_25 = 0 ; ( V_50 = V_26 [ V_25 ] ) != 0 ; V_25 ++ ) {
F_7 ( V_50 , V_21 ) ;
if ( F_2 ( V_6 ) )
break;
}
if ( V_50 ) {
V_2 = F_17 ( sizeof( struct V_1 ) , V_46 ) ;
if ( F_18 ( ! V_2 ) )
goto V_47;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
V_2 -> V_6 [ V_11 ] = V_6 [ V_11 ] ;
F_1 ( V_2 ) ;
V_2 -> V_5 = V_51 ;
V_2 -> V_7 = V_52 ;
V_2 -> V_19 = V_50 ;
F_20 ( V_33 , V_2 ) ;
}
F_7 ( 0xff , V_21 ) ;
for ( V_25 = 0 ; V_25 < V_8 ; V_25 ++ ) {
F_7 ( 0x8 | ( V_25 & 0xf ) , V_20 ) ;
if ( ! F_2 ( V_6 ) )
continue;
V_2 = F_17 ( sizeof( struct V_1 ) , V_46 ) ;
if ( F_18 ( ! V_2 ) )
goto V_47;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ )
V_2 -> V_6 [ V_11 ] = V_6 [ V_11 ] ;
V_2 -> V_53 = 0 ;
V_2 -> V_7 = V_25 ;
V_2 -> V_19 = 0 ;
F_1 ( V_2 ) ;
F_20 ( V_33 , V_2 ) ;
}
F_7 ( 0 , V_20 ) ;
F_21 ( & V_18 ) ;
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ )
F_22 ( & V_55 , V_56 + V_25 ) ;
F_23 () ;
return 0 ;
V_47:
F_21 ( & V_18 ) ;
V_34:
F_15 ( V_57 L_3 ) ;
return - V_58 ;
}
static T_2 void
F_24 ( struct V_1 * V_2 , int V_59 )
{
int V_7 = V_2 -> V_7 ;
if ( V_7 == V_52 ) {
F_15 ( V_60 L_4 ,
V_2 -> V_43 ) ;
} else if ( V_7 == V_49 ) {
F_15 ( V_60 L_5 ,
V_2 -> V_43 ) ;
} else if ( V_7 == V_45 ) {
F_15 ( V_60 L_6 ,
V_2 -> V_43 ) ;
}
if ( V_59 ) {
unsigned char V_61 , V_62 ;
V_61 = F_25 ( V_2 , 6 ) ;
V_62 = F_25 ( V_2 , 7 ) ;
F_15 ( V_60 L_7 , V_61 , V_62 ) ;
}
}
static int T_2 F_26 ( struct V_63 * V_64 , void * V_65 )
{
struct V_1 * V_2 = F_27 ( V_64 ) ;
unsigned char V_66 ;
V_66 = F_25 ( V_2 , 5 ) ;
if ( ! ( V_66 & 0x80 ) ) {
F_24 ( V_2 , ! ( V_66 & 0x40 ) ) ;
return 1 ;
}
return 0 ;
}
void T_2 F_28 ( void )
{
F_29 ( & V_67 , NULL , NULL , F_26 ) ;
}
