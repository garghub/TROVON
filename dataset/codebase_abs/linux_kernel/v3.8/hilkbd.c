static void F_1 ( void )
{
int V_1 ;
int V_2 ;
unsigned char V_3 ;
switch ( V_4 . V_5 [ 0 ] ) {
case 0x40 :
V_1 = ( V_4 . V_5 [ 1 ] & 1 ) == 0 ;
V_3 = V_4 . V_5 [ 1 ] >> 1 ;
V_2 = V_6 [ V_3 ] ;
F_2 ( V_4 . V_7 , V_2 , V_1 ) ;
break;
}
V_4 . V_8 = 0 ;
}
static inline void F_3 ( unsigned char V_9 , unsigned char V_10 )
{
if ( V_10 & 0x8 ) {
if ( V_10 & 0x10 )
F_1 () ;
} else {
if ( V_10 & 0x10 ) {
if ( V_4 . V_8 )
F_1 () ;
V_4 . V_8 = V_10 & 7 ;
V_4 . V_11 = 0 ;
}
}
}
static inline void F_4 ( unsigned char V_9 , unsigned char V_10 )
{
if ( V_4 . V_8 ) {
V_4 . V_5 [ V_4 . V_11 ++ ] = V_10 ;
V_4 . V_11 &= 15 ;
}
}
static T_1 F_5 ( int V_12 , void * V_13 )
{
unsigned char V_9 , V_10 ;
V_9 = F_6 () ;
V_10 = F_7 () ;
switch ( V_9 >> 4 ) {
case 0x5 :
F_3 ( V_9 , V_10 ) ;
break;
case 0x6 :
F_4 ( V_9 , V_10 ) ;
break;
case 0x4 :
V_4 . V_9 = V_9 ;
V_4 . V_10 = V_10 ;
F_8 () ;
V_4 . V_14 = 1 ;
break;
}
return V_15 ;
}
static void F_9 ( unsigned char V_16 , unsigned char * V_5 , unsigned int V_17 )
{
unsigned long V_18 ;
F_10 ( & V_4 . V_19 , V_18 ) ;
while ( F_11 () )
;
F_12 ( V_16 ) ;
while ( V_17 -- ) {
while ( F_11 () )
;
F_13 ( * ( V_5 ++ ) ) ;
}
F_14 ( & V_4 . V_19 , V_18 ) ;
}
static int F_15 ( void )
{
unsigned char V_10 ;
unsigned int V_20 , V_21 ;
T_2 V_22 ;
int V_23 ;
if ( V_4 . V_7 )
return - V_24 ;
F_16 ( & V_22 ) ;
F_17 ( & V_4 . V_19 ) ;
V_4 . V_7 = F_18 () ;
if ( ! V_4 . V_7 )
return - V_25 ;
V_23 = F_19 ( V_26 , F_5 , 0 , L_1 , V_4 . V_27 ) ;
if ( V_23 ) {
F_20 ( V_28 L_2 ) ;
goto V_29;
}
F_9 ( V_30 , NULL , 0 ) ;
V_4 . V_14 = 0 ;
F_9 ( V_31 , NULL , 0 ) ;
F_21 ( V_22 , V_4 . V_14 , 3 * V_32 ) ;
if ( ! V_4 . V_14 )
F_20 ( V_33 L_3 ) ;
V_10 = V_4 . V_10 ;
V_4 . V_14 = 0 ;
if ( V_10 == 0 ) {
V_21 = - 1 ;
F_20 ( V_33 L_4 ) ;
} else {
V_21 = F_22 ( ~ V_10 ) ;
F_20 ( V_34 L_5 , V_21 ) ;
}
V_10 = 0 ;
F_9 ( V_35 , & V_10 , 1 ) ;
for ( V_20 = 0 ; V_20 < V_36 ; V_20 ++ )
if ( V_6 [ V_20 ] != V_37 )
F_23 ( V_6 [ V_20 ] , V_4 . V_7 -> V_38 ) ;
V_4 . V_7 -> V_39 [ 0 ] = F_24 ( V_40 ) | F_24 ( V_41 ) ;
V_4 . V_7 -> V_42 [ 0 ] = F_24 ( V_43 ) | F_24 ( V_44 ) |
F_24 ( V_45 ) ;
V_4 . V_7 -> V_46 = V_36 ;
V_4 . V_7 -> V_47 = sizeof( V_6 [ 0 ] ) ;
V_4 . V_7 -> V_48 = V_6 ;
V_4 . V_7 -> V_49 = L_6 ;
V_4 . V_7 -> V_50 = L_7 ;
V_4 . V_7 -> V_51 . V_52 = V_53 ;
V_4 . V_7 -> V_51 . V_54 = V_55 ;
V_4 . V_7 -> V_51 . V_56 = 0x0001 ;
V_4 . V_7 -> V_51 . V_57 = 0x0010 ;
V_23 = F_25 ( V_4 . V_7 ) ;
if ( V_23 ) {
F_20 ( V_28 L_8 ) ;
goto V_58;
}
F_20 ( V_34 L_9 ,
V_4 . V_7 -> V_49 , V_21 , V_59 , V_26 ) ;
return 0 ;
V_58:
F_9 ( V_60 , NULL , 0 ) ;
F_26 ( V_26 , V_4 . V_27 ) ;
V_29:
F_27 ( V_4 . V_7 ) ;
V_4 . V_7 = NULL ;
return V_23 ;
}
static void F_28 ( void )
{
if ( V_26 )
F_26 ( V_26 , V_4 . V_27 ) ;
F_9 ( V_60 , NULL , 0 ) ;
F_29 ( V_4 . V_7 ) ;
V_4 . V_7 = NULL ;
}
static int F_30 ( struct V_61 * V_7 )
{
if ( V_4 . V_7 )
return - V_24 ;
if ( ! V_7 -> V_12 ) {
F_20 ( V_33 L_10 ,
( void * ) V_7 -> V_62 . V_63 ) ;
return - V_24 ;
}
V_64 = V_7 -> V_62 . V_63 ;
V_65 = V_7 -> V_12 ;
V_4 . V_27 = V_7 ;
F_20 ( V_34 L_11 , V_64 , V_65 ) ;
return F_15 () ;
}
static int F_31 ( struct V_61 * V_7 )
{
F_28 () ;
return 0 ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_66 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_66 ) ;
}
static int T_3 F_32 ( void )
{
int error ;
if ( V_4 . V_7 )
return - V_67 ;
if ( ! V_68 )
return - V_24 ;
if ( ! F_36 ( ( void * ) ( V_59 + V_69 ) ) ) {
F_20 ( V_28 L_12 ) ;
return - V_24 ;
}
if ( ! F_37 ( V_59 + V_69 , 2 , L_1 ) ) {
F_20 ( V_28 L_13 ) ;
return - V_70 ;
}
error = F_15 () ;
if ( error ) {
F_38 ( V_59 + V_69 , 2 ) ;
return error ;
}
return 0 ;
}
static void T_4 F_34 ( void )
{
F_28 () ;
F_38 ( V_59 + V_69 , 2 ) ;
}
